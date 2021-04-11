/*
 * gyro.h
 *
 *  Created on: Jul 3, 2019
 *      Author: segauxv
 */

#ifndef GYRO_H_
#define GYRO_H_


#include "fsl_common.h"
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT > 0)
#include "fsl_lpi2c.h"
#else
#include "fsl_i2c.h"
#endif


enum _fxaS2100_constants
{
    kFXAS2100_STATUS = 0x00,
    kFXAS2100_OUT_X_MSB = 0x01,
    kFXAS2100_OUT_X_LSB = 0x02,
    kFXAS2100_OUT_Y_MSB = 0x03,
    kFXAS2100_OUT_Y_LSB = 0x04,
    kFXAS2100_OUT_Z_MSB = 0x05,
    kFXAS2100_OUT_Z_LSB = 0x06,
	kFXAS2100_DR_STATUS = 0x07,
	kFXAS2100_F_STATUS = 0x08,
    kFXAS2100_F_SETUP = 0x09,
    kFXAS2100_F_EVENT = 0x0a,
    kFXAS2100_INT_SRC_FLAG= 0x0b,
    kFXAS2100_WHO_AM_I = 0x0c,
    kFXAS2100_CTRL_REG0 = 0x0d,
    kFXAS2100_RT_CFG = 0x0e,
	kFXAS2100_RT_SRC = 0x0f,
	kFXAS2100_RT_THS = 0x10,
	kFXAS2100_RT_COUNT = 0x11,
	kFXAS2100_TEMP = 0x12,
    kFXAS2100_CTRL_REG1 = 0x13,
    kFXAS2100_CTRL_REG2 = 0x14,
    kFXAS2100_CTRL_REG3 = 0x15,
};

typedef struct _fxa_data
{
    uint8_t gyroXMSB;
    uint8_t gyroXLSB;
    uint8_t gyroYMSB;
    uint8_t gyroYLSB;
    uint8_t gyroZMSB;
    uint8_t gyroZLSB;
} fxa_data_t;

/*! @brief mma8451q configure definition. This structure should be global.*/
typedef struct _fxa_handle
{
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    LPI2C_Type *base;
    lpi2c_master_transfer_t xfer;
    lpi2c_master_handle_t *i2cHandle;
#else
    I2C_Type *base;                 /*!< I2C base. */
    i2c_master_handle_t *i2cHandle; /*!< I2C master transfer context */
    i2c_master_transfer_t xfer;     /*!< I2C master xfer */
#endif
} fxa_handle_t;

/*******************************************************************************
 * API
 ******************************************************************************/


#if defined(__cplusplus)
extern "C" {
#endif


/*!
 * @brief Initialize the MMA8451 driver instance.
 *
 * @param accel_device Device driver state structure that will be filled in by this function.
 *      It is the responsibility of the caller to provide storage for this structure, and
 *      to free that storage when the driver is no longer needed.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t FXA_Init(fxa_handle_t *handle);

/*!
 * @brief Read the current acceleration values.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param accel Pointer to a structure that will be filled in with the current acceleration
 *      values for all three axes.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t FXA_ReadSensorData(fxa_handle_t *handle, fxa_data_t *accel);

/*!
 * @brief Read the value of register in accelerometer.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param reg variable store address of register
 * @param val pointer store return value.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t FXA_ReadReg(fxa_handle_t *handle, uint8_t reg, uint8_t *val);

/*!
 * @brief Write the value to register of accelerometer.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param reg variable store address of register
 * @param val pointer store value which is writen to accelerometer.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t FXA_WriteReg(fxa_handle_t *handle, uint8_t reg, uint8_t val);

#if defined(__cplusplus)
}
#endif


#endif /* GYRO_H_ */
