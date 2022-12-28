/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !Module          : AirSysTrb                                               */
/* !Description     : AirSysTrb Software Component                            */
/*                                                                            */
/* !File            : AirSysTrb.c                                             */
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
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Model name       : AirSysTrb_AUTOSAR.mdl                                 */
/*   Root subsystem   : /AirSysTrb                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M18-AirSysTrb/5-$*/
/* $Revision::   1.6                                                         $*/
/* $Author::   ADELVARE                               $$Date::   01 Aug 2011 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AirSysTrb.h"
#include "AirSysTrb_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AirSysTrb_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AirSysTrb AirSysTrb_B;

/* Block states (auto storage) */
D_Work_AirSysTrb AirSysTrb_DWork;

#define AirSysTrb_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AirSysTrb_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define AIRSYSTRB_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define AIRSYSTRB_VEMSRTLIBT_MINOR_VERSION_REQ 1
#define AIRSYSTRB_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define AIRSYSTRB_VEMSRTLIBT_VERSION_REQ (AIRSYSTRB_VEMSRTLIBT_PATCH_VERSION_REQ + AIRSYSTRB_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + AIRSYSTRB_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if AIRSYSTRB_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AirSysTrb_START_SEC_CODE
#include "AirSysTrb_MemMap.h"

void AirSysTrb_ASYNC1(int controlPortIdx)
{
}

void AirSysTrb_ASYNC2(int controlPortIdx)
{
}

void AirSysTrb_ASYNC3(int controlPortIdx)
{
}

void AirSysTrb_ASYNC4(int controlPortIdx)
{
}

void AirSysTrb_ASYNC5(int controlPortIdx)
{
}

/* Start for exported function: RE_AirSysTrb_005_TEV */
void RE_AirSysTrb_005_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F05_AirReqFil'
   *
   * Block requirements for '<S1>/F05_AirReqFil':
   *  1. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_013.03 ;
   *  2. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_014.03 ;
   *  3. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_016.03 ;
   *  4. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  5. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  6. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  7. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  8. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  9. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_031.01 ;
   *  10. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_032.01 ;
   *  11. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_033.01 ;
   *  12. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_034.01 ;
   *  13. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_035.01 ;
   *  14. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_036.01 ;
   *  15. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_037.01 ;
   *  16. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_042.02 ;
   *  17. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_043.01 ;
   *  18. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_044.01 ;
   *  19. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_045.01 ;
   *  20. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_046.01 ;
   *  21. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_048.01 ;
   *  22. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_049.01 ;
   *  23. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_050.01 ;
   */
}

