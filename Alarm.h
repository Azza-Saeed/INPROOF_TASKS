/*
 * App.h
 *
 * Created: 22/01/2024 01:32:34 م
 *  Author: Azza Saeed
 */ 


#ifndef APP_H_
#define APP_H_

#define F_CPU 16000000UL
#include <util/delay.h>

#include "Std_Types.h"
#include "bit_math.h"

#include "GIE.h"
#include "dio.h"
#include "TIMR0_int.h"
#include "TIMR0_config.h"
//#include "Configuration.h"

#define DUTY_CYCLE 70

void Alarm_voidInit(u8 port, u8 pin);

void Alarm_voidMain(void);

f32 Alarm_voidTime(f32 freq);

void Alarm_voidOn(f32 total_time, u8 duty_cycle);

void Alarm_voidOff(void);

void Alarm_voidAction(u8 duty_cycle);

void fptr(void);
#endif /* APP_H_ */