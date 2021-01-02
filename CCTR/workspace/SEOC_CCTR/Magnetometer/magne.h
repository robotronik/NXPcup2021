/*
 * magne.h
 *
 *  Created on: Jul 3, 2019
 *      Author: segauxv
 */

#ifndef MAGNE_H_
#define MAGNE_H_


#include "fsl_common.h"
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT > 0)
#include "fsl_lpi2c.h"
#else
#include "fsl_i2c.h"
#endif


enum _LIS3MDL_constants
{
    kLIS3MDL_STATUS = 0x27,
    kLIS3MDL_OUT_X_MSB = 0x28,
    kLIS3MDL_OUT_X_LSB = 0x29,
    kLIS3MDL_OUT_Y_MSB = 0x2a,
    kLIS3MDL_OUT_Y_LSB = 0x2b,
    kLIS3MDL_OUT_Z_MSB = 0x2c,
    kLIS3MDL_OUT_Z_LSB = 0x2d,
	kLIS3MDL_TEMP_OUT_L = 0x2e,
	kLIS3MDL_TEMP_OUT_H = 0x2f,
    kLIS3MDL_F_SETUP = 0x09,
	kLIS3MDL_WHO_AM_I = 0x0f,
    kLIS3MDL_CTRL_REG1 = 0x20,
    kLIS3MDL_CTRL_REG2 = 0x21,
    kLIS3MDL_CTRL_REG3 = 0x22,
    kLIS3MDL_CTRL_REG4 = 0x23,
    kLIS3MDL_CTRL_REG5 = 0x24,
	kLIS3MDL_INT_CFG= 0x30,
    kLIS3MDL_INT_SRC= 0x31,
	kLIS3MDL_INT_THS_L= 0x32,
	kLIS3MDL_INT_THS_H= 0x33,
};

typedef struct _lis_data
{
    uint8_t magneXMSB;
    uint8_t magneXLSB;
    uint8_t magneYMSB;
    uint8_t magneYLSB;
    uint8_t magneZMSB;
    uint8_t magneZLSB;
} lis_data_t;

/*! @brief mma8451q configure definition. This structure should be global.*/
typedef struct _lis_handle
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
} lis_handle_t;

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
status_t LIS_Init(lis_handle_t *handle);

/*!
 * @brief Read the current acceleration values.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param accel Pointer to a structure that will be filled in with the current acceleration
 *      values for all three axes.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t LIS_ReadSensorData(lis_handle_t *handle, lis_data_t *accel);

/*!
 * @brief Read the value of register in accelerometer.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param reg variable store address of register
 * @param val pointer store return value.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t LIS_ReadReg(lis_handle_t *handle, uint8_t reg, uint8_t *val);

/*!
 * @brief Write the value to register of accelerometer.
 *
 * @param handle Pointer to a valid accel_device instance structure.
 * @param reg variable store address of register
 * @param val pointer store value which is writen to accelerometer.
 *
 * @return kStatus_Success if success or kStatus_Fail if error.
 */
status_t LIS_WriteReg(lis_handle_t *handle, uint8_t reg, uint8_t val);

#if defined(__cplusplus)
}
#endif

#endif /* MAGNE_H_ */
