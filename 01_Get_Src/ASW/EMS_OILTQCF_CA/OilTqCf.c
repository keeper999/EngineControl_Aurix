/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : OilTqCf                                                 */
/* !Description     : OIL TORQUE CONFIGURATION                                */
/*                                                                            */
/* !Module          : OilTqCf                                                 */
/*                                                                            */
/* !File            : OilTqCf.c                                               */
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
/* !Reference       : V02NT1107584 / 02                                       */
/* !OtherRefs       : 01460_11_03533 / 2.0                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Sun Oct 21 15:29:22 2012                              */
/*   Model name       : OilTqCf_AUTOCODE.mdl                                  */
/*   Model version    : 1.64                                                  */
/*   Root subsystem   : /OilTqCf                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/OILTQCF_CA/OilTqC$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   12 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "OilTqCf.h"
#include "OilTqCf_private.h"

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
#define OILTQCF_START_SEC_VAR_UNSPECIFIED
#include "OilTqCf_MemMap.h"

/* Block signals (auto storage) */
BlockIO_OilTqCf OilTqCf_B;

/* Block states (auto storage) */
D_Work_OilTqCf OilTqCf_DWork;

#define OILTQCF_STOP_SEC_VAR_UNSPECIFIED
#include "OilTqCf_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define OILTQCF_START_SEC_CODE
#include "OilTqCf_MemMap.h"

void OilTqCf_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F00_OilTqCf_Init' */
void OilTqCf_F00_OilTqCf_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(OilTqCf_facNum, 0);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(OilTqCf_facDen, 16);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(OilTqCf_bPresOilReqCf, FALSE);
}

/* Output and update for exported function: OilTqCf_EveRst_OilTqCf */
void OilTqCf_EveRst_OilTqCf(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_OilTqCf_Init'
   */
  OilTqCf_F00_OilTqCf_Init();
}

/*
 * Output and update for atomic system:
 *    '<S6>/Mem'
 *    '<S6>/Mem1'
 */
void OilTqCf_Mem(Boolean rtu_Hld, SInt16 rtu_In, rtB_Mem_OilTqCf *localB,
                 rtDW_Mem_OilTqCf *localDW)
{
  /* Switch: '<S10>/Switch1' incorporates:
   *  UnitDelay: '<S16>/Unit Delay'
   */
  if (rtu_Hld) {
    localB->Switch1 = localDW->UnitDelay_DSTATE;
  } else {
    localB->Switch1 = rtu_In;
  }

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Switch1;
}

/* Start for function-call system: '<S1>/F0_OilTqCf' */
void OilTqCf_F0_OilTqCf_Start(void)
{
  /* Start for enable SubSystem: '<S5>/F01_OilTqCf'
   * Block description for '<S5>/F01_OilTqCf':
   *  01460_11_03533.2.1
   */

  /* InitializeConditions for atomic SubSystem: '<S6>/HysPos1' */

  /* InitializeConditions for UnitDelay: '<S15>/UnitDelay' */
  OilTqCf_DWork.UnitDelay = TRUE;

  /* end of InitializeConditions for SubSystem: '<S6>/HysPos1' */

  /* InitializeConditions for Memory: '<S23>/Memory' */
  OilTqCf_DWork.Memory_PreviousInput = TRUE;

  /* end of Start for SubSystem: '<S5>/F01_OilTqCf' */
}

/*
 * Output and update for function-call system: '<S1>/F0_OilTqCf'
 * Block description for: '<S1>/F0_OilTqCf'
 *   01460_11_03533.1.1
 */
