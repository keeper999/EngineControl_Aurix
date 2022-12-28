/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSPPOSN                                               */
/* !Description     : THRSPPOSN component.                                    */
/*                                                                            */
/* !Module          : THRSPPOSN                                               */
/* !Description     : CALCUL DE LA CONSIGNE DE POSITION PAPILLON MOTORISE     */
/*                                                                            */
/* !File            : THRSPPOSN_SCH.C                                         */
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
/*   1 / Thr_EveRst_SpPosn                                                    */
/*   2 / Thr_SdlMid_SpPosn                                                    */
/*   3 / Thr_EveOplCllEna_ThrSpPosn                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6095099 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSPPOSN/THRSPPOSN_SCH.C_v $*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   05 May 2014 $*/
/* $Author::   etsasson                               $$Date::   05 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRSPPOSN.h"
#include "THRSPPOSN_L.h"
#include "THRSPPOSN_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_SpPosn                                          */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSPPOSN_vidInitOutput();                               */
/*  extf argret void THRSPPOSN_vidInitThrottleRef();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_SpPosn                                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_SpPosn(void)
{
   THRSPPOSN_vidInitOutput();
   THRSPPOSN_vidInitThrottleRef();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_SpPosn                                          */
/* !Description :  Moniteur moyen pour la fonction papillon                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSPPOSN_vidComputeDtcThrPos();                         */
/*  extf argret void THRSPPOSN_vidStopEngineCase();                           */
/*  extf argret void THRSPPOSN_vidComputeDtcThrPosRef();                      */
/*  extf argret void THRSPPOSN_vidSwitchMgtMcut();                            */
/*  input uint8 THRSPPOSN_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_SpPosn                                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_SpPosn(void)
{
   if (THRSPPOSN_u8Inhib != 0x5A)
   {
      THRSPPOSN_vidComputeDtcThrPos();
      THRSPPOSN_vidStopEngineCase();
      THRSPPOSN_vidComputeDtcThrPosRef();
      THRSPPOSN_vidSwitchMgtMcut();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveOplCllEna_ThrSpPosn                                 */
/* !Description :  Evenement de passage d'une commande en boucle ouverte à une*/
/*                 commande en boucle ferme du papillon                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSPPOSN_vidInitThrottleRef();                          */
/*  input uint8 THRSPPOSN_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveOplCllEna_ThrSpPosn                                     */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveOplCllEna_ThrSpPosn(void)
{
   if (THRSPPOSN_u8Inhib != 0x5A)
   {
      THRSPPOSN_vidInitThrottleRef();
   }
}
/*------------------------------- end of file --------------------------------*/