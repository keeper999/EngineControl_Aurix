/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : mFuSp                                                   */
/* !Description     : INJECTION MASS PER CYLINDER                             */
/*                                                                            */
/* !Module          : mFuSp                                                   */
/*                                                                            */
/* !File            : mFuSp.c                                                 */
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
/* !Reference       : PTS_DOC_5060285 / 05                                    */
/* !OtherRefs       : VEMS V02 ECU#065798                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Jul 17 12:40:01 2013                              */
/*   Model name       : mFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.274                                                 */
/*   Root subsystem   : /mFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/MFUSP/mFuSp.c_v           $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "mFuSp.h"
#include "mFuSp_private.h"

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
#define MFUSP_START_SEC_VAR_UNSPECIFIED
#include "mFuSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_mFuSp mFuSp_B;

/* Block states (auto storage) */
D_Work_mFuSp mFuSp_DWork;

#define MFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "mFuSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define MFUSP_START_SEC_CODE
#include "mFuSp_MemMap.h"

void mFuSp_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S6>/F02_mFuSpSyncEve2' */
void mFuSp_F02_mFuSpSyncEve2(void)
{
  UInt16 localSelector1;
  UInt16 localAssignment1[6];
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S55>/F00_mFuSpSyncEve' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Constant: '<S55>/MFUSP_u8Inhib'
   *  EnablePort: '<S59>/Enable'
   *  RelationalOperator: '<S55>/Relational Operator'
   */
  if (MFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S59>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_facInjCmpCyl, 6, mFuSp_B.VEMS_vidGET3_h);

    /* S-Function "vems_vidGET" Block: <S59>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInNxtCyl, mFuSp_B.VEMS_vidGET_o);

    /* Selector: '<S59>/Selector1' */
    localSelector1 = mFuSp_B.VEMS_vidGET3_h[mFuSp_B.VEMS_vidGET_o - 1];

    /* S-Function "vems_vidGET" Block: <S59>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, mFuSp_B.VEMS_vidGET1_p);

    /* Assignment: '<S59>/Assignment' */
    for (locali = 0; locali < 6; locali++) {
      mFuSp_B.Assignment[(locali)] = mFuSp_B.VEMS_vidGET3_h[(locali)];
    }

    mFuSp_B.Assignment[mFuSp_B.VEMS_vidGET1_p - 1] = localSelector1;

    /* S-Function "vems_vidGET" Block: <S59>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjSys_prm_mFuSpCyl, 6, mFuSp_B.VEMS_vidGET2_n);

    /* Selector: '<S59>/Selector2' */
    localSelector1 = mFuSp_B.VEMS_vidGET2_n[mFuSp_B.VEMS_vidGET_o - 1];

    /* Assignment: '<S59>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment1[locali] = mFuSp_B.VEMS_vidGET2_n[(locali)];
    }

    localAssignment1[mFuSp_B.VEMS_vidGET1_p - 1] = localSelector1;

    /* RelationalOperator: '<S59>/Relational Operator' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    InjSys_bFuSpCylNull = (localSelector1 == 0);

    /* Switch: '<S59>/Switch' */
    for (locali = 0; locali < 6; locali++) {
      if (InjSys_bFuSpCylNull) {
        mFuSp_B.Switch[(locali)] = mFuSp_B.VEMS_vidGET2_n[(locali)];
      } else {
        mFuSp_B.Switch[(locali)] = localAssignment1[locali];
      }
    }

    /* Selector: '<S59>/Selector3' */
    mFuSp_B.Selector3 = mFuSp_B.Switch[mFuSp_B.VEMS_vidGET1_p - 1];

    /* S-Function "vems_vidSET" Block: <S59>/VEMS_vidSET */
    VEMS_vidSET(InjSys_mFuSp, mFuSp_B.Selector3);

    /* S-Function "vems_vidSET" Block: <S59>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_facInjCmpCyl, 6, mFuSp_B.Assignment);

    /* S-Function "vems_vidSET" Block: <S59>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_mFuSpCyl, 6, mFuSp_B.Switch);
  }

  /* end of Outputs for SubSystem: '<S55>/F00_mFuSpSyncEve' */
}

/* Output and update for exported function: InjSys_EveInj_mFuSp */
void InjSys_EveInj_mFuSp(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S6>/F02_mFuSpSyncEve2'
   */
  mFuSp_F02_mFuSpSyncEve2();
}

/* Output and update for function-call system: '<S6>/F01_Initialize' */
void mFuSp_F01_Initialize(void)
{
  /* S-Function "vems_vidSET" Block: <S53>/VEMS_vidSET */
  VEMS_vidSET(InjSys_mFuSp, 0U);

  /* S-Function "vems_vidSET" Block: <S53>/VEMS_vidSET2 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_mFuSpCyl, 6 , localArray );
  }

  /* S-Function "vems_vidSET" Block: <S53>/VEMS_vidSET1 */
  {
    UInt16 localArray[6] = {
      (0U),
      (0U),
      (0U),
      (0U),
      (0U),
      (0U)
    };

    /* Call of the macro VEMS_vidSET1DArray*/
    VEMS_vidSET1DArray( InjSys_prm_facInjCmpCyl, 6 , localArray );
  }
}

