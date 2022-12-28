/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : InjCutOffMgr                                            */
/* !Description     : GESTION DE LA COUPURE DES INJECTEURS                    */
/*                                                                            */
/* !Module          : InjCutOffMgr                                            */
/*                                                                            */
/* !File            : InjCutOffMgr.c                                          */
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
/* !Reference       : PTS_DOC_5048292 / 04                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Mon Mar 25 22:22:41 2013                              */
/*   Model name       : InjCutOffMgr_AUTOCODE.mdl                             */
/*   Model version    : 1.271                                                 */
/*   Root subsystem   : /InjCutOffMgr                                         */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/INJCUTOFFMGR/InjCutOffMgr.$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "InjCutOffMgr.h"
#include "InjCutOffMgr_private.h"

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
#define INJCUTOFFMGR_START_SEC_VAR_UNSPECIFIED
#include "InjCutOffMgr_MemMap.h"

/* Block signals (auto storage) */
BlockIO_InjCutOffMgr InjCutOffMgr_B;

/* Block states (auto storage) */
D_Work_InjCutOffMgr InjCutOffMgr_DWork;

#define INJCUTOFFMGR_STOP_SEC_VAR_UNSPECIFIED
#include "InjCutOffMgr_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define INJCUTOFFMGR_START_SEC_CODE
#include "InjCutOffMgr_MemMap.h"

void InjCutOffMgr_ASYNC1(int controlPortIdx)
{
}

void InjCutOffMgr_ASYNC2(int controlPortIdx)
{
}

void InjCutOffMgr_ASYNC4(int controlPortIdx)
{
  InjC__Gestion_coupure_injection();
}

