/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjSysMgrCrk                                            */
/* !Description     : InjSysMgrCrk : Start manager                            */
/*                                                                            */
/* !Module          : InjSysMgrCrk                                            */
/*                                                                            */
/* !File            : InjSysMgrCrk.c                                          */
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
/* !Reference       : PTS_DOC_5189648 / 02                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed May 01 18:07:07 2013                              */
/*   Model name       : InjSysMgrCrk_AUTOCODE.mdl                             */
/*   Model version    : 1.204                                                 */
/*   Root subsystem   : /InjSysMgrCrk                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJSYSMGRCRK/InjSysMgrCrk.$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjSysMgrCrk.h"
#include "InjSysMgrCrk_private.h"

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
#define INJSYSMGRCRK_START_SEC_VAR_UNSPECIFIED
#include "InjSysMgrCrk_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjSysMgrCrk InjSysMgrCrk_B;

/* Block states (auto storage) */
D_Work_InjSysMgrCrk InjSysMgrCrk_DWork;

#define INJSYSMGRCRK_STOP_SEC_VAR_UNSPECIFIED
#include "InjSysMgrCrk_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJSYSMGRCRK_START_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

void InjSysMgrCrk_ASYNC1(int controlPortIdx)
{
}

void InjSysMgrCrk_ASYNC2(int controlPortIdx)
{
}

void InjSysMgrCrk_ASYNC3(int controlPortIdx)
{
  InjSysM_F01_StallToRot_StrtHP_c();
}

void InjSysMgrCrk_ASYNC7(int controlPortIdx)
{
  InjSysMgrCrk_F02_Inj_StrtHP();
}

/* Start for function-call system: '<S1>/F02_Inj_StrtHP' */
void InjSysMgrC_F02_Inj_StrtHP_Start(void)
{
  /* Start for enable SubSystem: '<S9>/F02_Inj_StrtHP' */

  /* Start for ifaction SubSystem: '<S57>/F01_Inj_StrtHPCrk' */

  /* InitializeConditions for atomic SubSystem: '<S58>/F02_StrtHPReq' */

  /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
  InjSysMgrCrk_DWork.UnitDelay_DSTATE_b = TRUE;

  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
  InjSysMgrCrk_DWork.UnitDelay_DSTATE_l = TRUE;

  /* end of InitializeConditions for SubSystem: '<S58>/F02_StrtHPReq' */

  /* end of Start for SubSystem: '<S57>/F01_Inj_StrtHPCrk' */

  /* end of Start for SubSystem: '<S9>/F02_Inj_StrtHP' */
}

