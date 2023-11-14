/*****************************************************************
****    File Name    :  EXTI_interface.h                      ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  7 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the EXTI           ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_EXTI_INTERFACE_H_
#define    _MCAL_EXTI_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */


/* Define the EXTI Lines availabe on Ports A, B, and C for STM32F103xx */
typedef enum {
	Line0,
	Line1,
	Line2,
	Line3,
	Line4,
	Line5,
	Line6,
	Line7,
	Line8,
	Line9,
	Line10,
	Line11,
	Line12,
	Line13,
	Line14,
	Line15,
} EXTILine_t;


/* These macros decide he masking state of an EXTI line. These are to be written to (Copy_u8LineState). */
#define    EXTI_LINE_NOT_MASKED    1
#define    EXTI_LINE_MASKED        2


/* These macros are used to choose the EXTI line trigger */
#define    EXTI_LINE_TRIGGER_RISING            1
#define    EXTI_LINE_TRIGGER_FALLING           2
#define    EXTI_LINE_TRIGGER_LOGICAL_CHANGE    3



/* ======================================================== */  
/* ============== EXTI Functions declaration ============== */
/* ======================================================== */



ErrorState_t    MCAL_EXTI_enumMaskInterruptLine         (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineState);

ErrorState_t    MCAL_EXTI_enumMaskEventLine             (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineState);

ErrorState_t    MCAL_EXTI_enumSetInterruptTrigger       (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineTrigger);

ErrorState_t    MCAL_EXTI_enumSetSWIE                   (EXTILine_t    Copy_enumEXTILine);

ErrorState_t    MCAL_EXTI_enumGetLineTriggerRequest     (EXTILine_t    Copy_enumEXTILine , u8  * Ref_u8LineTriggerRequest);



#endif    //_MCAL_EXTI_INTERFACE_H_
