/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkMgrCorRbl                                            */
/* !Description     : CORRECTION RUMBLE                                       */
/*                                                                            */
/* !Module          : KnkMgrCorRbl                                            */
/*                                                                            */
/* !File            : KnkMgrCorRbl.c                                          */
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
/* !Reference       : PTS_DOC_6144313 / 03                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Mar 04 09:56:31 2014                              */
/*   Model name       : KnkMgrCorRbl_AUTOCODE.mdl                             */
/*   Model version    : 1.303                                                 */
/*   Root subsystem   : /KnkMgrCorRbl                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKMGRCORRBL/KnkM$*/
/* $Revision::   1.7                                                         $*/
/* $Author::   mbenfrad                               $$Date::   04 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "KnkMgrCorRbl.h"
#include "KnkMgrCorRbl_private.h"

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
#define KNKMGRCORRBL_START_SEC_VAR_UNSPECIFIED
#include "KnkMgrCorRbl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_KnkMgrCorRbl KnkMgrCorRbl_B;

/* Block states (auto storage) */
D_Work_KnkMgrCorRbl KnkMgrCorRbl_DWork;

#define KNKMGRCORRBL_STOP_SEC_VAR_UNSPECIFIED
#include "KnkMgrCorRbl_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define KNKMGRCORRBL_START_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

void KnkMgrCorRbl_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S1>/F06_Previous' */
void KnkMgrCorRbl_F06_Previous(void)
{
  /* Outputs for enable SubSystem: '<S10>/F06_Previous' incorporates:
   *  Constant: '<S10>/ConstVal'
   *  Constant: '<S10>/KNKMGRCORRBL_u8Inhib'
   *  EnablePort: '<S100>/Enable'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  if (KNKMGRCORRBL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S100>/VEMS_vidGET */
    VEMS_vidGET1DArray(KnkMgt_ctPerdRbl, 4, KnkMgt_ctPerdRbl_prev);

    /* S-Function "vems_vidGET" Block: <S100>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(KnkMgt_idxMinPosnRbl, 4, KnkMgt_idxMinPosnRbl_prev);

    /* S-Function "vems_vidGET" Block: <S100>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(KnkMgt_prm_bInjCutOffRblCyl, 4,
                       KnkMgt_prm_bInjCutOffRblCyl_prev);

    /* S-Function "vems_vidGET" Block: <S100>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(KnkMgt_ctTDCInjCutOff, 4, KnkMgt_ctTDCInjCutOff_prev);
  }

  /* end of Outputs for SubSystem: '<S10>/F06_Previous' */
}

/* Start for function-call system: '<S1>/F01_BenchMode' */
void KnkMgrCorRb_F01_BenchMode_Start(void)
{
  /* Start for enable SubSystem: '<S4>/F01_BenchMode' */

  /* Start for enable SubSystem: '<S16>/F01_RblTestBenchCyl1' */

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  KnkMgrCorRbl_DWork.UnitDelay_DSTATE_p = 1U;

  /* end of Start for SubSystem: '<S16>/F01_RblTestBenchCyl1' */

  /* Start for enable SubSystem: '<S16>/F02_RblTestBenchCyl2' */

  /* InitializeConditions for UnitDelay: '<S29>/Unit Delay' */
  KnkMgrCorRbl_DWork.UnitDelay_DSTATE_e = 1U;

  /* end of Start for SubSystem: '<S16>/F02_RblTestBenchCyl2' */

  /* Start for enable SubSystem: '<S16>/F03_RblTestBenchCyl3' */

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
  KnkMgrCorRbl_DWork.UnitDelay_DSTATE_n = 1U;

  /* end of Start for SubSystem: '<S16>/F03_RblTestBenchCyl3' */

  /* Start for enable SubSystem: '<S16>/F04_RblTestBenchCyl4' */

  /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
  KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a = 1U;

  /* end of Start for SubSystem: '<S16>/F04_RblTestBenchCyl4' */

  /* end of Start for SubSystem: '<S4>/F01_BenchMode' */
}

