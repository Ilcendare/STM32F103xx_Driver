/***********************************************************
****    File Name    :  CAN_config.h                    ****
****    Author       :  Eng. Mahmoud Sayed              ****
****    Date         :  11 Nov 2023                     ****
****    Version      :  V 1.0                           ****
****    Description  :  Configuration for the CAN       ****
****                    driver.                         ****
***********************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */



#ifndef    _MCAL_CAN_CONFIG_H_
#define    _MCAL_CAN_CONFIG_H_



/* ======================================================== */  
/* ===================== Configuration ==================== */
/* ======================================================== */



/* Pre-Setup configuration */



/**
 Debug Freez Configuration:
    - For disable -> write (0)
    - For enable  -> write (1)
 **/
#define    CAN_DEBUG_FREEZ    (0)



/**
 Timer Triggered Communication Mode:
    - For disable TTC mode -> write (0)
    - For enable  TTC mode-> write (1)
**/
 #define    CAN_TTC_MODE    (0)
 
 
 
/**
 Automatic Bus-off Management:
    - The Bus-Off state is left on software request, once 128 occurrences of 11 recessive bits
      have been monitored and the software has first set and cleared the INRQ bit of the CAN_MCR register -> write (0)
    - The Bus-Off state is left automatically by hardware once 128 occurrences of 11 recessive
      bits have been monitored -> write (1)
**/
#define    CAN_AUTO_BUS_OFF_MANAGEMENT    (0)



/**
    - Writing (0): The Sleep mode is left on software request by clearing the SLEEP bit of the CAN_MCR register.
    - Writing (1): The Sleep mode is left automatically by hardware on CAN message detection.
**/
#define    CAN_AUTO_WAKE_UP_MODE    (0)



/**
    - Writing (0): The CAN hardware will automatically retransmit the message until it has been
                   successfully transmitted according to the CAN standard.
    - Writing (1): A message will be transmitted only once, independently of the transmission result
                  (successful, error or arbitration lost).
**/
#define    CAN_NON_AUTO_RETRANSMISSION    (0)



/**
    - Writing (0): Receive FIFO not locked on overrun. Once a receive FIFO is full the next incoming
                   message will overwrite the previous one.
    - Writing (1): Receive FIFO locked against overrun. Once a receive FIFO is full the next incoming
                   message will be discarded.
**/
#define    CAN_RX_FIFO_LOCKED_MODE    (0)



/**
    - Writing (0): Priority driven by the identifier of the message.
    - Writing (1): Priority driven by the request order (chronologically).
**/
#define    CAN_TX_FIFO_PRIORITY    (0)



/* Frame configuration */



/**
    Configure the message ID mask
**/
#define    CAN_ID_MASK    (0x00000001)



/* Error management configuration */



#endif    //_MCAL_CAN_CONFIG_H_
