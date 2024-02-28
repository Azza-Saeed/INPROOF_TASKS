#include "bit_math.h"
#include "Std_Types.h"
#include "dio.h"
#include "SPI_Private.h"

#define F_CPU  1000000UL
#include <util/delay.h> 

#include "dio.h"
#include "SPI_Interface.h"

 u8  LOcal_u8_Received_Data=0;
 u8 local=0;
 u8 pread=0;
 void slave_callback()
 {
	 //SPI_Read_Data(&pread);
	 pread = SPDR;
	 dio_vidFlipChannel(DIO_PORTB, DIO_PIN0);
	 //dio_vidWriteChannel(DIO_PORTB, DIO_PIN0, STD_HIGH);
	 SPDR = 0xFA;
	 _delay_ms(100);
 }
 
int main(void)
{
	dio_vidConfigChannel(DIO_PORTB, DIO_PIN0, OUTPUT);
	Slave_Config Slave_Obj={ SPI_INTERRUPT_ENABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING};
	
	
	SPI_Init_Slave(&Slave_Obj);
	SPI_Set_CallBack(slave_callback);
	Global_Interrupt_Enable();
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN0, OUTPUT);
	
	while(1)
	{	
 		/*SPI_Send_Receive_Synch_Byte(u8Copy_data,&Ptr_Received);
 		if( Ptr_Received == 0x55 )
 		{
	 		dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
	 		_delay_ms(500);
 		}
		
_delay_ms(200); */
		 
		 //SPI_Read_Data(&Ptr_Received);
		 //if( Ptr_Received == 0x55 )
		 //{
			 //dio_vidWriteChannel(DIO_PORTC,DIO_PIN0,STD_HIGH);
			 //_delay_ms(500);
		 //}
		 //
		 //_delay_ms(200);
		 //
		 // interrupt
		// SPI_Send_ASynch_Byte(u8Copy_data);
		
		
		//SPI_Send_Receive_Synch_Byte(0xCC,&LOcal_u8_Received_Data);
		//Slave_Send(0xCC);
		//_delay_ms(200);
		 // check for this data
		 //SPI_Read_Data(&LOcal_u8_Received_Data);
		
		 //if( LOcal_u8_Received_Data == 0xDD )
		 //{
		//	 dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
		//	 _delay_ms(500);
		 //}
	
	}
	
	return 0;
}