/* Output and update for function-call system: '<S1>/F01_BenchMode' */
void KnkMgrCorRbl_F01_BenchMode(void)
{
  /* local block i/o variables */
  UInt8 localLookUpTable;
  UInt8 localLookUpTable_o;
  UInt8 localLookUpTable_j;
  UInt8 localLookUpTable_h;
  Boolean localRelationalOperator_k;
  UInt8 localSwitch1_jj;
  UInt8 localtmp[4];
  SInt32 localtmp_0;
  UInt8 localtmp_1;

  /* Outputs for enable SubSystem: '<S4>/F01_BenchMode' incorporates:
   *  Constant: '<S4>/ConstVal'
   *  Constant: '<S4>/KNKMGRCORRBL_u8Inhib'
   *  EnablePort: '<S16>/Enable'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  if (KNKMGRCORRBL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET3 */
    VEMS_vidGET(KnkRbl_noCyl, KnkMgrCorRbl_B.VEMS_vidGET3_f);

    /* Outputs for enable SubSystem: '<S16>/F01_RblTestBenchCyl1' incorporates:
     *  Constant: '<S16>/ConstVal_1'
     *  Constant: '<S16>/KnkMgt_bRblETB_C'
     *  EnablePort: '<S17>/NS_Enable'
     *  Logic: '<S16>/Logical Operator'
     *  RelationalOperator: '<S16>/Relational Operator1'
     */
    if (KnkMgt_bRblETB_C && (KnkMgrCorRbl_B.VEMS_vidGET3_f == 0)) {
      /* Sum: '<S17>/Add' incorporates:
       *  Constant: '<S17>/ConstVal'
       *  UnitDelay: '<S25>/Unit Delay'
       */
      localtmp_0 = 1 + KnkMgrCorRbl_DWork.UnitDelay_DSTATE_ep;
      if (((UInt32)localtmp_0) > 255U) {
        localSwitch1_jj = MAX_uint8_T;
      } else {
        localSwitch1_jj = (UInt8)localtmp_0;
      }

      /* UnitDelay: '<S26>/Unit Delay' */
      KnkMgt_ctIdxETBCyl1Prev = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_p;

      /* RelationalOperator: '<S17>/Relational Operator' incorporates:
       *  Constant: '<S17>/ConstVal_3'
       */
      localRelationalOperator_k = (KnkMgt_ctIdxETBCyl1Prev <= 0);

      /* Switch: '<S17>/Switch' incorporates:
       *  UnitDelay: '<S25>/Unit Delay'
       */
      if (!localRelationalOperator_k) {
        localSwitch1_jj = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_ep;
      }

      /* Switch: '<S17>/swith' incorporates:
       *  Constant: '<S17>/ConstVal_2'
       *  Constant: '<S17>/KnkMgt_idxMaxETBCyl1_C'
       *  RelationalOperator: '<S17>/Relational Operator1'
       */
      if ((localSwitch1_jj + -1) >= KnkMgt_idxMaxETBCyl1_C) {
        KnkMgt_idxETBCyl1 = 0U;
      } else {
        KnkMgt_idxETBCyl1 = localSwitch1_jj;
      }

      /* Lookup: '<S23>/Look-Up Table'
       * About '<S23>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable_h), (&(KnkMgt_ctIdxETBCyl1_T[0])),
                   KnkMgt_idxETBCyl1, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate1'
       *
       * Regarding '<S23>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Switch: '<S17>/Switch1' incorporates:
       *  Lookup: '<S23>/Look-Up Table'
       */
      if (localRelationalOperator_k) {
        localSwitch1_jj = localLookUpTable_h;
      } else {
        localSwitch1_jj = KnkMgt_ctIdxETBCyl1Prev;
      }

      /* Sum: '<S17>/Add1' incorporates:
       *  Constant: '<S17>/ConstVal_1'
       */
      localtmp_0 = localSwitch1_jj - 1;
      if (localtmp_0 <= 0) {
        KnkMgt_ctIdxETBCyl1 = 0U;
      } else {
        KnkMgt_ctIdxETBCyl1 = (UInt8)localtmp_0;
      }

      /* Lookup: '<S24>/Look-Up Table'
       * About '<S24>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(KnkMgt_stRblCyl1), (&(KnkMgt_stKnkETBCyl1_T[0])),
                   KnkMgt_idxETBCyl1, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate1'
       *
       * Regarding '<S24>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Update for UnitDelay: '<S25>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_ep = KnkMgt_idxETBCyl1;

      /* Update for UnitDelay: '<S26>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_p = KnkMgt_ctIdxETBCyl1;
    }

    /* end of Outputs for SubSystem: '<S16>/F01_RblTestBenchCyl1' */

    /* Outputs for enable SubSystem: '<S16>/F02_RblTestBenchCyl2' incorporates:
     *  Constant: '<S16>/ConstVal'
     *  Constant: '<S16>/KnkMgt_bRblETB_C_1'
     *  EnablePort: '<S18>/NS_Enable'
     *  Logic: '<S16>/Logical Operator1'
     *  RelationalOperator: '<S16>/Relational Operator2'
     */
    if (KnkMgt_bRblETB_C && (KnkMgrCorRbl_B.VEMS_vidGET3_f == 1)) {
      /* Sum: '<S18>/Add' incorporates:
       *  Constant: '<S18>/ConstVal'
       *  UnitDelay: '<S30>/Unit Delay'
       */
      localtmp_0 = 1 + KnkMgrCorRbl_DWork.UnitDelay_DSTATE_k;
      if (((UInt32)localtmp_0) > 255U) {
        localSwitch1_jj = MAX_uint8_T;
      } else {
        localSwitch1_jj = (UInt8)localtmp_0;
      }

      /* UnitDelay: '<S29>/Unit Delay' */
      KnkMgt_ctIdxETBCyl2Prev = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_e;

      /* RelationalOperator: '<S18>/Relational Operator' incorporates:
       *  Constant: '<S18>/ConstVal_3'
       */
      localRelationalOperator_k = (KnkMgt_ctIdxETBCyl2Prev <= 0);

      /* Switch: '<S18>/Switch' incorporates:
       *  UnitDelay: '<S30>/Unit Delay'
       */
      if (!localRelationalOperator_k) {
        localSwitch1_jj = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_k;
      }

      /* Switch: '<S18>/swith' incorporates:
       *  Constant: '<S18>/ConstVal_2'
       *  Constant: '<S18>/KnkMgt_idxMaxETBCyl2_C'
       *  RelationalOperator: '<S18>/Relational Operator1'
       */
      if ((localSwitch1_jj + -1) >= KnkMgt_idxMaxETBCyl2_C) {
        KnkMgt_idxETBCyl2 = 0U;
      } else {
        KnkMgt_idxETBCyl2 = localSwitch1_jj;
      }

      /* Lookup: '<S27>/Look-Up Table'
       * About '<S27>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable_j), (&(KnkMgt_ctIdxETBCyl2_T[0])),
                   KnkMgt_idxETBCyl2, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate1'
       *
       * Regarding '<S27>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Switch: '<S18>/Switch1' incorporates:
       *  Lookup: '<S27>/Look-Up Table'
       */
      if (localRelationalOperator_k) {
        localSwitch1_jj = localLookUpTable_j;
      } else {
        localSwitch1_jj = KnkMgt_ctIdxETBCyl2Prev;
      }

      /* Sum: '<S18>/Add1' incorporates:
       *  Constant: '<S18>/ConstVal_1'
       */
      localtmp_0 = localSwitch1_jj - 1;
      if (localtmp_0 <= 0) {
        KnkMgt_ctIdxETBCyl2 = 0U;
      } else {
        KnkMgt_ctIdxETBCyl2 = (UInt8)localtmp_0;
      }

      /* Lookup: '<S28>/Look-Up Table'
       * About '<S28>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(KnkMgt_stRblCyl2), (&(KnkMgt_stKnkETBCyl2_T[0])),
                   KnkMgt_idxETBCyl2, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate1'
       *
       * Regarding '<S28>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Update for UnitDelay: '<S30>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_k = KnkMgt_idxETBCyl2;

      /* Update for UnitDelay: '<S29>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_e = KnkMgt_ctIdxETBCyl2;
    }

    /* end of Outputs for SubSystem: '<S16>/F02_RblTestBenchCyl2' */

    /* Outputs for enable SubSystem: '<S16>/F03_RblTestBenchCyl3' incorporates:
     *  Constant: '<S16>/ConstVal_2'
     *  Constant: '<S16>/KnkMgt_bRblETB_C_2'
     *  EnablePort: '<S19>/NS_Enable'
     *  Logic: '<S16>/Logical Operator2'
     *  RelationalOperator: '<S16>/Relational Operator3'
     */
    if (KnkMgt_bRblETB_C && (KnkMgrCorRbl_B.VEMS_vidGET3_f == 2)) {
      /* Sum: '<S19>/Add' incorporates:
       *  Constant: '<S19>/ConstVal'
       *  UnitDelay: '<S34>/Unit Delay'
       */
      localtmp_0 = 1 + KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a1;
      if (((UInt32)localtmp_0) > 255U) {
        localSwitch1_jj = MAX_uint8_T;
      } else {
        localSwitch1_jj = (UInt8)localtmp_0;
      }

      /* UnitDelay: '<S33>/Unit Delay' */
      KnkMgt_ctIdxETBCyl3Prev = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_n;

      /* RelationalOperator: '<S19>/Relational Operator' incorporates:
       *  Constant: '<S19>/ConstVal_3'
       */
      localRelationalOperator_k = (KnkMgt_ctIdxETBCyl3Prev <= 0);

      /* Switch: '<S19>/Switch' incorporates:
       *  UnitDelay: '<S34>/Unit Delay'
       */
      if (!localRelationalOperator_k) {
        localSwitch1_jj = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a1;
      }

      /* Switch: '<S19>/swith' incorporates:
       *  Constant: '<S19>/ConstVal_2'
       *  Constant: '<S19>/KnkMgt_idxMaxETBCyl3_C'
       *  RelationalOperator: '<S19>/Relational Operator1'
       */
      if ((localSwitch1_jj + -1) >= KnkMgt_idxMaxETBCyl3_C) {
        KnkMgt_idxETBCyl3 = 0U;
      } else {
        KnkMgt_idxETBCyl3 = localSwitch1_jj;
      }

      /* Lookup: '<S31>/Look-Up Table'
       * About '<S31>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable_o), (&(KnkMgt_ctIdxETBCyl3_T[0])),
                   KnkMgt_idxETBCyl3, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate1'
       *
       * Regarding '<S31>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Switch: '<S19>/Switch1' incorporates:
       *  Lookup: '<S31>/Look-Up Table'
       */
      if (localRelationalOperator_k) {
        localSwitch1_jj = localLookUpTable_o;
      } else {
        localSwitch1_jj = KnkMgt_ctIdxETBCyl3Prev;
      }

      /* Sum: '<S19>/Add1' incorporates:
       *  Constant: '<S19>/ConstVal_1'
       */
      localtmp_0 = localSwitch1_jj - 1;
      if (localtmp_0 <= 0) {
        KnkMgt_ctIdxETBCyl3 = 0U;
      } else {
        KnkMgt_ctIdxETBCyl3 = (UInt8)localtmp_0;
      }

      /* Lookup: '<S32>/Look-Up Table'
       * About '<S32>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(KnkMgt_stRblCyl3), (&(KnkMgt_stKnkETBCyl3_T[0])),
                   KnkMgt_idxETBCyl3, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate1'
       *
       * Regarding '<S32>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Update for UnitDelay: '<S34>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a1 = KnkMgt_idxETBCyl3;

      /* Update for UnitDelay: '<S33>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_n = KnkMgt_ctIdxETBCyl3;
    }

    /* end of Outputs for SubSystem: '<S16>/F03_RblTestBenchCyl3' */

    /* Outputs for enable SubSystem: '<S16>/F04_RblTestBenchCyl4' incorporates:
     *  Constant: '<S16>/ConstVal_3'
     *  Constant: '<S16>/KnkMgt_bRblETB_C_3'
     *  EnablePort: '<S20>/NS_Enable'
     *  Logic: '<S16>/Logical Operator3'
     *  RelationalOperator: '<S16>/Relational Operator4'
     */
    if (KnkMgt_bRblETB_C && (KnkMgrCorRbl_B.VEMS_vidGET3_f == 3)) {
      /* Sum: '<S20>/Add' incorporates:
       *  Constant: '<S20>/ConstVal'
       *  UnitDelay: '<S38>/Unit Delay'
       */
      localtmp_0 = 1 + KnkMgrCorRbl_DWork.UnitDelay_DSTATE_l;
      if (((UInt32)localtmp_0) > 255U) {
        localSwitch1_jj = MAX_uint8_T;
      } else {
        localSwitch1_jj = (UInt8)localtmp_0;
      }

      /* UnitDelay: '<S37>/Unit Delay' */
      KnkMgt_ctIdxETBCyl4Prev = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a;

      /* RelationalOperator: '<S20>/Relational Operator' incorporates:
       *  Constant: '<S20>/ConstVal_3'
       */
      localRelationalOperator_k = (KnkMgt_ctIdxETBCyl4Prev <= 0);

      /* Switch: '<S20>/Switch' incorporates:
       *  UnitDelay: '<S38>/Unit Delay'
       */
      if (!localRelationalOperator_k) {
        localSwitch1_jj = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_l;
      }

      /* Switch: '<S20>/swith' incorporates:
       *  Constant: '<S20>/ConstVal_2'
       *  Constant: '<S20>/KnkMgt_idxMaxETBCyl4_C'
       *  RelationalOperator: '<S20>/Relational Operator1'
       */
      if ((localSwitch1_jj + -1) >= KnkMgt_idxMaxETBCyl4_C) {
        KnkMgt_idxETBCyl4 = 0U;
      } else {
        KnkMgt_idxETBCyl4 = localSwitch1_jj;
      }

      /* Lookup: '<S35>/Look-Up Table'
       * About '<S35>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(localLookUpTable), (&(KnkMgt_ctIdxETBCyl4_T[0])),
                   KnkMgt_idxETBCyl4, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate1'
       *
       * Regarding '<S35>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Switch: '<S20>/Switch1' incorporates:
       *  Lookup: '<S35>/Look-Up Table'
       */
      if (localRelationalOperator_k) {
        localSwitch1_jj = localLookUpTable;
      } else {
        localSwitch1_jj = KnkMgt_ctIdxETBCyl4Prev;
      }

      /* Sum: '<S20>/Add1' incorporates:
       *  Constant: '<S20>/ConstVal_1'
       */
      localtmp_0 = localSwitch1_jj - 1;
      if (localtmp_0 <= 0) {
        KnkMgt_ctIdxETBCyl4 = 0U;
      } else {
        KnkMgt_ctIdxETBCyl4 = (UInt8)localtmp_0;
      }

      /* Lookup: '<S36>/Look-Up Table'
       * About '<S36>/Look-Up Table':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U8_U8( &(KnkMgt_stRblCyl4), (&(KnkMgt_stKnkETBCyl4_T[0])),
                   KnkMgt_idxETBCyl4, (&(KnkMgt_idxBkptETB_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate1'
       *
       * Regarding '<S36>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Update for UnitDelay: '<S38>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_l = KnkMgt_idxETBCyl4;

      /* Update for UnitDelay: '<S37>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_a = KnkMgt_ctIdxETBCyl4;
    }

    /* end of Outputs for SubSystem: '<S16>/F04_RblTestBenchCyl4' */
    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(Detection_rbl, 4, KnkMgrCorRbl_B.VEMS_vidGET2_d);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(Detection_fort_cliquetis, 4,
                       KnkMgrCorRbl_B.VEMS_vidGET1_n0);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET */
    VEMS_vidGET1DArray(Detection_cliquetis, 4, KnkMgrCorRbl_B.VEMS_vidGET_h);

    /* S-Function "vems_vidGET" Block: <S16>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(KnkMgt_prm_bInjCutOffRblCyl, 4,
                       KnkMgrCorRbl_B.VEMS_vidGET4_f);

    /* Outputs for enable SubSystem: '<S16>/F05_RblBenchCoord' incorporates:
     *  Constant: '<S16>/KnkMgt_bRblETB_C_4'
     *  EnablePort: '<S21>/NS_Enable'
     */
    if (KnkMgt_bRblETB_C) {
      /* Selector: '<S21>/Selector4' incorporates:
       *  DataTypeConversion: '<S21>/DTC2'
       */
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      Detection_cliquetis_CurCyl = KnkMgrCorRbl_B.VEMS_vidGET_h[localtmp_1 - 1];

      /* Selector: '<S21>/Selector3' incorporates:
       *  DataTypeConversion: '<S21>/DTC3'
       */
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      Detection_fort_cliq_CurCyl = KnkMgrCorRbl_B.VEMS_vidGET1_n0[localtmp_1 - 1];

      /* Selector: '<S21>/Selector2' incorporates:
       *  DataTypeConversion: '<S21>/DTC4'
       */
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      Detection_rbl_CurCyl = KnkMgrCorRbl_B.VEMS_vidGET2_d[localtmp_1 - 1];

      /* Selector: '<S21>/Selector' incorporates:
       *  DataTypeConversion: '<S21>/DTC1'
       */
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      KnkMgt_bInjCutOffRblCurCyl = KnkMgrCorRbl_B.VEMS_vidGET4_f[localtmp_1 - 1];

      /* Selector: '<S21>/Selector1' incorporates:
       *  DataTypeConversion: '<S21>/DTC5'
       *  SignalConversion: '<S21>/TmpSignal ConversionAtSelector1Inport1'
       */
      localtmp[0] = KnkMgt_stRblCyl1;
      localtmp[1] = KnkMgt_stRblCyl2;
      localtmp[2] = KnkMgt_stRblCyl3;
      localtmp[3] = KnkMgt_stRblCyl4;
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      KnkMgt_stRblCurCyl = localtmp[localtmp_1 - 1];

      /* Switch: '<S21>/swith18' incorporates:
       *  Constant: '<S21>/ConstVal_1'
       */
      if (KnkMgt_bInjCutOffRblCurCyl) {
        localSwitch1_jj = 0U;
      } else {
        localSwitch1_jj = KnkMgt_stRblCurCyl;
      }

      /* Switch: '<S21>/swith19' incorporates:
       *  Constant: '<S21>/ConstVal_2'
       */
      if (Detection_rbl_CurCyl) {
        localSwitch1_jj = 2U;
      }

      /* Switch: '<S21>/swith1' incorporates:
       *  Constant: '<S21>/ConstVal'
       */
      if (Detection_fort_cliq_CurCyl) {
        localSwitch1_jj = 1U;
      }

      /* Switch: '<S21>/swith20' incorporates:
       *  Constant: '<S21>/ConstVal_3'
       */
      if (Detection_cliquetis_CurCyl) {
        localSwitch1_jj = 0U;
      }

      /* Assignment: '<S21>/Assignment' incorporates:
       *  Constant: '<S21>/ConstVal_5'
       *  DataTypeConversion: '<S21>/DTC6'
       *  RelationalOperator: '<S21>/Relational Operator9'
       *  UnitDelay: '<S40>/Unit Delay'
       */
      Detection_fort_cliquetis_bench[0] =
        KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[0];
      Detection_rbl_bench[0] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[0];
      Detection_fort_cliquetis_bench[1] =
        KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[1];
      Detection_rbl_bench[1] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[1];
      Detection_fort_cliquetis_bench[2] =
        KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[2];
      Detection_rbl_bench[2] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[2];
      Detection_fort_cliquetis_bench[3] =
        KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[3];
      Detection_rbl_bench[3] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[3];
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      Detection_fort_cliquetis_bench[localtmp_1 - 1] = (localSwitch1_jj == 1);

      /* Assignment: '<S21>/Assignment1' incorporates:
       *  Constant: '<S21>/ConstVal_4'
       *  DataTypeConversion: '<S21>/DTC7'
       *  RelationalOperator: '<S21>/Relational Operator8'
       *  UnitDelay: '<S39>/Unit Delay'
       */
      localtmp_0 = KnkMgrCorRbl_B.VEMS_vidGET3_f + 1;
      if (((UInt32)localtmp_0) > 255U) {
        localtmp_1 = MAX_uint8_T;
      } else {
        localtmp_1 = (UInt8)localtmp_0;
      }

      Detection_rbl_bench[localtmp_1 - 1] = (localSwitch1_jj == 2);

      /* Update for UnitDelay: '<S40>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[0] =
        Detection_fort_cliquetis_bench[0];

      /* Update for UnitDelay: '<S39>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[0] = Detection_rbl_bench[0];

      /* Update for UnitDelay: '<S40>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[1] =
        Detection_fort_cliquetis_bench[1];

      /* Update for UnitDelay: '<S39>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[1] = Detection_rbl_bench[1];

      /* Update for UnitDelay: '<S40>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[2] =
        Detection_fort_cliquetis_bench[2];

      /* Update for UnitDelay: '<S39>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[2] = Detection_rbl_bench[2];

      /* Update for UnitDelay: '<S40>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aw[3] =
        Detection_fort_cliquetis_bench[3];

      /* Update for UnitDelay: '<S39>/Unit Delay' */
      KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c5[3] = Detection_rbl_bench[3];
    }

    /* end of Outputs for SubSystem: '<S16>/F05_RblBenchCoord' */

    /* Switch: '<S22>/swith21' incorporates:
     *  Constant: '<S22>/KnkMgt_bRblETB_C'
     */
    if (KnkMgt_bRblETB_C) {
      Detection_rbl_Cfm[0] = Detection_rbl_bench[0];
      Detection_rbl_Cfm[1] = Detection_rbl_bench[1];
      Detection_rbl_Cfm[2] = Detection_rbl_bench[2];
      Detection_rbl_Cfm[3] = Detection_rbl_bench[3];
    } else {
      Detection_rbl_Cfm[0] = KnkMgrCorRbl_B.VEMS_vidGET2_d[0];
      Detection_rbl_Cfm[1] = KnkMgrCorRbl_B.VEMS_vidGET2_d[1];
      Detection_rbl_Cfm[2] = KnkMgrCorRbl_B.VEMS_vidGET2_d[2];
      Detection_rbl_Cfm[3] = KnkMgrCorRbl_B.VEMS_vidGET2_d[3];
    }

    /* Switch: '<S22>/swith22' incorporates:
     *  Constant: '<S22>/KnkMgt_bRblETB_C_1'
     */
    if (KnkMgt_bRblETB_C) {
      Detection_fort_cliquetis_Cfm[0] = Detection_fort_cliquetis_bench[0];
      Detection_fort_cliquetis_Cfm[1] = Detection_fort_cliquetis_bench[1];
      Detection_fort_cliquetis_Cfm[2] = Detection_fort_cliquetis_bench[2];
      Detection_fort_cliquetis_Cfm[3] = Detection_fort_cliquetis_bench[3];
    } else {
      Detection_fort_cliquetis_Cfm[0] = KnkMgrCorRbl_B.VEMS_vidGET1_n0[0];
      Detection_fort_cliquetis_Cfm[1] = KnkMgrCorRbl_B.VEMS_vidGET1_n0[1];
      Detection_fort_cliquetis_Cfm[2] = KnkMgrCorRbl_B.VEMS_vidGET1_n0[2];
      Detection_fort_cliquetis_Cfm[3] = KnkMgrCorRbl_B.VEMS_vidGET1_n0[3];
    }
  }

  /* end of Outputs for SubSystem: '<S4>/F01_BenchMode' */
}

/*
 * Output and update for action system:
 *    '<S50>/If Action Subsystem'
 *    '<S51>/If Action Subsystem'
 *    '<S87>/If Action Subsystem'
 *    '<S88>/If Action Subsystem'
 *    '<S93>/If Action Subsystem'
 */
void KnkMgrCorRbl_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S54>/Value 1' */
  (*rty_Out1) = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S50>/If Action Subsystem1'
 *    '<S51>/If Action Subsystem1'
 *    '<S87>/If Action Subsystem1'
 *    '<S88>/If Action Subsystem1'
 *    '<S93>/If Action Subsystem1'
 */
void KnkMgrCorRbl_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S55>/Value 2' */
  (*rty_Out1) = rtu_0;
}

/* Output and update for function-call system: '<S1>/F02_RblCount' */
void KnkMgrCorRbl_F02_RblCount(void)
{
  /* local block i/o variables */
  UInt16 localMinMax_e;
  UInt16 localLookUpTable2D;
  UInt16 localSelector1_pj;
  UInt8 localDTC5;
  Boolean localRelationalOperator_pl;
  Boolean localSelector1_p0;
  SInt32 localpluIdx;
  UInt8 localSwitch5;
  SInt16 localSwitch;
  Boolean localLogicalOperator3_l;
  SInt16 localSwitch2_p;
  Boolean localLogicalOperator4;
  SInt32 localSwitch1_c;
  Boolean localLogicalOperator1_k;
  UInt32 localAdd;
  Float32 localSwitch1_o;
  UInt32 localPrelookup_o2;
  SInt32 localq;
  UInt32 localqY;
  UInt16 locallocalDataTypeConversion;

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/ConstVal'
   *  Constant: '<S7>/KNKMGRCORRBL_u8Inhib'
   */
  localRelationalOperator_pl = (KNKMGRCORRBL_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S7>/F02_RblCount' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  if (localRelationalOperator_pl) {
    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, KnkMgrCorRbl_B.VEMS_vidGET1);

    /* PreLookup: '<S66>/Prelookup' */
    localSwitch5 = plook_u8u16u32n31_binca_f(KnkMgrCorRbl_B.VEMS_vidGET1,
      (&(KnkMgt_nEngNbZoneRbl_A[0])), 2U, &localPrelookup_o2);

    /* Sum: '<S46>/Add1' incorporates:
     *  Constant: '<S46>/ConstVal'
     */
    localq = localSwitch5 + 1;
    if (((UInt32)localq) > 255U) {
      KnkMgt_nbNEngZoneRbl = MAX_uint8_T;
    } else {
      KnkMgt_nbNEngZoneRbl = (UInt8)localq;
    }

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET */
    VEMS_vidGET(EngM_rTotLdExCor, KnkMgrCorRbl_B.VEMS_vidGET);

    /* DataTypeConversion Block: '<S58>/Data Type Conversion1'
     *
     * Regarding '<S58>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate1'
     *
     * Regarding '<S58>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S59>/Data Type Conversion1'
     *
     * Regarding '<S59>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate1'
     *
     * Regarding '<S59>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S60>/Data Type Conversion1'
     *
     * Regarding '<S60>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate1'
     *
     * Regarding '<S60>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S63>/Data Type Conversion1'
     *
     * Regarding '<S63>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate1'
     *
     * Regarding '<S63>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S64>/Data Type Conversion1'
     *
     * Regarding '<S64>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate1'
     *
     * Regarding '<S64>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* PreLookup: '<S67>/Prelookup' */
    localSwitch5 = plook_u8u16u32n31_binca_f(KnkMgrCorRbl_B.VEMS_vidGET,
      (&(KnkMgt_rAirLdNbZoneRbl_A[0])), 2U, &localPrelookup_o2);

    /* Sum: '<S46>/Add2' incorporates:
     *  Constant: '<S46>/ConstVal_1'
     */
    localq = localSwitch5 + 1;
    if (((UInt32)localq) > 255U) {
      KnkMgt_nbRLdZoneRbl = MAX_uint8_T;
    } else {
      KnkMgt_nbRLdZoneRbl = (UInt8)localq;
    }

    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET2 */
    VEMS_vidGET(KnkRbl_noCyl, KnkMgrCorRbl_B.VEMS_vidGET2_i);

    /* Outputs for atomic SubSystem: '<S41>/F01_RblDetCurCyl' *
     * Block requirements for '<S41>/F01_RblDetCurCyl':
     *  1. SubSystem "F01_RblDetCurCyl" !Trace_To : VEMS_E_10_02583_007.01 ;
     */

    /* DataTypeConversion: '<S43>/DTC3' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i;
    localqY = (UInt32)(localq + 1);
    if (localqY < ((UInt32)localq)) {
      localqY = MAX_uint32_T;
    }

    /* If: '<S50>/If' incorporates:
     *  ActionPort: '<S54>/Action Port'
     *  ActionPort: '<S55>/Action Port'
     *  Constant: '<S43>/KnkMgt_nEngSuperKnkHiThd_C'
     *  Constant: '<S43>/KnkMgt_nEngSuperKnkLoThd_C'
     *  RelationalOperator: '<S50>/Relational Operator'
     *  RelationalOperator: '<S50>/Relational Operator1'
     *  SubSystem: '<S50>/If Action Subsystem'
     *  SubSystem: '<S50>/If Action Subsystem1'
     */
    if (KnkMgt_nEngSuperKnkLoThd_C >= KnkMgrCorRbl_B.VEMS_vidGET1) {
      KnkMgrCorRbl_IfActionSubsystem(FALSE, &KnkRbl_bNEngHiSuperKnk);
    } else {
      if (KnkMgrCorRbl_B.VEMS_vidGET1 >= KnkMgt_nEngSuperKnkHiThd_C) {
        KnkMgrCorRbl_IfActionSubsystem1(TRUE, &KnkRbl_bNEngHiSuperKnk);
      }
    }

    /* If: '<S51>/If' incorporates:
     *  ActionPort: '<S56>/Action Port'
     *  ActionPort: '<S57>/Action Port'
     *  Constant: '<S43>/KnkMgt_nEngSuperKnkLoThd_C1'
     *  Constant: '<S43>/KnkMgt_nEngSuperKnkLoThd_C2'
     *  RelationalOperator: '<S51>/Relational Operator'
     *  RelationalOperator: '<S51>/Relational Operator1'
     *  SubSystem: '<S51>/If Action Subsystem'
     *  SubSystem: '<S51>/If Action Subsystem1'
     */
    if (KnkMgt_rLdSuperKnkLoThd_C >= KnkMgrCorRbl_B.VEMS_vidGET) {
      KnkMgrCorRbl_IfActionSubsystem(TRUE, &KnkMgrCorRbl_B.Merge_gy);
    } else {
      if (KnkMgrCorRbl_B.VEMS_vidGET >= KnkMgt_rLdSuperKnkHiThd_C) {
        KnkMgrCorRbl_IfActionSubsystem1(FALSE, &KnkMgrCorRbl_B.Merge_gy);
      }
    }

    /* Logic: '<S43>/Logical Operator1' */
    localLogicalOperator1_k = (KnkRbl_bNEngHiSuperKnk || KnkMgrCorRbl_B.Merge_gy);

    /* Logic: '<S43>/Logical Operator2' */
    KnkMgrCorRbl_B.LogicalOperator2_f[0] = ((localLogicalOperator1_k) &&
      Detection_fort_cliquetis_Cfm[0]);
    KnkMgrCorRbl_B.LogicalOperator2_f[1] = ((localLogicalOperator1_k) &&
      Detection_fort_cliquetis_Cfm[1]);
    KnkMgrCorRbl_B.LogicalOperator2_f[2] = ((localLogicalOperator1_k) &&
      Detection_fort_cliquetis_Cfm[2]);
    KnkMgrCorRbl_B.LogicalOperator2_f[3] = ((localLogicalOperator1_k) &&
      Detection_fort_cliquetis_Cfm[3]);

    /* Sum: '<S52>/Add' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    localAdd = localqY - 1U;

    /* Logic: '<S43>/Logical Operator3' incorporates:
     *  Constant: '<S52>/Constant'
     *  Logic: '<S43>/Logical Operator4'
     *  MinMax: '<S52>/MinMax'
     *  Selector: '<S52>/Selector'
     */
    KnkMgt_bKnkRblDetnCyl = (Detection_fort_cliquetis_Cfm[rt_MIN(localAdd, 3U)] &&
                             (!localLogicalOperator1_k));

    /* Sum: '<S53>/Add' incorporates:
     *  Constant: '<S53>/Constant1'
     */
    localqY--;

    /* Selector: '<S53>/Selector' incorporates:
     *  Constant: '<S53>/Constant'
     *  MinMax: '<S53>/MinMax'
     */
    KnkMgt_bRblDetnCyl = Detection_rbl_Cfm[rt_MIN(localqY, 3U)];

    /* end of Outputs for SubSystem: '<S41>/F01_RblDetCurCyl' */
    /* S-Function "vems_vidGET" Block: <S41>/VEMS_vidGET3 */
    VEMS_vidGET(TqLim_tqReqGlblTqRaw, KnkMgrCorRbl_B.VEMS_vidGET3);

    /* Outputs for atomic SubSystem: '<S41>/F00_RblInhWin' */

    /* DataTypeConversion: '<S42>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      locallocalDataTypeConversion = MAX_uint16_T;
    } else {
      locallocalDataTypeConversion = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Product: '<S49>/Product4' incorporates:
     *  Constant: '<S49>/offset'
     *  Constant: '<S49>/one_on_slope'
     *  Lookup_n-D: '<S48>/Lookup Table (n-D)'
     *  Sum: '<S49>/Add1'
     */
    localSwitch1_o = 16.0F * look1_iu16lftu16n4If_binlcns__1
      (locallocalDataTypeConversion, (&(KnkMgt_nEng_A[0])),
       (&(KnkMgt_tqGlblTqRawSpThd_M[0])), 8U);

    /* Switch: '<S49>/Switch1' incorporates:
     *  Constant: '<S49>/offset2'
     *  Constant: '<S49>/offset3'
     *  Constant: '<S49>/offset4'
     *  RelationalOperator: '<S49>/Relational Operator'
     *  Sum: '<S49>/Add3'
     *  Sum: '<S49>/Add4'
     */
    if (localSwitch1_o >= 0.0F) {
      localSwitch1_o += 0.5F;
    } else {
      localSwitch1_o -= 0.5F;
    }

    /* DataTypeConversion: '<S49>/OutDTConv' */
    if (localSwitch1_o < 32768.0F) {
      if (localSwitch1_o >= -32768.0F) {
        KnkMgt_tqGlblTqRawSpThd = (SInt16)localSwitch1_o;
      } else {
        KnkMgt_tqGlblTqRawSpThd = MIN_int16_T;
      }
    } else {
      KnkMgt_tqGlblTqRawSpThd = MAX_int16_T;
    }

    /* RelationalOperator: '<S42>/Relational Operator' */
    KnkMgt_bRblInhWin = (KnkMgrCorRbl_B.VEMS_vidGET3 < KnkMgt_tqGlblTqRawSpThd);

    /* end of Outputs for SubSystem: '<S41>/F00_RblInhWin' */

    /* Logic: '<S41>/Logical Operator4' */
    KnkMgt_bRblAcvWin3 = !KnkMgt_bRblInhWin;

    /* Outputs for enable SubSystem: '<S41>/F05_OccurCount' incorporates:
     *  EnablePort: '<S47>/KnkMgt_bRblAcvWin3'
     */
    if (KnkMgt_bRblAcvWin3) {
      /* SwitchCase: '<S47>/Switch Case' incorporates:
       *  ActionPort: '<S68>/Action Port'
       *  ActionPort: '<S69>/Action Port'
       *  ActionPort: '<S70>/Action Port'
       *  ActionPort: '<S71>/Action Port'
       *  DataTypeConversion: '<S47>/DTC3'
       *  SubSystem: '<S47>/F01_OccurRblCyl1'
       *  SubSystem: '<S47>/F02_OccurRblCyl2'
       *  SubSystem: '<S47>/F03_OccurRblCyl3'
       *  SubSystem: '<S47>/F04_OccurRblCyl4'
       */
      localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
      if (((UInt32)localq) > 255U) {
        localSwitch5 = MAX_uint8_T;
      } else {
        localSwitch5 = (UInt8)localq;
      }

      switch (localSwitch5) {
       case 1:
        /* NVRAM Read for EBDT Block <S68>/S-Function7 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurKnkRblCyl1, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurKnkRblCyl1_prev[col*3 + row] = plocalArray[row*3 +
                col];
            }
          }
        }

        /* Assignment: '<S68>/Assignment2' incorporates:
         *  DataTypeConversion: '<S68>/Data Type Conversion2'
         *  Selector: '<S68>/Selector1'
         *  Sum: '<S68>/Add2'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment2_j[(localq)] =
            KnkMgt_ctOccurKnkRblCyl1_prev[(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurKnkRblCyl1_prev[((KnkMgt_nbRLdZoneRbl
          - 1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)
          KnkMgt_bKnkRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment2_j[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S68>/EepromWriteAccess10 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment2_j[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurKnkRblCyl1, 3, 3, localArray);
        }

        /* NVRAM Read for EBDT Block <S68>/S-Function6 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurRblCyl1, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurRblCyl1_prev[col*3 + row] = plocalArray[row*3 + col];
            }
          }
        }

        /* Assignment: '<S68>/Assignment1' incorporates:
         *  DataTypeConversion: '<S68>/Data Type Conversion1'
         *  Selector: '<S68>/Selector2'
         *  Sum: '<S68>/Add1'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment1_b[(localq)] = KnkMgt_ctOccurRblCyl1_prev
            [(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurRblCyl1_prev[((KnkMgt_nbRLdZoneRbl -
          1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)KnkMgt_bRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment1_b[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S68>/EepromWriteAccess8 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment1_b[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurRblCyl1, 3, 3, localArray);
        }
        break;

       case 2:
        /* NVRAM Read for EBDT Block <S69>/S-Function9 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurRblCyl2, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurRblCyl2_prev[col*3 + row] = plocalArray[row*3 + col];
            }
          }
        }

        /* Assignment: '<S69>/Assignment1' incorporates:
         *  DataTypeConversion: '<S69>/Data Type Conversion1'
         *  Selector: '<S69>/Selector2'
         *  Sum: '<S69>/Add1'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment1_f[(localq)] = KnkMgt_ctOccurRblCyl2_prev
            [(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurRblCyl2_prev[((KnkMgt_nbRLdZoneRbl -
          1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)KnkMgt_bRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment1_f[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S69>/EepromWriteAccess11 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment1_f[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurRblCyl2, 3, 3, localArray);
        }

        /* NVRAM Read for EBDT Block <S69>/S-Function10 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurKnkRblCyl2, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurKnkRblCyl2_prev[col*3 + row] = plocalArray[row*3 +
                col];
            }
          }
        }

        /* Assignment: '<S69>/Assignment2' incorporates:
         *  DataTypeConversion: '<S69>/Data Type Conversion2'
         *  Selector: '<S69>/Selector1'
         *  Sum: '<S69>/Add2'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment2_l[(localq)] =
            KnkMgt_ctOccurKnkRblCyl2_prev[(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurKnkRblCyl2_prev[((KnkMgt_nbRLdZoneRbl
          - 1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)
          KnkMgt_bKnkRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment2_l[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S69>/EepromWriteAccess12 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment2_l[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurKnkRblCyl2, 3, 3, localArray);
        }
        break;

       case 3:
        /* NVRAM Read for EBDT Block <S70>/S-Function11 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurRblCyl3, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurRblCyl3_prev[col*3 + row] = plocalArray[row*3 + col];
            }
          }
        }

        /* Assignment: '<S70>/Assignment1' incorporates:
         *  DataTypeConversion: '<S70>/Data Type Conversion1'
         *  Selector: '<S70>/Selector2'
         *  Sum: '<S70>/Add1'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment1_m[(localq)] = KnkMgt_ctOccurRblCyl3_prev
            [(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurRblCyl3_prev[((KnkMgt_nbRLdZoneRbl -
          1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)KnkMgt_bRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment1_m[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S70>/EepromWriteAccess13 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment1_m[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurRblCyl3, 3, 3, localArray);
        }

        /* NVRAM Read for EBDT Block <S70>/S-Function12 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurKnkRblCyl3, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurKnkRblCyl3_prev[col*3 + row] = plocalArray[row*3 +
                col];
            }
          }
        }

        /* Assignment: '<S70>/Assignment2' incorporates:
         *  DataTypeConversion: '<S70>/Data Type Conversion2'
         *  Selector: '<S70>/Selector1'
         *  Sum: '<S70>/Add2'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment2_e[(localq)] =
            KnkMgt_ctOccurKnkRblCyl3_prev[(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurKnkRblCyl3_prev[((KnkMgt_nbRLdZoneRbl
          - 1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)
          KnkMgt_bKnkRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment2_e[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S70>/EepromWriteAccess14 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment2_e[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurKnkRblCyl3, 3, 3, localArray);
        }
        break;

       case 4:
        /* NVRAM Read for EBDT Block <S71>/S-Function14 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurKnkRblCyl4, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurKnkRblCyl4_prev[col*3 + row] = plocalArray[row*3 +
                col];
            }
          }
        }

        /* Assignment: '<S71>/Assignment2' incorporates:
         *  DataTypeConversion: '<S71>/Data Type Conversion2'
         *  Selector: '<S71>/Selector1'
         *  Sum: '<S71>/Add2'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment2_f[(localq)] =
            KnkMgt_ctOccurKnkRblCyl4_prev[(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurKnkRblCyl4_prev[((KnkMgt_nbRLdZoneRbl
          - 1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)
          KnkMgt_bKnkRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment2_f[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S71>/EepromWriteAccess1 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment2_f[row*3 +
                col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurKnkRblCyl4, 3, 3, localArray);
        }

        /* NVRAM Read for EBDT Block <S71>/S-Function13 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          VEMS_vidGET2DArray(KnkMgt_ctOccurRblCyl4, 3, 3, localArray);
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              KnkMgt_ctOccurRblCyl4_prev[col*3 + row] = plocalArray[row*3 + col];
            }
          }
        }

        /* Assignment: '<S71>/Assignment1' incorporates:
         *  DataTypeConversion: '<S71>/Data Type Conversion1'
         *  Selector: '<S71>/Selector2'
         *  Sum: '<S71>/Add1'
         */
        for (localq = 0; localq < 9; localq++) {
          KnkMgrCorRbl_B.Assignment1[(localq)] = KnkMgt_ctOccurRblCyl4_prev
            [(localq)];
        }

        localqY = (UInt32)(KnkMgt_ctOccurRblCyl4_prev[((KnkMgt_nbRLdZoneRbl -
          1) * 3) + (KnkMgt_nbNEngZoneRbl - 1)] + ((SInt32)KnkMgt_bRblDetnCyl));
        if (localqY > 65535U) {
          locallocalDataTypeConversion = MAX_uint16_T;
        } else {
          locallocalDataTypeConversion = (UInt16)localqY;
        }

        KnkMgrCorRbl_B.Assignment1[(KnkMgt_nbNEngZoneRbl - 1) + (3 *
          (KnkMgt_nbRLdZoneRbl - 1))] = locallocalDataTypeConversion;

        /* NVRAM Write for EBDT Block <S71>/EepromWriteAccess15 */
        {
          UInt32 row;
          UInt32 col;
          UInt16 localArray[3][3];
          UInt16 * plocalArray = &localArray[0][0];
          for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
              plocalArray[col*3 + row] = KnkMgrCorRbl_B.Assignment1[row*3 + col];
            }
          }

          VEMS_vidSET2DArray(KnkMgt_ctOccurRblCyl4, 3, 3, localArray);
        }
        break;
      }
    }

    /* end of Outputs for SubSystem: '<S41>/F05_OccurCount' */

    /* Selector: '<S44>/Selector' incorporates:
     *  DataTypeConversion: '<S44>/DTC3'
     */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localSwitch5 = MAX_uint8_T;
    } else {
      localSwitch5 = (UInt8)localq;
    }

    KnkMgt_ctPerdRblCyl_prev = KnkMgt_ctPerdRbl_prev[localSwitch5 - 1];

    /* Sum: '<S44>/Sum1' incorporates:
     *  Constant: '<S44>/KnkMgt_ctPerdRblInjCutOffDec_C'
     */
    localq = ((((KnkMgt_ctPerdRblCyl_prev << 1) + -2) -
               (KnkMgt_ctPerdRblInjCutOffDec_C << 1)) >> 1);
    if (localq <= 0) {
      localSwitch5 = 0U;
    } else {
      localSwitch5 = (UInt8)localq;
    }

    /* DataTypeConversion: '<S44>/DTC5' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Selector: '<S44>/Selector1' */
    localSelector1_p0 = KnkMgt_prm_bInjCutOffRblCyl_prev[localDTC5 - 1];

    /* Logic: '<S44>/Logical Operator2' incorporates:
     *  Logic: '<S44>/Logical Operator1'
     *  UnitDelay: '<S61>/Unit Delay'
     */
    localLogicalOperator1_k = ((!KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aa) &&
      (localSelector1_p0));

    /* DataTypeConversion: '<S60>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      localSelector1_pj = MAX_uint16_T;
    } else {
      localSelector1_pj = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Lookup2D: '<S60>/Look-Up Table (2-D)'
     * About '<S60>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localDTC5), (&(KnkMgt_ctPerdRblInc_M[0])),
                      localSelector1_pj, (&(KnkMgt_nEng_A[0])), 8U,
                      KnkMgrCorRbl_B.VEMS_vidGET, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate2'
     *
     * Regarding '<S60>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S44>/DTC1' */
    localSwitch = localDTC5;

    /* Logic: '<S44>/Logical Operator3' */
    localLogicalOperator3_l = (KnkMgt_bRblDetnCyl && KnkMgt_bRblAcvWin3);

    /* DataTypeConversion: '<S58>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      localSelector1_pj = MAX_uint16_T;
    } else {
      localSelector1_pj = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Lookup2D: '<S58>/Look-Up Table (2-D)'
     * About '<S58>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localDTC5), (&(KnkMgt_ctPerdKnkRblInc_M[0])),
                      localSelector1_pj, (&(KnkMgt_nEng_A[0])), 8U,
                      KnkMgrCorRbl_B.VEMS_vidGET, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate2'
     *
     * Regarding '<S58>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S44>/DTC2' */
    localSwitch2_p = localDTC5;

    /* Logic: '<S44>/Logical Operator4' */
    localLogicalOperator4 = (KnkMgt_bKnkRblDetnCyl && KnkMgt_bRblAcvWin3);

    /* DataTypeConversion: '<S59>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      localSelector1_pj = MAX_uint16_T;
    } else {
      localSelector1_pj = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Lookup2D: '<S59>/Look-Up Table (2-D)'
     * About '<S59>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localDTC5), (&(KnkMgt_ctPerdRblDec_M[0])),
                      localSelector1_pj, (&(KnkMgt_nEng_A[0])), 8U,
                      KnkMgrCorRbl_B.VEMS_vidGET, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate2'
     *
     * Regarding '<S59>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Switch: '<S44>/Switch2' incorporates:
     *  Constant: '<S44>/ConstVal'
     *  Product: '<S62>/Divide'
     */
    if (!localLogicalOperator4) {
      localSwitch2_p = (SInt16)(-localDTC5);
    }

    /* Switch: '<S44>/Switch' */
    if (!localLogicalOperator3_l) {
      localSwitch = localSwitch2_p;
    }

    /* Sum: '<S44>/Sum3' */
    localSwitch1_c = localSwitch + KnkMgt_ctPerdRblCyl_prev;

    /* MinMax: '<S44>/MinMax' incorporates:
     *  Constant: '<S44>/ConstVal_1'
     */
    localq = rt_MAX(0, localSwitch1_c);
    if (localq <= 0) {
      localDTC5 = 0U;
    } else if (localq > 255) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Switch: '<S44>/Switch3' */
    if (localSelector1_p0) {
      localDTC5 = KnkMgt_ctPerdRblCyl_prev;
    }

    /* Switch: '<S44>/Switch1' */
    if (!localLogicalOperator1_k) {
      localSwitch5 = localDTC5;
    }

    /* DataTypeConversion: '<S44>/DTC4' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Assignment: '<S44>/Assignment1' */
    KnkMgrCorRbl_B.Assignment1_j[0] = KnkMgt_ctPerdRbl_prev[0];
    KnkMgrCorRbl_B.Assignment1_j[1] = KnkMgt_ctPerdRbl_prev[1];
    KnkMgrCorRbl_B.Assignment1_j[2] = KnkMgt_ctPerdRbl_prev[2];
    KnkMgrCorRbl_B.Assignment1_j[3] = KnkMgt_ctPerdRbl_prev[3];
    KnkMgrCorRbl_B.Assignment1_j[localDTC5 - 1] = localSwitch5;

    /* S-Function "vems_vidSET" Block: <S44>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(KnkMgt_ctPerdRbl, 4, KnkMgrCorRbl_B.Assignment1_j);

    /* NVRAM Read for EBDT Block <S41>/S-Function15 */
    VEMS_vidGET1DArray(KnkMgt_ctTotRbl, 4, KnkMgt_ctTotRbl_prev);

    /* DataTypeConversion: '<S45>/DTC3' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Selector: '<S45>/Selector1' */
    localSelector1_pj = KnkMgt_ctTotRbl_prev[localDTC5 - 1];

    /* DataTypeConversion: '<S63>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      localLookUpTable2D = MAX_uint16_T;
    } else {
      localLookUpTable2D = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Lookup2D: '<S63>/Look-Up Table (2-D)'
     * About '<S63>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localMinMax_e), (&(KnkMgt_ctTotKnkRblInc_M[0])),
                       localLookUpTable2D, (&(KnkMgt_nEng_A[0])), 8U,
                       KnkMgrCorRbl_B.VEMS_vidGET, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate2'
     *
     * Regarding '<S63>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S45>/DTC2' */
    localSwitch1_c = localMinMax_e;

    /* Logic: '<S45>/Logical Operator1' */
    localLogicalOperator1_k = (KnkMgt_bKnkRblDetnCyl && KnkMgt_bRblAcvWin3);

    /* DataTypeConversion: '<S64>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET1 > 8191) {
      localMinMax_e = MAX_uint16_T;
    } else {
      localMinMax_e = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET1 << 3);
    }

    /* Lookup2D: '<S64>/Look-Up Table (2-D)'
     * About '<S64>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U16
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D), (&(KnkMgt_ctTotRblInc_M[0])),
                       localMinMax_e, (&(KnkMgt_nEng_A[0])), 8U,
                       KnkMgrCorRbl_B.VEMS_vidGET, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate2'
     *
     * Regarding '<S64>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S45>/DTC1' */
    localpluIdx = localLookUpTable2D;

    /* UnitDelay: '<S65>/Unit Delay' */
    KnkMgt_ctTotNbCycDecRbl_prev[0] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE[0];
    KnkMgt_ctTotNbCycDecRbl_prev[1] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE[1];
    KnkMgt_ctTotNbCycDecRbl_prev[2] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE[2];
    KnkMgt_ctTotNbCycDecRbl_prev[3] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE[3];

    /* DataTypeConversion: '<S45>/DTC6' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Selector: '<S45>/Selector' */
    localDTC5 = KnkMgt_ctTotNbCycDecRbl_prev[localDTC5 - 1];

    /* Sum: '<S45>/Sum2' incorporates:
     *  Constant: '<S45>/ConstVal_3'
     */
    localq = localDTC5 - 1;
    if (localq <= 0) {
      localSwitch5 = 0U;
    } else {
      localSwitch5 = (UInt8)localq;
    }

    /* Switch: '<S45>/Switch4' incorporates:
     *  Constant: '<S45>/ConstVal_2'
     *  Constant: '<S45>/KnkMgt_ctTotNbCycDecRbl_C'
     *  RelationalOperator: '<S45>/Relational Operator'
     */
    if (localDTC5 == 0) {
      localSwitch5 = KnkMgt_ctTotNbCycDecRbl_C;
    }

    /* Switch: '<S45>/Switch3' incorporates:
     *  Constant: '<S45>/ConstVal'
     *  Constant: '<S45>/ConstVal_1'
     *  Constant: '<S45>/ConstVal_5'
     *  RelationalOperator: '<S45>/Relational Operator1'
     */
    if (localSwitch5 == 0) {
      localq = -1;
    } else {
      localq = 0;
    }

    /* Switch: '<S45>/Switch2' incorporates:
     *  Logic: '<S45>/Logical Operator3'
     */
    if (!(KnkMgt_bRblDetnCyl && KnkMgt_bRblAcvWin3)) {
      localpluIdx = localq;
    }

    /* Switch: '<S45>/Switch1' */
    if (!localLogicalOperator1_k) {
      localSwitch1_c = localpluIdx;
    }

    /* Sum: '<S45>/Sum1' */
    localq = localSelector1_pj;
    localpluIdx = localq + localSwitch1_c;
    if ((localq > 0) && ((localSwitch1_c > 0) && (localpluIdx <= 0))) {
      localpluIdx = MAX_int32_T;
    }

    /* MinMax: '<S45>/MinMax' incorporates:
     *  Constant: '<S45>/ConstVal_4'
     */
    localq = rt_MAX(0, localpluIdx);
    if (localq <= 0) {
      localMinMax_e = 0U;
    } else if (localq > 65535) {
      localMinMax_e = MAX_uint16_T;
    } else {
      localMinMax_e = (UInt16)localq;
    }

    /* DataTypeConversion: '<S45>/DTC4' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Assignment: '<S45>/Assignment2' */
    KnkMgrCorRbl_B.Assignment2_d[0] = KnkMgt_ctTotRbl_prev[0];
    KnkMgrCorRbl_B.Assignment2_d[1] = KnkMgt_ctTotRbl_prev[1];
    KnkMgrCorRbl_B.Assignment2_d[2] = KnkMgt_ctTotRbl_prev[2];
    KnkMgrCorRbl_B.Assignment2_d[3] = KnkMgt_ctTotRbl_prev[3];
    KnkMgrCorRbl_B.Assignment2_d[localDTC5 - 1] = localMinMax_e;

    /* NVRAM Write for EBDT Block <S45>/EepromWriteAccess9 */
    VEMS_vidSET1DArray(KnkMgt_ctTotRbl, 4, KnkMgrCorRbl_B.Assignment2_d);

    /* Switch: '<S45>/Switch5' incorporates:
     *  Constant: '<S45>/KnkMgt_ctTotNbCycDecRbl_C_1'
     *  Logic: '<S45>/Logical Operator2'
     *  Logic: '<S45>/Logical Operator4'
     */
    if ((KnkMgt_bKnkRblDetnCyl || KnkMgt_bRblDetnCyl) && KnkMgt_bRblAcvWin3) {
      localSwitch5 = KnkMgt_ctTotNbCycDecRbl_C;
    }

    /* DataTypeConversion: '<S45>/DTC5' */
    localq = KnkMgrCorRbl_B.VEMS_vidGET2_i + 1;
    if (((UInt32)localq) > 255U) {
      localDTC5 = MAX_uint8_T;
    } else {
      localDTC5 = (UInt8)localq;
    }

    /* Assignment: '<S45>/Assignment1' */
    KnkMgt_ctTotNbCycDecRbl[0] = KnkMgt_ctTotNbCycDecRbl_prev[0];
    KnkMgt_ctTotNbCycDecRbl[1] = KnkMgt_ctTotNbCycDecRbl_prev[1];
    KnkMgt_ctTotNbCycDecRbl[2] = KnkMgt_ctTotNbCycDecRbl_prev[2];
    KnkMgt_ctTotNbCycDecRbl[3] = KnkMgt_ctTotNbCycDecRbl_prev[3];
    KnkMgt_ctTotNbCycDecRbl[localDTC5 - 1] = localSwitch5;

    /* S-Function "vems_vidSET" Block: <S41>/VEMS_vidSET */
    VEMS_vidSET1DArray(KnkMgt_bSuperKnkDet, 4, KnkMgrCorRbl_B.LogicalOperator2_f);
  }

  /* end of Outputs for SubSystem: '<S7>/F02_RblCount' */

  /* Update for enable SubSystem: '<S7>/F02_RblCount' incorporates:
   *  Update for EnablePort: '<S41>/Enable'
   */
  if (localRelationalOperator_pl) {
    /* Update for UnitDelay: '<S61>/Unit Delay' */
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_aa = localSelector1_p0;

    /* Update for UnitDelay: '<S65>/Unit Delay' */
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE[0] = KnkMgt_ctTotNbCycDecRbl[0];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE[1] = KnkMgt_ctTotNbCycDecRbl[1];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE[2] = KnkMgt_ctTotNbCycDecRbl[2];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE[3] = KnkMgt_ctTotNbCycDecRbl[3];
  }

  /* end of Update for SubSystem: '<S7>/F02_RblCount' */
}

