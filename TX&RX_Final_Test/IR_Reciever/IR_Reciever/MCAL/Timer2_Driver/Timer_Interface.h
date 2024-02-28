/*
 * Timer_Interface.h
 *
 *  Created on: Oct 20, 2023
 *      Author: youse
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_
#define MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_

void Timer_set_callback(void(*ptr)(void));
void Timer_VidInt();
void Timer1_Vid_OverFlowMode();
void Timer1_EnableInterrupt() ;
void Timer1_DiableInterrupt() ;
void Timer1_vidResetTCNT1Val();
u16 Timer1_u16GetTCNT1Val();


typedef void (*voidFuncPtr)(void);
/*timer modes */
#define NORMAL_MODE    0
#define PWM_MODE       1
#define CTC_MODE       2
#define FAST_PWM_MODE  3

/*Prescaling mode */
#define NO_CLK            0
#define NO_PRS            1
#define CLK_8             2
#define CLK_64            3
#define CLK_256           4
#define CLK_1024          5
#define CLK_EXT_FALLING   6
#define CLK_EXT_RISING    7
/*interrupt mode */
#define OVERFLOW                  1
#define OUTPUR_COMPARE            2




#endif /* MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_ */
