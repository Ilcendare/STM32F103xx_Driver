/***********************************************************
****    File Name    :  RCC_interface.h                 ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  31 Oct 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  This file contains the RCC      ****
                        functions declarations and user ****
                        define macros and enumeration	****
***********************************************************/



/* ============================================== */  
/* ============= File Header Guard ============== */
/* ============================================== */



#ifndef    _MCAL_RCC_INTERFACE_H_
#define    _MCAL_RCC_INTERFACE_H_



/* ============================================== */
/* ========= Configuration Struct Types ========= */
/* ============================================== */



typedef struct {
	u8 Clock_Source           ;
	u8 HSI_Trim_Value         ;
	u8 HSE_Oscillator         ;
	u8 Clock_Security_System  ;
	u8 AHB_Prescaler          ;
	u8 APB1_Prescaler         ;
	u8 APB2_Prescaler         ;
	u8 PLL_Source             ;
	u8 PLL_Multiplier_Factor  ;    // Assigned to integers from 2 to 16;
	u8 MCO_Pin_Status         ;
} RCC_InitConfig_t;



typedef enum{
	Per_ID_AHB_DMA1   =  0,
	Per_ID_AHB_DMA2   =  1,
	Per_ID_AHB_SRAM   =  2,
	Per_ID_AHB_FLITF  =  4,
	Per_ID_AHB_CRCE   =  6,
	Per_ID_AHB_FSMC   =  8,
	Per_ID_AHB_SDIO   =  10,
    Per_ID_APB2_AFIO   =  100,
    Per_ID_APB2_GPIOA  =  102,
    Per_ID_APB2_GPIOB  =  103,
    Per_ID_APB2_GPIOC  =  104,
    Per_ID_APB2_GPIOD  =  105,
    Per_ID_APB2_GPIOE  =  106,
    Per_ID_APB2_GPIOF  =  107,
    Per_ID_APB2_GPIOG  =  108,
    Per_ID_APB2_ADC1   =  109,
    Per_ID_APB2_ADC2   =  110,
    Per_ID_APB2_TIM1   =  111,
    Per_ID_APB2_SPI1   =  112,
    Per_ID_APB2_TIM8   =  113,
    Per_ID_APB2_USART1 =  114,
    Per_ID_APB2_ADC3   =  115,
    Per_ID_APB2_TIM9   =  119,
    Per_ID_APB2_TIM10  =  120,
    Per_ID_APB2_TIM11  =  121,
	Per_ID_APB1_TIM2   =  200,
	Per_ID_APB1_TIM3   =  201,
	Per_ID_APB1_TIM4   =  202,
	Per_ID_APB1_TIM5   =  203,
	Per_ID_APB1_TIM6   =  204,
	Per_ID_APB1_TIM7   =  205,
	Per_ID_APB1_TIM12  =  206,
	Per_ID_APB1_TIM13  =  207,
	Per_ID_APB1_TIM14  =  208,
	Per_ID_APB1_WWDGEN =  211,
	Per_ID_APB1_SPI2   =  214,
	Per_ID_APB1_SPI3   =  215,
	Per_ID_APB1_USART2 =  217,
	Per_ID_APB1_USART3 =  218,
	Per_ID_APB1_UART4  =  219,
	Per_ID_APB1_UART5  =  220,
	Per_ID_APB1_I2C1   =  221,
	Per_ID_APB1_I2C2   =  222,
	Per_ID_APB1_USB    =  223,
	Per_ID_APB1_CAN    =  225,
	Per_ID_APB1_BKP    =  226,
	Per_ID_APB1_PWR    =  228,
	Per_ID_APB1_DAC    =  229
} Peripheral_ID_t;



/* ============================================== */
/* ======= User Interface Macros and Enums ====== */
/* ============================================== */



// Defined Macros for the user to select the clock source type;
// These are be written to the (Clock_Source) that is in the (RCC_Init_Config_t);
#define    RCC_HSI_CLOCK_SORCE          0
#define    RCC_HSE_CLOCK_SORCE          1
#define    RCC_PLL_CLOCK_SORCE          2



