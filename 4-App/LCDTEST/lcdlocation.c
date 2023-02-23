/*
 * lcdlocation.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
/* LIB layer */
#include"Std_Types.h"
#include"Bit_Math.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL */
#include"DIO_interface.h"

/* HAL */
#include"LCD_interface.h"


int main (){

     /* DIO INIT */
     DIO__CheckStatusInit();
     /* LCD INIT */
     LCD_CheckStatusInit();
     /* Write NAME */

     LCD_CheckStatusWriteString("ELABBAS ");




while(1);
    return 0 ;

}


