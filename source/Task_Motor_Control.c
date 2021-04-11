#include "CCTR.h"

/*
 * Boucle de contrôle des moteurs
 */
float omega_1, omega_2;
void task_Motor_Control(void *pvParameters) {
	const TickType_t xDelay= Ms(300);
	float m_g_p, m_g, m_d_p, m_d;
	float Km= 0.25;
	float omega_ref= 6;
	int s_1, s_2;
	int s_1_p=0, s_2_p=0;
	omega_1=0; omega_2=0;
	PRINTF("Task Motor Control\n\r");
	for (;;)
	{
		s_1= speed_1_cnt;
		speed_1_cnt= 0;
		s_2= speed_2_cnt;
		speed_2_cnt= 0;
		/*
		PRINTF("S1 %d S2 %d\r\n", s_1, s_2);
		PRINTF("MG %d MD %d\r\n", (int)m_g, (int)m_d);
*/
		omega_1= (s_1 + s_1_p)*0.5;
		omega_2= (s_2 + s_2_p)*0.5;
		s_1_p= s_1;
		s_2_p= s_2;
		m_g= m_g_p-Km*((float)omega_1-omega_ref);
		m_d= m_d_p-Km*((float)omega_2-omega_ref);
		if (m_g < 0) m_g= 0;
		if (m_g > 20) m_g= 20;
		if (m_d < 0) m_d= 0;
		if (m_d > 20) m_d= 20;
		Motor_UpdatePwm((int)m_g, 1 ,
		        		(int)m_d, 1);
		m_g_p= m_g;
		m_d_p= m_d;
	//	PRINTF("S1 %d\r\nS2 %d\r\n", s_1, s_2);
	//	PRINTF("MG %d\r\nMD %d\r\n", ((int)(m_g*1)),  ((int)(m_d*1)));

		vTaskDelay(xDelay);

	}
}
