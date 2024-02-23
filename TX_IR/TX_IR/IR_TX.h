/*
 * TX.h
 *
 * Created: 29/01/2024 02:15:52 
 *  Author: Azza Saeed
 */ 


#ifndef TX_H_
#define TX_H_

typedef enum state{
	STD_OK,
	STD_NOK
}TRANSIMISSION_STATE;

typedef struct IR_parameters{
	u8 u8port;
	u8 u8pin;
	u8 u8Data;
	u8 u8Address;
}IR_parameters_t;

#define SET_BIT_PULSE_TIMES 9000
#define SET_BIT_PULSE_SPACE_TIMES 4500

#define LOW_PULSE_BURST_TIMES 563
#define LOW_PULSE_BURST_SPACE_TIMES 563

#define HIGH_PULSE_BURST_TIMES 563
#define HIGH_PULSE_BURST_SPACE_TIMES 16878 

#define CTC_START_LEVEL_HIGH	141
#define CTC_START_LEVEL_LOW		70
#define CTC_DATA_LEVEL_HIGH		9
#define CTCT_DATA_LOW_0			9
#define CTCT_DATA_LOW_1			26
#define IDLE_STATE              0


void IR_voidInit(IR_parameters_t IR_Obj);

void IR_voidSendStartBit(IR_parameters_t IR_Obj);

void IR_voidSendLogicLow(IR_parameters_t IR_Obj, u8 u8CTC_Val);

void IR_voidSendLogicHigh(IR_parameters_t IR_Obj, u8 u8CTC_Val);

void IR_voidTransmit(IR_parameters_t IR_Obj);

void IR_void_Polling_Transmit(IR_parameters_t IR_Obj);

void voidISRctc(void);

#endif /* TX_H_ */