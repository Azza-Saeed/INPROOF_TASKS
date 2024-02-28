/*
 * IR_Reciver_Prog.c
 *
 *  Created on: Jan 22, 2024
 *      Author: joe
 */


/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"

#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"
/********************/
/*******MCAL*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\MCAL\DIO_DRIVE/DIO_Interface.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\MCAL\Timer_Driver/Timer_Interface.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\MCAL\Timer_Driver/Timer_Priv.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\MCAL\UART_DRIVER/UART_Interface.h"
/********************/

/********OS Layer*********/
#include "IR_Reciver_Interface.h"
#include "IR_Reciver_Config.h"
#include "IR_Reciver_Prive.h"
#include <util/delay.h>


/************IR1 Variables******************/
volatile u32 IR1_Frame = 0;
volatile u8 IR1_BitCount = 0;
static volatile u8 IR1_DataReady = 0;
u8 IR1SumData[20] ;
/*******************************************/
/************IR2 Variables******************/
volatile u32 IR2_Frame = 0;
volatile u8 IR2_BitCount = 0;
volatile u8 IR2_DataReady = 0;
u8 IR2SumData[20] ;
/*******************************************/
/************IR3 Variables******************/
volatile u32 IR3_Frame = 0;
volatile u8 IR3_BitCount = 0;
volatile u8 IR3_DataReady = 0;
u8 IR3SumData[20] ;
/*******************************************/
/************IR4 Variables******************/
volatile u32 IR4_Frame = 0;
volatile u8 IR4_BitCount = 0;
volatile u8 IR4_DataReady = 0;
u8 IR4SumData[20] ;
/*******************************************/
/************IR5 Variables******************/
volatile u32 IR5_Frame = 0;
volatile u8 IR5_BitCount = 0;
volatile u8 IR5_DataReady = 0;
u8 IR5SumData[20] ;
/*******************************************/
/*IR IRs[N_SENSOR] = { { .port = SENSOR1_CONFIG_PORT, .pin = SENSOR1_CONFIG_PIN,
		.state = IR_ACTIVE, .direction = SENSOR1_CONFIG_DIRECTION, },  //sensor1
		{ .port = SENSOR2_CONFIG_PIN, .pin = SENSOR2_CONFIG_PIN, .state =
				IR_ACTIVE, .direction = SENSOR2_CONFIG_DIRECTION, },   //sensor2
		{ .port = SENSOR3_CONFIG_PIN, .pin = SENSOR3_CONFIG_PIN, .state =
				IR_ACTIVE, .direction = SENSOR3_CONFIG_DIRECTION, },   //sensor3
		{ .port = SENSOR4_CONFIG_PIN, .pin = SENSOR4_CONFIG_PIN, .state =
				IR_ACTIVE, .direction = SENSOR4_CONFIG_DIRECTION, },   //sensor4
		{ .port = SENSOR5_CONFIG_PIN, .pin = SENSOR5_CONFIG_PIN, .state =
				IR_ACTIVE, .direction = SENSOR5_CONFIG_DIRECTION, },   //sensor5
		{ .port = SENSOR6_CONFIG_PIN, .pin = SENSOR6_CONFIG_PIN, .state =
				IR_ACTIVE, .direction = SENSOR6_CONFIG_DIRECTION, }, }; //sensor6*/

void IR_VidIntialize() {
	Pin_vidSetDirDIO(SENSOR1_CONFIG_PORT, SENSOR1_CONFIG_PIN,SENSOR1_CONFIG_DIRECTION);  //sensor1
	Pin_vidSetDirDIO(SENSOR2_CONFIG_PORT, SENSOR2_CONFIG_PIN,SENSOR2_CONFIG_DIRECTION);  //sensor2
	Pin_vidSetDirDIO(SENSOR3_CONFIG_PORT, SENSOR3_CONFIG_PIN,SENSOR3_CONFIG_DIRECTION);  //sensor3
	Pin_vidSetDirDIO(SENSOR4_CONFIG_PORT, SENSOR4_CONFIG_PIN,SENSOR4_CONFIG_DIRECTION);  //sensor4
	Pin_vidSetDirDIO(SENSOR5_CONFIG_PORT, SENSOR5_CONFIG_PIN,SENSOR5_CONFIG_DIRECTION);  //sensor5
	Pin_vidSetDirDIO(SENSOR6_CONFIG_PORT, SENSOR6_CONFIG_PIN,SENSOR6_CONFIG_DIRECTION);  //sensor6
	Pin_vidSetDirDIO(SENSOR7_CONFIG_PORT, SENSOR7_CONFIG_PIN,SENSOR7_CONFIG_DIRECTION);  //sensor7
	Pin_vidSetDirDIO(SENSOR8_CONFIG_PORT, SENSOR8_CONFIG_PIN,SENSOR8_CONFIG_DIRECTION);  //sensor8

	Timer1_Vid_OverFlowMode();

}
IR_state IR3_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR3_CONFIG_PORT, SENSOR3_CONFIG_PIN);
}
IR_state IR4_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR4_CONFIG_PORT, SENSOR4_CONFIG_PIN);
}
IR_state IR5_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR5_CONFIG_PORT, SENSOR5_CONFIG_PIN);
}
IR_state IR6_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR6_CONFIG_PORT, SENSOR6_CONFIG_PIN);
}


