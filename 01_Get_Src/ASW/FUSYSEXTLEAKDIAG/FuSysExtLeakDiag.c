/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : FuSysExtLeakDiag                                        */
/* !Description     : Functional diagnosis of external leak on Fuel System    */
/*                                                                            */
/* !Module          : FuSysExtLeakDiag                                        */
/*                                                                            */
/* !File            : FuSysExtLeakDiag.c                                      */
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
/* !Reference       : PTS_DOC_5304538 / 04                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Dec 17 17:01:08 2013                              */
/*   Model name       : FuSysExtLeakDiag_AUTOCODE.mdl                         */
/*   Model version    : 1.350                                                 */
/*   Root subsystem   : /FuSysExtLeakDiag                                     */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUSYSEXTLEAKDIAG/FuSysExtLeak$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   etsasson                               $$Date::   19 Dec 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "FuSysExtLeakDiag.h"
#include "FuSysExtLeakDiag_private.h"

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
#define FUSYSEXTLEAKDIAG_START_SEC_VAR_UNSPECIFIED
#include "FuSysExtLeakDiag_MemMap.h"

/* Block signals (auto storage) */
BlockIO_FuSysExtLeakDiag FuSysExtLeakDiag_B;

/* Block states (auto storage) */
D_Work_FuSysExtLeakDiag FuSysExtLeakDiag_DWork;

#define FUSYSEXTLEAKDIAG_STOP_SEC_VAR_UNSPECIFIED
#include "FuSysExtLeakDiag_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define FUSYSEXTLEAKDIAG_START_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

/* Output and update for function-call system: '<S1>/00_FuSysExtLeakDiagInit' */
void FuSysExt_u_FuSysExtLeakDiagInit(void)
{
  /* Constant: '<S4>/Fu_tiPFuRailExtLeakEngRunDly_C' */
  Fu_tiPFuRailExtLeakEngRunDlyIn = Fu_tiPFuRailExtLeakEngRunDly_C;

  /* Constant: '<S4>/Fu_tiPFuRailExtLeakEngStallDly_C' */
  Fu_tiPFuRailExtLeakEngStallDlyIn = Fu_tiPFuRailExtLeakEngStallDly_C;
}

/* Output and update for exported function: Fu_EveRst_ExtLeakDiag */
void Fu_EveRst_ExtLeakDiag(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/00_FuSysExtLeakDiagInit'
   */
  FuSysExt_u_FuSysExtLeakDiagInit();
}

/* Outputs for atomic system: '<S9>/01_DlyAcvDiagRun' */
void FuSysExtLeakDia_u_DlyAcvDiagRun(void)
{
  SInt32 localrtmax;
  UInt16 localSwitch;
  UInt32 localtmp;

  /* Switch: '<S19>/Switch' incorporates:
   *  UnitDelay: '<S20>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  if (FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_pm) {
    localSwitch = FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_kp;
  } else {
    localSwitch = Fu_tiPFuRailExtLeakEngRunDlyIn;
  }

  /* MinMax: '<S16>/MinMax' incorporates:
   *  Constant: '<S16>/ConstVal'
   *  Constant: '<S16>/Fu_SampleTiMid_SC'
   *  DataTypeConversion: '<S16>/Data Type Conversion1'
   *  Sum: '<S16>/Sum'
   */
  localtmp = ((UInt32)Fu_SampleTiMid_SC) * 41943U;
  localrtmax = localSwitch - (((localtmp & 2097152U) != 0U) + ((SInt32)
    (localtmp >> 22U)));
  if (0 > localrtmax) {
    localrtmax = 0;
  }

  /* DataTypeConversion: '<S16>/Data Type Conversion2' */
  if (localrtmax <= 0) {
    localSwitch = 0U;
  } else {
    localSwitch = (UInt16)localrtmax;
  }

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Fu_pFuRailDifExtLeakThd_C'
   *  Constant: '<S16>/Fu_tiPFuRailExtLeakEngRunDly_C_1'
   *  RelationalOperator: '<S16>/Relational Operator2'
   */
  if (FuSysExtLeakDiag_B.VEMS_vidGET7 < Fu_pFuRailDifExtLeakThd_C) {
    localSwitch = Fu_tiPFuRailExtLeakEngRunDly_C;
  }

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Fu_tiPFuRailExtLeakEngRunDly_C'
   */
  if (Fu_bStrtDiagExtLeakEngRun) {
    Fu_tiPFuRailExtLeakEngRunDly = Fu_tiPFuRailExtLeakEngRunDly_C;
  } else {
    Fu_tiPFuRailExtLeakEngRunDly = localSwitch;
  }
}

