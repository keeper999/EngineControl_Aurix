/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLUSCTL                                          */
/* !Description     : INJFARCTLUSCTL component                                */
/*                                                                            */
/* !Module          : INJFARCTLUSCTL                                          */
/* !Description     : CALCUL DE LA BOUCLE FERMEE DE LA REGULATION DE RICHESSE */
/*                    AVEC SONDE AMONT                                        */
/*                                                                            */
/* !File            : INJFARCTLUSCTL_SCH.c                                    */
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
/*   1 / InjCtl_EveFbEnad_FarCtlMgr                                           */
/*   2 / InjCtl_EveFbForSafEnad_FarCtlMgr                                     */
/*   3 / InjCtl_EveIniClsdLoop_FarCtlMgr                                      */
/*   4 / InjCtl_EveIniFbClcn_FarCtlMgr                                        */
/*   5 / InjCtl_EveIniFbPrm_FarCtlMgr                                         */
/*   6 / InjCtl_EveRTSt_FarCtlUsCtl                                           */
/*   7 / InjCtl_EveReIniFbSaf_FarCtlMgr                                       */
/*   8 / InjCtl_EveRstLbdFb_FarCtlMgr                                         */
/*   9 / InjCtl_EveRst_InjFarCtlUsCtl                                         */
/*   10 / InjCtl_EveTDC_FarCtlUsCtl                                           */
/*   11 / InjCtl_SdlFast_FarCtlUsCtl                                          */
/*   12 / InjCtl_EveMonrFbCdn_FarCtlMgr                                       */
/*   13 / InjCtl_EveFbDisab_FarCtlMgr                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5215083 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJFARCTLUSCTL/INJFARC$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   18 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   18 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveFbEnad_FarCtlMgr                                 */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveFbEnad_FarCtlMgr   */
/* !Number      :  SCH.1                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidFFastTracking();                       */
/*  extf argret void INJFARCTLUSCTL_vidIniUplamMaxMin();                      */
/*  extf argret void INJFARCTLUSCTL_vidMgtFeedCalc();                         */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveFbEnad_FarCtlMgr                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveFbEnad_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidFFastTracking();
      INJFARCTLUSCTL_vidIniUplamMaxMin();
      INJFARCTLUSCTL_vidMgtFeedCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveFbForSafEnad_FarCtlMgr                           */
/* !Description :  Fonction d'accroche à l'event                              */
/*                 InjCtl_EveFbForSafEnad_FarCtlMgr                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidMonitorFedSaf();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveFbForSafEnad_FarCtlMgr                               */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveFbForSafEnad_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidMonitorFedSaf();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveIniClsdLoop_FarCtlMgr                            */
/* !Description :  Fonction d'accroche à l 'event                             */
/*                 InjCtl_EveIniClsdLoop_FarCtlMgr                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidInitClosedLoop();                      */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveIniClsdLoop_FarCtlMgr                                */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveIniClsdLoop_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidInitClosedLoop();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveIniFbClcn_FarCtlMgr                              */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveIniFbClcn_FarCtlMgr*/
/* !Number      :  SCH.4                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidIniUplamMaxMin();                      */
/*  extf argret void INJFARCTLUSCTL_vidInitFeedCalc();                        */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveIniFbClcn_FarCtlMgr                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveIniFbClcn_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidIniUplamMaxMin();
      INJFARCTLUSCTL_vidInitFeedCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveIniFbPrm_FarCtlMgr                               */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveIniFbPrm_FarCtlMgr */
/* !Number      :  SCH.5                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidInitFeedParam();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveIniFbPrm_FarCtlMgr                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveIniFbPrm_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidInitFeedParam();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRTSt_FarCtlUsCtl                                 */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveRTSt_FarCtlUsCtl   */
/* !Number      :  SCH.6                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidInit();                                */
/*  extf argret void INJFARCTLUSCTL_vidMonitorFedSaf();                       */
/*  extf argret void INJFARCTLUSCTL_vidIniUplamMaxMin();                      */
/*  extf argret void INJFARCTLUSCTL_vidInitFeedState();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveRTSt_FarCtlUsCtl                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRTSt_FarCtlUsCtl(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidInit();
      INJFARCTLUSCTL_vidMonitorFedSaf();
      INJFARCTLUSCTL_vidIniUplamMaxMin();
      INJFARCTLUSCTL_vidInitFeedState();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveReIniFbSaf_FarCtlMgr                             */
