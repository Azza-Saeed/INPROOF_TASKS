/*
 * Transmitter_IR.c
 *
 * Created: 04/02/2024 09:22:27 
 *  Author: Azza Saeed
 */ 
#include "Tranmitter_IR.h"

volatile static IR_parameters_t IR_Global_Obj;
volatile static u32 u32Concat=0;

/*
	Function Name        : IR_voidInit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : initialize the system
*/
void IR_voidInit(IR_parameters_t IR_Obj)
{
	IR_Global_Obj = IR_Obj;
	
//	u32Concat |= IR_Obj.u8Address;			// address bits
//	u32Concat |= (~IR_Obj.u8Address)<<8;	// inverted address bits
//	u32Concat |= (IR_Obj.u8Data)<<16;		// data bits
//	u32Concat |= (~IR_Obj.u8Data)<<24;		// inverted data bits
	
		u32Concat |= IR_Obj.u8Data;			// data bits
	/* IO initialization */
	dio_vidConfigChannel(IR_Obj.u8port, IR_Obj.u8pin,OUTPUT);
	/* Idle */
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin,STD_LOW);
	/* Initialize timer */
	TIMER2_void_Init();
}
/*
	Function Name        : IR_SendStartBit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the start of the frame
*/
void IR_voidSendStartBit(IR_parameters_t IR_Obj)
{
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
	_delay_ms(SET_BIT_PULSE_TIMES);
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
	_delay_ms(SET_BIT_PULSE_SPACE_TIMES);
}




/*
	Function Name        : IR_voidTransmit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the IR Address & Data
*/
void IR_voidTransmitData(IR_parameters_t IR_Obj)
{
	u8 u8Counter=0;

	/* check on data */
	for(u8Counter=0;u8Counter<MAXIMUM_LENGTH;u8Counter++ )
	{
		dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
		_delay_ms(HIGH_PULSE_BURST_TIMES);
		
		if(((u32Concat >> u8Counter) & 1 != 0 ) )
		{
			dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
			_delay_ms(HIGH_PULSE_BURST_SPACE_TIMES);
		}else{
			dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
			_delay_ms(LOW_PULSE_BURST_TIMES);
		}
	}
}
/*
	Function Name        : IR_voidTransmit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the IR signal
*/
void IR_voidTransmitFrame(IR_parameters_t IR_Obj)
{
	/* Sending Start Frame */
	IR_voidSendStartBit(IR_Obj);
	/* Sensing Address & Data */
	IR_voidTransmitData(IR_Obj);
	/* Send the end of the frame */
	IR_voidEndBit(IR_Obj);
}
/*
	Function Name        : IR_voidEndBit
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the end of the frame
*/
void IR_voidEndBit(IR_parameters_t IR_Obj)
{
	dio_vidWriteChannel(IR_Obj.u8port,IR_Obj.u8pin,STD_HIGH);
	_delay_ms(END_BURST_TIMES);
}
/*
	Function Name        : IR_voidSendPulses
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the start of the modulation pulses
*/
void IR_voidSendPulses(IR_parameters_t IR_Obj)
{
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
	_delay_ms(HIGH_PULSE_TIME);
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
	_delay_ms(LOW_PULSE_TIME);
}
///////////////////////////////////////// (version 2)  IR transmitter with timer /////////////////////////////////////////
/*
	Function Name        : IR_voidSendPulses_timer
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the start of the modulation pulses
*/
void IR_voidSendPulses_timer(IR_parameters_t IR_Obj)
{
	TCNT2 =0;
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
	while( TCNT2 <= HALF_PULSE_TIME );
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
	while( TCNT2 <= 2*HALF_PULSE_TIME );
}