/* Update for atomic system: '<S9>/01_DlyAcvDiagRun' */
void FuSysExt_u_DlyAcvDiagRun_Update(void)
{
  /* Update for UnitDelay: '<S21>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_kp = Fu_tiPFuRailExtLeakEngRunDly;

  /* Update for UnitDelay: '<S20>/Unit Delay' incorporates:
   *  Constant: '<S19>/Constant3'
   */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_pm = TRUE;
}

/* Output and update for atomic system: '<S9>/02_SavePFuRailRun' */
void FuSysExtLeakDi_u_SavePFuRailRun(void)
{
  /* Switch: '<S17>/Switch1' incorporates:
   *  UnitDelay: '<S22>/Unit Delay'
   */
  if (Fu_bStrtDiagExtLeakEngRun) {
    Fu_pFuRailExtLeakEngRunMem = FuSysExtLeakDiag_B.VEMS_vidGET5;
  } else {
    Fu_pFuRailExtLeakEngRunMem = FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_i4;
  }

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_i4 = Fu_pFuRailExtLeakEngRunMem;
}

/* Output and update for atomic system: '<S9>/03_IfGARRun' */
void FuSysExtLeakDiag_u_IfGARRun(void)
{
  SInt32 localtmp;
  UInt32 localtmp_0;
  UInt16 localtmp_1;

  /* Sum: '<S18>/Sum2' */
  localtmp = Fu_pFuRailExtLeakEngRunMem - FuSysExtLeakDiag_B.VEMS_vidGET5;
  if (localtmp <= 0) {
    Fu_pFuRailGrdExtLeakEngRun = 0U;
  } else {
    Fu_pFuRailGrdExtLeakEngRun = (UInt16)localtmp;
  }

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S18>/ConstVal'
   *  Constant: '<S18>/ConstVal_1'
   *  Constant: '<S18>/ConstVal_2'
   *  Constant: '<S18>/ConstVal_3'
   *  Constant: '<S18>/ConstVal_4'
   *  Constant: '<S18>/Fu_pFuRailGrdExtLkEngRunGThd_C'
   *  Constant: '<S18>/Fu_pFuRailGrdExtLkEngRunOfsThd_C'
   *  Constant: '<S18>/Fu_tiPFuRailExtLeakEngRunDly_C'
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/offset1'
   *  Constant: '<S23>/one_on_slope'
   *  DataTypeConversion: '<S18>/Data Type Conversion1'
   *  DataTypeConversion: '<S18>/Data Type Conversion3'
   *  DataTypeConversion: '<S23>/OutDTConv'
   *  Logic: '<S18>/Logical Operator7'
   *  MinMax: '<S18>/MinMax'
   *  Product: '<S23>/Product4'
   *  Product: '<S24>/Divide'
   *  RelationalOperator: '<S18>/Relational Operator1'
   *  RelationalOperator: '<S18>/Relational Operator2'
   *  RelationalOperator: '<S18>/Relational Operator3'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S23>/Add2'
   */
  if ((Fu_tiPFuRailExtLeakEngRunDly > 0) && (Fu_tiPFuRailExtLeakEngRunDly <
       Fu_tiPFuRailExtLeakEngRunDly_C)) {
    FuSysExtLeakDiag_B.Switch2_h[0] = TRUE;
    localtmp_0 = (UInt32)(((UInt16)((((((Float32)Fu_pFuRailExtLeakEngRunMem)
      * 781.25F) * (((Float32)Fu_pFuRailGrdExtLkEngRunGThd_C) *
                    3.921568859E-003F)) * 1.279999968E-003F) + 0.5F)) +
      Fu_pFuRailGrdExtLkEngRunOfsThd_C);
    if (localtmp_0 > 65535U) {
      localtmp_1 = MAX_uint16_T;
    } else {
      localtmp_1 = (UInt16)localtmp_0;
    }

    FuSysExtLeakDiag_B.Switch2_h[1] = (Fu_pFuRailGrdExtLeakEngRun > localtmp_1);
  } else {
    FuSysExtLeakDiag_B.Switch2_h[0] = FALSE;
    FuSysExtLeakDiag_B.Switch2_h[1] = FALSE;
  }
}

