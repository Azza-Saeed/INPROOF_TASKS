/*
 * SPI_MASTR.c
 *
 * Created: 25/02/2024 11:52:20 
 *  Author:	Azza Saeed
 */ 


#include "CPU_Configuration.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"


void Func_recieve_data_master( void );

volatile u8 u8Recieved_flag=0;
volatile u8 u8recieve_buffer[100];
volatile u8 counter=0;

u8 u8cpoy_data=0xF5;

int main(void)
{
	/* SPI Initialization */
	Master_Config Master_Obj={ SPI_INTERRUPT_ENABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};
	
	volatile u8  Ptr_Received=0;
	
	SPI_Init_Master(&Master_Obj);
	Global_Interrupt_Enable();
	SPI_Set_CallBack(Func_recieve_data_master);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
	

    while(1)
    {dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
	    _delay_ms(500);
			//SPI_Send_ASynch_Byte(DUMMY_DATA);
			//_delay_ms(500);
       /* Check for recieved data */
	  /* if( u8recieve_buffer[counter] == 0x1 )
	   {
		   // this the first sensor detect an object
	   }else if( u8recieve_buffer[counter] == 0x2 )	
	   {
		   // this is the second sensor detected an object
	}else if( u8recieve_buffer[counter] == 0x3 )
	{
		// this is the third sensor detected an object
	}
	*/
	  // for test the spi using interrupt
	  if( u8recieve_buffer[counter] == 0x55 )
	  {
		  dio_vidFlipChannel(DIO_PORTC,DIO_PIN5);
		  _delay_ms(500);
	  }
	
	   }		 
}

void Func_recieve_data_master( void )
{
	SPI_Read_Data(&u8recieve_buffer[counter]);
	//u8Recieved_flag=1;// for new recieved data
	counter++;

}
