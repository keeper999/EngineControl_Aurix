/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DMPVLVCMDSPARB                                          */
/* !Description     : DMPVLVCMDSPARB Component                                */
/*                                                                            */
/* !Module          : DMPVLVCMDSPARB                                          */
/* !Description     : DUMP-VALVE COMMAND ARBITRATION                          */
/*                                                                            */
/* !File            : DMPVLVCMDSPARB_SCH.C                                    */
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
/*   1 / DmpVlv_EveRst_DmpVlvCmdSpArb                                         */
/*   2 / DmpVlv_SdlFast_DmpVlvCmdSpArb                                        */
/*                                                                            */
/* !Reference   : V02 NT 12 02202 / 02                                        */
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

#include "DMPVLVCMDSPARB.h"
#include "DMPVLVCMDSPARB_L.h"
#include "DMPVLVCMDSPARB_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_EveRst_DmpVlvCmdSpArb                               */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_E_12_02202_001.01                                     */
/*                 VEMS_E_12_02202_002.01                                     */
/*                 VEMS_E_12_02202_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DMPVLVCMDSPARB_vidDmpVlvArb();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_EveRst_DmpVlvCmdSpArb                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_EveRst_DmpVlvCmdSpArb(void)
{
   DMPVLVCMDSPARB_vidDmpVlvArb();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DmpVlv_SdlFast_DmpVlvCmdSpArb                              */
/* !Description :  Fast scheduler for the dump-valve function                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_E_12_02202_001.01                                     */
/*                 VEMS_E_12_02202_002.01                                     */
/*                 VEMS_E_12_02202_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DMPVLVCMDSPARB_vidDmpVlvArb();                           */
/*  input uint8 DMPVLVCMDSPARB_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DmpVlv_SdlFast_DmpVlvCmdSpArb                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DmpVlv_SdlFast_DmpVlvCmdSpArb(void)
{
   if (DMPVLVCMDSPARB_u8Inhib != 0x5A)
   {
      DMPVLVCMDSPARB_vidDmpVlvArb();
   }
}
/*------------------------------- end of file --------------------------------*/