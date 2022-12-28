/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AdvPrevKnkT                                             */
/* !Description     : AdvPrevKnkT Software Component                          */
/*                                                                            */
/* !Module          : AdvPrevKnkT                                             */
/* !Description     : AdvPrevKnkT Software Component                          */
/*                                                                            */
/* !File            : AdvPrevKnkT.c                                           */
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
/*   Model name       : AdvPrevKnkT_AUTOSAR.mdl                               */
/*   Root subsystem   : /AdvPrevKnkT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/CAA/M05-AdvPrevKnkT$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   adelvare                               $$Date::   11 Apr 2013 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AdvPrevKnkT.h"
#include "AdvPrevKnkT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S71>/F01_02_04_03_01_Automate' */
#define IN_DECREMENT                   (1U)
#define IN_DEPART                      (2U)
#define IN_INHIBITION                  (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define AdvPrevKnkT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_AdvPrevKnkT AdvPrevKnkT_B;

/* Block states (auto storage) */
D_Work_AdvPrevKnkT AdvPrevKnkT_DWork;

#define AdvPrevKnkT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "AdvPrevKnkT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define ADVPREVKNKT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define ADVPREVKNKT_VEMSRTLIBT_MINOR_VERSION_REQ 0
#define ADVPREVKNKT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ADVPREVKNKT_VEMSRTLIBT_VERSION_REQ (ADVPREVKNKT_VEMSRTLIBT_PATCH_VERSION_REQ + ADVPREVKNKT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ADVPREVKNKT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ADVPREVKNKT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define AdvPrevKnkT_START_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"

void AdvPrevKnkT_ASYNC1(int controlPortIdx)
{
}

/* Start for exported function: RE_AdvPrevKnkT_001_MSE */
void RE_AdvPrevKnkT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F00_AdvPrevKnkT_init'
   *
   * Block requirements for '<S1>/F00_AdvPrevKnkT_init':
   *  1. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_024.01 ;
   *  2. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_042.01 ;
   *  3. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_047.01 ;
   *  4. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_048.01 ;
   */
}