/**********************************************IR1 Fun***************************************************************/
IR_state IR1_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR1_CONFIG_PORT, SENSOR1_CONFIG_PIN);
}
void IR1_BaseNEC()
{
	static u16 prevTime ;
	static u8 count1 = 0 ;

	if(IR1_u8GetRead() == IR_NONACTIVE)        // Start frame
	{
		IR1_DataReady = 0 ;
	if(IR1_DataReady == 0)
	{
		for(u8 i = 0 ; i < 34 ; i ++)
		{

			if(IR1_u8GetRead() == IR_NONACTIVE)
			{
				Timer1_vidResetTCNT1Val() ;
				while(IR1_u8GetRead() == IR_NONACTIVE);
				prevTime = Timer1_u16GetTCNT1Val() ;
				if ( prevTime  > NUM1_NEC_TIME)
				{ // Check for data bit1
					IR1_Frame |= (1UL << IR1_BitCount);
					IR1_BitCount++;
				}
				else if (prevTime  > NUM0_NEC_TIME)
				{ // Check for data bit0
					IR1_Frame |= (0UL << IR1_BitCount);
					IR1_BitCount++;
				 }
	          // Check for stop bit
			}
		   if (IR1_BitCount >= NUM_OF_BIT_FRAME)
			{
			   IR1SumData[count1] = IR_ACTIVE ;
			   count1  ++ ;
			 UART_Sendu32Value(IR1_Frame);
			 IR1_vidResetData();
			 break;
			}
		}
	}
	}
	else
	{
		IR1SumData[count1] = IR_NONACTIVE ;
		count1 ++ ;
		IR1_vidResetData();
	}

	if(count1 == NUM_OF_CHECK)
	{
		count1 = 0 ;
	    u8 IR1_CHEK = 0;

		for(u8 i = 0 ; i < NUM_OF_CHECK ; i ++ )
		{
			if(IR1SumData[i]  == 0  )
			{
				IR1_CHEK++ ;
			}
			else
			{
				IR1_CHEK-- ;
			}
		}
		if(IR1_CHEK == NUM_OF_CHECK )
		{

			Pin_vidSetValDIO(DIO_PORTC, DIO_PIN0,HIGH);
		}
		else
		{
			Pin_vidSetValDIO(DIO_PORTC, DIO_PIN0,LOW);
		}
	}


}

void IR1_vidResetData()
{
	IR1_DataReady = 1;
	IR1_Frame = 0  ;
	IR1_BitCount = 0 ;
}


/********************************************************************************************************************/
/**********************************************IR2 Fun***************************************************************/
IR_state IR2_u8GetRead() {
	return Pin_u8GetValDIO(SENSOR2_CONFIG_PORT, SENSOR2_CONFIG_PIN);
}
void IR2_BaseNEC()
{
	static u16 prevTime2 ;
	static u8 count2 = 0 ;

	if(IR2_u8GetRead() == IR_NONACTIVE)        // Start frame
	{
		IR2_DataReady = 0 ;
	while(IR2_DataReady==0)
	{
			if(IR2_u8GetRead() == IR_NONACTIVE)
			{
				Timer1_vidResetTCNT1Val() ;
				while(IR2_u8GetRead() == IR_NONACTIVE);
				prevTime2 = Timer1_u16GetTCNT1Val() ;
				if (prevTime2  > 0 && prevTime2  > NUM1_NEC_TIME)
				{ // Check for data bit1
					IR2_Frame |= (1UL << IR1_BitCount);
					IR2_BitCount++;
				}
				else if (prevTime2 > 0 && prevTime2  > NUM0_NEC_TIME)
				{ // Check for data bit0
					IR2_Frame |= (0UL << IR2_BitCount);
					IR2_BitCount++;
				 }
	          // Check for stop bit
			}
		   if (IR2_BitCount >= NUM_OF_BIT_FRAME)
			{
			   IR2SumData[count2] = IR_ACTIVE ;
			   count2  ++ ;
			 UART_Sendu32Value(IR2_Frame);
			 IR2_vidResetData();
			 Timer1_vidResetTCNT1Val() ;
			 break;
			}
	}
	}
	else
	{
		IR2SumData[count2] = IR_NONACTIVE ;
		count2 ++ ;
	}

	if(count2 == NUM_OF_CHECK)
	{
		count2 = 0 ;
	    u8 IR2_CHEK = 0;

		for(u8 i = 0 ; i < NUM_OF_CHECK ; i ++ )
		{
			if(IR2SumData[i]  == 0  )
			{
				IR2_CHEK++ ;
			}
			else
			{
				IR2_CHEK-- ;
			}
		}
		if(IR2_CHEK == NUM_OF_CHECK )
		{

			Pin_vidSetValDIO(DIO_PORTC, DIO_PIN1,HIGH);
		}
		else
		{
			Pin_vidSetValDIO(DIO_PORTC, DIO_PIN1,LOW);
		}
	}


}

void IR2_vidResetData()
{
	IR2_DataReady = 1;
	IR2_Frame = 0  ;
	IR2_BitCount = 0 ;
}



