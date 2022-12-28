/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpVlvCmdLrn                                          */
/* !Description     : HPPMPVLVCMDLRN - LEARNING STRATEGY OF THE HP PUMP SPILL VALVE COMMAND PROFILE*/
/*                                                                            */
/* !Module          : HPPmpVlvCmdLrn                                          */
/*                                                                            */
/* !File            : HPPmpVlvCmdLrn.c                                        */
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
/* !Reference       : PTS_DOC_5144356 / 05                                    */
/* !OtherRefs       : VEMS V02 ECU#065460                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Sun Mar 31 19:11:05 2013                              */
/*   Model name       : HPPmpVlvCmdLrn_AUTOCODE.mdl                           */
/*   Model version    : 1.471                                                 */
/*   Root subsystem   : /HPPmpVlvCmdLrn                                       */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPVLVCMDLRN/HPPmpVlvCm$*/
/* $Revision::   1.12                                                        $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpVlvCmdLrn.h"
#include "HPPmpVlvCmdLrn_private.h"

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
#define HPPMPVLVCMDLRN_START_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/* Block signals (auto storage) */
BlockIO_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_B;

/* Block states (auto storage) */
D_Work_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_PrevZCSigState;

/* Real-time model */
RT_MODEL_HPPmpVlvCmdLrn HPPmpVlvCmdLrn_M_;
RT_MODEL_HPPmpVlvCmdLrn *HPPmpVlvCmdLrn_M = &HPPmpVlvCmdLrn_M_;

#define HPPMPVLVCMDLRN_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpVlvCmdLrn_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPVLVCMDLRN_START_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