/* Output and update for function-call system: '<S1>/F02_Inj_StrtHP' */
void InjSysMgrCrk_F02_Inj_StrtHP(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator;
  Boolean localRelationalOperator1_g;
  Boolean localLogicalOperator_b;
  Boolean localLogic[2];
  Boolean localUnitDelay1;
  Boolean localUnitDelay_f;
  Boolean localLogicalOperator9;
  Boolean localLogicalOperator3;
  UInt8 localMerge4;
  Boolean localRelationalOperator4;
  Boolean localRelationalOperator3;
  Boolean localSwitch;
  Boolean localSwitch2_b;
  UInt32 localAdd;
  Boolean localAssignment_a[6];
  Boolean localAssignment[6];
  SInt32 locali;
  SInt16 locallocalAdd;

  /* Outputs for enable SubSystem: '<S9>/F02_Inj_StrtHP' incorporates:
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/INJSYSMGRCRK_u8Inhib'
   *  EnablePort: '<S57>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (INJSYSMGRCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET10 */
    VEMS_vidGET(InjSys_ctTDCThdAcvInjHPst, InjSys_ctTDCThdAcvInjHPPrev);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET9 */
    VEMS_vidGET1DArray(InjSys_prm_bInhInjHPstCyl, 6, InjSys_prm_bInhInjHPCylPrev);

    /* DataTypeDuplicate Block: '<S79>/Data Type Duplicate'
     *
     * Regarding '<S79>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S79>/Data Type Duplicate1'
     *
     * Regarding '<S79>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_pFuThdAcvInjHPst, InjSysMgrCrk_B.VEMS_vidGET5_j);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_pFuRailMes, InjSysMgrCrk_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_stEru, InjSysMgrCrk_B.VEMS_vidGET2_n);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET11 */
    VEMS_vidGET(InjSys_bDetPFuThdInjHPst, InjSys_bDetPFuThdInjHPstPrev);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, InjSysMgrCrk_B.VEMS_vidGET1_k);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, InjSysMgrCrk_B.VEMS_vidGET_d);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_bAcvInjModH, InjSys_bAcvInjModHprev);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_bAcvInjModSplst, InjSys_bAcvInjModSplstPrev);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bAcvInjModSst, InjSys_bAcvInjModSstPrev);

    /* S-Function "vems_vidGET" Block: <S57>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_bFrstCrk, InjSysMgrCrk_B.VEMS_vidGET3_l);

    /* If: '<S57>/If1' incorporates:
     *  ActionPort: '<S58>/Action Port'
     *  ActionPort: '<S59>/Action Port'
     *  Constant: '<S57>/Ext_stRun_SC'
     *  RelationalOperator: '<S57>/Relational Operator1'
     *  SubSystem: '<S57>/F01_Inj_StrtHPCrk'
     *  SubSystem: '<S57>/F02_Inj_StrtnotHPCrk'
     */
    if (InjSysMgrCrk_B.VEMS_vidGET2_n != Ext_stRun_SC) {
      /* Outputs for atomic SubSystem: '<S58>/F01_StrtHPDisa' */

      /* If: '<S60>/If' incorporates:
       *  ActionPort: '<S64>/Action Port'
       *  ActionPort: '<S65>/Action Port'
       *  Logic: '<S60>/Logical Operator3'
       *  SubSystem: '<S60>/F01_DecCnt'
       *  SubSystem: '<S60>/F02_NoDecCnt'
       */
      if (((((InjSys_prm_bInhInjHPCylPrev[0] && InjSys_prm_bInhInjHPCylPrev[1]) &&
             InjSys_prm_bInhInjHPCylPrev[2]) && InjSys_prm_bInhInjHPCylPrev[3]) &&
           InjSys_prm_bInhInjHPCylPrev[4]) && InjSys_prm_bInhInjHPCylPrev[5]) {
        /* Sum: '<S64>/Add2' incorporates:
         *  Constant: '<S64>/ConstVal_1'
         */
        locallocalAdd = (SInt16)(InjSys_ctTDCThdAcvInjHPPrev - 1);

        /* MinMax: '<S64>/MinMax1' incorporates:
         *  Constant: '<S64>/ConstVal'
         */
        locallocalAdd = (SInt16)rt_MAX(locallocalAdd, 0);
        if (locallocalAdd <= 0) {
          localMerge4 = 0U;
        } else if (locallocalAdd > 255) {
          localMerge4 = MAX_uint8_T;
        } else {
          localMerge4 = (UInt8)locallocalAdd;
        }
      } else {
        /* SignalConversion: '<S65>/Signal Conversion1' */
        localMerge4 = InjSys_ctTDCThdAcvInjHPPrev;
      }

      /* RelationalOperator: '<S60>/Relational Operator5' incorporates:
       *  Constant: '<S60>/ConstVal'
       */
      InjSys_bDisaHPst = (localMerge4 <= 0);

      /* SignalConversion: '<S60>/Signal Conversion1' */
      InjSysMgrCrk_B.Merge1 = localMerge4;

      /* end of Outputs for SubSystem: '<S58>/F01_StrtHPDisa' */

      /* Outputs for atomic SubSystem: '<S58>/F02_StrtHPReq' */

      /* RelationalOperator: '<S61>/Relational Operator4' incorporates:
       *  Constant: '<S61>/InjSys_pFuRailLoThdInhHPst_C'
       */
      localRelationalOperator4 = (InjSysMgrCrk_B.VEMS_vidGET4 <
        InjSys_pFuRailLoThdInhHPst_C);

      /* UnitDelay: '<S76>/Unit Delay' */
      localLogicalOperator_b = InjSysMgrCrk_DWork.UnitDelay_DSTATE_h;

      /* Logic: '<S68>/Logical Operator' incorporates:
       *  Logic: '<S68>/Logical Operator1'
       */
      localLogicalOperator_b = ((localRelationalOperator4) &&
        (!localLogicalOperator_b));

      /* RelationalOperator: '<S67>/Relational Operator' */
      localRelationalOperator = (InjSysMgrCrk_B.VEMS_vidGET4 >=
        InjSysMgrCrk_B.VEMS_vidGET5_j);

      /* RelationalOperator: '<S67>/Relational Operator1' incorporates:
       *  Constant: '<S61>/ConstVal'
       */
      localRelationalOperator1_g = (InjSysMgrCrk_B.VEMS_vidGET4 <= 0);

      /* UnitDelay: '<S74>/Unit Delay' */
      localUnitDelay_f = InjSysMgrCrk_DWork.UnitDelay_DSTATE_b;

      /* UnitDelay: '<S75>/Unit Delay' */
      localUnitDelay1 = InjSysMgrCrk_DWork.UnitDelay_DSTATE_l;

      /* Switch: '<S72>/Switch' */
      if (!localUnitDelay1) {
        localUnitDelay_f = InjSys_bDetPFuThdInjHPstPrev;
      }

      /* RelationalOperator: '<S61>/Relational Operator3' incorporates:
       *  Constant: '<S61>/ConstVal_2'
       */
      localRelationalOperator3 = !InjSys_bDetPFuThdInjHPstPrev;

      /* UnitDelay: '<S77>/Unit Delay' */
      localUnitDelay1 = InjSysMgrCrk_DWork.UnitDelay_DSTATE_d;

      /* Logic: '<S70>/Logical Operator' incorporates:
       *  Logic: '<S69>/Logical Operator'
       *  Logic: '<S69>/Logical Operator1'
       */
      localUnitDelay1 = !((localRelationalOperator3) && (!localUnitDelay1));

      /* Switch: '<S70>/Switch1' */
      if (!localUnitDelay1) {
        localUnitDelay_f = InjSys_bDetPFuThdInjHPstPrev;
      }

      /* CombinatorialLogic: '<S70>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator != 0);
        rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_g != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_f != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = InjSysMgrCrk_ConstP.pooled6[rowidx];
        localLogic[1] = InjSysMgrCrk_ConstP.pooled6[rowidx + 8];
      }

      /* UnitDelay: '<S73>/Unit Delay' */
      localUnitDelay_f = InjSysMgrCrk_DWork.UnitDelay_DSTATE_o;

      /* Switch: '<S71>/Switch' */
      if (localUnitDelay_f) {
        localUnitDelay_f = localLogic[0];
      } else {
        localUnitDelay_f = InjSys_bDetPFuThdInjHPstPrev;
      }

      /* Switch: '<S70>/Switch' */
      if (localUnitDelay1) {
        localSwitch = localUnitDelay_f;
      } else {
        localSwitch = InjSys_bDetPFuThdInjHPstPrev;
      }

      /* RelationalOperator: '<S61>/Relational Operator2' incorporates:
       *  Constant: '<S61>/ConstVal_1'
       */
      localUnitDelay1 = !localSwitch;

      /* UnitDelay: '<S66>/UnitDelay' */
      localUnitDelay_f = InjSysMgrCrk_DWork.UnitDelay;

      /* CombinatorialLogic: '<S66>/Logic' */
      {
        UInt32 rowidx= 0;

        /* Compute the truth table row index corresponding to the input */
        rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator_b != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay1 != 0);
        rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_f != 0);

        /* Copy the appropriate row of the table into the block output vector */
        localLogic[0] = InjSysMgrCrk_ConstP.pooled6[rowidx];
        localLogic[1] = InjSysMgrCrk_ConstP.pooled6[rowidx + 8];
      }

      /* UnitDelay: '<S66>/UnitDelay1' */
      localUnitDelay1 = InjSysMgrCrk_DWork.UnitDelay_p;

      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S66>/NotCLR3'
       */
      if (localUnitDelay1) {
        localSwitch2_b = localLogic[0];
      } else {
        localSwitch2_b = FALSE;
      }

      /* Logic: '<S61>/Logical Operator9' incorporates:
       *  Constant: '<S61>/Ext_stCrk_SC'
       *  Inport: '<Root>/FRM_bInhPfuCtl'
       *  Inport: '<Root>/FRM_bInhStrtHP'
       *  Logic: '<S61>/Logical Operator1'
       *  Logic: '<S61>/Logical Operator2'
       *  Logic: '<S61>/Logical Operator4'
       *  Logic: '<S61>/Logical Operator5'
       *  Logic: '<S66>/LO3'
       *  RelationalOperator: '<S61>/Relational Operator1'
       */
      localLogicalOperator9 = (((((InjSysMgrCrk_B.VEMS_vidGET2_n == Ext_stCrk_SC)
        && InjSys_bAuthHPst) && (!InjSys_bDisaHPst)) && (!(GDGAR_bGetFRM
        (FRM_FRM_INHSTRTHP) || GDGAR_bGetFRM(FRM_FRM_INHPFUCTL)))) &&
        (!localSwitch2_b));

      /* Logic: '<S61>/Logical Operator3' incorporates:
       *  Logic: '<S61>/Logical Operator8'
       */
      localLogicalOperator3 = ((localLogicalOperator9) && (!localSwitch));

      /* SignalConversion: '<S61>/Signal Conversion1' */
      InjSysMgrCrk_B.Merge2 = localSwitch;

      /* Update for UnitDelay: '<S76>/Unit Delay' */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE_h = localRelationalOperator4;

      /* Update for UnitDelay: '<S74>/Unit Delay' */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE_b = localSwitch;

      /* Update for UnitDelay: '<S75>/Unit Delay' incorporates:
       *  Constant: '<S72>/Constant3'
       */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE_l = TRUE;

      /* Update for UnitDelay: '<S77>/Unit Delay' */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE_d = localRelationalOperator3;

      /* Update for UnitDelay: '<S73>/Unit Delay' incorporates:
       *  Constant: '<S71>/Constant3'
       */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE_o = TRUE;

      /* Update for UnitDelay: '<S66>/UnitDelay' */
      InjSysMgrCrk_DWork.UnitDelay = localSwitch2_b;

      /* Update for UnitDelay: '<S66>/UnitDelay1' incorporates:
       *  Constant: '<S66>/NotCLR2'
       */
      InjSysMgrCrk_DWork.UnitDelay_p = TRUE;

      /* end of Outputs for SubSystem: '<S58>/F02_StrtHPReq' */

      /* Outputs for atomic SubSystem: '<S58>/F03_InjModReq' */

      /* Switch: '<S62>/Switch2' incorporates:
       *  Constant: '<S62>/ConstMat'
       *  Logic: '<S62>/Logical Operator1'
       *  Logic: '<S62>/Logical Operator2'
       *  Logic: '<S62>/Logical Operator3'
       *  SignalConversion: '<S58>/Signal Conversion4'
       *  SignalConversion: '<S58>/Signal Conversion5'
       */
      if ((!InjSys_bDisaHPst) && (!InjSysMgrCrk_B.VEMS_vidGET3_l)) {
        InjSysMgrCrk_B.SignalConversion5 = InjSys_bAcvInjModHprev;
        InjSysMgrCrk_B.SignalConversion4 = InjSys_bAcvInjModSplstPrev;
        localRelationalOperator4 = InjSys_bAcvInjModSstPrev;
      } else {
        InjSysMgrCrk_B.SignalConversion5 = TRUE;
        InjSysMgrCrk_B.SignalConversion4 = FALSE;
        localRelationalOperator4 = FALSE;
      }

      /* end of Outputs for SubSystem: '<S58>/F03_InjModReq' */

      /* Outputs for atomic SubSystem: '<S58>/F04_InhInjSync' */

      /* Switch: '<S63>/Switch1' */
      if (localRelationalOperator4) {
        localMerge4 = InjSysMgrCrk_B.VEMS_vidGET_d;
      } else {
        localMerge4 = InjSysMgrCrk_B.VEMS_vidGET1_k;
      }

      /* Sum: '<S79>/Add' incorporates:
       *  Constant: '<S79>/Constant1'
       *  DataTypeConversion: '<S63>/Data Type Conversion1'
       */
      localAdd = ((UInt32)localMerge4) - 1U;

      /* Assignment: '<S79>/Assignment' incorporates:
       *  Constant: '<S79>/Constant'
       *  MinMax: '<S79>/MinMax'
       */
      for (locali = 0; locali < 6; locali++) {
        localAssignment_a[locali] = InjSys_prm_bInhInjHPCylPrev[(locali)];
      }

      localAssignment_a[(SInt32)rt_MIN(localAdd, 5U)] = localLogicalOperator3;

      /* Sum: '<S80>/Add' incorporates:
       *  Constant: '<S80>/Constant1'
       *  DataTypeConversion: '<S63>/Data Type Conversion2'
       */
      localAdd = ((UInt32)InjSysMgrCrk_B.VEMS_vidGET_d) - 1U;

      /* Assignment: '<S80>/Assignment' incorporates:
       *  Constant: '<S63>/ConstVal'
       *  Constant: '<S80>/Constant'
       *  MinMax: '<S80>/MinMax'
       */
      for (locali = 0; locali < 6; locali++) {
        localAssignment[locali] = localAssignment_a[locali];
      }

      localAssignment[(SInt32)rt_MIN(localAdd, 5U)] = FALSE;

      /* Switch: '<S63>/Switch2' incorporates:
       *  Logic: '<S78>/Logical Operator'
       *  Logic: '<S78>/Logical Operator1'
       *  UnitDelay: '<S81>/Unit Delay'
       */
      if ((!localLogicalOperator3) && InjSysMgrCrk_DWork.UnitDelay_DSTATE) {
        for (locali = 0; locali < 6; locali++) {
          InjSysMgrCrk_B.Merge4[(locali)] = localAssignment[locali];
        }
      } else {
        for (locali = 0; locali < 6; locali++) {
          InjSysMgrCrk_B.Merge4[(locali)] = localAssignment_a[locali];
        }
      }

      /* Update for UnitDelay: '<S81>/Unit Delay' */
      InjSysMgrCrk_DWork.UnitDelay_DSTATE = localLogicalOperator3;

      /* end of Outputs for SubSystem: '<S58>/F04_InhInjSync' */

      /* SignalConversion: '<S58>/Signal Conversion1' */
      InjSysMgrCrk_B.Merge3 = localLogicalOperator9;

      /* SignalConversion: '<S58>/Signal Conversion2' */
      InjSysMgrCrk_B.Merge5 = localLogicalOperator3;

      /* SignalConversion: '<S58>/Signal Conversion3' */
      InjSysMgrCrk_B.SignalConversion3 = localRelationalOperator4;
    } else {
      /* Constant: '<S59>/ConstVal_2' */
      InjSysMgrCrk_B.Merge2 = TRUE;

      /* Constant: '<S59>/ConstVal_1' */
      InjSysMgrCrk_B.Merge1 = 0U;

      /* Constant: '<S59>/ConstVal' */
      InjSysMgrCrk_B.Merge3 = FALSE;

      /* Constant: '<S59>/ConstMat' */
      for (locali = 0; locali < 6; locali++) {
        InjSysMgrCrk_B.Merge4[(locali)] = InjSysMgrCrk_ConstP.ConstMat_Value_b
          [(locali)];
      }

      /* Constant: '<S59>/ConstVal_3' */
      InjSysMgrCrk_B.Merge5 = FALSE;
    }

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvHPst, InjSysMgrCrk_B.Merge3);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_bAcvInjModH, InjSysMgrCrk_B.SignalConversion5);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_bAcvInjModSplst, InjSysMgrCrk_B.SignalConversion4);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_bAcvInjModSst, InjSysMgrCrk_B.SignalConversion3);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET4 */
    VEMS_vidSET(InjSys_bDetPFuThdInjHPst, InjSysMgrCrk_B.Merge2);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET5 */
    VEMS_vidSET(InjSys_bInhInjHPst, InjSysMgrCrk_B.Merge5);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET6 */
    VEMS_vidSET(InjSys_ctTDCThdAcvInjHPst, InjSysMgrCrk_B.Merge1);

    /* S-Function "vems_vidSET" Block: <S57>/VEMS_vidSET7 */
    VEMS_vidSET1DArray(InjSys_prm_bInhInjHPstCyl, 6, InjSysMgrCrk_B.Merge4);
  }

  /* end of Outputs for SubSystem: '<S9>/F02_Inj_StrtHP' */
}

