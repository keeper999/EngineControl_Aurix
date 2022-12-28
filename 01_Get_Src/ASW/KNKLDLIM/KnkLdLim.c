/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : KnkLdLim                                                */
/* !Description     : LOAD LIMITATION IN KNOCK SITUATION                      */
/*                                                                            */
/* !Module          : KnkLdLim                                                */
/*                                                                            */
/* !File            : KnkLdLim.c                                              */
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
/* !Reference       : PTS_DOC_5144542 / 02                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Thu Mar 28 15:46:24 2013                              */
/*   Model name       : KnkLdLim_AUTOCODE.mdl                                 */
/*   Model version    : 1.206                                                 */
/*   Root subsystem   : /KnkLdLim                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/KNKRBLTREATSYS/KNKLDLIM/KnkLdLim$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "KnkLdLim.h"
#include "KnkLdLim_private.h"

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
#define KNKLDLIM_START_SEC_VAR_UNSPECIFIED
#include "KnkLdLim_MemMap.h"

/* Block signals (auto storage) */
BlockIO_KnkLdLim KnkLdLim_B;

/* Block states (auto storage) */
D_Work_KnkLdLim KnkLdLim_DWork;

#define KNKLDLIM_STOP_SEC_VAR_UNSPECIFIED
#include "KnkLdLim_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define KNKLDLIM_START_SEC_CODE
#include "KnkLdLim_MemMap.h"

