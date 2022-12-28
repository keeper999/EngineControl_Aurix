/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDETCFM                                              */
/* !Description     : MISFDETCFM component.                                   */
/*                                                                            */
/* !Module          : MISFDETCFM                                              */
/* !Description     : ALGORITHME DE DECISION POUR LA DETECTION MISFIRE        */
/*                                                                            */
/* !File            : MISFDETCFM_SCH.C                                        */
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
/*   1 / MISFMISFDETCFM_vidEntryInit                                          */
/*   2 / Misf_EveMisf_MisfDetCfm                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5198655 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDETCFM/MISFDETCFM_SCH.C_v$*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   06 Dec 2010 $*/
/* $Author::   wbouach                                $$Date::   06 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"MISFDETCFM.h"
#include"MISFDETCFM_L.h"
#include"MISFDETCFM_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFMISFDETCFM_vidEntryInit                                */
/* !Description :  Evènement de Reset du module MISFMISFDETCFM                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDETCFM_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MISFMISFDETCFM_vidEntryInit                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFMISFDETCFM_vidEntryInit(void)
{
   MISFDETCFM_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_MisfDetCfm                                    */
/* !Description :  Evènement lié à l'interruption logicielle de fin           */
/*                 d'acquisition de la fenêtre misfire                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDETCFM_vidDecision();                                */
/*  input uint8 MISFDETCFM_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_MisfDetCfm                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_MisfDetCfm(void)
{
   if (MISFDETCFM_u8Inhib != 0x5A)
   {
      MISFDETCFM_vidDecision();
   }
}
/*------------------------------ end of file ---------------------------------*/