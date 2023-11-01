/***********************************************************
****    File Name    :  RCC_program.c                   ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  31 Oct 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  This file contains the RCC      ****
                        registers, private variables,   ****
                        data types, and functions.		****
***********************************************************/



/* ============================================== */  
/* ============= File Header Guard ============== */
/* ============================================== */



#ifndef    _MCAL_RCC_PRIVATE_H_
#define    _MCAL_RCC_PRIVATE_H_



/* ============================================== */  
/* =========== RCC Registers Bitfield =========== */
/* ============================================== */



typedef struct {
	u32 HSION   :  1;
	u32 HSIRDY  :  1;
	u32         :  1;
	u32 HSITRIM :  5;
	u32 HSICAL  :  8;
	u32 HSEON   :  1;
	u32 HSERDY  :  1;
	u32 HSEBYP  :  1;
	u32 CSS     :  1;
	u32         :  4;
	u32 PLLON   :  1;
	u32 PLLRDY  :  1;
	u32         :  6;
} RCC_CR;



typedef struct {
	u32 SW       :  2;
	u32 SWS      :  2;
	u32 HPRE     :  4;
	u32 PPRE1    :  3;
	u32 PPRE2    :  3;
	u32 ADCPRE   :  2;
	u32 PLLSRC   :  1;
	u32 PLLXTPRE :  1;
	u32 PLLMUL   :  4;
	u32 USBPRE   :  1;
	u32          :  1;
	u32 MCO      :  3;
	u32          :  5;
} RCC_CFGR;


typedef union {
	struct {
		u32 DMA1EN  :  1;
		u32 DMA2EN  :  1;
		u32 SRAMEN  :  1;
		u32         :  1;
		u32 FLITFEN :  1;
		u32         :  1;
		u32 CRCEEN  :  1;
		u32         :  1;
		u32 FSMCEN  :  1;
		u32         :  1;
		u32 SDIOEN  :  1;
		u32         : 21;
	} Bit;

	u32 Word;

} RCC_AHBENR;

typedef union {
	struct {
		u32 AFIOEN   :  1;
		u32          :  1;
		u32 IOPAEN   :  1;
		u32 IOPBEN   :  1;
		u32 IOPCEN   :  1;
		u32 IOPDEN   :  1;
		u32 IOPEEN   :  1;
		u32 IOPFEN   :  1;
		u32 IOPGEN   :  1;
		u32 ADC1EN   :  1;
		u32 ADC2EN   :  1;
		u32 TIM1EN   :  1;
		u32 SPI1EN   :  1;
		u32 TIM8EN   :  1;
		u32 USART1EN :  1;
		u32 ADC3EN   :  1;
		u32          :  3;
		u32 TIM9EN   :  1;
		u32 TIM10EN  :  1;
		u32 TIM11EN  :  1;
		u32          : 10;
	} Bit;

	u32 Word;
	
} RCC_APB2ENR;



typedef union {
	struct {
		u32 TIM2EN   :  1;
		u32 TIM3EN   :  1;
		u32 TIM4EN   :  1;
		u32 TIM5EN   :  1;
		u32 TIM6EN   :  1;
		u32 TIM7EN   :  1;
		u32 TIM12EN  :  1;
		u32 TIM13EN  :  1;
		u32 TIM14EN  :  1;
		u32          :  2;
		u32 WWDGEN   :  1;
		u32          :  2;
		u32 SPI2EN   :  1;
		u32 SPI3EN   :  1;
		u32          :  1;
		u32 USART2EN :  1;
		u32 USART3EN :  1;
		u32 UART4EN  :  1;
		u32 UART5EN  :  1;
		u32 I2C1EN   :  1;
		u32 I2C2EN   :  1;
		u32 USBEN    :  1;
		u32          :  1;
		u32 CANEN    :  1;
		u32          :  1;
		u32 BKPEN    :  1;
		u32 PWREN    :  1;
		u32 DACEN    :  1;
		u32          :  2;	
	} Bit;

	u32 Word;

} RCC_APB1ENR;



/* ============================================== */  
/* ========== RCC Registers Definition ========== */
/* ============================================== */
typedef struct {
    volatile RCC_CR        CR;
    volatile RCC_CFGR      CFGR;
    volatile u32           CIR;
    volatile u32           APB2RSTR;
    volatile u32           APB1RSTR;
    volatile RCC_AHBENR    AHBENR;
    volatile RCC_APB2ENR   APB2ENR;
    volatile RCC_APB1ENR   APB1ENR;
    volatile u32           BDCR;
    volatile u32           CSR;
} RCC_Register_t;



#define    AHB_RCC_BASE_ADDRESS    0x40021000
#define    AHB_RCC    ((RCC_Register_t *) AHB_RCC_BASE_ADDRESS)



/* ============================================== */  
/* ============= RCC Private Macros ============= */
/* ============================================== */
#define    RCC_SYSTEM_CLOCK_HSI    0
#define    RCC_SYSTEM_CLOCK_HSE    1
#define    RCC_SYSTEM_CLOCK_PLL    2


/* ============================================== */  
/* ============ RCC Private Functions =========== */
/* ============================================== */



#endif    //_MCAL_RCC_PRIVATE_H_
