/*****************************************************************************/
/*                                                                           */
/* !Layer          : RTE                                                     */
/*                                                                           */
/* !Component      : RTE                                                     */
/*                                                                           */
/* !Module         : Rte_                                                    */
/* !Description    : Creation de macros pre et port runnables pour la        */
/*                   gestion des FRM et des défauts                          */
/* !File           :                                                         */
/*                                                                           */
/* !Scope          : Public Component                                        */
/*                                                                           */
/* !Target         : All                                                     */
/*                                                                           */
/* !Vendor         : Valeo                                                   */
/*                                                                           */
/* Coding language : C                                                       */
/*                                                                           */
/* COPYRIGHT 2006 VALEO                                                      */
/* all rights reserved                                                       */
/*                                                                           */
/*****************************************************************************/
/*                      Fichier genere automatiquement                       */
/*****************************************************************************/
/* PVCS Information                                                          */
/* $Archive::   I:/Projets/EBx_V46/LDA/Tools/RTE/Sources/GDGARConnector/archi$
   $Revision::   1.2      $$Author::   sbiet          $$Date::   19 Oct 2009 $
 *****************************************************************************/

#ifndef RTE_GDGAR_H
#define RTE_GDGAR_H

/*****************************************************************************/
/*                           Inclusion systemes                              */
/*****************************************************************************/

/*****************************************************************************/
/*                Inclusion des fichiers includes projet                     */
/*****************************************************************************/

#include "Rte.h"
#include "Rte_Vems_interface.h"
#include "GDGAR.H"

/*****************************************************************************/
/*                 Macros d'encapsulation des runnables                      */
/*****************************************************************************/

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlFast_AirExtPresAcqAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLFAST_AIREXTPRESACQADC()

#define POST_RE_AIRPRES_SDLFAST_AIREXTPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_EveRst_BattVoltAcqAdc           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_EVERST_BATTVOLTACQADC()

#define POST_RE_PWR_EVERST_BATTVOLTACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_Sdl2ms_BattVotlAcqAdc           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDL2MS_BATTVOTLACQADC()

#define POST_RE_PWR_SDL2MS_BATTVOTLACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirT_EveRst_AcqAirTAdc              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRT_EVERST_ACQAIRTADC()

#define POST_RE_AIRT_EVERST_ACQAIRTADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoT_SdlMid_AcqCoTAdc                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COT_SDLMID_ACQCOTADC()

#define POST_RE_COT_SDLMID_ACQCOTADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlFast_InMnfPresDiagAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLFAST_INMNFPRESDIAGADC()

#define POST_RE_AIRPRES_SDLFAST_INMNFPRESDIAGADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_Eve14TDC_InMnfPresAcqAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_EVE14TDC_INMNFPRESACQADC()

#define POST_RE_AIRPRES_EVE14TDC_INMNFPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoT_EveRst_AcqCoTAdc                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COT_EVERST_ACQCOTADC()

#define POST_RE_COT_EVERST_ACQCOTADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirT_SdlMid_AcqAirTAdc              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRT_SDLMID_ACQAIRTADC()

#define POST_RE_AIRT_SDLMID_ACQAIRTADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlMid_InMnfPresAcqAdc      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLMID_INMNFPRESACQADC()

#define POST_RE_AIRPRES_SDLMID_INMNFPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlFast_RelBrkAsiAcqAdc     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLFAST_RELBRKASIACQADC()

#define POST_RE_AIRPRES_SDLFAST_RELBRKASIACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_AcqAdc                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_ACQADC()

#define POST_RE_EXT_EVERST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_DrvrSenO2UsAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_DRVRSENO2USADC()

#define POST_RE_HEATSENO2_SDLFAST_DRVRSENO2USADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_EveRst_AcqAdc                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_EVERST_ACQADC()

#define POST_RE_PWR_EVERST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AccP_EveRst_AcqPosnAdc              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCP_EVERST_ACQPOSNADC()

#define POST_RE_ACCP_EVERST_ACQPOSNADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_EveInj_BattVotlAcqAdc           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_EVEINJ_BATTVOTLACQADC()

#define POST_RE_PWR_EVEINJ_BATTVOTLACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_SdlFast_AcqAdc                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDLFAST_ACQADC()

#define POST_RE_PWR_SDLFAST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlSlow_AirExtPresAcqAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLSLOW_AIREXTPRESACQADC()

#define POST_RE_AIRPRES_SDLSLOW_AIREXTPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_SdlFast_BattVoltAcqAdc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDLFAST_BATTVOLTACQADC()

#define POST_RE_PWR_SDLFAST_BATTVOLTACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlFast_DftStaCmdAdc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLFAST_DFTSTACMDADC()

#define POST_RE_ENGST_SDLFAST_DFTSTACMDADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_EveClcnServo_AcqAdcThr          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_EVECLCNSERVO_ACQADCTHR()

#define POST_RE_THR_EVECLCNSERVO_ACQADCTHR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenO2Us_SdlFast_UpLsAcqAdc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENO2US_SDLFAST_UPLSACQADC()

#define POST_RE_SENO2US_SDLFAST_UPLSACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AccP_SdlFast_SwtAcqDiagAdc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCP_SDLFAST_SWTACQDIAGADC()

#define POST_RE_ACCP_SDLFAST_SWTACQDIAGADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlFast_BrkAsiAcqAdc        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLFAST_BRKASIACQADC()

#define POST_RE_AIRPRES_SDLFAST_BRKASIACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AC_EveRst_ACPresAcqAdc              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AC_EVERST_ACPRESACQADC()

#define POST_RE_AC_EVERST_ACPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AC_SdlFast_ACPresAcqAdc             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AC_SDLFAST_ACPRESACQADC()

#define POST_RE_AC_SDLFAST_ACPRESACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AccP_SdlFast_AcqPosnAdc             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCP_SDLFAST_ACQPOSNADC()

#define POST_RE_ACCP_SDLFAST_ACQPOSNADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoT_EveStTR_AcqCoTAdc               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COT_EVESTTR_ACQCOTADC()

#define POST_RE_COT_EVESTTR_ACQCOTADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenO2Ds_SdlFast_DsLsAcqAdc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENO2DS_SDLFAST_DSLSACQADC()

#define POST_RE_SENO2DS_SDLFAST_DSLSACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_SdlMid_AcqAdc                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDLMID_ACQADC()

#define POST_RE_PWR_SDLMID_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_DrvrSenO2DsAdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_DRVRSENO2DSADC()

#define POST_RE_HEATSENO2_SDLFAST_DRVRSENO2DSADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_EveRst_AcqAdcThr                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_EVERST_ACQADCTHR()

#define POST_RE_THR_EVERST_ACQADCTHR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenAct_EveCrTR_AcqAdc               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENACT_EVECRTR_ACQADC()

#define POST_RE_SENACT_EVECRTR_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuAcq_EveSpl_AcqAdc                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUACQ_EVESPL_ACQADC()

#define POST_RE_FUACQ_EVESPL_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlFast_AcqAdc                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLFAST_ACQADC()

#define POST_RE_OIL_SDLFAST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuAcq_SdlFast_AcqAdc                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUACQ_SDLFAST_ACQADC()

#define POST_RE_FUACQ_SDLFAST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_Eve14TDC_AcqAdc             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_EVE14TDC_ACQADC()

#define POST_RE_AIRPRES_EVE14TDC_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuAcq_EveInj_AcqAdc                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUACQ_EVEINJ_ACQADC()

#define POST_RE_FUACQ_EVEINJ_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AcqAdc_EveRst_AcqAdc                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACQADC_EVERST_ACQADC()

#define POST_RE_ACQADC_EVERST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenAct_SdlSlow_AcqAdc               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENACT_SDLSLOW_ACQADC()

#define POST_RE_SENACT_SDLSLOW_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenAct_EveRTSt_AcqAdc               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENACT_EVERTST_ACQADC()

#define POST_RE_SENACT_EVERTST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_Eve14TDC_AcqAdc                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_EVE14TDC_ACQADC()

#define POST_RE_OIL_EVE14TDC_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirPres_SdlMid_AcqAdc               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRPRES_SDLMID_ACQADC()

#define POST_RE_AIRPRES_SDLMID_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_SenAct_SdlMid_AcqAdc                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SENACT_SDLMID_ACQADC()

#define POST_RE_SENACT_SDLMID_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_EveRst_AcqAdc                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_EVERST_ACQADC()

#define POST_RE_OIL_EVERST_ACQADC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_EveRst_AuthStrtSTTDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_EVERST_AUTHSTRTSTTDIO()

#define POST_RE_ENGST_EVERST_AUTHSTRTSTTDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlFast_AuthStrtSTTDio        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLFAST_AUTHSTRTSTTDIO()

#define POST_RE_ENGST_SDLFAST_AUTHSTRTSTTDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrRly_EveRst_IfCmdDiagDio          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRRLY_EVERST_IFCMDDIAGDIO()

#define POST_RE_PWRRLY_EVERST_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_STT_SdlFast_KeyPushInfoDio          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STT_SDLFAST_KEYPUSHINFODIO()

#define POST_RE_STT_SDLFAST_KEYPUSHINFODIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrRly_EveCkOn_IfCmdDiagDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRRLY_EVECKON_IFCMDDIAGDIO()

#define POST_RE_PWRRLY_EVECKON_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrlRly_EveRst_IfCmdDiagDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRLRLY_EVERST_IFCMDDIAGDIO()

#define POST_RE_PWRLRLY_EVERST_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_DrvrSenO2DsDio    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_DRVRSENO2DSDIO()

#define POST_RE_HEATSENO2_SDLFAST_DRVRSENO2DSDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Strtr_EveRst_IfCmdDiagDio           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STRTR_EVERST_IFCMDDIAGDIO()

#define POST_RE_STRTR_EVERST_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrRly_SdlMid_IfCmdDiagDio          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRRLY_SDLMID_IFCMDDIAGDIO()

#define POST_RE_PWRRLY_SDLMID_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_DrvrSenO2UsDio    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_DRVRSENO2USDIO()

#define POST_RE_HEATSENO2_SDLFAST_DRVRSENO2USDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrlRly_EveRxnIdDaRcdDmlDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRLRLY_EVERXNIDDARCDDMLDIO()

#define POST_RE_PWRLRLY_EVERXNIDDARCDDMLDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlSlow_BlowByCmdDio            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLSLOW_BLOWBYCMDDIO()

#define POST_RE_OIL_SDLSLOW_BLOWBYCMDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Brk_SdlMid_DiagBrkPedDio            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BRK_SDLMID_DIAGBRKPEDDIO()

#define POST_RE_BRK_SDLMID_DIAGBRKPEDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Gear_SdlFast_StrtLockAcqDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GEAR_SDLFAST_STRTLOCKACQDIO()

#define POST_RE_GEAR_SDLFAST_STRTLOCKACQDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrlRly_EveKOf_IfCmdDiagDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRLRLY_EVEKOF_IFCMDDIAGDIO()

#define POST_RE_PWRLRLY_EVEKOF_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrRly_EveKOn_IfCmdDiagDio          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRRLY_EVEKON_IFCMDDIAGDIO()

#define POST_RE_PWRRLY_EVEKON_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Clu_SdlFast_AcqnCluPedDio           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CLU_SDLFAST_ACQNCLUPEDDIO()

#define POST_RE_CLU_SDLFAST_ACQNCLUPEDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EcuSt_SdlFast_AcqWkuSigDio          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ECUST_SDLFAST_ACQWKUSIGDIO()

#define POST_RE_ECUST_SDLFAST_ACQWKUSIGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_EveKOf_DrvrSenO2UsDio     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_EVEKOF_DRVRSENO2USDIO()

#define POST_RE_HEATSENO2_EVEKOF_DRVRSENO2USDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlMid_AcqCmdCoFan            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLMID_ACQCMDCOFAN()

#define POST_RE_COFAN_SDLMID_ACQCMDCOFAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Strtr_SdlMid_IfCmdDiagDio           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STRTR_SDLMID_IFCMDDIAGDIO()

#define POST_RE_STRTR_SDLMID_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlMid_OilPresAcqDio            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLMID_OILPRESACQDIO()

#define POST_RE_OIL_SDLMID_OILPRESACQDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrlRly_EveKOn_IfCmdDiagDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRLRLY_EVEKON_IFCMDDIAGDIO()

#define POST_RE_PWRLRLY_EVEKON_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlFast_EngStOutIdcDio        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLFAST_ENGSTOUTIDCDIO()

#define POST_RE_ENGST_SDLFAST_ENGSTOUTIDCDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_AcqCmdDio                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_ACQCMDDIO()

#define POST_RE_EXT_EVERST_ACQCMDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_EveRst_EngStOutIdcDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_EVERST_ENGSTOUTIDCDIO()

#define POST_RE_ENGST_EVERST_ENGSTOUTIDCDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PwrlRly_SdlMid_IfCmdDiagDio         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWRLRLY_SDLMID_IFCMDDIAGDIO()

#define POST_RE_PWRLRLY_SDLMID_IFCMDDIAGDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_EveKOf_DrvrSenO2DsDio     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_EVEKOF_DRVRSENO2DSDIO()

#define POST_RE_HEATSENO2_EVEKOF_DRVRSENO2DSDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_SdlMid_VoltHldDevDio            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDLMID_VOLTHLDDEVDIO()

#define POST_RE_PWR_SDLMID_VOLTHLDDEVDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlFast_CmdDiagEngStOutIdc    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLFAST_CMDDIAGENGSTOUTIDC()

#define POST_RE_ENGST_SDLFAST_CMDDIAGENGSTOUTIDC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlMid_CmdDiagStrtr           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLMID_CMDDIAGSTRTR()

#define POST_RE_ENGST_SDLMID_CMDDIAGSTRTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_CmdDiagDrvO2Us    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_CMDDIAGDRVO2US()

#define POST_RE_HEATSENO2_SDLFAST_CMDDIAGDRVO2US()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngSt_SdlFast_CmdDiagAuthStrtSTT    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGST_SDLFAST_CMDDIAGAUTHSTRTSTT()

#define POST_RE_ENGST_SDLFAST_CMDDIAGAUTHSTRTSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlSlow_CmdDiagECTReq         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLSLOW_CMDDIAGECTREQ()

#define POST_RE_COFAN_SDLSLOW_CMDDIAGECTREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Pwr_SdlMid_CmdDiagDmtr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PWR_SDLMID_CMDDIAGDMTR()

#define POST_RE_PWR_SDLMID_CMDDIAGDMTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlvAct_SdlFast_CmdDiagVlvActIn      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_SDLFAST_CMDDIAGVLVACTIN()

#define POST_RE_VLVACT_SDLFAST_CMDDIAGVLVACTIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlMid_CmdDiagGMV1GMV2        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLMID_CMDDIAGGMV1GMV2()

#define POST_RE_COFAN_SDLMID_CMDDIAGGMV1GMV2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuPmp_SdlFast_CmdDiagPropFuPmp      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUPMP_SDLFAST_CMDDIAGPROPFUPMP()

#define POST_RE_FUPMP_SDLFAST_CMDDIAGPROPFUPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlSlow_CmdDiagBlowBy2          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLSLOW_CMDDIAGBLOWBY2()

#define POST_RE_OIL_SDLSLOW_CMDDIAGBLOWBY2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlvAct_SdlFast_CmdDiagVlvActEx      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_SDLFAST_CMDDIAGVLVACTEX()

#define POST_RE_VLVACT_SDLFAST_CMDDIAGVLVACTEX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Rly_SdlFast_CmdDiagRly              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_RLY_SDLFAST_CMDDIAGRLY()

#define POST_RE_RLY_SDLFAST_CMDDIAGRLY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Cstr_SdlFast_CmdDiagCstr            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CSTR_SDLFAST_CMDDIAGCSTR()

#define POST_RE_CSTR_SDLFAST_CMDDIAGCSTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_OutPutCmdDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_OUTPUTCMDDIAG()

#define POST_RE_EXT_EVERST_OUTPUTCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlSlow_CmdDiagBlowBy1          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLSLOW_CMDDIAGBLOWBY1()

#define POST_RE_OIL_SDLSLOW_CMDDIAGBLOWBY1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_HeatSenO2_SdlFast_CmdDiagDrvO2Ds    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_HEATSENO2_SDLFAST_CMDDIAGDRVO2DS()

#define POST_RE_HEATSENO2_SDLFAST_CMDDIAGDRVO2DS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_EveClcnServo_CmdDiagThrCmd      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_EVECLCNSERVO_CMDDIAGTHRCMD()

#define POST_RE_THR_EVECLCNSERVO_CMDDIAGTHRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_SdlMid_HPPmpActCmdDiag       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_SDLMID_HPPMPACTCMDDIAG()

#define POST_RE_PFUCTL_SDLMID_HPPMPACTCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoT_SdlSlow_TrbWaPmpDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COT_SDLSLOW_TRBWAPMPDIAG()

#define POST_RE_COT_SDLSLOW_TRBWAPMPDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Wg_SdlMid_WgcCmdDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_WG_SDLMID_WGCCMDDIAG()

#define POST_RE_WG_SDLMID_WGCCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DmpVlvAct_SdlFast_DmpVlvCmdDiag     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DMPVLVACT_SDLFAST_DMPVLVCMDDIAG()

#define POST_RE_DMPVLVACT_SDLFAST_DMPVLVCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_AcqDgoHaL                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_ACQDGOHAL()

#define POST_RE_EXT_EVERST_ACQDGOHAL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSysHw_SdlFast_CtlPmpReqDiag      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYSHW_SDLFAST_CTLPMPREQDIAG()

#define POST_RE_OILSYSHW_SDLFAST_CTLPMPREQDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASIC_SdlFast_diagasicgdiDiag        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASIC_SDLFAST_DIAGASICGDIDIAG()

#define POST_RE_ASIC_SDLFAST_DIAGASICGDIDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlFast_OilLvlAcqDiag           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLFAST_OILLVLACQDIAG()

#define POST_RE_OIL_SDLFAST_OILLVLACQDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Gear_EveRst_NeutPosnAcqPwd          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GEAR_EVERST_NEUTPOSNACQPWD()

#define POST_RE_GEAR_EVERST_NEUTPOSNACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Clu_EveRst_CluPedFreqAcqPwd         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CLU_EVERST_CLUPEDFREQACQPWD()

#define POST_RE_CLU_EVERST_CLUPEDFREQACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Clu_SdlFast_CluPedFreqAcqPwd        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CLU_SDLFAST_CLUPEDFREQACQPWD()

#define POST_RE_CLU_SDLFAST_CLUPEDFREQACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_EveRst_CmdDiagCoFanAcqPwd     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_EVERST_CMDDIAGCOFANACQPWD()

#define POST_RE_COFAN_EVERST_CMDDIAGCOFANACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlMid_CmdDiagCoFanAcqPwd     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLMID_CMDDIAGCOFANACQPWD()

#define POST_RE_COFAN_SDLMID_CMDDIAGCOFANACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_AcqPwd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_ACQPWD()

#define POST_RE_EXT_EVERST_ACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuPmp_EveRst_PropFuPmpPwd           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUPMP_EVERST_PROPFUPMPPWD()

#define POST_RE_FUPMP_EVERST_PROPFUPMPPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuPmp_SdlSlow_PropFuPmpDiagPwd      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUPMP_SDLSLOW_PROPFUPMPDIAGPWD()

#define POST_RE_FUPMP_SDLSLOW_PROPFUPMPDIAGPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Gear_SdlFast_NeutPosnAcqPwd         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GEAR_SDLFAST_NEUTPOSNACQPWD()

#define POST_RE_GEAR_SDLFAST_NEUTPOSNACQPWD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_EveRst_CatAcvDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_EVERST_CATACVDIAG()

#define POST_RE_CATMON_EVERST_CATACVDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_SdlSlow_CatAcvDiag           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_SDLSLOW_CATACVDIAG()

#define POST_RE_CATMON_SDLSLOW_CATACVDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_SdlMid_CatAcvDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_SDLMID_CATACVDIAG()

#define POST_RE_CATMON_SDLMID_CATACVDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_SdlFast_CatAcvDiag           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_SDLFAST_CATACVDIAG()

#define POST_RE_CATMON_SDLFAST_CATACVDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_SdlMid_CatPasDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_SDLMID_CATPASDIAG()

#define POST_RE_CATMON_SDLMID_CATPASDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_EveRst_CatPasDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_EVERST_CATPASDIAG()

#define POST_RE_CATMON_EVERST_CATPASDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AC_SdlSlow_CmdDio                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AC_SDLSLOW_CMDDIO()

#define POST_RE_AC_SDLSLOW_CMDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AC_EveRst_CmdDio                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AC_EVERST_CMDDIO()

#define POST_RE_AC_EVERST_CMDDIO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlMid_CmdPwmCoFan            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLMID_CMDPWMCOFAN()

#define POST_RE_COFAN_SDLMID_CMDPWMCOFAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlvAct_SdlFast_CmdPwmVlvActEx       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_SDLFAST_CMDPWMVLVACTEX()

#define POST_RE_VLVACT_SDLFAST_CMDPWMVLVACTEX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_SdlMid_CmdPwmThrCmd             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_SDLMID_CMDPWMTHRCMD()

#define POST_RE_THR_SDLMID_CMDPWMTHRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_EveRst_CmdPwmThrCmd             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_EVERST_CMDPWMTHRCMD()

#define POST_RE_THR_EVERST_CMDPWMTHRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Cstr_EveRst_CmdPwmCstr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CSTR_EVERST_CMDPWMCSTR()

#define POST_RE_CSTR_EVERST_CMDPWMCSTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuPmp_SdlFast_CmdPwmPropFuPmp       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUPMP_SDLFAST_CMDPWMPROPFUPMP()

#define POST_RE_FUPMP_SDLFAST_CMDPWMPROPFUPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Thr_EveClcnServo_CmdPwmThrCmd       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THR_EVECLCNSERVO_CMDPWMTHRCMD()

#define POST_RE_THR_EVECLCNSERVO_CMDPWMTHRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Ext_EveRst_CmdPwm                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXT_EVERST_CMDPWM()

#define POST_RE_EXT_EVERST_CMDPWM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Cstr_SdlMid_CmdPwmCstr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CSTR_SDLMID_CMDPWMCSTR()

#define POST_RE_CSTR_SDLMID_CMDPWMCSTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoFan_SdlSlow_CmdPmwECTCmd          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COFAN_SDLSLOW_CMDPMWECTCMD()

#define POST_RE_COFAN_SDLSLOW_CMDPMWECTCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlvAct_SdlFast_CmdPwmVlvActIn       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_SDLFAST_CMDPWMVLVACTIN()

#define POST_RE_VLVACT_SDLFAST_CMDPWMVLVACTIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DmpVlvAct_EveRst_CmdPwmAct          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DMPVLVACT_EVERST_CMDPWMACT()

#define POST_RE_DMPVLVACT_EVERST_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSysHw_SdlFast_CmdPwmAct          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYSHW_SDLFAST_CMDPWMACT()

#define POST_RE_OILSYSHW_SDLFAST_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Wg_SdlMid_CmdPwmAct                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_WG_SDLMID_CMDPWMACT()

#define POST_RE_WG_SDLMID_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoT_SdlSlow_CmdPwmAct               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COT_SDLSLOW_CMDPWMACT()

#define POST_RE_COT_SDLSLOW_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Wg_EveRst_CmdPwmAct                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_WG_EVERST_CMDPWMACT()

#define POST_RE_WG_EVERST_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DmpVlvAct_SdlFast_CmdPwmAct         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DMPVLVACT_SDLFAST_CMDPWMACT()

#define POST_RE_DMPVLVACT_SDLFAST_CMDPWMACT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StartProtocol                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STARTPROTOCOL()

#define POST_RE_STARTPROTOCOL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopProtocol                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPPROTOCOL()

#define POST_RE_STOPPROTOCOL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Supplier_Indication                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SUPPLIER_INDICATION()

#define POST_RE_SUPPLIER_INDICATION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Manufacturer_Indication             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MANUFACTURER_INDICATION()

#define POST_RE_MANUFACTURER_INDICATION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ManufSuppl_Indication               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MANUFSUPPL_INDICATION()

#define POST_RE_MANUFSUPPL_INDICATION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_GetSeed_SecLev02                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GETSEED_SECLEV02()

#define POST_RE_GETSEED_SECLEV02()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CompareKey_SecLev02                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COMPAREKEY_SECLEV02()

#define POST_RE_COMPAREKEY_SECLEV02()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID01                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID01()

#define POST_RE_OBDMID01TID01()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID02                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID02()

#define POST_RE_OBDMID01TID02()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID03                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID03()

#define POST_RE_OBDMID01TID03()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID04                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID04()

#define POST_RE_OBDMID01TID04()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID07                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID07()

#define POST_RE_OBDMID01TID07()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID08                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID08()

#define POST_RE_OBDMID01TID08()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TID0A                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TID0A()

#define POST_RE_OBDMID01TID0A()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TIDA0                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TIDA0()

#define POST_RE_OBDMID01TIDA0()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID01TIDA1                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID01TIDA1()

#define POST_RE_OBDMID01TIDA1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID01                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID01()

#define POST_RE_OBDMID02TID01()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID02                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID02()

#define POST_RE_OBDMID02TID02()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID03                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID03()

#define POST_RE_OBDMID02TID03()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID04                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID04()

#define POST_RE_OBDMID02TID04()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID07                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID07()

#define POST_RE_OBDMID02TID07()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TID08                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TID08()

#define POST_RE_OBDMID02TID08()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TIDC0                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TIDC0()

#define POST_RE_OBDMID02TIDC0()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TIDC1                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TIDC1()

#define POST_RE_OBDMID02TIDC1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID02TIDC2                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID02TIDC2()

#define POST_RE_OBDMID02TIDC2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID21TID81                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID21TID81()

#define POST_RE_OBDMID21TID81()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID41TIDD0                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID41TIDD0()

#define POST_RE_OBDMID41TIDD0()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMID42TIDDA                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMID42TIDDA()

#define POST_RE_OBDMID42TIDDA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA2TID0B                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA2TID0B()

#define POST_RE_OBDMIDA2TID0B()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA2TID0C                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA2TID0C()

#define POST_RE_OBDMIDA2TID0C()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA3TID0B                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA3TID0B()

#define POST_RE_OBDMIDA3TID0B()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA3TID0C                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA3TID0C()

#define POST_RE_OBDMIDA3TID0C()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA4TID0B                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA4TID0B()

#define POST_RE_OBDMIDA4TID0B()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA4TID0C                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA4TID0C()

#define POST_RE_OBDMIDA4TID0C()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA5TID0B                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA5TID0B()

#define POST_RE_OBDMIDA5TID0B()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OBDMIDA5TID0C                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OBDMIDA5TID0C()

#define POST_RE_OBDMIDA5TID0C()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DCM_MANU_StubServiceAftS            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DCM_MANU_STUBSERVICEAFTS()

#define POST_RE_DCM_MANU_STUBSERVICEAFTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable MainFunction                           */
/*---------------------------------------------------------------------------*/
#define PRE_MAINFUNCTION()

#define POST_MAINFUNCTION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Dcm_GetActiveProtocol                  */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_GETACTIVEPROTOCOL()

#define POST_DCM_GETACTIVEPROTOCOL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Dcm_TriggerOnEvent                     */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_TRIGGERONEVENT()

#define POST_DCM_TRIGGERONEVENT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Dcm_GetSesCtrlType                     */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_GETSESCTRLTYPE()

#define POST_DCM_GETSESCTRLTYPE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Dcm_GetSecurityLevel                   */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_GETSECURITYLEVEL()

#define POST_DCM_GETSECURITYLEVEL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Dcm_ResetToDefaultSession              */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_RESETTODEFAULTSESSION()

#define POST_DCM_RESETTODEFAULTSESSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer100usU32           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER100USU32()

#define POST_RE_FRUNTIME_GETTIMER100USU32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer1msU32             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER1MSU32()

#define POST_RE_FRUNTIME_GETTIMER1MSU32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer1sU32              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER1SU32()

#define POST_RE_FRUNTIME_GETTIMER1SU32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer1minU32            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER1MINU32()

#define POST_RE_FRUNTIME_GETTIMER1MINU32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer100msU32           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER100MSU32()

#define POST_RE_FRUNTIME_GETTIMER100MSU32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer_1ms_U32           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER_1MS_U32()

#define POST_RE_FRUNTIME_GETTIMER_1MS_U32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer_100ms_U32         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER_100MS_U32()

#define POST_RE_FRUNTIME_GETTIMER_100MS_U32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer_1s_U32            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER_1S_U32()

#define POST_RE_FRUNTIME_GETTIMER_1S_U32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer_1min_U32          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER_1MIN_U32()

#define POST_RE_FRUNTIME_GETTIMER_1MIN_U32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRunTime_GetTimer_100us_U32         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRUNTIME_GETTIMER_100US_U32()

#define POST_RE_FRUNTIME_GETTIMER_100US_U32()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_1_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_2_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_3_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_4_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_5_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_5_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_5_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_1_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_2_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_3_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_1_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_2_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_3_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_4_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_5_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_5_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_5_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_6_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_6_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_6_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_7_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_7_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_7_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_8_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_8_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_8_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_9_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_9_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_9_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2000MS_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2000MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2000MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_1_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_2_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_3_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_4_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_1_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_2_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_3_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_4_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_5_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_5_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_5_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2MS_POST       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2_5MS_1_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2_5MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2_5MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2_5MS_2_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2_5MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2_5MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_4000MS_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_4000MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_4000MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_400MS_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_400MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_400MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_1_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_2_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_3_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_4_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_5_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_5_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_5_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_50MS_POST      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_50MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_50MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_1_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_2_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_3_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_3_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_3_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_4_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_4_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_4_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_5_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_5_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_5_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_60000MS_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_60000MS_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_C_60000MS_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_1_4_TDC_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_1_4_TDC_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_1_4_TDC_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_BDC_1_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_BDC_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_BDC_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_BDC_2_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_BDC_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_BDC_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_CRK_OFF_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_CRK_OFF_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_CRK_OFF_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_CRK_ON_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_CRK_ON_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_CRK_ON_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EEST_POST      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EEST_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EEST_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ENG_RUN_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ENG_RUN_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ENG_RUN_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ENG_STAL_POST  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ENG_STAL_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ENG_STAL_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_EDGE_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_EDGE_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_PERIOD_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_PERIOD_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ICLC_EVENT_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ICLC_EVENT_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ICLC_EVENT_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IGK_OFF_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IGK_OFF_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IGK_OFF_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IGK_ON_POST    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IGK_ON_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IGK_ON_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_INJ_EVENT_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_INJ_EVENT_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_INJ_EVENT_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_EDGE_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_EDGE_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_PERIOD_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_PERIOD_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_KNK_WIN_POST   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_KNK_WIN_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_KNK_WIN_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_LTOO_POST      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_LTOO_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_LTOO_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_LTOO1_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_LTOO1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_LTOO1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_N_INV_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_N_INV_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_N_INV_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_N_INV_OFF_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_N_INV_OFF_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_N_INV_OFF_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_PTMHAL_EVT_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_PTMHAL_EVT_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_PTMHAL_EVT_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_SPILL_EVENT_POST */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_SPILL_EVENT_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_SPILL_EVENT_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TDC_1_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TDC_1_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TDC_1_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TDC_2_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TDC_2_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TDC_2_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_THR_POST       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_THR_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_THR_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TOLO_POST      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TOLO_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TOLO_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TOOTH_POST     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TOOTH_POST()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TOOTH_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_1_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_1_BSW_PRE()

#define POST_KRN_VIDC_1000MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_1_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_1_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_1_BSW_POST()

#define POST_KRN_VIDC_1000MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_2_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_2_BSW_PRE()

#define POST_KRN_VIDC_1000MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_2_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_2_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_2_BSW_POST()

#define POST_KRN_VIDC_1000MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_3_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_3_BSW_PRE()

#define POST_KRN_VIDC_1000MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_3_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_3_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_3_BSW_POST()

#define POST_KRN_VIDC_1000MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_4_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_4_BSW_PRE()

#define POST_KRN_VIDC_1000MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_4_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_4_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_4_BSW_POST()

#define POST_KRN_VIDC_1000MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_5_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_5_BSW_PRE()

#define POST_KRN_VIDC_1000MS_5_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_1000MS_5_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_1000MS_5_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_1000MS_5_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_1000MS_5_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_1000MS_5_BSW_POST()

#define POST_KRN_VIDC_1000MS_5_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_1_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_1_BSW_PRE()

#define POST_KRN_VIDC_100MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_1_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_1_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_1_BSW_POST()

#define POST_KRN_VIDC_100MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_2_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_2_BSW_PRE()

#define POST_KRN_VIDC_100MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_2_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_2_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_2_BSW_POST()

#define POST_KRN_VIDC_100MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_3_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_3_BSW_PRE()

#define POST_KRN_VIDC_100MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_100MS_3_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_100MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_100MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_100MS_3_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_100MS_3_BSW_POST()

#define POST_KRN_VIDC_100MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_1_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_1_BSW_PRE()

#define POST_KRN_VIDC_10MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_1_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_1_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_1_BSW_POST()

#define POST_KRN_VIDC_10MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_2_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_2_BSW_PRE()

#define POST_KRN_VIDC_10MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_2_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_2_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_2_BSW_POST()

#define POST_KRN_VIDC_10MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_3_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_3_BSW_PRE()

#define POST_KRN_VIDC_10MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_3_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_3_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_3_BSW_POST()

#define POST_KRN_VIDC_10MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_4_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_4_BSW_PRE()

#define POST_KRN_VIDC_10MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_4_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_4_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_4_BSW_POST()

#define POST_KRN_VIDC_10MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_5_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_5_BSW_PRE()

#define POST_KRN_VIDC_10MS_5_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_5_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_5_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_5_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_5_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_5_BSW_POST()

#define POST_KRN_VIDC_10MS_5_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_6_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_6_BSW_PRE()

#define POST_KRN_VIDC_10MS_6_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_6_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_6_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_6_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_6_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_6_BSW_POST()

#define POST_KRN_VIDC_10MS_6_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_7_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_7_BSW_PRE()

#define POST_KRN_VIDC_10MS_7_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_7_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_7_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_7_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_7_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_7_BSW_POST()

#define POST_KRN_VIDC_10MS_7_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_8_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_8_BSW_PRE()

#define POST_KRN_VIDC_10MS_8_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_8_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_8_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_8_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_8_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_8_BSW_POST()

#define POST_KRN_VIDC_10MS_8_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_9_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_9_BSW_PRE()

