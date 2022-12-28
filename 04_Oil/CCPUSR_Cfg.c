/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CCP                                                     */
/*                                                                            */
/* !Module          : CCPUSR_CFG                                              */
/* !Description     : Configuration of the user part                          */
/*                                                                            */
/* !File            : CCPUSR_CFG.C                                            */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::                                                               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* Generated on 11/10/14, 10:16:14 by Genecode v2.6.0.0                       */
/******************************************************************************/

#include "CCP.h"
#include "CCPUSR_Cfg.h"
#include "ComStack_Types.h"
#include "CanIf.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"

/* !Comment: CAN ID for all DAQ lists                                         */
CONST(PduIdType, CCP_CONST) CCPUSR_kaudtDaqMsgID[CCP_u8DAQ_NO_LISTS] =
{
   CanIf_CCP_10MS,
   CanIf_CCP_100MS,
   CanIf_CCP_1000MS,
   CanIf_CCP_PMH
};

/* !Comment: CAN ID for all DAQ lists for DEVAID                                        */
CONST(PduIdType, CCP_CONST) CCPUSR_kaudtDevaidDaqMsgID[CCP_u8DAQ_NO_LISTS] =
{
   CanIf_CCP_DEVAID_10MS,
   CanIf_CCP_DEVAID_100MS,
   CanIf_CCP_DEVAID_1000MS,
   CanIf_CCP_DEVAID_PMH
};

const uint32 CCPUSR_kau32WritableMemoryZone[2*CCPUSR_NB_WRITABLE_ZONE] =
{
   0x50000000,0x5001E000, /* RAM_CPU2 */
   0x60000000,0x6001E000, /* RAM_CPU1 */
   0x70000000,0x7001C000, /* RAM_CPU0 */
   0xB0000000,0xB0008000, /* LOCAL_RAM */
   0xBF000000,0xBF100000, /* EMEM */
   0xF0000000,0xFF120000, /* REGISTERS */
};

const uint32 CCPUSR_kau32ReadOnlyMemoryZone[2*CCPUSR_NB_READ_ONLY_ZONE] =
{
   0x80000000,0x80400000, /* ROM_CACHED */
   0xA0000000,0xA0400000, /* ROM */
   0xAF000000,0xAF100000, /* DATA_ROM_DF0 */
   0xAF110000,0xAF120000, /* DATA_ROM_DF1 */
};

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"

#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

/**********************************************************************************************************************/
/* !Description: Called by CanIf on CCP DAQ List frame transmission. We must send the next DAQ List frame             */
/**********************************************************************************************************************/

void CCP_vidUsrTxConfirmation_DAQ_10MS (void)
{
   CCP_vidDaqListTxMgr(CCP_u8DAQ_LST_DAQ_10MS);
}

void CCP_vidUsrTxConfirmation_DAQ_100MS (void)
{
   CCP_vidDaqListTxMgr(CCP_u8DAQ_LST_DAQ_100MS);
}

void CCP_vidUsrTxConfirmation_DAQ_1000MS (void)
{
   CCP_vidDaqListTxMgr(CCP_u8DAQ_LST_DAQ_1000MS);
}

void CCP_vidUsrTxConfirmation_DAQ_PMH (void)
{
   CCP_vidDaqListTxMgr(CCP_u8DAQ_LST_DAQ_PMH);
}




#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"


/*-------------------------------- end of file -------------------------------*/