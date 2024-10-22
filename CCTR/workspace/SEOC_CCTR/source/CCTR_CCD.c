#include "CCTR_CCD.h"
// Defines for LineScan Camera
#define TAOS_DELAY				asm ("nop")				// minimal delay time
#define	TAOS_SI_HIGH			CCD_SI_ON()
#define	TAOS_SI_LOW				CCD_SI_OFF()
#define	TAOS_CLK_HIGH			CCD_CK_ON()
#define	TAOS_CLK_LOW			CCD_CK_OFF()

#define	TAOS_2_SI_HIGH			CCD_2_SI_ON()
#define	TAOS_2_SI_LOW			CCD_2_SI_OFF()
#define	TAOS_2_CLK_HIGH			CCD_2_CK_ON()
#define	TAOS_2_CLK_LOW			CCD_2_CK_OFF()

adc16_channel_config_t ccd_config_channel;
adc16_channel_config_t ccd_2_config_channel;
int CCD_ImageData[2][128];
int CCD_2_ImageData[2][128];
void CCD_InitPin(void)
{
	gpio_pin_config_t led_config = {
			kGPIO_DigitalOutput, 0,
	};
	/* Init output LED GPIO. */
	GPIO_PinInit(CCD_SI_GPIO, CCD_SI_GPIO_PIN, &led_config);
	GPIO_PinInit(CCD_CK_GPIO, CCD_CK_GPIO_PIN, &led_config);
	// Camera 2 :
	GPIO_PinInit(CCD_SI_GPIO, CCD_2_SI_GPIO_PIN, &led_config);
	GPIO_PinInit(CCD_CK_GPIO, CCD_2_CK_GPIO_PIN, &led_config);

	CCD_SI_INIT(0);
	CCD_CK_INIT(0);

	// Camera 2 :
	CCD_2_SI_INIT(0);
	CCD_2_CK_INIT(0);

	adc16_config_t config;
	ADC16_GetDefaultConfig(&config);
    config.enableHighSpeed = true;
    config.resolution= kADC16_ResolutionSE8Bit;
    config.clockDivider = kADC16_ClockDivider1;
	ADC16_Init(CCD_ADC16_BASEADDR, &config);

	ccd_config_channel.channelNumber = CCD_ADC16_USER_CHANNEL;
	ccd_config_channel.enableInterruptOnConversionCompleted = false;
	ADC16_SetChannelConfig(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP, &ccd_config_channel);
	// Camera 2 :
	ccd_2_config_channel.channelNumber = CCD_2_ADC16_USER_CHANNEL;
	ccd_2_config_channel.enableInterruptOnConversionCompleted = false;
	ADC16_SetChannelConfig(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP, &ccd_2_config_channel);

}
int CCD_ADC_Value(int which) {
	if (which == 1){
		ADC16_SetChannelConfig(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP, &ccd_config_channel);
	}
	else{
		ADC16_SetChannelConfig(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP, &ccd_2_config_channel);
	}

	while ( ! (ADC16_GetChannelStatusFlags(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP) & kADC16_ChannelConversionDoneFlag));
	return ADC16_GetChannelConversionValue(CCD_ADC16_BASEADDR, CCD_ADC16_CHANNEL_GROUP);
}
// Capture LineScan Image
void CCD_ImageCapture(int which, int ind_buffer)
{
	if (which == 1){
		unsigned char i;
		TAOS_CLK_LOW;
		TAOS_SI_LOW;
		TAOS_DELAY;
		TAOS_CLK_HIGH;
		TAOS_DELAY;
		TAOS_CLK_LOW;
		TAOS_SI_HIGH;
		TAOS_DELAY;
		TAOS_CLK_HIGH;
		TAOS_DELAY;
		TAOS_SI_LOW;
		TAOS_DELAY;
		CCD_ImageData[ind_buffer][0] = CCD_ADC_Value(1);						// return value
		TAOS_CLK_LOW;
		for(i=1;i<128;i++)
		{
			TAOS_DELAY;
			TAOS_DELAY;
			TAOS_CLK_HIGH;
			TAOS_DELAY;
			TAOS_DELAY;
			// inputs data from camera (one pixel each time through loop)
			CCD_ImageData[ind_buffer][i] = CCD_ADC_Value(1);						// return value
			TAOS_CLK_LOW;
		}
		for(i=0;i<16;i++) {
		TAOS_DELAY;
		TAOS_DELAY;
		TAOS_CLK_HIGH;
		TAOS_DELAY;
		TAOS_DELAY;
		TAOS_CLK_LOW;
		}
	}
	else{
		unsigned char i;
				TAOS_2_CLK_LOW;
				TAOS_2_SI_LOW;
				TAOS_DELAY;
				TAOS_2_CLK_HIGH;
				TAOS_DELAY;
				TAOS_2_CLK_LOW;
				TAOS_2_SI_HIGH;
				TAOS_DELAY;
				TAOS_2_CLK_HIGH;
				TAOS_DELAY;
				TAOS_2_SI_LOW;
				TAOS_DELAY;
				CCD_2_ImageData[ind_buffer][0] = CCD_ADC_Value(2);						// return value
				TAOS_2_CLK_LOW;
				for(i=1;i<128;i++)
				{
					TAOS_DELAY;
					TAOS_DELAY;
					TAOS_2_CLK_HIGH;
					TAOS_DELAY;
					TAOS_DELAY;
					// inputs data from camera (one pixel each time through loop)
					CCD_2_ImageData[ind_buffer][i] = CCD_ADC_Value(2);						// return value
					TAOS_2_CLK_LOW;
				}
				for(i=0;i<16;i++) {
				TAOS_DELAY;
				TAOS_DELAY;
				TAOS_2_CLK_HIGH;
				TAOS_DELAY;
				TAOS_DELAY;
				TAOS_2_CLK_LOW;
				}
	}
}