/* Output and update for function-call system: '<S1>/1_Gestion_coupure_injection' */
void InjC__Gestion_coupure_injection(void)
{
  Float32 localGear_engaged_InjSys_GearEg;
  Float32 localfractionTmp_0d;
  UInt32 localGear_engaged_InjSys_Gear_p;
  UInt8 localSwitch;
  Boolean localDataTypeConversion_c;
  Boolean localAssignment_a[6];
  UInt8 localSwitch3;
  UInt8 localSwitch1;
  UInt8 localSwitch2;
  Boolean localSelector4_j;
  Boolean localAssignment[4];
  Boolean localAssignment2_k[4];
  SInt32 locali;

  /* Outputs for enable SubSystem: '<S7>/Gestion_coupure_injection' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/INJCUTOFFMGR_u8Inhib'
   *  EnablePort: '<S9>/Enable'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  if (INJCUTOFFMGR_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET21 */
    VEMS_vidGET(Thr_bInhInjMngServo, InjCutOffMgr_B.VEMS_vidGET21);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET1 */
    VEMS_vidGET(Bvmp_fco_request, InjCutOffMgr_B.VEMS_vidGET1);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET5 */
    VEMS_vidGET(Disable_inj_for_anti_flood, InjCutOffMgr_B.VEMS_vidGET5);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET6 */
    VEMS_vidGET(Dml_auto_injection, InjCutOffMgr_B.VEMS_vidGET6);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET11 */
    VEMS_vidGET(Engine_running_state, InjCutOffMgr_B.VEMS_vidGET11);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET18 */
    VEMS_vidGET(Regime_moteur_32, InjCutOffMgr_B.VEMS_vidGET18);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET17 */
    VEMS_vidGET(OxC_bOxCHeatPhaReq, InjCutOffMgr_B.VEMS_vidGET17);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET2 */
    VEMS_vidGET(CoEs_bAcvInjCutOffSTTEs, InjCutOffMgr_B.VEMS_vidGET2);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET15 */
    VEMS_vidGET(InjSys_bInhInjCutOffPFuDcha, InjCutOffMgr_B.VEMS_vidGET15);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET22 */
    VEMS_vidGET(TqSys_bInjCutProtAC, InjCutOffMgr_B.VEMS_vidGET22);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET */
    VEMS_vidGET(AirSys_mAirEngCylReq_tqEng, InjCutOffMgr_B.VEMS_vidGET);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET8 */
    VEMS_vidGET(EngM_mAirEngCylMin, InjCutOffMgr_B.VEMS_vidGET8);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET4 */
    VEMS_vidGET(DfwCtl_bInhInjProtDfw, InjCutOffMgr_B.VEMS_vidGET4);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET19 */
    VEMS_vidGET(TPM_bInhInjCutOff, InjCutOffMgr_B.VEMS_vidGET19);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET3 */
    VEMS_vidGET(CoStrtRStrt_stStopCutReq, InjCutOffMgr_B.VEMS_vidGET3);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET7 */
    VEMS_vidGET(ESLim_bAcvFuCutOff, InjCutOffMgr_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET13 */
    VEMS_vidGET(Gear_engaged, InjCutOffMgr_B.VEMS_vidGET13);

    /* PreLookup: '<S12>/Prelookup' */
    localGear_engaged_InjSys_Gear_p = plook_u32u8f_lincp
      (InjCutOffMgr_B.VEMS_vidGET13, (&(InjSys_GearEgd_A[0])), 5U,
       &localGear_engaged_InjSys_GearEg, &InjCutOffMgr_DWork.Prelookup_DWORK1);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET24 */
    VEMS_vidGET(EOM_tiEngRunStrt, InjCutOffMgr_B.VEMS_vidGET24);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET25 */
    VEMS_vidGET(Ext_tCoStrtMes, InjCutOffMgr_B.VEMS_vidGET25);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET26 */
    VEMS_vidGET(CoPTSt_tCoMesRStrtSTT, InjCutOffMgr_B.VEMS_vidGET26);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET27 */
    VEMS_vidGET(CoPTSt_bRStrtSTT, InjCutOffMgr_B.VEMS_vidGET27);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET28 */
    VEMS_vidGET(CoCha_bASRSecuReq, InjCutOffMgr_B.VEMS_vidGET28);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET29 */
    VEMS_vidGET(CoCha_bTqReqASR, InjCutOffMgr_B.VEMS_vidGET29);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET30 */
    VEMS_vidGET(CoPt_bSIP, InjCutOffMgr_B.VEMS_vidGET30);

    /* Outputs for atomic SubSystem: '<S9>/F01_TotCutOff' */

    /* Outputs for atomic SubSystem: '<S10>/F01_ReqInhFuCutOff' */

    /* Interpolation_n-D: '<S15>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localGear_engaged_InjSys_GearEg;
    localfractionTmp_0d = intrp1d_iu8ff_u32f_l_s(localGear_engaged_InjSys_Gear_p,
      localfractionTmp_0d, (&(InjSys_bInhTWCTotCutOff_T[0])));

    /* Sum: '<S17>/Add2' incorporates:
     *  Constant: '<S17>/offset'
     *  Constant: '<S17>/offset1'
     *  Constant: '<S17>/one_on_slope'
     *  Product: '<S17>/Product4'
     *  Sum: '<S17>/Add1'
     */
    localfractionTmp_0d += 0.5F;

    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S17>/OutDTConv'
     */
    if (localfractionTmp_0d < 256.0F) {
      if (localfractionTmp_0d >= 0.0F) {
        localSwitch2 = (UInt8)localfractionTmp_0d;
      } else {
        localSwitch2 = 0U;
      }
    } else {
      localSwitch2 = MAX_uint8_T;
    }

    /* DataTypeConversion: '<S13>/Data Type Conversion4' */
    locali = InjCutOffMgr_B.VEMS_vidGET25 + 40;
    if (locali <= 0) {
      localSwitch = 0U;
    } else if (locali > 255) {
      localSwitch = MAX_uint8_T;
    } else {
      localSwitch = (UInt8)locali;
    }

    /* Switch: '<S13>/Switch' */
    if (InjCutOffMgr_B.VEMS_vidGET27) {
      localSwitch = InjCutOffMgr_B.VEMS_vidGET26;
    }

    /* Logic: '<S13>/OU3' incorporates:
     *  Constant: '<S13>/InjSys_mAirMinInhCutOff_C'
     *  DataTypeConversion: '<S13>/Data Type Conversion2'
     *  DataTypeConversion: '<S13>/Data Type Conversion3'
     *  DataTypeConversion: '<S13>/Data Type Conversion5'
     *  RelationalOperator: '<S13>/Relational Operator1'
     *  Sum: '<S13>/Sum'
     */
    InjCutOffMgr_B.OU3 = ((((((Float32)InjCutOffMgr_B.VEMS_vidGET) *
      1.192016583E-007F) - (((Float32)InjCutOffMgr_B.VEMS_vidGET8) *
      5.960464478E-008F)) <= (((Float32)InjSys_mAirMinInhCutOff_C) *
      2.384033166E-007F)) && InjCutOffMgr_B.VEMS_vidGET15);

    /* Logic: '<S13>/OU10' incorporates:
     *  Constant: '<S13>/ERUN_ENGINE_OVERRUN_FCO'
     *  Constant: '<S13>/InjCutOff_bAcvInjCutOffSTTEs_C'
     *  Logic: '<S13>/OU2'
     *  RelationalOperator: '<S13>/Relational Operator3'
     */
    InjSys_bInjCutOffRaw = ((InjCutOffMgr_B.VEMS_vidGET11 ==
      ERUN_ENGINE_OVERRUN_FCO) || (InjCutOffMgr_B.VEMS_vidGET2 &&
      InjCutOff_bAcvInjCutOffSTTEs_C));

    /* Logic: '<S13>/OU6' incorporates:
     *  Constant: '<S13>/InjSys_bAcvPrioProtAC_C'
     *  Constant: '<S13>/InjSys_bEnaTotCutASRSecu_C'
     *  Constant: '<S13>/InjSys_bEnaTotCutASR_C'
     *  Constant: '<S13>/InjSys_bEnaTotCutSIP_C'
     *  Logic: '<S13>/OU1'
     *  Logic: '<S13>/OU12'
     *  Logic: '<S13>/OU13'
     *  Logic: '<S13>/OU4'
     *  Logic: '<S13>/OU5'
     *  Logic: '<S13>/OU7'
     *  Logic: '<S13>/OU8'
     *  Logic: '<S13>/OU9'
     */
    InjSys_bAcvCutOff_MP = ((InjSys_bAcvPrioProtAC_C &&
      InjCutOffMgr_B.VEMS_vidGET22) || (!((InjCutOffMgr_B.OU3 ||
      ((((!(InjCutOffMgr_B.VEMS_vidGET28 && InjSys_bEnaTotCutASRSecu_C)) &&
         (!(InjCutOffMgr_B.VEMS_vidGET29 && InjSys_bEnaTotCutASR_C))) &&
        (!(InjCutOffMgr_B.VEMS_vidGET30 && InjSys_bEnaTotCutSIP_C))) &&
       InjCutOffMgr_B.VEMS_vidGET19)) || ((localSwitch2 != 0) &&
      InjCutOffMgr_B.VEMS_vidGET17))));

    /* Logic: '<S13>/OU11' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion1'
     *  Lookup_n-D: '<S16>/Lookup Table (n-D)'
     *  RelationalOperator: '<S13>/Relational Operator2'
     */
    InjSys_bAcvCutOffTyp1 = ((InjSys_bInjCutOffRaw && InjSys_bAcvCutOff_MP) &&
                             ((((Float32)InjCutOffMgr_B.VEMS_vidGET24) *
      9.999999776E-003F) >= look1_iu8lftu16n7If_binlcns(localSwitch,
      (&(InjSys_tCoMes_A[0])), (&(InjSys_tiDlyInjCutOff_T[0])), 8U)));

    /* end of Outputs for SubSystem: '<S10>/F01_ReqInhFuCutOff' */

    /* Outputs for atomic SubSystem: '<S10>/F02_ForcFuCutOff' */

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Fco_regul_rich_regime_thresh2'
     *  Logic: '<S14>/OU4'
     *  RelationalOperator: '<S14>/Relational Operator5'
     */
    if (InjCutOffMgr_B.VEMS_vidGET3 == 2) {
      localDataTypeConversion_c = InjCutOffMgr_B.VEMS_vidGET2;
    } else {
      localDataTypeConversion_c = !InjCutOffMgr_B.VEMS_vidGET6;
    }

    /* Logic: '<S14>/OU12' incorporates:
     *  Constant: '<S14>/Fco_regul_rich_regime_thresh'
     *  Constant: '<S14>/Fco_regul_rich_regime_thresh1'
     *  Constant: '<S14>/InjSys_bETBAcvTotCutOff_C'
     *  Inport: '<Root>/FRM_bForcCylCutOff'
     *  Logic: '<S14>/OU7'
     *  RelationalOperator: '<S14>/Relational Operator2'
     *  RelationalOperator: '<S14>/Relational Operator6'
     *  UnitDelay: '<S18>/Unit Delay'
     */
    InjSys_bForcFuCutOff = (((((((((GDGAR_bGetFRM(FRM_FRM_FORCCYLCUTOFF) ||
      InjCutOffMgr_B.VEMS_vidGET5) || InjSys_bETBAcvTotCutOff_C) ||
      InjCutOffMgr_B.VEMS_vidGET7) || InjCutOffMgr_B.VEMS_vidGET1) ||
      (localDataTypeConversion_c)) || InjCutOffMgr_B.VEMS_vidGET21) ||
      ((InjCutOffMgr_DWork.UnitDelay_DSTATE > 0) &&
       (InjCutOffMgr_B.VEMS_vidGET18 > Fco_regul_rich_regime_thresh))) ||
      InjCutOffMgr_B.VEMS_vidGET4) || InjSys_bTotCutOffDftMod);

    /* end of Outputs for SubSystem: '<S10>/F02_ForcFuCutOff' */

    /* Logic: '<S10>/OU12' */
    InjCutOffMgr_B.OU12 = (InjSys_bAcvCutOffTyp1 || InjSys_bForcFuCutOff);

    /* Logic: '<S10>/OU6' */
    InjCutOffMgr_B.OU6 = !InjCutOffMgr_B.OU12;

    /* end of Outputs for SubSystem: '<S9>/F01_TotCutOff' */
    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET20 */
    VEMS_vidGET(TPM_bInhInjSelCutOff, InjCutOffMgr_B.VEMS_vidGET20);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET14 */
    VEMS_vidGET(IgSys_noCylCutOffTar, InjCutOffMgr_B.VEMS_vidGET14);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET9 */
    VEMS_vidGET(Eng_noInNxtCyl, InjCutOffMgr_B.VEMS_vidGET9);

    /* DataTypeConversion Block: '<S31>/Data Type Conversion'
     *
     * Regarding '<S31>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET16 */
    VEMS_vidGET1DArray(KnkMgt_prm_bInjCutOffRblCyl, 4,
                       InjCutOffMgr_B.VEMS_vidGET16);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET12 */
    VEMS_vidGET(Ext_noCylEng, InjCutOffMgr_B.VEMS_vidGET12);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET10 */
    VEMS_vidGET(Eng_noInNxtNxtCyl, InjCutOffMgr_B.VEMS_vidGET10);

    /* S-Function "vems_vidGET" Block: <S9>/VEMS_vidGET23 */
    VEMS_vidGET(InjSys_noCylCutOff, InjCutOffMgr_B.VEMS_vidGET23);

    /* Outputs for atomic SubSystem: '<S9>/F02_CylCutOff' */

    /* Outputs for enable SubSystem: '<S11>/F01_Coupure_par_cylindre' incorporates:
     *  EnablePort: '<S19>/Auto_injection'
     */
    if (InjCutOffMgr_B.OU6) {
      /* UnitDelay: '<S28>/Unit Delay' */
      InjSys_prm_bAcvCutOffTarCylPrev[0] =
        InjCutOffMgr_DWork.UnitDelay_DSTATE_n[0];
      InjSys_prm_bAcvCutOffTarCylPrev[1] =
        InjCutOffMgr_DWork.UnitDelay_DSTATE_n[1];
      InjSys_prm_bAcvCutOffTarCylPrev[2] =
        InjCutOffMgr_DWork.UnitDelay_DSTATE_n[2];
      InjSys_prm_bAcvCutOffTarCylPrev[3] =
        InjCutOffMgr_DWork.UnitDelay_DSTATE_n[3];

      /* Outputs for atomic SubSystem: '<S19>/00_CylCutOffTar' */

      /* Sum: '<S21>/Sum' */
      locali = InjCutOffMgr_B.VEMS_vidGET14 - InjCutOffMgr_B.VEMS_vidGET23;
      if (locali > 127) {
        InjSys_noCylCutOffTarSub = MAX_int8_T;
      } else if (locali <= -128) {
        InjSys_noCylCutOffTarSub = MIN_int8_T;
      } else {
        InjSys_noCylCutOffTarSub = (SInt8)locali;
      }

      /* Lookup: '<S31>/Look-Up Table1'
       * About '<S31>/Look-Up Table1':
       * Input0  Data Type:  Integer        U8
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Nearest
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      {
        UInt32 iLeft;
        BINARYSEARCH_U8_Near_iL( &(iLeft), InjCutOffMgr_B.VEMS_vidGET9,
          (&(InjSys_noInNxtCyl_A[0])), 5U);
        InjSys_noInNxtNxtNxtCyl = InjSys_noInNxtNxtNxtCyl_T[iLeft];
      }

      /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate1'
       *
       * Regarding '<S31>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Outputs for enable SubSystem: '<S21>/1_SubPos' incorporates:
       *  Constant: '<S21>/ConstVal_1'
       *  EnablePort: '<S29>/Enable'
       *  RelationalOperator: '<S21>/Relational Operator'
       */
      if (InjSys_noCylCutOffTarSub > 0) {
        /* Selector: '<S29>/Selector2' */
        localDataTypeConversion_c =
          InjSys_prm_bAcvCutOffTarCylPrev[InjCutOffMgr_B.VEMS_vidGET9 - 1];

        /* Logic: '<S29>/OU4' incorporates:
         *  Selector: '<S29>/Selector1'
         */
        localSelector4_j =
          (InjSys_prm_bAcvCutOffTarCylPrev[InjCutOffMgr_B.VEMS_vidGET10 - 1] &&
           (localDataTypeConversion_c));

        /* Switch: '<S29>/Switch3' */
        if (localDataTypeConversion_c) {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET10;
        } else {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET9;
        }

        /* Switch: '<S29>/Switch4' */
        if (localSelector4_j) {
          localSwitch = InjSys_noInNxtNxtNxtCyl;
        }

        /* Assignment: '<S29>/Assignment' incorporates:
         *  Constant: '<S29>/ConstVal_3'
         *  RelationalOperator: '<S29>/Relational Operator5'
         */
        localAssignment[0] = InjSys_prm_bAcvCutOffTarCylPrev[0];
        localAssignment[1] = InjSys_prm_bAcvCutOffTarCylPrev[1];
        localAssignment[2] = InjSys_prm_bAcvCutOffTarCylPrev[2];
        localAssignment[3] = InjSys_prm_bAcvCutOffTarCylPrev[3];
        localAssignment[localSwitch - 1] = (InjSys_noCylCutOffTarSub >= 1);

        /* Switch: '<S29>/Switch8' incorporates:
         *  Constant: '<S29>/ConstMat'
         *  Logic: '<S29>/OU7'
         *  Logic: '<S29>/OU8'
         *  Selector: '<S29>/Selector3'
         */
        if (InjSys_prm_bAcvCutOffTarCylPrev[InjSys_noInNxtNxtNxtCyl - 1] &&
            (localSelector4_j)) {
          localAssignment[0] = TRUE;
          localAssignment[1] = TRUE;
          localAssignment[2] = TRUE;
          localAssignment[3] = TRUE;
        }

        /* Selector: '<S29>/Selector4' */
        localSelector4_j = localAssignment[InjCutOffMgr_B.VEMS_vidGET10 - 1];

        /* Switch: '<S29>/Switch5' */
        if (localSelector4_j) {
          localSwitch = InjSys_noInNxtNxtNxtCyl;
        } else {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET10;
        }

        /* Assignment: '<S29>/Assignment1' incorporates:
         *  Constant: '<S29>/ConstVal_2'
         */
        localAssignment2_k[0] = localAssignment[0];
        localAssignment2_k[1] = localAssignment[1];
        localAssignment2_k[2] = localAssignment[2];
        localAssignment2_k[3] = localAssignment[3];
        localAssignment2_k[localSwitch - 1] = TRUE;

        /* Switch: '<S29>/Switch6' incorporates:
         *  Constant: '<S29>/ConstMat_1'
         *  Logic: '<S29>/OU5'
         *  Selector: '<S29>/Selector'
         */
        if ((localAssignment[InjSys_noInNxtNxtNxtCyl - 1]) && (localSelector4_j))
        {
          localAssignment2_k[0] = TRUE;
          localAssignment2_k[1] = TRUE;
          localAssignment2_k[2] = TRUE;
          localAssignment2_k[3] = TRUE;
        }

        /* Switch: '<S29>/Switch1' incorporates:
         *  Constant: '<S29>/ConstVal'
         *  Logic: '<S29>/OU3'
         *  RelationalOperator: '<S29>/Relational Operator1'
         */
        if (InjSys_noCylCutOffTarSub >= 2) {
          localAssignment[0] = localAssignment2_k[0];
          localAssignment[1] = localAssignment2_k[1];
          localAssignment[2] = localAssignment2_k[2];
          localAssignment[3] = localAssignment2_k[3];
        }

        /* Assignment: '<S29>/Assignment2' incorporates:
         *  Constant: '<S29>/ConstVal_5'
         */
        localAssignment2_k[0] = localAssignment[0];
        localAssignment2_k[1] = localAssignment[1];
        localAssignment2_k[2] = localAssignment[2];
        localAssignment2_k[3] = localAssignment[3];
        localAssignment2_k[InjSys_noInNxtNxtNxtCyl - 1] = TRUE;

        /* Switch: '<S29>/Switch7' incorporates:
         *  Constant: '<S29>/ConstMat_3'
         *  Logic: '<S29>/OU6'
         *  Selector: '<S29>/Selector5'
         */
        if (localAssignment[InjSys_noInNxtNxtNxtCyl - 1]) {
          localAssignment2_k[0] = TRUE;
          localAssignment2_k[1] = TRUE;
          localAssignment2_k[2] = TRUE;
          localAssignment2_k[3] = TRUE;
        }

        /* Switch: '<S29>/Switch2' incorporates:
         *  Constant: '<S29>/ConstVal_4'
         *  Logic: '<S29>/OU2'
         *  RelationalOperator: '<S29>/Relational Operator4'
         */
        if (InjSys_noCylCutOffTarSub >= 3) {
          localAssignment[0] = localAssignment2_k[0];
          localAssignment[1] = localAssignment2_k[1];
          localAssignment[2] = localAssignment2_k[2];
          localAssignment[3] = localAssignment2_k[3];
        }

        /* Switch: '<S29>/Switch' incorporates:
         *  Constant: '<S29>/ConstMat_2'
         *  Constant: '<S29>/ConstVal_1'
         *  Logic: '<S29>/OU1'
         *  RelationalOperator: '<S29>/Relational Operator3'
         */
        if (InjSys_noCylCutOffTarSub == 4) {
          localAssignment[0] = TRUE;
          localAssignment[1] = TRUE;
          localAssignment[2] = TRUE;
          localAssignment[3] = TRUE;
        }

        /* SignalConversion: '<S29>/Signal Conversion5' */
        InjSys_prm_bAcvCutOffTarCyl[0] = localAssignment[0];
        InjSys_prm_bAcvCutOffTarCyl[1] = localAssignment[1];
        InjSys_prm_bAcvCutOffTarCyl[2] = localAssignment[2];
        InjSys_prm_bAcvCutOffTarCyl[3] = localAssignment[3];
      }

      /* end of Outputs for SubSystem: '<S21>/1_SubPos' */

      /* Outputs for enable SubSystem: '<S21>/2_SubNeg' incorporates:
       *  Constant: '<S21>/ConstVal'
       *  EnablePort: '<S30>/Enable'
       *  RelationalOperator: '<S21>/Relational Operator1'
       */
      if (InjSys_noCylCutOffTarSub < 0) {
        /* Selector: '<S30>/Selector1' */
        localDataTypeConversion_c =
          InjSys_prm_bAcvCutOffTarCylPrev[InjCutOffMgr_B.VEMS_vidGET9 - 1];

        /* Logic: '<S30>/OU4' incorporates:
         *  Selector: '<S30>/Selector'
         */
        localSelector4_j =
          !(InjSys_prm_bAcvCutOffTarCylPrev[InjCutOffMgr_B.VEMS_vidGET10 - 1] ||
            (localDataTypeConversion_c));

        /* Switch: '<S30>/Switch3' incorporates:
         *  Logic: '<S30>/OU9'
         */
        if (!localDataTypeConversion_c) {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET10;
        } else {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET9;
        }

        /* Switch: '<S30>/Switch4' */
        if (localSelector4_j) {
          localSwitch = InjSys_noInNxtNxtNxtCyl;
        }

        /* Assignment: '<S30>/Assignment3' incorporates:
         *  Constant: '<S30>/ConstVal_1'
         */
        localAssignment[0] = InjSys_prm_bAcvCutOffTarCylPrev[0];
        localAssignment[1] = InjSys_prm_bAcvCutOffTarCylPrev[1];
        localAssignment[2] = InjSys_prm_bAcvCutOffTarCylPrev[2];
        localAssignment[3] = InjSys_prm_bAcvCutOffTarCylPrev[3];
        localAssignment[localSwitch - 1] = FALSE;

        /* Switch: '<S30>/Switch8' incorporates:
         *  Constant: '<S30>/ConstMat'
         *  Logic: '<S30>/OU10'
         *  Logic: '<S30>/OU7'
         *  Logic: '<S30>/OU8'
         *  Selector: '<S30>/Selector2'
         */
        if ((!InjSys_prm_bAcvCutOffTarCylPrev[InjSys_noInNxtNxtNxtCyl - 1]) &&
            (localSelector4_j)) {
          localAssignment[0] = FALSE;
          localAssignment[1] = FALSE;
          localAssignment[2] = FALSE;
          localAssignment[3] = FALSE;
        }

        /* Selector: '<S30>/Selector4' */
        localSelector4_j = localAssignment[InjCutOffMgr_B.VEMS_vidGET10 - 1];

        /* Switch: '<S30>/Switch5' incorporates:
         *  Logic: '<S30>/OU5'
         */
        if (!localSelector4_j) {
          localSwitch = InjSys_noInNxtNxtNxtCyl;
        } else {
          localSwitch = InjCutOffMgr_B.VEMS_vidGET10;
        }

        /* Assignment: '<S30>/Assignment1' incorporates:
         *  Constant: '<S30>/ConstVal_3'
         */
        localAssignment2_k[0] = localAssignment[0];
        localAssignment2_k[1] = localAssignment[1];
        localAssignment2_k[2] = localAssignment[2];
        localAssignment2_k[3] = localAssignment[3];
        localAssignment2_k[localSwitch - 1] = FALSE;

        /* Switch: '<S30>/Switch6' incorporates:
         *  Constant: '<S30>/ConstMat_1'
         *  Logic: '<S30>/OU11'
         *  Selector: '<S30>/Selector3'
         */
        if (!((localAssignment[InjSys_noInNxtNxtNxtCyl - 1]) ||
              (localSelector4_j))) {
          localAssignment2_k[0] = FALSE;
          localAssignment2_k[1] = FALSE;
          localAssignment2_k[2] = FALSE;
          localAssignment2_k[3] = FALSE;
        }

        /* Switch: '<S30>/Switch1' incorporates:
         *  Constant: '<S30>/ConstVal'
         *  Logic: '<S30>/OU3'
         *  RelationalOperator: '<S30>/Relational Operator1'
         */
        if (InjSys_noCylCutOffTarSub <= -2) {
          localAssignment[0] = localAssignment2_k[0];
          localAssignment[1] = localAssignment2_k[1];
          localAssignment[2] = localAssignment2_k[2];
          localAssignment[3] = localAssignment2_k[3];
        }

        /* Assignment: '<S30>/Assignment2' incorporates:
         *  Constant: '<S30>/ConstVal_5'
         */
        localAssignment2_k[0] = localAssignment[0];
        localAssignment2_k[1] = localAssignment[1];
        localAssignment2_k[2] = localAssignment[2];
        localAssignment2_k[3] = localAssignment[3];
        localAssignment2_k[InjSys_noInNxtNxtNxtCyl - 1] = FALSE;

        /* Switch: '<S30>/Switch7' incorporates:
         *  Constant: '<S30>/ConstMat_3'
         *  Selector: '<S30>/Selector5'
         */
        if (!localAssignment[InjSys_noInNxtNxtNxtCyl - 1]) {
          localAssignment2_k[0] = FALSE;
          localAssignment2_k[1] = FALSE;
          localAssignment2_k[2] = FALSE;
          localAssignment2_k[3] = FALSE;
        }

        /* Switch: '<S30>/Switch2' incorporates:
         *  Constant: '<S30>/ConstVal_4'
         *  Logic: '<S30>/OU2'
         *  RelationalOperator: '<S30>/Relational Operator4'
         */
        if (InjSys_noCylCutOffTarSub <= -3) {
          localAssignment[0] = localAssignment2_k[0];
          localAssignment[1] = localAssignment2_k[1];
          localAssignment[2] = localAssignment2_k[2];
          localAssignment[3] = localAssignment2_k[3];
        }

        /* Switch: '<S30>/Switch' incorporates:
         *  Constant: '<S30>/ConstMat_2'
         *  Constant: '<S30>/ConstVal_2'
         *  Logic: '<S30>/OU1'
         *  RelationalOperator: '<S30>/Relational Operator3'
         */
        if (InjSys_noCylCutOffTarSub == -4) {
          localAssignment[0] = FALSE;
          localAssignment[1] = FALSE;
          localAssignment[2] = FALSE;
          localAssignment[3] = FALSE;
        }

        /* SignalConversion: '<S30>/Signal Conversion5' */
        InjSys_prm_bAcvCutOffTarCyl[0] = localAssignment[0];
        InjSys_prm_bAcvCutOffTarCyl[1] = localAssignment[1];
        InjSys_prm_bAcvCutOffTarCyl[2] = localAssignment[2];
        InjSys_prm_bAcvCutOffTarCyl[3] = localAssignment[3];
      }

      /* end of Outputs for SubSystem: '<S21>/2_SubNeg' */

      /* end of Outputs for SubSystem: '<S19>/00_CylCutOffTar' */

      /* Interpolation_n-D: '<S26>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localGear_engaged_InjSys_GearEg;
      localfractionTmp_0d = intrp1d_iu8ff_u32f_l_s
        (localGear_engaged_InjSys_Gear_p, localfractionTmp_0d,
         (&(InjSys_bInhCylCutOff_T[0])));

      /* Sum: '<S27>/Add2' incorporates:
       *  Constant: '<S27>/offset'
       *  Constant: '<S27>/offset1'
       *  Constant: '<S27>/one_on_slope'
       *  Product: '<S27>/Product4'
       *  Sum: '<S27>/Add1'
       */
      localfractionTmp_0d += 0.5F;

      /* Logic: '<S19>/OU2' incorporates:
       *  Constant: '<S19>/InjSys_bEnaSelCutASRSecu_C'
       *  Constant: '<S19>/InjSys_bEnaSelCutASR_C'
       *  Constant: '<S19>/InjSys_bEnaSelCutSIP_C'
       *  DataTypeConversion: '<S19>/Data Type Conversion'
       *  DataTypeConversion: '<S27>/OutDTConv'
       *  Logic: '<S19>/OU12'
       *  Logic: '<S19>/OU13'
       *  Logic: '<S19>/OU3'
       *  Logic: '<S19>/OU5'
       *  Logic: '<S19>/OU9'
       */
      if (localfractionTmp_0d < 256.0F) {
        if (localfractionTmp_0d >= 0.0F) {
          localSwitch2 = (UInt8)localfractionTmp_0d;
        } else {
          localSwitch2 = 0U;
        }
      } else {
        localSwitch2 = MAX_uint8_T;
      }

      InjSys_bInhCutOffTar = (((localSwitch2 != 0) &&
        InjCutOffMgr_B.VEMS_vidGET17) || (((InjCutOffMgr_B.VEMS_vidGET20 &&
        (!(InjCutOffMgr_B.VEMS_vidGET28 && InjSys_bEnaSelCutASRSecu_C))) &&
        (!(InjCutOffMgr_B.VEMS_vidGET29 && InjSys_bEnaSelCutASR_C))) &&
        (!(InjCutOffMgr_B.VEMS_vidGET30 && InjSys_bEnaSelCutSIP_C))));

      /* Outputs for atomic SubSystem: '<S19>/0_Cylindre_1' */

      /* Logic: '<S22>/OU2' incorporates:
       *  Constant: '<S22>/ConstVal_1'
       *  Logic: '<S22>/OU1'
       *  Selector: '<S22>/Selector1'
       */
      InjSys_bCutOffCyl1Raw = (InjSys_prm_bAcvCutOffTarCyl[0] &&
        (!InjSys_bInhCutOffTar));

      /* Logic: '<S22>/OU3' incorporates:
       *  Constant: '<S22>/ConstVal'
       *  Inport: '<Root>/FRM_bAcvInjCutOffCyl1'
       *  Selector: '<S22>/Selector'
       */
      Coupure_decel_progr_inj_cyl1 = ((InjSys_bCutOffCyl1Raw || GDGAR_bGetFRM
        (FRM_FRM_ACVINJCUTOFFCYL1)) || InjCutOffMgr_B.VEMS_vidGET16[0]);

      /* end of Outputs for SubSystem: '<S19>/0_Cylindre_1' */

      /* Outputs for atomic SubSystem: '<S19>/1_Cylindre_2' */

      /* Logic: '<S23>/OU2' incorporates:
       *  Constant: '<S23>/ConstVal_1'
       *  Logic: '<S23>/OU1'
       *  Selector: '<S23>/Selector1'
       */
      InjSys_bCutOffCyl2Raw = (InjSys_prm_bAcvCutOffTarCyl[1] &&
        (!InjSys_bInhCutOffTar));

      /* Logic: '<S23>/OU3' incorporates:
       *  Constant: '<S23>/ConstVal'
       *  Inport: '<Root>/FRM_bAcvInjCutOffCyl2'
       *  Selector: '<S23>/Selector'
       */
      Coupure_decel_progr_inj_cyl2 = ((InjSys_bCutOffCyl2Raw || GDGAR_bGetFRM
        (FRM_FRM_ACVINJCUTOFFCYL2)) || InjCutOffMgr_B.VEMS_vidGET16[1]);

      /* end of Outputs for SubSystem: '<S19>/1_Cylindre_2' */

      /* Outputs for atomic SubSystem: '<S19>/2_Cylindre_3' */

      /* Logic: '<S24>/OU2' incorporates:
       *  Constant: '<S24>/ConstVal_1'
       *  Logic: '<S24>/OU1'
       *  Selector: '<S24>/Selector1'
       */
      InjSys_bCutOffCyl3Raw = (InjSys_prm_bAcvCutOffTarCyl[2] &&
        (!InjSys_bInhCutOffTar));

      /* Logic: '<S24>/OU3' incorporates:
       *  Constant: '<S24>/ConstVal'
       *  Inport: '<Root>/FRM_bAcvInjCutOffCyl3'
       *  Selector: '<S24>/Selector'
       */
      Coupure_decel_progr_inj_cyl3 = ((InjSys_bCutOffCyl3Raw || GDGAR_bGetFRM
        (FRM_FRM_ACVINJCUTOFFCYL3)) || InjCutOffMgr_B.VEMS_vidGET16[2]);

      /* end of Outputs for SubSystem: '<S19>/2_Cylindre_3' */

      /* RelationalOperator: '<S19>/Relational Operator5' incorporates:
       *  Constant: '<S19>/ConstVal'
       */
      localDataTypeConversion_c = (InjCutOffMgr_B.VEMS_vidGET12 == 4);

      /* Outputs for enable SubSystem: '<S19>/3_Cylindre_4' incorporates:
       *  EnablePort: '<S25>/Enable'
       */
      if (localDataTypeConversion_c) {
        /* Logic: '<S25>/OU2' incorporates:
         *  Constant: '<S25>/ConstVal_1'
         *  Logic: '<S25>/OU1'
         *  Selector: '<S25>/Selector1'
         */
        InjSys_bCutOffCyl4Raw = (InjSys_prm_bAcvCutOffTarCyl[3] &&
          (!InjSys_bInhCutOffTar));

        /* Logic: '<S25>/OU5' incorporates:
         *  Constant: '<S25>/ConstVal'
         *  Inport: '<Root>/FRM_bAcvInjCutOffCyl4'
         *  Selector: '<S25>/Selector'
         */
        InjCutOffMgr_B.OU5 = ((InjSys_bCutOffCyl4Raw || GDGAR_bGetFRM
          (FRM_FRM_ACVINJCUTOFFCYL4)) || InjCutOffMgr_B.VEMS_vidGET16[3]);
      }

      /* end of Outputs for SubSystem: '<S19>/3_Cylindre_4' */

      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S19>/ConstVal_1'
       *  Logic: '<S19>/OU1'
       */
      if (!localDataTypeConversion_c) {
        Coupure_decel_progr_inj_cyl4 = FALSE;
      } else {
        Coupure_decel_progr_inj_cyl4 = InjCutOffMgr_B.OU5;
      }

      /* SignalConversion: '<S19>/Signal Conversion5' incorporates:
       *  Inport: '<Root>/FRM_bAcvInjCutOffDmgCat'
       */
      InjCutOffMgr_B.SignalConversion5 = GDGAR_bGetFRM
        (FRM_FRM_ACVINJCUTOFFDMGCAT);

      /* Update for UnitDelay: '<S28>/Unit Delay' */
      InjCutOffMgr_DWork.UnitDelay_DSTATE_n[0] = InjSys_prm_bAcvCutOffTarCyl[0];
      InjCutOffMgr_DWork.UnitDelay_DSTATE_n[1] = InjSys_prm_bAcvCutOffTarCyl[1];
      InjCutOffMgr_DWork.UnitDelay_DSTATE_n[2] = InjSys_prm_bAcvCutOffTarCyl[2];
      InjCutOffMgr_DWork.UnitDelay_DSTATE_n[3] = InjSys_prm_bAcvCutOffTarCyl[3];
    }

    /* end of Outputs for SubSystem: '<S11>/F01_Coupure_par_cylindre' */

    /* Outputs for atomic SubSystem: '<S11>/F02_FuelCutOffMgr' */

    /* UnitDelay: '<S32>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      localAssignment_a[locali] = InjCutOffMgr_DWork.UnitDelay_DSTATE_p[(locali)];
    }

    /* Assignment: '<S20>/Assignment' incorporates:
     *  Constant: '<S20>/1'
     */
    localAssignment_a[InjCutOffMgr_B.VEMS_vidGET9 - 1] = TRUE;

    /* Logic: '<S20>/Logical Operator3' */
    InjCutOffMgr_B.LogicalOperator3 = (Coupure_decel_progr_inj_cyl2 ||
      InjCutOffMgr_B.OU12);

    /* Logic: '<S20>/Logical Operator5' */
    InjCutOffMgr_B.LogicalOperator5 = (Coupure_decel_progr_inj_cyl3 ||
      InjCutOffMgr_B.OU12);

    /* Logic: '<S20>/Logical Operator7' */
    InjCutOffMgr_B.LogicalOperator7 = (Coupure_decel_progr_inj_cyl4 ||
      InjCutOffMgr_B.OU12);

    /* Logic: '<S20>/Logical Operator8' */
    InjCutOffMgr_B.LogicalOperator8 = (Coupure_decel_progr_inj_cyl1 ||
      InjCutOffMgr_B.OU12);

    /* Sum: '<S20>/Sum' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     *  DataTypeConversion: '<S20>/Data Type Conversion2'
     *  DataTypeConversion: '<S20>/Data Type Conversion3'
     */
    InjCutOffMgr_B.Sum = (UInt8)(((((SInt32)Coupure_decel_progr_inj_cyl1) +
                                     ((SInt32)Coupure_decel_progr_inj_cyl2)) +
                                    ((SInt32)Coupure_decel_progr_inj_cyl3)) +
                                   ((SInt32)Coupure_decel_progr_inj_cyl4));

    /* Switch: '<S20>/Switch5' incorporates:
     *  Constant: '<S20>/2'
     *  Constant: '<S20>/4'
     */
    if (Coupure_decel_progr_inj_cyl1) {
      localSwitch = 1U;
    } else {
      localSwitch = 0U;
    }

    /* Switch: '<S20>/Switch2' incorporates:
     *  Constant: '<S20>/2'
     *  Constant: '<S20>/5'
     */
    if (Coupure_decel_progr_inj_cyl2) {
      localSwitch2 = 2U;
    } else {
      localSwitch2 = 0U;
    }

    /* Switch: '<S20>/Switch1' incorporates:
     *  Constant: '<S20>/2'
     *  Constant: '<S20>/6'
     */
    if (Coupure_decel_progr_inj_cyl3) {
      localSwitch1 = 4U;
    } else {
      localSwitch1 = 0U;
    }

    /* Switch: '<S20>/Switch3' incorporates:
     *  Constant: '<S20>/2'
     *  Constant: '<S20>/7'
     */
    if (Coupure_decel_progr_inj_cyl4) {
      localSwitch3 = 8U;
    } else {
      localSwitch3 = 0U;
    }

    /* Sum: '<S20>/Sum1' */
    InjCutOffMgr_B.Sum1 = (UInt8)(((localSwitch + localSwitch2) + localSwitch1)
      + localSwitch3);

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/3'
     */
    if (InjCutOffMgr_B.OU12) {
      for (locali = 0; locali < 6; locali++) {
        InjCutOffMgr_B.Switch[(locali)] = localAssignment_a[locali];
      }
    } else {
      InjCutOffMgr_B.Switch[0] = Coupure_decel_progr_inj_cyl1;
      InjCutOffMgr_B.Switch[1] = Coupure_decel_progr_inj_cyl2;
      InjCutOffMgr_B.Switch[2] = Coupure_decel_progr_inj_cyl3;
      InjCutOffMgr_B.Switch[3] = Coupure_decel_progr_inj_cyl4;
      InjCutOffMgr_B.Switch[4] = FALSE;
      InjCutOffMgr_B.Switch[5] = FALSE;
    }

    /* Update for UnitDelay: '<S32>/Unit Delay' */
    for (locali = 0; locali < 6; locali++) {
      InjCutOffMgr_DWork.UnitDelay_DSTATE_p[(locali)] = InjCutOffMgr_B.Switch
        [(locali)];
    }

    /* end of Outputs for SubSystem: '<S11>/F02_FuelCutOffMgr' */

    /* end of Outputs for SubSystem: '<S9>/F02_CylCutOff' */
    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET */
    VEMS_vidSET(Auto_injection, InjCutOffMgr_B.OU6);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET1 */
    VEMS_vidSET(Coupure_decel_progr_inj, InjCutOffMgr_B.Sum1);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET10 */
    VEMS_vidSET1DArray(InjSys_prm_bCylCutOff, 6, InjCutOffMgr_B.Switch);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET11 */
    VEMS_vidSET(InjSys_bInhCutOffAirMin, InjCutOffMgr_B.OU3);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET2 */
    VEMS_vidSET(Coupure_inj_ess_1, InjCutOffMgr_B.LogicalOperator8);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET3 */
    VEMS_vidSET(Coupure_inj_ess_2, InjCutOffMgr_B.LogicalOperator3);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET4 */
    VEMS_vidSET(Coupure_inj_ess_3, InjCutOffMgr_B.LogicalOperator5);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET5 */
    VEMS_vidSET(Coupure_inj_ess_4, InjCutOffMgr_B.LogicalOperator7);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET6 */
    VEMS_vidSET(Fco_for_mf_cat_dam_actif, InjCutOffMgr_B.SignalConversion5);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET7 */
    VEMS_vidSET(InjSys_bFuCutOff, InjCutOffMgr_B.OU12);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET8 */
    VEMS_vidSET(InjSys_bTotCutOff, InjCutOffMgr_B.OU12);

    /* S-Function "vems_vidSET" Block: <S9>/VEMS_vidSET9 */
    VEMS_vidSET(InjSys_noCylCutOff, InjCutOffMgr_B.Sum);

    /* Update for atomic SubSystem: '<S9>/F01_TotCutOff' */

    /* Update for atomic SubSystem: '<S10>/F02_ForcFuCutOff' */

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    InjCutOffMgr_DWork.UnitDelay_DSTATE = InjCutOffMgr_B.Sum1;

    /* end of Update for SubSystem: '<S10>/F02_ForcFuCutOff' */

    /* end of Update for SubSystem: '<S9>/F01_TotCutOff' */
  }

  /* end of Outputs for SubSystem: '<S7>/Gestion_coupure_injection' */
}

