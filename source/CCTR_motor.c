/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR_motor.h"

/* Initialize timer module */
void Motor_Init(void) {
	/* convert to match type of data */
	tpm_config_t tpmInfo;
	tpm_chnl_pwm_signal_param_t tpmParam[4];

	/* Configure tpm params with frequency 10kHZ */
	tpmParam[0].chnlNumber = (tpm_chnl_t) MOTOR_1_CHANNEL;
	tpmParam[0].level = kTPM_HighTrue;
	tpmParam[0].dutyCyclePercent = 0U;

	tpmParam[1].chnlNumber = (tpm_chnl_t) MOTOR_2_CHANNEL;
	tpmParam[1].level = kTPM_HighTrue;
	tpmParam[1].dutyCyclePercent = 0U;


	tpmParam[2].chnlNumber = (tpm_chnl_t) MOTOR_3_CHANNEL;
	tpmParam[2].level = kTPM_HighTrue;
	tpmParam[2].dutyCyclePercent = 0U;

	tpmParam[3].chnlNumber = (tpm_chnl_t) MOTOR_4_CHANNEL;
	tpmParam[3].level = kTPM_HighTrue;
	tpmParam[3].dutyCyclePercent = 0U;

	/* Initialize TPM module */
	TPM_GetDefaultConfig(&tpmInfo);
	tpmInfo.prescale = kTPM_Prescale_Divide_4;

	TPM_Init(MOTOR_TIMER_BASEADDR, &tpmInfo);

	CLOCK_SetTpmClock(MOTOR_CLOCK_MODE);

	TPM_SetupPwm(MOTOR_TIMER_BASEADDR, tpmParam, 4U, kTPM_EdgeAlignedPwm,
			MOTOR_PWM_FREQ, MOTOR_TIMER_SOURCE_CLOCK);
	TPM_StartTimer(MOTOR_TIMER_BASEADDR, kTPM_SystemClock);
}

/* Update the duty cycle of an active pwm signal */
 void Motor_UpdatePwm(uint16_t left, int16_t left_dir, uint16_t right,
		int16_t right_dir) {
	/* Updated duty cycle */
	 //PRINTF("MOTOR %d %d %d %d\n\r", left, left_dir, right, right_dir);
	 uint16_t left_c= left;
	 if (left>40) left_c=40;


	if (left_dir == 0) {
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
						(tpm_chnl_t) MOTOR_1_CHANNEL, kTPM_EdgeAlignedPwm, 0);
				TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
						(tpm_chnl_t) MOTOR_2_CHANNEL, kTPM_EdgeAlignedPwm, 0);
	}
	if (left_dir == 1) {
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_1_CHANNEL, kTPM_EdgeAlignedPwm, left_c);
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_2_CHANNEL, kTPM_EdgeAlignedPwm, 0);
	}

	if (left_dir == -1) {
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_1_CHANNEL, kTPM_EdgeAlignedPwm, 0);
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_2_CHANNEL, kTPM_EdgeAlignedPwm, left_c);
	}
	uint16_t right_c= right;
    if (right > 40) right_c=40;

	if (right_dir == 0) {
			TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
					(tpm_chnl_t) MOTOR_3_CHANNEL, kTPM_EdgeAlignedPwm, 0);
			TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
					(tpm_chnl_t) MOTOR_4_CHANNEL, kTPM_EdgeAlignedPwm, 0);
		}
	if (right_dir == 1) {
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_3_CHANNEL, kTPM_EdgeAlignedPwm, right_c);
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_4_CHANNEL, kTPM_EdgeAlignedPwm, 0);
	}
	if (right_dir == -1) {
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_3_CHANNEL, kTPM_EdgeAlignedPwm, 0);
		TPM_UpdatePwmDutycycle(MOTOR_TIMER_BASEADDR,
				(tpm_chnl_t) MOTOR_4_CHANNEL, kTPM_EdgeAlignedPwm, right_c);
	}
}
