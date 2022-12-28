/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPPERDDIAG                                     */
/* !Description     : HEATSENO2UPPERDDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPPERDDIAG                                     */
/* !Description     : DIAGNOSTIC DE LA SONDE A OXYGENE AMONT                  */
/*                                                                            */
/* !File            : HEATSENO2UPPERDDIAG_FCT1.C                              */
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
/*   1 / HEATSENO2UPPERDDIAG_vidInit                                          */
/*   2 / HEATSENO2UPPERDDIAG_vidIniOutput                                     */
/*   3 / HEATSENO2UPPERDDIAG_vidDiagCond                                      */
/*   4 / HEATSENO2UPPERDDIAG_vidStateMgr                                      */
/*   5 / HEATSENO2UPPERDDIAG_vidCounters                                      */
/*   6 / HEATSENO2UPPERDDIAG_vidCntLean                                       */
/*   7 / HEATSENO2UPPERDDIAG_vidIniCnLean                                     */
/*   8 / HEATSENO2UPPERDDIAG_vidCntRich                                       */
/*   9 / HEATSENO2UPPERDDIAG_vidIniCnRich                                     */
/*   10 / HEATSENO2UPPERDDIAG_vidPerdLean                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5012863 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPPERDDIA$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2UPPERDDIAG_L.h"
#include "HEATSENO2UPPERDDIAG_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidInit                                */
/* !Description :  Met à zéro certaines variables au début du calcul          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Oxy_sens_diag_test_completed;                              */
/*  output uint8 Oxy_period_tests;                                            */
/*  output uint8 Os_period_tests_done;                                        */
/*  output boolean Oxy_sens_diag_test_finished;                               */
/*  output uint16 LsMon_tiPerUs;                                              */
/*  output uint16 LsMon_noRatEfcLsUsPer;                                      */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidInit(void)
{
   /* 01_Initialisation */
   VEMS_vidSET(Oxy_sens_diag_test_completed, 0);
   Oxy_period_tests = 0;
   Os_period_tests_done = 0;
   VEMS_vidSET(Oxy_sens_diag_test_finished, 0);
   LsMon_tiPerUs = 0;
   VEMS_vidSET(LsMon_noRatEfcLsUsPer, 100);
   Dnstr_modifier_temp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidIniOutput                           */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  output boolean E_monitor_up_stream_oxy_sensor;                            */
/*  output boolean SenO2Us_bAcvSeqMemOxyApvPerd;                              */
/*  output boolean SenO2Us_bAcvSeqMemOxySensPerd;                             */
/*  output boolean SenO2Us_bAcvSeqOxyApvPerd;                                 */
/*  output boolean SenO2Us_bAcvSeqOxySensPerd;                                */
/*  output st63 State_ups_oxy_sens;                                           */
/*  output boolean Enable_period_lean;                                        */
/*  output boolean Enable_period_rich;                                        */
/*  output boolean HEATSENO2UPPERDDIAG_bOxySensPrev;                          */
/*  output boolean HEATSENO2UPPERDDIAG_bOxyApvPrev;                           */
/*  output uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;                             */
/*  output uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;                             */
/*  output uint8 HEATSENO2UPPERDDIAG_u8SysGasPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidIniOutput(void)
{
   uint8 u8LocalExt_stSysGas;


   VEMS_vidSET(E_monitor_up_stream_oxy_sensor, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqMemOxyApvPerd, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqMemOxySensPerd, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqOxyApvPerd, 0);
   VEMS_vidSET(SenO2Us_bAcvSeqOxySensPerd, 0);
   VEMS_vidSET(State_ups_oxy_sens, SYNCH_TO_UPS_OXY_SENS_START);
   Enable_period_lean = 0;
   Enable_period_rich = 0;
   HEATSENO2UPPERDDIAG_bOxySensPrev = 0;
   HEATSENO2UPPERDDIAG_bOxyApvPrev = 0;
   VEMS_vidSET(SenO2Us_PerDiag_FacMax_Obd6Mod, 0);
   VEMS_vidSET(SenO2Us_PerDiag_FacMes_Obd6Mod, 0);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   HEATSENO2UPPERDDIAG_u8SysGasPrev =
      (uint8)MATHSRV_udtMIN(u8LocalExt_stSysGas, 3);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidDiagCond                            */
/* !Description :  Cette fonction définit les conditions de diagnostic par    */
/*                 rapport à l’état moteur et aux paramètres de celui-ci      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_08083_001.01                                     */
/*                 VEMS_R_11_08083_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input boolean Flev_low_gas_level;                                         */
/*  input boolean Engine_stabilised;                                          */
/*  input boolean Lambda_closed_loop;                                         */
/*  input boolean Lfbk_on_enlean_clamp;                                       */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  input boolean Oxy_sens_diag_test_finished;                                */
/*  input uint8 Temperature_eau;                                              */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Ext_bPresGaz;                                               */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean VlvAct_bInhDiagPresScav;                                    */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint8 Oxy_sens_min_water_temp_gas;                                  */
/*  input uint16 Oxy_sens_min_engine_load_gas;                                */
/*  input uint8 Oxy_sens_min_engine_speed_gas;                                */
/*  input uint8 Oxy_sens_min_water_temp;                                      */
/*  input uint16 Oxy_sens_min_engine_load;                                    */
/*  input uint8 Oxy_sens_min_engine_speed;                                    */
/*  input boolean HEATSENO2UPPERDDIAG_bEnleanPrev;                            */
/*  input uint16 Lfbk_on_enlean_clamp_delay_c;                                */
/*  input uint16 Lfbk_on_enlean_clamp_delay;                                  */
/*  input boolean HEATSENO2UPPERDDIAG_bEnrichPrev;                            */
/*  input uint16 Lfbk_on_enrich_clamp_delay_c;                                */
/*  input uint16 Lfbk_on_enrich_clamp_delay;                                  */
/*  input uint16 SenO2Us_PerDiag_tiInhDiag;                                   */
/*  input uint16 SenO2Us_PerDiag_tiInhDiag_C;                                 */
/*  input boolean SenO2Us_bInhPerDiagPresScav_C;                              */
/*  input boolean HEATSENO2UPPERDDIAG_bTimeout1;                              */
/*  input boolean HEATSENO2UPPERDDIAG_bTimeout2;                              */
/*  output uint16 Lfbk_on_enlean_clamp_delay;                                 */
/*  output boolean HEATSENO2UPPERDDIAG_bTimeout1;                             */
/*  output uint16 Lfbk_on_enrich_clamp_delay;                                 */
/*  output boolean HEATSENO2UPPERDDIAG_bTimeout2;                             */
/*  output uint16 SenO2Us_PerDiag_tiInhDiag;                                  */
/*  output boolean E_monitor_up_stream_oxy_sensor;                            */
/*  output boolean HEATSENO2UPPERDDIAG_bEnleanPrev;                           */
/*  output boolean HEATSENO2UPPERDDIAG_bEnrichPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidDiagCond(void)
{
   boolean bLocalInhPerDiag;
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalFlev_low_gas_level;
   boolean bLocalFlevLowLevel;
   boolean bLocalVlvAct_bInhDiagPresScav;
   boolean bLocalExt_bPresGaz;
   boolean bLocalEngine_stabilised;
   boolean bLocalLambda_closed_loop;
   boolean bLocalLfbk_on_enlean_clamp;
   boolean bLocalLfbk_on_enrich_clamp;
   boolean bLocalOxySensDiagTestFinished;
   boolean bLocalEmonitorUpStreamOxySens;
   boolean bLocalCond;
   boolean bLocalCondition;
   uint8   u8LocalTemperature_eau;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalOxySensMinWater;
   uint8   u8LocalOxySensMinEngineSpeed;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalEngine_load;
   uint16  u16LocalOxySensMinEngineLoad;
   uint16  u16LocalEnleanTransitCount;
   uint16  u16LocalEnrichTransitCount;
   sint32  s32LocalCounter;


   bLocalInhPerDiag = GDGAR_bGetFRM(FRM_FRM_INHPERDIAG);
   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(Flev_low_gas_level, bLocalFlev_low_gas_level);
   VEMS_vidGET(Engine_stabilised, bLocalEngine_stabilised);
   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidGET(Lfbk_on_enlean_clamp, bLocalLfbk_on_enlean_clamp);
   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);
   VEMS_vidGET(Oxy_sens_diag_test_finished, bLocalOxySensDiagTestFinished);
   VEMS_vidGET(Temperature_eau, u8LocalTemperature_eau);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Ext_bPresGaz, bLocalExt_bPresGaz);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(VlvAct_bInhDiagPresScav, bLocalVlvAct_bInhDiagPresScav);
   VEMS_vidGET(CoPTSt_stEng,u8LocalCoPTSt_stEng);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      bLocalFlevLowLevel = bLocalFlev_low_gas_level;
      u8LocalOxySensMinWater = Oxy_sens_min_water_temp_gas;
      u16LocalOxySensMinEngineLoad = Oxy_sens_min_engine_load_gas;
      u8LocalOxySensMinEngineSpeed = Oxy_sens_min_engine_speed_gas;
   }
   else
   {
      bLocalFlevLowLevel = bLocalFlev_low_fuel_level;
      u8LocalOxySensMinWater = Oxy_sens_min_water_temp;
      u16LocalOxySensMinEngineLoad = Oxy_sens_min_engine_load;
      u8LocalOxySensMinEngineSpeed = Oxy_sens_min_engine_speed;
   }

   if (  (HEATSENO2UPPERDDIAG_bEnleanPrev == 0)
      && (bLocalLfbk_on_enlean_clamp != 0))
   {
      Lfbk_on_enlean_clamp_delay =
         (uint16)MATHSRV_udtMIN(Lfbk_on_enlean_clamp_delay_c, 1000);
      if (Lfbk_on_enlean_clamp_delay == 0)
      {
         HEATSENO2UPPERDDIAG_bTimeout1 = 1;
      }
      else
      {
         HEATSENO2UPPERDDIAG_bTimeout1 = 0;
      }
   }
   else
   {
      if (Lfbk_on_enlean_clamp_delay > 0)
      {
         u16LocalEnleanTransitCount = (uint16)(Lfbk_on_enlean_clamp_delay - 1);
         Lfbk_on_enlean_clamp_delay =
            (uint16)MATHSRV_udtMIN(u16LocalEnleanTransitCount, 1000);
         if (Lfbk_on_enlean_clamp_delay == 0)
         {
            HEATSENO2UPPERDDIAG_bTimeout1 = 1;
         }
         else
         {
            HEATSENO2UPPERDDIAG_bTimeout1 = 0;
         }
      }
   }

   if (  (HEATSENO2UPPERDDIAG_bEnrichPrev == 0)
      && (bLocalLfbk_on_enrich_clamp != 0))
   {
      Lfbk_on_enrich_clamp_delay =
         (uint16)MATHSRV_udtMIN(Lfbk_on_enrich_clamp_delay_c, 1000);
      if (Lfbk_on_enrich_clamp_delay == 0)
      {
         HEATSENO2UPPERDDIAG_bTimeout2 = 1;
      }
      else
      {
         HEATSENO2UPPERDDIAG_bTimeout2 = 0;
      }
   }
   else
   {
      if (Lfbk_on_enrich_clamp_delay > 0)
      {
         u16LocalEnrichTransitCount = (uint16)(Lfbk_on_enrich_clamp_delay - 1);
         Lfbk_on_enrich_clamp_delay =
            (uint16)MATHSRV_udtMIN(u16LocalEnrichTransitCount, 1000);
         if (Lfbk_on_enrich_clamp_delay == 0)
         {
            HEATSENO2UPPERDDIAG_bTimeout2 = 1;
         }
         else
         {
            HEATSENO2UPPERDDIAG_bTimeout2 = 0;
         }
      }
   }

   if (  (u8LocalExt_stSysGas != Ext_stTranGslGas_SC)
      && (u8LocalExt_stSysGas != Ext_stTranGasGsl_SC))
   {
      s32LocalCounter = SenO2Us_PerDiag_tiInhDiag - 1;
      SenO2Us_PerDiag_tiInhDiag =
         (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 50000);
      bLocalCond = 1;
   }
   else
   {
      SenO2Us_PerDiag_tiInhDiag =
         (uint16)MATHSRV_udtMIN(SenO2Us_PerDiag_tiInhDiag_C, 50000);
      bLocalCond = 0;
   }

   if (  (bLocalInhPerDiag == 0)
      && (bLocalFlevLowLevel == 0)
      && (bLocalEngine_stabilised != 0)
      && (bLocalLambda_closed_loop != 0)
      && (bLocalOxySensDiagTestFinished == 0)
      && (u8LocalTemperature_eau > u8LocalOxySensMinWater)
      && (u16LocalEngine_load > u16LocalOxySensMinEngineLoad)
      && (u8LocalRegime_moteur_32 > u8LocalOxySensMinEngineSpeed)
      && (  (bLocalExt_bPresGaz == 0)
         || (  (bLocalCond != 0)
            && (SenO2Us_PerDiag_tiInhDiag == 0)))
      && (  (SenO2Us_bInhPerDiagPresScav_C != 0)
         || (bLocalVlvAct_bInhDiagPresScav == 0)))
   {
      bLocalCondition = 1;
   }
   else
   {
      bLocalCondition = 0;
   }

   if (  (bLocalCondition != 0)
      && (  (bLocalLfbk_on_enlean_clamp == 0)
         || (HEATSENO2UPPERDDIAG_bTimeout1 == 0))
      && (  (bLocalLfbk_on_enrich_clamp == 0)
         || (HEATSENO2UPPERDDIAG_bTimeout2 == 0))
      && (u8LocalCoPTSt_stEng != Coupe_cale))
   {
      bLocalEmonitorUpStreamOxySens = 1;
   }
   else
   {
      bLocalEmonitorUpStreamOxySens = 0;
   }
   VEMS_vidSET(E_monitor_up_stream_oxy_sensor, bLocalEmonitorUpStreamOxySens);
   HEATSENO2UPPERDDIAG_bEnleanPrev = bLocalLfbk_on_enlean_clamp;
   HEATSENO2UPPERDDIAG_bEnrichPrev = bLocalLfbk_on_enrich_clamp;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidStateMgr                            */
/* !Description :  Diagramme d’état qui défini l’état dans lequel la sonde se */
/*                 trouve et créé les balises pour le calcul de la période    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPerdRich();                       */
/*  extf argret void HEATSENO2UPPERDDIAG_vidSensPerEf();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPerdLean();                       */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input st63 State_ups_oxy_sens;                                            */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean E_monitor_up_stream_oxy_sensor;                             */
/*  input uint16 Dnstr_modifier_time_scale;                                   */
/*  input boolean Lambda_slow_mode;                                           */
/*  input uint16 Oxy_sens_upper_voltage_thd_gas_c;                            */
/*  input uint16 Oxy_sens_lower_voltage_thd_gas_c;                            */
/*  input uint16 Oxy_sens_upper_voltage_thresh_c;                             */
/*  input uint16 Oxy_sens_lower_voltage_thresh_c;                             */
/*  input uint16 Oxy_sens_lower_voltage_thresh;                               */
/*  input boolean SenO2Us_bInhPerRich_C;                                      */
/*  input uint16 Oxy_sens_upper_voltage_thresh;                               */
/*  input boolean SenO2Us_bInhPerLean_C;                                      */
/*  input uint16 Oxy_ups_tempo_lean;                                          */
/*  input uint16 Oxy_ups_tempo_rich;                                          */
/*  output uint16 Oxy_sens_upper_voltage_thresh;                              */
/*  output uint16 Oxy_sens_lower_voltage_thresh;                              */
/*  output st63 State_ups_oxy_sens;                                           */
/*  output boolean Enable_period_lean;                                        */
/*  output boolean Enable_period_rich;                                        */
/*  output uint16 Dnstr_modifier_temp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidStateMgr(void)
{
   /* 03_Automate_OxySensPerd */
   boolean bLocalEmonitorUpStreamOxySens;
   boolean bLocalLambda_slow_mode;
   uint8   u8LocalState_ups_oxy_sens;
   uint8   u8LocalExt_stSysGas;
   uint16  u16LocalTension_sonde_amont;
   uint16  u16LocalOxy_sens_upper_volt_thr;
   uint16  u16LocalOxy_sens_lower_volt_thr;
   uint16  u16LocalDnstr_modifier_time_scal;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(E_monitor_up_stream_oxy_sensor, bLocalEmonitorUpStreamOxySens);
   VEMS_vidGET(Dnstr_modifier_time_scale, u16LocalDnstr_modifier_time_scal);
   VEMS_vidGET(Lambda_slow_mode, bLocalLambda_slow_mode);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalOxy_sens_upper_volt_thr = Oxy_sens_upper_voltage_thd_gas_c;
      u16LocalOxy_sens_lower_volt_thr = Oxy_sens_lower_voltage_thd_gas_c;
   }
   else
   {
      u16LocalOxy_sens_upper_volt_thr = Oxy_sens_upper_voltage_thresh_c;
      u16LocalOxy_sens_lower_volt_thr = Oxy_sens_lower_voltage_thresh_c;
   }
   Oxy_sens_upper_voltage_thresh =
      (uint16)MATHSRV_udtMIN(u16LocalOxy_sens_upper_volt_thr, 1024);
   Oxy_sens_lower_voltage_thresh =
      (uint16)MATHSRV_udtMIN(u16LocalOxy_sens_lower_volt_thr, 1024);

   switch (u8LocalState_ups_oxy_sens)
   {
      case SYNCH_TO_UPS_OXY_SENS_START:
         if (bLocalEmonitorUpStreamOxySens != 0)
         {
            if (  (u16LocalTension_sonde_amont < Oxy_sens_lower_voltage_thresh)
               && (SenO2Us_bInhPerRich_C ==0))
            {
               u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_RICH;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
            else
            {
               if (  ( u16LocalTension_sonde_amont
                     > Oxy_sens_upper_voltage_thresh)
                  && (SenO2Us_bInhPerLean_C == 0))
               {
                  u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_LEAN;
                  VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
               }
            }
         }
         break;

      case SYNCH_TO_UPS_OXY_SENS_LEAN:
         if (bLocalEmonitorUpStreamOxySens == 0)
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont < Oxy_sens_lower_voltage_thresh)
            {
               Enable_period_lean = 1;
               if (bLocalLambda_slow_mode == 0)
               {
                  Dnstr_modifier_temp = 0;
               }
               else
               {
                  Dnstr_modifier_temp = u16LocalDnstr_modifier_time_scal;
               }
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_LEAN;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
         }
         break;

      case SYNCH_TO_UPS_OXY_SENS_RICH:
         if (bLocalEmonitorUpStreamOxySens == 0)
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont > Oxy_sens_upper_voltage_thresh)
            {
               Enable_period_rich = 1;
               if (bLocalLambda_slow_mode == 0)
               {
                  Dnstr_modifier_temp = 0;
               }
               else
               {
                  Dnstr_modifier_temp = u16LocalDnstr_modifier_time_scal;
               }
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_RICH;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
         }
         break;

      case UPS_OXY_SENS_LEAN:
         if (  (  (u16LocalTension_sonde_amont < Oxy_sens_lower_voltage_thresh)
               && (  (  Oxy_ups_tempo_lean
                     >= (uint16)(MAX_OXY_SENS_TEMPO_L * 100))
                  || (  Oxy_ups_tempo_rich
                     >= (uint16)(MAX_OXY_SENS_TEMPO_R * 100))))
            || (bLocalEmonitorUpStreamOxySens == 0))
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont >= Oxy_sens_lower_voltage_thresh)
            {
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_TRANSIT_TO_RICH;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
         }
         break;

      case UPS_OXY_SENS_RICH:
         if (  (  (u16LocalTension_sonde_amont > Oxy_sens_upper_voltage_thresh)
               && (  (  Oxy_ups_tempo_rich
                     >= (uint16)(MAX_OXY_SENS_TEMPO_R * 100))
                  || (  Oxy_ups_tempo_lean
                     >= (uint16)(MAX_OXY_SENS_TEMPO_L * 100))))
            || (bLocalEmonitorUpStreamOxySens == 0))
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont <= Oxy_sens_upper_voltage_thresh)
            {
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_TRANSIT_TO_LEAN;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
         }
         break;

      case UPS_OXY_SENS_TRANSIT_TO_RICH:
         if (bLocalEmonitorUpStreamOxySens == 0)
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont < Oxy_sens_lower_voltage_thresh)
            {
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_LEAN;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
            else
            {
               if (u16LocalTension_sonde_amont > Oxy_sens_upper_voltage_thresh)
               {
                  HEATSENO2UPPERDDIAG_vidPerdRich();
                  HEATSENO2UPPERDDIAG_vidSensPerEf();
                  u8LocalState_ups_oxy_sens = UPS_OXY_SENS_RICH;
                  VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
               }
            }
         }
         break;

      case UPS_OXY_SENS_TRANSIT_TO_LEAN:
         if (bLocalEmonitorUpStreamOxySens == 0)
         {
            u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
            VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            Enable_period_lean = 0;
            Enable_period_rich = 0;
            Dnstr_modifier_temp = 0;
         }
         else
         {
            if (u16LocalTension_sonde_amont > Oxy_sens_upper_voltage_thresh)
            {
               u8LocalState_ups_oxy_sens = UPS_OXY_SENS_RICH;
               VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
            }
            else
            {
               if (u16LocalTension_sonde_amont < Oxy_sens_lower_voltage_thresh)
               {
                  HEATSENO2UPPERDDIAG_vidPerdLean();
                  HEATSENO2UPPERDDIAG_vidSensPerEf();
                  u8LocalState_ups_oxy_sens = UPS_OXY_SENS_LEAN;
                  VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
               }
            }
         }
         break;

      default:
         u8LocalState_ups_oxy_sens = SYNCH_TO_UPS_OXY_SENS_START;
         VEMS_vidSET(State_ups_oxy_sens, u8LocalState_ups_oxy_sens);
         Enable_period_lean = 0;
         Enable_period_rich = 0;
         Dnstr_modifier_temp = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCounters                            */
