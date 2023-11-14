/*****************************************************************
****    File Name    :  AFIO_program.c                        ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  8 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the AFIO           ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



/** ======================================================== **/  
/** ================== AFIO Defined Macros ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= AFIO Global Variables ================ **/
/** ======================================================== **/



/** ======================================================== **/  
/** ============= AFIO Functions Implementation ============ **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_AFIO_enumConfigEXTIPin
	Arguments     : u8 Copy_u8EXTIx , u8 Copy_u8PORTx
	Return type   : ErrorState_t (enum)
	Description   : Connect the EXTI Line to its didicated pin on the selected port.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_AFIO_enumConfigEXTIPin    (u8 Copy_u8EXTIx , u8 Copy_u8PORTx)
{
	ErrorState_t Local_u8State;
	
	if(Copy_u8EXTIx <= AFIO_EXTI_LINE_15)
	{
		if(Copy_u8PORTx <= AFIO_EXTI_PORTG)
		{
			u8 Local_u8Index = (Copy_u8EXTIx / 4);
			
			u8 Local_u8EXTIx = (Copy_u8EXTIx % 4);
			
			APB2_AFIO->EXTICR[Local_u8Index] |= (Copy_u8PORTx << (Local_u8EXTIx * 4));
			
			Local_u8State = AFIO_OK;
		}
		else
		{
			Local_u8State = AFIO_Error_UnavailablePort;
		}
	}
	else
	{
		Local_u8State = AFIO_Error_UnavailableEXTILine;
	}
	
	return Local_u8State;
}



/** ============================================== **/  
/** =========== AFIO ISRs Implementation ========= **/
/** ============================================== **/


