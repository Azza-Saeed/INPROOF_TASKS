/*
 * IR_Rec.h
 *
 * Created: 29/01/2024 09:42:27 
 *  Author: Azza Saeed
 */ 


#ifndef IR_REC_H_
#define IR_REC_H_

#define F_CPU 16000000UL 
#include <util/delay.h>

#define COMPARE_MATCH_VAL 2

void IR_voidInit(void);

void IR_voidGetFrame(void);

void voidISRTimer(void);

#endif /* IR_REC_H_ */