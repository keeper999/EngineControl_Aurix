/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRCORRDPOSN                                            */
/* !Description     : THRCORRDPOSN component.                                 */
/*                                                                            */
/* !Module          : THRCORRDPOSN                                            */
/* !Description     : Calcul de la position papillon corrigée                 */
/*                                                                            */
/* !File            : THRCORRDPOSN_SCH.C                                      */
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
/*   1 / THRCORRDPOSN_vidEntryInit                                            */
/*   2 / Thr_EveClcnServo_CorrdPosn                                           */
/*                                                                            */
/* !Reference   : V02 NT 08 05172 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRCORRDPOSN/ThrCorrdPosn_sch.$*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   30 Jun 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRCORRDPOSN.h"
#include "THRCORRDPOSN_l.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCORRDPOSN_vidEntryInit                                  */
/* !Description :  Evènement Reset ECU                                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRCORRDPOSN_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event Reset                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCORRDPOSN_vidEntryInit(void)
{
   THRCORRDPOSN_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_CorrdPosn                                 */
/* !Description :  Moniteur rapide de la fonction papillon.                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRCORRDPOSN_vidThrottlePosCorr();                       */
/*  input uint8 THRCORRDPOSN_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event Thr_EveClcnServo_CorrdPosn                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_CorrdPosn(void)
{
   if (THRCORRDPOSN_u8Inhib != 0x5A)
   {
      THRCORRDPOSN_vidThrottlePosCorr();
   }
}

/*------------------------------- End of file --------------------------------*/