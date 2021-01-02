#include "CCTR_accel.h"
/*******************************************************************************
 * Code
 ******************************************************************************/
i2c_master_handle_t g_MasterHandle;
/* MMA8451 device address */
const uint8_t g_accel_address[] =  {0x1EU};
const uint8_t g_gyro_address = 0x20U;
const uint8_t g_magne_address[] = {0x1CU};

mma_handle_t mmaHandle = {0};
mma_data_t sensorData = {0};

fxa_handle_t fxaHandle = {0};
fxa_data_t gyroData = {0};

lis_handle_t lisHandle = {0};
lis_data_t magneData = {0};


/* Upper bound and lower bound angle values */

uint8_t dataScale = 0;


static void i2c_release_bus_delay(void) {
	uint32_t i = 0;
	for (i = 0; i < ACCEL_I2C_RELEASE_BUS_COUNT; i++) {
		__NOP();
	}
}

void Accel_I2C_ReleaseBus(void) {
	uint8_t i = 0;
	gpio_pin_config_t pin_config;
	port_pin_config_t i2c_pin_config = { 0 };

	/* Config pin mux as gpio */
	i2c_pin_config.pullSelect = kPORT_PullUp;
	i2c_pin_config.mux = kPORT_MuxAsGpio;

	pin_config.pinDirection = kGPIO_DigitalOutput;
	pin_config.outputLogic = 1U;
	CLOCK_EnableClock(kCLOCK_PortC);
	PORT_SetPinConfig(ACCEL_I2C_RELEASE_SCL_PORT, ACCEL_I2C_RELEASE_SCL_PIN,
			&i2c_pin_config);
	PORT_SetPinConfig(ACCEL_I2C_RELEASE_SDA_PORT, ACCEL_I2C_RELEASE_SDA_PIN,
			&i2c_pin_config);

	GPIO_PinInit(ACCEL_I2C_RELEASE_SCL_GPIO, ACCEL_I2C_RELEASE_SCL_PIN,
			&pin_config);
	GPIO_PinInit(ACCEL_I2C_RELEASE_SDA_GPIO, ACCEL_I2C_RELEASE_SDA_PIN,
			&pin_config);

	/* Drive SDA low first to simulate a start */
	GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SDA_GPIO, ACCEL_I2C_RELEASE_SDA_PIN,
			0U);
	i2c_release_bus_delay();

	/* Send 9 pulses on SCL and keep SDA high */
	for (i = 0; i < 9; i++) {
		GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SCL_GPIO,
				ACCEL_I2C_RELEASE_SCL_PIN, 0U);
		i2c_release_bus_delay();

		GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SDA_GPIO,
				ACCEL_I2C_RELEASE_SDA_PIN, 1U);
		i2c_release_bus_delay();

		GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SCL_GPIO,
				ACCEL_I2C_RELEASE_SCL_PIN, 1U);
		i2c_release_bus_delay();
		i2c_release_bus_delay();
	}

	/* Send stop */
	GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SCL_GPIO, ACCEL_I2C_RELEASE_SCL_PIN,
			0U);
	i2c_release_bus_delay();

	GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SDA_GPIO, ACCEL_I2C_RELEASE_SDA_PIN,
			0U);
	i2c_release_bus_delay();

	GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SCL_GPIO, ACCEL_I2C_RELEASE_SCL_PIN,
			1U);
	i2c_release_bus_delay();

	GPIO_WritePinOutput(ACCEL_I2C_RELEASE_SDA_GPIO, ACCEL_I2C_RELEASE_SDA_PIN,
			1U);
	i2c_release_bus_delay();
}

