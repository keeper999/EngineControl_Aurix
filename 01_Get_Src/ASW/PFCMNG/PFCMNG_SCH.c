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
/* !File            : PFCMNG_SCH.C                                            */
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
/*   1 / Sfty_EveRst_PfcMng                                                   */
/*   2 / Sfty_SdlMid_PfcMng                                                   */
/*   3 / Sfty_SdlMid_PfcMng_Chk                                               */
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
#include "PFCMNG_IM.h"
#include "PFCMNG_L.h"
#include "GDGAR.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_EveRst_PfcMng                                         */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_11_06115_001.01                                     */
/*                 VEMS_E_11_06115_002.01                                     */
/*                 VEMS_E_11_06115_003.01                                     */
/*                 VEMS_E_11_06115_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFCMNG_vidInit();                                        */
/*  extf argret void PFCMNG_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_EveRst_PfcMng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_EveRst_PfcMng(void)
{
   PFCMNG_vidInit();
   PFCMNG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_SdlMid_PfcMng                                         */
/* !Description :  Middle scheduler of the function                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_11_06115_001.01                                     */
/*                 VEMS_E_11_06115_002.01                                     */
/*                 VEMS_E_11_06115_003.01                                     */
/*                 VEMS_E_11_06115_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFCMNG_vidStatus();                                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input uint8 PFCMNG_u8Inhib;                                               */
/*  input boolean Sfty_bDgoSftyChkPt_PfcMng;                                  */
/*  input boolean Sfty_bMonRunSftyChkPt_PfcMng;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_SdlMid_PfcMng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_SdlMid_PfcMng(void)
{
   boolean bLocalSfty_bDgoSftyChkPt_PfcMng;
   boolean bLocalSftybMonRunSftyChkPtPfcMng;


   if (PFCMNG_u8Inhib != 0x5A)
   {
      PFCMNG_vidStatus();
      VEMS_vidGET(Sfty_bDgoSftyChkPt_PfcMng, bLocalSfty_bDgoSftyChkPt_PfcMng);
      VEMS_vidGET(Sfty_bMonRunSftyChkPt_PfcMng,
                  bLocalSftybMonRunSftyChkPtPfcMng);
      GDGAR_vidGdu(GD_DFT_SFTYCHKPT_PFCMNG,
                   bLocalSfty_bDgoSftyChkPt_PfcMng,
                   bLocalSftybMonRunSftyChkPtPfcMng,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sfty_SdlMid_PfcMng_Chk                                     */
/* !Description :  Actual SEID and checkpoint call event                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_11_06115_001.01                                     */
/*                 VEMS_E_11_06115_002.01                                     */
/*                 VEMS_E_11_06115_003.01                                     */
/*                 VEMS_E_11_06115_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFCMNG_vidCheckpoint(argin WdgM_SupervisedEntityIdType   */
/*  u8LocalSEID, argin WdgM_CheckpointIdType u16LocalCheckpointID);           */
/*  input uint8 PFCMNG_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sfty_SdlMid_PfcMng_Chk                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sfty_SdlMid_PfcMng_Chk
(
   WdgM_SupervisedEntityIdType u8LocalSEID,
   WdgM_CheckpointIdType u16LocalCheckpointID
)
{
   if (PFCMNG_u8Inhib != 0x5A)
   {
      PFCMNG_vidCheckpoint(u8LocalSEID, u16LocalCheckpointID);
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------end-of-file-----------------------------------*/