/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatPasDiagT                                             */
/* !Description     : CatPasDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatPasDiagT                                             */
/* !Description     : Private Declarations                                    */
/*                                                                            */
/* !File            : CatPasDiagT_private.h                                   */
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
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   22 Nov 2013 $*/
/******************************************************************************/
#ifndef RTW_HEADER_CatPasDiagT_private_h_
#define RTW_HEADER_CatPasDiagT_private_h_
#include "Std_Types.h"
#include "CatPasDiagT_types.h"
#include "rtwtypes.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CatMon_mO2MaxGas_Obd6Mod       ((UInt16) 1024U)
#define CatMon_mO2Max_Obd6Mod          ((UInt16) 1024U)
#define CAT_CALCUL                     ((UInt8) 4U)
#define CAT_INIT                       ((UInt8) 1U)
#define CAT_SOMME                      ((UInt8) 2U)
#define CALL_EVENT                     (-1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/
#define CatPasDiagT_START_SEC_CODE
#include "CatPasDiagT_MemMap.h"

extern void RE_CatMon_EveRst_CatPasDiag_Start(void);
extern void RE_CatMon_EveRst_CatPasDiag(void);
extern void CatPasDiagT_if_s1(void);
extern void CatPasDiagT_if_s1_j(void);
extern void RE_CatMon_SdlMid_CatPasDiag_Init(void);
extern void RE_CatMon_SdlMid_CatPasDiag_Start(void);
extern void RE_CatMon_SdlMid_CatPasDiag(void);

#define CatPasDiagT_STOP_SEC_CODE
#include "CatPasDiagT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
/* !Comment: Declare data in section "CALIB_16BIT" */
#define CatPasDiagT_START_SEC_CALIB_16BIT
#include "CatPasDiagT_MemMap.h"

extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMaxPas_Obd6Mod_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMax_Obd6Mod_B;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMes_Obd6Mod_B;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMinPas_Obd6Mod_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMinStep_Obd6Mod_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_facMin_Obd6Mod_B;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_mO2StgIniGas_Obd6Mod_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_mO2StgIni_Obd6Mod_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiDlyAuthInjAcvDiag_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiDlyInjCutInhDiag_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) CatMon_tiInhDiag_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_max;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_max_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_min;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_air_flow_rate_min_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_1_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_2_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_3_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_den_ordre_4_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_0_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_2_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_coef_num_ordre_4_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_debit_gaz_moy_B;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_dec_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_degradation_inc_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_engine_load_seuil;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_engine_load_seuil_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_regime_moteur_seuil;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_regime_moteur_seuil_g;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_temperature_seuil;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_delta_temperature_seuil_gas;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_gas;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_idle;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_inf_idle_g;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_gas;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_idle;
extern CONST(SInt16, CATPASDIAGT_CALIB) Cat_seuil_degradation_sup_idle_g;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_max_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_idle;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_min_idle_gas;
extern CONST(UInt16, CATPASDIAGT_CALIB) Cat_temperature_moy_B;
extern CONST(UInt16, CATPASDIAGT_CALIB) OxC_nEngTmrPasIntr_C;
extern CONST(UInt16, CATPASDIAGT_CALIB) OxC_tiTmrPasIntr_C;

#define CatPasDiagT_STOP_SEC_CALIB_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "CARTO_16BIT" */
#define CatPasDiagT_START_SEC_CARTO_16BIT
#include "CatPasDiagT_MemMap.h"

extern CONST(UInt16, CATPASDIAGT_CARTO) Cat_pumped_gas_bkpt_map[16];
extern CONST(UInt16, CATPASDIAGT_CARTO) Cat_temperature_bkpt_map[16];

#define CatPasDiagT_STOP_SEC_CARTO_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "CALIB_8BIT" */
#define CatPasDiagT_START_SEC_CALIB_8BIT
#include "CatPasDiagT_MemMap.h"

extern CONST(UInt8, CATPASDIAGT_CALIB) CatMon_noSelModMaxCnt_C;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_air_temp_thresh_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_calcul_count_max;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_max;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_max_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_min;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_engine_load_min_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_gear_engaged_max_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_gear_engaged_max_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_acqui_min_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_nombre_echant_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_max_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_regime_moteur_min_idle_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_1_delay;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_1_delay_g;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_2_delay;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_stable_conditions_2_delay_g;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_gas;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_idle;
extern CONST(UInt8, CATPASDIAGT_CALIB) Cat_water_temp_thresh_idle_gas;

#define CatPasDiagT_STOP_SEC_CALIB_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "CARTO_8BIT" */
#define CatPasDiagT_START_SEC_CARTO_8BIT
#include "CatPasDiagT_MemMap.h"

