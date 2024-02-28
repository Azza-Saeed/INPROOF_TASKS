/*
 * Timer_confg.h
 *
 *  Created on: Oct 20, 2023
 *      Author: youse
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_CONFG_H_
#define MCAL_TIMER_DRIVER_TIMER_CONFG_H_



/* Description : TIMER Mode configuration */
/* range       : NORMAL_MODE   PWM_MODE  CTC_MODE   FAST_PWM_MODE*/
#define TIMER_MODE   CTC_MODE






/* Description : Timer  Prescaler configuration */
/* range
  NO_CLK   : No clock source (Timer/Counter stopped)
  NO_PRS   : clk/(No prescaling)
  CLK_8    : clk/8 (From prescaler)
  CLK_64   : clk/64 (From prescaler)
  CLK_256  : clk/256 (From prescaler)
  CLK_1024 : clk/1024 (From prescaler)
  CLK_EXT_FALLING :  External clock source on T0 pin. Clock on falling edge
  CLK_EXT_RISING   : External clock source on T0 pin. Clock on rising edge */
#define TIMER_PRS_SELECT   CLK_8


#define TIMER_SYSTEM  8

#define TIMER_RESOLUTION  8
#endif /* MCAL_TIMER_DRIVER_TIMER_CONFG_H_ */
