/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agPmpRefPFuM                                            */
/* !Description     : CALCULATION OF THE ANGULAR REFERENCES FOR THE PUMP STRIKES (GDI)*/
/*                                                                            */
/* !Module          : agPmpRefPFuM                                            */
/*                                                                            */
/* !File            : agPmpRefPFuM.c                                          */
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
/* !Reference       : V01NT1008000 / 01                                       */
/* !OtherRefs       : VEMS V02 ECU#059284                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Sep 12 10:58:54 2013                              */
/*   Model name       : agPmpRefPFuM_AUTOCODE.mdl                             */
/*   Model version    : 1.77                                                  */
/*   Root subsystem   : /agPmpRefPFuM                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/EBDT/agPmpRefPFuM/5-SOFT-LIV/agPm$*/
/* $Revision::   1.2                                                         $*/
/* $Author::   adelvare                               $$Date::   12 Sep 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "agPmpRefPFuM.h"
#include "agPmpRefPFuM_private.h"

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
#define AGPMPREFPFUM_START_SEC_VAR_UNSPECIFIED
#include "agPmpRefPFuM_MemMap.h"

/* Block signals (auto storage) */
BlockIO_agPmpRefPFuM agPmpRefPFuM_B;

#define AGPMPREFPFUM_STOP_SEC_VAR_UNSPECIFIED
#include "agPmpRefPFuM_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AGPMPREFPFUM_START_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

void agPmpRefPFuM_ASYNC1(int controlPortIdx)
{
}

void agPmpRefPFuM_ASYNC3(int controlPortIdx)
{
  agPmpRef_F01_agPmpStkRef_EveInj();
}

