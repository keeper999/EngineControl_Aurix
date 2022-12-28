/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILDIAG                                              */
/* !Description     : IGCOILDIAG component.                                   */
/*                                                                            */
/* !Module          : IGCOILDIAG                                              */
/* !Description     : DIAGNOSTIC DES BOBINES D’ALLUMAGE                       */
/*                                                                            */
/* !File            : IGCOILDIAG_SCH.C                                        */
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
/*   1 / IgCmd_EveICD_IgCoilDiag                                              */
/*   2 / IgCmd_SdlMid_IgCoilDiag                                              */
/*   3 / IgCmd_SdlFast_IgCoilDiag                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6719446 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGCOILDIAG/IGCOILDIAG_SCH.C_v     $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   04 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   04 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IGCOILDIAG.h"
#include "IGCOILDIAG_L.h"
#include "IGCOILDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_EveICD_IgCoilDiag                                    */
/* !Description :  Evénement de diagnostique du driver des bobines d'allumage */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILDIAG_vidCallDiagICD();                             */
/*  input uint8 IGCOILDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_EveICD_IgCoilDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_EveICD_IgCoilDiag(void)
{
   if (IGCOILDIAG_u8Inhib != 0x5A)
   {
      IGCOILDIAG_vidCallDiagICD();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlFast_IgCoilDiag                                   */
/* !Description :  Moniteur rapide de la fonction diagnostic IgCmd            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILDIAG_vidCallDiagSdlFast();                         */
/*  input uint8 IGCOILDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_SdlFast_IgCoilDiag                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlFast_IgCoilDiag(void)
{
   if (IGCOILDIAG_u8Inhib != 0x5A)
   {
      IGCOILDIAG_vidCallDiagSdlFast();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgCmd_SdlMid_IgCoilDiag                                    */
/* !Description :  Moniteur moyen de la fonction diagnostic IgCmd             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_05995_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILDIAG_vidCalcIcdDiagEnabled();                      */
/*  input uint8 IGCOILDIAG_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgCmd_SdlMid_IgCoilDiag                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgCmd_SdlMid_IgCoilDiag(void)
{
   if (IGCOILDIAG_u8Inhib != 0x5A)
   {
      IGCOILDIAG_vidCalcIcdDiagEnabled();
   }
}

/*---------------------------------end of file--------------------------------*/