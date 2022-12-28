/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2US                                             */
/* !Description     : HEATSENO2US Component                                   */
/*                                                                            */
/* !Module          : HEATSENO2US                                             */
/* !Description     : GESTION CHAUFFAGE SONDE AMONT                           */
/*                                                                            */
/* !File            : HEATSENO2US_SCH.C                                       */
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
/*   1 / HeatSenO2_EveRst_UsMgr                                               */
/*   2 / HeatSenO2_SdlFast_UsMgr                                              */
/*   3 / HeatSenO2_SdlMid_UsMgr                                               */
/*   4 / HeatSenO2_SdlSlow_UsMgr                                              */
/*   5 / HeatSenO2_EveStTCr_UsMgr                                             */
/*   6 / HeatSenO2_EveCrTR_UsMgr                                              */
/*   7 / HeatSenO2_EveRTSt_UsMgr                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5211932 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#061098                                         */
/* !OtherRefs   : VEMS V02 ECU#066573                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/HEATSENO2/HEATSENO2US/HEATSENO2U$*/
/* $Revision::   1.6      $$Author::   etsasson       $$Date::   26 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2US.h"
#include "HEATSENO2US_L.h"
#include "HEATSENO2US_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_UsMgr                                     */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidInitOutput();                             */
/*  extf argret void HEATSENO2US_vidLsUsDetRTStallint();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRst_UsMgr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_UsMgr(void)
{
   HEATSENO2US_vidInitOutput();
   HEATSENO2US_vidLsUsDetRTStallint();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_UsMgr                                    */
/* !Description :  Moniteur rapide pour le module chauffage sonde O2          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidMgrFastTran();                            */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_UsMgr                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidMgrFastTran();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_UsMgr                                     */
/* !Description :  Moniteur moyen pour le module chauffage sonde O2           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidAcvHeatWku();                             */
/*  extf argret void HEATSENO2US_vidTReCoLsHeat();                            */
/*  extf argret void HEATSENO2US_vidOxCHeatAftStrt();                         */
/*  extf argret void HEATSENO2US_vidLsUsDewPt();                              */
/*  extf argret void HEATSENO2US_vidFastLightOff();                           */
/*  extf argret void HEATSENO2US_vidMgrMidTran();                             */
/*  extf argret void HEATSENO2US_vidLsUsMgrHeatState();                       */
/*  extf argret void HEATSENO2US_vidOxCHeatReq();                             */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlMid_UsMgr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidAcvHeatWku();
      HEATSENO2US_vidTReCoLsHeat();
      HEATSENO2US_vidOxCHeatAftStrt();
      HEATSENO2US_vidLsUsDewPt();
      HEATSENO2US_vidFastLightOff();
      HEATSENO2US_vidMgrMidTran();
      HEATSENO2US_vidLsUsMgrHeatState();
      HEATSENO2US_vidOxCHeatReq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlSlow_UsMgr                                    */
/* !Description :  Moniteur lent pour le module chauffage sonde O2            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidMgrSlowTran();                            */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlSlow_UsMgr                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlSlow_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidMgrSlowTran();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveStTCr_UsMgr                                   */
/* !Description :  Evenement de détection du passage de l'état stall vers     */
/*                 cranking                                                   */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidLsUsDetRTStallint();                      */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveStTCr_UsMgr       								  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveStTCr_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidLsUsDetRTStallint();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveCrTR_UsMgr                                    */
/* !Description :  Evénement de détection le passage de cranking vers running */
/* !Number      :  SCH.6                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidLsUsDetRTStallint();                      */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveCrTR_UsMgr									      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveCrTR_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidLsUsDetRTStallint();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRTSt_UsMgr                                    */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.7                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_12_01117_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2US_vidLsUsDetRTStall();                         */
/*  input uint8 HEATSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRTSt_UsMgr    								      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRTSt_UsMgr(void)
{
   if (HEATSENO2US_u8Inhib != 0x5A)
   {
      HEATSENO2US_vidLsUsDetRTStall();
   }
}
/*------------------------------- end of file --------------------------------*/