/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : Wg_CmdBenchMod                                          */
/* !Description     : Wg_CmdBenchMod component.                               */
/*                                                                            */
/* !Module          : Wg_CmdBenchMod                                          */
/* !Description     : WASTEGATE SOLENOID VALVE OPEN LOOP COMMAND SETPOINT IN  */
/*                    BENCH MODE                                              */
/*                                                                            */
/* !File            : Wg_CmdBenchMod_sch.c                                    */
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
/*   1 / Wg_EveRst_WgCmdOplBenchMod                                           */
/*   2 / Wg_SdlMid_WgCmdOplBenchMod                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 08184 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "WG_CMDBENCHMOD.h"
#include "WG_CMDBENCHMOD_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_WgCmdOplBenchMod                                 */
/* !Description :  Event Reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_E_09_08184_001.01                                     */
/*                 VEMS_E_09_08184_002.01                                     */
/*                 VEMS_E_09_08184_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod();               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Wg_EveRst_WgCmdOplBenchMod                                     */
/* !Trigger  : Wg_EveRst_WgCmdOplBenchMod                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_WgCmdOplBenchMod(void)
{
   Wg_CmdBenchMod_vidIniWgCmdOplSpBenchMod();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_WgCmdOplBenchMod                                 */
/* !Description :  Middle schedule of the wastegate function                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_E_09_08184_001.01                                     */
/*                 VEMS_E_09_08184_002.01                                     */
/*                 VEMS_E_09_08184_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod();                */
/*  input uint8 Wg_CmdBenchMod_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : Wg_SdlMid_WgCmdOplBenchMod                                     */
/* !Trigger  : Wg_SdlMid_WgCmdOplBenchMod                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_WgCmdOplBenchMod(void)
{
   if( Wg_CmdBenchMod_u8Inhib != 0x5A )
   {
      Wg_CmdBenchMod_vidCalcWgCmdOplBenchMod();
   }
}