/* Output and update for exported function: RE_AirSysTrb_005_TEV */
void RE_AirSysTrb_005_TEV(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable;
  UInt16 localDataTypeConversion;
  Boolean localRelationalOperator;
  Boolean localSwitch2_l;
  Boolean localLO3;
  Boolean localLogicalOperator4;
  Boolean localRelationalOperator_i;
  Boolean localLogicalOperator_ha;
  Boolean localUnitDelay_b;
  Boolean localLogic[2];
  Float32 localDTConv_Single_To_UFix_14;
  UInt16 localTmpSignalConversionAtExt_n;
  Float32 localSum2;
  Float32 localSwitch2;
  Float32 localSwitch3;
  Float32 localSwitch4;
  Float32 localSwitch1;
  Boolean localTmpSignalConversionAtAi_dj;
  Boolean localLogicalOperator2;
  UInt8 localTmpSignalConversionAtCoVSC;
  Boolean localRelationalOperator_b;
  Boolean localRelationalOperator_g;
  Boolean localSwitch2_p1;
  Boolean localSwitch2_pv;
  UInt8 localTmpSignalConversionAtCoPt_;
  Boolean localTmpSignalConversionAtCoP_o;
  UInt16 localTmpSignalConversionAtAir_c;
  UInt16 localTmpSignalConversionAtAir_l;
  UInt16 localTmpSignalConversionAtAirSy[2];
  UInt16 localTmpSignalConversionAtAir_k;
  UInt16 localTmpSignalConversionAtAir_i;
  UInt16 localTmpSignalConversionAtAir_d;
  SInt32 localSum;
  Float32d localtmp;
  SInt16 locallocalSum;
  SInt32 localqY;
  SInt32 localqY_0;
  SInt32 localqY_1;
  SInt32 localqY_2;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F05_AirReqFil'
   *
   * Block requirements for '<S1>/F05_AirReqFil':
   *  1. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_013.03 ;
   *  2. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_014.03 ;
   *  3. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_016.03 ;
   *  4. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  5. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  6. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  7. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  8. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  9. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_031.01 ;
   *  10. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_032.01 ;
   *  11. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_033.01 ;
   *  12. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_034.01 ;
   *  13. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_035.01 ;
   *  14. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_036.01 ;
   *  15. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_037.01 ;
   *  16. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_042.02 ;
   *  17. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_043.01 ;
   *  18. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_044.01 ;
   *  19. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_045.01 ;
   *  20. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_046.01 ;
   *  21. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_048.01 ;
   *  22. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_049.01 ;
   *  23. SubSystem "F05_AirReqFil" !Trace_To : VEMS_R_10_07036_050.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsThrReqFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReqFil_INPUT'
   */
  Rte_Read_R_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil
    (&localTmpSignalConversionAtAir_c);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReq_INPUT'
   */
  Rte_Read_R_AirSys_pUsThrReq_AirSys_pUsThrReq(&localTmpSignalConversionAtAir_l);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_14' */
  localDTConv_Single_To_UFix_14 = ((Float32)localTmpSignalConversionAtAir_l) *
    8.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_bActStraLimSurgeOutport2' incorporates:
   *  Inport: '<Root>/AirSys_bActStraLimSurge'
   */
  Rte_Read_R_AirSys_bActStraLimSurge_AirSys_bActStraLimSurge
    (&localTmpSignalConversionAtAi_dj);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoVSCtl_stAccPOutport2' incorporates:
   *  Inport: '<Root>/CoVSCtl_stAccP'
   */
  Rte_Read_R_CoVSCtl_stAccP_CoVSCtl_stAccP(&localTmpSignalConversionAtCoVSC);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoPt_bSIPOutport2' incorporates:
   *  Inport: '<Root>/CoPt_bSIP'
   */
  Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&localTmpSignalConversionAtCoP_o);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtCoPt_stGSTypOutport2' incorporates:
   *  Inport: '<Root>/CoPt_stGSTyp'
   */
  Rte_Read_R_CoPt_stGSTyp_CoPt_stGSTyp(&localTmpSignalConversionAtCoPt_);

  /* Outputs for atomic SubSystem: '<S11>/F01_TipOutMgr'
   * Block description for '<S11>/F01_TipOutMgr':
   *  01460_10_02799_2.FR.5.2
   *
   * Block requirements for '<S11>/F01_TipOutMgr':
   *  1. SubSystem "F01_TipOutMgr" !Trace_To : VEMS_R_10_07036_017.03 ;
   */

  /* Outputs for enable SubSystem: '<S53>/F01_FrzInh' incorporates:
   *  Constant: '<S53>/AirSys_bAcvFrzMod_C'
   *  EnablePort: '<S55>/AirSys_bFrzInh'
   *  EnablePort: '<S56>/AirSys_bFrzClcn'
   *  Logic: '<S53>/Logical Operator'
   *  SubSystem: '<S53>/F02_FrzAcv'
   *
   * Block description for '<S53>/F01_FrzInh':
   *  01460_10_02799_2.FR.6.2
   *
   * Block description for '<S53>/F02_FrzAcv':
   *  01460_10_02799_2.FR.7.2
   *
   * Block requirements for '<S53>/F01_FrzInh':
   *  1. SubSystem "F01_FrzInh" !Trace_To : VEMS_R_10_07036_018.03 ;
   *
   * Block requirements for '<S53>/F02_FrzAcv':
   *  1. SubSystem "F02_FrzAcv" !Trace_To : VEMS_R_10_07036_019.03 ;
   */
  if (!AirSys_bAcvFrzMod_C) {
    /* Constant: '<S55>/Constant' */
    localTmpSignalConversionAtAi_dj = FALSE;
  } else {
    /* Sum: '<S56>/Sum1' incorporates:
     *  UnitDelay: '<S63>/Unit Delay'
     */
    localtmp = ACTEMS_FloorF(ACTEMS_LdexpF((Float32d)
      (localDTConv_Single_To_UFix_14 - AirSysTrb_DWork.UnitDelay_DSTATE_m5), -3));
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        locallocalSum = (SInt16)localtmp;
      } else {
        locallocalSum = MIN_int16_T;
      }
    } else {
      locallocalSum = MAX_int16_T;
    }

    /* Logic: '<S56>/Logical Operator5' incorporates:
     *  Constant: '<S56>/AirSys_pGrdUsThrInhFrzThd_C'
     *  DataTypeConversion: '<S11>/DTConv_Single_To_UFix_15'
     *  RelationalOperator: '<S56>/Relational Operator2'
     *  RelationalOperator: '<S56>/Relational Operator3'
     */
    localLogicalOperator4 = ((locallocalSum >= AirSys_pGrdUsThrInhFrzThd_C) ||
                             (((SInt32)localDTConv_Single_To_UFix_14) >
      (localTmpSignalConversionAtAir_c << 3)));

    /* DataStoreWrite: '<S56>/MemoryStore1' */
    AirSys_bInhFrzMod_MP = localLogicalOperator4;

    /* Logic: '<S56>/Logical Operator1' incorporates:
     *  Constant: '<S56>/AirSys_bAcvStraLimSurgeFrz_C'
     */
    localTmpSignalConversionAtAi_dj = (AirSys_bAcvStraLimSurgeFrz_C &&
      (localTmpSignalConversionAtAi_dj));

    /* Logic: '<S56>/Logical Operator2' incorporates:
     *  UnitDelay: '<S62>/Unit Delay'
     */
    localLogicalOperator2 = !AirSysTrb_DWork.UnitDelay_DSTATE_le;

    /* RelationalOperator: '<S56>/Relational Operator' incorporates:
     *  Constant: '<S56>/Constant'
     */
    localRelationalOperator = (localTmpSignalConversionAtCoVSC == 0);

    /* Switch: '<S72>/Switch' incorporates:
     *  RelationalOperator: '<S72>/UpperRelop'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_e < 0) {
      localSum = 0;
    } else {
      localSum = AirSysTrb_DWork.UnitDelay_DSTATE_e;
    }

    /* Switch: '<S72>/Switch2' incorporates:
     *  RelationalOperator: '<S72>/LowerRelop1'
     *  UnitDelay: '<S69>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_e > 819200) {
      localSum = 819200;
    }

    /* Switch: '<S58>/Switch2' incorporates:
     *  Constant: '<S56>/AirSys_tiSampleFast_SC1'
     *  Constant: '<S58>/Constant1'
     *  Logic: '<S67>/Logical Operator'
     *  Logic: '<S67>/Logical Operator1'
     *  Sum: '<S58>/Sum'
     *  UnitDelay: '<S73>/Unit Delay'
     */
    if ((!localRelationalOperator) && AirSysTrb_DWork.UnitDelay_DSTATE_j) {
      localqY = 0;
    } else {
      localqY_0 = ((SInt32)(((UInt32)(AirSys_tiSampleFast_SC * 16777)) >> 12))
        + 4;
      localqY = localqY_0 + localSum;
      if ((localqY_0 < 0) && ((localSum < 0) && (localqY >= 0))) {
        localqY = MIN_int32_T;
      } else {
        if ((localqY_0 > 0) && ((localSum > 0) && (localqY <= 0))) {
          localqY = MAX_int32_T;
        }
      }
    }

    /* RelationalOperator: '<S58>/Relational Operator' incorporates:
     *  Constant: '<S56>/TrbAct_tiDlyDetPUsThrDif_C1'
     */
    localRelationalOperator_b = (localqY > AirSys_tiDlyDetAccPNull_C);

    /* Logic: '<S68>/Logical Operator' incorporates:
     *  Logic: '<S68>/Logical Operator1'
     *  UnitDelay: '<S74>/Unit Delay'
     */
    localRelationalOperator_i = ((localRelationalOperator_b) &&
      (!AirSysTrb_DWork.UnitDelay_DSTATE_d));

    /* UnitDelay: '<S65>/UnitDelay' */
    localUnitDelay_b = AirSysTrb_DWork.UnitDelay;

    /* CombinatorialLogic: '<S65>/Logic' */
    {
      uint_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (uint_T)(localRelationalOperator != 0);
      rowidx = (rowidx << 1) + (uint_T)(localRelationalOperator_i != 0);
      rowidx = (rowidx << 1) + (uint_T)(localUnitDelay_b != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysTrb_ConstP.pooled8[rowidx];
      localLogic[1] = AirSysTrb_ConstP.pooled8[rowidx + 8];
    }

    /* Switch: '<S65>/Switch2' incorporates:
     *  Constant: '<S65>/NotCLR3'
     *  UnitDelay: '<S65>/UnitDelay1'
     */
    if (AirSysTrb_DWork.UnitDelay_l) {
      localSwitch2_p1 = localLogic[0];
    } else {
      localSwitch2_p1 = FALSE;
    }

    /* RelationalOperator: '<S57>/Relational Operator1' incorporates:
     *  Constant: '<S56>/AirSys_pGrdUsThrLoThd_C'
     */
    localUnitDelay_b = (AirSys_pGrdUsThrLoThd_C >= locallocalSum);

    /* RelationalOperator: '<S57>/Relational Operator' incorporates:
     *  Constant: '<S56>/AirSys_pGrdUsThrHiThd_C'
     */
    localRelationalOperator_i = (locallocalSum >= AirSys_pGrdUsThrHiThd_C);

    /* UnitDelay: '<S64>/UnitDelay' */
    localLogicalOperator_ha = AirSysTrb_DWork.UnitDelay_d;

    /* CombinatorialLogic: '<S64>/Logic' */
    {
      uint_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (uint_T)(localUnitDelay_b != 0);
      rowidx = (rowidx << 1) + (uint_T)(localRelationalOperator_i != 0);
      rowidx = (rowidx << 1) + (uint_T)(localLogicalOperator_ha != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysTrb_ConstP.pooled8[rowidx];
      localLogic[1] = AirSysTrb_ConstP.pooled8[rowidx + 8];
    }

    /* Switch: '<S64>/Switch2' incorporates:
     *  Constant: '<S64>/NotCLR3'
     *  UnitDelay: '<S64>/UnitDelay1'
     */
    if (AirSysTrb_DWork.UnitDelay_f) {
      localSwitch2_l = localLogic[0];
    } else {
      localSwitch2_l = FALSE;
    }

    /* Switch: '<S82>/Switch' incorporates:
     *  RelationalOperator: '<S82>/UpperRelop'
     *  UnitDelay: '<S79>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_mu < 0) {
      localSum = 0;
    } else {
      localSum = AirSysTrb_DWork.UnitDelay_DSTATE_mu;
    }

    /* Switch: '<S82>/Switch2' incorporates:
     *  RelationalOperator: '<S82>/LowerRelop1'
     *  UnitDelay: '<S79>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_mu > 819200) {
      localSum = 819200;
    }

    /* Switch: '<S59>/Switch2' incorporates:
     *  Constant: '<S56>/AirSys_tiSampleFast_SC2'
     *  Constant: '<S59>/Constant1'
     *  Logic: '<S77>/Logical Operator'
     *  Logic: '<S77>/Logical Operator1'
     *  Sum: '<S59>/Sum'
     *  UnitDelay: '<S83>/Unit Delay'
     */
    if ((!localSwitch2_l) && AirSysTrb_DWork.UnitDelay_DSTATE_o3) {
      localqY_1 = 0;
    } else {
      localqY_0 = ((SInt32)(((UInt32)(AirSys_tiSampleFast_SC * 16777)) >> 12))
        + 4;
      localqY_1 = localqY_0 + localSum;
      if ((localqY_0 < 0) && ((localSum < 0) && (localqY_1 >= 0))) {
        localqY_1 = MIN_int32_T;
      } else {
        if ((localqY_0 > 0) && ((localSum > 0) && (localqY_1 <= 0))) {
          localqY_1 = MAX_int32_T;
        }
      }
    }

    /* RelationalOperator: '<S59>/Relational Operator' incorporates:
     *  Constant: '<S56>/TrbAct_tiDlyDetPUsThrDif_C'
     */
    localRelationalOperator_g = (localqY_1 > AirSys_tiDlyDetPGrdUsThr_C);

    /* Logic: '<S78>/Logical Operator' incorporates:
     *  Logic: '<S78>/Logical Operator1'
     *  UnitDelay: '<S84>/Unit Delay'
     */
    localLogicalOperator_ha = ((localRelationalOperator_g) &&
      (!AirSysTrb_DWork.UnitDelay_DSTATE_f));

    /* UnitDelay: '<S75>/UnitDelay' */
    localUnitDelay_b = AirSysTrb_DWork.UnitDelay_d3;

    /* CombinatorialLogic: '<S75>/Logic' */
    {
      uint_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (uint_T)(localSwitch2_l != 0);
      rowidx = (rowidx << 1) + (uint_T)(localLogicalOperator_ha != 0);
      rowidx = (rowidx << 1) + (uint_T)(localUnitDelay_b != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysTrb_ConstP.pooled8[rowidx];
      localLogic[1] = AirSysTrb_ConstP.pooled8[rowidx + 8];
    }

    /* Switch: '<S75>/Switch2' incorporates:
     *  Constant: '<S75>/NotCLR3'
     *  UnitDelay: '<S75>/UnitDelay1'
     */
    if (AirSysTrb_DWork.UnitDelay_j) {
      localSwitch2_pv = localLogic[0];
    } else {
      localSwitch2_pv = FALSE;
    }

    /* Logic: '<S56>/Logical Operator4' */
    localLogicalOperator4 = (((localTmpSignalConversionAtAi_dj) ||
      (localLogicalOperator4)) || (localLogicalOperator2));

    /* Logic: '<S56>/Logical Operator6' incorporates:
     *  Constant: '<S56>/AirSys_bAcvStraLimSurgeFrz_C1'
     *  Constant: '<S56>/Constant1'
     *  Logic: '<S56>/Logical Operator3'
     *  Logic: '<S56>/Logical Operator7'
     *  RelationalOperator: '<S56>/Relational Operator1'
     */
    localLogicalOperator_ha = (((localSwitch2_p1) && (localSwitch2_pv)) ||
      (((localTmpSignalConversionAtCoP_o) && (localTmpSignalConversionAtCoPt_ ==
      1)) && AirSys_bDetMT_C));

    /* UnitDelay: '<S61>/UnitDelay' */
    localUnitDelay_b = AirSysTrb_DWork.UnitDelay_c;

    /* CombinatorialLogic: '<S61>/Logic' */
    {
      uint_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (uint_T)(localLogicalOperator_ha != 0);
      rowidx = (rowidx << 1) + (uint_T)(localLogicalOperator4 != 0);
      rowidx = (rowidx << 1) + (uint_T)(localUnitDelay_b != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysTrb_ConstP.pooled8[rowidx];
      localLogic[1] = AirSysTrb_ConstP.pooled8[rowidx + 8];
    }

    /* Switch: '<S61>/Switch2' incorporates:
     *  Constant: '<S61>/NotCLR3'
     *  UnitDelay: '<S61>/UnitDelay1'
     */
    if (AirSysTrb_DWork.UnitDelay_je) {
      localTmpSignalConversionAtAi_dj = localLogic[0];
    } else {
      localTmpSignalConversionAtAi_dj = FALSE;
    }

    /* Logic: '<S61>/LO3' */
    localLO3 = !localTmpSignalConversionAtAi_dj;

    /* Switch: '<S92>/Switch' incorporates:
     *  RelationalOperator: '<S92>/UpperRelop'
     *  UnitDelay: '<S89>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_o < 0) {
      localSum = 0;
    } else {
      localSum = AirSysTrb_DWork.UnitDelay_DSTATE_o;
    }

    /* Switch: '<S92>/Switch2' incorporates:
     *  RelationalOperator: '<S92>/LowerRelop1'
     *  UnitDelay: '<S89>/Unit Delay'
     */
    if (AirSysTrb_DWork.UnitDelay_DSTATE_o > 819200) {
      localSum = 819200;
    }

    /* Switch: '<S60>/Switch2' incorporates:
     *  Constant: '<S56>/AirSys_tiSampleFast_SC'
     *  Constant: '<S60>/Constant1'
     *  Logic: '<S87>/Logical Operator'
     *  Logic: '<S87>/Logical Operator1'
     *  Sum: '<S60>/Sum'
     *  UnitDelay: '<S93>/Unit Delay'
     */
    if ((!localLO3) && AirSysTrb_DWork.UnitDelay_DSTATE_c) {
      localSum = 0;
    } else {
      localqY_0 = ((SInt32)(((UInt32)(AirSys_tiSampleFast_SC * 16777)) >> 12))
        + 4;
      localqY_2 = localqY_0 + localSum;
      if ((localqY_0 < 0) && ((localSum < 0) && (localqY_2 >= 0))) {
        localqY_2 = MIN_int32_T;
      } else {
        if ((localqY_0 > 0) && ((localSum > 0) && (localqY_2 <= 0))) {
          localqY_2 = MAX_int32_T;
        }
      }

      localSum = localqY_2;
    }

    /* RelationalOperator: '<S60>/Relational Operator' incorporates:
     *  Constant: '<S56>/AirSys_tiDlyFrz_C'
     */
    localLogicalOperator2 = (localSum > AirSys_tiDlyFrz_C);

    /* Logic: '<S88>/Logical Operator' incorporates:
     *  Logic: '<S88>/Logical Operator1'
     *  UnitDelay: '<S94>/Unit Delay'
     */
    localLogicalOperator_ha = ((localLogicalOperator2) &&
      (!AirSysTrb_DWork.UnitDelay_DSTATE_em));

    /* UnitDelay: '<S85>/UnitDelay' */
    localUnitDelay_b = AirSysTrb_DWork.UnitDelay_b;

    /* CombinatorialLogic: '<S85>/Logic' */
    {
      uint_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (uint_T)(localLO3 != 0);
      rowidx = (rowidx << 1) + (uint_T)(localLogicalOperator_ha != 0);
      rowidx = (rowidx << 1) + (uint_T)(localUnitDelay_b != 0);

      /* Copy the appropriate row of the table into the block output vector */
      localLogic[0] = AirSysTrb_ConstP.pooled8[rowidx];
      localLogic[1] = AirSysTrb_ConstP.pooled8[rowidx + 8];
    }

    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S85>/NotCLR3'
     *  UnitDelay: '<S85>/UnitDelay1'
     */
    if (AirSysTrb_DWork.UnitDelay_n) {
      localTmpSignalConversionAtCoP_o = localLogic[0];
    } else {
      localTmpSignalConversionAtCoP_o = FALSE;
    }

    /* Update for UnitDelay: '<S63>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_m5 = localDTConv_Single_To_UFix_14;

    /* Update for UnitDelay: '<S62>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_le = localTmpSignalConversionAtCoP_o;

    /* Update for UnitDelay: '<S73>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_j = localRelationalOperator;

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_e = localqY;

    /* Update for UnitDelay: '<S74>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_d = localRelationalOperator_b;

    /* Update for UnitDelay: '<S65>/UnitDelay' */
    AirSysTrb_DWork.UnitDelay = localSwitch2_p1;

    /* Update for UnitDelay: '<S65>/UnitDelay1' incorporates:
     *  Constant: '<S65>/NotCLR2'
     */
    AirSysTrb_DWork.UnitDelay_l = TRUE;

    /* Update for UnitDelay: '<S64>/UnitDelay' */
    AirSysTrb_DWork.UnitDelay_d = localSwitch2_l;

    /* Update for UnitDelay: '<S64>/UnitDelay1' incorporates:
     *  Constant: '<S64>/NotCLR2'
     */
    AirSysTrb_DWork.UnitDelay_f = TRUE;

    /* Update for UnitDelay: '<S83>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_o3 = localSwitch2_l;

    /* Update for UnitDelay: '<S79>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_mu = localqY_1;

    /* Update for UnitDelay: '<S84>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_f = localRelationalOperator_g;

    /* Update for UnitDelay: '<S75>/UnitDelay' */
    AirSysTrb_DWork.UnitDelay_d3 = localSwitch2_pv;

    /* Update for UnitDelay: '<S75>/UnitDelay1' incorporates:
     *  Constant: '<S75>/NotCLR2'
     */
    AirSysTrb_DWork.UnitDelay_j = TRUE;

    /* Update for UnitDelay: '<S61>/UnitDelay' */
    AirSysTrb_DWork.UnitDelay_c = localTmpSignalConversionAtAi_dj;

    /* Update for UnitDelay: '<S61>/UnitDelay1' incorporates:
     *  Constant: '<S61>/NotCLR2'
     */
    AirSysTrb_DWork.UnitDelay_je = TRUE;

    /* Update for UnitDelay: '<S93>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_c = localLO3;

    /* Update for UnitDelay: '<S89>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_o = localSum;

    /* Update for UnitDelay: '<S94>/Unit Delay' */
    AirSysTrb_DWork.UnitDelay_DSTATE_em = localLogicalOperator2;

    /* Update for UnitDelay: '<S85>/UnitDelay' */
    AirSysTrb_DWork.UnitDelay_b = localTmpSignalConversionAtCoP_o;

    /* Update for UnitDelay: '<S85>/UnitDelay1' incorporates:
     *  Constant: '<S85>/NotCLR2'
     */
    AirSysTrb_DWork.UnitDelay_n = TRUE;
  }

  /* end of Outputs for SubSystem: '<S53>/F01_FrzInh' */

  /* end of Outputs for SubSystem: '<S11>/F01_TipOutMgr' */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&localTmpSignalConversionAtAirSy);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_2' */
  AirSysTrb_B.DTConv_Single_To_UFix_2[0] = ((Float32)
    localTmpSignalConversionAtAirSy[0]) * 1.525878906E-005F;
  AirSysTrb_B.DTConv_Single_To_UFix_2[1] = ((Float32)
    localTmpSignalConversionAtAirSy[1]) * 1.525878906E-005F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_5' */
  localDTConv_Single_To_UFix_14 = (Float32)localTmpSignalConversionAtExt_n;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsCmprReqFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsCmprReqFil_INPUT'
   */
  Rte_Read_R_AirSys_pUsCmprReqFil_AirSys_pUsCmprReqFil
    (&localTmpSignalConversionAtAir_k);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_6' */
  AirSys_pUsCmprReqFilPrev = ((Float32)localTmpSignalConversionAtAir_k) * 8.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pDsCmprReqFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pDsCmprReqFil_INPUT'
   */
  Rte_Read_R_AirSys_pDsCmprReqFil_AirSys_pDsCmprReqFil
    (&localTmpSignalConversionAtAir_i);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_7' */
  AirSys_pDsCmprReqFilPrev = ((Float32)localTmpSignalConversionAtAir_i) * 8.0F;

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_mfAirThrReqFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_mfAirThrReqFil_INPUT'
   */
  Rte_Read_R_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil
    (&localTmpSignalConversionAtAir_d);

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_8' */
  AirSys_mfAirThrReqFilPrev = ((Float32)localTmpSignalConversionAtAir_d) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S11>/DTConv_Single_To_UFix_9' */
  AirSys_pUsThrReqFilPrev = ((Float32)localTmpSignalConversionAtAir_c) * 8.0F;

  /* Outputs for atomic SubSystem: '<S11>/F02_FrzFilt'
   * Block description for '<S11>/F02_FrzFilt':
   *  01460_10_02799_2.FR.8.2
   *
   * Block requirements for '<S11>/F02_FrzFilt':
   *  1. SubSystem "F02_FrzFilt" !Trace_To : VEMS_R_10_07036_020.03 ;
   */

  /* Switch: '<S54>/Switch2' incorporates:
   *  DataTypeConversion: '<S11>/DTConv_Single_To_UFix_3'
   *  UnitDelay: '<S105>/Unit Delay'
   */
  if (localTmpSignalConversionAtAi_dj) {
    localSwitch2 = AirSysTrb_DWork.UnitDelay_DSTATE;
  } else {
    localSwitch2 = ((Float32)localTmpSignalConversionAtAir_l) * 8.0F;
  }

  /* DataTypeConversion: '<S96>/Data Type Conversion' */
  localLookUpTable = (UInt16)((SInt32)localDTConv_Single_To_UFix_14);

  /* Lookup: '<S96>/Look-Up Table'
   * About '<S96>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localDataTypeConversion), (&(AirSys_facFilGainUsThrPres_T[0])),
                 localLookUpTable, (&(Ext_nEngRef2_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S96>/Data Type Duplicate1'
   *
   * Regarding '<S96>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Saturate Block: '<S100>/Saturation'
   *
   * Regarding '<S100>/Saturation':
   *   Eliminated Saturate block
   */

  /* Sum: '<S100>/Sum2' incorporates:
   *  Constant: '<S100>/Constant1'
   *  Product: '<S112>/Divide'
   *  Product: '<S113>/Divide'
   *  Sum: '<S100>/Add1'
   */
  localSum2 = ((1.0F - (((Float32)localDataTypeConversion) * 1.525878906E-005F))
               * AirSys_pUsThrReqFilPrev) + ((((Float32)localDataTypeConversion)
    * 1.525878906E-005F) * localSwitch2);

  /* Switch: '<S54>/Switch3' incorporates:
   *  DataTypeConversion: '<S11>/DTConv_Single_To_UFix_1'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pDsCmprReq_irvOutport2'
   *  UnitDelay: '<S103>/Unit Delay'
   */
  if (localTmpSignalConversionAtAi_dj) {
    localSwitch3 = AirSysTrb_DWork.UnitDelay_DSTATE_l;
  } else {
    localSwitch3 = ((Float32)
                    Rte_IrvRead_RE_AirSysTrb_005_TEV_AirSys_pDsCmprReq_irv()) *
      8.0F;
  }

  /* DataTypeConversion: '<S95>/Data Type Conversion' */
  localDataTypeConversion = (UInt16)((SInt32)localDTConv_Single_To_UFix_14);

  /* Lookup: '<S95>/Look-Up Table'
   * About '<S95>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^-16
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable), (&(AirSys_facFilGainTrbMod_T[0])),
                 localDataTypeConversion, (&(Ext_nEngRef2_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S95>/Data Type Duplicate1'
   *
   * Regarding '<S95>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Saturate Block: '<S97>/Saturation'
   *
   * Regarding '<S97>/Saturation':
   *   Eliminated Saturate block
   */

  /* Saturate Block: '<S98>/Saturation'
   *
   * Regarding '<S98>/Saturation':
   *   Eliminated Saturate block
   */

  /* Saturate Block: '<S99>/Saturation'
   *
   * Regarding '<S99>/Saturation':
   *   Eliminated Saturate block
   */

  /* Sum: '<S98>/Sum2' incorporates:
   *  Constant: '<S98>/Constant1'
   *  Product: '<S108>/Divide'
   *  Product: '<S109>/Divide'
   *  Sum: '<S98>/Add1'
   */
  localDTConv_Single_To_UFix_14 = ((1.0F - (((Float32)localLookUpTable) *
    1.525878906E-005F)) * AirSys_pDsCmprReqFilPrev) + ((((Float32)
    localLookUpTable) * 1.525878906E-005F) * localSwitch3);

  /* Switch: '<S54>/Switch4' incorporates:
   *  DataTypeConversion: '<S11>/DTConv_Single_To_UFix_4'
   *  SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsCmprReq_irvOutport2'
   *  UnitDelay: '<S102>/Unit Delay'
   */
  if (localTmpSignalConversionAtAi_dj) {
    localSwitch4 = AirSysTrb_DWork.UnitDelay_DSTATE_b;
  } else {
    localSwitch4 = ((Float32)
                    Rte_IrvRead_RE_AirSysTrb_005_TEV_AirSys_pUsCmprReq_irv()) *
      8.0F;
  }

  /* Switch: '<S54>/Switch1' incorporates:
   *  UnitDelay: '<S104>/Unit Delay'
   */
  if (localTmpSignalConversionAtAi_dj) {
    localSwitch1 = AirSysTrb_DWork.UnitDelay_DSTATE_m;
  } else {
    localSwitch1 = AirSysTrb_B.DTConv_Single_To_UFix_2[0];
  }

  /* Update for UnitDelay: '<S105>/Unit Delay' */
  AirSysTrb_DWork.UnitDelay_DSTATE = localSwitch2;

  /* Update for UnitDelay: '<S103>/Unit Delay' */
  AirSysTrb_DWork.UnitDelay_DSTATE_l = localSwitch3;

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  AirSysTrb_DWork.UnitDelay_DSTATE_b = localSwitch4;

  /* Update for UnitDelay: '<S104>/Unit Delay' */
  AirSysTrb_DWork.UnitDelay_DSTATE_m = localSwitch1;

  /* end of Outputs for SubSystem: '<S11>/F02_FrzFilt' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Byp_Fonction_SC'
   *  Constant: '<S47>/Int_BypC'
   *  Constant: '<S99>/Constant1'
   *  DataTypeConversion: '<S47>/Data Type Conversion'
   *  Product: '<S110>/Divide'
   *  Product: '<S111>/Divide'
   *  Sum: '<S99>/Add1'
   *  Sum: '<S99>/Sum2'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_c = AirSys_mfAirThrReqFil_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)(((1.0F - (((Float32)localLookUpTable) *
      1.525878906E-005F)) * AirSys_mfAirThrReqFilPrev) + ((((Float32)
      localLookUpTable) * 1.525878906E-005F) * localSwitch1)), 16);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtAir_c = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtAir_c = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_c = MAX_uint16_T;
    }
  }

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Byp_Fonction_SC'
   *  Constant: '<S48>/Int_BypC'
   *  DataTypeConversion: '<S48>/Data Type Conversion'
   *  Sum: '<S54>/Add'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    locallocalSum = AirSys_pDifDsCmprUsThrReq_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)(localDTConv_Single_To_UFix_14 - localSum2),
      -3);
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        locallocalSum = (SInt16)localtmp;
      } else {
        locallocalSum = MIN_int16_T;
      }
    } else {
      locallocalSum = MAX_int16_T;
    }
  }

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Byp_Fonction_SC'
   *  Constant: '<S49>/Int_BypC'
   *  DataTypeConversion: '<S49>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_l = AirSys_pDsCmprReqFil_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)localDTConv_Single_To_UFix_14, -3);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtAir_l = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtAir_l = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_l = MAX_uint16_T;
    }
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Byp_Fonction_SC'
   *  Constant: '<S50>/Int_BypC'
   *  Constant: '<S97>/Constant1'
   *  DataTypeConversion: '<S50>/Data Type Conversion'
   *  Product: '<S106>/Divide'
   *  Product: '<S107>/Divide'
   *  Sum: '<S97>/Add1'
   *  Sum: '<S97>/Sum2'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_n = AirSys_pUsCmprReqFil_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)(((1.0F - (((Float32)localLookUpTable) *
      1.525878906E-005F)) * AirSys_pUsCmprReqFilPrev) + ((((Float32)
      localLookUpTable) * 1.525878906E-005F) * localSwitch4)), -3);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtExt_n = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtExt_n = 0U;
      }
    } else {
      localTmpSignalConversionAtExt_n = MAX_uint16_T;
    }
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Byp_Fonction_SC'
   *  Constant: '<S51>/Int_BypC'
   *  DataTypeConversion: '<S51>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_k = AirSys_pUsThrReqFil_B;
  } else {
    localtmp = ACTEMS_LdexpF((Float32d)localSum2, -3);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtAir_k = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtAir_k = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_k = MAX_uint16_T;
    }
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Byp_Fonction_SC'
   *  Constant: '<S52>/Int_BypC'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAi_dj = AirSys_bAcvFrzMod_B;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_bAcvFrzModInport2' */
  Rte_Write_P_AirSys_bAcvFrzMod_AirSys_bAcvFrzMod
    (localTmpSignalConversionAtAi_dj);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_mfAirThrReqFilInport2' */
  Rte_Write_P_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil
    (localTmpSignalConversionAtAir_c);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pDifDsCmprUsThrReqInport2' */
  Rte_Write_P_AirSys_pDifDsCmprUsThrReq_AirSys_pDifDsCmprUsThrReq(locallocalSum);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pDsCmprReqFilInport2' */
  Rte_Write_P_AirSys_pDsCmprReqFil_AirSys_pDsCmprReqFil
    (localTmpSignalConversionAtAir_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsCmprReqFilInport2' */
  Rte_Write_P_AirSys_pUsCmprReqFil_AirSys_pUsCmprReqFil
    (localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAirSys_pUsThrReqFilInport2' */
  Rte_Write_P_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil
    (localTmpSignalConversionAtAir_k);
}

/* Start for exported function: RE_AirSysTrb_004_TEV */
void RE_AirSysTrb_004_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F04_DsCmprPresReqClcn'
   *
   * Block requirements for '<S1>/F04_DsCmprPresReqClcn':
   *  1. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_009.01 ;
   *  2. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_010.01 ;
   *  3. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_012.01 ;
   *  4. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  5. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  6. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  7. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_041.01 ;
   */
}

/* Output and update for exported function: RE_AirSysTrb_004_TEV */
void RE_AirSysTrb_004_TEV(void)
{
  /* local block i/o variables */
  Float32 localSubtract1;
  UInt16 localLookUpTable_j;
  UInt16 localTmpSignalConversionAtAi_ma;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F04_DsCmprPresReqClcn'
   *
   * Block requirements for '<S1>/F04_DsCmprPresReqClcn':
   *  1. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_009.01 ;
   *  2. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_010.01 ;
   *  3. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_012.01 ;
   *  4. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  5. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  6. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  7. SubSystem "F04_DsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_041.01 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&AirSysTrb_B.TmpSignalConversionAtAirSys_p_p);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_pUsThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReq_INPUT'
   */
  Rte_Read_R_AirSys_pUsThrReq_AirSys_pUsThrReq(&localTmpSignalConversionAtAi_ma);

  /* Lookup: '<S44>/Look-Up Table'
   * About '<S44>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_j), (&(Air_pLossCAC_T[0])),
                 AirSysTrb_B.TmpSignalConversionAtAirSys_p_p[0],
                 (&(Air_mfAirRef1_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S44>/Data Type Duplicate1'
   *
   * Regarding '<S44>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Sum: '<S10>/Subtract1' */
  localSubtract1 = (Float32)((localTmpSignalConversionAtAi_ma << 3) +
    (localLookUpTable_j << 3));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S46>/autosar_testpoint1' */

  /* S-Function Block: <S46>/autosar_testpoint1 */
  AirSys_pUsCmprReq_IRV_MP = localSubtract1;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAirSys_pDsCmprReq_irvInport2' incorporates:
   *  DataTypeConversion: '<S10>/DTConv_Single_To_UFix_1'
   */
  localtmp = localSubtract1;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtAi_ma = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtAi_ma = 0U;
    }
  } else {
    localTmpSignalConversionAtAi_ma = MAX_uint16_T;
  }

  Rte_IrvWrite_RE_AirSysTrb_004_TEV_AirSys_pDsCmprReq_irv
    (localTmpSignalConversionAtAi_ma);
}

