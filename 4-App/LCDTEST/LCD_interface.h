/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  23/08/2020  ****************/
/*************** SWC      :    LCD       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_




#define   LCD__UINT8_LINE1                        0
#define   LCD__UINT8_LINE2                        1
#define   LCD__UINT8_LOCATION_NUMBER0             0
#define   LCD__UINT8_LOCATION_NUMBER1             1
#define   LCD__UINT8_LOCATION_NUMBER2             2
#define   LCD__UINT8_LOCATION_NUMBER3             3
#define   LCD__UINT8_LOCATION_NUMBER4             4
#define   LCD__UINT8_LOCATION_NUMBER5             5
#define   LCD__UINT8_LOCATION_NUMBER6             6 
#define   LCD__UINT8_LOCATION_NUMBER7             7
#define   LCD__UINT8_LOCATION_NUMBER8             8
#define   LCD__UINT8_LOCATION_NUMBER9             9     
#define   LCD__UINT8_LOCATION_NUMBER10            10
#define   LCD__UINT8_LOCATION_NUMBER11            11
#define   LCD__UINT8_LOCATION_NUMBER12            12
#define   LCD__UINT8_LOCATION_NUMBER13            13
#define   LCD__UINT8_LOCATION_NUMBER14            14
#define   LCD__UINT8_LOCATION_NUMBER15            15

/* Functions Declarations */

void  LCD_CheckStatusInit(Void);
void LCD_CheckStatusSendCmnd(_uint8 Copy__Uint8Cmnd);
void  LCD_CheckStatusSendChar(_uint8 Copy__Uint8Char);
CheckStatus  LCD_CheckStatusWriteString(_uint8 * Copy_p__Uint8String);
CheckStatus  LCD_CheckStatusGoToXY(_uint8 Copy__Uint8LineNumber,_uint8 Copy__Uint8LocationNumber);
#endif
