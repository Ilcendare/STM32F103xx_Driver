/*****************************************************************
****    File Name    :  CAN_interface.h                       ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  11 Nov 2023                           ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the CAN            ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_CAN_INTERFACE_H_
#define    _MCAL_CAN_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */



/* ======================================================== */  
/* ============== CAN Functions declaration =============== */
/* ======================================================== */



void    MCAL_CAN_voidInit();

void    MCAL_CAN_voidTransmit(u8 Ref_u8arrTransmittedData[] , u8 Copy_u8DLC);

void    MCAL_CAN_voidRecieve(u8 Ref_u8arrReceivedData[] , u8 Copy_u8DLC);




#endif    //_MCAL_CAN_INTERFACE_H_