/* Start for exported function: RE_AirSysTrb_003_TEV */
void RE_AirSysTrb_003_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F03_UsCmprPresReqClcn'
   *
   * Block requirements for '<S1>/F03_UsCmprPresReqClcn':
   *  1. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_005.01 ;
   *  2. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_006.01 ;
   *  3. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_008.01 ;
   *  4. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  5. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  6. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  7. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_040.01 ;
   */
}

/* Output and update for exported function: RE_AirSysTrb_003_TEV */
void RE_AirSysTrb_003_TEV(void)
{
  /* local block i/o variables */
  Float32 localSubtract1_e;
  UInt16 localDataTypeConversion_o;
  UInt16 localLookUpTable_h;
  UInt16 localTmpSignalConversionAtUsThr;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F03_UsCmprPresReqClcn'
   *
   * Block requirements for '<S1>/F03_UsCmprPresReqClcn':
   *  1. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_005.01 ;
   *  2. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_006.01 ;
   *  3. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_008.01 ;
   *  4. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  5. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  6. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  7. SubSystem "F03_UsCmprPresReqClcn" !Trace_To : VEMS_R_10_07036_040.01 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&AirSysTrb_B.TmpSignalConversionAtAirSys_p_m);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S41>/Data Type Conversion' */
  localDataTypeConversion_o = AirSysTrb_B.TmpSignalConversionAtAirSys_p_m[0];

  /* Lookup: '<S41>/Look-Up Table'
   * About '<S41>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_h), (&(Air_pLossAirFil_T[0])),
                 localDataTypeConversion_o, (&(Air_mfAirRef1_A[0])), 15U);

  /* DataTypeDuplicate Block: '<S41>/Data Type Duplicate1'
   *
   * Regarding '<S41>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Sum: '<S9>/Subtract1' */
  localSubtract1_e = (Float32)((localTmpSignalConversionAtUsThr << 3) -
    (localLookUpTable_h << 3));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S43>/autosar_testpoint1' */

  /* S-Function Block: <S43>/autosar_testpoint1 */
  AirSys_pUsCmprReq_IRV_MP = localSubtract1_e;

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAirSys_pUsCmprReq_irvInport2' incorporates:
   *  DataTypeConversion: '<S9>/DTConv_Single_To_UFix_1'
   */
  localtmp = localSubtract1_e;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localTmpSignalConversionAtUsThr = (UInt16)localtmp;
    } else {
      localTmpSignalConversionAtUsThr = 0U;
    }
  } else {
    localTmpSignalConversionAtUsThr = MAX_uint16_T;
  }

  Rte_IrvWrite_RE_AirSysTrb_003_TEV_AirSys_pUsCmprReq_irv
    (localTmpSignalConversionAtUsThr);
}

