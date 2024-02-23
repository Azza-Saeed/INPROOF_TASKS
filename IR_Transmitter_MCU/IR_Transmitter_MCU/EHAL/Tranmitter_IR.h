/*
 * Tranmitter_IR.h
 *
 * Created: 04/02/2024 09:22:45 
 *  Author: Azza Saeed
 */ 


#ifndef TRANMITTER_IR_H_
#define TRANMITTER_IR_H_

#define F_CPU 16000000UL
#include <util/delay.h>

#include "bit_math.h"
#include "Std_Types.h"

#include "dio.h"
#include "TIMR2_int.h"

typedef struct IR_parameters{
	u8 u8port;
	u8 u8pin;
	u8 u8Data;
	u8 u8Address;
}IR_parameters_t;

#define SET_BIT_PULSE_TIMES 9
#define HIGH_START_ITERATION 336

#define SET_BIT_PULSE_SPACE_TIMES 4.5
#define LOW_START_ITERATION 173

#define LOW_PULSE_BURST_TIMES 563
#define LOW_DATA_ITERATION 21

#define LOW_PULSE_BURST_SPACE_TIMES 0.563

#define HIGH_PULSE_BURST_TIMES 0.563
#define HIGH_PULSE_BURST_SPACE_TIMES 1.6875
#define HIGH_DATA_ITERATION 65

#define END_BURST_TIMES 0.563

#define HIGH_PULSE_TIME 0.011
#define LOW_PULSE_TIME 0.0101

#define MAXIMUM_LENGTH 32

#define NUMBER_OF_SENSORS 8
#define MAX_NUMBER_BITS 8

#define HALF_PULSE_TIME (24)

void IR_voidInit(IR_parameters_t IR_Obj);

void IR_voidSendStartBit(IR_parameters_t IR_Obj);

void IR_voidTransmitData(IR_parameters_t IR_Obj);

void IR_voidTransmitFrame(IR_parameters_t IR_Obj);

void IR_voidSendPulses(IR_parameters_t IR_Obj);

void IR_voidEndBit(IR_parameters_t IR_Obj);

/************************************************* The prototype of the transmit IR signal with timer ******************************************************/

void IR_voidSendPulses_timer(IR_parameters_t IR_Obj);

void IR_voidSendStartBit_timer(IR_parameters_t IR_Obj);

void IR_voidTransmitData_timer(IR_parameters_t IR_Obj);

void IR_voidEndBit_timer(IR_parameters_t IR_Obj);

void IR_voidTransmitFrame_timer(IR_parameters_t IR_Obj);

void IR_voidNew(IR_parameters_t IR_Obj);

#endif /* TRANMITTER_IR_H_ */