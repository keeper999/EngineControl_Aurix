/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatPasDiagT                                             */
/* !Description     : CatPasDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatPasDiagT                                             */
/*                                                                            */
/* !File            : CatPasDiagT_Def.c                                       */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : CatPasDiagT_AUTOSAR.mdl                               */
/*   Root subsystem   : /CatPasDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/3.1/CATMON/CATPASDIAGT/CatP$*/
/* $Revision::   1.11                                                        $*/
/* $Author::   etsasson                               $$Date::   22 Nov 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "CatPasDiagT.h"
#include "CatPasDiagT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CALIB_16BIT" */
#define CatPasDiagT_START_SEC_CALIB_16BIT
#include "CatPasDiagT_MemMap.h"

CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMaxPas_Obd6Mod_C = 65535U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMax_Obd6Mod_B = 0U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMes_Obd6Mod_B = 0U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMinPas_Obd6Mod_C = 32512U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMinStep_Obd6Mod_C = 16128U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMin_Obd6Mod_B = 0U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_mO2StgIniGas_Obd6Mod_C = 16320U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_mO2StgIni_Obd6Mod_C = 16320U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiDlyAuthInjAcvDiag_C = 1U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiDlyInjCutInhDiag_C = 65525U;
CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiInhDiag_C = 50U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_max = 1966U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_max_gas = 1966U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_min = 655U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_min_gas = 655U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1 = 39577U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_gas = 39577U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_idle = 56443U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_idle_gas = 56443U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2 = 47940U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_gas = 47940U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_idle = 9489U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_idle_gas = 9489U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3 = 28325U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_gas = 28325U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_idle = 6201U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_idle_gas = 6201U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4 = 12937U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_gas = 12937U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_idle = 58490U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_idle_gas = 58490U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0 = 26737U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_gas = 26737U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_idle = 3342U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_idle_gas = 3342U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2 = 53475U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_gas = 1000U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_idle = 4011U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_idle_gas = 1000U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4 = 26737U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_gas = 26737U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_idle = 3342U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_idle_gas = 3342U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_debit_gaz_moy_B = 0U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_gas = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_idle = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_idle_gas = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc = 200U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_gas = 200U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_idle = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_idle_gas = 100U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_engine_load_seuil = 492U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_engine_load_seuil_gas = 492U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_regime_moteur_seuil = 20U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_regime_moteur_seuil_g = 20U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_temperature_seuil = 3200U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_temperature_seuil_gas = 3200U;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf = -4000;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_gas = -4000;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_idle = -1480;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_idle_g = -1480;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup = 8000;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_gas = 8000;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_idle = 2225;
CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_idle_g = 2225;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max = 30400U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_gas = 30400U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_idle = 30400U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_idle_gas = 30400U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min = 20800U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_gas = 20800U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_idle = 17600U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_idle_gas = 17600U;
CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_moy_B = 1600U;
CONST(UInt16, CATPASDIAGT_CALIB) OxC_nEngTmrPasIntr_C = 200U;
CONST(UInt16, CATPASDIAGT_CALIB) OxC_tiTmrPasIntr_C = 30000U;

#define CatPasDiagT_STOP_SEC_CALIB_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "CARTO_16BIT" */
#define CatPasDiagT_START_SEC_CARTO_16BIT
#include "CatPasDiagT_MemMap.h"

CONST(UInt16, CATPASDIAGT_CARTO) Cat_pumped_gas_bkpt_map[16] = { 52U, 197U,
  393U, 459U, 524U, 721U, 918U, 1114U, 1245U, 1442U, 1638U, 1835U, 2032U, 2163U,
  2359U, 2556U } ;

CONST(UInt16, CATPASDIAGT_CARTO) Cat_temperature_bkpt_map[16] = { 17600U,
  18400U, 19200U, 20000U, 20800U, 21600U, 22400U, 23200U, 24000U, 24800U, 25600U,
  26400U, 27200U, 28000U, 28800U, 29600U } ;

