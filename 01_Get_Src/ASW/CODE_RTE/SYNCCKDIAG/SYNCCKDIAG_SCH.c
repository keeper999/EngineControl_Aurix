/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKDIAG                                              */
/* !Description     : SYNCCKDIAG Component                                    */
/*                                                                            */
/* !Module          : SYNCCKDIAG                                              */
/* !Description     : STATUT ET DIAGNOSTIC DU SIGNAL VILEBREQUIN              */
/*                                                                            */
/* !File            : SYNCCKDIAG_SCH.C                                        */
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
/*   1 / Sync_SdlMid_CkDiagSts                                                */
/*   2 / Sync_EveRst_CkDiagSts                                                */
/*   3 / Sync_EveStTCr_CkDiagSts                                              */
/*   4 / Sync_EveStTR_CkDiagSts                                               */
/*   5 / Sync_EveCkSnOn_CkDiagSts                                             */
/*   6 / Sync_EveCkLTo_CkDiagSts                                              */
/*   7 / Sync_EveCkSnOf_CkDiagSts                                             */
/*   8 / Sync_EveRTCr_CkDiagSts                                               */
/*   9 / Sync_EveCrTSt_CkDiagSts                                              */
/*   10 / Sync_SdlSlow_CkDiagSts                                              */
/*   11 / Sync_EveKOn_CkDiagSts                                               */
/*   12 / Sync_SdlFast_CkDiagSts                                              */
/*   13 / Sync_EveCkOf_CkDiagSts                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6886036 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKDIAG/SYNCCKDIAG_SCH.C_v$*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "SYNCCKDIAG.h"
#include "SYNCCKDIAG_L.h"
#include "SYNCCKDIAG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlMid_CkDiagSts                                      */
/* !Description :  Monitor moyen de la fonction Sync                          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidEventGeneration();                         */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlMid_CkDiagSts                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlMid_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidEventGeneration();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CkDiagSts                                      */
/* !Description :  fonction  Reset                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  extf argret void SYNCCKDIAG_vidResetDiag();                               */
/*  extf argret void SYNCCKDIAG_vidInitSelectCkMode();                        */
/*  extf argret void SYNCCKDIAG_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CkDiagSts                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CkDiagSts(void)
{
   SYNCCKDIAG_vidCkStsAcq();
   SYNCCKDIAG_vidResetDiag();
   SYNCCKDIAG_vidInitSelectCkMode();
   SYNCCKDIAG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveStTCr_CkDiagSts                                    */
/* !Description :  Evenement correspondante à l'évenement STALL vers CRANKING */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveStTCr_CkDiagSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveStTCr_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveStTR_CkDiagSts                                     */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveStTR_CkDiagSts                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveStTR_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOn_CkDiagSts                                   */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise                                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCrkDgnUpdateInReq();                       */
/*  extf argret void SYNCCKDIAG_vidCrkLngLtoo1Diag();                         */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_CkDiagSts                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCrkDgnUpdateInReq();
      SYNCCKDIAG_vidCrkLngLtoo1Diag();
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkLTo_CkDiagSts                                    */
/* !Description :  Evénement correspondant au passage de la dent longue       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCrkDgnUpdateInReq();                       */
/*  extf argret void SYNCCKDIAG_vidCrkInvalTeethDiag();                       */
/*  extf argret void SYNCCKDIAG_vidCrkInvalToothDiag();                       */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkLTo_CkDiagSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkLTo_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCrkDgnUpdateInReq();
      SYNCCKDIAG_vidCrkInvalTeethDiag();
      SYNCCKDIAG_vidCrkInvalToothDiag();
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOf_CkDiagSts                                   */
/* !Description :  Evénement d'appel de tâche "synchro perdue" du CMM (à la   */
/*                 perte de synchro et au calage)                             */
/* !Number      :  SCH.7                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCrkDgnUpdateInReq();                       */
/*  extf argret void SYNCCKDIAG_vidCrkInvalTeethDiag();                       */
/*  extf argret void SYNCCKDIAG_vidCrkInvalToothDiag();                       */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOf_CkDiagSts                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOf_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCrkDgnUpdateInReq();
      SYNCCKDIAG_vidCrkInvalTeethDiag();
      SYNCCKDIAG_vidCrkInvalToothDiag();
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRTCr_CkDiagSts                                     */
/* !Description :  Evénement RUNNING vers CRANKING                            */
/* !Number      :  SCH.8                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRTCr_CkDiagSts                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRTCr_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCrTSt_CkDiagSts                                    */
/* !Description :  Evénement CRANKING vers STALL                              */
/* !Number      :  SCH.9                                                      */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCrTSt_CkDiagSts                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCrTSt_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_CkDiagSts                                     */
/* !Description :  Moniteur lent de la fonction Sync                          */
/* !Number      :  SCH.10                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkAcqVld();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlSlow_CkDiagSts                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkAcqVld();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveKOn_CkDiagSts                                      */
/* !Description :  Evènement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.11                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidInitSelectCkMode();                        */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveKOn_CkDiagSts                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidInitSelectCkMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlFast_CkDiagSts                                     */
/* !Description :  Moniteur rapide de la fonction Sync                        */
/* !Number      :  SCH.12                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidBackUpMode();                              */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlFast_CkDiagSts                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlFast_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidBackUpMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkOf_CkDiagSts                                     */
/* !Description :  EveCkOff                                                   */
/* !Number      :  SCH.13                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKDIAG_vidCkStsAcq();                                */
/*  input uint8 SYNCCKDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkOf_CkDiagSts                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkOf_CkDiagSts(void)
{
   if (SYNCCKDIAG_u8Inhib != 0x5A)
   {
      SYNCCKDIAG_vidCkStsAcq();
   }
}

/*------------------------------- end of file --------------------------------*/