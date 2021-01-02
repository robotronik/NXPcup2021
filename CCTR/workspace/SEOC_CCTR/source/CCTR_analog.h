#include "CCTR.h"
/*
 * CCTR_analog.h
 *
 *  Created on: Jul 1, 2019
 *      Author: segauxv
 */

#ifndef ALAMAK_ANALOG_H_
#define ALAMAK_ANALOG_H_

#define FB_G_1_ADC16_USER_CHANNEL 23U
#define FB_G_2_ADC16_USER_CHANNEL 4U
#define FB_D_1_ADC16_USER_CHANNEL 0U
#define FB_D_2_ADC16_USER_CHANNEL 8U
#define POT_1_ADC16_USER_CHANNEL 13U
#define POT_2_ADC16_USER_CHANNEL 12U
#define POT_3_ADC16_USER_CHANNEL 9U

#define FB_G_1 1
#define FB_G_2 2
#define FB_D_1 3
#define FB_D_2 4
#define POT_1 5
#define POT_2 6
#define POT_3 7

/*!
 * @brief Initialisation des entrées analogique, la procédure est
 * la même que pour les entrées de la caméra
 *
 * @note Le choix de résolution se fait par la fonction CCD_Init, car le
 * groupe d'entrée utilisé est le même.
 */
void Analog_InitPin();

/*!
 * @brief Récupération de la valeur analogique sur le port spécifié
 *
 * @param int which_port Permet de sélectionner quelle entrée lire
 *
 * @note Valeurs de paramètre possibles :
 *
 * @param FB_G_1 Feedback moteur gauche, sens 1
 * @param FB_G_2 Feedback moteur gauche, sens 2
 * @param FB_D_1 Feedback moteur droit, sens 2
 * @param FB_D_2 Feedback moteur droit, sens 2
 * @param POT_1 Valeur lue sur le potentiomètre 1
 * @param POT_2 Valeur lue sur le potentiomètre 2
 * @param POT_3 Valeur lue sur le potentiomètre 3
 */
int get_ADC_Value(int which_port);


#endif /* ALAMAK_ANALOG_H_ */
