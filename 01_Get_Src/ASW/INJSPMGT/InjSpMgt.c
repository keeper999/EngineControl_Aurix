/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSpMgt                                                */
/* !Description     : INJECTION PARAMETERS MANAGER                            */
/*                                                                            */
/* !Module          : InjSpMgt                                                */
/*                                                                            */
/* !File            : InjSpMgt.c                                              */
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
/* !Reference       : PTS_DOC_5056002 / 04                                    */
/* !OtherRefs       : VEMS V02 ECU#065202                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Mar 07 15:35:56 2013                              */
/*   Model name       : InjSpMgt_AUTOCODE.mdl                                 */
/*   Model version    : 1.1004                                                */
/*   Root subsystem   : /InjSpMgt                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/InjSpMgt/5-SOFT-LIV/InjSpMgt$*/
/* $Revision::   1.13                                                        $*/
/* $Author::   adelvare                               $$Date::   11 Mar 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjSpMgt.h"
#include "InjSpMgt_private.h"

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
#define INJSPMGT_START_SEC_VAR_UNSPECIFIED
#include "InjSpMgt_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjSpMgt InjSpMgt_B;

/* Block states (auto storage) */
D_Work_InjSpMgt InjSpMgt_DWork;

#define INJSPMGT_STOP_SEC_VAR_UNSPECIFIED
#include "InjSpMgt_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJSPMGT_START_SEC_CODE
#include "InjSpMgt_MemMap.h"

void InjSpMgt_ASYNC1(int controlPortIdx)
{
}

void InjSpMgt_ASYNC2(int controlPortIdx)
{
}

void InjSpMgt_ASYNC3(int controlPortIdx)
{
}

void InjSpMgt_ASYNC4(int controlPortIdx)
{
  InjSpMgt_F01_InjSpMgtFct();
}

void InjSpMgt_ASYNC7(int controlPortIdx)
{
  InjSpMgt_F03_InjSpMgtFct2();
}

void InjSpMgt_ASYNC9(int controlPortIdx)
{
  InjSpMg_F02_SdlEveClcn_InjSpMgt();
}

/* Output and update for function-call system: '<S1>/F00_Init' */
void InjSpMgt_F00_Init(void)
{
  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET1 */
  VEMS_vidGET(Eng_noInCyl, InjSpMgt_B.VEMS_vidGET1_i);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET */
  VEMS_vidSET(InjSys_noInCylStopSTT, InjSpMgt_B.VEMS_vidGET1_i);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET */
  VEMS_vidGET(Eng_noCmprCyl, InjSpMgt_B.VEMS_vidGET_g);

  /* SignalConversion: '<S8>/Signal Conversion2' */
  InjSys_noCmprCylStopSTT = InjSpMgt_B.VEMS_vidGET_g;
}

/* Output and update for function-call system: '<S1>/F03a_PfurailInit' */
void InjSpMgt_F03a_PfurailInit(void)
{
  Float32 localtmp;
  SInt32 localtmp_0;
  UInt8 locallocalDataTypeConversion;

  /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET */
  VEMS_vidGET(Ext_tCoMes, InjSpMgt_B.VEMS_vidGET);

  /* DataTypeConversion: '<S12>/Data Type Conversion2' */
  localtmp_0 = InjSpMgt_B.VEMS_vidGET + 40;
  if (localtmp_0 <= 0) {
    locallocalDataTypeConversion = 0U;
  } else if (localtmp_0 > 255) {
    locallocalDataTypeConversion = MAX_uint8_T;
  } else {
    locallocalDataTypeConversion = (UInt8)localtmp_0;
  }

  /* DataTypeConversion: '<S288>/OutDTConv' incorporates:
   *  Constant: '<S288>/offset'
   *  Constant: '<S288>/offset1'
   *  Constant: '<S288>/one_on_slope'
   *  Lookup_n-D: '<S287>/Lookup Table (n-D)'
   *  Product: '<S288>/Product4'
   *  Sum: '<S288>/Add1'
   *  Sum: '<S288>/Add2'
   */
  localtmp = (1.279999968E-003F * look1_iu8lftu16p9If_binlcs
              (locallocalDataTypeConversion, (&(InjSys_tCoMes_A[0])),
               (&(InjSys_pFuRailIni_T[0])), 8U)) + 0.5F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      InjSpMgt_B.OutDTConv_c = (UInt16)localtmp;
    } else {
      InjSpMgt_B.OutDTConv_c = 0U;
    }
  } else {
    InjSpMgt_B.OutDTConv_c = MAX_uint16_T;
  }

  /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET */
  VEMS_vidSET(InjSys_pFuReq, InjSpMgt_B.OutDTConv_c);
}

/* Start for exported function: InjSys_EveRst_InjSpMgt */
void InjSys_EveRst_InjSpMgt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjSpMgt_fc_demux3'
   */

  /* Start for S-Function (fcncallgen): '<S16>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S1>/F00_Init'
   *  Start for SubSystem: '<S1>/F03a_PfurailInit'
   */
}

/* Output and update for exported function: InjSys_EveRst_InjSpMgt */
void InjSys_EveRst_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjSpMgt_fc_demux3'
   */

  /* S-Function (fcncallgen): '<S16>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/F00_Init'
   *  SubSystem: '<S1>/F03a_PfurailInit'
   */
  InjSpMgt_F00_Init();
  InjSpMgt_F03a_PfurailInit();
}

/* Start for function-call system: '<S1>/F01_InjSpMgtFct' */
void InjSpMgt_F01_InjSpMgtFct_Start(void)
{
  /* Start for enable SubSystem: '<S9>/F01_InjSpMgtFct' */

  /* Start for atomic SubSystem: '<S18>/F00_InjSpIf' */

  /* Start for ifaction SubSystem: '<S19>/F01_RunCase' */

  /* InitializeConditions for UnitDelay: '<S32>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_er = TRUE;

  /* end of Start for SubSystem: '<S19>/F01_RunCase' */

  /* Start for ifaction SubSystem: '<S19>/F02_NoRunCase' */

  /* InitializeConditions for UnitDelay: '<S37>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_e3 = TRUE;

  /* end of Start for SubSystem: '<S19>/F02_NoRunCase' */

  /* end of Start for SubSystem: '<S18>/F00_InjSpIf' */

  /* Start for atomic SubSystem: '<S18>/F02_TestPha' */

  /* Start for atomic SubSystem: '<S21>/F03_agInjSp' */

  /* Start for ifaction SubSystem: '<S67>/F02_agInjSpnoSTTStop' */

  /* InitializeConditions for atomic SubSystem: '<S114>/F04_PhaInjH1' */

  /* InitializeConditions for UnitDelay: '<S126>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay = TRUE;

  /* end of InitializeConditions for SubSystem: '<S114>/F04_PhaInjH1' */

  /* end of Start for SubSystem: '<S67>/F02_agInjSpnoSTTStop' */

  /* end of Start for SubSystem: '<S21>/F03_agInjSp' */

  /* end of Start for SubSystem: '<S18>/F02_TestPha' */

  /* InitializeConditions for atomic SubSystem: '<S18>/F01_TestFrac' */

  /* InitializeConditions for atomic SubSystem: '<S20>/F01_tiInjMinDet' */

  /* InitializeConditions for UnitDelay: '<S55>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_e = TRUE;

  /* InitializeConditions for UnitDelay: '<S56>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_j = TRUE;

  /* InitializeConditions for UnitDelay: '<S57>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_k = TRUE;

  /* InitializeConditions for UnitDelay: '<S58>/UnitDelay' */
  InjSpMgt_DWork.UnitDelay_df = TRUE;

  /* end of InitializeConditions for SubSystem: '<S20>/F01_tiInjMinDet' */

  /* end of InitializeConditions for SubSystem: '<S18>/F01_TestFrac' */

  /* end of Start for SubSystem: '<S9>/F01_InjSpMgtFct' */
}

