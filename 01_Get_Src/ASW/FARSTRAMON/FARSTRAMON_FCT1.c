/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FARSTRAMON                                              */
/* !Description     : FARSTRAMON component                                    */
/*                                                                            */
/* !Module          : FARSTRAMON                                              */
/* !Description     : Superviseur de stratégies liées à la Richesse           */
/*                                                                            */
/* !File            : FARSTRAMON_FCT1.C                                       */
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
/*   1 / FARSTRAMON_vidInitOutput                                             */
/*   2 / FARSTRAMON_vidFiltration                                             */
/*   3 / FARSTRAMON_vidAuthdiagEGR                                            */
/*   4 / FARSTRAMON_vidReqClsPurg                                             */
/*   5 / FARSTRAMON_vidPurgeTurbGasMod                                        */
/*   6 / FARSTRAMON_vidInhCstrTranGasMod                                      */
/*   7 / FARSTRAMON_vidPurgeCloseTurbMod                                      */
/*   8 / FARSTRAMON_vidPurgCloseNoTurbMod                                     */
/*   9 / FARSTRAMON_vidMngClsPurge                                            */
/*   10 / FARSTRAMON_vidEGREffect                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5147156 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/FARSTRAMON/FARSTRAMON_$*/
/* $Revision::   1.5      $$Author::   HHAMLAOU       $$Date::   20 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   20 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FARSTRAMON.h"
#include "FARSTRAMON_L.h"
#include "FARSTRAMON_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des variables de sorties et des  */
/*                 d'états d'automates.                                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Mf_emiss_det_fail_uavb0;                                    */
/*  input uint16 Gsm_no_effect_fast_closed_delay;                             */
/*  input uint8 StraMon_tiDlyAftDiagItrsv_C;                                  */
/*  output boolean GMS_bAuthDiagEGRHys;                                       */
/*  output boolean GSM_Misf_OBD_fail;                                         */
/*  output uint16 FARSTRAMON_u16AntiRebFilterCnt;                             */
/*  output st41 FARSTRAMON_stPurge;                                           */
/*  output boolean Gsm_closed_cpc_request;                                    */
/*  output boolean Gsm_cpc_no_effect;                                         */
/*  output uint16 Gsm_cpc_no_effect_count;                                    */
/*  output boolean Gsm_cpc_slow_closing_choice;                               */
/*  output st40 FARSTRAMON_stEGREffect;                                       */
/*  output boolean Gsm_closed_egr_request;                                    */
/*  output boolean Gsm_egr_no_effect;                                         */
/*  output uint16 Gsm_egr_no_effect_count;                                    */
/*  output boolean Gsm_saf_diag_enable;                                       */
/*  output boolean GSM_bAcvAFAAdp;                                            */
/*  output boolean Lambda_for_saf_diag_request;                               */
/*  output boolean Lfbk_mon_diag_test_enable;                                 */
/*  output boolean OxC_bAcvPrioMgt;                                           */
/*  output uint8 StraMon_tiDlyAftDiagItrsv;                                   */
/*  output uint8 Cstr_ctTiEnaPurgEngPrev;                                     */
/*  output boolean FARSTRAMON_bCounter_On_Off;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidInitOutput(void)
{
   boolean bLocalMf_emiss_det_fail_uavb0;


   /* INIT of Hysteresis's Output */
   GMS_bAuthDiagEGRHys = 0;

   /* INIT of anti rebound filter */
   VEMS_vidGET(Mf_emiss_det_fail_uavb0, bLocalMf_emiss_det_fail_uavb0);
   GSM_Misf_OBD_fail = bLocalMf_emiss_det_fail_uavb0;
   FARSTRAMON_u16AntiRebFilterCnt = 0;

   /* INIT of 02_ClsPurge */
   FARSTRAMON_stPurge = PURGE_INIT;
   VEMS_vidSET(Gsm_closed_cpc_request, 0);
   Gsm_cpc_no_effect = 0;
   Gsm_cpc_no_effect_count =
      (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay, 400);
   VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);

   /* INIT of 04_EGR_Effet */
   FARSTRAMON_stEGREffect = EGR_INIT;
   VEMS_vidSET(Gsm_closed_egr_request, 0);
   Gsm_egr_no_effect = 0;
   Gsm_egr_no_effect_count =
      (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay, 400);

   /* INIT of 05_Gestion_activation */
   VEMS_vidSET(Gsm_saf_diag_enable, 0);
   VEMS_vidSET(GSM_bAcvAFAAdp, 0);
   VEMS_vidSET(Lambda_for_saf_diag_request, 0);
   VEMS_vidSET(Lfbk_mon_diag_test_enable, 0);
   VEMS_vidSET(OxC_bAcvPrioMgt , 0);
   StraMon_tiDlyAftDiagItrsv =
      (uint8)MATHSRV_udtMIN(StraMon_tiDlyAftDiagItrsv_C, 50);

   /* INIT of previous */
   Cstr_ctTiEnaPurgEngPrev = 0;
   /* Variable globale*/
   FARSTRAMON_bCounter_On_Off = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidFiltration                                   */
