/************************************************************
****    File Name    :  GPIO_program.c                   ****
****    Author       :  Eng. Mahmoud Sayed               ****
****    Date         :  5 Nov 2023                       ****
****    Version      :  V 1.0                            ****
****    Description  :  This file contains the GPIO's    ****
                        function implementation          ****
************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



/** ======================================================== **/  
/** ================== GPIO Defined Macros ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= GPIO Global Variables ================ **/
/** ======================================================== **/



volatile GPIOx_Registers_t * Global_structGPIO[] = {
	APB2_GPIOA,
	APB2_GPIOB,
	APB2_GPIOC
};



/** ======================================================== **/  
/** ============= GPIO Functions Implementation ============ **/
/** ======================================================== **/



/* >>>>>>>>>>>>>>> Set Pin Mode Function <<<<<<<<<<<<<<< */



ErrorState_t    MCAL_GPIO_enumSetPinMode(GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, u32  Copy_u8Mode)
{
	ErrorState_t Local_enumStatus;
	
	
	if(Copy_enumGPIOx <= GPIOC)
	{
		if(Copy_enumPin <= PIN7)
		{
			Global_structGPIO[Copy_enumGPIOx]->CRL.Word &= ~(0b1111      << (4 * Copy_enumPin));
			
			Global_structGPIO[Copy_enumGPIOx]->CRL.Word |=  (Copy_u8Mode << (4 * Copy_enumPin));
			
			Local_enumStatus = GPIO_OK;
		}
		
		else if(Copy_enumPin <= PIN15)
		{
			Global_structGPIO[Copy_enumGPIOx]->CRH.Word &= ~(0b1111      << (4 * (Copy_enumPin - 8)));
			
			Global_structGPIO[Copy_enumGPIOx]->CRH.Word |=  (Copy_u8Mode << (4 * (Copy_enumPin - 8)));
			
			Local_enumStatus = GPIO_OK;
		}
		
		else
		{
			Local_enumStatus = GPIO_Error_UndefinedPinNumber;
		}
	}
	
	else
	{
		Local_enumStatus = GPIO_Error_UndefinedGPIOx;
	}
	
	
	return Local_enumStatus;
}



/* >>>>>>>>>>>>>>> Write to Pin Function <<<<<<<<<<<<<<< */



ErrorState_t    MCAL_GPIO_enumWritePin(GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, PinState_t  Copy_enumState)
{
	ErrorState_t Local_enumStatus;
	
	
	if(Copy_enumGPIOx <= GPIOC)
	{
		if(Copy_enumPin <= PIN15)
		{
			if(Copy_enumState == High)
			{
				SET_BIT(Global_structGPIO[Copy_enumGPIOx]->ODR.Word,Copy_enumPin);
				
				Local_enumStatus = GPIO_OK;
			}
			
			else if(Copy_enumState == Low)
			{
				CLR_BIT(Global_structGPIO[Copy_enumGPIOx]->ODR.Word,Copy_enumPin);
				
				Local_enumStatus = GPIO_OK;
			}
			
			else
			{
				Local_enumStatus = GPIO_Error_UndefinedPinState;
			}
		}
		
		else
		{
			Local_enumStatus = GPIO_Error_UndefinedPinNumber;
		}
	}
	
	else
	{
		Local_enumStatus = GPIO_Error_UndefinedGPIOx;
	}
	
	
	return Local_enumStatus;
}



/* >>>>>>>>>>>>>>> Read from Pin Function <<<<<<<<<<<<<<< */



ErrorState_t    MCAL_GPIO_enumReadPin(GPIOx_t  Copy_enumGPIOx, PINn_t  Copy_enumPin, PinState_t *Ref_u8State)
{
	ErrorState_t Local_enumStatus;
	
	
	if(Copy_enumGPIOx <= GPIOC)
	{
		if(Copy_enumPin <= PIN15)
		{
			*Ref_u8State = GET_BIT(Global_structGPIO[Copy_enumGPIOx]->IDR.Word,Copy_enumPin);
			
			Local_enumStatus = GPIO_OK;
		}
		
		else
		{
			Local_enumStatus = GPIO_Error_UndefinedPinNumber;
		}
	}
	
	else
	{
		Local_enumStatus = GPIO_Error_UndefinedGPIOx;
	}
	
	
	return Local_enumStatus;
}



/** ======================================================== **/  
/** =============== GPIO ISRs Implementation =============== **/
/** ======================================================== **/


