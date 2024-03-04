/*
 * SPI_MASTR.c
 *
 * Created: 25/02/2024 11:52:20
 *  Author: Azza Saeed
 */ 


#include "dio.h"
#include "SPI_Interface.h"

#undef F_CPU
#define F_CPU 1000000UL

#include <util/delay.h>

#include "STD_Types.h"
#include "BIT_MATH.h"

u8 Recieve_Data;

void SPI_Callback_Recieve(void);

int main(void)
{
	/* SPI Initialization */
	Slave_Config Slave_Obj={ SPI_INTERRUPT_ENABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING};
		
	SPI_Init_Slave(&Slave_Obj);
	Global_Interrupt_Enable();
	SPI_Set_CallBack(SPI_Callback_Recieve);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN7,OUTPUT);
	
    while(1)
    {
		if( Recieve_Data == 0xFE)
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN7);
			_delay_ms(500);
		}
	}	
}

void SPI_Callback_Recieve(void)
{
	SPI_Read_Data(&Recieve_Data);
}