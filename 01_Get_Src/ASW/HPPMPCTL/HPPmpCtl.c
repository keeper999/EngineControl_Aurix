/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : HPPmpCtl                                                */
/* !Description     : HPPmpCtl - RÉGULATION DE LA PRESSION RAIL               */
/*                                                                            */
/* !Module          : HPPmpCtl                                                */
/*                                                                            */
/* !File            : HPPmpCtl.c                                              */
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
/* !Reference       : V02NT1004143 / 03                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Tue Jul 10 10:40:13 2012                              */
/*   Model name       : HPPmpCtl_AUTOCODE.mdl                                 */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /HPPmpCtl                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUCTL/HPPMPCTL/HPPmpCtl.c_v    $*/
/* $Revision::   1.5                                                         $*/
/* $Author::   etsasson                               $$Date::   10 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "HPPmpCtl.h"
#include "HPPmpCtl_private.h"

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
#define HPPMPCTL_START_SEC_VAR_UNSPECIFIED
#include "HPPmpCtl_MemMap.h"

/* Block signals (auto storage) */
BlockIO_HPPmpCtl HPPmpCtl_B;

/* Block states (auto storage) */
D_Work_HPPmpCtl HPPmpCtl_DWork;

#define HPPMPCTL_STOP_SEC_VAR_UNSPECIFIED
#include "HPPmpCtl_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define HPPMPCTL_START_SEC_CODE
#include "HPPmpCtl_MemMap.h"

void HPPmpCtl_ASYNC1(int controlPortIdx)
{
}

/*
 * Output and update for atomic system:
 *    '<S10>/F01_HPPmpCtl'
 *    '<S7>/F01_HPPmpCtl'
 */
void HPPmpCtl_F01_HPPmpCtl(Float32 *rty_PFuCtl_pFuRailDifDClCtl,
  rtB_F01_HPPmpCtl_HPPmpCtl *localB)
{
  /* Constant: '<S11>/ConstVal' */
  localB->ConstVal = 0;

  /* Constant: '<S11>/ConstVal_1' */
  (*rty_PFuCtl_pFuRailDifDClCtl) = 0.0F;
}

/* Output and update for function-call system: '<S1>/F01_HPPmpCtl' */
void HPPmpCtl_F01_HPPmpCtl_c(void)
{
  /* Outputs for enable SubSystem: '<S6>/F01_HPPmpCtl' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/HPSENSDIAG_u8Inhib'
   *  EnablePort: '<S10>/Enable'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  if (HPPMPCTL_u8Inhib != 90) {
    /* Outputs for atomic SubSystem: '<S10>/F01_HPPmpCtl' */
    HPPmpCtl_F01_HPPmpCtl(&PFuCtl_pFuRailDifDClCtl, &HPPmpCtl_B.F01_HPPmpCtl_p);

    /* end of Outputs for SubSystem: '<S10>/F01_HPPmpCtl' */

    /* S-Function "vems_vidSET" Block: <S10>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_pFuRailDifIClCtl, HPPmpCtl_B.F01_HPPmpCtl_p.ConstVal);
  }

  /* end of Outputs for SubSystem: '<S6>/F01_HPPmpCtl' */
}

/* Output and update for exported function: PFuCtl_EveRTSt_HPPmpCtl */
void PFuCtl_EveRTSt_HPPmpCtl(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_HPPmpCtl'
   *
   * Block requirements for '<S1>/F01_HPPmpCtl':
   *  1. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_001.01 ;
   *  2. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_002.01 ;
   *  3. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_04161_003.01 ;
   *  4. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_001.01 ;
   *  5. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_002.01 ;
   *  6. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_003.01 ;
   *  7. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_004.01 ;
   *  8. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_005.01 ;
   *  9. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_006.01 ;
   *  10. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_007.01 ;
   *  11. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_009.01 ;
   *  12. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_05354_008.01 ;
   *  13. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_012.01 ;
   *  14. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_013.01 ;
   *  15. SubSystem "F01_HPPmpCtl" !Trace_To : VEMS_R_10_2880_041.01 ;
   */
  HPPmpCtl_F01_HPPmpCtl_c();
}

