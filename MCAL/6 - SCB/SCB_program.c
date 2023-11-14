/*****************************************************************
****    File Name    :  SCB_program.c                         ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  6 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the SCB            ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"



/** ======================================================== **/  
/** ================== SCB Defined Macros ================== **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= SCB Global Variables ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ============= SCB Functions Implementation ============= **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_SCB_enumSetPriorityGrouping
	Arguments     : u8 Copy_u8VECTKEY, u8 Copy_u8GroupingConfig
	Return type   : ErrorState_t (enum)
	Description   : Configure the number of priority groups(preemtive)/sub-groups. 
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_SCB_enumSetPriorityGrouping    (u8 Copy_u8VECTKEY, u8 Copy_u8GroupingConfig)
{
	ErrorState_t Local_enumStatus;
	
	if(Copy_u8VECTKEY == 0x5FA)
	{
		if(Copy_u8GroupingConfig >= 3 && Copy_u8GroupingConfig <= 7)
	    {
			CORE_SCB->AIRCR.Bit.VECTKEY = Copy_u8VECTKEY;
			
	    	CORE_SCB->AIRCR.Bit.PRIGROUP = Copy_u8GroupingConfig;
	    	
	    	Local_enumStatus = SCB_OK;
	    }
	    else
	    {
	    	Local_enumStatus = SCB_Error_UndefinedGrouping;
	    }
	}
	else
	{
		Local_enumStatus = SCB_Error_WrongVECTKEY;
	}
	
	return Local_enumStatus;
}



/** ============================================== **/  
/** =========== SCB ISRs Implementation ========== **/
/** ============================================== **/