#define POST_KRN_VIDC_10MS_9_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_10MS_9_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_10MS_9_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_10MS_9_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_10MS_9_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_10MS_9_BSW_POST()

#define POST_KRN_VIDC_10MS_9_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2000MS_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2000MS_BSW_PRE()

#define POST_KRN_VIDC_2000MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2000MS_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2000MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2000MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2000MS_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2000MS_BSW_POST()

#define POST_KRN_VIDC_2000MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_1_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_1_BSW_PRE()

#define POST_KRN_VIDC_200MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_1_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_1_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_1_BSW_POST()

#define POST_KRN_VIDC_200MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_2_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_2_BSW_PRE()

#define POST_KRN_VIDC_200MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_2_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_2_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_2_BSW_POST()

#define POST_KRN_VIDC_200MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_3_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_3_BSW_PRE()

#define POST_KRN_VIDC_200MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_3_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_3_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_3_BSW_POST()

#define POST_KRN_VIDC_200MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_4_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_4_BSW_PRE()

#define POST_KRN_VIDC_200MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_200MS_4_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_200MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_200MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_200MS_4_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_200MS_4_BSW_POST()

#define POST_KRN_VIDC_200MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_1_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_1_BSW_PRE()

#define POST_KRN_VIDC_20MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_1_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_1_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_1_BSW_POST()

#define POST_KRN_VIDC_20MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_2_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_2_BSW_PRE()

#define POST_KRN_VIDC_20MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_2_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_2_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_2_BSW_POST()

#define POST_KRN_VIDC_20MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_3_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_3_BSW_PRE()

#define POST_KRN_VIDC_20MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_3_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_3_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_3_BSW_POST()

#define POST_KRN_VIDC_20MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_4_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_4_BSW_PRE()

#define POST_KRN_VIDC_20MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_4_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_4_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_4_BSW_POST()

#define POST_KRN_VIDC_20MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_5_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_5_BSW_PRE()

#define POST_KRN_VIDC_20MS_5_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_20MS_5_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_20MS_5_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_20MS_5_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_20MS_5_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_20MS_5_BSW_POST()

#define POST_KRN_VIDC_20MS_5_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2MS_BSW_PRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2MS_BSW_PRE()

#define POST_KRN_VIDC_2MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2MS_ASW        */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2MS_BSW_POST                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2MS_BSW_POST()

#define POST_KRN_VIDC_2MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2_5MS_1_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2_5MS_1_BSW_PRE()

#define POST_KRN_VIDC_2_5MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2_5MS_1_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2_5MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2_5MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2_5MS_1_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2_5MS_1_BSW_POST()

#define POST_KRN_VIDC_2_5MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2_5MS_2_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2_5MS_2_BSW_PRE()

#define POST_KRN_VIDC_2_5MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_2_5MS_2_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_2_5MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_2_5MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_2_5MS_2_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_2_5MS_2_BSW_POST()

#define POST_KRN_VIDC_2_5MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_4000MS_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_4000MS_BSW_PRE()

#define POST_KRN_VIDC_4000MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_4000MS_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_4000MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_4000MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_4000MS_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_4000MS_BSW_POST()

#define POST_KRN_VIDC_4000MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_400MS_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_400MS_BSW_PRE()

#define POST_KRN_VIDC_400MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_400MS_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_400MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_400MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_400MS_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_400MS_BSW_POST()

#define POST_KRN_VIDC_400MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_1_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_1_BSW_PRE()

#define POST_KRN_VIDC_40MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_1_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_1_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_1_BSW_POST()

#define POST_KRN_VIDC_40MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_2_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_2_BSW_PRE()

#define POST_KRN_VIDC_40MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_2_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_2_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_2_BSW_POST()

#define POST_KRN_VIDC_40MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_3_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_3_BSW_PRE()

#define POST_KRN_VIDC_40MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_3_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_3_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_3_BSW_POST()

#define POST_KRN_VIDC_40MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_4_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_4_BSW_PRE()

#define POST_KRN_VIDC_40MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_4_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_4_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_4_BSW_POST()

#define POST_KRN_VIDC_40MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_5_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_5_BSW_PRE()

#define POST_KRN_VIDC_40MS_5_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_40MS_5_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_40MS_5_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_40MS_5_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_40MS_5_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_40MS_5_BSW_POST()

#define POST_KRN_VIDC_40MS_5_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_50MS_BSW_PRE                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_50MS_BSW_PRE()

#define POST_KRN_VIDC_50MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_50MS_ASW       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_50MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_50MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_50MS_BSW_POST                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_50MS_BSW_POST()

#define POST_KRN_VIDC_50MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_1_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_1_BSW_PRE()

#define POST_KRN_VIDC_5MS_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_1_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_1_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_1_BSW_POST()

#define POST_KRN_VIDC_5MS_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_2_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_2_BSW_PRE()

#define POST_KRN_VIDC_5MS_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_2_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_2_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_2_BSW_POST()

#define POST_KRN_VIDC_5MS_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_3_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_3_BSW_PRE()

#define POST_KRN_VIDC_5MS_3_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_3_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_3_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_3_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_3_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_3_BSW_POST()

#define POST_KRN_VIDC_5MS_3_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_4_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_4_BSW_PRE()

#define POST_KRN_VIDC_5MS_4_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_4_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_4_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_4_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_4_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_4_BSW_POST()

#define POST_KRN_VIDC_5MS_4_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_5_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_5_BSW_PRE()

#define POST_KRN_VIDC_5MS_5_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_5MS_5_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_5MS_5_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_5MS_5_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_5MS_5_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_5MS_5_BSW_POST()

#define POST_KRN_VIDC_5MS_5_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_60000MS_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_60000MS_BSW_PRE()

#define POST_KRN_VIDC_60000MS_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_C_60000MS_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_C_60000MS_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_C_60000MS_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidC_60000MS_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDC_60000MS_BSW_POST()

#define POST_KRN_VIDC_60000MS_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_1_4_TDC_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_1_4_TDC_BSW_PRE()

#define POST_KRN_VIDS_1_4_TDC_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_1_4_TDC_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_1_4_TDC_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_1_4_TDC_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_1_4_TDC_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_1_4_TDC_BSW_POST()

#define POST_KRN_VIDS_1_4_TDC_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_BDC_1_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_BDC_1_BSW_PRE()

#define POST_KRN_VIDS_BDC_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_BDC_1_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_BDC_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_BDC_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_BDC_1_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_BDC_1_BSW_POST()

#define POST_KRN_VIDS_BDC_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_BDC_2_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_BDC_2_BSW_PRE()

#define POST_KRN_VIDS_BDC_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_BDC_2_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_BDC_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_BDC_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_BDC_2_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_BDC_2_BSW_POST()

#define POST_KRN_VIDS_BDC_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_CRK_OFF_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_CRK_OFF_BSW_PRE()

#define POST_KRN_VIDS_CRK_OFF_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_CRK_OFF_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_CRK_OFF_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_CRK_OFF_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_CRK_OFF_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_CRK_OFF_BSW_POST()

#define POST_KRN_VIDS_CRK_OFF_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_CRK_ON_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_CRK_ON_BSW_PRE()

#define POST_KRN_VIDS_CRK_ON_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_CRK_ON_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_CRK_ON_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_CRK_ON_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_CRK_ON_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_CRK_ON_BSW_POST()

#define POST_KRN_VIDS_CRK_ON_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EEST_BSW_PRE                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EEST_BSW_PRE()

#define POST_KRN_VIDS_EEST_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EEST_ASW       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EEST_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EEST_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EEST_BSW_POST                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EEST_BSW_POST()

#define POST_KRN_VIDS_EEST_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ENG_RUN_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ENG_RUN_BSW_PRE()

#define POST_KRN_VIDS_ENG_RUN_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ENG_RUN_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ENG_RUN_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ENG_RUN_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ENG_RUN_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ENG_RUN_BSW_POST()

#define POST_KRN_VIDS_ENG_RUN_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ENG_STAL_BSW_PRE              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ENG_STAL_BSW_PRE()

#define POST_KRN_VIDS_ENG_STAL_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ENG_STAL_ASW   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ENG_STAL_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ENG_STAL_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ENG_STAL_BSW_POST             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ENG_STAL_BSW_POST()

#define POST_KRN_VIDS_ENG_STAL_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EX_CAM_EDGE_BSW_PRE           */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EX_CAM_EDGE_BSW_PRE()

#define POST_KRN_VIDS_EX_CAM_EDGE_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EX_CAM_EDGE_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_EDGE_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_EDGE_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EX_CAM_EDGE_BSW_POST          */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EX_CAM_EDGE_BSW_POST()

#define POST_KRN_VIDS_EX_CAM_EDGE_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EX_CAM_PERIOD_BSW_PRE         */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EX_CAM_PERIOD_BSW_PRE()

#define POST_KRN_VIDS_EX_CAM_PERIOD_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_EX_CAM_PERIOD_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_PERIOD_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_EX_CAM_PERIOD_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_EX_CAM_PERIOD_BSW_POST        */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_EX_CAM_PERIOD_BSW_POST()

#define POST_KRN_VIDS_EX_CAM_PERIOD_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ICLC_EVENT_BSW_PRE            */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ICLC_EVENT_BSW_PRE()

#define POST_KRN_VIDS_ICLC_EVENT_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_ICLC_EVENT_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_ICLC_EVENT_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_ICLC_EVENT_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_ICLC_EVENT_BSW_POST           */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_ICLC_EVENT_BSW_POST()

#define POST_KRN_VIDS_ICLC_EVENT_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IGK_OFF_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IGK_OFF_BSW_PRE()

#define POST_KRN_VIDS_IGK_OFF_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IGK_OFF_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IGK_OFF_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IGK_OFF_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IGK_OFF_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IGK_OFF_BSW_POST()

#define POST_KRN_VIDS_IGK_OFF_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IGK_ON_BSW_PRE                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IGK_ON_BSW_PRE()

#define POST_KRN_VIDS_IGK_ON_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IGK_ON_ASW     */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IGK_ON_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IGK_ON_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IGK_ON_BSW_POST               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IGK_ON_BSW_POST()

#define POST_KRN_VIDS_IGK_ON_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_INJ_EVENT_BSW_PRE             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_INJ_EVENT_BSW_PRE()

#define POST_KRN_VIDS_INJ_EVENT_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_INJ_EVENT_ASW  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_INJ_EVENT_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_INJ_EVENT_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_INJ_EVENT_BSW_POST            */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_INJ_EVENT_BSW_POST()

#define POST_KRN_VIDS_INJ_EVENT_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IN_CAM_EDGE_BSW_PRE           */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IN_CAM_EDGE_BSW_PRE()

#define POST_KRN_VIDS_IN_CAM_EDGE_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IN_CAM_EDGE_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_EDGE_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_EDGE_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IN_CAM_EDGE_BSW_POST          */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IN_CAM_EDGE_BSW_POST()

#define POST_KRN_VIDS_IN_CAM_EDGE_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IN_CAM_PERIOD_BSW_PRE         */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IN_CAM_PERIOD_BSW_PRE()

#define POST_KRN_VIDS_IN_CAM_PERIOD_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_IN_CAM_PERIOD_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_PERIOD_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_IN_CAM_PERIOD_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_IN_CAM_PERIOD_BSW_POST        */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_IN_CAM_PERIOD_BSW_POST()

#define POST_KRN_VIDS_IN_CAM_PERIOD_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_KNK_WIN_BSW_PRE               */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_KNK_WIN_BSW_PRE()

#define POST_KRN_VIDS_KNK_WIN_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_KNK_WIN_ASW    */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_KNK_WIN_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_KNK_WIN_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_KNK_WIN_BSW_POST              */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_KNK_WIN_BSW_POST()

#define POST_KRN_VIDS_KNK_WIN_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_LTOO_BSW_PRE                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_LTOO_BSW_PRE()

#define POST_KRN_VIDS_LTOO_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_LTOO_ASW       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_LTOO_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_LTOO_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_LTOO_BSW_POST                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_LTOO_BSW_POST()

#define POST_KRN_VIDS_LTOO_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_LTOO1_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_LTOO1_BSW_PRE()

#define POST_KRN_VIDS_LTOO1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_LTOO1_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_LTOO1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_LTOO1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_LTOO1_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_LTOO1_BSW_POST()

#define POST_KRN_VIDS_LTOO1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_N_INV_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_N_INV_BSW_PRE()

#define POST_KRN_VIDS_N_INV_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_N_INV_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_N_INV_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_N_INV_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_N_INV_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_N_INV_BSW_POST()

#define POST_KRN_VIDS_N_INV_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_N_INV_OFF_BSW_PRE             */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_N_INV_OFF_BSW_PRE()

#define POST_KRN_VIDS_N_INV_OFF_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_N_INV_OFF_ASW  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_N_INV_OFF_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_N_INV_OFF_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_N_INV_OFF_BSW_POST            */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_N_INV_OFF_BSW_POST()

#define POST_KRN_VIDS_N_INV_OFF_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_PTMHAL_EVT_BSW_PRE            */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_PTMHAL_EVT_BSW_PRE()

#define POST_KRN_VIDS_PTMHAL_EVT_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_PTMHAL_EVT_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_PTMHAL_EVT_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_PTMHAL_EVT_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_PTMHAL_EVT_BSW_POST           */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_PTMHAL_EVT_BSW_POST()

#define POST_KRN_VIDS_PTMHAL_EVT_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_SPILL_EVENT_BSW_PRE           */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_SPILL_EVENT_BSW_PRE()

#define POST_KRN_VIDS_SPILL_EVENT_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_SPILL_EVENT_ASW */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_SPILL_EVENT_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_SPILL_EVENT_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_SPILL_EVENT_BSW_POST          */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_SPILL_EVENT_BSW_POST()

#define POST_KRN_VIDS_SPILL_EVENT_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TDC_1_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TDC_1_BSW_PRE()

#define POST_KRN_VIDS_TDC_1_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TDC_1_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TDC_1_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TDC_1_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TDC_1_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TDC_1_BSW_POST()

#define POST_KRN_VIDS_TDC_1_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TDC_2_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TDC_2_BSW_PRE()

#define POST_KRN_VIDS_TDC_2_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TDC_2_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TDC_2_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TDC_2_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TDC_2_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TDC_2_BSW_POST()

#define POST_KRN_VIDS_TDC_2_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_THR_BSW_PRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_THR_BSW_PRE()

#define POST_KRN_VIDS_THR_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_THR_ASW        */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_THR_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_THR_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_THR_BSW_POST                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_THR_BSW_POST()

#define POST_KRN_VIDS_THR_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TOLO_BSW_PRE                  */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TOLO_BSW_PRE()

#define POST_KRN_VIDS_TOLO_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TOLO_ASW       */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TOLO_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TOLO_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TOLO_BSW_POST                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TOLO_BSW_POST()

#define POST_KRN_VIDS_TOLO_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TOOTH_BSW_PRE                 */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TOOTH_BSW_PRE()

#define POST_KRN_VIDS_TOOTH_BSW_PRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidActivate_OSTSK_S_TOOTH_ASW      */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDACTIVATE_OSTSK_S_TOOTH_ASW()

#define POST_KRN_VIDACTIVATE_OSTSK_S_TOOTH_ASW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KRN_vidS_TOOTH_BSW_POST                */
/*---------------------------------------------------------------------------*/
#define PRE_KRN_VIDS_TOOTH_BSW_POST()

#define POST_KRN_VIDS_TOOTH_BSW_POST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_EveSpl_HPPmpActCmdAcq        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_EVESPL_HPPMPACTCMDACQ()

#define POST_RE_PFUCTL_EVESPL_HPPMPACTCMDACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_EveRTSt_HPPmpActCmdAcq       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_EVERTST_HPPMPACTCMDACQ()

#define POST_RE_PFUCTL_EVERTST_HPPMPACTCMDACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_EveStTR_HPPmpActCmdAcq       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_EVESTTR_HPPMPACTCMDACQ()

#define POST_RE_PFUCTL_EVESTTR_HPPMPACTCMDACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_SdlFast_HPPmpActCmdAcq       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_SDLFAST_HPPMPACTCMDACQ()

#define POST_RE_PFUCTL_SDLFAST_HPPMPACTCMDACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFuCtl_EveRst_HPPmpActCmdAcq        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFUCTL_EVERST_HPPMPACTCMDACQ()

#define POST_RE_PFUCTL_EVERST_HPPMPACTCMDACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_EveSyncAccu_IgCoilMng         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_EVESYNCACCU_IGCOILMNG()

#define POST_RE_IGCMD_EVESYNCACCU_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_SdlFast_IgCoilMng             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_SDLFAST_IGCOILMNG()

#define POST_RE_IGCMD_SDLFAST_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_EveRst_IgCoilMng              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_EVERST_IGCOILMNG()

#define POST_RE_IGCMD_EVERST_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgSys_EveCkSnOn_IgCoilMng           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGSYS_EVECKSNON_IGCOILMNG()

#define POST_RE_IGSYS_EVECKSNON_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_SdlSlow_IgCoilMng             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_SDLSLOW_IGCOILMNG()

#define POST_RE_IGCMD_SDLSLOW_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_EveCkSnOf_IgCoilMng           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_EVECKSNOF_IGCOILMNG()

#define POST_RE_IGCMD_EVECKSNOF_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_EveStTR_IgCoilMng             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_EVESTTR_IGCOILMNG()

#define POST_RE_IGCMD_EVESTTR_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_IgCmd_EveICD_IgCoilMng              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IGCMD_EVEICD_IGCOILMNG()

#define POST_RE_IGCMD_EVEICD_IGCOILMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_001_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_001_OIE()

#define POST_RE_IMMO_001_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_002_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_002_OIE()

#define POST_RE_IMMO_002_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_003_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_003_OIE()

#define POST_RE_IMMO_003_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_004_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_004_OIE()

#define POST_RE_IMMO_004_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_005_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_005_OIE()

#define POST_RE_IMMO_005_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_006_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_006_OIE()

#define POST_RE_IMMO_006_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_008_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_008_OIE()

#define POST_RE_IMMO_008_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_009_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_009_OIE()

#define POST_RE_IMMO_009_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Immo_010_OIE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_IMMO_010_OIE()

#define POST_RE_IMMO_010_OIE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveCkSnOf_InjCmd                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVECKSNOF_INJCMD()

#define POST_RE_INJ_EVECKSNOF_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveSyncNotAccu_InjCmd           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVESYNCNOTACCU_INJCMD()

#define POST_RE_INJ_EVESYNCNOTACCU_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveRst_InjCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVERST_INJCMD()

#define POST_RE_INJ_EVERST_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveKOf_InjCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVEKOF_INJCMD()

#define POST_RE_INJ_EVEKOF_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveInj_InjCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVEINJ_INJCMD()

#define POST_RE_INJ_EVEINJ_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_SdlFast_InjCmd                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_SDLFAST_INJCMD()

#define POST_RE_INJ_SDLFAST_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveCrTR_InjCmd                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVECRTR_INJCMD()

#define POST_RE_INJ_EVECRTR_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveSpl_InjCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVESPL_INJCMD()

#define POST_RE_INJ_EVESPL_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Inj_EveStTCr_InjCmd                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJ_EVESTTCR_INJCMD()

#define POST_RE_INJ_EVESTTCR_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlVAct_EveInCmToo_AcqVlVActPos      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_EVEINCMTOO_ACQVLVACTPOS()

#define POST_RE_VLVACT_EVEINCMTOO_ACQVLVACTPOS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkSnOn_AcqCkMngIf           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKSNON_ACQCKMNGIF()

#define POST_RE_SYNC_EVECKSNON_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlFast_AcqCkMngIf             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLFAST_ACQCKMNGIF()

#define POST_RE_SYNC_SDLFAST_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveTestEnd_AcqCkMngIf          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVETESTEND_ACQCKMNGIF()

#define POST_RE_SYNC_EVETESTEND_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlVAct_EveExCmToo_AcqVlVActPos      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_EVEEXCMTOO_ACQVLVACTPOS()

#define POST_RE_VLVACT_EVEEXCMTOO_ACQVLVACTPOS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveTDC_AcqCkMngIf              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVETDC_ACQCKMNGIF()

#define POST_RE_SYNC_EVETDC_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveRst_InCmStsIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVERST_INCMSTSIF()

#define POST_RE_SYNC_EVERST_INCMSTSIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkOff_AcqSyncSTT            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKOFF_ACQSYNCSTT()

#define POST_RE_SYNC_EVECKOFF_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveStTR_AcqCkMngIf             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVESTTR_ACQCKMNGIF()

#define POST_RE_SYNC_EVESTTR_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveExCamEdge_AcqSyncSTT        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEEXCAMEDGE_ACQSYNCSTT()

#define POST_RE_SYNC_EVEEXCAMEDGE_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveRst_ExCmStsIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVERST_EXCMSTSIF()

#define POST_RE_SYNC_EVERST_EXCMSTSIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlSlow_AcqExCmSts             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLSLOW_ACQEXCMSTS()

#define POST_RE_SYNC_SDLSLOW_ACQEXCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveExCmToo_AcqExCmSts          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEEXCMTOO_ACQEXCMSTS()

#define POST_RE_SYNC_EVEEXCMTOO_ACQEXCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveKOn_AcqCkMngIf              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEKON_ACQCKMNGIF()

#define POST_RE_SYNC_EVEKON_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkTo_AcqSyncSTT             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKTO_ACQSYNCSTT()

#define POST_RE_SYNC_EVECKTO_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkSnOf_AcqSyncSTT           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKSNOF_ACQSYNCSTT()

#define POST_RE_SYNC_EVECKSNOF_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkLTo_AcqSyncSTT            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKLTO_ACQSYNCSTT()

#define POST_RE_SYNC_EVECKLTO_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VlvAct_EveRst_AcqVlVActPos          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VLVACT_EVERST_ACQVLVACTPOS()

#define POST_RE_VLVACT_EVERST_ACQVLVACTPOS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlMid_AcqSyncSTT              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLMID_ACQSYNCSTT()

#define POST_RE_SYNC_SDLMID_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveSyncAccu_AcqSyncSTT         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVESYNCACCU_ACQSYNCSTT()

#define POST_RE_SYNC_EVESYNCACCU_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveNInvOff_AcqSyncSTT          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVENINVOFF_ACQSYNCSTT()

#define POST_RE_SYNC_EVENINVOFF_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveInCmToo_AcqInCmSts          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEINCMTOO_ACQINCMSTS()

#define POST_RE_SYNC_EVEINCMTOO_ACQINCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveBDC_AcqCkMngIf              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEBDC_ACQCKMNGIF()

#define POST_RE_SYNC_EVEBDC_ACQCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlSlow_AcqInCmSts             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLSLOW_ACQINCMSTS()

#define POST_RE_SYNC_SDLSLOW_ACQINCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveRst_AcqSyncSTT              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVERST_ACQSYNCSTT()

#define POST_RE_SYNC_EVERST_ACQSYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_EveOilLvl_OilLvlHalAcq          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_EVEOILLVL_OILLVLHALACQ()

#define POST_RE_OIL_EVEOILLVL_OILLVLHALACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Oil_SdlFast_OilLvlHalAcq            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OIL_SDLFAST_OILLVLHALACQ()

#define POST_RE_OIL_SDLFAST_OILLVLHALACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OILLVLHALACQ_DT_vidEntryInit        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILLVLHALACQ_DT_VIDENTRYINIT()

#define POST_RE_OILLVLHALACQ_DT_VIDENTRYINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_ORng_Cat_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_ORNG_CAT_SETEVENTSTATUS()

#define POST_RE_CATMON_ORNG_CAT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_ORng_Cat_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_ORNG_CAT_GETEVENTSTATUS()

#define POST_RE_CATMON_ORNG_CAT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_ORng_CatApv_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_ORNG_CATAPV_SETEVENTSTATUS()

#define POST_RE_CATMON_ORNG_CATAPV_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CatMon_ORng_CatApv_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CATMON_ORNG_CATAPV_GETEVENTSTATUS()

#define POST_RE_CATMON_ORNG_CATAPV_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgt_ObsAdp_SetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGT_OBSADP_SETEVENTSTATUS()

#define POST_RE_AFAMGT_OBSADP_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgt_ObsAdp_GetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGT_OBSADP_GETEVENTSTATUS()

#define POST_RE_AFAMGT_OBSADP_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFEGRVLVLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFEGRVLVLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffEGRVlvLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFEGRVLVLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFEGRVLVLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS1LIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS1LIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs1Lim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS1LIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS1LIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS2LIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS2LIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs2Lim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS2LIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS2LIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS3LIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS3LIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfs3Lim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFS3LIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFS3LIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFSLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFSLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpArEffThrOfsLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPAREFFTHROFSLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPAREFFTHROFSLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpClsExOfsLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPCLSEXOFSLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPCLSEXOFSLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpClsExOfsLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPCLSEXOFSLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPCLSEXOFSLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpInjOfsLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPINJOFSLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPINJOFSLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpInjOfsLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPINJOFSLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPINJOFSLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpIvsInjConLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPIVSINJCONLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPIVSINJCONLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpIvsInjConLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPIVSINJCONLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPIVSINJCONLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpOpInOfsLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPOPINOFSLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPOPINOFSLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpOpInOfsLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPOPINOFSLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPOPINOFSLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpSlopInjConLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPSLOPINJCONLIM_SETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPSLOPINJCONLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_AFA_AdpSlopInjConLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_AFA_ADPSLOPINJCONLIM_GETEVENTSTATUS()

#define POST_RE_AFAT_AFA_ADPSLOPINJCONLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_Blt_SetEventStatus           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_BLT_SETEVENTSTATUS()

#define POST_RE_COPTUH_BLT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_Blt_GetEventStatus           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_BLT_GETEVENTSTATUS()

#define POST_RE_COPTUH_BLT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_CutReq_SetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_CUTREQ_SETEVENTSTATUS()

#define POST_RE_COPTUH_CUTREQ_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_CutReq_GetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_CUTREQ_GETEVENTSTATUS()

#define POST_RE_COPTUH_CUTREQ_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcClu_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCCLU_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCCLU_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcClu_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCCLU_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCCLU_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcNeut_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCNEUT_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCNEUT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcNeut_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCNEUT_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCNEUT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearEnaClu_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARENACLU_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARENACLU_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearEnaClu_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARENACLU_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARENACLU_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearNeut_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARNEUT_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARNEUT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearNeut_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARNEUT_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARNEUT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcMinClu_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCMINCLU_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCMINCLU_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGcMinClu_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGCMINCLU_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGCMINCLU_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearMinClu_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARMINCLU_SETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARMINCLU_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_ORngGearMinClu_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_ORNGGEARMINCLU_GETEVENTSTATUS()

#define POST_RE_COPTUH_ORNGGEARMINCLU_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_LgEngRStrtInh_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_LGENGRSTRTINH_SETEVENTSTATUS()

#define POST_RE_COPTUH_LGENGRSTRTINH_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPtUH_LgEngRStrtInh_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTUH_LGENGRSTRTINH_GETEVENTSTATUS()

#define POST_RE_COPTUH_LGENGRSTRTINH_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DfwCtl_ProtAdp_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DFWCTL_PROTADP_SETEVENTSTATUS()

#define POST_RE_DFWCTL_PROTADP_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DfwCtl_ProtAdp_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DFWCTL_PROTADP_GETEVENTSTATUS()

#define POST_RE_DFWCTL_PROTADP_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOnOffHi_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTONOFFHI_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTONOFFHI_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOnOffHi_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTONOFFHI_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTONOFFHI_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOnOffLo_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTONOFFLO_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTONOFFLO_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOnOffLo_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTONOFFLO_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTONOFFLO_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOscCfm_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTOSCCFM_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTOSCCFM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftOscCfm_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTOSCCFM_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTOSCCFM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegHi_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGHI_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGHI_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegHi_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGHI_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGHI_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegHiCfm_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGHICFM_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGHICFM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegHiCfm_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGHICFM_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGHICFM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegLo_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGLO_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGLO_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegLo_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGLO_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGLO_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegLoCfm_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGLOCFM_SETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGLOCFM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_DftRegLoCfm_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_DFTREGLOCFM_GETEVENTSTATUS()

#define POST_RE_OILSYS_DFTREGLOCFM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresMesFrz_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESMESFRZ_SETEVENTSTATUS()

#define POST_RE_OILSYS_PRESMESFRZ_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresMesFrz_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESMESFRZ_GETEVENTSTATUS()

#define POST_RE_OILSYS_PRESMESFRZ_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresToHi_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESTOHI_SETEVENTSTATUS()

#define POST_RE_OILSYS_PRESTOHI_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresToHi_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESTOHI_GETEVENTSTATUS()

#define POST_RE_OILSYS_PRESTOHI_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresToLo_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESTOLO_SETEVENTSTATUS()

#define POST_RE_OILSYS_PRESTOLO_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_PresToLo_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_PRESTOLO_GETEVENTSTATUS()

#define POST_RE_OILSYS_PRESTOLO_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__iBattMes_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__IBATTMES_SETEVENTSTATUS()

#define POST_RE_BATMGT__IBATTMES_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__iBattMes_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__IBATTMES_GETEVENTSTATUS()

#define POST_RE_BATMGT__IBATTMES_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__resBattIt_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__RESBATTIT_SETEVENTSTATUS()

#define POST_RE_BATMGT__RESBATTIT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__resBattIt_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__RESBATTIT_GETEVENTSTATUS()

#define POST_RE_BATMGT__RESBATTIT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__tBattMes_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__TBATTMES_SETEVENTSTATUS()

#define POST_RE_BATMGT__TBATTMES_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__tBattMes_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__TBATTMES_GETEVENTSTATUS()

#define POST_RE_BATMGT__TBATTMES_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattMes_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTMES_SETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTMES_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattMes_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTMES_GETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTMES_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattRstrt_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTRSTRT_SETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTRSTRT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattRstrt_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTRSTRT_GETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTRSTRT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ElProdMgt_CorLoss_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ELPRODMGT_CORLOSS_SETEVENTSTATUS()

#define POST_RE_ELPRODMGT_CORLOSS_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ElProdMgt_CorLoss_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ELPRODMGT_CORLOSS_GETEVENTSTATUS()

#define POST_RE_ELPRODMGT_CORLOSS_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoOptmEl_TqAlt_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COOPTMEL_TQALT_SETEVENTSTATUS()

#define POST_RE_COOPTMEL_TQALT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoOptmEl_TqAlt_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COOPTMEL_TQALT_GETEVENTSTATUS()

#define POST_RE_COOPTMEL_TQALT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattOc_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTOC_SETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTOC_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattOc_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTOC_GETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTOC_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattStrt_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTSTRT_SETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTSTRT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattStrt_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTSTRT_GETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTSTRT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ElProdMgt_CorSpCur_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ELPRODMGT_CORSPCUR_SETEVENTSTATUS()

#define POST_RE_ELPRODMGT_CORSPCUR_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ElProdMgt_CorSpCur_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ELPRODMGT_CORSPCUR_GETEVENTSTATUS()

#define POST_RE_ELPRODMGT_CORSPCUR_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__iBattMaxCkg_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__IBATTMAXCKG_SETEVENTSTATUS()

#define POST_RE_BATMGT__IBATTMAXCKG_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__iBattMaxCkg_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__IBATTMAXCKG_GETEVENTSTATUS()

#define POST_RE_BATMGT__IBATTMAXCKG_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__rBattSoC_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__RBATTSOC_SETEVENTSTATUS()

#define POST_RE_BATMGT__RBATTSOC_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__rBattSoC_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__RBATTSOC_GETEVENTSTATUS()

#define POST_RE_BATMGT__RBATTSOC_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattMinCkg_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTMINCKG_SETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTMINCKG_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_BatMgt__uBattMinCkg_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_BATMGT__UBATTMINCKG_GETEVENTSTATUS()

#define POST_RE_BATMGT__UBATTMINCKG_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_RCDLineScg_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_RCDLINESCG_SETEVENTSTATUS()

#define POST_RE_UCE_RCDLINESCG_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_RCDLineScg_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_RCDLINESCG_GETEVENTSTATUS()

#define POST_RE_UCE_RCDLINESCG_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_MainWkuDisrd_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_MAINWKUDISRD_SETEVENTSTATUS()

#define POST_RE_UCE_MAINWKUDISRD_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_MainWkuDisrd_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_MAINWKUDISRD_GETEVENTSTATUS()

#define POST_RE_UCE_MAINWKUDISRD_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_MainWkuIncst_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_MAINWKUINCST_SETEVENTSTATUS()

#define POST_RE_UCE_MAINWKUINCST_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UCE_MainWkuIncst_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_UCE_MAINWKUINCST_GETEVENTSTATUS()

#define POST_RE_UCE_MAINWKUINCST_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaCmd_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STACMD_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STACMD_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaCmd_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STACMD_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STACMD_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaElCmd_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAELCMD_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAELCMD_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaElCmd_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAELCMD_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAELCMD_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StuckMec_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STUCKMEC_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STUCKMEC_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StuckMec_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STUCKMEC_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STUCKMEC_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaAcvThd1_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAACVTHD1_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAACVTHD1_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaAcvThd1_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAACVTHD1_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAACVTHD1_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaAcvThd2_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAACVTHD2_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAACVTHD2_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaAcvThd2_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STAACVTHD2_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STAACVTHD2_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaCmdInfo_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STACMDINFO_SETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STACMDINFO_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StaStrtMgt_StaCmdInfo_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STASTRTMGT_STACMDINFO_GETEVENTSTATUS()

#define POST_RE_STASTRTMGT_STACMDINFO_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoSTT_ORngCutOffReq_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTT_ORNGCUTOFFREQ_SETEVENTSTATUS()

#define POST_RE_COSTT_ORNGCUTOFFREQ_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoSTT_ORngCutOffReq_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTT_ORNGCUTOFFREQ_GETEVENTSTATUS()

#define POST_RE_COSTT_ORNGCUTOFFREQ_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoSTT_ORngStopReq_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTT_ORNGSTOPREQ_SETEVENTSTATUS()

#define POST_RE_COSTT_ORNGSTOPREQ_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoSTT_ORngStopReq_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTT_ORNGSTOPREQ_GETEVENTSTATUS()

#define POST_RE_COSTT_ORNGSTOPREQ_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_ORngMplReq_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_ORNGMPLREQ_SETEVENTSTATUS()

#define POST_RE_COPTST_ORNGMPLREQ_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_ORngMplReq_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_ORNGMPLREQ_GETEVENTSTATUS()

#define POST_RE_COPTST_ORNGMPLREQ_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_SftyORngAMT_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_SFTYORNGAMT_SETEVENTSTATUS()

#define POST_RE_COPTST_SFTYORNGAMT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_SftyORngAMT_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_SFTYORNGAMT_GETEVENTSTATUS()