/* Output and update for function-call system: '<S1>/F01_InjSpMgtFct' */
void InjSpMgt_F01_InjSpMgtFct(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_ib;
  Boolean localRelationalOperator1_lv;
  Boolean localLogic[2];
  Boolean localRelationalOperator_dr;
  Boolean localRelationalOperator1_bq;
  Boolean localLogic_c[2];
  Boolean localRelationalOperator_bd;
  Boolean localRelationalOperator1_bg;
  Boolean localLogic_i[2];
  Boolean localUnitDelay1;
  Boolean localUnitDelay1_h;
  Boolean localUnitDelay1_d;
  Boolean localUnitDelay;
  Boolean localRelationalOperator1_gm;
  Boolean localLogic_j[2];
  Boolean localUnitDelay1_hu;
  Float32 localDTConv_UFix_To_Single_4;
  Float32 localDataTypeConversion3_m;
  Float32 localInterpolationUsingPreloo_g;
  UInt8 localSwitch3_kc;
  UInt32 localAdd_n;
  Float32 localDataTypeConversion5;
  Float32 localDataTypeConversion6;
  Float32 localInterpolationUsingPreloo_d;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_InjSys_nEng_A_1_j;
  Float32 localfractionTmp_0d_0;
  Boolean localSwitch2_i;
  Float32 localSwitch3_e;
  Boolean localSwitch2_a;
  Boolean localSwitch2_b0;
  Boolean localSwitch2_ft;
  Float32 localInterpolationUsingPreloo_a;
  UInt8 localSwitch5;
  UInt8 localSwitch6;
  UInt8 localSwitch7;
  Float32 locallocalMinMax2_o_idx;
  Float32 locallocalDataTypeConversion1_i;
  UInt16 locallocalOutDTConv;
  UInt16 locallocalOutDTConv_j;
  UInt16 locallocalOutDTConv_d;
  UInt16 locallocalOutDTConv_g;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S9>/F01_InjSpMgtFct' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S18>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET13 */
    VEMS_vidGET(IgCmd_agIgSp, InjSpMgt_B.VEMS_vidGET13_m);

    /* DataTypeConversion: '<S18>/DTConv_UFix_To_Single_4' */
    localDTConv_UFix_To_Single_4 = (((Float32)InjSpMgt_B.VEMS_vidGET13_m) *
      0.375F) - 36.0F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET28 */
    VEMS_vidGET1DArray(InjrM_prm_facGainInj, 4, InjSpMgt_B.VEMS_vidGET28);

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    InjSys_facGainInjH1 = ((Float32)InjSpMgt_B.VEMS_vidGET28[0]) * 0.015625F;

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    InjSys_facGainInjH2 = ((Float32)InjSpMgt_B.VEMS_vidGET28[1]) * 0.015625F;

    /* DataTypeConversion: '<S18>/Data Type Conversion2' */
    InjSys_facGainInjS1 = ((Float32)InjSpMgt_B.VEMS_vidGET28[2]) * 0.015625F;

    /* DataTypeConversion: '<S18>/Data Type Conversion3' */
    InjSys_facGainInjS2 = ((Float32)InjSpMgt_B.VEMS_vidGET28[3]) * 0.015625F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET29 */
    VEMS_vidGET1DArray(InjrM_prm_tiInjOfsInj, 4, InjSpMgt_B.VEMS_vidGET29);

    /* DataTypeConversion: '<S18>/Data Type Conversion4' */
    InjSys_tiInjOfsInjH1 = ((Float32)InjSpMgt_B.VEMS_vidGET29[0]) *
      3.200000037E-006F;

    /* DataTypeConversion: '<S18>/Data Type Conversion5' */
    InjSys_tiInjOfsInjH2 = ((Float32)InjSpMgt_B.VEMS_vidGET29[1]) *
      3.200000037E-006F;

    /* DataTypeConversion: '<S18>/Data Type Conversion6' */
    InjSys_tiInjOfsInjS1 = ((Float32)InjSpMgt_B.VEMS_vidGET29[2]) *
      3.200000037E-006F;

    /* DataTypeConversion: '<S18>/Data Type Conversion7' */
    InjSys_tiInjOfsInjS2 = ((Float32)InjSpMgt_B.VEMS_vidGET29[3]) *
      3.200000037E-006F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET10 */
    VEMS_vidGET(Ext_nEng, InjSpMgt_B.VEMS_vidGET10);

    /* DataTypeDuplicate Block: '<S137>/Data Type Duplicate2'
     *
     * Regarding '<S137>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET8 */
    VEMS_vidGET(Eng_stEru, InjSpMgt_B.VEMS_vidGET8_p);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET23 */
    VEMS_vidGET(InjSys_rInj1Sp, InjSpMgt_B.VEMS_vidGET23);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET25 */
    VEMS_vidGET(InjSys_rInj2Sp, InjSpMgt_B.VEMS_vidGET25);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET27 */
    VEMS_vidGET(InjSys_rInj3Sp, InjSpMgt_B.VEMS_vidGET27);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET15 */
    VEMS_vidGET(InjSys_agInj1Sp, InjSpMgt_B.VEMS_vidGET15_a);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET17 */
    VEMS_vidGET(InjSys_agInj2Sp, InjSpMgt_B.VEMS_vidGET17);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET19 */
    VEMS_vidGET(InjSys_agInj3Sp, InjSpMgt_B.VEMS_vidGET19);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET22 */
    VEMS_vidGET(InjSys_rInj1CrkSp, InjSpMgt_B.VEMS_vidGET22);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET24 */
    VEMS_vidGET(InjSys_rInj2CrkSp, InjSpMgt_B.VEMS_vidGET24);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET26 */
    VEMS_vidGET(InjSys_rInj3CrkSp, InjSpMgt_B.VEMS_vidGET26);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET14 */
    VEMS_vidGET(InjSys_agInj1CrkSp, InjSpMgt_B.VEMS_vidGET14_e);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET16 */
    VEMS_vidGET(InjSys_agInj2CrkSp, InjSpMgt_B.VEMS_vidGET16);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET18 */
    VEMS_vidGET(InjSys_agInj3CrkSp, InjSpMgt_B.VEMS_vidGET18);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET20 */
    VEMS_vidGET(InjSys_mFuCrkSp, InjSpMgt_B.VEMS_vidGET20);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET21 */
    VEMS_vidGET1DArray(InjSys_prm_mFuSpCyl, 6, InjSpMgt_B.VEMS_vidGET21);

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
     *
     * Regarding '<S28>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET6 */
    VEMS_vidGET(Eng_noInNxtCyl, InjSpMgt_B.VEMS_vidGET6_h);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET7 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, InjSpMgt_B.VEMS_vidGET7_d);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(EngM_prm_mAirPredInCyl, 6, InjSpMgt_B.VEMS_vidGET3_l);

    /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate'
     *
     * Regarding '<S29>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET9 */
    VEMS_vidGET(Ext_agCkPosnCurRef2, InjSpMgt_B.VEMS_vidGET9_k);

    /* DataTypeDuplicate Block: '<S162>/Data Type Duplicate1'
     *
     * Regarding '<S162>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S162>/Data Type Duplicate2'
     *
     * Regarding '<S162>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S164>/FixPt Data Type Propagation'
     *
     * Regarding '<S164>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S166>/Force any float to Double everything else to uint8'
     *
     * Regarding '<S166>/Force any float to Double everything else to uint8':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S166>/Force any float to Single everything else to uint8'
     *
     * Regarding '<S166>/Force any float to Single everything else to uint8':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S164>/FixPt Gateway Out'
     *
     * Regarding '<S164>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* Outputs for atomic SubSystem: '<S18>/F04_AcvFctClcn' */

    /* Logic: '<S23>/Logical Operator' incorporates:
     *  Constant: '<S23>/Constant2'
     *  Constant: '<S23>/Ext_noCylEng_SC'
     *  Constant: '<S23>/InjSys_agCkPosEveInj_SC'
     *  DataTypeConversion: '<S23>/Data Type Conversion2'
     *  Math: '<S162>/Math Function'
     *  Product: '<S163>/Divide'
     *  RelationalOperator: '<S23>/Relational Operator'
     */
    localtmp = Ext_noCylEng_SC;
    localExt_nEng_InjSys_nEng_A_1_j = (((UInt32)localtmp) == ((UInt32)0)) ?
      MAX_uint32_T : (5760U / ((UInt32)localtmp));
    if (localExt_nEng_InjSys_nEng_A_1_j > 65535U) {
      locallocalOutDTConv = MAX_uint16_T;
    } else {
      locallocalOutDTConv = (UInt16)localExt_nEng_InjSys_nEng_A_1_j;
    }

    localExt_nEng_InjSys_nEng_A_1_j = ((((UInt32)locallocalOutDTConv) * 43691U)
      >> 15);
    if (localExt_nEng_InjSys_nEng_A_1_j > 65535U) {
      locallocalOutDTConv = MAX_uint16_T;
    } else {
      locallocalOutDTConv = (UInt16)localExt_nEng_InjSys_nEng_A_1_j;
    }

    localExt_nEng_InjSys_nEng_A_1_j = ((((UInt32)InjSys_agCkPosEveInj_SC) *
      43691U) >> 12);
    if (localExt_nEng_InjSys_nEng_A_1_j > 65535U) {
      locallocalOutDTConv_j = MAX_uint16_T;
    } else {
      locallocalOutDTConv_j = (UInt16)localExt_nEng_InjSys_nEng_A_1_j;
    }

    InjSys_bDetCylInjSp = !(rt_mod_uint16(InjSpMgt_B.VEMS_vidGET9_k,
      locallocalOutDTConv) > locallocalOutDTConv_j);

    /* end of Outputs for SubSystem: '<S18>/F04_AcvFctClcn' */

    /* Outputs for atomic SubSystem: '<S18>/F00_InjSpIf' */

    /* If: '<S19>/If1' incorporates:
     *  ActionPort: '<S24>/Action Port'
     *  ActionPort: '<S25>/Action Port'
     *  Constant: '<S19>/Ext_stRun_SC'
     *  RelationalOperator: '<S19>/Relational Operator2'
     *  SubSystem: '<S19>/F01_RunCase'
     *  SubSystem: '<S19>/F02_NoRunCase'
     */
    if (InjSpMgt_B.VEMS_vidGET8_p == Ext_stRun_SC) {
      /* DataTypeConversion: '<S24>/Data Type Conversion4' */
      InjSys_rInjH1Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET23) *
        3.051757813E-005F;

      /* DataTypeConversion: '<S24>/Data Type Conversion1' */
      localDataTypeConversion5 = ((Float32)InjSpMgt_B.VEMS_vidGET17) * 0.09375F;

      /* DataTypeConversion: '<S24>/Data Type Conversion3' */
      localDataTypeConversion3_m = ((Float32)InjSpMgt_B.VEMS_vidGET25) *
        3.051757813E-005F;

      /* PreLookup: '<S31>/Prelookup' */
      localExt_nEng_InjSys_nEng_A_1_j = plook_u32u16f_binc
        (InjSpMgt_B.VEMS_vidGET10, (&(InjSys_nEng_A[0])), 15U,
         &localInterpolationUsingPreloo_g);

      /* Interpolation_n-D: '<S26>/Interpolation Using Prelookup3' */
      localfractionTmp_0d_0 = localInterpolationUsingPreloo_g;
      localfractionTmp_0d = intrp1d_iu16n4ff_u32f_l_ns
        (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d_0,
         (&(InjSys_agBegInjH2HiThd_T[0])));

      /* Interpolation_n-D: '<S27>/Interpolation Using Prelookup3' */
      localDataTypeConversion6 = localInterpolationUsingPreloo_g;
      localInterpolationUsingPreloo_g = intrp1d_iu16n4ff_u32f_l_ns
        (localExt_nEng_InjSys_nEng_A_1_j, localDataTypeConversion6,
         (&(InjSys_agBegInjH2LoThd_T[0])));

      /* RelationalOperator: '<S30>/Relational Operator' */
      localRelationalOperator_bd = ((((Float32)InjSpMgt_B.VEMS_vidGET17) *
        0.09375F) >= localfractionTmp_0d);

      /* RelationalOperator: '<S30>/Relational Operator1' */
      localRelationalOperator1_bg = ((((Float32)InjSpMgt_B.VEMS_vidGET17) *
        0.09375F) <= localInterpolationUsingPreloo_g);

      /* UnitDelay: '<S32>/UnitDelay' */
      localUnitDelay1_d = InjSpMgt_DWork.UnitDelay_er;

      /* CombinatorialLogic: '<S32>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_bd != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_bg != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_d != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_i[0] = InjSpMgt_ConstP.pooled26[rowidx];
        localLogic_i[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
      }

      /* UnitDelay: '<S32>/UnitDelay1' */
      localUnitDelay1_d = InjSpMgt_DWork.UnitDelay_n;

      /* Switch: '<S32>/Switch2' incorporates:
       *  Constant: '<S32>/NotCLR3'
       */
      if (localUnitDelay1_d) {
        localSwitch2_i = localLogic_i[0];
      } else {
        localSwitch2_i = TRUE;
      }

      /* SignalConversion: '<S24>/Signal Conversion' */
      InjSys_agBegInjH2Tmp = localDataTypeConversion5;

      /* SignalConversion: '<S24>/Signal Conversion1' */
      InjSys_agBegInjS1Tmp = localDataTypeConversion5;

      /* Switch: '<S24>/Switch1' incorporates:
       *  Constant: '<S24>/Constant1'
       */
      if (localSwitch2_i) {
        InjSys_rInjH2Tmp = localDataTypeConversion3_m;
      } else {
        InjSys_rInjH2Tmp = 0.0F;
      }

      /* Switch: '<S24>/Switch2' incorporates:
       *  Constant: '<S24>/Constant'
       */
      if (localSwitch2_i) {
        InjSys_rInjS1Tmp = 0.0F;
      } else {
        InjSys_rInjS1Tmp = localDataTypeConversion3_m;
      }

      /* DataTypeConversion: '<S24>/Data Type Conversion5' */
      InjSys_rInjS2Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET27) *
        3.051757813E-005F;

      /* DataTypeConversion: '<S24>/Data Type Conversion6' */
      InjSys_agBegInjH1Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET15_a) * 0.09375F;

      /* DataTypeConversion: '<S24>/Data Type Conversion7' */
      InjSys_agEndInjS2Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET19) * 0.09375F;

      /* Switch: '<S24>/Switch3' */
      if (InjSys_bDetCylInjSp) {
        localSwitch3_kc = InjSpMgt_B.VEMS_vidGET6_h;
      } else {
        localSwitch3_kc = InjSpMgt_B.VEMS_vidGET7_d;
      }

      /* DataTypeConversion: '<S24>/Data Type Conversion8' */
      localExt_nEng_InjSys_nEng_A_1_j = localSwitch3_kc;

      /* Sum: '<S28>/Add' incorporates:
       *  Constant: '<S28>/Constant1'
       */
      localAdd_n = localExt_nEng_InjSys_nEng_A_1_j - 1U;

      /* DataTypeConversion: '<S24>/Data Type Conversion2' incorporates:
       *  Constant: '<S28>/Constant'
       *  MinMax: '<S28>/MinMax'
       *  Selector: '<S28>/Selector'
       */
      InjSys_mFuSpMgt = ((Float32)InjSpMgt_B.VEMS_vidGET21[rt_MIN(localAdd_n,
        5U)]) * 7.450580597E-009F;

      /* Sum: '<S29>/Add' incorporates:
       *  Constant: '<S29>/Constant1'
       */
      localExt_nEng_InjSys_nEng_A_1_j--;

      /* SignalConversion: '<S24>/Signal Conversion3' incorporates:
       *  Constant: '<S29>/Constant'
       *  MinMax: '<S29>/MinMax'
       *  Selector: '<S29>/Selector'
       */
      InjSys_mAirSpMgt = InjSpMgt_B.VEMS_vidGET3_l[rt_MIN
        (localExt_nEng_InjSys_nEng_A_1_j, 5U)];

      /* Update for UnitDelay: '<S32>/UnitDelay' */
      InjSpMgt_DWork.UnitDelay_er = localSwitch2_i;

      /* Update for UnitDelay: '<S32>/UnitDelay1' incorporates:
       *  Constant: '<S32>/NotCLR2'
       */
      InjSpMgt_DWork.UnitDelay_n = TRUE;
    } else {
      /* DataTypeConversion: '<S25>/Data Type Conversion' */
      InjSys_rInjH1Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET22) *
        3.051757813E-005F;

      /* DataTypeConversion: '<S25>/Data Type Conversion5' */
      localDataTypeConversion5 = ((Float32)InjSpMgt_B.VEMS_vidGET24) *
        3.051757813E-005F;

      /* DataTypeConversion: '<S25>/Data Type Conversion6' */
      localDataTypeConversion6 = ((Float32)InjSpMgt_B.VEMS_vidGET16) * 0.09375F;

      /* PreLookup: '<S36>/Prelookup' */
      localExt_nEng_InjSys_nEng_A_1_j = plook_u32u16f_lincp
        (InjSpMgt_B.VEMS_vidGET10, (&(InjSys_nEng_A[0])), 15U,
         &localInterpolationUsingPreloo_d, &InjSpMgt_DWork.Prelookup_DWORK1_e);

      /* Interpolation_n-D: '<S33>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPreloo_d;
      localfractionTmp_0d = intrp1d_iu16n4ff_u32f_l_ns
        (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d,
         (&(InjSys_agBegInjH2HiThd_T[0])));

      /* Interpolation_n-D: '<S34>/Interpolation Using Prelookup3' */
      localfractionTmp_0d_0 = localInterpolationUsingPreloo_d;
      localInterpolationUsingPreloo_d = intrp1d_iu16n4ff_u32f_l_ns
        (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d_0,
         (&(InjSys_agBegInjH2LoThd_T[0])));

      /* RelationalOperator: '<S35>/Relational Operator' */
      localRelationalOperator_dr = ((((Float32)InjSpMgt_B.VEMS_vidGET16) *
        0.09375F) >= localfractionTmp_0d);

      /* RelationalOperator: '<S35>/Relational Operator1' */
      localRelationalOperator1_bq = ((((Float32)InjSpMgt_B.VEMS_vidGET16) *
        0.09375F) <= localInterpolationUsingPreloo_d);

      /* UnitDelay: '<S37>/UnitDelay' */
      localUnitDelay1_h = InjSpMgt_DWork.UnitDelay_e3;

      /* CombinatorialLogic: '<S37>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_dr != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_bq != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_h != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_c[0] = InjSpMgt_ConstP.pooled26[rowidx];
        localLogic_c[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
      }

      /* UnitDelay: '<S37>/UnitDelay1' */
      localUnitDelay1_h = InjSpMgt_DWork.UnitDelay_h;

      /* Switch: '<S37>/Switch2' incorporates:
       *  Constant: '<S37>/NotCLR3'
       */
      if (localUnitDelay1_h) {
        localSwitch2_i = localLogic_c[0];
      } else {
        localSwitch2_i = TRUE;
      }

      /* SignalConversion: '<S25>/Signal Conversion' */
      InjSys_agBegInjH2Tmp = localDataTypeConversion6;

      /* SignalConversion: '<S25>/Signal Conversion1' */
      InjSys_agBegInjS1Tmp = localDataTypeConversion6;

      /* Switch: '<S25>/Switch1' incorporates:
       *  Constant: '<S25>/Constant1'
       */
      if (localSwitch2_i) {
        InjSys_rInjH2Tmp = localDataTypeConversion5;
      } else {
        InjSys_rInjH2Tmp = 0.0F;
      }

      /* Switch: '<S25>/Switch2' incorporates:
       *  Constant: '<S25>/Constant'
       */
      if (localSwitch2_i) {
        InjSys_rInjS1Tmp = 0.0F;
      } else {
        InjSys_rInjS1Tmp = localDataTypeConversion5;
      }

      /* DataTypeConversion: '<S25>/Data Type Conversion1' */
      InjSys_rInjS2Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET26) *
        3.051757813E-005F;

      /* DataTypeConversion: '<S25>/Data Type Conversion2' */
      InjSys_agBegInjH1Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET14_e) * 0.09375F;

      /* DataTypeConversion: '<S25>/Data Type Conversion3' */
      InjSys_agEndInjS2Tmp = ((Float32)InjSpMgt_B.VEMS_vidGET18) * 0.09375F;

      /* DataTypeConversion: '<S25>/Data Type Conversion8' */
      InjSys_mFuSpMgt = ((Float32)InjSpMgt_B.VEMS_vidGET20) * 7.450580597E-009F;

      /* SignalConversion: '<S25>/Signal Conversion3' incorporates:
       *  Constant: '<S25>/InjSys_mAirCrkSpRef_C'
       */
      InjSys_mAirSpMgt = InjSys_mAirCrkSpRef_C;

      /* Update for UnitDelay: '<S37>/UnitDelay' */
      InjSpMgt_DWork.UnitDelay_e3 = localSwitch2_i;

      /* Update for UnitDelay: '<S37>/UnitDelay1' incorporates:
       *  Constant: '<S37>/NotCLR2'
       */
      InjSpMgt_DWork.UnitDelay_h = TRUE;
    }

    /* end of Outputs for SubSystem: '<S18>/F00_InjSpIf' */
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET11 */
    VEMS_vidGET(Ext_pFuRailMes, InjSpMgt_B.VEMS_vidGET11);

    /* DataTypeDuplicate Block: '<S124>/Data Type Duplicate2'
     *
     * Regarding '<S124>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S134>/Data Type Duplicate2'
     *
     * Regarding '<S134>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S18>/F01_TestFrac' */

    /* Outputs for atomic SubSystem: '<S20>/F01_tiInjMinDet' */

    /* PreLookup: '<S46>/Prelookup' */
    localExt_nEng_InjSys_nEng_A_1_j = plook_u32u16f_lincp
      (InjSpMgt_B.VEMS_vidGET11, (&(InjSys_pFuRailMes_A[0])), 15U,
       &localSwitch3_e, &InjSpMgt_DWork.Prelookup_DWORK1_o);

    /* Interpolation_n-D: '<S40>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localSwitch3_e;
    InjSys_tiInjMinLoThd = intrp1d_iu16n19ff_u32f_l_ns
      (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d,
       (&(InjSys_tiInjMinLoThd_T[0])));

    /* Interpolation_n-D: '<S41>/Interpolation Using Prelookup3' */
    localfractionTmp_0d_0 = localSwitch3_e;
    localSwitch3_e = intrp1d_iu16n19ff_u32f_l_ns(localExt_nEng_InjSys_nEng_A_1_j,
      localfractionTmp_0d_0, (&(InjSys_tiInjMinHys_T[0])));

    /* Sum: '<S38>/Add' */
    InjSys_tiInjMinHiThd = InjSys_tiInjMinLoThd + localSwitch3_e;

    /* Product: '<S51>/Divide' */
    localSwitch3_e = InjSys_rInjH1Tmp * InjSys_mFuSpMgt;

    /* Product: '<S49>/Divide' */
    localfractionTmp_0d = InjSys_facGainInjH1 * localSwitch3_e;

    /* RelationalOperator: '<S38>/Relational Operator' incorporates:
     *  Constant: '<S38>/Constant5'
     */
    localSwitch2_i = (localSwitch3_e > 0.0F);

    /* Switch: '<S38>/Switch3' incorporates:
     *  Constant: '<S38>/Constant'
     *  Sum: '<S38>/Sum4'
     */
    if (localSwitch2_i) {
      localSwitch3_e = InjSys_tiInjOfsInjH1 + localfractionTmp_0d;
    } else {
      localSwitch3_e = 0.0F;
    }

    /* RelationalOperator: '<S42>/Relational Operator' */
    localUnitDelay = (InjSys_tiInjMinLoThd >= localSwitch3_e);

    /* RelationalOperator: '<S42>/Relational Operator1' */
    localRelationalOperator1_gm = (localSwitch3_e >= InjSys_tiInjMinHiThd);

    /* UnitDelay: '<S55>/UnitDelay' */
    localUnitDelay1_hu = InjSpMgt_DWork.UnitDelay_e;

    /* CombinatorialLogic: '<S55>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_gm != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_hu != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_j[0] = InjSpMgt_ConstP.pooled26[rowidx];
      localLogic_j[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
    }

    /* UnitDelay: '<S55>/UnitDelay1' */
    localUnitDelay1_hu = InjSpMgt_DWork.UnitDelay_g;

    /* Switch: '<S55>/Switch2' incorporates:
     *  Constant: '<S55>/NotCLR3'
     */
    if (localUnitDelay1_hu) {
      localSwitch2_i = localLogic_j[0];
    } else {
      localSwitch2_i = TRUE;
    }

    /* Product: '<S47>/Divide' */
    localDataTypeConversion6 = InjSys_rInjH2Tmp * InjSys_mFuSpMgt;

    /* Switch: '<S38>/Switch15' incorporates:
     *  Constant: '<S38>/Constant16'
     *  Constant: '<S38>/Constant19'
     *  Product: '<S48>/Divide'
     *  RelationalOperator: '<S38>/Relational Operator4'
     *  Sum: '<S38>/Sum1'
     */
    if (localDataTypeConversion6 > 0.0F) {
      localDataTypeConversion6 = (InjSys_facGainInjH2 * localDataTypeConversion6)
        + InjSys_tiInjOfsInjH2;
    } else {
      localDataTypeConversion6 = 0.0F;
    }

    /* RelationalOperator: '<S43>/Relational Operator' */
    localUnitDelay1_hu = (InjSys_tiInjMinLoThd >= localDataTypeConversion6);

    /* RelationalOperator: '<S43>/Relational Operator1' */
    localRelationalOperator1_gm = (localDataTypeConversion6 >=
      InjSys_tiInjMinHiThd);

    /* UnitDelay: '<S56>/UnitDelay' */
    localUnitDelay = InjSpMgt_DWork.UnitDelay_j;

    /* CombinatorialLogic: '<S56>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_hu != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_gm != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_j[0] = InjSpMgt_ConstP.pooled26[rowidx];
      localLogic_j[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
    }

    /* UnitDelay: '<S56>/UnitDelay1' */
    localUnitDelay1_hu = InjSpMgt_DWork.UnitDelay_p;

    /* Switch: '<S56>/Switch2' incorporates:
     *  Constant: '<S56>/NotCLR3'
     */
    if (localUnitDelay1_hu) {
      localSwitch2_a = localLogic_j[0];
    } else {
      localSwitch2_a = TRUE;
    }

    /* Product: '<S50>/Divide' */
    localDataTypeConversion5 = InjSys_rInjS1Tmp * InjSys_mFuSpMgt;

    /* Switch: '<S38>/Switch8' incorporates:
     *  Constant: '<S38>/Constant1'
     *  Constant: '<S38>/Constant13'
     *  Product: '<S52>/Divide'
     *  RelationalOperator: '<S38>/Relational Operator1'
     *  Sum: '<S38>/Sum2'
     */
    if (localDataTypeConversion5 > 0.0F) {
      localDataTypeConversion5 = (InjSys_facGainInjS1 * localDataTypeConversion5)
        + InjSys_tiInjOfsInjS1;
    } else {
      localDataTypeConversion5 = 0.0F;
    }

    /* RelationalOperator: '<S44>/Relational Operator' */
    localUnitDelay1_hu = (InjSys_tiInjMinLoThd >= localDataTypeConversion5);

    /* RelationalOperator: '<S44>/Relational Operator1' */
    localRelationalOperator1_gm = (localDataTypeConversion5 >=
      InjSys_tiInjMinHiThd);

    /* UnitDelay: '<S57>/UnitDelay' */
    localUnitDelay = InjSpMgt_DWork.UnitDelay_k;

    /* CombinatorialLogic: '<S57>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_hu != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_gm != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_j[0] = InjSpMgt_ConstP.pooled26[rowidx];
      localLogic_j[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
    }

    /* UnitDelay: '<S57>/UnitDelay1' */
    localUnitDelay1_hu = InjSpMgt_DWork.UnitDelay_m;

    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S57>/NotCLR3'
     */
    if (localUnitDelay1_hu) {
      localSwitch2_b0 = localLogic_j[0];
    } else {
      localSwitch2_b0 = TRUE;
    }

    /* Product: '<S53>/Divide' */
    localfractionTmp_0d = InjSys_rInjS2Tmp * InjSys_mFuSpMgt;

    /* Switch: '<S38>/Switch9' incorporates:
     *  Constant: '<S38>/Constant6'
     *  Constant: '<S38>/Constant7'
     *  Product: '<S54>/Divide'
     *  RelationalOperator: '<S38>/Relational Operator2'
     *  Sum: '<S38>/Sum3'
     */
    if (localfractionTmp_0d > 0.0F) {
      localfractionTmp_0d = (InjSys_facGainInjS2 * localfractionTmp_0d) +
        InjSys_tiInjOfsInjS2;
    } else {
      localfractionTmp_0d = 0.0F;
    }

    /* RelationalOperator: '<S45>/Relational Operator' */
    localUnitDelay1_hu = (InjSys_tiInjMinLoThd >= localfractionTmp_0d);

    /* RelationalOperator: '<S45>/Relational Operator1' */
    localRelationalOperator1_gm = (localfractionTmp_0d >= InjSys_tiInjMinHiThd);

    /* UnitDelay: '<S58>/UnitDelay' */
    localUnitDelay = InjSpMgt_DWork.UnitDelay_df;

    /* CombinatorialLogic: '<S58>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_hu != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_gm != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_j[0] = InjSpMgt_ConstP.pooled26[rowidx];
      localLogic_j[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
    }

    /* UnitDelay: '<S58>/UnitDelay1' */
    localUnitDelay1_hu = InjSpMgt_DWork.UnitDelay_f;

    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S58>/NotCLR3'
     */
    if (localUnitDelay1_hu) {
      localSwitch2_ft = localLogic_j[0];
    } else {
      localSwitch2_ft = TRUE;
    }

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Constant12'
     */
    if (localSwitch2_i) {
      InjSys_rInjH1Resi = InjSys_rInjH1Tmp;
    } else {
      InjSys_rInjH1Resi = 0.0F;
    }

    /* Switch: '<S38>/Switch13' incorporates:
     *  Constant: '<S38>/Constant17'
     */
    if (localSwitch2_a) {
      InjSys_rInjH2Resi = InjSys_rInjH2Tmp;
    } else {
      InjSys_rInjH2Resi = 0.0F;
    }

    /* Switch: '<S38>/Switch14' incorporates:
     *  Constant: '<S38>/Constant18'
     */
    if (localSwitch2_a) {
      InjSys_tiInjH2TmpSat = 0.0F;
    } else {
      InjSys_tiInjH2TmpSat = localDataTypeConversion6;
    }

    /* Switch: '<S38>/Switch2' incorporates:
     *  Constant: '<S38>/Constant4'
     */
    if (localSwitch2_i) {
      InjSys_tiInjH1TmpSat = 0.0F;
    } else {
      InjSys_tiInjH1TmpSat = localSwitch3_e;
    }

    /* Switch: '<S38>/Switch4' incorporates:
     *  Constant: '<S38>/Constant2'
     */
    if (localSwitch2_b0) {
      InjSys_rInjS1Resi = InjSys_rInjS1Tmp;
    } else {
      InjSys_rInjS1Resi = 0.0F;
    }

    /* Switch: '<S38>/Switch5' incorporates:
     *  Constant: '<S38>/Constant3'
     */
    if (localSwitch2_b0) {
      InjSys_tiInjS1TmpSat = 0.0F;
    } else {
      InjSys_tiInjS1TmpSat = localDataTypeConversion5;
    }

    /* Switch: '<S38>/Switch6' incorporates:
     *  Constant: '<S38>/Constant8'
     */
    if (localSwitch2_ft) {
      InjSys_rInjS2Resi = InjSys_rInjS2Tmp;
    } else {
      InjSys_rInjS2Resi = 0.0F;
    }

    /* Switch: '<S38>/Switch7' incorporates:
     *  Constant: '<S38>/Constant14'
     */
    if (localSwitch2_ft) {
      InjSys_tiInjS2TmpSat = 0.0F;
    } else {
      InjSys_tiInjS2TmpSat = localfractionTmp_0d;
    }

    /* Update for UnitDelay: '<S55>/UnitDelay' */
    InjSpMgt_DWork.UnitDelay_e = localSwitch2_i;

    /* Update for UnitDelay: '<S55>/UnitDelay1' incorporates:
     *  Constant: '<S55>/NotCLR2'
     */
    InjSpMgt_DWork.UnitDelay_g = TRUE;

    /* Update for UnitDelay: '<S56>/UnitDelay' */
    InjSpMgt_DWork.UnitDelay_j = localSwitch2_a;

    /* Update for UnitDelay: '<S56>/UnitDelay1' incorporates:
     *  Constant: '<S56>/NotCLR2'
     */
    InjSpMgt_DWork.UnitDelay_p = TRUE;

    /* Update for UnitDelay: '<S57>/UnitDelay' */
    InjSpMgt_DWork.UnitDelay_k = localSwitch2_b0;

    /* Update for UnitDelay: '<S57>/UnitDelay1' incorporates:
     *  Constant: '<S57>/NotCLR2'
     */
    InjSpMgt_DWork.UnitDelay_m = TRUE;

    /* Update for UnitDelay: '<S58>/UnitDelay' */
    InjSpMgt_DWork.UnitDelay_df = localSwitch2_ft;

    /* Update for UnitDelay: '<S58>/UnitDelay1' incorporates:
     *  Constant: '<S58>/NotCLR2'
     */
    InjSpMgt_DWork.UnitDelay_f = TRUE;

    /* end of Outputs for SubSystem: '<S20>/F01_tiInjMinDet' */

    /* Outputs for atomic SubSystem: '<S20>/F02_rMassFuInjclcn' */

    /* Outputs for atomic SubSystem: '<S39>/F01_InjVldChk' */

    /* RelationalOperator: '<S59>/Relational Operator4' incorporates:
     *  Constant: '<S59>/Constant6'
     */
    InjSys_bVldInjH1 = (InjSys_tiInjH1TmpSat > 0.0F);

    /* RelationalOperator: '<S59>/Relational Operator1' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    InjSys_bVldInjH2 = (InjSys_tiInjH2TmpSat > 0.0F);

    /* RelationalOperator: '<S59>/Relational Operator2' incorporates:
     *  Constant: '<S59>/Constant2'
     */
    InjSys_bVldInjS1 = (InjSys_tiInjS1TmpSat > 0.0F);

    /* RelationalOperator: '<S59>/Relational Operator3' incorporates:
     *  Constant: '<S59>/Constant3'
     */
    InjSys_bVldInjS2 = (InjSys_tiInjS2TmpSat > 0.0F);

    /* end of Outputs for SubSystem: '<S39>/F01_InjVldChk' */

    /* If: '<S39>/If1' incorporates:
     *  ActionPort: '<S60>/Action Port'
     *  ActionPort: '<S61>/Action Port'
     *  Logic: '<S39>/Logical Operator'
     *  Logic: '<S39>/Logical Operator1'
     *  Logic: '<S39>/Logical Operator2'
     *  Logic: '<S39>/Logical Operator3'
     *  Logic: '<S39>/Logical Operator4'
     *  SubSystem: '<S39>/F02_noVldInjCase'
     *  SubSystem: '<S39>/F03_VldInjCase'
     */
    if ((((!InjSys_bVldInjH1) && (!InjSys_bVldInjH2)) && (!InjSys_bVldInjS1)) &&
        (!InjSys_bVldInjS2)) {
      /* SignalConversion: '<S60>/Signal Conversion8' incorporates:
       *  Constant: '<S60>/Constant12'
       */
      InjSys_rInjH1Sp = 1.0F;

      /* SignalConversion: '<S60>/Signal Conversion9' incorporates:
       *  Constant: '<S60>/Constant7'
       */
      InjSys_rInjH2Sp = 0.0F;

      /* SignalConversion: '<S60>/Signal Conversion10' incorporates:
       *  Constant: '<S60>/Constant1'
       */
      InjSys_rInjS1Sp = 0.0F;

      /* SignalConversion: '<S60>/Signal Conversion11' incorporates:
       *  Constant: '<S60>/Constant2'
       */
      InjSys_rInjS2Sp = 0.0F;
    } else {
      /* Switch: '<S61>/Switch1' incorporates:
       *  Constant: '<S61>/Constant1'
       *  Constant: '<S61>/Constant2'
       */
      if (InjSys_bVldInjH1) {
        localSwitch3_kc = 1U;
      } else {
        localSwitch3_kc = 0U;
      }

      /* Switch: '<S61>/Switch5' incorporates:
       *  Constant: '<S61>/Constant3'
       *  Constant: '<S61>/Constant4'
       */
      if (InjSys_bVldInjH2) {
        localSwitch5 = 1U;
      } else {
        localSwitch5 = 0U;
      }

      /* Switch: '<S61>/Switch6' incorporates:
       *  Constant: '<S61>/Constant5'
       *  Constant: '<S61>/Constant6'
       */
      if (InjSys_bVldInjS1) {
        localSwitch6 = 1U;
      } else {
        localSwitch6 = 0U;
      }

      /* Switch: '<S61>/Switch7' incorporates:
       *  Constant: '<S61>/Constant10'
       *  Constant: '<S61>/Constant11'
       */
      if (InjSys_bVldInjS2) {
        localSwitch7 = 1U;
      } else {
        localSwitch7 = 0U;
      }

      /* Product: '<S62>/Divide' incorporates:
       *  DataTypeConversion: '<S61>/Data Type Conversion8'
       *  Sum: '<S61>/Add'
       *  Sum: '<S61>/Add1'
       */
      localfractionTmp_0d = (((InjSys_rInjH1Resi + InjSys_rInjH2Resi) +
        InjSys_rInjS1Resi) + InjSys_rInjS2Resi) / ((Float32)((UInt8)
        (((localSwitch3_kc + localSwitch5) + localSwitch6) + localSwitch7)));

      /* Outputs for atomic SubSystem: '<S62>/If Action Subsystem3' */

      /* Switch: '<S64>/Switch1' incorporates:
       *  Constant: '<S64>/Constant1'
       *  Constant: '<S64>/Constant2'
       *  Constant: '<S64>/Constant3'
       *  Logic: '<S64>/Logical Operator1'
       *  RelationalOperator: '<S64>/Relational Operator'
       *  RelationalOperator: '<S64>/Relational Operator1'
       *  RelationalOperator: '<S64>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        InjSys_rInjResi = 0.0F;
      } else {
        InjSys_rInjResi = localfractionTmp_0d;
      }

      /* end of Outputs for SubSystem: '<S62>/If Action Subsystem3' */

      /* Switch: '<S61>/Switch3' incorporates:
       *  Constant: '<S61>/Constant8'
       *  SignalConversion: '<S61>/Signal Conversion10'
       *  Sum: '<S61>/Add3'
       */
      if (InjSys_bVldInjS1) {
        InjSys_rInjS1Sp = InjSys_rInjS1Tmp + InjSys_rInjResi;
      } else {
        InjSys_rInjS1Sp = 0.0F;
      }

      /* Switch: '<S61>/Switch4' incorporates:
       *  Constant: '<S61>/Constant9'
       *  SignalConversion: '<S61>/Signal Conversion11'
       *  Sum: '<S61>/Add4'
       */
      if (InjSys_bVldInjS2) {
        InjSys_rInjS2Sp = InjSys_rInjS2Tmp + InjSys_rInjResi;
      } else {
        InjSys_rInjS2Sp = 0.0F;
      }

      /* Switch: '<S61>/Switch' incorporates:
       *  Constant: '<S61>/Constant12'
       *  SignalConversion: '<S61>/Signal Conversion8'
       *  Sum: '<S61>/Add5'
       */
      if (InjSys_bVldInjH1) {
        InjSys_rInjH1Sp = InjSys_rInjH1Tmp + InjSys_rInjResi;
      } else {
        InjSys_rInjH1Sp = 0.0F;
      }

      /* Switch: '<S61>/Switch2' incorporates:
       *  Constant: '<S61>/Constant7'
       *  SignalConversion: '<S61>/Signal Conversion9'
       *  Sum: '<S61>/Add2'
       */
      if (InjSys_bVldInjH2) {
        InjSys_rInjH2Sp = InjSys_rInjH2Tmp + InjSys_rInjResi;
      } else {
        InjSys_rInjH2Sp = 0.0F;
      }
    }

    /* end of Outputs for SubSystem: '<S20>/F02_rMassFuInjclcn' */

    /* end of Outputs for SubSystem: '<S18>/F01_TestFrac' */
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET12 */
    VEMS_vidGET(Ext_tiToothLen, InjSpMgt_B.VEMS_vidGET12_l);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET30 */
    VEMS_vidGET1DArray(InjrSys_prm_tiInj, 4, InjSpMgt_B.VEMS_vidGET30);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET32 */
    VEMS_vidGET(Sync_bEngPosOk, InjSpMgt_B.VEMS_vidGET32);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET31 */
    VEMS_vidGET(Sync_agEs, InjSpMgt_B.VEMS_vidGET31);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET5 */
    VEMS_vidGET(Eng_noInCyl, InjSpMgt_B.VEMS_vidGET5_h);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_stEng, InjSpMgt_B.VEMS_vidGET1_h);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_noCmprCyl, InjSpMgt_B.VEMS_vidGET4_i);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSpMgt_B.VEMS_vidGET_gw);

    /* Outputs for atomic SubSystem: '<S18>/F02_TestPha' */

    /* Outputs for atomic SubSystem: '<S21>/F01_tiInjSp' */

    /* Product: '<S73>/Divide' */
    localfractionTmp_0d = InjSys_mFuSpMgt * InjSys_rInjH1Sp;

    /* Product: '<S69>/Divide' */
    localDataTypeConversion5 = InjSys_mFuSpMgt * InjSys_rInjH2Sp;

    /* Product: '<S70>/Divide' */
    localfractionTmp_0d_0 = InjSys_mFuSpMgt * InjSys_rInjS1Sp;

    /* Product: '<S71>/Divide' */
    localDataTypeConversion6 = InjSys_mFuSpMgt * InjSys_rInjS2Sp;

    /* Switch: '<S65>/Switch1' incorporates:
     *  Constant: '<S65>/Constant2'
     *  Constant: '<S65>/Constant3'
     *  Product: '<S72>/Divide'
     *  RelationalOperator: '<S65>/Relational Operator1'
     *  Sum: '<S65>/Sum1'
     */
    if (localDataTypeConversion5 > 0.0F) {
      InjSys_tiInjH2Sp = (InjSys_facGainInjH2 * localDataTypeConversion5) +
        InjSys_tiInjOfsInjH2;
    } else {
      InjSys_tiInjH2Sp = 0.0F;
    }

    /* Switch: '<S65>/Switch2' incorporates:
     *  Constant: '<S65>/Constant'
     *  Constant: '<S65>/Constant1'
     *  Product: '<S76>/Divide'
     *  RelationalOperator: '<S65>/Relational Operator'
     *  Sum: '<S65>/Sum4'
     */
    if (localfractionTmp_0d > 0.0F) {
      InjSys_tiInjH1Sp = (InjSys_facGainInjH1 * localfractionTmp_0d) +
        InjSys_tiInjOfsInjH1;
    } else {
      InjSys_tiInjH1Sp = 0.0F;
    }

    /* Switch: '<S65>/Switch3' incorporates:
     *  Constant: '<S65>/Constant4'
     *  Constant: '<S65>/Constant6'
     *  Product: '<S74>/Divide'
     *  RelationalOperator: '<S65>/Relational Operator2'
     *  Sum: '<S65>/Sum2'
     */
    if (localfractionTmp_0d_0 > 0.0F) {
      InjSys_tiInjS1Sp = (InjSys_facGainInjS1 * localfractionTmp_0d_0) +
        InjSys_tiInjOfsInjS1;
    } else {
      InjSys_tiInjS1Sp = 0.0F;
    }

    /* Switch: '<S65>/Switch4' incorporates:
     *  Constant: '<S65>/Constant5'
     *  Constant: '<S65>/Constant7'
     *  Product: '<S75>/Divide'
     *  RelationalOperator: '<S65>/Relational Operator3'
     *  Sum: '<S65>/Sum3'
     */
    if (localDataTypeConversion6 > 0.0F) {
      InjSys_tiInjS2Sp = (InjSys_facGainInjS2 * localDataTypeConversion6) +
        InjSys_tiInjOfsInjS2;
    } else {
      InjSys_tiInjS2Sp = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S21>/F01_tiInjSp' */

    /* Outputs for atomic SubSystem: '<S21>/F02_agWdInjSp' */

    /* DataTypeConversion: '<S66>/Data Type Conversion1' */
    locallocalDataTypeConversion1_i = ((Float32)InjSpMgt_B.VEMS_vidGET30[0]) *
      3.200000037E-006F;

    /* DataTypeConversion: '<S66>/Data Type Conversion2' incorporates:
     *  Constant: '<S66>/Ext_agWdTooth_SC1'
     */
    localDataTypeConversion5 = (Float32)Ext_agWdTooth_SC;

    /* DataTypeConversion: '<S66>/Data Type Conversion3' incorporates:
     *  Constant: '<S66>/InjSys_facConvTiToagWdStall_C1'
     */
    localDataTypeConversion3_m = (Float32)InjSys_facConvTiToagWdStall_C;

    /* DataTypeConversion: '<S66>/Data Type Conversion4' */
    localDataTypeConversion6 = ((Float32)InjSpMgt_B.VEMS_vidGET12_l) *
      3.200000037E-006F;

    /* If: '<S66>/If2' incorporates:
     *  ActionPort: '<S77>/Action Port'
     *  ActionPort: '<S78>/Action Port'
     *  Constant: '<S66>/Constant2'
     *  RelationalOperator: '<S66>/Relational Operator2'
     *  SubSystem: '<S66>/F01_InjHom1Width'
     *  SubSystem: '<S66>/F02_InjHom1WidthNul'
     */
    if (InjSys_tiInjH1Sp > 0.0F) {
      /* Switch: '<S77>/Switch3' incorporates:
       *  Constant: '<S77>/InjSys_bAcvTiInjETB_C'
       *  Constant: '<S77>/InjSys_bAcvTiInjETB_C1'
       *  Constant: '<S89>/Constant'
       *  Constant: '<S89>/Constant1'
       *  MinMax: '<S89>/MinMax'
       *  Selector: '<S89>/Selector'
       *  Sum: '<S89>/Add'
       */
      if (InjSys_bAcvTiInjETB_C) {
        localfractionTmp_0d = locallocalDataTypeConversion1_i;
      } else {
        localfractionTmp_0d = InjSys_tiInjH1Sp;
      }

      /* Product: '<S90>/Divide' incorporates:
       *  Product: '<S92>/Divide'
       */
      localfractionTmp_0d_0 = (localDataTypeConversion5 * localfractionTmp_0d) /
        localDataTypeConversion6;

      /* Outputs for atomic SubSystem: '<S90>/If Action Subsystem3' */

      /* Switch: '<S94>/Switch1' incorporates:
       *  Constant: '<S94>/Constant1'
       *  Constant: '<S94>/Constant2'
       *  Constant: '<S94>/Constant3'
       *  Logic: '<S94>/Logical Operator1'
       *  RelationalOperator: '<S94>/Relational Operator'
       *  RelationalOperator: '<S94>/Relational Operator1'
       *  RelationalOperator: '<S94>/Relational Operator3'
       */
      if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
           (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
           localfractionTmp_0d_0)) {
        localfractionTmp_0d_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S90>/If Action Subsystem3' */

      /* Switch: '<S77>/Switch1' incorporates:
       *  Constant: '<S77>/Constant2'
       *  Product: '<S91>/Divide'
       *  RelationalOperator: '<S77>/Relational Operator1'
       */
      if (InjSpMgt_B.VEMS_vidGET1_h != 6) {
        InjSys_agWdInjH1Sp = localfractionTmp_0d_0;
      } else {
        InjSys_agWdInjH1Sp = localfractionTmp_0d * localDataTypeConversion3_m;
      }
    } else {
      /* Constant: '<S78>/Constant' */
      InjSys_agWdInjH1Sp = 0.0F;
    }

    /* If: '<S66>/If1' incorporates:
     *  ActionPort: '<S79>/Action Port'
     *  ActionPort: '<S80>/Action Port'
     *  Constant: '<S66>/Constant1'
     *  RelationalOperator: '<S66>/Relational Operator1'
     *  SubSystem: '<S66>/F03_InjHom2Width'
     *  SubSystem: '<S66>/F04_InjHom2WidthNul'
     */
    if (InjSys_tiInjH2Sp > 0.0F) {
      /* Switch: '<S79>/Switch3' incorporates:
       *  Constant: '<S79>/InjSys_bAcvTiInjETB_C'
       *  Constant: '<S79>/InjSys_bAcvTiInjETB_C1'
       *  Constant: '<S95>/Constant'
       *  Constant: '<S95>/Constant1'
       *  MinMax: '<S95>/MinMax'
       *  Selector: '<S95>/Selector'
       *  Sum: '<S95>/Add'
       */
      if (InjSys_bAcvTiInjETB_C) {
        localfractionTmp_0d = locallocalDataTypeConversion1_i;
      } else {
        localfractionTmp_0d = InjSys_tiInjH2Sp;
      }

      /* Product: '<S96>/Divide' incorporates:
       *  Product: '<S98>/Divide'
       */
      localfractionTmp_0d_0 = (localDataTypeConversion5 * localfractionTmp_0d) /
        localDataTypeConversion6;

      /* Outputs for atomic SubSystem: '<S96>/If Action Subsystem3' */

      /* Switch: '<S100>/Switch1' incorporates:
       *  Constant: '<S100>/Constant1'
       *  Constant: '<S100>/Constant2'
       *  Constant: '<S100>/Constant3'
       *  Logic: '<S100>/Logical Operator1'
       *  RelationalOperator: '<S100>/Relational Operator'
       *  RelationalOperator: '<S100>/Relational Operator1'
       *  RelationalOperator: '<S100>/Relational Operator3'
       */
      if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
           (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
           localfractionTmp_0d_0)) {
        localfractionTmp_0d_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S96>/If Action Subsystem3' */

      /* Switch: '<S79>/Switch1' incorporates:
       *  Constant: '<S79>/Constant2'
       *  Product: '<S97>/Divide'
       *  RelationalOperator: '<S79>/Relational Operator1'
       */
      if (InjSpMgt_B.VEMS_vidGET1_h != 6) {
        InjSys_agWdInjH2Sp = localfractionTmp_0d_0;
      } else {
        InjSys_agWdInjH2Sp = localfractionTmp_0d * localDataTypeConversion3_m;
      }
    } else {
      /* Constant: '<S80>/Constant' */
      InjSys_agWdInjH2Sp = 0.0F;
    }

    /* If: '<S66>/If' incorporates:
     *  ActionPort: '<S81>/Action Port'
     *  ActionPort: '<S82>/Action Port'
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Relational Operator'
     *  SubSystem: '<S66>/F05_InjS1Width'
     *  SubSystem: '<S66>/F06_InjS1WidthNul'
     */
    if (InjSys_tiInjS1Sp > 0.0F) {
      /* Switch: '<S81>/Switch3' incorporates:
       *  Constant: '<S101>/Constant'
       *  Constant: '<S101>/Constant1'
       *  Constant: '<S81>/InjSys_bAcvTiInjETB_C'
       *  Constant: '<S81>/InjSys_bAcvTiInjETB_C1'
       *  MinMax: '<S101>/MinMax'
       *  Selector: '<S101>/Selector'
       *  Sum: '<S101>/Add'
       */
      if (InjSys_bAcvTiInjETB_C) {
        localfractionTmp_0d = locallocalDataTypeConversion1_i;
      } else {
        localfractionTmp_0d = InjSys_tiInjS1Sp;
      }

      /* Product: '<S102>/Divide' incorporates:
       *  Product: '<S104>/Divide'
       */
      localfractionTmp_0d_0 = (localDataTypeConversion5 * localfractionTmp_0d) /
        localDataTypeConversion6;

      /* Outputs for atomic SubSystem: '<S102>/If Action Subsystem3' */

      /* Switch: '<S106>/Switch1' incorporates:
       *  Constant: '<S106>/Constant1'
       *  Constant: '<S106>/Constant2'
       *  Constant: '<S106>/Constant3'
       *  Logic: '<S106>/Logical Operator1'
       *  RelationalOperator: '<S106>/Relational Operator'
       *  RelationalOperator: '<S106>/Relational Operator1'
       *  RelationalOperator: '<S106>/Relational Operator3'
       */
      if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
           (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
           localfractionTmp_0d_0)) {
        localfractionTmp_0d_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S102>/If Action Subsystem3' */

      /* Switch: '<S81>/Switch1' incorporates:
       *  Constant: '<S81>/Constant2'
       *  Product: '<S103>/Divide'
       *  RelationalOperator: '<S81>/Relational Operator1'
       */
      if (InjSpMgt_B.VEMS_vidGET1_h != 6) {
        InjSys_agWdInjS1Sp = localfractionTmp_0d_0;
      } else {
        InjSys_agWdInjS1Sp = localfractionTmp_0d * localDataTypeConversion3_m;
      }
    } else {
      /* Constant: '<S82>/Constant' */
      InjSys_agWdInjS1Sp = 0.0F;
    }

    /* If: '<S66>/If3' incorporates:
     *  ActionPort: '<S83>/Action Port'
     *  ActionPort: '<S84>/Action Port'
     *  Constant: '<S66>/Constant3'
     *  RelationalOperator: '<S66>/Relational Operator3'
     *  SubSystem: '<S66>/F07_InjS2Width'
     *  SubSystem: '<S66>/F08_InjS2WidthNul'
     */
    if (InjSys_tiInjS2Sp > 0.0F) {
      /* Switch: '<S83>/Switch3' incorporates:
       *  Constant: '<S107>/Constant'
       *  Constant: '<S107>/Constant1'
       *  Constant: '<S83>/InjSys_bAcvTiInjETB_C'
       *  Constant: '<S83>/InjSys_bAcvTiInjETB_C1'
       *  MinMax: '<S107>/MinMax'
       *  Selector: '<S107>/Selector'
       *  Sum: '<S107>/Add'
       */
      if (InjSys_bAcvTiInjETB_C) {
        localfractionTmp_0d_0 = locallocalDataTypeConversion1_i;
      } else {
        localfractionTmp_0d_0 = InjSys_tiInjS2Sp;
      }

      /* Product: '<S108>/Divide' incorporates:
       *  Product: '<S110>/Divide'
       */
      localfractionTmp_0d = (localDataTypeConversion5 * localfractionTmp_0d_0) /
        localDataTypeConversion6;

      /* Outputs for atomic SubSystem: '<S108>/If Action Subsystem3' */

      /* Switch: '<S112>/Switch1' incorporates:
       *  Constant: '<S112>/Constant1'
       *  Constant: '<S112>/Constant2'
       *  Constant: '<S112>/Constant3'
       *  Logic: '<S112>/Logical Operator1'
       *  RelationalOperator: '<S112>/Relational Operator'
       *  RelationalOperator: '<S112>/Relational Operator1'
       *  RelationalOperator: '<S112>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        localfractionTmp_0d = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S108>/If Action Subsystem3' */

      /* Switch: '<S83>/Switch1' incorporates:
       *  Constant: '<S83>/Constant2'
       *  Product: '<S109>/Divide'
       *  RelationalOperator: '<S83>/Relational Operator1'
       */
      if (InjSpMgt_B.VEMS_vidGET1_h != 6) {
        InjSys_agWdInjS2Sp = localfractionTmp_0d;
      } else {
        InjSys_agWdInjS2Sp = localfractionTmp_0d_0 * localDataTypeConversion3_m;
      }
    } else {
      /* Constant: '<S84>/Constant' */
      InjSys_agWdInjS2Sp = 0.0F;
    }

    /* DataTypeConversion: '<S85>/OutDTConv' incorporates:
     *  Constant: '<S85>/offset'
     *  Constant: '<S85>/offset1'
     *  Constant: '<S85>/one_on_slope'
     *  Product: '<S85>/Product4'
     *  Sum: '<S85>/Add1'
     *  Sum: '<S85>/Add2'
     */
    localDataTypeConversion6 = (1.066666698E+001F * InjSys_agWdInjH1Sp) + 0.5F;
    if (localDataTypeConversion6 < 65536.0F) {
      if (localDataTypeConversion6 >= 0.0F) {
        locallocalOutDTConv = (UInt16)localDataTypeConversion6;
      } else {
        locallocalOutDTConv = 0U;
      }
    } else {
      locallocalOutDTConv = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S86>/OutDTConv' incorporates:
     *  Constant: '<S86>/offset'
     *  Constant: '<S86>/offset1'
     *  Constant: '<S86>/one_on_slope'
     *  Product: '<S86>/Product4'
     *  Sum: '<S86>/Add1'
     *  Sum: '<S86>/Add2'
     */
    localDataTypeConversion6 = (1.066666698E+001F * InjSys_agWdInjH2Sp) + 0.5F;
    if (localDataTypeConversion6 < 65536.0F) {
      if (localDataTypeConversion6 >= 0.0F) {
        locallocalOutDTConv_j = (UInt16)localDataTypeConversion6;
      } else {
        locallocalOutDTConv_j = 0U;
      }
    } else {
      locallocalOutDTConv_j = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S87>/OutDTConv' incorporates:
     *  Constant: '<S87>/offset'
     *  Constant: '<S87>/offset1'
     *  Constant: '<S87>/one_on_slope'
     *  Product: '<S87>/Product4'
     *  Sum: '<S87>/Add1'
     *  Sum: '<S87>/Add2'
     */
    localDataTypeConversion6 = (1.066666698E+001F * InjSys_agWdInjS1Sp) + 0.5F;
    if (localDataTypeConversion6 < 65536.0F) {
      if (localDataTypeConversion6 >= 0.0F) {
        locallocalOutDTConv_d = (UInt16)localDataTypeConversion6;
      } else {
        locallocalOutDTConv_d = 0U;
      }
    } else {
      locallocalOutDTConv_d = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S88>/OutDTConv' incorporates:
     *  Constant: '<S88>/offset'
     *  Constant: '<S88>/offset1'
     *  Constant: '<S88>/one_on_slope'
     *  Product: '<S88>/Product4'
     *  Sum: '<S88>/Add1'
     *  Sum: '<S88>/Add2'
     */
    localDataTypeConversion6 = (1.066666698E+001F * InjSys_agWdInjS2Sp) + 0.5F;
    if (localDataTypeConversion6 < 65536.0F) {
      if (localDataTypeConversion6 >= 0.0F) {
        locallocalOutDTConv_g = (UInt16)localDataTypeConversion6;
      } else {
        locallocalOutDTConv_g = 0U;
      }
    } else {
      locallocalOutDTConv_g = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S21>/F02_agWdInjSp' */

    /* Outputs for atomic SubSystem: '<S21>/F03_agInjSp' */

    /* Outputs for atomic SubSystem: '<S67>/F01_agOfsPhaInjClcn' */

    /* PreLookup: '<S118>/Prelookup' */
    localExt_nEng_InjSys_nEng_A_1_j = plook_u32u16f_lincp
      (InjSpMgt_B.VEMS_vidGET10, (&(InjSys_nEng_A[0])), 15U,
       &localInterpolationUsingPreloo_a, &InjSpMgt_DWork.Prelookup_DWORK1);

    /* Interpolation_n-D: '<S116>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_a;
    InjSys_agOfsPhaInjS2 = intrp1d_iu16n4ff_u32f_l_ns
      (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d,
       (&(InjSys_agOfsPhaIg_T[0])));

    /* Interpolation_n-D: '<S117>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localInterpolationUsingPreloo_a;
    localInterpolationUsingPreloo_a = intrp1d_iu16n4ff_u32f_l_ns
      (localExt_nEng_InjSys_nEng_A_1_j, localfractionTmp_0d,
       (&(InjSys_agOfsPhaInj_T[0])));

    /* Switch: '<S113>/Switch1' incorporates:
     *  Constant: '<S113>/Constant1'
     *  RelationalOperator: '<S113>/Relational Operator1'
     */
    if (locallocalOutDTConv_d > 0) {
      InjSys_agOfsPhaInjH2 = localInterpolationUsingPreloo_a;
    } else {
      InjSys_agOfsPhaInjH2 = 0.0F;
    }

    /* Switch: '<S113>/Switch2' incorporates:
     *  Constant: '<S113>/Constant3'
     *  RelationalOperator: '<S113>/Relational Operator3'
     */
    if (locallocalOutDTConv_j > 0) {
      InjSys_agOfsPhaInjH1 = localInterpolationUsingPreloo_a;
    } else {
      InjSys_agOfsPhaInjH1 = 0.0F;
    }

    /* Switch: '<S113>/Switch3' incorporates:
     *  Constant: '<S113>/Constant2'
     *  RelationalOperator: '<S113>/Relational Operator2'
     */
    if (locallocalOutDTConv_g > 0) {
      InjSys_agOfsPhaInjS1 = localInterpolationUsingPreloo_a;
    } else {
      InjSys_agOfsPhaInjS1 = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S67>/F01_agOfsPhaInjClcn' */

    /* If: '<S67>/If1' incorporates:
     *  ActionPort: '<S114>/Action Port'
     *  ActionPort: '<S115>/Action Port'
     *  Constant: '<S67>/InjSys_agInj2CrkSpDft_C4'
     *  RelationalOperator: '<S67>/Relational Operator2'
     *  SubSystem: '<S67>/F02_agInjSpnoSTTStop'
     *  SubSystem: '<S67>/F03_agInjSpSTTStop'
     */
    if (InjSpMgt_B.VEMS_vidGET1_h != 6) {
      /* Outputs for atomic SubSystem: '<S114>/F01_PhaInjS2' */

      /* DataTypeConversion: '<S119>/DTConv_UFix_To_Single_5' incorporates:
       *  Constant: '<S119>/InjSys_agInjS2SpMin_C'
       */
      localfractionTmp_0d = ((Float32)InjSys_agInjS2SpMin_C) * 0.09375F;

      /* Logic: '<S119>/Logical Operator1' incorporates:
       *  Constant: '<S119>/Constant1'
       *  Constant: '<S119>/InjSys_bAcvTiInjETB_C'
       *  RelationalOperator: '<S119>/Relational Operator2'
       */
      localSwitch2_i = ((locallocalOutDTConv_g > 0) || InjSys_bAcvTiInjETB_C);

      /* Lookup_n-D: '<S123>/Lookup Table (n-D)' */
      localDataTypeConversion6 = look1_iu16lftu16n4If_binlcns
        (InjSpMgt_B.VEMS_vidGET11, (&(InjSys_pFuRailMes_A[0])),
         (&(InjSys_agInjS2SpMinLP_T[0])), 15U);

      /* Switch: '<S119>/Switch3' incorporates:
       *  Constant: '<S119>/InjSys_agInjS2SpMin_C1'
       *  RelationalOperator: '<S119>/Relational Operator3'
       *  Sum: '<S119>/Sum4'
       */
      if (InjSpMgt_B.VEMS_vidGET11 > InjSys_pFuRailMin_C) {
        localDataTypeConversion6 = InjSys_agOfsPhaInjS2 +
          localDTConv_UFix_To_Single_4;
      }

      /* Switch: '<S119>/Switch4' incorporates:
       *  Logic: '<S119>/Logical Operator2'
       *  Lookup_n-D: '<S124>/Lookup Table (n-D)'
       */
      if (InjSpMgt_B.VEMS_vidGET_gw) {
        localDataTypeConversion6 = look2_iu16u16lftu16n4If_binlcns
          (InjSpMgt_B.VEMS_vidGET10, InjSpMgt_B.VEMS_vidGET11,
           (&(InjSys_nEng_AgCkInjPhd_A[0])), (&(InjSys_DifInjr_A[0])),
           (&(Eng_tiAgCkInjPhd_M[0])), &InjSpMgt_ConstP.pooled16[0], 9U);
      }

      /* Switch: '<S119>/Switch1' incorporates:
       *  Constant: '<S119>/InjSys_bInhCorInjPhaSIgSp_C'
       */
      if (InjSys_bInhCorInjPhaSIgSp_C) {
        localDataTypeConversion6 = localfractionTmp_0d;
      }

      /* MinMax: '<S119>/MinMax1' */
      localfractionTmp_0d = rt_MAXf(localfractionTmp_0d,
        localDataTypeConversion6);

      /* Switch: '<S119>/Switch2' */
      if (localSwitch2_i) {
        localDataTypeConversion6 = InjSys_agEndInjS2Tmp;
      } else {
        localDataTypeConversion6 = localfractionTmp_0d;
      }

      /* Logic: '<S119>/Logical Operator' incorporates:
       *  RelationalOperator: '<S119>/Relational Operator1'
       */
      InjSys_bDetSatInjS2Min = ((localSwitch2_i) && (localDataTypeConversion6 <
        localfractionTmp_0d));

      /* MinMax: '<S119>/MinMax' */
      InjSys_agEndInjS2Sp = rt_MAXf(localDataTypeConversion6,
        localfractionTmp_0d);

      /* Sum: '<S119>/Sum5' */
      InjSys_agBegInjS2Sp = InjSys_agEndInjS2Sp + InjSys_agWdInjS2Sp;

      /* RelationalOperator: '<S119>/Relational Operator' incorporates:
       *  Constant: '<S119>/InjSys_agInjS2SpMax_C'
       *  DataTypeConversion: '<S119>/DTConv_UFix_To_Single_1'
       */
      InjSys_bDetPhaInjS2Max = (InjSys_agBegInjS2Sp > (((Float32)
        InjSys_agInjS2SpMax_C) * 0.09375F));

      /* end of Outputs for SubSystem: '<S114>/F01_PhaInjS2' */

      /* Outputs for atomic SubSystem: '<S114>/F02_PhaInjS1' */

      /* Logic: '<S120>/Logical Operator1' incorporates:
       *  Constant: '<S120>/Constant1'
       *  Constant: '<S120>/InjSys_bAcvTiInjETB_C'
       *  RelationalOperator: '<S120>/Relational Operator2'
       */
      localSwitch2_i = ((locallocalOutDTConv_d > 0) || InjSys_bAcvTiInjETB_C);

      /* Sum: '<S120>/Sum8' */
      localfractionTmp_0d = InjSys_agBegInjS2Sp + InjSys_agOfsPhaInjS1;

      /* Switch: '<S120>/Switch2' incorporates:
       *  Sum: '<S120>/Sum2'
       */
      if (localSwitch2_i) {
        localfractionTmp_0d_0 = InjSys_agBegInjS1Tmp - InjSys_agWdInjS1Sp;
      } else {
        localfractionTmp_0d_0 = localfractionTmp_0d;
      }

      /* Logic: '<S120>/Logical Operator' incorporates:
       *  RelationalOperator: '<S120>/Relational Operator3'
       */
      InjSys_bDetSatInjS1Min = ((localSwitch2_i) && (localfractionTmp_0d_0 <
        localfractionTmp_0d));

      /* MinMax: '<S120>/MinMax' */
      InjSys_agEndInjS1Sp = rt_MAXf(localfractionTmp_0d_0, localfractionTmp_0d);

      /* Sum: '<S120>/Sum1' */
      InjSys_agBegInjS1Sp = InjSys_agEndInjS1Sp + InjSys_agWdInjS1Sp;

      /* RelationalOperator: '<S120>/Relational Operator' incorporates:
       *  Constant: '<S120>/InjSys_agInjS1SpMax_C'
       *  DataTypeConversion: '<S120>/DTConv_UFix_To_Single_5'
       */
      InjSys_bDetPhaInjS1Max = (InjSys_agBegInjS1Sp > (((Float32)
        InjSys_agInjS1SpMax_C) * 0.09375F));

      /* end of Outputs for SubSystem: '<S114>/F02_PhaInjS1' */

      /* Outputs for atomic SubSystem: '<S114>/F03_PhaInjH2' */

      /* DataTypeConversion: '<S121>/DTConv_UFix_To_Single_5' incorporates:
       *  Constant: '<S121>/InjSys_agInjH2SpMin_C'
       */
      localfractionTmp_0d = ((Float32)InjSys_agInjH2SpMin_C) * 0.09375F;

      /* Logic: '<S121>/Logical Operator1' incorporates:
       *  Constant: '<S121>/Constant1'
       *  Constant: '<S121>/InjSys_bAcvTiInjETB_C'
       *  RelationalOperator: '<S121>/Relational Operator2'
       */
      localSwitch2_i = ((locallocalOutDTConv_j > 0) || InjSys_bAcvTiInjETB_C);

      /* Sum: '<S121>/Sum8' */
      localfractionTmp_0d_0 = InjSys_agBegInjS1Sp + InjSys_agOfsPhaInjH2;

      /* MinMax: '<S121>/MinMax1' */
      localfractionTmp_0d = rt_MAXf(localfractionTmp_0d, localfractionTmp_0d_0);

      /* Switch: '<S121>/Switch2' incorporates:
       *  Sum: '<S121>/Sum1'
       */
      if (localSwitch2_i) {
        localfractionTmp_0d_0 = InjSys_agBegInjH2Tmp - InjSys_agWdInjH2Sp;
      } else {
        localfractionTmp_0d_0 = localfractionTmp_0d;
      }

      /* Logic: '<S121>/Logical Operator' incorporates:
       *  RelationalOperator: '<S121>/Relational Operator1'
       */
      InjSys_bDetSatInjH2Min = ((localSwitch2_i) && (localfractionTmp_0d_0 <
        localfractionTmp_0d));

      /* MinMax: '<S121>/MinMax' */
      InjSys_agEndInjH2Sp = rt_MAXf(localfractionTmp_0d_0, localfractionTmp_0d);

      /* Sum: '<S121>/Sum5' */
      InjSys_agBegInjH2Sp = InjSys_agEndInjH2Sp + InjSys_agWdInjH2Sp;

      /* RelationalOperator: '<S121>/Relational Operator' incorporates:
       *  Constant: '<S121>/InjSys_agInjH2SpMax_C'
       *  DataTypeConversion: '<S121>/DTConv_UFix_To_Single_1'
       */
      InjSys_bDetPhaInjH2Max = (InjSys_agBegInjH2Sp > (((Float32)
        InjSys_agInjH2SpMax_C) * 0.09375F));

      /* end of Outputs for SubSystem: '<S114>/F03_PhaInjH2' */

      /* Outputs for atomic SubSystem: '<S114>/F04_PhaInjH1' */

      /* Sum: '<S122>/Add' */
      localfractionTmp_0d = InjSys_agBegInjH1Tmp - InjSys_agWdInjH1Sp;

      /* Sum: '<S122>/Sum8' */
      localfractionTmp_0d_0 = InjSys_agBegInjH2Sp + InjSys_agOfsPhaInjH1;

      /* MinMax: '<S122>/MinMax' */
      InjSys_agEndInjH1Sp = rt_MAXf(localfractionTmp_0d, localfractionTmp_0d_0);

      /* Sum: '<S122>/Sum5' */
      InjSys_agBegInjH1Sp = InjSys_agEndInjH1Sp + InjSys_agWdInjH1Sp;

      /* RelationalOperator: '<S125>/Relational Operator' incorporates:
       *  Constant: '<S122>/InjSys_agInjH1SpHiThd_C'
       *  DataTypeConversion: '<S122>/DTConv_UFix_To_Single_2'
       */
      localRelationalOperator_ib = (InjSys_agBegInjH1Sp >= (((Float32)
        InjSys_agInjH1SpHiThd_C) * 0.09375F));

      /* RelationalOperator: '<S125>/Relational Operator1' incorporates:
       *  Constant: '<S122>/InjSys_agInjH1SpLoThd_C'
       *  DataTypeConversion: '<S122>/DTConv_UFix_To_Single_3'
       */
      localRelationalOperator1_lv = (InjSys_agBegInjH1Sp <= (((Float32)
        InjSys_agInjH1SpLoThd_C) * 0.09375F));

      /* UnitDelay: '<S126>/UnitDelay' */
      localUnitDelay1 = InjSpMgt_DWork.UnitDelay;

      /* CombinatorialLogic: '<S126>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_ib != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_lv != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = InjSpMgt_ConstP.pooled26[rowidx];
        localLogic[1] = InjSpMgt_ConstP.pooled26[rowidx + 8];
      }

      /* UnitDelay: '<S126>/UnitDelay1' */
      localUnitDelay1 = InjSpMgt_DWork.UnitDelay_d;

      /* Switch: '<S126>/Switch2' incorporates:
       *  Constant: '<S126>/NotCLR3'
       */
      if (localUnitDelay1) {
        InjSys_bDetPhaInjH1Max = localLogic[0];
      } else {
        InjSys_bDetPhaInjH1Max = TRUE;
      }

      /* RelationalOperator: '<S122>/Relational Operator1' */
      InjSys_bDetSatInjH1Min = (localfractionTmp_0d < localfractionTmp_0d_0);

      /* Update for UnitDelay: '<S126>/UnitDelay' */
      InjSpMgt_DWork.UnitDelay = InjSys_bDetPhaInjH1Max;

      /* Update for UnitDelay: '<S126>/UnitDelay1' incorporates:
       *  Constant: '<S126>/NotCLR2'
       */
      InjSpMgt_DWork.UnitDelay_d = TRUE;

      /* end of Outputs for SubSystem: '<S114>/F04_PhaInjH1' */
    } else {
      /* Outputs for atomic SubSystem: '<S115>/F01_FrstInjSTTOfsClcn' */

      /* DataTypeConversion: '<S127>/DTConv_UFix_To_Single_1' */
      localfractionTmp_0d = ((Float32)InjSpMgt_B.VEMS_vidGET31) * 3.0F;

      /* Lookup_n-D: '<S133>/Lookup Table (n-D)' */
      Eng_AgCkOffFuInjStrt = look1_iu8lftu16n4If_binlcns
        (InjSpMgt_B.VEMS_vidGET31, (&(Sync_agEs_A[0])),
         (&(Eng_AgCkOffFuInjStrt_T[0])), 8U);

      /* Math: '<S127>/Math Function1' incorporates:
       *  Constant: '<S127>/Constant20'
       *  Constant: '<S127>/Constant8'
       *  Sum: '<S127>/Add4'
       */
      localfractionTmp_0d_0 = rt_mod32(240.0F - localfractionTmp_0d, 720.0F);

      /* Switch: '<S127>/Switch7' incorporates:
       *  Constant: '<S127>/Constant12'
       *  Constant: '<S127>/Constant7'
       *  RelationalOperator: '<S127>/Relational Operator8'
       *  Sum: '<S127>/Add2'
       */
      if (InjSpMgt_B.VEMS_vidGET5_h == 2) {
        localfractionTmp_0d_0 = 480.0F - localfractionTmp_0d;
      }

      /* Switch: '<S127>/Switch5' incorporates:
       *  Constant: '<S127>/Constant11'
       *  Constant: '<S127>/Constant5'
       *  RelationalOperator: '<S127>/Relational Operator7'
       *  Sum: '<S127>/Add1'
       */
      if (InjSpMgt_B.VEMS_vidGET5_h == 1) {
        localfractionTmp_0d_0 = 720.0F - localfractionTmp_0d;
      }

      /* Sum: '<S127>/Add5' incorporates:
       *  Constant: '<S127>/Constant16'
       */
      localDataTypeConversion6 = 720.0F - localfractionTmp_0d;

      /* Sum: '<S127>/Add6' incorporates:
       *  Constant: '<S127>/Constant17'
       */
      localDataTypeConversion5 = 480.0F - localfractionTmp_0d;

      /* Sum: '<S127>/Add8' incorporates:
       *  Constant: '<S127>/Constant18'
       */
      localfractionTmp_0d = 240.0F - localfractionTmp_0d;

      /* Math: '<S127>/Math Function2' incorporates:
       *  Constant: '<S127>/Constant9'
       */
      localfractionTmp_0d = rt_mod32(localfractionTmp_0d, 720.0F);

      /* Switch: '<S127>/Switch10' incorporates:
       *  Constant: '<S127>/Constant15'
       *  RelationalOperator: '<S127>/Relational Operator9'
       */
      if (InjSpMgt_B.VEMS_vidGET4_i == 2) {
        localfractionTmp_0d = localDataTypeConversion5;
      }

      /* Switch: '<S127>/Switch8' incorporates:
       *  Constant: '<S127>/Constant14'
       *  RelationalOperator: '<S127>/Relational Operator5'
       */
      if (InjSpMgt_B.VEMS_vidGET4_i == 1) {
        localfractionTmp_0d = localDataTypeConversion6;
      }

      /* Sum: '<S127>/Add7' */
      InjSys_prm_agMaxFrstInjSTT[0] = localfractionTmp_0d_0 -
        Eng_AgCkOffFuInjStrt;
      InjSys_prm_agMaxFrstInjSTT[1] = localfractionTmp_0d - Eng_AgCkOffFuInjStrt;

      /* Switch: '<S127>/Switch2' incorporates:
       *  Constant: '<S127>/Constant2'
       *  RelationalOperator: '<S127>/Relational Operator1'
       *  Sum: '<S127>/Sum5'
       */
      if (locallocalOutDTConv_d != 0) {
        localfractionTmp_0d_0 = InjSys_agBegInjS1Tmp;
      } else {
        localfractionTmp_0d_0 = InjSys_agEndInjS2Tmp + InjSys_agWdInjS2Sp;
      }

      /* Switch: '<S127>/Switch3' incorporates:
       *  Constant: '<S127>/Constant1'
       *  RelationalOperator: '<S127>/Relational Operator3'
       */
      if (locallocalOutDTConv_j != 0) {
        localfractionTmp_0d_0 = InjSys_agBegInjH2Tmp;
      }

      /* Switch: '<S127>/Switch1' incorporates:
       *  Constant: '<S127>/Constant6'
       *  RelationalOperator: '<S127>/Relational Operator2'
       */
      if (locallocalOutDTConv != 0) {
        InjSys_agFrstInjSTTReq = InjSys_agBegInjH1Tmp;
      } else {
        InjSys_agFrstInjSTTReq = localfractionTmp_0d_0;
      }

      /* Sum: '<S127>/Add3' */
      locallocalMinMax2_o_idx = InjSys_agFrstInjSTTReq -
        InjSys_prm_agMaxFrstInjSTT[0];
      locallocalDataTypeConversion1_i = InjSys_agFrstInjSTTReq -
        InjSys_prm_agMaxFrstInjSTT[1];

      /* Switch: '<S127>/Switch4' incorporates:
       *  Constant: '<S127>/Constant3'
       *  Constant: '<S127>/Constant4'
       *  Inport: '<Root>/FRM_bInhFrstInjSTT'
       *  Logic: '<S127>/Logical Operator3'
       *  Logic: '<S127>/Logical Operator4'
       *  MinMax: '<S127>/MinMax2'
       */
      if (InjSpMgt_B.VEMS_vidGET32 && (!GDGAR_bGetFRM(FRM_FRM_INHFRSTINJSTT))) {
        InjSys_prm_agOfsFrstInjSTT[0] = rt_MAXf(locallocalMinMax2_o_idx, 0.0F);
        InjSys_prm_agOfsFrstInjSTT[1] = rt_MAXf(locallocalDataTypeConversion1_i,
          0.0F);
      } else {
        InjSys_prm_agOfsFrstInjSTT[0] = 0.0F;
        InjSys_prm_agOfsFrstInjSTT[1] = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S115>/F01_FrstInjSTTOfsClcn' */

      /* Outputs for atomic SubSystem: '<S115>/F02_PhaInjS2STT' */

      /* DataTypeConversion: '<S128>/Data Type Conversion1' incorporates:
       *  Constant: '<S128>/InjSys_agInjS2SpMin_C'
       */
      localfractionTmp_0d = ((Float32)InjSys_agInjS2SpMin_C) * 0.09375F;

      /* Lookup_n-D: '<S134>/Lookup Table (n-D)' */
      localDataTypeConversion6 = look2_iu16u16lftu16n4If_binlcns
        (InjSpMgt_B.VEMS_vidGET10, InjSpMgt_B.VEMS_vidGET11,
         (&(InjSys_nEng_AgCkInjPhd_A[0])), (&(InjSys_DifInjr_A[0])),
         (&(Eng_tiAgCkInjPhd_M[0])), &InjSpMgt_ConstP.pooled16[0], 9U);

      /* Sum: '<S128>/Sum1' */
      locallocalMinMax2_o_idx = InjSys_agEndInjS2Tmp -
        InjSys_prm_agOfsFrstInjSTT[0];
      locallocalDataTypeConversion1_i = InjSys_agEndInjS2Tmp -
        InjSys_prm_agOfsFrstInjSTT[1];

      /* Switch: '<S128>/Switch1' incorporates:
       *  Constant: '<S128>/InjSys_bInhCorInjPhaSIgSp_C'
       *  Sum: '<S128>/Sum4'
       */
      if (InjSys_bInhCorInjPhaSIgSp_C) {
        localfractionTmp_0d_0 = localfractionTmp_0d;
      } else {
        localfractionTmp_0d_0 = InjSys_agOfsPhaInjS2 +
          localDTConv_UFix_To_Single_4;
      }

      /* Switch: '<S128>/Switch3' incorporates:
       *  Inport: '<Root>/FRM_bInhFrstInjSTT'
       *  Logic: '<S128>/Logical Operator2'
       *  Logic: '<S128>/Logical Operator3'
       *  MinMax: '<S128>/MinMax2'
       */
      if (!((!InjSpMgt_B.VEMS_vidGET32) || GDGAR_bGetFRM(FRM_FRM_INHFRSTINJSTT)))
      {
        localfractionTmp_0d_0 = rt_MAXf(localDTConv_UFix_To_Single_4,
          localDataTypeConversion6);
      }

      /* MinMax: '<S128>/MinMax1' */
      localfractionTmp_0d = rt_MAXf(localfractionTmp_0d, localfractionTmp_0d_0);

      /* Switch: '<S128>/Switch2' incorporates:
       *  Constant: '<S128>/Constant1'
       *  Constant: '<S128>/InjSys_bAcvTiInjETB_C'
       *  Logic: '<S128>/Logical Operator1'
       *  RelationalOperator: '<S128>/Relational Operator2'
       */
      if (!((locallocalOutDTConv_g > 0) || InjSys_bAcvTiInjETB_C)) {
        locallocalMinMax2_o_idx = localfractionTmp_0d;
        locallocalDataTypeConversion1_i = localfractionTmp_0d;
      }

      /* MinMax: '<S128>/MinMax' */
      InjSys_prm_agEndInjS2SpSTT[0] = rt_MAXf(locallocalMinMax2_o_idx,
        localfractionTmp_0d);
      InjSys_prm_agEndInjS2SpSTT[1] = rt_MAXf(locallocalDataTypeConversion1_i,
        localfractionTmp_0d);

      /* Sum: '<S128>/Sum5' */
      InjSys_prm_agBegInjS2SpSTT[0] = InjSys_prm_agEndInjS2SpSTT[0] +
        InjSys_agWdInjS2Sp;
      InjSys_prm_agBegInjS2SpSTT[1] = InjSys_prm_agEndInjS2SpSTT[1] +
        InjSys_agWdInjS2Sp;

      /* end of Outputs for SubSystem: '<S115>/F02_PhaInjS2STT' */

      /* Outputs for atomic SubSystem: '<S115>/F03_PhaInjS1STT' */

      /* Sum: '<S129>/Sum2' incorporates:
       *  Sum: '<S129>/Sum3'
       */
      locallocalMinMax2_o_idx = (InjSys_agBegInjS1Tmp -
        InjSys_prm_agOfsFrstInjSTT[0]) - InjSys_agWdInjS1Sp;
      locallocalDataTypeConversion1_i = (InjSys_agBegInjS1Tmp -
        InjSys_prm_agOfsFrstInjSTT[1]) - InjSys_agWdInjS1Sp;

      /* Sum: '<S129>/Sum8' */
      localDataTypeConversion6 = InjSys_prm_agBegInjS2SpSTT[0] +
        InjSys_agOfsPhaInjS1;
      localDataTypeConversion5 = InjSys_prm_agBegInjS2SpSTT[1] +
        InjSys_agOfsPhaInjS1;

      /* Switch: '<S129>/Switch2' incorporates:
       *  Constant: '<S129>/Constant1'
       *  Constant: '<S129>/InjSys_bAcvTiInjETB_C'
       *  Logic: '<S129>/Logical Operator1'
       *  RelationalOperator: '<S129>/Relational Operator2'
       */
      if (!((locallocalOutDTConv_d > 0) || InjSys_bAcvTiInjETB_C)) {
        locallocalMinMax2_o_idx = localDataTypeConversion6;
        locallocalDataTypeConversion1_i = localDataTypeConversion5;
      }

      /* MinMax: '<S129>/MinMax' */
      InjSys_prm_agEndInjS1SpSTT[0] = rt_MAXf(locallocalMinMax2_o_idx,
        localDataTypeConversion6);
      InjSys_prm_agEndInjS1SpSTT[1] = rt_MAXf(locallocalDataTypeConversion1_i,
        localDataTypeConversion5);

      /* Sum: '<S129>/Sum1' */
      InjSys_prm_agBegInjS1SpSTT[0] = InjSys_prm_agEndInjS1SpSTT[0] +
        InjSys_agWdInjS1Sp;
      InjSys_prm_agBegInjS1SpSTT[1] = InjSys_prm_agEndInjS1SpSTT[1] +
        InjSys_agWdInjS1Sp;

      /* end of Outputs for SubSystem: '<S115>/F03_PhaInjS1STT' */

      /* Outputs for atomic SubSystem: '<S115>/F04_PhaInjH2STT' */

      /* DataTypeConversion: '<S130>/Data Type Conversion2' incorporates:
       *  Constant: '<S130>/InjSys_agInjH2SpMin_C'
       */
      localfractionTmp_0d = ((Float32)InjSys_agInjH2SpMin_C) * 0.09375F;

      /* Sum: '<S130>/Sum1' incorporates:
       *  Sum: '<S130>/Sum2'
       */
      localDataTypeConversion5 = (InjSys_agBegInjH2Tmp -
        InjSys_prm_agOfsFrstInjSTT[0]) - InjSys_agWdInjH2Sp;
      localDataTypeConversion3_m = (InjSys_agBegInjH2Tmp -
        InjSys_prm_agOfsFrstInjSTT[1]) - InjSys_agWdInjH2Sp;

      /* Sum: '<S130>/Sum8' */
      locallocalMinMax2_o_idx = InjSys_prm_agBegInjS1SpSTT[0] +
        InjSys_agOfsPhaInjH2;
      locallocalDataTypeConversion1_i = InjSys_prm_agBegInjS1SpSTT[1] +
        InjSys_agOfsPhaInjH2;

      /* MinMax: '<S130>/MinMax1' */
      locallocalMinMax2_o_idx = rt_MAXf(localfractionTmp_0d,
        locallocalMinMax2_o_idx);
      localDataTypeConversion6 = rt_MAXf(localfractionTmp_0d,
        locallocalDataTypeConversion1_i);

      /* Switch: '<S130>/Switch2' incorporates:
       *  Constant: '<S130>/Constant1'
       *  Constant: '<S130>/InjSys_bAcvTiInjETB_C'
       *  Logic: '<S130>/Logical Operator1'
       *  RelationalOperator: '<S130>/Relational Operator2'
       */
      if (!((locallocalOutDTConv_j > 0) || InjSys_bAcvTiInjETB_C)) {
        localDataTypeConversion5 = locallocalMinMax2_o_idx;
        localDataTypeConversion3_m = localDataTypeConversion6;
      }

      /* MinMax: '<S130>/MinMax' */
      InjSys_prm_agEndInjH2SpSTT[0] = rt_MAXf(localDataTypeConversion5,
        locallocalMinMax2_o_idx);
      InjSys_prm_agEndInjH2SpSTT[1] = rt_MAXf(localDataTypeConversion3_m,
        localDataTypeConversion6);

      /* Sum: '<S130>/Sum5' */
      InjSys_prm_agBegInjH2SpSTT[0] = InjSys_prm_agEndInjH2SpSTT[0] +
        InjSys_agWdInjH2Sp;
      InjSys_prm_agBegInjH2SpSTT[1] = InjSys_prm_agEndInjH2SpSTT[1] +
        InjSys_agWdInjH2Sp;

      /* end of Outputs for SubSystem: '<S115>/F04_PhaInjH2STT' */

      /* Outputs for atomic SubSystem: '<S115>/F05_PhaInjH1STT' */

      /* Sum: '<S131>/Add' incorporates:
       *  Sum: '<S131>/Sum1'
       */
      locallocalMinMax2_o_idx = (InjSys_agBegInjH1Tmp -
        InjSys_prm_agOfsFrstInjSTT[0]) - InjSys_agWdInjH1Sp;
      locallocalDataTypeConversion1_i = (InjSys_agBegInjH1Tmp -
        InjSys_prm_agOfsFrstInjSTT[1]) - InjSys_agWdInjH1Sp;

      /* Sum: '<S131>/Sum8' */
      localDataTypeConversion6 = InjSys_prm_agBegInjH2SpSTT[0] +
        InjSys_agOfsPhaInjH1;
      localDataTypeConversion5 = InjSys_prm_agBegInjH2SpSTT[1] +
        InjSys_agOfsPhaInjH1;

      /* MinMax: '<S131>/MinMax' */
      InjSys_prm_agEndInjH1SpSTT[0] = rt_MAXf(locallocalMinMax2_o_idx,
        localDataTypeConversion6);
      InjSys_prm_agEndInjH1SpSTT[1] = rt_MAXf(locallocalDataTypeConversion1_i,
        localDataTypeConversion5);

      /* Sum: '<S131>/Sum5' */
      InjSys_prm_agBegInjH1SpSTT[0] = InjSys_prm_agEndInjH1SpSTT[0] +
        InjSys_agWdInjH1Sp;
      InjSys_prm_agBegInjH1SpSTT[1] = InjSys_prm_agEndInjH1SpSTT[1] +
        InjSys_agWdInjH1Sp;

      /* end of Outputs for SubSystem: '<S115>/F05_PhaInjH1STT' */

      /* Outputs for atomic SubSystem: '<S115>/F06_noInCylSTOP' */

      /* SignalConversion: '<S132>/Signal Conversion1' */
      InjSpMgt_B.SignalConversion1 = InjSpMgt_B.VEMS_vidGET5_h;

      /* SignalConversion: '<S132>/Signal Conversion3' */
      InjSys_noCmprCylStopSTT = InjSpMgt_B.VEMS_vidGET4_i;

      /* Switch: '<S132>/Switch2' incorporates:
       *  Constant: '<S132>/Constant2'
       *  RelationalOperator: '<S132>/Relational Operator1'
       */
      if (locallocalOutDTConv_d != 0) {
        locallocalMinMax2_o_idx = InjSys_prm_agBegInjS1SpSTT[0];
        locallocalDataTypeConversion1_i = InjSys_prm_agBegInjS1SpSTT[1];
      } else {
        locallocalMinMax2_o_idx = InjSys_prm_agBegInjS2SpSTT[0];
        locallocalDataTypeConversion1_i = InjSys_prm_agBegInjS2SpSTT[1];
      }

      /* Switch: '<S132>/Switch3' incorporates:
       *  Constant: '<S132>/Constant1'
       *  RelationalOperator: '<S132>/Relational Operator3'
       */
      if (locallocalOutDTConv_j != 0) {
        locallocalMinMax2_o_idx = InjSys_prm_agBegInjH2SpSTT[0];
        locallocalDataTypeConversion1_i = InjSys_prm_agBegInjH2SpSTT[1];
      }

      /* Switch: '<S132>/Switch1' incorporates:
       *  Constant: '<S132>/Constant6'
       *  RelationalOperator: '<S132>/Relational Operator2'
       */
      if (locallocalOutDTConv != 0) {
        InjSys_prm_agFrstInjSTTSp[0] = InjSys_prm_agBegInjH1SpSTT[0];
        InjSys_prm_agFrstInjSTTSp[1] = InjSys_prm_agBegInjH1SpSTT[1];
      } else {
        InjSys_prm_agFrstInjSTTSp[0] = locallocalMinMax2_o_idx;
        InjSys_prm_agFrstInjSTTSp[1] = locallocalDataTypeConversion1_i;
      }

      /* end of Outputs for SubSystem: '<S115>/F06_noInCylSTOP' */
    }

    /* end of Outputs for SubSystem: '<S21>/F03_agInjSp' */

    /* Outputs for atomic SubSystem: '<S21>/F04_DetSatPhaInj' */

    /* Logic: '<S68>/Logical Operator' */
    InjSpMgt_B.LogicalOperator = (((InjSys_bDetPhaInjH1Max ||
      InjSys_bDetPhaInjH2Max) || InjSys_bDetPhaInjS1Max) ||
      InjSys_bDetPhaInjS2Max);

    /* SignalConversion: '<S68>/TmpSignal ConversionAtSignal Conversion2Inport1' */
    InjSpMgt_B.TmpSignalConversionAtSignalConv = InjSys_bDetPhaInjH1Max;

    /* Logic: '<S68>/Logical Operator1' */
    InjSpMgt_B.LogicalOperator1 = (((InjSys_bDetSatInjH1Min ||
      InjSys_bDetSatInjH2Min) || InjSys_bDetSatInjS1Min) ||
      InjSys_bDetSatInjS2Min);

    /* end of Outputs for SubSystem: '<S21>/F04_DetSatPhaInj' */

    /* end of Outputs for SubSystem: '<S18>/F02_TestPha' */
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET2 */
    VEMS_vidGET(EngM_agCkClsInVlvEstimRef1, InjSpMgt_B.VEMS_vidGET2_e);

    /* Outputs for atomic SubSystem: '<S18>/F03_InjPrm' */

    /* If: '<S22>/If1' incorporates:
     *  ActionPort: '<S135>/Action Port'
     *  ActionPort: '<S136>/Action Port'
     *  SubSystem: '<S22>/F01_SpcInjMod'
     *  SubSystem: '<S22>/F02_NoSpcInjMod'
     */
    if (InjSpMgt_B.TmpSignalConversionAtSignalConv) {
      /* SignalConversion: '<S135>/Signal Conversion2' incorporates:
       *  Constant: '<S135>/Constant1'
       */
      InjSys_rInjH1Req = 32768U;

      /* SignalConversion: '<S135>/Signal Conversion3' incorporates:
       *  Constant: '<S135>/Constant4'
       */
      InjSys_rInjH2Req = 0U;

      /* SignalConversion: '<S135>/Signal Conversion4' incorporates:
       *  Constant: '<S135>/Constant4'
       */
      InjSys_rInjS1Req = 0U;

      /* SignalConversion: '<S135>/Signal Conversion5' incorporates:
       *  Constant: '<S135>/Constant4'
       */
      InjSys_rInjS2Req = 0U;

      /* DataTypeConversion: '<S135>/Data Type Conversion1' */
      localExt_nEng_InjSys_nEng_A_1_j = (UInt32)(InjSpMgt_B.VEMS_vidGET2_e +
        896);
      if (localExt_nEng_InjSys_nEng_A_1_j > 65535U) {
        locallocalOutDTConv = MAX_uint16_T;
      } else {
        locallocalOutDTConv = (UInt16)localExt_nEng_InjSys_nEng_A_1_j;
      }

      /* Lookup_n-D: '<S137>/Lookup Table (n-D)' */
      localDataTypeConversion5 = look2_iu16u16lftu16n4If_binlcns
        (InjSys_mAirSpMgt, InjSpMgt_B.VEMS_vidGET10, (&(InjSys_mAirInjSpMgt_A[0])),
         (&(InjSys_nEng_A[0])), (&(InjSys_agBegInjH1SpcInjMod_M[0])),
         &InjSpMgt_ConstP.pooled17[0], 16U);

      /* Lookup_n-D: '<S138>/Lookup Table (n-D)' */
      localDataTypeConversion6 = look2_iu16u16lftu16n4If_binlcns
        (InjSpMgt_B.VEMS_vidGET11, locallocalOutDTConv, (&(InjSys_pFuRailMes_A[0])),
         (&(InjSys_agCkClsInVlvEstimRef1_A[0])),
         (&(InjSys_agEndInjSpcModMaxLP_M[0])), &InjSpMgt_ConstP.pooled17[0], 16U);

      /* RelationalOperator: '<S135>/Relational Operator1' incorporates:
       *  Constant: '<S135>/Ext_agWdTooth_SC1'
       */
      InjSys_bHPFuRail = (InjSpMgt_B.VEMS_vidGET11 > InjSys_pFuRailMin_C);

      /* Switch: '<S135>/Switch1' incorporates:
       *  Constant: '<S135>/Ext_agWdTooth_SC4'
       *  DataTypeConversion: '<S135>/Data Type Conversion4'
       */
      if (!InjSys_bHPFuRail) {
        localDataTypeConversion5 = ((Float32)InjSys_agBegInjSpcModLP_C) *
          0.09375F;
      }

      /* Product: '<S142>/Divide' incorporates:
       *  Constant: '<S135>/Ext_agWdTooth_SC'
       *  DataTypeConversion: '<S135>/Data Type Conversion2'
       *  DataTypeConversion: '<S135>/Data Type Conversion3'
       *  Product: '<S144>/Divide'
       *  Product: '<S145>/Divide'
       *  Sum: '<S135>/Sum'
       */
      localfractionTmp_0d_0 = (((InjSys_facGainInjH1 * InjSys_mFuSpMgt) +
        InjSys_tiInjOfsInjH1) * ((Float32)Ext_agWdTooth_SC)) / (((Float32)
        InjSpMgt_B.VEMS_vidGET12_l) * 3.200000037E-006F);

      /* Outputs for atomic SubSystem: '<S142>/If Action Subsystem3' */

      /* Switch: '<S147>/Switch1' incorporates:
       *  Constant: '<S147>/Constant1'
       *  Constant: '<S147>/Constant2'
       *  Constant: '<S147>/Constant3'
       *  Logic: '<S147>/Logical Operator1'
       *  RelationalOperator: '<S147>/Relational Operator'
       *  RelationalOperator: '<S147>/Relational Operator1'
       *  RelationalOperator: '<S147>/Relational Operator3'
       */
      if (((localfractionTmp_0d_0 != localfractionTmp_0d_0) ||
           (localfractionTmp_0d_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
           localfractionTmp_0d_0)) {
        localfractionTmp_0d_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S142>/If Action Subsystem3' */

      /* Sum: '<S135>/Sum1' */
      localfractionTmp_0d = localDataTypeConversion5 - localfractionTmp_0d_0;

      /* Switch: '<S135>/Switch2' */
      if (InjSys_bHPFuRail) {
        localDataTypeConversion6 = localDTConv_UFix_To_Single_4;
      }

      /* MinMax: '<S135>/MinMax' */
      localfractionTmp_0d = rt_MAXf(localfractionTmp_0d,
        localDataTypeConversion6);

      /* SignalConversion: '<S135>/Signal Conversion6' incorporates:
       *  Constant: '<S141>/offset'
       *  Constant: '<S141>/offset1'
       *  Constant: '<S141>/one_on_slope'
       *  DataTypeConversion: '<S141>/OutDTConv'
       *  Product: '<S141>/Product4'
       *  Sum: '<S141>/Add1'
       *  Sum: '<S141>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * localDataTypeConversion5)
        + 0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agBegInjH1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agBegInjH1Req = 0U;
        }
      } else {
        InjSys_agBegInjH1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S139>/OutDTConv' incorporates:
       *  Constant: '<S139>/offset'
       *  Constant: '<S139>/offset1'
       *  Constant: '<S139>/one_on_slope'
       *  Product: '<S139>/Product4'
       *  Sum: '<S139>/Add1'
       *  Sum: '<S139>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * localfractionTmp_0d) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agEndInjH1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agEndInjH1Req = 0U;
        }
      } else {
        InjSys_agEndInjH1Req = MAX_uint16_T;
      }

      /* Product: '<S143>/Divide' incorporates:
       *  Sum: '<S135>/Sum2'
       */
      localfractionTmp_0d = (localDataTypeConversion5 - localfractionTmp_0d) /
        localfractionTmp_0d_0;

      /* Outputs for atomic SubSystem: '<S143>/If Action Subsystem3' */

      /* Switch: '<S149>/Switch1' incorporates:
       *  Constant: '<S149>/Constant1'
       *  Constant: '<S149>/Constant2'
       *  Constant: '<S149>/Constant3'
       *  Logic: '<S149>/Logical Operator1'
       *  RelationalOperator: '<S149>/Relational Operator'
       *  RelationalOperator: '<S149>/Relational Operator1'
       *  RelationalOperator: '<S149>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        localfractionTmp_0d = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S143>/If Action Subsystem3' */

      /* Switch: '<S135>/Switch3' incorporates:
       *  Constant: '<S135>/InjSys_agInjH2SpcInjMod_C1'
       *  Constant: '<S135>/InjSys_agInjH2SpcInjMod_C2'
       *  Constant: '<S140>/offset'
       *  Constant: '<S140>/offset1'
       *  Constant: '<S140>/one_on_slope'
       *  DataTypeConversion: '<S140>/OutDTConv'
       *  Product: '<S140>/Product4'
       *  Sum: '<S140>/Add1'
       *  Sum: '<S140>/Add2'
       */
      if (InjSys_bInhrMFuReqLPFu_C) {
        InjSys_rMFuReqLPFu = InjSys_rMFuReqLPFu_C;
      } else {
        localDataTypeConversion6 = (32768.0F * localfractionTmp_0d) + 0.5F;
        if (localDataTypeConversion6 < 65536.0F) {
          if (localDataTypeConversion6 >= 0.0F) {
            InjSys_rMFuReqLPFu = (UInt16)localDataTypeConversion6;
          } else {
            InjSys_rMFuReqLPFu = 0U;
          }
        } else {
          InjSys_rMFuReqLPFu = MAX_uint16_T;
        }
      }

      /* SignalConversion: '<S135>/Signal Conversion7' incorporates:
       *  Constant: '<S135>/InjSys_agInjH2SpcInjMod_C'
       */
      InjSys_agBegInjH2Req = InjSys_agInjH2SpcInjMod_C;

      /* SignalConversion: '<S135>/Signal Conversion8' incorporates:
       *  Constant: '<S135>/InjSys_agInjH2SpcInjMod_C'
       */
      InjSys_agEndInjH2Req = InjSys_agInjH2SpcInjMod_C;

      /* SignalConversion: '<S135>/Signal Conversion10' incorporates:
       *  Constant: '<S135>/InjSys_agInjS1SpcInjMod_C'
       */
      InjSys_agEndInjS1Req = InjSys_agInjS1SpcInjMod_C;

      /* SignalConversion: '<S135>/Signal Conversion9' incorporates:
       *  Constant: '<S135>/InjSys_agInjS1SpcInjMod_C'
       */
      InjSys_agBegInjS1Req = InjSys_agInjS1SpcInjMod_C;

      /* SignalConversion: '<S135>/Signal Conversion11' incorporates:
       *  Constant: '<S135>/InjSys_agInjS2SpcInjMod_C'
       */
      InjSys_agBegInjS2Req = InjSys_agInjS2SpcInjMod_C;

      /* SignalConversion: '<S135>/Signal Conversion12' incorporates:
       *  Constant: '<S135>/InjSys_agInjS2SpcInjMod_C'
       */
      InjSys_agEndInjS2Req = InjSys_agInjS2SpcInjMod_C;
    } else {
      /* DataTypeConversion: '<S150>/OutDTConv' incorporates:
       *  Constant: '<S150>/offset'
       *  Constant: '<S150>/offset1'
       *  Constant: '<S150>/one_on_slope'
       *  Product: '<S150>/Product4'
       *  Sum: '<S150>/Add1'
       *  Sum: '<S150>/Add2'
       */
      localDataTypeConversion6 = (32768.0F * InjSys_rInjH1Sp) + 0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_rInjH1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_rInjH1Req = 0U;
        }
      } else {
        InjSys_rInjH1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S151>/OutDTConv' incorporates:
       *  Constant: '<S151>/offset'
       *  Constant: '<S151>/offset1'
       *  Constant: '<S151>/one_on_slope'
       *  Product: '<S151>/Product4'
       *  Sum: '<S151>/Add1'
       *  Sum: '<S151>/Add2'
       */
      localDataTypeConversion6 = (32768.0F * InjSys_rInjH2Sp) + 0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_rInjH2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_rInjH2Req = 0U;
        }
      } else {
        InjSys_rInjH2Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S154>/OutDTConv' incorporates:
       *  Constant: '<S154>/offset'
       *  Constant: '<S154>/offset1'
       *  Constant: '<S154>/one_on_slope'
       *  Product: '<S154>/Product4'
       *  Sum: '<S154>/Add1'
       *  Sum: '<S154>/Add2'
       */
      localDataTypeConversion6 = (32768.0F * InjSys_rInjS1Sp) + 0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_rInjS1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_rInjS1Req = 0U;
        }
      } else {
        InjSys_rInjS1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S155>/OutDTConv' incorporates:
       *  Constant: '<S155>/offset'
       *  Constant: '<S155>/offset1'
       *  Constant: '<S155>/one_on_slope'
       *  Product: '<S155>/Product4'
       *  Sum: '<S155>/Add1'
       *  Sum: '<S155>/Add2'
       */
      localDataTypeConversion6 = (32768.0F * InjSys_rInjS2Sp) + 0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_rInjS2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_rInjS2Req = 0U;
        }
      } else {
        InjSys_rInjS2Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S156>/OutDTConv' incorporates:
       *  Constant: '<S156>/offset'
       *  Constant: '<S156>/offset1'
       *  Constant: '<S156>/one_on_slope'
       *  Product: '<S156>/Product4'
       *  Sum: '<S156>/Add1'
       *  Sum: '<S156>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agBegInjH1Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agBegInjH1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agBegInjH1Req = 0U;
        }
      } else {
        InjSys_agBegInjH1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S157>/OutDTConv' incorporates:
       *  Constant: '<S157>/offset'
       *  Constant: '<S157>/offset1'
       *  Constant: '<S157>/one_on_slope'
       *  Product: '<S157>/Product4'
       *  Sum: '<S157>/Add1'
       *  Sum: '<S157>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agEndInjH1Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agEndInjH1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agEndInjH1Req = 0U;
        }
      } else {
        InjSys_agEndInjH1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S158>/OutDTConv' incorporates:
       *  Constant: '<S158>/offset'
       *  Constant: '<S158>/offset1'
       *  Constant: '<S158>/one_on_slope'
       *  Product: '<S158>/Product4'
       *  Sum: '<S158>/Add1'
       *  Sum: '<S158>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agBegInjH2Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agBegInjH2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agBegInjH2Req = 0U;
        }
      } else {
        InjSys_agBegInjH2Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S159>/OutDTConv' incorporates:
       *  Constant: '<S159>/offset'
       *  Constant: '<S159>/offset1'
       *  Constant: '<S159>/one_on_slope'
       *  Product: '<S159>/Product4'
       *  Sum: '<S159>/Add1'
       *  Sum: '<S159>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agEndInjH2Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agEndInjH2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agEndInjH2Req = 0U;
        }
      } else {
        InjSys_agEndInjH2Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S160>/OutDTConv' incorporates:
       *  Constant: '<S160>/offset'
       *  Constant: '<S160>/offset1'
       *  Constant: '<S160>/one_on_slope'
       *  Product: '<S160>/Product4'
       *  Sum: '<S160>/Add1'
       *  Sum: '<S160>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agBegInjS1Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agBegInjS1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agBegInjS1Req = 0U;
        }
      } else {
        InjSys_agBegInjS1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S161>/OutDTConv' incorporates:
       *  Constant: '<S161>/offset'
       *  Constant: '<S161>/offset1'
       *  Constant: '<S161>/one_on_slope'
       *  Product: '<S161>/Product4'
       *  Sum: '<S161>/Add1'
       *  Sum: '<S161>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agEndInjS1Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agEndInjS1Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agEndInjS1Req = 0U;
        }
      } else {
        InjSys_agEndInjS1Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S152>/OutDTConv' incorporates:
       *  Constant: '<S152>/offset'
       *  Constant: '<S152>/offset1'
       *  Constant: '<S152>/one_on_slope'
       *  Product: '<S152>/Product4'
       *  Sum: '<S152>/Add1'
       *  Sum: '<S152>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agBegInjS2Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agBegInjS2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agBegInjS2Req = 0U;
        }
      } else {
        InjSys_agBegInjS2Req = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S153>/OutDTConv' incorporates:
       *  Constant: '<S153>/offset'
       *  Constant: '<S153>/offset1'
       *  Constant: '<S153>/one_on_slope'
       *  Product: '<S153>/Product4'
       *  Sum: '<S153>/Add1'
       *  Sum: '<S153>/Add2'
       */
      localDataTypeConversion6 = (1.066666698E+001F * InjSys_agEndInjS2Sp) +
        0.5F;
      if (localDataTypeConversion6 < 65536.0F) {
        if (localDataTypeConversion6 >= 0.0F) {
          InjSys_agEndInjS2Req = (UInt16)localDataTypeConversion6;
        } else {
          InjSys_agEndInjS2Req = 0U;
        }
      } else {
        InjSys_agEndInjS2Req = MAX_uint16_T;
      }

      /* Constant: '<S136>/Constant4' */
      InjSys_rMFuReqLPFu = 32768U;
    }

    /* end of Outputs for SubSystem: '<S18>/F03_InjPrm' */
    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvSpcInjModOvlp,
                InjSpMgt_B.TmpSignalConversionAtSignalConv);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_bDetBegInjMaxThd, InjSpMgt_B.LogicalOperator);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_bDetInjOvlp, InjSpMgt_B.LogicalOperator1);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_noInCylStopSTT, InjSpMgt_B.SignalConversion1);
  }

  /* end of Outputs for SubSystem: '<S9>/F01_InjSpMgtFct' */
}

