/*
 * IR_Reciver_Prive.h
 *
 *  Created on: Jan 22, 2024
 *      Author: joe
 */

#ifndef HAL_IR_RECIVER_IR_RECIVER_PRIVE_H_
#define HAL_IR_RECIVER_IR_RECIVER_PRIVE_H_

/* Section : Data Type  Declarations */
typedef struct {

	u8 port :3;
	u8 pin :3;
	u8 state :1;
	u8 direction :2;
} IR;

typedef enum IR_names {
	IR1 = 0, IR2, IR3, IR4, IR5, IR6,IR7,IR8
} IR_names;

#define NUM_OF_CHECK        20
#define NUM_OF_BIT_FRAME    32
#define NUM1_NEC_TIME     1200
#define NUM0_NEC_TIME     550
#endif /* HAL_IR_RECIVER_IR_RECIVER_PRIVE_H_ */
