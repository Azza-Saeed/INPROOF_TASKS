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
#include "dio.h"

/* Concatenation Function */
#define VECTOR(x) __vector_##x
/* ISR Body */
#define ISR(vector) \
void vector (void) __attribute__ ((signal,used, externally_visible)) ; \
void vector (void)

/* Pointer to Function*/
void (*ptr_func)(void);

typedef struct {
	UINT8_t Int_Enable;
	UINT8_t Data_Order;
	UINT8_t Polarity;
	UINT8_t Phase;
	UINT8_t Prescaler;

} Master_Config;

typedef struct {
	UINT8_t Int_Enable;
	UINT8_t Data_Order;
	UINT8_t Polarity;
	UINT8_t Phase;

} Slave_Config;



ERROR_STATE Global_Interrupt_Enable();
ERROR_STATE SPI_Init_Master(Master_Config *My_Config);
ERROR_STATE SPI_Init_Slave(Slave_Config *My_Config);
ERROR_STATE SPI_Send_Receive_Synch_Byte(UINT8_t byte, UINT8_t *received);
ERROR_STATE SPI_Read_Data(UINT8_t *var);
ERROR_STATE SPI_Send_ASynch_Byte(UINT8_t byte);
ERROR_STATE SPI_Set_CallBack(void (*func)(void));

void Master_Send(UINT8_t data);
UINT8_t Master_Receive();

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
