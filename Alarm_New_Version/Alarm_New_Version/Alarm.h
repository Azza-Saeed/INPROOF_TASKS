/*
 * Alarm.h
 *
 * Created: 13/02/2024 09:34:17 ص
 *  Author: Azza Saeed
 */ 


#ifndef ALARM_H_
#define ALARM_H_

typedef struct{
	u8 u8port;
	u8 u8pin;
}Alarm_parameters_t;


void Alarm_vidInit(Alarm_parameters_t Alarm_Obj);

void Alarm_vidActive(void);

void Alarm_vidDeactive(void);


#endif /* ALARM_H_ */