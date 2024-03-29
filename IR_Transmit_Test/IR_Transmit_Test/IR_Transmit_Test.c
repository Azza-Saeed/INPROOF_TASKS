﻿#include "avr_config.h"

#include "ir_types.h"
#include "errors.h"
#include "avr_util.h"
#include "general_util.h"
#include "ir_util.h"
#include "nec_module.h"
#include "sparkfun_com_11759.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEADER_SEGMENTS_SIZE (uint8_t) 15
#define DATA_SEGMENTS_SIZE (uint8_t) 40
#define UNSET_SEGMENT (int32_t) -1

void process_new_header_segment(struct Segment new_segment);
void process_new_segment(struct Segment new_segment);
void hard_reset();
void soft_reset();

volatile bool hard_reset_required = false;
volatile int32_t mark_start = UNSET_SEGMENT, mark_end = UNSET_SEGMENT, space_start = UNSET_SEGMENT, space_end = UNSET_SEGMENT;
volatile uint32_t decoded_data = 0;
volatile uint16_t tc1_overflows = 0;
volatile uint8_t selected_protocol = UNKNOWN;
volatile uint8_t free_header_index = 0;
volatile uint8_t data_bit_counter = 0;
struct Segment header_segments[HEADER_SEGMENTS_SIZE];
struct Pair data_pair;

int main(void) 
{
    /* Set PINB1 as an output */
    DDRB = (1 << PINB1);
    
    DDRC = (1 << BLUE_LED) | (1 << RED_LED);
	
    /*
     ICNC1 high to turn on input capture noise canceling
    */
    TCCR1B = (1 << ICNC1);
    
    usart_init();
	
    /* ICIE1 high to enable the input capture interrupt */
    /* TOIE0 high to enable the Timer1 overflow interrupt */
    TIMSK = (1 << ICES1) | (1 << TOIE0);
    sei();
	 
    /* Start Timer1 with a prescaler of 8 */
    TCCR1B |= (1 << CS11);
    /*
	 - Prescaler of 8 on TC1 will give our input capture the ability to capture events with
	lengths from .5 microseconds (1 tick) to 32767 microseconds (65535 ticks) <-- assuming 16MHz clock
		
	 - Prescaler of 1 (no prescaler) can only capture a maximum event (without guaranteed overflow, which would be annoying to consistently deal with)
	of 4095 microseconds.  This is inadequate, considering the header high-segment of the NEC protocol is 9000 microseconds (9ms) <-- assuming 16MHz clock
    */
    while (1) {
        if(!hard_reset_required) {
            if(mark_start != UNSET_SEGMENT && mark_end != UNSET_SEGMENT) {
                //a new mark has been closed (it's start and end times have been set) - let's process it
                uint16_t mark_ticks = calculate_segment_ticks(mark_start, mark_end);
                mark_start = -1;
                mark_end = -1;
                struct Segment new_segment;
                new_segment.is_mark = true;
                new_segment.is_space = false;
                new_segment.microseconds = ticks_to_microseconds(mark_ticks);
                process_new_segment(new_segment);
            }
                    
            if(space_start != UNSET_SEGMENT && space_end != UNSET_SEGMENT) {
                //a new space has been closed (it's start and end times have been set) - let's process it
                uint16_t space_ticks = calculate_segment_ticks(space_start, space_end);
                space_start = -1;
                space_end = -1;
                struct Segment new_segment;
                new_segment.is_mark = false;
                new_segment.is_space = true;
                new_segment.microseconds = ticks_to_microseconds(space_ticks);
                process_new_segment(new_segment);
            }
                    
            if(selected_protocol != UNKNOWN && data_pair.has_mark == true && data_pair.has_space == true) {
                data_pair.has_mark = false;
                data_pair.has_space = false;
                int8_t bit = nec_data_bit_from_pair(data_pair);
                if(bit != INVALID_PAIR_TIMINGS) {
                    if(bit == 1) {
                        int16_t pos = get_bit_position(NEC, data_bit_counter);
                        if(pos == NO_BIT_POS_FOR_UNKNOWN || pos == BIT_POS_CALC_ERROR || pos == INVALID_PROTOCOL) {
                            hard_reset();
                        }
                        BIT_SET(decoded_data, pos);
                    }
                    data_bit_counter++;
                } else {
                    hard_reset();
                }
            }
        } 
    }
}

