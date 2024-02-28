/*
 * Timer0_Priv.h
 *
 *  Created on: Dec 24, 2023
 *      Author: joe
 */

#ifndef MCAL_TIMER2_DRIVER_TIMER2_PRIV_H_
#define MCAL_TIMER2_DRIVER_TIMER2_PRIV_H_


/************Private Macros *********/
/*Timer2 Registers Definitions*/
#define  TCCR2_REG     *((volatile  u8 *)0x45)
#define  TCNT2_REG     *((volatile  u8 *)0x44)
#define  OCR2_REG      *((volatile  u8 *)0x43)
#define  ASSR_REG      *((volatile  u8 *)0x42)
#define  TIMSK_REG     *((volatile  u8 *)0x59)
#define  TIFR_REG      *((volatile  u8 *)0x58)
#define  SREG_REG      *((volatile  u8 *)0x5F)

// Timer/Counter2 Control Register – TCCR2 BINS
#define AS2       3
#define TCN2UB    2
#define OCR2UB    1
#define TCR2UB    0

// Timer/Counter2 Control Register – TCCR2 BINS
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

// Timer/Counter2 Interrupt Mask Register – TIMSK  BINS
#define OCIE2    7
#define TOIE2    6
#define TICIE1   5
#define OCIE1A   4
#define OCIE1B   3
#define TOIE1    2
#define OCIE0    1
#define TOIE0    0
// Timer/Counter2 Interrupt Flag Register – TIFR  BINS
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
// SREG Bits
#define I    7
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
#endif /* MCAL_TIMER2_DRIVER_TIMER2_PRIV_H_ */
