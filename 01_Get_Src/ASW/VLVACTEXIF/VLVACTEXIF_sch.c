/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXIF                                              */
/* !Description     : VLVACTEXIF component                                    */
/*                                                                            */
/* !Module          : VLVACTEXIF                                              */
/* !Description     : INTERFACE D’ADAPTATION DES CONSIGNE ET MESURE AAC POUR  */
/*                    LA FONCTION VVT ECHAPPEMENT                             */
/*                                                                            */
/* !File            : VLVACTEXIF_SCH.C                                        */
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
/*   1 / VlvAct_EveRst_ExIf                                                   */
/*   2 / VlvAct_EveExCmToo_ExIf                                               */
/*   3 / VlvAct_SdlFast_ExIf_1                                                */
/*   4 / VlvAct_SdlFast_ExIf_2                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5320145 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXIF/VLVACTEXIF_S$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   19 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXIF.h"
#include "VLVACTEXIF_L.h"
#include "VLVACTEXIF_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExIf                                         */
/* !Description :  Fonction d'accroche moniteur à l'évenement Reset           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06205_004.01                                     */
/*                 VEMS_E_08_06205_005.01                                     */
/*                 VEMS_E_08_06205_006.01                                     */
/*                 VEMS_R_08_06205_002.01                                     */
/*                 VEMS_R_08_06205_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXIF_vidInitOutput();                              */
/*  extf argret void VLVACTEXIF_vidInitialisation();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExIf                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExIf(void)
{
   VLVACTEXIF_vidInitOutput();
   VLVACTEXIF_vidInitialisation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCmToo_ExIf                                     */
/* !Description :  Evènement dent AAC échappement                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06205_004.01                                     */
/*                 VEMS_E_08_06205_005.01                                     */
/*                 VEMS_E_08_06205_006.01                                     */
/*                 VEMS_R_08_06205_002.01                                     */
/*                 VEMS_R_08_06205_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXIF_vidVVTToothErrDet();                          */
/*  input uint8 VLVACTEXIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCmToo_ExIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCmToo_ExIf(void)
{
   if (VLVACTEXIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXIF_vidVVTToothErrDet();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExIf_1                                      */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06205_004.01                                     */
/*                 VEMS_E_08_06205_005.01                                     */
/*                 VEMS_E_08_06205_006.01                                     */
/*                 VEMS_R_08_06205_002.01                                     */
/*                 VEMS_R_08_06205_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXIF_vidVVTPosition();                             */
/*  input uint8 VLVACTEXIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExIf_1                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExIf_1(void)
{
   if (VLVACTEXIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXIF_vidVVTPosition();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExIf_2                                      */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06205_004.01                                     */
/*                 VEMS_E_08_06205_005.01                                     */
/*                 VEMS_E_08_06205_006.01                                     */
/*                 VEMS_R_08_06205_002.01                                     */
/*                 VEMS_R_08_06205_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXIF_vidVVTSetpoint();                             */
/*  input uint8 VLVACTEXIF_u8Inhib;                                           */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExIf_2                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExIf_2(void)
{
   if (VLVACTEXIF_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXIF_vidVVTSetpoint();
      }
   }
}
/*-------------------------------- end of file -------------------------------*/