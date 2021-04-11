/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"


int BOARD_init_all(void)
{
  BOARD_InitPins();
  BOARD_InitBootClocks();
  BOARD_InitBootPeripherals();
  BOARD_InitDebugConsole();
  CCTR_InitPin();
  CCTR_InitClock();
  Steering_Init();
  Motor_Init();
  Speed_Init();
  Accel_Gyro_Magne_init();
}

void CCTR_InitPinLED(void)
{
	gpio_pin_config_t led_config = {
			kGPIO_DigitalOutput, 0,
	};
	/* Init output LED GPIO. */
	GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &led_config);
	GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &led_config);
	GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &led_config);

	LED_RED_INIT(0);
	LED_GREEN_INIT(0);
	LED_BLUE_INIT(0);
}

void CCTR_InitPinMotor(void)
{

}

void CCTR_InitPin()
{
	CCTR_InitPinLED();
	CCTR_InitPinMotor();
	CCD_InitPin();
	Analog_InitPin();
}
void CCTR_InitClock(void)
{
	/* Select the clock source for the TPM counter as kCLOCK_PllFllSelClk */

	CLOCK_SetTpmClock(1U);
}

void CCTR_InitMotor(void) {
	Motor_Init();
	Speed_Init();
}

