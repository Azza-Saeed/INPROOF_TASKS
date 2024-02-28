/*
 * IR_Reciver_Interface.h
 *
 *  Created on: Jan 22, 2024
 *      Author: joe
 */

#ifndef HAL_IR_RECIVER_IR_RECIVER_INTERFACE_H_
#define HAL_IR_RECIVER_IR_RECIVER_INTERFACE_H_

typedef enum IR_state {
	IR_NONACTIVE = 0, IR_ACTIVE = 1,
} IR_state;

/**************************************************/
/**********************Public Functions************/
/**************************************************/
void IR_VidIntialize(void);
u8 * IRS_u8GetRead(void);
/***********IR1 Fun ************/
IR_state IR1_u8GetRead(void);
void IR1_BaseNEC() ;
void IR1_vidResetData() ;
/******************************/
/***********IR2 Fun ************/
IR_state IR2_u8GetRead(void);
void IR2_BaseNEC() ;
void IR2_vidResetData() ;
/******************************/
/***********IR3 Fun ************/
IR_state IR3_u8GetRead(void);
void IR3_BaseNEC() ;
void IR3_vidResetData() ;
/******************************/
/***********IR4 Fun ************/
IR_state IR4_u8GetRead(void);
void IR4_BaseNEC() ;
void IR4_vidResetData() ;
/******************************/
/***********IR5 Fun ************/
IR_state IR5_u8GetRead(void);
void IR5_BaseNEC() ;
void IR5_vidResetData() ;
/******************************/
/***********IR6 Fun ************/
IR_state IR6_u8GetRead(void);
void IR6_BaseNEC() ;
void IR6_vidResetData() ;
/******************************/
/***********IR7 Fun ************/
IR_state IR7_u8GetRead(void);
void IR7_BaseNEC() ;
void IR7_vidResetData() ;
/******************************/
/***********IR8 Fun ************/
IR_state IR8_u8GetRead(void);
void IR8_BaseNEC() ;
void IR8_vidResetData() ;
/******************************/
typedef enum RepeatState {
	NOT_REPEAT = 0, REPEAT = 1,
} RepeatState;

typedef enum OverflowState {
	NO = 0, YES = 1,
} OverflowState;




#endif /* HAL_IR_RECIVER_IR_RECIVER_INTERFACE_H_ */
