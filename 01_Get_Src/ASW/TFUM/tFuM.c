/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : tFuM                                                    */
/* !Description     : tFuM – Fuel temperature estimation                      */
/*                                                                            */
/* !Module          : tFuM                                                    */
/*                                                                            */
/* !File            : tFuM.c                                                  */
/*                                                                            */
/* !Target          : All (optimized for "Generic->32-bit x86 compatible")    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V02NT1200996 / 02                                       */
/* !OtherRefs       : VEMS V02 ECU#062531                                     */
/* !OtherRefs       : VEMS V02 ECU#063038                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Aug 30 11:09:41 2012                              */
/*   Model name       : tFuM_AUTOCODE.mdl                                     */
/*   Model version    : 1.502                                                 */
/*   Root subsystem   : /tFuM                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/tFuM/5-SOFT-LIV/tFuM.c_v    $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   adelvare                               $$Date::   30 Aug 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "tFuM.h"
#include "tFuM_private.h"

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
#define TFUM_START_SEC_VAR_UNSPECIFIED
#include "tFuM_MemMap.h"

/* Block signals (auto storage) */
BlockIO_tFuM tFuM_B;

/* Block states (auto storage) */
D_Work_tFuM tFuM_DWork;

#define TFUM_STOP_SEC_VAR_UNSPECIFIED
#include "tFuM_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define TFUM_START_SEC_CODE
#include "tFuM_MemMap.h"

void tFuM_ASYNC1(int controlPortIdx)
{
}

void tFuM_ASYNC2(int controlPortIdx)
{
}

void tFuM_ASYNC3(int controlPortIdx)
{
}

void tFuM_ASYNC4(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S6>/F01_Ini_tEng' */
void tFuM_F01_Ini_tEng(void)
{
  /* S-Function "vems_vidGET" Block: <S10>/VEMS_vidGET */
  VEMS_vidGET(UsThrM_tThrMes, tFuM_B.VEMS_vidGET_i);

  /* DataTypeConversion: '<S10>/DTConv_UFix_To_Single_1' */
  FuSysM_tEng = (((Float32)tFuM_B.VEMS_vidGET_i) * 0.0078125F) + 223.0F;
}

/* Output and update for function-call system: '<S7>/F00_Ini_acvTFu' */
void tFuM_F00_Ini_acvTFu(void)
{
  /* SignalConversion: '<S22>/Signal Conversion3' incorporates:
   *  Constant: '<S22>/ConstVal'
   */
  FuSysM_bAcvTFuInit = TRUE;
}

/* Start for exported function: FuSysM_EveRst_tFuM */
void FuSysM_EveRst_tFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/tFuM_fc_demux_1'
   */
}

/* Output and update for exported function: FuSysM_EveRst_tFuM */
void FuSysM_EveRst_tFuM(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S5>/tFuM_fc_demux_1'
   */

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/F01_Ini_tEng'
   *  SubSystem: '<S7>/F00_Ini_acvTFu'
   */
  tFuM_F01_Ini_tEng();
  tFuM_F00_Ini_acvTFu();
}

/* Output and update for function-call system: '<S6>/F02_Calc_tEng' */
void tFuM_F02_Calc_tEng(void)
{
  Float32 localSum1_c;
  Float32 localSum1;
  UInt16 localfractionTmp_0d;
  Float32 localfrac[2];
  UInt32 localExt_spdVeh_FuSysM_spdVeh_A;
  UInt32 localbpIndex[2];
  UInt32 localCf_speed_for_air_FuSysM_rS;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  UInt16 localExt_spdVeh_FuSysM_spdVeh_a;
  UInt16 localCf_speed_for_air_FuSysM__k;

  /* Outputs for enable SubSystem: '<S11>/F02_Calc_tEng' incorporates:
   *  Constant: '<S11>/ConstVal'
   *  Constant: '<S11>/TFUM_u8Inhib'
   *  EnablePort: '<S12>/Enable'
   *  RelationalOperator: '<S11>/Relational Operator'
   */
  if (TFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_tOilEstim, tFuM_B.VEMS_vidGET1_g);

    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S12>/ConstVal'
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     */
    localSum1 = (((Float32)tFuM_B.VEMS_vidGET1_g) * 0.25F) + 2.731499939E+002F;

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tAirExtMes, tFuM_B.VEMS_vidGET3_h);

    /* Sum: '<S12>/Sum2' incorporates:
     *  Constant: '<S12>/ConstVal'
     *  DataTypeConversion: '<S12>/Data Type Conversion2'
     */
    localSum1_c = 2.731499939E+002F + ((Float32)tFuM_B.VEMS_vidGET3_h);

    /* Sum: '<S12>/Add2' */
    FuSysM_tOiltAirDif = localSum1 - localSum1_c;

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_spdVeh, tFuM_B.VEMS_vidGET2_k);

    /* PreLookup: '<S17>/Prelookup' */
    localExt_spdVeh_FuSysM_spdVeh_A = plook_u32u8u16n15_binc_n
      (tFuM_B.VEMS_vidGET2_k, (&(FuSysM_spdVeh_A[0])), 8U,
       &localExt_spdVeh_FuSysM_spdVeh_a);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET */
    VEMS_vidGET(Cf_speed_for_air, tFuM_B.VEMS_vidGET_la);

    /* PreLookup: '<S16>/Prelookup' */
    localCf_speed_for_air_FuSysM_rS = plook_u32u8u16n15_binc_n
      (tFuM_B.VEMS_vidGET_la, (&(FuSysM_rSpdFanReq_A[0])), 8U,
       &localCf_speed_for_air_FuSysM__k);

    /* Interpolation_n-D: '<S14>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_a;
    localfrac[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localfractionTmp_0d = localCf_speed_for_air_FuSysM__k;
    localfrac[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localbpIndex[0] = localExt_spdVeh_FuSysM_spdVeh_A;
    localbpIndex[1] = localCf_speed_for_air_FuSysM_rS;
    FuSysM_facExgUndHo = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex, localfrac,
      (&(FuSysM_facExgUndHo_M[0])), 9U);

    /* Sum: '<S12>/Add3' incorporates:
     *  Product: '<S18>/Divide'
     */
    FuSysM_tEngRaw = (FuSysM_facExgUndHo * FuSysM_tOiltAirDif) + localSum1_c;

    /* Interpolation_n-D: '<S15>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_a;
    localfrac_0[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localfractionTmp_0d = localCf_speed_for_air_FuSysM__k;
    localfrac_0[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localbpIndex_0[0] = localExt_spdVeh_FuSysM_spdVeh_A;
    localbpIndex_0[1] = localCf_speed_for_air_FuSysM_rS;
    FuSysM_rGainFilUndHo = intrp2d_iu16n15ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(FuSysM_rGainFilUndHo_M[0])), 9U);

    /* SignalConversion: '<S12>/Signal Conversion1' */
    FuSysM_tEngPrev = FuSysM_tEng;

    /* SignalConversion: '<S12>/Signal Conversion' incorporates:
     *  Product: '<S21>/Product'
     *  Saturate: '<S21>/Saturation [0-1]'
     *  Sum: '<S21>/Sum'
     *  Sum: '<S21>/Sum1'
     */
    FuSysM_tEng = ((FuSysM_tEngRaw - FuSysM_tEngPrev) * rt_SATURATE
                   (FuSysM_rGainFilUndHo, 0.0F, 1.0F)) + FuSysM_tEngPrev;
  }

  /* end of Outputs for SubSystem: '<S11>/F02_Calc_tEng' */
}

