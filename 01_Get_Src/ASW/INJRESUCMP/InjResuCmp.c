/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjResuCmp                                              */
/* !Description     : InjResuCmp : INJECTION COMPENSATION AFTER CUT OFF       */
/*                                                                            */
/* !Module          : InjResuCmp                                              */
/*                                                                            */
/* !File            : InjResuCmp.c                                            */
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
/* !Reference       : PTS_DOC_5873848 / 02                                    */
/* !OtherRefs       : VEMS V02 ECU#067745                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Dec 02 18:06:23 2013                              */
/*   Model name       : InjResuCmp_AUTOCODE.mdl                               */
/*   Model version    : 1.293                                                 */
/*   Root subsystem   : /InjResuCmp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJRESUCMP/InjResuCmp.c_v $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   HHAMLAOU                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjResuCmp.h"
#include "InjResuCmp_private.h"

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
#define INJRESUCMP_START_SEC_VAR_UNSPECIFIED
#include "InjResuCmp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjResuCmp InjResuCmp_B;

/* Block states (auto storage) */
D_Work_InjResuCmp InjResuCmp_DWork;

#define INJRESUCMP_STOP_SEC_VAR_UNSPECIFIED
#include "InjResuCmp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJRESUCMP_START_SEC_CODE
#include "InjResuCmp_MemMap.h"

void InjResuCmp_ASYNC1(int controlPortIdx)
{
}

void InjResuCmp_ASYNC2(int controlPortIdx)
{
}

void InjResuCmp_ASYNC3(int controlPortIdx)
{
  InjResuCmp_F01_Stall_indicator();
}

/* Output and update for function-call system: '<S1>/F01_Initialization' */
void InjResuCmp_F01_Initialization(void)
{
  /* S-Function "vems_vidSET" Block: <S7>/VEMS_vidSET */
  {
    UInt16 localArray[6] = {
      (4369U),
      (4369U),
      (4369U),
      (4369U),
      (4369U),
      (4369U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_facInjResuCyl, 6 , localArray );
  }

  /* Constant: '<S7>/Constant1' */
  InjSys_bDetStall = FALSE;
}

/* Output and update for exported function: InjSys_EveRst_InjResuCmp */
void InjSys_EveRst_InjResuCmp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Initialization'
   */
  InjResuCmp_F01_Initialization();
}

/*
 * Output and update for atomic system:
 *    '<S15>/rising_edge10'
 *    '<S15>/rising_edge11'
 *    '<S15>/rising_edge12'
 *    '<S15>/rising_edge13'
 *    '<S15>/rising_edge6'
 *    '<S15>/rising_edge8'
 *    '<S15>/rising_edge9'
 *    '<S56>/rising_edge6'
 *    '<S57>/rising_edge6'
 *    '<S58>/rising_edge6'
 * ...
 */
