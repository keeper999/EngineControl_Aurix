/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLCMDMOD                                               */
/* !Description     : IDLCMDMOD Component                                     */
/*                                                                            */
/* !Module          : IDLCMDMOD                                               */
/* !Description     :  Consigne de régime de ralenti spécifique aux modes de  */
/*                    combustion essence                                      */
/*                                                                            */
/* !File            : IDLCMDMOD_SCH.C                                         */
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
/*   1 / IDLCMDMOD_vidEntryInit                                               */
/*   2 / TqSys_Sdl10ms_nTarIdlCmbMod                                          */
/*                                                                            */
/* !Reference   : V02 NT 10 08588 / 02                                        */
/* !OtherRefs   : 01460_10_01430 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLCMDMOD/IDLCMDM$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "IDLCMDMOD.h"
#include "IDLCMDMOD_L.h"
#include "IDLCMDMOD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidEntryInit                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCMDMOD_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IDLCMDMOD_vidEntryInit                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidEntryInit(void)
{
   IDLCMDMOD_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl10ms_nTarIdlCmbMod                                */
/* !Description :  Scheduler de la fonction IDLCMDMOD.                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCMDMOD_vidDtrminePwrtrainStat();                      */
/*  extf argret void IDLCMDMOD_vidUnvectorizeMode();                          */
/*  extf argret void IDLCMDMOD_vidDetermineSetpoint();                        */
/*  input uint8 IDLCMDMOD_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl10ms_nTarIdlCmbMod                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl10ms_nTarIdlCmbMod(void)
{
/*QAC Warning(2:4152) : The name 'TqSys_Sdl10ms_nTarIdlCmbMod' is
imposed by the customer*/
   if (IDLCMDMOD_u8Inhib != 0x5A)
   {
      IDLCMDMOD_vidDtrminePwrtrainStat();
      IDLCMDMOD_vidUnvectorizeMode();
      IDLCMDMOD_vidDetermineSetpoint();
   }
}

/*------------------------------- end of file --------------------------------*/