/*
	Function Name        : IR_voidSendStartBit_timer
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the start of the frame
*/
void IR_voidSendStartBit_timer(IR_parameters_t IR_Obj)
{
	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
	_delay_ms(SET_BIT_PULSE_TIMES);
	
/*	for(int i=0; i<LOW_START_ITERATION;i++)
	{
		IR_voidSendPulses_timer(IR_Obj);
	}*/

	dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_LOW);
	_delay_ms(4.5);
	
	
}
/*
	Function Name        : IR_voidTransmitData_timer
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the IR Address & Data
*/
/*
void IR_voidTransmitData_timer(IR_parameters_t IR_Obj)
{
	u8 u8Counter=0;

	for(u8Counter=0;u8Counter<MAX_NUMBER_BITS;u8Counter++ )
	{
		
		dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
		_delay_ms(HIGH_PULSE_BURST_TIMES);
	
		if(CHECK_BIT(IR_Obj.u8Address, u8Counter) == 0)
		{
			for(int i=0;i<LOW_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
			
		}else{
			for(int i=0;i<HIGH_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
		}
	}
	for(u8Counter=0;u8Counter<MAX_NUMBER_BITS;u8Counter++ )
	{
		
		dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
		_delay_ms(HIGH_PULSE_BURST_TIMES);
		
		if(CHECK_BIT(~IR_Obj.u8Address, u8Counter) == 0) 
			for(int i=0;i<LOW_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
			
		}else{
			for(int i=0;i<HIGH_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
		}
	}
	
	for(u8Counter=0;u8Counter<MAX_NUMBER_BITS;u8Counter++ )
	{
		
		dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
		_delay_ms(HIGH_PULSE_BURST_TIMES);
		
		if(CHECK_BIT(IR_Obj.u8Data, u8Counter) == 0)
		{
			for(int i=0;i<LOW_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
			
		}else{
			for(int i=0;i<HIGH_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
		}
	}
	
	for(u8Counter=0;u8Counter<MAX_NUMBER_BITS;u8Counter++ )
	{
		
		dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
		_delay_ms(HIGH_PULSE_BURST_TIMES);
		
		if(CHECK_BIT(~IR_Obj.u8Data, u8Counter) == 0)
		{
			for(int i=0;i<LOW_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
			
		}else{
			for(int i=0;i<HIGH_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
		}
	}
}*/
/*
	Function Name        : IR_voidEndBit_timer
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send end of the frame
*/
void IR_voidEndBit_timer(IR_parameters_t IR_Obj)
{
	/* send the high signal */
	/*dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
	_delay_ms(HIGH_PULSE_BURST_TIMES);*/
	/* send the pulse modulation signal */
	/*for(int i=0;i<LOW_DATA_ITERATION;i++)
	{
		IR_voidSendPulses_timer(IR_Obj);
	}*/
			for(int i=0;i<LOW_DATA_ITERATION;i++)
			{
				IR_voidSendPulses_timer(IR_Obj);
			}
}
void IR_voidNew(IR_parameters_t IR_Obj){
	u8 u8Counter=0;
		for(u8Counter=0;u8Counter<MAX_NUMBER_BITS;u8Counter++ )
		{
			/* send the high signal */
			dio_vidWriteChannel(IR_Obj.u8port, IR_Obj.u8pin, STD_HIGH);
			_delay_ms(HIGH_PULSE_BURST_TIMES);
			/* check on the data and send the pulse modulation signal */
			if(CHECK_BIT(IR_Obj.u8Data, u8Counter) == 0)
			{
				for(int i=0;i<20/*LOW_DATA_ITERATION*/;i++)//20
				{
					IR_voidSendPulses_timer(IR_Obj);
				}
				
			}else{
				for(int i=0;i<HIGH_DATA_ITERATION;i++)
				{
					IR_voidSendPulses_timer(IR_Obj);
				}
			}
		}
}
/*
	Function Name        : IR_voidTransmitFrame_timer
	Function Returns     : void
	Function Arguments   : struct
	Function Description : send the IR signal
*/
void IR_voidTransmitFrame_timer(IR_parameters_t IR_Obj)
{
	/* send the start of the frame */
	IR_voidSendStartBit_timer(IR_Obj); 
	/* send the address and data */
	//IR_voidTransmitData_timer(IR_Obj);
	IR_voidNew(IR_Obj);
	/* send the end of the frame */
	IR_voidEndBit_timer(IR_Obj);
}