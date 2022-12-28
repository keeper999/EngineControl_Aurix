/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRN                                              */
/* !Description     : MISFDFTLRN component.                                   */
/*                                                                            */
/* !Module          : MISFDFTLRN                                              */
/* !Description     : Apprentissage des défauts Misfire.                      */
/*                                                                            */
/* !File            : MISFDFTLRN_SCH.C                                        */
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
/*   1 / Misf_EveRst_MisfDftLrn                                               */
/*   2 / Misf_SdlSlow_MisfDftLrn                                              */
/*   3 / Misf_EveMisf_MisfDftLrn                                              */
/*   4 / Misf_EveRstLrn_MisfDftLrn                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_SCH.C_v$*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   06 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   06 Jul 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFDFTLRN.h"
#include "MISFDFTLRN_L.h"
#include "MISFDFTLRN_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_MisfDftLrn                                     */
/* !Description :  Evènement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_00770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidInitOutput();                              */
/*  extf argret void MISFDFTLRN_vidEcuRst();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_MisfDftLrn                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_MisfDftLrn(void)
{
   MISFDFTLRN_vidInitOutput();
   MISFDFTLRN_vidEcuRst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlSlow_MisfDftLrn                                    */
/* !Description :  Moniteur lent de la fonction Misf                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_00770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidManuRst();                                 */
/*  input uint8 MISFDFTLRN_u8Inhib;                                           */
/*  input boolean Misf_bRstNoRlzd_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_SdlSlow_MisfDftLrn                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlSlow_MisfDftLrn(void)
{
   if (MISFDFTLRN_u8Inhib != 0x5A)
   {
      if (Misf_bRstNoRlzd_C != 0)
      {
         MISFDFTLRN_vidManuRst();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfDftLrn                                    */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_00770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidMfAdap();                                  */
/*  extf argret void MISFDFTLRN_vidAutomateMisfLrn();                         */
/*  extf argret void MISFDFTLRN_vidSampleWin();                               */
/*  extf argret void MISFDFTLRN_vidSaveLrn();                                 */
/*  extf argret void MISFDFTLRN_vidUpdateWinAdap();                           */
/*  input uint8 MISFDFTLRN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfDftLrn                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfDftLrn(void)
{
   if (MISFDFTLRN_u8Inhib != 0x5A)
   {
      MISFDFTLRN_vidMfAdap();
      MISFDFTLRN_vidAutomateMisfLrn();
	  MISFDFTLRN_vidSampleWin();
      MISFDFTLRN_vidSaveLrn();
      MISFDFTLRN_vidUpdateWinAdap ();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRstLrn_MisfDftLrn                                  */
/* !Description :  Evènement Reset adaptatifs Misfire                         */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_00770_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidManuRst();                                 */
/*  input uint8 MISFDFTLRN_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Misf_EveRstLrn_MisfDftLrn                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRstLrn_MisfDftLrn(void)
{
   if (MISFDFTLRN_u8Inhib != 0x5A)
   {
      MISFDFTLRN_vidManuRst();
   }
}
/********************************* end of file ********************************/