/* Output and update for function-call system: '<S1>/F03_InhInjSyncNtAc' */
void InjSysMgrCrk_F03_InhInjSyncNtAc(void)
{
  Boolean localLogicalOperator3_g;
  Boolean localLogicalOperator1_o;
  Boolean localLogicalOperator2_i;
  UInt8 localSwitch1_f;
  UInt32 localAdd_e;
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S10>/F03_InhInjSyncNtAc' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  Constant: '<S10>/INJSYSMGRCRK_u8Inhib'
   *  EnablePort: '<S82>/Enable'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if (INJSYSMGRCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET */
    VEMS_vidGET(Eng_noCmprCyl, InjSysMgrCrk_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_bAcvInjModSst, InjSysMgrCrk_B.VEMS_vidGET3_b);

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET5 */
    VEMS_vidGET(Sync_agEng, InjSysMgrCrk_B.VEMS_vidGET5_d);

    /* Logic: '<S82>/Logical Operator3' incorporates:
     *  Constant: '<S82>/ConstVal'
     *  Constant: '<S82>/ConstVal_2'
     *  RelationalOperator: '<S82>/Relational Operator1'
     *  RelationalOperator: '<S82>/Relational Operator4'
     */
    localLogicalOperator3_g = ((0 < InjSysMgrCrk_B.VEMS_vidGET5_d) &&
      (InjSysMgrCrk_B.VEMS_vidGET5_d < 10));

    /* Logic: '<S82>/Logical Operator1' incorporates:
     *  Constant: '<S82>/ConstVal_1'
     *  Constant: '<S82>/ConstVal_3'
     *  RelationalOperator: '<S82>/Relational Operator2'
     *  RelationalOperator: '<S82>/Relational Operator5'
     */
    localLogicalOperator1_o = ((40 < InjSysMgrCrk_B.VEMS_vidGET5_d) &&
      (InjSysMgrCrk_B.VEMS_vidGET5_d < 50));

    /* Logic: '<S82>/Logical Operator2' incorporates:
     *  Constant: '<S82>/ConstVal_4'
     *  Constant: '<S82>/ConstVal_5'
     *  RelationalOperator: '<S82>/Relational Operator3'
     *  RelationalOperator: '<S82>/Relational Operator6'
     */
    localLogicalOperator2_i = ((80 < InjSysMgrCrk_B.VEMS_vidGET5_d) &&
      (InjSysMgrCrk_B.VEMS_vidGET5_d < 90));

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_noCylEng, InjSysMgrCrk_B.VEMS_vidGET6_g);

    /* Logic: '<S82>/Logical Operator4' incorporates:
     *  Constant: '<S82>/ConstVal_6'
     *  Logic: '<S82>/Logical Operator5'
     *  RelationalOperator: '<S82>/Relational Operator'
     */
    InjSys_bAgStopNoInhHP = ((((localLogicalOperator3_g) ||
      (localLogicalOperator1_o)) || (localLogicalOperator2_i)) &&
      (InjSysMgrCrk_B.VEMS_vidGET6_g == 3));

    /* Logic: '<S82>/Logical Operator6' */
    localLogicalOperator3_g = (InjSysMgrCrk_B.VEMS_vidGET3_b ||
      InjSys_bAgStopNoInhHP);

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInCyl, InjSysMgrCrk_B.VEMS_vidGET1);

    /* Switch: '<S82>/Switch1' */
    if (localLogicalOperator3_g) {
      localSwitch1_f = InjSysMgrCrk_B.VEMS_vidGET;
    } else {
      localSwitch1_f = InjSysMgrCrk_B.VEMS_vidGET1;
    }

    /* Sum: '<S83>/Add' incorporates:
     *  Constant: '<S83>/Constant1'
     *  DataTypeConversion: '<S82>/Data Type Conversion1'
     */
    localAdd_e = ((UInt32)localSwitch1_f) - 1U;

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(InjSys_prm_bInhInjHPstCyl, 6,
                       InjSysMgrCrk_B.VEMS_vidGET4_j);

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate'
     *
     * Regarding '<S83>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate1'
     *
     * Regarding '<S83>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S82>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_bInhInjHPst, InjSysMgrCrk_B.VEMS_vidGET2_m);

    /* Assignment: '<S83>/Assignment' incorporates:
     *  Constant: '<S83>/Constant'
     *  MinMax: '<S83>/MinMax'
     */
    for (locali = 0; locali < 6; locali++) {
      InjSysMgrCrk_B.Assignment[(locali)] = InjSysMgrCrk_B.VEMS_vidGET4_j
        [(locali)];
    }

    InjSysMgrCrk_B.Assignment[rt_MIN(localAdd_e, 5U)] =
      InjSysMgrCrk_B.VEMS_vidGET2_m;

    /* S-Function "vems_vidSET" Block: <S82>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_bInhInjHPstCyl, 6, InjSysMgrCrk_B.Assignment);
  }

  /* end of Outputs for SubSystem: '<S10>/F03_InhInjSyncNtAc' */
}

