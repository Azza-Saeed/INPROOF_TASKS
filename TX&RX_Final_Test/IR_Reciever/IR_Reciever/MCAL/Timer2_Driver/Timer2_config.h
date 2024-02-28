/*
 * Timer0_config.h
 *
 *  Created on: Dec 24, 2023
 *      Author: joe
 */

#ifndef MCAL_TIMER2_DRIVER_TIMER2_CONFIG_H_
#define MCAL_TIMER2_DRIVER_TIMER2_CONFIG_H_

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
#define TIMER2_PRS_SELECT   CLK_64
#define F_CPU_2      16000000L

#endif /* MCAL_TIMER2_DRIVER_TIMER2_CONFIG_H_ */
