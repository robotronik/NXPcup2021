/*
Auteur :
Stéphane MANCINI
Grenoble INP
 */

/**
 * @file    main_SEOC_CCTR.c
 * @brief   Application entry point.
 */
#include "CCTR.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

void task_BT_Init(void *pvParameters);
#define task_BT_Init_PRIORITY 0

void task_Arret(void *pvParameters);
#define task_Arret_PRIORITY 0

void task_LED_2(void *pvParameters);
#define task_LED_PRIORITY 0

void task_Motor(void *pvParameters);
#define task_Motor_PRIORITY 2

void task_Speed(void *pvParameters);
#define task_Speed_PRIORITY 3

void task_Accel(void *pvParameters);
#define task_Accel_PRIORITY 2

void task_Steering(void *pvParameters);
#define task_Steering_PRIORITY 1

void task_Camera(void *pvParameters);
#define task_Camera_PRIORITY 4

void task_Camera_Display(void *pvParameters);
#define task_Camera_Display_PRIORITY 0

void task_DIP_LED(void *pvParameters);
#define task_DIP_LED_PRIORITY 0

void task_DIP_Switch(void *pvParameters);
#define task_DIP_Switch_PRIORITY 0

void task_Analog(void *pvParameters);
#define task_Analog_PRIORITY 0

void task_Gyro(void *pvParameters);
#define task_Gyro_PRIORITY 0

void task_Magne(void *pvParameters);
#define task_Magne_PRIORITY 0


void task_Camera_Double_Integration(void *pvParameters);
#define task_Camera_Double_Integration_PRIORITY 4

void task_Piste(void *pvParameters);
#define task_Piste_PRIORITY 1

void task_Piste_Display(void *pvParameters);
#define task_Piste_Display_PRIORITY 0


void task_Motor_Control(void *pvParameters);
#define task_Motor_Control_PRIORITY 2


/*
 * @brief   Application entry point.
 */

int main(void) {
	/* Init board hardware. */
	BOARD_init_all();

	PRINTF("Hello World CCTR SEOC Solution Piste Calib\n\r");
	LED_RED_TOGGLE();
	LED_GREEN_TOGGLE();
	/* Force the counter to be placed into memory. */
	//volatile static int i = 0 ;
	//xTaskCreate(task_DIP_LED, "Task_DIP_LED", configMINIMAL_STACK_SIZE + 100, NULL, task_DIP_LED_PRIORITY, NULL);
	//xTaskCreate(task_LED_2, "Task_LED", configMINIMAL_STACK_SIZE + 100, NULL, task_LED_PRIORITY, NULL);
	//xTaskCreate(task_Motor, "Task_Motor", configMINIMAL_STACK_SIZE + 100, NULL, task_Motor_PRIORITY, NULL);
	//xTaskCreate(task_Speed, "Task_Speed", configMINIMAL_STACK_SIZE + 200, NULL, task_Speed_PRIORITY, NULL);
	//xTaskCreate(task_Steering, "Task_Steering", configMINIMAL_STACK_SIZE + 100, NULL, task_Steering_PRIORITY, NULL);
	//xTaskCreate(task_Accel, "Task_Accel", configMINIMAL_STACK_SIZE + 100, NULL, task_Accel_PRIORITY, NULL);
#if 0
	xTaskCreate(task_Camera_Display, "Task_CAM_D", configMINIMAL_STACK_SIZE + 200, NULL, task_Camera_Display_PRIORITY, NULL);
	xTaskCreate(task_Camera, "Task_CAM", configMINIMAL_STACK_SIZE + 100, NULL, task_Camera_PRIORITY, NULL);
#endif
	//xTaskCreate(task_DIP_Switch, "Task_DIP_Switch", configMINIMAL_STACK_SIZE + 100, NULL, task_DIP_Switch_PRIORITY, NULL);
	//xTaskCreate(task_Analog, "Task_Analog", configMINIMAL_STACK_SIZE + 100, NULL, task_Analog_PRIORITY, NULL);
	//xTaskCreate(task_Gyro, "Task_Gyro", configMINIMAL_STACK_SIZE + 100, NULL, task_Gyro_PRIORITY, NULL);
	//xTaskCreate(task_Magne, "Task_Magne", configMINIMAL_STACK_SIZE + 100, NULL, task_Gyro_PRIORITY, NULL);
	//xTaskCreate(task_BT_Init, "Task_BT_init", configMINIMAL_STACK_SIZE + 100, NULL, task_BT_Init_PRIORITY, NULL);
#if 1
	xTaskCreate(task_Arret,"Task_Stop", configMINIMAL_STACK_SIZE + 100, NULL,task_Arret_PRIORITY,NULL);
	xTaskCreate(task_Camera_Double_Integration, "Task_C2", configMINIMAL_STACK_SIZE + 200, NULL, task_Camera_Double_Integration_PRIORITY, NULL);
	xTaskCreate(task_Piste, "Task_Track", configMINIMAL_STACK_SIZE + 200, NULL, task_Piste_PRIORITY, NULL);
	xTaskCreate(task_Piste_Display, "Task_TD", configMINIMAL_STACK_SIZE + 200+100, NULL, task_Piste_Display_PRIORITY, NULL);

	xTaskCreate(task_Motor_Control, "Task_MC", configMINIMAL_STACK_SIZE + 200, NULL, task_Motor_Control_PRIORITY, NULL);
#endif

	vTaskStartScheduler();
	/* Enter an infinite loop, just incrementing a counter. */
	for (;;)
		;

	return 0 ;
}
