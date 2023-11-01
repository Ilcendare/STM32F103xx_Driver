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



/* ============================================== */  
/* ================= Error Types ================ */
/* ============================================== */



typedef enum {
	RCC_OK,
	RCC_Error_Peripheral_ID
} ErrorState_t;



#endif    //_LIB_STD_TYPES_H_
