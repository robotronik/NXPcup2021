/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"


static uint16_t buffer[128];

/* test CCD Camera */
void task_Camera(void *pvParameters) {
	const TickType_t xDelay= Ms(15);

	PRINTF("Task Camera GO\r\n");
	PRINTF("\n\r");
	for (;;)
	{
		Camera_ImageCapture(1, buffer);
		for(int ii=0; ii<128; ii++) buffer[ii]= 0.5*buffer[ii];
		vTaskDelay(xDelay);
	}
}


void task_Camera_Display(void *pvParameters) {
	const TickType_t xDelay= Ms(200);
	PRINTF("Task Camera Display GO\r\n");
	PRINTF("\n\r");
	for (;;)
	{
		PRINTF("camera ");
		for(int i=0;i<128;i++)
			PRINTF("%d ", buffer[i]);
		PRINTF("\r\n");
		vTaskDelay(xDelay);
	}
}
