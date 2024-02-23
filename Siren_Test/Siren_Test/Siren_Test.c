/*
 * Siren_Test.c
 *
 * Created: 22/01/2024 01:30:25 م
 *  Author: Azza Saeed
 */ 

#define F_CPU 16000000UL

#include "dio.h"

#include "Alarm_Driver.h"

int main(void)
{
	Alarm_Parameters_t alarm_par={DIO_PORTC,DIO_PIN1};
		
	Alarm_voidInit(alarm_par);

    while(1)
    {
		Alarm_voidOn(alarm_par);
	}       

}