/*
 * Timer2.Prog.c
 *
 *  Created on: Dec 24, 2023
 *      Author: joe
 */

/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"
/********************/
#include "Timer2_Interface.h"
#include "Timer2_Priv.h"
#include "Timer2_config.h"
#include <avr/interrupt.h>


void Timer2_vidInit() {
	TCNT2 = 5;
	TIMSK_REG = (2 << TOIE2);
	TCCR2_REG = (0 << WGM21) | (0 << WGM20);  //   normal mode

	// set the prescaler
	switch (TIMER2_PRS_SELECT) {
	case NO_CLK:
		CLR_BIT(TCCR2_REG, CS20);
		CLR_BIT(TCCR2_REG, CS21);
		CLR_BIT(TCCR2_REG, CS22);
		break;
	case NO_PRS:
		SET_BIT(TCCR2_REG, CS20);
		CLR_BIT(TCCR2_REG, CS21);
		CLR_BIT(TCCR2_REG, CS22);
		break;

	case CLK_8:
		CLR_BIT(TCCR2_REG, CS20);
		SET_BIT(TCCR2_REG, CS21);
		CLR_BIT(TCCR2_REG, CS22);
		break;

	case CLK_64:
		SET_BIT(TCCR2_REG, CS20);
		SET_BIT(TCCR2_REG, CS21);
		CLR_BIT(TCCR2_REG, CS22);
		break;

	case CLK_256:
		CLR_BIT(TCCR2_REG, CS20);
		CLR_BIT(TCCR2_REG, CS21);
		SET_BIT(TCCR2_REG, CS22);
		break;

	case CLK_1024:
		SET_BIT(TCCR2_REG, CS20);
		CLR_BIT(TCCR2_REG, CS21);
		SET_BIT(TCCR2_REG, CS22);
		break;
	case CLK_EXT_FALLING:
		CLR_BIT(TCCR2_REG, CS20);
		SET_BIT(TCCR2_REG, CS21);
		SET_BIT(TCCR2_REG, CS22);
		break;
	case CLK_EXT_RISING:
		SET_BIT(TCCR2_REG, CS20);
		SET_BIT(TCCR2_REG, CS21);
		SET_BIT(TCCR2_REG, CS22);
		break;

	}
	// Enable global interrupt
	SET_BIT(SREG_REG, I);
}

u8 Timer2_u8NTC2Val()
{
	return TCNT2 ;
}
ISR(TIMER2_OVF_vect){
	TCNT2 =5;

}
