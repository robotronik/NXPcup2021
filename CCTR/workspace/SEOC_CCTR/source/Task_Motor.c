#include "CCTR.h"



 void task_test_Motor(void *pvParameters) {

TickType_t xLastWakeTime;
 const TickType_t xDelay=100/portTICK_PERIOD_MS;
 xLastWakeTime = xTaskGetTickCount();
 int motor_cpt = 0, increase = 1;

     for (;;)
     {
    	 int sens = 1;
         Motor_UpdatePwm((int)20, sens , (int)20, sens);


         int s1n = speed_1_cnt, s2n = speed_2_cnt;
         speed_2_cnt = 0;
         speed_1_cnt = 0;

         PRINTF("s1n %d  s2n %d \r\n", s1n, s2n);
         vTaskDelayUntil(&xLastWakeTime, xDelay);
     }
 }
