/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  09/10/2020  ****************/
/*************** SWC      :   UART       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/





/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL LAYER*/
#include"UART_interface.h"
#include"UART_private.h"
#include"UART_config.h"



Void UART_VoidInit(Void)
{
        _uint8 Local_uint8UCSRCValue=0x80; 
        /* Buadrate = 9600*/
        _uint16 Local_uint16UBRRVALUE = 51;
        UART_UBRRL_UINT8__REG = (_uint8)Local_uint16UBRRVALUE;
        UART_UBRRH_UINT8__REG = (_uint8)(Local_uint16UBRRVALUE>>8);

        /*Enable TX/RX*/
        SET_BIT(UART_UCSRB_UINT8__REG,3);
        SET_BIT(UART_UCSRB_UINT8__REG,4);
        /*Character size is 8 bits*/
        CLEAR_BIT(UART_UCSRB_UINT8__REG,2);
        SET_BIT(Local_uint8UCSRCValue,2);
        SET_BIT(Local_uint8UCSRCValue,1);
        /*Asynchrounce mode */
        CLEAR_BIT(Local_uint8UCSRCValue,6);
        /*Disable oparity bit */
        CLEAR_BIT(Local_uint8UCSRCValue,5);
        CLEAR_BIT(Local_uint8UCSRCValue,4);
        /*two stop bit */
        SET_BIT(Local_uint8UCSRCValue,3);
        /*Update UCSRC*/
        UART_UCSRC_UINT8__REG = Local_uint8UCSRCValue;

}

Void UART_VoidTxData(_uint8 Copy_Uint8TxData)
{
        /*check if tx buffer empty*/
        while (!GET_BIT(UART_UCSRA_UINT8__REG,5))
        {
                /* code */
        }
        UART_UDR_UINT8__REG = Copy_Uint8TxData;
        
}
CheckStatus UART_CheckStatusRxData(_uint8 *Copy_Uint8RxData)
{
        CheckStatus Local_CheckStatusErrorCheck = CHECK_SUCCESS;
        if(Copy_Uint8RxData != NULL)
        {
                /* check the recive flag */
                while (!GET_BIT(UART_UCSRA_UINT8__REG,7))
                {
                        /* code */
                }
                *Copy_Uint8RxData = UART_UDR_UINT8__REG;


        }
        else
        {
                Local_CheckStatusErrorCheck = CHECK_FAIL;
        }
  return Local_CheckStatusErrorCheck;       
}




CheckStatus UART_CheckStatusTxStringSynchWithBlocking(_uint8 * Copy_Uint8TxString)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_FAIL;
        _uint8 Local_Uint8Counter = 0 ;
    
        while (Copy_Uint8TxString[Local_Uint8Counter] != '\0')
        {
                UART_VoidTxData(Copy_Uint8TxString[Local_Uint8Counter]);
                Local_Uint8Counter++;
                Local_CheckStatusReturnValue = CHECK_SUCCESS;
        }
        return Local_CheckStatusReturnValue;

}

CheckStatus UART_CheckStatusRxStringSynchWithBlocking(_uint8 * Copy_Uint8RxString)
{
        CheckStatus Local_CheckStatusReturnValue = CHECK_FAIL;
        _uint8      Local_Uint8Counter=0;
        while (Copy_Uint8RxString[Local_Uint8Counter] != '\0')
        {
                UART_CheckStatusRxData(Copy_Uint8RxString[Local_Uint8Counter]);
                Local_Uint8Counter++;
                Local_CheckStatusReturnValue = CHECK_SUCCESS;
        }
        return Local_CheckStatusReturnValue;
        
}

Void UART_VoidTxStringAsynch(Void (*Copy_PF_Notification)(Void))
{


}

Void UART_VoidRxStringAsynch(Void (*Copy_PF_Notification)(Void))
{

}