/* Output and update for function-call system: '<S7>/F02_Sdl_Calc_fuel_temp' */
void tFuM_F02_Sdl_Calc_fuel_temp(void)
{
  SInt32 localDataTypeConversion1_m;
  SInt32 localDataTypeConversion2;
  Boolean localLogicalOperator3;
  Float32 localMerge_l;
  Boolean localRelationalOperator_k;
  Boolean localLogicalOperator2_o;
  Float32 localDataTypeConversion2_c;
  Float32 localfrac[2];
  UInt32 localExt_tCoMes_FuSysM_tCoMes_A;
  UInt32 localbpIndex[2];
  UInt32 localExt_tAirExtMes_FuSysM_tAir;
  Float32 localDivide_b;
  UInt32 localFuSysM_mfFuEstim_FuSysM_mf;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
  UInt32 localbpIndex_1[2];
  Float32 localSwitch_d;
  Float32 localfrac_2[2];
  UInt32 localExt_spdVeh_FuSysM_spdVeh_o;
  UInt32 localbpIndex_2[2];
  UInt32 localCf_speed_for_air_FuSysM__j;
  Float32 localfrac_3[2];
  UInt32 localbpIndex_3[2];
  Float32 localfrac_4[2];
  UInt32 localbpIndex_4[2];
  Float32 localSwitch;
  Float32 localSwitch_p;
  UInt16 localfractionTmp_0d;
  Float32 localfrac_5[2];
  UInt32 localbpIndex_5[2];
  Float32 localfrac_6[2];
  UInt32 localbpIndex_6[2];
  UInt16 localExt_tCoMes_FuSysM_tCoMes_a;
  UInt16 localExt_tAirExtMes_FuSysM_tA_p;
  UInt16 localFuSysM_mfFuEstim_FuSysM__d;
  UInt16 localExt_spdVeh_FuSysM_spdVeh_f;
  UInt16 localCf_speed_for_air_FuSysM__c;
  UInt16 localExt_pFuRailMes_FuSysM_pF_o;
  UInt8 locallocalOutDTConv;

  /* Outputs for enable SubSystem: '<S24>/F02_Sdl_Calc_fuel_temp' incorporates:
   *  Constant: '<S24>/ConstVal'
   *  Constant: '<S24>/TFUM_u8Inhib'
   *  EnablePort: '<S35>/Enable'
   *  RelationalOperator: '<S24>/Relational Operator'
   */
  if (TFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_tCoMes, tFuM_B.VEMS_vidGET6);

    /* DataTypeConversion: '<S35>/Data Type Conversion1' */
    localDataTypeConversion1_m = tFuM_B.VEMS_vidGET6;

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_tAirExtMes, tFuM_B.VEMS_vidGET5);

    /* DataTypeConversion: '<S35>/Data Type Conversion2' */
    localDataTypeConversion2 = tFuM_B.VEMS_vidGET5;

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET7 */
    VEMS_vidGET(Ext_tFuRailMes, tFuM_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET8 */
    VEMS_vidGET(Ext_tFuUsPmpMes, tFuM_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEng, tFuM_B.VEMS_vidGET2_l);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_spdVeh, tFuM_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET */
    VEMS_vidGET(Cf_speed_for_air, tFuM_B.VEMS_vidGET_l);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET9 */
    VEMS_vidGET(InjrSys_mFuInjEstim, tFuM_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET10 */
    VEMS_vidGET(WaPmp_bAcvWaPmp, tFuM_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_stEru, tFuM_B.VEMS_vidGET1_j);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_pFuRailMes, tFuM_B.VEMS_vidGET3_j);

    /* SignalConversion: '<S35>/Signal Conversion3' */
    FuSysM_tFuUsPmpPrev = FuSysM_tFuUsPmpFineRsl;

    /* SignalConversion: '<S35>/Signal Conversion4' */
    FuSysM_tFuPrev = FuSysM_tFuFineRsl;

    /* If: '<S35>/If' incorporates:
     *  ActionPort: '<S36>/Action Port'
     *  ActionPort: '<S37>/Action Port'
     *  Constant: '<S35>/FuSysM_bAcvTFuETB_C'
     *  SubSystem: '<S35>/F01_ClcntFuTest'
     *  SubSystem: '<S35>/F02_ClcntFuNoTest'
     */
    if (FuSysM_bAcvTFuETB_C) {
      /* DataTypeConversion: '<S36>/Data Type Conversion' incorporates:
       *  Constant: '<S36>/FuSysM_tFuUsPmpETB_C'
       */
      localMerge_l = ((Float32)FuSysM_tFuUsPmpETB_C) + 233.0F;

      /* DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
       *  Constant: '<S36>/FuSysM_tFuETB_C'
       */
      localDivide_b = ((Float32)FuSysM_tFuETB_C) + 233.0F;
    } else {
      /* DataTypeConversion: '<S46>/OutDTConv' incorporates:
       *  Constant: '<S40>/ConstVal'
       *  Constant: '<S40>/Ext_noCylEng_SC'
       *  Constant: '<S46>/offset'
       *  Constant: '<S46>/offset1'
       *  Constant: '<S46>/one_on_slope'
       *  DataTypeConversion: '<S40>/Data Type Conversion'
       *  DataTypeConversion: '<S40>/Data Type Conversion1'
       *  DataTypeConversion: '<S40>/Data Type Conversion2'
       *  Product: '<S46>/Product4'
       *  Product: '<S47>/Divide'
       *  Product: '<S48>/Divide'
       *  Product: '<S49>/Divide'
       *  Sum: '<S46>/Add1'
       *  Sum: '<S46>/Add2'
       */
      localDivide_b = ((((((Float32)Ext_noCylEng_SC) / 120.0F) * ((Float32)
        tFuM_B.VEMS_vidGET2_l)) * (((Float32)tFuM_B.VEMS_vidGET9) *
        7.450580597E-009F)) * 2.56E+006F) + 0.5F;
      if (localDivide_b < 65536.0F) {
        FuSysM_mfFuEstim = (UInt16)localDivide_b;
      } else {
        FuSysM_mfFuEstim = MAX_uint16_T;
      }

      /* PreLookup: '<S45>/Prelookup' */
      localFuSysM_mfFuEstim_FuSysM_mf = plook_u32u16u16n15_binc_n
        (FuSysM_mfFuEstim, (&(FuSysM_mfFuEstim_A[0])), 8U,
         &localFuSysM_mfFuEstim_FuSysM__d);

      /* Logic: '<S41>/Logical Operator3' incorporates:
       *  Constant: '<S41>/Ext_bTSen_tFuUsPmp_SC'
       *  Inport: '<Root>/FRM_bInhMes_tFuUsPmp'
       *  Logic: '<S41>/Logical Operator2'
       */
      localLogicalOperator3 = (Ext_bTSen_tFuUsPmp_SC && (!GDGAR_bGetFRM
        (FRM_FRM_INHMES_TFUUSPMP)));

      /* PreLookup: '<S44>/Prelookup' */
      localExt_spdVeh_FuSysM_spdVeh_o = plook_u32u8u16n15_binc_n
        (tFuM_B.VEMS_vidGET4, (&(FuSysM_spdVeh_A[0])), 8U,
         &localExt_spdVeh_FuSysM_spdVeh_f);

      /* PreLookup: '<S43>/Prelookup' */
      localCf_speed_for_air_FuSysM__j = plook_u32u8u16n15_binc_n
        (tFuM_B.VEMS_vidGET_l, (&(FuSysM_rSpdFanReq_A[0])), 8U,
         &localCf_speed_for_air_FuSysM__c);

      /* If: '<S41>/If' incorporates:
       *  ActionPort: '<S50>/Action Port'
       *  ActionPort: '<S51>/Action Port'
       *  SubSystem: '<S41>/F01_tFuUsPmp_Mes'
       *  SubSystem: '<S41>/F02_tFuUsPmp_Calc'
       */
      if (localLogicalOperator3) {
        /* Sum: '<S50>/Sum1' incorporates:
         *  Constant: '<S50>/ConstVal'
         *  DataTypeConversion: '<S50>/Data Type Conversion2'
         */
        localMerge_l = 2.731499939E+002F + ((Float32)tFuM_B.VEMS_vidGET8);
      } else {
        /* RelationalOperator: '<S51>/Relational Operator' incorporates:
         *  Constant: '<S51>/Ext_stRun_SC'
         */
        localRelationalOperator_k = (tFuM_B.VEMS_vidGET1_j == Ext_stRun_SC);

        /* Logic: '<S51>/Logical Operator2' incorporates:
         *  Inport: '<Root>/FRM_bInhMes_tFuUsPmp'
         */
        localLogicalOperator2_o = !GDGAR_bGetFRM(FRM_FRM_INHMES_TFUUSPMP);

        /* Logic: '<S51>/Logical Operator1' incorporates:
         *  Logic: '<S54>/Logical Operator'
         *  Logic: '<S54>/Logical Operator1'
         *  Logic: '<S55>/Logical Operator'
         *  Logic: '<S55>/Logical Operator1'
         *  UnitDelay: '<S54>/UnitDelay'
         *  UnitDelay: '<S55>/UnitDelay'
         */
        FuSysM_bRstFil = (((localRelationalOperator_k) && (!tFuM_DWork.UnitDelay))
                          || ((localLogicalOperator2_o) &&
                              (!tFuM_DWork.UnitDelay_m)));

        /* If: '<S51>/If' incorporates:
         *  ActionPort: '<S52>/Action Port'
         *  ActionPort: '<S53>/Action Port'
         *  SubSystem: '<S51>/F01_tFuUsPmp_Running'
         *  SubSystem: '<S51>/F02_tFuUsPmp_not_Running'
         */
        if (localRelationalOperator_k) {
          /* UnitDelay: '<S81>/Unit Delay' */
          localLogicalOperator3 = tFuM_DWork.UnitDelay_DSTATE_e;

          /* DataTypeConversion: '<S52>/Data Type Conversion2' incorporates:
           *  Constant: '<S52>/FuSysM_tiSampleSlow_SC'
           */
          localDataTypeConversion2_c = ((Float32)FuSysM_tiSampleSlow_SC) *
            1.000000047E-003F;

          /* DataTypeConversion: '<S70>/OutDTConv' incorporates:
           *  Constant: '<S70>/offset'
           *  Constant: '<S70>/offset1'
           *  Constant: '<S70>/one_on_slope'
           *  Product: '<S70>/Product4'
           *  Sum: '<S70>/Add1'
           *  Sum: '<S70>/Add2'
           */
          localDivide_b = (((Float32)localDataTypeConversion1_m) - -40.0F) +
            0.5F;
          if (localDivide_b < 256.0F) {
            if (localDivide_b >= 0.0F) {
              locallocalOutDTConv = (UInt8)localDivide_b;
            } else {
              locallocalOutDTConv = 0U;
            }
          } else {
            locallocalOutDTConv = MAX_uint8_T;
          }

          /* PreLookup: '<S65>/Prelookup' */
          localExt_tCoMes_FuSysM_tCoMes_A = plook_u32u8u16n15_binc_n
            (locallocalOutDTConv, (&(FuSysM_tCoMes_A[0])), 8U,
             &localExt_tCoMes_FuSysM_tCoMes_a);

          /* DataTypeConversion: '<S71>/OutDTConv' incorporates:
           *  Constant: '<S71>/offset'
           *  Constant: '<S71>/offset1'
           *  Constant: '<S71>/one_on_slope'
           *  Product: '<S71>/Product4'
           *  Sum: '<S71>/Add1'
           *  Sum: '<S71>/Add2'
           */
          localDivide_b = (((Float32)localDataTypeConversion2) - -50.0F) + 0.5F;
          if (localDivide_b < 256.0F) {
            if (localDivide_b >= 0.0F) {
              locallocalOutDTConv = (UInt8)localDivide_b;
            } else {
              locallocalOutDTConv = 0U;
            }
          } else {
            locallocalOutDTConv = MAX_uint8_T;
          }

          /* PreLookup: '<S64>/Prelookup' */
          localExt_tAirExtMes_FuSysM_tAir = plook_u32u8u16n15_binc_n
            (locallocalOutDTConv, (&(FuSysM_tAirExtMes_A[0])), 8U,
             &localExt_tAirExtMes_FuSysM_tA_p);

          /* Interpolation_n-D: '<S68>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_tCoMes_FuSysM_tCoMes_a;
          localfrac[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localExt_tAirExtMes_FuSysM_tA_p;
          localfrac[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex[0] = localExt_tCoMes_FuSysM_tCoMes_A;
          localbpIndex[1] = localExt_tAirExtMes_FuSysM_tAir;
          FuSysM_tiFilBastFuUsPmp = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex,
            localfrac, (&(FuSysM_tiFilBastFuUsPmp_M[0])), 9U);

          /* Product: '<S78>/Divide' incorporates:
           *  Sum: '<S56>/Sum3'
           */
          localDivide_b = localDataTypeConversion2_c /
            (localDataTypeConversion2_c + FuSysM_tiFilBastFuUsPmp);

          /* Outputs for atomic SubSystem: '<S78>/If Action Subsystem3' */

          /* Switch: '<S83>/Switch1' incorporates:
           *  Constant: '<S83>/Constant1'
           *  Constant: '<S83>/Constant2'
           *  Constant: '<S83>/Constant3'
           *  Logic: '<S83>/Logical Operator1'
           *  RelationalOperator: '<S83>/Relational Operator'
           *  RelationalOperator: '<S83>/Relational Operator1'
           *  RelationalOperator: '<S83>/Relational Operator3'
           */
          if (((localDivide_b != localDivide_b) || (localDivide_b >
                3.000000005E+038F)) || (-3.000000005E+038F > localDivide_b)) {
            localDivide_b = 0.0F;
          }

          /* end of Outputs for SubSystem: '<S78>/If Action Subsystem3' */

          /* Interpolation_n-D: '<S61>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          FuSysM_facCormfFutFuUsPmp = intrp1d_iu8n7ff_u32f_l_ns
            (localFuSysM_mfFuEstim_FuSysM_mf, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facCormfFutFuUsPmp_T[0])));

          /* Interpolation_n-D: '<S67>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_tCoMes_FuSysM_tCoMes_a;
          localfrac_0[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localExt_tAirExtMes_FuSysM_tA_p;
          localfrac_0[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_0[0] = localExt_tCoMes_FuSysM_tCoMes_A;
          localbpIndex_0[1] = localExt_tAirExtMes_FuSysM_tAir;
          localMerge_l = intrp2d_iu8ff_u32f_l_s(localbpIndex_0, localfrac_0,
            (&(FuSysM_tFuUsPmpWaPmpOn_M[0])), 9U);

          /* Interpolation_n-D: '<S66>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_tCoMes_FuSysM_tCoMes_a;
          localfrac_1[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localExt_tAirExtMes_FuSysM_tA_p;
          localfrac_1[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_1[0] = localExt_tCoMes_FuSysM_tCoMes_A;
          localbpIndex_1[1] = localExt_tAirExtMes_FuSysM_tAir;
          localSwitch_d = intrp2d_iu8ff_u32f_l_s(localbpIndex_1, localfrac_1,
            (&(FuSysM_tFuUsPmpWaPmpOff_M[0])), 9U);

          /* Switch: '<S52>/Switch' */
          if (tFuM_B.VEMS_vidGET10) {
            FuSysM_tFuUsPmpBasRaw = localMerge_l;
          } else {
            FuSysM_tFuUsPmpBasRaw = localSwitch_d;
          }

          /* Product: '<S72>/Divide' */
          FuSysM_tFuUsPmpBasCorRaw = FuSysM_facCormfFutFuUsPmp *
            FuSysM_tFuUsPmpBasRaw;

          /* UnitDelay: '<S85>/Unit Delay' */
          localSwitch_d = tFuM_DWork.UnitDelay_DSTATE;

          /* Switch: '<S79>/Switch' incorporates:
           *  UnitDelay: '<S84>/Unit Delay'
           */
          if (!tFuM_DWork.UnitDelay_DSTATE_n) {
            localSwitch_d = FuSysM_tFuUsPmpPrev;
          }

          /* Switch: '<S56>/Switch' incorporates:
           *  Logic: '<S56>/Logical Operator'
           *  Product: '<S80>/Divide'
           *  Sum: '<S56>/Sum1'
           *  Sum: '<S56>/Sum2'
           */
          if (!FuSysM_bRstFil) {
            localSwitch = localSwitch_d - ((localSwitch_d -
              FuSysM_tFuUsPmpBasCorRaw) * localDivide_b);
          } else {
            localSwitch = FuSysM_tFuUsPmpPrev;
          }

          /* Switch: '<S77>/Switch' */
          if (localLogicalOperator3) {
            FuSysM_tFuUsPmpBasFil = localSwitch;
          } else {
            FuSysM_tFuUsPmpBasFil = FuSysM_tFuUsPmpPrev;
          }

          /* UnitDelay: '<S90>/Unit Delay' */
          localLogicalOperator3 = tFuM_DWork.UnitDelay_DSTATE_dp;

          /* Interpolation_n-D: '<S69>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_f;
          localfrac_2[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          localfrac_2[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_2[0] = localExt_spdVeh_FuSysM_spdVeh_o;
          localbpIndex_2[1] = localCf_speed_for_air_FuSysM__j;
          FuSysM_tiFilExgtFuUsPmp = intrp2d_iu16n6ff_u32f_l_ns(localbpIndex_2,
            localfrac_2, (&(FuSysM_tiFilExgtFuUsPmp_M[0])), 9U);

          /* Product: '<S87>/Divide' incorporates:
           *  Sum: '<S57>/Sum3'
           */
          localDivide_b = localDataTypeConversion2_c /
            (localDataTypeConversion2_c + FuSysM_tiFilExgtFuUsPmp);

          /* Outputs for atomic SubSystem: '<S87>/If Action Subsystem3' */

          /* Switch: '<S92>/Switch1' incorporates:
           *  Constant: '<S92>/Constant1'
           *  Constant: '<S92>/Constant2'
           *  Constant: '<S92>/Constant3'
           *  Logic: '<S92>/Logical Operator1'
           *  RelationalOperator: '<S92>/Relational Operator'
           *  RelationalOperator: '<S92>/Relational Operator1'
           *  RelationalOperator: '<S92>/Relational Operator3'
           */
          if (((localDivide_b != localDivide_b) || (localDivide_b >
                3.000000005E+038F)) || (-3.000000005E+038F > localDivide_b)) {
            localDivide_b = 0.0F;
          }

          /* end of Outputs for SubSystem: '<S87>/If Action Subsystem3' */

          /* Interpolation_n-D: '<S60>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          FuSysM_facCormfFutFuUsPmpExt = intrp1d_iu8n7ff_u32f_l_ns
            (localFuSysM_mfFuEstim_FuSysM_mf, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facCormfFutFuUsPmpExt_T[0])));

          /* Sum: '<S52>/Sum1' incorporates:
           *  Constant: '<S52>/ConstVal_1'
           *  Sum: '<S52>/Sum5'
           */
          FuSysM_tFuUsPmpAirDif = (2.731499939E+002F + ((Float32)
            localDataTypeConversion2)) - FuSysM_tFuUsPmpPrev;

          /* Interpolation_n-D: '<S63>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_f;
          localfrac_3[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          localfrac_3[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_3[0] = localExt_spdVeh_FuSysM_spdVeh_o;
          localbpIndex_3[1] = localCf_speed_for_air_FuSysM__j;
          FuSysM_facExgtExttFuUsPmp = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_3,
            localfrac_3, (&(FuSysM_facExgtExttFuUsPmp_M[0])), 9U);

          /* Product: '<S73>/Divide' */
          FuSysM_tFuUsPmpExtRaw = FuSysM_tFuUsPmpAirDif *
            FuSysM_facExgtExttFuUsPmp;

          /* Product: '<S74>/Divide' */
          FuSysM_tFuUsPmpExtCorRaw = FuSysM_facCormfFutFuUsPmpExt *
            FuSysM_tFuUsPmpExtRaw;

          /* UnitDelay: '<S94>/Unit Delay' */
          localSwitch_d = tFuM_DWork.UnitDelay_DSTATE_d;

          /* Switch: '<S88>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal_2'
           *  UnitDelay: '<S93>/Unit Delay'
           */
          if (!tFuM_DWork.UnitDelay_DSTATE_d5) {
            localSwitch_d = 0.0F;
          }

          /* Switch: '<S57>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal_2'
           *  Logic: '<S57>/Logical Operator'
           *  Product: '<S89>/Divide'
           *  Sum: '<S57>/Sum1'
           *  Sum: '<S57>/Sum2'
           */
          if (!FuSysM_bRstFil) {
            localSwitch_p = localSwitch_d - ((localSwitch_d -
              FuSysM_tFuUsPmpExtCorRaw) * localDivide_b);
          } else {
            localSwitch_p = 0.0F;
          }

          /* Switch: '<S86>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal_2'
           */
          if (localLogicalOperator3) {
            FuSysM_tFuUsPmpExtCorFil = localSwitch_p;
          } else {
            FuSysM_tFuUsPmpExtCorFil = 0.0F;
          }

          /* UnitDelay: '<S99>/Unit Delay' */
          localLogicalOperator3 = tFuM_DWork.UnitDelay_DSTATE_f;

          /* Product: '<S96>/Divide' incorporates:
           *  Sum: '<S58>/Sum3'
           */
          localDivide_b = localDataTypeConversion2_c /
            (localDataTypeConversion2_c + FuSysM_tiFilExgtFuUsPmp);

          /* Outputs for atomic SubSystem: '<S96>/If Action Subsystem3' */

          /* Switch: '<S101>/Switch1' incorporates:
           *  Constant: '<S101>/Constant1'
           *  Constant: '<S101>/Constant2'
           *  Constant: '<S101>/Constant3'
           *  Logic: '<S101>/Logical Operator1'
           *  RelationalOperator: '<S101>/Relational Operator'
           *  RelationalOperator: '<S101>/Relational Operator1'
           *  RelationalOperator: '<S101>/Relational Operator3'
           */
          if (((localDivide_b != localDivide_b) || (localDivide_b >
                3.000000005E+038F)) || (-3.000000005E+038F > localDivide_b)) {
            localDivide_b = 0.0F;
          }

          /* end of Outputs for SubSystem: '<S96>/If Action Subsystem3' */

          /* Interpolation_n-D: '<S59>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          FuSysM_facCormfFutFuUsPmpEng = intrp1d_iu8n7ff_u32f_l_ns
            (localFuSysM_mfFuEstim_FuSysM_mf, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facCormfFutFuUsPmpEng_T[0])));

          /* Sum: '<S52>/Sum3' */
          FuSysM_tFuUsPmptEngDif = FuSysM_tEng - FuSysM_tFuUsPmpPrev;

          /* Interpolation_n-D: '<S62>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_f;
          localfrac_4[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          localfrac_4[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_4[0] = localExt_spdVeh_FuSysM_spdVeh_o;
          localbpIndex_4[1] = localCf_speed_for_air_FuSysM__j;
          FuSysM_facExgtEngtFuUsPmp = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_4,
            localfrac_4, (&(FuSysM_facExgtEngtFuUsPmp_M[0])), 9U);

          /* Product: '<S75>/Divide' */
          FuSysM_tFuUsPmpEngRaw = FuSysM_tFuUsPmptEngDif *
            FuSysM_facExgtEngtFuUsPmp;

          /* Product: '<S76>/Divide' */
          FuSysM_tFuUsPmpEngCorRaw = FuSysM_facCormfFutFuUsPmpEng *
            FuSysM_tFuUsPmpEngRaw;

          /* UnitDelay: '<S103>/Unit Delay' */
          localSwitch_d = tFuM_DWork.UnitDelay_DSTATE_h;

          /* Switch: '<S97>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal'
           *  UnitDelay: '<S102>/Unit Delay'
           */
          if (!tFuM_DWork.UnitDelay_DSTATE_p) {
            localSwitch_d = 0.0F;
          }

          /* Switch: '<S58>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal'
           *  Logic: '<S58>/Logical Operator'
           *  Product: '<S98>/Divide'
           *  Sum: '<S58>/Sum1'
           *  Sum: '<S58>/Sum2'
           */
          if (!FuSysM_bRstFil) {
            localDivide_b = localSwitch_d - ((localSwitch_d -
              FuSysM_tFuUsPmpEngCorRaw) * localDivide_b);
          } else {
            localDivide_b = 0.0F;
          }

          /* Switch: '<S95>/Switch' incorporates:
           *  Constant: '<S52>/ConstVal'
           */
          if (localLogicalOperator3) {
            FuSysM_tFuUsPmpEngCorFil = localDivide_b;
          } else {
            FuSysM_tFuUsPmpEngCorFil = 0.0F;
          }

          /* Sum: '<S52>/Sum2' */
          localMerge_l = (FuSysM_tFuUsPmpBasFil + FuSysM_tFuUsPmpExtCorFil) +
            FuSysM_tFuUsPmpEngCorFil;

          /* Update for UnitDelay: '<S81>/Unit Delay' incorporates:
           *  Constant: '<S77>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_e = TRUE;

          /* Update for UnitDelay: '<S85>/Unit Delay' */
          tFuM_DWork.UnitDelay_DSTATE = localSwitch;

          /* Update for UnitDelay: '<S84>/Unit Delay' incorporates:
           *  Constant: '<S79>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_n = TRUE;

          /* Update for UnitDelay: '<S90>/Unit Delay' incorporates:
           *  Constant: '<S86>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_dp = TRUE;

          /* Update for UnitDelay: '<S94>/Unit Delay' */
          tFuM_DWork.UnitDelay_DSTATE_d = localSwitch_p;

          /* Update for UnitDelay: '<S93>/Unit Delay' incorporates:
           *  Constant: '<S88>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_d5 = TRUE;

          /* Update for UnitDelay: '<S99>/Unit Delay' incorporates:
           *  Constant: '<S95>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_f = TRUE;

          /* Update for UnitDelay: '<S103>/Unit Delay' */
          tFuM_DWork.UnitDelay_DSTATE_h = localDivide_b;

          /* Update for UnitDelay: '<S102>/Unit Delay' incorporates:
           *  Constant: '<S97>/Constant3'
           */
          tFuM_DWork.UnitDelay_DSTATE_p = TRUE;
        } else {
          /* Interpolation_n-D: '<S104>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          FuSysM_facExgAirtFuUsPmp = intrp1d_iu16n16ff_u32f_l_ns
            (localCf_speed_for_air_FuSysM__j, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facExgAirStalltFuUsPmp_T[0])));

          /* Sum: '<S53>/Sum1' incorporates:
           *  Constant: '<S53>/ConstVal_1'
           *  Sum: '<S53>/Sum5'
           */
          FuSysM_tFuUsPmpAirDifStall = (2.731499939E+002F + ((Float32)
            localDataTypeConversion2)) - FuSysM_tFuUsPmpPrev;

          /* Sum: '<S53>/Sum11' incorporates:
           *  Constant: '<S53>/ConstVal'
           *  Sum: '<S53>/Sum12'
           */
          FuSysM_tFuUsPmpWaDifStall = (2.731499939E+002F + ((Float32)
            localDataTypeConversion1_m)) - FuSysM_tFuUsPmpPrev;

          /* Product: '<S106>/Divide' incorporates:
           *  Constant: '<S53>/FuSysM_facExgWatFuUsPmp_C'
           */
          FuSysM_tFuUsPmpExgWaCor = (((Float32)FuSysM_facExgWatFuUsPmp_C) *
            1.525878906E-005F) * FuSysM_tFuUsPmpWaDifStall;

          /* Product: '<S105>/Divide' */
          FuSysM_tFuUsPmpExgAirCor = FuSysM_tFuUsPmpAirDifStall *
            FuSysM_facExgAirtFuUsPmp;

          /* Sum: '<S53>/Sum2' */
          localMerge_l = (FuSysM_tFuUsPmpPrev + FuSysM_tFuUsPmpExgWaCor) +
            FuSysM_tFuUsPmpExgAirCor;
        }

        /* Update for UnitDelay: '<S54>/UnitDelay' */
        tFuM_DWork.UnitDelay = localRelationalOperator_k;

        /* Update for UnitDelay: '<S55>/UnitDelay' */
        tFuM_DWork.UnitDelay_m = localLogicalOperator2_o;
      }

      /* If: '<S42>/If' incorporates:
       *  ActionPort: '<S107>/Action Port'
       *  ActionPort: '<S108>/Action Port'
       *  Constant: '<S42>/Ext_bTSen_tFuRail_SC'
       *  Inport: '<Root>/FRM_bInhMes_tFuRail'
       *  Logic: '<S42>/Logical Operator2'
       *  Logic: '<S42>/Logical Operator3'
       *  SubSystem: '<S42>/F01_tFu_Mes'
       *  SubSystem: '<S42>/F02_tFu_Calc'
       */
      if (Ext_bTSen_tFuRail_SC && (!GDGAR_bGetFRM(FRM_FRM_INHMES_TFURAIL))) {
        /* Sum: '<S107>/Sum1' incorporates:
         *  Constant: '<S107>/ConstVal'
         *  DataTypeConversion: '<S107>/Data Type Conversion1'
         */
        localDivide_b = 2.731499939E+002F + ((Float32)tFuM_B.VEMS_vidGET7);
      } else {
        /* If: '<S108>/If' incorporates:
         *  ActionPort: '<S109>/Action Port'
         *  ActionPort: '<S110>/Action Port'
         *  Constant: '<S108>/Ext_stRun_SC'
         *  RelationalOperator: '<S108>/Relational Operator'
         *  SubSystem: '<S108>/F01_tFu_Running'
         *  SubSystem: '<S108>/F02_tFu_not_Running'
         */
        if (tFuM_B.VEMS_vidGET1_j == Ext_stRun_SC) {
          /* DataTypeConversion: '<S109>/Data Type Conversion1' incorporates:
           *  Constant: '<S109>/FuSysM_facExgWatFu_C'
           */
          localDivide_b = ((Float32)FuSysM_facExgWatFu_C) * 1.525878906E-005F;

          /* Interpolation_n-D: '<S111>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          FuSysM_facCormfFutFuExgWa = intrp1d_iu8n7ff_u32f_l_ns
            (localFuSysM_mfFuEstim_FuSysM_mf, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facCormfFutFuExgWa_T[0])));

          /* Interpolation_n-D: '<S112>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          FuSysM_facCormfFutFu = intrp1d_iu8n7ff_u32f_l_ns
            (localFuSysM_mfFuEstim_FuSysM_mf, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facCormfFutFu_T[0])));

          /* PreLookup: '<S115>/Prelookup' */
          localExt_tCoMes_FuSysM_tCoMes_A = plook_u32u16u16n15_binc_n
            (tFuM_B.VEMS_vidGET3_j, (&(FuSysM_pFuRail_A[0])), 8U,
             &localExt_pFuRailMes_FuSysM_pF_o);

          /* Interpolation_n-D: '<S113>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localFuSysM_mfFuEstim_FuSysM__d;
          localfrac_5[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localExt_pFuRailMes_FuSysM_pF_o;
          localfrac_5[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_5[0] = localFuSysM_mfFuEstim_FuSysM_mf;
          localbpIndex_5[1] = localExt_tCoMes_FuSysM_tCoMes_A;
          FuSysM_facExgmfFu = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_5,
            localfrac_5, (&(FuSysM_facExgmfFu_M[0])), 9U);

          /* Interpolation_n-D: '<S114>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localExt_spdVeh_FuSysM_spdVeh_f;
          localfrac_6[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          localfrac_6[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
          localbpIndex_6[0] = localExt_spdVeh_FuSysM_spdVeh_o;
          localbpIndex_6[1] = localCf_speed_for_air_FuSysM__j;
          FuSysM_facExgtEngtFu = intrp2d_iu16n16ff_u32f_l_ns(localbpIndex_6,
            localfrac_6, (&(FuSysM_facExgtEngtFu_M[0])), 9U);

          /* Sum: '<S109>/Sum1' incorporates:
           *  Constant: '<S109>/ConstVal'
           *  Sum: '<S109>/Sum3'
           */
          FuSysM_tFutWaDif = (2.731499939E+002F + ((Float32)
            localDataTypeConversion1_m)) - FuSysM_tFuPrev;

          /* Sum: '<S109>/Sum2' */
          FuSysM_tFutFuUsPmpDif = localMerge_l - FuSysM_tFuPrev;

          /* Sum: '<S109>/Sum4' */
          FuSysM_tFutEngDif = FuSysM_tEng - FuSysM_tFuPrev;

          /* Product: '<S118>/Divide' */
          FuSysM_tFuExgtEngRaw = FuSysM_tFutEngDif * FuSysM_facExgtEngtFu;

          /* Product: '<S117>/Divide' */
          FuSysM_tFuExgtEngCor = FuSysM_tFuExgtEngRaw * FuSysM_facCormfFutFu;

          /* Product: '<S120>/Divide' */
          FuSysM_tFuExgmfFuCor = FuSysM_tFutFuUsPmpDif * FuSysM_facExgmfFu;

          /* Product: '<S119>/Divide' incorporates:
           *  Product: '<S116>/Divide'
           */
          FuSysM_tFuExgWaCor = (localDivide_b * FuSysM_facCormfFutFuExgWa) *
            FuSysM_tFutWaDif;

          /* Sum: '<S109>/Sum7' */
          localDivide_b = ((FuSysM_tFuPrev + FuSysM_tFuExgtEngCor) +
                           FuSysM_tFuExgmfFuCor) + FuSysM_tFuExgWaCor;
        } else {
          /* DataTypeConversion: '<S110>/Data Type Conversion1' incorporates:
           *  Constant: '<S110>/FuSysM_facExgWatFu_C'
           */
          localDivide_b = ((Float32)FuSysM_facExgWatFu_C) * 1.525878906E-005F;

          /* Interpolation_n-D: '<S121>/Interpolation Using Prelookup3' */
          localfractionTmp_0d = localCf_speed_for_air_FuSysM__c;
          FuSysM_factFuExgAirStall = intrp1d_iu16n16ff_u32f_l_ns
            (localCf_speed_for_air_FuSysM__j, ((Float32)localfractionTmp_0d) *
             3.051757813E-005F, (&(FuSysM_facExgAirStalltFu_T[0])));

          /* Sum: '<S110>/Sum1' incorporates:
           *  Constant: '<S110>/ConstVal_1'
           *  Sum: '<S110>/Sum5'
           */
          FuSysM_tFutAirDifStall = (2.731499939E+002F + ((Float32)
            localDataTypeConversion2)) - FuSysM_tFuPrev;

          /* Sum: '<S110>/Sum11' incorporates:
           *  Constant: '<S110>/ConstVal'
           *  Sum: '<S110>/Sum12'
           */
          FuSysM_tFutWaDifStall = (2.731499939E+002F + ((Float32)
            localDataTypeConversion1_m)) - FuSysM_tFuPrev;

          /* Product: '<S123>/Divide' */
          FuSysM_tFuExgWaStallCor = FuSysM_tFutWaDifStall * localDivide_b;

          /* Product: '<S122>/Divide' */
          FuSysM_tFuExgAirStallCor = FuSysM_tFutAirDifStall *
            FuSysM_factFuExgAirStall;

          /* Sum: '<S110>/Sum2' */
          localDivide_b = (FuSysM_tFuPrev + FuSysM_tFuExgWaStallCor) +
            FuSysM_tFuExgAirStallCor;
        }
      }
    }

    /* SignalConversion: '<S35>/Signal Conversion1' */
    FuSysM_tFuFineRsl = localDivide_b;

    /* SignalConversion: '<S35>/Signal Conversion2' */
    FuSysM_tFuUsPmpFineRsl = localMerge_l;

    /* DataTypeConversion: '<S38>/OutDTConv' incorporates:
     *  Constant: '<S38>/offset'
     *  Constant: '<S38>/offset1'
     *  Constant: '<S38>/one_on_slope'
     *  Product: '<S38>/Product4'
     *  Sum: '<S38>/Add1'
     *  Sum: '<S38>/Add2'
     */
    localDivide_b = (localDivide_b - 233.0F) + 0.5F;
    if (localDivide_b < 65536.0F) {
      if (localDivide_b >= 0.0F) {
        tFuM_B.OutDTConv_b = (UInt16)localDivide_b;
      } else {
        tFuM_B.OutDTConv_b = 0U;
      }
    } else {
      tFuM_B.OutDTConv_b = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S39>/OutDTConv' incorporates:
     *  Constant: '<S39>/offset'
     *  Constant: '<S39>/offset1'
     *  Constant: '<S39>/one_on_slope'
     *  Product: '<S39>/Product4'
     *  Sum: '<S39>/Add1'
     *  Sum: '<S39>/Add2'
     */
    localDivide_b = (localMerge_l - 233.0F) + 0.5F;
    if (localDivide_b < 256.0F) {
      if (localDivide_b >= 0.0F) {
        tFuM_B.OutDTConv_c = (UInt8)localDivide_b;
      } else {
        tFuM_B.OutDTConv_c = 0U;
      }
    } else {
      tFuM_B.OutDTConv_c = MAX_uint8_T;
    }

    /* S-Function "vems_vidSET" Block: <S35>/VEMS_vidSET */
    VEMS_vidSET(FuSysM_tFu, tFuM_B.OutDTConv_b);

    /* S-Function "vems_vidSET" Block: <S35>/VEMS_vidSET1 */
    VEMS_vidSET(FuSysM_tFuUsPmp, tFuM_B.OutDTConv_c);
  }

  /* end of Outputs for SubSystem: '<S24>/F02_Sdl_Calc_fuel_temp' */
}

