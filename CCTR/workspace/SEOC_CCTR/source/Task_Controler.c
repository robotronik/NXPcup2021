#include "CCTR.h"
#include "global.h"


int init_done = 0;
int half_track_size = 64;
int seuil_abs = 0;

void task_Control(void *pvParameters) {
	int max = 0, min = 255, pos_max, pos_min;
	int min_moy, max_moy;
	int frame[128], frame_filtered[128];
	PRINTF("Controler\n\r");

	/* Init */
	for (int k = 0 ; k < 5; k++) {
		CCD_ImageCapture(1, 0);
		vTaskDelay(3);
		CCD_ImageCapture(1, 0);

		memcpy(frame, CCD_ImageData[0], sizeof(int) * 128);

		/* Filtrage */
		for (int k=2; k<126; k++) {
			frame_filtered[k] = (frame[k+1] - frame[k-1])>>1; // derive basique
		}
		frame_filtered[1] = 0;
		frame_filtered[126] = 0;
		frame_filtered[0] = 0;
		frame_filtered[127] = 0;


		for (int k = 2; k<64; k++) {
			if (frame_filtered[k] > max) {
				max = frame_filtered[k];
				pos_max = k;
			}
		}
		for (int k = 64; k<128; k++) {
			if (frame_filtered[k] < min) {
				min = frame_filtered[k];
				pos_min = k;
			}
		}
		half_track_size += (pos_min - pos_max)>>1;

		min_moy += min;
		max_moy += max;

	}

	half_track_size = (int) (half_track_size/5.0);
	min_moy = (int) (min_moy / 5.0);
	max_moy = (int) (max_moy / 5.0);

	seuil_abs = (max_moy > -min_moy)? -min_moy : max_moy;
	seuil_abs = seuil_abs >> 1;

	init_done = 1;

	float consigne = 750;
	float Ki = 5;
	TickType_t xDelay = 20/portTICK_PERIOD_MS;


	/* Control */
	for (;;) {
#if 0
		consigne = (int)(850 - 200 * (track_middle - 32) / 64.0);

		if (consigne < 650) {
			consigne = 650;
		}
		else if (consigne > 850) {
			consigne = 850;
		}

		 Steering_UpdatePwm((int)consigne);

		vTaskDelay(xDelay);
#endif
		vTaskDelay(xDelay);

	}

}
