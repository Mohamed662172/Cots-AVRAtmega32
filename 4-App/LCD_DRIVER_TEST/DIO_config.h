/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/8/2020	****************************************************/
/*********	SWC		:	DIO			****************************************************/
/*********	Version	:	V1.0		****************************************************/
/***************************************************************************************/

#ifndef  DIO_CONFIG
#define  DIO_CONFIG


/***

OPTIONS :  

********** FOR DIRECTIONS ****************************
1-	INPUT   (DEFAULT)
2-	OUTPUT
******************************************************

********* FOR PIN VALUES (DIRECTION : OUTPUT) ********
3-	OUTPUT_LOW	
4-	OUTPUT_HIGH
******************************************************

********* FOR PIN VALUE (DIRECTION : INPUT) **********
5-	FLOAT_INPUT (DEFAULT)
6-	PULLUP_INPUT
******************************************************

***/

/******** PORT A PINS DIRECTIONS ********/

#define DIO_PA0_DIRECTION_INIT		OUTPUT
#define DIO_PA1_DIRECTION_INIT		OUTPUT
#define DIO_PA2_DIRECTION_INIT		OUTPUT
#define DIO_PA3_DIRECTION_INIT		OUTPUT
#define DIO_PA4_DIRECTION_INIT		OUTPUT
#define DIO_PA5_DIRECTION_INIT		OUTPUT
#define DIO_PA6_DIRECTION_INIT		OUTPUT
#define DIO_PA7_DIRECTION_INIT		OUTPUT

/****************************************/

/******** PORT B PINS DIRECTIONS ********/

#define DIO_PB0_DIRECTION_INIT		OUTPUT
#define DIO_PB1_DIRECTION_INIT		OUTPUT
#define DIO_PB2_DIRECTION_INIT		OUTPUT
#define DIO_PB3_DIRECTION_INIT		INPUT
#define DIO_PB4_DIRECTION_INIT		INPUT
#define DIO_PB5_DIRECTION_INIT		INPUT
#define DIO_PB6_DIRECTION_INIT		INPUT
#define DIO_PB7_DIRECTION_INIT		INPUT

/****************************************/

/******** PORT C PINS DIRECTIONS ********/


#define DIO_PC0_DIRECTION_INIT		INPUT
#define DIO_PC1_DIRECTION_INIT		INPUT
#define DIO_PC2_DIRECTION_INIT		INPUT
#define DIO_PC3_DIRECTION_INIT		INPUT
#define DIO_PC4_DIRECTION_INIT		INPUT
#define DIO_PC5_DIRECTION_INIT		INPUT
#define DIO_PC6_DIRECTION_INIT		INPUT
#define DIO_PC7_DIRECTION_INIT		INPUT

/****************************************/

/******** PORT D PINS DIRECTIONS ********/


#define DIO_PD0_DIRECTION_INIT		OUTPUT
#define DIO_PD1_DIRECTION_INIT      OUTPUT
#define DIO_PD2_DIRECTION_INIT		OUTPUT
#define DIO_PD3_DIRECTION_INIT		OUTPUT
#define DIO_PD4_DIRECTION_INIT		OUTPUT
#define DIO_PD5_DIRECTION_INIT		OUTPUT
#define DIO_PD6_DIRECTION_INIT		OUTPUT
#define DIO_PD7_DIRECTION_INIT		OUTPUT

/****************************************/




/******** PORT A PINS INITIAL VALUES *********/

#define DIO_PA0_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA1_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA2_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA3_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA4_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA5_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA6_LOGIC_INIT		OUTPUT_LOW
#define DIO_PA7_LOGIC_INIT		OUTPUT_LOW

/*********************************************/

/******** PORT B PINS INITIAL VALUES *********/

#define DIO_PB0_LOGIC_INIT		OUTPUT_LOW
#define DIO_PB1_LOGIC_INIT		OUTPUT_LOW
#define DIO_PB2_LOGIC_INIT		OUTPUT_LOW
#define DIO_PB3_LOGIC_INIT		FLOAT_INPUT
#define DIO_PB4_LOGIC_INIT		FLOAT_INPUT
#define DIO_PB5_LOGIC_INIT		FLOAT_INPUT
#define DIO_PB6_LOGIC_INIT		FLOAT_INPUT
#define DIO_PB7_LOGIC_INIT		FLOAT_INPUT

/*********************************************/

/******** PORT C PINS INITIAL VALUES *********/


#define DIO_PC0_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC1_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC2_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC3_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC4_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC5_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC6_LOGIC_INIT		FLOAT_INPUT
#define DIO_PC7_LOGIC_INIT		FLOAT_INPUT

/*********************************************/

/******** PORT D PINS INITIAL VALUES *********/


#define DIO_PD0_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD1_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD2_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD3_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD4_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD5_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD6_LOGIC_INIT		OUTPUT_LOW
#define DIO_PD7_LOGIC_INIT		OUTPUT_LOW

/*********************************************/



#endif	 
