/*
 * magne.c
 *
 *  Created on: Jul 3, 2019
 *      Author: segauxv
 */

#include <Magnetometer/magne.h>


status_t LIS_Init(lis_handle_t *handle)
{

    /* UltraHigh performance mode (X + Y)*/
    if(LIS_WriteReg(handle, kLIS3MDL_CTRL_REG1, 0x70) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* +/-4gauss full scale */
    if(LIS_WriteReg(handle, kLIS3MDL_CTRL_REG2, 0x00) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* Mode conversion continue */

    if(LIS_WriteReg(handle, kLIS3MDL_CTRL_REG3, 0x00) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* UltraHigh performance mode (Z) */
    if(LIS_WriteReg(handle, kLIS3MDL_CTRL_REG4, 0x0c) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    return kStatus_Success;
}


status_t LIS_ReadSensorData(lis_handle_t *handle, lis_data_t *magne)
{
    uint8_t val = 0U;
    uint8_t ucStatus = 0;

    do
    {
        if(LIS_ReadReg(handle, kLIS3MDL_STATUS, &ucStatus) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    } while (!(ucStatus & 0x08));

    if(LIS_ReadReg(handle, kLIS3MDL_OUT_X_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneXMSB = val;
    if(LIS_ReadReg(handle, kLIS3MDL_OUT_X_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneXLSB = val;

    if(LIS_ReadReg(handle, kLIS3MDL_OUT_Y_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneYMSB = val;
    if(LIS_ReadReg(handle, kLIS3MDL_OUT_Y_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneYLSB = val;

    if(LIS_ReadReg(handle, kLIS3MDL_OUT_Z_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneZMSB = val;
    if(LIS_ReadReg(handle, kLIS3MDL_OUT_Z_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    magne->magneZLSB = val;

    return kStatus_Success;
}



status_t LIS_ReadReg(lis_handle_t *handle, uint8_t reg, uint8_t *val)
{
    status_t status = kStatus_Success;

    /* Configure I2C xfer */
    handle->xfer.subaddress = (uint32_t)reg;
    handle->xfer.subaddressSize = 1U;
    handle->xfer.data = val;
    handle->xfer.dataSize = 1U;
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    handle->xfer.direction = kLPI2C_Read;
    handle->xfer.flags = kLPI2C_TransferDefaultFlag;
#else
    handle->xfer.direction = kI2C_Read;
    handle->xfer.flags = kI2C_TransferDefaultFlag;
#endif

#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    if(LPI2C_MasterTransferNonBlocking(handle->base, handle->i2cHandle, &handle->xfer) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    /*  wait for transfer completed. */
    while ((!g_nakFlag) && (!g_completionFlag))
    {
    }

    g_nakFlag = false;

    if (g_completionFlag == true)
    {
        g_completionFlag = false;
    }
    else
    {
        status = kStatus_Fail;
    }
#else
    status = I2C_MasterTransferBlocking(handle->base, &handle->xfer);
#endif

    return status;
}


status_t LIS_WriteReg(lis_handle_t *handle, uint8_t reg, uint8_t val)
{
    status_t status = kStatus_Success;
    uint8_t buff[1];

    buff[0] = val;
    /* Set I2C xfer structure */
    handle->xfer.subaddress = (uint32_t)reg;
    handle->xfer.subaddressSize = 1U;
    handle->xfer.data = buff;
    handle->xfer.dataSize = 1U;
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    handle->xfer.direction = kLPI2C_Write;
    handle->xfer.flags = kLPI2C_TransferDefaultFlag;
#else
    handle->xfer.direction = kI2C_Write;
    handle->xfer.flags = kI2C_TransferDefaultFlag;
#endif

#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    if(LPI2C_MasterTransferNonBlocking(handle->base, handle->i2cHandle, &handle->xfer) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    /*  wait for transfer completed. */
    while ((!g_nakFlag) && (!g_completionFlag))
    {
    }

    g_nakFlag = false;

    if (g_completionFlag == true)
    {
        g_completionFlag = false;
    }
    else
    {
        status = kStatus_Fail;
    }
#else
    status = I2C_MasterTransferBlocking(handle->base, &handle->xfer);
#endif

    return status;
}
