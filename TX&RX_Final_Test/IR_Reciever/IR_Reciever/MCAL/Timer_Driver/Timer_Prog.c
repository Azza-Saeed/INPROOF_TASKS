/*
 * Timer_Prog.c
 *
 *  Created on: Oct 20, 2023
 *      Author: yousef
 */
/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"
/********************/
#include "Timer_Interface.h"
#include "Timer_Priv.h"
#include "Timer_confg.h"
#include <avr/interrupt.h>


static volatile voidFuncPtr Timer1_Fun_OVERFLOW;

//Init global pointer to function

static void(*Gptrtofunc)(void);

void __vector_7(void)        __attribute__((signal));

void Timer_VidInt()
{

	//CTC MODE , Enable INT of compare match for channel A
		TCCR1A_REG = 0x00;
	//Output Compare Register 1 A – OCR1AH and OCR1AL
	OCR1A_REG = 1000;
	//Timer/Counter1 – TCNT1H and TCNT1L
		TCNT1_REG = 0;
	// Bit 4 – OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
		SET_BIT(TIMSK_REG,OCIE1A_PIN) ;

	// set the prescaler
	switch(TIMER_PRS_SELECT)
	{
	case NO_CLK : CLR_BIT(TCCR1B_REG,CS10_PIN);
		          CLR_BIT(TCCR1B_REG,CS11_PIN);
		          CLR_BIT(TCCR1B_REG,CS12_PIN);
		          break;
	case NO_PRS : SET_BIT(TCCR1B_REG,CS10_PIN);
	              CLR_BIT(TCCR1B_REG,CS11_PIN);
	              CLR_BIT(TCCR1B_REG,CS12_PIN);
	              break;

	case CLK_8  : CLR_BIT(TCCR1B_REG,CS10_PIN);
		          SET_BIT(TCCR1B_REG,CS11_PIN);
		          CLR_BIT(TCCR1B_REG,CS12_PIN);
		          break;

	case CLK_64 : SET_BIT(TCCR1B_REG,CS10_PIN);
	              SET_BIT(TCCR1B_REG,CS11_PIN);
		          CLR_BIT(TCCR1B_REG,CS12_PIN);
		          break;

	case CLK_256 : CLR_BIT(TCCR1B_REG,CS10_PIN);
	               CLR_BIT(TCCR1B_REG,CS11_PIN);
	               SET_BIT(TCCR1B_REG,CS12_PIN);
	               break;

	case CLK_1024 : SET_BIT(TCCR1B_REG,CS10_PIN);
		            CLR_BIT(TCCR1B_REG,CS11_PIN);
		            SET_BIT(TCCR1B_REG,CS12_PIN);
		            break;
	case CLK_EXT_FALLING : CLR_BIT(TCCR1B_REG,CS10_PIN);
	                       SET_BIT(TCCR1B_REG,CS11_PIN);
	                       SET_BIT(TCCR1B_REG,CS12_PIN);
	                       break;
	case CLK_EXT_RISING : SET_BIT(TCCR1B_REG,CS10_PIN);
	                      SET_BIT(TCCR1B_REG,CS11_PIN);
		                  SET_BIT(TCCR1B_REG,CS12_PIN);
		                  break;

	}
    // Waveform Generation Mode :these bits control the counting sequence of the counter, the source for maximum (TOP) counter value
	//CTC Mode Waveform Generation
	CLR_BIT(TCCR1B_REG,WGM13_PIN);
	SET_BIT(TCCR1B_REG,WGM12_PIN);

	// Enable global interrupt
	    SET_BIT(SREG_REG, I_PIN) ;

}

void Timer1_Vid_OverFlowMode()
{

	TCCR1A_REG = 0x00;
	TCCR1B_REG = (0<<CS10_PIN) | (1<<CS11_PIN) | (0<<CS12_PIN);  // Timer mode with 8 prescler
	TIMSK_REG = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	SET_BIT(SREG_REG, I_PIN) ;

}
void Timer1_EnableInterrupt()
{
	// Enable global interrupt
		SET_BIT(SREG_REG, I_PIN) ;
}
void Timer1_DiableInterrupt()
{
	// Enable global interrupt
		CLR_BIT(SREG_REG, I_PIN) ;
}

u16 Timer1_u16GetTCNT1Val()
{
	return TCNT1_REG ;
}
void Timer1_vidResetTCNT1Val()
{
	TCNT1_REG = 0 ;
}
void Timer_set_callback( void(*localPfunc)(void))
{
	//set global pointer to function
	Gptrtofunc = localPfunc;
}



void __vector_7(void)
{
	Gptrtofunc();
}


ISR(TIMER1_OVF_vect) {



	Timer1_vidResetTCNT1Val();

}