/* Start for exported function: FuSysM_SdlSlow_tFuM */
void FuSysM_SdlSlow_tFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S5>/tFuM_fc_demux_2'
   */

  /* Start for S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S6>/F02_Calc_tEng'
   *  Start for SubSystem: '<S7>/F02_Sdl_Calc_fuel_temp'
   */
}

/* Output and update for exported function: FuSysM_SdlSlow_tFuM */
void FuSysM_SdlSlow_tFuM(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S5>/tFuM_fc_demux_2'
   */

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  SubSystem: '<S6>/F02_Calc_tEng'
   *  SubSystem: '<S7>/F02_Sdl_Calc_fuel_temp'
   */
  tFuM_F02_Calc_tEng();
  tFuM_F02_Sdl_Calc_fuel_temp();
}

/* Output and update for function-call system: '<S7>/F03_save_fuel_temp_EEPROM' */
void tFuM_F03_save_fuel_temp_EEPROM(void)
{
  /* Outputs for enable SubSystem: '<S25>/F03_save_fuel_temp_EEPROM' incorporates:
   *  Constant: '<S25>/ConstVal'
   *  Constant: '<S25>/TFUM_u8Inhib'
   *  EnablePort: '<S124>/Enable'
   *  RelationalOperator: '<S25>/Relational Operator'
   */
  if (TFUM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S124>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_tFuUsPmp, tFuM_B.VEMS_vidGET2_e);

    /* NVRAM Write for EBDT Block <S124>/EepromWriteAccess */
    VEMS_vidSET(FuSysM_tFuUsPmp_NV, tFuM_B.VEMS_vidGET2_e);

    /* S-Function "vems_vidGET" Block: <S124>/VEMS_vidGET1 */
    VEMS_vidGET(FuSysM_tFu, tFuM_B.VEMS_vidGET1_a);

    /* NVRAM Write for EBDT Block <S124>/EepromWriteAccess1 */
    VEMS_vidSET(FuSysM_tFu_NV, tFuM_B.VEMS_vidGET1_a);

    /* S-Function "vems_vidGET" Block: <S124>/VEMS_vidGET */
    VEMS_vidGET(EOM_tiEngStop, tFuM_B.VEMS_vidGET_d);

    /* NVRAM Write for EBDT Block <S124>/EepromWriteAccess2 */
    VEMS_vidSET(FuSysM_tiEngStopPwrl, tFuM_B.VEMS_vidGET_d);
  }

  /* end of Outputs for SubSystem: '<S25>/F03_save_fuel_temp_EEPROM' */
}

