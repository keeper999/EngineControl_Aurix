/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : TqCkEngLimCord                                          */
/* !Description     : SAFETY TMS : GERER LE BOUCLAGE                          */
/*                                                                            */
/* !Module          : TqCkEngLimCord                                          */
/*                                                                            */
/* !File            : TqCkEngLimCord.c                                        */
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
/* !Reference       : V02NT1001252 / 06                                       */
/* !OtherRefs       : CSCT_CGMT09_2641 / 2.4                                  */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jun 19 17:16:01 2012                              */
/*   Model name       : TqCkEngLimCord_AUTOCODE.mdl                           */
/*   Model version    : 1.173                                                 */
/*   Root subsystem   : /TqCkEngLimCord                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKENGLIMCORD_CA/TqCk$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   etsasson                               $$Date::   12 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "TqCkEngLimCord.h"
#include "TqCkEngLimCord_private.h"

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
#define TQCKENGLIMCORD_START_SEC_VAR_UNSPECIFIED
#include "TqCkEngLimCord_MemMap.h"

/* Block signals (auto storage) */
BlockIO_TqCkEngLimCord TqCkEngLimCord_B;

/* Block states (auto storage) */
D_Work_TqCkEngLimCord TqCkEngLimCord_DWork;

#define TQCKENGLIMCORD_STOP_SEC_VAR_UNSPECIFIED
#include "TqCkEngLimCord_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define TQCKENGLIMCORD_START_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

