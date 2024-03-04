/*
 * States.c
 *
 * Created: 04/03/2024 10:30:33 
 *  Author: Azza Saeed
 */ 
#include "bit_math.h"
#include "Std_Types.h"

#include "ASM.h"

/************************************* extern or include the spi variable ***********************************************/
volatile u8 SPI_Obj;
u8 RFID1_Obj;
u8 RFID2_Obj;

Error_States_t Normal_State(void)
{
	// calling spi task to get the value of IR
	// calling RFID1 TAsk to get the value of RFID1
	// calling Uart task to get the value of RFID2
	
	/******************************* SART CHEKING ON THE PRIEVIOUS INPUTS ************************/
	// if ( RFID1 == 1 ) then we will open gate and send uart message to the another gate to open the gate and turn on the RJB ( the uart value will be u8 varaiable )
	// if ( RFID2 == 1 ) then we will open gate and turn on the RJB ( not send uart message )
	// if ( RFID1 == 1  && RFID2 ==1 ) then we will go to the alarm state and turn on the alarm and turn the RJB and update the state variable 
	// checking on the SPI Read
	// if ( SPI_Value != 255 ) then we will go to the Obstcal detected state
	
}

Error_States_t Obstcale_Detected_State(void)
{
	// checking on the IR value only 
	// the action or output of this state can be RJB or Alarm or Both
	// if the output was the alarm then we will go to the alarm state else we will update the RJB color
	// update the state to be Normal state and then return to Normal state
}

Error_States_t Alarm_State(void)
{
	// calling the Alarm task to turn the alarm 
	// loop until the reason of this state stopped
	// update the state to be Normal state and then return to Normal state
}