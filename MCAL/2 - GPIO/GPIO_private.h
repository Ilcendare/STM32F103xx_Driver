/************************************************************
****    File Name    :  GPIO_program.c                   ****
****    Author       :  Eng. Mahmoud Sayed               ****
****    Date         :  5 Nov 2023                       ****
****    Version      :  V 1.0                            ****
****    Description  :  This file contains the GPIO's    ****
                        registers, private variables,    ****
                        data types, and functions.		 ****
************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_GPIO_PRIVATE_H_ 
#define    _MCAL_GPIO_PRIVATE_H_ 



/* ======================================================== */  
/* ================ GPIO Registers Bitfield =============== */
/* ======================================================== */



typedef union {
    struct {
        u32 Mode_0 : 2;
        u32 Conf_0 : 2;
		
        u32 Mode_1 : 2;
        u32 Conf_1 : 2;
		
        u32 Mode_2 : 2;
        u32 Conf_2 : 2;
		
        u32 Mode_3 : 2;
        u32 Conf_3 : 2;
		
        u32 Mode_4 : 2;
        u32 Conf_4 : 2;
		
        u32 Mode_5 : 2;
        u32 Conf_5 : 2;
		
        u32 Mode_6 : 2;
        u32 Conf_6 : 2;
		
        u32 Mode_7 : 2;
        u32 Conf_7 : 2;
	} Bit;
	
    u32 Word;
} CRL_t;



typedef union {
    struct {
        u32 Mode_8  : 2;
        u32 Conf_8  : 2;
		
        u32 Mode_9  : 2;
        u32 Conf_9  : 2;
		
        u32 Mode_10 : 2;
        u32 Conf_10 : 2;
		
        u32 Mode_11 : 2;
        u32 Conf_11 : 2;
		
        u32 Mode_12 : 2;
        u32 Conf_12 : 2;
		
        u32 Mode_13 : 2;
        u32 Conf_13 : 2;
		
        u32 Mode_14 : 2;
        u32 Conf_14 : 2;
		
        u32 Mode_15 : 2;
        u32 Conf_15 : 2;
	} Bit;
	
    u32 Word;
} CRH_t;



typedef union {
    struct {
        u32    PIN0  :  1;
        u32    PIN1  :  1;
        u32    PIN2  :  1;
        u32    PIN3  :  1;
        u32    PIN4  :  1;
        u32    PIN5  :  1;
        u32    PIN6  :  1;
        u32    PIN7  :  1;
        u32    PIN8  :  1;
        u32    PIN9  :  1;
        u32    PIN10 :  1;
        u32    PIN11 :  1;
        u32    PIN12 :  1;
        u32    PIN13 :  1;
        u32    PIN14 :  1;
        u32    PIN15 :  1;
		u32          : 16;
	} Bit;
	
    u32 Word;
} IDR_t;



typedef union {
    struct {
        u32    PIN0  :  1;
        u32    PIN1  :  1;
        u32    PIN2  :  1;
        u32    PIN3  :  1;
        u32    PIN4  :  1;
        u32    PIN5  :  1;
        u32    PIN6  :  1;
        u32    PIN7  :  1;
        u32    PIN8  :  1;
        u32    PIN9  :  1;
        u32    PIN10 :  1;
        u32    PIN11 :  1;
        u32    PIN12 :  1;
        u32    PIN13 :  1;
        u32    PIN14 :  1;
        u32    PIN15 :  1;
		u32          : 16;
	} Bit;
	
    u32 Word;
} ODR_t;



