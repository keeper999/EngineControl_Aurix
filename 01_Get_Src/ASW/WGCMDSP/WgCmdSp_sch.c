/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WgCmdSp                                                 */
/* !Description     : WgCmdSp component.                                      */
/*                                                                            */
/* !Module          : WgCmdSp                                                 */
/* !Description     : WASTEGATE SOLENOID VALVE COMMAND SETPOINT               */
/*                                                                            */
/* !File            : WGCMDSP_SCH.C                                           */
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
/*   1 / Wg_EveRst_WgCmdSp                                                    */
/*   2 / Wg_SdlMid_WgCmdSp                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5070689 / 02                                        */
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
#include "WGCMDSP.h"
#include "WGCMDSP_L.h"
#include "WGCMDSP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_WgCmdSp                                          */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_10_02948_001.01                                     */
/*                 VEMS_E_10_02948_002.01                                     */
/*                 VEMS_E_10_02948_003.01                                     */
/*                 VEMS_E_10_02948_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidInit();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_WgCmdSp                                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_WgCmdSp(void)
{
   WgCmdSp_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_WgCmdSp                                          */
/* !Description :  Middle schedule of the wastegate function                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_E_10_02948_002.01                                     */
/*                 VEMS_E_10_02948_003.01                                     */
/*                 VEMS_E_10_02948_004.01                                     */
/*                 VEMS_E_10_02948_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WgCmdSp_vidClcPwmWg();                                   */
/*  extf argret void WgCmdSp_vidSumElmPIDA();                                 */
/*  input uint8 WGCMDSP_u8Inhib;                                              */
/*  input boolean Wg_bSelWgCmdSp_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_WgCmdSp                                              */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_WgCmdSp(void)
{
   if (WGCMDSP_u8Inhib != 0x5A)
   {
      if (Wg_bSelWgCmdSp_C != 0)
      {
         WgCmdSp_vidClcPwmWg();
         WgCmdSp_vidSumElmPIDA();
      }
   }
}
/*------------------------------- end of file --------------------------------*/