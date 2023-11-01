/***********************************************************
****    File Name    :  BIT_MATH.h                      ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  31 Oct 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  This file contains the          **** 
****                    essential functions for the     ****
****					bitwise operations.             ****
***********************************************************/



/* ============================================== */  
/* ============= File Header Guard ============== */
/* ============================================== */



#ifndef    _LIB_BIT_MATH_H_
#define    _LIB_BIT_MATH_H_



/* ============================================== */  
/* ============= Bitwise Functions ============== */
/* ============================================== */



#define    SET_BIT(REG,BIT)       (REG) |=  (1 << (BIT))
#define    CLR_BIT(REG,BIT)       (REG) &= ~(1 << (BIT))
#define    TOGGLE_BIT(REG,BIT)    (REG) ^=  (1 << (BIT))
#define    GET_BIT(REG,BIT)       (1) & ((REG) >> (BIT))

#define    SET_WORD(REG,VAL)      (REG) |= (VAL)
#define    WRITE_WORD(REG,VAL)    (REG)  = (VAL)



#endif    //_LIB_BIT_MATH_H_
