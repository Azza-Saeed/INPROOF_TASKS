/*
 * SPI_TEST_ATmega8.c
 *
 * Created: 18/02/2024 11:49:37
 *  Author: Azza Saeed
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>

#include "bit_math.h"
#include "Std_Types.h"

#include "LED.h"
#include "SPI.h"
#include "dio.h"
int main(void)
{
	SPI Spi_Slave_Parameters={SPI_SLAVE,SPI_SAMPLE_RISING,SPI_PRESCALE_2,SPI_DATAORDER_LSB};
	u8 u8Recieved_Data=0x56;
	
	SPI_VoidInit(&Spi_Slave_Parameters);
	SPI_voidInterruptEnable();
	
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN7,OUTPUT);
	
	while(1)
	{
		/*u8Recieved_Data=SPI_u8RecDataSlave();
		if( u8Recieved_Data == 0x66 )
		{
			dio_vidFlipChannel(DIO_PORTD,DIO_PIN7);
			_delay_ms(500);
		}
		_delay_ms(500);*/
		
	dio_vidFlipChannel(DIO_PORTB,DIO_PIN0);
	_delay_ms(500);
	
	}
}