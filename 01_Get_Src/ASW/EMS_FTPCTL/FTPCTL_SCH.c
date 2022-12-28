/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FTPCTL                                                  */
/* !Description     : FTPCTL component                                        */
/*                                                                            */
/* !Module          : FTPCTL                                                  */
/* !Description     : Fuel Transfer Pump Control (FTPCtl)                     */
/*                                                                            */
/* !File            : FTPCTL_SCH.C                                            */
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
/*   1 / FTPCTL_vidEntryInit                                                  */
/*   2 / FTPCtl_Sdl10ms_FTPCtl                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5139357 / 02                                        */
/* !OtherRefs   : 01460_10_02425 / 3.3                                        */
/* !OtherRefs   : VEMS V02 ECU#067192                                         */
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
#include "FTPCTL.h"
#include "FTPCTL_l.h"
#include "FTPCTL_IM.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCTL_vidEntryInit                                        */
/* !Description :  Event reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FTPCTL_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FTPCTL_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCTL_vidEntryInit(void)
{
   FTPCTL_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FTPCtl_Sdl10ms_FTPCtl                                      */
/* !Description :  Monitor of the FTPCTL function                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_11_02548_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FTPCTL_vidEngine_need_calculus();                        */
/*  extf argret void FTPCTL_vidWorking_field();                               */
/*  extf argret void FTPCTL_vidVolt_Control_activ();                          */
/*  extf argret void FTPCTL_vidPriming_need();                                */
/*  extf argret void FTPCTL_vidPressHoldCaseCutStall();                       */
/*  extf argret void FTPCTL_vidPressHoldEngineActive();                       */
/*  extf argret void FTPCTL_vidPressure_hold_in_gas();                        */
/*  extf argret void FTPCTL_vidFlowSetpointSynthesis();                       */
/*  extf argret void FTPCTL_vidRecovryModesActivation();                      */
/*  input uint8 FTPCTL_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FTPCtl_Sdl10ms_FTPCtl                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FTPCtl_Sdl10ms_FTPCtl(void)
{
   /*QAC Warning, Msg(2:4152) --> sched name imposed by specification*/
   if (FTPCTL_u8Inhib != 0x5A)
   {
      FTPCTL_vidEngine_need_calculus();
      FTPCTL_vidWorking_field();
      FTPCTL_vidVolt_Control_activ();
      FTPCTL_vidPriming_need();
      FTPCTL_vidPressHoldCaseCutStall();
      FTPCTL_vidPressHoldEngineActive();
      FTPCTL_vidPressure_hold_in_gas();
      FTPCTL_vidFlowSetpointSynthesis();
      FTPCTL_vidRecovryModesActivation();
   }
}
/*---------------------------------End Of File--------------------------------*/