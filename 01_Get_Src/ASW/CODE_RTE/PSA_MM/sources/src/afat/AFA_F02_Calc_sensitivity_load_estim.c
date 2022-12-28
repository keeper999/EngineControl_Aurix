/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFA                                                     */
/* !Description     : AFA Software component                                  */
/*                                                                            */
/* !Module          : AFA                                                     */
/* !Description     : AFA Software Component                                  */
/*                                                                            */
/* !File            : AFA_F02_Calc_sensitivity_load_estim.c                   */
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
/*   Model name       : AFA_F02_Calc_sensitivity_load_estim.mdl               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   adelvare                               $$Date::   27 Jul 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFA_F02_Calc_sensitivity_load_estim.h"
#include "AFA_F02_Calc_sensitivity_load_estim_private.h"
#include "AFAT.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt16 AFA_rMassBurnRg;              /* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
SInt16 AFA_rMassGrdBurnRg_agCkEx;     /* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
SInt16 AFA_rMassGrdBurnRg_agCkIn;     /* '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

/* Start for referenced model: 'AFA_F02_Calc_sensitivity_load_estim' */
void mr_AFA_F02_Calc_sensitivi_Start(void)
{
  /* Start for ModelReference: '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
  mr_AFA_F07_Residual_scave_Start();
}

/* Output and update for referenced model: 'AFA_F02_Calc_sensitivity_load_estim' */
void mr_AFA_F02_Calc_sensitivity_loa(const UInt16 *rtu_AFA_nEngFil, const
  SInt16 *rtu_AFA_agCkClsExVlvEstimRef1_p, const UInt16
  *rtu_AFA_agCkClsInVlvEstimRef1_k, const SInt16
  *rtu_AFA_agCkOpInVlvEstimRef1F_o, const UInt32 *rtu_AFA_tAirUsInVlvEstimFil,
  const UInt16 *rtu_AFA_tExMnfEstimFi2, const UInt16 *rtu_AFA_pDsThrFi2,
  const UInt16 *rtu_AFA_pExMnfEstimFi2, const UInt16
  *rtu_AFA_pAirExtEstimFil, const UInt16 *rtu_AFA_pDsThrPred_facVlvOvlp_b,
  const SInt16 *rtu_AFA_tCoMesFil, const UInt32 *rtu_AFA_facSlopEfcCorFil,
  const UInt16 *rtu_AFA_rTotLdExCorFil, const UInt16
  *rtu_AFA_mfArGrdVlv_rPresInEx, const UInt16 *rtu_AFA_mfArGrdVlv_rPresExIn,
  const UInt16 *rtu_AFA_nEngCorFil, UInt32 *rty_AFA_rTotLdGrd_pDsThr,
  SInt16 *rty_AFA_facSlopGrdEfc_agCkIn, SInt16 *rty_AFA_facOfsGrdEfc_agCkIn,
  SInt16 *rty_AFA_facOfsGrdEfc_agCkEx)
{
  /* local block i/o variables */
  SInt32 localAFA_F02_cylinder_volume_at;
  UInt32 localAFA_F09_offset_air_load_o1;
  UInt16 localAFA_F07_Residual_scavenged;
  UInt16 localAFA_F07_Residual_scaveng_m;
  UInt16 localAFA_F07_Residual_scaveng_h;
  UInt16 localAFA_F01_fresh_gas_temperat;
  UInt16 localAFA_F02_cylinder_volume__j;
  UInt16 localAFA_F03_Slop_correction_o1;
  UInt16 localAFA_F07_Residual_scaveng_a;
  SInt16 localAFA_F03_Slop_correction_o2;
  SInt16 localAFA_F07_Residual_scaveng_f;
  SInt16 localAFA_F07_Residual_scaven_f2;
  SInt16 localAFA_F07_Residual_scaveng_p;
  SInt16 localAFA_F07_Residual_scaveng_k;
  UInt16 localAFA_F05_Slop_air_load_o2;
  UInt16 localAFA_F08_burn_gas_temperatu;
  UInt16 localAFA_F06_Specific_VVT_angle;
  SInt16 localAFA_F06_Specific_VVT_ang_e;
  UInt16 localAFA_F07_Residual_scaveng_e;
  SInt16 localAFA_F07_Residual_scaveng_j;
  SInt16 localAFA_F08_burn_gas_tempera_g;
  SInt16 localAFA_F08_burn_gas_tempera_n;
  UInt8 localAFA_F04_Water_correction_t;

  /* ModelReference: '<Root>/AFA_F01_fresh_gas_temperature'
   *
   * Block requirements for '<Root>/AFA_F01_fresh_gas_temperature':
   *  1. ModelReference "AFA_F01_fresh_gas_temperature" !Trace_To : VEMS_R_11_04467_065.02 ;
   */
  mr_AFA_F01_fresh_gas_temperatur(&(*rtu_AFA_tAirUsInVlvEstimFil),
    &(*rtu_AFA_nEngFil), &localAFA_F01_fresh_gas_temperat);

  /* ModelReference: '<Root>/AFA_F02_cylinder_volume_at_close_intake_valve'
   *
   * Block requirements for '<Root>/AFA_F02_cylinder_volume_at_close_intake_valve':
   *  1. ModelReference "AFA_F02_cylinder_volume_at_close_intake_valve" !Trace_To : VEMS_R_11_04467_066.01 ;
   */
  mr_AFA_F02_cylinder_volume_at_c(&(*rtu_AFA_agCkClsInVlvEstimRef1_k),
    &localAFA_F02_cylinder_volume__j, &localAFA_F02_cylinder_volume_at);

  /* ModelReference: '<Root>/AFA_F03_Slop_correction'
   *
   * Block requirements for '<Root>/AFA_F03_Slop_correction':
   *  1. ModelReference "AFA_F03_Slop_correction" !Trace_To : VEMS_R_11_04467_067.02 ;
   */
  mr_AFA_F03_Slop_correction(&(*rtu_AFA_agCkClsInVlvEstimRef1_k),
    &(*rtu_AFA_nEngFil), &(*rtu_AFA_pDsThrFi2), &(*rtu_AFA_pAirExtEstimFil),
    &(*rtu_AFA_nEngCorFil), &localAFA_F03_Slop_correction_o1,
    &localAFA_F03_Slop_correction_o2);

  /* ModelReference: '<Root>/AFA_F04_Water_correction_temperature'
   *
   * Block requirements for '<Root>/AFA_F04_Water_correction_temperature':
   *  1. ModelReference "AFA_F04_Water_correction_temperature" !Trace_To : VEMS_R_11_04467_072.01 ;
   */
  mr_AFA_F04_Water_correction_tem(&(*rtu_AFA_nEngFil), &(*rtu_AFA_tCoMesFil),
    &localAFA_F04_Water_correction_t);

  /* ModelReference: '<Root>/AFA_F05_Slop_air_load'
   *
   * Block requirements for '<Root>/AFA_F05_Slop_air_load':
   *  1. ModelReference "AFA_F05_Slop_air_load" !Trace_To : VEMS_R_11_04467_073.01 ;
   */
  mr_AFA_F05_Slop_air_load(&localAFA_F03_Slop_correction_o1,
    &localAFA_F03_Slop_correction_o2, &localAFA_F02_cylinder_volume__j,
    &localAFA_F02_cylinder_volume_at, &localAFA_F04_Water_correction_t,
    &(*rtu_AFA_facSlopEfcCorFil), &(*rtu_AFA_pDsThrFi2),
    &localAFA_F01_fresh_gas_temperat, &(*rty_AFA_facSlopGrdEfc_agCkIn),
    &localAFA_F05_Slop_air_load_o2);

  /* ModelReference: '<Root>/AFA_F06_Specific_VVT_angle'
   *
   * Block requirements for '<Root>/AFA_F06_Specific_VVT_angle':
   *  1. ModelReference "AFA_F06_Specific_VVT_angle" !Trace_To : VEMS_R_11_04467_074.01 ;
   */
  mr_AFA_F06_Specific_VVT_angle(&(*rtu_AFA_agCkClsExVlvEstimRef1_p),
    &(*rtu_AFA_agCkOpInVlvEstimRef1F_o), &localAFA_F06_Specific_VVT_ang_e,
    &localAFA_F06_Specific_VVT_angle);

  /* ModelReference: '<Root>/AFA_F07_Residual_scavenged_reaspired_mass'
   *
   * Block requirements for '<Root>/AFA_F07_Residual_scavenged_reaspired_mass':
   *  1. ModelReference "AFA_F07_Residual_scavenged_reaspired_mass" !Trace_To : VEMS_R_11_04467_075.02 ;
   */
  mr_AFA_F07_Residual_scavenged_r(&(*rtu_AFA_nEngFil),
    &(*rtu_AFA_pDsThrPred_facVlvOvlp_b), &(*rtu_AFA_pExMnfEstimFi2),
    &(*rtu_AFA_tExMnfEstimFi2), &localAFA_F06_Specific_VVT_ang_e,
    &localAFA_F06_Specific_VVT_angle, &(*rtu_AFA_agCkOpInVlvEstimRef1F_o),
    &(*rtu_AFA_agCkClsExVlvEstimRef1_p), &(*rtu_AFA_tAirUsInVlvEstimFil),
    &(*rtu_AFA_mfArGrdVlv_rPresInEx), &(*rtu_AFA_mfArGrdVlv_rPresExIn),
    &(*rtu_AFA_nEngCorFil), &localAFA_F07_Residual_scavenged,
    &localAFA_F07_Residual_scaveng_f, &localAFA_F07_Residual_scaven_f2,
    &AFA_rMassBurnRg, &AFA_rMassGrdBurnRg_agCkEx, &AFA_rMassGrdBurnRg_agCkIn,
    &localAFA_F07_Residual_scaveng_m, &localAFA_F07_Residual_scaveng_p,
    &localAFA_F07_Residual_scaveng_k, &localAFA_F07_Residual_scaveng_j,
    &localAFA_F07_Residual_scaveng_a, &localAFA_F07_Residual_scaveng_e,
    &localAFA_F07_Residual_scaveng_h);

  /* ModelReference: '<Root>/AFA_F08_burn_gas_temperature'
   *
   * Block requirements for '<Root>/AFA_F08_burn_gas_temperature':
   *  1. ModelReference "AFA_F08_burn_gas_temperature" !Trace_To : VEMS_R_11_04467_095.01 ;
   */
  mr_AFA_F08_burn_gas_temperature(&(*rtu_AFA_tExMnfEstimFi2),
    &(*rtu_AFA_pDsThrPred_facVlvOvlp_b), &(*rtu_AFA_pExMnfEstimFi2),
    &localAFA_F07_Residual_scavenged, &localAFA_F07_Residual_scaveng_f,
    &localAFA_F07_Residual_scaven_f2, &AFA_rMassBurnRg,
    &AFA_rMassGrdBurnRg_agCkEx, &AFA_rMassGrdBurnRg_agCkIn,
    &localAFA_F07_Residual_scaveng_m, &localAFA_F07_Residual_scaveng_p,
    &localAFA_F07_Residual_scaveng_k, &localAFA_F08_burn_gas_temperatu,
    &localAFA_F08_burn_gas_tempera_g, &localAFA_F08_burn_gas_tempera_n);

  /* ModelReference: '<Root>/AFA_F09_offset_air_load'
   *
   * Block requirements for '<Root>/AFA_F09_offset_air_load':
   *  1. ModelReference "AFA_F09_offset_air_load" !Trace_To : VEMS_R_11_04467_096.02 ;
   */
  mr_AFA_F09_offset_air_load(&localAFA_F01_fresh_gas_temperat,
    &localAFA_F08_burn_gas_temperatu, &localAFA_F08_burn_gas_tempera_g,
    &localAFA_F08_burn_gas_tempera_n, &AFA_rMassBurnRg,
    &localAFA_F07_Residual_scaveng_m, &localAFA_F07_Residual_scaveng_p,
    &localAFA_F07_Residual_scaveng_k, &localAFA_F07_Residual_scaveng_j,
    &localAFA_F07_Residual_scaveng_a, &localAFA_F07_Residual_scaveng_e,
    &localAFA_F09_offset_air_load_o1, &(*rty_AFA_facOfsGrdEfc_agCkEx),
    &(*rty_AFA_facOfsGrdEfc_agCkIn));

  /* ModelReference: '<Root>/AFA_F10_Total_load_gradient'
   *
   * Block requirements for '<Root>/AFA_F10_Total_load_gradient':
   *  1. ModelReference "AFA_F10_Total_load_gradient" !Trace_To : VEMS_R_11_04467_097.01 ;
   */
  mr_AFA_F10_Total_load_gradient(&localAFA_F05_Slop_air_load_o2,
    &(*rtu_AFA_rTotLdExCorFil), &localAFA_F09_offset_air_load_o1,
    &localAFA_F07_Residual_scaveng_h, &(*rty_AFA_rTotLdGrd_pDsThr));
}

/* Model initialize function */
void mr_AFA_F02_Calc_sens_initialize(void)
{
  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F01_fresh_gas_temperature' */
  mr_AFA_F01_fresh_gas_initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F02_cylinder_volume_at_close_intake_valve' */
  mr_AFA_F02_cylinder__initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F03_Slop_correction' */
  mr_AFA_F03_Slop_corr_initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F04_Water_correction_temperature' */
  mr_AFA_F04_Water_cor_initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F05_Slop_air_load' */
  mr_AFA_F05_Slop_air__initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F06_Specific_VVT_angle' */
  mr_AFA_F06_Specific__initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F07_Residual_scavenged_reaspired_mass' */
  mr_AFA_F07_Residual__initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F08_burn_gas_temperature' */
  mr_AFA_F08_burn_gas__initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F09_offset_air_load' */
  mr_AFA_F09_offset_ai_initialize();

  /* Model Initialize fcn for ModelReference Block: '<Root>/AFA_F10_Total_load_gradient' */
  mr_AFA_F10_Total_loa_initialize();
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
