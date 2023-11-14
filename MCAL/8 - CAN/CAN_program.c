/*****************************************************************
****    File Name    :  CAN_program.c                         ****
****    Author       :  Eng. Mahmoud Sayed                    ****
****    Date         :  11 Nov 2023                           ****
****    Version      :  V 1.0                                 ****
****    Description  :  This file contains the CAN            ****
****                    function implementation               ****
*****************************************************************/



/** ======================================================== **/  
/** ==================== Include Files ===================== **/
/** ======================================================== **/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CAN_interface.h"
#include "CAN_private.h"
#include "CAN_config.h"



/** ======================================================== **/  
/** ================== CAN Defined Macros ================== **/
/** ======================================================== **/



/** ======================================================== **/  
/** ================= CAN Global Variables ================= **/
/** ======================================================== **/



/** ======================================================== **/  
/** ============= CAN Functions Implementation ============= **/
/** ======================================================== **/



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_CAN_voidInit
	Arguments     : void
	Return type   : void
	Description   : Initialization for the CAN driver 
	based on its configuration.
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */



void    MCAL_CAN_voidInit(void)
{
	APB1_CAN1_CONTROL_STATUS->MCR.INRQ = 1;    // Enter the CAN Initialization mode.
	
	
	
	/* >>>>>>>>>>>>>>>>>>>> Initialization Steps <<<<<<<<<<<<<<<<<<<< */
	/** First: Initialize the MCR register **/
	
	
	// Configure the debug freez mode
	APB1_CAN1_CONTROL_STATUS->MCR.DBF = CAN_DEBUG_FREEZ;
	
	// Configure the time triggered communication mode
	APB1_CAN1_CONTROL_STATUS->MCR.TTCM = CAN_TTC_MODE;

    // Configure the automatic bus off management
	APB1_CAN1_CONTROL_STATUS->MCR.ABOM = CAN_AUTO_BUS_OFF_MANAGEMENT;

    // Configure the automatic wake-up 
    APB1_CAN1_CONTROL_STATUS->MCR.AWUM = CAN_AUTO_WAKE_UP_MODE;
    
    // Configure the automatic retransmission
    APB1_CAN1_CONTROL_STATUS->MCR.NART = CAN_NON_AUTO_RETRANSMISSION;
    
    // Configure the RX FIFO retransmission
    APB1_CAN1_CONTROL_STATUS->MCR.RFLM = CAN_RX_FIFO_LOCKED_MODE;
    
    // Configure TX FIFO priority
    APB1_CAN1_CONTROL_STATUS->MCR.TXFP = CAN_TX_FIFO_PRIORITY;
	
	
	
	/** Second: Initialize the Interrupt register **/
	
	
	
	// Clear all interrupts in the IER register (Can be set by software later)
	APB1_CAN1_CONTROL_STATUS->IER = 0x00000000;
	
	
	
	APB1_CAN1_CONTROL_STATUS->MCR.INRQ = 0;    // Exit the CAN Initialization mode, and Enter the CAN Normal mode.	
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_CAN_voidTransmit
	Arguments     : u8 Ref_u8arrTransmittedData[] , u8 Copy_u8DLC
	Return type   : void
	Description   : TX with Standard ID
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
void    MCAL_CAN_voidTransmit(u32 Copy_u32MessageID ,u8 Ref_u8arrTransmittedData[] , u8 Copy_u8DLC)
{
	APB1_CAN1_MAILBOX->TI0R
}



/*  >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<
    Function name : MCAL_CAN_voidRecieve
	Arguments     : u8 Ref_u8arrReceivedData[] , u8 Copy_u8DLC
	Return type   : void
	Description   : 
    >>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<< */
	
	
	
void    MCAL_CAN_voidRecieve(u8 Ref_u8arrReceivedData[] , u8 Copy_u8DLC)
{
	
}



/** ============================================== **/  
/** =========== CAN ISRs Implementation ========== **/
/** ============================================== **/