typedef union {
    struct {
        u32    BS0  :  1;
        u32    BS1  :  1;
        u32    BS2  :  1;
        u32    BS3  :  1;
        u32    BS4  :  1;
        u32    BS5  :  1;
        u32    BS6  :  1;
        u32    BS7  :  1;
        u32    BS8  :  1;
        u32    BS9  :  1;
        u32    BS10 :  1;
        u32    BS11 :  1;
        u32    BS12 :  1;
        u32    BS13 :  1;
        u32    BS14 :  1;
        u32    BS15 :  1;
        u32    BR0  :  1;
        u32    BR1  :  1;
        u32    BR2  :  1;
        u32    BR3  :  1;
        u32    BR4  :  1;
        u32    BR5  :  1;
        u32    BR6  :  1;
        u32    BR7  :  1;
        u32    BR8  :  1;
        u32    BR9  :  1;
        u32    BR10 :  1;
        u32    BR11 :  1;
        u32    BR12 :  1;
        u32    BR13 :  1;
        u32    BR14 :  1;
        u32    BR15 :  1;
		
	} Bit;
	
    u32 Word;
} BSRR_t;



typedef union {
    struct {
        u32    BR0  :  1;
        u32    BR1  :  1;
        u32    BR2  :  1;
        u32    BR3  :  1;
        u32    BR4  :  1;
        u32    BR5  :  1;
        u32    BR6  :  1;
        u32    BR7  :  1;
        u32    BR8  :  1;
        u32    BR9  :  1;
        u32    BR10 :  1;
        u32    BR11 :  1;
        u32    BR12 :  1;
        u32    BR13 :  1;
        u32    BR14 :  1;
        u32    BR15 :  1;
		u32         : 16;
	} Bit;
	
    u32 Word;
} BRR_t;



typedef union {
    struct {
        u32    LCK0  :  1;
        u32    LCK1  :  1;
        u32    LCK2  :  1;
        u32    LCK3  :  1;
        u32    LCK4  :  1;
        u32    LCK5  :  1;
        u32    LCK6  :  1;
        u32    LCK7  :  1;
        u32    LCK8  :  1;
        u32    LCK9  :  1;
        u32    LCK10 :  1;
        u32    LCK11 :  1;
        u32    LCK12 :  1;
        u32    LCK13 :  1;
        u32    LCK14 :  1;
        u32    LCK15 :  1;
		u32    LCKK  :  1;
		u32          : 15;
	} Bit;
	
    u32 Word;
} LCKR_t;



/* ======================================================== */  
/* =============== GPIO Registers Definition ============== */
/* ======================================================== */



typedef struct {
    volatile CRL_t    CRL   ;
    volatile CRH_t    CRH   ;
    volatile IDR_t    IDR   ;
    volatile ODR_t    ODR   ;
    volatile BSRR_t   BSRR  ;
    volatile BRR_t    BRR   ;
    volatile LCKR_t   LCKR  ;
} GPIOx_Registers_t;


#define    GPIOA_BASE_ADDRESS    0x40010800

#define    GPIOB_BASE_ADDRESS    0x40010C00

#define    GPIOC_BASE_ADDRESS    0x40011000

#define    GPIOD_BASE_ADDRESS    0x40011400

#define    GPIOE_BASE_ADDRESS    0x40011800

#define    GPIOF_BASE_ADDRESS    0x40011C00

#define    GPIOG_BASE_ADDRESS    0x40012000


#define    APB2_GPIOA    ((GPIOx_Registers_t *)GPIOA_BASE_ADDRESS)

#define    APB2_GPIOB    ((GPIOx_Registers_t *)GPIOB_BASE_ADDRESS)

#define    APB2_GPIOC    ((GPIOx_Registers_t *)GPIOC_BASE_ADDRESS)

#define    APB2_GPIOD    ((GPIOx_Registers_t *)GPIOD_BASE_ADDRESS)

#define    APB2_GPIOE    ((GPIOx_Registers_t *)GPIOE_BASE_ADDRESS)

#define    APB2_GPIOF    ((GPIOx_Registers_t *)GPIOF_BASE_ADDRESS)

#define    APB2_GPIOG    ((GPIOx_Registers_t *)GPIOG_BASE_ADDRESS)



/* ======================================================== */  
/* ================== GPIO Private Macros ================= */
/* ======================================================== */



/* ======================================================== */  
/* ================= GPIO Private Functions =============== */
/* ======================================================== */



#endif    //_MCAL_GPIO_PRIVATE_H_
