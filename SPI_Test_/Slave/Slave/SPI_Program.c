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

void SPI_Init_Master(Master_Config *My_Config) {
	dio_vidConfigChannel(MISO_PORT, MISO_PIN, INPUT);
	dio_vidConfigChannel(MOSI_PORT, MOSI_PIN, OUTPUT);
	dio_vidConfigChannel(CLOCK_PORT, CLOCK_PIN, OUTPUT);
	dio_vidConfigChannel(SS_PORT, SS_PIN, OUTPUT);

	SPCR |= (1 << SPE)
			| (My_Config->Int_Enable << SPIE)
			| (My_Config->Data_Order << DORD) | (SPI_MASTER << MSTR)
			| (My_Config->Polarity << CPOL) | (My_Config->Phase << CPHA)
			| (My_Config->Prescaler & 0x3);

	SPSR |= (My_Config->Prescaler >> 2);
}

void SPI_Init_Slave(Slave_Config *My_Config) {
	dio_vidConfigChannel(MISO_PORT, MISO_PIN, OUTPUT);
	dio_vidConfigChannel(MOSI_PORT, MOSI_PIN, INPUT);
	dio_vidConfigChannel(CLOCK_PORT, CLOCK_PIN, INPUT);
	dio_vidConfigChannel(SS_PORT, SS_PIN, INPUT);

	SPCR = 0;
	SPCR |= (SPI_ENABLE << SPE) | (My_Config->Int_Enable << SPIE)
			| (My_Config->Data_Order << DORD) | (My_Config->Polarity << CPOL)
			| (My_Config->Phase << CPHA);
}

void SPI_Send_Receive_Synch_Byte(u8 byte, u8 *received) {
	SPDR = byte;

	while (!CHECK_BIT(SPSR, SPIF));
	*received = SPDR;
}

void SPI_Send_ASynch_Byte(u8 byte) {
	SPDR = byte;

	//while (!CHECK_BIT(SPSR, SPIF));
}

void SPI_Read_Data(u8 *var) {
	*var = SPDR;
}

void SPI_Set_CallBack(void (*func)(void)) {
	ptr_func = func;
}

void Global_Interrupt_Enable() {
	SREG |= (1 << 7);
}
void Master_Send(u8 data){
	SPI_Send_ASynch_Byte(data);
}
void Slave_Send(u8 data){
	SPI_Send_ASynch_Byte(data);
}
u8 Master_Receive(){
	u8 received=0;
	SPI_Send_Receive_Synch_Byte(DUMMY_DATA,&received);
	return received;
}