void TqCkEngLimCord_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage' */
void CSCT_CGMT09_2641_v2_4_Gerer_Bou(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  Boolean localRelationalOperator_m;
  Boolean localRelationalOperator1_d;
  Boolean localLogic[2];
  Boolean localUnitDelay_b;
  Float localDTConv_UFix_To_Single_11;
  Float localDTConv_UFix_To_Single_3;
  Float localDTConv_UFix_To_Single_4_k;
  Float localDTConv_UFix_To_Single_6;
  Float localDTConv_UFix_To_Single_8;
  Boolean localLogicalOperator_o;
  Boolean localRelationalOperator1_g;
  Boolean localRelationalOperator2_o;
  Float localSum1;
  Float localSwitch_i;
  Float localSwitch_f;
  Boolean localRelationalOperator_f;
  Boolean localSwitch2;
  SInt16 localrtmax;
  SInt32 localDTConv_UFix_To_Single_13;
  SInt32 localDTConv_UFix_To_Single_14;

  /* Outputs for enable SubSystem: '<S4>/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S4>/Relational Operator'
   *
   * Block requirements for '<S4>/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage':
   *  1. SubSystem "F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage" !Trace_To : VEMS_R_10_01252_001.03 ;
   */
  if (TQCKENGLIMCORD_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/S-Function6 */
    VEMS_vidGET(SftyMgt_tqMaxRes, TqCkEngLimCord_B.SFunction6);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function7 */
    VEMS_vidGET(SftyMgt_bDeceAcvCll, TqCkEngLimCord_B.SFunction7);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function8 */
    VEMS_vidGET(SftyMgt_stTqReqCha, TqCkEngLimCord_B.SFunction8);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function9 */
    VEMS_vidGET(SftyMgt_bAcvIdlCll, TqCkEngLimCord_B.SFunction9);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function5 */
    VEMS_vidGET(SftyMgt_bAcvCllUnChk, TqCkEngLimCord_B.SFunction5);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function4 */
    VEMS_vidGET(SftyMgt_tqIdcEngCurMaxEngLim, TqCkEngLimCord_B.SFunction4);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function3 */
    VEMS_vidGET(SftyMgt_tqIdcAirReqTqSys, TqCkEngLimCord_B.SFunction3);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function1 */
    VEMS_vidGET(SftyMgt_bInhTqCllFRM, TqCkEngLimCord_B.SFunction1);

    /* Outputs for atomic SubSystem: '<S6>/F01_Generer_demande_bouclage' *
     * Block requirements for '<S6>/F01_Generer_demande_bouclage':
     *  1. SubSystem "F01_Generer_demande_bouclage" !Trace_To : VEMS_R_10_01252_002.03 ;
     */

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_11' incorporates:
     *  Constant: '<S7>/SftyMgt_tiSdlCllReq_SC_4'
     */
    localDTConv_UFix_To_Single_11 = ((Float)SftyMgt_tiSdlCllReq_SC) *
      1.000000047E-003F;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_13' incorporates:
     *  Constant: '<S7>/SftyMgt_tqDifHighForc_C'
     */
    localDTConv_UFix_To_Single_13 = SftyMgt_tqDifHighForc_C;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_14' */
    localDTConv_UFix_To_Single_14 = TqCkEngLimCord_B.SFunction6;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_3' incorporates:
     *  Constant: '<S7>/SftyMgt_tiDeacForcCll_C'
     */
    localDTConv_UFix_To_Single_3 = ((Float)SftyMgt_tiDeacForcCll_C) *
      3.999999911E-002F;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_4' incorporates:
     *  Constant: '<S7>/SftyMgt_tiTqDifCfm_C'
     */
    localDTConv_UFix_To_Single_4_k = ((Float)SftyMgt_tiTqDifCfm_C) *
      3.999999911E-002F;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_6' incorporates:
     *  Constant: '<S7>/SftyMgt_tiTranCll_C'
     */
    localDTConv_UFix_To_Single_6 = ((Float)SftyMgt_tiTranCll_C) *
      3.999999911E-002F;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_8' incorporates:
     *  Constant: '<S7>/SftyMgt_tiAcvForcCll_C'
     */
    localDTConv_UFix_To_Single_8 = ((Float)SftyMgt_tiAcvForcCll_C) *
      3.999999911E-002F;

    /* Logic: '<S7>/Logical Operator' */
    localLogicalOperator_o = !TqCkEngLimCord_B.SFunction5;

    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  Constant: '<S7>/SftyMgt_noTqReqChaASR_C'
     */
    localRelationalOperator1_g = (TqCkEngLimCord_B.SFunction8 ==
      SftyMgt_noTqReqChaASR_C);

    /* RelationalOperator: '<S7>/Relational Operator2' incorporates:
     *  Constant: '<S7>/SftyMgt_noTqReqChaMSR_C'
     */
    localRelationalOperator2_o = (TqCkEngLimCord_B.SFunction8 ==
      SftyMgt_noTqReqChaMSR_C);

    /* RelationalOperator: '<S9>/Relational Operator' incorporates:
     *  Constant: '<S7>/SftyMgt_tqHiResThr_C'
     *  DataTypeConversion: '<S7>/DTConv_UFix_To_Single_1'
     */
    localRelationalOperator_m = (localDTConv_UFix_To_Single_14 >=
      SftyMgt_tqHiResThr_C);

    /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
     *  Constant: '<S7>/SftyMgt_tqLoResThr_C'
     *  DataTypeConversion: '<S7>/DTConv_UFix_To_Single_2'
     */
    localRelationalOperator1_d = (localDTConv_UFix_To_Single_14 <=
      SftyMgt_tqLoResThr_C);

    /* UnitDelay: '<S15>/Unit Delay' */
    localUnitDelay_b = TqCkEngLimCord_DWork.UnitDelay_DSTATE_k;

    /* CombinatorialLogic: '<S14>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator_m != 0);
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_d != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_b != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = TqCkEngLimCord_ConstP.Logic_table[rowidx];
      localLogic[1] = TqCkEngLimCord_ConstP.Logic_table[rowidx + 8];
    }

    /* UnitDelay: '<S16>/Unit Delay' */
    localUnitDelay_b = TqCkEngLimCord_DWork.UnitDelay_DSTATE_m;

    /* Switch: '<S14>/Switch2' incorporates:
     *  Constant: '<S14>/NotCLR3'
     */
    if (localUnitDelay_b) {
      localSwitch2 = localLogic[0];
    } else {
      localSwitch2 = TRUE;
    }

    /* Sum: '<S12>/Sum1' */
    localSum1 = localDTConv_UFix_To_Single_11 + localDTConv_UFix_To_Single_8;

    /* Sum: '<S10>/Sum1' */
    localDTConv_UFix_To_Single_8 = localDTConv_UFix_To_Single_11 +
      localDTConv_UFix_To_Single_4_k;

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Cste_0'
     *  MinMax: '<S10>/MinMax'
     *  RelationalOperator: '<S7>/Relational Operator4'
     *  Sum: '<S10>/Sum'
     *  Sum: '<S7>/Sum'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    if ((TqCkEngLimCord_B.SFunction4 - TqCkEngLimCord_B.SFunction3) >=
        localDTConv_UFix_To_Single_13) {
      localSwitch_i = rt_MINf(TqCkEngLimCord_DWork.UnitDelay_DSTATE_c,
        localDTConv_UFix_To_Single_8) + localDTConv_UFix_To_Single_11;
    } else {
      localSwitch_i = 0.0F;
    }

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Cste_0'
     *  Logic: '<S7>/Logical Operator5'
     *  MinMax: '<S12>/MinMax'
     *  RelationalOperator: '<S10>/Relational Operator'
     *  Sum: '<S12>/Sum'
     *  UnitDelay: '<S19>/Unit Delay'
     */
    if ((localSwitch_i >= localDTConv_UFix_To_Single_8) ||
        TqCkEngLimCord_B.SFunction1) {
      localSwitch_f = rt_MINf(TqCkEngLimCord_DWork.UnitDelay_DSTATE_i, localSum1)
        + localDTConv_UFix_To_Single_11;
    } else {
      localSwitch_f = 0.0F;
    }

    /* RelationalOperator: '<S12>/Relational Operator' */
    localRelationalOperator_f = (localSwitch_f >= localSum1);

    /* Sum: '<S13>/Sum1' */
    localSum1 = localDTConv_UFix_To_Single_11 + localDTConv_UFix_To_Single_3;

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Cste_0'
     *  MinMax: '<S13>/MinMax'
     *  Sum: '<S13>/Sum'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    if (localRelationalOperator_f) {
      localDTConv_UFix_To_Single_4_k = 0.0F;
    } else {
      localDTConv_UFix_To_Single_4_k = rt_MINf
        (TqCkEngLimCord_DWork.UnitDelay_DSTATE_gf, localSum1) +
        localDTConv_UFix_To_Single_11;
    }

    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Logic: '<S13>/Logical Operator'
     *  Logic: '<S7>/Logical Operator1'
     *  RelationalOperator: '<S13>/Relational Operator'
     */
    SftyMgt_bAcvCllRaw_MP = ((((TqCkEngLimCord_B.SFunction7 || (localSwitch2)) ||
                               ((localRelationalOperator1_g) ||
      (localRelationalOperator2_o))) || TqCkEngLimCord_B.SFunction9) ||
      (!(localDTConv_UFix_To_Single_4_k >= localSum1)));

    /* Sum: '<S11>/Sum1' */
    localSum1 = localDTConv_UFix_To_Single_11 + localDTConv_UFix_To_Single_6;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Cste_0'
     *  MinMax: '<S11>/MinMax'
     *  Sum: '<S11>/Sum'
     *  UnitDelay: '<S18>/Unit Delay'
     */
    if (SftyMgt_bAcvCllRaw_MP) {
      localDTConv_UFix_To_Single_8 = rt_MINf
        (TqCkEngLimCord_DWork.UnitDelay_DSTATE_iw, localSum1) +
        localDTConv_UFix_To_Single_11;
    } else {
      localDTConv_UFix_To_Single_8 = 0.0F;
    }

    /* Logic: '<S7>/Logical Operator3' incorporates:
     *  RelationalOperator: '<S11>/Relational Operator'
     */
    SftyMgt_bDftCll = ((localDTConv_UFix_To_Single_8 >= localSum1) &&
                       (localLogicalOperator_o));

    /* Update for UnitDelay: '<S15>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_k = localSwitch2;

    /* Update for UnitDelay: '<S16>/Unit Delay' incorporates:
     *  Constant: '<S14>/NotCLR2'
     */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_m = TRUE;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_i = localSwitch_f;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_c = localSwitch_i;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_gf = localDTConv_UFix_To_Single_4_k;

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_iw = localDTConv_UFix_To_Single_8;

    /* end of Outputs for SubSystem: '<S6>/F01_Generer_demande_bouclage' */
    /* S-Function "vems_vidGET" Block: <S6>/S-Function14 */
    VEMS_vidGET(SftyMgt_tqIdcEngLimCo, TqCkEngLimCord_B.SFunction14);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function13 */
    VEMS_vidGET(SftyMgt_tqCkAntiOscCor, TqCkEngLimCord_B.SFunction13);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function12 */
    VEMS_vidGET(SftyMgt_tqIdcAgIgMin, TqCkEngLimCord_B.SFunction12);

    /* S-Function "vems_vidGET" Block: <S6>/S-Function10 */
    VEMS_vidGET(SftyMgt_nCkFil, TqCkEngLimCord_B.SFunction10);

    /* DataTypeConversion Block: '<S27>/Data Type Conversion'
     *
     * Regarding '<S27>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S6>/S-Function11 */
    VEMS_vidGET(SftyMgt_bAcvAutoInj, TqCkEngLimCord_B.SFunction11);

    /* Outputs for atomic SubSystem: '<S6>/F02_Generer_Couple_Boucle' *
     * Block requirements for '<S6>/F02_Generer_Couple_Boucle':
     *  1. SubSystem "F02_Generer_Couple_Boucle" !Trace_To : VEMS_R_10_01252_003.02 ;
     */

    /* Outputs for atomic SubSystem: '<S8>/F02_01_bouclage_debouclage' *
     * Block requirements for '<S8>/F02_01_bouclage_debouclage':
     *  1. SubSystem "F02_01_bouclage_debouclage" !Trace_To : VEMS_R_10_01252_004.02 ;
     */

    /* Switch: '<S21>/Switch2' */
    if (TqCkEngLimCord_B.SFunction5) {
      SftyMgt_tqCkEngLimCordRaw = TqCkEngLimCord_B.SFunction14;
    } else {
      SftyMgt_tqCkEngLimCordRaw = TqCkEngLimCord_B.SFunction4;
    }

    /* end of Outputs for SubSystem: '<S8>/F02_01_bouclage_debouclage' */

    /* Outputs for atomic SubSystem: '<S8>/F02_02_AOS' *
     * Block requirements for '<S8>/F02_02_AOS':
     *  1. SubSystem "F02_02_AOS" !Trace_To : VEMS_R_10_01252_006.01 ;
     */

    /* RelationalOperator: '<S22>/Relational Operator3' incorporates:
     *  Constant: '<S22>/SftyMgt_tqMaxAntiOsc_C'
     */
    SftyMgt_bDftAOS = (TqCkEngLimCord_B.SFunction13 > SftyMgt_tqMaxAntiOsc_C);

    /* Sum: '<S22>/Sum2' */
    localDTConv_UFix_To_Single_13 = SftyMgt_tqCkEngLimCordRaw +
      TqCkEngLimCord_B.SFunction13;
    if (localDTConv_UFix_To_Single_13 > 32767) {
      SftyMgt_tqCkAntiOscCord = MAX_int16_T;
    } else if (localDTConv_UFix_To_Single_13 <= -32768) {
      SftyMgt_tqCkAntiOscCord = MIN_int16_T;
    } else {
      SftyMgt_tqCkAntiOscCord = (SInt16)localDTConv_UFix_To_Single_13;
    }

    /* end of Outputs for SubSystem: '<S8>/F02_02_AOS' */

    /* Outputs for atomic SubSystem: '<S8>/F02_03_CoordinationBoucleAAMin' *
     * Block requirements for '<S8>/F02_03_CoordinationBoucleAAMin':
     *  1. SubSystem "F02_03_CoordinationBoucleAAMin" !Trace_To : VEMS_R_10_01252_007.01 ;
     */

    /* Logic: '<S23>/Logical Operator3' incorporates:
     *  Constant: '<S23>/SftyMgt_tqOfsAgIgMin_C'
     *  DataTypeConversion: '<S23>/DTConv_UFix_To_Single_1'
     *  RelationalOperator: '<S23>/Relational Operator4'
     *  Sum: '<S23>/Sum1'
     */
    SftyMgt_bDftAgIgMin = ((TqCkEngLimCord_B.SFunction12 >=
      (SftyMgt_tqCkAntiOscCord + SftyMgt_tqOfsAgIgMin_C)) &&
      TqCkEngLimCord_B.SFunction5);

    /* MinMax: '<S23>/MinMax' */
    localrtmax = SftyMgt_tqCkAntiOscCord;
    if (TqCkEngLimCord_B.SFunction12 > SftyMgt_tqCkAntiOscCord) {
      localrtmax = TqCkEngLimCord_B.SFunction12;
    }

    SftyMgt_tqIdcEngLimCordIgMin = localrtmax;

    /* end of Outputs for SubSystem: '<S8>/F02_03_CoordinationBoucleAAMin' */

    /* Outputs for atomic SubSystem: '<S8>/F02_04_OTorque' *
     * Block requirements for '<S8>/F02_04_OTorque':
     *  1. SubSystem "F02_04_OTorque" !Trace_To : VEMS_R_10_01252_009.03 ;
     */

    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/Cste_0'
     *  Constant: '<S24>/Cste_1'
     *  Logic: '<S24>/Logical Operator1'
     *  Logic: '<S24>/Logical Operator3'
     *  RelationalOperator: '<S24>/Relational Operator2'
     */
    if ((SftyMgt_tqCkAntiOscCord == 0) && (!TqCkEngLimCord_B.SFunction11)) {
      TqCkEngLimCord_B.Switch1 = 0;
    } else {
      TqCkEngLimCord_B.Switch1 = SftyMgt_tqIdcEngLimCordIgMin;
    }

    /* end of Outputs for SubSystem: '<S8>/F02_04_OTorque' */

    /* Outputs for atomic SubSystem: '<S8>/F02_05_securisation_consigne_air' *
     * Block requirements for '<S8>/F02_05_securisation_consigne_air':
     *  1. SubSystem "F02_05_securisation_consigne_air" !Trace_To : VEMS_R_10_01252_005.02 ;
     */

    /* Lookup: '<S27>/Look-Up Table'
     * About '<S27>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-2
     * Output0 Data Type:  Fixed Point    U16  2^-4  Bias -2000.0
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(SftyMgt_tqOplThd_T[0])),
                   TqCkEngLimCord_B.SFunction10, (&(SftyMgt_nEngOplThdX_A[0])),
                   7U);

    /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate1'
     *
     * Regarding '<S27>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Logic: '<S25>/Logical Operator1' incorporates:
     *  DataTypeConversion: '<S25>/DTConv_UFix_To_Single_3'
     *  Logic: '<S25>/LogicalOperator'
     *  RelationalOperator: '<S25>/Relational Operator1'
     *  Sum: '<S25>/Sum'
     */
    SftyMgt_bDftIdcAir = ((!TqCkEngLimCord_B.SFunction5) &&
                          (TqCkEngLimCord_B.SFunction3 > ((-32000 +
      TqCkEngLimCord_B.SFunction14) + localLookUpTable)));

    /* end of Outputs for SubSystem: '<S8>/F02_05_securisation_consigne_air' */

    /* Outputs for atomic SubSystem: '<S8>/F02_06_synthese_defaut' *
     * Block requirements for '<S8>/F02_06_synthese_defaut':
     *  1. SubSystem "F02_06_synthese_defaut" !Trace_To : VEMS_R_10_01252_008.02 ;
     */

    /* DataTypeConversion: '<S26>/DTConv_UFix_To_Single_8' incorporates:
     *  Constant: '<S26>/SftyMgt_tiSdlCllReq_SC_1'
     */
    localDTConv_UFix_To_Single_4_k = ((Float)SftyMgt_tiSdlCllReq_SC) *
      1.000000047E-003F;

    /* Sum: '<S28>/Sum1' incorporates:
     *  Constant: '<S26>/SftyMgt_tiDftTqIdcAgIgMin_C'
     *  DataTypeConversion: '<S26>/DTConv_UFix_To_Single_7'
     */
    localDTConv_UFix_To_Single_8 = (((Float)SftyMgt_tiDftTqIdcAgIgMin_C) *
      3.999999911E-002F) + localDTConv_UFix_To_Single_4_k;

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Cste_0'
     *  MinMax: '<S28>/MinMax'
     *  Sum: '<S28>/Sum'
     *  UnitDelay: '<S32>/Unit Delay'
     */
    if (SftyMgt_bDftAgIgMin) {
      localDTConv_UFix_To_Single_11 = rt_MINf
        (TqCkEngLimCord_DWork.UnitDelay_DSTATE, localDTConv_UFix_To_Single_8) +
        localDTConv_UFix_To_Single_4_k;
    } else {
      localDTConv_UFix_To_Single_11 = 0.0F;
    }

    /* Switch: '<S26>/Switch3' incorporates:
     *  Constant: '<S26>/Cste_0_3'
     *  Constant: '<S26>/SftyMgt_bInhDftAgIgMin_C'
     *  RelationalOperator: '<S28>/Relational Operator'
     */
    if (SftyMgt_bInhDftAgIgMin_C) {
      SftyMgt_bDgoAgIgMin_MP = FALSE;
    } else {
      SftyMgt_bDgoAgIgMin_MP = (localDTConv_UFix_To_Single_11 >=
        localDTConv_UFix_To_Single_8);
    }

    /* Sum: '<S29>/Sum1' incorporates:
     *  Constant: '<S26>/SftyMgt_tiDftTqAntiOscMon_C'
     *  DataTypeConversion: '<S26>/DTConv_UFix_To_Single_4'
     */
    localSwitch_f = (((Float)SftyMgt_tiDftTqAntiOscMon_C) * 3.999999911E-002F)
      + localDTConv_UFix_To_Single_4_k;

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Cste_0'
     *  MinMax: '<S29>/MinMax'
     *  Sum: '<S29>/Sum'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    if (SftyMgt_bDftAOS) {
      localDTConv_UFix_To_Single_3 = rt_MINf
        (TqCkEngLimCord_DWork.UnitDelay_DSTATE_e, localSwitch_f) +
        localDTConv_UFix_To_Single_4_k;
    } else {
      localDTConv_UFix_To_Single_3 = 0.0F;
    }

    /* Switch: '<S26>/Switch4' incorporates:
     *  Constant: '<S26>/Cste_0'
     *  Constant: '<S26>/SftyMgt_bInhDftAOS_C'
     *  RelationalOperator: '<S29>/Relational Operator'
     */
    if (SftyMgt_bInhDftAOS_C) {
      SftyMgt_bDgoAOS_MP = FALSE;
    } else {
      SftyMgt_bDgoAOS_MP = (localDTConv_UFix_To_Single_3 >= localSwitch_f);
    }

    /* Sum: '<S30>/Sum1' incorporates:
     *  Constant: '<S26>/SftyMgt_tiDftIdcAir_C'
     *  DataTypeConversion: '<S26>/DTConv_UFix_To_Single_2'
     */
    localSwitch_f = (((Float)SftyMgt_tiDftIdcAir_C) * 3.999999911E-002F) +
      localDTConv_UFix_To_Single_4_k;

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S30>/Cste_0'
     *  MinMax: '<S30>/MinMax'
     *  Sum: '<S30>/Sum'
     *  UnitDelay: '<S34>/Unit Delay'
     */
    if (SftyMgt_bDftIdcAir) {
      localSwitch_i = rt_MINf(TqCkEngLimCord_DWork.UnitDelay_DSTATE_o,
        localSwitch_f) + localDTConv_UFix_To_Single_4_k;
    } else {
      localSwitch_i = 0.0F;
    }

    /* Switch: '<S26>/Switch2' incorporates:
     *  Constant: '<S26>/Cste_2'
     *  Constant: '<S26>/SftyMgt_bInhDftIdcAir_C'
     *  RelationalOperator: '<S30>/Relational Operator'
     */
    if (SftyMgt_bInhDftIdcAir_C) {
      SftyMgt_bDgoIdcAir_MP = FALSE;
    } else {
      SftyMgt_bDgoIdcAir_MP = (localSwitch_i >= localSwitch_f);
    }

    /* Sum: '<S31>/Sum1' incorporates:
     *  Constant: '<S26>/SftyMgt_tiDftCll_C'
     *  DataTypeConversion: '<S26>/DTConv_UFix_To_Single_1'
     */
    localSwitch_f = (((Float)SftyMgt_tiDftCll_C) * 3.999999911E-002F) +
      localDTConv_UFix_To_Single_4_k;

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Cste_0'
     *  MinMax: '<S31>/MinMax'
     *  Sum: '<S31>/Sum'
     *  UnitDelay: '<S35>/Unit Delay'
     */
    if (SftyMgt_bDftCll) {
      localDTConv_UFix_To_Single_8 = rt_MINf
        (TqCkEngLimCord_DWork.UnitDelay_DSTATE_g, localSwitch_f) +
        localDTConv_UFix_To_Single_4_k;
    } else {
      localDTConv_UFix_To_Single_8 = 0.0F;
    }

    /* Switch: '<S26>/Switch1' incorporates:
     *  Constant: '<S26>/Cste_0_2'
     *  Constant: '<S26>/SftyMgt_bInhDftCll_C'
     *  RelationalOperator: '<S31>/Relational Operator'
     */
    if (SftyMgt_bInhDftCll_C) {
      SftyMgt_bDgoCll_MP = FALSE;
    } else {
      SftyMgt_bDgoCll_MP = (localDTConv_UFix_To_Single_8 >= localSwitch_f);
    }

    /* Logic: '<S26>/Logical Operator2' */
    TqCkEngLimCord_B.LogicalOperator2 = (((SftyMgt_bDgoAgIgMin_MP ||
      SftyMgt_bDgoAOS_MP) || SftyMgt_bDgoIdcAir_MP) || SftyMgt_bDgoCll_MP);

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE = localDTConv_UFix_To_Single_11;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_e = localDTConv_UFix_To_Single_3;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_o = localSwitch_i;

    /* Update for UnitDelay: '<S35>/Unit Delay' */
    TqCkEngLimCord_DWork.UnitDelay_DSTATE_g = localDTConv_UFix_To_Single_8;

    /* end of Outputs for SubSystem: '<S8>/F02_06_synthese_defaut' */

    /* end of Outputs for SubSystem: '<S6>/F02_Generer_Couple_Boucle' */
    /* S-Function "vems_vidSET" Block: <S6>/S-Function15 */
    VEMS_vidSET(SftyMgt_tqCkEngLimCord, TqCkEngLimCord_B.Switch1);

    /* S-Function "vems_vidSET" Block: <S6>/S-Function2 */
    VEMS_vidSET(SftyMgt_bDgoTqCord, TqCkEngLimCord_B.LogicalOperator2);
  }

  /* end of Outputs for SubSystem: '<S4>/F0_CSCT_CGMT09_2641_v2_4_Gerer_Bouclage' */
}

/* Output and update for exported function: SftyMgt_SdlMid_tqCkEngLimCord */
void SftyMgt_SdlMid_tqCkEngLimCord(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/CSCT_CGMT09_2641_v2_4_Gerer_Bouclage'
   */
  CSCT_CGMT09_2641_v2_4_Gerer_Bou();
}

/* Output and update for function-call system: '<S1>/Init' */
void TqCkEngLimCord_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S5>/S-Function15 */
  VEMS_vidSET(SftyMgt_bDgoTqCord, FALSE);

  /* S-Function "vems_vidSET" Block: <S5>/S-Function1 */
  VEMS_vidSET(SftyMgt_tqCkEngLimCord, 0);
}

/* Output and update for exported function: SftyMgt_Init_tqCkEngLimCord */
void SftyMgt_Init_tqCkEngLimCord(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/Init'
   */
  TqCkEngLimCord_Init();
}

/* Model initialize function */
void TqCkEngLimCord_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
}

#define TQCKENGLIMCORD_STOP_SEC_CODE
#include "TqCkEngLimCord_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
