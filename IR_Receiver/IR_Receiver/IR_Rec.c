/*
 * IR_Rec.c
 *
 * Created: 29/01/2024 09:42:00 
 *  Author: Azza Saeed
 */ 

#include "dio.h"
#include "TIMR2_int.h"
#include "EXTI0_int.h"
#include "GIE.h"

#include "bit_math.h"
#include "Std_Types.h"

#include "IR_Rec.h"

volatile u8  u8StartFlag      = 0;
volatile u32 u32FrameData[50] = {0};
volatile u8  u8EdgeCounter    =	0;
volatile u8  u8Data           =	0;
volatile u8 u8TimerCounter    = 0;
 
void IR_voidInit(void)
{
	/* IO initialization */
	dio_vidConfigChannel(DIO_PORTA,0,INPUT);
	dio_vidConfigChannel(DIO_PORTC,1,OUTPUT);
	dio_vidConfigChannel(DIO_PORTC,2,OUTPUT);
	
	/* EXTI0 Initialization */
	EXT0_voidCallBack(IR_voidGetFrame);
	EXT0_voidInit();
	EXT0_voidEnable();
	
	/* TIMER2 Initialization every 1 micro second */
	TIMER2_void_Init();
	TIMER2_void_SetCompareVal(COMPARE_MATCH_VAL);
	GIE_voidGlobalInterruptEnable();
	TIMER2_void_SetCTCCallBack(voidISRTimer);
}

void IR_voidGetFrame(void)
{
	u8 u8DataCounter=0;
	
	if ( 0 == u8StartFlag )
	{
		/* Start Timer */
		TIMER2_void_EnableCTCInt();
		u8StartFlag = 1;
	}
	else
	{   /* Save Time in this array */
		u32FrameData[u8EdgeCounter] = TCNT2;
		TCNT2 = 0;
		TIMER2_void_DisableCTCInt();
		TIMER2_void_EnableCTCInt();
	}

	if( ( u32FrameData[0] >= 10000 ) && (u32FrameData[0] <= 14000 ))
	{
		for(u8DataCounter=0;u8DataCounter<8;u8DataCounter++)
		{
			if( ( u32FrameData[17+u8DataCounter] >= 2000 ) && ( u32FrameData[17+u8DataCounter] <= 2300 ) )
			{
				SET_BIT(u8Data,u8DataCounter);
			}
			else
			{
				CLEAR_BIT(u8Data,u8DataCounter);
			}
		}
	}
	else
	{
		/* Invalid Frame */
	}
	u8StartFlag		= 0;
	u32FrameData[0] = 0;
	u8EdgeCounter	= 0;
}
	
void voidISRTimer(void)
{
	u8TimerCounter++;
}