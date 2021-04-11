/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"


void task_LED_2(void *pvParameters) {
	const TickType_t xDelay= Ms(1000);
	int led_cpt=0;

	for (;;)
	{
		//PRINTF("LED blink %d\r\n", led_cpt);

		LED_RED_TOGGLE();
		LED_GREEN_TOGGLE();
		LED_BLUE_TOGGLE();

		//PRINTF("A");
		vTaskDelay(xDelay);
		led_cpt++;

		//vTaskSuspend(NULL);
	}
}
