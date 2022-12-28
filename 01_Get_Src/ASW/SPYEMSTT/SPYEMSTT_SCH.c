/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPYEMSTT                                                */
/* !Description     : SPYEMSTT Component                                      */
/*                                                                            */
/* !Module          : SPYEMSTT                                                */
/* !Description     : Espionner le SEEM STT : SpyEmSTT                        */
/*                                                                            */
/* !File            : SPYEMSTT_SCH.C                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / STT_EveRst_SpyEmSTT                                                  */
/*   2 / STT_SdlMid_SpyEmSTT                                                  */
/*                                                                            */
/* !Reference   : V02 NT 10 05852 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPYEMSTT/SPYEMSTT_SCH.C_v         $*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   04 Oct 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   04 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SPYEMSTT.h"
#include "SPYEMSTT_L.h"
#include "SPYEMSTT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_EveRst_SpyEmSTT                                        */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPYEMSTT_vidInitOutput();                                */
/*  extf argret void SPYEMSTT_vidInitialization();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_EveRst_SpyEmSTT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_EveRst_SpyEmSTT(void)
{
   SPYEMSTT_vidInitOutput();
   SPYEMSTT_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_SdlMid_SpyEmSTT                                        */
/* !Description :  Moniteur moyen de la fonction SpySTT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPYEMSTT_vidRecNotStopCase();                            */
/*  input uint8 SPYEMSTT_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_SdlMid_SpyEmSTT                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_SdlMid_SpyEmSTT(void)
{
   if (SPYEMSTT_u8Inhib != 0x5A)
   {
      SPYEMSTT_vidRecNotStopCase();
   }
}
/*-------------------------------- end of file -------------------------------*/