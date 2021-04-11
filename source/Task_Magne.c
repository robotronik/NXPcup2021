/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"


/* Pour Verification de la mesure de champ magnétique  */
void task_Magne(void *pvParameters) {
	const TickType_t xDelay=100/portTICK_PERIOD_MS;
	PRINTF("Magne Test \n\r");
	PRINTF("\n\r");
	char s[80];
	for (;;)
	{
		int x, y, z;
		/* ATTENTION PRINTF a un pb de signe */
		Magne_get(&x, &y, &z);
		//PRINTF("Magne A %08i %08i %08i\r\n", x, y, z);

			sprintf(s, "Magne %08i %08i %08i", x, y, z);
			PRINTF("%s\r\n", s);


		//FPRINTF(UART1, "%s\r\n", s); // UART0
		vTaskDelay(xDelay);

		//vTaskSuspend(NULL);
	}
}
