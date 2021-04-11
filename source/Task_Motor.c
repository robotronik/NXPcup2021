/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"
int motor_cpt=0;

/*
 * Pour le test des moteurs
 */
 void task_Motor(void *pvParameters) {
	 const TickType_t xDelay= Ms(2000);

     for (;;)
     {

    	 int pwm_duty_cycle= (motor_cpt/5) % 20;
    	 int sens;
    	 if (motor_cpt < 100)
    		 sens = 1;
    	 else
    		 sens = -1;

         Motor_UpdatePwm(pwm_duty_cycle, sens ,
        		         pwm_duty_cycle, sens);



         vTaskDelay(xDelay);
         motor_cpt=(motor_cpt +10)% 200;
     }
 }