/* !Description :  Pour éviter une bagotage dans les  inhibitions du aux ratés*/
/*                 de combustion, le booléen Mf_emiss_det_fail_uavb0 , qui    */
/*                 indique la détection des ratés de combustion OBD, est      */
/*                 filtré par un filtre anti-rebond  sur les rebonds de 1 à 0.*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_00524_001.02                                     */
/*                 VEMS_R_10_00524_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FARSTRAMON_vidAuthdiagEGR();                             */
/*  input boolean Ext_bPresEGRVlv;                                            */
/*  input boolean GMS_bAuthDiagEGRHys;                                        */
/*  input boolean Mf_emiss_det_fail_uavb0;                                    */
/*  input boolean GSM_Misf_OBD_fail;                                          */
/*  input uint16 GSM_Misf_OBD_Down_C;                                         */
/*  input uint16 FARSTRAMON_u16AntiRebFilterCnt;                              */
/*  output boolean GMS_bAuthDiagEGR;                                          */
/*  output uint16 FARSTRAMON_u16AntiRebFilterCnt;                             */
/*  output boolean GSM_Misf_OBD_fail;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidFiltration(void)
{
   boolean bLocalExt_bPresEGRVlv;
   boolean bLocalMf_emiss_det_fail_uavb0;
   uint16  u16LocalAntiReboundFilterThd;
   uint32  u32LocalCounter;


   VEMS_vidGET(Ext_bPresEGRVlv, bLocalExt_bPresEGRVlv);
   if (bLocalExt_bPresEGRVlv == 0)
   {
      GMS_bAuthDiagEGR = 0;
   }
   else
   {
      FARSTRAMON_vidAuthdiagEGR();
      GMS_bAuthDiagEGR = GMS_bAuthDiagEGRHys;
   }

   VEMS_vidGET(Mf_emiss_det_fail_uavb0, bLocalMf_emiss_det_fail_uavb0);

   if (bLocalMf_emiss_det_fail_uavb0 != GSM_Misf_OBD_fail)
   {
      if (bLocalMf_emiss_det_fail_uavb0 == 0)
      {
         u16LocalAntiReboundFilterThd = GSM_Misf_OBD_Down_C;
      }
      else
      {
         u16LocalAntiReboundFilterThd = 0;
      }

      u32LocalCounter = (uint32)(FARSTRAMON_u16AntiRebFilterCnt + 1);

      FARSTRAMON_u16AntiRebFilterCnt = (uint16)MATHSRV_udtMIN(u32LocalCounter,
                                                              65335);

      if (u32LocalCounter >= u16LocalAntiReboundFilterThd)
      {
         GSM_Misf_OBD_fail = bLocalMf_emiss_det_fail_uavb0;
         FARSTRAMON_u16AntiRebFilterCnt = 0;
      }
   }
   else
   {
      FARSTRAMON_u16AntiRebFilterCnt = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidAuthdiagEGR                                  */
/* !Description :  Fonction qui permet de calibrer                            */
/*                 Gsm_egr_relative_pos_hi_thresh et                          */
/*                 Gsm_egr_relative_pos_low_thresh afin que l'ouverture       */
/*                 résiduelle tolérée de l'EGR ait un effet négligeable sur   */
/*                 les différents diagnostics.                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Egr_relative_needle_pos;                                     */
/*  input uint16 Gsm_egr_relative_pos_low_thresh;                             */
/*  input uint16 Gsm_egr_relative_pos_hi_thresh;                              */
/*  input boolean GMS_bAuthDiagEGRHys;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidAuthdiagEGR(void)
{
   uint16 u16LocalEgr_relative_needle_pos;


   VEMS_vidGET(Egr_relative_needle_pos, u16LocalEgr_relative_needle_pos);
   MATHSRV_vidSchmittTriggerU16(u16LocalEgr_relative_needle_pos,
                                Gsm_egr_relative_pos_low_thresh,
                                Gsm_egr_relative_pos_hi_thresh,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &GMS_bAuthDiagEGRHys);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidReqClsPurg                                   */
/* !Description :  Cette fonction est le manager de stratégie demande la      */
/*                 fermeture de la purge au gestionnaire.                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FARSTRAMON_vidPurgeTurbGasMod();                         */
/*  extf argret void FARSTRAMON_vidMngClsPurge();                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidReqClsPurg(void)
{
   FARSTRAMON_vidPurgeTurbGasMod();
   FARSTRAMON_vidMngClsPurge();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidPurgeTurbGasMod                              */
