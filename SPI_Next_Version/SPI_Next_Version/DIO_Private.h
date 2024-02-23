/***
 *        ____  ________       ____       _             __         __
 *       / __ \/  _/ __ \     / __ \_____(_)   ______ _/ /____    / /_
 *      / / / // // / / /    / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / /_/ // // /_/ /    / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_____/___/\____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                   /_____/
 */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "CPU_Configuration.h"

/************************************************************************/
/*                          PORT REGISTER:                              */
/************************************************************************/

// PORT A REGISTER:
#define PORTA 	*((volatile UINT8_t*)0x3B)
#define DDRA 	*((volatile UINT8_t*)0x3A)
#define PINA 	*((volatile UINT8_t*)0x39)

// PORT B REGISTER:
#define PORTB 	*((volatile UINT8_t*)0x38)
#define DDRB 	*((volatile UINT8_t*)0x37)
#define PINB 	*((volatile UINT8_t*)0x36)

// PORT C REGISTER:
#define PORTC 	*((volatile UINT8_t*)0x35)
#define DDRC 	*((volatile UINT8_t*)0x34)
#define PINC 	*((volatile UINT8_t*)0x33)

// PORT D REGISTER:
#define PORTD 	*((volatile UINT8_t*)0x32)
#define DDRD 	*((volatile UINT8_t*)0x31)
#define PIND 	*((volatile UINT8_t*)0x30)



#endif /* DIO_PRIVATE_H_ */
