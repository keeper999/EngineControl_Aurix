/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFWINADP                                              */
/* !Description     : MISFWINADP Component                                    */
/*                                                                            */
/* !Module          : MISFWINADP                                              */
/* !Description     : Correction des fenêtres d’acquisition par un adaptatif  */
/*                                                                            */
/* !File            : MISFWINADP_SCH.C                                        */
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
/*   1 / MISFWINADP_vidEntryInit                                              */
/*   2 / Misf_EveMisf_MisfWinAdp                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 00776 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFWINADP/MISFWINADP_SCH.c_v$*/
/* $Revision::   1.1      $$Author::   fsanchez2      $$Date::   15 Apr 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MISFWINADP.h"
#include "MISFWINADP_L.h"
#include "MISFWINADP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidEntryInit                                    */
/* !Description :  Evénement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINADP_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MISFWINADP_vidEntryInit                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidEntryInit(void)
{
   MISFWINADP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfWinAdp                                    */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFWINADP_vidConditionActiv();                          */
/*  extf argret void MISFWINADP_vidCorrectedWindow();                         */
/*  input uint8 MISFWINADP_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfWinAdp                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfWinAdp(void)
{
   if (MISFWINADP_u8Inhib != 0x5A)
   {
      MISFWINADP_vidConditionActiv();
      MISFWINADP_vidCorrectedWindow();
   }
}
/*------------------------------- end of file --------------------------------*/