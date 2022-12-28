/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkDetRbl                                               */
/* !Description     : KnkDetRbl component.                                    */
/*                                                                            */
/* !Module          : KnkDetRbl                                               */
/* !Description     : RUMBLE DETECTION                                        */
/*                                                                            */
/* !File            : KNKDETRBL_SCH.C                                         */
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
/*   1 / KnkTreat_EveRst_KnkDetRbl                                            */
/*   2 / KnkTreat_EveCkSnOn_KnkDetRbl                                         */
/*   3 / KnkTreat_EveRbl_KnkDetRbl                                            */
/*   4 / KnkTreat_SdlSlow_KnkDetRbl                                           */
/*   5 / KnkTreat_SdlMid_KnkDetRbl                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5068340 / 09                                        */
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
#include "KnkDetRbl.h"
#include "KnkDetRbl_L.h"
#include "KnkDetRbl_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkDetRbl                                  */
/* !Description :  tache reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_001.02                                     */
/*                 VEMS_E_10_02581_003.02                                     */
/*                 VEMS_E_10_02581_004.01                                     */
/*                 VEMS_E_10_02581_005.02                                     */
/*                 VEMS_E_10_02581_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDETRBL_vidInit();                                     */
/*  extf argret void KnkDetRbl_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkDetRbl                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkDetRbl(void)
{
   KNKDETRBL_vidInit();
   KnkDetRbl_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCkSnOn_KnkDetRbl                               */
/* !Description :  Tache tournant synchro (démarrage, calage perte de synchro)*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_001.02                                     */
/*                 VEMS_E_10_02581_003.02                                     */
/*                 VEMS_E_10_02581_004.01                                     */
/*                 VEMS_E_10_02581_005.02                                     */
/*                 VEMS_E_10_02581_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKDETRBL_vidReinitTacheSynchRbl();                      */
/*  input uint8 KnkDetRbl_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCkSnOn_KnkDetRbl                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCkSnOn_KnkDetRbl(void)
{
   if (KnkDetRbl_u8Inhib != 0x5A)
   {
      KNKDETRBL_vidReinitTacheSynchRbl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_KnkDetRbl                                  */
/* !Description :  Tâche rumble                                               */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_001.02                                     */
/*                 VEMS_E_10_02581_003.02                                     */
/*                 VEMS_E_10_02581_004.01                                     */
/*                 VEMS_E_10_02581_005.02                                     */
/*                 VEMS_E_10_02581_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkDetRbl_vidTache_rumble();                             */
/*  input uint8 KnkDetRbl_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_KnkDetRbl                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_KnkDetRbl(void)
{
   if (KnkDetRbl_u8Inhib != 0x5A)
   {
      KnkDetRbl_vidTache_rumble();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlSlow_KnkDetRbl                                 */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.4                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_001.02                                     */
/*                 VEMS_E_10_02581_003.02                                     */
/*                 VEMS_E_10_02581_004.01                                     */
/*                 VEMS_E_10_02581_005.02                                     */
/*                 VEMS_E_10_02581_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkDetRbl_vidCalcFactFiltrageN();                        */
/*  input uint8 KnkDetRbl_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlSlow_KnkDetRbl                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlSlow_KnkDetRbl(void)
{
   if (KnkDetRbl_u8Inhib != 0x5A)
   {
      KnkDetRbl_vidCalcFactFiltrageN();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_SdlMid_KnkDetRbl                                  */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.5                                                      */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_E_10_02581_001.02                                     */
/*                 VEMS_E_10_02581_003.02                                     */
/*                 VEMS_E_10_02581_004.01                                     */
/*                 VEMS_E_10_02581_005.02                                     */
/*                 VEMS_E_10_02581_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkDetRbl_vidCalcFactFiltrLoad();                        */
/*  input uint8 KnkDetRbl_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_SdlMid_KnkDetRbl                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_SdlMid_KnkDetRbl(void)
{
   if (KnkDetRbl_u8Inhib != 0x5A)
   {
      KnkDetRbl_vidCalcFactFiltrLoad();
   }
}
/*-------------------------------- end of file -------------------------------*/