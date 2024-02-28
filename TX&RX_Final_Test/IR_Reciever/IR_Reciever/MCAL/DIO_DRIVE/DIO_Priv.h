/*
 * DIO_Priv.h
 *
 *  Created on: Nov 26, 2023
 *      Author: youse
 */

#ifndef MCAL_DIO_DRIVE_DIO_PRIV_H_
#define MCAL_DIO_DRIVE_DIO_PRIV_H_


#define PORTB_REG  *((volatile u8 *) 0x38)
#define PORTC_REG  *((volatile u8 *) 0x35)
#define PORTD_REG  *((volatile u8 *) 0x32)


#define DDRB_REG  *((volatile u8 *) 0x37)
#define DDRC_REG  *((volatile u8 *) 0x34)
#define DDRD_REG  *((volatile u8 *) 0x31)


#define PINB_REG  *((volatile u8 *) 0x36)
#define PINC_REG  *((volatile u8 *) 0x33)
#define PIND_REG  *((volatile u8 *) 0x30)



#endif /* MCAL_DIO_DRIVE_DIO_PRIV_H_ */