/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"

#ifndef CCTR_STEERING_H
#define CCTR_STEERING_H


// A modifier après calibrage de la direction droite
#define STEERING_OFFSET 722

// A ne pas modifier
#define STEERING_ZERO 750 
#define STEERING_AMPLITUDE  100
#define STEERING_MIN  STEERING_ZERO-STEERING_AMPLITUDE 
#define STEERING_MAX  STEERING_ZERO+STEERING_AMPLITUDE

/*!
 * @brief Ajuste le signal de commande du servo-moteur selon la direction
 * souhaitée.
 * @param uint16_t direction Entier entre -200 et 200
 */
uint16_t Steering_UpdatePwm_Relative(uint16_t direction);

uint16_t Steering_UpdatePwm_Absolute(uint16_t direction);


/*!
 * @brief Initialisation des timer liés au servo-moteur
 */
void Steering_Init(void);


void TPM_UpdatePwmDutycycle_10000(TPM_Type *base,
                            tpm_chnl_t chnlNumber,
                            tpm_pwm_mode_t currentPwmMode,
                            uint16_t dutyCycle);

/* Board steering port map */
#define STEERING_TIMER_BASEADDR TPM1
#define STEERING_CHANNEL 0U

/* Get source clock for TPM driver */
#define STEERING_TIMER_SOURCE_CLOCK  CLOCK_GetFreq(kCLOCK_PllFllSelClk)
#define STEERING_CLOCK_MODE 1U
#define STEERING_PWM_FREQ 50U /* 50 Hz = 25 ms */

#endif
