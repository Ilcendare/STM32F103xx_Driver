/*******************************************************************
****    File Name    :  SCB_program.c                           ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  6 Nov 2023                              ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the SCB's            ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_SCB_PRIVATE_H_ 
#define    _MCAL_SCB_PRIVATE_H_ 



/* ======================================================== */  
/* ================ SCB Registers Bitfield ========== */
/* ======================================================== */



typedef union {
	struct {
	    u32 VECTRESET     : 1;    // Reserved
		u32 VECTCLRACTIVE : 1;    // Reserved
		u32 SYSRESETREQ   : 1;
		u32               : 5;    // Reserved
	    u32 PRIGROUP      : 3;
		u32               : 4;    // Reserved
		u32 ENDIANESS     : 1;    // Reserved
		u32 VECTKEY       :16;
	} Bit;
	
	u32 Word;
	
} AIRCR_t;



/* ======================================================== */  
/* =============== SCB Registers Definition ========= */
/* ======================================================== */



typedef struct {
    volatile u32 ACTLR;
	volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile AIRCR_t AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCRS;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 MMAR;
    volatile u32 BFAR;
} SCB_Register_t;

#define    SCB_ADDRESS_BASE    0xE000ED00

#define    CORE_SCB    ((SCB_Register_t *) SCB_ADDRESS_BASE)



/* ======================================================== */  
/* ================== SCB Private Macros ============ */
/* ======================================================== */



/* ======================================================== */  
/* ================= SCB Private Functions ========== */
/* ======================================================== */



#endif    //_MCAL_SCB_PRIVATE_H_
