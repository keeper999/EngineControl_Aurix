/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : InMdlT                                                  */
/* !Description     : InMdlT Software Component                               */
/*                                                                            */
/* !Module          : InMdlT                                                  */
/* !Description     : InMdlT Software Component                               */
/*                                                                            */
/* !File            : InMdlT.c                                                */
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
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : InMdlT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /InMdlT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M02-InMdlT/5-SOF$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   09 Jul 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InMdlT.h"
#include "InMdlT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S226>/F00_Load_transient_detection_chart1' */
#define IN_ACCEL                       (1U)
#define IN_DECEL                       (2U)
#define IN_STEADY                      (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define InMdlT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InMdlT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InMdlT InMdlT_B;

/* Block states (auto storage) */
D_Work_InMdlT InMdlT_DWork;

#define InMdlT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "InMdlT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "AirEfcEngCylPrmT_compatibility.h"
#define INMDLT_AIREFCENGCYLPRMT_MAJOR_VERSION_REQ 4
#define INMDLT_AIREFCENGCYLPRMT_MINOR_VERSION_REQ 2
#define INMDLT_AIREFCENGCYLPRMT_PATCH_VERSION_REQ 0
#define INMDLT_AIREFCENGCYLPRMT_VERSION_REQ (INMDLT_AIREFCENGCYLPRMT_PATCH_VERSION_REQ + INMDLT_AIREFCENGCYLPRMT_MINOR_VERSION_REQ*1000 + INMDLT_AIREFCENGCYLPRMT_MAJOR_VERSION_REQ*1000000)
#if INMDLT_AIREFCENGCYLPRMT_VERSION_REQ > AIREFCENGCYLPRMT_VERSION
#error AirEfcEngCylPrmT version is not compatible with current SWC version
#endif

#include "VemsRtLibT_compatibility.h"
#define INMDLT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define INMDLT_VEMSRTLIBT_MINOR_VERSION_REQ 13
#define INMDLT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define INMDLT_VEMSRTLIBT_VERSION_REQ (INMDLT_VEMSRTLIBT_PATCH_VERSION_REQ + INMDLT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + INMDLT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if INMDLT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define InMdlT_START_SEC_CODE
#include "InMdlT_MemMap.h"

void InMdlT_ASYNC1(int controlPortIdx)
{
}

void InMdlT_ASYNC2(int controlPortIdx)
{
}

void InMdlT_ASYNC3(int controlPortIdx)
{
}

void InMdlT_ASYNC4(int controlPortIdx)
{
}

void InMdlT_ASYNC5(int controlPortIdx)
{
}

void InMdlT_ASYNC6(int controlPortIdx)
{
}

void InMdlT_ASYNC7(int controlPortIdx)
{
}

void InMdlT_ASYNC8(int controlPortIdx)
{
}

void InMdlT_ASYNC9(int controlPortIdx)
{
}

void InMdlT_ASYNC10(int controlPortIdx)
{
}

void InMdlT_ASYNC11(int controlPortIdx)
{
}

void InMdlT_ASYNC12(int controlPortIdx)
{
}

void InMdlT_ASYNC13(int controlPortIdx)
{
}

void InMdlT_ASYNC14(int controlPortIdx)
{
}

void InMdlT_ASYNC15(int controlPortIdx)
{
}

void InMdlT_ASYNC16(int controlPortIdx)
{
}

void InMdlT_ASYNC17(int controlPortIdx)
{
}

void InMdlT_ASYNC18(int controlPortIdx)
{
}

void InMdlT_ASYNC19(int controlPortIdx)
{
}

void InMdlT_ASYNC20(int controlPortIdx)
{
}

void InMdlT_ASYNC21(int controlPortIdx)
{
}

void InMdlT_ASYNC22(int controlPortIdx)
{
}

void InMdlT_ASYNC23(int controlPortIdx)
{
}

void InMdlT_ASYNC24(int controlPortIdx)
{
}

void InMdlT_ASYNC25(int controlPortIdx)
{
}

void InMdlT_ASYNC26(int controlPortIdx)
{
}

void InMdlT_ASYNC27(int controlPortIdx)
{
}

void InMdlT_ASYNC28(int controlPortIdx)
{
}

void InMdlT_ASYNC29(int controlPortIdx)
{
}

void InMdlT_ASYNC30(int controlPortIdx)
{
}

void InMdlT_ASYNC31(int controlPortIdx)
{
}

void InMdlT_ASYNC32(int controlPortIdx)
{
}

void InMdlT_ASYNC33(int controlPortIdx)
{
}

void InMdlT_ASYNC34(int controlPortIdx)
{
}

void InMdlT_ASYNC35(int controlPortIdx)
{
}

void InMdlT_ASYNC36(int controlPortIdx)
{
}

void InMdlT_ASYNC37(int controlPortIdx)
{
}

void InMdlT_ASYNC38(int controlPortIdx)
{
}

void InMdlT_ASYNC39(int controlPortIdx)
{
}

void InMdlT_ASYNC40(int controlPortIdx)
{
}

void InMdlT_ASYNC41(int controlPortIdx)
{
}

void InMdlT_ASYNC42(int controlPortIdx)
{
}

void InMdlT_ASYNC43(int controlPortIdx)
{
}

void InMdlT_ASYNC44(int controlPortIdx)
{
}

void InMdlT_ASYNC45(int controlPortIdx)
{
}

void InMdlT_ASYNC46(int controlPortIdx)
{
}

void InMdlT_ASYNC47(int controlPortIdx)
{
}

void InMdlT_ASYNC48(int controlPortIdx)
{
}

void InMdlT_ASYNC49(int controlPortIdx)
{
}

void InMdlT_ASYNC50(int controlPortIdx)
{
}

void InMdlT_ASYNC51(int controlPortIdx)
{
}

void InMdlT_ASYNC52(int controlPortIdx)
{
}

void InMdlT_ASYNC53(int controlPortIdx)
{
}

void InMdlT_ASYNC54(int controlPortIdx)
{
}

/* Start for exported function: RE_InMdlT_008_TEV */
void RE_InMdlT_008_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F01_Throttle_flowrate'
   *
   * Block requirements for '<S1>/INM1_F01_Throttle_flowrate':
   *  1. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_112.01 ;
   *  2. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_113.01 ;
   *  3. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_333.03 ;
   *  4. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : 01552_10_02417-InMdlT.I059(0) ;
   *  5. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : 01552_10_02417-InMdlT-I235(0) ;
   *  6. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_212.01 ;
   *  7. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_213.01 ;
   *  8. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_216.01 ;
   *  9. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_217.02 ;
   *  10. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_218.02 ;
   *  11. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_219.02 ;
   *  12. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  13. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_215.01 ;
   *  14. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  15. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  16. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  17. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  18. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  19. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  20. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_210.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_008_TEV */
void RE_InMdlT_008_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtThrLr;
  UInt16 localDataTypeConversion2;
  UInt16 localLookUpTable;
  UInt16 localLookUpTable_c;
  UInt16 localLookUpTable_e;
  UInt8 localTmpSignalConversionAtEng_s;
  Boolean localRelationalOperator;
  Float32 localDivide_c5;
  UInt16 localrtmin;
  Float32 localDivide_js;
  Float32 localmax;
  SInt8 localTmpSignalConversionAtAFA_f;
  SInt8 localTmpSignalConversionAtAFA_k;
  SInt8 localTmpSignalConversionAtAF_a0;
  SInt16 localTmpSignalConversionAtAFA_a;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F01_Throttle_flowrate'
   *
   * Block requirements for '<S1>/INM1_F01_Throttle_flowrate':
   *  1. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_112.01 ;
   *  2. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_113.01 ;
   *  3. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_333.03 ;
   *  4. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : 01552_10_02417-InMdlT.I059(0) ;
   *  5. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : 01552_10_02417-InMdlT-I235(0) ;
   *  6. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_212.01 ;
   *  7. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_213.01 ;
   *  8. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_216.01 ;
   *  9. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_217.02 ;
   *  10. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_218.02 ;
   *  11. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_219.02 ;
   *  12. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  13. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_215.01 ;
   *  14. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  15. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  16. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  17. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  18. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  19. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  20. SubSystem "INM1_F01_Throttle_flowrate" !Trace_To : VEMS_R_11_01067_210.01 ;
   */

  /* SignalConversion: '<S41>/TmpSignal ConversionAtAFA_arEffThrOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffThrOfs'
   */
  Rte_Read_R_AFA_arEffThrOfs_AFA_arEffThrOfs(&localTmpSignalConversionAtAFA_a);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtAFA_facArEffThrOfs1Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs1'
   */
  Rte_Read_R_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1
    (&localTmpSignalConversionAtAFA_f);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtAFA_facArEffThrOfs2Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs2'
   */
  Rte_Read_R_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2
    (&localTmpSignalConversionAtAFA_k);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtAFA_facArEffThrOfs3Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs3'
   */
  Rte_Read_R_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3
    (&localTmpSignalConversionAtAF_a0);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&localTmpSignalConversionAtThrLr);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&InMdlT_B.TmpSignalConversionAtUsThrM_tSq);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor
    (&InMdlT_B.TmpSignalConversionAtUsThrM_p_c);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_pDs_b5);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* RelationalOperator: '<S41>/Relational Operator' incorporates:
   *  Constant: '<S41>/Ext_stRun_SC'
   */
  localRelationalOperator = (localTmpSignalConversionAtEng_s == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S41>/Calc_thr_fr' incorporates:
   *  EnablePort: '<S93>/NS_bRun'
   *
   * Block requirements for '<S41>/Calc_thr_fr':
   *  1. SubSystem "Calc_thr_fr" !Trace_To : VEMS_R_11_01067_114.01 ;
   */
  if (localRelationalOperator) {
    /* Outputs for atomic SubSystem: '<S93>/F01_Calc_eff_area' *
     * Block requirements for '<S93>/F01_Calc_eff_area':
     *  1. SubSystem "F01_Calc_eff_area" !Trace_To : VEMS_R_11_01067_115.01 ;
     */

    /* Lookup: '<S102>/Look-Up Table'
     * About '<S102>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U16  2^-24
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_c), (&(Air_arEffThr_T[0])),
                   localTmpSignalConversionAtThrLr, (&(Air_rOpThr_T[0])), 32U);

    /* DataTypeDuplicate Block: '<S102>/Data Type Duplicate1'
     *
     * Regarding '<S102>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion Block: '<S99>/Signal Conversion2'
     *
     * Regarding '<S99>/Signal Conversion2':
     *   Eliminate redundant signal conversion block
     */

    /* DataStoreWrite: '<S99>/Data Store Write2' */
    InM_arEffThr_MP = localLookUpTable_c;

    /* Outputs for atomic SubSystem: '<S99>/F01_Calc_eff_area_offset' *
     * Block requirements for '<S99>/F01_Calc_eff_area_offset':
     *  1. SubSystem "F01_Calc_eff_area_offset" !Trace_To : VEMS_R_11_01067_116.01 ;
     */

    /* MinMax: '<S103>/MinMax' incorporates:
     *  Constant: '<S103>/AFA_rOpThrMax_C'
     */
    localrtmin = localTmpSignalConversionAtThrLr;
    if (AFA_rOpThrMax_C < localTmpSignalConversionAtThrLr) {
      localrtmin = AFA_rOpThrMax_C;
    }

    /* DataStoreWrite: '<S103>/Data Store Write' */
    AFA_rOpThrMax_MP = localrtmin;

    /* Sum: '<S103>/Sum' incorporates:
     *  Constant: '<S103>/AFA_rOpThrRef2_C'
     */
    localDivide_js = (((Float32)localrtmin) * 0.0009765625F) - (((Float32)
      AFA_rOpThrRef2_C) * 0.0009765625F);

    /* MinMax: '<S103>/MinMax1' incorporates:
     *  Constant: '<S103>/Constant8'
     */
    localmax = rt_MAXf(0.0F, localDivide_js);

    /* DataStoreWrite: '<S103>/Data Store Write1' incorporates:
     *  Constant: '<S105>/offset'
     *  Constant: '<S105>/offset1'
     *  Constant: '<S105>/one_on_slope'
     *  DataTypeConversion: '<S105>/OutDTConv'
     *  Product: '<S105>/Product4'
     *  Sum: '<S105>/Add1'
     *  Sum: '<S105>/Add2'
     */
    AFA_rOpThrRef2_MP = (UInt16)((1024.0F * localmax) + 0.5F);

    /* Sum: '<S103>/Sum1' incorporates:
     *  Constant: '<S103>/AFA_rOpThrRef3_C'
     */
    localDivide_js = (((Float32)localrtmin) * 0.0009765625F) - (((Float32)
      AFA_rOpThrRef3_C) * 0.0009765625F);

    /* MinMax: '<S103>/MinMax2' incorporates:
     *  Constant: '<S103>/Constant9'
     */
    localDivide_js = rt_MAXf(localDivide_js, 0.0F);

    /* DataStoreWrite: '<S103>/Data Store Write2' incorporates:
     *  Constant: '<S104>/offset'
     *  Constant: '<S104>/offset1'
     *  Constant: '<S104>/one_on_slope'
     *  DataTypeConversion: '<S104>/OutDTConv'
     *  Product: '<S104>/Product4'
     *  Sum: '<S104>/Add1'
     *  Sum: '<S104>/Add2'
     */
    AFA_rOpThrRef3_MP = (UInt16)((1024.0F * localDivide_js) + 0.5F);

    /* Sum: '<S103>/Sum2' incorporates:
     *  Product: '<S106>/Divide'
     *  Product: '<S107>/Divide'
     *  Product: '<S108>/Divide'
     */
    InM_arEffThrOfs = (((((Float32)localTmpSignalConversionAtAFA_f) *
                         3.814697266E-006F) * (((Float32)localrtmin) *
      0.0009765625F)) + ((((Float32)localTmpSignalConversionAtAFA_k) *
                          3.814697266E-006F) * localmax)) + ((((Float32)
      localTmpSignalConversionAtAF_a0) * 3.814697266E-006F) * localDivide_js);

    /* end of Outputs for SubSystem: '<S99>/F01_Calc_eff_area_offset' */

    /* Sum: '<S99>/Sum3' */
    localmax = ((((Float32)localLookUpTable_c) * 5.960464478E-008F) -
                (((Float32)localTmpSignalConversionAtAFA_a) * 5.960464478E-008F))
      - InM_arEffThrOfs;

    /* end of Outputs for SubSystem: '<S93>/F01_Calc_eff_area' */

    /* Outputs for atomic SubSystem: '<S93>/F02_Calc_thr_area_mass_fr' *
     * Block requirements for '<S93>/F02_Calc_thr_area_mass_fr':
     *  1. SubSystem "F02_Calc_thr_area_mass_fr" !Trace_To : VEMS_R_11_01067_117.01 ;
     */

    /* DataTypeConversion: '<S100>/Data Type Conversion9' */
    localDivide_c5 = ((Float32)InMdlT_B.TmpSignalConversionAtUsThrM_p_c) * 8.0F;

    /* Product: '<S113>/Divide' incorporates:
     *  DataTypeConversion: '<S100>/Data Type Conversion8'
     */
    localDivide_js = (((Float32)InMdlT_B.TmpSignalConversionAtInM_pDs_b5) *
                      0.0078125F) / localDivide_c5;

    /* Outputs for atomic SubSystem: '<S113>/If Action Subsystem3' */

    /* Switch: '<S119>/Switch1' incorporates:
     *  Constant: '<S119>/Constant1'
     *  Constant: '<S119>/Constant2'
     *  Constant: '<S119>/Constant3'
     *  Logic: '<S119>/Logical Operator1'
     *  RelationalOperator: '<S119>/Relational Operator'
     *  RelationalOperator: '<S119>/Relational Operator1'
     *  RelationalOperator: '<S119>/Relational Operator3'
     */
    if (((localDivide_js != localDivide_js) || (localDivide_js >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_js)) {
      localDivide_js = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S113>/If Action Subsystem3' */

    /* DataTypeConversion: '<S113>/Data Type Conversion2' */
    localtmp = ACTEMS_LdexpF((Float32d)localDivide_js, 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion2 = (UInt16)localtmp;
      } else {
        localDataTypeConversion2 = 0U;
      }
    } else {
      localDataTypeConversion2 = MAX_uint16_T;
    }

    /* Lookup: '<S109>/Look-Up Table'
     * About '<S109>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-20
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(InM_facCfeThr_T[0])),
                   localDataTypeConversion2, (&(Air_rAirPres_A[0])), 21U);

    /* DataTypeDuplicate Block: '<S109>/Data Type Duplicate1'
     *
     * Regarding '<S109>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion Block: '<S100>/Signal Conversion2'
     *
     * Regarding '<S100>/Signal Conversion2':
     *   Eliminate redundant signal conversion block
     */

    /* DataStoreWrite: '<S100>/Data Store Write2' */
    InM_facCfeThr_MP = localLookUpTable;

    /* Lookup: '<S110>/Look-Up Table'
     * About '<S110>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-11  Bias -3.1999511718750000E+001
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_e), (&(InM_facCfeGradThr_T[0])),
                   localDataTypeConversion2, (&(Air_rAirPres_A[0])), 21U);

    /* DataTypeDuplicate Block: '<S110>/Data Type Duplicate1'
     *
     * Regarding '<S110>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion: '<S100>/Signal Conversion1' */
    InMdlT_B.Merge3_a = localLookUpTable_e;

    /* SignalConversion: '<S100>/Signal Conversion3' */
    InMdlT_B.Merge2_h = localDataTypeConversion2;

    /* Product: '<S112>/Divide' incorporates:
     *  DataTypeConversion: '<S100>/Data Type Conversion7'
     */
    localDivide_js = localmax / (((Float32)
      InMdlT_B.TmpSignalConversionAtUsThrM_tSq) * 0.125F);

    /* Outputs for atomic SubSystem: '<S112>/If Action Subsystem3' */

    /* Switch: '<S117>/Switch1' incorporates:
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S117>/Constant2'
     *  Constant: '<S117>/Constant3'
     *  Logic: '<S117>/Logical Operator1'
     *  RelationalOperator: '<S117>/Relational Operator'
     *  RelationalOperator: '<S117>/Relational Operator1'
     *  RelationalOperator: '<S117>/Relational Operator3'
     */
    if (((localDivide_js != localDivide_js) || (localDivide_js >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_js)) {
      localDivide_js = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S112>/If Action Subsystem3' */

    /* Product: '<S115>/Divide' */
    localDivide_c5 *= localDivide_js;

    /* DataTypeConversion: '<S111>/OutDTConv' incorporates:
     *  Constant: '<S111>/offset'
     *  Constant: '<S111>/offset1'
     *  Constant: '<S111>/one_on_slope'
     *  Product: '<S111>/Product4'
     *  Product: '<S114>/Divide'
     *  Sum: '<S111>/Add1'
     *  Sum: '<S111>/Add2'
     */
    localDivide_js = (((((Float32)localLookUpTable) * 9.536743164E-007F) *
                       localDivide_c5) * 65536.0F) + 0.5F;
    if (localDivide_js < 65536.0F) {
      if (localDivide_js >= 0.0F) {
        InMdlT_B.Merge1 = (UInt16)localDivide_js;
      } else {
        InMdlT_B.Merge1 = 0U;
      }
    } else {
      InMdlT_B.Merge1 = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S93>/F02_Calc_thr_area_mass_fr' */

    /* DataTypeConversion: '<S101>/OutDTConv' incorporates:
     *  Constant: '<S101>/offset'
     *  Constant: '<S101>/offset1'
     *  Constant: '<S101>/one_on_slope'
     *  Product: '<S101>/Product4'
     *  Sum: '<S101>/Add1'
     *  Sum: '<S101>/Add2'
     */
    localDivide_js = (1.6777216E+007F * localmax) + 0.5F;
    if (localDivide_js < 65536.0F) {
      if (localDivide_js >= 0.0F) {
        InMdlT_B.Merge4_o = (UInt16)localDivide_js;
      } else {
        InMdlT_B.Merge4_o = 0U;
      }
    } else {
      InMdlT_B.Merge4_o = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S41>/Calc_thr_fr' */

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_mfAirThrEstim1Outport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_mfAi_c);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_rAirPres1Outport2' incorporates:
   *  Inport: '<Root>/InM_rAirPres_INPUT'
   */
  Rte_Read_R_InM_rAirPres_InM_rAirPres(&InMdlT_B.TmpSignalConversionAtInM_rAirPr);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_facCfeGradThr1Outport2' incorporates:
   *  Inport: '<Root>/InM_facCfeGradThr_INPUT'
   */
  Rte_Read_R_InM_facCfeGradThr_InM_facCfeGradThr
    (&InMdlT_B.TmpSignalConversionAtInM_facCfe);

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_arEffAdpThr1Outport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpThr_INPUT'
   */
  Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr
    (&InMdlT_B.TmpSignalConversionAtInM_arEffA);

  /* Outputs for enable SubSystem: '<S41>/NOT' incorporates:
   *  EnablePort: '<S94>/NS_bRun'
   *  Logic: '<S41>/NAN1'
   */
  if (!localRelationalOperator) {
    /* SignalConversion: '<S94>/Signal Conversion4' */
    InMdlT_B.Merge1 = InMdlT_B.TmpSignalConversionAtInM_mfAi_c;

    /* SignalConversion: '<S94>/Signal Conversion1' */
    InMdlT_B.Merge2_h = InMdlT_B.TmpSignalConversionAtInM_rAirPr;

    /* SignalConversion: '<S94>/Signal Conversion2' */
    InMdlT_B.Merge3_a = InMdlT_B.TmpSignalConversionAtInM_facCfe;

    /* SignalConversion: '<S94>/Signal Conversion3' */
    InMdlT_B.Merge4_o = InMdlT_B.TmpSignalConversionAtInM_arEffA;
  }

  /* end of Outputs for SubSystem: '<S41>/NOT' */

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Byp_Fonction_SC'
   *  Constant: '<S95>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localrtmin = InM_arEffAdpThr_B;
  } else {
    localrtmin = InMdlT_B.Merge4_o;
  }

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_arEffAdpThrInport2' */
  Rte_Write_P_InM_arEffAdpThr_InM_arEffAdpThr(localrtmin);

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S96>/Byp_Fonction_SC'
   *  Constant: '<S96>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localrtmin = InM_facCfeGradThr_B;
  } else {
    localrtmin = InMdlT_B.Merge3_a;
  }

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_facCfeGradThrInport2' */
  Rte_Write_P_InM_facCfeGradThr_InM_facCfeGradThr(localrtmin);

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Byp_Fonction_SC'
   *  Constant: '<S97>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localrtmin = InM_mfAirThrEstim_B;
  } else {
    localrtmin = InMdlT_B.Merge1;
  }

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_mfAirThrEstimInport2' */
  Rte_Write_P_InM_mfAirThrEstim_InM_mfAirThrEstim(localrtmin);

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Byp_Fonction_SC'
   *  Constant: '<S98>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localrtmin = InM_rAirPres_B;
  } else {
    localrtmin = InMdlT_B.Merge2_h;
  }

  /* SignalConversion: '<S41>/TmpSignal ConversionAtInM_rAirPresInport2' */
  Rte_Write_P_InM_rAirPres_InM_rAirPres(localrtmin);
}

/* Start for exported function: RE_InMdlT_004_TEV */
void RE_InMdlT_004_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S17>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F02_2fc_demux1'
   *
   * Block requirements for '<S1>/INM1_F02_2fc_demux1':
   *  1. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_331.03 ;
   *  2. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  3. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  4. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_172.01 ;
   *  5. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  7. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_289.02 ;
   *  8. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  9. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_182.02 ;
   *  10. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_183.01 ;
   *  11. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_184.02 ;
   *  12. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_193.01 ;
   *  13. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_188.01 ;
   *  14. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_187.01 ;
   *  15. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  16. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_191.01 ;
   *  17. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  18. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_174.01 ;
   *  19. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_176.01 ;
   *  20. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_178.01 ;
   *  21. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_180.01 ;
   *  22. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_177.01 ;
   *  23. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_179.01 ;
   *  24. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_181.01 ;
   *  25. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_175.03 ;
   *  26. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_185.02 ;
   *  27. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_186.02 ;
   *  28. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_385.01 ;
   *  29. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_190.01 ;
   *  30. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_368.01 ;
   *  31. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  32. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_289.02 ;
   *  33. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_001.02 ;
   *  34. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_002.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_004_TEV */
void RE_InMdlT_004_TEV(void)
{
  /* local block i/o variables */
  Float32 localInvokeAUTOSARServerOperati;
  Float32 localInvokeAUTOSARServerOpera_e;
  Float32 localInvokeAUTOSARServerOpera_n;
  Float32 localInvokeAUTOSARServerOper_ec;
  Float32 localInvokeAUTOSARServerOpera_b;
  Float32 localInvokeAUTOSARServerOpera_f;
  Float32 localDTConv_UFix_To_Single_13;
  Float32 localDTConv_UFix_To_Single_14;
  Float32 localDTConv_UFix_To_Single_15;
  Float32 localDTConv_UFix_To_Single_1;
  Float32 localDTConv_UFix_To_Single_16;
  Float32 localDTConv_UFix_To_Single_17;
  Float32 localDTConv_UFix_To_Single_2;
  Float32 localDTConv_UFix_To_Single_4;
  Float32 localDTConv_UFix_To_Single_7;
  Float32 localDTConv_UFix_To_Single_6;
  Float32 localSignalConversion8;
  Float32 localTmpSignalConversionAtSigna;
  Float32 localTmpSignalConversionAtSig_h;
  Float32 localDTConv_UFix_To_Single_20;
  Float32 localDTConv_UFix_To_Single_21;
  Float32 localInvokeAUTOSARServerOpera_d;
  Float32 localInvokeAUTOSARServerOpera_h;
  Float32 localInvokeAUTOSARServerOper_du;
  Float32 localInvokeAUTOSARServerOpera_c;
  Float32 localInvokeAUTOSARServerOper_es;
  Float32 localInvokeAUTOSARServerOper_n5;
  Float32 localInvokeAUTOSARServerOper_ct;
  Float32 localInvokeAUTOSARServerOper_ej;
  Float32 localInvokeAUTOSARServerOper_ei;
  Float32 localInvokeAUTOSARServerOper_fe;
  Float32 localInvokeAUTOSARServerOpe_ecc;
  Float32 local_;
  Float32 localInvokeAUTOSARServerOper_ne;
  Float32 localInvokeAUTOSARServerOper_cu;
  Float32 localInvokeAUTOSARServerOper_nn;
  Float32 localInvokeAUTOSARServerOper_nq;
  Float32 localInvokeAUTOSARServerOper_bh;
  Float32 localInvokeAUTOSARServerOper_dc;
  SInt16 localTmpSignalConversionAtExt_t;
  UInt16 localSignalConversion6;
  UInt16 localTmpSignalConversionAtSig_l;
  UInt16 localDTConv_UFix_To_Single_3;
  UInt16 localTmpSignalConversionAtSig_e;
  UInt16 localOutDTConv_n;
  UInt16 localDTConv_UFix_To_Single_5;
  UInt16 localDTConv_UFix_To_Single_8;
  Float32 localAirEfc_facChrExpFilEstim_i;
  Float32 localAirEfc_facChrExpScvFilEsti;
  Float32 localInM_facSlopEfcEstim_irv;
  UInt16 localTmpSignalConversionAtInThM;
  SInt16 localTmpSignalConversionAtEngM_;
  UInt16 localTmpSignalConversionAtEng_a;
  SInt16 localTmpSignalConversionAtEng_e;
  UInt16 localTmpSignalConversionAtInT_g;
  UInt16 localTmpSignalConversionAtInjSy[6];
  UInt16 localTmpSignalConversionAtExM_h[6];
  UInt16 localTmpSignalConversionAtExM_p[6];
  UInt16 localTmpSignalConversionAtInj_f[6];
  UInt16 localTmpSignalConversionAtInj_m[6];
  UInt16 localTmpSignalConversionAtIn_mf[6];
  UInt16 localTmpSignalConversionAtInj_c[6];
  UInt16 localTmpSignalConversionAtInj_n[6];
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtFuSys;
  SInt16 localTmpSignalConversionAtEng_g;
  UInt16 localTmpSignalConversionAtEn_az;
  Float32 localtmp;
  UInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S17>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F02_2fc_demux1'
   *
   * Block requirements for '<S1>/INM1_F02_2fc_demux1':
   *  1. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_331.03 ;
   *  2. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  3. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  4. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_172.01 ;
   *  5. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  7. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_289.02 ;
   *  8. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  9. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_182.02 ;
   *  10. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_183.01 ;
   *  11. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_184.02 ;
   *  12. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_193.01 ;
   *  13. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_188.01 ;
   *  14. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_187.01 ;
   *  15. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  16. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_191.01 ;
   *  17. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  18. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_174.01 ;
   *  19. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_176.01 ;
   *  20. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_178.01 ;
   *  21. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_180.01 ;
   *  22. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_177.01 ;
   *  23. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_179.01 ;
   *  24. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_181.01 ;
   *  25. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_175.03 ;
   *  26. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_185.02 ;
   *  27. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_186.02 ;
   *  28. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_385.01 ;
   *  29. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_190.01 ;
   *  30. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_368.01 ;
   *  31. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  32. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_289.02 ;
   *  33. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_001.02 ;
   *  34. SubSystem "INM1_F02_2fc_demux1" !Trace_To : VEMS_R_11_01067_002.02 ;
   */

  /* SignalConversion: '<S43>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&InMdlT_B.TmpSignalConversionAtExt_nEn_ef);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (&localTmpSignalConversionAtEng_a);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&localTmpSignalConversionAtEng_e);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInT_g);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tExMnfEstimCyl'
   */
  Rte_Read_R_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl
    (&localTmpSignalConversionAtExM_h);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pExMnfEstimOvlpCyl'
   */
  Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&localTmpSignalConversionAtExM_p);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_pDsT_b);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&InMdlT_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_concAirEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_k =
    Rte_IrvRead_RE_InMdlT_004_TEV_InM_concAirEstim_irv();

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&InMdlT_B.TmpSignalConversionAtEng_noIn_j);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_agBegInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_agEndInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl
    (&localTmpSignalConversionAtInj_f);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_mFuInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl
    (&localTmpSignalConversionAtInj_m);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_agBegInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl
    (&localTmpSignalConversionAtInj_c);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_agEndInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl
    (&localTmpSignalConversionAtInj_n);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInjSys_prm_mFuInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl
    (&localTmpSignalConversionAtIn_mf);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtFuSysM_tFuOutport2' incorporates:
   *  Inport: '<Root>/FuSysM_tFu'
   */
  Rte_Read_R_FuSysM_tFu_FuSysM_tFu(&localTmpSignalConversionAtFuSys);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEngM_facCorOfsEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorOfsEfc'
   */
  Rte_Read_R_EngM_facCorOfsEfc_EngM_facCorOfsEfc
    (&localTmpSignalConversionAtEng_g);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtEngM_facCorSlopEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorSlopEfc'
   */
  Rte_Read_R_EngM_facCorSlopEfc_EngM_facCorSlopEfc
    (&localTmpSignalConversionAtEn_az);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_prm_pDsThrPred_facVlvOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredOvlpCyl_INPUT'
   */
  Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&InMdlT_B.TmpSignalConversionAtInM_prm_pD);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor(&localTmpSignalConversionAtInThM);

  /* Outputs for atomic SubSystem: '<S43>/F01_Input_Interface' *
   * Block requirements for '<S43>/F01_Input_Interface':
   *  1. SubSystem "F01_Input_Interface" !Trace_To : VEMS_R_11_01067_005.02 ;
   */

  /* SignalConversion: '<S134>/Signal Conversion6' */
  localSignalConversion6 = InMdlT_B.TmpSignalConversionAtExt_nEn_ef;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_13' */
  localDTConv_UFix_To_Single_13 = ((Float32)localTmpSignalConversionAtEngM_) *
    0.09375F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_14' */
  localDTConv_UFix_To_Single_14 = (((Float32)localTmpSignalConversionAtEng_a) *
    0.09375F) + 84.0F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_15' */
  localDTConv_UFix_To_Single_15 = ((Float32)localTmpSignalConversionAtEng_e) *
    0.09375F;

  /* SignalConversion: '<S134>/TmpSignal ConversionAtSignal Conversion9Inport1' */
  localTmpSignalConversionAtSig_e = localTmpSignalConversionAtInT_g;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_1' incorporates:
   *  Selector: '<S134>/Selector4'
   */
  localDTConv_UFix_To_Single_1 = ((Float32)
    localTmpSignalConversionAtInjSy[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1])
    * 0.0625F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_16' incorporates:
   *  Selector: '<S134>/Selector1'
   */
  localDTConv_UFix_To_Single_16 = (((Float32)
    localTmpSignalConversionAtExM_h[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1])
    * 0.03125F) + 223.0F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_17' incorporates:
   *  Selector: '<S134>/Selector2'
   */
  localDTConv_UFix_To_Single_17 = ((Float32)
    localTmpSignalConversionAtExM_p[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1])
    * 8.0F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_2' incorporates:
   *  Selector: '<S134>/Selector5'
   */
  localDTConv_UFix_To_Single_2 = ((Float32)
    localTmpSignalConversionAtInj_f[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1])
    * 0.0625F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_4' incorporates:
   *  Selector: '<S134>/Selector9'
   */
  localDTConv_UFix_To_Single_4 = ((Float32)
    InMdlT_B.TmpSignalConversionAtInM_prm_pD[InMdlT_B.TmpSignalConversionAtEng_noIn_j
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_7' incorporates:
   *  Selector: '<S134>/Selector3'
   */
  localDTConv_UFix_To_Single_7 = ((Float32)
    localTmpSignalConversionAtInj_m[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1])
    * 7.450580597E-009F;

  /* Selector: '<S134>/Selector6' */
  InMdlT_B.Selector6 =
    localTmpSignalConversionAtIn_mf[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1];

  /* Selector: '<S134>/Selector7' */
  InMdlT_B.Selector7 =
    localTmpSignalConversionAtInj_c[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1];

  /* Selector: '<S134>/Selector8' */
  InMdlT_B.Selector8 =
    localTmpSignalConversionAtInj_n[InMdlT_B.TmpSignalConversionAtEng_noIn_j - 1];

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_3' incorporates:
   *  SignalConversion: '<S134>/Signal Conversion16'
   */
  localtmp_0 = (InMdlT_B.TmpSignalConversionAtInM_pDsT_b >> 10);
  if (localtmp_0 > 65535U) {
    localDTConv_UFix_To_Single_3 = MAX_uint16_T;
  } else {
    localDTConv_UFix_To_Single_3 = (UInt16)localtmp_0;
  }

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_6' incorporates:
   *  SignalConversion: '<S134>/Signal Conversion15'
   */
  localDTConv_UFix_To_Single_6 = ((Float32)
    InMdlT_B.TmpSignalConversionAtUsThrM_pAi) * 8.0F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_8' */
  localtmp_0 = (UInt32)((SInt32)(((UInt32)(localTmpSignalConversionAtFARSp *
    17857)) >> 14));
  if (localtmp_0 > 65535U) {
    localDTConv_UFix_To_Single_8 = MAX_uint16_T;
  } else {
    localDTConv_UFix_To_Single_8 = (UInt16)localtmp_0;
  }

  /* SignalConversion: '<S134>/Signal Conversion8' */
  localSignalConversion8 = InMdlT_B.TmpSignalConversionAtInM_conc_k;

  /* SignalConversion: '<S134>/TmpSignal ConversionAtSignal Conversion7Inport1' incorporates:
   *  SignalConversion: '<S43>/TmpSignal ConversionAtAirEfc_facChrExpFilPrevEstimOutport2'
   */
  localTmpSignalConversionAtSigna =
    Rte_IrvRead_RE_InMdlT_004_TEV_AirEfc_facChrExpFilEstim_irv();

  /* SignalConversion: '<S134>/TmpSignal ConversionAtSignal Conversion4Inport1' incorporates:
   *  SignalConversion: '<S43>/TmpSignal ConversionAtAirEfc_facChrExpScvFilPrevEstimOutport2'
   */
  localTmpSignalConversionAtSig_h =
    Rte_IrvRead_RE_InMdlT_004_TEV_AirEfc_facChrExpScvFilEstim_irv();

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_5' */
  localtmp_0 = (UInt32)(localTmpSignalConversionAtFuSys + 10);
  if (localtmp_0 > 65535U) {
    localDTConv_UFix_To_Single_5 = MAX_uint16_T;
  } else {
    localDTConv_UFix_To_Single_5 = (UInt16)localtmp_0;
  }

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_20' */
  localDTConv_UFix_To_Single_20 = ((Float32)localTmpSignalConversionAtEng_g) *
    3.051757813E-005F;

  /* DataTypeConversion: '<S134>/DTConv_UFix_To_Single_21' */
  localDTConv_UFix_To_Single_21 = ((Float32)localTmpSignalConversionAtEn_az) *
    3.051757813E-005F;

  /* SignalConversion: '<S134>/TmpSignal ConversionAtSignal Conversion5Inport1' */
  localTmpSignalConversionAtSig_l = localTmpSignalConversionAtInThM;

  /* end of Outputs for SubSystem: '<S43>/F01_Input_Interface' */

  /* SignalConversion: '<S43>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* S-Function (sfun_autosar_clientop): '<S43>/Invoke AUTOSAR Server Operation' incorporates:
   *  Constant: '<S134>/Cste_4'
   *
   * Block requirements for '<S43>/Invoke AUTOSAR Server Operation':
   *  1. S-Function "Invoke AUTOSAR Server Operation" !Trace_To : VEMS_R_11_01067_006.02 ;
   */
  Rte_Call_R_LibAirEfc_OP_LibAirEfc(localSignalConversion6,
    localDTConv_UFix_To_Single_13, localDTConv_UFix_To_Single_14,
    localDTConv_UFix_To_Single_15, localTmpSignalConversionAtSig_e,
    localDTConv_UFix_To_Single_16, localDTConv_UFix_To_Single_3,
    localDTConv_UFix_To_Single_17, localDTConv_UFix_To_Single_6,
    localDTConv_UFix_To_Single_8, localDTConv_UFix_To_Single_4,
    localTmpSignalConversionAtExt_t, localTmpSignalConversionAtSigna,
    localTmpSignalConversionAtSig_h, ((UInt8)4U), localDTConv_UFix_To_Single_1,
    localDTConv_UFix_To_Single_2, localDTConv_UFix_To_Single_7,
    localDTConv_UFix_To_Single_5, localDTConv_UFix_To_Single_20,
    localDTConv_UFix_To_Single_21, localTmpSignalConversionAtSig_l,
    &localInvokeAUTOSARServerOper_ei, &localInvokeAUTOSARServerOper_fe,
    &localInvokeAUTOSARServerOperati, &localInvokeAUTOSARServerOpe_ecc, &local_,
    &localInvokeAUTOSARServerOper_ne, &localInvokeAUTOSARServerOper_cu,
    &localInvokeAUTOSARServerOper_nn, &localInvokeAUTOSARServerOper_nq,
    &localInvokeAUTOSARServerOpera_e, &localInvokeAUTOSARServerOpera_n,
    &localInvokeAUTOSARServerOpera_d, &localInvokeAUTOSARServerOper_bh,
    &localInvokeAUTOSARServerOper_dc, &localInvokeAUTOSARServerOpera_h,
    &localInvokeAUTOSARServerOper_du, &localInvokeAUTOSARServerOpera_c,
    &localInvokeAUTOSARServerOper_es, &localInvokeAUTOSARServerOper_n5,
    &localInvokeAUTOSARServerOper_ct, &localInvokeAUTOSARServerOper_ej);

  /* SignalConversion Block: '<S143>/copy'
   *
   * Regarding '<S143>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S144>/copy'
   *
   * Regarding '<S144>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S145>/copy'
   *
   * Regarding '<S145>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* S-Function (sfun_autosar_clientop): '<S43>/Invoke AUTOSAR Server Operation1' incorporates:
   *  Constant: '<S134>/Cste_4'
   */
  Rte_Call_R_LibEngCylPrm_OP_LibEngCylPrm(localTmpSignalConversionAtSig_e,
    localInvokeAUTOSARServerOper_cu, localDTConv_UFix_To_Single_3,
    localInvokeAUTOSARServerOpe_ecc, localInvokeAUTOSARServerOperati,
    localInvokeAUTOSARServerOper_fe, localInvokeAUTOSARServerOper_ei, local_,
    localInvokeAUTOSARServerOper_nq, localSignalConversion8,
    localInvokeAUTOSARServerOper_ne, localInvokeAUTOSARServerOper_nn,
    localSignalConversion6, ((UInt8)4U), localDTConv_UFix_To_Single_5,
    localDTConv_UFix_To_Single_14, localInvokeAUTOSARServerOper_bh,
    localInvokeAUTOSARServerOper_dc, &localInvokeAUTOSARServerOper_cu,
    &localInvokeAUTOSARServerOpe_ecc, &localInvokeAUTOSARServerOper_fe,
    &localInvokeAUTOSARServerOper_ec, &localInvokeAUTOSARServerOper_ei, &local_,
    &localInvokeAUTOSARServerOpera_b, &localInvokeAUTOSARServerOper_nq,
    &localInvokeAUTOSARServerOpera_f, &localInvokeAUTOSARServerOper_ne,
    &localInvokeAUTOSARServerOper_nn, &localInvokeAUTOSARServerOper_bh,
    &localInvokeAUTOSARServerOper_dc);

  /* Outputs for atomic SubSystem: '<S43>/F02_Output_Interface_calculation' *
   * Block requirements for '<S43>/F02_Output_Interface_calculation':
   *  1. SubSystem "F02_Output_Interface_calculation" !Trace_To : VEMS_R_11_01067_007.01 ;
   *  2. SubSystem "F02_Output_Interface_calculation" !Trace_To : VEMS_R_11_01067_008.01 ;
   *  3. SubSystem "F02_Output_Interface_calculation" !Trace_To : VEMS_R_11_01067_009.01 ;
   *  4. SubSystem "F02_Output_Interface_calculation" !Trace_To : VEMS_R_11_01067_010.01 ;
   */

  /* DataTypeConversion: '<S142>/OutDTConv' incorporates:
   *  Constant: '<S142>/offset'
   *  Constant: '<S142>/offset1'
   *  Constant: '<S142>/one_on_slope'
   *  Product: '<S142>/Product4'
   *  Sum: '<S142>/Add1'
   *  Sum: '<S142>/Add2'
   */
  localInM_facSlopEfcEstim_irv = (65536.0F * localInvokeAUTOSARServerOpera_b) +
    0.5F;
  if (localInM_facSlopEfcEstim_irv < 65536.0F) {
    if (localInM_facSlopEfcEstim_irv >= 0.0F) {
      localTmpSignalConversionAtEng_a = (UInt16)localInM_facSlopEfcEstim_irv;
    } else {
      localTmpSignalConversionAtEng_a = 0U;
    }
  } else {
    localTmpSignalConversionAtEng_a = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S140>/OutDTConv' incorporates:
   *  Constant: '<S140>/offset'
   *  Constant: '<S140>/offset1'
   *  Constant: '<S140>/one_on_slope'
   *  Product: '<S140>/Product4'
   *  Sum: '<S140>/Add1'
   *  Sum: '<S140>/Add2'
   */
  localInM_facSlopEfcEstim_irv = (16384.0F * localInvokeAUTOSARServerOper_ec) +
    0.5F;
  if (localInM_facSlopEfcEstim_irv < 65536.0F) {
    if (localInM_facSlopEfcEstim_irv >= 0.0F) {
      localOutDTConv_n = (UInt16)localInM_facSlopEfcEstim_irv;
    } else {
      localOutDTConv_n = 0U;
    }
  } else {
    localOutDTConv_n = MAX_uint16_T;
  }

  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S147>/Byp_Fonction_SC'
   *  Constant: '<S147>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInT_g = InM_rTotLdExEstim_B;
  } else {
    localTmpSignalConversionAtInT_g = localOutDTConv_n;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S143>/autosar_testpoint1' */

  /* S-Function Block: <S143>/autosar_testpoint1 */
  InM_facSlopEfcEstim_IRV_MP = localInvokeAUTOSARServerOperati;

  /* SignalConversion: '<S135>/Signal Conversion1' */
  localInM_facSlopEfcEstim_irv = localInvokeAUTOSARServerOperati;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S144>/autosar_testpoint1' */

  /* S-Function Block: <S144>/autosar_testpoint1 */
  AirEfc_facChrExpFilEstim_IRV_MP = localInvokeAUTOSARServerOpera_e;

  /* SignalConversion: '<S135>/Signal Conversion3' */
  localAirEfc_facChrExpFilEstim_i = localInvokeAUTOSARServerOpera_e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S145>/autosar_testpoint1' */

  /* S-Function Block: <S145>/autosar_testpoint1 */
  AirEfc_facChrExpScvFilEstim = localInvokeAUTOSARServerOpera_n;

  /* SignalConversion: '<S135>/Signal Conversion4' */
  localAirEfc_facChrExpScvFilEsti = localInvokeAUTOSARServerOpera_n;

  /* DataTypeConversion: '<S141>/OutDTConv' incorporates:
   *  Constant: '<S141>/offset'
   *  Constant: '<S141>/offset1'
   *  Constant: '<S141>/one_on_slope'
   *  Product: '<S141>/Product4'
   *  Sum: '<S141>/Add1'
   *  Sum: '<S141>/Add2'
   */
  localtmp = (65536.0F * localInvokeAUTOSARServerOpera_f) + 0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_n = (UInt16)localtmp;
    } else {
      localOutDTConv_n = 0U;
    }
  } else {
    localOutDTConv_n = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S146>/autosar_testpoint1' */

  /* S-Function Block: <S146>/autosar_testpoint1 */
  InM_mfTotExEstim_IRV_MP = localOutDTConv_n;

  /* SignalConversion: '<S135>/Signal Conversion2' */
  localTmpSignalConversionAtFARSp = localOutDTConv_n;

  /* end of Outputs for SubSystem: '<S43>/F02_Output_Interface_calculation' */

  /* SignalConversion: '<S43>/TmpSignal ConversionAtAirEfc_facChrExpFilEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_004_TEV_AirEfc_facChrExpFilEstim_irv
    (localAirEfc_facChrExpFilEstim_i);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtAirEfc_facChrExpScvFilEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_004_TEV_AirEfc_facChrExpScvFilEstim_irv
    (localAirEfc_facChrExpScvFilEsti);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_facSlopEfcEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_004_TEV_InM_facSlopEfcEstim_irv
    (localInM_facSlopEfcEstim_irv);

  /* Switch: '<S139>/Switch' incorporates:
   *  Constant: '<S139>/Byp_Fonction_SC'
   *  Constant: '<S139>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_a = InM_mfAirEstim_B;
  }

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_mfAirEstimInport2' */
  Rte_Write_P_InM_mfAirEstim_InM_mfAirEstim(localTmpSignalConversionAtEng_a);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_mfTotExEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_004_TEV_InM_mfTotExEstim_irv
    (localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S43>/TmpSignal ConversionAtInM_rTotLdExEstimInport2' */
  Rte_Write_P_InM_rTotLdExEstim_InM_rTotLdExEstim
    (localTmpSignalConversionAtInT_g);
}

/* Start for exported function: RE_InMdlT_037_MSE */
void RE_InMdlT_037_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S28>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F02_1_init'
   *
   * Block requirements for '<S1>/INM1_F02_1_init':
   *  1. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_357.01 ;
   *  2. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  3. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_172.01 ;
   *  4. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  5. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  7. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_289.02 ;
   */

  /* Start for atomic SubSystem: '<S42>/F01_Task_scheduler' */

  /* Start for Embedded MATLAB: '<S121>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S42>/F01_EngCylPrm_outputs_initialization'
   *  Start for SubSystem: '<S42>/F03_AirEfc_outputs_initialization'
   */

  /* end of Start for SubSystem: '<S42>/F01_Task_scheduler' */
}

/* Output and update for exported function: RE_InMdlT_037_MSE */
void RE_InMdlT_037_MSE(void)
{
  UInt16 localSwitch_0;
  UInt16 localSignalConversion;

  /* S-Function (fcncallgen): '<S28>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F02_1_init'
   *
   * Block requirements for '<S1>/INM1_F02_1_init':
   *  1. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_357.01 ;
   *  2. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  3. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_172.01 ;
   *  4. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  5. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_290.02 ;
   *  7. SubSystem "INM1_F02_1_init" !Trace_To : VEMS_R_11_01067_289.02 ;
   */

  /* Outputs for atomic SubSystem: '<S42>/F01_Task_scheduler' */

  /* Embedded MATLAB: '<S121>/Task_sceduler' incorporates:
   *  SubSystem: '<S42>/F01_EngCylPrm_outputs_initialization'
   *  SubSystem: '<S42>/F03_AirEfc_outputs_initialization'
   */
  /* Embedded MATLAB Function 'InMdlT/INM1_F02_1_init/F01_Task_scheduler/Task_sceduler': '<S126>:1' */
  /* '<S126>:1:2' */

  /* SignalConversion: '<S129>/copy' incorporates:
   *  Constant: '<S122>/Cste_0'
   */
  AirEfc_facChrExpScvFilEstim = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S129>/autosar_testpoint1' */

  /* S-Function Block: <S129>/autosar_testpoint1 */

  /* SignalConversion: '<S128>/copy' incorporates:
   *  Constant: '<S122>/Cste_1'
   */
  AirEfc_facChrExpFilEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S128>/autosar_testpoint1' */

  /* S-Function Block: <S128>/autosar_testpoint1 */

  /* SignalConversion: '<S127>/copy' incorporates:
   *  Constant: '<S122>/Cste_1e_5'
   */
  InM_facSlopEfcEstim_IRV_MP = 9.999999747E-006F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S127>/autosar_testpoint1' */

  /* S-Function Block: <S127>/autosar_testpoint1 */

  /* SignalConversion: '<S122>/Signal Conversion2' incorporates:
   *  Constant: '<S122>/Cste_1e_5'
   */
  InMdlT_B.InM_facSlopEfcEstim_irv_d = 9.999999747E-006F;

  /* '<S126>:1:3' */

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S120>/Cste_1'
   *  Constant: '<S125>/Byp_Fonction_SC'
   *  Constant: '<S125>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_0 = InM_rTotLdExEstim_B;
  } else {
    localSwitch_0 = 16384U;
  }

  /* SignalConversion: '<S120>/Signal Conversion1' incorporates:
   *  Constant: '<S120>/Cste_3'
   */
  localSignalConversion = 0U;

  /* SignalConversion: '<S124>/copy' incorporates:
   *  Constant: '<S120>/Cste_2'
   */
  InM_mfTotExEstim_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S124>/autosar_testpoint1' */

  /* S-Function Block: <S124>/autosar_testpoint1 */

  /* SignalConversion: '<S120>/Signal Conversion2' incorporates:
   *  Constant: '<S120>/Cste_2'
   */
  InMdlT_B.InM_mfTotExEstim_irv_i = 0U;

  /* end of Outputs for SubSystem: '<S42>/F01_Task_scheduler' */

  /* SignalConversion: '<S42>/TmpSignal ConversionAtAirEfc_facChrExpFilEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_037_MSE_AirEfc_facChrExpFilEstim_irv(0.0F);

  /* SignalConversion: '<S42>/TmpSignal ConversionAtAirEfc_facChrExpScvFilEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_037_MSE_AirEfc_facChrExpScvFilEstim_irv(0.0F);

  /* SignalConversion: '<S42>/TmpSignal ConversionAtInM_facSlopEfcEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_037_MSE_InM_facSlopEfcEstim_irv
    (InMdlT_B.InM_facSlopEfcEstim_irv_d);

  /* Switch: '<S123>/Switch' incorporates:
   *  Constant: '<S123>/Byp_Fonction_SC'
   *  Constant: '<S123>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSignalConversion = InM_mfAirEstim_B;
  }

  /* SignalConversion: '<S42>/TmpSignal ConversionAtInM_mfAirEstimInport2' */
  Rte_Write_P_InM_mfAirEstim_InM_mfAirEstim(localSignalConversion);

  /* SignalConversion: '<S42>/TmpSignal ConversionAtInM_mfTotExEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_037_MSE_InM_mfTotExEstim_irv
    (InMdlT_B.InM_mfTotExEstim_irv_i);

  /* SignalConversion: '<S42>/TmpSignal ConversionAtInM_rTotLdExEstimInport2' */
  Rte_Write_P_InM_rTotLdExEstim_InM_rTotLdExEstim(localSwitch_0);
}

/* Start for exported function: RE_InMdlT_039_MSE */
void RE_InMdlT_039_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S33>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F03_1_InCanPurgGasFlow_init'
   *
   * Block requirements for '<S1>/INM1_F03_1_InCanPurgGasFlow_init':
   *  1. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_017.01 ;
   *  2. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_018.01 ;
   *  3. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_019.01 ;
   *  4. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_359.01 ;
   *  5. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_273.01 ;
   *  6. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_369.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_039_MSE */
void RE_InMdlT_039_MSE(void)
{
  UInt8 localInM_facCfeCanPurgCor;
  UInt16 localInM_mfTotCanPurgEstim;

  /* S-Function (fcncallgen): '<S33>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F03_1_InCanPurgGasFlow_init'
   *
   * Block requirements for '<S1>/INM1_F03_1_InCanPurgGasFlow_init':
   *  1. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_017.01 ;
   *  2. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_018.01 ;
   *  3. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_019.01 ;
   *  4. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_359.01 ;
   *  5. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_273.01 ;
   *  6. SubSystem "INM1_F03_1_InCanPurgGasFlow_init" !Trace_To : VEMS_R_11_01067_369.01 ;
   */

  /* user code (Output function Body for TID88) */
  RE_InMdlT_Init();

  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S148>/Byp_Fonction_SC'
   *  Constant: '<S148>/Int_BypC'
   *  Constant: '<S44>/Constant9'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localInM_facCfeCanPurgCor = InM_facCfeCanPurgCor_B;
  } else {
    localInM_facCfeCanPurgCor = 0U;
  }

  /* SignalConversion: '<S44>/TmpSignal ConversionAtInM_facCfeCanPurgCorInport2' */
  Rte_Write_P_InM_facCfeCanPurgCor_InM_facCfeCanPurgCor
    (localInM_facCfeCanPurgCor);

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   *  Constant: '<S44>/Constant1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localInM_mfTotCanPurgEstim = InM_mfTotCanPurgEstim_B;
  } else {
    localInM_mfTotCanPurgEstim = 0U;
  }

  /* SignalConversion: '<S44>/TmpSignal ConversionAtInM_mfTotCanPurgEstimInport2' */
  Rte_Write_P_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim
    (localInM_mfTotCanPurgEstim);
}

/* Start for exported function: RE_InMdlT_031_TEV */
void RE_InMdlT_031_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S34>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F03_2InCanPurgGasFlow_computation'
   *
   * Block requirements for '<S1>/INM1_F03_2InCanPurgGasFlow_computation':
   *  1. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_017.01 ;
   *  2. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_018.01 ;
   *  3. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_348.01 ;
   *  4. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_273.01 ;
   *  5. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_369.01 ;
   *  6. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  7. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_194.01 ;
   *  8. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  9. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_272.01 ;
   *  10. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_271.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_031_TEV */
void RE_InMdlT_031_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtCanPu;
  UInt16 localDataTypeConversion1;
  UInt16 localOutDTConv_j;
  Boolean localAutosarServer;
  UInt8 localTmpSignalConversionAtCan_o;
  UInt8 localLookUpTable_n;
  UInt8 localTmpSignalConversionAtEng_b;
  Boolean localRelationalOperator_k;
  Boolean localNot;
  Float32 localDataTypeConversion12;
  Float32 localDivide_k;
  Float32 localAdd2_n;
  UInt8 localMerge2;
  UInt16 localInM_mfTotCanPurgEstim_p;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt8 localTmpSignalConversionAtUsT_i;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S34>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F03_2InCanPurgGasFlow_computation'
   *
   * Block requirements for '<S1>/INM1_F03_2InCanPurgGasFlow_computation':
   *  1. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_017.01 ;
   *  2. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_018.01 ;
   *  3. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_348.01 ;
   *  4. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_273.01 ;
   *  5. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_369.01 ;
   *  6. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  7. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_194.01 ;
   *  8. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  9. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_272.01 ;
   *  10. SubSystem "INM1_F03_2InCanPurgGasFlow_computation" !Trace_To : VEMS_R_11_01067_271.01 ;
   */

  /* SignalConversion: '<S45>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_b);

  /* RelationalOperator: '<S45>/Relational Operator' incorporates:
   *  Constant: '<S45>/Ext_stRun_SC'
   */
  localRelationalOperator_k = (localTmpSignalConversionAtEng_b == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S45>/F01_Engine_not_running' incorporates:
   *  EnablePort: '<S150>/EngineNotRunning'
   *  Logic: '<S45>/Logical Operator1'
   *
   * Block requirements for '<S45>/F01_Engine_not_running':
   *  1. SubSystem "F01_Engine_not_running" !Trace_To : VEMS_R_11_01067_020.01 ;
   *  2. SubSystem "F01_Engine_not_running" !Trace_To : VEMS_R_11_01067_021.01 ;
   */
  if (!localRelationalOperator_k) {
    /* Switch: '<S153>/Switch' incorporates:
     *  Constant: '<S150>/Constant9'
     *  Constant: '<S153>/Byp_Fonction_SC'
     *  Constant: '<S153>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge2 = InM_facCfeCanPurgCor_B;
    } else {
      localMerge2 = 0U;
    }

    /* Switch: '<S154>/Switch' incorporates:
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S154>/Byp_Fonction_SC'
     *  Constant: '<S154>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localInM_mfTotCanPurgEstim_p = InM_mfTotCanPurgEstim_B;
    } else {
      localInM_mfTotCanPurgEstim_p = 0U;
    }
  }

  /* end of Outputs for SubSystem: '<S45>/F01_Engine_not_running' */

  /* SignalConversion: '<S45>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S45>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&localTmpSignalConversionAtUsT_i);

  /* SignalConversion: '<S45>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_pDsT_i);

  /* SignalConversion: '<S45>/TmpSignal ConversionAtCanPurg_rOpCanPurgReqOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_rOpCanPurgReq'
   */
  Rte_Read_R_CanPurg_rOpCanPurgReq_CanPurg_rOpCanPurgReq
    (&localTmpSignalConversionAtCan_o);

  /* SignalConversion: '<S45>/TmpSignal ConversionAtCanPurg_concFuStmEstimOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_concFuStmEstim'
   */
  Rte_Read_R_CanPurg_concFuStmEstim_CanPurg_concFuStmEstim
    (&localTmpSignalConversionAtCanPu);

  /* S-Function (sfun_autosar_clientop): '<S152>/AutosarServer' */
  Rte_Call_R_FRM_bInhInMDynCor_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S152>/Not' */
  localNot = !localAutosarServer;

  /* Outputs for enable SubSystem: '<S45>/F02_Engine_running' incorporates:
   *  EnablePort: '<S151>/EngineRunning'
   *
   * Block requirements for '<S45>/F02_Engine_running':
   *  1. SubSystem "F02_Engine_running" !Trace_To : VEMS_R_11_01067_020.01 ;
   *  2. SubSystem "F02_Engine_running" !Trace_To : VEMS_R_11_01067_022.01 ;
   */
  if (localRelationalOperator_k) {
    /* DataTypeConversion: '<S151>/Data Type Conversion12' */
    localDataTypeConversion12 = ((Float32)localTmpSignalConversionAtUsThr) *
      8.0F;

    /* Product: '<S161>/Divide' incorporates:
     *  DataTypeConversion: '<S151>/Data Type Conversion3'
     */
    localDivide_k = (((Float32)InMdlT_B.TmpSignalConversionAtInM_pDsT_i) *
                     0.0078125F) / localDataTypeConversion12;

    /* Outputs for atomic SubSystem: '<S161>/If Action Subsystem3' */

    /* Switch: '<S170>/Switch1' incorporates:
     *  Constant: '<S170>/Constant1'
     *  Constant: '<S170>/Constant2'
     *  Constant: '<S170>/Constant3'
     *  Logic: '<S170>/Logical Operator1'
     *  RelationalOperator: '<S170>/Relational Operator'
     *  RelationalOperator: '<S170>/Relational Operator1'
     *  RelationalOperator: '<S170>/Relational Operator3'
     */
    if (((localDivide_k != localDivide_k) || (localDivide_k > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_k)) {
      localDivide_k = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S161>/If Action Subsystem3' */

    /* DataTypeConversion: '<S151>/Data Type Conversion1' */
    localtmp = localDivide_k;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDataTypeConversion1 = (UInt16)localtmp;
      } else {
        localDataTypeConversion1 = 0U;
      }
    } else {
      localDataTypeConversion1 = MAX_uint16_T;
    }

    /* Lookup: '<S156>/Look-Up Table'
     * About '<S156>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-20
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localOutDTConv_j), (&(InM_facCfeVlv_T[0])),
                   localDataTypeConversion1, (&(Air_rAirPres_A[0])), 21U);

    /* DataTypeDuplicate Block: '<S156>/Data Type Duplicate1'
     *
     * Regarding '<S156>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S157>/Look-Up Table'
     * About '<S157>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_n), (&(InM_facCfeCanPurgCor_T[0])),
                  localTmpSignalConversionAtCanPu, (&(Air_concFuStm_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S157>/Data Type Duplicate1'
     *
     * Regarding '<S157>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S162>/Data Type Conversion'
     *
     * Regarding '<S162>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Product: '<S166>/Divide' incorporates:
     *  Constant: '<S151>/Constant7'
     *  Sum: '<S151>/Sum'
     */
    localAdd2_n = ((((Float32)localLookUpTable_n) * 0.00390625F) + 1.0F) *
      (((Float32)localOutDTConv_j) * 9.536743164E-007F);

    /* DataTypeConversion: '<S159>/OutDTConv' incorporates:
     *  Constant: '<S159>/offset'
     *  Constant: '<S159>/offset1'
     *  Constant: '<S159>/one_on_slope'
     *  Product: '<S159>/Product4'
     *  Sum: '<S159>/Add1'
     *  Sum: '<S159>/Add2'
     */
    localDivide_k = (1.048576E+006F * localAdd2_n) + 0.5F;
    if (localDivide_k < 65536.0F) {
      localOutDTConv_j = (UInt16)localDivide_k;
    } else {
      localOutDTConv_j = MAX_uint16_T;
    }

    /* DataStoreWrite: '<S151>/Data Store Write1' */
    InM_facCfeCanPurg_MP = localOutDTConv_j;

    /* Lookup: '<S155>/Look-Up Table'
     * About '<S155>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  2^-8
     * Output0 Data Type:  Fixed Point    U16  2^-28
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localOutDTConv_j), (&(InM_arEffCanPurg_T[0])),
                  localTmpSignalConversionAtCan_o, (&(InM_rOpCanPurg_A[0])), 10U);

    /* DataTypeDuplicate Block: '<S155>/Data Type Duplicate1'
     *
     * Regarding '<S155>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataStoreWrite: '<S151>/Data Store Write2' */
    InM_arEffCanPurg_MP = localOutDTConv_j;

    /* Product: '<S160>/Divide' incorporates:
     *  DataTypeConversion: '<S151>/Data Type Conversion4'
     */
    localDivide_k = localDataTypeConversion12 / (((Float32)
      localTmpSignalConversionAtUsT_i) * 0.125F);

    /* Outputs for atomic SubSystem: '<S160>/If Action Subsystem3' */

    /* Switch: '<S168>/Switch1' incorporates:
     *  Constant: '<S168>/Constant1'
     *  Constant: '<S168>/Constant2'
     *  Constant: '<S168>/Constant3'
     *  Logic: '<S168>/Logical Operator1'
     *  RelationalOperator: '<S168>/Relational Operator'
     *  RelationalOperator: '<S168>/Relational Operator1'
     *  RelationalOperator: '<S168>/Relational Operator3'
     */
    if (((localDivide_k != localDivide_k) || (localDivide_k > 3.000000005E+038F))
        || (-3.000000005E+038F > localDivide_k)) {
      localDivide_k = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S160>/If Action Subsystem3' */

    /* Switch: '<S151>/Switch1' incorporates:
     *  Constant: '<S151>/Constant2'
     *  DataTypeConversion: '<S151>/Data Type Conversion2'
     *  Product: '<S164>/Divide'
     *  Product: '<S165>/Divide'
     */
    if (localNot) {
      localAdd2_n = 0.0F;
    } else {
      localAdd2_n *= (((Float32)localOutDTConv_j) * 3.725290298E-009F) *
        localDivide_k;
    }

    /* DataTypeConversion: '<S158>/OutDTConv' incorporates:
     *  Constant: '<S158>/offset'
     *  Constant: '<S158>/offset1'
     *  Constant: '<S158>/one_on_slope'
     *  Product: '<S158>/Product4'
     *  Sum: '<S158>/Add1'
     *  Sum: '<S158>/Add2'
     */
    localDivide_k = (1.048576E+006F * localAdd2_n) + 0.5F;
    if (localDivide_k < 65536.0F) {
      if (localDivide_k >= 0.0F) {
        localOutDTConv_j = (UInt16)localDivide_k;
      } else {
        localOutDTConv_j = 0U;
      }
    } else {
      localOutDTConv_j = MAX_uint16_T;
    }

    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S162>/Byp_Fonction_SC'
     *  Constant: '<S162>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge2 = InM_facCfeCanPurgCor_B;
    } else {
      localMerge2 = localLookUpTable_n;
    }

    /* Switch: '<S163>/Switch' incorporates:
     *  Constant: '<S163>/Byp_Fonction_SC'
     *  Constant: '<S163>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localInM_mfTotCanPurgEstim_p = InM_mfTotCanPurgEstim_B;
    } else {
      localInM_mfTotCanPurgEstim_p = localOutDTConv_j;
    }
  }

  /* end of Outputs for SubSystem: '<S45>/F02_Engine_running' */

  /* SignalConversion: '<S45>/TmpSignal ConversionAtInM_facCfeCanPurgCorInport2' */
  Rte_Write_P_InM_facCfeCanPurgCor_InM_facCfeCanPurgCor(localMerge2);

  /* SignalConversion: '<S45>/TmpSignal ConversionAtInM_mfTotCanPurgEstimInport2' */
  Rte_Write_P_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim
    (localInM_mfTotCanPurgEstim_p);
}

/* Start for exported function: RE_InMdlT_038_MSE */
void RE_InMdlT_038_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S35>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F04_1_Cpc_init_asl'
   *
   * Block requirements for '<S1>/INM1_F04_1_Cpc_init_asl':
   *  1. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_011.01 ;
   *  2. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_012.01 ;
   *  3. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_013.01 ;
   *  4. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_358.01 ;
   *  5. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  6. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_277.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_038_MSE */
void RE_InMdlT_038_MSE(void)
{
  UInt16 localSwitch_c;

  /* S-Function (fcncallgen): '<S35>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F04_1_Cpc_init_asl'
   *
   * Block requirements for '<S1>/INM1_F04_1_Cpc_init_asl':
   *  1. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_011.01 ;
   *  2. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_012.01 ;
   *  3. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_013.01 ;
   *  4. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_358.01 ;
   *  5. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  6. SubSystem "INM1_F04_1_Cpc_init_asl" !Trace_To : VEMS_R_11_01067_277.01 ;
   */

  /* Switch: '<S172>/Switch' incorporates:
   *  Constant: '<S172>/Byp_Fonction_SC'
   *  Constant: '<S172>/Int_BypC'
   *  Constant: '<S46>/Constant2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_c = InM_mfAirCanPurgEstim_B;
  } else {
    localSwitch_c = 0U;
  }

  /* SignalConversion: '<S46>/TmpSignal ConversionAtInM_mfAirCanPurgEstimInport2' */
  Rte_Write_P_InM_mfAirCanPurgEstim_InM_mfAirCanPurgEstim(localSwitch_c);

  /* SignalConversion: '<S171>/copy' incorporates:
   *  Constant: '<S46>/Constant1'
   */
  InM_mfFuStmCanPurgEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S171>/autosar_testpoint1' */

  /* S-Function Block: <S171>/autosar_testpoint1 */

  /* SignalConversion: '<S46>/TmpSignal ConversionAtInM_mfFuStmCanPurgEstim_irvInport2' incorporates:
   *  Constant: '<S46>/Constant1'
   *  SignalConversion: '<S46>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_038_MSE_InM_mfFuStmCanPurgEstim_irv(0.0F);
}

/* Start for exported function: RE_InMdlT_027_TEV */
void RE_InMdlT_027_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S36>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F04_2_Calc_purge_fr'
   *
   * Block requirements for '<S1>/INM1_F04_2_Calc_purge_fr':
   *  1. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_011.01 ;
   *  2. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_012.01 ;
   *  3. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_014.01 ;
   *  4. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_345.02 ;
   *  5. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  6. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_277.01 ;
   *  7. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_271.01 ;
   *  8. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_278.01 ;
   *  9. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  10. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_370.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_027_TEV */
void RE_InMdlT_027_TEV(void)
{
  /* local block i/o variables */
  Float32 localSwitch1_a;
  UInt8 localTmpSignalConversionAtEn_gd;
  Boolean localRelationalOperator_o;
  Float32 localInM_mfFuStmCanPurgEstim__j;
  Float32 localAdd2_o;
  UInt16 localMerge2_n;
  UInt16 localTmpSignalConversionAtCan_c;

  /* S-Function (fcncallgen): '<S36>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F04_2_Calc_purge_fr'
   *
   * Block requirements for '<S1>/INM1_F04_2_Calc_purge_fr':
   *  1. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_011.01 ;
   *  2. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_012.01 ;
   *  3. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_014.01 ;
   *  4. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_345.02 ;
   *  5. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  6. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_277.01 ;
   *  7. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_271.01 ;
   *  8. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_278.01 ;
   *  9. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  10. SubSystem "INM1_F04_2_Calc_purge_fr" !Trace_To : VEMS_R_11_01067_370.01 ;
   */

  /* SignalConversion: '<S47>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_gd);

  /* RelationalOperator: '<S47>/Relational Operator' incorporates:
   *  Constant: '<S47>/Ext_stRun_SC'
   */
  localRelationalOperator_o = (localTmpSignalConversionAtEn_gd == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S47>/F01_Engine_not_running' incorporates:
   *  EnablePort: '<S173>/EngineNotRunning'
   *  Logic: '<S47>/Logical Operator1'
   *
   * Block requirements for '<S47>/F01_Engine_not_running':
   *  1. SubSystem "F01_Engine_not_running" !Trace_To : VEMS_R_11_01067_015.01 ;
   */
  if (!localRelationalOperator_o) {
    /* Constant: '<S173>/Constant2' */
    localMerge2_n = 0U;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S176>/autosar_testpoint1' incorporates:
     *  Constant: '<S173>/Constant1'
     */

    /* S-Function Block: <S176>/autosar_testpoint1 */
    InM_mfFuStmCanPurgEstim_IRV_MP = 0.0F;

    /* SignalConversion: '<S173>/Signal Conversion2' incorporates:
     *  Constant: '<S173>/Constant1'
     */
    localInM_mfFuStmCanPurgEstim__j = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S47>/F01_Engine_not_running' */

  /* SignalConversion: '<S47>/TmpSignal ConversionAtCanPurg_concFuStmEstimOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_concFuStmEstim'
   */
  Rte_Read_R_CanPurg_concFuStmEstim_CanPurg_concFuStmEstim
    (&InMdlT_B.TmpSignalConversionAtCanPurg_co);

  /* SignalConversion: '<S47>/TmpSignal ConversionAtCanPurg_concFuStmErrOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_concFuStmErr'
   */
  Rte_Read_R_CanPurg_concFuStmErr_CanPurg_concFuStmErr
    (&localTmpSignalConversionAtCan_c);

  /* SignalConversion: '<S47>/TmpSignal ConversionAtInM_mfTotCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfTotCanPurgEstim_INPUT'
   */
  Rte_Read_R_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim
    (&InMdlT_B.TmpSignalConversionAtInM_mfTotC);

  /* Outputs for enable SubSystem: '<S47>/F02_Engine_running' incorporates:
   *  EnablePort: '<S174>/EngineRunning'
   *
   * Block requirements for '<S47>/F02_Engine_running':
   *  1. SubSystem "F02_Engine_running" !Trace_To : VEMS_R_11_01067_016.01 ;
   */
  if (localRelationalOperator_o) {
    /* DataTypeConversion: '<S174>/Data Type Conversion2' */
    localInM_mfFuStmCanPurgEstim__j = ((Float32)
      InMdlT_B.TmpSignalConversionAtInM_mfTotC) * 9.536743164E-007F;

    /* DataTypeConversion: '<S174>/Data Type Conversion5' */
    localSwitch1_a = ((Float32)InMdlT_B.TmpSignalConversionAtCanPurg_co) *
      1.525878906E-005F;

    /* Product: '<S180>/Divide' incorporates:
     *  Constant: '<S174>/Constant8'
     *  Constant: '<S174>/Constant9'
     *  DataTypeConversion: '<S174>/Data Type Conversion1'
     *  Product: '<S179>/Divide'
     *  Sum: '<S174>/Sum1'
     *  Sum: '<S174>/Sum2'
     */
    localAdd2_o = ((1.0F - localSwitch1_a) * localInM_mfFuStmCanPurgEstim__j) *
      (1.0F - (((Float32)localTmpSignalConversionAtCan_c) * 1.525878906E-005F));

    /* Switch: '<S174>/Switch1' incorporates:
     *  Constant: '<S174>/Ext_stRun_SC'
     *  Product: '<S181>/Divide'
     *  Sum: '<S174>/Sum3'
     */
    if (InM_bSelCanPurgClc_C) {
      localSwitch1_a = localInM_mfFuStmCanPurgEstim__j - localAdd2_o;
    } else {
      localSwitch1_a *= localInM_mfFuStmCanPurgEstim__j;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S178>/autosar_testpoint1' */

    /* S-Function Block: <S178>/autosar_testpoint1 */
    InM_mfFuStmCanPurgEstim_IRV_MP = localSwitch1_a;

    /* SignalConversion: '<S174>/Signal Conversion2' */
    localInM_mfFuStmCanPurgEstim__j = localSwitch1_a;

    /* DataTypeConversion: '<S177>/OutDTConv' incorporates:
     *  Constant: '<S177>/offset'
     *  Constant: '<S177>/offset1'
     *  Constant: '<S177>/one_on_slope'
     *  Product: '<S177>/Product4'
     *  Sum: '<S177>/Add1'
     *  Sum: '<S177>/Add2'
     */
    localAdd2_o = (1.048576E+006F * localAdd2_o) + 0.5F;
    if (localAdd2_o < 65536.0F) {
      if (localAdd2_o >= 0.0F) {
        localMerge2_n = (UInt16)localAdd2_o;
      } else {
        localMerge2_n = 0U;
      }
    } else {
      localMerge2_n = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S47>/F02_Engine_running' */

  /* Switch: '<S175>/Switch' incorporates:
   *  Constant: '<S175>/Byp_Fonction_SC'
   *  Constant: '<S175>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localMerge2_n = InM_mfAirCanPurgEstim_B;
  }

  /* SignalConversion: '<S47>/TmpSignal ConversionAtInM_mfAirCanPurgEstimInport2' */
  Rte_Write_P_InM_mfAirCanPurgEstim_InM_mfAirCanPurgEstim(localMerge2_n);

  /* SignalConversion: '<S47>/TmpSignal ConversionAtInM_mfFuStmCanPurgEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_027_TEV_InM_mfFuStmCanPurgEstim_irv
    (localInM_mfFuStmCanPurgEstim__j);
}

/* Output and update for exported function: RE_InMdlT_045_MSE */
void RE_InMdlT_045_MSE(void)
{
  UInt16 localSwitch_fe;

  /* S-Function (fcncallgen): '<S37>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F05_1_Init'
   *
   * Block requirements for '<S1>/INM1_F05_1_Init':
   *  1. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_365.01 ;
   *  2. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_119.01 ;
   *  3. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_120.01 ;
   *  4. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_121.01 ;
   *  5. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_276.02 ;
   *  6. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_269.03 ;
   *  7. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_266.03 ;
   *  8. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_267.03 ;
   *  9. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_268.03 ;
   *  10. SubSystem "INM1_F05_1_Init" !Trace_To : VEMS_R_11_01067_270.03 ;
   */

  /* Switch: '<S182>/Switch' incorporates:
   *  Constant: '<S182>/Byp_Fonction_SC'
   *  Constant: '<S182>/Int_BypC'
   *  Constant: '<S48>/Constant3'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_mfEGREstimEGRVlv_B;
  } else {
    localSwitch_fe = InM_mfEGREstimEGRVlv_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvInport2' */
  Rte_Write_P_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv(localSwitch_fe);

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S184>/Byp_Fonction_SC'
   *  Constant: '<S184>/Int_BypC'
   *  Constant: '<S48>/Constant5'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_pBackEgPUsEGRVlv_B;
  } else {
    localSwitch_fe = InM_pBackEgPUsEGRVlv_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_pBackEgPUsEGRVlvInport2' */
  Rte_Write_P_InM_pBackEgPUsEGRVlv_InM_pBackEgPUsEGRVlv(localSwitch_fe);

  /* Switch: '<S186>/Switch' incorporates:
   *  Constant: '<S186>/Byp_Fonction_SC'
   *  Constant: '<S186>/Int_BypC'
   *  Constant: '<S48>/Constant4'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_mfEGRReq_arEGR_B;
  } else {
    localSwitch_fe = InM_mfEGRReq_arEGR_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_mfEGRReq_arEGRInport2' */
  Rte_Write_P_InM_mfEGRReq_arEGR_InM_mfEGRReq_arEGR(localSwitch_fe);

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Byp_Fonction_SC'
   *  Constant: '<S187>/Int_BypC'
   *  Constant: '<S48>/Constant6'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_pUsEGRVlv_B;
  } else {
    localSwitch_fe = InM_pUsEGRVlv_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_pUsEGRVlvInport2' */
  Rte_Write_P_InM_pUsEGRVlv_InM_pUsEGRVlv(localSwitch_fe);

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S183>/Byp_Fonction_SC'
   *  Constant: '<S183>/Int_BypC'
   *  Constant: '<S48>/Constant1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_arEffAdpEGRVlv_B;
  } else {
    localSwitch_fe = InM_arEffAdpEGRVlv_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_arEffAdpEGRVlvInport2' */
  Rte_Write_P_InM_arEffAdpEGRVlv_InM_arEffAdpEGRVlv(localSwitch_fe);

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Byp_Fonction_SC'
   *  Constant: '<S185>/Int_BypC'
   *  Constant: '<S48>/Constant2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fe = InM_arEffEGRVlv_B;
  } else {
    localSwitch_fe = InM_arEffEGRVlv_C;
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtInM_arEffEGRVlvInport2' */
  Rte_Write_P_InM_arEffEGRVlv_InM_arEffEGRVlv(localSwitch_fe);
}

/* Start for exported function: RE_InMdlT_029_TEV */
void RE_InMdlT_029_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S38>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F05_2_Egr_prs_flowrate'
   *
   * Block requirements for '<S1>/INM1_F05_2_Egr_prs_flowrate':
   *  1. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_118.01 ;
   *  2. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_119.01 ;
   *  3. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_120.01 ;
   *  4. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_122.01 ;
   *  5. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_347.02 ;
   *  6. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_276.02 ;
   *  7. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_269.03 ;
   *  8. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_268.03 ;
   *  9. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_270.03 ;
   *  10. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_266.03 ;
   *  11. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_267.03 ;
   *  12. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  13. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_264.01 ;
   *  14. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_263.01 ;
   *  15. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_262.01 ;
   *  16. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_261.02 ;
   *  17. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  18. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  19. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_371.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_029_TEV */
void RE_InMdlT_029_TEV(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable_a;
  UInt16 localLookUpTable_g;
  UInt16 localTmpSignalConversionAtExM_m;
  UInt16 localDataTypeConversion13;
  UInt16 localDataTypeConversion11;
  UInt16 localLookUpTable_nc;
  UInt16 localLookUpTable_f;
  UInt16 localLookUpTable_h;
  Boolean localAutosarServer_p;
  UInt8 localTmpSignalConversionAtEGRVl;
  Boolean localNot_c;
  Boolean localNot_f;
  Float32 localSum;
  Float32 localDataTypeConversion9;
  Float32 localDivide_pp;
  Float32 localDivide_jb;
  UInt16 localTmpSignalConversionAtInM_k;
  UInt16 localTmpSignalConversionAtUsT_k;
  SInt8 localTmpSignalConversionAtAFA_n;
  SInt8 localTmpSignalConversionAtAFA_r;
  UInt16 localTmpSignalConversionAtInM_g;
  UInt32 localTmpSignalConversionAtInM_p;
  UInt8 localTmpSignalConversionAtInT_m;
  Float32d localtmp;
  SInt32 localqY;
  UInt16 locallocalInM_pUsEGRVlv;

  /* S-Function (fcncallgen): '<S38>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F05_2_Egr_prs_flowrate'
   *
   * Block requirements for '<S1>/INM1_F05_2_Egr_prs_flowrate':
   *  1. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_118.01 ;
   *  2. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_119.01 ;
   *  3. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_120.01 ;
   *  4. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_122.01 ;
   *  5. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_347.02 ;
   *  6. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_276.02 ;
   *  7. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_269.03 ;
   *  8. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_268.03 ;
   *  9. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_270.03 ;
   *  10. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_266.03 ;
   *  11. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_267.03 ;
   *  12. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  13. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_264.01 ;
   *  14. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_263.01 ;
   *  15. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_262.01 ;
   *  16. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_261.02 ;
   *  17. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  18. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  19. SubSystem "INM1_F05_2_Egr_prs_flowrate" !Trace_To : VEMS_R_11_01067_371.01 ;
   */

  /* SignalConversion: '<S49>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&localTmpSignalConversionAtUsT_k);

  /* SignalConversion: '<S49>/TmpSignal ConversionAtExM_mfEgWoutEGROutport2' incorporates:
   *  Inport: '<Root>/ExM_mfEgWoutEGR'
   */
  Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(&localTmpSignalConversionAtExM_m);

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_pBackEgPUsEGRVlv1Outport2' incorporates:
   *  Inport: '<Root>/InM_pBackEgPUsEGRVlv_INPUT'
   */
  Rte_Read_R_InM_pBackEgPUsEGRVlv_InM_pBackEgPUsEGRVlv
    (&localTmpSignalConversionAtInM_k);

  /* Outputs for atomic SubSystem: '<S49>/F01_Egr_upstr_prs' *
   * Block requirements for '<S49>/F01_Egr_upstr_prs':
   *  1. SubSystem "F01_Egr_upstr_prs" !Trace_To : VEMS_R_11_01067_123.01 ;
   */

  /* Lookup: '<S200>/Look-Up Table'
   * About '<S200>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_g), (&(InM_pDrpLossUsEGRVlv_T[0])),
                 localTmpSignalConversionAtExM_m, (&(Air_mfEGR_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S200>/Data Type Duplicate1'
   *
   * Regarding '<S200>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* SignalConversion Block: '<S188>/Signal Conversion2'
   *
   * Regarding '<S188>/Signal Conversion2':
   *   Eliminate redundant signal conversion block
   */

  /* DataStoreWrite: '<S188>/Data Store Write2' */
  InM_pDrpLossUsEGRVlv_MP = localLookUpTable_g;

  /* Lookup: '<S199>/Look-Up Table'
   * About '<S199>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_a), (&(InM_pBackEgPUsEGRVlv_T[0])),
                 localTmpSignalConversionAtExM_m, (&(Air_mfEg_A[0])), 16U);

  /* DataTypeDuplicate Block: '<S199>/Data Type Duplicate1'
   *
   * Regarding '<S199>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S198>/Data Type Conversion'
   *
   * Regarding '<S198>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Sum: '<S188>/Sum2' incorporates:
   *  Sum: '<S188>/Sum4'
   */
  localqY = ((SInt32)((UInt32)(localTmpSignalConversionAtInM_k +
    localTmpSignalConversionAtUsT_k))) - localLookUpTable_g;
  if (localqY <= 0) {
    locallocalInM_pUsEGRVlv = 0U;
  } else if (localqY > 65535) {
    locallocalInM_pUsEGRVlv = MAX_uint16_T;
  } else {
    locallocalInM_pUsEGRVlv = (UInt16)localqY;
  }

  /* end of Outputs for SubSystem: '<S49>/F01_Egr_upstr_prs' */

  /* SignalConversion: '<S49>/TmpSignal ConversionAtEGRVlv_rOpEGRReqOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_rOpEGRReq'
   */
  Rte_Read_R_EGRVlv_rOpEGRReq_EGRVlv_rOpEGRReq(&localTmpSignalConversionAtEGRVl);

  /* SignalConversion: '<S49>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/AFA_rCor_arEffEGRVlv'
   */
  Rte_Read_R_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv
    (&localTmpSignalConversionAtAFA_r);

  /* SignalConversion: '<S49>/TmpSignal ConversionAtAFA_arEffEGRVlvOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffEGRVlvOfs'
   */
  Rte_Read_R_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs
    (&localTmpSignalConversionAtAFA_n);

  /* Outputs for atomic SubSystem: '<S49>/F02_Egr_eff_area' *
   * Block requirements for '<S49>/F02_Egr_eff_area':
   *  1. SubSystem "F02_Egr_eff_area" !Trace_To : VEMS_R_11_01067_124.01 ;
   */

  /* Lookup: '<S201>/Look-Up Table'
   * About '<S201>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U8  2^-8
   * Output0 Data Type:  Fixed Point    U16  2^-24
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U8( &(localLookUpTable_h), (&(Air_arEffEGRVlv_T[0])),
                localTmpSignalConversionAtEGRVl, (&(Air_rOpEGR_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S201>/Data Type Duplicate1'
   *
   * Regarding '<S201>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S194>/Data Type Conversion'
   *
   * Regarding '<S194>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Sum: '<S189>/Sum' incorporates:
   *  Constant: '<S189>/Constant5'
   *  DataTypeConversion: '<S189>/Data Type Conversion1'
   *  DataTypeConversion: '<S189>/Data Type Conversion3'
   *  Product: '<S202>/Divide'
   *  Sum: '<S189>/Sum1'
   */
  localSum = ((1.0F - (((Float32)localTmpSignalConversionAtAFA_r) * 0.00390625F))
              * (((Float32)localLookUpTable_h) * 5.960464478E-008F)) -
    (((Float32)localTmpSignalConversionAtAFA_n) * 5.960464478E-008F);

  /* end of Outputs for SubSystem: '<S49>/F02_Egr_eff_area' */

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor_INPUT'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&localTmpSignalConversionAtInM_g);

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim(&localTmpSignalConversionAtInM_p);

  /* S-Function (sfun_autosar_clientop): '<S191>/AutosarServer' */
  Rte_Call_R_FRM_bInhInMDynCor_GetFunctionPermission(&localAutosarServer_p);

  /* Logic: '<S191>/Not' */
  localNot_c = !localAutosarServer_p;

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInThM_tSqrtEgUsEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InThM_tSqrtEgUsEGRVlv'
   */
  Rte_Read_R_InThM_tSqrtEgUsEGRVlv_InThM_tSqrtEgUsEGRVlv
    (&localTmpSignalConversionAtInT_m);

  /* S-Function (sfun_autosar_clientop): '<S192>/AutosarServer' */
  Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission(&localAutosarServer_p);

  /* Logic: '<S192>/Not' */
  localNot_f = !localAutosarServer_p;

  /* Outputs for atomic SubSystem: '<S49>/F03_Egr_flowrate' *
   * Block requirements for '<S49>/F03_Egr_flowrate':
   *  1. SubSystem "F03_Egr_flowrate" !Trace_To : VEMS_R_11_01067_125.01 ;
   */

  /* DataTypeConversion: '<S190>/Data Type Conversion9' */
  localDataTypeConversion9 = ((Float32)locallocalInM_pUsEGRVlv) * 8.0F;

  /* Product: '<S207>/Divide' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion10'
   */
  localDivide_pp = (((Float32)localTmpSignalConversionAtInM_g) * 8.0F) /
    localDataTypeConversion9;

  /* Outputs for atomic SubSystem: '<S207>/If Action Subsystem3' */

  /* Switch: '<S215>/Switch1' incorporates:
   *  Constant: '<S215>/Constant1'
   *  Constant: '<S215>/Constant2'
   *  Constant: '<S215>/Constant3'
   *  Logic: '<S215>/Logical Operator1'
   *  RelationalOperator: '<S215>/Relational Operator'
   *  RelationalOperator: '<S215>/Relational Operator1'
   *  RelationalOperator: '<S215>/Relational Operator3'
   */
  if (((localDivide_pp != localDivide_pp) || (localDivide_pp > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_pp)) {
    localDivide_pp = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S207>/If Action Subsystem3' */

  /* DataTypeConversion: '<S190>/Data Type Conversion11' */
  localtmp = localDivide_pp;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion11 = (UInt16)localtmp;
    } else {
      localDataTypeConversion11 = 0U;
    }
  } else {
    localDataTypeConversion11 = MAX_uint16_T;
  }

  /* Lookup: '<S203>/Look-Up Table'
   * About '<S203>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-20
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_f), (&(InM_facCfeVlv_T[0])),
                 localDataTypeConversion11, (&(Air_rAirPres_A[0])), 21U);

  /* DataTypeDuplicate Block: '<S203>/Data Type Duplicate1'
   *
   * Regarding '<S203>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Logic: '<S190>/Logical Operator' incorporates:
   *  Constant: '<S190>/InM_bInhEGRPresEstim_C'
   */
  localNot_c = ((localNot_c) || InM_bInhEGRPresEstim_C);

  /* Product: '<S210>/Divide' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion8'
   */
  localDivide_pp = (((Float32)localTmpSignalConversionAtInM_p) * 0.0078125F) /
    localDataTypeConversion9;

  /* Outputs for atomic SubSystem: '<S210>/If Action Subsystem3' */

  /* Switch: '<S221>/Switch1' incorporates:
   *  Constant: '<S221>/Constant1'
   *  Constant: '<S221>/Constant2'
   *  Constant: '<S221>/Constant3'
   *  Logic: '<S221>/Logical Operator1'
   *  RelationalOperator: '<S221>/Relational Operator'
   *  RelationalOperator: '<S221>/Relational Operator1'
   *  RelationalOperator: '<S221>/Relational Operator3'
   */
  if (((localDivide_pp != localDivide_pp) || (localDivide_pp > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_pp)) {
    localDivide_pp = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S210>/If Action Subsystem3' */

  /* DataTypeConversion: '<S190>/Data Type Conversion13' */
  localtmp = localDivide_pp;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion13 = (UInt16)localtmp;
    } else {
      localDataTypeConversion13 = 0U;
    }
  } else {
    localDataTypeConversion13 = MAX_uint16_T;
  }

  /* Lookup: '<S204>/Look-Up Table'
   * About '<S204>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^-20
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_nc), (&(InM_facCfeVlv1_T[0])),
                 localDataTypeConversion13, (&(Air_rAirPres_A[0])), 21U);

  /* DataTypeDuplicate Block: '<S204>/Data Type Duplicate1'
   *
   * Regarding '<S204>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Switch: '<S190>/Switch' incorporates:
   *  Lookup: '<S204>/Look-Up Table'
   */
  if (localNot_c) {
    localTmpSignalConversionAtInM_p = localLookUpTable_f;
  } else {
    localTmpSignalConversionAtInM_p = localLookUpTable_nc;
  }

  /* Switch: '<S190>/Switch2' incorporates:
   *  Logic: '<S190>/Logical Operator1'
   */
  if (!localNot_f) {
    localqY = localLookUpTable_f;
  } else {
    localqY = (SInt32)localTmpSignalConversionAtInM_p;
  }

  /* DataStoreWrite: '<S190>/Data Store Write1' */
  InM_facCfeEGR_MP = (UInt32)localqY;

  /* DataStoreWrite: '<S190>/Data Store Write2' */
  InM_facCfeEGREstim_MP = localTmpSignalConversionAtInM_p;

  /* DataTypeConversion: '<S190>/Data Type Conversion3' */
  localDivide_pp = ((Float32)localTmpSignalConversionAtInT_m) * 0.125F;

  /* Product: '<S208>/Divide' */
  localDivide_jb = localDataTypeConversion9 / localDivide_pp;

  /* Outputs for atomic SubSystem: '<S208>/If Action Subsystem3' */

  /* Switch: '<S217>/Switch1' incorporates:
   *  Constant: '<S217>/Constant1'
   *  Constant: '<S217>/Constant2'
   *  Constant: '<S217>/Constant3'
   *  Logic: '<S217>/Logical Operator1'
   *  RelationalOperator: '<S217>/Relational Operator'
   *  RelationalOperator: '<S217>/Relational Operator1'
   *  RelationalOperator: '<S217>/Relational Operator3'
   */
  if (((localDivide_jb != localDivide_jb) || (localDivide_jb > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_jb)) {
    localDivide_jb = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S208>/If Action Subsystem3' */

  /* DataTypeConversion: '<S205>/OutDTConv' incorporates:
   *  Constant: '<S205>/offset'
   *  Constant: '<S205>/offset1'
   *  Constant: '<S205>/one_on_slope'
   *  DataTypeConversion: '<S190>/Data Type Conversion2'
   *  Product: '<S205>/Product4'
   *  Product: '<S213>/Divide'
   *  Sum: '<S205>/Add1'
   *  Sum: '<S205>/Add2'
   */
  localDivide_jb = (((((Float32)localqY) * 9.536743164E-007F) * localDivide_jb)
                    * 128.0F) + 0.5F;
  if (localDivide_jb < 65536.0F) {
    if (localDivide_jb >= 0.0F) {
      localTmpSignalConversionAtInM_k = (UInt16)localDivide_jb;
    } else {
      localTmpSignalConversionAtInM_k = 0U;
    }
  } else {
    localTmpSignalConversionAtInM_k = MAX_uint16_T;
  }

  /* Product: '<S209>/Divide' incorporates:
   *  DataTypeConversion: '<S190>/Data Type Conversion1'
   */
  localDivide_pp = (((Float32)localTmpSignalConversionAtInM_p) *
                    9.536743164E-007F) / localDivide_pp;

  /* Outputs for atomic SubSystem: '<S209>/If Action Subsystem3' */

  /* Switch: '<S219>/Switch1' incorporates:
   *  Constant: '<S219>/Constant1'
   *  Constant: '<S219>/Constant2'
   *  Constant: '<S219>/Constant3'
   *  Logic: '<S219>/Logical Operator1'
   *  RelationalOperator: '<S219>/Relational Operator'
   *  RelationalOperator: '<S219>/Relational Operator1'
   *  RelationalOperator: '<S219>/Relational Operator3'
   */
  if (((localDivide_pp != localDivide_pp) || (localDivide_pp > 3.000000005E+038F))
      || (-3.000000005E+038F > localDivide_pp)) {
    localDivide_pp = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S209>/If Action Subsystem3' */

  /* Sum: '<S206>/Add2' incorporates:
   *  Constant: '<S206>/offset'
   *  Constant: '<S206>/offset1'
   *  Constant: '<S206>/one_on_slope'
   *  Product: '<S206>/Product4'
   *  Product: '<S211>/Divide'
   *  Product: '<S212>/Divide'
   *  Sum: '<S206>/Add1'
   */
  localDivide_pp = (((localDivide_pp * localDataTypeConversion9) * localSum) *
                    65536.0F) + 0.5F;

  /* end of Outputs for SubSystem: '<S49>/F03_Egr_flowrate' */

  /* Switch: '<S195>/Switch' incorporates:
   *  Constant: '<S195>/Byp_Fonction_SC'
   *  Constant: '<S195>/Int_BypC'
   *  DataTypeConversion: '<S195>/Data Type Conversion'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_k = InM_arEffAdpEGRVlv_B;
  } else {
    localtmp = localSum;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 24);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtUsT_k = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtUsT_k = 0U;
      }
    } else {
      localTmpSignalConversionAtUsT_k = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_arEffAdpEGRVlvInport2' */
  Rte_Write_P_InM_arEffAdpEGRVlv_InM_arEffAdpEGRVlv
    (localTmpSignalConversionAtUsT_k);

  /* Switch: '<S194>/Switch' incorporates:
   *  Constant: '<S194>/Byp_Fonction_SC'
   *  Constant: '<S194>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_k = InM_arEffEGRVlv_B;
  } else {
    localTmpSignalConversionAtUsT_k = localLookUpTable_h;
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_arEffEGRVlvInport2' */
  Rte_Write_P_InM_arEffEGRVlv_InM_arEffEGRVlv(localTmpSignalConversionAtUsT_k);

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Byp_Fonction_SC'
   *  Constant: '<S197>/Int_BypC'
   *  DataTypeConversion: '<S206>/OutDTConv'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_k = InM_mfEGREstimEGRVlv_B;
  } else if (localDivide_pp < 65536.0F) {
    if (localDivide_pp >= 0.0F) {
      localTmpSignalConversionAtUsT_k = (UInt16)localDivide_pp;
    } else {
      localTmpSignalConversionAtUsT_k = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_k = MAX_uint16_T;
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvInport2' */
  Rte_Write_P_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (localTmpSignalConversionAtUsT_k);

  /* Switch: '<S196>/Switch' incorporates:
   *  Constant: '<S196>/Byp_Fonction_SC'
   *  Constant: '<S196>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInM_k = InM_mfEGRReq_arEGR_B;
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_mfEGRReq_arEGRInport2' */
  Rte_Write_P_InM_mfEGRReq_arEGR_InM_mfEGRReq_arEGR
    (localTmpSignalConversionAtInM_k);

  /* Switch: '<S198>/Switch' incorporates:
   *  Constant: '<S198>/Byp_Fonction_SC'
   *  Constant: '<S198>/Int_BypC'
   *  Lookup: '<S199>/Look-Up Table'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_k = InM_pBackEgPUsEGRVlv_B;
  } else {
    localTmpSignalConversionAtUsT_k = localLookUpTable_a;
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_pBackEgPUsEGRVlvInport2' */
  Rte_Write_P_InM_pBackEgPUsEGRVlv_InM_pBackEgPUsEGRVlv
    (localTmpSignalConversionAtUsT_k);

  /* Switch: '<S193>/Switch' incorporates:
   *  Constant: '<S193>/Byp_Fonction_SC'
   *  Constant: '<S193>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    locallocalInM_pUsEGRVlv = InM_pUsEGRVlv_B;
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAtInM_pUsEGRVlvInport2' */
  Rte_Write_P_InM_pUsEGRVlv_InM_pUsEGRVlv(locallocalInM_pUsEGRVlv);
}

/* Output and update for exported function: RE_InMdlT_035_MSE */
void RE_InMdlT_035_MSE(void)
{
  UInt8 localSwitch_o;
  Boolean localSwitch_go;
  SInt16 localInM_mfAirDifIn;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F06_1_Init'
   *
   * Block requirements for '<S1>/INM1_F06_1_Init':
   *  1. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_154.01 ;
   *  2. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_155.01 ;
   *  3. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_156.01 ;
   *  4. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_355.01 ;
   *  5. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_165.01 ;
   *  6. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_166.01 ;
   *  7. SubSystem "INM1_F06_1_Init" !Trace_To : VEMS_R_11_01067_167.01 ;
   */

  /* Switch: '<S224>/Switch' incorporates:
   *  Constant: '<S224>/Byp_Fonction_SC'
   *  Constant: '<S224>/Int_BypC'
   *  Constant: '<S50>/Constant3'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localInM_mfAirDifIn = InM_mfAirDifIn_B;
  } else {
    localInM_mfAirDifIn = 0;
  }

  /* SignalConversion: '<S50>/TmpSignal ConversionAtInM_mfAirDifInInport2' */
  Rte_Write_P_InM_mfAirDifIn_InM_mfAirDifIn(localInM_mfAirDifIn);

  /* Switch: '<S223>/Switch' incorporates:
   *  Constant: '<S223>/Byp_Fonction_SC'
   *  Constant: '<S223>/Int_BypC'
   *  Constant: '<S50>/Ext_stStabTranLd_SC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_o = InM_stTranLd_B;
  } else {
    localSwitch_o = Ext_stStabTranLd_SC;
  }

  /* SignalConversion: '<S50>/TmpSignal ConversionAtInM_stTranLdInport2' */
  Rte_Write_P_InM_stTranLd_InM_stTranLd(localSwitch_o);

  /* Switch: '<S222>/Switch' incorporates:
   *  Constant: '<S222>/Byp_Fonction_SC'
   *  Constant: '<S222>/Int_BypC'
   *  Constant: '<S50>/Constant1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_go = InM_bAcceEng_B;
  } else {
    localSwitch_go = TRUE;
  }

  /* SignalConversion: '<S50>/TmpSignal ConversionAtInM_bAcceEngInport2' */
  Rte_Write_P_InM_bAcceEng_InM_bAcceEng(localSwitch_go);
}

/* Start for exported function: RE_InMdlT_002_TEV */
void RE_InMdlT_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F06_2_Load_transient_detection'
   *
   * Block requirements for '<S1>/INM1_F06_2_Load_transient_detection':
   *  1. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_154.01 ;
   *  2. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_155.01 ;
   *  3. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_157.01 ;
   *  4. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_330.01 ;
   *  5. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_165.01 ;
   *  6. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_166.01 ;
   *  7. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_167.01 ;
   *  8. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  9. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  10. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_169.01 ;
   *  11. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  12. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_321.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_002_TEV */
void RE_InMdlT_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtIn_jk;
  UInt8 localLookUpTable_d;
  UInt8 localLookUpTable_e1;
  UInt8 localTmpSignalConversionAtEng_m;
  Boolean localRelationalOperator_d;
  Boolean localMerge1;
  UInt8 localMerge;
  Float32 localSum_l;
  SInt16 localMerge2_b;
  UInt16 localTmpSignalConversionAtInM_m;
  UInt16 localTmpSignalConversionAtIn_gi;
  UInt16 localTmpSignalConversionAtInM_j;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F06_2_Load_transient_detection'
   *
   * Block requirements for '<S1>/INM1_F06_2_Load_transient_detection':
   *  1. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_154.01 ;
   *  2. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_155.01 ;
   *  3. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_157.01 ;
   *  4. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_330.01 ;
   *  5. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_165.01 ;
   *  6. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_166.01 ;
   *  7. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_167.01 ;
   *  8. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  9. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  10. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_169.01 ;
   *  11. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  12. SubSystem "INM1_F06_2_Load_transient_detection" !Trace_To : VEMS_R_11_01067_321.02 ;
   */

  /* SignalConversion: '<S51>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_m);

  /* RelationalOperator: '<S51>/Relational Operator' incorporates:
   *  Constant: '<S51>/Ext_stRun_SC'
   */
  localRelationalOperator_d = (localTmpSignalConversionAtEng_m == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S51>/F00_Engine_not_running' incorporates:
   *  EnablePort: '<S225>/EngineNotRunning'
   *  Logic: '<S51>/NAN'
   *
   * Block requirements for '<S51>/F00_Engine_not_running':
   *  1. SubSystem "F00_Engine_not_running" !Trace_To : VEMS_R_11_01067_158.01 ;
   */
  if (!localRelationalOperator_d) {
    /* Switch: '<S229>/Switch' incorporates:
     *  Constant: '<S225>/Constant4'
     *  Constant: '<S229>/Byp_Fonction_SC'
     *  Constant: '<S229>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge2_b = InM_mfAirDifIn_B;
    } else {
      localMerge2_b = 0;
    }

    /* Switch: '<S228>/Switch' incorporates:
     *  Constant: '<S225>/Ext_stStabTranLd_SC'
     *  Constant: '<S228>/Byp_Fonction_SC'
     *  Constant: '<S228>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge = InM_stTranLd_B;
    } else {
      localMerge = Ext_stStabTranLd_SC;
    }

    /* Switch: '<S227>/Switch' incorporates:
     *  Constant: '<S225>/Constant2'
     *  Constant: '<S227>/Byp_Fonction_SC'
     *  Constant: '<S227>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge1 = InM_bAcceEng_B;
    } else {
      localMerge1 = TRUE;
    }
  }

  /* end of Outputs for SubSystem: '<S51>/F00_Engine_not_running' */

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_mfAirThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&localTmpSignalConversionAtInM_m);

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_mfAirCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirCanPurgEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirCanPurgEstim_InM_mfAirCanPurgEstim
    (&localTmpSignalConversionAtIn_gi);

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_mfAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirEstim_InM_mfAirEstim(&localTmpSignalConversionAtInM_j);

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_mfTotExEstim_irvOutport2' */
  localTmpSignalConversionAtIn_jk =
    Rte_IrvRead_RE_InMdlT_002_TEV_InM_mfTotExEstim_irv();

  /* Outputs for enable SubSystem: '<S51>/F01_Engine_running' incorporates:
   *  EnablePort: '<S226>/EngineRunning'
   *
   * Block requirements for '<S51>/F01_Engine_running':
   *  1. SubSystem "F01_Engine_running" !Trace_To : VEMS_R_11_01067_159.01 ;
   */
  if (localRelationalOperator_d) {
    /* Lookup: '<S230>/Look-Up Table'
     * About '<S230>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_d), (&(InM_mfAirTranToStabThd_T[0])),
                  localTmpSignalConversionAtIn_jk, (&(Air_mfAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S230>/Data Type Duplicate1'
     *
     * Regarding '<S230>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S231>/Look-Up Table'
     * About '<S231>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U8  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_e1), (&(InM_mfAirStabToTranThd_T[0])),
                  localTmpSignalConversionAtIn_jk, (&(Air_mfAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S231>/Data Type Duplicate1'
     *
     * Regarding '<S231>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S226>/Data Type Conversion1' incorporates:
     *  Lookup: '<S230>/Look-Up Table'
     */
    InM_mfAirTranToStabThd = ((Float32)localLookUpTable_d) * 3.051757813E-005F;

    /* DataTypeConversion: '<S226>/Data Type Conversion2' incorporates:
     *  Lookup: '<S231>/Look-Up Table'
     */
    InM_mfAirStabToTranThd = ((Float32)localLookUpTable_e1) * 3.051757813E-005F;

    /* Sum: '<S226>/Sum' incorporates:
     *  DataTypeConversion: '<S226>/Data Type Conversion3'
     *  DataTypeConversion: '<S226>/Data Type Conversion4'
     *  DataTypeConversion: '<S226>/Data Type Conversion5'
     */
    localSum_l = ((((Float32)localTmpSignalConversionAtInM_m) *
                   1.525878906E-005F) + (((Float32)
      localTmpSignalConversionAtIn_gi) * 9.536743164E-007F)) - (((Float32)
      localTmpSignalConversionAtInM_j) * 1.525878906E-005F);

    /* Stateflow: '<S226>/F00_Load_transient_detection_chart1' incorporates:
     *  Constant: '<S226>/Ext_stAcceTranLd_SC'
     *  Constant: '<S226>/Ext_stDeceTranLd_SC'
     *  Constant: '<S226>/Ext_stStabTranLd_SC'
     */
    /* Gateway: InMdlT/INM1_F06_2_Load_transient_detection/F01_Engine_running/F00_Load_transient_detection_chart1 */
    /* During: InMdlT/INM1_F06_2_Load_transient_detection/F01_Engine_running/F00_Load_transient_detection_chart1 */
    if (InMdlT_DWork.is_active_c3_InMdlT == 0) {
      /* Entry: InMdlT/INM1_F06_2_Load_transient_detection/F01_Engine_running/F00_Load_transient_detection_chart1 */
      InMdlT_DWork.is_active_c3_InMdlT = 1U;

      /* Transition: '<S232>:4' */
      /* Entry 'STEADY': '<S232>:1' */
      InMdlT_DWork.is_c3_InMdlT = IN_STEADY;
      InM_stTranLd_SF = Ext_stStabTranLd_SC;
      InM_bAcceEng_SF = TRUE;
    } else {
      switch (InMdlT_DWork.is_c3_InMdlT) {
       case IN_ACCEL:
        /* During 'ACCEL': '<S232>:2' */
        if ((localSum_l < InM_mfAirTranToStabThd) && (localSum_l >=
             (-InM_mfAirStabToTranThd))) {
          /* Transition: '<S232>:7' */
          /* Exit 'ACCEL': '<S232>:2' */
          /* Entry 'STEADY': '<S232>:1' */
          InMdlT_DWork.is_c3_InMdlT = IN_STEADY;
          InM_stTranLd_SF = Ext_stStabTranLd_SC;
          InM_bAcceEng_SF = TRUE;
        } else {
          if (localSum_l < (-InM_mfAirStabToTranThd)) {
            /* Transition: '<S232>:10' */
            /* Exit 'ACCEL': '<S232>:2' */
            /* Entry 'DECEL': '<S232>:3' */
            InMdlT_DWork.is_c3_InMdlT = IN_DECEL;
            InM_stTranLd_SF = Ext_stDeceTranLd_SC;
            InM_bAcceEng_SF = FALSE;
          }
        }
        break;

       case IN_DECEL:
        /* During 'DECEL': '<S232>:3' */
        if ((localSum_l > (-InM_mfAirTranToStabThd)) && (localSum_l <=
             InM_mfAirStabToTranThd)) {
          /* Transition: '<S232>:6' */
          /* Exit 'DECEL': '<S232>:3' */
          /* Entry 'STEADY': '<S232>:1' */
          InMdlT_DWork.is_c3_InMdlT = IN_STEADY;
          InM_stTranLd_SF = Ext_stStabTranLd_SC;
          InM_bAcceEng_SF = TRUE;
        } else {
          if (localSum_l > InM_mfAirStabToTranThd) {
            /* Transition: '<S232>:9' */
            /* Exit 'DECEL': '<S232>:3' */
            /* Entry 'ACCEL': '<S232>:2' */
            InMdlT_DWork.is_c3_InMdlT = IN_ACCEL;
            InM_stTranLd_SF = Ext_stAcceTranLd_SC;
            InM_bAcceEng_SF = TRUE;
          }
        }
        break;

       case IN_STEADY:
        /* During 'STEADY': '<S232>:1' */
        if (localSum_l < (-InM_mfAirStabToTranThd)) {
          /* Transition: '<S232>:8' */
          /* Exit 'STEADY': '<S232>:1' */
          /* Entry 'DECEL': '<S232>:3' */
          InMdlT_DWork.is_c3_InMdlT = IN_DECEL;
          InM_stTranLd_SF = Ext_stDeceTranLd_SC;
          InM_bAcceEng_SF = FALSE;
        } else {
          if (localSum_l > InM_mfAirStabToTranThd) {
            /* Transition: '<S232>:5' */
            /* Exit 'STEADY': '<S232>:1' */
            /* Entry 'ACCEL': '<S232>:2' */
            InMdlT_DWork.is_c3_InMdlT = IN_ACCEL;
            InM_stTranLd_SF = Ext_stAcceTranLd_SC;
            InM_bAcceEng_SF = TRUE;
          }
        }
        break;

       default:
        /* Transition: '<S232>:4' */
        /* Entry 'STEADY': '<S232>:1' */
        InMdlT_DWork.is_c3_InMdlT = IN_STEADY;
        InM_stTranLd_SF = Ext_stStabTranLd_SC;
        InM_bAcceEng_SF = TRUE;
        break;
      }
    }

    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Byp_Fonction_SC'
     *  Constant: '<S233>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge1 = InM_bAcceEng_B;
    } else {
      localMerge1 = InM_bAcceEng_SF;
    }

    /* Switch: '<S234>/Switch' incorporates:
     *  Constant: '<S234>/Byp_Fonction_SC'
     *  Constant: '<S234>/Int_BypC'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge = InM_stTranLd_B;
    } else {
      localMerge = InM_stTranLd_SF;
    }

    /* Switch: '<S235>/Switch' incorporates:
     *  Constant: '<S235>/Byp_Fonction_SC'
     *  Constant: '<S235>/Int_BypC'
     *  DataTypeConversion: '<S235>/Data Type Conversion'
     */
    if (INMDLT_ACTIVE_BYP_C) {
      localMerge2_b = InM_mfAirDifIn_B;
    } else {
      localtmp = localSum_l;
      localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 15);
      if (localtmp < 32768.0F) {
        if (localtmp >= -32768.0F) {
          localMerge2_b = (SInt16)localtmp;
        } else {
          localMerge2_b = MIN_int16_T;
        }
      } else {
        localMerge2_b = MAX_int16_T;
      }
    }
  }

  /* end of Outputs for SubSystem: '<S51>/F01_Engine_running' */

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_bAcceEngInport2' */
  Rte_Write_P_InM_bAcceEng_InM_bAcceEng(localMerge1);

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_mfAirDifInInport2' */
  Rte_Write_P_InM_mfAirDifIn_InM_mfAirDifIn(localMerge2_b);

  /* SignalConversion: '<S51>/TmpSignal ConversionAtInM_stTranLdInport2' */
  Rte_Write_P_InM_stTranLd_InM_stTranLd(localMerge);
}

/* Start for exported function: RE_InMdlT_040_MSE */
void RE_InMdlT_040_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F07_1_IntkEstimMnfldP_initialization'
   *
   * Block requirements for '<S1>/INM1_F07_1_IntkEstimMnfldP_initialization':
   *  1. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_023.01 ;
   *  2. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_024.01 ;
   *  3. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_025.01 ;
   *  4. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_360.01 ;
   *  5. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  6. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  7. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  8. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_197.01 ;
   *  9. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_196.01 ;
   *  10. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_293.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_040_MSE */
void RE_InMdlT_040_MSE(void)
{
  UInt16 localInM_tiInvEigVal_pDsThr;
  UInt8 localSwitch_i3;
  UInt32 localSwitch_jl;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F07_1_IntkEstimMnfldP_initialization'
   *
   * Block requirements for '<S1>/INM1_F07_1_IntkEstimMnfldP_initialization':
   *  1. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_023.01 ;
   *  2. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_024.01 ;
   *  3. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_025.01 ;
   *  4. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_360.01 ;
   *  5. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  6. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  7. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  8. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_197.01 ;
   *  9. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_196.01 ;
   *  10. SubSystem "INM1_F07_1_IntkEstimMnfldP_initialization" !Trace_To : VEMS_R_11_01067_293.02 ;
   */

  /* SignalConversion: '<S238>/copy' incorporates:
   *  Constant: '<S52>/Constant2'
   */
  InM_pGradDsThrEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S238>/autosar_testpoint1' */

  /* S-Function Block: <S238>/autosar_testpoint1 */

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_pGradDsThrEstim_irvInport2' incorporates:
   *  Constant: '<S52>/Constant2'
   *  SignalConversion: '<S52>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_InMdlT_040_MSE_InM_pGradDsThrEstim_irv(0.0F);

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/Byp_Fonction_SC'
   *  Constant: '<S241>/Int_BypC'
   *  Constant: '<S52>/Constant3'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localInM_tiInvEigVal_pDsThr = InM_tiInvEigVal_pDsThr_B;
  } else {
    localInM_tiInvEigVal_pDsThr = 10U;
  }

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_tiInvEigVal_pDsThrInport2' */
  Rte_Write_P_InM_tiInvEigVal_pDsThr_InM_tiInvEigVal_pDsThr
    (localInM_tiInvEigVal_pDsThr);

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Byp_Fonction_SC'
   *  Constant: '<S242>/Int_BypC'
   *  Constant: '<S52>/Constant1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_i3 = InM_tiRelax_pDsThrEstim_B;
  } else {
    localSwitch_i3 = 0U;
  }

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_tiRelax_pDsThrEstimInport2' */
  Rte_Write_P_InM_tiRelax_pDsThrEstim_InM_tiRelax_pDsThrEstim(localSwitch_i3);

  /* SignalConversion: '<S237>/copy' incorporates:
   *  Constant: '<S52>/Constant'
   */
  InM_pDsThrEstimPrev_IRV_MP = 1.0E+005F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S237>/autosar_testpoint1' */

  /* S-Function Block: <S237>/autosar_testpoint1 */

  /* SignalConversion: '<S239>/copy' incorporates:
   *  Constant: '<S52>/Constant'
   */
  InM_pDsThrEstimLoResl_IRV_MP = 1.0E+005F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S239>/autosar_testpoint1' */

  /* S-Function Block: <S239>/autosar_testpoint1 */

  /* Switch: '<S240>/Switch' incorporates:
   *  Constant: '<S236>/offset'
   *  Constant: '<S236>/offset1'
   *  Constant: '<S236>/one_on_slope'
   *  Constant: '<S240>/Byp_Fonction_SC'
   *  Constant: '<S240>/Int_BypC'
   *  Constant: '<S52>/Constant'
   *  DataTypeConversion: '<S236>/OutDTConv'
   *  Product: '<S236>/Product4'
   *  Sum: '<S236>/Add1'
   *  Sum: '<S236>/Add2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_jl = InM_pDsThrEstim_B;
  } else {
    localSwitch_jl = 12800000U;
  }

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_pDsThrEstimInport2' */
  Rte_Write_P_InM_pDsThrEstim_InM_pDsThrEstim(localSwitch_jl);

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_pDsThrEstimLoResl_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_040_MSE_InM_pDsThrEstimLoResl_irv(1.0E+005F);

  /* SignalConversion: '<S52>/TmpSignal ConversionAtInM_pDsThrEstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_040_MSE_InM_pDsThrEstimPrev_irv(1.0E+005F);
}

/* Start for exported function: RE_InMdlT_006_TEV */
void RE_InMdlT_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM1_F07_2_IntkEstimMnfldP_computation'
   *
   * Block requirements for '<S1>/INM1_F07_2_IntkEstimMnfldP_computation':
   *  1. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_023.01 ;
   *  2. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_024.01 ;
   *  3. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_026.01 ;
   *  4. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_332.03 ;
   *  5. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  7. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  8. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  9. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_197.01 ;
   *  10. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_196.01 ;
   *  11. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  12. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  13. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  14. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  15. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  16. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  17. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  18. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  19. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_369.01 ;
   *  20. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  21. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_207.01 ;
   *  22. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_206.01 ;
   *  23. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_205.01 ;
   *  24. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  25. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_149.01 ;
   *  26. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  27. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_204.01 ;
   *  28. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_203.01 ;
   *  29. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  30. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_193.01 ;
   *  31. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  32. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_209.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_006_TEV */
void RE_InMdlT_006_TEV(void)
{
  /* local block i/o variables */
  Float32 localDivide_l;
  Float32 localDataTypeConversion8_h;
  Float32 localDataTypeConversion12_a;
  Float32 localMinMax_k;
  UInt16 localDivide_pl;
  UInt8 localLookUpTable_f3;
  Boolean localRelationalOperator_e;
  Float32 localInM_pGradDsThrEstim_irv_f;
  UInt16 localTmpSignalConversionAtExt_n;
  Float32 localLookupTablenD;
  Float32 localDataTypeConversion2_e;
  Float32 localDivide_k2;
  Boolean localTmpSignalConversionAtIn_mc;
  Boolean localTmpSignalConversionAtEGR_j;
  UInt16 localTmpSignalConversionAtUsT_b;
  UInt8 localTmpSignalConversionAtUsT_l;
  UInt16 localTmpSignalConversionAtInM_c;
  UInt16 localTmpSignalConversionAtInT_o;
  UInt16 localTmpSignalConversionAtIn_ot;
  UInt16 localTmpSignalConversionAtInM_b;
  UInt16 localTmpSignalConversionAtInM_a;
  UInt16 localTmpSignalConversionAtUsT_f;
  UInt16 localTmpSignalConversionAtInT_h;
  UInt16 localTmpSignalConversionAtInT_c;
  UInt16 localTmpSignalConversionAtInT_f;
  UInt16 localTmpSignalConversionAtInT_n;
  UInt8 localTmpSignalConversionAtInT_a;
  SInt32 localTmpSignalConversionAtBlby_;
  UInt32 localTmpSignalConversionAtInM_o;
  UInt16 localTmpSignalConversionAtUsT_n;
  SInt16 localTmpSignalConversionAtEng_t;
  Float32 localInM_pDsThrEstimLoResl_irv_;
  Float32 localInM_pDsThrEstimPrev_irv_d;
  UInt16 locallocalTmpSignalConversionAt;
  UInt8 locallocalTmpSignalConversion_0;
  UInt32 localtmp;

  /* S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM1_F07_2_IntkEstimMnfldP_computation'
   *
   * Block requirements for '<S1>/INM1_F07_2_IntkEstimMnfldP_computation':
   *  1. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_023.01 ;
   *  2. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_024.01 ;
   *  3. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_026.01 ;
   *  4. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_332.03 ;
   *  5. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  6. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_195.01 ;
   *  7. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  8. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  9. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_197.01 ;
   *  10. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_196.01 ;
   *  11. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  12. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  13. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  14. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  15. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  16. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  17. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_281.02 ;
   *  18. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  19. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_369.01 ;
   *  20. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  21. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_207.01 ;
   *  22. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_206.01 ;
   *  23. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_205.01 ;
   *  24. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  25. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_149.01 ;
   *  26. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  27. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_204.01 ;
   *  28. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_203.01 ;
   *  29. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  30. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_193.01 ;
   *  31. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  32. SubSystem "INM1_F07_2_IntkEstimMnfldP_computation" !Trace_To : VEMS_R_11_01067_209.01 ;
   */

  /* SignalConversion: '<S53>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&localTmpSignalConversionAtUsT_b);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&locallocalTmpSignalConversion_0);

  /* RelationalOperator: '<S53>/Relational Operator' incorporates:
   *  Constant: '<S53>/Ext_stRun_SC'
   */
  localRelationalOperator_e = (locallocalTmpSignalConversion_0 == Ext_stRun_SC);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&localTmpSignalConversionAtUsT_n);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsT_f);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_arEffAdpThrOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpThr_INPUT'
   */
  Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr(&localTmpSignalConversionAtInM_c);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_facCfeGradThr_irvOutport2' incorporates:
   *  Inport: '<Root>/InM_facCfeGradThr_INPUT'
   */
  Rte_Read_R_InM_facCfeGradThr_InM_facCfeGradThr
    (&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&localTmpSignalConversionAtUsT_l);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_mfTotCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfTotCanPurgEstim_INPUT'
   */
  Rte_Read_R_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim
    (&localTmpSignalConversionAtInM_b);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_mfAirThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&localTmpSignalConversionAtIn_ot);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_facHeatExcWallInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_facHeatExcWallInMnf'
   */
  Rte_Read_R_InThM_facHeatExcWallInMnf_InThM_facHeatExcWallInMnf
    (&localTmpSignalConversionAtInT_a);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_tWallInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tWallInMnf'
   */
  Rte_Read_R_InThM_tWallInMnf_InThM_tWallInMnf(&localTmpSignalConversionAtInT_f);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_tMixtInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tMixtInMnf'
   */
  Rte_Read_R_InThM_tMixtInMnf_InThM_tMixtInMnf(&localTmpSignalConversionAtInT_n);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_tInMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tInMnfEstim'
   */
  Rte_Read_R_InThM_tInMnfEstim_InThM_tInMnfEstim
    (&localTmpSignalConversionAtInT_c);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_bAcceEngOutport2' incorporates:
   *  Inport: '<Root>/InM_bAcceEng_INPUT'
   */
  Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&localTmpSignalConversionAtIn_mc);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtEGRVlv_bClnEGRFoulOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bClnEGRFoul'
   */
  Rte_Read_R_EGRVlv_bClnEGRFoul_EGRVlv_bClnEGRFoul
    (&localTmpSignalConversionAtEGR_j);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv_INPUT'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtInM_a);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_tEGRInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tEGRInMnf'
   */
  Rte_Read_R_InThM_tEGRInMnf_InThM_tEGRInMnf(&localTmpSignalConversionAtInT_h);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInT_o);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_pPrevDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim(&localTmpSignalConversionAtInM_o);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtBlby_mfFuStmCmpAirSysOutport2' incorporates:
   *  Inport: '<Root>/Blby_mfFuStmCmpAirSys'
   */
  Rte_Read_R_Blby_mfFuStmCmpAirSys_Blby_mfFuStmCmpAirSys
    (&localTmpSignalConversionAtBlby_);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtEng_tOilEstimOutport2' incorporates:
   *  Inport: '<Root>/Eng_tOilEstim'
   */
  Rte_Read_R_Eng_tOilEstim_Eng_tOilEstim(&localTmpSignalConversionAtEng_t);

  /* If: '<S53>/If' incorporates:
   *  ActionPort: '<S243>/Action Port'
   *  ActionPort: '<S244>/Action Port'
   *  SubSystem: '<S53>/F00_Reset_manifold_state'
   *  SubSystem: '<S53>/F01_Calc_estimated_pressure'
   *
   * Block requirements for '<S53>/F00_Reset_manifold_state':
   *  1. SubSystem "F00_Reset_manifold_state" !Trace_To : VEMS_R_11_01067_027.01 ;
   *
   * Block requirements for '<S53>/F01_Calc_estimated_pressure':
   *  1. SubSystem "F01_Calc_estimated_pressure" !Trace_To : VEMS_R_11_01067_028.01 ;
   */
  if (localRelationalOperator_e) {
    /* Outputs for atomic SubSystem: '<S244>/F01_Calc_eigenvalues' *
     * Block requirements for '<S244>/F01_Calc_eigenvalues':
     *  1. SubSystem "F01_Calc_eigenvalues" !Trace_To : VEMS_R_11_01067_029.01 ;
     */

    /* Product: '<S264>/Divide' incorporates:
     *  DataTypeConversion: '<S251>/Data Type Conversion12'
     *  DataTypeConversion: '<S251>/Data Type Conversion3'
     *  DataTypeConversion: '<S251>/Data Type Conversion4'
     *  Product: '<S258>/Divide'
     */
    localInM_pGradDsThrEstim_irv_f = (((((Float32)
      locallocalTmpSignalConversionAt) * 0.00048828125F) - 3.199951172E+001F) *
                                      (((Float32)
      localTmpSignalConversionAtInM_c) * 5.960464478E-008F)) * (((Float32)
      localTmpSignalConversionAtUsT_l) * 0.125F);

    /* DataStoreWrite: '<S251>/Data Store Write2' incorporates:
     *  Constant: '<S256>/offset'
     *  Constant: '<S256>/offset1'
     *  Constant: '<S256>/one_on_slope'
     *  DataTypeConversion: '<S256>/OutDTConv'
     *  Product: '<S256>/Product4'
     *  Sum: '<S256>/Add1'
     *  Sum: '<S256>/Add2'
     */
    localDivide_k2 = ((localInM_pGradDsThrEstim_irv_f - -6.249904633E-002F) *
                      1.048576E+006F) + 0.5F;
    if (localDivide_k2 >= 0.0F) {
      InM_facMfThr_MP = (UInt16)localDivide_k2;
    } else {
      InM_facMfThr_MP = 0U;
    }

    /* Switch: '<S251>/Switch' incorporates:
     *  Constant: '<S251>/InM_facKK1Acc_C'
     *  Constant: '<S251>/InM_facKK1Dec_C'
     */
    if (localTmpSignalConversionAtIn_mc) {
      localTmpSignalConversionAtInM_c = InM_facKK1Acc_C;
    } else {
      localTmpSignalConversionAtInM_c = InM_facKK1Dec_C;
    }

    /* DataTypeConversion: '<S255>/OutDTConv' incorporates:
     *  Constant: '<S251>/Eng_mRef_C'
     *  Constant: '<S251>/Ext_noCylEng_SC'
     *  Constant: '<S251>/Ext_noCylRev_SC'
     *  Constant: '<S255>/offset'
     *  Constant: '<S255>/offset1'
     *  Constant: '<S255>/one_on_slope'
     *  DataTypeConversion: '<S251>/Data Type Conversion10'
     *  DataTypeConversion: '<S251>/Data Type Conversion2'
     *  DataTypeConversion: '<S251>/Data Type Conversion5'
     *  DataTypeConversion: '<S251>/Data Type Conversion6'
     *  DataTypeConversion: '<S251>/Data Type Conversion7'
     *  DataTypeConversion: '<S251>/Data Type Conversion8'
     *  Product: '<S255>/Product4'
     *  Product: '<S257>/Divide'
     *  Product: '<S259>/Divide'
     *  Product: '<S260>/Divide'
     *  Product: '<S261>/Divide'
     *  Product: '<S262>/Divide'
     *  Product: '<S263>/Divide'
     *  SignalConversion: '<S53>/TmpSignal ConversionAtInM_facSlopEfcEstim_irvOutport2'
     *  Sum: '<S251>/Sum'
     *  Sum: '<S255>/Add1'
     *  Sum: '<S255>/Add2'
     */
    localDivide_k2 = ((((((((((Float32)localTmpSignalConversionAtInT_o) *
      0.0078125F) + 223.0F) * (((Float32)Ext_noCylEng_SC) / ((Float32)
      Ext_noCylRev_SC))) * ((Float32)localTmpSignalConversionAtExt_n)) *
                         Rte_IrvRead_RE_InMdlT_006_TEV_InM_facSlopEfcEstim_irv())
                        * (((Float32)Eng_mRef_C) * 1.192016583E-007F)) -
                       localInM_pGradDsThrEstim_irv_f) * (((Float32)
      localTmpSignalConversionAtInM_c) * 16.0F)) + 0.5F;
    if (localDivide_k2 < 65536.0F) {
      if (localDivide_k2 >= 0.0F) {
        locallocalTmpSignalConversionAt = (UInt16)localDivide_k2;
      } else {
        locallocalTmpSignalConversionAt = 0U;
      }
    } else {
      locallocalTmpSignalConversionAt = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S244>/F01_Calc_eigenvalues' */

    /* Outputs for atomic SubSystem: '<S244>/F02_Calc_relaxation_term' *
     * Block requirements for '<S244>/F02_Calc_relaxation_term':
     *  1. SubSystem "F02_Calc_relaxation_term" !Trace_To : VEMS_R_11_01067_030.01 ;
     */

    /* Product: '<S268>/Divide' incorporates:
     *  Constant: '<S252>/InM_tiSampleFast_SC'
     */
    localtmp = ((((UInt32)locallocalTmpSignalConversionAt) * ((UInt32)
      InM_tiSampleFast_SC)) >> 1);
    if (localtmp > 65535U) {
      localTmpSignalConversionAtUsT_b = MAX_uint16_T;
    } else {
      localTmpSignalConversionAtUsT_b = (UInt16)localtmp;
    }

    localtmp = (UInt32)((SInt32)(((UInt32)(localTmpSignalConversionAtUsT_b *
      16777)) >> 14));
    if (localtmp > 65535U) {
      localDivide_pl = MAX_uint16_T;
    } else {
      localDivide_pl = (UInt16)localtmp;
    }

    /* Lookup: '<S265>/Look-Up Table'
     * About '<S265>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_f3), (&(InM_facRelax_T[0])),
                  localDivide_pl, (&(InM_facRelax_A[0])), 29U);

    /* DataTypeDuplicate Block: '<S265>/Data Type Duplicate1'
     *
     * Regarding '<S265>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S266>/OutDTConv' incorporates:
     *  Constant: '<S252>/InM_tiSampleFast_SC1'
     *  Constant: '<S266>/offset'
     *  Constant: '<S266>/offset1'
     *  Constant: '<S266>/one_on_slope'
     *  DataTypeConversion: '<S252>/Data Type Conversion1'
     *  DataTypeConversion: '<S252>/Data Type Conversion12'
     *  Lookup: '<S265>/Look-Up Table'
     *  Product: '<S266>/Product4'
     *  Product: '<S267>/Divide'
     *  Sum: '<S266>/Add1'
     *  Sum: '<S266>/Add2'
     */
    localDivide_k2 = (((((Float32)localLookUpTable_f3) * 0.00390625F) *
                       (((Float32)InM_tiSampleFast_SC) * 5.000000237E-004F)) *
                      16384.0F) + 0.5F;
    if (localDivide_k2 < 256.0F) {
      locallocalTmpSignalConversion_0 = (UInt8)localDivide_k2;
    } else {
      locallocalTmpSignalConversion_0 = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S244>/F02_Calc_relaxation_term' */

    /* Outputs for atomic SubSystem: '<S244>/F03_diff_pressure' *
     * Block requirements for '<S244>/F03_diff_pressure':
     *  1. SubSystem "F03_diff_pressure" !Trace_To : VEMS_R_11_01067_031.01 ;
     */

    /* DataTypeConversion: '<S253>/Data Type Conversion12' */
    localInM_pGradDsThrEstim_irv_f = ((Float32)localTmpSignalConversionAtInM_a)
      * 1.525878906E-005F;

    /* Switch: '<S253>/Switch5' incorporates:
     *  Constant: '<S253>/Constant1'
     */
    if (localTmpSignalConversionAtEGR_j) {
      localLookupTablenD = localInM_pGradDsThrEstim_irv_f;
    } else {
      localLookupTablenD = 0.0F;
    }

    /* Sum: '<S253>/Sum1' incorporates:
     *  DataTypeConversion: '<S253>/Data Type Conversion1'
     *  DataTypeConversion: '<S253>/Data Type Conversion5'
     */
    localLookupTablenD += (((Float32)localTmpSignalConversionAtIn_ot) *
      1.525878906E-005F) + (((Float32)localTmpSignalConversionAtInM_b) *
      9.536743164E-007F);

    /* DataStoreWrite: '<S253>/Data Store Write1' incorporates:
     *  Constant: '<S271>/offset'
     *  Constant: '<S271>/offset1'
     *  Constant: '<S271>/one_on_slope'
     *  DataTypeConversion: '<S271>/OutDTConv'
     *  Product: '<S271>/Product4'
     *  Sum: '<S271>/Add1'
     *  Sum: '<S271>/Add2'
     */
    localDivide_k2 = (65536.0F * localLookupTablenD) + 0.5F;
    if (localDivide_k2 < 65536.0F) {
      InM_mfSel_MP = (UInt16)localDivide_k2;
    } else {
      InM_mfSel_MP = MAX_uint16_T;
    }

    /* Switch: '<S253>/Switch' incorporates:
     *  Constant: '<S253>/InM_facKK1Acc_C'
     *  Constant: '<S253>/InM_facKK1Dec_C'
     */
    if (localTmpSignalConversionAtIn_mc) {
      localTmpSignalConversionAtInM_c = InM_facKK1Acc_C;
    } else {
      localTmpSignalConversionAtInM_c = InM_facKK1Dec_C;
    }

    /* DataTypeConversion: '<S253>/Data Type Conversion2' */
    localDataTypeConversion2_e = ((Float32)localTmpSignalConversionAtInM_c) *
      16.0F;

    /* DataStoreWrite: '<S253>/Data Store Write2' incorporates:
     *  Constant: '<S270>/offset'
     *  Constant: '<S270>/offset1'
     *  Constant: '<S270>/one_on_slope'
     *  DataTypeConversion: '<S270>/OutDTConv'
     *  Product: '<S270>/Product4'
     *  Sum: '<S270>/Add1'
     *  Sum: '<S270>/Add2'
     */
    localDivide_k2 = (256.0F * localDataTypeConversion2_e) + 0.5F;
    if (localDivide_k2 < 256.0F) {
      InM_facKK1_MP = (UInt8)localDivide_k2;
    } else {
      InM_facKK1_MP = MAX_uint8_T;
    }

    /* Product: '<S273>/Divide' incorporates:
     *  DataTypeConversion: '<S253>/Data Type Conversion4'
     */
    localDivide_k2 = ((((Float32)localTmpSignalConversionAtUsT_f) * 0.0078125F)
                      + 223.0F) * localLookupTablenD;

    /* Product: '<S274>/Divide' */
    localInM_pDsThrEstimLoResl_irv_ = (Float32)((ACTEMS_LdexpF((Float32d)
      localTmpSignalConversionAtInT_h, -5) + 223.0F) * ((Float32d)
      localInM_pGradDsThrEstim_irv_f));

    /* Switch: '<S253>/Switch6' incorporates:
     *  Constant: '<S253>/Constant9'
     */
    if (localTmpSignalConversionAtEGR_j) {
      localInM_pDsThrEstimLoResl_irv_ = 0.0F;
    }

    /* DataTypeConversion: '<S253>/Data Type Conversion6' incorporates:
     *  SignalConversion: '<S53>/TmpSignal ConversionAtInM_mfTotExEstim_irvOutport2'
     */
    localLookupTablenD = ((Float32)
                          Rte_IrvRead_RE_InMdlT_006_TEV_InM_mfTotExEstim_irv()) *
      1.525878906E-005F;

    /* Product: '<S275>/Divide' incorporates:
     *  DataTypeConversion: '<S253>/Data Type Conversion7'
     */
    localInM_pDsThrEstimPrev_irv_d = ((((Float32)
      localTmpSignalConversionAtInT_c) * 0.0078125F) + 223.0F) *
      localLookupTablenD;

    /* Product: '<S276>/Divide' incorporates:
     *  DataTypeConversion: '<S253>/Data Type Conversion10'
     *  DataTypeConversion: '<S253>/Data Type Conversion9'
     *  Sum: '<S253>/Sum2'
     */
    localInM_pGradDsThrEstim_irv_f = (((((Float32)
      localTmpSignalConversionAtInT_f) * 0.0078125F) + 223.0F) - ((((Float32)
      localTmpSignalConversionAtInT_n) * 0.0078125F) + 223.0F)) *
      localLookupTablenD;

    /* Switch: '<S253>/Switch1' incorporates:
     *  Constant: '<S253>/Constant5'
     *  Constant: '<S253>/InM_bInhHeatTrf_C'
     *  DataTypeConversion: '<S253>/Data Type Conversion11'
     */
    if (InM_bInhHeatTrf_C) {
      localLookupTablenD = 0.0F;
    } else {
      localLookupTablenD = ((Float32)localTmpSignalConversionAtInT_a) *
        0.00390625F;
    }

    /* Product: '<S277>/Divide' */
    localInM_pGradDsThrEstim_irv_f *= localLookupTablenD;

    /* Product: '<S278>/Divide' incorporates:
     *  DataTypeConversion: '<S253>/Data Type Conversion3'
     *  Lookup_n-D: '<S269>/Lookup Table (n-D)'
     *  Product: '<S279>/Divide'
     *  Sum: '<S253>/Sum3'
     */
    localDivide_l = ((((localDivide_k2 + localInM_pDsThrEstimLoResl_irv_) -
                       localInM_pDsThrEstimPrev_irv_d) +
                      localInM_pGradDsThrEstim_irv_f) + ((((Float32)
      localTmpSignalConversionAtBlby_) * 1.192092896E-007F) *
      look1_is16lftu16n7If_binlcns(localTmpSignalConversionAtEng_t,
      (&(InM_tOilEstim_A[0])), (&(InM_tOilEstim_T[0])), 7U))) *
      localDataTypeConversion2_e;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S272>/autosar_testpoint1' */

    /* S-Function Block: <S272>/autosar_testpoint1 */
    InM_pGradDsThrEstim_IRV_MP = localDivide_l;

    /* end of Outputs for SubSystem: '<S244>/F03_diff_pressure' */

    /* Outputs for atomic SubSystem: '<S244>/F04_Calc_pressure_integration' *
     * Block requirements for '<S244>/F04_Calc_pressure_integration':
     *  1. SubSystem "F04_Calc_pressure_integration" !Trace_To : VEMS_R_11_01067_032.01 ;
     */

    /* DataTypeConversion: '<S254>/Data Type Conversion12' */
    localDataTypeConversion12_a = ((Float32)localTmpSignalConversionAtInM_o) *
      0.0078125F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S281>/autosar_testpoint1' */

    /* S-Function Block: <S281>/autosar_testpoint1 */
    InM_pDsThrEstimPrev_IRV_MP = localDataTypeConversion12_a;

    /* Sum: '<S254>/Sum' incorporates:
     *  DataTypeConversion: '<S254>/Data Type Conversion5'
     *  Product: '<S283>/Divide'
     */
    localMinMax_k = ((((Float32)locallocalTmpSignalConversion_0) *
                      6.103515625E-005F) * localDivide_l) +
      localDataTypeConversion12_a;

    /* DataTypeConversion: '<S254>/Data Type Conversion2' */
    localInM_pGradDsThrEstim_irv_f = ((Float32)localTmpSignalConversionAtUsT_n)
      * 8.0F;

    /* MinMax: '<S254>/MinMax' */
    localMinMax_k = rt_MINf(localMinMax_k, localInM_pGradDsThrEstim_irv_f);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S282>/autosar_testpoint1' */

    /* S-Function Block: <S282>/autosar_testpoint1 */
    InM_pDsThrEstimLoResl_IRV_MP = localMinMax_k;

    /* SignalConversion: '<S254>/Signal Conversion3' */
    localInM_pDsThrEstimLoResl_irv_ = localMinMax_k;

    /* SignalConversion: '<S254>/Signal Conversion4' */
    localInM_pDsThrEstimPrev_irv_d = localDataTypeConversion12_a;

    /* DataTypeConversion: '<S280>/OutDTConv' incorporates:
     *  Constant: '<S280>/offset'
     *  Constant: '<S280>/offset1'
     *  Constant: '<S280>/one_on_slope'
     *  Product: '<S280>/Product4'
     *  Sum: '<S280>/Add1'
     *  Sum: '<S280>/Add2'
     */
    localDivide_k2 = (128.0F * localMinMax_k) + 0.5F;
    if (localDivide_k2 < 4.294967296E+009F) {
      if (localDivide_k2 >= 0.0F) {
        localTmpSignalConversionAtInM_o = (UInt32)localDivide_k2;
      } else {
        localTmpSignalConversionAtInM_o = 0U;
      }
    } else {
      localTmpSignalConversionAtInM_o = MAX_uint32_T;
    }

    /* end of Outputs for SubSystem: '<S244>/F04_Calc_pressure_integration' */

    /* SignalConversion: '<S244>/Signal Conversion1' */
    localInM_pGradDsThrEstim_irv_f = localDivide_l;
  } else {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S249>/autosar_testpoint1' incorporates:
     *  Constant: '<S243>/Constant2'
     */
    /* S-Function Block: <S249>/autosar_testpoint1 */
    InM_pGradDsThrEstim_IRV_MP = 0.0F;

    /* SignalConversion: '<S243>/Signal Conversion5' incorporates:
     *  Constant: '<S243>/Constant2'
     */
    localInM_pGradDsThrEstim_irv_f = 0.0F;

    /* Constant: '<S243>/Constant3' */
    locallocalTmpSignalConversionAt = 10U;

    /* Constant: '<S243>/Constant1' */
    locallocalTmpSignalConversion_0 = 0U;

    /* DataTypeConversion: '<S243>/Data Type Conversion8' */
    localDataTypeConversion8_h = ((Float32)localTmpSignalConversionAtUsT_b) *
      8.0F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S248>/autosar_testpoint1' */

    /* S-Function Block: <S248>/autosar_testpoint1 */
    InM_pDsThrEstimPrev_IRV_MP = localDataTypeConversion8_h;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S250>/autosar_testpoint1' */

    /* S-Function Block: <S250>/autosar_testpoint1 */
    InM_pDsThrEstimLoResl_IRV_MP = localDataTypeConversion8_h;

    /* SignalConversion: '<S243>/Signal Conversion' incorporates:
     *  DataTypeConversion: '<S243>/Data Type Conversion1'
     */
    localTmpSignalConversionAtInM_o = (UInt32)(localTmpSignalConversionAtUsT_b
      << 10);

    /* SignalConversion: '<S243>/Signal Conversion2' */
    localInM_pDsThrEstimLoResl_irv_ = localDataTypeConversion8_h;

    /* SignalConversion: '<S243>/Signal Conversion6' */
    localInM_pDsThrEstimPrev_irv_d = localDataTypeConversion8_h;
  }

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S245>/Byp_Fonction_SC'
   *  Constant: '<S245>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInM_o = InM_pDsThrEstim_B;
  }

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_pDsThrEstimInport2' */
  Rte_Write_P_InM_pDsThrEstim_InM_pDsThrEstim(localTmpSignalConversionAtInM_o);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_pDsThrEstimLoResl_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_006_TEV_InM_pDsThrEstimLoResl_irv
    (localInM_pDsThrEstimLoResl_irv_);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_pDsThrEstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_006_TEV_InM_pDsThrEstimPrev_irv
    (localInM_pDsThrEstimPrev_irv_d);

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_pGradDsThrEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_006_TEV_InM_pGradDsThrEstim_irv
    (localInM_pGradDsThrEstim_irv_f);

  /* Switch: '<S246>/Switch' incorporates:
   *  Constant: '<S246>/Byp_Fonction_SC'
   *  Constant: '<S246>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = InM_tiInvEigVal_pDsThr_B;
  }

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_tiInvEigVal_pDsThrInport2' */
  Rte_Write_P_InM_tiInvEigVal_pDsThr_InM_tiInvEigVal_pDsThr
    (locallocalTmpSignalConversionAt);

  /* Switch: '<S247>/Switch' incorporates:
   *  Constant: '<S247>/Byp_Fonction_SC'
   *  Constant: '<S247>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversion_0 = InM_tiRelax_pDsThrEstim_B;
  }

  /* SignalConversion: '<S53>/TmpSignal ConversionAtInM_tiRelax_pDsThrEstimInport2' */
  Rte_Write_P_InM_tiRelax_pDsThrEstim_InM_tiRelax_pDsThrEstim
    (locallocalTmpSignalConversion_0);
}

/* Start for exported function: RE_InMdlT_042_MSE */
void RE_InMdlT_042_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F02_1_InEstimMnfFu_initialization'
   *
   * Block requirements for '<S1>/INM2_F02_1_InEstimMnfFu_initialization':
   *  1. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_045.01 ;
   *  2. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_044.01 ;
   *  3. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_043.01 ;
   *  4. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_362.01 ;
   *  5. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  6. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  7. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_324.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_042_MSE */
void RE_InMdlT_042_MSE(void)
{
  /* S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F02_1_InEstimMnfFu_initialization'
   *
   * Block requirements for '<S1>/INM2_F02_1_InEstimMnfFu_initialization':
   *  1. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_045.01 ;
   *  2. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_044.01 ;
   *  3. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_043.01 ;
   *  4. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_362.01 ;
   *  5. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  6. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  7. SubSystem "INM2_F02_1_InEstimMnfFu_initialization" !Trace_To : VEMS_R_11_01067_324.02 ;
   */

  /* SignalConversion: '<S317>/copy' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  InM_mFuStmEstimPrev_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S317>/autosar_testpoint1' */

  /* S-Function Block: <S317>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/TmpSignal ConversionAtInM_mFuStmEstimPrev_irvInport2' incorporates:
   *  Constant: '<S56>/Constant1'
   *  SignalConversion: '<S56>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_042_MSE_InM_mFuStmEstimPrev_irv(0.0F);

  /* SignalConversion: '<S318>/copy' incorporates:
   *  Constant: '<S56>/Constant2'
   */
  InM_mGradFuStmEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S318>/autosar_testpoint1' */

  /* S-Function Block: <S318>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/TmpSignal ConversionAtInM_mGradFuStmEstim_irvInport2' incorporates:
   *  Constant: '<S56>/Constant2'
   *  SignalConversion: '<S56>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_InMdlT_042_MSE_InM_mGradFuStmEstim_irv(0.0F);

  /* SignalConversion: '<S319>/copy' incorporates:
   *  Constant: '<S56>/Constant'
   */
  InM_mFuStmEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S319>/autosar_testpoint1' */

  /* S-Function Block: <S319>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/TmpSignal ConversionAtInM_mFuStmEstim_irvInport2' incorporates:
   *  Constant: '<S56>/Constant'
   *  SignalConversion: '<S56>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_042_MSE_InM_mFuStmEstim_irv(0.0F);
}

/* Start for exported function: RE_InMdlT_028_TEV */
void RE_InMdlT_028_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S12>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F02_2_Calc_estimated_fuel_mass'
   *
   * Block requirements for '<S1>/INM2_F02_2_Calc_estimated_fuel_mass':
   *  1. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_043.01 ;
   *  2. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_044.01 ;
   *  3. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_046.01 ;
   *  4. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_346.02 ;
   *  5. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  6. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  7. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_324.02 ;
   *  8. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  9. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  10. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_223.01 ;
   *  11. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  12. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  13. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  14. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_280.01 ;
   *  15. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_320.02 ;
   */

  /* Start for ifaction SubSystem: '<S57>/F02_Estimation_fuel_mass' *
   * Block requirements for '<S57>/F02_Estimation_fuel_mass':
   *  1. SubSystem "F02_Estimation_fuel_mass" !Trace_To : VEMS_R_11_01067_048.01 ;
   */

  /* InitializeConditions for atomic SubSystem: '<S321>/F03_Calc_estimated_fuel_mass' *
   * Block requirements for '<S321>/F03_Calc_estimated_fuel_mass':
   *  1. SubSystem "F03_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_051.01 ;
   */

  /* InitializeConditions for Memory: '<S349>/Memory' */
  InMdlT_DWork.Memory_PreviousInput = TRUE;

  /* InitializeConditions for Memory: '<S337>/Memory' */
  InMdlT_DWork.Memory_PreviousInput_h = TRUE;

  /* end of InitializeConditions for SubSystem: '<S321>/F03_Calc_estimated_fuel_mass' */

  /* end of Start for SubSystem: '<S57>/F02_Estimation_fuel_mass' */
}

/* Output and update for exported function: RE_InMdlT_028_TEV */
void RE_InMdlT_028_TEV(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_ko;
  Float32 localDivide_iz;
  Float32 localMinMax_c;
  Boolean localLogic[2];
  Boolean localLogic_g[2];
  Boolean localMemory;
  Boolean localLogicalOperator3;
  Boolean localR;
  UInt8 localTmpSignalConversionAtEng_n;
  Boolean localRelationalOperator_ex;
  Float32 localInM_mGradFuStmEstim_irv_g;
  Boolean localRelationalOperator_bc;
  Float32 localSwitch1_p;
  Boolean localRelationalOperator2;
  Boolean localRelationalOperator1_d;
  Boolean localTmpSignalConversionAtCan_i;
  Boolean localTmpSignalConversionAtIn_px;
  SInt32 localTmpSignalConversionAtBlb_f;
  UInt8 localTmpSignalConversionAtInM_t;
  Float32 localInM_mFuStmEstimPrev_irv_i;
  Float32 localInM_mFuStmEstim_irv_f;

  /* S-Function (fcncallgen): '<S12>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F02_2_Calc_estimated_fuel_mass'
   *
   * Block requirements for '<S1>/INM2_F02_2_Calc_estimated_fuel_mass':
   *  1. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_043.01 ;
   *  2. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_044.01 ;
   *  3. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_046.01 ;
   *  4. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_346.02 ;
   *  5. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  6. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  7. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_324.02 ;
   *  8. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  9. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  10. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_223.01 ;
   *  11. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  12. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  13. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  14. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_280.01 ;
   *  15. SubSystem "INM2_F02_2_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_320.02 ;
   */

  /* SignalConversion: '<S57>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_n);

  /* RelationalOperator: '<S57>/Relational Operator' incorporates:
   *  Constant: '<S57>/Ext_stRun_SC'
   */
  localRelationalOperator_ex = (localTmpSignalConversionAtEng_n == Ext_stRun_SC);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_bAcceEngOutport2' incorporates:
   *  Inport: '<Root>/InM_bAcceEng_INPUT'
   */
  Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&localTmpSignalConversionAtIn_px);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_tiRelax_mTotEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_tiRelax_mTotEstim_INPUT'
   */
  Rte_Read_R_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim
    (&localTmpSignalConversionAtInM_t);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_mPrevFuStmEstimOutport2' */
  localTmpSignalConversionAtIn_ko =
    Rte_IrvRead_RE_InMdlT_028_TEV_InM_mFuStmEstim_irv();

  /* SignalConversion: '<S57>/TmpSignal ConversionAtCanPurg_bAcvClsPurgReqOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_bAcvClsPurgReq'
   */
  Rte_Read_R_CanPurg_bAcvClsPurgReq_CanPurg_bAcvClsPurgReq
    (&localTmpSignalConversionAtCan_i);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtBlby_mfFuStmCmpAirSysOutport2' incorporates:
   *  Inport: '<Root>/Blby_mfFuStmCmpAirSys'
   */
  Rte_Read_R_Blby_mfFuStmCmpAirSys_Blby_mfFuStmCmpAirSys
    (&localTmpSignalConversionAtBlb_f);

  /* If: '<S57>/If' incorporates:
   *  ActionPort: '<S320>/Action Port'
   *  ActionPort: '<S321>/Action Port'
   *  SubSystem: '<S57>/F01_Reset_fuel_mass'
   *  SubSystem: '<S57>/F02_Estimation_fuel_mass'
   *
   * Block requirements for '<S57>/F01_Reset_fuel_mass':
   *  1. SubSystem "F01_Reset_fuel_mass" !Trace_To : VEMS_R_11_01067_047.01 ;
   *
   * Block requirements for '<S57>/F02_Estimation_fuel_mass':
   *  1. SubSystem "F02_Estimation_fuel_mass" !Trace_To : VEMS_R_11_01067_048.01 ;
   */
  if (localRelationalOperator_ex) {
    /* DataTypeConversion: '<S321>/Data Type Conversion4' */
    localInM_mFuStmEstimPrev_irv_i = ((Float32)localTmpSignalConversionAtBlb_f)
      * 1.192092896E-007F;

    /* Outputs for atomic SubSystem: '<S321>/F01_calcul_fuel_term_relax' *
     * Block requirements for '<S321>/F01_calcul_fuel_term_relax':
     *  1. SubSystem "F01_calcul_fuel_term_relax" !Trace_To : VEMS_R_11_01067_049.01 ;
     */

    /* DataTypeConversion: '<S325>/Data Type Conversion1' */
    InM_tiRelax_mFuStmEstim = ((Float32)localTmpSignalConversionAtInM_t) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S321>/F01_calcul_fuel_term_relax' */

    /* Outputs for atomic SubSystem: '<S321>/F02_diff_fuel_mass' *
     * Block requirements for '<S321>/F02_diff_fuel_mass':
     *  1. SubSystem "F02_diff_fuel_mass" !Trace_To : VEMS_R_11_01067_050.01 ;
     */

    /* Switch: '<S326>/Switch' incorporates:
     *  Constant: '<S326>/Constant3'
     *  Constant: '<S326>/InM_rKk2_C'
     *  DataTypeConversion: '<S326>/Data Type Conversion4'
     */
    if (localTmpSignalConversionAtIn_px) {
      localInM_mGradFuStmEstim_irv_g = 1.0F;
    } else {
      localInM_mGradFuStmEstim_irv_g = ((Float32)InM_rKk2_C) * 0.00390625F;
    }

    /* Product: '<S329>/Divide' incorporates:
     *  DataTypeConversion: '<S326>/Data Type Conversion1'
     *  Product: '<S330>/Divide'
     *  SignalConversion: '<S57>/TmpSignal ConversionAtInM_concFuStmEstim_irvOutport2'
     *  SignalConversion: '<S57>/TmpSignal ConversionAtInM_mfFuStmCanPurgEstim_irvOutport2'
     *  SignalConversion: '<S57>/TmpSignal ConversionAtInM_mfTotExEstim_irvOutport2'
     *  Sum: '<S326>/Sum1'
     *  Sum: '<S326>/Sum2'
     */
    localDivide_iz = ((Rte_IrvRead_RE_InMdlT_028_TEV_InM_mfFuStmCanPurgEstim_irv
                       () - ((((Float32)
      Rte_IrvRead_RE_InMdlT_028_TEV_InM_mfTotExEstim_irv()) * 1.525878906E-005F)
      * Rte_IrvRead_RE_InMdlT_028_TEV_InM_concFuStmEstim_irv())) +
                      localInM_mFuStmEstimPrev_irv_i) *
      localInM_mGradFuStmEstim_irv_g;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S328>/autosar_testpoint1' */

    /* S-Function Block: <S328>/autosar_testpoint1 */
    InM_mGradFuStmEstim_IRV_MP = localDivide_iz;

    /* end of Outputs for SubSystem: '<S321>/F02_diff_fuel_mass' */

    /* Outputs for atomic SubSystem: '<S321>/F03_Calc_estimated_fuel_mass' *
     * Block requirements for '<S321>/F03_Calc_estimated_fuel_mass':
     *  1. SubSystem "F03_Calc_estimated_fuel_mass" !Trace_To : VEMS_R_11_01067_051.01 ;
     */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S333>/autosar_testpoint1' */

    /* S-Function Block: <S333>/autosar_testpoint1 */
    InM_mFuStmEstimPrev_IRV_MP = localTmpSignalConversionAtIn_ko;

    /* Sum: '<S327>/Sum2' incorporates:
     *  Constant: '<S327>/InM_mFuStmEstimDec_C'
     *  DataTypeConversion: '<S327>/Data Type Conversion6'
     */
    localInM_mFuStmEstim_irv_f = localTmpSignalConversionAtIn_ko - (((Float32)
      InM_mFuStmEstimDec_C) * 1.862645149E-009F);

    /* RelationalOperator: '<S327>/Relational Operator' incorporates:
     *  Constant: '<S327>/InM_mFuStmEstimDec_C1'
     *  DataTypeConversion: '<S327>/Data Type Conversion2'
     */
    localRelationalOperator_bc = (localInM_mFuStmEstimPrev_irv_i <= (((Float32)
      InM_mfFuStmBlbyThd_C) * 2.169999931E-007F));

    /* Logic: '<S332>/Logical Operator3' */
    localMemory = !localRelationalOperator_bc;

    /* UnitDelay: '<S351>/Unit Delay' */
    localR = InMdlT_DWork.UnitDelay_DSTATE_f;

    /* UnitDelay: '<S358>/Unit Delay' */
    localLogicalOperator3 = InMdlT_DWork.UnitDelay_DSTATE_j;

    /* DataTypeConversion: '<S327>/Data Type Conversion1' incorporates:
     *  Constant: '<S327>/InM_tiSampleFast_SC'
     */
    localInM_mGradFuStmEstim_irv_g = ((Float32)InM_tiSampleFast_SC) *
      5.000000237E-004F;

    /* Sum: '<S332>/Sum2' incorporates:
     *  Constant: '<S327>/InM_tiDlyFuStmCls_C1'
     *  Constant: '<S332>/Constant1'
     *  Constant: '<S332>/Constant6'
     *  DataTypeConversion: '<S332>/Data Type Conversion3'
     *  MinMax: '<S332>/MinMax1'
     *  Product: '<S352>/Divide'
     */
    localInM_mFuStmEstimPrev_irv_i = (((Float32)InM_tiDlyFuStmClsBbly_C) *
      1.000000047E-003F) + (10.0F * localInM_mGradFuStmEstim_irv_g);

    /* UnitDelay: '<S350>/Unit Delay' */
    localMinMax_c = InMdlT_DWork.UnitDelay_DSTATE;

    /* RelationalOperator: '<S357>/LowerRelop1' */
    localRelationalOperator_ex = (localMinMax_c > localInM_mFuStmEstimPrev_irv_i);

    /* Switch: '<S357>/Switch' incorporates:
     *  Constant: '<S332>/Constant3'
     *  RelationalOperator: '<S357>/UpperRelop'
     */
    if (localMinMax_c < 0.0F) {
      localMinMax_c = 0.0F;
    }

    /* Switch: '<S357>/Switch2' */
    if (!localRelationalOperator_ex) {
      localInM_mFuStmEstimPrev_irv_i = localMinMax_c;
    }

    /* Switch: '<S332>/Switch1' incorporates:
     *  Constant: '<S332>/Constant4'
     *  Constant: '<S332>/Constant7'
     *  Logic: '<S332>/Logical Operator2'
     *  Logic: '<S353>/Logical Operator'
     *  Logic: '<S353>/Logical Operator1'
     *  Sum: '<S332>/Sum1'
     */
    if ((localR) || ((localRelationalOperator_bc) && (!localLogicalOperator3)))
    {
      localSwitch1_p = 0.0F;
    } else {
      localSwitch1_p = (localInM_mGradFuStmEstim_irv_g +
                        localInM_mFuStmEstimPrev_irv_i) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S332>/Relational Operator2' incorporates:
     *  MinMax: '<S332>/MinMax1'
     */
    localRelationalOperator2 = (localSwitch1_p >= (((Float32)
      InM_tiDlyFuStmClsBbly_C) * 1.000000047E-003F));

    /* UnitDelay: '<S359>/Unit Delay' */
    localLogicalOperator3 = InMdlT_DWork.UnitDelay_DSTATE_je;

    /* RelationalOperator: '<S332>/Relational Operator1' incorporates:
     *  Constant: '<S332>/Constant2'
     *  MinMax: '<S332>/MinMax1'
     */
    localRelationalOperator1_d = (InM_tiDlyFuStmClsBbly_C == 0U);

    /* Switch: '<S332>/Switch' incorporates:
     *  Constant: '<S332>/Constant5'
     *  Logic: '<S332>/Logical Operator1'
     *  Logic: '<S354>/Logical Operator'
     *  Logic: '<S354>/Logical Operator1'
     */
    if (!localRelationalOperator1_d) {
      localLogicalOperator3 = ((localRelationalOperator2) &&
        (!localLogicalOperator3));
    } else {
      localLogicalOperator3 = TRUE;
    }

    /* Memory: '<S349>/Memory' */
    localR = InMdlT_DWork.Memory_PreviousInput;

    /* CombinatorialLogic: '<S349>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InMdlT_ConstP.pooled31[rowidx];
      localLogic[1] = InMdlT_ConstP.pooled31[rowidx + 8];
    }

    /* Logic: '<S331>/Logical Operator3' */
    localLogicalOperator3 = !localTmpSignalConversionAtCan_i;

    /* UnitDelay: '<S339>/Unit Delay' */
    localR = InMdlT_DWork.UnitDelay_DSTATE_i;

    /* UnitDelay: '<S346>/Unit Delay' */
    localMemory = InMdlT_DWork.UnitDelay_DSTATE_h;

    /* Product: '<S340>/Divide' incorporates:
     *  Constant: '<S331>/Constant6'
     */
    localMinMax_c = 10.0F * localInM_mGradFuStmEstim_irv_g;

    /* Sum: '<S331>/Sum2' incorporates:
     *  Constant: '<S327>/InM_tiDlyFuStmCls_C'
     *  Constant: '<S331>/Constant1'
     *  MinMax: '<S331>/MinMax1'
     */
    localInM_mFuStmEstimPrev_irv_i = (((Float32)InM_tiDlyFuStmCls_C) *
      1.000000047E-003F) + localMinMax_c;

    /* UnitDelay: '<S338>/Unit Delay' */
    localMinMax_c = InMdlT_DWork.UnitDelay_DSTATE_b;

    /* RelationalOperator: '<S345>/LowerRelop1' */
    localRelationalOperator_ex = (localMinMax_c > localInM_mFuStmEstimPrev_irv_i);

    /* Switch: '<S345>/Switch' incorporates:
     *  Constant: '<S331>/Constant3'
     *  RelationalOperator: '<S345>/UpperRelop'
     */
    if (localMinMax_c < 0.0F) {
      localMinMax_c = 0.0F;
    }

    /* Switch: '<S345>/Switch2' */
    if (!localRelationalOperator_ex) {
      localInM_mFuStmEstimPrev_irv_i = localMinMax_c;
    }

    /* Switch: '<S331>/Switch1' incorporates:
     *  Constant: '<S331>/Constant4'
     *  Constant: '<S331>/Constant7'
     *  Logic: '<S331>/Logical Operator2'
     *  Logic: '<S341>/Logical Operator'
     *  Logic: '<S341>/Logical Operator1'
     *  Sum: '<S331>/Sum1'
     */
    if ((localR) || ((localTmpSignalConversionAtCan_i) && (!localMemory))) {
      localInM_mGradFuStmEstim_irv_g = 0.0F;
    } else {
      localInM_mGradFuStmEstim_irv_g = (localInM_mGradFuStmEstim_irv_g +
        localInM_mFuStmEstimPrev_irv_i) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S331>/Relational Operator2' incorporates:
     *  MinMax: '<S331>/MinMax1'
     */
    localRelationalOperator_ex = (localInM_mGradFuStmEstim_irv_g >= (((Float32)
      InM_tiDlyFuStmCls_C) * 1.000000047E-003F));

    /* UnitDelay: '<S347>/Unit Delay' */
    localR = InMdlT_DWork.UnitDelay_DSTATE_g;

    /* RelationalOperator: '<S331>/Relational Operator1' incorporates:
     *  Constant: '<S331>/Constant2'
     *  MinMax: '<S331>/MinMax1'
     */
    localTmpSignalConversionAtIn_px = (InM_tiDlyFuStmCls_C == 0U);

    /* Switch: '<S331>/Switch' incorporates:
     *  Constant: '<S331>/Constant5'
     *  Logic: '<S331>/Logical Operator1'
     *  Logic: '<S342>/Logical Operator'
     *  Logic: '<S342>/Logical Operator1'
     */
    if (!localTmpSignalConversionAtIn_px) {
      localR = ((localRelationalOperator_ex) && (!localR));
    } else {
      localR = TRUE;
    }

    /* Memory: '<S337>/Memory' */
    localMemory = InMdlT_DWork.Memory_PreviousInput_h;

    /* CombinatorialLogic: '<S337>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_g[0] = InMdlT_ConstP.pooled31[rowidx];
      localLogic_g[1] = InMdlT_ConstP.pooled31[rowidx + 8];
    }

    /* Switch: '<S327>/Switch' incorporates:
     *  Logic: '<S327>/Logical Operator1'
     *  Product: '<S335>/Divide'
     *  Sum: '<S327>/Sum'
     */
    if ((localLogic[1]) && (localLogic_g[1])) {
      localMinMax_c = localInM_mFuStmEstim_irv_f;
    } else {
      localMinMax_c = (localDivide_iz * InM_tiRelax_mFuStmEstim) +
        localTmpSignalConversionAtIn_ko;
    }

    /* MinMax: '<S327>/MinMax' incorporates:
     *  Constant: '<S327>/Constant'
     */
    localMinMax_c = rt_MAXf(localMinMax_c, 0.0F);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S334>/autosar_testpoint1' */

    /* S-Function Block: <S334>/autosar_testpoint1 */
    InM_mFuStmEstim_IRV_MP = localMinMax_c;

    /* SignalConversion: '<S327>/Signal Conversion1' */
    localInM_mFuStmEstim_irv_f = localMinMax_c;

    /* SignalConversion: '<S327>/Signal Conversion2' */
    localInM_mFuStmEstimPrev_irv_i = localTmpSignalConversionAtIn_ko;

    /* Update for UnitDelay: '<S351>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_f = localRelationalOperator1_d;

    /* Update for UnitDelay: '<S358>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_j = localRelationalOperator_bc;

    /* Update for UnitDelay: '<S350>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE = localSwitch1_p;

    /* Update for UnitDelay: '<S359>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_je = localRelationalOperator2;

    /* Update for Memory: '<S349>/Memory' */
    InMdlT_DWork.Memory_PreviousInput = localLogic[0];

    /* Update for UnitDelay: '<S339>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_i = localTmpSignalConversionAtIn_px;

    /* Update for UnitDelay: '<S346>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_h = localTmpSignalConversionAtCan_i;

    /* Update for UnitDelay: '<S338>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_b = localInM_mGradFuStmEstim_irv_g;

    /* Update for UnitDelay: '<S347>/Unit Delay' */
    InMdlT_DWork.UnitDelay_DSTATE_g = localRelationalOperator_ex;

    /* Update for Memory: '<S337>/Memory' */
    InMdlT_DWork.Memory_PreviousInput_h = localLogic_g[0];

    /* end of Outputs for SubSystem: '<S321>/F03_Calc_estimated_fuel_mass' */

    /* SignalConversion: '<S321>/Signal Conversion' */
    localInM_mGradFuStmEstim_irv_g = localDivide_iz;
  } else {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S322>/autosar_testpoint1' incorporates:
     *  Constant: '<S320>/Constant1'
     */
    /* S-Function Block: <S322>/autosar_testpoint1 */
    InM_mFuStmEstimPrev_IRV_MP = 0.0F;

    /* SignalConversion: '<S320>/Signal Conversion2' incorporates:
     *  Constant: '<S320>/Constant1'
     */
    localInM_mFuStmEstimPrev_irv_i = 0.0F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S323>/autosar_testpoint1' incorporates:
     *  Constant: '<S320>/Constant3'
     */

    /* S-Function Block: <S323>/autosar_testpoint1 */
    InM_mGradFuStmEstim_IRV_MP = 0.0F;

    /* SignalConversion: '<S320>/Signal Conversion1' incorporates:
     *  Constant: '<S320>/Constant3'
     */
    localInM_mGradFuStmEstim_irv_g = 0.0F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S324>/autosar_testpoint1' incorporates:
     *  Constant: '<S320>/Constant2'
     */

    /* S-Function Block: <S324>/autosar_testpoint1 */
    InM_mFuStmEstim_IRV_MP = 0.0F;

    /* SignalConversion: '<S320>/Signal Conversion3' incorporates:
     *  Constant: '<S320>/Constant2'
     */
    localInM_mFuStmEstim_irv_f = 0.0F;
  }

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_mFuStmEstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_028_TEV_InM_mFuStmEstimPrev_irv
    (localInM_mFuStmEstimPrev_irv_i);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_mFuStmEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_028_TEV_InM_mFuStmEstim_irv(localInM_mFuStmEstim_irv_f);

  /* SignalConversion: '<S57>/TmpSignal ConversionAtInM_mGradFuStmEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_028_TEV_InM_mGradFuStmEstim_irv
    (localInM_mGradFuStmEstim_irv_g);
}

/* Start for exported function: RE_InMdlT_046_MSE */
void RE_InMdlT_046_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S13>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F03_2_Reset_egr_mass'
   *
   * Block requirements for '<S1>/INM2_F03_2_Reset_egr_mass':
   *  1. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_128.01 ;
   *  4. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_366.01 ;
   *  5. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_046_MSE */
void RE_InMdlT_046_MSE(void)
{
  UInt32 localSwitch_ga;
  UInt16 localSwitch_ig;

  /* S-Function (fcncallgen): '<S13>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F03_2_Reset_egr_mass'
   *
   * Block requirements for '<S1>/INM2_F03_2_Reset_egr_mass':
   *  1. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_128.01 ;
   *  4. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_366.01 ;
   *  5. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_2_Reset_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S368>/autosar_testpoint1' incorporates:
   *  Constant: '<S59>/InM_tiDlyEGRCls_C'
   */

  /* S-Function Block: <S368>/autosar_testpoint1 */
  InM_ctEGRVlvCls_IRV_MP = InM_tiDlyEGRCls_C;

  /* SignalConversion: '<S59>/TmpSignal ConversionAtInM_ctEGRVlvCls_irvInport2' incorporates:
   *  Constant: '<S59>/InM_tiDlyEGRCls_C'
   *  SignalConversion: '<S59>/Signal Conversion'
   */
  Rte_IrvWrite_RE_InMdlT_046_MSE_InM_ctEGRVlvCls_irv(InM_tiDlyEGRCls_C);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S369>/autosar_testpoint1' incorporates:
   *  Constant: '<S59>/Constant3'
   */

  /* S-Function Block: <S369>/autosar_testpoint1 */
  InM_mEGREstimPrev_IRV_MP = 0.0F;

  /* Switch: '<S371>/Switch' incorporates:
   *  Constant: '<S366>/offset'
   *  Constant: '<S366>/offset1'
   *  Constant: '<S366>/one_on_slope'
   *  Constant: '<S371>/Byp_Fonction_SC'
   *  Constant: '<S371>/Int_BypC'
   *  Constant: '<S59>/Constant3'
   *  DataTypeConversion: '<S366>/OutDTConv'
   *  Product: '<S366>/Product4'
   *  Sum: '<S366>/Add1'
   *  Sum: '<S366>/Add2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ga = InM_mEGREstim_B;
  } else {
    localSwitch_ga = 0U;
  }

  /* SignalConversion: '<S59>/TmpSignal ConversionAtInM_mEGREstimInport2' */
  Rte_Write_P_InM_mEGREstim_InM_mEGREstim(localSwitch_ga);

  /* Switch: '<S370>/Switch' incorporates:
   *  Constant: '<S370>/Byp_Fonction_SC'
   *  Constant: '<S370>/Int_BypC'
   *  DataTypeConversion: '<S367>/OutDTConv'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ig = InM_mEGREstimLoResl_B;
  } else {
    localSwitch_ig = 0U;
  }

  /* SignalConversion: '<S59>/TmpSignal ConversionAtInM_mEGREstimLoReslInport2' */
  Rte_Write_P_InM_mEGREstimLoResl_InM_mEGREstimLoResl(localSwitch_ig);

  /* SignalConversion: '<S59>/TmpSignal ConversionAtInM_mEGREstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_046_MSE_InM_mEGREstimPrev_irv(0.0F);
}

/* Start for exported function: RE_InMdlT_013_DRE */
void RE_InMdlT_013_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S14>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F03_1_Reset_egr_mass1'
   *
   * Block requirements for '<S1>/INM2_F03_1_Reset_egr_mass1':
   *  1. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_128.01 ;
   *  4. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_336.02 ;
   *  5. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_224.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_013_DRE */
void RE_InMdlT_013_DRE(void)
{
  UInt32 localInM_mEGREstim;
  UInt16 localSwitch_e0;

  /* S-Function (fcncallgen): '<S14>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F03_1_Reset_egr_mass1'
   *
   * Block requirements for '<S1>/INM2_F03_1_Reset_egr_mass1':
   *  1. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_128.01 ;
   *  4. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_336.02 ;
   *  5. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_1_Reset_egr_mass1" !Trace_To : VEMS_R_11_01067_224.01 ;
   */

  /* SignalConversion: '<S362>/copy' incorporates:
   *  Constant: '<S58>/InM_tiDlyEGRCls_C'
   */
  InM_ctEGRVlvCls_IRV_MP = InM_tiDlyEGRCls_C;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S362>/autosar_testpoint1' */

  /* S-Function Block: <S362>/autosar_testpoint1 */

  /* SignalConversion: '<S58>/TmpSignal ConversionAtInM_ctEGRVlvCls_irvInport2' incorporates:
   *  Constant: '<S58>/InM_tiDlyEGRCls_C'
   *  SignalConversion: '<S58>/Signal Conversion'
   */
  Rte_IrvWrite_RE_InMdlT_013_DRE_InM_ctEGRVlvCls_irv(InM_tiDlyEGRCls_C);

  /* SignalConversion: '<S363>/copy' incorporates:
   *  Constant: '<S58>/Constant3'
   */
  InM_mEGREstimPrev_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S363>/autosar_testpoint1' */

  /* S-Function Block: <S363>/autosar_testpoint1 */

  /* Switch: '<S365>/Switch' incorporates:
   *  Constant: '<S360>/offset'
   *  Constant: '<S360>/offset1'
   *  Constant: '<S360>/one_on_slope'
   *  Constant: '<S365>/Byp_Fonction_SC'
   *  Constant: '<S365>/Int_BypC'
   *  Constant: '<S58>/Constant3'
   *  DataTypeConversion: '<S360>/OutDTConv'
   *  Product: '<S360>/Product4'
   *  Sum: '<S360>/Add1'
   *  Sum: '<S360>/Add2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localInM_mEGREstim = InM_mEGREstim_B;
  } else {
    localInM_mEGREstim = 0U;
  }

  /* SignalConversion: '<S58>/TmpSignal ConversionAtInM_mEGREstimInport2' */
  Rte_Write_P_InM_mEGREstim_InM_mEGREstim(localInM_mEGREstim);

  /* Switch: '<S364>/Switch' incorporates:
   *  Constant: '<S364>/Byp_Fonction_SC'
   *  Constant: '<S364>/Int_BypC'
   *  DataTypeConversion: '<S361>/OutDTConv'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_e0 = InM_mEGREstimLoResl_B;
  } else {
    localSwitch_e0 = 0U;
  }

  /* SignalConversion: '<S58>/TmpSignal ConversionAtInM_mEGREstimLoReslInport2' */
  Rte_Write_P_InM_mEGREstimLoResl_InM_mEGREstimLoResl(localSwitch_e0);

  /* SignalConversion: '<S58>/TmpSignal ConversionAtInM_mEGREstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_013_DRE_InM_mEGREstimPrev_irv(0.0F);
}

/* Start for exported function: RE_InMdlT_012_TEV */
void RE_InMdlT_012_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S15>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F03_3_Calc_egr_mass'
   *
   * Block requirements for '<S1>/INM2_F03_3_Calc_egr_mass':
   *  1. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_129.01 ;
   *  4. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_335.03 ;
   *  5. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  9. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  10. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_226.01 ;
   *  11. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  12. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  13. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_227.01 ;
   *  14. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  15. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_149.01 ;
   *  16. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  17. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_350.01 ;
   *  18. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  19. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  20. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_380.01 ;
   *  21. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_298.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_012_TEV */
void RE_InMdlT_012_TEV(void)
{
  /* local block i/o variables */
  Float32 localDivide_is;
  Float32 localSum_i;
  Float32 localcopy;
  Float32 localMinMax_n;
  UInt32 localTmpSignalConversionAtIn_mw;
  UInt32 localSwitch_ev;
  UInt8 localTmpSignalConversionAtEn_ay;
  Boolean localRelationalOperator_hv;
  Float32 localSum1_kc;
  Float32 localSwitch_az;
  SInt32 localrtmax;
  Boolean localTmpSignalConversionAtEGR_c;
  UInt32 localSwitch_hv;
  UInt16 localTmpSignalConversionAtIn_gx;
  SInt32 localrtmax_0;

  /* S-Function (fcncallgen): '<S15>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F03_3_Calc_egr_mass'
   *
   * Block requirements for '<S1>/INM2_F03_3_Calc_egr_mass':
   *  1. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_126.01 ;
   *  2. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_127.01 ;
   *  3. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_129.01 ;
   *  4. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_335.03 ;
   *  5. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  6. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  7. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_389.01 ;
   *  8. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_224.01 ;
   *  9. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  10. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_226.01 ;
   *  11. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  12. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_321.02 ;
   *  13. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_227.01 ;
   *  14. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  15. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_149.01 ;
   *  16. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  17. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_350.01 ;
   *  18. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  19. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  20. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_380.01 ;
   *  21. SubSystem "INM2_F03_3_Calc_egr_mass" !Trace_To : VEMS_R_11_01067_298.02 ;
   */

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_bAcceEngOutport2' incorporates:
   *  Inport: '<Root>/InM_bAcceEng_INPUT'
   */
  Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&InMdlT_B.TmpSignalConversionAtInM_bAcceE);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_tiRelax_mTotEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_tiRelax_mTotEstim_INPUT'
   */
  Rte_Read_R_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim
    (&InMdlT_B.TmpSignalConversionAtInM_tiRela);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_concEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_concEGREstim_INPUT'
   */
  Rte_Read_R_InM_concEGREstim_InM_concEGREstim
    (&InMdlT_B.TmpSignalConversionAtInM_concEG);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mfTotExEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_mfTotE =
    Rte_IrvRead_RE_InMdlT_012_TEV_InM_mfTotExEstim_irv();

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv_INPUT'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&InMdlT_B.TmpSignalConversionAtInM_mfEG_l);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtEGRVlv_bClnEGRFoulOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bClnEGRFoul'
   */
  Rte_Read_R_EGRVlv_bClnEGRFoul_EGRVlv_bClnEGRFoul
    (&InMdlT_B.TmpSignalConversionAtEGRVlv_bCl);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtEGRVlv_bAcvClsEGRReqOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bAcvClsEGRReq'
   */
  Rte_Read_R_EGRVlv_bAcvClsEGRReq_EGRVlv_bAcvClsEGRReq
    (&localTmpSignalConversionAtEGR_c);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_ctEGRVlvClsPrevOutport2' */
  localTmpSignalConversionAtIn_mw =
    Rte_IrvRead_RE_InMdlT_012_TEV_InM_ctEGRVlvCls_irv();

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstimPrevOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_mEGREs =
    Rte_IrvRead_RE_InMdlT_012_TEV_InM_mEGREstimPrev_irv();

  /* SignalConversion: '<S60>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_ay);

  /* RelationalOperator: '<S60>/Relational Operator' incorporates:
   *  Constant: '<S60>/Ext_stRun_SC'
   */
  localRelationalOperator_hv = (localTmpSignalConversionAtEn_ay == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S60>/F01_Calc_estimated_egr' incorporates:
   *  EnablePort: '<S372>/NS_bRun'
   *
   * Block requirements for '<S60>/F01_Calc_estimated_egr':
   *  1. SubSystem "F01_Calc_estimated_egr" !Trace_To : VEMS_R_11_01067_130.01 ;
   */
  if (localRelationalOperator_hv) {
    /* Outputs for atomic SubSystem: '<S372>/F01_calcul_egr_relaxation_term' *
     * Block requirements for '<S372>/F01_calcul_egr_relaxation_term':
     *  1. SubSystem "F01_calcul_egr_relaxation_term" !Trace_To : VEMS_R_11_01067_131.01 ;
     */

    /* DataTypeConversion: '<S376>/Data Type Conversion1' */
    InM_tiRelax_mEGREstim = ((Float32)InMdlT_B.TmpSignalConversionAtInM_tiRela)
      * 6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S372>/F01_calcul_egr_relaxation_term' */

    /* Outputs for atomic SubSystem: '<S372>/F02_diff_egr_mass' *
     * Block requirements for '<S372>/F02_diff_egr_mass':
     *  1. SubSystem "F02_diff_egr_mass" !Trace_To : VEMS_R_11_01067_132.01 ;
     */

    /* Switch: '<S377>/Switch1' incorporates:
     *  Constant: '<S377>/Constant6'
     *  DataTypeConversion: '<S377>/Data Type Conversion12'
     */
    if (InMdlT_B.TmpSignalConversionAtEGRVlv_bCl) {
      localSum1_kc = 0.0F;
    } else {
      localSum1_kc = ((Float32)InMdlT_B.TmpSignalConversionAtInM_mfEG_l) *
        1.525878906E-005F;
    }

    /* Sum: '<S377>/Sum1' incorporates:
     *  DataTypeConversion: '<S377>/Data Type Conversion1'
     *  DataTypeConversion: '<S377>/Data Type Conversion2'
     *  Product: '<S383>/Divide'
     */
    localSum1_kc -= (((Float32)InMdlT_B.TmpSignalConversionAtInM_concEG) *
                     1.525878906E-005F) * (((Float32)
      InMdlT_B.TmpSignalConversionAtInM_mfTotE) * 1.525878906E-005F);

    /* Product: '<S380>/Product4' incorporates:
     *  Constant: '<S380>/offset'
     *  Constant: '<S380>/one_on_slope'
     *  Sum: '<S380>/Add1'
     */
    localSwitch_az = 32768.0F * localSum1_kc;

    /* Switch: '<S380>/Switch1' incorporates:
     *  Constant: '<S380>/offset2'
     *  Constant: '<S380>/offset3'
     *  Constant: '<S380>/offset4'
     *  RelationalOperator: '<S380>/Relational Operator'
     *  Sum: '<S380>/Add3'
     *  Sum: '<S380>/Add4'
     */
    if (localSwitch_az >= 0.0F) {
      localSwitch_az += 0.5F;
    } else {
      localSwitch_az -= 0.5F;
    }

    /* DataStoreWrite: '<S377>/Data Store Write2' incorporates:
     *  DataTypeConversion: '<S380>/OutDTConv'
     */
    if (localSwitch_az < 32768.0F) {
      InM_mGradEGREstimRaw_MP = (SInt16)localSwitch_az;
    } else {
      InM_mGradEGREstimRaw_MP = MAX_int16_T;
    }

    /* Switch: '<S377>/Switch' incorporates:
     *  Constant: '<S377>/Constant3'
     *  Constant: '<S377>/InM_rKk2_C'
     *  DataTypeConversion: '<S377>/Data Type Conversion4'
     */
    if (InMdlT_B.TmpSignalConversionAtInM_bAcceE) {
      localSwitch_az = 1.0F;
    } else {
      localSwitch_az = ((Float32)InM_rKk2_C) * 0.00390625F;
    }

    /* Product: '<S382>/Divide' */
    localDivide_is = localSum1_kc * localSwitch_az;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S381>/autosar_testpoint1' */

    /* S-Function Block: <S381>/autosar_testpoint1 */
    InM_mGradEGREstim_IRV_MP = localDivide_is;

    /* end of Outputs for SubSystem: '<S372>/F02_diff_egr_mass' */

    /* Outputs for atomic SubSystem: '<S372>/F03_Calc_egr_mass_integration' *
     * Block requirements for '<S372>/F03_Calc_egr_mass_integration':
     *  1. SubSystem "F03_Calc_egr_mass_integration" !Trace_To : VEMS_R_11_01067_133.01 ;
     */

    /* Sum: '<S378>/Sum' incorporates:
     *  Product: '<S387>/Divide'
     */
    localMinMax_n = (localDivide_is * InM_tiRelax_mEGREstim) +
      InMdlT_B.TmpSignalConversionAtInM_mEGREs;

    /* MinMax: '<S378>/MinMax' incorporates:
     *  Constant: '<S378>/Constant'
     */
    localMinMax_n = rt_MAXf(localMinMax_n, 0.0F);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S386>/autosar_testpoint1' */

    /* S-Function Block: <S386>/autosar_testpoint1 */
    InM_mEGREstimPrev_IRV_MP = localMinMax_n;

    /* SignalConversion: '<S378>/Signal Conversion2' */
    InMdlT_B.InM_mEGREstimPrev_irv_i = localMinMax_n;

    /* DataTypeConversion: '<S384>/OutDTConv' incorporates:
     *  Constant: '<S384>/offset'
     *  Constant: '<S384>/offset1'
     *  Constant: '<S384>/one_on_slope'
     *  Product: '<S384>/Product4'
     *  Sum: '<S384>/Add1'
     *  Sum: '<S384>/Add2'
     */
    localSum1_kc = (5.36870912E+008F * localMinMax_n) + 0.5F;
    if (localSum1_kc < 4.294967296E+009F) {
      if (localSum1_kc >= 0.0F) {
        InMdlT_B.Merge4 = (UInt32)localSum1_kc;
      } else {
        InMdlT_B.Merge4 = 0U;
      }
    } else {
      InMdlT_B.Merge4 = MAX_uint32_T;
    }

    /* DataTypeConversion: '<S385>/OutDTConv' incorporates:
     *  Constant: '<S385>/offset'
     *  Constant: '<S385>/offset1'
     *  Constant: '<S385>/one_on_slope'
     *  Product: '<S385>/Product4'
     *  Sum: '<S385>/Add1'
     *  Sum: '<S385>/Add2'
     */
    localSum1_kc = (4.5134985E+006F * localMinMax_n) + 0.5F;
    if (localSum1_kc < 65536.0F) {
      if (localSum1_kc >= 0.0F) {
        InMdlT_B.Merge5_j = (UInt16)localSum1_kc;
      } else {
        InMdlT_B.Merge5_j = 0U;
      }
    } else {
      InMdlT_B.Merge5_j = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S372>/F03_Calc_egr_mass_integration' */

    /* Outputs for atomic SubSystem: '<S372>/F04_Egr_mass_adjustment' *
     * Block requirements for '<S372>/F04_Egr_mass_adjustment':
     *  1. SubSystem "F04_Egr_mass_adjustment" !Trace_To : VEMS_R_11_01067_134.01 ;
     */

    /* Outputs for atomic SubSystem: '<S379>/F01_Reset_egr_counter' *
     * Block requirements for '<S379>/F01_Reset_egr_counter':
     *  1. SubSystem "F01_Reset_egr_counter" !Trace_To : VEMS_R_11_01067_135.01 ;
     */

    /* MinMax: '<S388>/MinMax' incorporates:
     *  Constant: '<S388>/Constant2'
     *  Constant: '<S388>/InM_tiSampleFast_SC'
     *  DataTypeConversion: '<S388>/Data Type Conversion12'
     *  Sum: '<S388>/Sum'
     */
    localrtmax = 0;
    if (localTmpSignalConversionAtIn_mw > 2147483647U) {
      localrtmax_0 = MAX_int32_T;
    } else {
      localrtmax_0 = (SInt32)localTmpSignalConversionAtIn_mw;
    }

    localrtmax_0 -= (SInt32)(((UInt32)((SInt32)InM_tiSampleFast_SC)) >> 1);
    if (localrtmax_0 > 0) {
      localrtmax = localrtmax_0;
    }

    if (localrtmax <= 0) {
      localSwitch_ev = 0U;
    } else {
      localSwitch_ev = (UInt32)localrtmax;
    }

    /* Switch: '<S388>/Switch' incorporates:
     *  Constant: '<S388>/InM_tiDlyEGRCls_C'
     */
    if (!localTmpSignalConversionAtEGR_c) {
      localSwitch_ev = InM_tiDlyEGRCls_C;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S390>/autosar_testpoint1' */

    /* S-Function Block: <S390>/autosar_testpoint1 */
    InM_ctEGRVlvCls_IRV_MP = localSwitch_ev;

    /* SignalConversion: '<S388>/Signal Conversion1' */
    InMdlT_B.InM_ctEGRVlvCls_irv_p = localSwitch_ev;

    /* end of Outputs for SubSystem: '<S379>/F01_Reset_egr_counter' */

    /* Outputs for enable SubSystem: '<S379>/F02_Corrected_egr_mass' incorporates:
     *  Constant: '<S379>/Constant2'
     *  Constant: '<S379>/Constant3'
     *  EnablePort: '<S389>/NS_Enable'
     *  Logic: '<S379>/Logical Operator'
     *  RelationalOperator: '<S379>/Relational Operator'
     *  RelationalOperator: '<S379>/Relational Operator1'
     *
     * Block requirements for '<S379>/F02_Corrected_egr_mass':
     *  1. SubSystem "F02_Corrected_egr_mass" !Trace_To : VEMS_R_11_01067_136.01 ;
     */
    if ((localTmpSignalConversionAtIn_mw == 0U) &&
        (InMdlT_B.TmpSignalConversionAtInM_mEGREs > 0.0F)) {
      /* Sum: '<S389>/Sum' incorporates:
       *  Constant: '<S389>/InM_mEGREstimDec_C'
       *  DataTypeConversion: '<S389>/Data Type Conversion12'
       */
      localSum_i = InMdlT_B.TmpSignalConversionAtInM_mEGREs - (((Float32)
        InM_mEGREstimDec_C) * 1.490116119E-008F);

      /* S-Function (sfun_autosar_extras_dsm_read_write): '<S393>/autosar_testpoint1' */

      /* S-Function Block: <S393>/autosar_testpoint1 */
      InM_mEGREstimPrev_IRV_MP = localSum_i;

      /* SignalConversion: '<S389>/Signal Conversion1' */
      InMdlT_B.InM_mEGREstimPrev_irv_i = localSum_i;

      /* DataTypeConversion: '<S391>/OutDTConv' incorporates:
       *  Constant: '<S391>/offset'
       *  Constant: '<S391>/offset1'
       *  Constant: '<S391>/one_on_slope'
       *  Product: '<S391>/Product4'
       *  Sum: '<S391>/Add1'
       *  Sum: '<S391>/Add2'
       */
      localSum1_kc = (5.36870912E+008F * localSum_i) + 0.5F;
      if (localSum1_kc < 4.294967296E+009F) {
        if (localSum1_kc >= 0.0F) {
          InMdlT_B.Merge4 = (UInt32)localSum1_kc;
        } else {
          InMdlT_B.Merge4 = 0U;
        }
      } else {
        InMdlT_B.Merge4 = MAX_uint32_T;
      }

      /* DataTypeConversion: '<S392>/OutDTConv' incorporates:
       *  Constant: '<S392>/offset'
       *  Constant: '<S392>/offset1'
       *  Constant: '<S392>/one_on_slope'
       *  Product: '<S392>/Product4'
       *  Sum: '<S392>/Add1'
       *  Sum: '<S392>/Add2'
       */
      localSum1_kc = (4.5134985E+006F * localSum_i) + 0.5F;
      if (localSum1_kc < 65536.0F) {
        if (localSum1_kc >= 0.0F) {
          InMdlT_B.Merge5_j = (UInt16)localSum1_kc;
        } else {
          InMdlT_B.Merge5_j = 0U;
        }
      } else {
        InMdlT_B.Merge5_j = MAX_uint16_T;
      }
    }

    /* end of Outputs for SubSystem: '<S379>/F02_Corrected_egr_mass' */

    /* end of Outputs for SubSystem: '<S372>/F04_Egr_mass_adjustment' */

    /* SignalConversion: '<S372>/Signal Conversion1' */
    localSum1_kc = localDivide_is;
  }

  /* end of Outputs for SubSystem: '<S60>/F01_Calc_estimated_egr' */

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mGradEGREstim_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_mGradE =
    Rte_IrvRead_RE_InMdlT_012_TEV_InM_mGradEGREstim_irv();

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstim1Outport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstim_INPUT'
   */
  Rte_Read_R_InM_mEGREstim_InM_mEGREstim
    (&InMdlT_B.TmpSignalConversionAtInM_mEGR_d);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstimLoResl1Outport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstimLoResl_INPUT'
   */
  Rte_Read_R_InM_mEGREstimLoResl_InM_mEGREstimLoResl
    (&localTmpSignalConversionAtIn_gx);

  /* Outputs for enable SubSystem: '<S60>/F02_NOT' incorporates:
   *  EnablePort: '<S373>/NS_bRun'
   *  Logic: '<S60>/NAN1'
   */
  if (!localRelationalOperator_hv) {
    /* SignalConversion: '<S373>/Signal Conversion2' */
    localcopy = InMdlT_B.TmpSignalConversionAtInM_mGradE;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S395>/autosar_testpoint1' */

    /* S-Function Block: <S395>/autosar_testpoint1 */
    InM_mGradEGREstim_IRV_MP = localcopy;

    /* SignalConversion: '<S373>/Signal Conversion1' */
    localSum1_kc = localcopy;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S394>/autosar_testpoint1' */

    /* S-Function Block: <S394>/autosar_testpoint1 */
    InM_ctEGRVlvCls_IRV_MP = localTmpSignalConversionAtIn_mw;

    /* SignalConversion: '<S373>/Signal Conversion5' */
    InMdlT_B.InM_ctEGRVlvCls_irv_p = localTmpSignalConversionAtIn_mw;

    /* SignalConversion: '<S396>/copy' */
    localcopy = InMdlT_B.TmpSignalConversionAtInM_mEGREs;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S396>/autosar_testpoint1' */

    /* S-Function Block: <S396>/autosar_testpoint1 */
    InM_mEGREstimPrev_IRV_MP = localcopy;

    /* SignalConversion: '<S373>/Signal Conversion3' */
    InMdlT_B.InM_mEGREstimPrev_irv_i = InMdlT_B.TmpSignalConversionAtInM_mEGREs;

    /* SignalConversion: '<S373>/Signal Conversion4' */
    InMdlT_B.Merge4 = InMdlT_B.TmpSignalConversionAtInM_mEGR_d;

    /* SignalConversion: '<S373>/Signal Conversion' */
    InMdlT_B.Merge5_j = localTmpSignalConversionAtIn_gx;
  }

  /* end of Outputs for SubSystem: '<S60>/F02_NOT' */

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_ctEGRVlvClsInport2' */
  Rte_IrvWrite_RE_InMdlT_012_TEV_InM_ctEGRVlvCls_irv
    (InMdlT_B.InM_ctEGRVlvCls_irv_p);

  /* Switch: '<S375>/Switch' incorporates:
   *  Constant: '<S375>/Byp_Fonction_SC'
   *  Constant: '<S375>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_hv = InM_mEGREstim_B;
  } else {
    localSwitch_hv = InMdlT_B.Merge4;
  }

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstimInport2' */
  Rte_Write_P_InM_mEGREstim_InM_mEGREstim(localSwitch_hv);

  /* Switch: '<S374>/Switch' incorporates:
   *  Constant: '<S374>/Byp_Fonction_SC'
   *  Constant: '<S374>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_gx = InM_mEGREstimLoResl_B;
  } else {
    localTmpSignalConversionAtIn_gx = InMdlT_B.Merge5_j;
  }

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstimLoReslInport2' */
  Rte_Write_P_InM_mEGREstimLoResl_InM_mEGREstimLoResl
    (localTmpSignalConversionAtIn_gx);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mEGREstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_012_TEV_InM_mEGREstimPrev_irv
    (InMdlT_B.InM_mEGREstimPrev_irv_i);

  /* SignalConversion: '<S60>/TmpSignal ConversionAtInM_mGradEGREstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_012_TEV_InM_mGradEGREstim_irv(localSum1_kc);
}

/* Start for exported function: RE_InMdlT_041_MSE */
void RE_InMdlT_041_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S16>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F04_1_InEstimMnfAir_initialization'
   *
   * Block requirements for '<S1>/INM2_F04_1_InEstimMnfAir_initialization':
   *  1. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_033.01 ;
   *  2. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_034.01 ;
   *  3. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_035.01 ;
   *  4. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_361.02 ;
   *  5. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_220.01 ;
   *  6. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  7. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  8. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  9. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_208.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_041_MSE */
void RE_InMdlT_041_MSE(void)
{
  Float32 localDataTypeConversion12_h;
  Float32 localDataTypeConversion7_o;
  UInt16 localTmpSignalConversionAtUsT_c;
  UInt32 localSwitch_as;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S16>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F04_1_InEstimMnfAir_initialization'
   *
   * Block requirements for '<S1>/INM2_F04_1_InEstimMnfAir_initialization':
   *  1. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_033.01 ;
   *  2. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_034.01 ;
   *  3. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_035.01 ;
   *  4. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_361.02 ;
   *  5. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_220.01 ;
   *  6. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  7. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  8. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  9. SubSystem "INM2_F04_1_InEstimMnfAir_initialization" !Trace_To : VEMS_R_11_01067_208.01 ;
   */

  /* SignalConversion: '<S61>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&InMdlT_B.TmpSignalConversionAtUsThrM_p_k);

  /* DataTypeConversion: '<S61>/Data Type Conversion12' */
  localDataTypeConversion12_h = ((Float32)
    InMdlT_B.TmpSignalConversionAtUsThrM_p_k) * 8.0F;

  /* DataTypeConversion: '<S61>/Data Type Conversion7' incorporates:
   *  Constant: '<S61>/InM_facKk2_C'
   */
  localDataTypeConversion7_o = ((Float32)InM_facKk2_C) * 1.862645149E-009F;

  /* SignalConversion: '<S61>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsT_c);

  /* Product: '<S397>/Divide' incorporates:
   *  DataTypeConversion: '<S61>/Data Type Conversion2'
   *  Product: '<S401>/Divide'
   */
  localDataTypeConversion12_h = (localDataTypeConversion12_h *
    localDataTypeConversion7_o) / ((((Float32)localTmpSignalConversionAtUsT_c) *
    0.0078125F) + 223.0F);

  /* Outputs for atomic SubSystem: '<S397>/If Action Subsystem3' */

  /* Switch: '<S403>/Switch1' incorporates:
   *  Constant: '<S403>/Constant1'
   *  Constant: '<S403>/Constant2'
   *  Constant: '<S403>/Constant3'
   *  Logic: '<S403>/Logical Operator1'
   *  RelationalOperator: '<S403>/Relational Operator'
   *  RelationalOperator: '<S403>/Relational Operator1'
   *  RelationalOperator: '<S403>/Relational Operator3'
   */
  if (localDataTypeConversion12_h != localDataTypeConversion12_h) {
    localDataTypeConversion12_h = 1.000000047E-003F;
  }

  /* end of Outputs for SubSystem: '<S397>/If Action Subsystem3' */

  /* SignalConversion: '<S398>/copy' */
  InM_mAirEstimPrev_IRV_MP = localDataTypeConversion12_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S398>/autosar_testpoint1' */

  /* S-Function Block: <S398>/autosar_testpoint1 */

  /* Switch: '<S400>/Switch' incorporates:
   *  Constant: '<S400>/Byp_Fonction_SC'
   *  Constant: '<S400>/Int_BypC'
   *  DataTypeConversion: '<S400>/Data Type Conversion'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_as = InM_mAirEstim_B;
  } else {
    localtmp = localDataTypeConversion12_h;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 29);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        localSwitch_as = (UInt32)localtmp;
      } else {
        localSwitch_as = 0U;
      }
    } else {
      localSwitch_as = MAX_uint32_T;
    }
  }

  /* SignalConversion: '<S61>/TmpSignal ConversionAtInM_mAirEstimInport2' */
  Rte_Write_P_InM_mAirEstim_InM_mAirEstim(localSwitch_as);

  /* SignalConversion: '<S61>/TmpSignal ConversionAtInM_mAirEstimPrev_irvInport2' incorporates:
   *  SignalConversion: '<S61>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_041_MSE_InM_mAirEstimPrev_irv
    (localDataTypeConversion12_h);

  /* SignalConversion: '<S399>/copy' incorporates:
   *  Constant: '<S61>/Constant4'
   */
  InM_mGradAirEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S399>/autosar_testpoint1' */

  /* S-Function Block: <S399>/autosar_testpoint1 */

  /* SignalConversion: '<S61>/TmpSignal ConversionAtInM_mGradAirEstim_irvInport2' incorporates:
   *  Constant: '<S61>/Constant4'
   *  SignalConversion: '<S61>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_InMdlT_041_MSE_InM_mGradAirEstim_irv(0.0F);
}

/* Start for exported function: RE_InMdlT_010_TEV */
void RE_InMdlT_010_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S18>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F04_2_Manifold_air_mass_estimated'
   *
   * Block requirements for '<S1>/INM2_F04_2_Manifold_air_mass_estimated':
   *  1. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_033.01 ;
   *  2. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_034.01 ;
   *  3. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_036.01 ;
   *  4. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_334.03 ;
   *  5. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_220.01 ;
   *  6. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  7. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  8. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  9. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  10. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  11. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_223.01 ;
   *  12. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_221.01 ;
   *  13. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_169.01 ;
   *  14. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  15. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_198.01 ;
   *  16. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  17. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  18. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  19. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  20. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  21. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  22. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  23. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_206.01 ;
   *  24. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  25. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  26. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_189.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_010_TEV */
void RE_InMdlT_010_TEV(void)
{
  /* local block i/o variables */
  Float32 localSwitch1_dl;
  Float32 localDivide_of;
  Float32 localDataTypeConversion12_pk;
  UInt16 localTmpSignalConversionAtExt_b;
  UInt16 localLookUpTable_b;
  Boolean localRelationalOperator_nm;
  Float32 localDivide_lq;
  Boolean localTmpSignalConversionAtEGR_m;
  Boolean localTmpSignalConversionAtInM_d;
  UInt16 localTmpSignalConversionAtUsT_h;
  UInt16 localTmpSignalConversionAtUs_bl;
  UInt8 localTmpSignalConversionAtInM_n;
  UInt16 localTmpSignalConversionAtIn_fl;
  UInt16 localTmpSignalConversionAtIn_br;
  UInt16 localTmpSignalConversionAtIn_oc;
  UInt16 localTmpSignalConversionAtIn_bz;
  UInt32 localTmpSignalConversionAtIn_mr;
  UInt16 localTmpSignalConversionAtInM_i;
  UInt32 localTmpSignalConversionAtIn_ki;
  UInt16 localTmpSignalConversionAtInT_j;
  UInt32 localTmpSignalConversionAtIn_by;
  UInt16 localTmpSignalConversionAtInM_r;
  Float32 localInM_mAirEstimPrev_irv_j;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S18>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F04_2_Manifold_air_mass_estimated'
   *
   * Block requirements for '<S1>/INM2_F04_2_Manifold_air_mass_estimated':
   *  1. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_033.01 ;
   *  2. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_034.01 ;
   *  3. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_036.01 ;
   *  4. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_334.03 ;
   *  5. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_220.01 ;
   *  6. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  7. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  8. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_211.01 ;
   *  9. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  10. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  11. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_223.01 ;
   *  12. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_221.01 ;
   *  13. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_169.01 ;
   *  14. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  15. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_198.01 ;
   *  16. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  17. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  18. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  19. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  20. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  21. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  22. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_192.02 ;
   *  23. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_206.01 ;
   *  24. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  25. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  26. SubSystem "INM2_F04_2_Manifold_air_mass_estimated" !Trace_To : VEMS_R_11_01067_189.01 ;
   */

  /* SignalConversion: '<S62>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&localTmpSignalConversionAtUsT_h);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUs_bl);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&InMdlT_B.TmpSignalConversionAtEng_stEr_p);

  /* RelationalOperator: '<S62>/Relational Operator' incorporates:
   *  Constant: '<S62>/Ext_stRun_SC'
   */
  localRelationalOperator_nm = (InMdlT_B.TmpSignalConversionAtEng_stEr_p ==
    Ext_stRun_SC);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_tiRelax_mTotEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_tiRelax_mTotEstim_INPUT'
   */
  Rte_Read_R_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim
    (&localTmpSignalConversionAtInM_n);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_facRelaxCplMassPresEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_facRelaxCplMassPresEstim_INPUT'
   */
  Rte_Read_R_InM_facRelaxCplMassPresEstim_InM_facRelaxCplMassPresEstim
    (&localTmpSignalConversionAtInM_i);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mfAirCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirCanPurgEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirCanPurgEstim_InM_mfAirCanPurgEstim
    (&localTmpSignalConversionAtIn_br);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mfAirThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&localTmpSignalConversionAtIn_fl);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_bAcceEngOutport2' incorporates:
   *  Inport: '<Root>/InM_bAcceEng_INPUT'
   */
  Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&localTmpSignalConversionAtInM_d);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtEGRVlv_bClnEGRFoulOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bClnEGRFoul'
   */
  Rte_Read_R_EGRVlv_bClnEGRFoul_EGRVlv_bClnEGRFoul
    (&localTmpSignalConversionAtEGR_m);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv_INPUT'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtIn_oc);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mfAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirEstim_InM_mfAirEstim(&localTmpSignalConversionAtIn_bz);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mPrevAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mAirEstim_INPUT'
   */
  Rte_Read_R_InM_mAirEstim_InM_mAirEstim(&localTmpSignalConversionAtIn_mr);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_rAirPresOutport2' incorporates:
   *  Inport: '<Root>/InM_rAirPres_INPUT'
   */
  Rte_Read_R_InM_rAirPres_InM_rAirPres(&localTmpSignalConversionAtInM_r);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim(&localTmpSignalConversionAtIn_ki);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInThM_tMixtInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tMixtInMnf'
   */
  Rte_Read_R_InThM_tMixtInMnf_InThM_tMixtInMnf(&localTmpSignalConversionAtInT_j);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstim_INPUT'
   */
  Rte_Read_R_InM_mEGREstim_InM_mEGREstim(&localTmpSignalConversionAtIn_by);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_b);

  /* If: '<S62>/If' incorporates:
   *  ActionPort: '<S404>/Action Port'
   *  ActionPort: '<S405>/Action Port'
   *  SubSystem: '<S62>/F01_Reset_air_mass'
   *  SubSystem: '<S62>/F02_Calc_estimated_air_mass'
   *
   * Block requirements for '<S62>/F01_Reset_air_mass':
   *  1. SubSystem "F01_Reset_air_mass" !Trace_To : VEMS_R_11_01067_037.01 ;
   *
   * Block requirements for '<S62>/F02_Calc_estimated_air_mass':
   *  1. SubSystem "F02_Calc_estimated_air_mass" !Trace_To : VEMS_R_11_01067_038.01 ;
   */
  if (localRelationalOperator_nm) {
    /* Outputs for atomic SubSystem: '<S405>/F01_Calc_air_mass_relaxation_term' *
     * Block requirements for '<S405>/F01_Calc_air_mass_relaxation_term':
     *  1. SubSystem "F01_Calc_air_mass_relaxation_term" !Trace_To : VEMS_R_11_01067_039.01 ;
     */

    /* DataTypeConversion: '<S414>/Data Type Conversion1' */
    InM_tiRelax_mAirEstim = ((Float32)localTmpSignalConversionAtInM_n) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S405>/F01_Calc_air_mass_relaxation_term' */

    /* Outputs for atomic SubSystem: '<S405>/F02_Diff_air_mass' *
     * Block requirements for '<S405>/F02_Diff_air_mass':
     *  1. SubSystem "F02_Diff_air_mass" !Trace_To : VEMS_R_11_01067_040.01 ;
     */

    /* Switch: '<S415>/Switch1' incorporates:
     *  Constant: '<S415>/Constant6'
     *  DataTypeConversion: '<S415>/Data Type Conversion12'
     */
    if (localTmpSignalConversionAtEGR_m) {
      localDivide_lq = ((Float32)localTmpSignalConversionAtIn_oc) *
        1.525878906E-005F;
    } else {
      localDivide_lq = 0.0F;
    }

    /* Sum: '<S415>/Sum1' incorporates:
     *  DataTypeConversion: '<S415>/Data Type Conversion3'
     *  DataTypeConversion: '<S415>/Data Type Conversion4'
     *  DataTypeConversion: '<S415>/Data Type Conversion5'
     */
    localDivide_lq = (((((Float32)localTmpSignalConversionAtIn_fl) *
                        1.525878906E-005F) + (((Float32)
      localTmpSignalConversionAtIn_br) * 9.536743164E-007F)) + localDivide_lq) -
      (((Float32)localTmpSignalConversionAtIn_bz) * 1.525878906E-005F);

    /* Product: '<S418>/Product4' incorporates:
     *  Constant: '<S418>/offset'
     *  Constant: '<S418>/one_on_slope'
     *  Sum: '<S418>/Add1'
     */
    localInM_mAirEstimPrev_irv_j = 65536.0F * localDivide_lq;

    /* Switch: '<S418>/Switch1' incorporates:
     *  Constant: '<S418>/offset2'
     *  Constant: '<S418>/offset3'
     *  Constant: '<S418>/offset4'
     *  RelationalOperator: '<S418>/Relational Operator'
     *  Sum: '<S418>/Add3'
     *  Sum: '<S418>/Add4'
     */
    if (localInM_mAirEstimPrev_irv_j >= 0.0F) {
      localInM_mAirEstimPrev_irv_j += 0.5F;
    } else {
      localInM_mAirEstimPrev_irv_j -= 0.5F;
    }

    /* DataStoreWrite: '<S415>/Data Store Write2' incorporates:
     *  DataTypeConversion: '<S418>/OutDTConv'
     */
    if (localInM_mAirEstimPrev_irv_j < 32768.0F) {
      if (localInM_mAirEstimPrev_irv_j >= -32768.0F) {
        InM_mGradAirEstimRaw_MP = (SInt16)localInM_mAirEstimPrev_irv_j;
      } else {
        InM_mGradAirEstimRaw_MP = MIN_int16_T;
      }
    } else {
      InM_mGradAirEstimRaw_MP = MAX_int16_T;
    }

    /* Switch: '<S415>/Switch' incorporates:
     *  Constant: '<S415>/Constant3'
     *  Constant: '<S415>/InM_rKk2_C'
     *  DataTypeConversion: '<S415>/Data Type Conversion2'
     */
    if (localTmpSignalConversionAtInM_d) {
      localInM_mAirEstimPrev_irv_j = 1.0F;
    } else {
      localInM_mAirEstimPrev_irv_j = ((Float32)InM_rKk2_C) * 0.00390625F;
    }

    /* Product: '<S420>/Divide' */
    localDivide_of = localDivide_lq * localInM_mAirEstimPrev_irv_j;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S419>/autosar_testpoint1' */

    /* S-Function Block: <S419>/autosar_testpoint1 */
    InM_mGradAirEstim_IRV_MP = localDivide_of;

    /* end of Outputs for SubSystem: '<S405>/F02_Diff_air_mass' */

    /* Outputs for atomic SubSystem: '<S405>/F03_Calc_air_mass_integration' *
     * Block requirements for '<S405>/F03_Calc_air_mass_integration':
     *  1. SubSystem "F03_Calc_air_mass_integration" !Trace_To : VEMS_R_11_01067_041.01 ;
     */

    /* DataTypeConversion: '<S416>/Data Type Conversion12' */
    localDataTypeConversion12_pk = ((Float32)localTmpSignalConversionAtIn_mr) *
      1.862645149E-009F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S421>/autosar_testpoint1' */

    /* S-Function Block: <S421>/autosar_testpoint1 */
    InM_mAirEstimPrev_IRV_MP = localDataTypeConversion12_pk;

    /* SignalConversion: '<S416>/Signal Conversion2' */
    localInM_mAirEstimPrev_irv_j = localDataTypeConversion12_pk;

    /* Sum: '<S416>/Sum' incorporates:
     *  DataTypeConversion: '<S416>/Data Type Conversion4'
     *  Product: '<S422>/Divide'
     *  Product: '<S423>/Divide'
     *  SignalConversion: '<S62>/TmpSignal ConversionAtInM_pGradDsThrEstim_irvOutport2'
     */
    InM_mAirEstimInt = ((localDivide_of * InM_tiRelax_mAirEstim) +
                        localDataTypeConversion12_pk) - ((((Float32)
      localTmpSignalConversionAtInM_i) * 9.094947018E-013F) *
      Rte_IrvRead_RE_InMdlT_010_TEV_InM_pGradDsThrEstim_irv());

    /* end of Outputs for SubSystem: '<S405>/F03_Calc_air_mass_integration' */

    /* Outputs for atomic SubSystem: '<S405>/F04_Air_mass_calc_switch' *
     * Block requirements for '<S405>/F04_Air_mass_calc_switch':
     *  1. SubSystem "F04_Air_mass_calc_switch" !Trace_To : VEMS_R_11_01067_042.01 ;
     */

    /* Product: '<S427>/Divide' incorporates:
     *  Constant: '<S417>/InM_facKk2_C'
     *  DataTypeConversion: '<S417>/Data Type Conversion'
     *  DataTypeConversion: '<S417>/Data Type Conversion1'
     *  DataTypeConversion: '<S417>/Data Type Conversion12'
     *  Product: '<S428>/Divide'
     */
    localDivide_lq = ((((Float32)localTmpSignalConversionAtIn_ki) * 0.0078125F)
                      * (((Float32)InM_facKk2_C) * 1.862645149E-009F)) /
      ((((Float32)localTmpSignalConversionAtInT_j) * 0.0078125F) + 223.0F);

    /* Outputs for atomic SubSystem: '<S427>/If Action Subsystem3' */

    /* Switch: '<S430>/Switch1' incorporates:
     *  Constant: '<S430>/Constant1'
     *  Constant: '<S430>/Constant2'
     *  Constant: '<S430>/Constant3'
     *  Logic: '<S430>/Logical Operator1'
     *  RelationalOperator: '<S430>/Relational Operator'
     *  RelationalOperator: '<S430>/Relational Operator1'
     *  RelationalOperator: '<S430>/Relational Operator3'
     */
    if (localDivide_lq != localDivide_lq) {
      localDivide_lq = 1.000000047E-003F;
    }

    /* end of Outputs for SubSystem: '<S427>/If Action Subsystem3' */

    /* Sum: '<S417>/Add' incorporates:
     *  DataTypeConversion: '<S417>/Data Type Conversion2'
     *  SignalConversion: '<S62>/TmpSignal ConversionAtInM_mFuStmEstim_irvOutport2'
     */
    localDivide_lq = (localDivide_lq - (((Float32)
      localTmpSignalConversionAtIn_by) * 1.862645149E-009F)) -
      Rte_IrvRead_RE_InMdlT_010_TEV_InM_mFuStmEstim_irv();

    /* MinMax: '<S417>/MinMax' incorporates:
     *  Constant: '<S417>/Constant2'
     */
    localDivide_lq = rt_MAXf(localDivide_lq, 0.0F);

    /* DataStoreWrite: '<S417>/Data Store Write2' incorporates:
     *  Constant: '<S426>/offset'
     *  Constant: '<S426>/offset1'
     *  Constant: '<S426>/one_on_slope'
     *  DataTypeConversion: '<S426>/OutDTConv'
     *  Product: '<S426>/Product4'
     *  Sum: '<S426>/Add1'
     *  Sum: '<S426>/Add2'
     */
    localtmp = (5.36870912E+008F * localDivide_lq) + 0.5F;
    if (localtmp < 4.294967296E+009F) {
      InM_mAirEstimPres_MP = (UInt32)localtmp;
    } else {
      InM_mAirEstimPres_MP = MAX_uint32_T;
    }

    /* Lookup: '<S424>/Look-Up Table'
     * About '<S424>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_b), (&(InM_rAirPresFullLd_T[0])),
                   localTmpSignalConversionAtExt_b, (&(Ext_nEngRef2_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S424>/Data Type Duplicate1'
     *
     * Regarding '<S424>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Switch: '<S417>/Switch' incorporates:
     *  Lookup: '<S424>/Look-Up Table'
     *  RelationalOperator: '<S417>/Relational Operator'
     */
    if (!(localTmpSignalConversionAtInM_r > localLookUpTable_b)) {
      localDivide_lq = InM_mAirEstimInt;
    }

    /* DataTypeConversion: '<S425>/OutDTConv' incorporates:
     *  Constant: '<S425>/offset'
     *  Constant: '<S425>/offset1'
     *  Constant: '<S425>/one_on_slope'
     *  Product: '<S425>/Product4'
     *  Sum: '<S425>/Add1'
     *  Sum: '<S425>/Add2'
     */
    localDivide_lq = (5.36870912E+008F * localDivide_lq) + 0.5F;
    if (localDivide_lq < 4.294967296E+009F) {
      if (localDivide_lq >= 0.0F) {
        localTmpSignalConversionAtIn_mr = (UInt32)localDivide_lq;
      } else {
        localTmpSignalConversionAtIn_mr = 0U;
      }
    } else {
      localTmpSignalConversionAtIn_mr = MAX_uint32_T;
    }

    /* end of Outputs for SubSystem: '<S405>/F04_Air_mass_calc_switch' */

    /* SignalConversion: '<S405>/Signal Conversion2' */
    localDivide_lq = localDivide_of;
  } else {
    /* Product: '<S408>/Divide' incorporates:
     *  Constant: '<S404>/InM_facKk2_C'
     *  DataTypeConversion: '<S404>/Data Type Conversion12'
     *  DataTypeConversion: '<S404>/Data Type Conversion2'
     *  DataTypeConversion: '<S404>/Data Type Conversion6'
     *  Product: '<S411>/Divide'
     */
    localDivide_lq = ((((Float32)localTmpSignalConversionAtUsT_h) * 8.0F) *
                      (((Float32)InM_facKk2_C) * 1.862645149E-009F)) /
      ((((Float32)localTmpSignalConversionAtUs_bl) * 0.0078125F) + 223.0F);

    /* Outputs for atomic SubSystem: '<S408>/If Action Subsystem3' */

    /* Switch: '<S413>/Switch1' incorporates:
     *  Constant: '<S413>/Constant1'
     *  Constant: '<S413>/Constant2'
     *  Constant: '<S413>/Constant3'
     *  Logic: '<S413>/Logical Operator1'
     *  RelationalOperator: '<S413>/Relational Operator'
     *  RelationalOperator: '<S413>/Relational Operator1'
     *  RelationalOperator: '<S413>/Relational Operator3'
     */
    if (localDivide_lq != localDivide_lq) {
      localSwitch1_dl = 1.000000047E-003F;
    } else {
      localSwitch1_dl = localDivide_lq;
    }

    /* end of Outputs for SubSystem: '<S408>/If Action Subsystem3' */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S409>/autosar_testpoint1' */

    /* S-Function Block: <S409>/autosar_testpoint1 */
    InM_mAirEstimPrev_IRV_MP = localSwitch1_dl;

    /* SignalConversion: '<S404>/Signal Conversion3' */
    localInM_mAirEstimPrev_irv_j = localSwitch1_dl;

    /* DataTypeConversion: '<S407>/OutDTConv' incorporates:
     *  Constant: '<S407>/offset'
     *  Constant: '<S407>/offset1'
     *  Constant: '<S407>/one_on_slope'
     *  Product: '<S407>/Product4'
     *  Sum: '<S407>/Add1'
     *  Sum: '<S407>/Add2'
     */
    localDivide_lq = (5.36870912E+008F * localSwitch1_dl) + 0.5F;
    if (localDivide_lq < 4.294967296E+009F) {
      if (localDivide_lq >= 0.0F) {
        localTmpSignalConversionAtIn_mr = (UInt32)localDivide_lq;
      } else {
        localTmpSignalConversionAtIn_mr = 0U;
      }
    } else {
      localTmpSignalConversionAtIn_mr = MAX_uint32_T;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S410>/autosar_testpoint1' incorporates:
     *  Constant: '<S404>/Constant4'
     */

    /* S-Function Block: <S410>/autosar_testpoint1 */
    InM_mGradAirEstim_IRV_MP = 0.0F;

    /* SignalConversion: '<S404>/Signal Conversion4' incorporates:
     *  Constant: '<S404>/Constant4'
     */
    localDivide_lq = 0.0F;
  }

  /* Switch: '<S406>/Switch' incorporates:
   *  Constant: '<S406>/Byp_Fonction_SC'
   *  Constant: '<S406>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_mr = InM_mAirEstim_B;
  }

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mAirEstimInport2' */
  Rte_Write_P_InM_mAirEstim_InM_mAirEstim(localTmpSignalConversionAtIn_mr);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mAirEstimPrev_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_010_TEV_InM_mAirEstimPrev_irv
    (localInM_mAirEstimPrev_irv_j);

  /* SignalConversion: '<S62>/TmpSignal ConversionAtInM_mGradAirEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_010_TEV_InM_mGradAirEstim_irv(localDivide_lq);
}

/* Start for exported function: RE_InMdlT_047_MSE */
void RE_InMdlT_047_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S19>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F05_1_Init_concentration1'
   *
   * Block requirements for '<S1>/INM2_F05_1_Init_concentration1':
   *  1. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_139.01 ;
   *  4. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_367.01 ;
   *  5. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_282.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_047_MSE */
void RE_InMdlT_047_MSE(void)
{
  UInt16 localSwitch_iu;

  /* S-Function (fcncallgen): '<S19>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F05_1_Init_concentration1'
   *
   * Block requirements for '<S1>/INM2_F05_1_Init_concentration1':
   *  1. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_139.01 ;
   *  4. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_367.01 ;
   *  5. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_1_Init_concentration1" !Trace_To : VEMS_R_11_01067_282.02 ;
   */

  /* Switch: '<S435>/Switch' incorporates:
   *  Constant: '<S435>/Byp_Fonction_SC'
   *  Constant: '<S435>/Int_BypC'
   *  Constant: '<S63>/Constant2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_iu = InM_concEGREstim_B;
  } else {
    localSwitch_iu = 0U;
  }

  /* SignalConversion: '<S63>/TmpSignal ConversionAtInM_concEGREstimInport2' */
  Rte_Write_P_InM_concEGREstim_InM_concEGREstim(localSwitch_iu);

  /* SignalConversion: '<S433>/copy' incorporates:
   *  Constant: '<S63>/Constant3'
   */
  InM_concAirEstim_IRV_MP = 1.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S433>/autosar_testpoint1' */

  /* S-Function Block: <S433>/autosar_testpoint1 */

  /* SignalConversion: '<S63>/TmpSignal ConversionAtInM_concAirEstim_irvInport2' incorporates:
   *  Constant: '<S63>/Constant3'
   *  SignalConversion: '<S63>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_047_MSE_InM_concAirEstim_irv(1.0F);

  /* SignalConversion: '<S434>/copy' incorporates:
   *  Constant: '<S63>/Constant1'
   */
  InM_concFuStmEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S434>/autosar_testpoint1' */

  /* S-Function Block: <S434>/autosar_testpoint1 */

  /* SignalConversion: '<S63>/TmpSignal ConversionAtInM_concFuStmEstim_irvInport2' incorporates:
   *  Constant: '<S63>/Constant1'
   *  SignalConversion: '<S63>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_InMdlT_047_MSE_InM_concFuStmEstim_irv(0.0F);

  /* SignalConversion: '<S432>/copy' incorporates:
   *  Constant: '<S63>/Constant5'
   */
  InM_concFuStmRaw_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S432>/autosar_testpoint1' */

  /* S-Function Block: <S432>/autosar_testpoint1 */

  /* SignalConversion: '<S63>/TmpSignal ConversionAtInM_concFuStmRaw_irvInport2' incorporates:
   *  Constant: '<S63>/Constant5'
   *  SignalConversion: '<S63>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_047_MSE_InM_concFuStmRaw_irv(0.0F);

  /* SignalConversion: '<S431>/copy' incorporates:
   *  Constant: '<S63>/Constant4'
   */
  InM_concAirRaw_IRV_MP = 1.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S431>/autosar_testpoint1' */

  /* S-Function Block: <S431>/autosar_testpoint1 */

  /* SignalConversion: '<S63>/TmpSignal ConversionAtInM_concAirRaw_irvInport2' incorporates:
   *  Constant: '<S63>/Constant4'
   *  SignalConversion: '<S63>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_InMdlT_047_MSE_InM_concAirRaw_irv(1.0F);
}

/* Start for exported function: RE_InMdlT_015_DRE */
void RE_InMdlT_015_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S20>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F05_2_Init_concentration'
   *
   * Block requirements for '<S1>/INM2_F05_2_Init_concentration':
   *  1. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_139.01 ;
   *  4. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_338.01 ;
   *  5. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_282.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_015_DRE */
void RE_InMdlT_015_DRE(void)
{
  UInt16 localSwitch_a1;

  /* S-Function (fcncallgen): '<S20>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F05_2_Init_concentration'
   *
   * Block requirements for '<S1>/INM2_F05_2_Init_concentration':
   *  1. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_139.01 ;
   *  4. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_338.01 ;
   *  5. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_2_Init_concentration" !Trace_To : VEMS_R_11_01067_282.02 ;
   */

  /* Switch: '<S440>/Switch' incorporates:
   *  Constant: '<S440>/Byp_Fonction_SC'
   *  Constant: '<S440>/Int_BypC'
   *  Constant: '<S64>/Constant2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_a1 = InM_concEGREstim_B;
  } else {
    localSwitch_a1 = 0U;
  }

  /* SignalConversion: '<S64>/TmpSignal ConversionAtInM_concEGREstimInport2' */
  Rte_Write_P_InM_concEGREstim_InM_concEGREstim(localSwitch_a1);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S438>/autosar_testpoint1' incorporates:
   *  Constant: '<S64>/Constant3'
   */

  /* S-Function Block: <S438>/autosar_testpoint1 */
  InM_concAirEstim_IRV_MP = 1.0F;

  /* SignalConversion: '<S64>/TmpSignal ConversionAtInM_concAirEstim_irvInport2' incorporates:
   *  Constant: '<S64>/Constant3'
   *  SignalConversion: '<S64>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_015_DRE_InM_concAirEstim_irv(1.0F);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S439>/autosar_testpoint1' incorporates:
   *  Constant: '<S64>/Constant1'
   */

  /* S-Function Block: <S439>/autosar_testpoint1 */
  InM_concFuStmEstim_IRV_MP = 0.0F;

  /* SignalConversion: '<S64>/TmpSignal ConversionAtInM_concFuStmEstim_irvInport2' incorporates:
   *  Constant: '<S64>/Constant1'
   *  SignalConversion: '<S64>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_InMdlT_015_DRE_InM_concFuStmEstim_irv(0.0F);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S437>/autosar_testpoint1' incorporates:
   *  Constant: '<S64>/Constant5'
   */

  /* S-Function Block: <S437>/autosar_testpoint1 */
  InM_concFuStmRaw_IRV_MP = 0.0F;

  /* SignalConversion: '<S64>/TmpSignal ConversionAtInM_concFuStmRaw_irvInport2' incorporates:
   *  Constant: '<S64>/Constant5'
   *  SignalConversion: '<S64>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_015_DRE_InM_concFuStmRaw_irv(0.0F);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S436>/autosar_testpoint1' incorporates:
   *  Constant: '<S64>/Constant4'
   */

  /* S-Function Block: <S436>/autosar_testpoint1 */
  InM_concAirRaw_IRV_MP = 1.0F;

  /* SignalConversion: '<S64>/TmpSignal ConversionAtInM_concAirRaw_irvInport2' incorporates:
   *  Constant: '<S64>/Constant4'
   *  SignalConversion: '<S64>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_InMdlT_015_DRE_InM_concAirRaw_irv(1.0F);
}

/* Start for exported function: RE_InMdlT_014_TEV */
void RE_InMdlT_014_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S21>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F05_3Etat_collecteur'
   *
   * Block requirements for '<S1>/INM2_F05_3Etat_collecteur':
   *  1. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_140.01 ;
   *  4. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_337.02 ;
   *  5. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  10. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  11. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  12. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_230.01 ;
   *  13. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  14. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  15. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  16. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  17. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_198.01 ;
   *  18. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  19. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  20. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  21. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_227.01 ;
   *  22. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  23. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_300.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_014_TEV */
void RE_InMdlT_014_TEV(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion2_m;
  Float32 localSwitch1_ek;
  Float32 localSwitch1_i;
  Float32 localSum_b;
  Float32 localSwitch2_i;
  Float32 localcopy_e;
  Float32 localSwitch2_k;
  Float32 localDataTypeConversion1_j;
  Float32 localTmpSignalConversionAtInM_l;
  Float32 localMerge_h;
  Float32 localInM_concFuStmEstim_irv_o;
  Float32 localDivide_kp;
  Boolean localTmpSignalConversionAtEGR_k;
  UInt32 localTmpSignalConversionAtIn_ob;
  UInt32 localTmpSignalConversionAtIn_bp;
  UInt16 localTmpSignalConversionAtIn_ni;

  /* S-Function (fcncallgen): '<S21>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F05_3Etat_collecteur'
   *
   * Block requirements for '<S1>/INM2_F05_3Etat_collecteur':
   *  1. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_137.01 ;
   *  2. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_138.01 ;
   *  3. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_140.01 ;
   *  4. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_337.02 ;
   *  5. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_229.01 ;
   *  6. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  7. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  8. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  9. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  10. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  11. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  12. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_230.01 ;
   *  13. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  14. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  15. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_222.01 ;
   *  16. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  17. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_198.01 ;
   *  18. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_325.02 ;
   *  19. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  20. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  21. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_227.01 ;
   *  22. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  23. SubSystem "INM2_F05_3Etat_collecteur" !Trace_To : VEMS_R_11_01067_300.02 ;
   */

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_mEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstim_INPUT'
   */
  Rte_Read_R_InM_mEGREstim_InM_mEGREstim(&localTmpSignalConversionAtIn_ob);

  /* DataTypeConversion: '<S65>/Data Type Conversion1' */
  localDataTypeConversion1_j = ((Float32)localTmpSignalConversionAtIn_ob) *
    1.862645149E-009F;

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_mAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mAirEstim_INPUT'
   */
  Rte_Read_R_InM_mAirEstim_InM_mAirEstim(&localTmpSignalConversionAtIn_bp);

  /* DataTypeConversion: '<S65>/Data Type Conversion2' */
  localDataTypeConversion2_m = ((Float32)localTmpSignalConversionAtIn_bp) *
    1.862645149E-009F;

  /* SignalConversion: '<S65>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&InMdlT_B.TmpSignalConversionAtEng_stEr_d);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_mFuStmEstim_irvOutport2' */
  localTmpSignalConversionAtInM_l =
    Rte_IrvRead_RE_InMdlT_014_TEV_InM_mFuStmEstim_irv();

  /* Outputs for atomic SubSystem: '<S65>/F01_Calc_manifold_total_mass_estimated' *
   * Block requirements for '<S65>/F01_Calc_manifold_total_mass_estimated':
   *  1. SubSystem "F01_Calc_manifold_total_mass_estimated" !Trace_To : VEMS_R_11_01067_141.01 ;
   */

  /* If: '<S441>/If' incorporates:
   *  ActionPort: '<S444>/Action Port'
   *  ActionPort: '<S445>/Action Port'
   *  Constant: '<S441>/Ext_stRun_SC'
   *  RelationalOperator: '<S441>/Relational Operator'
   *  SubSystem: '<S441>/F01_Reset_manifold_state'
   *  SubSystem: '<S441>/F02_Calc_total_mass_estimated'
   *
   * Block requirements for '<S441>/F01_Reset_manifold_state':
   *  1. SubSystem "F01_Reset_manifold_state" !Trace_To : VEMS_R_11_01067_142.01 ;
   *
   * Block requirements for '<S441>/F02_Calc_total_mass_estimated':
   *  1. SubSystem "F02_Calc_total_mass_estimated" !Trace_To : VEMS_R_11_01067_143.01 ;
   */
  if (InMdlT_B.TmpSignalConversionAtEng_stEr_d == Ext_stRun_SC) {
    /* Sum: '<S445>/Sum' */
    localSum_b = (localDataTypeConversion2_m + localTmpSignalConversionAtInM_l)
      + localDataTypeConversion1_j;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S447>/autosar_testpoint1' */

    /* S-Function Block: <S447>/autosar_testpoint1 */
    InM_mTotEstim_IRV_MP = localSum_b;

    /* SignalConversion: '<S445>/Signal Conversion' */
    localMerge_h = localSum_b;
  } else {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S446>/autosar_testpoint1' */
    /* S-Function Block: <S446>/autosar_testpoint1 */
    InM_mTotEstim_IRV_MP = localDataTypeConversion2_m;

    /* SignalConversion: '<S444>/Signal Conversion' */
    localMerge_h = localDataTypeConversion2_m;
  }

  /* end of Outputs for SubSystem: '<S65>/F01_Calc_manifold_total_mass_estimated' */

  /* SignalConversion: '<S65>/TmpSignal ConversionAtEGRVlv_bClnEGRFoulOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_bClnEGRFoul'
   */
  Rte_Read_R_EGRVlv_bClnEGRFoul_EGRVlv_bClnEGRFoul
    (&localTmpSignalConversionAtEGR_k);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv_INPUT'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&InMdlT_B.TmpSignalConversionAtInM_mfEGRE);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor
    (&InMdlT_B.TmpSignalConversionAtEngM_mfTot);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concAirEstim_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_f =
    Rte_IrvRead_RE_InMdlT_014_TEV_InM_concAirEstim_irv();

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concFuStmEstim_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_o =
    Rte_IrvRead_RE_InMdlT_014_TEV_InM_concFuStmEstim_irv();

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concEGREstim1Outport2' incorporates:
   *  Inport: '<Root>/InM_concEGREstim_INPUT'
   */
  Rte_Read_R_InM_concEGREstim_InM_concEGREstim(&localTmpSignalConversionAtIn_ni);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concAirRaw_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_con_fs =
    Rte_IrvRead_RE_InMdlT_014_TEV_InM_concAirRaw_irv();

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concFuStmRaw_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_c =
    Rte_IrvRead_RE_InMdlT_014_TEV_InM_concFuStmRaw_irv();

  /* SignalConversion: '<S65>/TmpSignal ConversionAtBlby_mfFuStmCmpAirSysOutport2' incorporates:
   *  Inport: '<Root>/Blby_mfFuStmCmpAirSys'
   */
  Rte_Read_R_Blby_mfFuStmCmpAirSys_Blby_mfFuStmCmpAirSys
    (&InMdlT_B.TmpSignalConversionAtBlby_mfFuS);

  /* Outputs for atomic SubSystem: '<S65>/F02_Calc_concentration_estimated' *
   * Block requirements for '<S65>/F02_Calc_concentration_estimated':
   *  1. SubSystem "F02_Calc_concentration_estimated" !Trace_To : VEMS_R_11_01067_144.01 ;
   */

  /* Outputs for enable SubSystem: '<S442>/F01_Calc_concentration' incorporates:
   *  Constant: '<S442>/Ext_stRun_SC'
   *  EnablePort: '<S448>/NS_bRun'
   *  EnablePort: '<S449>/NS_bRun'
   *  Logic: '<S442>/NAN'
   *  RelationalOperator: '<S442>/Relational Operator'
   *  SubSystem: '<S442>/F02_NOT'
   *
   * Block requirements for '<S442>/F01_Calc_concentration':
   *  1. SubSystem "F01_Calc_concentration" !Trace_To : VEMS_R_11_01067_145.01 ;
   */
  if (InMdlT_B.TmpSignalConversionAtEng_stEr_d == Ext_stRun_SC) {
    /* Outputs for atomic SubSystem: '<S448>/F02_Calc_fuel_vap_comcentration' *
     * Block requirements for '<S448>/F02_Calc_fuel_vap_comcentration':
     *  1. SubSystem "F02_Calc_fuel_vap_comcentration" !Trace_To : VEMS_R_11_01067_147.01 ;
     */

    /* Product: '<S459>/Divide' */
    localTmpSignalConversionAtInM_l /= localMerge_h;

    /* Outputs for atomic SubSystem: '<S459>/If Action Subsystem3' */

    /* Switch: '<S462>/Switch1' incorporates:
     *  Constant: '<S462>/Constant1'
     *  Constant: '<S462>/Constant2'
     *  Constant: '<S462>/Constant3'
     *  Logic: '<S462>/Logical Operator1'
     *  RelationalOperator: '<S462>/Relational Operator'
     *  RelationalOperator: '<S462>/Relational Operator1'
     *  RelationalOperator: '<S462>/Relational Operator3'
     */
    if (((localTmpSignalConversionAtInM_l != localTmpSignalConversionAtInM_l) ||
         (localTmpSignalConversionAtInM_l > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localTmpSignalConversionAtInM_l)) {
      localSwitch1_ek = 0.0F;
    } else {
      localSwitch1_ek = localTmpSignalConversionAtInM_l;
    }

    /* end of Outputs for SubSystem: '<S459>/If Action Subsystem3' */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S460>/autosar_testpoint1' */

    /* S-Function Block: <S460>/autosar_testpoint1 */
    InM_concFuStmEstim_IRV_MP = localSwitch1_ek;

    /* end of Outputs for SubSystem: '<S448>/F02_Calc_fuel_vap_comcentration' */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S454>/autosar_testpoint1' */

    /* S-Function Block: <S454>/autosar_testpoint1 */
    InM_concFuStmEstim_IRV_MP = localSwitch1_ek;

    /* Outputs for atomic SubSystem: '<S448>/F01_Calc_air_concentration' *
     * Block requirements for '<S448>/F01_Calc_air_concentration':
     *  1. SubSystem "F01_Calc_air_concentration" !Trace_To : VEMS_R_11_01067_146.01 ;
     */

    /* Product: '<S456>/Divide' */
    localTmpSignalConversionAtInM_l = localDataTypeConversion2_m / localMerge_h;

    /* Outputs for atomic SubSystem: '<S456>/If Action Subsystem3' */

    /* Switch: '<S458>/Switch1' incorporates:
     *  Constant: '<S458>/Constant1'
     *  Constant: '<S458>/Constant2'
     *  Constant: '<S458>/Constant3'
     *  Logic: '<S458>/Logical Operator1'
     *  RelationalOperator: '<S458>/Relational Operator'
     *  RelationalOperator: '<S458>/Relational Operator1'
     *  RelationalOperator: '<S458>/Relational Operator3'
     */
    if (((localTmpSignalConversionAtInM_l != localTmpSignalConversionAtInM_l) ||
         (localTmpSignalConversionAtInM_l > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localTmpSignalConversionAtInM_l)) {
      localSwitch1_i = 1.0F;
    } else {
      localSwitch1_i = localTmpSignalConversionAtInM_l;
    }

    /* end of Outputs for SubSystem: '<S456>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S448>/F01_Calc_air_concentration' */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S455>/autosar_testpoint1' */

    /* S-Function Block: <S455>/autosar_testpoint1 */
    InM_concAirEstim_IRV_MP = localSwitch1_i;

    /* Outputs for atomic SubSystem: '<S448>/F03_Calc_egr_concentration' *
     * Block requirements for '<S448>/F03_Calc_egr_concentration':
     *  1. SubSystem "F03_Calc_egr_concentration" !Trace_To : VEMS_R_11_01067_148.01 ;
     */

    /* Product: '<S464>/Divide' */
    localTmpSignalConversionAtInM_l = localDataTypeConversion1_j / localMerge_h;

    /* Outputs for atomic SubSystem: '<S464>/If Action Subsystem3' */

    /* Switch: '<S466>/Switch1' incorporates:
     *  Constant: '<S466>/Constant1'
     *  Constant: '<S466>/Constant2'
     *  Constant: '<S466>/Constant3'
     *  Logic: '<S466>/Logical Operator1'
     *  RelationalOperator: '<S466>/Relational Operator'
     *  RelationalOperator: '<S466>/Relational Operator1'
     *  RelationalOperator: '<S466>/Relational Operator3'
     */
    if (((localTmpSignalConversionAtInM_l != localTmpSignalConversionAtInM_l) ||
         (localTmpSignalConversionAtInM_l > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localTmpSignalConversionAtInM_l)) {
      localTmpSignalConversionAtInM_l = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S464>/If Action Subsystem3' */

    /* DataTypeConversion: '<S463>/OutDTConv' incorporates:
     *  Constant: '<S463>/offset'
     *  Constant: '<S463>/offset1'
     *  Constant: '<S463>/one_on_slope'
     *  Product: '<S463>/Product4'
     *  Sum: '<S463>/Add1'
     *  Sum: '<S463>/Add2'
     */
    localDataTypeConversion1_j = (65536.0F * localTmpSignalConversionAtInM_l) +
      0.5F;
    if (localDataTypeConversion1_j < 65536.0F) {
      if (localDataTypeConversion1_j >= 0.0F) {
        InMdlT_B.Merge3_l = (UInt16)localDataTypeConversion1_j;
      } else {
        InMdlT_B.Merge3_l = 0U;
      }
    } else {
      InMdlT_B.Merge3_l = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S448>/F03_Calc_egr_concentration' */

    /* SignalConversion: '<S448>/Signal Conversion1' */
    localInM_concFuStmEstim_irv_o = localSwitch1_ek;

    /* SignalConversion: '<S448>/Signal Conversion3' */
    localDataTypeConversion1_j = localSwitch1_i;

    /* Outputs for atomic SubSystem: '<S448>/F04_Calc_raw_air_concentration' *
     * Block requirements for '<S448>/F04_Calc_raw_air_concentration':
     *  1. SubSystem "F04_Calc_raw_air_concentration" !Trace_To : VEMS_R_11_01067_149.01 ;
     */

    /* Sum: '<S453>/Sum1' incorporates:
     *  DataTypeConversion: '<S453>/Data Type Conversion2'
     *  SignalConversion: '<S65>/TmpSignal ConversionAtInM_mfFuStmCanPurgEstim_irvOutport2'
     */
    localTmpSignalConversionAtInM_l = (((Float32)
      InMdlT_B.TmpSignalConversionAtBlby_mfFuS) * 1.192092896E-007F) +
      Rte_IrvRead_RE_InMdlT_014_TEV_InM_mfFuStmCanPurgEstim_irv();

    /* DataTypeConversion: '<S453>/Data Type Conversion6' */
    localSwitch2_i = ((Float32)InMdlT_B.TmpSignalConversionAtEngM_mfTot) *
      1.525878906E-005F;

    /* Product: '<S471>/Divide' */
    localDivide_kp = localTmpSignalConversionAtInM_l / localSwitch2_i;

    /* Outputs for atomic SubSystem: '<S471>/If Action Subsystem3' */

    /* Switch: '<S482>/Switch1' incorporates:
     *  Constant: '<S482>/Constant1'
     *  Constant: '<S482>/Constant2'
     *  Constant: '<S482>/Constant3'
     *  Logic: '<S482>/Logical Operator1'
     *  RelationalOperator: '<S482>/Relational Operator'
     *  RelationalOperator: '<S482>/Relational Operator1'
     *  RelationalOperator: '<S482>/Relational Operator3'
     */
    if (((localDivide_kp != localDivide_kp) || (localDivide_kp >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_kp)) {
      localDivide_kp = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S471>/If Action Subsystem3' */

    /* Sum: '<S469>/Add2' incorporates:
     *  Constant: '<S469>/offset'
     *  Constant: '<S469>/offset1'
     *  Constant: '<S469>/one_on_slope'
     *  Product: '<S469>/Product4'
     *  Sum: '<S469>/Add1'
     */
    localSwitch2_k = (65536.0F * localDivide_kp) + 0.5F;

    /* DataStoreWrite: '<S453>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S469>/OutDTConv'
     */
    if (localSwitch2_k < 65536.0F) {
      if (localSwitch2_k >= 0.0F) {
        InM_concFuStmRawNoSat_MP = (UInt16)localSwitch2_k;
      } else {
        InM_concFuStmRawNoSat_MP = 0U;
      }
    } else {
      InM_concFuStmRawNoSat_MP = MAX_uint16_T;
    }

    /* Switch: '<S453>/Switch1' incorporates:
     *  Constant: '<S453>/Constant6'
     *  DataTypeConversion: '<S453>/Data Type Conversion5'
     */
    if (localTmpSignalConversionAtEGR_k) {
      localSwitch2_k = 0.0F;
    } else {
      localSwitch2_k = ((Float32)InMdlT_B.TmpSignalConversionAtInM_mfEGRE) *
        1.525878906E-005F;
    }

    /* Product: '<S472>/Divide' incorporates:
     *  Sum: '<S453>/Sum3'
     */
    localTmpSignalConversionAtInM_l = (localTmpSignalConversionAtInM_l +
      localSwitch2_k) / localSwitch2_i;

    /* Outputs for atomic SubSystem: '<S472>/If Action Subsystem3' */

    /* Switch: '<S484>/Switch1' incorporates:
     *  Constant: '<S484>/Constant1'
     *  Constant: '<S484>/Constant2'
     *  Constant: '<S484>/Constant3'
     *  Logic: '<S484>/Logical Operator1'
     *  RelationalOperator: '<S484>/Relational Operator'
     *  RelationalOperator: '<S484>/Relational Operator1'
     *  RelationalOperator: '<S484>/Relational Operator3'
     */
    if (((localTmpSignalConversionAtInM_l != localTmpSignalConversionAtInM_l) ||
         (localTmpSignalConversionAtInM_l > 3.000000005E+038F)) ||
        (-3.000000005E+038F > localTmpSignalConversionAtInM_l)) {
      localTmpSignalConversionAtInM_l = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S472>/If Action Subsystem3' */

    /* Sum: '<S470>/Add2' incorporates:
     *  Constant: '<S470>/offset'
     *  Constant: '<S470>/offset1'
     *  Constant: '<S470>/one_on_slope'
     *  Product: '<S470>/Product4'
     *  Sum: '<S470>/Add1'
     */
    localSwitch2_k = ((localTmpSignalConversionAtInM_l - 1.525878906E-005F) *
                      65536.0F) + 0.5F;

    /* DataStoreWrite: '<S453>/Data Store Write2' incorporates:
     *  DataTypeConversion: '<S470>/OutDTConv'
     */
    if (localSwitch2_k < 65536.0F) {
      if (localSwitch2_k >= 0.0F) {
        InM_concAirRawNoSat_MP = (UInt16)localSwitch2_k;
      } else {
        InM_concAirRawNoSat_MP = 0U;
      }
    } else {
      InM_concAirRawNoSat_MP = MAX_uint16_T;
    }

    /* Sum: '<S453>/Sum2' incorporates:
     *  Constant: '<S453>/Constant1'
     */
    localSwitch2_k = 1.0F - localTmpSignalConversionAtInM_l;

    /* RelationalOperator: '<S477>/LowerRelop1' incorporates:
     *  Constant: '<S453>/Constant2'
     */
    localTmpSignalConversionAtEGR_k = (localSwitch2_k > 1.0F);

    /* Switch: '<S477>/Switch' incorporates:
     *  Constant: '<S453>/Constant3'
     *  RelationalOperator: '<S477>/UpperRelop'
     */
    if (localSwitch2_k < 0.0F) {
      localSwitch2_k = 0.0F;
    }

    /* Switch: '<S477>/Switch2' incorporates:
     *  Constant: '<S453>/Constant2'
     */
    if (localTmpSignalConversionAtEGR_k) {
      localSwitch2_k = 1.0F;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S473>/autosar_testpoint1' */

    /* S-Function Block: <S473>/autosar_testpoint1 */
    InM_concAirRaw_IRV_MP = localSwitch2_k;

    /* Switch: '<S480>/Switch' incorporates:
     *  Constant: '<S453>/Constant5'
     *  RelationalOperator: '<S480>/UpperRelop'
     */
    if (localDivide_kp < 0.0F) {
      localSwitch2_i = 0.0F;
    } else {
      localSwitch2_i = localDivide_kp;
    }

    /* Switch: '<S480>/Switch2' incorporates:
     *  Constant: '<S453>/Constant4'
     *  RelationalOperator: '<S480>/LowerRelop1'
     */
    if (localDivide_kp > 1.0F) {
      localSwitch2_i = 1.0F;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S474>/autosar_testpoint1' */

    /* S-Function Block: <S474>/autosar_testpoint1 */
    InM_concFuStmRaw_IRV_MP = localSwitch2_i;

    /* SignalConversion: '<S453>/Signal Conversion1' */
    InMdlT_B.InM_concAirRaw_irv_c = localSwitch2_k;

    /* SignalConversion: '<S453>/Signal Conversion2' */
    InMdlT_B.InM_concFuStmRaw_irv_h = localSwitch2_i;

    /* end of Outputs for SubSystem: '<S448>/F04_Calc_raw_air_concentration' */
  } else {
    /* SignalConversion: '<S487>/copy' */
    localcopy_e = InMdlT_B.TmpSignalConversionAtInM_conc_f;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S487>/autosar_testpoint1' */

    /* S-Function Block: <S487>/autosar_testpoint1 */
    InM_concAirEstim_IRV_MP = localcopy_e;

    /* SignalConversion: '<S449>/Signal Conversion3' */
    localDataTypeConversion1_j = InMdlT_B.TmpSignalConversionAtInM_conc_f;

    /* SignalConversion: '<S486>/copy' */
    localcopy_e = InMdlT_B.TmpSignalConversionAtInM_conc_o;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S486>/autosar_testpoint1' */

    /* S-Function Block: <S486>/autosar_testpoint1 */
    InM_concFuStmEstim_IRV_MP = localcopy_e;

    /* SignalConversion: '<S449>/Signal Conversion1' */
    localInM_concFuStmEstim_irv_o = InMdlT_B.TmpSignalConversionAtInM_conc_o;

    /* SignalConversion: '<S449>/Signal Conversion2' */
    InMdlT_B.Merge3_l = localTmpSignalConversionAtIn_ni;

    /* SignalConversion: '<S485>/copy' */
    localcopy_e = InMdlT_B.TmpSignalConversionAtInM_con_fs;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S485>/autosar_testpoint1' */

    /* S-Function Block: <S485>/autosar_testpoint1 */
    InM_concAirRaw_IRV_MP = localcopy_e;

    /* SignalConversion: '<S449>/Signal Conversion4' */
    InMdlT_B.InM_concAirRaw_irv_c = InMdlT_B.TmpSignalConversionAtInM_con_fs;

    /* SignalConversion: '<S488>/copy' */
    localcopy_e = InMdlT_B.TmpSignalConversionAtInM_conc_c;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S488>/autosar_testpoint1' */

    /* S-Function Block: <S488>/autosar_testpoint1 */
    InM_concFuStmRaw_IRV_MP = localcopy_e;

    /* SignalConversion: '<S449>/Signal Conversion5' */
    InMdlT_B.InM_concFuStmRaw_irv_h = InMdlT_B.TmpSignalConversionAtInM_conc_c;
  }

  /* end of Outputs for SubSystem: '<S442>/F01_Calc_concentration' */

  /* end of Outputs for SubSystem: '<S65>/F02_Calc_concentration_estimated' */

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concAirEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_014_TEV_InM_concAirEstim_irv(localDataTypeConversion1_j);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concAirRaw_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_014_TEV_InM_concAirRaw_irv
    (InMdlT_B.InM_concAirRaw_irv_c);

  /* Switch: '<S443>/Switch' incorporates:
   *  Constant: '<S443>/Byp_Fonction_SC'
   *  Constant: '<S443>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_ni = InM_concEGREstim_B;
  } else {
    localTmpSignalConversionAtIn_ni = InMdlT_B.Merge3_l;
  }

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concEGREstimInport2' */
  Rte_Write_P_InM_concEGREstim_InM_concEGREstim(localTmpSignalConversionAtIn_ni);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concFuStmEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_014_TEV_InM_concFuStmEstim_irv
    (localInM_concFuStmEstim_irv_o);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_concFuStmRaw_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_014_TEV_InM_concFuStmRaw_irv
    (InMdlT_B.InM_concFuStmRaw_irv_h);

  /* SignalConversion: '<S65>/TmpSignal ConversionAtInM_mTotEstim_irvInport2' incorporates:
   *  SignalConversion: '<S65>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_014_TEV_InM_mTotEstim_irv(localMerge_h);
}

/* Output and update for exported function: RE_InMdlT_032_TEV */
void RE_InMdlT_032_TEV(void)
{
  UInt8 localTmpSignalConversionAtEng_h;
  Boolean localRelationalOperator_j3;
  Float32 localSwitch1_lb;
  Float32 localSum2_ag;
  Float32 localAdd2_da;
  UInt16 localTmpSignalConversionAtIn_in;
  SInt32 localTmpSignalConversionAtBlb_m;
  UInt16 localTmpSignalConversionAtEn_gn;
  UInt16 localTmpSignalConversionAtIn_az;
  UInt16 localMerge2_l;
  UInt16 localTmpSignalConversionAtIn_on;

  /* S-Function (fcncallgen): '<S22>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F06_Coherence_control'
   *
   * Block requirements for '<S1>/INM2_F06_Coherence_control':
   *  1. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_150.01 ;
   *  2. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_151.01 ;
   *  3. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_152.01 ;
   *  4. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_349.03 ;
   *  5. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  6. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_230.01 ;
   *  7. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_171.01 ;
   *  8. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_370.01 ;
   *  9. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_202.01 ;
   *  10. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_381.01 ;
   *  11. SubSystem "INM2_F06_Coherence_control" !Trace_To : VEMS_R_11_01067_274.02 ;
   */

  /* SignalConversion: '<S66>/TmpSignal ConversionAtInM_mfTotCanPurgEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfTotCanPurgEstim_INPUT'
   */
  Rte_Read_R_InM_mfTotCanPurgEstim_InM_mfTotCanPurgEstim
    (&localTmpSignalConversionAtIn_az);

  /* SignalConversion: '<S66>/TmpSignal ConversionAtInM_mfAirThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_mfAirT);

  /* SignalConversion: '<S66>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv_INPUT'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtIn_in);

  /* SignalConversion: '<S66>/TmpSignal ConversionAtEngM_mfTotExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_mfTotExCor'
   */
  Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&localTmpSignalConversionAtEn_gn);

  /* SignalConversion: '<S66>/TmpSignal ConversionAtBlby_mfFuStmCmpAirSysOutport2' incorporates:
   *  Inport: '<Root>/Blby_mfFuStmCmpAirSys'
   */
  Rte_Read_R_Blby_mfFuStmCmpAirSys_Blby_mfFuStmCmpAirSys
    (&localTmpSignalConversionAtBlb_m);

  /* SignalConversion: '<S66>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_h);

  /* RelationalOperator: '<S66>/Relational Operator' incorporates:
   *  Constant: '<S66>/Ext_stRun_SC'
   */
  localRelationalOperator_j3 = (localTmpSignalConversionAtEng_h == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S66>/01_man_total_mass_coherence_control' incorporates:
   *  EnablePort: '<S489>/NS_bRun'
   *
   * Block requirements for '<S66>/01_man_total_mass_coherence_control':
   *  1. SubSystem "01_man_total_mass_coherence_control" !Trace_To : VEMS_R_11_01067_153.01 ;
   */
  if (localRelationalOperator_j3) {
    /* DataTypeConversion: '<S489>/Data Type Conversion4' */
    localSwitch1_lb = ((Float32)localTmpSignalConversionAtEn_gn) *
      1.525878906E-005F;

    /* Switch: '<S489>/Switch' incorporates:
     *  Constant: '<S489>/Constant3'
     *  Constant: '<S489>/InM_rKk2_C'
     *  DataTypeConversion: '<S489>/Data Type Conversion3'
     */
    if (InM_bInhCmpAirBby_C) {
      localAdd2_da = 0.0F;
    } else {
      localAdd2_da = ((Float32)localTmpSignalConversionAtBlb_m) *
        1.192092896E-007F;
    }

    /* Sum: '<S489>/Sum2' incorporates:
     *  DataTypeConversion: '<S489>/Data Type Conversion1'
     *  DataTypeConversion: '<S489>/Data Type Conversion2'
     *  DataTypeConversion: '<S489>/Data Type Conversion5'
     */
    localSum2_ag = (((((Float32)InMdlT_B.TmpSignalConversionAtInM_mfAirT) *
                      1.525878906E-005F) + (((Float32)
      localTmpSignalConversionAtIn_az) * 9.536743164E-007F)) + (((Float32)
      localTmpSignalConversionAtIn_in) * 1.525878906E-005F)) + localAdd2_da;

    /* Switch: '<S492>/Switch' incorporates:
     *  Constant: '<S492>/ '
     *  Constant: '<S492>/ 1'
     *  Constant: '<S492>/constant'
     *  RelationalOperator: '<S492>/Relational Operator'
     */
    localAdd2_da = 3.051757813E-005F;

    /* Switch: '<S492>/Switch2' incorporates:
     *  Abs: '<S492>/Abs'
     *  Constant: '<S492>/ '
     *  RelationalOperator: '<S492>/Relational Operator1'
     */
    if (!(localSwitch1_lb < 3.051757813E-005F)) {
      localAdd2_da = localSwitch1_lb;
    }

    /* Product: '<S492>/Product' */
    localAdd2_da = localSum2_ag / localAdd2_da;

    /* Switch: '<S497>/Switch' incorporates:
     *  Constant: '<S492>/SatMinDiv'
     *  RelationalOperator: '<S497>/UpperRelop'
     */
    if (localAdd2_da < -1.0E+005F) {
      localSwitch1_lb = -1.0E+005F;
    } else {
      localSwitch1_lb = localAdd2_da;
    }

    /* Switch: '<S497>/Switch2' incorporates:
     *  Constant: '<S492>/SatMaxDiv'
     *  RelationalOperator: '<S497>/LowerRelop1'
     */
    if (localAdd2_da > 1.0E+005F) {
      localSwitch1_lb = 1.0E+005F;
    }

    /* Switch: '<S492>/Switch1' incorporates:
     *  Constant: '<S492>/Constant2'
     *  RelationalOperator: '<S492>/Relational Operator2'
     */
    if (localAdd2_da != localAdd2_da) {
      localSwitch1_lb = 0.0F;
    }

    /* DataTypeConversion: '<S493>/OutDTConv' incorporates:
     *  Constant: '<S493>/offset'
     *  Constant: '<S493>/offset1'
     *  Constant: '<S493>/one_on_slope'
     *  Product: '<S493>/Product4'
     *  Sum: '<S493>/Add1'
     *  Sum: '<S493>/Add2'
     */
    localSwitch1_lb = (16384.0F * localSwitch1_lb) + 0.5F;
    if (localSwitch1_lb < 65536.0F) {
      if (localSwitch1_lb >= 0.0F) {
        localMerge2_l = (UInt16)localSwitch1_lb;
      } else {
        localMerge2_l = 0U;
      }
    } else {
      localMerge2_l = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S66>/01_man_total_mass_coherence_control' */

  /* SignalConversion: '<S66>/TmpSignal ConversionAtInM_rCohMnfMf1Outport2' incorporates:
   *  Inport: '<Root>/InM_rCohMnfMf_INPUT'
   */
  Rte_Read_R_InM_rCohMnfMf_InM_rCohMnfMf(&localTmpSignalConversionAtIn_on);

  /* Outputs for enable SubSystem: '<S66>/02_NOT' incorporates:
   *  EnablePort: '<S490>/NS_bRun'
   *  Logic: '<S66>/NAN'
   */
  if (!localRelationalOperator_j3) {
    /* SignalConversion: '<S490>/Signal Conversion2' */
    localMerge2_l = localTmpSignalConversionAtIn_on;
  }

  /* end of Outputs for SubSystem: '<S66>/02_NOT' */

  /* Switch: '<S491>/Switch' incorporates:
   *  Constant: '<S491>/Byp_Fonction_SC'
   *  Constant: '<S491>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localMerge2_l = InM_rCohMnfMf_B;
  }

  /* SignalConversion: '<S66>/TmpSignal ConversionAtInM_rCohMnfMfInport2' */
  Rte_Write_P_InM_rCohMnfMf_InM_rCohMnfMf(localMerge2_l);
}

/* Start for exported function: RE_InMdlT_016_TEV */
void RE_InMdlT_016_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S23>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F01_Inlet_valve_closing_horizon_computation'
   *
   * Block requirements for '<S1>/INM3_F01_Inlet_valve_closing_horizon_computation':
   *  1. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_052.01 ;
   *  2. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  3. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  4. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_234.01 ;
   *  5. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_236.01 ;
   *  6. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  7. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  8. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_235.01 ;
   *  9. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_339.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_016_TEV */
void RE_InMdlT_016_TEV(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_fa;
  Float32 localSwitch_m;
  Float32 localcopy_l;
  Float32 localDivide_jw;
  UInt8 localDataTypeConversion_l;
  UInt8 localLookUpTable_p;
  UInt8 localTmpSignalConversionAtEn_hp;
  Boolean localLogicalOperator1_f;
  Float32 localDataTypeConversion3_c;
  Float32 localDivide_dl;

  /* S-Function (fcncallgen): '<S23>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F01_Inlet_valve_closing_horizon_computation'
   *
   * Block requirements for '<S1>/INM3_F01_Inlet_valve_closing_horizon_computation':
   *  1. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_052.01 ;
   *  2. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  3. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  4. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_234.01 ;
   *  5. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_236.01 ;
   *  6. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  7. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  8. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_235.01 ;
   *  9. SubSystem "INM3_F01_Inlet_valve_closing_horizon_computation" !Trace_To : VEMS_R_11_01067_339.01 ;
   */

  /* SignalConversion: '<S67>/TmpSignal ConversionAtExt_agCkPosnCurRef2Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkPosnCurRef2'
   */
  Rte_Read_R_Ext_agCkPosnCurRef2_Ext_agCkPosnCurRef2
    (&InMdlT_B.TmpSignalConversionAtExt_agCk_j);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&InMdlT_B.TmpSignalConversionAtExt_agCkOp);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&InMdlT_B.TmpSignalConversionAtEng_noEx_p);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtExt_tiHldPerEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiHldPerEng'
   */
  Rte_Read_R_Ext_tiHldPerEng_Ext_tiHldPerEng
    (&InMdlT_B.TmpSignalConversionAtExt_tiHl_g);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_hp);

  /* Logic: '<S67>/Logical Operator1' incorporates:
   *  Constant: '<S67>/Ext_stRun_SC'
   *  Constant: '<S67>/InM_bInhPred_C'
   *  Logic: '<S67>/Logical Operator'
   *  RelationalOperator: '<S67>/Relational Operator'
   */
  localLogicalOperator1_f = ((Ext_stRun_SC == localTmpSignalConversionAtEn_hp) &&
                             (!InM_bInhPred_C));

  /* Outputs for enable SubSystem: '<S67>/F01_Horizon_computation' incorporates:
   *  EnablePort: '<S498>/NS_bAcv'
   *
   * Block requirements for '<S67>/F01_Horizon_computation':
   *  1. SubSystem "F01_Horizon_computation" !Trace_To : VEMS_R_11_01067_053.01 ;
   *  2. SubSystem "F01_Horizon_computation" !Trace_To : VEMS_R_11_01067_054.01 ;
   */
  if (localLogicalOperator1_f) {
    /* Outputs for atomic SubSystem: '<S498>/F01_Calc_closed_inlet_valve' *
     * Block requirements for '<S498>/F01_Calc_closed_inlet_valve':
     *  1. SubSystem "F01_Calc_closed_inlet_valve" !Trace_To : VEMS_R_11_01067_055.01 ;
     */

    /* DataTypeConversion: '<S500>/Data Type Conversion3' incorporates:
     *  Constant: '<S500>/InM_agCkLoTDCRef2_C'
     */
    localDataTypeConversion3_c = ((Float32)InM_agCkLoTDCRef2_C) * 0.09375F;

    /* Switch: '<S500>/Switch' incorporates:
     *  Constant: '<S500>/InM_bHrznClcMod_C'
     *  DataTypeConversion: '<S500>/Data Type Conversion2'
     *  Sum: '<S500>/Sum2'
     */
    if (InM_bHrznClcMod_C) {
      localSwitch_m = (((Float32)InMdlT_B.TmpSignalConversionAtExt_agCkOp) *
                       0.09375F) + localDataTypeConversion3_c;
    } else {
      localSwitch_m = localDataTypeConversion3_c;
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S503>/autosar_testpoint1' */

    /* S-Function Block: <S503>/autosar_testpoint1 */
    InM_agCkClsInVlvEstimRef2_IRV_MP = localSwitch_m;

    /* end of Outputs for SubSystem: '<S498>/F01_Calc_closed_inlet_valve' */

    /* Outputs for atomic SubSystem: '<S498>/F02_Calc_angular_difference' *
     * Block requirements for '<S498>/F02_Calc_angular_difference':
     *  1. SubSystem "F02_Calc_angular_difference" !Trace_To : VEMS_R_11_01067_056.01 ;
     */

    /* DataTypeConversion: '<S501>/Data Type Conversion2' */
    localDataTypeConversion3_c = ((Float32)
      InMdlT_B.TmpSignalConversionAtExt_agCk_j) * 0.09375F;

    /* Product: '<S506>/Divide' incorporates:
     *  Constant: '<S501>/Constant2'
     *  Constant: '<S501>/Ext_noCylEng_SC'
     *  DataTypeConversion: '<S501>/Data Type Conversion12'
     */
    localDivide_dl = 720.0F / ((Float32)Ext_noCylEng_SC);

    /* DataTypeConversion: '<S504>/Data Type Conversion' */
    localDataTypeConversion_l = InMdlT_B.TmpSignalConversionAtEng_noEx_p;

    /* Lookup: '<S504>/Look-Up Table'
     * About '<S504>/Look-Up Table':
     * Input0  Data Type:  Integer        U8
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_p), (&(InM_facCylRef2_T[0])),
                 localDataTypeConversion_l, (&(InM_noCylEng_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S504>/Data Type Duplicate1'
     *
     * Regarding '<S504>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Math: '<S501>/Math Function' incorporates:
     *  Constant: '<S501>/Constant4'
     *  DataTypeConversion: '<S501>/Data Type Conversion'
     *  Product: '<S507>/Divide'
     *  Sum: '<S501>/Sum2'
     */
    localDataTypeConversion3_c = rt_mod32(localDataTypeConversion3_c -
      (localDivide_dl * ((Float32)localLookUpTable_p)), 720.0F);

    /* DataStoreWrite: '<S501>/Data Store Write2' incorporates:
     *  Constant: '<S505>/offset'
     *  Constant: '<S505>/offset1'
     *  Constant: '<S505>/one_on_slope'
     *  DataTypeConversion: '<S505>/OutDTConv'
     *  Product: '<S505>/Product4'
     *  Sum: '<S505>/Add1'
     *  Sum: '<S505>/Add2'
     */
    localDivide_dl = (1.066666698E+001F * localDataTypeConversion3_c) + 0.5F;
    if (localDivide_dl < 65536.0F) {
      if (localDivide_dl >= 0.0F) {
        InM_agCkPosnCurCor_MP = (UInt16)localDivide_dl;
      } else {
        InM_agCkPosnCurCor_MP = 0U;
      }
    } else {
      InM_agCkPosnCurCor_MP = MAX_uint16_T;
    }

    /* Sum: '<S501>/Sum3' */
    InM_agCkPhaHrznPred = localSwitch_m - localDataTypeConversion3_c;

    /* end of Outputs for SubSystem: '<S498>/F02_Calc_angular_difference' */

    /* Outputs for atomic SubSystem: '<S498>/F03_Calc_prediction_time' *
     * Block requirements for '<S498>/F03_Calc_prediction_time':
     *  1. SubSystem "F03_Calc_prediction_time" !Trace_To : VEMS_R_11_01067_057.01 ;
     */

    /* DataTypeConversion: '<S502>/Data Type Conversion1' incorporates:
     *  Constant: '<S502>/Ext_noCylEng_SC'
     */
    localDivide_jw = (Float32)Ext_noCylEng_SC;

    /* Product: '<S511>/Divide' incorporates:
     *  Constant: '<S502>/Constant9'
     *  DataTypeConversion: '<S502>/Data Type Conversion12'
     *  Product: '<S509>/Divide'
     *  Product: '<S510>/Divide'
     */
    localDivide_jw = ((((Float32)InMdlT_B.TmpSignalConversionAtExt_tiHl_g) *
                       3.200000037E-006F) / (720.0F / localDivide_jw)) *
      InM_agCkPhaHrznPred;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S508>/autosar_testpoint1' */

    /* S-Function Block: <S508>/autosar_testpoint1 */
    InM_tiHrznPred_IRV_MP = localDivide_jw;

    /* SignalConversion: '<S502>/Signal Conversion1' */
    InMdlT_B.InM_tiHrznPred_irv_m = localDivide_jw;

    /* end of Outputs for SubSystem: '<S498>/F03_Calc_prediction_time' */

    /* SignalConversion: '<S498>/Signal Conversion2' */
    localDataTypeConversion3_c = localSwitch_m;
  }

  /* end of Outputs for SubSystem: '<S67>/F01_Horizon_computation' */

  /* SignalConversion: '<S67>/TmpSignal ConversionAtInM_tiHrznPred_irv1Outport2' */
  localTmpSignalConversionAtIn_fa =
    Rte_IrvRead_RE_InMdlT_016_TEV_InM_tiHrznPred_irv();

  /* SignalConversion: '<S67>/TmpSignal ConversionAtInM_agCkClsInVlvEstimRef2_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_agCkCl =
    Rte_IrvRead_RE_InMdlT_016_TEV_InM_agCkClsInVlvEstimRef2_irv();

  /* Outputs for enable SubSystem: '<S67>/F01_NOT' incorporates:
   *  EnablePort: '<S499>/NS_bAcv'
   *  Logic: '<S67>/NAN'
   */
  if (!localLogicalOperator1_f) {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S512>/autosar_testpoint1' */
    /* S-Function Block: <S512>/autosar_testpoint1 */
    InM_tiHrznPred_IRV_MP = localTmpSignalConversionAtIn_fa;

    /* SignalConversion: '<S499>/Signal Conversion1' */
    InMdlT_B.InM_tiHrznPred_irv_m = localTmpSignalConversionAtIn_fa;

    /* SignalConversion: '<S513>/copy' */
    localcopy_l = InMdlT_B.TmpSignalConversionAtInM_agCkCl;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S513>/autosar_testpoint1' */

    /* S-Function Block: <S513>/autosar_testpoint1 */
    InM_agCkClsInVlvEstimRef2_IRV_MP = localcopy_l;

    /* SignalConversion: '<S499>/Signal Conversion2' */
    localDataTypeConversion3_c = InMdlT_B.TmpSignalConversionAtInM_agCkCl;
  }

  /* end of Outputs for SubSystem: '<S67>/F01_NOT' */

  /* SignalConversion: '<S67>/TmpSignal ConversionAtInM_agCkClsInVlvEstimRef_2_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_016_TEV_InM_agCkClsInVlvEstimRef2_irv
    (localDataTypeConversion3_c);

  /* SignalConversion: '<S67>/TmpSignal ConversionAtInM_tiHrznPred_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_016_TEV_InM_tiHrznPred_irv
    (InMdlT_B.InM_tiHrznPred_irv_m);
}

/* Start for exported function: RE_InMdlT_026_TEV */
void RE_InMdlT_026_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S24>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F02_Inlet_valve_closing_horizon_computation1'
   *
   * Block requirements for '<S1>/INM3_F02_Inlet_valve_closing_horizon_computation1':
   *  1. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_160.01 ;
   *  2. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_161.01 ;
   *  3. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_344.01 ;
   *  4. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  5. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  6. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_174.01 ;
   *  7. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  8. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_234.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_026_TEV */
void RE_InMdlT_026_TEV(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_k1;
  Float32 localMinMax_e;
  UInt8 localDataTypeConversion_o;
  UInt8 localLookUpTable_fk;
  UInt8 localTmpSignalConversionAtEn_p4;
  Boolean localLogicalOperator1_do;
  Float32 localDivide_btp;
  Float32 localSwitch_dj;
  UInt16 localTmpSignalConversionAtExt_a;
  UInt16 localTmpSignalConversionAtEx_n2;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S24>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F02_Inlet_valve_closing_horizon_computation1'
   *
   * Block requirements for '<S1>/INM3_F02_Inlet_valve_closing_horizon_computation1':
   *  1. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_160.01 ;
   *  2. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_161.01 ;
   *  3. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_344.01 ;
   *  4. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  5. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  6. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_174.01 ;
   *  7. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  8. SubSystem "INM3_F02_Inlet_valve_closing_horizon_computation1" !Trace_To : VEMS_R_11_01067_234.01 ;
   */

  /* SignalConversion: '<S68>/TmpSignal ConversionAtExt_agCkPosnCurRef2Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkPosnCurRef2'
   */
  Rte_Read_R_Ext_agCkPosnCurRef2_Ext_agCkPosnCurRef2
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S68>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&InMdlT_B.TmpSignalConversionAtEng_noInCy);

  /* SignalConversion: '<S68>/TmpSignal ConversionAtExt_tiHldPerEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiHldPerEng'
   */
  Rte_Read_R_Ext_tiHldPerEng_Ext_tiHldPerEng(&localTmpSignalConversionAtEx_n2);

  /* SignalConversion: '<S68>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_p4);

  /* Logic: '<S68>/Logical Operator1' incorporates:
   *  Constant: '<S68>/Ext_stRun_SC'
   *  Constant: '<S68>/InM_bInhPred_C'
   *  Logic: '<S68>/Logical Operator'
   *  RelationalOperator: '<S68>/Relational Operator'
   */
  localLogicalOperator1_do = ((Ext_stRun_SC == localTmpSignalConversionAtEn_p4) &&
                              (!InM_bInhPred_C));

  /* Outputs for enable SubSystem: '<S68>/F01_Horizon_computation' incorporates:
   *  EnablePort: '<S514>/PredAcv'
   *
   * Block requirements for '<S68>/F01_Horizon_computation':
   *  1. SubSystem "F01_Horizon_computation" !Trace_To : VEMS_R_11_01067_162.01 ;
   */
  if (localLogicalOperator1_do) {
    /* Outputs for atomic SubSystem: '<S514>/F01_Calc_angular_difference' *
     * Block requirements for '<S514>/F01_Calc_angular_difference':
     *  1. SubSystem "F01_Calc_angular_difference" !Trace_To : VEMS_R_11_01067_163.01 ;
     */

    /* Product: '<S520>/Divide' incorporates:
     *  Constant: '<S516>/Constant2'
     *  Constant: '<S516>/Ext_noCylEng_SC'
     *  DataTypeConversion: '<S516>/Data Type Conversion12'
     */
    localDivide_btp = 720.0F / ((Float32)Ext_noCylEng_SC);

    /* DataTypeConversion: '<S518>/Data Type Conversion' */
    localDataTypeConversion_o = InMdlT_B.TmpSignalConversionAtEng_noInCy;

    /* Lookup: '<S518>/Look-Up Table'
     * About '<S518>/Look-Up Table':
     * Input0  Data Type:  Integer        U8
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_fk), (&(InM_facCylRef2_T[0])),
                 localDataTypeConversion_o, (&(InM_noCylEng_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S518>/Data Type Duplicate1'
     *
     * Regarding '<S518>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Math: '<S516>/Math Function' incorporates:
     *  Constant: '<S516>/Constant4'
     *  DataTypeConversion: '<S516>/Data Type Conversion1'
     *  Product: '<S521>/Divide'
     *  Sum: '<S516>/Sum2'
     */
    localSwitch_dj = rt_mod32((((Float32)localTmpSignalConversionAtExt_a) *
      0.09375F) - (localDivide_btp * ((Float32)localLookUpTable_fk)), 720.0F);

    /* DataStoreWrite: '<S516>/Data Store Write2' incorporates:
     *  Constant: '<S519>/offset'
     *  Constant: '<S519>/offset1'
     *  Constant: '<S519>/one_on_slope'
     *  DataTypeConversion: '<S519>/OutDTConv'
     *  Product: '<S519>/Product4'
     *  Sum: '<S519>/Add1'
     *  Sum: '<S519>/Add2'
     */
    localtmp = (1.066666698E+001F * localSwitch_dj) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        InM_agCkPosnCurRef2Cor_MP = (UInt16)localtmp;
      } else {
        InM_agCkPosnCurRef2Cor_MP = 0U;
      }
    } else {
      InM_agCkPosnCurRef2Cor_MP = MAX_uint16_T;
    }

    /* Switch: '<S516>/Switch' incorporates:
     *  Constant: '<S516>/Constant3'
     *  RelationalOperator: '<S516>/Relational Operator'
     */
    if (!(localSwitch_dj >= localDivide_btp)) {
      localSwitch_dj = 720.0F;
    }

    /* Sum: '<S516>/Sum3' incorporates:
     *  SignalConversion: '<S68>/TmpSignal ConversionAtInM_agCkClsInVlvEstimRef2_irvOutport2'
     */
    InM_agCkPhaHrznPredInCyl =
      Rte_IrvRead_RE_InMdlT_026_TEV_InM_agCkClsInVlvEstimRef2_irv() -
      localSwitch_dj;

    /* end of Outputs for SubSystem: '<S514>/F01_Calc_angular_difference' */

    /* Outputs for atomic SubSystem: '<S514>/F02_Calc_prediction_time' *
     * Block requirements for '<S514>/F02_Calc_prediction_time':
     *  1. SubSystem "F02_Calc_prediction_time" !Trace_To : VEMS_R_11_01067_164.01 ;
     */

    /* DataTypeConversion: '<S517>/Data Type Conversion2' incorporates:
     *  Constant: '<S517>/Ext_noCylEng_SC'
     */
    localMinMax_e = (Float32)Ext_noCylEng_SC;

    /* Product: '<S525>/Divide' incorporates:
     *  Constant: '<S517>/Constant9'
     *  DataTypeConversion: '<S517>/Data Type Conversion12'
     *  Product: '<S523>/Divide'
     *  Product: '<S524>/Divide'
     */
    localMinMax_e = ((((Float32)localTmpSignalConversionAtEx_n2) *
                      3.200000037E-006F) / (720.0F / localMinMax_e)) *
      InM_agCkPhaHrznPredInCyl;

    /* MinMax: '<S517>/MinMax' incorporates:
     *  Constant: '<S517>/Constant1'
     */
    localMinMax_e = rt_MAXf(localMinMax_e, 0.0F);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S522>/autosar_testpoint1' */

    /* S-Function Block: <S522>/autosar_testpoint1 */
    InM_tiHrznPredInCyl_IRV_MP = localMinMax_e;

    /* SignalConversion: '<S517>/Signal Conversion1' */
    InMdlT_B.InM_tiHrznPredInCyl_irv_n = localMinMax_e;

    /* end of Outputs for SubSystem: '<S514>/F02_Calc_prediction_time' */
  }

  /* end of Outputs for SubSystem: '<S68>/F01_Horizon_computation' */

  /* SignalConversion: '<S68>/TmpSignal ConversionAtInM_tiHrznPredInCyl_irv1Outport2' */
  localTmpSignalConversionAtIn_k1 =
    Rte_IrvRead_RE_InMdlT_026_TEV_InM_tiHrznPredInCyl_irv();

  /* Outputs for enable SubSystem: '<S68>/F01_NOT' incorporates:
   *  EnablePort: '<S515>/PredAcv'
   *  Logic: '<S68>/NAN'
   */
  if (!localLogicalOperator1_do) {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S526>/autosar_testpoint1' */
    /* S-Function Block: <S526>/autosar_testpoint1 */
    InM_tiHrznPredInCyl_IRV_MP = localTmpSignalConversionAtIn_k1;

    /* SignalConversion: '<S515>/Signal Conversion2' */
    InMdlT_B.InM_tiHrznPredInCyl_irv_n = localTmpSignalConversionAtIn_k1;
  }

  /* end of Outputs for SubSystem: '<S68>/F01_NOT' */

  /* SignalConversion: '<S68>/TmpSignal ConversionAtInM_tiHrznPredInCyl_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_026_TEV_InM_tiHrznPredInCyl_irv
    (InMdlT_B.InM_tiHrznPredInCyl_irv_n);
}

/* Start for exported function: RE_InMdlT_033_TEV */
void RE_InMdlT_033_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S25>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F03_Horizon_prediction_au_croisement'
   *
   * Block requirements for '<S1>/INM3_F03_Horizon_prediction_au_croisement':
   *  1. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_058.01 ;
   *  2. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_059.01 ;
   *  3. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_350.01 ;
   *  4. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  5. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  6. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_275.01 ;
   *  7. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_236.01 ;
   *  8. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_234.01 ;
   *  9. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  10. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_235.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_033_TEV */
void RE_InMdlT_033_TEV(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_oi;
  Float32 localMinMax_i;
  UInt8 localDataTypeConversion_f;
  UInt8 localLookUpTable_e0;
  UInt8 localTmpSignalConversionAtEn_bh;
  Boolean localLogicalOperator1_l2;
  Float32 localInM_tiHrznPred_facVlvOvlp_;
  SInt16 localTmpSignalConversionAtExt_g;
  SInt16 localTmpSignalConversionAtEx_ab;

  /* S-Function (fcncallgen): '<S25>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F03_Horizon_prediction_au_croisement'
   *
   * Block requirements for '<S1>/INM3_F03_Horizon_prediction_au_croisement':
   *  1. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_058.01 ;
   *  2. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_059.01 ;
   *  3. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_350.01 ;
   *  4. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  5. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  6. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_275.01 ;
   *  7. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_236.01 ;
   *  8. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_234.01 ;
   *  9. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  10. SubSystem "INM3_F03_Horizon_prediction_au_croisement" !Trace_To : VEMS_R_11_01067_235.01 ;
   */

  /* SignalConversion: '<S69>/TmpSignal ConversionAtInM_tiHrznPred_facVlvOvlp_irv1Outport2' */
  localTmpSignalConversionAtIn_oi =
    Rte_IrvRead_RE_InMdlT_033_TEV_InM_tiHrznPred_facVlvOvlp_irv();

  /* SignalConversion: '<S69>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_bh);

  /* Logic: '<S69>/Logical Operator1' incorporates:
   *  Constant: '<S69>/Ext_stRun_SC'
   *  Constant: '<S69>/InM_bInhPred_C'
   *  Logic: '<S69>/Logical Operator'
   *  RelationalOperator: '<S69>/Relational Operator'
   */
  localLogicalOperator1_l2 = ((Ext_stRun_SC == localTmpSignalConversionAtEn_bh) &&
                              (!InM_bInhPred_C));

  /* Outputs for enable SubSystem: '<S69>/F01_NOT' incorporates:
   *  EnablePort: '<S527>/PredAcv'
   *  Logic: '<S69>/NAN'
   */
  if (!localLogicalOperator1_l2) {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S529>/autosar_testpoint1' */
    /* S-Function Block: <S529>/autosar_testpoint1 */
    InM_tiHrznPred_facVlvOvlp_IRV_MP = localTmpSignalConversionAtIn_oi;

    /* SignalConversion: '<S527>/Signal Conversion2' */
    localInM_tiHrznPred_facVlvOvlp_ = localTmpSignalConversionAtIn_oi;
  }

  /* end of Outputs for SubSystem: '<S69>/F01_NOT' */

  /* SignalConversion: '<S69>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_g);

  /* SignalConversion: '<S69>/TmpSignal ConversionAtExt_agCkClsExVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkClsExVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0
    (&localTmpSignalConversionAtEx_ab);

  /* SignalConversion: '<S69>/TmpSignal ConversionAtExt_agCkPosnCurRef2Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkPosnCurRef2'
   */
  Rte_Read_R_Ext_agCkPosnCurRef2_Ext_agCkPosnCurRef2
    (&InMdlT_B.TmpSignalConversionAtExt_agCkPo);

  /* SignalConversion: '<S69>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&InMdlT_B.TmpSignalConversionAtEng_noExCy);

  /* SignalConversion: '<S69>/TmpSignal ConversionAtExt_tiHldPerEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiHldPerEng'
   */
  Rte_Read_R_Ext_tiHldPerEng_Ext_tiHldPerEng
    (&InMdlT_B.TmpSignalConversionAtExt_tiHldP);

  /* Outputs for enable SubSystem: '<S69>/F01_calc_horizon_prediction' incorporates:
   *  EnablePort: '<S528>/NS_bEna'
   *
   * Block requirements for '<S69>/F01_calc_horizon_prediction':
   *  1. SubSystem "F01_calc_horizon_prediction" !Trace_To : VEMS_R_11_01067_060.01 ;
   */
  if (localLogicalOperator1_l2) {
    /* DataTypeConversion: '<S528>/Data Type Conversion3' */
    localInM_tiHrznPred_facVlvOvlp_ = ((Float32)
      InMdlT_B.TmpSignalConversionAtExt_agCkPo) * 0.09375F;

    /* Outputs for atomic SubSystem: '<S528>/F01_Calc_overlapping_angle' *
     * Block requirements for '<S528>/F01_Calc_overlapping_angle':
     *  1. SubSystem "F01_Calc_overlapping_angle" !Trace_To : VEMS_R_11_01067_061.01 ;
     */

    /* Sum: '<S530>/Sum3' incorporates:
     *  Constant: '<S530>/Constant1'
     *  Constant: '<S530>/InM_agCkHiTDCRef2_C'
     *  DataTypeConversion: '<S530>/Data Type Conversion'
     *  DataTypeConversion: '<S530>/Data Type Conversion1'
     *  DataTypeConversion: '<S530>/Data Type Conversion2'
     *  Product: '<S533>/Divide'
     *  Sum: '<S530>/Sum1'
     */
    InM_agCkOvlpEstimRef2 = (((((Float32)localTmpSignalConversionAtExt_g) *
      0.09375F) + (((Float32)localTmpSignalConversionAtEx_ab) * 0.09375F)) *
      0.5F) + (((Float32)InM_agCkHiTDCRef2_C) * 0.09375F);

    /* end of Outputs for SubSystem: '<S528>/F01_Calc_overlapping_angle' */

    /* Outputs for atomic SubSystem: '<S528>/F02_Calc_angular_difference' *
     * Block requirements for '<S528>/F02_Calc_angular_difference':
     *  1. SubSystem "F02_Calc_angular_difference" !Trace_To : VEMS_R_11_01067_062.01 ;
     */

    /* DataTypeConversion: '<S534>/Data Type Conversion' */
    localDataTypeConversion_f = InMdlT_B.TmpSignalConversionAtEng_noExCy;

    /* Lookup: '<S534>/Look-Up Table'
     * About '<S534>/Look-Up Table':
     * Input0  Data Type:  Integer        U8
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_e0), (&(InM_facCylRef2_T[0])),
                 localDataTypeConversion_f, (&(InM_noCylEng_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S534>/Data Type Duplicate1'
     *
     * Regarding '<S534>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S531>/Sum3' incorporates:
     *  Constant: '<S531>/Constant2'
     *  Constant: '<S531>/Constant4'
     *  Constant: '<S531>/Ext_noCylEng_SC'
     *  DataTypeConversion: '<S531>/Data Type Conversion1'
     *  DataTypeConversion: '<S531>/Data Type Conversion12'
     *  Math: '<S531>/Math Function'
     *  Product: '<S535>/Divide'
     *  Product: '<S536>/Divide'
     *  Sum: '<S531>/Sum2'
     */
    InM_agCkPhaHrznOvlpPred = InM_agCkOvlpEstimRef2 - rt_mod32
      (localInM_tiHrznPred_facVlvOvlp_ - ((720.0F / ((Float32)Ext_noCylEng_SC))
        * ((Float32)localLookUpTable_e0)), 720.0F);

    /* end of Outputs for SubSystem: '<S528>/F02_Calc_angular_difference' */

    /* DataTypeConversion: '<S532>/Data Type Conversion2' incorporates:
     *  Constant: '<S532>/Ext_noCylEng_SC'
     */
    localMinMax_i = (Float32)Ext_noCylEng_SC;

    /* Product: '<S540>/Divide' incorporates:
     *  Constant: '<S532>/Constant1'
     *  DataTypeConversion: '<S532>/Data Type Conversion12'
     *  Product: '<S538>/Divide'
     *  Product: '<S539>/Divide'
     */
    localMinMax_i = ((((Float32)InMdlT_B.TmpSignalConversionAtExt_tiHldP) *
                      3.200000037E-006F) / (720.0F / localMinMax_i)) *
      InM_agCkPhaHrznOvlpPred;

    /* MinMax: '<S532>/MinMax' incorporates:
     *  Constant: '<S532>/Cste_0'
     */
    localMinMax_i = rt_MAXf(localMinMax_i, 0.0F);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S537>/autosar_testpoint1' */

    /* S-Function Block: <S537>/autosar_testpoint1 */
    InM_tiHrznPred_facVlvOvlp_IRV_MP = localMinMax_i;

    /* SignalConversion: '<S532>/Signal Conversion1' */
    localInM_tiHrznPred_facVlvOvlp_ = localMinMax_i;
  }

  /* end of Outputs for SubSystem: '<S69>/F01_calc_horizon_prediction' */

  /* SignalConversion: '<S69>/TmpSignal ConversionAtInM_tiHrznPred_facVlvOvlp_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_033_TEV_InM_tiHrznPred_facVlvOvlp_irv
    (localInM_tiHrznPred_facVlvOvlp_);
}

/* Start for exported function: RE_InMdlT_018_TEV */
void RE_InMdlT_018_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S26>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F04_Manage_manifold_prediction'
   *
   * Block requirements for '<S1>/INM3_F04_Manage_manifold_prediction':
   *  1. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_064.01 ;
   *  2. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_065.01 ;
   *  3. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_340.02 ;
   *  4. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  5. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  6. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  7. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  8. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_304.02 ;
   *  9. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  10. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  11. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  12. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  13. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  14. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  15. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  16. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  17. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  18. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  19. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_239.01 ;
   *  20. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  21. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  22. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_324.02 ;
   *  23. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  24. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  25. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  26. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  27. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  28. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  29. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_380.01 ;
   *  30. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  31. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_238.01 ;
   *  32. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_237.01 ;
   *  33. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  34. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  35. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  36. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  37. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_206.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_018_TEV */
void RE_InMdlT_018_TEV(void)
{
  /* local block i/o variables */
  Float32 localcopy_n;
  UInt16 localDataTypeConversion_n;
  UInt16 localcopy_f;
  UInt16 localcopy_p;
  UInt16 localOutDTConv_p[3];
  UInt16 localDivide_dqi[3];
  UInt16 localLookUpTable_by;
  UInt8 localLookUpTable_a0[3];
  UInt8 localLookUpTable_hz[3];
  Float32 localTmpSignalConversionAtIn_ow;
  Float32 localTmpSignalConversionAtIn_im;
  Float32 localTmpSignalConversionAtIn_py;
  Float32 localTmpSignalConversionAtIn_p1;
  Float32 localTmpSignalConversionAtIn_jm;
  Float32 localTmpSignalConversionAtIn_mp;
  Float32 localTmpSignalConversionAtIn_jw;
  Float32 localTmpSignalConversionAtIn_mb;
  Float32 localTmpSignalConversionAtIn_mt;
  Float32 localSignalConversion2;
  Float32 localSignalConversion3;
  Float32 localSignalConversion1;
  UInt8 localTmpSignalConversionAtEng_f;
  Boolean localRelationalOperator_ns;
  Float32 localInM_concAirPredInCyl_irv;
  Float32 localInM_concFuPred_irv;
  UInt16 localTmpSignalConversionAtI_bpi;
  UInt16 localTmpSignalConversionAtIn_kz;
  Float32 localDataTypeConversion2_oc;
  Boolean localRelationalOperator1_m5;
  Float32 localDataTypeConversion12_i;
  UInt16 localTmpSignalConversionAtI_giy;
  UInt16 localTmpSignalConversionAtInT_i;
  UInt16 localTmpSignalConversionAtIn_cc;
  SInt32 locallocalSum_j;
  Float32 locallocalDivide_fe_idx;
  Float32 locallocalDivide_fe_idx_0;
  Float32 locallocalDivide_fe_idx_1;
  Float32d localtmp;
  UInt16 localtmp_0;

  /* S-Function (fcncallgen): '<S26>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F04_Manage_manifold_prediction'
   *
   * Block requirements for '<S1>/INM3_F04_Manage_manifold_prediction':
   *  1. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_064.01 ;
   *  2. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_065.01 ;
   *  3. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_340.02 ;
   *  4. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  5. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  6. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  7. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  8. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_304.02 ;
   *  9. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  10. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  11. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  12. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  13. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  14. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  15. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  16. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  17. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_292.02 ;
   *  18. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_293.02 ;
   *  19. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_239.01 ;
   *  20. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_295.02 ;
   *  21. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_296.02 ;
   *  22. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_324.02 ;
   *  23. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_323.02 ;
   *  24. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_297.02 ;
   *  25. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  26. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_291.02 ;
   *  27. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  28. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_320.02 ;
   *  29. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_380.01 ;
   *  30. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  31. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_238.01 ;
   *  32. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_237.01 ;
   *  33. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  34. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  35. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  36. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_384.01 ;
   *  37. SubSystem "INM3_F04_Manage_manifold_prediction" !Trace_To : VEMS_R_11_01067_206.01 ;
   */

  /* SignalConversion: '<S70>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&InMdlT_B.TmpSignalConversionAtExt_nEng_e);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concAirEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_g =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concAirEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concFuStmEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_n =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concFuStmEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor
    (&InMdlT_B.TmpSignalConversionAtUsThrM_p_b);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrEstimPrev_irvOutport2' */
  localTmpSignalConversionAtIn_ow =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pDsThrEstimPrev_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pGradDsThrEstim_irvOutport2' */
  localTmpSignalConversionAtIn_im =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pGradDsThrEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_tiInvEigVal_pDsThrOutport2' incorporates:
   *  Inport: '<Root>/InM_tiInvEigVal_pDsThr_INPUT'
   */
  Rte_Read_R_InM_tiInvEigVal_pDsThr_InM_tiInvEigVal_pDsThr
    (&localTmpSignalConversionAtI_bpi);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mAirEstimPrev_irvOutport2' */
  localTmpSignalConversionAtIn_py =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mAirEstimPrev_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mGradAirEstim_irvOutport2' */
  localTmpSignalConversionAtIn_p1 =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mGradAirEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mFuStmEstimPrev_irvOutport2' */
  localTmpSignalConversionAtIn_jm =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mFuStmEstimPrev_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mGradFuStmEstim_irvOutport2' */
  localTmpSignalConversionAtIn_mp =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mGradFuStmEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mEGREstimPrev_irvOutport2' */
  localTmpSignalConversionAtIn_jw =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mEGREstimPrev_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mGradEGREstimOutport2' */
  localTmpSignalConversionAtIn_mb =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mGradEGREstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrEstimLoResl_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_pDsT_g =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pDsThrEstimLoResl_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mAirEstim_INPUT'
   */
  Rte_Read_R_InM_mAirEstim_InM_mAirEstim
    (&InMdlT_B.TmpSignalConversionAtInM_mAirEs);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mFuStmEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_mFuStm =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mFuStmEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mEGREstim_INPUT'
   */
  Rte_Read_R_InM_mEGREstim_InM_mEGREstim
    (&InMdlT_B.TmpSignalConversionAtInM_mEGR_g);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_mTotEstim_irvOutport2' */
  localTmpSignalConversionAtIn_mt =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_mTotEstim_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_tiInvEigVal_mAirOutport2' incorporates:
   *  Inport: '<Root>/InM_tiInvEigVal_mAir_INPUT'
   */
  Rte_Read_R_InM_tiInvEigVal_mAir_InM_tiInvEigVal_mAir
    (&localTmpSignalConversionAtIn_kz);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_facCoplMassPresOutport2' incorporates:
   *  Inport: '<Root>/InM_facCoplMassPres_INPUT'
   */
  Rte_Read_R_InM_facCoplMassPres_InM_facCoplMassPres
    (&localTmpSignalConversionAtI_giy);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_tiHrznPred_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_tiHrzn =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_tiHrznPred_irv();

  /* SignalConversion: '<S70>/Signal Conversion2' */
  localSignalConversion2 = InMdlT_B.TmpSignalConversionAtInM_tiHrzn;

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_tiHrznPred_facVlvOvlp_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_tiHr_o =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_tiHrznPred_facVlvOvlp_irv();

  /* SignalConversion: '<S70>/Signal Conversion3' */
  localSignalConversion3 = InMdlT_B.TmpSignalConversionAtInM_tiHr_o;

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_tiHrznPredInCyl_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_tiHr_h =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_tiHrznPredInCyl_irv();

  /* SignalConversion: '<S70>/Signal Conversion1' */
  localSignalConversion1 = InMdlT_B.TmpSignalConversionAtInM_tiHr_h;

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_rAirPresOutport2' incorporates:
   *  Inport: '<Root>/InM_rAirPres_INPUT'
   */
  Rte_Read_R_InM_rAirPres_InM_rAirPres(&localTmpSignalConversionAtIn_cc);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInThM_tMixtInMnfOutport2' incorporates:
   *  Inport: '<Root>/InThM_tMixtInMnf'
   */
  Rte_Read_R_InThM_tMixtInMnf_InThM_tMixtInMnf(&localTmpSignalConversionAtInT_i);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_f);

  /* RelationalOperator: '<S70>/Relational Operator' incorporates:
   *  Constant: '<S70>/Ext_stRun_SC'
   */
  localRelationalOperator_ns = (localTmpSignalConversionAtEng_f == Ext_stRun_SC);

  /* Outputs for enable SubSystem: '<S70>/01_Manifold_prediction' incorporates:
   *  EnablePort: '<S541>/NS_bAcv'
   *
   * Block requirements for '<S70>/01_Manifold_prediction':
   *  1. SubSystem "01_Manifold_prediction" !Trace_To : VEMS_R_11_01067_066.01 ;
   */
  if (localRelationalOperator_ns) {
    /* Outputs for atomic SubSystem: '<S541>/F01_Calc_predict_pressure' *
     * Block requirements for '<S541>/F01_Calc_predict_pressure':
     *  1. SubSystem "F01_Calc_predict_pressure" !Trace_To : VEMS_R_11_01067_067.01 ;
     */

    /* Outputs for atomic SubSystem: '<S543>/F01_Calc_predict_pressure_relaxation_term' *
     * Block requirements for '<S543>/F01_Calc_predict_pressure_relaxation_term':
     *  1. SubSystem "F01_Calc_predict_pressure_relaxation_term" !Trace_To : VEMS_R_11_01067_068.01 ;
     */

    /* Product: '<S558>/Divide' */
    localtmp = localSignalConversion2 * ((Float32)
      localTmpSignalConversionAtI_bpi);
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 10);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localDivide_dqi[0] = localtmp_0;
    localtmp = localSignalConversion3 * ((Float32)
      localTmpSignalConversionAtI_bpi);
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 10);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localDivide_dqi[1] = localtmp_0;
    localtmp = localSignalConversion1 * ((Float32)
      localTmpSignalConversionAtI_bpi);
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 10);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localDivide_dqi[2] = localtmp_0;

    /* Lookup: '<S557>/Look-Up Table'
     * About '<S557>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_hz[0]), (&(InM_facRelax_T[0])),
                  localDivide_dqi[0], (&(InM_facRelax_A[0])), 29U);
    LookUp_U8_U16( &(localLookUpTable_hz[1]), (&(InM_facRelax_T[0])),
                  localDivide_dqi[1], (&(InM_facRelax_A[0])), 29U);
    LookUp_U8_U16( &(localLookUpTable_hz[2]), (&(InM_facRelax_T[0])),
                  localDivide_dqi[2], (&(InM_facRelax_A[0])), 29U);

    /* DataTypeDuplicate Block: '<S557>/Data Type Duplicate1'
     *
     * Regarding '<S557>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S559>/Divide' incorporates:
     *  DataTypeConversion: '<S555>/Data Type Conversion1'
     *  Lookup: '<S557>/Look-Up Table'
     */
    locallocalDivide_fe_idx = (((Float32)localLookUpTable_hz[0]) * 0.00390625F)
      * localSignalConversion2;
    locallocalDivide_fe_idx_0 = (((Float32)localLookUpTable_hz[1]) *
      0.00390625F) * localSignalConversion3;
    locallocalDivide_fe_idx_1 = (((Float32)localLookUpTable_hz[2]) *
      0.00390625F) * localSignalConversion1;

    /* end of Outputs for SubSystem: '<S543>/F01_Calc_predict_pressure_relaxation_term' */

    /* Outputs for atomic SubSystem: '<S543>/F02_Calc_predict_pressure' *
     * Block requirements for '<S543>/F02_Calc_predict_pressure':
     *  1. SubSystem "F02_Calc_predict_pressure" !Trace_To : VEMS_R_11_01067_069.01 ;
     */

    /* Outputs for atomic SubSystem: '<S556>/F01_Calc_pred_pressure_classic_integration' *
     * Block requirements for '<S556>/F01_Calc_pred_pressure_classic_integration':
     *  1. SubSystem "F01_Calc_pred_pressure_classic_integration" !Trace_To : VEMS_R_11_01067_070.01 ;
     */

    /* DataTypeConversion: '<S560>/Data Type Conversion12' */
    localDataTypeConversion12_i = ((Float32)
      InMdlT_B.TmpSignalConversionAtUsThrM_p_b) * 8.0F;

    /* MinMax: '<S560>/MinMax' */

    /* DataTypeConversion: '<S543>/Data Type Conversion2' */
    localtmp = locallocalDivide_fe_idx;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_pDsThrPred[0] = localtmp_0;

    /* Sum: '<S560>/Sum' incorporates:
     *  Product: '<S562>/Divide'
     */
    InM_pDsThrPredRawNoSat_MP[0] = (locallocalDivide_fe_idx *
      localTmpSignalConversionAtIn_im) + localTmpSignalConversionAtIn_ow;
    InM_pDsThrPredRawTmp[0] = rt_MINf(localDataTypeConversion12_i,
      InM_pDsThrPredRawNoSat_MP[0]);

    /* DataTypeConversion: '<S543>/Data Type Conversion2' */
    localtmp = locallocalDivide_fe_idx_0;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_pDsThrPred[1] = localtmp_0;

    /* Sum: '<S560>/Sum' incorporates:
     *  Product: '<S562>/Divide'
     */
    InM_pDsThrPredRawNoSat_MP[1] = (locallocalDivide_fe_idx_0 *
      localTmpSignalConversionAtIn_im) + localTmpSignalConversionAtIn_ow;
    InM_pDsThrPredRawTmp[1] = rt_MINf(localDataTypeConversion12_i,
      InM_pDsThrPredRawNoSat_MP[1]);

    /* DataTypeConversion: '<S543>/Data Type Conversion2' */
    localtmp = locallocalDivide_fe_idx_1;
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 14);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_pDsThrPred[2] = localtmp_0;

    /* Sum: '<S560>/Sum' incorporates:
     *  Product: '<S562>/Divide'
     */
    InM_pDsThrPredRawNoSat_MP[2] = (locallocalDivide_fe_idx_1 *
      localTmpSignalConversionAtIn_im) + localTmpSignalConversionAtIn_ow;
    InM_pDsThrPredRawTmp[2] = rt_MINf(localDataTypeConversion12_i,
      InM_pDsThrPredRawNoSat_MP[2]);

    /* end of Outputs for SubSystem: '<S556>/F01_Calc_pred_pressure_classic_integration' */

    /* Outputs for atomic SubSystem: '<S556>/F02_Calc_reconfiguration_pression_predite' *
     * Block requirements for '<S556>/F02_Calc_reconfiguration_pression_predite':
     *  1. SubSystem "F02_Calc_reconfiguration_pression_predite" !Trace_To : VEMS_R_11_01067_071.01 ;
     */

    /* Switch: '<S561>/Switch' incorporates:
     *  Constant: '<S561>/InM_bInhPred_C'
     */
    if (InM_bInhPred_C) {
      InM_prm_pDsThrPredRawRef[0] = InMdlT_B.TmpSignalConversionAtInM_pDsT_g;
      InM_prm_pDsThrPredRawRef[1] = InMdlT_B.TmpSignalConversionAtInM_pDsT_g;
      InM_prm_pDsThrPredRawRef[2] = InMdlT_B.TmpSignalConversionAtInM_pDsT_g;
    } else {
      InM_prm_pDsThrPredRawRef[0] = InM_pDsThrPredRawTmp[0];
      InM_prm_pDsThrPredRawRef[1] = InM_pDsThrPredRawTmp[1];
      InM_prm_pDsThrPredRawRef[2] = InM_pDsThrPredRawTmp[2];
    }

    /* end of Outputs for SubSystem: '<S556>/F02_Calc_reconfiguration_pression_predite' */

    /* end of Outputs for SubSystem: '<S543>/F02_Calc_predict_pressure' */

    /* end of Outputs for SubSystem: '<S541>/F01_Calc_predict_pressure' */

    /* Outputs for atomic SubSystem: '<S541>/F02_Calc_mass_and_concentration_prediction' *
     * Block requirements for '<S541>/F02_Calc_mass_and_concentration_prediction':
     *  1. SubSystem "F02_Calc_mass_and_concentration_prediction" !Trace_To : VEMS_R_11_01067_072.01 ;
     */

    /* Outputs for atomic SubSystem: '<S544>/F01_Calc_mass_relax_term' *
     * Block requirements for '<S544>/F01_Calc_mass_relax_term':
     *  1. SubSystem "F01_Calc_mass_relax_term" !Trace_To : VEMS_R_11_01067_073.01 ;
     */

    /* DataTypeConversion: '<S563>/Data Type Conversion2' */
    localDataTypeConversion2_oc = (Float32)localTmpSignalConversionAtIn_kz;

    /* DataTypeConversion: '<S573>/OutDTConv' incorporates:
     *  Constant: '<S573>/offset'
     *  Constant: '<S573>/offset1'
     *  Constant: '<S573>/one_on_slope'
     *  Product: '<S573>/Product4'
     *  Product: '<S575>/Divide'
     *  Sum: '<S573>/Add1'
     *  Sum: '<S573>/Add2'
     */
    locallocalDivide_fe_idx_1 = ((localSignalConversion2 *
      localDataTypeConversion2_oc) * 1024.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localOutDTConv_p[0] = localtmp_0;
    locallocalDivide_fe_idx_1 = ((localSignalConversion3 *
      localDataTypeConversion2_oc) * 1024.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localOutDTConv_p[1] = localtmp_0;
    locallocalDivide_fe_idx_1 = ((localSignalConversion1 *
      localDataTypeConversion2_oc) * 1024.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    localOutDTConv_p[2] = localtmp_0;

    /* Lookup: '<S571>/Look-Up Table'
     * About '<S571>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_a0[0]), (&(InM_facRelax_T[0])),
                  localOutDTConv_p[0], (&(InM_facRelax_A[0])), 29U);
    LookUp_U8_U16( &(localLookUpTable_a0[1]), (&(InM_facRelax_T[0])),
                  localOutDTConv_p[1], (&(InM_facRelax_A[0])), 29U);
    LookUp_U8_U16( &(localLookUpTable_a0[2]), (&(InM_facRelax_T[0])),
                  localOutDTConv_p[2], (&(InM_facRelax_A[0])), 29U);

    /* DataTypeDuplicate Block: '<S571>/Data Type Duplicate1'
     *
     * Regarding '<S571>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S572>/OutDTConv' incorporates:
     *  Constant: '<S572>/offset'
     *  Constant: '<S572>/offset1'
     *  Constant: '<S572>/one_on_slope'
     *  DataTypeConversion: '<S563>/Data Type Conversion1'
     *  Lookup: '<S571>/Look-Up Table'
     *  Product: '<S572>/Product4'
     *  Product: '<S574>/Divide'
     *  Sum: '<S572>/Add1'
     *  Sum: '<S572>/Add2'
     */
    locallocalDivide_fe_idx_1 = (((((Float32)localLookUpTable_a0[0]) *
      0.00390625F) * localSignalConversion2) * 16384.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_mTotPred[0] = localtmp_0;
    locallocalDivide_fe_idx_1 = (((((Float32)localLookUpTable_a0[1]) *
      0.00390625F) * localSignalConversion3) * 16384.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_mTotPred[1] = localtmp_0;
    locallocalDivide_fe_idx_1 = (((((Float32)localLookUpTable_a0[2]) *
      0.00390625F) * localSignalConversion1) * 16384.0F) + 0.5F;
    if (locallocalDivide_fe_idx_1 < 65536.0F) {
      if (locallocalDivide_fe_idx_1 >= 0.0F) {
        localtmp_0 = (UInt16)locallocalDivide_fe_idx_1;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    InM_tiRelax_mTotPred[2] = localtmp_0;

    /* end of Outputs for SubSystem: '<S544>/F01_Calc_mass_relax_term' */

    /* Outputs for atomic SubSystem: '<S544>/F02_Calc_mass_press_relax_term' *
     * Block requirements for '<S544>/F02_Calc_mass_press_relax_term':
     *  1. SubSystem "F02_Calc_mass_press_relax_term" !Trace_To : VEMS_R_11_01067_074.01 ;
     */

    /* Abs: '<S564>/Abs1' incorporates:
     *  Sum: '<S564>/Sum1'
     */
    localDataTypeConversion2_oc = ACTEMS_FabsF((Float32)
      (localTmpSignalConversionAtIn_kz - localTmpSignalConversionAtI_bpi));

    /* RelationalOperator: '<S564>/Relational Operator1' incorporates:
     *  Constant: '<S564>/Constant6'
     */
    localRelationalOperator1_m5 = (localTmpSignalConversionAtI_giy == 0);

    /* end of Outputs for SubSystem: '<S544>/F02_Calc_mass_press_relax_term' */

    /* Outputs for atomic SubSystem: '<S544>/F03_Calc_predict_egr_mass' *
     * Block requirements for '<S544>/F03_Calc_predict_egr_mass':
     *  1. SubSystem "F03_Calc_predict_egr_mass" !Trace_To : VEMS_R_11_01067_075.01 ;
     */

    /* Sum: '<S564>/Sum' */
    locallocalSum_j = InM_tiRelax_pDsThrPred[0] - InM_tiRelax_mTotPred[0];

    /* Abs: '<S564>/Abs' */
    if (locallocalSum_j < 0) {
      InM_tiRelaxMassAir_MP[0] = (UInt16)(-locallocalSum_j);
    } else {
      InM_tiRelaxMassAir_MP[0] = (UInt16)locallocalSum_j;
    }

    /* Logic: '<S564>/Logical Operator' incorporates:
     *  Constant: '<S564>/Constant1'
     *  RelationalOperator: '<S564>/Relational Operator'
     */
    InM_bSelFacRelaxCop_MP[0] = ((localRelationalOperator1_m5) || (0 ==
      InM_tiRelaxMassAir_MP[0]));

    /* Product: '<S576>/Divide' incorporates:
     *  Product: '<S577>/Divide'
     */
    locallocalDivide_fe_idx_1 = ((((Float32)InM_tiRelaxMassAir_MP[0]) *
      6.103515625E-005F) * (((Float32)localTmpSignalConversionAtI_giy) *
      1.490116119E-008F)) / localDataTypeConversion2_oc;

    /* Switch: '<S564>/Switch' incorporates:
     *  Constant: '<S564>/Constant7'
     *  Constant: '<S579>/Constant1'
     *  Constant: '<S579>/Constant2'
     *  Constant: '<S579>/Constant3'
     *  Logic: '<S579>/Logical Operator1'
     *  RelationalOperator: '<S579>/Relational Operator'
     *  RelationalOperator: '<S579>/Relational Operator1'
     *  RelationalOperator: '<S579>/Relational Operator3'
     *  Switch: '<S579>/Switch1'
     */
    if (InM_bSelFacRelaxCop_MP[0]) {
      InM_facRelaxCoplMassPresPred[0] = 0.0F;
    } else if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
                (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) ||
               (-3.000000005E+038F > locallocalDivide_fe_idx_1)) {
      InM_facRelaxCoplMassPresPred[0] = 0.0F;
    } else {
      InM_facRelaxCoplMassPresPred[0] = locallocalDivide_fe_idx_1;
    }

    /* Outputs for atomic SubSystem: '<S565>/F01_Calc_egr_relax_term' *
     * Block requirements for '<S565>/F01_Calc_egr_relax_term':
     *  1. SubSystem "F01_Calc_egr_relax_term" !Trace_To : VEMS_R_11_01067_076.01 ;
     */

    /* DataTypeConversion: '<S580>/Data Type Conversion' */
    InM_tiRelax_mEGRPred[0] = ((Float32)InM_tiRelax_mTotPred[0]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S565>/F01_Calc_egr_relax_term' */

    /* Sum: '<S564>/Sum' */
    locallocalSum_j = InM_tiRelax_pDsThrPred[1] - InM_tiRelax_mTotPred[1];

    /* Abs: '<S564>/Abs' */
    if (locallocalSum_j < 0) {
      InM_tiRelaxMassAir_MP[1] = (UInt16)(-locallocalSum_j);
    } else {
      InM_tiRelaxMassAir_MP[1] = (UInt16)locallocalSum_j;
    }

    /* Logic: '<S564>/Logical Operator' incorporates:
     *  Constant: '<S564>/Constant1'
     *  RelationalOperator: '<S564>/Relational Operator'
     */
    InM_bSelFacRelaxCop_MP[1] = ((localRelationalOperator1_m5) || (0 ==
      InM_tiRelaxMassAir_MP[1]));

    /* Product: '<S576>/Divide' incorporates:
     *  Product: '<S577>/Divide'
     */
    locallocalDivide_fe_idx_1 = ((((Float32)InM_tiRelaxMassAir_MP[1]) *
      6.103515625E-005F) * (((Float32)localTmpSignalConversionAtI_giy) *
      1.490116119E-008F)) / localDataTypeConversion2_oc;

    /* Switch: '<S564>/Switch' incorporates:
     *  Constant: '<S564>/Constant7'
     *  Constant: '<S579>/Constant1'
     *  Constant: '<S579>/Constant2'
     *  Constant: '<S579>/Constant3'
     *  Logic: '<S579>/Logical Operator1'
     *  RelationalOperator: '<S579>/Relational Operator'
     *  RelationalOperator: '<S579>/Relational Operator1'
     *  RelationalOperator: '<S579>/Relational Operator3'
     *  Switch: '<S579>/Switch1'
     */
    if (InM_bSelFacRelaxCop_MP[1]) {
      InM_facRelaxCoplMassPresPred[1] = 0.0F;
    } else if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
                (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) ||
               (-3.000000005E+038F > locallocalDivide_fe_idx_1)) {
      InM_facRelaxCoplMassPresPred[1] = 0.0F;
    } else {
      InM_facRelaxCoplMassPresPred[1] = locallocalDivide_fe_idx_1;
    }

    /* Outputs for atomic SubSystem: '<S565>/F01_Calc_egr_relax_term' *
     * Block requirements for '<S565>/F01_Calc_egr_relax_term':
     *  1. SubSystem "F01_Calc_egr_relax_term" !Trace_To : VEMS_R_11_01067_076.01 ;
     */

    /* DataTypeConversion: '<S580>/Data Type Conversion' */
    InM_tiRelax_mEGRPred[1] = ((Float32)InM_tiRelax_mTotPred[1]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S565>/F01_Calc_egr_relax_term' */

    /* Sum: '<S564>/Sum' */
    locallocalSum_j = InM_tiRelax_pDsThrPred[2] - InM_tiRelax_mTotPred[2];

    /* Abs: '<S564>/Abs' */
    if (locallocalSum_j < 0) {
      InM_tiRelaxMassAir_MP[2] = (UInt16)(-locallocalSum_j);
    } else {
      InM_tiRelaxMassAir_MP[2] = (UInt16)locallocalSum_j;
    }

    /* Logic: '<S564>/Logical Operator' incorporates:
     *  Constant: '<S564>/Constant1'
     *  RelationalOperator: '<S564>/Relational Operator'
     */
    InM_bSelFacRelaxCop_MP[2] = ((localRelationalOperator1_m5) || (0 ==
      InM_tiRelaxMassAir_MP[2]));

    /* Product: '<S576>/Divide' incorporates:
     *  Product: '<S577>/Divide'
     */
    locallocalDivide_fe_idx_1 = ((((Float32)InM_tiRelaxMassAir_MP[2]) *
      6.103515625E-005F) * (((Float32)localTmpSignalConversionAtI_giy) *
      1.490116119E-008F)) / localDataTypeConversion2_oc;

    /* Switch: '<S564>/Switch' incorporates:
     *  Constant: '<S564>/Constant7'
     *  Constant: '<S579>/Constant1'
     *  Constant: '<S579>/Constant2'
     *  Constant: '<S579>/Constant3'
     *  Logic: '<S579>/Logical Operator1'
     *  RelationalOperator: '<S579>/Relational Operator'
     *  RelationalOperator: '<S579>/Relational Operator1'
     *  RelationalOperator: '<S579>/Relational Operator3'
     *  Switch: '<S579>/Switch1'
     */
    if (InM_bSelFacRelaxCop_MP[2]) {
      InM_facRelaxCoplMassPresPred[2] = 0.0F;
    } else if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
                (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) ||
               (-3.000000005E+038F > locallocalDivide_fe_idx_1)) {
      InM_facRelaxCoplMassPresPred[2] = 0.0F;
    } else {
      InM_facRelaxCoplMassPresPred[2] = locallocalDivide_fe_idx_1;
    }

    /* Outputs for atomic SubSystem: '<S565>/F01_Calc_egr_relax_term' *
     * Block requirements for '<S565>/F01_Calc_egr_relax_term':
     *  1. SubSystem "F01_Calc_egr_relax_term" !Trace_To : VEMS_R_11_01067_076.01 ;
     */

    /* DataTypeConversion: '<S580>/Data Type Conversion' */
    InM_tiRelax_mEGRPred[2] = ((Float32)InM_tiRelax_mTotPred[2]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S565>/F01_Calc_egr_relax_term' */

    /* Outputs for atomic SubSystem: '<S565>/F02_Calc_predict_egr_mass' *
     * Block requirements for '<S565>/F02_Calc_predict_egr_mass':
     *  1. SubSystem "F02_Calc_predict_egr_mass" !Trace_To : VEMS_R_11_01067_077.01 ;
     */

    /* DataTypeConversion: '<S581>/Data Type Conversion1' */
    localDataTypeConversion12_i = ((Float32)
      InMdlT_B.TmpSignalConversionAtInM_mEGR_g) * 1.862645149E-009F;

    /* Switch: '<S581>/Switch' incorporates:
     *  Constant: '<S581>/InM_bInhPred_C'
     *  Product: '<S582>/Divide'
     *  Sum: '<S581>/Sum3'
     */
    if (InM_bInhPred_C) {
      InM_mBurnInMnfPred[0] = localDataTypeConversion12_i;
      InM_mBurnInMnfPred[1] = localDataTypeConversion12_i;
      InM_mBurnInMnfPred[2] = localDataTypeConversion12_i;
    } else {
      InM_mBurnInMnfPred[0] = (InM_tiRelax_mEGRPred[0] *
        localTmpSignalConversionAtIn_mb) + localTmpSignalConversionAtIn_jw;
      InM_mBurnInMnfPred[1] = (InM_tiRelax_mEGRPred[1] *
        localTmpSignalConversionAtIn_mb) + localTmpSignalConversionAtIn_jw;
      InM_mBurnInMnfPred[2] = (InM_tiRelax_mEGRPred[2] *
        localTmpSignalConversionAtIn_mb) + localTmpSignalConversionAtIn_jw;
    }

    /* end of Outputs for SubSystem: '<S565>/F02_Calc_predict_egr_mass' */

    /* end of Outputs for SubSystem: '<S544>/F03_Calc_predict_egr_mass' */

    /* Outputs for atomic SubSystem: '<S544>/F04_Calc_predict_ess_mass' *
     * Block requirements for '<S544>/F04_Calc_predict_ess_mass':
     *  1. SubSystem "F04_Calc_predict_ess_mass" !Trace_To : VEMS_R_11_01067_078.01 ;
     */

    /* Outputs for atomic SubSystem: '<S566>/F01_Calc_ess_relax_term' *
     * Block requirements for '<S566>/F01_Calc_ess_relax_term':
     *  1. SubSystem "F01_Calc_ess_relax_term" !Trace_To : VEMS_R_11_01067_079.01 ;
     */

    /* DataTypeConversion: '<S583>/Data Type Conversion' */
    InM_tiRelax_mFuStmPred[0] = ((Float32)InM_tiRelax_mTotPred[0]) *
      6.103515625E-005F;
    InM_tiRelax_mFuStmPred[1] = ((Float32)InM_tiRelax_mTotPred[1]) *
      6.103515625E-005F;
    InM_tiRelax_mFuStmPred[2] = ((Float32)InM_tiRelax_mTotPred[2]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S566>/F01_Calc_ess_relax_term' */

    /* Outputs for atomic SubSystem: '<S566>/F02_Calc_predict_essence_mass' *
     * Block requirements for '<S566>/F02_Calc_predict_essence_mass':
     *  1. SubSystem "F02_Calc_predict_essence_mass" !Trace_To : VEMS_R_11_01067_080.01 ;
     */

    /* Switch: '<S584>/Switch' incorporates:
     *  Constant: '<S584>/InM_bInhPred_C'
     *  Product: '<S585>/Divide'
     *  Sum: '<S584>/Sum2'
     */
    if (InM_bInhPred_C) {
      InM_mFuInMnfMnfPred[0] = InMdlT_B.TmpSignalConversionAtInM_mFuStm;
      InM_mFuInMnfMnfPred[1] = InMdlT_B.TmpSignalConversionAtInM_mFuStm;
      InM_mFuInMnfMnfPred[2] = InMdlT_B.TmpSignalConversionAtInM_mFuStm;
    } else {
      InM_mFuInMnfMnfPred[0] = (InM_tiRelax_mFuStmPred[0] *
        localTmpSignalConversionAtIn_mp) + localTmpSignalConversionAtIn_jm;
      InM_mFuInMnfMnfPred[1] = (InM_tiRelax_mFuStmPred[1] *
        localTmpSignalConversionAtIn_mp) + localTmpSignalConversionAtIn_jm;
      InM_mFuInMnfMnfPred[2] = (InM_tiRelax_mFuStmPred[2] *
        localTmpSignalConversionAtIn_mp) + localTmpSignalConversionAtIn_jm;
    }

    /* end of Outputs for SubSystem: '<S566>/F02_Calc_predict_essence_mass' */

    /* end of Outputs for SubSystem: '<S544>/F04_Calc_predict_ess_mass' */

    /* Outputs for atomic SubSystem: '<S544>/F05_Calc_predict_air_mass' *
     * Block requirements for '<S544>/F05_Calc_predict_air_mass':
     *  1. SubSystem "F05_Calc_predict_air_mass" !Trace_To : VEMS_R_11_01067_081.01 ;
     */

    /* Outputs for atomic SubSystem: '<S567>/F03_Predict_air_mass_calc_switch' incorporates:
     *  Sum: '<S588>/Add'
     *
     * Block requirements for '<S567>/F03_Predict_air_mass_calc_switch':
     *  1. SubSystem "F03_Predict_air_mass_calc_switch" !Trace_To : VEMS_R_11_01067_084.01 ;
     */

    /* DataTypeConversion: '<S588>/Data Type Conversion12' incorporates:
     *  Constant: '<S588>/InM_facKk2_C'
     */
    localDataTypeConversion2_oc = ((Float32)InM_facKk2_C) * 1.862645149E-009F;

    /* DataTypeConversion: '<S588>/Data Type Conversion' */
    localDataTypeConversion12_i = (((Float32)localTmpSignalConversionAtInT_i) *
      0.0078125F) + 223.0F;

    /* Outputs for atomic SubSystem: '<S567>/F01_Calc_air_relax_term' *
     * Block requirements for '<S567>/F01_Calc_air_relax_term':
     *  1. SubSystem "F01_Calc_air_relax_term" !Trace_To : VEMS_R_11_01067_082.01 ;
     */

    /* DataTypeConversion: '<S586>/Data Type Conversion' */
    InM_tiRelax_mAirPred[0] = ((Float32)InM_tiRelax_mTotPred[0]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S567>/F01_Calc_air_relax_term' */

    /* Outputs for atomic SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' *
     * Block requirements for '<S567>/F02_Calc_predict_air_mass_integration':
     *  1. SubSystem "F02_Calc_predict_air_mass_integration" !Trace_To : VEMS_R_11_01067_083.01 ;
     */

    /* Sum: '<S587>/Sum1' incorporates:
     *  Product: '<S589>/Divide'
     *  Product: '<S590>/Divide'
     */
    InM_mAirPredInt[0] = ((InM_tiRelax_mAirPred[0] *
      localTmpSignalConversionAtIn_p1) + localTmpSignalConversionAtIn_py) -
      (InM_facRelaxCoplMassPresPred[0] * localTmpSignalConversionAtIn_im);

    /* end of Outputs for SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' */

    /* Product: '<S592>/Divide' incorporates:
     *  Product: '<S593>/Divide'
     */
    locallocalDivide_fe_idx_1 = (InM_prm_pDsThrPredRawRef[0] *
      localDataTypeConversion2_oc) / localDataTypeConversion12_i;

    /* Outputs for atomic SubSystem: '<S592>/If Action Subsystem3' */

    /* Switch: '<S595>/Switch1' incorporates:
     *  Constant: '<S595>/Constant1'
     *  Constant: '<S595>/Constant2'
     *  Constant: '<S595>/Constant3'
     *  Logic: '<S595>/Logical Operator1'
     *  RelationalOperator: '<S595>/Relational Operator'
     *  RelationalOperator: '<S595>/Relational Operator1'
     *  RelationalOperator: '<S595>/Relational Operator3'
     */
    if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
         (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) || (-3.000000005E+038F
         > locallocalDivide_fe_idx_1)) {
      InM_mAirCylPred_MP[0] = 1.000000047E-003F;
    } else {
      InM_mAirCylPred_MP[0] = locallocalDivide_fe_idx_1;
    }

    /* end of Outputs for SubSystem: '<S592>/If Action Subsystem3' */
    locallocalDivide_fe_idx = (InM_mAirCylPred_MP[0] - InM_mBurnInMnfPred[0]) -
      InM_mFuInMnfMnfPred[0];

    /* Outputs for atomic SubSystem: '<S567>/F01_Calc_air_relax_term' *
     * Block requirements for '<S567>/F01_Calc_air_relax_term':
     *  1. SubSystem "F01_Calc_air_relax_term" !Trace_To : VEMS_R_11_01067_082.01 ;
     */

    /* DataTypeConversion: '<S586>/Data Type Conversion' */
    InM_tiRelax_mAirPred[1] = ((Float32)InM_tiRelax_mTotPred[1]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S567>/F01_Calc_air_relax_term' */

    /* Outputs for atomic SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' *
     * Block requirements for '<S567>/F02_Calc_predict_air_mass_integration':
     *  1. SubSystem "F02_Calc_predict_air_mass_integration" !Trace_To : VEMS_R_11_01067_083.01 ;
     */

    /* Sum: '<S587>/Sum1' incorporates:
     *  Product: '<S589>/Divide'
     *  Product: '<S590>/Divide'
     */
    InM_mAirPredInt[1] = ((InM_tiRelax_mAirPred[1] *
      localTmpSignalConversionAtIn_p1) + localTmpSignalConversionAtIn_py) -
      (InM_facRelaxCoplMassPresPred[1] * localTmpSignalConversionAtIn_im);

    /* end of Outputs for SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' */

    /* Product: '<S592>/Divide' incorporates:
     *  Product: '<S593>/Divide'
     */
    locallocalDivide_fe_idx_1 = (InM_prm_pDsThrPredRawRef[1] *
      localDataTypeConversion2_oc) / localDataTypeConversion12_i;

    /* Outputs for atomic SubSystem: '<S592>/If Action Subsystem3' */

    /* Switch: '<S595>/Switch1' incorporates:
     *  Constant: '<S595>/Constant1'
     *  Constant: '<S595>/Constant2'
     *  Constant: '<S595>/Constant3'
     *  Logic: '<S595>/Logical Operator1'
     *  RelationalOperator: '<S595>/Relational Operator'
     *  RelationalOperator: '<S595>/Relational Operator1'
     *  RelationalOperator: '<S595>/Relational Operator3'
     */
    if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
         (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) || (-3.000000005E+038F
         > locallocalDivide_fe_idx_1)) {
      InM_mAirCylPred_MP[1] = 1.000000047E-003F;
    } else {
      InM_mAirCylPred_MP[1] = locallocalDivide_fe_idx_1;
    }

    /* end of Outputs for SubSystem: '<S592>/If Action Subsystem3' */
    locallocalDivide_fe_idx_0 = (InM_mAirCylPred_MP[1] - InM_mBurnInMnfPred[1])
      - InM_mFuInMnfMnfPred[1];

    /* Outputs for atomic SubSystem: '<S567>/F01_Calc_air_relax_term' *
     * Block requirements for '<S567>/F01_Calc_air_relax_term':
     *  1. SubSystem "F01_Calc_air_relax_term" !Trace_To : VEMS_R_11_01067_082.01 ;
     */

    /* DataTypeConversion: '<S586>/Data Type Conversion' */
    InM_tiRelax_mAirPred[2] = ((Float32)InM_tiRelax_mTotPred[2]) *
      6.103515625E-005F;

    /* end of Outputs for SubSystem: '<S567>/F01_Calc_air_relax_term' */

    /* Outputs for atomic SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' *
     * Block requirements for '<S567>/F02_Calc_predict_air_mass_integration':
     *  1. SubSystem "F02_Calc_predict_air_mass_integration" !Trace_To : VEMS_R_11_01067_083.01 ;
     */

    /* Sum: '<S587>/Sum1' incorporates:
     *  Product: '<S589>/Divide'
     *  Product: '<S590>/Divide'
     */
    InM_mAirPredInt[2] = ((InM_tiRelax_mAirPred[2] *
      localTmpSignalConversionAtIn_p1) + localTmpSignalConversionAtIn_py) -
      (InM_facRelaxCoplMassPresPred[2] * localTmpSignalConversionAtIn_im);

    /* end of Outputs for SubSystem: '<S567>/F02_Calc_predict_air_mass_integration' */

    /* Product: '<S592>/Divide' incorporates:
     *  Product: '<S593>/Divide'
     */
    locallocalDivide_fe_idx_1 = (InM_prm_pDsThrPredRawRef[2] *
      localDataTypeConversion2_oc) / localDataTypeConversion12_i;

    /* Outputs for atomic SubSystem: '<S592>/If Action Subsystem3' */

    /* Switch: '<S595>/Switch1' incorporates:
     *  Constant: '<S595>/Constant1'
     *  Constant: '<S595>/Constant2'
     *  Constant: '<S595>/Constant3'
     *  Logic: '<S595>/Logical Operator1'
     *  RelationalOperator: '<S595>/Relational Operator'
     *  RelationalOperator: '<S595>/Relational Operator1'
     *  RelationalOperator: '<S595>/Relational Operator3'
     */
    if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
         (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) || (-3.000000005E+038F
         > locallocalDivide_fe_idx_1)) {
      InM_mAirCylPred_MP[2] = 1.000000047E-003F;
    } else {
      InM_mAirCylPred_MP[2] = locallocalDivide_fe_idx_1;
    }

    /* end of Outputs for SubSystem: '<S592>/If Action Subsystem3' */

    /* Sum: '<S588>/Add' */
    locallocalDivide_fe_idx_1 = (InM_mAirCylPred_MP[2] - InM_mBurnInMnfPred[2])
      - InM_mFuInMnfMnfPred[2];

    /* DataTypeConversion: '<S591>/Data Type Conversion' */
    localDataTypeConversion_n = InMdlT_B.TmpSignalConversionAtExt_nEng_e;

    /* Lookup: '<S591>/Look-Up Table'
     * About '<S591>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_by), (&(InM_rAirPresFullLd_T[0])),
                   localDataTypeConversion_n, (&(Ext_nEngRef2_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S591>/Data Type Duplicate1'
     *
     * Regarding '<S591>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S588>/Data Type Conversion1' */
    localDataTypeConversion2_oc = ((Float32)
      InMdlT_B.TmpSignalConversionAtInM_mAirEs) * 1.862645149E-009F;

    /* MinMax: '<S588>/MinMax' incorporates:
     *  Constant: '<S588>/Constant2'
     */
    InM_mAirPredPres_MP[0] = rt_MAXf(locallocalDivide_fe_idx, 0.0F);
    InM_mAirPredPres_MP[1] = rt_MAXf(locallocalDivide_fe_idx_0, 0.0F);
    InM_mAirPredPres_MP[2] = rt_MAXf(locallocalDivide_fe_idx_1, 0.0F);

    /* Switch: '<S588>/Switch' incorporates:
     *  DataTypeConversion: '<S591>/Data Type Conversion'
     *  Lookup: '<S591>/Look-Up Table'
     *  RelationalOperator: '<S588>/Relational Operator'
     */
    if (localTmpSignalConversionAtIn_cc > localLookUpTable_by) {
      locallocalDivide_fe_idx = InM_mAirPredPres_MP[0];
      locallocalDivide_fe_idx_0 = InM_mAirPredPres_MP[1];
      locallocalDivide_fe_idx_1 = InM_mAirPredPres_MP[2];
    } else {
      locallocalDivide_fe_idx = InM_mAirPredInt[0];
      locallocalDivide_fe_idx_0 = InM_mAirPredInt[1];
      locallocalDivide_fe_idx_1 = InM_mAirPredInt[2];
    }

    /* Switch: '<S588>/Switch1' incorporates:
     *  Constant: '<S588>/InM_bInhPred_C'
     */
    if (InM_bInhPred_C) {
      InM_mAirPred[0] = localDataTypeConversion2_oc;
      InM_mAirPred[1] = localDataTypeConversion2_oc;
      InM_mAirPred[2] = localDataTypeConversion2_oc;
    } else {
      InM_mAirPred[0] = locallocalDivide_fe_idx;
      InM_mAirPred[1] = locallocalDivide_fe_idx_0;
      InM_mAirPred[2] = locallocalDivide_fe_idx_1;
    }

    /* end of Outputs for SubSystem: '<S567>/F03_Predict_air_mass_calc_switch' */

    /* end of Outputs for SubSystem: '<S544>/F05_Calc_predict_air_mass' */

    /* Outputs for atomic SubSystem: '<S544>/F06_Calc_predict_total_mass' *
     * Block requirements for '<S544>/F06_Calc_predict_total_mass':
     *  1. SubSystem "F06_Calc_predict_total_mass" !Trace_To : VEMS_R_11_01067_085.01 ;
     */

    /* Switch: '<S568>/Switch' incorporates:
     *  Constant: '<S568>/InM_bInhPred_C'
     *  Sum: '<S568>/Sum4'
     */
    if (InM_bInhPred_C) {
      InM_mTotPred[0] = localTmpSignalConversionAtIn_mt;
      InM_mTotPred[1] = localTmpSignalConversionAtIn_mt;
      InM_mTotPred[2] = localTmpSignalConversionAtIn_mt;
    } else {
      InM_mTotPred[0] = (InM_mAirPred[0] + InM_mFuInMnfMnfPred[0]) +
        InM_mBurnInMnfPred[0];
      InM_mTotPred[1] = (InM_mAirPred[1] + InM_mFuInMnfMnfPred[1]) +
        InM_mBurnInMnfPred[1];
      InM_mTotPred[2] = (InM_mAirPred[2] + InM_mFuInMnfMnfPred[2]) +
        InM_mBurnInMnfPred[2];
    }

    /* end of Outputs for SubSystem: '<S544>/F06_Calc_predict_total_mass' */

    /* Outputs for atomic SubSystem: '<S544>/F07_Calc_ess_concentration' *
     * Block requirements for '<S544>/F07_Calc_ess_concentration':
     *  1. SubSystem "F07_Calc_ess_concentration" !Trace_To : VEMS_R_11_01067_086.01 ;
     */

    /* Product: '<S596>/Divide' */
    locallocalDivide_fe_idx = InM_mFuInMnfMnfPred[0] / InM_mTotPred[0];
    locallocalDivide_fe_idx_0 = InM_mFuInMnfMnfPred[1] / InM_mTotPred[1];
    locallocalDivide_fe_idx_1 = InM_mFuInMnfMnfPred[2] / InM_mTotPred[2];

    /* Switch: '<S569>/Switch' incorporates:
     *  Constant: '<S569>/InM_bInhPred_C'
     *  Constant: '<S598>/Constant1'
     *  Constant: '<S598>/Constant2'
     *  Constant: '<S598>/Constant3'
     *  Logic: '<S598>/Logical Operator1'
     *  RelationalOperator: '<S598>/Relational Operator'
     *  RelationalOperator: '<S598>/Relational Operator1'
     *  RelationalOperator: '<S598>/Relational Operator3'
     *  Switch: '<S598>/Switch1'
     */
    if (InM_bInhPred_C) {
      InM_prm_concFuPredRef[0] = InMdlT_B.TmpSignalConversionAtInM_conc_n;
      InM_prm_concFuPredRef[1] = InMdlT_B.TmpSignalConversionAtInM_conc_n;
      InM_prm_concFuPredRef[2] = InMdlT_B.TmpSignalConversionAtInM_conc_n;
    } else {
      if (((locallocalDivide_fe_idx != locallocalDivide_fe_idx) ||
           (locallocalDivide_fe_idx > 3.000000005E+038F)) || (-3.000000005E+038F
           > locallocalDivide_fe_idx)) {
        InM_prm_concFuPredRef[0] = 0.0F;
      } else {
        InM_prm_concFuPredRef[0] = locallocalDivide_fe_idx;
      }

      if (((locallocalDivide_fe_idx_0 != locallocalDivide_fe_idx_0) ||
           (locallocalDivide_fe_idx_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDivide_fe_idx_0)) {
        InM_prm_concFuPredRef[1] = 0.0F;
      } else {
        InM_prm_concFuPredRef[1] = locallocalDivide_fe_idx_0;
      }

      if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
           (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDivide_fe_idx_1)) {
        InM_prm_concFuPredRef[2] = 0.0F;
      } else {
        InM_prm_concFuPredRef[2] = locallocalDivide_fe_idx_1;
      }
    }

    /* end of Outputs for SubSystem: '<S544>/F07_Calc_ess_concentration' */

    /* Outputs for atomic SubSystem: '<S544>/F08_Calc_air_concentration' *
     * Block requirements for '<S544>/F08_Calc_air_concentration':
     *  1. SubSystem "F08_Calc_air_concentration" !Trace_To : VEMS_R_11_01067_087.01 ;
     */

    /* Product: '<S599>/Divide' */
    locallocalDivide_fe_idx = InM_mAirPred[0] / InM_mTotPred[0];
    locallocalDivide_fe_idx_0 = InM_mAirPred[1] / InM_mTotPred[1];
    locallocalDivide_fe_idx_1 = InM_mAirPred[2] / InM_mTotPred[2];

    /* Switch: '<S570>/Switch' incorporates:
     *  Constant: '<S570>/InM_bInhPred_C'
     *  Constant: '<S601>/Constant1'
     *  Constant: '<S601>/Constant2'
     *  Constant: '<S601>/Constant3'
     *  Logic: '<S601>/Logical Operator1'
     *  RelationalOperator: '<S601>/Relational Operator'
     *  RelationalOperator: '<S601>/Relational Operator1'
     *  RelationalOperator: '<S601>/Relational Operator3'
     *  Switch: '<S601>/Switch1'
     */
    if (InM_bInhPred_C) {
      InM_prm_concAirPredRef[0] = InMdlT_B.TmpSignalConversionAtInM_conc_g;
      InM_prm_concAirPredRef[1] = InMdlT_B.TmpSignalConversionAtInM_conc_g;
      InM_prm_concAirPredRef[2] = InMdlT_B.TmpSignalConversionAtInM_conc_g;
    } else {
      if (((locallocalDivide_fe_idx != locallocalDivide_fe_idx) ||
           (locallocalDivide_fe_idx > 3.000000005E+038F)) || (-3.000000005E+038F
           > locallocalDivide_fe_idx)) {
        InM_prm_concAirPredRef[0] = 1.0F;
      } else {
        InM_prm_concAirPredRef[0] = locallocalDivide_fe_idx;
      }

      if (((locallocalDivide_fe_idx_0 != locallocalDivide_fe_idx_0) ||
           (locallocalDivide_fe_idx_0 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDivide_fe_idx_0)) {
        InM_prm_concAirPredRef[1] = 1.0F;
      } else {
        InM_prm_concAirPredRef[1] = locallocalDivide_fe_idx_0;
      }

      if (((locallocalDivide_fe_idx_1 != locallocalDivide_fe_idx_1) ||
           (locallocalDivide_fe_idx_1 > 3.000000005E+038F)) ||
          (-3.000000005E+038F > locallocalDivide_fe_idx_1)) {
        InM_prm_concAirPredRef[2] = 1.0F;
      } else {
        InM_prm_concAirPredRef[2] = locallocalDivide_fe_idx_1;
      }
    }

    /* end of Outputs for SubSystem: '<S544>/F08_Calc_air_concentration' */

    /* end of Outputs for SubSystem: '<S541>/F02_Calc_mass_and_concentration_prediction' */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S548>/autosar_testpoint1' */

    /* S-Function Block: <S548>/autosar_testpoint1 */
    InM_concAirPredInCyl_IRV_MP = InM_prm_concAirPredRef[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S549>/autosar_testpoint1' */

    /* S-Function Block: <S549>/autosar_testpoint1 */
    InM_concFuPred_IRV_MP = InM_prm_concFuPredRef[0];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S550>/autosar_testpoint1' */

    /* S-Function Block: <S550>/autosar_testpoint1 */
    InM_concFuPredInCyl_IRV_MP = InM_prm_concFuPredRef[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S551>/autosar_testpoint1' */

    /* S-Function Block: <S551>/autosar_testpoint1 */
    InM_pDsThr_facVlvOvlp_IRV_MP = InM_prm_pDsThrPredRawRef[1];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S552>/autosar_testpoint1' */

    /* S-Function Block: <S552>/autosar_testpoint1 */
    InM_concAirPred_IRV_MP = InM_prm_concAirPredRef[0];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S553>/autosar_testpoint1' */

    /* S-Function Block: <S553>/autosar_testpoint1 */
    InM_pDsThrPredInCylRaw_IRV_MP = InM_prm_pDsThrPredRawRef[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S554>/autosar_testpoint1' */

    /* S-Function Block: <S554>/autosar_testpoint1 */
    InM_pDsThrPredRaw_IRV_MP = InM_prm_pDsThrPredRawRef[0];

    /* Outputs for atomic SubSystem: '<S541>/F03_Calc_eng_speed' *
     * Block requirements for '<S541>/F03_Calc_eng_speed':
     *  1. SubSystem "F03_Calc_eng_speed" !Trace_To : VEMS_R_11_01067_088.01 ;
     */

    /* SignalConversion: '<S602>/copy' */
    localcopy_p = InMdlT_B.TmpSignalConversionAtExt_nEng_e;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S602>/autosar_testpoint1' */

    /* S-Function Block: <S602>/autosar_testpoint1 */
    InM_nEngPred_IRV_MP = localcopy_p;

    /* SignalConversion: '<S545>/Signal Conversion1' */
    InMdlT_B.InM_nEngPred_irv_m = InMdlT_B.TmpSignalConversionAtExt_nEng_e;

    /* end of Outputs for SubSystem: '<S541>/F03_Calc_eng_speed' */

    /* SignalConversion: '<S541>/Signal Conversion1' */
    localDataTypeConversion2_oc = InM_prm_concFuPredRef[2];

    /* SignalConversion: '<S541>/Signal Conversion2' */
    localDataTypeConversion12_i = InM_prm_concAirPredRef[0];

    /* SignalConversion: '<S541>/Signal Conversion3' */
    locallocalDivide_fe_idx_1 = InM_prm_pDsThrPredRawRef[2];

    /* SignalConversion: '<S541>/Signal Conversion4' */
    locallocalDivide_fe_idx = InM_prm_pDsThrPredRawRef[1];

    /* SignalConversion: '<S541>/Signal Conversion5' */
    locallocalDivide_fe_idx_0 = InM_prm_pDsThrPredRawRef[0];

    /* SignalConversion: '<S541>/Signal Conversion6' */
    localInM_concFuPred_irv = InM_prm_concFuPredRef[0];

    /* SignalConversion: '<S541>/Signal Conversion7' */
    localInM_concAirPredInCyl_irv = InM_prm_concAirPredRef[2];
  }

  /* end of Outputs for SubSystem: '<S70>/01_Manifold_prediction' */

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_nEngPred1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_nEngPr =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_nEngPred_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrPredRaw_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_pDsT_n =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pDsThrPredRaw_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrPredInCylRaw_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_pDsT_m =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pDsThrPredInCylRaw_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThr_facVlvOvlp_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_pDsT_h =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_pDsThr_facVlvOvlp_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concFuPred_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_l =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concFuPred_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concFuPredInCyl_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_b =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concFuPredInCyl_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concAirPred_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_a =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concAirPred_irv();

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concAirPredInCyl_irv1Outport2' */
  InMdlT_B.TmpSignalConversionAtInM_conc_e =
    Rte_IrvRead_RE_InMdlT_018_TEV_InM_concAirPredInCyl_irv();

  /* Outputs for enable SubSystem: '<S70>/01_NOT' incorporates:
   *  EnablePort: '<S542>/NS_bAcv'
   *  Logic: '<S70>/NAN'
   */
  if (!localRelationalOperator_ns) {
    /* SignalConversion: '<S609>/copy' */
    localcopy_f = InMdlT_B.TmpSignalConversionAtInM_nEngPr;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S609>/autosar_testpoint1' */

    /* S-Function Block: <S609>/autosar_testpoint1 */
    InM_nEngPred_IRV_MP = localcopy_f;

    /* SignalConversion: '<S542>/Signal Conversion4' */
    InMdlT_B.InM_nEngPred_irv_m = InMdlT_B.TmpSignalConversionAtInM_nEngPr;

    /* SignalConversion: '<S606>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_pDsT_n;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S606>/autosar_testpoint1' */

    /* S-Function Block: <S606>/autosar_testpoint1 */
    InM_pDsThrPredRaw_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion5' */
    locallocalDivide_fe_idx_0 = InMdlT_B.TmpSignalConversionAtInM_pDsT_n;

    /* SignalConversion: '<S607>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_pDsT_h;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S607>/autosar_testpoint1' */

    /* S-Function Block: <S607>/autosar_testpoint1 */
    InM_pDsThr_facVlvOvlp_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion6' */
    locallocalDivide_fe_idx = InMdlT_B.TmpSignalConversionAtInM_pDsT_h;

    /* SignalConversion: '<S608>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_pDsT_m;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S608>/autosar_testpoint1' */

    /* S-Function Block: <S608>/autosar_testpoint1 */
    InM_pDsThrPredInCylRaw_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion7' */
    locallocalDivide_fe_idx_1 = InMdlT_B.TmpSignalConversionAtInM_pDsT_m;

    /* SignalConversion: '<S605>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_conc_l;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S605>/autosar_testpoint1' */

    /* S-Function Block: <S605>/autosar_testpoint1 */
    InM_concFuPred_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion3' */
    localInM_concFuPred_irv = InMdlT_B.TmpSignalConversionAtInM_conc_l;

    /* SignalConversion: '<S604>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_conc_b;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S604>/autosar_testpoint1' */

    /* S-Function Block: <S604>/autosar_testpoint1 */
    InM_concFuPredInCyl_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion8' */
    localDataTypeConversion2_oc = InMdlT_B.TmpSignalConversionAtInM_conc_b;

    /* SignalConversion: '<S610>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_conc_a;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S610>/autosar_testpoint1' */

    /* S-Function Block: <S610>/autosar_testpoint1 */
    InM_concAirPred_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion2' */
    localDataTypeConversion12_i = InMdlT_B.TmpSignalConversionAtInM_conc_a;

    /* SignalConversion: '<S603>/copy' */
    localcopy_n = InMdlT_B.TmpSignalConversionAtInM_conc_e;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S603>/autosar_testpoint1' */

    /* S-Function Block: <S603>/autosar_testpoint1 */
    InM_concAirPredInCyl_IRV_MP = localcopy_n;

    /* SignalConversion: '<S542>/Signal Conversion1' */
    localInM_concAirPredInCyl_irv = InMdlT_B.TmpSignalConversionAtInM_conc_e;
  }

  /* end of Outputs for SubSystem: '<S70>/01_NOT' */

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concAirPredInCyl_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_concAirPredInCyl_irv
    (localInM_concAirPredInCyl_irv);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concAirPred_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_concAirPred_irv(localDataTypeConversion12_i);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concFuPredInCyl_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_concFuPredInCyl_irv
    (localDataTypeConversion2_oc);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_concFuPred_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_concFuPred_irv(localInM_concFuPred_irv);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_nEngPredInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_nEngPred_irv(InMdlT_B.InM_nEngPred_irv_m);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrPredInCylRaw_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_pDsThrPredInCylRaw_irv
    (locallocalDivide_fe_idx_1);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThrPredRaw_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_pDsThrPredRaw_irv(locallocalDivide_fe_idx_0);

  /* SignalConversion: '<S70>/TmpSignal ConversionAtInM_pDsThr_facVlvOvlp_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_018_TEV_InM_pDsThr_facVlvOvlp_irv
    (locallocalDivide_fe_idx);
}

/* Start for exported function: RE_InMdlT_044_MSE */
void RE_InMdlT_044_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S27>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F05_1_Init_Reset_model_pression'
   *
   * Block requirements for '<S1>/INM3_F05_1_Init_Reset_model_pression':
   *  1. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_104.01 ;
   *  2. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_103.01 ;
   *  3. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_102.01 ;
   *  4. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_364.01 ;
   *  5. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  6. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  7. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  8. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_318.02 ;
   *  9. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  10. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  11. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  12. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  13. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_291.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_044_MSE */
void RE_InMdlT_044_MSE(void)
{
  Float32 localTmpSignalConversionAtIn_mj;

  /* S-Function (fcncallgen): '<S27>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F05_1_Init_Reset_model_pression'
   *
   * Block requirements for '<S1>/INM3_F05_1_Init_Reset_model_pression':
   *  1. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_104.01 ;
   *  2. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_103.01 ;
   *  3. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_102.01 ;
   *  4. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_364.01 ;
   *  5. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  6. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  7. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  8. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_318.02 ;
   *  9. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  10. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  11. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  12. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  13. SubSystem "INM3_F05_1_Init_Reset_model_pression" !Trace_To : VEMS_R_11_01067_291.02 ;
   */

  /* SignalConversion: '<S612>/copy' incorporates:
   *  Constant: '<S71>/Constant1'
   */
  InM_cntPrevSenPres_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S612>/autosar_testpoint1' */

  /* S-Function Block: <S612>/autosar_testpoint1 */

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_cntSenPresInport2' incorporates:
   *  Constant: '<S71>/Constant1'
   *  SignalConversion: '<S71>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_cntPrevSenPres_irv(0U);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pDsThrEstimLoResl_irvOutport2' */
  localTmpSignalConversionAtIn_mj =
    Rte_IrvRead_RE_InMdlT_044_MSE_InM_pDsThrEstimLoResl_irv();

  /* SignalConversion: '<S611>/copy' */
  InM_pPrevSenFil_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S611>/autosar_testpoint1' */

  /* S-Function Block: <S611>/autosar_testpoint1 */

  /* SignalConversion: '<S613>/copy' */
  InM_pPrev1SenFil_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S613>/autosar_testpoint1' */

  /* S-Function Block: <S613>/autosar_testpoint1 */

  /* SignalConversion: '<S614>/copy' */
  InM_pPrevSenSat_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S614>/autosar_testpoint1' */

  /* S-Function Block: <S614>/autosar_testpoint1 */

  /* SignalConversion: '<S615>/copy' */
  InM_pPrevSenBuffer_02_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S615>/autosar_testpoint1' */

  /* S-Function Block: <S615>/autosar_testpoint1 */

  /* SignalConversion: '<S616>/copy' */
  InM_pPrevSenBuffer_01_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S616>/autosar_testpoint1' */

  /* S-Function Block: <S616>/autosar_testpoint1 */

  /* SignalConversion: '<S617>/copy' */
  InM_pPrevSenBuffer_03_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S617>/autosar_testpoint1' */

  /* S-Function Block: <S617>/autosar_testpoint1 */

  /* SignalConversion: '<S618>/copy' */
  InM_pPrevSenBuffer_04_IRV_MP = localTmpSignalConversionAtIn_mj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S618>/autosar_testpoint1' */

  /* S-Function Block: <S618>/autosar_testpoint1 */

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pPrev1SenFilInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrev1SenFil_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pPrevSenBuffer_01_irvInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenBuffer_01_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pPrevSenBuffer_02_irvInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion16'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenBuffer_02_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pPrevSenBuffer_03_irvInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion17'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenBuffer_03_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pPrevSenBuffer_04_irvInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion18'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenBuffer_04_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pSenFilInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenFil_irv
    (localTmpSignalConversionAtIn_mj);

  /* SignalConversion: '<S71>/TmpSignal ConversionAtInM_pSenSatInport2' incorporates:
   *  SignalConversion: '<S71>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_InMdlT_044_MSE_InM_pPrevSenSat_irv
    (localTmpSignalConversionAtIn_mj);
}

/* Start for exported function: RE_InMdlT_022_TEV */
void RE_InMdlT_022_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S29>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F05_2_Manage_model_acqui_pression'
   *
   * Block requirements for '<S1>/INM3_F05_2_Manage_model_acqui_pression':
   *  1. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_102.01 ;
   *  2. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_103.01 ;
   *  3. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_105.01 ;
   *  4. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_342.02 ;
   *  5. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_318.02 ;
   *  6. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  7. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  8. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  9. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  10. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  11. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  12. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  13. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  14. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  15. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_291.02 ;
   */

  /* Start for ifaction SubSystem: '<S72>/Function-Call Subsystem1' */

  /* Start for S-Function (fcncallgen): '<S622>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S72>/F01_Reinit_model_acqui_pression'
   *
   * Block requirements for '<S72>/F01_Reinit_model_acqui_pression':
   *  1. SubSystem "F01_Reinit_model_acqui_pression" !Trace_To : VEMS_R_11_01067_106.01 ;
   */

  /* end of Start for SubSystem: '<S72>/Function-Call Subsystem1' */

  /* Start for ifaction SubSystem: '<S72>/Function-Call Subsystem' */

  /* Start for S-Function (fcncallgen): '<S621>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S72>/F02_Filtrer_entree_pression'
   *
   * Block requirements for '<S72>/F02_Filtrer_entree_pression':
   *  1. SubSystem "F02_Filtrer_entree_pression" !Trace_To : VEMS_R_11_01067_107.01 ;
   */

  /* end of Start for SubSystem: '<S72>/Function-Call Subsystem' */
}

/* Output and update for exported function: RE_InMdlT_022_TEV */
void RE_InMdlT_022_TEV(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_df;
  Float32 localTmpSignalConversionAtIn_bx;
  Float32 localTmpSignalConversionAtIn_ky;
  Float32 localTmpSignalConversionAtIn_pz;
  Float32 localTmpSignalConversionAtIn_jr;
  Float32 localTmpSignalConversionAtIn_oq;
  Float32 localTmpSignalConversionAtIn_gz;
  Float32 localSum4_k;
  Float32 localMinMax_l;
  Float32 localAssignment[4];
  UInt8 localTmpSignalConversionAtIn_fi;
  UInt8 localMathFunction_g;
  UInt8 localTmpSignalConversionAtEn_a0;
  Float32 localTmpSignalConversionAtIn_os;
  Float32 localInM_pDsThrSenEstim_irv_c;
  Float32 localInM_pPrev1SenFil_irv_n;
  Float32 localInM_pPrevSenBuffer_01_irv_;
  Float32 localInM_pPrevSenBuffer_02_irv_;
  Float32 localInM_pPrevSenBuffer_04_irv_;
  Float32 localInM_pPrevSenFil_irv_o;
  Float32 localInM_pPrevSenSat_irv_c;
  SInt32 localtmp;

  /* S-Function (fcncallgen): '<S29>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F05_2_Manage_model_acqui_pression'
   *
   * Block requirements for '<S1>/INM3_F05_2_Manage_model_acqui_pression':
   *  1. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_102.01 ;
   *  2. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_103.01 ;
   *  3. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_105.01 ;
   *  4. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_342.02 ;
   *  5. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_318.02 ;
   *  6. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  7. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  8. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  9. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  10. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  11. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  12. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  13. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  14. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  15. SubSystem "INM3_F05_2_Manage_model_acqui_pression" !Trace_To : VEMS_R_11_01067_291.02 ;
   */

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pDsThrEstimLoResl_irvOutport2' */
  localTmpSignalConversionAtIn_df =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pDsThrEstimLoResl_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_cntSenPres1Outport2' */
  localTmpSignalConversionAtIn_fi =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_cntPrevSenPres_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_01_irv1Outport2' */
  localTmpSignalConversionAtIn_bx =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_01_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_02_irv1Outport2' */
  localTmpSignalConversionAtIn_ky =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_02_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_03_irv1Outport2' */
  localTmpSignalConversionAtIn_pz =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_03_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_04_irv4Outport2' */
  localTmpSignalConversionAtIn_jr =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_04_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEn_a0);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenSatOutport2' */
  localTmpSignalConversionAtIn_os =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenSat_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenFilOutport2' */
  localTmpSignalConversionAtIn_oq =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pPrevSenFil_irv();

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pDsThrSenEstim_irv1Outport2' */
  localTmpSignalConversionAtIn_gz =
    Rte_IrvRead_RE_InMdlT_022_TEV_InM_pDsThrSenEstim_irv();

  /* If: '<S72>/If1' incorporates:
   *  ActionPort: '<S621>/Action Port'
   *  ActionPort: '<S622>/Action Port'
   *  Constant: '<S72>/Ext_stRun_SC'
   *  Constant: '<S72>/InM_bInhSenMdl_C'
   *  Logic: '<S72>/Logical Operator1'
   *  Logic: '<S72>/Logical Operator3'
   *  RelationalOperator: '<S72>/Relational Operator'
   *  SubSystem: '<S72>/Function-Call Subsystem'
   *  SubSystem: '<S72>/Function-Call Subsystem1'
   */
  if ((localTmpSignalConversionAtEn_a0 == Ext_stRun_SC) && (!InM_bInhSenMdl_C))
  {
    /* S-Function (fcncallgen): '<S621>/Function-Call Generator' incorporates:
     *  SubSystem: '<S72>/F02_Filtrer_entree_pression'
     *
     * Block requirements for '<S72>/F02_Filtrer_entree_pression':
     *  1. SubSystem "F02_Filtrer_entree_pression" !Trace_To : VEMS_R_11_01067_107.01 ;
     */

    /* Outputs for atomic SubSystem: '<S620>/F01_trunc_pressure' *
     * Block requirements for '<S620>/F01_trunc_pressure':
     *  1. SubSystem "F01_trunc_pressure" !Trace_To : VEMS_R_11_01067_108.01 ;
     */

    /* DataTypeConversion: '<S632>/Data Type Conversion1' incorporates:
     *  Constant: '<S632>/InM_pSenLoThd_C'
     */
    localInM_pPrevSenSat_irv_c = ((Float32)InM_pSenLoThd_C) * 8.0F;

    /* MinMax: '<S632>/MinMax1' */
    localInM_pPrevSenSat_irv_c = rt_MAXf(localTmpSignalConversionAtIn_df,
      localInM_pPrevSenSat_irv_c);

    /* DataTypeConversion: '<S632>/Data Type Conversion2' incorporates:
     *  Constant: '<S632>/InM_pSenHiThd_C'
     */
    localInM_pPrevSenBuffer_02_irv_ = ((Float32)InM_pSenHiThd_C) * 8.0F;

    /* MinMax: '<S632>/MinMax' */
    localMinMax_l = rt_MINf(localInM_pPrevSenSat_irv_c,
      localInM_pPrevSenBuffer_02_irv_);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S640>/autosar_testpoint1' */

    /* S-Function Block: <S640>/autosar_testpoint1 */
    InM_pPrevSenSat_IRV_MP = localMinMax_l;

    /* end of Outputs for SubSystem: '<S620>/F01_trunc_pressure' */

    /* Outputs for atomic SubSystem: '<S620>/F02_RC_filter' *
     * Block requirements for '<S620>/F02_RC_filter':
     *  1. SubSystem "F02_RC_filter" !Trace_To : VEMS_R_11_01067_109.01 ;
     */

    /* Sum: '<S633>/Sum1' incorporates:
     *  Constant: '<S633>/InM_pSenFilGain1_C'
     *  Constant: '<S633>/InM_pSenFilGain2_C'
     *  DataTypeConversion: '<S633>/Data Type Conversion3'
     *  DataTypeConversion: '<S633>/Data Type Conversion6'
     *  Product: '<S644>/Divide'
     *  Product: '<S645>/Divide'
     *  Sum: '<S633>/Sum2'
     *  Sum: '<S633>/Sum3'
     */
    localInM_pPrevSenSat_irv_c = ((localTmpSignalConversionAtIn_os -
      localTmpSignalConversionAtIn_oq) * (((Float32)InM_pSenFilGain1_C) *
      0.00390625F)) + ((localMinMax_l - localTmpSignalConversionAtIn_os) *
                       (((Float32)InM_pSenFilGain2_C) * 0.00390625F));

    /* DataStoreWrite: '<S633>/Data Store Write2' incorporates:
     *  Constant: '<S641>/offset'
     *  Constant: '<S641>/offset1'
     *  Constant: '<S641>/one_on_slope'
     *  DataTypeConversion: '<S641>/OutDTConv'
     *  Product: '<S641>/Product4'
     *  Sum: '<S641>/Add1'
     *  Sum: '<S641>/Add2'
     */
    localTmpSignalConversionAtIn_os = (0.125F * localInM_pPrevSenSat_irv_c) +
      0.5F;
    if (localTmpSignalConversionAtIn_os < 65536.0F) {
      if (localTmpSignalConversionAtIn_os >= 0.0F) {
        InM_pSenFilRaw_MP = (UInt16)localTmpSignalConversionAtIn_os;
      } else {
        InM_pSenFilRaw_MP = 0U;
      }
    } else {
      InM_pSenFilRaw_MP = MAX_uint16_T;
    }

    /* Sum: '<S633>/Sum4' */
    localSum4_k = localTmpSignalConversionAtIn_oq + localInM_pPrevSenSat_irv_c;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S642>/autosar_testpoint1' */

    /* S-Function Block: <S642>/autosar_testpoint1 */
    InM_pPrevSenFil_IRV_MP = localSum4_k;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S643>/autosar_testpoint1' */

    /* S-Function Block: <S643>/autosar_testpoint1 */
    InM_pPrev1SenFil_IRV_MP = localTmpSignalConversionAtIn_oq;

    /* SignalConversion: '<S633>/Signal Conversion2' */
    localInM_pPrev1SenFil_irv_n = localTmpSignalConversionAtIn_oq;

    /* end of Outputs for SubSystem: '<S620>/F02_RC_filter' */

    /* SignalConversion: '<S620>/Signal Conversion1' */
    localInM_pPrevSenSat_irv_c = localMinMax_l;

    /* SignalConversion: '<S620>/Signal Conversion2' */
    localInM_pPrevSenFil_irv_o = localSum4_k;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S638>/autosar_testpoint1' */

    /* S-Function Block: <S638>/autosar_testpoint1 */
    InM_cntPrevSenPres_IRV_MP = localTmpSignalConversionAtIn_fi;

    /* SignalConversion: '<S620>/Signal Conversion3' */
    localTmpSignalConversionAtEn_a0 = localTmpSignalConversionAtIn_fi;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S637>/autosar_testpoint1' */

    /* S-Function Block: <S637>/autosar_testpoint1 */
    InM_pDsThrSenEstim_IRV_MP = localTmpSignalConversionAtIn_gz;

    /* SignalConversion: '<S620>/Signal Conversion4' */
    localInM_pDsThrSenEstim_irv_c = localTmpSignalConversionAtIn_gz;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S639>/autosar_testpoint1' */

    /* S-Function Block: <S639>/autosar_testpoint1 */
    InM_pPrevSenBuffer_01_IRV_MP = localTmpSignalConversionAtIn_bx;

    /* SignalConversion: '<S620>/Signal Conversion5' */
    localInM_pPrevSenBuffer_01_irv_ = localTmpSignalConversionAtIn_bx;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S634>/autosar_testpoint1' */

    /* S-Function Block: <S634>/autosar_testpoint1 */
    InM_pPrevSenBuffer_02_IRV_MP = localTmpSignalConversionAtIn_ky;

    /* SignalConversion: '<S620>/Signal Conversion6' */
    localInM_pPrevSenBuffer_02_irv_ = localTmpSignalConversionAtIn_ky;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S635>/autosar_testpoint1' */

    /* S-Function Block: <S635>/autosar_testpoint1 */
    InM_pPrevSenBuffer_03_IRV_MP = localTmpSignalConversionAtIn_pz;

    /* SignalConversion: '<S620>/Signal Conversion7' */
    localTmpSignalConversionAtIn_os = localTmpSignalConversionAtIn_pz;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S636>/autosar_testpoint1' */

    /* S-Function Block: <S636>/autosar_testpoint1 */
    InM_pPrevSenBuffer_04_IRV_MP = localTmpSignalConversionAtIn_jr;

    /* SignalConversion: '<S620>/Signal Conversion8' */
    localInM_pPrevSenBuffer_04_irv_ = localTmpSignalConversionAtIn_jr;
  } else {
    /* S-Function (fcncallgen): '<S622>/Function-Call Generator' incorporates:
     *  SubSystem: '<S72>/F01_Reinit_model_acqui_pression'
     *
     * Block requirements for '<S72>/F01_Reinit_model_acqui_pression':
     *  1. SubSystem "F01_Reinit_model_acqui_pression" !Trace_To : VEMS_R_11_01067_106.01 ;
     */

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S623>/autosar_testpoint1' */
    /* S-Function Block: <S623>/autosar_testpoint1 */
    InM_pPrevSenFil_IRV_MP = localTmpSignalConversionAtIn_df;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S624>/autosar_testpoint1' */

    /* S-Function Block: <S624>/autosar_testpoint1 */
    InM_pDsThrSenEstim_IRV_MP = localTmpSignalConversionAtIn_df;

    /* Sum: '<S619>/Sum3' incorporates:
     *  Constant: '<S619>/Constant2'
     */
    localtmp = localTmpSignalConversionAtIn_fi + 1;
    if (((UInt32)localtmp) > 255U) {
      localMathFunction_g = MAX_uint8_T;
    } else {
      localMathFunction_g = (UInt8)localtmp;
    }

    /* Math: '<S619>/Math Function' incorporates:
     *  Constant: '<S619>/Constant1'
     */
    localMathFunction_g = rt_mod_uint8(localMathFunction_g, 4U);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S625>/autosar_testpoint1' */

    /* S-Function Block: <S625>/autosar_testpoint1 */
    InM_cntPrevSenPres_IRV_MP = localMathFunction_g;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S626>/autosar_testpoint1' */

    /* S-Function Block: <S626>/autosar_testpoint1 */
    InM_pPrev1SenFil_IRV_MP = localTmpSignalConversionAtIn_df;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S627>/autosar_testpoint1' */

    /* S-Function Block: <S627>/autosar_testpoint1 */
    InM_pPrevSenSat_IRV_MP = localTmpSignalConversionAtIn_df;

    /* SignalConversion: '<S619>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment[0] = localTmpSignalConversionAtIn_bx;
    localAssignment[1] = localTmpSignalConversionAtIn_ky;
    localAssignment[2] = localTmpSignalConversionAtIn_pz;
    localAssignment[3] = localTmpSignalConversionAtIn_jr;

    /* Assignment: '<S619>/Assignment' */
    localAssignment[(SInt32)localTmpSignalConversionAtIn_fi] =
      localTmpSignalConversionAtIn_df;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S628>/autosar_testpoint1' */

    /* S-Function Block: <S628>/autosar_testpoint1 */
    InM_pPrevSenBuffer_02_IRV_MP = localAssignment[1];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S629>/autosar_testpoint1' */

    /* S-Function Block: <S629>/autosar_testpoint1 */
    InM_pPrevSenBuffer_01_IRV_MP = localAssignment[0];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S630>/autosar_testpoint1' */

    /* S-Function Block: <S630>/autosar_testpoint1 */
    InM_pPrevSenBuffer_03_IRV_MP = localAssignment[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S631>/autosar_testpoint1' */

    /* S-Function Block: <S631>/autosar_testpoint1 */
    InM_pPrevSenBuffer_04_IRV_MP = localAssignment[3];

    /* SignalConversion: '<S619>/Signal Conversion1' */
    localInM_pPrevSenSat_irv_c = localTmpSignalConversionAtIn_df;

    /* SignalConversion: '<S619>/Signal Conversion16' */
    localInM_pPrevSenBuffer_02_irv_ = localAssignment[1];

    /* SignalConversion: '<S619>/Signal Conversion17' */
    localTmpSignalConversionAtIn_os = localAssignment[2];

    /* SignalConversion: '<S619>/Signal Conversion18' */
    localInM_pPrevSenBuffer_04_irv_ = localAssignment[3];

    /* SignalConversion: '<S619>/Signal Conversion2' */
    localInM_pPrevSenFil_irv_o = localTmpSignalConversionAtIn_df;

    /* SignalConversion: '<S619>/Signal Conversion21' */
    localInM_pPrevSenBuffer_01_irv_ = localAssignment[0];

    /* SignalConversion: '<S619>/Signal Conversion4' */
    localInM_pPrev1SenFil_irv_n = localTmpSignalConversionAtIn_df;

    /* SignalConversion: '<S619>/Signal Conversion7' */
    localTmpSignalConversionAtEn_a0 = localMathFunction_g;

    /* SignalConversion: '<S619>/Signal Conversion8' */
    localInM_pDsThrSenEstim_irv_c = localTmpSignalConversionAtIn_df;
  }

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_cntSenPresInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_cntPrevSenPres_irv
    (localTmpSignalConversionAtEn_a0);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pDsThrSenEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pDsThrSenEstim_irv
    (localInM_pDsThrSenEstim_irv_c);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrev1SenFilInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrev1SenFil_irv
    (localInM_pPrev1SenFil_irv_n);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_01_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_01_irv
    (localInM_pPrevSenBuffer_01_irv_);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_02_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_02_irv
    (localInM_pPrevSenBuffer_02_irv_);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_03_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_03_irv
    (localTmpSignalConversionAtIn_os);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pPrevSenBuffer_04_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenBuffer_04_irv
    (localInM_pPrevSenBuffer_04_irv_);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pSenFilInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenFil_irv(localInM_pPrevSenFil_irv_o);

  /* SignalConversion: '<S72>/TmpSignal ConversionAtInM_pSenSatInport2' */
  Rte_IrvWrite_RE_InMdlT_022_TEV_InM_pPrevSenSat_irv(localInM_pPrevSenSat_irv_c);
}

/* Start for exported function: RE_InMdlT_024_DRE */
void RE_InMdlT_024_DRE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S30>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F05_3_Moyennage_des_acquisitions'
   *
   * Block requirements for '<S1>/INM3_F05_3_Moyennage_des_acquisitions':
   *  1. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_110.01 ;
   *  2. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_343.03 ;
   *  3. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  4. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  5. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  6. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  7. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  8. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  9. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  10. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  11. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  12. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  13. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_390.01 ;
   *  14. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_391.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_024_DRE */
void RE_InMdlT_024_DRE(void)
{
  /* local block i/o variables */
  Float32 localTmpSignalConversionAtIn_pb;
  Float32 localTmpSignalConversionAtIn_c3;
  Float32 localTmpSignalConversionAtIn_nx;
  Float32 localTmpSignalConversionAtIn_ha;
  Float32 localTmpSignalConversionAtIn_iq;
  Float32 localDivide_ie;
  Float32 localAssignment_a[4];
  UInt32 localFRT_tiPresMesTmr_irv;
  UInt8 localTmpSignalConversionAtIn_fy;
  UInt8 localMathFunction_a;
  Float32 localTmpSignalConversionAtIn_pu;
  UInt32 localTmpSignalConversionAtFRT_t;
  UInt8 localTmpSignalConversionAtEng_i;
  Float32 localInM_pPrevSenBuffer_01_ir_l;
  Float32 localInM_pPrevSenBuffer_02_ir_h;
  Float32 localInM_pPrevSenBuffer_03_ir_p;
  Float32 localInM_pPrevSenBuffer_04_ir_d;
  UInt32 localqY;
  SInt32 localtmp;

  /* S-Function (fcncallgen): '<S30>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F05_3_Moyennage_des_acquisitions'
   *
   * Block requirements for '<S1>/INM3_F05_3_Moyennage_des_acquisitions':
   *  1. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_110.01 ;
   *  2. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_343.03 ;
   *  3. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  4. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  5. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_315.02 ;
   *  6. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_352.01 ;
   *  7. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_353.01 ;
   *  8. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  9. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  10. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_316.02 ;
   *  11. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_317.02 ;
   *  12. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_314.02 ;
   *  13. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_390.01 ;
   *  14. SubSystem "INM3_F05_3_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_391.01 ;
   */

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pSenFilOutport2' */
  localTmpSignalConversionAtIn_pu =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrevSenFil_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_cntPrevSenPres_irvOutport2' */
  localTmpSignalConversionAtIn_fy =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_cntPrevSenPres_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_01_irv1Outport2' */
  localTmpSignalConversionAtIn_pb =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_01_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_02_irv1Outport2' */
  localTmpSignalConversionAtIn_c3 =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_02_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_03_irv1Outport2' */
  localTmpSignalConversionAtIn_nx =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_03_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_04_irv1Outport2' */
  localTmpSignalConversionAtIn_ha =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_04_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtFRT_tiSenFilTmr_irvOutport2' */
  localTmpSignalConversionAtFRT_t =
    Rte_IrvRead_RE_InMdlT_024_DRE_FRT_tiSenFilTmr_irv();

  /* SignalConversion: '<S73>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_i);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pDsThrSenEstim_irv1Outport2' */
  localTmpSignalConversionAtIn_iq =
    Rte_IrvRead_RE_InMdlT_024_DRE_InM_pDsThrSenEstim_irv();

  /* If: '<S73>/If1' incorporates:
   *  ActionPort: '<S646>/Action Port'
   *  ActionPort: '<S647>/Action Port'
   *  Constant: '<S73>/Ext_stRun_SC'
   *  RelationalOperator: '<S73>/Relational Operator'
   *  SubSystem: '<S73>/F01_Moyennage_des_acquisitions'
   *  SubSystem: '<S73>/F02_else'
   *
   * Block requirements for '<S73>/F01_Moyennage_des_acquisitions':
   *  1. SubSystem "F01_Moyennage_des_acquisitions" !Trace_To : VEMS_R_11_01067_111.01 ;
   */
  if (localTmpSignalConversionAtEng_i == Ext_stRun_SC) {
    /* S-Function (Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U32): '<S646>/Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U1' */
    localMathFunction_a =
      Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U32
      ( &localFRT_tiPresMesTmr_irv);

    /* Sum: '<S649>/Sum2' */
    localqY = localFRT_tiPresMesTmr_irv - localTmpSignalConversionAtFRT_t;
    if (localqY > localFRT_tiPresMesTmr_irv) {
      localqY = 0U;
    }

    /* Switch: '<S649>/Switch' incorporates:
     *  Constant: '<S649>/Constant6'
     *  Constant: '<S649>/MaxTimer100us_SC'
     *  RelationalOperator: '<S649>/Relational Operator'
     *  Sum: '<S649>/Sum6'
     *  Sum: '<S649>/Sum7'
     */
    if (!(localFRT_tiPresMesTmr_irv >= localTmpSignalConversionAtFRT_t)) {
      localTmpSignalConversionAtFRT_t = MaxTimer100us_SC -
        localTmpSignalConversionAtFRT_t;
      if (localTmpSignalConversionAtFRT_t > MaxTimer100us_SC) {
        localTmpSignalConversionAtFRT_t = 0U;
      }

      localTmpSignalConversionAtFRT_t += localFRT_tiPresMesTmr_irv;
      if (localTmpSignalConversionAtFRT_t < localFRT_tiPresMesTmr_irv) {
        localTmpSignalConversionAtFRT_t = MAX_uint32_T;
      }

      localqY = localTmpSignalConversionAtFRT_t + 1U;
      if (localqY < localTmpSignalConversionAtFRT_t) {
        localqY = MAX_uint32_T;
      }
    }

    /* Sum: '<S646>/Sum3' incorporates:
     *  Constant: '<S646>/InM_tiSampleFast_SC'
     *  Constant: '<S649>/Constant4'
     *  DataTypeConversion: '<S646>/Data Type Conversion14'
     *  Product: '<S649>/Divide'
     *  Product: '<S657>/Divide'
     *  Product: '<S658>/Divide'
     *  SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrev1SenFilOutport2'
     *  Sum: '<S646>/Sum4'
     */
    localTmpSignalConversionAtIn_pu += (((Float32)(((Float32d)localqY) / 10000.0F))
      / (((Float32)InM_tiSampleFast_SC) * 5.000000237E-004F)) *
      (localTmpSignalConversionAtIn_pu -
       Rte_IrvRead_RE_InMdlT_024_DRE_InM_pPrev1SenFil_irv());

    /* Sum: '<S648>/Add2' incorporates:
     *  Constant: '<S648>/offset'
     *  Constant: '<S648>/offset1'
     *  Constant: '<S648>/one_on_slope'
     *  Product: '<S648>/Product4'
     *  Sum: '<S648>/Add1'
     */
    localDivide_ie = (0.125F * localTmpSignalConversionAtIn_pu) + 0.5F;

    /* DataStoreWrite: '<S646>/Data Store Write2' incorporates:
     *  DataTypeConversion: '<S648>/OutDTConv'
     */
    if (localDivide_ie < 65536.0F) {
      if (localDivide_ie >= 0.0F) {
        InM_pSenBufferRaw_MP = (UInt16)localDivide_ie;
      } else {
        InM_pSenBufferRaw_MP = 0U;
      }
    } else {
      InM_pSenBufferRaw_MP = MAX_uint16_T;
    }

    /* SignalConversion: '<S646>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_a[0] = localTmpSignalConversionAtIn_pb;
    localAssignment_a[1] = localTmpSignalConversionAtIn_c3;
    localAssignment_a[2] = localTmpSignalConversionAtIn_nx;
    localAssignment_a[3] = localTmpSignalConversionAtIn_ha;

    /* Assignment: '<S646>/Assignment' */
    localAssignment_a[(SInt32)localTmpSignalConversionAtIn_fy] =
      localTmpSignalConversionAtIn_pu;

    /* Product: '<S656>/Divide' incorporates:
     *  Constant: '<S646>/Constant'
     *  Sum: '<S646>/Sum1'
     */
    localDivide_ie = (((localAssignment_a[0] + localAssignment_a[1]) +
                       localAssignment_a[2]) + localAssignment_a[3]) / 4.0F;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S650>/autosar_testpoint1' */

    /* S-Function Block: <S650>/autosar_testpoint1 */
    InM_pDsThrSenEstim_IRV_MP = localDivide_ie;

    /* Sum: '<S646>/Sum5' incorporates:
     *  Constant: '<S646>/Constant3'
     */
    localtmp = localTmpSignalConversionAtIn_fy + 1;
    if (((UInt32)localtmp) > 255U) {
      localMathFunction_a = MAX_uint8_T;
    } else {
      localMathFunction_a = (UInt8)localtmp;
    }

    /* Math: '<S646>/Math Function' incorporates:
     *  Constant: '<S646>/Constant2'
     */
    localMathFunction_a = rt_mod_uint8(localMathFunction_a, 4U);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S651>/autosar_testpoint1' */

    /* S-Function Block: <S651>/autosar_testpoint1 */
    InM_cntPrevSenPres_IRV_MP = localMathFunction_a;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S652>/autosar_testpoint1' */

    /* S-Function Block: <S652>/autosar_testpoint1 */
    InM_pPrevSenBuffer_02_IRV_MP = localAssignment_a[1];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S653>/autosar_testpoint1' */

    /* S-Function Block: <S653>/autosar_testpoint1 */
    InM_pPrevSenBuffer_01_IRV_MP = localAssignment_a[0];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S654>/autosar_testpoint1' */

    /* S-Function Block: <S654>/autosar_testpoint1 */
    InM_pPrevSenBuffer_03_IRV_MP = localAssignment_a[2];

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S655>/autosar_testpoint1' */

    /* S-Function Block: <S655>/autosar_testpoint1 */
    InM_pPrevSenBuffer_04_IRV_MP = localAssignment_a[3];

    /* SignalConversion: '<S646>/Signal Conversion1' */
    localTmpSignalConversionAtIn_pu = localDivide_ie;

    /* SignalConversion: '<S646>/Signal Conversion16' */
    localInM_pPrevSenBuffer_02_ir_h = localAssignment_a[1];

    /* SignalConversion: '<S646>/Signal Conversion17' */
    localInM_pPrevSenBuffer_03_ir_p = localAssignment_a[2];

    /* SignalConversion: '<S646>/Signal Conversion18' */
    localInM_pPrevSenBuffer_04_ir_d = localAssignment_a[3];

    /* SignalConversion: '<S646>/Signal Conversion2' */
    localTmpSignalConversionAtEng_i = localMathFunction_a;

    /* SignalConversion: '<S646>/Signal Conversion21' */
    localInM_pPrevSenBuffer_01_ir_l = localAssignment_a[0];
  } else {
    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S659>/autosar_testpoint1' */
    /* S-Function Block: <S659>/autosar_testpoint1 */
    InM_pDsThrSenEstim_IRV_MP = localTmpSignalConversionAtIn_iq;

    /* SignalConversion: '<S647>/Signal Conversion2' */
    localTmpSignalConversionAtIn_pu = localTmpSignalConversionAtIn_iq;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S660>/autosar_testpoint1' */

    /* S-Function Block: <S660>/autosar_testpoint1 */
    InM_cntPrevSenPres_IRV_MP = localTmpSignalConversionAtIn_fy;

    /* SignalConversion: '<S647>/Signal Conversion1' */
    localTmpSignalConversionAtEng_i = localTmpSignalConversionAtIn_fy;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S662>/autosar_testpoint1' */

    /* S-Function Block: <S662>/autosar_testpoint1 */
    InM_pPrevSenBuffer_01_IRV_MP = localTmpSignalConversionAtIn_pb;

    /* SignalConversion: '<S647>/Signal Conversion21' */
    localInM_pPrevSenBuffer_01_ir_l = localTmpSignalConversionAtIn_pb;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S661>/autosar_testpoint1' */

    /* S-Function Block: <S661>/autosar_testpoint1 */
    InM_pPrevSenBuffer_02_IRV_MP = localTmpSignalConversionAtIn_c3;

    /* SignalConversion: '<S647>/Signal Conversion16' */
    localInM_pPrevSenBuffer_02_ir_h = localTmpSignalConversionAtIn_c3;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S663>/autosar_testpoint1' */

    /* S-Function Block: <S663>/autosar_testpoint1 */
    InM_pPrevSenBuffer_03_IRV_MP = localTmpSignalConversionAtIn_nx;

    /* SignalConversion: '<S647>/Signal Conversion17' */
    localInM_pPrevSenBuffer_03_ir_p = localTmpSignalConversionAtIn_nx;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S664>/autosar_testpoint1' */

    /* S-Function Block: <S664>/autosar_testpoint1 */
    InM_pPrevSenBuffer_04_IRV_MP = localTmpSignalConversionAtIn_ha;

    /* SignalConversion: '<S647>/Signal Conversion18' */
    localInM_pPrevSenBuffer_04_ir_d = localTmpSignalConversionAtIn_ha;
  }

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_cntSenPresInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_cntPrevSenPres_irv
    (localTmpSignalConversionAtEng_i);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pDsThrSenEstim_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_pDsThrSenEstim_irv
    (localTmpSignalConversionAtIn_pu);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_01_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_01_irv
    (localInM_pPrevSenBuffer_01_ir_l);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_02_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_02_irv
    (localInM_pPrevSenBuffer_02_ir_h);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_03_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_03_irv
    (localInM_pPrevSenBuffer_03_ir_p);

  /* SignalConversion: '<S73>/TmpSignal ConversionAtInM_pPrevSenBuffer_04_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_024_DRE_InM_pPrevSenBuffer_04_irv
    (localInM_pPrevSenBuffer_04_ir_d);
}

/* Output and update for exported function: RE_InMdlT_043_MSE */
void RE_InMdlT_043_MSE(void)
{
  UInt8 localSwitch_e2;
  UInt16 localTmpSignalConversionAtExt_c;
  SInt16 localSwitch_ny;
  UInt16 localSwitch_g1;
  UInt16 localTmpSignalConversionAtUsT_d;
  UInt16 localSwitch_k[6];
  SInt32 locali;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S31>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F06_1_Init'
   *
   * Block requirements for '<S1>/INM3_F06_1_Init':
   *  1. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_091.01 ;
   *  2. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_090.01 ;
   *  3. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_089.01 ;
   *  4. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_363.02 ;
   *  5. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_255.01 ;
   *  6. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_251.01 ;
   *  7. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_247.01 ;
   *  8. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_256.01 ;
   *  9. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_248.01 ;
   *  10. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_249.01 ;
   *  11. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_250.01 ;
   *  12. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_254.01 ;
   *  13. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_382.01 ;
   *  14. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_246.01 ;
   *  15. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_240.02 ;
   *  16. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_241.01 ;
   *  17. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_242.01 ;
   *  18. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_243.01 ;
   *  19. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_244.01 ;
   *  20. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_245.01 ;
   *  21. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_253.01 ;
   *  22. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  23. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  24. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  25. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  26. SubSystem "INM3_F06_1_Init" !Trace_To : VEMS_R_11_01067_252.02 ;
   */

  /* Switch: '<S672>/Switch' incorporates:
   *  Constant: '<S672>/Byp_Fonction_SC'
   *  Constant: '<S672>/Int_BypC'
   *  Constant: '<S74>/Constant1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ny = InM_pDynCorPres_B;
  } else {
    localSwitch_ny = 0;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDynCorPresInport2' */
  Rte_Write_P_InM_pDynCorPres_InM_pDynCorPres(localSwitch_ny);

  /* Switch: '<S668>/Switch' incorporates:
   *  Constant: '<S668>/Byp_Fonction_SC'
   *  Constant: '<S668>/Int_BypC'
   *  Constant: '<S74>/Constant2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ny = InM_pDsThrEstimErr_B;
  } else {
    localSwitch_ny = 0;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDsThrEstimErrInport2' */
  Rte_Write_P_InM_pDsThrEstimErr_InM_pDsThrEstimErr(localSwitch_ny);

  /* SignalConversion: '<S74>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&localTmpSignalConversionAtUsT_d);

  /* Switch: '<S683>/Switch' incorporates:
   *  Constant: '<S683>/Byp_Fonction_SC'
   *  Constant: '<S683>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_pDsThrCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDsThrCorInport2' */
  Rte_Write_P_InM_pDsThrCor_InM_pDsThrCor(localSwitch_g1);

  /* Switch: '<S671>/Switch' incorporates:
   *  Constant: '<S671>/Byp_Fonction_SC'
   *  Constant: '<S671>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_pDsThrPredInCyl_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDsThrPredInCylInport2' */
  Rte_Write_P_InM_pDsThrPredInCyl_InM_pDsThrPredInCyl(localSwitch_g1);

  /* Switch: '<S669>/Switch' incorporates:
   *  Constant: '<S669>/Byp_Fonction_SC'
   *  Constant: '<S669>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_pDsThrPred_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDsThrPredInport2' */
  Rte_Write_P_InM_pDsThrPred_InM_pDsThrPred(localSwitch_g1);

  /* Switch: '<S670>/Switch' incorporates:
   *  Constant: '<S670>/Byp_Fonction_SC'
   *  Constant: '<S670>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_pDsThrPred_facVlvOvlp_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_pDsThrPred_facVlvOvlpInport2' */
  Rte_Write_P_InM_pDsThrPred_facVlvOvlp_InM_pDsThrPred_facVlvOvlp(localSwitch_g1);

  /* Switch: '<S675>/Switch' incorporates:
   *  Constant: '<S675>/Byp_Fonction_SC'
   *  Constant: '<S675>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localSwitch_k[locali] = InM_prm_pDsThrPredCyl_B[(locali)];
    }
  } else {
    localSwitch_k[0] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[1] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[2] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[3] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[4] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[5] = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_prm_pDsThrPredCylInport2' */
  Rte_Write_P_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl(&localSwitch_k);

  /* Switch: '<S684>/Switch' incorporates:
   *  Constant: '<S684>/Byp_Fonction_SC'
   *  Constant: '<S684>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localSwitch_k[locali] = InM_prm_pDsThrPredOvlpCyl_B[(locali)];
    }
  } else {
    localSwitch_k[0] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[1] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[2] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[3] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[4] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[5] = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCylInport2' */
  Rte_Write_P_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl(&localSwitch_k);

  /* SignalConversion: '<S74>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_c);

  /* Switch: '<S682>/Switch' incorporates:
   *  Constant: '<S682>/Byp_Fonction_SC'
   *  Constant: '<S682>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_c = InM_nEngCor_B;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_nEngCorInport2' */
  Rte_Write_P_InM_nEngCor_InM_nEngCor(localTmpSignalConversionAtExt_c);

  /* DataTypeConversion: '<S665>/OutDTConv' incorporates:
   *  Constant: '<S665>/offset'
   *  Constant: '<S665>/offset1'
   *  Constant: '<S665>/one_on_slope'
   *  Product: '<S665>/Product4'
   *  SignalConversion: '<S74>/TmpSignal ConversionAtInM_concAirRawOutport2'
   *  Sum: '<S665>/Add1'
   *  Sum: '<S665>/Add2'
   */
  localtmp = ((Rte_IrvRead_RE_InMdlT_043_MSE_InM_concAirRaw_irv() -
               1.525878906E-005F) * 65536.0F) + 0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtUsT_d = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtUsT_d = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_d = MAX_uint16_T;
  }

  /* Switch: '<S667>/Switch' incorporates:
   *  Constant: '<S667>/Byp_Fonction_SC'
   *  Constant: '<S667>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concAirCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concAirCorInport2' */
  Rte_Write_P_InM_concAirCor_InM_concAirCor(localSwitch_g1);

  /* Switch: '<S677>/Switch' incorporates:
   *  Constant: '<S677>/Byp_Fonction_SC'
   *  Constant: '<S677>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concAirPredCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concAirPredCorInport2' */
  Rte_Write_P_InM_concAirPredCor_InM_concAirPredCor(localSwitch_g1);

  /* Switch: '<S678>/Switch' incorporates:
   *  Constant: '<S678>/Byp_Fonction_SC'
   *  Constant: '<S678>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concAirPredInCylCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concAirPredInCylCorInport2' */
  Rte_Write_P_InM_concAirPredInCylCor_InM_concAirPredInCylCor(localSwitch_g1);

  /* Switch: '<S673>/Switch' incorporates:
   *  Constant: '<S673>/Byp_Fonction_SC'
   *  Constant: '<S673>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localSwitch_k[locali] = InM_prm_concAirPredCyl_B[(locali)];
    }
  } else {
    localSwitch_k[0] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[1] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[2] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[3] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[4] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[5] = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_prm_concAirPredCylInport2' */
  Rte_Write_P_InM_prm_concAirPredCyl_InM_prm_concAirPredCyl(&localSwitch_k);

  /* DataTypeConversion: '<S666>/OutDTConv' incorporates:
   *  Constant: '<S666>/offset'
   *  Constant: '<S666>/offset1'
   *  Constant: '<S666>/one_on_slope'
   *  Product: '<S666>/Product4'
   *  SignalConversion: '<S74>/TmpSignal ConversionAtInM_concFuStmRawOutport2'
   *  Sum: '<S666>/Add1'
   *  Sum: '<S666>/Add2'
   */
  localtmp = (65536.0F * Rte_IrvRead_RE_InMdlT_043_MSE_InM_concFuStmRaw_irv()) +
    0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtUsT_d = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtUsT_d = 0U;
    }
  } else {
    localTmpSignalConversionAtUsT_d = MAX_uint16_T;
  }

  /* Switch: '<S679>/Switch' incorporates:
   *  Constant: '<S679>/Byp_Fonction_SC'
   *  Constant: '<S679>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concFuCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concFuCorInport2' */
  Rte_Write_P_InM_concFuCor_InM_concFuCor(localSwitch_g1);

  /* Switch: '<S680>/Switch' incorporates:
   *  Constant: '<S680>/Byp_Fonction_SC'
   *  Constant: '<S680>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concFuPredCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concFuPredCorInport2' */
  Rte_Write_P_InM_concFuPredCor_InM_concFuPredCor(localSwitch_g1);

  /* Switch: '<S681>/Switch' incorporates:
   *  Constant: '<S681>/Byp_Fonction_SC'
   *  Constant: '<S681>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_g1 = InM_concFuPredInCylCor_B;
  } else {
    localSwitch_g1 = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_concFuPredInCylCorInport2' */
  Rte_Write_P_InM_concFuPredInCylCor_InM_concFuPredInCylCor(localSwitch_g1);

  /* Switch: '<S674>/Switch' incorporates:
   *  Constant: '<S674>/Byp_Fonction_SC'
   *  Constant: '<S674>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localSwitch_k[locali] = InM_prm_concFuPredCyl_B[(locali)];
    }
  } else {
    localSwitch_k[0] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[1] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[2] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[3] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[4] = localTmpSignalConversionAtUsT_d;
    localSwitch_k[5] = localTmpSignalConversionAtUsT_d;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_prm_concFuPredCylInport2' */
  Rte_Write_P_InM_prm_concFuPredCyl_InM_prm_concFuPredCyl(&localSwitch_k);

  /* Switch: '<S676>/Switch' incorporates:
   *  Constant: '<S676>/Byp_Fonction_SC'
   *  Constant: '<S676>/Int_BypC'
   *  Constant: '<S74>/InM_stPPurMode_SC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_e2 = InM_stModeMng_B;
  } else {
    localSwitch_e2 = InM_stPPurMode_SC;
  }

  /* SignalConversion: '<S74>/TmpSignal ConversionAtInM_stModeMngInport2' */
  Rte_Write_P_InM_stModeMng_InM_stModeMng(localSwitch_e2);
}

/* Start for exported function: RE_InMdlT_020_TEV */
void RE_InMdlT_020_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S32>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM3_F06_2_Correction_dynamic_load'
   *
   * Block requirements for '<S1>/INM3_F06_2_Correction_dynamic_load':
   *  1. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_089.01 ;
   *  2. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_090.01 ;
   *  3. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_092.01 ;
   *  4. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_341.03 ;
   *  5. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_255.01 ;
   *  6. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_251.01 ;
   *  7. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_247.01 ;
   *  8. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_256.01 ;
   *  9. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_248.01 ;
   *  10. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_249.01 ;
   *  11. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_250.01 ;
   *  12. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_254.01 ;
   *  13. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_382.01 ;
   *  14. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_246.01 ;
   *  15. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_240.02 ;
   *  16. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_241.01 ;
   *  17. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_242.01 ;
   *  18. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_243.01 ;
   *  19. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_244.01 ;
   *  20. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_245.01 ;
   *  21. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_253.01 ;
   *  22. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  23. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  24. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  25. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_379.01 ;
   *  26. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  27. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  28. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  29. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  30. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  31. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  32. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  33. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  34. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  35. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  36. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  37. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  38. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_257.01 ;
   *  39. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  40. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_379.01 ;
   *  41. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_376.01 ;
   *  42. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_377.02 ;
   *  43. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_378.01 ;
   *  44. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_385.01 ;
   *  45. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  46. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  47. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  48. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_252.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_020_TEV */
void RE_InMdlT_020_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer_i;
  Boolean localNot_k;
  Float32 localTmpSignalConversionAtIn_b1;
  UInt16 localTmpSignalConversionAtIn_hr;
  Float32 localTmpSignalConversionAtIn_ka;
  Float32 localTmpSignalConversionAtIn_mz;
  UInt8 localSwitch1_ov;
  SInt32 localrtmin;
  Float32 localSwitch1_b;
  UInt8 localTmpSignalConversionAtEn_g4;
  UInt8 localTmpSignalConversionAtEn_er;
  UInt8 localTmpSignalConversionAtEn_eq;
  UInt16 localAssignment2[6];
  SInt16 localTmpSignalConversionAtIn_j3;
  UInt16 localTmpSignalConversionAtI_flx[6];
  UInt16 localTmpSignalConversionAtIn_o3[6];
  UInt16 localTmpSignalConversionAtI_ft2[6];
  UInt16 localTmpSignalConversionAtIn_dd[6];
  Float32d localtmp;
  UInt16 locallocalDataTypeConversion1_b;
  UInt16 locallocalDataTypeConversion2_h;
  UInt16 locallocalDataTypeConversion3_c;
  UInt16 locallocalDataTypeConversion4_p;
  UInt16 locallocalDataTypeConversion5_a;
  UInt16 locallocalDataTypeConversion6_b;
  UInt16 locallocalOutDTConv_dp;
  SInt32 localrtmin_0;
  SInt32 localq;
  UInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S32>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM3_F06_2_Correction_dynamic_load'
   *
   * Block requirements for '<S1>/INM3_F06_2_Correction_dynamic_load':
   *  1. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_089.01 ;
   *  2. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_090.01 ;
   *  3. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_092.01 ;
   *  4. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_341.03 ;
   *  5. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_255.01 ;
   *  6. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_251.01 ;
   *  7. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_247.01 ;
   *  8. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_256.01 ;
   *  9. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_248.01 ;
   *  10. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_249.01 ;
   *  11. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_250.01 ;
   *  12. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_254.01 ;
   *  13. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_382.01 ;
   *  14. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_246.01 ;
   *  15. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_240.02 ;
   *  16. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_241.01 ;
   *  17. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_242.01 ;
   *  18. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_243.01 ;
   *  19. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_244.01 ;
   *  20. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_245.01 ;
   *  21. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_253.01 ;
   *  22. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  23. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_208.01 ;
   *  24. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_189.01 ;
   *  25. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_379.01 ;
   *  26. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_282.02 ;
   *  27. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  28. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  29. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  30. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  31. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  32. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  33. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_299.02 ;
   *  34. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_300.02 ;
   *  35. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  36. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  37. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  38. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_257.01 ;
   *  39. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_173.01 ;
   *  40. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_379.01 ;
   *  41. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_376.01 ;
   *  42. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_377.02 ;
   *  43. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_378.01 ;
   *  44. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_385.01 ;
   *  45. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_233.01 ;
   *  46. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_209.01 ;
   *  47. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_322.02 ;
   *  48. SubSystem "INM3_F06_2_Correction_dynamic_load" !Trace_To : VEMS_R_11_01067_252.02 ;
   */

  /* SignalConversion: '<S75>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&InMdlT_B.TmpSignalConversionAtEng_stEruO);

  /* S-Function (sfun_autosar_clientop): '<S688>/AutosarServer' */
  Rte_Call_R_FRM_bInhInMDynCor_GetFunctionPermission(&localAutosarServer_i);

  /* Logic: '<S688>/Not' */
  localNot_k = !localAutosarServer_i;

  /* S-Function (sfun_autosar_clientop): '<S689>/AutosarServer' */
  Rte_Call_R_FRM_bInhInMNomMod_GetFunctionPermission(&localAutosarServer_i);

  /* Outputs for atomic SubSystem: '<S75>/F01_Dynamic_Correction_Supervision' *
   * Block requirements for '<S75>/F01_Dynamic_Correction_Supervision':
   *  1. SubSystem "F01_Dynamic_Correction_Supervision" !Trace_To : VEMS_R_11_01067_093.01 ;
   */

  /* Switch: '<S685>/Switch' incorporates:
   *  Constant: '<S685>/Constant4'
   *  Constant: '<S685>/InM_bInhInMDynCor_C'
   *  Constant: '<S685>/InM_stDynCorMode_SC'
   *  Logic: '<S685>/Logical Operator'
   */
  if (InM_bInhInMDynCor_C || (localNot_k)) {
    localSwitch1_ov = InM_stPPurMode_SC;
  } else {
    localSwitch1_ov = InM_stDynCorMode_SC;
  }

  /* Switch: '<S685>/Switch1' incorporates:
   *  Constant: '<S685>/InM_bInhInMNomMod_C'
   *  Constant: '<S685>/InM_stPresSenDftMod_SC'
   *  Logic: '<S685>/Logical Operator1'
   *  Logic: '<S689>/Not'
   */
  if (InM_bInhInMNomMod_C || (!localAutosarServer_i)) {
    localSwitch1_ov = InM_stPresSenDftMod_SC;
  }

  /* Switch: '<S685>/Switch2' incorporates:
   *  Constant: '<S685>/Ext_stRun_SC'
   *  Constant: '<S685>/InM_stPPurMode_SC'
   *  RelationalOperator: '<S685>/Relational Operator1'
   */
  if (InMdlT_B.TmpSignalConversionAtEng_stEruO != Ext_stRun_SC) {
    localSwitch1_ov = InM_stPPurMode_SC;
  }

  /* end of Outputs for SubSystem: '<S75>/F01_Dynamic_Correction_Supervision' */

  /* SignalConversion: '<S75>/TmpSignal ConversionAtUsThrM_pDsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pDsThrMesCor'
   */
  Rte_Read_R_UsThrM_pDsThrMesCor_UsThrM_pDsThrMesCor
    (&InMdlT_B.TmpSignalConversionAtUsThrM_pDs);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrSenEstim_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_pDsThr =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_pDsThrSenEstim_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&InMdlT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirRaw_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_concAi =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_concAirRaw_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuStmRaw_irvOutport2' */
  InMdlT_B.TmpSignalConversionAtInM_concFu =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_concFuStmRaw_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrPredRaw_irvOutport2' */
  localTmpSignalConversionAtIn_b1 =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_pDsThrPredRaw_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor
    (&InMdlT_B.TmpSignalConversionAtUsThrM_pUs);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim
    (&InMdlT_B.TmpSignalConversionAtInM_pDsT_d);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_nEngPred_irvOutport2' */
  localTmpSignalConversionAtIn_hr =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_nEngPred_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThr_facVlvOvlp_irvOutport2' */
  localTmpSignalConversionAtIn_ka =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_pDsThr_facVlvOvlp_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrPredInCylRaw_irvOutport2' */
  localTmpSignalConversionAtIn_mz =
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_pDsThrPredInCylRaw_irv();

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrEstimErrPrevOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstimErr_INPUT'
   */
  Rte_Read_R_InM_pDsThrEstimErr_InM_pDsThrEstimErr
    (&localTmpSignalConversionAtIn_j3);

  /* Outputs for atomic SubSystem: '<S75>/F02_Calc_Dynamic_Correction' *
   * Block requirements for '<S75>/F02_Calc_Dynamic_Correction':
   *  1. SubSystem "F02_Calc_Dynamic_Correction" !Trace_To : VEMS_R_11_01067_094.01 ;
   */

  /* DataTypeConversion: '<S686>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirPred_irvOutport2'
   */
  localtmp = ACTEMS_LdexpF(((Float32d)
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_concAirPred_irv()) -
    1.5258789062500000E-005F, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion1_b = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion1_b = 0U;
    }
  } else {
    locallocalDataTypeConversion1_b = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S686>/Data Type Conversion2' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirPredInCyl_irvOutport2'
   */
  localtmp = ACTEMS_LdexpF(((Float32d)
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_concAirPredInCyl_irv()) -
    1.5258789062500000E-005F, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion2_h = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion2_h = 0U;
    }
  } else {
    locallocalDataTypeConversion2_h = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S686>/Data Type Conversion3' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirEstim_irvOutport2'
   */
  localtmp = ACTEMS_LdexpF(((Float32d)
    Rte_IrvRead_RE_InMdlT_020_TEV_InM_concAirEstim_irv()) -
    1.5258789062500000E-005F, 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion3_c = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion3_c = 0U;
    }
  } else {
    locallocalDataTypeConversion3_c = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S686>/Data Type Conversion4' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuStmEstim_irvOutport2'
   */
  localtmp = Rte_IrvRead_RE_InMdlT_020_TEV_InM_concFuStmEstim_irv();
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion4_p = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion4_p = 0U;
    }
  } else {
    locallocalDataTypeConversion4_p = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S686>/Data Type Conversion5' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuPred_irvOutport2'
   */
  localtmp = Rte_IrvRead_RE_InMdlT_020_TEV_InM_concFuPred_irv();
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion5_a = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion5_a = 0U;
    }
  } else {
    locallocalDataTypeConversion5_a = MAX_uint16_T;
  }

  /* DataTypeConversion: '<S686>/Data Type Conversion6' incorporates:
   *  SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuPredInCyl_irvOutport2'
   */
  localtmp = Rte_IrvRead_RE_InMdlT_020_TEV_InM_concFuPredInCyl_irv();
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 16);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalDataTypeConversion6_b = (UInt16)localtmp;
    } else {
      locallocalDataTypeConversion6_b = 0U;
    }
  } else {
    locallocalDataTypeConversion6_b = MAX_uint16_T;
  }

  /* Outputs for enable SubSystem: '<S686>/F01_P_N_pur_mode' incorporates:
   *  Constant: '<S686>/InM_stPPurMode_SC'
   *  EnablePort: '<S708>/Enable'
   *  RelationalOperator: '<S686>/Relational Operator'
   *
   * Block requirements for '<S686>/F01_P_N_pur_mode':
   *  1. SubSystem "F01_P_N_pur_mode" !Trace_To : VEMS_R_11_01067_095.01 ;
   */
  if (localSwitch1_ov == InM_stPPurMode_SC) {
    /* Constant: '<S708>/Constant1' */
    InMdlT_B.Merge = 0;

    /* Constant: '<S708>/Constant2' */
    InMdlT_B.Merge1_n = 0;

    /* SignalConversion: '<S708>/Signal Conversion1' */
    InMdlT_B.Merge3 = InMdlT_B.TmpSignalConversionAtUsThrM_pDs;

    /* SignalConversion: '<S708>/Signal Conversion10' */
    InMdlT_B.Merge5_a = InMdlT_B.TmpSignalConversionAtUsThrM_pDs;

    /* SignalConversion: '<S708>/Signal Conversion3' */
    InMdlT_B.Merge2 = InMdlT_B.TmpSignalConversionAtUsThrM_pDs;

    /* SignalConversion: '<S708>/Signal Conversion4' */
    InMdlT_B.Merge4_n = InMdlT_B.TmpSignalConversionAtUsThrM_pDs;

    /* SignalConversion: '<S708>/Signal Conversion8' */
    InMdlT_B.Merge6_o = InMdlT_B.TmpSignalConversionAtExt_nEngOu;

    /* DataTypeConversion: '<S711>/OutDTConv' incorporates:
     *  Constant: '<S711>/offset'
     *  Constant: '<S711>/offset1'
     *  Constant: '<S711>/one_on_slope'
     *  Product: '<S711>/Product4'
     *  Sum: '<S711>/Add1'
     *  Sum: '<S711>/Add2'
     */
    localSwitch1_b = ((InMdlT_B.TmpSignalConversionAtInM_concAi -
                       1.525878906E-005F) * 65536.0F) + 0.5F;
    if (localSwitch1_b < 65536.0F) {
      if (localSwitch1_b >= 0.0F) {
        locallocalOutDTConv_dp = (UInt16)localSwitch1_b;
      } else {
        locallocalOutDTConv_dp = 0U;
      }
    } else {
      locallocalOutDTConv_dp = MAX_uint16_T;
    }

    /* SignalConversion: '<S708>/Signal Conversion11' */
    InMdlT_B.Merge8 = locallocalOutDTConv_dp;

    /* SignalConversion: '<S708>/Signal Conversion12' */
    InMdlT_B.Merge9 = locallocalOutDTConv_dp;

    /* SignalConversion: '<S708>/Signal Conversion6' */
    InMdlT_B.Merge7 = locallocalOutDTConv_dp;

    /* DataTypeConversion: '<S712>/OutDTConv' incorporates:
     *  Constant: '<S712>/offset'
     *  Constant: '<S712>/offset1'
     *  Constant: '<S712>/one_on_slope'
     *  Product: '<S712>/Product4'
     *  Sum: '<S712>/Add1'
     *  Sum: '<S712>/Add2'
     */
    localSwitch1_b = (65536.0F * InMdlT_B.TmpSignalConversionAtInM_concFu) +
      0.5F;
    if (localSwitch1_b < 65536.0F) {
      if (localSwitch1_b >= 0.0F) {
        locallocalOutDTConv_dp = (UInt16)localSwitch1_b;
      } else {
        locallocalOutDTConv_dp = 0U;
      }
    } else {
      locallocalOutDTConv_dp = MAX_uint16_T;
    }

    /* SignalConversion: '<S708>/Signal Conversion2' */
    InMdlT_B.Merge11 = locallocalOutDTConv_dp;

    /* SignalConversion: '<S708>/Signal Conversion5' */
    InMdlT_B.Merge10 = locallocalOutDTConv_dp;

    /* SignalConversion: '<S708>/Signal Conversion7' */
    InMdlT_B.Merge12 = locallocalOutDTConv_dp;
  }

  /* end of Outputs for SubSystem: '<S686>/F01_P_N_pur_mode' */

  /* Outputs for enable SubSystem: '<S686>/F02_P_N_hybride_mode' incorporates:
   *  Constant: '<S686>/InM_stDynCorMode_SC'
   *  EnablePort: '<S709>/Enable'
   *  RelationalOperator: '<S686>/Relational Operator1'
   *
   * Block requirements for '<S686>/F02_P_N_hybride_mode':
   *  1. SubSystem "F02_P_N_hybride_mode" !Trace_To : VEMS_R_11_01067_096.01 ;
   */
  if (localSwitch1_ov == InM_stDynCorMode_SC) {
    /* MinMax: '<S709>/MinMax' incorporates:
     *  Sum: '<S709>/Sum1'
     */
    localtmp = (((Float32)localTmpSignalConversionAtIn_j3) * 8.0F) +
      localTmpSignalConversionAtIn_b1;
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3));
    if (localtmp < 2.147483648E+009F) {
      if (localtmp >= -2.147483648E+009F) {
        localrtmin_0 = (SInt32)localtmp;
      } else {
        localrtmin_0 = MIN_int32_T;
      }
    } else {
      localrtmin_0 = MAX_int32_T;
    }

    localrtmin = InMdlT_B.TmpSignalConversionAtUsThrM_pUs;
    if (localrtmin < localrtmin_0) {
      localrtmin_0 = localrtmin;
    }

    if (localrtmin_0 <= 0) {
      InMdlT_B.Merge3 = 0U;
    } else {
      InMdlT_B.Merge3 = (UInt16)localrtmin_0;
    }

    /* MinMax: '<S709>/MinMax1' incorporates:
     *  Sum: '<S709>/Sum2'
     */
    localrtmin = localTmpSignalConversionAtIn_j3;
    localq = (SInt32)(InMdlT_B.TmpSignalConversionAtInM_pDsT_d >> 10U);
    localrtmin_0 = localrtmin + localq;
    if ((localrtmin > 0) && ((localq > 0) && (localrtmin_0 <= 0))) {
      localrtmin_0 = MAX_int32_T;
    }

    localrtmin = InMdlT_B.TmpSignalConversionAtUsThrM_pUs;
    if (localrtmin < localrtmin_0) {
      localrtmin_0 = localrtmin;
    }

    if (localrtmin_0 <= 0) {
      InMdlT_B.Merge2 = 0U;
    } else {
      InMdlT_B.Merge2 = (UInt16)localrtmin_0;
    }

    /* MinMax: '<S709>/MinMax2' incorporates:
     *  Sum: '<S709>/Sum3'
     */
    localtmp = (((Float32)localTmpSignalConversionAtIn_j3) * 8.0F) +
      localTmpSignalConversionAtIn_ka;
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3));
    if (localtmp < 2.147483648E+009F) {
      if (localtmp >= -2.147483648E+009F) {
        localrtmin_0 = (SInt32)localtmp;
      } else {
        localrtmin_0 = MIN_int32_T;
      }
    } else {
      localrtmin_0 = MAX_int32_T;
    }

    localrtmin = InMdlT_B.TmpSignalConversionAtUsThrM_pUs;
    if (localrtmin < localrtmin_0) {
      localrtmin_0 = localrtmin;
    }

    if (localrtmin_0 <= 0) {
      InMdlT_B.Merge4_n = 0U;
    } else {
      InMdlT_B.Merge4_n = (UInt16)localrtmin_0;
    }

    /* MinMax: '<S709>/MinMax3' incorporates:
     *  Sum: '<S709>/Sum4'
     */
    localtmp = (((Float32)localTmpSignalConversionAtIn_j3) * 8.0F) +
      localTmpSignalConversionAtIn_mz;
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3));
    if (localtmp < 2.147483648E+009F) {
      if (localtmp >= -2.147483648E+009F) {
        localrtmin_0 = (SInt32)localtmp;
      } else {
        localrtmin_0 = MIN_int32_T;
      }
    } else {
      localrtmin_0 = MAX_int32_T;
    }

    localrtmin = InMdlT_B.TmpSignalConversionAtUsThrM_pUs;
    if (localrtmin < localrtmin_0) {
      localrtmin_0 = localrtmin;
    }

    if (localrtmin_0 <= 0) {
      InMdlT_B.Merge5_a = 0U;
    } else {
      InMdlT_B.Merge5_a = (UInt16)localrtmin_0;
    }

    /* Product: '<S713>/Product4' incorporates:
     *  Constant: '<S713>/offset'
     *  Constant: '<S713>/one_on_slope'
     *  Sum: '<S709>/Sum'
     *  Sum: '<S713>/Add1'
     */
    localSwitch1_b = (localTmpSignalConversionAtIn_b1 -
                      InMdlT_B.TmpSignalConversionAtInM_pDsThr) * 0.125F;

    /* Switch: '<S713>/Switch1' incorporates:
     *  Constant: '<S713>/offset2'
     *  Constant: '<S713>/offset3'
     *  Constant: '<S713>/offset4'
     *  RelationalOperator: '<S713>/Relational Operator'
     *  Sum: '<S713>/Add3'
     *  Sum: '<S713>/Add4'
     */
    if (localSwitch1_b >= 0.0F) {
      localSwitch1_b += 0.5F;
    } else {
      localSwitch1_b -= 0.5F;
    }

    /* DataTypeConversion: '<S713>/OutDTConv' */
    if (localSwitch1_b < 32768.0F) {
      if (localSwitch1_b >= -32768.0F) {
        InMdlT_B.Merge = (SInt16)localSwitch1_b;
      } else {
        InMdlT_B.Merge = MIN_int16_T;
      }
    } else {
      InMdlT_B.Merge = MAX_int16_T;
    }

    /* Sum: '<S709>/Sum6' */
    localtmp = (((Float32)InMdlT_B.TmpSignalConversionAtUsThrM_pDs) * 8.0F) -
      InMdlT_B.TmpSignalConversionAtInM_pDsThr;
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3));
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        InMdlT_B.Merge1_n = (SInt16)localtmp;
      } else {
        InMdlT_B.Merge1_n = MIN_int16_T;
      }
    } else {
      InMdlT_B.Merge1_n = MAX_int16_T;
    }

    /* SignalConversion: '<S709>/Signal Conversion1' */
    InMdlT_B.Merge6_o = localTmpSignalConversionAtIn_hr;

    /* SignalConversion: '<S709>/Signal Conversion2' */
    InMdlT_B.Merge7 = locallocalDataTypeConversion3_c;

    /* SignalConversion: '<S709>/Signal Conversion3' */
    InMdlT_B.Merge8 = locallocalDataTypeConversion1_b;

    /* SignalConversion: '<S709>/Signal Conversion4' */
    InMdlT_B.Merge9 = locallocalDataTypeConversion2_h;

    /* SignalConversion: '<S709>/Signal Conversion9' */
    InMdlT_B.Merge10 = locallocalDataTypeConversion4_p;

    /* SignalConversion: '<S709>/Signal Conversion10' */
    InMdlT_B.Merge11 = locallocalDataTypeConversion5_a;

    /* SignalConversion: '<S709>/Signal Conversion11' */
    InMdlT_B.Merge12 = locallocalDataTypeConversion6_b;
  }

  /* end of Outputs for SubSystem: '<S686>/F02_P_N_hybride_mode' */

  /* Outputs for enable SubSystem: '<S686>/F03_Alpha_N_pur_mode' incorporates:
   *  Constant: '<S686>/InM_stPresSenDftMod_SC'
   *  EnablePort: '<S710>/Enable'
   *  RelationalOperator: '<S686>/Relational Operator2'
   *
   * Block requirements for '<S686>/F03_Alpha_N_pur_mode':
   *  1. SubSystem "F03_Alpha_N_pur_mode" !Trace_To : VEMS_R_11_01067_097.01 ;
   */
  if (localSwitch1_ov == InM_stPresSenDftMod_SC) {
    /* Product: '<S714>/Product4' incorporates:
     *  Constant: '<S714>/offset'
     *  Constant: '<S714>/one_on_slope'
     *  Sum: '<S710>/Sum'
     *  Sum: '<S714>/Add1'
     */
    localSwitch1_b = (localTmpSignalConversionAtIn_b1 -
                      InMdlT_B.TmpSignalConversionAtInM_pDsThr) * 0.125F;

    /* Switch: '<S714>/Switch1' incorporates:
     *  Constant: '<S714>/offset2'
     *  Constant: '<S714>/offset3'
     *  Constant: '<S714>/offset4'
     *  RelationalOperator: '<S714>/Relational Operator'
     *  Sum: '<S714>/Add3'
     *  Sum: '<S714>/Add4'
     */
    if (localSwitch1_b >= 0.0F) {
      localSwitch1_b += 0.5F;
    } else {
      localSwitch1_b -= 0.5F;
    }

    /* DataTypeConversion: '<S714>/OutDTConv' */
    if (localSwitch1_b < 32768.0F) {
      if (localSwitch1_b >= -32768.0F) {
        InMdlT_B.Merge = (SInt16)localSwitch1_b;
      } else {
        InMdlT_B.Merge = MIN_int16_T;
      }
    } else {
      InMdlT_B.Merge = MAX_int16_T;
    }

    /* DataTypeConversion: '<S715>/OutDTConv' incorporates:
     *  Constant: '<S715>/offset'
     *  Constant: '<S715>/offset1'
     *  Constant: '<S715>/one_on_slope'
     *  Product: '<S715>/Product4'
     *  Sum: '<S715>/Add1'
     *  Sum: '<S715>/Add2'
     */
    localSwitch1_b = (0.125F * localTmpSignalConversionAtIn_b1) + 0.5F;
    if (localSwitch1_b < 65536.0F) {
      if (localSwitch1_b >= 0.0F) {
        InMdlT_B.Merge3 = (UInt16)localSwitch1_b;
      } else {
        InMdlT_B.Merge3 = 0U;
      }
    } else {
      InMdlT_B.Merge3 = MAX_uint16_T;
    }

    /* Constant: '<S710>/Constant2' */
    InMdlT_B.Merge1_n = 0;

    /* SignalConversion: '<S710>/Signal Conversion1' incorporates:
     *  DataTypeConversion: '<S710>/Data Type Conversion8'
     */
    localtmp_0 = (InMdlT_B.TmpSignalConversionAtInM_pDsT_d >> 10);
    if (localtmp_0 > 65535U) {
      InMdlT_B.Merge2 = MAX_uint16_T;
    } else {
      InMdlT_B.Merge2 = (UInt16)localtmp_0;
    }

    /* DataTypeConversion: '<S716>/OutDTConv' incorporates:
     *  Constant: '<S716>/offset'
     *  Constant: '<S716>/offset1'
     *  Constant: '<S716>/one_on_slope'
     *  Product: '<S716>/Product4'
     *  Sum: '<S716>/Add1'
     *  Sum: '<S716>/Add2'
     */
    localSwitch1_b = (0.125F * localTmpSignalConversionAtIn_ka) + 0.5F;
    if (localSwitch1_b < 65536.0F) {
      if (localSwitch1_b >= 0.0F) {
        InMdlT_B.Merge4_n = (UInt16)localSwitch1_b;
      } else {
        InMdlT_B.Merge4_n = 0U;
      }
    } else {
      InMdlT_B.Merge4_n = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S717>/OutDTConv' incorporates:
     *  Constant: '<S717>/offset'
     *  Constant: '<S717>/offset1'
     *  Constant: '<S717>/one_on_slope'
     *  Product: '<S717>/Product4'
     *  Sum: '<S717>/Add1'
     *  Sum: '<S717>/Add2'
     */
    localSwitch1_b = (0.125F * localTmpSignalConversionAtIn_mz) + 0.5F;
    if (localSwitch1_b < 65536.0F) {
      if (localSwitch1_b >= 0.0F) {
        InMdlT_B.Merge5_a = (UInt16)localSwitch1_b;
      } else {
        InMdlT_B.Merge5_a = 0U;
      }
    } else {
      InMdlT_B.Merge5_a = MAX_uint16_T;
    }

    /* SignalConversion: '<S710>/Signal Conversion2' */
    InMdlT_B.Merge6_o = localTmpSignalConversionAtIn_hr;

    /* SignalConversion: '<S710>/Signal Conversion3' */
    InMdlT_B.Merge7 = locallocalDataTypeConversion3_c;

    /* SignalConversion: '<S710>/Signal Conversion7' */
    InMdlT_B.Merge8 = locallocalDataTypeConversion1_b;

    /* SignalConversion: '<S710>/Signal Conversion8' */
    InMdlT_B.Merge9 = locallocalDataTypeConversion2_h;

    /* SignalConversion: '<S710>/Signal Conversion9' */
    InMdlT_B.Merge10 = locallocalDataTypeConversion4_p;

    /* SignalConversion: '<S710>/Signal Conversion10' */
    InMdlT_B.Merge11 = locallocalDataTypeConversion5_a;

    /* SignalConversion: '<S710>/Signal Conversion11' */
    InMdlT_B.Merge12 = locallocalDataTypeConversion6_b;
  }

  /* end of Outputs for SubSystem: '<S686>/F03_Alpha_N_pur_mode' */

  /* end of Outputs for SubSystem: '<S75>/F02_Calc_Dynamic_Correction' */

  /* SignalConversion: '<S75>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&localTmpSignalConversionAtEn_g4);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtEng_noExNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExNxtCyl'
   */
  Rte_Read_R_Eng_noExNxtCyl_Eng_noExNxtCyl(&localTmpSignalConversionAtEn_er);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&localTmpSignalConversionAtEn_eq);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_pDsThrPredCylPrevOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredCyl_INPUT'
   */
  Rte_Read_R_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl
    (&localTmpSignalConversionAtI_flx);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_concAirPredCylPrevOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_concAirPredCyl_INPUT'
   */
  Rte_Read_R_InM_prm_concAirPredCyl_InM_prm_concAirPredCyl
    (&localTmpSignalConversionAtI_ft2);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_concFuPredCylPrevOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_concFuPredCyl_INPUT'
   */
  Rte_Read_R_InM_prm_concFuPredCyl_InM_prm_concFuPredCyl
    (&localTmpSignalConversionAtIn_dd);

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCyl1Outport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredOvlpCyl_INPUT'
   */
  Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&localTmpSignalConversionAtIn_o3);

  /* Outputs for atomic SubSystem: '<S75>/F03_Vecteur_cylindre' *
   * Block requirements for '<S75>/F03_Vecteur_cylindre':
   *  1. SubSystem "F03_Vecteur_cylindre" !Trace_To : VEMS_R_11_01067_098.01 ;
   */

  /* Outputs for atomic SubSystem: '<S687>/F01_ecriture_vecteur_cylindre' *
   * Block requirements for '<S687>/F01_ecriture_vecteur_cylindre':
   *  1. SubSystem "F01_ecriture_vecteur_cylindre" !Trace_To : VEMS_R_11_01067_099.01 ;
   */

  /* Assignment: '<S718>/Assignment4' */
  localTmpSignalConversionAtI_flx[localTmpSignalConversionAtEn_g4 - 1] =
    InMdlT_B.Merge3;

  /* Assignment: '<S718>/Assignment3' */
  localTmpSignalConversionAtI_flx[localTmpSignalConversionAtEn_er - 1] =
    InMdlT_B.Merge3;

  /* Assignment: '<S718>/Assignment1' */
  localTmpSignalConversionAtI_flx[localTmpSignalConversionAtEn_eq - 1] =
    InMdlT_B.Merge5_a;

  /* end of Outputs for SubSystem: '<S687>/F01_ecriture_vecteur_cylindre' */

  /* Outputs for atomic SubSystem: '<S687>/F02_ecriture_vecteur_cylindre' *
   * Block requirements for '<S687>/F02_ecriture_vecteur_cylindre':
   *  1. SubSystem "F02_ecriture_vecteur_cylindre" !Trace_To : VEMS_R_11_01067_100.01 ;
   */

  /* Assignment: '<S719>/Assignment3' */
  localTmpSignalConversionAtIn_o3[localTmpSignalConversionAtEn_g4 - 1] =
    InMdlT_B.Merge4_n;

  /* Assignment: '<S719>/Assignment1' */
  localTmpSignalConversionAtIn_o3[localTmpSignalConversionAtEn_er - 1] =
    InMdlT_B.Merge4_n;

  /* end of Outputs for SubSystem: '<S687>/F02_ecriture_vecteur_cylindre' */

  /* Outputs for atomic SubSystem: '<S687>/F03_ecriture_vecteur_cylindre' *
   * Block requirements for '<S687>/F03_ecriture_vecteur_cylindre':
   *  1. SubSystem "F03_ecriture_vecteur_cylindre" !Trace_To : VEMS_R_11_01067_101.01 ;
   */

  /* Assignment: '<S720>/Assignment6' */
  localTmpSignalConversionAtI_ft2[localTmpSignalConversionAtEn_g4 - 1] =
    InMdlT_B.Merge8;

  /* Assignment: '<S720>/Assignment1' */
  localTmpSignalConversionAtI_ft2[localTmpSignalConversionAtEn_er - 1] =
    InMdlT_B.Merge8;

  /* Assignment: '<S720>/Assignment2' */
  for (localrtmin = 0; localrtmin < 6; localrtmin++) {
    localAssignment2[localrtmin] = localTmpSignalConversionAtI_ft2[localrtmin];
    localTmpSignalConversionAtI_ft2[localrtmin] =
      localTmpSignalConversionAtIn_dd[localrtmin];
  }

  localAssignment2[localTmpSignalConversionAtEn_eq - 1] = InMdlT_B.Merge9;

  /* Assignment: '<S720>/Assignment3' */
  localTmpSignalConversionAtI_ft2[localTmpSignalConversionAtEn_g4 - 1] =
    InMdlT_B.Merge11;

  /* Assignment: '<S720>/Assignment4' */
  localTmpSignalConversionAtI_ft2[localTmpSignalConversionAtEn_er - 1] =
    InMdlT_B.Merge11;

  /* Assignment: '<S720>/Assignment5' */
  localTmpSignalConversionAtI_ft2[localTmpSignalConversionAtEn_eq - 1] =
    InMdlT_B.Merge12;

  /* end of Outputs for SubSystem: '<S687>/F03_ecriture_vecteur_cylindre' */

  /* end of Outputs for SubSystem: '<S75>/F03_Vecteur_cylindre' */

  /* Switch: '<S690>/Switch' incorporates:
   *  Constant: '<S690>/Byp_Fonction_SC'
   *  Constant: '<S690>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concAirCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge7;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirCorInport2' */
  Rte_Write_P_InM_concAirCor_InM_concAirCor(localTmpSignalConversionAtIn_hr);

  /* Switch: '<S700>/Switch' incorporates:
   *  Constant: '<S700>/Byp_Fonction_SC'
   *  Constant: '<S700>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concAirPredCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge8;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirPredCorInport2' */
  Rte_Write_P_InM_concAirPredCor_InM_concAirPredCor
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S701>/Switch' incorporates:
   *  Constant: '<S701>/Byp_Fonction_SC'
   *  Constant: '<S701>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concAirPredInCylCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge9;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concAirPredInCylCorInport2' */
  Rte_Write_P_InM_concAirPredInCylCor_InM_concAirPredInCylCor
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S702>/Switch' incorporates:
   *  Constant: '<S702>/Byp_Fonction_SC'
   *  Constant: '<S702>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concFuCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge10;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuCorInport2' */
  Rte_Write_P_InM_concFuCor_InM_concFuCor(localTmpSignalConversionAtIn_hr);

  /* Switch: '<S703>/Switch' incorporates:
   *  Constant: '<S703>/Byp_Fonction_SC'
   *  Constant: '<S703>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concFuPredCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge11;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuPredCorInport2' */
  Rte_Write_P_InM_concFuPredCor_InM_concFuPredCor
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S704>/Switch' incorporates:
   *  Constant: '<S704>/Byp_Fonction_SC'
   *  Constant: '<S704>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_concFuPredInCylCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge12;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_concFuPredInCylCorInport2' */
  Rte_Write_P_InM_concFuPredInCylCor_InM_concFuPredInCylCor
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S705>/Switch' incorporates:
   *  Constant: '<S705>/Byp_Fonction_SC'
   *  Constant: '<S705>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_nEngCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge6_o;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_nEngCorInport2' */
  Rte_Write_P_InM_nEngCor_InM_nEngCor(localTmpSignalConversionAtIn_hr);

  /* Switch: '<S706>/Switch' incorporates:
   *  Constant: '<S706>/Byp_Fonction_SC'
   *  Constant: '<S706>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_pDsThrCor_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge2;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrCorInport2' */
  Rte_Write_P_InM_pDsThrCor_InM_pDsThrCor(localTmpSignalConversionAtIn_hr);

  /* Switch: '<S691>/Switch' incorporates:
   *  Constant: '<S691>/Byp_Fonction_SC'
   *  Constant: '<S691>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_j3 = InM_pDsThrEstimErr_B;
  } else {
    localTmpSignalConversionAtIn_j3 = InMdlT_B.Merge1_n;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrEstimErrInport2' */
  Rte_Write_P_InM_pDsThrEstimErr_InM_pDsThrEstimErr
    (localTmpSignalConversionAtIn_j3);

  /* Switch: '<S694>/Switch' incorporates:
   *  Constant: '<S694>/Byp_Fonction_SC'
   *  Constant: '<S694>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_pDsThrPredInCyl_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge5_a;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrPredInCylInport2' */
  Rte_Write_P_InM_pDsThrPredInCyl_InM_pDsThrPredInCyl
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S692>/Switch' incorporates:
   *  Constant: '<S692>/Byp_Fonction_SC'
   *  Constant: '<S692>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_pDsThrPred_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge3;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrPredInport2' */
  Rte_Write_P_InM_pDsThrPred_InM_pDsThrPred(localTmpSignalConversionAtIn_hr);

  /* Switch: '<S693>/Switch' incorporates:
   *  Constant: '<S693>/Byp_Fonction_SC'
   *  Constant: '<S693>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hr = InM_pDsThrPred_facVlvOvlp_B;
  } else {
    localTmpSignalConversionAtIn_hr = InMdlT_B.Merge4_n;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDsThrPred_facVlvOvlpInport2' */
  Rte_Write_P_InM_pDsThrPred_facVlvOvlp_InM_pDsThrPred_facVlvOvlp
    (localTmpSignalConversionAtIn_hr);

  /* Switch: '<S695>/Switch' incorporates:
   *  Constant: '<S695>/Byp_Fonction_SC'
   *  Constant: '<S695>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_j3 = InM_pDynCorPres_B;
  } else {
    localTmpSignalConversionAtIn_j3 = InMdlT_B.Merge;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_pDynCorPresInport2' */
  Rte_Write_P_InM_pDynCorPres_InM_pDynCorPres(localTmpSignalConversionAtIn_j3);

  /* Switch: '<S696>/Switch' incorporates:
   *  Constant: '<S696>/Byp_Fonction_SC'
   *  Constant: '<S696>/Int_BypC'
   */
  for (localrtmin = 0; localrtmin < 6; localrtmin++) {
    if (INMDLT_ACTIVE_BYP_C) {
      localAssignment2[localrtmin] = InM_prm_concAirPredCyl_B[(localrtmin)];
    }
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_concAirPredCylInport2' */
  Rte_Write_P_InM_prm_concAirPredCyl_InM_prm_concAirPredCyl(&localAssignment2);

  /* Switch: '<S697>/Switch' incorporates:
   *  Constant: '<S697>/Byp_Fonction_SC'
   *  Constant: '<S697>/Int_BypC'
   */
  for (localrtmin = 0; localrtmin < 6; localrtmin++) {
    if (INMDLT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtI_ft2[localrtmin] = InM_prm_concFuPredCyl_B
        [(localrtmin)];
    }
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_concFuPredCylInport2' */
  Rte_Write_P_InM_prm_concFuPredCyl_InM_prm_concFuPredCyl
    (&localTmpSignalConversionAtI_ft2);

  /* Switch: '<S698>/Switch' incorporates:
   *  Constant: '<S698>/Byp_Fonction_SC'
   *  Constant: '<S698>/Int_BypC'
   */
  for (localrtmin = 0; localrtmin < 6; localrtmin++) {
    if (INMDLT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtI_flx[localrtmin] = InM_prm_pDsThrPredCyl_B
        [(localrtmin)];
    }
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_pDsThrPredCylInport2' */
  Rte_Write_P_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl
    (&localTmpSignalConversionAtI_flx);

  /* Switch: '<S707>/Switch' incorporates:
   *  Constant: '<S707>/Byp_Fonction_SC'
   *  Constant: '<S707>/Int_BypC'
   */
  for (localrtmin = 0; localrtmin < 6; localrtmin++) {
    if (INMDLT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtIn_o3[localrtmin] = InM_prm_pDsThrPredOvlpCyl_B
        [(localrtmin)];
    }
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCylInport2' */
  Rte_Write_P_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&localTmpSignalConversionAtIn_o3);

  /* Switch: '<S699>/Switch' incorporates:
   *  Constant: '<S699>/Byp_Fonction_SC'
   *  Constant: '<S699>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch1_ov = InM_stModeMng_B;
  }

  /* SignalConversion: '<S75>/TmpSignal ConversionAtInM_stModeMngInport2' */
  Rte_Write_P_InM_stModeMng_InM_stModeMng(localSwitch1_ov);
}

/* Start for exported function: RE_InMdlT_001_MSE */
void RE_InMdlT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM00_init'
   *
   * Block requirements for '<S1>/INM00_init':
   *  1. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_329.02 ;
   *  2. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_383.01 ;
   *  3. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  4. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  5. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  6. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  7. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_304.02 ;
   *  8. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  9. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  10. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  11. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  12. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  13. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  14. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  15. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  16. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  17. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  18. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_274.02 ;
   */
}

/* Output and update for exported function: RE_InMdlT_001_MSE */
void RE_InMdlT_001_MSE(void)
{
  UInt16 localSwitch_ab;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM00_init'
   *
   * Block requirements for '<S1>/INM00_init':
   *  1. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_329.02 ;
   *  2. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_383.01 ;
   *  3. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_298.02 ;
   *  4. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_301.02 ;
   *  5. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_302.02 ;
   *  6. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_303.03 ;
   *  7. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_304.02 ;
   *  8. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_305.02 ;
   *  9. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_306.02 ;
   *  10. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_307.02 ;
   *  11. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_308.02 ;
   *  12. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_309.02 ;
   *  13. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_310.02 ;
   *  14. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_311.02 ;
   *  15. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_312.03 ;
   *  16. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_313.02 ;
   *  17. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_326.03 ;
   *  18. SubSystem "INM00_init" !Trace_To : VEMS_R_11_01067_274.02 ;
   */

  /* SignalConversion: '<S76>/copy' incorporates:
   *  Constant: '<S40>/Constant9'
   */
  InM_mGradEGREstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S76>/autosar_testpoint1' */

  /* S-Function Block: <S76>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_mGradEGREstim_irvInport2' incorporates:
   *  Constant: '<S40>/Constant9'
   *  SignalConversion: '<S40>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_mGradEGREstim_irv(0.0F);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S92>/Byp_Fonction_SC'
   *  Constant: '<S92>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ab = InM_rAirPres_B;
  } else {
    localSwitch_ab = 0U;
  }

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_rAirPresInport2' */
  Rte_Write_P_InM_rAirPres_InM_rAirPres(localSwitch_ab);

  /* SignalConversion: '<S84>/copy' incorporates:
   *  Constant: '<S40>/Constant2'
   */
  InM_mTotEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S84>/autosar_testpoint1' */

  /* S-Function Block: <S84>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_mTotEstim_irvInport2' incorporates:
   *  Constant: '<S40>/Constant2'
   *  SignalConversion: '<S40>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_mTotEstim_irv(0.0F);

  /* SignalConversion: '<S85>/copy' incorporates:
   *  Constant: '<S40>/Constant3'
   */
  InM_agCkClsInVlvEstimRef2_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S85>/autosar_testpoint1' */

  /* S-Function Block: <S85>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_agCkClsInVlvEstimRef2_irvInport2' incorporates:
   *  Constant: '<S40>/Constant3'
   *  SignalConversion: '<S40>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_agCkClsInVlvEstimRef2_irv(0.0F);

  /* SignalConversion: '<S86>/copy' incorporates:
   *  Constant: '<S40>/Constant4'
   */
  InM_tiHrznPred_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S86>/autosar_testpoint1' */

  /* S-Function Block: <S86>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_tiHrznPred_irvInport2' incorporates:
   *  Constant: '<S40>/Constant4'
   *  SignalConversion: '<S40>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_tiHrznPred_irv(0.0F);

  /* SignalConversion: '<S87>/copy' incorporates:
   *  Constant: '<S40>/Constant5'
   */
  InM_concAirPred_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S87>/autosar_testpoint1' */

  /* S-Function Block: <S87>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_concAirPred_irvInport2' incorporates:
   *  Constant: '<S40>/Constant5'
   *  SignalConversion: '<S40>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_concAirPred_irv(0.0F);

  /* SignalConversion: '<S88>/copy' incorporates:
   *  Constant: '<S40>/Constant6'
   */
  InM_concAirPredInCyl_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' */

  /* S-Function Block: <S88>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_concAirPredInCyl_irvInport2' incorporates:
   *  Constant: '<S40>/Constant6'
   *  SignalConversion: '<S40>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_concAirPredInCyl_irv(0.0F);

  /* SignalConversion: '<S89>/copy' incorporates:
   *  Constant: '<S40>/Constant7'
   */
  InM_concFuPred_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' */

  /* S-Function Block: <S89>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_concFuPred_irvInport2' incorporates:
   *  Constant: '<S40>/Constant7'
   *  SignalConversion: '<S40>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_concFuPred_irv(0.0F);

  /* SignalConversion: '<S90>/copy' incorporates:
   *  Constant: '<S40>/Constant8'
   */
  InM_concFuPredInCyl_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' */

  /* S-Function Block: <S90>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_concFuPredInCyl_irvInport2' incorporates:
   *  Constant: '<S40>/Constant8'
   *  SignalConversion: '<S40>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_concFuPredInCyl_irv(0.0F);

  /* SignalConversion: '<S77>/copy' incorporates:
   *  Constant: '<S40>/Constant10'
   */
  InM_nEngPred_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S77>/autosar_testpoint1' */

  /* S-Function Block: <S77>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_nEngPred_irvInport2' incorporates:
   *  Constant: '<S40>/Constant10'
   *  SignalConversion: '<S40>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_nEngPred_irv(0U);

  /* SignalConversion: '<S78>/copy' incorporates:
   *  Constant: '<S40>/Constant11'
   */
  InM_pDsThr_facVlvOvlp_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S78>/autosar_testpoint1' */

  /* S-Function Block: <S78>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_pDsThr_facVlvOvlp_irvInport2' incorporates:
   *  Constant: '<S40>/Constant11'
   *  SignalConversion: '<S40>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_pDsThr_facVlvOvlp_irv(0.0F);

  /* SignalConversion: '<S79>/copy' incorporates:
   *  Constant: '<S40>/Constant12'
   */
  InM_pDsThrPredInCylRaw_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S79>/autosar_testpoint1' */

  /* S-Function Block: <S79>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_pDsThrPredInCylRaw_irvInport2' incorporates:
   *  Constant: '<S40>/Constant12'
   *  SignalConversion: '<S40>/Signal Conversion12'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_pDsThrPredInCylRaw_irv(0.0F);

  /* SignalConversion: '<S80>/copy' incorporates:
   *  Constant: '<S40>/Constant13'
   */
  InM_pDsThrPredRaw_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S80>/autosar_testpoint1' */

  /* S-Function Block: <S80>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_pDsThrPredRaw_irvInport2' incorporates:
   *  Constant: '<S40>/Constant13'
   *  SignalConversion: '<S40>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_pDsThrPredRaw_irv(0.0F);

  /* SignalConversion: '<S81>/copy' incorporates:
   *  Constant: '<S40>/Constant14'
   */
  InM_tiHrznPredInCyl_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S81>/autosar_testpoint1' */

  /* S-Function Block: <S81>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_tiHrznPredInCyl_irvInport2' incorporates:
   *  Constant: '<S40>/Constant14'
   *  SignalConversion: '<S40>/Signal Conversion14'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_tiHrznPredInCyl_irv(0.0F);

  /* SignalConversion: '<S82>/copy' incorporates:
   *  Constant: '<S40>/Constant15'
   */
  InM_pDsThrSenEstim_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S82>/autosar_testpoint1' */

  /* S-Function Block: <S82>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_pDsThrSenEstim_irvInport2' incorporates:
   *  Constant: '<S40>/Constant15'
   *  SignalConversion: '<S40>/Signal Conversion15'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_pDsThrSenEstim_irv(0.0F);

  /* SignalConversion: '<S83>/copy' incorporates:
   *  Constant: '<S40>/Constant16'
   */
  InM_tiHrznPred_facVlvOvlp_IRV_MP = 0.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S83>/autosar_testpoint1' */

  /* S-Function Block: <S83>/autosar_testpoint1 */

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_tiHrznPred_facVlvOvlp_irvInport2' incorporates:
   *  Constant: '<S40>/Constant16'
   *  SignalConversion: '<S40>/Signal Conversion16'
   */
  Rte_IrvWrite_RE_InMdlT_001_MSE_InM_tiHrznPred_facVlvOvlp_irv(0.0F);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S40>/Constant17'
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_ab = InM_rCohMnfMf_B;
  } else {
    localSwitch_ab = 16384U;
  }

  /* SignalConversion: '<S40>/TmpSignal ConversionAtInM_rCohMnfMfInport2' */
  Rte_Write_P_InM_rCohMnfMf_InM_rCohMnfMf(localSwitch_ab);
}

/* Output and update for exported function: RE_InMdlT_036_MSE */
void RE_InMdlT_036_MSE(void)
{
  UInt16 localSwitch_hu;
  UInt8 localSwitch_fp;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F01_1_InEstimMnfRelax_initialization'
   *
   * Block requirements for '<S1>/INM2_F01_1_InEstimMnfRelax_initialization':
   *  1. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_356.01 ;
   *  2. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_372.01 ;
   *  3. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_373.01 ;
   *  4. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_374.01 ;
   *  5. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_375.01 ;
   *  6. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_390.01 ;
   *  7. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_391.01 ;
   *  8. SubSystem "INM2_F01_1_InEstimMnfRelax_initialization" !Trace_To : VEMS_R_11_01067_392.01 ;
   */

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Byp_Fonction_SC'
   *  Constant: '<S284>/Int_BypC'
   *  Constant: '<S54>/Cste_2'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_hu = InM_tiInvEigVal_mAir_B;
  } else {
    localSwitch_hu = 2U;
  }

  /* SignalConversion: '<S54>/TmpSignal ConversionAtInM_tiInvEigVal_mAirInport2' */
  Rte_Write_P_InM_tiInvEigVal_mAir_InM_tiInvEigVal_mAir(localSwitch_hu);

  /* Switch: '<S285>/Switch' incorporates:
   *  Constant: '<S285>/Byp_Fonction_SC'
   *  Constant: '<S285>/Int_BypC'
   *  Constant: '<S54>/Cste_1'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_hu = InM_facCoplMassPres_B;
  } else {
    localSwitch_hu = 0U;
  }

  /* SignalConversion: '<S54>/TmpSignal ConversionAtInM_facCoplMassPresInport2' */
  Rte_Write_P_InM_facCoplMassPres_InM_facCoplMassPres(localSwitch_hu);

  /* Switch: '<S286>/Switch' incorporates:
   *  Constant: '<S286>/Byp_Fonction_SC'
   *  Constant: '<S286>/Int_BypC'
   *  Constant: '<S54>/Cste_3'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_fp = InM_tiRelax_mTotEstim_B;
  } else {
    localSwitch_fp = 0U;
  }

  /* SignalConversion: '<S54>/TmpSignal ConversionAtInM_tiRelax_mTotEstimInport2' */
  Rte_Write_P_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim(localSwitch_fp);

  /* Switch: '<S287>/Switch' incorporates:
   *  Constant: '<S287>/Byp_Fonction_SC'
   *  Constant: '<S287>/Int_BypC'
   *  Constant: '<S54>/Cste_0'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localSwitch_hu = InM_facRelaxCplMassPresEstim_B;
  } else {
    localSwitch_hu = 0U;
  }

  /* SignalConversion: '<S54>/TmpSignal ConversionAtInM_facRelaxCplMassPresEstimInport2' */
  Rte_Write_P_InM_facRelaxCplMassPresEstim_InM_facRelaxCplMassPresEstim
    (localSwitch_hu);
}

/* Start for exported function: RE_InMdlT_034_TEV */
void RE_InMdlT_034_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/INM2_F01_2_InEstimMnfRelax_calculation'
   *
   * Block requirements for '<S1>/INM2_F01_2_InEstimMnfRelax_calculation':
   *  1. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  2. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_372.01 ;
   *  3. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_373.01 ;
   *  4. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_374.01 ;
   *  5. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_375.01 ;
   *  6. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  7. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  8. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  9. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_210.01 ;
   *  10. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  11. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  12. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_239.01 ;
   *  13. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  14. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  15. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_390.01 ;
   *  16. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_391.01 ;
   *  17. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_393.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_034_TEV */
void RE_InMdlT_034_TEV(void)
{
  /* local block i/o variables */
  UInt16 localDivide_h2;
  UInt8 localLookUpTable_l;
  UInt8 localTmpSignalConversionAtEng_j;
  Boolean localRelationalOperator_l5;
  Float32 localDivide_ew;
  Float32 localSwitch_o5;
  Float32 localDivide_j3;
  Float32 localDivide_iy;
  UInt16 localTmpSignalConversionAtIn_o4;
  Boolean localTmpSignalConversionAtIn_am;
  UInt8 localTmpSignalConversionAtUsT_e;
  UInt16 localTmpSignalConversionAtIn_d2;
  UInt32 localTmpSignalConversionAtIn_au;
  UInt16 localTmpSignalConversionAtIn_js;
  UInt16 localTmpSignalConversionAtIn_hj;
  UInt8 localTmpSignalConversionAtI_kci;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/INM2_F01_2_InEstimMnfRelax_calculation'
   *
   * Block requirements for '<S1>/INM2_F01_2_InEstimMnfRelax_calculation':
   *  1. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_354.01 ;
   *  2. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_372.01 ;
   *  3. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_373.01 ;
   *  4. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_374.01 ;
   *  5. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_375.01 ;
   *  6. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_168.01 ;
   *  7. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_199.01 ;
   *  8. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_201.01 ;
   *  9. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_210.01 ;
   *  10. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  11. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_200.01 ;
   *  12. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_239.01 ;
   *  13. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_170.01 ;
   *  14. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_232.01 ;
   *  15. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_390.01 ;
   *  16. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_391.01 ;
   *  17. SubSystem "INM2_F01_2_InEstimMnfRelax_calculation" !Trace_To : VEMS_R_11_01067_393.01 ;
   */

  /* SignalConversion: '<S55>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_j);

  /* RelationalOperator: '<S55>/Relational Operator' incorporates:
   *  Constant: '<S55>/Ext_stRun_SC'
   */
  localRelationalOperator_l5 = (localTmpSignalConversionAtEng_j == Ext_stRun_SC);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_arEffAdpThrOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpThr_INPUT'
   */
  Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr(&localTmpSignalConversionAtIn_hj);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_facCfeGradThrOutport2' incorporates:
   *  Inport: '<Root>/InM_facCfeGradThr_INPUT'
   */
  Rte_Read_R_InM_facCfeGradThr_InM_facCfeGradThr
    (&localTmpSignalConversionAtIn_js);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&localTmpSignalConversionAtUsT_e);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_bAcceEngOutport2' incorporates:
   *  Inport: '<Root>/InM_bAcceEng_INPUT'
   */
  Rte_Read_R_InM_bAcceEng_InM_bAcceEng(&localTmpSignalConversionAtIn_am);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_tiRelax_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_tiRelax_pDsThrEstim_INPUT'
   */
  Rte_Read_R_InM_tiRelax_pDsThrEstim_InM_tiRelax_pDsThrEstim
    (&localTmpSignalConversionAtI_kci);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_tiInvEigVal_pDsThrOutport2' incorporates:
   *  Inport: '<Root>/InM_tiInvEigVal_pDsThr_INPUT'
   */
  Rte_Read_R_InM_tiInvEigVal_pDsThr_InM_tiInvEigVal_pDsThr
    (&localTmpSignalConversionAtIn_o4);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_mfAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirEstim_INPUT'
   */
  Rte_Read_R_InM_mfAirEstim_InM_mfAirEstim(&localTmpSignalConversionAtIn_d2);

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_mAirEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mAirEstim_INPUT'
   */
  Rte_Read_R_InM_mAirEstim_InM_mAirEstim(&localTmpSignalConversionAtIn_au);

  /* If: '<S55>/If' incorporates:
   *  ActionPort: '<S288>/Action Port'
   *  ActionPort: '<S289>/Action Port'
   *  SubSystem: '<S55>/F01_Engine_not_running'
   *  SubSystem: '<S55>/F02_Engine_running'
   *
   * Block requirements for '<S55>/F01_Engine_not_running':
   *  1. SubSystem "F01_Engine_not_running" !Trace_To : VEMS_R_11_01067_394.01 ;
   *
   * Block requirements for '<S55>/F02_Engine_running':
   *  1. SubSystem "F02_Engine_running" !Trace_To : VEMS_R_11_01067_395.01 ;
   */
  if (localRelationalOperator_l5) {
    /* Outputs for atomic SubSystem: '<S289>/F01_Calc_manifold_air_mass_eigenvalue' *
     * Block requirements for '<S289>/F01_Calc_manifold_air_mass_eigenvalue':
     *  1. SubSystem "F01_Calc_manifold_air_mass_eigenvalue" !Trace_To : VEMS_R_11_01067_396.01 ;
     */

    /* Product: '<S298>/Divide' incorporates:
     *  Constant: '<S294>/Cste_-1'
     *  DataTypeConversion: '<S294>/Data Type Conversion1'
     *  Product: '<S300>/Divide'
     *  Product: '<S301>/Divide'
     */
    localDivide_j3 = (((Float32)((ACTEMS_LdexpF((Float32d)
      localTmpSignalConversionAtIn_js, -11) - 3.1999511718750000E+001F) * -1.0F)) *
                      (((Float32)localTmpSignalConversionAtIn_hj) *
                       5.960464478E-008F)) / (((Float32)
      localTmpSignalConversionAtUsT_e) * 0.125F);

    /* Outputs for atomic SubSystem: '<S298>/If Action Subsystem3' */

    /* Switch: '<S305>/Switch1' incorporates:
     *  Constant: '<S305>/Constant1'
     *  Constant: '<S305>/Constant2'
     *  Constant: '<S305>/Constant3'
     *  Logic: '<S305>/Logical Operator1'
     *  RelationalOperator: '<S305>/Relational Operator'
     *  RelationalOperator: '<S305>/Relational Operator1'
     *  RelationalOperator: '<S305>/Relational Operator3'
     */
    if (((localDivide_j3 != localDivide_j3) || (localDivide_j3 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_j3)) {
      localDivide_j3 = 1.000000012E-007F;
    }

    /* end of Outputs for SubSystem: '<S298>/If Action Subsystem3' */

    /* Product: '<S299>/Divide' incorporates:
     *  DataTypeConversion: '<S294>/Data Type Conversion2'
     *  DataTypeConversion: '<S294>/Data Type Conversion4'
     */
    localDivide_iy = (((Float32)localTmpSignalConversionAtIn_d2) *
                      1.525878906E-005F) / (((Float32)
      localTmpSignalConversionAtIn_au) * 1.862645149E-009F);

    /* Outputs for atomic SubSystem: '<S299>/If Action Subsystem3' */

    /* Switch: '<S307>/Switch1' incorporates:
     *  Constant: '<S307>/Constant1'
     *  Constant: '<S307>/Constant2'
     *  Constant: '<S307>/Constant3'
     *  Logic: '<S307>/Logical Operator1'
     *  RelationalOperator: '<S307>/Relational Operator'
     *  RelationalOperator: '<S307>/Relational Operator1'
     *  RelationalOperator: '<S307>/Relational Operator3'
     */
    if (((localDivide_iy != localDivide_iy) || (localDivide_iy >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_iy)) {
      localDivide_iy = 10.0F;
    }

    /* end of Outputs for SubSystem: '<S299>/If Action Subsystem3' */

    /* Switch: '<S294>/Switch' incorporates:
     *  Constant: '<S294>/Cste_1'
     *  Constant: '<S294>/InM_rKk2_C'
     *  DataTypeConversion: '<S294>/Data Type Conversion3'
     */
    if (localTmpSignalConversionAtIn_am) {
      localSwitch_o5 = 1.0F;
    } else {
      localSwitch_o5 = ((Float32)InM_rKk2_C) * 0.00390625F;
    }

    /* Product: '<S302>/Divide' */
    localDivide_ew = localSwitch_o5 * localDivide_j3;

    /* Product: '<S303>/Divide' */
    localDivide_iy *= localSwitch_o5;

    /* end of Outputs for SubSystem: '<S289>/F01_Calc_manifold_air_mass_eigenvalue' */

    /* Outputs for atomic SubSystem: '<S289>/F02_Calc_mass_relaxation_term' *
     * Block requirements for '<S289>/F02_Calc_mass_relaxation_term':
     *  1. SubSystem "F02_Calc_mass_relaxation_term" !Trace_To : VEMS_R_11_01067_397.01 ;
     */

    /* Product: '<S312>/Divide' incorporates:
     *  Constant: '<S295>/InM_tiSampleFast_SC_1'
     */
    localtmp = (((Float32d)InM_tiSampleFast_SC) * 0.0005F) * ((Float32d)
      localDivide_iy);
    localtmp = ACTEMS_LdexpF(localtmp, 10);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localDivide_h2 = (UInt16)localtmp;
      } else {
        localDivide_h2 = 0U;
      }
    } else {
      localDivide_h2 = MAX_uint16_T;
    }

    /* Lookup: '<S308>/Look-Up Table'
     * About '<S308>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-10
     * Output0 Data Type:  Fixed Point    U8  2^-8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_l), (&(InM_facRelax_T[0])), localDivide_h2,
                  (&(InM_facRelax_A[0])), 29U);

    /* DataTypeDuplicate Block: '<S308>/Data Type Duplicate1'
     *
     * Regarding '<S308>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S313>/Divide' incorporates:
     *  Constant: '<S295>/InM_tiSampleFast_SC'
     */
    localDivide_j3 = (Float32)((((Float32d)InM_tiSampleFast_SC) * 0.0005F) *
      ACTEMS_LdexpF((Float32d)localLookUpTable_l, -8));

    /* DataTypeConversion: '<S309>/OutDTConv' incorporates:
     *  Constant: '<S309>/offset'
     *  Constant: '<S309>/offset1'
     *  Constant: '<S309>/one_on_slope'
     *  Product: '<S309>/Product4'
     *  Sum: '<S309>/Add1'
     *  Sum: '<S309>/Add2'
     */
    localSwitch_o5 = (16384.0F * localDivide_j3) + 0.5F;
    if (localSwitch_o5 < 256.0F) {
      if (localSwitch_o5 >= 0.0F) {
        localTmpSignalConversionAtEng_j = (UInt8)localSwitch_o5;
      } else {
        localTmpSignalConversionAtEng_j = 0U;
      }
    } else {
      localTmpSignalConversionAtEng_j = MAX_uint8_T;
    }

    /* Product: '<S311>/Divide' incorporates:
     *  Product: '<S314>/Divide'
     *  Sum: '<S295>/Sum'
     *  Sum: '<S295>/Sum1'
     */
    localDivide_j3 = (((((Float32)localTmpSignalConversionAtI_kci) *
                        6.103515625E-005F) - localDivide_j3) * localDivide_ew) /
      (localDivide_iy - ((Float32)localTmpSignalConversionAtIn_o4));

    /* Outputs for atomic SubSystem: '<S311>/If Action Subsystem3' */

    /* Switch: '<S316>/Switch1' incorporates:
     *  Constant: '<S316>/Constant1'
     *  Constant: '<S316>/Constant2'
     *  Constant: '<S316>/Constant3'
     *  Logic: '<S316>/Logical Operator1'
     *  RelationalOperator: '<S316>/Relational Operator'
     *  RelationalOperator: '<S316>/Relational Operator1'
     *  RelationalOperator: '<S316>/Relational Operator3'
     */
    if (((localDivide_j3 != localDivide_j3) || (localDivide_j3 >
          3.000000005E+038F)) || (-3.000000005E+038F > localDivide_j3)) {
      localDivide_j3 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S311>/If Action Subsystem3' */

    /* DataTypeConversion: '<S310>/OutDTConv' incorporates:
     *  Constant: '<S310>/offset'
     *  Constant: '<S310>/offset1'
     *  Constant: '<S310>/one_on_slope'
     *  Product: '<S310>/Product4'
     *  Sum: '<S310>/Add1'
     *  Sum: '<S310>/Add2'
     */
    localSwitch_o5 = (1.099511628E+012F * localDivide_j3) + 0.5F;
    if (localSwitch_o5 < 65536.0F) {
      if (localSwitch_o5 >= 0.0F) {
        localTmpSignalConversionAtIn_o4 = (UInt16)localSwitch_o5;
      } else {
        localTmpSignalConversionAtIn_o4 = 0U;
      }
    } else {
      localTmpSignalConversionAtIn_o4 = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S289>/F02_Calc_mass_relaxation_term' */

    /* DataTypeConversion: '<S296>/OutDTConv' incorporates:
     *  Constant: '<S296>/offset'
     *  Constant: '<S296>/offset1'
     *  Constant: '<S296>/one_on_slope'
     *  Product: '<S296>/Product4'
     *  Sum: '<S296>/Add1'
     *  Sum: '<S296>/Add2'
     */
    localSwitch_o5 = localDivide_iy + 0.5F;
    if (localSwitch_o5 < 65536.0F) {
      if (localSwitch_o5 >= 0.0F) {
        localTmpSignalConversionAtIn_hj = (UInt16)localSwitch_o5;
      } else {
        localTmpSignalConversionAtIn_hj = 0U;
      }
    } else {
      localTmpSignalConversionAtIn_hj = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S297>/OutDTConv' incorporates:
     *  Constant: '<S297>/offset'
     *  Constant: '<S297>/offset1'
     *  Constant: '<S297>/one_on_slope'
     *  Product: '<S297>/Product4'
     *  Sum: '<S297>/Add1'
     *  Sum: '<S297>/Add2'
     */
    localSwitch_o5 = (6.7108864E+007F * localDivide_ew) + 0.5F;
    if (localSwitch_o5 < 65536.0F) {
      if (localSwitch_o5 >= 0.0F) {
        localTmpSignalConversionAtIn_js = (UInt16)localSwitch_o5;
      } else {
        localTmpSignalConversionAtIn_js = 0U;
      }
    } else {
      localTmpSignalConversionAtIn_js = MAX_uint16_T;
    }
  } else {
    /* Constant: '<S288>/Cste_2' */
    localTmpSignalConversionAtIn_hj = 2U;

    /* Constant: '<S288>/Cste_1' */
    localTmpSignalConversionAtIn_js = 0U;

    /* Constant: '<S288>/Cste_3' */
    localTmpSignalConversionAtEng_j = 0U;

    /* Constant: '<S288>/Cste_0' */
    localTmpSignalConversionAtIn_o4 = 0U;
  }

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Byp_Fonction_SC'
   *  Constant: '<S291>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_js = InM_facCoplMassPres_B;
  }

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_facCoplMassPresInport2' */
  Rte_Write_P_InM_facCoplMassPres_InM_facCoplMassPres
    (localTmpSignalConversionAtIn_js);

  /* Switch: '<S293>/Switch' incorporates:
   *  Constant: '<S293>/Byp_Fonction_SC'
   *  Constant: '<S293>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_o4 = InM_facRelaxCplMassPresEstim_B;
  }

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_facRelaxCplMassPresEstimInport2' */
  Rte_Write_P_InM_facRelaxCplMassPresEstim_InM_facRelaxCplMassPresEstim
    (localTmpSignalConversionAtIn_o4);

  /* Switch: '<S290>/Switch' incorporates:
   *  Constant: '<S290>/Byp_Fonction_SC'
   *  Constant: '<S290>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtIn_hj = InM_tiInvEigVal_mAir_B;
  }

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_tiInvEigVal_mAirInport2' */
  Rte_Write_P_InM_tiInvEigVal_mAir_InM_tiInvEigVal_mAir
    (localTmpSignalConversionAtIn_hj);

  /* Switch: '<S292>/Switch' incorporates:
   *  Constant: '<S292>/Byp_Fonction_SC'
   *  Constant: '<S292>/Int_BypC'
   */
  if (INMDLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_j = InM_tiRelax_mTotEstim_B;
  }

  /* SignalConversion: '<S55>/TmpSignal ConversionAtInM_tiRelax_mTotEstimInport2' */
  Rte_Write_P_InM_tiRelax_mTotEstim_InM_tiRelax_mTotEstim
    (localTmpSignalConversionAtEng_j);
}

/* Start for exported function: RE_InMdlT_037_TEV */
void RE_InMdlT_037_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_IntkUpdTmr'
   *
   * Block requirements for '<S1>/F00_IntkUpdTmr':
   *  1. SubSystem "F00_IntkUpdTmr" !Trace_To : VEMS_R_11_01067_391.01 ;
   */
}

/* Output and update for exported function: RE_InMdlT_037_TEV */
void RE_InMdlT_037_TEV(void)
{
  /* local block i/o variables */
  UInt32 localFRT_tiSenFilTmr_irv;
  Std_ReturnType localRte_Call_R_InMdlT_GetTimer;

  /* S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_IntkUpdTmr'
   *
   * Block requirements for '<S1>/F00_IntkUpdTmr':
   *  1. SubSystem "F00_IntkUpdTmr" !Trace_To : VEMS_R_11_01067_391.01 ;
   */

  /* S-Function (Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U32): '<S39>/Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U32' */
  localRte_Call_R_InMdlT_GetTimer =
    Rte_Call_R_InMdlT_GetTimer_100us_U32_GetTimer_100us_U32
    ( &localFRT_tiSenFilTmr_irv);

  /* SignalConversion: '<S39>/TmpSignal ConversionAtFRT_tiSenFilTmr_irvInport2' */
  Rte_IrvWrite_RE_InMdlT_037_TEV_FRT_tiSenFilTmr_irv(localFRT_tiSenFilTmr_irv);
}

/* Model initialize function */
void RE_InMdlT_Init(void)
{
  /* Registration code */

  /* block I/O */
  {
    InMdlT_B.TmpSignalConversionAtInM_facCfe = 65535U;
    InMdlT_B.Merge3_a = 65535U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__10'
   *  Start for SubSystem: '<Root>/__ExpFcn__11'
   *  Start for SubSystem: '<Root>/__ExpFcn__114'
   *  Start for SubSystem: '<Root>/__ExpFcn__117'
   *  Start for SubSystem: '<Root>/__ExpFcn__118'
   *  Start for SubSystem: '<Root>/__ExpFcn__12'
   *  Start for SubSystem: '<Root>/__ExpFcn__125'
   *  Start for SubSystem: '<Root>/__ExpFcn__13'
   *  Start for SubSystem: '<Root>/__ExpFcn__14'
   *  Start for SubSystem: '<Root>/__ExpFcn__15'
   *  Start for SubSystem: '<Root>/__ExpFcn__16'
   *  Start for SubSystem: '<Root>/__ExpFcn__17'
   *  Start for SubSystem: '<Root>/__ExpFcn__18'
   *  Start for SubSystem: '<Root>/__ExpFcn__19'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__20'
   *  Start for SubSystem: '<Root>/__ExpFcn__21'
   *  Start for SubSystem: '<Root>/__ExpFcn__22'
   *  Start for SubSystem: '<Root>/__ExpFcn__23'
   *  Start for SubSystem: '<Root>/__ExpFcn__24'
   *  Start for SubSystem: '<Root>/__ExpFcn__25'
   *  Start for SubSystem: '<Root>/__ExpFcn__26'
   *  Start for SubSystem: '<Root>/__ExpFcn__27'
   *  Start for SubSystem: '<Root>/__ExpFcn__28'
   *  Start for SubSystem: '<Root>/__ExpFcn__29'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__30'
   *  Start for SubSystem: '<Root>/__ExpFcn__31'
   *  Start for SubSystem: '<Root>/__ExpFcn__32'
   *  Start for SubSystem: '<Root>/__ExpFcn__33'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   *  Start for SubSystem: '<Root>/__ExpFcn__8'
   *  Start for SubSystem: '<Root>/__ExpFcn__9'
   */
  RE_InMdlT_008_TEV_Start();
  RE_InMdlT_004_TEV_Start();
  RE_InMdlT_037_MSE_Start();
  RE_InMdlT_039_MSE_Start();
  RE_InMdlT_031_TEV_Start();
  RE_InMdlT_038_MSE_Start();
  RE_InMdlT_027_TEV_Start();
  RE_InMdlT_029_TEV_Start();
  RE_InMdlT_002_TEV_Start();
  RE_InMdlT_040_MSE_Start();
  RE_InMdlT_006_TEV_Start();
  RE_InMdlT_042_MSE_Start();
  RE_InMdlT_028_TEV_Start();
  RE_InMdlT_046_MSE_Start();
  RE_InMdlT_013_DRE_Start();
  RE_InMdlT_012_TEV_Start();
  RE_InMdlT_041_MSE_Start();
  RE_InMdlT_010_TEV_Start();
  RE_InMdlT_047_MSE_Start();
  RE_InMdlT_015_DRE_Start();
  RE_InMdlT_014_TEV_Start();
  RE_InMdlT_016_TEV_Start();
  RE_InMdlT_026_TEV_Start();
  RE_InMdlT_033_TEV_Start();
  RE_InMdlT_018_TEV_Start();
  RE_InMdlT_044_MSE_Start();
  RE_InMdlT_022_TEV_Start();
  RE_InMdlT_024_DRE_Start();
  RE_InMdlT_020_TEV_Start();
  RE_InMdlT_001_MSE_Start();
  RE_InMdlT_034_TEV_Start();
  RE_InMdlT_037_TEV_Start();
}

#define InMdlT_STOP_SEC_CODE
#include "InMdlT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