/* Output and update for function-call system: '<S1>/F01_HPPmpCtl_Ini' */
void HPPmpCtl_F01_HPPmpCtl_Ini(void)
{
  /* Outputs for atomic SubSystem: '<S7>/F01_HPPmpCtl' */
  HPPmpCtl_F01_HPPmpCtl(&PFuCtl_pFuRailDifDClCtl, &HPPmpCtl_B.F01_HPPmpCtl_d);

  /* end of Outputs for SubSystem: '<S7>/F01_HPPmpCtl' */

  /* S-Function "vems_vidSET" Block: <S7>/VEMS_vidSET */
  VEMS_vidSET(PFuCtl_pFuRailDifIClCtl, HPPmpCtl_B.F01_HPPmpCtl_d.ConstVal);
}

/* Output and update for exported function: PFuCtl_EveRst_HPPmpCtl */
void PFuCtl_EveRst_HPPmpCtl(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_HPPmpCtl_Ini'
   *
   * Block requirements for '<S1>/F01_HPPmpCtl_Ini':
   *  1. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_001.01 ;
   *  2. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_002.01 ;
   *  3. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_04161_003.01 ;
   *  4. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_001.01 ;
   *  5. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_002.01 ;
   *  6. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_003.01 ;
   *  7. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_004.01 ;
   *  8. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_005.01 ;
   *  9. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_006.01 ;
   *  10. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_007.01 ;
   *  11. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_009.01 ;
   *  12. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_05354_008.01 ;
   *  13. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_012.01 ;
   *  14. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_013.01 ;
   *  15. SubSystem "F01_HPPmpCtl_Ini" !Trace_To : VEMS_R_10_2880_041.01 ;
   */
  HPPmpCtl_F01_HPPmpCtl_Ini();
}

