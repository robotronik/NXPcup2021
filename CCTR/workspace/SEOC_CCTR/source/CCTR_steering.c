#include "CCTR_steering.h"
void TPM_UpdatePwmDutycycle_10000(TPM_Type *base,
                            tpm_chnl_t chnlNumber,
                            tpm_pwm_mode_t currentPwmMode,
                            uint16_t dutyCycle)
{
    assert(chnlNumber < FSL_FEATURE_TPM_CHANNEL_COUNTn(base));
#if defined(FSL_FEATURE_TPM_HAS_COMBINE) && FSL_FEATURE_TPM_HAS_COMBINE
    if(currentPwmMode == kTPM_CombinedPwm)
    {
        assert(FSL_FEATURE_TPM_COMBINE_HAS_EFFECTn(base));
    }
#endif

    uint16_t cnv, mod;

    mod = base->MOD;
#if defined(FSL_FEATURE_TPM_HAS_COMBINE) && FSL_FEATURE_TPM_HAS_COMBINE
    if (currentPwmMode == kTPM_CombinedPwm)
    {
        uint16_t cnvFirstEdge;

        /* This check is added for combined mode as the channel number should be the pair number */
        if (chnlNumber >= (FSL_FEATURE_TPM_CHANNEL_COUNTn(base) / 2))
        {
            return;
        }
        cnv = (mod * dutyCyclePercent) / 100;
        cnvFirstEdge = base->CONTROLS[chnlNumber * 2].CnV;
        /* For 100% duty cycle */
        if (cnv >= mod)
        {
            cnv = mod + 1;
        }
        base->CONTROLS[(chnlNumber * 2) + 1].CnV = cnvFirstEdge + cnv;
    }
    else
    {
#endif
    	//PRINTF("CYCLE %d MOD %d\n\r", dutyCycle, mod);
    	int cnvi;
        cnvi = (mod * (int)dutyCycle) / 10000;
        //PRINTF("CNVI %d\n\r", cnvi);
        /* For 100% duty cycle */
        // MODIF VIRGILE --> AJOUT DU "i" à CNV DANS LE IF
        if (cnvi >= mod)
        {
            cnvi = mod + 1;
        }
        base->CONTROLS[chnlNumber].CnV = cnvi;
#if defined(FSL_FEATURE_TPM_HAS_COMBINE) && FSL_FEATURE_TPM_HAS_COMBINE
    }
#endif
}

/* Update the duty cycle of an active pwm signal */
 void Steering_UpdatePwm(uint16_t direction) {
	/* Updated duty cycle */
	 uint16_t direction_c= direction;
	 if (direction < 650) direction_c = 650;
	 if (direction > 815) direction_c = 815;
	TPM_UpdatePwmDutycycle_10000(STEERING_TIMER_BASEADDR,
			(tpm_chnl_t) STEERING_CHANNEL, kTPM_EdgeAlignedPwm, direction);


}
	 // ATTENTION : position centrale = pulse 1.5 ms
	 // correspond à rapport 7.5 => 750/10000
	 // Le rapport cyclique est exprimé en 10000 ème
	 // la précision est en réalité donnée par le diviseur de fréquence du TPM
     // Pour plus de précision, réduire le diviseur de frequence pour augmenter mod
	 // vérifier que MOD ne dépasse par 16 bits
	 // Avec division par 128, mod vaut 7499


/* Initialize timer module */
void Steering_Init(void) {
	/* convert to match type of data */
	tpm_config_t tpmInfo;
	tpm_chnl_pwm_signal_param_t tpmParam[1];


	/* Configure tpm params with frequency 50 Hz */
	tpmParam[0].chnlNumber = (tpm_chnl_t) STEERING_CHANNEL;
	tpmParam[0].level = kTPM_HighTrue;
	tpmParam[0].dutyCyclePercent = 7U;


	/* Initialize TPM module */
	TPM_GetDefaultConfig(&tpmInfo);
	tpmInfo.prescale = kTPM_Prescale_Divide_128;

	TPM_Init(STEERING_TIMER_BASEADDR, &tpmInfo);

	CLOCK_SetTpmClock(STEERING_CLOCK_MODE);

	TPM_SetupPwm(STEERING_TIMER_BASEADDR, tpmParam, 1U, kTPM_EdgeAlignedPwm,
			STEERING_PWM_FREQ, STEERING_TIMER_SOURCE_CLOCK);

	Steering_UpdatePwm(750); /* Position milieu du servo */
	TPM_StartTimer(STEERING_TIMER_BASEADDR, kTPM_SystemClock);

}
