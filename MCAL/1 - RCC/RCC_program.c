/***********************************************************
****    File Name    :  RCC_program.c                   ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  31 Oct 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  This file contains the RCC      ****
                        function implementation         ****
***********************************************************/



/** ============================================== **/  
/** =============== Include Files ================ **/
/** ============================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



/** ============================================== **/  
/** ============= RCC Defined Macros ============= **/
/** ============================================== **/



/** ============================================== **/  
/** ============ RCC Global Variables ============ **/
/** ============================================== **/



/** ============================================== **/  
/** ======== RCC Functions Implementation ======== **/
/** ============================================== **/



/** =============== RCC Initialization Function =============== **/



void MCAL_RCC_InitSystemClock (RCC_InitConfig_t * RCC_InitConfig)
{
    
    
    /** Configure the AHB, APB1, and APB2 prescalers **/
    AHB_RCC->CFGR.HPRE  = RCC_InitConfig->AHB_Prescaler  ;
    AHB_RCC->CFGR.PPRE1 = RCC_InitConfig->APB1_Prescaler ;
    AHB_RCC->CFGR.PPRE2 = RCC_InitConfig->APB2_Prescaler ;
    
    
    /** Configure the clock source selected **/
    switch(RCC_InitConfig->Clock_Source)
    {
        case RCC_HSI_CLOCK_SORCE:    // If the HSI clock source is selected
            
            
            /* Configure the HSI trimming value */
            AHB_RCC->CR.HSITRIM = RCC_InitConfig->HSI_Trim_Value;
            
            
            /* Enable the HSI clock source */
            AHB_RCC->CR.HSION = 1;
            AHB_RCC->CR.HSEON = 0;
            AHB_RCC->CR.PLLON = 0;
            
            
	    /* Wait for the HSI clock source to be ready */
            while(AHB_RCC->CR.HSIRDY == 0);
			
			
	    /* Select the HSI as the system clock */
	    AHB_RCC->CFGR.SW = RCC_SYSTEM_CLOCK_HSI;
            break;
			
			
            // ----------------------------------------------------------------------- //
            
            
        case RCC_HSE_CLOCK_SORCE:    // If the HSE clock source is selected
            
            
            /* Configure the HSE oscillator */
            switch(RCC_InitConfig->HSE_Oscillator)
            {
            	case RCC_HSE_CRYSTAL_OSCILLATOR:    AHB_RCC->CR.HSEBYP = 1;    break;
            	case RCC_HSE_RC_OSCILLATOR:         AHB_RCC->CR.HSEBYP = 0;    break;
            	default:
            	
            }
            
            
            /* Configure the clock security system */
            switch(RCC_InitConfig->Clock_Security_System)
            {
            	case RCC_CSS_ON:     AHB_RCC->CR.CSS = 1;    break;
            	case RCC_CSS_OFF:    AHB_RCC->CR.CSS = 0;    break;
            	default:
            	
            }
            
            
            /* Enable the HSE clock source */
            AHB_RCC->CR.HSION = 0;
            AHB_RCC->CR.HSEON = 1;
            AHB_RCC->CR.PLLON = 0;
            
            
            /* Wait for the HSI clock source to be ready */
            while(AHB_RCC->CR.HSERDY == 0);
			
			
	    /* Select the HSE as the system clock */
	    AHB_RCC->CFGR.SW = RCC_SYSTEM_CLOCK_HSE;
            break;
            
            
            // ----------------------------------------------------------------------- //
			
			
        case RCC_PLL_CLOCK_SORCE:    // If the PLL clock source is selected
            
			
            /* Configure the PLL source */
            switch(RCC_InitConfig->PLL_Source)
            {
                case RCC_PLL_SOURCE_HSI_DIV_2:    AHB_RCC->CFGR.PLLSRC = 0;    break;
                case RCC_PLL_SOURCE_HSE_NOT_DIV:  AHB_RCC->CFGR.PLLSRC = 1;    AHB_RCC->CFGR.PLLXTPRE = 0;    break;
                case RCC_PLL_SOURCE_HSE_DIV_2:    AHB_RCC->CFGR.PLLSRC = 1;    AHB_RCC->CFGR.PLLXTPRE = 1;    break;
                default:
                
            }
            
            
            /* Set the PLL multiplier factor to the selected factor */
            AHB_RCC->CFGR.PLLMUL = RCC_InitConfig->PLL_Multiplier_Factor - 2;
            
            
	    /* Enable the PLL clock source */
	    AHB_RCC->CR.HSION = 0;
            AHB_RCC->CR.HSEON = 0;
            AHB_RCC->CR.PLLON = 1;
            
			
	    /* Wait for the PLL clock source to be ready */
            while(AHB_RCC->CR.PLLRDY == 1);
            
            
	    /* Select the PLL as the system clock */
            AHB_RCC->CFGR.SW = RCC_SYSTEM_CLOCK_PLL;
            break;
            
            
            // ----------------------------------------------------------------------- //
			
			
        default:
            /* Warning: Wrong selection for Clock_Source; Default selection
               will be applied (RCC_HSI_CLOCK_SORCE);--------------------*/
            
            
            /* Set the HSI trimming value to 16 */
            AHB_RCC->CR.HSITRIM = 16;
            
            
            /* Enable the HSI clock source */
            AHB_RCC->CR.HSION = 1;
            AHB_RCC->CR.HSEON = 0;
            AHB_RCC->CR.PLLON = 0;
            
            
            /* Wait for the HSI clock source to be ready */
            while(!(AHB_RCC->CR.HSIRDY == 1));
            
            
            /* Select the HSI as the system clock */
            AHB_RCC->CFGR.SW = RCC_SYSTEM_CLOCK_HSI;
    }
    
	
	/** Configure the MCO pin **/
	AHB_RCC->CFGR.MCO = RCC_InitConfig->MCO_Pin_Status;
}



/** =============== Peripheral Clock Enable Function =============== **/



ErrorState_t MCAL_RCC_EnablePeripheralClock (Peripheral_ID_t Peripheral_ID)
{
	
	ErrorState_t Status;
	
	
	switch(Peripheral_ID)
	{
		case DMA1...SDIO:     // Enabling a peripheral in the AHB bus
		
		    SET_BIT(AHB_RCC->AHBENR.Word , Peripheral_ID);
		
		    Status = RCC_OK;
		
		    break;
		
		
		case AFIO...TIM11:    // Enabling a peripheral in the APB2 bus
		
		    SET_BIT(AHB_RCC->APB2ENR.Word , Peripheral_ID - 100);
		
		    Status = RCC_OK;
		
		    break;
		
		
		case TIM2...DAC:      // Enabling a peripheral in the APB1 bus
		
		    SET_BIT(AHB_RCC->APB1ENR.Word , Peripheral_ID - 200);
		
		    Status = RCC_OK;
		
		    break;
		
		
		default:
		
		    Status = RCC_Error_Peripheral_ID;
		
	}
	
	return Status;
}



/** ============================================== **/  
/** =========== RCC ISRs Implementation ========== **/
/** ============================================== **/


