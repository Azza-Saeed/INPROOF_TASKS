/*
 * Slave.c
 *
 * Created: 28/02/2024 02:38:17 
 *  Author: Azza Saeed
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "Std_Types.h"
#include "bit_math.h"

#include "dio.h"
#include "GIE.h"
#include "SPI.h"


int main(void)
{
	u8 u8Copy_Data=0xDF;
	u8 recieved_data=0;
	
	SPI Master_Obj={ SPI_MASTER,SPI_SAMPLE_RISING,SPI_PRESCALE_128,SPI_DATAORDER_LSB};
		
		SPI_VoidInit(&Master_Obj);
		SPI_voidInterruptEnable();
		GIE_voidGlobalInterruptEnable();
		dio_vidConfigChannel(DIO_PORTC,DIO_PIN7,OUTPUT);
		
    while(1)
    {
		SPI_u8SelectSlave(DIO_PORTA, DIO_PIN3);
        SPI_u8SendRecDataInterrupt(u8Copy_Data);
		
		_delay_ms(500);
		dio_vidSetPortValue(DIO_PORTC, recieved_data);
		if( recieved_data == 0xFa )
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN7);
			_delay_ms(500);
		}			
    }
}