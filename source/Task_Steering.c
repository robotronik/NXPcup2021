/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/


#include "CCTR.h"
int steering_cpt=0;

/*
BEWARE - DANGER

Avant d'activer cette tâche, régler le servo:
- eteindre l'alim servo, 
- dévisser le bras
- désactiver la tache tast_Steering
- allumer le MCU, charger le code (Steering_Zero() est le réglage par défaut)
- puis allumer le servo
- visser le bras 
- calibrer la position zero et reporter la valeur affichée dans CCTR_Steering.h

*/


 void task_Steering(void *pvParameters) {
 const TickType_t xDelay=100/portTICK_PERIOD_MS;
 steering_cpt=0;
int iter=0;
	int POT_1_VALUE;
     for (;;)
     {
         
	// Tests de direction
	// La direction est exprimé en 10 000 eme
	// Prend une valeur signée d'angle de rotation autour de la ligne droite


	// Calibration de la ligne droite
#if 1
	POT_1_VALUE =  get_ADC_Value(POT_1);
	PRINTF("P1: %d \n\r", POT_1_VALUE);
	steering_cpt= STEERING_ZERO-100+POT_1_VALUE;
	PRINTF("Steering offset : %d\n\r", steering_cpt);
	Steering_UpdatePwm_Absolute(steering_cpt);
	// Pour régler le zéro de la ligne droite, tourner le potentiomètre P1 jusqu'à ce que les roues soient droites
	// Reporter la valeur de Steering offset dans CCTR_steering.h, en modifiant la valeur de la macro STEERING_OFFSET

#else
		int s=(steering_cpt%20) - 10;
		PRINTF("SR %d\n\r", s);
    	 if (iter<100) //10 secondes
          Steering_UpdatePwm_Relative(s);
    	 else
          Steering_Zero();
#endif
    	 iter ++;
         vTaskDelay(xDelay);
         steering_cpt=(steering_cpt +1)%100;

         //vTaskSuspend(NULL);
     }
 }
