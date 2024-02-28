/*
 * UART_Config.h
 *
 *  Created on: Dec 19, 2023
 *      Author: joe
 */

#ifndef MCAL_UART_DRIVER_UART_CONFIG_H_
#define MCAL_UART_DRIVER_UART_CONFIG_H_

/******************************************************************************/
/********************** configuration for UART ************************/
/******************************************************************************/

/* Description : frequency configuration */
/* range       : Select the frequency  for CPU .
 * 				 Ex : 8MHz , 16MHz , ......
 * 				 */
#define F_CPU_M 16000000UL
/* Define frequency here its 8MHz */
/* Description : Baudrate configuration */
/*               Select the Baudrate  for UART .
 *range       :  2400 , 4800 , 9600 , 19200 , 38400 , 57600 ,115200
 * 				 */
#define USART_BAUDRATE 9600

/* Description :  Character Size configuration */
/*                Select the Character Size  for UART .
 *range        :  BIT5 , BIT6 , BIT7 , BIT8 , BIT9 */
#define USART_CHAR_SIZE   BIT8

/* Description :   Mode Select configuration */
/*                Select the Mode  for UART .
 *range        :  ASYN_OP: Asynchronous Operation
 *             :  SYN_OP : synchronous Operation*/
#define USART_MODE   ASYN_OP

/* Description :   Parity Mode configuration */
/*                 Select the  Parity Mode  for UART .
 *range        :   PARITY_DISABLED : Disabled
 *             :   PARITY_EVEN :  Enabled, Even Parity
 *             :   PARITY_ODD :  Enabled, ODD Parity*/
#define USART_PARITY_MODE   PARITY_DISABLED
#endif /* MCAL_UART_DRIVER_UART_CONFIG_H_ */
