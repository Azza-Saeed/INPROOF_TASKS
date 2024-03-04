/*
 * ASM.h
 *
 *  Created: 03/03/2024 09:36:42 
 *  Author: Azza Saeed
 */ 


#ifndef ASM_H_
#define ASM_H_

/********************************************* INCLUDING LIBRARY ***************************************/
#include "bit_math.h"
#include "Std_Types.h"

typedef struct{
	u8 Alarm_State;
	u8 Motor_State;
	u8 RJB1_State;
	u8 RJB2_State;
	u8 Uart_state;
}Struct_Obj_t;

/************************************* DEGINE MACROSE FOR ALARM ***********************************/
#define OFF		0
#define ON		1

/************************************* DEFINE MACROSE FOR RJB ************************************/
#define BLUE	0
#define GREEN	1
#define RED		2

/************************************* DEFINE MACROSE FOR MOTOR ********************************/
#define CENTER  0
#define RIGHT   1
#define LEFT    2


Struct_Obj_t ASM_PrepareOutputs(void);

void ASM_GatherInputs(void);



#endif /* ASM_H_ */