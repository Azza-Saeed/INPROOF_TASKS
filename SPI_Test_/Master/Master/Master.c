#include "bit_math.h"
#include "Std_Types.h"
#include "dio.h"


#define F_CPU  1000000UL
#include <util/delay.h> 

#include "dio.h"
#include "SPI_Interface.h"

void Func_recieve_data_master( void );


volatile u8 u8recieve_buffer;

volatile u8 u8cpoy_data=0xF5;

int main(void)
{
	//Master_Config Master_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};
	//volatile u8 u8Copy_data=0x55;
	//volatile u8  Ptr_Received=0;
	//
	//SPI_Init_Master(&Master_Obj);
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN7,OUTPUT);
	// Interupt
	/* SPI Initialization */
	Master_Config Master_Obj={ SPI_INTERRUPT_ENABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING,SPI_PRESCALER_128};

	SPI_Init_Master(&Master_Obj);
	SPI_Set_CallBack(Func_recieve_data_master);
	Global_Interrupt_Enable();
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);

	
    while(1)
    {
		//SPI_Send_Receive_Synch_Byte(u8Copy_data,&Ptr_Received);
		
	
		/*if( Ptr_Received == 0xF5 )
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN7);
			_delay_ms(500);
		}
		*/
		//Master_Send(u8Copy_data);
		//Ptr_Received=Master_Receive();
		//
		//if( Ptr_Received == 0xF5 )
		//{
			//dio_vidFlipChannel(DIO_PORTC,DIO_PIN7);
			//_delay_ms(500);
		//}
		
		// interrupt
		SPI_Send_ASynch_Byte(DUMMY_DATA);
		_delay_ms(500);
		 //for test the spi using interrupt
		
		if( u8recieve_buffer == 0xE5 )
		{
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
			_delay_ms(500);
		}
    }
}
void Func_recieve_data_master( void )
{
	//u8recieve_buffer = SPDR;
	SPI_Read_Data(&u8recieve_buffer);
	
	//u8Recieved_flag=1;// for new recieved data

}