/* Output and update for function-call system: '<S1>/F03_InjSpMgtFct2' */
void InjSpMgt_F03_InjSpMgtFct2(void)
{
  Float32 localDataTypeConversion3_f;
  Float32 localSwitch;
  Float32 localSwitch2_bf;
  Float32 localSum_n;
  Float32 localSwitch_e;
  UInt16 localSwitch1_d;

  /* Outputs for enable SubSystem: '<S11>/F03_InjSpMgtFct2' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S265>/Enable'
   *  RelationalOperator: '<S11>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_pFuSp, InjSpMgt_B.VEMS_vidGET4_e);

    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_pFuCrkSp, InjSpMgt_B.VEMS_vidGET3_c);

    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET */
    VEMS_vidGET(Eng_stEru, InjSpMgt_B.VEMS_vidGET_d);

    /* Outputs for atomic SubSystem: '<S265>/F01_PFuReqRaw' */

    /* Switch: '<S266>/Switch1' incorporates:
     *  Constant: '<S266>/Ext_stRun_SC'
     *  RelationalOperator: '<S266>/Relational Operator2'
     */
    if (InjSpMgt_B.VEMS_vidGET_d == Ext_stRun_SC) {
      localSwitch1_d = InjSpMgt_B.VEMS_vidGET4_e;
    } else {
      localSwitch1_d = InjSpMgt_B.VEMS_vidGET3_c;
    }

    /* DataTypeConversion: '<S266>/Data Type Conversion3' */
    localDataTypeConversion3_f = ((Float32)localSwitch1_d) * 781.25F;

    /* UnitDelay: '<S277>/Unit Delay' */
    localSwitch = InjSpMgt_DWork.UnitDelay_DSTATE;

    /* Switch: '<S271>/Switch' incorporates:
     *  UnitDelay: '<S278>/Unit Delay'
     */
    if (!InjSpMgt_DWork.UnitDelay_DSTATE_e) {
      localSwitch = localDataTypeConversion3_f;
    }

    /* Sum: '<S268>/Sum' */
    localSum_n = localDataTypeConversion3_f - localSwitch;

    /* Product: '<S272>/Divide' incorporates:
     *  Constant: '<S266>/InjSys_pFuGrdPos_C'
     *  Constant: '<S266>/constant'
     *  DataTypeConversion: '<S266>/Data Type Conversion12'
     */
    localSwitch2_bf = ((Float32)InjSys_pFuGrdPos_C) * 781.25F;

    /* Product: '<S273>/Divide' incorporates:
     *  Constant: '<S266>/InjSys_pFuGrdNeg_C'
     *  Constant: '<S266>/constant'
     *  Constant: '<S266>/constant1'
     *  DataTypeConversion: '<S266>/Data Type Conversion1'
     *  Product: '<S269>/Divide'
     */
    localSwitch_e = (((Float32)InjSys_pFuGrdNeg_C) * 781.25F) * -1.0F;

    /* Switch: '<S276>/Switch' incorporates:
     *  RelationalOperator: '<S276>/UpperRelop'
     */
    if (!(localSum_n < localSwitch_e)) {
      localSwitch_e = localSum_n;
    }

    /* Switch: '<S276>/Switch2' incorporates:
     *  RelationalOperator: '<S276>/LowerRelop1'
     */
    if (!(localSum_n > localSwitch2_bf)) {
      localSwitch2_bf = localSwitch_e;
    }

    /* Switch: '<S268>/Switch' incorporates:
     *  Constant: '<S266>/InjSys_bEnaPresFuGrdLim_C'
     *  Sum: '<S268>/Sum2'
     */
    if (InjSys_bEnaPresFuGrdLim_C) {
      InjSys_pFuReqRaw = localSwitch2_bf + localSwitch;
    } else {
      InjSys_pFuReqRaw = localDataTypeConversion3_f;
    }

    /* Update for UnitDelay: '<S277>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE = InjSys_pFuReqRaw;

    /* Update for UnitDelay: '<S278>/Unit Delay' incorporates:
     *  Constant: '<S271>/Constant3'
     */
    InjSpMgt_DWork.UnitDelay_DSTATE_e = TRUE;

    /* end of Outputs for SubSystem: '<S265>/F01_PFuReqRaw' */
    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, InjSpMgt_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_pFuReq, InjSys_pFuReqPrev);

    /* Outputs for atomic SubSystem: '<S265>/F02_PfuFilt' */

    /* Switch: '<S267>/Switch1' incorporates:
     *  Constant: '<S267>/InjSys_pFuReqMaxDft_C'
     *  Constant: '<S267>/InjSys_pFuReqMax_C'
     *  Inport: '<Root>/FRM_bLimFuRailPfu'
     */
    if (GDGAR_bGetFRM(FRM_FRM_LIMFURAILPFU)) {
      localSwitch1_d = InjSys_pFuReqMaxDft_C;
    } else {
      localSwitch1_d = InjSys_pFuReqMax_C;
    }

    /* DataTypeConversion: '<S283>/Conversion' */
    localDataTypeConversion3_f = ((Float32)localSwitch1_d) * 781.25F;

    /* DataTypeConversion: '<S284>/Conversion' incorporates:
     *  Constant: '<S267>/InjSys_pFuReqMin_C'
     */
    localSwitch = ((Float32)InjSys_pFuReqMin_C) * 781.25F;

    /* Switch: '<S285>/Switch' incorporates:
     *  RelationalOperator: '<S285>/UpperRelop'
     */
    if (!(InjSys_pFuReqRaw < localSwitch)) {
      localSwitch = InjSys_pFuReqRaw;
    }

    /* Switch: '<S285>/Switch2' incorporates:
     *  RelationalOperator: '<S285>/LowerRelop1'
     */
    if (!(InjSys_pFuReqRaw > localDataTypeConversion3_f)) {
      localDataTypeConversion3_f = localSwitch;
    }

    /* DataTypeConversion: '<S267>/Data Type Conversion2' */
    localSwitch = ((Float32)InjSys_pFuReqPrev) * 781.25F;

    /* Lookup_n-D: '<S281>/Lookup Table (n-D)' */
    InjSys_rFilGainPFuReq = look1_iu16lftu8n8If_binlcns(InjSpMgt_B.VEMS_vidGET1,
      (&(InjSys_nEng_A[0])), (&(InjSys_rFilGainPFuReq_T[0])), 15U);

    /* DataTypeConversion: '<S282>/OutDTConv' incorporates:
     *  Constant: '<S282>/offset'
     *  Constant: '<S282>/offset1'
     *  Constant: '<S282>/one_on_slope'
     *  Product: '<S282>/Product4'
     *  Product: '<S286>/Divide'
     *  Saturate: '<S280>/Saturation [0-1]'
     *  Sum: '<S280>/Sum'
     *  Sum: '<S280>/Sum1'
     *  Sum: '<S282>/Add1'
     *  Sum: '<S282>/Add2'
     */
    localDataTypeConversion3_f = ((((localDataTypeConversion3_f - localSwitch) *
      rt_SATURATE(InjSys_rFilGainPFuReq, 0.0F, 1.0F)) + localSwitch) *
      1.279999968E-003F) + 0.5F;
    if (localDataTypeConversion3_f < 65536.0F) {
      if (localDataTypeConversion3_f >= 0.0F) {
        InjSpMgt_B.OutDTConv = (UInt16)localDataTypeConversion3_f;
      } else {
        InjSpMgt_B.OutDTConv = 0U;
      }
    } else {
      InjSpMgt_B.OutDTConv = MAX_uint16_T;
    }

    /* end of Outputs for SubSystem: '<S265>/F02_PfuFilt' */
    /* S-Function "vems_vidGET" Block: <S265>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pFuRailSplMes, InjSpMgt_B.VEMS_vidGET2);

    /* DataTypeConversion Block: '<S267>/Data Type Conversion3'
     *
     * Regarding '<S267>/Data Type Conversion3':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidSET" Block: <S265>/VEMS_vidSET */
    VEMS_vidSET(InjSys_pFuReq, InjSpMgt_B.OutDTConv);
  }

  /* end of Outputs for SubSystem: '<S11>/F03_InjSpMgtFct2' */
}

