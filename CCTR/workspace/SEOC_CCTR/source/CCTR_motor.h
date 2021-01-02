#include "CCTR.h"
#ifndef ALAMAK_MOTOR_H
#define ALAMAK_MOTOR_H
#define MOTOR_TIMER_BASEADDR TPM0
#define MOTOR_1_CHANNEL 5U
#define MOTOR_2_CHANNEL 0U
#define MOTOR_3_CHANNEL 2U
#define MOTOR_4_CHANNEL 3U
/* Get source clock for TPM driver */
#define MOTOR_TIMER_SOURCE_CLOCK  CLOCK_GetFreq(kCLOCK_PllFllSelClk)
#define MOTOR_CLOCK_MODE 1U
#define MOTOR_PWM_FREQ 10000U

/*!
 * @brief Initialise les timer sur les sorties concernées afin de pouvoir
 * piloter les moteurs DC
 */
void Motor_Init(void);

/*!
 * @brief Met à jour les signaux de commandes des moteurs à partir
 * d'informations sur la vitesse et le sens de rotation de cahque moteur
 *
 * @param uint16_t left vitesse désirée pour le moteur gauche (0 à 40)
 * @param uint16_t left_dir sens désiré pour le moteur gauche (-1 ou 1)
 * @param uint16_t right vitesse désirée pour le moteur droit (0 à 40)
 * @param uint16_t right_dir sens désiré pour le moteur droit (-1 ou 1)
 *
 */
void Motor_UpdatePwm(uint16_t left, int16_t left_dir, uint16_t right,
		int16_t right_dir);
#endif
