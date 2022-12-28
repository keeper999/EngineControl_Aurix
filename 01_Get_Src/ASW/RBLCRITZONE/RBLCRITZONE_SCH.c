/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RBLCRITZONE                                             */
/* !Description     : RBLCRITZONE Component                                   */
/*                                                                            */
/* !Module          : RBLCRITZONE                                             */
/* !Description     : Rumble Critical Zone Detection                          */
/*                                                                            */
/* !File            : RBLCRITZONE_SCH.C                                       */
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
/*   1 / KnkTreat_EveRst_RblCritZone                                          */
/*   2 / KnkTreat_EveCrTR_RblCritZone                                         */
/*   3 / KnkTreat_EveRTCr_RblCritZone                                         */
/*   4 / KnkTreat_EveBDC_RblCritZone                                          */
/*                                                                            */
/* !Reference   : V02 NT 12 00518 / 01                                        */
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

#include "RBLCRITZONE.h"
#include "RBLCRITZONE_L.h"
#include "RBLCRITZONE_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_RblCritZone                                */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_12_00518_001.01                                     */
/*                 VEMS_E_12_00518_002.01                                     */
/*                 VEMS_E_12_00518_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLCRITZONE_vidInitialization();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_RblCritZone                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_RblCritZone(void)
{
   RBLCRITZONE_vidInitialization();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveCrTR_RblCritZone                               */
/* !Description :  Evénement CRANKING vers RUNNING                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_12_00518_001.01                                     */
/*                 VEMS_E_12_00518_002.01                                     */
/*                 VEMS_E_12_00518_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLCRITZONE_vidInitialization();                         */
/*  input uint8 RBLCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveCrTR_RblCritZone                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveCrTR_RblCritZone(void)
{
   if (RBLCRITZONE_u8Inhib != 0x5A)
   {
      RBLCRITZONE_vidInitialization();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRTCr_RblCritZone                               */
/* !Description :  Evénement RUNNING vers CRANKING                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_12_00518_001.01                                     */
/*                 VEMS_E_12_00518_002.01                                     */
/*                 VEMS_E_12_00518_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLCRITZONE_vidInitialization();                         */
/*  input uint8 RBLCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRTCr_RblCritZone                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRTCr_RblCritZone(void)
{
   if (RBLCRITZONE_u8Inhib != 0x5A)
   {
      RBLCRITZONE_vidInitialization();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveBDC_RblCritZone                                */
/* !Description :  Interruption PMB                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_12_00518_001.01                                     */
/*                 VEMS_E_12_00518_002.01                                     */
/*                 VEMS_E_12_00518_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RBLCRITZONE_vidComputeCritZone();                        */
/*  input uint8 RBLCRITZONE_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveBDC_RblCritZone                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveBDC_RblCritZone(void)
{
   if (RBLCRITZONE_u8Inhib != 0x5A)
   {
      RBLCRITZONE_vidComputeCritZone();
   }
}

/*------------------------------- end of file --------------------------------*/