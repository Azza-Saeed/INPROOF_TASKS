/*
 * IR_Transmitter.c
 *
 * Created: 04/02/2024 09:20:09 ص
 *  Author: Azza Saeed
 */ 

#include "Tranmitter_IR.h"

int main(void)
{
	//IR_parameters_t ir_1 = {DIO_PORTC,DIO_PIN0, 0xF0,0xff};
		
	IR_parameters_t Array_Transmitter[NUMBER_OF_SENSORS] ={ {DIO_PORTC,DIO_PIN0, 0xf0,0xff},{DIO_PORTC,DIO_PIN1, 0xf1,0xff}, {DIO_PORTC,DIO_PIN2, 0xf2,0xff},
										   {DIO_PORTC,DIO_PIN3, 0xf3,0xff}, {DIO_PORTC,DIO_PIN4, 0xf4,0xff}, {DIO_PORTC,DIO_PIN5, 0xf5,0xff}, 
										   {DIO_PORTC,DIO_PIN6, 0xf6,0xff}, {DIO_PORTC,DIO_PIN7, 0xf7,0xff} };
	u8 u8Counter=0;
	for( u8Counter=0;u8Counter<NUMBER_OF_SENSORS;u8Counter++)
	{
		IR_voidInit( Array_Transmitter[u8Counter] );
	}
	
	//IR_voidInit(ir_1);
	
    while(1)
    {
		//IR_voidTransmitFrame_timer(ir_1);
	
     for( u8Counter=0;u8Counter<NUMBER_OF_SENSORS;u8Counter++)
        {
	        IR_voidTransmitFrame_timer(Array_Transmitter[u8Counter]);
        }
	  
    }
}