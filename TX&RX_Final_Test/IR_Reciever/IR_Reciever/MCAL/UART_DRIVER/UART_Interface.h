/*
 * UART_Interface.h
 *
 *  Created on: Dec 19, 2023
 *      Author: joe
 */

#ifndef MCAL_UART_DRIVER_UART_INTERFACE_H_
#define MCAL_UART_DRIVER_UART_INTERFACE_H_

void UART_vidInit();
void UART_vidSendChar(u8 ch);
u8 UART_u8GetChar();
u8 UART_u8GetCharFromINT();

void UART_Sendu32Value(unsigned int val);

u8 FromHexTOStringHex(u8 val);
#endif /* MCAL_UART_DRIVER_UART_INTERFACE_H_ */
