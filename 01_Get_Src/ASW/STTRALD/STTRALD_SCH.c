/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTRALD                                                 */
/* !Description     : STTRALD component.                                      */
/*                                                                            */
/* !Module          : STTRALD                                                 */
/* !Description     : Automate de detection des transitoires de charge        */
/*                                                                            */
/* !File            : STTRALD_SCH.C                                           */
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
/*   1 / STTRALD_vidEntryInit                                                 */
/*   2 / InM_SdlFast_stTraLd                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 04622 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#043770                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/STTRALD/STTRALD_SCH.C_v           $*/
/* $Revision::   1.0      $$Author::   pcabariq       $$Date::   21 Sep 2009 $*/
/* $Author::   pcabariq                               $$Date::   21 Sep 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STTRALD.h"
#include "STTRALD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTRALD_vidEntryInit                                       */
/* !Description :  Fonction d'accroche au moniteur reset.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTRALD_vidInitOutputs();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : STTRALD_vidEntryInit                                           */
/* !Trigger  : Event Reset                                                    */
/*                                                                            */
/* !LastAuthor  : H.GHORBEL                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTRALD_vidEntryInit(void)
{
   STTRALD_vidInitOutputs();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InM_SdlFast_stTraLd                                        */
/* !Description :  Fonction d'accroche au moniteur 5 ms.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void STTRALD_vidLoadTransDetectStMach();                      */
/*  input uint8 STTRALD_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : InM_SdlFast_stTraLd                                            */
/* !Trigger  : Time 5ms                                                       */
/*                                                                            */
/* !LastAuthor  : H.GHORBEL                                                   */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InM_SdlFast_stTraLd(void)
{
   if(STTRALD_u8Inhib != 0x5A)
   {
      STTRALD_vidLoadTransDetectStMach();
   }
}
/*------------------------------- end of file --------------------------------*/