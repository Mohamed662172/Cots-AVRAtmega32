/********************************************************/
/*************** Name     :ELabbas salah ****************/
/*************** Date     :  24/10/2020  ****************/
/*************** SWC      :    RTO       ****************/
/*************** Version  :    V1.0      ****************/
/********************************************************/



/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* mcal layer */
#include"TMR_interface.h"
#include"GIE_interface.h"


/* serv layer */

#include"RTO_interface.h"
#include"RTO_private.h"
#include"RTO_config.h"


static TCB RTO_ASTRTASKS[RTO_UINT8_MAX_NUMBER_OF_TASKS];

CheckStatus RTO_CheckStatusCreateTask(_uint8 Copy__Uint8Priority, _uint16 Copy__Uint16Priodicity,_uint16 Copy__Uint16FristDelay,void (*PTF)(Void))
{
                CheckStatus Local_ErrorState = CHECK_FAIL;
        if( (PTF != NULL) && Copy__Uint8Priority < RTO_UINT8_MAX_NUMBER_OF_TASKS)
        {
                RTO_ASTRTASKS[Copy__Uint8Priority].Priodicity = Copy__Uint16Priodicity;
                RTO_ASTRTASKS[Copy__Uint8Priority].FristDelay = Copy__Uint16FristDelay;
                RTO_ASTRTASKS[Copy__Uint8Priority].PTF = PTF;

                Local_ErrorState=CHECK_SUCCESS;
        }
        return Local_ErrorState;
}



static Void RTO_VoidSchedular(Void)
{
        _uint8  Local_Uint8Counter=0x00;
        for(Local_Uint8Counter=0;Local_Uint8Counter<RTO_UINT8_MAX_NUMBER_OF_TASKS;++Local_Uint8Counter)
        {
                if( RTO_ASTRTASKS[Local_Uint8Counter].FristDelay == 0 )
                {
                        // call functiion
                        RTO_ASTRTASKS[Local_Uint8Counter].PTF();
                        /*update frist delay with the periodicity*/
                        RTO_ASTRTASKS[Local_Uint8Counter].FristDelay=RTO_ASTRTASKS[Local_Uint8Counter].Priodicity-1;
                }
                else
                {
                        RTO_ASTRTASKS[Local_Uint8Counter].FristDelay--;
                }
        }

}

Void RTO_VoidInit(Void)
{
	/*enable global interrupt */
    GIE_VoidEnable();

    /* TMR Set call back for over flow */
  TMR_CheckStatusTimer0OVFSetCallBack(&RTO_VoidSchedular);

}

Void RTO_VoidStartTmr(_uint16 Copy_Uint16TmrInMsec)
{

    /* Init Enable */
    TMR_CheckSatusInit(Copy_Uint16TmrInMsec);
}
