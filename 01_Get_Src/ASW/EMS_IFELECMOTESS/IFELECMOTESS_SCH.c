/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFELECMOTESS                                            */
/* !Description     : IFELECMOTESS component.                                 */
/*                                                                            */
/* !Module          : IFELECMOTESS                                            */
/* !Description     : INTERFACE BESOIN ELECTRIQUE MOTEUR ESSENCE              */
/*                                                                            */
/* !File            : IFELECMOTESS_SCH.C                                      */
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
/*   1 / IFELECMOTESS_vidEntryInit                                            */
/*   2 / IfEngReq_Sdl10ms_Cord                                                */
/*                                                                            */
/* !Reference   : V02 NT 12 00929 / 01                                        */
/* !OtherRefs   : 01460_11_00542_1 / 2.1                                      */
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
#include "IFELECMOTESS.h"
#include "IFELECMOTESS_L.h"
#include "IFELECMOTESS_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFELECMOTESS_vidEntryInit                                  */
/* !Description :  Evennement Reset                                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_12_00929_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFELECMOTESS_vidInitOutput();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFELECMOTESS_vidEntryInit                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFELECMOTESS_vidEntryInit(void)
{
   IFELECMOTESS_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IfEngReq_Sdl10ms_Cord                                      */
/* !Description :  La fonction est appelée toutes les 10 ms.                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_12_00929_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFELECMOTESS_vidByte_carrier();                          */
/*  input uint8 IFELECMOTESS_u8Inhib;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IfEngReq_Sdl10ms_Cord                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IfEngReq_Sdl10ms_Cord(void)
{
   /*QAC Msg(2:4152): Name Imposed By Specification*/
   if (IFELECMOTESS_u8Inhib != 0x5A)
   {
      IFELECMOTESS_vidByte_carrier();
   }
}
/*-------------------------------- End of file -------------------------------*/