/* Output and update for exported function: FuSysM_EvePwrl_tFuM */
void FuSysM_EvePwrl_tFuM(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S7>/F03_save_fuel_temp_EEPROM'
   */
  tFuM_F03_save_fuel_temp_EEPROM();
}

/* Output and update for function-call system: '<S7>/F01_Init_fuel_temp' */
void tFuM_F01_Init_fuel_temp(void)
{
  SInt32 localDTConv_UFix_To_Single_1;
  Float32 localDTConv_UFix_To_Single_3;
  Float32 localDTConv_UFix_To_Single_4;
  SInt32 localDTConv_UFix_To_Single_5;
  Float32 localSwitch_o;
  Float32 localAdd2_d;
  UInt16 localfractionTmp_0d;
  Float32 localfrac[2];
  UInt32 localExt_tCoMes_NV_FuSysM_tCoMe;
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  UInt16 localExt_tCoMes_NV_FuSysM_tCo_j;
  UInt16 localFuSysM_tiEcuStop_FuSysM__k;
  UInt8 locallocalDTConv_UFix_To_Single;
  UInt32 localqY;

  /* Outputs for enable SubSystem: '<S23>/F01_Init_fuel_temp' incorporates:
   *  Constant: '<S23>/ConstVal'
   *  Constant: '<S23>/TFUM_u8Inhib'
   *  EnablePort: '<S27>/Enable'
   *  RelationalOperator: '<S23>/Relational Operator'
   */
  if (TFUM_u8Inhib != 90) {
    /* Constant: '<S27>/ConstVal_2' */
    FuSysM_bAcvTFuInit = FALSE;

    /* NVRAM Read for EBDT Block <S27>/EepromReadAccess3 */
    VEMS_vidGET(FuSysM_tFuUsPmp_NV, tFuM_B.EepromReadAccess3);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_1' */
    localDTConv_UFix_To_Single_1 = tFuM_B.EepromReadAccess3 + 233;

    /* NVRAM Read for EBDT Block <S27>/EepromReadAccess */
    VEMS_vidGET(Ext_tCoMes_NV, tFuM_B.EepromReadAccess);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_2' */
    localDTConv_UFix_To_Single_5 = tFuM_B.EepromReadAccess + 40;
    if (localDTConv_UFix_To_Single_5 <= 0) {
      locallocalDTConv_UFix_To_Single = 0U;
    } else if (localDTConv_UFix_To_Single_5 > 255) {
      locallocalDTConv_UFix_To_Single = MAX_uint8_T;
    } else {
      locallocalDTConv_UFix_To_Single = (UInt8)localDTConv_UFix_To_Single_5;
    }

    /* NVRAM Read for EBDT Block <S27>/EepromReadAccess2 */
    VEMS_vidGET(FuSysM_tFu_NV, tFuM_B.EepromReadAccess2);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_3' */
    localDTConv_UFix_To_Single_3 = ((Float32)tFuM_B.EepromReadAccess2) + 233.0F;

    /* S-Function "vems_vidGET" Block: <S27>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_tCoMes, tFuM_B.VEMS_vidGET1);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_4' */
    localDTConv_UFix_To_Single_4 = (Float32)tFuM_B.VEMS_vidGET1;

    /* S-Function "vems_vidGET" Block: <S27>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_tFuRailMes, tFuM_B.VEMS_vidGET2);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_5' */
    localDTConv_UFix_To_Single_5 = tFuM_B.VEMS_vidGET2;

    /* S-Function "vems_vidGET" Block: <S27>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tFuUsPmpMes, tFuM_B.VEMS_vidGET3);

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_6' */
    localSwitch_o = (Float32)tFuM_B.VEMS_vidGET3;

    /* DataTypeConversion: '<S27>/DTConv_UFix_To_Single_7' */
    localAdd2_d = (Float32)tFuM_B.EepromReadAccess;

    /* NVRAM Read for EBDT Block <S27>/EepromReadAccess1 */
    VEMS_vidGET(FuSysM_tiEngStopPwrl, tFuM_B.EepromReadAccess1);

    /* PreLookup: '<S30>/Prelookup' */
    localExt_tCoMes_NV_FuSysM_tCoMe = plook_u32u8u16n15_binc_n
      (locallocalDTConv_UFix_To_Single, (&(FuSysM_tCoMes_A[0])), 8U,
       &localExt_tCoMes_NV_FuSysM_tCo_j);

    /* S-Function "vems_vidGET" Block: <S27>/VEMS_vidGET */
    VEMS_vidGET(EOM_tiEngStop, tFuM_B.VEMS_vidGET);

    /* Sum: '<S27>/Sum4' */
    localqY = tFuM_B.VEMS_vidGET - tFuM_B.EepromReadAccess1;
    if (localqY > tFuM_B.VEMS_vidGET) {
      localqY = 0U;
    }

    FuSysM_tiEcuStop = localqY;

    /* PreLookup: '<S31>/Prelookup' */
    localqY = plook_u32u32u16n15_binc_n(FuSysM_tiEcuStop, (&(FuSysM_tiEngStop_A
      [0])), 8U, &localFuSysM_tiEcuStop_FuSysM__k);

    /* Interpolation_n-D: '<S28>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_tCoMes_NV_FuSysM_tCo_j;
    localfrac[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localfractionTmp_0d = localFuSysM_tiEcuStop_FuSysM__k;
    localfrac[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localbpIndex[0] = localExt_tCoMes_NV_FuSysM_tCoMe;
    localbpIndex[1] = localqY;
    FuSysM_rCorTFuIni = intrp2d_iu8n7ff_u32f_l_ns__1(localbpIndex, localfrac,
      (&(FuSysM_rCorTFuIni_M[0])), 9U);

    /* Interpolation_n-D: '<S29>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_tCoMes_NV_FuSysM_tCo_j;
    localfrac_0[0] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localfractionTmp_0d = localFuSysM_tiEcuStop_FuSysM__k;
    localfrac_0[1] = ((Float32)localfractionTmp_0d) * 3.051757813E-005F;
    localbpIndex_0[0] = localExt_tCoMes_NV_FuSysM_tCoMe;
    localbpIndex_0[1] = localqY;
    FuSysM_rCorTFuUsPmpIni = intrp2d_iu8n7ff_u32f_l_ns__1(localbpIndex_0,
      localfrac_0, (&(FuSysM_rCorTFuUsPmpIni_M[0])), 9U);

    /* Sum: '<S27>/Sum12' incorporates:
     *  Constant: '<S27>/ConstVal_3'
     */
    localDTConv_UFix_To_Single_4 += 2.731499939E+002F;

    /* Sum: '<S27>/Sum1' incorporates:
     *  Constant: '<S27>/ConstVal'
     */
    localAdd2_d += 2.731499939E+002F;

    /* Sum: '<S27>/Sum5' incorporates:
     *  Product: '<S34>/Divide'
     *  Sum: '<S27>/Sum8'
     */
    localfrac[0] = ((((Float32)localDTConv_UFix_To_Single_1) - localAdd2_d) *
                    FuSysM_rCorTFuUsPmpIni) + localDTConv_UFix_To_Single_4;
    localfrac[1] = ((localDTConv_UFix_To_Single_3 - localAdd2_d) *
                    FuSysM_rCorTFuIni) + localDTConv_UFix_To_Single_4;

    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/ConstVal_4'
     *  Constant: '<S27>/Ext_bTSen_tFuUsPmp_SC'
     *  Inport: '<Root>/FRM_bInhMes_tFuUsPmp'
     *  Logic: '<S27>/Logical Operator2'
     *  Logic: '<S27>/Logical Operator3'
     *  Sum: '<S27>/Sum3'
     */
    if ((!GDGAR_bGetFRM(FRM_FRM_INHMES_TFUUSPMP)) && Ext_bTSen_tFuUsPmp_SC) {
      localAdd2_d = 2.731499939E+002F + localSwitch_o;
    } else {
      localAdd2_d = localfrac[0];
    }

    /* SignalConversion: '<S27>/Signal Conversion1' */
    FuSysM_tFuUsPmpFineRsl = localAdd2_d;

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/ConstVal_1'
     *  Constant: '<S27>/Ext_bTSen_tFuRail_SC'
     *  Inport: '<Root>/FRM_bInhMes_tFuRail'
     *  Logic: '<S27>/Logical Operator'
     *  Logic: '<S27>/Logical Operator1'
     *  Sum: '<S27>/Sum2'
     */
    if ((!GDGAR_bGetFRM(FRM_FRM_INHMES_TFURAIL)) && Ext_bTSen_tFuRail_SC) {
      localSwitch_o = 2.731499939E+002F + ((Float32)
        localDTConv_UFix_To_Single_5);
    } else {
      localSwitch_o = localfrac[1];
    }

    /* SignalConversion: '<S27>/Signal Conversion2' */
    FuSysM_tFuFineRsl = localSwitch_o;

    /* DataTypeConversion: '<S32>/OutDTConv' incorporates:
     *  Constant: '<S32>/offset'
     *  Constant: '<S32>/offset1'
     *  Constant: '<S32>/one_on_slope'
     *  Product: '<S32>/Product4'
     *  Sum: '<S32>/Add1'
     *  Sum: '<S32>/Add2'
     */
    localDTConv_UFix_To_Single_3 = (localAdd2_d - 233.0F) + 0.5F;
    if (localDTConv_UFix_To_Single_3 < 256.0F) {
      if (localDTConv_UFix_To_Single_3 >= 0.0F) {
        tFuM_B.OutDTConv_d = (UInt8)localDTConv_UFix_To_Single_3;
      } else {
        tFuM_B.OutDTConv_d = 0U;
      }
    } else {
      tFuM_B.OutDTConv_d = MAX_uint8_T;
    }

    /* DataTypeConversion: '<S33>/OutDTConv' incorporates:
     *  Constant: '<S33>/offset'
     *  Constant: '<S33>/offset1'
     *  Constant: '<S33>/one_on_slope'
     *  Product: '<S33>/Product4'
     *  Sum: '<S33>/Add1'
     *  Sum: '<S33>/Add2'
     */
    localDTConv_UFix_To_Single_3 = (localSwitch_o - 233.0F) + 0.5F;
    if (localDTConv_UFix_To_Single_3 < 65536.0F) {
      if (localDTConv_UFix_To_Single_3 >= 0.0F) {
        tFuM_B.OutDTConv = (UInt16)localDTConv_UFix_To_Single_3;
      } else {
        tFuM_B.OutDTConv = 0U;
      }
    } else {
      tFuM_B.OutDTConv = MAX_uint16_T;
    }

    /* S-Function "vems_vidSET" Block: <S27>/VEMS_vidSET */
    VEMS_vidSET(FuSysM_tFu, tFuM_B.OutDTConv);

    /* S-Function "vems_vidSET" Block: <S27>/VEMS_vidSET1 */
    VEMS_vidSET(FuSysM_tFuUsPmp, tFuM_B.OutDTConv_d);
  }

  /* end of Outputs for SubSystem: '<S23>/F01_Init_fuel_temp' */
}

/* Start for exported function: FuSysM_EveRxn552_tFuM */
void FuSysM_EveRxn552_tFuM_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for Stateflow: '<S26>/Chart'
   */
}

/* Output and update for exported function: FuSysM_EveRxn552_tFuM */
void FuSysM_EveRxn552_tFuM(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Stateflow: '<S26>/Chart'
   */

  /* Stateflow: '<S26>/Chart' incorporates:
   *  SubSystem: '<S7>/F01_Init_fuel_temp'
   */
  /* Gateway: tFuM/F02_Calc_fuel_temp/Function_Call_Generator_with_condition1/Chart */
  /* During: tFuM/F02_Calc_fuel_temp/Function_Call_Generator_with_condition1/Chart */
  if (((SInt32)FuSysM_bAcvTFuInit) == 1) {
    /* Transition: '<S125>:1' */
    /* Event: '<S125>:5' */
    tFuM_F01_Init_fuel_temp();
  }
}

/* Model initialize function */
void tFuM_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  FuSysM_EveRst_tFuM_Start();
  FuSysM_SdlSlow_tFuM_Start();
  FuSysM_EveRxn552_tFuM_Start();
}

#define TFUM_STOP_SEC_CODE
#include "tFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
