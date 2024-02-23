/*
 * Alarm.c
 *
 * Created: 13/02/2024 09:34:01 ص
 *  Author: Azza Saeed
 */ 
#include "Std_Types.h"
#include "bit_math.h"

#include "dio.h"
#include "Alarm.h"

Alarm_parameters_t Alarm_Obj_Global;

void Alarm_vidInit(Alarm_parameters_t Alarm_Obj)
{
	Alarm_Obj_Global.u8port=Alarm_Obj.u8port;
	Alarm_Obj_Global.u8pin=Alarm_Obj.u8pin;
	
	dio_vidConfigChannel(Alarm_Obj.u8port,Alarm_Obj.u8pin,OUTPUT);
}

void Alarm_vidActive(void)
{
	dio_vidFlipChannel(Alarm_Obj_Global.u8port,Alarm_Obj_Global.u8pin);
}

void Alarm_vidDeactive(void)
{
	dio_vidWriteChannel(Alarm_Obj_Global.u8port,Alarm_Obj_Global.u8pin,STD_LOW);
}