/* Start for exported function: InjSys_EveCkSnNtAc_InjSysMgrCrk */
void InjSys_EveCkSnNtAc_InjSysMgrCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   */

  /* Start for S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F02_Inj_StrtHP'
   *  Start for SubSystem: '<S1>/F03_InhInjSyncNtAc'
   */
  InjSysMgrC_F02_Inj_StrtHP_Start();
}

/* Output and update for exported function: InjSys_EveCkSnNtAc_InjSysMgrCrk */
void InjSys_EveCkSnNtAc_InjSysMgrCrk(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   */

  /* S-Function (fcncallgen): '<S11>/gen' incorporates:
   *  SubSystem: '<S1>/F03_InhInjSyncNtAc'
   */
  InjSysMgrCrk_ASYNC7(0);
  InjSysMgrCrk_F03_InhInjSyncNtAc();
}

/* Output and update for exported function: InjSys_EveInj_InjSysMgrCrk */
void InjSys_EveInj_InjSysMgrCrk(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' */
  InjSysMgrCrk_ASYNC7(1);
}

/*
 * Start for atomic system:
 *    '<S12>/F01_StallToRot_StrtHP'
 *    '<S8>/F01_StallToRot_StrtHP'
 */
void Inj_F01_StallToRot_StrtHP_Start(rtB_F01_StallToRot_StrtHP_InjSy *localB)
{
  SInt32 locali;

  /* Start for atomic SubSystem: '<S13>/F04_StrtHPInjIf' */

  /* Start for Constant: '<S17>/ConstMat' */
  for (locali = 0; locali < 6; locali++) {
    localB->ConstMat[(locali)] = InjSysMgrCrk_ConstP.pooled7[(locali)];
  }

  /* Start for Constant: '<S17>/ConstVal' */
  localB->ConstVal = TRUE;

  /* end of Start for SubSystem: '<S13>/F04_StrtHPInjIf' */
}

/*
 * Output and update for atomic system:
 *    '<S12>/F01_StallToRot_StrtHP'
 *    '<S8>/F01_StallToRot_StrtHP'
 */
