/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjAstWupCmp                                            */
/* !Description     : INJECTION CORRECTION IN AFTER START AND WARM UP         */
/*                                                                            */
/* !Module          : InjAstWupCmp                                            */
/*                                                                            */
/* !File            : InjAstWupCmp.c                                          */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : PTS_DOC_5038663 / 03                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Feb 18 18:51:55 2013                              */
/*   Model name       : InjAstWupCmp_AUTOCODE.mdl                             */
/*   Model version    : 1.510                                                 */
/*   Root subsystem   : /InjAstWupCmp                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJASTWUPCMP/InjAstWupCmp.$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjAstWupCmp.h"
#include "InjAstWupCmp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S35>/F01_Etat_Activations1' */
#define IN_State_AstAutn               (1U)
#define IN_State_AstSTT                (2U)
#define IN_State_AstStrt               (3U)
#define IN_State_Normal                (4U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define INJASTWUPCMP_START_SEC_VAR_UNSPECIFIED
#include "InjAstWupCmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjAstWupCmp InjAstWupCmp_B;

/* Block states (auto storage) */
D_Work_InjAstWupCmp InjAstWupCmp_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_InjAstWupCmp InjAstWupCmp_PrevZCSigState;

#define INJASTWUPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "InjAstWupCmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJASTWUPCMP_START_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

void InjAstWupCmp_ASYNC1(int controlPortIdx)
{
}

void InjAstWupCmp_ASYNC2(int controlPortIdx)
{
  InjAstWupCmp_F02_InjAstWupCmp();
}

/* Output and update for function-call system: '<S1>/F01_Initialization' */
void InjAstWupCmp_F01_Initialization(void)
{
  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET5 */
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
    VEMS_vidSET1DArray( InjSys_prm_facStrtCorCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET3 */
  VEMS_vidSET(InjSys_bAcvStrtCor, FALSE);

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET4 */
  VEMS_vidSET(InjSys_ctNbCmbAst, ((UInt16)0U));
}

/* Output and update for exported function: InjSys_EveRst_InjAstWupCmp */
void InjSys_EveRst_InjAstWupCmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialization'
   */
  InjAstWupCmp_F01_Initialization();
}

/* Start for function-call system: '<S1>/F02_InjAstWupCmp' */
void InjAstWu_F02_InjAstWupCmp_Start(void)
{
  SInt32 locali;

  /* Start for enable SubSystem: '<S6>/F00_InjAstWupCmp' */

  /* InitializeConditions for UnitDelay: '<S153>/Unit Delay' */
  for (locali = 0; locali < 6; locali++) {
    InjAstWupCmp_DWork.UnitDelay_DSTATE_k[(locali)] =
      InjAstWupCmp_ConstP.UnitDelay_X0[(locali)];
  }

  /* end of Start for SubSystem: '<S6>/F00_InjAstWupCmp' */
}

