/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMIN                                             */
/* !Description     : ADDONADVMIN component                                   */
/*                                                                            */
/* !Module          : ADDONADVMIN                                             */
/* !Description     : Offset d'avance minimale                                */
/*                                                                            */
/* !File            : ADDONADVMIN_SCH.c                                       */
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
/*   1 / ADDONADVMIN_vidEntryInit                                             */
/*   2 / IgSys_EveTDC_AddOnAdvMin                                             */
/*                                                                            */
/* !Reference   : V02 NT 11 01472 / 01                                        */
/* !OtherRefs   : 01460_10_01466_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
/* !OtherRefs   : VEMS V02 ECU#053831                                         */
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
#include "ADDONADVMIN.h"
#include "ADDONADVMIN_L.h"
#include "ADDONADVMIN_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidEntryInit                                   */
/* !Description :  Evènement de reset du calculateur.                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMIN_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : ADDONADVMIN_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidEntryInit(void)
{
   ADDONADVMIN_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgSys_EveTDC_AddOnAdvMin                                   */
/* !Description :  Occurrence de calcul de la fonction AddOnAdvMin.           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONADVMIN_vidOffset_Aamini();                          */
/*  input uint8 ADDONADVMIN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IgSys_EveTDC_AddOnAdvMin                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgSys_EveTDC_AddOnAdvMin(void)
{
   if (ADDONADVMIN_u8Inhib != 0x5A)
   {
      ADDONADVMIN_vidOffset_Aamini();
   }
}
/*---------------------------------end of file--------------------------------*/