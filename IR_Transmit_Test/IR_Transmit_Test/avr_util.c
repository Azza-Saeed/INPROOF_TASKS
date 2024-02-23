#include "avr_util.h"

bool icp_listening_for_rising() 
{
    if(TCCR1B & (1 << ICES1)) {
        return true;
    }
    return false;
}

bool icp_listening_for_falling() 
{
    return !icp_listening_for_rising();
}

void icp_listen_for_rising() 
{
    TCCR1B |= (1 << ICES1);
}

void icp_listen_for_falling() 
{
    TCCR1B ^= (1 << ICES1);
}

void usart_init() 
{
    /*
     UBRR is a 16-bit register, but only the 4 least significant bits of UBBR0H are valid.
     Let's put our calculated baud rate into these registers.
    */
    UBRRH = (CALCULATED_BAUD >> 8);
    UBRRL = CALCULATED_BAUD;
    
    /*
      Set the TXEN0 bit in the USART control register B to enable transmission off the TX pin.
    */
    UCSRB = (1 << TXEN);
    
    /*
      Set these bits to set 8-bits in the USART control register C to set a character size of 8.
    */
    UCSRC = (1 << UCSZ0) | (1 << UCSZ1);
}

void usart_transmit(unsigned char data) 
{
    // Wait for transmit buffer to be empty
    while ( !(UCSRA & (1 << UDRE)) );
    
    UDR = data;
}

void usart_transmit_string(char* string) 
{
    for(uint8_t i = 0; i < strlen(string); i++) {
        usart_transmit(string[i]);
    }
}