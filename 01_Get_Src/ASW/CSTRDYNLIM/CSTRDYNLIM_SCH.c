/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRDYNLIM                                              */
/* !Description     : CSTRDYNLIM component.                                   */
/*                                                                            */
/* !Module          : CSTRDYNLIM                                              */
/* !Description     : BORNAGE DYNAMIQUE DE DEBIT PURGE                        */
/*                                                                            */
/* !File            : CSTRDYNLIM_SCH.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Cstr_EveRst_CstrDynLim                                               */
/*   2 / Cstr_SdlMid_CstrDynLim                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5205503 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CSTR/CSTRDYNLIM/CSTRDYNLIM_SCH.C$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   22 May 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   22 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_Types.h"
#include "CSTRDYNLIM.h"
#include "CSTRDYNLIM_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_CstrDynLim                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_09_01456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRDYNLIM_vidInitOutput();                              */
/*  extf argret void CSTRDYNLIM_vidDynLimClc();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_CstrDynLim                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_CstrDynLim(void)
{
   CSTRDYNLIM_vidInitOutput();
   CSTRDYNLIM_vidDynLimClc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlMid_CstrDynLim                                     */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_09_01456_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRDYNLIM_vidDynLimClc();                               */
/*  input uint8 CSTRDYNLIM_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlMid_CstrDynLim                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlMid_CstrDynLim(void)
{
   if (CSTRDYNLIM_u8Inhib != 0x5A)
   {
      CSTRDYNLIM_vidDynLimClc();
   }
}
/*------------------------------- end of file --------------------------------*/