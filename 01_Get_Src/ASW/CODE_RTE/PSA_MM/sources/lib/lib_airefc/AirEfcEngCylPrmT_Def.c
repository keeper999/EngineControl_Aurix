/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirEfcEngCylPrmT                                        */
/* !Description     : AirEfcEngCylPrmT Software Component                     */
/*                                                                            */
/* !Module          : AirEfcEngCylPrmT                                        */
/*                                                                            */
/* !File            : AirEfcEngCylPrmT_Def.c                                  */
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
/*   Model name       : AirEfcEngCylPrmT_AUTOSAR.mdl                          */
/*   Root subsystem   : /AirEfcEngCylPrmT                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M04-AirEfcEngCyl$*/
/* $Revision::   1.3                                                         $*/
/* $Author::   adelvare                               $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirEfcEngCylPrmT.h"
#include "AirEfcEngCylPrmT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Comment: Define data in section "CARTO_16BIT" */
#define AirEfcEngCylPrmT_START_SEC_CARTO_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) AirEfc_facLfpChrExpAtm_M[11][18] = { {65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U}, {65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U}, {65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U}, {65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U}, {65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U}, {65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U}, {65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U}, {65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U}, {65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U}, {65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U}, {65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U} } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) AirEfc_facLfpChrExpBoost_M[88] = {
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U,
  65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U, 65535U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) AirEfc_facTFu_T[16] = { 904U, 924U, 943U,
  963U, 982U, 1000U, 1018U, 1036U, 1054U, 1071U, 1088U, 1104U, 1121U, 1137U,
  1153U, 1169U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_agCkClsExVlvClrOfs_T[18] = { 0U,
  2185U, 3277U, 4369U, 6554U, 8738U, 10923U, 13107U, 15292U, 17476U, 19661U,
  21845U, 24030U, 26214U, 28399U, 30583U, 32768U, 34953U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_agCkClsInVlvClrOfs_T[18] = { 0U,
  2185U, 3277U, 4369U, 6554U, 8738U, 10923U, 13107U, 15292U, 17476U, 19661U,
  21845U, 24030U, 26214U, 28399U, 30583U, 32768U, 34953U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_agCkOpExVlvClrOfs_T[18] = { 0U,
  2185U, 3277U, 4369U, 6554U, 8738U, 10923U, 13107U, 15292U, 17476U, 19661U,
  21845U, 24030U, 26214U, 28399U, 30583U, 32768U, 34953U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_agCkOpInVlvClrOfs_T[18] = { 0U,
  2185U, 3277U, 4369U, 6554U, 8738U, 10923U, 13107U, 15292U, 17476U, 19661U,
  21845U, 24030U, 26214U, 28399U, 30583U, 32768U, 34953U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_cppFu_T[16] = { 100U, 100U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U }
;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_dstExVlvClrX_A[18] = { 0U, 655U,
  1311U, 1966U, 2621U, 3277U, 3932U, 4587U, 5243U, 5898U, 6554U, 7864U, 8520U,
  9175U, 9830U, 10486U, 11141U, 11796U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_dstExVlvClr_M[13][14] = { {0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U} } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_dstInVlvClrX_A[18] = { 0U, 655U,
  1311U, 1966U, 2621U, 3277U, 3932U, 4587U, 5243U, 5898U, 6554U, 7864U, 8520U,
  9175U, 9830U, 10486U, 11141U, 11796U } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_dstInVlvClr_M[13][14] = { {0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U} } ;

CONST(SInt16, AIREFCENGCYLPRMT_CARTO) EngM_tCoStrtY_A[13] = { -40, -20, 0, 10,
  20, 30, 40, 50, 60, 70, 80, 90, 120 } ;

CONST(UInt16, AIREFCENGCYLPRMT_CARTO) EngM_tiEngRunX_A[14] = { 0U, 10U, 20U,
  30U, 40U, 50U, 60U, 70U, 80U, 90U, 120U, 150U, 200U, 300U } ;

#define AirEfcEngCylPrmT_STOP_SEC_CARTO_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "CALIB_16BIT" */
#define AirEfcEngCylPrmT_START_SEC_CALIB_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

CONST(SInt16, AIREFCENGCYLPRMT_CALIB) AirEfc_agInj1BegOfs_C = 0;
CONST(SInt16, AIREFCENGCYLPRMT_CALIB) AirEfc_agInj1EndOfs_C = 0;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) AirEfc_facMassAirScv_C = 100U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkClsExVlvRef0Ref1_C = 52429U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkClsInVlvRef0Ref1_C = 49730U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkExWdLawRef0_C = 17733U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkInWdLawRef0_C = 17733U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkOpExVlvRef0Ref1_C = 52429U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_agCkOpInVlvRef0Ref1_C = 49730U;
CONST(UInt16, AIREFCENGCYLPRMT_CALIB) EngM_facStoich_C = 10700U;

#define AirEfcEngCylPrmT_STOP_SEC_CALIB_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "CALIB_8BIT" */
#define AirEfcEngCylPrmT_START_SEC_CALIB_8BIT
#include "AirEfcEngCylPrmT_MemMap.h"

CONST(UInt8, AIREFCENGCYLPRMT_CALIB) EngM_cppAirBurn_C = 43U;
CONST(UInt8, AIREFCENGCYLPRMT_CALIB) EngM_cppAir_C = 128U;

#define AirEfcEngCylPrmT_STOP_SEC_CALIB_8BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "CALIB_BOOLEAN" */
#define AirEfcEngCylPrmT_START_SEC_CALIB_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"

CONST(Boolean, AIREFCENGCYLPRMT_CALIB) AcvMP_noVlvMdl_C = 0;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) AirEfc_bAcvEngSpdCorScv_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) AirEfc_bAcvEngSpdCorSlop_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) AirEfc_bAcvGDIOfs_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) AirEfc_bTMixtCylGDI_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) EngM_bClsExVlvOfs_C = 0;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) EngM_bItBurnRate_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) EngM_bOpInVlvOfs_C = 0;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) EngM_bTMixtCyl_C = 1;
CONST(Boolean, AIREFCENGCYLPRMT_CALIB) EngM_bdstVlvClr_C = 1;