/* Output and update for function-call system: '<S1>/F03_HPPmpCtl' */
void HPPmpCtl_F03_HPPmpCtl(void)
{
  Float32 localDataTypeConversion1;
  Boolean localLogicalOperator;
  Float32 localDataTypeConversion1_j;
  Float32 localExt_nEng_PFuCtl_nEng1_A_16;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  Float32 localInjrSys_mFuInjEstim_InjrSy;
  UInt32 localExt_nEng_PFuCtl_nEng1_A__g;
  UInt32 localbpIndex[2];
  UInt32 localInjrSys_mFuInjEstim_Injr_m;
  Boolean localNOT1;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Float32 localSwitch1;
  UInt16 locallocalOutDTConv_f;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S9>/F03_HPPmpCtl' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Constant: '<S9>/HPSENSDIAG_u8Inhib'
   *  EnablePort: '<S18>/Enable'
   *  RelationalOperator: '<S9>/Relational Operator'
   */
  if (HPPMPCTL_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET9 */
    VEMS_vidGET(PFuCtl_pFuRailDifIClCtl, HPPmpCtl_B.VEMS_vidGET9);

    /* DataTypeConversion: '<S18>/Data Type Conversion1' */
    PFuCtl_pFuRailDifIClCtl_prev = ((Float32)HPPmpCtl_B.VEMS_vidGET9) *
      1.192092896E-002F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_pFuReq, HPPmpCtl_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pFuRailSplMes, HPPmpCtl_B.VEMS_vidGET1);

    /* Sum: '<S22>/Sub' */
    localtmp = HPPmpCtl_B.VEMS_vidGET4 - HPPmpCtl_B.VEMS_vidGET1;
    if (localtmp > 32767) {
      HPPmpCtl_B.Sub = MAX_int16_T;
    } else if (localtmp <= -32768) {
      HPPmpCtl_B.Sub = MIN_int16_T;
    } else {
      HPPmpCtl_B.Sub = (SInt16)localtmp;
    }

    /* DataTypeConversion: '<S19>/Data Type Conversion1' */
    localDataTypeConversion1 = ((Float32)HPPmpCtl_B.Sub) * 781.25F;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET8 */
    VEMS_vidGET(PFuCtl_bAcvETBPFuOplCtl, HPPmpCtl_B.VEMS_vidGET8);

    /* Logic: '<S30>/Logical Operator' incorporates:
     *  Logic: '<S30>/Logical Operator1'
     *  UnitDelay: '<S32>/Unit Delay'
     */
    localLogicalOperator = ((!HPPmpCtl_B.VEMS_vidGET8) &&
      HPPmpCtl_DWork.UnitDelay_DSTATE_a);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET6 */
    VEMS_vidGET(PFuCtl_bAcvPFuCtl, HPPmpCtl_B.VEMS_vidGET6);

    /* Logic: '<S21>/Logical Operator' incorporates:
     *  Logic: '<S31>/Logical Operator'
     *  Logic: '<S31>/Logical Operator1'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    PFuCtl_bPFuRailClCtlIni = ((localLogicalOperator) ||
      (HPPmpCtl_B.VEMS_vidGET6 && (!HPPmpCtl_DWork.UnitDelay_DSTATE_o)));

    /* DataTypeConversion: '<S22>/Data Type Conversion1' */
    localDataTypeConversion1_j = ((Float32)HPPmpCtl_B.Sub) * 781.25F;

    /* UnitDelay: '<S34>/Unit Delay' */
    PFuCtl_pFuRailDif_prev = HPPmpCtl_DWork.UnitDelay_DSTATE;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, HPPmpCtl_B.VEMS_vidGET);

    /* PreLookup: '<S27>/Prelookup' */
    localExt_nEng_PFuCtl_nEng1_A__g = plook_u32u16f_binc(HPPmpCtl_B.VEMS_vidGET,
      (&(PFuCtl_nEng1_A[0])), 15U, &localExt_nEng_PFuCtl_nEng1_A_16);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET5 */
    VEMS_vidGET(InjrSys_mFuInjEstim, HPPmpCtl_B.VEMS_vidGET5);

    /* PreLookup: '<S28>/Prelookup' */
    localInjrSys_mFuInjEstim_Injr_m = plook_u32u16f_binc(HPPmpCtl_B.VEMS_vidGET5,
      (&(InjrSys_mFuInjEstim_A[0])), 6U, &localInjrSys_mFuInjEstim_InjrSy);

    /* Interpolation_n-D: '<S35>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localExt_nEng_PFuCtl_nEng1_A_16;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localInjrSys_mFuInjEstim_InjrSy;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localExt_nEng_PFuCtl_nEng1_A__g;
    localbpIndex[1] = localInjrSys_mFuInjEstim_Injr_m;
    PFuCtl_facGainPPFuCtl_MP = intrp2d_iu16n15ff_u32f_l_ns(localbpIndex,
      localfrac, (&(PFuCtl_facGainPPFuCtl_M[0])), 16U);

    /* Lookup_n-D: '<S36>/Lookup Table (n-D)' incorporates:
     *  Constant: '<S37>/offset'
     *  Constant: '<S37>/one_on_slope'
     *  DataTypeConversion: '<S37>/OutDTConv'
     *  Product: '<S37>/Product4'
     *  Sum: '<S37>/Add1'
     */
    PFuCtl_facGainPPFuCtlErrW_MP = look1_iu16lftu8n8If_binlcns((UInt16)
      ((SInt32)((Float32)ACTEMS_FloorF(((localDataTypeConversion1 -
      -2.56E+007F) * 1.279999968E-003F) + 0.5F))), (&(PFuCtl_pFuRailDif_A[0])),
      (&(PFuCtl_facWErrGainPPFuCtl_T[0])), 4U);

    /* Product: '<S39>/Divide' */
    PFuCtl_facGainPPFuCtlErrCor_MP = PFuCtl_facGainPPFuCtlErrW_MP *
      PFuCtl_facGainPPFuCtl_MP;

    /* Product: '<S38>/Divide' */
    PFuCtl_pFuRailDifPClCtl = localDataTypeConversion1 *
      PFuCtl_facGainPPFuCtlErrCor_MP;

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET7 */
    VEMS_vidGET(PFuCtl_bDetAgWdPmpCmdLim, HPPmpCtl_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_bTotCutOff, HPPmpCtl_B.VEMS_vidGET3);

    /* If: '<S24>/If2' incorporates:
     *  ActionPort: '<S40>/Action Port'
     *  ActionPort: '<S41>/Action Port'
     *  SubSystem: '<S24>/F01_IIni'
     *  SubSystem: '<S24>/F02_IClcn'
     */
    if (PFuCtl_bPFuRailClCtlIni) {
      /* SignalConversion: '<S40>/Signal Conversion3' incorporates:
       *  Constant: '<S40>/ConstVal'
       */
      localSwitch1 = 0.0F;
    } else {
      /* Logic: '<S41>/NOT' */
      localLogicalOperator = !HPPmpCtl_B.VEMS_vidGET7;

      /* Logic: '<S41>/NOT1' */
      localNOT1 = !HPPmpCtl_B.VEMS_vidGET3;

      /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_nEng_PFuCtl_nEng1_A_16;
      localfrac_0[0] = localfractionTmp_0d;
      localfractionTmp_0d = localInjrSys_mFuInjEstim_InjrSy;
      localfrac_0[1] = localfractionTmp_0d;
      localbpIndex_0[0] = localExt_nEng_PFuCtl_nEng1_A__g;
      localbpIndex_0[1] = localInjrSys_mFuInjEstim_Injr_m;
      localSwitch1 = intrp2d_iu16n15ff_u32f_l_ns(localbpIndex_0, localfrac_0,
        (&(PFuCtl_facGainIPFuCtl_M[0])), 16U);

      /* Product: '<S44>/Divide' */
      PFuCtl_pFuRailDifIncIClCtl = localDataTypeConversion1 * localSwitch1;

      /* DataTypeConversion: '<S43>/OutDTConv' incorporates:
       *  Abs: '<S41>/Abs1'
       *  Constant: '<S43>/offset'
       *  Constant: '<S43>/one_on_slope'
       *  Product: '<S43>/Product4'
       *  Sum: '<S43>/Add1'
       */
      locallocalOutDTConv_f = (UInt16)((SInt32)((Float32)ACTEMS_FloorF
        ((1.279999968E-003F * ACTEMS_FabsF(localDataTypeConversion1)) + 0.5F)));

      /* RelationalOperator: '<S41>/Greater Or Equal' incorporates:
       *  Constant: '<S41>/PFuCtl_pFuRailDifAcvClCtl_C'
       */
      HPPmpCtl_B.GreaterOrEqual = (locallocalOutDTConv_f >=
        PFuCtl_pFuRailDifAcvClCtl_C);

      /* Switch: '<S41>/Switch1' incorporates:
       *  Logic: '<S41>/AND'
       *  Sum: '<S41>/Add1'
       */
      if ((localLogicalOperator) && (localNOT1)) {
        localSwitch1 = PFuCtl_pFuRailDifIncIClCtl + PFuCtl_pFuRailDifIClCtl_prev;
      } else {
        localSwitch1 = PFuCtl_pFuRailDifIClCtl_prev;
      }

      /* Switch: '<S41>/Switch3' incorporates:
       *  Constant: '<S41>/ConstVal'
       *  Constant: '<S41>/PFuCtl_bAcvRstIFuRailCtl_C'
       *  Logic: '<S41>/NOT3'
       */
      if (!PFuCtl_bAcvRstIFuRailCtl_C) {
        localfractionTmp_0d = PFuCtl_pFuRailDifIClCtl_prev;
      } else {
        localfractionTmp_0d = 0.0F;
      }

      /* Switch: '<S41>/Switch5' incorporates:
       *  Constant: '<S41>/ZERO4'
       *  Inport: '<Root>/FRM_bInhRstIFuRailCtl'
       *  Logic: '<S41>/NOT2'
       *  RelationalOperator: '<S41>/Greater Or Equal1'
       */
      if (!GDGAR_bGetFRM(FRM_FRM_INHRSTIFURAILCTL)) {
        localLogicalOperator = HPPmpCtl_B.GreaterOrEqual;
      } else {
        localLogicalOperator = (locallocalOutDTConv_f >=
          PFuCtl_pFuRailDifAcvClCtlDft_C);
      }

      /* Switch: '<S41>/Switch2' */
      if (localLogicalOperator) {
        localSwitch1 = localfractionTmp_0d;
      }
    }

    /* SignalConversion: '<S18>/Signal Conversion' */
    PFuCtl_pFuRailDifDClCtl_prev = PFuCtl_pFuRailDifDClCtl;

    /* If: '<S25>/If2' incorporates:
     *  ActionPort: '<S45>/Action Port'
     *  ActionPort: '<S46>/Action Port'
     *  SubSystem: '<S25>/F01_DIni'
     *  SubSystem: '<S25>/F02_DClcn'
     */
    if (PFuCtl_bPFuRailClCtlIni) {
      /* SignalConversion: '<S45>/Signal Conversion3' incorporates:
       *  Constant: '<S45>/ConstVal'
       */
      localfractionTmp_0d = 0.0F;
    } else {
      /* Sum: '<S46>/Add1' */
      localDataTypeConversion1 -= PFuCtl_pFuRailDif_prev;

      /* Interpolation_n-D: '<S47>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_nEng_PFuCtl_nEng1_A_16;
      localfractionTmp_0d = intrp1d_iu16n14ff_u32f_l_ns
        (localExt_nEng_PFuCtl_nEng1_A__g, localfractionTmp_0d,
         (&(PFuCtl_facGainD1PFuCtl_T[0])));

      /* Product: '<S49>/Divide' */
      localDataTypeConversion1 *= localfractionTmp_0d;

      /* Interpolation_n-D: '<S48>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localExt_nEng_PFuCtl_nEng1_A_16;
      localfractionTmp_0d = intrp1d_iu16n14ff_u32f_l_ns
        (localExt_nEng_PFuCtl_nEng1_A__g, localfractionTmp_0d,
         (&(PFuCtl_facGainD2PFuCtl_T[0])));

      /* Sum: '<S46>/Add2' incorporates:
       *  Product: '<S50>/Divide'
       */
      localfractionTmp_0d = (localfractionTmp_0d * PFuCtl_pFuRailDifDClCtl_prev)
        + localDataTypeConversion1;
    }

    /* Sum: '<S26>/Add1' */
    PFuCtl_pFuRailDifClCtl = (PFuCtl_pFuRailDifPClCtl + localSwitch1) +
      localfractionTmp_0d;

    /* SignalConversion: '<S19>/Signal Conversion1' */
    PFuCtl_pFuRailDifDClCtl = localfractionTmp_0d;

    /* DataTypeConversion: '<S29>/OutDTConv' incorporates:
     *  Constant: '<S29>/offset'
     *  Constant: '<S29>/one_on_slope'
     *  Product: '<S29>/Product4'
     *  Sum: '<S29>/Add1'
     */
    localDataTypeConversion1 = 8.388607788E+001F * localSwitch1;
    if ((localDataTypeConversion1 < 8.388608E+006F) && (localDataTypeConversion1
         > -8.388608E+006F)) {
      localDataTypeConversion1 = (Float32)ACTEMS_FloorF
        (localDataTypeConversion1 + 0.5F);
    }

    if (localDataTypeConversion1 < 2.147483648E+009F) {
      if (localDataTypeConversion1 >= -2.147483648E+009F) {
        HPPmpCtl_B.OutDTConv_m = (SInt32)localDataTypeConversion1;
      } else {
        HPPmpCtl_B.OutDTConv_m = MIN_int32_T;
      }
    } else {
      HPPmpCtl_B.OutDTConv_m = MAX_int32_T;
    }

    /* Product: '<S53>/Divide' incorporates:
     *  Constant: '<S20>/PFuCtl_noTDCPmpStk_C'
     *  DataTypeConversion: '<S20>/Data Type Conversion2'
     *  DataTypeConversion: '<S20>/Data Type Conversion3'
     */
    PFuCtl_mFuPmpReqOpl = (((Float32)HPPmpCtl_B.VEMS_vidGET5) *
      7.450580597E-009F) * ((Float32)PFuCtl_noTDCPmpStk_C);

    /* Switch: '<S20>/Switch1' */
    if (HPPmpCtl_B.VEMS_vidGET8) {
      PFuCtl_pFuRailDifCtl = PFuCtl_pFuRailDifOplCtl;
    } else {
      PFuCtl_pFuRailDifCtl = PFuCtl_pFuRailDifClCtl;
    }

    /* S-Function "vems_vidGET" Block: <S18>/VEMS_vidGET2 */
    VEMS_vidGET(FuSysM_facCnvMassFuPFu, HPPmpCtl_B.VEMS_vidGET2);

    /* Product: '<S52>/Divide' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     */
    localfractionTmp_0d = PFuCtl_pFuRailDifCtl / (((Float32)
      HPPmpCtl_B.VEMS_vidGET2) * 1.220703125E+006F);

    /* Outputs for atomic SubSystem: '<S52>/If Action Subsystem3' */

    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S55>/Constant1'
     *  Constant: '<S55>/Constant2'
     *  Constant: '<S55>/Constant3'
     *  Logic: '<S55>/Logical Operator1'
     *  RelationalOperator: '<S55>/Relational Operator'
     *  RelationalOperator: '<S55>/Relational Operator1'
     *  RelationalOperator: '<S55>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      PFuCtl_mFuPmpReqCtl = 0.0F;
    } else {
      PFuCtl_mFuPmpReqCtl = localfractionTmp_0d;
    }

    /* end of Outputs for SubSystem: '<S52>/If Action Subsystem3' */

    /* DataTypeConversion: '<S51>/OutDTConv' incorporates:
     *  Constant: '<S51>/offset'
     *  Constant: '<S51>/one_on_slope'
     *  Product: '<S51>/Product4'
     *  Sum: '<S20>/Add'
     *  Sum: '<S51>/Add1'
     */
    localDataTypeConversion1 = ((PFuCtl_mFuPmpReqOpl + PFuCtl_mFuPmpReqCtl) -
      -0.0078125F) * 1.34217728E+008F;
    if ((localDataTypeConversion1 < 8.388608E+006F) && (localDataTypeConversion1
         > -8.388608E+006F)) {
      localDataTypeConversion1 = (Float32)ACTEMS_FloorF
        (localDataTypeConversion1 + 0.5F);
    }

    if (localDataTypeConversion1 < 4.294967296E+009F) {
      if (localDataTypeConversion1 >= 0.0F) {
        HPPmpCtl_B.OutDTConv = (UInt32)localDataTypeConversion1;
      } else {
        HPPmpCtl_B.OutDTConv = 0U;
      }
    } else {
      HPPmpCtl_B.OutDTConv = MAX_uint32_T;
    }

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvIFrzPrailDif, HPPmpCtl_B.GreaterOrEqual);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET1 */
    VEMS_vidSET(PFuCtl_mFuPmpReq, HPPmpCtl_B.OutDTConv);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET2 */
    VEMS_vidSET(PFuCtl_pFuRailDif, HPPmpCtl_B.Sub);

    /* S-Function "vems_vidSET" Block: <S18>/VEMS_vidSET3 */
    VEMS_vidSET(PFuCtl_pFuRailDifIClCtl, HPPmpCtl_B.OutDTConv_m);

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    HPPmpCtl_DWork.UnitDelay_DSTATE_a = HPPmpCtl_B.VEMS_vidGET8;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    HPPmpCtl_DWork.UnitDelay_DSTATE_o = HPPmpCtl_B.VEMS_vidGET6;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    HPPmpCtl_DWork.UnitDelay_DSTATE = localDataTypeConversion1_j;
  }

  /* end of Outputs for SubSystem: '<S9>/F03_HPPmpCtl' */
}

