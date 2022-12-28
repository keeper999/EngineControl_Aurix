/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WgCmdSpArb                                              */
/* !Description     : WgCmdSpArb component.                                   */
/*                                                                            */
/* !Module          : WgCmdSpArb                                              */
/* !Description     : WASTEGATE COMMAND ARBITRATION                           */
/*                                                                            */
/* !File            : WGCMDSPARB_SCH.C                                        */
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
/*   1 / Wg_EveRst_WgCmdSpArb                                                 */
/*   2 / Wg_SdlMid_WgCmdSpArb                                                 */
/*                                                                            */
/* !Reference   : V02 NT 10 02950 / 05                                        */
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
#include "WGCMDSPARB.h"
#include "WGCMDSPARB_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_EveRst_WgCmdSpArb                                       */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_E_10_02950_001.02                                     */
/*                 VEMS_E_10_02950_002.02                                     */
/*                 VEMS_E_10_02950_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WGCMDSPARB_vidWgArb();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_EveRst_WgCmdSpArb                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_EveRst_WgCmdSpArb(void)
{
   WGCMDSPARB_vidWgArb();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Wg_SdlMid_WgCmdSpArb                                       */
/* !Description :  Middle schedule of the wastegate function                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_E_10_02950_001.02                                     */
/*                 VEMS_E_10_02950_002.02                                     */
/*                 VEMS_E_10_02950_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WGCMDSPARB_vidWgArb();                                   */
/*  input uint8 WGCMDSPARB_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Wg_SdlMid_WgCmdSpArb                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Wg_SdlMid_WgCmdSpArb(void)
{
   if (WGCMDSPARB_u8Inhib != 0x5A)
   {
      WGCMDSPARB_vidWgArb();
   }
}
/*------------------------------- end of file --------------------------------*/