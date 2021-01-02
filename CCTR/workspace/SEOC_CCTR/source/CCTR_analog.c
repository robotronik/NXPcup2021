#include "CCTR_analog.h"
/*
 * CCTR_analog.c
 *
 *  Created on: Jul 1, 2019
 *      Author: segauxv
 */

adc16_channel_config_t fb_g_1_config_channel;
adc16_channel_config_t fb_g_2_config_channel;
adc16_channel_config_t fb_d_1_config_channel;
adc16_channel_config_t fb_d_2_config_channel;
adc16_channel_config_t p_1_config_channel;
adc16_channel_config_t p_2_config_channel;
adc16_channel_config_t p_3_config_channel;

void Analog_InitPin(){
	//L'init de ADC0 est déjà faite par la fonction CCD_InitPin !

	fb_g_1_config_channel.channelNumber = FB_G_1_ADC16_USER_CHANNEL;
	fb_g_1_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &fb_g_1_config_channel);

	fb_g_2_config_channel.channelNumber = FB_G_2_ADC16_USER_CHANNEL;
	fb_g_2_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelMuxMode(ADC0, kADC16_ChannelMuxB);
	ADC16_SetChannelConfig(ADC0, 0U, &fb_g_2_config_channel);

	fb_d_1_config_channel.channelNumber = FB_D_1_ADC16_USER_CHANNEL;
	fb_d_1_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &fb_d_1_config_channel);

	fb_d_2_config_channel.channelNumber = FB_D_2_ADC16_USER_CHANNEL;
	fb_d_2_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &fb_d_2_config_channel);

	p_1_config_channel.channelNumber = POT_1_ADC16_USER_CHANNEL;
	p_1_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &p_1_config_channel);

	p_2_config_channel.channelNumber = POT_2_ADC16_USER_CHANNEL;
	p_2_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &p_2_config_channel);

	p_3_config_channel.channelNumber = POT_3_ADC16_USER_CHANNEL;
	p_3_config_channel.enableInterruptOnConversionCompleted = false;
	//Channel_group à changer ...?
	ADC16_SetChannelConfig(ADC0, 0U, &p_3_config_channel);
}

int get_ADC_Value(int which_port) {

	if (which_port == 1){
		ADC16_SetChannelConfig(ADC0, 0U, &fb_g_1_config_channel);
	}
	if (which_port == 2){
			ADC16_SetChannelConfig(ADC0, 0U, &fb_g_2_config_channel);
	}
	if (which_port == 3){
			ADC16_SetChannelConfig(ADC0, 0U, &fb_d_1_config_channel);
	}
	if (which_port == 4){
			ADC16_SetChannelConfig(ADC0, 0U, &fb_d_2_config_channel);
	}
	if (which_port == 5){
			ADC16_SetChannelConfig(ADC0, 0U, &p_1_config_channel);
	}
	if (which_port == 6){
			ADC16_SetChannelConfig(ADC0, 0U, &p_2_config_channel);
	}
	if (which_port == 7){
			ADC16_SetChannelConfig(ADC0, 0U, &p_3_config_channel);
	}


	while ( ! (ADC16_GetChannelStatusFlags(ADC0, 0U) & kADC16_ChannelConversionDoneFlag));
	return ADC16_GetChannelConversionValue(ADC0, 0U);
}
