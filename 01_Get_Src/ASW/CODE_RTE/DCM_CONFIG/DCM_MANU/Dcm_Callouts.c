/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : Dcm_Callouts.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Dcm_ReadMemory                                                       */
/*   2 / Dcm_WriteMemory                                                      */
/*   3 / Dcm_SetProgConditions                                                */
/*   4 / Dcm_GetProgConditions                                                */
/*   5 / Dcm_Confirmation                                                     */
/*   6 / Dcm_vidStopAllRoutines                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dcm$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "Dcm.h"
#include "Dcm_Cfg.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dcm_ReadMemory                                             */
/* !Description :  The Dcm_ReadMemory callout is used to request memory data  */
/*                 identified by the parameter memoryAddress and memorySize.  */
/*                 This service is needed for the implementation of UDS       */
/*                 services: ReadMemoryByAdress, RequestUpload,               */
/*                 ReadDataByIdentifier.                                      */
/* !Number      :  Dcm_Callouts.1                                             */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dcm_ReturnReadMemoryType Dcm_ReadMemory
(
   uint8 MemoryIdentifier,
   uint32 MemoryAddress,
   uint32 MemorySize,
   uint8* MemoryData
)
{
   return (Dcm_ReturnReadMemoryType)0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dcm_WriteMemory                                            */
/* !Description :  The Dcm_WriteMemory callout is used to write memory data   */
/*                 identified by the parameter memoryAddress and memorySize.  */
/*                 This service is needed for the mplementation of UDS        */
/*                 services: WriteMemoryByAdress, RequestDownload,            */
/*                 WriteDataByIdentifier.                                     */
/* !Number      :  Dcm_WriteMemory.2                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dcm_ReturnWriteMemoryType Dcm_WriteMemory
(
   uint8 MemoryIdentifier,
   uint32 MemoryAddress,
   uint32 MemorySize,
   uint8* MemoryData
)
{
   return (Dcm_ReturnWriteMemoryType)0;
}

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType Dcm_SetProgConditions
(
   Dcm_ProgConditionsType* ProgConditions
)
{
  return (Std_ReturnType)0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Dcm_EcuStartModeType Dcm_GetProgConditions
(
   Dcm_ProgConditionsType* ProgConditions
)
{
  return (Dcm_EcuStartModeType)0;
}
#endif

#if(DCM_bDIAG_SERV_IS_CALLOUT == STD_ON)
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dcm_Confirmation                                           */
/* !Description :  This function confirms thesuccessful transmission or a     */
/*                 transmission error of a diagnostic service. The idContext  */
/*                 and the dcmRxPduId are required to identify the message    */
/*                 which was processed.                                       */
/* !Number      :  DCM_CALLOUTS.5                                             */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Dcm_Confirmation
(
   Dcm_IdContextType idContext,
   PduIdType dcmRxPduId,
   Dcm_ConfirmationStatusType status
)
{
}
#endif

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Dcm_vidStopAllRoutines                                     */
/* !Description :  Called by Dcm upon going into the default session. The     */
/*                 integrator should implement this callout in order to stop  */
/*                 the running routines.                                      */
/* !Number      :  DCM_CALLOUTS.6                                             */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_EveSessChg();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Dcm_vidStopAllRoutines(void)
{
   /* stop all running routines */
   DCM_MANU_EveSessChg();
}
