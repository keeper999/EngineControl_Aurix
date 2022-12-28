/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DmpVlvOplCmd                                            */
/* !Description     : DmpVlvOplCmd component.                                 */
/*                                                                            */
/* !Module          : DmpVlvOplCmd                                            */
/* !Description     : DUMP VALVE OPEN LOOP COMMAND SETPOINT                   */
/*                                                                            */
/* !File            : DmpVlvOplCmd_sch.c                                      */
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
/*   1 / DmpVlvAct_EveRst_DmpVlvOplCmd                                        */
/*   2 / DmpVlvAct_SdlMid_DmpVlvOplCmd                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 01292 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "STD_TYPES.h"
#include "DmpVlvOplCmd.h"
#include "DmpVlvOplCmd_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_EveRst_DmpVlvOplCmd                              */
/* !Description :  Event reset  (Outputs initializations)                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DmpVlvOplCmd_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_EveRst_DmpVlvOplCmd                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_EveRst_DmpVlvOplCmd(void)
{
   DmpVlvOplCmd_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlvAct_SdlMid_DmpVlvOplCmd                              */
/* !Description :  Middle scheduler of the Airpres function DmpVlvAct         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DmpVlvOplCmd_vidCalcCmdBModeBenchMod();                  */
/*  input uint8 DmpVlvOplCmd_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlvAct_SdlMid_DmpVlvOplCmd                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlvAct_SdlMid_DmpVlvOplCmd(void)
{
   if(DmpVlvOplCmd_u8Inhib != 0x5A)
   {
      DmpVlvOplCmd_vidCalcCmdBModeBenchMod();
   }
}