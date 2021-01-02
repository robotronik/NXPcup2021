#include "CCTR.h"
/*
 * Task_BT_init.c
 *
 *  Created on: Jul 1, 2019
 *      Author: segauxv
 */

void task_BT_Init(void *pvParameters) {
	 const TickType_t xDelay=1000/portTICK_PERIOD_MS;
	 const TickType_t fast=100/portTICK_PERIOD_MS;
/*
	float x= 1.0;
    PRINTF("Test double %a\n\r", x);
    x=0.0;
    PRINTF("Test double %a\n\r", x);
	 x= 3740;
	PRINTF("Test double %a\n\r", x);
*/
	 PRINTF("Blue Tooth initialization starts");
     vTaskDelay(xDelay);
	 vTaskDelay(xDelay);
	 LogConsole_Printf("$$$");
	 vTaskDelay(xDelay);
	 vTaskDelay(xDelay);
	 LogConsole_Printf("SN,BLBoys\r");
	 //PRINTF("C,34C9F08A757B\r"); //CLEF BLUETOOTH
	 //PRINTF("C,9C5CF946D97E\r"); //MON PORTABLE
	 //PRINTF("SM,0\r"); //SLAVE MODE
	 //PRINTF("SM,6\r"); // PAIR MODE
	 vTaskDelay(xDelay);
	 vTaskDelay(xDelay);
	 vTaskDelay(xDelay);


	 LogConsole_Printf("---\r");
	 PRINTF("Blue Tooth module initialized");
	 LOG_BT_OK = 1;
	 vTaskDelay(xDelay);
	 // test Bluetooth, a supprimer
     int y_cpt=0;
     while (1)
     {
	 	 //LOG_PRINTF("DIP LED State :(%d)\r\n", dip_led_cpt);
	 	 LOG_PRINTF("y %d\r\n", y_cpt % 255);
	 	 LOG_PRINTF("z %d\r\n", 128 - (y_cpt % 255));
		 vTaskDelay(fast);
	 	 y_cpt++;

     }
	 vTaskSuspend(NULL);


}
