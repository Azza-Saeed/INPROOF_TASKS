/*

 * File:   application.c
 * Author: yousef
 *
 * Created on November 23, 2023, 12:22 PM
 */


/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"


/********************/

/********MCAL*********/
#include "MCAL/DIO_DRIVE/DIO_Interface.h"


/********************/


/********HAL*********/
#include "HAL/IR_Reciver/IR_Reciver_Interface.h"

/********************/


#include <util/delay.h>


int main(void) {


	UART_vidInit();
	UART_Sendu32Value(0x4FAC);
	IR_VidIntialize() ;
	//Port_vidSetDirDIO(DIO_PORTB,0xff) ;



	while (1)
	{

		//Port_vidTogelDIO(DIO_PORTB) ;
		//_delay_ms(100);
		IR1_BaseNEC();

	}
    return 0;
}


