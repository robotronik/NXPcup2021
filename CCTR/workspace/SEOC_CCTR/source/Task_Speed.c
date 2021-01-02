#include "CCTR.h"
#include "global.h"

/* Pour Verification de la mesure de vitesse */
/* On doit retrouver la période du moteur/steering  sur chacune des entrées */
/* Attention  : même si le rapport cyclique change, la période mesurée ne change pas */

/*
 *  Manip
 * Brancher PTE22 ou PTE23 sur sortie PTA4/ PTA12
 * Corrige par les rapports des 'prescale'
 * Motor 1 => 1200 OK
 * Steering => 200 000 OK
 */
float ang_measured_speed1_rad_s;
float ang_measured_speed2_rad_s;

void task_Speed(void *pvParameters) {

	TickType_t xLastWakeTime;
	const TickType_t xDelay = 100 / portTICK_PERIOD_MS;

    xLastWakeTime = xTaskGetTickCount();



    float pwm_prev1 = 0, pwm_prev2 = 0;
    float pwm_next1 = 0, pwm_next2 = 0;

    float speed_ref_m_s = 0.8;
    float ang_ref_speed_rad_s = 100 * speed_ref_m_s / WHEEL_RADIUS; // mult par 100 pour passer en m/s
    float PID_Ki = 1;
    float period_s = xDelay / 1000.0; // conversion de xFrequency en SI et cast en int

    int n_magnet = 9;
    float speed_ratio = 2 * 3.14 / n_magnet;

	while(init_done == 0) {
		vTaskDelay(xDelay);
	}

	for (;;)
	{
		int sens = 1;

		vTaskDelayUntil(&xLastWakeTime, xDelay);

		int s1n = speed_1_cnt, s2n = speed_2_cnt;

		speed_2_cnt = 0;
		speed_1_cnt = 0;

//		PRINTF("s1n %d  s2n %d \r\n", s1n, s2n);

		ang_measured_speed1_rad_s = s1n * speed_ratio / period_s; // omega
		ang_measured_speed2_rad_s = s2n * speed_ratio / period_s;

		pwm_next1 = pwm_prev1 - PID_Ki * (ang_measured_speed1_rad_s - ang_ref_speed_rad_s) * period_s;
    	pwm_next2 = pwm_prev2 - PID_Ki * (ang_measured_speed2_rad_s - ang_ref_speed_rad_s) * period_s;

		// Controle des bornes de la PWM

		 if (pwm_next1 < 0 ) {
			 pwm_next1 = 0;
		 }
		 else if (pwm_next1 > 100 ) {
			 pwm_next1 = 100;
		 }
		 if (pwm_next2 < 0) {
			 pwm_next2 = 0;
		 }
		 else if (pwm_next2 > 100 ) {
			 pwm_next2 = 100;
		 }

		 Motor_UpdatePwm((int)pwm_next1, sens , (int)pwm_next2, sens);
//		 Motor_UpdatePwm((int)15, sens , (int)15, sens);


//			PRINTF("pwm1 %d  pwm2 %d \r\n", pwm_next1, pwm_next2);


		 pwm_prev1 = pwm_next1;
		 pwm_prev2 = pwm_next2;


//		PRINTF("time %d\r\n", xLastWakeTime);

		/*delta=speed_1_C-speed_1_C_o+(speed_1_OVF-speed_1_OVF_o)*0xFFFF;
		PRINTF("Speed (1) %08d %08d %08d %08d %08d %08d\r\n",
				delta, speed_1_C, speed_1_OVF, speed_1_C_o, speed_1_OVF_o,		speed_1_cnt);
		delta=speed_2_C-speed_2_C_o+(speed_2_OVF-speed_2_OVF_o)*0xFFFF;
		PRINTF("     Speed (2) %08d %08d %08d %08d %08d %08d\r\n",
				delta, speed_2_C, speed_2_OVF, speed_2_C_o, speed_2_OVF_o, speed_2_cnt);
		PRINTF("SPEED %d %d\r\n", speed_1_cnt, speed_2_cnt);*/

		//vTaskSuspend(NULL);
	}
}


void task_Speed_Plot(void *pvParameters) {
	const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

	for (;;)
	{
		PRINTF("S1 %a\r\n", ang_measured_speed1_rad_s);
		PRINTF("S2 %a\r\n", ang_measured_speed2_rad_s);
		vTaskDelay(xDelay);
	}
}