/* Start for exported function: RE_AirSysTrb_002_TEV */
void RE_AirSysTrb_002_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F02_UsThrPresReq'
   *
   * Block requirements for '<S1>/F02_UsThrPresReq':
   *  1. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_001.01 ;
   *  2. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_002.01 ;
   *  3. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_004.01 ;
   *  4. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  5. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_022.01 ;
   *  6. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  7. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_024.01 ;
   *  8. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  9. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_026.01 ;
   *  10. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_039.01 ;
   */
}

/* Output and update for exported function: RE_AirSysTrb_002_TEV */
void RE_AirSysTrb_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion2;
  UInt16 localLookUpTable_d;
  Float32 localDivide_o;
  Float32 localMinMax4;
  UInt16 localTmpSignalConversionAtAi_if[2];
  UInt16 localTmpSignalConversionAtAir_n;
  UInt8 localTmpSignalConversionAtUsT_k;
  UInt16 localTmpSignalConversionAtAi_lc[2];
  UInt16 localTmpSignalConversionAtUsT_j;
  Float32d localtmp;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F02_UsThrPresReq'
   *
   * Block requirements for '<S1>/F02_UsThrPresReq':
   *  1. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_001.01 ;
   *  2. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_002.01 ;
   *  3. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_004.01 ;
   *  4. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  5. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_022.01 ;
   *  6. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  7. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_024.01 ;
   *  8. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  9. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_026.01 ;
   *  10. SubSystem "F02_UsThrPresReq" !Trace_To : VEMS_R_10_07036_039.01 ;
   */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&localTmpSignalConversionAtAi_if);

  /* DataTypeConversion: '<S8>/DTConv_Single_To_UFix_5' */
  AirSysTrb_B.DTConv_Single_To_UFix_5[0] = ((Float32)
    localTmpSignalConversionAtAi_if[0]) * 1.525878906E-005F;
  AirSysTrb_B.DTConv_Single_To_UFix_5[1] = ((Float32)
    localTmpSignalConversionAtAi_if[1]) * 1.525878906E-005F;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_arThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_arThrReq'
   */
  Rte_Read_R_AirSys_arThrReq_AirSys_arThrReq(&localTmpSignalConversionAtAir_n);

  /* Product: '<S27>/Divide' incorporates:
   *  DataTypeConversion: '<S8>/DTConv_Single_To_UFix_3'
   */
  localDivide_o = AirSysTrb_B.DTConv_Single_To_UFix_5[0] / (((Float32)
    localTmpSignalConversionAtAir_n) * 5.960464478E-008F);

  /* Outputs for atomic SubSystem: '<S27>/If Action Subsystem3' */

  /* Switch: '<S40>/Switch1' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Constant: '<S40>/Constant2'
   *  Constant: '<S40>/Constant3'
   *  Logic: '<S40>/Logical Operator1'
   *  RelationalOperator: '<S40>/Relational Operator'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  RelationalOperator: '<S40>/Relational Operator3'
   *  Saturate: '<S40>/Saturation'
   */
  if (((localDivide_o != localDivide_o) || (localDivide_o > 1.0E+007F)) ||
      (-1.0E+007F > localDivide_o)) {
    localDivide_o = 0.0F;
  } else {
    localDivide_o = rt_SATURATE(localDivide_o, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtUsThrM_tSqrtInAirOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tSqrtInAir'
   */
  Rte_Read_R_UsThrM_tSqrtInAir_UsThrM_tSqrtInAir
    (&localTmpSignalConversionAtUsT_k);

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_prm_pInMnfReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_pInMnfReq'
   */
  Rte_Read_R_AirSys_prm_pInMnfReq_AirSys_prm_pInMnfReq
    (&localTmpSignalConversionAtAi_lc);

  /* DataTypeConversion: '<S8>/DTConv_Single_To_UFix_1' */
  AirSysTrb_B.DTConv_Single_To_UFix_1[0] = ((Float32)
    localTmpSignalConversionAtAi_lc[0]) * 8.0F;
  AirSysTrb_B.DTConv_Single_To_UFix_1[1] = ((Float32)
    localTmpSignalConversionAtAi_lc[1]) * 8.0F;

  /* Product: '<S26>/Divide' incorporates:
   *  DataTypeConversion: '<S8>/DTConv_Single_To_UFix_2'
   *  Product: '<S30>/Divide'
   */
  localDivide_o = ((((Float32)localTmpSignalConversionAtUsT_k) * 0.125F) *
                   localDivide_o) / AirSysTrb_B.DTConv_Single_To_UFix_1[0];

  /* Outputs for atomic SubSystem: '<S26>/If Action Subsystem3' */

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant2'
   *  Constant: '<S38>/Constant3'
   *  Logic: '<S38>/Logical Operator1'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  RelationalOperator: '<S38>/Relational Operator1'
   *  RelationalOperator: '<S38>/Relational Operator3'
   *  Saturate: '<S38>/Saturation'
   */
  if (((localDivide_o != localDivide_o) || (localDivide_o > 1.0E+007F)) ||
      (-1.0E+007F > localDivide_o)) {
    localDivide_o = 0.0F;
  } else {
    localDivide_o = rt_SATURATE(localDivide_o, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S26>/If Action Subsystem3' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S8>/ConstVal_2'
   *  RelationalOperator: '<S34>/UpperRelop'
   */
  if (localDivide_o < 0.0F) {
    localMinMax4 = 0.0F;
  } else {
    localMinMax4 = localDivide_o;
  }

  /* Switch: '<S34>/Switch2' incorporates:
   *  Constant: '<S8>/ConstVal'
   *  RelationalOperator: '<S34>/LowerRelop1'
   */
  if (localDivide_o > 0.0625F) {
    localMinMax4 = 0.0625F;
  }

  /* DataTypeConversion: '<S8>/SignalConversion' */
  localtmp = localMinMax4;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 20);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion2 = (UInt16)localtmp;
    } else {
      localDataTypeConversion2 = 0U;
    }
  } else {
    localDataTypeConversion2 = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S8>/MemoryStore1' */
  AirSys_facRatPresThrClcn_MP = localDataTypeConversion2;

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  localtmp = localMinMax4;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 20);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion2 = (UInt16)localtmp;
    } else {
      localDataTypeConversion2 = 0U;
    }
  } else {
    localDataTypeConversion2 = MAX_uint16_T;
  }

  /* Lookup: '<S22>/Look-Up Table'
   * About '<S22>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-20
   * Output0 Data Type:  Fixed Point    U16  2^-13
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_d), (&(AirSys_rAirPresThr_T[0])),
                 localDataTypeConversion2, (&(AirSys_facRatPresThrClcn_A[0])),
                 8U);

  /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate1'
   *
   * Regarding '<S22>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S8>/AirSys_pLossAirThrMax_C'
   *  Sum: '<S8>/Sum1'
   */
  localDivide_o = ((((Float32)AirSys_pLossAirThrMax_C) * 8.0F) +
                   AirSysTrb_B.DTConv_Single_To_UFix_1[0]) /
    AirSysTrb_B.DTConv_Single_To_UFix_1[0];

  /* Outputs for atomic SubSystem: '<S25>/If Action Subsystem3' */

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant2'
   *  Constant: '<S36>/Constant3'
   *  Logic: '<S36>/Logical Operator1'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  RelationalOperator: '<S36>/Relational Operator1'
   *  RelationalOperator: '<S36>/Relational Operator3'
   *  Saturate: '<S36>/Saturation'
   */
  if (((localDivide_o != localDivide_o) || (localDivide_o > 1.0E+007F)) ||
      (-1.0E+007F > localDivide_o)) {
    localDivide_o = 0.0F;
  } else {
    localDivide_o = rt_SATURATE(localDivide_o, -1.0E+007F, 1.0E+007F);
  }

  /* end of Outputs for SubSystem: '<S25>/If Action Subsystem3' */

  /* DataTypeConversion: '<S25>/Data Type Conversion2' */
  localtmp = localDivide_o;
  localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), 13);
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localDataTypeConversion2 = (UInt16)localtmp;
    } else {
      localDataTypeConversion2 = 0U;
    }
  } else {
    localDataTypeConversion2 = MAX_uint16_T;
  }

  /* MinMax: '<S8>/MinMax3' */
  localTmpSignalConversionAtAir_n = localLookUpTable_d;
  if (localDataTypeConversion2 < localLookUpTable_d) {
    localTmpSignalConversionAtAir_n = localDataTypeConversion2;
  }

  /* Product: '<S31>/Divide' */
  localMinMax4 = (((Float32)localTmpSignalConversionAtAir_n) * 0.0001220703125F)
    * AirSysTrb_B.DTConv_Single_To_UFix_1[0];

  /* SignalConversion: '<S8>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsT_j);

  /* DataTypeConversion: '<S8>/DTConv_Single_To_UFix_4' */
  localDivide_o = ((Float32)localTmpSignalConversionAtUsT_j) * 8.0F;

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  MinMax: '<S8>/MinMax4'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAir_n = AirSys_pUsThrReq_B;
  } else {
    localtmp = rt_MAXf(localMinMax4, localDivide_o);
    localtmp = ACTEMS_LdexpF((Float32d)((Float32)localtmp), -3);
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtAir_n = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtAir_n = 0U;
      }
    } else {
      localTmpSignalConversionAtAir_n = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S8>/TmpSignal ConversionAtAirSys_pUsThrReqInport2' */
  Rte_Write_P_AirSys_pUsThrReq_AirSys_pUsThrReq(localTmpSignalConversionAtAir_n);
}

