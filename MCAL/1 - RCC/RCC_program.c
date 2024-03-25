/***********************************************************
****    File Name    :  RCC_program.c                   ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  16 Dec 2023                     ****
****    Version      :  V 2.0                           ****
****    Description  :  This file contains the RCC      ****
                        function implementation         ****
***********************************************************/



/** ======================================================== **/
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



/** ======================================================== **/
/** ================== RCC Defined Macros ================== **/
/** ======================================================== **/



/** ======================================================== **/
/** ================= RCC Global Variables ================= **/
/** ======================================================== **/



/** ======================================================== **/
/** ============= RCC Functions Implementation ============= **/
/** ======================================================== **/



/** >>>>>>>>>>>>>>> RCC Initialization Function <<<<<<<<<<<<<<< **/



ErrorState_t MCAL_RCC_voidInitSystemClock (RCC_InitConfig_t * RCC_InitConfig)
{
	ErrorState_t Local_enumState;
	
	if(RCC_InitConfig != NULL)
	{
		/* Reset all RCC registers */
		AHB_RCC->CR.Word      = 0x00000000U;
	    AHB_RCC->CFGR.Word    = 0x00000000U;
	    AHB_RCC->AHBENR.Word  = 0x00000014U;
	    AHB_RCC->APB1ENR.Word = 0x00000000U;
	    AHB_RCC->APB2ENR.Word = 0x00000000U;
	    
	    /* Define the RCC timeout counter variable */
        u32 RCC_TIMEOUT_COUNTER = 0;
	    
        
        /** Configure the AHB, APB1, and APB2 prescalers **/
        AHB_RCC->CFGR.Bit.HPRE  = RCC_InitConfig->AHB_Prescaler  ;
        AHB_RCC->CFGR.Bit.PPRE1 = RCC_InitConfig->APB1_Prescaler ;
        AHB_RCC->CFGR.Bit.PPRE2 = RCC_InitConfig->APB2_Prescaler ;
        
        
        /** Configure the clock source selected **/
        switch(RCC_InitConfig->Clock_Source)
        {
        case RCC_HSI_CLOCK_SORCE:    // If the HSI clock source is selected
            
            
            /* Configure the HSI trimming value */
            AHB_RCC->CR.Bit.HSITRIM = RCC_InitConfig->HSI_Trim_Value;
            
            
            /* Enable the HSI clock source */
            AHB_RCC->CR.Bit.HSION = 1;
            
            
		    /* Wait for the HSI clock source to be ready */
            while((AHB_RCC->CR.Bit.HSIRDY == 0) && (RCC_TIMEOUT_COUNTER < MAX_TIMEOUT_DELAY))
            {
            	RCC_TIMEOUT_COUNTER++;
            }


			/* Check if a timeout has occured */
            if(RCC_TIMEOUT_COUNTER == MAX_TIMEOUT_DELAY)
			{
				Local_enumState = RCC_Error_Timeout;
				break;
			}
			

			/* Select the HSI as the system clock */
			AHB_RCC->CFGR.Bit.SW = RCC_SYSTEM_CLOCK_HSI;
            break;
			
			
            // ----------------------------------------------------------------------- //
            
            
        case RCC_HSE_CLOCK_SORCE:    // If the HSE clock source is selected
            
            
        	/* Enable the HSE clock source */
			AHB_RCC->CR.Bit.HSEON = 1;


            /* Configure the HSE oscillator */
            switch(RCC_InitConfig->HSE_Oscillator)
            {
            	case RCC_HSE_CRYSTAL_OSCILLATOR:    AHB_RCC->CR.Bit.HSEBYP = 0;    break;
            	case RCC_HSE_RC_OSCILLATOR:         AHB_RCC->CR.Bit.HSEBYP = 1;    break;
            	default:
            	
            }
            
            
            /* Configure the clock security system */
            switch(RCC_InitConfig->Clock_Security_System)
            {
            	case RCC_CSS_ON:     AHB_RCC->CR.Bit.CSS = 1;    break;
            	case RCC_CSS_OFF:    AHB_RCC->CR.Bit.CSS = 0;    break;
            	default:
            	
            }
            
            
            /* Wait for the HSI clock source to be ready */
            while((AHB_RCC->CR.Bit.HSERDY == 0) && (RCC_TIMEOUT_COUNTER < MAX_TIMEOUT_DELAY))
            {
            	RCC_TIMEOUT_COUNTER++;
            }


			/* Check if a timeout has occured */
            if(RCC_TIMEOUT_COUNTER == MAX_TIMEOUT_DELAY)
			{
				Local_enumState = RCC_Error_Timeout;
				break;
			}
			

			/* Select the HSE as the system clock */
			AHB_RCC->CFGR.Bit.SW = RCC_SYSTEM_CLOCK_HSE;
            break;
            
            
            // ----------------------------------------------------------------------- //
			
			
        case RCC_PLL_CLOCK_SORCE:    // If the PLL clock source is selected
            
			
            /* Configure the PLL source */
            switch(RCC_InitConfig->PLL_Source)
            {
                case RCC_PLL_SOURCE_HSI_DIV_2:    AHB_RCC->CFGR.Bit.PLLSRC = 0;    break;
                case RCC_PLL_SOURCE_HSE_NOT_DIV:  AHB_RCC->CFGR.Bit.PLLSRC = 1;    AHB_RCC->CFGR.Bit.PLLXTPRE = 0;    break;
                case RCC_PLL_SOURCE_HSE_DIV_2:    AHB_RCC->CFGR.Bit.PLLSRC = 1;    AHB_RCC->CFGR.Bit.PLLXTPRE = 1;    break;
                default:
                
            }
            
            
            /* Set the PLL multiplier factor to the selected factor */
            AHB_RCC->CFGR.Bit.PLLMUL = RCC_InitConfig->PLL_Multiplier_Factor - 2;
            
            
			/* Enable the PLL clock source */
            AHB_RCC->CR.Bit.PLLON = 1;
            
			
			/* Wait for the PLL clock source to be ready */
            while((AHB_RCC->CR.Bit.PLLRDY == 1) && (RCC_TIMEOUT_COUNTER < MAX_TIMEOUT_DELAY))
			{
            	RCC_TIMEOUT_COUNTER++;
				break;
			}


			/* Check if a timeout has occured */
            if(RCC_TIMEOUT_COUNTER == MAX_TIMEOUT_DELAY)
            {
            	Local_enumState = RCC_Error_Timeout;
				break;
            }
            

			/* Select the PLL as the system clock */
            AHB_RCC->CFGR.Bit.SW = RCC_SYSTEM_CLOCK_PLL;
            break;
            
            
            // ----------------------------------------------------------------------- //
			
			
        default:
            /* Warning: Wrong selection for Clock_Source; Default selection
               will be applied (RCC_HSI_CLOCK_SORCE);--------------------*/
            
            
            /* Set the HSI trimming value to 16 */
            AHB_RCC->CR.Bit.HSITRIM = 16;
            
            
            /* Enable the HSI clock source */
            AHB_RCC->CR.Bit.HSION = 1;
            AHB_RCC->CR.Bit.HSEON = 0;
            AHB_RCC->CR.Bit.PLLON = 0;
            
            
            /* Wait for the HSI clock source to be ready */
            while((AHB_RCC->CR.Bit.HSIRDY == 0) && (RCC_TIMEOUT_COUNTER < MAX_TIMEOUT_DELAY))
            {
            	RCC_TIMEOUT_COUNTER++;
            }

            if(RCC_TIMEOUT_COUNTER == MAX_TIMEOUT_DELAY)
			{
				Local_enumState = RCC_Error_Timeout;
				break;
			}
            
            
            /* Select the HSI as the system clock */
            AHB_RCC->CFGR.Bit.SW = RCC_SYSTEM_CLOCK_HSI;
        }
    
	
	    /** Configure the MCO pin **/
	    AHB_RCC->CFGR.Bit.MCO = RCC_InitConfig->MCO_Pin_Status;
		
		Local_enumState = RCC_OK;
	}
	else
	{
		Local_enumState = RCC_Error_NULLStruct;
	}
	
	return Local_enumState;
}



