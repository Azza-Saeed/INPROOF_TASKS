/*
 * Alarm_New_Version.c
 *
 * Created: 13/02/2024 09:32:50 ص
 *  Author: Azza Saeed
 */ 


#include "Std_Types.h"
#include "bit_math.h"

#include "dio.h"
#include "Scheduler_interface.h"

#include "Alarm.h"

void ALarm_Task(void);

u16 u16ActiveCounter=0;

int main(void)
{
	Alarm_parameters_t Alarm_Obj={DIO_PORTC,DIO_PIN1};
		
	Alarm_vidInit(Alarm_Obj);
	
	Create_u8task(0,1,0,ALarm_Task);
	
	Start_voidSchaduler();
	
    while(1)
    {
		
    }
}
void ALarm_Task(void)
{
	u16ActiveCounter++;
	
	if( u16ActiveCounter <= 1000 )
	{
		Alarm_vidActive();
	}
	else if( u16ActiveCounter == 1500 )
	{
		Alarm_vidDeactive();
		u16ActiveCounter=0;
	}	
	else{
		
	}	

}