/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.1
processor: MKL25Z128xxx4
package_id: MKL25Z128VLK4
mcu_data: ksdk2_0
processor_version: 4.0.0
board: FRDM-KL25Z
pin_labels:
- {pin_num: '1', pin_signal: PTE0/UART1_TX/RTC_CLKOUT/CMP0_OUT/I2C1_SDA, label: 'J2[18]/D14', identifier: BLUETOOTH_TX}
- {pin_num: '2', pin_signal: PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL, label: 'J2[20]/D15', identifier: BLUETOOTH_RX}
- {pin_num: '3', pin_signal: PTE2/SPI1_SCK, label: 'J9[9]', identifier: ACC_INT_2}
- {pin_num: '4', pin_signal: PTE3/SPI1_MISO/SPI1_MOSI, label: 'J9[11]', identifier: ACC_INT_1}
- {pin_num: '5', pin_signal: PTE4/SPI1_PCS0, label: 'J9[13]', identifier: GYR_INT_2}
- {pin_num: '6', pin_signal: PTE5, label: 'J9[15]', identifier: GYR_INT_1}
- {pin_num: '13', pin_signal: ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX, label: 'J10[1]', identifier: FB_D_1}
- {pin_num: '15', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX, label: 'J10[5]', identifier: SPEED_1}
- {pin_num: '16', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX, label: 'J10[7]', identifier: SPEED_2}
- {pin_num: '21', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, label: 'J10[9]', identifier: FB_G_2}
- {pin_num: '22', pin_signal: DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1, label: 'J10[11]', identifier: FB_G_1}
- {pin_num: '30', pin_signal: TSI0_CH5/PTA4/I2C1_SDA/TPM0_CH1/NMI_b, label: 'J1[10]/D4', identifier: SW_7}
- {pin_num: '31', pin_signal: PTA5/USB_CLKIN/TPM0_CH2, label: 'J1[12]/D5', identifier: SW_6}
- {pin_num: '32', pin_signal: PTA12/TPM1_CH0, label: 'J1[8]/D3', identifier: STEERING}
- {pin_num: '33', pin_signal: PTA13/TPM1_CH1, label: 'J2[2]/D8', identifier: STERRING_2}
- {pin_num: '36', pin_signal: PTA16/SPI0_MOSI/SPI0_MISO, label: 'J2[9]', identifier: MAG_DRDY}
- {pin_num: '43', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0, label: 'J10[2]/A0', identifier: FB_D_2}
- {pin_num: '44', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1, label: 'J10[4]/A1', identifier: POT_3}
- {pin_num: '45', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0, label: 'J10[6]/A2', identifier: POT_2}
- {pin_num: '46', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1, label: 'J10[8]/A3', identifier: POT_1}
- {pin_num: '47', pin_signal: PTB8/EXTRG_IN, label: 'J9[1]', identifier: CCD_SI_1}
- {pin_num: '48', pin_signal: PTB9, label: 'J9[3]', identifier: CCD_CLK_1}
- {pin_num: '49', pin_signal: PTB10/SPI1_PCS0, label: 'J9[5]', identifier: CCD_CLK_0}
- {pin_num: '50', pin_signal: PTB11/SPI1_SCK, label: 'J9[7]', identifier: CCD_SI_0}
- {pin_num: '55', pin_signal: ADC0_SE14/TSI0_CH13/PTC0/EXTRG_IN/CMP0_OUT, label: 'J1[3]', identifier: LED_5}
- {pin_num: '56', pin_signal: ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0, label: 'J10[12]/U6[31]/A5', identifier: CCD_AD_1}
- {pin_num: '57', pin_signal: ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1, label: 'J10[10]/A4', identifier: CCD_AD_0}
- {pin_num: '58', pin_signal: PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa, label: 'J1[5]', identifier: LED_4}
- {pin_num: '61', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3, label: 'J1[7]', identifier: LED_3}
- {pin_num: '62', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, label: 'J1[9]', identifier: LED_2}
- {pin_num: '63', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO, label: 'J1[11]', identifier: LED_1}
- {pin_num: '64', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, label: 'J1[1]', identifier: LED_6}
- {pin_num: '65', pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4, label: 'J1[14]', identifier: AGM_I2C_SCL}
- {pin_num: '66', pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5, label: 'J1[16]', identifier: AGM_I2C_SDA}
- {pin_num: '67', pin_signal: PTC10/I2C1_SCL, label: 'J1[13]', identifier: SW_5}
- {pin_num: '68', pin_signal: PTC11/I2C1_SDA, label: 'J1[15]', identifier: SW_4}
- {pin_num: '69', pin_signal: PTC12/TPM_CLKIN0, label: 'J2[1]', identifier: SW_1}
- {pin_num: '70', pin_signal: PTC13/TPM_CLKIN1, label: 'J2[3]', identifier: SW_2}
- {pin_num: '71', pin_signal: PTC16, label: 'J2[5]', identifier: SW_3}
- {pin_num: '72', pin_signal: PTC17, label: 'J2[7]', identifier: MAG_INT}
- {pin_num: '73', pin_signal: PTD0/SPI0_PCS0/TPM0_CH0, label: 'J2[6]/D10', identifier: MOTOR_PWM_G_2}
- {pin_num: '75', pin_signal: PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO, label: 'J2[8]/D11', identifier: MOTOR_PWM_D_1}
- {pin_num: '76', pin_signal: PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI, label: 'J2[10]/D12', identifier: MOTOR_PWM_D_2}
- {pin_num: '77', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, label: 'J1[6]/D2', identifier: SW_8}
- {pin_num: '78', pin_signal: ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5, label: 'J2[4]/D9', identifier: MOTOR_PWM_G_1}
- {pin_num: '79', pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/UART0_RX/SPI1_MISO, label: 'J2[17]', identifier: DEBUG_PIN_R}
- {pin_num: '80', pin_signal: PTD7/SPI1_MISO/UART0_TX/SPI1_MOSI, label: 'J2[19]', identifier: DEBUG_PIN}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '32', peripheral: TPM1, signal: 'CH, 0', pin_signal: PTA12/TPM1_CH0, direction: OUTPUT}
  - {pin_num: '78', peripheral: TPM0, signal: 'CH, 5', pin_signal: ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5, direction: OUTPUT}
  - {pin_num: '73', peripheral: TPM0, signal: 'CH, 0', pin_signal: PTD0/SPI0_PCS0/TPM0_CH0, direction: OUTPUT}
  - {pin_num: '75', peripheral: TPM0, signal: 'CH, 2', pin_signal: PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO, direction: OUTPUT}
  - {pin_num: '76', peripheral: TPM0, signal: 'CH, 3', pin_signal: PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI, direction: OUTPUT}
  - {pin_num: '15', peripheral: TPM2, signal: 'CH, 0', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX, direction: INPUT}
  - {pin_num: '53', peripheral: GPIOB, signal: 'GPIO, 18', pin_signal: TSI0_CH11/PTB18/TPM2_CH0, direction: OUTPUT}
  - {pin_num: '54', peripheral: GPIOB, signal: 'GPIO, 19', pin_signal: TSI0_CH12/PTB19/TPM2_CH1, direction: OUTPUT}
  - {pin_num: '74', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1, direction: OUTPUT}
  - {pin_num: '50', peripheral: GPIOB, signal: 'GPIO, 11', pin_signal: PTB11/SPI1_SCK, direction: OUTPUT}
  - {pin_num: '49', peripheral: GPIOB, signal: 'GPIO, 10', pin_signal: PTB10/SPI1_PCS0, direction: OUTPUT}
  - {pin_num: '57', peripheral: ADC0, signal: 'SE, 11', pin_signal: ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1}
  - {pin_num: '16', peripheral: TPM2, signal: 'CH, 1', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX, direction: INPUT}
  - {pin_num: '1', peripheral: UART1, signal: TX, pin_signal: PTE0/UART1_TX/RTC_CLKOUT/CMP0_OUT/I2C1_SDA, direction: OUTPUT}
  - {pin_num: '2', peripheral: UART1, signal: RX, pin_signal: PTE1/SPI1_MOSI/UART1_RX/SPI1_MISO/I2C1_SCL}
  - {pin_num: '56', peripheral: ADC0, signal: 'SE, 15', pin_signal: ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0}
  - {pin_num: '48', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: PTB9, direction: OUTPUT}
  - {pin_num: '47', peripheral: GPIOB, signal: 'GPIO, 8', pin_signal: PTB8/EXTRG_IN, direction: OUTPUT}
  - {pin_num: '22', peripheral: ADC0, signal: 'SE, 23', pin_signal: DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1}
  - {pin_num: '21', peripheral: ADC0, signal: 'SE, 4b', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0}
  - {pin_num: '13', peripheral: ADC0, signal: 'SE, 0', pin_signal: ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX}
  - {pin_num: '43', peripheral: ADC0, signal: 'SE, 8', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0}
  - {pin_num: '46', peripheral: ADC0, signal: 'SE, 13', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1}
  - {pin_num: '45', peripheral: ADC0, signal: 'SE, 12', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0}
  - {pin_num: '44', peripheral: ADC0, signal: 'SE, 9', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1}
  - {pin_num: '65', peripheral: I2C0, signal: SCL, pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4}
  - {pin_num: '66', peripheral: I2C0, signal: SDA, pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5}
  - {pin_num: '4', peripheral: GPIOE, signal: 'GPIO, 3', pin_signal: PTE3/SPI1_MISO/SPI1_MOSI}
  - {pin_num: '3', peripheral: GPIOE, signal: 'GPIO, 2', pin_signal: PTE2/SPI1_SCK}
  - {pin_num: '6', peripheral: GPIOE, signal: 'GPIO, 5', pin_signal: PTE5}
  - {pin_num: '5', peripheral: GPIOE, signal: 'GPIO, 4', pin_signal: PTE4/SPI1_PCS0}
  - {pin_num: '72', peripheral: GPIOC, signal: 'GPIO, 17', pin_signal: PTC17}
  - {pin_num: '36', peripheral: GPIOA, signal: 'GPIO, 16', pin_signal: PTA16/SPI0_MOSI/SPI0_MISO}
  - {pin_num: '64', peripheral: GPIOC, signal: 'GPIO, 7', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, direction: OUTPUT}
  - {pin_num: '55', peripheral: GPIOC, signal: 'GPIO, 0', pin_signal: ADC0_SE14/TSI0_CH13/PTC0/EXTRG_IN/CMP0_OUT, direction: OUTPUT}
  - {pin_num: '58', peripheral: GPIOC, signal: 'GPIO, 3', pin_signal: PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa, direction: OUTPUT}
  - {pin_num: '61', peripheral: GPIOC, signal: 'GPIO, 4', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3, direction: OUTPUT}
  - {pin_num: '62', peripheral: GPIOC, signal: 'GPIO, 5', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, direction: OUTPUT}
  - {pin_num: '63', peripheral: GPIOC, signal: 'GPIO, 6', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO, direction: OUTPUT}
  - {pin_num: '69', peripheral: GPIOC, signal: 'GPIO, 12', pin_signal: PTC12/TPM_CLKIN0, direction: INPUT}
  - {pin_num: '70', peripheral: GPIOC, signal: 'GPIO, 13', pin_signal: PTC13/TPM_CLKIN1, direction: INPUT}
  - {pin_num: '71', peripheral: GPIOC, signal: 'GPIO, 16', pin_signal: PTC16, direction: INPUT}
  - {pin_num: '68', peripheral: GPIOC, signal: 'GPIO, 11', pin_signal: PTC11/I2C1_SDA, direction: INPUT}
  - {pin_num: '67', peripheral: GPIOC, signal: 'GPIO, 10', pin_signal: PTC10/I2C1_SCL, direction: INPUT}
  - {pin_num: '31', peripheral: GPIOA, signal: 'GPIO, 5', pin_signal: PTA5/USB_CLKIN/TPM0_CH2, direction: INPUT}
  - {pin_num: '30', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: TSI0_CH5/PTA4/I2C1_SDA/TPM0_CH1/NMI_b, direction: INPUT}
  - {pin_num: '77', peripheral: GPIOD, signal: 'GPIO, 4', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, direction: INPUT}
  - {pin_num: '28', peripheral: UART0, signal: TX, pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1, direction: OUTPUT}
  - {pin_num: '27', peripheral: UART0, signal: RX, pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t SW_7_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA4 (pin 30)  */
    GPIO_PinInit(BOARD_INITPINS_SW_7_GPIO, BOARD_INITPINS_SW_7_PIN, &SW_7_config);

    gpio_pin_config_t SW_6_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA5 (pin 31)  */
    GPIO_PinInit(BOARD_INITPINS_SW_6_GPIO, BOARD_INITPINS_SW_6_PIN, &SW_6_config);

    gpio_pin_config_t CCD_SI_1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB8 (pin 47)  */
    GPIO_PinInit(BOARD_INITPINS_CCD_SI_1_GPIO, BOARD_INITPINS_CCD_SI_1_PIN, &CCD_SI_1_config);

    gpio_pin_config_t CCD_CLK_1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB9 (pin 48)  */
    GPIO_PinInit(BOARD_INITPINS_CCD_CLK_1_GPIO, BOARD_INITPINS_CCD_CLK_1_PIN, &CCD_CLK_1_config);

    gpio_pin_config_t CCD_CLK_0_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB10 (pin 49)  */
    GPIO_PinInit(BOARD_INITPINS_CCD_CLK_0_GPIO, BOARD_INITPINS_CCD_CLK_0_PIN, &CCD_CLK_0_config);

    gpio_pin_config_t CCD_SI_0_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB11 (pin 50)  */
    GPIO_PinInit(BOARD_INITPINS_CCD_SI_0_GPIO, BOARD_INITPINS_CCD_SI_0_PIN, &CCD_SI_0_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB18 (pin 53)  */
    GPIO_PinInit(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_PIN, &LED_RED_config);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB19 (pin 54)  */
    GPIO_PinInit(BOARD_INITPINS_LED_GREEN_GPIO, BOARD_INITPINS_LED_GREEN_PIN, &LED_GREEN_config);

    gpio_pin_config_t LED_5_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC0 (pin 55)  */
    GPIO_PinInit(BOARD_INITPINS_LED_5_GPIO, BOARD_INITPINS_LED_5_PIN, &LED_5_config);

    gpio_pin_config_t LED_4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC3 (pin 58)  */
    GPIO_PinInit(BOARD_INITPINS_LED_4_GPIO, BOARD_INITPINS_LED_4_PIN, &LED_4_config);

    gpio_pin_config_t LED_3_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC4 (pin 61)  */
    GPIO_PinInit(BOARD_INITPINS_LED_3_GPIO, BOARD_INITPINS_LED_3_PIN, &LED_3_config);

    gpio_pin_config_t LED_2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC5 (pin 62)  */
    GPIO_PinInit(BOARD_INITPINS_LED_2_GPIO, BOARD_INITPINS_LED_2_PIN, &LED_2_config);

    gpio_pin_config_t LED_1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC6 (pin 63)  */
    GPIO_PinInit(BOARD_INITPINS_LED_1_GPIO, BOARD_INITPINS_LED_1_PIN, &LED_1_config);

    gpio_pin_config_t LED_6_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC7 (pin 64)  */
    GPIO_PinInit(BOARD_INITPINS_LED_6_GPIO, BOARD_INITPINS_LED_6_PIN, &LED_6_config);

    gpio_pin_config_t SW_5_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC10 (pin 67)  */
    GPIO_PinInit(BOARD_INITPINS_SW_5_GPIO, BOARD_INITPINS_SW_5_PIN, &SW_5_config);

    gpio_pin_config_t SW_4_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC11 (pin 68)  */
    GPIO_PinInit(BOARD_INITPINS_SW_4_GPIO, BOARD_INITPINS_SW_4_PIN, &SW_4_config);

    gpio_pin_config_t SW_1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC12 (pin 69)  */
    GPIO_PinInit(BOARD_INITPINS_SW_1_GPIO, BOARD_INITPINS_SW_1_PIN, &SW_1_config);

    gpio_pin_config_t SW_2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC13 (pin 70)  */
    GPIO_PinInit(BOARD_INITPINS_SW_2_GPIO, BOARD_INITPINS_SW_2_PIN, &SW_2_config);

    gpio_pin_config_t SW_3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC16 (pin 71)  */
    GPIO_PinInit(BOARD_INITPINS_SW_3_GPIO, BOARD_INITPINS_SW_3_PIN, &SW_3_config);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD1 (pin 74)  */
    GPIO_PinInit(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_PIN, &LED_BLUE_config);

    gpio_pin_config_t SW_8_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD4 (pin 77)  */
    GPIO_PinInit(BOARD_INITPINS_SW_8_GPIO, BOARD_INITPINS_SW_8_PIN, &SW_8_config);

    /* PORTA1 (pin 27) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_RX_PORT, BOARD_INITPINS_DEBUG_UART_RX_PIN, kPORT_MuxAlt2);

    /* PORTA12 (pin 32) is configured as TPM1_CH0 */
    PORT_SetPinMux(BOARD_INITPINS_STEERING_PORT, BOARD_INITPINS_STEERING_PIN, kPORT_MuxAlt3);

    /* PORTA16 (pin 36) is configured as PTA16 */
    PORT_SetPinMux(BOARD_INITPINS_MAG_DRDY_PORT, BOARD_INITPINS_MAG_DRDY_PIN, kPORT_MuxAsGpio);

    /* PORTA2 (pin 28) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_TX_PORT, BOARD_INITPINS_DEBUG_UART_TX_PIN, kPORT_MuxAlt2);

    /* PORTA4 (pin 30) is configured as PTA4 */
    PORT_SetPinMux(BOARD_INITPINS_SW_7_PORT, BOARD_INITPINS_SW_7_PIN, kPORT_MuxAsGpio);

    /* PORTA5 (pin 31) is configured as PTA5 */
    PORT_SetPinMux(BOARD_INITPINS_SW_6_PORT, BOARD_INITPINS_SW_6_PIN, kPORT_MuxAsGpio);

    /* PORTB0 (pin 43) is configured as ADC0_SE8 */
    PORT_SetPinMux(BOARD_INITPINS_FB_D_2_PORT, BOARD_INITPINS_FB_D_2_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB1 (pin 44) is configured as ADC0_SE9 */
    PORT_SetPinMux(BOARD_INITPINS_POT_3_PORT, BOARD_INITPINS_POT_3_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB10 (pin 49) is configured as PTB10 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_CLK_0_PORT, BOARD_INITPINS_CCD_CLK_0_PIN, kPORT_MuxAsGpio);

    /* PORTB11 (pin 50) is configured as PTB11 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_SI_0_PORT, BOARD_INITPINS_CCD_SI_0_PIN, kPORT_MuxAsGpio);

    /* PORTB18 (pin 53) is configured as PTB18 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, kPORT_MuxAsGpio);

    /* PORTB19 (pin 54) is configured as PTB19 */
    PORT_SetPinMux(BOARD_INITPINS_LED_GREEN_PORT, BOARD_INITPINS_LED_GREEN_PIN, kPORT_MuxAsGpio);

    /* PORTB2 (pin 45) is configured as ADC0_SE12 */
    PORT_SetPinMux(BOARD_INITPINS_POT_2_PORT, BOARD_INITPINS_POT_2_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB3 (pin 46) is configured as ADC0_SE13 */
    PORT_SetPinMux(BOARD_INITPINS_POT_1_PORT, BOARD_INITPINS_POT_1_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB8 (pin 47) is configured as PTB8 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_SI_1_PORT, BOARD_INITPINS_CCD_SI_1_PIN, kPORT_MuxAsGpio);

    /* PORTB9 (pin 48) is configured as PTB9 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_CLK_1_PORT, BOARD_INITPINS_CCD_CLK_1_PIN, kPORT_MuxAsGpio);

    /* PORTC0 (pin 55) is configured as PTC0 */
    PORT_SetPinMux(BOARD_INITPINS_LED_5_PORT, BOARD_INITPINS_LED_5_PIN, kPORT_MuxAsGpio);

    /* PORTC1 (pin 56) is configured as ADC0_SE15 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_AD_1_PORT, BOARD_INITPINS_CCD_AD_1_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTC10 (pin 67) is configured as PTC10 */
    PORT_SetPinMux(BOARD_INITPINS_SW_5_PORT, BOARD_INITPINS_SW_5_PIN, kPORT_MuxAsGpio);

    /* PORTC11 (pin 68) is configured as PTC11 */
    PORT_SetPinMux(BOARD_INITPINS_SW_4_PORT, BOARD_INITPINS_SW_4_PIN, kPORT_MuxAsGpio);

    /* PORTC12 (pin 69) is configured as PTC12 */
    PORT_SetPinMux(BOARD_INITPINS_SW_1_PORT, BOARD_INITPINS_SW_1_PIN, kPORT_MuxAsGpio);

    /* PORTC13 (pin 70) is configured as PTC13 */
    PORT_SetPinMux(BOARD_INITPINS_SW_2_PORT, BOARD_INITPINS_SW_2_PIN, kPORT_MuxAsGpio);

    /* PORTC16 (pin 71) is configured as PTC16 */
    PORT_SetPinMux(BOARD_INITPINS_SW_3_PORT, BOARD_INITPINS_SW_3_PIN, kPORT_MuxAsGpio);

    /* PORTC17 (pin 72) is configured as PTC17 */
    PORT_SetPinMux(BOARD_INITPINS_MAG_INT_PORT, BOARD_INITPINS_MAG_INT_PIN, kPORT_MuxAsGpio);

    /* PORTC2 (pin 57) is configured as ADC0_SE11 */
    PORT_SetPinMux(BOARD_INITPINS_CCD_AD_0_PORT, BOARD_INITPINS_CCD_AD_0_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTC3 (pin 58) is configured as PTC3 */
    PORT_SetPinMux(BOARD_INITPINS_LED_4_PORT, BOARD_INITPINS_LED_4_PIN, kPORT_MuxAsGpio);

    /* PORTC4 (pin 61) is configured as PTC4 */
    PORT_SetPinMux(BOARD_INITPINS_LED_3_PORT, BOARD_INITPINS_LED_3_PIN, kPORT_MuxAsGpio);

    /* PORTC5 (pin 62) is configured as PTC5 */
    PORT_SetPinMux(BOARD_INITPINS_LED_2_PORT, BOARD_INITPINS_LED_2_PIN, kPORT_MuxAsGpio);

    /* PORTC6 (pin 63) is configured as PTC6 */
    PORT_SetPinMux(BOARD_INITPINS_LED_1_PORT, BOARD_INITPINS_LED_1_PIN, kPORT_MuxAsGpio);

    /* PORTC7 (pin 64) is configured as PTC7 */
    PORT_SetPinMux(BOARD_INITPINS_LED_6_PORT, BOARD_INITPINS_LED_6_PIN, kPORT_MuxAsGpio);

    /* PORTC8 (pin 65) is configured as I2C0_SCL */
    PORT_SetPinMux(BOARD_INITPINS_AGM_I2C_SCL_PORT, BOARD_INITPINS_AGM_I2C_SCL_PIN, kPORT_MuxAlt2);

    /* PORTC9 (pin 66) is configured as I2C0_SDA */
    PORT_SetPinMux(BOARD_INITPINS_AGM_I2C_SDA_PORT, BOARD_INITPINS_AGM_I2C_SDA_PIN, kPORT_MuxAlt2);

    /* PORTD0 (pin 73) is configured as TPM0_CH0 */
    PORT_SetPinMux(BOARD_INITPINS_MOTOR_PWM_G_2_PORT, BOARD_INITPINS_MOTOR_PWM_G_2_PIN, kPORT_MuxAlt4);

    /* PORTD1 (pin 74) is configured as PTD1 */
    PORT_SetPinMux(BOARD_INITPINS_LED_BLUE_PORT, BOARD_INITPINS_LED_BLUE_PIN, kPORT_MuxAsGpio);

    /* PORTD2 (pin 75) is configured as TPM0_CH2 */
    PORT_SetPinMux(BOARD_INITPINS_MOTOR_PWM_D_1_PORT, BOARD_INITPINS_MOTOR_PWM_D_1_PIN, kPORT_MuxAlt4);

    /* PORTD3 (pin 76) is configured as TPM0_CH3 */
    PORT_SetPinMux(BOARD_INITPINS_MOTOR_PWM_D_2_PORT, BOARD_INITPINS_MOTOR_PWM_D_2_PIN, kPORT_MuxAlt4);

    /* PORTD4 (pin 77) is configured as PTD4 */
    PORT_SetPinMux(BOARD_INITPINS_SW_8_PORT, BOARD_INITPINS_SW_8_PIN, kPORT_MuxAsGpio);

    /* PORTD5 (pin 78) is configured as TPM0_CH5 */
    PORT_SetPinMux(BOARD_INITPINS_MOTOR_PWM_G_1_PORT, BOARD_INITPINS_MOTOR_PWM_G_1_PIN, kPORT_MuxAlt4);

    /* PORTE0 (pin 1) is configured as UART1_TX */
    PORT_SetPinMux(BOARD_INITPINS_BLUETOOTH_TX_PORT, BOARD_INITPINS_BLUETOOTH_TX_PIN, kPORT_MuxAlt3);

    /* PORTE1 (pin 2) is configured as UART1_RX */
    PORT_SetPinMux(BOARD_INITPINS_BLUETOOTH_RX_PORT, BOARD_INITPINS_BLUETOOTH_RX_PIN, kPORT_MuxAlt3);

    /* PORTE2 (pin 3) is configured as PTE2 */
    PORT_SetPinMux(BOARD_INITPINS_ACC_INT_2_PORT, BOARD_INITPINS_ACC_INT_2_PIN, kPORT_MuxAsGpio);

    /* PORTE20 (pin 13) is configured as ADC0_SE0 */
    PORT_SetPinMux(BOARD_INITPINS_FB_D_1_PORT, BOARD_INITPINS_FB_D_1_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTE22 (pin 15) is configured as TPM2_CH0 */
    PORT_SetPinMux(BOARD_INITPINS_SPEED_1_PORT, BOARD_INITPINS_SPEED_1_PIN, kPORT_MuxAlt3);

    /* PORTE23 (pin 16) is configured as TPM2_CH1 */
    PORT_SetPinMux(BOARD_INITPINS_SPEED_2_PORT, BOARD_INITPINS_SPEED_2_PIN, kPORT_MuxAlt3);

    /* PORTE29 (pin 21) is configured as ADC0_SE4b */
    PORT_SetPinMux(BOARD_INITPINS_FB_G_2_PORT, BOARD_INITPINS_FB_G_2_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTE3 (pin 4) is configured as PTE3 */
    PORT_SetPinMux(BOARD_INITPINS_ACC_INT_1_PORT, BOARD_INITPINS_ACC_INT_1_PIN, kPORT_MuxAsGpio);

    /* PORTE30 (pin 22) is configured as ADC0_SE23 */
    PORT_SetPinMux(BOARD_INITPINS_FB_G_1_PORT, BOARD_INITPINS_FB_G_1_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTE4 (pin 5) is configured as PTE4 */
    PORT_SetPinMux(BOARD_INITPINS_GYR_INT_2_PORT, BOARD_INITPINS_GYR_INT_2_PIN, kPORT_MuxAsGpio);

    /* PORTE5 (pin 6) is configured as PTE5 */
    PORT_SetPinMux(BOARD_INITPINS_GYR_INT_1_PORT, BOARD_INITPINS_GYR_INT_1_PIN, kPORT_MuxAsGpio);

    SIM->SOPT4 = ((SIM->SOPT4 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT4_TPM1CH0SRC_MASK | SIM_SOPT4_TPM2CH0SRC_MASK)))

                  /* TPM1 channel 0 input capture source select: TPM1_CH0 signal. */
                  | SIM_SOPT4_TPM1CH0SRC(SOPT4_TPM1CH0SRC_TPM1_CH0)

                  /* TPM2 channel 0 input capture source select: TPM2_CH0 signal. */
                  | SIM_SOPT4_TPM2CH0SRC(SOPT4_TPM2CH0SRC_TPM2_CH0));

    SIM->SOPT5 =
        ((SIM->SOPT5 &
          /* Mask bits to zero which are setting */
          (~(SIM_SOPT5_UART0TXSRC_MASK | SIM_SOPT5_UART0RXSRC_MASK | SIM_SOPT5_UART1TXSRC_MASK | SIM_SOPT5_UART1RXSRC_MASK)))

         /* UART0 transmit data source select: UART0_TX pin. */
         | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)

         /* UART0 receive data source select: UART0_RX pin. */
         | SIM_SOPT5_UART0RXSRC(SOPT5_UART0RXSRC_UART_RX)

         /* UART1 transmit data source select: UART1_TX pin. */
         | SIM_SOPT5_UART1TXSRC(SOPT5_UART1TXSRC_UART_TX)

         /* UART1 receive data source select: UART1_RX pin. */
         | SIM_SOPT5_UART1RXSRC(SOPT5_UART1RXSRC_UART_RX));
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '65', peripheral: I2C0, signal: SCL, pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4, pull_enable: enable}
  - {pin_num: '66', peripheral: I2C0, signal: SDA, pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_I2C_ConfigurePins(void)
{
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);

    const port_pin_config_t AGM_I2C_SCL = {/* Internal pull-up resistor is enabled */
                                           kPORT_PullUp,
                                           /* Slow slew rate is configured */
                                           kPORT_SlowSlewRate,
                                           /* Passive filter is disabled */
                                           kPORT_PassiveFilterDisable,
                                           /* Low drive strength is configured */
                                           kPORT_LowDriveStrength,
                                           /* Pin is configured as I2C0_SCL */
                                           kPORT_MuxAlt2};
    /* PORTC8 (pin 65) is configured as I2C0_SCL */
    PORT_SetPinConfig(BOARD_I2C_CONFIGUREPINS_AGM_I2C_SCL_PORT, BOARD_I2C_CONFIGUREPINS_AGM_I2C_SCL_PIN, &AGM_I2C_SCL);

    const port_pin_config_t AGM_I2C_SDA = {/* Internal pull-up resistor is enabled */
                                           kPORT_PullUp,
                                           /* Slow slew rate is configured */
                                           kPORT_SlowSlewRate,
                                           /* Passive filter is disabled */
                                           kPORT_PassiveFilterDisable,
                                           /* Low drive strength is configured */
                                           kPORT_LowDriveStrength,
                                           /* Pin is configured as I2C0_SDA */
                                           kPORT_MuxAlt2};
    /* PORTC9 (pin 66) is configured as I2C0_SDA */
    PORT_SetPinConfig(BOARD_I2C_CONFIGUREPINS_AGM_I2C_SDA_PORT, BOARD_I2C_CONFIGUREPINS_AGM_I2C_SDA_PIN, &AGM_I2C_SDA);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