#define CatPasDiagT_STOP_SEC_CARTO_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define CatPasDiagT_START_SEC_CALIB_8BIT
#include "CatPasDiagT_MemMap.h"

CONST(UInt8, CATPASDIAGT_CALIB) CatMon_noSelModMaxCnt_C = 0U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_gas = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_idle = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_idle_gas = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_calcul_count_max = 255U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_max = 96U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_max_gas = 96U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_min = 19U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_min_gas = 19U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_gear_engaged_max_idle = 3U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_gear_engaged_max_idle_gas = 3U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min = 15U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_gas = 15U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_idle = 47U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_idle_gas = 47U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant = 47U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_gas = 47U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_idle = 160U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_idle_gas = 160U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max = 157U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_gas = 157U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_idle = 28U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_idle_gas = 28U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_gas = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_idle = 20U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_idle_gas = 20U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_1_delay = 51U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_1_delay_g = 51U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_2_delay = 26U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_2_delay_g = 26U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_gas = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_idle = 40U;
CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_idle_gas = 40U;

#define CatPasDiagT_STOP_SEC_CALIB_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "CARTO_8BIT" */
#define CatPasDiagT_START_SEC_CARTO_8BIT
#include "CatPasDiagT_MemMap.h"

CONST(UInt8, CATPASDIAGT_CARTO) Cat_fac_dec_map[16][16] = { { 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U } } ;

CONST(UInt8, CATPASDIAGT_CARTO) Cat_fac_inc_map[16][16] = { { 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U },{ 85U, 85U, 85U, 85U,
  85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 85U } } ;

