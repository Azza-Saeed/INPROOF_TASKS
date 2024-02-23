#include "bit_math.h"
#include "Std_Types.h"
#include "dio.h"

/********* application test DIO ****************
 * config pin B4 as output	(Connected to green led on fares kit)
 */

#define LED_PORT	DIO_PORTB
#define LED_PIN		DIO_PIN4



int main(void)
{

	dio_vidConfigChannel(LED_PORT, LED_PIN, OUTPUT);

	while(1)
	{
			dio_vidWriteChannel(LED_PORT, LED_PIN, STD_HIGH);
			_delay_ms(1000);
			dio_vidWriteChannel(LED_PORT, LED_PIN, STD_LOW);
	
	}






	return 0;
}
