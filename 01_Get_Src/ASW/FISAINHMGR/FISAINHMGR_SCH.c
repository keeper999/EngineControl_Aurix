/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FISAINHMGR                                              */
/* !Description     : FISAINHMGR component                                    */
/*                                                                            */
/* !Module          : FISAINHMGR                                              */
/* !Description     : INHIBITIONS ET RECONFIGURATIONS RELATIVES À LA FONCTION */
/*                    D’ADAPTATION DE L’INJECTION AU DÉMARRAGE (FISA)         */
/*                                                                            */
/* !File            : FISAINHMGR_SCH.C                                        */
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
/*   1 / FISAINHMGR_vidEntryInit                                              */
/*   2 / Fisa_SdlMid_FisaInhMgr                                               */
/*   3 / Fisa_EveTDC_FisaInhMgr                                               */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/FISAINHMGR/FISAINHMGR_SCH.C_v     $*/
/* $Revision::   1.0      $$Author::   sbiet          $$Date::   09 Jul 2009 $*/
/* $Author::   sbiet                                  $$Date::   09 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "FISAINHMGR.h"
#include "FISAINHMGR_L.h"
#include "FISAINHMGR_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction d'accroche sur l'évent FISAINHMGR_vidEntryInit.    */
/* !Number      : SCH.1                                                       */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void FISAINHMGR_vidInitOutput();                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : FISAINHMGR_vidEntryInit                                        */
/* !Trigger  : FISAINHMGR_vidEntryInit                                        */
/*                                                                            */
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FISAINHMGR_vidEntryInit(void)
{
   FISAINHMGR_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Moniteur medium pour la fonction FISA .                     */
/* !Number      : SCH.2                                                       */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void FISAINHMGR_vidFisaCaseDetermin();                       */
/*                                                                            */
/*   input uint8 FISAINHMGR_u8Inhib;                                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Fisa_SdlMid_FisaInhMgr                                         */
/* !Trigger  : Fisa_SdlMid_FisaInhMgr                                         */
/*                                                                            */
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_SdlMid_FisaInhMgr(void)
{
   if (FISAINHMGR_u8Inhib != 0x5A)
   {
      FISAINHMGR_vidFisaCaseDetermin();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Evènement interruption PMH .                                */
/* !Number      : SCH.3                                                       */
/* !Reference   : V02 NT 09 00158 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf argret void FISAINHMGR_vidReconfigManagement();                     */
/*                                                                            */
/*   input uint8 FISAINHMGR_u8Inhib;                                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Fisa_EveTDC_FisaInhMgr                                         */
/* !Trigger  : Fisa_EveTDC_FisaInhMgr                                         */
/*                                                                            */
/* !LastAuthor  : L.DHIB                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fisa_EveTDC_FisaInhMgr(void)
{
   if (FISAINHMGR_u8Inhib != 0x5A)
   {
      FISAINHMGR_vidReconfigManagement();
   }
}
/*------------------------------- end of file --------------------------------*/