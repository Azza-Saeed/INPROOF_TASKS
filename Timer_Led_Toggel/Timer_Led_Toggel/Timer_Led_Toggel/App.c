/*
 * App.c
 */ 
#include "App.h"

void App_Main(void)
{
	dio_vidFlipChannel(DIO_PORTC,DIO_PIN1);
}
void App_Init(void)
{
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN1,OUTPUT);
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(COMPARE_VALUE);
	GIE_voidGlobalInterruptEnable();
	TIMER0_void_SetCTCCallBack(App_Main);
	TIMER0_void_EnableCTCInt();
}