#define POST_RE_COPTST_SFTYORNGAMT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_SftyORngAT_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_SFTYORNGAT_SETEVENTSTATUS()

#define POST_RE_COPTST_SFTYORNGAT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoPTSt_SftyORngAT_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COPTST_SFTYORNGAT_GETEVENTSTATUS()

#define POST_RE_COPTST_SFTYORNGAT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_AntiBoil_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_ANTIBOIL_SETEVENTSTATUS()

#define POST_RE_THMGT_ANTIBOIL_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_AntiBoil_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_ANTIBOIL_GETEVENTSTATUS()

#define POST_RE_THMGT_ANTIBOIL_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_CoSysDfct_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_COSYSDFCT_SETEVENTSTATUS()

#define POST_RE_THMGT_COSYSDFCT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_CoSysDfct_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_COSYSDFCT_GETEVENTSTATUS()

#define POST_RE_THMGT_COSYSDFCT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_FSFBlockCls_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_FSFBLOCKCLS_SETEVENTSTATUS()

#define POST_RE_THMGT_FSFBLOCKCLS_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_FSFBlockCls_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_FSFBLOCKCLS_GETEVENTSTATUS()

#define POST_RE_THMGT_FSFBLOCKCLS_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_FSFBlockOp_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_FSFBLOCKOP_SETEVENTSTATUS()

#define POST_RE_THMGT_FSFBLOCKOP_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_FSFBlockOp_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_FSFBLOCKOP_GETEVENTSTATUS()

#define POST_RE_THMGT_FSFBLOCKOP_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoBlock_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOBLOCK_SETEVENTSTATUS()

#define POST_RE_THMGT_TCOBLOCK_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoBlock_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOBLOCK_GETEVENTSTATUS()

#define POST_RE_THMGT_TCOBLOCK_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoOverEstim_SetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOOVERESTIM_SETEVENTSTATUS()

#define POST_RE_THMGT_TCOOVERESTIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoOverEstim_GetEventStatus   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOOVERESTIM_GETEVENTSTATUS()

#define POST_RE_THMGT_TCOOVERESTIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoSlowRise_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOSLOWRISE_SETEVENTSTATUS()

#define POST_RE_THMGT_TCOSLOWRISE_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoSlowRise_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOSLOWRISE_GETEVENTSTATUS()

#define POST_RE_THMGT_TCOSLOWRISE_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoUndEstim_SetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOUNDESTIM_SETEVENTSTATUS()

#define POST_RE_THMGT_TCOUNDESTIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoUndEstim_GetEventStatus    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOUNDESTIM_GETEVENTSTATUS()

#define POST_RE_THMGT_TCOUNDESTIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoWarn_SetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOWARN_SETEVENTSTATUS()

#define POST_RE_THMGT_TCOWARN_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_TCoWarn_GetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_TCOWARN_GETEVENTSTATUS()

#define POST_RE_THMGT_TCOWARN_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_ThermoStuckCls_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_THERMOSTUCKCLS_SETEVENTSTATUS()

#define POST_RE_THMGT_THERMOSTUCKCLS_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_ThermoStuckCls_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_THERMOSTUCKCLS_GETEVENTSTATUS()

#define POST_RE_THMGT_THERMOSTUCKCLS_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_ThermoStuckOp_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_THERMOSTUCKOP_SETEVENTSTATUS()

#define POST_RE_THMGT_THERMOSTUCKOP_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_ThermoStuckOp_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_THERMOSTUCKOP_GETEVENTSTATUS()

#define POST_RE_THMGT_THERMOSTUCKOP_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngHiDragRed_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGHIDRAGRED_SETEVENTSTATUS()

#define POST_RE_TQADP_ORNGHIDRAGRED_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngHiDragRed_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGHIDRAGRED_GETEVENTSTATUS()

#define POST_RE_TQADP_ORNGHIDRAGRED_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngHiNeut_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGHINEUT_SETEVENTSTATUS()

#define POST_RE_TQADP_ORNGHINEUT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngHiNeut_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGHINEUT_GETEVENTSTATUS()

#define POST_RE_TQADP_ORNGHINEUT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngLoDragRed_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGLODRAGRED_SETEVENTSTATUS()

#define POST_RE_TQADP_ORNGLODRAGRED_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngLoDragRed_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGLODRAGRED_GETEVENTSTATUS()

#define POST_RE_TQADP_ORNGLODRAGRED_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngLoNeut_SetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGLONEUT_SETEVENTSTATUS()

#define POST_RE_TQADP_ORNGLONEUT_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_ORngLoNeut_GetEventStatus     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_ORNGLONEUT_GETEVENTSTATUS()

#define POST_RE_TQADP_ORNGLONEUT_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqCmp_tqAltRv_SetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQCMP_TQALTRV_SETEVENTSTATUS()

#define POST_RE_TQCMP_TQALTRV_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqCmp_tqAltRv_GetEventStatus        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQCMP_TQALTRV_GETEVENTSTATUS()

#define POST_RE_TQCMP_TQALTRV_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbAct_ArDeltaCorLim_SetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACT_ARDELTACORLIM_SETEVENTSTATUS()

#define POST_RE_TRBACT_ARDELTACORLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbAct_ArDeltaCorLim_GetEventStatus */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACT_ARDELTACORLIM_GETEVENTSTATUS()

#define POST_RE_TRBACT_ARDELTACORLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_RatConvTraClc_SetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_RATCONVTRACLC_SETEVENTSTATUS()

#define POST_RE_VSCTL_RATCONVTRACLC_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_RatConvTraClc_GetEventStatus  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_RATCONVTRACLC_GETEVENTSTATUS()

#define POST_RE_VSCTL_RATCONVTRACLC_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_SpdVehClc_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_SPDVEHCLC_SETEVENTSTATUS()

#define POST_RE_VSCTL_SPDVEHCLC_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_SpdVehClc_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_SPDVEHCLC_GETEVENTSTATUS()

#define POST_RE_VSCTL_SPDVEHCLC_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSLim_SetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSLIM_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSLIM_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSLim_GetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSLIM_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSLIM_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSLimBody_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSLIMBODY_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSLIMBODY_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSLimBody_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSLIMBODY_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSLIMBODY_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSMax_SetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSMAX_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSMAX_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSMax_GetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSMAX_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSMAX_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSMaxp_SetEventStatus         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSMAXP_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSMAXP_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSMaxp_GetEventStatus         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSMAXP_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSMAXP_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSReg_SetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREG_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSREG_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSReg_GetEventStatus          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREG_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSREG_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSRegBody_SetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREGBODY_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSREGBODY_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSRegBody_GetEventStatus      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREGBODY_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSREGBODY_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSRegVeh_SetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREGVEH_SETEVENTSTATUS()

#define POST_RE_VSCTL_VSREGVEH_SETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCtl_VSRegVeh_GetEventStatus       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCTL_VSREGVEH_GETEVENTSTATUS()

#define POST_RE_VSCTL_VSREGVEH_GETEVENTSTATUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhIrvOxCMon_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHIRVOXCMON_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHIRVOXCMON_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvOxCMon_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVOXCMON_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVOXCMON_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCatMonFacFrz_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCATMONFACFRZ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCATMONFACFRZ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPasCatMon_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPASCATMON_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPASCATMON_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhACOn_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHACON_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHACON_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhACRlsTakeOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHACRLSTAKEOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHACRLSTAKEOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBrioVst_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBRIOVST_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBRIOVST_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPwrPresInvld_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPWRPRESINVLD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPWRPRESINVLD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvFrzESP_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVFRZESP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVFRZESP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimAgIgWup_tAir_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMAGIGWUP_TAIR_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMAGIGWUP_TAIR_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimAgIgWup_tCo_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMAGIGWUP_TCO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMAGIGWUP_TCO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvPAirExtMesDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVPAIREXTMESDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVPAIREXTMESDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTCoMesDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTCOMESDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTCOMESDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCll_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCLL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCLL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimSelCutOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMSELCUTOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMSELCUTOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bActAFAAdpRst_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACTAFAADPRST_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACTAFAADPRST_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bActAFAInjGainRst_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACTAFAINJGAINRST_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACTAFAINJGAINRST_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAdpClcStRstReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVADPCLCSTRSTREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVADPCLCSTRSTREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAdpValRstReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVADPVALRSTREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVADPVALRSTREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAFA_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHAFA_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHAFA_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAFAObsAdp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHAFAOBSADP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHAFAOBSADP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhInMNomMod_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHINMNOMMOD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHINMNOMMOD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAirThrArSpByp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVAIRTHRARSPBYP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVAIRTHRARSPBYP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPIAirSys_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPIAIRSYS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPIAIRSYS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDmpVlvCtlThr_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDMPVLVCTLTHR_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDMPVLVCTLTHR_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCutCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCUTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCUTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvFastRstrtCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVFASTRSTRTCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVFASTRSTRTCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvRstrtCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVRSTRTCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVRSTRTCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCluPCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCLUPCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCLUPCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhNeutCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHNEUTCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHNEUTCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhSpdVehCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSPDVEHCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSPDVEHCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvRunCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVRUNCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVRUNCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCutCoPtASE_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCUTCOPTASE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCUTCOPTASE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtBrk_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTBRK_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTBRK_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtSpdVeh_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTSPDVEH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTSPDVEH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtStPt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTSTPT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTSTPT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtTCo_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTTCO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTTCO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqCll_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQCLL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQCLL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoEmSTTVSSCtzStrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOEMSTTVSSCTZSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOEMSTTVSSCTZSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTT_uEmPredRstrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTT_UEMPREDRSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTT_UEMPREDRSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTTNwCurClcStop_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTTNWCURCLCSTOP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTTNWCURCLCSTOP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTTStopAuth_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTTSTOPAUTH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTTSTOPAUTH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTTVSSCtzStrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTTVSSCTZSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTTVSSCTZSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTTWaitStrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTTWAITSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTTWAITSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoEmSTTDftUcapCurSp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOEMSTTDFTUCAPCURSP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOEMSTTDFTUCAPCURSP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoEmSTTDftUcapVoltSp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOEMSTTDFTUCAPVOLTSP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOEMSTTDFTUCAPVOLTSP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoEmSTTRstrtReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOEMSTTRSTRTREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOEMSTTRSTRTREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTT_uVSSCtzRstrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTT_UVSSCTZRSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTT_UVSSCTZRSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoEmSTTNwCurMv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOEMSTTNWCURMV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOEMSTTNWCURMV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoEmSTTCutReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOEMSTTCUTREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOEMSTTCUTREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvDrvTraInvld_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVDRVTRAINVLD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVDRVTRAINVLD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDft_CluPedPrss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFT_CLUPEDPRSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFT_CLUPEDPRSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDft_spdVeh_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFT_SPDVEH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFT_SPDVEH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhOverShootDet_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHOVERSHOOTDET_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHOVERSHOOTDET_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDft_bBrkPedPrss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFT_BBRKPEDPRSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFT_BBRKPEDPRSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDft_bCluPPedPrss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFT_BCLUPPEDPRSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFT_BCLUPPEDPRSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCutTotCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCUTTOTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCUTTOTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvRStrtCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVRSTRTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVRSTRTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvRunCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVRUNCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVRUNCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvSTTLitCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVSTTLITCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVSTTLITCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCluPCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCLUPCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCLUPCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhNeutCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHNEUTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHNEUTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPushCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPUSHCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPUSHCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhspdVehCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSPDVEHCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSPDVEHCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStopCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTOPCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTOPCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvFastRStrtCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVFASTRSTRTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVFASTRSTRTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCtlDmprAuth_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCTLDMPRAUTH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCTLDMPRAUTH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDgoBltCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDGOBLTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDGOBLTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDgoCluNeutCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDGOCLUNEUTCOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDGOCLUNEUTCOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRelBrkAsiCoPtUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRELBRKASICOPTUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRELBRKASICOPTUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAOS_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHAOS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHAOS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhOscDet_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHOSCDET_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHOSCDET_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvUsThrCtlDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVUSTHRCTLDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVUSTHRCTLDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDmpVlvCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDMPVLVCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDMPVLVCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStraLimSurge_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTRALIMSURGE_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTRALIMSURGE_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimRvEngLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMRVENGLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMRVENGLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhInrtLim_tCoMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHINRTLIM_TCOMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHINRTLIM_TCOMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvInrtLim_bCluP_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVINRTLIM_BCLUP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVINRTLIM_BCLUP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvInrtLim_bRvs_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVINRTLIM_BRVS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVINRTLIM_BRVS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvInrtLim_spdVeh_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVINRTLIM_SPDVEH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVINRTLIM_SPDVEH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRedLdMax_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BREDLDMAX_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BREDLDMAX_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLimLd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLIMLD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLIMLD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLockVlvRbl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLOCKVLVRBL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLOCKVLVRBL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhLdTrb_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHLDTRB_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHLDTRB_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLimThrPresDelta_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLIMTHRPRESDELTA_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLIMTHRPRESDELTA_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimRich_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMRICH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMRICH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCmbModDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCMBMODDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCMBMODDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCmbModHiLvlDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCMBMODHILVLDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCMBMODHILVLDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvNomModPrio_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVNOMMODPRIO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVNOMMODPRIO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCmbModPrf_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCMBMODPRF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCMBMODPRF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLimTExIni_tCo_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIMTEXINI_TCO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIMTEXINI_TCO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bSenPres_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BSENPRES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BSENPRES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bTrbAct_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BTRBACT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BTRBACT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bSenTEg_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BSENTEG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BSENTEG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bLihAstWupSTT_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BLIHASTWUPSTT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BLIHASTWUPSTT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAflLih_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVAFLLIH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVAFLLIH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAfrLih_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVAFRLIH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVAFRLIH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAfsLih_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVAFSLIH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVAFSLIH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhGSI3_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHGSI3_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHGSI3_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhInMDynCor_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHINMDYNCOR_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHINMDYNCOR_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhInThMEngSpdCor_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHINTHMENGSPDCOR_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHINTHMENGSPDCOR_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhInThM_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHINTHM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHINTHM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhMPM_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHMPM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHMPM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvModTog_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVMODTOG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVMODTOG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftCmVlv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTCMVLV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTCMVLV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftPOilMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTPOILMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTPOILMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftTCoMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTTCOMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTTCOMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftTOilMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTTOILMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTTOILMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhOilPmpPropCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHOILPMPPROPCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHOILPMPPROPCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPAirExtMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPAIREXTMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPAIREXTMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bOilPmpVolMaxForc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BOILPMPVOLMAXFORC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BOILPMPVOLMAXFORC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bUncrtTq_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BUNCRTTQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BUNCRTTQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhESPReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHESPREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHESPREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElDftLvlProd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELDFTLVLPROD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELDFTLVLPROD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElDftSoC_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELDFTSOC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELDFTSOC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElSatLvlProd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELSATLVLPROD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELSATLVLPROD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElElMgtReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELELMGTREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELELMGTREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElEngReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELENGREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELENGREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElFrntTraReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELFRNTTRAREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELFRNTTRAREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElFrzLvlProd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELFRZLVLPROD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELFRZLVLPROD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElReTraReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELRETRAREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELRETRAREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElStra_tAirExt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELSTRA_TAIREXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELSTRA_TAIREXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElTHom_tAirExt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELTHOM_TAIREXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELTHOM_TAIREXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElTHom_tBatt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELTHOM_TBATT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELTHOM_TBATT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElWup_tBatt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELWUP_TBATT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELWUP_TBATT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElWupElMgt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELWUPELMGT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELWUPELMGT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvBatMgtDftValStBatt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVBATMGTDFTVALSTBATT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVBATMGTDFTVALSTBATT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtSoCClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTSOCCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTSOCCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtTestCohVolt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTTESTCOHVOLT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTTESTCOHVOLT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtCorVoltSp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTCORVOLTSP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTCORVOLTSP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmEl_tBatt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMEL_TBATT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMEL_TBATT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmEl_tCo_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMEL_TCO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMEL_TCO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElBattElEProv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELBATTELEPROV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELBATTELEPROV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElProdElEProv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELPRODELEPROV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELPRODELEPROV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElSlopStra_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELSLOPSTRA_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELSLOPSTRA_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElSoCSpDftVal_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELSOCSPDFTVAL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELSOCSPDFTVAL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElBackUpStra_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELBACKUPSTRA_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELBACKUPSTRA_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElBlsProd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELBLSPROD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELBLSPROD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElCurAuxEstim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELCURAUXESTIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELCURAUXESTIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElRvAltLoss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELRVALTLOSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELRVALTLOSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElTHom_iBatt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELTHOM_IBATT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELTHOM_IBATT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElTHom_spdVeh_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELTHOM_SPDVEH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELTHOM_SPDVEH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElTHomElMgt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELTHOMELMGT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELTHOMELMGT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgt_uBattRstrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGT_UBATTRSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGT_UBATTRSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtBattNotConn_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTBATTNOTCONN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTBATTNOTCONN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtCurBattMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTCURBATTMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTCURBATTMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtKmAntiAgi_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTKMANTIAGI_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTKMANTIAGI_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtPerAntiAgi_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTPERANTIAGI_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTPERANTIAGI_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtSoH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTSOH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTSOH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtStSoCAfts_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTSTSOCAFTS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTSTSOCAFTS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtTBattMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTTBATTMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTTBATTMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtTiAntiAgi_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTTIANTIAGI_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTTIANTIAGI_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtVoltBattClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTVOLTBATTCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTVOLTBATTCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvElProdMgtStraDftCom_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVELPRODMGTSTRADFTCOM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVELPRODMGTSTRADFTCOM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvElProdMgtStraDftEl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVELPRODMGTSTRADFTEL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVELPRODMGTSTRADFTEL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvElProdMgtStraDftMec_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVELPRODMGTSTRADFTMEC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVELPRODMGTSTRADFTMEC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtAltOfsSpMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTALTOFSSPMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTALTOFSSPMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtAltProvIdf_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTALTPROVIDF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTALTPROVIDF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtAltVoltSp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTALTVOLTSP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTALTVOLTSP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtCorOfsLoss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTCOROFSLOSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTCOROFSLOSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtDiagCorLoss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTDIAGCORLOSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTDIAGCORLOSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhElProdMgtTqAltLoss_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHELPRODMGTTQALTLOSS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHELPRODMGTTQALTLOSS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoOptmElElMgtOldReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOOPTMELELMGTOLDREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOOPTMELELMGTOLDREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtDiagSoC_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTDIAGSOC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTDIAGSOC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtOfsSoC_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTOFSSOC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTOFSSOC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhBatMgtStcBattSoC_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHBATMGTSTCBATTSOC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHBATMGTSTCBATTSOC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoOptmElMinSoCReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOOPTMELMINSOCREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOOPTMELMINSOCREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqLimUHBrioUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQLIMUHBRIOUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQLIMUHBRIOUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTqLimUHMdl_tqGrdLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTQLIMUHMDL_TQGRDLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTQLIMUHMDL_TQGRDLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRecupUH_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRECUPUH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRECUPUH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRecupVoltCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRECUPVOLTCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRECUPVOLTCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhWup_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHWUP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHWUP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqLimUHAntiStall_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQLIMUHANTISTALL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQLIMUHANTISTALL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDrivTyp_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDRIVTYP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDRIVTYP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqLimUHTqMchFrz_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQLIMUHTQMCHFRZ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQLIMUHTQMCHFRZ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqSysStInjEs_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQSYSSTINJES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQSYSSTINJES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvStaStrtMgtDftValThd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVSTASTRTMGTDFTVALTHD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVSTASTRTMGTDFTVALTHD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvStaStrtMgtDiagElCmd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVSTASTRTMGTDIAGELCMD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVSTASTRTMGTDIAGELCMD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStaStrtMgtVoltFall_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTASTRTMGTVOLTFALL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTASTRTMGTVOLTFALL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvStaRstrtMgtDftValThd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVSTARSTRTMGTDFTVALTHD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVSTARSTRTMGTDFTVALTHD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvStaRstrtMgtDiagElCmd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVSTARSTRTMGTDIAGELCMD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVSTARSTRTMGTDIAGELCMD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStaRstrtMgtVoltFall_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTARSTRTMGTVOLTFALL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTARSTRTMGTVOLTFALL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStaStrtMgtDmgTiCnt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTASTRTMGTDMGTICNT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTASTRTMGTDMGTICNT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStaStrtMgtDmgVehDst_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTASTRTMGTDMGVEHDST_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTASTRTMGTDMGVEHDST_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhSta_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTA_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTA_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoPTStByp_nEng_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOPTSTBYP_NENG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOPTSTBYP_NENG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoPTStByp_spdVeh_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOPTSTBYP_SPDVEH_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOPTSTBYP_SPDVEH_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoPTStEngStop_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOPTSTENGSTOP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOPTSTENGSTOP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvEngCutOffRCDLo_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVENGCUTOFFRCDLO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVENGCUTOFFRCDLO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhEngCutOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHENGCUTOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHENGCUTOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhSTT_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvEngCutOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVENGCUTOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVENGCUTOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bStrtPrf_GetFunctionPermission  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BSTRTPRF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BSTRTPRF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvPrmCoTqRStrt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVPRMCOTQRSTRT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVPRMCOTQRSTRT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvAdFan_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVADFAN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVADFAN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvBattFan_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVBATTFAN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVBATTFAN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvBoilLimChg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVBOILLIMCHG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVBOILLIMCHG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoVlvMaxOp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOVLVMAXOP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOVLVMAXOP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoVlvOpByp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOVLVOPBYP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOVLVOPBYP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoVlvOpHeat_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOVLVOPHEAT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOVLVOPHEAT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvCoVlvOpRad_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVCOVLVOPRAD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVCOVLVOPRAD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvECUFan_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVECUFAN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVECUFAN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvEHRPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVEHRPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVEHRPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvFanHiSpd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVFANHISPD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVFANHISPD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvFanHiSpdRcvMod_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVFANHISPDRCVMOD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVFANHISPDRCVMOD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvFanLoSpd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVFANLOSPD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVFANLOSPD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvHeatWaPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVHEATWAPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVHEATWAPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLoTCoReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLOTCOREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLOTCOREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLoThdACCmprOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLOTHDACCMPROFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLOTHDACCMPROFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLoThdTCoWarn_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLOTHDTCOWARN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLOTHDTCOWARN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvNoEgdGearDft_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVNOEGDGEARDFT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVNOEGDGEARDFT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvOpFSF_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVOPFSF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVOPFSF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTCoWarn_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTCOWARN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTCOWARN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvModTAlt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVMODTALT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVMODTALT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvModTECU_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVMODTECU_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVMODTECU_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValMfEg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALMFEG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALMFEG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTAirExt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTAIREXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTAIREXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTAirIn_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTAIRIN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTAIRIN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTCAC_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTCAC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTCAC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTEg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTEG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTEG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTqIdc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTQIDC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTQIDC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvThMgtRcvValTUsPFlt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTHMGTRCVVALTUSPFLT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTHMGTRCVVALTUSPFLT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTrbWaPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTRBWAPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTRBWAPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvVeryLoTCoReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVVERYLOTCOREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVVERYLOTCOREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacCoBoilLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACCOBOILLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACCOBOILLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacCoVlv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACCOVLV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACCOVLV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDiMoveFSFReq_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDIMOVEFSFREQ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDIMOVEFSFREQ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCTICoHeat_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCTICOHEAT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCTICOHEAT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDiagCoBoilLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDIAGCOBOILLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDIAGCOBOILLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDiagFctFSF_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDIAGFCTFSF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDIAGFCTFSF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhDiagTCoWarn_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHDIAGTCOWARN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHDIAGTCOWARN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhECTPwrLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHECTPWRLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHECTPWRLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhEHRPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHEHRPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHEHRPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhHeatReqMainWaPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHHEATREQMAINWAPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHHEATREQMAINWAPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhHeatWaPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHHEATWAPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHHEATWAPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhIdlIncCoHeat_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHIDLINCCOHEAT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHIDLINCCOHEAT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTCoBlockDiag_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTCOBLOCKDIAG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTCOBLOCKDIAG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTCoColdDiag_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTCOCOLDDIAG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTCOCOLDDIAG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTCoMdlCompDiag_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTCOMDLCOMPDIAG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTCOMDLCOMPDIAG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTCoRiseDiag_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTCORISEDIAG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTCORISEDIAG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhThermoDiag1_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTHERMODIAG1_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTHERMODIAG1_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhSpdAdpThr_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSPDADPTHR_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSPDADPTHR_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvEcpHeatProt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVECPHEATPROT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVECPHEATPROT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTPMDecTMaxDev_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTPMDECTMAXDEV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTPMDECTMAXDEV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvLimScv_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVLIMSCV_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVLIMSCV_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTPMInhLsTWCSt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTPMINHLSTWCST_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTPMINHLSTWCST_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCutOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCUTOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCUTOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTqEngLossDftOil_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTQENGLOSSDFTOIL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTQENGLOSSDFTOIL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTqEngLossDftPDs_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTQENGLOSSDFTPDS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTQENGLOSSDFTPDS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTqEngLossDftPmp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTQENGLOSSDFTPMP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTQENGLOSSDFTPMP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvTqEngLossDftT_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVTQENGLOSSDFTT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVTQENGLOSSDFTT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftAltTyp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTALTTYP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTALTTYP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftComAlt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTCOMALT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTCOMALT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftElAlt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTELALT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTELALT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDftMecAlt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFTMECALT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFTMECALT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhACExtECULossMdl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHACEXTECULOSSMDL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHACEXTECULOSSMDL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhACItECULossMdl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHACITECULOSSMDL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHACITECULOSSMDL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAdp_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHADP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHADP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAltLossMdl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHALTLOSSMDL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHALTLOSSMDL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCnvLossMdl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCNVLOSSMDL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCNVLOSSMDL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhStgPmpLossMdl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSTGPMPLOSSMDL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSTGPMPLOSSMDL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTAirEstim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTAIRESTIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTAIRESTIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDft_pAirExt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDFT_PAIREXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDFT_PAIREXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAntiDB_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHANTIDB_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHANTIDB_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhEco_GetFunctionPermission   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHECO_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHECO_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhGreen_tCoMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHGREEN_TCOMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHGREEN_TCOMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhGreen_tOxCEstim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHGREEN_TOXCESTIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHGREEN_TOXCESTIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhNRegTakeOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHNREGTAKEOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHNREGTAKEOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhNTarIdlTakeOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHNTARIDLTAKEOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHNTARIDLTAKEOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRegNLimN_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHREGNLIMN_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHREGNLIMN_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvTqDemRevStOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVTQDEMREVSTOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVTQDEMREVSTOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhRvTqDemTakeOff_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHRVTQDEMTAKEOFF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHRVTQDEMTAKEOFF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqDemSptMod_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQDEMSPTMOD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQDEMSPTMOD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTqLimEM_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTQLIMEM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTQLIMEM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhAdp_tqEM_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHADP_TQEM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHADP_TQEM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtSIP_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTSIP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTSIP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhCoPtCrawl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHCOPTCRAWL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHCOPTCRAWL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPosnTrbActMod_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPOSNTRBACTMOD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPOSNTRBACTMOD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhSenCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHSENCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHSENCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhTrbActCmd_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHTRBACTCMD_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHTRBACTCMD_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhArAdpTrbAct_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHARADPTRBACT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHARADPTRBACT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhMes_pUsThrMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHMES_PUSTHRMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHMES_PUSTHRMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhPresSenAdj_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHPRESSENADJ_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHPRESSENADJ_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhMes_pAirExt_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHMES_PAIREXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHMES_PAIREXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhMes_pDsThrMes_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHMES_PDSTHRMES_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHMES_PDSTHRMES_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlKDCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLKDCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLKDCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacNFrntWhlClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACNFRNTWHLCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACNFRNTWHLCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacSpdVehClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACSPDVEHCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACSPDVEHCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlBrkClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLBRKCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLBRKCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlEngClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLENGCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLENGCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlGrdLkClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLGRDLKCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLGRDLKCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlLoWhlGripClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLLOWHLGRIPCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLLOWHLGRIPCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlNoGearChgClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLNOGEARCHGCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLNOGEARCHGCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlPTClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLPTCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLPTCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlTraClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLTRACLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLTRACLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlVehClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLVEHCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLVEHCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlWhlSlipClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLWHLSLIPCLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLWHLSLIPCLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlrTqWhlPTReClc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLRTQWHLPTRECLC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLRTQWHLPTRECLC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRcvVSCtlSpdFrntWhl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BRCVVSCTLSPDFRNTWHL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BRCVVSCTLSPDFRNTWHL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRcvVSCtlSpdReWhl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BRCVVSCTLSPDREWHL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BRCVVSCTLSPDREWHL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRcvVSCtlrConvTra_Ext_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BRCVVSCTLRCONVTRA_EXT_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BRCVVSCTLRCONVTRA_EXT_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRcvVSCtlrConvTra_Int1_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BRCVVSCTLRCONVTRA_INT1_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BRCVVSCTLRCONVTRA_INT1_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bRcvVSCtlrConvTra_Int2_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BRCVVSCTLRCONVTRA_INT2_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BRCVVSCTLRCONVTRA_INT2_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacIrvVSLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACIRVVSLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACIRVVSLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDiFastDeacVSCtlVSLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDIFASTDEACVSCTLVSLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDIFASTDEACVSCTLVSLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhVSLim_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHVSLIM_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHVSLIM_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvVSMax_no1_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVVSMAX_NO1_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVVSMAX_NO1_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bAcvVSMax_no2_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BACVVSMAX_NO2_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BACVVSMAX_NO2_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacIrvVSMax_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACIRVVSMAX_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACIRVVSMAX_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSMax_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSMAX_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSMAX_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSMaxc_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSMAXC_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSMAXC_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSMaxf_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSMAXF_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSMAXF_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSMaxp_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSMAXP_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSMAXP_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSMaxs_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSMAXS_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSMAXS_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhVSMax_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHVSMAX_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHVSMAX_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacIrvVSReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACIRVVSREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACIRVVSREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacRvVSReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACRVVSREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACRVVSREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacSatMaxSpdVehVSReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACSATMAXSPDVEHVSREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACSATMAXSPDVEHVSREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bInhVSReg_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BINHVSREG_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BINHVSREG_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FRM_bDeacVSCtlGearCtl_GetFunctionPermission */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FRM_BDEACVSCTLGEARCTL_GETFUNCTIONPERMISSION()

#define POST_RE_FRM_BDEACVSCTLGEARCTL_GETFUNCTIONPERMISSION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ACCmd_003_DRE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCMD_003_DRE()

#define POST_RE_ACCMD_003_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ACCmd_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCMD_001_MSE()

#define POST_RE_ACCMD_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ACCmd_004_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCMD_004_TEV()

#define POST_RE_ACCMD_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ACCmd_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ACCMD_002_TEV()

#define POST_RE_ACCMD_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvCordT_003_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVCORDT_003_MSE()

#define POST_RE_ADVCORDT_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvCordT_007_DRE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVCORDT_007_DRE()

#define POST_RE_ADVCORDT_007_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvCordT_002_DRE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVCORDT_002_DRE()

#define POST_RE_ADVCORDT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvCordT_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVCORDT_001_MSE()

#define POST_RE_ADVCORDT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvCordT_005_DRE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVCORDT_005_DRE()

#define POST_RE_ADVCORDT_005_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMaxT_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMAXT_001_MSE()

#define POST_RE_ADVMAXT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMaxT_002_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMAXT_002_DRE()

#define POST_RE_ADVMAXT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_008_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_008_DRE()

#define POST_RE_ADVMINT_008_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_002_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_002_DRE()

#define POST_RE_ADVMINT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_001_MSE()

#define POST_RE_ADVMINT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_005_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_005_MSE()

#define POST_RE_ADVMINT_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_006_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_006_DRE()

#define POST_RE_ADVMINT_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvOptmT_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVOPTMT_001_MSE()

#define POST_RE_ADVOPTMT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvOptmT_002_DRE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVOPTMT_002_DRE()

#define POST_RE_ADVOPTMT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvOptmT_003_DRE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVOPTMT_003_DRE()

#define POST_RE_ADVOPTMT_003_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvOptmT_004_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVOPTMT_004_MSE()

#define POST_RE_ADVOPTMT_004_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvPrevKnkT_002                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVPREVKNKT_002()

#define POST_RE_ADVPREVKNKT_002()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvPrevKnkT_001_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVPREVKNKT_001_MSE()

#define POST_RE_ADVPREVKNKT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_001_MSE()

#define POST_RE_ADVSPT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_002_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_002_DRE()

#define POST_RE_ADVSPT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_003_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_003_MSE()

#define POST_RE_ADVSPT_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_006_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_006_DRE()

#define POST_RE_ADVSPT_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_005_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_005_MSE()

#define POST_RE_ADVSPT_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvSpT_004_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVSPT_004_DRE()

#define POST_RE_ADVSPT_004_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_RstStart                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_RSTSTART()

#define POST_RE_AFAMGTT_RSTSTART()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsSesChgInd               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSSESCHGIND()

#define POST_RE_AFAMGTT_AFTSSESCHGIND()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvmChkRead              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVMCHKREAD()

#define POST_RE_AFAMGTT_AFTSNVMCHKREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvmWrite                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVMWRITE()

#define POST_RE_AFAMGTT_AFTSNVMWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsGetSesChgPerm           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSGETSESCHGPERM()

#define POST_RE_AFAMGTT_AFTSGETSESCHGPERM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_004_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_004_MSE()

#define POST_RE_AFAMGTT_004_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvmRead                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVMREAD()

#define POST_RE_AFAMGTT_AFTSNVMREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvmChkWrite             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVMCHKWRITE()

#define POST_RE_AFAMGTT_AFTSNVMCHKWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_RstRqResults                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_RSTRQRESULTS()

#define POST_RE_AFAMGTT_RSTRQRESULTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvm                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVM()

#define POST_RE_AFAMGTT_AFTSNVM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_003_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_003_TEV()

#define POST_RE_AFAMGTT_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_001_MSE()

#define POST_RE_AFAMGTT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftrsInit                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTRSINIT()

#define POST_RE_AFAMGTT_AFTRSINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_007_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_007_TEV()

#define POST_RE_AFAMGTT_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_AftsNvmRDL                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_AFTSNVMRDL()

#define POST_RE_AFAMGTT_AFTSNVMRDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAMgtT_002_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAMGTT_002_MSE()

#define POST_RE_AFAMGTT_002_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_002_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_002_MSE()

#define POST_RE_AFAT_002_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_005_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_005_TEV()

