/*
 * States.h
 *
 * Created: 04/03/2024 10:30:48 
 *  Author: Azza Saeed
 */ 


#ifndef ASM_H_
#define ASM_H_

/****************************** DEFENITION OF ERROR STATES *********************************/
typedef enum{
	STD_TYPES_NOT_OK=0,
	STD_TYPES_OK
}Error_States_t;
/****************************** DEFENETION OF OBSTCALE STATES *****************************/
typedef enum{
	No_Obstacle=0,
	Obstacle,
	Undefine
}Obstcale_state_t;

/****************************** DeFENITION OF STATES **************************************/

Error_States_t Normal_State(void);

Error_States_t Obstcale_Detected_State(void);

Error_States_t Alarm_State(void);


#endif /* ASM_H_ */