/*
 * App.c
 *
 * Created: 14/02/2024 12:22:29 
 *  Author: Azza Saeed
 */ 

#include "Tranmitter_IR.h"

#include "App.h"

//IR_parameters_t Transmitter ={DIO_PORTB,DIO_PIN0, 0xf0,0xff};
IR_parameters_t Array_Transmitter[NUMBER_OF_SENSORS] ={ {DIO_PORTC,DIO_PIN0, 0xf0,0xff},{DIO_PORTC,DIO_PIN1, 0xf1,0xff}, {DIO_PORTC,DIO_PIN2, 0xf2,0xff},
										   {DIO_PORTC,DIO_PIN3, 0xf3,0xff}, {DIO_PORTC,DIO_PIN4, 0xf4,0xff}, {DIO_PORTC,DIO_PIN5, 0xf5,0xff}, 
										   {DIO_PORTD,DIO_PIN7, 0xf6,0xff}, {DIO_PORTD,DIO_PIN6, 0xf7,0xff} };
	
void App_vidInit(void)
{	
		u8 u8Counter=0;
		for( u8Counter=0;u8Counter<NUMBER_OF_SENSORS;u8Counter++)
		{
			dio_vidConfigChannel(DIO_PORTB,DIO_PIN0+u8Counter,OUTPUT);
		}	
	//IR_voidInit(Transmitter);
	//dio_vidConfigChannel(DIO_PORTB,DIO_PIN0,OUTPUT);
}

void App_vidMain(void)
{
	//IR_voidTransmitFrame_timer(Transmitter);
		u8 u8Counter=0;
		for( u8Counter=0;u8Counter<NUMBER_OF_SENSORS;u8Counter++)
		{
			IR_voidTransmitFrame_timer( Array_Transmitter[u8Counter] );
		}
	//IR_voidSendPulses(Transmitter);
	//IR_voidSendStartBit_timer(Transmitter);
	/*dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,STD_HIGH);
	_delay_ms(500);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN0,STD_LOW);
	_delay_ms(500);*/
}