/* Output and update for function-call system: '<S4>/F01_agPmpStkRef_EveInj' */
void agPmpRef_F01_agPmpStkRef_EveInj(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  UInt8 localMathFunction4;
  Boolean localLogicalOperator3;
  SInt32 localDTConv_UFix_To_Single_4;
  SInt32 localAdd10;
  SInt32 locallocalSwitch1_idx;
  SInt32 locallocalAdd;
  SInt32 locallocalAdd_0;
  UInt8 locallocalAdd_1;
  SInt16 localtmp;

  /* Outputs for enable SubSystem: '<S5>/F01_agPmpStkRef_EveInj' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/MONENGSTRT_u8Inhib1'
   *  EnablePort: '<S7>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (AGPMPREFPFUM_u8Inhib != 90) {
    /* Sum: '<S7>/Add1' incorporates:
     *  Constant: '<S7>/FuSysM_ctTDCRefPmpCmd_C'
     *  Constant: '<S7>/FuSysM_noTDCBtwPmpStk_C'
     */
    localAdd10 = FuSysM_ctTDCRefPmpCmd_C + FuSysM_noTDCBtwPmpStk_C;
    if (((UInt32)localAdd10) > 255U) {
      locallocalAdd_1 = MAX_uint8_T;
    } else {
      locallocalAdd_1 = (UInt8)localAdd10;
    }

    /* S-Function "vems_vidGET" Block: <S7>/S-Function1 */
    VEMS_vidGET(PFuCtl_agWdPmpCmdReq, agPmpRefPFuM_B.SFunction1_a);

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_4' */
    localDTConv_UFix_To_Single_4 = agPmpRefPFuM_B.SFunction1_a;

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_5' incorporates:
     *  Constant: '<S7>/FuSysM_agPerPmpRef_C'
     */
    localAdd10 = FuSysM_agPerPmpRef_C;

    /* S-Function "vems_vidGET" Block: <S7>/S-Function3 */
    VEMS_vidGET(PFuCtl_agPmpCmdEfcReq, agPmpRefPFuM_B.SFunction3_g);

    /* S-Function "vems_vidGET" Block: <S7>/S-Function4 */
    VEMS_vidGET(Ext_nEng, agPmpRefPFuM_B.SFunction4);

    /* DataTypeConversion Block: '<S8>/Data Type Conversion'
     *
     * Regarding '<S8>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* Lookup: '<S8>/Look-Up Table'
     * About '<S8>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(FuSysM_agDlyPmpStk_T[0])),
                   agPmpRefPFuM_B.SFunction4, (&(FuSysM_nEng_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S8>/Data Type Duplicate1'
     *
     * Regarding '<S8>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Sum: '<S7>/Add4' incorporates:
     *  Constant: '<S7>/FuSysM_agConvSplRefEveInj_C'
     *  Sum: '<S7>/Add14'
     */
    locallocalSwitch1_idx = (SInt32)((UInt32)(agPmpRefPFuM_B.SFunction3_g +
      localLookUpTable));
    locallocalAdd_0 = FuSysM_agConvSplRefEveInj_C;
    locallocalAdd = locallocalSwitch1_idx + locallocalAdd_0;
    if (((locallocalSwitch1_idx > 0) && (locallocalAdd_0 > 0)) && (locallocalAdd
         <= 0)) {
      locallocalAdd = MAX_int32_T;
    }

    /* Sum: '<S7>/Add7' */
    locallocalAdd_0 = locallocalAdd - localAdd10;
    if ((locallocalAdd < 0) && (locallocalAdd_0 >= 0)) {
      locallocalAdd_0 = MIN_int32_T;
    }

    /* Sum: '<S7>/Add2' incorporates:
     *  Constant: '<S7>/FuSysM_agBtwTDCRef_C'
     *  DataTypeConversion: '<S7>/DTConv_UFix_To_Single_6'
     */
    localAdd10 = locallocalAdd - FuSysM_agBtwTDCRef_C;
    if ((locallocalAdd < 0) && (localAdd10 >= 0)) {
      localAdd10 = MIN_int32_T;
    }

    /* S-Function "vems_vidGET" Block: <S7>/S-Function2 */
    VEMS_vidGET(Ext_ctTDC, agPmpRefPFuM_B.SFunction2_b);

    /* Math: '<S7>/Math Function4' incorporates:
     *  Constant: '<S7>/Ext_noCylEng_SC'
     */
    localMathFunction4 = rt_mod_uint8(agPmpRefPFuM_B.SFunction2_b,
      Ext_noCylEng_SC);

    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/FuSysM_bCfPmpOneTDCStk_C'
     *  Constant: '<S7>/FuSysM_ctTDCRefPmpCmd_C'
     *  Logic: '<S7>/Logical Operator1'
     *  RelationalOperator: '<S7>/Relational Operator1'
     *  RelationalOperator: '<S7>/Relational Operator2'
     */
    FuSysM_bAcvPmpCmdTDCCur = (((localMathFunction4 == FuSysM_ctTDCRefPmpCmd_C) ||
                                (locallocalAdd_1 == localMathFunction4)) ||
      FuSysM_bCfPmpOneTDCStk_C);

    /* Switch: '<S7>/Switch1' incorporates:
     *  Sum: '<S7>/Add12'
     *  Sum: '<S7>/Add3'
     */
    if (FuSysM_bAcvPmpCmdTDCCur) {
      localAdd10 = locallocalAdd;
      locallocalSwitch1_idx = locallocalAdd + localDTConv_UFix_To_Single_4;
      if (((locallocalAdd > 0) && (localDTConv_UFix_To_Single_4 > 0)) &&
          (locallocalSwitch1_idx <= 0)) {
        locallocalSwitch1_idx = MAX_int32_T;
      }
    } else {
      locallocalSwitch1_idx = localAdd10 + localDTConv_UFix_To_Single_4;
      if (((localAdd10 > 0) && (localDTConv_UFix_To_Single_4 > 0)) &&
          (locallocalSwitch1_idx <= 0)) {
        locallocalSwitch1_idx = MAX_int32_T;
      }
    }

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_1' */
    if (localAdd10 > 32767) {
      localtmp = MAX_int16_T;
    } else if (localAdd10 <= -32768) {
      localtmp = MIN_int16_T;
    } else {
      localtmp = (SInt16)localAdd10;
    }

    agPmpRefPFuM_B.DTConv_UFix_To_Single_1_o[0] = localtmp;
    if (locallocalSwitch1_idx > 32767) {
      localtmp = MAX_int16_T;
    } else if (locallocalSwitch1_idx <= -32768) {
      localtmp = MIN_int16_T;
    } else {
      localtmp = (SInt16)locallocalSwitch1_idx;
    }

    agPmpRefPFuM_B.DTConv_UFix_To_Single_1_o[1] = localtmp;

    /* S-Function "vems_vidGET" Block: <S7>/S-Function5 */
    VEMS_vidGET(PFuCtl_mFuPmpEstim, agPmpRefPFuM_B.SFunction5);

    /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_2' */
    if (agPmpRefPFuM_B.SFunction5 > 2147483647U) {
      localAdd10 = MAX_int32_T;
    } else {
      localAdd10 = (SInt32)agPmpRefPFuM_B.SFunction5;
    }

    /* Logic: '<S7>/Logical Operator3' incorporates:
     *  Constant: '<S7>/FuSysM_bCfPmpOneTDCStk_C1'
     *  Logic: '<S7>/Logical Operator4'
     */
    localLogicalOperator3 = ((!FuSysM_bCfPmpOneTDCStk_C) &&
      FuSysM_bAcvPmpCmdTDCCur);

    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant6'
     */
    if (FuSysM_bAcvPmpCmdTDCCur) {
      agPmpRefPFuM_B.Switch2 = localAdd10;
    } else {
      agPmpRefPFuM_B.Switch2 = 0;
    }

    /* S-Function "vems_vidSET" Block: <S7>/S-Function10 */
    VEMS_vidSET(FuSysM_mFuPmpStk1Req, agPmpRefPFuM_B.Switch2);

    /* Switch: '<S7>/Switch3' incorporates:
     *  Constant: '<S7>/Constant7'
     */
    if (localLogicalOperator3) {
      agPmpRefPFuM_B.Switch3 = 0;
    } else {
      agPmpRefPFuM_B.Switch3 = localAdd10;
    }

    /* S-Function "vems_vidSET" Block: <S7>/S-Function11 */
    VEMS_vidSET(FuSysM_mFuPmpStk2Req, agPmpRefPFuM_B.Switch3);

    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Constant: '<S7>/Constant4'
     *  DataTypeConversion: '<S7>/DTConv_UFix_To_Single_3'
     *  Sum: '<S7>/Add10'
     */
    if (FuSysM_bAcvPmpCmdTDCCur) {
      localAdd10 = localDTConv_UFix_To_Single_4 + locallocalAdd_0;
      if (((localDTConv_UFix_To_Single_4 > 0) && (locallocalAdd_0 > 0)) &&
          (localAdd10 <= 0)) {
        localAdd10 = MAX_int32_T;
      }

      if (localAdd10 > 32767) {
        localtmp = MAX_int16_T;
      } else if (localAdd10 <= -32768) {
        localtmp = MIN_int16_T;
      } else {
        localtmp = (SInt16)localAdd10;
      }

      agPmpRefPFuM_B.Switch[0] = localtmp;
      if (locallocalAdd_0 > 32767) {
        localtmp = MAX_int16_T;
      } else if (locallocalAdd_0 <= -32768) {
        localtmp = MIN_int16_T;
      } else {
        localtmp = (SInt16)locallocalAdd_0;
      }

      agPmpRefPFuM_B.Switch[1] = localtmp;
    } else {
      agPmpRefPFuM_B.Switch[0] = 0;
      agPmpRefPFuM_B.Switch[1] = 0;
    }

    /* S-Function "vems_vidSET" Block: <S7>/S-Function6 */
    VEMS_vidSET(FuSysM_agBegPmpStk1Ref, agPmpRefPFuM_B.Switch[1]);

    /* S-Function "vems_vidSET" Block: <S7>/S-Function7 */
    VEMS_vidSET(FuSysM_agEndPmpStk1Ref, agPmpRefPFuM_B.Switch[0]);

    /* S-Function "vems_vidSET" Block: <S7>/S-Function8 */
    VEMS_vidSET(FuSysM_agBegPmpStk2Ref, agPmpRefPFuM_B.DTConv_UFix_To_Single_1_o[0]);

    /* S-Function "vems_vidSET" Block: <S7>/S-Function9 */
    VEMS_vidSET(FuSysM_agEndPmpStk2Ref,
                agPmpRefPFuM_B.DTConv_UFix_To_Single_1_o[1]);
  }

  /* end of Outputs for SubSystem: '<S5>/F01_agPmpStkRef_EveInj' */
}

