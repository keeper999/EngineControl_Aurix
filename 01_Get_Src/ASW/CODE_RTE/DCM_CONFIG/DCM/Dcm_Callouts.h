/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm_Callouts.h                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   I:/PROJETS/LIBEMB/LOG/COM/DCM/LOG/Dcm_Callouts.h_v           $*/
/* $Revision::   1.6      $$Author::   lvoilmy        $$Date::   22 Nov 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DCM_CALLOUTS_H
#define DCM_CALLOUTS_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "ComStack_Types.h"
#include "Dcm_Types.h"
#include "Dcm_Cfg.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description The Dcm_ReadMemory callout is used to request memory data 
                 identified by the parameter memoryAddress and memorySize.
                 This service is needed for the implementation of UDS services: 
                   - ReadMemoryByAdress 
                   - RequestUpload 
                   - ReadDataByIdentifier (in case of Dynamical DID defined by 
                     memory address) 
*******************************************************************************/
extern Dcm_ReturnReadMemoryType Dcm_ReadMemory(
  uint8 MemoryIdentifier, 
  uint32 MemoryAddress, 
  uint32 MemorySize, 
  uint8* MemoryData 
);

/******************************************************************************/
/*! \Description The Dcm_WriteMemory callout is used to write memory data 
                 identified by the parameter memoryAddress and memorySize.
                 This service is needed for the mplementation of UDS services:
                   - WriteMemoryByAdress 
                   - RequestDownload 
                   - WriteDataByIdentifier (in case of Dynamical DID defined by 
                     memory address) 
*******************************************************************************/
extern Dcm_ReturnWriteMemoryType Dcm_WriteMemory( 
    uint8 MemoryIdentifier, 
    uint32 MemoryAddress, 
    uint32 MemorySize, 
    uint8* MemoryData 
);

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/******************************************************************************/
/*! \Description The Dcm_SetProgConditions callout allows the integrator to 
                 store relevant information prior to jumping to bootloader.
                 The context parameter are defined in Dcm_ProgConditionsType
*******************************************************************************/
extern Std_ReturnType Dcm_SetProgConditions( 
    Dcm_ProgConditionsType * ProgConditions 
);

/******************************************************************************/
/*! \Description The Dcm_GetProgConditions callout is called upon DCM
                 initialization and allows to determine if a response ($50 or 
                 $51) has to be sent depending on request within the 
                 bootloader. The context parameter are defined in 
                 Dcm_ProgConditionsType
*******************************************************************************/
extern Dcm_EcuStartModeType Dcm_GetProgConditions( 
    Dcm_ProgConditionsType * ProgConditions 
);
#endif

#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
/******************************************************************************/
/*! \Description This function confirms thesuccessful transmission or a 
                 transmission error of a diagnostic service. 
                 The idContext and the dcmRxPduId are required to identify the 
                 message which was processed.
*******************************************************************************/
FUNC(void,DCM_CODE) Dcm_Confirmation(Dcm_IdContextType idContext,
                       PduIdType dcmRxPduId,Dcm_ConfirmationStatusType status);

#endif

/******************************************************************************/
/*! \Description Called by Dcm upon going into the default session. 
                 The integrator should implement this callout in order to stop
                 the running routines.
*******************************************************************************/
extern FUNC(void,DCM_CODE) Dcm_vidStopAllRoutines(void);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DCM_CALLOUTS_H */
