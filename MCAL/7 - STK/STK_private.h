/*******************************************************************
****    File Name    :  STK_program.c                           ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  7 Nov 2023                              ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the STK's            ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_STK_PRIVATE_H_ 
#define    _MCAL_STK_PRIVATE_H_ 



/* ======================================================== */  
/* ================ STK Registers Bitfield ================ */
/* ======================================================== */



typedef union {
	struct {
        volatile u32 ENABLE    :  1;
		volatile u32 TICKINT   :  1;
		volatile u32 CLKSOURCE :  1;
		volatile u32           : 13;
		volatile u32 COUNTFLAG :  1;
		volatile u32           : 15;
	} Bit;
	
	volatile u32 Word;
	
} CTRL_t;



/* ======================================================== */  
/* =============== STK Registers Definition =============== */
/* ======================================================== */



typedef struct {
	volatile CTRL_t CTRL;
    volatile u32    LOAD;
    volatile u32    VAL;
    volatile u32    CALIB;
} STK_Register_t;


#define    STK_BASE_ADDRESS    0xE000E010

#define    CORE_STK    ((STK_Register_t *) STK_BASE_ADDRESS)



/* ======================================================== */  
/* ================== STK Private Macros ================== */
/* ======================================================== */



/* ======================================================== */  
/* ================= STK Private Functions ================ */
/* ======================================================== */



#endif    //_MCAL_STK_PRIVATE_H_