#define POST_RE_AFAT_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_006_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_006_TEV()

#define POST_RE_AFAT_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_003_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_003_MSE()

#define POST_RE_AFAT_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_007_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_007_TEV()

#define POST_RE_AFAT_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_004_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_004_TEV()

#define POST_RE_AFAT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_001_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_001_MSE()

#define POST_RE_AFAT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OP_LibEngCylPrm                        */
/*---------------------------------------------------------------------------*/
#define PRE_OP_LIBENGCYLPRM()

#define POST_OP_LIBENGCYLPRM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OP_LibAirEfc                           */
/*---------------------------------------------------------------------------*/
#define PRE_OP_LIBAIREFC()

#define POST_OP_LIBAIREFC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OP_LibVlvBasChg                        */
/*---------------------------------------------------------------------------*/
#define PRE_OP_LIBVLVBASCHG()

#define POST_OP_LIBVLVBASCHG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_005_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_005_TEV()

#define POST_RE_AIRSYSAIR_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_006_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_006_TEV()

#define POST_RE_AIRSYSAIR_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_002_TEV()

#define POST_RE_AIRSYSAIR_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_001_MSE()

#define POST_RE_AIRSYSAIR_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_003_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_003_TEV()

#define POST_RE_AIRSYSAIR_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_007_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_007_TEV()

#define POST_RE_AIRSYSAIR_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_004_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_004_TEV()

#define POST_RE_AIRSYSAIR_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysTrb_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSTRB_002_TEV()

#define POST_RE_AIRSYSTRB_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysTrb_003_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSTRB_003_TEV()

#define POST_RE_AIRSYSTRB_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysTrb_005_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSTRB_005_TEV()

#define POST_RE_AIRSYSTRB_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysTrb_004_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSTRB_004_TEV()

#define POST_RE_AIRSYSTRB_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysTrb_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSTRB_001_MSE()

#define POST_RE_AIRSYSTRB_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_002_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_002_TEV()

#define POST_RE_ASE_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_011_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_011_MSE()

#define POST_RE_ASE_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_005_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_005_MSE()

#define POST_RE_ASE_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_012_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_012_TEV()

#define POST_RE_ASE_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_006_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_006_TEV()

#define POST_RE_ASE_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_004_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_004_TEV()

#define POST_RE_ASE_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_008_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_008_TEV()

#define POST_RE_ASE_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_007_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_007_MSE()

#define POST_RE_ASE_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_010_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_010_TEV()

#define POST_RE_ASE_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_003_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_003_MSE()

#define POST_RE_ASE_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_009_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_009_MSE()

#define POST_RE_ASE_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ASE_001_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ASE_001_MSE()

#define POST_RE_ASE_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoClLASl_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COCLLASL_001_MSE()

#define POST_RE_COCLLASL_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_TqCll                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_TQCLL()

#define POST_RE_TQSYS_EVESYNC_TQCLL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_TqCordLim             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_TQCORDLIM()

#define POST_RE_TQSYS_EVESYNC_TQCORDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_VarAntiStall          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_VARANTISTALL()

#define POST_RE_TQSYS_EVESYNC_VARANTISTALL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CoPtAntiStall         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_COPTANTISTALL()

#define POST_RE_TQSYS_EVESYNC_COPTANTISTALL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_IdlCordLim            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_IDLCORDLIM()

#define POST_RE_TQSYS_SDL10MS_IDLCORDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_AntiStallReg          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_ANTISTALLREG()

#define POST_RE_TQSYS_EVESYNC_ANTISTALLREG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_IdlCordLim            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_IDLCORDLIM()

#define POST_RE_TQSYS_EVESYNC_IDLCORDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCordLim             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCORDLIM()

#define POST_RE_TQSYS_SDL10MS_TQCORDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CurCord               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CURCORD()

#define POST_RE_TQSYS_EVESYNC_CURCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoEmSTT_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COEMSTT_001_MSE()

#define POST_RE_COEMSTT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoEmSTT_AftsNvramWrite_1            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COEMSTT_AFTSNVRAMWRITE_1()

#define POST_RE_COEMSTT_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoEmSTT_002_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COEMSTT_002_TEV()

#define POST_RE_COEMSTT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoEmSTT_AftsNvramRead_1             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COEMSTT_AFTSNVRAMREAD_1()

#define POST_RE_COEMSTT_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoEmSTT_AftsNvramReset_1            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COEMSTT_AFTSNVRAMRESET_1()

#define POST_RE_COEMSTT_AFTSNVRAMRESET_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSyncFrame38D_Tra           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNCFRAME38D_TRA()

#define POST_RE_TQSYS_EVESYNCFRAME38D_TRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoGBx_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COGBX_001_MSE()

#define POST_RE_COGBX_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_CoPtGearCord          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_COPTGEARCORD()

#define POST_RE_TQSYS_SDL10MS_COPTGEARCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_CluPCord              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_CLUPCORD()

#define POST_RE_TQSYS_SDL10MS_CLUPCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSyncFrame30D_Tra           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNCFRAME30D_TRA()

#define POST_RE_TQSYS_EVESYNCFRAME30D_TRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_Tra                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_TRA()

#define POST_RE_TQSYS_EVESYNC_TRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl20ms_Tra                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL20MS_TRA()

#define POST_RE_TQSYS_SDL20MS_TRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_Tra                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TRA()

#define POST_RE_TQSYS_SDL10MS_TRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_AftsNvramReset_1        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_AFTSNVRAMRESET_1()

#define POST_RE_COSTOPSTART_AFTSNVRAMRESET_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_023_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_023_MSE()

#define POST_RE_COSTOPSTART_023_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_029_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_029_MSE()

#define POST_RE_COSTOPSTART_029_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_019_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_019_MSE()

#define POST_RE_COSTOPSTART_019_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_020_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_020_TEV()

#define POST_RE_COSTOPSTART_020_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_015_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_015_MSE()

#define POST_RE_COSTOPSTART_015_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_AftsNvramWrite_1        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_AFTSNVRAMWRITE_1()

#define POST_RE_COSTOPSTART_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_013_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_013_MSE()

#define POST_RE_COSTOPSTART_013_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_014_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_014_TEV()

#define POST_RE_COSTOPSTART_014_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_017_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_017_MSE()

#define POST_RE_COSTOPSTART_017_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_003_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_003_MSE()

#define POST_RE_COSTOPSTART_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_032_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_032_TEV()

#define POST_RE_COSTOPSTART_032_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_026_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_026_TEV()

#define POST_RE_COSTOPSTART_026_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_030_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_030_TEV()

#define POST_RE_COSTOPSTART_030_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_004_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_004_TEV()

#define POST_RE_COSTOPSTART_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_AftsNvramRead_1         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_AFTSNVRAMREAD_1()

#define POST_RE_COSTOPSTART_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_011_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_011_MSE()

#define POST_RE_COSTOPSTART_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_012_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_012_TEV()

#define POST_RE_COSTOPSTART_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_008_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_008_TEV()

#define POST_RE_COSTOPSTART_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_009_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_009_MSE()

#define POST_RE_COSTOPSTART_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_016_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_016_TEV()

#define POST_RE_COSTOPSTART_016_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_025_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_025_MSE()

#define POST_RE_COSTOPSTART_025_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_027_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_027_MSE()

#define POST_RE_COSTOPSTART_027_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_007_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_007_MSE()

#define POST_RE_COSTOPSTART_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_024_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_024_TEV()

#define POST_RE_COSTOPSTART_024_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_021_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_021_MSE()

#define POST_RE_COSTOPSTART_021_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_018_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_018_TEV()

#define POST_RE_COSTOPSTART_018_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_028_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_028_TEV()

#define POST_RE_COSTOPSTART_028_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_010_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_010_TEV()

#define POST_RE_COSTOPSTART_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_022_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_022_TEV()

#define POST_RE_COSTOPSTART_022_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoStopStart_031_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COSTOPSTART_031_MSE()

#define POST_RE_COSTOPSTART_031_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_010_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_010_TEV()

#define POST_RE_COTQ_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_002_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_002_TEV()

#define POST_RE_COTQ_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_011_DRE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_011_DRE()

#define POST_RE_COTQ_011_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_006_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_006_TEV()

#define POST_RE_COTQ_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_005_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_005_MSE()

#define POST_RE_COTQ_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_008_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_008_TEV()

#define POST_RE_COTQ_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_009_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_009_MSE()

#define POST_RE_COTQ_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_004_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_004_TEV()

#define POST_RE_COTQ_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_003_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_003_MSE()

#define POST_RE_COTQ_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_001_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_001_MSE()

#define POST_RE_COTQ_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoTq_007_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COTQ_007_MSE()

#define POST_RE_COTQ_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CurStCalc             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CURSTCALC()

#define POST_RE_TQSYS_EVESYNC_CURSTCALC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CurDrivFil_001_MSE                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_CURDRIVFIL_001_MSE()

#define POST_RE_CURDRIVFIL_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CurDrivFil            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CURDRIVFIL()

#define POST_RE_TQSYS_EVESYNC_CURDRIVFIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CurCor                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CURCOR()

#define POST_RE_TQSYS_EVESYNC_CURCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CutDyn                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CUTDYN()

#define POST_RE_TQSYS_EVESYNC_CUTDYN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_TqClrCros             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_TQCLRCROS()

#define POST_RE_TQSYS_EVESYNC_TQCLRCROS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_AOS                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_AOS()

#define POST_RE_TQSYS_EVESYNC_AOS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DfwCtl_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DFWCTL_002_TEV()

#define POST_RE_DFWCTL_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DfwCtl_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DFWCTL_001_MSE()

#define POST_RE_DFWCTL_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DfwCtl_AftsNvramRead_1                 */
/*---------------------------------------------------------------------------*/
#define PRE_DFWCTL_AFTSNVRAMREAD_1()

#define POST_DFWCTL_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DfwCtl_AftsNvramReset_1                */
/*---------------------------------------------------------------------------*/
#define PRE_DFWCTL_AFTSNVRAMRESET_1()

#define POST_DFWCTL_AFTSNVRAMRESET_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DmpVlv_H_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DMPVLV_H_001_MSE()

#define POST_RE_DMPVLV_H_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_DmpVlv_H_002_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_DMPVLV_H_002_TEV()

#define POST_RE_DMPVLV_H_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EBStub_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EBSTUB_001_MSE()

#define POST_RE_EBSTUB_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLim_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIM_001_MSE()

#define POST_RE_ENGLIM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_EngLimStat            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_ENGLIMSTAT()

#define POST_RE_TQSYS_SDL10MS_ENGLIMSTAT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqLimFwdRvs           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQLIMFWDRVS()

#define POST_RE_TQSYS_SDL10MS_TQLIMFWDRVS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_012_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_012_DRE()

#define POST_RE_ENGLIMTQT_012_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_009_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_009_MSE()

#define POST_RE_ENGLIMTQT_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_007_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_007_MSE()

#define POST_RE_ENGLIMTQT_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_002_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_002_DRE()

#define POST_RE_ENGLIMTQT_002_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_001_MSE()

#define POST_RE_ENGLIMTQT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_011_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_011_MSE()

#define POST_RE_ENGLIMTQT_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_014_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_014_DRE()

#define POST_RE_ENGLIMTQT_014_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_003_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_003_MSE()

#define POST_RE_ENGLIMTQT_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_008_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_008_DRE()

#define POST_RE_ENGLIMTQT_008_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_013_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_013_MSE()

#define POST_RE_ENGLIMTQT_013_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_006_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_006_DRE()

#define POST_RE_ENGLIMTQT_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_005_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_005_MSE()

#define POST_RE_ENGLIMTQT_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_004_DRE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_004_DRE()

#define POST_RE_ENGLIMTQT_004_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngLimTqT_010_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGLIMTQT_010_TEV()

#define POST_RE_ENGLIMTQT_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslLim_003_TEV                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLLIM_003_TEV()

#define POST_RE_ENGMGSLLIM_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslLim_001_MSE                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLLIM_001_MSE()

#define POST_RE_ENGMGSLLIM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslLim_002_TEV                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLLIM_002_TEV()

#define POST_RE_ENGMGSLLIM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_018_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_018_TEV()

#define POST_RE_ENGMGSLT_018_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_024_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_024_TEV()

#define POST_RE_ENGMGSLT_024_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_012_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_012_TEV()

#define POST_RE_ENGMGSLT_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_004_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_004_TEV()

#define POST_RE_ENGMGSLT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_022_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_022_TEV()

#define POST_RE_ENGMGSLT_022_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_008_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_008_TEV()

#define POST_RE_ENGMGSLT_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_020_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_020_TEV()

#define POST_RE_ENGMGSLT_020_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_001_MSE()

#define POST_RE_ENGMGSLT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_002_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_002_TEV()

#define POST_RE_ENGMGSLT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngMGslT_026_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGMGSLT_026_TEV()

#define POST_RE_ENGMGSLT_026_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EOMGsl_004_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EOMGSL_004_TEV()

#define POST_RE_EOMGSL_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EOMGsl_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EOMGSL_001_MSE()

#define POST_RE_EOMGSL_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EOMGsl_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EOMGSL_002_TEV()

#define POST_RE_EOMGSL_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EOMGsl_003_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EOMGSL_003_TEV()

#define POST_RE_EOMGSL_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT1_004_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT1_004_MSE()

#define POST_RE_EXMGSLT1_004_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT1_002_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT1_002_TEV()

#define POST_RE_EXMGSLT1_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT1_005_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT1_005_MSE()

#define POST_RE_EXMGSLT1_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT1_003_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT1_003_TEV()

#define POST_RE_EXMGSLT1_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_001_MSE()

#define POST_RE_EXMGSLT2_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_007_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_007_TEV()

#define POST_RE_EXMGSLT2_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_006_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_006_TEV()

#define POST_RE_EXMGSLT2_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_013_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_013_MSE()

#define POST_RE_FARSP_013_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_004_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_004_TEV()

#define POST_RE_FARSP_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_008_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_008_TEV()

#define POST_RE_FARSP_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_024_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_024_TEV()

#define POST_RE_FARSP_024_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_014_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_014_TEV()

#define POST_RE_FARSP_014_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_018_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_018_TEV()

#define POST_RE_FARSP_018_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_012_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_012_TEV()

#define POST_RE_FARSP_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_017_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_017_MSE()

#define POST_RE_FARSP_017_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_009_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_009_MSE()

#define POST_RE_FARSP_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_023_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_023_MSE()

#define POST_RE_FARSP_023_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_021_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_021_MSE()

#define POST_RE_FARSP_021_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_015_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_015_MSE()

#define POST_RE_FARSP_015_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_026_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_026_TEV()

#define POST_RE_FARSP_026_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_022_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_022_TEV()

#define POST_RE_FARSP_022_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_001_MSE()

#define POST_RE_FARSP_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_016_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_016_TEV()

#define POST_RE_FARSP_016_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_010_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_010_TEV()

#define POST_RE_FARSP_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_006_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_006_TEV()

#define POST_RE_FARSP_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_003_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_003_MSE()

#define POST_RE_FARSP_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_011_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_011_MSE()

#define POST_RE_FARSP_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_025_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_025_MSE()

#define POST_RE_FARSP_025_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_005_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_005_MSE()

#define POST_RE_FARSP_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_007_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_007_MSE()

#define POST_RE_FARSP_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_002_TEV()

#define POST_RE_FARSP_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FISA_CrankSync                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FISA_CRANKSYNC()

#define POST_RE_FISA_CRANKSYNC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FISA_init                           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FISA_INIT()

#define POST_RE_FISA_INIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_GSI_002_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GSI_002_TEV()

#define POST_RE_GSI_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_GSI_001_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_GSI_001_MSE()

#define POST_RE_GSI_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_013_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_013_DRE()

#define POST_RE_INMDLT_013_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_043_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_043_MSE()

#define POST_RE_INMDLT_043_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_027_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_027_TEV()

#define POST_RE_INMDLT_027_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_016_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_016_TEV()

#define POST_RE_INMDLT_016_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_029_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_029_TEV()

#define POST_RE_INMDLT_029_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_022_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_022_TEV()

#define POST_RE_INMDLT_022_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_032_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_032_TEV()

#define POST_RE_INMDLT_032_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_033_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_033_TEV()

#define POST_RE_INMDLT_033_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_035_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_035_MSE()

#define POST_RE_INMDLT_035_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_018_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_018_TEV()

#define POST_RE_INMDLT_018_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_044_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_044_MSE()

#define POST_RE_INMDLT_044_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_045_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_045_MSE()

#define POST_RE_INMDLT_045_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_046_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_046_MSE()

#define POST_RE_INMDLT_046_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_031_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_031_TEV()

#define POST_RE_INMDLT_031_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_028_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_028_TEV()

#define POST_RE_INMDLT_028_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_002_TEV()

#define POST_RE_INMDLT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_010_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_010_TEV()

#define POST_RE_INMDLT_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_015_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_015_DRE()

#define POST_RE_INMDLT_015_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_038_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_038_MSE()

#define POST_RE_INMDLT_038_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_012_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_012_TEV()

#define POST_RE_INMDLT_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_026_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_026_TEV()

#define POST_RE_INMDLT_026_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_006_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_006_TEV()

#define POST_RE_INMDLT_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_041_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_041_MSE()

#define POST_RE_INMDLT_041_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_037_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_037_TEV()

#define POST_RE_INMDLT_037_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_024_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_024_DRE()

#define POST_RE_INMDLT_024_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_014_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_014_TEV()

#define POST_RE_INMDLT_014_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_037_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_037_MSE()

#define POST_RE_INMDLT_037_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_039_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_039_MSE()

#define POST_RE_INMDLT_039_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_034_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_034_TEV()

#define POST_RE_INMDLT_034_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_042_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_042_MSE()

#define POST_RE_INMDLT_042_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_004_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_004_TEV()

#define POST_RE_INMDLT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_020_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_020_TEV()

#define POST_RE_INMDLT_020_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_040_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_040_MSE()

#define POST_RE_INMDLT_040_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_008_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_008_TEV()

#define POST_RE_INMDLT_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_036_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_036_MSE()

#define POST_RE_INMDLT_036_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_047_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_047_MSE()

#define POST_RE_INMDLT_047_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_001_MSE()

#define POST_RE_INMDLT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_005_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_005_TEV()

#define POST_RE_INTHMDLT_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_004_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_004_TEV()

#define POST_RE_INTHMDLT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_006_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_006_TEV()

#define POST_RE_INTHMDLT_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_008_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_008_TEV()

#define POST_RE_INTHMDLT_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_007_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_007_TEV()

#define POST_RE_INTHMDLT_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_002_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_002_TEV()

#define POST_RE_INTHMDLT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InThMdlT_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INTHMDLT_001_MSE()

#define POST_RE_INTHMDLT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_005_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_005_TEV()

#define POST_RE_MPM_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvm                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVM()

#define POST_RE_MPM_AFTSNVM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_RstStart                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_RSTSTART()

#define POST_RE_MPM_RSTSTART()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvmChkRead                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVMCHKREAD()

#define POST_RE_MPM_AFTSNVMCHKREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_RstRqResults                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_RSTRQRESULTS()

#define POST_RE_MPM_RSTRQRESULTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvmWrite                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVMWRITE()

#define POST_RE_MPM_AFTSNVMWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_007_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_007_TEV()

#define POST_RE_MPM_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_004_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_004_TEV()

#define POST_RE_MPM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvmRDL                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVMRDL()

#define POST_RE_MPM_AFTSNVMRDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_003_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_003_TEV()

#define POST_RE_MPM_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvmRead                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVMREAD()

#define POST_RE_MPM_AFTSNVMREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_002_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_002_TEV()

#define POST_RE_MPM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftrsInit                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTRSINIT()

#define POST_RE_MPM_AFTRSINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsNvmChkWrite                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSNVMCHKWRITE()

#define POST_RE_MPM_AFTSNVMCHKWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_006_DRE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_006_DRE()

#define POST_RE_MPM_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsSesChgInd                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSSESCHGIND()

#define POST_RE_MPM_AFTSSESCHGIND()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_001_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_001_MSE()

#define POST_RE_MPM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_MPM_AftsGetSesChgPerm               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_MPM_AFTSGETSESCHGPERM()

#define POST_RE_MPM_AFTSGETSESCHGPERM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_002_TEV()

#define POST_RE_OILSYS_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OilSys_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OILSYS_001_MSE()

#define POST_RE_OILSYS_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_CoCha                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_COCHA()

#define POST_RE_TQSYS_SDL10MS_COCHA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFilFast_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFILFAST_001_MSE()

#define POST_RE_PFILFAST_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_tqEfcFil              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQEFCFIL()

#define POST_RE_TQSYS_SDL10MS_TQEFCFIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_CoChaTqSlow           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_COCHATQSLOW()

#define POST_RE_TQSYS_SDL10MS_COCHATQSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_EfcAirFil             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_EFCAIRFIL()

#define POST_RE_TQSYS_SDL10MS_EFCAIRFIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PFilSlow_008_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PFILSLOW_008_MSE()

#define POST_RE_PFILSLOW_008_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PnmAct_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PNMACT_001_MSE()

#define POST_RE_PNMACT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_PnmAct_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PNMACT_002_TEV()

#define POST_RE_PNMACT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_AftsNvramRead_1            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_AFTSNVRAMREAD_1()

#define POST_RE_PRODELEM_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_004_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_004_TEV()

#define POST_RE_PRODELEM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_AftsNvramWrite_1           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_AFTSNVRAMWRITE_1()

#define POST_RE_PRODELEM_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_002_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_002_TEV()

#define POST_RE_PRODELEM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_AftsNvramReset_1           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_AFTSNVRAMRESET_1()

#define POST_RE_PRODELEM_AFTSNVRAMRESET_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_001_MSE()

#define POST_RE_PRODELEM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_006_TEV                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_006_TEV()

#define POST_RE_PRODELEM_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_005_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_005_MSE()

#define POST_RE_PRODELEM_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_003_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_003_MSE()

#define POST_RE_PRODELEM_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_003_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_003_MSE()

#define POST_RE_PRODELENG_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_007_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_007_MSE()

#define POST_RE_PRODELENG_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_001_MSE()

#define POST_RE_PRODELENG_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_005_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_005_MSE()

#define POST_RE_PRODELENG_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_AftsNvramRead_1           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_AFTSNVRAMREAD_1()

#define POST_RE_PRODELENG_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_015_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_015_MSE()

#define POST_RE_PRODELENG_015_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_006_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_006_TEV()

#define POST_RE_PRODELENG_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_008_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_008_TEV()

#define POST_RE_PRODELENG_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_011_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_011_MSE()

#define POST_RE_PRODELENG_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_016_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_016_TEV()

#define POST_RE_PRODELENG_016_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_013_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_013_MSE()

#define POST_RE_PRODELENG_013_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_002_TEV()

#define POST_RE_PRODELENG_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_010_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_010_TEV()

#define POST_RE_PRODELENG_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_012_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_012_TEV()

#define POST_RE_PRODELENG_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_014_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_014_TEV()

#define POST_RE_PRODELENG_014_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_009_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_009_MSE()

#define POST_RE_PRODELENG_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_AftsNvramWrite_1          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_AFTSNVRAMWRITE_1()

#define POST_RE_PRODELENG_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEng_004_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELENG_004_TEV()

#define POST_RE_PRODELENG_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_RCD_002_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_RCD_002_TEV()

#define POST_RE_RCD_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_RCD_001_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_RCD_001_MSE()

#define POST_RE_RCD_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_002_TEV                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_002_TEV()

#define POST_RE_STOPSTRTEM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_AftsNvramWrite_1         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_AFTSNVRAMWRITE_1()

#define POST_RE_STOPSTRTEM_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_AftsNvramRead_1          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_AFTSNVRAMREAD_1()

#define POST_RE_STOPSTRTEM_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_004_TEV                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_004_TEV()

#define POST_RE_STOPSTRTEM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_AftsNvramReset_1         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_AFTSNVRAMRESET_1()

#define POST_RE_STOPSTRTEM_AFTSNVRAMRESET_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_006_TEV                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_006_TEV()

#define POST_RE_STOPSTRTEM_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_001_MSE                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_001_MSE()

#define POST_RE_STOPSTRTEM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_005_MSE                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_005_MSE()

#define POST_RE_STOPSTRTEM_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_003_MSE                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_003_MSE()

#define POST_RE_STOPSTRTEM_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_004_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_004_TEV()

#define POST_RE_STOPSTRTENG_004_TEV()\
{\
  Boolean bValue;\
  Rte_Read_R_CoPTSt_bDgoSftyORngAT_CoPTSt_bDgoSftyORngAT(&bValue);\
  GDGAR_vidGdu(GD_DFT_SFTYORNGAT,bValue,1,0);\
  Rte_Read_R_CoPTSt_bDgoSftyORngAMT_CoPTSt_bDgoSftyORngAMT(&bValue);\
  GDGAR_vidGdu(GD_DFT_SFTYORNGAMT,bValue,1,0);\
}

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_006_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_006_TEV()

#define POST_RE_STOPSTRTENG_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_005_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_005_MSE()

#define POST_RE_STOPSTRTENG_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_009_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_009_MSE()

#define POST_RE_STOPSTRTENG_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_011_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_011_MSE()

#define POST_RE_STOPSTRTENG_011_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_023_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_023_MSE()

#define POST_RE_STOPSTRTENG_023_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_017_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_017_MSE()

#define POST_RE_STOPSTRTENG_017_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_007_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_007_MSE()

#define POST_RE_STOPSTRTENG_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_014_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_014_TEV()

#define POST_RE_STOPSTRTENG_014_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_022_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_022_TEV()

#define POST_RE_STOPSTRTENG_022_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_020_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_020_TEV()

#define POST_RE_STOPSTRTENG_020_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_021_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_021_MSE()

#define POST_RE_STOPSTRTENG_021_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_010_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_010_TEV()

#define POST_RE_STOPSTRTENG_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_018_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_018_TEV()

#define POST_RE_STOPSTRTENG_018_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_016_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_016_TEV()

#define POST_RE_STOPSTRTENG_016_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_008_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_008_TEV()

#define POST_RE_STOPSTRTENG_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_013_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_013_MSE()

#define POST_RE_STOPSTRTENG_013_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_003_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_003_MSE()

#define POST_RE_STOPSTRTENG_003_MSE()\
{\
  Boolean bValue;\
  Rte_Read_R_CoPTSt_bDgoSftyORngAMT_CoPTSt_bDgoSftyORngAMT(&bValue);\
  GDGAR_vidGdu(GD_DFT_SFTYORNGAMT,bValue,1,0);\
  Rte_Read_R_CoPTSt_bDgoSftyORngAT_CoPTSt_bDgoSftyORngAT(&bValue);\
  GDGAR_vidGdu(GD_DFT_SFTYORNGAT,bValue,1,0);\
}

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_015_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_015_MSE()

#define POST_RE_STOPSTRTENG_015_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_012_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_012_TEV()

#define POST_RE_STOPSTRTENG_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_019_MSE                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_019_MSE()

#define POST_RE_STOPSTRTENG_019_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_024_TEV                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_024_TEV()

#define POST_RE_STOPSTRTENG_024_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_004_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_004_TEV()

#define POST_RE_THMGT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_AftsNvramRead_1               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_AFTSNVRAMREAD_1()

#define POST_RE_THMGT_AFTSNVRAMREAD_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_001_MSE()

#define POST_RE_THMGT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_003_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_003_TEV()

#define POST_RE_THMGT_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_002_TEV()

#define POST_RE_THMGT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_AftsNvramWrite_1              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_AFTSNVRAMWRITE_1()

#define POST_RE_THMGT_AFTSNVRAMWRITE_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThrSpT_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THRSPT_001_MSE()

#define POST_RE_THRSPT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThrSpT_003_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THRSPT_003_TEV()

#define POST_RE_THRSPT_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThrSpT_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THRSPT_002_TEV()

#define POST_RE_THRSPT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_003_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_003_TEV()

#define POST_RE_TPM_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_005_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_005_TEV()

#define POST_RE_TPM_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_002_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_002_TEV()

#define POST_RE_TPM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_004_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_004_TEV()

#define POST_RE_TPM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_008_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_008_TEV()

#define POST_RE_TPM_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_001_MSE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_001_MSE()

#define POST_RE_TPM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_006_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_006_TEV()

#define POST_RE_TPM_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_007_TEV                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_007_TEV()

#define POST_RE_TPM_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_009_DRE                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_009_DRE()

#define POST_RE_TPM_009_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpAccCord          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPACCCORD()

#define POST_RE_TQSYS_SDL10MS_TQCMPACCCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqAC4            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQAC4()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQAC4()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqAC             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQAC()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQAC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqCnv            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQCNV()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQCNV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpEngLoss          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPENGLOSS()

#define POST_RE_TQSYS_SDL10MS_TQCMPENGLOSS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqStg            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQSTG()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQSTG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdpCmp_001_MSE                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADPCMP_001_MSE()

#define POST_RE_TQADPCMP_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpGlbCord          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPGLBCORD()

#define POST_RE_TQSYS_SDL10MS_TQCMPGLBCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqAlt            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQALT()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQALT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqAdp_Sdl10ms_TqAdpLossClc          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQADP_SDL10MS_TQADPLOSSCLC()

#define POST_RE_TQADP_SDL10MS_TQADPLOSSCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl100ms_TqCmpTAir            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL100MS_TQCMPTAIR()

#define POST_RE_TQSYS_SDL100MS_TQCMPTAIR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_TqCmpTqAC3            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_TQCMPTQAC3()

#define POST_RE_TQSYS_SDL10MS_TQCMPTQAC3()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_007_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_007_TEV()

#define POST_RE_TQDEM_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_001_MSE()

#define POST_RE_TQDEM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_006_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_006_TEV()

#define POST_RE_TQDEM_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_002_TEV()

#define POST_RE_TQDEM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_008_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_008_TEV()

#define POST_RE_TQDEM_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_005_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_005_TEV()

#define POST_RE_TQDEM_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_004_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_004_TEV()

#define POST_RE_TQDEM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqDem_003_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQDEM_003_TEV()

#define POST_RE_TQDEM_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqEM_006_DRE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQEM_006_DRE()

#define POST_RE_TQEM_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqEM_004_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQEM_004_TEV()

#define POST_RE_TQEM_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqEM_002_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQEM_002_TEV()

#define POST_RE_TQEM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqEM_001_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQEM_001_MSE()

#define POST_RE_TQEM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_008_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_008_DRE()

#define POST_RE_TQTREAT_008_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_002_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_002_TEV()

#define POST_RE_TQTREAT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_005_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_005_MSE()

#define POST_RE_TQTREAT_005_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_007_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_007_MSE()

#define POST_RE_TQTREAT_007_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_004_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_004_TEV()

#define POST_RE_TQTREAT_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_010_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_010_TEV()

#define POST_RE_TQTREAT_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_003_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_003_MSE()

#define POST_RE_TQTREAT_003_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_009_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_009_MSE()

#define POST_RE_TQTREAT_009_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_001_MSE()

#define POST_RE_TQTREAT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_006_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_006_DRE()

#define POST_RE_TQTREAT_006_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_018_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_018_DRE()

#define POST_RE_TRABVX_018_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_001_MSE()

#define POST_RE_TRABVX_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_016_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_016_DRE()

#define POST_RE_TRABVX_016_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_028_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_028_TEV()

#define POST_RE_TRABVX_028_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_032_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_032_TEV()

#define POST_RE_TRABVX_032_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_020_DRE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_020_DRE()

#define POST_RE_TRABVX_020_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_030_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_030_TEV()

#define POST_RE_TRABVX_030_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActGsl_004_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTGSL_004_TEV()

#define POST_RE_TRBACTGSL_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActGsl_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTGSL_001_MSE()

#define POST_RE_TRBACTGSL_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActGsl_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTGSL_002_TEV()

#define POST_RE_TRBACTGSL_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActGsl_003_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTGSL_003_TEV()

#define POST_RE_TRBACTGSL_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActMgt_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTMGT_001_MSE()

#define POST_RE_TRBACTMGT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActMgt_003_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTMGT_003_TEV()

#define POST_RE_TRBACTMGT_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActMgt_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTMGT_002_TEV()

#define POST_RE_TRBACTMGT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_005_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_005_TEV()

#define POST_RE_TRBACTSYS_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvm                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVM()

#define POST_RE_TRBACTSYS_AFTSNVM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_RstRqResults              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_RSTRQRESULTS()

#define POST_RE_TRBACTSYS_RSTRQRESULTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvmChkWrite           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVMCHKWRITE()

#define POST_RE_TRBACTSYS_AFTSNVMCHKWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvmChkRead            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVMCHKREAD()

#define POST_RE_TRBACTSYS_AFTSNVMCHKREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvmRDL                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVMRDL()

#define POST_RE_TRBACTSYS_AFTSNVMRDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_001_MSE                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_001_MSE()

#define POST_RE_TRBACTSYS_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_003_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_003_TEV()

#define POST_RE_TRBACTSYS_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsSesChgInd             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSSESCHGIND()

#define POST_RE_TRBACTSYS_AFTSSESCHGIND()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_RstStart                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_RSTSTART()

#define POST_RE_TRBACTSYS_RSTSTART()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvmRead               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVMREAD()

#define POST_RE_TRBACTSYS_AFTSNVMREAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_004_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_004_TEV()

#define POST_RE_TRBACTSYS_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsNvmWrite              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSNVMWRITE()

#define POST_RE_TRBACTSYS_AFTSNVMWRITE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftsGetSesChgPerm         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTSGETSESCHGPERM()

#define POST_RE_TRBACTSYS_AFTSGETSESCHGPERM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_AftrsInit                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_AFTRSINIT()

#define POST_RE_TRBACTSYS_AFTRSINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TrbActSys_002_TEV                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRBACTSYS_002_TEV()

#define POST_RE_TRBACTSYS_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_008_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_008_TEV()

#define POST_RE_USTHRMT_008_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_010_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_010_TEV()

#define POST_RE_USTHRMT_010_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_006_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_006_TEV()

#define POST_RE_USTHRMT_006_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_002_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_002_TEV()

#define POST_RE_USTHRMT_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_004_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_004_MSE()

#define POST_RE_USTHRMT_004_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_001_MSE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_001_MSE()

#define POST_RE_USTHRMT_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_011_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_011_TEV()

#define POST_RE_USTHRMT_011_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_009_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_009_DRE()

#define POST_RE_USTHRMT_009_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_008_DRE                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_008_DRE()

#define POST_RE_USTHRMT_008_DRE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_005_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_005_TEV()

#define POST_RE_USTHRMT_005_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_007_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_007_TEV()

#define POST_RE_USTHRMT_007_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_UsThrMT_012_TEV                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_USTHRMT_012_TEV()

