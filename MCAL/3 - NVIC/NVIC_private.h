/*******************************************************************
****    File Name    :  NVIC_program.c                          ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  6 Nov 2023                              ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the NVIC's           ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_NVIC_PRIVATE_H_ 
#define    _MCAL_NVIC_PRIVATE_H_ 



/* ======================================================== */  
/* ================ NVIC Registers Bitfield =============== */
/* ======================================================== */



/* ======================================================== */  
/* =============== NVIC Registers Definition ============== */
/* ======================================================== */


typedef struct {
    volatile u32 ISER[20];
    volatile u32 ICER[20];
    volatile u32 ISPR[20];
    volatile u32 ICPR[20];
    volatile u32 IABR[20];
    volatile u32 IPR[20];
    volatile u32 STIR;
} NVIC_Register_t;

#define    NVIC_BASE_ADDRESS    0xE000E100

#define    CORE_NVIC    ((NVIC_Register_t *) NVIC_BASE_ADDRESS)



/* ======================================================== */  
/* ================== NVIC Private Macros ================= */
/* ======================================================== */



/* ======================================================== */  
/* ================= NVIC Private Functions =============== */
/* ======================================================== */



#endif    //_MCAL_NVIC_PRIVATE_H_
