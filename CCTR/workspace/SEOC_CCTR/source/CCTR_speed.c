#include "CCTR_speed.h"
volatile bool speed_1_Flag= false, speed_2_Flag= false;
volatile int speed_OVF_Flag=0;

volatile int speed_1_C=0;
volatile int speed_1_OVF=0;

volatile int speed_2_C=0;
volatile int speed_2_OVF=0;

volatile int speed_1_C_o=0;
volatile int speed_1_OVF_o=0;

volatile int speed_2_C_o=0;
volatile int speed_2_OVF_o=0;
extern volatile int speed_1_cnt=0;
extern volatile int speed_2_cnt=0;


/*******************************************************************************
 * Code
 ******************************************************************************/
/* La macro eponyme permet d'enregistrer le handler */

void SPEED_INTERRUPT_HANDLER(void)
{
    uint32_t status;
    status=TPM_GetStatusFlags(SPEED_TPM_BASEADDR);
    /* Clear interrupt flag.*/
    if (status & SPEED_1_CHANNEL_FLAG){
        speed_1_Flag = true;
        speed_1_cnt ++;
        speed_1_C_o= speed_1_C;
        speed_1_OVF_o= speed_1_OVF;
        speed_1_C=TPM_GetCnV(SPEED_TPM_BASEADDR, 0);
        speed_1_OVF=speed_OVF_Flag;
    }

    if (status & SPEED_2_CHANNEL_FLAG) {
           speed_2_Flag = true;
           speed_2_cnt ++;
           speed_2_C_o= speed_2_C;
           speed_2_OVF_o= speed_2_OVF;
           speed_2_C=TPM_GetCnV(SPEED_TPM_BASEADDR, 1);
           speed_2_OVF=speed_OVF_Flag;

    }
    if (status & SPEED_OVF_FLAG)
              speed_OVF_Flag ++;

    TPM_ClearStatusFlags(SPEED_TPM_BASEADDR, SPEED_1_CHANNEL_FLAG | SPEED_2_CHANNEL_FLAG| SPEED_OVF_FLAG);

}
#if 0
status_t Speed_TPMFreq(TPM_Type *base,
                      const tpm_chnl_pwm_signal_param_t *chnlParams,
					  uint32_t pwmFreq_Hz,
                      uint32_t srcClock_Hz)
{
    assert(chnlParams);
    assert(pwmFreq_Hz);
    assert(srcClock_Hz);


    uint32_t mod;
    uint32_t tpmClock = (srcClock_Hz / (1U << (base->SC & TPM_SC_PS_MASK)));
    uint16_t cnv;
    uint8_t i;
    // mode kTPM_CombinedPwm
    base->SC &= ~TPM_SC_CPWMS_MASK;
                mod = (tpmClock / pwmFreq_Hz) - 1;
                if (mod > 65535U)
                    {
                        return kStatus_Fail;
                    }
                    /* Set the PWM period */
                    base->MOD = mod;

}
#endif
/*!
 * @brief Main function
 */
int Speed_Init(void)
{
	tpm_config_t tpmInfo;
	//uint32_t captureVal = 0;

    /* Print a note to terminal */
    PRINTF("\r\Speed capture init\r\n");

    TPM_GetDefaultConfig(&tpmInfo);
    /* Initialize TPM module */
	tpmInfo.prescale = kTPM_Prescale_Divide_4;

    TPM_Init(SPEED_TPM_BASEADDR, &tpmInfo);

    /* Setup input capture on a TPM channel */
    TPM_SetupInputCapture(SPEED_TPM_BASEADDR, SPEED_1_CAPTURE_CHANNEL, kTPM_FallingEdge);
    TPM_SetupInputCapture(SPEED_TPM_BASEADDR, SPEED_2_CAPTURE_CHANNEL, kTPM_FallingEdge);

    /* Set the timer to be in free-running mode */
    SPEED_TPM_BASEADDR->MOD = 0xFFFF;

    /* Enable channel interrupt when the second edge is detected */
    TPM_EnableInterrupts(SPEED_TPM_BASEADDR, SPEED_1_INTERRUPT_ENABLE);
    TPM_EnableInterrupts(SPEED_TPM_BASEADDR, SPEED_2_INTERRUPT_ENABLE);
    TPM_EnableInterrupts(SPEED_TPM_BASEADDR, SPEED_OVF_INTERRUPT_ENABLE);

    /* Enable at the NVIC */
    EnableIRQ(SPEED_INTERRUPT_NUMBER);

    TPM_StartTimer(SPEED_TPM_BASEADDR, kTPM_SystemClock);
}

void Speed_Get(void)
{
    while (speed_1_Flag != true)
    {
    }
int captureVal;

    captureVal = SPEED_TPM_BASEADDR->CONTROLS[SPEED_1_CAPTURE_CHANNEL].CnV;
    captureVal = SPEED_TPM_BASEADDR->CONTROLS[SPEED_2_CAPTURE_CHANNEL].CnV;

    PRINTF("\r\nCapture value C(n)V=%x\r\n", captureVal);
    while (1)
    {
    }
}
