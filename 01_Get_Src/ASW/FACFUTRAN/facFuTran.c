/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : facFuTran                                               */
/* !Description     : FACFUTRAN : INJECTED FUEL MASS CORRECTION FACTOR DURING LOAD TRANSIENT*/
/*                                                                            */
/* !Module          : facFuTran                                               */
/*                                                                            */
/* !File            : facFuTran.c                                             */
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
/* !Reference       : PTS_DOC_5464905 / 10                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon May 19 23:02:25 2014                              */
/*   Model name       : facFuTran_AUTOCODE.mdl                                */
/*   Model version    : 1.640                                                 */
/*   Root subsystem   : /facFuTran                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/FACFUTRAN/facFuTran.c_v   $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   etsasson                               $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "facFuTran.h"
#include "facFuTran_private.h"

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
#define FACFUTRAN_START_SEC_VAR_UNSPECIFIED
#include "facFuTran_MemMap.h"

/* Block signals (auto storage) */
BlockIO_facFuTran facFuTran_B;

/* Block states (auto storage) */
D_Work_facFuTran facFuTran_DWork;

#define FACFUTRAN_STOP_SEC_VAR_UNSPECIFIED
#include "facFuTran_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define FACFUTRAN_START_SEC_CODE
#include "facFuTran_MemMap.h"

void facFuTran_ASYNC1(int controlPortIdx)
{
}

void facFuTran_ASYNC2(int controlPortIdx)
{
}

void facFuTran_ASYNC3(int controlPortIdx)
{
  facF_F00_facFuTranFctInit_Inhib();
}

/*
 * Output and update for atomic system:
 *    '<S42>/rising_edge'
 *    '<S42>/rising_edge2'
 *    '<S37>/rising_edge1'
 *    '<S189>/Rising_edge'
 *    '<S20>/rising_edge'
 *    '<S20>/rising_edge2'
 *    '<S15>/rising_edge1'
 *    '<S58>/rising_edge'
 *    '<S58>/rising_edge1'
 *    '<S58>/rising_edge2'
 *    '<S58>/rising_edge3'
 */
void facFuTran_rising_edge(Boolean rtu_Signal, rtB_rising_edge_facFuTran_i
  *localB, rtDW_rising_edge_facFuTran_j *localDW)
{
  /* Logic: '<S49>/Logical Operator' incorporates:
   *  Logic: '<S49>/Logical Operator1'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  localB->LogicalOperator = (rtu_Signal && (!localDW->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtu_Signal;
}

/*
 * Initial conditions for atomic system:
 *    '<S35>/facFuTranFctInit_Inhib'
 *    '<S5>/facFuTranFctInit_Inhib'
 */
void fac_facFuTranFctInit_Inhib_Init(rtDW_facFuTranFctInit_Inhib_fac *localDW)
{
  /* InitializeConditions for atomic SubSystem: '<S36>/F01_bACvWfCmp' */

  /* InitializeConditions for UnitDelay: '<S44>/UnitDelay' */
  localDW->UnitDelay = TRUE;

  /* end of InitializeConditions for SubSystem: '<S36>/F01_bACvWfCmp' */
}

/*
 * Output and update for atomic system:
 *    '<S35>/facFuTranFctInit_Inhib'
 *    '<S5>/facFuTranFctInit_Inhib'
 */
void facFuTra_facFuTranFctInit_Inhib(Float32 rtu_InjSys_facTranCmpPrevRmp,
  Boolean rtu_Dv_detection_pied_leve, Boolean rtu_TqSys_bEngNOnIdl, UInt8
  rtu_CoPTSt_stEngNew, UInt8 rtu_Ext_tiTDC, Boolean rtu_CoPTSt_bRStrtSTT,
  UInt32 rtu_InjSys_mFuReq, UInt8 rtu_Eng_noInNxtCyl, Boolean
  rtu_InjSys_bTotCutOff, UInt16 rtu_InjSys_nEngInjSp, Boolean
  rtu_EOM_bTranMod, const UInt16 rtu_InjSys_prm_facInjResuCyl[6],
  rtB_facFuTranFctInit_Inhib_facF *localB, rtDW_facFuTranFctInit_Inhib_fac
  *localDW)
{
  /* local block i/o variables */
  Boolean localRelationalOperator1_g;
  Boolean localRelationalOperator2;
  Boolean localRelationalOperator3_p;
  Boolean localUnitDelay_bg;
  Boolean localLogic_p[2];
  Boolean localLogicalOperator5;
  Boolean localSwitch_fn;
  Boolean localLogicalOperator3_l;
  Float32 localDTConv_UFix_To_Single_2;
  Float32 localSwitch_n;
  Float32 localSwitch2_l;
  Boolean localRelationalOperator1_b;
  Boolean localSwitch2_ll;
  SInt32 localSwitch1_f;
  UInt32 localAdd_g;
  UInt8 localSwitch2_ln;

  /* Outputs for atomic SubSystem: '<S36>/F01_bACvWfCmp' */

  /* RelationalOperator: '<S37>/Relational Operator1' incorporates:
   *  Constant: '<S37>/CoPTSt_stEngRun_SC'
   */
  localRelationalOperator1_g = (rtu_CoPTSt_stEngNew == CoPTSt_stEngRun_SC);

  /* Logic: '<S37>/Logical Operator3' incorporates:
   *  Logic: '<S37>/Logical Operator13'
   *  Logic: '<S37>/Logical Operator2'
   */
  localLogicalOperator3_l = (((!rtu_Dv_detection_pied_leve) &&
    (!rtu_TqSys_bEngNOnIdl)) && (localRelationalOperator1_g));

  /* Logic: '<S42>/Logical Operator3' */
  localUnitDelay_bg = !localRelationalOperator1_g;

  /* UnitDelay: '<S47>/Unit Delay' */
  localLogicalOperator5 = localDW->UnitDelay_DSTATE_e;

  /* Outputs for atomic SubSystem: '<S42>/rising_edge' */
  facFuTran_rising_edge(localRelationalOperator1_g, &localB->rising_edge,
                        &localDW->rising_edge);

  /* end of Outputs for SubSystem: '<S42>/rising_edge' */

  /* DataTypeConversion: '<S42>/DTConv_UFix_To_Single_2' */
  localDTConv_UFix_To_Single_2 = ((Float32)rtu_Ext_tiTDC) * 1.000000047E-003F;

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S37>/InjSys_tiDlyAcvWfSTT_C'
   *  Constant: '<S37>/InjSys_tiDlyAcvWf_C'
   */
  if (rtu_CoPTSt_bRStrtSTT) {
    localSwitch2_ln = InjSys_tiDlyAcvWfSTT_C;
  } else {
    localSwitch2_ln = InjSys_tiDlyAcvWf_C;
  }

  /* Sum: '<S42>/Sum2' incorporates:
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S42>/Constant6'
   *  DataTypeConversion: '<S42>/DTConv_UFix_To_Single_1'
   *  MinMax: '<S42>/MinMax1'
   *  Product: '<S48>/Divide'
   */
  localSwitch2_l = (((Float32)localSwitch2_ln) * 1.000000015E-001F) + (10.0F *
    localDTConv_UFix_To_Single_2);

  /* UnitDelay: '<S46>/Unit Delay' */
  localSwitch_n = localDW->UnitDelay_DSTATE;

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S42>/Constant3'
   *  RelationalOperator: '<S53>/UpperRelop'
   */
  if (localDW->UnitDelay_DSTATE < 0.0F) {
    localSwitch_n = 0.0F;
  }

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/LowerRelop1'
   */
  if (!(localDW->UnitDelay_DSTATE > localSwitch2_l)) {
    localSwitch2_l = localSwitch_n;
  }

  /* Switch: '<S42>/Switch1' incorporates:
   *  Constant: '<S42>/Constant4'
   *  Constant: '<S42>/Constant7'
   *  Logic: '<S42>/Logical Operator2'
   *  Sum: '<S42>/Sum1'
   */
  if ((localLogicalOperator5) || localB->rising_edge.LogicalOperator) {
    localDTConv_UFix_To_Single_2 = 0.0F;
  } else {
    localDTConv_UFix_To_Single_2 = (localDTConv_UFix_To_Single_2 +
      localSwitch2_l) + 2.220446049E-016F;
  }

  /* RelationalOperator: '<S42>/Relational Operator2' incorporates:
   *  MinMax: '<S42>/MinMax1'
   */
  localRelationalOperator2 = (localDTConv_UFix_To_Single_2 >= (((Float32)
    localSwitch2_ln) * 1.000000015E-001F));

  /* Outputs for atomic SubSystem: '<S42>/rising_edge2' */
  facFuTran_rising_edge(localRelationalOperator2, &localB->rising_edge2,
                        &localDW->rising_edge2);

  /* end of Outputs for SubSystem: '<S42>/rising_edge2' */

  /* RelationalOperator: '<S42>/Relational Operator1' incorporates:
   *  Constant: '<S42>/Constant2'
   *  MinMax: '<S42>/MinMax1'
   */
  localRelationalOperator1_b = (localSwitch2_ln == 0);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant5'
   *  Logic: '<S42>/Logical Operator1'
   */
  if (!localRelationalOperator1_b) {
    localLogicalOperator5 = localB->rising_edge2.LogicalOperator;
  } else {
    localLogicalOperator5 = TRUE;
  }

  /* UnitDelay: '<S44>/UnitDelay' */
  localSwitch_fn = localDW->UnitDelay;

  /* CombinatorialLogic: '<S44>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_bg != 0);
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator5 != 0);
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_fn != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_p[0] = facFuTran_ConstP.pooled19[rowidx];
    localLogic_p[1] = facFuTran_ConstP.pooled19[rowidx + 8];
  }

  /* UnitDelay: '<S44>/UnitDelay1' */
  localSwitch_fn = localDW->UnitDelay_c;

  /* Switch: '<S44>/Switch2' incorporates:
   *  Constant: '<S44>/NotCLR3'
   */
  if (localSwitch_fn) {
    localSwitch2_ll = localLogic_p[0];
  } else {
    localSwitch2_ll = TRUE;
  }

  /* Logic: '<S37>/Logical Operator4' incorporates:
   *  Logic: '<S44>/LO3'
   */
  localSwitch_fn = ((localLogicalOperator3_l) || (!localSwitch2_ll));

  /* DataStoreWrite: '<S37>/InjSys_bAcvWfCmpSet_MP_DSW' */
  InjSys_bAcvWfCmpSet_MP = localSwitch_fn;

  /* DataTypeConversion: '<S37>/DTConv_UFix_To_Single_2' incorporates:
   *  Constant: '<S37>/InjSys_noClcnAftrReInjThr_C'
   */
  localSwitch1_f = InjSys_noClcnAftrReInjThr_C;

  /* RelationalOperator: '<S37>/Relational Operator3' incorporates:
   *  Constant: '<S37>/ConstVal_2'
   */
  localRelationalOperator3_p = (0U != rtu_InjSys_mFuReq);

  /* Outputs for atomic SubSystem: '<S37>/rising_edge1' */
  facFuTran_rising_edge(localRelationalOperator3_p, &localB->rising_edge1,
                        &localDW->rising_edge1);

  /* end of Outputs for SubSystem: '<S37>/rising_edge1' */

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<S37>/ConstVal_3'
   *  Logic: '<S37>/Logical Operator10'
   *  Sum: '<S37>/Sum'
   *  UnitDelay: '<S41>/Unit Delay'
   */
  if (!(rtu_Dv_detection_pied_leve && localB->rising_edge1.LogicalOperator)) {
    localSwitch1_f = localDW->UnitDelay_DSTATE_a - 1;
  }

  /* MinMax: '<S37>/MinMax' incorporates:
   *  Constant: '<S37>/ConstVal_6'
   */
  localSwitch1_f = rt_MAX(localSwitch1_f, 0);
  if (localSwitch1_f <= 0) {
    localSwitch2_ln = 0U;
  } else {
    localSwitch2_ln = (UInt8)localSwitch1_f;
  }

  /* DataStoreWrite: '<S37>/InjSys_noClcnAfterReInj_DSW' */
  InjSys_noClcnAfterReInj = localSwitch2_ln;

  /* Logic: '<S37>/Logical Operator5' */
  localLogicalOperator5 = !localRelationalOperator1_g;

  /* UnitDelay: '<S39>/UnitDelay' */
  localUnitDelay_bg = localDW->UnitDelay_b;

  /* CombinatorialLogic: '<S39>/Logic' */
  {
    UInt32 rowidx= 0;

    /* Compute the truth table row index corresponding to the input */
    rowidx = (rowidx << 1) + (UInt32)(localSwitch_fn != 0);
    rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator5 != 0);
    rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_bg != 0);

    /* Copy the appropriate row of the table into the block output vector */
    localLogic_p[0] = facFuTran_ConstP.pooled19[rowidx];
    localLogic_p[1] = facFuTran_ConstP.pooled19[rowidx + 8];
  }

  /* UnitDelay: '<S39>/UnitDelay1' */
  localSwitch_fn = localDW->UnitDelay_o;

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S39>/NotCLR3'
   */
  if (localSwitch_fn) {
    localLogicalOperator3_l = localLogic_p[0];
  } else {
    localLogicalOperator3_l = FALSE;
  }

  /* Sum: '<S40>/Add' incorporates:
   *  Constant: '<S40>/Constant1'
   *  DataTypeConversion: '<S37>/DTConv_UFix_To_Single_1'
   */
  localAdd_g = ((UInt32)rtu_Eng_noInNxtCyl) - 1U;

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/ConstVal'
   *  Constant: '<S37>/ConstVal_1'
   *  Constant: '<S37>/ConstVal_4'
   *  Constant: '<S37>/InjSys_bAcvWfResuTran_C'
   *  Constant: '<S40>/Constant'
   *  Logic: '<S37>/Logical Operator7'
   *  Logic: '<S37>/Logical Operator8'
   *  MinMax: '<S40>/MinMax'
   *  RelationalOperator: '<S37>/Relational Operator2'
   *  Selector: '<S40>/Selector'
   */
  if (InjSys_bAcvWfResuTran_C || (!(rtu_InjSys_prm_facInjResuCyl[rt_MIN
        (localAdd_g, 5U)] > 4369))) {
    localSwitch_fn = TRUE;
  } else {
    localSwitch_fn = FALSE;
  }

  /* Logic: '<S37>/Logical Operator1' incorporates:
   *  Constant: '<S37>/ConstVal_5'
   *  Constant: '<S37>/InjSys_bAcvWfModTran_C'
   *  Constant: '<S37>/InjSys_bAcvfacFuTranClcn_C'
   *  Constant: '<S37>/InjSys_bInhReInjCond_C'
   *  Constant: '<S37>/InjSys_nMaxAcvWf_C'
   *  Logic: '<S37>/Logical Operator'
   *  Logic: '<S37>/Logical Operator11'
   *  Logic: '<S37>/Logical Operator6'
   *  Logic: '<S37>/Logical Operator9'
   *  RelationalOperator: '<S37>/Relational Operator'
   *  RelationalOperator: '<S37>/Relational Operator4'
   */
  localB->LogicalOperator1 = (((((((!rtu_InjSys_bTotCutOff) &&
    (rtu_InjSys_nEngInjSp <= InjSys_nMaxAcvWf_C)) && (localLogicalOperator3_l)) &&
                                 ((!rtu_EOM_bTranMod) || InjSys_bAcvWfModTran_C))
    && InjSys_bAcvfacFuTranClcn_C) && (localSwitch_fn)) && ((localSwitch2_ln <=
    0) || InjSys_bInhReInjCond_C));

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  localDW->UnitDelay_DSTATE_e = localRelationalOperator1_b;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localDTConv_UFix_To_Single_2;

  /* Update for UnitDelay: '<S44>/UnitDelay' */
  localDW->UnitDelay = localSwitch2_ll;

  /* Update for UnitDelay: '<S44>/UnitDelay1' incorporates:
   *  Constant: '<S44>/NotCLR2'
   */
  localDW->UnitDelay_c = TRUE;

  /* Update for UnitDelay: '<S41>/Unit Delay' */
  localDW->UnitDelay_DSTATE_a = localSwitch2_ln;

  /* Update for UnitDelay: '<S39>/UnitDelay' */
  localDW->UnitDelay_b = localLogicalOperator3_l;

  /* Update for UnitDelay: '<S39>/UnitDelay1' incorporates:
   *  Constant: '<S39>/NotCLR2'
   */
  localDW->UnitDelay_o = TRUE;

  /* end of Outputs for SubSystem: '<S36>/F01_bACvWfCmp' */

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/ConstVal'
   *  Logic: '<S36>/Logical Operator1'
   *  Logic: '<S36>/Logical Operator3'
   *  UnitDelay: '<S38>/Unit Delay'
   */
  if (localB->LogicalOperator1 && (!localDW->UnitDelay_DSTATE_b)) {
    localB->Switch1 = 1.0F;
  } else {
    localB->Switch1 = rtu_InjSys_facTranCmpPrevRmp;
  }

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  localDW->UnitDelay_DSTATE_b = localB->LogicalOperator1;
}

