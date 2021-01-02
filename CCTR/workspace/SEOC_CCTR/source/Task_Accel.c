#include "CCTR.h"


/* Pour Verification de la mesure d'acceleration  */

void task_Accel(void *pvParameters) {
	const TickType_t xDelay=100/portTICK_PERIOD_MS;
	PRINTF("Accel Test \n\r");
	PRINTF("\n\r");
	char s[80];
	for (;;)
	{
		int x, y, z;
		/* ATTENTION PRINTF a un pb de signe */
		Accel_get(&x, &y, &z);
		//PRINTF("Accel A %08i %08i %08i\r\n", x, y, z);

		sprintf(s, "X %08i", x);
		PRINTF("%s\r\n", s);
		sprintf(s, "Y %08i", y);
		PRINTF("%s\r\n", s);
		sprintf(s, "Z %08i", z);
		PRINTF("%s\r\n", s);


		vTaskDelay(xDelay);

		//vTaskSuspend(NULL);
	}
}
