/*****************************************************************
****    File Name    :  STK_interface.h                       ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  7 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the STK            ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_STK_INTERFACE_H_
#define    _MCAL_STK_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



typedef struct {
	u8 STK_ClockSource;
	u8 STK_InterruptHandler;
} STK_InitConfig_t;



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */


/* These macros decides the Core Timer SysTick clock source */
/* These are to be written to the (STK_ClockSource) in a STK_InitConfig_t struct instance */
#define    STK_CLOCK_SOURCE_AHB          1
#define    STK_CLOCK_SOURCE_AHB_DIV_8    0


/* These macros decides the Core Timer SysTick interrupt handler */
/* These are to be written to the (STK_InterruptHandler) in a STK_InitConfig_t struct instance */
#define    STK_INTERRUPT_HANDLER_ENABLE     1
#define    STK_INTERRUPT_HANDLER_DISABLE    0



/* ======================================================== */  
/* ============== STK Functions declaration =============== */
/* ======================================================== */



ErrorState_t    MCAL_STK_enumInitSysTick             (STK_InitConfig_t  * Ref_structSTKInitConfig);

ErrorState_t    MCAL_STK_enumDeInitSysTick           (void);

ErrorState_t    MCAL_STK_enumSetBusyWait             (u32    Copy_u32Delay);

ErrorState_t    MCAL_STK_enumSetSingleAction         (u32    Copy_u32Delay , void (*Callback) (void));

ErrorState_t    MCAL_STK_enumSetPeriodicAction       (u32    Copy_u32Delay , void (*Callback) (void));

ErrorState_t    MCAL_STK_enumStopTimer               (void);

ErrorState_t    MCAL_STK_enumGetElapsedTime          (u32  * Ref_u32ElapsedTime);

ErrorState_t    MCAL_STK_enumGetRemainingTime        (u32  * Ref_u32RemainingTime);



#endif    //_MCAL_STK_INTERFACE_H_
