/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CCP                                                     */
/*                                                                            */
/* !Module          : CCPUSR_CFG                                              */
/* !Description     : Configuration of the user part                          */
/*                                                                            */
/* !File            : CCPUSR_CFG.H                                            */
/*                                                                            */
/* !Scope           : Public                                                  */
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

#ifndef CCPUSR_CFG_H
#define CCPUSR_CFG_H

#include "CCP_Typ.h"
#include "CCP_Cfg.h"
#include "ComStack_Types.h"
#include "CanIf.h"
#include "CCPUSR_CanIf_Cfg.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CCPUSR_CANIF_DTO_TX_ID        CanIf_CCP_DTO
#define CCPUSR_CANIF_DEVAID_DTO_TX_ID CanIf_CCP_DEVAID_DTO
#define CCPUSR_DFLT_CALIB_PAGE_ADDR 0x80040084
#define CCPUSR_DFLT_CALIB_PAGE_EXTN 0


#define CCPUSR_NB_WRITABLE_ZONE 6
#define CCPUSR_NB_READ_ONLY_ZONE 4


/* Calibration areas infos */
#define CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_ROM 0x80040000
#define CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_RAM 0xBF000000
#define CCPUSR_CALIBRATION_SIZE                    0x80000

/* Tx Confirmation function for DAQ lists */
#define CCP_UsrTxConf_DAQ_10MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_Devaid_DAQ_10MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_DAQ_100MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_Devaid_DAQ_100MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_DAQ_1000MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_Devaid_DAQ_1000MS CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_DAQ_PMH CCPUSR_vidDaqListTxConf
#define CCP_UsrTxConf_Devaid_DAQ_PMH CCPUSR_vidDaqListTxConf



/* Tx Confirmation ID for DAQ lists = to daq list number */
#define CDD_CCP_10MS 0
#define CDD_CCP_DEVAID_10MS CDD_CCP_10MS
#define CDD_CCP_100MS 1
#define CDD_CCP_DEVAID_100MS CDD_CCP_100MS
#define CDD_CCP_1000MS 2
#define CDD_CCP_DEVAID_1000MS CDD_CCP_1000MS
#define CDD_CCP_PMH 3
#define CDD_CCP_DEVAID_PMH CDD_CCP_PMH



/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"

/* !Comment: CAN ID for all DAQ lists                                         */
extern CONST(PduIdType, CCP_CONST) CCPUSR_kaudtDaqMsgID[CCP_u8DAQ_NO_LISTS];
extern CONST(PduIdType, CCP_CONST) CCPUSR_kaudtDevaidDaqMsgID[CCP_u8DAQ_NO_LISTS];

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"


#endif /* CCPUSR_CFG_H */

/*-------------------------------- end of file -------------------------------*/