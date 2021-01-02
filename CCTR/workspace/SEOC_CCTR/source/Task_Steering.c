#include "CCTR.h"
#include "global.h"

int steering_cpt=0;

 void task_test_Steering(void *pvParameters) {
 const TickType_t xDelay=20/portTICK_PERIOD_MS;
 steering_cpt=0;
 int steering_pos = 750;

     for (;;)
     {
         //PRINTF("Steering %d\r\n", steering_cpt);
         //Steering_UpdatePwm(750);
    	 // ATTENTION : position centrale = pulse 1.5 ms
    	 // correspond à rapport 7.5 => 750/10000
    	 // Le rapport cyclique est exprimé en 10000 ème
    	 // la précision est en réalité donnée par le diviseur de fréquence du TPM
         // Pour plus de précision, réduire le diviseur de frequence pour augmenter mod
    	 // vérifier que MOD ne dépasse par 16 bits
    	 // Avec division par 128, mod vaut 7499


		 Steering_UpdatePwm(750);
		 vTaskDelay(xDelay);

		 /* Tourne dans le sens trigo */

		 while(steering_pos < 815) {
			 Steering_UpdatePwm(steering_pos);
			 steering_pos++;
			  vTaskDelay(xDelay);
			  led_sel = BLUE;
		 }

		 while(steering_pos > 650) {
			 Steering_UpdatePwm(steering_pos);
			 steering_pos--;
			 vTaskDelay(xDelay);
			 led_sel= RED;
		 }

		 while(steering_pos < 732) {
			 Steering_UpdatePwm(steering_pos);
			 steering_pos++;
			 vTaskDelay(xDelay);
			 led_sel = GREEN;
		 }

         //vTaskSuspend(NULL);
     }
 }


 void task_Steering(void *pvParameters) {
	const TickType_t xDelay=50/portTICK_PERIOD_MS;
	float commande;
	float tab_somme_erreur[32];
	int8_t ind;
	float erreur, somme_erreur, erreur_precedente;

	float Kp = 1.2;
	float Ki = 0.001;
	float Kd = 0;


	while(init_done == 0) {
		vTaskDelay(xDelay);
	}

    somme_erreur = 0;
    erreur_precedente = 0;
    for (int i = 0; i < 32; i++) {
        tab_somme_erreur[i] = 0;
    }
    somme_erreur = 0;
    ind = 0;

	for (;;)
	{
		erreur = (float) (63.5f - (float) track_middle);
		erreur = erreur / 63.5f;

		somme_erreur -= tab_somme_erreur[ind];
		tab_somme_erreur[ind] = erreur;
		somme_erreur += erreur;
		ind = (ind + 1)%32;

		commande = (float) (Kp * erreur + Ki * somme_erreur + Kd * (erreur - erreur_precedente));
		commande = (commande > 1.0f)? 1.0f : commande;
		commande = (commande < -1.0f)? -1.0f : commande;

 		Steering_UpdatePwm(732 + (int)(commande * 82));
 		vTaskDelay(xDelay);


	}
}