/* Output and update for function-call system: '<S10>/F02_SdlEveClcn_InjSpMgt' */
void InjSpMg_F02_SdlEveClcn_InjSpMgt(void)
{
  UInt32 localAdd_f;
  Boolean localRelationalOperator5_b;
  UInt32 localAdd_b;
  UInt32 localAdd_ng;
  UInt32 localAdd_p;
  UInt8 localSwitch1_bj;
  UInt16 localSwitch6_i;
  UInt16 localSwitch10;
  UInt16 localSwitch5_l;
  UInt16 localAssignment_k[6];
  UInt16 localAssignment_hd[6];
  UInt16 localAssignment_bf[6];
  UInt16 localAssignment_oi[6];
  UInt16 localAssignment_h[6];
  UInt16 localAssignment[6];
  UInt16 localAssignment_e[6];
  UInt16 localAssignment_b[6];
  UInt16 localAssignment_l[6];
  UInt16 localAssignment_d[6];
  UInt16 localAssignment_nm[6];
  UInt16 localAssignment_o[6];
  UInt16 localAssignment_m[6];
  UInt16 localAssignment_n[6];
  UInt16 localAssignment_c[6];
  UInt16 localAssignment_or[6];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_f_idx;
  UInt16 locallocalOutDTConv_f_idx_0;
  UInt16 locallocalOutDTConv_k_idx;

  /* Outputs for enable SubSystem: '<S168>/F02_SdlEveClcn_InjSpMgt' incorporates:
   *  Constant: '<S168>/Constant1'
   *  Constant: '<S168>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S207>/Enable'
   *  RelationalOperator: '<S168>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* DataTypeConversion: '<S207>/Data Type Conversion1' */
    localAdd_f = InjSys_noCmprCylStopSTT;

    /* DataTypeConversion: '<S207>/Data Type Conversion10' */
    localAdd_b = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH1Req * 3)) >>
      1));
    if (localAdd_b > 65535U) {
      localSwitch6_i = MAX_uint16_T;
    } else {
      localSwitch6_i = (UInt16)localAdd_b;
    }

    /* DataTypeConversion: '<S207>/Data Type Conversion11' */
    localAdd_b = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH2Req * 3)) >>
      1));
    if (localAdd_b > 65535U) {
      localSwitch10 = MAX_uint16_T;
    } else {
      localSwitch10 = (UInt16)localAdd_b;
    }

    /* DataTypeConversion: '<S207>/Data Type Conversion12' */
    localAdd_b = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH2Req * 3)) >>
      1));
    if (localAdd_b > 65535U) {
      locallocalOutDTConv_k_idx = MAX_uint16_T;
    } else {
      locallocalOutDTConv_k_idx = (UInt16)localAdd_b;
    }

    /* DataTypeConversion: '<S207>/Data Type Conversion2' */
    localAdd_b = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH1Req * 3)) >>
      1));
    if (localAdd_b > 65535U) {
      localSwitch5_l = MAX_uint16_T;
    } else {
      localSwitch5_l = (UInt16)localAdd_b;
    }

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, InjSpMgt_B.VEMS_vidGET1_a);

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, InjSpMgt_B.VEMS_vidGET2_d);

    /* Switch: '<S207>/Switch1' */
    if (InjSys_bDetCylInjSp) {
      localSwitch1_bj = InjSpMgt_B.VEMS_vidGET1_a;
    } else {
      localSwitch1_bj = InjSpMgt_B.VEMS_vidGET2_d;
    }

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_stEng, InjSpMgt_B.VEMS_vidGET_b);

    /* RelationalOperator: '<S207>/Relational Operator5' incorporates:
     *  Constant: '<S207>/Ext_stRun_SC'
     */
    localRelationalOperator5_b = (InjSpMgt_B.VEMS_vidGET_b != 6);

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_noInCylStopSTT, InjSpMgt_B.VEMS_vidGET3_lr);

    /* Switch: '<S207>/Switch2' */
    if (localRelationalOperator5_b) {
      InjSys_noCylInjSp = localSwitch1_bj;
    } else {
      InjSys_noCylInjSp = InjSpMgt_B.VEMS_vidGET3_lr;
    }

    /* DataTypeConversion: '<S207>/Data Type Conversion4' */
    localAdd_b = InjSys_noCylInjSp;

    /* Sum: '<S208>/Add' incorporates:
     *  Constant: '<S208>/Constant1'
     */
    localAdd_ng = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_rMFuReqLPFu, 6, InjSys_prm_rMFuReqLPFuPrev);

    /* DataTypeDuplicate Block: '<S208>/Data Type Duplicate'
     *
     * Regarding '<S208>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S208>/Data Type Duplicate1'
     *
     * Regarding '<S208>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S208>/Assignment' incorporates:
     *  Constant: '<S208>/Constant'
     *  MinMax: '<S208>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_p[(locali)] = InjSys_prm_rMFuReqLPFuPrev[(locali)];
    }

    InjSpMgt_B.Assignment_p[rt_MIN(localAdd_ng, 5U)] = InjSys_rMFuReqLPFu;

    /* Sum: '<S209>/Add' incorporates:
     *  Constant: '<S209>/Constant1'
     */
    localAdd_ng = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH1ReqCyl, 6, InjSys_prm_rInjH1ReqCylPrev);

    /* DataTypeDuplicate Block: '<S209>/Data Type Duplicate'
     *
     * Regarding '<S209>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S209>/Data Type Duplicate1'
     *
     * Regarding '<S209>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S209>/Assignment' incorporates:
     *  Constant: '<S209>/Constant'
     *  MinMax: '<S209>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_j[(locali)] = InjSys_prm_rInjH1ReqCylPrev[(locali)];
    }

    InjSpMgt_B.Assignment_j[rt_MIN(localAdd_ng, 5U)] = InjSys_rInjH1Req;

    /* Sum: '<S210>/Add' incorporates:
     *  Constant: '<S210>/Constant1'
     */
    localAdd_ng = localAdd_f - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6,
                       InjSys_prm_agBegInjH2CylPrev);

    /* DataTypeDuplicate Block: '<S225>/Data Type Duplicate'
     *
     * Regarding '<S225>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S225>/Data Type Duplicate1'
     *
     * Regarding '<S225>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S236>/OutDTConv' incorporates:
     *  Constant: '<S236>/offset'
     *  Constant: '<S236>/offset1'
     *  Constant: '<S236>/one_on_slope'
     *  Product: '<S236>/Product4'
     *  Sum: '<S236>/Add1'
     *  Sum: '<S236>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agBegInjH2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agBegInjH2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx_0 = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch7' */
    if (!localRelationalOperator5_b) {
      locallocalOutDTConv_k_idx = locallocalOutDTConv_f_idx;
    }

    /* Sum: '<S225>/Add' incorporates:
     *  Constant: '<S225>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* Assignment: '<S225>/Assignment' incorporates:
     *  Constant: '<S225>/Constant'
     *  MinMax: '<S225>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_k[locali] = InjSys_prm_agBegInjH2CylPrev[(locali)];
    }

    localAssignment_k[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_k_idx;

    /* Assignment: '<S210>/Assignment' incorporates:
     *  Constant: '<S210>/Constant'
     *  MinMax: '<S210>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_hd[locali] = localAssignment_k[locali];
    }

    localAssignment_hd[(SInt32)rt_MIN(localAdd_ng, 5U)] =
      locallocalOutDTConv_f_idx_0;

    /* Sum: '<S211>/Add' incorporates:
     *  Constant: '<S211>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6,
                       InjSys_prm_agEndInjH2CylPrev);

    /* DataTypeDuplicate Block: '<S211>/Data Type Duplicate'
     *
     * Regarding '<S211>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S211>/Data Type Duplicate1'
     *
     * Regarding '<S211>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S235>/OutDTConv' incorporates:
     *  Constant: '<S235>/offset'
     *  Constant: '<S235>/offset1'
     *  Constant: '<S235>/one_on_slope'
     *  Product: '<S235>/Product4'
     *  Sum: '<S235>/Add1'
     *  Sum: '<S235>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agEndInjH2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agEndInjH2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx_0 = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch10' */
    if (!localRelationalOperator5_b) {
      localSwitch10 = locallocalOutDTConv_f_idx;
    }

    /* Assignment: '<S211>/Assignment' incorporates:
     *  Constant: '<S211>/Constant'
     *  MinMax: '<S211>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_bf[locali] = InjSys_prm_agEndInjH2CylPrev[(locali)];
    }

    localAssignment_bf[(SInt32)rt_MIN(localAdd_p, 5U)] = localSwitch10;

    /* Sum: '<S212>/Add' incorporates:
     *  Constant: '<S212>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S212>/Assignment' incorporates:
     *  Constant: '<S212>/Constant'
     *  MinMax: '<S212>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_oi[locali] = localAssignment_bf[locali];
    }

    localAssignment_oi[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_f_idx_0;

    /* Sum: '<S213>/Add' incorporates:
     *  Constant: '<S213>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6,
                       InjSys_prm_agBegInjS1CylPrev);

    /* DataTypeDuplicate Block: '<S213>/Data Type Duplicate'
     *
     * Regarding '<S213>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S213>/Data Type Duplicate1'
     *
     * Regarding '<S213>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S234>/OutDTConv' incorporates:
     *  Constant: '<S234>/offset'
     *  Constant: '<S234>/offset1'
     *  Constant: '<S234>/one_on_slope'
     *  Product: '<S234>/Product4'
     *  Sum: '<S234>/Add1'
     *  Sum: '<S234>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_k_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_k_idx = 0U;
      }
    } else {
      locallocalOutDTConv_k_idx = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch11' */
    if (localRelationalOperator5_b) {
      locallocalOutDTConv_k_idx = InjSys_agBegInjS1Req;
    }

    /* Assignment: '<S213>/Assignment' incorporates:
     *  Constant: '<S213>/Constant'
     *  MinMax: '<S213>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_h[locali] = InjSys_prm_agBegInjS1CylPrev[(locali)];
    }

    localAssignment_h[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_k_idx;

    /* Sum: '<S214>/Add' incorporates:
     *  Constant: '<S214>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S214>/Assignment' incorporates:
     *  Constant: '<S214>/Constant'
     *  MinMax: '<S214>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = localAssignment_h[locali];
    }

    localAssignment[(SInt32)rt_MIN(localAdd_p, 5U)] = locallocalOutDTConv_f_idx;

    /* Sum: '<S215>/Add' incorporates:
     *  Constant: '<S215>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6,
                       InjSys_prm_agEndInjS1CylPrev);

    /* DataTypeDuplicate Block: '<S215>/Data Type Duplicate'
     *
     * Regarding '<S215>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S215>/Data Type Duplicate1'
     *
     * Regarding '<S215>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S233>/OutDTConv' incorporates:
     *  Constant: '<S233>/offset'
     *  Constant: '<S233>/offset1'
     *  Constant: '<S233>/one_on_slope'
     *  Product: '<S233>/Product4'
     *  Sum: '<S233>/Add1'
     *  Sum: '<S233>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_k_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_k_idx = 0U;
      }
    } else {
      locallocalOutDTConv_k_idx = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx_0 = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch14' */
    if (localRelationalOperator5_b) {
      locallocalOutDTConv_k_idx = InjSys_agEndInjS1Req;
    }

    /* Assignment: '<S215>/Assignment' incorporates:
     *  Constant: '<S215>/Constant'
     *  MinMax: '<S215>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_e[locali] = InjSys_prm_agEndInjS1CylPrev[(locali)];
    }

    localAssignment_e[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_k_idx;

    /* Sum: '<S216>/Add' incorporates:
     *  Constant: '<S216>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S216>/Assignment' incorporates:
     *  Constant: '<S216>/Constant'
     *  MinMax: '<S216>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_b[locali] = localAssignment_e[locali];
    }

    localAssignment_b[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_f_idx_0;

    /* Sum: '<S217>/Add' incorporates:
     *  Constant: '<S217>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6,
                       InjSys_prm_agBegInjS2CylPrev);

    /* DataTypeDuplicate Block: '<S217>/Data Type Duplicate'
     *
     * Regarding '<S217>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S217>/Data Type Duplicate1'
     *
     * Regarding '<S217>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S232>/OutDTConv' incorporates:
     *  Constant: '<S232>/offset'
     *  Constant: '<S232>/offset1'
     *  Constant: '<S232>/one_on_slope'
     *  Product: '<S232>/Product4'
     *  Sum: '<S232>/Add1'
     *  Sum: '<S232>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_k_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_k_idx = 0U;
      }
    } else {
      locallocalOutDTConv_k_idx = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch16' */
    if (localRelationalOperator5_b) {
      locallocalOutDTConv_k_idx = InjSys_agBegInjS2Req;
    }

    /* Assignment: '<S217>/Assignment' incorporates:
     *  Constant: '<S217>/Constant'
     *  MinMax: '<S217>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_l[locali] = InjSys_prm_agBegInjS2CylPrev[(locali)];
    }

    localAssignment_l[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_k_idx;

    /* Sum: '<S218>/Add' incorporates:
     *  Constant: '<S218>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S218>/Assignment' incorporates:
     *  Constant: '<S218>/Constant'
     *  MinMax: '<S218>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_d[locali] = localAssignment_l[locali];
    }

    localAssignment_d[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_f_idx;

    /* Sum: '<S219>/Add' incorporates:
     *  Constant: '<S219>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6,
                       InjSys_prm_agEndInjH1CylPrev);

    /* DataTypeDuplicate Block: '<S219>/Data Type Duplicate'
     *
     * Regarding '<S219>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S219>/Data Type Duplicate1'
     *
     * Regarding '<S219>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S230>/OutDTConv' incorporates:
     *  Constant: '<S230>/offset'
     *  Constant: '<S230>/offset1'
     *  Constant: '<S230>/one_on_slope'
     *  Product: '<S230>/Product4'
     *  Sum: '<S230>/Add1'
     *  Sum: '<S230>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agEndInjH1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agEndInjH1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx_0 = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch6' */
    if (!localRelationalOperator5_b) {
      localSwitch6_i = locallocalOutDTConv_f_idx;
    }

    /* Assignment: '<S219>/Assignment' incorporates:
     *  Constant: '<S219>/Constant'
     *  MinMax: '<S219>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_nm[locali] = InjSys_prm_agEndInjH1CylPrev[(locali)];
    }

    localAssignment_nm[(SInt32)rt_MIN(localAdd_p, 5U)] = localSwitch6_i;

    /* Sum: '<S220>/Add' incorporates:
     *  Constant: '<S220>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET16 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6,
                       InjSys_prm_agEndInjS2CylPrev);

    /* DataTypeDuplicate Block: '<S220>/Data Type Duplicate'
     *
     * Regarding '<S220>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S220>/Data Type Duplicate1'
     *
     * Regarding '<S220>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S231>/OutDTConv' incorporates:
     *  Constant: '<S231>/offset'
     *  Constant: '<S231>/offset1'
     *  Constant: '<S231>/one_on_slope'
     *  Product: '<S231>/Product4'
     *  Sum: '<S231>/Add1'
     *  Sum: '<S231>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_k_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_k_idx = 0U;
      }
    } else {
      locallocalOutDTConv_k_idx = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch17' */
    if (localRelationalOperator5_b) {
      locallocalOutDTConv_k_idx = InjSys_agEndInjS2Req;
    }

    /* Assignment: '<S220>/Assignment' incorporates:
     *  Constant: '<S220>/Constant'
     *  MinMax: '<S220>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_o[locali] = InjSys_prm_agEndInjS2CylPrev[(locali)];
    }

    localAssignment_o[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_k_idx;

    /* Sum: '<S221>/Add' incorporates:
     *  Constant: '<S221>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S221>/Assignment' incorporates:
     *  Constant: '<S221>/Constant'
     *  MinMax: '<S221>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_m[locali] = localAssignment_o[locali];
      localAssignment_n[locali] = localAssignment_nm[locali];
    }

    localAssignment_m[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_f_idx;

    /* Sum: '<S222>/Add' incorporates:
     *  Constant: '<S222>/Constant1'
     */
    localAdd_p = localAdd_f - 1U;

    /* Assignment: '<S222>/Assignment' incorporates:
     *  Constant: '<S222>/Constant'
     *  MinMax: '<S222>/MinMax'
     */
    localAssignment_n[(SInt32)rt_MIN(localAdd_p, 5U)] =
      locallocalOutDTConv_f_idx_0;

    /* Sum: '<S223>/Add' incorporates:
     *  Constant: '<S223>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6,
                       InjSys_prm_agBegInjH1CylPrev);

    /* DataTypeDuplicate Block: '<S223>/Data Type Duplicate'
     *
     * Regarding '<S223>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S223>/Data Type Duplicate1'
     *
     * Regarding '<S223>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S229>/OutDTConv' incorporates:
     *  Constant: '<S229>/offset'
     *  Constant: '<S229>/offset1'
     *  Constant: '<S229>/one_on_slope'
     *  Product: '<S229>/Product4'
     *  Sum: '<S229>/Add1'
     *  Sum: '<S229>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agBegInjH1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agBegInjH1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_f_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_f_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_f_idx_0 = MAX_uint16_T;
    }

    /* Switch: '<S207>/Switch5' */
    if (!localRelationalOperator5_b) {
      localSwitch5_l = locallocalOutDTConv_f_idx;
    }

    /* Assignment: '<S223>/Assignment' incorporates:
     *  Constant: '<S223>/Constant'
     *  MinMax: '<S223>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_c[locali] = InjSys_prm_agBegInjH1CylPrev[(locali)];
    }

    localAssignment_c[(SInt32)rt_MIN(localAdd_p, 5U)] = localSwitch5_l;

    /* Sum: '<S224>/Add' incorporates:
     *  Constant: '<S224>/Constant1'
     */
    localAdd_f--;

    /* Assignment: '<S224>/Assignment' incorporates:
     *  Constant: '<S224>/Constant'
     *  MinMax: '<S224>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_or[locali] = localAssignment_c[locali];
    }

    localAssignment_or[(SInt32)rt_MIN(localAdd_f, 5U)] =
      locallocalOutDTConv_f_idx_0;

    /* Sum: '<S226>/Add' incorporates:
     *  Constant: '<S226>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS2ReqCyl, 6, InjSys_prm_rInjS2ReqCylPrev);

    /* DataTypeDuplicate Block: '<S226>/Data Type Duplicate'
     *
     * Regarding '<S226>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S226>/Data Type Duplicate1'
     *
     * Regarding '<S226>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S226>/Assignment' incorporates:
     *  Constant: '<S226>/Constant'
     *  MinMax: '<S226>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_a[(locali)] = InjSys_prm_rInjS2ReqCylPrev[(locali)];
    }

    InjSpMgt_B.Assignment_a[rt_MIN(localAdd_p, 5U)] = InjSys_rInjS2Req;

    /* Sum: '<S227>/Add' incorporates:
     *  Constant: '<S227>/Constant1'
     */
    localAdd_p = localAdd_b - 1U;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS1ReqCyl, 6, InjSys_prm_rInjS1ReqCylPrev);

    /* DataTypeDuplicate Block: '<S227>/Data Type Duplicate'
     *
     * Regarding '<S227>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S227>/Data Type Duplicate1'
     *
     * Regarding '<S227>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S227>/Assignment' incorporates:
     *  Constant: '<S227>/Constant'
     *  MinMax: '<S227>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_jh[(locali)] = InjSys_prm_rInjS1ReqCylPrev[(locali)];
    }

    InjSpMgt_B.Assignment_jh[rt_MIN(localAdd_p, 5U)] = InjSys_rInjS1Req;

    /* Sum: '<S228>/Add' incorporates:
     *  Constant: '<S228>/Constant1'
     */
    localAdd_b--;

    /* S-Function "vems_vidGET" Block: <S207>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH2ReqCyl, 6, InjSys_prm_rInjH2ReqCylPrev);

    /* DataTypeDuplicate Block: '<S228>/Data Type Duplicate'
     *
     * Regarding '<S228>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S228>/Data Type Duplicate1'
     *
     * Regarding '<S228>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S228>/Assignment' incorporates:
     *  Constant: '<S228>/Constant'
     *  MinMax: '<S228>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_f[(locali)] = InjSys_prm_rInjH2ReqCylPrev[(locali)];

      /* Switch: '<S207>/Switch12' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch12_f[(locali)] = localAssignment_h[locali];
      } else {
        InjSpMgt_B.Switch12_f[(locali)] = localAssignment[locali];
      }

      /* Switch: '<S207>/Switch13' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch13_o[(locali)] = localAssignment_e[locali];
      } else {
        InjSpMgt_B.Switch13_o[(locali)] = localAssignment_b[locali];
      }

      /* Switch: '<S207>/Switch15' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch15[(locali)] = localAssignment_l[locali];
      } else {
        InjSpMgt_B.Switch15[(locali)] = localAssignment_d[locali];
      }

      /* Switch: '<S207>/Switch18' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch18[(locali)] = localAssignment_o[locali];
      } else {
        InjSpMgt_B.Switch18[(locali)] = localAssignment_m[locali];
      }

      /* Switch: '<S207>/Switch3' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch3_f[(locali)] = localAssignment_c[locali];
      } else {
        InjSpMgt_B.Switch3_f[(locali)] = localAssignment_or[locali];
      }

      /* Switch: '<S207>/Switch4' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch4_b[(locali)] = localAssignment_nm[locali];
      } else {
        InjSpMgt_B.Switch4_b[(locali)] = localAssignment_n[locali];
      }

      /* Switch: '<S207>/Switch8' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch8_e[(locali)] = localAssignment_k[locali];
      } else {
        InjSpMgt_B.Switch8_e[(locali)] = localAssignment_hd[locali];
      }

      /* Switch: '<S207>/Switch9' */
      if (localRelationalOperator5_b) {
        InjSpMgt_B.Switch9_p[(locali)] = localAssignment_bf[locali];
      } else {
        InjSpMgt_B.Switch9_p[(locali)] = localAssignment_oi[locali];
      }
    }

    InjSpMgt_B.Assignment_f[rt_MIN(localAdd_b, 5U)] = InjSys_rInjH2Req;

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, InjSpMgt_B.Switch3_f);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, InjSpMgt_B.Switch8_e);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET10 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS1ReqCyl, 6, InjSpMgt_B.Assignment_jh);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET11 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS2ReqCyl, 6, InjSpMgt_B.Assignment_a);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET12 */
    VEMS_vidSET1DArray(InjSys_prm_rMFuReqLPFu, 6, InjSpMgt_B.Assignment_p);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, InjSpMgt_B.Switch12_f);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, InjSpMgt_B.Switch15);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, InjSpMgt_B.Switch4_b);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, InjSpMgt_B.Switch9_p);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, InjSpMgt_B.Switch13_o);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, InjSpMgt_B.Switch18);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH1ReqCyl, 6, InjSpMgt_B.Assignment_j);

    /* S-Function "vems_vidSET" Block: <S207>/VEMS_vidSET9 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH2ReqCyl, 6, InjSpMgt_B.Assignment_f);
  }

  /* end of Outputs for SubSystem: '<S168>/F02_SdlEveClcn_InjSpMgt' */
}