void KnkLdLim_ASYNC1(int controlPortIdx)
{
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem'
 *    '<S25>/If Action Subsystem'
 *    '<S30>/If Action Subsystem'
 */
void KnkLdLim_IfActionSubsystem(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S22>/Value 1' */
  (*rty_Out1) = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S12>/If Action Subsystem1'
 *    '<S25>/If Action Subsystem1'
 *    '<S30>/If Action Subsystem1'
 */
void KnkLdLim_IfActionSubsystem1(Boolean rtu_0, Boolean *rty_Out1)
{
  /* Inport: '<S23>/Value 2' */
  (*rty_Out1) = rtu_0;
}

/* Output and update for function-call system: '<S1>/F02_LoadLimCalc' */
void KnkLdLim_F02_LoadLimCalc(void)
{
  Float32 localExt_nEng_KnkMgt_nEng_ldLim;
  Float32 localInterpolationUsingPreloo_m;
  Boolean localLogicalOperator;
  Float32 localtmp;
  Float32 localDivide;
  Float32 localfrac[2];
  UInt32 localExt_rAirLd_KnkMgt_rAirLd_l;
  UInt32 localbpIndex[2];
  UInt32 localExt_nEng_KnkMgt_nEng_ldL_e;
  Float32 localfrac_0[2];
  UInt32 localbpIndex_0[2];
  Boolean localRelationalOperator_o;
  SInt16 localSwitch_d;
  Float32 localSum2[6];
  SInt32 locali;
  UInt8 locallocalDTConv_UFix_To_Single;
  SInt32 localq;
  SInt32 localqY;

  /* Outputs for enable SubSystem: '<S5>/F02_LoadLimCalc' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (KNKLDLIM_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET(KnkRbl_noCyl, KnkLdLim_B.VEMS_vidGET7);

    /* DataTypeConversion: '<S6>/DTConv_UFix_To_Single_2' */
    locali = KnkLdLim_B.VEMS_vidGET7 + 1;
    if (((UInt32)locali) > 255U) {
      locallocalDTConv_UFix_To_Single = MAX_uint8_T;
    } else {
      locallocalDTConv_UFix_To_Single = (UInt8)locali;
    }

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(KnkMgt_prm_agIgKnkDetOfsCyl, 6, KnkLdLim_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_nEng, KnkLdLim_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(Ext_rAirLd, KnkLdLim_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(IgSys_agIgKnkPrevOfs, KnkLdLim_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(KnkMgt_prm_agIgKnkAdpOfsCyl, 6, KnkLdLim_B.VEMS_vidGET5);

    /* Outputs for enable SubSystem: '<S6>/F01_LdLimAdvCor' incorporates:
     *  Constant: '<S6>/KnkMgt_bAcvLdLimAdvCor_C'
     *  EnablePort: '<S7>/NS_Enable'
     */
    if (KnkMgt_bAcvLdLimAdvCor_C) {
      /* Sum: '<S7>/Sum2' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion2'
       *  DataTypeConversion: '<S7>/Data Type Conversion3'
       */
      for (locali = 0; locali < 6; locali++) {
        localSum2[locali] = ((((Float32)KnkLdLim_B.VEMS_vidGET6[(locali)]) *
                              0.375F) - 36.0F) + ((((Float32)
          KnkLdLim_B.VEMS_vidGET5[(locali)]) * 0.375F) - 36.0F);
      }

      /* DataTypeConversion: '<S7>/DTConv_UFix_To_Single_2' incorporates:
       *  Constant: '<S7>/KnkMgt_tiFilAgIgKnkCor_C'
       */
      localExt_nEng_KnkMgt_nEng_ldLim = ((Float32)KnkMgt_tiFilAgIgKnkCor_C) *
        4.999999888E-003F;

      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  Constant: '<S7>/Ext_noCylEng_SC'
       */
      localInterpolationUsingPreloo_m = (Float32)Ext_noCylEng_SC;

      /* Logic: '<S18>/Logical Operator' incorporates:
       *  Constant: '<S7>/Constant8'
       *  Logic: '<S18>/Logical Operator1'
       *  UnitDelay: '<S24>/Unit Delay'
       */
      localLogicalOperator = !KnkLdLim_DWork.UnitDelay_DSTATE_d3;

      /* Outputs for enable SubSystem: '<S11>/Reset du filtre' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      if (localLogicalOperator) {
        /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
         *  Constant: '<S7>/Constant6'
         */
        KnkLdLim_B.DataTypeConversion = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S11>/Reset du filtre' */

      /* Saturate: '<S21>/Saturation [0-1]' */
      localtmp = localExt_nEng_KnkMgt_nEng_ldLim;

      /* Product: '<S17>/Divide' incorporates:
       *  Sum: '<S7>/Add'
       */
      localDivide = (((((localSum2[0] + localSum2[1]) + localSum2[2]) +
                       localSum2[3]) + localSum2[4]) + localSum2[5]) /
        localInterpolationUsingPreloo_m;

      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S7>/Constant6'
       *  UnitDelay: '<S20>/UnitDelay'
       *  UnitDelay: '<S20>/UnitDelay1'
       */
      if (KnkLdLim_DWork.UnitDelay_i) {
        localInterpolationUsingPreloo_m = KnkLdLim_DWork.UnitDelay;
      } else {
        localInterpolationUsingPreloo_m = 0.0F;
      }

      /* Sum: '<S21>/Sum' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  Sum: '<S7>/Sum1'
       */
      localDivide = (localDivide - ((((Float32)KnkLdLim_B.VEMS_vidGET3) *
        0.375F) - 36.0F)) - localInterpolationUsingPreloo_m;

      /* Sum: '<S21>/Sum1' incorporates:
       *  Product: '<S21>/Product'
       */
      localDivide = (rt_SATURATE(localtmp, 0.0F, 1.0F) * localDivide) +
        localInterpolationUsingPreloo_m;

      /* Switch: '<S11>/Switch' */
      if (localLogicalOperator) {
        KnkMgt_agIgKnkCorFil = KnkLdLim_B.DataTypeConversion;
      } else {
        KnkMgt_agIgKnkCorFil = localDivide;
      }

      /* PreLookup: '<S16>/Prelookup' */
      localExt_rAirLd_KnkMgt_rAirLd_l = plook_u32u16f_binc
        (KnkLdLim_B.VEMS_vidGET2, (&(KnkMgt_rAirLd_ldLim_A[0])), 7U,
         &localInterpolationUsingPreloo_m);

      /* PreLookup: '<S15>/Prelookup' */
      localExt_nEng_KnkMgt_nEng_ldL_e = plook_u32u16f_binc
        (KnkLdLim_B.VEMS_vidGET1, (&(KnkMgt_nEng_ldLim_A[0])), 7U,
         &localExt_nEng_KnkMgt_nEng_ldLim);

      /* Interpolation_n-D: '<S14>/Interpolation Using Prelookup3' */
      localDivide = localInterpolationUsingPreloo_m;
      localfrac[0] = localDivide;
      localDivide = localExt_nEng_KnkMgt_nEng_ldLim;
      localfrac[1] = localDivide;
      localbpIndex[0] = localExt_rAirLd_KnkMgt_rAirLd_l;
      localbpIndex[1] = localExt_nEng_KnkMgt_nEng_ldL_e;
      localDivide = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex, localfrac,
        (&(KnkMgt_agIgLoThd_KnkLdLim_M[0])), 8U);

      /* RelationalOperator: '<S12>/Relational Operator1' */
      localLogicalOperator = (localDivide >= KnkMgt_agIgKnkCorFil);

      /* Interpolation_n-D: '<S13>/Interpolation Using Prelookup3' */
      localDivide = localInterpolationUsingPreloo_m;
      localfrac_0[0] = localDivide;
      localDivide = localExt_nEng_KnkMgt_nEng_ldLim;
      localfrac_0[1] = localDivide;
      localbpIndex_0[0] = localExt_rAirLd_KnkMgt_rAirLd_l;
      localbpIndex_0[1] = localExt_nEng_KnkMgt_nEng_ldL_e;
      localInterpolationUsingPreloo_m = intrp2d_iu8n2ff_u32f_l_ns(localbpIndex_0,
        localfrac_0, (&(KnkMgt_agIgHiThd_KnkLdLim_M[0])), 8U);

      /* RelationalOperator: '<S12>/Relational Operator' */
      localRelationalOperator_o = (KnkMgt_agIgKnkCorFil >=
        localInterpolationUsingPreloo_m);

      /* If: '<S12>/If' incorporates:
       *  ActionPort: '<S22>/Action Port'
       *  ActionPort: '<S23>/Action Port'
       *  SubSystem: '<S12>/If Action Subsystem'
       *  SubSystem: '<S12>/If Action Subsystem1'
       */
      if (localLogicalOperator) {
        KnkLdLim_IfActionSubsystem(FALSE, &KnkMgt_bLdLimKnkAdvCor);
      } else {
        if (localRelationalOperator_o) {
          KnkLdLim_IfActionSubsystem1(TRUE, &KnkMgt_bLdLimKnkAdvCor);
        }
      }

      /* Update for UnitDelay: '<S24>/Unit Delay' incorporates:
       *  Constant: '<S7>/Constant8'
       */
      KnkLdLim_DWork.UnitDelay_DSTATE_d3 = TRUE;

      /* Update for UnitDelay: '<S20>/UnitDelay' */
      KnkLdLim_DWork.UnitDelay = KnkMgt_agIgKnkCorFil;

      /* Update for UnitDelay: '<S20>/UnitDelay1' incorporates:
       *  Constant: '<S20>/Constant3'
       */
      KnkLdLim_DWork.UnitDelay_i = TRUE;
    }

    /* end of Outputs for SubSystem: '<S6>/F01_LdLimAdvCor' */
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(KnkMgt_bSuperKnkDet, 4, KnkLdLim_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET1DArray(Detection_cliquetis, 4, KnkLdLim_B.VEMS_vidGET);

    /* Outputs for enable SubSystem: '<S6>/F02_LoadLimKnk' incorporates:
     *  Constant: '<S6>/KnkMgt_bAcvLdLimKnkDet_C'
     *  EnablePort: '<S8>/NS_Enable'
     */
    if (KnkMgt_bAcvLdLimKnkDet_C) {
      /* DataTypeConversion: '<S8>/DTConv_UFix_To_Single_1' incorporates:
       *  Constant: '<S8>/KnkMgt_ctKnkDetInc_C'
       */
      localSwitch_d = KnkMgt_ctKnkDetInc_C;

      /* Switch: '<S8>/Switch' incorporates:
       *  Constant: '<S8>/Constant_61'
       *  Constant: '<S8>/KnkMgt_bStraLdLimKnkDet_C'
       *  Constant: '<S8>/KnkMgt_ctKnkDetDec_C'
       *  Logic: '<S8>/OU2'
       *  Logic: '<S8>/OU4'
       *  Product: '<S27>/Divide'
       *  Selector: '<S8>/Selector'
       *  Selector: '<S8>/Selector1'
       */
      if (!(KnkLdLim_B.VEMS_vidGET[locallocalDTConv_UFix_To_Single - 1] ||
            (KnkMgt_bStraLdLimKnkDet_C &&
             KnkLdLim_B.VEMS_vidGET4[locallocalDTConv_UFix_To_Single - 1]))) {
        localSwitch_d = (SInt16)(-KnkMgt_ctKnkDetDec_C);
      }

      /* Sum: '<S8>/Sum' incorporates:
       *  UnitDelay: '<S26>/Unit Delay'
       */
      locali = KnkLdLim_DWork.UnitDelay_DSTATE_d + localSwitch_d;
      if (locali <= 0) {
        KnkMgt_ctKnkDetLdLim = 0U;
      } else if (locali > 65535) {
        KnkMgt_ctKnkDetLdLim = MAX_uint16_T;
      } else {
        KnkMgt_ctKnkDetLdLim = (UInt16)locali;
      }

      /* If: '<S25>/If' incorporates:
       *  ActionPort: '<S28>/Action Port'
       *  ActionPort: '<S29>/Action Port'
       *  Constant: '<S8>/KnkMgt_ctKnkDetHiThd_C'
       *  Constant: '<S8>/KnkMgt_ctKnkDetLoThd_C'
       *  RelationalOperator: '<S25>/Relational Operator'
       *  RelationalOperator: '<S25>/Relational Operator1'
       *  SubSystem: '<S25>/If Action Subsystem'
       *  SubSystem: '<S25>/If Action Subsystem1'
       */
      if (KnkMgt_ctKnkDetLoThd_C >= KnkMgt_ctKnkDetLdLim) {
        KnkLdLim_IfActionSubsystem(FALSE, &KnkMgt_bAcvTmpLdLimKnkRaw);
      } else {
        if (KnkMgt_ctKnkDetLdLim >= KnkMgt_ctKnkDetHiThd_C) {
          KnkLdLim_IfActionSubsystem1(TRUE, &KnkMgt_bAcvTmpLdLimKnkRaw);
        }
      }

      /* Update for UnitDelay: '<S26>/Unit Delay' */
      KnkLdLim_DWork.UnitDelay_DSTATE_d = KnkMgt_ctKnkDetLdLim;
    }

    /* end of Outputs for SubSystem: '<S6>/F02_LoadLimKnk' */

    /* Outputs for enable SubSystem: '<S6>/F03_LoadLimSuperKnk' incorporates:
     *  Constant: '<S6>/KnkMgt_bAcvLdLimSuperKnkDet_C'
     *  EnablePort: '<S9>/NS_Enable'
     */
    if (KnkMgt_bAcvLdLimSuperKnkDet_C) {
      /* DataTypeConversion: '<S9>/DTConv_UFix_To_Single_1' incorporates:
       *  Constant: '<S9>/KnkMgt_ctSuperKnkDetInc_C'
       */
      locali = KnkMgt_ctSuperKnkDetInc_C;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant_62'
       *  Constant: '<S9>/KnkMgt_ctSuperKnkDetDec_C'
       *  Product: '<S32>/Divide'
       *  Selector: '<S9>/Selector'
       */
      if (!KnkLdLim_B.VEMS_vidGET4[locallocalDTConv_UFix_To_Single - 1]) {
        locali = -KnkMgt_ctSuperKnkDetDec_C;
      }

      /* Sum: '<S9>/Sum' incorporates:
       *  UnitDelay: '<S31>/Unit Delay'
       */
      localq = KnkLdLim_DWork.UnitDelay_DSTATE;
      localqY = localq + locali;
      if ((localq > 0) && ((locali > 0) && (localqY <= 0))) {
        localqY = MAX_int32_T;
      }

      if (localqY <= 0) {
        KnkMgt_ctSuperKnkDetLdLim = 0U;
      } else if (localqY > 65535) {
        KnkMgt_ctSuperKnkDetLdLim = MAX_uint16_T;
      } else {
        KnkMgt_ctSuperKnkDetLdLim = (UInt16)localqY;
      }

      /* If: '<S30>/If' incorporates:
       *  ActionPort: '<S33>/Action Port'
       *  ActionPort: '<S34>/Action Port'
       *  Constant: '<S9>/KnkMgt_ctSuperKnkDetHiThd_C'
       *  Constant: '<S9>/KnkMgt_ctSuperKnkDetLoThd_C'
       *  RelationalOperator: '<S30>/Relational Operator'
       *  RelationalOperator: '<S30>/Relational Operator1'
       *  SubSystem: '<S30>/If Action Subsystem'
       *  SubSystem: '<S30>/If Action Subsystem1'
       */
      if (KnkMgt_ctSuperKnkDetLoThd_C >= KnkMgt_ctSuperKnkDetLdLim) {
        KnkLdLim_IfActionSubsystem(FALSE, &KnkMgt_bAcvTmpLdLimSuperKnkRaw);
      } else {
        if (KnkMgt_ctSuperKnkDetLdLim >= KnkMgt_ctSuperKnkDetHiThd_C) {
          KnkLdLim_IfActionSubsystem1(TRUE, &KnkMgt_bAcvTmpLdLimSuperKnkRaw);
        }
      }

      /* Update for UnitDelay: '<S31>/Unit Delay' */
      KnkLdLim_DWork.UnitDelay_DSTATE = KnkMgt_ctSuperKnkDetLdLim;
    }

    /* end of Outputs for SubSystem: '<S6>/F03_LoadLimSuperKnk' */

    /* Outputs for atomic SubSystem: '<S6>/F04_LoadLimCoord' */

    /* Logic: '<S10>/OU1' incorporates:
     *  Constant: '<S10>/KnkMgt_bLdLimAdvCor_knk_C'
     *  Logic: '<S10>/OU3'
     */
    localLogicalOperator = (KnkMgt_bAcvTmpLdLimKnkRaw ||
      (KnkMgt_bLdLimAdvCor_knk_C && KnkMgt_bLdLimKnkAdvCor));

    /* Logic: '<S10>/OU4' incorporates:
     *  Constant: '<S10>/KnkMgt_bLdLimAdvCor_superKnk_C'
     *  Logic: '<S10>/OU2'
     */
    KnkLdLim_B.OU4 = ((KnkMgt_bLdLimKnkAdvCor && KnkMgt_bLdLimAdvCor_superKnk_C)
                      || KnkMgt_bAcvTmpLdLimSuperKnkRaw);

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/KnkMgt_bLdLimStra_C'
     *  Logic: '<S10>/OU14'
     */
    if (KnkMgt_bLdLimStra_C) {
      KnkLdLim_B.Switch = localLogicalOperator;
    } else {
      KnkLdLim_B.Switch = ((localLogicalOperator) || KnkLdLim_B.OU4);
    }

    /* end of Outputs for SubSystem: '<S6>/F04_LoadLimCoord' */
    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(KnkMgt_bAcvTmpLdLimKnkReq, KnkLdLim_B.Switch);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(KnkMgt_bAcvTmpLdLimSuperKnkReq, KnkLdLim_B.OU4);
  }

  /* end of Outputs for SubSystem: '<S5>/F02_LoadLimCalc' */
}

/* Output and update for exported function: KnkTreat_EveBDC_LdLim */
void KnkTreat_EveBDC_LdLim(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_LoadLimCalc'
   *
   * Block requirements for '<S1>/F02_LoadLimCalc':
   *  1. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_001.01 ;
   *  2. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_002.01 ;
   *  3. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_003.01 ;
   *  4. SubSystem "F02_LoadLimCalc" !Trace_To : VEMS_E_11_01859_004.01 ;
   */
  KnkLdLim_F02_LoadLimCalc();
}

/* Output and update for function-call system: '<S1>/F01_Init' */
void KnkLdLim_F01_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(KnkMgt_bAcvTmpLdLimSuperKnkReq, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(KnkMgt_bAcvTmpLdLimKnkReq, FALSE);
}

/* Output and update for exported function: KnkTreat_EveRst_LdLim */
void KnkTreat_EveRst_LdLim(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Init'
   *
   * Block requirements for '<S1>/F01_Init':
   *  1. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_001.01 ;
   *  2. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_002.01 ;
   *  3. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_003.01 ;
   *  4. SubSystem "F01_Init" !Trace_To : VEMS_E_11_01859_004.01 ;
   */
  KnkLdLim_F01_Init();
}

/* Model initialize function */
void KnkLdLim_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    (void) memset(&KnkLdLim_B.VEMS_vidGET6[0], 96U,
                  6U*sizeof(UInt8));
    KnkLdLim_B.VEMS_vidGET3 = 96U;
    (void) memset(&KnkLdLim_B.VEMS_vidGET5[0], 96U,
                  6U*sizeof(UInt8));
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
}

#define KNKLDLIM_STOP_SEC_CODE
#include "KnkLdLim_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
