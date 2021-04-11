/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"

int FB_G_1_VALUE, FB_G_2_VALUE, FB_D_1_VALUE, FB_D_2_VALUE, POT_1_VALUE, POT_2_VALUE, POT_3_VALUE;

void task_Analog(void *pvParameters) {
	const TickType_t xDelay= Ms(100);
	PRINTF("ANALOG READ PINS\r\n");
	PRINTF("\n\r");
	for (;;)
	{

		FB_G_1_VALUE =  get_ADC_Value(FB_G_1);

		PRINTF("FBg1: %d ", FB_G_1_VALUE) ;
		//vTaskDelay(xDelay);
		FB_G_2_VALUE = get_ADC_Value(FB_G_2);
		PRINTF("FBg2: %d ", FB_G_2_VALUE);
		//vTaskDelay(xDelay);
		FB_D_1_VALUE = get_ADC_Value(FB_D_1);
		PRINTF("FBd1: %d ", FB_D_1_VALUE);
		//vTaskDelay(xDelay);
		FB_D_2_VALUE = get_ADC_Value(FB_D_2);
		PRINTF("FBd2: %d \r\n\r", FB_D_2_VALUE);
		//vTaskDelay(xDelay);
		POT_1_VALUE =  get_ADC_Value(POT_1);
		PRINTF("P1: %d ", POT_1_VALUE);
		//vTaskDelay(xDelay);
		POT_2_VALUE = get_ADC_Value(POT_2);
		PRINTF("P2: %d ", POT_2_VALUE);
		//vTaskDelay(xDelay);
		POT_3_VALUE = get_ADC_Value(POT_3);
		PRINTF("P3: %d \r\n", POT_3_VALUE);
		vTaskDelay(xDelay);

		//PRINTF("FBg1: %d FBg2: %d FBd1: %d FBd2: %d \r\n ",FB_G_1_VALUE, FB_G_2_VALUE, FB_D_1_VALUE, FB_D_2_VALUE);
		//PRINTF("\r");
		//PRINTF("POT1: %d POT2: %d POT3: %d \r\n",POT_1_VALUE, POT_2_VALUE, POT_3_VALUE);

		//vTaskDelay(xDelay);
		//vTaskSuspend(NULL);
	}
}