void InjSysMgr_F01_StallToRot_StrtHP(SInt16 rtu_Ext_tCoMes, Boolean
  rtu_CoEs_bIntrSTTEsLoEngSpd, Boolean rtu_CoPTSt_bRStrtSTT, UInt16
  rtu_FuSysM_tFu, Boolean rtu_FRM_bInhPfuCtl, Boolean rtu_FRM_bInhStrtHP,
  UInt8 rtu_Eng_stEru, Boolean rtu_Ext_bFrstCrk, Boolean
  rtu_Ext_bEngReStrt, UInt16 rtu_Ext_pFuRailSplMes, Boolean
  *rty_InjSys_bAuthHPst, rtB_F01_StallToRot_StrtHP_InjSy *localB)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  UInt16 localLookUpTable_d;
  UInt16 localLookUpTable_p;
  UInt16 localLookUpTable_f;
  UInt16 localLookUpTable_dq;
  UInt16 localLookUpTable_l;
  UInt8 localLookUpTable_d4;
  UInt8 localLookUpTable_i;
  UInt8 localLookUpTable_f3;
  UInt8 localLookUpTable_c;
  UInt8 localLookUpTable_e;
  UInt8 localDataTypeConversion1;
  Boolean localLogicalOperator5_e;
  Boolean localLogicalOperator3_h;
  UInt8 localSwitch4;
  UInt16 localSwitch3;
  SInt32 locali;

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  locali = rtu_Ext_tCoMes + 40;
  if (locali <= 0) {
    localDataTypeConversion1 = 0U;
  } else if (locali > 255) {
    localDataTypeConversion1 = MAX_uint8_T;
  } else {
    localDataTypeConversion1 = (UInt8)locali;
  }

  /* Outputs for atomic SubSystem: '<S13>/F01_StrtHPCond' *
   * Block requirements for '<S13>/F01_StrtHPCond':
   *  1. SubSystem "F01_StrtHPCond" !Trace_To : VEMS_E_11_01571_001.01 ;
   *  2. SubSystem "F01_StrtHPCond" !Trace_To : VEMS_E_11_01571_002.01 ;
   */

  /* If: '<S14>/If' incorporates:
   *  ActionPort: '<S18>/Action Port'
   *  ActionPort: '<S19>/Action Port'
   *  Logic: '<S14>/Logical Operator10'
   *  SubSystem: '<S14>/F01_StrtHPCondSTT'
   *  SubSystem: '<S14>/F02_StrtHPCond'
   *
   * Block requirements for '<S14>/F02_StrtHPCond':
   *  1. SubSystem "F02_StrtHPCond" !Trace_To : VEMS_E_11_01571_003.01 ;
   */
  if (rtu_CoEs_bIntrSTTEsLoEngSpd || rtu_CoPTSt_bRStrtSTT) {
    /* Lookup: '<S20>/Look-Up Table'
     * About '<S20>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  Bias 233.0
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_e), (&(InjSys_bAuthHPStSTT_T[0])),
                  rtu_FuSysM_tFu, (&(InjSys_tFuHPSt_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S20>/Data Type Duplicate1'
     *
     * Regarding '<S20>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    localLogicalOperator5_e = (localLookUpTable_e != 0);

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/InjSys_bInhTFuelCondForHPStrt_C'
     *  Constant: '<S18>/InjSys_tCoHiThdAcvHPstSTT_C'
     *  Constant: '<S18>/InjSys_tCoLoThdAcvHPstSTT_C'
     *  Logic: '<S18>/Logical Operator4'
     *  RelationalOperator: '<S18>/Relational Operator5'
     *  RelationalOperator: '<S18>/Relational Operator6'
     */
    if (InjSys_bInhTFuelCondForHPStrt_C) {
      localLogicalOperator5_e = ((localDataTypeConversion1 >=
        InjSys_tCoLoThdAcvHPstSTT_C) && (localDataTypeConversion1 <=
        InjSys_tCoHiThdAcvHPstSTT_C));
    }

    /* Logic: '<S18>/Logical Operator5' incorporates:
     *  Constant: '<S18>/Ext_stRun_SC'
     *  Constant: '<S18>/InjSys_bInhETBHPst_C'
     *  Logic: '<S18>/Logical Operator1'
     *  Logic: '<S18>/Logical Operator10'
     *  Logic: '<S18>/Logical Operator3'
     *  Logic: '<S18>/Logical Operator9'
     *  RelationalOperator: '<S18>/Relational Operator1'
     */
    localLogicalOperator5_e = ((((localLogicalOperator5_e) &&
      ((!rtu_FRM_bInhStrtHP) && (!rtu_FRM_bInhPfuCtl))) && (rtu_Eng_stEru !=
      Ext_stRun_SC)) && (!InjSys_bInhETBHPst_C));

    /* SignalConversion: '<S18>/Signal Conversion' */
    localB->Merge2_p = localLogicalOperator5_e;

    /* SignalConversion: '<S18>/Signal Conversion1' */
    (*rty_InjSys_bAuthHPst) = localLogicalOperator5_e;
  } else {
    /* Lookup: '<S21>/Look-Up Table'
     * About '<S21>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  Bias 233.0
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_c), (&(InjSys_bAuthHPSt_T[0])),
                  rtu_FuSysM_tFu, (&(InjSys_tFuHPSt_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S21>/Data Type Duplicate1'
     *
     * Regarding '<S21>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S19>/Data Type Conversion1' */
    localLogicalOperator5_e = (localLookUpTable_c != 0);

    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/InjSys_bInhTFuelCondForHPStrt_C'
     *  Constant: '<S19>/InjSys_tCoHiThdAcvHPst_C'
     *  Constant: '<S19>/InjSys_tCoLoThdAcvHPst_C'
     *  Logic: '<S19>/Logical Operator2'
     *  RelationalOperator: '<S19>/Relational Operator5'
     *  RelationalOperator: '<S19>/Relational Operator6'
     */
    if (InjSys_bInhTFuelCondForHPStrt_C) {
      localLogicalOperator5_e = ((localDataTypeConversion1 >=
        InjSys_tCoLoThdAcvHPst_C) && (localDataTypeConversion1 <=
        InjSys_tCoHiThdAcvHPst_C));
    }

    /* Logic: '<S19>/Logical Operator5' incorporates:
     *  Constant: '<S19>/Ext_stRun_SC'
     *  Constant: '<S19>/InjSys_bInhETBHPst_C'
     *  Logic: '<S19>/Logical Operator1'
     *  Logic: '<S19>/Logical Operator10'
     *  Logic: '<S19>/Logical Operator3'
     *  Logic: '<S19>/Logical Operator4'
     *  Logic: '<S19>/Logical Operator6'
     *  RelationalOperator: '<S19>/Relational Operator7'
     */
    localLogicalOperator5_e = (((((localLogicalOperator5_e) &&
      ((!rtu_FRM_bInhStrtHP) && (!rtu_FRM_bInhPfuCtl))) && (rtu_Eng_stEru !=
      Ext_stRun_SC)) && (!InjSys_bInhETBHPst_C)) && (!rtu_Ext_bFrstCrk));

    /* SignalConversion: '<S19>/Signal Conversion' */
    localB->Merge2_p = localLogicalOperator5_e;

    /* SignalConversion: '<S19>/Signal Conversion1' */
    (*rty_InjSys_bAuthHPst) = localLogicalOperator5_e;
  }

  /* end of Outputs for SubSystem: '<S13>/F01_StrtHPCond' */

  /* Outputs for atomic SubSystem: '<S13>/F02_StrtInjMod' */

  /* If: '<S15>/If' incorporates:
   *  ActionPort: '<S22>/Action Port'
   *  ActionPort: '<S23>/Action Port'
   *  Logic: '<S15>/Logical Operator10'
   *  SubSystem: '<S15>/F01_StrtInjModSTT'
   *  SubSystem: '<S15>/F02_StrtInjModWoSTT'
   */
  if (rtu_CoEs_bIntrSTTEsLoEngSpd || rtu_CoPTSt_bRStrtSTT) {
    /* Logic: '<S22>/Logical Operator2' incorporates:
     *  Constant: '<S22>/InjSys_tCoHiThdAcvModSstSTT_C'
     *  Constant: '<S22>/InjSys_tCoLoThdAcvModSstSTT_C'
     *  RelationalOperator: '<S22>/Relational Operator2'
     *  RelationalOperator: '<S22>/Relational Operator3'
     */
    localLogicalOperator3_h = (((localDataTypeConversion1 >=
      InjSys_tCoLoThdAcvModSstSTT_C) && (localDataTypeConversion1 <=
      InjSys_tCoHiThdAcvModSstSTT_C)) && localB->Merge2_p);

    /* Switch: '<S22>/Switch3' incorporates:
     *  Constant: '<S22>/InjSys_tCoLoThdAcvModSplLPSTT_C'
     *  Constant: '<S22>/InjSys_tCoLoThdAcvModSplstSTT_C'
     */
    if (localB->Merge2_p) {
      localSwitch4 = InjSys_tCoLoThdAcvModSplstSTT_C;
    } else {
      localSwitch4 = InjSys_tCoLoThdAcvModSplLPSTT_C;
    }

    /* RelationalOperator: '<S22>/Relational Operator4' */
    localLogicalOperator5_e = (localDataTypeConversion1 >= localSwitch4);

    /* Switch: '<S22>/Switch4' incorporates:
     *  Constant: '<S22>/InjSys_tCoHiThdAcvModSplLPSTT_C'
     *  Constant: '<S22>/InjSys_tCoHiThdAcvModSplstSTT_C'
     */
    if (localB->Merge2_p) {
      localSwitch4 = InjSys_tCoHiThdAcvModSplstSTT_C;
    } else {
      localSwitch4 = InjSys_tCoHiThdAcvModSplLPSTT_C;
    }

    /* Logic: '<S22>/Logical Operator6' incorporates:
     *  Logic: '<S22>/Logical Operator12'
     *  RelationalOperator: '<S22>/Relational Operator7'
     */
    localLogicalOperator5_e = (((!localLogicalOperator3_h) &&
      (localLogicalOperator5_e)) && (localDataTypeConversion1 <= localSwitch4));

    /* Logic: '<S22>/Logical Operator11' */
    localB->Merge3 = !((localLogicalOperator3_h) || (localLogicalOperator5_e));

    /* SignalConversion: '<S22>/Signal Conversion2' */
    localB->Merge5 = localLogicalOperator5_e;

    /* SignalConversion: '<S22>/Signal Conversion3' */
    localB->Merge4 = localLogicalOperator3_h;
  } else {
    /* Logic: '<S23>/Logical Operator3' incorporates:
     *  Constant: '<S23>/InjSys_tCoHiThdAcvModSst_C'
     *  Constant: '<S23>/InjSys_tCoLoThdAcvModSst_C'
     *  RelationalOperator: '<S23>/Relational Operator1'
     *  RelationalOperator: '<S23>/Relational Operator5'
     */
    localLogicalOperator3_h = (((localDataTypeConversion1 >=
      InjSys_tCoLoThdAcvModSst_C) && (localDataTypeConversion1 <=
      InjSys_tCoHiThdAcvModSst_C)) && localB->Merge2_p);

    /* Switch: '<S23>/Switch3' incorporates:
     *  Constant: '<S23>/InjSys_tCoLoThdAcvModSplstLP_C'
     *  Constant: '<S23>/InjSys_tCoLoThdAcvModSplst_C'
     */
    if (localB->Merge2_p) {
      localSwitch4 = InjSys_tCoLoThdAcvModSplst_C;
    } else {
      localSwitch4 = InjSys_tCoLoThdAcvModSplstLP_C;
    }

    /* RelationalOperator: '<S23>/Relational Operator6' */
    localLogicalOperator5_e = (localDataTypeConversion1 >= localSwitch4);

    /* Switch: '<S23>/Switch4' incorporates:
     *  Constant: '<S23>/InjSys_tCoHiThdAcvModSplstLP_C'
     *  Constant: '<S23>/InjSys_tCoHiThdAcvModSplst_C'
     */
    if (localB->Merge2_p) {
      localSwitch4 = InjSys_tCoHiThdAcvModSplst_C;
    } else {
      localSwitch4 = InjSys_tCoHiThdAcvModSplstLP_C;
    }

    /* Logic: '<S23>/Logical Operator4' incorporates:
     *  Logic: '<S23>/Logical Operator2'
     *  RelationalOperator: '<S23>/Relational Operator7'
     */
    localLogicalOperator5_e = (((!localLogicalOperator3_h) &&
      (localLogicalOperator5_e)) && (localDataTypeConversion1 <= localSwitch4));

    /* Logic: '<S23>/Logical Operator1' */
    localB->Merge3 = !((localLogicalOperator3_h) || (localLogicalOperator5_e));

    /* SignalConversion: '<S23>/Signal Conversion1' */
    localB->Merge5 = localLogicalOperator5_e;

    /* SignalConversion: '<S23>/Signal Conversion4' */
    localB->Merge4 = localLogicalOperator3_h;
  }

  /* end of Outputs for SubSystem: '<S13>/F02_StrtInjMod' */

  /* Outputs for atomic SubSystem: '<S13>/F03_pRailThd' *
   * Block requirements for '<S13>/F03_pRailThd':
   *  1. SubSystem "F03_pRailThd" !Trace_To : VEMS_E_11_01571_004.01 ;
   */

  /* If: '<S16>/If' incorporates:
   *  ActionPort: '<S24>/Action Port'
   *  ActionPort: '<S25>/Action Port'
   *  Logic: '<S16>/Logical Operator10'
   *  SubSystem: '<S16>/F01_pRailThdSTT'
   *  SubSystem: '<S16>/F02_pRailThdWoSTT'
   */
  if (rtu_CoEs_bIntrSTTEsLoEngSpd || rtu_CoPTSt_bRStrtSTT) {
    /* Lookup: '<S26>/Look-Up Table'
     * About '<S26>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_f3), (&(InjSys_ctTDCThdAcvInjHPstSTT_T[0])),
                 localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S26>/Data Type Duplicate1'
     *
     * Regarding '<S26>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S27>/Look-Up Table'
     * About '<S27>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_f), (&(InjSys_pFuThdAcvInjModHSTT_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate1'
     *
     * Regarding '<S27>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S28>/Look-Up Table'
     * About '<S28>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_dq), (&(InjSys_pFuThdAcvInjModSSTT_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate1'
     *
     * Regarding '<S28>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S29>/Look-Up Table'
     * About '<S29>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_l), (&(InjSys_pFuThdAcvInjModSplSTT_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate1'
     *
     * Regarding '<S29>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* SignalConversion: '<S24>/Signal Conversion' */
    localB->Merge2 = localLookUpTable_f3;

    /* Switch: '<S24>/Switch1' incorporates:
     *  Lookup: '<S27>/Look-Up Table'
     *  Lookup: '<S28>/Look-Up Table'
     */
    if (localB->Merge4) {
      localSwitch3 = localLookUpTable_dq;
    } else {
      localSwitch3 = localLookUpTable_f;
    }

    /* Switch: '<S24>/Switch3' incorporates:
     *  Logic: '<S24>/Logical Operator'
     *  Lookup: '<S29>/Look-Up Table'
     */
    if (localB->Merge5) {
      localSwitch3 = localLookUpTable_l;
    }

    /* Switch: '<S24>/Switch2' incorporates:
     *  Constant: '<S24>/InjSys_pFuThAcvInjLPSt_C'
     */
    if (localB->Merge2_p) {
      localB->Merge1 = localSwitch3;
    } else {
      localB->Merge1 = InjSys_pFuThAcvInjLPSt_C;
    }
  } else {
    /* Lookup: '<S30>/Look-Up Table'
     * About '<S30>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_d4), (&(InjSys_ctTDCThdAcvInjHPRstrt_T[0])),
                 localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate1'
     *
     * Regarding '<S30>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S31>/Look-Up Table'
     * About '<S31>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U8( &(localLookUpTable_i), (&(InjSys_ctTDCThdAcvInjHPst_T[0])),
                 localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate1'
     *
     * Regarding '<S31>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S32>/Look-Up Table'
     * About '<S32>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable), (&(InjSys_pFuThdAcvInjModH_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate1'
     *
     * Regarding '<S32>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S33>/Look-Up Table'
     * About '<S33>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_d), (&(InjSys_pFuThdAcvInjModS_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate1'
     *
     * Regarding '<S33>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup: '<S34>/Look-Up Table'
     * About '<S34>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U8  Bias -40.0
     * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U8( &(localLookUpTable_p), (&(InjSys_pFuThdAcvInjModSpl_T[0])),
                  localDataTypeConversion1, (&(Ext_tCoMes_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate1'
     *
     * Regarding '<S34>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Switch: '<S25>/Switch1' incorporates:
     *  Lookup: '<S32>/Look-Up Table'
     *  Lookup: '<S33>/Look-Up Table'
     */
    if (localB->Merge4) {
      localSwitch3 = localLookUpTable_d;
    } else {
      localSwitch3 = localLookUpTable;
    }

    /* Switch: '<S25>/Switch2' incorporates:
     *  Logic: '<S25>/Logical Operator1'
     *  Lookup: '<S30>/Look-Up Table'
     *  Lookup: '<S31>/Look-Up Table'
     */
    if (!rtu_Ext_bEngReStrt) {
      localB->Merge2 = localLookUpTable_i;
    } else {
      localB->Merge2 = localLookUpTable_d4;
    }

    /* Switch: '<S25>/Switch3' incorporates:
     *  Logic: '<S25>/Logical Operator'
     *  Lookup: '<S34>/Look-Up Table'
     */
    if (localB->Merge5) {
      localSwitch3 = localLookUpTable_p;
    }

    /* Switch: '<S25>/Switch4' incorporates:
     *  Constant: '<S25>/InjSys_pFuThAcvInjLPSt_C'
     */
    if (localB->Merge2_p) {
      localB->Merge1 = localSwitch3;
    } else {
      localB->Merge1 = InjSys_pFuThAcvInjLPSt_C;
    }
  }

  /* end of Outputs for SubSystem: '<S13>/F03_pRailThd' */

  /* Outputs for atomic SubSystem: '<S13>/F04_StrtHPInjIf' */

  /* Constant: '<S17>/ConstMat' */
  for (locali = 0; locali < 6; locali++) {
    localB->ConstMat[(locali)] = InjSysMgrCrk_ConstP.pooled7[(locali)];
  }

  /* Constant: '<S17>/ConstVal' */
  localB->ConstVal = TRUE;

  /* RelationalOperator: '<S17>/Relational Operator6' */
  localB->RelationalOperator6 = (rtu_Ext_pFuRailSplMes > localB->Merge1);

  /* end of Outputs for SubSystem: '<S13>/F04_StrtHPInjIf' */
}

