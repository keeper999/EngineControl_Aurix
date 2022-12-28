/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPYSTT                                                  */
/* !Description     : SPYSTT component.                                       */
/*                                                                            */
/* !Module          : SPYSTT                                                  */
/* !Description     : SPY STT                                                 */
/*                                                                            */
/* !File            : SPYSTT_SCH.C                                            */
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
/*   1 / STT_EveRst_SpySTT                                                    */
/*   2 / STT_SdlMid_SpySTT                                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 02508 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPYSTT/SPYSTT_SCH.C_v             $*/
/* $Revision::   1.3      $$Author::   ACHEBINO       $$Date::   30 Sep 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "SPYSTT.h"
#include "SPYSTT_L.h"
#include "SPYSTT_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_EveRst_SpySTT                                          */
/* !Description :  évènement d'initialisation                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPYSTT_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_EveRst_SpySTT                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_EveRst_SpySTT(void)
{
   SPYSTT_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_SdlMid_SpySTT                                          */
/* !Description :  évenement d'appel aux fonctionalités du module SPYSTT      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_001.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPYSTT_vidRecNotStopCase();                              */
/*  extf argret void SPYSTT_vidCutCasRstFaiRec();                             */
/*  input uint8 SPYSTT_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_SdlMid_SpySTT                                              */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_SdlMid_SpySTT(void)
{
   if (SPYSTT_u8Inhib != 0x5A)
   {
      SPYSTT_vidRecNotStopCase();
      SPYSTT_vidCutCasRstFaiRec();
   }
}
/*-------------------------------- end of file -------------------------------*/
