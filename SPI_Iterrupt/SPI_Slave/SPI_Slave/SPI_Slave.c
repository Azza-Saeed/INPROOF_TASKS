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


int main(void)
{
	/* SPI Initialization */
	//Master_Config Slave_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};
	//
	//volatile u8  Ptr_Received=0;
	//u8 u8Copy_data=0x55;
	//
	//SPI_Init_Slave(&Slave_Obj);
	//Global_Interrupt_Enable();
	//SPI_Set_CallBack(Func_recieve_slave);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
	
    while(1)
    {
		 dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
		 _delay_ms(500);
		 
		//SPI_Send_ASynch_Byte(u8Copy_data);
		//_delay_ms(200);
		//// check for this data 
		//SPI_Read_Data(&Ptr_Received);
		//
		//if( Ptr_Received == DUMMY_DATA )
		//{
			 //dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
			 //_delay_ms(500);
		 //}
	}	
}