/* Output and update for function-call system: '<S1>/F03_RblCorr' */
void KnkMgrCorRbl_F03_RblCorr(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion_n;
  UInt16 localDataTypeConversion_a;
  UInt16 localDataTypeConversion_e;
  UInt16 localMinMax_ed;
  UInt8 localLookUpTable2D_e;
  UInt8 localLookUpTable_c;
  UInt8 localLookUpTable_l;
  UInt8 localDTC6;
  Boolean localRelationalOperator_pl2;
  UInt16 localSelector_l;
  UInt8 localDTC1_e;
  SInt32 localSum3;
  Boolean localRelationalOperator1_d;
  UInt8 localSwitch1_a[4];
  UInt8 locallocalDTC1_e;
  SInt16 locallocalSwitch_l;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/ConstVal'
   *  Constant: '<S8>/KNKMGRCORRBL_u8Inhib'
   */
  localRelationalOperator_pl2 = (KNKMGRCORRBL_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S8>/F03_RblCorr' incorporates:
   *  EnablePort: '<S72>/Enable'
   */
  if (localRelationalOperator_pl2) {
    /* NVRAM Read for EBDT Block <S72>/S-Function7 */
    VEMS_vidGET1DArray(KnkMgt_ctInjCutOffRbl, 4, KnkMgt_ctInjCutOffRbl_prev);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET3 */
    VEMS_vidGET(KnkRbl_noCyl, KnkMgrCorRbl_B.VEMS_vidGET3_j);

    /* DataTypeConversion: '<S78>/DTC3' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Selector: '<S78>/Selector' */
    localSelector_l = KnkMgt_ctInjCutOffRbl_prev[localDTC6 - 1];

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_nEng, KnkMgrCorRbl_B.VEMS_vidGET2);

    /* DataTypeConversion: '<S81>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET2 > 8191) {
      localDataTypeConversion_n = MAX_uint16_T;
    } else {
      localDataTypeConversion_n = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET2 << 3);
    }

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET1 */
    VEMS_vidGET(EngM_rTotLdExCor, KnkMgrCorRbl_B.VEMS_vidGET1_n);

    /* DataTypeConversion Block: '<S81>/Data Type Conversion1'
     *
     * Regarding '<S81>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate1'
     *
     * Regarding '<S81>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S83>/Data Type Conversion1'
     *
     * Regarding '<S83>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate1'
     *
     * Regarding '<S83>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S81>/Look-Up Table (2-D)'
     * About '<S81>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_e), (&(KnkMgt_ctTDCInjCutOffInc_M[0])),
                      localDataTypeConversion_n, (&(KnkMgt_nEng_A[0])), 8U,
                      KnkMgrCorRbl_B.VEMS_vidGET1_n, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S81>/Data Type Duplicate2'
     *
     * Regarding '<S81>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(Knk_rbl_index, 4, KnkMgrCorRbl_B.VEMS_vidGET4);

    /* DataTypeConversion: '<S75>/DTC3' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Selector: '<S75>/Selector' */
    localDTC6 = KnkMgrCorRbl_B.VEMS_vidGET4[localDTC6 - 1];

    /* Selector: '<S75>/Selector1' incorporates:
     *  DataTypeConversion: '<S75>/DTC1'
     */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    localDTC1_e = KnkMgt_idxMinPosnRbl_prev[locallocalDTC1_e - 1];

    /* MinMax: '<S75>/MinMax' */
    localDTC1_e = (UInt8)rt_MIN(localDTC6, localDTC1_e);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(KnkMgt_ctPerdRbl, 4, KnkMgrCorRbl_B.VEMS_vidGET5);

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/ConstVal'
     *  DataTypeConversion: '<S75>/DTC2'
     *  RelationalOperator: '<S75>/Relational Operator1'
     *  Selector: '<S75>/Selector2'
     */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    if (KnkMgrCorRbl_B.VEMS_vidGET5[locallocalDTC1_e - 1] > 0) {
      localDTC6 = localDTC1_e;
    }

    /* Assignment: '<S75>/Assignment2' incorporates:
     *  DataTypeConversion: '<S75>/DTC4'
     */
    KnkMgrCorRbl_B.Assignment2_n[0] = KnkMgt_idxMinPosnRbl_prev[0];
    KnkMgrCorRbl_B.Assignment2_n[1] = KnkMgt_idxMinPosnRbl_prev[1];
    KnkMgrCorRbl_B.Assignment2_n[2] = KnkMgt_idxMinPosnRbl_prev[2];
    KnkMgrCorRbl_B.Assignment2_n[3] = KnkMgt_idxMinPosnRbl_prev[3];
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    KnkMgrCorRbl_B.Assignment2_n[locallocalDTC1_e - 1] = localDTC6;

    /* Outputs for atomic SubSystem: '<S73>/F02_Depassement_seuil' *
     * Block requirements for '<S73>/F02_Depassement_seuil':
     *  1. SubSystem "F02_Depassement_seuil" !Trace_To : VEMS_E_10_02583_008.01 ;
     */

    /* DataTypeConversion: '<S76>/DTC1' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    /* DataTypeConversion: '<S76>/DTC3' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC1_e = MAX_uint8_T;
    } else {
      localDTC1_e = (UInt8)localSum3;
    }

    /* DataTypeConversion: '<S79>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET2 > 8191) {
      localDataTypeConversion_a = MAX_uint16_T;
    } else {
      localDataTypeConversion_a = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET2 << 3);
    }

    /* Lookup: '<S79>/Look-Up Table'
     * About '<S79>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_c), (&(KnkMgt_ctPerdRblInjCutOffThd1_T[0])),
                  localDataTypeConversion_a, (&(KnkMgt_nEng_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S79>/Data Type Duplicate1'
     *
     * Regarding '<S79>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S80>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET2 > 8191) {
      localDataTypeConversion_e = MAX_uint16_T;
    } else {
      localDataTypeConversion_e = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET2 << 3);
    }

    /* Lookup: '<S80>/Look-Up Table'
     * About '<S80>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_l), (&(KnkMgt_ctPerdRblInjCutOffThd2_T[0])),
                  localDataTypeConversion_e, (&(KnkMgt_nEng_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S80>/Data Type Duplicate1'
     *
     * Regarding '<S80>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Switch: '<S76>/Switch1' incorporates:
     *  Constant: '<S76>/KnkMgt_bIdxMinPosnRblAcv_C'
     */
    if (KnkMgt_bIdxMinPosnRblAcv_C) {
      localSwitch1_a[0] = KnkMgrCorRbl_B.Assignment2_n[0];
      localSwitch1_a[1] = KnkMgrCorRbl_B.Assignment2_n[1];
      localSwitch1_a[2] = KnkMgrCorRbl_B.Assignment2_n[2];
      localSwitch1_a[3] = KnkMgrCorRbl_B.Assignment2_n[3];
    } else {
      localSwitch1_a[0] = KnkMgrCorRbl_B.VEMS_vidGET4[0];
      localSwitch1_a[1] = KnkMgrCorRbl_B.VEMS_vidGET4[1];
      localSwitch1_a[2] = KnkMgrCorRbl_B.VEMS_vidGET4[2];
      localSwitch1_a[3] = KnkMgrCorRbl_B.VEMS_vidGET4[3];
    }

    /* Selector: '<S76>/Selector1' */
    Knk_rbl_index_cyl = localSwitch1_a[locallocalDTC1_e - 1];

    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S76>/KnkMgt_idxCritRblThd_C'
     *  Lookup: '<S79>/Look-Up Table'
     *  Lookup: '<S80>/Look-Up Table'
     *  RelationalOperator: '<S76>/Relational Operator1'
     */
    if (Knk_rbl_index_cyl <= KnkMgt_idxCritRblThd_C) {
      locallocalDTC1_e = localLookUpTable_l;
    } else {
      locallocalDTC1_e = localLookUpTable_c;
    }

    /* Logic: '<S76>/Logical Operator1' incorporates:
     *  Logic: '<S76>/Logical Operator2'
     *  Logic: '<S76>/Logical Operator3'
     *  Logic: '<S76>/Logical Operator4'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  Selector: '<S76>/Selector'
     */
    KnkMgt_bInjCutOffCylReq = (((!KnkMgt_bRblInhWin) && (KnkMgt_bKnkRblDetnCyl ||
      KnkMgt_bRblDetnCyl)) && (KnkMgrCorRbl_B.VEMS_vidGET5[localDTC1_e - 1] >=
      locallocalDTC1_e));

    /* end of Outputs for SubSystem: '<S73>/F02_Depassement_seuil' */

    /* Selector: '<S77>/Selector' incorporates:
     *  DataTypeConversion: '<S77>/DTC3'
     */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    KnkMgt_ctTDCInjCutOffCyl_prev = KnkMgt_ctTDCInjCutOff_prev[locallocalDTC1_e
      - 1];

    /* Sum: '<S77>/Sum3' incorporates:
     *  Constant: '<S77>/ConstVal_1'
     */
    locallocalSwitch_l = (SInt16)(KnkMgt_ctTDCInjCutOffCyl_prev + -1);

    /* MinMax: '<S77>/MinMax' incorporates:
     *  Constant: '<S77>/ConstVal_2'
     */
    locallocalSwitch_l = (SInt16)rt_MAX(0, locallocalSwitch_l);
    if (locallocalSwitch_l <= 0) {
      localDTC1_e = 0U;
    } else if (locallocalSwitch_l > 255) {
      localDTC1_e = MAX_uint8_T;
    } else {
      localDTC1_e = (UInt8)locallocalSwitch_l;
    }

    /* Switch: '<S77>/Switch' incorporates:
     *  Lookup2D: '<S81>/Look-Up Table (2-D)'
     */
    if (KnkMgt_bInjCutOffCylReq) {
      localDTC1_e = localLookUpTable2D_e;
    }

    /* DataTypeConversion: '<S77>/DTC2' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Assignment: '<S77>/Assignment2' */
    KnkMgrCorRbl_B.Assignment2_a[0] = KnkMgt_ctTDCInjCutOff_prev[0];
    KnkMgrCorRbl_B.Assignment2_a[1] = KnkMgt_ctTDCInjCutOff_prev[1];
    KnkMgrCorRbl_B.Assignment2_a[2] = KnkMgt_ctTDCInjCutOff_prev[2];
    KnkMgrCorRbl_B.Assignment2_a[3] = KnkMgt_ctTDCInjCutOff_prev[3];
    KnkMgrCorRbl_B.Assignment2_a[localDTC6 - 1] = localDTC1_e;

    /* DataTypeConversion: '<S78>/DTC1' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Selector: '<S78>/Selector1' */
    localDTC6 = KnkMgrCorRbl_B.Assignment2_a[localDTC6 - 1];

    /* DataTypeConversion: '<S78>/DTC2' */
    locallocalSwitch_l = localDTC6;

    /* DataTypeConversion: '<S83>/Data Type Conversion' */
    if (KnkMgrCorRbl_B.VEMS_vidGET2 > 8191) {
      localMinMax_ed = MAX_uint16_T;
    } else {
      localMinMax_ed = (UInt16)(KnkMgrCorRbl_B.VEMS_vidGET2 << 3);
    }

    /* Lookup2D: '<S83>/Look-Up Table (2-D)'
     * About '<S83>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U16  2^-3
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Integer        U8
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localDTC6), (&(KnkMgt_ctTDCInjCutOffDec_M[0])),
                      localMinMax_ed, (&(KnkMgt_nEng_A[0])), 8U,
                      KnkMgrCorRbl_B.VEMS_vidGET1_n, (&(KnkMgt_rAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate2'
     *
     * Regarding '<S83>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/ConstVal'
     *  Product: '<S84>/Divide'
     */
    if (!KnkMgt_bInjCutOffCylReq) {
      locallocalSwitch_l = (SInt16)(-localDTC6);
    }

    /* Sum: '<S78>/Sum3' */
    localSum3 = localSelector_l + locallocalSwitch_l;

    /* MinMax: '<S78>/MinMax' incorporates:
     *  Constant: '<S78>/ConstVal_2'
     */
    localSum3 = rt_MAX(0, localSum3);
    if (localSum3 <= 0) {
      localMinMax_ed = 0U;
    } else if (localSum3 > 65535) {
      localMinMax_ed = MAX_uint16_T;
    } else {
      localMinMax_ed = (UInt16)localSum3;
    }

    /* DataTypeConversion: '<S78>/DTC5' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* RelationalOperator: '<S78>/Relational Operator1' incorporates:
     *  Constant: '<S78>/ConstVal_1'
     *  Selector: '<S78>/Selector2'
     */
    localRelationalOperator1_d = (KnkMgrCorRbl_B.Assignment2_a[localDTC6 - 1] ==
      0);

    /* DataTypeConversion: '<S78>/DTC4' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Switch: '<S78>/Switch1' incorporates:
     *  Logic: '<S78>/Logical Operator1'
     *  Selector: '<S78>/Selector3'
     */
    if (!(KnkMgt_bInjCutOffCylReq || (localRelationalOperator1_d))) {
      localMinMax_ed = KnkMgt_ctInjCutOffRbl_prev[localDTC6 - 1];
    }

    /* DataTypeConversion: '<S78>/DTC6' */
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      localDTC6 = MAX_uint8_T;
    } else {
      localDTC6 = (UInt8)localSum3;
    }

    /* Assignment: '<S78>/Assignment2' */
    KnkMgrCorRbl_B.Assignment2[0] = KnkMgt_ctInjCutOffRbl_prev[0];
    KnkMgrCorRbl_B.Assignment2[1] = KnkMgt_ctInjCutOffRbl_prev[1];
    KnkMgrCorRbl_B.Assignment2[2] = KnkMgt_ctInjCutOffRbl_prev[2];
    KnkMgrCorRbl_B.Assignment2[3] = KnkMgt_ctInjCutOffRbl_prev[3];
    KnkMgrCorRbl_B.Assignment2[localDTC6 - 1] = localMinMax_ed;

    /* NVRAM Write for EBDT Block <S72>/EepromWriteAccess */
    VEMS_vidSET1DArray(KnkMgt_ctInjCutOffRbl, 4, KnkMgrCorRbl_B.Assignment2);

    /* Assignment: '<S77>/Assignment1' incorporates:
     *  Constant: '<S77>/ConstVal'
     *  DataTypeConversion: '<S77>/DTC1'
     *  RelationalOperator: '<S77>/Relational Operator'
     *  UnitDelay: '<S82>/Unit Delay'
     */
    KnkMgrCorRbl_B.Assignment1_p[0] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[0];
    KnkMgrCorRbl_B.Assignment1_p[1] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[1];
    KnkMgrCorRbl_B.Assignment1_p[2] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[2];
    KnkMgrCorRbl_B.Assignment1_p[3] = KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[3];
    localSum3 = KnkMgrCorRbl_B.VEMS_vidGET3_j + 1;
    if (((UInt32)localSum3) > 255U) {
      locallocalDTC1_e = MAX_uint8_T;
    } else {
      locallocalDTC1_e = (UInt8)localSum3;
    }

    KnkMgrCorRbl_B.Assignment1_p[locallocalDTC1_e - 1] = (localDTC1_e > 0);

    /* NVRAM Read for EBDT Block <S72>/S-Function9 */
    VEMS_vidGET1DArray(KnkMgt_ctTotRbl, 4, KnkMgrCorRbl_B.SFunction9);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET6 */
    VEMS_vidGET(KnkMgt_bAcvIrvLdLimToilReq, KnkMgrCorRbl_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S72>/VEMS_vidGET7 */
    VEMS_vidGET(KnkMgt_bAcvIrvLdLimRblPvtReq, KnkMgrCorRbl_B.VEMS_vidGET7);

    /* Outputs for atomic SubSystem: '<S74>/F02_IrvRblCorReq' */

    /* MinMax: '<S86>/MinMax1' */
    localSelector_l = (UInt16)rt_MAX(KnkMgrCorRbl_B.SFunction9[0],
      KnkMgrCorRbl_B.SFunction9[1]);
    localSelector_l = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.SFunction9[2]);
    localSelector_l = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.SFunction9[3]);

    /* If: '<S93>/If' incorporates:
     *  ActionPort: '<S96>/Action Port'
     *  ActionPort: '<S97>/Action Port'
     *  Constant: '<S86>/KnkMgt_ctOccurRblIrvLdLimHiThd_C'
     *  Constant: '<S86>/KnkMgt_ctOccurRbllrvLdLimLoThd_C'
     *  RelationalOperator: '<S93>/Relational Operator'
     *  RelationalOperator: '<S93>/Relational Operator1'
     *  SubSystem: '<S93>/If Action Subsystem'
     *  SubSystem: '<S93>/If Action Subsystem1'
     */
    if (KnkMgt_ctOccurRbllrvLdLimLoThd_C >= ((UInt32)localSelector_l)) {
      KnkMgrCorRbl_IfActionSubsystem(FALSE, &KnkMgrCorRbl_B.Merge_i);
    } else {
      if (((UInt32)localSelector_l) >= KnkMgt_ctOccurRblIrvLdLimHiThd_C) {
        KnkMgrCorRbl_IfActionSubsystem1(TRUE, &KnkMgrCorRbl_B.Merge_i);
      }
    }

    /* Logic: '<S94>/Logical Operator1' incorporates:
     *  Constant: '<S86>/KnkMgt_bInhIrvLdLimRbl_C'
     *  Logic: '<S86>/Logical Operator1'
     *  Logic: '<S86>/Logical Operator3'
     *  Logic: '<S94>/Logical Operator'
     *  UnitDelay: '<S95>/Unit Delay'
     *  UnitDelay: '<S98>/Unit Delay'
     */
    localRelationalOperator1_d = !((!(KnkMgrCorRbl_DWork.UnitDelay_DSTATE_at ||
      KnkMgrCorRbl_B.Merge_i)) || ((KnkMgrCorRbl_DWork.UnitDelay_DSTATE_h &&
      (!KnkMgrCorRbl_B.Merge_i)) && KnkMgt_bInhIrvLdLimRbl_C));

    /* Logic: '<S86>/Logical Operator2' */
    KnkMgrCorRbl_B.LogicalOperator2 = (((localRelationalOperator1_d) ||
      KnkMgrCorRbl_B.VEMS_vidGET6) || KnkMgrCorRbl_B.VEMS_vidGET7);

    /* Update for UnitDelay: '<S95>/Unit Delay' */
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_h = KnkMgrCorRbl_B.Merge_i;

    /* Update for UnitDelay: '<S98>/Unit Delay' */
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_at = localRelationalOperator1_d;

    /* end of Outputs for SubSystem: '<S74>/F02_IrvRblCorReq' */

    /* MinMax: '<S85>/MinMax1' */
    localSelector_l = (UInt16)rt_MAX(KnkMgrCorRbl_B.Assignment2[0],
      KnkMgrCorRbl_B.Assignment2[1]);
    localSelector_l = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.Assignment2[2]);
    localMinMax_ed = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.Assignment2[3]);

    /* If: '<S87>/If' incorporates:
     *  ActionPort: '<S89>/Action Port'
     *  ActionPort: '<S90>/Action Port'
     *  Constant: '<S85>/KnkMgt_ctInjCutOfTmpLimLdHiThd_C'
     *  Constant: '<S85>/KnkMgt_ctInjCutOfTmpLimLdLoThd_C'
     *  RelationalOperator: '<S87>/Relational Operator'
     *  RelationalOperator: '<S87>/Relational Operator1'
     *  SubSystem: '<S87>/If Action Subsystem'
     *  SubSystem: '<S87>/If Action Subsystem1'
     */
    if (((UInt32)KnkMgt_ctInjCutOfTmpLimLdLoThd_C) >= ((UInt32)
         localMinMax_ed)) {
      KnkMgrCorRbl_IfActionSubsystem(FALSE, &KnkMgrCorRbl_B.Merge);
    } else {
      if (((UInt32)localMinMax_ed) >= ((UInt32)
           KnkMgt_ctInjCutOfTmpLimLdHiThd_C)) {
        KnkMgrCorRbl_IfActionSubsystem1(TRUE, &KnkMgrCorRbl_B.Merge);
      }
    }

    /* MinMax: '<S85>/MinMax' */
    localSelector_l = (UInt16)rt_MAX(KnkMgrCorRbl_B.Assignment2[0],
      KnkMgrCorRbl_B.Assignment2[1]);
    localSelector_l = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.Assignment2[2]);
    localMinMax_ed = (UInt16)rt_MAX(localSelector_l,
      KnkMgrCorRbl_B.Assignment2[3]);

    /* If: '<S88>/If' incorporates:
     *  ActionPort: '<S91>/Action Port'
     *  ActionPort: '<S92>/Action Port'
     *  Constant: '<S85>/KnkMgt_ctInjCutOffVlvPosnHiThd_C'
     *  Constant: '<S85>/KnkMgt_ctInjCutOffVlvPosnLoThd_C'
     *  RelationalOperator: '<S88>/Relational Operator'
     *  RelationalOperator: '<S88>/Relational Operator1'
     *  SubSystem: '<S88>/If Action Subsystem'
     *  SubSystem: '<S88>/If Action Subsystem1'
     */
    if (((UInt32)KnkMgt_ctInjCutOffVlvPosnLoThd_C) >= ((UInt32)
         localMinMax_ed)) {
      KnkMgrCorRbl_IfActionSubsystem(FALSE, &KnkMgrCorRbl_B.Merge_g);
    } else {
      if (((UInt32)localMinMax_ed) >= ((UInt32)
           KnkMgt_ctInjCutOffVlvPosnHiThd_C)) {
        KnkMgrCorRbl_IfActionSubsystem1(TRUE, &KnkMgrCorRbl_B.Merge_g);
      }
    }

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET */
    VEMS_vidSET(KnkMgt_bAcvIrvLdLimRblReq, KnkMgrCorRbl_B.LogicalOperator2);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET1 */
    VEMS_vidSET(KnkMgt_bAcvTmpLdLimRblReq, KnkMgrCorRbl_B.Merge);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET2 */
    VEMS_vidSET(KnkMgt_bAcvVlvPosnRblReq, KnkMgrCorRbl_B.Merge_g);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET3 */
    VEMS_vidSET1DArray(KnkMgt_ctTDCInjCutOff, 4, KnkMgrCorRbl_B.Assignment2_a);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET4 */
    VEMS_vidSET1DArray(KnkMgt_idxMinPosnRbl, 4, KnkMgrCorRbl_B.Assignment2_n);

    /* S-Function "vems_vidSET" Block: <S72>/VEMS_vidSET5 */
    VEMS_vidSET1DArray(KnkMgt_prm_bInjCutOffRblCyl, 4,
                       KnkMgrCorRbl_B.Assignment1_p);
  }

  /* end of Outputs for SubSystem: '<S8>/F03_RblCorr' */

  /* Update for enable SubSystem: '<S8>/F03_RblCorr' incorporates:
   *  Update for EnablePort: '<S72>/Enable'
   */
  if (localRelationalOperator_pl2) {
    /* Update for UnitDelay: '<S82>/Unit Delay' */
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[0] = KnkMgrCorRbl_B.Assignment1_p[0];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[1] = KnkMgrCorRbl_B.Assignment1_p[1];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[2] = KnkMgrCorRbl_B.Assignment1_p[2];
    KnkMgrCorRbl_DWork.UnitDelay_DSTATE_c[3] = KnkMgrCorRbl_B.Assignment1_p[3];
  }

  /* end of Update for SubSystem: '<S8>/F03_RblCorr' */
}

