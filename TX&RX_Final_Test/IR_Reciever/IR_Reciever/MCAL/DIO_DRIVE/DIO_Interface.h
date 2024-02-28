/*
 * DIO_Interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: youse
 */

#ifndef MCAL_DIO_DRIVE_DIO_INTERFACE_H_
#define MCAL_DIO_DRIVE_DIO_INTERFACE_H_


/**************************************************/
/**********************Public MAcros************/
/**************************************************/


/* Section : Macro Declarations */
/*Direction States*/
#define DIO_PORT_OUTPUT                 0xff
#define DIO_PORT_INPUT                    0x00
#define DIO_PORT_INPUT_PULLUP       0x51
/* Section : Data Type  Declarations */

typedef enum{
	LOW = 0 ,
	HIGH = 1,
}pin_state;
typedef enum{
	INPUT = 0 ,
	OUTPUT ,
   INPUT_PULLUP,
}dir_state_pin;
typedef enum{
	DIO_PIN0 = 0 ,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}pin_num;
/*Port ID*/
typedef enum{
	DIO_PORTB=0,
	DIO_PORTC,
	DIO_PORTD,

}port_num;
/*typedef struct{
	u8 port : 3 ;
	u8 pin : 3 ;
	u8 direction : 3 ;
	u8 state : 1 ;
}pin_config;*/


/**************************************************/
/**********************Public Functions************/
/**************************************************/
void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

void Pin_vidInitializeDIO( port_num _port_num , pin_num _pin_num , dir_state_pin _dir_state_pin , pin_state _pin_state ) ;
void Pin_vidSetValDIO( port_num _port_num , pin_num _pin_num  , pin_state _pin_state ) ;
void Pin_vidSetDirDIO( port_num _port_num , pin_num _pin_num  , dir_state_pin _dir_state_pin  ) ;
u8 Pin_u8GetValDIO(port_num _port_num , pin_num _pin_num);
void Pin_vidTogelDIO(port_num _port_num , pin_num _pin_num);

void Port_vidSetValDIO(port_num _port_num , u8 PortVal) ;
void Port_vidSetDirDIO(port_num _port_num , u8 PortDir);
void Port_vidTogelDIO(port_num _port_num );

#endif /* MCAL_DIO_DRIVE_DIO_INTERFACE_H_ */