void HPPmpVlvCmdLrn_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F01_Init' */
void HPPmpVlvCmdLrn_F01_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(PFuCtl_NrProfCmd, PFuCtl_CmdProfilInit_C);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(PFuCtl_bAcvLrnInProgs, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET3 */
  VEMS_vidSET(PFuCtl_ctNrLrnVld, ((UInt16)0U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(PFuCtl_ctNrLrnInProgs, ((UInt16)0U));
}

/* Output and update for exported function: PFuCtl_EveRst_HPPmpVlvCmdLrn */
void PFuCtl_EveRst_HPPmpVlvCmdLrn(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Init'
   */
  HPPmpVlvCmdLrn_F01_Init();
}

/* Disable for function-call system: '<S1>/F02_HPPmpVlvCmdLrn' */
void HPPm_F02_HPPmpVlvCmdLrn_Disable(void)
{
  /* Disable for enable SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' */

  /* Disable for If: '<S6>/If' */
  HPPmpVlvCmdLrn_DWork.If_ActiveSubsystem = -1;

  /* Disable for ifaction SubSystem: '<S6>/F02_HPPmpCmdLrn' */

  /* Disable for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* Disable for atomic SubSystem: '<S9>/F02_Interruption_condition' */

  /* Disable for enable SubSystem: '<S17>/F02_Interruption_Condition' */

  /* Disable for Outport: '<S41>/PFuCtl_bPmpCmdLrnRst' */
  PFuCtl_bPmpCmdLrnRst = FALSE;
  HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE = FALSE;

  /* end of Disable for SubSystem: '<S17>/F02_Interruption_Condition' */

  /* end of Disable for SubSystem: '<S9>/F02_Interruption_condition' */

  /* end of Disable for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* Disable for atomic SubSystem: '<S8>/F02_Learning' */

  /* Disable for enable SubSystem: '<S10>/F01_Buffer' */

  /* Disable for Outport: '<S74>/PFuCtl_ctNrAppl' */
  PFuCtl_ctNrAppl = 0U;
  HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE = FALSE;

  /* end of Disable for SubSystem: '<S10>/F01_Buffer' */

  /* end of Disable for SubSystem: '<S8>/F02_Learning' */

  /* end of Disable for SubSystem: '<S6>/F02_HPPmpCmdLrn' */
  HPPmpVlvCmdLrn_DWork.F00_HPPmpVlvCmdLrn_MODE = FALSE;

  /* end of Disable for SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' */
}

/* Start for function-call system: '<S1>/F02_HPPmpVlvCmdLrn' */
void HPPmpV_F02_HPPmpVlvCmdLrn_Start(void)
{
  /* Start for enable SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' */

  /* Start for If: '<S6>/If' */
  HPPmpVlvCmdLrn_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S6>/F02_HPPmpCmdLrn' */

  /* Start for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* Start for atomic SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

  /* Start for atomic SubSystem: '<S18>/F02_Learning_in_progress' */

  /* Start for trigger SubSystem: '<S43>/F02_Reinit_ct' */

  /* VirtualOutportStart for Outport: '<S71>/PFuCtl_NrLrnIt' */
  PFuCtl_NrLrnIt = 1U;

  /* end of Start for SubSystem: '<S43>/F02_Reinit_ct' */

  /* end of Start for SubSystem: '<S18>/F02_Learning_in_progress' */

  /* end of Start for SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

  /* end of Start for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* Start for atomic SubSystem: '<S8>/F02_Learning' */

  /* Start for trigger SubSystem: '<S10>/F03c_learning_Interrupt' */

  /* VirtualOutportStart for Outport: '<S78>/PFuCtl_NrProfCmdRaw' */
  PFuCtl_NrProfCmdRaw = PFuCtl_CmdProfilInit_C;

  /* end of Start for SubSystem: '<S10>/F03c_learning_Interrupt' */

  /* end of Start for SubSystem: '<S8>/F02_Learning' */

  /* InitializeConditions for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* InitializeConditions for atomic SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

  /* InitializeConditions for atomic SubSystem: '<S18>/F02_Learning_in_progress' */

  /* InitializeConditions for UnitDelay: '<S72>/Unit Delay' */
  HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c4 = 1U;

  /* end of InitializeConditions for SubSystem: '<S18>/F02_Learning_in_progress' */

  /* end of InitializeConditions for SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

  /* end of InitializeConditions for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

  /* InitializeConditions for atomic SubSystem: '<S8>/F02_Learning' */

  /* InitializeConditions for UnitDelay: '<S84>/Unit Delay' */
  HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ek = PFuCtl_CmdProfilInit_C;

  /* InitializeConditions for Merge: '<S10>/Merge' */
  if (rtmIsFirstInitCond(HPPmpVlvCmdLrn_M)) {
    PFuCtl_NrProfCmdRaw = 25U;
  }

  /* end of InitializeConditions for SubSystem: '<S8>/F02_Learning' */

  /* VirtualOutportStart for Outport: '<S8>/PFuCtl_NrProfCmdRawSat' */
  PFuCtl_NrProfCmdRawSat = PFuCtl_CmdProfilInit_C;

  /* end of Start for SubSystem: '<S6>/F02_HPPmpCmdLrn' */

  /* end of Start for SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' */
}

/* Output and update for function-call system: '<S1>/F02_HPPmpVlvCmdLrn' */
void HPPmpVlvCmdL_F02_HPPmpVlvCmdLrn(void)
{
  /* local block i/o variables */
  Boolean localLogicalOperator3_a;
  Boolean localLogic[2];
  Boolean localLogicalOperator2_l;
  Boolean localLogicalOperator_e;
  Boolean localLogic_e[2];
  Boolean localLogic_j[2];
  Boolean localLogicalOperator1_m;
  Boolean localUnitDelay1;
  Boolean localUnitDelay_p;
  Boolean localUnitDelay_b;
  Boolean localLogicalOperator8_k;
  Boolean localUnitDelay_nkl;
  Boolean localUnitDelay_o;
  Boolean localRelationalOperator1_m;
  Boolean localLogic_g[2];
  Boolean localUnitDelay1_k;
  SInt8 localrtPrevAction;
  SInt8 localrtAction;
  Boolean localUnitDelay_n;
  Boolean localSwitch2_f;
  Boolean localSwitch2_g;
  Boolean localSwitch2_fd;
  Boolean localSwitch2_o2;
  Boolean localSwitch2_c;
  Boolean localSwitch2_o4;
  Boolean localSwitch2_fb;
  Boolean localSwitch2_n;
  Boolean localSwitch2_ag;
  Boolean localSwitch2_fs;
  SInt32 localDataTypeConversion2;
  Float32 localDataTypeConversion4;
  Float32 localSum;
  SInt32 localAdd4;
  Float32 localDivide_m;
  UInt16 localAbs1;
  UInt16 localAbs2;
  UInt16 localAbs3;
  UInt8 locallocalDataTypeConversion;
  UInt8 locallocalDataTypeConversion1_f;
  UInt32 localtmp;
  UInt16 locallocalAbs;

  /* Outputs for enable SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/HPPmpVlvCmdLrn_u8Inhib'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (HPPMPVLVCMDLRN_u8Inhib != 90) {
    if (!(((SInt32)HPPmpVlvCmdLrn_DWork.F00_HPPmpVlvCmdLrn_MODE) != 0)) {
      HPPmpVlvCmdLrn_DWork.F00_HPPmpVlvCmdLrn_MODE = TRUE;
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, HPPmpVlvCmdLrn_B.VEMS_vidGET);

    /* DataTypeDuplicate Block: '<S47>/Data Type Duplicate2'
     *
     * Regarding '<S47>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pDsThrMesSI, HPPmpVlvCmdLrn_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_tAir, HPPmpVlvCmdLrn_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, HPPmpVlvCmdLrn_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET10 */
    VEMS_vidGET(PFuCtl_bAcvPFuCtl, HPPmpVlvCmdLrn_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET11 */
    VEMS_vidGET(PFuCtl_bInhPFuCtl, HPPmpVlvCmdLrn_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pFuRailSplMes, HPPmpVlvCmdLrn_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_pFuReq, HPPmpVlvCmdLrn_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_uBatt, HPPmpVlvCmdLrn_B.VEMS_vidGET5);

    /* DataTypeConversion Block: '<S100>/Data Type Conversion1'
     *
     * Regarding '<S100>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S100>/Data Type Duplicate1'
     *
     * Regarding '<S100>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET12 */
    VEMS_vidGET(PFuCtl_mFuPmpReq, HPPmpVlvCmdLrn_B.VEMS_vidGET12);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET8 */
    VEMS_vidGET(InjrSys_mFuInjEstim, HPPmpVlvCmdLrn_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bTotCutOff, HPPmpVlvCmdLrn_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET9 */
    VEMS_vidGET(PFuCtl_agWdPmpCmdReq, HPPmpVlvCmdLrn_B.VEMS_vidGET9);

    /* If: '<S6>/If' incorporates:
     *  ActionPort: '<S7>/Action Port'
     *  ActionPort: '<S8>/Action Port'
     *  Constant: '<S6>/PFuCtl_bAcvETBHPPmpVlvCmdLrn_C'
     *  SubSystem: '<S6>/F01_HPPmpCmdLrnETB'
     *  SubSystem: '<S6>/F02_HPPmpCmdLrn'
     */
    localrtPrevAction = HPPmpVlvCmdLrn_DWork.If_ActiveSubsystem;
    if (PFuCtl_bAcvETBHPPmpVlvCmdLrn_C) {
      localrtAction = 0;
    } else {
      localrtAction = 1;
    }

    HPPmpVlvCmdLrn_DWork.If_ActiveSubsystem = localrtAction;
    if ((localrtPrevAction != localrtAction) && (localrtPrevAction == 1)) {
      /* Disable for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* Disable for atomic SubSystem: '<S9>/F02_Interruption_condition' */

      /* Disable for enable SubSystem: '<S17>/F02_Interruption_Condition' */

      /* Disable for Outport: '<S41>/PFuCtl_bPmpCmdLrnRst' */
      PFuCtl_bPmpCmdLrnRst = FALSE;
      HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE = FALSE;

      /* end of Disable for SubSystem: '<S17>/F02_Interruption_Condition' */

      /* end of Disable for SubSystem: '<S9>/F02_Interruption_condition' */

      /* end of Disable for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* Disable for atomic SubSystem: '<S8>/F02_Learning' */

      /* Disable for enable SubSystem: '<S10>/F01_Buffer' */

      /* Disable for Outport: '<S74>/PFuCtl_ctNrAppl' */
      PFuCtl_ctNrAppl = 0U;
      HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE = FALSE;

      /* end of Disable for SubSystem: '<S10>/F01_Buffer' */

      /* end of Disable for SubSystem: '<S8>/F02_Learning' */
    }

    switch (localrtAction) {
     case 0:
      /* Constant: '<S7>/PFuCtl_CmdProfETB_C' */
      HPPmpVlvCmdLrn_B.Merge = PFuCtl_CmdProfETB_C;
      break;

     case 1:
      /* UnitDelay: '<S15>/Unit Delay' */
      PFuCtl_bHPPmpVlvCmdLrnVld_prev = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ow;

      /* UnitDelay: '<S14>/Unit Delay' */
      PFuCtl_bHPPmpVlvCmdLrnIt_prev = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_os;

      /* UnitDelay: '<S13>/Unit Delay' */
      localUnitDelay_n = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_a;

      /* Outputs for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* DataTypeConversion: '<S9>/Data Type Conversion' */
      localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET3 + 40;
      if (localAdd4 <= 0) {
        locallocalDataTypeConversion = 0U;
      } else {
        locallocalDataTypeConversion = (UInt8)localAdd4;
      }

      /* DataTypeConversion: '<S9>/Data Type Conversion1' */
      localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET4 + 40;
      if (localAdd4 <= 0) {
        locallocalDataTypeConversion1_f = 0U;
      } else if (localAdd4 > 255) {
        locallocalDataTypeConversion1_f = MAX_uint8_T;
      } else {
        locallocalDataTypeConversion1_f = (UInt8)localAdd4;
      }

      /* Outputs for atomic SubSystem: '<S9>/F01_Environmental_Activation_condition' */

      /* RelationalOperator: '<S21>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_pDsThrMesLoLrnThdHi_C'
       */
      localUnitDelay_o = (PFuCtl_pDsThrMesLoLrnThdHi_C >=
                          HPPmpVlvCmdLrn_B.VEMS_vidGET1);

      /* RelationalOperator: '<S21>/Relational Operator2' incorporates:
       *  Constant: '<S16>/PFuCtl_pDsThrMesHiLrnThdHi_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET1 >=
        PFuCtl_pDsThrMesHiLrnThdHi_C);

      /* UnitDelay: '<S31>/UnitDelay' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_c;

      /* CombinatorialLogic: '<S31>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S31>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_cm;

      /* Switch: '<S31>/Switch2' incorporates:
       *  Constant: '<S31>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_f = localLogic_g[0];
      } else {
        localSwitch2_f = FALSE;
      }

      /* RelationalOperator: '<S26>/Relational Operator' incorporates:
       *  Constant: '<S16>/PFuCtl_pDsThrMesHiLrnThdLo_C'
       */
      localUnitDelay1_k = (HPPmpVlvCmdLrn_B.VEMS_vidGET1 >=
                           PFuCtl_pDsThrMesHiLrnThdLo_C);

      /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_pDsThrMesLoLrnThdLo_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET1 <=
        PFuCtl_pDsThrMesLoLrnThdLo_C);

      /* UnitDelay: '<S36>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_f;

      /* CombinatorialLogic: '<S36>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S36>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_fi;

      /* Switch: '<S36>/Switch2' incorporates:
       *  Constant: '<S36>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_g = localLogic_g[0];
      } else {
        localSwitch2_g = FALSE;
      }

      /* RelationalOperator: '<S20>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_nEngLoLrnThdHi_C'
       */
      localUnitDelay1_k = (PFuCtl_nEngLoLrnThdHi_C >=
                           HPPmpVlvCmdLrn_B.VEMS_vidGET);

      /* RelationalOperator: '<S20>/Relational Operator2' incorporates:
       *  Constant: '<S16>/PFuCtl_nEngHiLrnThdHi_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET >=
        PFuCtl_nEngHiLrnThdHi_C);

      /* UnitDelay: '<S30>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_e;

      /* CombinatorialLogic: '<S30>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S30>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_d;

      /* Switch: '<S30>/Switch2' incorporates:
       *  Constant: '<S30>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_fd = localLogic_g[0];
      } else {
        localSwitch2_fd = FALSE;
      }

      /* RelationalOperator: '<S25>/Relational Operator' incorporates:
       *  Constant: '<S16>/PFuCtl_nEngHiLrnThdLo_C'
       */
      localUnitDelay1_k = (HPPmpVlvCmdLrn_B.VEMS_vidGET >=
                           PFuCtl_nEngHiLrnThdLo_C);

      /* RelationalOperator: '<S25>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_nEngLoLrnThdLo_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET <=
        PFuCtl_nEngLoLrnThdLo_C);

      /* UnitDelay: '<S35>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_db;

      /* CombinatorialLogic: '<S35>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S35>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_a;

      /* Switch: '<S35>/Switch2' incorporates:
       *  Constant: '<S35>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_o2 = localLogic_g[0];
      } else {
        localSwitch2_o2 = FALSE;
      }

      /* Logic: '<S16>/Logical Operator4' incorporates:
       *  Logic: '<S16>/Logical Operator1'
       *  Logic: '<S16>/Logical Operator3'
       */
      HPPmpVlvCmdLrn_B.LogicalOperator4 = (((localSwitch2_fd) &&
        (localSwitch2_o2)) && ((localSwitch2_f) && (localSwitch2_g)));

      /* RelationalOperator: '<S22>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_tCoMesLoLrnThdHi_C'
       */
      localUnitDelay1_k = (PFuCtl_tCoMesLoLrnThdHi_C >=
                           locallocalDataTypeConversion1_f);

      /* RelationalOperator: '<S22>/Relational Operator2' incorporates:
       *  Constant: '<S16>/PFuCtl_tCoMesHiLrnThdHi_C'
       */
      localRelationalOperator1_m = (locallocalDataTypeConversion1_f >=
        PFuCtl_tCoMesHiLrnThdHi_C);

      /* UnitDelay: '<S32>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_m;

      /* CombinatorialLogic: '<S32>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S32>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_hd;

      /* Switch: '<S32>/Switch2' incorporates:
       *  Constant: '<S32>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_c = localLogic_g[0];
      } else {
        localSwitch2_c = FALSE;
      }

      /* RelationalOperator: '<S29>/Relational Operator' incorporates:
       *  Constant: '<S16>/PFuCtl_tCoMesHiLrnThdLo_C'
       */
      localUnitDelay1_k = (locallocalDataTypeConversion1_f >=
                           PFuCtl_tCoMesHiLrnThdLo_C);

      /* RelationalOperator: '<S29>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_tCoMesLoLrnThdLo_C'
       */
      localRelationalOperator1_m = (locallocalDataTypeConversion1_f <=
        PFuCtl_tCoMesLoLrnThdLo_C);

      /* UnitDelay: '<S39>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_p;

      /* CombinatorialLogic: '<S39>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S39>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_bx;

      /* Switch: '<S39>/Switch2' incorporates:
       *  Constant: '<S39>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_o4 = localLogic_g[0];
      } else {
        localSwitch2_o4 = FALSE;
      }

      /* RelationalOperator: '<S23>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_uBattLoLrnThdHi_C'
       */
      localUnitDelay1_k = (PFuCtl_uBattLoLrnThdHi_C >=
                           HPPmpVlvCmdLrn_B.VEMS_vidGET5);

      /* RelationalOperator: '<S23>/Relational Operator2' incorporates:
       *  Constant: '<S16>/PFuCtl_uBattHiLrnThdHi_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET5 >=
        PFuCtl_uBattHiLrnThdHi_C);

      /* UnitDelay: '<S33>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_l;

      /* CombinatorialLogic: '<S33>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S33>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_c5;

      /* Switch: '<S33>/Switch2' incorporates:
       *  Constant: '<S33>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_fb = localLogic_g[0];
      } else {
        localSwitch2_fb = FALSE;
      }

      /* RelationalOperator: '<S28>/Relational Operator' incorporates:
       *  Constant: '<S16>/PFuCtl_uBattHiLrnThdLo_C'
       */
      localUnitDelay1_k = (HPPmpVlvCmdLrn_B.VEMS_vidGET5 >=
                           PFuCtl_uBattHiLrnThdLo_C);

      /* RelationalOperator: '<S28>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_uBattLoLrnThdLo_C'
       */
      localRelationalOperator1_m = (HPPmpVlvCmdLrn_B.VEMS_vidGET5 <=
        PFuCtl_uBattLoLrnThdLo_C);

      /* UnitDelay: '<S38>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_g;

      /* CombinatorialLogic: '<S38>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S38>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_p1;

      /* Switch: '<S38>/Switch2' incorporates:
       *  Constant: '<S38>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_n = localLogic_g[0];
      } else {
        localSwitch2_n = FALSE;
      }

      /* RelationalOperator: '<S24>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_tAirLoLrnThdHi_C'
       */
      localUnitDelay1_k = (PFuCtl_tAirLoLrnThdHi_C >=
                           locallocalDataTypeConversion);

      /* RelationalOperator: '<S24>/Relational Operator2' incorporates:
       *  Constant: '<S16>/PFuCtl_tAirHiLrnThdHi_C'
       */
      localRelationalOperator1_m = (locallocalDataTypeConversion >=
        PFuCtl_tAirHiLrnThdHi_C);

      /* UnitDelay: '<S34>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_ig;

      /* CombinatorialLogic: '<S34>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S34>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_au;

      /* Switch: '<S34>/Switch2' incorporates:
       *  Constant: '<S34>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_ag = localLogic_g[0];
      } else {
        localSwitch2_ag = FALSE;
      }

      /* RelationalOperator: '<S27>/Relational Operator' incorporates:
       *  Constant: '<S16>/PFuCtl_tAirHiLrnThdLo_C'
       */
      localUnitDelay1_k = (locallocalDataTypeConversion >=
                           PFuCtl_tAirHiLrnThdLo_C);

      /* RelationalOperator: '<S27>/Relational Operator1' incorporates:
       *  Constant: '<S16>/PFuCtl_tAirLoLrnThdLo_C'
       */
      localRelationalOperator1_m = (locallocalDataTypeConversion <=
        PFuCtl_tAirLoLrnThdLo_C);

      /* UnitDelay: '<S37>/UnitDelay' */
      localUnitDelay_o = HPPmpVlvCmdLrn_DWork.UnitDelay_o;

      /* CombinatorialLogic: '<S37>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1_k != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_o != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_g[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_g[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S37>/UnitDelay1' */
      localUnitDelay1_k = HPPmpVlvCmdLrn_DWork.UnitDelay_hv;

      /* Switch: '<S37>/Switch2' incorporates:
       *  Constant: '<S37>/NotCLR3'
       */
      if (localUnitDelay1_k) {
        localSwitch2_fs = localLogic_g[0];
      } else {
        localSwitch2_fs = FALSE;
      }

      /* Logic: '<S16>/Logical Operator11' incorporates:
       *  Constant: '<S16>/Constant4'
       *  Constant: '<S16>/PFuCtl_bForcAcvLrn_C'
       *  Inport: '<Root>/FRM_bInhVlvCmdLrn'
       *  Logic: '<S16>/Logical Operator10'
       *  Logic: '<S16>/Logical Operator12'
       *  Logic: '<S16>/Logical Operator2'
       *  Logic: '<S16>/Logical Operator5'
       *  Logic: '<S16>/Logical Operator6'
       *  Logic: '<S16>/Logical Operator7'
       *  Logic: '<S16>/Logical Operator8'
       *  Logic: '<S16>/Logical Operator9'
       *  RelationalOperator: '<S16>/Relational Operator2'
       */
      HPPmpVlvCmdLrn_B.LogicalOperator11 =
        (((((((HPPmpVlvCmdLrn_B.LogicalOperator4 && ((((localSwitch2_c) &&
                  (localSwitch2_o4)) && ((localSwitch2_fb) && (localSwitch2_n)))
                && ((localSwitch2_ag) && (localSwitch2_fs)))) &&
              HPPmpVlvCmdLrn_B.VEMS_vidGET10) && (!GDGAR_bGetFRM
              (FRM_FRM_INHVLVCMDLRN))) && (!HPPmpVlvCmdLrn_B.VEMS_vidGET11)) &&
           (!HPPmpVlvCmdLrn_B.VEMS_vidGET6)) && (HPPmpVlvCmdLrn_B.VEMS_vidGET9
           != 0)) || PFuCtl_bForcAcvLrn_C);

      /* Update for UnitDelay: '<S31>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_c = localSwitch2_f;

      /* Update for UnitDelay: '<S31>/UnitDelay1' incorporates:
       *  Constant: '<S31>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_cm = TRUE;

      /* Update for UnitDelay: '<S36>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_f = localSwitch2_g;

      /* Update for UnitDelay: '<S36>/UnitDelay1' incorporates:
       *  Constant: '<S36>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_fi = TRUE;

      /* Update for UnitDelay: '<S30>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_e = localSwitch2_fd;

      /* Update for UnitDelay: '<S30>/UnitDelay1' incorporates:
       *  Constant: '<S30>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_d = TRUE;

      /* Update for UnitDelay: '<S35>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_db = localSwitch2_o2;

      /* Update for UnitDelay: '<S35>/UnitDelay1' incorporates:
       *  Constant: '<S35>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_a = TRUE;

      /* Update for UnitDelay: '<S32>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_m = localSwitch2_c;

      /* Update for UnitDelay: '<S32>/UnitDelay1' incorporates:
       *  Constant: '<S32>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_hd = TRUE;

      /* Update for UnitDelay: '<S39>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_p = localSwitch2_o4;

      /* Update for UnitDelay: '<S39>/UnitDelay1' incorporates:
       *  Constant: '<S39>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_bx = TRUE;

      /* Update for UnitDelay: '<S33>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_l = localSwitch2_fb;

      /* Update for UnitDelay: '<S33>/UnitDelay1' incorporates:
       *  Constant: '<S33>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_c5 = TRUE;

      /* Update for UnitDelay: '<S38>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_g = localSwitch2_n;

      /* Update for UnitDelay: '<S38>/UnitDelay1' incorporates:
       *  Constant: '<S38>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_p1 = TRUE;

      /* Update for UnitDelay: '<S34>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_ig = localSwitch2_ag;

      /* Update for UnitDelay: '<S34>/UnitDelay1' incorporates:
       *  Constant: '<S34>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_au = TRUE;

      /* Update for UnitDelay: '<S37>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_o = localSwitch2_fs;

      /* Update for UnitDelay: '<S37>/UnitDelay1' incorporates:
       *  Constant: '<S37>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_hv = TRUE;

      /* end of Outputs for SubSystem: '<S9>/F01_Environmental_Activation_condition' */

      /* UnitDelay: '<S19>/Unit Delay' */
      PFuCtl_bAcvLrnInProgs_prev = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_kb;

      /* Outputs for atomic SubSystem: '<S9>/F02_Interruption_condition' */

      /* Outputs for trigger SubSystem: '<S17>/F01_Learning_EnvCond' incorporates:
       *  TriggerPort: '<S40>/PFuCtl_bAcvLrnInProgs_prev'
       */
      if (PFuCtl_bAcvLrnInProgs_prev &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F01_Learning_EnvCond_Trig_ZCE !=
           POS_ZCSIG)) {
        /* SignalConversion: '<S40>/Signal Conversion' */
        Ext_nEngLrn = HPPmpVlvCmdLrn_B.VEMS_vidGET;

        /* SignalConversion: '<S40>/Signal Conversion1' */
        Ext_pDsThrMesSILrn = HPPmpVlvCmdLrn_B.VEMS_vidGET1;

        /* SignalConversion: '<S40>/Signal Conversion2' */
        Ext_uBattLrn = HPPmpVlvCmdLrn_B.VEMS_vidGET5;

        /* SignalConversion: '<S40>/Signal Conversion3' */
        InjSys_pFuReqLrn = HPPmpVlvCmdLrn_B.VEMS_vidGET7;

        /* SignalConversion: '<S40>/Signal Conversion4' */
        Ext_pFuRailSplMesLrn = HPPmpVlvCmdLrn_B.VEMS_vidGET2;
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F01_Learning_EnvCond_Trig_ZCE = (UInt8)
        (PFuCtl_bAcvLrnInProgs_prev ? ((SInt32)POS_ZCSIG) : ((SInt32)
          ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S17>/F01_Learning_EnvCond' */

      /* Outputs for enable SubSystem: '<S17>/F02_Interruption_Condition' incorporates:
       *  EnablePort: '<S41>/PFuCtl_bAcvLrnInProgs_prev'
       */
      if (PFuCtl_bAcvLrnInProgs_prev) {
        if (!(((SInt32)HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE) !=
              0)) {
          HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE = TRUE;
        }

        /* Sum: '<S41>/Add1' */
        localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET - Ext_nEngLrn;

        /* Abs: '<S41>/Abs' */
        if (localAdd4 < 0) {
          locallocalAbs = (UInt16)(-localAdd4);
        } else {
          locallocalAbs = (UInt16)localAdd4;
        }

        /* Sum: '<S41>/Add2' */
        localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET1 - Ext_pDsThrMesSILrn;

        /* Abs: '<S41>/Abs1' */
        if (localAdd4 < 0) {
          localAbs1 = (UInt16)(-localAdd4);
        } else {
          localAbs1 = (UInt16)localAdd4;
        }

        /* Sum: '<S41>/Add3' */
        localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET5 - Ext_uBattLrn;

        /* Abs: '<S41>/Abs2' */
        if (localAdd4 < 0) {
          localAbs2 = (UInt16)(-localAdd4);
        } else {
          localAbs2 = (UInt16)localAdd4;
        }

        /* Sum: '<S41>/Add4' */
        localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET7 - InjSys_pFuReqLrn;

        /* Abs: '<S41>/Abs3' */
        if (localAdd4 < 0) {
          localAbs3 = (UInt16)(-localAdd4);
        } else {
          localAbs3 = (UInt16)localAdd4;
        }

        /* Logic: '<S41>/Logical Operator3' incorporates:
         *  Constant: '<S41>/PFuCtl_bForcIntLrn_C'
         *  Constant: '<S41>/PFuCtl_nEngDiff_C'
         *  Constant: '<S41>/PFuCtl_pDsThrMesDiff_C'
         *  Constant: '<S41>/PFuCtl_pFuReqDiff_C'
         *  Constant: '<S41>/PFuCtl_uBattDiff_C'
         *  RelationalOperator: '<S41>/Relational Operator1'
         *  RelationalOperator: '<S41>/Relational Operator12'
         *  RelationalOperator: '<S41>/Relational Operator13'
         *  RelationalOperator: '<S41>/Relational Operator14'
         */
        PFuCtl_bPmpCmdLrnRst = ((((((locallocalAbs >= PFuCtl_nEngDiff_C) ||
          (localAbs1 >= PFuCtl_pDsThrMesDiff_C)) || (localAbs2 >=
          PFuCtl_uBattDiff_C)) || (localAbs3 >= PFuCtl_pFuReqDiff_C)) ||
          PFuCtl_bForcIntLrn_C) || (localUnitDelay_n));
      } else {
        if ((SInt32)HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE) {
          /* Disable for Outport: '<S41>/PFuCtl_bPmpCmdLrnRst' */
          PFuCtl_bPmpCmdLrnRst = FALSE;
          HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S17>/F02_Interruption_Condition' */

      /* end of Outputs for SubSystem: '<S9>/F02_Interruption_condition' */

      /* Outputs for atomic SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

      /* Outputs for atomic SubSystem: '<S18>/F01_Activation_Deactivation_Condition' */

      /* Sum: '<S42>/Add1' incorporates:
       *  UnitDelay: '<S53>/Unit Delay'
       */
      localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET7 -
        HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ez;

      /* Abs: '<S42>/Abs1' */
      if (localAdd4 < 0) {
        PFuCtl_pRailSpDifAbs = (UInt16)(-localAdd4);
      } else {
        PFuCtl_pRailSpDifAbs = (UInt16)localAdd4;
      }

      /* Sum: '<S42>/Add' */
      localAdd4 = HPPmpVlvCmdLrn_B.VEMS_vidGET7 - HPPmpVlvCmdLrn_B.VEMS_vidGET2;

      /* Abs: '<S42>/Abs3' */
      if (localAdd4 < 0) {
        locallocalAbs = (UInt16)(-localAdd4);
      } else {
        locallocalAbs = (UInt16)localAdd4;
      }

      /* DataTypeConversion: '<S42>/Data Type Conversion2' incorporates:
       *  Constant: '<S42>/PFuCtl_NoSplRazFailPmpStk_C'
       */
      localDataTypeConversion2 = PFuCtl_NoSplRazFailPmpStk_C;

      /* DataTypeConversion: '<S42>/Data Type Conversion4' incorporates:
       *  Constant: '<S42>/PFuCtl_tiTransLrn_C'
       */
      localDataTypeConversion4 = ((Float32)PFuCtl_tiTransLrn_C) *
        1.000000047E-003F;

      /* Outputs for atomic SubSystem: '<S42>/F01_Sample_time' */

      /* Product: '<S54>/Divide' incorporates:
       *  Constant: '<S46>/Constant3'
       *  Constant: '<S46>/PFuCtl_NrSpilEvePerCycle_C'
       *  DataTypeConversion: '<S46>/Data Type Conversion1'
       *  DataTypeConversion: '<S46>/Data Type Conversion4'
       *  Product: '<S55>/Divide'
       */
      localDivide_m = 120.0F / ((Float32)(HPPmpVlvCmdLrn_B.VEMS_vidGET *
        PFuCtl_NrSpilEvePerCycle_C));

      /* Outputs for atomic SubSystem: '<S54>/If Action Subsystem3' */

      /* Switch: '<S57>/Switch1' incorporates:
       *  Constant: '<S57>/Constant1'
       *  Constant: '<S57>/Constant2'
       *  Constant: '<S57>/Constant3'
       *  Logic: '<S57>/Logical Operator1'
       *  RelationalOperator: '<S57>/Relational Operator'
       *  RelationalOperator: '<S57>/Relational Operator1'
       *  RelationalOperator: '<S57>/Relational Operator3'
       */
      if (((localDivide_m != localDivide_m) || (localDivide_m >
            3.000000005E+038F)) || (-3.000000005E+038F > localDivide_m)) {
        PFuCtl_tideltaT = 0.0F;
      } else {
        PFuCtl_tideltaT = localDivide_m;
      }

      /* end of Outputs for SubSystem: '<S54>/If Action Subsystem3' */

      /* end of Outputs for SubSystem: '<S42>/F01_Sample_time' */

      /* Logic: '<S42>/Logical Operator1' incorporates:
       *  Constant: '<S42>/PFuCtl_pPrailDiffThd_C'
       *  Logic: '<S42>/Logical Operator4'
       *  RelationalOperator: '<S42>/Relational Operator'
       */
      PFuCtl_bAcvHPPmpBgnLrn = ((HPPmpVlvCmdLrn_B.LogicalOperator11 &&
        (locallocalAbs <= PFuCtl_pPrailDiffThd_C)) &&
        (!PFuCtl_bHPPmpVlvCmdLrnVld_prev));

      /* RelationalOperator: '<S48>/Relational Operator' incorporates:
       *  Constant: '<S42>/PFuCtl_pPrailHiDiffThdPmpStk_C'
       */
      localUnitDelay_p = (localAdd4 >= PFuCtl_pPrailHiDiffThdPmpStk_C);

      /* RelationalOperator: '<S48>/Relational Operator1' incorporates:
       *  Constant: '<S42>/PFuCtl_pPrailLoDiffThdPmpStk_C'
       */
      localUnitDelay_nkl = (localAdd4 <= PFuCtl_pPrailLoDiffThdPmpStk_C);

      /* UnitDelay: '<S58>/UnitDelay' */
      localLogicalOperator8_k = HPPmpVlvCmdLrn_DWork.UnitDelay_n;

      /* CombinatorialLogic: '<S58>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_p != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_nkl != 0);
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator8_k != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_j[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_j[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S58>/UnitDelay1' */
      localLogicalOperator8_k = HPPmpVlvCmdLrn_DWork.UnitDelay_k;

      /* Switch: '<S58>/Switch2' incorporates:
       *  Constant: '<S58>/NotCLR3'
       */
      if (localLogicalOperator8_k) {
        localUnitDelay_n = localLogic_j[0];
      } else {
        localUnitDelay_n = FALSE;
      }

      /* RelationalOperator: '<S42>/Relational Operator2' incorporates:
       *  Constant: '<S42>/PFuCtl_pPrailSpDiffThdHi_C'
       */
      localSwitch2_f = (PFuCtl_pRailSpDifAbs <= PFuCtl_pPrailSpDiffThdHi_C);

      /* UnitDelay: '<S61>/Unit Delay' */
      localLogicalOperator8_k = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_dt;

      /* Logic: '<S50>/Logical Operator2' incorporates:
       *  Logic: '<S50>/Logical Operator4'
       */
      localLogicalOperator8_k = ((localSwitch2_f) && (!localLogicalOperator8_k));

      /* UnitDelay: '<S62>/Unit Delay' */
      localUnitDelay_nkl = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_k3;

      /* Switch: '<S50>/Switch1' */
      if (localLogicalOperator8_k) {
        localSwitch2_g = localLogicalOperator8_k;
      } else {
        localSwitch2_g = localUnitDelay_nkl;
      }

      /* UnitDelay: '<S60>/Unit Delay' */
      localDivide_m = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE;

      /* Switch: '<S50>/Switch4' incorporates:
       *  Lookup_n-D: '<S47>/Lookup Table (n-D)'
       *  Sum: '<S50>/Sum1'
       */
      if (localLogicalOperator8_k) {
        localDivide_m = look2_1fcv2bcvbcvbfbba7xfbbnx(PFuCtl_pRailSpDifAbs,
          HPPmpVlvCmdLrn_B.VEMS_vidGET, (&(PFuCtl_pRailSpDifAbs_A[0])),
          (&(PFuCtl_nEng_tiTrans_A[0])), (&(PFuCtl_tiTransPrail_M[0])),
          &HPPmpVlvCmdLrn_ConstP.LookupTablenD_maxInde[0], 9U) + PFuCtl_tideltaT;
      }

      /* Sum: '<S50>/Sum' */
      localSum = localDivide_m - PFuCtl_tideltaT;

      /* Logic: '<S42>/Logical Operator8' incorporates:
       *  Constant: '<S42>/Constant1'
       *  Constant: '<S50>/Constant4'
       *  Logic: '<S42>/Logical Operator7'
       *  Logic: '<S50>/Logical Operator'
       *  RelationalOperator: '<S42>/Relational Operator1'
       *  RelationalOperator: '<S50>/Relational Operator3'
       */
      localLogicalOperator8_k = (((HPPmpVlvCmdLrn_B.VEMS_vidGET10 &&
        (localUnitDelay_n)) && (HPPmpVlvCmdLrn_B.VEMS_vidGET12 != 1048576U)) &&
                                 ((localSwitch2_f) && ((localSwitch2_g) &&
        (9.999999717E-010F >= localSum))));

      /* Logic: '<S42>/Logical Operator5' */
      localSwitch2_fd = !PFuCtl_bAcvLrnInProgs_prev;

      /* UnitDelay: '<S64>/Unit Delay' */
      localUnitDelay_nkl = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_od;

      /* Logic: '<S51>/Logical Operator2' incorporates:
       *  Logic: '<S51>/Logical Operator4'
       */
      localUnitDelay_nkl = ((localSwitch2_fd) && (!localUnitDelay_nkl));

      /* UnitDelay: '<S65>/Unit Delay' */
      localUnitDelay_p = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_o0;

      /* Switch: '<S51>/Switch1' */
      if (localUnitDelay_nkl) {
        localSwitch2_o2 = localUnitDelay_nkl;
      } else {
        localSwitch2_o2 = localUnitDelay_p;
      }

      /* UnitDelay: '<S63>/Unit Delay' */
      localDivide_m = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_e;

      /* Switch: '<S51>/Switch4' incorporates:
       *  Sum: '<S51>/Sum1'
       */
      if (localUnitDelay_nkl) {
        localDivide_m = localDataTypeConversion4 + PFuCtl_tideltaT;
      }

      /* Sum: '<S51>/Sum' */
      localDataTypeConversion4 = localDivide_m - PFuCtl_tideltaT;

      /* Logic: '<S42>/Logical Operator2' incorporates:
       *  Constant: '<S51>/Constant4'
       *  Logic: '<S42>/Logical Operator3'
       *  Logic: '<S51>/Logical Operator'
       *  RelationalOperator: '<S51>/Relational Operator3'
       */
      PFuCtl_bLrnVldFaildPmpStk = ((localLogicalOperator8_k) &&
        ((localSwitch2_fd) && ((localSwitch2_o2) && (9.999999717E-010F >=
        localDataTypeConversion4))));

      /* Logic: '<S42>/Logical Operator6' */
      PFuCtl_bRunHPPmpLrn = (PFuCtl_bLrnVldFaildPmpStk &&
        HPPmpVlvCmdLrn_B.LogicalOperator11);

      /* UnitDelay: '<S67>/Unit Delay' */
      localUnitDelay_nkl = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_il;

      /* Logic: '<S52>/Logical Operator2' incorporates:
       *  Logic: '<S52>/Logical Operator4'
       */
      localUnitDelay_nkl = (PFuCtl_bRunHPPmpLrn && (!localUnitDelay_nkl));

      /* UnitDelay: '<S68>/Unit Delay' */
      localUnitDelay_p = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_i1;

      /* Switch: '<S52>/Switch1' */
      if (localUnitDelay_nkl) {
        localSwitch2_c = localUnitDelay_nkl;
      } else {
        localSwitch2_c = localUnitDelay_p;
      }

      /* UnitDelay: '<S66>/Unit Delay' */
      localDivide_m = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_l;

      /* Switch: '<S52>/Switch4' incorporates:
       *  Constant: '<S42>/Constant3'
       *  Sum: '<S52>/Sum1'
       */
      if (localUnitDelay_nkl) {
        localDivide_m = ((Float32)localDataTypeConversion2) + 1.0F;
      }

      /* Sum: '<S52>/Sum' incorporates:
       *  Constant: '<S42>/Constant3'
       */
      localDivide_m--;

      /* Logic: '<S42>/Logical Operator9' incorporates:
       *  Constant: '<S52>/Constant4'
       *  Logic: '<S52>/Logical Operator'
       *  RelationalOperator: '<S52>/Relational Operator3'
       */
      localSwitch2_o4 = ((localLogicalOperator8_k) && ((localSwitch2_c) &&
        (9.999999717E-010F >= localDivide_m)));

      /* UnitDelay: '<S59>/Unit Delay' */
      localUnitDelay_nkl = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c5;

      /* Switch: '<S42>/Switch2' incorporates:
       *  Constant: '<S42>/Constant2'
       *  Logic: '<S42>/Logical Operator10'
       *  Logic: '<S49>/Logical Operator'
       *  Logic: '<S49>/Logical Operator1'
       */
      if (!((localSwitch2_o4) && (!localUnitDelay_nkl))) {
        localSwitch2_fb = localLogicalOperator8_k;
      } else {
        localSwitch2_fb = FALSE;
      }

      /* Update for UnitDelay: '<S53>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ez = HPPmpVlvCmdLrn_B.VEMS_vidGET7;

      /* Update for UnitDelay: '<S58>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_n = localUnitDelay_n;

      /* Update for UnitDelay: '<S58>/UnitDelay1' incorporates:
       *  Constant: '<S58>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_k = TRUE;

      /* Update for UnitDelay: '<S61>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_dt = localSwitch2_f;

      /* Update for UnitDelay: '<S62>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_k3 = localSwitch2_g;

      /* Update for UnitDelay: '<S60>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE = localSum;

      /* Update for UnitDelay: '<S64>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_od = localSwitch2_fd;

      /* Update for UnitDelay: '<S65>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_o0 = localSwitch2_o2;

      /* Update for UnitDelay: '<S63>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_e = localDataTypeConversion4;

      /* Update for UnitDelay: '<S67>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_il = PFuCtl_bRunHPPmpLrn;

      /* Update for UnitDelay: '<S68>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_i1 = localSwitch2_c;

      /* Update for UnitDelay: '<S66>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_l = localDivide_m;

      /* Update for UnitDelay: '<S59>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c5 = localSwitch2_o4;

      /* end of Outputs for SubSystem: '<S18>/F01_Activation_Deactivation_Condition' */

      /* Outputs for atomic SubSystem: '<S18>/F02_Learning_in_progress' */

      /* UnitDelay: '<S72>/Unit Delay' */
      PFuCtl_NrLrnIt_prev = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c4;

      /* Outputs for trigger SubSystem: '<S43>/F01_ct_nbr_Lrn' incorporates:
       *  TriggerPort: '<S70>/PFuCtl_bAcvHPPmpBgnLrn'
       */
      if (PFuCtl_bAcvHPPmpBgnLrn &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F01_ct_nbr_Lrn_Trig_ZCE != POS_ZCSIG))
      {
        /* Switch: '<S70>/Switch2' incorporates:
         *  Constant: '<S70>/Constant7'
         *  Constant: '<S70>/PFuCtl_NrLrnCond_C'
         *  RelationalOperator: '<S70>/Relational Operator3'
         */
        if (PFuCtl_NrLrnIt_prev == 0) {
          locallocalAbs = PFuCtl_NrLrnCond_C;
        } else {
          locallocalAbs = PFuCtl_NrLrnIt_prev;
        }

        /* Sum: '<S70>/Add1' incorporates:
         *  Constant: '<S70>/Constant6'
         *  Constant: '<S70>/Constant9'
         *  MinMax: '<S70>/MinMax1'
         */
        localAdd4 = locallocalAbs - 1;
        if (localAdd4 <= 0) {
          PFuCtl_NrLrnIt = 0U;
        } else {
          PFuCtl_NrLrnIt = (UInt16)localAdd4;
        }
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F01_ct_nbr_Lrn_Trig_ZCE = (UInt8)
        (PFuCtl_bAcvHPPmpBgnLrn ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S43>/F01_ct_nbr_Lrn' */

      /* Outputs for trigger SubSystem: '<S43>/F02_Reinit_ct' incorporates:
       *  TriggerPort: '<S71>/PFuCtl_bHPPmpVlvCmdLrnIt_prev'
       */
      if (PFuCtl_bHPPmpVlvCmdLrnIt_prev &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F02_Reinit_ct_Trig_ZCE != POS_ZCSIG)) {
        /* Constant: '<S71>/Constant2' */
        PFuCtl_NrLrnIt = 1U;
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F02_Reinit_ct_Trig_ZCE = (UInt8)
        (PFuCtl_bHPPmpVlvCmdLrnIt_prev ? ((SInt32)POS_ZCSIG) : ((SInt32)
          ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S43>/F02_Reinit_ct' */

      /* Logic: '<S43>/Logical Operator2' incorporates:
       *  Constant: '<S43>/Constant4'
       *  RelationalOperator: '<S43>/Relational Operator2'
       */
      localLogicalOperator2_l = ((0 == PFuCtl_NrLrnIt) || PFuCtl_bRunHPPmpLrn);

      /* Logic: '<S43>/Logical Operator' incorporates:
       *  Logic: '<S43>/Logical Operator1'
       */
      localLogicalOperator_e = ((PFuCtl_bPmpCmdLrnRst ||
        (!HPPmpVlvCmdLrn_B.LogicalOperator11)) || PFuCtl_bHPPmpVlvCmdLrnVld_prev);

      /* UnitDelay: '<S69>/UnitDelay' */
      localUnitDelay1 = HPPmpVlvCmdLrn_DWork.UnitDelay_b;

      /* CombinatorialLogic: '<S69>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator2_l != 0);
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator_e != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic_e[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic_e[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S69>/UnitDelay1' */
      localUnitDelay1 = HPPmpVlvCmdLrn_DWork.UnitDelay_h;

      /* Switch: '<S69>/Switch2' incorporates:
       *  Constant: '<S69>/NotCLR3'
       */
      if (localUnitDelay1) {
        localSwitch2_g = localLogic_e[0];
      } else {
        localSwitch2_g = FALSE;
      }

      /* Update for UnitDelay: '<S72>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c4 = PFuCtl_NrLrnIt;

      /* Update for UnitDelay: '<S69>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_b = localSwitch2_g;

      /* Update for UnitDelay: '<S69>/UnitDelay1' incorporates:
       *  Constant: '<S69>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_h = TRUE;

      /* end of Outputs for SubSystem: '<S18>/F02_Learning_in_progress' */

      /* Outputs for trigger SubSystem: '<S18>/F03_Activation_inc_press_test' incorporates:
       *  TriggerPort: '<S44>/PFuCtl_bRunHPPmpLrn'
       */
      if (PFuCtl_bRunHPPmpLrn &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F03_Activation_inc_press_test_T !=
           POS_ZCSIG)) {
        /* SignalConversion: '<S44>/Signal Conversion1' incorporates:
         *  Constant: '<S44>/Constant4'
         */
        PFuCtl_bAcvPFuIncTst = TRUE;
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F03_Activation_inc_press_test_T = (UInt8)
        (PFuCtl_bRunHPPmpLrn ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S18>/F03_Activation_inc_press_test' */

      /* Outputs for trigger SubSystem: '<S18>/F04_Deactivation_inc_press_test' incorporates:
       *  TriggerPort: '<S45>/PFuCtl_bAcvLrnInProgs'
       */
      if ((!localSwitch2_g) &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F04_Deactivation_inc_press_test !=
           ZERO_ZCSIG)) {
        /* SignalConversion: '<S45>/Signal Conversion1' incorporates:
         *  Constant: '<S45>/Constant4'
         */
        PFuCtl_bAcvPFuIncTst = FALSE;
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F04_Deactivation_inc_press_test = (UInt8)
        (localSwitch2_g ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S18>/F04_Deactivation_inc_press_test' */

      /* end of Outputs for SubSystem: '<S9>/F03_Consolidation_Activation_condition' */

      /* Update for UnitDelay: '<S19>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_kb = localSwitch2_g;

      /* end of Outputs for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* Outputs for atomic SubSystem: '<S8>/F02_Learning' */

      /* DataTypeConversion: '<S81>/OutDTConv' incorporates:
       *  Constant: '<S81>/offset'
       *  Constant: '<S81>/offset1'
       *  Constant: '<S81>/one_on_slope'
       *  Lookup_n-D: '<S80>/Lookup Table (n-D)'
       *  Product: '<S81>/Product4'
       *  Sum: '<S81>/Add1'
       *  Sum: '<S81>/Add2'
       */
      localDivide_m = look1_iu16lftu16If_binlcs(HPPmpVlvCmdLrn_B.VEMS_vidGET8, (
        &(PFuCtl_mFuInjEstim_A[0])), (&(PFuCtl_NrAppl_T[0])), 15U) + 0.5F;
      if (localDivide_m < 65536.0F) {
        if (localDivide_m >= 0.0F) {
          PFuCtl_NrAppl = (UInt16)localDivide_m;
        } else {
          PFuCtl_NrAppl = 0U;
        }
      } else {
        PFuCtl_NrAppl = MAX_uint16_T;
      }

      /* Outputs for atomic SubSystem: '<S10>/F04_LearningSuccess' */

      /* UnitDelay: '<S99>/Unit Delay' */
      localLogicalOperator1_m = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_lg;

      /* Logic: '<S79>/Logical Operator1' incorporates:
       *  Logic: '<S95>/Logical Operator'
       *  Logic: '<S95>/Logical Operator1'
       */
      localLogicalOperator1_m = ((localSwitch2_g) && ((localSwitch2_fb) &&
        (!localLogicalOperator1_m)));

      /* Logic: '<S79>/Logical Operator3' incorporates:
       *  Logic: '<S79>/Logical Operator2'
       */
      localLogicalOperator3_a = (PFuCtl_bLrnVldFaildPmpStk ||
        (!HPPmpVlvCmdLrn_B.LogicalOperator11));

      /* UnitDelay: '<S91>/UnitDelay' */
      localUnitDelay_b = HPPmpVlvCmdLrn_DWork.UnitDelay;

      /* CombinatorialLogic: '<S91>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator1_m != 0);
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3_a != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_b != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx];
        localLogic[1] = HPPmpVlvCmdLrn_ConstP.pooled9[rowidx + 8];
      }

      /* UnitDelay: '<S91>/UnitDelay1' */
      localUnitDelay_b = HPPmpVlvCmdLrn_DWork.UnitDelay_i;

      /* Switch: '<S91>/Switch2' incorporates:
       *  Constant: '<S91>/NotCLR3'
       */
      if (localUnitDelay_b) {
        HPPmpVlvCmdLrn_B.Switch2 = localLogic[0];
      } else {
        HPPmpVlvCmdLrn_B.Switch2 = FALSE;
      }

      /* Logic: '<S91>/LO3' */
      PFuCtl_bHPPmpVlvCmdLrnFaild = !HPPmpVlvCmdLrn_B.Switch2;

      /* UnitDelay: '<S97>/Unit Delay' */
      localUnitDelay_b = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_i;

      /* Logic: '<S93>/Logical Operator' incorporates:
       *  Logic: '<S93>/Logical Operator1'
       */
      localUnitDelay_n = ((!localSwitch2_g) && (localUnitDelay_b));

      /* UnitDelay: '<S96>/Unit Delay' */
      localUnitDelay_b = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_d;

      /* Logic: '<S92>/Logical Operator' incorporates:
       *  Logic: '<S92>/Logical Operator1'
       */
      localSwitch2_f = ((!HPPmpVlvCmdLrn_B.LogicalOperator11) &&
                        (localUnitDelay_b));

      /* UnitDelay: '<S98>/Unit Delay' */
      localUnitDelay_b = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_eu;

      /* Logic: '<S79>/Logical Operator4' incorporates:
       *  Logic: '<S79>/Logical Operator5'
       *  Logic: '<S94>/Logical Operator'
       *  Logic: '<S94>/Logical Operator1'
       */
      PFuCtl_bHPPmpVlvCmdLrnIt = ((PFuCtl_bHPPmpVlvCmdLrnFaild &&
        (localUnitDelay_n)) && ((localSwitch2_f) || (PFuCtl_bPmpCmdLrnRst &&
        (!localUnitDelay_b))));

      /* Update for UnitDelay: '<S99>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_lg = localSwitch2_fb;

      /* Update for UnitDelay: '<S91>/UnitDelay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay = HPPmpVlvCmdLrn_B.Switch2;

      /* Update for UnitDelay: '<S91>/UnitDelay1' incorporates:
       *  Constant: '<S91>/NotCLR2'
       */
      HPPmpVlvCmdLrn_DWork.UnitDelay_i = TRUE;

      /* Update for UnitDelay: '<S97>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_i = localSwitch2_g;

      /* Update for UnitDelay: '<S96>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_d =
        HPPmpVlvCmdLrn_B.LogicalOperator11;

      /* Update for UnitDelay: '<S98>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_eu = PFuCtl_bPmpCmdLrnRst;

      /* end of Outputs for SubSystem: '<S10>/F04_LearningSuccess' */

      /* Logic: '<S10>/Logical Operator3' */
      localUnitDelay_n = ((localSwitch2_g) && PFuCtl_bHPPmpVlvCmdLrnFaild);

      /* Outputs for enable SubSystem: '<S10>/F01_Buffer' incorporates:
       *  EnablePort: '<S74>/Enable'
       */
      if (localUnitDelay_n) {
        if (!(((SInt32)HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE) != 0)) {
          HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE = TRUE;
        }

        /* Sum: '<S74>/Add' incorporates:
         *  Constant: '<S74>/Constant1'
         *  UnitDelay: '<S90>/Unit Delay'
         */
        localtmp = (UInt32)(HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_n + 1);
        if (localtmp > 65535U) {
          locallocalAbs = MAX_uint16_T;
        } else {
          locallocalAbs = (UInt16)localtmp;
        }

        /* Switch: '<S74>/Switch2' incorporates:
         *  Constant: '<S74>/Constant2'
         *  RelationalOperator: '<S74>/Relational Operator1'
         */
        if (!(locallocalAbs < PFuCtl_NrAppl)) {
          locallocalAbs = 0U;
        }

        /* Switch: '<S74>/Switch1' incorporates:
         *  RelationalOperator: '<S74>/Relational Operator2'
         *  UnitDelay: '<S88>/Unit Delay'
         *  UnitDelay: '<S89>/Unit Delay'
         */
        if (HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_o <= PFuCtl_NrAppl) {
          PFuCtl_ctNrAppl = locallocalAbs;
        } else {
          PFuCtl_ctNrAppl = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c;
        }

        /* Update for UnitDelay: '<S90>/Unit Delay' */
        HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_n = PFuCtl_ctNrAppl;

        /* Update for UnitDelay: '<S88>/Unit Delay' */
        HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_o = PFuCtl_NrAppl;

        /* Update for UnitDelay: '<S89>/Unit Delay' */
        HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_c = PFuCtl_ctNrAppl;
      } else {
        if ((SInt32)HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE) {
          /* Disable for Outport: '<S74>/PFuCtl_ctNrAppl' */
          PFuCtl_ctNrAppl = 0U;
          HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE = FALSE;
        }
      }

      /* end of Outputs for SubSystem: '<S10>/F01_Buffer' */

      /* UnitDelay: '<S84>/Unit Delay' */
      PFuCtl_NrProfCmdRaw_prev = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ek;

      /* Outputs for enable SubSystem: '<S10>/F02_Iteration_profil' incorporates:
       *  EnablePort: '<S75>/Enable'
       */
      if (localUnitDelay_n) {
        /* Sum: '<S75>/Add2' incorporates:
         *  Constant: '<S75>/Constant2'
         */
        localAdd4 = PFuCtl_NrProfCmdRaw_prev - 1;
        if (localAdd4 <= 0) {
          locallocalDataTypeConversion = 0U;
        } else {
          locallocalDataTypeConversion = (UInt8)localAdd4;
        }

        /* RelationalOperator: '<S75>/Relational Operator' incorporates:
         *  Constant: '<S75>/Constant1'
         *  Sum: '<S75>/Add1'
         */
        localUnitDelay_n = (((UInt32)(PFuCtl_ctNrAppl + 1)) >= ((UInt32)
          PFuCtl_NrAppl));

        /* Logic: '<S75>/Logical Operator1' incorporates:
         *  Constant: '<S75>/PFuCtl_FaildPmpStk_C'
         *  Constant: '<S75>/PFuCtl_FaildPmpStk_C1'
         *  Logic: '<S75>/Logical Operator5'
         *  RelationalOperator: '<S75>/Relational Operator1'
         *  RelationalOperator: '<S75>/Relational Operator2'
         *  Sum: '<S75>/Add'
         */
        PFuCtl_bAcvRstLrnPFuInc = ((PFuCtl_bAcvPFuIncTst &&
          ((PFuCtl_NrProfCmdRaw_prev == PFuCtl_CmdProfilTst_C) &&
           (localUnitDelay_n))) && ((HPPmpVlvCmdLrn_B.VEMS_vidGET2 -
          Ext_pFuRailSplMesLrn) <= PFuCtl_pFuRailMesDiff_C));

        /* Switch: '<S75>/Switch' */
        if (!localUnitDelay_n) {
          locallocalDataTypeConversion = PFuCtl_NrProfCmdRaw_prev;
        }

        /* Switch: '<S75>/Switch1' incorporates:
         *  Constant: '<S75>/PFuCtl_FaildPmpStk_C2'
         */
        if (PFuCtl_bAcvRstLrnPFuInc) {
          locallocalDataTypeConversion = PFuCtl_CmdProfilTst_C;
        }

        /* MinMax: '<S75>/MinMax' incorporates:
         *  Constant: '<S75>/Constant4'
         */
        PFuCtl_NrProfCmdRaw = locallocalDataTypeConversion;
      }

      /* end of Outputs for SubSystem: '<S10>/F02_Iteration_profil' */

      /* UnitDelay: '<S82>/Unit Delay' */
      PFuCtl_bAcvFaildPmpStk = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_g;

      /* Outputs for trigger SubSystem: '<S10>/F03_Failed_Pump_Stroke' incorporates:
       *  TriggerPort: '<S76>/PFuCtl_bAcvFaildPmpStk'
       */
      if (PFuCtl_bAcvFaildPmpStk &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F03_Failed_Pump_Stroke_Trig_ZCE !=
           POS_ZCSIG)) {
        /* Switch: '<S76>/Switch' incorporates:
         *  Constant: '<S76>/PFuCtl_FaildPmpStk_C'
         *  Constant: '<S76>/PFuCtl_FaildPmpStk_C1'
         *  Sum: '<S76>/Add'
         */
        if (HPPmpVlvCmdLrn_B.Switch2) {
          localAdd4 = PFuCtl_FaildPmpStk_C + PFuCtl_NrProfCmdRaw_prev;
          if (localAdd4 <= 0) {
            PFuCtl_NrProfCmdRaw = 0U;
          } else if (localAdd4 > 255) {
            PFuCtl_NrProfCmdRaw = MAX_uint8_T;
          } else {
            PFuCtl_NrProfCmdRaw = (UInt8)localAdd4;
          }
        } else {
          PFuCtl_NrProfCmdRaw = PFuCtl_CmdProfilInit_C;
        }
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F03_Failed_Pump_Stroke_Trig_ZCE = (UInt8)
        (PFuCtl_bAcvFaildPmpStk ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S10>/F03_Failed_Pump_Stroke' */

      /* UnitDelay: '<S83>/Unit Delay' */
      PFuCtl_bAcvFaildPmpStks = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_b;

      /* Outputs for trigger SubSystem: '<S10>/F03b_Failed_pump_strokes' incorporates:
       *  TriggerPort: '<S77>/PFuCtl_bAcvFaildPmpStks'
       */
      if (PFuCtl_bAcvFaildPmpStks &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F03b_Failed_pump_strokes_Trig_Z !=
           POS_ZCSIG)) {
        /* Constant: '<S77>/PFuCtl_FaildPmpStk_C' */
        PFuCtl_NrProfCmdRaw = PFuCtl_CmdProfilInit_C;
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F03b_Failed_pump_strokes_Trig_Z = (UInt8)
        (PFuCtl_bAcvFaildPmpStks ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S10>/F03b_Failed_pump_strokes' */

      /* Outputs for trigger SubSystem: '<S10>/F03c_learning_Interrupt' incorporates:
       *  TriggerPort: '<S78>/PFuCtl_Trig'
       */
      if (PFuCtl_bHPPmpVlvCmdLrnIt &&
          (HPPmpVlvCmdLrn_PrevZCSigState.F03c_learning_Interrupt_Trig_ZC !=
           POS_ZCSIG)) {
        /* Sum: '<S78>/Add' incorporates:
         *  Constant: '<S78>/PFuCtl_FaildCndProfilInc_C'
         */
        localAdd4 = PFuCtl_FaildCndProfilInc_C + PFuCtl_NrProfCmdRaw_prev;
        if (((UInt32)localAdd4) > 255U) {
          PFuCtl_NrProfCmdRaw = MAX_uint8_T;
        } else {
          PFuCtl_NrProfCmdRaw = (UInt8)localAdd4;
        }
      }

      HPPmpVlvCmdLrn_PrevZCSigState.F03c_learning_Interrupt_Trig_ZC = (UInt8)
        (PFuCtl_bHPPmpVlvCmdLrnIt ? ((SInt32)POS_ZCSIG) : ((SInt32)ZERO_ZCSIG));

      /* end of Outputs for SubSystem: '<S10>/F03c_learning_Interrupt' */

      /* Switch: '<S87>/Switch' incorporates:
       *  Constant: '<S10>/PFuCtl_LrnPmpCmdProfMin_C'
       *  RelationalOperator: '<S87>/UpperRelop'
       */
      if (PFuCtl_NrProfCmdRaw < PFuCtl_LrnPmpCmdProfMin_C) {
        locallocalDataTypeConversion = PFuCtl_LrnPmpCmdProfMin_C;
      } else {
        locallocalDataTypeConversion = PFuCtl_NrProfCmdRaw;
      }

      /* Switch: '<S87>/Switch2' incorporates:
       *  Constant: '<S10>/PFuCtl_LrnPmpCmdProfMax_C'
       *  RelationalOperator: '<S87>/LowerRelop1'
       */
      if (PFuCtl_NrProfCmdRaw > PFuCtl_LrnPmpCmdProfMax_C) {
        PFuCtl_NrProfCmdRawSat = PFuCtl_LrnPmpCmdProfMax_C;
      } else {
        PFuCtl_NrProfCmdRawSat = locallocalDataTypeConversion;
      }

      /* Update for UnitDelay: '<S84>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ek = PFuCtl_NrProfCmdRawSat;

      /* Update for UnitDelay: '<S82>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_g = localSwitch2_fb;

      /* Update for UnitDelay: '<S83>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_b = PFuCtl_bLrnVldFaildPmpStk;

      /* end of Outputs for SubSystem: '<S8>/F02_Learning' */

      /* Outputs for atomic SubSystem: '<S8>/F03_appl_Lrn' */

      /* DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
       *  Constant: '<S11>/PFuCtl_CmdProfCor_C'
       */
      locallocalAbs = (UInt16)(PFuCtl_CmdProfCor_C + 250);

      /* Lookup2D: '<S100>/Look-Up Table (2-D)'
       * About '<S100>/Look-Up Table (2-D)':
       * Input0  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
       * Input1  Data Type:  Fixed Point    U16  2^-6  FSlope 1.5104
       * Output0 Data Type:  Fixed Point    U16  Bias -250.0
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(PFuCtl_OfsNrProfCmd), (&(PFuCtl_OfsNrProfCmd_M[0])),
                         Ext_uBattLrn, (&(PFuCtl_uBattLrn_A[0])), 15U,
                         HPPmpVlvCmdLrn_B.VEMS_vidGET5, (&(PFuCtl_uBatt_A[0])),
                         15U);

      /* DataTypeDuplicate Block: '<S100>/Data Type Duplicate2'
       *
       * Regarding '<S100>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* Switch: '<S11>/Switch3' */
      if (!localSwitch2_g) {
        locallocalAbs = PFuCtl_OfsNrProfCmd;
      }

      /* DataTypeConversion: '<S11>/Data Type Conversion1' incorporates:
       *  Sum: '<S11>/Add1'
       */
      localtmp = (UInt32)(locallocalAbs + PFuCtl_NrProfCmdRawSat);
      if (localtmp > 65535U) {
        localAbs1 = MAX_uint16_T;
      } else {
        localAbs1 = (UInt16)localtmp;
      }

      localAdd4 = localAbs1 + -250;
      if (localAdd4 <= 0) {
        locallocalDataTypeConversion = 0U;
      } else if (localAdd4 > 255) {
        locallocalDataTypeConversion = MAX_uint8_T;
      } else {
        locallocalDataTypeConversion = (UInt8)localAdd4;
      }

      /* Switch: '<S11>/Switch2' incorporates:
       *  Constant: '<S11>/PFuCtl_CmdProfiNoIdle_C1'
       *  Inport: '<Root>/FRM_bInhVlvCmdLrn'
       */
      if (GDGAR_bGetFRM(FRM_FRM_INHVLVCMDLRN)) {
        locallocalDataTypeConversion = PFuCtl_PmpCmdProfDft_C;
      }

      /* DataTypeConversion: '<S103>/OutDTConv' incorporates:
       *  Constant: '<S103>/offset'
       *  Constant: '<S103>/offset1'
       *  Constant: '<S103>/one_on_slope'
       *  Lookup_n-D: '<S102>/Lookup Table (n-D)'
       *  Product: '<S103>/Product4'
       *  Sum: '<S103>/Add1'
       *  Sum: '<S103>/Add2'
       */
      localDivide_m = look1_iu16lftu8If_binlcs(HPPmpVlvCmdLrn_B.VEMS_vidGET5,
        (&(PFuCtl_uBatt_A[0])), (&(PFuCtl_PmpCmdDftProfil_T[0])), 15U) + 0.5F;
      if (localDivide_m < 256.0F) {
        if (localDivide_m >= 0.0F) {
          locallocalDataTypeConversion1_f = (UInt8)localDivide_m;
        } else {
          locallocalDataTypeConversion1_f = 0U;
        }
      } else {
        locallocalDataTypeConversion1_f = MAX_uint8_T;
      }

      /* Switch: '<S11>/Switch4' incorporates:
       *  Constant: '<S11>/PFuCtl_CmdProfiNoIdle_C'
       */
      if (localSwitch2_fb) {
        locallocalDataTypeConversion1_f = PFuCtl_CmdProfiNoIdle_C;
      }

      /* Switch: '<S11>/Switch1' */
      if (!HPPmpVlvCmdLrn_B.LogicalOperator4) {
        locallocalDataTypeConversion = locallocalDataTypeConversion1_f;
      }

      /* RelationalOperator: '<S106>/LowerRelop1' incorporates:
       *  Constant: '<S11>/PFuCtl_PmpCmdProfMax_C'
       */
      localUnitDelay_n = (locallocalDataTypeConversion > PFuCtl_PmpCmdProfMax_C);

      /* Switch: '<S106>/Switch' incorporates:
       *  Constant: '<S11>/PFuCtl_PmpCmdProfMin_C'
       *  RelationalOperator: '<S106>/UpperRelop'
       */
      if (locallocalDataTypeConversion < PFuCtl_PmpCmdProfMin_C) {
        locallocalDataTypeConversion = PFuCtl_PmpCmdProfMin_C;
      }

      /* Switch: '<S106>/Switch2' incorporates:
       *  Constant: '<S11>/PFuCtl_PmpCmdProfMax_C'
       */
      if (localUnitDelay_n) {
        locallocalDataTypeConversion = PFuCtl_PmpCmdProfMax_C;
      }

      /* SignalConversion: '<S11>/Signal Conversion' */
      HPPmpVlvCmdLrn_B.Merge = locallocalDataTypeConversion;

      /* end of Outputs for SubSystem: '<S8>/F03_appl_Lrn' */

      /* Outputs for atomic SubSystem: '<S8>/F04_Counter' */

      /* Switch: '<S12>/Switch2' incorporates:
       *  Constant: '<S12>/Constant1'
       *  Logic: '<S110>/Logical Operator'
       *  Logic: '<S110>/Logical Operator1'
       *  Sum: '<S12>/Add'
       *  UnitDelay: '<S108>/Unit Delay'
       *  UnitDelay: '<S112>/Unit Delay'
       */
      if (HPPmpVlvCmdLrn_B.Switch2 && (!HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_k))
      {
        localtmp = (UInt32)(HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_p + 1);
        if (localtmp > 65535U) {
          locallocalAbs = MAX_uint16_T;
        } else {
          locallocalAbs = (UInt16)localtmp;
        }
      } else {
        locallocalAbs = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_p;
      }

      /* SignalConversion: '<S12>/Signal Conversion' */
      HPPmpVlvCmdLrn_B.SignalConversion = locallocalAbs;

      /* Switch: '<S12>/Switch1' incorporates:
       *  Constant: '<S12>/Constant2'
       *  Logic: '<S109>/Logical Operator'
       *  Logic: '<S109>/Logical Operator1'
       *  Sum: '<S12>/Add1'
       *  UnitDelay: '<S107>/Unit Delay'
       *  UnitDelay: '<S111>/Unit Delay'
       */
      if ((localSwitch2_g) && (!HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_m)) {
        localtmp = (UInt32)(HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_j + 1);
        if (localtmp > 65535U) {
          localAbs1 = MAX_uint16_T;
        } else {
          localAbs1 = (UInt16)localtmp;
        }
      } else {
        localAbs1 = HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_j;
      }

      /* SignalConversion: '<S12>/Signal Conversion1' */
      HPPmpVlvCmdLrn_B.SignalConversion1 = localAbs1;

      /* Update for UnitDelay: '<S108>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_p = locallocalAbs;

      /* Update for UnitDelay: '<S112>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_k = HPPmpVlvCmdLrn_B.Switch2;

      /* Update for UnitDelay: '<S107>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_j = localAbs1;

      /* Update for UnitDelay: '<S111>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_m = localSwitch2_g;

      /* end of Outputs for SubSystem: '<S8>/F04_Counter' */

      /* SignalConversion: '<S8>/Signal Conversion' */
      HPPmpVlvCmdLrn_B.SignalConversion_j = localSwitch2_fb;

      /* SignalConversion: '<S8>/Signal Conversion1' */
      HPPmpVlvCmdLrn_B.SignalConversion1_m = localSwitch2_g;

      /* Update for UnitDelay: '<S15>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_ow = HPPmpVlvCmdLrn_B.Switch2;

      /* Update for UnitDelay: '<S14>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_os = PFuCtl_bHPPmpVlvCmdLrnIt;

      /* Update for UnitDelay: '<S13>/Unit Delay' */
      HPPmpVlvCmdLrn_DWork.UnitDelay_DSTATE_a = PFuCtl_bAcvRstLrnPFuInc;
      break;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_NrProfCmd, HPPmpVlvCmdLrn_B.Merge);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_bAcvHPPmpVlvLrnCond, HPPmpVlvCmdLrn_B.LogicalOperator11);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
    VEMS_vidSET(PFuCtl_bAcvLowNoiseZone, HPPmpVlvCmdLrn_B.LogicalOperator4);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET3 */
    VEMS_vidSET(PFuCtl_bAcvLrnInProgs, HPPmpVlvCmdLrn_B.SignalConversion1_m);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET4 */
    VEMS_vidSET(PFuCtl_bFaildPmpStk, HPPmpVlvCmdLrn_B.SignalConversion_j);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET5 */
    VEMS_vidSET(PFuCtl_bHPPmpVlvCmdLrnVld, HPPmpVlvCmdLrn_B.Switch2);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET6 */
    VEMS_vidSET(PFuCtl_ctNrLrnInProgs, HPPmpVlvCmdLrn_B.SignalConversion1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET7 */
    VEMS_vidSET(PFuCtl_ctNrLrnVld, HPPmpVlvCmdLrn_B.SignalConversion);
  } else {
    if ((SInt32)HPPmpVlvCmdLrn_DWork.F00_HPPmpVlvCmdLrn_MODE) {
      /* Disable for If: '<S6>/If' */
      HPPmpVlvCmdLrn_DWork.If_ActiveSubsystem = -1;

      /* Disable for ifaction SubSystem: '<S6>/F02_HPPmpCmdLrn' */

      /* Disable for atomic SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* Disable for atomic SubSystem: '<S9>/F02_Interruption_condition' */

      /* Disable for enable SubSystem: '<S17>/F02_Interruption_Condition' */

      /* Disable for Outport: '<S41>/PFuCtl_bPmpCmdLrnRst' */
      PFuCtl_bPmpCmdLrnRst = FALSE;
      HPPmpVlvCmdLrn_DWork.F02_Interruption_Condition_MODE = FALSE;

      /* end of Disable for SubSystem: '<S17>/F02_Interruption_Condition' */

      /* end of Disable for SubSystem: '<S9>/F02_Interruption_condition' */

      /* end of Disable for SubSystem: '<S8>/F01_Learning_Activation_Condition' */

      /* Disable for atomic SubSystem: '<S8>/F02_Learning' */

      /* Disable for enable SubSystem: '<S10>/F01_Buffer' */

      /* Disable for Outport: '<S74>/PFuCtl_ctNrAppl' */
      PFuCtl_ctNrAppl = 0U;
      HPPmpVlvCmdLrn_DWork.F01_Buffer_MODE = FALSE;

      /* end of Disable for SubSystem: '<S10>/F01_Buffer' */

      /* end of Disable for SubSystem: '<S8>/F02_Learning' */

      /* end of Disable for SubSystem: '<S6>/F02_HPPmpCmdLrn' */
      HPPmpVlvCmdLrn_DWork.F00_HPPmpVlvCmdLrn_MODE = FALSE;
    }
  }

  /* end of Outputs for SubSystem: '<S5>/F00_HPPmpVlvCmdLrn' */
}

/* Disable for exported function: PFuCtl_EveSpl_HPPmpVlvCmdLrn */
void PFuCtl_EveSpl_HPPmpVlvCmdLrn_Disable(void)
{
  /* Disable for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Disable for SubSystem: '<S1>/F02_HPPmpVlvCmdLrn'
   */
  HPPm_F02_HPPmpVlvCmdLrn_Disable();
}

/* Start for exported function: PFuCtl_EveSpl_HPPmpVlvCmdLrn */
void PFuCtl_EveSpl_HPPmpVlvCmdLrn_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_HPPmpVlvCmdLrn'
   */
  HPPmpV_F02_HPPmpVlvCmdLrn_Start();
}

/* Output and update for exported function: PFuCtl_EveSpl_HPPmpVlvCmdLrn */
void PFuCtl_EveSpl_HPPmpVlvCmdLrn(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_HPPmpVlvCmdLrn'
   */
  HPPmpVlvCmdL_F02_HPPmpVlvCmdLrn();
}

/* Model initialize function */
void HPPmpVlvCmdLrn_initialize(void)
{
  /* Registration code */
  rtmSetFirstInitCond(HPPmpVlvCmdLrn_M, 1);

  /* block I/O */
  {
    HPPmpVlvCmdLrn_B.VEMS_vidGET12 = 1048576U;
  }

  /* custom signals */
  PFuCtl_OfsNrProfCmd = 250U;

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  PFuCtl_EveSpl_HPPmpVlvCmdLrn_Start();
  HPPmpVlvCmdLrn_PrevZCSigState.F03c_learning_Interrupt_Trig_ZC = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F03b_Failed_pump_strokes_Trig_Z = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F03_Failed_Pump_Stroke_Trig_ZCE = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F04_Deactivation_inc_press_test = ZERO_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F03_Activation_inc_press_test_T = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F02_Reinit_ct_Trig_ZCE = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F01_ct_nbr_Lrn_Trig_ZCE = POS_ZCSIG;
  HPPmpVlvCmdLrn_PrevZCSigState.F01_Learning_EnvCond_Trig_ZCE = POS_ZCSIG;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(HPPmpVlvCmdLrn_M)) {
    rtmSetFirstInitCond(HPPmpVlvCmdLrn_M, 0);
  }

  /* End of first time initialization. */
  rtmSetFirstInitCond(HPPmpVlvCmdLrn_M, 0);
}

#define HPPMPVLVCMDLRN_STOP_SEC_CODE
#include "HPPmpVlvCmdLrn_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