/* Output and update for function-call system: '<S1>/F05_Interface' */
void KnkMgrCorRbl_F05_Interface(void)
{
  /* Outputs for enable SubSystem: '<S9>/F05_Interface' incorporates:
   *  Constant: '<S9>/ConstVal'
   *  Constant: '<S9>/KNKMGRCORRBL_u8Inhib'
   *  EnablePort: '<S99>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (KNKMGRCORRBL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S99>/VEMS_vidGET */
    VEMS_vidGET(Autorise_detection_rbl, KnkMgrCorRbl_B.VEMS_vidGET_f);

    /* SignalConversion: '<S99>/Signal Conversion4' */
    KnkMgt_bMonRunORng_RblVlvPosn = KnkMgrCorRbl_B.VEMS_vidGET_f;

    /* SignalConversion: '<S99>/Signal Conversion5' */
    KnkMgt_bMonRunORng_RblTmpLdLim = KnkMgrCorRbl_B.VEMS_vidGET_f;

    /* SignalConversion: '<S99>/Signal Conversion8' */
    KnkMgt_bMonRunORng_RblIrvLdLim = KnkMgrCorRbl_B.VEMS_vidGET_f;

    /* S-Function "vems_vidGET" Block: <S99>/VEMS_vidGET1 */
    VEMS_vidGET(KnkMgt_bAcvIrvLdLimRblReq, KnkMgrCorRbl_B.VEMS_vidGET1_f);

    /* SignalConversion: '<S99>/Signal Conversion1' */
    KnkMgt_bDgoORng_RblIrvLdLim = KnkMgrCorRbl_B.VEMS_vidGET1_f;

    /* S-Function "vems_vidGET" Block: <S99>/VEMS_vidGET3 */
    VEMS_vidGET(KnkMgt_bAcvVlvPosnRblReq, KnkMgrCorRbl_B.VEMS_vidGET3_d);

    /* SignalConversion: '<S99>/Signal Conversion2' */
    KnkMgt_bDgoORng_RblVlvPosn = KnkMgrCorRbl_B.VEMS_vidGET3_d;

    /* S-Function "vems_vidGET" Block: <S99>/VEMS_vidGET2 */
    VEMS_vidGET(KnkMgt_bAcvTmpLdLimRblReq, KnkMgrCorRbl_B.VEMS_vidGET2_c);

    /* SignalConversion: '<S99>/Signal Conversion3' */
    KnkMgt_bDgoORng_RblTmpLdLim = KnkMgrCorRbl_B.VEMS_vidGET2_c;
  }

  /* end of Outputs for SubSystem: '<S9>/F05_Interface' */
}

