/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFSUCDETIDLE                                          */
/* !Description     : MISFSUCDETIDLE component                                */
/*                                                                            */
/* !Module          : MISFSUCDETIDLE                                          */
/* !Description     : Algorithmes De Détection De 2 Misfires Successifs en    */
/*                    IDLE                                                    */
/*                                                                            */
/* !File            : MISFSUCDETIDLE_SCH.C                                    */
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
/*   1 / Misf_EveRst_MisfSucDetIdle                                           */
/*   2 / Misf_EveMisf_MisfSucDetIdle                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5198644 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065828                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFSUCDETIDLE.h"
#include "MISFSUCDETIDLE_L.h"
#include "MISFSUCDETIDLE_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfSucDetIdle                                 */
/* !Description :  Evènement reset calculateur                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidIni();                                 */
/*  extf argret void MISFSUCDETIDLE_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_MisfSucDetIdle                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfSucDetIdle(void)
{
   MISFSUCDETIDLE_vidIni();
   MISFSUCDETIDLE_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfSucDetIdle                                */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B.SAFI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFSUCDETIDLE_vidMainMisfSucDet();                      */
/*  input uint8 MISFSUCDETIDLE_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfSucDetIdle                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfSucDetIdle(void)
{
   if (MISFSUCDETIDLE_u8Inhib != 0x5A)
   {
      MISFSUCDETIDLE_vidMainMisfSucDet();
   }
}
/*---------------------------- end of file -----------------------------------*/