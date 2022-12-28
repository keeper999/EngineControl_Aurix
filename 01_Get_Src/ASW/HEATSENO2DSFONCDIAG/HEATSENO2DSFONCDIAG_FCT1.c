/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSFONCDIAG                                     */
/* !Description     : HEATSENO2DSFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2DSFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AVAL                       */
/*                                                                            */
/* !File            : HEATSENO2DSFONCDIAG_FCT1.C                              */
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
/*   1 / HEATSENO2DSFONCDIAG_vidIniAvDiag                                     */
/*   2 / HEATSENO2DSFONCDIAG_vidAvFDiag                                       */
/*   3 / HEATSENO2DSFONCDIAG_vidFldOrFco                                      */
/*   4 / HEATSENO2DSFONCDIAG_vidIncCtDiag                                     */
/*   5 / HEATSENO2DSFONCDIAG_vidInitDiag                                      */
/*   6 / HEATSENO2DSFONCDIAG_vidCondDiag                                      */
/*   7 / HEATSENO2DSFONCDIAG_vidInitTempo                                     */
/*   8 / HEATSENO2DSFONCDIAG_vidDecTempo                                      */
/*   9 / HEATSENO2DSFONCDIAG_vidCalcDiag                                      */
/*   10 / HEATSENO2DSFONCDIAG_vidDiag                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 07942 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSFONCDIA$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   24 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   24 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSFONCDIAG.h"
#include "HEATSENO2DSFONCDIAG_L.h"
#include "HEATSENO2DSFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIniAvDiag                           */
/* !Description :  Fonction d'initialisation des parametres                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFld_C;                                 */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFco_C;                                 */
/*  output uint16 Ldsd_av_f_diag_count;                                       */
/*  output uint16 Ldsd_av_f_diag_confirm_count;                               */
/*  output uint16 Ldsd_av_diag_ai_count;                                      */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFld;                                  */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFco;                                  */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFld;                            */
/*  output boolean LsMon_bItrsvSenO2DsDiagDoneFco;                            */
/*  output uint32 HEATSENO2DSFONCDIAG_u32mAirCor;                             */
/*  output boolean HEATSENO2DSFONCDIAG_bEnTCataPrev;                          */
/*  output uint8 HEATSENO2DSFONCDIAG_u8SysGasPrev;                            */
/*  output boolean Ldsd_av_ena_mode_defaut;                                   */
/*  output boolean Ldsd_av_fco;                                               */
/*  output boolean Ldsd_av_fld;                                               */
/*  output boolean HEATSENO2DSFONCDIAG_bAcvItDsDiag;                          */
/*  output boolean HEATSENO2DSFONCDIAG_bAvItDsDgBva;                          */
/*  output uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;                             */
/*  output uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;                             */
/*  output boolean SenO2Ds_bAcvSeqDsPlausFld;                                 */
/*  output boolean SenO2Ds_bAcvSeqMemDsPlausFld;                              */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output boolean LsMon_bCaseItrsvSenO2DsDiag;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIniAvDiag(void)
{
   /* 01_init_av_f_diag */
   Ldsd_av_f_diag_count = 0;
   Ldsd_av_f_diag_confirm_count = 0;
   Ldsd_av_diag_ai_count = 0;
   LsMon_tiCfmSenO2DsDiagFld = LsMon_tiCfmSenO2DsDiagFld_C;
   LsMon_tiCfmSenO2DsDiagFco = LsMon_tiCfmSenO2DsDiagFco_C;
   LsMon_bItrsvSenO2DsDiagDoneFld = 0;
   LsMon_bItrsvSenO2DsDiagDoneFco = 0;
   /* Internals initialization */
   HEATSENO2DSFONCDIAG_u32mAirCor = 0;
   HEATSENO2DSFONCDIAG_bEnTCataPrev = 0;
   HEATSENO2DSFONCDIAG_u8SysGasPrev = 0;
   Ldsd_av_ena_mode_defaut = 0;
   Ldsd_av_fco = 0;
   Ldsd_av_fld = 0;
   HEATSENO2DSFONCDIAG_bAcvItDsDiag = 1;
   HEATSENO2DSFONCDIAG_bAvItDsDgBva = 1;
   /* Outputs initialization */
   VEMS_vidSET(SenO2Ds_FcoPlausFacMax_Obd6Mod, 0);
   VEMS_vidSET(SenO2Ds_FcoPlausFacMes_Obd6Mod, 0);
   VEMS_vidSET(SenO2Ds_FldPlausFacMes_Obd6Mod, 0);
   VEMS_vidSET(SenO2Ds_FldPlausFacMin_Obd6Mod, 0);
   VEMS_vidSET(SenO2Ds_bAcvSeqDsPlausFld, 0);
   VEMS_vidSET(SenO2Ds_bAcvSeqMemDsPlausFld, 0);
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   VEMS_vidSET(LsMon_bCaseItrsvSenO2DsDiag, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidAvFDiag                             */
/* !Description :  Le diagnostic fonctionnel est décomposé en plusieurs       */
/*                 parties : On vérifie si les conditions sont réuni pour     */
/*                 effectuer le diagnostique et On détermine le type de       */
/*                 diagnostic.                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSFONCDIAG_vidFldOrFco();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIncCtDiag();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidInitDiag();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidCondDiag();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidCalcDiag();                       */
/*  input boolean Ldsd_av_fld_or_fco;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidAvFDiag(void)
{
   boolean bLocalAvFldOrFcoPrev;


   bLocalAvFldOrFcoPrev = Ldsd_av_fld_or_fco;
   HEATSENO2DSFONCDIAG_vidFldOrFco();
   if (Ldsd_av_fld_or_fco != 0)
   {
      HEATSENO2DSFONCDIAG_vidIncCtDiag();
      if (bLocalAvFldOrFcoPrev == 0)
      {
         HEATSENO2DSFONCDIAG_vidInitDiag();
      }
   }
   HEATSENO2DSFONCDIAG_vidCondDiag();
   HEATSENO2DSFONCDIAG_vidCalcDiag();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidFldOrFco                            */
/* !Description :  Le diagnostic est déclenché dans deux cas de vie :  Soit   */
/*                 coupure injection  ou Etat pleine charge avec dépassement  */
/*                 d'un seuil d'objectif de richesse sans misfire             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input st07 Engine_running_state;                                          */
/*  input uint32 Objectif_richesse_global;                                    */
/*  input uint16 Mf_emiss_sum_uavn0;                                          */
/*  input boolean Auto_injection;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Ldsd_av_f_diag_obj_rich_thd_g;                                */
/*  input uint16 Ldsd_av_f_diag_mf_emiss_thd_g;                               */
/*  input uint8 Ldsd_av_f_diag_obj_rich_thresh;                               */
/*  input uint16 Ldsd_av_f_diag_mf_emiss_thresh;                              */
/*  input boolean Ldsd_av_fld;                                                */
/*  input boolean Ldsd_av_fco;                                                */
/*  output boolean Ldsd_av_fld;                                               */
/*  output boolean Ldsd_av_fco;                                               */
/*  output boolean Ldsd_av_fld_or_fco;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidFldOrFco(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalLdsdAvFldPrev;
   boolean bLocalLdsdAvFcoPrev;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalMf_emiss_sum_uavn0;
   uint16  u16LocalLdsdAvFDiagObjRich;
   uint16  u16LocalDiagMfEmissThresh;
   uint32  u32LocalObjectif_richesse_global;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Objectif_richesse_global, u32LocalObjectif_richesse_global);
   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalLdsdAvFDiagObjRich = (uint16)( Ldsd_av_f_diag_obj_rich_thd_g
                                           * 256);
      u16LocalDiagMfEmissThresh = Ldsd_av_f_diag_mf_emiss_thd_g;
   }
   else
   {
      u16LocalLdsdAvFDiagObjRich = (uint16)( Ldsd_av_f_diag_obj_rich_thresh
                                           * 256);
      u16LocalDiagMfEmissThresh = Ldsd_av_f_diag_mf_emiss_thresh;
   }
   bLocalLdsdAvFldPrev = Ldsd_av_fld;
   if (  (u8LocalEngine_running_state == ERUN_FULL_LOAD)
      && (u32LocalObjectif_richesse_global >= u16LocalLdsdAvFDiagObjRich)
      && (u16LocalMf_emiss_sum_uavn0 <= u16LocalDiagMfEmissThresh))
   {
      Ldsd_av_fld = 1;
   }
   else
   {
      Ldsd_av_fld = 0;
   }

   bLocalLdsdAvFcoPrev = Ldsd_av_fco;
   if (bLocalAuto_injection != 0)
   {
      Ldsd_av_fco = 0;
   }
   else
   {
      Ldsd_av_fco = 1;
   }

   if (  (  (Ldsd_av_fld == 0)
         && (bLocalLdsdAvFldPrev != 0))
      || (  (bLocalAuto_injection != 0)
         && (bLocalLdsdAvFcoPrev != 0)))
   {
      Ldsd_av_fld_or_fco = 0;
   }
   else
   {
      if (  (Ldsd_av_fco != 0)
         || (Ldsd_av_fld != 0))
      {
         Ldsd_av_fld_or_fco = 1;
      }
      else
      {
         Ldsd_av_fld_or_fco = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIncCtDiag                           */
/* !Description :  Comptage du diagnostic                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_av_f_diag_count;                                        */
/*  output uint16 Ldsd_av_f_diag_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIncCtDiag(void)
{
   uint32 u32LocalLdsd_av_f_diag_count;


   u32LocalLdsd_av_f_diag_count = (uint32)(Ldsd_av_f_diag_count + 1);
   Ldsd_av_f_diag_count = (uint16)MATHSRV_udtMIN(u32LocalLdsd_av_f_diag_count,
                                                 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidInitDiag                            */
/* !Description :  Initialisation du diagnostic                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Ldsd_av_f_diag_fld_conf_delay;                               */
/*  input uint16 Ldsd_av_f_diag_fco_conf_delay;                               */
/*  output uint16 Ldsd_av_f_diag_count;                                       */
/*  output uint16 Ldsd_av_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidInitDiag(void)
{
   boolean bLocalAuto_injection;


   Ldsd_av_f_diag_count = 0;

   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   if (bLocalAuto_injection != 0)
   {
      Ldsd_av_f_diag_confirm_count =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fld_conf_delay, 5990);
   }
   else
   {
      Ldsd_av_f_diag_confirm_count =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fco_conf_delay, 5990);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidCondDiag                            */
/* !Description :  Le diagnostic fonctionnel n'est effectué qu'a certaines    */
/*                 conditions.                                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDecTempo();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidInitTempo();                      */
/*  input boolean Lshd_down_stream_lbda_sensor_hot;                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 Temperature_eau;                                              */
/*  input st69 Saf_status;                                                    */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input boolean Auto_injection;                                             */
/*  input boolean VlvAct_bInhDiagPresScav;                                    */
/*  input boolean Ext_bPresGaz;                                               */
/*  input boolean Lambda_closed_loop;                                         */
/*  input boolean LsMon_bAcvItrsvSenO2DsDiag;                                 */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input uint16 Ldsd_av_f_diag_max_delay_gas;                                */
/*  input uint8 Ldsd_av_f_diag_fld_mAir_thd_g;                                */
/*  input uint8 Ldsd_av_f_diag_fco_mAir_thd_g;                                */
/*  input uint16 Ldsd_av_f_diag_max_delay;                                    */
/*  input uint8 Ldsd_av_f_diag_fld_mAir_thresh;                               */
/*  input uint8 Ldsd_av_f_diag_fco_mAir_thresh;                               */
/*  input boolean Manu_inh_diag_av_max_delay;                                 */
/*  input uint16 Ldsd_av_f_diag_count;                                        */
/*  input boolean HEATSENO2DSFONCDIAG_bEnTCataPrev;                           */
/*  input boolean Ldsd_av_fld_or_fco;                                         */
/*  input uint32 HEATSENO2DSFONCDIAG_u32mAirCor;                              */
/*  input uint8 LsMon_mfAirCorIntSenO2Ds;                                     */
/*  input uint16 SenO2Ds_tiInhDiag;                                           */
/*  input uint16 SenO2Ds_tiInhDiag_C;                                         */
/*  input sint16 Ldsd_av_f_diag_water_temp_thresh;                            */
/*  input uint16 Ldsd_av_diag_ai_count;                                       */
/*  input boolean SenO2Ds_bInhDiagPresScav_C;                                 */
/*  input boolean Manu_inh_Ldsd_av_diag_intru_cond;                           */
/*  output boolean HEATSENO2DSFONCDIAG_bEnTCataPrev;                          */
/*  output uint32 HEATSENO2DSFONCDIAG_u32mAirCor;                             */
/*  output uint8 LsMon_mfAirCorIntSenO2Ds;                                    */
/*  output uint16 SenO2Ds_tiInhDiag;                                          */
/*  output boolean Ldsd_av_diag_cond;                                         */
/*  output boolean Ldsd_av_diag_intru_cond;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidCondDiag(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalLsSys_LsDsMaiOxCHeatOkdiag;
   boolean bLocalInhDiagSenO2DsScg;
   boolean bLocalInhDiagSenO2DsEIDiag;
   boolean bLocalDiagCataOffOn;
   boolean bLocalDiagmAirCor;
   boolean bLocalVlvAct_bInhDiagPresScav;
   boolean bLocalInhDiag;
   boolean bLocalSysGas;
   boolean bLocalExt_bPresGaz;
   boolean bLocal_Ldsd_av_diag_cond;
   boolean bLocalLdsdAvDiagCond;
   boolean bLocalLdsdAvDiagIntruCond;
   boolean bLocalLambda_closed_loop;
   boolean bLocalLsMon_bAcvItrsvSenO2DsDiag;
   boolean bLocalFlev_low_fuel_level;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalSaf_status;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalDiagFldMAirThd;
   uint8   u8LocalDiagFcoMAirThd;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalInhDiag;
   uint16  u16LocalEngM_mfAirCor;
   uint16  u16LocalDiagMaxDelay;
   uint32  u32LocalmAirCor;
   sint32  s32LocalWaterTemp;


   bLocalInhDiagSenO2DsScg = GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2DSSCG);
   bLocalInhDiagSenO2DsEIDiag = GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2DSEIDIAG);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOkdiag,
               bLocalLsSys_LsDsMaiOxCHeatOkdiag);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Saf_status, u8LocalSaf_status);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(EngM_mfAirCor, u16LocalEngM_mfAirCor);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(VlvAct_bInhDiagPresScav, bLocalVlvAct_bInhDiagPresScav);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidGET(LsMon_bAcvItrsvSenO2DsDiag, bLocalLsMon_bAcvItrsvSenO2DsDiag);
   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalDiagMaxDelay = Ldsd_av_f_diag_max_delay_gas;
      u8LocalDiagFldMAirThd = Ldsd_av_f_diag_fld_mAir_thd_g;
      u8LocalDiagFcoMAirThd = Ldsd_av_f_diag_fco_mAir_thd_g;
   }
   else
   {
      u16LocalDiagMaxDelay = Ldsd_av_f_diag_max_delay;
      u8LocalDiagFldMAirThd = Ldsd_av_f_diag_fld_mAir_thresh;
      u8LocalDiagFcoMAirThd = Ldsd_av_f_diag_fco_mAir_thresh;
   }
   bLocalDiagCataOffOn = 0;
   if (bLocalAuto_injection != 0)
   {
      HEATSENO2DSFONCDIAG_vidDecTempo();
   }
   else
   {
      if (  (Manu_inh_diag_av_max_delay == 0)
         && (Ldsd_av_f_diag_count >= u16LocalDiagMaxDelay) )
      {
         bLocalDiagCataOffOn = 1;
         if (HEATSENO2DSFONCDIAG_bEnTCataPrev == 0)
         {
            HEATSENO2DSFONCDIAG_vidInitTempo();
         }
      }
   }
   HEATSENO2DSFONCDIAG_bEnTCataPrev = bLocalDiagCataOffOn;

   bLocalDiagmAirCor = 0;
   if (Ldsd_av_fld_or_fco != 0)
   {
      HEATSENO2DSFONCDIAG_u32mAirCor =
         MATHSRV_u32Add_u32_u32(HEATSENO2DSFONCDIAG_u32mAirCor,
                                (uint32)u16LocalEngM_mfAirCor);
      u32LocalmAirCor = ( ( ( HEATSENO2DSFONCDIAG_u32mAirCor / 65536)
                          * SenO2Ds_SampleTiMid_SC)
                        + ( ( ( ( HEATSENO2DSFONCDIAG_u32mAirCor % 65536)
                              * SenO2Ds_SampleTiMid_SC)
                            + 32768)
                          / 65536));
      LsMon_mfAirCorIntSenO2Ds = (uint8)MATHSRV_udtMIN(u32LocalmAirCor, 255);
      if (bLocalAuto_injection != 0)
      {
         if (LsMon_mfAirCorIntSenO2Ds >= u8LocalDiagFldMAirThd)
         {
            bLocalDiagmAirCor = 1;
         }
      }
      else
      {
         if (LsMon_mfAirCorIntSenO2Ds >= u8LocalDiagFcoMAirThd)
         {
            bLocalDiagmAirCor = 1;
         }
      }
   }
   else
   {
      HEATSENO2DSFONCDIAG_u32mAirCor = 0;
      LsMon_mfAirCorIntSenO2Ds = 0;
   }
   bLocalSysGas = 0;
   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      bLocalSysGas = 1;
      if (SenO2Ds_tiInhDiag > 0)
      {
         u16LocalInhDiag = (uint16)(SenO2Ds_tiInhDiag - 1);
         SenO2Ds_tiInhDiag = (uint16)MATHSRV_udtMIN(u16LocalInhDiag, 50000);
      }
   }
   else
   {
      SenO2Ds_tiInhDiag = (uint16)MATHSRV_udtMIN(SenO2Ds_tiInhDiag_C, 50000);
   }

   bLocalInhDiag = 0;
   if (bLocalExt_bPresGaz == 0)
   {
      bLocalInhDiag = 1;
   }
   else
   {
      if (  (bLocalSysGas != 0)
         && (SenO2Ds_tiInhDiag == 0))
      {
         bLocalInhDiag = 1;
      }
   }

   s32LocalWaterTemp = (sint32)(Ldsd_av_f_diag_water_temp_thresh + 64);
   if (  (bLocalLsSys_LsDsMaiOxCHeatOkdiag != 0)
      && (u8LocalVehicle_active_state == VS_RUNNING)
      && (u8LocalTemperature_eau > s32LocalWaterTemp)
      && (u8LocalSaf_status != SAF_PUMP_VALVE_ACTIVATED)
      && (bLocalInhDiagSenO2DsScg == 0)
      && (bLocalInhDiagSenO2DsEIDiag == 0)
      && (Ldsd_av_diag_ai_count == 0)
      && (  (bLocalAuto_injection != 0)
         || (Manu_inh_diag_av_max_delay != 0)
         || (Ldsd_av_f_diag_count < u16LocalDiagMaxDelay))
      && (bLocalInhDiag != 0)
      && (  (SenO2Ds_bInhDiagPresScav_C != 0)
         || (bLocalVlvAct_bInhDiagPresScav == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (bLocalFlev_low_fuel_level ==0))
   {
      bLocal_Ldsd_av_diag_cond = 1;
   }
   else
   {
      bLocal_Ldsd_av_diag_cond = 0;
   }
   bLocalLdsdAvDiagCond = 0;
   bLocalLdsdAvDiagIntruCond = 0;
   if (bLocal_Ldsd_av_diag_cond != 0)
   {
      if (bLocalDiagmAirCor != 0)
      {
         bLocalLdsdAvDiagCond = 1;
      }
      else
      {
         if (  (Manu_inh_Ldsd_av_diag_intru_cond == 0)
            && (  (bLocalLambda_closed_loop != 0)
               || (bLocalLsMon_bAcvItrsvSenO2DsDiag != 0))
            && (u8LocalEngine_running_state != ERUN_ON_IDLE)
            && (Ldsd_av_fld_or_fco == 0))
         {
            bLocalLdsdAvDiagIntruCond = 1;
         }
      }
   }
   Ldsd_av_diag_cond = bLocalLdsdAvDiagCond;
   Ldsd_av_diag_intru_cond = bLocalLdsdAvDiagIntruCond;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidInitTempo                           */
/* !Description :  Initialisation de Ldsd_av_diag_ai_count                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_av_diag_delay_sensor_hot_g;                             */
/*  input uint16 Ldsd_av_diag_delay_sensor_hot;                               */
/*  output uint16 Ldsd_av_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidInitTempo(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalCount;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalCount = Ldsd_av_diag_delay_sensor_hot_g;
   }
   else
   {
      u16LocalCount = Ldsd_av_diag_delay_sensor_hot;
   }
   Ldsd_av_diag_ai_count = (uint16)MATHSRV_udtMIN(u16LocalCount, 52428);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDecTempo                            */
/* !Description :  Decrementation de Ldsd_av_diag_ai_count                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_av_diag_ai_count;                                       */
/*  output uint16 Ldsd_av_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDecTempo(void)
{
   sint32 s32LocalLdsd_av_diag_ai_count;


   s32LocalLdsd_av_diag_ai_count = (sint32)(Ldsd_av_diag_ai_count - 1);
   Ldsd_av_diag_ai_count =
      (uint16)MATHSRV_udtCLAMP(s32LocalLdsd_av_diag_ai_count, 0, 52428);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidCalcDiag                            */
/* !Description :  Activation du diagnostic                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiag();                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiagIhBva();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiagIntru();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDgIntrBva();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiagInInh();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDiagInDon();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDgInDnBva();                      */
/*  input st70 LsMon_stItrsvSenO2DsDiag;                                      */
/*  input boolean Presence_bva;                                               */
/*  input boolean LsMon_bCaseItrsvSenO2DsDiag;                                */
/*  input boolean Ldsd_av_diag_cond;                                          */
/*  input boolean Auto_injection;                                             */
/*  input boolean Ldsd_av_diag_intru_cond;                                    */
/*  input boolean LsMon_bItrsvSenO2DsDiagDoneFld;                             */
/*  input boolean LsMon_bItrsvSenO2DsDiagDoneFco;                             */
/*  input boolean LsMon_bManDiagFldActiv_C;                                   */
/*  input boolean LsMon_bManDiagFcoActiv_C;                                   */
/*  output boolean SenO2Ds_bMonRunRaw_DsPlausFld;                             */
/*  output boolean SenO2Ds_bMonRunRaw_DsPlausFco;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidCalcDiag(void)
{
   boolean bLocalDsPlausFld;
   boolean bLocalDsPlausFco;
   boolean bLocalPresence_bva;
   boolean bLocalAuto_injection;
   boolean bLocalLsMon_bCasItrsvSenO2DsDiag;
   uint8   u8LocalLsMon_stItrsvSenO2DsDiag;


   VEMS_vidGET(LsMon_stItrsvSenO2DsDiag, u8LocalLsMon_stItrsvSenO2DsDiag);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   VEMS_vidGET(LsMon_bCaseItrsvSenO2DsDiag, bLocalLsMon_bCasItrsvSenO2DsDiag);
   if (Ldsd_av_diag_cond != 0)
   {
      HEATSENO2DSFONCDIAG_vidDiag();
      VEMS_vidGET(Auto_injection, bLocalAuto_injection);
      if (bLocalAuto_injection != 0)
      {
         bLocalDsPlausFld = 1;
         bLocalDsPlausFco = 0;
      }
      else
      {
         bLocalDsPlausFld = 0;
         bLocalDsPlausFco = 1;
      }
   }
   else
   {
      bLocalDsPlausFld = 0;
      bLocalDsPlausFco = 0;
   }

   if (  (Ldsd_av_diag_intru_cond ==0)
      || (bLocalPresence_bva ==0))
   {
      HEATSENO2DSFONCDIAG_vidDiagIhBva();
   }

   if (Ldsd_av_diag_intru_cond != 0)
   {
      if (LsMon_bItrsvSenO2DsDiagDoneFld == 0)
      {
         bLocalDsPlausFld = 1;
         HEATSENO2DSFONCDIAG_vidDiagIntru();
      }

      if (bLocalPresence_bva != 0)
      {
         if (LsMon_bItrsvSenO2DsDiagDoneFco == 0)
         {
            bLocalDsPlausFco = 1;
            HEATSENO2DSFONCDIAG_vidDgIntrBva();
         }
      }
   }
   else
   {
      HEATSENO2DSFONCDIAG_vidDiagInInh();
   }

   if (  (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_OK)
      || (u8LocalLsMon_stItrsvSenO2DsDiag == LSMON_ITRSV_SENO2DS_DIAG_NOK))
   {
      if (bLocalLsMon_bCasItrsvSenO2DsDiag != 0)
      {
         if (LsMon_bManDiagFldActiv_C == 0)
         {
            HEATSENO2DSFONCDIAG_vidDiagInDon();
         }
      }
      else
      {
         if (LsMon_bManDiagFcoActiv_C == 0)
         {
            HEATSENO2DSFONCDIAG_vidDgInDnBva();
         }
      }
   }

   SenO2Ds_bMonRunRaw_DsPlausFld = bLocalDsPlausFld;
   SenO2Ds_bMonRunRaw_DsPlausFco = bLocalDsPlausFco;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiag                                */
/* !Description :  Le diagnostic vérifie que les valeurs de la tension sonde  */
/*                 sont cohérentes                                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_002.01                                     */
/*                 VEMS_R_11_07942_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidDecTConfD();                      */
/*  extf argret void HEATSENO2DSFONCDIAG_vidMode6();                          */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIniTConfD();                      */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_av_f_diag_fld_thd_g;                                    */
/*  input uint16 Ldsd_av_f_diag_fco_thd_g;                                    */
/*  input uint16 Ldsd_av_f_diag_fld_thresh;                                   */
/*  input uint16 Ldsd_av_f_diag_fco_thresh;                                   */
/*  input boolean Ldsd_av_ena_mode_defaut;                                    */
/*  input uint16 Ldsd_av_f_diag_confirm_count;                                */
/*  output boolean Ldsd_av_ena_mode_defaut;                                   */
/*  output boolean Ldsd_av_fld_confirm;                                       */
/*  output boolean SenO2Ds_bMonWaitRaw_DsPlausFco;                            */
/*  output boolean Ldsd_av_fld_failure;                                       */
/*  output boolean SenO2Ds_bDgoORng_DsPlausFco;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiag(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalAvFldFailure;
   boolean bLocalORng_DsPlausFco;
   boolean bLocalDiagEnaPrev;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalDiagFldThd;
   uint16  u16LocalDiagFcoThd;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalDiagFldThd = Ldsd_av_f_diag_fld_thd_g;
      u16LocalDiagFcoThd = Ldsd_av_f_diag_fco_thd_g;
   }
   else
   {
      u16LocalDiagFldThd = Ldsd_av_f_diag_fld_thresh;
      u16LocalDiagFcoThd = Ldsd_av_f_diag_fco_thresh;
   }
   bLocalDiagEnaPrev = Ldsd_av_ena_mode_defaut;
   bLocalAvFldFailure = 0;
   bLocalORng_DsPlausFco = 0;
   if (  (  (bLocalAuto_injection != 0)
         && (u16LocalTension_sonde_aval < u16LocalDiagFldThd))
      || (  (bLocalAuto_injection == 0)
         && (u16LocalTension_sonde_aval > u16LocalDiagFcoThd)))
   {
      Ldsd_av_ena_mode_defaut = 1;
      /* 01_decrem_tempo_confirm_defaut */
      HEATSENO2DSFONCDIAG_vidDecTConfD();
      if (Ldsd_av_f_diag_confirm_count == 0)
      {
         if (bLocalAuto_injection != 0)
         {
            bLocalAvFldFailure = 1;
            Ldsd_av_fld_confirm = 1;
            SenO2Ds_bMonWaitRaw_DsPlausFco =1;
         }
         else
         {
            bLocalORng_DsPlausFco = 1;
            Ldsd_av_fld_confirm = 0;
            SenO2Ds_bMonWaitRaw_DsPlausFco =0;
         }
         /* 03_mode_06 */
         HEATSENO2DSFONCDIAG_vidMode6();
      }
      else
      {
         Ldsd_av_fld_confirm = 0;
         SenO2Ds_bMonWaitRaw_DsPlausFco =1;
      }
   }
   else
   {
      if (bLocalAuto_injection != 0)
      {
         Ldsd_av_fld_confirm = 1;
         SenO2Ds_bMonWaitRaw_DsPlausFco =1;
      }
      else
      {
         Ldsd_av_fld_confirm = 0;
         SenO2Ds_bMonWaitRaw_DsPlausFco =0;
      }
      Ldsd_av_ena_mode_defaut = 0;
      if (bLocalDiagEnaPrev != 0)
      {
         /* 02_init_tempo_confirm_defaut */
         HEATSENO2DSFONCDIAG_vidIniTConfD();
      }
      HEATSENO2DSFONCDIAG_vidMode6();
   }

   Ldsd_av_fld_failure = bLocalAvFldFailure;
   SenO2Ds_bDgoORng_DsPlausFco = bLocalORng_DsPlausFco;
}

/*---------------------------- end of file -----------------------------------*/