/* !Description :  Compteurs temporels pour le calcul de la période           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidIniCnLean();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCntLean();                        */
/*  extf argret void HEATSENO2UPPERDDIAG_vidIniCnRich();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCntRich();                        */
/*  input boolean Enable_period_lean;                                         */
/*  input boolean Enable_period_rich;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCounters(void)
{
   /* 04_Counters */
   if (Enable_period_lean == 0)
   {
      HEATSENO2UPPERDDIAG_vidIniCnLean();
   }
   else
   {
      HEATSENO2UPPERDDIAG_vidCntLean();
   }

   if (Enable_period_rich == 0)
   {
      HEATSENO2UPPERDDIAG_vidIniCnRich();
   }
   else
   {
      HEATSENO2UPPERDDIAG_vidCntRich();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCntLean                             */
/* !Description :  Incrémentation de la variable Oxy_ups_tempo_lean           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_tempo_lean;                                          */
/*  output uint16 Oxy_ups_tempo_lean;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCntLean(void)
{
   if (Oxy_ups_tempo_lean < 26214)
   {
      Oxy_ups_tempo_lean = (uint16)(Oxy_ups_tempo_lean + 1);
   }
   else
   {
      Oxy_ups_tempo_lean = 26214;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidIniCnLean                           */
/* !Description :  Initialisation de la variable Oxy_ups_tempo_lean           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Oxy_ups_tempo_lean;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidIniCnLean(void)
{
   Oxy_ups_tempo_lean = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCntRich                             */
/* !Description :  Incrémentation de la variable Oxy_ups_tempo_rich           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_tempo_rich;                                          */
/*  output uint16 Oxy_ups_tempo_rich;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCntRich(void)
{
   if (Oxy_ups_tempo_rich < 26214)
   {
      Oxy_ups_tempo_rich = (uint16)(Oxy_ups_tempo_rich + 1);
   }
   else
   {
      Oxy_ups_tempo_rich = 26214;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidIniCnRich                           */
/* !Description :  Initialisation de la variable Oxy_ups_tempo_rich           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Oxy_ups_tempo_rich;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidIniCnRich(void)
{
   Oxy_ups_tempo_rich = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPerdLean                            */
/* !Description :  Cette fonction fait le bilan des pannes présentes          */
/*                 concernant la période, les temps de réponse et le mark     */
/*                 space ratio                                                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCrPrdLean();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCalcPerdL();                      */
/*  extf argret void HEATSENO2UPPERDDIAG_vidCrPrdRich();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input boolean Enable_period_lean;                                         */
/*  input uint16 Min_oxy_sens_amfr_gas_c;                                     */
/*  input uint16 Min_oxy_sens_amfr_c;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPerdLean(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalEngM_mfTotExCor;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(EngM_mfTotExCor, u16LocalEngM_mfTotExCor);

   if (Enable_period_lean != 0)
   {
      HEATSENO2UPPERDDIAG_vidCrPrdLean();
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         if (u16LocalEngM_mfTotExCor >= Min_oxy_sens_amfr_gas_c)
         {
            HEATSENO2UPPERDDIAG_vidCalcPerdL();
         }
      }
      else
      {
         if (u16LocalEngM_mfTotExCor >= Min_oxy_sens_amfr_c)
         {
            HEATSENO2UPPERDDIAG_vidCalcPerdL();
         }
      }
   }
   else
   {
      HEATSENO2UPPERDDIAG_vidCrPrdRich();
   }
}
/*------------------------------- end of file --------------------------------*/