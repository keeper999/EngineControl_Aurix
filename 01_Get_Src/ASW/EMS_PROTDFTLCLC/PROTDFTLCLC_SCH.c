/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTDFTLCLC                                             */
/* !Description     : PROTDFTLCLC component.                                  */
/*                                                                            */
/* !Module          : PROTDFTLCLC                                             */
/* !Description     : Protection Differentiel et Surchauffe Frein             */
/*                                                                            */
/* !File            : PROTDFTLCLC_SCH.C                                       */
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
/*   1 / PROTDFTLCLC_vidEntryInit                                             */
/*   2 / CoPt_Sdl10ms_ProtDftlClc                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 04686 / 01                                        */
/* !OtherRefs   : 01460_10_02301 / 1.2                                        */
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

#include "PROTDFTLCLC.h"
#include "PROTDFTLCLC_L.h"
#include "PROTDFTLCLC_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidEntryInit                                   */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_04686_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTDFTLCLC_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PROTDFTLCLC_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidEntryInit(void)
{
   PROTDFTLCLC_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoPt_Sdl10ms_ProtDftlClc                                   */
/* !Description :  Fonction d'accroche au moniteur 10ms                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_04686_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTDFTLCLC_vidEstimSollicitDiff();                      */
/*  extf argret void PROTDFTLCLC_vidDetActLimitCouple();                      */
/*  extf argret void PROTDFTLCLC_vidDetCoupleProtDiff();                      */
/*  extf argret void PROTDFTLCLC_vidDetCouplProtFrein();                      */
/*  extf argret void PROTDFTLCLC_vidCoordCouplLimit();                        */
/*  input uint8 PROTDFTLCLC_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoPt_Sdl10ms_ProtDftlClc                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoPt_Sdl10ms_ProtDftlClc(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (PROTDFTLCLC_u8Inhib != 0x5A)
   {
      PROTDFTLCLC_vidEstimSollicitDiff();
      PROTDFTLCLC_vidDetActLimitCouple();
      PROTDFTLCLC_vidDetCoupleProtDiff();
      PROTDFTLCLC_vidDetCouplProtFrein();
      PROTDFTLCLC_vidCoordCouplLimit();
   }
}
/*------------------------------end-of-file-----------------------------------*/