/* Output and update for exported function: InjSys_EveRst_mFuSp */
void InjSys_EveRst_mFuSp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S6>/F01_Initialize'
   */
  mFuSp_F01_Initialize();
}

/* Output and update for function-call system: '<S5>/F01_Calculate_Injection_Mass' */
void mF_F01_Calculate_Injection_Mass(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D;
  Float32 localDataTypeConversion4;
  Boolean localRelationalOperator_l;
  Float32 localSwitch2;
  Boolean localLowerRelop1_i;
  UInt32 localAdd;
  UInt32 localAdd_f;
  SInt32 localmin;
  UInt32 localAdd_fs;
  SInt32 localmin_0;
  SInt32 localmin_1;
  UInt16 localSwitch_b;
  Float32 locallocalDataTypeConversion2_c;
  Float32 locallocalDataTypeConversion2_0;
  Float32 locallocalSum2_n_idx;
  Float32 locallocalSum2_n_idx_0;

  /* Outputs for enable SubSystem: '<S8>/F00_Calculate_Injection_Mass' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/MFUSP_u8Inhib'
   *  EnablePort: '<S9>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (MFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET */
    VEMS_vidGET(AFReg_facCorRichPrec, mFuSp_B.VEMS_vidGET);

    /* DataTypeConversion: '<S9>/Data Type Conversion4' */
    localDataTypeConversion4 = ((Float32)mFuSp_B.VEMS_vidGET) *
      3.051757813E-005F;

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET8 */
    VEMS_vidGET(Ext_nEng, mFuSp_B.VEMS_vidGET8);

    /* DataTypeConversion Block: '<S12>/Data Type Conversion'
     *
     * Regarding '<S12>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET9 */
    VEMS_vidGET(Ext_pDsThrMesSI, mFuSp_B.VEMS_vidGET9);

    /* DataTypeConversion Block: '<S12>/Data Type Conversion1'
     *
     * Regarding '<S12>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S12>/Data Type Duplicate1'
     *
     * Regarding '<S12>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(EngM_prm_mAirPredInCyl, 6, mFuSp_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(EngM_prm_mAirScvCorCyl, 6, mFuSp_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET12 */
    VEMS_vidGET1DArray(FARSp_prm_rMixtCylSp, 6, mFuSp_B.VEMS_vidGET12);

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

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET17 */
    VEMS_vidGET1DArray(InjSys_prm_facStrtCorCyl, 6, mFuSp_B.VEMS_vidGET17);

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

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET18 */
    VEMS_vidGET1DArray(InjSys_prm_facTranCmpCyl, 6, mFuSp_B.VEMS_vidGET18);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate'
     *
     * Regarding '<S36>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate'
     *
     * Regarding '<S37>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET16 */
    VEMS_vidGET1DArray(InjSys_prm_facInjResuCyl, 6, mFuSp_B.VEMS_vidGET16);

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate'
     *
     * Regarding '<S34>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S35>/Data Type Duplicate'
     *
     * Regarding '<S35>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET15 */
    VEMS_vidGET(InjSys_facStoichAdpFlex, mFuSp_B.VEMS_vidGET15);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET11 */
    VEMS_vidGET(Ext_stTypInjSysCf, mFuSp_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET7 */
    VEMS_vidGET(Ext_bGasQly, mFuSp_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET10 */
    VEMS_vidGET1DArray(Ext_prm_idxFuTypCyl, 6, mFuSp_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET1 */
    VEMS_vidGET(EngM_mTotExPred, mFuSp_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET2 */
    VEMS_vidGET(EngM_mTotExPredIn, mFuSp_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET13 */
    VEMS_vidGET1DArray(InM_prm_concFuPredCyl, 6, mFuSp_B.VEMS_vidGET13);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET6 */
    VEMS_vidGET(Eng_noInNxtCyl, mFuSp_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET5 */
    VEMS_vidGET(Eng_noInCyl, mFuSp_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET14 */
    VEMS_vidGET(InjCtl_rDiagTrim, mFuSp_B.VEMS_vidGET14);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET19 */
    VEMS_vidGET(InjCtl_rlamAdapt, mFuSp_B.VEMS_vidGET19);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET20 */
    VEMS_vidGET(OxC_bMonRunORngIntr, mFuSp_B.VEMS_vidGET20);

    /* If: '<S9>/If' incorporates:
     *  ActionPort: '<S10>/Action Port'
     *  ActionPort: '<S11>/Action Port'
     *  Constant: '<S9>/InjSys_bAcvETBFuMass_C'
     *  SubSystem: '<S9>/F01_mFuSpETB'
     *  SubSystem: '<S9>/F02_mFuSpClcn'
     */
    if (InjSys_bAcvETBFuMass_C) {
      /* Lookup2D: '<S12>/Look-Up Table (2-D)'
       * About '<S12>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^3
       * Output0 Data Type:  Fixed Point    U16  2^-27
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D), (&(InjSys_mFuSpETB_M[0])),
                         mFuSp_B.VEMS_vidGET8, (&(Ext_nEngX_A[0])), 15U,
                         mFuSp_B.VEMS_vidGET9, (&(Ext_pDsThrMesSIY_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S12>/Data Type Duplicate2'
       *
       * Regarding '<S12>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S10>/Data Type Conversion2' incorporates:
       *  Constant: '<S10>/InjSys_mETBFuMassSlewRate_C'
       */
      locallocalSum2_n_idx = ((Float32)InjSys_mETBFuMassSlewRate_C) *
        7.450580597E-009F;

      /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
       *  Constant: '<S10>/InjSys_mETBFuMass_C'
       *  Constant: '<S10>/InjSys_noETBSelMassFuSp_C'
       *  Lookup2D: '<S12>/Look-Up Table (2-D)'
       */
      if (InjSys_noETBSelMassFuSp_C == 0) {
        localSwitch_b = InjSys_mETBFuMass_C;
      } else {
        localSwitch_b = localLookUpTable2D;
      }

      /* DataTypeConversion: '<S10>/Data Type Conversion3' */
      locallocalDataTypeConversion2_c = ((Float32)localSwitch_b) *
        7.450580597E-009F;

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/InjSys_bInhCorRichETBFuMass_C'
       *  Product: '<S15>/Divide'
       */
      if (!InjSys_bInhCorRichETBFuMass_C) {
        locallocalDataTypeConversion2_c *= localDataTypeConversion4;
      }

      /* Product: '<S14>/Divide' incorporates:
       *  Constant: '<S10>/InjSys_noETBSelMassFuSp_C2'
       */
      localSwitch2 = -locallocalSum2_n_idx;

      /* RelationalOperator: '<S13>/Relational Operator' incorporates:
       *  Constant: '<S13>/Constant'
       *  UnitDelay: '<S13>/Unit Delay'
       */
      localLowerRelop1_i = (1 == mFuSp_DWork.UnitDelay_DSTATE);

      /* Outputs for enable SubSystem: '<S13>/Slewing' incorporates:
       *  EnablePort: '<S16>/Enable'
       */
      if (localLowerRelop1_i) {
        /* Sum: '<S16>/Sum' incorporates:
         *  DataStoreRead: '<S16>/Data Store Read'
         */
        locallocalSum2_n_idx_0 = locallocalDataTypeConversion2_c - mFuSp_DWork.Y;

        /* RelationalOperator: '<S16>/Relational Operator' */
        localRelationalOperator_l = (locallocalSum2_n_idx_0 >=
          locallocalSum2_n_idx);

        /* Switch: '<S16>/Switch1' incorporates:
         *  RelationalOperator: '<S16>/Relational Operator1'
         */
        if (!(locallocalSum2_n_idx_0 >= localSwitch2)) {
          locallocalSum2_n_idx_0 = localSwitch2;
        }

        /* Switch: '<S16>/Switch' */
        if (localRelationalOperator_l) {
          locallocalSum2_n_idx_0 = locallocalSum2_n_idx;
        }

        /* Sum: '<S16>/Sum1' incorporates:
         *  DataStoreRead: '<S16>/Data Store Read1'
         */
        mFuSp_B.Sum1 = mFuSp_DWork.Y + locallocalSum2_n_idx_0;

        /* DataStoreWrite: '<S16>/Data Store Write' */
        mFuSp_DWork.Y = mFuSp_B.Sum1;
      }

      /* end of Outputs for SubSystem: '<S13>/Slewing' */

      /* Outputs for enable SubSystem: '<S13>/initialisation_slewing' incorporates:
       *  EnablePort: '<S17>/Enable'
       *  Logic: '<S13>/Logical Operator'
       */
      if (!localLowerRelop1_i) {
        /* Inport: '<S17>/INIT_OUTPUT' */
        mFuSp_B.INIT_OUTPUT = locallocalDataTypeConversion2_c;

        /* DataStoreWrite: '<S17>/Data Store Write' */
        mFuSp_DWork.Y = mFuSp_B.INIT_OUTPUT;
      }

      /* end of Outputs for SubSystem: '<S13>/initialisation_slewing' */

      /* Switch: '<S13>/Switch' */
      if (localLowerRelop1_i) {
        locallocalDataTypeConversion2_c = mFuSp_B.Sum1;
      } else {
        locallocalDataTypeConversion2_c = mFuSp_B.INIT_OUTPUT;
      }

      /* SignalConversion: '<S10>/Signal Conversion1' */
      InjSys_prm_mFuSp[0] = locallocalDataTypeConversion2_c;
      InjSys_prm_mFuSp[1] = locallocalDataTypeConversion2_c;

      /* DataTypeConversion: '<S10>/Data Type Conversion1' incorporates:
       *  Constant: '<S10>/InjSys_facInjCmpETB_C'
       */
      locallocalDataTypeConversion2_c = ((Float32)InjSys_facInjCmpETB_C) *
        2.500000119E-004F;

      /* SignalConversion: '<S10>/Signal Conversion2' */
      InjSys_prm_facInjCmp[0] = locallocalDataTypeConversion2_c;
      InjSys_prm_facInjCmp[1] = locallocalDataTypeConversion2_c;

      /* SignalConversion: '<S10>/Signal Conversion3' incorporates:
       *  Constant: '<S10>/InjSys_facInjCmpETB_C1'
       */
      mFuSp_B.Merge3[0] = 0U;
      mFuSp_B.Merge3[1] = 0U;

      /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
       *  Constant: '<S13>/Constant'
       */
      mFuSp_DWork.UnitDelay_DSTATE = 1U;
    } else {
      /* Outputs for atomic SubSystem: '<S11>/F01_Air_Filling' */

      /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
       *  Selector: '<S18>/Selector3'
       *  Selector: '<S18>/Selector4'
       */
      locallocalDataTypeConversion2_c = ((Float32)
        mFuSp_B.VEMS_vidGET3[mFuSp_B.VEMS_vidGET6 - 1]) * 1.192016583E-007F;
      locallocalDataTypeConversion2_0 = ((Float32)
        mFuSp_B.VEMS_vidGET3[mFuSp_B.VEMS_vidGET5 - 1]) * 1.192016583E-007F;

      /* Sum: '<S18>/Sum2' incorporates:
       *  DataTypeConversion: '<S18>/Data Type Conversion1'
       *  Selector: '<S18>/Selector5'
       *  Selector: '<S18>/Selector6'
       */
      locallocalSum2_n_idx = (((Float32)
        mFuSp_B.VEMS_vidGET4[mFuSp_B.VEMS_vidGET6 - 1]) * 1.192016583E-007F) +
        locallocalDataTypeConversion2_c;
      locallocalSum2_n_idx_0 = (((Float32)
        mFuSp_B.VEMS_vidGET4[mFuSp_B.VEMS_vidGET5 - 1]) * 1.192016583E-007F) +
        locallocalDataTypeConversion2_0;

      /* Switch: '<S18>/Switch' incorporates:
       *  Constant: '<S18>/Ext_stTypGslGdi_SC'
       *  RelationalOperator: '<S18>/Relational Operator2'
       */
      if (mFuSp_B.VEMS_vidGET11 != Ext_stTypGslGdi_SC) {
        locallocalDataTypeConversion2_c = locallocalSum2_n_idx;
        locallocalDataTypeConversion2_0 = locallocalSum2_n_idx_0;
      }

      /* MultiPortSwitch: '<S18>/Multiport Switch2' incorporates:
       *  Selector: '<S18>/Selector1'
       *  Selector: '<S18>/Selector2'
       */
      switch (mFuSp_B.VEMS_vidGET10[mFuSp_B.VEMS_vidGET6 - 1]) {
       case 0:
        InjSys_prm_mAirPred[0] = locallocalDataTypeConversion2_c;
        break;

       case 1:
        InjSys_prm_mAirPred[0] = locallocalSum2_n_idx;
        break;

       default:
        InjSys_prm_mAirPred[0] = locallocalDataTypeConversion2_c;
        break;
      }

      switch (mFuSp_B.VEMS_vidGET10[mFuSp_B.VEMS_vidGET5 - 1]) {
       case 0:
        InjSys_prm_mAirPred[1] = locallocalDataTypeConversion2_0;
        break;

       case 1:
        InjSys_prm_mAirPred[1] = locallocalSum2_n_idx_0;
        break;

       default:
        InjSys_prm_mAirPred[1] = locallocalDataTypeConversion2_0;
        break;
      }

      /* end of Outputs for SubSystem: '<S11>/F01_Air_Filling' */

      /* Outputs for atomic SubSystem: '<S11>/F02_Canister_Purge' */

      /* Product: '<S23>/Divide' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       *  DataTypeConversion: '<S19>/Data Type Conversion1'
       *  Selector: '<S19>/Selector1'
       *  Selector: '<S19>/Selector2'
       */
      locallocalDataTypeConversion2_c = (((Float32)
        mFuSp_B.VEMS_vidGET13[mFuSp_B.VEMS_vidGET6 - 1]) * 1.525878906E-005F) *
        (((Float32)mFuSp_B.VEMS_vidGET1) * 1.192016583E-007F);
      locallocalDataTypeConversion2_0 = (((Float32)
        mFuSp_B.VEMS_vidGET13[mFuSp_B.VEMS_vidGET5 - 1]) * 1.525878906E-005F) *
        (((Float32)mFuSp_B.VEMS_vidGET2) * 1.192016583E-007F);

      /* end of Outputs for SubSystem: '<S11>/F02_Canister_Purge' */

      /* Outputs for atomic SubSystem: '<S11>/F03_Stoichiometric_Coefficient' */

      /* DataTypeConversion: '<S20>/Data Type Conversion4' */
      localSwitch2 = ((Float32)mFuSp_B.VEMS_vidGET15) * 3.051757813E-005F;

      /* Switch: '<S28>/Switch2' incorporates:
       *  Constant: '<S24>/Constant'
       *  RelationalOperator: '<S28>/LowerRelop1'
       */
      if (localSwitch2 > 1.0F) {
        localSwitch2 = 1.0F;
      }

      /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
       *  Constant: '<S20>/InjSys_facStoichFlex2_C'
       */
      locallocalSum2_n_idx_0 = ((Float32)InjSys_facStoichFlex2_C) *
        3.051757813E-004F;

      /* Sum: '<S24>/Sum2' incorporates:
       *  Constant: '<S20>/InjSys_facStoichFlex1_C'
       *  DataTypeConversion: '<S20>/Data Type Conversion2'
       *  Product: '<S24>/Divide'
       *  Sum: '<S24>/Sum3'
       */
      InjSys_facStoichFlex_MP = (((((Float32)InjSys_facStoichFlex1_C) *
        3.051757813E-004F) - locallocalSum2_n_idx_0) * localSwitch2) +
        locallocalSum2_n_idx_0;

      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S20>/InjSys_facStoichBasGas_C'
       *  Constant: '<S20>/InjSys_facStoichRichGas_C'
       */
      if (mFuSp_B.VEMS_vidGET7) {
        localSwitch_b = InjSys_facStoichBasGas_C;
      } else {
        localSwitch_b = InjSys_facStoichRichGas_C;
      }

      /* DataTypeConversion: '<S20>/Data Type Conversion3' */
      InjSys_facStoichGas_MP = ((Float32)localSwitch_b) * 3.051757813E-004F;

      /* DataTypeConversion: '<S20>/Data Type Conversion5' incorporates:
       *  Constant: '<S20>/InjSys_facStoichGsl_C'
       */
      localSwitch2 = ((Float32)InjSys_facStoichGsl_C) * 3.051757813E-004F;

      /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
       *  Selector: '<S20>/Selector1'
       *  Selector: '<S20>/Selector2'
       */
      switch (mFuSp_B.VEMS_vidGET10[mFuSp_B.VEMS_vidGET6 - 1]) {
       case 0:
        InjSys_prm_facStoich[0] = localSwitch2;
        break;

       case 1:
        InjSys_prm_facStoich[0] = InjSys_facStoichGas_MP;
        break;

       default:
        InjSys_prm_facStoich[0] = InjSys_facStoichFlex_MP;
        break;
      }

      switch (mFuSp_B.VEMS_vidGET10[mFuSp_B.VEMS_vidGET5 - 1]) {
       case 0:
        InjSys_prm_facStoich[1] = localSwitch2;
        break;

       case 1:
        InjSys_prm_facStoich[1] = InjSys_facStoichGas_MP;
        break;

       default:
        InjSys_prm_facStoich[1] = InjSys_facStoichFlex_MP;
        break;
      }

      /* end of Outputs for SubSystem: '<S11>/F03_Stoichiometric_Coefficient' */

      /* Outputs for atomic SubSystem: '<S11>/F04_Fuel_Mass_Set_Point' */

      /* Product: '<S38>/Divide' */
      localSwitch2 = InjSys_prm_mAirPred[0] / InjSys_prm_facStoich[0];

      /* Outputs for atomic SubSystem: '<S38>/If Action Subsystem3' */

      /* Switch: '<S50>/Switch1' incorporates:
       *  Constant: '<S50>/Constant1'
       *  Constant: '<S50>/Constant2'
       *  Constant: '<S50>/Constant3'
       *  Logic: '<S50>/Logical Operator1'
       *  RelationalOperator: '<S50>/Relational Operator'
       *  RelationalOperator: '<S50>/Relational Operator1'
       *  RelationalOperator: '<S50>/Relational Operator3'
       */
      if (((localSwitch2 != localSwitch2) || (localSwitch2 > 3.000000005E+038F))
          || (-3.000000005E+038F > localSwitch2)) {
        localSwitch2 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S38>/If Action Subsystem3' */

      /* Product: '<S39>/Divide' */
      locallocalSum2_n_idx_0 = InjSys_prm_mAirPred[1] / InjSys_prm_facStoich[1];

      /* Outputs for atomic SubSystem: '<S39>/If Action Subsystem3' */

      /* Switch: '<S52>/Switch1' incorporates:
       *  Constant: '<S52>/Constant1'
       *  Constant: '<S52>/Constant2'
       *  Constant: '<S52>/Constant3'
       *  Logic: '<S52>/Logical Operator1'
       *  RelationalOperator: '<S52>/Relational Operator'
       *  RelationalOperator: '<S52>/Relational Operator1'
       *  RelationalOperator: '<S52>/Relational Operator3'
       */
      if (((locallocalSum2_n_idx_0 != locallocalSum2_n_idx_0) ||
           (locallocalSum2_n_idx_0 > 3.000000005E+038F)) || (-3.000000005E+038F >
           locallocalSum2_n_idx_0)) {
        locallocalSum2_n_idx_0 = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S39>/If Action Subsystem3' */

      /* DataTypeConversion: '<S21>/Data Type Conversion6' */
      localAdd = mFuSp_B.VEMS_vidGET6;

      /* Sum: '<S30>/Add' incorporates:
       *  Constant: '<S30>/Constant1'
       */
      localAdd_f = localAdd - 1U;

      /* MinMax: '<S30>/MinMax' incorporates:
       *  Constant: '<S30>/Constant'
       */
      localmin = (SInt32)rt_MIN(localAdd_f, 5U);

      /* DataTypeConversion: '<S21>/Data Type Conversion7' */
      localAdd_f = mFuSp_B.VEMS_vidGET5;

      /* Sum: '<S31>/Add' incorporates:
       *  Constant: '<S31>/Constant1'
       */
      localAdd_fs = localAdd_f - 1U;

      /* Product: '<S44>/Divide' incorporates:
       *  Constant: '<S31>/Constant'
       *  DataTypeConversion: '<S21>/Data Type Conversion4'
       *  MinMax: '<S31>/MinMax'
       *  Selector: '<S30>/Selector'
       *  Selector: '<S31>/Selector'
       */
      InjSys_prm_mFuReq_MP[0] = (((Float32)mFuSp_B.VEMS_vidGET12[(localmin)]) *
        0.000244140625F) * localSwitch2;
      InjSys_prm_mFuReq_MP[1] = (((Float32)mFuSp_B.VEMS_vidGET12[rt_MIN
        (localAdd_fs, 5U)]) * 0.000244140625F) * locallocalSum2_n_idx_0;

      /* Sum: '<S32>/Add' incorporates:
       *  Constant: '<S32>/Constant1'
       */
      localAdd_fs = localAdd - 1U;

      /* MinMax: '<S32>/MinMax' incorporates:
       *  Constant: '<S32>/Constant'
       */
      localmin = (SInt32)rt_MIN(localAdd_fs, 5U);

      /* Sum: '<S33>/Add' incorporates:
       *  Constant: '<S33>/Constant1'
       */
      localAdd_fs = localAdd_f - 1U;

      /* MinMax: '<S33>/MinMax' incorporates:
       *  Constant: '<S33>/Constant'
       */
      localmin_0 = (SInt32)rt_MIN(localAdd_fs, 5U);

      /* Sum: '<S34>/Add' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      localAdd_fs = localAdd - 1U;

      /* MinMax: '<S34>/MinMax' incorporates:
       *  Constant: '<S34>/Constant'
       */
      localmin_1 = (SInt32)rt_MIN(localAdd_fs, 5U);

      /* Sum: '<S35>/Add' incorporates:
       *  Constant: '<S35>/Constant1'
       */
      localAdd_fs = localAdd_f - 1U;

      /* Product: '<S43>/Divide' incorporates:
       *  Constant: '<S35>/Constant'
       *  DataTypeConversion: '<S21>/Data Type Conversion10'
       *  DataTypeConversion: '<S21>/Data Type Conversion9'
       *  MinMax: '<S35>/MinMax'
       *  Selector: '<S32>/Selector'
       *  Selector: '<S33>/Selector'
       *  Selector: '<S34>/Selector'
       *  Selector: '<S35>/Selector'
       */
      locallocalSum2_n_idx = (((Float32)mFuSp_B.VEMS_vidGET17[(localmin)]) *
        0.000244140625F) * (((Float32)mFuSp_B.VEMS_vidGET16[(localmin_1)]) *
                            2.288818359E-004F);
      locallocalSum2_n_idx_0 = (((Float32)mFuSp_B.VEMS_vidGET17[(localmin_0)]) *
        0.000244140625F) * (((Float32)mFuSp_B.VEMS_vidGET16[rt_MIN(localAdd_fs,
        5U)]) * 2.288818359E-004F);

      /* Sum: '<S36>/Add' incorporates:
       *  Constant: '<S36>/Constant1'
       */
      localAdd--;

      /* Sum: '<S37>/Add' incorporates:
       *  Constant: '<S37>/Constant1'
       */
      localAdd_f--;

      /* Product: '<S40>/Divide' incorporates:
       *  Constant: '<S36>/Constant'
       *  Constant: '<S37>/Constant'
       *  DataTypeConversion: '<S21>/Data Type Conversion5'
       *  MinMax: '<S36>/MinMax'
       *  MinMax: '<S37>/MinMax'
       *  Product: '<S42>/Divide'
       *  Selector: '<S36>/Selector'
       *  Selector: '<S37>/Selector'
       */
      InjSys_prm_mFuReqCmp_MP[0] = (InjSys_prm_mFuReq_MP[0] *
        locallocalSum2_n_idx) * (((Float32)mFuSp_B.VEMS_vidGET18[rt_MIN
        (localAdd, 5U)]) * 0.000244140625F);
      InjSys_prm_mFuReqCmp_MP[1] = (InjSys_prm_mFuReq_MP[1] *
        locallocalSum2_n_idx_0) * (((Float32)mFuSp_B.VEMS_vidGET18[rt_MIN
        (localAdd_f, 5U)]) * 0.000244140625F);

      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S21>/InjSys_mFuMax_C2'
       *  DataTypeConversion: '<S21>/Data Type Conversion8'
       *  Sum: '<S21>/Sum3'
       */
      if (mFuSp_B.VEMS_vidGET20) {
        localDataTypeConversion4 = (((Float32)mFuSp_B.VEMS_vidGET19) *
          7.629394531E-006F) + 1.0F;
      }

      /* Sum: '<S21>/Sum2' incorporates:
       *  Constant: '<S21>/InjSys_mFuMax_C1'
       *  DataTypeConversion: '<S21>/Data Type Conversion1'
       */
      localSwitch2 = (((Float32)mFuSp_B.VEMS_vidGET14) * 0.00390625F) + 1.0F;

      /* Product: '<S45>/Divide' incorporates:
       *  Product: '<S41>/Divide'
       *  Sum: '<S21>/Sum1'
       */
      InjSys_prm_mFuRawTmp_MP[0] = ((InjSys_prm_mFuReqCmp_MP[0] -
        locallocalDataTypeConversion2_c) * localDataTypeConversion4) *
        localSwitch2;
      InjSys_prm_mFuRawTmp_MP[1] = ((InjSys_prm_mFuReqCmp_MP[1] -
        locallocalDataTypeConversion2_0) * localDataTypeConversion4) *
        localSwitch2;

      /* DataTypeConversion: '<S21>/Data Type Conversion2' incorporates:
       *  Constant: '<S21>/InjSys_mFuMax_C'
       */
      localDataTypeConversion4 = ((Float32)InjSys_mFuMax_C) * 7.450580597E-009F;

      /* DataTypeConversion: '<S21>/Data Type Conversion3' incorporates:
       *  Constant: '<S21>/InjSys_mFuMin_C'
       */
      localSwitch2 = ((Float32)InjSys_mFuMin_C) * 7.450580597E-009F;

      /* end of Outputs for SubSystem: '<S11>/F04_Fuel_Mass_Set_Point' */

      /* SignalConversion: '<S21>/Signal Conversion1' incorporates:
       *  RelationalOperator: '<S48>/LowerRelop1'
       *  RelationalOperator: '<S48>/UpperRelop'
       *  Switch: '<S48>/Switch'
       *  Switch: '<S48>/Switch2'
       */
      if (InjSys_prm_mFuRawTmp_MP[0] > localDataTypeConversion4) {
        InjSys_prm_mFuSp[0] = localDataTypeConversion4;
      } else if (InjSys_prm_mFuRawTmp_MP[0] < localSwitch2) {
        InjSys_prm_mFuSp[0] = localSwitch2;
      } else {
        InjSys_prm_mFuSp[0] = InjSys_prm_mFuRawTmp_MP[0];
      }

      /* SignalConversion: '<S21>/Signal Conversion2' */
      InjSys_prm_facInjCmp[0] = locallocalSum2_n_idx;

      /* DataTypeConversion: '<S22>/OutDTConv' incorporates:
       *  Constant: '<S22>/offset'
       *  Constant: '<S22>/offset1'
       *  Constant: '<S22>/one_on_slope'
       *  Product: '<S22>/Product4'
       *  Sum: '<S22>/Add1'
       *  Sum: '<S22>/Add2'
       */
      locallocalSum2_n_idx = (1.34217728E+008F * locallocalDataTypeConversion2_c)
        + 0.5F;
      if (locallocalSum2_n_idx < 65536.0F) {
        localSwitch_b = (UInt16)locallocalSum2_n_idx;
      } else {
        localSwitch_b = MAX_uint16_T;
      }

      mFuSp_B.Merge3[0] = localSwitch_b;

      /* SignalConversion: '<S21>/Signal Conversion1' incorporates:
       *  RelationalOperator: '<S48>/LowerRelop1'
       *  RelationalOperator: '<S48>/UpperRelop'
       *  Switch: '<S48>/Switch'
       *  Switch: '<S48>/Switch2'
       */
      if (InjSys_prm_mFuRawTmp_MP[1] > localDataTypeConversion4) {
        InjSys_prm_mFuSp[1] = localDataTypeConversion4;
      } else if (InjSys_prm_mFuRawTmp_MP[1] < localSwitch2) {
        InjSys_prm_mFuSp[1] = localSwitch2;
      } else {
        InjSys_prm_mFuSp[1] = InjSys_prm_mFuRawTmp_MP[1];
      }

      /* SignalConversion: '<S21>/Signal Conversion2' */
      InjSys_prm_facInjCmp[1] = locallocalSum2_n_idx_0;

      /* DataTypeConversion: '<S22>/OutDTConv' incorporates:
       *  Constant: '<S22>/offset'
       *  Constant: '<S22>/offset1'
       *  Constant: '<S22>/one_on_slope'
       *  Product: '<S22>/Product4'
       *  Sum: '<S22>/Add1'
       *  Sum: '<S22>/Add2'
       */
      locallocalSum2_n_idx = (1.34217728E+008F * locallocalDataTypeConversion2_0)
        + 0.5F;
      if (locallocalSum2_n_idx < 65536.0F) {
        localSwitch_b = (UInt16)locallocalSum2_n_idx;
      } else {
        localSwitch_b = MAX_uint16_T;
      }

      mFuSp_B.Merge3[1] = localSwitch_b;
    }

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET */
    VEMS_vidSET1DArray(InjSys_prm_mCanPurg, 2, mFuSp_B.Merge3);
  }

  /* end of Outputs for SubSystem: '<S8>/F00_Calculate_Injection_Mass' */
}

/* Output and update for function-call system: '<S6>/F02_mFuSpSyncEve1' */
void mFuSp_F02_mFuSpSyncEve1(void)
{
  /* local block i/o variables */
  Boolean localRelationalOperator_hr;
  UInt16 localAssignment2[6];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_idx;
  UInt16 locallocalOutDTConv_idx_0;

  /* RelationalOperator: '<S54>/Relational Operator' incorporates:
   *  Constant: '<S54>/Constant1'
   *  Constant: '<S54>/MFUSP_u8Inhib'
   */
  localRelationalOperator_hr = (MFUSP_u8Inhib != 90);

  /* Outputs for enable SubSystem: '<S54>/F00_mFuSpSyncEve1' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (localRelationalOperator_hr) {
    /* S-Function "vems_vidGET" Block: <S56>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(InjSys_prm_mFuSpCyl, 6, InjSys_prm_mFuSpCylPrev);

    /* DataTypeConversion: '<S57>/OutDTConv' incorporates:
     *  Constant: '<S57>/offset'
     *  Constant: '<S57>/offset1'
     *  Constant: '<S57>/one_on_slope'
     *  Product: '<S57>/Product4'
     *  Sum: '<S57>/Add1'
     *  Sum: '<S57>/Add2'
     */
    localtmp = (1.34217728E+008F * InjSys_prm_mFuSp[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (1.34217728E+008F * InjSys_prm_mFuSp[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* S-Function "vems_vidGET" Block: <S56>/VEMS_vidGET1 */
    VEMS_vidGET(Eng_noInNxtCyl, mFuSp_B.VEMS_vidGET1_f);

    /* Assignment: '<S56>/Assignment' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment2[locali] = InjSys_prm_mFuSpCylPrev[(locali)];
    }

    localAssignment2[mFuSp_B.VEMS_vidGET1_f - 1] = locallocalOutDTConv_idx;

    /* S-Function "vems_vidGET" Block: <S56>/VEMS_vidGET */
    VEMS_vidGET(Eng_noInCyl, mFuSp_B.VEMS_vidGET_e);

    /* Assignment: '<S56>/Assignment1' */
    for (locali = 0; locali < 6; locali++) {
      mFuSp_B.Assignment1[(locali)] = localAssignment2[locali];
    }

    mFuSp_B.Assignment1[mFuSp_B.VEMS_vidGET_e - 1] = locallocalOutDTConv_idx_0;

    /* S-Function "vems_vidGET" Block: <S56>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(InjSys_prm_facInjCmpCyl, 6, InjSys_prm_facInjCmpCylPrev);

    /* DataTypeConversion: '<S58>/OutDTConv' incorporates:
     *  Constant: '<S58>/offset'
     *  Constant: '<S58>/offset1'
     *  Constant: '<S58>/one_on_slope'
     *  Product: '<S58>/Product4'
     *  Sum: '<S58>/Add1'
     *  Sum: '<S58>/Add2'
     */
    localtmp = (4000.0F * InjSys_prm_facInjCmp[0]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx = 0U;
      }
    } else {
      locallocalOutDTConv_idx = MAX_uint16_T;
    }

    localtmp = (4000.0F * InjSys_prm_facInjCmp[1]) + 0.5F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        locallocalOutDTConv_idx_0 = (UInt16)localtmp;
      } else {
        locallocalOutDTConv_idx_0 = 0U;
      }
    } else {
      locallocalOutDTConv_idx_0 = MAX_uint16_T;
    }

    /* Assignment: '<S56>/Assignment2' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment2[locali] = InjSys_prm_facInjCmpCylPrev[(locali)];
    }

    localAssignment2[mFuSp_B.VEMS_vidGET1_f - 1] = locallocalOutDTConv_idx;

    /* Assignment: '<S56>/Assignment3' */
    for (locali = 0; locali < 6; locali++) {
      mFuSp_B.Assignment3[(locali)] = localAssignment2[locali];
    }

    mFuSp_B.Assignment3[mFuSp_B.VEMS_vidGET_e - 1] = locallocalOutDTConv_idx_0;

    /* Selector: '<S56>/Selector1' */
    mFuSp_B.Selector1 = mFuSp_B.Assignment1[mFuSp_B.VEMS_vidGET1_f - 1];

    /* S-Function "vems_vidSET" Block: <S56>/VEMS_vidSET */
    VEMS_vidSET(InjSys_mFuSp, mFuSp_B.Selector1);

    /* S-Function "vems_vidSET" Block: <S56>/VEMS_vidSET1 */
    VEMS_vidSET1DArray(InjSys_prm_facInjCmpCyl, 6, mFuSp_B.Assignment3);

    /* S-Function "vems_vidSET" Block: <S56>/VEMS_vidSET2 */
    VEMS_vidSET1DArray(InjSys_prm_mFuSpCyl, 6, mFuSp_B.Assignment1);
  }

  /* end of Outputs for SubSystem: '<S54>/F00_mFuSpSyncEve1' */
}

/* Start for exported function: InjSys_SdlFast_mFuSp */
void InjSys_SdlFast_mFuSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S4>/mFuSp_fc_demux2'
   */

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S5>/F01_Calculate_Injection_Mass'
   *  Start for SubSystem: '<S6>/F02_mFuSpSyncEve1'
   */
}

/* Output and update for exported function: InjSys_SdlFast_mFuSp */
void InjSys_SdlFast_mFuSp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S4>/mFuSp_fc_demux2'
   */

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  SubSystem: '<S5>/F01_Calculate_Injection_Mass'
   *  SubSystem: '<S6>/F02_mFuSpSyncEve1'
   */
  mF_F01_Calculate_Injection_Mass();
  mFuSp_F02_mFuSpSyncEve1();
}

/* Model initialize function */
void mFuSp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  InjSys_SdlFast_mFuSp_Start();
}

#define MFUSP_STOP_SEC_CODE
#include "mFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
