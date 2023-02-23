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
CheckStatus LCD_CheckStatusShiftRightOrLeft(_uint32 Copy__Uint32DelayValue);
Void         LCD_VoidInit(Void);
CheckStatus  LCD_CheckStatusSendCmnd(_uint8 Copy__Uint8Cmnd);
CheckStatus  LCD_CheckStatusSendChar(_uint8 Copy__Uint8Char);
CheckStatus  LCD_CheckStatusWriteString(_uint8 * Copy_p__Uint8String);
CheckStatus  LCD_CheckStatusGoToXY(_uint8 Copy__Uint8LineNumber,_uint8 Copy__Uint8LocationNumber);
Void         LCD_VoidClearDisplay(Void);
CheckStatus  LCD_CheckStatusSendNumber(_uint32 Copy__Uint32Number);
CheckStatus LCD_CheckStatusSpecialChar(_uint8 Copy__Uint8CGRamLocation,_uint8 Copy__Uint8LCDLine ,_uint8 Copy__Uint8DDRamLocation);
Void LCD_VoidShiftRight(_uint8 Copy__Uint8PositionValue,_uint32 Copy__Uint32DelayValue);
Void LCD_VoidShiftLeft(_uint8 Copy__Uint8PositionValue,_uint32 Copy__Uint32DelayValue);
CheckStatus LCD_CheckStatusDisplaySpecialChar(_uint8 Copy__Uint8Char);
Void LCD_VoidInit4bit(Void);

#endif
