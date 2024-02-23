/***
 *       _____ ____  ____     ____
 *      / ___// __ \/  _/    / __ \_________  ____ __________ _____ ___   _____
 *      \__ \/ /_/ // /     / /_/ / ___/ __ \/ __ `/ ___/ __ `/ __ `__ \ / ___/
 *     ___/ / ____// /     / ____/ /  / /_/ / /_/ / /  / /_/ / / / / / // /__
 *    /____/_/   /___/____/_/   /_/   \____/\__, /_/   \__,_/_/ /_/ /_(_)___/
 *                  /_____/                /____/
 */


#include "SPI_Interface.h"

ISR(VECTOR(12)) {
	ptr_func();
}

ERROR_STATE SPI_Init_Master(Master_Config *My_Config) {
	ERROR_STATE error_state = SUCCESS;
	DIO_SetPin_Direction(MISO_PORT, MISO_PIN, DIO_INPUT);
	DIO_SetPin_Direction(MOSI_PORT, MOSI_PIN, DIO_OUTPUT);
	DIO_SetPin_Direction(CLOCK_PORT, CLOCK_PIN, DIO_OUTPUT);
	DIO_SetPin_Direction(SS_PORT, SS_PIN, DIO_OUTPUT);

	SPCR |= (1 << SPE)
			| (My_Config->Int_Enable << SPIE)
			| (My_Config->Data_Order << DORD) | (SPI_MASTER << MSTR)
			| (My_Config->Polarity << CPOL) | (My_Config->Phase << CPHA)
			| (My_Config->Prescaler & 0x3);

	SPSR |= (My_Config->Prescaler >> 2);
	return error_state;
}

ERROR_STATE SPI_Init_Slave(Slave_Config *My_Config) {
	ERROR_STATE error_state = SUCCESS;
	DIO_SetPin_Direction(MISO_PORT, MISO_PIN, DIO_OUTPUT);
	DIO_SetPin_Direction(MOSI_PORT, MOSI_PIN, DIO_INPUT);
	DIO_SetPin_Direction(CLOCK_PORT, CLOCK_PIN, DIO_INPUT);
	DIO_SetPin_Direction(SS_PORT, SS_PIN, DIO_INPUT);

	SPCR = 0;
	SPCR |= (SPI_ENABLE << SPE) | (My_Config->Int_Enable << SPIE)
			| (My_Config->Data_Order << DORD) | (My_Config->Polarity << CPOL)
			| (My_Config->Phase << CPHA);
	return error_state;
}

ERROR_STATE SPI_Send_Receive_Synch_Byte(UINT8_t byte, UINT8_t *received) {
	ERROR_STATE error_state = SUCCESS;
	SPDR = byte;

	while (!GET_BIT(SPSR, SPIF));
	*received = SPDR;
	return error_state;
}

ERROR_STATE SPI_Send_ASynch_Byte(UINT8_t byte) {
	ERROR_STATE error_state = SUCCESS;
	SPDR = byte;

	while (!GET_BIT(SPSR, SPIF));
	return error_state;
}

ERROR_STATE SPI_Read_Data(UINT8_t *var) {
	ERROR_STATE error_state = SUCCESS;
	*var = SPDR;
	return error_state;
}

ERROR_STATE SPI_Set_CallBack(void (*func)(void)) {
	ERROR_STATE error_state = SUCCESS;
	ptr_func = func;
	return error_state;
}

ERROR_STATE Global_Interrupt_Enable() {
	ERROR_STATE error_state = SUCCESS;
	SREG |= (1 << 7);
	return error_state;
}
void Master_Send(UINT8_t data){
	SPI_Send_ASynch_Byte(data);
}

UINT8_t Master_Receive(){
	UINT8_t received=0;
	SPI_Send_Receive_Synch_Byte(DUMMY_DATA,&received);
	return received;
}
