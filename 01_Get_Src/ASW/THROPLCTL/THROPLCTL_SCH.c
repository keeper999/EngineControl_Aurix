/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THROPLCTL                                               */
/* !Description     : THROPLCTL Component.                                    */
/*                                                                            */
/* !Module          : THROPLCTL                                               */
/* !Description     : COMMANDE EN BOUCLE OUVERTE DU PAPILLON                  */
/*                                                                            */
/* !File            : THROPLCTL_SCH.C                                         */
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
/*   1 / Thr_EveRst_OplCtl                                                    */
/*   2 / Thr_SdlFast_OplCtl                                                   */
/*   3 / Thr_SdlMid_OplCtl                                                    */
/*                                                                            */
/* !Reference   : V02 NT 08 04793 / 08                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THROPLCTL/THROPLCTL_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   FMERAH1        $$Date::   Apr 19 2012 $*/
/* $Author::   FMERAH1                                $$Date::   Apr 19 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THROPLCTL.h"
#include "THROPLCTL_L.h"
#include "THROPLCTL_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_OplCtl                                          */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  FMERAH1                                                    */
/* !Trace_To    :  VEMS_E_08_04793_002.01                                     */
/*                 VEMS_E_08_04793_001.01                                     */
/*                 VEMS_E_08_04793_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THROPLCTL_vidInitOutput();                               */
/*  extf argret void THROPLCTL_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : THROPLCTL_vidEntryInit                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_OplCtl(void)
{
   THROPLCTL_vidInitOutput();
   THROPLCTL_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlFast_OplCtl                                         */
/* !Description :  Moniteur rapide pour la fonction papillon                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  FMERAH1                                                    */
/* !Trace_To    :  VEMS_E_08_04793_002.01                                     */
/*                 VEMS_E_08_04793_001.01                                     */
/*                 VEMS_E_08_04793_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THROPLCTL_vidInitMcwInh();                               */
/*  input uint8 THROPLCTL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlFast_OplCtl                                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlFast_OplCtl(void)
{
   if (THROPLCTL_u8Inhib != 0x5A)
   {
      THROPLCTL_vidInitMcwInh();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_OplCtl                                          */
/* !Description :  Moniteur moyen pour la fonction papillon                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  FMERAH1                                                    */
/* !Trace_To    :  VEMS_E_08_04793_002.01                                     */
/*                 VEMS_E_08_04793_001.01                                     */
/*                 VEMS_E_08_04793_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THROPLCTL_vidConditions();                               */
/*  extf argret void THROPLCTL_vidCalcOpeningRamp();                          */
/*  extf argret void THROPLCTL_vidCalcClosingRamp();                          */
/*  extf argret void THROPLCTL_vidCalcExitLowThrust();                        */
/*  extf argret void THROPLCTL_vidInitMcpInh();                               */
/*  extf argret void THROPLCTL_CalcWaitAdc();                                 */
/*  input uint8 THROPLCTL_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_OplCtl                                              */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_OplCtl(void)
{
   if (THROPLCTL_u8Inhib != 0x5A)
   {
      THROPLCTL_vidConditions();
      THROPLCTL_vidCalcOpeningRamp();
      THROPLCTL_vidCalcClosingRamp();
      THROPLCTL_vidCalcExitLowThrust();
      THROPLCTL_vidInitMcpInh();
      THROPLCTL_CalcWaitAdc();
   }
}

/*----------------------------- end of file ----------------------------------*/