/* Start for function-call system: '<S4>/F00_facFuTranFctInit_Inhib' */
void F00_facFuTranFctInit_Inhi_Start(void)
{
  /* Start for enable SubSystem: '<S6>/F00_facFuTranFctInit' */

  /* InitializeConditions for atomic SubSystem: '<S35>/facFuTranFctInit_Inhib' */
  fac_facFuTranFctInit_Inhib_Init(&facFuTran_DWork.facFuTranFctInit_Inhib);

  /* end of InitializeConditions for SubSystem: '<S35>/facFuTranFctInit_Inhib' */

  /* end of Start for SubSystem: '<S6>/F00_facFuTranFctInit' */
}

/* Output and update for function-call system: '<S4>/F00_facFuTranFctInit_Inhib' */
void facF_F00_facFuTranFctInit_Inhib(void)
{
  /* local block i/o variables */
  Float32 localSignalConversion2;

  /* Outputs for enable SubSystem: '<S6>/F00_facFuTranFctInit' incorporates:
   *  Constant: '<S6>/ConstVal'
   *  Constant: '<S6>/FACFUTRAN_u8Inhib'
   *  EnablePort: '<S35>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (FACFUTRAN_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bTotCutOff, facFuTran_B.VEMS_vidGET6_b);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_nEngInjSp, facFuTran_B.VEMS_vidGET8_n);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_tiTDC, facFuTran_B.VEMS_vidGET5_e);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_stEngNew, facFuTran_B.VEMS_vidGET1_d);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET10 */
    VEMS_vidGET(TqSys_bEngNOnIdl, facFuTran_B.VEMS_vidGET10_j);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET3 */
    VEMS_vidGET(EOM_bTranMod, facFuTran_B.VEMS_vidGET3_d);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_facInjResuCyl, 6, facFuTran_B.VEMS_vidGET9_c);

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate'
     *
     * Regarding '<S40>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET4 */
    VEMS_vidGET(Eng_noInNxtCyl, facFuTran_B.VEMS_vidGET4_m);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET */
    VEMS_vidGET(CoPTSt_bRStrtSTT, facFuTran_B.VEMS_vidGET_k);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET2 */
    VEMS_vidGET(Dv_detection_pied_leve, facFuTran_B.VEMS_vidGET2_m);

    /* S-Function "vems_vidGET" Block: <S35>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_mFuReq, facFuTran_B.VEMS_vidGET7_h);

    /* SignalConversion: '<S35>/Signal Conversion2' */
    localSignalConversion2 = InjSys_facTranCmpPrevRmp;

    /* Outputs for atomic SubSystem: '<S35>/facFuTranFctInit_Inhib' */
    facFuTra_facFuTranFctInit_Inhib(localSignalConversion2,
      facFuTran_B.VEMS_vidGET2_m, facFuTran_B.VEMS_vidGET10_j,
      facFuTran_B.VEMS_vidGET1_d, facFuTran_B.VEMS_vidGET5_e,
      facFuTran_B.VEMS_vidGET_k, facFuTran_B.VEMS_vidGET7_h,
      facFuTran_B.VEMS_vidGET4_m, facFuTran_B.VEMS_vidGET6_b,
      facFuTran_B.VEMS_vidGET8_n, facFuTran_B.VEMS_vidGET3_d,
      facFuTran_B.VEMS_vidGET9_c, &facFuTran_B.facFuTranFctInit_Inhib,
      &facFuTran_DWork.facFuTranFctInit_Inhib);

    /* end of Outputs for SubSystem: '<S35>/facFuTranFctInit_Inhib' */

    /* SignalConversion: '<S35>/Signal Conversion1' */
    InjSys_facTranCmpPrevRmp = facFuTran_B.facFuTranFctInit_Inhib.Switch1;

    /* S-Function "vems_vidSET" Block: <S35>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvWfCmp,
                facFuTran_B.facFuTranFctInit_Inhib.LogicalOperator1);
  }

  /* end of Outputs for SubSystem: '<S6>/F00_facFuTranFctInit' */
}

/*
 * Outputs for atomic system:
 *    '<S178>/rising_edge'
 *    '<S178>/rising_edge1'
 *    '<S179>/rising_edge1'
 *    '<S179>/rising_edge2'
 *    '<S180>/rising_edge1'
 *    '<S180>/rising_edge2'
 *    '<S181>/rising_edge'
 *    '<S181>/rising_edge1'
 */
void facFuTran_rising_edge_m(Boolean rtu_Signal, rtB_rising_edge_facFuTran
  *localB, rtDW_rising_edge_facFuTran *localDW)
{
  /* Logic: '<S185>/Logical Operator' incorporates:
   *  Logic: '<S185>/Logical Operator1'
   *  UnitDelay: '<S187>/Unit Delay'
   */
  localB->LogicalOperator = (rtu_Signal && (!localDW->UnitDelay_DSTATE));
}

/*
 * Update for atomic system:
 *    '<S178>/rising_edge'
 *    '<S178>/rising_edge1'
 *    '<S179>/rising_edge1'
 *    '<S179>/rising_edge2'
 *    '<S180>/rising_edge1'
 *    '<S180>/rising_edge2'
 *    '<S181>/rising_edge'
 *    '<S181>/rising_edge1'
 */