#define POST_RE_USTHRMT_012_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCo_002_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCO_002_TEV()

#define POST_RE_VSCO_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSCo_001_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSCO_001_MSE()

#define POST_RE_VSCO_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSInfo_002_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSINFO_002_TEV()

#define POST_RE_VSINFO_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSInfo_003_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSINFO_003_TEV()

#define POST_RE_VSINFO_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSInfo_001_MSE                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSINFO_001_MSE()

#define POST_RE_VSINFO_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSInfo_004_TEV                      */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSINFO_004_TEV()

#define POST_RE_VSINFO_004_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSLim_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSLIM_001_MSE()

#define POST_RE_VSLIM_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSLim_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSLIM_002_TEV()

#define POST_RE_VSLIM_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSMax_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSMAX_002_TEV()

#define POST_RE_VSMAX_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSMax_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSMAX_001_MSE()

#define POST_RE_VSMAX_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSReg_001_MSE                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSREG_001_MSE()

#define POST_RE_VSREG_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSReg_002_TEV                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSREG_002_TEV()

#define POST_RE_VSREG_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSSp_002_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSSP_002_TEV()

#define POST_RE_VSSP_002_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSSp_003_TEV                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSSP_003_TEV()

#define POST_RE_VSSP_003_TEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSSp_004_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSSP_004_MSE()

#define POST_RE_VSSP_004_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VSSp_001_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VSSP_001_MSE()

#define POST_RE_VSSP_001_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlFast_CkDiagSts              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLFAST_CKDIAGSTS()

#define POST_RE_SYNC_SDLFAST_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkSnOf_CkDiagSts            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKSNOF_CKDIAGSTS()

#define POST_RE_SYNC_EVECKSNOF_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveStTR_CkDiagSts              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVESTTR_CKDIAGSTS()

#define POST_RE_SYNC_EVESTTR_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlMid_CkDiagSts               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLMID_CKDIAGSTS()

#define POST_RE_SYNC_SDLMID_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveRst_CkDiagSts               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVERST_CKDIAGSTS()

#define POST_RE_SYNC_EVERST_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkSnOn_CkDiagSts            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKSNON_CKDIAGSTS()

#define POST_RE_SYNC_EVECKSNON_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveRTCr_CkDiagSts              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVERTCR_CKDIAGSTS()

#define POST_RE_SYNC_EVERTCR_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCrTSt_CkDiagSts             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECRTST_CKDIAGSTS()

#define POST_RE_SYNC_EVECRTST_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveStTCr_CkDiagSts             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVESTTCR_CKDIAGSTS()

#define POST_RE_SYNC_EVESTTCR_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveKOn_CkDiagSts               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVEKON_CKDIAGSTS()

#define POST_RE_SYNC_EVEKON_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_SdlSlow_CkDiagSts              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_SDLSLOW_CKDIAGSTS()

#define POST_RE_SYNC_SDLSLOW_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkLTo_CkDiagSts             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKLTO_CKDIAGSTS()

#define POST_RE_SYNC_EVECKLTO_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_Sync_EveCkOf_CkDiagSts              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_SYNC_EVECKOF_CKDIAGSTS()

#define POST_RE_SYNC_EVECKOF_CKDIAGSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoT_SdlSlow_AcqCoT                     */
/*---------------------------------------------------------------------------*/
#define PRE_COT_SDLSLOW_ACQCOT()

#define POST_COT_SDLSLOW_ACQCOT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoT_SdlSlow_TrbWaPmp                   */
/*---------------------------------------------------------------------------*/
#define PRE_COT_SDLSLOW_TRBWAPMP()

#define POST_COT_SDLSLOW_TRBWAPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlSlow_FarCtlMgr               */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLSLOW_FARCTLMGR()

#define POST_INJCTL_SDLSLOW_FARCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_SdlSlow_tFuM                    */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_SDLSLOW_TFUM()

#define POST_FUSYSM_SDLSLOW_TFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_SdlSlow_tFuMIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_SDLSLOW_TFUMIF()

#define POST_FUSYSM_SDLSLOW_TFUMIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlMid_InCmd                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLMID_INCMD()

#define POST_VLVACT_SDLMID_INCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlMid_ExCmd                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLMID_EXCMD()

#define POST_VLVACT_SDLMID_EXCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlSlow_DiagMem                  */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLSLOW_DIAGMEM()

#define POST_ECUST_SDLSLOW_DIAGMEM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CONFIGLIN_vidMngSch_1S                 */
/*---------------------------------------------------------------------------*/
#define PRE_CONFIGLIN_VIDMNGSCH_1S()

#define POST_CONFIGLIN_VIDMNGSCH_1S()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlSlow_UpLsAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLSLOW_UPLSACQ()

#define POST_SENO2US_SDLSLOW_UPLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlSlow_UsMgr                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLSLOW_USMGR()

#define POST_HEATSENO2_SDLSLOW_USMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_KnkAcqFiltFst          */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_KNKACQFILTFST()

#define POST_KNKTREAT_EVEKNK_KNKACQFILTFST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkInstNoiseRbl        */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKINSTNOISERBL()

#define POST_KNKTREAT_EVERBL_KNKINSTNOISERBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkDetRbl              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKDETRBL()

#define POST_KNKTREAT_EVERBL_KNKDETRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkMvNoiseAdpRbl       */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKMVNOISEADPRBL()

#define POST_KNKTREAT_EVERBL_KNKMVNOISEADPRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_KnkDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_KNKDIAG()

#define POST_KNKTREAT_EVEKNK_KNKDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_InstNoise              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_INSTNOISE()

#define POST_KNKTREAT_EVEKNK_INSTNOISE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_KnkDet                 */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_KNKDET()

#define POST_KNKTREAT_EVEKNK_KNKDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_NoiseAdp               */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_NOISEADP()

#define POST_KNKTREAT_EVEKNK_NOISEADP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_ShdDet                 */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_SHDDET()

#define POST_KNKTREAT_EVEKNK_SHDDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_KnkAcqLst              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_KNKACQLST()

#define POST_KNKTREAT_EVEKNK_KNKACQLST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkRblAcqLst           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKRBLACQLST()

#define POST_KNKTREAT_EVERBL_KNKRBLACQLST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_KnkAcqFiltLst          */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_KNKACQFILTLST()

#define POST_KNKTREAT_EVEKNK_KNKACQFILTLST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkMgrCorRbl           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKMGRCORRBL()

#define POST_KNKTREAT_EVERBL_KNKMGRCORRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveKnk_BenchMod               */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEKNK_BENCHMOD()

#define POST_KNKTREAT_EVEKNK_BENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_RblDetBench            */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_RBLDETBENCH()

#define POST_KNKTREAT_EVERBL_RBLDETBENCH()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRbl_KnkMgrCorRblIf         */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERBL_KNKMGRCORRBLIF()

#define POST_KNKTREAT_EVERBL_KNKMGRCORRBLIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrsCtl_SdlSlow_CrsCtlInTreatIf         */
/*---------------------------------------------------------------------------*/
#define PRE_CRSCTL_SDLSLOW_CRSCTLINTREATIF()

#define POST_CRSCTL_SDLSLOW_CRSCTLINTREATIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrsCtl_SdlSlow_CrsCtlBsiTreat          */
/*---------------------------------------------------------------------------*/
#define PRE_CRSCTL_SDLSLOW_CRSCTLBSITREAT()

#define POST_CRSCTL_SDLSLOW_CRSCTLBSITREAT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrsCtl_SdlFast_CrsCtlInTreatIf         */
/*---------------------------------------------------------------------------*/
#define PRE_CRSCTL_SDLFAST_CRSCTLINTREATIF()

#define POST_CRSCTL_SDLFAST_CRSCTLINTREATIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VSCTL_SdlMid_LstCrsCtlDeacCaus         */
/*---------------------------------------------------------------------------*/
#define PRE_VSCTL_SDLMID_LSTCRSCTLDEACCAUS()

#define POST_VSCTL_SDLMID_LSTCRSCTLDEACCAUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrsCtl_SdlFast_CrsCtlOutTreat          */
/*---------------------------------------------------------------------------*/
#define PRE_CRSCTL_SDLFAST_CRSCTLOUTTREAT()

#define POST_CRSCTL_SDLFAST_CRSCTLOUTTREAT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrsCtl_SdlFast_CrsCtlOutTreatIf        */
/*---------------------------------------------------------------------------*/
#define PRE_CRSCTL_SDLFAST_CRSCTLOUTTREATIF()

#define POST_CRSCTL_SDLFAST_CRSCTLOUTTREATIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl40ms_ProtManClu               */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL40MS_PROTMANCLU()

#define POST_TQSYS_SDL40MS_PROTMANCLU()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Gear_SdlMid_FctDiagRvsSt               */
/*---------------------------------------------------------------------------*/
#define PRE_GEAR_SDLMID_FCTDIAGRVSST()

#define POST_GEAR_SDLMID_FCTDIAGRVSST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TWCMgt_SdlFast_TWCMgt                  */
/*---------------------------------------------------------------------------*/
#define PRE_TWCMGT_SDLFAST_TWCMGT()

#define POST_TWCMGT_SDLFAST_TWCMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TWCMgt_SdlFast_TWCMgtIf                */
/*---------------------------------------------------------------------------*/
#define PRE_TWCMGT_SDLFAST_TWCMGTIF()

#define POST_TWCMGT_SDLFAST_TWCMGTIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlMid_DiagMem                   */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLMID_DIAGMEM()

#define POST_ECUST_SDLMID_DIAGMEM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlMid_Wku                       */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLMID_WKU()

#define POST_ECUST_SDLMID_WKU()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlMid_EcuMng                    */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLMID_ECUMNG()

#define POST_ECUST_SDLMID_ECUMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlMid_EcuMngIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLMID_ECUMNGIF()

#define POST_ECUST_SDLMID_ECUMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_SdlMid_ActrTstFuTnkPmp           */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_SDLMID_ACTRTSTFUTNKPMP()

#define POST_FUPMP_SDLMID_ACTRTSTFUTNKPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_SdlMid_Mng                       */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_SDLMID_MNG()

#define POST_FUPMP_SDLMID_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_SdlFast_CrashVeh                */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_SDLFAST_CRASHVEH()

#define POST_RLYPWR_SDLFAST_CRASHVEH()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Rly_SdlFast_ActTstPwrRly               */
/*---------------------------------------------------------------------------*/
#define PRE_RLY_SDLFAST_ACTTSTPWRRLY()

#define POST_RLY_SDLFAST_ACTTSTPWRRLY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_SdlFast_Mng                     */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_SDLFAST_MNG()

#define POST_RLYPWR_SDLFAST_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrlRly_SdlMid_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRLRLY_SDLMID_IFCMDDIAG()

#define POST_PWRLRLY_SDLMID_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrRly_SdlMid_IfCmdDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_PWRRLY_SDLMID_IFCMDDIAG()

#define POST_PWRRLY_SDLMID_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_SdlMid_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_SDLMID_MNG()

#define POST_RLYPWR_SDLMID_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlMid_UpLsAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLMID_UPLSACQ()

#define POST_SENO2US_SDLMID_UPLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlLow_DsLsAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLLOW_DSLSACQ()

#define POST_SENO2DS_SDLLOW_DSLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirSys_SdlMid_InAirflowDiag            */
/*---------------------------------------------------------------------------*/
#define PRE_AIRSYS_SDLMID_INAIRFLOWDIAG()

#define POST_AIRSYS_SDLMID_INAIRFLOWDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_SpgPresSp               */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_SPGPRESSP()

#define POST_AIRPRES_SDLMID_SPGPRESSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_InMnfPresDiag           */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_INMNFPRESDIAG()

#define POST_AIRPRES_SDLMID_INMNFPRESDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_FctDiagTrbPres          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_FCTDIAGTRBPRES()

#define POST_AIRPRES_SDLMID_FCTDIAGTRBPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlSlow_WgActrTest                  */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLSLOW_WGACTRTEST()

#define POST_WG_SDLSLOW_WGACTRTEST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlvAct_SdlMid_DmpVlvOplCmd          */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLVACT_SDLMID_DMPVLVOPLCMD()

#define POST_DMPVLVACT_SDLMID_DMPVLVOPLCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfWinAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFWINACQ()

#define POST_MISF_EVEMISF_MISFWINACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDiagStabCdn           */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDIAGSTABCDN()

#define POST_MISF_EVEMISF_MISFDIAGSTABCDN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDftLrn                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDFTLRN()

#define POST_MISF_EVEMISF_MISFDFTLRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfWinAdp                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFWINADP()

#define POST_MISF_EVEMISF_MISFWINADP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDet                   */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDET()

#define POST_MISF_EVEMISF_MISFDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDetIdle               */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDETIDLE()

#define POST_MISF_EVEMISF_MISFDETIDLE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDetCfm                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDETCFM()

#define POST_MISF_EVEMISF_MISFDETCFM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfSucDetIdle            */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFSUCDETIDLE()

#define POST_MISF_EVEMISF_MISFSUCDETIDLE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfSucDet                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFSUCDET()

#define POST_MISF_EVEMISF_MISFSUCDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfRoughnsRoad           */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFROUGHNSROAD()

#define POST_MISF_EVEMISF_MISFROUGHNSROAD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfFaiCtr                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFFAICTR()

#define POST_MISF_EVEMISF_MISFFAICTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_AvrMisfCnt                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_AVRMISFCNT()

#define POST_MISF_EVEMISF_AVRMISFCNT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveMisf_MisfDetCfmIf              */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEMISF_MISFDETCFMIF()

#define POST_MISF_EVEMISF_MISFDETCFMIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCam_ExAcq                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCAM_EXACQ()

#define POST_VLVACT_EVEEXCAM_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCmToo_ExAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCMTOO_EXACQ()

#define POST_VLVACT_EVEEXCMTOO_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCmToo_ExEndStop            */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCMTOO_EXENDSTOP()

#define POST_VLVACT_EVEEXCMTOO_EXENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCmToo_ExEstim              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCMTOO_EXESTIM()

#define POST_VLVACT_EVEEXCMTOO_EXESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCmToo_ExIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCMTOO_EXIF()

#define POST_VLVACT_EVEEXCMTOO_EXIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveExCmToo_ExServo              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEEXCMTOO_EXSERVO()

#define POST_VLVACT_EVEEXCMTOO_EXSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveExCmToo_ExCmSts                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEEXCMTOO_EXCMSTS()

#define POST_SYNC_EVEEXCMTOO_EXCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SAIMMO_vidSdlFast                      */
/*---------------------------------------------------------------------------*/
#define PRE_SAIMMO_VIDSDLFAST()

#define POST_SAIMMO_VIDSDLFAST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_CtrlCfg                     */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_CTRLCFG()

#define POST_CF_SDLFAST_CTRLCFG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_CtrlCfgIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_CTRLCFGIF()

#define POST_CF_SDLFAST_CTRLCFGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CONFIGLIN_vidMngSch_10MS               */
/*---------------------------------------------------------------------------*/
#define PRE_CONFIGLIN_VIDMNGSCH_10MS()

#define POST_CONFIGLIN_VIDMNGSCH_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Gear_SdlFast_StrtLockAcq               */
/*---------------------------------------------------------------------------*/
#define PRE_GEAR_SDLFAST_STRTLOCKACQ()

#define POST_GEAR_SDLFAST_STRTLOCKACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Gear_SdlFast_NeutPosnAcq               */
/*---------------------------------------------------------------------------*/
#define PRE_GEAR_SDLFAST_NEUTPOSNACQ()

#define POST_GEAR_SDLFAST_NEUTPOSNACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlFast_AcqWkuSig                */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLFAST_ACQWKUSIG()

#define POST_ECUST_SDLFAST_ACQWKUSIG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_SdlFast_Wku                      */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_SDLFAST_WKU()

#define POST_ECUST_SDLFAST_WKU()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlFast_GJDD                        */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLFAST_GJDD()

#define POST_GD_SDLFAST_GJDD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IUPRGENDEN_vidMngEveSdlFast            */
/*---------------------------------------------------------------------------*/
#define PRE_IUPRGENDEN_VIDMNGEVESDLFAST()

#define POST_IUPRGENDEN_VIDMNGEVESDLFAST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlFast_GJDDIf                      */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLFAST_GJDDIF()

#define POST_GD_SDLFAST_GJDDIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlFast_AcqVehSpdSen            */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLFAST_ACQVEHSPDSEN()

#define POST_VEHSPD_SDLFAST_ACQVEHSPDSEN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlFast_VehMng                  */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLFAST_VEHMNG()

#define POST_VEHSPD_SDLFAST_VEHMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlFast_SpdVehSecu             */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLFAST_SPDVEHSECU()

#define POST_SFTYMGT_SDLFAST_SPDVEHSECU()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlFast_VehMngIf                */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLFAST_VEHMNGIF()

#define POST_VEHSPD_SDLFAST_VEHMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_SdlFast_AcqnCluPed                 */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_SDLFAST_ACQNCLUPED()

#define POST_CLU_SDLFAST_ACQNCLUPED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_SdlFast_CluPedFreqAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_SDLFAST_CLUPEDFREQACQ()

#define POST_CLU_SDLFAST_CLUPEDFREQACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_SdlFast_BattVoltAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDLFAST_BATTVOLTACQ()

#define POST_PWR_SDLFAST_BATTVOLTACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable BoostReq_SdlFast_BattVoltReq           */
/*---------------------------------------------------------------------------*/
#define PRE_BOOSTREQ_SDLFAST_BATTVOLTREQ()

#define POST_BOOSTREQ_SDLFAST_BATTVOLTREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Volt_SdlFast_IgVoltAdj                 */
/*---------------------------------------------------------------------------*/
#define PRE_VOLT_SDLFAST_IGVOLTADJ()

#define POST_VOLT_SDLFAST_IGVOLTADJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IfEngReq_Sdl10ms_Cord                  */
/*---------------------------------------------------------------------------*/
#define PRE_IFENGREQ_SDL10MS_CORD()

#define POST_IFENGREQ_SDL10MS_CORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_SdlFast_BattVoltAcqIf              */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDLFAST_BATTVOLTACQIF()

#define POST_PWR_SDLFAST_BATTVOLTACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlFast_OilPropPresAcq             */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLFAST_OILPROPPRESACQ()

#define POST_OIL_SDLFAST_OILPROPPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlMid_OilPresAcq                  */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLMID_OILPRESACQ()

#define POST_OIL_SDLMID_OILPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlFast_OilLvlAcq                  */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLFAST_OILLVLACQ()

#define POST_OIL_SDLFAST_OILLVLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlMid_ActrTstCtlPmp               */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLMID_ACTRTSTCTLPMP()

#define POST_OIL_SDLMID_ACTRTSTCTLPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OilSysHw_SdlFast_CtlPmpReq             */
/*---------------------------------------------------------------------------*/
#define PRE_OILSYSHW_SDLFAST_CTLPMPREQ()

#define POST_OILSYSHW_SDLFAST_CTLPMPREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlMid_ActrTstBlowBy               */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLMID_ACTRTSTBLOWBY()

#define POST_OIL_SDLMID_ACTRTSTBLOWBY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlMid_ActrTstCtlPmpIf             */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLMID_ACTRTSTCTLPMPIF()

#define POST_OIL_SDLMID_ACTRTSTCTLPMPIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuAcq_SdlFast_PFuAcq                   */
/*---------------------------------------------------------------------------*/
#define PRE_FUACQ_SDLFAST_PFUACQ()

#define POST_FUACQ_SDLFAST_PFUACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuAcq_SdlFast_PFuAcqIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_FUACQ_SDLFAST_PFUACQIF()

#define POST_FUACQ_SDLFAST_PFUACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlFast_UpLsAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLFAST_UPLSACQ()

#define POST_SENO2US_SDLFAST_UPLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlFast_PerDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLFAST_PERDIAG()

#define POST_SENO2US_SDLFAST_PERDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlFast_UsPlaus                */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLFAST_USPLAUS()

#define POST_SENO2US_SDLFAST_USPLAUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlFast_SenO2DlyGenr           */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLFAST_SENO2DLYGENR()

#define POST_SENO2US_SDLFAST_SENO2DLYGENR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlMid_DsLsAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLMID_DSLSACQ()

#define POST_SENO2DS_SDLMID_DSLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlMid_SigGrdDiag              */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLMID_SIGGRDDIAG()

#define POST_SENO2DS_SDLMID_SIGGRDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlMid_DsPlaus                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLMID_DSPLAUS()

#define POST_SENO2DS_SDLMID_DSPLAUS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_SdlFast_UpLsAcqIf              */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_SDLFAST_UPLSACQIF()

#define POST_SENO2US_SDLFAST_UPLSACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlMid_DsPlausIf               */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLMID_DSPLAUSIF()

#define POST_SENO2DS_SDLMID_DSPLAUSIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngClu_1                */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGCLU_1()

#define POST_CF_SDLFAST_FLOWMNGCLU_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngBrkAsi               */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGBRKASI()

#define POST_CF_SDLFAST_FLOWMNGBRKASI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngBatt                 */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGBATT()

#define POST_CF_SDLFAST_FLOWMNGBATT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngAlt                  */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGALT()

#define POST_CF_SDLFAST_FLOWMNGALT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngPwt                  */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGPWT()

#define POST_CF_SDLFAST_FLOWMNGPWT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngBrk                  */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGBRK()

#define POST_CF_SDLFAST_FLOWMNGBRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngPedPrss              */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGPEDPRSS()

#define POST_CF_SDLFAST_FLOWMNGPEDPRSS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngGear                 */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGGEAR()

#define POST_CF_SDLFAST_FLOWMNGGEAR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngOilPres              */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGOILPRES()

#define POST_CF_SDLFAST_FLOWMNGOILPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGIF()

#define POST_CF_SDLFAST_FLOWMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlMid_DiagBrkPed                  */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLMID_DIAGBRKPED()

#define POST_BRK_SDLMID_DIAGBRKPED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlMid_MngBrkPed                   */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLMID_MNGBRKPED()

#define POST_BRK_SDLMID_MNGBRKPED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlMid_DiagBrkPedNoBVH2p           */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLMID_DIAGBRKPEDNOBVH2P()

#define POST_BRK_SDLMID_DIAGBRKPEDNOBVH2P()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlMid_BrkPedBVH2p                 */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLMID_BRKPEDBVH2P()

#define POST_BRK_SDLMID_BRKPEDBVH2P()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_AcqPosn                   */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_ACQPOSN()

#define POST_ACCP_SDLFAST_ACQPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_AccPMngModSec             */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_ACCPMNGMODSEC()

#define POST_ACCP_SDLFAST_ACCPMNGMODSEC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_Clc                       */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_CLC()

#define POST_ACCP_SDLFAST_CLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_SwtAcqDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_SWTACQDIAG()

#define POST_ACCP_SDLFAST_SWTACQDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_Ftm                       */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_FTM()

#define POST_ACCP_SDLFAST_FTM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_MonStuckAccP              */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_MONSTUCKACCP()

#define POST_ACCP_SDLFAST_MONSTUCKACCP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_AccPEM                    */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_ACCPEM()

#define POST_ACCP_SDLFAST_ACCPEM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlFast_StIf                      */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLFAST_STIF()

#define POST_ACCP_SDLFAST_STIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable STT_SdlFast_KeyPushInfo                */
/*---------------------------------------------------------------------------*/
#define PRE_STT_SDLFAST_KEYPUSHINFO()

#define POST_STT_SDLFAST_KEYPUSHINFO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngReqH_SdlFast_EngReqH                */
/*---------------------------------------------------------------------------*/
#define PRE_ENGREQH_SDLFAST_ENGREQH()

#define POST_ENGREQH_SDLFAST_ENGREQH()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_024_TEVIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_024_TEVIF()

#define POST_RE_STOPSTRTENG_024_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CcpDaqListSetEvent_Fast                */
/*---------------------------------------------------------------------------*/
#define PRE_CCPDAQLISTSETEVENT_FAST()

#define POST_CCPDAQLISTSETEVENT_FAST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkOn_CkMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKON_CKMNGIF()

#define POST_SYNC_EVECKON_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkOn_SyncSTT                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKON_SYNCSTT()

#define POST_SYNC_EVECKON_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveCkOn_EngStrtStop              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVECKON_ENGSTRTSTOP()

#define POST_ENGST_EVECKON_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrM_EveClcn_InjrConMdl            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRM_EVECLCN_INJRCONMDL()

#define POST_RE_INJRM_EVECLCN_INJRCONMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrM_EveClcn_InjrOfsMdl            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRM_EVECLCN_INJROFSMDL()

#define POST_RE_INJRM_EVECLCN_INJROFSMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjCrk_EveClcn1_PreInjTi            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJCRK_EVECLCN1_PREINJTI()

#define POST_RE_INJCRK_EVECLCN1_PREINJTI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrRly_EveCkOn_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRRLY_EVECKON_IFCMDDIAG()

#define POST_PWRRLY_EVECKON_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoEs_SdlFast_STTEs                     */
/*---------------------------------------------------------------------------*/
#define PRE_COES_SDLFAST_STTES()

#define POST_COES_SDLFAST_STTES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoPTSt_SdlFast_RStrtSTT                */
/*---------------------------------------------------------------------------*/
#define PRE_COPTST_SDLFAST_RSTRTSTT()

#define POST_COPTST_SDLFAST_RSTRTSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlFast_DgoHalAcqInj               */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLFAST_DGOHALACQINJ()

#define POST_INJ_SDLFAST_DGOHALACQINJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable STT_SdlFast_STTmO2Clc                  */
/*---------------------------------------------------------------------------*/
#define PRE_STT_SDLFAST_STTMO2CLC()

#define POST_STT_SDLFAST_STTMO2CLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_014_TEVIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_014_TEVIF()

#define POST_RE_STOPSTRTENG_014_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_004_TEVIf                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_004_TEVIF()

#define POST_RE_STOPSTRTEM_004_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuAcq_EveSpl_PFuAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_FUACQ_EVESPL_PFUACQ()

#define POST_FUACQ_EVESPL_PFUACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuAcq_EveSpl_PFuAcqIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_FUACQ_EVESPL_PFUACQIF()

#define POST_FUACQ_EVESPL_PFUACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveSpl_InjSysSpCrk              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESPL_INJSYSSPCRK()

#define POST_INJSYS_EVESPL_INJSYSSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveSpl_pFuSp                    */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESPL_PFUSP()

#define POST_INJSYS_EVESPL_PFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveSpl_InjSpMgt                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESPL_INJSPMGT()

#define POST_INJSYS_EVESPL_INJSPMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_EveSpl_agPmpRefPFuM             */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_EVESPL_AGPMPREFPFUM()

#define POST_FUSYSM_EVESPL_AGPMPREFPFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_EveSpl_pFuM                     */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_EVESPL_PFUM()

#define POST_FUSYSM_EVESPL_PFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveSpl_InjrPrmMdl                */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVESPL_INJRPRMMDL()

#define POST_INJRM_EVESPL_INJRPRMMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveSpl_InjrMdl                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVESPL_INJRMDL()

#define POST_INJRM_EVESPL_INJRMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_EveSpl_tiFuSp                  */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_EVESPL_TIFUSP()

#define POST_INJRSYS_EVESPL_TIFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveSpl_InjrMdlIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVESPL_INJRMDLIF()

#define POST_INJRM_EVESPL_INJRMDLIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_FuRailCtlMgr             */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_FURAILCTLMGR()

#define POST_PFUCTL_EVESPL_FURAILCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_HPPmpCtl                 */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_HPPMPCTL()

#define POST_PFUCTL_EVESPL_HPPMPCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_HPPmpVlvCmdLrn           */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_HPPMPVLVCMDLRN()

#define POST_PFUCTL_EVESPL_HPPMPVLVCMDLRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_ActrTstHPPmp             */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_ACTRTSTHPPMP()

#define POST_PFUCTL_EVESPL_ACTRTSTHPPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_HPPmpMdl                 */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_HPPMPMDL()

#define POST_PFUCTL_EVESPL_HPPMPMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_HPPmpFctDiag             */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_HPPMPFCTDIAG()

#define POST_PFUCTL_EVESPL_HPPMPFCTDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveSpl_HPPmpActCmd              */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESPL_HPPMPACTCMD()

#define POST_PFUCTL_EVESPL_HPPMPACTCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Volt_EveSpl_InjVoltAdj                 */
/*---------------------------------------------------------------------------*/
#define PRE_VOLT_EVESPL_INJVOLTADJ()

#define POST_VOLT_EVESPL_INJVOLTADJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveSpl_HPSensDiag                   */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVESPL_HPSENSDIAG()

#define POST_FU_EVESPL_HPSENSDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ExM_SdlFast_InterfExMSC                */
/*---------------------------------------------------------------------------*/
#define PRE_EXM_SDLFAST_INTERFEXMSC()

#define POST_EXM_SDLFAST_INTERFEXMSC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngM_SdlMid_InterfEngMSC               */
/*---------------------------------------------------------------------------*/
#define PRE_ENGM_SDLMID_INTERFENGMSC()

#define POST_ENGM_SDLMID_INTERFENGMSC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngM_SdlMid_InterfUsThrMSC             */
/*---------------------------------------------------------------------------*/
#define PRE_ENGM_SDLMID_INTERFUSTHRMSC()

#define POST_ENGM_SDLMID_INTERFUSTHRMSC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirSys_SdlFast_InterfAirSysSC          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRSYS_SDLFAST_INTERFAIRSYSSC()

#define POST_AIRSYS_SDLFAST_INTERFAIRSYSSC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_SdlFast_ActrTstDV               */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_SDLFAST_ACTRTSTDV()

#define POST_DMPVLV_SDLFAST_ACTRTSTDV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_SdlFast_DmpVlvCmdSpArb          */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_SDLFAST_DMPVLVCMDSPARB()

#define POST_DMPVLV_SDLFAST_DMPVLVCMDSPARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlvAct_SdlFast_DmpVlvCmd            */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLVACT_SDLFAST_DMPVLVCMD()

#define POST_DMPVLVACT_SDLFAST_DMPVLVCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_005_TEVIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_005_TEVIF()

#define POST_RE_AIRSYSAIR_005_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OEMGsl_003_TEVIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OEMGSL_003_TEVIF()

#define POST_RE_OEMGSL_003_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlFast_FctDiagWg                   */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLFAST_FCTDIAGWG()

#define POST_WG_SDLFAST_FCTDIAGWG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlMid_WgCmdOplBenchMod             */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLMID_WGCMDOPLBENCHMOD()

#define POST_WG_SDLMID_WGCMDOPLBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlMid_WgCmdSp                      */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLMID_WGCMDSP()

#define POST_WG_SDLMID_WGCMDSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlMid_WgCmdSpArb                   */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLMID_WGCMDSPARB()

#define POST_WG_SDLMID_WGCMDSPARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Wg_SdlMid_WgcCmd                       */
/*---------------------------------------------------------------------------*/
#define PRE_WG_SDLMID_WGCCMD()

#define POST_WG_SDLMID_WGCCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlFast_KnkAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLFAST_KNKACQ()

#define POST_KNKTREAT_SDLFAST_KNKACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlFast_KnkRblAcq             */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLFAST_KNKRBLACQ()

#define POST_KNKTREAT_SDLFAST_KNKRBLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlFast_KnkAcqFilt            */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLFAST_KNKACQFILT()

#define POST_KNKTREAT_SDLFAST_KNKACQFILT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlFast_KnkDet                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLFAST_KNKDET()

#define POST_KNKTREAT_SDLFAST_KNKDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_SdlFast_KnkAdpCor                */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_SDLFAST_KNKADPCOR()

#define POST_IGLIM_SDLFAST_KNKADPCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_SdlFast_TCoRegKnk                */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_SDLFAST_TCOREGKNK()

#define POST_IGSYS_SDLFAST_TCOREGKNK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CatMon_SdlFast_CatAcvDiagIf            */
/*---------------------------------------------------------------------------*/
#define PRE_CATMON_SDLFAST_CATACVDIAGIF()

#define POST_CATMON_SDLFAST_CATACVDIAGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CatMon_SdlFast_CatAcvDiagIf2           */
/*---------------------------------------------------------------------------*/
#define PRE_CATMON_SDLFAST_CATACVDIAGIF2()

#define POST_CATMON_SDLFAST_CATACVDIAGIF2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FarSp_SdlFast_ActrTstFarSp             */
/*---------------------------------------------------------------------------*/
#define PRE_FARSP_SDLFAST_ACTRTSTFARSP()

#define POST_FARSP_SDLFAST_ACTRTSTFARSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FARSp_022_TEVIf                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FARSP_022_TEVIF()

#define POST_RE_FARSP_022_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Far_SdlFast_FarSpMgr                   */
/*---------------------------------------------------------------------------*/
#define PRE_FAR_SDLFAST_FARSPMGR()

#define POST_FAR_SDLFAST_FARSPMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlFast_FarCtlMgr               */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLFAST_FARCTLMGR()

#define POST_INJCTL_SDLFAST_FARCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlFast_FarCtlUsCtl             */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLFAST_FARCTLUSCTL()

#define POST_INJCTL_SDLFAST_FARCTLUSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlFast_InjFarCtlDsCtl          */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLFAST_INJFARCTLDSCTL()

#define POST_INJCTL_SDLFAST_INJFARCTLDSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlFast_LamClmpd                */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLFAST_LAMCLMPD()

#define POST_INJCTL_SDLFAST_LAMCLMPD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlFast_InjTiCor                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLFAST_INJTICOR()

#define POST_INJ_SDLFAST_INJTICOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlFast_IfAirSysIgSys           */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLFAST_IFAIRSYSIGSYS()

#define POST_INJCTL_SDLFAST_IFAIRSYSIGSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlFast_InjTiCorIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLFAST_INJTICORIF()

#define POST_INJ_SDLFAST_INJTICORIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlFast_FuTiRunIf2                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLFAST_FUTIRUNIF2()

#define POST_INJ_SDLFAST_FUTIRUNIF2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCrk_SdlFast_AntiFlood               */
/*---------------------------------------------------------------------------*/
#define PRE_INJCRK_SDLFAST_ANTIFLOOD()

#define POST_INJCRK_SDLFAST_ANTIFLOOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCutOff_SdlFast_InjCutOffBvmp        */
/*---------------------------------------------------------------------------*/
#define PRE_INJCUTOFF_SDLFAST_INJCUTOFFBVMP()

#define POST_INJCUTOFF_SDLFAST_INJCUTOFFBVMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCutOff_SdlFast_CutOff               */
/*---------------------------------------------------------------------------*/
#define PRE_INJCUTOFF_SDLFAST_CUTOFF()

#define POST_INJCUTOFF_SDLFAST_CUTOFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_InjSysSpCrk             */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_INJSYSSPCRK()

