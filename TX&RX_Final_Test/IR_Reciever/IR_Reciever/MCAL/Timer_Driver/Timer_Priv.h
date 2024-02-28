/*
 * Timer_Priv.h
 *
 *  Created on: Oct 20, 2023
 *      Author: youse
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_PRIV_H_
#define MCAL_TIMER_DRIVER_TIMER_PRIV_H_

/************Private Macros *********/
/*Timer Registers Definitions*/
#define SREG_REG         (*((volatile u8 *)(0x5F)))
#define TCCR0_REG        (*((volatile u8 *)(0x53)))
#define TCNT0_REG        (*((volatile u8 *)(0x52)))

#define TIMSK_REG        (*((volatile u8 *)(0x59)))
#define TIFR_REG         (*((volatile u8 *)(0x58)))
//#define DDRB        *((volatile u8*)0x37)


#define TCCR1A_REG        (*((volatile u8 *)(0x4F)))
#define TCCR1B_REG        (*((volatile u8 *)(0x4E)))
#define TCNT1H_REG        (*((volatile u8 *)(0x4D)))
#define TCNT1L_REG        (*((volatile u8 *)(0x4C)))
#define TCNT1_REG         (*((volatile u16 *)(0x4C)))
#define OCR1AH_REG        (*((volatile u8 *)(0x4B)))
#define OCR1AL_REG        (*((volatile u8 *)(0x4A)))
#define OCR1A_REG         (*((volatile u16 *)(0x4A)))

#define OCR1BH_REG        (*((volatile u8 *)(0x49)))
#define OCR1BL_REG        (*((volatile u8 *)(0x48)))
#define OCR1B_REG         (*((volatile u16 *)(0x48)))

#define ICR1H_REG         (*((volatile u8 *)(0x47)))
#define ICR1L_REG         (*((volatile u8 *)(0x46)))

#define ICR1_REG          (*((volatile u16 *)(0x46)))

//Timer/Counter Interrupt Mask Register – TIMSK
#define TICIE1_PIN 5
#define OCIE1A_PIN 4
#define OCIE1B_PIN 3
#define TOIE1_PIN  2


// Timer/Counter1 Control Register A – TCCR1A BINS
#define COM1A1_PIN   7
#define COM1A0_PIN   6
#define COM1B1_PIN   5
#define COM1B0_PIN   4
#define FOC1A_PIN    3
#define FOC1B_PIN    2
#define WGM11_PIN    1
#define WGM10_PIN    0

// Timer/Counter Interrupt Mask Register – TIMSK  BINS
#define OCIE2_PIN    7
#define TOIE2_PIN   6
#define TICIE1_PIN   5
#define OCIE1A_PIN   4
#define OCIE1B_PIN   3
#define TOIE1_PIN    2
#define OCIE0_PIN    1
#define TOIE0_PIN    0
// Timer/Counter Interrupt Flag Register – TIFR  BINS
#define OCF2_PIN    7
#define TOV2_PIN    6
#define ICF1_PIN    5
#define OCF1A_PIN   4
#define OCF1B_PIN   3
#define TOV1_PIN    2
#define OCF0_PIN    1
#define TOV0_PIN    0
// SREG Bits
#define I_PIN    7
//Timer/Counter1 Control Register B – TCCR1B BINS
#define ICNC1_PIN   7
#define ICES1_PIN   6
#define WGM13_PIN   4
#define WGM12_PIN   3
#define CS12_PIN    2
#define CS11_PIN    1
#define CS10_PIN    0
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
#endif /* MCAL_TIMER_DRIVER_TIMER_PRIV_H_ */
