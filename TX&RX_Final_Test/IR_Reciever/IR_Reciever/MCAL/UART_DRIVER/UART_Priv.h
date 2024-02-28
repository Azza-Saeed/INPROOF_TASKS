/*
 * UART_Priv.h
 *
 *  Created on: Dec 19, 2023
 *      Author: joe
 */

#ifndef MCAL_UART_DRIVER_UART_PRIV_H_
#define MCAL_UART_DRIVER_UART_PRIV_H_

#define BAUD_PRESCALE (((F_CPU_M) / (USART_BAUDRATE * 16UL)) - 1)

#define UDR_REG     *((volatile u8 *) 0x2C)

#define UCSRA_REG   *((volatile u8 *) 0x2B)
#define UCSRB_REG   *((volatile u8 *) 0x2A)
#define UCSRC_REG   *((volatile u8 *) 0x40)


#define UBRRH_REG  *((volatile u8 *) 0x40)
#define UBRRL_REG  *((volatile u8 *) 0x29)



/********** USART Control and Status Register A – UCSRA ************/
#define RXC    7
#define TXC    6
#define UDRE   5
#define FE     4
#define DOR    3
#define PE     2
#define U2X    1
#define MPCM   0
/********** USART Control and Status Register B – UCSRB ************/
#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0
/********** USART Control and Status Register C – UCSRC ************/
#define URSEL    7
#define UMSEL    6
#define UPM1     5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0    1
#define UCPOL    0
/**********  Character Size Macros************/
#define BIT5    0
#define BIT6    1
#define BIT7    2
#define BIT8    3
#define BIT9    4
/**********   Mode Select Macros************/
#define ASYN_OP    0
#define SYN_OP     1
/**********   Parity Mode Macros************/
#define PARITY_DISABLED    0
#define PARITY_EVEN        1
#define PARITY_ODD         2

#endif /* MCAL_UART_DRIVER_UART_PRIV_H_ */
