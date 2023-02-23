/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/05/2020  ****************/
/*************** SWC      :    DIO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/
#ifndef  DIO_INTERFACE_H
#define  DIO_INTERFACE_H



/* Macros For PORT Id */
#define DIO__UINT8_PORTA    0
#define DIO__UINT8_PORTB    1
#define DIO__UINT8_PORTC    2
#define DIO__UINT8_PORTD    3
/*
typedef enum{DIO_UINT8_PORTA,DIO_UINT8_PORTB,DIO_UINT8_PORTC,DIO_UINT8_PORTD}DIO_PORTID;
*/
/* Macros For PIN Id */

#define DIO__UINT8_PIN0     0
#define DIO__UINT8_PIN1     1
#define DIO__UINT8_PIN2     2
#define DIO__UINT8_PIN3     3
#define DIO__UINT8_PIN4     4
#define DIO__UINT8_PIN5     5
#define DIO__UINT8_PIN6     6
#define DIO__UINT8_PIN7     7

/* Macros For PIN Direction */

#define DIO__UINT8_INPUT     0
#define DIO__UINT8_OUTPUT    1

/* Macros For PIN Value  */
#define  DIO__UINT8_LOW          0
#define  DIO__UINT8_HIGH         1

/* Prototypes of Dio Driver */
CheckStatus DIO__CheckStatusInit             ( Void );

CheckStatus DIO__CheckStatusSetPinDirection  ( _uint8 Copy__uint8PortId, _uint8 Copy__uin8PinId, _uint8 Copy__uint8PinDirection);

CheckStatus DIO__CheckStatusSetPinValue      ( _uint8 Copy__uint8PortId, _uint8 Copy__uint8PinId, _uint8 Copy__uint8PinValue);

CheckStatus DIO__CheckStatusGetPinValue      (_uint8 Copy__uint8PortId, _uint8 Copy__uint8PinId, _uint8 * Copy_p_uint8ReturnPinValue);

CheckStatus DIO__CheckStatusSetPortDirection (_uint8 Copy__uint8PortId, _uint8 Copy__uint8PortDirection);

CheckStatus DIO__CheckStatusSetPortValue     (_uint8 Copy__uint8PortId, _uint8 Copy__uint8PortValue); 

CheckStatus DIO__CheckStatusGetPortValue     (_uint8 Copy__uint8PortId,_uint8 * Copy_p_uint8ReturnPortValue); 














#endif