void InjResuCmp_rising_edge10(Boolean rtu_Signal, rtB_rising_edge10_InjResuCmp
  *localB, rtDW_rising_edge10_InjResuCmp *localDW)
{
  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Logic: '<S35>/Logical Operator1'
   *  UnitDelay: '<S42>/Unit Delay'
   */
  localB->LogicalOperator = (rtu_Signal && (!localDW->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S42>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtu_Signal;
}

/* Start for function-call system: '<S1>/F01_Stall_indicator' */
void InjRe_F01_Stall_indicator_Start(void)
{
  SInt32 locali;

  /* Start for enable SubSystem: '<S8>/F01_Stall_indicator' */

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
  for (locali = 0; locali < 6; locali++) {
    InjResuCmp_DWork.UnitDelay_DSTATE_p[(locali)] =
      InjResuCmp_ConstP.UnitDelay_X0[(locali)];
  }

  /* end of Start for SubSystem: '<S8>/F01_Stall_indicator' */
}

/* Output and update for function-call system: '<S1>/F01_Stall_indicator' */
void InjResuCmp_F01_Stall_indicator(void)
{
  /* local block i/o variables */
  Boolean localSelector;
  Boolean localSelector_g;
  Boolean localSelector_d;
  Boolean localSelector_c;
  Boolean localSelector_k;
  Boolean localSelector_a;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  Boolean localAssignment[6];
  Boolean localSwitch2;
  Boolean localSwitch2_a;
  Boolean localSwitch2_j;
  Boolean localSwitch2_ak;
  Boolean localSwitch2_k;
  Boolean localSwitch2_n;
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S8>/F01_Stall_indicator' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/INJRESUCMP_u8Inhib'
   *  EnablePort: '<S15>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (INJRESUCMP_u8Inhib != 90) {
    /* Outputs for atomic SubSystem: '<S15>/rising_edge13' */
    InjResuCmp_rising_edge10(InjSys_bDetStall, &InjResuCmp_B.rising_edge13,
      &InjResuCmp_DWork.rising_edge13);

    /* end of Outputs for SubSystem: '<S15>/rising_edge13' */

    /* S-Function "vems_vidGET" Block: <S15>/VEMS_vidGET */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, InjResuCmp_B.VEMS_vidGET_d);

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
     *
     * Regarding '<S28>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate'
     *
     * Regarding '<S29>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate'
     *
     * Regarding '<S30>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate'
     *
     * Regarding '<S31>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate'
     *
     * Regarding '<S32>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate'
     *
     * Regarding '<S33>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Selector: '<S28>/Selector' incorporates:
     *  Constant: '<S15>/ConstVal1'
     *  Constant: '<S28>/Constant'
     *  Constant: '<S28>/Constant1'
     *  MinMax: '<S28>/MinMax'
     *  Sum: '<S28>/Add'
     */
    localSelector = InjResuCmp_B.VEMS_vidGET_d[0];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge6' */
    InjResuCmp_rising_edge10(localSelector, &InjResuCmp_B.rising_edge6,
      &InjResuCmp_DWork.rising_edge6);

    /* end of Outputs for SubSystem: '<S15>/rising_edge6' */

    /* UnitDelay: '<S16>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_oz;

    /* CombinatorialLogic: '<S16>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge6.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S16>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_ncb;

    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S16>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2 = localLogic[0];
    } else {
      localSwitch2 = FALSE;
    }

    /* Selector: '<S29>/Selector' incorporates:
     *  Constant: '<S29>/Constant'
     *  MinMax: '<S29>/MinMax'
     */
    localSelector_g = InjResuCmp_B.VEMS_vidGET_d[1];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge8' */
    InjResuCmp_rising_edge10(localSelector_g, &InjResuCmp_B.rising_edge8,
      &InjResuCmp_DWork.rising_edge8);

    /* end of Outputs for SubSystem: '<S15>/rising_edge8' */

    /* UnitDelay: '<S17>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_lq;

    /* CombinatorialLogic: '<S17>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge8.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S17>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_k;

    /* Switch: '<S17>/Switch2' incorporates:
     *  Constant: '<S17>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_a = localLogic[0];
    } else {
      localSwitch2_a = FALSE;
    }

    /* Selector: '<S30>/Selector' incorporates:
     *  Constant: '<S30>/Constant'
     *  MinMax: '<S30>/MinMax'
     */
    localSelector_d = InjResuCmp_B.VEMS_vidGET_d[2];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge9' */
    InjResuCmp_rising_edge10(localSelector_d, &InjResuCmp_B.rising_edge9,
      &InjResuCmp_DWork.rising_edge9);

    /* end of Outputs for SubSystem: '<S15>/rising_edge9' */

    /* UnitDelay: '<S18>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_pr;

    /* CombinatorialLogic: '<S18>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge9.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S18>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_ci;

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_j = localLogic[0];
    } else {
      localSwitch2_j = FALSE;
    }

    /* Selector: '<S31>/Selector' incorporates:
     *  Constant: '<S31>/Constant'
     *  MinMax: '<S31>/MinMax'
     */
    localSelector_c = InjResuCmp_B.VEMS_vidGET_d[3];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge10' */
    InjResuCmp_rising_edge10(localSelector_c, &InjResuCmp_B.rising_edge10,
      &InjResuCmp_DWork.rising_edge10);

    /* end of Outputs for SubSystem: '<S15>/rising_edge10' */

    /* UnitDelay: '<S19>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_gb;

    /* CombinatorialLogic: '<S19>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge10.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S19>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_lk;

    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_ak = localLogic[0];
    } else {
      localSwitch2_ak = FALSE;
    }

    /* Selector: '<S32>/Selector' incorporates:
     *  Constant: '<S32>/Constant'
     *  MinMax: '<S32>/MinMax'
     */
    localSelector_k = InjResuCmp_B.VEMS_vidGET_d[4];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge11' */
    InjResuCmp_rising_edge10(localSelector_k, &InjResuCmp_B.rising_edge11,
      &InjResuCmp_DWork.rising_edge11);

    /* end of Outputs for SubSystem: '<S15>/rising_edge11' */

    /* UnitDelay: '<S20>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_nb;

    /* CombinatorialLogic: '<S20>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge11.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S20>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_f;

    /* Switch: '<S20>/Switch2' incorporates:
     *  Constant: '<S20>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_k = localLogic[0];
    } else {
      localSwitch2_k = FALSE;
    }

    /* Selector: '<S33>/Selector' incorporates:
     *  Constant: '<S33>/Constant'
     *  MinMax: '<S33>/MinMax'
     */
    localSelector_a = InjResuCmp_B.VEMS_vidGET_d[5];

    /* Outputs for atomic SubSystem: '<S15>/rising_edge12' */
    InjResuCmp_rising_edge10(localSelector_a, &InjResuCmp_B.rising_edge12,
      &InjResuCmp_DWork.rising_edge12);

    /* end of Outputs for SubSystem: '<S15>/rising_edge12' */

    /* UnitDelay: '<S21>/UnitDelay' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_oj;

    /* CombinatorialLogic: '<S21>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge13.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge12.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* UnitDelay: '<S21>/UnitDelay1' */
    localUnitDelay1 = InjResuCmp_DWork.UnitDelay_a;

    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/NotCLR3'
     */
    if (localUnitDelay1) {
      localSwitch2_n = localLogic[0];
    } else {
      localSwitch2_n = FALSE;
    }

    /* UnitDelay: '<S34>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment[locali] = InjResuCmp_DWork.UnitDelay_DSTATE_p[(locali)];
    }

    /* Assignment: '<S22>/Assignment' incorporates:
     *  Constant: '<S15>/ConstVal2'
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  MinMax: '<S22>/MinMax'
     *  Sum: '<S22>/Add'
     */
    localAssignment[0] = localSwitch2;

    /* Assignment: '<S23>/Assignment' incorporates:
     *  Constant: '<S23>/Constant'
     *  MinMax: '<S23>/MinMax'
     */
    localAssignment[1] = localSwitch2_a;

    /* Assignment: '<S24>/Assignment' incorporates:
     *  Constant: '<S24>/Constant'
     *  MinMax: '<S24>/MinMax'
     */
    localAssignment[2] = localSwitch2_j;

    /* Assignment: '<S25>/Assignment' incorporates:
     *  Constant: '<S25>/Constant'
     *  MinMax: '<S25>/MinMax'
     */
    localAssignment[3] = localSwitch2_ak;

    /* Assignment: '<S26>/Assignment' incorporates:
     *  Constant: '<S26>/Constant'
     *  MinMax: '<S26>/MinMax'
     */
    localAssignment[4] = localSwitch2_k;

    /* Assignment: '<S27>/Assignment' incorporates:
     *  Constant: '<S27>/Constant'
     *  MinMax: '<S27>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSys_prm_bDetStall[(locali)] = localAssignment[locali];
    }

    InjSys_prm_bDetStall[5] = localSwitch2_n;

    /* Update for UnitDelay: '<S16>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_oz = localSwitch2;

    /* Update for UnitDelay: '<S16>/UnitDelay1' incorporates:
     *  Constant: '<S16>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_ncb = TRUE;

    /* Update for UnitDelay: '<S17>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_lq = localSwitch2_a;

    /* Update for UnitDelay: '<S17>/UnitDelay1' incorporates:
     *  Constant: '<S17>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_k = TRUE;

    /* Update for UnitDelay: '<S18>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_pr = localSwitch2_j;

    /* Update for UnitDelay: '<S18>/UnitDelay1' incorporates:
     *  Constant: '<S18>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_ci = TRUE;

    /* Update for UnitDelay: '<S19>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_gb = localSwitch2_ak;

    /* Update for UnitDelay: '<S19>/UnitDelay1' incorporates:
     *  Constant: '<S19>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_lk = TRUE;

    /* Update for UnitDelay: '<S20>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_nb = localSwitch2_k;

    /* Update for UnitDelay: '<S20>/UnitDelay1' incorporates:
     *  Constant: '<S20>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_f = TRUE;

    /* Update for UnitDelay: '<S21>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_oj = localSwitch2_n;

    /* Update for UnitDelay: '<S21>/UnitDelay1' incorporates:
     *  Constant: '<S21>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_a = TRUE;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      InjResuCmp_DWork.UnitDelay_DSTATE_p[(locali)] = InjSys_prm_bDetStall
        [(locali)];
    }
  }

  /* end of Outputs for SubSystem: '<S8>/F01_Stall_indicator' */
}

/*
 * Output and update for atomic system:
 *    '<S50>/Counter'
 *    '<S50>/Counter1'
 *    '<S50>/Counter2'
 *    '<S50>/Counter3'
 *    '<S50>/Counter4'
 *    '<S50>/Counter5'
 *    '<S53>/Counter'
 *    '<S53>/Counter1'
 *    '<S53>/Counter2'
 *    '<S53>/Counter3'
 * ...
 */
void InjResuCmp_Counter(UInt8 rtu_Inc, Boolean rtu_Ena, Boolean rtu_Rst,
  rtB_Counter_InjResuCmp *localB, rtDW_Counter_InjResuCmp *localDW, UInt16
  rtp_Cnt_Max)
{
  UInt8 localSwitch2_o;
  UInt16 localSwitch;
  UInt32 localtmp;

  /* Switch: '<S99>/Switch2' incorporates:
   *  RelationalOperator: '<S99>/LowerRelop1'
   *  RelationalOperator: '<S99>/UpperRelop'
   *  Switch: '<S99>/Switch'
   */
  localSwitch2_o = rtu_Inc;

  /* Outputs for atomic SubSystem: '<S56>/rising_edge6' */
  InjResuCmp_rising_edge10(rtu_Rst, &localB->rising_edge6,
    &localDW->rising_edge6);

  /* end of Outputs for SubSystem: '<S56>/rising_edge6' */

  /* Sum: '<S56>/Sum1' incorporates:
   *  UnitDelay: '<S95>/Unit Delay'
   */
  localtmp = (UInt32)(localSwitch2_o + localDW->UnitDelay_DSTATE);
  if (localtmp > 65535U) {
    localSwitch = MAX_uint16_T;
  } else {
    localSwitch = (UInt16)localtmp;
  }

  /* Switch: '<S56>/Switch1' incorporates:
   *  UnitDelay: '<S95>/Unit Delay'
   */
  if (!rtu_Ena) {
    localSwitch = localDW->UnitDelay_DSTATE;
  }

  /* Switch: '<S56>/Switch2' incorporates:
   *  Constant: '<S56>/Constant1'
   */
  if (localB->rising_edge6.LogicalOperator) {
    localSwitch = 0U;
  }

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S56>/Cnt_Max'
   *  RelationalOperator: '<S102>/LowerRelop1'
   */
  if (localSwitch > rtp_Cnt_Max) {
    localB->Switch2 = rtp_Cnt_Max;
  } else {
    localB->Switch2 = localSwitch;
  }

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Switch2;
}

/*
 * Output and update for atomic system:
 *    '<S52>/falling_edge1'
 *    '<S52>/falling_edge2'
 *    '<S52>/falling_edge3'
 *    '<S52>/falling_edge4'
 *    '<S52>/falling_edge5'
 *    '<S52>/falling_edge6'
 */
void InjResuCmp_falling_edge1(Boolean rtu_Signal, rtB_falling_edge1_InjResuCmp
  *localB, rtDW_falling_edge1_InjResuCmp *localDW)
{
  /* Logic: '<S193>/Logical Operator' incorporates:
   *  Logic: '<S193>/Logical Operator1'
   *  UnitDelay: '<S205>/Unit Delay'
   */
  localB->LogicalOperator = ((!rtu_Signal) && localDW->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S205>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtu_Signal;
}

/* Output and update for function-call system: '<S1>/F02_InjResuCmp' */
void InjResuCmp_F02_InjResuCmp(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator;
  Boolean localSelector_h;
  Boolean localSelector_ai;
  Boolean localSelector_n;
  Boolean localSelector_l;
  Boolean localSelector_f;
  Boolean localSelector_p;
  Boolean localSelector_e;
  Boolean localSwitch2_m;
  Boolean localSelector_b;
  Boolean localSwitch2_ft;
  Boolean localSelector_dm;
  Boolean localSwitch2_c;
  Boolean localSelector_m;
  Boolean localSwitch2_e;
  Boolean localSelector_j;
  Boolean localSwitch2_l;
  Boolean localSelector_ag;
  Boolean localSwitch2_mk;
  Boolean localSelector_lt;
  Boolean localSelector_i;
  Boolean localLogicalOperator_e;
  Boolean localSelector_ga;
  Boolean localSelector_ln;
  Boolean localLogicalOperator1;
  Boolean localSelector_ib;
  Boolean localSelector_gy;
  Boolean localLogicalOperator2;
  Boolean localSelector_p2;
  Boolean localSelector_hb;
  Boolean localLogicalOperator3;
  Boolean localSelector_kr;
  Boolean localSelector_jw;
  Boolean localLogicalOperator4;
  Boolean localSelector_iq;
  Boolean localSelector_bz;
  Boolean localLogicalOperator5;
  Boolean localUnitDelay;
  Boolean localLogic_p[2];
  UInt16 localAssignment_m[6];
  Float32 localAdd2_m[6];
  Boolean localAssignment_c[6];
  Float32 localExt_nEng_InjSys_nEng_facIn;
  Float32 localfractionTmp_0d;
  UInt32 localExt_nEng_InjSys_nEng_fac_e;
  Float32 localfrac[2];
  UInt32 localbpIndex[2];
  Float32 localSwitch2_b[6];
  UInt32 localEngM_prm_mAirPredInCyl_Inj[6];
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  SInt32 locali;
  Float32 locallocalAdd;
  SInt32 localtmp;
  UInt8 locallocalDataTypeConversion4_i;
  UInt16 locallocalAssignment_m;

  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/INJRESUCMP_u8Inhib'
   */
  localRelationalOperator = (INJRESUCMP_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S9>/F02_InjResuCmp' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  if (localRelationalOperator) {
    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(InjSys_prm_bCylCutOff, 6, InjResuCmp_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate'
     *
     * Regarding '<S68>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S70>/Data Type Duplicate'
     *
     * Regarding '<S70>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate'
     *
     * Regarding '<S72>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate'
     *
     * Regarding '<S74>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S76>/Data Type Duplicate'
     *
     * Regarding '<S76>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S78>/Data Type Duplicate'
     *
     * Regarding '<S78>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* Outputs for atomic SubSystem: '<S49>/F01_CutOff_Counters' */

    /* Selector: '<S68>/Selector' incorporates:
     *  Constant: '<S50>/ConstVal'
     *  Constant: '<S68>/Constant'
     *  Constant: '<S68>/Constant1'
     *  MinMax: '<S68>/MinMax'
     *  Sum: '<S68>/Add'
     */
    localSelector_lt = InjResuCmp_B.VEMS_vidGET6[0];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge7' */
    InjResuCmp_rising_edge10(localSelector_lt, &InjResuCmp_B.rising_edge7,
      &InjResuCmp_DWork.rising_edge7);

    /* end of Outputs for SubSystem: '<S50>/rising_edge7' */

    /* Selector: '<S69>/Selector' incorporates:
     *  Constant: '<S50>/ConstVal1'
     *  Constant: '<S69>/Constant'
     *  Constant: '<S69>/Constant1'
     *  MinMax: '<S69>/MinMax'
     *  Sum: '<S69>/Add'
     */
    localSelector_i = InjSys_prm_bDetStall[0];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge6' */
    InjResuCmp_rising_edge10(localSelector_i, &InjResuCmp_B.rising_edge6_k,
      &InjResuCmp_DWork.rising_edge6_k);

    /* end of Outputs for SubSystem: '<S50>/rising_edge6' */

    /* Logic: '<S50>/Logical Operator' */
    localLogicalOperator_e = (InjResuCmp_B.rising_edge7.LogicalOperator ||
      InjResuCmp_B.rising_edge6_k.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_lt, localLogicalOperator_e,
                       &InjResuCmp_B.Counter, &InjResuCmp_DWork.Counter,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter' */

    /* Selector: '<S72>/Selector' incorporates:
     *  Constant: '<S72>/Constant'
     *  MinMax: '<S72>/MinMax'
     */
    localSelector_ga = InjResuCmp_B.VEMS_vidGET6[1];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge1' */
    InjResuCmp_rising_edge10(localSelector_ga, &InjResuCmp_B.rising_edge1,
      &InjResuCmp_DWork.rising_edge1);

    /* end of Outputs for SubSystem: '<S50>/rising_edge1' */

    /* Selector: '<S73>/Selector' incorporates:
     *  Constant: '<S73>/Constant'
     *  MinMax: '<S73>/MinMax'
     */
    localSelector_ln = InjSys_prm_bDetStall[1];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge8' */
    InjResuCmp_rising_edge10(localSelector_ln, &InjResuCmp_B.rising_edge8_a,
      &InjResuCmp_DWork.rising_edge8_a);

    /* end of Outputs for SubSystem: '<S50>/rising_edge8' */

    /* Logic: '<S50>/Logical Operator1' */
    localLogicalOperator1 = (InjResuCmp_B.rising_edge1.LogicalOperator ||
      InjResuCmp_B.rising_edge8_a.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter1' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_ga, localLogicalOperator1,
                       &InjResuCmp_B.Counter1, &InjResuCmp_DWork.Counter1,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter1' */

    /* Selector: '<S74>/Selector' incorporates:
     *  Constant: '<S74>/Constant'
     *  MinMax: '<S74>/MinMax'
     */
    localSelector_ib = InjResuCmp_B.VEMS_vidGET6[2];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge2' */
    InjResuCmp_rising_edge10(localSelector_ib, &InjResuCmp_B.rising_edge2,
      &InjResuCmp_DWork.rising_edge2);

    /* end of Outputs for SubSystem: '<S50>/rising_edge2' */

    /* Selector: '<S75>/Selector' incorporates:
     *  Constant: '<S75>/Constant'
     *  MinMax: '<S75>/MinMax'
     */
    localSelector_gy = InjSys_prm_bDetStall[2];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge9' */
    InjResuCmp_rising_edge10(localSelector_gy, &InjResuCmp_B.rising_edge9_n,
      &InjResuCmp_DWork.rising_edge9_n);

    /* end of Outputs for SubSystem: '<S50>/rising_edge9' */

    /* Logic: '<S50>/Logical Operator2' */
    localLogicalOperator2 = (InjResuCmp_B.rising_edge2.LogicalOperator ||
      InjResuCmp_B.rising_edge9_n.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter2' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_ib, localLogicalOperator2,
                       &InjResuCmp_B.Counter2, &InjResuCmp_DWork.Counter2,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter2' */

    /* Selector: '<S76>/Selector' incorporates:
     *  Constant: '<S76>/Constant'
     *  MinMax: '<S76>/MinMax'
     */
    localSelector_p2 = InjResuCmp_B.VEMS_vidGET6[3];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge3' */
    InjResuCmp_rising_edge10(localSelector_p2, &InjResuCmp_B.rising_edge3,
      &InjResuCmp_DWork.rising_edge3);

    /* end of Outputs for SubSystem: '<S50>/rising_edge3' */

    /* Selector: '<S77>/Selector' incorporates:
     *  Constant: '<S77>/Constant'
     *  MinMax: '<S77>/MinMax'
     */
    localSelector_hb = InjSys_prm_bDetStall[3];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge10' */
    InjResuCmp_rising_edge10(localSelector_hb, &InjResuCmp_B.rising_edge10_k,
      &InjResuCmp_DWork.rising_edge10_k);

    /* end of Outputs for SubSystem: '<S50>/rising_edge10' */

    /* Logic: '<S50>/Logical Operator3' */
    localLogicalOperator3 = (InjResuCmp_B.rising_edge3.LogicalOperator ||
      InjResuCmp_B.rising_edge10_k.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter3' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_p2, localLogicalOperator3,
                       &InjResuCmp_B.Counter3, &InjResuCmp_DWork.Counter3,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter3' */

    /* Selector: '<S78>/Selector' incorporates:
     *  Constant: '<S78>/Constant'
     *  MinMax: '<S78>/MinMax'
     */
    localSelector_kr = InjResuCmp_B.VEMS_vidGET6[4];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge4' */
    InjResuCmp_rising_edge10(localSelector_kr, &InjResuCmp_B.rising_edge4,
      &InjResuCmp_DWork.rising_edge4);

    /* end of Outputs for SubSystem: '<S50>/rising_edge4' */

    /* Selector: '<S79>/Selector' incorporates:
     *  Constant: '<S79>/Constant'
     *  MinMax: '<S79>/MinMax'
     */
    localSelector_jw = InjSys_prm_bDetStall[4];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge11' */
    InjResuCmp_rising_edge10(localSelector_jw, &InjResuCmp_B.rising_edge11_i,
      &InjResuCmp_DWork.rising_edge11_i);

    /* end of Outputs for SubSystem: '<S50>/rising_edge11' */

    /* Logic: '<S50>/Logical Operator4' */
    localLogicalOperator4 = (InjResuCmp_B.rising_edge4.LogicalOperator ||
      InjResuCmp_B.rising_edge11_i.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter4' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_kr, localLogicalOperator4,
                       &InjResuCmp_B.Counter4, &InjResuCmp_DWork.Counter4,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter4' */

    /* Selector: '<S70>/Selector' incorporates:
     *  Constant: '<S70>/Constant'
     *  MinMax: '<S70>/MinMax'
     */
    localSelector_iq = InjResuCmp_B.VEMS_vidGET6[5];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge5' */
    InjResuCmp_rising_edge10(localSelector_iq, &InjResuCmp_B.rising_edge5,
      &InjResuCmp_DWork.rising_edge5);

    /* end of Outputs for SubSystem: '<S50>/rising_edge5' */

    /* Selector: '<S71>/Selector' incorporates:
     *  Constant: '<S71>/Constant'
     *  MinMax: '<S71>/MinMax'
     */
    localSelector_bz = InjSys_prm_bDetStall[5];

    /* Outputs for atomic SubSystem: '<S50>/rising_edge12' */
    InjResuCmp_rising_edge10(localSelector_bz, &InjResuCmp_B.rising_edge12_h,
      &InjResuCmp_DWork.rising_edge12_h);

    /* end of Outputs for SubSystem: '<S50>/rising_edge12' */

    /* Logic: '<S50>/Logical Operator5' */
    localLogicalOperator5 = (InjResuCmp_B.rising_edge5.LogicalOperator ||
      InjResuCmp_B.rising_edge12_h.LogicalOperator);

    /* Outputs for atomic SubSystem: '<S50>/Counter5' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_iq, localLogicalOperator5,
                       &InjResuCmp_B.Counter5, &InjResuCmp_DWork.Counter5,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S50>/Counter5' */

    /* UnitDelay: '<S80>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_m[locali] = InjResuCmp_DWork.UnitDelay_DSTATE_e[(locali)];
    }

    /* Assignment: '<S62>/Assignment' incorporates:
     *  Constant: '<S50>/ConstVal2'
     *  Constant: '<S62>/Constant'
     *  Constant: '<S62>/Constant1'
     *  MinMax: '<S62>/MinMax'
     *  Sum: '<S62>/Add'
     */
    localAssignment_m[0] = InjResuCmp_B.Counter.Switch2;

    /* Assignment: '<S63>/Assignment' incorporates:
     *  Constant: '<S63>/Constant'
     *  MinMax: '<S63>/MinMax'
     */
    localAssignment_m[1] = InjResuCmp_B.Counter1.Switch2;

    /* Assignment: '<S64>/Assignment' incorporates:
     *  Constant: '<S64>/Constant'
     *  MinMax: '<S64>/MinMax'
     */
    localAssignment_m[2] = InjResuCmp_B.Counter2.Switch2;

    /* Assignment: '<S65>/Assignment' incorporates:
     *  Constant: '<S65>/Constant'
     *  MinMax: '<S65>/MinMax'
     */
    localAssignment_m[3] = InjResuCmp_B.Counter3.Switch2;

    /* Assignment: '<S66>/Assignment' incorporates:
     *  Constant: '<S66>/Constant'
     *  MinMax: '<S66>/MinMax'
     */
    localAssignment_m[4] = InjResuCmp_B.Counter4.Switch2;

    /* Assignment: '<S67>/Assignment' incorporates:
     *  Constant: '<S67>/Constant'
     *  MinMax: '<S67>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSys_prm_ctNbCmbCutOffCyl[(locali)] = localAssignment_m[locali];
    }

    InjSys_prm_ctNbCmbCutOffCyl[5] = InjResuCmp_B.Counter5.Switch2;

    /* end of Outputs for SubSystem: '<S49>/F01_CutOff_Counters' */

    /* Outputs for atomic SubSystem: '<S49>/F03_Resume_counter_activation' */
    for (locali = 0; locali < 6; locali++) {
      /* Product: '<S173>/Divide' incorporates:
       *  Constant: '<S51>/Ext_noCylEng_SC'
       */
      localExt_nEng_InjSys_nEng_fac_e = div_u32_ceiling((UInt32)
        InjSys_prm_ctNbCmbCutOffCyl[(locali)], (UInt32)Ext_noCylEng_SC);
      if (localExt_nEng_InjSys_nEng_fac_e > 65535U) {
        locallocalAssignment_m = MAX_uint16_T;
      } else {
        locallocalAssignment_m = (UInt16)localExt_nEng_InjSys_nEng_fac_e;
      }

      /* DataTypeConversion: '<S172>/OutDTConv' incorporates:
       *  Constant: '<S172>/offset'
       *  Constant: '<S172>/offset1'
       *  Constant: '<S172>/one_on_slope'
       *  Lookup_n-D: '<S171>/Lookup Table (n-D)'
       *  Product: '<S172>/Product4'
       *  Sum: '<S172>/Add1'
       *  Sum: '<S172>/Add2'
       */
      locallocalAdd = look1_iu16lfIf_binlcs__1(locallocalAssignment_m,
        (&(InjSys_ctAntCmpStop_A[0])), (&(InjSys_ctAntCmpStop_T[0])), 7U) + 0.5F;
      if (locallocalAdd < 65536.0F) {
        if (locallocalAdd >= 0.0F) {
          locallocalAssignment_m = (UInt16)locallocalAdd;
        } else {
          locallocalAssignment_m = 0U;
        }
      } else {
        locallocalAssignment_m = MAX_uint16_T;
      }

      InjSys_prm_ctAntCmpStopCyl[(locali)] = locallocalAssignment_m;

      /* Logic: '<S52>/Logical Operator' */
      localAssignment_c[locali] = (InjResuCmp_B.VEMS_vidGET6[(locali)] ||
        InjSys_prm_bDetStall[(locali)]);
    }

    /* Selector: '<S186>/Selector' incorporates:
     *  Constant: '<S186>/Constant'
     *  MinMax: '<S186>/MinMax'
     */
    localSelector_e = localAssignment_c[1];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge1' */
    InjResuCmp_falling_edge1(localSelector_e, &InjResuCmp_B.falling_edge1,
      &InjResuCmp_DWork.falling_edge1);

    /* end of Outputs for SubSystem: '<S52>/falling_edge1' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge1' */
    InjResuCmp_rising_edge10(localSelector_e, &InjResuCmp_B.rising_edge1_k,
      &InjResuCmp_DWork.rising_edge1_k);

    /* end of Outputs for SubSystem: '<S52>/rising_edge1' */

    /* UnitDelay: '<S174>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay;

    /* CombinatorialLogic: '<S174>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge1.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge1_k.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S174>/NotCLR3'
     *  UnitDelay: '<S174>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_n) {
      localSwitch2_m = localLogic_p[0];
    } else {
      localSwitch2_m = FALSE;
    }

    /* Selector: '<S188>/Selector' incorporates:
     *  Constant: '<S188>/Constant'
     *  MinMax: '<S188>/MinMax'
     */
    localSelector_b = localAssignment_c[2];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge2' */
    InjResuCmp_falling_edge1(localSelector_b, &InjResuCmp_B.falling_edge2,
      &InjResuCmp_DWork.falling_edge2);

    /* end of Outputs for SubSystem: '<S52>/falling_edge2' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge2' */
    InjResuCmp_rising_edge10(localSelector_b, &InjResuCmp_B.rising_edge2_g,
      &InjResuCmp_DWork.rising_edge2_g);

    /* end of Outputs for SubSystem: '<S52>/rising_edge2' */

    /* UnitDelay: '<S175>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay_c;

    /* CombinatorialLogic: '<S175>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge2.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge2_g.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S175>/Switch2' incorporates:
     *  Constant: '<S175>/NotCLR3'
     *  UnitDelay: '<S175>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_l) {
      localSwitch2_ft = localLogic_p[0];
    } else {
      localSwitch2_ft = FALSE;
    }

    /* Selector: '<S189>/Selector' incorporates:
     *  Constant: '<S189>/Constant'
     *  MinMax: '<S189>/MinMax'
     */
    localSelector_dm = localAssignment_c[3];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge3' */
    InjResuCmp_falling_edge1(localSelector_dm, &InjResuCmp_B.falling_edge3,
      &InjResuCmp_DWork.falling_edge3);

    /* end of Outputs for SubSystem: '<S52>/falling_edge3' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge3' */
    InjResuCmp_rising_edge10(localSelector_dm, &InjResuCmp_B.rising_edge3_f,
      &InjResuCmp_DWork.rising_edge3_f);

    /* end of Outputs for SubSystem: '<S52>/rising_edge3' */

    /* UnitDelay: '<S176>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay_j;

    /* CombinatorialLogic: '<S176>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge3.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge3_f.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S176>/NotCLR3'
     *  UnitDelay: '<S176>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_nc) {
      localSwitch2_c = localLogic_p[0];
    } else {
      localSwitch2_c = FALSE;
    }

    /* Selector: '<S190>/Selector' incorporates:
     *  Constant: '<S190>/Constant'
     *  MinMax: '<S190>/MinMax'
     */
    localSelector_m = localAssignment_c[4];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge4' */
    InjResuCmp_falling_edge1(localSelector_m, &InjResuCmp_B.falling_edge4,
      &InjResuCmp_DWork.falling_edge4);

    /* end of Outputs for SubSystem: '<S52>/falling_edge4' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge4' */
    InjResuCmp_rising_edge10(localSelector_m, &InjResuCmp_B.rising_edge4_c,
      &InjResuCmp_DWork.rising_edge4_c);

    /* end of Outputs for SubSystem: '<S52>/rising_edge4' */

    /* UnitDelay: '<S177>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay_g;

    /* CombinatorialLogic: '<S177>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge4.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge4_c.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S177>/NotCLR3'
     *  UnitDelay: '<S177>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_gw) {
      localSwitch2_e = localLogic_p[0];
    } else {
      localSwitch2_e = FALSE;
    }

    /* Selector: '<S191>/Selector' incorporates:
     *  Constant: '<S191>/Constant'
     *  MinMax: '<S191>/MinMax'
     */
    localSelector_j = localAssignment_c[5];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge5' */
    InjResuCmp_falling_edge1(localSelector_j, &InjResuCmp_B.falling_edge5,
      &InjResuCmp_DWork.falling_edge5);

    /* end of Outputs for SubSystem: '<S52>/falling_edge5' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge5' */
    InjResuCmp_rising_edge10(localSelector_j, &InjResuCmp_B.rising_edge5_g,
      &InjResuCmp_DWork.rising_edge5_g);

    /* end of Outputs for SubSystem: '<S52>/rising_edge5' */

    /* UnitDelay: '<S178>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay_i;

    /* CombinatorialLogic: '<S178>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge5.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge5_g.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S178>/NotCLR3'
     *  UnitDelay: '<S178>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_p) {
      localSwitch2_l = localLogic_p[0];
    } else {
      localSwitch2_l = FALSE;
    }

    /* Selector: '<S187>/Selector' incorporates:
     *  Constant: '<S187>/Constant'
     *  Constant: '<S187>/Constant1'
     *  Constant: '<S52>/ConstVal'
     *  MinMax: '<S187>/MinMax'
     *  Sum: '<S187>/Add'
     */
    localSelector_ag = localAssignment_c[0];

    /* Outputs for atomic SubSystem: '<S52>/falling_edge6' */
    InjResuCmp_falling_edge1(localSelector_ag, &InjResuCmp_B.falling_edge6,
      &InjResuCmp_DWork.falling_edge6);

    /* end of Outputs for SubSystem: '<S52>/falling_edge6' */

    /* Outputs for atomic SubSystem: '<S52>/rising_edge6' */
    InjResuCmp_rising_edge10(localSelector_ag, &InjResuCmp_B.rising_edge6_e,
      &InjResuCmp_DWork.rising_edge6_e);

    /* end of Outputs for SubSystem: '<S52>/rising_edge6' */

    /* UnitDelay: '<S179>/UnitDelay' */
    localUnitDelay = InjResuCmp_DWork.UnitDelay_o;

    /* CombinatorialLogic: '<S179>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.falling_edge6.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)
        (InjResuCmp_B.rising_edge6_e.LogicalOperator != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_p[0] = InjResuCmp_ConstP.pooled17[rowidx];
      localLogic_p[1] = InjResuCmp_ConstP.pooled17[rowidx + 8];
    }

    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S179>/NotCLR3'
     *  UnitDelay: '<S179>/UnitDelay1'
     */
    if (InjResuCmp_DWork.UnitDelay_na) {
      localSwitch2_mk = localLogic_p[0];
    } else {
      localSwitch2_mk = FALSE;
    }

    /* UnitDelay: '<S192>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_c[locali] = InjResuCmp_DWork.UnitDelay_DSTATE_c[(locali)];
    }

    /* Assignment: '<S185>/Assignment' incorporates:
     *  Constant: '<S185>/Constant'
     *  Constant: '<S185>/Constant1'
     *  Constant: '<S52>/ConstVal_8'
     *  MinMax: '<S185>/MinMax'
     *  Sum: '<S185>/Add'
     */
    localAssignment_c[0] = localSwitch2_mk;

    /* Assignment: '<S180>/Assignment' incorporates:
     *  Constant: '<S180>/Constant'
     *  MinMax: '<S180>/MinMax'
     */
    localAssignment_c[1] = localSwitch2_m;

    /* Assignment: '<S181>/Assignment' incorporates:
     *  Constant: '<S181>/Constant'
     *  MinMax: '<S181>/MinMax'
     */
    localAssignment_c[2] = localSwitch2_ft;

    /* Assignment: '<S182>/Assignment' incorporates:
     *  Constant: '<S182>/Constant'
     *  MinMax: '<S182>/MinMax'
     */
    localAssignment_c[3] = localSwitch2_c;

    /* Assignment: '<S183>/Assignment' incorporates:
     *  Constant: '<S183>/Constant'
     *  MinMax: '<S183>/MinMax'
     */
    localAssignment_c[4] = localSwitch2_e;

    /* Assignment: '<S184>/Assignment' incorporates:
     *  Constant: '<S184>/Constant'
     *  MinMax: '<S184>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSys_prm_bInjResuCyl[(locali)] = localAssignment_c[locali];
    }

    InjSys_prm_bInjResuCyl[5] = localSwitch2_l;

    /* end of Outputs for SubSystem: '<S49>/F03_Resume_counter_activation' */

    /* Outputs for atomic SubSystem: '<S49>/F04_Resume_counters' */

    /* Selector: '<S230>/Selector' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S230>/Constant1'
     *  Constant: '<S53>/ConstVal'
     *  MinMax: '<S230>/MinMax'
     *  Sum: '<S230>/Add'
     */
    localSelector_h = InjSys_prm_bInjResuCyl[0];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge7' */
    InjResuCmp_rising_edge10(localSelector_h, &InjResuCmp_B.rising_edge7_j,
      &InjResuCmp_DWork.rising_edge7_j);

    /* end of Outputs for SubSystem: '<S53>/rising_edge7' */

    /* Outputs for atomic SubSystem: '<S53>/Counter' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_h,
                       InjResuCmp_B.rising_edge7_j.LogicalOperator,
                       &InjResuCmp_B.Counter_e, &InjResuCmp_DWork.Counter_e,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter' */

    /* Selector: '<S229>/Selector' incorporates:
     *  Constant: '<S229>/Constant'
     *  MinMax: '<S229>/MinMax'
     */
    localSelector_ai = InjSys_prm_bInjResuCyl[1];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge1' */
    InjResuCmp_rising_edge10(localSelector_ai, &InjResuCmp_B.rising_edge1_c,
      &InjResuCmp_DWork.rising_edge1_c);

    /* end of Outputs for SubSystem: '<S53>/rising_edge1' */

    /* Outputs for atomic SubSystem: '<S53>/Counter1' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_ai,
                       InjResuCmp_B.rising_edge1_c.LogicalOperator,
                       &InjResuCmp_B.Counter1_h, &InjResuCmp_DWork.Counter1_h,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter1' */

    /* Selector: '<S231>/Selector' incorporates:
     *  Constant: '<S231>/Constant'
     *  MinMax: '<S231>/MinMax'
     */
    localSelector_n = InjSys_prm_bInjResuCyl[2];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge2' */
    InjResuCmp_rising_edge10(localSelector_n, &InjResuCmp_B.rising_edge2_p,
      &InjResuCmp_DWork.rising_edge2_p);

    /* end of Outputs for SubSystem: '<S53>/rising_edge2' */

    /* Outputs for atomic SubSystem: '<S53>/Counter2' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_n,
                       InjResuCmp_B.rising_edge2_p.LogicalOperator,
                       &InjResuCmp_B.Counter2_o, &InjResuCmp_DWork.Counter2_o,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter2' */

    /* Selector: '<S232>/Selector' incorporates:
     *  Constant: '<S232>/Constant'
     *  MinMax: '<S232>/MinMax'
     */
    localSelector_l = InjSys_prm_bInjResuCyl[3];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge3' */
    InjResuCmp_rising_edge10(localSelector_l, &InjResuCmp_B.rising_edge3_e,
      &InjResuCmp_DWork.rising_edge3_e);

    /* end of Outputs for SubSystem: '<S53>/rising_edge3' */

    /* Outputs for atomic SubSystem: '<S53>/Counter3' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_l,
                       InjResuCmp_B.rising_edge3_e.LogicalOperator,
                       &InjResuCmp_B.Counter3_h, &InjResuCmp_DWork.Counter3_h,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter3' */

    /* Selector: '<S233>/Selector' incorporates:
     *  Constant: '<S233>/Constant'
     *  MinMax: '<S233>/MinMax'
     */
    localSelector_f = InjSys_prm_bInjResuCyl[4];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge4' */
    InjResuCmp_rising_edge10(localSelector_f, &InjResuCmp_B.rising_edge4_k,
      &InjResuCmp_DWork.rising_edge4_k);

    /* end of Outputs for SubSystem: '<S53>/rising_edge4' */

    /* Outputs for atomic SubSystem: '<S53>/Counter4' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_f,
                       InjResuCmp_B.rising_edge4_k.LogicalOperator,
                       &InjResuCmp_B.Counter4_b, &InjResuCmp_DWork.Counter4_b,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter4' */

    /* Selector: '<S234>/Selector' incorporates:
     *  Constant: '<S234>/Constant'
     *  MinMax: '<S234>/MinMax'
     */
    localSelector_p = InjSys_prm_bInjResuCyl[5];

    /* Outputs for atomic SubSystem: '<S53>/rising_edge5' */
    InjResuCmp_rising_edge10(localSelector_p, &InjResuCmp_B.rising_edge5_f,
      &InjResuCmp_DWork.rising_edge5_f);

    /* end of Outputs for SubSystem: '<S53>/rising_edge5' */

    /* Outputs for atomic SubSystem: '<S53>/Counter5' */
    InjResuCmp_Counter(((UInt8)1U), localSelector_p,
                       InjResuCmp_B.rising_edge5_f.LogicalOperator,
                       &InjResuCmp_B.Counter5_n, &InjResuCmp_DWork.Counter5_n,
                       ((UInt16)65535U));

    /* end of Outputs for SubSystem: '<S53>/Counter5' */

    /* UnitDelay: '<S235>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_m[locali] = InjResuCmp_DWork.UnitDelay_DSTATE[(locali)];
    }

    /* Assignment: '<S228>/Assignment' incorporates:
     *  Constant: '<S228>/Constant'
     *  Constant: '<S228>/Constant1'
     *  Constant: '<S53>/ConstVal_4'
     *  MinMax: '<S228>/MinMax'
     *  Sum: '<S228>/Add'
     */
    localAssignment_m[0] = InjResuCmp_B.Counter_e.Switch2;

    /* Assignment: '<S223>/Assignment' incorporates:
     *  Constant: '<S223>/Constant'
     *  MinMax: '<S223>/MinMax'
     */
    localAssignment_m[1] = InjResuCmp_B.Counter1_h.Switch2;

    /* Assignment: '<S224>/Assignment' incorporates:
     *  Constant: '<S224>/Constant'
     *  MinMax: '<S224>/MinMax'
     */
    localAssignment_m[2] = InjResuCmp_B.Counter2_o.Switch2;

    /* Assignment: '<S225>/Assignment' incorporates:
     *  Constant: '<S225>/Constant'
     *  MinMax: '<S225>/MinMax'
     */
    localAssignment_m[3] = InjResuCmp_B.Counter3_h.Switch2;

    /* Assignment: '<S226>/Assignment' incorporates:
     *  Constant: '<S226>/Constant'
     *  MinMax: '<S226>/MinMax'
     */
    localAssignment_m[4] = InjResuCmp_B.Counter4_b.Switch2;

    /* Assignment: '<S227>/Assignment' incorporates:
     *  Constant: '<S227>/Constant'
     *  MinMax: '<S227>/MinMax'
     */
    localAssignment_m[5] = InjResuCmp_B.Counter5_n.Switch2;
    for (locali = 0; locali < 6; locali++) {
      /* Product: '<S236>/Divide' incorporates:
       *  Constant: '<S53>/Ext_noCylEng_SC'
       */
      localtmp = Ext_noCylEng_SC;
      localExt_nEng_InjSys_nEng_fac_e = (((UInt32)localtmp) == ((UInt32)0)) ?
        MAX_uint32_T : (((UInt32)localAssignment_m[locali]) / ((UInt32)
        localtmp));
      if (localExt_nEng_InjSys_nEng_fac_e > 65535U) {
        locallocalAssignment_m = MAX_uint16_T;
      } else {
        locallocalAssignment_m = (UInt16)localExt_nEng_InjSys_nEng_fac_e;
      }

      InjSys_prm_ctInjResuCyl[(locali)] = locallocalAssignment_m;

      /* Update for UnitDelay: '<S235>/Unit Delay' */
      InjResuCmp_DWork.UnitDelay_DSTATE[(locali)] = localAssignment_m[locali];
    }

    /* end of Outputs for SubSystem: '<S49>/F04_Resume_counters' */
    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, InjResuCmp_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET */
    VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, InjResuCmp_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET9 */
    VEMS_vidGET(TqSys_bEngNOnIdl, InjResuCmp_B.VEMS_vidGET9);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(EngM_prm_mAirPredInCyl, 6, InjResuCmp_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEng, InjResuCmp_B.VEMS_vidGET2);

    /* Outputs for atomic SubSystem: '<S49>/F05_Compensations' *
     * Block requirements for '<S49>/F05_Compensations':
     *  1. SubSystem "F05_Compensations" !Trace_To : VEMS_R_10_07956_017.01 ;
     */

    /* DataTypeConversion: '<S54>/Data Type Conversion4' */
    locali = InjResuCmp_B.VEMS_vidGET4 + 40;
    if (locali <= 0) {
      locallocalDataTypeConversion4_i = 0U;
    } else if (locali > 255) {
      locallocalDataTypeConversion4_i = MAX_uint8_T;
    } else {
      locallocalDataTypeConversion4_i = (UInt8)locali;
    }

    /* PreLookup: '<S322>/Prelookup' */
    localExt_nEng_InjSys_nEng_fac_e = plook_u32u8f_binc
      (locallocalDataTypeConversion4_i, (&(InjSys_tCo_facInjResuTCor_A[0])), 7U,
       &localExt_nEng_InjSys_nEng_facIn);

    /* Interpolation_n-D: '<S315>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_InjSys_nEng_facIn;
    InjSys_facInjResuTCor_MP = intrp1d_iu16n13ff_u32f_l_ns
      (localExt_nEng_InjSys_nEng_fac_e, localfractionTmp_0d,
       (&(InjSys_facInjResuTCor_T[0])));

    /* Interpolation_n-D: '<S316>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_InjSys_nEng_facIn;
    InjSys_facTCorIntrSTT_MP = intrp1d_iu16n13ff_u32f_l_ns
      (localExt_nEng_InjSys_nEng_fac_e, localfractionTmp_0d,
       (&(InjSys_facInjResuTCorIntrSTT_T[0])));

    /* PreLookup: '<S323>/Prelookup' */
    localExt_nEng_InjSys_nEng_fac_e = plook_u32u16f_binc
      (InjResuCmp_B.VEMS_vidGET2, (&(InjSys_nEng_facInjResuCorX_A[0])), 7U,
       &localExt_nEng_InjSys_nEng_facIn);

    /* PreLookup: '<S324>/Prelookup' */
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl_Inj[locali] = plook_u32u16f_binc
        (InjResuCmp_B.VEMS_vidGET1[(locali)], (&(InjSys_mAir_facInjResuCorY_A[0])),
         7U, &localSwitch2_b[locali]);
    }

    /* Interpolation_n-D: '<S317>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_InjSys_nEng_facIn;
    localfrac[0] = localfractionTmp_0d;
    localbpIndex[0] = localExt_nEng_InjSys_nEng_fac_e;
    for (locali = 0; locali < 6; locali++) {
      localfractionTmp_0d = localSwitch2_b[(UInt32)locali];
      localfrac[1] = localfractionTmp_0d;
      localbpIndex[1] = localEngM_prm_mAirPredInCyl_Inj[(UInt32)locali];
      InjSys_prm_facInjResuCor_MP[(locali)] = intrp2d_iu16n13ff_u32f_l_ns
        (localbpIndex, localfrac, (&(InjSys_facInjResuCor_M[0])), 8U);
    }

    /* Interpolation_n-D: '<S318>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_InjSys_nEng_facIn;
    localfrac_0[0] = localfractionTmp_0d;
    localbpIndex_0[0] = localExt_nEng_InjSys_nEng_fac_e;
    for (locali = 0; locali < 6; locali++) {
      localfractionTmp_0d = localSwitch2_b[(UInt32)locali];
      localfrac_0[1] = localfractionTmp_0d;
      localbpIndex_0[1] = localEngM_prm_mAirPredInCyl_Inj[(UInt32)locali];
      InjSys_prm_facCorIntrSTT_MP[(locali)] = intrp2d_iu16n13ff_u32f_l_ns
        (localbpIndex_0, localfrac_0, (&(InjSys_facInjResuCorIntrSTT_M[0])), 8U);
    }

    for (locali = 0; locali < 6; locali++) {
      /* Sum: '<S54>/Sum' */
      localExt_nEng_InjSys_nEng_fac_e = (UInt32)(InjSys_prm_ctInjResuCyl
        [(locali)] + InjSys_prm_ctAntCmpStopCyl[(locali)]);
      if (localExt_nEng_InjSys_nEng_fac_e > 65535U) {
        locallocalAssignment_m = MAX_uint16_T;
      } else {
        locallocalAssignment_m = (UInt16)localExt_nEng_InjSys_nEng_fac_e;
      }

      /* Lookup_n-D: '<S319>/Lookup Table (n-D)' */
      InjSys_prm_facInjResuIdlCmp_MP[(locali)] = look1_iu16lftu16n13If_binlcns
        (locallocalAssignment_m, (&(InjSys_ct_facInjResuIdlCmp_A[0])),
         (&(InjSys_facInjResuIdlCmp_T[0])), 7U);

      /* Lookup_n-D: '<S320>/Lookup Table (n-D)' */
      InjSys_prm_facInjResuTqCmp_MP[(locali)] = look1_iu16lftu16n13If_binlcns
        (locallocalAssignment_m, (&(InjSys_ct_facInjResuTqCmp_A[0])),
         (&(InjSys_facInjResuTqCmp_T[0])), 7U);

      /* Lookup_n-D: '<S321>/Lookup Table (n-D)' */
      InjSys_prm_facInjResuIntrSTT_MP[(locali)] = look1_iu16lftu16n13If_binlcns
        (locallocalAssignment_m, (&(InjSys_ct_facInjResuIntrSTT_A[0])),
         (&(InjSys_facInjResuIntrSTT_T[0])), 7U);
    }

    /* Product: '<S327>/Divide' */
    for (locali = 0; locali < 6; locali++) {
      localSwitch2_b[locali] = InjSys_facInjResuTCor_MP *
        InjSys_prm_facInjResuCor_MP[(locali)];
    }

    /* Product: '<S325>/Divide' incorporates:
     *  Constant: '<S54>/ConstVal'
     *  Sum: '<S54>/Sum1'
     */
    for (locali = 0; locali < 6; locali++) {
      localAdd2_m[locali] = (InjSys_prm_facInjResuIdlCmp_MP[(locali)] - 1.0F) *
        localSwitch2_b[locali];
    }

    /* Sum: '<S54>/Sum3' incorporates:
     *  Constant: '<S54>/ConstVal3'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSys_prm_facResuIdl_MP[(locali)] = localAdd2_m[locali] + 1.0F;
    }

    /* Product: '<S326>/Divide' incorporates:
     *  Constant: '<S54>/ConstVal1'
     *  Sum: '<S54>/Sum2'
     */
    for (locali = 0; locali < 6; locali++) {
      localAdd2_m[locali] = (InjSys_prm_facInjResuTqCmp_MP[(locali)] - 1.0F) *
        localSwitch2_b[locali];
    }

    /* Sum: '<S54>/Sum4' incorporates:
     *  Constant: '<S54>/ConstVal4'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSys_prm_facResuTq_MP[(locali)] = localAdd2_m[locali] + 1.0F;
    }

    /* Switch: '<S54>/Switch' */
    for (locali = 0; locali < 6; locali++) {
      if (InjResuCmp_B.VEMS_vidGET9) {
        localSwitch2_b[locali] = InjSys_prm_facResuIdl_MP[(locali)];
      } else {
        localSwitch2_b[locali] = InjSys_prm_facResuTq_MP[(locali)];
      }
    }

    /* Switch: '<S54>/Switch2' incorporates:
     *  Constant: '<S54>/ConstVal2'
     *  Constant: '<S54>/ConstVal5'
     *  Logic: '<S54>/Logical Operator'
     *  Product: '<S328>/Divide'
     *  Product: '<S329>/Divide'
     *  Sum: '<S54>/Sum5'
     *  Sum: '<S54>/Sum6'
     */
    if (InjResuCmp_B.VEMS_vidGET) {
      for (locali = 0; locali < 6; locali++) {
        localSwitch2_b[locali] = ((InjSys_prm_facInjResuIntrSTT_MP[(locali)] -
          1.0F) * (InjSys_facTCorIntrSTT_MP * InjSys_prm_facCorIntrSTT_MP
                   [(locali)])) + 1.0F;
      }
    }

    /* Switch: '<S54>/Switch1' incorporates:
     *  Constant: '<S54>/ConstMat'
     *  Constant: '<S54>/InjSys_bAcvInjResuCmp_C'
     */
    for (locali = 0; locali < 6; locali++) {
      if (InjSys_bAcvInjResuCmp_C) {
        InjSys_prm_facGslResuCyl[(locali)] = localSwitch2_b[locali];
      } else {
        InjSys_prm_facGslResuCyl[(locali)] = InjResuCmp_ConstP.ConstMat_Value
          [(locali)];
      }
    }

    /* end of Outputs for SubSystem: '<S49>/F05_Compensations' */
    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(Ext_prm_idxFuTypCyl, 6, InjResuCmp_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET8 */
    VEMS_vidGET1DArray(InjSys_prm_facGasResuCyl, 6, InjResuCmp_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(InjSys_prm_facFlexResuCyl, 6, InjResuCmp_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S49>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_facInjResuAdpFlex, InjResuCmp_B.VEMS_vidGET5);

    /* Outputs for atomic SubSystem: '<S49>/F06_Fuel_Choice' */

    /* DataTypeConversion: '<S55>/Data Type Conversion1' */
    localfractionTmp_0d = ((Float32)InjResuCmp_B.VEMS_vidGET5) *
      3.051757813E-005F;

    /* Switch: '<S335>/Switch2' incorporates:
     *  Constant: '<S330>/Constant'
     *  RelationalOperator: '<S335>/LowerRelop1'
     */
    if (localfractionTmp_0d > 1.0F) {
      localfractionTmp_0d = 1.0F;
    }

    for (locali = 0; locali < 6; locali++) {
      /* MultiPortSwitch: '<S55>/Multiport Switch' incorporates:
       *  DataTypeConversion: '<S55>/Data Type Conversion'
       *  DataTypeConversion: '<S55>/Data Type Conversion4'
       *  Product: '<S330>/Divide'
       *  Sum: '<S330>/Sum2'
       *  Sum: '<S330>/Sum3'
       */
      switch (InjResuCmp_B.VEMS_vidGET3[(locali)]) {
       case 0:
        locallocalAdd = InjSys_prm_facGslResuCyl[(locali)];
        break;

       case 1:
        locallocalAdd = ((Float32)InjResuCmp_B.VEMS_vidGET8[(locali)]) *
          2.288818359E-004F;
        break;

       default:
        locallocalAdd = (((((Float32)InjResuCmp_B.VEMS_vidGET7[(locali)]) *
                           2.288818359E-004F) - InjSys_prm_facGslResuCyl[(locali)])
                         * localfractionTmp_0d) + InjSys_prm_facGslResuCyl
          [(locali)];
        break;
      }

      /* DataTypeConversion: '<S331>/OutDTConv' incorporates:
       *  Constant: '<S331>/offset'
       *  Constant: '<S331>/offset1'
       *  Constant: '<S331>/one_on_slope'
       *  Product: '<S331>/Product4'
       *  Sum: '<S331>/Add1'
       *  Sum: '<S331>/Add2'
       */
      locallocalAdd = (4.369066895E+003F * locallocalAdd) + 0.5F;
      if (locallocalAdd < 65536.0F) {
        if (locallocalAdd >= 0.0F) {
          locallocalAssignment_m = (UInt16)locallocalAdd;
        } else {
          locallocalAssignment_m = 0U;
        }
      } else {
        locallocalAssignment_m = MAX_uint16_T;
      }

      InjResuCmp_B.OutDTConv[(locali)] = locallocalAssignment_m;
    }

    /* end of Outputs for SubSystem: '<S49>/F06_Fuel_Choice' */
    /* S-Function "vems_vidSET" Block: <S49>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_facInjResuCyl, 6, InjResuCmp_B.OutDTConv);
  }

  /* end of Outputs for SubSystem: '<S9>/F02_InjResuCmp' */

  /* Update for enable SubSystem: '<S9>/F02_InjResuCmp' incorporates:
   *  Update for EnablePort: '<S49>/Enable'
   */
  if (localRelationalOperator) {
    /* Update for atomic SubSystem: '<S49>/F03_Resume_counter_activation' */

    /* Update for UnitDelay: '<S174>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay = localSwitch2_m;

    /* Update for UnitDelay: '<S174>/UnitDelay1' incorporates:
     *  Constant: '<S174>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_n = TRUE;

    /* Update for UnitDelay: '<S175>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_c = localSwitch2_ft;

    /* Update for UnitDelay: '<S175>/UnitDelay1' incorporates:
     *  Constant: '<S175>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_l = TRUE;

    /* Update for UnitDelay: '<S176>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_j = localSwitch2_c;

    /* Update for UnitDelay: '<S176>/UnitDelay1' incorporates:
     *  Constant: '<S176>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_nc = TRUE;

    /* Update for UnitDelay: '<S177>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_g = localSwitch2_e;

    /* Update for UnitDelay: '<S177>/UnitDelay1' incorporates:
     *  Constant: '<S177>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_gw = TRUE;

    /* Update for UnitDelay: '<S178>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_i = localSwitch2_l;

    /* Update for UnitDelay: '<S178>/UnitDelay1' incorporates:
     *  Constant: '<S178>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_p = TRUE;

    /* Update for UnitDelay: '<S179>/UnitDelay' */
    InjResuCmp_DWork.UnitDelay_o = localSwitch2_mk;

    /* Update for UnitDelay: '<S179>/UnitDelay1' incorporates:
     *  Constant: '<S179>/NotCLR2'
     */
    InjResuCmp_DWork.UnitDelay_na = TRUE;
    for (locali = 0; locali < 6; locali++) {
      /* Update for atomic SubSystem: '<S49>/F01_CutOff_Counters' */

      /* Update for UnitDelay: '<S80>/Unit Delay' */
      InjResuCmp_DWork.UnitDelay_DSTATE_e[(locali)] =
        InjSys_prm_ctNbCmbCutOffCyl[(locali)];

      /* end of Update for SubSystem: '<S49>/F01_CutOff_Counters' */

      /* Update for UnitDelay: '<S192>/Unit Delay' */
      InjResuCmp_DWork.UnitDelay_DSTATE_c[(locali)] = InjSys_prm_bInjResuCyl
        [(locali)];
    }

    /* end of Update for SubSystem: '<S49>/F03_Resume_counter_activation' */
  }

  /* end of Update for SubSystem: '<S9>/F02_InjResuCmp' */
}

/* Start for exported function: InjSys_EveInj_InjResuCmp */
void InjSys_EveInj_InjResuCmp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_Stall_indicator'
   *  Start for SubSystem: '<S1>/F02_InjResuCmp'
   */
  InjRe_F01_Stall_indicator_Start();
}

/* Output and update for exported function: InjSys_EveInj_InjResuCmp */
void InjSys_EveInj_InjResuCmp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  SubSystem: '<S1>/F02_InjResuCmp'
   */
  InjResuCmp_ASYNC3(0);
  InjResuCmp_F02_InjResuCmp();
}

/* Output and update for function-call system: '<S1>/F03_Det_Stall' */
void InjResuCmp_F03_Det_Stall(void)
{
  /* Outputs for enable SubSystem: '<S10>/F03_Det_Stall' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/INJRESUCMP_u8Inhib'
   *  EnablePort: '<S336>/Enable'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if (INJRESUCMP_u8Inhib != 90) {
    /* Constant: '<S336>/Constant' */
    InjSys_bDetStall = TRUE;
  }

  /* end of Outputs for SubSystem: '<S10>/F03_Det_Stall' */
}

/* Output and update for exported function: InjSys_EveRTSt_InjResuCmp */
void InjSys_EveRTSt_InjResuCmp(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc2'
   */

  /* S-Function (fcncallgen): '<S12>/gen' incorporates:
   *  SubSystem: '<S1>/F03_Det_Stall'
   */
  InjResuCmp_F03_Det_Stall();
  InjResuCmp_ASYNC3(1);
}

/* Output and update for function-call system: '<S1>/F00_RstDetStall' */
void InjResuCmp_F00_RstDetStall(void)
{
  /* Outputs for enable SubSystem: '<S6>/F00_RstDetStall' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/INJRESUCMP_u8Inhib'
   *  EnablePort: '<S14>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (INJRESUCMP_u8Inhib != 90) {
    /* Constant: '<S14>/Constant' */
    InjSys_bDetStall = FALSE;
  }

  /* end of Outputs for SubSystem: '<S6>/F00_RstDetStall' */
}

/* Output and update for exported function: InjSys_EveStTR_InjResuCmp */
void InjSys_EveStTR_InjResuCmp(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc3'
   */

  /* S-Function (fcncallgen): '<S13>/gen' incorporates:
   *  SubSystem: '<S1>/F00_RstDetStall'
   */
  InjResuCmp_ASYNC3(2);
  InjResuCmp_F00_RstDetStall();
}

/* Model initialize function */
void InjResuCmp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
  InjSys_EveInj_InjResuCmp_Start();
}

#define INJRESUCMP_STOP_SEC_CODE
#include "InjResuCmp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