/* Output and update for function-call system: '<S13>/F01_InhFrstInjCkOn' */
void InjSpMgt_F01_InhFrstInjCkOn(void)
{
  Float32 localSwitch8_k;
  SInt32 localSwitch5_o;
  Boolean localLogicalOperator4_e;
  SInt32 localAdd1_a5;
  SInt32 localAdd2_g;
  SInt32 localAdd4_g;
  SInt32 localAdd6_o;

  /* Outputs for enable SubSystem: '<S289>/F01_InhFrstInjCkOn' incorporates:
   *  Constant: '<S289>/Constant1'
   *  Constant: '<S289>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S291>/Enable'
   *  RelationalOperator: '<S289>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S291>/VEMS_vidGET1 */
    VEMS_vidGET(Sync_agEng, InjSpMgt_B.VEMS_vidGET1_jg);

    /* DataTypeConversion: '<S291>/Data Type Conversion' */
    localSwitch8_k = ((Float32)InjSpMgt_B.VEMS_vidGET1_jg) * 6.0F;

    /* Sum: '<S291>/Add1' incorporates:
     *  Constant: '<S291>/Constant5'
     */
    localAdd1_a5 = 720 - ((SInt32)localSwitch8_k);

    /* Sum: '<S291>/Add2' incorporates:
     *  Constant: '<S291>/Constant7'
     */
    localAdd2_g = 480 - ((SInt32)localSwitch8_k);

    /* Sum: '<S291>/Add3' incorporates:
     *  Constant: '<S291>/Constant8'
     */
    localSwitch5_o = 240 - ((SInt32)localSwitch8_k);

    /* Sum: '<S291>/Add4' incorporates:
     *  Constant: '<S291>/Constant16'
     */
    localAdd4_g = 720 - ((SInt32)localSwitch8_k);

    /* Sum: '<S291>/Add6' incorporates:
     *  Constant: '<S291>/Constant17'
     */
    localAdd6_o = 480 - ((SInt32)localSwitch8_k);

    /* Sum: '<S291>/Add7' incorporates:
     *  Constant: '<S291>/Constant18'
     */
    localSwitch8_k = 240.0F - localSwitch8_k;

    /* S-Function "vems_vidGET" Block: <S291>/VEMS_vidGET2 */
    VEMS_vidGET(Sync_bEngPosOk, InjSpMgt_B.VEMS_vidGET2_n);

    /* Logic: '<S291>/Logical Operator4' incorporates:
     *  Inport: '<Root>/FRM_bInhFrstInjSTT'
     */
    localLogicalOperator4_e = !GDGAR_bGetFRM(FRM_FRM_INHFRSTINJSTT);

    /* S-Function "vems_vidGET" Block: <S291>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSpMgt_B.VEMS_vidGET_fh);

    /* Logic: '<S291>/Logical Operator3' */
    localLogicalOperator4_e = ((InjSpMgt_B.VEMS_vidGET2_n &&
      (localLogicalOperator4_e)) && InjSpMgt_B.VEMS_vidGET_fh);

    /* Math: '<S291>/Math Function1' incorporates:
     *  Constant: '<S291>/Constant1'
     */
    localSwitch8_k = rt_mod32(localSwitch8_k, 720.0F);

    /* S-Function "vems_vidGET" Block: <S291>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_noInCylStopSTT, InjSpMgt_B.VEMS_vidGET3_n);

    /* Switch: '<S291>/Switch6' incorporates:
     *  Constant: '<S291>/Constant10'
     *  Constant: '<S291>/Constant9'
     *  RelationalOperator: '<S291>/Relational Operator6'
     *  Sum: '<S291>/Add5'
     */
    if (localSwitch5_o < 0) {
      localSwitch5_o += 720;
    }

    /* Switch: '<S291>/Switch7' incorporates:
     *  Constant: '<S291>/Constant12'
     *  RelationalOperator: '<S291>/Relational Operator8'
     */
    if (InjSpMgt_B.VEMS_vidGET3_n == 2) {
      localSwitch5_o = localAdd2_g;
    }

    /* Switch: '<S291>/Switch5' incorporates:
     *  Constant: '<S291>/Constant11'
     *  RelationalOperator: '<S291>/Relational Operator7'
     */
    if (InjSpMgt_B.VEMS_vidGET3_n == 1) {
      localSwitch5_o = localAdd1_a5;
    }

    /* Switch: '<S291>/Switch10' incorporates:
     *  Constant: '<S291>/Constant15'
     *  RelationalOperator: '<S291>/Relational Operator9'
     */
    if (InjSys_noCmprCylStopSTT == 2) {
      localSwitch8_k = (Float32)localAdd6_o;
    }

    /* Switch: '<S291>/Switch8' incorporates:
     *  Constant: '<S291>/Constant14'
     *  RelationalOperator: '<S291>/Relational Operator5'
     */
    if (InjSys_noCmprCylStopSTT == 1) {
      localSwitch8_k = (Float32)localAdd4_g;
    }

    /* Switch: '<S291>/Switch3' incorporates:
     *  Constant: '<S291>/InjSys_agInj2CrkSpDft_C4'
     *  RelationalOperator: '<S291>/Relational Operator1'
     */
    if (localLogicalOperator4_e) {
      InjSpMgt_B.Switch3_j[0] = (((Float32)localSwitch5_o) <=
        InjSys_prm_agFrstInjSTTSp[0]);
      InjSpMgt_B.Switch3_j[1] = (localSwitch8_k <= InjSys_prm_agFrstInjSTTSp[1]);
    } else {
      InjSpMgt_B.Switch3_j[0] = FALSE;
      InjSpMgt_B.Switch3_j[1] = FALSE;
    }

    /* S-Function "vems_vidSET" Block: <S291>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_bInhFrstInjSTT, 2, InjSpMgt_B.Switch3_j);
  }

  /* end of Outputs for SubSystem: '<S289>/F01_InhFrstInjCkOn' */
}

