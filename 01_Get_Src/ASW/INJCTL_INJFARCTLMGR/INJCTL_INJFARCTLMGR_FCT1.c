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
/* !File            : INJCTL_INJFARCTLMGR_FCT1.C                              */
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
/*   1 / INJCTL_INJFARCTLMGR_vidInit                                          */
/*   2 / INJCTL_INJFARCTLMGR_vidInitFdbk                                      */
/*   3 / INJCTL_INJFARCTLMGR_vidInitDelay                                     */
/*   4 / INJCTL_INJFARCTLMGR_vidDecDelay                                      */
/*   5 / INJCTL_INJFARCTLMGR_vidFSM                                           */
/*   6 / INJCTL_INJFARCTLMGR_vidSetThresh                                     */
/*   7 / INJCTL_INJFARCTLMGR_vidResetCond                                     */
/*   8 / INJCTL_INJFARCTLMGR_vidMontrCond                                     */
/*   9 / INJCTL_INJFARCTLMGR_vidDiagCata                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5147287 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJCTL_INJFARCTLMGR/IN$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   08 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   08 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "Std_Types.h"
#include "Mathsrv.h"
#include "INJCTL_INJFARCTLMGR.h"
#include "INJCTL_INJFARCTLMGR_L.h"
#include "INJCTL_INJFARCTLMGR_IM.h"
#include "SWFAIL.h"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidInit                                */
/* !Description :  Le bouclage de la richesse est désactivé lors d’un calage  */
/*                 moteur ou lors de l’initialisation du calculateur. Alors,  */
/*                 "Lambda_cond_for_adaptation = 0"                           */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Lambda_cond_for_adaptation;                                */
/*  output boolean Lambda_cond_for_feedback;                                  */
/*  output boolean AFReg_bAFRegAcv;                                           */
/*  output boolean OxC_bMonIntrErunCdn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidInit(void)
{
   VEMS_vidSET(Lambda_cond_for_adaptation, 0);
   VEMS_vidSET(Lambda_cond_for_feedback, 0);
   VEMS_vidSET(AFReg_bAFRegAcv, 0);
   VEMS_vidSET(OxC_bMonIntrErunCdn, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidInitFdbk                            */
/* !Description :  Initialise l'automate Monitor_feedback_conds_state.        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void InjCtl_EveIniFbPrm_FarCtlMgr();                          */
/*  output boolean Lambda_for_saf_diag_active;                                */
/*  output boolean Conditions_for_feedback;                                   */
/*  output boolean Lambda_closed_loop;                                        */
/*  output boolean Phase_apres_depart;                                        */
/*  output boolean Enable_dec_obj_rich_mise_en_ac;                            */
/*  output st30 Monitor_feedback_conds_state;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidInitFdbk(void)
{
   VEMS_vidSET(Lambda_for_saf_diag_active, 0);
   VEMS_vidSET(Conditions_for_feedback, 0);
   VEMS_vidSET(Lambda_closed_loop, 0);
   VEMS_vidSET(Phase_apres_depart, 0);
   VEMS_vidSET(Enable_dec_obj_rich_mise_en_ac, 0);
   InjCtl_EveIniFbPrm_FarCtlMgr();
   VEMS_vidSET(Monitor_feedback_conds_state, WAITING_TO_START_FEEDBACK);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidInitDelay                           */
