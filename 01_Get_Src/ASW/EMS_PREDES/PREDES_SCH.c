/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PREDES                                                  */
/* !Description     : PREDES Component.                                       */
/*                                                                            */
/* !Module          : PREDES                                                  */
/* !Description     : Engine speed prediction during the engine stop          */
/*                                                                            */
/* !File            : PREDES_SCH.C                                            */
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
/*   1 / PredEs_vidEntryInit                                                  */
/*   2 / PredEs_Sdl10ms_PredEs                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5141019 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_3146 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#053617                                         */
/* !OtherRefs   : VEMS V02 ECU#062167                                         */
/* !OtherRefs   : VEMS V02 ECU#064286                                         */
/* !OtherRefs   : VEMS V02 ECU#065488                                         */
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
#include "PREDES.h"
#include "PREDES_L.h"
#include "PREDES_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PredEs_vidEntryInit                                        */
/* !Description :  Événement reset calculateur.                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_001.02                                     */
/*                 VEMS_R_11_01167_002.01                                     */
/*                 VEMS_R_11_01167_003.01                                     */
/*                 VEMS_R_11_01167_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PredEs_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PredEs_vidEntryInit(void)
{
   PREDES_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PredEs_Sdl10ms_PredEs                                      */
/* !Description :  Accroche moniteur 10 ms.                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_11_01167_001.02                                     */
/*                 VEMS_R_11_01167_002.01                                     */
/*                 VEMS_R_11_01167_003.01                                     */
/*                 VEMS_R_11_01167_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PREDES_vidGlobalView();                                  */
/*  input uint8 PREDES_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PredEs_Sdl10ms_PredEs                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PredEs_Sdl10ms_PredEs(void)
{
   /*QAC Msg(2:4152): Name imposed by specification*/
   if (PREDES_u8Inhib != 0x5A)
   {
      PREDES_vidGlobalView();
   }
}
/*------------------------------- end of file --------------------------------*/