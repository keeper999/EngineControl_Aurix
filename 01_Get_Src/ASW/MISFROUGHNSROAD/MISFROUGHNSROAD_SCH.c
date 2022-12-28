/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFROUGHNSROAD                                         */
/* !Description     : MISFROUGHNSROAD component.                              */
/*                                                                            */
/* !Module          : MISFROUGHNSROAD                                         */
/* !Description     : DETECTION DE LA MAUVAISE ROUTE                          */
/*                                                                            */
/* !File            : MISFROUGHNSROAD_SCH.C                                   */
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
/*   1 / MISFROUGHNSROAD_vidEntryInit                                         */
/*   2 / Misf_EveMisf_MisfRoughnsRoad                                         */
/*                                                                            */
/* !Reference   : V02 NT 09 02692 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFROUGHNSROAD/MISFROUGHNSRO$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Jan 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include"STD_TYPES.h"
#include"MISFROUGHNSROAD.h"
#include"MISFROUGHNSROAD_L.h"
#include"MISFROUGHNSROAD_IM.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROAD_vidEntryInit                               */
/* !Description :  Fonction d'initialisation des sorties du module            */
/*                 MISFROUGHNSROAD.                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFROUGHNSROAD_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : MISFROUGHNSROAD_vidEntryInit                                   */
/* !Trigger  : MISFROUGHNSROAD_vidEntryInit                                   */
/*                                                                            */
/* !LastAuthor  : A.LABBENE                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROAD_vidEntryInit(void)
{
   MISFROUGHNSROAD_vidInitOutput();
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfRoughnsRoad                               */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFROUGHNSROAD_vidRoughRoad();                          */
/*  input uint8 MISFROUGHNSROAD_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Misf_EveMisf_MisfRoughnsRoad                                   */
/* !Trigger  : Misf_EveMisf_MisfRoughnsRoad                                   */
/*                                                                            */
/* !LastAuthor  : A.LABBENE                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfRoughnsRoad(void)
{
   if (MISFROUGHNSROAD_u8Inhib != 0x5A)
   {
      MISFROUGHNSROAD_vidRoughRoad();
   }
}