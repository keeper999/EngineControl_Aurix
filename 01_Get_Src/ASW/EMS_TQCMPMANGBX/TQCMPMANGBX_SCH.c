/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCMPMANGBX                                             */
/* !Description     : TQCMPMANGBX Component                                   */
/*                                                                            */
/* !Module          : TQCMPMANGBX                                             */
/* !Description     : ESTIMATION OF MANUAL GEARBOX LOSSES                     */
/*                                                                            */
/* !File            : TQCMPMANGBX_SCH.C                                       */
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
/*   1 / TQCMPMANGBX_vidEntryInit                                             */
/*   2 / TqSys_Sdl20ms_TqCmpManGBx                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5199347 / 01                                        */
/* !OtherRefs   : 01460_12_02440 / 1.1                                        */
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
#include "TQCMPMANGBX.h"
#include "TQCMPMANGBX_L.h"
#include "TQCMPMANGBX_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCMPMANGBX_vidEntryInit                                   */
/* !Description :  Evenement d'initialisation des sorties                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  PTS_R_5199347_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCMPMANGBX_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TQCMPMANGBX_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCMPMANGBX_vidEntryInit(void)
{
   TQCMPMANGBX_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TqSys_Sdl20ms_TqCmpManGBx                                  */
/* !Description :  Function scheduling                                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  PTS_R_5199347_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCMPMANGBX_vidManualGearBoxLoss();                      */
/*  input uint8 TQCMPMANGBX_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : TqSys_Sdl20ms_TqCmpManGBx                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TqSys_Sdl20ms_TqCmpManGBx(void)
{
   if (TQCMPMANGBX_u8Inhib != 0x5A)
   {
      TQCMPMANGBX_vidManualGearBoxLoss();
   }
}
/*------------------------------end of file-----------------------------------*/