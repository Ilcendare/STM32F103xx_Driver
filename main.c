/***********************************************************
****    File Name    :  main.c                          ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  1  Nov 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  The main function file.         ****
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
/** ========= User-Defined Defined Macros ======== **/
/** ============================================== **/



/** ============================================== **/
/** ======== User-Defined Global Variables ======= **/
/** ============================================== **/



RCC_InitConfig_t RCC_InitConfig_Struct;



/** ============================================== **/
/** ===== User-Defined Functions Declaration ===== **/
/** ============================================== **/



void InitializeSystem(void);



/** =============== The main Function =============== **/



void main(void)
{
	InitializeSystem();


	while(1)
	{

	}
}



/** ================================================= **/



/** =============================================== **/
/** ==== User-Defined Functions Implementation ==== **/
/** =============================================== **/



void InitializeSystem(void)
{
	RCC_InitConfig_Struct.AHB_Prescaler = RCC_AHB_PRE_SYSCLK_NOT_DIV;
	RCC_InitConfig_Struct.APB1_Prescaler = RCC_APB1_PRE_AHBCLK_NOT_DIV;
	RCC_InitConfig_Struct.APB2_Prescaler = RCC_APB2_PRE_AHBCLK_NOT_DIV;
	RCC_InitConfig_Struct.Clock_Source = RCC_HSE_CLOCK_SORCE;
	RCC_InitConfig_Struct.Clock_Security_System = RCC_CSS_ON;
	RCC_InitConfig_Struct.HSE_Oscillator = RCC_HSE_CRYSTAL_OSCILLATOR;

	MCAL_RCC_InitSystemClock(&RCC_InitConfig_Struct);

	if(MCAL_RCC_EnablePeripheralClock(GPIOA) != RCC_OK)
	{
		// Error_Handler();
	}
}



/** =============================================== **/
/** ======= User-Defined ISRs Implementation ====== **/
/** =============================================== **/
