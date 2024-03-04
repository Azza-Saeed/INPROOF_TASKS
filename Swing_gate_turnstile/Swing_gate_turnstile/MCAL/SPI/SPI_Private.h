/***
 *       _____ ____  ____     ____       _             __         __
 *      / ___// __ \/  _/    / __ \_____(_)   ______ _/ /____    / /_
 *      \__ \/ /_/ // /     / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     ___/ / ____// /     / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /____/_/   /___/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                  /_____/
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

//#include "CPU_Configuration.h"

#define SREG	*((volatile u8 *) 0x5F)

#define SPDR	*((volatile u8 *) 0x2F)

#define SPSR 	*((volatile u8 *) 0x2E)
#define SPI2X   0
#define WCOL    6
#define SPIF    7


#define SPCR 	*((volatile u8 *) 0x2D)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7


#define MISO_PORT   DIO_PORTB
#define MISO_PIN	DIO_PIN6

#define MOSI_PORT	DIO_PORTB
#define MOSI_PIN	DIO_PIN5

#define CLOCK_PORT	DIO_PORTB
#define CLOCK_PIN	DIO_PIN7

#define SS_PORT		DIO_PORTB
#define SS_PIN		DIO_PIN4

#define SPI_DISABLE				0
#define SPI_ENABLE				1

#define SPI_INTERRUPT_DISABLE	0
#define SPI_INTERRUPT_ENABLE	1


#define SPI_MSB					0
#define SPI_LSB					1

#define SPI_SLAVE				0
#define SPI_MASTER				1

#define SPI_RISING_LEADING		0
#define SPI_FALLING_LEADING		1

#define SPI_SAMPLE_LEADING		0
#define SPI_SAMPLE_SETUP		1

#define SPI_PRESCALER_4			0
#define SPI_PRESCALER_16		1
#define SPI_PRESCALER_64		2
#define SPI_PRESCALER_128		3
#define SPI_PRESCALER_2			4
#define SPI_PRESCALER_8			5
#define SPI_PRESCALER_32		6


#define DUMMY_DATA 				0xFE
#define UPDATE_YOURSELF			0xFD

#endif /* SPI_PRIVATE_H_ */