/* Start for function-call system: '<S1>/F01_StallToRot_StrtHP' */
void I_F01_StallToRot_StrtHP_l_Start(void)
{
  /* Start for enable SubSystem: '<S7>/F01_StallToRot_StrtHP' */

  /* Start for atomic SubSystem: '<S12>/F01_StallToRot_StrtHP' */
  Inj_F01_StallToRot_StrtHP_Start(&InjSysMgrCrk_B.F01_StallToRot_StrtHP_n);

  /* end of Start for SubSystem: '<S12>/F01_StallToRot_StrtHP' */

  /* end of Start for SubSystem: '<S7>/F01_StallToRot_StrtHP' */
}

/* Output and update for function-call system: '<S1>/F01_StallToRot_StrtHP' */
void InjSysM_F01_StallToRot_StrtHP_c(void)
{
  /* Outputs for enable SubSystem: '<S7>/F01_StallToRot_StrtHP' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/INJSYSMGRCRK_u8Inhib'
   *  EnablePort: '<S12>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (INJSYSMGRCRK_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET6 */
    VEMS_vidGET(Ext_tCoMes, InjSysMgrCrk_B.VEMS_vidGET6_b);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET7 */
    VEMS_vidGET(FuSysM_tFu, InjSysMgrCrk_B.VEMS_vidGET7_n);

    /* DataTypeConversion Block: '<S20>/Data Type Conversion'
     *
     * Regarding '<S20>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S21>/Data Type Conversion'
     *
     * Regarding '<S21>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_bFrstCrk, InjSysMgrCrk_B.VEMS_vidGET4_px);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_bEngReStrt, InjSysMgrCrk_B.VEMS_vidGET3_o);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_pFuRailSplMes, InjSysMgrCrk_B.VEMS_vidGET5_h);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET1 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysMgrCrk_B.VEMS_vidGET1_o);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET2 */
    VEMS_vidGET(Eng_stEru, InjSysMgrCrk_B.VEMS_vidGET2_c);

    /* S-Function "vems_vidGET" Block: <S12>/VEMS_vidGET */
    VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjSysMgrCrk_B.VEMS_vidGET_k);

    /* Outputs for atomic SubSystem: '<S12>/F01_StallToRot_StrtHP' */
    InjSysMgr_F01_StallToRot_StrtHP(InjSysMgrCrk_B.VEMS_vidGET6_b,
      InjSysMgrCrk_B.VEMS_vidGET_k, InjSysMgrCrk_B.VEMS_vidGET1_o,
      InjSysMgrCrk_B.VEMS_vidGET7_n, GDGAR_bGetFRM(FRM_FRM_INHPFUCTL),
      GDGAR_bGetFRM(FRM_FRM_INHSTRTHP), InjSysMgrCrk_B.VEMS_vidGET2_c,
      InjSysMgrCrk_B.VEMS_vidGET4_px, InjSysMgrCrk_B.VEMS_vidGET3_o,
      InjSysMgrCrk_B.VEMS_vidGET5_h, &InjSys_bAuthHPst,
      &InjSysMgrCrk_B.F01_StallToRot_StrtHP_n);

    /* end of Outputs for SubSystem: '<S12>/F01_StallToRot_StrtHP' */

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvHPst, InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge2_p);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_bAcvInjModH,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge3);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_bAcvInjModSplst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge5);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_bAcvInjModSst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge4);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET4 */
    VEMS_vidSET(InjSys_bDetPFuThdInjHPst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.RelationalOperator6);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET5 */
    VEMS_vidSET(InjSys_bInhInjHPst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.ConstVal);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET6 */
    VEMS_vidSET(InjSys_ctTDCThdAcvInjHPst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge2);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET7 */
    VEMS_vidSET(InjSys_pFuThdAcvInjHPst,
                InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.Merge1);

    /* S-Function "vems_vidSET" Block: <S12>/VEMS_vidSET8 */
    VEMS_vidSET1DArray(InjSys_prm_bInhInjHPstCyl, 6,
                       InjSysMgrCrk_B.F01_StallToRot_StrtHP_n.ConstMat);
  }

  /* end of Outputs for SubSystem: '<S7>/F01_StallToRot_StrtHP' */
}

