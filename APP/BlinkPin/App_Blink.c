
#include <App_Blink.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

void APP_voidBlinkPin(GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin)
{
	MCAL_GPIO_enumWritePin(Copy_enumGPIOx, Copy_enumPin, High);

	for(u32 i = 0; i < 80000; i++);

	MCAL_GPIO_enumWritePin(Copy_enumGPIOx, Copy_enumPin, Low);

	for(u32 i = 0; i < 80000; i++);
}
