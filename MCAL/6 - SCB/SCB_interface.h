/*****************************************************************
****    File Name    :  SCB_interface.h                       ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  6 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the SCB's          ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_SCB_INTERFACE_H_
#define    _MCAL_SCB_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */



#define    GROUP_PRIORITY_16_SUB_PRIORITY_NONE    0b011
#define    GROUP_PRIORITY_8_SUB_PRIORITY_2        0b100
#define    GROUP_PRIORITY_4_SUB_PRIORITY_4        0b101
#define    GROUP_PRIORITY_2_SUB_PRIORITY_8        0b110
#define    GROUP_PRIORITY_NONE_SUB_PRIORITY_16    0b111



/* ======================================================== */  
/* ============== SCB Functions declaration =============== */
/* ======================================================== */



ErrorState_t    MCAL_SCB_enumSetPriorityGrouping    (u8 Copy_u8VECTKEY, u8 Copy_u8GroupingConfig);



#endif    //_MCAL_SCB_INTERFACE_H_
