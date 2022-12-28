/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PFCMNG                                                  */
/* !Description     : PFCMNG Component                                        */
/*                                                                            */
/* !Module          : PFCMNG                                                  */
/* !Description     : PFC ConfigurationS                                      */
/*                                                                            */
/* !File            : PFCMNG_FCT1.C                                           */
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
/*   1 / PFCMNG_vidInitOutput                                                 */
/*   2 / PFCMNG_vidInit                                                       */
/*   3 / PFCMNG_vidCheckpoint                                                 */
/*   4 / PFCMNG_vidStatus                                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 06115 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PFCMNG.h"
#include "PFCMNG_L.h"
#include "PFCMNG_IM.h"
#include "GDGAR.h"
#include "WDGM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFCMNG_vidInitOutput                                       */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Sfty_bMonRunSftyChkPt_PfcMng;                              */
/*  output boolean Sfty_bDgoSftyChkPt_PfcMng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFCMNG_vidInitOutput(void)
{
   VEMS_vidSET(Sfty_bMonRunSftyChkPt_PfcMng, 0);
   VEMS_vidSET(Sfty_bDgoSftyChkPt_PfcMng, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFCMNG_vidInit                                             */
/* !Description :  Cette fonction configure le nombre de SEID, le nombre de   */
/*                 checkpoints et le timeout.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WdgM_Init(argin WdgM_ConfigType * ConfigPtr);            */
/*  input uint8 WDGM_NB_CHECKPOINT;                                           */
/*  input uint8 WDGM_TIMEOUT;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFCMNG_vidInit(void)
{
   WdgM_ConfigType       LocalStructConfiPtr;
   WdgM_CheckpointIdType auLocalpoints;
   uint16                au16LocalTimeout;


   auLocalpoints = (uint16)WDGM_NB_CHECKPOINT;
   au16LocalTimeout = (uint16)(WDGM_TIMEOUT / 10);

   LocalStructConfiPtr.udtNumberOfSE = (uint8)WDGM_NB_SEID;
   LocalStructConfiPtr.audtNumberOfCheckpoints = &auLocalpoints;
   LocalStructConfiPtr.au16Timeout = &au16LocalTimeout;

   WdgM_Init(&LocalStructConfiPtr);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFCMNG_vidCheckpoint                                       */
/* !Description :  Cette fonction incrémente le nombre de checkpoints         */
/*                 automatiquement après chaque appel de l'événement          */
/*                 checkpoint.                                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WdgM_CheckpointReached(argin WdgM_SupervisedEntityIdType */
/*  SEID, argin WdgM_CheckpointIdType CheckpointID)argout Std_ReturnType;     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFCMNG_vidCheckpoint
(
   WdgM_SupervisedEntityIdType u8LocalSEID,
   WdgM_CheckpointIdType u16LocalCheckpointID
)
{
   Std_ReturnType udtLocalRetCheckPointReached;
   /*Msg(3:3203) WdgM_CheckpointReached returns Std value*/

   udtLocalRetCheckPointReached =
      WdgM_CheckpointReached(u8LocalSEID, u16LocalCheckpointID);
   /*Msg(3:3199) WdgM_CheckpointReached returns Std value*/
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFCMNG_vidStatus                                           */
/* !Description :  A diagnosis concerning the logical sequence errors and     */
/*                 sequence timeout errors is realized for each SEID. If the  */
/*                 status is NOK, a failure flag is set to 1.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin boolean bIndexFRM);              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void WdgM_GetLocalStatus(argin WdgM_SupervisedEntityIdType    */
/* SEID, argout WdgM_LocalStatusType * Status) argout Std_ReturnType;         */
/*  output boolean Sfty_bMonRunSftyChkPt_PfcMng;                              */
/*  output boolean Sfty_bDgoSftyChkPt_PfcMng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFCMNG_vidStatus(void)
{
   boolean        bLocalFRM_bInhDiagchkpt_PfcMng;
   boolean        bLocalSftybMonRunSftyChkPtPfcMng;
   boolean        bLocalSfty_bDgoSftyChkPt_PfcMng;
   Std_ReturnType udtLocalGetLocalStatus;
   /*Msg(3:3203) WdgM_GetLocalStatus returns Std value*/
   uint8          u8LocalStatus;


   u8LocalStatus = 0;
   bLocalFRM_bInhDiagchkpt_PfcMng = GDGAR_bGetFRM(FRM_FRM_INHDIAGCHKPT_PFCMNG);
   if (bLocalFRM_bInhDiagchkpt_PfcMng != 0)
   {
      bLocalSftybMonRunSftyChkPtPfcMng = 0;
   }
   else
   {
      bLocalSftybMonRunSftyChkPtPfcMng = 1;
   }
   VEMS_vidSET(Sfty_bMonRunSftyChkPt_PfcMng, bLocalSftybMonRunSftyChkPtPfcMng);

   udtLocalGetLocalStatus = WdgM_GetLocalStatus(0, &u8LocalStatus);
   /*Msg(3:3199) WdgM_GetLocalStatus returns Std value*/
   if ((u8LocalStatus == WDGM_LOCAL_STATUS_FAILED))
   {
      bLocalSfty_bDgoSftyChkPt_PfcMng = 1;
   }
   else
   {
      bLocalSfty_bDgoSftyChkPt_PfcMng = 0;
   }
   VEMS_vidSET(Sfty_bDgoSftyChkPt_PfcMng, bLocalSfty_bDgoSftyChkPt_PfcMng);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------end-of-file-----------------------------------*/