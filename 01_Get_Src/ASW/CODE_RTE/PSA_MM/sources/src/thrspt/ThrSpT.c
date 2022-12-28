/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : ThrSpT                                                  */
/* !Description     : ThrSpT Software Component                               */
/*                                                                            */
/* !Module          : ThrSpT                                                  */
/* !Description     : ThrSpT Software Component                               */
/*                                                                            */
/* !File            : ThrSpT.c                                                */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : ThrSpT_AUTOSAR.mdl                                    */
/*   Root subsystem   : /ThrSpT                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M09-ThrSpT/5-SOF$*/
/* $Revision::   1.5                                                         $*/
/* $Author::   plchinaz                               $$Date::   03 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "ThrSpT.h"
#include "ThrSpT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define ThrSpT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_ThrSpT ThrSpT_B;

/* Block states (auto storage) */
D_Work_ThrSpT ThrSpT_DWork;

#define ThrSpT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "ThrSpT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define THRSPT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define THRSPT_VEMSRTLIBT_MINOR_VERSION_REQ 12
#define THRSPT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define THRSPT_VEMSRTLIBT_VERSION_REQ (THRSPT_VEMSRTLIBT_PATCH_VERSION_REQ + THRSPT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + THRSPT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if THRSPT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define ThrSpT_START_SEC_CODE
#include "ThrSpT_MemMap.h"

void ThrSpT_ASYNC1(int controlPortIdx)
{
}

void ThrSpT_ASYNC2(int controlPortIdx)
{
}

void ThrSpT_ASYNC3(int controlPortIdx)
{
}

/* Start for exported function: RE_ThrSpT_003_TEV */
void RE_ThrSpT_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Thr_adpt'
   *
   * Block requirements for '<S1>/F01_Thr_adpt':
   *  1. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_007.01 ;
   *  2. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_006.01 ;
   *  3. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_028.01 ;
   *  4. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_020.01 ;
   *  5. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_021.01 ;
   *  6. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_022.01 ;
   *  7. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_023.01 ;
   *  8. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_024.01 ;
   *  9. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_025.01 ;
   */
}