/* Start for exported function: InjSys_EveCkSnNtAc_InjSpMgt */
void InjSys_EveCkSnNtAc_InjSpMgt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjSpMgt_fc_demux4'
   */

  /* Start for S-Function (fcncallgen): '<S17>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F02_SdlEveClcn_InjSpMgt'
   *  Start for SubSystem: '<S13>/F01_InhFrstInjCkOn'
   */
}

/* Output and update for exported function: InjSys_EveCkSnNtAc_InjSpMgt */
void InjSys_EveCkSnNtAc_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjSpMgt_fc_demux4'
   */

  /* S-Function (fcncallgen): '<S17>/Function-Call Generator' incorporates:
   *  SubSystem: '<S13>/F01_InhFrstInjCkOn'
   */
  InjSpMgt_ASYNC4(1);
  InjSpMgt_ASYNC7(1);
  InjSpMgt_ASYNC9(0);
  InjSpMgt_F01_InhFrstInjCkOn();
}

/* Output and update for function-call system: '<S13>/F02_InhFrstInjSdlFast' */
void InjSpMgt_F02_InhFrstInjSdlFast(void)
{
  Boolean localRelationalOperator2_gz;
  Boolean localLogicalOperator3_j;
  Boolean localSwitch2_pt;

  /* Outputs for enable SubSystem: '<S290>/F02_InhFrstInjSdlFast' incorporates:
   *  Constant: '<S290>/Constant1'
   *  Constant: '<S290>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S292>/Enable'
   *  RelationalOperator: '<S290>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S292>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, InjSpMgt_B.VEMS_vidGET_l);

    /* RelationalOperator: '<S292>/Relational Operator2' */
    localRelationalOperator2_gz = (InjSpMgt_B.VEMS_vidGET_l ==
      InjSys_noCmprCylStopSTT);

    /* S-Function "vems_vidGET" Block: <S292>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_bInhFrstInjSTT, 2,
                       InjSys_prm_bInhFrstInjSTTPrev);

    /* Logic: '<S292>/Logical Operator1' */
    localRelationalOperator2_gz = ((localRelationalOperator2_gz) &&
      InjSys_prm_bInhFrstInjSTTPrev[1]);

    /* S-Function "vems_vidGET" Block: <S292>/VEMS_vidGET2 */
    VEMS_vidGET(Sync_bEngPosOk, InjSpMgt_B.VEMS_vidGET2_m);

    /* Logic: '<S292>/Logical Operator3' incorporates:
     *  Inport: '<Root>/FRM_bInhFrstInjSTT'
     *  Logic: '<S292>/Logical Operator4'
     */
    localLogicalOperator3_j = (InjSpMgt_B.VEMS_vidGET2_m && (!GDGAR_bGetFRM
      (FRM_FRM_INHFRSTINJSTT)));

    /* S-Function "vems_vidGET" Block: <S292>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, InjSpMgt_B.VEMS_vidGET1_j);

    /* S-Function "vems_vidGET" Block: <S292>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_noInCylStopSTT, InjSpMgt_B.VEMS_vidGET3_j);

    /* Switch: '<S292>/Switch1' incorporates:
     *  Constant: '<S292>/InjSys_agInj2CrkSpDft_C3'
     *  Constant: '<S292>/InjSys_agInj2CrkSpDft_C5'
     */
    if (localRelationalOperator2_gz) {
      localRelationalOperator2_gz = TRUE;
    } else {
      localRelationalOperator2_gz = FALSE;
    }

    /* Switch: '<S292>/Switch2' incorporates:
     *  Constant: '<S292>/InjSys_agInj2CrkSpDft_C1'
     *  Constant: '<S292>/InjSys_agInj2CrkSpDft_C2'
     *  Logic: '<S292>/Logical Operator6'
     *  RelationalOperator: '<S292>/Relational Operator1'
     */
    if ((InjSpMgt_B.VEMS_vidGET1_j == InjSpMgt_B.VEMS_vidGET3_j) &&
        InjSys_prm_bInhFrstInjSTTPrev[0]) {
      localSwitch2_pt = TRUE;
    } else {
      localSwitch2_pt = FALSE;
    }

    /* Switch: '<S292>/Switch3' incorporates:
     *  Constant: '<S292>/InjSys_agInj2CrkSpDft_C4'
     */
    if (localLogicalOperator3_j) {
      InjSpMgt_B.Switch3_o[0] = localSwitch2_pt;
      InjSpMgt_B.Switch3_o[1] = localRelationalOperator2_gz;
    } else {
      InjSpMgt_B.Switch3_o[0] = FALSE;
      InjSpMgt_B.Switch3_o[1] = FALSE;
    }

    /* S-Function "vems_vidSET" Block: <S292>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_bInhFrstInjSTT, 2, InjSpMgt_B.Switch3_o);
  }

  /* end of Outputs for SubSystem: '<S290>/F02_InhFrstInjSdlFast' */
}