// Defined Macros for the user to configure the HSE source (External RC or Crystal oscillators);
// The RC oscillator is up to 24 MHz - The crystal oscillator is 4-16 MHz;
// These are to be written to the (HSE_Oscillator) that is in the (RCC_Init_Config_t);
#define RCC_HSE_CRYSTAL_OSCILLATOR    3
#define RCC_HSE_RC_OSCILLATOR          4



// Defined Macros for the user to enable/disable the clock security system;
// These are to be written to the (Clock_Security_System) that is in the (RCC_Init_Config_t);
#define RCC_CSS_ON          5
#define RCC_CSS_OFF         6



// Defined Macro for the default HSI Trim value;
// Can be changed by entering another value other than the default;
// This is to be written to the (HSI_Trim_Value) that is in the (RCC_Init_Config_t);
#define RCC_HSI_TRIM_DEFAULT    16



// Defined Macro for the AHB prescaler;
// These are to be written to the (AHB_Prescaler) that is in the (RCC_Init_Config_t);
#define RCC_AHB_PRE_SYSCLK_NOT_DIV      0b0000
#define RCC_AHB_PRE_SYSCLK_DIV_2        0b1000
#define RCC_AHB_PRE_SYSCLK_DIV_4        0b1001
#define RCC_AHB_PRE_SYSCLK_DIV_8        0b1010
#define RCC_AHB_PRE_SYSCLK_DIV_16       0b1011
#define RCC_AHB_PRE_SYSCLK_DIV_64       0b1100
#define RCC_AHB_PRE_SYSCLK_DIV_128      0b1101
#define RCC_AHB_PRE_SYSCLK_DIV_256      0b1110
#define RCC_AHB_PRE_SYSCLK_DIV_512      0b1111



// Defined Macro for the APB1 prescaler;
// These are to be written to the (APB1_Prescaler) that is in the (RCC_Init_Config_t);
#define RCC_APB1_PRE_AHBCLK_NOT_DIV     0b000
#define RCC_APB1_PRE_AHBCLK_DIV_2       0b100
#define RCC_APB1_PRE_AHBCLK_DIV_4       0b101
#define RCC_APB1_PRE_AHBCLK_DIV_8       0b110
#define RCC_APB1_PRE_AHBCLK_DIV_16      0b111



// Defined Macro for the APB2 prescaler;
// These are to be written to the (APB2_Prescaler) that is in the (RCC_Init_Config_t);
#define RCC_APB2_PRE_AHBCLK_NOT_DIV     0b000
#define RCC_APB2_PRE_AHBCLK_DIV_2       0b100
#define RCC_APB2_PRE_AHBCLK_DIV_4       0b101
#define RCC_APB2_PRE_AHBCLK_DIV_8       0b110
#define RCC_APB2_PRE_AHBCLK_DIV_16      0b111



// Defined Macro for the PLL source;
// These are to be written to the (PLL_Source) that is in the (RCC_Init_Config_t);
#define RCC_PLL_SOURCE_HSI_DIV_2        7
#define RCC_PLL_SOURCE_HSE_DIV_2        8
#define RCC_PLL_SOURCE_HSE_NOT_DIV      9



// Defined Macro for the MCO pin;
// These are to be written to the (MCO_Pin_Status) that is in the (RCC_Init_Config_t);
#define RCC_MCO_OFF                 0b000
#define RCC_MCO_ON_SYSCLK           0b100
#define RCC_MCO_ON_HSI              0b101
#define RCC_MCO_ON_HSE              0b110
#define RCC_MCO_ON_PLL_DIV_2        0b111



/* ============================================== */  
/* ========= RCC Functions declaration ========== */
/* ============================================== */



ErrorState_t    MCAL_RCC_voidInitSystemClock            (RCC_InitConfig_t * RCC_InitConfig );
ErrorState_t    MCAL_RCC_enumEnablePeripheralClock      (Peripheral_ID_t    Peripheral_ID  );
ErrorState_t    MCAL_RCC_enumDisablePeripheralClock     (Peripheral_ID_t    Peripheral_ID  );



#endif    //_MCAL_RCC_INTERFACE_H_