/* Outputs for enable system: '<S8>/01_FuSysExtLeakEngRunDiag' */
void FuSysE_u_FuSysExtLeakEngRunDiag(void)
{
  if (Fu_bAcvExtLeakEngRunDiag) {
    /* Outputs for atomic SubSystem: '<S9>/01_DlyAcvDiagRun' */
    FuSysExtLeakDia_u_DlyAcvDiagRun();

    /* end of Outputs for SubSystem: '<S9>/01_DlyAcvDiagRun' */

    /* Outputs for atomic SubSystem: '<S9>/02_SavePFuRailRun' */
    FuSysExtLeakDi_u_SavePFuRailRun();

    /* end of Outputs for SubSystem: '<S9>/02_SavePFuRailRun' */

    /* Outputs for atomic SubSystem: '<S9>/03_IfGARRun' */
    FuSysExtLeakDiag_u_IfGARRun();

    /* end of Outputs for SubSystem: '<S9>/03_IfGARRun' */
  }
}

/* Update for enable system: '<S8>/01_FuSysExtLeakEngRunDiag' */
void u_FuSysExtLeakEngRunDiag_Update(void)
{
  if (Fu_bAcvExtLeakEngRunDiag) {
    /* Update for atomic SubSystem: '<S9>/01_DlyAcvDiagRun' */
    FuSysExt_u_DlyAcvDiagRun_Update();

    /* end of Update for SubSystem: '<S9>/01_DlyAcvDiagRun' */
  }
}

/* Outputs for atomic system: '<S10>/01_DlyAcvDiagStall' */
void FuSysExtLeakD_u_DlyAcvDiagStall(void)
{
  SInt32 localrtmax;
  UInt16 localSwitch_g;
  UInt32 localtmp;

  /* Switch: '<S28>/Switch' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  if (FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_d) {
    localSwitch_g = FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_h;
  } else {
    localSwitch_g = Fu_tiPFuRailExtLeakEngStallDlyIn;
  }

  /* MinMax: '<S25>/MinMax' incorporates:
   *  Constant: '<S25>/ConstVal'
   *  Constant: '<S25>/Fu_SampleTiMid_SC'
   *  DataTypeConversion: '<S25>/Data Type Conversion3'
   *  Sum: '<S25>/Sum'
   */
  localtmp = ((UInt32)Fu_SampleTiMid_SC) * 41943U;
  localrtmax = localSwitch_g - (((localtmp & 2097152U) != 0U) + ((SInt32)
    (localtmp >> 22U)));
  if (0 > localrtmax) {
    localrtmax = 0;
  }

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Fu_pFuRailExtLeakMinThd_C'
   *  Constant: '<S25>/Fu_tiPFuRailExtLeakEngStallDly_C'
   *  DataTypeConversion: '<S25>/Data Type Conversion2'
   *  Logic: '<S25>/OU14'
   *  RelationalOperator: '<S25>/Relational Operator1'
   */
  if ((FuSysExtLeakDiag_B.VEMS_vidGET5 > Fu_pFuRailExtLeakMinThd_C) &&
      Fu_bStrtDiagExtLeakEngStall) {
    Fu_tiPFuRailExtLeakEngStallDly = Fu_tiPFuRailExtLeakEngStallDly_C;
  } else if (localrtmax <= 0) {
    Fu_tiPFuRailExtLeakEngStallDly = 0U;
  } else {
    Fu_tiPFuRailExtLeakEngStallDly = (UInt16)localrtmax;
  }
}

/* Update for atomic system: '<S10>/01_DlyAcvDiagStall' */
void FuSysE_u_DlyAcvDiagStall_Update(void)
{
  /* Update for UnitDelay: '<S30>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_h = Fu_tiPFuRailExtLeakEngStallDly;

  /* Update for UnitDelay: '<S29>/Unit Delay' incorporates:
   *  Constant: '<S28>/Constant3'
   */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_d = TRUE;
}

