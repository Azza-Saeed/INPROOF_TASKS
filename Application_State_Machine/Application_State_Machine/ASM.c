/*
 *  ASM.c
 *
 *  Created: 03/03/2024 09:36:59 
 *  Author: Azza Saeed
 */ 
#include "ASM.h"

/* this variable updated with spi task */
volatile u8 SPI_Value=0;
Struct_Obj_t outputs={ 0,0,0,0 };
u8 u8Uart_Get_RFID2,RFID1_Value,Fire_Value;
	
void ASM_GatherInputs(void)
{
	// CAll SPI_Manager_Task to Update the spi_value
	/* Update the Inputs Values */
	//RFID1_Value = RIFD1_u8GetValue();
	//u8Uart_Get_RFID2 = UART_u8Get_RFID2_Value();
	//Fire_Value= Get_u8FireValue();
}


Struct_Obj_t ASM_PrepareOutputs(void)
{
	if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */	
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=BLUE;
		outputs.Motor_State=CENTER;
		outputs.RJB2_State=BLUE;
		outputs.Uart_state=0;
		//Normal_State();
	}
	else if ( ( RFID1_Value == 1 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=GREEN;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0xF5;
	}
	else if ( ( RFID1_Value == 1 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 252 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=GREEN;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0xF5;
	}
	else if ( ( RFID1_Value == 1 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 63 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=ON;
		outputs.RJB1_State=RED;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0xF5;
	}
	else if ( ( RFID1_Value == 1 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 231 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0xF5;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 252 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=ON;
		outputs.RJB1_State=RED;
		outputs.Motor_State=CENTER;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value != 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=ON;
		outputs.RJB1_State=RED;
		outputs.Motor_State=CENTER;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=BLUE;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=BLUE;
		outputs.Uart_state=0xF5;		
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 1 ) && ( SPI_Value == 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=LEFT;
		outputs.RJB2_State=GREEN;
		outputs.Uart_state=0x5F;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 1 ) && ( SPI_Value == 63 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=LEFT;
		outputs.RJB2_State=GREEN;
		outputs.Uart_state=0x5F;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 0 ) && ( SPI_Value == 255 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=LEFT;
		outputs.RJB2_State=GREEN;
		outputs.Uart_state=0x5F;
	}
	else if ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 1 ) && ( SPI_Value == 252 ) && ( Fire_Value == 0 ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=LEFT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0x5F;
	}
	else if ( ( ( RFID1_Value == 0 ) && ( u8Uart_Get_RFID2 == 1 ) && ( SPI_Value == 252 ) ) || (Fire_Value == 1  ) )
	{
		/* Actions */
		outputs.Alarm_State=OFF;
		outputs.RJB1_State=RED;
		outputs.Motor_State=RIGHT;
		outputs.RJB2_State=RED;
		outputs.Uart_state=0xF5;
	}
	else{
		/* Do Nothing */
	}
	return outputs;
}

