/*
 * SPI_Slave.c
 *
 * Created: 20/02/2024 09:44:21 
 *  Author: Azza Saeed
 */ 


#include "CPU_Configuration.h"
#include "dio.h"
#include "SPI_Interface.h"

int main(void)
{
	Slave_Config Slave_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING};
	UINT8_t u8Copy_data=0x44;
	UINT8_t * Ptr_Received=0;
	
	SPI_Init_Slave(&Slave_Obj);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
    while(1)
    {
 		SPI_Send_Receive_Synch_Byte(u8Copy_data,Ptr_Received);
 		if( *Ptr_Received == 0x55 )
 		{
	 		dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
	 		_delay_ms(500);
 		}
 		_delay_ms(200);
       	//	dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
      //_delay_ms(500);	
    }
}