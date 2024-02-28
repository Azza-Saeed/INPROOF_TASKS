/*
 * DIO_Prog.c
 *
 *  Created on: Nov 26, 2023
 *      Author: youse
 */

/********LIB*********/
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/BIT_MATH.h"
#include "C:\Users\Dell\Desktop\INPROOF_TASKS\TX&RX_Final_Test\IR_Reciever\IR_Reciever\SERVICE\LIB/STD_TYPES.h"
/********************/
#include "DIO_Interface.h"
#include "DIO_Priv.h"
#include "DIO_Config.h"



/*************************PINS Functions ********************************/
void Pin_vidInitializeDIO( port_num _port_num , pin_num _pin_num , dir_state_pin _dir_state_pin , pin_state _pin_state )
{

	if(_port_num <= DIO_PORTD &&_pin_num <= DIO_PIN7)
	{
		if(_dir_state_pin == INPUT_PULLUP)
		{
			Pin_vidSetDirDIO(_port_num,_pin_num,_dir_state_pin);
		} else if (_dir_state_pin == OUTPUT)
		{
			Pin_vidSetDirDIO(_port_num,_pin_num,_dir_state_pin);
			Pin_vidSetValDIO(_port_num,_pin_num,_pin_state);
		}
		else if (_dir_state_pin == INPUT) {
			Pin_vidSetDirDIO(_port_num, _pin_num, _dir_state_pin);
		}
	}
}

void Pin_vidSetValDIO( port_num _port_num , u8 _pin_num  , pin_state _pin_state )
{
	if(_port_num <= DIO_PORTD && _pin_num <= DIO_PIN7)
	{
		if(_pin_state == LOW)
		{
			switch(_port_num)
			 {

				 case DIO_PORTB : CLR_BIT(PORTB_REG,_pin_num); break;
				 case DIO_PORTC : CLR_BIT(PORTC_REG,_pin_num); break;
				 case DIO_PORTD : CLR_BIT(PORTD_REG,_pin_num); break;

				 	 	 	 }
		}
		else if (_pin_state == HIGH)
		{
			switch(_port_num)
			{

				case DIO_PORTB : SET_BIT(PORTB_REG,_pin_num); break;
				case DIO_PORTC : SET_BIT(PORTC_REG,_pin_num); break;
				case DIO_PORTD : SET_BIT(PORTD_REG,_pin_num); break;
				 	 	 	 }
		}

	}



}
void Pin_vidSetDirDIO( port_num _port_num , pin_num _pin_num  , dir_state_pin _dir_state_pin  )
{


	switch(_dir_state_pin)
	{
	case INPUT: switch(_port_num)
				{

					case DIO_PORTB :CLR_BIT(DDRB_REG,_pin_num);break ;
					case DIO_PORTC :CLR_BIT(DDRC_REG,_pin_num);break ;
					case DIO_PORTD :CLR_BIT(DDRD_REG,_pin_num);break ;
				}break;
	case OUTPUT: switch(_port_num)
				{

					case DIO_PORTB :SET_BIT(DDRB_REG,_pin_num);break ;
					case DIO_PORTC :SET_BIT(DDRC_REG,_pin_num);break ;
					case DIO_PORTD :SET_BIT(DDRD_REG,_pin_num);break ;
				}break;
	case INPUT_PULLUP: switch(_port_num)
				{

					case DIO_PORTB :CLR_BIT(DDRB_REG,_pin_num);
								SET_BIT(PORTB_REG,_pin_num);
								break ;
					case DIO_PORTC :CLR_BIT(DDRC_REG,_pin_num);
								SET_BIT(PORTC_REG,_pin_num);
								break ;
					case DIO_PORTD :CLR_BIT(DDRD_REG,_pin_num);
								SET_BIT(PORTD_REG,_pin_num);
								break ;
				}break;
	}


}
u8 Pin_u8GetValDIO(port_num _port_num , pin_num _pin_num)
{
	u8 Result = 0 ;

	if(_port_num <= DIO_PORTD && _pin_num <= DIO_PIN7)
	{
		switch(_port_num)
		{

		case DIO_PORTB : Result = GET_BIT(PINB_REG,_pin_num);break ;
		case DIO_PORTC : Result = GET_BIT(PINC_REG,_pin_num);break ;
		case DIO_PORTD : Result = GET_BIT(PIND_REG,_pin_num);break ;
	    }
	}
	else
	{

	}
	return Result ;



}

void Pin_vidTogelDIO(port_num _port_num , pin_num _pin_num)
{
	if(_port_num <= DIO_PORTD&& _pin_num <= DIO_PIN7)
	{
        switch(_port_num)
	 	  {

	 	 	 	case DIO_PORTB : TOG_BIT(PORTB_REG,_pin_num);break;
	 	 	 	case DIO_PORTC : TOG_BIT(PORTC_REG,_pin_num); break;
	 	 	 	case DIO_PORTD : TOG_BIT(PORTD_REG,_pin_num); break;

	 	  }

	}



}



/*************************PORTS Functions ********************************/
void Port_vidSetValDIO(port_num _port_num , u8 PortVal)
{
	if(_port_num <= DIO_PORTD)
		{
		switch(_port_num)
		{

		case DIO_PORTB : PORTB_REG = PortVal ;break ;
		case DIO_PORTC : PORTC_REG = PortVal ;break ;
		case DIO_PORTD : PORTD_REG = PortVal ;break ;
		}
		}
	else
	{

	}

}
void Port_vidSetDirDIO(port_num _port_num , u8 PortDir)
{

	if(_port_num <= DIO_PORTD)
	{
		if(PortDir != DIO_PORT_INPUT_PULLUP)
		{
			switch(_port_num)
			{

			case DIO_PORTB :DDRB_REG = PortDir ;break ;
			case DIO_PORTC :DDRC_REG = PortDir ;break ;
			case DIO_PORTD :DDRD_REG = PortDir ;break ;
			}
		}
		else
		{
			switch(_port_num)
			{

			case DIO_PORTB :DDRB_REG = PortDir ;
						PORTB_REG = 0xff ;
						break ;
			case DIO_PORTC :DDRC_REG = PortDir ;
						PORTC_REG = 0xff ;
						break ;
			case DIO_PORTD :DDRD_REG = PortDir ;
						PORTD_REG = 0xff ;
						break ;
			}
		}

	}
	else
	{

	}
}
void Port_vidTogelDIO(port_num _port_num )
{
	if(_port_num <= DIO_PORTD)
		{
		switch(_port_num)
		{

		case DIO_PORTB : PORTB_REG = PORTB_REG ^ 0xff ;break ;
		case DIO_PORTC : PORTC_REG = PORTC_REG ^ 0xff ;break ;
		case DIO_PORTD : PORTD_REG = PORTD_REG ^ 0xff ;break ;
		}
		}
	else
	{

	}
}