/* Start for exported function: KnkTreat_EveRbl_KnkMgrCorRbl */
void KnkTreat_EveRbl_KnkMgrCorRbl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc1'
   *
   * Block requirements for '<S1>/demux_fc1':
   *  1. SubSystem "demux_fc1" !Trace_To : VEMS_E_10_02583_002.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_BenchMode'
   *  Start for SubSystem: '<S1>/F02_RblCount'
   *  Start for SubSystem: '<S1>/F03_RblCorr'
   *  Start for SubSystem: '<S1>/F05_Interface'
   *  Start for SubSystem: '<S1>/F06_Previous'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu1'
   *  Start for SubSystem: '<S1>/GDGAR_vidGdu2'
   *
   * Block requirements for '<S1>/F01_BenchMode':
   *  1. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_009.01 ;
   *  2. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F02_RblCount':
   *  1. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_005.01 ;
   *  2. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F03_RblCorr':
   *  1. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_001.01 ;
   *  2. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F05_Interface':
   *  1. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F06_Previous':
   *  1. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_004.01 ;
   */
  KnkMgrCorRb_F01_BenchMode_Start();
}

/* Output and update for exported function: KnkTreat_EveRbl_KnkMgrCorRbl */
void KnkTreat_EveRbl_KnkMgrCorRbl(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc1'
   *
   * Block requirements for '<S1>/demux_fc1':
   *  1. SubSystem "demux_fc1" !Trace_To : VEMS_E_10_02583_002.01 ;
   */

  /* S-Function (fcncallgen): '<S15>/gen' incorporates:
   *  SubSystem: '<S1>/F01_BenchMode'
   *  SubSystem: '<S1>/F02_RblCount'
   *  SubSystem: '<S1>/F03_RblCorr'
   *  SubSystem: '<S1>/F05_Interface'
   *  SubSystem: '<S1>/F06_Previous'
   *  SubSystem: '<S1>/GDGAR_vidGdu'
   *  SubSystem: '<S1>/GDGAR_vidGdu1'
   *  SubSystem: '<S1>/GDGAR_vidGdu2'
   *
   * Block requirements for '<S1>/F01_BenchMode':
   *  1. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_009.01 ;
   *  2. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F01_BenchMode" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F02_RblCount':
   *  1. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_005.01 ;
   *  2. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F02_RblCount" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F03_RblCorr':
   *  1. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_001.01 ;
   *  2. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  3. SubSystem "F03_RblCorr" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F05_Interface':
   *  1. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F05_Interface" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F06_Previous':
   *  1. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F06_Previous" !Trace_To : VEMS_E_10_02583_004.01 ;
   */
  KnkMgrCorRbl_F06_Previous();
  KnkMgrCorRbl_F01_BenchMode();
  KnkMgrCorRbl_F02_RblCount();
  KnkMgrCorRbl_F03_RblCorr();
  KnkMgrCorRbl_F05_Interface();

  /* Outputs for atomic SubSystem: '<S11>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S101>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNG_RBLVLVPOSN, KnkMgt_bDgoORng_RblVlvPosn,
               KnkMgt_bMonRunORng_RblVlvPosn, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S11>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S12>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S102>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNG_RBLTMPLDLIM, KnkMgt_bDgoORng_RblTmpLdLim,
               KnkMgt_bMonRunORng_RblTmpLdLim, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S12>/GDGAR_vidGdu' */

  /* Outputs for atomic SubSystem: '<S13>/GDGAR_vidGdu' */
  /* S-Function "GDGAR_bGetFRM" Block: <S103>/S-Function */
  GDGAR_vidGdu(GD_DFT_ORNG_RBLIRVLDLIM, KnkMgt_bDgoORng_RblIrvLdLim,
               KnkMgt_bMonRunORng_RblIrvLdLim, DIAG_DISPO);

  /* end of Outputs for SubSystem: '<S13>/GDGAR_vidGdu' */
}

