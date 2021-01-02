/*
 * Copyright 2016-2018 NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    SEOC_CCTR.c
 * @brief   Application entry point.
 */
#include "CCTR.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

void task_BT_Init(void *pvParameters);
#define task_BT_Init_PRIORITY 0


void task_LED(void *pvParameters);
#define task_LED_PRIORITY 0

void task_test_Motor(void *pvParameters);
#define task_Motor_PRIORITY 2

void task_Speed(void *pvParameters);
#define task_Speed_PRIORITY 2

void task_Speed_Plot(void *pvParameters);
#define task_Speed_Plot_PRIORITY 3

void task_Accel(void *pvParameters);
#define task_Accel_PRIORITY 3

void task_Steering(void *pvParameters);
#define task_Steering_PRIORITY 1

void task_test_Steering(void *pvParameters);
#define task_Steering_PRIORITY 1

void task_CCD(void *pvParameters);
#define task_CCD_PRIORITY 0

void task_CCD_get_middle(void *pvParameters);
#define task_CCD_get_middle_PRIORITY 1

void task_Display(void *pvParameters);
#define task_Display_PRIORITY 4

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

void task_Control(void *pvParameters);
#define task_Control_PRIORITY 4
/*
 * @brief   Application entry point.
 */
//QueueHandle_t xQueueData = NULL;
// Nathan, Alexandre
int main(void) {


	//xQueueData = xQueueCreate(1, 8*sizeof(int));


	/* Init board hardware. */
	BOARD_InitPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
	//TPM_InitAll();



	/*
	 *  DANS PIN_MUX.C : mettre ces lignes là plutot, et changer la fonction
	 *   - {pin_num: '65', peripheral: I2C0, signal: SCL, pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4, pull_enable: enable}
  	 *   - {pin_num: '66', peripheral: I2C0, signal: SDA, pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5, pull_enable: enable}
	 */

	/*! Fonctions d'initialisation des différentes entrées/sorties et des protocoles de communication */
	CCTR_InitPin();
	CCTR_InitClock();
	PRINTF("Hello World CCTR SEOC Test PINs\n\r");
	Steering_Init();
	Motor_Init();
	Speed_Init();
	Accel_Gyro_Magne_init();

	/* Force the counter to be placed into memory. */

	PRINTF("Task creation\n\r");



	xTaskCreate(task_LED, "Task_LED", configMINIMAL_STACK_SIZE + 10, NULL, task_LED_PRIORITY, NULL);
	xTaskCreate(task_Control, "Task_Control", configMINIMAL_STACK_SIZE + 300, NULL, task_Control_PRIORITY, NULL);

	xTaskCreate(task_Speed, "Task_Speed", configMINIMAL_STACK_SIZE + 200, NULL, task_Speed_PRIORITY, NULL);
//	xTaskCreate(task_Speed_Plot, "Task_Speed_Plot", configMINIMAL_STACK_SIZE + 100, NULL, task_Speed_Plot_PRIORITY, NULL);

	xTaskCreate(task_Steering, "Task_Steering", configMINIMAL_STACK_SIZE + 100, NULL, task_Steering_PRIORITY, NULL);
//	xTaskCreate(task_Display, "Task_Display", configMINIMAL_STACK_SIZE + 100, NULL, task_Display_PRIORITY, NULL);

	xTaskCreate(task_CCD_get_middle, "Task_middle", configMINIMAL_STACK_SIZE + 500, NULL, task_CCD_get_middle_PRIORITY, NULL);
	xTaskCreate(task_CCD, "Task_CCD", configMINIMAL_STACK_SIZE + 100, NULL, task_CCD_PRIORITY, NULL);

//	xTaskCreate(task_Accel, "Task_Accel", configMINIMAL_STACK_SIZE + 100, NULL, task_Accel_PRIORITY, NULL);
//	xTaskCreate(task_Analog, "Task_Analog", configMINIMAL_STACK_SIZE + 100, NULL, task_Analog_PRIORITY, NULL);
//  xTaskCreate(task_Gyro, "Task_Gyro", configMINIMAL_STACK_SIZE + 100, NULL, task_Gyro_PRIORITY, NULL);
//	xTaskCreate(task_Magne, "Task_Magne", configMINIMAL_STACK_SIZE + 100, NULL, task_Gyro_PRIORITY, NULL);

//	xTaskCreate(task_test_Speed, "Task_test_Speed", configMINIMAL_STACK_SIZE, NULL, task_Speed_PRIORITY, NULL);
//	xTaskCreate(task_test_Steering, "Task_Steering", configMINIMAL_STACK_SIZE + 100, NULL, task_Steering_PRIORITY, NULL);

//	xTaskCreate(task_test_Motor, "Task_Motor", configMINIMAL_STACK_SIZE + 500, NULL, task_Motor_PRIORITY, NULL);


//	xTaskCreate(task_DIP_LED, "Task_DIP_LED", configMINIMAL_STACK_SIZE + 100, NULL, task_DIP_LED_PRIORITY, NULL);
//	xTaskCreate(task_BT_Init, "Task_BT_init", configMINIMAL_STACK_SIZE + 100, NULL, task_BT_Init_PRIORITY, NULL);
//	xTaskCreate(task_DIP_Switch, "Task_DIP_Switch", configMINIMAL_STACK_SIZE + 100, NULL, task_DIP_Switch_PRIORITY, NULL);
	PRINTF("Scheduler\n\r");
	vTaskStartScheduler();
	/* Enter an infinite loop, just incrementing a counter. */
	for (;;)
		;
	return 0 ;
}
