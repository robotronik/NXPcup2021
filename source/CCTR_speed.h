/*
  Auteur :
  Stéphane MANCINI
  Grenoble INP
*/

#include "CCTR.h"
#ifndef CCTR_SPEED_H
#define CCTR_SPEED_H

#define SPEED_TPM_BASEADDR TPM2

/* TPM channel used for SPEED_1 input capture */
#define SPEED_1_CAPTURE_CHANNEL kTPM_Chnl_0
#define SPEED_2_CAPTURE_CHANNEL kTPM_Chnl_1

/* Interrupt number and interrupt handler for the TPM instance used */
#define SPEED_INTERRUPT_NUMBER TPM2_IRQn
#define SPEED_INTERRUPT_HANDLER TPM2_IRQHandler

/* Interrupt to enable and flag to read; depends on the TPM channel used */
#define SPEED_1_INTERRUPT_ENABLE kTPM_Chnl0InterruptEnable
#define SPEED_2_INTERRUPT_ENABLE kTPM_Chnl1InterruptEnable
#define SPEED_OVF_INTERRUPT_ENABLE kTPM_TimeOverflowInterruptEnable

#define SPEED_1_CHANNEL_FLAG kTPM_Chnl0Flag
#define SPEED_2_CHANNEL_FLAG kTPM_Chnl1Flag
#define SPEED_OVF_FLAG kTPM_TimeOverflowFlag
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Initialisation des entrées pour les capteurs à effet Hall
 * et autorisation d'interruption sur les entrées concernées
 */
int Speed_Init(void);

/*!
 * @brief Affiche la vitesse des roues au moment où cette fonction est appelée.
 * @note Il faudra probablement modifier cette fonction pour qu'elle renvoit la valeur
 * de vitesse, au moins par pointeur.
 */
void Speed_Get(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern volatile bool speed_1_Flag, speed_2_Flag;

extern volatile int speed_OVF_Flag;

extern volatile int speed_1_C;
extern volatile int speed_1_OVF;
extern volatile int speed_1_cnt;


extern volatile int speed_2_C;
extern volatile int speed_2_OVF;
extern volatile int speed_2_cnt;

extern volatile int speed_1_C_o;
extern volatile int speed_1_OVF_o;

extern volatile int speed_2_C_o;
extern volatile int speed_2_OVF_o;

#endif
