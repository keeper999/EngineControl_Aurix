/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkInstNoiseRbl                                         */
/* !Description     : KnkInstNoiseRbl component.                              */
/*                                                                            */
/* !Module          : KnkInstNoiseRbl                                         */
/* !Description     : ENGINE INSTANTANEOUS NOISE ESTIMATION(RUMBLE)           */
/*                                                                            */
/* !File            : knkinstnoiserbl_sch.c                                   */
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
/*   1 / KNKINSTNOISERBL_vidEntryInit                                         */
/*   2 / KnkTreat_EveRbl_KnkInstNoiseRbl                                      */
/*                                                                            */
/* !Reference   : V02 NT 10 02580 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "KnkInstNoiseRbl.h"
#include "KnkInstNoiseRbl_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidEntryInit                               */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_02580_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINSTNOISERBL_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  Event Reset                                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidEntryInit(void)
{
   KNKINSTNOISERBL_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_KnkInstNoiseRbl                            */
/* !Description :  Task computing for the cylinder being.                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_10_02580_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KNKINSTNOISERBL_vidKnkInstNoiRbl();                      */
/*  input uint8 KnkInstNoiseRbl_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_KnkInstNoiseRbl                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_KnkInstNoiseRbl(void)
{
   if (KnkInstNoiseRbl_u8Inhib != 0x5A)
   {
      KNKINSTNOISERBL_vidKnkInstNoiRbl();
   }
}