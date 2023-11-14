/*****************************************************************
****    File Name    :  STK_program.c                         ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  7 Nov 2023                            ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the STK            ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"



/** ======================================================== **/  
/** ================== STK Defined Macros ================== **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= STK Global Variables ================= **/
/** ======================================================== **/



void (* SysTickHandler_Callback)(void);
u8    Global_u8PeriodicAction;



/** ======================================================== **/  
/** ============= STK Functions Implementation ============= **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumInitSysTick
	Arguments     : STK_InitConfig_t * Ref_structSTKInitConfig
	Return type   : ErrorState_t (enum)
	Description   : Initialize the core timer SysTick
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_STK_enumInitSysTick    (STK_InitConfig_t  * Ref_structSTKInitConfig)
{
	ErrorState_t Local_enumState;
	
	if(Ref_structSTKInitConfig != NULL)
	{
		if(Ref_structSTKInitConfig->STK_ClockSource < 2)
		{
			if(Ref_structSTKInitConfig->STK_InterruptHandler < 2)
		    {
				CORE_STK->CTRL.Bit.CLKSOURCE = Ref_structSTKInitConfig->STK_ClockSource;

			    CORE_STK->CTRL.Bit.TICKINT = Ref_structSTKInitConfig->STK_InterruptHandler;

			    //CORE_STK->CTRL.Bit.ENABLE = 1;

				Local_enumState = STK_OK;
		    }
		    else
		    {
			    Local_enumState = STK_Error_InitConfigInterruptHandler;
		    }
		}
		else
		{
			Local_enumState = STK_Error_InitConfigClockSource;
		}
	}
	else
	{
		Local_enumState = STK_Error_NULLStruct;
	}
	
	return Local_enumState;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumDeInitSysTick
	Arguments     : void
	Return type   : ErrorState_t (enum)
	Description   : Deinitialize and stop the the core timer SysTick
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_STK_enumDeInitSysTick    (void)
{
	CORE_STK->CTRL.Bit.ENABLE = 0;

	CORE_STK->LOAD = 0;

	CORE_STK->VAL = 0;
	
	return STK_OK;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumSetBusyWait
	Arguments     : u32 Copy_u32Delay
	Return type   : ErrorState_t (enum)
	Description   : Set a busy wait with a delay.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



ErrorState_t    MCAL_STK_enumSetBusyWait    (u32    Copy_u32Delay)
{
	if(CORE_STK->CTRL.Bit.TICKINT == 1)
	{
		CORE_STK->CTRL.Bit.TICKINT = 0;
		
		CORE_STK->LOAD = (Copy_u32Delay & 0x00FFFFFF);
		
		CORE_STK->CTRL.Bit.ENABLE = 1;

		while((CORE_STK->CTRL.Bit.COUNTFLAG) == 0);
		
		CORE_STK->CTRL.Bit.ENABLE = 0;

		CORE_STK->LOAD = 0;

		CORE_STK->VAL = 0;
		
		CORE_STK->CTRL.Bit.TICKINT = 1;
	}
	else
	{
		CORE_STK->LOAD = (Copy_u32Delay & 0x00FFFFFF);
		
		CORE_STK->CTRL.Bit.ENABLE = 1;

		while(!(CORE_STK->CTRL.Bit.COUNTFLAG));

		CORE_STK->CTRL.Bit.ENABLE = 0;

		CORE_STK->LOAD = 0;

		CORE_STK->VAL = 0;
	}
	
	return STK_OK;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumSetSingleAction
	Arguments     : u32 Copy_u32Delay , void (*Callback) (void)
	Return type   : ErrorState_t (enum)
	Description   : Set a single interval action with a delay.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	

	
ErrorState_t    MCAL_STK_enumSetSingleAction    (u32    Copy_u32Delay , void (*Callback) (void))
{
	ErrorState_t Local_enumState;
	
	if(CORE_STK->CTRL.Bit.TICKINT == 1)
	{
		if(Callback != NULL)
		{
			SysTickHandler_Callback = Callback;
			
			Global_u8PeriodicAction = 0;

			CORE_STK->LOAD = Copy_u32Delay;
		
			CORE_STK->CTRL.Bit.ENABLE = 1;

		    Local_enumState = STK_OK;
		}
		else
		{
			Local_enumState = STK_Error_NULLCallback;
		}
	}
	else
	{
		Local_enumState = STK_Error_InterruptHandlerDisabled;
	}
	
	return Local_enumState;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumSetPeriodicAction
	Arguments     : u32 Copy_u32Delay , void (*Callback) (void)
	Return type   : ErrorState_t (enum)
	Description   : Set a periodic interval action with a delay.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_STK_enumSetPeriodicAction    (u32    Copy_u32Delay , void (*Callback) (void))
{
	ErrorState_t Local_enumState;
	
	if(CORE_STK->CTRL.Bit.TICKINT == 1)
	{
		if(Callback != NULL)
		{
			SysTickHandler_Callback = Callback;
			
			Global_u8PeriodicAction = 1;

			CORE_STK->LOAD = Copy_u32Delay;

			CORE_STK->CTRL.Bit.ENABLE = 1;
		
		    Local_enumState = STK_OK;
		}
		else
		{
			Local_enumState = STK_Error_NULLCallback;
		}
	}
	else
	{
		Local_enumState = STK_Error_InterruptHandlerDisabled;
	}
	
	return Local_enumState;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumStopTimer
	Arguments     : void
	Return type   : ErrorState_t (enum)
	Description   : Stop the SysTick Timer
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_STK_enumStopTimer    (void)
{
	CORE_STK->CTRL.Bit.ENABLE = 0;

	CORE_STK->LOAD = 0;
	
	CORE_STK->VAL = 0;
	
	return STK_OK;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumGetElapsedTime
	Arguments     : u32 * Ref_u32ElapsedTime
	Return type   : ErrorState_t (enum)
	Description   : Get the elapsed time since the last underflow
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_STK_enumGetElapsedTime    (u32  * Ref_u32ElapsedTime)
{
	*Ref_u32ElapsedTime = (CORE_STK->LOAD) - (CORE_STK->VAL);
	
	return STK_OK;
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_STK_enumGetRemainingTime
	Arguments     : u32 * Ref_u32RemainingTime
	Return type   : ErrorState_t (enum)
	Description   : Get the remaining time to get to the next underflow
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
ErrorState_t    MCAL_STK_enumGetRemainingTime    (u32  * Ref_u32RemainingTime)
{
	*Ref_u32RemainingTime = CORE_STK->VAL;
	
	return STK_OK;
}

	
	
/** ============================================== **/  
/** =========== STK ISRs Implementation ========== **/
/** ============================================== **/



void SysTick_Handler(void)
{
	if(SysTickHandler_Callback != NULL)
	{
		if(Global_u8PeriodicAction == 0)    // Single Action
		{
			CORE_STK->CTRL.Bit.ENABLE = 0;

			CORE_STK->LOAD = 0;
			
			CORE_STK->VAL = 0;
			
			SysTickHandler_Callback();
		}
		else                                // Periodic Action
		{
			SysTickHandler_Callback();
		}
	}
}