/* Output and update for atomic system: '<S10>/02_SavePFuRailStall' */
void FuSysExtLeak_u_SavePFuRailStall(void)
{
  /* Switch: '<S26>/Switch1' incorporates:
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if (Fu_bStrtDiagExtLeakEngStall) {
    Fu_pFuRailExtLeakEngStallMem = FuSysExtLeakDiag_B.VEMS_vidGET5;
  } else {
    Fu_pFuRailExtLeakEngStallMem = FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_i;
  }

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_i = Fu_pFuRailExtLeakEngStallMem;
}

/* Output and update for atomic system: '<S10>/03_IfGARStall' */
void FuSysExtLeakDiag_u_IfGARStall(void)
{
  Float32 localtmp;
  UInt16 localtmp_0;
  SInt32 localtmp_1;

  /* Sum: '<S27>/Sum2' */
  localtmp_1 = Fu_pFuRailExtLeakEngStallMem - FuSysExtLeakDiag_B.VEMS_vidGET5;
  if (localtmp_1 <= 0) {
    Fu_pFuRailGrdExtLeakEngStall = 0U;
  } else {
    Fu_pFuRailGrdExtLeakEngStall = (UInt16)localtmp_1;
  }

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S27>/ConstVal'
   *  Constant: '<S27>/ConstVal_1'
   *  Constant: '<S27>/ConstVal_2'
   *  Constant: '<S27>/ConstVal_3'
   *  Constant: '<S27>/Fu_tiPFuRailExtLeakEngStallDly_C'
   *  Constant: '<S33>/offset'
   *  Constant: '<S33>/offset1'
   *  Constant: '<S33>/one_on_slope'
   *  DataTypeConversion: '<S33>/OutDTConv'
   *  Logic: '<S27>/Logical Operator7'
   *  Lookup_n-D: '<S32>/Lookup Table (n-D)'
   *  Product: '<S33>/Product4'
   *  RelationalOperator: '<S27>/Relational Operator1'
   *  RelationalOperator: '<S27>/Relational Operator2'
   *  RelationalOperator: '<S27>/Relational Operator3'
   *  Sum: '<S33>/Add1'
   *  Sum: '<S33>/Add2'
   */
  if ((Fu_tiPFuRailExtLeakEngStallDly > 0) && (Fu_tiPFuRailExtLeakEngStallDly <
       Fu_tiPFuRailExtLeakEngStallDly_C)) {
    FuSysExtLeakDiag_B.Switch2[0] = TRUE;
    localtmp = (1.279999968E-003F * look1_iu16lfIf_binlcs
                (Fu_pFuRailExtLeakEngStallMem,
                 (&(Fu_pFuRailExtLeakEngStallMem_A[0])),
                 (&(Fu_pFuRailGrdExtLkEngStallThd_T[0])), 8U)) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localtmp_0 = (UInt16)localtmp;
      } else {
        localtmp_0 = 0U;
      }
    } else {
      localtmp_0 = MAX_uint16_T;
    }

    FuSysExtLeakDiag_B.Switch2[1] = (Fu_pFuRailGrdExtLeakEngStall > localtmp_0);
  } else {
    FuSysExtLeakDiag_B.Switch2[0] = FALSE;
    FuSysExtLeakDiag_B.Switch2[1] = FALSE;
  }
}

/* Outputs for enable system: '<S8>/02_FuSysExtLeakEngStallDiag' */
void FuSy_u_FuSysExtLeakEngStallDiag(void)
{
  if (Fu_bAcvExtLeakEngStallDiag) {
    /* Outputs for atomic SubSystem: '<S10>/01_DlyAcvDiagStall' */
    FuSysExtLeakD_u_DlyAcvDiagStall();

    /* end of Outputs for SubSystem: '<S10>/01_DlyAcvDiagStall' */

    /* Outputs for atomic SubSystem: '<S10>/02_SavePFuRailStall' */
    FuSysExtLeak_u_SavePFuRailStall();

    /* end of Outputs for SubSystem: '<S10>/02_SavePFuRailStall' */

    /* Outputs for atomic SubSystem: '<S10>/03_IfGARStall' */
    FuSysExtLeakDiag_u_IfGARStall();

    /* end of Outputs for SubSystem: '<S10>/03_IfGARStall' */
  }
}

/* Update for enable system: '<S8>/02_FuSysExtLeakEngStallDiag' */
void u_FuSysExtLeakEngStallDi_Update(void)
{
  if (Fu_bAcvExtLeakEngStallDiag) {
    /* Update for atomic SubSystem: '<S10>/01_DlyAcvDiagStall' */
    FuSysE_u_DlyAcvDiagStall_Update();

    /* end of Update for SubSystem: '<S10>/01_DlyAcvDiagStall' */
  }
}

