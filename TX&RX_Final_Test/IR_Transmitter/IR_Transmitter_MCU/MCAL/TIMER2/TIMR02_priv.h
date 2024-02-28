/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      File:  TIMER2_priv.h
 *		Module: TIMER2
 *  Description:  TIMER2 HW registers definitions     
 *  
 *********************************************************************************************************************/

#ifndef _TIMER2_PRIV
#define _TIMER2_PRIV

/*	TIMER2 HW Registers Definition	*/
#define TIMSK	 (*(volatile u8 * )0x59)
#define OCR2 	 (*(volatile u8 * )0x43)
#define TCCR2	 (*(volatile u8 * )0x45)
#define TCNT2	 (*(volatile u8 * )0x44)
#define ASSR	 (*(volatile u8 * )0x42)
#define TIFR	 (*(volatile u8 * )0x58)


/*	TIMER2 Modes Definition	*/
#define TIMER2_NORMAL 		1
#define TIMER2_CTC 			2
#define TIMER2_FAST_PWM 	3
#define TIMER2_PHASE_PWM 	4

/*	TIMER2 Prescaller Definition	*/
#define TIMER2_DIV_BY_1			1
#define TIMER2_DIV_BY_8			2
#define TIMER2_DIV_BY_32		3
#define TIMER2_DIV_BY_64		4
#define TIMER2_DIV_BY_128		5
#define TIMER2_DIV_BY_256		6
#define TIMER2_DIV_BY_1024		7

/*	OC2 Action Modes 	*/
#define TIMER2_NO_ACTION	100
#define TIMER2_TOGGLE		12
#define TIMER2_SET			20
#define TIMER2_CLEAR		25


#endif

/**********************************************************************************************************************
 *  END OF FILE: TIMER2_priv.h
 *********************************************************************************************************************/
