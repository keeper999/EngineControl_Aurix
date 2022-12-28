/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCRK_ANTIFLOOD                                        */
/* !Description     : INJCRK_ANTIFLOOD component                              */
/*                                                                            */
/* !Module          : INJCRK_ANTIFLOOD                                        */
/* !Description     : DETECTION DE DEMANDE DE DENOYAGE                        */
/*                                                                            */
/* !File            : INJCRK_ANTIFLOOD_SCH.C                                  */
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
/*   1 / INJCRK_ANTIFLOOD_vidEntryInit                                        */
/*   2 / InjCrk_EveStTCr_AntiFlood                                            */
/*   3 / InjCrk_EveKOn_AntiFlood                                              */
/*   4 / InjCrk_EveRTCr_AntiFlood                                             */
/*   5 / InjCrk_SdlFast_AntiFlood                                             */
/*                                                                            */
/* !Reference   : V02 NT 08 04908 / 2                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJRCRK/INJCRK_ANTIFLOOD/INJCR$*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   18 Mar 2011 $*/
/* $Author::   hmelloul                               $$Date::   18 Mar 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "INJCRK_ANTIFLOOD.h"
#include "INJCRK_ANTIFLOOD_L.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCRK_ANTIFLOOD_vidEntryInit                              */
/* !Description :  Fonction d'accroche à l'evenement Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidInitOutput();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event INJCRK_ANTIFLOOD_vidEntryInit                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCRK_ANTIFLOOD_vidEntryInit(void)
{
   INJCRK_ANTIFLOOD_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCrk_EveStTCr_AntiFlood                                  */
/* !Description :  Fonction d'accroche à l'evenement InjCrk_EveStTCr_AntiFlood*/
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidCrkFuelling();                       */
/*  input uint8 INJCRK_ANTIFLOOD_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event InjCrk_EveStTCr_AntiFlood                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCrk_EveStTCr_AntiFlood(void)
{
   if (INJCRK_ANTIFLOOD_u8Inhib != 0x5A)
   {
      INJCRK_ANTIFLOOD_vidCrkFuelling();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCrk_EveKOn_AntiFlood                                    */
/* !Description :  Fonction d'accroche à l'evenement InjCrk_EveKOn_AntiFlood  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidCrkFuelling();                       */
/*  input uint8 INJCRK_ANTIFLOOD_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event InjCrk_EveKOn_AntiFlood                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCrk_EveKOn_AntiFlood(void)
{
   if (INJCRK_ANTIFLOOD_u8Inhib != 0x5A)
   {
      INJCRK_ANTIFLOOD_vidCrkFuelling();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCrk_EveRTCr_AntiFlood                                   */
/* !Description :  Fonction d'accroche à l'evenement InjCrk_EveRTCr_AntiFlood */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidIniRunToCrnk();                      */
/*  input uint8 INJCRK_ANTIFLOOD_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event InjCrk_EveRTCr_AntiFlood                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCrk_EveRTCr_AntiFlood(void)
{
   if (INJCRK_ANTIFLOOD_u8Inhib != 0x5A)
   {
      INJCRK_ANTIFLOOD_vidIniRunToCrnk();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCrk_SdlFast_AntiFlood                                   */
/* !Description :  Fonction d'accroche à l'evenement InjCrk_SdlFast_AntiFlood */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.SELMI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCRK_ANTIFLOOD_vidMngAntiFlood();                      */
/*  input uint8 INJCRK_ANTIFLOOD_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Event InjCrk_SdlFast_AntiFlood                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCrk_SdlFast_AntiFlood(void)
{
   if (INJCRK_ANTIFLOOD_u8Inhib != 0x5A)
   {
      INJCRK_ANTIFLOOD_vidMngAntiFlood();
   }
}
/*---------------------------- end of file -----------------------------------*/