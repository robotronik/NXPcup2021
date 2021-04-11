/*
 * gyro.c
 *
 *  Created on: Jul 3, 2019
 *      Author: segauxv
 */

#include <Gyrometer/gyro.h>


status_t FXA_Init(fxa_handle_t *handle)
{
    uint8_t val = 0;

    /* Reset sensor */
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG1, 0x20) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    /*while(!(FXA_ReadReg(handle, kFXAS2100_INT_SRC_FLAG) & 0x08))  { // wait for boot end flag to be set
    }*/

    /* Put the FXAS2100 into standby mode */
    if(FXA_ReadReg(handle, kFXAS2100_CTRL_REG1, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    //val &= (uint8_t)(~(0x03));
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG1, val & ~(0x03)) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* Set the range, -500dps to 500dps */ //PAS 100% sûr de la résolution !!!!
    /*if(FXA_ReadReg(handle, kFXAS2100_CTRL_REG0, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    val &= (uint8_t)(~0x03);
    val |= 0x01;*/
    // 200deg/s
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG0, 0x03) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    // 50 DR
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG1, 0x08) != kStatus_Success)
        {
            return kStatus_Fail;
        }

    /*  Disable FIFO, route FIFO and rate threshold interrupts to INT2, enable data ready interrupt, route to INT1 */
/*    if(FXA_ReadReg(handle, kFXAS2100_CTRL_REG2, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    val &= 0x3F;*/
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG2, 0x0e) != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* Set up rate threshold detection */
    if(FXA_WriteReg(handle, kFXAS2100_RT_CFG, 0x07) != kStatus_Success)
    {
    	return kStatus_Fail;

    }
    if(FXA_WriteReg(handle, kFXAS2100_RT_THS, 0x00 | 0x0d) != kStatus_Success)
    {
    	return kStatus_Fail;

    }
    if(FXA_WriteReg(handle, kFXAS2100_RT_COUNT, 0x04) != kStatus_Success)
    {
        return kStatus_Fail;

    }
    /* Put the kFXAS2100 into active mode */ //
    if(FXA_ReadReg(handle, kFXAS2100_CTRL_REG1, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    //Back standby
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG1, val & ~(0x03)) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    if(FXA_WriteReg(handle, kFXAS2100_CTRL_REG1, val | 0x02) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    return kStatus_Success;
}


status_t FXA_ReadSensorData(fxa_handle_t *handle, fxa_data_t *gyro)
{
    uint8_t val = 0U;
    uint8_t ucStatus = 0;

    do
    {
        if(FXA_ReadReg(handle, kFXAS2100_STATUS, &ucStatus) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    } while (!(ucStatus & 0x08));

    if(FXA_ReadReg(handle, kFXAS2100_OUT_X_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroXMSB = val;
    if(FXA_ReadReg(handle, kFXAS2100_OUT_X_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroXLSB = val;

    if(FXA_ReadReg(handle, kFXAS2100_OUT_Y_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroYMSB = val;
    if(FXA_ReadReg(handle, kFXAS2100_OUT_Y_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroYLSB = val;

    if(FXA_ReadReg(handle, kFXAS2100_OUT_Z_MSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroZMSB = val;
    if(FXA_ReadReg(handle, kFXAS2100_OUT_Z_LSB, &val) != kStatus_Success)
    {
        return kStatus_Fail;
    }
    gyro->gyroZLSB = val;

    return kStatus_Success;
}



status_t FXA_ReadReg(fxa_handle_t *handle, uint8_t reg, uint8_t *val)
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


status_t FXA_WriteReg(fxa_handle_t *handle, uint8_t reg, uint8_t val)
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
