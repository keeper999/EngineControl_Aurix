/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPFONCDIAG                                     */
/* !Description     : HEATSENO2UPFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AMONT                      */
/*                                                                            */
/* !File            : HEATSENO2UPFONCDIAG_FCT1.C                              */
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
/*   1 / HEATSENO2UPFONCDIAG_vidIniAmDiag                                     */
/*   2 / HEATSENO2UPFONCDIAG_vidAmFDiag                                       */
/*   3 / HEATSENO2UPFONCDIAG_vidFldOrFco                                      */
/*   4 / HEATSENO2UPFONCDIAG_vidIncCtDiag                                     */
/*   5 / HEATSENO2UPFONCDIAG_vidInitDiag                                      */
/*   6 / HEATSENO2UPFONCDIAG_vidCondDiag                                      */
/*   7 / HEATSENO2UPFONCDIAG_vidDecTempo                                      */
/*   8 / HEATSENO2UPFONCDIAG_vidInitTempo                                     */
/*   9 / HEATSENO2UPFONCDIAG_vidCalcDiag                                      */
/*   10 / HEATSENO2UPFONCDIAG_vidDiag                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5482727 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   17 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPFONCDIAG.h"
#include "HEATSENO2UPFONCDIAG_L.h"
#include "HEATSENO2UPFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidIniAmDiag                           */
/* !Description :  Fonction d'initialisation des parametres                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 LsMon_tiCfmSenO2UsDiag_C;                                    */
/*  output uint16 Ldsd_am_f_diag_count;                                       */
/*  output uint16 Ldsd_am_f_diag_confirm_count;                               */
/*  output uint16 Ldsd_am_diag_ai_count;                                      */
/*  output uint16 LsMon_tiCfmSenO2UsDiag;                                     */
/*  output uint32 HEATSENO2UPFONCDIAG_u32MfAirCor;                            */
/*  output boolean HEATSENO2UPFONCDIAG_bEnTCataPrev;                          */
/*  output uint8 HEATSENO2UPFONCDIAG_u8SysGasPrev;                            */
/*  output boolean Ldsd_am_ena_mode_defaut;                                   */
/*  output boolean Ldsd_am_fco;                                               */
/*  output boolean Ldsd_am_fld;                                               */
/*  output uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;                             */
/*  output uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Us_FldPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Us_FldPlausFacMin_Obd6Mod;                             */
/*  output boolean SenO2Us_bAcvSeqMemUsPlausFld;                              */
/*  output boolean SenO2Us_bAcvSeqUsPlausFld;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidIniAmDiag(void)
{
   /*01_init_am_f_diag*/
   Ldsd_am_f_diag_count = 0;
   Ldsd_am_f_diag_confirm_count = 0;
   Ldsd_am_diag_ai_count = 0;
   LsMon_tiCfmSenO2UsDiag = LsMon_tiCfmSenO2UsDiag_C;
   /* Internals initialization */
   HEATSENO2UPFONCDIAG_u32MfAirCor = 0;
   HEATSENO2UPFONCDIAG_bEnTCataPrev = 0;
   HEATSENO2UPFONCDIAG_u8SysGasPrev = 0;
   Ldsd_am_ena_mode_defaut = 0;
   Ldsd_am_fco = 0;
   Ldsd_am_fld = 0;
   /* Outputs initialization */
   VEMS_vidSET(SenO2Us_FcoPlausFacMax_Obd6Mod, 0);
   VEMS_vidSET(SenO2Us_FcoPlausFacMes_Obd6Mod, 0);
   VEMS_vidSET(SenO2Us_FldPlausFacMes_Obd6Mod, 0);
   VEMS_vidSET(SenO2Us_FldPlausFacMin_Obd6Mod, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqMemUsPlausFld, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqUsPlausFld, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidAmFDiag                             */
/* !Description :  Le diagnostic fonctionnel est décomposé en plusieurs       */
/*                 parties : On vérifie si les conditions sont réuni pour     */
/*                 effectuer le diagnostique et On détermine le type de       */
/*                 diagnostic.                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPFONCDIAG_vidFldOrFco();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidIncCtDiag();                      */
/*  extf argret void HEATSENO2UPFONCDIAG_vidInitDiag();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidCondDiag();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidCalcDiag();                       */
/*  input boolean Ldsd_am_fld_or_fco;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidAmFDiag(void)
{
   boolean bLocalAmFldOrFcoPrev;

   bLocalAmFldOrFcoPrev = Ldsd_am_fld_or_fco;
   HEATSENO2UPFONCDIAG_vidFldOrFco();
   if (Ldsd_am_fld_or_fco != 0)
   {
      HEATSENO2UPFONCDIAG_vidIncCtDiag();
      if (bLocalAmFldOrFcoPrev == 0)
      {
         HEATSENO2UPFONCDIAG_vidInitDiag();
      }
   }
   HEATSENO2UPFONCDIAG_vidCondDiag();
   HEATSENO2UPFONCDIAG_vidCalcDiag();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidFldOrFco                            */
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
/*  input uint8 Ldsd_am_f_diag_obj_rich_thd_g;                                */
/*  input uint16 Ldsd_am_f_diag_mf_emiss_thd_g;                               */
/*  input uint8 Ldsd_am_f_diag_obj_rich_thresh;                               */
/*  input uint16 Ldsd_am_f_diag_mf_emiss_thresh;                              */
/*  input boolean Ldsd_am_fld;                                                */
/*  input boolean Ldsd_am_fco;                                                */
/*  output boolean Ldsd_am_fld;                                               */
/*  output boolean Ldsd_am_fco;                                               */
/*  output boolean Ldsd_am_fld_or_fco;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidFldOrFco(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalLdsdAmFldPrev;
   boolean bLocalLdsdAmFcoPrev;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalMf_emiss_sum_uavn0;
   uint16  u16LocalLdsdAmFDiagObjRich;
   uint16  u16LocalDiagMfEmissThresh;
   uint32  u32LocalObjectif_richesse_global;


   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(Objectif_richesse_global, u32LocalObjectif_richesse_global);
   VEMS_vidGET(Mf_emiss_sum_uavn0, u16LocalMf_emiss_sum_uavn0);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalLdsdAmFDiagObjRich = (uint16)( Ldsd_am_f_diag_obj_rich_thd_g
                                           * 256);
      u16LocalDiagMfEmissThresh = Ldsd_am_f_diag_mf_emiss_thd_g;
   }
   else
   {
      u16LocalLdsdAmFDiagObjRich = (uint16)( Ldsd_am_f_diag_obj_rich_thresh
                                           * 256);
      u16LocalDiagMfEmissThresh = Ldsd_am_f_diag_mf_emiss_thresh;
   }
   bLocalLdsdAmFldPrev = Ldsd_am_fld;
   if (  (u8LocalEngine_running_state == ERUN_FULL_LOAD)
      && (u32LocalObjectif_richesse_global >= u16LocalLdsdAmFDiagObjRich)
      && (u16LocalMf_emiss_sum_uavn0 <= u16LocalDiagMfEmissThresh))
   {
      Ldsd_am_fld = 1;
   }
   else
   {
      Ldsd_am_fld = 0;
   }

   bLocalLdsdAmFcoPrev = Ldsd_am_fco;
   if (bLocalAuto_injection != 0)
   {
      Ldsd_am_fco = 0;
   }
   else
   {
      Ldsd_am_fco = 1;
   }

   if (  (  (Ldsd_am_fld == 0)
         && (bLocalLdsdAmFldPrev != 0))
      || (  (bLocalAuto_injection != 0)
         && (bLocalLdsdAmFcoPrev != 0)))
   {
      Ldsd_am_fld_or_fco = 0;
   }
   else
   {
      if (  (Ldsd_am_fco != 0)
         || (Ldsd_am_fld != 0))
      {
         Ldsd_am_fld_or_fco = 1;
      }
      else
      {
         Ldsd_am_fld_or_fco = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidIncCtDiag                           */
/* !Description :  Comptage du diagnostic                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_am_f_diag_count;                                        */
/*  output uint16 Ldsd_am_f_diag_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidIncCtDiag(void)
{
   uint32 u32LocalLdsd_am_f_diag_count;


   u32LocalLdsd_am_f_diag_count = (uint32)(Ldsd_am_f_diag_count + 1);
   Ldsd_am_f_diag_count = (uint16)MATHSRV_udtMIN(u32LocalLdsd_am_f_diag_count,
                                                 52428);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidInitDiag                            */
/* !Description :  Initialisation du diagnostic                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Ldsd_am_f_diag_fld_conf_g_delay;                             */
/*  input uint16 Ldsd_am_f_diag_fld_conf_delay;                               */
/*  input uint16 Ldsd_am_f_diag_fco_conf_g_delay;                             */
/*  input uint16 Ldsd_am_f_diag_fco_conf_delay;                               */
/*  output uint16 Ldsd_am_f_diag_count;                                       */
/*  output uint16 Ldsd_am_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidInitDiag(void)
{
   boolean bLocalAuto_injection;
   uint8   u8LocalExt_stSysGas;


   Ldsd_am_f_diag_count = 0;
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);

   if (bLocalAuto_injection != 0)
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_conf_g_delay, 5990);
      }
      else
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_conf_delay, 5990);
      }
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_conf_g_delay, 5990);
      }
      else
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_conf_delay, 5990);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidCondDiag                            */
/* !Description :  Le diagnostic fonctionnel n'est effectué qu'a certaines    */
/*                 conditions.                                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07980_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidDecTempo();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidInitTempo();                      */
/*  input boolean LsSys_bLsUsMainOxCHeatOkdiag;                               */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Temperature_eau;                                              */
/*  input st69 Saf_status;                                                    */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint16 EngM_mfAirCor;                                               */
/*  input boolean Auto_injection;                                             */
/*  input boolean VlvAct_bInhDiagPresScav;                                    */
/*  input boolean Ext_bPresGaz;                                               */
/*  input boolean Lambda_closed_loop;                                         */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input uint8 CanPurg_rOpCanPurgReq;                                        */
/*  input sint16 Ldsd_am_f_diag_water_temp_thd_g;                             */
/*  input uint8 Ldsd_am_f_diag_fld_mAir_thd_g;                                */
/*  input uint8 Ldsd_am_f_diag_fco_mAir_thd_g;                                */
/*  input sint16 Ldsd_am_f_diag_water_temp_thresh;                            */
/*  input uint8 Ldsd_am_f_diag_fld_mAir_thresh;                               */
/*  input uint8 Ldsd_am_f_diag_fco_mAir_thresh;                               */
/*  input boolean Manu_inh_diag_am_max_delay;                                 */
/*  input uint16 Ldsd_am_f_diag_count;                                        */
/*  input uint16 Ldsd_am_f_diag_max_delay;                                    */
/*  input boolean HEATSENO2UPFONCDIAG_bEnTCataPrev;                           */
/*  input boolean Ldsd_am_fld_or_fco;                                         */
/*  input uint32 HEATSENO2UPFONCDIAG_u32MfAirCor;                             */
/*  input uint8 LsMon_mfAirCorIntSenO2Us;                                     */
/*  input uint16 SenO2Us_tiInhDiag;                                           */
/*  input uint16 SenO2Us_tiInhDiag_C;                                         */
/*  input uint16 Ldsd_am_diag_ai_count;                                       */
/*  input boolean SenO2Us_bInhDiagPresScav_C;                                 */
/*  input boolean Manu_inh_Ldsd_am_diag_norm_cond;                            */
/*  input boolean SenO2Us_bInhDiagIdlCdn_C;                                   */
/*  input uint8 SenO2Us_rOpCanPurgMax_C;                                      */
/*  output boolean HEATSENO2UPFONCDIAG_bEnTCataPrev;                          */
/*  output uint32 HEATSENO2UPFONCDIAG_u32MfAirCor;                            */
/*  output uint8 LsMon_mfAirCorIntSenO2Us;                                    */
/*  output uint16 SenO2Us_tiInhDiag;                                          */
/*  output boolean Ldsd_am_diag_norm_cond;                                    */
/*  output boolean Ldsd_am_diag_cond;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidCondDiag(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalLsSys_UsMainOxCHeatOkdiag;
   boolean bLocalInhDiagSenO2UsScg;
   boolean bLocalInhDiagSenO2UsEIDiag;
   boolean bLocalDiagCataOffOn;
   boolean bLocalDiagmAirCor;
   boolean bLocalVlvAct_bInhDiagPresScav;
   boolean bLocalInhDiag;
   boolean bLocalSysGas;
   boolean bLocalExt_bPresGaz;
   boolean bLocalLdsdAmDiagCond;
   boolean bLocalLambda_closed_loop;
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalResult1;
   boolean bLocalResult2;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalSaf_status;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalDiagFldMAirThd;
   uint8   u8LocalDiagFcoMAirThd;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalEngine_running_state;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalCanPurg_rOpCanPurgReq;
   uint16  u16LocalInhDiag;
   uint16  u16LocalEngM_mfAirCor;
   sint16  s16LocalDiagWaterTempThd;
   uint32  u32LocalmAirCor;
   sint32  s32LocalWaterTemp;


   bLocalInhDiagSenO2UsScg = GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2USSCG);
   bLocalInhDiagSenO2UsEIDiag = GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2USEIDIAG);
   VEMS_vidGET(LsSys_bLsUsMainOxCHeatOkdiag,
               bLocalLsSys_UsMainOxCHeatOkdiag);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Saf_status, u8LocalSaf_status);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(EngM_mfAirCor, u16LocalEngM_mfAirCor);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(VlvAct_bInhDiagPresScav, bLocalVlvAct_bInhDiagPresScav);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(CanPurg_rOpCanPurgReq, u8LocalCanPurg_rOpCanPurgReq);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      s16LocalDiagWaterTempThd = Ldsd_am_f_diag_water_temp_thd_g;
      u8LocalDiagFldMAirThd = Ldsd_am_f_diag_fld_mAir_thd_g;
      u8LocalDiagFcoMAirThd = Ldsd_am_f_diag_fco_mAir_thd_g;
   }
   else
   {
      s16LocalDiagWaterTempThd = Ldsd_am_f_diag_water_temp_thresh;
      u8LocalDiagFldMAirThd = Ldsd_am_f_diag_fld_mAir_thresh;
      u8LocalDiagFcoMAirThd = Ldsd_am_f_diag_fco_mAir_thresh;
   }
   bLocalDiagCataOffOn = 0;
   if (bLocalAuto_injection != 0)
   {
      HEATSENO2UPFONCDIAG_vidDecTempo();
   }
   else
   {
      if (  (Manu_inh_diag_am_max_delay == 0)
         && (Ldsd_am_f_diag_count >= Ldsd_am_f_diag_max_delay))
      {
         bLocalDiagCataOffOn = 1;
         if (HEATSENO2UPFONCDIAG_bEnTCataPrev == 0)
         {
            HEATSENO2UPFONCDIAG_vidInitTempo();
         }
      }
   }
   HEATSENO2UPFONCDIAG_bEnTCataPrev = bLocalDiagCataOffOn;

   bLocalDiagmAirCor = 0;
   if (Ldsd_am_fld_or_fco != 0)
   {
      HEATSENO2UPFONCDIAG_u32MfAirCor =
         MATHSRV_u32Add_u32_u32(HEATSENO2UPFONCDIAG_u32MfAirCor,
                                (uint32)u16LocalEngM_mfAirCor);
      u32LocalmAirCor = ( ( ( HEATSENO2UPFONCDIAG_u32MfAirCor / 65536)
                          * SenO2Us_SampleTiFast_SC)
                        + ( ( ( ( HEATSENO2UPFONCDIAG_u32MfAirCor % 65536)
                              * SenO2Us_SampleTiFast_SC)
                            + 32768)
                          / 65536));
      LsMon_mfAirCorIntSenO2Us = (uint8)MATHSRV_udtMIN(u32LocalmAirCor, 255);
      if (bLocalAuto_injection != 0)
      {
         if (LsMon_mfAirCorIntSenO2Us >= u8LocalDiagFldMAirThd)
         {
            bLocalDiagmAirCor = 1;
         }
      }
      else
      {
         if (LsMon_mfAirCorIntSenO2Us >= u8LocalDiagFcoMAirThd)
         {
            bLocalDiagmAirCor = 1;
         }
      }
   }
   else
   {
      HEATSENO2UPFONCDIAG_u32MfAirCor = 0;
      LsMon_mfAirCorIntSenO2Us = 0;
   }

   bLocalSysGas = 0;
   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      bLocalSysGas = 1;
      if (SenO2Us_tiInhDiag > 0)
      {
         u16LocalInhDiag = (uint16)(SenO2Us_tiInhDiag - 1);
         SenO2Us_tiInhDiag = (uint16)MATHSRV_udtMIN(u16LocalInhDiag, 50000);
      }
   }
   else
   {
      SenO2Us_tiInhDiag = (uint16)MATHSRV_udtMIN(SenO2Us_tiInhDiag_C, 50000);
   }

   bLocalInhDiag = 0;
   if (bLocalExt_bPresGaz == 0)
   {
      bLocalInhDiag = 1;
   }
   else
   {
      if (  (bLocalSysGas != 0)
         && (SenO2Us_tiInhDiag == 0))
      {
         bLocalInhDiag = 1;
      }
   }

   s32LocalWaterTemp = (sint32)(s16LocalDiagWaterTempThd + 64);
   if (  (bLocalLsSys_UsMainOxCHeatOkdiag != 0)
      && (u8LocalVehicle_active_state == VS_RUNNING)
      && (u8LocalTemperature_eau > s32LocalWaterTemp)
      && (u8LocalSaf_status != SAF_PUMP_VALVE_ACTIVATED)
      && (bLocalInhDiagSenO2UsScg == 0)
      && (bLocalInhDiagSenO2UsEIDiag == 0)
      && (Ldsd_am_diag_ai_count == 0))
   {
      bLocalResult1 = 1;
   }
   else
   {
      bLocalResult1 = 0;
   }

   if (  (  (bLocalAuto_injection != 0)
         || (Manu_inh_diag_am_max_delay != 0)
         || (Ldsd_am_f_diag_count < Ldsd_am_f_diag_max_delay))
      && (bLocalInhDiag != 0)
      && (  (SenO2Us_bInhDiagPresScav_C != 0)
         || (bLocalVlvAct_bInhDiagPresScav == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale)
      && (bLocalFlev_low_fuel_level ==0))
   {
      bLocalResult2 = 1;
   }
   else
   {
      bLocalResult2 = 0;
   }

   if (  (bLocalResult1 != 0)
      && (bLocalResult2 != 0))
   {
      bLocalLdsdAmDiagCond = 1;
   }
   else
   {
      bLocalLdsdAmDiagCond = 0;
   }
   if (  (bLocalDiagmAirCor == 0)
      && (Manu_inh_Ldsd_am_diag_norm_cond == 0)
      && (bLocalLdsdAmDiagCond != 0)
      && (bLocalLambda_closed_loop != 0)
      && (Ldsd_am_fld_or_fco == 0)
      && (  (u8LocalEngine_running_state != ERUN_ON_IDLE)
         || (SenO2Us_bInhDiagIdlCdn_C != 0))
      && (u8LocalCanPurg_rOpCanPurgReq <= SenO2Us_rOpCanPurgMax_C))
   {
      Ldsd_am_diag_norm_cond = 1;
   }
   else
   {
      Ldsd_am_diag_norm_cond = 0;
   }
   if (  (bLocalLdsdAmDiagCond != 0)
      && (bLocalDiagmAirCor != 0))
   {
      Ldsd_am_diag_cond = 1;
   }
   else
   {
      Ldsd_am_diag_cond = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidDecTempo                            */
/* !Description :  Decrementation de Ldsd_am_diag_ai_count                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_am_diag_ai_count;                                       */
/*  output uint16 Ldsd_am_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidDecTempo(void)
{
   sint32 s32LocalLdsd_am_diag_ai_count;


   s32LocalLdsd_am_diag_ai_count = (sint32)(Ldsd_am_diag_ai_count - 1);
   Ldsd_am_diag_ai_count =
      (uint16)MATHSRV_udtCLAMP(s32LocalLdsd_am_diag_ai_count, 0, 52428);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidInitTempo                           */
/* !Description :  Initialisation de Ldsd_am_diag_ai_count                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_am_diag_delay_sensor_hot_g;                             */
/*  input uint16 Ldsd_am_diag_delay_sensor_hot;                               */
/*  output uint16 Ldsd_am_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidInitTempo(void)
{
   uint8  u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Ldsd_am_diag_ai_count =
         (uint16)MATHSRV_udtMIN(Ldsd_am_diag_delay_sensor_hot_g, 52428);
   }
   else
   {
      Ldsd_am_diag_ai_count =
         (uint16)MATHSRV_udtMIN(Ldsd_am_diag_delay_sensor_hot, 52428);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidCalcDiag                            */
/* !Description :  Activation du diagnostic                                   */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPFONCDIAG_vidDiag();                           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidNormDiag();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidIntmpDiag();                      */
/*  input boolean Ldsd_am_diag_cond;                                          */
/*  input boolean Auto_injection;                                             */
/*  input boolean Ldsd_am_diag_norm_cond;                                     */
/*  output boolean SenO2Us_bMonRunRaw_UsPlausFco;                             */
/*  output boolean SenO2Us_bMonRunRaw_UsPlausFld;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidCalcDiag(void)
{
   boolean bLocalUsPlausFld;
   boolean bLocalAuto_injection;


   bLocalUsPlausFld = 0;
   if (Ldsd_am_diag_cond != 0)
   {
      HEATSENO2UPFONCDIAG_vidDiag();
      VEMS_vidGET(Auto_injection, bLocalAuto_injection);
      if (bLocalAuto_injection !=0)
      {
         bLocalUsPlausFld = 1;
         SenO2Us_bMonRunRaw_UsPlausFco = 0;
      }
      else
      {
         SenO2Us_bMonRunRaw_UsPlausFco = 1;
      }
   }
   else
   {
      SenO2Us_bMonRunRaw_UsPlausFco = 0;
   }
   if (Ldsd_am_diag_norm_cond != 0)
   {
      bLocalUsPlausFld = 1;
      HEATSENO2UPFONCDIAG_vidNormDiag();
   }
   else
   {
      HEATSENO2UPFONCDIAG_vidIntmpDiag();
   }
   SenO2Us_bMonRunRaw_UsPlausFld = bLocalUsPlausFld;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidDiag                                */
/* !Description :  Le diagnostic vérifie que les valeurs de la tension sonde  */
/*                 sont cohérentes                                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07980_002.01                                     */
/*                 VEMS_R_11_07980_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidDecTConfD();                      */
/*  extf argret void HEATSENO2UPFONCDIAG_vidMode6();                          */
/*  extf argret void HEATSENO2UPFONCDIAG_vidIniTConfD();                      */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_am_f_diag_fld_thd_g;                                    */
/*  input uint16 Ldsd_am_f_diag_fco_thd_g;                                    */
/*  input uint16 Ldsd_am_f_diag_fld_thresh;                                   */
/*  input uint16 Ldsd_am_f_diag_fco_thresh;                                   */
/*  input boolean Ldsd_am_ena_mode_defaut;                                    */
/*  input uint16 Ldsd_am_f_diag_confirm_count;                                */
/*  output boolean Ldsd_am_ena_mode_defaut;                                   */
/*  output boolean Ldsd_am_fld_confirm;                                       */
/*  output boolean SenO2Us_bMonWaitRaw_UsPlausFco;                            */
/*  output boolean Ldsd_am_fld_failure;                                       */
/*  output boolean SenO2Us_bDgoORng_UsPlausFco;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidDiag(void)
{
   boolean bLocalAuto_injection;
   boolean bLocalAmFldFailure;
   boolean bLocalORng_UsPlausFco;
   boolean bLocalDiagEnaPrev;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalTension_sonde_amont;
   uint16  u16LocalDiagFldThd;
   uint16  u16LocalDiagFcoThd;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalDiagFldThd = Ldsd_am_f_diag_fld_thd_g;
      u16LocalDiagFcoThd = Ldsd_am_f_diag_fco_thd_g;
   }
   else
   {
      u16LocalDiagFldThd = Ldsd_am_f_diag_fld_thresh;
      u16LocalDiagFcoThd = Ldsd_am_f_diag_fco_thresh;
   }

   bLocalDiagEnaPrev = Ldsd_am_ena_mode_defaut;
   bLocalAmFldFailure = 0;
   bLocalORng_UsPlausFco = 0;
   if (  (  (bLocalAuto_injection != 0)
         && (u16LocalTension_sonde_amont < u16LocalDiagFldThd))
      || (  (bLocalAuto_injection == 0)
         && (u16LocalTension_sonde_amont > u16LocalDiagFcoThd)))
   {
      Ldsd_am_ena_mode_defaut = 1;
      /* 01_decrem_tempo_confirm_defaut */
      HEATSENO2UPFONCDIAG_vidDecTConfD();
      if (Ldsd_am_f_diag_confirm_count == 0)
      {
         if (bLocalAuto_injection != 0)
         {
            bLocalAmFldFailure = 1;
            Ldsd_am_fld_confirm = 1;
            SenO2Us_bMonWaitRaw_UsPlausFco = 1;
         }
         else
         {
            bLocalORng_UsPlausFco = 1;
            Ldsd_am_fld_confirm = 0;
            SenO2Us_bMonWaitRaw_UsPlausFco = 0;
         }
         /* 03_mode_06 */
         HEATSENO2UPFONCDIAG_vidMode6();
      }
      else
      {
         Ldsd_am_fld_confirm = 0;
         SenO2Us_bMonWaitRaw_UsPlausFco = 1;
      }
   }
   else
   {
      if (bLocalAuto_injection != 0)
      {
         Ldsd_am_fld_confirm = 1;
         SenO2Us_bMonWaitRaw_UsPlausFco =1;
      }
      else
      {
         Ldsd_am_fld_confirm = 0;
         SenO2Us_bMonWaitRaw_UsPlausFco =0;
      }
      Ldsd_am_ena_mode_defaut = 0;
      if (bLocalDiagEnaPrev != 0)
      {
         /* 02_init_tempo_confirm_defaut */
         HEATSENO2UPFONCDIAG_vidIniTConfD();
      }
      HEATSENO2UPFONCDIAG_vidMode6();
   }
   Ldsd_am_fld_failure = bLocalAmFldFailure;
   SenO2Us_bDgoORng_UsPlausFco = bLocalORng_UsPlausFco;
}
/*---------------------------- end of file -----------------------------------*/