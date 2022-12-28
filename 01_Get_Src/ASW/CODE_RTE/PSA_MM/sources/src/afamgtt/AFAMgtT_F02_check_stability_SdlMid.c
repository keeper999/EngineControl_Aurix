/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software component                              */
/*                                                                            */
/* !Module          : AFAMgtT                                                 */
/* !Description     : AFAMgtT Software Component                              */
/*                                                                            */
/* !File            : AFAMgtT_F02_check_stability_SdlMid.c                    */
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
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAMgtT_F02_check_stability_SdlMid.h"
#include "AFAMgtT_F02_check_stability_SdlMid_private.h"
#include "AFAMgtT.h"
/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAMgtT_START_SEC_CODE
#include "AFAMgtT_MemMap.h"

/* Output and update for referenced model: 'AFAMgtT_F02_check_stability_SdlMid' */
void mr_AFAMgtT_F02_check_stability_(const UInt16 *rtu_EngM_rAirLdCor, const
  UInt8 *rtu_EGRVlv_stEGRMod, const UInt16 *rtu_EGRSys_rEGRReq, const
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
  *rty_AFAMgt_tiCntStabEOM, UInt32 *rty_AFAMgt_tiCntStabFacStrt)
{
  Boolean localRelationalOperator1[6];
  UInt16 localrtmin;
  SInt32 localrtmin_0;
  SInt32 localrtmin_1;
  SInt16 localAbs;
  UInt32 localtmp;

  /* Outputs for atomic SubSystem: '<S1>/F01_Afa_gear_engaged_check' *
   * Block requirements for '<S1>/F01_Afa_gear_engaged_check':
   *  1. SubSystem "F01_Afa_gear_engaged_check" !Trace_To : VEMS_R_11 _04434_006.01 ;
   */

  /* If: '<S2>/If' incorporates:
   *  ActionPort: '<S8>/Action Port'
   *  ActionPort: '<S9>/Action Port'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  SubSystem: '<S2>/F01_Afa_gear_engaged_stable_no_check'
   *  SubSystem: '<S2>/F02_Afa_gear_engaged_stable_check'
   *
   * Block requirements for '<S2>/F01_Afa_gear_engaged_stable_no_check':
   *  1. SubSystem "F01_Afa_gear_engaged_stable_no_check" !Trace_To : VEMS_R_11 _04434_007.01 ;
   *
   * Block requirements for '<S2>/F02_Afa_gear_engaged_stable_check':
   *  1. SubSystem "F02_Afa_gear_engaged_stable_check" !Trace_To : VEMS_R_11 _04434_008.01 ;
   */
  if (((*rtu_CoPt_noEgdGearCord) != (*rtu_AFAMgt_noEgdGearCordPrev)) ||
      (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S8>/Constant' */
    (*rty_AFAMgt_bStabEgdGear) = FALSE;

    /* SignalConversion: '<S8>/Signal Conversion1' incorporates:
     *  Constant: '<S8>/AFAMgt_tiDlyStabEgdGear_C'
     */
    (*rty_AFAMgt_tiCntStabEgdGear) = AFAMgt_tiDlyStabEgdGear_C;
  } else {
    /* If: '<S9>/If1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     *  ActionPort: '<S11>/Action Port'
     *  Constant: '<S9>/Constant'
     *  RelationalOperator: '<S9>/Relational Operator'
     *  SubSystem: '<S9>/F01_Afa_gear_engaged_stable'
     *  SubSystem: '<S9>/F02_Afa_gear_engaged_wait'
     *
     * Block requirements for '<S9>/F01_Afa_gear_engaged_stable':
     *  1. SubSystem "F01_Afa_gear_engaged_stable" !Trace_To : VEMS_R_11 _04434_009.01 ;
     *
     * Block requirements for '<S9>/F02_Afa_gear_engaged_wait':
     *  1. SubSystem "F02_Afa_gear_engaged_wait" !Trace_To : VEMS_R_11 _04434_010.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabEgdGearPrev) <= 0U) {
      /* Constant: '<S10>/Constant' */
      (*rty_AFAMgt_bStabEgdGear) = TRUE;

      /* SignalConversion: '<S10>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabEgdGear) = (*rtu_AFAMgt_tiCntStabEgdGearPrev);
    } else {
      /* Constant: '<S11>/Constant' */
      (*rty_AFAMgt_bStabEgdGear) = FALSE;

      /* Sum: '<S11>/Add' incorporates:
       *  Constant: '<S11>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabEgdGearPrev) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabEgdGearPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabEgdGear) = localtmp;
    }
  }

  /* end of Outputs for SubSystem: '<S1>/F01_Afa_gear_engaged_check' */

  /* Outputs for atomic SubSystem: '<S1>/F02_Afa_engine_air_load_check' *
   * Block requirements for '<S1>/F02_Afa_engine_air_load_check':
   *  1. SubSystem "F02_Afa_engine_air_load_check" !Trace_To : VEMS_R_11 _04434_011.01 ;
   */

  /* If: '<S3>/If' incorporates:
   *  ActionPort: '<S12>/Action Port'
   *  ActionPort: '<S13>/Action Port'
   *  Constant: '<S3>/AFAMgt_rAirLdDeltaMaxThd_C'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  SubSystem: '<S3>/F01_Afa_engine_air_load_stable_no_check'
   *  SubSystem: '<S3>/F02_Afa_engine_air_load_stable_check'
   *  Sum: '<S3>/Add'
   *
   * Block requirements for '<S3>/F01_Afa_engine_air_load_stable_no_check':
   *  1. SubSystem "F01_Afa_engine_air_load_stable_no_check" !Trace_To : VEMS_R_11 _04434_012.01 ;
   *
   * Block requirements for '<S3>/F02_Afa_engine_air_load_stable_check':
   *  1. SubSystem "F02_Afa_engine_air_load_stable_check" !Trace_To : VEMS_R_11 _04434_013.01 ;
   */
  if ((((((Float32)(*rtu_AFAMgt_rAirLdMaxPrev)) * 6.103515625E-005F) -
        (((Float32)(*rtu_AFAMgt_rAirLdMinPrev)) * 6.103515625E-005F)) >
       (((Float32)AFAMgt_rAirLdDeltaMaxThd_C) * 6.103515625E-005F)) ||
      (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S12>/Constant' */
    (*rty_AFAMgt_bStabAirLdCor) = FALSE;

    /* SignalConversion: '<S12>/Signal Conversion1' */
    (*rty_AFAMgt_rAirLdMax) = (*rtu_EngM_rAirLdCor);

    /* SignalConversion: '<S12>/Signal Conversion2' */
    (*rty_AFAMgt_rAirLdMin) = (*rtu_EngM_rAirLdCor);

    /* SignalConversion: '<S12>/Signal Conversion3' incorporates:
     *  Constant: '<S12>/AFAMgt_tiDlyStabAirLd_C'
     */
    (*rty_AFAMgt_tiCntStabAirLd) = AFAMgt_tiDlyStabAirLd_C;
  } else {
    /* If: '<S13>/If1' incorporates:
     *  ActionPort: '<S14>/ Afa_engine_air_load_stable_count ==0'
     *  ActionPort: '<S15>/Action Port'
     *  Constant: '<S13>/Constant'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  SubSystem: '<S13>/F01_Afa_engine_air_load_stable'
     *  SubSystem: '<S13>/F02_Afa_engine_air_load_wait'
     *
     * Block requirements for '<S13>/F01_Afa_engine_air_load_stable':
     *  1. SubSystem "F01_Afa_engine_air_load_stable" !Trace_To : VEMS_R_11 _04434_014.01 ;
     *
     * Block requirements for '<S13>/F02_Afa_engine_air_load_wait':
     *  1. SubSystem "F02_Afa_engine_air_load_wait" !Trace_To : VEMS_R_11 _04434_015.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabAirLdPrev) <= 0U) {
      /* Constant: '<S14>/Constant' */
      (*rty_AFAMgt_bStabAirLdCor) = TRUE;

      /* SignalConversion: '<S14>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabAirLd) = (*rtu_AFAMgt_tiCntStabAirLdPrev);
    } else {
      /* Constant: '<S15>/Constant' */
      (*rty_AFAMgt_bStabAirLdCor) = FALSE;

      /* Sum: '<S15>/Add' incorporates:
       *  Constant: '<S15>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabAirLdPrev) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabAirLdPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabAirLd) = localtmp;
    }

    /* MinMax: '<S13>/MinMax' */
    localrtmin = (*rtu_EngM_rAirLdCor);
    if ((*rtu_AFAMgt_rAirLdMinPrev) < (*rtu_EngM_rAirLdCor)) {
      localrtmin = (*rtu_AFAMgt_rAirLdMinPrev);
    }

    (*rty_AFAMgt_rAirLdMin) = localrtmin;

    /* MinMax: '<S13>/MinMax1' */
    localrtmin = (*rtu_EngM_rAirLdCor);
    if ((*rtu_AFAMgt_rAirLdMaxPrev) > (*rtu_EngM_rAirLdCor)) {
      localrtmin = (*rtu_AFAMgt_rAirLdMaxPrev);
    }

    (*rty_AFAMgt_rAirLdMax) = localrtmin;
  }

  /* end of Outputs for SubSystem: '<S1>/F02_Afa_engine_air_load_check' */

  /* Outputs for atomic SubSystem: '<S1>/F03_pressure_dynamic_corr_check' *
   * Block requirements for '<S1>/F03_pressure_dynamic_corr_check':
   *  1. SubSystem "F03_pressure_dynamic_corr_check" !Trace_To : VEMS_R_11 _04434_016.01 ;
   */

  /* Abs: '<S4>/Abs' */
  if ((*rtu_InM_pDynCorPres) < 0) {
    localtmp = (UInt32)(-(*rtu_InM_pDynCorPres));
    if (localtmp > 32767U) {
      localAbs = MAX_int16_T;
    } else {
      localAbs = (SInt16)localtmp;
    }
  } else {
    localAbs = (*rtu_InM_pDynCorPres);
  }

  /* If: '<S4>/If1' incorporates:
   *  ActionPort: '<S16>/Action Port'
   *  ActionPort: '<S17>/Action Port'
   *  Constant: '<S4>/AFAMgt_pDynCorMaxThd_C'
   *  RelationalOperator: '<S4>/Relational Operator1'
   *  SubSystem: '<S4>/F01_pressure_dynamic_corr_no_check'
   *  SubSystem: '<S4>/F02_pressure_dynamic_corr_check'
   *
   * Block requirements for '<S4>/F01_pressure_dynamic_corr_no_check':
   *  1. SubSystem "F01_pressure_dynamic_corr_no_check" !Trace_To : VEMS_R_11 _04434_017.01 ;
   *
   * Block requirements for '<S4>/F02_pressure_dynamic_corr_check':
   *  1. SubSystem "F02_pressure_dynamic_corr_check" !Trace_To : VEMS_R_11 _04434_018.01 ;
   */
  if ((localAbs > AFAMgt_pDynCorMaxThd_C) || (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S16>/Constant' */
    (*rty_AFAMgt_bIdcNotDynCorPres) = FALSE;

    /* SignalConversion: '<S16>/Signal Conversion' incorporates:
     *  Constant: '<S16>/AFAMgt_tiDlyNotDynCorPres_C'
     */
    (*rty_AFAMgt_tiCntNotDynCorPres) = AFAMgt_tiDlyNotDynCorPres_C;
  } else {
    /* If: '<S17>/If1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     *  ActionPort: '<S19>/Action Port'
     *  Constant: '<S17>/Constant'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  SubSystem: '<S17>/F01_pressure_dynamic_corr_stable'
     *  SubSystem: '<S17>/F02_pressure_dynamic_corr_wait'
     *
     * Block requirements for '<S17>/F01_pressure_dynamic_corr_stable':
     *  1. SubSystem "F01_pressure_dynamic_corr_stable" !Trace_To : VEMS_R_11 _04434_019.01 ;
     *
     * Block requirements for '<S17>/F02_pressure_dynamic_corr_wait':
     *  1. SubSystem "F02_pressure_dynamic_corr_wait" !Trace_To : VEMS_R_11 _04434_020.01 ;
     */
    if ((*rtu_AFAMgt_tiCntNotDynCorPresPr) <= 0U) {
      /* Constant: '<S18>/Constant' */
      (*rty_AFAMgt_bIdcNotDynCorPres) = TRUE;

      /* SignalConversion: '<S18>/Signal Conversion' */
      (*rty_AFAMgt_tiCntNotDynCorPres) = (*rtu_AFAMgt_tiCntNotDynCorPresPr);
    } else {
      /* Constant: '<S19>/Constant' */
      (*rty_AFAMgt_bIdcNotDynCorPres) = FALSE;

      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S19>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntNotDynCorPresPr) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntNotDynCorPresPr)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntNotDynCorPres) = localtmp;
    }
  }

  /* end of Outputs for SubSystem: '<S1>/F03_pressure_dynamic_corr_check' */

  /* Outputs for atomic SubSystem: '<S1>/F04_EgrRateStability' *
   * Block requirements for '<S1>/F04_EgrRateStability':
   *  1. SubSystem "F04_EgrRateStability" !Trace_To : VEMS_R_11 _04434_021.01 ;
   */

  /* If: '<S5>/If' incorporates:
   *  ActionPort: '<S20>/Action Port'
   *  ActionPort: '<S21>/Action Port'
   *  Constant: '<S5>/AFAMgt_rOpEGRDeltaMaxThd_C'
   *  Constant: '<S5>/EGRVlv_stEgrPrvtFoul_SC'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  SubSystem: '<S5>/F01_Afa_EGR_rate_stable_no_check'
   *  SubSystem: '<S5>/F02_Afa_EGR_rate_stable_check'
   *  Sum: '<S5>/Add'
   *
   * Block requirements for '<S5>/F01_Afa_EGR_rate_stable_no_check':
   *  1. SubSystem "F01_Afa_EGR_rate_stable_no_check" !Trace_To : VEMS_R_11 _04434_022.01 ;
   *
   * Block requirements for '<S5>/F02_Afa_EGR_rate_stable_check':
   *  1. SubSystem "F02_Afa_EGR_rate_stable_check" !Trace_To : VEMS_R_11 _04434_023.01 ;
   */
  if ((((*rtu_EGRVlv_stEGRMod) == EGRVlv_stEgrPrvtFoul_SC) || (((((Float32)
           (*rtu_AFAMgt_rEGRMaxPrev)) * 0.001953125F) - (((Float32)
           (*rtu_AFAMgt_rEGRMinPrev)) * 0.001953125F)) > (((Float32)
          AFAMgt_rOpEGRDeltaMaxThd_C) * 0.001953125F))) ||
      (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S20>/Constant4' */
    (*rty_AFAMgt_bIdcStabRatOpEGR) = FALSE;

    /* DataTypeConversion: '<S20>/Data Type Conversion1' */
    if ((*rtu_EGRSys_rEGRReq) > 255) {
      (*rty_AFAMgt_rEGRMax) = MAX_uint8_T;
    } else {
      (*rty_AFAMgt_rEGRMax) = (UInt8)(*rtu_EGRSys_rEGRReq);
    }

    /* DataTypeConversion: '<S20>/Data Type Conversion2' */
    if ((*rtu_EGRSys_rEGRReq) > 255) {
      (*rty_AFAMgt_rEGRMin) = MAX_uint8_T;
    } else {
      (*rty_AFAMgt_rEGRMin) = (UInt8)(*rtu_EGRSys_rEGRReq);
    }

    /* SignalConversion: '<S20>/Signal Conversion3' incorporates:
     *  Constant: '<S20>/AFAMgt_tiDlyStabRatOpEGR_C'
     */
    (*rty_AFAMgt_tiCntStabRatOpEGR) = AFAMgt_tiDlyStabRatOpEGR_C;
  } else {
    /* If: '<S21>/If' incorporates:
     *  ActionPort: '<S22>/Action Port'
     *  ActionPort: '<S23>/Action Port'
     *  Constant: '<S21>/Constant'
     *  RelationalOperator: '<S21>/Relational Operator'
     *  SubSystem: '<S21>/F01_Afa_egr_rate_stable'
     *  SubSystem: '<S21>/F02_Afa_egr_rate_stable_Wait'
     *
     * Block requirements for '<S21>/F01_Afa_egr_rate_stable':
     *  1. SubSystem "F01_Afa_egr_rate_stable" !Trace_To : VEMS_R_11 _04434_024.01 ;
     *
     * Block requirements for '<S21>/F02_Afa_egr_rate_stable_Wait':
     *  1. SubSystem "F02_Afa_egr_rate_stable_Wait" !Trace_To : VEMS_R_11 _04434_025.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabRatOpEGRPre) <= 0U) {
      /* Constant: '<S22>/Constant4' */
      (*rty_AFAMgt_bIdcStabRatOpEGR) = TRUE;

      /* SignalConversion: '<S22>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabRatOpEGR) = (*rtu_AFAMgt_tiCntStabRatOpEGRPre);
    } else {
      /* Constant: '<S23>/Constant4' */
      (*rty_AFAMgt_bIdcStabRatOpEGR) = FALSE;

      /* Sum: '<S23>/Add1' incorporates:
       *  Constant: '<S23>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabRatOpEGRPre) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabRatOpEGRPre)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabRatOpEGR) = localtmp;
    }

    /* MinMax: '<S21>/MinMax' */
    localrtmin_0 = (*rtu_EGRSys_rEGRReq);
    localrtmin_1 = (*rtu_AFAMgt_rEGRMinPrev);
    if (((UInt32)localrtmin_1) < ((UInt32)localrtmin_0)) {
      localrtmin_0 = localrtmin_1;
    }

    (*rty_AFAMgt_rEGRMin) = (UInt8)localrtmin_0;

    /* MinMax: '<S21>/MinMax1' */
    localrtmin_0 = (*rtu_EGRSys_rEGRReq);
    localrtmin_1 = (*rtu_AFAMgt_rEGRMaxPrev);
    if (((UInt32)localrtmin_1) > ((UInt32)localrtmin_0)) {
      localrtmin_0 = localrtmin_1;
    }

    if (((UInt32)localrtmin_0) > 255U) {
      (*rty_AFAMgt_rEGRMax) = MAX_uint8_T;
    } else {
      (*rty_AFAMgt_rEGRMax) = (UInt8)localrtmin_0;
    }
  }

  /* end of Outputs for SubSystem: '<S1>/F04_EgrRateStability' */

  /* Outputs for atomic SubSystem: '<S1>/F05_EOM_check' *
   * Block requirements for '<S1>/F05_EOM_check':
   *  1. SubSystem "F05_EOM_check" !Trace_To : VEMS_R_11 _04434_026.01 ;
   */

  /* If: '<S6>/If' incorporates:
   *  ActionPort: '<S24>/Action Port'
   *  ActionPort: '<S25>/Action Port'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  SubSystem: '<S6>/F01_EOM_stable_no_check'
   *  SubSystem: '<S6>/F02_EOM_stable_check'
   *
   * Block requirements for '<S6>/F01_EOM_stable_no_check':
   *  1. SubSystem "F01_EOM_stable_no_check" !Trace_To : VEMS_R_11 _04434_027.01 ;
   *
   * Block requirements for '<S6>/F02_EOM_stable_check':
   *  1. SubSystem "F02_EOM_stable_check" !Trace_To : VEMS_R_11 _04434_028.01 ;
   */
  if ((((SInt32)(*rtu_EOM_bTranMod)) != ((SInt32)(*rtu_AFAMgt_bTranModPrev))) ||
      (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S24>/Constant' */
    (*rty_AFAMgt_bStabEOM) = FALSE;

    /* SignalConversion: '<S24>/Signal Conversion1' incorporates:
     *  Constant: '<S24>/AFAMgt_tiDlyStabEOM_C'
     */
    (*rty_AFAMgt_tiCntStabEOM) = AFAMgt_tiDlyStabEOM_C;
  } else {
    /* If: '<S25>/If1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     *  ActionPort: '<S27>/Action Port'
     *  Constant: '<S25>/Constant'
     *  RelationalOperator: '<S25>/Relational Operator'
     *  SubSystem: '<S25>/F01_EOM_stable'
     *  SubSystem: '<S25>/F02_EOM_wait'
     *
     * Block requirements for '<S25>/F01_EOM_stable':
     *  1. SubSystem "F01_EOM_stable" !Trace_To : VEMS_R_11 _04434_029.01 ;
     *
     * Block requirements for '<S25>/F02_EOM_wait':
     *  1. SubSystem "F02_EOM_wait" !Trace_To : VEMS_R_11 _04434_030.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabEOMPrev) <= 0U) {
      /* Constant: '<S26>/Constant' */
      (*rty_AFAMgt_bStabEOM) = TRUE;

      /* SignalConversion: '<S26>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabEOM) = (*rtu_AFAMgt_tiCntStabEOMPrev);
    } else {
      /* Constant: '<S27>/Constant' */
      (*rty_AFAMgt_bStabEOM) = FALSE;

      /* Sum: '<S27>/Add' incorporates:
       *  Constant: '<S27>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabEOMPrev) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabEOMPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabEOM) = localtmp;
    }
  }

  /* end of Outputs for SubSystem: '<S1>/F05_EOM_check' */

  /* Outputs for atomic SubSystem: '<S1>/F06_Fuel_Compensation_check' *
   * Block requirements for '<S1>/F06_Fuel_Compensation_check':
   *  1. SubSystem "F06_Fuel_Compensation_check" !Trace_To : VEMS_R_11 _04434_031.01 ;
   */

  /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
   *  Constant: '<S7>/AFAMgt_facStrtCorCylThd_C'
   */
  for (localrtmin_0 = 0; localrtmin_0 < 6; localrtmin_0++) {
    localRelationalOperator1[localrtmin_0] = (((UInt32)
      (rtu_InjSys_prm_facStrtCorCyl[(localrtmin_0)] << 4)) >= ((UInt32)
      (AFAMgt_facStrtCorCylThd_C * 15)));
  }

  /* If: '<S7>/If1' incorporates:
   *  ActionPort: '<S28>/Action Port'
   *  ActionPort: '<S29>/Action Port'
   *  Logic: '<S7>/Logical Operator'
   *  SubSystem: '<S7>/F01_Fuel_Compensation_no_check'
   *  SubSystem: '<S7>/F02_Fuel_Compensation_check'
   *
   * Block requirements for '<S7>/F01_Fuel_Compensation_no_check':
   *  1. SubSystem "F01_Fuel_Compensation_no_check" !Trace_To : VEMS_R_11 _04434_032.01 ;
   *
   * Block requirements for '<S7>/F02_Fuel_Compensation_check':
   *  1. SubSystem "F02_Fuel_Compensation_check" !Trace_To : VEMS_R_11 _04434_033.01 ;
   */
  if (((((((localRelationalOperator1[0]) || (localRelationalOperator1[1])) ||
          (localRelationalOperator1[2])) || (localRelationalOperator1[3])) ||
        (localRelationalOperator1[4])) || (localRelationalOperator1[5])) ||
      (*rtu_AFAMgt_bIdcInhChk)) {
    /* Constant: '<S28>/Constant' */
    (*rty_AFAMgt_bStabFacStrtCor) = FALSE;

    /* SignalConversion: '<S28>/Signal Conversion1' incorporates:
     *  Constant: '<S28>/AFAMgt_tiDlyStabFacStrt_C'
     */
    (*rty_AFAMgt_tiCntStabFacStrt) = AFAMgt_tiDlyStabFacStrt_C;
  } else {
    /* If: '<S29>/If1' incorporates:
     *  ActionPort: '<S30>/Action Port'
     *  ActionPort: '<S31>/Action Port'
     *  Constant: '<S29>/Constant'
     *  RelationalOperator: '<S29>/Relational Operator'
     *  SubSystem: '<S29>/F01_Fuel_Compensation_stable'
     *  SubSystem: '<S29>/F02_Fuel_Compensation_wait'
     *
     * Block requirements for '<S29>/F01_Fuel_Compensation_stable':
     *  1. SubSystem "F01_Fuel_Compensation_stable" !Trace_To : VEMS_R_11 _04434_034.01 ;
     *
     * Block requirements for '<S29>/F02_Fuel_Compensation_wait':
     *  1. SubSystem "F02_Fuel_Compensation_wait" !Trace_To : VEMS_R_11 _04434_035.01 ;
     */
    if ((*rtu_AFAMgt_tiCntStabFacStrtPrev) <= 0U) {
      /* Constant: '<S30>/Constant' */
      (*rty_AFAMgt_bStabFacStrtCor) = TRUE;

      /* SignalConversion: '<S30>/Signal Conversion' */
      (*rty_AFAMgt_tiCntStabFacStrt) = (*rtu_AFAMgt_tiCntStabFacStrtPrev);
    } else {
      /* Constant: '<S31>/Constant' */
      (*rty_AFAMgt_bStabFacStrtCor) = FALSE;

      /* Sum: '<S31>/Add' incorporates:
       *  Constant: '<S31>/AFAMgt_tiSampleMid_SC'
       */
      localtmp = (*rtu_AFAMgt_tiCntStabFacStrtPrev) - ((((UInt32)
        AFAMgt_tiSampleMid_SC) * 52429U) >> 19);
      if (localtmp > (*rtu_AFAMgt_tiCntStabFacStrtPrev)) {
        localtmp = 0U;
      }

      (*rty_AFAMgt_tiCntStabFacStrt) = localtmp;
    }
  }

  /* end of Outputs for SubSystem: '<S1>/F06_Fuel_Compensation_check' */

  /* SignalConversion: '<Root>/Signal Conversion1' */
  (*rty_AFAMgt_noEgdGearCordHld) = (*rtu_CoPt_noEgdGearCord);

  /* SignalConversion: '<Root>/Signal Conversion2' */
  (*rty_AFAMgt_bTranModHld) = (*rtu_EOM_bTranMod);
}

/* Model initialize function */
void mr_AFAMgtT_F02_check_initialize(void)
{
  /* (no initialization code required) */
}

#define AFAMgtT_STOP_SEC_CODE
#include "AFAMgtT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
