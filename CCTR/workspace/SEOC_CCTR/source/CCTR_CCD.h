#include "CCTR.h"
#ifndef ALAMAK_CCD_H
#define ALAMAK_CCD_H

#define CCD_ADC16_BASEADDR ADC0
#define CCD_ADC16_CHANNEL_GROUP 0U
#define CCD_ADC16_USER_CHANNEL 11U /* PTC2, ADC0_SE11 */

#define CCD_2_ADC16_USER_CHANNEL 15U

#define CCD_ADC16_IRQn ADC0_IRQn
#define CCD_ADC16_IRQ_HANDLER_FUNC ADC0_IRQHandler


extern int CCD_ImageData[2][128];
extern int CCD_2_ImageData[2][128];


/* CCD mapping */
#define LOGIC_CCD_ON 0U
#define LOGIC_CCD_OFF 1U

#define CCD_CK_GPIO GPIOB
#define CCD_CK_GPIO_PORT PORTB
#define CCD_CK_GPIO_PIN 10U

#define CCD_2_CK_GPIO_PIN 9U


#define CCD_CK_INIT(output)                                                 \
    GPIO_WritePinOutput(CCD_CK_GPIO, CCD_CK_GPIO_PIN, output); \
    CCD_CK_GPIO->PDDR |= (1U << CCD_CK_GPIO_PIN) /*!< Enable target CCD_CK */
#define CCD_CK_ON() \
    GPIO_SetPinsOutput(CCD_CK_GPIO, 1U << CCD_CK_GPIO_PIN) /*!< Turn on target CCD_CK */
#define CCD_CK_OFF() \
    GPIO_ClearPinsOutput(CCD_CK_GPIO, 1U << CCD_CK_GPIO_PIN) /*!< Turn off target CCD_CK */
#define CCD_CK_TOGGLE() \
    GPIO_TogglePinsOutput(CCD_CK_GPIO, 1U << CCD_CK_GPIO_PIN) /*!< Toggle on target CCD_CK */


#define CCD_2_CK_INIT(output)                                                 \
    GPIO_WritePinOutput(CCD_CK_GPIO, CCD_2_CK_GPIO_PIN, output); \
    CCD_CK_GPIO->PDDR |= (1U << CCD_2_CK_GPIO_PIN) /*!< Enable target CCD_CK */
#define CCD_2_CK_ON() \
    GPIO_SetPinsOutput(CCD_CK_GPIO, 1U << CCD_2_CK_GPIO_PIN) /*!< Turn on target CCD_CK */
#define CCD_2_CK_OFF() \
    GPIO_ClearPinsOutput(CCD_CK_GPIO, 1U << CCD_2_CK_GPIO_PIN) /*!< Turn off target CCD_CK */
#define CCD_2_CK_TOGGLE() \
    GPIO_TogglePinsOutput(CCD_CK_GPIO, 1U << CCD_2_CK_GPIO_PIN) /*!< Toggle on target CCD_CK */




#define CCD_SI_GPIO GPIOB
#define CCD_SI_GPIO_PORT PORTB
#define CCD_SI_GPIO_PIN 11U

#define CCD_2_SI_GPIO_PIN 8U

#define CCD_SI_INIT(output)                                                 \
    GPIO_WritePinOutput(CCD_SI_GPIO, CCD_SI_GPIO_PIN, output); \
    CCD_SI_GPIO->PDDR |= (1U << CCD_SI_GPIO_PIN) /*!< Enable target CCD_SI */
#define CCD_SI_ON() \
    GPIO_SetPinsOutput(CCD_SI_GPIO, 1U << CCD_SI_GPIO_PIN) /*!< Turn on target CCD_SI */
#define CCD_SI_OFF() \
    GPIO_ClearPinsOutput(CCD_SI_GPIO, 1U << CCD_SI_GPIO_PIN) /*!< Turn off target CCD_SI */
#define CCD_SI_TOGGLE() \
    GPIO_TogglePinsOutput(CCD_SI_GPIO, 1U << CCD_SI_GPIO_PIN) /*!< Toggle on target CCD_SI */

#define CCD_2_SI_INIT(output)                                                 \
    GPIO_WritePinOutput(CCD_SI_GPIO, CCD_2_SI_GPIO_PIN, output); \
    CCD_SI_GPIO->PDDR |= (1U << CCD_2_SI_GPIO_PIN) /*!< Enable target CCD_SI */
#define CCD_2_SI_ON() \
    GPIO_SetPinsOutput(CCD_SI_GPIO, 1U << CCD_2_SI_GPIO_PIN) /*!< Turn on target CCD_SI */
#define CCD_2_SI_OFF() \
    GPIO_ClearPinsOutput(CCD_SI_GPIO, 1U << CCD_2_SI_GPIO_PIN) /*!< Turn off target CCD_SI */
#define CCD_2_SI_TOGGLE() \
    GPIO_TogglePinsOutput(CCD_SI_GPIO, 1U << CCD_2_SI_GPIO_PIN) /*!< Toggle on target CCD_SI */

/*!
 * @brief Initialisation des pins pour les deux caméras (génération des clock,
 * intitialisation des entrées analogiques)
 *
 * @note C'est dans cette fonction qu'on peut choisir la résolution (l.40)
 * par défaut, elle est de 8 bits (0-255), mais on peut aller jusqu'a 16 bits
 */
void CCD_InitPin(void);

/*!
 * @brief Récupération de la valeur d'un pixel de la caméra
 *
 * @param int which Entier permettant de choisir quelle caméra utiliser (1 ou 2)
 */
int CCD_ADC_Value(int which);

/*!
 * @brief Cette fonction permet de récupérer la ligne complète vue par
 * la caméra. Cette ligne de 128 pixels est stockée dans la variable
 * CCD_(2)_ImageData
 *
 * @param int which Entier permettant de choisir quelle caméra utiliser (1 ou 2)
 */
void CCD_ImageCapture(int which, int ind_buffer);

#endif