/* Output and update for function-call system: '<S1>/F01_Init' */
void KnkMgrCorRbl_F01_Init(void)
{
  /* SignalConversion: '<S5>/TmpSignal ConversionAtVEMS_vidSETInport1' incorporates:
   *  Constant: '<S5>/ConstVal'
   */
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_e[0] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_e[1] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_e[2] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_e[3] = 0U;

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET */
  VEMS_vidSET1DArray(KnkMgt_ctPerdRbl, 4,
                     KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_e);
}

/* Output and update for function-call system: '<S1>/F01_InitBis' */
void KnkMgrCorRbl_F01_InitBis(void)
{
  /* SignalConversion: '<S6>/TmpSignal ConversionAtVEMS_vidSET1Inport1' incorporates:
   *  Constant: '<S6>/ConstVal_1'
   */
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vidSE[0] = 16U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vidSE[1] = 16U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vidSE[2] = 16U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vidSE[3] = 16U;

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
  VEMS_vidSET1DArray(KnkMgt_idxMinPosnRbl, 4,
                     KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vidSE);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtVEMS_vidSETInport1' incorporates:
   *  Constant: '<S6>/ConstVal'
   */
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_n[0] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_n[1] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_n[2] = 0U;
  KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_n[3] = 0U;

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
  VEMS_vidSET1DArray(KnkMgt_ctTDCInjCutOff, 4,
                     KnkMgrCorRbl_B.TmpSignalConversionAtVEMS_vid_n);
}

