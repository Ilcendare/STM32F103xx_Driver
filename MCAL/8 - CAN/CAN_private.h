/*******************************************************************
****    File Name    :  CAN_pivate.h                            ****
****    Author       :  Eng. Mahmoud Sayed                      ****
****    Date         :  11 Nov 2023                             ****
****    Version      :  V 1.0                                   ****
****    Description  :  This file contains the CAN's            ****
****                    registers, private variables,           ****
****                    data types, and functions.		        ****
*******************************************************************/



/* ======================================================== */  
/* ================== File Header Guard =================== */
/* ======================================================== */
 
 
 
#ifndef    _MCAL_CAN_PRIVATE_H_ 
#define    _MCAL_CAN_PRIVATE_H_ 



/* ======================================================== */  
/* ================ CAN Registers Bitfield ================ */
/* ======================================================== */



/** Control and status registers bitfield definition **/



typedef union {
	struct {
	    u32 INRQ  :  1;
        u32 SLEEP :  1;
		u32 TXFP  :  1;
		u32 RFLM  :  1;
		u32 NART  :  1;
		u32 AWUM  :  1;
		u32 ABOM  :  1;
		u32 TTCM  :  1;
		u32       :  7;
		u32 RESET :  1;
		u32 DBF   :  1;
		u32       : 15;
	}
	
	u32 Word;
	
} MCR_t;



typedef union {
	struct {
		u32 INAK  :  1;
		u32 SLAK  :  1;
		u32 ERRI  :  1;
		u32 WKUI  :  1;
		u32 SLAKI :  1;
		u32       :  3; 
		u32 TXM   :  1;
		u32 RXM   :  1;
		u32 SAMP  :  1;
		u32 RX    :  1;
	    u32       : 20;
	}
	
	u32 Word;
	
}MSR_t;



typedef union { LOW[2:0]
	struct {
		u32  RQCP0 : 1;
		u32  TXOK0 : 1;
		u32  ALST0 : 1;
		u32  TERR0 : 1;
		u32        : 3;
		u32  ABRQ0 : 1; 
		u32  RQCP1 : 1;
		u32  TXOK1 : 1;
		u32  ALST1 : 1;
		u32  TERR1 : 1;
		u32        : 3;
	    u32  ABRQ1 : 1;
		u32  RQCP2 : 1;
		u32  TXOK2 : 1;
		u32  ALST2 : 1;
		u32  TERR2 : 1;
		u32        : 3;
		u32  ABRQ2 : 1;
		u32  CODE  : 2;
		u32  TME   : 3;
		u32  LOW   : 3;
	}
	
	u32 Word;
	
}TSR_t;



typedef union { Reserved
	struct {
		u32  TMEIE  : 1;
		u32  FMPIE0 : 1;
		u32  FFIE0  : 1;
		u32  FOVIE0 : 1;
		u32  FMPIE1 : 1;
		u32  FFIE1  : 1; 
		u32  FOVIE1 : 1;
		u32         : 1;
		u32  EWGIE  : 1;
		u32  EPVIE  : 1;
	    u32  BOFIE  : 1;
		u32  LECIE  : 1;
		u32         : 3;
		u32  ERRIE  : 1;
		u32  WKUIE  : 1;
		u32  SLKIE  : 1;
		u32         :14;
	}
	
	u32 Word;
	
} IER_t;



typedef union {
	struct {
		u32  EWGF: 1;
		u32  EPVF: 1;
		u32  BOFF: 1;
		u32      : 1;  
		u32  LEC : 3;
		u32      : 9; 
		u32  TEC : 8;
		u32  REC : 8;
	}
	
	u32 Word;
	
}ESR_t;



/** Mailbox registers bitfield definition **/



typedef union {
	struct {
		u32 DLC : 4;
		u32     : 4;
		u32 TGT : 1;
		u32     : 7;
		u32 TIME: 16;
	}
	
	u32 Word;
	
}TDTxR_t;



typedef union {
	struct {
		u32 DATA0 : 8;
		u32 DATA1 : 8;
		u32 DATA2 : 8;
		u32 DATA3 : 8;
	}
	
	u32 Word;
	
}TXRX_DLxR_t;



typedef union {
	struct {
		u32 DATA4 : 8;
		u32 DATA5 : 8;
		u32 DATA6 : 8;
		u32 DATA7 : 8;
	}
	
	u32 Word;
	
}TXRX_DHxR_t;



/* ======================================================== */  
/* =============== CAN Registers Definition =============== */
/* ======================================================== */



/** Define the Control and Statuse registers with their offset in a struct **/



typedef struct {
	volatile MCR_t MCR;
    volatile MSR_t MSR;
    volatile TSR_t TSR;
    volatile u32 RF0R;
    volatile u32 RF1R;
    volatile IER_t IER;
    volatile ESR_t ESR;
    volatile u32 BTR;
} CAN_ControlRegisters_t;



/** Define the Mailbox registers with their offset in a struct **/



typedef struct {
	/** For TX mailbox 0 (TX buffer 0) **/
	volatile u32 TI0R;
    volatile TDTxR_t TDT0R;
    volatile TXRX_DLxR_t TDL0R;
    volatile TXRX_DHxR_t TDH0R;
	
	
	/** For TX mailbox 1 (TX buffer 1) **/
    volatile u32 TI1R;
    volatile TDTxR_t TDT1R;
    volatile TXRX_DLxR_t TDL1R;
    volatile TXRX_DHxR_t TDH1R;


    /** For TX mailbox 2 (TX buffer 2) **/
    volatile u32 TI2R;
    volatile TDTxR_t TDT2R;
    volatile TXRX_DLxR_t TDL2R;
    volatile TXRX_DHxR_t TDH2R;
    
	
	/** For RX mailbox 0 (RX FIFO 0) **/
    volatile u32 RI0R;
    volatile u32 RDT0R;
    volatile TXRX_DLxR_t RDL0R;
    volatile TXRX_DHxR_t RDH0R;


    /** For RX mailbox 1 (RX FIFO 1) **/
    volatile u32 RI1R;
    volatile u32 RDT1R;
    volatile TXRX_DLxR_t RDL1R;
    volatile TXRX_DHxR_t RDH1R;
} CAN_MailboxRegisters_t;



#define    CAN1_ADDRESS_BASE     0x40006400
#define    CAN2_ADDRESS_BASE     0x40006800



/** Define the first mailbox register offset from the CANx base address */
#define    CAN_MAILBOX_OFFSET    0x180



/** Define CAN1 registers **/
#define    APB1_CAN1_CONTROL_STATUS    ((CAN_ControlRegisters_t *)CAN1_ADDRESS_BASE)
#define    APB1_CAN1_MAILBOX           ((CAN_MailboxRegisters_t *)(CAN1_ADDRESS_BASE + CAN_MAILBOX_OFFSET))



/** Define CAN2 registers **/
#define    APB1_CAN2_CONTROL_STATUS    ((CAN_ControlRegisters_t *)CAN2_ADDRESS_BASE)
#define    APB1_CAN2_MAILBOX           ((CAN_MailboxRegisters_t *)(CAN2_ADDRESS_BASE + CAN_MAILBOX_OFFSET))



/* ======================================================== */  
/* ================== CAN Private Macros ================== */
/* ======================================================== */



/* ======================================================== */  
/* ================= CAN Private Functions ================ */
/* ======================================================== */



#endif    //_MCAL_CAN_PRIVATE_H_