/* Start for exported function: InjSys_SdlFast_InjSpMgt */
void InjSys_SdlFast_InjSpMgt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjSpMgt_fc_demux'
   */
}

/* Output and update for exported function: InjSys_SdlFast_InjSpMgt */
void InjSys_SdlFast_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjSpMgt_fc_demux'
   */

  /* S-Function (fcncallgen): '<S14>/Function-Call Generator' incorporates:
   *  SubSystem: '<S13>/F02_InhFrstInjSdlFast'
   */
  InjSpMgt_ASYNC4(2);
  InjSpMgt_ASYNC9(1);
  InjSpMgt_F02_InhFrstInjSdlFast();
}

/* Output and update for exported function: InjSys_EveSpl_InjSpMgt */
void InjSys_EveSpl_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' */
  InjSpMgt_ASYNC7(0);
}

/* Output and update for function-call system: '<S10>/F03_SyncEveClcn_InjSpMgt' */
void InjSpM_F03_SyncEveClcn_InjSpMgt(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_l;
  UInt32 localAdd_ka;
  UInt32 localAdd_a;
  Boolean localLogicalOperator26;
  UInt32 localAdd_fs;
  UInt32 localAdd_c;
  UInt16 localAssignment_i[6];
  UInt16 localAssignment_c4[6];
  UInt16 localAssignment_g[6];
  UInt16 localAssignment_gv[6];
  UInt16 localAssignment_lr[6];
  UInt16 localAssignment_k1[6];
  UInt16 localAssignment_la[6];
  UInt16 localAssignment_ar[6];
  UInt16 localAssignment_bg[6];
  UInt16 localAssignment_hu[6];
  UInt16 localAssignment_a[6];
  UInt16 localAssignment_n5[6];
  UInt16 localAssignment_bv[6];
  UInt16 localAssignment_o3[6];
  UInt16 localAssignment_ku[6];
  UInt16 localAssignment_ac[6];
  UInt16 localAssignment_p[6];
  UInt16 localAssignment_nz[6];
  UInt16 localAssignment_ce[6];
  UInt16 localAssignment_it[6];
  UInt16 localAssignment_ml[6];
  UInt16 localAssignment_iq[6];
  UInt16 localAssignment_kq[6];
  UInt16 localAssignment_j[6];
  UInt16 localAssignment_py[6];
  UInt16 localAssignment_hy[6];
  SInt32 locali;
  UInt16 locallocalDataTypeConversion;
  UInt16 locallocalDataTypeConversion12_;
  UInt16 locallocalDataTypeConversion2_l;
  UInt16 locallocalDataTypeConversion6_f;

  /* RelationalOperator: '<S169>/Relational Operator' incorporates:
   *  Constant: '<S169>/Constant1'
   *  Constant: '<S169>/INJSPMGT_u8Inhib'
   */
  localRelationalOperator_l = (INJSPMGT_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S169>/F03_SyncEveClcn_InjSpMgt' incorporates:
   *  EnablePort: '<S237>/Enable'
   */
  if (localRelationalOperator_l) {
    /* DataTypeConversion: '<S237>/Data Type Conversion11' */
    localAdd_fs = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH1Req * 3)) >>
      1));
    if (localAdd_fs > 65535U) {
      locallocalDataTypeConversion = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion = (UInt16)localAdd_fs;
    }

    /* DataTypeConversion: '<S237>/Data Type Conversion12' */
    localAdd_fs = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH1Req * 3)) >>
      1));
    if (localAdd_fs > 65535U) {
      locallocalDataTypeConversion12_ = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion12_ = (UInt16)localAdd_fs;
    }

    /* DataTypeConversion: '<S237>/Data Type Conversion2' */
    localAdd_fs = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH2Req * 3)) >>
      1));
    if (localAdd_fs > 65535U) {
      locallocalDataTypeConversion2_l = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion2_l = (UInt16)localAdd_fs;
    }

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, InjSpMgt_B.VEMS_vidGET1_p5);

    /* DataTypeConversion: '<S237>/Data Type Conversion4' */
    localAdd_ka = InjSpMgt_B.VEMS_vidGET1_p5;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInNxtCyl, InjSpMgt_B.VEMS_vidGET_f);

    /* DataTypeConversion: '<S237>/Data Type Conversion5' */
    localAdd_a = InjSpMgt_B.VEMS_vidGET_f;

    /* DataTypeConversion: '<S237>/Data Type Conversion6' */
    localAdd_fs = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH2Req * 3)) >>
      1));
    if (localAdd_fs > 65535U) {
      locallocalDataTypeConversion6_f = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion6_f = (UInt16)localAdd_fs;
    }

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_bAcvFrstInjSp, InjSpMgt_B.VEMS_vidGET2_f);

    /* Logic: '<S237>/Logical Operator26' incorporates:
     *  Logic: '<S237>/Logical Operator27'
     *  UnitDelay: '<S264>/Unit Delay'
     */
    localLogicalOperator26 = ((!InjSpMgt_B.VEMS_vidGET2_f) &&
      InjSpMgt_DWork.UnitDelay_DSTATE_dk);

    /* Sum: '<S238>/Add' incorporates:
     *  Constant: '<S238>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_rMFuReqLPFu, 6, InjSpMgt_B.VEMS_vidGET9);

    /* DataTypeDuplicate Block: '<S238>/Data Type Duplicate'
     *
     * Regarding '<S238>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S238>/Data Type Duplicate1'
     *
     * Regarding '<S238>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S238>/Assignment' incorporates:
     *  Constant: '<S238>/Constant'
     *  MinMax: '<S238>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_i[locali] = InjSpMgt_B.VEMS_vidGET9[(locali)];
    }

    localAssignment_i[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_rMFuReqLPFu;

    /* Sum: '<S239>/Add' incorporates:
     *  Constant: '<S239>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET8);

    /* DataTypeDuplicate Block: '<S239>/Data Type Duplicate'
     *
     * Regarding '<S239>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S239>/Data Type Duplicate1'
     *
     * Regarding '<S239>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S239>/Assignment' incorporates:
     *  Constant: '<S239>/Constant'
     *  MinMax: '<S239>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_c4[locali] = InjSpMgt_B.VEMS_vidGET8[(locali)];
    }

    localAssignment_c4[(SInt32)rt_MIN(localAdd_fs, 5U)] =
      locallocalDataTypeConversion12_;

    /* Sum: '<S240>/Add' incorporates:
     *  Constant: '<S240>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET13);

    /* DataTypeDuplicate Block: '<S240>/Data Type Duplicate'
     *
     * Regarding '<S240>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S240>/Data Type Duplicate1'
     *
     * Regarding '<S240>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S240>/Assignment' incorporates:
     *  Constant: '<S240>/Constant'
     *  MinMax: '<S240>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_g[locali] = InjSpMgt_B.VEMS_vidGET13[(locali)];
    }

    localAssignment_g[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_agEndInjS1Req;

    /* Sum: '<S241>/Add' incorporates:
     *  Constant: '<S241>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET14 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, InjSpMgt_B.VEMS_vidGET14);

    /* DataTypeDuplicate Block: '<S241>/Data Type Duplicate'
     *
     * Regarding '<S241>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S241>/Data Type Duplicate1'
     *
     * Regarding '<S241>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S241>/Assignment' incorporates:
     *  Constant: '<S241>/Constant'
     *  MinMax: '<S241>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_gv[locali] = InjSpMgt_B.VEMS_vidGET14[(locali)];
    }

    localAssignment_gv[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_agBegInjS2Req;

    /* Sum: '<S242>/Add' incorporates:
     *  Constant: '<S242>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET15 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, InjSpMgt_B.VEMS_vidGET15);

    /* DataTypeDuplicate Block: '<S242>/Data Type Duplicate'
     *
     * Regarding '<S242>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S242>/Data Type Duplicate1'
     *
     * Regarding '<S242>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Assignment: '<S242>/Assignment' incorporates:
     *  Constant: '<S242>/Constant'
     *  MinMax: '<S242>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_lr[locali] = InjSpMgt_B.VEMS_vidGET15[(locali)];
    }

    localAssignment_lr[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_agEndInjS2Req;

    /* Sum: '<S243>/Add' incorporates:
     *  Constant: '<S243>/Constant1'
     */
    localAdd_fs = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET3);

    /* DataTypeDuplicate Block: '<S260>/Data Type Duplicate'
     *
     * Regarding '<S260>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S260>/Data Type Duplicate1'
     *
     * Regarding '<S260>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S260>/Add' incorporates:
     *  Constant: '<S260>/Constant1'
     */
    localAdd_c = localAdd_ka - 1U;

    /* Assignment: '<S260>/Assignment' incorporates:
     *  Constant: '<S260>/Constant'
     *  MinMax: '<S260>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_k1[locali] = InjSpMgt_B.VEMS_vidGET3[(locali)];
    }

    localAssignment_k1[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_rInjH1Req;

    /* Assignment: '<S243>/Assignment' incorporates:
     *  Constant: '<S243>/Constant'
     *  MinMax: '<S243>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_la[locali] = localAssignment_k1[locali];
    }

    localAssignment_la[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_rInjH1Req;

    /* Sum: '<S244>/Add' incorporates:
     *  Constant: '<S244>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_rInjH2ReqCyl, 6, InjSpMgt_B.VEMS_vidGET4);

    /* DataTypeDuplicate Block: '<S259>/Data Type Duplicate'
     *
     * Regarding '<S259>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S259>/Data Type Duplicate1'
     *
     * Regarding '<S259>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S259>/Add' incorporates:
     *  Constant: '<S259>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S259>/Assignment' incorporates:
     *  Constant: '<S259>/Constant'
     *  MinMax: '<S259>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_ar[locali] = InjSpMgt_B.VEMS_vidGET4[(locali)];
    }

    localAssignment_ar[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_rInjH2Req;

    /* Assignment: '<S244>/Assignment' incorporates:
     *  Constant: '<S244>/Constant'
     *  MinMax: '<S244>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_bg[locali] = localAssignment_ar[locali];
    }

    localAssignment_bg[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_rInjH2Req;

    /* Sum: '<S245>/Add' incorporates:
     *  Constant: '<S245>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET5);

    /* DataTypeDuplicate Block: '<S258>/Data Type Duplicate'
     *
     * Regarding '<S258>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S258>/Data Type Duplicate1'
     *
     * Regarding '<S258>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S258>/Add' incorporates:
     *  Constant: '<S258>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S258>/Assignment' incorporates:
     *  Constant: '<S258>/Constant'
     *  MinMax: '<S258>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_hu[locali] = InjSpMgt_B.VEMS_vidGET5[(locali)];
    }

    localAssignment_hu[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_rInjS1Req;

    /* Assignment: '<S245>/Assignment' incorporates:
     *  Constant: '<S245>/Constant'
     *  MinMax: '<S245>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_a[locali] = localAssignment_hu[locali];
    }

    localAssignment_a[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_rInjS1Req;

    /* Sum: '<S246>/Add' incorporates:
     *  Constant: '<S246>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_rInjS2ReqCyl, 6, InjSpMgt_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S257>/Data Type Duplicate'
     *
     * Regarding '<S257>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S257>/Data Type Duplicate1'
     *
     * Regarding '<S257>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S257>/Add' incorporates:
     *  Constant: '<S257>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S257>/Assignment' incorporates:
     *  Constant: '<S257>/Constant'
     *  MinMax: '<S257>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_n5[locali] = InjSpMgt_B.VEMS_vidGET6[(locali)];
    }

    localAssignment_n5[(SInt32)rt_MIN(localAdd_fs, 5U)] = InjSys_rInjS2Req;

    /* Assignment: '<S246>/Assignment' incorporates:
     *  Constant: '<S246>/Constant'
     *  MinMax: '<S246>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_bv[locali] = localAssignment_n5[locali];
    }

    localAssignment_bv[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_rInjS2Req;

    /* Sum: '<S247>/Add' incorporates:
     *  Constant: '<S247>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET7);

    /* DataTypeDuplicate Block: '<S250>/Data Type Duplicate'
     *
     * Regarding '<S250>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S250>/Data Type Duplicate1'
     *
     * Regarding '<S250>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S250>/Add' incorporates:
     *  Constant: '<S250>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S250>/Assignment' incorporates:
     *  Constant: '<S250>/Constant'
     *  MinMax: '<S250>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_o3[locali] = InjSpMgt_B.VEMS_vidGET7[(locali)];
    }

    localAssignment_o3[(SInt32)rt_MIN(localAdd_fs, 5U)] =
      locallocalDataTypeConversion;

    /* Assignment: '<S247>/Assignment' incorporates:
     *  Constant: '<S247>/Constant'
     *  MinMax: '<S247>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_ku[locali] = localAssignment_o3[locali];
      localAssignment_ac[locali] = localAssignment_c4[locali];
      localAssignment_p[locali] = localAssignment_i[locali];
    }

    localAssignment_ku[(SInt32)rt_MIN(localAdd_c, 5U)] =
      locallocalDataTypeConversion;

    /* Sum: '<S248>/Add' incorporates:
     *  Constant: '<S248>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* Assignment: '<S248>/Assignment' incorporates:
     *  Constant: '<S248>/Constant'
     *  MinMax: '<S248>/MinMax'
     */
    localAssignment_ac[(SInt32)rt_MIN(localAdd_c, 5U)] =
      locallocalDataTypeConversion12_;

    /* Sum: '<S249>/Add' incorporates:
     *  Constant: '<S249>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* Assignment: '<S249>/Assignment' incorporates:
     *  Constant: '<S249>/Constant'
     *  MinMax: '<S249>/MinMax'
     */
    localAssignment_p[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_rMFuReqLPFu;

    /* Sum: '<S251>/Add' incorporates:
     *  Constant: '<S251>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6,
                       InjSpMgt_B.VEMS_vidGET10_h);

    /* DataTypeDuplicate Block: '<S261>/Data Type Duplicate'
     *
     * Regarding '<S261>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S261>/Data Type Duplicate1'
     *
     * Regarding '<S261>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S261>/Add' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S261>/Assignment' incorporates:
     *  Constant: '<S261>/Constant'
     *  MinMax: '<S261>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_nz[locali] = InjSpMgt_B.VEMS_vidGET10_h[(locali)];
    }

    localAssignment_nz[(SInt32)rt_MIN(localAdd_fs, 5U)] =
      locallocalDataTypeConversion2_l;

    /* Assignment: '<S251>/Assignment' incorporates:
     *  Constant: '<S251>/Constant'
     *  MinMax: '<S251>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_ce[locali] = localAssignment_nz[locali];
    }

    localAssignment_ce[(SInt32)rt_MIN(localAdd_c, 5U)] =
      locallocalDataTypeConversion2_l;

    /* Sum: '<S252>/Add' incorporates:
     *  Constant: '<S252>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET11 */
    VEMS_vidGET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6,
                       InjSpMgt_B.VEMS_vidGET11_g);

    /* DataTypeDuplicate Block: '<S262>/Data Type Duplicate'
     *
     * Regarding '<S262>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S262>/Data Type Duplicate1'
     *
     * Regarding '<S262>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S262>/Add' incorporates:
     *  Constant: '<S262>/Constant1'
     */
    localAdd_fs = localAdd_ka - 1U;

    /* Assignment: '<S262>/Assignment' incorporates:
     *  Constant: '<S262>/Constant'
     *  MinMax: '<S262>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_it[locali] = InjSpMgt_B.VEMS_vidGET11_g[(locali)];
    }

    localAssignment_it[(SInt32)rt_MIN(localAdd_fs, 5U)] =
      locallocalDataTypeConversion6_f;

    /* Assignment: '<S252>/Assignment' incorporates:
     *  Constant: '<S252>/Constant'
     *  MinMax: '<S252>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_ml[locali] = localAssignment_it[locali];
    }

    localAssignment_ml[(SInt32)rt_MIN(localAdd_c, 5U)] =
      locallocalDataTypeConversion6_f;

    /* Sum: '<S253>/Add' incorporates:
     *  Constant: '<S253>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* S-Function "vems_vidGET" Block: <S237>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, InjSpMgt_B.VEMS_vidGET12);

    /* DataTypeDuplicate Block: '<S263>/Data Type Duplicate'
     *
     * Regarding '<S263>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S263>/Data Type Duplicate1'
     *
     * Regarding '<S263>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S263>/Add' incorporates:
     *  Constant: '<S263>/Constant1'
     */
    localAdd_ka--;

    /* Assignment: '<S263>/Assignment' incorporates:
     *  Constant: '<S263>/Constant'
     *  MinMax: '<S263>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_iq[locali] = InjSpMgt_B.VEMS_vidGET12[(locali)];
    }

    localAssignment_iq[(SInt32)rt_MIN(localAdd_ka, 5U)] = InjSys_agBegInjS1Req;

    /* Assignment: '<S253>/Assignment' incorporates:
     *  Constant: '<S253>/Constant'
     *  MinMax: '<S253>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_kq[locali] = localAssignment_iq[locali];
      localAssignment_j[locali] = localAssignment_g[locali];
      localAssignment_py[locali] = localAssignment_gv[locali];
      localAssignment_hy[locali] = localAssignment_lr[locali];

      /* Switch: '<S237>/Switch1' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch1[(locali)] = localAssignment_bg[locali];
      } else {
        InjSpMgt_B.Switch1[(locali)] = localAssignment_ar[locali];
      }
    }

    localAssignment_kq[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_agBegInjS1Req;

    /* Sum: '<S254>/Add' incorporates:
     *  Constant: '<S254>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* Assignment: '<S254>/Assignment' incorporates:
     *  Constant: '<S254>/Constant'
     *  MinMax: '<S254>/MinMax'
     */
    localAssignment_j[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_agEndInjS1Req;

    /* Sum: '<S255>/Add' incorporates:
     *  Constant: '<S255>/Constant1'
     */
    localAdd_c = localAdd_a - 1U;

    /* Assignment: '<S255>/Assignment' incorporates:
     *  Constant: '<S255>/Constant'
     *  MinMax: '<S255>/MinMax'
     */
    localAssignment_py[(SInt32)rt_MIN(localAdd_c, 5U)] = InjSys_agBegInjS2Req;

    /* Sum: '<S256>/Add' incorporates:
     *  Constant: '<S256>/Constant1'
     */
    localAdd_a--;

    /* Assignment: '<S256>/Assignment' incorporates:
     *  Constant: '<S256>/Constant'
     *  MinMax: '<S256>/MinMax'
     */
    localAssignment_hy[(SInt32)rt_MIN(localAdd_a, 5U)] = InjSys_agEndInjS2Req;
    for (locali = 0; locali < 6; locali++) {
      /* Switch: '<S237>/Switch10' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch10[(locali)] = localAssignment_kq[locali];
      } else {
        InjSpMgt_B.Switch10[(locali)] = localAssignment_iq[locali];
      }

      /* Switch: '<S237>/Switch11' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch11[(locali)] = localAssignment_j[locali];
      } else {
        InjSpMgt_B.Switch11[(locali)] = localAssignment_g[locali];
      }

      /* Switch: '<S237>/Switch12' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch12[(locali)] = localAssignment_py[locali];
      } else {
        InjSpMgt_B.Switch12[(locali)] = localAssignment_gv[locali];
      }

      /* Switch: '<S237>/Switch13' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch13[(locali)] = localAssignment_hy[locali];
      } else {
        InjSpMgt_B.Switch13[(locali)] = localAssignment_lr[locali];
      }

      /* Switch: '<S237>/Switch2' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch2[(locali)] = localAssignment_a[locali];
      } else {
        InjSpMgt_B.Switch2[(locali)] = localAssignment_hu[locali];
      }

      /* Switch: '<S237>/Switch3' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch3[(locali)] = localAssignment_bv[locali];
      } else {
        InjSpMgt_B.Switch3[(locali)] = localAssignment_n5[locali];
      }

      /* Switch: '<S237>/Switch4' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch4[(locali)] = localAssignment_ku[locali];
      } else {
        InjSpMgt_B.Switch4[(locali)] = localAssignment_o3[locali];
      }

      /* Switch: '<S237>/Switch5' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch5[(locali)] = localAssignment_ac[locali];
      } else {
        InjSpMgt_B.Switch5[(locali)] = localAssignment_c4[locali];
      }

      /* Switch: '<S237>/Switch6' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch6[(locali)] = localAssignment_p[locali];
      } else {
        InjSpMgt_B.Switch6[(locali)] = localAssignment_i[locali];
      }

      /* Switch: '<S237>/Switch7' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch7[(locali)] = localAssignment_ce[locali];
      } else {
        InjSpMgt_B.Switch7[(locali)] = localAssignment_nz[locali];
      }

      /* Switch: '<S237>/Switch8' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch8[(locali)] = localAssignment_la[locali];
      } else {
        InjSpMgt_B.Switch8[(locali)] = localAssignment_k1[locali];
      }

      /* Switch: '<S237>/Switch9' */
      if (localLogicalOperator26) {
        InjSpMgt_B.Switch9[(locali)] = localAssignment_ml[locali];
      } else {
        InjSpMgt_B.Switch9[(locali)] = localAssignment_it[locali];
      }
    }

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, InjSpMgt_B.Switch4);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, InjSpMgt_B.Switch7);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET10 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS1ReqCyl, 6, InjSpMgt_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET11 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS2ReqCyl, 6, InjSpMgt_B.Switch3);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET12 */
    VEMS_vidSET1DArray(InjSys_prm_rMFuReqLPFu, 6, InjSpMgt_B.Switch6);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, InjSpMgt_B.Switch10);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, InjSpMgt_B.Switch12);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, InjSpMgt_B.Switch5);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, InjSpMgt_B.Switch9);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, InjSpMgt_B.Switch11);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, InjSpMgt_B.Switch13);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH1ReqCyl, 6, InjSpMgt_B.Switch8);

    /* S-Function "vems_vidSET" Block: <S237>/VEMS_vidSET9 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH2ReqCyl, 6, InjSpMgt_B.Switch1);
  }

  /* end of Outputs for SubSystem: '<S169>/F03_SyncEveClcn_InjSpMgt' */

  /* Update for enable SubSystem: '<S169>/F03_SyncEveClcn_InjSpMgt' incorporates:
   *  Update for EnablePort: '<S237>/Enable'
   */
  if (localRelationalOperator_l) {
    /* Update for UnitDelay: '<S264>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE_dk = InjSpMgt_B.VEMS_vidGET2_f;
  }

  /* end of Update for SubSystem: '<S169>/F03_SyncEveClcn_InjSpMgt' */
}

