/*
 * TX_IR.c
 *
 * Created: 29/01/2024 01:45:35 
 *  Author: Azza Saeed
 */ 
#include "bit_math.h"
#include "Std_Types.h"

#define F_CPU  16000000UL
#include <util/delay.h>

#include "dio.h"
#include "TIMR2_int.h"
#include "GIE.h"

#include "IR_TX.h"


int main(void)
{
	IR_parameters_t IR_Obj={DIO_PORTC,DIO_PIN1, 0x55, 0xff};
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	/* IR Initialization */
	IR_voidInit(IR_Obj);
	/* Enable the global interrupt */
	GIE_voidGlobalInterruptEnable();
	
    while(1)
    {
		//dio_vidWriteChannel(DIO_PORTC,DIO_PIN1,STD_HIGH);
		//_delay_ms(9);
		//dio_vidWriteChannel(DIO_PORTC,DIO_PIN1,STD_LOW);
		//_delay_ms(4.5);
		
		/* Transmit signal */
        IR_voidTransmit(IR_Obj);
		_delay_ms(200);
    }
}