/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINIF                                              */
/* !Description     : VLVACTINIF component                                    */
/*                                                                            */
/* !Module          : VLVACTINIF                                              */
/* !Description     : INTERFACE D’ADAPTATION DES CONSIGNE ET MESURE AAC POUR  */
/*                    LA FONCTION VVT ADMISSION                               */
/*                                                                            */
/* !File            : VLVACTINIF_SCH.C                                        */
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
/*   1 / VlvAct_EveRst_InIf                                                   */
/*   2 / VlvAct_EveInCmToo_InIf                                               */
/*   3 / VlvAct_SdlFast_InIf_1                                                */
/*   4 / VlvAct_SdlFast_InIf_2                                                */
/*   5 / VlvAct_SdlFast_InIf_3                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5320155 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINIF/VLVACTINIF_S$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   19 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINIF.h"
#include "VLVACTINIF_L.h"
#include "VLVACTINIF_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InIf                                         */
/* !Description :  Evènement reset du calculateur .                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_002.01                                     */
/*                 VEMS_R_08_06183_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidInitOutput();                              */
/*  extf argret void VLVACTINIF_vidInitialisation();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InIf                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InIf(void)
{
   VLVACTINIF_vidInitOutput();
   VLVACTINIF_vidInitialisation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCmToo_InIf                                     */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_002.01                                     */
/*                 VEMS_R_08_06183_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidVVTToothErrDet();                          */
/*  input uint8 VLVACTINIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCmToo_InIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCmToo_InIf(void)
{
   if (VLVACTINIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINIF_vidVVTToothErrDet();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InIf_1                                      */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_002.01                                     */
/*                 VEMS_R_08_06183_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidVVTPosition();                             */
/*  input uint8 VLVACTINIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InIf_1                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InIf_1(void)
{
   if (VLVACTINIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINIF_vidVVTPosition();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InIf_2                                      */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_002.01                                     */
/*                 VEMS_R_08_06183_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidVVTSetpoint();                             */
/*  input uint8 VLVACTINIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InIf_2                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InIf_2(void)
{
   if (VLVACTINIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C !=0)
      {
         VLVACTINIF_vidVVTSetpoint();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InIf_3                                      */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.5                                                      */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_R_08_06183_002.01                                     */
/*                 VEMS_R_08_06183_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINIF_vidVVTDiagInhFlagCal();                       */
/*  input uint8 VLVACTINIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :    VlvAct_SdlFast_InIf_3                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InIf_3(void)
{
   if (VLVACTINIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINIF_vidVVTDiagInhFlagCal();
      }
   }
}
/*-------------------------------- end of file -------------------------------*/