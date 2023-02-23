

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL LAYER*/
#include"SPI_interface.h"
#include"SPI_private.h"
#include"SPI_config.h"



Void SPI_VoidInit(Void)
{
        
    /* select Data Order = LSB*/
    CLEAR_BIT(SPI_UINT8_SPCR_REG,5);
    /* select Master Mode */
    SET_BIT(SPI_UINT8_SPCR_REG,4); 
    /*Select Clk Polarity  Falling/raiseing setup/sample*/
    SET_BIT(SPI_UINT8_SPCR_REG,3);
    SET_BIT(SPI_UINT8_SPCR_REG,2);
    /*select clk rate focs/64*/
    SET_BIT(SPI_UINT8_SPCR_REG,1);
    CLEAR_BIT(SPI_UINT8_SPCR_REG,0);       
    
           


}
CheckStatus SPI_CheckStatusTxRx(_uint8 Copy_Uint8DataByteTx,_uint8* Copy_Uint8DataByteRx)
{
        CheckStatus Local_ErrorState = CHECK_FAIL;
        if(Copy_Uint8DataByteRx != NULL)
        {
                /* Send data Byte*/

                SPI_UINT8_SPDR_REG = Copy_Uint8DataByteTx;
                while (!GET_BIT(SPI_UINT8_SPSR_REG,7))
                {
                        /* code */
                }
                /*Read Data*/
                *Copy_Uint8DataByteRx = SPI_UINT8_SPDR_REG;
                Local_ErrorState=CHECK_SUCCESS;
        }
        return Local_ErrorState;
}