/* Output and update for exported function: PFuCtl_EveSpl_HPPmpCtl */
void PFuCtl_EveSpl_HPPmpCtl(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_HPPmpCtl'
   *
   * Block requirements for '<S1>/F03_HPPmpCtl':
   *  1. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_001.01 ;
   *  2. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_002.01 ;
   *  3. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_04161_003.01 ;
   *  4. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_001.01 ;
   *  5. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_002.01 ;
   *  6. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_003.01 ;
   *  7. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_004.01 ;
   *  8. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_005.01 ;
   *  9. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_006.01 ;
   *  10. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_007.01 ;
   *  11. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_008.01 ;
   *  12. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_05354_009.01 ;
   *  13. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_012.01 ;
   *  14. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_013.01 ;
   *  15. SubSystem "F03_HPPmpCtl" !Trace_To : VEMS_R_10_2880_041.01 ;
   */
  HPPmpCtl_F03_HPPmpCtl();
}

/* Output and update for function-call system: '<S1>/F02_HPPmpCtl_ETB' */
void HPPmpCtl_F02_HPPmpCtl_ETB(void)
{
  Float32 localSwitch;
  Float32 localSwitch1_o;
  Boolean localRelationalOperator_c;
  Float32 localDivide_e;
  UInt16 localSwitch3_h;
  SInt16 localSwitch2;
  UInt32 localtmp;
  UInt16 localtmp_0;

  /* Inport: '<S8>/PFuCtl_pFuRailDifOplCtl_prev' */
  PFuCtl_pFuRailDifOplCtl_prev = PFuCtl_pFuRailDifOplCtl;

  /* Inport: '<S8>/PFuCtl_tiETB_Prev' */
  PFuCtl_tiETB_Prev = PFuCtl_tiETB;

  /* Outputs for enable SubSystem: '<S8>/F02_HPPmpCtl_ETB' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/HPSENSDIAG_u8Inhib'
   *  EnablePort: '<S13>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (HPPMPCTL_u8Inhib != 90) {
    /* If: '<S13>/If' incorporates:
     *  ActionPort: '<S14>/Action Port'
     *  ActionPort: '<S15>/Action Port'
     *  Constant: '<S13>/PFuCtl_bAcvETBPFuClCtl_C'
     *  SubSystem: '<S13>/F01_PFuOplCtl_Clcn'
     *  SubSystem: '<S13>/F02_PFuOplCtl_Ini'
     */
    if (PFuCtl_bAcvETBPFuClCtl_C) {
      /* Sum: '<S14>/Add1' incorporates:
       *  Constant: '<S14>/PFuCtl_tiSampleMid_SC'
       */
      localtmp = (UInt32)((SInt32)(((UInt32)((PFuCtl_tiETB_Prev << 13) +
        (PFuCtl_tiSampleMid_SC * 205))) >> 13));
      if (localtmp > 65535U) {
        localSwitch3_h = MAX_uint16_T;
      } else {
        localSwitch3_h = (UInt16)localtmp;
      }

      /* Switch: '<S14>/Switch3' incorporates:
       *  Constant: '<S14>/ConstVal_1'
       *  Constant: '<S14>/PFuCtl_tiPFuDifStep1ETB_C'
       *  Constant: '<S14>/PFuCtl_tiPFuDifStep2ETB_C'
       *  RelationalOperator: '<S14>/Relational Operator1'
       *  Sum: '<S14>/Add2'
       */
      localtmp = (UInt32)(PFuCtl_tiPFuDifStep2ETB_C +
                            PFuCtl_tiPFuDifStep1ETB_C);
      if (localtmp > 65535U) {
        localtmp_0 = MAX_uint16_T;
      } else {
        localtmp_0 = (UInt16)localtmp;
      }

      if (!(PFuCtl_tiETB_Prev <= localtmp_0)) {
        localSwitch3_h = 0U;
      }

      /* Switch: '<S14>/Switch1' incorporates:
       *  Constant: '<S14>/PFuCtl_pFuRailDifStep1ETB_C'
       *  Constant: '<S14>/PFuCtl_pFuRailDifStep2ETB_C'
       *  Constant: '<S14>/PFuCtl_tiPFuDifStep1ETB_C_1'
       *  RelationalOperator: '<S14>/Relational Operator'
       */
      if (localSwitch3_h <= PFuCtl_tiPFuDifStep1ETB_C) {
        localSwitch2 = PFuCtl_pFuRailDifStep1ETB_C;
      } else {
        localSwitch2 = PFuCtl_pFuRailDifStep2ETB_C;
      }

      /* Switch: '<S14>/Switch2' incorporates:
       *  Constant: '<S14>/PFuCtl_bSelETBpFuRailDifReq_C'
       *  Constant: '<S14>/PFuCtl_pFuRailDifReqETB_C'
       */
      if (!PFuCtl_bSelETBpFuRailDifReq_C) {
        localSwitch2 = PFuCtl_pFuRailDifReqETB_C;
      }

      /* DataTypeConversion: '<S14>/Data Type Conversion2' incorporates:
       *  Constant: '<S14>/PFuCtl_pRailRampMaxETB_C'
       */
      localSwitch = ((Float32)PFuCtl_pRailRampMaxETB_C) * 390.625F;

      /* SignalConversion: '<S14>/Signal Conversion' */
      PFuCtl_tiETB = localSwitch3_h;

      /* Sum: '<S16>/Sum' incorporates:
       *  DataTypeConversion: '<S14>/Data Type Conversion1'
       */
      localSwitch1_o = (((Float32)localSwitch2) * 781.25F) -
        PFuCtl_pFuRailDifOplCtl_prev;

      /* RelationalOperator: '<S16>/Relational Operator' */
      localRelationalOperator_c = (localSwitch1_o >= localSwitch);

      /* Product: '<S17>/Divide' incorporates:
       *  Constant: '<S14>/ConstVal'
       */
      localDivide_e = -localSwitch;

      /* Switch: '<S16>/Switch1' incorporates:
       *  RelationalOperator: '<S16>/Relational Operator1'
       */
      if (!(localSwitch1_o >= localDivide_e)) {
        localSwitch1_o = localDivide_e;
      }

      /* Switch: '<S16>/Switch' */
      if (!localRelationalOperator_c) {
        localSwitch = localSwitch1_o;
      }

      /* Sum: '<S16>/Sum1' */
      PFuCtl_pFuRailDifOplCtl = PFuCtl_pFuRailDifOplCtl_prev + localSwitch;

      /* SignalConversion: '<S14>/Signal Conversion1' incorporates:
       *  Constant: '<S14>/ConstVal_2'
       */
      HPPmpCtl_B.Merge2 = TRUE;
    } else {
      /* SignalConversion: '<S15>/Signal Conversion3' incorporates:
       *  Constant: '<S15>/ConstVal_1'
       */
      PFuCtl_tiETB = 0U;

      /* SignalConversion: '<S15>/Signal Conversion1' incorporates:
       *  Constant: '<S15>/ConstVal'
       */
      PFuCtl_pFuRailDifOplCtl = 0.0F;

      /* SignalConversion: '<S15>/Signal Conversion2' incorporates:
       *  Constant: '<S15>/ConstVal_2'
       */
      HPPmpCtl_B.Merge2 = FALSE;
    }

    /* S-Function "vems_vidSET" Block: <S13>/VEMS_vidSET */
    VEMS_vidSET(PFuCtl_bAcvETBPFuOplCtl, HPPmpCtl_B.Merge2);
  }

  /* end of Outputs for SubSystem: '<S8>/F02_HPPmpCtl_ETB' */
}