/* !Description :  A froid, l’objectif de richesse visé n’est plus unitaire   */
/*                 mais légèrement supérieur. Par conséquent, il est          */
/*                 nécessaire de laisser la régulation de richesse inactive   */
/*                 pendant un délai fonction de la température d’eau.         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_08_05763_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Obj_rich_decrease_enable;                                   */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Temperature_eau_a_stall;                                      */
/*  input uint8 CoPTSt_tCoMesRStrtSTT;                                        */
/*  input uint8 Obj_rich_temp_eau_stall_bkpt_map[9];                          */
/*  input uint8 Lbda_fdbk_enable_offset_map[9];                               */
/*  input uint8 CoPTSt_tCoMesRStrtSTT_bkpt_map[9];                            */
/*  input uint8 Lbda_fdbk_enable_offset_stt_map[9];                           */
/*  input uint8 Temperature_eau_bkpt_map[16];                                 */
/*  input uint8 Lbda_fdbk_enable_adapt_delay_map[16];                         */
/*  input uint8 Lbda_fdbk_enab_adp_delay_stt_map[16];                         */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  output uint8 Lbda_fdbk_enable_adapt_count;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidInitDelay(void)
{
   boolean bLocalObj_rich_decrease_enable;
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalTemperature_eau_a_stall;
   uint8   u8LocalCoPTSt_tCoMesRStrtSTT;
   uint8   u8LocalInterp1;
   uint8   u8LocalInterp2;
   uint8   u8LocalInterp3;
   uint8   u8LocalInterp4;
   uint8   u8LocalSwitch1;
   uint8   u8LocalSwitch2;
   uint16  u16LocalPara;


   VEMS_vidGET(Obj_rich_decrease_enable, bLocalObj_rich_decrease_enable);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Temperature_eau_a_stall, u8LocalTemperature_eau_a_stall);
   VEMS_vidGET(CoPTSt_tCoMesRStrtSTT, u8LocalCoPTSt_tCoMesRStrtSTT);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(
                  Obj_rich_temp_eau_stall_bkpt_map,
                  u8LocalTemperature_eau_a_stall, 9);

   u8LocalInterp1 = MATHSRV_u8Interp1d(
                    Lbda_fdbk_enable_offset_map,
                    u16LocalPara);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(
                  CoPTSt_tCoMesRStrtSTT_bkpt_map,
                  u8LocalCoPTSt_tCoMesRStrtSTT,9);

   u8LocalInterp2 = MATHSRV_u8Interp1d(
                    Lbda_fdbk_enable_offset_stt_map,
                    u16LocalPara);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU8(
                  Temperature_eau_bkpt_map,
                  u8LocalTemperature_eau,16);

   u8LocalInterp3 = MATHSRV_u8Interp1d(
                    Lbda_fdbk_enable_adapt_delay_map,
                    u16LocalPara);

   u8LocalInterp4 = MATHSRV_u8Interp1d(
                    Lbda_fdbk_enab_adp_delay_stt_map,
                    u16LocalPara);

   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);

   if (bLocalCoPTSt_bRStrtSTT !=0)
   {
      u8LocalSwitch1 = u8LocalInterp2;
      u8LocalSwitch2 = u8LocalInterp4;
   }
   else
   {
      u8LocalSwitch1 = u8LocalInterp1;
      u8LocalSwitch2 = u8LocalInterp3;
   }

   if ( bLocalObj_rich_decrease_enable != 0 )
   {
      if (u8LocalSwitch2 > u8LocalSwitch1)
      {
         Lbda_fdbk_enable_adapt_count =
            (uint8)(u8LocalSwitch2 - u8LocalSwitch1);
      }
      else
      {
         Lbda_fdbk_enable_adapt_count = 0;
      }
   }
   else
   {
      Lbda_fdbk_enable_adapt_count = u8LocalSwitch2;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidDecDelay                            */
/* !Description :  Ce bloc décrémente le délai d’activation de la régulation  */
/*                 de richesse de la valeur du pas de InjCtl_SampleTiSlow_SC. */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Lbda_fdbk_enable_adapt_count;                                 */
/*  output uint8 Lbda_fdbk_enable_adapt_count;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidDecDelay(void)
{
   if ( Lbda_fdbk_enable_adapt_count > 0)
   {
      Lbda_fdbk_enable_adapt_count = (uint8)(Lbda_fdbk_enable_adapt_count - 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidFSM                                 */
/* !Description :  Ce bloc permet de gérer les conditions de régulation, en   */
/*                 modifiant l’état de la variable :                          */
/*                 Monitor_feedback_conds_state.                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_08_05763_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void InjCtl_EveFbDisab_FarCtlMgr();                           */
/*  extf argret void InjCtl_EveIniFbPrm_FarCtlMgr();                          */
/*  extf argret void InjCtl_EveRstLbdFb_FarCtlMgr();                          */
/*  extf argret void InjCtl_EveMonrFbCdn_FarCtlMgr();                         */
/*  extf argret void INJCTL_INJFARCTLMGR_vidMontrCond();                      */
/*  extf argret void InjCtl_EveFbEnad_FarCtlMgr();                            */
/*  extf argret void InjCtl_EveIniFbClcn_FarCtlMgr();                         */
/*  extf argret void InjCtl_EveIniClsdLoop_FarCtlMgr();                       */
/*  extf argret void INJCTL_INJFARCTLMGR_vidResetCond();                      */
/*  extf argret void InjCtl_EveReIniFbSaf_FarCtlMgr();                        */
/*  extf argret void InjCtl_EveFbForSafEnad_FarCtlMgr();                      */
/*  extf argret void INJCTL_INJFARCTLMGR_vidSetThresh();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st07 Engine_running_state;                                          */
/*  input st30 Monitor_feedback_conds_state;                                  */
/*  input boolean Lshd_up_stream_lbda_sensor_hot;                             */
/*  input boolean Lambda_cond_for_adaptation;                                 */
/*  input boolean Lambda_cond_for_feedback;                                   */
/*  input st26 Feedback_calculations_state;                                   */
/*  input boolean Lambda_rich_for_cata_diag;                                  */
/*  input boolean InjCtl_bInhIntrCdn_C;                                       */
/*  input boolean Phase_apres_depart;                                         */
/*  input uint16 Compteur_de_pmh;                                             */
/*  input uint16 Initial_fco_count;                                           */
/*  input uint8 Lambda_enable_after_fco_tdc;                                  */
/*  input boolean Lambda_for_saf_diag_request;                                */
/*  input uint8 Temperature_eau;                                              */
/*  input uint8 Lambda_enable_temp_thresh;                                    */
/*  input boolean Aux_air_pump_disabled;                                      */
/*  input uint8 Lbda_fdbk_enable_adapt_count;                                 */
/*  input st23 Vehicle_active_state;                                          */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Lambda_closed_loop;                                         */
/*  output boolean Conditions_for_feedback;                                   */
/*  output boolean Lambda_closed_loop;                                        */
/*  output boolean Phase_apres_depart;                                        */
/*  output boolean Enable_dec_obj_rich_mise_en_ac;                            */
/*  output uint16 Initial_fco_count;                                          */
/*  output boolean Lambda_for_saf_diag_active;                                */
/*  output boolean AFReg_bAFRegAcv;                                           */
/*  output st30 Monitor_feedback_conds_state;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidFSM(void)
{
   boolean bLocalPhase_apres_depart;
   boolean bLocalLambda_cond_for_adaptation;
   boolean bLocalLambda_cond_for_feedback;
   boolean bLocalLambda_for_saf_diag_rqst;
   boolean bLocalAux_air_pump_disabled;
   boolean bLocalLambda_closed_loop;
   boolean bLocalMoteur_tournant;
   boolean bLocalFco;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalMonitor_feedback_conds_st;
   uint8   u8LocalFeedback_calculations_st;
   uint8   u8LocalLshd_up_strm_lbda_sen_hot;
   uint8   u8LocalTemperature_eau;
   uint16  u16LocalCompteur_de_pmh;
   sint32  s32LocalCond1;
   uint32  u32LocalCond2;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   if (  (u8LocalEngine_running_state == ERUN_ENGINE_OVERRUN_FCO)
      || (u8LocalEngine_running_state == ERUN_ENGINE_OVERSPEED_FCO))
   {
      bLocalFco = 1;
   }
   else
   {
      bLocalFco = 0;
   }

   VEMS_vidGET(Monitor_feedback_conds_state, u8LocalMonitor_feedback_conds_st);
   VEMS_vidGET(Lshd_up_stream_lbda_sensor_hot,
               u8LocalLshd_up_strm_lbda_sen_hot);

   switch (u8LocalMonitor_feedback_conds_st)
   {
      case FEEDBACK_ENABLED:
         if (u8LocalLshd_up_strm_lbda_sen_hot == 0)
         {
            VEMS_vidSET(Conditions_for_feedback, 0);
            VEMS_vidSET(Lambda_closed_loop, 0);
            InjCtl_EveFbDisab_FarCtlMgr();
            VEMS_vidSET(Phase_apres_depart, 1);
            u8LocalMonitor_feedback_conds_st = WAITING_SENSOR_AND_TEMP_CONDS;
         }
         else
         {
            if (bLocalFco != 0)
            {
               VEMS_vidSET(Conditions_for_feedback, 0);
               VEMS_vidSET(Lambda_closed_loop, 0);
               InjCtl_EveIniFbPrm_FarCtlMgr();
               InjCtl_EveRstLbdFb_FarCtlMgr();
               InjCtl_EveFbDisab_FarCtlMgr();
               u8LocalMonitor_feedback_conds_st = FEEDBACK_DISABLED_IN_FCO;
            }
            else
            {
               InjCtl_EveMonrFbCdn_FarCtlMgr();
               INJCTL_INJFARCTLMGR_vidMontrCond();

               VEMS_vidGET(Lambda_cond_for_adaptation,
                           bLocalLambda_cond_for_adaptation);
               VEMS_vidGET(Lambda_cond_for_feedback,
                           bLocalLambda_cond_for_feedback);
               VEMS_vidGET(Feedback_calculations_state,
                           u8LocalFeedback_calculations_st);

               if (  (bLocalLambda_cond_for_adaptation == 0)
                  && (  (  (  (  u8LocalFeedback_calculations_st
                               == FEEDBACK_SYSTEM_RICH)
                           && (Lambda_rich_for_cata_diag != 0))
                        || (  (  u8LocalFeedback_calculations_st
                              == FEEDBACK_SYSTEM_LEAN)
                           && (Lambda_rich_for_cata_diag == 0))
                        || (bLocalLambda_cond_for_feedback == 0))
                     || (InjCtl_bInhIntrCdn_C != 0)))
               {
                  VEMS_vidSET(Conditions_for_feedback, 0);
                  VEMS_vidSET(Lambda_closed_loop, 0);
                  InjCtl_EveIniFbPrm_FarCtlMgr();
                  InjCtl_EveFbDisab_FarCtlMgr();
                  u8LocalMonitor_feedback_conds_st =
                        FEEDBACK_DISABLED_NOT_IN_FCO;
               }
               else
               {
                  InjCtl_EveFbEnad_FarCtlMgr();
               }
            }
         }
         break;

      case FEEDBACK_DISABLED_NOT_IN_FCO:
         if (bLocalFco != 0)
         {
            u8LocalMonitor_feedback_conds_st = FEEDBACK_DISABLED_IN_FCO;
         }
         else
         {
            InjCtl_EveMonrFbCdn_FarCtlMgr();
            INJCTL_INJFARCTLMGR_vidMontrCond();

            VEMS_vidGET(Lambda_cond_for_adaptation,
                        bLocalLambda_cond_for_adaptation);
            if (bLocalLambda_cond_for_adaptation != 0)
            {
               VEMS_vidSET(Conditions_for_feedback, 1);
               VEMS_vidSET(Lambda_closed_loop, 1);
               InjCtl_EveIniFbClcn_FarCtlMgr();
               InjCtl_EveIniFbPrm_FarCtlMgr();

               VEMS_vidGET(Phase_apres_depart, bLocalPhase_apres_depart);
               if ( bLocalPhase_apres_depart != 0 )
               {
                  VEMS_vidSET(Phase_apres_depart, 0);
                  VEMS_vidSET(Enable_dec_obj_rich_mise_en_ac, 1);
                  InjCtl_EveIniClsdLoop_FarCtlMgr();
               }
               else
               {
                  InjCtl_EveRstLbdFb_FarCtlMgr();
               }
               u8LocalMonitor_feedback_conds_st = FEEDBACK_ENABLED;
            }
         }
         break;

      case FEEDBACK_DISABLED_IN_FCO:
         if (bLocalFco == 0)
         {
            VEMS_vidGET(Compteur_de_pmh, u16LocalCompteur_de_pmh);
            Initial_fco_count = u16LocalCompteur_de_pmh;
            u8LocalMonitor_feedback_conds_st = WAITING_FOR_POST_FCO_DELAY;
         }
         break;

      case WAITING_FOR_POST_FCO_DELAY:
         VEMS_vidGET(Compteur_de_pmh, u16LocalCompteur_de_pmh);
         s32LocalCond1 = (sint32) (u16LocalCompteur_de_pmh - Initial_fco_count);
         u32LocalCond2 = (uint32)( u16LocalCompteur_de_pmh
                                 + (65535 - Initial_fco_count));

         if (  (  (s32LocalCond1 >= Lambda_enable_after_fco_tdc)
               && (u16LocalCompteur_de_pmh > Initial_fco_count))
            || (  (u16LocalCompteur_de_pmh < Initial_fco_count)
               && (u32LocalCond2 >= Lambda_enable_after_fco_tdc)))
         {
            INJCTL_INJFARCTLMGR_vidResetCond();
            u8LocalMonitor_feedback_conds_st = FEEDBACK_DISABLED_NOT_IN_FCO;
         }
         break;

      case FEEDBACK_FOR_SAF_IN_FCO:
         if (bLocalFco == 0)
         {
            u8LocalMonitor_feedback_conds_st = FEEDBACK_FOR_SAF_ENABLED;
         }
         break;

      case FEEDBACK_FOR_SAF_ENABLED:
         VEMS_vidGET(Lambda_for_saf_diag_request,
                     bLocalLambda_for_saf_diag_rqst);
         if (  (bLocalLambda_for_saf_diag_rqst == 0)
            || (u8LocalLshd_up_strm_lbda_sen_hot == 0)
            )
         {
            VEMS_vidSET(Lambda_for_saf_diag_active, 0);
            InjCtl_EveRstLbdFb_FarCtlMgr();
            InjCtl_EveIniFbPrm_FarCtlMgr();
            InjCtl_EveReIniFbSaf_FarCtlMgr();
            u8LocalMonitor_feedback_conds_st = WAITING_SENSOR_AND_TEMP_CONDS;
            VEMS_vidSET(Phase_apres_depart, 1);
         }
         else
         {
            if ( bLocalFco != 0 )
            {
               InjCtl_EveRstLbdFb_FarCtlMgr();
               InjCtl_EveIniFbPrm_FarCtlMgr();
               InjCtl_EveReIniFbSaf_FarCtlMgr();
               u8LocalMonitor_feedback_conds_st = FEEDBACK_FOR_SAF_IN_FCO;
            }
            else
            {
               InjCtl_EveFbForSafEnad_FarCtlMgr();
            }
         }
         break;

      case WAITING_SENSOR_AND_TEMP_CONDS:
         VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
         if (  (u8LocalLshd_up_strm_lbda_sen_hot != 0)
            && (u8LocalTemperature_eau >= Lambda_enable_temp_thresh)
            )
         {
            VEMS_vidGET(Lambda_for_saf_diag_request,
                        bLocalLambda_for_saf_diag_rqst);
            if (bLocalLambda_for_saf_diag_rqst != 0)
            {
               VEMS_vidSET(Lambda_for_saf_diag_active, 1);
               InjCtl_EveRstLbdFb_FarCtlMgr();
               InjCtl_EveIniFbPrm_FarCtlMgr();
               InjCtl_EveReIniFbSaf_FarCtlMgr();
               u8LocalMonitor_feedback_conds_st = FEEDBACK_FOR_SAF_ENABLED;
            }
            else
            {
               VEMS_vidGET(Aux_air_pump_disabled, bLocalAux_air_pump_disabled);
               if (  (bLocalAux_air_pump_disabled != 0)
                  && (Lbda_fdbk_enable_adapt_count == 0)
                  )
               {
                  INJCTL_INJFARCTLMGR_vidResetCond();
                  u8LocalMonitor_feedback_conds_st =
                        FEEDBACK_DISABLED_NOT_IN_FCO;
               }
            }
         }
         else
         {
            INJCTL_INJFARCTLMGR_vidSetThresh();
         }
         break;

      case WAITING_TO_START_FEEDBACK:
         VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
         VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
         if (  (u8LocalVehicle_active_state == VS_RUNNING)
            && (bLocalMoteur_tournant == 1))
         {
            VEMS_vidSET(Phase_apres_depart, 1);
            u8LocalMonitor_feedback_conds_st = WAITING_SENSOR_AND_TEMP_CONDS;
         }
         break;

      default:
         u8LocalMonitor_feedback_conds_st = WAITING_TO_START_FEEDBACK;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidSET(AFReg_bAFRegAcv, bLocalLambda_closed_loop);

   VEMS_vidSET(Monitor_feedback_conds_state, u8LocalMonitor_feedback_conds_st);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidSetThresh                           */
/* !Description :  Lors d’un démarrage, le seuil de température d’eau à       */
/*                 atteindre peut être adapté à 3 fonctionnements différents. */
/*                 En fonction de la température de l’eau au démarrage, un    */
/*                 offset est appliqué au seuil de température.               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_for_saf_diag_request;                                */
/*  input uint8 Lambda_saf_enable_thresh_temp;                                */
/*  input boolean Obj_rich_decrease_enable;                                   */
/*  input uint8 Lambda_enable_thresh_temp;                                    */
/*  input uint8 Temperature_eau_a_stall;                                      */
/*  input uint8 Obj_rich_temp_eau_stall_bkpt_map[9];                          */
/*  input uint8 Lambda_enable_temp_offset_map[9];                             */
/*  input uint8 Lambda_enable_temp_thresh;                                    */
/*  output uint8 Lambda_enable_temp_thresh;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidSetThresh(void)
{
   boolean bLocalObj_rich_decrease_enable;
   boolean bLocalLambda_for_saf_diag_rqst;
   uint8   u8LocalTemperature_eau_a_stall;
   uint8   u8LocalInterp;
   uint16  u16LocalPara;
   sint16  s16LocalTemp;


   VEMS_vidGET(Lambda_for_saf_diag_request, bLocalLambda_for_saf_diag_rqst);
   if (bLocalLambda_for_saf_diag_rqst != 0)
   {
      Lambda_enable_temp_thresh = Lambda_saf_enable_thresh_temp;
   }
   else
   {
      VEMS_vidGET(Obj_rich_decrease_enable, bLocalObj_rich_decrease_enable);
      if (bLocalObj_rich_decrease_enable == 0)
      {
         Lambda_enable_temp_thresh = Lambda_enable_thresh_temp;
      }
      else
      {
         VEMS_vidGET(Temperature_eau_a_stall, u8LocalTemperature_eau_a_stall);
         u16LocalPara = MATHSRV_u16CalcParaIncAryU8(
                          Obj_rich_temp_eau_stall_bkpt_map,
                          u8LocalTemperature_eau_a_stall,9);
         u8LocalInterp = MATHSRV_u8Interp1d(
                           Lambda_enable_temp_offset_map,
                           u16LocalPara);

         s16LocalTemp = (sint16)( (Lambda_enable_temp_thresh - u8LocalInterp)
                                + 64);
         if (s16LocalTemp > 255)
         {
            Lambda_enable_temp_thresh = 255;
         }
         else
         {
            if (s16LocalTemp < 0)
            {
               Lambda_enable_temp_thresh = 0;
            }
            else
            {
               Lambda_enable_temp_thresh = (uint8)s16LocalTemp;
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidResetCond                           */
/* !Description :  Ce bloc permet de réinitialiser les compteurs de validation*/
/*                 avant débouclage.                                          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Lambda_disable_counter;                                     */
/*  output uint16 Lambda_disable_knk_counter;                                 */
/*  output uint16 Lambda_disable_stt_counter;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidResetCond(void)
{
   Lambda_disable_counter     = 0;
   Lambda_disable_knk_counter = 0;
   Lambda_disable_stt_counter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidMontrCond                           */
/* !Description :  Le système de régulation par feedback de la sonde ne       */
/*                 fonctionne qu' à richesse 1. Toute consigne de richesse    */
/*                 différente ne peut être régulée. Cependant, l' objectif de */
/*                 richesse à atteindre est calibrable avec hystérésis.       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_08_05763_002.01                                     */
/*                 VEMS_R_08_05763_005.01                                     */
/*                 VEMS_R_08_05763_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJCTL_INJFARCTLMGR_vidFdRegCnd();                       */
/*  extf argret void INJCTL_INJFARCTLMGR_vidFdRichCnd();                      */
/*  extf argret void INJCTL_INJFARCTLMGR_vidGlobalCnd();                      */
/*  input boolean InjCtl_bAcvObjRichRegul_C;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidMontrCond(void)
{
   if (InjCtl_bAcvObjRichRegul_C != 0)
   {
   /*02_feedback_conditions_Obj_rich_regulation*/
      INJCTL_INJFARCTLMGR_vidFdRegCnd();
   }
   else
   {
   /*01_feedback_conditions_enrichment*/
      INJCTL_INJFARCTLMGR_vidFdRichCnd();
   }
   /*03_feedback_conditions_global*/
   INJCTL_INJFARCTLMGR_vidGlobalCnd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJCTL_INJFARCTLMGR_vidDiagCata                            */
