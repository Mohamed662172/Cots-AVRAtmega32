/* LIB layer */
#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include"DIO_interface.h"

/* HAL */
#include"LCD_interface.h"
#include"KPAD_interface.h"
/*
void Framethree(void);
void Frameone(void);
void Frametwo(void);
*/
int main (){

     /* DIO INIT */
     DIO_VoidInit();
     /* LCD INIT */
     LCD_VoidInit();
     /* Write NAME */

LCD_CheckStatusSendChar('A');
while(TRUE)
{
	/*
 	Frameone();
 _delay_ms(350);

 	Framethree();
_delay_ms(350);
    Frametwo();
_delay_ms(350);*/
}


    return 0 ;

}
/*
void Frameone(void)
{
    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
    LCD_CheckStatusWriteString("Hi,I'm Hamoksha");

    LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER9);
    LCD_CheckStatusDisplaySpecialChar(1);
    _delay_ms(500);
LCD_VoidClearDisplay();
}
void  Frametwo(void)
{
	int i,j;
for(i=0;i<4;++i){

    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER3);
    LCD_CheckStatusWriteString("I Love Dance");

LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+i);
LCD_CheckStatusDisplaySpecialChar(1);
_delay_ms(350);
LCD_CheckStatusSpecialChar(6,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+i);
LCD_CheckStatusDisplaySpecialChar(6);
_delay_ms(350);
LCD_CheckStatusSpecialChar(7,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+i);
LCD_CheckStatusDisplaySpecialChar(7);
_delay_ms(350);
LCD_CheckStatusSpecialChar(8,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+i);
LCD_CheckStatusDisplaySpecialChar(8);
_delay_ms(350);
LCD_VoidClearDisplay();
}
for(j=2;j>=0;--j){
    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER3);
    LCD_CheckStatusWriteString("I Love Dance");
	LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+j);
LCD_CheckStatusDisplaySpecialChar(1);
_delay_ms(350);
LCD_CheckStatusSpecialChar(6,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+j);
LCD_CheckStatusDisplaySpecialChar(6);
_delay_ms(350);
LCD_CheckStatusSpecialChar(7,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+j);
LCD_CheckStatusDisplaySpecialChar(7);
_delay_ms(350);
LCD_CheckStatusSpecialChar(8,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER8+j);
LCD_CheckStatusDisplaySpecialChar(8);
_delay_ms(350);
LCD_VoidClearDisplay();



}

}
void Framethree(void)
{


for(int i=0;i<15;++i){

    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
    LCD_CheckStatusWriteString("I PlAY FOOTBALL");

   LCD_CheckStatusSpecialChar(4,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER15);
    LCD_CheckStatusDisplaySpecialChar(4);

    LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0+i);
	LCD_CheckStatusDisplaySpecialChar(1);
    _delay_ms(250);
	LCD_CheckStatusSpecialChar(2,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER0+i);
	LCD_CheckStatusDisplaySpecialChar(2);
	_delay_ms(250);
	LCD_CheckStatusSpecialChar(3,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER1+i);
	LCD_CheckStatusDisplaySpecialChar(3);
	_delay_ms(250);
	LCD_CheckStatusSpecialChar(5,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER1+i);
	LCD_CheckStatusDisplaySpecialChar(5);

	if(i==14)
			{
		_delay_ms(250);
		LCD_VoidClearDisplay();
		    LCD_CheckStatusGoToXY(LCD__UINT8_LINE1,LCD__UINT8_LOCATION_NUMBER0);
			LCD_CheckStatusWriteString("     GoaaaaaL!    ");
			LCD_CheckStatusSpecialChar(6,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER10);
			LCD_CheckStatusDisplaySpecialChar(6);
			_delay_ms(250);
			   LCD_CheckStatusSpecialChar(1,LCD__UINT8_LINE2,LCD__UINT8_LOCATION_NUMBER10);
				LCD_CheckStatusDisplaySpecialChar(1);
			    _delay_ms(250);

			}

	_delay_ms(250);
	LCD_VoidClearDisplay();


}

}

*/