/* Start for exported function: RE_AirSysTrb_001_MSE */
void RE_AirSysTrb_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_AirSysTrb_init'
   *
   * Block requirements for '<S1>/F00_AirSysTrb_init':
   *  1. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_003.01 ;
   *  2. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_005.01 ;
   *  3. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_006.01 ;
   *  4. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_007.01 ;
   *  5. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_009.01 ;
   *  6. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_010.01 ;
   *  7. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_011.01 ;
   *  8. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_013.03 ;
   *  9. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_014.03 ;
   *  10. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_015.01 ;
   *  11. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  12. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  13. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  14. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  15. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  16. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  17. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_030.01 ;
   *  18. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_031.01 ;
   *  19. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_032.01 ;
   *  20. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_033.01 ;
   *  21. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_034.01 ;
   *  22. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_035.01 ;
   *  23. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_036.01 ;
   *  24. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_038.01 ;
   */
}

/* Output and update for exported function: RE_AirSysTrb_001_MSE */
void RE_AirSysTrb_001_MSE(void)
{
  Boolean localSwitch_dg;
  UInt16 localSwitch_ew;
  SInt16 localSwitch_lg;
  UInt16 localTmpSignalConversionAtUsT_g;
  UInt16 localAirSys_pUsCmprReq_irv_p;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_AirSysTrb_init'
   *
   * Block requirements for '<S1>/F00_AirSysTrb_init':
   *  1. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_003.01 ;
   *  2. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_005.01 ;
   *  3. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_006.01 ;
   *  4. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_007.01 ;
   *  5. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_009.01 ;
   *  6. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_010.01 ;
   *  7. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_011.01 ;
   *  8. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_013.03 ;
   *  9. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_014.03 ;
   *  10. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_015.01 ;
   *  11. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_021.01 ;
   *  12. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_023.01 ;
   *  13. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_025.01 ;
   *  14. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_027.01 ;
   *  15. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_028.01 ;
   *  16. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_029.01 ;
   *  17. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_030.01 ;
   *  18. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_031.01 ;
   *  19. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_032.01 ;
   *  20. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_033.01 ;
   *  21. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_034.01 ;
   *  22. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_035.01 ;
   *  23. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_036.01 ;
   *  24. SubSystem "F00_AirSysTrb_init" !Trace_To : VEMS_R_10_07036_038.01 ;
   */

  /* user code (Output function Body for TID6) */
  Runnable_AirSysTrb_Init();

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   *  Constant: '<S7>/Constant'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_dg = AirSys_bAcvFrzMod_B;
  } else {
    localSwitch_dg = FALSE;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_bAcvFrzModInport2' */
  Rte_Write_P_AirSys_bAcvFrzMod_AirSys_bAcvFrzMod(localSwitch_dg);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_prm_mfAirThrReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_prm_mfAirThrReq'
   */
  Rte_Read_R_AirSys_prm_mfAirThrReq_AirSys_prm_mfAirThrReq
    (&AirSysTrb_B.TmpSignalConversionAtAirSys_prm);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Byp_Fonction_SC'
   *  Constant: '<S12>/Int_BypC'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_ew = AirSys_mfAirThrReqFil_B;
  } else {
    localSwitch_ew = AirSysTrb_B.TmpSignalConversionAtAirSys_prm[0];
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_mfAirThrReqFilInport2' */
  Rte_Write_P_AirSys_mfAirThrReqFil_AirSys_mfAirThrReqFil(localSwitch_ew);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Byp_Fonction_SC'
   *  Constant: '<S13>/Int_BypC'
   *  Constant: '<S7>/Constant2'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_lg = AirSys_pDifDsCmprUsThrReq_B;
  } else {
    localSwitch_lg = 0;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pDifDsCmprUsThrReqInport2' */
  Rte_Write_P_AirSys_pDifDsCmprUsThrReq_AirSys_pDifDsCmprUsThrReq(localSwitch_lg);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pUsThrMesCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrMesCor'
   */
  Rte_Read_R_UsThrM_pUsThrMesCor_UsThrM_pUsThrMesCor
    (&localTmpSignalConversionAtUsT_g);

  /* DataTypeConversion: '<S7>/DTConv_Single_To_UFix_2' */
  AirSys_pDsCmprReq_IRV_MP = ((Float32)localTmpSignalConversionAtUsT_g) * 8.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S20>/autosar_testpoint1' */

  /* S-Function Block: <S20>/autosar_testpoint1 */

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Byp_Fonction_SC'
   *  Constant: '<S14>/Int_BypC'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_ew = AirSys_pDsCmprReqFil_B;
  } else {
    localSwitch_ew = localTmpSignalConversionAtUsT_g;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pDsCmprReqFilInport2' */
  Rte_Write_P_AirSys_pDsCmprReqFil_AirSys_pDsCmprReqFil(localSwitch_ew);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pDsCmprReq_irvInport2' incorporates:
   *  SignalConversion: '<S7>/SignalConversion'
   */
  Rte_IrvWrite_RE_AirSysTrb_001_MSE_AirSys_pDsCmprReq_irv
    (localTmpSignalConversionAtUsT_g);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&AirSysTrb_B.TmpSignalConversionAtUsThrM_pAi);

  /* DataTypeConversion: '<S7>/DTConv_Single_To_UFix_1' */
  AirSys_pUsCmprReq_IRV_MP = ((Float32)
    AirSysTrb_B.TmpSignalConversionAtUsThrM_pAi) * 8.0F;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S21>/autosar_testpoint1' */

  /* S-Function Block: <S21>/autosar_testpoint1 */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Byp_Fonction_SC'
   *  Constant: '<S15>/Int_BypC'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_ew = AirSys_pUsCmprReqFil_B;
  } else {
    localSwitch_ew = AirSysTrb_B.TmpSignalConversionAtUsThrM_pAi;
  }

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localTmpSignalConversionAtUsT_g = AirSys_pUsThrReq_B;
  } else {
    localTmpSignalConversionAtUsT_g =
      AirSysTrb_B.TmpSignalConversionAtUsThrM_pAi;
  }

  /* SignalConversion: '<S7>/SignalConversion1' */
  localAirSys_pUsCmprReq_irv_p = AirSysTrb_B.TmpSignalConversionAtUsThrM_pAi;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pUsCmprReqFilInport2' */
  Rte_Write_P_AirSys_pUsCmprReqFil_AirSys_pUsCmprReqFil(localSwitch_ew);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pUsCmprReq_irvInport2' */
  Rte_IrvWrite_RE_AirSysTrb_001_MSE_AirSys_pUsCmprReq_irv
    (localAirSys_pUsCmprReq_irv_p);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pUsThrReqInport2' */
  Rte_Write_P_AirSys_pUsThrReq_AirSys_pUsThrReq(localTmpSignalConversionAtUsT_g);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pUsThrReq_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AirSys_pUsThrReq_INPUT'
   */
  Rte_Read_R_AirSys_pUsThrReq_AirSys_pUsThrReq
    (&AirSysTrb_B.TmpSignalConversionAtAirSys_pUs);

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   */
  if (AIRSYSTRB_ACTIVE_BYP_C) {
    localSwitch_ew = AirSys_pUsThrReqFil_B;
  } else {
    localSwitch_ew = AirSysTrb_B.TmpSignalConversionAtAirSys_pUs;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtAirSys_pUsThrReqFilInport2' */
  Rte_Write_P_AirSys_pUsThrReqFil_AirSys_pUsThrReqFil(localSwitch_ew);
}

/* Model initialize function */
void Runnable_AirSysTrb_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   */
  RE_AirSysTrb_005_TEV_Start();
  RE_AirSysTrb_004_TEV_Start();
  RE_AirSysTrb_003_TEV_Start();
  RE_AirSysTrb_002_TEV_Start();
  RE_AirSysTrb_001_MSE_Start();
}

#define AirSysTrb_STOP_SEC_CODE
#include "AirSysTrb_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
