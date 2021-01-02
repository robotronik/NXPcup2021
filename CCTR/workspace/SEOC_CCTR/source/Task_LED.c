#include "global.h"
#include "CCTR.h"

int led_sel=CYAN;

void task_LED(void *pvParameters) {
const TickType_t xDelay=100/portTICK_PERIOD_MS;
	PRINTF("\r\n");

	for (;;)
	{
//		PRINTF("led %d\r\n", led_sel);
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
		if (led_sel == RED || led_sel == YELLOW || led_sel == PURPLE || led_sel == WHITE) {
			LED_RED_ON();
		}

		if (led_sel == GREEN || led_sel == YELLOW || led_sel == CYAN || led_sel == WHITE) {
			LED_GREEN_ON();
		}

		if (led_sel == BLUE  || led_sel == CYAN || led_sel == PURPLE || led_sel == WHITE) {
			LED_BLUE_ON();
		}

		vTaskDelay(xDelay);

		//vTaskSuspend(NULL);
	}
}