/* !Description :  Cette fonction identifie le mode de demande de fermeture de*/
/*                 la purge.                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FARSTRAMON_vidInhCstrTranGasMod();                       */
/*  extf argret void FARSTRAMON_vidPurgeCloseTurbMod();                       */
/*  extf argret void FARSTRAMON_vidPurgCloseNoTurbMod();                      */
/*  input boolean Ext_bEngTrbMode;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidPurgeTurbGasMod(void)
{
   boolean bLocalExt_bEngTrbMode;


   VEMS_vidGET(Ext_bEngTrbMode, bLocalExt_bEngTrbMode);
   FARSTRAMON_vidInhCstrTranGasMod();
   if (  (bLocalExt_bEngTrbMode != 0)
      && (Ext_bPresCnstrDblePk_SC == 0))
   /*QAC Msg(3:3356)/(3:3359)/(3:3201):
                    This condition, imposed by specification, is always FALSE */
   {
      FARSTRAMON_vidPurgeCloseTurbMod();
   }
   else
   {
      FARSTRAMON_vidPurgCloseNoTurbMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidInhCstrTranGasMod                            */
/* !Description :  Cette fonction spécifie la demande d’inhibition de la purge*/
/*                 canister sur les transitions Gaz-Essence.                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_00524_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 GasMgt_stTranTypIp;                                           */
/*  input boolean CstrMgr_bAcvReqTranGslGasIp_C;                              */
/*  input boolean CstrMgr_bAcvReqTranGasGslIp_C;                              */
/*  output boolean CstrMgr_bInhCstrTranGasMod;                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidInhCstrTranGasMod(void)
{
   uint8 u8LocalGasMgt_stTranTypIp;


   VEMS_vidGET(GasMgt_stTranTypIp, u8LocalGasMgt_stTranTypIp);
   if (  (  (u8LocalGasMgt_stTranTypIp == GasMgt_stTranGslGasIp_SC)
         && (CstrMgr_bAcvReqTranGslGasIp_C != 0))
      || (  (u8LocalGasMgt_stTranTypIp == GasMgt_stTranGasGslIp_SC)
         && (CstrMgr_bAcvReqTranGasGslIp_C != 0)))
   {
      CstrMgr_bInhCstrTranGasMod = 1;
   }
   else
   {
      CstrMgr_bInhCstrTranGasMod = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidPurgeCloseTurbMod                            */
/* !Description :  Cette fonction spécifie les requêtes de fermeture immédiate*/
/*                 et progressive de la purge canister d’un moteur            */
/*                 suralimenté.                                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Atmospheric_pressure;                                        */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 Cstr_pMinUsDsPurgClose_C;                                    */
/*  input uint16 Cstr_pHysUsDsPurgClose_C;                                    */
/*  input uint16 Cstr_pMinUsDsPurgImdtClose_C;                                */
/*  output boolean Cstr_bDmdClosePurgTurbMod;                                 */
/*  output boolean Cstr_bDmdClosePurgImdtTurbMod;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidPurgeCloseTurbMod(void)
{
   uint16   u16LocalAtmospheric_pressure;
   uint16   u16LocalIoMapManifoldPressMeas;
   sint32   s32LocalThreshold2;
   sint32   s32LocalThreshold1;


   VEMS_vidGET(Atmospheric_pressure, u16LocalAtmospheric_pressure);
   VEMS_vidGET(Io_map_manifold_press_measured, u16LocalIoMapManifoldPressMeas);
   s32LocalThreshold2 =
      (sint32)(u16LocalAtmospheric_pressure - Cstr_pMinUsDsPurgClose_C);
   s32LocalThreshold1 = s32LocalThreshold2 - Cstr_pHysUsDsPurgClose_C;
   if (u16LocalIoMapManifoldPressMeas > s32LocalThreshold2)
   {
      Cstr_bDmdClosePurgTurbMod = 1;
   }
   else
   {
      if (u16LocalIoMapManifoldPressMeas <= s32LocalThreshold1)
      {
         Cstr_bDmdClosePurgTurbMod = 0;
      }
   }
   s32LocalThreshold1 =
      u16LocalAtmospheric_pressure - Cstr_pMinUsDsPurgImdtClose_C;
   if (u16LocalIoMapManifoldPressMeas > s32LocalThreshold1)
   {
      Cstr_bDmdClosePurgImdtTurbMod = 1;
   }
   else
   {
      Cstr_bDmdClosePurgImdtTurbMod = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidPurgCloseNoTurbMod                           */
/* !Description :  Cette fonction spécifie les requêtes de fermeture immédiate*/
/*                 et progressive de la purge canister d’un moteur            */
/*                 atmosphérique.                                             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Cstr_bDmdClosePurgTurbMod;                                 */
/*  output boolean Cstr_bDmdClosePurgImdtTurbMod;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidPurgCloseNoTurbMod(void)
{
   Cstr_bDmdClosePurgTurbMod = 0;
   Cstr_bDmdClosePurgImdtTurbMod = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidMngClsPurge                                  */
/* !Description :  Cette fonction gère la fermeture de la vanne purge.        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Lfbk_mon_diag_test_request;                                 */
/*  input boolean Flex_alc_rate_est_needed_uavb0;                             */
/*  input boolean Flex_alc_rate_diag_run_uavb0;                               */
/*  input boolean Aux_air_pump_disabled;                                      */
/*  input boolean AFA_bAuthClsCanPurg;                                        */
/*  input boolean AFAMgt_bAuthAdpReq;                                         */
/*  input uint16 InM_mfTotCanPurgEstim;                                       */
/*  input boolean EngReqH_bInhCanPurg;                                        */
/*  input boolean CoEs_bAcvClsCanPurgSTTEs;                                   */
/*  input boolean InjSys_bCanPurgCutOff;                                      */
/*  input uint16 AFA_noAdpEfc;                                                */
/*  input boolean OxC_bAcvPrioMgt;                                            */
/*  input boolean Blby_bIdcWoutBlbyCnd;                                       */
/*  input st41 FARSTRAMON_stPurge;                                            */
/*  input boolean GSM_Misf_OBD_fail;                                          */
/*  input boolean Cstr_bDmdClosePurgTurbMod;                                  */
/*  input boolean Cstr_bDmdClosePurgImdtTurbMod;                              */
/*  input boolean CstrMgr_bInhCstrTranGasMod;                                 */
/*  input boolean Cstr_bEnaPurgEngStrtRstrt;                                  */
/*  input uint16 Gsm_noAdpEfcCpcThd_C;                                        */
/*  input uint16 Gsm_no_effect_fast_closed_delay;                             */
/*  input uint16 Gsm_no_effect_slow_closed_delay;                             */
/*  input uint16 Gsm_cpc_no_effect_count;                                     */
/*  output st41 FARSTRAMON_stPurge;                                           */
/*  output boolean Gsm_cpc_no_effect;                                         */
/*  output boolean Gsm_closed_cpc_request;                                    */
/*  output boolean Gsm_cpc_slow_closing_choice;                               */
/*  output uint16 Gsm_cpc_no_effect_count;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidMngClsPurge(void)
{
   boolean bLocalLfbk_mon_diag_test_request;
   boolean bLocalFlexAlcRateEstNeededUavb0;
   boolean bLocalFlexAlcRateDiagRun_uavb0;
   boolean bLocalAux_air_pump_disabled;
   boolean bLocalAFA_bAuthClsCanPurg;
   boolean bLocalAFAMgt_bAuthAdpReq;
   boolean bLocalEngReqH_bInhCanPurg;
   boolean bLocalCoEs_bAcvClsCanPurgSTTEs;
   boolean bLocalInjSys_bCanPurgCutOff;
   boolean bLocalOxC_bAcvPrioMgt;
   boolean bLocalBlby_bIdcWoutBlbyCnd;
   uint16  u16LocalAFA_noAdpEfc;
   uint16  u16LocalCpcNoEffectCount;
   uint16  u16LocalInM_mfTotCanPurgEstim;


   VEMS_vidGET(Lfbk_mon_diag_test_request, bLocalLfbk_mon_diag_test_request);
   VEMS_vidGET(Flex_alc_rate_est_needed_uavb0, bLocalFlexAlcRateEstNeededUavb0);
   VEMS_vidGET(Flex_alc_rate_diag_run_uavb0, bLocalFlexAlcRateDiagRun_uavb0);
   VEMS_vidGET(Aux_air_pump_disabled, bLocalAux_air_pump_disabled);
   VEMS_vidGET(AFA_bAuthClsCanPurg, bLocalAFA_bAuthClsCanPurg);
   VEMS_vidGET(AFAMgt_bAuthAdpReq, bLocalAFAMgt_bAuthAdpReq);
   VEMS_vidGET(InM_mfTotCanPurgEstim, u16LocalInM_mfTotCanPurgEstim);
   VEMS_vidGET(EngReqH_bInhCanPurg, bLocalEngReqH_bInhCanPurg);
   VEMS_vidGET(CoEs_bAcvClsCanPurgSTTEs, bLocalCoEs_bAcvClsCanPurgSTTEs);
   VEMS_vidGET(InjSys_bCanPurgCutOff, bLocalInjSys_bCanPurgCutOff);
   VEMS_vidGET(AFA_noAdpEfc, u16LocalAFA_noAdpEfc);
   VEMS_vidGET(OxC_bAcvPrioMgt, bLocalOxC_bAcvPrioMgt);
   VEMS_vidGET(Blby_bIdcWoutBlbyCnd, bLocalBlby_bIdcWoutBlbyCnd);

   switch (FARSTRAMON_stPurge)
   {
      case PURGE_INIT:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAFAMgt_bAuthAdpReq == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
            && (GSM_Misf_OBD_fail == 0)
            && (Cstr_bDmdClosePurgTurbMod == 0)
            && (Cstr_bDmdClosePurgImdtTurbMod == 0)
            && (CstrMgr_bInhCstrTranGasMod == 0)
            && (Cstr_bEnaPurgEngStrtRstrt != 0)
            && (bLocalEngReqH_bInhCanPurg == 0)
            && (bLocalCoEs_bAcvClsCanPurgSTTEs == 0)
            && (bLocalInjSys_bCanPurgCutOff == 0)
            && (u16LocalAFA_noAdpEfc >= Gsm_noAdpEfcCpcThd_C)
            && (bLocalOxC_bAcvPrioMgt == 0)
            && (bLocalBlby_bIdcWoutBlbyCnd != 0))
         {
            FARSTRAMON_stPurge = GSM_PURGE_CANISTER_RESET;
            Gsm_cpc_no_effect = 0;
            VEMS_vidSET(Gsm_closed_cpc_request, 0);
            VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         }
         else
         {
            VEMS_vidSET(Gsm_closed_cpc_request, 1);
            if (u16LocalInM_mfTotCanPurgEstim != 0)
            {
               if (  (bLocalAFA_bAuthClsCanPurg == 0)
                  || (  (Cstr_bDmdClosePurgTurbMod != 0)
                     && (Cstr_bDmdClosePurgImdtTurbMod != 0)))
               {
                  FARSTRAMON_stPurge = FAST_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
               }
               else
               {
                  if (Cstr_bDmdClosePurgImdtTurbMod == 0)
                  {
                     FARSTRAMON_stPurge = SLOW_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_slow_closed_delay,
                                            400);
                     VEMS_vidSET(Gsm_cpc_slow_closing_choice, 1);
                  }
               }
            }
            else
            {
               FARSTRAMON_stPurge = PURGE_COUNTER_DEC;
            }
         }
         break;

      case GSM_PURGE_CANISTER_RESET:
         if (  (bLocalLfbk_mon_diag_test_request != 0)
            || (bLocalAFAMgt_bAuthAdpReq != 0)
            || (bLocalAux_air_pump_disabled == 0)
            || (bLocalFlexAlcRateEstNeededUavb0 != 0)
            || (bLocalFlexAlcRateDiagRun_uavb0 != 0)
            || (GSM_Misf_OBD_fail != 0)
            || (Cstr_bDmdClosePurgTurbMod != 0)
            || (Cstr_bDmdClosePurgImdtTurbMod != 0)
            || (CstrMgr_bInhCstrTranGasMod != 0)
            || (Cstr_bEnaPurgEngStrtRstrt == 0)
            || (bLocalEngReqH_bInhCanPurg != 0)
            || (bLocalCoEs_bAcvClsCanPurgSTTEs != 0)
            || (bLocalInjSys_bCanPurgCutOff != 0)
            || (u16LocalAFA_noAdpEfc < Gsm_noAdpEfcCpcThd_C)
            || (bLocalOxC_bAcvPrioMgt != 0)
            || (bLocalBlby_bIdcWoutBlbyCnd == 0))
         {
            VEMS_vidSET(Gsm_closed_cpc_request, 1);
            if (u16LocalInM_mfTotCanPurgEstim != 0)
            {
               if (  (bLocalAFA_bAuthClsCanPurg == 0)
                  || (  (Cstr_bDmdClosePurgTurbMod != 0)
                     && (Cstr_bDmdClosePurgImdtTurbMod != 0)))
               {
                  FARSTRAMON_stPurge = FAST_CLOSING_DELAY;
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
               }
               else
               {
                  if (Cstr_bDmdClosePurgImdtTurbMod == 0)
                  {
                     FARSTRAMON_stPurge = SLOW_CLOSING_DELAY;
                     VEMS_vidSET(Gsm_cpc_slow_closing_choice, 1);
                     Gsm_cpc_no_effect_count =
                        (uint16)MATHSRV_udtMIN(Gsm_no_effect_slow_closed_delay,
                                               400);
                  }
               }
            }
            else
            {
               FARSTRAMON_stPurge = PURGE_COUNTER_DEC;
            }
         }
         break;

      case PURGE_COUNTER_DEC:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAFAMgt_bAuthAdpReq == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
            && (GSM_Misf_OBD_fail == 0)
            && (Cstr_bDmdClosePurgTurbMod == 0)
            && (Cstr_bDmdClosePurgImdtTurbMod == 0)
            && (CstrMgr_bInhCstrTranGasMod == 0)
            && (Cstr_bEnaPurgEngStrtRstrt != 0)
            && (bLocalEngReqH_bInhCanPurg == 0)
            && (bLocalCoEs_bAcvClsCanPurgSTTEs == 0)
            && (bLocalInjSys_bCanPurgCutOff == 0)
            && (u16LocalAFA_noAdpEfc >= Gsm_noAdpEfcCpcThd_C)
            && (bLocalOxC_bAcvPrioMgt == 0)
            && (bLocalBlby_bIdcWoutBlbyCnd != 0))
         {
            FARSTRAMON_stPurge = GSM_PURGE_CANISTER_RESET;
            Gsm_cpc_no_effect = 0;
            VEMS_vidSET(Gsm_closed_cpc_request, 0);
            VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         }
         else
         {
            if (u16LocalInM_mfTotCanPurgEstim != 0)
            {
               if (  (bLocalAFA_bAuthClsCanPurg == 0)
                  || (  (Cstr_bDmdClosePurgTurbMod != 0)
                     && (Cstr_bDmdClosePurgImdtTurbMod != 0)))
               {
                  FARSTRAMON_stPurge = FAST_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
               }
               else
               {
                  if (Cstr_bDmdClosePurgImdtTurbMod == 0)
                  {
                     FARSTRAMON_stPurge = SLOW_CLOSING_DELAY;
                     Gsm_cpc_no_effect_count =
                        (uint16)MATHSRV_udtMIN(Gsm_no_effect_slow_closed_delay,
                                               400);
                     VEMS_vidSET(Gsm_cpc_slow_closing_choice, 1);
                  }

               }
            }
            else
            {
               if (Gsm_cpc_no_effect_count == 0)
               {
                  FARSTRAMON_stPurge = GSM_PURGE_AUTORISATION;
                  Gsm_cpc_no_effect = 1;
               }
               else
               {
                  u16LocalCpcNoEffectCount =
                     (uint16)(Gsm_cpc_no_effect_count - 1);
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(u16LocalCpcNoEffectCount, 400);
               }
            }
         }
         break;

      case GSM_PURGE_AUTORISATION:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAFAMgt_bAuthAdpReq == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
            && (GSM_Misf_OBD_fail == 0)
            && (Cstr_bDmdClosePurgTurbMod == 0)
            && (Cstr_bDmdClosePurgImdtTurbMod == 0)
            && (CstrMgr_bInhCstrTranGasMod == 0)
            && (Cstr_bEnaPurgEngStrtRstrt != 0)
            && (bLocalEngReqH_bInhCanPurg == 0)
            && (bLocalCoEs_bAcvClsCanPurgSTTEs == 0)
            && (bLocalInjSys_bCanPurgCutOff == 0)
            && (u16LocalAFA_noAdpEfc >= Gsm_noAdpEfcCpcThd_C)
            && (bLocalOxC_bAcvPrioMgt == 0)
            && (bLocalBlby_bIdcWoutBlbyCnd != 0))
         {
            FARSTRAMON_stPurge = GSM_PURGE_CANISTER_RESET;
            Gsm_cpc_no_effect = 0;
            VEMS_vidSET(Gsm_closed_cpc_request, 0);
            VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         }
         else
         {
            if (u16LocalInM_mfTotCanPurgEstim != 0)
            {
               if (  (bLocalAFA_bAuthClsCanPurg == 0)
                  || (  (Cstr_bDmdClosePurgTurbMod != 0)
                     && (Cstr_bDmdClosePurgImdtTurbMod != 0)))
               {
                  FARSTRAMON_stPurge = FAST_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
               }
               else
               {
                  if (Cstr_bDmdClosePurgImdtTurbMod == 0)
                  {
                     FARSTRAMON_stPurge = SLOW_CLOSING_DELAY;
                     Gsm_cpc_no_effect_count =
                        (uint16)MATHSRV_udtMIN(Gsm_no_effect_slow_closed_delay,
                                               400);
                     VEMS_vidSET(Gsm_cpc_slow_closing_choice, 1);
                  }
               }
            }
         }
         break;

      case SLOW_CLOSING_DELAY:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAFAMgt_bAuthAdpReq == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
            && (GSM_Misf_OBD_fail == 0)
            && (Cstr_bDmdClosePurgTurbMod == 0)
            && (Cstr_bDmdClosePurgImdtTurbMod == 0)
            && (CstrMgr_bInhCstrTranGasMod == 0)
            && (Cstr_bEnaPurgEngStrtRstrt != 0)
            && (bLocalEngReqH_bInhCanPurg == 0)
            && (bLocalCoEs_bAcvClsCanPurgSTTEs == 0)
            && (bLocalInjSys_bCanPurgCutOff == 0)
            && (u16LocalAFA_noAdpEfc >= Gsm_noAdpEfcCpcThd_C)
            && (bLocalOxC_bAcvPrioMgt == 0)
            && (bLocalBlby_bIdcWoutBlbyCnd != 0))
         {
            FARSTRAMON_stPurge = GSM_PURGE_CANISTER_RESET;
            Gsm_cpc_no_effect = 0;
            VEMS_vidSET(Gsm_closed_cpc_request, 0);
            VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         }
         else
         {
            if (u16LocalInM_mfTotCanPurgEstim == 0)
            {
               FARSTRAMON_stPurge = PURGE_COUNTER_DEC;
            }
            else
            {
               if (  (bLocalAFA_bAuthClsCanPurg == 0)
                  || (  (Cstr_bDmdClosePurgTurbMod != 0)
                     && (Cstr_bDmdClosePurgImdtTurbMod != 0)))
               {
                  FARSTRAMON_stPurge = FAST_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
               }
            }
         }
         break;

      case FAST_CLOSING_DELAY:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAFAMgt_bAuthAdpReq == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0)
            && (GSM_Misf_OBD_fail == 0)
            && (Cstr_bDmdClosePurgTurbMod == 0)
            && (Cstr_bDmdClosePurgImdtTurbMod == 0)
            && (CstrMgr_bInhCstrTranGasMod == 0)
            && (Cstr_bEnaPurgEngStrtRstrt != 0)
            && (bLocalEngReqH_bInhCanPurg == 0)
            && (bLocalCoEs_bAcvClsCanPurgSTTEs == 0)
            && (bLocalInjSys_bCanPurgCutOff == 0)
            && (u16LocalAFA_noAdpEfc >= Gsm_noAdpEfcCpcThd_C)
            && (bLocalOxC_bAcvPrioMgt == 0)
            && (bLocalBlby_bIdcWoutBlbyCnd != 0))
         {
            FARSTRAMON_stPurge = GSM_PURGE_CANISTER_RESET;
            Gsm_cpc_no_effect = 0;
            VEMS_vidSET(Gsm_closed_cpc_request, 0);
            VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         }
         else
         {
            if (u16LocalInM_mfTotCanPurgEstim == 0)
            {
               FARSTRAMON_stPurge = PURGE_COUNTER_DEC;
            }
            else
            {
               if (  (bLocalAFA_bAuthClsCanPurg != 0)
                  && (Cstr_bDmdClosePurgImdtTurbMod == 0))
               {
                  FARSTRAMON_stPurge = SLOW_CLOSING_DELAY;
                  Gsm_cpc_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_slow_closed_delay,
                                            400);
                  VEMS_vidSET(Gsm_cpc_slow_closing_choice, 1);
               }
            }
         }
         break;
      default :
         FARSTRAMON_stPurge = PURGE_INIT;
         VEMS_vidSET(Gsm_closed_cpc_request, 0);
         Gsm_cpc_no_effect = 0;
         Gsm_cpc_no_effect_count =
            (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay, 400);
         VEMS_vidSET(Gsm_cpc_slow_closing_choice, 0);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FARSTRAMON_vidEGREffect                                    */
/* !Description :  La vanne EGR doit être fermée : pendant que l’IAE est      */
/*                 active ou pendant une demande d’autorisation du diagnostic */
/*                 de surveillance de lambda feedback                         */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Lfbk_mon_diag_test_request;                                 */
/*  input boolean Flex_alc_rate_est_needed_uavb0;                             */
/*  input boolean Flex_alc_rate_diag_run_uavb0;                               */
/*  input boolean Aux_air_pump_disabled;                                      */
/*  input st40 FARSTRAMON_stEGREffect;                                        */
/*  input boolean Ext_bPresEGRVlv;                                            */
/*  input boolean GMS_bAuthDiagEGR;                                           */
/*  input uint16 Gsm_no_effect_fast_closed_delay;                             */
/*  input uint16 Gsm_egr_no_effect_count;                                     */
/*  output st40 FARSTRAMON_stEGREffect;                                       */
/*  output boolean Gsm_egr_no_effect;                                         */
/*  output boolean Gsm_closed_egr_request;                                    */
/*  output uint16 Gsm_egr_no_effect_count;                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FARSTRAMON_vidEGREffect(void)
{
   boolean bLocalExt_bPresEGRVlv;
   boolean bLocalLfbk_mon_diag_test_request;
   boolean bLocalFlexAlcRateEstNeededUavb0;
   boolean bLocalFlexAlcRateDiagRun_uavb0;
   boolean bLocalAux_air_pump_disabled;
   uint16  u16LocalEffectCount;


   VEMS_vidGET(Lfbk_mon_diag_test_request, bLocalLfbk_mon_diag_test_request);
   VEMS_vidGET(Flex_alc_rate_est_needed_uavb0, bLocalFlexAlcRateEstNeededUavb0);
   VEMS_vidGET(Flex_alc_rate_diag_run_uavb0, bLocalFlexAlcRateDiagRun_uavb0);
   VEMS_vidGET(Aux_air_pump_disabled, bLocalAux_air_pump_disabled);

   switch (FARSTRAMON_stEGREffect)
   {
      case EGR_INIT:
         VEMS_vidGET(Ext_bPresEGRVlv, bLocalExt_bPresEGRVlv);
         if (bLocalExt_bPresEGRVlv != 0)
         {
            if (  (bLocalLfbk_mon_diag_test_request == 0)
               && (bLocalAux_air_pump_disabled != 0)
               && (bLocalFlexAlcRateEstNeededUavb0 == 0)
               && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
            {
               FARSTRAMON_stEGREffect = EGR_RESET;
               Gsm_egr_no_effect = 0;
               VEMS_vidSET(Gsm_closed_egr_request, 0);
            }
            else
            {
               VEMS_vidSET(Gsm_closed_egr_request, 1);
               if (GMS_bAuthDiagEGR == 0)
               {
                  FARSTRAMON_stEGREffect = EGR_REINIT_COUNTER;
                  Gsm_egr_no_effect_count =
                     (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                            400);
               }
               else
               {
                  FARSTRAMON_stEGREffect = EGR_COUNTER_DEC;
               }
            }
         }
         else
         {
            FARSTRAMON_stEGREffect = GSM_NON_EFFECT_EGR;
            Gsm_egr_no_effect = 1;
         }
         break;
      case GSM_NON_EFFECT_EGR :
         break;
      case EGR_RESET:
         if (  (bLocalLfbk_mon_diag_test_request != 0)
            || (bLocalAux_air_pump_disabled == 0)
            || (bLocalFlexAlcRateEstNeededUavb0 != 0)
            || (bLocalFlexAlcRateDiagRun_uavb0 != 0))
         {
            VEMS_vidSET(Gsm_closed_egr_request, 1);
            if (GMS_bAuthDiagEGR == 0)
            {
               FARSTRAMON_stEGREffect = EGR_REINIT_COUNTER;
               Gsm_egr_no_effect_count =
                  (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay,
                                         400);
            }
            else
            {
               FARSTRAMON_stEGREffect = EGR_COUNTER_DEC;
            }
         }
         break;
      case EGR_COUNTER_DEC:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
         {
            FARSTRAMON_stEGREffect = EGR_RESET;
            Gsm_egr_no_effect = 0;
            VEMS_vidSET(Gsm_closed_egr_request, 0);
         }
         else
         {
            if (GMS_bAuthDiagEGR == 0)
            {
               FARSTRAMON_stEGREffect = EGR_REINIT_COUNTER;
               Gsm_egr_no_effect_count =
                  (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay, 400);
            }
            else
            {
               if (Gsm_egr_no_effect_count == 0)
               {
                  FARSTRAMON_stEGREffect = GSM_EGR_AUTORISATION;
                  Gsm_egr_no_effect = 1;
               }
               else
               {
                  u16LocalEffectCount = (uint16)(Gsm_egr_no_effect_count - 1);
                  Gsm_egr_no_effect_count =
                     (uint16)MATHSRV_udtMIN(u16LocalEffectCount, 400);
               }
            }
         }
         break;
      case EGR_REINIT_COUNTER:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
         {
            FARSTRAMON_stEGREffect = EGR_RESET;
            Gsm_egr_no_effect = 0;
            VEMS_vidSET(Gsm_closed_egr_request, 0);
         }
         else
         {
            if (GMS_bAuthDiagEGR != 0)
            {
               FARSTRAMON_stEGREffect = EGR_COUNTER_DEC;
            }
         }
         break;
      case GSM_EGR_AUTORISATION:
         if (  (bLocalLfbk_mon_diag_test_request == 0)
            && (bLocalAux_air_pump_disabled != 0)
            && (bLocalFlexAlcRateEstNeededUavb0 == 0)
            && (bLocalFlexAlcRateDiagRun_uavb0 == 0))
         {
            FARSTRAMON_stEGREffect = EGR_RESET;
            Gsm_egr_no_effect = 0;
            VEMS_vidSET(Gsm_closed_egr_request, 0);
         }
         break;
      default:
         FARSTRAMON_stEGREffect = EGR_INIT;
         VEMS_vidSET(Gsm_closed_egr_request, 0);
         Gsm_egr_no_effect = 0;
         Gsm_egr_no_effect_count =
            (uint16)MATHSRV_udtMIN(Gsm_no_effect_fast_closed_delay, 400);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*------------------------------- end of file --------------------------------*/