/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPTMOD                                                  */
/* !Description     : SPTMOD Component.                                       */
/*                                                                            */
/* !Module          : SPTMOD                                                  */
/* !Description     : Sport Mode Supervisor                                   */
/*                                                                            */
/* !File            : SPTMOD_SCH.C                                            */
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
/*   1 / SPTMOD_vidEntryInit                                                  */
/*   2 / TqSys_Sdl10ms_SptMod                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 04668 / 01                                        */
/* !OtherRefs   : 01460_11_00109 / 01                                         */
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
#include "SPTMOD.h"
#include "SPTMOD_L.h"
#include "SPTMOD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPTMOD_vidEntryInit                                        */
/* !Description :  Événement reset calculateur.                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPTMOD_vidInitOutputs();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SPTMOD_vidInitOutputs                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPTMOD_vidEntryInit(void)
{
   SPTMOD_vidInitOutputs();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_SptMod                                       */
/* !Description :  Schéduling de la fonction / Function's scheduling          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04668_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPTMOD_vidSuperviseurModeSport();                        */
/*  input uint8 SPTMOD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl10ms_SptMod                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_SptMod(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (SPTMOD_u8Inhib != 0x5A)
   {
      SPTMOD_vidSuperviseurModeSport();
   }
}
/*------------------------------- end of file --------------------------------*/