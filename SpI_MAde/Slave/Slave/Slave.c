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
	u8 u8Copy_Data=0xFa;
	u8 recieved_data=0;
	
	SPI Slave_Obj={ SPI_SLAVE,SPI_SAMPLE_RISING,SPI_PRESCALE_128,SPI_DATAORDER_LSB};
		
		SPI_VoidInit(&Slave_Obj);
		//SPI_voidInterruptEnable();
		//GIE_voidGlobalInterruptEnable();
		dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
		
    while(1)
    {
        //recieved_data = SPI_u8SendRecData(u8Copy_Data);
		_delay_ms(100);
		
		if( recieved_data == 0xDF )
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
			_delay_ms(500);
		}			
    }
}