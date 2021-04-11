#include "CCTR.h"
#include "CCTR_img_proc.h"

static  unsigned char Camera_ImageData[128];
static  unsigned char img[128];
static  uint16_t buffer[128];

/* test CCD */
void task_Camera_Double_Integration(void *pvParameters) {
	const TickType_t xDelay= Ms(30);
	const TickType_t xDelaySlow= Ms(50);
	PRINTF("Task Camera Double Integration GO\r\n");
	PRINTF("\n\r");
	for (;;)
	{
		Camera_ImageCapture(1, buffer);
		vTaskDelay(xDelay);
		Camera_ImageCapture(1, buffer);
		for(int i=0;i<128;i++)
			{
			buffer[i]>>=1; 										//Q : Divisé par 2?
				if (buffer[i]>=255) buffer[i]=255;
				Camera_ImageData[i]= buffer[i];//(buffer[i]*(0.8+(i-64)*(i-64)/8000.0));
			}
		/* nettoie les bords */
		for (int i=0;i<3; i++)
		{
		Camera_ImageData[127-i]=Camera_ImageData[124];
		Camera_ImageData[i]=Camera_ImageData[4];
		}
		vTaskDelay(xDelaySlow);
	}
}

Bord bord, bord_o;
float steering_p=0, steering=0;
int perdu=0, bv;

void task_Piste(void *pvParameters) {
	const TickType_t xDelay= Ms(100);
	PRINTF("Task Piste GO\r\n");
	float Ks= 0.9;																//A ADAPTER!
	steering_p=0; steering=0;
	bord.cas=0; bord.gauche=0; bord.droite=127;
	bord_o.cas=0; bord_o.gauche=0; bord_o.droite=127;

	float c;
	int m, cas;
	for (;;)
	{

		Ligne_Filtre_Gaussien(img, Camera_ImageData);
		cas=Ligne_Bord_Detecte(&bord, img);
		//PRINTF("CAS %d %d\r\n", cas, bord.cas);
		bv= Bord_Vitesse(&perdu, bord_o, bord);
		/*MODIFIE*/
		if (*perdu=1 && bord.cas = 4)
		{
			task_Arret_PRIORITY = 4;
			vTaskDelay(xDelay);
		}
		m= Bord_Milieu(bord)-64;
		c= -(0.99*bv + 0.01*m);
		steering= steering_p-Ks*(c);
		Steering_UpdatePwm_Relative((int)2*steering_p);

		steering_p= steering;
		bord_o.cas= bord.cas;
		bord_o.gauche= bord.gauche;
		bord_o.droite= bord.droite;
		vTaskDelay(xDelay);
		//vTaskSuspend(NULL);
	}
}

extern float omega_1, omega_2;

extern int diff[128];
#if 0
#define LG LOG_PRINTF
#else
#define LG PRINTF
#endif
void task_Piste_Display(void *pvParameters) {

	const TickType_t xDelay= Ms(1000);
	PRINTF("Task Piste Display\r\n");
	for (;;)
	{
		LG("diff ");
		for(int i=0;i<128;i++)
			LG("%d ", img[i]);
		LG("\r\n");

#if 0
		LG("diff ");
				for(int i=0;i<128;i++)
					LG("%d ", diff[i]);
				LG("\r\n");
#endif
		LG("BC %d\r\nBG %d\r\nBD %d\r\n", bord.cas, bord.gauche, bord.droite);
		LG("BV %d\r\n", bv);
		LG("S %d\r\n", ((int)(steering_p)));
		LG("MG %d\r\nMD %d\r\n", ((int)(omega_1)), ((int)(omega_2)));

		vTaskDelay(xDelay);

		//vTaskSuspend(NULL);
	}
}
