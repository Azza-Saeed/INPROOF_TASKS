/*
 * TX.c
 *
 * Created: 29/01/2024 02:15:32 م
 *  Author: Azza Saeed
 */ 
#include "dio.h"
#include "TIMR2_int.h"
#include "GIE.h"

#include "bit_math.h"
#include "Std_Types.h"

#include "IR_TX.h"

u8 u8State= IDLE_STATE;
volatile static IR_parameters_t IR_Global_Obj;
volatile static u64 u32Concat=0;

/*
	Function Name        : IR_voidInit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : initialize the system
*/
void IR_voidInit(IR_parameters_t IR_Obj)
{
	IR_Global_Obj = IR_Obj;
	
	u32Concat |= IR_Obj.u8Address;			// address bits 
	u32Concat |= (~IR_Obj.u8Address)<<8;	// inverted address bits
	u32Concat |= (IR_Obj.u8Data)<<16;		// data bits
		u32Concat |= (~IR_Obj.u8Data)<<24;		// inverted data bits
	u32Concat |= 0<<32;					//end bit
	/* IO initialization */
	dio_vidConfigChannel(IR_Obj.u8port, IR_Obj.u8pin,OUTPUT);
	/* Idle */
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin,STD_LOW);
	/* Timer2 Initialization / every 1 micro second */
}
/*
	Function Name        : IR_SendStartBit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the start of the frame
*/
void IR_voidSendStartBit(IR_parameters_t IR_Obj)
{
	u8State = CTC_START_LEVEL_HIGH;
	IR_SendLogicHigh(IR_Obj,CTC_START_LEVEL_HIGH);
}
/*
	Function Name        : IR_SendLogicLow
	Function Returns     : void
	Function Arguments   : struct and CTCT value
	Function Description : send the logic low
*/
void IR_SendLogicLow(IR_parameters_t IR_Obj, u8 u8CTC_Val)
{
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin,STD_LOW);
	TIMER2_void_Init();
	TIMER2_void_SetCompareVal(u8CTC_Val);
	TIMER2_void_SetCTCCallBack(voidISRctc);
	TIMER2_void_EnableCTCInt();
}
/*
	Function Name        : IR_SendLogicHigh
	Function Returns     : void
	Function Arguments   : struct and CTC value
	Function Description : send the logic high
*/
void IR_SendLogicHigh(IR_parameters_t IR_Obj, u8 u8CTC_Val)
{
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin,STD_HIGH);
	TIMER2_void_Init();
	TIMER2_void_SetCompareVal(u8CTC_Val);
	TIMER2_void_SetCTCCallBack(voidISRctc);
	TIMER2_void_EnableCTCInt();	
}
/*
	Function Name        : IR_voidTransmit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the IR signal
*/
void IR_voidTransmit(IR_parameters_t IR_Obj)
{
  IR_voidSendStartBit(IR_Obj);
}
/*
	Function Name        : voidISRctc
	Function Returns     : void
	Function Arguments   : void
	Function Description : ISR of the timer 
*/
void voidISRctc(void)
{
	static u8 u8counter = 0;
	if( u8State == CTC_START_LEVEL_HIGH )
	{
		u8State =CTC_START_LEVEL_LOW;
		IR_SendLogicLow(IR_Global_Obj,CTC_START_LEVEL_LOW);
	}else if( u8State == CTC_START_LEVEL_LOW )
	{
		u8State = CTC_DATA_LEVEL_HIGH;
		IR_SendLogicHigh(IR_Global_Obj,CTC_DATA_LEVEL_HIGH);
		/* Disable for checking */
		
	}else if( u8State == CTC_DATA_LEVEL_HIGH )
	{
		if(CHECK_BIT(u32Concat, u8counter) == 1)
		{
			u8State = CTCT_DATA_LOW_1;
			IR_SendLogicLow(IR_Global_Obj,CTCT_DATA_LOW_1);
		}
		else
		{
			u8State = CTCT_DATA_LOW_0;
			IR_SendLogicLow(IR_Global_Obj,CTCT_DATA_LOW_0);	
		}
		
		u8counter++;
		
	}else if( u8State == CTCT_DATA_LOW_0 || u8State == CTCT_DATA_LOW_1)
	{
		// check on counter for number of bits
		u8State = CTC_DATA_LEVEL_HIGH;
		IR_SendLogicHigh(IR_Global_Obj,CTC_DATA_LEVEL_HIGH);
		if(u8counter == 32)
		{
			u8State = IDLE_STATE;
		}
	}else if( u8State == IDLE_STATE ){
		TIMER2_void_DisableCounting();
		// shall send an end bit TBD
	}
	
}

void IR_void_SendStartBit_Polling(IR_parameters_t IR_Obj)
{
	
}
void IR_void_Polling_Transmit(IR_parameters_t IR_Obj)
{
	IR_void_SendStartBit_Polling(IR_Obj);
}

void IR_void_Polling_Action(IR_parameters_t IR_Obj)
{
	
}