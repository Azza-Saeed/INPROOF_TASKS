#include "bit_math.h"
#include "Std_Types.h"
#include "dio.h"
//#include "TIMR2_int.h"

/********* application test DIO ****************
 * config pin B4 as output
 * Toggle led every 1000 msec
 */

#define F_CPU  1000000UL
#include <util/delay.h> 

#include "dio.h"
#include "SPI_Interface.h"

int main(void)
{
	Slave_Config Slave_Obj={ SPI_INTERRUPT_DISABLE,SPI_LSB,SPI_RISING_LEADING,SPI_SAMPLE_LEADING};
	volatile u8 u8Copy_data=0xFF;
	volatile u8  Ptr_Received=0;
	
	SPI_Init_Slave(&Slave_Obj);
	
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN0, OUTPUT);
	
	while(1)
	{		
 		SPI_Send_Receive_Synch_Byte(u8Copy_data,&Ptr_Received);
 		if( Ptr_Received == 0x55 )
 		{
	 		dio_vidFlipChannel(DIO_PORTB,DIO_PIN0);
	 		_delay_ms(500);
 		}
 		_delay_ms(500);
	}
	
	return 0;
}