extern CONST(UInt8, CATPASDIAGT_CARTO) Cat_fac_dec_map[16][16];
extern CONST(UInt8, CATPASDIAGT_CARTO) Cat_fac_inc_map[16][16];
extern CONST(UInt8, CATPASDIAGT_CARTO) Cat_seuil_obd_gas_map[16][16];
extern CONST(UInt8, CATPASDIAGT_CARTO) Cat_seuil_obd_map[16][16];

#define CatPasDiagT_STOP_SEC_CARTO_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "CALIB_BOOLEAN" */
#define CatPasDiagT_START_SEC_CALIB_BOOLEAN
#include "CatPasDiagT_MemMap.h"

extern CONST(Boolean, CATPASDIAGT_CALIB) CATPASDIAGT_ACTIVE_BYP_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvEuro6Cat_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqMemORng_Cat_B;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqORngCat_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bAcvSeqORng_Cat_B;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaIntrGas_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaIntr_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaPasGas_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bEnaPas_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) CatMon_bInhMonWait_Cat_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_gas;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_idle;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_diag_continu_manu_inh_idle_g;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_mon_inhibe_fast_tracking_B;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_priorite_intrusif;
extern CONST(Boolean, CATPASDIAGT_CALIB) Cat_priorite_intrusif_gas;
extern CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagAlcEst_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagAlcRate_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) Flex_bInhDiagCatPasDiagBlby_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) OxC_bEnaTmrPasIntr_C;
extern CONST(Boolean, CATPASDIAGT_CALIB) OxC_bMonReqORngIntr_B;

#define CatPasDiagT_STOP_SEC_CALIB_BOOLEAN
#include "CatPasDiagT_MemMap.h"

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
/* !Comment: Declare data in section "INTERNAL_VAR_16BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_16BIT
#include "CatPasDiagT_MemMap.h"

extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMaxIntr_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMaxPas_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMax_Obd6ModRaw;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMesIntr_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMesPas_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMes_Obd6ModRaw;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMinIntr_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMinPas_Obd6Mod;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_facMin_Obd6ModRaw;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiDlyAuthInjAcvDiag;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiDlyInjCutInhDiag;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) CatMon_tiInhDiag;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_degradation_count_IRV_MP;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_degradation_count_idle;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) Cat_energ_aval;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_inf_idle_t;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_inf_temp;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_sup_idle_t;
extern VAR(SInt16, CATPASDIAGT_INTERNAL_VAR) Cat_seuil_degradation_sup_temp;
extern VAR(UInt16, CATPASDIAGT_INTERNAL_VAR) OxC_tiTmrPasIntr_IRV_MP;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_16BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_8BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_8BIT
#include "CatPasDiagT_MemMap.h"

extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_calcul_count_IRV_MP;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_state;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_energ_inst_aval;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_acqui;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_echant_idle_temp;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_nombre_echant_temp;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_puissance;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_stable_conditions_1_tempo;
extern VAR(UInt8, CATPASDIAGT_INTERNAL_VAR) Cat_stable_conditions_2_tempo;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_8BIT
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_BOOLEAN" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "CatPasDiagT_MemMap.h"

extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bDgoORngPas;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bDgoORngPasIdle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngPas;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngPasIdle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonRunORngRaw_Cat;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) CatMon_bMonWaitORngRaw_Cat;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_analyse_autorisee;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_cond_activ_idle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_activ;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_diagnostic;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_diagnostic_idle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_conditions_stab;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_continu_manu_inh_idle_t;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_continu_manu_inh_temp;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diag_cycle_end_idle_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_autorise_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_cycle_end_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_effectue_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_effectue_idle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_passif;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_diagnostic_ralenti;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_etat_defectueux_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_etat_defectueux_idle_IRV_MP;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_puissance_calculee;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_reinit_degrad_count;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_reinit_degrad_count_idle;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_engine_load;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_regime_moteur;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cat_stable_cond_temperature;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_calcul;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_init;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Cond_for_somme;
extern VAR(Boolean, CATPASDIAGT_INTERNAL_VAR) Seuil_obd_depasse;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "CatPasDiagT_MemMap.h"

/* !Comment: Declare data in section "INTERNAL_VAR_32BIT" */
#define CatPasDiagT_START_SEC_INTERNAL_VAR_32BIT
#include "CatPasDiagT_MemMap.h"

extern VAR(Float32, CATPASDIAGT_INTERNAL_VAR) Cat_debit_gaz_sum;
extern VAR(Float32, CATPASDIAGT_INTERNAL_VAR) Cat_temperature_sum;

#define CatPasDiagT_STOP_SEC_INTERNAL_VAR_32BIT
#include "CatPasDiagT_MemMap.h"
#endif                                 /* RTW_HEADER_CatPasDiagT_private_h_ */

/*-------------------------------- end of file -------------------------------*/
