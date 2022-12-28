/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRLRLY                                                 */
/* !Description     : PWRLRLY component.                                      */
/*                                                                            */
/* !Module          : PWRLRLY                                                 */
/* !Description     : COMMANDE ET DIAGNOSTIC DU RELAIS PRINCIPAL              */
/*                                                                            */
/* !File            : PWRLRLY_SCH.C                                           */
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
/*   1 / PwrlRly_EveRst_IfCmdDiag                                             */
/*   2 / PwrlRly_EveKOf_IfCmdDiag                                             */
/*   3 / PwrlRly_EveKOn_IfCmdDiag                                             */
/*   4 / PwrlRly_EveRxnIdDaRcdDml                                             */
/*   5 / PwrlRly_SdlMid_IfCmdDiag                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6559340 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RLY/PWRLRLY/PWRLRLY_SCH.c_v       $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PWRLRLY.h"
#include "PWRLRLY_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveRst_IfCmdDiag                                   */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLRLY_vidInitialization();                             */
/*  extf argret void PWRLRLY_vidCmd();                                        */
/*  extf argret void PWRLRLY_vidDiag();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : PwrlRly_EveRst_IfCmdDiag                                       */
/* !Trigger  : PwrlRly_EveRst_IfCmdDiag                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveRst_IfCmdDiag(void)
{
   PWRLRLY_vidInitialization();
   PWRLRLY_vidCmd();
   PWRLRLY_vidDiag();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveKOf_IfCmdDiag                                   */
/* !Description :  Evènement associé au passage de clef ON à clef OFF         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLRLY_vidCmd();                                        */
/*  input uint8 PWRLRLY_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : PwrlRly_EveKOf_IfCmdDiag                                       */
/* !Trigger  : PwrlRly_EveKOf_IfCmdDiag                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveKOf_IfCmdDiag(void)
{
   if (PWRLRLY_u8Inhib != 0x5A)
   {
      PWRLRLY_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveKOn_IfCmdDiag                                   */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLRLY_vidCmd();                                        */
/*  input uint8 PWRLRLY_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : PwrlRly_EveKOn_IfCmdDiag                                       */
/* !Trigger  : PwrlRly_EveKOn_IfCmdDiag                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveKOn_IfCmdDiag(void)
{
   if (PWRLRLY_u8Inhib != 0x5A)
   {
      PWRLRLY_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveRxnIdDaRcdDml                                   */
/* !Description :  Evénement de réception de la trame des données RCD et DML  */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLRLY_vidCmd();                                        */
/*  input uint8 PWRLRLY_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : PwrlRly_EveRxnIdDaRcdDml                                       */
/* !Trigger  : PwrlRly_EveRxnIdDaRcdDml                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveRxnIdDaRcdDml(void)
{
   if (PWRLRLY_u8Inhib != 0x5A)
   {
      PWRLRLY_vidCmd();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_SdlMid_IfCmdDiag                                   */
/* !Description :  Moniteur moyen du relais principal                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRLRLY_vidCmd();                                        */
/*  extf argret void PWRLRLY_vidGduCall();                                    */
/*  input uint8 PWRLRLY_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : PwrlRly_SdlMid_IfCmdDiag                                       */
/* !Trigger  : PwrlRly_SdlMid_IfCmdDiag                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_SdlMid_IfCmdDiag(void)
{
   if (PWRLRLY_u8Inhib != 0x5A)
   {
      PWRLRLY_vidCmd();
      PWRLRLY_vidGduCall();
   }
}
/*------------------------------- end of file --------------------------------*/