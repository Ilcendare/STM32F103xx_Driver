/**************************************************************
****    File Name    :  GPIO_interface.h                   ****
****    Author       :  Eng. Mahmoud Sayed                 ****
****    Date         :  5 Nov 2023                         ****
****    Version      :  V 1.0                              ****
****    Description  :  This file contains the GPIO's      ****
****                    functions declarations and user    ****
****                    define macros and enumeration	   ****
**************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_GPIO_INTERFACE_H_
#define    _MCAL_GPIO_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */



typedef enum {
	GPIOA,
	GPIOB,
	GPIOC
} GPIOx_t;



typedef enum {
	PIN0,
	PIN1,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
} PINn_t;



typedef enum {
	Low,
	High
} PinState_t;



#define    GPIO_OUTPUT_2HZ_PUSH_PULL         0b0010
#define    GPIO_OUTPUT_10HZ_PUSH_PULL        0b0001
#define    GPIO_OUTPUT_50HZ_PUSH_PULL        0b0011

#define    GPIO_OUTPUT_2HZ_OPEN_DRAIN        0b0110
#define    GPIO_OUTPUT_10HZ_OPEN_DRAIN       0b0101
#define    GPIO_OUTPUT_50HZ_OPEN_DRAIN       0b0111

#define    GPIO_OUTPUT_2HZ_AF_PUSH_PULL      0b1010
#define    GPIO_OUTPUT_10HZ_AF_PUSH_PULL     0b1001
#define    GPIO_OUTPUT_50HZ_AF_PUSH_PULL     0b1011

#define    GPIO_OUTPUT_2HZ_AF_OPEN_DRAIN     0b1110
#define    GPIO_OUTPUT_10HZ_AF_OPEN_DRAIN    0b1101
#define    GPIO_OUTPUT_50HZ_AF_OPEN_DRAIN    0b1111

#define    GPIO_INPUT_ANALOG                 0b0000
#define    GPIO_INPUT_FLOATING               0b0100
#define    GPIO_INPUT_PULLUP_PULLDOWN        0b1000



/* ======================================================== */  
/* ============== GPIO Functions declaration ============== */
/* ======================================================== */



ErrorState_t    MCAL_GPIO_enumSetPinMode    (GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, u32  Copy_u8Mode             );
ErrorState_t    MCAL_GPIO_enumWritePin      (GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, PinState_t  Copy_enumState  );
ErrorState_t    MCAL_GPIO_enumReadPin       (GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, u8 *Ref_u8State             );



#endif    //_MCAL_GPIO_INTERFACE_H_
