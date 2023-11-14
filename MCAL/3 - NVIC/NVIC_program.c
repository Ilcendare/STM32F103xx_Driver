/*****************************************************************
****    File Name    :  NVIC_program.c                        ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  6 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the NVIC           ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



/** ======================================================== **/  
/** ================== NVIC Defined Macros ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= NVIC Global Variables ================ **/
/** ======================================================== **/



/** ======================================================== **/  
/** ============= NVIC Functions Implementation ============ **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_NVIC_enumSetIRQx
	Arguments     : IRQx_t Copy_enumIRQx
	Return type   : ErrorState_t (enum)
	Description   : Enable an interrupt request 
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumSetIRQx    (IRQx_t Copy_enumIRQx)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    CORE_NVIC->ISER[Local_u8Register] = (1 << Local_u8Index);
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_NVIC_enumClearIRQx
	Arguments     : IRQx_t Copy_enumIRQx
	Return type   : ErrorState_t (enum)
	Description   : Disable an interrupt request
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumClearIRQx    (IRQx_t Copy_enumIRQx)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    CORE_NVIC->ICER[Local_u8Register] = (1 << Local_u8Index);
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_NVIC_enumGetIRQxState
	Arguments     : IRQx_t Copy_enumIRQx , u8 * Ref_u8IRQxStatus
	Return type   : ErrorState_t (enum)
	Description   : Check an interrupt request's state (enabled or disabled)
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumGetIRQxState    (IRQx_t Copy_enumIRQx , u8 * Ref_u8IRQxStatus)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    *Ref_u8IRQxStatus = GET_BIT(CORE_NVIC->ISER[Local_u8Register] , (1 << Local_u8Index));
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_NVIC_enumSetIRQxPendingFlag
	Arguments     : IRQx_t Copy_enumIRQx
	Return type   : ErrorState_t (enum)
	Description   : Set an interrupt request pending flag
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumSetIRQxPendingFlag    (IRQx_t Copy_enumIRQx)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    CORE_NVIC->ISPR[Local_u8Register] = (1 << Local_u8Index);
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name: MCAL_NVIC_enumClearIRQxPendingFlag
	Arguments    : IRQx_t Copy_enumIRQx
	Return type  : ErrorState_t (enum)
	Description  : Clear an interrupt request pending flag
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumClearIRQxPendingFlag    (IRQx_t Copy_enumIRQx)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    CORE_NVIC->ICPR[Local_u8Register] = (1 << Local_u8Index);
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}

    return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name: MCAL_NVIC_enumGetIRQxPendingFlag
	Arguments    : IRQx_t Copy_enumIRQx , u8 * Ref_u8PendingFlagStatus
	Return type  : ErrorState_t (enum)
	Description  : Read an interrupt request pending flag
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumGetIRQxPendingFlag    (IRQx_t Copy_enumIRQx , u8 * Ref_u8PendingFlagStatus)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    *Ref_u8PendingFlagStatus = GET_BIT(CORE_NVIC->ISPR[Local_u8Register] , (1 << Local_u8Index));
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name: MCAL_NVIC_enumGetIRQxActiveFlag
	Arguments    : IRQx_t Copy_enumIRQx , u8 * Ref_u8ActiveFlagStatus
	Return type  : ErrorState_t (enum)
	Description  : Read an interrupt request active flag
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumGetIRQxActiveFlag    (IRQx_t Copy_enumIRQx , u8 * Ref_u8ActiveFlagStatus)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 32;
	
        u8 Local_u8Index = Copy_enumIRQx - (Local_u8Register * 32);
	
	    *Ref_u8ActiveFlagStatus = GET_BIT(CORE_NVIC->IABR[Local_u8Register] , (1 << Local_u8Index));
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name: MCAL_NVIC_enumSetIRQxPriority
    Arguments    : IRQx_t Copy_enumIRQx , u8 Copy_u8Priority
    Return type  : ErrorState_t (enum)
    Description  : Set an interrupt request priority
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_NVIC_enumSetIRQxPriority    (IRQx_t Copy_enumIRQx , u8 Copy_u8Priority)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		u8 Local_u8Register = Copy_enumIRQx / 4;
	
	    u8 Local_u8Offset   = Copy_enumIRQx % 4;
	
	    CORE_NVIC->IPR[Local_u8Register] &= ~(0x11 << (Local_u8Offset * 8));
	
	    CORE_NVIC->IPR[Local_u8Register] |=  (Copy_u8Priority << (Local_u8Offset * 8));
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name: MCAL_NVIC_enumGenerateSWI
    Arguments    : IRQx_t Copy_enumIRQx
    Return type  : ErrorState_t (enum)
    Description  : Generate a software generated interrupt. The value to be written is
    the Interrupt ID of the required SGI in the range 0-239. For example, a value of 0b000000011
    specifies interrupt IRQ3.
	
	NOTE: 
	When the USERSETMPEND bit in the SCR is set to 1, unprivileged software can access the STIR. 
	Only privileged software can enable unprivileged access to the STIR.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_NVIC_enumGenerateSWI    (IRQx_t Copy_enumIRQx)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_enumIRQx >= WWDG && Copy_enumIRQx <= DMA2_Channel4_5)
	{
		CORE_NVIC->STIR = Copy_enumIRQx;
		
		Local_enumStatus = NVIC_OK;
	}
	else
	{
		Local_enumStatus = NVIC_Error_UndefinedIRQ;
	}
	
	return Local_enumStatus;
}



/** ============================================== **/  
/** ======== Component ISRs Implementation ======= **/
/** ============================================== **/


