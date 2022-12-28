/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STRTLOCKACQ                                             */
/* !Description     : STRTLOCKACQ component.                                  */
/*                                                                            */
/* !Module          : STRTLOCKACQ                                             */
/* !Description     : ACQUISITION DE L’INFORMATION START LOCK BV .            */
/*                                                                            */
/* !File            : STRTLOCKACQ_SCH.C                                       */
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
/*   1 / Gear_EveRst_StrtLockAcq                                              */
/*   2 / Gear_SdlFast_StrtLockAcq                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6530087 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STRTLOCKACQ/STRTLOCKACQ_SCH.C_v   $*/
/* $Revision::   1.6      $$Author::   achebino       $$Date::   27 May 2014 $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STRTLOCKACQ.h"
#include "STRTLOCKACQ_L.h"
#include "STRTLOCKACQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_EveRst_StrtLockAcq                                    */
/* !Description :  Fonction d'accroche à l'évenement RESET                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STRTLOCKACQ_vidInitialisation();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Gear_EveRst_StrtLockAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_EveRst_StrtLockAcq(void)
{
   STRTLOCKACQ_vidInitialisation();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_SdlFast_StrtLockAcq                                   */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STRTLOCKACQ_vidOS();                                     */
/*  input uint8 STRTLOCKACQ_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Trigger  : Gear_SdlFast_StrtLockAcq                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_SdlFast_StrtLockAcq(void)
{
   if (STRTLOCKACQ_u8Inhib != 0x5A)
   {
      STRTLOCKACQ_vidOS();
   }
}
/*****************************end of file**************************************/