/* Output and update for exported function: RE_ThrSpT_003_TEV */
void RE_ThrSpT_003_TEV(void)
{
  /* local block i/o variables */
  Boolean localAutosarServer;
  Boolean localNot;
  Boolean localTmpSignalConversionAtAir_k;
  Boolean localTmpSignalConversionAtVeh_b;
  Boolean localTmpSignalConversionAtIdlSy;
  UInt32 localTmpSignalConversionAtAirSy;
  SInt32 localConversion;
  SInt32 localSwitch;
  UInt16 localrtmax;
  SInt32 localq;
  SInt32 localqY;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Thr_adpt'
   *
   * Block requirements for '<S1>/F01_Thr_adpt':
   *  1. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_007.01 ;
   *  2. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_006.01 ;
   *  3. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_028.01 ;
   *  4. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_020.01 ;
   *  5. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_021.01 ;
   *  6. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_022.01 ;
   *  7. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_023.01 ;
   *  8. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_024.01 ;
   *  9. SubSystem "F01_Thr_adpt" !Trace_To : VEMS_R_10_06996_025.01 ;
   */

  /* S-Function (sfun_autosar_clientop): '<S23>/AutosarServer' */
  Rte_Call_R_FRM_bInhSpdAdpThr_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S23>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtIdlSys_bAcvIdlCtlOutport2' incorporates:
   *  Inport: '<Root>/IdlSys_bAcvIdlCtl'
   */
  Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl
    (&localTmpSignalConversionAtIdlSy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtVeh_bRunVehOutport2' incorporates:
   *  Inport: '<Root>/Veh_bRunVeh'
   */
  Rte_Read_R_Veh_bRunVeh_Veh_bRunVeh(&localTmpSignalConversionAtVeh_b);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_bInhPiAirEngCorOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bInhPiAirEngCor'
   */
  Rte_Read_R_AirSys_bInhPiAirEngCor_AirSys_bInhPiAirEngCor
    (&localTmpSignalConversionAtAir_k);

  /* Outputs for atomic SubSystem: '<S7>/F01_01_Cond_adapt' *
   * Block requirements for '<S7>/F01_01_Cond_adapt':
   *  1. SubSystem "F01_01_Cond_adapt" !Trace_To : VEMS_R_10_06996_008.01 ;
   */

  /* Switch: '<S20>/Switch9' incorporates:
   *  Constant: '<S20>/Constant19'
   *  Logic: '<S20>/Logical Operator10'
   *  Logic: '<S20>/Logical Operator8'
   *  Logic: '<S20>/Logical Operator9'
   */
  if (localNot) {
    ThrSys_bAcvSpdAdpThr = FALSE;
  } else {
    ThrSys_bAcvSpdAdpThr = (((localTmpSignalConversionAtIdlSy) &&
      (!localTmpSignalConversionAtVeh_b)) && (!localTmpSignalConversionAtAir_k));
  }

  /* end of Outputs for SubSystem: '<S7>/F01_01_Cond_adapt' */

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_mAirEngIntCorOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mAirEngIntCor'
   */
  Rte_Read_R_AirSys_mAirEngIntCor_AirSys_mAirEngIntCor
    (&localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtThrSys_arSpdAdpThrPrevOutport2' */
  ThrSpT_B.TmpSignalConversionAtThrSys_arS =
    Rte_IrvRead_RE_ThrSpT_003_TEV_ThrSys_arSpdAdpThr_irv();

  /* Outputs for enable SubSystem: '<S7>/F01_02_Adaptation_papillon' incorporates:
   *  EnablePort: '<S21>/ThrSys_bInhAdpThr'
   *  EnablePort: '<S22>/ThrSys_bInhAdpThr'
   *  Logic: '<S7>/Logical Operator'
   *  SubSystem: '<S7>/F01_02_Adaptation_papillon_else'
   *
   * Block requirements for '<S7>/F01_02_Adaptation_papillon':
   *  1. SubSystem "F01_02_Adaptation_papillon" !Trace_To : VEMS_R_10_06996_009.01 ;
   *
   * Block requirements for '<S7>/F01_02_Adaptation_papillon_else':
   *  1. SubSystem "F01_02_Adaptation_papillon" !Trace_To : VEMS_R_10_06996_009.01 ;
   */
  if (!localNot) {
    /* UnitDelay: '<S26>/Unit Delay' */
    ThrSys_tiStabSign_mIntPrev = ThrSpT_DWork.UnitDelay_DSTATE_a;

    /* UnitDelay: '<S27>/Unit Delay' */
    ThrSys_bAdpThrSign_mIntPrev = ThrSpT_DWork.UnitDelay_DSTATE_o;

    /* If: '<S21>/If1' incorporates:
     *  ActionPort: '<S24>/Action Port'
     *  ActionPort: '<S25>/Action Port'
     *  SubSystem: '<S21>/F01_02_01_Init_adapt'
     *  SubSystem: '<S21>/F01_02_02_Run_adapt'
     *
     * Block requirements for '<S21>/F01_02_01_Init_adapt':
     *  1. SubSystem "F01_02_01_Init_adapt" !Trace_To : VEMS_R_10_06996_010.01 ;
     *
     * Block requirements for '<S21>/F01_02_02_Run_adapt':
     *  1. SubSystem "F01_02_02_Run_adapt" !Trace_To : VEMS_R_10_06996_011.02 ;
     *  2. SubSystem "F01_02_02_Run_adapt" !Trace_To : VEMS_R_10_06996_029.01 ;
     */
    if (!ThrSys_bAcvSpdAdpThr) {
      /* Constant: '<S24>/Constant' */
      ThrSys_bAdpThrSign_mAirInt = TRUE;

      /* SignalConversion: '<S24>/Signal Conversion' incorporates:
       *  Constant: '<S24>/ThrSys_tiDlyStabSign_mAirInt_C'
       */
      ThrSys_tiStabSign_mAirInt = ThrSys_tiDlyStabSign_mAirInt_C;

      /* SignalConversion: '<S24>/Signal Conversion1' */
      ThrSpT_B.Merge2 = ThrSpT_B.TmpSignalConversionAtThrSys_arS;
    } else {
      /* Outputs for atomic SubSystem: '<S25>/F01_02_02_01_Calcul_du_signe' *
       * Block requirements for '<S25>/F01_02_02_01_Calcul_du_signe':
       *  1. SubSystem "F01_02_02_01_Calcul_du_signe" !Trace_To : VEMS_R_10_06996_012.01 ;
       */

      /* MinMax: '<S28>/MinMax' incorporates:
       *  Constant: '<S28>/Constant20'
       *  Constant: '<S28>/ThrSys_tiSampleFast_SC'
       *  Sum: '<S28>/Sum'
       */
      localSwitch = (ThrSys_tiStabSign_mIntPrev << 1) - ThrSys_tiSampleFast_SC;
      localSwitch = (localSwitch >= 0) ? ((SInt32)(((UInt32)localSwitch) >>
        1U)) : (~((SInt32)(((UInt32)(~localSwitch)) >> 1U)));
      if (localSwitch <= 0) {
        localrtmax = 0U;
      } else if (localSwitch > 65535) {
        localrtmax = MAX_uint16_T;
      } else {
        localrtmax = (UInt16)localSwitch;
      }

      /* RelationalOperator: '<S28>/Relational Operator9' incorporates:
       *  Constant: '<S28>/Constant24'
       */
      localNot = (localTmpSignalConversionAtAirSy >= 2147456160U);

      /* Switch: '<S28>/Switch9' incorporates:
       *  Constant: '<S28>/Constant19'
       *  Constant: '<S28>/ThrSys_tiDlyStabSign_mAirInt_C'
       *  RelationalOperator: '<S28>/Relational Operator6'
       */
      if (ThrSys_tiStabSign_mIntPrev == 0) {
        localrtmax = ThrSys_tiDlyStabSign_mAirInt_C;
      }

      /* Switch: '<S28>/Switch8' incorporates:
       *  Constant: '<S28>/ThrSys_tiDlyStabSign_mAirInt_C'
       *  RelationalOperator: '<S28>/Relational Operator8'
       */
      if (((SInt32)localNot) != ((SInt32)ThrSys_bAdpThrSign_mIntPrev)) {
        ThrSys_tiStabSign_mAirInt = ThrSys_tiDlyStabSign_mAirInt_C;
      } else {
        ThrSys_tiStabSign_mAirInt = localrtmax;
      }

      /* end of Outputs for SubSystem: '<S25>/F01_02_02_01_Calcul_du_signe' */

      /* Outputs for enable SubSystem: '<S25>/F01_02_02_02_Adapt_papillon' incorporates:
       *  Constant: '<S25>/Constant1'
       *  EnablePort: '<S29>/ThrSys_bAuthUpdApdThr'
       *  EnablePort: '<S30>/ThrSys_bAuthUpdApdThr'
       *  Logic: '<S25>/Logical Operator'
       *  RelationalOperator: '<S25>/Relational Operator1'
       *  SubSystem: '<S25>/F01_02_02_02_Adapt_papillon_else'
       *
       * Block requirements for '<S25>/F01_02_02_02_Adapt_papillon':
       *  1. SubSystem "F01_02_02_02_Adapt_papillon" !Trace_To : VEMS_R_10_06996_013.01 ;
       *
       * Block requirements for '<S25>/F01_02_02_02_Adapt_papillon_else':
       *  1. SubSystem "F01_02_02_02_Adapt_papillon" !Trace_To : VEMS_R_10_06996_013.01 ;
       */
      if (ThrSys_tiStabSign_mIntPrev == 0) {
        /* DataTypeConversion: '<S33>/Conversion' incorporates:
         *  Constant: '<S29>/ThrSys_arMaxSpdAdpThr_C'
         */
        localSwitch = ThrSys_arMaxSpdAdpThr_C * 4295;
        localConversion = (localSwitch >= 0) ? ((SInt32)(((UInt32)localSwitch)
          >> 12U)) : (~((SInt32)(((UInt32)(~localSwitch)) >> 12U)));

        /* DataTypeConversion: '<S34>/Conversion' incorporates:
         *  Constant: '<S29>/ThrSys_arMinSpdAdpThr_C'
         */
        localSwitch = ThrSys_arMinSpdAdpThr_C * 4295;
        localSwitch = (localSwitch >= 0) ? ((SInt32)(((UInt32)localSwitch) >>
          12U)) : (~((SInt32)(((UInt32)(~localSwitch)) >> 12U)));

        /* Sum: '<S29>/Sum3' incorporates:
         *  Constant: '<S29>/ThrSys_arStepSpdAdpThr_C'
         *  UnitDelay: '<S32>/Unit Delay'
         */
        localq = (SInt32)(((UInt32)(ThrSys_arStepSpdAdpThr_C * 4295)) >> 12);
        localqY = ThrSpT_DWork.UnitDelay_DSTATE + localq;
        if ((ThrSpT_DWork.UnitDelay_DSTATE > 0) && ((localq > 0) && (localqY <=
              0))) {
          localqY = MAX_int32_T;
        }

        /* Switch: '<S29>/Switch1' incorporates:
         *  Constant: '<S29>/ThrSys_arStepSpdAdpThr_C'
         *  Sum: '<S29>/Sum2'
         *  UnitDelay: '<S32>/Unit Delay'
         */
        if (!localNot) {
          localqY = ThrSpT_DWork.UnitDelay_DSTATE - ((SInt32)(((UInt32)
            (ThrSys_arStepSpdAdpThr_C * 4295)) >> 12));
          if ((ThrSpT_DWork.UnitDelay_DSTATE < 0) && (localqY >= 0)) {
            localqY = MIN_int32_T;
          }
        }

        /* Switch: '<S35>/Switch' incorporates:
         *  RelationalOperator: '<S35>/UpperRelop'
         */
        if (!(localqY < localSwitch)) {
          localSwitch = localqY;
        }

        /* Switch: '<S35>/Switch2' incorporates:
         *  RelationalOperator: '<S35>/LowerRelop1'
         */
        if (localqY > localConversion) {
          localSwitch = localConversion;
        }

        /* SignalConversion: '<S29>/Signal Conversion' */
        ThrSpT_B.Merge2 = localSwitch;

        /* Update for UnitDelay: '<S32>/Unit Delay' */
        ThrSpT_DWork.UnitDelay_DSTATE = localSwitch;
      } else {
        /* SignalConversion: '<S30>/Signal Conversion1' */
        ThrSpT_B.Merge2 = ThrSpT_B.TmpSignalConversionAtThrSys_arS;
      }

      /* end of Outputs for SubSystem: '<S25>/F01_02_02_02_Adapt_papillon' */

      /* SignalConversion: '<S25>/Signal Conversion' */
      ThrSys_bAdpThrSign_mAirInt = localNot;
    }

    /* Update for UnitDelay: '<S26>/Unit Delay' */
    ThrSpT_DWork.UnitDelay_DSTATE_a = ThrSys_tiStabSign_mAirInt;

    /* Update for UnitDelay: '<S27>/Unit Delay' */
    ThrSpT_DWork.UnitDelay_DSTATE_o = ThrSys_bAdpThrSign_mAirInt;
  } else {
    /* SignalConversion: '<S22>/Signal Conversion' */
    ThrSpT_B.Merge2 = ThrSpT_B.TmpSignalConversionAtThrSys_arS;
  }

  /* end of Outputs for SubSystem: '<S7>/F01_02_Adaptation_papillon' */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S19>/autosar_testpoint1' */

  /* S-Function Block: <S19>/autosar_testpoint1 */
  ThrSys_arSpdAdpThr_IRV_MP = ThrSpT_B.Merge2;

  /* S-Function (NvRamWriteAccess): '<S7>/EepromWriteAccess' */
  ThrSpT_sNV_Z1_CONST_32BIT.ThrSys_arSpdAdpThr_NV = ThrSpT_B.Merge2;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtThrSys_arSpdAdpThr_irvInport2' incorporates:
   *  SignalConversion: '<S7>/Signal Conversion'
   */
  Rte_IrvWrite_RE_ThrSpT_003_TEV_ThrSys_arSpdAdpThr_irv(ThrSpT_B.Merge2);
}

/* Start for exported function: RE_ThrSpT_002_TEV */
void RE_ThrSpT_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_Calcul_de_la_consig_pos_pap'
   *
   * Block requirements for '<S1>/F01_Calcul_de_la_consig_pos_pap':
   *  1. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_002.01 ;
   *  2. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_001.01 ;
   *  3. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_027.01 ;
   *  4. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_015.01 ;
   *  5. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_016.01 ;
   *  6. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_017.01 ;
   *  7. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_018.01 ;
   *  8. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_019.01 ;
   *  9. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_014.01 ;
   *  10. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_024.01 ;
   */
}

/* Output and update for exported function: RE_ThrSpT_002_TEV */
void RE_ThrSpT_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtAir_l;
  UInt16 localDataTypeConversion1;
  UInt16 localLookUpTable;
  UInt16 localrtmin;
  Float32 localMinMax1;
  Float32 localmax;
  SInt8 localTmpSignalConversionAtAFA_f;
  SInt8 localTmpSignalConversionAtAFA_m;
  SInt8 localTmpSignalConversionAtAF_al;
  SInt16 localTmpSignalConversionAtAFA_a;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_Calcul_de_la_consig_pos_pap'
   *
   * Block requirements for '<S1>/F01_Calcul_de_la_consig_pos_pap':
   *  1. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_002.01 ;
   *  2. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_001.01 ;
   *  3. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_027.01 ;
   *  4. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_015.01 ;
   *  5. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_016.01 ;
   *  6. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_017.01 ;
   *  7. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_018.01 ;
   *  8. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_019.01 ;
   *  9. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_014.01 ;
   *  10. SubSystem "F01_Calcul_de_la_consig_pos_pap" !Trace_To : VEMS_R_10_06996_024.01 ;
   */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAirSys_arThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_arThrReq'
   */
  Rte_Read_R_AirSys_arThrReq_AirSys_arThrReq(&localTmpSignalConversionAtAir_l);

  /* Outputs for atomic SubSystem: '<S6>/F01_01_Calc_Consigne_position_nominale' *
   * Block requirements for '<S6>/F01_01_Calc_Consigne_position_nominale':
   *  1. SubSystem "F01_01_Calc_Consigne_position_nominale" !Trace_To : VEMS_R_10_06996_003.02 ;
   */

  /* Lookup: '<S14>/Look-Up Table'
   * About '<S14>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-24
   * Output0 Data Type:  Fixed Point    U16  2^-10
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(ThrSys_rOpThrNom), (&(Air_rOpThr_T[0])),
                 localTmpSignalConversionAtAir_l, (&(Air_arEffThr_A[0])), 32U);

  /* DataTypeDuplicate Block: '<S14>/Data Type Duplicate1'
   *
   * Regarding '<S14>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* end of Outputs for SubSystem: '<S6>/F01_01_Calc_Consigne_position_nominale' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAFA_facArEffThrOfs1Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs1'
   */
  Rte_Read_R_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1
    (&localTmpSignalConversionAtAFA_f);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAFA_facArEffThrOfs2Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs2'
   */
  Rte_Read_R_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2
    (&localTmpSignalConversionAtAFA_m);

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAFA_facArEffThrOfs3Outport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs3'
   */
  Rte_Read_R_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3
    (&localTmpSignalConversionAtAF_al);

  /* Outputs for atomic SubSystem: '<S6>/F01_02_Calc_eff_area_offset' *
   * Block requirements for '<S6>/F01_02_Calc_eff_area_offset':
   *  1. SubSystem "F01_02_Calc_eff_area_offset" !Trace_To : VEMS_R_10_06996_004.01 ;
   */

  /* MinMax: '<S11>/MinMax' incorporates:
   *  Constant: '<S11>/AFA_rOpThrMax_C'
   */
  localrtmin = ThrSys_rOpThrNom;
  if (AFA_rOpThrMax_C < ThrSys_rOpThrNom) {
    localrtmin = AFA_rOpThrMax_C;
  }

  /* DataStoreWrite: '<S11>/Data Store Write' */
  ThrSys_rOpThrNomSat_MP = localrtmin;

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S11>/AFA_rOpThrRef2_C'
   */
  localMinMax1 = (((Float32)localrtmin) * 0.0009765625F) - (((Float32)
    AFA_rOpThrRef2_C) * 0.0009765625F);

  /* MinMax: '<S11>/MinMax1' incorporates:
   *  Constant: '<S11>/Constant8'
   */
  localmax = rt_MAXf(0.0F, localMinMax1);

  /* DataStoreWrite: '<S11>/Data Store Write1' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion1'
   */
  localtmp = ACTEMS_LdexpF((Float32d)localmax, 10);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      ThrSys_rOpThrNomRef2_MP = (UInt16)localtmp;
    } else {
      ThrSys_rOpThrNomRef2_MP = 0U;
    }
  } else {
    ThrSys_rOpThrNomRef2_MP = MAX_uint16_T;
  }

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<S11>/AFA_rOpThrRef3_C'
   */
  localMinMax1 = (((Float32)localrtmin) * 0.0009765625F) - (((Float32)
    AFA_rOpThrRef3_C) * 0.0009765625F);

  /* MinMax: '<S11>/MinMax2' incorporates:
   *  Constant: '<S11>/Constant9'
   */
  localMinMax1 = rt_MAXf(localMinMax1, 0.0F);

  /* DataStoreWrite: '<S11>/Data Store Write2' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  localtmp = ACTEMS_LdexpF((Float32d)localMinMax1, 10);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      ThrSys_rOpThrNomRef3_MP = (UInt16)localtmp;
    } else {
      ThrSys_rOpThrNomRef3_MP = 0U;
    }
  } else {
    ThrSys_rOpThrNomRef3_MP = MAX_uint16_T;
  }

  /* Sum: '<S11>/Sum2' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion3'
   *  DataTypeConversion: '<S11>/Data Type Conversion5'
   *  DataTypeConversion: '<S11>/Data Type Conversion6'
   *  DataTypeConversion: '<S11>/Data Type Conversion7'
   *  Product: '<S15>/Divide'
   *  Product: '<S16>/Divide'
   *  Product: '<S17>/Divide'
   */
  ThrSys_arOpEffThrOfs = (((((Float32)localTmpSignalConversionAtAFA_f) *
    3.814697266E-006F) * (((Float32)localrtmin) * 0.0009765625F)) +
    ((((Float32)localTmpSignalConversionAtAFA_m) * 3.814697266E-006F) *
     localmax)) + ((((Float32)localTmpSignalConversionAtAF_al) *
                    3.814697266E-006F) * localMinMax1);

  /* end of Outputs for SubSystem: '<S6>/F01_02_Calc_eff_area_offset' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtAFA_arEffThrOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffThrOfs'
   */
  Rte_Read_R_AFA_arEffThrOfs_AFA_arEffThrOfs(&localTmpSignalConversionAtAFA_a);

  /* Outputs for atomic SubSystem: '<S6>/F01_03_Calc_Consigne_position_papillon_corrigee' *
   * Block requirements for '<S6>/F01_03_Calc_Consigne_position_papillon_corrigee':
   *  1. SubSystem "F01_03_Calc_Consigne_position_papillon_corrigee" !Trace_To : VEMS_R_10_06996_005.02 ;
   */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAtThrSys_arSpdAdpThrOutport2'
   *  Sum: '<S12>/Sum1'
   */
  localtmp = ACTEMS_LdexpF((Float32d)((((((Float32)
    localTmpSignalConversionAtAFA_a) * 5.960464478E-008F) + ThrSys_arOpEffThrOfs)
    + (((Float32)Rte_IrvRead_RE_ThrSpT_002_TEV_ThrSys_arSpdAdpThr_irv()) *
       3.725290298E-009F)) + (((Float32)localTmpSignalConversionAtAir_l) *
    5.960464478E-008F)), 24);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion1 = (UInt16)localtmp;
    } else {
      localDataTypeConversion1 = 0U;
    }
  } else {
    localDataTypeConversion1 = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S12>/Data Store Write2' */
  ThrSys_arThrCor_MP = localDataTypeConversion1;

  /* Lookup: '<S18>/Look-Up Table'
   * About '<S18>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-24
   * Output0 Data Type:  Fixed Point    U16  2^-10
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable), (&(Air_rOpThr_T[0])),
                 localDataTypeConversion1, (&(Air_arEffThr_A[0])), 32U);

  /* DataTypeDuplicate Block: '<S18>/Data Type Duplicate1'
   *
   * Regarding '<S18>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S13>/Data Type Conversion'
   *
   * Regarding '<S13>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S6>/F01_03_Calc_Consigne_position_papillon_corrigee' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   *  Lookup: '<S18>/Look-Up Table'
   */
  if (THRSPT_ACTIVE_BYP_C) {
    localrtmin = ThrSys_rOpThrReq_B;
  } else {
    localrtmin = localLookUpTable;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtThrSys_rOpThrReqInport2' */
  Rte_Write_P_ThrSys_rOpThrReq_ThrSys_rOpThrReq(localrtmin);
}

/* Start for exported function: RE_ThrSpT_001_MSE */
void RE_ThrSpT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_ThrAdpr_initialization'
   *
   * Block requirements for '<S1>/F00_ThrAdpr_initialization':
   *  1. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_026.01 ;
   *  2. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_014.01 ;
   *  3. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_024.01 ;
   *  4. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_029.01 ;
   */
}

