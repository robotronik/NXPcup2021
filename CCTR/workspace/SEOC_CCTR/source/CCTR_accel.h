#include "CCTR.h"
#ifndef ALAMAK_ACCEL_H
#define ALAMAK_ACCEL_H

#include <Accelerometer/fsl_mma.h>
#include <Gyrometer/gyro.h>
#include <Magnetometer/magne.h>
/* I2C source clock */
#define ACCEL_I2C_CLK_SRC I2C0_CLK_SRC
#define ACCEL_I2C_BAUDRATE 100000U
#define ACCEL_I2C_BASEADDR BOARD_ACCEL_I2C_BASEADDR //Défini dans board.h I2C0 --> ok normalement

#define ACCEL_I2C_RELEASE_SDA_PORT PORTC//PORTE
#define ACCEL_I2C_RELEASE_SCL_PORT PORTC//PORTE
#define ACCEL_I2C_RELEASE_SDA_GPIO GPIOC//GPIOE
#define ACCEL_I2C_RELEASE_SDA_PIN 9U//25U
#define ACCEL_I2C_RELEASE_SCL_GPIO GPIOC//GPIOE
#define ACCEL_I2C_RELEASE_SCL_PIN 8U//24U
#define ACCEL_I2C_RELEASE_BUS_COUNT 100U
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern i2c_master_handle_t g_MasterHandle;
/* MMA8451 device address */
//extern const uint8_t g_accel_address;

/*!
 * @brief Initialisation des ports I2C pour communiquer avec les
 * 3 appareils
 */
int Accel_Gyro_Magne_init(void);

/*!
 * @brief Récupération des valeurs d'accélération sur les trois axes.
 * la fonction renvoit -1 si il y a une erreur.
 *
 * @param int *x Pointeur pour stocker l'accélération en x
 * @param int *y Pointeur pour stocker l'accélération en y
 * @param int *z Pointeur pour stocker l'accélération en z
 */
int Accel_get(int *x, int *y, int *z);

/*!
 * @brief Récupération des valeurs de vitesse angulaire sur les
 * trois axes. la fonction renvoit -1 si il y a une erreur.
 *
 * @param int *x Pointeur pour stocker la vitesse angulaire en x
 * @param int *y Pointeur pour stocker la vitesse angulaire en y
 * @param int *z Pointeur pour stocker la vitesse angulaire en z
 */
int Gyro_get(int *x, int *y, int *z);

/*!
 * @brief Récupération des valeurs d'intensité du champ magnétique sur les
 * trois axes. la fonction renvoit -1 si il y a une erreur.
 *
 * @param int *x Pointeur pour stocker l'intensité du champ en x
 * @param int *y Pointeur pour stocker l'intensité du champ en y
 * @param int *z Pointeur pour stocker l'intensité du champ en z
 */
int Magne_get(int *x, int *y, int *z);

#endif
