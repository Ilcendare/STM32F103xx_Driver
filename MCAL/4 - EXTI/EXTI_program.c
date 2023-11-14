/*****************************************************************
****    File Name    :  EXTI_program.c                        ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  7 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the EXTI           ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



/** ======================================================== **/  
/** ================== EXTI Defined Macros ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= EXTI Global Variables ================ **/
/** ======================================================== **/



/** ======================================================== **/  
/** ============= EXTI Functions Implementation ============ **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_EXTI_enumMaskInterruptLine
	Arguments     : EXTI_Line_t Copy_enumEXTILine , u8 Copy_u8LineState
	Return type   : ErrorState_t (enum)
	Description   : Change the interrupt masking state of an EXTI line
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_EXTI_enumMaskInterruptLine    (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineState)
{
	ErrorState_t Local_enumState;
	
	if(Copy_enumEXTILine >= Line0 && Copy_enumEXTILine <= Line15)
	{
        if(Copy_u8LineState == EXTI_LINE_NOT_MASKED)
        {
            SET_BIT(APB2_EXTI->IMR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
        }
        else if(Copy_u8LineState == EXTI_LINE_MASKED)
        {
            CLR_BIT(APB2_EXTI->IMR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
        }
        else
        {
        	Local_enumState = EXTI_Error_UnavailableMaskState;
        }
	}
	else
	{
		Local_enumState = EXTI_Error_UnavailableEXTILine;
	}

	return Local_enumState;	
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_EXTI_enumMaskEventLine
	Arguments     : EXTI_Line_t Copy_enumEXTILine , u8 Copy_u8LineState
	Return type   : ErrorState_t (enum)
	Description   : Change the event masking state of an EXTI line
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_EXTI_enumMaskEventLine    (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineState)
{
	ErrorState_t Local_enumState;
	
	if(Copy_enumEXTILine >= Line0 && Copy_enumEXTILine <= Line15)
	{
        if(Copy_u8LineState == EXTI_LINE_NOT_MASKED)
        {
            SET_BIT(APB2_EXTI->EMR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
        }
        else if(Copy_u8LineState == EXTI_LINE_MASKED)
        {
            CLR_BIT(APB2_EXTI->EMR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
        }
        else
        {
        	Local_enumState = EXTI_Error_UnavailableMaskState;
        }
	}
	else
	{
		Local_enumState = EXTI_Error_UnavailableEXTILine;
	}

	return Local_enumState;	
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_EXTI_enumSetInterruptTrigger
	Arguments     : EXTI_Line_t Copy_enumEXTILine , u8 Copy_u8LineTrigger
	Return type   : ErrorState_t (enum)
	Description   : Set the line external interrupt request trigger (rising, falling, or both)
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_EXTI_enumSetInterruptTrigger    (EXTILine_t    Copy_enumEXTILine , u8    Copy_u8LineTrigger)
{
	ErrorState_t Local_enumState;
	
	if(Copy_enumEXTILine >= Line0 && Copy_enumEXTILine <= Line15)
	{
        if(Copy_u8LineTrigger == EXTI_LINE_TRIGGER_RISING)
		{
			SET_BIT(APB2_EXTI->RTSR , Copy_enumEXTILine);
			
			CLR_BIT(APB2_EXTI->FTSR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
		}
		else if(Copy_u8LineTrigger == EXTI_LINE_TRIGGER_FALLING)
		{
			SET_BIT(APB2_EXTI->FTSR , Copy_enumEXTILine);
			
			CLR_BIT(APB2_EXTI->RTSR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
		}
		else if(Copy_u8LineTrigger == EXTI_LINE_TRIGGER_LOGICAL_CHANGE)
		{
			SET_BIT(APB2_EXTI->RTSR , Copy_enumEXTILine);
			
			SET_BIT(APB2_EXTI->FTSR , Copy_enumEXTILine);
			
			Local_enumState = EXTI_OK;
		}
	    else
		{
			Local_enumState = EXTI_Error_NoReqTrigSelected;
		}
	}
	else
	{
		Local_enumState = EXTI_Error_UnavailableEXTILine;
	}

	return Local_enumState;	
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_EXTI_enumSetSWIE
	Arguments     : EXTI_Line_t Copy_enumEXTILine
	Return type   : ErrorState_t (enum)
	Description   : Trigger the external interrupt request on line X.
	
	NOTE:
	If the interrupt is enabled on this line in the EXTI_IMR, writing a '1' to this bit when it is set to
    '0' sets the corresponding pending bit in EXTI_PR resulting in an interrupt request
    generation.
    This bit is cleared by clearing the corresponding bit of EXTI_PR (by writing a 1 into the bit).
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_EXTI_enumSetSWIE    (EXTILine_t    Copy_enumEXTILine)
{
	ErrorState_t Local_enumState;
	
	if(Copy_enumEXTILine >= Line0 && Copy_enumEXTILine <= Line15)
	{
        SET_BIT(APB2_EXTI->SWIER , Copy_enumEXTILine);
		
		Local_enumState = EXTI_OK;
	}
	else
	{
		Local_enumState = EXTI_Error_UnavailableEXTILine;
	}

	return Local_enumState;	
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_EXTI_enumGetLineTriggerRequest
	Arguments     : EXTI_Line_t Copy_enumEXTILine , u8 * Ref_u8LineTriggerRequest
	Return type   : ErrorState_t (enum)
	Description   : Read the trigger request state of interrupt on line X.
	                if Ref_u8LineTriggerRequest = 0: No trigger request occurred
                    if Ref_u8LineTriggerRequest = 1: selected trigger request occurred
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_EXTI_enumGetLineTriggerRequest    (EXTILine_t    Copy_enumEXTILine , u8  * Ref_u8LineTriggerRequest)
{
	ErrorState_t Local_enumState;
	
	if(Copy_enumEXTILine >= Line0 && Copy_enumEXTILine <= Line15)
	{
        *Ref_u8LineTriggerRequest = GET_BIT(APB2_EXTI->PR , Copy_enumEXTILine);
		
		Local_enumState = EXTI_OK;
	}
	else
	{
		Local_enumState = EXTI_Error_UnavailableEXTILine;
	}

	return Local_enumState;	
}



/** ============================================== **/  
/** ========== EXTI ISRs Implementation ========== **/
/** ============================================== **/