/* Output and update for exported function: RE_ThrSpT_001_MSE */
void RE_ThrSpT_001_MSE(void)
{
  UInt16 localThrSys_rOpThrReq_p;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_ThrAdpr_initialization'
   *
   * Block requirements for '<S1>/F00_ThrAdpr_initialization':
   *  1. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_026.01 ;
   *  2. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_014.01 ;
   *  3. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_024.01 ;
   *  4. SubSystem "F00_ThrAdpr_initialization" !Trace_To : VEMS_R_10_06996_029.01 ;
   */

  /* user code (Output function Body for TID4) */
  RE_ThrSp_Init();

  /* S-Function (NvRamReadAccess): '<S5>/EepromReadAccess' */
  ThrSpT_B.EepromReadAccess = ThrSpT_sNV_Z1_CONST_32BIT.ThrSys_arSpdAdpThr_NV;

  /* DataTypeConversion Block: '<S5>/DTConv_UFix_To_Single_1'
   *
   * Regarding '<S5>/DTConv_UFix_To_Single_1':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S8>/copy' */
  ThrSys_arSpdAdpThr_IRV_MP = ThrSpT_B.EepromReadAccess;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S8>/autosar_testpoint1' */

  /* S-Function Block: <S8>/autosar_testpoint1 */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtThrSys_arSpdAdpThr_irvInport2' incorporates:
   *  SignalConversion: '<S5>/Signal Conversion'
   */
  Rte_IrvWrite_RE_ThrSpT_001_MSE_ThrSys_arSpdAdpThr_irv
    (ThrSpT_B.EepromReadAccess);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S5>/Rend_egr_homogene_bkpt1'
   *  Constant: '<S9>/Byp_Fonction_SC'
   *  Constant: '<S9>/Int_BypC'
   */
  if (THRSPT_ACTIVE_BYP_C) {
    localThrSys_rOpThrReq_p = ThrSys_rOpThrReq_B;
  } else {
    localThrSys_rOpThrReq_p = 0U;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtThrSys_rOpThrReqInport2' */
  Rte_Write_P_ThrSys_rOpThrReq_ThrSys_rOpThrReq(localThrSys_rOpThrReq_p);
}

/* Model initialize function */
void RE_ThrSp_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   */
  RE_ThrSpT_003_TEV_Start();
  RE_ThrSpT_002_TEV_Start();
  RE_ThrSpT_001_MSE_Start();
}

#define ThrSpT_STOP_SEC_CODE
#include "ThrSpT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
