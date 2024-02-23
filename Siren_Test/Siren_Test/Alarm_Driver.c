/*
 * Alarm_Driver.c
 *
 * Created: 08/02/2024 04:09:01 م
 *  Author: Azza Saeed
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "bit_math.h"
#include "Std_Types.h"

#include "dio.h"

#include "Alarm_Driver.h"


void Alarm_voidInit(Alarm_Parameters_t Alarm_Obj)
{
	dio_vidConfigChannel(Alarm_Obj.u8port, Alarm_Obj.u8pin,OUTPUT);
}

void Alarm_voidOn(Alarm_Parameters_t Alarm_Obj)
{
		for(int i=0;i<MAXIMUM_TIME;i++)
		{
			dio_vidWriteChannel(Alarm_Obj.u8port, Alarm_Obj.u8pin,STD_HIGH);
			_delay_ms(ALARM_TONE);
			dio_vidWriteChannel(Alarm_Obj.u8port, Alarm_Obj.u8pin,STD_LOW);
			_delay_ms(ALARM_TONE);
		//	dio_vidFlipChannel(Alarm_Obj.u8port, Alarm_Obj.u8pin);
		}
		_delay_ms(500);
}
