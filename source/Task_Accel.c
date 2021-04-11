/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"


/* Pour Verification de la mesure d'acceleration  */

void task_Accel(void *pvParameters) {
	const TickType_t xDelay=100/portTICK_PERIOD_MS;
	PRINTF("Accel Test \n\r");
	//PRINTF("\n\r");
	char s[80];
	for (;;)
	{
		int x, y, z;
		/* ATTENTION PRINTF a un pb de signe */
		Accel_get(&x, &y, &z);
	    //sprintf(s, "Accel %08i %08i %08i", x, y, z);
	    PRINTF("AX %d AY %d AZ %d\r\n", x,y,z);
		vTaskDelay(xDelay);
		//vTaskSuspend(NULL);
	}
}
