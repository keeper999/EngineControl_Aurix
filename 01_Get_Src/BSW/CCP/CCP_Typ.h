/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_TYP                                                                                         */
/* !Description     : Declaration of component data types                                                             */
/*                                                                                                                    */
/* !File            : CCP_TYP.h                                                                                       */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT 2009 VALEO                                                                                               */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#ifndef CCP_TYP_H
#define CCP_TYP_H

#include "Std_Types.h"
#include "Std_Limits.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !MComment: defines to specify features/services activation                                                         */
#define CCP_coACVD   0x5A
#define CCP_coDEACVD 0xA5

#define CCP_coMSB_FIRST      HIGH_BYTE_FIRST
#define CCP_coLSB_FIRST      LOW_BYTE_FIRST
#define CCP_coCPU_BYTE_ORDER CPU_BYTE_ORDER

#define CCP_u8DAQ_NO_ELMS_PER_ODT 7

#define CCP_u8DAQ_TX_ST_DONE  0
#define CCP_u8DAQ_TX_ST_RUNNG 1

#define CCP_coDAQ_ELM_SIZE_MAX_8_BITS  1
#define CCP_coDAQ_ELM_SIZE_MAX_16_BITS 2
#define CCP_coDAQ_ELM_SIZE_MAX_32_BITS 3


/**********************************************************************************************************************/
/* TYPES                                                                                                              */
/**********************************************************************************************************************/
/* !Comment: type for command status. Shall be able to contain an uint8 value and should be defined to the size of    */
/*           the micro registers to optimize the code.                                                                */
typedef uint8_least CCP_tudtCmdSts;

typedef uint8_least CCP_tudtState;
typedef uint8_least CCP_tudtCmdCode;

typedef P2FUNC(CCP_tudtCmdSts, CCP_APPL_CODE, CCP_tpfudtSrvFcn)(void);

typedef struct
{
   uint32 u32Adr;
   uint8  u8Extn;
}
CCP_tstrMta;

typedef struct
{
   uint8 u8NoOdt;    /* !Comment : Number of ODTs                                                                     */
   uint8 u8FirstPid; /* !Comment : PID of the first ODT                                                               */
                     /* !Range   : 0..0xFD                                                                            */
}
CCP_tstrDaqListStatCfg;

/* !Comment : Dynamic configuration of a DAQ list and data used to manage it                                          */
/*            (structure order optimised for element access speed: higher access rate first)                          */
typedef struct
{
   boolean vbStopTx;         /* !Comment : Request to stop sending ODT                                                */
   boolean bLstOdtProcd;     /* !Comment : Indicates if the last ODT of the DAQ list has been processed               */
   uint8   vu8TxSt;          /* !Comment : State of the DAQ list transmission                                         */
                             /* !Range   : CCP_u8DAQ_TX_ST_DONE, CCP_u8DAQ_TX_ST_RUNNG                                */
   uint8   u8OdtLstIdx;      /* !Comment : Index of the last ODT to send                                              */
                             /* !Range   : 0..(number of ODT defined in the configuration - 1)                        */
   boolean vbEvtSet;         /* !Comment : Signal that a new event has been set                                       */
   uint8   u8EveChn;         /* !Comment : Event channel associated to the DAQ list                                   */
                             /* !Range   : 0..(CCP_u8DAQ_NO_EVE_CHNS-1)                                               */
   uint8   vu8CfgChgdCtr;    /* !Comment : Counter used to indicate that the dynamic configuration of DAQ list has    */
                             /*            changed                                                                    */
                             /*            (used as a rollover counter)                                               */
   uint8   u8CfgChgdAckdCtr; /* !Comment : Counter used to acknowledge the modifications of the DAQ list dynamic      */
                             /*            configuration                                                              */
   uint8   vu8Mod;           /* !Comment : DAQ list mode                                                              */
                             /* !Range   : CCP_u8DAQ_MOD_STOP, CCP_u8DAQ_MOD_STRT, CCP_u8DAQ_MOD_SYNCD_STRT           */
   uint16  u16Ctr;           /* !Comment : Number of cycles before sending the DAQ list                               */
   uint16  u16Pslr;          /* !Comment : Prescaler to lower the transmission rate                                   */
}
CCP_tstrDaqListDynCfg;

/* !Comment : Defines the location of an element in a DAQ list                                                        */
typedef struct
{
   uint8 u8ListIdx; /* !Comment : DAQ list index                                                                      */
                    /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                           */
   uint8 u8OdtIdx;  /* !Comment : ODT index in the selected DAQ list                                                  */
                    /* !Range   : 0..(number of ODT defined in the configuration - 1)                                 */
   uint8 u8ElmIdx;  /* !Comment : Element index in the selected ODT of the selected DAQ list                          */
                    /*            (shall be set to CCP_u8DAQ_NO_ELMS_PER_ODT if no element selected)                  */
                    /* !Range   : 0..CCP_u8DAQ_NO_ELMS_PER_ODT                                                        */
}
CCP_tstrDaqListSeldElm;

/* !Comment : CPP initialization parameters                                                                           */
typedef struct
{
   /* !Comment : This variable is only there to avoid the compiling error "empty struct or union"                     */
   uint16 u16Dummy;
}
CCP_tstrIniPrms;


#endif /* CCP_TYP_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