/* Output and update for exported function: InjSys_EveRTSt_InjSysMgrCrk */
void InjSys_EveRTSt_InjSysMgrCrk(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' */
  InjSysMgrCrk_ASYNC3(1);
}

/* Start for function-call system: '<S1>/F01_StallToRot_StrtHP_init' */
void F01_StallToRot_StrtHP_ini_Start(void)
{
  /* Start for atomic SubSystem: '<S8>/F01_StallToRot_StrtHP' */
  Inj_F01_StallToRot_StrtHP_Start(&InjSysMgrCrk_B.F01_StallToRot_StrtHP_d);

  /* end of Start for SubSystem: '<S8>/F01_StallToRot_StrtHP' */

  /* DataTypeConversion Block: '<S42>/Data Type Conversion'
   *
   * Regarding '<S42>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S43>/Data Type Conversion'
   *
   * Regarding '<S43>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */
}

/* Output and update for function-call system: '<S1>/F01_StallToRot_StrtHP_init' */
void InjS_F01_StallToRot_StrtHP_init(void)
{
  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET6 */
  VEMS_vidGET(Ext_tCoMes, InjSysMgrCrk_B.VEMS_vidGET6);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET7 */
  VEMS_vidGET(FuSysM_tFu, InjSysMgrCrk_B.VEMS_vidGET7);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET4 */
  VEMS_vidGET(Ext_bFrstCrk, InjSysMgrCrk_B.VEMS_vidGET4_p);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET3 */
  VEMS_vidGET(Ext_bEngReStrt, InjSysMgrCrk_B.VEMS_vidGET3);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET5 */
  VEMS_vidGET(Ext_pFuRailSplMes, InjSysMgrCrk_B.VEMS_vidGET5);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET1 */
  VEMS_vidGET(CoPTSt_bRStrtSTT, InjSysMgrCrk_B.VEMS_vidGET1_h);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET2 */
  VEMS_vidGET(Eng_stEru, InjSysMgrCrk_B.VEMS_vidGET2);

  /* S-Function "vems_vidGET" Block: <S8>/VEMS_vidGET */
  VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, InjSysMgrCrk_B.VEMS_vidGET_f);

  /* Outputs for atomic SubSystem: '<S8>/F01_StallToRot_StrtHP' */
  InjSysMgr_F01_StallToRot_StrtHP(InjSysMgrCrk_B.VEMS_vidGET6,
    InjSysMgrCrk_B.VEMS_vidGET_f, InjSysMgrCrk_B.VEMS_vidGET1_h,
    InjSysMgrCrk_B.VEMS_vidGET7, GDGAR_bGetFRM(FRM_FRM_INHPFUCTL), GDGAR_bGetFRM
                                  (FRM_FRM_INHSTRTHP),
    InjSysMgrCrk_B.VEMS_vidGET2, InjSysMgrCrk_B.VEMS_vidGET4_p,
    InjSysMgrCrk_B.VEMS_vidGET3, InjSysMgrCrk_B.VEMS_vidGET5, &InjSys_bAuthHPst,
    &InjSysMgrCrk_B.F01_StallToRot_StrtHP_d);

  /* end of Outputs for SubSystem: '<S8>/F01_StallToRot_StrtHP' */

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET */
  VEMS_vidSET(InjSys_bAcvHPst, InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge2_p);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_bAcvInjModH, InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge3);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_bAcvInjModSplst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge5);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET3 */
  VEMS_vidSET(InjSys_bAcvInjModSst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge4);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET4 */
  VEMS_vidSET(InjSys_bDetPFuThdInjHPst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.RelationalOperator6);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET5 */
  VEMS_vidSET(InjSys_bInhInjHPst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.ConstVal);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET6 */
  VEMS_vidSET(InjSys_ctTDCThdAcvInjHPst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge2);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET7 */
  VEMS_vidSET(InjSys_pFuThdAcvInjHPst,
              InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.Merge1);

  /* S-Function "vems_vidSET" Block: <S8>/VEMS_vidSET8 */
  VEMS_vidSET1DArray(InjSys_prm_bInhInjHPstCyl, 6,
                     InjSysMgrCrk_B.F01_StallToRot_StrtHP_d.ConstMat);
}

