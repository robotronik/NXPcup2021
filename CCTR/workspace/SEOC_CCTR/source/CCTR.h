#ifndef ALAMAK_H
#define ALAMAK_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_tpm.h"
#include "fsl_i2c.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_adc16.h"
#include "fsl_uart.h"

static inline uint32_t TPM_GetSC(TPM_Type *base)
{
    return base->SC;
}
static inline uint32_t TPM_GetCNT(TPM_Type *base)
{
    return base->CNT;
}
static inline uint32_t TPM_GetMod(TPM_Type *base)
{
    return base->MOD;
}

static inline uint32_t TPM_GetCnV(TPM_Type *base, int channel)
{
    return base->CONTROLS[channel].CnV;
}
static inline uint32_t TPM_GetCnSC(TPM_Type *base, int channel)
{
    return base->CONTROLS[channel].CnSC;
}

#include "CCTR_motor.h"
#include "CCTR_steering.h"
#include "CCTR_speed.h"
#include "CCTR_accel.h"
#include "CCTR_CCD.h"
#include "CCTR_analog.h"


void CCTR_InitPin();
void CCTR_InitClock(void);



#endif
