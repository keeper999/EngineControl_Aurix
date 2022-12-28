/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions declaration                                                                      */
/*                                                                                                                    */
/* !File            : CCPUSR.h                                                                                        */
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

#ifndef CCPUSR_H
#define CCPUSR_H

#include "Std_Types.h"
#include "ComStack_Types.h"
#include "CCPUSR_Cfg.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
#define CCPUSR_CAL_STORE_INIT				 1U
#define CCPUSR_CAL_STORE_REQUESTED		 2U
#define CCPUSR_CAL_STORE_WAIT_CONDITION 4U
#define CCPUSR_CAL_STORE_CONDITION_OK	 8U


/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/

#define CCP_START_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"

extern uint8 CCPUSR_enuCalStoreStatus;

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"


/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"

extern const uint32 CCPUSR_kau32WritableMemoryZone[2*CCPUSR_NB_WRITABLE_ZONE];
extern const uint32 CCPUSR_kau32ReadOnlyMemoryZone[2*CCPUSR_NB_READ_ONLY_ZONE];

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "Ccp_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

extern void CCPUSR_vidRxIndication(PduIdType RxPduId, PduInfoType *PduInfoPtr);
FUNC(void, CCP_USR_CODE) CCP_vidMainFunction(void);

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

#endif /* CCPUSR_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
