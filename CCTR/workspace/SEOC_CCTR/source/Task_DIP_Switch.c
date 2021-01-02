#include "CCTR.h"
/*
 * Task_DIP_Switch.c
 *
 *  Created on: Jul 1, 2019
 *      Author: segauxv
 */

extern int BTok;

void task_DIP_Switch(void *pvParameters) {
	 const TickType_t xDelay=1000/portTICK_PERIOD_MS;
	 int dip[8] = {0,0,0,0,0,0,0,0};
	 //extern QueueHandle_t xQueueData;
	 for (;;){
		 dip[0] = GPIO_ReadPinInput(BOARD_INITPINS_SW_1_GPIO, BOARD_INITPINS_SW_1_PIN);
		 dip[1] = GPIO_ReadPinInput(BOARD_INITPINS_SW_2_GPIO, BOARD_INITPINS_SW_2_PIN);
		 dip[2] = GPIO_ReadPinInput(BOARD_INITPINS_SW_3_GPIO, BOARD_INITPINS_SW_3_PIN);
		 dip[3] = GPIO_ReadPinInput(BOARD_INITPINS_SW_4_GPIO, BOARD_INITPINS_SW_4_PIN);
		 dip[4] = GPIO_ReadPinInput(BOARD_INITPINS_SW_5_GPIO, BOARD_INITPINS_SW_5_PIN);
		 dip[5] = GPIO_ReadPinInput(BOARD_INITPINS_SW_6_GPIO, BOARD_INITPINS_SW_6_PIN);
		 dip[6] = GPIO_ReadPinInput(BOARD_INITPINS_SW_7_GPIO, BOARD_INITPINS_SW_7_PIN);
		 dip[7] = GPIO_ReadPinInput(BOARD_INITPINS_SW_8_GPIO, BOARD_INITPINS_SW_8_PIN);
		 if (BTok == 1){
			 PRINTF("DIPSW : %d %d %d %d %d %d %d %d\n\r",dip[0],dip[1],dip[2],dip[3],dip[4],dip[5],dip[6],dip[7]);
		 }

		 //xQueueSend(xQueueData, dip, 0);
		 vTaskDelay(xDelay);
		 //vTaskSuspend(NULL);
	 }
}
