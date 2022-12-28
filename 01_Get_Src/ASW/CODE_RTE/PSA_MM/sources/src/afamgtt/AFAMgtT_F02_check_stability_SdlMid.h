/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT_F02_check_stability_SdlMid                      */
/*                                                                            */
/* !File            : AFAMgtT_F02_check_stability_SdlMid.h                    */
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
/*   Model name       : AFAMgtT_F02_check_stability_SdlMid.mdl                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M10-AFAMgtT/5-SO$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Jul 2011 $*/
/******************************************************************************/
#ifndef RTW_HEADER_AFAMgtT_F02_check_stability_SdlMid_h_
#define RTW_HEADER_AFAMgtT_F02_check_stability_SdlMid_h_
#ifndef AFAMgtT_F02_check_stability_SdlMid_COMMON_INCLUDES_
# define AFAMgtT_F02_check_stability_SdlMid_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "AFAMgtT_F02_check_stability_SdlMid_import.h"
#endif                                 /* AFAMgtT_F02_check_stability_SdlMid_COMMON_INCLUDES_ */

#include "AFAMgtT_F02_check_stability_SdlMid_types.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTION DECLARATION                                                       */
/******************************************************************************/

/* !Comment: Declare code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Model reference registration function */
extern void mr_AFAMgtT_F02_check_initialize(void);


extern void mr_AFAMgtT_F02_check_stability_(const UInt16 *rtu_EngM_rAirLdCor,
  const UInt8 *rtu_EGRVlv_stEGRMod, const UInt16 *rtu_EGRSys_rEGRReq, const
  SInt16 *rtu_InM_pDynCorPres, const UInt8 *rtu_CoPt_noEgdGearCord, const
  Boolean *rtu_EOM_bTranMod, const UInt16 rtu_InjSys_prm_facStrtCorCyl[6],
  const Boolean *rtu_AFAMgt_bIdcInhChk, const UInt16
  *rtu_AFAMgt_rAirLdMaxPrev, const UInt16 *rtu_AFAMgt_rAirLdMinPrev, const
  UInt32 *rtu_AFAMgt_tiCntStabAirLdPrev, const UInt8 *rtu_AFAMgt_rEGRMaxPrev,
  const UInt8 *rtu_AFAMgt_rEGRMinPrev, const UInt32
  *rtu_AFAMgt_tiCntStabRatOpEGRPre, const UInt32
  *rtu_AFAMgt_tiCntNotDynCorPresPr, const UInt32
  *rtu_AFAMgt_tiCntStabEgdGearPrev, const UInt8 *rtu_AFAMgt_noEgdGearCordPrev,
  const Boolean *rtu_AFAMgt_bTranModPrev, const UInt32
  *rtu_AFAMgt_tiCntStabEOMPrev, const UInt32 *rtu_AFAMgt_tiCntStabFacStrtPrev,
  Boolean *rty_AFAMgt_bStabAirLdCor, Boolean *rty_AFAMgt_bIdcStabRatOpEGR,
  Boolean *rty_AFAMgt_bIdcNotDynCorPres, Boolean *rty_AFAMgt_bStabEgdGear,
  Boolean *rty_AFAMgt_bStabEOM, Boolean *rty_AFAMgt_bStabFacStrtCor,
  UInt16 *rty_AFAMgt_rAirLdMax, UInt16 *rty_AFAMgt_rAirLdMin, UInt32
  *rty_AFAMgt_tiCntStabAirLd, UInt8 *rty_AFAMgt_rEGRMax, UInt8
  *rty_AFAMgt_rEGRMin, UInt32 *rty_AFAMgt_tiCntStabRatOpEGR, UInt32
  *rty_AFAMgt_tiCntNotDynCorPres, UInt32 *rty_AFAMgt_tiCntStabEgdGear, UInt8
  *rty_AFAMgt_noEgdGearCordHld, Boolean *rty_AFAMgt_bTranModHld, UInt32
  *rty_AFAMgt_tiCntStabEOM, UInt32 *rty_AFAMgt_tiCntStabFacStrt);

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S17>/Signal Conversion1' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : AFAMgtT_F02_check_stability_SdlMid
 * '<S1>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability
 * '<S2>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F01_Afa_gear_engaged_check
 * '<S3>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F02_Afa_engine_air_load_check
 * '<S4>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F03_pressure_dynamic_corr_check
 * '<S5>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F04_EgrRateStability
 * '<S6>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F05_EOM_check
 * '<S7>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F06_Fuel_Compensation_check
 * '<S8>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F01_Afa_gear_engaged_check/F01_Afa_gear_engaged_stable_no_check
 * '<S9>'   : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F01_Afa_gear_engaged_check/F02_Afa_gear_engaged_stable_check
 * '<S10>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F01_Afa_gear_engaged_check/F02_Afa_gear_engaged_stable_check/F01_Afa_gear_engaged_stable
 * '<S11>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F01_Afa_gear_engaged_check/F02_Afa_gear_engaged_stable_check/F02_Afa_gear_engaged_wait
 * '<S12>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F02_Afa_engine_air_load_check/F01_Afa_engine_air_load_stable_no_check
 * '<S13>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F02_Afa_engine_air_load_check/F02_Afa_engine_air_load_stable_check
 * '<S14>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F02_Afa_engine_air_load_check/F02_Afa_engine_air_load_stable_check/F01_Afa_engine_air_load_stable
 * '<S15>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F02_Afa_engine_air_load_check/F02_Afa_engine_air_load_stable_check/F02_Afa_engine_air_load_wait
 * '<S16>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F03_pressure_dynamic_corr_check/F01_pressure_dynamic_corr_no_check
 * '<S17>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F03_pressure_dynamic_corr_check/F02_pressure_dynamic_corr_check
 * '<S18>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F03_pressure_dynamic_corr_check/F02_pressure_dynamic_corr_check/F01_pressure_dynamic_corr_stable
 * '<S19>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F03_pressure_dynamic_corr_check/F02_pressure_dynamic_corr_check/F02_pressure_dynamic_corr_wait
 * '<S20>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F04_EgrRateStability/F01_Afa_EGR_rate_stable_no_check
 * '<S21>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F04_EgrRateStability/F02_Afa_EGR_rate_stable_check
 * '<S22>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F04_EgrRateStability/F02_Afa_EGR_rate_stable_check/F01_Afa_egr_rate_stable
 * '<S23>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F04_EgrRateStability/F02_Afa_EGR_rate_stable_check/F02_Afa_egr_rate_stable_Wait
 * '<S24>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F05_EOM_check/F01_EOM_stable_no_check
 * '<S25>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F05_EOM_check/F02_EOM_stable_check
 * '<S26>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F05_EOM_check/F02_EOM_stable_check/F01_EOM_stable
 * '<S27>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F05_EOM_check/F02_EOM_stable_check/F02_EOM_wait
 * '<S28>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F06_Fuel_Compensation_check/F01_Fuel_Compensation_no_check
 * '<S29>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F06_Fuel_Compensation_check/F02_Fuel_Compensation_check
 * '<S30>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F06_Fuel_Compensation_check/F02_Fuel_Compensation_check/F01_Fuel_Compensation_stable
 * '<S31>'  : AFAMgtT_F02_check_stability_SdlMid/F01_check_stability/F06_Fuel_Compensation_check/F02_Fuel_Compensation_check/F02_Fuel_Compensation_wait
 */

/*-
 * Requirements for '<Root>': AFAMgtT_F02_check_stability_SdlMid
 */
#endif                                 /* RTW_HEADER_AFAMgtT_F02_check_stability_SdlMid_h_ */

/*-------------------------------- end of file -------------------------------*/
