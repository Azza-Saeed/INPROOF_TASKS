﻿/*
 * Schaduller.c
 *
 * Created: 24/01/2024 02:59:20 م
 *  Author: Azza Saeed
 */ 


#include "APP.h"

int main(void)
{
	App_voidIit();
	
	//Create_u8task(0,100,1,Blue_led);
	//Create_u8task(1,200,1000,Green_Led);
	Create_u8task(0,0.0005,0,Red_Led);
	
	Start_voidSchaduler();
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}