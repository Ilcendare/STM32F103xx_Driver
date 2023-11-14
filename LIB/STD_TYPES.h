/***********************************************************
****    File Name    :  STD_TYPES.h                     ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  31 Oct 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  This file contains the          **** 
****                    standard data types.            ****
***********************************************************/



/* ============================================== */  
/* ============= File Header Guard ============== */
/* ============================================== */



#ifndef    _LIB_STD_TYPES_H_
#define    _LIB_STD_TYPES_H_



/* ============================================== */  
/* =============== Standard Types =============== */
/* ============================================== */



typedef    unsigned char             u8;
typedef    unsigned short int        u16;
typedef    unsigned long int         u32;
typedef    unsigned long long int    u64;

typedef    signed char               s8;
typedef    signed short int          s16;
typedef    signed long int           s32;
typedef    signed long long int      s64;

typedef    float            f32;
typedef    double           f64;

#define    NULL    (void *)0



/* ============================================== */  
/* ================= Error Types ================ */
/* ============================================== */



typedef enum {
	RCC_OK,
	RCC_Error_NULLStruct,
	RCC_Error_UndefinedPeripheralID,
	
	GPIO_OK,
	GPIO_Error_UndefinedGPIOx,
	GPIO_Error_UndefinedPinNumber,
	GPIO_Error_UndefinedPinState,
	
	NVIC_OK,
	NVIC_Error_UndefinedIRQ,
	
	SCB_OK,
	SCB_Error_WrongVECTKEY,
	SCB_Error_UndefinedGrouping,
	
	EXTI_OK,
	EXTI_Error_UnavailableEXTILine,
	EXTI_Error_UnavailableMaskState,
	EXTI_Error_NoReqTrigSelected,
	
	STK_OK,
	STK_Error_NULLStruct,
	STK_Error_InitConfigClockSource,
	STK_Error_InitConfigInterruptHandler,
	STK_Error_InterruptHandlerDisabled,
	STK_Error_NULLCallback,
	
	AFIO_OK,
	AFIO_Error_UnavailablePort,
	AFIO_Error_UnavailableEXTILine
} ErrorState_t;



#endif    //_LIB_STD_TYPES_H_
