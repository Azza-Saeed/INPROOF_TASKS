/*
 * UART_Prog.c
 *
 *  Created on: Dec 19, 2023
 *      Author: joe
 */

/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"
/********************/
#include "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Priv.h"
#include <avr/interrupt.h>
#include <stdio.h>


static u8 UART_u8ResData = 0;

void UART_vidInit()
{


	UCSRB_REG |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE); /* Turn on the transmission and reception */

	/* Select the Mode  for UART */
	switch (USART_MODE) {
	case ASYN_OP:
		CLR_BIT(UCSRC_REG, UMSEL);
		break;
	case SYN_OP:
		SET_BIT(UCSRC_REG, UMSEL);
		break;
	}
	/* Select the character sizes */
	switch (USART_PARITY_MODE) {
	case PARITY_DISABLED:
		CLR_BIT(UCSRC_REG, UPM0);
		CLR_BIT(UCSRC_REG, UPM1);
		break;
	case PARITY_EVEN:
		SET_BIT(UCSRC_REG, UPM0);
		CLR_BIT(UCSRC_REG, UPM1);
		break;
	case PARITY_ODD:
		SET_BIT(UCSRC_REG, UPM0);
		SET_BIT(UCSRC_REG, UPM1);
		break;
	}
	/* Select the character sizes */
	switch (USART_CHAR_SIZE) {
	case BIT5:
		CLR_BIT(UCSRC_REG, UCSZ0);
		CLR_BIT(UCSRC_REG, UCSZ1);
		CLR_BIT(UCSRB_REG, UCSZ2);
		break;
	case BIT6:
		SET_BIT(UCSRC_REG, UCSZ0);
		CLR_BIT(UCSRC_REG, UCSZ1);
		CLR_BIT(UCSRB_REG, UCSZ2);
		break;
	case BIT7:
		CLR_BIT(UCSRC_REG, UCSZ0);
		SET_BIT(UCSRC_REG, UCSZ1);
		CLR_BIT(UCSRB_REG, UCSZ2);
		break;
	case BIT8:
		SET_BIT(UCSRC_REG, UCSZ0);
		SET_BIT(UCSRC_REG, UCSZ1);
		CLR_BIT(UCSRB_REG, UCSZ2);
		break;
	case BIT9:
		SET_BIT(UCSRC_REG, UCSZ0);
		SET_BIT(UCSRC_REG, UCSZ1);
		SET_BIT(UCSRB_REG, UCSZ2);
		break;
	}
	UCSRC_REG |= (1 << URSEL);
	UBRRL_REG = BAUD_PRESCALE; /* Load lower 8-bits of the baud rate */
	UBRRH_REG = (BAUD_PRESCALE >> 8); /* Load upper 8-bits */
	// Enable global interrupt
	SET_BIT(SREG, 7);

}
void UART_Sendu32Value(unsigned int val) {
	// Send 32-bit value byte by byte
	char hex_string[9]; // 8 characters for hexadecimal representation plus null terminator

	// Convert the number to hexadecimal string
	sprintf(hex_string, "%08X", val);

	// Send the hexadecimal string via UART
	for (int i = 0; i < 8; i++) {
		UART_vidSendChar(hex_string[i]);
	}

}

void UART_vidSendChar(u8 ch) {
	while (!(UCSRA_REG & (1 << UDRE)))
		; /* Wait for empty transmit buffer */
	UDR_REG = ch;
}
u8 UART_u8GetChar()
{
	while ((UCSRA_REG & (1 << RXC)) == 0)
		;
	/* Clear Flag */
	SET_BIT(UCSRA_REG, RXC);
	/* Wait till data is received */
	return (UDR_REG); /* Return the byte */

}
u8 UART_u8GetCharFromINT() {
	return UART_u8ResData;
}


ISR( USART_RXC_vect) {
	UART_u8ResData = UDR_REG;
	UDR_REG = UART_u8ResData;
}