#define POST_INJSYS_SDLFAST_INJSYSSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_mFuSpCrk                */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_MFUSPCRK()

#define POST_INJSYS_SDLFAST_MFUSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_IfEOMInjSp              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_IFEOMINJSP()

#define POST_INJSYS_SDLFAST_IFEOMINJSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_rInjSp                  */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_RINJSP()

#define POST_INJSYS_SDLFAST_RINJSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_agInjSp                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_AGINJSP()

#define POST_INJSYS_SDLFAST_AGINJSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_InjAstWupCmp            */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_INJASTWUPCMP()

#define POST_INJSYS_SDLFAST_INJASTWUPCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_facFuTran               */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_FACFUTRAN()

#define POST_INJSYS_SDLFAST_FACFUTRAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_facFuTranIf             */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_FACFUTRANIF()

#define POST_INJSYS_SDLFAST_FACFUTRANIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_mFuSp                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_MFUSP()

#define POST_INJSYS_SDLFAST_MFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_InjSpMgt                */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_INJSPMGT()

#define POST_INJSYS_SDLFAST_INJSPMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_stTypElCmd              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_STTYPELCMD()

#define POST_INJSYS_SDLFAST_STTYPELCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_mFuInj                  */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_MFUINJ()

#define POST_INJSYS_SDLFAST_MFUINJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CylM_SdlFast_pCylM                     */
/*---------------------------------------------------------------------------*/
#define PRE_CYLM_SDLFAST_PCYLM()

#define POST_CYLM_SDLFAST_PCYLM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_SdlFast_pFuM                    */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_SDLFAST_PFUM()

#define POST_FUSYSM_SDLFAST_PFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_SdlFast_InjrPrmMdl               */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_SDLFAST_INJRPRMMDL()

#define POST_INJRM_SDLFAST_INJRPRMMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_SdlFast_InjrMdl                  */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_SDLFAST_INJRMDL()

#define POST_INJRM_SDLFAST_INJRMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_SdlFast_tiFuSp                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_SDLFAST_TIFUSP()

#define POST_INJRSYS_SDLFAST_TIFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrSys_SnStTCrFast_InjTiReq        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRSYS_SNSTTCRFAST_INJTIREQ()

#define POST_RE_INJRSYS_SNSTTCRFAST_INJTIREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_SnStTCrFast_InjTiReqIf         */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_SNSTTCRFAST_INJTIREQIF()

#define POST_INJRSYS_SNSTTCRFAST_INJTIREQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrSys_StTCrFast_TiFuSp            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRSYS_STTCRFAST_TIFUSP()

#define POST_RE_INJRSYS_STTCRFAST_TIFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_StTCrFast_TiFuSpIf             */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_STTCRFAST_TIFUSPIF()

#define POST_INJRSYS_STTCRFAST_TIFUSPIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RICHBOOST_vidEntry_10ms                */
/*---------------------------------------------------------------------------*/
#define PRE_RICHBOOST_VIDENTRY_10MS()

#define POST_RICHBOOST_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoPt_Sdl10ms_ProtDftlClc               */
/*---------------------------------------------------------------------------*/
#define PRE_COPT_SDL10MS_PROTDFTLCLC()

#define POST_COPT_SDL10MS_PROTDFTLCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_TqCha                    */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_TQCHA()

#define POST_TQSYS_SDL10MS_TQCHA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqIdlRes                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQIDLRES()

#define POST_TQRES_SDL10MS_TQIDLRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQLNCHRES_vidEntry_10ms                */
/*---------------------------------------------------------------------------*/
#define PRE_TQLNCHRES_VIDENTRY_10MS()

#define POST_TQLNCHRES_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqAltRes                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQALTRES()

#define POST_TQRES_SDL10MS_TQALTRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQSTGPMPRES_vidEntry_10ms              */
/*---------------------------------------------------------------------------*/
#define PRE_TQSTGPMPRES_VIDENTRY_10MS()

#define POST_TQSTGPMPRES_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQCNVRES_vidEntry_10ms                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQCNVRES_VIDENTRY_10MS()

#define POST_TQCNVRES_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQFANRES_vidEntry_10ms                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQFANRES_VIDENTRY_10MS()

#define POST_TQFANRES_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQEIPMPRES_vidEntry_10ms               */
/*---------------------------------------------------------------------------*/
#define PRE_TQEIPMPRES_VIDENTRY_10MS()

#define POST_TQEIPMPRES_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqCoHeatRes              */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQCOHEATRES()

#define POST_TQRES_SDL10MS_TQCOHEATRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqCrawlRes               */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQCRAWLRES()

#define POST_TQRES_SDL10MS_TQCRAWLRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqEOMRes                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQEOMRES()

#define POST_TQRES_SDL10MS_TQEOMRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqACRes                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQACRES()

#define POST_TQRES_SDL10MS_TQACRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqMaxRes                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQMAXRES()

#define POST_TQRES_SDL10MS_TQMAXRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_BrkAsi                   */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_BRKASI()

#define POST_TQSYS_SDL10MS_BRKASI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_SptMod                   */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_SPTMOD()

#define POST_TQSYS_SDL10MS_SPTMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_006_TEVIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_006_TEVIF()

#define POST_RE_PRODELEM_006_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_tqLimSfty                */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_TQLIMSFTY()

#define POST_TQSYS_SDLFAST_TQLIMSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_SpBenchMod               */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_SPBENCHMOD()

#define POST_TQSYS_SDLFAST_SPBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_TqSysIdc                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_TQSYSIDC()

#define POST_TQSYS_SDLFAST_TQSYSIDC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_TqSysVld                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_TQSYSVLD()

#define POST_TQSYS_SDLFAST_TQSYSVLD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl10ms_tqAltResIf               */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL10MS_TQALTRESIF()

#define POST_TQRES_SDL10MS_TQALTRESIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_tqLimSftyIf              */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_TQLIMSFTYIF()

#define POST_TQSYS_SDLFAST_TQLIMSFTYIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlMid_SyncSTT                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLMID_SYNCSTT()

#define POST_SYNC_SDLMID_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlMid_CkMngIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLMID_CKMNGIF()

#define POST_SYNC_SDLMID_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlMid_NEngClc                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLMID_NENGCLC()

#define POST_SYNC_SDLMID_NENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable COSYNC_vidEntry_10ms                   */
/*---------------------------------------------------------------------------*/
#define PRE_COSYNC_VIDENTRY_10MS()

#define POST_COSYNC_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PredEs_Sdl10ms_PredEs                  */
/*---------------------------------------------------------------------------*/
#define PRE_PREDES_SDL10MS_PREDES()

#define POST_PREDES_SDL10MS_PREDES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PREDESCHG_vidEntry_10ms                */
/*---------------------------------------------------------------------------*/
#define PRE_PREDESCHG_VIDENTRY_10MS()

#define POST_PREDESCHG_VIDENTRY_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrkMgt_SdlFast_AirThrArCrkSp           */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLFAST_AIRTHRARCRKSP()

#define POST_CRKMGT_SDLFAST_AIRTHRARCRKSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrkMgt_SdlFast_AirTqStructMngt         */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLFAST_AIRTQSTRUCTMNGT()

#define POST_CRKMGT_SDLFAST_AIRTQSTRUCTMNGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Crkmgt_sdlFast_tqStructMngtIf          */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLFAST_TQSTRUCTMNGTIF()

#define POST_CRKMGT_SDLFAST_TQSTRUCTMNGTIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Crkmgt_sdlFast_tqStructMngtIf2         */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLFAST_TQSTRUCTMNGTIF2()

#define POST_CRKMGT_SDLFAST_TQSTRUCTMNGTIF2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrkMgt_SdlFast_IfTqSysIf               */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLFAST_IFTQSYSIF()

#define POST_CRKMGT_SDLFAST_IFTQSYSIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ExM_SdlFast_ExOfs                      */
/*---------------------------------------------------------------------------*/
#define PRE_EXM_SDLFAST_EXOFS()

#define POST_EXM_SDLFAST_EXOFS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_EngrunStIfAir            */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_ENGRUNSTIFAIR()

#define POST_ENGST_SDLFAST_ENGRUNSTIFAIR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InAcq                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INACQ()

#define POST_VLVACT_SDLFAST_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InEstim                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INESTIM()

#define POST_VLVACT_SDLFAST_INESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InIf_1                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INIF_1()

#define POST_VLVACT_SDLFAST_INIF_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InVlvSpBenchMod         */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INVLVSPBENCHMOD()

#define POST_VLVACT_SDLFAST_INVLVSPBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InActrTest              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INACTRTEST()

#define POST_VLVACT_SDLFAST_INACTRTEST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InIf_2                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INIF_2()

#define POST_VLVACT_SDLFAST_INIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InIf_3                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INIF_3()

#define POST_VLVACT_SDLFAST_INIF_3()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InEndStop               */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INENDSTOP()

#define POST_VLVACT_SDLFAST_INENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InMng_1                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INMNG_1()

#define POST_VLVACT_SDLFAST_INMNG_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InServo                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INSERVO()

#define POST_VLVACT_SDLFAST_INSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_Sdlfast_InMon                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INMON()

#define POST_VLVACT_SDLFAST_INMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCam_InAcq                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCAM_INACQ()

#define POST_VLVACT_EVEINCAM_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCmToo_InAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCMTOO_INACQ()

#define POST_VLVACT_EVEINCMTOO_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCmToo_InEndStop            */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCMTOO_INENDSTOP()

#define POST_VLVACT_EVEINCMTOO_INENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCmToo_InEstim              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCMTOO_INESTIM()

#define POST_VLVACT_EVEINCMTOO_INESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCmToo_InIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCMTOO_INIF()

#define POST_VLVACT_EVEINCMTOO_INIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveInCmToo_InServo              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEINCMTOO_INSERVO()

#define POST_VLVACT_EVEINCMTOO_INSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveInCmToo_InCmSts                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEINCMTOO_INCMSTS()

#define POST_SYNC_EVEINCMTOO_INCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveInCmToo_CmCkMon                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEINCMTOO_CMCKMON()

#define POST_SYNC_EVEINCMTOO_CMCKMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_Sdl2ms_BattVotlAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDL2MS_BATTVOTLACQ()

#define POST_PWR_SDL2MS_BATTVOTLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ComStMng_EveSdlFast                    */
/*---------------------------------------------------------------------------*/
#define PRE_COMSTMNG_EVESDLFAST()

#define POST_COMSTMNG_EVESDLFAST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF3C9If                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF3C9IF()

#define POST_CAN_SDLSLOW_FHCANF3C9IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF349If_2              */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF349IF_2()

#define POST_CAN_SDLSLOW_FHCANF349IF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlFast_DsLsAcqIf              */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLFAST_DSLSACQIF()

#define POST_SENO2DS_SDLFAST_DSLSACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF349_FlowMng          */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF349_FLOWMNG()

#define POST_CAN_SDLSLOW_FHCANF349_FLOWMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VidMainFunction_StackCom_5MS           */
/*---------------------------------------------------------------------------*/
#define PRE_VIDMAINFUNCTION_STACKCOM_5MS()

#define POST_VIDMAINFUNCTION_STACKCOM_5MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlFast_ActrTstInj                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLFAST_ACTRTSTINJ()

#define POST_INJ_SDLFAST_ACTRTSTINJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCutOff_SdlFast_CutOffIf             */
/*---------------------------------------------------------------------------*/
#define PRE_INJCUTOFF_SDLFAST_CUTOFFIF()

#define POST_INJCUTOFF_SDLFAST_CUTOFFIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_SdlFast_InjrMdlIf                */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_SDLFAST_INJRMDLIF()

#define POST_INJRM_SDLFAST_INJRMDLIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCrk_SdlFast_AntiFloodIf             */
/*---------------------------------------------------------------------------*/
#define PRE_INJCRK_SDLFAST_ANTIFLOODIF()

#define POST_INJCRK_SDLFAST_ANTIFLOODIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_SdlFast_FuRailCtlMgr            */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_SDLFAST_FURAILCTLMGR()

#define POST_PFUCTL_SDLFAST_FURAILCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlFast_FuMFastCorrn         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLFAST_FUMFASTCORRN()

#define POST_RE_INJSYS_SDLFAST_FUMFASTCORRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlFast_TauXMgr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLFAST_TAUXMGR()

#define POST_RE_INJSYS_SDLFAST_TAUXMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveFastCrTR_TauXPrm          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVEFASTCRTR_TAUXPRM()

#define POST_RE_INJSYS_EVEFASTCRTR_TAUXPRM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlFast_TauXCoef             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLFAST_TAUXCOEF()

#define POST_RE_INJSYS_SDLFAST_TAUXCOEF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_FastCrTR_TauXCorrn           */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_FASTCRTR_TAUXCORRN()

#define POST_RE_INJSYS_FASTCRTR_TAUXCORRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_FastCrTR_TauXCorrnIf            */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_FASTCRTR_TAUXCORRNIF()

#define POST_INJSYS_FASTCRTR_TAUXCORRNIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_SdlFast_mFuSpIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_SDLFAST_MFUSPIF()

#define POST_INJSYS_SDLFAST_MFUSPIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_SdlFast_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_SDLFAST_MNG()

#define POST_FUPMP_SDLFAST_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FTPCtl_Sdl10ms_FTPCtl                  */
/*---------------------------------------------------------------------------*/
#define PRE_FTPCTL_SDL10MS_FTPCTL()

#define POST_FTPCTL_SDL10MS_FTPCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_SdlFast_PropFuPmp                */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_SDLFAST_PROPFUPMP()

#define POST_FUPMP_SDLFAST_PROPFUPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FuPmp                       */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FUPMP()

#define POST_CF_SDLFAST_FUPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgCmd_SdlFast_ActrTstCoil              */
/*---------------------------------------------------------------------------*/
#define PRE_IGCMD_SDLFAST_ACTRTSTCOIL()

#define POST_IGCMD_SDLFAST_ACTRTSTCOIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveFRMUpd_SecuMng                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVEFRMUPD_SECUMNG()

#define POST_THR_EVEFRMUPD_SECUMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_FullRngPosn                 */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_FULLRNGPOSN()

#define POST_THR_SDLMID_FULLRNGPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_MngServo                    */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_MNGSERVO()

#define POST_THR_SDLMID_MNGSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_ThrCmd                      */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_THRCMD()

#define POST_THR_SDLMID_THRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_ThrPosnSpSpc                */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_THRPOSNSPSPC()

#define POST_THR_SDLMID_THRPOSNSPSPC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_BenchAut                    */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_BENCHAUT()

#define POST_THR_SDLMID_BENCHAUT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_ActrTstThr                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_ACTRTSTTHR()

#define POST_THR_SDLMID_ACTRTSTTHR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_SpBenchMod                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_SPBENCHMOD()

#define POST_THR_SDLMID_SPBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_SpPosn                      */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_SPPOSN()

#define POST_THR_SDLMID_SPPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_BoostSp                     */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_BOOSTSP()

#define POST_THR_SDLMID_BOOSTSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_AbsSpPosn                   */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_ABSSPPOSN()

#define POST_THR_SDLMID_ABSSPPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_OplCtl                      */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_OPLCTL()

#define POST_THR_SDLMID_OPLCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_Servo                       */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_SERVO()

#define POST_THR_SDLMID_SERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_ThermoProt                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_THERMOPROT()

#define POST_THR_SDLMID_THERMOPROT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveFRMUpd_ThrSecuMngIf             */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVEFRMUPD_THRSECUMNGIF()

#define POST_THR_EVEFRMUPD_THRSECUMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlMid_MngServoIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLMID_MNGSERVOIF()

#define POST_THR_SDLMID_MNGSERVOIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlFast_ifTqMon                */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLFAST_IFTQMON()

#define POST_SFTYMGT_SDLFAST_IFTQMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_Sdl10ms_IfTMS                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDL10MS_IFTMS()

#define POST_SFTYMGT_SDL10MS_IFTMS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sfty_SdlFast_DiagCpuSfty               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTY_SDLFAST_DIAGCPUSFTY()

#define POST_SFTY_SDLFAST_DIAGCPUSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_AirExtPresAcq          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_AIREXTPRESACQ()

#define POST_AIRPRES_SDLFAST_AIREXTPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_InMnfPresDiag          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_INMNFPRESDIAG()

#define POST_AIRPRES_SDLFAST_INMNFPRESDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_BrkAsiAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_BRKASIACQ()

#define POST_AIRPRES_SDLFAST_BRKASIACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_RelBrkAsiAcq           */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_RELBRKASIACQ()

#define POST_AIRPRES_SDLFAST_RELBRKASIACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_MonBrkAsi              */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_MONBRKASI()

#define POST_AIRPRES_SDLFAST_MONBRKASI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlFast_AirExtPresAcqIf        */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLFAST_AIREXTPRESACQIF()

#define POST_AIRPRES_SDLFAST_AIREXTPRESACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlFast_PresDiagCoh                */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLFAST_PRESDIAGCOH()

#define POST_OIL_SDLFAST_PRESDIAGCOH()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VidMainFunction_StackCom_10MS          */
/*---------------------------------------------------------------------------*/
#define PRE_VIDMAINFUNCTION_STACKCOM_10MS()

#define POST_VIDMAINFUNCTION_STACKCOM_10MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_EveOilLvl_OilLvlAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_EVEOILLVL_OILLVLACQ()

#define POST_OIL_EVEOILLVL_OILLVLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveStTR_CkMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVESTTR_CKMNGIF()

#define POST_SYNC_EVESTTR_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveStTR_FuSysCkMngIf              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVESTTR_FUSYSCKMNGIF()

#define POST_SYNC_EVESTTR_FUSYSCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveStTR_EngStrtStop              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVESTTR_ENGSTRTSTOP()

#define POST_ENGST_EVESTTR_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveStTR_VehSt                    */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVESTTR_VEHST()

#define POST_ENGST_EVESTTR_VEHST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoT_EveStTR_AcqCoT                     */
/*---------------------------------------------------------------------------*/
#define PRE_COT_EVESTTR_ACQCOT()

#define POST_COT_EVESTTR_ACQCOT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveStTR_ClcnFisaGain              */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVESTTR_CLCNFISAGAIN()

#define POST_FISA_EVESTTR_CLCNFISAGAIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_EveStTR_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_EVESTTR_MNG()

#define POST_FUPMP_EVESTTR_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_FuPmp_EveStTR_Mng                   */
/*---------------------------------------------------------------------------*/
#define PRE_CF_FUPMP_EVESTTR_MNG()

#define POST_CF_FUPMP_EVESTTR_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_EveStTR_Mng                     */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_EVESTTR_MNG()

#define POST_RLYPWR_EVESTTR_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveStTR_InjSysMgrCrk            */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESTTR_INJSYSMGRCRK()

#define POST_INJSYS_EVESTTR_INJSYSMGRCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveStTR_InjSysSpCrk             */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESTTR_INJSYSSPCRK()

#define POST_INJSYS_EVESTTR_INJSYSSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveStTR_mFuSpCrk                */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESTTR_MFUSPCRK()

#define POST_INJSYS_EVESTTR_MFUSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveStTR_InjResuCmp              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVESTTR_INJRESUCMP()

#define POST_INJSYS_EVESTTR_INJRESUCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveStTR_FuRailCtlMgr            */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESTTR_FURAILCTLMGR()

#define POST_PFUCTL_EVESTTR_FURAILCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveStTR_HPPmpMdl                */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESTTR_HPPMPMDL()

#define POST_PFUCTL_EVESTTR_HPPMPMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveStTR_HPPmpActCmd             */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVESTTR_HPPMPACTCMD()

#define POST_PFUCTL_EVESTTR_HPPMPACTCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveStTR_FuLvl                       */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVESTTR_FULVL()

#define POST_FU_EVESTTR_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgCmd_EveStTR_MisfGenr                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGCMD_EVESTTR_MISFGENR()

#define POST_IGCMD_EVESTTR_MISFGENR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveStTR_KnkMvNoisAdpRbl       */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVESTTR_KNKMVNOISADPRBL()

#define POST_KNKTREAT_EVESTTR_KNKMVNOISADPRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OilTqCf_Sdl20ms_OilTqCf                */
/*---------------------------------------------------------------------------*/
#define PRE_OILTQCF_SDL20MS_OILTQCF()

#define POST_OILTQCF_SDL20MS_OILTQCF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl20ms_TqAdvMin                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL20MS_TQADVMIN()

#define POST_TQSYS_SDL20MS_TQADVMIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlMid_MuxTqReq                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLMID_MUXTQREQ()

#define POST_TQSYS_SDLMID_MUXTQREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl20ms_TqCmpManGBx              */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL20MS_TQCMPMANGBX()

#define POST_TQSYS_SDL20MS_TQCMPMANGBX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqRes_Sdl20ms_tqACRes                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQRES_SDL20MS_TQACRES()

#define POST_TQRES_SDL20MS_TQACRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlMid_KnkDetRbl              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLMID_KNKDETRBL()

#define POST_KNKTREAT_SDLMID_KNKDETRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlMid_KnkDet                 */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLMID_KNKDET()

#define POST_KNKTREAT_SDLMID_KNKDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlFast_FHCanF34DIf                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLFAST_FHCANF34DIF()

#define POST_CAN_SDLFAST_FHCANF34DIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_SdlMid_KnkInhAdp                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_SDLMID_KNKINHADP()

#define POST_IGLIM_SDLMID_KNKINHADP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_SdlMid_KnkAdpCor                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_SDLMID_KNKADPCOR()

#define POST_IGLIM_SDLMID_KNKADPCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_SdlMid_CluSwtDiag                  */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_SDLMID_CLUSWTDIAG()

#define POST_CLU_SDLMID_CLUSWTDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_SdlMid_Acq                         */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDLMID_ACQ()

#define POST_PWR_SDLMID_ACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlFast_TeleSrv                    */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLFAST_TELESRV()

#define POST_SRV_SDLFAST_TELESRV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlFast_RefIdEta                   */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLFAST_REFIDETA()

#define POST_SRV_SDLFAST_REFIDETA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlFast_ObdSrvPid                  */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLFAST_OBDSRVPID()

#define POST_SRV_SDLFAST_OBDSRVPID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlFast_PwrlMrk                    */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLFAST_PWRLMRK()

#define POST_SRV_SDLFAST_PWRLMRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DCM_CONFIG_sdlFast_DiagSrv             */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_CONFIG_SDLFAST_DIAGSRV()

#define POST_DCM_CONFIG_SDLFAST_DIAGSRV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlFast_PostEquSrv                 */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLFAST_POSTEQUSRV()

#define POST_SRV_SDLFAST_POSTEQUSRV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlFast_MisfWinAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLFAST_MISFWINACQ()

#define POST_MISF_SDLFAST_MISFWINACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlFast_MisfRoughnsRoadCan        */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLFAST_MISFROUGHNSROADCAN()

#define POST_MISF_SDLFAST_MISFROUGHNSROADCAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ISLIN_vidSdlFast                       */
/*---------------------------------------------------------------------------*/
#define PRE_ISLIN_VIDSDLFAST()

#define POST_ISLIN_VIDSDLFAST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Lin_SdlFast_IsLinIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_LIN_SDLFAST_ISLINIF()

#define POST_LIN_SDLFAST_ISLINIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlFast_HPSensDiag                  */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLFAST_HPSENSDIAG()

#define POST_FU_SDLFAST_HPSENSDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlFast_StuckInjrDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLFAST_STUCKINJRDIAG()

#define POST_FU_SDLFAST_STUCKINJRDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlFast_FuLvl                       */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLFAST_FULVL()

#define POST_FU_SDLFAST_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VidMainFunction_StackCom_20MS          */
/*---------------------------------------------------------------------------*/
#define PRE_VIDMAINFUNCTION_STACKCOM_20MS()

#define POST_VIDMAINFUNCTION_STACKCOM_20MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOf_KnkRblAcq           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNOF_KNKRBLACQ()

#define POST_KNKTREAT_EVECKSNOF_KNKRBLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOf_KnkAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNOF_KNKACQ()

#define POST_KNKTREAT_EVECKSNOF_KNKACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOf_SyncSTT                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNOF_SYNCSTT()

#define POST_SYNC_EVECKSNOF_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOf_SyncCkDiagDiag          */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNOF_SYNCCKDIAGDIAG()

#define POST_SYNC_EVECKSNOF_SYNCCKDIAGDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOf_EngSyncMng              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNOF_ENGSYNCMNG()

#define POST_SYNC_EVECKSNOF_ENGSYNCMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveCkSnOf_MisfWinAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVECKSNOF_MISFWINACQ()

#define POST_MISF_EVECKSNOF_MISFWINACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InCln                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INCLN()

#define POST_VLVACT_SDLFAST_INCLN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InMng_2                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INMNG_2()

#define POST_VLVACT_SDLFAST_INMNG_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_InCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_INCMD()

#define POST_VLVACT_SDLFAST_INCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExAcq                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXACQ()

#define POST_VLVACT_SDLFAST_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExEstim                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXESTIM()

#define POST_VLVACT_SDLFAST_EXESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExIf_1                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXIF_1()

#define POST_VLVACT_SDLFAST_EXIF_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExVlvSpBenchMod         */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXVLVSPBENCHMOD()

#define POST_VLVACT_SDLFAST_EXVLVSPBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExActrTest              */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXACTRTEST()

#define POST_VLVACT_SDLFAST_EXACTRTEST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExIf_2                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXIF_2()

#define POST_VLVACT_SDLFAST_EXIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExEndStop               */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXENDSTOP()

#define POST_VLVACT_SDLFAST_EXENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExMng_1                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXMNG_1()

#define POST_VLVACT_SDLFAST_EXMNG_1()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExServo                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXSERVO()

#define POST_VLVACT_SDLFAST_EXSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_Sdlfast_ExMon                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXMON()

#define POST_VLVACT_SDLFAST_EXMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExCln                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXCLN()

#define POST_VLVACT_SDLFAST_EXCLN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExMng_2                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXMNG_2()

#define POST_VLVACT_SDLFAST_EXMNG_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlFast_ExCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLFAST_EXCMD()

#define POST_VLVACT_SDLFAST_EXCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_AltiCor                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_ALTICOR()

#define POST_VLVSYS_SDLFAST_ALTICOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_VlvIn                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_VLVIN()

#define POST_VLVSYS_SDLFAST_VLVIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_VlvEx                   */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_VLVEX()

#define POST_VLVSYS_SDLFAST_VLVEX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_VlvArb                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_VLVARB()

#define POST_VLVSYS_SDLFAST_VLVARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_VlvInIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_VLVINIF()

#define POST_VLVSYS_SDLFAST_VLVINIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvSys_SdlFast_VlvExIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVSYS_SDLFAST_VLVEXIF()

#define POST_VLVSYS_SDLFAST_VLVEXIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlSlow_NoProd                      */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLSLOW_NOPROD()

#define POST_CF_SDLSLOW_NOPROD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlSlow_TunCfg                      */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLSLOW_TUNCFG()

#define POST_CF_SDLSLOW_TUNCFG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlSlow_InEndStop               */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLSLOW_INENDSTOP()

#define POST_VLVACT_SDLSLOW_INENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_SdlSlow_ExEndStop               */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_SDLSLOW_EXENDSTOP()

#define POST_VLVACT_SDLSLOW_EXENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_SdlSlow_CluSwtDiag                 */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_SDLSLOW_CLUSWTDIAG()

#define POST_CLU_SDLSLOW_CLUSWTDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sfty_SdlSlow_DiagCpuSfty               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTY_SDLSLOW_DIAGCPUSFTY()

#define POST_SFTY_SDLSLOW_DIAGCPUSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlSlow_FuLvl                       */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLSLOW_FULVL()

#define POST_FU_SDLSLOW_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_SdlSlow_IgArb                    */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_SDLSLOW_IGARB()

#define POST_IGSYS_SDLSLOW_IGARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlMid_TauXMgr               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLMID_TAUXMGR()

#define POST_RE_INJSYS_SDLMID_TAUXMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlMid_TauXCoef              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLMID_TAUXCOEF()

#define POST_RE_INJSYS_SDLMID_TAUXCOEF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_SdlMid_InjTiCor                    */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_SDLMID_INJTICOR()

#define POST_INJ_SDLMID_INJTICOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlSlow_MisfDftLrn                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLSLOW_MISFDFTLRN()

#define POST_MISF_SDLSLOW_MISFDFTLRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlSlow_MisfDftLrnOut             */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLSLOW_MISFDFTLRNOUT()

#define POST_MISF_SDLSLOW_MISFDFTLRNOUT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgCmd_SdlSlow_MisfGenr                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGCMD_SDLSLOW_MISFGENR()

#define POST_IGCMD_SDLSLOW_MISFGENR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlSlow_MisfFaiCtr                */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLSLOW_MISFFAICTR()

#define POST_MISF_SDLSLOW_MISFFAICTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_SdlSlow_BlowByCmd                  */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_SDLSLOW_BLOWBYCMD()

#define POST_OIL_SDLSLOW_BLOWBYCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_CkMngIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_CKMNGIF()

#define POST_SYNC_EVECKSNON_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkLTo1_SyncSTT                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKLTO1_SYNCSTT()

#define POST_SYNC_EVECKLTO1_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_SyncCkDiagDiag          */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_SYNCCKDIAGDIAG()

#define POST_SYNC_EVECKSNON_SYNCCKDIAGDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_EngSyncMng              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_ENGSYNCMNG()

#define POST_SYNC_EVECKSNON_ENGSYNCMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_CkMngIfIf               */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_CKMNGIFIF()

#define POST_SYNC_EVECKSNON_CKMNGIFIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_CkMngIfIf_2             */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_CKMNGIFIF_2()

#define POST_SYNC_EVECKSNON_CKMNGIFIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_IfAirSysIgSys           */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_IFAIRSYSIGSYS()

#define POST_SYNC_EVECKSNON_IFAIRSYSIGSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkSnOn_FuSysCkMngIf            */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKSNON_FUSYSCKMNGIF()

#define POST_SYNC_EVECKSNON_FUSYSCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveCkSnOn_InAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVECKSNON_INACQ()

#define POST_VLVACT_EVECKSNON_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveCkSnOn_InEndStop             */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVECKSNON_INENDSTOP()

#define POST_VLVACT_EVECKSNON_INENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveCkSnOn_ExAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVECKSNON_EXACQ()

#define POST_VLVACT_EVECKSNON_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveCkSnOn_ExEndStop             */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVECKSNON_EXENDSTOP()

#define POST_VLVACT_EVECKSNON_EXENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_KnkAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_KNKACQ()

#define POST_KNKTREAT_EVECKSNON_KNKACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_KnkRblAcq           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_KNKRBLACQ()

#define POST_KNKTREAT_EVECKSNON_KNKRBLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_KnkAcqFilt          */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_KNKACQFILT()

#define POST_KNKTREAT_EVECKSNON_KNKACQFILT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_InstNoise           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_INSTNOISE()

#define POST_KNKTREAT_EVECKSNON_INSTNOISE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_KnkDetRbl           */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_KNKDETRBL()

#define POST_KNKTREAT_EVECKSNON_KNKDETRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_ShdDet              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_SHDDET()

#define POST_KNKTREAT_EVECKSNON_SHDDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveCkSnOn_KnkDet              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVECKSNON_KNKDET()

#define POST_KNKTREAT_EVECKSNON_KNKDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveCkSnOn_ShdCor                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVECKSNON_SHDCOR()

#define POST_IGLIM_EVECKSNON_SHDCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveCkSnOn_EngStrtStop            */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVECKSNON_ENGSTRTSTOP()

#define POST_ENGST_EVECKSNON_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveCkSnOn_MisfWinAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVECKSNON_MISFWINACQ()

#define POST_MISF_EVECKSNON_MISFWINACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjCrk_EveClcn2_PreInjTi            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJCRK_EVECLCN2_PREINJTI()

#define POST_RE_INJCRK_EVECLCN2_PREINJTI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_CkMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_CKMNGIF()

#define POST_SYNC_EVERTST_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_InCmSts                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_INCMSTS()

#define POST_SYNC_EVERTST_INCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgCmd_EveRTSt_MisfGenr                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGCMD_EVERTST_MISFGENR()

#define POST_IGCMD_EVERTST_MISFGENR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_CkMngIfIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_CKMNGIFIF()

#define POST_SYNC_EVERTST_CKMNGIFIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_CkMngIfIf_2               */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_CKMNGIFIF_2()

#define POST_SYNC_EVERTST_CKMNGIFIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenAct_EveRTSt_tECUAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENACT_EVERTST_TECUACQ()

#define POST_SENACT_EVERTST_TECUACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenAct_EveRTSt_tECUAcqIf               */
/*---------------------------------------------------------------------------*/
#define PRE_SENACT_EVERTST_TECUACQIF()

#define POST_SENACT_EVERTST_TECUACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveRTSt_FisaRFuDet                */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVERTST_FISARFUDET()

#define POST_FISA_EVERTST_FISARFUDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveRTSt_InjSysMgrCrk            */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVERTST_INJSYSMGRCRK()

#define POST_INJSYS_EVERTST_INJSYSMGRCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveRTSt_InjResuCmp              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVERTST_INJRESUCMP()

#define POST_INJSYS_EVERTST_INJRESUCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_EveRTSt_FarCtlMgr               */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_EVERTST_FARCTLMGR()

#define POST_INJCTL_EVERTST_FARCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_EveRTSt_FarCtlUsCtl             */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_EVERTST_FARCTLUSCTL()

#define POST_INJCTL_EVERTST_FARCTLUSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_EveRTSt_InjTiCor                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_EVERTST_INJTICOR()

#define POST_INJ_EVERTST_INJTICOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_RstRTSt_InjTiReqIf             */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_RSTRTST_INJTIREQIF()

#define POST_INJRSYS_RSTRTST_INJTIREQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_RstRTSt_TiFuSpIf               */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_RSTRTST_TIFUSPIF()

#define POST_INJRSYS_RSTRTST_TIFUSPIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrSys_RstRTSt_TiFuSp              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRSYS_RSTRTST_TIFUSP()

#define POST_RE_INJRSYS_RSTRTST_TIFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_EveRTSt_IfAirSysIgSys           */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_EVERTST_IFAIRSYSIGSYS()

#define POST_INJCTL_EVERTST_IFAIRSYSIGSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveRTSt_FuRailCtlMgr            */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVERTST_FURAILCTLMGR()

#define POST_PFUCTL_EVERTST_FURAILCTLMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveRTSt_HPPmpCtl                */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVERTST_HPPMPCTL()

#define POST_PFUCTL_EVERTST_HPPMPCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveRTSt_HPPmpMdl                */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVERTST_HPPMPMDL()