/* Start for exported function: InjSys_EveRst_InjSysMgrCrk */
void InjSys_EveRst_InjSysMgrCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_StallToRot_StrtHP_init'
   */
  F01_StallToRot_StrtHP_ini_Start();
}

/* Output and update for exported function: InjSys_EveRst_InjSysMgrCrk */
void InjSys_EveRst_InjSysMgrCrk(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_StallToRot_StrtHP_init'
   */
  InjS_F01_StallToRot_StrtHP_init();
}

/* Start for exported function: InjSys_EveStTR_InjSysMgrCrk */
void InjSys_EveStTR_InjSysMgrCrk_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_StallToRot_StrtHP'
   */
  I_F01_StallToRot_StrtHP_l_Start();
}

/* Output and update for exported function: InjSys_EveStTR_InjSysMgrCrk */
void InjSys_EveStTR_InjSysMgrCrk(void)
{
  /* S-Function (fcncallgen): '<S6>/expFcn' */
  InjSysMgrCrk_ASYNC3(0);
}

/* Model initialize function */
void InjSysMgrCrk_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  InjSys_EveCkSnNtAc_InjSysMgrCrk_Start();
  InjSys_EveRst_InjSysMgrCrk_Start();
  InjSys_EveStTR_InjSysMgrCrk_Start();
}

#define INJSYSMGRCRK_STOP_SEC_CODE
#include "InjSysMgrCrk_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
