/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRABSSPPOSN                                            */
/* !Description     : THRABSSPPOSN component                                  */
/*                                                                            */
/* !Module          : THRABSSPPOSN                                            */
/* !Description     : Calcul de la Consigne de Position Papillon Absolue      */
/*                                                                            */
/* !File            : THRABSSPPOSN_SCH.C                                      */
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
/*   1 / Thr_EveRst_AbsSpPosn                                                 */
/*   2 / Thr_SdlSlow_AbsSpPosn                                                */
/*   3 / Thr_SdlMid_AbsSpPosn                                                 */
/*   4 / Thr_EveOplCllEna_ThrAbsSpPosn                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 04493 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRABSSPPOSN/ThrAbsSpPosn_SCH.$*/
/* $Revision::   1.5      $$Author::   ACHEBINO       $$Date::   30 Jun 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "THRABSSPPOSN.h"
#include "THRABSSPPOSN_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_AbsSpPosn                                       */
/* !Description :  Sched reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRABSSPPOSN_vidInitOutput();                            */
/*  extf argret void THRABSSPPOSN_vidInitThrotPosRef();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Thr_EveRst_AbsSpPosn                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_AbsSpPosn(void)
{
   THRABSSPPOSN_vidInitOutput();
   THRABSSPPOSN_vidInitThrotPosRef();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlSlow_AbsSpPosn                                      */
/* !Description :  Moniteur lent pour la fonction papillon                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRABSSPPOSN_vidCompOpenThresh();                        */
/*  input uint8 THRABSSPPOSN_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Thr_SdlSlow_AbsSpPosn                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlSlow_AbsSpPosn(void)
{
   if (THRABSSPPOSN_u8Inhib != 0x5A)
   {
      THRABSSPPOSN_vidCompOpenThresh();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_AbsSpPosn                                       */
/* !Description :  Moniteur moyen pour la fonction papillon                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRABSSPPOSN_vidModifThrustPos();                        */
/*  extf argret void THRABSSPPOSN_vidComputeAbsRef();                         */
/*  input uint8 THRABSSPPOSN_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Thr_SdlMid_AbsSpPosn                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_AbsSpPosn(void)
{
   if (THRABSSPPOSN_u8Inhib != 0x5A)
   {
      THRABSSPPOSN_vidModifThrustPos();
      THRABSSPPOSN_vidComputeAbsRef();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveOplCllEna_ThrAbsSpPosn                              */
/* !Description :  Evenement de passage d'une commande en boucle ouverte à une*/
/*                 commande  en boucle ferme du papillon.                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Walid Salhi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRABSSPPOSN_vidModifThrustPos();                        */
/*  extf argret void THRABSSPPOSN_vidComputeAbsRef();                         */
/*  input uint8 THRABSSPPOSN_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Thr_EveOplCllEna_ThrAbsSpPosn                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveOplCllEna_ThrAbsSpPosn(void)
{
   if (THRABSSPPOSN_u8Inhib != 0x5A)
   {
      THRABSSPPOSN_vidModifThrustPos();
      THRABSSPPOSN_vidComputeAbsRef();
   }
}
/*------------------------------- end of file --------------------------------*/