void facFuTran_rising_edge_l_Update(Boolean rtu_Signal,
  rtDW_rising_edge_facFuTran *localDW)
{
  /* Update for UnitDelay: '<S187>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtu_Signal;
}

/* Start for function-call system: '<S4>/F01_facFuTranFct' */
void facFuTra_F01_facFuTranFct_Start(void)
{
  /* Start for enable SubSystem: '<S8>/F01_facFuTranFct' */

  /* Start for If: '<S90>/If' */
  facFuTran_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S90>/F01_facFuTranClcn' */

  /* InitializeConditions for atomic SubSystem: '<S92>/F05_facTranCmpFilClcn' */

  /* InitializeConditions for atomic SubSystem: '<S99>/F04_TranCmpFil' */

  /* InitializeConditions for UnitDelay: '<S214>/UnitDelay' */
  facFuTran_DWork.UnitDelay_kb = TRUE;

  /* end of InitializeConditions for SubSystem: '<S99>/F04_TranCmpFil' */

  /* end of InitializeConditions for SubSystem: '<S92>/F05_facTranCmpFilClcn' */

  /* end of Start for SubSystem: '<S90>/F01_facFuTranClcn' */

  /* end of Start for SubSystem: '<S8>/F01_facFuTranFct' */
}

/* Output and update for function-call system: '<S4>/F01_facFuTranFct' */
void facFuTran_F01_facFuTranFct(void)
{
  /* local block i/o variables */
  Float32 localSwitch_f;
  Boolean localRelationalOperator;
  Boolean localSwitch2_e;
  Boolean localLogicalOperator1_n;
  Boolean localSwitch2_i;
  Boolean localUnitDelay_k;
  Boolean localLogic[2];
  Boolean localUnitDelay_b;
  Boolean localLogic_l[2];
  UInt8 localDataTypeConversion_o;
  UInt8 localLookUpTable2D;
  UInt8 localLookUpTable2D_o;
  SInt8 localrtAction;
  UInt32 localAdd_ks;
  SInt32 localDataTypeConversion1_f;
  SInt32 localDataTypeConversion2;
  SInt32 localDataTypeConversion3_f;
  Float32 localLookupTablenD;
  Float32 localSwitch_c;
  UInt32 localAdd;
  SInt32 localSwitch_e;
  UInt32 localAdd_h;
  Boolean localAssignment[6];
  UInt32 localAdd_m;
  UInt32 localAdd_k;
  Float32 localInterpolationUsingPrelooku;
  Float32 localfrac[2];
  Float32 localExt_tCoMes_InjSys_tCoMes_A;
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localInjSys_nEngInjSp_InjSys_nE;
  Float32 localfractionTmp_0d;
  Float32 localfrac_1[2];
  Float32 localInjSys_mAirPredInjSp_InjSy;
  UInt32 localbpIndex_1[2];
  Float32 localfrac_2[2];
  UInt32 localbpIndex_2[2];
  Float32 localfrac_3[2];
  UInt32 localbpIndex_3[2];
  Float32 localfrac_4[2];
  UInt32 localbpIndex_4[2];
  Float32 localfrac_5[2];
  UInt32 localbpIndex_5[2];
  Float32 localfrac_6[2];
  UInt32 localbpIndex_6[2];
  Float32 localfrac_7[2];
  UInt32 localbpIndex_7[2];
  Float32 localfrac_8[2];
  UInt32 localbpIndex_8[2];
  Float32 localfrac_9[2];
  UInt32 localbpIndex_9[2];
  Float32 localfrac_a[2];
  UInt32 localbpIndex_a[2];
  Float32 localfrac_b[2];
  UInt32 localbpIndex_b[2];
  Float32 localfrac_c[2];
  UInt32 localbpIndex_c[2];
  Boolean localLowerRelop1_m;
  Float32 localSwitch;
  UInt8 locallocalDataTypeConversion1_h;
  UInt8 locallocalDataTypeConversion2_o;
  UInt16 locallocalSwitch_g;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/ConstVal'
   *  Constant: '<S8>/FACFUTRAN_u8Inhib'
   */
  localRelationalOperator = (FACFUTRAN_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S8>/F01_facFuTranFct' incorporates:
   *  EnablePort: '<S90>/Enable'
   */
  if (localRelationalOperator) {
    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET14 */
    VEMS_vidGET(InjSys_bAcvWfCmp, facFuTran_B.VEMS_vidGET14);

    /* Outputs for atomic SubSystem: '<S91>/rising_edge' */

    /* Logic: '<S94>/Logical Operator' incorporates:
     *  Logic: '<S94>/Logical Operator1'
     *  UnitDelay: '<S95>/Unit Delay'
     */
    InjSys_bDetAcvWfCmp = (facFuTran_B.VEMS_vidGET14 &&
      (!facFuTran_DWork.UnitDelay_DSTATE_k1));

    /* Update for UnitDelay: '<S95>/Unit Delay' */
    facFuTran_DWork.UnitDelay_DSTATE_k1 = facFuTran_B.VEMS_vidGET14;

    /* end of Outputs for SubSystem: '<S91>/rising_edge' */
    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET12 */
    VEMS_vidGET(InjSys_mAirPredInjSp, facFuTran_B.VEMS_vidGET12);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET13 */
    VEMS_vidGET(InjSys_nEngInjSp, facFuTran_B.VEMS_vidGET13);

    /* DataTypeConversion Block: '<S183>/Data Type Conversion'
     *
     * Regarding '<S183>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S184>/Data Type Conversion'
     *
     * Regarding '<S184>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET10 */
    VEMS_vidGET(FISA_facWupAdp, facFuTran_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET8 */
    VEMS_vidGET(Ext_tCoMes, facFuTran_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET7 */
    VEMS_vidGET(Ext_tAirExtMes, facFuTran_B.VEMS_vidGET7_o);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET9 */
    VEMS_vidGET(Ext_tCoStrtMes, facFuTran_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET11 */
    VEMS_vidGET(InjSys_ctNbCmbAst, facFuTran_B.VEMS_vidGET11);

    /* DataTypeDuplicate Block: '<S173>/Data Type Duplicate2'
     *
     * Regarding '<S173>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(EOM_prm_idxBas1ModCur, 16, facFuTran_B.VEMS_vidGET3_g);

    /* DataTypeDuplicate Block: '<S100>/Data Type Duplicate'
     *
     * Regarding '<S100>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(EOM_prm_idxBas2ModCur, 16, facFuTran_B.VEMS_vidGET5);

    /* DataTypeDuplicate Block: '<S101>/Data Type Duplicate'
     *
     * Regarding '<S101>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(EOM_prm_idxBas1ModTar, 16, facFuTran_B.VEMS_vidGET4_i);

    /* DataTypeDuplicate Block: '<S102>/Data Type Duplicate'
     *
     * Regarding '<S102>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(EOM_prm_idxBas2ModTar, 16, facFuTran_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S103>/Data Type Duplicate'
     *
     * Regarding '<S103>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET */
    VEMS_vidGET1DArray(EOM_prm_facBasModCur, 16, facFuTran_B.VEMS_vidGET_p);

    /* DataTypeDuplicate Block: '<S104>/Data Type Duplicate'
     *
     * Regarding '<S104>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(EOM_prm_facBasModTar, 16, facFuTran_B.VEMS_vidGET1_m);

    /* DataTypeDuplicate Block: '<S105>/Data Type Duplicate'
     *
     * Regarding '<S105>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S90>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(EOM_prm_facTranMod, 16, facFuTran_B.VEMS_vidGET2_d);

    /* DataTypeDuplicate Block: '<S106>/Data Type Duplicate'
     *
     * Regarding '<S106>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* If: '<S90>/If' incorporates:
     *  ActionPort: '<S92>/Action Port'
     *  ActionPort: '<S93>/Action Port'
     *  SubSystem: '<S90>/F01_facFuTranClcn'
     *  SubSystem: '<S90>/F02_facFuTrannoClcn '
     */
    if (facFuTran_B.VEMS_vidGET14) {
      localrtAction = 0;

      /* DataTypeConversion: '<S92>/Data Type Conversion' */
      localSwitch_e = facFuTran_B.VEMS_vidGET8 + 40;
      if (localSwitch_e <= 0) {
        localDataTypeConversion_o = 0U;
      } else if (localSwitch_e > 255) {
        localDataTypeConversion_o = MAX_uint8_T;
      } else {
        localDataTypeConversion_o = (UInt8)localSwitch_e;
      }

      /* Outputs for atomic SubSystem: '<S92>/F01_IfEOMfacTranSp' */

      /* DataTypeConversion: '<S96>/Data Type Conversion' incorporates:
       *  Constant: '<S104>/Constant'
       *  MinMax: '<S104>/MinMax'
       *  Selector: '<S104>/Selector'
       */
      InjSys_facBasModCurInjTran = ((Float32)facFuTran_B.VEMS_vidGET_p[3]) *
        0.0078125F;

      /* DataTypeConversion: '<S96>/Data Type Conversion1' incorporates:
       *  Constant: '<S105>/Constant'
       *  MinMax: '<S105>/MinMax'
       *  Selector: '<S105>/Selector'
       */
      InjSys_facBasModTarInjTran = ((Float32)facFuTran_B.VEMS_vidGET1_m[3]) *
        0.0078125F;

      /* DataTypeConversion: '<S96>/Data Type Conversion2' incorporates:
       *  Constant: '<S106>/Constant'
       *  MinMax: '<S106>/MinMax'
       *  Selector: '<S106>/Selector'
       */
      InjSys_facTranModInjTran = ((Float32)facFuTran_B.VEMS_vidGET2_d[3]) *
        0.0078125F;

      /* Selector: '<S100>/Selector' incorporates:
       *  Constant: '<S100>/Constant'
       *  MinMax: '<S100>/MinMax'
       */
      InjSys_idxBas1ModCurInjTran = facFuTran_B.VEMS_vidGET3_g[3];

      /* Selector: '<S101>/Selector' incorporates:
       *  Constant: '<S101>/Constant'
       *  MinMax: '<S101>/MinMax'
       */
      InjSys_idxBas2ModCurInjTran = facFuTran_B.VEMS_vidGET5[3];

      /* Selector: '<S102>/Selector' incorporates:
       *  Constant: '<S102>/Constant'
       *  MinMax: '<S102>/MinMax'
       */
      InjSys_idxBas1ModTarInjTran = facFuTran_B.VEMS_vidGET4_i[3];

      /* Selector: '<S103>/Selector' incorporates:
       *  Constant: '<S103>/Constant'
       *  MinMax: '<S103>/MinMax'
       */
      InjSys_idxBas2ModTarInjTran = facFuTran_B.VEMS_vidGET6[3];

      /* end of Outputs for SubSystem: '<S92>/F01_IfEOMfacTranSp' */

      /* Outputs for atomic SubSystem: '<S92>/F03_facTranSpClcn' */

      /* DataTypeConversion: '<S97>/Data Type Conversion1' */
      localDataTypeConversion1_f = InjSys_idxBas2ModCurInjTran;

      /* DataTypeConversion: '<S97>/Data Type Conversion2' */
      localDataTypeConversion2 = InjSys_idxBas1ModTarInjTran;

      /* DataTypeConversion: '<S97>/Data Type Conversion3' */
      localDataTypeConversion3_f = InjSys_idxBas2ModTarInjTran;

      /* DataTypeConversion: '<S97>/Data Type Conversion4' */
      localAdd_ks = InjSys_idxBas1ModCurInjTran;

      /* Outputs for atomic SubSystem: '<S97>/F01_Mode_Mask_InjTran' */

      /* DataTypeConversion: '<S107>/DTConv_UFix_To_Single_1' incorporates:
       *  Constant: '<S107>/InjSys_idxModInjTranSatMax_C'
       */
      localAdd = InjSys_idxModInjTranSatMax_C;

      /* DataTypeConversion: '<S107>/DTConv_UFix_To_Single_2' incorporates:
       *  Constant: '<S107>/InjSys_idxModInjTranSatMin_C'
       */
      localSwitch_e = InjSys_idxModInjTranSatMin_C;

      /* Switch: '<S121>/Switch' incorporates:
       *  RelationalOperator: '<S121>/UpperRelop'
       */
      if (localAdd_ks < ((UInt32)localSwitch_e)) {
        localAdd_h = (UInt32)localSwitch_e;
      } else {
        localAdd_h = localAdd_ks;
      }

      /* Switch: '<S121>/Switch2' incorporates:
       *  RelationalOperator: '<S121>/LowerRelop1'
       */
      if (localAdd_ks > localAdd) {
        localAdd_h = localAdd;
      }

      /* Switch: '<S124>/Switch' incorporates:
       *  RelationalOperator: '<S124>/UpperRelop'
       */
      if (((UInt32)localDataTypeConversion1_f) < ((UInt32)localSwitch_e)) {
        localAdd_m = (UInt32)localSwitch_e;
      } else {
        localAdd_m = (UInt32)localDataTypeConversion1_f;
      }

      /* Switch: '<S124>/Switch2' incorporates:
       *  RelationalOperator: '<S124>/LowerRelop1'
       */
      if (((UInt32)localDataTypeConversion1_f) > localAdd) {
        localAdd_m = localAdd;
      }

      /* Switch: '<S127>/Switch' incorporates:
       *  RelationalOperator: '<S127>/UpperRelop'
       */
      if (((UInt32)localDataTypeConversion2) < ((UInt32)localSwitch_e)) {
        localAdd_k = (UInt32)localSwitch_e;
      } else {
        localAdd_k = (UInt32)localDataTypeConversion2;
      }

      /* Switch: '<S127>/Switch2' incorporates:
       *  RelationalOperator: '<S127>/LowerRelop1'
       */
      if (((UInt32)localDataTypeConversion2) > localAdd) {
        localAdd_k = localAdd;
      }

      /* Switch: '<S130>/Switch' incorporates:
       *  RelationalOperator: '<S130>/UpperRelop'
       */
      if (!(((UInt32)localDataTypeConversion3_f) < ((UInt32)localSwitch_e)))
      {
        localSwitch_e = localDataTypeConversion3_f;
      }

      /* Switch: '<S130>/Switch2' incorporates:
       *  RelationalOperator: '<S130>/LowerRelop1'
       */
      if (!(((UInt32)localDataTypeConversion3_f) > localAdd)) {
        localAdd = (UInt32)localSwitch_e;
      }

      /* Sum: '<S115>/Add' incorporates:
       *  Constant: '<S115>/Constant1'
       */
      localAdd_h--;

      /* SignalConversion: '<S115>/TmpSignal ConversionAtAssignmentInport1' incorporates:
       *  Constant: '<S107>/ConstVal'
       */
      localAssignment[0] = FALSE;
      localAssignment[1] = FALSE;
      localAssignment[2] = FALSE;
      localAssignment[3] = FALSE;
      localAssignment[4] = FALSE;
      localAssignment[5] = FALSE;

      /* Assignment: '<S115>/Assignment' incorporates:
       *  Constant: '<S107>/ConstVal_5'
       *  Constant: '<S115>/Constant'
       *  MinMax: '<S115>/MinMax'
       */
      localAssignment[(SInt32)rt_MIN(localAdd_h, 5U)] = TRUE;

      /* Sum: '<S116>/Add' incorporates:
       *  Constant: '<S116>/Constant1'
       */
      localAdd_m--;

      /* Assignment: '<S116>/Assignment' incorporates:
       *  Constant: '<S107>/ConstVal_1'
       *  Constant: '<S116>/Constant'
       *  MinMax: '<S116>/MinMax'
       */
      localAssignment[(SInt32)rt_MIN(localAdd_m, 5U)] = TRUE;

      /* Sum: '<S117>/Add' incorporates:
       *  Constant: '<S117>/Constant1'
       */
      localAdd_k--;

      /* Assignment: '<S117>/Assignment' incorporates:
       *  Constant: '<S107>/ConstVal_2'
       *  Constant: '<S117>/Constant'
       *  MinMax: '<S117>/MinMax'
       */
      localAssignment[(SInt32)rt_MIN(localAdd_k, 5U)] = TRUE;

      /* Sum: '<S118>/Add' incorporates:
       *  Constant: '<S118>/Constant1'
       */
      localAdd--;

      /* Assignment: '<S118>/Assignment' incorporates:
       *  Constant: '<S107>/ConstVal_3'
       *  Constant: '<S118>/Constant'
       *  MinMax: '<S118>/MinMax'
       */
      for (localSwitch_e = 0; localSwitch_e < 6; localSwitch_e++) {
        InjSys_prm_bAcvInjTranSpCal[(localSwitch_e)] =
          localAssignment[localSwitch_e];
      }

      InjSys_prm_bAcvInjTranSpCal[rt_MIN(localAdd, 5U)] = TRUE;

      /* end of Outputs for SubSystem: '<S97>/F01_Mode_Mask_InjTran' */

      /* Outputs for atomic SubSystem: '<S97>/F02_Calibrations_InjTran' */

      /* Outputs for atomic SubSystem: '<S108>/F01_Unvectorize_Activation_Boolean_InjTran' */

      /* SignalConversion: '<S131>/Signal Conversion' */
      InjSys_bAcvInjTranSpCal1 = InjSys_prm_bAcvInjTranSpCal[0];

      /* SignalConversion: '<S131>/Signal Conversion1' */
      InjSys_bAcvInjTranSpCal2 = InjSys_prm_bAcvInjTranSpCal[1];

      /* SignalConversion: '<S131>/Signal Conversion2' */
      InjSys_bAcvInjTranSpCal3 = InjSys_prm_bAcvInjTranSpCal[2];

      /* SignalConversion: '<S131>/Signal Conversion3' */
      InjSys_bAcvInjTranSpCal4 = InjSys_prm_bAcvInjTranSpCal[3];

      /* SignalConversion: '<S131>/Signal Conversion4' */
      InjSys_bAcvInjTranSpCal5 = InjSys_prm_bAcvInjTranSpCal[4];

      /* SignalConversion: '<S131>/Signal Conversion5' */
      InjSys_bAcvInjTranSpCal6 = InjSys_prm_bAcvInjTranSpCal[5];

      /* end of Outputs for SubSystem: '<S108>/F01_Unvectorize_Activation_Boolean_InjTran' */

      /* PreLookup: '<S141>/Prelookup' */
      localAdd = plook_u32u16f_binc(facFuTran_B.VEMS_vidGET13,
        (&(InjSys_nEngInjSpTranX_A[0])), 8U, &localInjSys_nEngInjSp_InjSys_nE);

      /* PreLookup: '<S140>/Prelookup' */
      localAdd_h = plook_u32u16f_binc(facFuTran_B.VEMS_vidGET12,
        (&(InjSys_mAirInjSpTranY_A[0])), 8U, &localInjSys_mAirPredInjSp_InjSy);

      /* Outputs for enable SubSystem: '<S108>/F02_Calibration_1_InjTran' incorporates:
       *  EnablePort: '<S132>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal1) {
        /* Interpolation_n-D: '<S142>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_1[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_1[1] = localfractionTmp_0d;
        localbpIndex_1[0] = localAdd;
        localbpIndex_1[1] = localAdd_h;
        InjSys_facTranAccSpCal1 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_1,
          localfrac_1, (&(InjSys_facTranAccCal1_M[0])), 9U);

        /* Interpolation_n-D: '<S143>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_2[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_2[1] = localfractionTmp_0d;
        localbpIndex_2[0] = localAdd;
        localbpIndex_2[1] = localAdd_h;
        InjSys_facTranDecSpCal1 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_2,
          localfrac_2, (&(InjSys_facTranDecCal1_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F02_Calibration_1_InjTran' */

      /* Outputs for enable SubSystem: '<S108>/F03_Calibration_2_InjTran' incorporates:
       *  EnablePort: '<S133>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal2) {
        /* Interpolation_n-D: '<S144>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_3[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_3[1] = localfractionTmp_0d;
        localbpIndex_3[0] = localAdd;
        localbpIndex_3[1] = localAdd_h;
        InjSys_facTranAccSpCal2 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_3,
          localfrac_3, (&(InjSys_facTranAccCal2_M[0])), 9U);

        /* Interpolation_n-D: '<S145>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_4[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_4[1] = localfractionTmp_0d;
        localbpIndex_4[0] = localAdd;
        localbpIndex_4[1] = localAdd_h;
        InjSys_facTranDecSpCal2 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_4,
          localfrac_4, (&(InjSys_facTranDecCal2_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F03_Calibration_2_InjTran' */

      /* Outputs for enable SubSystem: '<S108>/F04_Calibration_3_InjTran' incorporates:
       *  EnablePort: '<S134>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal3) {
        /* Interpolation_n-D: '<S146>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_5[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_5[1] = localfractionTmp_0d;
        localbpIndex_5[0] = localAdd;
        localbpIndex_5[1] = localAdd_h;
        InjSys_facTranAccSpCal3 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_5,
          localfrac_5, (&(InjSys_facTranAccCal3_M[0])), 9U);

        /* Interpolation_n-D: '<S147>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_6[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_6[1] = localfractionTmp_0d;
        localbpIndex_6[0] = localAdd;
        localbpIndex_6[1] = localAdd_h;
        InjSys_facTranDecSpCal3 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_6,
          localfrac_6, (&(InjSys_facTranDecCal3_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F04_Calibration_3_InjTran' */

      /* Outputs for enable SubSystem: '<S108>/F05_Calibration_4_InjTran' incorporates:
       *  EnablePort: '<S135>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal4) {
        /* Interpolation_n-D: '<S148>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_7[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_7[1] = localfractionTmp_0d;
        localbpIndex_7[0] = localAdd;
        localbpIndex_7[1] = localAdd_h;
        InjSys_facTranAccSpCal4 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_7,
          localfrac_7, (&(InjSys_facTranAccCal4_M[0])), 9U);

        /* Interpolation_n-D: '<S149>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_8[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_8[1] = localfractionTmp_0d;
        localbpIndex_8[0] = localAdd;
        localbpIndex_8[1] = localAdd_h;
        InjSys_facTranDecSpCal4 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_8,
          localfrac_8, (&(InjSys_facTranDecCal4_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F05_Calibration_4_InjTran' */

      /* Outputs for enable SubSystem: '<S108>/F06_Calibration_5_InjTran' incorporates:
       *  EnablePort: '<S136>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal5) {
        /* Interpolation_n-D: '<S150>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_9[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_9[1] = localfractionTmp_0d;
        localbpIndex_9[0] = localAdd;
        localbpIndex_9[1] = localAdd_h;
        InjSys_facTranAccSpCal5 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_9,
          localfrac_9, (&(InjSys_facTranAccCal5_M[0])), 9U);

        /* Interpolation_n-D: '<S151>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_a[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_a[1] = localfractionTmp_0d;
        localbpIndex_a[0] = localAdd;
        localbpIndex_a[1] = localAdd_h;
        InjSys_facTranDecSpCal5 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_a,
          localfrac_a, (&(InjSys_facTranDecCal5_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F06_Calibration_5_InjTran' */

      /* Outputs for enable SubSystem: '<S108>/F07_Calibration_6_InjTran' incorporates:
       *  EnablePort: '<S137>/Enable'
       */
      if (InjSys_bAcvInjTranSpCal6) {
        /* Interpolation_n-D: '<S152>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_b[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_b[1] = localfractionTmp_0d;
        localbpIndex_b[0] = localAdd;
        localbpIndex_b[1] = localAdd_h;
        InjSys_facTranAccSpCal6 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_b,
          localfrac_b, (&(InjSys_facTranAccCal6_M[0])), 9U);

        /* Interpolation_n-D: '<S153>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localInjSys_nEngInjSp_InjSys_nE;
        localfrac_c[0] = localfractionTmp_0d;
        localfractionTmp_0d = localInjSys_mAirPredInjSp_InjSy;
        localfrac_c[1] = localfractionTmp_0d;
        localbpIndex_c[0] = localAdd;
        localbpIndex_c[1] = localAdd_h;
        InjSys_facTranDecSpCal6 = intrp2d_iu16n12ff_u32f_l_ns(localbpIndex_c,
          localfrac_c, (&(InjSys_facTranDecCal6_M[0])), 9U);
      }

      /* end of Outputs for SubSystem: '<S108>/F07_Calibration_6_InjTran' */

      /* Outputs for atomic SubSystem: '<S108>/F08_Vectorize_Calibrations_InjTranDec' */

      /* SignalConversion: '<S138>/Signal Conversion' */
      InjSys_prm_facTranDecSpCal[0] = InjSys_facTranDecSpCal1;
      InjSys_prm_facTranDecSpCal[1] = InjSys_facTranDecSpCal2;
      InjSys_prm_facTranDecSpCal[2] = InjSys_facTranDecSpCal3;
      InjSys_prm_facTranDecSpCal[3] = InjSys_facTranDecSpCal4;
      InjSys_prm_facTranDecSpCal[4] = InjSys_facTranDecSpCal5;
      InjSys_prm_facTranDecSpCal[5] = InjSys_facTranDecSpCal6;

      /* end of Outputs for SubSystem: '<S108>/F08_Vectorize_Calibrations_InjTranDec' */

      /* Outputs for atomic SubSystem: '<S108>/F09_Vectorize_Calibrations_InjTranAcc' */

      /* SignalConversion: '<S139>/Signal Conversion' */
      InjSys_prm_facTranAccSpCal[0] = InjSys_facTranAccSpCal1;
      InjSys_prm_facTranAccSpCal[1] = InjSys_facTranAccSpCal2;
      InjSys_prm_facTranAccSpCal[2] = InjSys_facTranAccSpCal3;
      InjSys_prm_facTranAccSpCal[3] = InjSys_facTranAccSpCal4;
      InjSys_prm_facTranAccSpCal[4] = InjSys_facTranAccSpCal5;
      InjSys_prm_facTranAccSpCal[5] = InjSys_facTranAccSpCal6;

      /* end of Outputs for SubSystem: '<S108>/F09_Vectorize_Calibrations_InjTranAcc' */

      /* Switch: '<S108>/Switch' */
      for (localSwitch_e = 0; localSwitch_e < 6; localSwitch_e++) {
        if (InjSys_bDetDecTran) {
          InjSys_prm_facTranSpCal[(localSwitch_e)] = InjSys_prm_facTranDecSpCal
            [(localSwitch_e)];
        } else {
          InjSys_prm_facTranSpCal[(localSwitch_e)] = InjSys_prm_facTranAccSpCal
            [(localSwitch_e)];
        }
      }

      /* end of Outputs for SubSystem: '<S97>/F02_Calibrations_InjTran' */

      /* Outputs for atomic SubSystem: '<S97>/F03_Select_Modes_InjTran' */

      /* Sum: '<S154>/Add' incorporates:
       *  Constant: '<S154>/Constant1'
       */
      localAdd_ks--;

      /* Selector: '<S154>/Selector' incorporates:
       *  Constant: '<S154>/Constant'
       *  MinMax: '<S154>/MinMax'
       */
      InjSys_facTranSpBas1ModCur = InjSys_prm_facTranSpCal[rt_MIN(localAdd_ks,
        5U)];

      /* Sum: '<S155>/Add' incorporates:
       *  Constant: '<S155>/Constant1'
       */
      localAdd_ks = ((UInt32)localDataTypeConversion1_f) - 1U;

      /* Selector: '<S155>/Selector' incorporates:
       *  Constant: '<S155>/Constant'
       *  MinMax: '<S155>/MinMax'
       */
      InjSys_facTranSpBas2ModCur = InjSys_prm_facTranSpCal[rt_MIN(localAdd_ks,
        5U)];

      /* Sum: '<S156>/Add' incorporates:
       *  Constant: '<S156>/Constant1'
       */
      localAdd_ks = ((UInt32)localDataTypeConversion2) - 1U;

      /* Selector: '<S156>/Selector' incorporates:
       *  Constant: '<S156>/Constant'
       *  MinMax: '<S156>/MinMax'
       */
      InjSys_facTranSpBas1ModTar = InjSys_prm_facTranSpCal[rt_MIN(localAdd_ks,
        5U)];

      /* Sum: '<S157>/Add' incorporates:
       *  Constant: '<S157>/Constant1'
       */
      localAdd_ks = ((UInt32)localDataTypeConversion3_f) - 1U;

      /* Selector: '<S157>/Selector' incorporates:
       *  Constant: '<S157>/Constant'
       *  MinMax: '<S157>/MinMax'
       */
      InjSys_facTranSpBas2ModTar = InjSys_prm_facTranSpCal[rt_MIN(localAdd_ks,
        5U)];

      /* end of Outputs for SubSystem: '<S97>/F03_Select_Modes_InjTran' */

      /* Outputs for atomic SubSystem: '<S97>/F04_Interpolation_InjTran' */

      /* Switch: '<S164>/Switch' incorporates:
       *  Constant: '<S158>/Constant1'
       *  RelationalOperator: '<S164>/UpperRelop'
       */
      if (InjSys_facBasModTarInjTran < 0.0F) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = InjSys_facBasModTarInjTran;
      }

      /* Switch: '<S164>/Switch2' incorporates:
       *  Constant: '<S158>/Constant'
       *  RelationalOperator: '<S164>/LowerRelop1'
       */
      if (InjSys_facBasModTarInjTran > 1.0F) {
        localfractionTmp_0d = 1.0F;
      }

      /* Sum: '<S158>/Sum2' incorporates:
       *  Product: '<S158>/Divide'
       *  Sum: '<S158>/Sum3'
       */
      InjSys_facTranSpModTar_MP = ((InjSys_facTranSpBas1ModTar -
        InjSys_facTranSpBas2ModTar) * localfractionTmp_0d) +
        InjSys_facTranSpBas2ModTar;

      /* Switch: '<S168>/Switch' incorporates:
       *  Constant: '<S159>/Constant1'
       *  RelationalOperator: '<S168>/UpperRelop'
       */
      if (InjSys_facBasModCurInjTran < 0.0F) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = InjSys_facBasModCurInjTran;
      }

      /* Switch: '<S168>/Switch2' incorporates:
       *  Constant: '<S159>/Constant'
       *  RelationalOperator: '<S168>/LowerRelop1'
       */
      if (InjSys_facBasModCurInjTran > 1.0F) {
        localfractionTmp_0d = 1.0F;
      }

      /* Sum: '<S159>/Sum2' incorporates:
       *  Product: '<S159>/Divide'
       *  Sum: '<S159>/Sum3'
       */
      InjSys_facTranSpModCur_MP = ((InjSys_facTranSpBas1ModCur -
        InjSys_facTranSpBas2ModCur) * localfractionTmp_0d) +
        InjSys_facTranSpBas2ModCur;

      /* Switch: '<S172>/Switch' incorporates:
       *  Constant: '<S160>/Constant1'
       *  RelationalOperator: '<S172>/UpperRelop'
       */
      if (InjSys_facTranModInjTran < 0.0F) {
        localfractionTmp_0d = 0.0F;
      } else {
        localfractionTmp_0d = InjSys_facTranModInjTran;
      }

      /* Switch: '<S172>/Switch2' incorporates:
       *  Constant: '<S160>/Constant'
       *  RelationalOperator: '<S172>/LowerRelop1'
       */
      if (InjSys_facTranModInjTran > 1.0F) {
        localfractionTmp_0d = 1.0F;
      }

      /* Sum: '<S160>/Sum2' incorporates:
       *  Product: '<S160>/Divide'
       *  Sum: '<S160>/Sum3'
       */
      InjSys_facTranSp = ((InjSys_facTranSpModTar_MP - InjSys_facTranSpModCur_MP)
                          * localfractionTmp_0d) + InjSys_facTranSpModCur_MP;

      /* end of Outputs for SubSystem: '<S97>/F04_Interpolation_InjTran' */

      /* end of Outputs for SubSystem: '<S92>/F03_facTranSpClcn' */

      /* Outputs for atomic SubSystem: '<S92>/F04_facTranCmpIniClcn' */

      /* DataTypeConversion: '<S98>/Data Type Conversion1' */
      localSwitch_e = facFuTran_B.VEMS_vidGET7_o + 50;
      if (localSwitch_e <= 0) {
        locallocalDataTypeConversion1_h = 0U;
      } else if (localSwitch_e > 255) {
        locallocalDataTypeConversion1_h = MAX_uint8_T;
      } else {
        locallocalDataTypeConversion1_h = (UInt8)localSwitch_e;
      }

      /* DataTypeConversion: '<S98>/Data Type Conversion2' */
      localSwitch_e = facFuTran_B.VEMS_vidGET9 + 40;
      if (localSwitch_e <= 0) {
        locallocalDataTypeConversion2_o = 0U;
      } else if (localSwitch_e > 255) {
        locallocalDataTypeConversion2_o = MAX_uint8_T;
      } else {
        locallocalDataTypeConversion2_o = (UInt8)localSwitch_e;
      }

      /* Lookup_n-D: '<S173>/Lookup Table (n-D)' */
      localLookupTablenD = look2_iu8u16lftu16n12If_binlcns
        (locallocalDataTypeConversion2_o, facFuTran_B.VEMS_vidGET11,
         (&(InjSys_tCoStrtMes_A[0])), (&(InjSys_ctNbCmbAst_A[0])),
         (&(InjSys_facCorAst_M[0])), &facFuTran_ConstP.pooled9[0], 9U);

      /* Lookup_n-D: '<S174>/Lookup Table (n-D)' */
      localSwitch_c = look2_iu8u8lftu16n12If_binlcns(localDataTypeConversion_o,
        locallocalDataTypeConversion1_h, (&(InjSys_tCoMes_A[0])),
        (&(InjSys_tAirExtMes_A[0])), (&(InjSys_facCorExtCd_M[0])),
        &facFuTran_ConstP.pooled9[0], 9U);

      /* Product: '<S176>/Divide' incorporates:
       *  Product: '<S175>/Divide'
       */
      localfractionTmp_0d = (InjSys_facTranSp * localLookupTablenD) *
        localSwitch_c;

      /* Switch: '<S98>/Switch' incorporates:
       *  Constant: '<S98>/ConstVal'
       *  Constant: '<S98>/InjSys_bAcvFISAWupAdp_C'
       *  DataTypeConversion: '<S98>/Data Type Conversion3'
       */
      if (InjSys_bAcvFISAWupAdp_C) {
        localSwitch_c = ((Float32)facFuTran_B.VEMS_vidGET10) * 0.0078125F;
      } else {
        localSwitch_c = 1.0F;
      }

      /* Product: '<S177>/Divide' incorporates:
       *  Constant: '<S98>/ConstVal_2'
       *  Sum: '<S98>/Sum'
       */
      InjSys_facTranCmpIni = (localfractionTmp_0d + 1.0F) * localSwitch_c;

      /* end of Outputs for SubSystem: '<S92>/F04_facTranCmpIniClcn' */

      /* Outputs for atomic SubSystem: '<S92>/F05_facTranCmpFilClcn' */

      /* Outputs for atomic SubSystem: '<S99>/F01_TranRmpClcn' */

      /* Outputs for atomic SubSystem: '<S178>/rising_edge' */
      facFuTran_rising_edge_m(InjSys_bDetDecTran, &facFuTran_B.rising_edge_m,
        &facFuTran_DWork.rising_edge_m);

      /* end of Outputs for SubSystem: '<S178>/rising_edge' */

      /* Outputs for atomic SubSystem: '<S178>/rising_edge1' */
      facFuTran_rising_edge_m(InjSys_bDetAccTran, &facFuTran_B.rising_edge1,
        &facFuTran_DWork.rising_edge1);

      /* end of Outputs for SubSystem: '<S178>/rising_edge1' */

      /* UnitDelay: '<S182>/UnitDelay' */
      localUnitDelay_b = facFuTran_DWork.UnitDelay_b;

      /* CombinatorialLogic: '<S182>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge_m.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge1.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_b != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_l[0] = facFuTran_ConstP.pooled19[rowidx];
        localLogic_l[1] = facFuTran_ConstP.pooled19[rowidx + 8];
      }

      /* Switch: '<S182>/Switch2' incorporates:
       *  Constant: '<S182>/NotCLR3'
       *  UnitDelay: '<S182>/UnitDelay1'
       */
      if (facFuTran_DWork.UnitDelay_l) {
        localSwitch2_i = localLogic_l[0];
      } else {
        localSwitch2_i = FALSE;
      }

      /* Lookup2D: '<S183>/Look-Up Table (2-D)'
       * About '<S183>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U8  Bias -40.0
       * Output0 Data Type:  Fixed Point    U8  Bias 1.0
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U8_U16_U8( &(localLookUpTable2D), (&(InjSys_noCmbRmpTranAcc_M[0])),
                       facFuTran_B.VEMS_vidGET13, (&(InjSys_nEngInjSpTranX_A[0])),
                       8U, localDataTypeConversion_o, (&(InjSys_tCoMes_A[0])),
                       8U);

      /* DataTypeDuplicate Block: '<S183>/Data Type Duplicate2'
       *
       * Regarding '<S183>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Lookup2D: '<S184>/Look-Up Table (2-D)'
       * About '<S184>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U8  Bias -40.0
       * Output0 Data Type:  Fixed Point    U8  Bias 1.0
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U8_U16_U8( &(localLookUpTable2D_o), (&(InjSys_noCmbRmpTranDec_M[0])),
                       facFuTran_B.VEMS_vidGET13, (&(InjSys_nEngInjSpTranX_A[0])),
                       8U, localDataTypeConversion_o, (&(InjSys_tCoMes_A[0])),
                       8U);

      /* DataTypeDuplicate Block: '<S184>/Data Type Duplicate2'
       *
       * Regarding '<S184>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Switch: '<S178>/Switch1' incorporates:
       *  Lookup2D: '<S183>/Look-Up Table (2-D)'
       *  Lookup2D: '<S184>/Look-Up Table (2-D)'
       */
      if (localSwitch2_i) {
        InjSys_noCmbRmpTran = localLookUpTable2D_o;
      } else {
        InjSys_noCmbRmpTran = localLookUpTable2D;
      }

      /* end of Outputs for SubSystem: '<S99>/F01_TranRmpClcn' */

      /* Outputs for atomic SubSystem: '<S99>/F02_NbCmbTranClcn' */

      /* Outputs for atomic SubSystem: '<S179>/rising_edge1' */
      facFuTran_rising_edge_m(InjSys_bDetAccTran, &facFuTran_B.rising_edge1_d,
        &facFuTran_DWork.rising_edge1_d);

      /* end of Outputs for SubSystem: '<S179>/rising_edge1' */

      /* Outputs for atomic SubSystem: '<S179>/rising_edge2' */
      facFuTran_rising_edge_m(InjSys_bDetDecTran, &facFuTran_B.rising_edge2,
        &facFuTran_DWork.rising_edge2);

      /* end of Outputs for SubSystem: '<S179>/rising_edge2' */

      /* Logic: '<S179>/Logical Operator1' */
      localLogicalOperator1_n = (facFuTran_B.rising_edge1_d.LogicalOperator ||
        facFuTran_B.rising_edge2.LogicalOperator);

      /* Outputs for atomic SubSystem: '<S179>/Counter1' */

      /* Outputs for atomic SubSystem: '<S189>/Rising_edge' */
      facFuTran_rising_edge(localLogicalOperator1_n, &facFuTran_B.Rising_edge,
                            &facFuTran_DWork.Rising_edge);

      /* end of Outputs for SubSystem: '<S189>/Rising_edge' */

      /* Sum: '<S189>/Sum1' incorporates:
       *  UnitDelay: '<S196>/Unit Delay'
       */
      localAdd = (UInt32)(1 + facFuTran_DWork.UnitDelay_DSTATE_f);
      if (localAdd > 65535U) {
        locallocalSwitch_g = MAX_uint16_T;
      } else {
        locallocalSwitch_g = (UInt16)localAdd;
      }

      /* Switch: '<S189>/Switch2' incorporates:
       *  Constant: '<S189>/Constant1'
       */
      if (facFuTran_B.Rising_edge.LogicalOperator) {
        locallocalSwitch_g = 0U;
      }

      /* Switch: '<S202>/Switch2' incorporates:
       *  Constant: '<S189>/Cnt_Max'
       *  RelationalOperator: '<S202>/LowerRelop1'
       */
      if (locallocalSwitch_g > 256) {
        locallocalSwitch_g = 256U;
      }

      /* Update for UnitDelay: '<S196>/Unit Delay' */
      facFuTran_DWork.UnitDelay_DSTATE_f = locallocalSwitch_g;

      /* end of Outputs for SubSystem: '<S179>/Counter1' */

      /* Sum: '<S179>/Sum2' incorporates:
       *  Constant: '<S179>/ConstVal_1'
       */
      localAdd = (UInt32)(1 + locallocalSwitch_g);
      if (localAdd > 65535U) {
        locallocalSwitch_g = MAX_uint16_T;
      } else {
        locallocalSwitch_g = (UInt16)localAdd;
      }

      /* RelationalOperator: '<S179>/Relational Operator' incorporates:
       *  DataTypeConversion: '<S179>/Data Type Conversion'
       */
      localLowerRelop1_m = (locallocalSwitch_g > ((UInt16)(InjSys_noCmbRmpTran
        + 1)));

      /* Outputs for atomic SubSystem: '<S179>/Mem' */

      /* Switch: '<S190>/Switch1' incorporates:
       *  UnitDelay: '<S190>/UnitDelay'
       */
      if (localLowerRelop1_m) {
        locallocalSwitch_g = facFuTran_DWork.UnitDelay;
      }

      /* Update for UnitDelay: '<S190>/UnitDelay' */
      facFuTran_DWork.UnitDelay = locallocalSwitch_g;

      /* end of Outputs for SubSystem: '<S179>/Mem' */

      /* DataTypeConversion: '<S179>/Data Type Conversion1' */
      if (locallocalSwitch_g > 255) {
        InjSys_ctNbCmbTran = MAX_uint8_T;
      } else {
        InjSys_ctNbCmbTran = (UInt8)locallocalSwitch_g;
      }

      /* Logic: '<S179>/Logical Operator2' */
      InjSys_bDetRmpTran = !localLowerRelop1_m;

      /* end of Outputs for SubSystem: '<S99>/F02_NbCmbTranClcn' */

      /* Outputs for atomic SubSystem: '<S99>/F03_TranCmpRmp' */

      /* DataTypeConversion: '<S180>/Data Type Conversion' */
      localfractionTmp_0d = ((Float32)InjSys_noCmbRmpTran) + 1.0F;

      /* DataTypeConversion: '<S180>/Data Type Conversion1' */
      localLookupTablenD = (Float32)InjSys_ctNbCmbTran;

      /* Outputs for atomic SubSystem: '<S180>/rising_edge1' */
      facFuTran_rising_edge_m(InjSys_bDetAccTran, &facFuTran_B.rising_edge1_b,
        &facFuTran_DWork.rising_edge1_b);

      /* end of Outputs for SubSystem: '<S180>/rising_edge1' */

      /* Outputs for atomic SubSystem: '<S180>/rising_edge2' */
      facFuTran_rising_edge_m(InjSys_bDetDecTran, &facFuTran_B.rising_edge2_e,
        &facFuTran_DWork.rising_edge2_e);

      /* end of Outputs for SubSystem: '<S180>/rising_edge2' */

      /* Switch: '<S180>/Switch1' incorporates:
       *  Logic: '<S180>/Logical Operator1'
       *  Logic: '<S180>/Logical Operator2'
       */
      if (!(facFuTran_B.rising_edge1_b.LogicalOperator ||
            facFuTran_B.rising_edge2_e.LogicalOperator)) {
        InjSys_facTranCmpRawRmp = InjSys_facTranCmpPrevRmp;
      } else {
        InjSys_facTranCmpRawRmp = InjSys_facTranCmpIni;
      }

      /* Product: '<S206>/Divide' incorporates:
       *  Constant: '<S180>/ConstVal'
       *  Sum: '<S180>/Sum1'
       */
      localfractionTmp_0d = (InjSys_facTranCmpRawRmp - 1.0F) /
        localfractionTmp_0d;

      /* Outputs for atomic SubSystem: '<S206>/If Action Subsystem3' */

      /* Switch: '<S211>/Switch1' incorporates:
       *  Constant: '<S211>/Constant1'
       *  Constant: '<S211>/Constant2'
       *  Constant: '<S211>/Constant3'
       *  Logic: '<S211>/Logical Operator1'
       *  RelationalOperator: '<S211>/Relational Operator'
       *  RelationalOperator: '<S211>/Relational Operator1'
       *  RelationalOperator: '<S211>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        localfractionTmp_0d = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S206>/If Action Subsystem3' */

      /* Product: '<S207>/Divide' */
      InjSys_facTranCmpRmp = localfractionTmp_0d * localLookupTablenD;

      /* end of Outputs for SubSystem: '<S99>/F03_TranCmpRmp' */

      /* Outputs for atomic SubSystem: '<S99>/F04_TranCmpFil' */

      /* Outputs for atomic SubSystem: '<S181>/rising_edge' */
      facFuTran_rising_edge_m(InjSys_bDetDecTran, &facFuTran_B.rising_edge_h,
        &facFuTran_DWork.rising_edge_h);

      /* end of Outputs for SubSystem: '<S181>/rising_edge' */

      /* Outputs for atomic SubSystem: '<S181>/rising_edge1' */
      facFuTran_rising_edge_m(InjSys_bDetAccTran, &facFuTran_B.rising_edge1_i,
        &facFuTran_DWork.rising_edge1_i);

      /* end of Outputs for SubSystem: '<S181>/rising_edge1' */

      /* UnitDelay: '<S214>/UnitDelay' */
      localUnitDelay_k = facFuTran_DWork.UnitDelay_kb;

      /* CombinatorialLogic: '<S214>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge_h.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge1_i.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_k != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = facFuTran_ConstP.pooled19[rowidx];
        localLogic[1] = facFuTran_ConstP.pooled19[rowidx + 8];
      }

      /* Switch: '<S214>/Switch2' incorporates:
       *  Constant: '<S214>/NotCLR3'
       *  UnitDelay: '<S214>/UnitDelay1'
       */
      if (facFuTran_DWork.UnitDelay_ep) {
        localSwitch2_e = localLogic[0];
      } else {
        localSwitch2_e = TRUE;
      }

      /* Switch: '<S181>/Switch' incorporates:
       *  Constant: '<S181>/ConstVal_1'
       *  Constant: '<S181>/ConstVal_3'
       *  Sum: '<S181>/Sum3'
       *  Sum: '<S181>/Sum4'
       */
      if (localSwitch2_e) {
        localSwitch = 1.0F - InjSys_facTranCmpRmp;
      } else {
        localSwitch = InjSys_facTranCmpRmp + 1.0F;
      }

      /* PreLookup: '<S216>/Prelookup' */
      localAdd = plook_u32u16f_binc(facFuTran_B.VEMS_vidGET13,
        (&(InjSys_nEngInjSpTranX_A[0])), 8U, &localInterpolationUsingPrelooku);

      /* PreLookup: '<S219>/Prelookup' */
      localAdd_h = plook_u32u8f_binc(localDataTypeConversion_o,
        (&(InjSys_tCoMes_A[0])), 8U, &localExt_tCoMes_InjSys_tCoMes_A);

      /* Interpolation_n-D: '<S218>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPrelooku;
      localfrac[0] = localfractionTmp_0d;
      localfractionTmp_0d = localExt_tCoMes_InjSys_tCoMes_A;
      localfrac[1] = localfractionTmp_0d;
      localbpIndex[0] = localAdd;
      localbpIndex[1] = localAdd_h;
      localSwitch_c = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex, localfrac,
        (&(InjSys_rGainFilDecCmp_M[0])), 9U);

      /* Interpolation_n-D: '<S217>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPrelooku;
      localfrac_0[0] = localfractionTmp_0d;
      localfractionTmp_0d = localExt_tCoMes_InjSys_tCoMes_A;
      localfrac_0[1] = localfractionTmp_0d;
      localbpIndex_0[0] = localAdd;
      localbpIndex_0[1] = localAdd_h;
      localInterpolationUsingPrelooku = intrp2d_iu8n7ff_u32f_l_ns(localbpIndex_0,
        localfrac_0, (&(InjSys_rGainFilAccCmp_M[0])), 9U);

      /* Switch: '<S181>/Switch1' */
      if (!localSwitch2_e) {
        localSwitch_c = localInterpolationUsingPrelooku;
      }

      /* Outputs for atomic SubSystem: '<S181>/DLowPassFilter_TypeK' */

      /* Switch: '<S230>/Switch' incorporates:
       *  Constant: '<S215>/Constant2'
       *  RelationalOperator: '<S230>/UpperRelop'
       */
      if (localSwitch_c < 0.0F) {
        localLookupTablenD = 0.0F;
      } else {
        localLookupTablenD = localSwitch_c;
      }

      /* Switch: '<S230>/Switch2' incorporates:
       *  Constant: '<S215>/Constant1'
       *  RelationalOperator: '<S230>/LowerRelop1'
       */
      if (localSwitch_c > 1.0F) {
        localLookupTablenD = 1.0F;
      }

      /* Outputs for atomic SubSystem: '<S215>/UnitDly_ExtIni1' */

      /* Switch: '<S225>/Switch' incorporates:
       *  UnitDelay: '<S232>/Unit Delay'
       *  UnitDelay: '<S233>/Unit Delay'
       */
      if (facFuTran_DWork.UnitDelay_DSTATE_k) {
        localfractionTmp_0d = facFuTran_DWork.UnitDelay_DSTATE;
      } else {
        localfractionTmp_0d = localSwitch;
      }

      /* end of Outputs for SubSystem: '<S215>/UnitDly_ExtIni1' */

      /* Switch: '<S215>/Switch' incorporates:
       *  Constant: '<S181>/ConstVal'
       *  Constant: '<S215>/Constant3'
       *  Logic: '<S181>/Logical Operator1'
       *  Product: '<S226>/Divide'
       *  Product: '<S227>/Divide'
       *  Sum: '<S215>/Sum1'
       *  Sum: '<S215>/Sum2'
       */
      if (InjSys_bDetRmpTran || InjSys_bDetAcvWfCmp) {
        localSwitch_f = localSwitch;
      } else {
        localSwitch_f = ((1.0F - localLookupTablenD) * localfractionTmp_0d) +
          localLookupTablenD;
      }

      /* Outputs for atomic SubSystem: '<S215>/IniCdn' */

      /* Switch: '<S224>/Switch' incorporates:
       *  UnitDelay: '<S231>/Unit Delay'
       */
      if (facFuTran_DWork.UnitDelay_DSTATE_km) {
        localSwitch = localSwitch_f;
      }

      /* Update for UnitDelay: '<S231>/Unit Delay' incorporates:
       *  Constant: '<S224>/Constant3'
       */
      facFuTran_DWork.UnitDelay_DSTATE_km = TRUE;

      /* end of Outputs for SubSystem: '<S215>/IniCdn' */

      /* Update for atomic SubSystem: '<S215>/UnitDly_ExtIni1' */

      /* Update for UnitDelay: '<S232>/Unit Delay' incorporates:
       *  Constant: '<S225>/Constant3'
       */
      facFuTran_DWork.UnitDelay_DSTATE_k = TRUE;

      /* Update for UnitDelay: '<S233>/Unit Delay' */
      facFuTran_DWork.UnitDelay_DSTATE = localSwitch_f;

      /* end of Update for SubSystem: '<S215>/UnitDly_ExtIni1' */

      /* end of Outputs for SubSystem: '<S181>/DLowPassFilter_TypeK' */

      /* DataTypeConversion: '<S220>/OutDTConv' incorporates:
       *  Constant: '<S220>/offset'
       *  Constant: '<S220>/offset1'
       *  Constant: '<S220>/one_on_slope'
       *  Product: '<S220>/Product4'
       *  Sum: '<S220>/Add1'
       *  Sum: '<S220>/Add2'
       */
      localfractionTmp_0d = (4096.0F * localSwitch) + 0.5F;
      if (localfractionTmp_0d < 65536.0F) {
        if (localfractionTmp_0d >= 0.0F) {
          InjSys_facTranCmp = (UInt16)localfractionTmp_0d;
        } else {
          InjSys_facTranCmp = 0U;
        }
      } else {
        InjSys_facTranCmp = MAX_uint16_T;
      }

      /* end of Outputs for SubSystem: '<S99>/F04_TranCmpFil' */

      /* end of Outputs for SubSystem: '<S92>/F05_facTranCmpFilClcn' */
    } else {
      localrtAction = 1;

      /* Constant: '<S93>/ConstVal' */
      InjSys_facTranCmp = 4096U;
    }

    facFuTran_DWork.If_ActiveSubsystem = localrtAction;

    /* SignalConversion: '<S90>/S-Function3' */
    InjSys_facTranCmpPrevRmp = InjSys_facTranCmpRawRmp;
  }

  /* end of Outputs for SubSystem: '<S8>/F01_facFuTranFct' */

  /* Update for enable SubSystem: '<S8>/F01_facFuTranFct' incorporates:
   *  Update for EnablePort: '<S90>/Enable'
   */
  if (localRelationalOperator) {
    /* Update for If: '<S90>/If' incorporates:
     *  Update for ActionPort: '<S92>/Action Port'
     *  Update for SubSystem: '<S90>/F01_facFuTranClcn'
     */
    if (facFuTran_DWork.If_ActiveSubsystem == 0) {
      /* Update for atomic SubSystem: '<S92>/F05_facTranCmpFilClcn' */

      /* Update for atomic SubSystem: '<S99>/F01_TranRmpClcn' */

      /* Update for atomic SubSystem: '<S178>/rising_edge' */
      facFuTran_rising_edge_l_Update(InjSys_bDetDecTran,
        &facFuTran_DWork.rising_edge_m);

      /* end of Update for SubSystem: '<S178>/rising_edge' */

      /* Update for atomic SubSystem: '<S178>/rising_edge1' */
      facFuTran_rising_edge_l_Update(InjSys_bDetAccTran,
        &facFuTran_DWork.rising_edge1);

      /* end of Update for SubSystem: '<S178>/rising_edge1' */

      /* Update for UnitDelay: '<S182>/UnitDelay' */
      facFuTran_DWork.UnitDelay_b = localSwitch2_i;

      /* Update for UnitDelay: '<S182>/UnitDelay1' incorporates:
       *  Constant: '<S182>/NotCLR2'
       */
      facFuTran_DWork.UnitDelay_l = TRUE;

      /* end of Update for SubSystem: '<S99>/F01_TranRmpClcn' */

      /* Update for atomic SubSystem: '<S99>/F02_NbCmbTranClcn' */

      /* Update for atomic SubSystem: '<S179>/rising_edge1' */
      facFuTran_rising_edge_l_Update(InjSys_bDetAccTran,
        &facFuTran_DWork.rising_edge1_d);

      /* end of Update for SubSystem: '<S179>/rising_edge1' */

      /* Update for atomic SubSystem: '<S179>/rising_edge2' */
      facFuTran_rising_edge_l_Update(InjSys_bDetDecTran,
        &facFuTran_DWork.rising_edge2);

      /* end of Update for SubSystem: '<S179>/rising_edge2' */

      /* end of Update for SubSystem: '<S99>/F02_NbCmbTranClcn' */

      /* Update for atomic SubSystem: '<S99>/F03_TranCmpRmp' */

      /* Update for atomic SubSystem: '<S180>/rising_edge1' */
      facFuTran_rising_edge_l_Update(InjSys_bDetAccTran,
        &facFuTran_DWork.rising_edge1_b);

      /* end of Update for SubSystem: '<S180>/rising_edge1' */

      /* Update for atomic SubSystem: '<S180>/rising_edge2' */
      facFuTran_rising_edge_l_Update(InjSys_bDetDecTran,
        &facFuTran_DWork.rising_edge2_e);

      /* end of Update for SubSystem: '<S180>/rising_edge2' */

      /* end of Update for SubSystem: '<S99>/F03_TranCmpRmp' */

      /* Update for atomic SubSystem: '<S99>/F04_TranCmpFil' */

      /* Update for atomic SubSystem: '<S181>/rising_edge' */
      facFuTran_rising_edge_l_Update(InjSys_bDetDecTran,
        &facFuTran_DWork.rising_edge_h);

      /* end of Update for SubSystem: '<S181>/rising_edge' */

      /* Update for atomic SubSystem: '<S181>/rising_edge1' */
      facFuTran_rising_edge_l_Update(InjSys_bDetAccTran,
        &facFuTran_DWork.rising_edge1_i);

      /* end of Update for SubSystem: '<S181>/rising_edge1' */

      /* Update for UnitDelay: '<S214>/UnitDelay' */
      facFuTran_DWork.UnitDelay_kb = localSwitch2_e;

      /* Update for UnitDelay: '<S214>/UnitDelay1' incorporates:
       *  Constant: '<S214>/NotCLR2'
       */
      facFuTran_DWork.UnitDelay_ep = TRUE;

      /* end of Update for SubSystem: '<S99>/F04_TranCmpFil' */

      /* end of Update for SubSystem: '<S92>/F05_facTranCmpFilClcn' */
    }
  }

  /* end of Update for SubSystem: '<S8>/F01_facFuTranFct' */
}

/* Output and update for function-call system: '<S9>/F02_facFuTranSync' */
void facFuTran_F02_facFuTranSync(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_j;
  UInt32 localAdd_a;
  SInt32 locali;

  /* RelationalOperator: '<S237>/Relational Operator' incorporates:
   *  Constant: '<S237>/ConstVal'
   *  Constant: '<S237>/FACFUTRAN_u8Inhib'
   */
  localRelationalOperator_j = (FACFUTRAN_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S237>/F02_facFuTranSync' incorporates:
   *  EnablePort: '<S238>/Enable'
   */
  if (localRelationalOperator_j) {
    /* S-Function "vems_vidGET" Block: <S238>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInNxtCyl, facFuTran_B.VEMS_vidGET_n);

    /* Sum: '<S239>/Add' incorporates:
     *  Constant: '<S239>/Constant1'
     *  DataTypeConversion: '<S238>/DTConv_UFix_To_Single_1'
     */
    localAdd_a = ((UInt32)facFuTran_B.VEMS_vidGET_n) - 1U;

    /* S-Function "vems_vidGET" Block: <S238>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(InjSys_prm_facTranCmpCylRaw, 6,
                       InjSys_prm_facTranCmpCylPrev);

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
      facFuTran_B.Assignment[(locali)] = InjSys_prm_facTranCmpCylPrev[(locali)];
    }

    facFuTran_B.Assignment[rt_MIN(localAdd_a, 5U)] = InjSys_facTranCmp;

    /* S-Function "vems_vidSET" Block: <S238>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_facTranCmpCylRaw, 6, facFuTran_B.Assignment);
  }

  /* end of Outputs for SubSystem: '<S237>/F02_facFuTranSync' */
}

/* Output and update for function-call system: '<S4>/F03_RstDetTran' */
void facFuTran_F03_RstDetTran(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_a;

  /* RelationalOperator: '<S10>/Relational Operator' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  Constant: '<S10>/FACFUTRAN_u8Inhib'
   */
  localRelationalOperator_a = (FACFUTRAN_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S10>/F03_RstDetTran' incorporates:
   *  EnablePort: '<S240>/Enable'
   */
  if (localRelationalOperator_a) {
    /* SignalConversion: '<S240>/Signal Conversion1' */
    InjSys_bRstDetAccTran = InjSys_bDetAccTran;

    /* SignalConversion: '<S240>/Signal Conversion2' */
    InjSys_bRstDetDecTran = InjSys_bDetDecTran;
  }

  /* end of Outputs for SubSystem: '<S10>/F03_RstDetTran' */
}

/* Start for exported function: InjSys_EveInj_facFuTran */
void InjSys_EveInj_facFuTran_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S4>/fc_demux1'
   */

  /* Start for S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S4>/F00_facFuTranFctInit_Inhib'
   *  Start for SubSystem: '<S4>/F01_facFuTranFct'
   *  Start for SubSystem: '<S4>/F03_RstDetTran'
   *  Start for SubSystem: '<S9>/F02_facFuTranSync'
   */
  F00_facFuTranFctInit_Inhi_Start();
  facFuTra_F01_facFuTranFct_Start();
}

/* Output and update for exported function: InjSys_EveInj_facFuTran */
void InjSys_EveInj_facFuTran(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S4>/fc_demux1'
   */

  /* S-Function (fcncallgen): '<S11>/Function-Call Generator' incorporates:
   *  SubSystem: '<S4>/F01_facFuTranFct'
   *  SubSystem: '<S4>/F03_RstDetTran'
   *  SubSystem: '<S9>/F02_facFuTranSync'
   */
  facFuTran_ASYNC3(0);
  facFuTran_F01_facFuTranFct();
  facFuTran_F02_facFuTranSync();
  facFuTran_F03_RstDetTran();
}

/* Initial conditions for function-call system: '<S4>/F00_facFuTranFctInit' */
void facFu_F00_facFuTranFctInit_Init(void)
{
  /* InitializeConditions for atomic SubSystem: '<S5>/facFuTranFctInit_Inhib' */
  fac_facFuTranFctInit_Inhib_Init(&facFuTran_DWork.facFuTranFctInit_Inhib_c);

  /* end of InitializeConditions for SubSystem: '<S5>/facFuTranFctInit_Inhib' */
}

/* Output and update for function-call system: '<S4>/F00_facFuTranFctInit' */
void facFuTran_F00_facFuTranFctInit(void)
{
  /* local block i/o variables */
  Float32 localSignalConversion12;

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET6 */
  VEMS_vidGET(InjSys_bTotCutOff, facFuTran_B.VEMS_vidGET6_c);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET8 */
  VEMS_vidGET(InjSys_nEngInjSp, facFuTran_B.VEMS_vidGET8_a);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET5 */
  VEMS_vidGET(Ext_tiTDC, facFuTran_B.VEMS_vidGET5_b);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET1 */
  VEMS_vidGET(CoPTSt_stEngNew, facFuTran_B.VEMS_vidGET1_k);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET10 */
  VEMS_vidGET(TqSys_bEngNOnIdl, facFuTran_B.VEMS_vidGET10_f);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET3 */
  VEMS_vidGET(EOM_bTranMod, facFuTran_B.VEMS_vidGET3_c);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET9 */
  VEMS_vidGET1DArray(InjSys_prm_facInjResuCyl, 6, facFuTran_B.VEMS_vidGET9_j);

  /* DataTypeDuplicate Block: '<S18>/Data Type Duplicate'
   *
   * Regarding '<S18>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET4 */
  VEMS_vidGET(Eng_noInNxtCyl, facFuTran_B.VEMS_vidGET4_p);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET */
  VEMS_vidGET(CoPTSt_bRStrtSTT, facFuTran_B.VEMS_vidGET_j);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET2 */
  VEMS_vidGET(Dv_detection_pied_leve, facFuTran_B.VEMS_vidGET2_p);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET7 */
  VEMS_vidGET(InjSys_mFuReq, facFuTran_B.VEMS_vidGET7);

  /* SignalConversion: '<S5>/Signal Conversion12' */
  localSignalConversion12 = InjSys_facTranCmpPrevRmp;

  /* Outputs for atomic SubSystem: '<S5>/facFuTranFctInit_Inhib' */
  facFuTra_facFuTranFctInit_Inhib(localSignalConversion12,
    facFuTran_B.VEMS_vidGET2_p, facFuTran_B.VEMS_vidGET10_f,
    facFuTran_B.VEMS_vidGET1_k, facFuTran_B.VEMS_vidGET5_b,
    facFuTran_B.VEMS_vidGET_j, facFuTran_B.VEMS_vidGET7,
    facFuTran_B.VEMS_vidGET4_p, facFuTran_B.VEMS_vidGET6_c,
    facFuTran_B.VEMS_vidGET8_a, facFuTran_B.VEMS_vidGET3_c,
    facFuTran_B.VEMS_vidGET9_j, &facFuTran_B.facFuTranFctInit_Inhib_c,
    &facFuTran_DWork.facFuTranFctInit_Inhib_c);

  /* end of Outputs for SubSystem: '<S5>/facFuTranFctInit_Inhib' */

  /* SignalConversion: '<S5>/Signal Conversion1' */
  InjSys_facTranCmpPrevRmp = facFuTran_B.facFuTranFctInit_Inhib_c.Switch1;

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET */
  VEMS_vidSET(InjSys_bAcvWfCmp,
              facFuTran_B.facFuTranFctInit_Inhib_c.LogicalOperator1);
}

/* Output and update for function-call system: '<S9>/F01_facFuTranRst' */
void facFuTran_F01_facFuTranRst(void)
{
  /* S-Function "vems_vidSET" Block: <S236>/VEMS_vidSET */
  {
    UInt16 localArray[6] = {
      (4096U),
      (4096U),
      (4096U),
      (4096U),
      (4096U),
      (4096U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_facTranCmpCylRaw, 6 , localArray );
  }
}

/* Initial conditions for exported function: InjSys_EveRst_facFuTran */
void InjSys_EveRst_facFuTran_Init(void)
{
  /* InitializeConditions for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  InitializeConditions for SubSystem: '<S4>/fc_demux2'
   */

  /* InitializeConditions for S-Function (fcncallgen): '<S12>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<S4>/F00_facFuTranFctInit'
   *  InitializeConditions for SubSystem: '<S9>/F01_facFuTranRst'
   */
  facFu_F00_facFuTranFctInit_Init();
}

/* Start for exported function: InjSys_EveRst_facFuTran */
void InjSys_EveRst_facFuTran_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S4>/fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S12>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S4>/F00_facFuTranFctInit'
   *  Start for SubSystem: '<S9>/F01_facFuTranRst'
   */
}

/* Output and update for exported function: InjSys_EveRst_facFuTran */
void InjSys_EveRst_facFuTran(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S4>/fc_demux2'
   */

  /* S-Function (fcncallgen): '<S12>/Function-Call Generator' incorporates:
   *  SubSystem: '<S4>/F00_facFuTranFctInit'
   *  SubSystem: '<S9>/F01_facFuTranRst'
   */
  facFuTran_F00_facFuTranFctInit();
  facFuTran_F01_facFuTranRst();
}

/*
 * Output and update for action system:
 *    '<S62>/If Action Subsystem'
 *    '<S63>/If Action Subsystem'
 */
void facFuTran_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S80>/Value 1' */
  (*rty_Out1) = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S62>/If Action Subsystem1'
 *    '<S63>/If Action Subsystem1'
 */
void facFuTran_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S81>/Value 2' */
  (*rty_Out1) = rtu_0;
}

/* Output and update for function-call system: '<S4>/F00b_DetTranFct' */
void facFuTran_F00b_DetTranFct(void)
{
  /* local block i/o variables */
  Boolean localLogicalOperator7;
  Boolean localLogicalOperator1_f;
  Boolean localLogic_c[2];
  Boolean localUnitDelay1_k;
  UInt8 localDataTypeConversion7;
  UInt8 localLookUpTable;
  UInt8 localLookUpTable_g;
  Float32 localInterpolationUsingPreloo_m;
  Float32 localfractionTmp_0d;
  UInt32 localInjSys_nEngInjSp_InjSys__e;
  Float32 localInterpolationUsingPreloo_o;
  Float32 localInjSys_mAirPredInjSp_Inj_m;
  Float32 localInterpolationUsingPreloo_i;
  Boolean localRelationalOperator1_f;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  UInt32 localInjSys_mAirPredInjSp_Inj_a;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S7>/DetTranFct_Inhib' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/FACFUTRAN_u8Inhib'
   *  EnablePort: '<S57>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (FACFUTRAN_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_mAirPredInjSp, facFuTran_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET */
    VEMS_vidGET(EngM_mAirCor, facFuTran_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_tCoMes, facFuTran_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET1 */
    VEMS_vidGET(EngM_mAirPredIn, facFuTran_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_nEngInjSp, facFuTran_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_bAcvWfCmp, facFuTran_B.VEMS_vidGET5_a);

    /* If: '<S57>/If' incorporates:
     *  ActionPort: '<S58>/Action Port'
     *  ActionPort: '<S59>/Action Port'
     *  SubSystem: '<S57>/F01_DetTranClcn'
     *  SubSystem: '<S57>/F02_DetTrannoClcn'
     */
    if (facFuTran_B.VEMS_vidGET5_a) {
      /* DataTypeConversion: '<S58>/Data Type Conversion7' */
      localtmp = facFuTran_B.VEMS_vidGET2 + 40;
      if (localtmp <= 0) {
        localDataTypeConversion7 = 0U;
      } else if (localtmp > 255) {
        localDataTypeConversion7 = MAX_uint8_T;
      } else {
        localDataTypeConversion7 = (UInt8)localtmp;
      }

      /* PreLookup: '<S70>/Prelookup' */
      localInjSys_nEngInjSp_InjSys__e = plook_u32u8f_binc
        (localDataTypeConversion7, (&(InjSys_tCoMes_A[0])), 8U,
         &localInterpolationUsingPreloo_m);

      /* Interpolation_n-D: '<S67>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPreloo_m;
      localInterpolationUsingPreloo_i = intrp1d_iu8n8ff_u32f_l_ns
        (localInjSys_nEngInjSp_InjSys__e, localfractionTmp_0d,
         (&(InjSys_rDetAccTranLoThr_T[0])));

      /* Switch: '<S58>/Switch1' incorporates:
       *  Constant: '<S58>/InjSys_bSelVarInjSys_C'
       *  DataTypeConversion: '<S58>/Data Type Conversion1'
       *  DataTypeConversion: '<S58>/Data Type Conversion5'
       */
      if (InjSys_bSelVarInjSys_C) {
        localInjSys_mAirPredInjSp_Inj_m = ((Float32)facFuTran_B.VEMS_vidGET3) *
          1.192016583E-007F;
      } else {
        localInjSys_mAirPredInjSp_Inj_m = ((Float32)facFuTran_B.VEMS_vidGET1) *
          1.192016583E-007F;
      }

      /* DataTypeConversion: '<S58>/Data Type Conversion2' */
      localInterpolationUsingPreloo_o = ((Float32)facFuTran_B.VEMS_vidGET) *
        1.192016583E-007F;

      /* Sum: '<S58>/Sum' */
      localfractionTmp_0d = localInjSys_mAirPredInjSp_Inj_m -
        localInterpolationUsingPreloo_o;

      /* Product: '<S73>/Divide' */
      localfractionTmp_0d /= localInterpolationUsingPreloo_o;

      /* Outputs for atomic SubSystem: '<S73>/If Action Subsystem3' */

      /* Switch: '<S85>/Switch1' incorporates:
       *  Constant: '<S85>/Constant1'
       *  Constant: '<S85>/Constant2'
       *  Constant: '<S85>/Constant3'
       *  Logic: '<S85>/Logical Operator1'
       *  RelationalOperator: '<S85>/Relational Operator'
       *  RelationalOperator: '<S85>/Relational Operator1'
       *  RelationalOperator: '<S85>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        InjSys_rMAirPredMAirCor = 0.0F;
      } else {
        InjSys_rMAirPredMAirCor = localfractionTmp_0d;
      }

      /* end of Outputs for SubSystem: '<S73>/If Action Subsystem3' */

      /* RelationalOperator: '<S63>/Relational Operator1' */
      localRelationalOperator1_f = (localInterpolationUsingPreloo_i >=
        InjSys_rMAirPredMAirCor);

      /* Interpolation_n-D: '<S66>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPreloo_m;
      localInterpolationUsingPreloo_m = intrp1d_iu8n8ff_u32f_l_ns
        (localInjSys_nEngInjSp_InjSys__e, localfractionTmp_0d,
         (&(InjSys_rDetAccTranHiThr_T[0])));

      /* PreLookup: '<S64>/Prelookup' */
      localInjSys_nEngInjSp_InjSys__e = plook_u32u16f_binc
        (facFuTran_B.VEMS_vidGET4, (&(InjSys_nEngInjSp_A[0])), 8U,
         &localInterpolationUsingPreloo_o);

      /* PreLookup: '<S65>/Prelookup' */
      localInjSys_mAirPredInjSp_Inj_a = plook_u32u16f_binc
        (facFuTran_B.VEMS_vidGET3, (&(InjSys_mAirPredInjSp_A[0])), 8U,
         &localInjSys_mAirPredInjSp_Inj_m);

      /* Interpolation_n-D: '<S71>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPreloo_o;
      localfrac[0] = localfractionTmp_0d;
      localfractionTmp_0d = localInjSys_mAirPredInjSp_Inj_m;
      localfrac[1] = localfractionTmp_0d;
      localbpIndex[0] = localInjSys_nEngInjSp_InjSys__e;
      localbpIndex[1] = localInjSys_mAirPredInjSp_Inj_a;
      localInterpolationUsingPreloo_i = intrp2d_iu8n4ff_u32f_l_ns(localbpIndex,
        localfrac, (&(InjSys_facDetAccTranHiThr_M[0])), 9U);

      /* Product: '<S75>/Divide' */
      localfractionTmp_0d = localInterpolationUsingPreloo_m *
        localInterpolationUsingPreloo_i;

      /* If: '<S63>/If' incorporates:
       *  ActionPort: '<S82>/Action Port'
       *  ActionPort: '<S83>/Action Port'
       *  RelationalOperator: '<S63>/Relational Operator'
       *  SubSystem: '<S63>/If Action Subsystem'
       *  SubSystem: '<S63>/If Action Subsystem1'
       */
      if (localRelationalOperator1_f) {
        facFuTran_IfActionSubsystem(FALSE, &InjSys_bDetAccTranTmp);
      } else {
        if (InjSys_rMAirPredMAirCor >= localfractionTmp_0d) {
          facFuTran_IfActionSubsystem1(TRUE, &InjSys_bDetAccTranTmp);
        }
      }

      /* Outputs for atomic SubSystem: '<S58>/rising_edge' */
      facFuTran_rising_edge(InjSys_bDetAccTranTmp, &facFuTran_B.rising_edge_h0,
                            &facFuTran_DWork.rising_edge_h0);

      /* end of Outputs for SubSystem: '<S58>/rising_edge' */

      /* Lookup: '<S69>/Look-Up Table'
       * About '<S69>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Output0 Data Type:  Fixed Point    U8  2^-8  Bias -1.0
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable), (&(InjSys_rDetDecTranLoThr_T[0])),
                   localDataTypeConversion7, (&(InjSys_tCoMes_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate1'
       *
       * Regarding '<S69>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S58>/Data Type Conversion6' incorporates:
       *  Lookup: '<S69>/Look-Up Table'
       */
      localInterpolationUsingPreloo_i = (((Float32)localLookUpTable) *
        0.00390625F) - 1.0F;

      /* Interpolation_n-D: '<S72>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localInterpolationUsingPreloo_o;
      localfrac_0[0] = localfractionTmp_0d;
      localfractionTmp_0d = localInjSys_mAirPredInjSp_Inj_m;
      localfrac_0[1] = localfractionTmp_0d;
      localbpIndex_0[0] = localInjSys_nEngInjSp_InjSys__e;
      localbpIndex_0[1] = localInjSys_mAirPredInjSp_Inj_a;
      localInterpolationUsingPreloo_o = intrp2d_iu8n4ff_u32f_l_ns(localbpIndex_0,
        localfrac_0, (&(InjSys_facDetDecTranLoThr_M[0])), 9U);

      /* Product: '<S74>/Divide' */
      localfractionTmp_0d = localInterpolationUsingPreloo_i *
        localInterpolationUsingPreloo_o;

      /* RelationalOperator: '<S62>/Relational Operator1' */
      localRelationalOperator1_f = (localfractionTmp_0d >=
        InjSys_rMAirPredMAirCor);

      /* Lookup: '<S68>/Look-Up Table'
       * About '<S68>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U8  Bias -40.0
       * Output0 Data Type:  Fixed Point    U8  2^-8  Bias -1.0
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable_g), (&(InjSys_rDetDecTranHiThr_T[0])),
                   localDataTypeConversion7, (&(InjSys_tCoMes_A[0])), 8U);

      /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate1'
       *
       * Regarding '<S68>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* If: '<S62>/If' incorporates:
       *  ActionPort: '<S80>/Action Port'
       *  ActionPort: '<S81>/Action Port'
       *  DataTypeConversion: '<S58>/Data Type Conversion3'
       *  Lookup: '<S68>/Look-Up Table'
       *  RelationalOperator: '<S62>/Relational Operator'
       *  SubSystem: '<S62>/If Action Subsystem'
       *  SubSystem: '<S62>/If Action Subsystem1'
       */
      if (localRelationalOperator1_f) {
        facFuTran_IfActionSubsystem(TRUE, &InjSys_bDetDecTranTmp);
      } else {
        if (InjSys_rMAirPredMAirCor >= ((((Float32)localLookUpTable_g) *
              0.00390625F) - 1.0F)) {
          facFuTran_IfActionSubsystem1(FALSE, &InjSys_bDetDecTranTmp);
        }
      }

      /* Logic: '<S58>/Logical Operator7' */
      localLogicalOperator7 = (InjSys_bDetDecTranTmp || InjSys_bRstDetAccTran);

      /* Outputs for atomic SubSystem: '<S58>/rising_edge1' */
      facFuTran_rising_edge(localLogicalOperator7, &facFuTran_B.rising_edge1_n,
                            &facFuTran_DWork.rising_edge1_n);

      /* end of Outputs for SubSystem: '<S58>/rising_edge1' */

      /* UnitDelay: '<S60>/UnitDelay' */
      localUnitDelay1_k = facFuTran_DWork.UnitDelay_e;

      /* CombinatorialLogic: '<S60>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge_h0.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge1_n.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_c[0] = facFuTran_ConstP.pooled19[rowidx];
        localLogic_c[1] = facFuTran_ConstP.pooled19[rowidx + 8];
      }

      /* UnitDelay: '<S60>/UnitDelay1' */
      localUnitDelay1_k = facFuTran_DWork.UnitDelay_j;

      /* Switch: '<S60>/Switch2' incorporates:
       *  Constant: '<S60>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        facFuTran_B.Switch2 = localLogic_c[0];
      } else {
        facFuTran_B.Switch2 = FALSE;
      }

      /* Outputs for atomic SubSystem: '<S58>/rising_edge2' */
      facFuTran_rising_edge(InjSys_bDetDecTranTmp, &facFuTran_B.rising_edge2_f,
                            &facFuTran_DWork.rising_edge2_f);

      /* end of Outputs for SubSystem: '<S58>/rising_edge2' */

      /* Logic: '<S58>/Logical Operator1' */
      localLogicalOperator1_f = (InjSys_bDetAccTranTmp || InjSys_bRstDetDecTran);

      /* Outputs for atomic SubSystem: '<S58>/rising_edge3' */
      facFuTran_rising_edge(localLogicalOperator1_f, &facFuTran_B.rising_edge3,
                            &facFuTran_DWork.rising_edge3);

      /* end of Outputs for SubSystem: '<S58>/rising_edge3' */

      /* UnitDelay: '<S61>/UnitDelay' */
      localUnitDelay1_k = facFuTran_DWork.UnitDelay_a;

      /* CombinatorialLogic: '<S61>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge2_f.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)
          (facFuTran_B.rising_edge3.LogicalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_c[0] = facFuTran_ConstP.pooled19[rowidx];
        localLogic_c[1] = facFuTran_ConstP.pooled19[rowidx + 8];
      }

      /* UnitDelay: '<S61>/UnitDelay1' */
      localUnitDelay1_k = facFuTran_DWork.UnitDelay_k;

      /* Switch: '<S61>/Switch2' incorporates:
       *  Constant: '<S61>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        facFuTran_B.Switch2_p = localLogic_c[0];
      } else {
        facFuTran_B.Switch2_p = FALSE;
      }

      /* Update for UnitDelay: '<S60>/UnitDelay' */
      facFuTran_DWork.UnitDelay_e = facFuTran_B.Switch2;

      /* Update for UnitDelay: '<S60>/UnitDelay1' incorporates:
       *  Constant: '<S60>/NotCLR2'
       */
      facFuTran_DWork.UnitDelay_j = TRUE;

      /* Update for UnitDelay: '<S61>/UnitDelay' */
      facFuTran_DWork.UnitDelay_a = facFuTran_B.Switch2_p;

      /* Update for UnitDelay: '<S61>/UnitDelay1' incorporates:
       *  Constant: '<S61>/NotCLR2'
       */
      facFuTran_DWork.UnitDelay_k = TRUE;
    } else {
      /* Constant: '<S59>/ConstVal' */
      facFuTran_B.ConstVal = FALSE;

      /* Constant: '<S59>/ConstVal_2' */
      facFuTran_B.ConstVal_2 = FALSE;
    }

    /* Switch: '<S57>/Switch1' */
    if (facFuTran_B.VEMS_vidGET5_a) {
      InjSys_bDetAccTran = facFuTran_B.Switch2;
    } else {
      InjSys_bDetAccTran = facFuTran_B.ConstVal;
    }

    /* Switch: '<S57>/Switch2' */
    if (facFuTran_B.VEMS_vidGET5_a) {
      InjSys_bDetDecTran = facFuTran_B.Switch2_p;
    } else {
      InjSys_bDetDecTran = facFuTran_B.ConstVal_2;
    }
  }

  /* end of Outputs for SubSystem: '<S7>/DetTranFct_Inhib' */
}

/* Start for exported function: InjSys_SdlFast_facFuTran */
void InjSys_SdlFast_facFuTran_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S4>/fc_demux3'
   */
}

/* Output and update for exported function: InjSys_SdlFast_facFuTran */
void InjSys_SdlFast_facFuTran(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S4>/fc_demux3'
   */

  /* S-Function (fcncallgen): '<S13>/Function-Call Generator' incorporates:
   *  SubSystem: '<S4>/F00b_DetTranFct'
   */
  facFuTran_ASYNC3(1);
  facFuTran_F00b_DetTranFct();
}

/* Model initialize function */
void facFuTran_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  InjSys_EveInj_facFuTran_Start();
  InjSys_EveRst_facFuTran_Start();
  InjSys_SdlFast_facFuTran_Start();

  /* InitializeConditions for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__1'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__2'
   *  InitializeConditions for SubSystem: '<Root>/__ExpFcn__3'
   */
  InjSys_EveRst_facFuTran_Init();
}

#define FACFUTRAN_STOP_SEC_CODE
#include "facFuTran_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
