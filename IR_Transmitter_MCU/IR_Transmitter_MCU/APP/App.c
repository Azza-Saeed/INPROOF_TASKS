/*
 * App.c
 *
 * Created: 14/02/2024 12:22:29 
 *  Author: Azza Saeed
 */ 

#include "Tranmitter_IR.h"

#include "App.h"

IR_parameters_t Transmitter ={DIO_PORTB,DIO_PIN0, 0xf0,0xff};
	
void App_vidInit(void)
{	
		
	//IR_voidInit(Transmitter);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN0,OUTPUT);
}

void App_vidMain(void)
{
	IR_voidTransmitFrame_timer(Transmitter);
	//IR_voidSendPulses(Transmitter);
	//IR_voidSendStartBit_timer(Transmitter);
	/*dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,STD_HIGH);
	_delay_ms(500);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,STD_LOW);
	_delay_ms(500);*/
}