/* Output and update for function-call system: '<S1>/F02_InjAstWupCmp' */
void InjAstWupCmp_F02_InjAstWupCmp(void)
{
  UInt32 localExt_nEng_InjSys_nEng_facWu;
  Boolean localLogicalOperator;
  Boolean localLogicalOperator4;
  UInt16 localSwitch2_g;
  Float32 localExt_tCoMes_InjSys_tCo_facW;
  Float32 localEngM_mAirPred_InjAstWupCmp;
  Float32 localSum1;
  Float32 localSwitch_p;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Float32 localfrac_0[2];
  Float32 localSwitch2;
  UInt32 localbpIndex_0[2];
  Float32 localfrac_1[2];
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
  Boolean localLowerRelop1_e;
  Boolean localUpperRelop_o;
  Float32 localAssignment1[6];
  Float32 localAdd4;
  Float32 localDataTypeConversion1_i;
  Float32 localExt_tCoMes_InjSys_tCo_fa_e;
  Float32 localfrac_b[2];
  Float32 localInjSys_ctNbCmbAst_InjSys_m;
  UInt32 localExt_tCoMes_InjSys_tCo_f_en;
  UInt32 localbpIndex_b[2];
  Float32 localfrac_c[2];
  UInt32 localbpIndex_c[2];
  Float32 localMultiportSwitch1_g;
  Float32 localfrac_d[2];
  Float32 localSwitch_i;
  UInt32 localExt_nEng_InjSys_nEng_fac_n;
  UInt32 localbpIndex_d[2];
  UInt32 localEngM_mAirPred_InjAstWupC_i;
  Float32 localfrac_e[2];
  UInt32 localbpIndex_e[2];
  Float32 localfrac_f[2];
  UInt32 localbpIndex_f[2];
  Float32 localfrac_g[2];
  UInt32 localbpIndex_g[2];
  Float32 localfrac_h[2];
  UInt32 localbpIndex_h[2];
  Float32 localfrac_i[2];
  UInt32 localbpIndex_i[2];
  Float32 localfrac_j[2];
  UInt32 localbpIndex_j[2];
  Float32 localfrac_k[2];
  UInt32 localbpIndex_k[2];
  Float32 localfrac_l[2];
  UInt32 localbpIndex_l[2];
  Float32 localfrac_m[2];
  UInt32 localbpIndex_m[2];
  Float32 localMultiportSwitch1_m;
  Float32 localfrac_n[2];
  Float32 localMultiportSwitch_j;
  UInt32 localbpIndex_n[2];
  Float32 localfrac_o[2];
  UInt32 localbpIndex_o[2];
  Float32 localfrac_p[2];
  UInt32 localbpIndex_p[2];
  Float32 localfrac_q[2];
  UInt32 localbpIndex_q[2];
  Float32 localfrac_r[2];
  UInt32 localbpIndex_r[2];
  Float32 localfrac_s[2];
  UInt32 localbpIndex_s[2];
  Float32 localfrac_t[2];
  UInt32 localbpIndex_t[2];
  Float32 localfrac_u[2];
  UInt32 localbpIndex_u[2];
  Float32 localExt_tCoMes_InjSys_tCo_facA;
  Float32 localfrac_v[2];
  Float32 localInjSys_ctNbCmbAst_InjSys_c;
  UInt32 localbpIndex_v[2];
  Float32 localMultiportSwitch1;
  Float32 localfrac_w[2];
  Float32 localMultiportSwitch;
  UInt32 localbpIndex_w[2];
  Float32 localfrac_x[2];
  UInt32 localbpIndex_x[2];
  Float32 localfrac_y[2];
  UInt32 localbpIndex_y[2];
  Float32 localfrac_z[2];
  UInt32 localbpIndex_z[2];
  Float32 localfrac_10[2];
  UInt32 localbpIndex_10[2];
  Float32 localfrac_11[2];
  UInt32 localbpIndex_11[2];
  Float32 localfrac_12[2];
  UInt32 localbpIndex_12[2];
  SInt32 locali;
  SInt8 locallocalOutDTConv_p;
  SInt8 locallocalOutDTConv;
  UInt8 locallocalDataTypeConversion;
  UInt8 locallocalDataTypeConversion_0;
  UInt8 locallocalDataTypeConversion_1;

  /* Outputs for enable SubSystem: '<S6>/F00_InjAstWupCmp' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/INJASTWUPCMP_u8Inhib'
   *  EnablePort: '<S8>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (INJASTWUPCMP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET38 */
    VEMS_vidGET(Ext_tAirExtMes, InjAstWupCmp_B.VEMS_vidGET38);

    /* DataTypeConversion: '<S8>/Data Type Conversion11' */
    locali = InjAstWupCmp_B.VEMS_vidGET38 + 50;
    if (locali <= 0) {
      locallocalDataTypeConversion = 0U;
    } else if (locali > 255) {
      locallocalDataTypeConversion = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion = (UInt8)locali;
    }

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET39 */
    VEMS_vidGET(Ext_tCoMes, InjAstWupCmp_B.VEMS_vidGET39);

    /* DataTypeConversion: '<S8>/Data Type Conversion12' */
    locali = InjAstWupCmp_B.VEMS_vidGET39 + 40;
    if (locali <= 0) {
      locallocalDataTypeConversion_0 = 0U;
    } else if (locali > 255) {
      locallocalDataTypeConversion_0 = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion_0 = (UInt8)locali;
    }

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET34 */
    VEMS_vidGET(Eng_noInNxtCyl, InjAstWupCmp_B.VEMS_vidGET34);

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant1'
     *  DataTypeConversion: '<S9>/DTConv_UFix_To_Single_1'
     */
    localExt_nEng_InjSys_nEng_facWu = ((UInt32)InjAstWupCmp_B.VEMS_vidGET34) -
      1U;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET31 */
    VEMS_vidGET1DArray(EngM_prm_mAirPredInCyl, 6, InjAstWupCmp_B.VEMS_vidGET31);

    /* DataTypeDuplicate Block: '<S17>/Data Type Duplicate'
     *
     * Regarding '<S17>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S17>/Selector' incorporates:
     *  Constant: '<S17>/Constant'
     *  MinMax: '<S17>/MinMax'
     */
    EngM_mAirPred_InjAstWupCmp = InjAstWupCmp_B.VEMS_vidGET31[rt_MIN
      (localExt_nEng_InjSys_nEng_facWu, 5U)];

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET35 */
    VEMS_vidGET(Ext_bAcvInjSys, InjAstWupCmp_B.VEMS_vidGET35_b);

    /* Logic: '<S20>/Logical Operator' incorporates:
     *  Logic: '<S20>/Logical Operator1'
     *  UnitDelay: '<S31>/Unit Delay'
     */
    localLogicalOperator = (InjAstWupCmp_B.VEMS_vidGET35_b &&
      (!InjAstWupCmp_DWork.UnitDelay_DSTATE_m));

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET25 */
    VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjAstWupCmp_B.VEMS_vidGET25);

    /* Logic: '<S10>/Logical Operator4' incorporates:
     *  Logic: '<S10>/Logical Operator1'
     *  Logic: '<S10>/Logical Operator3'
     *  UnitDelay: '<S19>/Unit Delay'
     */
    localLogicalOperator4 = ((localLogicalOperator) ||
      ((!InjAstWupCmp_B.VEMS_vidGET25) && InjAstWupCmp_DWork.UnitDelay_DSTATE_ij));

    /* Sum: '<S18>/Sum1' incorporates:
     *  UnitDelay: '<S23>/Unit Delay'
     */
    localExt_nEng_InjSys_nEng_facWu = (UInt32)(1 +
      InjAstWupCmp_DWork.UnitDelay_DSTATE_i);
    if (localExt_nEng_InjSys_nEng_facWu > 65535U) {
      localSwitch2_g = MAX_uint16_T;
    } else {
      localSwitch2_g = (UInt16)localExt_nEng_InjSys_nEng_facWu;
    }

    /* Switch: '<S18>/Switch1' incorporates:
     *  UnitDelay: '<S23>/Unit Delay'
     */
    if (!InjAstWupCmp_B.VEMS_vidGET35_b) {
      localSwitch2_g = InjAstWupCmp_DWork.UnitDelay_DSTATE_i;
    }

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Logic: '<S24>/Logical Operator'
     *  Logic: '<S24>/Logical Operator1'
     *  UnitDelay: '<S24>/UnitDelay'
     */
    if ((localLogicalOperator4) && (!InjAstWupCmp_DWork.UnitDelay)) {
      localSwitch2_g = 0U;
    }

    /* Switch: '<S30>/Switch2' incorporates:
     *  RelationalOperator: '<S30>/LowerRelop1'
     */
    if (localSwitch2_g > 4095) {
      InjAstWupCmp_B.Switch2 = 4095U;
    } else {
      InjAstWupCmp_B.Switch2 = localSwitch2_g;
    }

    /* Logic: '<S10>/Logical Operator2' incorporates:
     *  Constant: '<S10>/InjSys_bAcvStrtCor_C'
     *  Constant: '<S10>/InjSys_tAcvStrtCor_C'
     *  Logic: '<S10>/Logical Operator'
     *  RelationalOperator: '<S10>/Relational Operator1'
     */
    InjAstWupCmp_B.LogicalOperator2 = ((InjAstWupCmp_B.VEMS_vidGET35_b &&
      (locallocalDataTypeConversion_0 <= InjSys_tAcvStrtCor_C)) &&
      InjSys_bAcvStrtCor_C);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET29 */
    VEMS_vidGET(EngM_agCkClsExVlvReqRef1, InjAstWupCmp_B.VEMS_vidGET29);

    /* DataTypeConversion: '<S11>/Data Type Conversion2' */
    localExt_tCoMes_InjSys_tCo_facW = ((Float32)InjAstWupCmp_B.VEMS_vidGET29) *
      0.09375F;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET30 */
    VEMS_vidGET(EngM_agCkOpInVlvReqRef1, InjAstWupCmp_B.VEMS_vidGET30);

    /* DataTypeConversion: '<S11>/Data Type Conversion3' */
    localEngM_mAirPred_InjAstWupCmp = ((Float32)InjAstWupCmp_B.VEMS_vidGET30) *
      0.09375F;

    /* Sum: '<S11>/Sum1' */
    localSum1 = localEngM_mAirPred_InjAstWupCmp +
      localExt_tCoMes_InjSys_tCo_facW;

    /* Product: '<S34>/Divide' incorporates:
     *  Constant: '<S11>/Constant'
     */
    InjSys_agCkPosnVlvOvlp = localSum1 / 2.0F;

    /* Product: '<S32>/Product4' incorporates:
     *  Constant: '<S32>/offset'
     *  Constant: '<S32>/one_on_slope'
     *  Sum: '<S32>/Add1'
     */
    localSwitch_p = 1.333333373E+000F * InjSys_agCkPosnVlvOvlp;

    /* Sum: '<S32>/Add3' incorporates:
     *  Constant: '<S32>/offset3'
     */
    localSum1 = localSwitch_p + 0.5F;

    /* Sum: '<S32>/Add4' incorporates:
     *  Constant: '<S32>/offset4'
     */
    localAdd4 = localSwitch_p - 0.5F;

    /* RelationalOperator: '<S32>/Relational Operator' incorporates:
     *  Constant: '<S32>/offset2'
     */
    localLogicalOperator = (localSwitch_p >= 0.0F);

    /* Switch: '<S32>/Switch1' */
    if (localLogicalOperator) {
      localSwitch_p = localSum1;
    } else {
      localSwitch_p = localAdd4;
    }

    /* DataTypeConversion: '<S32>/OutDTConv' */
    localSum1 = localSwitch_p;
    if (localSum1 < 128.0F) {
      if (localSum1 >= -128.0F) {
        locallocalOutDTConv = (SInt8)localSum1;
      } else {
        locallocalOutDTConv = MIN_int8_T;
      }
    } else {
      locallocalOutDTConv = MAX_int8_T;
    }

    /* Sum: '<S11>/Sum' */
    InjSys_agCkVlvOvlp = localExt_tCoMes_InjSys_tCo_facW -
      localEngM_mAirPred_InjAstWupCmp;

    /* Product: '<S33>/Product4' incorporates:
     *  Constant: '<S33>/offset'
     *  Constant: '<S33>/one_on_slope'
     *  Sum: '<S33>/Add1'
     */
    localSwitch_p = 6.666666865E-001F * InjSys_agCkVlvOvlp;

    /* Sum: '<S33>/Add3' incorporates:
     *  Constant: '<S33>/offset3'
     */
    localSum1 = localSwitch_p + 0.5F;

    /* Sum: '<S33>/Add4' incorporates:
     *  Constant: '<S33>/offset4'
     */
    localAdd4 = localSwitch_p - 0.5F;

    /* RelationalOperator: '<S33>/Relational Operator' incorporates:
     *  Constant: '<S33>/offset2'
     */
    localLogicalOperator = (localSwitch_p >= 0.0F);

    /* Switch: '<S33>/Switch1' */
    if (localLogicalOperator) {
      localSwitch_p = localSum1;
    } else {
      localSwitch_p = localAdd4;
    }

    /* DataTypeConversion: '<S33>/OutDTConv' */
    localSum1 = localSwitch_p;
    if (localSum1 < 128.0F) {
      if (localSum1 >= -128.0F) {
        locallocalOutDTConv_p = (SInt8)localSum1;
      } else {
        locallocalOutDTConv_p = MIN_int8_T;
      }
    } else {
      locallocalOutDTConv_p = MAX_int8_T;
    }

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET36 */
    VEMS_vidGET(Ext_nEng, InjAstWupCmp_B.VEMS_vidGET36);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET48 */
    VEMS_vidGET(InjSys_noInjPat, InjAstWupCmp_B.VEMS_vidGET48);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET28 */
    VEMS_vidGET(EOM_tiEngStopRst, InjAstWupCmp_B.VEMS_vidGET28);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET42 */
    VEMS_vidGET(FISA_facAstAdp, InjAstWupCmp_B.VEMS_vidGET42);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET33 */
    VEMS_vidGET(EngReqH_bEngRStrtAutnAvl, InjAstWupCmp_B.VEMS_vidGET33);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET26 */
    VEMS_vidGET(CoPTSt_stEngNew, InjAstWupCmp_B.VEMS_vidGET26);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET27 */
    VEMS_vidGET(EOM_bTWCHeatPha, InjAstWupCmp_B.VEMS_vidGET27);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET49 */
    VEMS_vidGET(TWCMgt_stHeatPhaReq, InjAstWupCmp_B.VEMS_vidGET49);

    /* Outputs for atomic SubSystem: '<S8>/F03_After_start' *
     * Block requirements for '<S8>/F03_After_start':
     *  1. SubSystem "F02_After_start" !Trace_To : VEMS_R_10_07956_017.01 ;
     */

    /* Stateflow: '<S35>/F01_Etat_Activations1' incorporates:
     *  Constant: '<S35>/CoPTSt_stEndStall_SC'
     *  Constant: '<S35>/CoPTSt_stFirstStrt_SC'
     *  Constant: '<S35>/CoPTSt_stRstrt_SC'
     *  Constant: '<S35>/CoPTSt_stStall_SC'
     *  Constant: '<S35>/CoPTSt_stStopSTT_SC'
     *  Constant: '<S35>/CoPTSt_stStop_SC'
     *  Constant: '<S35>/InjSys_stAstAutn_SC'
     *  Constant: '<S35>/InjSys_stAstSTT_SC'
     *  Constant: '<S35>/InjSys_stAstStrt_SC'
     *  Constant: '<S35>/InjSys_stIni_SC'
     */
    /* Gateway: InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F01_Detection_Life_Case/F01_Etat_Activations1 */
    /* During: InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F01_Detection_Life_Case/F01_Etat_Activations1 */
    if (InjAstWupCmp_DWork.is_active_c2_InjAstWupCmp == 0) {
      /* Entry: InjAstWupCmp/F02_InjAstWupCmp/F00_InjAstWupCmp/F03_After_start/F01_Detection_Life_Case/F01_Etat_Activations1 */
      InjAstWupCmp_DWork.is_active_c2_InjAstWupCmp = 1U;

      /* Transition: '<S40>:5' */
      /* Entry 'State_Normal': '<S40>:2' */
      InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_Normal;
      InjSys_stAcvAst = InjSys_stIni_SC;
    } else {
      switch (InjAstWupCmp_DWork.is_c2_InjAstWupCmp) {
       case IN_State_AstAutn:
        /* During 'State_AstAutn': '<S40>:4' */
        if ((((InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStopSTT_SC) ||
              (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStall_SC)) ||
             (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStop_SC)) || (((SInt32)
              InjAstWupCmp_B.VEMS_vidGET25) == 1)) {
          /* Transition: '<S40>:8' */
          /* Exit 'State_AstAutn': '<S40>:4' */
          /* Entry 'State_Normal': '<S40>:2' */
          InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_Normal;
          InjSys_stAcvAst = InjSys_stIni_SC;
        }
        break;

       case IN_State_AstSTT:
        /* During 'State_AstSTT': '<S40>:1' */
        if (((InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStopSTT_SC) ||
             (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStall_SC)) ||
            (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStop_SC)) {
          /* Transition: '<S40>:10' */
          /* Exit 'State_AstSTT': '<S40>:1' */
          /* Entry 'State_Normal': '<S40>:2' */
          InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_Normal;
          InjSys_stAcvAst = InjSys_stIni_SC;
        }
        break;

       case IN_State_AstStrt:
        /* During 'State_AstStrt': '<S40>:3' */
        if ((((InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStopSTT_SC) ||
              (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStall_SC)) ||
             (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stStop_SC)) || (((SInt32)
              InjAstWupCmp_B.VEMS_vidGET25) == 1)) {
          /* Transition: '<S40>:7' */
          /* Exit 'State_AstStrt': '<S40>:3' */
          /* Entry 'State_Normal': '<S40>:2' */
          InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_Normal;
          InjSys_stAcvAst = InjSys_stIni_SC;
        }
        break;

       case IN_State_Normal:
        /* During 'State_Normal': '<S40>:2' */
        if ((InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stRstrt_SC) && (((SInt32)
              InjAstWupCmp_B.VEMS_vidGET33) == 1)) {
          /* Transition: '<S40>:11' */
          /* Exit 'State_Normal': '<S40>:2' */
          /* Entry 'State_AstAutn': '<S40>:4' */
          InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_AstAutn;
          InjSys_stAcvAst = InjSys_stAstAutn_SC;
        } else if (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stFirstStrt_SC) {
          /* Transition: '<S40>:9' */
          /* Exit 'State_Normal': '<S40>:2' */
          /* Entry 'State_AstStrt': '<S40>:3' */
          InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_AstStrt;
          InjSys_stAcvAst = InjSys_stAstStrt_SC;
        } else {
          if ((((InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stRstrt_SC) &&
                (((SInt32)InjAstWupCmp_B.VEMS_vidGET33) == 0)) ||
               (InjAstWupCmp_B.VEMS_vidGET26 == CoPTSt_stEndStall_SC)) ||
              (((SInt32)InjAstWupCmp_B.VEMS_vidGET25) == 1)) {
            /* Transition: '<S40>:6' */
            /* Exit 'State_Normal': '<S40>:2' */
            /* Entry 'State_AstSTT': '<S40>:1' */
            InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_AstSTT;
            InjSys_stAcvAst = InjSys_stAstSTT_SC;
          }
        }
        break;

       default:
        /* Transition: '<S40>:5' */
        /* Entry 'State_Normal': '<S40>:2' */
        InjAstWupCmp_DWork.is_c2_InjAstWupCmp = IN_State_Normal;
        InjSys_stAcvAst = InjSys_stIni_SC;
        break;
      }
    }

    /* Outputs for enable SubSystem: '<S12>/F02_Ast_Nominal_Start' incorporates:
     *  Constant: '<S12>/InjSys_stAstStrt_SC'
     *  EnablePort: '<S36>/Enable'
     *  RelationalOperator: '<S12>/Relational Operator3'
     */
    if (InjSys_stAcvAst == InjSys_stAstStrt_SC) {
      /* DataTypeConversion: '<S36>/Data Type Conversion1' */
      localDataTypeConversion1_i = ((Float32)InjAstWupCmp_B.VEMS_vidGET42) *
        0.0078125F;

      /* PreLookup: '<S56>/Prelookup' */
      localExt_tCoMes_InjSys_tCo_f_en = plook_u32u8f_binc
        (locallocalDataTypeConversion_0, (&(InjSys_tCo_facAstInjX_A[0])), 11U,
         &localExt_tCoMes_InjSys_tCo_fa_e);

      /* PreLookup: '<S57>/Prelookup' */
      localExt_nEng_InjSys_nEng_facWu = plook_u32u16f_binc
        (InjAstWupCmp_B.Switch2, (&(InjSys_ct_facAstInjY_A[0])), 7U,
         &localInjSys_ctNbCmbAst_InjSys_m);

      /* Interpolation_n-D: '<S41>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_b[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_b[1] = localSum1;
      localbpIndex_b[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_b[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstInj0_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_b,
        localfrac_b, (&(InjSys_facAstInj0_M[0])), 12U);

      /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_c[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_c[1] = localSum1;
      localbpIndex_c[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_c[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstInj1_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_c,
        localfrac_c, (&(InjSys_facAstInj1_M[0])), 12U);

      /* PreLookup: '<S58>/Prelookup' */
      localExt_nEng_InjSys_nEng_fac_n = plook_u32u16f_binc
        (InjAstWupCmp_B.VEMS_vidGET36, (&(InjSys_nEng_facAstCorInjX_A[0])), 7U,
         &localMultiportSwitch1_g);

      /* PreLookup: '<S59>/Prelookup' */
      localEngM_mAirPred_InjAstWupC_i = plook_u32u16f_binc
        (EngM_mAirPred_InjAstWupCmp, (&(InjSys_mAir_facAstCorInjY_A[0])), 7U,
         &localSwitch_i);

      /* Interpolation_n-D: '<S43>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_d[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_d[1] = localSum1;
      localbpIndex_d[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_d[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorTWCHeatHi_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_d,
        localfrac_d, (&(InjSys_facAstCorTWCHeatHi_M[0])), 8U);

      /* Interpolation_n-D: '<S44>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_e[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_e[1] = localSum1;
      localbpIndex_e[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_e[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorTWCHeatLo_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_e,
        localfrac_e, (&(InjSys_facAstCorTWCHeatLo_M[0])), 8U);

      /* Interpolation_n-D: '<S45>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_f[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_f[1] = localSum1;
      localbpIndex_f[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_f[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstInj2_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_f,
        localfrac_f, (&(InjSys_facAstInj2_M[0])), 12U);

      /* Interpolation_n-D: '<S46>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_g[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_g[1] = localSum1;
      localbpIndex_g[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_g[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstInj3_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_g,
        localfrac_g, (&(InjSys_facAstInj3_M[0])), 12U);

      /* Interpolation_n-D: '<S47>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_h[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_h[1] = localSum1;
      localbpIndex_h[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_h[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstTWCHeatHi_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_h,
        localfrac_h, (&(InjSys_facAstTWCHeatHi_M[0])), 12U);

      /* Interpolation_n-D: '<S48>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_fa_e;
      localfrac_i[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_m;
      localfrac_i[1] = localSum1;
      localbpIndex_i[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_i[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstTWCHeatLo_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_i,
        localfrac_i, (&(InjSys_facAstTWCHeatLo_M[0])), 12U);

      /* Interpolation_n-D: '<S49>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_j[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_j[1] = localSum1;
      localbpIndex_j[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_j[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj0_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_j,
        localfrac_j, (&(InjSys_facAstCorInj0_M[0])), 8U);

      /* Interpolation_n-D: '<S50>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_k[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_k[1] = localSum1;
      localbpIndex_k[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_k[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj1_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_k,
        localfrac_k, (&(InjSys_facAstCorInj1_M[0])), 8U);

      /* Interpolation_n-D: '<S51>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_l[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_l[1] = localSum1;
      localbpIndex_l[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_l[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj2_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_l,
        localfrac_l, (&(InjSys_facAstCorInj2_M[0])), 8U);

      /* Interpolation_n-D: '<S52>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_g;
      localfrac_m[0] = localSum1;
      localSum1 = localSwitch_i;
      localfrac_m[1] = localSum1;
      localbpIndex_m[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_m[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj3_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_m,
        localfrac_m, (&(InjSys_facAstCorInj3_M[0])), 8U);

      /* Lookup_n-D: '<S53>/Lookup Table (n-D)' */
      InjSys_facHotStrtCor_MP = look1_iu8lftu16n13If_binlcns
        (locallocalDataTypeConversion, (&(InjSys_tAir_facHotStrtCor_A[0])),
         (&(InjSys_facHotStrtCor_T[0])), 7U);

      /* Lookup_n-D: '<S54>/Lookup Table (n-D)' */
      InjSys_facAstTiEngStop_MP = look2_iu32u8lftu16n13If_binlcns
        (InjAstWupCmp_B.VEMS_vidGET28, locallocalDataTypeConversion_0,
         (&(InjSys_ti_facAstTiEngStopX_A[0])), (&(InjSys_tCo_facAstTiEngStopY_A
           [0])), (&(InjSys_facAstTiEngStop_M[0])),
         &InjAstWupCmp_ConstP.pooled4[0], 8U);

      /* Lookup_n-D: '<S55>/Lookup Table (n-D)' */
      InjSys_facAstStrtCorVVT_MP = look2_is8s8lftu16n13If_binlcns
        (locallocalOutDTConv_p, locallocalOutDTConv,
         (&(InjSys_agCk_facCorVVTX_A[0])), (&(InjSys_agCk_facCorVVTY_A[0])),
         (&(InjSys_facAstStrtCorVVT_M[0])), &InjAstWupCmp_ConstP.pooled5[0], 8U);

      /* MultiPortSwitch: '<S36>/Multiport Switch' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localSwitch_i = InjSys_facAstInj0_MP;
        break;

       case 1:
        localSwitch_i = InjSys_facAstInj1_MP;
        break;

       case 2:
        localSwitch_i = InjSys_facAstInj2_MP;
        break;

       default:
        localSwitch_i = InjSys_facAstInj3_MP;
        break;
      }

      /* MultiPortSwitch: '<S36>/Multiport Switch1' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localMultiportSwitch1_g = InjSys_facAstCorInj0_MP;
        break;

       case 1:
        localMultiportSwitch1_g = InjSys_facAstCorInj1_MP;
        break;

       case 2:
        localMultiportSwitch1_g = InjSys_facAstCorInj2_MP;
        break;

       default:
        localMultiportSwitch1_g = InjSys_facAstCorInj3_MP;
        break;
      }

      /* Product: '<S63>/Divide' */
      InjSys_facAstCorRaw1Strt_MP = localSwitch_i * localMultiportSwitch1_g;

      /* Product: '<S61>/Divide' */
      localSum1 = InjSys_facAstTWCHeatHi_MP * InjSys_facAstCorTWCHeatHi_MP;

      /* Product: '<S62>/Divide' */
      localAdd4 = InjSys_facAstTWCHeatLo_MP * InjSys_facAstCorTWCHeatLo_MP;

      /* MultiPortSwitch: '<S36>/Multiport Switch2' */
      switch (InjAstWupCmp_B.VEMS_vidGET49) {
       case 0:
        InjSys_facAstCorTWCHeat_MP = InjSys_facAstCorRaw1Strt_MP;
        break;

       case 1:
        InjSys_facAstCorTWCHeat_MP = localSum1;
        break;

       case 2:
        InjSys_facAstCorTWCHeat_MP = localAdd4;
        break;

       case 3:
        InjSys_facAstCorTWCHeat_MP = localAdd4;
        break;

       default:
        InjSys_facAstCorTWCHeat_MP = localSum1;
        break;
      }

      /* Switch: '<S36>/Switch' */
      if (InjAstWupCmp_B.VEMS_vidGET27) {
        localSwitch_i = InjSys_facAstCorTWCHeat_MP;
      } else {
        localSwitch_i = InjSys_facAstCorRaw1Strt_MP;
      }

      /* Product: '<S64>/Divide' */
      localSum1 = InjSys_facAstTiEngStop_MP * localSwitch_i;

      /* Product: '<S65>/Divide' */
      InjSys_facAstCorRaw2Strt_MP = localSum1 * localDataTypeConversion1_i;

      /* Sum: '<S36>/Sum' incorporates:
       *  Constant: '<S36>/Constant'
       *  Product: '<S60>/Divide'
       *  Product: '<S66>/Divide'
       */
      InjSys_facAstStrt = ((InjSys_facHotStrtCor_MP * InjSys_facAstStrtCorVVT_MP)
                           * InjSys_facAstCorRaw2Strt_MP) + 1.0F;
    }

    /* end of Outputs for SubSystem: '<S12>/F02_Ast_Nominal_Start' */

    /* Outputs for enable SubSystem: '<S12>/F03_Ast_STT' incorporates:
     *  Constant: '<S12>/InjSys_stAstSTT_SC'
     *  EnablePort: '<S37>/Enable'
     *  RelationalOperator: '<S12>/Relational Operator2'
     */
    if (InjSys_stAcvAst == InjSys_stAstSTT_SC) {
      /* DataTypeConversion: '<S37>/Data Type Conversion1' */
      localAdd4 = ((Float32)InjAstWupCmp_B.VEMS_vidGET42) * 0.0078125F;

      /* PreLookup: '<S78>/Prelookup' */
      localExt_nEng_InjSys_nEng_facWu = plook_u32u8f_binc
        (locallocalDataTypeConversion_0, (&(InjSys_tCo_facAstInjX_A[0])), 11U,
         &localMultiportSwitch1_m);

      /* PreLookup: '<S79>/Prelookup' */
      localExt_tCoMes_InjSys_tCo_f_en = plook_u32u16f_binc
        (InjAstWupCmp_B.Switch2, (&(InjSys_ct_facAstInjY_A[0])), 7U,
         &localMultiportSwitch_j);

      /* Interpolation_n-D: '<S67>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_m;
      localfrac_n[0] = localSum1;
      localSum1 = localMultiportSwitch_j;
      localfrac_n[1] = localSum1;
      localbpIndex_n[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_n[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj0STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_n,
        localfrac_n, (&(InjSys_facAstInj0STT_M[0])), 12U);

      /* Interpolation_n-D: '<S68>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_m;
      localfrac_o[0] = localSum1;
      localSum1 = localMultiportSwitch_j;
      localfrac_o[1] = localSum1;
      localbpIndex_o[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_o[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj1STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_o,
        localfrac_o, (&(InjSys_facAstInj1STT_M[0])), 12U);

      /* Interpolation_n-D: '<S69>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_m;
      localfrac_p[0] = localSum1;
      localSum1 = localMultiportSwitch_j;
      localfrac_p[1] = localSum1;
      localbpIndex_p[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_p[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj2STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_p,
        localfrac_p, (&(InjSys_facAstInj2STT_M[0])), 12U);

      /* Interpolation_n-D: '<S70>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1_m;
      localfrac_q[0] = localSum1;
      localSum1 = localMultiportSwitch_j;
      localfrac_q[1] = localSum1;
      localbpIndex_q[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_q[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj3STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_q,
        localfrac_q, (&(InjSys_facAstInj3STT_M[0])), 12U);

      /* PreLookup: '<S80>/Prelookup' */
      localExt_tCoMes_InjSys_tCo_f_en = plook_u32u16f_binc
        (InjAstWupCmp_B.VEMS_vidGET36, (&(InjSys_nEng_facAstCorInjX_A[0])), 7U,
         &localMultiportSwitch_j);

      /* PreLookup: '<S81>/Prelookup' */
      localExt_nEng_InjSys_nEng_facWu = plook_u32u16f_binc
        (EngM_mAirPred_InjAstWupCmp, (&(InjSys_mAir_facAstCorInjY_A[0])), 7U,
         &localMultiportSwitch1_m);

      /* Interpolation_n-D: '<S71>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch_j;
      localfrac_r[0] = localSum1;
      localSum1 = localMultiportSwitch1_m;
      localfrac_r[1] = localSum1;
      localbpIndex_r[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_r[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstCorInj0STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_r,
        localfrac_r, (&(InjSys_facAstCorInj0STT_M[0])), 8U);

      /* Interpolation_n-D: '<S72>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch_j;
      localfrac_s[0] = localSum1;
      localSum1 = localMultiportSwitch1_m;
      localfrac_s[1] = localSum1;
      localbpIndex_s[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_s[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstCorInj1STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_s,
        localfrac_s, (&(InjSys_facAstCorInj1STT_M[0])), 8U);

      /* Interpolation_n-D: '<S73>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch_j;
      localfrac_t[0] = localSum1;
      localSum1 = localMultiportSwitch1_m;
      localfrac_t[1] = localSum1;
      localbpIndex_t[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_t[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstCorInj2STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_t,
        localfrac_t, (&(InjSys_facAstCorInj2STT_M[0])), 8U);

      /* Interpolation_n-D: '<S74>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch_j;
      localfrac_u[0] = localSum1;
      localSum1 = localMultiportSwitch1_m;
      localfrac_u[1] = localSum1;
      localbpIndex_u[0] = localExt_tCoMes_InjSys_tCo_f_en;
      localbpIndex_u[1] = localExt_nEng_InjSys_nEng_facWu;
      InjSys_facAstCorInj3STT_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_u,
        localfrac_u, (&(InjSys_facAstCorInj3STT_M[0])), 8U);

      /* Lookup_n-D: '<S75>/Lookup Table (n-D)' */
      InjSys_facHotStrtCorSTT_MP = look1_iu8lftu16n13If_binlcns
        (locallocalDataTypeConversion, (&(InjSys_tAir_facHotStrtCor_A[0])),
         (&(InjSys_facHotStrtCorSTT_T[0])), 7U);

      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S37>/Constant1'
       */
      if (InjAstWupCmp_B.VEMS_vidGET25) {
        InjSys_tiEngStopRstSTT = 0U;
      } else {
        InjSys_tiEngStopRstSTT = InjAstWupCmp_B.VEMS_vidGET28;
      }

      /* Lookup_n-D: '<S76>/Lookup Table (n-D)' */
      InjSys_facAstTiEngStopSTT_MP = look2_iu32u8lftu16n13If_binlcns
        (InjSys_tiEngStopRstSTT, locallocalDataTypeConversion_0,
         (&(InjSys_ti_facAstTiEngStopX_A[0])), (&(InjSys_tCo_facAstTiEngStopY_A
           [0])), (&(InjSys_facAstTiEngStopSTT_M[0])),
         &InjAstWupCmp_ConstP.pooled4[0], 8U);

      /* Lookup_n-D: '<S77>/Lookup Table (n-D)' */
      InjSys_facAstSTTCorVVT_MP = look2_is8s8lftu16n13If_binlcns
        (locallocalOutDTConv_p, locallocalOutDTConv,
         (&(InjSys_agCk_facCorVVTX_A[0])), (&(InjSys_agCk_facCorVVTY_A[0])),
         (&(InjSys_facAstSTTCorVVT_M[0])), &InjAstWupCmp_ConstP.pooled5[0], 8U);

      /* MultiPortSwitch: '<S37>/Multiport Switch' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localMultiportSwitch_j = InjSys_facAstInj0STT_MP;
        break;

       case 1:
        localMultiportSwitch_j = InjSys_facAstInj1STT_MP;
        break;

       case 2:
        localMultiportSwitch_j = InjSys_facAstInj2STT_MP;
        break;

       default:
        localMultiportSwitch_j = InjSys_facAstInj3STT_MP;
        break;
      }

      /* MultiPortSwitch: '<S37>/Multiport Switch1' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localMultiportSwitch1_m = InjSys_facAstCorInj0STT_MP;
        break;

       case 1:
        localMultiportSwitch1_m = InjSys_facAstCorInj1STT_MP;
        break;

       case 2:
        localMultiportSwitch1_m = InjSys_facAstCorInj2STT_MP;
        break;

       default:
        localMultiportSwitch1_m = InjSys_facAstCorInj3STT_MP;
        break;
      }

      /* Product: '<S84>/Divide' */
      InjSys_facAstCorRaw1STT_MP = localMultiportSwitch_j *
        localMultiportSwitch1_m;

      /* Product: '<S86>/Divide' incorporates:
       *  Product: '<S85>/Divide'
       */
      InjSys_facAstCorRaw2STT_MP = (InjSys_facAstTiEngStopSTT_MP *
        InjSys_facAstCorRaw1STT_MP) * localAdd4;

      /* Sum: '<S37>/Sum' incorporates:
       *  Constant: '<S37>/Constant'
       *  Product: '<S82>/Divide'
       *  Product: '<S83>/Divide'
       */
      InjSys_facAstSTT = ((InjSys_facHotStrtCorSTT_MP *
                           InjSys_facAstSTTCorVVT_MP) *
                          InjSys_facAstCorRaw2STT_MP) + 1.0F;
    }

    /* end of Outputs for SubSystem: '<S12>/F03_Ast_STT' */

    /* Outputs for enable SubSystem: '<S12>/F04_Ast_Autonomous_Restart' incorporates:
     *  Constant: '<S12>/InjSys_stAstAutn_SC'
     *  EnablePort: '<S38>/Enable'
     *  RelationalOperator: '<S12>/Relational Operator1'
     */
    if (InjSys_stAcvAst == InjSys_stAstAutn_SC) {
      /* DataTypeConversion: '<S38>/Data Type Conversion1' */
      localAdd4 = ((Float32)InjAstWupCmp_B.VEMS_vidGET42) * 0.0078125F;

      /* PreLookup: '<S98>/Prelookup' */
      localExt_nEng_InjSys_nEng_facWu = plook_u32u8f_binc
        (locallocalDataTypeConversion_0, (&(InjSys_tCo_facAstInjX_A[0])), 11U,
         &localExt_tCoMes_InjSys_tCo_facA);

      /* PreLookup: '<S99>/Prelookup' */
      localExt_tCoMes_InjSys_tCo_f_en = plook_u32u16f_binc
        (InjAstWupCmp_B.Switch2, (&(InjSys_ct_facAstInjY_A[0])), 7U,
         &localInjSys_ctNbCmbAst_InjSys_c);

      /* Interpolation_n-D: '<S87>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_facA;
      localfrac_v[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_c;
      localfrac_v[1] = localSum1;
      localbpIndex_v[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_v[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj0Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_v,
        localfrac_v, (&(InjSys_facAstInj0Autn_M[0])), 12U);

      /* PreLookup: '<S100>/Prelookup' */
      localExt_nEng_InjSys_nEng_fac_n = plook_u32u16f_binc
        (InjAstWupCmp_B.VEMS_vidGET36, (&(InjSys_nEng_facAstCorInjX_A[0])), 7U,
         &localMultiportSwitch1);

      /* PreLookup: '<S101>/Prelookup' */
      localEngM_mAirPred_InjAstWupC_i = plook_u32u16f_binc
        (EngM_mAirPred_InjAstWupCmp, (&(InjSys_mAir_facAstCorInjY_A[0])), 7U,
         &localMultiportSwitch);

      /* Interpolation_n-D: '<S88>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1;
      localfrac_w[0] = localSum1;
      localSum1 = localMultiportSwitch;
      localfrac_w[1] = localSum1;
      localbpIndex_w[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_w[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj0Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_w,
        localfrac_w, (&(InjSys_facAstCorInj0Autn_M[0])), 8U);

      /* Interpolation_n-D: '<S89>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_facA;
      localfrac_x[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_c;
      localfrac_x[1] = localSum1;
      localbpIndex_x[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_x[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj3Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_x,
        localfrac_x, (&(InjSys_facAstInj3Autn_M[0])), 12U);

      /* Interpolation_n-D: '<S90>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1;
      localfrac_y[0] = localSum1;
      localSum1 = localMultiportSwitch;
      localfrac_y[1] = localSum1;
      localbpIndex_y[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_y[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj1Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_y,
        localfrac_y, (&(InjSys_facAstCorInj1Autn_M[0])), 8U);

      /* Interpolation_n-D: '<S91>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1;
      localfrac_z[0] = localSum1;
      localSum1 = localMultiportSwitch;
      localfrac_z[1] = localSum1;
      localbpIndex_z[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_z[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj2Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_z,
        localfrac_z, (&(InjSys_facAstCorInj2Autn_M[0])), 8U);

      /* Interpolation_n-D: '<S92>/Interpolation Using Prelookup3' */
      localSum1 = localMultiportSwitch1;
      localfrac_10[0] = localSum1;
      localSum1 = localMultiportSwitch;
      localfrac_10[1] = localSum1;
      localbpIndex_10[0] = localExt_nEng_InjSys_nEng_fac_n;
      localbpIndex_10[1] = localEngM_mAirPred_InjAstWupC_i;
      InjSys_facAstCorInj3Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_10,
        localfrac_10, (&(InjSys_facAstCorInj3Autn_M[0])), 8U);

      /* Interpolation_n-D: '<S93>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_facA;
      localfrac_11[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_c;
      localfrac_11[1] = localSum1;
      localbpIndex_11[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_11[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj1Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_11,
        localfrac_11, (&(InjSys_facAstInj1Autn_M[0])), 12U);

      /* Interpolation_n-D: '<S94>/Interpolation Using Prelookup3' */
      localSum1 = localExt_tCoMes_InjSys_tCo_facA;
      localfrac_12[0] = localSum1;
      localSum1 = localInjSys_ctNbCmbAst_InjSys_c;
      localfrac_12[1] = localSum1;
      localbpIndex_12[0] = localExt_nEng_InjSys_nEng_facWu;
      localbpIndex_12[1] = localExt_tCoMes_InjSys_tCo_f_en;
      InjSys_facAstInj2Autn_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_12,
        localfrac_12, (&(InjSys_facAstInj2Autn_M[0])), 12U);

      /* Lookup_n-D: '<S95>/Lookup Table (n-D)' */
      InjSys_facHotStrtCorAutn_MP = look1_iu8lftu16n13If_binlcns
        (locallocalDataTypeConversion, (&(InjSys_tAir_facHotStrtCor_A[0])),
         (&(InjSys_facHotStrtCorAutn_T[0])), 7U);

      /* Lookup_n-D: '<S96>/Lookup Table (n-D)' */
      InjSys_facAstTiStopAutn_MP = look2_iu32u8lftu16n13If_binlcns
        (InjAstWupCmp_B.VEMS_vidGET28, locallocalDataTypeConversion_0,
         (&(InjSys_ti_facAstTiEngStopX_A[0])), (&(InjSys_tCo_facAstTiEngStopY_A
           [0])), (&(InjSys_facAstTiEngStopAutn_M[0])),
         &InjAstWupCmp_ConstP.pooled4[0], 8U);

      /* Lookup_n-D: '<S97>/Lookup Table (n-D)' */
      InjSys_facAstAutnCorVVT_MP = look2_is8s8lftu16n13If_binlcns
        (locallocalOutDTConv_p, locallocalOutDTConv,
         (&(InjSys_agCk_facCorVVTX_A[0])), (&(InjSys_agCk_facCorVVTY_A[0])),
         (&(InjSys_facAstAutnCorVVT_M[0])), &InjAstWupCmp_ConstP.pooled5[0], 8U);

      /* MultiPortSwitch: '<S38>/Multiport Switch' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localMultiportSwitch = InjSys_facAstInj0Autn_MP;
        break;

       case 1:
        localMultiportSwitch = InjSys_facAstInj1Autn_MP;
        break;

       case 2:
        localMultiportSwitch = InjSys_facAstInj2Autn_MP;
        break;

       default:
        localMultiportSwitch = InjSys_facAstInj3Autn_MP;
        break;
      }

      /* MultiPortSwitch: '<S38>/Multiport Switch1' */
      switch (InjAstWupCmp_B.VEMS_vidGET48) {
       case 0:
        localMultiportSwitch1 = InjSys_facAstCorInj0Autn_MP;
        break;

       case 1:
        localMultiportSwitch1 = InjSys_facAstCorInj1Autn_MP;
        break;

       case 2:
        localMultiportSwitch1 = InjSys_facAstCorInj2Autn_MP;
        break;

       default:
        localMultiportSwitch1 = InjSys_facAstCorInj3Autn_MP;
        break;
      }

      /* Product: '<S106>/Divide' */
      InjSys_facAstCorRaw1Autn_MP = localMultiportSwitch * localMultiportSwitch1;

      /* Product: '<S104>/Divide' incorporates:
       *  Product: '<S105>/Divide'
       */
      InjSys_facAstCorRaw2Autn_MP = (InjSys_facAstTiStopAutn_MP *
        InjSys_facAstCorRaw1Autn_MP) * localAdd4;

      /* Sum: '<S38>/Sum' incorporates:
       *  Constant: '<S38>/Constant'
       *  Product: '<S102>/Divide'
       *  Product: '<S103>/Divide'
       */
      InjSys_facAstAutn = ((InjSys_facHotStrtCorAutn_MP *
                            InjSys_facAstAutnCorVVT_MP) *
                           InjSys_facAstCorRaw2Autn_MP) + 1.0F;
    }

    /* end of Outputs for SubSystem: '<S12>/F04_Ast_Autonomous_Restart' */

    /* MultiPortSwitch: '<S39>/Multiport Switch' incorporates:
     *  Constant: '<S39>/Constant'
     */
    switch (InjSys_stAcvAst) {
     case 0:
      InjSys_facAst = 1.0F;
      break;

     case 1:
      InjSys_facAst = InjSys_facAstStrt;
      break;

     case 2:
      InjSys_facAst = InjSys_facAstSTT;
      break;

     default:
      InjSys_facAst = InjSys_facAstAutn;
      break;
    }

    /* end of Outputs for SubSystem: '<S8>/F03_After_start' */
    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET43 */
    VEMS_vidGET(FISA_facWupAdp, InjAstWupCmp_B.VEMS_vidGET43);

    /* DataTypeConversion: '<S13>/Data Type Conversion1' */
    localDataTypeConversion1_i = ((Float32)InjAstWupCmp_B.VEMS_vidGET43) *
      0.0078125F;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET40 */
    VEMS_vidGET(Ext_tCoStrtMes, InjAstWupCmp_B.VEMS_vidGET40);

    /* DataTypeConversion: '<S13>/Data Type Conversion13' */
    locali = InjAstWupCmp_B.VEMS_vidGET40 + 40;
    if (locali <= 0) {
      locallocalDataTypeConversion_1 = 0U;
    } else if (locali > 255) {
      locallocalDataTypeConversion_1 = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion_1 = (UInt8)locali;
    }

    /* PreLookup: '<S123>/Prelookup' */
    localExt_nEng_InjSys_nEng_facWu = plook_u32u16f_binc
      (InjAstWupCmp_B.VEMS_vidGET36, (&(InjSys_nEng_facWupCorInjX_A[0])), 7U,
       &localSwitch_p);

    /* PreLookup: '<S124>/Prelookup' */
    localExt_tCoMes_InjSys_tCo_f_en = plook_u32u16f_binc
      (EngM_mAirPred_InjAstWupCmp, (&(InjSys_mAir_facWupCorInjY_A[0])), 7U,
       &localEngM_mAirPred_InjAstWupCmp);

    /* Interpolation_n-D: '<S107>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac[1] = localSum1;
    localbpIndex[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorInj0_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex,
      localfrac, (&(InjSys_facWupCorInj0_M[0])), 8U);

    /* PreLookup: '<S121>/Prelookup' */
    localExt_nEng_InjSys_nEng_fac_n = plook_u32u8f_binc
      (locallocalDataTypeConversion_0, (&(InjSys_tCo_facWupInjX_A[0])), 11U,
       &localExt_tCoMes_InjSys_tCo_facW);

    /* PreLookup: '<S122>/Prelookup' */
    localEngM_mAirPred_InjAstWupC_i = plook_u32u8f_binc
      (locallocalDataTypeConversion_1, (&(InjSys_tCo_facWupInjY_A[0])), 7U,
       &localSwitch2);

    /* Interpolation_n-D: '<S108>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_0[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_0[1] = localSum1;
    localbpIndex_0[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_0[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupInj0_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_0,
      localfrac_0, (&(InjSys_facWupInj0_M[0])), 12U);

    /* Interpolation_n-D: '<S109>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_1[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_1[1] = localSum1;
    localbpIndex_1[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_1[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupInj1_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_1,
      localfrac_1, (&(InjSys_facWupInj1_M[0])), 12U);

    /* Interpolation_n-D: '<S110>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_2[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_2[1] = localSum1;
    localbpIndex_2[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_2[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupInj2_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_2,
      localfrac_2, (&(InjSys_facWupInj2_M[0])), 12U);

    /* Interpolation_n-D: '<S111>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_3[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_3[1] = localSum1;
    localbpIndex_3[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_3[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupInj3_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_3,
      localfrac_3, (&(InjSys_facWupInj3_M[0])), 12U);

    /* Interpolation_n-D: '<S112>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac_4[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac_4[1] = localSum1;
    localbpIndex_4[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex_4[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorInj3_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_4,
      localfrac_4, (&(InjSys_facWupCorInj3_M[0])), 8U);

    /* Interpolation_n-D: '<S113>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac_5[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac_5[1] = localSum1;
    localbpIndex_5[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex_5[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorInj1_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_5,
      localfrac_5, (&(InjSys_facWupCorInj1_M[0])), 8U);

    /* Interpolation_n-D: '<S114>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac_6[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac_6[1] = localSum1;
    localbpIndex_6[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex_6[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorInj2_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_6,
      localfrac_6, (&(InjSys_facWupCorInj2_M[0])), 8U);

    /* Interpolation_n-D: '<S115>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac_7[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac_7[1] = localSum1;
    localbpIndex_7[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex_7[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorTWCHeatHi_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_7,
      localfrac_7, (&(InjSys_facWupCorTWCHeatHi_M[0])), 8U);

    /* Interpolation_n-D: '<S116>/Interpolation Using Prelookup3' */
    localSum1 = localSwitch_p;
    localfrac_8[0] = localSum1;
    localSum1 = localEngM_mAirPred_InjAstWupCmp;
    localfrac_8[1] = localSum1;
    localbpIndex_8[0] = localExt_nEng_InjSys_nEng_facWu;
    localbpIndex_8[1] = localExt_tCoMes_InjSys_tCo_f_en;
    InjSys_facWupCorTWCHeatLo_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_8,
      localfrac_8, (&(InjSys_facWupCorTWCHeatLo_M[0])), 8U);

    /* Interpolation_n-D: '<S117>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_9[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_9[1] = localSum1;
    localbpIndex_9[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_9[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupTWCHeatHi_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_9,
      localfrac_9, (&(InjSys_facWupTWCHeatHi_M[0])), 12U);

    /* Interpolation_n-D: '<S118>/Interpolation Using Prelookup3' */
    localSum1 = localExt_tCoMes_InjSys_tCo_facW;
    localfrac_a[0] = localSum1;
    localSum1 = localSwitch2;
    localfrac_a[1] = localSum1;
    localbpIndex_a[0] = localExt_nEng_InjSys_nEng_fac_n;
    localbpIndex_a[1] = localEngM_mAirPred_InjAstWupC_i;
    InjSys_facWupTWCHeatLo_MP = intrp2d_iu16n13ff_u32f_l_ns(localbpIndex_a,
      localfrac_a, (&(InjSys_facWupTWCHeatLo_M[0])), 12U);

    /* Lookup_n-D: '<S119>/Lookup Table (n-D)' */
    InjSys_facWupCorAirT_MP = look1_iu8lftu16n13If_binlcns
      (locallocalDataTypeConversion, (&(InjSys_tAir_facWupCorAirT_A[0])),
       (&(InjSys_facWupCorAirT_T[0])), 7U);

    /* Lookup_n-D: '<S120>/Lookup Table (n-D)' */
    InjSys_facWupCorVVT_MP = look2_is8s8lftu16n13If_binlcns
      (locallocalOutDTConv_p, locallocalOutDTConv, (&(InjSys_agCk_facCorVVTX_A[0])),
       (&(InjSys_agCk_facCorVVTY_A[0])), (&(InjSys_facWupCorVVT_M[0])),
       &InjAstWupCmp_ConstP.pooled5[0], 8U);

    /* MultiPortSwitch: '<S13>/Multiport Switch' */
    switch (InjAstWupCmp_B.VEMS_vidGET48) {
     case 0:
      localSwitch2 = InjSys_facWupInj0_MP;
      break;

     case 1:
      localSwitch2 = InjSys_facWupInj1_MP;
      break;

     case 2:
      localSwitch2 = InjSys_facWupInj2_MP;
      break;

     default:
      localSwitch2 = InjSys_facWupInj3_MP;
      break;
    }

    /* MultiPortSwitch: '<S13>/Multiport Switch1' */
    switch (InjAstWupCmp_B.VEMS_vidGET48) {
     case 0:
      localSwitch_p = InjSys_facWupCorInj0_MP;
      break;

     case 1:
      localSwitch_p = InjSys_facWupCorInj1_MP;
      break;

     case 2:
      localSwitch_p = InjSys_facWupCorInj2_MP;
      break;

     default:
      localSwitch_p = InjSys_facWupCorInj3_MP;
      break;
    }

    /* Product: '<S128>/Divide' */
    InjSys_facWupCorRaw_MP = localSwitch2 * localSwitch_p;

    /* Product: '<S125>/Divide' */
    localSum1 = InjSys_facWupTWCHeatHi_MP * InjSys_facWupCorTWCHeatHi_MP;

    /* Product: '<S126>/Divide' */
    localAdd4 = InjSys_facWupTWCHeatLo_MP * InjSys_facWupCorTWCHeatLo_MP;

    /* MultiPortSwitch: '<S13>/Multiport Switch2' */
    switch (InjAstWupCmp_B.VEMS_vidGET49) {
     case 0:
      InjSys_facWupCorTWCHeat_MP = InjSys_facWupCorRaw_MP;
      break;

     case 1:
      InjSys_facWupCorTWCHeat_MP = localSum1;
      break;

     case 2:
      InjSys_facWupCorTWCHeat_MP = localAdd4;
      break;

     case 3:
      InjSys_facWupCorTWCHeat_MP = localAdd4;
      break;

     default:
      InjSys_facWupCorTWCHeat_MP = localSum1;
      break;
    }

    /* Switch: '<S13>/Switch' */
    if (InjAstWupCmp_B.VEMS_vidGET27) {
      localSwitch2 = InjSys_facWupCorTWCHeat_MP;
    } else {
      localSwitch2 = InjSys_facWupCorRaw_MP;
    }

    /* Product: '<S127>/Divide' incorporates:
     *  Product: '<S130>/Divide'
     */
    localSum1 = (InjSys_facWupCorAirT_MP * InjSys_facWupCorVVT_MP) *
      localSwitch2;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     *  Product: '<S129>/Divide'
     */
    InjSys_facWup = (localSum1 * localDataTypeConversion1_i) + 1.0F;

    /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
     *  Constant: '<S14>/InjSys_tiTauDeacStrtCor_C'
     */
    localSum1 = ((Float32)InjSys_tiTauDeacStrtCor_C) * 0.01171875F;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET41 */
    VEMS_vidGET(Ext_tiTDC, InjAstWupCmp_B.VEMS_vidGET41);

    /* DataTypeConversion: '<S14>/Data Type Conversion2' */
    localSwitch2 = ((Float32)InjAstWupCmp_B.VEMS_vidGET41) * 1.000000047E-003F;

    /* Sum: '<S131>/Sum3' */
    localSum1 += localSwitch2;

    /* Product: '<S135>/Divide' */
    localSum1 = localSwitch2 / localSum1;

    /* UnitDelay: '<S138>/Unit Delay' */
    localSwitch2 = InjAstWupCmp_DWork.UnitDelay_DSTATE;

    /* MinMax: '<S14>/MinMax' */
    localSwitch_p = rt_MAXf(InjSys_facAst, InjSys_facWup);

    /* Switch: '<S134>/Switch' incorporates:
     *  UnitDelay: '<S139>/Unit Delay'
     */
    if (!InjAstWupCmp_DWork.UnitDelay_DSTATE_b) {
      localSwitch2 = localSwitch_p;
    }

    /* Sum: '<S131>/Sum2' incorporates:
     *  Constant: '<S14>/Constant'
     */
    localAdd4 = localSwitch2 - 1.0F;

    /* Sum: '<S131>/Sum1' incorporates:
     *  Product: '<S136>/Divide'
     */
    localDataTypeConversion1_i = localSwitch2 - (localSum1 * localAdd4);

    /* Logic: '<S14>/Logical Operator' incorporates:
     *  Inport: '<Root>/FRM_bInhTCoInjStrtCor'
     *  Logic: '<S14>/Logical Operator2'
     */
    localLogicalOperator = (InjAstWupCmp_B.LogicalOperator2 && (!GDGAR_bGetFRM
      (FRM_FRM_INHTCOINJSTRTCOR)));

    /* Switch: '<S131>/Switch' incorporates:
     *  Logic: '<S131>/Logical Operator'
     *  Logic: '<S132>/Logical Operator'
     *  Logic: '<S132>/Logical Operator1'
     *  UnitDelay: '<S140>/Unit Delay'
     */
    if ((!localLogicalOperator) && InjAstWupCmp_DWork.UnitDelay_DSTATE_o) {
      localDataTypeConversion1_i = localSwitch_p;
    }

    /* Switch: '<S133>/Switch' incorporates:
     *  UnitDelay: '<S137>/Unit Delay'
     */
    if (InjAstWupCmp_DWork.UnitDelay_DSTATE_a) {
      localSwitch2 = localDataTypeConversion1_i;
    } else {
      localSwitch2 = localSwitch_p;
    }

    /* Switch: '<S14>/Switch' */
    if (!localLogicalOperator) {
      localSwitch_p = localSwitch2;
    }

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S14>/InjSys_bAcvInjAstWupCmp_C'
     */
    if (InjSys_bAcvInjAstWupCmp_C) {
      InjSys_facStrtCorGsl = localSwitch_p;
    } else {
      InjSys_facStrtCorGsl = 1.0F;
    }

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET45 */
    VEMS_vidGET(InjSys_facAstWupCmpAdpFlex, InjAstWupCmp_B.VEMS_vidGET45);

    /* DataTypeConversion: '<S15>/Data Type Conversion3' */
    localSwitch2 = ((Float32)InjAstWupCmp_B.VEMS_vidGET45) * 3.051757813E-005F;

    /* RelationalOperator: '<S151>/LowerRelop1' incorporates:
     *  Constant: '<S141>/Constant'
     */
    localLowerRelop1_e = (localSwitch2 > 1.0F);

    /* RelationalOperator: '<S151>/UpperRelop' incorporates:
     *  Constant: '<S141>/Constant1'
     */
    localUpperRelop_o = (localSwitch2 < 0.0F);

    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S141>/Constant1'
     */
    if (localUpperRelop_o) {
      localSwitch2 = 0.0F;
    }

    /* Switch: '<S151>/Switch2' incorporates:
     *  Constant: '<S141>/Constant'
     */
    if (localLowerRelop1_e) {
      localSwitch2 = 1.0F;
    }

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET46 */
    VEMS_vidGET(InjSys_facStrtCorFlex, InjAstWupCmp_B.VEMS_vidGET46);

    /* Product: '<S141>/Divide' incorporates:
     *  DataTypeConversion: '<S15>/Data Type Conversion2'
     *  Sum: '<S141>/Sum3'
     */
    localSum1 = ((((Float32)InjAstWupCmp_B.VEMS_vidGET46) * 2.288818359E-004F)
                 - InjSys_facStrtCorGsl) * localSwitch2;

    /* Sum: '<S141>/Sum2' */
    localSum1 += InjSys_facStrtCorGsl;

    /* DataTypeConversion: '<S15>/DTConv_UFix_To_Single_1' */
    localEngM_mAirPred_InjAstWupC_i = InjAstWupCmp_B.VEMS_vidGET34;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET47 */
    VEMS_vidGET(InjSys_facStrtCorGas, InjAstWupCmp_B.VEMS_vidGET47);

    /* DataTypeConversion: '<S15>/Data Type Conversion1' */
    localAdd4 = ((Float32)InjAstWupCmp_B.VEMS_vidGET47) * 2.288818359E-004F;

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET44 */
    VEMS_vidGET(IgSys_tDifTAirUsInVlvEstim, InjAstWupCmp_B.VEMS_vidGET44);

    /* DataTypeDuplicate Block: '<S143>/Data Type Duplicate2'
     *
     * Regarding '<S143>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup_n-D: '<S142>/Lookup Table (n-D)' */
    InjSys_facCorRichTAir_MP = look1_is16lftu16n13If_binlcns
      (InjAstWupCmp_B.VEMS_vidGET44, (&(InjSys_tDifCorNTAirY_A[0])),
       (&(InjSys_facCorRichTAir_T[0])), 8U);

    /* Lookup_n-D: '<S143>/Lookup Table (n-D)' */
    InjSys_facCorRichNTAir_MP = look2_1fc22bc2bcvbfbbr64fbbnx
      (InjAstWupCmp_B.VEMS_vidGET36, InjAstWupCmp_B.VEMS_vidGET44,
       (&(InjSys_nCorRichX_A[0])), (&(InjSys_tDifCorNTAirY_A[0])),
       (&(InjSys_facCorRichNTAir_M[0])),
       &InjAstWupCmp_ConstP.LookupTablenD_maxInde[0], 18U);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET32 */
    VEMS_vidGET(EngM_rAirLdCor, InjAstWupCmp_B.VEMS_vidGET32);

    /* DataTypeDuplicate Block: '<S144>/Data Type Duplicate2'
     *
     * Regarding '<S144>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup_n-D: '<S144>/Lookup Table (n-D)' */
    InjSys_facCorRichNAirLd_MP = look2_1fcv2bcvbcvbfbbr64fbbnx
      (InjAstWupCmp_B.VEMS_vidGET36, InjAstWupCmp_B.VEMS_vidGET32,
       (&(InjSys_nCorRichX_A[0])), (&(InjSys_rCorRichNAirLdY_A[0])),
       (&(InjSys_facCorRichNAirLd_M[0])),
       &InjAstWupCmp_ConstP.LookupTablenD_maxIn_k[0], 18U);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET37 */
    VEMS_vidGET1DArray(Ext_prm_idxFuTypCyl, 6, InjAstWupCmp_B.VEMS_vidGET37);

    /* DataTypeDuplicate Block: '<S145>/Data Type Duplicate'
     *
     * Regarding '<S145>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Sum: '<S145>/Add' incorporates:
     *  Constant: '<S145>/Constant1'
     */
    localEngM_mAirPred_InjAstWupC_i--;

    /* MultiPortSwitch: '<S15>/Multiport Switch' incorporates:
     *  Constant: '<S145>/Constant'
     *  MinMax: '<S145>/MinMax'
     *  Selector: '<S145>/Selector'
     */
    switch (InjAstWupCmp_B.VEMS_vidGET37[rt_MIN(localEngM_mAirPred_InjAstWupC_i,
             5U)]) {
     case 0:
      InjSys_facStrtCorRaw_MP = InjSys_facStrtCorGsl;
      break;

     case 1:
      InjSys_facStrtCorRaw_MP = localAdd4;
      break;

     default:
      InjSys_facStrtCorRaw_MP = localSum1;
      break;
    }

    /* Sum: '<S15>/Sum2' incorporates:
     *  Constant: '<S15>/Constant'
     *  Product: '<S147>/Divide'
     *  Sum: '<S15>/Sum1'
     */
    InjSys_facCorRichCold_MP = ((InjSys_facCorRichNAirLd_MP *
      InjSys_facCorRichTAir_MP) + InjSys_facCorRichNTAir_MP) + 1.0F;

    /* Product: '<S146>/Divide' */
    InjSys_facStrtCor = InjSys_facStrtCorRaw_MP * InjSys_facCorRichCold_MP;

    /* Assignment: '<S16>/Assignment1' incorporates:
     *  UnitDelay: '<S153>/Unit Delay'
     */
    for (locali = 0; locali < 6; locali++) {
      localAssignment1[locali] = InjAstWupCmp_DWork.UnitDelay_DSTATE_k[(locali)];
    }

    localAssignment1[InjAstWupCmp_B.VEMS_vidGET34 - 1] = InjSys_facStrtCor;

    /* DataTypeConversion: '<S152>/OutDTConv' incorporates:
     *  Constant: '<S152>/offset'
     *  Constant: '<S152>/offset1'
     *  Constant: '<S152>/one_on_slope'
     *  Product: '<S152>/Product4'
     *  Sum: '<S152>/Add1'
     *  Sum: '<S152>/Add2'
     */
    for (locali = 0; locali < 6; locali++) {
      localSum1 = (4096.0F * localAssignment1[locali]) + 0.5F;
      if (localSum1 < 65536.0F) {
        if (localSum1 >= 0.0F) {
          localSwitch2_g = (UInt16)localSum1;
        } else {
          localSwitch2_g = 0U;
        }
      } else {
        localSwitch2_g = MAX_uint16_T;
      }

      InjAstWupCmp_B.OutDTConv[(locali)] = localSwitch2_g;
    }

    /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_bAcvStrtCor, InjAstWupCmp_B.LogicalOperator2);

    /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET4 */
    VEMS_vidSET(InjSys_ctNbCmbAst, InjAstWupCmp_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(InjSys_prm_facStrtCorCyl, 6, InjAstWupCmp_B.OutDTConv);

    /* Update for UnitDelay: '<S31>/Unit Delay' */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_m = InjAstWupCmp_B.VEMS_vidGET35_b;

    /* Update for UnitDelay: '<S19>/Unit Delay' */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_ij = InjAstWupCmp_B.VEMS_vidGET25;

    /* Update for UnitDelay: '<S24>/UnitDelay' */
    InjAstWupCmp_DWork.UnitDelay = localLogicalOperator4;

    /* Update for UnitDelay: '<S23>/Unit Delay' */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_i = InjAstWupCmp_B.Switch2;

    /* Update for UnitDelay: '<S137>/Unit Delay' incorporates:
     *  Constant: '<S133>/Constant3'
     */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_a = TRUE;

    /* Update for UnitDelay: '<S138>/Unit Delay' */
    InjAstWupCmp_DWork.UnitDelay_DSTATE = localDataTypeConversion1_i;

    /* Update for UnitDelay: '<S139>/Unit Delay' incorporates:
     *  Constant: '<S134>/Constant3'
     */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_b = TRUE;

    /* Update for UnitDelay: '<S140>/Unit Delay' */
    InjAstWupCmp_DWork.UnitDelay_DSTATE_o = localLogicalOperator;

    /* Update for UnitDelay: '<S153>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      InjAstWupCmp_DWork.UnitDelay_DSTATE_k[(locali)] = localAssignment1[locali];
    }
  }

  /* end of Outputs for SubSystem: '<S6>/F00_InjAstWupCmp' */
}

