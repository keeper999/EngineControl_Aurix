/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RBLDETBENCH                                             */
/* !Description     : RBLDETBENCH component.                                  */
/*                                                                            */
/* !Module          : RBLDETBENCH                                             */
/* !Description     : MODE BANC POUR LA CALIBRATION DE LA DETECTION RUMBLE    */
/*                                                                            */
/* !File            : RBLDETBENCH_SCH.C                                       */
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
/*   1 / RBLDETBENCH_vidEntryInit                                             */
/*   2 / KnkTreat_EveRbl_RblDetBench                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 02549 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#060167                                         */
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
#include "RBLDETBENCH.h"
#include "RBLDETBENCH_L.h"
#include "RBLDETBENCH_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLDETBENCH_vidEntryInit                                   */
/* !Description :  initialisation des variables prev.                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLDETBENCH_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RBLDETBENCH_vidEntryInit                                       */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLDETBENCH_vidEntryInit(void)
{
   RBLDETBENCH_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_RblDetBench                                */
/* !Description :  Tâche Rumble pour le mode banc détection.                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_02549_001.01                                     */
/*                 VEMS_E_11_02549_002.01                                     */
/*                 VEMS_E_11_02549_003.01                                     */
/*                 VEMS_E_11_02549_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLDETBENCH_vidRbl_Test_bed();                           */
/*  input uint8 RBLDETBENCH_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_RblDetBench                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_RblDetBench(void)
{
   if (RBLDETBENCH_u8Inhib != 0x5A)
   {
      RBLDETBENCH_vidRbl_Test_bed();
   }
}

/*------------------------------- end of file --------------------------------*/