/*****************************************************************
****    File Name    :  NVIC_interface.h                      ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  6 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the NVIC's         ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_NVIC_INTERFACE_H_
#define    _MCAL_NVIC_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */



/* Defined IRQs ID based on the Interrupt Vector Table */

typedef enum {
    WWDG,
    PVD,
    TAMPER,
    RTC,
    FLASH,
    RCC,
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    DMA1_Channel1,
    DMA1_Channel2,
    DMA1_Channel3,
    DMA1_Channel4,
    DMA1_Channel5,
    DMA1_Channel6,
    DMA1_Channel7,
    ADC1_2,
    USB_HP_CAN_,
    TX,
    USB_LP_CAN_,
    RX0,
    CAN_RX1,
    CAN_SCE,
    EXTI9_5,
    TIM1_BRK,
    TIM1_UP,
    TIM1_TRG_COM,
    TIM1_CC,
    TIM2,
    TIM3,
    TIM4,
    I2C1_EV,
    I2C1_ER,
    I2C2_EV,
    I2C2_ER,
    SPI1,
    SPI2,
    USART1,
    USART2,
    USART3,
    EXTI15_10,
    RTCAlarm,
    USBWakeup,
    TIM8_BRK,
    TIM8_UP,
    TIM8_TRG_COM,
    TIM8_CC,
    ADC3,
    FSMC,
    SDIO,
    TIM5,
    SPI3,
    UART4,
    UART5,
    TIM6,
    TIM7,
    DMA2_Channel1,
    DMA2_Channel2,
    DMA2_Channel3,
    DMA2_Channel4_5,
} IRQx_t;



/* ======================================================== */  
/* ============== NVIC Functions declaration ============== */
/* ======================================================== */



ErrorState_t    MCAL_NVIC_enumSetIRQx                 (IRQx_t    Copy_enumIRQx                                 );

ErrorState_t    MCAL_NVIC_enumClearIRQx               (IRQx_t    Copy_enumIRQx                                 );

ErrorState_t    MCAL_NVIC_enumGetIRQxState            (IRQx_t    Copy_enumIRQx , u8  * Ref_u8IRQxStatus        );

ErrorState_t    MCAL_NVIC_enumSetIRQxPendingFlag      (IRQx_t    Copy_enumIRQx                                 );

ErrorState_t    MCAL_NVIC_enumClearIRQxPendingFlag    (IRQx_t    Copy_enumIRQx                                 );

ErrorState_t    MCAL_NVIC_enumGetIRQxPendingFlag      (IRQx_t    Copy_enumIRQx , u8  * Ref_u8PendingFlagStatus );

ErrorState_t    MCAL_NVIC_enumGetIRQxActiveFlag       (IRQx_t    Copy_enumIRQx , u8  * Ref_u8ActiveFlagStatus  );

ErrorState_t    MCAL_NVIC_enumSetIRQxPriority         (IRQx_t    Copy_enumIRQx , u8    Copy_u8Priority         );

ErrorState_t    MCAL_NVIC_enumGenerateSWI             (IRQx_t    Copy_enumIRQx                                 );



#endif    //_MCAL_NVIC_INTERFACE_H_