#define POST_PFUCTL_EVERTST_HPPMPMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_EveRTSt_HPPmpActCmd             */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_EVERTST_HPPMPACTCMD()

#define POST_PFUCTL_EVERTST_HPPMPACTCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_EveRTSt_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_EVERTST_MNG()

#define POST_FUPMP_EVERTST_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveRTSt_EngStrtStop              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVERTST_ENGSTRTSTOP()

#define POST_ENGST_EVERTST_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveRTSt_TiEngStop                */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVERTST_TIENGSTOP()

#define POST_ENGST_EVERTST_TIENGSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_IfAirSysIgSys             */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_IFAIRSYSIGSYS()

#define POST_SYNC_EVERTST_IFAIRSYSIGSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveRTSt_FuSysCkMngIf              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVERTST_FUSYSCKMNGIF()

#define POST_SYNC_EVERTST_FUSYSCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveRTSt_IgCrk                    */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVERTST_IGCRK()

#define POST_IGSYS_EVERTST_IGCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveRTSt_FuLvl                       */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVERTST_FULVL()

#define POST_FU_EVERTST_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRTSt_KnkAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERTST_KNKACQ()

#define POST_KNKTREAT_EVERTST_KNKACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveRTSt_KnkRblAcq             */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVERTST_KNKRBLACQ()

#define POST_KNKTREAT_EVERTST_KNKRBLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_EveRTSt_UsMgr                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_EVERTST_USMGR()

#define POST_HEATSENO2_EVERTST_USMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_EveRTSt_DsMgr                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_EVERTST_DSMGR()

#define POST_HEATSENO2_EVERTST_DSMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlMid_HrdRcvMng                    */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLMID_HRDRCVMNG()

#define POST_GD_SDLMID_HRDRCVMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FRunTime_SdlMid                        */
/*---------------------------------------------------------------------------*/
#define PRE_FRUNTIME_SDLMID()

#define POST_FRUNTIME_SDLMID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlSlow_SumRat                      */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLSLOW_SUMRAT()

#define POST_GD_SDLSLOW_SUMRAT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CcpDaqListSetEvent_Slow                */
/*---------------------------------------------------------------------------*/
#define PRE_CCPDAQLISTSETEVENT_SLOW()

#define POST_CCPDAQLISTSETEVENT_SLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlSlow_IndicOBD                    */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLSLOW_INDICOBD()

#define POST_GD_SDLSLOW_INDICOBD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenAct_SdlSlow_tIGBTAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_SENACT_SDLSLOW_TIGBTACQ()

#define POST_SENACT_SDLSLOW_TIGBTACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DIAGCAN_Eve50ms                        */
/*---------------------------------------------------------------------------*/
#define PRE_DIAGCAN_EVE50MS()

#define POST_DIAGCAN_EVE50MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DCM_CONFIG_SdlMid_RcRst                */
/*---------------------------------------------------------------------------*/
#define PRE_DCM_CONFIG_SDLMID_RCRST()

#define POST_DCM_CONFIG_SDLMID_RCRST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_CkMngIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_CKMNGIF()

#define POST_SYNC_EVETDC_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_SyncSTT                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_SYNCSTT()

#define POST_SYNC_EVETDC_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_IfNEngClc                  */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_IFNENGCLC()

#define POST_SYNC_EVETDC_IFNENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_CkMngIf3                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_CKMNGIF3()

#define POST_SYNC_EVETDC_CKMNGIF3()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_NEngClc                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_NENGCLC()

#define POST_SYNC_EVETDC_NENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_CkMngIfIf_2                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_CKMNGIFIF_2()

#define POST_SYNC_EVETDC_CKMNGIFIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_FuSysCkMngIf               */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_FUSYSCKMNGIF()

#define POST_SYNC_EVETDC_FUSYSCKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_CkMngIfIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_CKMNGIFIF()

#define POST_SYNC_EVETDC_CKMNGIFIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveTDC_IfAirSysIgSys              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVETDC_IFAIRSYSIGSYS()

#define POST_SYNC_EVETDC_IFAIRSYSIGSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveTDC_InAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVETDC_INACQ()

#define POST_VLVACT_EVETDC_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveTDC_ExAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVETDC_EXACQ()

#define POST_VLVACT_EVETDC_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Us_EveTDC_UpLsAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2US_EVETDC_UPLSACQ()

#define POST_SENO2US_EVETDC_UPLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable STT_EveTDC_STTmO2Clc                   */
/*---------------------------------------------------------------------------*/
#define PRE_STT_EVETDC_STTMO2CLC()

#define POST_STT_EVETDC_STTMO2CLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveTDC_FisaInhMgr                 */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVETDC_FISAINHMGR()

#define POST_FISA_EVETDC_FISAINHMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveTDC_FisaRFuDet                 */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVETDC_FISARFUDET()

#define POST_FISA_EVETDC_FISARFUDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveTDC_ClcnFisaGain               */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVETDC_CLCNFISAGAIN()

#define POST_FISA_EVETDC_CLCNFISAGAIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_EveTDC_FarCtlUsCtl              */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_EVETDC_FARCTLUSCTL()

#define POST_INJCTL_EVETDC_FARCTLUSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_EveTDC_FarCtlUsCtlIf            */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_EVETDC_FARCTLUSCTLIF()

#define POST_INJCTL_EVETDC_FARCTLUSCTLIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_EveTDC_ObdSrvPid                   */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_EVETDC_OBDSRVPID()

#define POST_SRV_EVETDC_OBDSRVPID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveBDC_CritZone                  */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVEBDC_CRITZONE()

#define POST_IGLIM_EVEBDC_CRITZONE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveBDC_KnkAdpCor                 */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVEBDC_KNKADPCOR()

#define POST_IGLIM_EVEBDC_KNKADPCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveBDC_ShdCor                    */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVEBDC_SHDCOR()

#define POST_IGLIM_EVEBDC_SHDCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveBDC_FastCor                   */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVEBDC_FASTCOR()

#define POST_IGLIM_EVEBDC_FASTCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_EveBDC_CritZoneIf                */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_EVEBDC_CRITZONEIF()

#define POST_IGLIM_EVEBDC_CRITZONEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_EveBDC_TqSysVld                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_EVEBDC_TQSYSVLD()

#define POST_TQSYS_EVEBDC_TQSYSVLD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_EveTDC_SpBenchMod                */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_EVETDC_SPBENCHMOD()

#define POST_TQSYS_EVETDC_SPBENCHMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_EveTDC_ifTqMon                 */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_EVETDC_IFTQMON()

#define POST_SFTYMGT_EVETDC_IFTQMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_EveBDC_ObdSrvPid                   */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_EVEBDC_OBDSRVPID()

#define POST_SRV_EVEBDC_OBDSRVPID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OilSys_EveTDC_OilDsp                   */
/*---------------------------------------------------------------------------*/
#define PRE_OILSYS_EVETDC_OILDSP()

#define POST_OILSYS_EVETDC_OILDSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveTDC_PosnMes                     */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVETDC_POSNMES()

#define POST_THR_EVETDC_POSNMES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CcpDaqListSetEvent_Angular             */
/*---------------------------------------------------------------------------*/
#define PRE_CCPDAQLISTSETEVENT_ANGULAR()

#define POST_CCPDAQLISTSETEVENT_ANGULAR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkTo_SyncSTT                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKTO_SYNCSTT()

#define POST_SYNC_EVECKTO_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable BufNEs_EveCgt_BufNEs                   */
/*---------------------------------------------------------------------------*/
#define PRE_BUFNES_EVECGT_BUFNES()

#define POST_BUFNES_EVECGT_BUFNES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlSlow_IuprFrz                     */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLSLOW_IUPRFRZ()

#define POST_GD_SDLSLOW_IUPRFRZ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IUPRGENDEN_vidMngEveSdlSlow            */
/*---------------------------------------------------------------------------*/
#define PRE_IUPRGENDEN_VIDMNGEVESDLSLOW()

#define POST_IUPRGENDEN_VIDMNGEVESDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IuprSpcDen_SdlSlow                     */
/*---------------------------------------------------------------------------*/
#define PRE_IUPRSPCDEN_SDLSLOW()

#define POST_IUPRSPCDEN_SDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IUPRRATIO_vidMngEveSdlSlow             */
/*---------------------------------------------------------------------------*/
#define PRE_IUPRRATIO_VIDMNGEVESDLSLOW()

#define POST_IUPRRATIO_VIDMNGEVESDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FRunTime_SdlSlow                       */
/*---------------------------------------------------------------------------*/
#define PRE_FRUNTIME_SDLSLOW()

#define POST_FRUNTIME_SDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_TiEngStop                */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_TIENGSTOP()

#define POST_ENGST_SDLFAST_TIENGSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_EngStrtStop              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_ENGSTRTSTOP()

#define POST_ENGST_SDLFAST_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_VehSt                    */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_VEHST()

#define POST_ENGST_SDLFAST_VEHST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_SdlMid_VoltHldDev                  */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDLMID_VOLTHLDDEV()

#define POST_PWR_SDLMID_VOLTHLDDEV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Strtr_SdlMid_IfCmdDiag                 */
/*---------------------------------------------------------------------------*/
#define PRE_STRTR_SDLMID_IFCMDDIAG()

#define POST_STRTR_SDLMID_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_EngrunSt                 */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_ENGRUNST()

#define POST_ENGST_SDLFAST_ENGRUNST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_EngStOutIdc              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_ENGSTOUTIDC()

#define POST_ENGST_SDLFAST_ENGSTOUTIDC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_MonEngStrt               */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_MONENGSTRT()

#define POST_ENGST_SDLFAST_MONENGSTRT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_DftStaCmd                */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_DFTSTACMD()

#define POST_ENGST_SDLFAST_DFTSTACMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_AuthStrtSTT              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_AUTHSTRTSTT()

#define POST_ENGST_SDLFAST_AUTHSTRTSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlFast_OscDet                   */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLFAST_OSCDET()

#define POST_ENGST_SDLFAST_OSCDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlSlow_FlowMng                     */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLSLOW_FLOWMNG()

#define POST_CF_SDLSLOW_FLOWMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_nTarIdlCmbMod            */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_NTARIDLCMBMOD()

#define POST_TQSYS_SDL10MS_NTARIDLCMBMOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_028_TEVIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_028_TEVIF()

#define POST_RE_TRABVX_028_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_004_TEVIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_004_TEVIF()

#define POST_RE_TQTREAT_004_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_Sdl10ms_CoPtGearCordIf        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_SDL10MS_COPTGEARCORDIF()

#define POST_RE_TQSYS_SDL10MS_COPTGEARCORDIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlFast_FlowMngClu_2                */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLFAST_FLOWMNGCLU_2()

#define POST_CF_SDLFAST_FLOWMNGCLU_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_TqEfcCordLim             */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_TQEFCCORDLIM()

#define POST_TQSYS_SDL10MS_TQEFCCORDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_Sdl10ms_nTarIdl                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDL10MS_NTARIDL()

#define POST_TQSYS_SDL10MS_NTARIDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_AirExtPresAcq           */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_AIREXTPRESACQ()

#define POST_AIRPRES_SDLMID_AIREXTPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_InMnfPresAcq            */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_INMNFPRESACQ()

#define POST_AIRPRES_SDLMID_INMNFPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_SpgPresAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_SPGPRESACQ()

#define POST_AIRPRES_SDLMID_SPGPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrkMgt_SdlMid_AirThrArCrkSp            */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLMID_AIRTHRARCRKSP()

#define POST_CRKMGT_SDLMID_AIRTHRARCRKSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CrkMgt_SdlMid_AirTqStructMngt          */
/*---------------------------------------------------------------------------*/
#define PRE_CRKMGT_SDLMID_AIRTQSTRUCTMNGT()

#define POST_CRKMGT_SDLMID_AIRTQSTRUCTMNGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlFast_FuConcEstim               */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLFAST_FUCONCESTIM()

#define POST_CSTR_SDLFAST_FUCONCESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlFast_CstrEfcRed                */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLFAST_CSTREFCRED()

#define POST_CSTR_SDLFAST_CSTREFCRED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlFast_CstrCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLFAST_CSTRCMD()

#define POST_CSTR_SDLFAST_CSTRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlMid_MonVehSpd                */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLMID_MONVEHSPD()

#define POST_VEHSPD_SDLMID_MONVEHSPD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlMid_SpgPresAcqif            */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLMID_SPGPRESACQIF()

#define POST_AIRPRES_SDLMID_SPGPRESACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_023_MSEIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_023_MSEIF()

#define POST_RE_STOPSTRTENG_023_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEng_013_MSEIf               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTENG_013_MSEIF()

#define POST_RE_STOPSTRTENG_013_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_StopStrtEm_003_MSEIf                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_STOPSTRTEM_003_MSEIF()

#define POST_RE_STOPSTRTEM_003_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ProdElEm_005_MSEIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_PRODELEM_005_MSEIF()

#define POST_RE_PRODELEM_005_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_001_MSEIf                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_001_MSEIF()

#define POST_RE_TPM_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OilTqCf_EveRst_OilTqCf                 */
/*---------------------------------------------------------------------------*/
#define PRE_OILTQCF_EVERST_OILTQCF()

#define POST_OILTQCF_EVERST_OILTQCF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqTreat_003_MSEIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQTREAT_003_MSEIF()

#define POST_RE_TQTREAT_003_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TraBVx_001_MSEIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TRABVX_001_MSEIF()

#define POST_RE_TRABVX_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoGBx_001_MSEIf                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COGBX_001_MSEIF()

#define POST_RE_COGBX_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_CoClLASl_001_MSEIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_COCLLASL_001_MSEIF()

#define POST_RE_COCLLASL_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_001_MSEIfTWC               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_001_MSEIFTWC()

#define POST_RE_EXMGSLT2_001_MSEIFTWC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_EngM_initIf                         */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ENGM_INITIF()

#define POST_RE_ENGM_INITIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_043_MSEIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_043_MSEIF()

#define POST_RE_INMDLT_043_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_001_MSEIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_001_MSEIF()

#define POST_RE_EXMGSLT2_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AFAT_026_MSE                        */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AFAT_026_MSE()

#define POST_RE_AFAT_026_MSE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AirSysAir_001_MSEIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_AIRSYSAIR_001_MSEIF()

#define POST_RE_AIRSYSAIR_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlvAct_EveRst_DmpVlvOplCmd          */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLVACT_EVERST_DMPVLVOPLCMD()

#define POST_DMPVLVACT_EVERST_DMPVLVOPLCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_EveRst_ActrTstDV                */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_EVERST_ACTRTSTDV()

#define POST_DMPVLV_EVERST_ACTRTSTDV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_EveRst_DmpVlvCmdSpArb           */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_EVERST_DMPVLVCMDSPARB()

#define POST_DMPVLV_EVERST_DMPVLVCMDSPARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_EveRst_FctDiagDmpVlv            */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_EVERST_FCTDIAGDMPVLV()

#define POST_DMPVLV_EVERST_FCTDIAGDMPVLV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_005_MSEIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_005_MSEIF()

#define POST_RE_ADVMINT_005_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_OEMGsl_001_MSEIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_OEMGSL_001_MSEIF()

#define POST_RE_OEMGSL_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMaxT_001_MSEIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMAXT_001_MSEIF()

#define POST_RE_ADVMAXT_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuSysM_EveRst_TFuM                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUSYSM_EVERST_TFUM()

#define POST_RE_FUSYSM_EVERST_TFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveRst_FuMFastCorrn          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVERST_FUMFASTCORRN()

#define POST_RE_INJSYS_EVERST_FUMFASTCORRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveRst_TauXMgr               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVERST_TAUXMGR()

#define POST_RE_INJSYS_EVERST_TAUXMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveRst_TauXPrm               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVERST_TAUXPRM()

#define POST_RE_INJSYS_EVERST_TAUXPRM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveRst_TauXCoef              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVERST_TAUXCOEF()

#define POST_RE_INJSYS_EVERST_TAUXCOEF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveRst_TauXCorrn             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVERST_TAUXCORRN()

#define POST_RE_INJSYS_EVERST_TAUXCORRN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrM_EveRst_InjrConMdl             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRM_EVERST_INJRCONMDL()

#define POST_RE_INJRM_EVERST_INJRCONMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrM_EveRst_InjrOfsMdl             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRM_EVERST_INJROFSMDL()

#define POST_RE_INJRM_EVERST_INJROFSMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_001_MSEIf                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_001_MSEIF()

#define POST_RE_THMGT_001_MSEIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_EveRTSt_InjTiReq               */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_EVERTST_INJTIREQ()

#define POST_INJRSYS_EVERTST_INJTIREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjCrk_EveRst_PreInjTi              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJCRK_EVERST_PREINJTI()

#define POST_RE_INJCRK_EVERST_PREINJTI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjCrk_EveRst_SWInit                */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJCRK_EVERST_SWINIT()

#define POST_RE_INJCRK_EVERST_SWINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrSys_EveRst_SWInit               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRSYS_EVERST_SWINIT()

#define POST_RE_INJRSYS_EVERST_SWINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjrSys_RstRTSt_InjTiReq            */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJRSYS_RSTRTST_INJTIREQ()

#define POST_RE_INJRSYS_RSTRTST_INJTIREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TauXSp2_EveRst_SWInit               */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TAUXSP2_EVERST_SWINIT()

#define POST_RE_TAUXSP2_EVERST_SWINIT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveRst_FuCns                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVERST_FUCNS()

#define POST_FU_EVERST_FUCNS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveRst_FuLvl                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVERST_FULVL()

#define POST_FU_EVERST_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveRst_HPSensDiag                   */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVERST_HPSENSDIAG()

#define POST_FU_EVERST_HPSENSDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveRst_ExtLeakDiag                  */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVERST_EXTLEAKDIAG()

#define POST_FU_EVERST_EXTLEAKDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_EveIni_Wku                       */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_EVEINI_WKU()

#define POST_ECUST_EVEINI_WKU()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveTestEnd_IfInhThrCpuSfty         */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVETESTEND_IFINHTHRCPUSFTY()

#define POST_THR_EVETESTEND_IFINHTHRCPUSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_EveKOf_DC                           */
/*---------------------------------------------------------------------------*/
#define PRE_GD_EVEKOF_DC()

#define POST_GD_EVEKOF_DC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GOBD_vidMngEveKOf                      */
/*---------------------------------------------------------------------------*/
#define PRE_GOBD_VIDMNGEVEKOF()

#define POST_GOBD_VIDMNGEVEKOF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_EveKOf_DCIf                         */
/*---------------------------------------------------------------------------*/
#define PRE_GD_EVEKOF_DCIF()

#define POST_GD_EVEKOF_DCIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_EveKOf_AccPEM                     */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_EVEKOF_ACCPEM()

#define POST_ACCP_EVEKOF_ACCPEM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_EveKOf_DrvrSenO2Us           */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_EVEKOF_DRVRSENO2US()

#define POST_HEATSENO2_EVEKOF_DRVRSENO2US()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_EveKOf_DrvrSenO2Ds           */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_EVEKOF_DRVRSENO2DS()

#define POST_HEATSENO2_EVEKOF_DRVRSENO2DS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_EveKOf_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_EVEKOF_MNG()

#define POST_RLYPWR_EVEKOF_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrlRly_EveKOf_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRLRLY_EVEKOF_IFCMDDIAG()

#define POST_PWRLRLY_EVEKOF_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOf_InCln                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKOF_INCLN()

#define POST_VLVACT_EVEKOF_INCLN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOf_ExCln                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKOF_EXCLN()

#define POST_VLVACT_EVEKOF_EXCLN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveKOf_EngStrtStop               */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVEKOF_ENGSTRTSTOP()

#define POST_ENGST_EVEKOF_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_EveKOf_CstrMgr                    */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_EVEKOF_CSTRMGR()

#define POST_CSTR_EVEKOF_CSTRMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveKOf_FuLvl                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVEKOF_FULVL()

#define POST_FU_EVEKOF_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveKOf_EngSyncMng                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEKOF_ENGSYNCMNG()

#define POST_SYNC_EVEKOF_ENGSYNCMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_EveKOf_DiagAirExtPres          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVEKOF_DIAGAIREXTPRES()

#define POST_AIRPRES_EVEKOF_DIAGAIREXTPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_EveKOf_AvrMisfCnt                 */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_EVEKOF_AVRMISFCNT()

#define POST_MISF_EVEKOF_AVRMISFCNT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_EveKOf_EcuMng                    */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_EVEKOF_ECUMNG()

#define POST_ECUST_EVEKOF_ECUMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrRly_SdlFast_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRRLY_SDLFAST_IFCMDDIAG()

#define POST_PWRRLY_SDLFAST_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlMid_DftLiMsgMgt                 */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLMID_DFTLIMSGMGT()

#define POST_CAN_SDLMID_DFTLIMSGMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF38DIf                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF38DIF()

#define POST_CAN_SDLSLOW_FHCANF38DIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF432If                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF432IF()

#define POST_CAN_SDLSLOW_FHCANF432IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF495If                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF495IF()

#define POST_CAN_SDLSLOW_FHCANF495IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF592If                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF592IF()

#define POST_CAN_SDLSLOW_FHCANF592IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Can_SdlSlow_FHCanF612If                */
/*---------------------------------------------------------------------------*/
#define PRE_CAN_SDLSLOW_FHCANF612IF()

#define POST_CAN_SDLSLOW_FHCANF612IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AC_SdlFast_ACPresAcq                   */
/*---------------------------------------------------------------------------*/
#define PRE_AC_SDLFAST_ACPRESACQ()

#define POST_AC_SDLFAST_ACPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AC_SdlFast_ACPresAcqIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_AC_SDLFAST_ACPRESACQIF()

#define POST_AC_SDLFAST_ACPRESACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CatMdl_SdlSlow_EstimAgi                */
/*---------------------------------------------------------------------------*/
#define PRE_CATMDL_SDLSLOW_ESTIMAGI()

#define POST_CATMDL_SDLSLOW_ESTIMAGI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_SdlSlow_Mng                     */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_SDLSLOW_MNG()

#define POST_RLYPWR_SDLSLOW_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrRly_SdlSlow_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRRLY_SDLSLOW_IFCMDDIAG()

#define POST_PWRRLY_SDLSLOW_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoT_SdlMid_AcqCoT                      */
/*---------------------------------------------------------------------------*/
#define PRE_COT_SDLMID_ACQCOT()

#define POST_COT_SDLMID_ACQCOT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoFan_SdlMid_ActrTstGMV                */
/*---------------------------------------------------------------------------*/
#define PRE_COFAN_SDLMID_ACTRTSTGMV()

#define POST_COFAN_SDLMID_ACTRTSTGMV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoFan_SdlMid_CmdDiagCoFan              */
/*---------------------------------------------------------------------------*/
#define PRE_COFAN_SDLMID_CMDDIAGCOFAN()

#define POST_COFAN_SDLMID_CMDDIAGCOFAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ThMgt_SdlMid_ActrTstECT                */
/*---------------------------------------------------------------------------*/
#define PRE_THMGT_SDLMID_ACTRTSTECT()

#define POST_THMGT_SDLMID_ACTRTSTECT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoFan_SdlMid_CmdDiagCoFanIf            */
/*---------------------------------------------------------------------------*/
#define PRE_COFAN_SDLMID_CMDDIAGCOFANIF()

#define POST_COFAN_SDLMID_CMDDIAGCOFANIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlMid_ActrTstCstr                */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLMID_ACTRTSTCSTR()

#define POST_CSTR_SDLMID_ACTRTSTCSTR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlMid_CstrMgr                    */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLMID_CSTRMGR()

#define POST_CSTR_SDLMID_CSTRMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlMid_CstrDynLim                 */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLMID_CSTRDYNLIM()

#define POST_CSTR_SDLMID_CSTRDYNLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlMid_CstrCmd                    */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLMID_CSTRCMD()

#define POST_CSTR_SDLMID_CSTRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_SdlMid_IgExThermoProt            */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_SDLMID_IGEXTHERMOPROT()

#define POST_IGSYS_SDLMID_IGEXTHERMOPROT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlMid_FuCns                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLMID_FUCNS()

#define POST_FU_SDLMID_FUCNS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlMid_FuLvl                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLMID_FULVL()

#define POST_FU_SDLMID_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_SdlMid_ExtLeakDiag                  */
/*---------------------------------------------------------------------------*/
#define PRE_FU_SDLMID_EXTLEAKDIAG()

#define POST_FU_SDLMID_EXTLEAKDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_SdlMid_FisaInhMgr                 */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_SDLMID_FISAINHMGR()

#define POST_FISA_SDLMID_FISAINHMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_UsMgr                 */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_USMGR()

#define POST_HEATSENO2_SDLMID_USMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_DsMgr                 */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_DSMGR()

#define POST_HEATSENO2_SDLMID_DSMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_UsCmd                 */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_USCMD()

#define POST_HEATSENO2_SDLMID_USCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_DsCmd                 */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_DSCMD()

#define POST_HEATSENO2_SDLMID_DSCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_HotSenO2Flg           */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_HOTSENO2FLG()

#define POST_HEATSENO2_SDLMID_HOTSENO2FLG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlMid_ReqAdjVltCtl          */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLMID_REQADJVLTCTL()

#define POST_HEATSENO2_SDLMID_REQADJVLTCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCtl_SdlMid_InjFarCtlDsCtl           */
/*---------------------------------------------------------------------------*/
#define PRE_INJCTL_SDLMID_INJFARCTLDSCTL()

#define POST_INJCTL_SDLMID_INJFARCTLDSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Mux_SdlMid_MuxDiagOn                   */
/*---------------------------------------------------------------------------*/
#define PRE_MUX_SDLMID_MUXDIAGON()

#define POST_MUX_SDLMID_MUXDIAGON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlMid_FlowMngTAir                  */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLMID_FLOWMNGTAIR()

#define POST_CF_SDLMID_FLOWMNGTAIR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlMid_FlowMngTOil                  */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLMID_FLOWMNGTOIL()

#define POST_CF_SDLMID_FLOWMNGTOIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlMid_FlowMngGmv                   */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLMID_FLOWMNGGMV()

#define POST_CF_SDLMID_FLOWMNGGMV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlMid_FlowMngIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLMID_FLOWMNGIF()

#define POST_CF_SDLMID_FLOWMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CONFIGLIN_vidMngSch_100MS              */
/*---------------------------------------------------------------------------*/
#define PRE_CONFIGLIN_VIDMNGSCH_100MS()

#define POST_CONFIGLIN_VIDMNGSCH_100MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Eng_Sdl100ms_tOilEstim                 */
/*---------------------------------------------------------------------------*/
#define PRE_ENG_SDL100MS_TOILESTIM()

#define POST_ENG_SDL100MS_TOILESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable OilSys_SdlMid_OilDsp                   */
/*---------------------------------------------------------------------------*/
#define PRE_OILSYS_SDLMID_OILDSP()

#define POST_OILSYS_SDLMID_OILDSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Eng_Sdl100ms_tOilEstimIf               */
/*---------------------------------------------------------------------------*/
#define PRE_ENG_SDL100MS_TOILESTIMIF()

#define POST_ENG_SDL100MS_TOILESTIMIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_SdlSlow_PropFuPmp                */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_SDLSLOW_PROPFUPMP()

#define POST_FUPMP_SDLSLOW_PROPFUPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CTP_SdlMid_ActrTstCTP                  */
/*---------------------------------------------------------------------------*/
#define PRE_CTP_SDLMID_ACTRTSTCTP()

#define POST_CTP_SDLMID_ACTRTSTCTP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AC_SdlSlow_AdHeatCmd                   */
/*---------------------------------------------------------------------------*/
#define PRE_AC_SDLSLOW_ADHEATCMD()

#define POST_AC_SDLSLOW_ADHEATCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CcpDaqListSetEvent_Medium              */
/*---------------------------------------------------------------------------*/
#define PRE_CCPDAQLISTSETEVENT_MEDIUM()

#define POST_CCPDAQLISTSETEVENT_MEDIUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FHCAN_EveSdl100ms                      */
/*---------------------------------------------------------------------------*/
#define PRE_FHCAN_EVESDL100MS()

#define POST_FHCAN_EVESDL100MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlSlow_CmCkMon                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLSLOW_CMCKMON()

#define POST_SYNC_SDLSLOW_CMCKMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlSlow_MonEngSpd                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLSLOW_MONENGSPD()

#define POST_SYNC_SDLSLOW_MONENGSPD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlSlow_NEngClc                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLSLOW_NENGCLC()

#define POST_SYNC_SDLSLOW_NENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_Sdl40ms_IfTMS                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDL40MS_IFTMS()

#define POST_SFTYMGT_SDL40MS_IFTMS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_bInjCutOff              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_BINJCUTOFF()

#define POST_SFTYMGT_SDLMID_BINJCUTOFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_bEnaTqOfs               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_BENATQOFS()

#define POST_SFTYMGT_SDLMID_BENATQOFS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_LiHChk                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_LIHCHK()

#define POST_SFTYMGT_SDLMID_LIHCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_STTDrvTra               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_STTDRVTRA()

#define POST_SFTYMGT_SDLMID_STTDRVTRA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqAuxSumLoss            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQAUXSUMLOSS()

#define POST_SFTYMGT_SDLMID_TQAUXSUMLOSS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCkFricLoss            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCKFRICLOSS()

#define POST_SFTYMGT_SDLMID_TQCKFRICLOSS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCkEngLossAdp          */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCKENGLOSSADP()

#define POST_SFTYMGT_SDLMID_TQCKENGLOSSADP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCnvLoss               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCNVLOSS()

#define POST_SFTYMGT_SDLMID_TQCNVLOSS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqSumLossCord           */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQSUMLOSSCORD()

#define POST_SFTYMGT_SDLMID_TQSUMLOSSCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqSumLossCmp            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQSUMLOSSCMP()

#define POST_SFTYMGT_SDLMID_TQSUMLOSSCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_nTarIdlChk              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_NTARIDLCHK()

#define POST_SFTYMGT_SDLMID_NTARIDLCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_Sdl40ms_tqCkEfc                */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDL40MS_TQCKEFC()

#define POST_SFTYMGT_SDL40MS_TQCKEFC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_TqVSCtlChk              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQVSCTLCHK()

#define POST_SFTYMGT_SDLMID_TQVSCTLCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCoVSCtl               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCOVSCTL()

#define POST_SFTYMGT_SDLMID_TQCOVSCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCkEfcFil              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCKEFCFIL()

#define POST_SFTYMGT_SDLMID_TQCKEFCFIL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqEfcFilCo              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQEFCFILCO()

#define POST_SFTYMGT_SDLMID_TQEFCFILCO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqEfcReqCoCha           */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQEFCREQCOCHA()

#define POST_SFTYMGT_SDLMID_TQEFCREQCOCHA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_Sdl40ms_GBxChk                 */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDL40MS_GBXCHK()

#define POST_SFTYMGT_SDL40MS_GBXCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqEfcCoGBx              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQEFCCOGBX()

#define POST_SFTYMGT_SDLMID_TQEFCCOGBX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqIdcCoGBx              */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQIDCCOGBX()

#define POST_SFTYMGT_SDLMID_TQIDCCOGBX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqIdcCoNReg             */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQIDCCONREG()

#define POST_SFTYMGT_SDLMID_TQIDCCONREG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_nOfsIdlTakeOff          */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_NOFSIDLTAKEOFF()

#define POST_SFTYMGT_SDLMID_NOFSIDLTAKEOFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqIdl                   */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQIDL()

#define POST_SFTYMGT_SDLMID_TQIDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_IdlChk                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_IDLCHK()

#define POST_SFTYMGT_SDLMID_IDLCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqIdcEngLimCo           */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQIDCENGLIMCO()

#define POST_SFTYMGT_SDLMID_TQIDCENGLIMCO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_pDsThrChk               */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_PDSTHRCHK()

#define POST_SFTYMGT_SDLMID_PDSTHRCHK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqIdcEngReal            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQIDCENGREAL()

#define POST_SFTYMGT_SDLMID_TQIDCENGREAL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqCkEngLimCord          */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCKENGLIMCORD()

#define POST_SFTYMGT_SDLMID_TQCKENGLIMCORD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_tqComp                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_TQCOMP()

#define POST_SFTYMGT_SDLMID_TQCOMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_DftMgt                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_DFTMGT()

#define POST_SFTYMGT_SDLMID_DFTMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_FrfGen                  */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_FRFGEN()

#define POST_SFTYMGT_SDLMID_FRFGEN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_SftyMgr                 */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_SFTYMGR()

#define POST_SFTYMGT_SDLMID_SFTYMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_IfSftyMgtSTT            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_IFSFTYMGTSTT()

#define POST_SFTYMGT_SDLMID_IFSFTYMGTSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_ifTqMon                 */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_IFTQMON()

#define POST_SFTYMGT_SDLMID_IFTQMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sfty_SdlMid_PfcMng                     */
/*---------------------------------------------------------------------------*/
#define PRE_SFTY_SDLMID_PFCMNG()

#define POST_SFTY_SDLMID_PFCMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SftyMgt_SdlMid_DiagSftyLvl2            */
/*---------------------------------------------------------------------------*/
#define PRE_SFTYMGT_SDLMID_DIAGSFTYLVL2()

#define POST_SFTYMGT_SDLMID_DIAGSFTYLVL2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_SdlMid_HPPmpCtl                 */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_SDLMID_HPPMPCTL()

#define POST_PFUCTL_SDLMID_HPPMPCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PFuCtl_SdlMid_HPPmpActCmd              */
/*---------------------------------------------------------------------------*/
#define PRE_PFUCTL_SDLMID_HPPMPACTCMD()

#define POST_PFUCTL_SDLMID_HPPMPACTCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Misf_SdlMid_MisfDiagStabCdn            */
/*---------------------------------------------------------------------------*/
#define PRE_MISF_SDLMID_MISFDIAGSTABCDN()

#define POST_MISF_SDLMID_MISFDIAGSTABCDN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CatMon_SdlMid_CatMonIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_CATMON_SDLMID_CATMONIF()

#define POST_CATMON_SDLMID_CATMONIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable StraMon_SdlMid_FarStraMon              */
/*---------------------------------------------------------------------------*/
#define PRE_STRAMON_SDLMID_FARSTRAMON()

#define POST_STRAMON_SDLMID_FARSTRAMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlSfty_BrkAsiAcq              */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLSFTY_BRKASIACQ()

#define POST_AIRPRES_SDLSFTY_BRKASIACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlSfty_RelBrkAsiAcq           */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLSFTY_RELBRKASIACQ()

#define POST_AIRPRES_SDLSFTY_RELBRKASIACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlSfty_ThrPosnMes                 */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLSFTY_THRPOSNMES()

