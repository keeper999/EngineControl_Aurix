/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions declaration                                                                      */
/*                                                                                                                    */
/* !File            : CCPUSR_CanIf_Cfg.h                                                                              */
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

#ifndef CCPUSR_CANIF_CFG_H
#define CCPUSR_CANIF_CFG_H

#include "Std_Types.h"
#include "CanIf.h"
#include "CCPUSR_Cfg.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* To be removed when Tresos Configuration will allow it */
#define CDD_CCP_DTO        0  /* To be removed when Tresos Configuration will allow it */
#define CDD_CCP_DEVAID_DTO 0  /* To be removed when Tresos Configuration will allow it */

#define CDD_CCP_CRO        0 /* not used except for CanIf */
#define CDD_CCP_DEVAID_CRO 1 /* not used except for CanIf */


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

extern void CCP_UsrTxConf_DTO(PduIdType CanTxPduId); /* To be removed when Tresos Configuration will allow it */
extern void CCP_UsrTxConf_Devaid_DTO(PduIdType CanTxPduId); /* To be removed when Tresos Configuration will allow it */

extern void CCP_UsrRxInd_CRO(PduIdType RxPduId, PduInfoType *PduInfoPtr);
extern void CCP_UsrRxInd_Devaid_CRO(PduIdType RxPduId, PduInfoType *PduInfoPtr);

extern void CCPUSR_vidDaqListTxConf(PduIdType CanTxPduId);

extern void CCPUSR_vidSendDaqMessage(uint8 u8DaqId, const uint8 aku8Data[8]);

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

#endif /* CCPUSR_CANIF_CFG_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
