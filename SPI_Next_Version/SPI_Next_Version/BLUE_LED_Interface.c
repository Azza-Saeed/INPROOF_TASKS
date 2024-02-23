/***
 *        ____  __    __  ________     __    __________       ____      __            ____
 *       / __ )/ /   / / / / ____/    / /   / ____/ __ \     /  _/___  / /____  _____/ __/___ _________   _____
 *      / __  / /   / / / / __/      / /   / __/ / / / /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \ / ___/
 *     / /_/ / /___/ /_/ / /___     / /___/ /___/ /_/ /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __// /__
 *    /_____/_____/\____/_____/____/_____/_____/_____/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)___/
 *                           /_____/                /_____/
 */

#include "BLUE_LED_Private.h"

ERROR_STATE BLUE_LED_Initializ(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Direction(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_OUTPUT);
	return state_error;
}
ERROR_STATE BLUE_LED_ON(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_HIGH);
	return state_error;
}
ERROR_STATE BLUE_LED_OFF(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_SetPin_Value(BLUE_LED_PORT,BLUE_LED_PIN,BLUE_LED_LOW);
	return state_error;
}
ERROR_STATE BLUE_LED_TGL(void){
	ERROR_STATE state_error = SUCCESS;
	DIO_TglPin_Value(BLUE_LED_PORT,BLUE_LED_PIN);
	return state_error;
}
/**/