/* Output and update for exported function: RE_AdvPrevKnkT_001_MSE */
void RE_AdvPrevKnkT_001_MSE(void)
{
  Boolean localSwitch_h;
  SInt16 localSwitch_i;
  UInt16 localSwitch;
  UInt8 localSwitch_f;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_AdvPrevKnkT_init'
   *
   * Block requirements for '<S1>/F00_AdvPrevKnkT_init':
   *  1. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_024.01 ;
   *  2. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_042.01 ;
   *  3. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_047.01 ;
   *  4. SubSystem "F00_AdvPrevKnkT_init" !Trace_To : VEMS_R_10_06435_048.01 ;
   */

  /* user code (Output function Body for TID3) */
  Runnable_AdvPrevKnkT_Init();

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Byp_Fonction_SC'
   *  Constant: '<S9>/Int_BypC'
   */
  if (ADVPREVKNKT_ACTIVE_BYP_C) {
    localSwitch_i = IgSys_tDifTAirUsInVlvEstim_B;
  } else {
    localSwitch_i = 0;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_tDifTAirUsInVlvEstimInport2' */
  Rte_Write_P_IgSys_tDifTAirUsInVlvEstim_IgSys_tDifTAirUsInVlvEstim
    (localSwitch_i);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Byp_Fonction_SC'
   *  Constant: '<S7>/Int_BypC'
   */
  if (ADVPREVKNKT_ACTIVE_BYP_C) {
    localSwitch = IgSys_rAirLdClc_B;
  } else {
    localSwitch = 0U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_rAirLdClcInport2' */
  Rte_Write_P_IgSys_rAirLdClc_IgSys_rAirLdClc(localSwitch);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S4>/init1'
   *  Constant: '<S6>/Byp_Fonction_SC'
   *  Constant: '<S6>/Int_BypC'
   */
  if (ADVPREVKNKT_ACTIVE_BYP_C) {
    localSwitch_h = IgSys_bAirLdDynDet_B;
  } else {
    localSwitch_h = FALSE;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_bAirLdDynDetInport2' */
  Rte_Write_P_IgSys_bAirLdDynDet_IgSys_bAirLdDynDet(localSwitch_h);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S4>/init'
   *  Constant: '<S8>/Byp_Fonction_SC'
   *  Constant: '<S8>/Int_BypC'
   */
  if (ADVPREVKNKT_ACTIVE_BYP_C) {
    localSwitch_f = IgSys_agIgKnkPrevOfs_B;
  } else {
    localSwitch_f = 96U;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtIgSys_agIgKnkPrevOfsInport2' */
  Rte_Write_P_IgSys_agIgKnkPrevOfs_IgSys_agIgKnkPrevOfs(localSwitch_f);
}

/* Start for exported function: RE_AdvPrevKnkT_002 */
void RE_AdvPrevKnkT_002_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_AdvPrevKnkT'
   *
   * Block requirements for '<S1>/F01_AdvPrevKnkT':
   *  1. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_001.01 ;
   *  2. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_002.01 ;
   *  3. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_024.01 ;
   *  4. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_025.01 ;
   *  5. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_026.01 ;
   *  6. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_027.01 ;
   *  7. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_028.01 ;
   *  8. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_029.02 ;
   *  9. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_030.01 ;
   *  10. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_031.01 ;
   *  11. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_032.01 ;
   *  12. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_033.01 ;
   *  13. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_034.01 ;
   *  14. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_035.01 ;
   *  15. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_036.01 ;
   *  16. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_037.01 ;
   *  17. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_038.01 ;
   *  18. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_039.02 ;
   *  19. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_040.01 ;
   *  20. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_041.01 ;
   *  21. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_042.01 ;
   *  22. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_043.01 ;
   *  23. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_044.01 ;
   *  24. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_045.01 ;
   *  25. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_046.01 ;
   *  26. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_047.01 ;
   *  27. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_048.01 ;
   *  28. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_049.01 ;
   *  29. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_050.01 ;
   *  30. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_051.01 ;
   *  31. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_052.01 ;
   *  32. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_053.01 ;
   *  33. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_054.01 ;
   */
}

/* Output and update for exported function: RE_AdvPrevKnkT_002 */
void RE_AdvPrevKnkT_002(void)
{
  /* local block i/o variables */
  SInt16 localDataTypeConversion_o;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtInM_p;
  UInt16 localDataTypeConversion_f;
  UInt16 localTmpSignalConversionAtVeh_s;
  UInt16 localTmpSignalConversionAtInThM;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localMinMax_h;
  UInt16 localDataTypeConversion1_l;
  UInt16 localLookUpTable2D;
  UInt8 localTmpSignalConversionAtCoPt_;
  Boolean localRte_Call_R_FRM_bAcvTCoMesD;
  Boolean localRte_Call_R_FRM_bAcvPAirExt;
  UInt8 localTmpSignalConversionAtIgS_h;
  UInt8 localLookUpTable2D_m;
  UInt8 localLookUpTable2D_c;
  UInt8 localLookUpTable2D_f;
  UInt8 localLookUpTable;
  UInt8 localLookUpTable_h;
  SInt8 localLookUpTable2D_b;
  SInt8 localLookUpTable2D_bx;
  SInt8 localLookUpTable_b;
  SInt8 localLookUpTable2D_d;
  UInt8 localLookUpTable2D_h;
  UInt8 localTmpSignalConversionAtEng_s;
  Boolean localTmpSignalConversionAtIgS_m;
  Float32 localDivide_m;
  Float32 localSaturation01_b;
  Float32 localDataTypeConversion8;
  Float32 localSum1_h;
  Float32 localSwitch1;
  Boolean localIgSys_bAirLdDynDet_n;
  SInt16 localTmpSignalConversionAtExt_t;
  UInt8 localIgSys_agIgKnkPrevOfs;
  UInt16 localIgSys_rAirLdClc;
  SInt16 localIgSys_tDifTAirUsInVlvEstim;
  SInt16 localTmpSignalConversionAtIgS_l;
  UInt16 localTmpSignalConversionAtIgSys;
  UInt8 localTmpSignalConversionAtIgS_a;
  UInt16 localTmpSignalConversionAtAirSy;
  UInt8 localTmpSignalConversionAtExt_l;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtInM_c;
  UInt16 localTmpSignalConversionAtEng_p;
  UInt16 localTmpSignalConversionAtEng_e;
  UInt16 localTmpSignalConversionAtUsThr;
  Float32d localtmp;
  SInt32 localq;
  UInt32 localqY;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_AdvPrevKnkT'
   *
   * Block requirements for '<S1>/F01_AdvPrevKnkT':
   *  1. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_001.01 ;
   *  2. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_002.01 ;
   *  3. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_024.01 ;
   *  4. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_025.01 ;
   *  5. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_026.01 ;
   *  6. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_027.01 ;
   *  7. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_028.01 ;
   *  8. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_029.02 ;
   *  9. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_030.01 ;
   *  10. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_031.01 ;
   *  11. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_032.01 ;
   *  12. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_033.01 ;
   *  13. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_034.01 ;
   *  14. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_035.01 ;
   *  15. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_036.01 ;
   *  16. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_037.01 ;
   *  17. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_038.01 ;
   *  18. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_039.02 ;
   *  19. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_040.01 ;
   *  20. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_041.01 ;
   *  21. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_042.01 ;
   *  22. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_043.01 ;
   *  23. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_044.01 ;
   *  24. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_045.01 ;
   *  25. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_046.01 ;
   *  26. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_047.01 ;
   *  27. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_048.01 ;
   *  28. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_049.01 ;
   *  29. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_050.01 ;
   *  30. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_051.01 ;
   *  31. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_052.01 ;
   *  32. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_053.01 ;
   *  33. SubSystem "F01_AdvPrevKnkT" !Trace_To : VEMS_R_10_06435_054.01 ;
   */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkPrevOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgKnkPrevOfs_INPUT'
   */
  Rte_Read_R_IgSys_agIgKnkPrevOfs_IgSys_agIgKnkPrevOfs
    (&localTmpSignalConversionAtIgS_a);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_bAirLdDynDet_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_bAirLdDynDet_INPUT'
   */
  Rte_Read_R_IgSys_bAirLdDynDet_IgSys_bAirLdDynDet
    (&localTmpSignalConversionAtIgS_m);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_rAirLdClc_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_rAirLdClc_INPUT'
   */
  Rte_Read_R_IgSys_rAirLdClc_IgSys_rAirLdClc(&localTmpSignalConversionAtIgSys);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_tDifTAirUsInVlvEstim_INPUTOutport2' incorporates:
   *  Inport: '<Root>/IgSys_tDifTAirUsInVlvEstim_INPUT'
   */
  Rte_Read_R_IgSys_tDifTAirUsInVlvEstim_IgSys_tDifTAirUsInVlvEstim
    (&localTmpSignalConversionAtIgS_l);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEng_stEruOutport2' incorporates:
   *  Inport: '<Root>/Eng_stEru'
   */
  Rte_Read_R_Eng_stEru_Eng_stEru(&localTmpSignalConversionAtEng_s);

  /* Outputs for atomic SubSystem: '<S5>/F01_01_Condition_d_activation' *
   * Block requirements for '<S5>/F01_01_Condition_d_activation':
   *  1. SubSystem "F01_01_Condition_d_activation" !Trace_To : VEMS_R_10_06435_003.01 ;
   */

  /* Logic: '<S11>/Logical Operator' incorporates:
   *  Constant: '<S11>/Ext_stRun_SC'
   *  Constant: '<S11>/IgSys_bAcvETBMod_C'
   *  Logic: '<S11>/Logical Operator1'
   *  RelationalOperator: '<S11>/Relational Operator'
   */
  IgSys_bAcvKnkPrev = ((!IgSys_bAcvETBMod_C) && (localTmpSignalConversionAtEng_s
    == Ext_stRun_SC));

  /* end of Outputs for SubSystem: '<S5>/F01_01_Condition_d_activation' */

  /* Outputs for enable SubSystem: '<S5>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S10>/Enable'
   *  Logic: '<S5>/Logical Operator'
   *
   * Block requirements for '<S5>/Enabled Subsystem':
   *  1. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_024.01 ;
   *  2. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_042.01 ;
   *  3. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_047.01 ;
   *  4. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_048.01 ;
   *  5. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_051.01 ;
   *  6. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_052.01 ;
   *  7. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_053.01 ;
   *  8. SubSystem "Enabled Subsystem" !Trace_To : VEMS_R_10_06435_054.01 ;
   */
  if (!IgSys_bAcvKnkPrev) {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Byp_Fonction_SC'
     *  Constant: '<S16>/Int_BypC'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_tDifTAirUsInVlvEstim = IgSys_tDifTAirUsInVlvEstim_B;
    } else {
      localIgSys_tDifTAirUsInVlvEstim = localTmpSignalConversionAtIgS_l;
    }

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Byp_Fonction_SC'
     *  Constant: '<S14>/Int_BypC'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_rAirLdClc = IgSys_rAirLdClc_B;
    } else {
      localIgSys_rAirLdClc = localTmpSignalConversionAtIgSys;
    }

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Byp_Fonction_SC'
     *  Constant: '<S13>/Int_BypC'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_bAirLdDynDet_n = IgSys_bAirLdDynDet_B;
    } else {
      localIgSys_bAirLdDynDet_n = localTmpSignalConversionAtIgS_m;
    }

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S15>/Byp_Fonction_SC'
     *  Constant: '<S15>/Int_BypC'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_agIgKnkPrevOfs = IgSys_agIgKnkPrevOfs_B;
    } else {
      localIgSys_agIgKnkPrevOfs = localTmpSignalConversionAtIgS_a;
    }
  }

  /* end of Outputs for SubSystem: '<S5>/Enabled Subsystem' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_rAirLdPredOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdPred'
   */
  Rte_Read_R_EngM_rAirLdPred_EngM_rAirLdPred(&localTmpSignalConversionAtEng_e);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtAirSys_rAirLdReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rAirLdReq'
   */
  Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtVeh_spdVehOutport2' incorporates:
   *  Inport: '<Root>/Veh_spdVeh'
   */
  Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&localTmpSignalConversionAtVeh_s);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtCoPt_noEgdGearCordOutport2' incorporates:
   *  Inport: '<Root>/CoPt_noEgdGearCord'
   */
  Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord
    (&localTmpSignalConversionAtCoPt_);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtInM_concEGREstimOutport2' incorporates:
   *  Inport: '<Root>/InM_concEGREstim'
   */
  Rte_Read_R_InM_concEGREstim_InM_concEGREstim(&localTmpSignalConversionAtInM_c);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtEngM_rMaxTotLdOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMaxTotLd'
   */
  Rte_Read_R_EngM_rMaxTotLd_EngM_rMaxTotLd(&localTmpSignalConversionAtEng_p);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtExt_tiTDCOutport2' incorporates:
   *  Inport: '<Root>/Ext_tiTDC'
   */
  Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&localTmpSignalConversionAtExt_l);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkAdpOfsMvOutport2' incorporates:
   *  Inport: '<Root>/IgSys_agIgKnkAdpOfsMv'
   */
  Rte_Read_R_IgSys_agIgKnkAdpOfsMv_IgSys_agIgKnkAdpOfsMv
    (&localTmpSignalConversionAtIgS_h);

  /* Outputs for enable SubSystem: '<S5>/F01_02_Fonction_cliquetis' incorporates:
   *  EnablePort: '<S12>/IgSys_bAcvKnkPrev'
   *
   * Block requirements for '<S5>/F01_02_Fonction_cliquetis':
   *  1. SubSystem "F01_02_Fonction_cliquetis" !Trace_To : VEMS_R_10_06435_004.01 ;
   */
  if (IgSys_bAcvKnkPrev) {
    /* Outputs for atomic SubSystem: '<S12>/F01_02_01_Calcul_delta_remplissage' *
     * Block requirements for '<S12>/F01_02_01_Calcul_delta_remplissage':
     *  1. SubSystem "F01_02_01_Calcul_delta_remplissage" !Trace_To : VEMS_R_10_06435_005.01 ;
     */

    /* Lookup: '<S31>/Look-Up Table'
     * About '<S31>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable), (&(IgSys_facFil1DeltaAirLdDyn_T[0])),
                  localTmpSignalConversionAtExt_n,
                  (&(IgSys_nEng_facFilDeltaAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate1'
     *
     * Regarding '<S31>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S18>/Data Type Conversion7' incorporates:
     *  Lookup: '<S31>/Look-Up Table'
     */
    localDivide_m = ((Float32)localLookUpTable) * 9.999999776E-003F;

    /* Saturate: '<S42>/Saturation [0-1]' */
    localSaturation01_b = rt_SATURATE(localDivide_m, 0.0F, 1.0F);

    /* DataTypeConversion: '<S18>/Data Type Conversion8' */
    localDataTypeConversion8 = ((Float32)localTmpSignalConversionAtAirSy) *
      6.103515625E-005F;

    /* UnitDelay: '<S41>/UnitDelay' */
    localDivide_m = AdvPrevKnkT_DWork.UnitDelay_m;

    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S18>/const2'
     *  UnitDelay: '<S41>/UnitDelay1'
     */
    if (!AdvPrevKnkT_DWork.UnitDelay_k) {
      localDivide_m = 0.0F;
    }

    /* Sum: '<S42>/Sum1' incorporates:
     *  Product: '<S42>/Product'
     *  Sum: '<S42>/Sum'
     */
    localSum1_h = ((localDataTypeConversion8 - localDivide_m) *
                   localSaturation01_b) + localDivide_m;

    /* DataStoreWrite: '<S18>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)localSum1_h) + 3.0F, 14);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        IgSys_rFil1DeltaAir_MP = (UInt32)localtmp;
      } else {
        IgSys_rFil1DeltaAir_MP = 0U;
      }
    } else {
      IgSys_rFil1DeltaAir_MP = MAX_uint32_T;
    }

    /* Lookup: '<S30>/Look-Up Table'
     * About '<S30>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16( &(localLookUpTable_h), (&(IgSys_facFil2DeltaAirLdDyn_T[0])),
                  localTmpSignalConversionAtExt_n,
                  (&(IgSys_nEng_facFilDeltaAir_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S30>/Data Type Duplicate1'
     *
     * Regarding '<S30>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
     *  Lookup: '<S30>/Look-Up Table'
     */
    localDivide_m = ((Float32)localLookUpTable_h) * 9.999999776E-003F;

    /* Saturate: '<S39>/Saturation [0-1]' */
    localSaturation01_b = rt_SATURATE(localDivide_m, 0.0F, 1.0F);

    /* UnitDelay: '<S38>/UnitDelay' */
    localDivide_m = AdvPrevKnkT_DWork.UnitDelay_l;

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S18>/const1'
     *  UnitDelay: '<S38>/UnitDelay1'
     */
    if (!AdvPrevKnkT_DWork.UnitDelay_f) {
      localDivide_m = 0.0F;
    }

    /* Sum: '<S39>/Sum1' incorporates:
     *  Product: '<S39>/Product'
     *  Sum: '<S39>/Sum'
     */
    localSaturation01_b = ((localSum1_h - localDivide_m) * localSaturation01_b)
      + localDivide_m;

    /* DataStoreWrite: '<S18>/Data Store Write1' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion2'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)localSaturation01_b) + 3.0F, 14);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        IgSys_rFil2DeltaAir_MP = (UInt32)localtmp;
      } else {
        IgSys_rFil2DeltaAir_MP = 0U;
      }
    } else {
      IgSys_rFil2DeltaAir_MP = MAX_uint32_T;
    }

    /* UnitDelay: '<S35>/Unit Delay' */
    localDivide_m = AdvPrevKnkT_DWork.UnitDelay_DSTATE;

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/IgSys_bSelFilTypAirLd_C'
     */
    if (!IgSys_bSelFilTypAirLd_C) {
      localDivide_m = localSaturation01_b;
    }

    /* Sum: '<S18>/Add1' */
    localDivide_m = localSum1_h - localDivide_m;

    /* DataStoreWrite: '<S18>/Data Store Write2' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion4'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)localDivide_m) + 3.0F, 14);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        IgSys_rDeltaAirLdMod2_MP = (UInt32)localtmp;
      } else {
        IgSys_rDeltaAirLdMod2_MP = 0U;
      }
    } else {
      IgSys_rDeltaAirLdMod2_MP = MAX_uint32_T;
    }

    /* Sum: '<S18>/Add' incorporates:
     *  UnitDelay: '<S34>/Unit Delay'
     */
    localSwitch1 = localDataTypeConversion8 -
      AdvPrevKnkT_DWork.UnitDelay_DSTATE_b;

    /* DataStoreWrite: '<S18>/Data Store Write3' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion5'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)localSwitch1) + 3.0F, 14);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        IgSys_rDeltaAirLdMod1_MP = (UInt32)localtmp;
      } else {
        IgSys_rDeltaAirLdMod1_MP = 0U;
      }
    } else {
      IgSys_rDeltaAirLdMod1_MP = MAX_uint32_T;
    }

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/IgSys_bModDeltaAirLdDet_C'
     */
    if (!IgSys_bModDeltaAirLdDet_C) {
      localSwitch1 = localDivide_m;
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion6' incorporates:
     *  Constant: '<S18>/IgSys_facFilDeltaAirLdDyn_C'
     *  Product: '<S36>/Divide'
     */
    localtmp = ACTEMS_LdexpF(((Float32d)((Float32)((((Float32d)
      IgSys_facFilDeltaAirLdDyn_C) * 0.01F) * ((Float32d)localSwitch1)))) + 3.0F, 14);
    if (localtmp < 4.294967296E+009F) {
      if (localtmp >= 0.0F) {
        IgSys_rDeltaAirLdDyn = (UInt32)localtmp;
      } else {
        IgSys_rDeltaAirLdDyn = 0U;
      }
    } else {
      IgSys_rDeltaAirLdDyn = MAX_uint32_T;
    }

    /* Update for UnitDelay: '<S41>/UnitDelay' */
    AdvPrevKnkT_DWork.UnitDelay_m = localSum1_h;

    /* Update for UnitDelay: '<S41>/UnitDelay1' incorporates:
     *  Constant: '<S41>/Constant3'
     */
    AdvPrevKnkT_DWork.UnitDelay_k = TRUE;

    /* Update for UnitDelay: '<S38>/UnitDelay' */
    AdvPrevKnkT_DWork.UnitDelay_l = localSaturation01_b;

    /* Update for UnitDelay: '<S38>/UnitDelay1' incorporates:
     *  Constant: '<S38>/Constant3'
     */
    AdvPrevKnkT_DWork.UnitDelay_f = TRUE;

    /* Update for UnitDelay: '<S35>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE = localSum1_h;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_b = localDataTypeConversion8;

    /* end of Outputs for SubSystem: '<S12>/F01_02_01_Calcul_delta_remplissage' */

    /* Outputs for atomic SubSystem: '<S12>/F01_02_02_Dynamique_de_charge' *
     * Block requirements for '<S12>/F01_02_02_Dynamique_de_charge':
     *  1. SubSystem "F01_02_02_Dynamique_de_charge" !Trace_To : VEMS_R_10_06435_006.01 ;
     *  2. SubSystem "F01_02_02_Dynamique_de_charge" !Trace_To : VEMS_R_10_06435_008.01 ;
     */

    /* Lookup: '<S46>/Look-Up Table'
     * About '<S46>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Fixed Point    U16  2^-14
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localMinMax_h), (&(IgSys_rDeltaAirLdDynThd_T[0])),
                   localTmpSignalConversionAtExt_n, (&(IgSys_nEng_AirLdDet_A[0])),
                   8U);

    /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate1'
     *
     * Regarding '<S46>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  DataTypeConversion: '<S44>/Data Type Conversion2'
     */
    localq = localMinMax_h;
    localqY = (UInt32)(localq + 49152);
    if (localqY < ((UInt32)localq)) {
      localqY = MAX_uint32_T;
    }

    IgSys_bAirLdDynDetWoutTmr = (IgSys_rDeltaAirLdDyn >= localqY);

    /* Outputs for enable SubSystem: '<S19>/F01_02_02_01_Maintien_dynamique_charge' incorporates:
     *  EnablePort: '<S43>/IgSys_bAirLdDynDetWoutTmr'
     *
     * Block requirements for '<S19>/F01_02_02_01_Maintien_dynamique_charge':
     *  1. SubSystem "F01_02_02_01_Maintien_dynamique_charge" !Trace_To : VEMS_R_10_06435_007.01 ;
     */
    if (IgSys_bAirLdDynDetWoutTmr) {
      /* Lookup: '<S45>/Look-Up Table'
       * About '<S45>/Look-Up Table':
       * Input0  Data Type:  Integer        U16
       * Output0 Data Type:  Fixed Point    U16  2^-10  FSlope 1.024
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(IgSys_tiAirLdDynDet), (&(IgSys_tiAirLdDynDet_T[0])),
                     localTmpSignalConversionAtExt_n, (&(IgSys_nEng_AirLdDet_A[0])),
                     8U);

      /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate1'
       *
       * Regarding '<S45>/Data Type Duplicate1':
       *   Unused code path elimination
       */
    }

    /* end of Outputs for SubSystem: '<S19>/F01_02_02_01_Maintien_dynamique_charge' */

    /* MinMax: '<S48>/MinMax' incorporates:
     *  Constant: '<S47>/Constant5'
     */
    localTmpSignalConversionAtIgSys = 10000U;
    if (IgSys_tiAirLdDynDet < 10000) {
      localTmpSignalConversionAtIgSys = IgSys_tiAirLdDynDet;
    }

    localMinMax_h = localTmpSignalConversionAtIgSys;

    /* MinMax: '<S48>/MinMax1' incorporates:
     *  Constant: '<S47>/Constant7'
     */
    localTmpSignalConversionAtIgSys = localMinMax_h;

    /* Sum: '<S47>/Sum1' */
    localqY = (UInt32)(localTmpSignalConversionAtExt_l + localMinMax_h);
    if (localqY > 65535U) {
      localMinMax_h = MAX_uint16_T;
    } else {
      localMinMax_h = (UInt16)localqY;
    }

    /* Switch: '<S47>/Switch3' incorporates:
     *  Logic: '<S47>/Logical Operator'
     *  Logic: '<S47>/Logical Operator1'
     *  Logic: '<S47>/Logical Operator3'
     *  UnitDelay: '<S47>/Unit Delay'
     *  UnitDelay: '<S47>/Unit Delay1'
     */
    if (!(IgSys_bAirLdDynDetWoutTmr && (!AdvPrevKnkT_DWork.UnitDelay1_DSTATE)))
    {
      localMinMax_h = AdvPrevKnkT_DWork.UnitDelay_DSTATE_i;
    }

    /* Sum: '<S47>/Sum3' */
    localq = localMinMax_h - localTmpSignalConversionAtExt_l;
    if (localq <= 0) {
      localIgSys_rAirLdClc = 0U;
    } else {
      localIgSys_rAirLdClc = (UInt16)localq;
    }

    /* RelationalOperator: '<S47>/Relational Operator' incorporates:
     *  Constant: '<S47>/Constant1'
     */
    localTmpSignalConversionAtIgS_m = (localIgSys_rAirLdClc > 0);

    /* DataStoreWrite: '<S44>/MemoryStore1' */
    IgSys_bAcvAirLdDynDet2_MP = localTmpSignalConversionAtIgS_m;

    /* Logic: '<S44>/Logical Operator4' incorporates:
     *  Constant: '<S44>/IgSys_bAcvAirLdDynDet_C'
     */
    localIgSys_bAirLdDynDet_n = ((localTmpSignalConversionAtIgS_m) &&
      IgSys_bAcvAirLdDynDet_C);

    /* Logic: '<S44>/Logical Operator8' incorporates:
     *  Constant: '<S44>/IgSys_bAcvAirLdDynPrevDet_C'
     */
    IgSys_bAirLdDynPrevDynDet = ((localTmpSignalConversionAtIgS_m) &&
      IgSys_bAcvAirLdDynPrevDet_C);

    /* MinMax: '<S49>/MinMax' */
    if (localIgSys_rAirLdClc < localTmpSignalConversionAtIgSys) {
      localTmpSignalConversionAtIgSys = localIgSys_rAirLdClc;
    }

    localMinMax_h = localTmpSignalConversionAtIgSys;

    /* Update for UnitDelay: '<S47>/Unit Delay1' */
    AdvPrevKnkT_DWork.UnitDelay1_DSTATE = IgSys_bAirLdDynDetWoutTmr;

    /* Update for UnitDelay: '<S47>/Unit Delay' incorporates:
     *  Constant: '<S47>/Constant1'
     *  MinMax: '<S49>/MinMax1'
     */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_i = localMinMax_h;

    /* end of Outputs for SubSystem: '<S12>/F01_02_02_Dynamique_de_charge' */

    /* Outputs for atomic SubSystem: '<S12>/F01_02_04_Avance_preventive_dynamique' *
     * Block requirements for '<S12>/F01_02_04_Avance_preventive_dynamique':
     *  1. SubSystem "F01_02_04_Avance_preventive_dynamique" !Trace_To : VEMS_R_10_06435_015.01 ;
     */

    /* Outputs for atomic SubSystem: '<S21>/F01_02_04_01_Calcul_du_retrait_d_avance' *
     * Block requirements for '<S21>/F01_02_04_01_Calcul_du_retrait_d_avance':
     *  1. SubSystem "F01_02_04_01_Calcul_du_retrait_d_avance" !Trace_To : VEMS_R_10_06435_016.01 ;
     */

    /* Lookup2D: '<S73>/Look-Up Table (2-D)'
     * About '<S73>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_m), (&(IgSys_agIgPrevDynOfs_M[0])),
                      localTmpSignalConversionAtExt_n, (&(IgSys_nEng_PrevDynX_A
      [0])), 8U, localTmpSignalConversionAtEngM_, (&(IgSys_rAirLdCor_PrevDynY_A
      [0])), 8U);

    /* DataTypeDuplicate Block: '<S73>/Data Type Duplicate2'
     *
     * Regarding '<S73>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S69>/Data Type Conversion2' incorporates:
     *  Lookup2D: '<S73>/Look-Up Table (2-D)'
     */
    localSaturation01_b = (((Float32)localLookUpTable2D_m) * 0.375F) - 36.0F;

    /* Lookup2D: '<S74>/Look-Up Table (2-D)'
     * About '<S74>/Look-Up Table (2-D)':
     * Input0  Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Input1  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Output0 Data Type:  Fixed Point    S8  2^-5  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S8_U8_U16( &(localLookUpTable2D_b), (&(IgSys_rCorPrevDyn1Ofs_M[0])),
                     localTmpSignalConversionAtIgS_h,
                     (&(IgSys_knkAdp_PrevDynX_A[0])), 8U,
                     localTmpSignalConversionAtInThM,
                     (&(IgSys_tAirUsInVlv_PrevDynY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate2'
     *
     * Regarding '<S74>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S75>/Divide' incorporates:
     *  DataTypeConversion: '<S69>/Data Type Conversion3'
     *  Lookup2D: '<S74>/Look-Up Table (2-D)'
     */
    localSaturation01_b *= ((Float32)localLookUpTable2D_b) * 3.999999911E-002F;

    /* DataStoreWrite: '<S69>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S69>/Data Type Conversion1'
     */
    localtmp = (((Float32d)localSaturation01_b) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        IgSys_agIgPrevDynOfsCor_MP = (UInt8)localtmp;
      } else {
        IgSys_agIgPrevDynOfsCor_MP = 0U;
      }
    } else {
      IgSys_agIgPrevDynOfsCor_MP = MAX_uint8_T;
    }

    /* Lookup2D: '<S72>/Look-Up Table (2-D)'
     * About '<S72>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U8
     * Input1  Data Type:  Fixed Point    U16  2^-7
     * Output0 Data Type:  Fixed Point    S8  2^-5  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S8_U8_U16( &(localLookUpTable2D_d), (&(IgSys_rCorPrevDyn2Ofs_M[0])),
                     localTmpSignalConversionAtCoPt_,
                     (&(IgSys_noEgdGearCord_PrevDynX_A[0])), 5U,
                     localTmpSignalConversionAtVeh_s,
                     (&(IgSys_spdVeh_PrevDynY_A[0])), 5U);

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate2'
     *
     * Regarding '<S72>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S76>/Divide' */
    IgSys_agIgPrevDynCalcOfs = (Float32)((((Float32d)localLookUpTable2D_d) * 0.04F)
      * ((Float32d)localSaturation01_b));

    /* end of Outputs for SubSystem: '<S21>/F01_02_04_01_Calcul_du_retrait_d_avance' */

    /* Outputs for atomic SubSystem: '<S21>/F01_02_04_02_Pente_de_retour' *
     * Block requirements for '<S21>/F01_02_04_02_Pente_de_retour':
     *  1. SubSystem "F01_02_04_02_Pente_de_retour" !Trace_To : VEMS_R_10_06435_017.01 ;
     */

    /* Product: '<S78>/Divide' incorporates:
     *  Constant: '<S70>/IgSys_agIgPrevDynIncOfs_C'
     *  Constant: '<S70>/const'
     *  Constant: '<S70>/const1'
     *  DataTypeConversion: '<S70>/Data Type Conversion'
     *  MinMax: '<S70>/MinMax'
     *  Product: '<S77>/Divide'
     */
    IgSys_agIgPrevDynSlopDrivInc = (Float32)((((Float32d)
      IgSys_agIgPrevDynIncOfs_C) * 0.375F) / ((Float32d)(((Float32)((UInt16)
      rt_MAX(localTmpSignalConversionAtExt_n, 1U))) / 60.0F)));

    /* end of Outputs for SubSystem: '<S21>/F01_02_04_02_Pente_de_retour' */

    /* *
     * Block requirements for '<S71>/F01_02_04_03_01_Automate':
     *  1. SubSystem "F01_02_04_03_01_Automate" !Trace_To : VEMS_R_10_06435_018.01 ;
     */

    /* Stateflow: '<S71>/F01_02_04_03_01_Automate' */
    /* Gateway: AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_03_Gestion_du_correctif_cliquetis_dynamique/F01_02_04_03_01_Automate */
    /* During: AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_03_Gestion_du_correctif_cliquetis_dynamique/F01_02_04_03_01_Automate */
    if (AdvPrevKnkT_DWork.is_active_c1_AdvPrevKnkT == 0) {
      /* Entry: AdvPrevKnkT/F01_AdvPrevKnkT/F01_02_Fonction_cliquetis/F01_02_04_Avance_preventive_dynamique/F01_02_04_03_Gestion_du_correctif_cliquetis_dynamique/F01_02_04_03_01_Automate */
      AdvPrevKnkT_DWork.is_active_c1_AdvPrevKnkT = 1U;

      /* Transition: '<S79>:4' */
      /* Entry 'DEPART': '<S79>:1' */
      AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_DEPART;
    } else {
      switch (AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT) {
       case IN_DECREMENT:
        /* During 'DECREMENT': '<S79>:2' */
        if ((((SInt32)IgSys_bAirLdDynPrevDynDet) == 0) &&
            (AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i >= 0.0F)) {
          /* Transition: '<S79>:5' */
          /* Exit 'DECREMENT': '<S79>:2' */
          /* Entry 'DEPART': '<S79>:1' */
          AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_DEPART;
        } else if (((SInt32)IgSys_bAirLdDynPrevDynDet) == 1) {
          /* Transition: '<S79>:7' */
          /* Exit 'DECREMENT': '<S79>:2' */
          /* Entry 'INHIBITION': '<S79>:3' */
          AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_INHIBITION;
        } else {
          AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i = rt_MINf
            (AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i + IgSys_agIgPrevDynSlopDrivInc,
             0.0F);
        }
        break;

       case IN_DEPART:
        /* During 'DEPART': '<S79>:1' */
        if (((SInt32)IgSys_bAirLdDynPrevDynDet) == 1) {
          /* Transition: '<S79>:6' */
          /* Exit 'DEPART': '<S79>:1' */
          /* Entry 'INHIBITION': '<S79>:3' */
          AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_INHIBITION;
        } else {
          AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i = 0.0F;
        }
        break;

       case IN_INHIBITION:
        /* During 'INHIBITION': '<S79>:3' */
        if (((SInt32)IgSys_bAirLdDynPrevDynDet) == 0) {
          /* Transition: '<S79>:8' */
          /* Exit 'INHIBITION': '<S79>:3' */
          /* Entry 'DECREMENT': '<S79>:2' */
          AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_DECREMENT;
        } else {
          AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i = IgSys_agIgPrevDynCalcOfs;
        }
        break;

       default:
        /* Transition: '<S79>:4' */
        /* Entry 'DEPART': '<S79>:1' */
        AdvPrevKnkT_DWork.is_c1_AdvPrevKnkT = IN_DEPART;
        break;
      }
    }

    /* DataTypeConversion: '<S71>/Data Type Conversion2' */
    localtmp = ACTEMS_FloorF(((((Float32d)AdvPrevKnkT_B.IgSys_agIgPrevDynOfs_i) +
      36.0F) / 0.375F) + 0.5F);
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        IgSys_agIgPrevDynOfs = (UInt8)localtmp;
      } else {
        IgSys_agIgPrevDynOfs = 0U;
      }
    } else {
      IgSys_agIgPrevDynOfs = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S12>/F01_02_04_Avance_preventive_dynamique' */

    /* Outputs for atomic SubSystem: '<S12>/F01_02_05_Avance_preventive_statique' *
     * Block requirements for '<S12>/F01_02_05_Avance_preventive_statique':
     *  1. SubSystem "F01_02_05_Avance_preventive_statique" !Trace_To : VEMS_R_10_06435_019.01 ;
     */

    /* Outputs for atomic SubSystem: '<S22>/F01_02_05_01_Aspect_richesse_correctif_statique' *
     * Block requirements for '<S22>/F01_02_05_01_Aspect_richesse_correctif_statique':
     *  1. SubSystem "F01_02_05_01_Aspect_richesse_correctif_statique" !Trace_To : VEMS_R_10_06435_020.01 ;
     */

    /* DataTypeConversion: '<S84>/Data Type Conversion1' */
    localqY = (UInt32)((SInt32)(((UInt32)(localTmpSignalConversionAtFARSp *
      17857)) >> 14));
    if (localqY > 65535U) {
      localDataTypeConversion1_l = MAX_uint16_T;
    } else {
      localDataTypeConversion1_l = (UInt16)localqY;
    }

    /* Lookup2D: '<S84>/Look-Up Table (2-D)'
     * About '<S84>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-13  FSlope 1.835
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(IgSys_agIgPrevStatLamOfs),
                      (&(IgSys_agIgPrevStatLamOfs_M[0])),
                      localTmpSignalConversionAtExt_n,
                      (&(IgSys_nEng_PrevStatX_A[0])), 8U,
                      localDataTypeConversion1_l,
                      (&(IgSys_rLamEngCorReq_PrevStaY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S84>/Data Type Duplicate2'
     *
     * Regarding '<S84>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S22>/F01_02_05_01_Aspect_richesse_correctif_statique' */

    /* Outputs for atomic SubSystem: '<S22>/F01_02_05_02_Aspect_EGR_correctif_statique' *
     * Block requirements for '<S22>/F01_02_05_02_Aspect_EGR_correctif_statique':
     *  1. SubSystem "F01_02_05_02_Aspect_EGR_correctif_statique" !Trace_To : VEMS_R_10_06435_021.01 ;
     */

    /* Lookup2D: '<S85>/Look-Up Table (2-D)'
     * About '<S85>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_f), (&(IgSys_agIgPrevEGROfs_M[0])),
                      localTmpSignalConversionAtExt_n,
                      (&(IgSys_nEng_PrevStatX_A[0])), 8U,
                      localTmpSignalConversionAtEngM_,
                      (&(IgSys_rAirLdCor_PrevStatY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S85>/Data Type Duplicate2'
     *
     * Regarding '<S85>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Product: '<S86>/Divide' */
    localq = ((localLookUpTable2D_f * 3) + -288) *
      localTmpSignalConversionAtInM_c;
    localq = (((localq >= 0) ? ((SInt32)(((UInt32)localq) >> 16U)) :
               (~((SInt32)(((UInt32)(~localq)) >> 16U)))) * 21845) + 6291456;
    localq = (localq >= 0) ? ((SInt32)(((UInt32)localq) >> 16U)) :
      (~((SInt32)(((UInt32)(~localq)) >> 16U)));
    if (localq <= 0) {
      IgSys_agIgPrevEGROfs = 0U;
    } else if (localq > 255) {
      IgSys_agIgPrevEGROfs = MAX_uint8_T;
    } else {
      IgSys_agIgPrevEGROfs = (UInt8)localq;
    }

    /* end of Outputs for SubSystem: '<S22>/F01_02_05_02_Aspect_EGR_correctif_statique' */

    /* Outputs for atomic SubSystem: '<S22>/F01_02_05_03_Aspect_Patmo_correctif_statique' *
     * Block requirements for '<S22>/F01_02_05_03_Aspect_Patmo_correctif_statique':
     *  1. SubSystem "F01_02_05_03_Aspect_Patmo_correctif_statique" !Trace_To : VEMS_R_10_06435_022.01 ;
     */

    /* S-Function (sfun_autosar_clientop): '<S89>/Rte_Call_R_FRM_bAcvPAirExtMesDft_GetFunctionPermission_sf' */
    Rte_Call_R_FRM_bAcvPAirExtMesDft_GetFunctionPermission
      (&localRte_Call_R_FRM_bAcvPAirExt);

    /* Switch: '<S82>/Switch1' incorporates:
     *  Constant: '<S82>/IgSys_pAirExtMesDft_C'
     *  Logic: '<S89>/Not'
     */
    if (!localRte_Call_R_FRM_bAcvPAirExt) {
      localDataTypeConversion_f = IgSys_pAirExtMesDft_C;
    } else {
      localDataTypeConversion_f = localTmpSignalConversionAtUsThr;
    }

    /* Lookup: '<S87>/Look-Up Table'
     * About '<S87>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    S8  2^-5  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_S8_U16( &(localLookUpTable_b), (&(IgSys_rCorPrevStatPOfs_T[0])),
                  localDataTypeConversion_f, (&(IgSys_pAirExtMes_PrevStat_A[0])),
                  8U);

    /* DataTypeDuplicate Block: '<S87>/Data Type Duplicate1'
     *
     * Regarding '<S87>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S82>/Data Type Conversion' */
    if (localLookUpTable_b <= 0) {
      localDataTypeConversion_f = 0U;
    } else {
      localDataTypeConversion_f = (UInt16)localLookUpTable_b;
    }

    /* DataStoreWrite: '<S82>/Data Store Write' */
    IgSys_rCorPrevStatPOfs_MP = localDataTypeConversion_f;

    /* Lookup2D: '<S88>/Look-Up Table (2-D)'
     * About '<S88>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(localLookUpTable2D_c), (&(IgSys_agIgPrevStatPOfs_M[0])),
                      localTmpSignalConversionAtExt_n,
                      (&(IgSys_nEng_PrevStatX_A[0])), 8U,
                      localTmpSignalConversionAtEngM_,
                      (&(IgSys_rAirLdCor_PrevStatY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S88>/Data Type Duplicate2'
     *
     * Regarding '<S88>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S82>/Data Type Conversion1'
     *
     * Regarding '<S82>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataStoreWrite: '<S82>/Data Store Write1' */
    IgSys_agIgPrevStatPOfs_MP = localLookUpTable2D_c;

    /* DataTypeConversion: '<S82>/Data Type Conversion2' incorporates:
     *  DataTypeConversion: '<S82>/Data Type Conversion3'
     *  DataTypeConversion: '<S82>/Data Type Conversion4'
     *  Product: '<S90>/Divide'
     */
    localtmp = (((Float32d)(((((Float32)localLookUpTable2D_c) * 0.375F) - 36.0F) *
                          (((Float32)localLookUpTable_b) * 3.999999911E-002F)))
                + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        IgSys_agIgPrevStatPOfs = (UInt8)localtmp;
      } else {
        IgSys_agIgPrevStatPOfs = 0U;
      }
    } else {
      IgSys_agIgPrevStatPOfs = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S22>/F01_02_05_03_Aspect_Patmo_correctif_statique' */

    /* Outputs for atomic SubSystem: '<S22>/F01_02_05_04_Aspect_temperatures_correctif_statique' *
     * Block requirements for '<S22>/F01_02_05_04_Aspect_temperatures_correctif_statique':
     *  1. SubSystem "F01_02_05_04_Aspect_temperatures_correctif_statique" !Trace_To : VEMS_R_10_06435_023.01 ;
     */

    /* Lookup2D: '<S92>/Look-Up Table (2-D)'
     * About '<S92>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    S8  2^-5  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_S8_U16_U16( &(localLookUpTable2D_bx), (&(IgSys_rCorPrevStatTOfs_M[0])),
                      localTmpSignalConversionAtExt_n,
                      (&(IgSys_nEng_PrevStatX_A[0])), 8U,
                      localTmpSignalConversionAtEngM_,
                      (&(IgSys_rAirLdCor_PrevStatY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S92>/Data Type Duplicate2'
     *
     * Regarding '<S92>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S83>/Data Type Conversion1' */
    if (localLookUpTable2D_bx <= 0) {
      localLookUpTable2D = 0U;
    } else {
      localLookUpTable2D = (UInt16)localLookUpTable2D_bx;
    }

    /* DataStoreWrite: '<S83>/Data Store Write' */
    IgSys_rCorPrevStatTOfs_MP = localLookUpTable2D;

    /* S-Function (sfun_autosar_clientop): '<S94>/Rte_Call_R_FRM_bAcvTCoMesDft_GetFunctionPermission_sf' */
    Rte_Call_R_FRM_bAcvTCoMesDft_GetFunctionPermission
      (&localRte_Call_R_FRM_bAcvTCoMesD);

    /* Switch: '<S83>/Switch2' incorporates:
     *  Constant: '<S83>/IgSys_tCoMesDft_C'
     *  Logic: '<S94>/Not'
     */
    if (!localRte_Call_R_FRM_bAcvTCoMesD) {
      localLookUpTable2D_h = IgSys_tCoMesDft_C;
    } else {
      localLookUpTable2D_h = (UInt8)(localTmpSignalConversionAtExt_t + 40);
    }

    /* DataTypeConversion: '<S91>/Data Type Conversion' */
    localDataTypeConversion_o = (SInt16)(localLookUpTable2D_h + -40);

    /* Lookup2D: '<S91>/Look-Up Table (2-D)'
     * About '<S91>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        S16
     * Input1  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Output0 Data Type:  Fixed Point    U8  2^-2  FSlope 1.5  Bias -36.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_S16_U16( &(localLookUpTable2D_h), (&(IgSys_agIgPrevStatTOfs_M[0])),
                      localDataTypeConversion_o, (&(IgSys_tCoMes_PrevStatX_A[0])),
                      8U, localTmpSignalConversionAtInThM,
                      (&(IgSys_tAirUsInVlv_PrevStatY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S91>/Data Type Duplicate2'
     *
     * Regarding '<S91>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S83>/SignalConversion'
     *
     * Regarding '<S83>/SignalConversion':
     *   Eliminate redundant data type conversion
     */

    /* DataStoreWrite: '<S83>/MemoryStore1' */
    IgSys_agIgPrevStatTOfs_MP = localLookUpTable2D_h;

    /* Lookup2D: '<S93>/Look-Up Table (2-D)'
     * About '<S93>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^-14
     * Output0 Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D), (&(IgSys_tRefTAirUsInVlvEstim_M[0])),
                       localTmpSignalConversionAtExt_n,
                       (&(IgSys_nEng_PrevStatX_A[0])), 8U,
                       localTmpSignalConversionAtEngM_,
                       (&(IgSys_rAirLdCor_PrevStatY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S93>/Data Type Duplicate2'
     *
     * Regarding '<S93>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Sum: '<S83>/Add1' */
    localSum1_h = (((Float32)localTmpSignalConversionAtInThM) * 0.0078125F) -
      (((Float32)localLookUpTable2D) * 0.0078125F);

    /* Product: '<S95>/Divide' */
    localq = ((localLookUpTable2D_h * 3) + -288) * (localLookUpTable2D_bx * 41);
    localq = (localq >= 0) ? ((SInt32)(((UInt32)localq) >> 10U)) :
      (~((SInt32)(((UInt32)(~localq)) >> 10U)));
    if (localq > 32767) {
      localTmpSignalConversionAtIgS_l = MAX_int16_T;
    } else if (localq <= -32768) {
      localTmpSignalConversionAtIgS_l = MIN_int16_T;
    } else {
      localTmpSignalConversionAtIgS_l = (SInt16)localq;
    }

    localq = (localTmpSignalConversionAtIgS_l * 21845) + 6291456;
    localq = (localq >= 0) ? ((SInt32)(((UInt32)localq) >> 16U)) :
      (~((SInt32)(((UInt32)(~localq)) >> 16U)));
    if (localq <= 0) {
      IgSys_agIgPrevStatTOfs = 0U;
    } else if (localq > 255) {
      IgSys_agIgPrevStatTOfs = MAX_uint8_T;
    } else {
      IgSys_agIgPrevStatTOfs = (UInt8)localq;
    }

    /* end of Outputs for SubSystem: '<S22>/F01_02_05_04_Aspect_temperatures_correctif_statique' */

    /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
     *  Sum: '<S22>/Add1'
     */
    localtmp = (((Float32d)(((((((Float32)IgSys_agIgPrevStatLamOfs) * 0.375F) +
      -144.0F) + (((Float32)IgSys_agIgPrevEGROfs) * 0.375F)) + (((Float32)
      IgSys_agIgPrevStatPOfs) * 0.375F)) + (((Float32)IgSys_agIgPrevStatTOfs) *
      0.375F))) + 36.0F) / 0.375F;
    if (localtmp < 256.0F) {
      if (localtmp >= 0.0F) {
        IgSys_agIgPrevStatOfs = (UInt8)localtmp;
      } else {
        IgSys_agIgPrevStatOfs = 0U;
      }
    } else {
      IgSys_agIgPrevStatOfs = MAX_uint8_T;
    }

    /* end of Outputs for SubSystem: '<S12>/F01_02_05_Avance_preventive_statique' */

    /* Sum: '<S12>/Add1' */
    localSaturation01_b = ((((Float32)IgSys_agIgPrevDynOfs) * 0.375F) + -72.0F)
      + (((Float32)IgSys_agIgPrevStatOfs) * 0.375F);

    /* DataTypeConversion: '<S27>/Conversion' incorporates:
     *  Constant: '<S12>/IgSys_agIgMaxPrevKnkOfsSat_C'
     */
    localDivide_m = (((Float32)IgSys_agIgMaxPrevKnkOfsSat_C) * 0.375F) - 36.0F;

    /* DataTypeConversion: '<S28>/Conversion' incorporates:
     *  Constant: '<S12>/IgSys_agIgMinPrevKnkOfsSat_C'
     */
    localSwitch1 = (((Float32)IgSys_agIgMinPrevKnkOfsSat_C) * 0.375F) - 36.0F;

    /* Switch: '<S29>/Switch' incorporates:
     *  RelationalOperator: '<S29>/UpperRelop'
     */
    if (!(localSaturation01_b < localSwitch1)) {
      localSwitch1 = localSaturation01_b;
    }

    /* Switch: '<S29>/Switch2' incorporates:
     *  RelationalOperator: '<S29>/LowerRelop1'
     */
    if (!(localSaturation01_b > localDivide_m)) {
      localDivide_m = localSwitch1;
    }

    /* Outputs for atomic SubSystem: '<S12>/F01_02_03_Calcul_du_remplissage_dynamique' *
     * Block requirements for '<S12>/F01_02_03_Calcul_du_remplissage_dynamique':
     *  1. SubSystem "F01_02_03_Calcul_du_remplissage_dynamique" !Trace_To : VEMS_R_10_06435_009.01 ;
     */

    /* Outputs for atomic SubSystem: '<S20>/F01_02_03_01_Calcul_du_facteur_de_filtrage' *
     * Block requirements for '<S20>/F01_02_03_01_Calcul_du_facteur_de_filtrage':
     *  1. SubSystem "F01_02_03_01_Calcul_du_facteur_de_filtrage" !Trace_To : VEMS_R_10_06435_010.01 ;
     */

    /* Lookup2D: '<S55>/Look-Up Table (2-D)'
     * About '<S55>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.28
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U8_U16_U16( &(IgSys_facFilAirLdDyn), (&(IgSys_facFilAirLdDyn_M[0])),
                      localTmpSignalConversionAtExt_n,
                      (&(IgSys_nEng_facFilAirldDynX_A[0])), 8U,
                      localTmpSignalConversionAtInM_p,
                      (&(IgSys_pDsThr_facFilAirLdDynY_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
     *
     * Regarding '<S55>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S20>/F01_02_03_01_Calcul_du_facteur_de_filtrage' */

    /* Outputs for atomic SubSystem: '<S20>/F01_02_03_02_Calcul_du_retard' *
     * Block requirements for '<S20>/F01_02_03_02_Calcul_du_retard':
     *  1. SubSystem "F01_02_03_02_Calcul_du_retard" !Trace_To : VEMS_R_10_06435_011.01 ;
     */

    /* Lookup: '<S56>/Look-Up Table'
     * About '<S56>/Look-Up Table':
     * Input0  Data Type:  Integer        U16
     * Output0 Data Type:  Integer        U8
     * Round Mode: Ceiling
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U8_U16_CEILING( &(IgSys_noDlyClcAirLdDyn),
                          (&(IgSys_noDlyCalcAirLdDyn_T[0])),
                          localTmpSignalConversionAtExt_n,
                          (&(IgSys_nEng_noDlyCalcAirLd_A[0])), 8U);

    /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate1'
     *
     * Regarding '<S56>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* end of Outputs for SubSystem: '<S20>/F01_02_03_02_Calcul_du_retard' */

    /* Outputs for atomic SubSystem: '<S20>/F01_02_03_03_Calcul_et_choix_de_remplissage' *
     * Block requirements for '<S20>/F01_02_03_03_Calcul_et_choix_de_remplissage':
     *  1. SubSystem "F01_02_03_03_Calcul_et_choix_de_remplissage" !Trace_To : VEMS_R_10_06435_012.01 ;
     */

    /* MinMax: '<S52>/MinMax' */
    localTmpSignalConversionAtIgSys = localTmpSignalConversionAtAirSy;
    if (localTmpSignalConversionAtEng_p < localTmpSignalConversionAtAirSy) {
      localTmpSignalConversionAtIgSys = localTmpSignalConversionAtEng_p;
    }

    /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
     *  Constant: '<S52>/IgSys_idxModRatAirLdCalc_C'
     */
    switch (IgSys_idxModRatAirLdCalc_C) {
     case 0:
      IgSys_rAirLdClcRef = localTmpSignalConversionAtEng_e;
      break;

     case 1:
      IgSys_rAirLdClcRef = localTmpSignalConversionAtAirSy;
      break;

     default:
      IgSys_rAirLdClcRef = localTmpSignalConversionAtIgSys;
      break;
    }

    /* end of Outputs for SubSystem: '<S20>/F01_02_03_03_Calcul_et_choix_de_remplissage' */

    /* Outputs for atomic SubSystem: '<S20>/F01_02_03_04_Application_du_retard' *
     * Block requirements for '<S20>/F01_02_03_04_Application_du_retard':
     *  1. SubSystem "F01_02_03_04_Application_du_retard" !Trace_To : VEMS_R_10_06435_013.01 ;
     */

    /* UnitDelay: '<S58>/Unit Delay' */
    localTmpSignalConversionAtIgSys = AdvPrevKnkT_DWork.UnitDelay_DSTATE_l;

    /* UnitDelay: '<S57>/Unit Delay' */
    localIgSys_rAirLdClc = AdvPrevKnkT_DWork.UnitDelay_DSTATE_c;

    /* UnitDelay: '<S59>/Unit Delay' */
    localTmpSignalConversionAtEng_e = AdvPrevKnkT_DWork.UnitDelay_DSTATE_f;

    /* UnitDelay: '<S64>/Unit Delay' */
    localTmpSignalConversionAtAirSy = AdvPrevKnkT_DWork.UnitDelay_DSTATE_f2;

    /* UnitDelay: '<S63>/Unit Delay' */
    localTmpSignalConversionAtUsThr = AdvPrevKnkT_DWork.UnitDelay_DSTATE_n;

    /* UnitDelay: '<S62>/Unit Delay' */
    localTmpSignalConversionAtInM_c = AdvPrevKnkT_DWork.UnitDelay_DSTATE_o;

    /* UnitDelay: '<S61>/Unit Delay' */
    localTmpSignalConversionAtFARSp = AdvPrevKnkT_DWork.UnitDelay_DSTATE_k;

    /* MultiPortSwitch: '<S53>/Index Vector' incorporates:
     *  UnitDelay: '<S60>/Unit Delay'
     */
    switch (IgSys_noDlyClcAirLdDyn) {
     case 0:
      IgSys_rAirLdDynWoutFil = IgSys_rAirLdClcRef;
      break;

     case 1:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_l;
      break;

     case 2:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_c;
      break;

     case 3:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_f;
      break;

     case 4:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_f2;
      break;

     case 5:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_n;
      break;

     case 6:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_o;
      break;

     case 7:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_k;
      break;

     default:
      IgSys_rAirLdDynWoutFil = AdvPrevKnkT_DWork.UnitDelay_DSTATE_kj;
      break;
    }

    /* Update for UnitDelay: '<S58>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_l = IgSys_rAirLdClcRef;

    /* Update for UnitDelay: '<S57>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_c = localTmpSignalConversionAtIgSys;

    /* Update for UnitDelay: '<S59>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_f = localIgSys_rAirLdClc;

    /* Update for UnitDelay: '<S64>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_f2 = localTmpSignalConversionAtEng_e;

    /* Update for UnitDelay: '<S63>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_n = localTmpSignalConversionAtAirSy;

    /* Update for UnitDelay: '<S62>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_o = localTmpSignalConversionAtUsThr;

    /* Update for UnitDelay: '<S61>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_k = localTmpSignalConversionAtInM_c;

    /* Update for UnitDelay: '<S60>/Unit Delay' */
    AdvPrevKnkT_DWork.UnitDelay_DSTATE_kj = localTmpSignalConversionAtFARSp;

    /* end of Outputs for SubSystem: '<S20>/F01_02_03_04_Application_du_retard' */

    /* Outputs for atomic SubSystem: '<S20>/F01_02_03_05_Filtarge_du_remplissage' *
     * Block requirements for '<S20>/F01_02_03_05_Filtarge_du_remplissage':
     *  1. SubSystem "F01_02_03_05_Filtarge_du_remplissage" !Trace_To : VEMS_R_10_06435_014.01 ;
     */

    /* DataTypeConversion: '<S54>/Data Type Conversion1' */
    localSaturation01_b = ((Float32)IgSys_facFilAirLdDyn) * 9.999999776E-003F;

    /* UnitDelay: '<S67>/UnitDelay' */
    localSwitch1 = AdvPrevKnkT_DWork.UnitDelay;

    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S54>/const'
     *  UnitDelay: '<S67>/UnitDelay1'
     */
    if (!AdvPrevKnkT_DWork.UnitDelay_lg) {
      localSwitch1 = 0.0F;
    }

    /* Sum: '<S68>/Sum1' incorporates:
     *  DataTypeConversion: '<S54>/Data Type Conversion'
     *  Product: '<S68>/Product'
     *  Saturate: '<S68>/Saturation [0-1]'
     *  Sum: '<S68>/Sum'
     */
    localSaturation01_b = (((((Float32)IgSys_rAirLdDynWoutFil) *
      6.103515625E-005F) - localSwitch1) * rt_SATURATE(localSaturation01_b, 0.0F,
      1.0F)) + localSwitch1;

    /* Update for UnitDelay: '<S67>/UnitDelay' */
    AdvPrevKnkT_DWork.UnitDelay = localSaturation01_b;

    /* Update for UnitDelay: '<S67>/UnitDelay1' incorporates:
     *  Constant: '<S67>/Constant3'
     */
    AdvPrevKnkT_DWork.UnitDelay_lg = TRUE;

    /* end of Outputs for SubSystem: '<S20>/F01_02_03_05_Filtarge_du_remplissage' */

    /* end of Outputs for SubSystem: '<S12>/F01_02_03_Calcul_du_remplissage_dynamique' */

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/Byp_Fonction_SC'
     *  Constant: '<S23>/Int_BypC'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_bAirLdDynDet_n = IgSys_bAirLdDynDet_B;
    }

    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/Byp_Fonction_SC'
     *  Constant: '<S24>/Int_BypC'
     *  DataTypeConversion: '<S24>/Data Type Conversion'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_rAirLdClc = IgSys_rAirLdClc_B;
    } else {
      localtmp = ACTEMS_LdexpF((Float32d)localSaturation01_b, 14);
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          localIgSys_rAirLdClc = (UInt16)localtmp;
        } else {
          localIgSys_rAirLdClc = 0U;
        }
      } else {
        localIgSys_rAirLdClc = MAX_uint16_T;
      }
    }

    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Byp_Fonction_SC'
     *  Constant: '<S25>/Int_BypC'
     *  DataTypeConversion: '<S25>/Data Type Conversion'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_agIgKnkPrevOfs = IgSys_agIgKnkPrevOfs_B;
    } else {
      localtmp = (((Float32d)localDivide_m) + 36.0F) / 0.375F;
      if (localtmp < 256.0F) {
        localIgSys_agIgKnkPrevOfs = (UInt8)localtmp;
      } else {
        localIgSys_agIgKnkPrevOfs = MAX_uint8_T;
      }
    }

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/Byp_Fonction_SC'
     *  Constant: '<S26>/Int_BypC'
     *  DataTypeConversion: '<S26>/Data Type Conversion'
     */
    if (ADVPREVKNKT_ACTIVE_BYP_C) {
      localIgSys_tDifTAirUsInVlvEstim = IgSys_tDifTAirUsInVlvEstim_B;
    } else {
      localtmp = ACTEMS_LdexpF((Float32d)localSum1_h, 7);
      if (localtmp < 32768.0F) {
        if (localtmp >= -32768.0F) {
          localIgSys_tDifTAirUsInVlvEstim = (SInt16)localtmp;
        } else {
          localIgSys_tDifTAirUsInVlvEstim = MIN_int16_T;
        }
      } else {
        localIgSys_tDifTAirUsInVlvEstim = MAX_int16_T;
      }
    }
  }

  /* end of Outputs for SubSystem: '<S5>/F01_02_Fonction_cliquetis' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_agIgKnkPrevOfsInport2' */
  Rte_Write_P_IgSys_agIgKnkPrevOfs_IgSys_agIgKnkPrevOfs
    (localIgSys_agIgKnkPrevOfs);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_bAirLdDynDetInport2' */
  Rte_Write_P_IgSys_bAirLdDynDet_IgSys_bAirLdDynDet(localIgSys_bAirLdDynDet_n);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_rAirLdClcInport2' */
  Rte_Write_P_IgSys_rAirLdClc_IgSys_rAirLdClc(localIgSys_rAirLdClc);

  /* SignalConversion: '<S5>/TmpSignal ConversionAtIgSys_tDifTAirUsInVlvEstimInport2' */
  Rte_Write_P_IgSys_tDifTAirUsInVlvEstim_IgSys_tDifTAirUsInVlvEstim
    (localIgSys_tDifTAirUsInVlvEstim);
}

/* Model initialize function */
void Runnable_AdvPrevKnkT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  RE_AdvPrevKnkT_001_MSE_Start();
  RE_AdvPrevKnkT_002_Start();
}

#define AdvPrevKnkT_STOP_SEC_CODE
#include "AdvPrevKnkT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
