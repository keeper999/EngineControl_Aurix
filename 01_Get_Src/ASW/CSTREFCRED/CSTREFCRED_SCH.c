/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTREFCRED                                              */
/* !Description     : CSTREFCRED component                                    */
/*                                                                            */
/* !Module          : CSTREFCRED                                              */
/* !Description     : DEGRADATION DE RENDEMENT AU RALENTI POUR LA PURGE       */
/*                                                                            */
/* !File            : CSTREFCRED_SCH.C                                        */
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
/*   1 / Cstr_EveRst_CstrEfcRed                                               */
/*   2 / Cstr_SdlFast_CstrEfcRed                                              */
/*   3 / Cstr_EveCrTR_CstrEfcRed                                              */
/*   4 / Cstr_SdlSlow_CstrEfcRed                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 01759 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTREFCRED/CSTREFCRED_SCH.C_v$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   26 Aug 2010 $*/
/* $Author::   hmelloul                               $$Date::   26 Aug 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CSTREFCRED.H"
#include "CSTREFCRED_L.H"
#include "CSTREFCRED_IM.H"




/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_CstrEfcRed                                     */
/* !Description :  Fonction d'accroche à l'evenement  Cstr_EveRst_CstrEfcRed  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :    VEMS_R_09_01759_001.01                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTREFCRED_vidIni();                                     */
/*  extf argret void CSTREFCRED_vidInhApplySlewRate();                        */
/*  extf argret void CSTREFCRED_vidIniIdlReq();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_CstrEfcRed                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_CstrEfcRed(void)
{
   CSTREFCRED_vidIni();
   CSTREFCRED_vidInhApplySlewRate();
   CSTREFCRED_vidIniIdlReq();
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlFast_CstrEfcRed                                    */
/* !Description :  Fonction d'accroche au moniteur Cstr_SdlFast_CstrEfcRed    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :    VEMS_R_09_01759_001.01                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTREFCRED_vidTarClcn();                                 */
/*  extf argret void CSTREFCRED_vidInhApplySlewRate();                        */
/*  extf argret void CSTREFCRED_vidClcnIdlReq();                              */
/*  input uint8 CSTREFCRED_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlFast_CstrEfcRed                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlFast_CstrEfcRed(void)
{
   if (CSTREFCRED_u8Inhib != 0x5A)
   {
      CSTREFCRED_vidTarClcn();
      CSTREFCRED_vidInhApplySlewRate();
      CSTREFCRED_vidClcnIdlReq();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveCrTR_CstrEfcRed                                    */
/* !Description :  Fonction d'accroche au moniteur Cstr_EveCrTR_CstrEfcRed    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :    VEMS_R_09_01759_001.01                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTREFCRED_vidIniIdlReq();                               */
/*  input uint8 CSTREFCRED_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveCrTR_CstrEfcRed                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveCrTR_CstrEfcRed(void)
{
   if (CSTREFCRED_u8Inhib != 0x5A)
   {
      CSTREFCRED_vidIniIdlReq();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlSlow_CstrEfcRed                                    */
/* !Description :  Fonction d'accroche au moniteur Cstr_SdlSlow_CstrEfcRed    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  R.GHORBEL                                                  */
/* !Trace_To    :    VEMS_R_09_01759_001.01                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTREFCRED_vidClcnIdlReq();                              */
/*  input uint8 CSTREFCRED_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlSlow_CstrEfcRed                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlSlow_CstrEfcRed(void)
{
   if (CSTREFCRED_u8Inhib != 0x5A)
   {
      CSTREFCRED_vidClcnIdlReq();
   }
}

/*-------------------------- end of file -------------------------------------*/