/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMAX                                             */
/* !Description     : ADDONADVMAX component                                   */
/*                                                                            */
/* !Module          : ADDONADVMAX                                             */
/* !Description     : Offset d'avance limite cliquetis                        */
/*                                                                            */
/* !File            : ADDONADVMAX_SCH.C                                       */
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
/*   1 / ADDONADVMAX_vidEntryInit                                             */
/*   2 / IgSys_EveTDC_AddOnAdvMax                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 01471 / 01                                        */
/* !OtherRefs   : 01460_10_01465_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053830                                         */
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
#include "ADDONADVMAX.h"
#include "ADDONADVMAX_L.h"
#include "ADDONADVMAX_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidEntryInit                                   */
/* !Description :  Evènement de reset du calculateur.                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMAX_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ADDONADVMAX_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidEntryInit(void)
{
   ADDONADVMAX_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveTDC_AddOnAdvMax                                   */
/* !Description :  Occurrence de calcul de la fonction AddOnAdvMax.           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMAX_vidOffset_Aamaxi();                          */
/*  input uint8 ADDONADVMAX_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveTDC_AddOnAdvMax                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveTDC_AddOnAdvMax(void)
{
   if (ADDONADVMAX_u8Inhib != 0x5A)
   {
      ADDONADVMAX_vidOffset_Aamaxi();
   }
}
/*---------------------------------end of file--------------------------------*/