/* Output and update for exported function: InjCutOff_EveInj_CutOff */
void InjCutOff_EveInj_CutOff(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' */
  InjCutOffMgr_ASYNC4(1);
}

/* Output and update for function-call system: '<S1>/0_Initialisation' */
void InjCutOffMgr__Initialisation(void)
{
  /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
  VEMS_vidGET(Thr_bInhInjMngServo, InjCutOffMgr_B.VEMS_vidGET_k);

  /* Logic: '<S6>/OU1' */
  InjCutOffMgr_B.OU1 = !InjCutOffMgr_B.VEMS_vidGET_k;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtVEMS_vidSET10Inport1' incorporates:
   *  Constant: '<S6>/3'
   */
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[0] = InjCutOffMgr_B.OU1;
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[1] = InjCutOffMgr_B.OU1;
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[2] = InjCutOffMgr_B.OU1;
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[3] = InjCutOffMgr_B.OU1;
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[4] = FALSE;
  InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE[5] = FALSE;

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
  VEMS_vidSET(Auto_injection, InjCutOffMgr_B.OU1);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET10 */
  VEMS_vidSET1DArray(InjSys_prm_bCylCutOff, 6,
                     InjCutOffMgr_B.TmpSignalConversionAtVEMS_vidSE);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
  VEMS_vidSET(Coupure_inj_ess_1, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET3 */
  VEMS_vidSET(Coupure_inj_ess_2, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET4 */
  VEMS_vidSET(Coupure_inj_ess_3, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET5 */
  VEMS_vidSET(Coupure_inj_ess_4, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET7 */
  VEMS_vidSET(InjSys_bFuCutOff, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET8 */
  VEMS_vidSET(InjSys_bTotCutOff, InjCutOffMgr_B.VEMS_vidGET_k);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
  VEMS_vidSET(Coupure_decel_progr_inj, ((UInt8)0U));

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET6 */
  VEMS_vidSET(Fco_for_mf_cat_dam_actif, FALSE);

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET9 */
  VEMS_vidSET(InjSys_noCylCutOff, ((UInt8)0U));

  /* SignalConversion: '<S6>/Signal Conversion9' incorporates:
   *  Constant: '<S6>/5'
   */
  InjSys_bTotCutOffDftMod = FALSE;

  /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET11 */
  VEMS_vidSET(InjSys_bInhCutOffAirMin, FALSE);
}

/* Output and update for exported function: InjCutOff_EveRst_CutOff */
void InjCutOff_EveRst_CutOff(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/0_Initialisation'
   */
  InjCutOffMgr__Initialisation();
}

/* Output and update for exported function: InjCutOff_SdlFast_CutOff */
void InjCutOff_SdlFast_CutOff(void)
{
  /* S-Function (fcncallgen): '<S4>/expFcn' */
  InjCutOffMgr_ASYNC4(0);
}

/* Output and update for function-call system: '<S1>/2_InjCutOffMgrDftMod' */
void InjCutOffMg__InjCutOffMgrDftMod(void)
{
  /* Outputs for enable SubSystem: '<S8>/2_InjCutOffMgrDftMod' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/INJCUTOFFMGR_u8Inhib'
   *  EnablePort: '<S33>/Enable'
   *  RelationalOperator: '<S8>/Relational Operator'
   */
  if (INJCUTOFFMGR_u8Inhib != 90) {
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/ERUN_ENGINE_OVERRUN_FCO1'
     *  Constant: '<S33>/ERUN_ENGINE_OVERRUN_FCO2'
     *  Inport: '<Root>/FRM_bInhRStrtDftStuckInjr'
     */
    if (GDGAR_bGetFRM(FRM_FRM_INHRSTRTDFTSTUCKINJR)) {
      InjSys_bTotCutOffDftMod = TRUE;
    } else {
      InjSys_bTotCutOffDftMod = FALSE;
    }
  }

  /* end of Outputs for SubSystem: '<S8>/2_InjCutOffMgrDftMod' */
}

/* Output and update for exported function: InjCutOff_EveStTCr_CutOff */
void InjCutOff_EveStTCr_CutOff(void)
{
  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/2_InjCutOffMgrDftMod'
   */
  InjCutOffMg__InjCutOffMgrDftMod();
}

/* Model initialize function */
void InjCutOffMgr_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    InjCutOffMgr_B.VEMS_vidGET26 = 40U;
  }

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   */
}

#define INJCUTOFFMGR_STOP_SEC_CODE
#include "InjCutOffMgr_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
