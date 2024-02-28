/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *      File:  TIMER2_int.h
 *		Module: TIMER2
 *  Description:  TIMER2 Functions prototypes    
 *  
 *********************************************************************************************************************/

#ifndef _TIMER2_INT_H
#define _TIMER2_INT_H

#include "TIMR02_priv.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void TIMER2_void_Init(void);

void TIMER2_void_SetTimerReg(u8 Copy_uint8Val);

void TIMER2_void_SetCompareVal(u8 Copy_uint8Val);

void TIMER2_void_EnableOVInt(void);

void TIMER2_void_DisableOVInt(void);

void TIMER2_void_EnableCTCInt(void);

void TIMER2_void_DisableCTCInt(void);

void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;


#endif /* TIMER2_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: TIMER2_int.h
 *********************************************************************************************************************/
