/*
 * DIO_Config.h
 *
 *  Created on: Nov 26, 2023
 *      Author: youse
 */

#ifndef MCAL_DIO_DRIVE_DIO_CONFIG_H_
#define MCAL_DIO_DRIVE_DIO_CONFIG_H_

/******************************************************************************/
/********************** configuration for DIO ************************/
/******************************************************************************/
/* Description : PORTS configuration */



/* Description : PORTA configuration (direction) 8 pins --> from pin 0 to 7 */
/* range       :  OUTPUT_MODE  --> for Make the Direction of pin output
 *                INPUT_MODE   --> for Make the Direction of pin input
 *                PULLUP_MODE   --> for Make the Direction of pin input
 *                SELECT_MODE   --> for Make the Direction of pin input  */
#define  PORTA_DIR    OUTPUT_MODE

#if PORTA_DIR == SELECT_MODE
#define PORTA_DIR_PINS      000000
#endif
/* Description : PORTA configuration (pin first state )6 pins --> from pin 0 to 5 */
/* range       :  HIGH  --> for Make the pin value HIGH
 *                LOW  --> for Make the pin value LOW */

#define  PORTA_FIRST_PINS_STATE    PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH, \
                                   PINS_HIGH
/********************************************************************/



/* Description : PORTB configuration 8 pins --> from pin 0 to 7 */
/* range       :  OUTPUT_MODE  --> for Make the Direction of pin output
 *                INPUT_MODE   --> for Make the Direction of pin input
 *                PULLUP_MODE   --> for Make the Direction of pin input
 *                SELECT_MODE   --> for Make the Direction of pin input  */

#define  PORTB_DIR    PULLUP_MODE

#if PORTB_DIR == SELECT_MODE
#define PORTB_DIR_PINS      000000
#endif
/********************************************************************/


/* Description : PORTC configuration 8 pins --> from pin 0 to 7 */
/* range       :  OUTPUT_MODE  --> for Make the Direction of pin output
 *                      INPUT_MODE   --> for Make the Direction of pin input
 *                      SELECT_MODE   --> for Make the Direction of pin input  */

#define  PORTC_DIR    INPUT_MODE

#if PORTC_DIR == SELECT_MODE
#define PORTC_DIR_PINS      000000
#endif
/********************************************************************/

/* Description : PORTD configuration 8 pins --> from pin 0 to 7 */
/* range       :  OUTPUT_MODE  --> for Make the Direction of pin output
 *                      INPUT_MODE   --> for Make the Direction of pin input
 *                      SELECT_MODE   --> for Make the Direction of pin input  */

#define  PORTD_DIR    INPUT_MODE

#if PORTD_DIR == SELECT_MODE
#define PORTD_DIR_PINS      000000
#endif
/********************************************************************/




#endif /* MCAL_DIO_DRIVE_DIO_CONFIG_H_ */
