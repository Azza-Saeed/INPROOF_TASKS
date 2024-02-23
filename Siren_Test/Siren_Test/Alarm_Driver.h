/*
 * Alarm_Driver.h
 *
 * Created: 08/02/2024 04:09:17 م
 *  Author: Azza Saeed
 */ 


#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_

typedef struct{
	u8 u8port;
	u8 u8pin;
}Alarm_Parameters_t;

#define MAXIMUM_TIME  500

#define ALARM_TONE    0.5 

void Alarm_voidInit(Alarm_Parameters_t Alarm_Obj);

void Alarm_voidOn(Alarm_Parameters_t Alarm_Obj);


#endif /* ALARM_DRIVER_H_ */