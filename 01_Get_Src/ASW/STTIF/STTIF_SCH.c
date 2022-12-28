/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTIF                                                   */
/* !Description     : STTIF component.                                        */
/*                                                                            */
/* !Module          : STTIF                                                   */
/* !Description     : Spécification d’interface pour la fonction STT          */
/*                                                                            */
/* !File            : STTIF_SCH.C                                             */
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
/*   1 / InjCutOff_EveRst_CutOffIf                                            */
/*   2 / InjCutOff_SdlFast_CutOffIf                                           */
/*   3 / InjCutOff_EveInj_CutOffIf                                            */
/*   4 / Sync_EveRst_CkMngIfIf_2                                              */
/*   5 / Sync_EveRTSt_CkMngIfIf_2                                             */
/*   6 / Sync_EveTDC_CkMngIfIf_2                                              */
/*   7 / Sync_EveCkSnOn_CkMngIfIf_2                                           */
/*   8 / Sync_EveBDC_CkMngIfIf_2                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5199315 / 01                                        */
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
#include "STTIF.h"
#include "STTIF_L.h"
#include "STTIF_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCutOff_EveRst_CutOffIf                                  */
/* !Description :  Evènement reset.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidInjCutOff();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCutOff_EveRst_CutOffIf                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCutOff_EveRst_CutOffIf(void)
{
   STTIF_vidInjCutOff();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCutOff_SdlFast_CutOffIf                                 */
/* !Description :  Scheduler rapide.                                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidInjCutOff();                                    */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCutOff_SdlFast_CutOffIf                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCutOff_SdlFast_CutOffIf(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidInjCutOff();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCutOff_EveInj_CutOffIf                                  */
/* !Description :  Evènement injection.                                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidInjCutOff();                                    */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCutOff_EveInj_CutOffIf                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCutOff_EveInj_CutOffIf(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidInjCutOff();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CkMngIfIf_2                                    */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidOutput_nEng();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CkMngIfIf_2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CkMngIfIf_2(void)
{
   STTIF_vidOutput_nEng();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRTSt_CkMngIfIf_2                                   */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidOutput_nEng();                                  */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRTSt_CkMngIfIf_2                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRTSt_CkMngIfIf_2(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidOutput_nEng();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveTDC_CkMngIfIf_2                                    */
/* !Description :  Interruption PMH.                                          */
/* !Number      :  SCH.6                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidOutput_nEng();                                  */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveTDC_CkMngIfIf_2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveTDC_CkMngIfIf_2(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidOutput_nEng();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveCkSnOn_CkMngIfIf_2                                 */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_synchronise.                                        */
/* !Number      :  SCH.7                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidOutput_nEng();                                  */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveCkSnOn_CkMngIfIf_2                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveCkSnOn_CkMngIfIf_2(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidOutput_nEng();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveBDC_CkMngIfIf_2                                    */
/* !Description :  Interruption PMB.                                          */
/* !Number      :  SCH.8                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_12_01296_001.01                                     */
/*                 VEMS_E_12_01296_002.01                                     */
/*                 VEMS_E_12_01296_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTIF_vidOutput_nEng();                                  */
/*  input uint8 STTIF_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveBDC_CkMngIfIf_2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveBDC_CkMngIfIf_2(void)
{
   if (STTIF_u8Inhib != 0x5A)
   {
      STTIF_vidOutput_nEng();
   }
}
/****************************** end of file ***********************************/