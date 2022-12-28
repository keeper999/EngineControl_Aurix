/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTAB                                                 */
/* !Description     : ENGSTAB component.                                      */
/*                                                                            */
/* !Module          : ENGSTAB                                                 */
/* !Description     : Engine Stabilised                                       */
/*                                                                            */
/* !File            : ENGSTAB_SCH.C                                           */
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
/*   1 / EngSt_EveRst_EngStab                                                 */
/*   2 / EngSt_SdlMid_EngStab                                                 */
/*                                                                            */
/* !Reference   : V02 NT 09 03216 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ENGSTAB/ENGSTAB_SCH.C_v           $*/
/* $Revision::   1.1      $$Author::   wbouach        $$Date::   02 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   02 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGSTAB.h"
#include "ENGSTAB_L.h"
#include "ENGSTAB_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngStab                                       */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidInitEngineStabilised();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngStab                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngStab(void)
{
   ENGSTAB_vidInitEngineStabilised();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlMid_EngStab                                       */
/* !Description :  Moniteur moyen de la fonction EngSt.                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Wael.Chambah                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGSTAB_vidCalcEngineStabilised();                       */
/*  input uint8 ENGSTAB_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlMid_EngStab                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlMid_EngStab(void)
{
   if (ENGSTAB_u8Inhib != 0x5A)
   {
      ENGSTAB_vidCalcEngineStabilised();
   }
}

/*------------------------------- end of file --------------------------------*/