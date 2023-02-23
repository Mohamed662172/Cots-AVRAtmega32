/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/08/2020  ****************/
/*************** SWC      :    LCD       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*
SELECT :
          1-Control Port
          2-Register Select  PIN
          3-Read / Write  PIN
          4-Enable   PIN
*/

#define  LCD__UINT8_CONTROL_PORT       DIO__UINT8_PORTD
#define  LCD__UINT8_RS_PIN             DIO__UINT8_PIN0  
#define  LCD__UINT8_RW_PIN             DIO__UINT8_PIN1  
#define  LCD__UINT8_E_PIN              DIO__UINT8_PIN2  
#define  LCD__UINT8_DATA_PORT          DIO__UINT8_PORTA
#endif
