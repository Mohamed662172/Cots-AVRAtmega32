/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */


/*

 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

/* LIB LAYER */
#include "Std_Types.h"
#include "Bit_Math.h"

/* MCAL Layer */
#include"DIO_interface.h"

/*HAL Layer*/
#include "LCD_interface.h"
/*SERV layer */
#include"FreeRTOS.h"
#include"task.h"
#include"semphr.h"

Void  App_VoidTask1(Void * Copy_Pv);
Void  App_VoidTask2(Void * Copy_Pv);

/* create global semphaor*/

xSemaphoreHandle App_LCDSemph;

int main (void)
{

	DIO_VoidInit();
	LCD_VoidInit4bit();
    /* create semaphor */
    vSemaphoreCreateBinary(App_LCDSemph);

   xTaskCreate(&App_VoidTask1,NULL,200,NULL,1,NULL);
   xTaskCreate(&App_VoidTask2,NULL,200,NULL,1,NULL);


   vTaskStartScheduler();
return 0;
}

Void  App_VoidTask1(Void * Copy_Pv)
{

     while(TRUE)
     {
    	if(xSemaphoreTake(App_LCDSemph,portMAX_DELAY)== pdTRUE)
    	{

    		LCD_CheckStatusWriteString("I AM TASK1");

    		xSemaphoreGive(App_LCDSemph);

             vTaskDelay(1000);
      }
     }
}

Void  App_VoidTask2(Void * Copy_Pv)
{
    while(TRUE)
{

    	if(xSemaphoreTake(App_LCDSemph,portMAX_DELAY)== pdTRUE){

    		LCD_CheckStatusWriteString("I AM TASK2");

             xSemaphoreGive(App_LCDSemph);
    		vTaskDelay(1000);
      }
 }
}
