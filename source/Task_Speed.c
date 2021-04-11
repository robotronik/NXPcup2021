/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"

/*
 * Test des capteurs sur les roues
 */

void task_Speed(void *pvParameters) {
	const TickType_t xDelay= Ms(200);
	PRINTF("Task Speed\n\r");
	for (;;)
	{

		int delta;

		int s1n=speed_1_cnt, s2n=speed_2_cnt;
		speed_2_cnt =0;
		speed_1_cnt =0;
		PRINTF("S1 %d\r\n", s1n);
		PRINTF("S2 %d\r\n", s2n);


		vTaskDelay(xDelay);

		//vTaskSuspend(NULL);
	}
}