void OilTqCf_F0_OilTqCf(void)
{
  /* local block i/o variables */
  Boolean localLogic[2];
  Boolean localLogicalOperator3;
  Boolean localR;
  Boolean localMemory;
  Boolean localRelationalOperator4;
  Boolean localSwitch_f;
  Boolean localLogic_l[2];
  Boolean localUnitDelay1;
  Float32 localSwitch2;
  Float32 localSwitch;
  Float32 localmax;
  Boolean localRelationalOperator2;
  Boolean localLowerRelop1;
  Boolean localRelationalOperator1_i;
  SInt32 localtmp;
  SInt16 locallocalAdd;

  /* Outputs for enable SubSystem: '<S5>/F01_OilTqCf' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/OILTQCF_u8Inhib'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   *
   * Block description for '<S5>/F01_OilTqCf':
   *  01460_11_03533.2.1
   */
  if (OILTQCF_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET(TqCmp_tqSumLossCmp, OilTqCf_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET(TqSys_tqCkEngReal, OilTqCf_B.VEMS_vidGET7);

    /* Sum: '<S6>/Add' */
    localtmp = OilTqCf_B.VEMS_vidGET6 + OilTqCf_B.VEMS_vidGET7;
    if (localtmp > 32767) {
      locallocalAdd = MAX_int16_T;
    } else if (localtmp <= -32768) {
      locallocalAdd = MIN_int16_T;
    } else {
      locallocalAdd = (SInt16)localtmp;
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(EngLim_tqIdcLim, OilTqCf_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(EngLim_tqIdcFLdLim, OilTqCf_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(EngLim_tqIdcLdMaxTrbMax, OilTqCf_B.VEMS_vidGET2);

    /* MultiPortSwitch: '<S6>/Multiport Switch1' incorporates:
     *  Constant: '<S6>/OilTqCf_facDen_C'
     *  Constant: '<S6>/OilTqCf_stPrmDen_C'
     */
    switch (OilTqCf_stPrmDen_C) {
     case 0:
      OilTqCf_facDen_MP = OilTqCf_B.VEMS_vidGET3;
      break;

     case 1:
      OilTqCf_facDen_MP = OilTqCf_B.VEMS_vidGET1;
      break;

     case 2:
      OilTqCf_facDen_MP = OilTqCf_B.VEMS_vidGET2;
      break;

     default:
      OilTqCf_facDen_MP = OilTqCf_facDen_C;
      break;
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(CoPt_bSIPCord, OilTqCf_B.VEMS_vidGET);

    /* Outputs for atomic SubSystem: '<S6>/Mem1' */
    OilTqCf_Mem(OilTqCf_B.VEMS_vidGET, OilTqCf_facDen_MP, &OilTqCf_B.Mem1,
                &OilTqCf_DWork.Mem1);

    /* end of Outputs for SubSystem: '<S6>/Mem1' */

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/OilTqCf_bAcvSIPCordCdnDen_C'
     */
    if (OilTqCf_bAcvSIPCordCdnDen_C) {
      OilTqCf_B.Switch1 = OilTqCf_B.Mem1.Switch1;
    } else {
      OilTqCf_B.Switch1 = OilTqCf_facDen_MP;
    }

    /* DataTypeConversion: '<S6>/DTC1' */
    localSwitch2 = ((Float32)OilTqCf_B.Switch1) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET9 */
    VEMS_vidGET(TqSys_tqIdcReq, OilTqCf_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET8 */
    VEMS_vidGET(TqSys_tqIdcAirReqGen, OilTqCf_B.VEMS_vidGET8);

    /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
     *  Constant: '<S6>/OilTqCf_facNum_C'
     *  Constant: '<S6>/OilTqCf_stPrmNum_C'
     */
    switch (OilTqCf_stPrmNum_C) {
     case 0:
      OilTqCf_facNum_MP = OilTqCf_B.VEMS_vidGET9;
      break;

     case 1:
      OilTqCf_facNum_MP = OilTqCf_B.VEMS_vidGET8;
      break;

     case 2:
      OilTqCf_facNum_MP = locallocalAdd;
      break;

     case 3:
      OilTqCf_facNum_MP = OilTqCf_B.VEMS_vidGET7;
      break;

     default:
      OilTqCf_facNum_MP = OilTqCf_facNum_C;
      break;
    }

    /* Outputs for atomic SubSystem: '<S6>/Mem' */
    OilTqCf_Mem(OilTqCf_B.VEMS_vidGET, OilTqCf_facNum_MP, &OilTqCf_B.Mem,
                &OilTqCf_DWork.Mem);

    /* end of Outputs for SubSystem: '<S6>/Mem' */

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/OilTqCf_bAcvSIPCordCdnNum_C'
     */
    if (OilTqCf_bAcvSIPCordCdnNum_C) {
      OilTqCf_B.Switch = OilTqCf_B.Mem.Switch1;
    } else {
      OilTqCf_B.Switch = OilTqCf_facNum_MP;
    }

    /* DataTypeConversion: '<S6>/DTC50' */
    localSwitch = ((Float32)OilTqCf_B.Switch) * 0.0625F;

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_nEng, OilTqCf_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_pAirExtMes, OilTqCf_B.VEMS_vidGET5);

    /* DataTypeDuplicate Block: '<S8>/Data Type Duplicate2'
     *
     * Regarding '<S8>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S9>/Data Type Duplicate2'
     *
     * Regarding '<S9>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup_n-D: '<S8>/Lookup Table (n-D)' */
    OilTqCf_rLdHi_MP = look2_iu16lftu16n4If_binlcns(OilTqCf_B.VEMS_vidGET4,
      OilTqCf_B.VEMS_vidGET5, (&(OilTqCf_nEng_rLdHiX_A[0])),
      (&(OilTqCf_pAirExtMes_rLdHiY_A[0])), (&(OilTqCf_rLdHi_M[0])),
      &OilTqCf_ConstP.pooled3[0], 9U);

    /* MinMax: '<S6>/MinMax' incorporates:
     *  Constant: '<S6>/Constant'
     */
    localmax = rt_MAXf(localSwitch, 0.0F);

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/ '
     *  Constant: '<S12>/ 1'
     *  Constant: '<S12>/constant'
     *  RelationalOperator: '<S12>/Relational Operator'
     */
    if (localSwitch2 >= 0.0F) {
      localSwitch = 10.0F;
    } else {
      localSwitch = -10.0F;
    }

    /* Switch: '<S12>/Switch2' incorporates:
     *  Abs: '<S12>/Abs'
     *  Constant: '<S12>/ '
     *  RelationalOperator: '<S12>/Relational Operator1'
     */
    if (!(ACTEMS_FabsF(localSwitch2) < 10.0F)) {
      localSwitch = localSwitch2;
    }

    /* Product: '<S12>/Product' incorporates:
     *  Constant: '<S6>/Constant1'
     *  MinMax: '<S6>/MinMax1'
     */
    localSwitch = rt_MINf(2000.0F, localmax) / localSwitch;

    /* RelationalOperator: '<S12>/Relational Operator2' */
    localRelationalOperator2 = (localSwitch != localSwitch);

    /* RelationalOperator: '<S21>/LowerRelop1' incorporates:
     *  Constant: '<S12>/SatMaxDiv'
     */
    localLowerRelop1 = (localSwitch > 1.0F);

    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S12>/SatMinDiv'
     *  RelationalOperator: '<S21>/UpperRelop'
     */
    if (localSwitch < 0.0F) {
      localSwitch = 0.0F;
    }

    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S12>/SatMaxDiv'
     */
    if (localLowerRelop1) {
      localSwitch = 1.0F;
    }

    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    if (localRelationalOperator2) {
      localSwitch = 0.0F;
    }

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S6>/VEMS_Constant'
     */
    OilTqCf_rLdNorm_MP = 100.0F * localSwitch;

    /* Lookup_n-D: '<S9>/Lookup Table (n-D)' */
    OilTqCf_rLdLo_MP = look2_iu16lftu16n4If_binlcns(OilTqCf_B.VEMS_vidGET4,
      OilTqCf_B.VEMS_vidGET5, (&(OilTqCf_nEng_rLdLoX_A[0])),
      (&(OilTqCf_pAirExtMes_rLdLoY_A[0])), (&(OilTqCf_rLdLo_M[0])),
      &OilTqCf_ConstP.pooled3[0], 9U);

    /* Outputs for atomic SubSystem: '<S6>/HysPos1' */

    /* RelationalOperator: '<S7>/Relational Operator4' */
    localRelationalOperator4 = (OilTqCf_rLdHi_MP <= OilTqCf_rLdNorm_MP);

    /* Switch: '<S7>/Switch' incorporates:
     *  RelationalOperator: '<S7>/Relational Operator1'
     *  RelationalOperator: '<S7>/Relational Operator2'
     *  RelationalOperator: '<S7>/Relational Operator3'
     */
    if (OilTqCf_rLdHi_MP != OilTqCf_rLdLo_MP) {
      localSwitch_f = (OilTqCf_rLdNorm_MP <= OilTqCf_rLdLo_MP);
    } else {
      localSwitch_f = (OilTqCf_rLdNorm_MP < OilTqCf_rLdLo_MP);
    }

    /* UnitDelay: '<S15>/UnitDelay' */
    localUnitDelay1 = OilTqCf_DWork.UnitDelay;

    /* CombinatorialLogic: '<S15>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator4 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localSwitch_f != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_l[0] = OilTqCf_ConstP.Logic_table[rowidx];
      localLogic_l[1] = OilTqCf_ConstP.Logic_table[rowidx + 8];
    }

    /* UnitDelay: '<S15>/UnitDelay1' */
    localUnitDelay1 = OilTqCf_DWork.UnitDelay_g;

    /* Switch: '<S15>/Switch2' incorporates:
     *  Constant: '<S15>/NotCLR3'
     */
    if (localUnitDelay1) {
      localRelationalOperator2 = localLogic_l[0];
    } else {
      localRelationalOperator2 = TRUE;
    }

    /* Update for UnitDelay: '<S15>/UnitDelay' */
    OilTqCf_DWork.UnitDelay = localRelationalOperator2;

    /* Update for UnitDelay: '<S15>/UnitDelay1' incorporates:
     *  Constant: '<S15>/NotCLR2'
     */
    OilTqCf_DWork.UnitDelay_g = TRUE;

    /* end of Outputs for SubSystem: '<S6>/HysPos1' */

    /* Logic: '<S13>/Logical Operator3' */
    localLogicalOperator3 = !localRelationalOperator2;

    /* Sum: '<S13>/Sum2' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant6'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/OilTqCf_tiDlyHysCfm_C'
     *  MinMax: '<S13>/MinMax1'
     *  Product: '<S26>/Divide'
     */
    localSwitch2 = (((Float32)OilTqCf_tiDlyHysCfm_C) * 1.000000015E-001F) +
      1.999999881E-001F;

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S13>/Constant3'
     *  RelationalOperator: '<S31>/UpperRelop'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    if (OilTqCf_DWork.UnitDelay_DSTATE < 0.0F) {
      localSwitch = 0.0F;
    } else {
      localSwitch = OilTqCf_DWork.UnitDelay_DSTATE;
    }

    /* Switch: '<S31>/Switch2' incorporates:
     *  RelationalOperator: '<S31>/LowerRelop1'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    if (!(OilTqCf_DWork.UnitDelay_DSTATE > localSwitch2)) {
      localSwitch2 = localSwitch;
    }

    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant4'
     *  Constant: '<S13>/Constant7'
     *  Constant: '<S6>/Constant3'
     *  Logic: '<S13>/Logical Operator2'
     *  Logic: '<S27>/Logical Operator'
     *  Logic: '<S27>/Logical Operator1'
     *  Sum: '<S13>/Sum1'
     *  UnitDelay: '<S25>/Unit Delay'
     *  UnitDelay: '<S32>/Unit Delay'
     */
    if (OilTqCf_DWork.UnitDelay_DSTATE_a || ((localRelationalOperator2) &&
         (!OilTqCf_DWork.UnitDelay_DSTATE_g))) {
      localSwitch2 = 0.0F;
    } else {
      localSwitch2 = (1.999999955E-002F + localSwitch2) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S13>/Relational Operator2' incorporates:
     *  MinMax: '<S13>/MinMax1'
     */
    localLowerRelop1 = (localSwitch2 >= (((Float32)OilTqCf_tiDlyHysCfm_C) *
      1.000000015E-001F));

    /* RelationalOperator: '<S13>/Relational Operator1' incorporates:
     *  Constant: '<S13>/Constant2'
     *  MinMax: '<S13>/MinMax1'
     */
    localRelationalOperator1_i = (OilTqCf_tiDlyHysCfm_C == 0);

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant5'
     *  Logic: '<S13>/Logical Operator1'
     *  Logic: '<S28>/Logical Operator'
     *  Logic: '<S28>/Logical Operator1'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    if (!localRelationalOperator1_i) {
      localR = ((localLowerRelop1) && (!OilTqCf_DWork.UnitDelay_DSTATE_h));
    } else {
      localR = TRUE;
    }

    /* Memory: '<S23>/Memory' */
    localMemory = OilTqCf_DWork.Memory_PreviousInput;

    /* CombinatorialLogic: '<S23>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localR != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = OilTqCf_ConstP.Logic_table_f[rowidx];
      localLogic[1] = OilTqCf_ConstP.Logic_table_f[rowidx + 8];
    }

    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/OilTqCf_bAcvrLdNormCdn_C'
     *  Constant: '<S6>/OilTqCf_bPresOilReqCf_C'
     *  Inport: '<Root>/FRM_bUncrtTq'
     *  Logic: '<S6>/Logical Operator1'
     */
    if (OilTqCf_bAcvrLdNormCdn_C) {
      OilTqCf_B.Switch2 = (GDGAR_bGetFRM(FRM_FRM_UNCRTTQ) || (localLogic[1]));
    } else {
      OilTqCf_B.Switch2 = OilTqCf_bPresOilReqCf_C;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(OilTqCf_bPresOilReqCf, OilTqCf_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(OilTqCf_facDen, OilTqCf_B.Switch1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
    VEMS_vidSET(OilTqCf_facNum, OilTqCf_B.Switch);

    /* Update for UnitDelay: '<S25>/Unit Delay' */
    OilTqCf_DWork.UnitDelay_DSTATE_a = localRelationalOperator1_i;

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    OilTqCf_DWork.UnitDelay_DSTATE_g = localRelationalOperator2;

    /* Update for UnitDelay: '<S24>/Unit Delay' */
    OilTqCf_DWork.UnitDelay_DSTATE = localSwitch2;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    OilTqCf_DWork.UnitDelay_DSTATE_h = localLowerRelop1;

    /* Update for Memory: '<S23>/Memory' */
    OilTqCf_DWork.Memory_PreviousInput = localLogic[0];
  }

  /* end of Outputs for SubSystem: '<S5>/F01_OilTqCf' */
}

/* Start for exported function: OilTqCf_Sdl20ms_OilTqCf */
void OilTqCf_Sdl20ms_OilTqCf_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F0_OilTqCf'
   *
   * Block description for '<S1>/F0_OilTqCf':
   *  01460_11_03533.1.1
   *
   * Block requirements for '<S1>/F0_OilTqCf':
   *  1. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_001.02 ;
   *  2. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_002.02 ;
   */
  OilTqCf_F0_OilTqCf_Start();
}

/* Output and update for exported function: OilTqCf_Sdl20ms_OilTqCf */
void OilTqCf_Sdl20ms_OilTqCf(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F0_OilTqCf'
   *
   * Block description for '<S1>/F0_OilTqCf':
   *  01460_11_03533.1.1
   *
   * Block requirements for '<S1>/F0_OilTqCf':
   *  1. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_001.02 ;
   *  2. SubSystem "F0_OilTqCf" !Trace_To : VEMS_R_11_07584_002.02 ;
   */
  OilTqCf_F0_OilTqCf();
}

/* Model initialize function */
void OilTqCf_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  OilTqCf_Sdl20ms_OilTqCf_Start();
}

#define OILTQCF_STOP_SEC_CODE
#include "OilTqCf_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
