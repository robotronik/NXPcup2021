#include "CCTR.h"
#include "global.h"
#define CST_HYSTERESIS 20


int FLAG_CCD = 0;
int frame_filtered[128];
int delay_ccd_short = 4, delay_ccd_long, delay_tot = 50;
int ind_buffer = 1;
int mean = 0;
int track_middle = 64;

/* test CCD */
void task_CCD(void *pvParameters) {
	delay_ccd_long = delay_tot - delay_ccd_short;
	TickType_t xDelay_short = delay_ccd_short/portTICK_PERIOD_MS;
	TickType_t xDelay_long = delay_ccd_long/portTICK_PERIOD_MS;
	//PRINTF("CCD\n\r");

	while(init_done == 0) {
		vTaskDelay(xDelay_long);
	}
	float kDelay = 0.0001;
	float delay = 6.0;
	float moyenneCible = 128.0*128.0;
	int nbPointCible = 30;
	float kNbPoint = 0.2; // Mustn't exceed 0.2
	for (;;)
	{
		int tmp = (ind_buffer + 1) % 2;
		vTaskDelay(xDelay_long);
		CCD_ImageCapture(1, tmp);


		vTaskDelay(xDelay_short);
		CCD_ImageCapture(1, tmp);
		ind_buffer = tmp;
		int moyenne = 0;
		int nbPointSaturation = 0;
		for (int i = 0 ; i<128 ; i++) {
			moyenne += CCD_ImageData[ind_buffer][i];
			if (CCD_ImageData[ind_buffer][i] > 230) {
				nbPointSaturation++;
			}
		}

		unsigned int val_unsigned = nbPointSaturation - nbPointCible;
		float sign = (nbPointSaturation - nbPointCible)/(float)val_unsigned;

		//delay = delay - kDelay*(moyenne - moyenneCible);
		if (nbPointSaturation - nbPointCible > 80) {
			delay = delay - kNbPoint*(float)(nbPointSaturation - nbPointCible);
		}
		else if (nbPointSaturation - nbPointCible < -20) {
			delay = delay - kNbPoint*(float)(nbPointSaturation - nbPointCible);
		}
		else if (nbPointSaturation > 2*(nbPointCible + CST_HYSTERESIS) || nbPointSaturation < 2*(nbPointCible - CST_HYSTERESIS)) {
			delay = delay - sign*1;
		}
		else if (nbPointSaturation > (nbPointCible + CST_HYSTERESIS) || nbPointSaturation < (nbPointCible - CST_HYSTERESIS)) { //Hysteresis
			delay = delay - sign*0.2;
		}

//		delay = delay - kNbPoint*(float)(nbPointSaturation - nbPointCible);
		if (delay < 0) {
			delay = 0;
		}
		xDelay_short = delay;


//		PRINTF("NbPointSaturation : %d\n\r",nbPointSaturation);
//		PRINTF("Hysteresis : %d et %d\n\r",nbPointCible + CST_HYSTERESIS, nbPointCible - CST_HYSTERESIS );
////		PRINTF("MOYENNE : %d\n\r",moyenne);
//		PRINTF("DELAY : %d\n\r",((int)delay));
		//vTaskSuspend(NULL);
	}
}



void task_CCD_get_middle(void * pvParameters) {
	const TickType_t xDelay=50/portTICK_PERIOD_MS;
	int frame[128];

	while(init_done == 0) {
		vTaskDelay(xDelay);
	}

	for (;;) {

		memcpy(frame, CCD_ImageData[ind_buffer], sizeof(int) * 128);

		/* Filtrage */
		for (int k=2; k<126; k++) {
			frame_filtered[k] = (frame[k+1] - frame[k-1])>>1; // derive avec lissage
		}
		frame_filtered[1] = 0;
		frame_filtered[126] = 0;
		frame_filtered[0] = 0;
		frame_filtered[127] = 0;

//		PRINTF("derive ");
//		for(int i=0;i<128;i++)
//			PRINTF("%d ", frame_filtered[i]);
//		PRINTF("\r\n");
//
//		PRINTF("camera ");
//		for(int i=0;i<128;i++)
//			PRINTF("%d ", CCD_ImageData[ind_buffer][i]);
//		PRINTF("\r\n");
//
//		PRINTF("camera ");
//		for(int i=0;i<128;i++)
//			PRINTF("%d ", CCD_2_ImageData[ind_buffer][i]);
//		PRINTF("\r\n");

		int min = 255, max = 0, pos_min, pos_max;
		for (int i=0; i < 64; i++) {
			if (max < frame_filtered[i]) {
				max = frame_filtered[i];
				pos_max = i;
			}
		}


		for (int j=64; j < 128; j++) {
			if (min > frame_filtered[j]) {
				min = frame_filtered[j];
				pos_min = j;
			}
		}

		int max_abs, pos;

		if (max > -min) {
			max_abs = max;
			pos = pos_max + half_track_size;
		}
		else {
			max_abs = -min;
			pos = pos_min - half_track_size;
		}

//		PRINTF("pos %d\n\r min %d, max %d\n\r", pos, min, max);
		if (max_abs > seuil_abs) {
			track_middle = pos;
			if (pos > 64) {
				led_sel = BLUE;
			}
			else {
				led_sel = GREEN;
			}
		}
		else {
//			track_middle = 64;
			/* track_middle ne change pas */
			led_sel = RED;
		}

		vTaskDelay(xDelay);

	}

}