/* Output and update for exported function: FuSysM_EveCkSnOn_agPmpRefPFuM */
void FuSysM_EveCkSnOn_agPmpRefPFuM(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' */
  agPmpRefPFuM_ASYNC3(0);
}

/* Output and update for exported function: FuSysM_EveInj_agPmpRefPFuM */
void FuSysM_EveInj_agPmpRefPFuM(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' */
  agPmpRefPFuM_ASYNC3(1);
}

/* Output and update for function-call system: '<S4>/F02_agPmpStkRef_Spl' */
void agPmpRefPFu_F02_agPmpStkRef_Spl(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable_k;
  SInt32 localtmp;
  UInt32 localtmp_0;
  UInt16 localtmp_1;

  /* Outputs for enable SubSystem: '<S6>/F02_agPmpStkRef_Spl' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/MONENGSTRT_u8Inhib'
   *  EnablePort: '<S9>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (AGPMPREFPFUM_u8Inhib != 90) {
    /* Outputs for enable SubSystem: '<S9>/F01_agPmpStkRefClcn' incorporates:
     *  Constant: '<S9>/FuSysM_bCfPmpOneTDCStk_C'
     *  EnablePort: '<S10>/FuSysM_bCfPmpOneTDCStk_C'
     */
    if (FuSysM_bCfPmpOneTDCStk_C) {
      /* S-Function "vems_vidGET" Block: <S10>/S-Function1 */
      VEMS_vidGET(PFuCtl_agPmpCmdEfcReq, agPmpRefPFuM_B.SFunction1);

      /* S-Function "vems_vidGET" Block: <S10>/S-Function3 */
      VEMS_vidGET(Ext_nEng, agPmpRefPFuM_B.SFunction3);

      /* DataTypeConversion Block: '<S11>/Data Type Conversion'
       *
       * Regarding '<S11>/Data Type Conversion':
       *   Eliminate redundant data type conversion
       */

      /* Lookup: '<S11>/Look-Up Table'
       * About '<S11>/Look-Up Table':
       * Input0  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_k), (&(FuSysM_agDlyPmpStk_T[0])),
                     agPmpRefPFuM_B.SFunction3, (&(FuSysM_nEng_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S11>/Data Type Duplicate1'
       *
       * Regarding '<S11>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Sum: '<S10>/Add4' incorporates:
       *  Constant: '<S10>/FuSysM_agConvSplRefEveInj_C'
       *  Sum: '<S10>/Add14'
       */
      localtmp_0 = (UInt32)(agPmpRefPFuM_B.SFunction1 + localLookUpTable_k);
      if (localtmp_0 > 65535U) {
        localtmp_1 = MAX_uint16_T;
      } else {
        localtmp_1 = (UInt16)localtmp_0;
      }

      localtmp = localtmp_1 + FuSysM_agConvSplRefEveInj_C;
      if (localtmp > 32767) {
        agPmpRefPFuM_B.Add4 = MAX_int16_T;
      } else if (localtmp <= -32768) {
        agPmpRefPFuM_B.Add4 = MIN_int16_T;
      } else {
        agPmpRefPFuM_B.Add4 = (SInt16)localtmp;
      }

      /* S-Function "vems_vidGET" Block: <S10>/S-Function6 */
      VEMS_vidGET(PFuCtl_agWdPmpCmdReq, agPmpRefPFuM_B.SFunction6);

      /* Sum: '<S10>/Add12' */
      localtmp = agPmpRefPFuM_B.Add4 + agPmpRefPFuM_B.SFunction6;
      if (localtmp > 32767) {
        agPmpRefPFuM_B.Add12 = MAX_int16_T;
      } else if (localtmp <= -32768) {
        agPmpRefPFuM_B.Add12 = MIN_int16_T;
      } else {
        agPmpRefPFuM_B.Add12 = (SInt16)localtmp;
      }

      /* S-Function "vems_vidSET" Block: <S10>/S-Function5 */
      VEMS_vidSET(FuSysM_agEndPmpStk2Ref, agPmpRefPFuM_B.Add12);

      /* S-Function "vems_vidSET" Block: <S10>/S-Function7 */
      VEMS_vidSET(FuSysM_agBegPmpStk2Ref, agPmpRefPFuM_B.Add4);

      /* S-Function "vems_vidGET" Block: <S10>/S-Function2 */
      VEMS_vidGET(PFuCtl_mFuPmpEstim, agPmpRefPFuM_B.SFunction2);

      /* DataTypeConversion: '<S10>/DTConv_UFix_To_Single_1' */
      if (agPmpRefPFuM_B.SFunction2 > 2147483647U) {
        agPmpRefPFuM_B.DTConv_UFix_To_Single_1 = MAX_int32_T;
      } else {
        agPmpRefPFuM_B.DTConv_UFix_To_Single_1 = (SInt32)
          agPmpRefPFuM_B.SFunction2;
      }

      /* S-Function "vems_vidSET" Block: <S10>/S-Function4 */
      VEMS_vidSET(FuSysM_mFuPmpStk2Req, agPmpRefPFuM_B.DTConv_UFix_To_Single_1);
    }

    /* end of Outputs for SubSystem: '<S9>/F01_agPmpStkRefClcn' */
  }

  /* end of Outputs for SubSystem: '<S6>/F02_agPmpStkRef_Spl' */
}

/* Output and update for exported function: FuSysM_EveSpl_agPmpRefPFuM */
void FuSysM_EveSpl_agPmpRefPFuM(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S4>/F02_agPmpStkRef_Spl'
   */
  agPmpRefPFu_F02_agPmpStkRef_Spl();
}

/* Model initialize function */
void agPmpRefPFuM_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
}

#define AGPMPREFPFUM_STOP_SEC_CODE
#include "agPmpRefPFuM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
