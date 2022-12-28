/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AUTHSTRTSTT                                             */
/* !Description     : AUTHSTRTSTT Component                                   */
/*                                                                            */
/* !Module          : AUTHSTRTSTT                                             */
/* !Description     : Pilotage Autorisation de redémarrage STT                */
/*                                                                            */
/* !File            : AUTHSTRTSTT_SCH.C                                       */
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
/*   1 / EngSt_EveRst_AuthStrtSTT                                             */
/*   2 / EngSt_SdlFast_AuthStrtSTT                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6525148 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/AUTHSTRTSTT/AUTHSTRTSTT_SCH.C_v   $*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AUTHSTRTSTT.h"
#include "AUTHSTRTSTT_L.h"
#include "AUTHSTRTSTT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_AuthStrtSTT                                   */
/* !Description :  Evenement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_12_01002_001.01                                     */
/*                 VEMS_E_12_01002_002.01                                     */
/*                 VEMS_E_12_01002_003.01                                     */
/*                 VEMS_E_12_01002_004.01                                     */
/*                 VEMS_E_12_01002_005.01                                     */
/*                 VEMS_E_12_01002_006.01                                     */
/*                 VEMS_E_12_01002_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AUTHSTRTSTT_vidInitialisation();                         */
/*  extf argret void AUTHSTRTSTT_vidInhCrkAltHw();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : EngSt_EveRst_AuthStrtSTT                                       */
/* !Trigger  : EngSt_EveRst_AuthStrtSTT                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_AuthStrtSTT(void)
{
   AUTHSTRTSTT_vidInitialisation();
   AUTHSTRTSTT_vidInhCrkAltHw();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_AuthStrtSTT                                  */
/* !Description :  Moniteur rapide pour la fonction CallMng                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_12_01002_001.01                                     */
/*                 VEMS_E_12_01002_002.01                                     */
/*                 VEMS_E_12_01002_003.01                                     */
/*                 VEMS_E_12_01002_004.01                                     */
/*                 VEMS_E_12_01002_005.01                                     */
/*                 VEMS_E_12_01002_006.01                                     */
/*                 VEMS_E_12_01002_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AUTHSTRTSTT_vidCallMng();                                */
/*  input uint8 AUTHSTRTSTT_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : EngSt_SdlFast_AuthStrtSTT                                      */
/* !Trigger  : EngSt_SdlFast_AuthStrtSTT                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_AuthStrtSTT(void)
{
   if (AUTHSTRTSTT_u8Inhib != 0x5A)
   {
      AUTHSTRTSTT_vidCallMng();
   }
}
/*---------------------------------End Of File--------------------------------*/