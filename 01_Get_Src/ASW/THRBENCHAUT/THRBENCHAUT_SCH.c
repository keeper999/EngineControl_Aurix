/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHAUT                                             */
/* !Description     : THRBENCHAUT Component                                   */
/*                                                                            */
/* !Module          : THRBENCHAUT                                             */
/* !Description     : MODE BANC AUTOMATIQUE PAPILLON MOTORISE                 */
/*                                                                            */
/* !File            : THRBENCHAUT_SCH.C                                       */
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
/*   1 / Thr_EveRst_BenchAut                                                  */
/*   2 / Thr_SdlMid_BenchAut                                                  */
/*                                                                            */
/* !Reference   : V02 NT 08 04529 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#055915                                         */
/* !OtherRefs   : VEMS V02 ECU#056022                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRBENCHAUT/THRBENCHAUT_SCH.$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRBENCHAUT.h"
#include "THRBENCHAUT_l.h"
#include "THRBENCHAUT_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_BenchAut                                        */
/* !Description :  Sched reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidInitOutput();                             */
/*  extf argret void THRBENCHAUT_vidResetSinTime();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_BenchAut                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_BenchAut(void)
{
   THRBENCHAUT_vidInitOutput();
   THRBENCHAUT_vidResetSinTime();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_BenchAut                                        */
/* !Description :  Moniteur moyen pour la fonction papillon                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRBENCHAUT_vidMotThrAutBenchMod();                      */
/*  input uint8 THRBENCHAUT_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_BenchAut                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_BenchAut(void)
{
   if (THRBENCHAUT_u8Inhib != 0x5A)
   {
      THRBENCHAUT_vidMotThrAutBenchMod();
   }
}
/*------------------------------- end of file --------------------------------*/