/** >>>>>>>>>>>>>>> Peripheral Clock Enable Function <<<<<<<<<<<<<<< **/



ErrorState_t MCAL_RCC_enumEnablePeripheralClock (Peripheral_ID_t Copy_enumPeripheralID)
{
	
	ErrorState_t Status;
	
	
	switch(Copy_enumPeripheralID)
	{
		case Per_ID_AHB_DMA1...Per_ID_AHB_SDIO:     // Enable a peripheral in the AHB bus
		
			SET_BIT(AHB_RCC->AHBENR.Word , Copy_enumPeripheralID);
		
			Status = RCC_OK;
		
			break;
		
		
		case Per_ID_APB2_AFIO...Per_ID_APB2_TIM11:    // Enable a peripheral in the APB2 bus
		
			ET_BIT(AHB_RCC->APB2ENR.Word , (Copy_enumPeripheralID - 100U));
		
			Status = RCC_OK;
		
			break;
		
		
		case Per_ID_APB1_TIM2...Per_ID_APB1_DAC:      // Enable a peripheral in the APB1 bus
		
			SET_BIT(AHB_RCC->APB1ENR.Word , (Copy_enumPeripheralID - 200U));
		
			Status = RCC_OK;
		
			break;
		
		
		default:
		
			Status = RCC_Error_UndefinedPeripheralID;
	}
	
	return Status;
}


/** >>>>>>>>>>>>>>> Peripheral Clock Disable Function <<<<<<<<<<<<<<< **/



ErrorState_t MCAL_RCC_enumDisablePeripheralClock (Peripheral_ID_t Copy_enumPeripheralID)
{

	ErrorState_t Status;


	switch(Copy_enumPeripheralID)
	{
		case Per_ID_AHB_DMA1...Per_ID_AHB_SDIO:     // Disable a peripheral in the AHB bus

			CLR_BIT(AHB_RCC->AHBENR.Word , Copy_enumPeripheralID);

			Status = RCC_OK;

			break;


		case Per_ID_APB2_AFIO...Per_ID_APB2_TIM11:    // Disable a peripheral in the APB2 bus

			CLR_BIT(AHB_RCC->APB2ENR.Word , (Copy_enumPeripheralID - 100U));

			Status = RCC_OK;

			break;


		case Per_ID_APB1_TIM2...Per_ID_APB1_DAC:      // Disable a peripheral in the APB1 bus

			CLR_BIT(AHB_RCC->APB1ENR.Word , (Copy_enumPeripheralID - 200U));

			Status = RCC_OK;

			break;


		default:

			Status = RCC_Error_UndefinedPeripheralID;
	}

	return Status;
}



/** ======================================================== **/
/** ================ RCC ISRs Implementation =============== **/
/** ======================================================== **/