#include "CCTR.h"
/*
 * Task_DIP_LED.c
 *
 *  Created on: Jul 1, 2019
 *      Author: segauxv
 */
//int dip_led_cpt[6] = {0, 0, 0, 0, 0, 0};
int dip_led_cpt = 1;


void task_DIP_LED(void *pvParameters) {
	 const TickType_t xDelay=1000/portTICK_PERIOD_MS;
	 const TickType_t fast=200/portTICK_PERIOD_MS;
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_1_GPIO, 1U << BOARD_INITPINS_LED_1_PIN);
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_2_GPIO, 1U << BOARD_INITPINS_LED_2_PIN);
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_3_GPIO, 1U << BOARD_INITPINS_LED_3_PIN);
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_4_GPIO, 1U << BOARD_INITPINS_LED_4_PIN);
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_5_GPIO, 1U << BOARD_INITPINS_LED_5_PIN);
	 GPIO_ClearPinsOutput(BOARD_INITPINS_LED_6_GPIO, 1U << BOARD_INITPINS_LED_6_PIN);

	 vTaskDelay(xDelay);
	 int y_cpt=0;
	 for (;;)
	      {
		 	 	 PRINTF("DEBUG LED %d\r\n", dip_led_cpt);
		 	 	 PRINTF("y %d\r\n", y_cpt % 255);


		 	 	 y_cpt++;
	          // Utiliser les fonction GPIO_SetPinsOutput et GPIO_ClearPinsOutput pour donner les valeurs 1 ou 0
	          if (dip_led_cpt ==1){
	              GPIO_TogglePinsOutput(BOARD_INITPINS_LED_1_GPIO, 1U << BOARD_INITPINS_LED_1_PIN);
//	              Led_1_State =  !Led_1_State;
	          }
	          if (dip_led_cpt ==2){
	          	  GPIO_TogglePinsOutput(BOARD_INITPINS_LED_2_GPIO, 1U << BOARD_INITPINS_LED_2_PIN);
//	          	  Led_2_State =  !Led_2_State;
	          }
	          if (dip_led_cpt ==3){
	        	  GPIO_TogglePinsOutput(BOARD_INITPINS_LED_3_GPIO, 1U << BOARD_INITPINS_LED_3_PIN);
	          }
	          if (dip_led_cpt == 4){
	        	  GPIO_TogglePinsOutput(BOARD_INITPINS_LED_4_GPIO, 1U << BOARD_INITPINS_LED_4_PIN);
	          }
	          if (dip_led_cpt ==5){
	        	  GPIO_TogglePinsOutput(BOARD_INITPINS_LED_5_GPIO, 1U << BOARD_INITPINS_LED_5_PIN);
	          }
	          if (dip_led_cpt ==6){
	        	  GPIO_TogglePinsOutput(BOARD_INITPINS_LED_6_GPIO, 1U << BOARD_INITPINS_LED_6_PIN);
	          }
        	  //PRINTF("%08i %08i %08i %08i %08i %08i ",Led_1_State, Led_2_State, Led_3_State, Led_4_State, Led_5_State, Led_6_State);
	          //PRINTF("B");
	          vTaskDelay(fast);

	          dip_led_cpt++;
	          if (dip_led_cpt == 7)
	        	  	dip_led_cpt =1;

	          //vTaskSuspend(NULL);
	      }

}
