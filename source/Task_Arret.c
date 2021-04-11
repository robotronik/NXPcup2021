
#include "CCTR.h"

/* Arret des moteurs*/
void task_Arret(void *pvParameters) {
    Motor_UpdatePwm(0, 0,
	          		0, 0);
}