/* Start for exported function: InjSys_EveInj_InjAstWupCmp */
void InjSys_EveInj_InjAstWupCmp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_InjAstWupCmp'
   */
  InjAstWu_F02_InjAstWupCmp_Start();
}

/* Output and update for exported function: InjSys_EveInj_InjAstWupCmp */
void InjSys_EveInj_InjAstWupCmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  InjAstWupCmp_ASYNC2(0);
}

/* Output and update for function-call system: '<S1>/F03_EventDetection' */
void InjAstWupCmp_F03_EventDetection(void)
{
  /* Outputs for enable SubSystem: '<S7>/F03_EventDetection' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/INJASTWUPCMP_u8Inhib'
   *  EnablePort: '<S154>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (INJASTWUPCMP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S154>/VEMS_vidGET35 */
    VEMS_vidGET(Ext_bAcvInjSys, InjAstWupCmp_B.VEMS_vidGET35);

    /* Outputs for trigger SubSystem: '<S154>/00_Detection' incorporates:
     *  TriggerPort: '<S155>/Trigger'
     */
    if (InjAstWupCmp_B.VEMS_vidGET35 &&
        (InjAstWupCmp_PrevZCSigState.u_Detection_Trig_ZCE != POS_ZCSIG)) {
      /* S-Function (fcncallgen): '<S155>/Function-Call Generator' */
      InjAstWupCmp_ASYNC2(1);
    }

    InjAstWupCmp_PrevZCSigState.u_Detection_Trig_ZCE = (UInt8)
      (InjAstWupCmp_B.VEMS_vidGET35 ? ((SInt32)POS_ZCSIG) : ((SInt32)
        ZERO_ZCSIG));

    /* end of Outputs for SubSystem: '<S154>/00_Detection' */
  }

  /* end of Outputs for SubSystem: '<S7>/F03_EventDetection' */
}

/* Output and update for exported function: InjSys_SdlFast_InjAstWupCmp */
void InjSys_SdlFast_InjAstWupCmp(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_EventDetection'
   */
  InjAstWupCmp_F03_EventDetection();
}

/* Model initialize function */
void InjAstWupCmp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  InjSys_EveInj_InjAstWupCmp_Start();
  InjAstWupCmp_PrevZCSigState.u_Detection_Trig_ZCE = POS_ZCSIG;
}

#define INJASTWUPCMP_STOP_SEC_CODE
#include "InjAstWupCmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