/* Output and update for atomic system: '<S8>/03_FuSysStabPrail' */
void FuSysExtLeakDi_u_FuSysStabPrail(void)
{
  Boolean localRelationalOperator3_a;
  Boolean localRelationalOperator2_a;
  Boolean localRelationalOperator1_a;
  UInt32 localSwitch2;
  SInt32 localAdd2_d;
  UInt32 locallocalSwitch;
  SInt32 localq;

  /* Sum: '<S11>/Add1' incorporates:
   *  UnitDelay: '<S34>/Unit Delay'
   */
  localAdd2_d = FuSysExtLeakDiag_B.VEMS_vidGET4 -
    FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_k;

  /* Abs: '<S11>/Abs1' */
  if (localAdd2_d < 0) {
    Fu_pFuReqDiff = (UInt16)(-localAdd2_d);
  } else {
    Fu_pFuReqDiff = (UInt16)localAdd2_d;
  }

  /* Sum: '<S11>/Add2' incorporates:
   *  UnitDelay: '<S35>/Unit Delay'
   */
  if (FuSysExtLeakDiag_B.VEMS_vidGET3 > 2147483647U) {
    localAdd2_d = MAX_int32_T;
  } else {
    localAdd2_d = (SInt32)FuSysExtLeakDiag_B.VEMS_vidGET3;
  }

  if (FuSysExtLeakDiag_DWork.UnitDelay_DSTATE > 2147483647U) {
    localq = MAX_int32_T;
  } else {
    localq = (SInt32)FuSysExtLeakDiag_DWork.UnitDelay_DSTATE;
  }

  localAdd2_d -= localq;

  /* Abs: '<S11>/Abs2' */
  if (localAdd2_d < 0) {
    localSwitch2 = (UInt32)(-localAdd2_d);
  } else {
    localSwitch2 = (UInt32)localAdd2_d;
  }

  /* RelationalOperator: '<S11>/Relational Operator3' incorporates:
   *  Constant: '<S11>/Fu_mFuReqDiff_C'
   */
  localRelationalOperator3_a = (localSwitch2 <= Fu_mFuReqDiff_C);

  /* Sum: '<S36>/Sum1' incorporates:
   *  Constant: '<S11>/Fu_SampleTiMid_SC'
   *  Constant: '<S11>/Fu_tiTransPFuReq_C'
   */
  localSwitch2 = Fu_tiTransPFuReq_C + ((UInt32)Fu_SampleTiMid_SC);
  if (localSwitch2 < Fu_tiTransPFuReq_C) {
    localSwitch2 = MAX_uint32_T;
  }

  /* RelationalOperator: '<S11>/Relational Operator2' incorporates:
   *  Constant: '<S11>/Fu_pFuReqDiff_C'
   */
  localRelationalOperator2_a = (Fu_pFuReqDiff <= Fu_pFuReqDiff_C);

  /* Switch: '<S36>/Switch2' incorporates:
   *  Logic: '<S36>/Logical Operator2'
   *  Logic: '<S36>/Logical Operator4'
   *  UnitDelay: '<S37>/Unit Delay'
   *  UnitDelay: '<S39>/Unit Delay'
   */
  if (!((localRelationalOperator2_a) &&
        (!FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_f))) {
    localSwitch2 = FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_p;
  }

  /* Sum: '<S36>/Sum' incorporates:
   *  Constant: '<S11>/Fu_SampleTiMid_SC'
   */
  locallocalSwitch = localSwitch2 - ((UInt32)Fu_SampleTiMid_SC);
  if (locallocalSwitch > localSwitch2) {
    locallocalSwitch = 0U;
  }

  /* Switch: '<S36>/Switch3' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant4'
   *  RelationalOperator: '<S36>/Relational Operator3'
   */
  if (0U >= locallocalSwitch) {
    Fu_tiTransPFuReqDly = 0U;
  } else {
    Fu_tiTransPFuReqDly = locallocalSwitch;
  }

  /* RelationalOperator: '<S11>/Relational Operator1' incorporates:
   *  Constant: '<S11>/ConstVal'
   */
  localRelationalOperator1_a = (Fu_tiTransPFuReqDly > 0U);

  /* Logic: '<S11>/Logical Operator1' */
  Fu_bStabMFuReq = ((localRelationalOperator3_a) && (localRelationalOperator1_a));

  /* Logic: '<S11>/Logical Operator7' */
  Fu_bStabPFuReq = ((localRelationalOperator2_a) && (localRelationalOperator1_a));

  /* Logic: '<S11>/OU5' incorporates:
   *  Constant: '<S11>/Fu_bAcvExtLeakEngRunDiag_C'
   *  Constant: '<S11>/Fu_nEngMinLeakEngRunDiag_C'
   *  Inport: '<Root>/FRM_bInhFuSysExtLeakDiag'
   *  Logic: '<S11>/OU1'
   *  Logic: '<S11>/OU6'
   *  RelationalOperator: '<S11>/Relational Operator4'
   */
  Fu_bAcvExtLeakEngRunDiag = (((((((FuSysExtLeakDiag_B.VEMS_vidGET2 >=
    Fu_nEngMinLeakEngRunDiag_C) && FuSysExtLeakDiag_B.VEMS_vidGET1) &&
    (!GDGAR_bGetFRM(FRM_FRM_INHFUSYSEXTLEAKDIAG))) && Fu_bAcvExtLeakEngRunDiag_C)
    && (!FuSysExtLeakDiag_B.VEMS_vidGET6)) && Fu_bStabMFuReq) && Fu_bStabPFuReq);

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_k = FuSysExtLeakDiag_B.VEMS_vidGET4;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE = FuSysExtLeakDiag_B.VEMS_vidGET3;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_f = localRelationalOperator2_a;

  /* Update for UnitDelay: '<S39>/Unit Delay' */
  FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_p = locallocalSwitch;
}

