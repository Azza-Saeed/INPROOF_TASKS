/*
 * Alarm_Update.c
 *
 * Created: 12/02/2024 03:47:22 م
 *  Author: Dell
 */ 


#include "Alarm.h"

int main(void)
{
	Alarm_voidInit(DIO_PORTC,DIO_PIN1);
	
    while(1)
    {
       Alarm_voidMain();
    }
}