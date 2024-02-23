/*
 * SPI__version2.c
 *
 * Created: 20/02/2024 09:22:37 
 *  Author: Azza Saeed
 */ 


#include "CPU_Configuration.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"

int main(void)
{
	Master_Config Master_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};
	volatile u8 u8Copy_data=0x55;
	volatile u8  Ptr_Received=0;
	
	SPI_Init_Master(&Master_Obj);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	
    while(1)
    {
		SPI_Send_Receive_Synch_Byte(u8Copy_data,&Ptr_Received);
		
		if( Ptr_Received == 0xFF )
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN1);
			_delay_ms(500);
		}
		_delay_ms(500);
		
    }
}