#define AirEfcEngCylPrmT_STOP_SEC_CALIB_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_32BIT" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_32BIT
#include "AirEfcEngCylPrmT_MemMap.h"

VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkInj_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkVlvOvlp_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCk_facTDC_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv1_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv2_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facAirScv_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facChgCorSlopEfcMax_MP =
  0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facChgCorSlopEfcMin_MP =
  0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facChgCorSlopEfc_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorAtmSlopEfc_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorBoostSlopEfc_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorMassBurnRg_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facCorSlopEfc_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facMassFlowCor_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTAirUsInVlv_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTBurnCyl_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTCo_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTExSqrt_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_facTInSqrt_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfAirScvRed_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfBurnRspgRedBas_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_mfBurnRspgRedCor_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rFuStmMass_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassAirScvTot_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgBoostCorSat_MP =
  0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgBoostCor_MP =
  0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgCorSat_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgCor_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRgTot_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRspgTot_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurnRspg_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rMassBurn_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresDsThr_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresEngScv_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresEng_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rPresExMnf_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_rVolCyl_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_SumcppBurnMass_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_SumcppMass_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkClsExVlvClrOfs_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkClsInVlvClrOfs_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkOpExVlvClrOfs_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_agCkOpInVlvClrOfs_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facAirtMixt_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facFuSteam_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_facFutMixt_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_rTotLdExMax_MP = 0.0F;
VAR(Float32, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_rTotLd_MP = 0.0F;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_16BIT" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

VAR(SInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_agCkPosnVlvOvlp_MP = 0;
VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_nEngScv_MP = 0U;
VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_nEngSlop_MP = 0U;
VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_dstExVlvClr_MP = 0U;
VAR(UInt16, AIREFCENGCYLPRMT_INTERNAL_VAR) EngM_dstInVlvClr_MP = 0U;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AirEfcEngCylPrmT_MemMap.h"

/* !Comment: Define data in section "INTERNAL_VAR_BOOLEAN" */
#define AirEfcEngCylPrmT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"

VAR(Boolean, AIREFCENGCYLPRMT_INTERNAL_VAR) AirEfc_bMassBurnRgCor_MP = FALSE;

#define AirEfcEngCylPrmT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AirEfcEngCylPrmT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
