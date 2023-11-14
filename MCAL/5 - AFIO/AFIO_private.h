/*******************************************************************
****    File Name    :  AFIO_program.c                          ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  8 Nov 2023                      ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the AFIO's           ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_AFIO_PRIVATE_H_ 
#define    _MCAL_AFIO_PRIVATE_H_ 



/* ======================================================== */  
/* ================ AFIO Registers Bitfield =============== */
/* ======================================================== */



/* ======================================================== */  
/* =============== AFIO Registers Definition ============== */
/* ======================================================== */



typedef struct {
    u32 EVCR;
    u32 MAPR;
    u32 EXTICR[4];
    u32 MAPR2;
} AFIO_Register_t;

#define    AFIO_BASE_ADDRESS    0x40010000

#define    APB2_AFIO    ((AFIO_Register_t *)AFIO_BASE_ADDRESS)



/* ======================================================== */  
/* ================== AFIO Private Macros ================= */
/* ======================================================== */



/* ======================================================== */  
/* ================= AFIO Private Functions =============== */
/* ======================================================== */



#endif    //_MCAL_AFIO_PRIVATE_H_
#endif    //_MCAL_AFIO_PRIVATE_H_