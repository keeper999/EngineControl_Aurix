/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSNSPLRN                                            */
/* !Description     : ThrPosnSpLrn component                                  */
/*                                                                            */
/* !Module          : THRPOSNSPLRN                                            */
/* !Description     : CALCUL DES CONSIGNES SPECIFIQUES DE POSITION PAPILLON   */
/*                    MOTORISE EN BOUCLE FERMEE                               */
/*                                                                            */
/* !File            : THRPOSNSPLRN_SCH.C                                      */
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
/*   1 / Thr_EveRst_ThrPosnSpSpc                                              */
/*   2 / Thr_SdlMid_ThrPosnSpSpc                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 00303 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRPOSNSPLRN/ThrPosnSpLrn_sc$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   01 Jul 2013 $*/
/* $Author::   etsasson                               $$Date::   01 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "THRPOSNSPLRN.h"
#include "THRPOSNSPLRN_L.h"
#include "THRPOSNSPLRN_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_ThrPosnSpSpc                                    */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_00303_001.01                                     */
/*                 VEMS_E_11_00303_002.01                                     */
/*                 VEMS_E_11_00303_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSNSPLRN_vidInit();                                  */
/*  extf argret void THRPOSNSPLRN_vidMobiltRestorat();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_ThrPosnSpSpc                                        */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_ThrPosnSpSpc(void)
{
   THRPOSNSPLRN_vidInit();
   THRPOSNSPLRN_vidMobiltRestorat();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_ThrPosnSpSpc                                    */
/* !Description :  Evènement de moniteur moyen de la fonction                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_00303_001.01                                     */
/*                 VEMS_E_11_00303_002.01                                     */
/*                 VEMS_E_11_00303_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRPOSNSPLRN_vidMobiltRestorat();                        */
/*  extf argret void THRPOSNSPLRN_vidAutomate();                              */
/*  extf argret void THRPOSNSPLRN_vidSlewRate();                              */
/*  extf argret void THRPOSNSPLRN_vidFinalSpcSp();                            */
/*  input uint8 THRPOSNSPLRN_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_ThrPosnSpSpc                                        */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_ThrPosnSpSpc(void)
{
   if(THRPOSNSPLRN_u8Inhib != 0x5A)
   {
      THRPOSNSPLRN_vidMobiltRestorat();
      THRPOSNSPLRN_vidAutomate ();
      THRPOSNSPLRN_vidSlewRate ();
      THRPOSNSPLRN_vidFinalSpcSp();
   }
}
/*----------------------------- end of file ----------------------------------*/