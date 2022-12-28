/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLIMSFTY                                               */
/* !Description     : TQLIMSFTY component.                                    */
/*                                                                            */
/* !Module          : TQLIMSFTY                                               */
/* !Description     : LIMITATION DE COUPLE POUR LA SECURITE DE FONCTIONNEMENT */
/*                                                                            */
/* !File            : TQLIMSFTY_SCH.C                                         */
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
/*   1 / TqSys_EveRst_tqLimSfty                                               */
/*   2 / TqSys_SdlFast_tqLimSfty                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 07804 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/TQLIMSFTY/TQLIMSFTY_SCH.C_v       $*/
/* $Revision::   1.1      $$Author::   hmelloul       $$Date::   01 Dec 2010 $*/
/* $Author::   hmelloul                               $$Date::   01 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQLIMSFTY.h"
#include "TQLIMSFTY_L.h"
#include "TQLIMSFTY_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_EveRst_tqLimSfty                                     */
/* !Description :  Evènement d'initialisation du calculateur.                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  M.FERSI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLIMSFTY_vidEcuReset();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_EveRst_tqLimSfty                                         */
/* !Trigger  : TqSys_EveRst_tqLimSfty                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_EveRst_tqLimSfty(void)
{
   TQLIMSFTY_vidEcuReset();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_SdlFast_tqLimSfty                                    */
/* !Description :  Moniteur moyen pour la fonction EngLim.                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  M.FERSI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLIMSFTY_vidTorqueLimitSafety();                        */
/*  extf argret void TQLIMSFTY_vidPreviousCalc();                             */
/*  input uint8 TQLIMSFTY_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : TqSys_SdlFast_tqLimSfty                                        */
/* !Trigger  : TqSys_SdlFast_tqLimSfty                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_SdlFast_tqLimSfty(void)
{
   if (TQLIMSFTY_u8Inhib != 0x5A)
   {
      TQLIMSFTY_vidTorqueLimitSafety();
      TQLIMSFTY_vidPreviousCalc();
   }
}

/*---------------------------- end of file -----------------------------------*/