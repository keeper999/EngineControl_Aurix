/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHMODE                                            */
/* !Description     : THRBENCHMODE component.                                 */
/*                                                                            */
/* !Module          : THRBENCHMODE                                            */
/* !Description     : CALCUL DE LA CONSIGNE DE POSITION PAPILLON MOTORISE EN  */
/*                    MODE BANC MOTEUR                                        */
/*                                                                            */
/* !File            : THRBENCHMODE_SCH.C                                      */
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
/*   1 / Thr_EveRst_SpBenchMod                                                */
/*   2 / Thr_SdlMid_SpBenchMod                                                */
/*                                                                            */
/* !Reference   : V02 NT 09 07776 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/REF/MODULES/THR/THRBENCHMODE/THRBENCHMODE_sc$*/
/* $Revision::   1.1      $$Author::   vgarnier       $$Date::   13 Oct 2010 $*/
/* $Author::   vgarnier                               $$Date::   13 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRBENCHMODE.h"
#include "THRBENCHMODE_L.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_SpBenchMod                                      */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.FENDRI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHMODE_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_SpBenchMod                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_SpBenchMod(void)
{
   THRBENCHMODE_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_SpBenchMod                                      */
/* !Description :  Moniteur moyen de la fonction papillon                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.FENDRI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void THRBENCHMODE_vidNormFunc();                              */
/*  input uint8 THRBENCHMODE_u8Inhib;                                         */
/*  input boolean Thr_bAcvSpBenchMod_C;                                       */
/*  output boolean Thr_bAcvSpBenchMod;                                        */
/*  output boolean Thr_bAcvSpBenchMod_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_SpBenchMod                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_SpBenchMod(void)
{
   if(THRBENCHMODE_u8Inhib != 0x5A)
   {
      VEMS_vidSET(Thr_bAcvSpBenchMod, Thr_bAcvSpBenchMod_C);
      if (Thr_bAcvSpBenchMod_C != 0)
      {
         THRBENCHMODE_vidNormFunc();
      }
   }
}
/*---------------------------------End Of File--------------------------------*/