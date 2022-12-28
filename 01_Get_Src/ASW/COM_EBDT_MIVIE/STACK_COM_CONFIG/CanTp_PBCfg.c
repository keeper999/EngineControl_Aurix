
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_PBCfg.c                                           */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.0      $$Author::   madel          $$Date::   Nov 22 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp_PBCfg.c
*
* \par
*   This file contains post-build time configuration parameters of the CanTp 
    Component                                                                 */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0838]: Empty macros of memory classes     */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */

#include "CanTp_PBCfg.h"
#include "CanTp_Types.h"
#include "CanTp_LocalCfg.h"
#include "CanIf_Cfg.h"


#define CANTP_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"


  
/* Eval('CANTP-CRC-002','GENERAL')                     */

/* Eval('CANTP-CRC-003','GENERAL')                     */
/******************************************************************************/
/*! \Description    Array that contains the post-build time configuration    
                    parameters for each CanTpTxNSdu                           */
/******************************************************************************/
static CONST (CanTp_tstrTxNSduPBCfgType, CANTP_CALIB_CONST)
                                    akstrTxNSduPBCfg[CanTp_u16NUM_OF_TX_NSDUS] =
{
/******************************************************************************/
/********************* CanTpTxNSdu 000 - CanTpChannel 03 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-006','0')                     */

/* Eval('CANTP-CRC-007','0')                     */

/* Eval('CANTP-CRC-010','0')                     */

/* Eval('CANTP-CRC-011','0')                     */

/* Eval('CANTP-CRC-013','0')                     */

/* Eval('CANTP-CRC-016','0')                     */

/* Eval('CANTP-CRC-017','0')                     */
    {
        /*  u16NAs          */  100,
        /*  u16NBs          */  100,
        /*  u16NCs          */  2,
        /*  udtTxLSduId     */  CanIf_CanTpTxNPdu_688,
        /*  udtTxIPduId     */  0x1
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 001 - CanTpChannel 02 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-006','1')                     */

/* Eval('CANTP-CRC-007','1')                     */

/* Eval('CANTP-CRC-010','1')                     */

/* Eval('CANTP-CRC-011','1')                     */

/* Eval('CANTP-CRC-013','1')                     */

/* Eval('CANTP-CRC-016','1')                     */

/* Eval('CANTP-CRC-017','1')                     */
    {
        /*  u16NAs          */  100,
        /*  u16NBs          */  100,
        /*  u16NCs          */  2,
        /*  udtTxLSduId     */  CanIf_CanTpTxNPdu_688,
        /*  udtTxIPduId     */  0x1
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 002 - CanTpChannel 00 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-006','2')                     */

/* Eval('CANTP-CRC-007','2')                     */

/* Eval('CANTP-CRC-010','2')                     */

/* Eval('CANTP-CRC-011','2')                     */

/* Eval('CANTP-CRC-013','2')                     */

/* Eval('CANTP-CRC-016','2')                     */

/* Eval('CANTP-CRC-017','2')                     */
    {
        /*  u16NAs          */  100,
        /*  u16NBs          */  100,
        /*  u16NCs          */  2,
        /*  udtTxLSduId     */  CanIf_CanTpTxNPdu_7E8,
        /*  udtTxIPduId     */  0x0
    }
    ,
/******************************************************************************/
/********************* CanTpTxNSdu 003 - CanTpChannel 01 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-006','3')                     */

/* Eval('CANTP-CRC-007','3')                     */

/* Eval('CANTP-CRC-010','3')                     */

/* Eval('CANTP-CRC-011','3')                     */

/* Eval('CANTP-CRC-013','3')                     */

/* Eval('CANTP-CRC-016','3')                     */

/* Eval('CANTP-CRC-017','3')                     */
    {
        /*  u16NAs          */  100,
        /*  u16NBs          */  100,
        /*  u16NCs          */  2,
        /*  udtTxLSduId     */  CanIf_CanTpTxNPdu_7E8,
        /*  udtTxIPduId     */  0x0
    }
    ,
};
/******************************************************************************/
/*  \ConfigTool     -An entry in akstrTxNSduPBCfg shall be created for each
                     instance of CanTpTxNSdu
                    -The entries must be ordered as in CanTp_akstreTxNSduPCCfg 
                     ascendingly based on the configuration parameter 
                     CanTpTxNSduId of each CanTpTxNSdu.                       */
/******************************************************************************/



/******************************************************************************/
/*! \Description    Array that contains the post-build time configuration    
                    parameters for each CanTpRxNSdu                           */
/******************************************************************************/
static CONST (CanTp_tstrRxNSduPBCfgType, CANTP_CALIB_CONST)
                                    akstrRxNSduPBCfg[CanTp_u16NUM_OF_RX_NSDUS] =
{
/******************************************************************************/
/********************* CanTpRxNSdu 000 - CanTpChannel 03 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-004','0')                     */

/* Eval('CANTP-CRC-005','0')                     */

/* Eval('CANTP-CRC-008','0')                     */

/* Eval('CANTP-CRC-009','0')                     */

/* Eval('CANTP-CRC-012','0')                     */

/* Eval('CANTP-CRC-014','0')                     */

/* Eval('CANTP-CRC-015','0')                     */
  {
        /*  u8BlockSize     */  0,
        /*  u16NAr          */  100,
        /*  u16NBr          */  2,
        /*  u16NCr          */  100,
        /*  u16RxWftMax     */  3,
        /*  u8STmin         */  10,   
        /*  udtRxIPduId     */  0x2,
        /*  udtTxFcLSduId    */  CanIf_CanTpTxNPdu_688
		
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 001 - CanTpChannel 02 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-004','1')                     */

/* Eval('CANTP-CRC-005','1')                     */

/* Eval('CANTP-CRC-008','1')                     */

/* Eval('CANTP-CRC-009','1')                     */

/* Eval('CANTP-CRC-012','1')                     */

/* Eval('CANTP-CRC-014','1')                     */

/* Eval('CANTP-CRC-015','1')                     */
  {
        /*  u8BlockSize     */  0,
        /*  u16NAr          */  100,
        /*  u16NBr          */  2,
        /*  u16NCr          */  100,
        /*  u16RxWftMax     */  3,
        /*  u8STmin         */  10,   
        /*  udtRxIPduId     */  0x1,
        /*  udtTxFcLSduId    */  CanIf_CanTpTxNPdu_688
		
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 002 - CanTpChannel 00 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-004','2')                     */

/* Eval('CANTP-CRC-005','2')                     */

/* Eval('CANTP-CRC-008','2')                     */

/* Eval('CANTP-CRC-009','2')                     */

/* Eval('CANTP-CRC-012','2')                     */

/* Eval('CANTP-CRC-014','2')                     */

/* Eval('CANTP-CRC-015','2')                     */
  {
        /*  u8BlockSize     */  0,
        /*  u16NAr          */  100,
        /*  u16NBr          */  2,
        /*  u16NCr          */  100,
        /*  u16RxWftMax     */  3,
        /*  u8STmin         */  10,   
        /*  udtRxIPduId     */  0x0,
        /*  udtTxFcLSduId    */  CanIf_CanTpTxNPdu_7E8
		
    }
    ,
/******************************************************************************/
/********************* CanTpRxNSdu 003 - CanTpChannel 01 **********************/
/******************************************************************************/

/* Eval('CANTP-CRC-004','3')                     */

/* Eval('CANTP-CRC-005','3')                     */

/* Eval('CANTP-CRC-008','3')                     */

/* Eval('CANTP-CRC-009','3')                     */

/* Eval('CANTP-CRC-012','3')                     */

/* Eval('CANTP-CRC-014','3')                     */

/* Eval('CANTP-CRC-015','3')                     */
  {
        /*  u8BlockSize     */  0,
        /*  u16NAr          */  100,
        /*  u16NBr          */  2,
        /*  u16NCr          */  100,
        /*  u16RxWftMax     */  3,
        /*  u8STmin         */  10,   
        /*  udtRxIPduId     */  0x3,
        /*  udtTxFcLSduId    */  CanIf_CanTpTxNPdu_7E8
		
    }
    
};
/******************************************************************************/
/*  \ConfigTool     -An entry in akstrRxNSduPBCfg shall be created for each
                     instance of CanTpRxNSdu
                    -The entries must be ordered as in CanTp_akstreRxNSduPCCfg 
                     ascendingly based on the configuration parameter 
                     CanTpRxNSduId of each CanTpRxNSdu.                       */
/******************************************************************************/



/******************************************************************************/
/*! \Description    A Structure of type CanTp_ConfigType containing references
                    to all post-build configurations defined, in addition to
                    global CanTp post build configuration parameters.         */
/******************************************************************************/

static CONST(CanTp_ConfigType, CANTP_CALIB_CONST) kstrGlobalCfg01 = 
{
    /*  u32MainFunctionPeriod   */  10000,
    /*  pkstrRxNSduCfg          */  akstrRxNSduPBCfg,
    /*  pkstrTxNSduCfg          */  akstrTxNSduPBCfg
};




CONSTP2CONST(CanTp_ConfigType, CANTP_CALIB_CONST, CANTP_CALIB_CONST)
                          CanTp_akpkstreCanTpConfig[CanTp_u8NUM_OF_CONFIG_SETS] =
{
    &kstrGlobalCfg01
};



#define CANTP_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

/* Eval('CANTP-CRC-018','GENERAL')                     */

/* Eval('CANTP-CRC-019','GENERAL')                     */




/*-------------------------------- end of file -------------------------------*/

/* PRQA L:L1                                                                  */