int Accel_Gyro_Magne_init(void) {

	i2c_master_config_t i2cConfig = { 0 };
	uint8_t sensorRange = 0;
	uint32_t i2cSourceClock = 0;

	/*int16_t xData = 0;
	int16_t yData = 0;
	int16_t xAngle = 0;
	int16_t yAngle = 0;*/
	//uint8_t i = 0;
	uint8_t regResult = 0;
	//uint8_t array_addr_size = 0;
    //bool foundDevice = false;


	Accel_I2C_ReleaseBus();
	BOARD_I2C_ConfigurePins();




	i2cSourceClock = CLOCK_GetFreq(ACCEL_I2C_CLK_SRC);
	mmaHandle.base = ACCEL_I2C_BASEADDR;
	mmaHandle.i2cHandle = &g_MasterHandle;
	fxaHandle.base = ACCEL_I2C_BASEADDR;
	fxaHandle.i2cHandle = &g_MasterHandle;
	lisHandle.base = ACCEL_I2C_BASEADDR;
	lisHandle.i2cHandle = &g_MasterHandle;

	I2C_MasterGetDefaultConfig(&i2cConfig);
	PRINTF("DEfault CONFIG gotten\n\r");
	I2C_MasterInit(BOARD_ACCEL_I2C_BASEADDR, &i2cConfig, i2cSourceClock);
	PRINTF("Master Init done\n\r");
	I2C_MasterTransferCreateHandle(BOARD_ACCEL_I2C_BASEADDR, &g_MasterHandle,
			NULL, NULL);
	PRINTF("Master transfer create hanlde done\n\r");

	/* Find sensor devices */
	mmaHandle.xfer.slaveAddress = g_accel_address[0];
	if (MMA_ReadReg(&mmaHandle, kMMA8451_WHO_AM_I, &regResult)
							!= kStatus_Success) {
		PRINTF("\r\nACCEL NOT FOUND\r\n");
	}
	else
		PRINTF("Accelerometer Found\n\r");

	fxaHandle.xfer.slaveAddress = g_gyro_address;
	if (FXA_ReadReg(&fxaHandle, kFXAS2100_WHO_AM_I, &regResult)
					!= kStatus_Success) {
		PRINTF("\r\nGYRO NOT FOUND\r\n");
	}
	else
		PRINTF("Gyroscope Found\n\r");

	lisHandle.xfer.slaveAddress = g_magne_address[0];
	if (LIS_ReadReg(&lisHandle, kLIS3MDL_WHO_AM_I, &regResult)
						!= kStatus_Success) {
		PRINTF("\r\nMAGNE NOT FOUND\r\n");
	}
	else
		PRINTF("Magnetometer Found\n\r");

	/*array_addr_size = sizeof(g_accel_address) / sizeof(g_accel_address[0]);
	for (i = 0; i < array_addr_size; i++) {
		mmaHandle.xfer.slaveAddress = g_accel_address[i];
		if (MMA_ReadReg(&mmaHandle, kMMA8451_WHO_AM_I, &regResult)
				== kStatus_Success) {
			foundDevice = true;
			break;
		}
		if ((i == (array_addr_size - 1)) && (!foundDevice)) {
			PRINTF("\r\nDo not found sensor device\r\n");
			while (1) {
			};
		}
	}*/

	/* Init accelerometer sensor */
	if (MMA_Init(&mmaHandle) != kStatus_Success) {
		return -1;
	}
	/* Init gyro sensor */
	if (FXA_Init(&fxaHandle) != kStatus_Success) {
		return -1;
	}
	/* Init magne sensor */
	if (LIS_Init(&lisHandle) != kStatus_Success) {
		return -1;
	}

	/* Get accel range */
	if (MMA_ReadReg(&mmaHandle, kMMA8451_XYZ_DATA_CFG, &sensorRange)
			!= kStatus_Success) {
		return -1;
	}
	if (sensorRange == 0x00) {
		dataScale = 2U;
	} else if (sensorRange == 0x01) {
		dataScale = 4U;
	} else if (sensorRange == 0x10) {
		dataScale = 8U;
	} else {
	}
}
int Accel_get(int *x, int *y, int *z) {
	int16_t xData = 0;
	int16_t yData = 0;
	int16_t zData = 0;

		/* Get new accelerometer data. */
		if (MMA_ReadSensorData(&mmaHandle, &sensorData) != kStatus_Success) {
			return -1;
		}
		/* Get the X and Y data from the sensor data structure in 14 bit left format data*/
		xData = (int16_t) ((uint16_t) ((uint16_t) sensorData.accelXMSB << 8)
				| (uint16_t) sensorData.accelXLSB) / 4U;
		yData = (int16_t) ((uint16_t) ((uint16_t) sensorData.accelYMSB << 8)
				| (uint16_t) sensorData.accelYLSB) / 4U;
		zData = (int16_t) ((uint16_t) ((uint16_t) sensorData.accelZMSB << 8)
						| (uint16_t) sensorData.accelZLSB) / 4U;
		*x=(int)xData;
		*y=(int)yData;
		*z=(int)zData;
}

int Gyro_get(int *x, int *y, int *z) {
	int16_t xData = 0;
	int16_t yData = 0;
	int16_t zData = 0;

		/* Get new accelerometer data. */
		if (FXA_ReadSensorData(&fxaHandle, &gyroData) != kStatus_Success) {
			return -1;
		}
		/* Get the X and Y data from the sensor data structure in 14 bit left format data*/
		xData = (int16_t) ((uint16_t) ((uint16_t) gyroData.gyroXMSB << 8)
				| (uint16_t) gyroData.gyroXLSB) / 4U;
		yData = (int16_t) ((uint16_t) ((uint16_t) gyroData.gyroYMSB << 8)
				| (uint16_t) gyroData.gyroYLSB) / 4U;
		zData = (int16_t) ((uint16_t) ((uint16_t) gyroData.gyroZMSB << 8)
						| (uint16_t) gyroData.gyroZLSB) / 4U;
		*x=(int)xData;
		*y=(int)yData;
		*z=(int)zData;
}

int Magne_get(int *x, int *y, int *z) {
	int16_t xData = 0;
	int16_t yData = 0;
	int16_t zData = 0;

		/* Get new accelerometer data. */
		if (LIS_ReadSensorData(&lisHandle, &magneData) != kStatus_Success) {
			return -1;
		}
		/* Get the X and Y data from the sensor data structure in 14 bit left format data*/
		xData = (int16_t) ((uint16_t) ((uint16_t) magneData.magneXMSB << 8)
				| (uint16_t) magneData.magneXLSB) / 4U;
		yData = (int16_t) ((uint16_t) ((uint16_t) magneData.magneYMSB << 8)
				| (uint16_t) magneData.magneYLSB) / 4U;
		zData = (int16_t) ((uint16_t) ((uint16_t) magneData.magneZMSB << 8)
						| (uint16_t) magneData.magneZLSB) / 4U;
		*x=(int)xData;
		*y=(int)yData;
		*z=(int)zData;
}