ISR(TIMER1_CAPT_vect) 
{
    if(icp_listening_for_falling()) {
        mark_start = ICR1;
        if(space_start != -1) {
            //we don't want to set space_end if we haven't started timing a space yet
            //e.g. this is the first pulse of a full burst, and it is falling (the start of a mark in a TSOP382)
            space_end = ICR1;
        }
        icp_listen_for_rising(); 
    } else if(icp_listening_for_rising()) {
        space_start = ICR1;
        if(mark_start != -1) {
            //we don't want to set mark_end if we haven't started timing a mark yet
            //e.g. this is the first pulse of a full burst, and it is rising
            mark_end = ICR1;
        }
        icp_listen_for_falling();
    }        
}

ISR(TIMER1_OVF_vect) 
{
    PORTC = 0x0; //clear any debug LEDs set on PORTC
    
    if(tc1_overflows == 10) {
        soft_reset();
    } else if(hard_reset_required) {
        tc1_overflows++;
    }
}

void process_new_segment(struct Segment new_segment) 
{
    if(selected_protocol == UNKNOWN) {
        //this segment must be part of the header since we haven't matched the header to a protocol yet
        process_new_header_segment(new_segment);
    } else if(selected_protocol == NEC) {
        //this is a logical data segment for the NEC protocol
        if(new_segment.is_mark) {
            if(all_data_bits_received(NEC, data_bit_counter)) {
                //in the NEC protocol, there are typically 32 data bits transferred, followed by a single trailer mark to signal the end of transmission.  we're done here, so let's reset program state
                soft_reset();
            } else {
                data_pair.mark = new_segment;
                data_pair.has_mark = true;
            }
        } else if(new_segment.is_space) {
            data_pair.space = new_segment;
            data_pair.has_space = true;
        } else {
            hard_reset();
        }
    } else {
        //this probably shouldn't happen 
        hard_reset();
    }
}

void process_new_header_segment(struct Segment new_segment) 
{
    if(free_header_index >= HEADER_SEGMENTS_SIZE) {
        //something went wrong, we haven't matched a header to a protocol yet
        //we don't want to add this mark to the header array because we'll be out of bounds.  let's hard reset
        hard_reset();
    } else {
        header_segments[free_header_index++] = new_segment;
        selected_protocol = protocol_from_header(header_segments, free_header_index);
    }
}

/*
  Recovers from situations in which the program has entered an unexpected state and can't continue.
  We'll set a flag to let the rest of the program to ignore everything else, and once a certain time has
  passed (determined by timer overflows), we'll do a soft reset to reinitialize program state.
  
  We can't simply call a soft_reset() here to reinitialize program state, because code following a hard_reset()
  call could muck up that freshly reinitialized state.
*/
void hard_reset() 
{
    usart_transmit_string("hard reset\n");
    hard_reset_required = true;
}

/*
  Clears program state in the event of an expected reset (e.g. end of one full transmission).
*/
void soft_reset() 
{
    hard_reset_required = false;
    mark_start = UNSET_SEGMENT;
    mark_end = UNSET_SEGMENT;
    space_start = UNSET_SEGMENT;
    space_end = UNSET_SEGMENT;
    selected_protocol = UNKNOWN;
    tc1_overflows = 0;
    data_bit_counter = 0;
    decoded_data = 0;
    
    for(uint8_t i = 0; i < free_header_index; i++) {
        reinitialize_segment(&header_segments[i]);
    }
    free_header_index = 0;
    reinitialize_pair(&data_pair);
}
