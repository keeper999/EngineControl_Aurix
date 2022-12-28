/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : Dlt_RID.h                                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dlt                                                     */
/* !Description     : Dlt                                                     */
/*                                                                            */
/* !Module          : Dlt                                                     */
/* !Description     : Dlt                                                     */
/*                                                                            */
/* !File            : Dlt_RID.h                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
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
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad        $$Date::   22 May 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DLT_RID_H_
#define DLT_RID_H_

#include "STD_TYPES.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

extern Std_ReturnType DLT_RequestResult_DFD2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFD2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFD2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDE
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDE
(
   uint8 *Choix_Actionneur,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDE
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDF
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDF
(
   uint8 *Choix_Bobinne,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDF
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE1
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE1
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE1
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE6
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE6
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE6
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE7
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE7
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE7
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE8
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE8
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE8
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE9
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE9
(
   uint8 *Choix_BlowBy,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE9
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFEA
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFEA
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFEA
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFEC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFEC
(
   uint8 *Choix_Vitesse,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFEC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFED
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFED
(
   uint8 *Choix_Cylindre,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFED
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFEE
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFEE
(
   uint8 *Choix_Sonde,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFEE
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFEF
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFEF
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFEF
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_0302
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_0302
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFAD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFAD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Pression_Rail,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Pression_Rail,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Pression_Rail,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_0400
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_0400
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFA0
(
   uint8 Cntrl_Inhibition,
   uint16 Tool_Signature,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8 *Statut_Lecture,
   uint8 *Tab_IUPR,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8 *Statut_Lecture,
   uint8 *Tab_IUPR,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DF22
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_F000
(
   uint8 Param_1,
   uint8 Param_2,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFCA
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFCA
(
   uint8 Cntrl_ModeSTT,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFE2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Param_Supl,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFE2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFE2
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF20
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF20
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF28
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF28
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF2A
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF2A
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF2C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF2C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF2D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF2D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFA1
(
   uint8 Cntrl_Inhibition,
   uint16 Tool_Signature,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFAD
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFAC
(
   uint32 Code_Antidemarrage,
   uint8* Option_Appairage,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Problem_Value,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFAE
(
   uint8 *Code_Antidemarrage,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint8 *Problem_Value,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);


extern Std_ReturnType DLT_RequestResult_DF15
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF15
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF1C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF1C
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF0D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF0D
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF34
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF34
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF08
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF08
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF10
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF10
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF11
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF11
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF35
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF35
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFC7
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFC7
(
   uint8 Cntrl_ModeSTT,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFC8
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFC8
(
   uint8 Cntrl_ModeSTT,
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   Dcm_NegativeResponseCodeType *ErrorCode
);

/* RIDs pour SC4 */
extern Std_ReturnType DLT_RequestResult_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFCC
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFEB
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDB
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   uint8* Param_Supl,
   uint16* currentDataLength,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StopRoutine_DFDA
(
   Dcm_OpStatusType OpStatus,
   uint8 *State_Routine,
   uint16 *currentDataLength,
   Dcm_NegativeResponseCodeType *ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF33
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF33
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF36 
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF36 
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DF37
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_RequestResult_DF37
(
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);

extern Std_ReturnType DLT_StartRoutine_DFA2
(
   uint8 Cntrl_Inhibition,
   uint16 Tool_Signature,
   Dcm_OpStatusType OpStatus,
   uint8* State_Routine,
   Dcm_NegativeResponseCodeType* ErrorCode
);


#endif /* DLT_RID_H_ */