/* Output and update for exported function: PFuCtl_SdlMid_HPPmpCtl */
void PFuCtl_SdlMid_HPPmpCtl(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_HPPmpCtl_ETB'
   *
   * Block requirements for '<S1>/F02_HPPmpCtl_ETB':
   *  1. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_001.01 ;
   *  2. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_002.01 ;
   *  3. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_04161_003.01 ;
   *  4. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_001.01 ;
   *  5. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_002.01 ;
   *  6. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_003.01 ;
   *  7. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_004.01 ;
   *  8. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_005.01 ;
   *  9. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_006.01 ;
   *  10. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_007.01 ;
   *  11. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_008.01 ;
   *  12. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_05354_009.01 ;
   *  13. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_012.01 ;
   *  14. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_013.01 ;
   *  15. SubSystem "F02_HPPmpCtl_ETB" !Trace_To : VEMS_R_10_2880_041.01 ;
   */
  HPPmpCtl_F02_HPPmpCtl_ETB();
}

/* Model initialize function */
void HPPmpCtl_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    HPPmpCtl_B.OutDTConv = 1048576U;
  }

  /* custom signals */
  PFuCtl_mFuPmpReq = 1048576U;

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
}

#define HPPMPCTL_STOP_SEC_CODE
#include "HPPmpCtl_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
