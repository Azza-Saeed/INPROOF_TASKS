/***
 *        ____  ________       ____      __            ____                  __
 *       / __ \/  _/ __ \     /  _/___  / /____  _____/ __/___ _________    / /_
 *      / / / // // / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /_/ // // /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/___/\____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                   /_____/
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/************************************************************************/
/*                         Data Definitions:                            */
/************************************************************************/

typedef enum {
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}DIO_Port;

typedef enum {
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}DIO_Pin;

typedef enum{
	DIO_INPUT  = 0,
	DIO_OUTPUT = 1
}DIO_State;

typedef enum {
	DIO_LOW	  = 0,
	DIO_HIGH  = 1
}DIO_Status;

/************************************************************************/
/*                      Functions Prototypes                            */
/************************************************************************/

ERROR_STATE DIO_SetPin_Direction(DIO_Port port, DIO_Pin pin, DIO_State state);
ERROR_STATE DIO_SetPin_Value(DIO_Port port, DIO_Pin pin, DIO_Status status);
ERROR_STATE DIO_TglPin_Value(DIO_Port port, DIO_Pin pin);
ERROR_STATE DIO_GetPin_Value(DIO_Port port, DIO_Pin pin,UINT8_t* pin_value);
ERROR_STATE DIO_SetPin_PULLUP(DIO_Port port, DIO_Pin pin);


#endif /* DIO_INTERFACE_H_ */




