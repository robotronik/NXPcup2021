#include "CCTR.h"

#ifndef ALAMAK_STEERING_H
#define ALAMAK_STEERING_H

/* Board steering port map */
#define STEERING_TIMER_BASEADDR TPM1
#define STEERING_CHANNEL 0U

/* Get source clock for TPM driver */
#define STEERING_TIMER_SOURCE_CLOCK  CLOCK_GetFreq(kCLOCK_PllFllSelClk)
#define STEERING_CLOCK_MODE 1U
#define STEERING_PWM_FREQ 50U /* 50 Hz = 25 ms */

/*!
 * @brief Initialisation des timer liés au servo-moteur
 */
void Steering_Init(void);

/*!
 * @brief Ajuste le signal de commande du servo-moteur selon la direction
 * souhaitée.
 * @param uint16_t direction Entier entre 650 et 850
 */
void Steering_UpdatePwm(uint16_t direction);
#endif
