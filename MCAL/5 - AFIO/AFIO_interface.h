/*****************************************************************
****    File Name    :  AFIO_interface.h                      ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  8 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the AFIO           ****
                        functions declarations and user       ****
                        define macros and enumeration	      ****
*****************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_AFIO_INTERFACE_H_
#define    _MCAL_AFIO_INTERFACE_H_



/* ======================================================== */
/* ============== Configuration Struct Types ============== */
/* ======================================================== */



/* ======================================================== */
/* ============ User Interface Macros and Enums =========== */
/* ======================================================== */



/* These macros are used to decide which port to select for the EXTI_LINE_x */
/* These are to be written to (Copy_u8PORTx) */
#define    AFIO_EXTI_PORTA    0
#define    AFIO_EXTI_PORTB    1
#define    AFIO_EXTI_PORTC    2
#define    AFIO_EXTI_PORTD    3
#define    AFIO_EXTI_PORTE    4
#define    AFIO_EXTI_PORTF    5
#define    AFIO_EXTI_PORTG    6



/* These macrose decide which EXTI line is connected to the slected port */
/* These are to be written to (Copy_u8EXTIx) */
#define    AFIO_EXTI_LINE_0     0
#define    AFIO_EXTI_LINE_1     1
#define    AFIO_EXTI_LINE_2     2
#define    AFIO_EXTI_LINE_3     3
#define    AFIO_EXTI_LINE_4     4
#define    AFIO_EXTI_LINE_5     5
#define    AFIO_EXTI_LINE_6     6
#define    AFIO_EXTI_LINE_7     7
#define    AFIO_EXTI_LINE_8     8
#define    AFIO_EXTI_LINE_9     9
#define    AFIO_EXTI_LINE_10    10
#define    AFIO_EXTI_LINE_11    11
#define    AFIO_EXTI_LINE_12    12
#define    AFIO_EXTI_LINE_13    13
#define    AFIO_EXTI_LINE_14    14
#define    AFIO_EXTI_LINE_15    15



/* ======================================================== */  
/* ============== AFIO Functions declaration ============== */
/* ======================================================== */



ErrorState_t    MCAL_AFIO_enumConfigEXTIPin     (u8    Copy_u8EXTIx , u8    Copy_u8PORTx);

//ErrorState_t    MCAL_AFIO_enumConfigAFIO        (AFIO_t     Copy_enumAFIO              );

//ErrorState_t    MCAL_AFIO_enumConfigEVENTOUT    (u8    Copy_u8GPIOx , u8    Copy_u8PINx);

/** (MCAL_AFIO_enumConfigAFIO) and (MCAL_AFIO_enumConfigEVENTOUT) are kept For later... **/


#endif    //_MCAL_AFIO_INTERFACE_H_
