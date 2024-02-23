/*
 * App.c
 *
 * Created: 24/01/2024 04:22:44 م
 *  Author: Azza Saeed
 */ 

#include "App.h"

void App_voidIit(void)
{
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN0,OUTPUT);
	//dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN2,OUTPUT);
}
void Blue_led(void)
{
	dio_vidFlipChannel(DIO_PORTC,DIO_PIN2);
}

void Green_Led(void)
{
	dio_vidFlipChannel(DIO_PORTC,DIO_PIN1);
}

void Red_Led(void)
{
	dio_vidFlipChannel(DIO_PORTC,DIO_PIN0);
}