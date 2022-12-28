/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : pFuSp                                                   */
/* !Description     : pFuSp : Fuel Pressure Set Point                         */
/*                                                                            */
/* !Module          : pFuSp                                                   */
/*                                                                            */
/* !File            : pFuSp.c                                                 */
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
/* !Reference       : V02NT1104340 / 03                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Dec 20 19:22:07 2012                              */
/*   Model name       : pFuSp_AUTOCODE.mdl                                    */
/*   Model version    : 1.341                                                 */
/*   Root subsystem   : /pFuSp                                                */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/PFUSP/PfuSp.c_v           $*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "pFuSp.h"
#include "pFuSp_private.h"

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
#define PFUSP_START_SEC_VAR_UNSPECIFIED
#include "pFuSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_pFuSp pFuSp_B;

/* Block states (auto storage) */
D_Work_pFuSp pFuSp_DWork;

#define PFUSP_STOP_SEC_VAR_UNSPECIFIED
#include "pFuSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define PFUSP_START_SEC_CODE
#include "pFuSp_MemMap.h"

void pFuSp_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S3>/F01_Initialization' */
void pFuSp_F01_Initialization(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET7 */
  VEMS_vidSET(InjSys_pFuSp, 640U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_bAcvSpcInjMod, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(InjSys_bAcvAirLdMinSat, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET6 */
  VEMS_vidSET(InjSys_bInjSpNotAccu, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_bAcvCllRailDcha, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET4 */
  VEMS_vidSET(InjSys_bHPPmpCutOff, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET3 */
  VEMS_vidSET(InjSys_bCanPurgCutOff, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET5 */
  VEMS_vidSET(InjSys_bInhInjCutOffPFuDcha, FALSE);
}

/* Output and update for exported function: InjSys_EveRst_pFuSp */
void InjSys_EveRst_pFuSp(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S3>/F01_Initialization'
   */
  pFuSp_F01_Initialization();
}

/* Start for function-call system: '<S3>/F02_pFuSp' */
void pFuSp_F02_pFuSp_Start(void)
{
  /* Start for enable SubSystem: '<S5>/F02_pFuSp' */

  /* InitializeConditions for Memory: '<S100>/Memory' */
  pFuSp_DWork.Memory_PreviousInput = TRUE;

  /* InitializeConditions for UnitDelay: '<S111>/Unit Delay' */
  pFuSp_DWork.UnitDelay_DSTATE_a = 6500U;

  /* end of Start for SubSystem: '<S5>/F02_pFuSp' */
}

/* Output and update for function-call system: '<S3>/F02_pFuSp' */
void pFuSp_F02_pFuSp(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D;
  Boolean localLogic[2];
  Boolean localRelationalOperator1_fa;
  Boolean localLogic_n[2];
  Boolean localLogicalOperator3;
  Boolean localSwitch_j;
  Boolean localLogic_l[2];
  Boolean localUnitDelay_g;
  Boolean localMemory;
  Boolean localSwitch_l;
  Float32 localDTConv_UFix_To_Single_1;
  Boolean localLogicalOperator;
  Boolean localRelationalOperator2;
  Boolean localRelationalOperator1;
  Boolean localSwitch2_k;
  Float32 localDivide_a;
  Boolean localAssignment3[15];
  UInt8 localSwitch2_h;
  Float32 localSwitch2_f;
  Boolean localLowerRelop1_d;
  Float32 localAdd2_k;
  Float32 localLookupTablenD;
  Float32 localLookupTablenD_m;
  Float32 localDataTypeConversion6;
  Boolean localRelationalOperator1_i;
  Float32 localSwitch_m;
  Boolean localRelationalOperator_f;
  UInt16 localMultiportSwitch;
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S5>/F02_pFuSp' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/PFUSP_u8Inhib'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (PFUSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, pFuSp_B.VEMS_vidGET);

    /* DataTypeConversion Block: '<S10>/Data Type Conversion'
     *
     * Regarding '<S10>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pDsThrMesSI, pFuSp_B.VEMS_vidGET1);

    /* DataTypeConversion Block: '<S10>/Data Type Conversion1'
     *
     * Regarding '<S10>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate1'
     *
     * Regarding '<S10>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET14 */
    VEMS_vidGET(InjSys_mAirPredInjSp, pFuSp_B.VEMS_vidGET14);

    /* DataTypeConversion Block: '<S53>/Data Type Conversion1'
     *
     * Regarding '<S53>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate1'
     *
     * Regarding '<S53>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S54>/Data Type Conversion1'
     *
     * Regarding '<S54>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate1'
     *
     * Regarding '<S54>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S55>/Data Type Conversion1'
     *
     * Regarding '<S55>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate1'
     *
     * Regarding '<S55>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S56>/Data Type Conversion1'
     *
     * Regarding '<S56>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate1'
     *
     * Regarding '<S56>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S57>/Data Type Conversion1'
     *
     * Regarding '<S57>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate1'
     *
     * Regarding '<S57>/Data Type Duplicate1':
     *   Unused code path elimination
     */

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

    /* DataTypeConversion Block: '<S61>/Data Type Conversion1'
     *
     * Regarding '<S61>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate1'
     *
     * Regarding '<S61>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S62>/Data Type Conversion1'
     *
     * Regarding '<S62>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate1'
     *
     * Regarding '<S62>/Data Type Duplicate1':
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

    /* DataTypeConversion Block: '<S65>/Data Type Conversion1'
     *
     * Regarding '<S65>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate1'
     *
     * Regarding '<S65>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET15 */
    VEMS_vidGET(InjSys_nEngInjSp, pFuSp_B.VEMS_vidGET15);

    /* DataTypeConversion Block: '<S53>/Data Type Conversion'
     *
     * Regarding '<S53>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S54>/Data Type Conversion'
     *
     * Regarding '<S54>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S55>/Data Type Conversion'
     *
     * Regarding '<S55>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S56>/Data Type Conversion'
     *
     * Regarding '<S56>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S57>/Data Type Conversion'
     *
     * Regarding '<S57>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S58>/Data Type Conversion'
     *
     * Regarding '<S58>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S59>/Data Type Conversion'
     *
     * Regarding '<S59>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S60>/Data Type Conversion'
     *
     * Regarding '<S60>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S61>/Data Type Conversion'
     *
     * Regarding '<S61>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S62>/Data Type Conversion'
     *
     * Regarding '<S62>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S63>/Data Type Conversion'
     *
     * Regarding '<S63>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S64>/Data Type Conversion'
     *
     * Regarding '<S64>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S65>/Data Type Conversion'
     *
     * Regarding '<S65>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET10 */
    VEMS_vidGET(InjSys_idxBas1ModCurPfuSp, pFuSp_B.VEMS_vidGET10);

    /* DataTypeDuplicate Block: '<S24>/Data Type Duplicate'
     *
     * Regarding '<S24>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate'
     *
     * Regarding '<S25>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S26>/Data Type Propagation'
     *
     * Regarding '<S26>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET12 */
    VEMS_vidGET(InjSys_idxBas2ModCurPfuSp, pFuSp_B.VEMS_vidGET12);

    /* DataTypeDuplicate Block: '<S27>/Data Type Duplicate'
     *
     * Regarding '<S27>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
     *
     * Regarding '<S28>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S29>/Data Type Propagation'
     *
     * Regarding '<S29>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET11 */
    VEMS_vidGET(InjSys_idxBas1ModTarPfuSp, pFuSp_B.VEMS_vidGET11);

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

    /* S-Function Block: '<S32>/Data Type Propagation'
     *
     * Regarding '<S32>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET13 */
    VEMS_vidGET(InjSys_idxBas2ModTarPfuSp, pFuSp_B.VEMS_vidGET13);

    /* DataTypeDuplicate Block: '<S33>/Data Type Duplicate'
     *
     * Regarding '<S33>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S34>/Data Type Duplicate'
     *
     * Regarding '<S34>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S35>/Data Type Propagation'
     *
     * Regarding '<S35>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_facBasModCurPfuSp, pFuSp_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_facBasModTarPfuSp, pFuSp_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_facTranModPfuSp, pFuSp_B.VEMS_vidGET9);

    /* If: '<S6>/If' incorporates:
     *  ActionPort: '<S7>/Action Port'
     *  ActionPort: '<S8>/Action Port'
     *  Constant: '<S6>/InjSys_bAcvETBpFuSp_C'
     *  SubSystem: '<S6>/F00_pFuSpETB'
     *  SubSystem: '<S6>/F01_pFuSpClcn'
     */
    if (InjSys_bAcvETBpFuSp_C) {
      /* DataTypeConversion: '<S7>/DTConv_Single_To_UFix_1' incorporates:
       *  Constant: '<S7>/ InjSys_pFuSpETBSlewRate_C'
       */
      localSwitch2_f = ((Float32)InjSys_pFuSpETBSlewRate_C) * 781.25F;

      /* Lookup2D: '<S10>/Look-Up Table (2-D)'
       * About '<S10>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^3
       * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D), (&(InjSys_pFuSpETB_M[0])),
                         pFuSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                         pFuSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate2'
       *
       * Regarding '<S10>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
       *  Constant: '<S7>/InjSys_noETBSelpFuSp_C'
       *  Constant: '<S7>/InjSys_pFuSpETB_C'
       *  Lookup2D: '<S10>/Look-Up Table (2-D)'
       */
      if (InjSys_noETBSelpFuSp_C == 0) {
        localMultiportSwitch = InjSys_pFuSpETB_C;
      } else {
        localMultiportSwitch = localLookUpTable2D;
      }

      /* DataTypeConversion: '<S7>/DTConv_Single_To_UFix_2' */
      localAdd2_k = ((Float32)localMultiportSwitch) * 781.25F;

      /* Product: '<S13>/Divide' incorporates:
       *  Constant: '<S7>/Constant'
       */
      localDivide_a = -localSwitch2_f;

      /* RelationalOperator: '<S12>/Relational Operator' incorporates:
       *  Constant: '<S12>/Constant'
       *  UnitDelay: '<S12>/Unit Delay'
       */
      localLowerRelop1_d = (1 == pFuSp_DWork.UnitDelay_DSTATE_m);

      /* Outputs for enable SubSystem: '<S12>/Slewing' incorporates:
       *  EnablePort: '<S14>/Enable'
       */
      if (localLowerRelop1_d) {
        /* Sum: '<S14>/Sum' incorporates:
         *  DataStoreRead: '<S14>/Data Store Read'
         */
        localSwitch_m = localAdd2_k - pFuSp_DWork.Y;

        /* RelationalOperator: '<S14>/Relational Operator' */
        localRelationalOperator_f = (localSwitch_m >= localSwitch2_f);

        /* Switch: '<S14>/Switch1' incorporates:
         *  RelationalOperator: '<S14>/Relational Operator1'
         */
        if (!(localSwitch_m >= localDivide_a)) {
          localSwitch_m = localDivide_a;
        }

        /* Switch: '<S14>/Switch' */
        if (localRelationalOperator_f) {
          localSwitch_m = localSwitch2_f;
        }

        /* Sum: '<S14>/Sum1' incorporates:
         *  DataStoreRead: '<S14>/Data Store Read1'
         */
        pFuSp_B.Sum1 = pFuSp_DWork.Y + localSwitch_m;

        /* DataStoreWrite: '<S14>/Data Store Write' */
        pFuSp_DWork.Y = pFuSp_B.Sum1;
      }

      /* end of Outputs for SubSystem: '<S12>/Slewing' */

      /* Outputs for enable SubSystem: '<S12>/initialisation_slewing' incorporates:
       *  EnablePort: '<S15>/Enable'
       *  Logic: '<S12>/Logical Operator'
       */
      if (!localLowerRelop1_d) {
        /* Inport: '<S15>/INIT_OUTPUT' */
        pFuSp_B.INIT_OUTPUT = localAdd2_k;

        /* DataStoreWrite: '<S15>/Data Store Write' */
        pFuSp_DWork.Y = pFuSp_B.INIT_OUTPUT;
      }

      /* end of Outputs for SubSystem: '<S12>/initialisation_slewing' */

      /* Switch: '<S12>/Switch' */
      if (localLowerRelop1_d) {
        localSwitch2_f = pFuSp_B.Sum1;
      } else {
        localSwitch2_f = pFuSp_B.INIT_OUTPUT;
      }

      /* DataTypeConversion: '<S11>/OutDTConv' incorporates:
       *  Constant: '<S11>/offset'
       *  Constant: '<S11>/offset1'
       *  Constant: '<S11>/one_on_slope'
       *  Product: '<S11>/Product4'
       *  Sum: '<S11>/Add1'
       *  Sum: '<S11>/Add2'
       */
      localSwitch2_f = (1.279999968E-003F * localSwitch2_f) + 0.5F;
      if (localSwitch2_f < 65536.0F) {
        if (localSwitch2_f >= 0.0F) {
          pFuSp_B.Merge = (UInt16)localSwitch2_f;
        } else {
          pFuSp_B.Merge = 0U;
        }
      } else {
        pFuSp_B.Merge = MAX_uint16_T;
      }

      /* Update for UnitDelay: '<S12>/Unit Delay' incorporates:
       *  Constant: '<S12>/Constant'
       */
      pFuSp_DWork.UnitDelay_DSTATE_m = 1U;
    } else {
      /* SignalConversion: '<S16>/TmpSignal ConversionAtAssignment1Inport1' incorporates:
       *  Constant: '<S16>/ConstVal'
       */
      localAssignment3[0] = FALSE;
      localAssignment3[1] = FALSE;
      localAssignment3[2] = FALSE;
      localAssignment3[3] = FALSE;
      localAssignment3[4] = FALSE;
      localAssignment3[5] = FALSE;
      localAssignment3[6] = FALSE;
      localAssignment3[7] = FALSE;
      localAssignment3[8] = FALSE;
      localAssignment3[9] = FALSE;
      localAssignment3[10] = FALSE;
      localAssignment3[11] = FALSE;
      localAssignment3[12] = FALSE;
      localAssignment3[13] = FALSE;
      localAssignment3[14] = FALSE;

      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMin_C'
       *  RelationalOperator: '<S26>/UpperRelop'
       */
      if (pFuSp_B.VEMS_vidGET10 < InjSys_idxModPfuSatMin_C) {
        localSwitch2_h = InjSys_idxModPfuSatMin_C;
      } else {
        localSwitch2_h = pFuSp_B.VEMS_vidGET10;
      }

      /* Switch: '<S26>/Switch2' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMax_C'
       *  RelationalOperator: '<S26>/LowerRelop1'
       */
      if (pFuSp_B.VEMS_vidGET10 > InjSys_idxModPfuSatMax_C) {
        localSwitch2_h = InjSys_idxModPfuSatMax_C;
      }

      /* Assignment: '<S16>/Assignment1' incorporates:
       *  Constant: '<S16>/ConstVal_1'
       */
      localAssignment3[localSwitch2_h - 1] = TRUE;

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMin_C_1'
       *  RelationalOperator: '<S29>/UpperRelop'
       */
      if (pFuSp_B.VEMS_vidGET12 < InjSys_idxModPfuSatMin_C) {
        localSwitch2_h = InjSys_idxModPfuSatMin_C;
      } else {
        localSwitch2_h = pFuSp_B.VEMS_vidGET12;
      }

      /* Switch: '<S29>/Switch2' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMax_C_1'
       *  RelationalOperator: '<S29>/LowerRelop1'
       */
      if (pFuSp_B.VEMS_vidGET12 > InjSys_idxModPfuSatMax_C) {
        localSwitch2_h = InjSys_idxModPfuSatMax_C;
      }

      /* Assignment: '<S16>/Assignment2' incorporates:
       *  Constant: '<S16>/ConstVal_2'
       */
      localAssignment3[localSwitch2_h - 1] = TRUE;

      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMin_C_2'
       *  RelationalOperator: '<S32>/UpperRelop'
       */
      if (pFuSp_B.VEMS_vidGET11 < InjSys_idxModPfuSatMin_C) {
        localSwitch2_h = InjSys_idxModPfuSatMin_C;
      } else {
        localSwitch2_h = pFuSp_B.VEMS_vidGET11;
      }

      /* Switch: '<S32>/Switch2' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMax_C_2'
       *  RelationalOperator: '<S32>/LowerRelop1'
       */
      if (pFuSp_B.VEMS_vidGET11 > InjSys_idxModPfuSatMax_C) {
        localSwitch2_h = InjSys_idxModPfuSatMax_C;
      }

      /* Assignment: '<S16>/Assignment3' incorporates:
       *  Constant: '<S16>/ConstVal_3'
       */
      localAssignment3[localSwitch2_h - 1] = TRUE;

      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMin_C_3'
       *  RelationalOperator: '<S35>/UpperRelop'
       */
      if (pFuSp_B.VEMS_vidGET13 < InjSys_idxModPfuSatMin_C) {
        localSwitch2_h = InjSys_idxModPfuSatMin_C;
      } else {
        localSwitch2_h = pFuSp_B.VEMS_vidGET13;
      }

      /* Switch: '<S35>/Switch2' incorporates:
       *  Constant: '<S16>/InjSys_idxModPfuSatMax_C_3'
       *  RelationalOperator: '<S35>/LowerRelop1'
       */
      if (pFuSp_B.VEMS_vidGET13 > InjSys_idxModPfuSatMax_C) {
        localSwitch2_h = InjSys_idxModPfuSatMax_C;
      }

      /* Assignment: '<S16>/Assignment4' incorporates:
       *  Constant: '<S16>/ConstVal_4'
       */
      for (locali = 0; locali < 15; locali++) {
        InjSys_prm_bAcvPfuSpCal[(locali)] = localAssignment3[locali];
      }

      InjSys_prm_bAcvPfuSpCal[localSwitch2_h - 1] = TRUE;

      /* SignalConversion: '<S36>/Signal Conversion' */
      InjSys_bAcvPfuSpCal1 = InjSys_prm_bAcvPfuSpCal[0];

      /* SignalConversion: '<S36>/Signal Conversion1' */
      InjSys_bAcvPfuSpCal2 = InjSys_prm_bAcvPfuSpCal[1];

      /* SignalConversion: '<S36>/Signal Conversion10' */
      InjSys_bAcvPfuSpCal11 = InjSys_prm_bAcvPfuSpCal[10];

      /* SignalConversion: '<S36>/Signal Conversion11' */
      InjSys_bAcvPfuSpCal12 = InjSys_prm_bAcvPfuSpCal[11];

      /* SignalConversion: '<S36>/Signal Conversion12' */
      InjSys_bAcvPfuSpCal13 = InjSys_prm_bAcvPfuSpCal[12];

      /* SignalConversion: '<S36>/Signal Conversion13' */
      InjSys_bAcvPfuSpCal14 = InjSys_prm_bAcvPfuSpCal[13];

      /* SignalConversion: '<S36>/Signal Conversion14' */
      InjSys_bAcvPfuSpCal15 = InjSys_prm_bAcvPfuSpCal[14];

      /* SignalConversion: '<S36>/Signal Conversion2' */
      InjSys_bAcvPfuSpCal3 = InjSys_prm_bAcvPfuSpCal[2];

      /* SignalConversion: '<S36>/Signal Conversion3' */
      InjSys_bAcvPfuSpCal4 = InjSys_prm_bAcvPfuSpCal[3];

      /* SignalConversion: '<S36>/Signal Conversion4' */
      InjSys_bAcvPfuSpCal5 = InjSys_prm_bAcvPfuSpCal[4];

      /* SignalConversion: '<S36>/Signal Conversion5' */
      InjSys_bAcvPfuSpCal6 = InjSys_prm_bAcvPfuSpCal[5];

      /* SignalConversion: '<S36>/Signal Conversion6' */
      InjSys_bAcvPfuSpCal7 = InjSys_prm_bAcvPfuSpCal[6];

      /* SignalConversion: '<S36>/Signal Conversion7' */
      InjSys_bAcvPfuSpCal8 = InjSys_prm_bAcvPfuSpCal[7];

      /* SignalConversion: '<S36>/Signal Conversion8' */
      InjSys_bAcvPfuSpCal9 = InjSys_prm_bAcvPfuSpCal[8];

      /* SignalConversion: '<S36>/Signal Conversion9' */
      InjSys_bAcvPfuSpCal10 = InjSys_prm_bAcvPfuSpCal[9];

      /* Outputs for enable SubSystem: '<S17>/F02_Calibration_1_pFuSp' incorporates:
       *  EnablePort: '<S37>/Enable'
       */
      if (InjSys_bAcvPfuSpCal1) {
        /* Lookup2D: '<S53>/Look-Up Table (2-D)'
         * About '<S53>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal1), (&(InjSys_pFuSpCal1_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal1X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate2'
         *
         * Regarding '<S53>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F02_Calibration_1_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F03_Calibration_2_pFuSp' incorporates:
       *  EnablePort: '<S38>/Enable'
       */
      if (InjSys_bAcvPfuSpCal2) {
        /* Lookup2D: '<S54>/Look-Up Table (2-D)'
         * About '<S54>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal2), (&(InjSys_pFuSpCal2_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal2X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate2'
         *
         * Regarding '<S54>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F03_Calibration_2_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F04_Calibration_3_pFuSp' incorporates:
       *  EnablePort: '<S39>/Enable'
       */
      if (InjSys_bAcvPfuSpCal3) {
        /* Lookup2D: '<S55>/Look-Up Table (2-D)'
         * About '<S55>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal3), (&(InjSys_pFuSpCal3_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal3X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
         *
         * Regarding '<S55>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F04_Calibration_3_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F05_Calibration_4_pFuSp' incorporates:
       *  EnablePort: '<S40>/Enable'
       */
      if (InjSys_bAcvPfuSpCal4) {
        /* Lookup2D: '<S56>/Look-Up Table (2-D)'
         * About '<S56>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal4), (&(InjSys_pFuSpCal4_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal4X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate2'
         *
         * Regarding '<S56>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F05_Calibration_4_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F06_Calibration_5_pFuSp' incorporates:
       *  EnablePort: '<S41>/Enable'
       */
      if (InjSys_bAcvPfuSpCal5) {
        /* Lookup2D: '<S57>/Look-Up Table (2-D)'
         * About '<S57>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal5), (&(InjSys_pFuSpCal5_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal5X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate2'
         *
         * Regarding '<S57>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F06_Calibration_5_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F07_Calibration_6_pFuSp' incorporates:
       *  EnablePort: '<S42>/Enable'
       */
      if (InjSys_bAcvPfuSpCal6) {
        /* Lookup2D: '<S58>/Look-Up Table (2-D)'
         * About '<S58>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal6), (&(InjSys_pFuSpCal6_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal6X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate2'
         *
         * Regarding '<S58>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F07_Calibration_6_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F08_Calibration_7_pFuSp' incorporates:
       *  EnablePort: '<S43>/Enable'
       */
      if (InjSys_bAcvPfuSpCal7) {
        /* Lookup2D: '<S59>/Look-Up Table (2-D)'
         * About '<S59>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal7), (&(InjSys_pFuSpCal7_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal7X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate2'
         *
         * Regarding '<S59>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F08_Calibration_7_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F09_Calibration_8_pFuSp' incorporates:
       *  EnablePort: '<S44>/Enable'
       */
      if (InjSys_bAcvPfuSpCal8) {
        /* Lookup2D: '<S60>/Look-Up Table (2-D)'
         * About '<S60>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal8), (&(InjSys_pFuSpCal8_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal8X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate2'
         *
         * Regarding '<S60>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F09_Calibration_8_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F10_Calibration_9_pFuSp' incorporates:
       *  EnablePort: '<S45>/Enable'
       */
      if (InjSys_bAcvPfuSpCal9) {
        /* Lookup2D: '<S61>/Look-Up Table (2-D)'
         * About '<S61>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal9), (&(InjSys_pFuSpCal9_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal9X_A[0])),
                           15U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);

        /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate2'
         *
         * Regarding '<S61>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F10_Calibration_9_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F11_Calibration_10_pFuSp' incorporates:
       *  EnablePort: '<S46>/Enable'
       */
      if (InjSys_bAcvPfuSpCal10) {
        /* Lookup2D: '<S62>/Look-Up Table (2-D)'
         * About '<S62>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal10), (&(InjSys_pFuSpCal10_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal10X_A[0])),
                           7U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);

        /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate2'
         *
         * Regarding '<S62>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F11_Calibration_10_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F12_Calibration_11_pFuSp' incorporates:
       *  EnablePort: '<S47>/Enable'
       */
      if (InjSys_bAcvPfuSpCal11) {
        /* Lookup2D: '<S63>/Look-Up Table (2-D)'
         * About '<S63>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal11), (&(InjSys_pFuSpCal11_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal11X_A[0])),
                           7U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);

        /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate2'
         *
         * Regarding '<S63>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F12_Calibration_11_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F13_Calibration_12_pFuSp' incorporates:
       *  EnablePort: '<S48>/Enable'
       */
      if (InjSys_bAcvPfuSpCal12) {
        /* Lookup2D: '<S64>/Look-Up Table (2-D)'
         * About '<S64>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal12), (&(InjSys_pFuSpCal12_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal12X_A[0])),
                           7U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);

        /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate2'
         *
         * Regarding '<S64>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F13_Calibration_12_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F14_Calibration_13_pFuSp' incorporates:
       *  EnablePort: '<S49>/Enable'
       */
      if (InjSys_bAcvPfuSpCal13) {
        /* Lookup2D: '<S65>/Look-Up Table (2-D)'
         * About '<S65>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
         * Lookup Method: Linear_Endpoint
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        Look2D_U16_U16_U16( &(InjSys_pFuSpCal13), (&(InjSys_pFuSpCal13_M[0])),
                           pFuSp_B.VEMS_vidGET15, (&(InjSys_nEngInjSpCal13X_A[0])),
                           7U, pFuSp_B.VEMS_vidGET14,
                           (&(InjSys_mAirInjSpCal13Y_A[0])), 7U);

        /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate2'
         *
         * Regarding '<S65>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S17>/F14_Calibration_13_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F15_Calibration_14_pFuSp' incorporates:
       *  EnablePort: '<S50>/Enable'
       */
      if (InjSys_bAcvPfuSpCal14) {
        /* SignalConversion: '<S50>/Signal Conversion' incorporates:
         *  Constant: '<S50>/InjSys_pFuSpCal14_C'
         */
        InjSys_pFuSpCal14 = InjSys_pFuSpCal14_C;
      }

      /* end of Outputs for SubSystem: '<S17>/F15_Calibration_14_pFuSp' */

      /* Outputs for enable SubSystem: '<S17>/F16_Calibration_15_pFuSp' incorporates:
       *  EnablePort: '<S51>/Enable'
       */
      if (InjSys_bAcvPfuSpCal15) {
        /* SignalConversion: '<S51>/Signal Conversion' incorporates:
         *  Constant: '<S51>/InjSys_pFuSpCal15_C'
         */
        InjSys_pFuSpCal15 = InjSys_pFuSpCal15_C;
      }

      /* end of Outputs for SubSystem: '<S17>/F16_Calibration_15_pFuSp' */

      /* SignalConversion: '<S52>/Signal Conversion' */
      InjSys_prm_pFuSpCal[0] = InjSys_pFuSpCal1;
      InjSys_prm_pFuSpCal[1] = InjSys_pFuSpCal2;
      InjSys_prm_pFuSpCal[2] = InjSys_pFuSpCal3;
      InjSys_prm_pFuSpCal[3] = InjSys_pFuSpCal4;
      InjSys_prm_pFuSpCal[4] = InjSys_pFuSpCal5;
      InjSys_prm_pFuSpCal[5] = InjSys_pFuSpCal6;
      InjSys_prm_pFuSpCal[6] = InjSys_pFuSpCal7;
      InjSys_prm_pFuSpCal[7] = InjSys_pFuSpCal8;
      InjSys_prm_pFuSpCal[8] = InjSys_pFuSpCal9;
      InjSys_prm_pFuSpCal[9] = InjSys_pFuSpCal10;
      InjSys_prm_pFuSpCal[10] = InjSys_pFuSpCal11;
      InjSys_prm_pFuSpCal[11] = InjSys_pFuSpCal12;
      InjSys_prm_pFuSpCal[12] = InjSys_pFuSpCal13;
      InjSys_prm_pFuSpCal[13] = InjSys_pFuSpCal14;
      InjSys_prm_pFuSpCal[14] = InjSys_pFuSpCal15;

      /* DataTypeConversion: '<S18>/DTConv_UFix_To_Single_1' incorporates:
       *  Selector: '<S18>/Selector2'
       */
      InjSys_pFuSpBas1ModTar = ((Float32)
        InjSys_prm_pFuSpCal[pFuSp_B.VEMS_vidGET11 - 1]) * 781.25F;

      /* DataTypeConversion: '<S18>/DTConv_UFix_To_Single_2' incorporates:
       *  Selector: '<S18>/Selector1'
       */
      InjSys_pFuSpBas2ModCur = ((Float32)
        InjSys_prm_pFuSpCal[pFuSp_B.VEMS_vidGET12 - 1]) * 781.25F;

      /* DataTypeConversion: '<S18>/DTConv_UFix_To_Single_3' incorporates:
       *  Selector: '<S18>/Selector3'
       */
      InjSys_pFuSpBas2ModTar = ((Float32)
        InjSys_prm_pFuSpCal[pFuSp_B.VEMS_vidGET13 - 1]) * 781.25F;

      /* DataTypeConversion: '<S18>/DTConv_UFix_To_Single_4' incorporates:
       *  Selector: '<S18>/Selector'
       */
      InjSys_pFuSpBas1ModCur = ((Float32)
        InjSys_prm_pFuSpCal[pFuSp_B.VEMS_vidGET10 - 1]) * 781.25F;

      /* DataTypeConversion: '<S19>/Data Type Conversion2' */
      localSwitch2_f = ((Float32)pFuSp_B.VEMS_vidGET9) * 0.0078125F;

      /* Switch: '<S73>/Switch2' incorporates:
       *  Constant: '<S66>/Constant'
       *  RelationalOperator: '<S73>/LowerRelop1'
       */
      if (localSwitch2_f > 1.0F) {
        localSwitch2_f = 1.0F;
      }

      /* DataTypeConversion: '<S19>/Data Type Conversion' */
      localAdd2_k = ((Float32)pFuSp_B.VEMS_vidGET7) * 0.0078125F;

      /* Switch: '<S81>/Switch2' incorporates:
       *  Constant: '<S68>/Constant'
       *  RelationalOperator: '<S81>/LowerRelop1'
       */
      if (localAdd2_k > 1.0F) {
        localAdd2_k = 1.0F;
      }

      /* Sum: '<S68>/Sum2' incorporates:
       *  Product: '<S68>/Divide'
       *  Sum: '<S68>/Sum3'
       */
      InjSys_pFuSpModCur_MP = ((InjSys_pFuSpBas1ModCur - InjSys_pFuSpBas2ModCur)
        * localAdd2_k) + InjSys_pFuSpBas2ModCur;

      /* DataTypeConversion: '<S19>/Data Type Conversion1' */
      localAdd2_k = ((Float32)pFuSp_B.VEMS_vidGET8) * 0.0078125F;

      /* Switch: '<S77>/Switch2' incorporates:
       *  Constant: '<S67>/Constant'
       *  RelationalOperator: '<S77>/LowerRelop1'
       */
      if (localAdd2_k > 1.0F) {
        localAdd2_k = 1.0F;
      }

      /* Sum: '<S67>/Sum2' incorporates:
       *  Product: '<S67>/Divide'
       *  Sum: '<S67>/Sum3'
       */
      InjSys_pFuSpModTar_MP = ((InjSys_pFuSpBas1ModTar - InjSys_pFuSpBas2ModTar)
        * localAdd2_k) + InjSys_pFuSpBas2ModTar;

      /* DataTypeConversion: '<S69>/OutDTConv' incorporates:
       *  Constant: '<S69>/offset'
       *  Constant: '<S69>/offset1'
       *  Constant: '<S69>/one_on_slope'
       *  Product: '<S66>/Divide'
       *  Product: '<S69>/Product4'
       *  Sum: '<S66>/Sum2'
       *  Sum: '<S66>/Sum3'
       *  Sum: '<S69>/Add1'
       *  Sum: '<S69>/Add2'
       */
      localSwitch2_f = ((((InjSys_pFuSpModTar_MP - InjSys_pFuSpModCur_MP) *
                          localSwitch2_f) + InjSys_pFuSpModCur_MP) *
                        1.279999968E-003F) + 0.5F;
      if (localSwitch2_f < 65536.0F) {
        if (localSwitch2_f >= 0.0F) {
          pFuSp_B.Merge = (UInt16)localSwitch2_f;
        } else {
          pFuSp_B.Merge = 0U;
        }
      } else {
        pFuSp_B.Merge = MAX_uint16_T;
      }
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET16 */
    VEMS_vidGET(InjSys_pFuReq, pFuSp_B.VEMS_vidGET16);

    /* DataTypeConversion: '<S9>/DTConv_UFix_To_Single_1' */
    localDTConv_UFix_To_Single_1 = ((Float32)pFuSp_B.VEMS_vidGET16) * 781.25F;

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET(Ext_tiTDC, pFuSp_B.VEMS_vidGET5);

    /* Product: '<S90>/Divide' incorporates:
     *  Constant: '<S82>/InjSys_idxTiPerSplEve_C'
     */
    InjSys_tiTDCPmp = (Float32)((((Float32d)pFuSp_B.VEMS_vidGET5) * 0.001) *
      ((Float32d)InjSys_idxTiPerSplEve_C));

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(Ext_pFuRailSplMes, pFuSp_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET(Ext_tCoMes, pFuSp_B.VEMS_vidGET4);

    /* Outputs for atomic SubSystem: '<S9>/F02_Monitor_pressure' */

    /* DataTypeConversion: '<S83>/Data Type Conversion3' */
    locali = pFuSp_B.VEMS_vidGET4 + 40;
    if (locali <= 0) {
      localSwitch2_h = 0U;
    } else if (locali > 255) {
      localSwitch2_h = MAX_uint8_T;
    } else {
      localSwitch2_h = (UInt8)locali;
    }

    /* Sum: '<S83>/Subtract1' incorporates:
     *  Constant: '<S83>/InjSys_pPresDifLowHys_C'
     *  DataTypeConversion: '<S83>/Data Type Conversion1'
     */

    /* Lookup_n-D: '<S92>/Lookup Table (n-D)' */
    localLookupTablenD = look1_iu16lfIf_binlcs(pFuSp_B.VEMS_vidGET16,
      (&(InjSys_pPresDifMaxInj_A[0])), (&(InjSys_pPresDifMaxInj_T[0])), 9U);
    localSwitch2_f = localLookupTablenD - (((Float32)InjSys_pPresDifLowHys_C) *
      781.25F);

    /* MinMax: '<S83>/MinMax' incorporates:
     *  Constant: '<S83>/ConstVal'
     */
    localAdd2_k = rt_MAXf(localSwitch2_f, 0.0F);

    /* Sum: '<S83>/Subtract' incorporates:
     *  DataTypeConversion: '<S83>/Data Type Conversion4'
     */
    localSwitch2_f = (((Float32)pFuSp_B.VEMS_vidGET3) * 781.25F) -
      localDTConv_UFix_To_Single_1;

    /* If: '<S91>/If' incorporates:
     *  ActionPort: '<S95>/Action Port'
     *  ActionPort: '<S96>/Action Port'
     *  Lookup_n-D: '<S93>/Lookup Table (n-D)'
     *  Product: '<S94>/Divide'
     *  RelationalOperator: '<S91>/Relational Operator'
     *  RelationalOperator: '<S91>/Relational Operator1'
     *  SubSystem: '<S91>/If Action Subsystem'
     *  SubSystem: '<S91>/If Action Subsystem1'
     */
    if (localAdd2_k >= localSwitch2_f) {
      /* Inport: '<S95>/Value 1' incorporates:
       *  Constant: '<S83>/ConstVal1'
       */
      pFuSp_B.Merge_p = FALSE;
    } else {
      if (localSwitch2_f >= (localLookupTablenD * look1_iu8lftu16n13If_binlcns__1
                             (localSwitch2_h, (&(InjSys_tCo_facPresDifMaxInj_A[0])),
            (&(InjSys_facPresDifMaxInj_T[0])), 7U))) {
        /* Inport: '<S96>/Value 2' incorporates:
         *  Constant: '<S83>/ConstVal2'
         */
        pFuSp_B.Merge_p = TRUE;
      }
    }

    /* end of Outputs for SubSystem: '<S9>/F02_Monitor_pressure' */
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET17 */
    VEMS_vidGET(MonMisf_bDetInstMisf, pFuSp_B.VEMS_vidGET17);

    /* Logic: '<S84>/Logical Operator' */
    localLogicalOperator = !pFuSp_B.VEMS_vidGET17;

    /* Logic: '<S98>/Logical Operator3' */
    localLogicalOperator3 = !localLogicalOperator;

    /* Sum: '<S98>/Sum2' incorporates:
     *  Constant: '<S84>/InjSys_tiDlyAcvSpcInjMod_C'
     *  Constant: '<S98>/Constant1'
     *  Constant: '<S98>/Constant6'
     *  MinMax: '<S98>/MinMax1'
     *  Product: '<S103>/Divide'
     */
    localSwitch2_f = (((Float32)InjSys_tiDlyAcvSpcInjMod_C) * 0.5F) + (10.0F *
      InjSys_tiTDCPmp);

    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S98>/Constant3'
     *  RelationalOperator: '<S108>/UpperRelop'
     *  UnitDelay: '<S101>/Unit Delay'
     */
    if (pFuSp_DWork.UnitDelay_DSTATE < 0.0F) {
      localAdd2_k = 0.0F;
    } else {
      localAdd2_k = pFuSp_DWork.UnitDelay_DSTATE;
    }

    /* Switch: '<S108>/Switch2' incorporates:
     *  RelationalOperator: '<S108>/LowerRelop1'
     *  UnitDelay: '<S101>/Unit Delay'
     */
    if (!(pFuSp_DWork.UnitDelay_DSTATE > localSwitch2_f)) {
      localSwitch2_f = localAdd2_k;
    }

    /* Switch: '<S98>/Switch1' incorporates:
     *  Constant: '<S98>/Constant4'
     *  Constant: '<S98>/Constant7'
     *  Logic: '<S104>/Logical Operator'
     *  Logic: '<S104>/Logical Operator1'
     *  Logic: '<S98>/Logical Operator2'
     *  Sum: '<S98>/Sum1'
     *  UnitDelay: '<S102>/Unit Delay'
     *  UnitDelay: '<S109>/Unit Delay'
     */
    if (pFuSp_DWork.UnitDelay_DSTATE_g || ((localLogicalOperator) &&
         (!pFuSp_DWork.UnitDelay_DSTATE_j))) {
      localSwitch_m = 0.0F;
    } else {
      localSwitch_m = (InjSys_tiTDCPmp + localSwitch2_f) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S98>/Relational Operator2' incorporates:
     *  MinMax: '<S98>/MinMax1'
     */
    localRelationalOperator2 = (localSwitch_m >= (((Float32)
      InjSys_tiDlyAcvSpcInjMod_C) * 0.5F));

    /* RelationalOperator: '<S98>/Relational Operator1' incorporates:
     *  Constant: '<S98>/Constant2'
     *  MinMax: '<S98>/MinMax1'
     */
    localRelationalOperator1 = (InjSys_tiDlyAcvSpcInjMod_C == 0);

    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S98>/Constant5'
     *  Logic: '<S105>/Logical Operator'
     *  Logic: '<S105>/Logical Operator1'
     *  Logic: '<S98>/Logical Operator1'
     *  UnitDelay: '<S110>/Unit Delay'
     */
    if (!localRelationalOperator1) {
      localSwitch_j = ((localRelationalOperator2) &&
                       (!pFuSp_DWork.UnitDelay_DSTATE_ae));
    } else {
      localSwitch_j = TRUE;
    }

    /* Memory: '<S100>/Memory' */
    localUnitDelay_g = pFuSp_DWork.Memory_PreviousInput;

    /* CombinatorialLogic: '<S100>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localLogicalOperator3 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localSwitch_j != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_g != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = pFuSp_ConstP.pooled11[rowidx];
      localLogic[1] = pFuSp_ConstP.pooled11[rowidx + 8];
    }

    /* UnitDelay: '<S97>/UnitDelay' */
    localUnitDelay_g = pFuSp_DWork.UnitDelay;

    /* CombinatorialLogic: '<S97>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(pFuSp_B.VEMS_vidGET17 != 0);
      rowidx = (rowidx << 1) + (UInt32)(localLogic[1] != 0);
      rowidx = (rowidx << 1) + (UInt32)(localUnitDelay_g != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_l[0] = pFuSp_ConstP.Logic_table[rowidx];
      localLogic_l[1] = pFuSp_ConstP.Logic_table[rowidx + 8];
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S97>/NotCLR3'
     *  UnitDelay: '<S97>/UnitDelay1'
     */
    if (pFuSp_DWork.UnitDelay_h) {
      localSwitch2_k = localLogic_l[0];
    } else {
      localSwitch2_k = FALSE;
    }

    /* Switch: '<S84>/Switch' incorporates:
     *  Constant: '<S84>/ConstVal'
     *  Constant: '<S84>/InjSys_bAcvMonMisfSpcInjMod_C'
     */
    if (InjSys_bAcvMonMisfSpcInjMod_C) {
      InjSys_bInhSpcInjMod = localSwitch2_k;
    } else {
      InjSys_bInhSpcInjMod = FALSE;
    }

    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S85>/ConstVal'
     *  Constant: '<S85>/InjSys_bAuthAirLdMinSat_C'
     *  Constant: '<S85>/InjSys_nMaxGrdLdSat_C'
     *  DataTypeConversion: '<S85>/DTConv_UFix_To_Single_1'
     *  RelationalOperator: '<S85>/Relational Operator'
     *  Sum: '<S85>/Sum'
     *  UnitDelay: '<S111>/Unit Delay'
     */
    if (InjSys_bAuthAirLdMinSat_C) {
      InjSys_bInhAirLdMinSat = ((pFuSp_B.VEMS_vidGET -
        pFuSp_DWork.UnitDelay_DSTATE_a) > InjSys_nMaxGrdLdSat_C);
    } else {
      InjSys_bInhAirLdMinSat = TRUE;
    }

    /* Outputs for atomic SubSystem: '<S9>/F05_Choose_Strategy' */

    /* Logic: '<S86>/Logical Operator3' incorporates:
     *  Logic: '<S86>/Logical Operator2'
     */
    InjSys_bAcvSpcInjModTmp = ((!InjSys_bInhSpcInjMod) && pFuSp_B.Merge_p);

    /* Logic: '<S86>/Logical Operator4' incorporates:
     *  Logic: '<S86>/Logical Operator1'
     */
    InjSys_bAcvAirLdMinSatTmp = (pFuSp_B.Merge_p && (!InjSys_bInhAirLdMinSat));

    /* SignalConversion: '<S86>/TmpSignal ConversionAtSignal ConversionInport1' */
    InjSys_bInhInjCutOffTmp = pFuSp_B.Merge_p;

    /* end of Outputs for SubSystem: '<S9>/F05_Choose_Strategy' */

    /* Outputs for atomic SubSystem: '<S9>/F06_Activate_functionality' */

    /* Switch: '<S87>/Switch3' incorporates:
     *  Constant: '<S87>/InjSys_bAcvAirLdMinSat_C'
     *  Constant: '<S87>/InjSys_stManAirLdMinSat_C'
     */
    if (InjSys_stManAirLdMinSat_C != 0) {
      localLowerRelop1_d = InjSys_bAcvAirLdMinSat_C;
    } else {
      localLowerRelop1_d = InjSys_bAcvAirLdMinSatTmp;
    }

    /* Switch: '<S87>/Switch1' incorporates:
     *  Constant: '<S87>/ConstVal_1'
     *  Inport: '<Root>/FRM_bInhPfuInjSp'
     */
    if (GDGAR_bGetFRM(FRM_FRM_INHPFUINJSP)) {
      localLowerRelop1_d = FALSE;
    }

    /* Switch: '<S87>/Switch4' incorporates:
     *  Constant: '<S87>/InjSys_bAcvAirLdMinSat_C1'
     *  Constant: '<S87>/InjSys_stManAirLdMinSat_C1'
     */
    if (InjSys_stManInhInjCutOff_C != 0) {
      localRelationalOperator_f = InjSys_bInhInjCutOff_C;
    } else {
      localRelationalOperator_f = InjSys_bInhInjCutOffTmp;
    }

    /* Switch: '<S87>/Switch5' incorporates:
     *  Constant: '<S87>/ConstVal_2'
     *  Inport: '<Root>/FRM_bInhPfuInjSp'
     */
    if (GDGAR_bGetFRM(FRM_FRM_INHPFUINJSP)) {
      pFuSp_B.Switch5 = FALSE;
    } else {
      pFuSp_B.Switch5 = localRelationalOperator_f;
    }

    /* Logic: '<S87>/Logical Operator1' incorporates:
     *  Constant: '<S87>/InjSys_bAcvAirLdMinSat_C2'
     *  Logic: '<S87>/Logical Operator4'
     */
    pFuSp_B.LogicalOperator1_f = ((localLowerRelop1_d) || (pFuSp_B.Switch5 &&
      InjSys_bAcvAirLdMinSatDcha_C));

    /* Switch: '<S87>/Switch2' incorporates:
     *  Constant: '<S87>/InjSys_bAcvSpcInjMod_C'
     *  Constant: '<S87>/InjSys_stManSpcInjMod_C'
     */
    if (InjSys_stManSpcInjMod_C != 0) {
      localRelationalOperator_f = InjSys_bAcvSpcInjMod_C;
    } else {
      localRelationalOperator_f = InjSys_bAcvSpcInjModTmp;
    }

    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S87>/ConstVal'
     *  Inport: '<Root>/FRM_bInhPfuInjSp'
     */
    if (GDGAR_bGetFRM(FRM_FRM_INHPFUINJSP)) {
      pFuSp_B.Switch = FALSE;
    } else {
      pFuSp_B.Switch = localRelationalOperator_f;
    }

    /* end of Outputs for SubSystem: '<S9>/F06_Activate_functionality' */
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_bTotCutOff, pFuSp_B.VEMS_vidGET6);

    /* Outputs for atomic SubSystem: '<S9>/F07_Tq_Cll_Request' */

    /* Logic: '<S88>/Logical Operator1' incorporates:
     *  Logic: '<S88>/Logical Operator'
     *  Logic: '<S88>/Logical Operator2'
     */
    pFuSp_B.LogicalOperator1 = ((pFuSp_B.Switch5 || pFuSp_B.LogicalOperator1_f) &&
                                (!pFuSp_B.VEMS_vidGET6));

    /* end of Outputs for SubSystem: '<S9>/F07_Tq_Cll_Request' */
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET18 */
    VEMS_vidGET(TqLimEM_tqLimEM, pFuSp_B.VEMS_vidGET18);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_pFuMesFineResl, pFuSp_B.VEMS_vidGET2);

    /* Outputs for atomic SubSystem: '<S9>/F08_Cut_off_HP_Pump' */

    /* DataTypeConversion: '<S89>/Data Type Conversion1' */
    localLookupTablenD = ((Float32)pFuSp_B.VEMS_vidGET2) * 10000.0F;

    /* DataTypeConversion: '<S89>/Data Type Conversion3' */
    localLookupTablenD_m = ((Float32)pFuSp_B.VEMS_vidGET18) * 0.0625F;

    /* DataTypeConversion: '<S89>/Data Type Conversion6' incorporates:
     *  Constant: '<S89>/InjSys_tiPmpCutOffTqLimEM_C1'
     */
    localDataTypeConversion6 = ((Float32)InjSys_pFuDifMaxRailDcha_C) * 781.25F;

    /* DataTypeConversion: '<S89>/Data Type Conversion7' incorporates:
     *  Constant: '<S89>/InjSys_tiPmpCutOffTqLimEM_C'
     */
    localAdd2_k = ((Float32)InjSys_tiPmpCutOffTqLimEM_C) * 1.000000015E-001F;

    /* UnitDelay: '<S115>/Unit Delay' */
    TqLimEM_tqLimEMPrec = pFuSp_DWork.UnitDelay_DSTATE_e;

    /* Product: '<S112>/Divide' incorporates:
     *  Sum: '<S89>/Sum'
     */
    localSwitch2_f = (localLookupTablenD_m - TqLimEM_tqLimEMPrec) /
      InjSys_tiTDCPmp;

    /* Outputs for atomic SubSystem: '<S112>/If Action Subsystem3' */

    /* Switch: '<S117>/Switch1' incorporates:
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S117>/Constant2'
     *  Constant: '<S117>/Constant3'
     *  Logic: '<S117>/Logical Operator1'
     *  RelationalOperator: '<S117>/Relational Operator'
     *  RelationalOperator: '<S117>/Relational Operator1'
     *  RelationalOperator: '<S117>/Relational Operator3'
     */
    if (((localSwitch2_f != localSwitch2_f) || (localSwitch2_f >
          3.000000005E+038F)) || (-3.000000005E+038F > localSwitch2_f)) {
      localSwitch2_f = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S112>/If Action Subsystem3' */

    /* RelationalOperator: '<S89>/Relational Operator' incorporates:
     *  Constant: '<S89>/InjSys_tqMaxPosGrdDcha_C'
     *  DataTypeConversion: '<S89>/Data Type Conversion8'
     */
    localLowerRelop1_d = (localSwitch2_f < (((Float32)InjSys_tqMaxPosGrdDcha_C)
      * 0.0625F));

    /* Product: '<S113>/Divide' incorporates:
     *  Sum: '<S89>/Sum1'
     */
    localSwitch2_f = (TqLimEM_tqLimEMPrec - localLookupTablenD_m) /
      InjSys_tiTDCPmp;

    /* Outputs for atomic SubSystem: '<S113>/If Action Subsystem3' */

    /* Switch: '<S119>/Switch1' incorporates:
     *  Constant: '<S119>/Constant1'
     *  Constant: '<S119>/Constant2'
     *  Constant: '<S119>/Constant3'
     *  Logic: '<S119>/Logical Operator1'
     *  RelationalOperator: '<S119>/Relational Operator'
     *  RelationalOperator: '<S119>/Relational Operator1'
     *  RelationalOperator: '<S119>/Relational Operator3'
     */
    if (((localSwitch2_f != localSwitch2_f) || (localSwitch2_f >
          3.000000005E+038F)) || (-3.000000005E+038F > localSwitch2_f)) {
      localSwitch2_f = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S113>/If Action Subsystem3' */

    /* RelationalOperator: '<S89>/Relational Operator1' incorporates:
     *  Constant: '<S89>/InjSys_tqMaxNegGrdDcha_C'
     *  DataTypeConversion: '<S89>/Data Type Conversion4'
     */
    localRelationalOperator1_fa = (localSwitch2_f > (((Float32)
      InjSys_tqMaxNegGrdDcha_C) * 0.0625F));

    /* UnitDelay: '<S114>/Unit Delay' */
    localMemory = pFuSp_DWork.UnitDelay_DSTATE_b;

    /* UnitDelay: '<S123>/UnitDelay' */
    localSwitch_l = pFuSp_DWork.UnitDelay_j;

    /* MinMax: '<S114>/MinMax1' incorporates:
     *  Constant: '<S114>/Constant1'
     */
    localDivide_a = localAdd2_k;

    /* Sum: '<S114>/Sum2' incorporates:
     *  Constant: '<S114>/Constant6'
     *  Product: '<S114>/Product'
     */
    localSwitch2_f = (10.0F * InjSys_tiTDCPmp) + localAdd2_k;

    /* UnitDelay: '<S122>/Unit Delay' */
    localAdd2_k = pFuSp_DWork.UnitDelay_DSTATE_h;

    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S114>/Constant3'
     *  RelationalOperator: '<S127>/UpperRelop'
     */
    if (pFuSp_DWork.UnitDelay_DSTATE_h < 0.0F) {
      localAdd2_k = 0.0F;
    }

    /* Switch: '<S127>/Switch2' incorporates:
     *  RelationalOperator: '<S127>/LowerRelop1'
     */
    if (!(pFuSp_DWork.UnitDelay_DSTATE_h > localSwitch2_f)) {
      localSwitch2_f = localAdd2_k;
    }

    /* Switch: '<S114>/Switch1' incorporates:
     *  Constant: '<S114>/Constant4'
     *  Constant: '<S114>/Constant7'
     *  Logic: '<S114>/Logical Operator2'
     *  Logic: '<S123>/Logical Operator'
     *  Logic: '<S123>/Logical Operator1'
     *  Sum: '<S114>/Sum1'
     */
    if ((localMemory) || ((!localRelationalOperator1_fa) && (localSwitch_l))) {
      localSwitch2_f = 0.0F;
    } else {
      localSwitch2_f = (InjSys_tiTDCPmp + localSwitch2_f) + 2.220446049E-016F;
    }

    /* RelationalOperator: '<S114>/Relational Operator2' */
    localRelationalOperator_f = (localSwitch2_f >= localDivide_a);

    /* UnitDelay: '<S124>/UnitDelay' */
    localSwitch_l = pFuSp_DWork.UnitDelay_k;

    /* RelationalOperator: '<S114>/Relational Operator1' incorporates:
     *  Constant: '<S114>/Constant2'
     */
    localRelationalOperator1_i = (localDivide_a == 0.0F);

    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S114>/Constant5'
     *  Logic: '<S114>/Logical Operator1'
     *  Logic: '<S124>/Logical Operator'
     *  Logic: '<S124>/Logical Operator1'
     */
    if (!localRelationalOperator1_i) {
      localSwitch_l = ((localRelationalOperator_f) && (!localSwitch_l));
    } else {
      localSwitch_l = TRUE;
    }

    /* Memory: '<S121>/Memory' */
    localMemory = pFuSp_DWork.Memory_PreviousInput_e;

    /* CombinatorialLogic: '<S121>/Logic' */
    {
      UInt32 rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (UInt32)(localRelationalOperator1_fa != 0);
      rowidx = (rowidx << 1) + (UInt32)(localSwitch_l != 0);
      rowidx = (rowidx << 1) + (UInt32)(localMemory != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic_n[0] = pFuSp_ConstP.pooled11[rowidx];
      localLogic_n[1] = pFuSp_ConstP.pooled11[rowidx + 8];
    }

    /* Logic: '<S89>/Logical Operator3' */
    pFuSp_B.LogicalOperator3 = (pFuSp_B.LogicalOperator1_f || pFuSp_B.Switch);

    /* Logic: '<S89>/Logical Operator6' incorporates:
     *  Constant: '<S89>/InjSys_bAcvPmpCutTqLimEM_C'
     *  Constant: '<S89>/InjSys_bAcvPmpCutTqLimEM_C1'
     *  Constant: '<S89>/InjSys_tiPmpCutOffTqLimEM_C2'
     *  Logic: '<S89>/Logical Operator1'
     *  Logic: '<S89>/Logical Operator2'
     *  Logic: '<S89>/Logical Operator4'
     *  Logic: '<S89>/Logical Operator5'
     *  RelationalOperator: '<S89>/Relational Operator2'
     *  RelationalOperator: '<S89>/Relational Operator3'
     *  Sum: '<S89>/Sum2'
     */
    pFuSp_B.LogicalOperator6 = ((((((pFuSp_B.VEMS_vidGET2 >
      InjSys_pFuMinRailDcha_C) && (((localLowerRelop1_d) && (localLogic_n[0])) &&
      InjSys_bAcvPmpCutTqLimEM_C)) || pFuSp_B.VEMS_vidGET6) ||
      pFuSp_B.LogicalOperator1_f) || pFuSp_B.Switch) && (((localLookupTablenD -
      localDTConv_UFix_To_Single_1) > localDataTypeConversion6) ||
      InjSys_bInhDifFuRailDCha_C));

    /* Update for UnitDelay: '<S115>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_e = localLookupTablenD_m;

    /* Update for UnitDelay: '<S114>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_b = localRelationalOperator1_i;

    /* Update for UnitDelay: '<S123>/UnitDelay' */
    pFuSp_DWork.UnitDelay_j = localRelationalOperator1_fa;

    /* Update for UnitDelay: '<S122>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_h = localSwitch2_f;

    /* Update for UnitDelay: '<S124>/UnitDelay' */
    pFuSp_DWork.UnitDelay_k = localRelationalOperator_f;

    /* Update for Memory: '<S121>/Memory' */
    pFuSp_DWork.Memory_PreviousInput_e = localLogic_n[0];

    /* end of Outputs for SubSystem: '<S9>/F08_Cut_off_HP_Pump' */
    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvAirLdMinSat, pFuSp_B.LogicalOperator1_f);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_bAcvCllRailDcha, pFuSp_B.LogicalOperator1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_bAcvSpcInjMod, pFuSp_B.Switch);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_bCanPurgCutOff, pFuSp_B.LogicalOperator3);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET4 */
    VEMS_vidSET(InjSys_bHPPmpCutOff, pFuSp_B.LogicalOperator6);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET5 */
    VEMS_vidSET(InjSys_bInhInjCutOffPFuDcha, pFuSp_B.Switch5);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET6 */
    VEMS_vidSET(InjSys_bInjSpNotAccu, pFuSp_B.Merge_p);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET7 */
    VEMS_vidSET(InjSys_pFuSp, pFuSp_B.Merge);

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_g = localRelationalOperator1;

    /* Update for UnitDelay: '<S109>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_j = localLogicalOperator;

    /* Update for UnitDelay: '<S101>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE = localSwitch_m;

    /* Update for UnitDelay: '<S110>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_ae = localRelationalOperator2;

    /* Update for Memory: '<S100>/Memory' */
    pFuSp_DWork.Memory_PreviousInput = localLogic[0];

    /* Update for UnitDelay: '<S97>/UnitDelay' */
    pFuSp_DWork.UnitDelay = localSwitch2_k;

    /* Update for UnitDelay: '<S97>/UnitDelay1' incorporates:
     *  Constant: '<S97>/NotCLR2'
     */
    pFuSp_DWork.UnitDelay_h = TRUE;

    /* Update for UnitDelay: '<S111>/Unit Delay' */
    pFuSp_DWork.UnitDelay_DSTATE_a = pFuSp_B.VEMS_vidGET;
  }

  /* end of Outputs for SubSystem: '<S5>/F02_pFuSp' */
}

/* Start for exported function: InjSys_EveSpl_pFuSp */
void InjSys_EveSpl_pFuSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S3>/F02_pFuSp'
   */
  pFuSp_F02_pFuSp_Start();
}

/* Output and update for exported function: InjSys_EveSpl_pFuSp */
void InjSys_EveSpl_pFuSp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S3>/F02_pFuSp'
   */
  pFuSp_F02_pFuSp();
}

/* Model initialize function */
void pFuSp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  InjSys_EveSpl_pFuSp_Start();
}

#define PFUSP_STOP_SEC_CODE
#include "pFuSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
