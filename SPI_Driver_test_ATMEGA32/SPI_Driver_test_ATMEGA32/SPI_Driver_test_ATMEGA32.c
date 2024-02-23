/*
 * SPI_Driver_test_ATMEGA32.c
 *
 * Created: 18/02/2024 10:53:12
 *  Author: Azza Saeed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "bit_math.h"
#include "Std_Types.h"

#include "SPI.h"
#include "LED.h"
#include "dio.h"

int main(void)
{
	SPI Spi_Master_Parameters={SPI_MASTER,SPI_SAMPLE_RISING,SPI_PRESCALE_128,SPI_DATAORDER_LSB};
	u8 u8Send_Data=0x66;
	u8 rec=0;
	SPI_VoidInit(&Spi_Master_Parameters);
	SPI_voidInterruptEnable();
	
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN6,OUTPUT);
	
	while(1)
	{
		/*rec=SPI_u8SendRecData(u8Send_Data);
		if(rec == 0x56 )
		{
			dio_vidFlipChannel(DIO_PORTD,DIO_PIN6);
			_delay_ms(500);
		}
		_delay_ms(500);*/
		
		SPI_u8SendRecDataInterrupt(u8Send_Data);		
		_delay_ms(500);
	}

}