#define POST_THR_SDLSFTY_THRPOSNMES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable NeutPosnAcq_SdlSfty_SftyLvl2           */
/*---------------------------------------------------------------------------*/
#define PRE_NEUTPOSNACQ_SDLSFTY_SFTYLVL2()

#define POST_NEUTPOSNACQ_SDLSFTY_SFTYLVL2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_SdlSfty_rCluPedPrssMes             */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_SDLSFTY_RCLUPEDPRSSMES()

#define POST_CLU_SDLSFTY_RCLUPEDPRSSMES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlSfty_BrkPed                     */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLSFTY_BRKPED()

#define POST_BRK_SDLSFTY_BRKPED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Brk_SdlSfty_BrkPedBVH2p                */
/*---------------------------------------------------------------------------*/
#define PRE_BRK_SDLSFTY_BRKPEDBVH2P()

#define POST_BRK_SDLSFTY_BRKPEDBVH2P()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlMid_VehMux                   */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLMID_VEHMUX()

#define POST_VEHSPD_SDLMID_VEHMUX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlMid_VehMng                   */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLMID_VEHMNG()

#define POST_VEHSPD_SDLMID_VEHMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_SdlSfty_MonVehSpd               */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_SDLSFTY_MONVEHSPD()

#define POST_VEHSPD_SDLSFTY_MONVEHSPD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ASIC_SdlFast_diagasicgdi               */
/*---------------------------------------------------------------------------*/
#define PRE_ASIC_SDLFAST_DIAGASICGDI()

#define POST_ASIC_SDLFAST_DIAGASICGDI()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_EveInj_BattVotlAcq                 */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_EVEINJ_BATTVOTLACQ()

#define POST_PWR_EVEINJ_BATTVOTLACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuAcq_EveInj_PFuAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_FUACQ_EVEINJ_PFUACQ()

#define POST_FUACQ_EVEINJ_PFUACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_facFuTranIf              */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_FACFUTRANIF()

#define POST_INJSYS_EVEINJ_FACFUTRANIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCutOff_EveInj_CutOff                */
/*---------------------------------------------------------------------------*/
#define PRE_INJCUTOFF_EVEINJ_CUTOFF()

#define POST_INJCUTOFF_EVEINJ_CUTOFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_InjSysMgrCrk             */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_INJSYSMGRCRK()

#define POST_INJSYS_EVEINJ_INJSYSMGRCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_mFuSpCrk                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_MFUSPCRK()

#define POST_INJSYS_EVEINJ_MFUSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_InjAstWupCmp             */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_INJASTWUPCMP()

#define POST_INJSYS_EVEINJ_INJASTWUPCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_InjResuCmp               */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_INJRESUCMP()

#define POST_INJSYS_EVEINJ_INJRESUCMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_FacFuTran                */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_FACFUTRAN()

#define POST_INJSYS_EVEINJ_FACFUTRAN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_mFuSp                    */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_MFUSP()

#define POST_INJSYS_EVEINJ_MFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_InjSpMgt                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_INJSPMGT()

#define POST_INJSYS_EVEINJ_INJSPMGT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_stTypElCmdInjr           */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_STTYPELCMDINJR()

#define POST_INJSYS_EVEINJ_STTYPELCMDINJR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_mFuInj                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_MFUINJ()

#define POST_INJSYS_EVEINJ_MFUINJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CylM_EveInj_pCylM                      */
/*---------------------------------------------------------------------------*/
#define PRE_CYLM_EVEINJ_PCYLM()

#define POST_CYLM_EVEINJ_PCYLM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_EveInj_agPmpRefPFuM             */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_EVEINJ_AGPMPREFPFUM()

#define POST_FUSYSM_EVEINJ_AGPMPREFPFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuSysM_EveInj_pFuM                     */
/*---------------------------------------------------------------------------*/
#define PRE_FUSYSM_EVEINJ_PFUM()

#define POST_FUSYSM_EVEINJ_PFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveInj_InjrPrmMdl                */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVEINJ_INJRPRMMDL()

#define POST_INJRM_EVEINJ_INJRPRMMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveInj_InjrMdl                   */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVEINJ_INJRMDL()

#define POST_INJRM_EVEINJ_INJRMDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrSys_EveInj_tiFuSp                  */
/*---------------------------------------------------------------------------*/
#define PRE_INJRSYS_EVEINJ_TIFUSP()

#define POST_INJRSYS_EVEINJ_TIFUSP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveInj_mFuInjIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEINJ_MFUINJIF()

#define POST_INJSYS_EVEINJ_MFUINJIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjrM_EveInj_InjrMdlIf                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJRM_EVEINJ_INJRMDLIF()

#define POST_INJRM_EVEINJ_INJRMDLIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCutOff_EveInj_CutOffIf              */
/*---------------------------------------------------------------------------*/
#define PRE_INJCUTOFF_EVEINJ_CUTOFFIF()

#define POST_INJCUTOFF_EVEINJ_CUTOFFIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Volt_EveInj_InjVoltAdj                 */
/*---------------------------------------------------------------------------*/
#define PRE_VOLT_EVEINJ_INJVOLTADJ()

#define POST_VOLT_EVEINJ_INJVOLTADJ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveInj_FuCns                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVEINJ_FUCNS()

#define POST_FU_EVEINJ_FUCNS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GDGAR_EveKeyOn                         */
/*---------------------------------------------------------------------------*/
#define PRE_GDGAR_EVEKEYON()

#define POST_GDGAR_EVEKEYON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_ExAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_EXACQ()

#define POST_VLVACT_EVEKON_EXACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_ExEndStop                */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_EXENDSTOP()

#define POST_VLVACT_EVEKON_EXENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_ExServo                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_EXSERVO()

#define POST_VLVACT_EVEKON_EXSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_InAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_INACQ()

#define POST_VLVACT_EVEKON_INACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_InEndStop                */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_INENDSTOP()

#define POST_VLVACT_EVEKON_INENDSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VlvAct_EveKOn_InServo                  */
/*---------------------------------------------------------------------------*/
#define PRE_VLVACT_EVEKON_INSERVO()

#define POST_VLVACT_EVEKON_INSERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Clu_EveKOn_CluSwtDiag                  */
/*---------------------------------------------------------------------------*/
#define PRE_CLU_EVEKON_CLUSWTDIAG()

#define POST_CLU_EVEKON_CLUSWTDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fu_EveKOn_FuLvl                        */
/*---------------------------------------------------------------------------*/
#define PRE_FU_EVEKON_FULVL()

#define POST_FU_EVEKON_FULVL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Fisa_EveKOn_FisaRFuDet                 */
/*---------------------------------------------------------------------------*/
#define PRE_FISA_EVEKON_FISARFUDET()

#define POST_FISA_EVEKON_FISARFUDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveKOn_EngStrtStop               */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVEKON_ENGSTRTSTOP()

#define POST_ENGST_EVEKON_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EcuSt_EveKOn_EcuMng                    */
/*---------------------------------------------------------------------------*/
#define PRE_ECUST_EVEKON_ECUMNG()

#define POST_ECUST_EVEKON_ECUMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveKOn_VehSt                     */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVEKON_VEHST()

#define POST_ENGST_EVEKON_VEHST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_EveKOn_EngrunSt                  */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_EVEKON_ENGRUNST()

#define POST_ENGST_EVEKON_ENGRUNST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_FuPmp_EveKOn_Mng                    */
/*---------------------------------------------------------------------------*/
#define PRE_CF_FUPMP_EVEKON_MNG()

#define POST_CF_FUPMP_EVEKON_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjSys_EveKOn_mFuSpCrk                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEKON_MFUSPCRK()

#define POST_INJSYS_EVEKON_MFUSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrlRly_EveKOn_IfCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_PWRLRLY_EVEKON_IFCMDDIAG()

#define POST_PWRLRLY_EVEKON_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RlyPwr_EveKOn_Mng                      */
/*---------------------------------------------------------------------------*/
#define PRE_RLYPWR_EVEKON_MNG()

#define POST_RLYPWR_EVEKON_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Injsys_EveKOn_mFuSpCrk                 */
/*---------------------------------------------------------------------------*/
#define PRE_INJSYS_EVEKON_MFUSPCRK()

#define POST_INJSYS_EVEKON_MFUSPCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable PwrRly_EveKOn_IfCmdDiag                */
/*---------------------------------------------------------------------------*/
#define PRE_PWRRLY_EVEKON_IFCMDDIAG()

#define POST_PWRRLY_EVEKON_IFCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable FuPmp_EveKOn_Mng                       */
/*---------------------------------------------------------------------------*/
#define PRE_FUPMP_EVEKON_MNG()

#define POST_FUPMP_EVEKON_MNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCrk_EveKOn_AntiFlood                */
/*---------------------------------------------------------------------------*/
#define PRE_INJCRK_EVEKON_ANTIFLOOD()

#define POST_INJCRK_EVEKON_ANTIFLOOD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InjCrk_EveKOn_AntiFloodIf              */
/*---------------------------------------------------------------------------*/
#define PRE_INJCRK_EVEKON_ANTIFLOODIF()

#define POST_INJCRK_EVEKON_ANTIFLOODIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveKOn_EngSyncMng                 */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEKON_ENGSYNCMNG()

#define POST_SYNC_EVEKON_ENGSYNCMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveKOn_InCmSts                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEKON_INCMSTS()

#define POST_SYNC_EVEKON_INCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveKOn_ExCmSts                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEKON_EXCMSTS()

#define POST_SYNC_EVEKON_EXCMSTS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveKOn_CmCkMon                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEKON_CMCKMON()

#define POST_SYNC_EVEKON_CMCKMON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_EveKOn_DiagAirExtPres          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVEKON_DIAGAIREXTPRES()

#define POST_AIRPRES_EVEKON_DIAGAIREXTPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Inj_EveCkOff_InjCmd                    */
/*---------------------------------------------------------------------------*/
#define PRE_INJ_EVECKOFF_INJCMD()

#define POST_INJ_EVECKOFF_INJCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkOf_CkMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKOF_CKMNGIF()

#define POST_SYNC_EVECKOF_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkOff_SyncSTT                  */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKOFF_SYNCSTT()

#define POST_SYNC_EVECKOFF_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveInCamEdge_SyncSTT              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEINCAMEDGE_SYNCSTT()

#define POST_SYNC_EVEINCAMEDGE_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveExCamEdge_SyncSTT              */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEEXCAMEDGE_SYNCSTT()

#define POST_SYNC_EVEEXCAMEDGE_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveNInvOff_SyncSTT                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVENINVOFF_SYNCSTT()

#define POST_SYNC_EVENINVOFF_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GDU_vidSdlSlow                         */
/*---------------------------------------------------------------------------*/
#define PRE_GDU_VIDSDLSLOW()

#define POST_GDU_VIDSDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable WUC_vidMngEveSldSlow                   */
/*---------------------------------------------------------------------------*/
#define PRE_WUC_VIDMNGEVESLDSLOW()

#define POST_WUC_VIDMNGEVESLDSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GOBD_vidMngEveSldSlow                  */
/*---------------------------------------------------------------------------*/
#define PRE_GOBD_VIDMNGEVESLDSLOW()

#define POST_GOBD_VIDMNGEVESLDSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GMIL_vidMngEveSldSlow                  */
/*---------------------------------------------------------------------------*/
#define PRE_GMIL_VIDMNGEVESLDSLOW()

#define POST_GMIL_VIDMNGEVESLDSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable GD_SdlSlow_DiagTab                     */
/*---------------------------------------------------------------------------*/
#define PRE_GD_SDLSLOW_DIAGTAB()

#define POST_GD_SDLSLOW_DIAGTAB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DGOTEST_vidSdlSlow                     */
/*---------------------------------------------------------------------------*/
#define PRE_DGOTEST_VIDSDLSLOW()

#define POST_DGOTEST_VIDSDLSLOW()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkLTo_SyncCkDiagDiag           */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKLTO_SYNCCKDIAGDIAG()

#define POST_SYNC_EVECKLTO_SYNCCKDIAGDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveCkLTo_SyncSTT                  */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVECKLTO_SYNCSTT()

#define POST_SYNC_EVECKLTO_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Pwr_SdlFast_Acq                        */
/*---------------------------------------------------------------------------*/
#define PRE_PWR_SDLFAST_ACQ()

#define POST_PWR_SDLFAST_ACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_PosnMes               */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_POSNMES()

#define POST_THR_EVECLCNSERVO_POSNMES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_mCut                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_MCUT()

#define POST_THR_EVECLCNSERVO_MCUT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_StopClcn              */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_STOPCLCN()

#define POST_THR_EVECLCNSERVO_STOPCLCN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_SecuMng               */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_SECUMNG()

#define POST_THR_EVECLCNSERVO_SECUMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_CorrdPosn             */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_CORRDPOSN()

#define POST_THR_EVECLCNSERVO_CORRDPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_Servo                 */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_SERVO()

#define POST_THR_EVECLCNSERVO_SERVO()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_ThermoProt            */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_THERMOPROT()

#define POST_THR_EVECLCNSERVO_THERMOPROT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_ThrCmd                */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_THRCMD()

#define POST_THR_EVECLCNSERVO_THRCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_Diag                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_DIAG()

#define POST_THR_EVECLCNSERVO_DIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_ThrSftyMng            */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_THRSFTYMNG()

#define POST_THR_EVECLCNSERVO_THRSFTYMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveClcnServo_CorrdPosnIf2          */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVECLCNSERVO_CORRDPOSNIF2()

#define POST_THR_EVECLCNSERVO_CORRDPOSNIF2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Oil_Eve14TDC_OilPropPresAcq            */
/*---------------------------------------------------------------------------*/
#define PRE_OIL_EVE14TDC_OILPROPPRESACQ()

#define POST_OIL_EVE14TDC_OILPROPPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_Eve14TDC_InMnfPresAcq          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVE14TDC_INMNFPRESACQ()

#define POST_AIRPRES_EVE14TDC_INMNFPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_Eve14TDC_SpgPresAcq            */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVE14TDC_SPGPRESACQ()

#define POST_AIRPRES_EVE14TDC_SPGPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_Eve14TDC_DiagTrbPres           */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVE14TDC_DIAGTRBPRES()

#define POST_AIRPRES_EVE14TDC_DIAGTRBPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_Eve14TDC_SpgPresAcqif          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_EVE14TDC_SPGPRESACQIF()

#define POST_AIRPRES_EVE14TDC_SPGPRESACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_Eve14TDC_ObdSrvPid                 */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_EVE14TDC_OBDSRVPID()

#define POST_SRV_EVE14TDC_OBDSRVPID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable DmpVlv_Eve14TDC_FctDiagDmpVlv          */
/*---------------------------------------------------------------------------*/
#define PRE_DMPVLV_EVE14TDC_FCTDIAGDMPVLV()

#define POST_DMPVLV_EVE14TDC_FCTDIAGDMPVLV()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlSlow_EngStrtStop              */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLSLOW_ENGSTRTSTOP()

#define POST_ENGST_SDLSLOW_ENGSTRTSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlSlow_TiEngStop                */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLSLOW_TIENGSTOP()

#define POST_ENGST_SDLSLOW_TIENGSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_FuSysM_SdlSlow_TFuM                 */
/*---------------------------------------------------------------------------*/
#define PRE_RE_FUSYSM_SDLSLOW_TFUM()

#define POST_RE_FUSYSM_SDLSLOW_TFUM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlSlow_EngStrtStopIf            */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLSLOW_ENGSTRTSTOPIF()

#define POST_ENGST_SDLSLOW_ENGSTRTSTOPIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoT_SdlSlow_FctDiagCoT                 */
/*---------------------------------------------------------------------------*/
#define PRE_COT_SDLSLOW_FCTDIAGCOT()

#define POST_COT_SDLSLOW_FCTDIAGCOT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable MEAP_SdlMid_ActrTstMEAP                */
/*---------------------------------------------------------------------------*/
#define PRE_MEAP_SDLMID_ACTRTSTMEAP()

#define POST_MEAP_SDLMID_ACTRTSTMEAP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CoFan_SdlSlow_ECTReq                   */
/*---------------------------------------------------------------------------*/
#define PRE_COFAN_SDLSLOW_ECTREQ()

#define POST_COFAN_SDLSLOW_ECTREQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ThMgt_002_TEVIf                     */
/*---------------------------------------------------------------------------*/
#define PRE_RE_THMGT_002_TEVIF()

#define POST_RE_THMGT_002_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlSlow_FuConcEstim               */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLSLOW_FUCONCESTIM()

#define POST_CSTR_SDLSLOW_FUCONCESTIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cstr_SdlSlow_CstrEfcRed                */
/*---------------------------------------------------------------------------*/
#define PRE_CSTR_SDLSLOW_CSTREFCRED()

#define POST_CSTR_SDLSLOW_CSTREFCRED()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Cf_SdlSlow_IfAirSys                    */
/*---------------------------------------------------------------------------*/
#define PRE_CF_SDLSLOW_IFAIRSYS()

#define POST_CF_SDLSLOW_IFAIRSYS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AC_SdlSlow_AdHeatCmdDiag               */
/*---------------------------------------------------------------------------*/
#define PRE_AC_SDLSLOW_ADHEATCMDDIAG()

#define POST_AC_SDLSLOW_ADHEATCMDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SAIMMO_SdlMid                          */
/*---------------------------------------------------------------------------*/
#define PRE_SAIMMO_SDLMID()

#define POST_SAIMMO_SDLMID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenAct_SdlMid_tECUAcq                  */
/*---------------------------------------------------------------------------*/
#define PRE_SENACT_SDLMID_TECUACQ()

#define POST_SENACT_SDLMID_TECUACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenAct_SdlMid_tECUAcqIf                */
/*---------------------------------------------------------------------------*/
#define PRE_SENACT_SDLMID_TECUACQIF()

#define POST_SENACT_SDLMID_TECUACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlMid_VehSt                     */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLMID_VEHST()

#define POST_ENGST_SDLMID_VEHST()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlMid_EngStab                   */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLMID_ENGSTAB()

#define POST_ENGST_SDLMID_ENGSTAB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngSt_SdlMid_TiEngStop                 */
/*---------------------------------------------------------------------------*/
#define PRE_ENGST_SDLMID_TIENGSTOP()

#define POST_ENGST_SDLMID_TIENGSTOP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AccP_SdlSlow_FLrng                     */
/*---------------------------------------------------------------------------*/
#define PRE_ACCP_SDLSLOW_FLRNG()

#define POST_ACCP_SDLSLOW_FLRNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlSlow_AbsSpPosn                  */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLSLOW_ABSSPPOSN()

#define POST_THR_SDLSLOW_ABSSPPOSN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AC_SdlMid_ACPresAcq                    */
/*---------------------------------------------------------------------------*/
#define PRE_AC_SDLMID_ACPRESACQ()

#define POST_AC_SDLMID_ACPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlSlow_KnkDetRbl             */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLSLOW_KNKDETRBL()

#define POST_KNKTREAT_SDLSLOW_KNKDETRBL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlSlow_KnkDet                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLSLOW_KNKDET()

#define POST_KNKTREAT_SDLSLOW_KNKDET()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlSlow_NoiseAdp              */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLSLOW_NOISEADP()

#define POST_KNKTREAT_SDLSLOW_NOISEADP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgLim_SdlSlow_KnkAdpCor                */
/*---------------------------------------------------------------------------*/
#define PRE_IGLIM_SDLSLOW_KNKADPCOR()

#define POST_IGLIM_SDLSLOW_KNKADPCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ISLIN_vidSdlMid                        */
/*---------------------------------------------------------------------------*/
#define PRE_ISLIN_VIDSDLMID()

#define POST_ISLIN_VIDSDLMID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CLUPEDPOSNDIAG_vidEntry_100ms          */
/*---------------------------------------------------------------------------*/
#define PRE_CLUPEDPOSNDIAG_VIDENTRY_100MS()

#define POST_CLUPEDPOSNDIAG_VIDENTRY_100MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirT_SdlMid_AcqAirT                    */
/*---------------------------------------------------------------------------*/
#define PRE_AIRT_SDLMID_ACQAIRT()

#define POST_AIRT_SDLMID_ACQAIRT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirT_SdlMid_AcqAirTIfAir               */
/*---------------------------------------------------------------------------*/
#define PRE_AIRT_SDLMID_ACQAIRTIFAIR()

#define POST_AIRT_SDLMID_ACQAIRTIFAIR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirT_SdlMid_AcqAirTIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_AIRT_SDLMID_ACQAIRTIF()

#define POST_AIRT_SDLMID_ACQAIRTIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirT_SdlMid_MonAirT                    */
/*---------------------------------------------------------------------------*/
#define PRE_AIRT_SDLMID_MONAIRT()

#define POST_AIRT_SDLMID_MONAIRT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlSlow_AirExtPresAcq          */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLSLOW_AIREXTPRESACQ()

#define POST_AIRPRES_SDLSLOW_AIREXTPRESACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlSlow_DiagAirExtPres         */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLSLOW_DIAGAIREXTPRES()

#define POST_AIRPRES_SDLSLOW_DIAGAIREXTPRES()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirPres_SdlSlow_AirExtPresAcqIf        */
/*---------------------------------------------------------------------------*/
#define PRE_AIRPRES_SDLSLOW_AIREXTPRESACQIF()

#define POST_AIRPRES_SDLSLOW_AIREXTPRESACQIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TPM_008_TEVIf                       */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TPM_008_TEVIF()

#define POST_RE_TPM_008_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngReqH_SdlMid_EngReqH                 */
/*---------------------------------------------------------------------------*/
#define PRE_ENGREQH_SDLMID_ENGREQH()

#define POST_ENGREQH_SDLMID_ENGREQH()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable STT_SdlMid_SpySTT                      */
/*---------------------------------------------------------------------------*/
#define PRE_STT_SDLMID_SPYSTT()

#define POST_STT_SDLMID_SPYSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable STT_SdlMid_SpyEmSTT                    */
/*---------------------------------------------------------------------------*/
#define PRE_STT_SDLMID_SPYEMSTT()

#define POST_STT_SDLMID_SPYEMSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlMid_ObdSrvPid                   */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLMID_OBDSRVPID()

#define POST_SRV_SDLMID_OBDSRVPID()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlMid_ObdSrv06                    */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLMID_OBDSRV06()

#define POST_SRV_SDLMID_OBDSRV06()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ThMgt_SdlMid_ActrTstTrbWaPmp           */
/*---------------------------------------------------------------------------*/
#define PRE_THMGT_SDLMID_ACTRTSTTRBWAPMP()

#define POST_THMGT_SDLMID_ACTRTSTTRBWAPMP()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable CCP_vidMainFunction                    */
/*---------------------------------------------------------------------------*/
#define PRE_CCP_VIDMAINFUNCTION()

#define POST_CCP_VIDMAINFUNCTION()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable InM_SdlFast_stTraLd                    */
/*---------------------------------------------------------------------------*/
#define PRE_INM_SDLFAST_STTRALD()

#define POST_INM_SDLFAST_STTRALD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMaxT_002_DREIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMAXT_002_DREIF()

#define POST_RE_ADVMAXT_002_DREIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TQESTMAX_TqSys_EveSync                 */
/*---------------------------------------------------------------------------*/
#define PRE_TQESTMAX_TQSYS_EVESYNC()

#define POST_TQESTMAX_TQSYS_EVESYNC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_EveSync_SBPA                     */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_EVESYNC_SBPA()

#define POST_TQSYS_EVESYNC_SBPA()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IdlSys_EveSync_GslIdlCtl               */
/*---------------------------------------------------------------------------*/
#define PRE_IDLSYS_EVESYNC_GSLIDLCTL()

#define POST_IDLSYS_EVESYNC_GSLIDLCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IdlSys_EveSync_bAcvIdlCtl              */
/*---------------------------------------------------------------------------*/
#define PRE_IDLSYS_EVESYNC_BACVIDLCTL()

#define POST_IDLSYS_EVESYNC_BACVIDLCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IdlSys_EveSync_tqIdcIdl                */
/*---------------------------------------------------------------------------*/
#define PRE_IDLSYS_EVESYNC_TQIDCIDL()

#define POST_IDLSYS_EVESYNC_TQIDCIDL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IdlSys_EveSync_AntiStall               */
/*---------------------------------------------------------------------------*/
#define PRE_IDLSYS_EVESYNC_ANTISTALL()

#define POST_IDLSYS_EVESYNC_ANTISTALL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IdlSys_EveSync_bInjCutOff              */
/*---------------------------------------------------------------------------*/
#define PRE_IDLSYS_EVESYNC_BINJCUTOFF()

#define POST_IDLSYS_EVESYNC_BINJCUTOFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_IdlCordLimIf          */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_IDLCORDLIMIF()

#define POST_RE_TQSYS_EVESYNC_IDLCORDLIMIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_TqSys_EveSync_CurCorIf              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_TQSYS_EVESYNC_CURCORIF()

#define POST_RE_TQSYS_EVESYNC_CURCORIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_EveTDC_TqSysIdc                  */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_EVETDC_TQSYSIDC()

#define POST_TQSYS_EVETDC_TQSYSIDC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveBDC_IgCrk                     */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVEBDC_IGCRK()

#define POST_IGSYS_EVEBDC_IGCRK()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveBDC_IgArb                     */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVEBDC_IGARB()

#define POST_IGSYS_EVEBDC_IGARB()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveBDC_IgExThermoProt            */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVEBDC_IGEXTHERMOPROT()

#define POST_IGSYS_EVEBDC_IGEXTHERMOPROT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VidMainFunction_StackCom_2_5MS         */
/*---------------------------------------------------------------------------*/
#define PRE_VIDMAINFUNCTION_STACKCOM_2_5MS()

#define POST_VIDMAINFUNCTION_STACKCOM_2_5MS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable VehSpd_EveVSTop_AcqVehSpdSen           */
/*---------------------------------------------------------------------------*/
#define PRE_VEHSPD_EVEVSTOP_ACQVEHSPDSEN()

#define POST_VEHSPD_EVEVSTOP_ACQVEHSPDSEN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlFast_DsLsAcq                */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLFAST_DSLSACQ()

#define POST_SENO2DS_SDLFAST_DSLSACQ()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable SenO2Ds_SdlFast_SigGrdDiag             */
/*---------------------------------------------------------------------------*/
#define PRE_SENO2DS_SDLFAST_SIGGRDDIAG()

#define POST_SENO2DS_SDLFAST_SIGGRDDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_ActrTSO2Us           */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_ACTRTSO2US()

#define POST_HEATSENO2_SDLFAST_ACTRTSO2US()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_ActrTSO2Ds           */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_ACTRTSO2DS()

#define POST_HEATSENO2_SDLFAST_ACTRTSO2DS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_UsMgr                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_USMGR()

#define POST_HEATSENO2_SDLFAST_USMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_DsMgr                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_DSMGR()

#define POST_HEATSENO2_SDLFAST_DSMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_UsCmd                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_USCMD()

#define POST_HEATSENO2_SDLFAST_USCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_DsCmd                */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_DSCMD()

#define POST_HEATSENO2_SDLFAST_DSCMD()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_DrvrSenO2Us          */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_DRVRSENO2US()

#define POST_HEATSENO2_SDLFAST_DRVRSENO2US()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_DrvrSenO2Ds          */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_DRVRSENO2DS()

#define POST_HEATSENO2_SDLFAST_DRVRSENO2DS()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_HeatSenO2Mon         */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_HEATSENO2MON()

#define POST_HEATSENO2_SDLFAST_HEATSENO2MON()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable HeatSenO2_SdlFast_HeatSenO2MonIf       */
/*---------------------------------------------------------------------------*/
#define PRE_HEATSENO2_SDLFAST_HEATSENO2MONIF()

#define POST_HEATSENO2_SDLFAST_HEATSENO2MONIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveBDC_CkMngIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEBDC_CKMNGIF()

#define POST_SYNC_EVEBDC_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveBDC_IfNEngClc                  */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEBDC_IFNENGCLC()

#define POST_SYNC_EVEBDC_IFNENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveBDC_NEngClc                    */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEBDC_NENGCLC()

#define POST_SYNC_EVEBDC_NENGCLC()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgCmd_EveBDC_MisfGenr                  */
/*---------------------------------------------------------------------------*/
#define PRE_IGCMD_EVEBDC_MISFGENR()

#define POST_IGCMD_EVEBDC_MISFGENR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveBDC_RblCritZone            */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEBDC_RBLCRITZONE()

#define POST_KNKTREAT_EVEBDC_RBLCRITZONE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_EveBDC_LdLim                  */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_EVEBDC_LDLIM()

#define POST_KNKTREAT_EVEBDC_LDLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_EveBDC_CkMngIfIf_2                */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_EVEBDC_CKMNGIFIF_2()

#define POST_SYNC_EVEBDC_CKMNGIFIF_2()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveTDC_AddOnAdvOptm              */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVETDC_ADDONADVOPTM()

#define POST_IGSYS_EVETDC_ADDONADVOPTM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveTDC_AddOnAdvMax               */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVETDC_ADDONADVMAX()

#define POST_IGSYS_EVETDC_ADDONADVMAX()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveTDC_AddOnAdvMin               */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVETDC_ADDONADVMIN()

#define POST_IGSYS_EVETDC_ADDONADVMIN()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable IgSys_EveTDC_AddOnAgCor                */
/*---------------------------------------------------------------------------*/
#define PRE_IGSYS_EVETDC_ADDONAGCOR()

#define POST_IGSYS_EVETDC_ADDONAGCOR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_AdvMinT_006_DREIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_RE_ADVMINT_006_DREIF()

#define POST_RE_ADVMINT_006_DREIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngLimTq_EveBDC_IgAdvTq3If             */
/*---------------------------------------------------------------------------*/
#define PRE_ENGLIMTQ_EVEBDC_IGADVTQ3IF()

#define POST_ENGLIMTQ_EVEBDC_IGADVTQ3IF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_ExMGslT2_006_TEVIf                  */
/*---------------------------------------------------------------------------*/
#define PRE_RE_EXMGSLT2_006_TEVIF()

#define POST_RE_EXMGSLT2_006_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable EngM_SdlMid_intkLoaEstimnIf            */
/*---------------------------------------------------------------------------*/
#define PRE_ENGM_SDLMID_INTKLOAESTIMNIF()

#define POST_ENGM_SDLMID_INTKLOAESTIMNIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirSys_SdlFast_AirTqEff                */
/*---------------------------------------------------------------------------*/
#define PRE_AIRSYS_SDLFAST_AIRTQEFF()

#define POST_AIRSYS_SDLFAST_AIRTQEFF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable AirSys_SdlFast_nEngGrdIf               */
/*---------------------------------------------------------------------------*/
#define PRE_AIRSYS_SDLFAST_NENGGRDIF()

#define POST_AIRSYS_SDLFAST_NENGGRDIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_SdlSlow_TauXMgr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_SDLSLOW_TAUXMGR()

#define POST_RE_INJSYS_SDLSLOW_TAUXMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable KnkTreat_SdlSlow_RblPvt                */
/*---------------------------------------------------------------------------*/
#define PRE_KNKTREAT_SDLSLOW_RBLPVT()

#define POST_KNKTREAT_SDLSLOW_RBLPVT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InMdlT_020_TEVIf                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INMDLT_020_TEVIF()

#define POST_RE_INMDLT_020_TEVIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlFast_CkMngIf                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLFAST_CKMNGIF()

#define POST_SYNC_SDLFAST_CKMNGIF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlFast_SyncSTT                   */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLFAST_SYNCSTT()

#define POST_SYNC_SDLFAST_SYNCSTT()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlFast_ThrSftyMng                 */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLFAST_THRSFTYMNG()

#define POST_THR_SDLFAST_THRSFTYMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlFast_IfInhThrCpuSfty            */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLFAST_IFINHTHRCPUSFTY()

#define POST_THR_SDLFAST_IFINHTHRCPUSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_SdlFast_OplCtl                     */
/*---------------------------------------------------------------------------*/
#define PRE_THR_SDLFAST_OPLCTL()

#define POST_THR_SDLFAST_OPLCTL()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Srv_SdlMid_ActrTstMng                  */
/*---------------------------------------------------------------------------*/
#define PRE_SRV_SDLMID_ACTRTSTMNG()

#define POST_SRV_SDLMID_ACTRTSTMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable TqSys_SdlFast_ChaAdvMinUnlim           */
/*---------------------------------------------------------------------------*/
#define PRE_TQSYS_SDLFAST_CHAADVMINUNLIM()

#define POST_TQSYS_SDLFAST_CHAADVMINUNLIM()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable ISFHCAN_vidTxManagerPrivate            */
/*---------------------------------------------------------------------------*/
#define PRE_ISFHCAN_VIDTXMANAGERPRIVATE()

#define POST_ISFHCAN_VIDTXMANAGERPRIVATE()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveCrTR_TauXMgr              */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVECRTR_TAUXMGR()

#define POST_RE_INJSYS_EVECRTR_TAUXMGR()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_InjSys_EveCrTR_TauXCoef             */
/*---------------------------------------------------------------------------*/
#define PRE_RE_INJSYS_EVECRTR_TAUXCOEF()

#define POST_RE_INJSYS_EVECRTR_TAUXCOEF()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveTestAbort_ThrSftyMng            */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVETESTABORT_THRSFTYMNG()

#define POST_THR_EVETESTABORT_THRSFTYMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveTestAbort_IfInhThrCpuSfty       */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVETESTABORT_IFINHTHRCPUSFTY()

#define POST_THR_EVETESTABORT_IFINHTHRCPUSFTY()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Thr_EveTestStart_ThrSftyMng            */
/*---------------------------------------------------------------------------*/
#define PRE_THR_EVETESTSTART_THRSFTYMNG()

#define POST_THR_EVETESTSTART_THRSFTYMNG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable Sync_SdlMid_SyncCkDiagDiag             */
/*---------------------------------------------------------------------------*/
#define PRE_SYNC_SDLMID_SYNCCKDIAGDIAG()

#define POST_SYNC_SDLMID_SYNCCKDIAGDIAG()

/*---------------------------------------------------------------------------*/
/* Macros d'encapsulation du runnable RE_VirtualComponent                    */
/*---------------------------------------------------------------------------*/
#define PRE_RE_VIRTUALCOMPONENT()

#define POST_RE_VIRTUALCOMPONENT()\
{\
  Boolean bValue;\
  Rte_Read_R_Sync_bDgoCkSig_Sync_bDgoCkSig(&bValue);\
  GDGAR_vidGdu(GD_DFT_CKSIG,bValue,1,0);\
  Rte_Read_R_SftyMgt_bDgoIrvEngStop_SftyMgt_bDgoIrvEngStop(&bValue);\
  GDGAR_vidGdu(GD_DFT_IRVENGSTOP,bValue,1,0);\
}

/*****************************************************************************/
/*                             Fin de fichier                                */
/*****************************************************************************/

#endif

