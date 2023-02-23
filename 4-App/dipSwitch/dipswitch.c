/*
 * dipswitch.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#include<avr/io.h>
#define F_CPU    8000000UL
#include<util/delay.h>



int main()
{
/*configuer PA0 as output  , PB7as input*/
DDRA = 0x01;
DDRB = 0x00;

//PORTB = 0x80;
while(1)
{
if((PINB && 0x80)== 0){

	PORTA=0x01;
}
else if ((PINB && 0x80)!= 0)
{
	PORTA=0x00;
}
else {
/*DoNothing*/
}
}



return 0 ;
}

