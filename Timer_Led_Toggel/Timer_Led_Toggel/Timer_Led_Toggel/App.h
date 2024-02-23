/*
 * App.h
 *
 * Created: 25/12/2023 06:15:21 م
 *  Author: Dell
 */ 


#ifndef APP_H_
#define APP_H_

#include "Std_Types.h"
#include "bit_math.h"

#include "GIE.h"
#include "dio.h"
#include "TIMR0_int.h"

#define COMPARE_VALUE 100

void App_Main(void);
void App_Init(void);


#endif /* APP_H_ */