/*
 * App.c
 *
 * Created: 22/01/2024 01:32:22 
 *  Author: Azza Saeed
 */
#include "Alarm.h"
#include "util/delay.h"
u8 port_number, pin_number;

void Alarm_voidMain(void)
{
	f32 total_time;
	total_time = Alarm_voidGetTime(2);
	Alarm_voidOn(total_time,DUTY_CYCLE);
	//dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
	//_delay_ms(5000);
	
}

void Alarm_voidInit(u8 port, u8 pin)
{
	port_number = port;
	pin_number = pin;
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN2,OUTPUT);
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
	dio_vidConfigChannel(port_number,pin_number,OUTPUT);
	TIMER0_void_Init();
	//dio_vidWriteChannel(DIO_PORTC,DIO_PIN2,STD_HIGH);
	//TIMER0_void_SetCompareVal(255);
	//GIE_voidGlobalInterruptEnable();
	//TIMER0_void_SetCTCCallBack(fptr);
	//TIMER0_void_EnableCTCInt();
}

f32 Alarm_voidGetTime(f32 freq)
{
	f32 total_time;
	
	total_time = (1.0/freq);
	
	return total_time;
}

void Alarm_voidOn(f32 total_time, u8 duty_cycle)
{
	f32 tick_time, compare_match_time, on_time;
	
	tick_time = ( (float)TIMER0_PRESCALER /F_CPU);
	on_time = (total_time) * (duty_cycle/100.0);
	compare_match_time = ((float)on_time / tick_time);
	
	TIMER0_void_SetCompareVal(compare_match_time); //TIMER0_void_SetCompareVal(255);
	GIE_voidGlobalInterruptEnable();
	TIMER0_void_SetCTCCallBack(fptr);
	TIMER0_void_EnableCTCInt();	
	
}

void Alarm_voidOff(void)
{
	TIMER0_void_DisableCTCInt();
	//GIE_voidGlobalInterruptDisable();
}

void fptr(void)
{
	static u32 counter=0;

	if (counter == 62)
	{
		dio_vidWriteChannel(port_number,pin_number, STD_LOW);
		
	}
	else if (counter == 93)
	{
		dio_vidWriteChannel(port_number,pin_number, STD_HIGH);
		counter = 0;
	}
	
	
	counter++;
}
void Alarm_voidAction(u8 duty_cycle)
{
		TIMER0_void_SetCompareVal(duty_cycle); //TIMER0_void_SetCompareVal(255);
		GIE_voidGlobalInterruptEnable();
		TIMER0_void_SetCTCCallBack(fptr);
		TIMER0_void_EnableCTCInt();
}