/* Start for exported function: KnkTreat_EveRst_KnkMgrCorRbl */
void KnkTreat_EveRst_KnkMgrCorRbl_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/demux_fc'
   *
   * Block requirements for '<S1>/demux_fc':
   *  1. SubSystem "demux_fc" !Trace_To : VEMS_E_10_02583_002.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  Start for SubSystem: '<S1>/F01_Init'
   *  Start for SubSystem: '<S1>/F01_InitBis'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F01_InitBis':
   *  1. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_004.01 ;
   */
}

/* Output and update for exported function: KnkTreat_EveRst_KnkMgrCorRbl */
void KnkTreat_EveRst_KnkMgrCorRbl(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/demux_fc'
   *
   * Block requirements for '<S1>/demux_fc':
   *  1. SubSystem "demux_fc" !Trace_To : VEMS_E_10_02583_002.01 ;
   */

  /* S-Function (fcncallgen): '<S14>/gen' incorporates:
   *  SubSystem: '<S1>/F01_Init'
   *  SubSystem: '<S1>/F01_InitBis'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : VEMS_E_10_02583_004.01 ;
   *
   * Block requirements for '<S1>/F01_InitBis':
   *  1. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_003.01 ;
   *  2. SubSystem "F01_InitBis" !Trace_To : VEMS_E_10_02583_004.01 ;
   */
  KnkMgrCorRbl_F01_Init();
  KnkMgrCorRbl_F01_InitBis();
}

/* Model initialize function */
void KnkMgrCorRbl_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  KnkTreat_EveRbl_KnkMgrCorRbl_Start();
  KnkTreat_EveRst_KnkMgrCorRbl_Start();
}

#define KNKMGRCORRBL_STOP_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
