/*******************************************************************
****    File Name    :  EXTI_program.c                          ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  7 Nov 2023                              ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the EXTI             ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_EXTI_PRIVATE_H_ 
#define    _MCAL_EXTI_PRIVATE_H_ 



/* ======================================================== */  
/* ================ EXTI Registers Bitfield =============== */
/* ======================================================== */



/* ======================================================== */  
/* =============== EXTI Registers Definition ============== */
/* ======================================================== */



typedef struct {
	u32 IMR;
    u32 EMR;
    u32 RTSR;
    u32 FTSR;
    u32 SWIER;
    u32 PR;
} EXTI_Register_t;

#define    EXTI_BASE_ADDRESS    0x40010400

#define    APB2_EXTI    ((EXTI_Register_t *) EXTI_BASE_ADDRESS)



/* ======================================================== */  
/* ================== EXTI Private Macros ================= */
/* ======================================================== */



/* ======================================================== */  
/* ================= EXTI Private Functions =============== */
/* ======================================================== */



#endif    //_MCAL_EXTI_PRIVATE_H_
