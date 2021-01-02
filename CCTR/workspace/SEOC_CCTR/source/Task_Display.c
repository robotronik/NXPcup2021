#include "CCTR.h"
#include "global.h"


void task_Display(void *pvParameters) {
	const TickType_t xDelay=20/portTICK_PERIOD_MS;


	while(init_done == 0) {
		vTaskDelay(xDelay);
	}

	PRINTF("CCD Task display GO\r\n");
	PRINTF("\n\r");
	for (;;)
	{
		PRINTF("camera ");
		for(int i=0;i<128;i++)
			PRINTF("%d ", CCD_ImageData[ind_buffer][i]);
		PRINTF("\r\n");

		PRINTF("middle %d\r\n", track_middle);

		PRINTF("ind_buffer %d \r\n", ind_buffer);


		vTaskDelay(xDelay);
		//vTaskSuspend(NULL);
	}
}
