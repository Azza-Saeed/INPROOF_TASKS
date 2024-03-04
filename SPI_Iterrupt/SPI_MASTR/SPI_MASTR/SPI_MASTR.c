/*
 * SPI_MASTR.c
 *
 * Created: 25/02/2024 11:52:20 
 *  Author:	Azza Saeed
 */ 


#include "CPU_Configuration.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"


int main(void)
{
	/* SPI Initialization */
	Master_Config Master_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};
	
	volatile u8  Ptr_Received=0;
	
	SPI_Init_Master(&Master_Obj);

    while(1)
    {
	 
	  SPI_Send_Receive_Synch_Byte(DUMMY_DATA,&Ptr_Received);
	  _delay_ms(500);
	
	}		 
}

