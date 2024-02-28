/*
 * IR_Transmitter_MCU.c
 *
 * Created: 14/02/2024 12:19:41 
 *  Author: Azza Saeed
 */ 


#include "App.h"

int main(void)
{
	App_vidInit();
	
    while(1)
    {
        App_vidMain(); 
    }
}