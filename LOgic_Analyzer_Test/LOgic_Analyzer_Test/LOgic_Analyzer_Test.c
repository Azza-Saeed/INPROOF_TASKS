/*
 * LOgic_Analyzer_Test.c
 *
 * Created: 01/02/2024 12:50:28 م
 *  Author: Azza Saeed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "dio.h"

int main(void)
{
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	
    while(1)
    {
	dio_vidWriteChannel(DIO_PORTC,DIO_PIN1,STD_HIGH);
	_delay_ms(100);
	dio_vidWriteChannel(DIO_PORTC,DIO_PIN1,STD_LOW);
	_delay_ms(100);
        //TODO:: Please write your application code 
    }
}