/* Output and update for exported function: InjSys_EveInj_InjSpMgt */
void InjSys_EveInj_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S10>/F03_SyncEveClcn_InjSpMgt'
   */
  InjSpM_F03_SyncEveClcn_InjSpMgt();
}

/* Output and update for function-call system: '<S10>/F01_SyncRotToCrank' */
void InjSpMgt_F01_SyncRotToCrank(void)
{
  UInt32 localAdd_n5;
  UInt32 localAdd_o;
  UInt32 localAdd_ab;
  UInt32 localAdd_j;
  UInt16 localAssignment_ia[6];
  UInt16 localAssignment_l5[6];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_e_idx;
  UInt16 locallocalOutDTConv_e_idx_0;
  UInt16 locallocalOutDTConv_e_idx_1;
  UInt16 locallocalSwitch;
  UInt16 locallocalSwitch_0;
  UInt16 locallocalSwitch_1;

  /* Outputs for enable SubSystem: '<S167>/F01_SyncRotToCrank' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Constant: '<S167>/INJSPMGT_u8Inhib'
   *  EnablePort: '<S170>/Enable'
   *  RelationalOperator: '<S167>/Relational Operator'
   */
  if (INJSPMGT_u8Inhib != 90) {
    /* DataTypeConversion: '<S170>/Data Type Conversion1' */
    localAdd_o = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH1Req * 3)) >>
      1));
    if (localAdd_o > 65535U) {
      locallocalSwitch = MAX_uint16_T;
    } else {
      locallocalSwitch = (UInt16)localAdd_o;
    }

    /* DataTypeConversion: '<S170>/Data Type Conversion2' */
    localAdd_o = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH2Req * 3)) >>
      1));
    if (localAdd_o > 65535U) {
      locallocalSwitch_0 = MAX_uint16_T;
    } else {
      locallocalSwitch_0 = (UInt16)localAdd_o;
    }

    /* DataTypeConversion: '<S170>/Data Type Conversion3' */
    localAdd_o = (UInt32)((SInt32)(((UInt32)(InjSys_agEndInjH2Req * 3)) >>
      1));
    if (localAdd_o > 65535U) {
      locallocalSwitch_1 = MAX_uint16_T;
    } else {
      locallocalSwitch_1 = (UInt16)localAdd_o;
    }

    /* S-Function "vems_vidGET" Block: <S170>/VEMS_vidGET1 */
    VEMS_vidGET(InjSys_noInCylStopSTT, InjSpMgt_B.VEMS_vidGET1_p);

    /* DataTypeConversion: '<S170>/Data Type Conversion4' */
    localAdd_n5 = InjSpMgt_B.VEMS_vidGET1_p;

    /* DataTypeConversion: '<S170>/Data Type Conversion5' */
    localAdd_o = (UInt32)((SInt32)(((UInt32)(InjSys_agBegInjH1Req * 3)) >>
      1));
    if (localAdd_o > 65535U) {
      locallocalOutDTConv_e_idx_1 = MAX_uint16_T;
    } else {
      locallocalOutDTConv_e_idx_1 = (UInt16)localAdd_o;
    }

    /* DataTypeConversion: '<S170>/Data Type Conversion6' */
    localAdd_o = InjSys_noCmprCylStopSTT;

    /* Sum: '<S171>/Add' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    localAdd_j = localAdd_o - 1U;

    /* SignalConversion: '<S191>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = InjSys_rInjH1Req;
    localAssignment_ia[1] = InjSys_rInjH1Req;
    localAssignment_ia[2] = InjSys_rInjH1Req;
    localAssignment_ia[3] = InjSys_rInjH1Req;
    localAssignment_ia[4] = InjSys_rInjH1Req;
    localAssignment_ia[5] = InjSys_rInjH1Req;

    /* UnitDelay: '<S203>/Unit Delay' */
    locallocalOutDTConv_e_idx_0 = InjSpMgt_DWork.UnitDelay_DSTATE_d;

    /* S-Function "vems_vidGET" Block: <S170>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSpMgt_B.VEMS_vidGET_o);

    /* Switch: '<S170>/Switch1' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSys_rInjH1Req;
    }

    /* Sum: '<S191>/Add' incorporates:
     *  Constant: '<S191>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* Assignment: '<S191>/Assignment' incorporates:
     *  Constant: '<S191>/Constant'
     *  MinMax: '<S191>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Assignment: '<S171>/Assignment' incorporates:
     *  Constant: '<S171>/Constant'
     *  MinMax: '<S171>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment[rt_MIN(localAdd_j, 5U)] = locallocalOutDTConv_e_idx_0;

    /* Sum: '<S172>/Add' incorporates:
     *  Constant: '<S172>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* SignalConversion: '<S194>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = locallocalOutDTConv_e_idx_1;
    localAssignment_ia[1] = locallocalOutDTConv_e_idx_1;
    localAssignment_ia[2] = locallocalOutDTConv_e_idx_1;
    localAssignment_ia[3] = locallocalOutDTConv_e_idx_1;
    localAssignment_ia[4] = locallocalOutDTConv_e_idx_1;
    localAssignment_ia[5] = locallocalOutDTConv_e_idx_1;

    /* DataTypeConversion: '<S202>/OutDTConv' incorporates:
     *  Constant: '<S202>/offset'
     *  Constant: '<S202>/offset1'
     *  Constant: '<S202>/one_on_slope'
     *  Product: '<S202>/Product4'
     *  Sum: '<S202>/Add1'
     *  Sum: '<S202>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agBegInjH1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agBegInjH1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch9' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = locallocalOutDTConv_e_idx_1;
    }

    /* Sum: '<S194>/Add' incorporates:
     *  Constant: '<S194>/Constant1'
     */
    localAdd_j = localAdd_n5 - 1U;

    /* Assignment: '<S194>/Assignment' incorporates:
     *  Constant: '<S194>/Constant'
     *  MinMax: '<S194>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_j, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Switch: '<S170>/Switch17' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_1 = locallocalOutDTConv_e_idx;
    }

    /* Assignment: '<S172>/Assignment' incorporates:
     *  Constant: '<S172>/Constant'
     *  MinMax: '<S172>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_jw[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_jw[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_1;

    /* Sum: '<S173>/Add' incorporates:
     *  Constant: '<S173>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S173>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = locallocalSwitch;
    localAssignment_ia[1] = locallocalSwitch;
    localAssignment_ia[2] = locallocalSwitch;
    localAssignment_ia[3] = locallocalSwitch;
    localAssignment_ia[4] = locallocalSwitch;
    localAssignment_ia[5] = locallocalSwitch;

    /* DataTypeConversion: '<S195>/OutDTConv' incorporates:
     *  Constant: '<S195>/offset'
     *  Constant: '<S195>/offset1'
     *  Constant: '<S195>/one_on_slope'
     *  Product: '<S195>/Product4'
     *  Sum: '<S195>/Add1'
     *  Sum: '<S195>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agEndInjH1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agEndInjH1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch11' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = locallocalSwitch;
    }

    /* Assignment: '<S173>/Assignment' incorporates:
     *  Constant: '<S173>/Constant'
     *  MinMax: '<S173>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S174>/Add' incorporates:
     *  Constant: '<S174>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch18' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalSwitch = locallocalOutDTConv_e_idx;
    }

    /* Assignment: '<S174>/Assignment' incorporates:
     *  Constant: '<S174>/Constant'
     *  MinMax: '<S174>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_o[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_o[rt_MIN(localAdd_ab, 5U)] = locallocalSwitch;

    /* Sum: '<S175>/Add' incorporates:
     *  Constant: '<S175>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S175>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = InjSys_agEndInjS2Req;
    localAssignment_ia[1] = InjSys_agEndInjS2Req;
    localAssignment_ia[2] = InjSys_agEndInjS2Req;
    localAssignment_ia[3] = InjSys_agEndInjS2Req;
    localAssignment_ia[4] = InjSys_agEndInjS2Req;
    localAssignment_ia[5] = InjSys_agEndInjS2Req;

    /* DataTypeConversion: '<S201>/OutDTConv' incorporates:
     *  Constant: '<S201>/offset'
     *  Constant: '<S201>/offset1'
     *  Constant: '<S201>/one_on_slope'
     *  Product: '<S201>/Product4'
     *  Sum: '<S201>/Add1'
     *  Sum: '<S201>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch12' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSys_agEndInjS2Req;
    }

    /* Assignment: '<S175>/Assignment' incorporates:
     *  Constant: '<S175>/Constant'
     *  MinMax: '<S175>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S176>/Add' incorporates:
     *  Constant: '<S176>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch24' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = locallocalOutDTConv_e_idx;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_agEndInjS2Req;
    }

    /* Assignment: '<S176>/Assignment' incorporates:
     *  Constant: '<S176>/Constant'
     *  MinMax: '<S176>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_b[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_b[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S177>/Add' incorporates:
     *  Constant: '<S177>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S177>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = InjSys_agBegInjS2Req;
    localAssignment_ia[1] = InjSys_agBegInjS2Req;
    localAssignment_ia[2] = InjSys_agBegInjS2Req;
    localAssignment_ia[3] = InjSys_agBegInjS2Req;
    localAssignment_ia[4] = InjSys_agBegInjS2Req;
    localAssignment_ia[5] = InjSys_agBegInjS2Req;

    /* DataTypeConversion: '<S200>/OutDTConv' incorporates:
     *  Constant: '<S200>/offset'
     *  Constant: '<S200>/offset1'
     *  Constant: '<S200>/one_on_slope'
     *  Product: '<S200>/Product4'
     *  Sum: '<S200>/Add1'
     *  Sum: '<S200>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch10' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSys_agBegInjS2Req;
    }

    /* Assignment: '<S177>/Assignment' incorporates:
     *  Constant: '<S177>/Constant'
     *  MinMax: '<S177>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S178>/Add' incorporates:
     *  Constant: '<S178>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch23' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = locallocalOutDTConv_e_idx;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_agBegInjS2Req;
    }

    /* Assignment: '<S178>/Assignment' incorporates:
     *  Constant: '<S178>/Constant'
     *  MinMax: '<S178>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_b2[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_b2[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S179>/Add' incorporates:
     *  Constant: '<S179>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S179>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = InjSys_agEndInjS1Req;
    localAssignment_ia[1] = InjSys_agEndInjS1Req;
    localAssignment_ia[2] = InjSys_agEndInjS1Req;
    localAssignment_ia[3] = InjSys_agEndInjS1Req;
    localAssignment_ia[4] = InjSys_agEndInjS1Req;
    localAssignment_ia[5] = InjSys_agEndInjS1Req;

    /* DataTypeConversion: '<S199>/OutDTConv' incorporates:
     *  Constant: '<S199>/offset'
     *  Constant: '<S199>/offset1'
     *  Constant: '<S199>/one_on_slope'
     *  Product: '<S199>/Product4'
     *  Sum: '<S199>/Add1'
     *  Sum: '<S199>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agEndInjS1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch8' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSys_agEndInjS1Req;
    }

    /* Assignment: '<S179>/Assignment' incorporates:
     *  Constant: '<S179>/Constant'
     *  MinMax: '<S179>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S180>/Add' incorporates:
     *  Constant: '<S180>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch22' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = locallocalOutDTConv_e_idx;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_agEndInjS1Req;
    }

    /* Assignment: '<S180>/Assignment' incorporates:
     *  Constant: '<S180>/Constant'
     *  MinMax: '<S180>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_e[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_e[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S181>/Add' incorporates:
     *  Constant: '<S181>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S181>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = InjSys_agBegInjS1Req;
    localAssignment_ia[1] = InjSys_agBegInjS1Req;
    localAssignment_ia[2] = InjSys_agBegInjS1Req;
    localAssignment_ia[3] = InjSys_agBegInjS1Req;
    localAssignment_ia[4] = InjSys_agBegInjS1Req;
    localAssignment_ia[5] = InjSys_agBegInjS1Req;

    /* DataTypeConversion: '<S198>/OutDTConv' incorporates:
     *  Constant: '<S198>/offset'
     *  Constant: '<S198>/offset1'
     *  Constant: '<S198>/one_on_slope'
     *  Product: '<S198>/Product4'
     *  Sum: '<S198>/Add1'
     *  Sum: '<S198>/Add2'
     */
    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS1SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_0 = MAX_uint16_T;
    }

    localtmp = (1.066666698E+001F * InjSys_prm_agBegInjS1SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_1 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_1 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_1 = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch6' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSys_agBegInjS1Req;
    }

    /* Assignment: '<S181>/Assignment' incorporates:
     *  Constant: '<S181>/Constant'
     *  MinMax: '<S181>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S182>/Add' incorporates:
     *  Constant: '<S182>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S182>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_l5[0] = InjSys_rInjH2Req;
    localAssignment_l5[1] = InjSys_rInjH2Req;
    localAssignment_l5[2] = InjSys_rInjH2Req;
    localAssignment_l5[3] = InjSys_rInjH2Req;
    localAssignment_l5[4] = InjSys_rInjH2Req;
    localAssignment_l5[5] = InjSys_rInjH2Req;

    /* Switch: '<S170>/Switch3' incorporates:
     *  UnitDelay: '<S204>/Unit Delay'
     */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSpMgt_DWork.UnitDelay_DSTATE_c;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_rInjH2Req;
    }

    /* Assignment: '<S182>/Assignment' incorporates:
     *  Constant: '<S182>/Constant'
     *  MinMax: '<S182>/MinMax'
     */
    localAssignment_l5[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S183>/Add' incorporates:
     *  Constant: '<S183>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch21' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_1 = InjSys_agBegInjS1Req;
    }

    /* Assignment: '<S183>/Assignment' incorporates:
     *  Constant: '<S183>/Constant'
     *  MinMax: '<S183>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_k[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_k[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_1;

    /* Sum: '<S184>/Add' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S184>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = locallocalSwitch_1;
    localAssignment_ia[1] = locallocalSwitch_1;
    localAssignment_ia[2] = locallocalSwitch_1;
    localAssignment_ia[3] = locallocalSwitch_1;
    localAssignment_ia[4] = locallocalSwitch_1;
    localAssignment_ia[5] = locallocalSwitch_1;

    /* DataTypeConversion: '<S197>/OutDTConv' incorporates:
     *  Constant: '<S197>/offset'
     *  Constant: '<S197>/offset1'
     *  Constant: '<S197>/one_on_slope'
     *  Product: '<S197>/Product4'
     *  Sum: '<S197>/Add1'
     *  Sum: '<S197>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agEndInjH2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_1 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_1 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_1 = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agEndInjH2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch4' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_1 = locallocalSwitch_1;
    }

    /* Assignment: '<S184>/Assignment' incorporates:
     *  Constant: '<S184>/Constant'
     *  MinMax: '<S184>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_1;

    /* Sum: '<S185>/Add' incorporates:
     *  Constant: '<S185>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch20' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalSwitch_1 = locallocalOutDTConv_e_idx;
    }

    /* Assignment: '<S185>/Assignment' incorporates:
     *  Constant: '<S185>/Constant'
     *  MinMax: '<S185>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_l[(locali)] = localAssignment_ia[locali];
    }

    InjSpMgt_B.Assignment_l[rt_MIN(localAdd_ab, 5U)] = locallocalSwitch_1;

    /* Sum: '<S186>/Add' incorporates:
     *  Constant: '<S186>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S186>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_ia[0] = locallocalSwitch_0;
    localAssignment_ia[1] = locallocalSwitch_0;
    localAssignment_ia[2] = locallocalSwitch_0;
    localAssignment_ia[3] = locallocalSwitch_0;
    localAssignment_ia[4] = locallocalSwitch_0;
    localAssignment_ia[5] = locallocalSwitch_0;

    /* DataTypeConversion: '<S196>/OutDTConv' incorporates:
     *  Constant: '<S196>/offset'
     *  Constant: '<S196>/offset1'
     *  Constant: '<S196>/one_on_slope'
     *  Product: '<S196>/Product4'
     *  Sum: '<S196>/Add1'
     *  Sum: '<S196>/Add2'
     */
    localtmp = (16.0F * InjSys_prm_agBegInjH2SpSTT[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx_1 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx_1 = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx_1 = MAX_uint16_T;
    }

    localtmp = (16.0F * InjSys_prm_agBegInjH2SpSTT[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_e_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_e_idx = 0U;
      }
    } else {
      locallocalOutDTConv_e_idx = MAX_uint16_T;
    }

    /* Switch: '<S170>/Switch2' */
    if (!InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_1 = locallocalSwitch_0;
    }

    /* Assignment: '<S186>/Assignment' incorporates:
     *  Constant: '<S186>/Constant'
     *  MinMax: '<S186>/MinMax'
     */
    localAssignment_ia[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_1;

    /* Sum: '<S187>/Add' incorporates:
     *  Constant: '<S187>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Switch: '<S170>/Switch19' */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalSwitch_0 = locallocalOutDTConv_e_idx;
    }

    /* Assignment: '<S187>/Assignment' incorporates:
     *  Constant: '<S187>/Constant'
     *  MinMax: '<S187>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_ma[(locali)] = localAssignment_ia[locali];
      InjSpMgt_B.Assignment_m[(locali)] = localAssignment_l5[locali];
    }

    InjSpMgt_B.Assignment_ma[rt_MIN(localAdd_ab, 5U)] = locallocalSwitch_0;

    /* Sum: '<S188>/Add' incorporates:
     *  Constant: '<S188>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Assignment: '<S188>/Assignment' incorporates:
     *  Constant: '<S188>/Constant'
     *  MinMax: '<S188>/MinMax'
     */
    InjSpMgt_B.Assignment_m[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S189>/Add' incorporates:
     *  Constant: '<S189>/Constant1'
     */
    localAdd_ab = localAdd_n5 - 1U;

    /* SignalConversion: '<S189>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_l5[0] = InjSys_rInjS1Req;
    localAssignment_l5[1] = InjSys_rInjS1Req;
    localAssignment_l5[2] = InjSys_rInjS1Req;
    localAssignment_l5[3] = InjSys_rInjS1Req;
    localAssignment_l5[4] = InjSys_rInjS1Req;
    localAssignment_l5[5] = InjSys_rInjS1Req;

    /* Switch: '<S170>/Switch5' incorporates:
     *  UnitDelay: '<S205>/Unit Delay'
     */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSpMgt_DWork.UnitDelay_DSTATE_p;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_rInjS1Req;
    }

    /* Assignment: '<S189>/Assignment' incorporates:
     *  Constant: '<S189>/Constant'
     *  MinMax: '<S189>/MinMax'
     */
    localAssignment_l5[(SInt32)rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S190>/Add' incorporates:
     *  Constant: '<S190>/Constant1'
     */
    localAdd_ab = localAdd_o - 1U;

    /* Assignment: '<S190>/Assignment' incorporates:
     *  Constant: '<S190>/Constant'
     *  MinMax: '<S190>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_my[(locali)] = localAssignment_l5[locali];
    }

    InjSpMgt_B.Assignment_my[rt_MIN(localAdd_ab, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S192>/Add' incorporates:
     *  Constant: '<S192>/Constant1'
     */
    localAdd_n5--;

    /* SignalConversion: '<S192>/TmpSignal ConversionAtAssignmentInport1' */
    localAssignment_l5[0] = InjSys_rInjS2Req;
    localAssignment_l5[1] = InjSys_rInjS2Req;
    localAssignment_l5[2] = InjSys_rInjS2Req;
    localAssignment_l5[3] = InjSys_rInjS2Req;
    localAssignment_l5[4] = InjSys_rInjS2Req;
    localAssignment_l5[5] = InjSys_rInjS2Req;

    /* Switch: '<S170>/Switch7' incorporates:
     *  UnitDelay: '<S206>/Unit Delay'
     */
    if (InjSpMgt_B.VEMS_vidGET_o) {
      locallocalOutDTConv_e_idx_0 = InjSpMgt_DWork.UnitDelay_DSTATE_h;
    } else {
      locallocalOutDTConv_e_idx_0 = InjSys_rInjS2Req;
    }

    /* Assignment: '<S192>/Assignment' incorporates:
     *  Constant: '<S192>/Constant'
     *  MinMax: '<S192>/MinMax'
     */
    localAssignment_l5[(SInt32)rt_MIN(localAdd_n5, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* Sum: '<S193>/Add' incorporates:
     *  Constant: '<S193>/Constant1'
     */
    localAdd_o--;

    /* Assignment: '<S193>/Assignment' incorporates:
     *  Constant: '<S193>/Constant'
     *  MinMax: '<S193>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSpMgt_B.Assignment_h[(locali)] = localAssignment_l5[locali];
    }

    InjSpMgt_B.Assignment_h[rt_MIN(localAdd_o, 5U)] =
      locallocalOutDTConv_e_idx_0;

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH1ReqCyl, 6, InjSpMgt_B.Assignment_jw);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjH2ReqCyl, 6, InjSpMgt_B.Assignment_ma);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET10 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS1ReqCyl, 6, InjSpMgt_B.Assignment_my);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET11 */
    VEMS_vidSET1DArray(InjSys_prm_rInjS2ReqCyl, 6, InjSpMgt_B.Assignment_h);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS1ReqCyl, 6, InjSpMgt_B.Assignment_k);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(InjSys_prm_agBegInjS2ReqCyl, 6, InjSpMgt_B.Assignment_b2);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH1ReqCyl, 6, InjSpMgt_B.Assignment_o);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjH2ReqCyl, 6, InjSpMgt_B.Assignment_l);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET6 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS1ReqCyl, 6, InjSpMgt_B.Assignment_e);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjSys_prm_agEndInjS2ReqCyl, 6, InjSpMgt_B.Assignment_b);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH1ReqCyl, 6, InjSpMgt_B.Assignment);

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET9 */
    VEMS_vidSET1DArray(InjSys_prm_rInjH2ReqCyl, 6, InjSpMgt_B.Assignment_m);

    /* SignalConversion: '<S170>/TmpSignal ConversionAtVEMS_vidSET12Inport1' */
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[0] = InjSys_rMFuReqLPFu;
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[1] = InjSys_rMFuReqLPFu;
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[2] = InjSys_rMFuReqLPFu;
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[3] = InjSys_rMFuReqLPFu;
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[4] = InjSys_rMFuReqLPFu;
    InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE[5] = InjSys_rMFuReqLPFu;

    /* S-Function "vems_vidSET" Block: <S170>/VEMS_vidSET12 */
    VEMS_vidSET1DArray(InjSys_prm_rMFuReqLPFu, 6,
                       InjSpMgt_B.TmpSignalConversionAtVEMS_vidSE);

    /* Update for UnitDelay: '<S203>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE_d = InjSys_rInjH1Req;

    /* Update for UnitDelay: '<S204>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE_c = InjSys_rInjH2Req;

    /* Update for UnitDelay: '<S205>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE_p = InjSys_rInjS1Req;

    /* Update for UnitDelay: '<S206>/Unit Delay' */
    InjSpMgt_DWork.UnitDelay_DSTATE_h = InjSys_rInjS2Req;
  }

  /* end of Outputs for SubSystem: '<S167>/F01_SyncRotToCrank' */
}

/* Start for exported function: InjSys_EveStTCr_InjSpMgt */
void InjSys_EveStTCr_InjSpMgt_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/InjSpMgt_fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S10>/F01_SyncRotToCrank'
   *  Start for SubSystem: '<S1>/F01_InjSpMgtFct'
   */
  InjSpMgt_F01_InjSpMgtFct_Start();
}

/* Output and update for exported function: InjSys_EveStTCr_InjSpMgt */
void InjSys_EveStTCr_InjSpMgt(void)
{
  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/InjSpMgt_fc_demux1'
   */

  /* S-Function (fcncallgen): '<S15>/Function-Call Generator' incorporates:
   *  SubSystem: '<S10>/F01_SyncRotToCrank'
   */
  InjSpMgt_ASYNC4(0);
  InjSpMgt_F01_SyncRotToCrank();
}

/* Model initialize function */
void InjSpMgt_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    InjSpMgt_B.VEMS_vidGET13_m = 96U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   */
  InjSys_EveRst_InjSpMgt_Start();
  InjSys_EveCkSnNtAc_InjSpMgt_Start();
  InjSys_SdlFast_InjSpMgt_Start();
  InjSys_EveStTCr_InjSpMgt_Start();
}

#define INJSPMGT_STOP_SEC_CODE
#include "InjSpMgt_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
