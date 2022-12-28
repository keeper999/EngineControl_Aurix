/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYACTEST                                               */
/* !Description     : RLYACTEST component.                                    */
/*                                                                            */
/* !Module          : RLYACTEST                                               */
/* !Description     : TEST ACTIONNEUR DU RELAIS DE PUISSANCE.                 */
/*                                                                            */
/* !File            : RLYACTEST_SCH.C                                         */
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
/*   1 / Rly_EveRst_ActTstPwrRly                                              */
/*   2 / Rly_SdlFast_ActTstPwrRly                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 00872 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/RLYACTEST/RLYACTEST_SCH.C_v $*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   19 Oct 2011 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "std_types.h"
#include "RLYACTEST.h"
#include "RLYACTEST_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Rly_EveRst_ActTstPwrRly                                    */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00872_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYACTEST_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Rly_EveRst_ActTstPwrRly                                        */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Rly_EveRst_ActTstPwrRly(void)
{
   RLYACTEST_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Rly_SdlFast_ActTstPwrRly                                   */
/* !Description :  Moniteur rapide du relais de puissance (actionneurs).      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00872_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYACTEST_vidTimeCmdPwrRly();                            */
/*  input uint8 RLYACTEST_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Rly_SdlFast_ActTstPwrRly                                       */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Rly_SdlFast_ActTstPwrRly(void)
{
   if (RLYACTEST_u8Inhib != 0x5A)
   {
      RLYACTEST_vidTimeCmdPwrRly();
   }
}

/*---------------------------- end of file -----------------------------------*/