/*
 * App.c
 *
 * Created: 24/01/2024 04:22:44 م
 *  Author: Azza Saeed
 */ 

#include "App.h"
#include "SPI_Interface.h"
#include "GIE.h"

u8 Recieve_Array[5];
u8 u8counter=0;
u8 u8recieve_buffer;

void App_voidIit(void)
{
	/* SPI Slave Initialization */
	Slave_Config Slave_Obj={SPI_INTERRUPT_ENABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING};

	SPI_Init_Slave(&Slave_Obj);
	/* Function callback of the Spi*/
	SPI_Set_CallBack(Func_recieve_data);
	/* Enable global interrupt */
	Global_Interrupt_Enable();
	/* Set Pin as output for check */
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN7,OUTPUT);
}
void App_vidMain(void)
{
		SPI_Send_ASynch_Byte(0xFD);
		_delay_ms(10);
		/* Check the correct data */
		if( u8recieve_buffer == 0xFA )
		{
			/* Toggle channel for check */
			dio_vidFlipChannel(DIO_PORTC,DIO_PIN7);
			_delay_ms(500);
		}
}
void Func_recieve_data( void )
{
	/* Read Data From Master */
	SPI_Read_Data(&u8recieve_buffer);
	//u8recieve_buffer = SPDR;
	//u8counter++;
	//u8Recieved_flag=1;// for new recieved data
}







//void Blue_led(void)
//{
	//dio_vidFlipChannel(DIO_PORTC,DIO_PIN2);
//}
//
//void Green_Led(void)
//{
	//dio_vidFlipChannel(DIO_PORTC,DIO_PIN1);
//}
//
//void Red_Led(void)
//{
	//dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
//}