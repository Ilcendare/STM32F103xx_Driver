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
	DMA1   =  0,
	DMA2   =  1,
	SRAM   =  2,
	FLITF  =  4,
	CRCE   =  6,
	FSMC   =  8,
	SDIO   =  10,
	AFIO   =  100,    
	GPIOA  =  102, 
	GPIOB  =  103, 
	GPIOC  =  104,
	GPIOD  =  105, 	
	GPIOE  =  106, 
	GPIOF  =  107, 
 	GPIOG  =  108, 
 	ADC1   =  109, 
 	ADC2   =  110, 
  	TIM1   =  111, 
 	SPI1   =  112, 
 	TIM8   =  113, 
 	USART1 =  114,
 	ADC3   =  115,  
 	TIM9   =  119, 
 	TIM10  =  120,
 	TIM11  =  121,
	TIM2   =  200,
	TIM3   =  201,
	TIM4   =  202,
	TIM5   =  203,
	TIM6   =  204,
	TIM7   =  205,
	TIM12  =  206,
	TIM13  =  207,
	TIM14  =  208,
	WWDGEN =  211,
	SPI2   =  214,
	SPI3   =  215,
	USART2 =  217,
	USART3 =  218,
	UART4  =  219,
	UART5  =  220,
	I2C1   =  221,
	I2C2   =  222,
	USB    =  223,
	CAN    =  225,
	BKP    =  226,
	PWR    =  228,
	DAC    =  229
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



void            MCAL_RCC_InitSystemClock          (RCC_InitConfig_t * RCC_InitConfig );
ErrorState_t    MCAL_RCC_EnablePeripheralClock    (Peripheral_ID_t    Peripheral_ID  );



#endif    //_MCAL_RCC_INTERFACE_H_
