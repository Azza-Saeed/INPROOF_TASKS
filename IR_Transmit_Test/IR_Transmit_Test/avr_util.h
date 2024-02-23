#ifndef AVR_UTIL_H_
#define AVR_UTIL_H_

#include "avr_config.h"
#include "Std_Types.h"

#include <avr/io.h>
#include <stdbool.h>
#include <string.h>

#define BAUD_RATE 1000000
#define CALCULATED_BAUD ((F_CPU / 16 / BAUD_RATE) - 1)

#define UDR				(*(volatile u8* )0x2C)
#define UCSRA				(*(volatile u8* )0x2B)
#define UCSRB				(*(volatile u8* )0x2A)
#define UBRRH				(*(volatile u8* )0x40)
#define UCSRC				(*(volatile u8* )0x40)
#define UBRRL				(*(volatile u8* )0x29)

bool icp_listening_for_rising();
bool icp_listening_for_falling();
void icp_listen_for_rising();
void icp_listen_for_falling();
void usart_init();
void usart_transmit(unsigned char data);
void usart_transmit_string(char* string);

#endif /* AVR_UTIL_H_ */