/* !Description :  Ce bloc permet d’évaluer les conditions d’autorisation du  */
/*                 diagnostic catalyseur intrusif.                            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  VEMS_R_08_05763_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st07 Engine_running_state;                                          */
/*  input st30 Monitor_feedback_conds_state;                                  */
/*  input boolean Lambda_cond_for_feedback;                                   */
/*  input boolean OxC_bInhNormRunCond_C;                                      */
/*  output boolean OxC_bMonIntrErunCdn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJCTL_INJFARCTLMGR_vidDiagCata(void)
{
   boolean bLocalLambda_cond_for_feedback;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalMonitor_feedback_conds_st;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Monitor_feedback_conds_state, u8LocalMonitor_feedback_conds_st);
   VEMS_vidGET(Lambda_cond_for_feedback, bLocalLambda_cond_for_feedback);
   if (  (  (u8LocalEngine_running_state == ERUN_NORMAL_RUNNING)
         || (OxC_bInhNormRunCond_C != 0))
      && (  (u8LocalMonitor_feedback_conds_st == FEEDBACK_ENABLED)
         || (  (u8LocalMonitor_feedback_conds_st ==
                FEEDBACK_DISABLED_NOT_IN_FCO)
            && (bLocalLambda_cond_for_feedback != 0)))
      )
   {
      VEMS_vidSET(OxC_bMonIntrErunCdn, 1);
   }
   else
   {
      VEMS_vidSET(OxC_bMonIntrErunCdn, 0);
   }
}
/*------------------------------ end of file ---------------------------------*/