/* Outputs for enable system: '<S5>/01_FuSysExtLeakDiag' */
void FuSysExtLeak_u_FuSysExtLeakDiag(void)
{
  Boolean localLogicalOperator;
  Boolean localLogicalOperator_k;
  Boolean localRelationalOperator2_ee;
  Boolean localRelationalOperator3_h;
  Boolean localRelationalOperator4_i;
  Boolean localRelationalOperator5;
  if (FuSysExtLeakDiag_B.RelationalOperator) {
    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET7 */
    VEMS_vidGET(PFuCtl_pFuRailDifIClCtl, FuSysExtLeakDiag_B.VEMS_vidGET7);

    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  Constant: '<S8>/Fu_pFuRailDifExtLeakThd_C'
     */
    FuSysExtLeakDiag_B.RelationalOperator1 = (FuSysExtLeakDiag_B.VEMS_vidGET7 >
      Fu_pFuRailDifExtLeakThd_C);

    /* Logic: '<S15>/Logical Operator' incorporates:
     *  Logic: '<S15>/Logical Operator1'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    Fu_bStrtDiagExtLeakEngRun = (FuSysExtLeakDiag_B.RelationalOperator1 &&
      (!FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_b));

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET5 */
    VEMS_vidGET(PFuAcq_pFuRailMes, FuSysExtLeakDiag_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_bRun, FuSysExtLeakDiag_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_pFuReq, FuSysExtLeakDiag_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_mFuReq, FuSysExtLeakDiag_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET6 */
    VEMS_vidGET(PFuCtl_bAcvLrnInProgs, FuSysExtLeakDiag_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEng, FuSysExtLeakDiag_B.VEMS_vidGET2);

    /* Outputs for atomic SubSystem: '<S8>/03_FuSysStabPrail' */
    FuSysExtLeakDi_u_FuSysStabPrail();

    /* end of Outputs for SubSystem: '<S8>/03_FuSysStabPrail' */

    /* Outputs for enable SubSystem: '<S8>/01_FuSysExtLeakEngRunDiag' incorporates:
     *  EnablePort: '<S9>/Fu_bAcvExtLeakEngRunDiag'
     */
    FuSysE_u_FuSysExtLeakEngRunDiag();

    /* end of Outputs for SubSystem: '<S8>/01_FuSysExtLeakEngRunDiag' */

    /* Logic: '<S14>/Logical Operator' incorporates:
     *  Inport: '<Root>/FRM_bInhFuSysExtLeakDiag'
     *  Logic: '<S14>/Logical Operator1'
     *  UnitDelay: '<S42>/Unit Delay'
     */
    localLogicalOperator = ((!GDGAR_bGetFRM(FRM_FRM_INHFUSYSEXTLEAKDIAG)) &&
      FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_g);

    /* Logic: '<S12>/Logical Operator' incorporates:
     *  Logic: '<S12>/Logical Operator1'
     *  UnitDelay: '<S40>/Unit Delay'
     */
    localLogicalOperator_k = ((!FuSysExtLeakDiag_B.VEMS_vidGET1) &&
      FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_pt);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET */
    VEMS_vidGET(Code_test_action, FuSysExtLeakDiag_B.VEMS_vidGET);

    /* RelationalOperator: '<S8>/Relational Operator2' incorporates:
     *  Constant: '<S8>/CODE_TEST_INJECTEUR_1'
     */
    localRelationalOperator2_ee = (FuSysExtLeakDiag_B.VEMS_vidGET ==
      CODE_TEST_INJECTEUR_1);

    /* RelationalOperator: '<S8>/Relational Operator3' incorporates:
     *  Constant: '<S8>/CODE_TEST_INJECTEUR_2'
     */
    localRelationalOperator3_h = (FuSysExtLeakDiag_B.VEMS_vidGET ==
      CODE_TEST_INJECTEUR_2);

    /* RelationalOperator: '<S8>/Relational Operator4' incorporates:
     *  Constant: '<S8>/CODE_TEST_INJECTEUR_3'
     */
    localRelationalOperator4_i = (FuSysExtLeakDiag_B.VEMS_vidGET ==
      CODE_TEST_INJECTEUR_3);

    /* RelationalOperator: '<S8>/Relational Operator5' incorporates:
     *  Constant: '<S8>/CODE_TEST_INJECTEUR_4'
     */
    localRelationalOperator5 = (FuSysExtLeakDiag_B.VEMS_vidGET ==
      CODE_TEST_INJECTEUR_4);

    /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET8 */
    VEMS_vidGET(Srv_bActrTstEna, FuSysExtLeakDiag_B.VEMS_vidGET8);

    /* Logic: '<S8>/OU7' incorporates:
     *  Logic: '<S8>/OU6'
     */
    Fu_bActrTstInjr = (((((localRelationalOperator2_ee) ||
                          (localRelationalOperator3_h)) ||
                         (localRelationalOperator4_i)) ||
                        (localRelationalOperator5)) &&
                       FuSysExtLeakDiag_B.VEMS_vidGET8);

    /* Logic: '<S8>/OU11' incorporates:
     *  Logic: '<S13>/Logical Operator'
     *  Logic: '<S13>/Logical Operator1'
     *  Logic: '<S8>/OU10'
     *  Logic: '<S8>/OU9'
     *  UnitDelay: '<S41>/Unit Delay'
     */
    Fu_bStrtDiagExtLeakEngStall = (((localLogicalOperator) ||
      (localLogicalOperator_k)) || (((!Fu_bActrTstInjr) &&
      FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_gp) &&
      (!FuSysExtLeakDiag_B.VEMS_vidGET1)));

    /* Logic: '<S8>/OU1' incorporates:
     *  Constant: '<S8>/Fu_bAcvExtLeakEngStallDiag_C'
     *  Inport: '<Root>/FRM_bInhFuSysExtLeakDiag'
     *  Logic: '<S8>/OU2'
     *  Logic: '<S8>/OU3'
     */
    Fu_bAcvExtLeakEngStallDiag = (((!FuSysExtLeakDiag_B.VEMS_vidGET1) &&
      (!GDGAR_bGetFRM(FRM_FRM_INHFUSYSEXTLEAKDIAG))) &&
      Fu_bAcvExtLeakEngStallDiag_C);

    /* Outputs for enable SubSystem: '<S8>/02_FuSysExtLeakEngStallDiag' incorporates:
     *  EnablePort: '<S10>/Fu_bAcvExtLeakEngStallDiag'
     */
    FuSy_u_FuSysExtLeakEngStallDiag();

    /* end of Outputs for SubSystem: '<S8>/02_FuSysExtLeakEngStallDiag' */

    /* Switch: '<S8>/Switch' */
    if (Fu_bAcvExtLeakEngRunDiag) {
      localLogicalOperator = FuSysExtLeakDiag_B.Switch2_h[0];
      localLogicalOperator_k = FuSysExtLeakDiag_B.Switch2_h[1];
    } else {
      localLogicalOperator = FuSysExtLeakDiag_B.Switch2[0];
      localLogicalOperator_k = FuSysExtLeakDiag_B.Switch2[1];
    }

    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/ConstVal'
     *  Constant: '<S8>/ConstVal_1'
     *  Inport: '<Root>/FRM_bInhFuSysExtLeakDiag'
     *  Logic: '<S8>/OU4'
     *  Logic: '<S8>/OU5'
     *  Logic: '<S8>/OU8'
     */
    if (((FuSysExtLeakDiag_B.VEMS_vidGET1 && (!Fu_bAcvExtLeakEngRunDiag)) ||
         Fu_bActrTstInjr) || GDGAR_bGetFRM(FRM_FRM_INHFUSYSEXTLEAKDIAG)) {
      localLogicalOperator = FALSE;
      localLogicalOperator_k = FALSE;
    }

    /* SignalConversion: '<S8>/Signal Conversion' */
    Fu_bMonRunExtLeak_FuSys = localLogicalOperator;

    /* SignalConversion: '<S8>/Signal Conversion1' */
    Fu_bDgoExtLeak_FuSys = localLogicalOperator_k;
  }
}

/* Update for enable system: '<S5>/01_FuSysExtLeakDiag' */
void FuSys_u_FuSysExtLeakDiag_Update(void)
{
  if (FuSysExtLeakDiag_B.RelationalOperator) {
    /* Update for UnitDelay: '<S43>/Unit Delay' */
    FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_b =
      FuSysExtLeakDiag_B.RelationalOperator1;

    /* Update for enable SubSystem: '<S8>/01_FuSysExtLeakEngRunDiag' incorporates:
     *  Update for EnablePort: '<S9>/Fu_bAcvExtLeakEngRunDiag'
     */
    u_FuSysExtLeakEngRunDiag_Update();

    /* end of Update for SubSystem: '<S8>/01_FuSysExtLeakEngRunDiag' */

    /* Update for UnitDelay: '<S42>/Unit Delay' incorporates:
     *  Update for Inport: '<Root>/FRM_bInhFuSysExtLeakDiag'
     */
    FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_g = GDGAR_bGetFRM
      (FRM_FRM_INHFUSYSEXTLEAKDIAG);

    /* Update for UnitDelay: '<S40>/Unit Delay' */
    FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_pt = FuSysExtLeakDiag_B.VEMS_vidGET1;

    /* Update for UnitDelay: '<S41>/Unit Delay' */
    FuSysExtLeakDiag_DWork.UnitDelay_DSTATE_gp = Fu_bActrTstInjr;

    /* Update for enable SubSystem: '<S8>/02_FuSysExtLeakEngStallDiag' incorporates:
     *  Update for EnablePort: '<S10>/Fu_bAcvExtLeakEngStallDiag'
     */
    u_FuSysExtLeakEngStallDi_Update();

    /* end of Update for SubSystem: '<S8>/02_FuSysExtLeakEngStallDiag' */
  }
}

/* Output and update for function-call system: '<S1>/01_FuSysExtLeakDiag' */
void FuSysExtLe_u_FuSysExtLeakDiag_l(void)
{
  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<S5>/ConstVal'
   *  Constant: '<S5>/FUSYSEXTLEAKDIAG_u8Inhib'
   */
  FuSysExtLeakDiag_B.RelationalOperator = (FUSYSEXTLEAKDIAG_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S5>/01_FuSysExtLeakDiag' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  FuSysExtLeak_u_FuSysExtLeakDiag();

  /* end of Outputs for SubSystem: '<S5>/01_FuSysExtLeakDiag' */

  /* Update for enable SubSystem: '<S5>/01_FuSysExtLeakDiag' incorporates:
   *  Update for EnablePort: '<S8>/Enable'
   */
  FuSys_u_FuSysExtLeakDiag_Update();

  /* end of Update for SubSystem: '<S5>/01_FuSysExtLeakDiag' */
}

/* Start for exported function: Fu_SdlMid_ExtLeakDiag */
void Fu_SdlMid_ExtLeakDiag_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S7>/gen' incorporates:
   *  Start for SubSystem: '<S1>/01_FuSysExtLeakDiag'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu'
   *
   * Block requirements for '<S1>/01_FuSysExtLeakDiag':
   *  1. SubSystem "01_FuSysExtLeakDiag" !Trace_To : VEMS_E_11_02026_001.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_11_02026_001.01 ;
   */
}

/* Output and update for exported function: Fu_SdlMid_ExtLeakDiag */
void Fu_SdlMid_ExtLeakDiag(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S7>/gen' incorporates:
   *  SubSystem: '<S1>/01_FuSysExtLeakDiag'
   *  SubSystem: '<S1>/GDGAR_vidGdu'
   *
   * Block requirements for '<S1>/01_FuSysExtLeakDiag':
   *  1. SubSystem "01_FuSysExtLeakDiag" !Trace_To : VEMS_E_11_02026_001.01 ;
   *
   * Block requirements for '<S1>/GDGAR_vidGdu':
   *  1. SubSystem "GDGAR_vidGdu" !Trace_To : VEMS_E_11_02026_001.01 ;
   */
  FuSysExtLe_u_FuSysExtLeakDiag_l();

  /* Outputs for atomic SubSystem: '<S6>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S44>/S-Function */
  GDGAR_vidGdu(GD_DFT_EXTLEAK_FUSYS, Fu_bDgoExtLeak_FuSys,
               Fu_bMonRunExtLeak_FuSys, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S6>/GDGAR_vidGdu' */
}

/* Model initialize function */
void FuSysExtLeakDiag_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  Fu_SdlMid_ExtLeakDiag_Start();
}

#define FUSYSEXTLEAKDIAG_STOP_SEC_CODE
#include "FuSysExtLeakDiag_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
