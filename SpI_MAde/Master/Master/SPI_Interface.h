/***
 *       _____ ____  ____     ____      __            ____                  __
 *      / ___// __ \/  _/    /  _/___  / /____  _____/ __/___ _________    / /_
 *      \__ \/ /_/ // /      / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     ___/ / ____// /     _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /____/_/   /___/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                  /_____/
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "SPI_Private.h"
#include "CPU_Configuration.h"
#include "DIO_Interface.h"

/* Concatenation Function */
#define VECTOR(x) __vector_##x
/* ISR Body */
#define ISR(vector) \
void vector (void) __attribute__ ((signal,used, externally_visible)) ; \
void vector (void)

/* Pointer to Function*/
void (*ptr_func)(void);

typedef struct {
	u8 Int_Enable;
	u8 Data_Order;
	u8 Polarity;
	u8 Phase;
	u8 Prescaler;

} Master_Config;

typedef struct {
	u8 Int_Enable;
	u8 Data_Order;
	u8 Polarity;
	u8 Phase;

} Slave_Config;



void Global_Interrupt_Enable();
void SPI_Init_Master(Master_Config *My_Config);
void SPI_Init_Slave(Slave_Config *My_Config);
void SPI_Send_Receive_Synch_Byte(u8 byte, u8 *received);
void SPI_Read_Data(u8 *var);
void SPI_Send_ASynch_Byte(u8 byte);
void SPI_Set_CallBack(void (*func)(void));

void Master_Send(u8 data);
void Slave_Send(u8 data);
u8 Master_Receive();

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
