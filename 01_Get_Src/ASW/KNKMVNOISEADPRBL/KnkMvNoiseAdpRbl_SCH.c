/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkMvNoiseAdpRbl                                        */
/* !Description     : KnkMvNoiseAdpRbl component.                             */
/*                                                                            */
/* !Module          : KnkMvNoiseAdpRbl                                        */
/* !Description     : ADAPTATION OF THE AVERAGE ENGINE NOISE (RUMBLE)         */
/*                                                                            */
/* !File            : KnkMvNoiseAdpRbl_SCH.C                                  */
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
/*   1 / KnkTreat_EveStTR_KnkMvNoisAdpRbl                                     */
/*   2 / KnkTreat_EveRbl_KnkMvNoiseAdpRbl                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 02582 / 4                                         */
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
#include "KnkMvNoiseAdpRbl.h"
#include "KnkMvNoiseAdpRbl_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveStTR_KnkMvNoisAdpRbl                           */
/* !Description :  Evénement calé tournant.                                   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_10_02582_001.02                                     */
/*                 VEMS_E_10_02582_002.01                                     */
/*                 VEMS_E_10_02582_003.01                                     */
/*                 VEMS_E_10_02582_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkMvNoiseAdpRbl_vidInit_adaptation_knk();               */
/*  input uint8 KnkMvNoiseAdpRbl_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :  KnkTreat_EveStTR_KnkMvNoisAdpRbl                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveStTR_KnkMvNoisAdpRbl(void)
{
   if (KnkMvNoiseAdpRbl_u8Inhib != 0x5A)
   {
      KnkMvNoiseAdpRbl_vidInit_adaptation_knk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRbl_KnkMvNoiseAdpRbl                           */
/* !Description :  Tâche de calcul rumble                                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_10_02582_001.02                                     */
/*                 VEMS_E_10_02582_002.01                                     */
/*                 VEMS_E_10_02582_003.01                                     */
/*                 VEMS_E_10_02582_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkMvNoiseAdpRbl_vidEnable_Adaptation();                 */
/*  input uint8 KnkMvNoiseAdpRbl_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRbl_KnkMvNoiseAdpRbl                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRbl_KnkMvNoiseAdpRbl(void)
{
   if (KnkMvNoiseAdpRbl_u8Inhib != 0x5A)
   {
      KnkMvNoiseAdpRbl_vidEnable_Adaptation();
   }
}

/*------------------------------- end of file --------------------------------*/