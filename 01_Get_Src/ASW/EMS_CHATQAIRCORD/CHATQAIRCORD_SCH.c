/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CHATQAIRCORD                                            */
/* !Description     : CHATQAIRCORD component.                                 */
/*                                                                            */
/* !Module          : CHATQAIRCORD                                            */
/* !Description     : CALCUL DE LA CONSIGNE D'AIR LORS D'UNE RÉGULATION ASR.  */
/*                                                                            */
/* !File            : CHATQAIRCORD_SCH.C                                      */
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
/*   1 / CHATQAIRCORD_vidEntryInit                                            */
/*   2 / TqSys_Sdl10ms_TqCha                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5139605 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_1240 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/CHATQAIRCORD/CHAT$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CHATQAIRCORD.h"
#include "CHATQAIRCORD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CHATQAIRCORD_vidEntryInit                                  */
/* !Description :  Fonction d'accroche au Reset.                              */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHATQAIRCORD_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CHATQAIRCORD_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CHATQAIRCORD_vidEntryInit(void)
{
   CHATQAIRCORD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_TqCha                                        */
/* !Description :  Fonction d'accroche au moniteur 10ms.                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CHATQAIRCORD_vidCalcConsigRegASR();                      */
/*  input uint8 CHATQAIRCORD_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl10ms_TqCha                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_TqCha(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (CHATQAIRCORD_u8Inhib != 0x5A)
   {
      CHATQAIRCORD_vidCalcConsigRegASR();
   }
}
/*-------------------------------- end of file -------------------------------*/