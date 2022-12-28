/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJCTL_INJFARCTLMGR                                     */
/* !Description     : INJCTL_INJFARCTLMGR component.                          */
/*                                                                            */
/* !Module          : INJCTL_INJFARCTLMGR                                     */
/* !Description     : MANAGER DE GESTION DE LA REGULATION DE RICHESSE         */
/*                                                                            */
/* !File            : INJCTL_INJFARCTLMGR_SCH.C                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / InjCtl_EveRst_FarCtlMgr                                              */
/*   2 / InjCtl_EveRTSt_FarCtlMgr                                             */
/*   3 / InjCtl_EveCrTR_FarCtlMgr                                             */
/*   4 / InjCtl_SdlFast_FarCtlMgr                                             */
/*   5 / InjCtl_SdlSlow_FarCtlMgr                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5147287 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJCTL_INJFARCTLMGR/IN$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   08 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   08 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INJCTL_INJFARCTLMGR.h"
#include "INJCTL_INJFARCTLMGR_L.h"
#include "INJCTL_INJFARCTLMGR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRst_FarCtlMgr                                    */
/* !Description :  Evènement de Reset du calculateur                          */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_08_05763_007.01                                     */
/*                 VEMS_E_08_05763_008.01                                     */
/*                 VEMS_E_08_05763_009.01                                     */
/*                 VEMS_E_08_05763_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidInit();                           */
/*  extf argret void INJCTL_INJFARCTLMGR_vidInitFdbk();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveRst_FarCtlMgr                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRst_FarCtlMgr(void)
{
   INJCTL_INJFARCTLMGR_vidInit();
   INJCTL_INJFARCTLMGR_vidInitFdbk();

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRTSt_FarCtlMgr                                   */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_08_05763_007.01                                     */
/*                 VEMS_E_08_05763_008.01                                     */
/*                 VEMS_E_08_05763_009.01                                     */
/*                 VEMS_E_08_05763_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidInit();                           */
/*  extf argret void INJCTL_INJFARCTLMGR_vidInitFdbk();                       */
/*  input uint8 INJCTL_INJFARCTLMGR_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveRTSt_FarCtlMgr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRTSt_FarCtlMgr(void)
{
   if ( INJCTL_INJFARCTLMGR_u8Inhib != 0x5A )
   {
      INJCTL_INJFARCTLMGR_vidInit();
      INJCTL_INJFARCTLMGR_vidInitFdbk();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveCrTR_FarCtlMgr                                   */
/* !Description :  Evènement de CRANKING vers RUNNING                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_08_05763_007.01                                     */
/*                 VEMS_E_08_05763_008.01                                     */
/*                 VEMS_E_08_05763_009.01                                     */
/*                 VEMS_E_08_05763_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidInitDelay();                      */
/*  input uint8 INJCTL_INJFARCTLMGR_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveCrTR_FarCtlMgr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveCrTR_FarCtlMgr(void)
{
   if ( INJCTL_INJFARCTLMGR_u8Inhib != 0x5A )
   {
      INJCTL_INJFARCTLMGR_vidInitDelay();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlFast_FarCtlMgr                                   */
/* !Description :  Moniteur rapide de la fonction régulation de richesse      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_08_05763_007.01                                     */
/*                 VEMS_E_08_05763_008.01                                     */
/*                 VEMS_E_08_05763_009.01                                     */
/*                 VEMS_E_08_05763_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidFSM();                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidDiagCata();                       */
/*  input uint8 INJCTL_INJFARCTLMGR_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlFast_FarCtlMgr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlFast_FarCtlMgr(void)
{
   if ( INJCTL_INJFARCTLMGR_u8Inhib != 0x5A )
   {
      INJCTL_INJFARCTLMGR_vidFSM();
      INJCTL_INJFARCTLMGR_vidDiagCata();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlSlow_FarCtlMgr                                   */
/* !Description :  Moniteur lent de la fonction régulation de richesse        */
/* !Number      :  SCH.5                                                      */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_E_08_05763_007.01                                     */
/*                 VEMS_E_08_05763_008.01                                     */
/*                 VEMS_E_08_05763_009.01                                     */
/*                 VEMS_E_08_05763_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidDecDelay();                       */
/*  input uint8 INJCTL_INJFARCTLMGR_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlSlow_FarCtlMgr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlSlow_FarCtlMgr(void)
{
   if ( INJCTL_INJFARCTLMGR_u8Inhib != 0x5A )
   {
      INJCTL_INJFARCTLMGR_vidDecDelay();
   }
}
/*------------------------------ end of file ---------------------------------*/