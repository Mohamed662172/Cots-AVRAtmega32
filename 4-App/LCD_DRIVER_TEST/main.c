#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

int main (void)
{
	DIO_u8PortsInit();
	LCD_voidInit();
	LCD_u8SendData('B');
	LCD_u8SendData('B');
    while(1);
}