/* !Description :  Fonction d'accroche à l'event                              */
/*                 InjCtl_EveReIniFbSaf_FarCtlMgr                             */
/* !Number      :  SCH.7                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidMonitorFedSaf();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveReIniFbSaf_FarCtlMgr                                 */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveReIniFbSaf_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidMonitorFedSaf();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRstLbdFb_FarCtlMgr                               */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveRstLbdFb_FarCtlMgr */
/* !Number      :  SCH.8                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidResetLFB();                            */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveRstLbdFb_FarCtlMgr                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRstLbdFb_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidResetLFB();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveRst_InjFarCtlUsCtl                               */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveRst_InjFarCtlUsCtl */
/* !Number      :  SCH.9                                                      */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidInit();                                */
/*  extf argret void INJFARCTLUSCTL_vidInitFedSaf();                          */
/*  extf argret void INJFARCTLUSCTL_vidIniUplamMaxMin();                      */
/*  extf argret void INJFARCTLUSCTL_vidInitFeedState();                       */
/*  extf argret void INJFARCTLUSCTL_vidIniAdap();                             */
/*  extf argret void INJFARCTLUSCTL_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveRst_InjFarCtlUsCtl                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveRst_InjFarCtlUsCtl(void)
{
   INJFARCTLUSCTL_vidInit();
   INJFARCTLUSCTL_vidInitFedSaf();
   INJFARCTLUSCTL_vidIniUplamMaxMin();
   INJFARCTLUSCTL_vidInitFeedState();
   INJFARCTLUSCTL_vidIniAdap();
   INJFARCTLUSCTL_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveTDC_FarCtlUsCtl                                  */
/* !Description :  Fonction d'accroche à l'event InjCtl_EveTDC_FarCtlUsCtl    */
/* !Number      :  SCH.10                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidFuncCtlFdInjAc();                      */
/*  extf argret void INJFARCTLUSCTL_vidFCallbdLdDerv();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveTDC_FarCtlUsCtl                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveTDC_FarCtlUsCtl(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidFuncCtlFdInjAc();
      INJFARCTLUSCTL_vidFCallbdLdDerv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_SdlFast_FarCtlUsCtl                                 */
/* !Description :  Fonction d'accroche à l'event  InjCtl_SdlFast_FarCtlUsCtl  */
/* !Number      :  SCH.11                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidFuncCalLFbFilt();                      */
/*  extf argret void INJFARCTLUSCTL_vidFuncCalAttGain();                      */
/*  extf argret void INJFARCTLUSCTL_vidLamdaGazDelcal();                      */
/*  extf argret void INJFARCTLUSCTL_vidMeanLamFeedCal();                      */
/*  extf argret void INJFARCTLUSCTL_vidAdaplamfeebcal();                      */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_SdlFast_FarCtlUsCtl                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_SdlFast_FarCtlUsCtl(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidFuncCalLFbFilt();
      INJFARCTLUSCTL_vidFuncCalAttGain();
      INJFARCTLUSCTL_vidLamdaGazDelcal();
      INJFARCTLUSCTL_vidMeanLamFeedCal();
      INJFARCTLUSCTL_vidAdaplamfeebcal();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveMonrFbCdn_FarCtlMgr                              */
/* !Description :  Fonction d'accroche à l'event                              */
/*                 InjCtl_EveMonrFbCdn_FarCtlMgr                              */
/* !Number      :  SCH.12                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidInitLambdaFB();                        */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveMonrFbCdn_FarCtlMgr                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveMonrFbCdn_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidInitLambdaFB();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  InjCtl_EveFbDisab_FarCtlMgr                                */
/* !Description :  Evènement de désactivation de la régulation de richesse    */
/* !Number      :  SCH.13                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidIniUplamMaxMin();                      */
/*  extf argret void INJFARCTLUSCTL_vidInitFeedState();                       */
/*  input uint8 INJFARCTLUSCTL_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : InjCtl_EveFbDisab_FarCtlMgr                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InjCtl_EveFbDisab_FarCtlMgr(void)
{
   if (INJFARCTLUSCTL_u8Inhib != 0x5A)
   {
      INJFARCTLUSCTL_vidIniUplamMaxMin();
      INJFARCTLUSCTL_vidInitFeedState();
   }
}

/*------------------------------- end of file --------------------------------*/