CONST(UInt8, CATPASDIAGT_CARTO) Cat_seuil_obd_gas_map[16][16] = { { 157U, 115U, 98U,
  113U, 114U, 128U, 129U, 91U, 139U, 110U, 89U, 48U, 170U, 222U, 171U, 171U },
{ 157U, 102U, 175U, 175U, 175U, 156U, 162U, 140U, 167U, 132U, 157U, 108U, 162U,
  199U, 181U, 181U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 11U, 11U, 12U, 12U, 12U, 10U, 4U, 10U, 6U, 4U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 35U, 27U, 20U, 17U, 12U, 11U, 14U, 10U, 14U, 7U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 32U, 33U, 32U, 28U, 26U, 20U, 17U, 15U, 13U, 7U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 73U, 39U, 34U, 33U, 31U, 39U, 20U, 21U, 23U, 16U },{ 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 49U, 28U, 35U, 33U, 32U, 32U, 25U, 19U, 23U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 53U, 40U, 52U, 33U, 34U, 32U, 26U, 24U, 23U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 27U, 33U, 31U, 22U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 55U, 34U, 33U, 19U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 40U, 28U, 36U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 18U,
  31U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

CONST(UInt8, CATPASDIAGT_CARTO) Cat_seuil_obd_map[16][16] = { { 157U, 115U, 98U,
  113U, 114U, 128U, 129U, 91U, 139U, 110U, 89U, 48U, 170U, 222U, 171U, 171U },
{ 157U, 102U, 175U, 175U, 175U, 156U, 162U, 140U, 167U, 132U, 157U, 108U, 162U,
  199U, 181U, 181U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U },{ 0U, 0U, 0U, 0U, 0U, 0U, 11U, 11U, 12U, 12U, 12U, 10U, 4U, 10U, 6U, 4U },{ 0U,
  0U, 0U, 0U, 0U, 0U, 35U, 27U, 20U, 17U, 12U, 11U, 14U, 10U, 14U, 7U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 32U, 33U, 32U, 28U, 26U, 20U, 17U, 15U, 13U, 7U },{ 0U, 0U, 0U,
  0U, 0U, 0U, 73U, 39U, 34U, 33U, 31U, 39U, 20U, 21U, 23U, 16U },{ 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 49U, 28U, 35U, 33U, 32U, 32U, 25U, 19U, 23U },{ 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 53U, 40U, 52U, 33U, 34U, 32U, 26U, 24U, 23U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 27U, 33U, 31U, 22U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 55U, 34U, 33U, 19U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 40U, 28U, 36U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 18U,
  31U },{ 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },{ 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U } } ;

#define CatPasDiagT_STOP_SEC_CARTO_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define CatPasDiagT_START_SEC_CALIB_BOOLEAN
#include "CatPasDiagT_MemMap.h"

CONST(Boolean, CATPASDIAGT_CALIB) CATPASDIAGT_ACTIVE_BYP_C = 0;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvEuro6Cat_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqMemORng_Cat_B = 0;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqORngCat_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqORng_Cat_B = 0;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaIntrGas_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaIntr_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaPasGas_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaPas_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bInhDiagPresScav_C = 0;
CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bInhMonWait_Cat_C = 0;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_gas = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_idle = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_idle_g = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_mon_inhibe_fast_tracking_B = 0;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_priorite_intrusif = 0;
CONST(Boolean, CATPASDIAGT_CALIB) Cat_priorite_intrusif_gas = 0;
CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagAlcEst_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagAlcRate_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagBlby_C = 1;
CONST(Boolean, CATPASDIAGT_CALIB) OxC_bEnaTmrPasIntr_C = 0;
CONST(Boolean, CATPASDIAGT_CALIB) OxC_bMonReqORngIntr_B = 0;

#define CatPasDiagT_STOP_SEC_CALIB_BOOLEAN
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_16BIT
#include "CatPasDiagT_MemMap.h"

VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMaxIntr_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMaxPas_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMax_Obd6ModRaw = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMesIntr_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMesPas_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMes_Obd6ModRaw = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMinIntr_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMinPas_Obd6Mod = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMin_Obd6ModRaw = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiDlyAuthInjAcvDiag = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiDlyInjCutInhDiag = 0U;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiInhDiag = 0U;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_degradation_count_IRV_MP = 0;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_degradation_count_idle = 0;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) Cat_energ_aval = 0U;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_inf_idle_t = 0;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_inf_temp = 0;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_sup_idle_t = 0;
VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_sup_temp = 0;
VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) OxC_tiTmrPasIntr_IRV_MP = 0U;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_8BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_8BIT
#include "CatPasDiagT_MemMap.h"

VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_calcul_count_IRV_MP = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_state = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_energ_inst_aval = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_acqui = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_echant_idle_temp = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_echant_temp = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_puissance = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_stable_conditions_1_tempo = 0U;
VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_stable_conditions_2_tempo = 0U;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "CatPasDiagT_MemMap.h"

VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bDgoORngPas = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bDgoORngPasIdle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngPas = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngPasIdle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngRaw_Cat = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonWaitORngRaw_Cat = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_analyse_autorisee = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_cond_activ_idle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_activ = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_diagnostic = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_diagnostic_idle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_stab = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_continu_manu_inh_idle_t =
  FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_continu_manu_inh_temp = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_cycle_end_idle_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_autorise_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_cycle_end_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_effectue_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_effectue_idle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_passif = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_ralenti = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_etat_defectueux_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_etat_defectueux_idle_IRV_MP = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_puissance_calculee = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_reinit_degrad_count = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_reinit_degrad_count_idle = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_engine_load = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_regime_moteur = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_temperature = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_calcul = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_init = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_somme = FALSE;
VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Seuil_obd_depasse = FALSE;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "CatPasDiagT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_32BIT
#include "CatPasDiagT_MemMap.h"

VAR(Float32, CATPASDIAGT_INTERNAL_VAR) Cat_debit_gaz_sum = 0.0F;
VAR(Float32, CATPASDIAGT_INTERNAL_VAR) Cat_temperature_sum = 0.0F;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_32BIT
#include "CatPasDiagT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
