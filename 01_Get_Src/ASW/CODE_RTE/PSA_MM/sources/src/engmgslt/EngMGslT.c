/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : EngMGslT                                                */
/* !Description     : EngMGslT Software Component                             */
/*                                                                            */
/* !Module          : EngMGslT                                                */
/* !Description     : EngMGslT Software Component                             */
/*                                                                            */
/* !File            : EngMGslT.c                                              */
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
/*   Model name       : EngMGslT_AUTOSAR.mdl                                  */
/*   Root subsystem   : /EngMGslT                                             */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M05-EngMGslT/5-S$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   adelvare                               $$Date::   31 May 2012 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "EngMGslT.h"
#include "EngMGslT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define EngMGslT_START_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngMGslT_MemMap.h"

/* Block signals (auto storage) */
BlockIO_EngMGslT EngMGslT_B;

/* Block states (auto storage) */
D_Work_EngMGslT EngMGslT_DWork;

#define EngMGslT_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
#include "EngMGslT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "AirEfcEngCylPrmT_compatibility.h"
#define ENGMGSLT_AIREFCENGCYLPRMT_MAJOR_VERSION_REQ 4
#define ENGMGSLT_AIREFCENGCYLPRMT_MINOR_VERSION_REQ 0
#define ENGMGSLT_AIREFCENGCYLPRMT_PATCH_VERSION_REQ 0
#define ENGMGSLT_AIREFCENGCYLPRMT_VERSION_REQ (ENGMGSLT_AIREFCENGCYLPRMT_PATCH_VERSION_REQ + ENGMGSLT_AIREFCENGCYLPRMT_MINOR_VERSION_REQ*1000 + ENGMGSLT_AIREFCENGCYLPRMT_MAJOR_VERSION_REQ*1000000)
#if ENGMGSLT_AIREFCENGCYLPRMT_VERSION_REQ > AIREFCENGCYLPRMT_VERSION
#error AirEfcEngCylPrmT version is not compatible with current SWC version
#endif

#include "VemsRtLibT_compatibility.h"
#define ENGMGSLT_VEMSRTLIBT_MAJOR_VERSION_REQ 2
#define ENGMGSLT_VEMSRTLIBT_MINOR_VERSION_REQ 19
#define ENGMGSLT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define ENGMGSLT_VEMSRTLIBT_VERSION_REQ (ENGMGSLT_VEMSRTLIBT_PATCH_VERSION_REQ + ENGMGSLT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + ENGMGSLT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if ENGMGSLT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define EngMGslT_START_SEC_CODE
#include "EngMGslT_MemMap.h"

void EngMGslT_ASYNC1(int controlPortIdx)
{
}

void EngMGslT_ASYNC2(int controlPortIdx)
{
}

void EngMGslT_ASYNC3(int controlPortIdx)
{
}

void EngMGslT_ASYNC4(int controlPortIdx)
{
}

void EngMGslT_ASYNC5(int controlPortIdx)
{
}

void EngMGslT_ASYNC6(int controlPortIdx)
{
}

void EngMGslT_ASYNC7(int controlPortIdx)
{
}

void EngMGslT_ASYNC8(int controlPortIdx)
{
}

void EngMGslT_ASYNC9(int controlPortIdx)
{
}

void EngMGslT_ASYNC10(int controlPortIdx)
{
}

void EngMGslT_ASYNC11(int controlPortIdx)
{
}

void EngMGslT_ASYNC12(int controlPortIdx)
{
}

void EngMGslT_ASYNC13(int controlPortIdx)
{
}

void EngMGslT_ASYNC14(int controlPortIdx)
{
}

/* Start for exported function: RE_EngMGslT_001_MSE */
void RE_EngMGslT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_EngMGslT_init'
   *
   * Block requirements for '<S1>/F01_EngMGslT_init':
   *  1. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_005.01 ;
   *  2. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_006.01 ;
   *  3. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_010.01 ;
   *  4. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_011.01 ;
   *  5. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_013.01 ;
   *  6. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_016.01 ;
   *  7. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_020.02 ;
   *  8. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_021.02 ;
   *  9. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_019.02 ;
   *  10. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_043.01 ;
   *  11. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_046.01 ;
   *  12. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_056.02 ;
   *  13. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_077.01 ;
   *  14. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_088.01 ;
   *  15. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_089.01 ;
   *  16. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_090.01 ;
   *  17. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_091.01 ;
   *  18. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_092.01 ;
   *  19. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_093.01 ;
   *  20. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_094.01 ;
   *  21. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_095.01 ;
   *  22. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_106.01 ;
   *  23. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_105.01 ;
   *  24. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_107.01 ;
   *  25. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_108.01 ;
   *  26. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_111.01 ;
   *  27. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_113.01 ;
   *  28. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_114.01 ;
   *  29. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_117.01 ;
   *  30. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_119.01 ;
   *  31. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_120.02 ;
   *  32. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_112.01 ;
   *  33. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_115.01 ;
   *  34. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_116.01 ;
   *  35. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_118.01 ;
   *  36. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_121.01 ;
   *  37. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  38. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_133.02 ;
   *  39. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_134.01 ;
   *  40. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_135.01 ;
   *  41. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_136.01 ;
   *  42. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_137.01 ;
   *  43. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_138.01 ;
   *  44. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_139.01 ;
   *  45. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_140.01 ;
   *  46. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_141.01 ;
   *  47. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_142.01 ;
   *  48. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_143.01 ;
   *  49. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_144.02 ;
   *  50. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_145.02 ;
   *  51. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_146.01 ;
   *  52. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_147.01 ;
   *  53. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_148.01 ;
   *  54. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_149.02 ;
   *  55. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_150.01 ;
   *  56. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_151.01 ;
   *  57. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_152.01 ;
   *  58. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_153.01 ;
   *  59. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_154.01 ;
   *  60. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_155.01 ;
   *  61. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_156.01 ;
   *  62. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_157.01 ;
   *  63. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_158.01 ;
   *  64. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_268.02 ;
   *  65. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  66. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_187.02 ;
   *  67. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_191.02 ;
   *  68. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_062.01 ;
   *  69. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_264.02 ;
   *  70. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_061.02 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_001_MSE */
void RE_EngMGslT_001_MSE(void)
{
  SInt16 localEngM_agCkClsExVlvEstimRef1;
  UInt16 localEngM_agCkClsInVlvEstimRef0;
  UInt8 localEngM_agCkClsInVlvReqRef0;
  UInt32 localEngM_facMassAirScvCor;
  UInt16 localEngM_prm_mAirPredInCyl[6];
  SInt32 locali;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_EngMGslT_init'
   *
   * Block requirements for '<S1>/F01_EngMGslT_init':
   *  1. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_005.01 ;
   *  2. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_006.01 ;
   *  3. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_010.01 ;
   *  4. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_011.01 ;
   *  5. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_013.01 ;
   *  6. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_016.01 ;
   *  7. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_020.02 ;
   *  8. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_021.02 ;
   *  9. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_019.02 ;
   *  10. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_043.01 ;
   *  11. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_046.01 ;
   *  12. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_056.02 ;
   *  13. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_077.01 ;
   *  14. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_088.01 ;
   *  15. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_089.01 ;
   *  16. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_090.01 ;
   *  17. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_091.01 ;
   *  18. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_092.01 ;
   *  19. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_093.01 ;
   *  20. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_094.01 ;
   *  21. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_095.01 ;
   *  22. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_106.01 ;
   *  23. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_105.01 ;
   *  24. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_107.01 ;
   *  25. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_108.01 ;
   *  26. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_111.01 ;
   *  27. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_113.01 ;
   *  28. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_114.01 ;
   *  29. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_117.01 ;
   *  30. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_119.01 ;
   *  31. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_120.02 ;
   *  32. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_112.01 ;
   *  33. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_115.01 ;
   *  34. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_116.01 ;
   *  35. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_118.01 ;
   *  36. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_121.01 ;
   *  37. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  38. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_133.02 ;
   *  39. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_134.01 ;
   *  40. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_135.01 ;
   *  41. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_136.01 ;
   *  42. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_137.01 ;
   *  43. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_138.01 ;
   *  44. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_139.01 ;
   *  45. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_140.01 ;
   *  46. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_141.01 ;
   *  47. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_142.01 ;
   *  48. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_143.01 ;
   *  49. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_144.02 ;
   *  50. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_145.02 ;
   *  51. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_146.01 ;
   *  52. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_147.01 ;
   *  53. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_148.01 ;
   *  54. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_149.02 ;
   *  55. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_150.01 ;
   *  56. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_151.01 ;
   *  57. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_152.01 ;
   *  58. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_153.01 ;
   *  59. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_154.01 ;
   *  60. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_155.01 ;
   *  61. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_156.01 ;
   *  62. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_157.01 ;
   *  63. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_158.01 ;
   *  64. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_268.02 ;
   *  65. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  66. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_187.02 ;
   *  67. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_191.02 ;
   *  68. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_062.01 ;
   *  69. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_264.02 ;
   *  70. SubSystem "F01_EngMGslT_init" !Trace_To : VEMS_R_11_00998_061.02 ;
   */

  /* user code (Output function Body for TID24) */
  Runnable_EngMGslT_Init();

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvEstimRef1 = EngM_agCkClsExVlvEstimRef1_B;
  } else {
    localEngM_agCkClsExVlvEstimRef1 = 0;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (localEngM_agCkClsExVlvEstimRef1);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvEstimRef1 = EngM_agCkClsExVlvReqRef1_B;
  } else {
    localEngM_agCkClsExVlvEstimRef1 = 0;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsExVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkClsExVlvReqRef1_EngM_agCkClsExVlvReqRef1
    (localEngM_agCkClsExVlvEstimRef1);

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S53>/Byp_Fonction_SC'
   *  Constant: '<S53>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_agCkClsInVlvEstimRef0_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 1024U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef0Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvEstimRef0_EngM_agCkClsInVlvEstimRef0
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S12>/Constant3'
   *  Constant: '<S64>/Byp_Fonction_SC'
   *  Constant: '<S64>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_agCkClsInVlvEstimRef1_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 1024U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S75>/Byp_Fonction_SC'
   *  Constant: '<S75>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_agCkClsInVlvReqRef0_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsInVlvReqRef0Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvReqRef0_EngM_agCkClsInVlvReqRef0
    (localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S86>/Byp_Fonction_SC'
   *  Constant: '<S86>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_agCkOpExVlvEstimRef0_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 1024U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpExVlvEstimRef0Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvEstimRef0_EngM_agCkOpExVlvEstimRef0
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S12>/Constant6'
   *  Constant: '<S97>/Byp_Fonction_SC'
   *  Constant: '<S97>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_agCkOpExVlvEstimRef1_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 1024U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpExVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvEstimRef1_EngM_agCkOpExVlvEstimRef1
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S108>/Switch' incorporates:
   *  Constant: '<S108>/Byp_Fonction_SC'
   *  Constant: '<S108>/Int_BypC'
   *  Constant: '<S12>/Constant7'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_agCkOpExVlvReqRef0_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpExVlvReqRef0Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvReqRef0_EngM_agCkOpExVlvReqRef0
    (localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/Byp_Fonction_SC'
   *  Constant: '<S110>/Int_BypC'
   *  Constant: '<S12>/Constant8'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_agCkOpExVlvReqRef1_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpExVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvReqRef1_EngM_agCkOpExVlvReqRef1
    (localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S111>/Byp_Fonction_SC'
   *  Constant: '<S111>/Int_BypC'
   *  Constant: '<S12>/Constant9'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvEstimRef1 = EngM_agCkOpInVlvEstimRef1_B;
  } else {
    localEngM_agCkClsExVlvEstimRef1 = 0;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (localEngM_agCkClsExVlvEstimRef1);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S12>/Constant10'
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvEstimRef1 = EngM_agCkOpInVlvReqRef1_B;
  } else {
    localEngM_agCkClsExVlvEstimRef1 = 0;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkOpInVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkOpInVlvReqRef1_EngM_agCkOpInVlvReqRef1
    (localEngM_agCkClsExVlvEstimRef1);

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S12>/Constant11'
   *  Constant: '<S35>/Byp_Fonction_SC'
   *  Constant: '<S35>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_facACor_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facACorInport2' */
  Rte_Write_P_EngM_facACor_EngM_facACor(localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S12>/Constant12'
   *  Constant: '<S45>/Byp_Fonction_SC'
   *  Constant: '<S45>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_facAPred_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facAPredInport2' */
  Rte_Write_P_EngM_facAPred_EngM_facAPred(localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S12>/Constant13'
   *  Constant: '<S46>/Byp_Fonction_SC'
   *  Constant: '<S46>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvReqRef0 = EngM_facDCor_B;
  } else {
    localEngM_agCkClsInVlvReqRef0 = 128U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facDCorInport2' */
  Rte_Write_P_EngM_facDCor_EngM_facDCor(localEngM_agCkClsInVlvReqRef0);

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S12>/Constant14'
   *  Constant: '<S47>/Byp_Fonction_SC'
   *  Constant: '<S47>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_facMassAirScvCor_B;
  } else {
    localEngM_facMassAirScvCor = 65536U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facMassAirScvCorInport2' */
  Rte_Write_P_EngM_facMassAirScvCor_EngM_facMassAirScvCor
    (localEngM_facMassAirScvCor);

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S12>/Constant15'
   *  Constant: '<S48>/Byp_Fonction_SC'
   *  Constant: '<S48>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_facMassAirScvReq_B;
  } else {
    localEngM_facMassAirScvCor = 65536U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facMassAirScvReqInport2' */
  Rte_Write_P_EngM_facMassAirScvReq_EngM_facMassAirScvReq
    (localEngM_facMassAirScvCor);

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S12>/Constant16'
   *  Constant: '<S49>/Byp_Fonction_SC'
   *  Constant: '<S49>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facMassFlowLdCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facMassFlowLdCorInport2' */
  Rte_Write_P_EngM_facMassFlowLdCor_EngM_facMassFlowLdCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S12>/Constant17'
   *  Constant: '<S50>/Byp_Fonction_SC'
   *  Constant: '<S50>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facOfsEfcCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facOfsEfcCorInport2' */
  Rte_Write_P_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S12>/Constant18'
   *  Constant: '<S51>/Byp_Fonction_SC'
   *  Constant: '<S51>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facOfsEfcPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facOfsEfcPredInport2' */
  Rte_Write_P_EngM_facOfsEfcPred_EngM_facOfsEfcPred
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S12>/Constant19'
   *  Constant: '<S52>/Byp_Fonction_SC'
   *  Constant: '<S52>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facOfsEfcReq_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facOfsEfcReqInport2' */
  Rte_Write_P_EngM_facOfsEfcReq_EngM_facOfsEfcReq
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S12>/Constant20'
   *  Constant: '<S54>/Byp_Fonction_SC'
   *  Constant: '<S54>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facSlopEfcCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 29789U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facSlopEfcCorInport2' */
  Rte_Write_P_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S12>/Constant21'
   *  Constant: '<S55>/Byp_Fonction_SC'
   *  Constant: '<S55>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facSlopEfcPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 29789U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facSlopEfcPredInport2' */
  Rte_Write_P_EngM_facSlopEfcPred_EngM_facSlopEfcPred
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S12>/Constant22'
   *  Constant: '<S56>/Byp_Fonction_SC'
   *  Constant: '<S56>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_facSlopEfcReq_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 29789U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facSlopEfcReqInport2' */
  Rte_Write_P_EngM_facSlopEfcReq_EngM_facSlopEfcReq
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S12>/Constant23'
   *  Constant: '<S57>/Byp_Fonction_SC'
   *  Constant: '<S57>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mAirCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 50335U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirCorInport2' */
  Rte_Write_P_EngM_mAirCor_EngM_mAirCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S12>/Constant24'
   *  Constant: '<S58>/Byp_Fonction_SC'
   *  Constant: '<S58>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_mAirEngCylMax_B;
  } else {
    localEngM_facMassAirScvCor = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirEngCylMaxInport2' */
  Rte_Write_P_EngM_mAirEngCylMax_EngM_mAirEngCylMax(localEngM_facMassAirScvCor);

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S12>/Constant25'
   *  Constant: '<S59>/Byp_Fonction_SC'
   *  Constant: '<S59>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_mAirEngCylMin_B;
  } else {
    localEngM_facMassAirScvCor = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirEngCylMinInport2' */
  Rte_Write_P_EngM_mAirEngCylMin_EngM_mAirEngCylMin(localEngM_facMassAirScvCor);

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S12>/Constant26'
   *  Constant: '<S60>/Byp_Fonction_SC'
   *  Constant: '<S60>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_mAirEngCylTrbMax_B;
  } else {
    localEngM_facMassAirScvCor = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirEngCylTrbMaxInport2' */
  Rte_Write_P_EngM_mAirEngCylTrbMax_EngM_mAirEngCylTrbMax
    (localEngM_facMassAirScvCor);

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S12>/Constant27'
   *  Constant: '<S61>/Byp_Fonction_SC'
   *  Constant: '<S61>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mAirPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 5453U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirPredInport2' */
  Rte_Write_P_EngM_mAirPred_EngM_mAirPred(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S12>/Constant28'
   *  Constant: '<S62>/Byp_Fonction_SC'
   *  Constant: '<S62>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mAirPredIn_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 5453U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirPredInInport2' */
  Rte_Write_P_EngM_mAirPredIn_EngM_mAirPredIn(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S12>/Constant29'
   *  Constant: '<S63>/Byp_Fonction_SC'
   *  Constant: '<S63>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor = EngM_mAirPresUsThr_B;
  } else {
    localEngM_facMassAirScvCor = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirPresUsThrInport2' */
  Rte_Write_P_EngM_mAirPresUsThr_EngM_mAirPresUsThr(localEngM_facMassAirScvCor);

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S12>/Constant30'
   *  Constant: '<S65>/Byp_Fonction_SC'
   *  Constant: '<S65>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mAirScvCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mAirScvCorInport2' */
  Rte_Write_P_EngM_mAirScvCor_EngM_mAirScvCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S12>/Constant31'
   *  Constant: '<S66>/Byp_Fonction_SC'
   *  Constant: '<S66>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mBurnCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mBurnCorInport2' */
  Rte_Write_P_EngM_mBurnCor_EngM_mBurnCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S12>/Constant32'
   *  Constant: '<S67>/Byp_Fonction_SC'
   *  Constant: '<S67>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mTotExPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 5453U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mTotExPredInport2' */
  Rte_Write_P_EngM_mTotExPred_EngM_mTotExPred(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S12>/Constant33'
   *  Constant: '<S68>/Byp_Fonction_SC'
   *  Constant: '<S68>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mTotExPredIn_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 5453U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mTotExPredInInport2' */
  Rte_Write_P_EngM_mTotExPredIn_EngM_mTotExPredIn
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S12>/Constant34'
   *  Constant: '<S69>/Byp_Fonction_SC'
   *  Constant: '<S69>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfAirCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 43U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfAirCorInport2' */
  Rte_Write_P_EngM_mfAirCor_EngM_mfAirCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S12>/Constant35'
   *  Constant: '<S70>/Byp_Fonction_SC'
   *  Constant: '<S70>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfAirPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 393U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfAirPredInport2' */
  Rte_Write_P_EngM_mfAirPred_EngM_mfAirPred(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S12>/Constant36'
   *  Constant: '<S71>/Byp_Fonction_SC'
   *  Constant: '<S71>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfAirPredIn_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 393U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfAirPredInInport2' */
  Rte_Write_P_EngM_mfAirPredIn_EngM_mfAirPredIn(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S12>/Constant37'
   *  Constant: '<S72>/Byp_Fonction_SC'
   *  Constant: '<S72>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfAirScvCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfAirScvCorInport2' */
  Rte_Write_P_EngM_mfAirScvCor_EngM_mfAirScvCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S12>/Constant38'
   *  Constant: '<S73>/Byp_Fonction_SC'
   *  Constant: '<S73>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfTotExCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfTotExCorInport2' */
  Rte_Write_P_EngM_mfTotExCor_EngM_mfTotExCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S12>/Constant39'
   *  Constant: '<S74>/Byp_Fonction_SC'
   *  Constant: '<S74>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfTotExPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfTotExPredInport2' */
  Rte_Write_P_EngM_mfTotExPred_EngM_mfTotExPred(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S12>/Constant40'
   *  Constant: '<S76>/Byp_Fonction_SC'
   *  Constant: '<S76>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_mfTotExPredIn_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_mfTotExPredInInport2' */
  Rte_Write_P_EngM_mfTotExPredIn_EngM_mfTotExPredIn
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S77>/Switch' incorporates:
   *  Constant: '<S12>/Constant41'
   *  Constant: '<S77>/Byp_Fonction_SC'
   *  Constant: '<S77>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_pInMnfMinReq_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_pInMnfMinReqInport2' */
  Rte_Write_P_EngM_pInMnfMinReq_EngM_pInMnfMinReq
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S78>/Switch' incorporates:
   *  Constant: '<S12>/Constant42'
   *  Constant: '<S12>/Constant43'
   *  Constant: '<S12>/Constant44'
   *  Constant: '<S12>/Constant45'
   *  Constant: '<S12>/Constant46'
   *  Constant: '<S12>/Constant47'
   *  Constant: '<S78>/Byp_Fonction_SC'
   *  Constant: '<S78>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mAirPredInCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 5453U;
    localEngM_prm_mAirPredInCyl[1] = 5453U;
    localEngM_prm_mAirPredInCyl[2] = 5453U;
    localEngM_prm_mAirPredInCyl[3] = 5453U;
    localEngM_prm_mAirPredInCyl[4] = 5453U;
    localEngM_prm_mAirPredInCyl[5] = 5453U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredInCylInport2' */
  Rte_Write_P_EngM_prm_mAirPredInCyl_EngM_prm_mAirPredInCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S12>/Constant48'
   *  Constant: '<S12>/Constant49'
   *  Constant: '<S12>/Constant50'
   *  Constant: '<S12>/Constant51'
   *  Constant: '<S12>/Constant52'
   *  Constant: '<S12>/Constant53'
   *  Constant: '<S79>/Byp_Fonction_SC'
   *  Constant: '<S79>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mAirScvCorCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 0U;
    localEngM_prm_mAirPredInCyl[1] = 0U;
    localEngM_prm_mAirPredInCyl[2] = 0U;
    localEngM_prm_mAirPredInCyl[3] = 0U;
    localEngM_prm_mAirPredInCyl[4] = 0U;
    localEngM_prm_mAirPredInCyl[5] = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirScvCorCylInport2' */
  Rte_Write_P_EngM_prm_mAirScvCorCyl_EngM_prm_mAirScvCorCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S80>/Switch' incorporates:
   *  Constant: '<S12>/Constant54'
   *  Constant: '<S12>/Constant55'
   *  Constant: '<S12>/Constant56'
   *  Constant: '<S12>/Constant57'
   *  Constant: '<S12>/Constant58'
   *  Constant: '<S12>/Constant59'
   *  Constant: '<S80>/Byp_Fonction_SC'
   *  Constant: '<S80>/Int_BypC'
   *  DataTypeConversion: '<S80>/Data Type Conversion'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mfAirCorCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 43U;
    localEngM_prm_mAirPredInCyl[1] = 43U;
    localEngM_prm_mAirPredInCyl[2] = 43U;
    localEngM_prm_mAirPredInCyl[3] = 43U;
    localEngM_prm_mAirPredInCyl[4] = 43U;
    localEngM_prm_mAirPredInCyl[5] = 43U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirCorCylInport2' */
  Rte_Write_P_EngM_prm_mfAirCorCyl_EngM_prm_mfAirCorCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S12>/Constant60'
   *  Constant: '<S12>/Constant61'
   *  Constant: '<S12>/Constant62'
   *  Constant: '<S12>/Constant63'
   *  Constant: '<S12>/Constant64'
   *  Constant: '<S12>/Constant65'
   *  Constant: '<S81>/Byp_Fonction_SC'
   *  Constant: '<S81>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mfAirPredInCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 393U;
    localEngM_prm_mAirPredInCyl[1] = 393U;
    localEngM_prm_mAirPredInCyl[2] = 393U;
    localEngM_prm_mAirPredInCyl[3] = 393U;
    localEngM_prm_mAirPredInCyl[4] = 393U;
    localEngM_prm_mAirPredInCyl[5] = 393U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredInCylInport2' */
  Rte_Write_P_EngM_prm_mfAirPredInCyl_EngM_prm_mfAirPredInCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S12>/Constant66'
   *  Constant: '<S12>/Constant67'
   *  Constant: '<S12>/Constant68'
   *  Constant: '<S12>/Constant69'
   *  Constant: '<S12>/Constant70'
   *  Constant: '<S12>/Constant71'
   *  Constant: '<S82>/Byp_Fonction_SC'
   *  Constant: '<S82>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mfAirScvCorCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 0U;
    localEngM_prm_mAirPredInCyl[1] = 0U;
    localEngM_prm_mAirPredInCyl[2] = 0U;
    localEngM_prm_mAirPredInCyl[3] = 0U;
    localEngM_prm_mAirPredInCyl[4] = 0U;
    localEngM_prm_mAirPredInCyl[5] = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirScvCorCylInport2' */
  Rte_Write_P_EngM_prm_mfAirScvCorCyl_EngM_prm_mfAirScvCorCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S12>/Constant72'
   *  Constant: '<S12>/Constant73'
   *  Constant: '<S12>/Constant74'
   *  Constant: '<S12>/Constant75'
   *  Constant: '<S12>/Constant76'
   *  Constant: '<S12>/Constant77'
   *  Constant: '<S83>/Byp_Fonction_SC'
   *  Constant: '<S83>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_mfTotExCorCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 0U;
    localEngM_prm_mAirPredInCyl[1] = 0U;
    localEngM_prm_mAirPredInCyl[2] = 0U;
    localEngM_prm_mAirPredInCyl[3] = 0U;
    localEngM_prm_mAirPredInCyl[4] = 0U;
    localEngM_prm_mAirPredInCyl[5] = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfTotExCorCylInport2' */
  Rte_Write_P_EngM_prm_mfTotExCorCyl_EngM_prm_mfTotExCorCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S12>/Constant78'
   *  Constant: '<S12>/Constant79'
   *  Constant: '<S12>/Constant80'
   *  Constant: '<S12>/Constant81'
   *  Constant: '<S12>/Constant82'
   *  Constant: '<S12>/Constant83'
   *  Constant: '<S84>/Byp_Fonction_SC'
   *  Constant: '<S84>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_rAirLdPredInCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 16384U;
    localEngM_prm_mAirPredInCyl[1] = 16384U;
    localEngM_prm_mAirPredInCyl[2] = 16384U;
    localEngM_prm_mAirPredInCyl[3] = 16384U;
    localEngM_prm_mAirPredInCyl[4] = 16384U;
    localEngM_prm_mAirPredInCyl[5] = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredInCylInport2' */
  Rte_Write_P_EngM_prm_rAirLdPredInCyl_EngM_prm_rAirLdPredInCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S12>/Constant84'
   *  Constant: '<S12>/Constant85'
   *  Constant: '<S12>/Constant86'
   *  Constant: '<S12>/Constant87'
   *  Constant: '<S12>/Constant88'
   *  Constant: '<S12>/Constant89'
   *  Constant: '<S85>/Byp_Fonction_SC'
   *  Constant: '<S85>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    for (locali = 0; locali < 6; locali++) {
      localEngM_prm_mAirPredInCyl[locali] = EngM_prm_rTotLdExCorCyl_B[(locali)];
    }
  } else {
    localEngM_prm_mAirPredInCyl[0] = 16384U;
    localEngM_prm_mAirPredInCyl[1] = 16384U;
    localEngM_prm_mAirPredInCyl[2] = 16384U;
    localEngM_prm_mAirPredInCyl[3] = 16384U;
    localEngM_prm_mAirPredInCyl[4] = 16384U;
    localEngM_prm_mAirPredInCyl[5] = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rTotLdExCorCylInport2' */
  Rte_Write_P_EngM_prm_rTotLdExCorCyl_EngM_prm_rTotLdExCorCyl
    (&localEngM_prm_mAirPredInCyl);

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S12>/Constant91'
   *  Constant: '<S87>/Byp_Fonction_SC'
   *  Constant: '<S87>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rAirLdCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rAirLdCorInport2' */
  Rte_Write_P_EngM_rAirLdCor_EngM_rAirLdCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S12>/Constant90'
   *  Constant: '<S88>/Byp_Fonction_SC'
   *  Constant: '<S88>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rAirLdPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rAirLdPredInport2' */
  Rte_Write_P_EngM_rAirLdPred_EngM_rAirLdPred(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S89>/Switch' incorporates:
   *  Constant: '<S12>/Constant92'
   *  Constant: '<S89>/Byp_Fonction_SC'
   *  Constant: '<S89>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rAirLdPredIn_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rAirLdPredInInport2' */
  Rte_Write_P_EngM_rAirLdPredIn_EngM_rAirLdPredIn
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S12>/Constant93'
   *  Constant: '<S90>/Byp_Fonction_SC'
   *  Constant: '<S90>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvEstimRef1 = EngM_rDeltaLdInjPha_B;
  } else {
    localEngM_agCkClsExVlvEstimRef1 = 0;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rDeltaLdInjPhaInport2' */
  Rte_Write_P_EngM_rDeltaLdInjPha_EngM_rDeltaLdInjPha
    (localEngM_agCkClsExVlvEstimRef1);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S12>/Constant97'
   *  Constant: '<S91>/Byp_Fonction_SC'
   *  Constant: '<S91>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rItBurnRateCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rItBurnRateCorInport2' */
  Rte_Write_P_EngM_rItBurnRateCor_EngM_rItBurnRateCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S12>/Constant96'
   *  Constant: '<S92>/Byp_Fonction_SC'
   *  Constant: '<S92>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rMassAirResiCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMassAirResiCorInport2' */
  Rte_Write_P_EngM_rMassAirResiCor_EngM_rMassAirResiCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S12>/Constant95'
   *  Constant: '<S93>/Byp_Fonction_SC'
   *  Constant: '<S93>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rMassAirScvCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMassAirScvCorInport2' */
  Rte_Write_P_EngM_rMassAirScvCor_EngM_rMassAirScvCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S12>/Constant94'
   *  Constant: '<S94>/Byp_Fonction_SC'
   *  Constant: '<S94>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rMaxTotLd_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMaxTotLdInport2' */
  Rte_Write_P_EngM_rMaxTotLd_EngM_rMaxTotLd(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S12>/Constant98'
   *  Constant: '<S95>/Byp_Fonction_SC'
   *  Constant: '<S95>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rTotLdExCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rTotLdExCorInport2' */
  Rte_Write_P_EngM_rTotLdExCor_EngM_rTotLdExCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S96>/Switch' incorporates:
   *  Constant: '<S12>/Constant99'
   *  Constant: '<S96>/Byp_Fonction_SC'
   *  Constant: '<S96>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rTotLdExPred_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 16384U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rTotLdExPredInport2' */
  Rte_Write_P_EngM_rTotLdExPred_EngM_rTotLdExPred
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S12>/Constant100'
   *  Constant: '<S98>/Byp_Fonction_SC'
   *  Constant: '<S98>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_rltMassAirScvCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 0U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rltMassAirScvCorInport2' */
  Rte_Write_P_EngM_rltMassAirScvCor_EngM_rltMassAirScvCor
    (localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S12>/Constant101'
   *  Constant: '<S99>/Byp_Fonction_SC'
   *  Constant: '<S99>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_tBurnCylCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 2464U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_tBurnCylCorInport2' */
  Rte_Write_P_EngM_tBurnCylCor_EngM_tBurnCylCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S100>/Byp_Fonction_SC'
   *  Constant: '<S100>/Int_BypC'
   *  Constant: '<S12>/Constant102'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_tMixtCylCor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 2464U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_tMixtCylCorInport2' */
  Rte_Write_P_EngM_tMixtCylCor_EngM_tMixtCylCor(localEngM_agCkClsInVlvEstimRef0);

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Byp_Fonction_SC'
   *  Constant: '<S101>/Int_BypC'
   *  Constant: '<S12>/Constant103'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsInVlvEstimRef0 = EngM_tMixtCylGDICor_B;
  } else {
    localEngM_agCkClsInVlvEstimRef0 = 2464U;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_tMixtCylGDICorInport2' */
  Rte_Write_P_EngM_tMixtCylGDICor_EngM_tMixtCylGDICor
    (localEngM_agCkClsInVlvEstimRef0);

  /* SignalConversion: '<S112>/copy' incorporates:
   *  Constant: '<S12>/Constant104'
   */
  AirEfc_facChrExpFilCor_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S112>/autosar_testpoint1' */

  /* S-Function Block: <S112>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpFilCor_irvInport2' incorporates:
   *  Constant: '<S12>/Constant104'
   *  SignalConversion: '<S12>/Signal Conversion29'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpFilCor_irv(0U);

  /* SignalConversion: '<S113>/copy' incorporates:
   *  Constant: '<S12>/Constant105'
   */
  AirEfc_facChrExpFilPred_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S113>/autosar_testpoint1' */

  /* S-Function Block: <S113>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpFilPred_irvInport2' incorporates:
   *  Constant: '<S12>/Constant105'
   *  SignalConversion: '<S12>/Signal Conversion28'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpFilPred_irv(0U);

  /* SignalConversion: '<S114>/copy' incorporates:
   *  Constant: '<S12>/Constant106'
   */
  AirEfc_facChrExpScvFilCor_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S114>/autosar_testpoint1' */

  /* S-Function Block: <S114>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpScvFilCor_irvInport2' incorporates:
   *  Constant: '<S12>/Constant106'
   *  SignalConversion: '<S12>/Signal Conversion27'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpScvFilCor_irv(0U);

  /* SignalConversion: '<S115>/copy' incorporates:
   *  Constant: '<S12>/Constant107'
   */
  AirEfc_facChrExpScvFilPred = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S115>/autosar_testpoint1' */

  /* S-Function Block: <S115>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpScvFilPred_irvInport2' incorporates:
   *  Constant: '<S12>/Constant107'
   *  SignalConversion: '<S12>/Signal Conversion26'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpScvFilPred_irv(0U);

  /* SignalConversion: '<S116>/copy' incorporates:
   *  Constant: '<S12>/Constant108'
   */
  EngM_agCkClsInVlvReqRef1_IRV_MP = 128U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S116>/autosar_testpoint1' */

  /* S-Function Block: <S116>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_agCkClsInVlvReqRef1_irvInport2' incorporates:
   *  Constant: '<S12>/Constant108'
   *  SignalConversion: '<S12>/Signal Conversion24'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_agCkClsInVlvReqRef1_irv(128U);

  /* SignalConversion: '<S117>/copy' incorporates:
   *  Constant: '<S12>/Constant109'
   */
  EngM_facECor_IRV_MP = 256U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S117>/autosar_testpoint1' */

  /* S-Function Block: <S117>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facECor_irvInport2' incorporates:
   *  Constant: '<S12>/Constant109'
   *  SignalConversion: '<S12>/Signal Conversion25'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_facECor_irv(256U);

  /* SignalConversion: '<S118>/copy' incorporates:
   *  Constant: '<S12>/Constant110'
   */
  EngM_prm_mAirPredCyl_001_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S118>/autosar_testpoint1' */

  /* S-Function Block: <S118>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_001_irvInport2' incorporates:
   *  Constant: '<S12>/Constant110'
   *  SignalConversion: '<S12>/Signal Conversion23'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_001_irv(5453U);

  /* SignalConversion: '<S119>/copy' incorporates:
   *  Constant: '<S12>/Constant111'
   */
  EngM_prm_mAirPredCyl_002_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S119>/autosar_testpoint1' */

  /* S-Function Block: <S119>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_002_irvInport2' incorporates:
   *  Constant: '<S12>/Constant111'
   *  SignalConversion: '<S12>/Signal Conversion22'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_002_irv(5453U);

  /* SignalConversion: '<S120>/copy' incorporates:
   *  Constant: '<S12>/Constant112'
   */
  EngM_prm_mAirPredCyl_003_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S120>/autosar_testpoint1' */

  /* S-Function Block: <S120>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_003_irvInport2' incorporates:
   *  Constant: '<S12>/Constant112'
   *  SignalConversion: '<S12>/Signal Conversion21'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_003_irv(5453U);

  /* SignalConversion: '<S121>/copy' incorporates:
   *  Constant: '<S12>/Constant113'
   */
  EngM_prm_mAirPredCyl_004_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S121>/autosar_testpoint1' */

  /* S-Function Block: <S121>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_004_irvInport2' incorporates:
   *  Constant: '<S12>/Constant113'
   *  SignalConversion: '<S12>/Signal Conversion20'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_004_irv(5453U);

  /* SignalConversion: '<S25>/copy' incorporates:
   *  Constant: '<S12>/Constant114'
   */
  EngM_prm_mAirPredCyl_005_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S25>/autosar_testpoint1' */

  /* S-Function Block: <S25>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_005_irvInport2' incorporates:
   *  Constant: '<S12>/Constant114'
   *  SignalConversion: '<S12>/Signal Conversion19'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_005_irv(5453U);

  /* SignalConversion: '<S26>/copy' incorporates:
   *  Constant: '<S12>/Constant115'
   */
  EngM_prm_mAirPredCyl_006_IRV_MP = 5453U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S26>/autosar_testpoint1' */

  /* S-Function Block: <S26>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_006_irvInport2' incorporates:
   *  Constant: '<S12>/Constant115'
   *  SignalConversion: '<S12>/Signal Conversion18'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mAirPredCyl_006_irv(5453U);

  /* SignalConversion: '<S27>/copy' incorporates:
   *  Constant: '<S12>/Constant116'
   */
  EngM_prm_mfAirPredCyl_001_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S27>/autosar_testpoint1' */

  /* S-Function Block: <S27>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_001_irvInport2' incorporates:
   *  Constant: '<S12>/Constant116'
   *  SignalConversion: '<S12>/Signal Conversion17'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_001_irv(393U);

  /* SignalConversion: '<S28>/copy' incorporates:
   *  Constant: '<S12>/Constant117'
   */
  EngM_prm_mfAirPredCyl_002_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S28>/autosar_testpoint1' */

  /* S-Function Block: <S28>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_002_irvInport2' incorporates:
   *  Constant: '<S12>/Constant117'
   *  SignalConversion: '<S12>/Signal Conversion16'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_002_irv(393U);

  /* SignalConversion: '<S29>/copy' incorporates:
   *  Constant: '<S12>/Constant118'
   */
  EngM_prm_mfAirPredCyl_003_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S29>/autosar_testpoint1' */

  /* S-Function Block: <S29>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_003_irvInport2' incorporates:
   *  Constant: '<S12>/Constant118'
   *  SignalConversion: '<S12>/Signal Conversion15'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_003_irv(393U);

  /* SignalConversion: '<S30>/copy' incorporates:
   *  Constant: '<S12>/Constant119'
   */
  EngM_prm_mfAirPredCyl_004_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S30>/autosar_testpoint1' */

  /* S-Function Block: <S30>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_004_irvInport2' incorporates:
   *  Constant: '<S12>/Constant119'
   *  SignalConversion: '<S12>/Signal Conversion14'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_004_irv(393U);

  /* SignalConversion: '<S31>/copy' incorporates:
   *  Constant: '<S12>/Constant120'
   */
  EngM_prm_mfAirPredCyl_005_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S31>/autosar_testpoint1' */

  /* S-Function Block: <S31>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_005_irvInport2' incorporates:
   *  Constant: '<S12>/Constant120'
   *  SignalConversion: '<S12>/Signal Conversion13'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_005_irv(393U);

  /* SignalConversion: '<S32>/copy' incorporates:
   *  Constant: '<S12>/Constant121'
   */
  EngM_prm_mfAirPredCyl_006_IRV_MP = 393U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S32>/autosar_testpoint1' */

  /* S-Function Block: <S32>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_006_irvInport2' incorporates:
   *  Constant: '<S12>/Constant121'
   *  SignalConversion: '<S12>/Signal Conversion12'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_mfAirPredCyl_006_irv(393U);

  /* SignalConversion: '<S33>/copy' incorporates:
   *  Constant: '<S12>/Constant122'
   */
  EngM_prm_rAirLdPredCyl_001 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S33>/autosar_testpoint1' */

  /* S-Function Block: <S33>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_001_irvInport2' incorporates:
   *  Constant: '<S12>/Constant122'
   *  SignalConversion: '<S12>/Signal Conversion11'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_001_irv(16384U);

  /* SignalConversion: '<S34>/copy' incorporates:
   *  Constant: '<S12>/Constant123'
   */
  EngM_prm_rAirLdPredCyl_002 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S34>/autosar_testpoint1' */

  /* S-Function Block: <S34>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_002_irvInport2' incorporates:
   *  Constant: '<S12>/Constant123'
   *  SignalConversion: '<S12>/Signal Conversion10'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_002_irv(16384U);

  /* SignalConversion: '<S36>/copy' incorporates:
   *  Constant: '<S12>/Constant124'
   */
  EngM_prm_rAirLdPredCyl_003 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S36>/autosar_testpoint1' */

  /* S-Function Block: <S36>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_003_irvInport2' incorporates:
   *  Constant: '<S12>/Constant124'
   *  SignalConversion: '<S12>/Signal Conversion9'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_003_irv(16384U);

  /* SignalConversion: '<S37>/copy' incorporates:
   *  Constant: '<S12>/Constant125'
   */
  EngM_prm_rAirLdPredCyl_004 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S37>/autosar_testpoint1' */

  /* S-Function Block: <S37>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_004_irvInport2' incorporates:
   *  Constant: '<S12>/Constant125'
   *  SignalConversion: '<S12>/Signal Conversion8'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_004_irv(16384U);

  /* SignalConversion: '<S38>/copy' incorporates:
   *  Constant: '<S12>/Constant126'
   */
  EngM_prm_rAirLdPredCyl_005 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S38>/autosar_testpoint1' */

  /* S-Function Block: <S38>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_005_irvInport2' incorporates:
   *  Constant: '<S12>/Constant126'
   *  SignalConversion: '<S12>/Signal Conversion7'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_005_irv(16384U);

  /* SignalConversion: '<S39>/copy' incorporates:
   *  Constant: '<S12>/Constant127'
   */
  EngM_prm_rAirLdPredCyl_006 = 16384U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S39>/autosar_testpoint1' */

  /* S-Function Block: <S39>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_006_irvInport2' incorporates:
   *  Constant: '<S12>/Constant127'
   *  SignalConversion: '<S12>/Signal Conversion6'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_prm_rAirLdPredCyl_006_irv(16384U);

  /* SignalConversion: '<S40>/copy' incorporates:
   *  Constant: '<S12>/Constant128'
   */
  EngM_rMaxAvlLd_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S40>/autosar_testpoint1' */

  /* S-Function Block: <S40>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMaxAvlLd_irvInport2' incorporates:
   *  Constant: '<S12>/Constant128'
   *  SignalConversion: '<S12>/Signal Conversion5'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_rMaxAvlLd_irv(0U);

  /* SignalConversion: '<S41>/copy' incorporates:
   *  Constant: '<S12>/Constant129'
   */
  EngM_rMinTotLd_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S41>/autosar_testpoint1' */

  /* S-Function Block: <S41>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rMinTotLd_irvInport2' incorporates:
   *  Constant: '<S12>/Constant129'
   *  SignalConversion: '<S12>/Signal Conversion4'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_rMinTotLd_irv(0U);

  /* SignalConversion: '<S43>/copy' incorporates:
   *  Constant: '<S12>/Constant131'
   */
  AirEfc_facChrExpScvFilReq_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S43>/autosar_testpoint1' */

  /* S-Function Block: <S43>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpScvFilReq_irvInport2' incorporates:
   *  Constant: '<S12>/Constant131'
   *  SignalConversion: '<S12>/Signal Conversion1'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpScvFilReq_irv(0U);

  /* SignalConversion: '<S42>/copy' incorporates:
   *  Constant: '<S12>/Constant130'
   */
  AirEfc_facChrExpFilReq_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S42>/autosar_testpoint1' */

  /* S-Function Block: <S42>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAirEfc_facChrExpFilReq_irvInport2' incorporates:
   *  Constant: '<S12>/Constant130'
   *  SignalConversion: '<S12>/Signal Conversion2'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_AirEfc_facChrExpFilReq_irv(0U);

  /* SignalConversion: '<S44>/copy' incorporates:
   *  Constant: '<S12>/Constant132'
   */
  InM_pDsThrPrev_IRV_MP = 12500U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S44>/autosar_testpoint1' */

  /* S-Function Block: <S44>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInM_pDsThrPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant132'
   *  SignalConversion: '<S12>/Signal Conversion3'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_InM_pDsThrPrev_irv(12500U);

  /* SignalConversion: '<S102>/copy' incorporates:
   *  Constant: '<S12>/Constant133'
   */
  EngM_rVolCylClsInVlvPrev_IRV_MP = 32768U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S102>/autosar_testpoint1' */

  /* S-Function Block: <S102>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rVolCylClsInVlvPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant133'
   *  SignalConversion: '<S12>/SignalConversion4'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_rVolCylClsInVlvPrev_irv(32768U);

  /* SignalConversion: '<S103>/copy' incorporates:
   *  Constant: '<S12>/Constant136'
   */
  EngM_facTAirUsInVlvPrev_IRV_MP = 32768U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S103>/autosar_testpoint1' */

  /* S-Function Block: <S103>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facTAirUsInVlvPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant136'
   *  SignalConversion: '<S12>/SignalConversion5'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_facTAirUsInVlvPrev_irv(32768U);

  /* SignalConversion: '<S104>/copy' incorporates:
   *  Constant: '<S12>/Constant137'
   */
  EngM_facTCoPrev_IRV_MP = 128U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S104>/autosar_testpoint1' */

  /* S-Function Block: <S104>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facTCoPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant137'
   *  SignalConversion: '<S12>/SignalConversion6'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_facTCoPrev_irv(128U);

  /* SignalConversion: '<S105>/copy' incorporates:
   *  Constant: '<S12>/Constant138'
   */
  EngM_facCorAtmSlopEfcPrev_IRV_MP = 32768U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S105>/autosar_testpoint1' */

  /* S-Function Block: <S105>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facCorAtmSlopEfcPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant138'
   *  SignalConversion: '<S12>/SignalConversion7'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_facCorAtmSlopEfcPrev_irv(32768U);

  /* SignalConversion: '<S106>/copy' incorporates:
   *  Constant: '<S12>/Constant139'
   */
  EngM_facCorBoostSlopEfcPrev_IRV_MP = 32768U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S106>/autosar_testpoint1' */

  /* S-Function Block: <S106>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_facCorBoostSlopEfcPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant139'
   *  SignalConversion: '<S12>/SignalConversion8'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_facCorBoostSlopEfcPrev_irv(32768U);

  /* SignalConversion: '<S107>/copy' incorporates:
   *  Constant: '<S12>/Constant134'
   */
  EngM_pDeltaCorSlopEfcPrev_IRV_MP = 500U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S107>/autosar_testpoint1' */

  /* S-Function Block: <S107>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_pDeltaCorSlopEfcPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant134'
   *  SignalConversion: '<S12>/SignalConversion9'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_pDeltaCorSlopEfcPrev_irv(500U);

  /* SignalConversion: '<S109>/copy' incorporates:
   *  Constant: '<S12>/Constant135'
   */
  EngM_pBegCorBoostSlopEfcPrev_IRV_MP = 11875U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S109>/autosar_testpoint1' */

  /* S-Function Block: <S109>/autosar_testpoint1 */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_pBegCorBoostSlopEfcPrev_irvInport2' incorporates:
   *  Constant: '<S12>/Constant135'
   *  SignalConversion: '<S12>/SignalConversion10'
   */
  Rte_IrvWrite_RE_EngMGslT_001_MSE_EngM_pBegCorBoostSlopEfcPrev_irv(11875U);
}

/* Output and update for exported function: RE_EngMGslT_002_TEV */
void RE_EngMGslT_002_TEV(void)
{
  /* local block i/o variables */
  UInt16 localDataTypeConversion_j;
  UInt16 localLookUpTable2D;
  UInt16 localSelector;
  UInt8 localTmpSignalConversionAtEng_n;
  Float32 localProduct4_d;
  Float32 localMerge81;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localTmpSignalConversionAtEn_jp;
  UInt16 localTmpSignalConversionAtEn_hj;
  UInt16 localEngM_mTotExPredIn_a;
  UInt16 localTmpSignalConversionAtInM_p[6];
  UInt16 localAssignment_o[6];
  UInt16 localAssignment_k[6];
  SInt32 locali;
  UInt16 locallocalTmpSignalConversionAt;
  UInt16 locallocalTmpSignalConversion_0;
  UInt16 locallocalTmpSignalConversion_1;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_InPredLdEstimIn'
   *
   * Block requirements for '<S1>/F01_InPredLdEstimIn':
   *  1. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_075.01 ;
   *  2. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_076.01 ;
   *  3. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_078.01 ;
   *  4. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_088.01 ;
   *  5. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_089.01 ;
   *  6. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_090.01 ;
   *  7. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_091.01 ;
   *  8. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_092.01 ;
   *  9. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_093.01 ;
   *  10. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_094.01 ;
   *  11. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_095.01 ;
   *  12. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  13. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  14. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  15. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_104.01 ;
   *  16. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_285.01 ;
   *  17. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_286.01 ;
   *  18. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_287.01 ;
   *  19. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_288.01 ;
   *  20. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_289.01 ;
   *  21. SubSystem "F01_InPredLdEstimIn" !Trace_To : VEMS_R_11_00998_269.02 ;
   */

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_rMassAirResiCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMassAirResiCor_INPUT'
   */
  Rte_Read_R_EngM_rMassAirResiCor_EngM_rMassAirResiCor
    (&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&locallocalTmpSignalConversion_1);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_facOfsEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor(&locallocalTmpSignalConversion_0);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslT_B.TmpSignalConversionAtExt_nEng_f);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtInM_prm_pDsThrPredCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredCyl'
   */
  Rte_Read_R_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl
    (&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&localTmpSignalConversionAtEng_n);

  /* Outputs for atomic SubSystem: '<S13>/F01_cylinder_mass_estimation' *
   * Block requirements for '<S13>/F01_cylinder_mass_estimation':
   *  1. SubSystem "F01_cylinder_mass_estimation" !Trace_To : VEMS_R_11_00998_079.01 ;
   */

  /* Selector: '<S130>/Selector' */
  localSelector =
    localTmpSignalConversionAtInM_p[localTmpSignalConversionAtEng_n - 1];

  /* If: '<S130>/If' incorporates:
   *  ActionPort: '<S137>/Action Port'
   *  ActionPort: '<S138>/Action Port'
   *  Constant: '<S130>/EngM_bTotLdEx_C'
   *  SubSystem: '<S130>/If Action Subsystem'
   *  SubSystem: '<S130>/If Action Subsystem1'
   */
  if (EngM_bTotLdEx_C) {
    /* DataTypeConversion: '<S141>/Data Type Conversion' */
    localDataTypeConversion_j = EngMGslT_B.TmpSignalConversionAtExt_nEng_f;

    /* Lookup2D: '<S141>/Look-Up Table (2-D)'
     * About '<S141>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U16  2^-14
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D), (&(EngM_rTotLdEx_M[0])),
                       localDataTypeConversion_j, (&(EngM_nEngY_A[0])), 17U,
                       localSelector, (&(EngM_pDsThr_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S141>/Data Type Duplicate2'
     *
     * Regarding '<S141>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* DataStoreWrite: '<S137>/MemoryStore1' */
    EngM_rTotLdEx_MP = localLookUpTable2D;

    /* DataTypeConversion: '<S137>/SignalConversion11' */
    localMerge81 = ((Float32)localLookUpTable2D) * 6.103515625E-005F;
  } else {
    /* Sum: '<S138>/Sum1' incorporates:
     *  DataTypeConversion: '<S138>/SignalConversion3'
     *  DataTypeConversion: '<S13>/SignalConversion5'
     *  DataTypeConversion: '<S13>/SignalConversion6'
     *  Product: '<S142>/Divide'
     */
    localMerge81 = ((((Float32)localSelector) * 8.0F) * (((Float32)
      locallocalTmpSignalConversion_1) * 3.356933620E-010F)) - (((Float32)
      locallocalTmpSignalConversionAt) * 6.103515625E-005F);
  }

  /* DataTypeConversion: '<S130>/SignalConversion1' incorporates:
   *  Constant: '<S130>/EngM_rTotLdExMin_C'
   */
  localProduct4_d = ((Float32)EngM_rTotLdExMin_C) * 6.103515625E-005F;

  /* MinMax: '<S130>/MinMax' */
  EngM_rTotLdExPredIn = rt_MAXf(localMerge81, localProduct4_d);

  /* DataTypeConversion: '<S139>/OutDTConv' incorporates:
   *  Constant: '<S139>/offset'
   *  Constant: '<S139>/one_on_slope'
   *  DataTypeConversion: '<S13>/SignalConversion2'
   *  DataTypeConversion: '<S13>/SignalConversion7'
   *  Product: '<S139>/Product4'
   *  Product: '<S140>/Divide'
   *  Sum: '<S130>/Sum2'
   *  Sum: '<S139>/Add1'
   */
  localProduct4_d = ((((((Float32)locallocalTmpSignalConversion_0) *
                        1.525878906E-005F) + 1.525878906E-005F) *
                      EngM_rTotLdExPredIn) + (((Float32)
    localTmpSignalConversionAtEngM_) * 6.103515625E-005F)) * 16384.0F;
  if (localProduct4_d < 65536.0F) {
    if (localProduct4_d >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt16)localProduct4_d;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* Assignment: '<S130>/Assignment' incorporates:
   *  SignalConversion: '<S130>/TmpSignal ConversionAtAssignmentInport1'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_001_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_002_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_003_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_004_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_005_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_006_irvOutport2'
   */
  localTmpSignalConversionAtInM_p[0] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_001_irv();
  localTmpSignalConversionAtInM_p[1] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_002_irv();
  localTmpSignalConversionAtInM_p[2] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_003_irv();
  localTmpSignalConversionAtInM_p[3] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_004_irv();
  localTmpSignalConversionAtInM_p[4] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_005_irv();
  localTmpSignalConversionAtInM_p[5] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_rAirLdPredCyl_006_irv();
  localTmpSignalConversionAtInM_p[localTmpSignalConversionAtEng_n - 1] =
    locallocalTmpSignalConversionAt;

  /* end of Outputs for SubSystem: '<S13>/F01_cylinder_mass_estimation' */

  /* DataTypeConversion: '<S13>/SignalConversion1' incorporates:
   *  Constant: '<S13>/EngM_mRef_C'
   */
  localMerge81 = ((Float32)EngM_mRef_C) * 1.192016583E-007F;

  /* Outputs for atomic SubSystem: '<S13>/F03_fresh_air_mass' *
   * Block requirements for '<S13>/F03_fresh_air_mass':
   *  1. SubSystem "F03_fresh_air_mass" !Trace_To : VEMS_R_11_00998_081.01 ;
   */

  /* DataTypeConversion: '<S144>/OutDTConv' incorporates:
   *  Constant: '<S144>/offset'
   *  Constant: '<S144>/one_on_slope'
   *  Product: '<S144>/Product4'
   *  Product: '<S145>/Divide'
   *  Sum: '<S144>/Add1'
   */
  localProduct4_d = ((((Float32)locallocalTmpSignalConversionAt) *
                      6.103515625E-005F) * localMerge81) * 8.389145E+006F;
  if (localProduct4_d < 65536.0F) {
    locallocalTmpSignalConversion_0 = (UInt16)localProduct4_d;
  } else {
    locallocalTmpSignalConversion_0 = MAX_uint16_T;
  }

  /* Assignment: '<S132>/Assignment' incorporates:
   *  SignalConversion: '<S132>/TmpSignal ConversionAtAssignmentInport1'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_001_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_002_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_003_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_004_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_005_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_006_irvOutport2'
   */
  localAssignment_o[0] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_001_irv();
  localAssignment_o[1] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_002_irv();
  localAssignment_o[2] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_003_irv();
  localAssignment_o[3] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_004_irv();
  localAssignment_o[4] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_005_irv();
  localAssignment_o[5] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mAirPredCyl_006_irv();
  localAssignment_o[localTmpSignalConversionAtEng_n - 1] =
    locallocalTmpSignalConversion_0;

  /* end of Outputs for SubSystem: '<S13>/F03_fresh_air_mass' */

  /* Switch: '<S122>/Switch' incorporates:
   *  Constant: '<S122>/Byp_Fonction_SC'
   *  Constant: '<S122>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversion_0 = EngM_mAirPredIn_B;
  }

  /* Switch: '<S123>/Switch' incorporates:
   *  Constant: '<S123>/Byp_Fonction_SC'
   *  Constant: '<S123>/Int_BypC'
   *  Constant: '<S135>/offset'
   *  Constant: '<S135>/one_on_slope'
   *  DataTypeConversion: '<S135>/OutDTConv'
   *  Product: '<S135>/Product4'
   *  Product: '<S143>/Divide'
   *  Sum: '<S135>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mTotExPredIn_a = EngM_mTotExPredIn_B;
  } else {
    localProduct4_d = (EngM_rTotLdExPredIn * localMerge81) * 8.389145E+006F;
    if (localProduct4_d < 65536.0F) {
      if (localProduct4_d >= 0.0F) {
        localEngM_mTotExPredIn_a = (UInt16)localProduct4_d;
      } else {
        localEngM_mTotExPredIn_a = 0U;
      }
    } else {
      localEngM_mTotExPredIn_a = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_facMassFlowLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facMassFlowLdCor_INPUT'
   */
  Rte_Read_R_EngM_facMassFlowLdCor_EngM_facMassFlowLdCor
    (&localTmpSignalConversionAtEn_jp);

  /* DataTypeConversion: '<S13>/SignalConversion4' */
  localMerge81 = ((Float32)localTmpSignalConversionAtEn_jp) * 6.103515716E-006F;

  /* Outputs for atomic SubSystem: '<S13>/F05_fresh_air_massflow' *
   * Block requirements for '<S13>/F05_fresh_air_massflow':
   *  1. SubSystem "F05_fresh_air_massflow" !Trace_To : VEMS_R_11_00998_083.01 ;
   */

  /* DataTypeConversion: '<S147>/OutDTConv' incorporates:
   *  Constant: '<S147>/offset'
   *  Constant: '<S147>/one_on_slope'
   *  Product: '<S147>/Product4'
   *  Product: '<S148>/Divide'
   *  Sum: '<S147>/Add1'
   */
  localProduct4_d = ((((Float32)locallocalTmpSignalConversionAt) *
                      6.103515625E-005F) * localMerge81) * 65536.0F;
  if (localProduct4_d < 65536.0F) {
    locallocalTmpSignalConversion_1 = (UInt16)localProduct4_d;
  } else {
    locallocalTmpSignalConversion_1 = MAX_uint16_T;
  }

  /* Assignment: '<S134>/Assignment' incorporates:
   *  SignalConversion: '<S134>/TmpSignal ConversionAtAssignmentInport1'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_001_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_002_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_003_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_004_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_005_irvOutport2'
   *  SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_006_irvOutport2'
   */
  localAssignment_k[0] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_001_irv();
  localAssignment_k[1] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_002_irv();
  localAssignment_k[2] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_003_irv();
  localAssignment_k[3] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_004_irv();
  localAssignment_k[4] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_005_irv();
  localAssignment_k[5] =
    Rte_IrvRead_RE_EngMGslT_002_TEV_EngM_prm_mfAirPredCyl_006_irv();
  localAssignment_k[localTmpSignalConversionAtEng_n - 1] =
    locallocalTmpSignalConversion_1;

  /* end of Outputs for SubSystem: '<S13>/F05_fresh_air_massflow' */

  /* Switch: '<S124>/Switch' incorporates:
   *  Constant: '<S124>/Byp_Fonction_SC'
   *  Constant: '<S124>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversion_1 = EngM_mfAirPredIn_B;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_rMassAirScvCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMassAirScvCor_INPUT'
   */
  Rte_Read_R_EngM_rMassAirScvCor_EngM_rMassAirScvCor
    (&localTmpSignalConversionAtEn_hj);

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Byp_Fonction_SC'
   *  Constant: '<S125>/Int_BypC'
   *  Constant: '<S136>/offset'
   *  Constant: '<S136>/one_on_slope'
   *  DataTypeConversion: '<S136>/OutDTConv'
   *  DataTypeConversion: '<S13>/SignalConversion8'
   *  Product: '<S136>/Product4'
   *  Product: '<S146>/Divide'
   *  Sum: '<S133>/Sum3'
   *  Sum: '<S136>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEngM_ = EngM_mfTotExPredIn_B;
  } else {
    localProduct4_d = (((((Float32)localTmpSignalConversionAtEn_hj) *
                         6.103515625E-005F) + EngM_rTotLdExPredIn) *
                       localMerge81) * 65536.0F;
    if (localProduct4_d < 65536.0F) {
      if (localProduct4_d >= 0.0F) {
        localTmpSignalConversionAtEngM_ = (UInt16)localProduct4_d;
      } else {
        localTmpSignalConversionAtEngM_ = 0U;
      }
    } else {
      localTmpSignalConversionAtEngM_ = MAX_uint16_T;
    }
  }

  for (locali = 0; locali < 6; locali++) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S126>/Byp_Fonction_SC'
     *  Constant: '<S126>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment_o[locali] = EngM_prm_mAirPredInCyl_B[(locali)];
    }

    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S127>/Byp_Fonction_SC'
     *  Constant: '<S127>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment_k[locali] = EngM_prm_mfAirPredInCyl_B[(locali)];
    }

    /* Switch: '<S128>/Switch' incorporates:
     *  Constant: '<S128>/Byp_Fonction_SC'
     *  Constant: '<S128>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtInM_p[locali] = EngM_prm_rAirLdPredInCyl_B
        [(locali)];
    }
  }

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/Byp_Fonction_SC'
   *  Constant: '<S129>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = EngM_rAirLdPredIn_B;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_mAirPredInInport2' */
  Rte_Write_P_EngM_mAirPredIn_EngM_mAirPredIn(locallocalTmpSignalConversion_0);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_mTotExPredInInport2' */
  Rte_Write_P_EngM_mTotExPredIn_EngM_mTotExPredIn(localEngM_mTotExPredIn_a);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_mfAirPredInInport2' */
  Rte_Write_P_EngM_mfAirPredIn_EngM_mfAirPredIn(locallocalTmpSignalConversion_1);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_mfTotExPredInInport2' */
  Rte_Write_P_EngM_mfTotExPredIn_EngM_mfTotExPredIn
    (localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mAirPredInCylInport2' */
  Rte_Write_P_EngM_prm_mAirPredInCyl_EngM_prm_mAirPredInCyl(&localAssignment_o);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_mfAirPredInCylInport2' */
  Rte_Write_P_EngM_prm_mfAirPredInCyl_EngM_prm_mfAirPredInCyl(&localAssignment_k);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_prm_rAirLdPredInCylInport2' */
  Rte_Write_P_EngM_prm_rAirLdPredInCyl_EngM_prm_rAirLdPredInCyl
    (&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEngM_rAirLdPredInInport2' */
  Rte_Write_P_EngM_rAirLdPredIn_EngM_rAirLdPredIn
    (locallocalTmpSignalConversionAt);
}

/*
 * Output and update for atomic system:
 *    '<S16>/F02_libEngLdM'
 *    '<S14>/F02_libEngLdM'
 *    '<S15>/F02_libEngLdM'
 */
void EngMGslT_F02_libEngLdM(UInt16 rtu_Ext_nEngRef, Float32
  rtu_EngM_agCkClsExVlvRef1, Float32 rtu_EngM_agCkClsInVlvRef1, Float32
  rtu_EngM_agCkOpInVlvRef1, UInt16 rtu_InM_tAirUsInVlvEstimRef, Float32
  rtu_ExM_tExMnfEstimRef, UInt16 rtu_InM_pDsThr, Float32
  rtu_ExM_pExMnfEstimRef, Float32 rtu_UsThrM_pAirExtEstimRef, UInt16
  rtu_InjSys_rlamEngCorReqRef, Float32 rtu_InM_pDsThrPred_facVlvOvlpRe, SInt16
  rtu_Ext_tCoMes, Float32 rtu_AirEfc_facChrExpFilPrev, Float32
  rtu_AirEfc_facChrExpScvFilPrev, UInt8 rtu_EngM_noAcvMPVal, Float32
  rtu_InjSys_agInj1BegRef, Float32 rtu_InjSys_agInj1EndRef, Float32
  rtu_InjSys_mFu1Inj, UInt16 rtu_InjSys_tFuRef, Float32
  rtu_EngM_facCorOfsEfcRef, Float32 rtu_EngM_facCorSlopEfcRef, UInt16
  rtu_InThM_nEngCorRef, Float32 rtu_InM_concAir, rtB_F02_libEngLdM_EngMGslT
  *localB)
{
  /* local block i/o variables */
  Float32 localAirEfc_rMassBurn;
  Float32 localAirEfc_pDsThrCorClsInVlv;
  Float32 localAirEfc_agInj1End;
  Float32 localAirEfc_rFuMassInj1InPha;

  /* Outputs for atomic SubSystem: '<S357>/AirEfcT' *
   * Block requirements for '<S357>/AirEfcT':
   *  1. SubSystem "AirEfcT" !Trace_To : VEMS_R_11_00998_260.03 ;
   */

  /* S-Function (sfun_autosar_clientop): '<S379>/Invoke AUTOSAR Server Operation' */
  Rte_Call_R_LibAirEfc_OP_LibAirEfc(rtu_Ext_nEngRef, rtu_EngM_agCkClsExVlvRef1,
    rtu_EngM_agCkClsInVlvRef1, rtu_EngM_agCkOpInVlvRef1,
    rtu_InM_tAirUsInVlvEstimRef, rtu_ExM_tExMnfEstimRef, rtu_InM_pDsThr,
    rtu_ExM_pExMnfEstimRef, rtu_UsThrM_pAirExtEstimRef,
    rtu_InjSys_rlamEngCorReqRef, rtu_InM_pDsThrPred_facVlvOvlpRe, rtu_Ext_tCoMes,
    rtu_AirEfc_facChrExpFilPrev, rtu_AirEfc_facChrExpScvFilPrev,
    rtu_EngM_noAcvMPVal, rtu_InjSys_agInj1BegRef, rtu_InjSys_agInj1EndRef,
    rtu_InjSys_mFu1Inj, rtu_InjSys_tFuRef, rtu_EngM_facCorOfsEfcRef,
    rtu_EngM_facCorSlopEfcRef, rtu_InThM_nEngCorRef, &localAirEfc_rMassBurn,
    &localB->AirEfc_rMassAirResi, &localB->AirEfc_facSlopEfc,
    &localB->AirEfc_facOfsEfc, &localB->AirEfc_rMassAirScv,
    &localAirEfc_pDsThrCorClsInVlv, &localB->AirEfc_tBurnCyl,
    &localB->AirEfc_rVolCylClsInVlv, &localB->AirEfc_facMassFlowLd,
    &localB->AirEfc_facChrExpFil, &localB->AirEfc_facChrExpScvFil,
    &localB->AirEfc_facMassAirScv, &localAirEfc_agInj1End,
    &localAirEfc_rFuMassInj1InPha, &localB->AirEfc_rDeltaLdInjPhaRef,
    &localB->AirEfc_facTAirUsInVlv, &localB->AirEfc_facTCo,
    &localB->AirEfc_facCorAtmSlopEfc, &localB->AirEfc_facCorBoostSlopEfc,
    &localB->AirEfc_pBegCorBoostSlopEfc, &localB->AirEfc_pDeltaCorSlopEfc);

  /* end of Outputs for SubSystem: '<S357>/AirEfcT' */

  /* Outputs for atomic SubSystem: '<S357>/EngCylPrmT' */

  /* S-Function (sfun_autosar_clientop): '<S380>/Invoke AUTOSAR Server Operation'
   *
   * Block requirements for '<S380>/Invoke AUTOSAR Server Operation':
   *  1. S-Function "Invoke AUTOSAR Server Operation" !Trace_To : VEMS_R_11_00998_052.01 ;
   */
  Rte_Call_R_LibEngCylPrm_OP_LibEngCylPrm(rtu_InM_tAirUsInVlvEstimRef,
    localB->AirEfc_tBurnCyl, rtu_InM_pDsThr, localB->AirEfc_facOfsEfc,
    localB->AirEfc_facSlopEfc, localB->AirEfc_rMassAirResi,
    localAirEfc_rMassBurn, localB->AirEfc_rMassAirScv,
    localB->AirEfc_facMassFlowLd, rtu_InM_concAir, localAirEfc_pDsThrCorClsInVlv,
    localB->AirEfc_rVolCylClsInVlv, rtu_Ext_nEngRef, rtu_EngM_noAcvMPVal,
    rtu_InjSys_tFuRef, rtu_EngM_agCkClsInVlvRef1, localAirEfc_agInj1End,
    localAirEfc_rFuMassInj1InPha, &localB->EngM_rItBurnRate,
    &localB->EngM_tMixtCyl, &localB->EngM_rAirLd, &localB->EngM_rTotLdEx,
    &localB->EngM_mfAirScv, &localB->EngM_mAir, &localB->EngM_mfAir,
    &localB->EngM_mTotEx, &localB->EngM_mfTotEx, &localB->EngM_mBurn,
    &localB->EngM_mAirScv, &localB->EngM_tMixtCylGDI,
    &localB->EngM_rltMassAirScv);

  /* end of Outputs for SubSystem: '<S357>/EngCylPrmT' */
}

/* Start for exported function: RE_EngMGslT_020_TEV */
void RE_EngMGslT_020_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IntkPredLoaEstimn'
   *
   * Block requirements for '<S1>/F01_IntkPredLoaEstimn':
   *  1. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_040.02 ;
   *  2. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_041.02 ;
   *  3. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_042.01 ;
   *  4. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  5. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  6. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_104.01 ;
   *  7. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_159.01 ;
   *  8. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  9. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_184.01 ;
   *  10. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_185.01 ;
   *  11. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_186.01 ;
   *  12. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_187.02 ;
   *  13. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_188.01 ;
   *  14. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_189.01 ;
   *  15. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_190.01 ;
   *  16. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_192.01 ;
   *  17. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_191.02 ;
   *  18. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_193.01 ;
   *  19. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_194.01 ;
   *  20. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_195.01 ;
   *  21. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_228.02 ;
   *  22. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_229.02 ;
   *  23. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_230.02 ;
   *  24. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_231.02 ;
   *  25. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_232.02 ;
   *  26. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_233.02 ;
   *  27. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_234.02 ;
   *  28. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_235.02 ;
   *  29. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_236.02 ;
   *  30. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_237.02 ;
   *  31. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_238.02 ;
   *  32. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_239.02 ;
   *  33. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_240.02 ;
   *  34. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_241.02 ;
   *  35. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_242.02 ;
   *  36. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_243.02 ;
   *  37. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_244.02 ;
   *  38. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_245.02 ;
   *  39. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_250.02 ;
   *  40. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_251.02 ;
   *  41. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_278.01 ;
   *  42. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_279.01 ;
   *  43. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_280.01 ;
   *  44. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_274.03 ;
   *  45. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : CSMT_CGMT09_0051_2.FR.3.0 ;
   *  46. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : CSMT_CGMT09_0051_2.FR.4.0 ;
   *  47. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_046.01 ;
   *  48. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_043.01 ;
   *  49. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  50. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  51. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_160.01 ;
   *  52. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  53. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_162.04 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_020_TEV */
void RE_EngMGslT_020_TEV(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion8;
  Float32 localDataTypeConversion9;
  Float32 localDataTypeConversion10;
  Float32 localDataTypeConversion1;
  Float32 localDataTypeConversion12;
  Float32 localDataTypeConversion13;
  Float32 localDataTypeConversion2;
  Float32 localDataTypeConversion20;
  Float32 localDataTypeConversion3;
  Float32 localDataTypeConversion7;
  Float32 localDataTypeConversion15;
  Float32 localDataTypeConversion17;
  Float32 localDataTypeConversion18;
  Float32 localDataTypeConversion21;
  Float32 localDataTypeConversion22;
  UInt16 localSignalConversion12;
  UInt16 localTmpSignalConversionAtSi_jw;
  UInt16 localAssignment2[6];
  UInt16 localAssignment2_h[6];
  UInt16 localOutDTConv_o;
  UInt16 localOutDTConv_n;
  UInt16 localSelector8;
  UInt16 localTmpSignalConversionAtSi_cr;
  UInt16 localAssignment1[6];
  UInt16 localDataTypeConversion16;
  UInt16 localDataTypeConversion4;
  Float32 localTmpSignalConversionAtSig_j;
  Float32 localTmpSignalConversionAtSig_n;
  Float32 localTmpSignalConversionAtSig_o;
  Float32 localTmpSignalConversionAtSig_f;
  Float32 localTmpSignalConversionAtSig_c;
  Float32 localTmpSignalConversionAtSig_i;
  UInt8 localTmpSignalConversionAtEn_gz;
  UInt8 localTmpSignalConversionAtEn_du;
  UInt8 localTmpSignalConversionAtEn_n3;
  UInt16 localTmpSignalConversionAtInThM;
  UInt8 localTmpSignalConversionAtEn_li;
  UInt16 localAirEfc_facChrExpScvFilPr_c;
  UInt16 localEngM_prm_mfAirPredCyl_00_h;
  UInt16 localEngM_prm_mfAirPredCyl_00_m;
  UInt16 localEngM_prm_mfAirPredCyl_00_n;
  UInt16 localEngM_prm_mfAirPredCyl_00_d;
  UInt16 localEngM_prm_mAirPredCyl_004_j;
  UInt16 localEngM_prm_mAirPredCyl_005_o;
  UInt16 localEngM_prm_mAirPredCyl_006_l;
  UInt16 localEngM_prm_mfAirPredCyl_00_a;
  UInt16 localEngM_prm_mAirPredCyl_001_g;
  UInt16 localEngM_prm_mAirPredCyl_002_k;
  UInt16 localEngM_prm_mAirPredCyl_003_l;
  UInt16 localEngM_prm_rAirLdPredCyl_0_p;
  UInt16 localEngM_prm_rAirLdPredCyl_0_b;
  UInt16 localEngM_prm_rAirLdPredCyl_0_e;
  UInt16 localEngM_prm_rAirLdPredCyl_0_m;
  UInt16 localEngM_prm_rAirLdPredCyl_0_c;
  UInt16 localEngM_prm_rAirLdPredCyl_0_n;
  UInt16 localEngM_prm_mfAirPredCyl_0_au;
  UInt16 localEngM_mTotExPred_p;
  UInt16 localEngM_mfTotExPred_c;
  UInt16 localEngM_rTotLdExPred_i;
  SInt16 localTmpSignalConversionAtEn_pu;
  SInt16 localTmpSignalConversionAtEng_o;
  UInt16 localTmpSignalConversionAtInj_l[6];
  UInt16 localTmpSignalConversionAtExM_d[6];
  UInt16 localTmpSignalConversionAtExM_p[6];
  UInt16 localTmpSignalConversionAtInjSy[6];
  UInt16 localTmpSignalConversionAtInM_k[6];
  UInt16 localTmpSignalConversionAtInj_a[6];
  UInt16 localTmpSignalConversionAtIn_pn[6];
  UInt16 localTmpSignalConversionAtInj_j[6];
  UInt16 localTmpSignalConversionAtInj_c[6];
  UInt16 localTmpSignalConversionAtIn_la[6];
  SInt16 localTmpSignalConversionAtEn_ng;
  UInt16 localTmpSignalConversionAtEn_hg;
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalTmpSignalConversionAt;
  UInt16 locallocalTmpSignalConversion_0;
  UInt16 locallocalTmpSignalConversion_1;
  UInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IntkPredLoaEstimn'
   *
   * Block requirements for '<S1>/F01_IntkPredLoaEstimn':
   *  1. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_040.02 ;
   *  2. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_041.02 ;
   *  3. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_042.01 ;
   *  4. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  5. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  6. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_104.01 ;
   *  7. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_159.01 ;
   *  8. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  9. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_184.01 ;
   *  10. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_185.01 ;
   *  11. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_186.01 ;
   *  12. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_187.02 ;
   *  13. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_188.01 ;
   *  14. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_189.01 ;
   *  15. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_190.01 ;
   *  16. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_192.01 ;
   *  17. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_191.02 ;
   *  18. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_193.01 ;
   *  19. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_194.01 ;
   *  20. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_195.01 ;
   *  21. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_228.02 ;
   *  22. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_229.02 ;
   *  23. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_230.02 ;
   *  24. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_231.02 ;
   *  25. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_232.02 ;
   *  26. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_233.02 ;
   *  27. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_234.02 ;
   *  28. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_235.02 ;
   *  29. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_236.02 ;
   *  30. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_237.02 ;
   *  31. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_238.02 ;
   *  32. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_239.02 ;
   *  33. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_240.02 ;
   *  34. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_241.02 ;
   *  35. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_242.02 ;
   *  36. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_243.02 ;
   *  37. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_244.02 ;
   *  38. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_245.02 ;
   *  39. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_250.02 ;
   *  40. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_251.02 ;
   *  41. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_278.01 ;
   *  42. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_279.01 ;
   *  43. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_280.01 ;
   *  44. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_274.03 ;
   *  45. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : CSMT_CGMT09_0051_2.FR.3.0 ;
   *  46. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : CSMT_CGMT09_0051_2.FR.4.0 ;
   *  47. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_046.01 ;
   *  48. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_043.01 ;
   *  49. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  50. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  51. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_160.01 ;
   *  52. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  53. SubSystem "F01_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_162.04 ;
   */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslT_B.TmpSignalConversionAtExt_nEng_e);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&localTmpSignalConversionAtEn_pu);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsInVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&localTmpSignalConversionAtEng_o);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&locallocalTmpSignalConversion_0);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tExMnfEstimCyl'
   */
  Rte_Read_R_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl
    (&localTmpSignalConversionAtExM_d);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pExMnfEstimOvlpCyl'
   */
  Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&localTmpSignalConversionAtExM_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInM_prm_pDsThrPredCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredCyl'
   */
  Rte_Read_R_InM_prm_pDsThrPredCyl_InM_prm_pDsThrPredCyl
    (&EngMGslT_B.TmpSignalConversionAtInM_prm__c);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&EngMGslT_B.TmpSignalConversionAtUsThrM_p_e);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp
    (&EngMGslT_B.TmpSignalConversionAtFARSp_rM_o);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredOvlpCyl'
   */
  Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&localTmpSignalConversionAtIn_pn);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInM_prm_concAirPredCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_concAirPredCyl'
   */
  Rte_Read_R_InM_prm_concAirPredCyl_InM_prm_concAirPredCyl
    (&localTmpSignalConversionAtInM_k);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&EngMGslT_B.TmpSignalConversionAtEng_noIn_d);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_agBegInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl
    (&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_agEndInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl
    (&localTmpSignalConversionAtInj_l);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_mFuInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl
    (&localTmpSignalConversionAtInj_a);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtFuSysM_tFuOutport2' incorporates:
   *  Inport: '<Root>/FuSysM_tFu'
   */
  Rte_Read_R_FuSysM_tFu_FuSysM_tFu(&locallocalTmpSignalConversion_1);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_facCorOfsEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorOfsEfc'
   */
  Rte_Read_R_EngM_facCorOfsEfc_EngM_facCorOfsEfc
    (&localTmpSignalConversionAtEn_ng);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_facCorSlopEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorSlopEfc'
   */
  Rte_Read_R_EngM_facCorSlopEfc_EngM_facCorSlopEfc
    (&localTmpSignalConversionAtEn_hg);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_agBegInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl
    (&localTmpSignalConversionAtInj_j);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_agEndInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl
    (&localTmpSignalConversionAtInj_c);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInjSys_prm_mFuInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl
    (&localTmpSignalConversionAtIn_la);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&localTmpSignalConversionAtEn_n3);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl(&localTmpSignalConversionAtEn_gz);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEng_noCmbCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmbCyl'
   */
  Rte_Read_R_Eng_noCmbCyl_Eng_noCmbCyl(&localTmpSignalConversionAtEn_du);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor(&localTmpSignalConversionAtInThM);

  /* Outputs for atomic SubSystem: '<S16>/F03_Input_Interface_IntkPredLoaEstimn'
   * Block description for '<S16>/F03_Input_Interface_IntkPredLoaEstimn':
   *  CSMT_CGMT09_0051_2.FR.5.2
   *
   * Block requirements for '<S16>/F03_Input_Interface_IntkPredLoaEstimn':
   *  1. SubSystem "F03_Input_Interface_IntkPredLoaEstimn" !Trace_To : VEMS_R_11_00998_044.02 ;
   */

  /* SignalConversion: '<S358>/Signal Conversion12' */
  localSignalConversion12 = EngMGslT_B.TmpSignalConversionAtExt_nEng_e;

  /* DataTypeConversion: '<S358>/Data Type Conversion8' */
  localDataTypeConversion8 = ((Float32)localTmpSignalConversionAtEn_pu) *
    0.09375F;

  /* DataTypeConversion: '<S358>/Data Type Conversion9' */
  localDataTypeConversion9 = (((Float32)locallocalTmpSignalConversionAt) *
    0.09375F) + 84.0F;

  /* DataTypeConversion: '<S358>/Data Type Conversion10' */
  localDataTypeConversion10 = ((Float32)localTmpSignalConversionAtEng_o) *
    0.09375F;

  /* SignalConversion: '<S358>/TmpSignal ConversionAtSignal Conversion7Inport1' */
  localTmpSignalConversionAtSi_cr = locallocalTmpSignalConversion_0;

  /* MultiPortSwitch: '<S358>/Multiport Switch' incorporates:
   *  Constant: '<S358>/EngM_noPhaInjPredLoaEstimn_C'
   */
  switch (EngM_noPhaInjPredLoaEstimn_C + 1) {
   case 1:
    localTmpSignalConversionAtEn_gz = EngMGslT_B.TmpSignalConversionAtEng_noIn_d;
    break;

   case 2:
    break;

   case 3:
    localTmpSignalConversionAtEn_gz = localTmpSignalConversionAtEn_du;
    break;

   default:
    localTmpSignalConversionAtEn_gz = localTmpSignalConversionAtEn_n3;
    break;
  }

  /* DataTypeConversion: '<S358>/Data Type Conversion1' incorporates:
   *  Selector: '<S358>/Selector1'
   */
  localDataTypeConversion1 = ((Float32)
    localTmpSignalConversionAtInj_l[localTmpSignalConversionAtEn_gz - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S358>/Data Type Conversion12' incorporates:
   *  Selector: '<S358>/Selector10'
   */
  localDataTypeConversion12 = (((Float32)
    localTmpSignalConversionAtExM_d[EngMGslT_B.TmpSignalConversionAtEng_noIn_d -
    1]) * 0.03125F) + 223.0F;

  /* DataTypeConversion: '<S358>/Data Type Conversion13' incorporates:
   *  Selector: '<S358>/Selector9'
   */
  localDataTypeConversion13 = ((Float32)
    localTmpSignalConversionAtExM_p[EngMGslT_B.TmpSignalConversionAtEng_noIn_d -
    1]) * 8.0F;

  /* DataTypeConversion: '<S358>/Data Type Conversion2' incorporates:
   *  Selector: '<S358>/Selector'
   */
  localDataTypeConversion2 = ((Float32)
    localTmpSignalConversionAtInjSy[localTmpSignalConversionAtEn_gz - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S358>/Data Type Conversion20' incorporates:
   *  Selector: '<S358>/Selector7'
   */
  localDataTypeConversion20 = (((Float32)
    localTmpSignalConversionAtInM_k[localTmpSignalConversionAtEn_n3 - 1]) *
    1.525878906E-005F) + 1.525878906E-005F;

  /* DataTypeConversion: '<S358>/Data Type Conversion3' incorporates:
   *  Selector: '<S358>/Selector2'
   */
  localDataTypeConversion3 = ((Float32)
    localTmpSignalConversionAtInj_a[localTmpSignalConversionAtEn_gz - 1]) *
    7.450580597E-009F;

  /* DataTypeConversion: '<S358>/Data Type Conversion7' incorporates:
   *  Selector: '<S358>/Selector6'
   */
  localDataTypeConversion7 = ((Float32)
    localTmpSignalConversionAtIn_pn[localTmpSignalConversionAtEn_n3 - 1]) * 8.0F;

  /* Selector: '<S358>/Selector3' */
  EngMGslT_B.Selector3 =
    localTmpSignalConversionAtInj_j[localTmpSignalConversionAtEn_gz - 1];

  /* Selector: '<S358>/Selector4' */
  EngMGslT_B.Selector4_m =
    localTmpSignalConversionAtInj_c[localTmpSignalConversionAtEn_gz - 1];

  /* Selector: '<S358>/Selector5' */
  EngMGslT_B.Selector5_f =
    localTmpSignalConversionAtIn_la[localTmpSignalConversionAtEn_gz - 1];

  /* Selector: '<S358>/Selector8' */
  localSelector8 =
    EngMGslT_B.TmpSignalConversionAtInM_prm__c[localTmpSignalConversionAtEn_n3 -
    1];

  /* DataTypeConversion: '<S358>/Data Type Conversion15' */
  localDataTypeConversion15 = ((Float32)
    EngMGslT_B.TmpSignalConversionAtUsThrM_p_e) * 8.0F;

  /* DataTypeConversion: '<S358>/Data Type Conversion16' */
  localtmp_0 = (UInt32)((SInt32)(((UInt32)
    (EngMGslT_B.TmpSignalConversionAtFARSp_rM_o * 17857)) >> 14));
  if (localtmp_0 > 65535U) {
    localDataTypeConversion16 = MAX_uint16_T;
  } else {
    localDataTypeConversion16 = (UInt16)localtmp_0;
  }

  /* DataTypeConversion: '<S358>/Data Type Conversion17' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtAirEfc_facChrExpFilPred_irv1Outport2'
   */
  localDataTypeConversion17 = ((Float32)
    Rte_IrvRead_RE_EngMGslT_020_TEV_AirEfc_facChrExpFilPred_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S358>/Data Type Conversion18' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtAirEfc_facChrExpScvFilPred_irv1Outport2'
   */
  localDataTypeConversion18 = ((Float32)
    Rte_IrvRead_RE_EngMGslT_020_TEV_AirEfc_facChrExpScvFilPred_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S358>/Data Type Conversion4' */
  localtmp_0 = (UInt32)(locallocalTmpSignalConversion_1 + 10);
  if (localtmp_0 > 65535U) {
    localDataTypeConversion4 = MAX_uint16_T;
  } else {
    localDataTypeConversion4 = (UInt16)localtmp_0;
  }

  /* DataTypeConversion: '<S358>/Data Type Conversion21' */
  localDataTypeConversion21 = ((Float32)localTmpSignalConversionAtEn_ng) *
    3.051757813E-005F;

  /* DataTypeConversion: '<S358>/Data Type Conversion22' */
  localDataTypeConversion22 = ((Float32)localTmpSignalConversionAtEn_hg) *
    3.051757813E-005F;

  /* SignalConversion: '<S358>/TmpSignal ConversionAtSignal Conversion15Inport1' */
  localTmpSignalConversionAtSi_jw = localTmpSignalConversionAtInThM;

  /* end of Outputs for SubSystem: '<S16>/F03_Input_Interface_IntkPredLoaEstimn' */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EngMGslT_B.TmpSignalConversionAtExt_tCoM_f);

  /* Outputs for atomic SubSystem: '<S16>/F02_libEngLdM' *
   * Block requirements for '<S16>/F02_libEngLdM':
   *  1. SubSystem "F02_libEngLdM" !Trace_To : VEMS_R_11_00998_018.02 ;
   */
  EngMGslT_F02_libEngLdM(localSignalConversion12, localDataTypeConversion8,
    localDataTypeConversion9, localDataTypeConversion10,
    localTmpSignalConversionAtSi_cr, localDataTypeConversion12, localSelector8,
    localDataTypeConversion13, localDataTypeConversion15,
    localDataTypeConversion16, localDataTypeConversion7,
    EngMGslT_B.TmpSignalConversionAtExt_tCoM_f, localDataTypeConversion17,
    localDataTypeConversion18, ((UInt8)2U), localDataTypeConversion2,
    localDataTypeConversion1, localDataTypeConversion3, localDataTypeConversion4,
    localDataTypeConversion21, localDataTypeConversion22,
    localTmpSignalConversionAtSi_jw, localDataTypeConversion20,
    &EngMGslT_B.F02_libEngLdM);

  /* end of Outputs for SubSystem: '<S16>/F02_libEngLdM' */

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEng_noExNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExNxtCyl'
   */
  Rte_Read_R_Eng_noExNxtCyl_Eng_noExNxtCyl(&localTmpSignalConversionAtEn_li);

  /* Outputs for atomic SubSystem: '<S16>/F01_Output_Interface_IntkPredLoaEstimn' *
   * Block requirements for '<S16>/F01_Output_Interface_IntkPredLoaEstimn':
   *  1. SubSystem "F01_Output_Interface" !Trace_To : VEMS_R_11_00998_047.01 ;
   */

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion4Inport1' */
  localTmpSignalConversionAtSig_j = EngMGslT_B.F02_libEngLdM.AirEfc_facChrExpFil;

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion1Inport1' */
  localTmpSignalConversionAtSig_n = EngMGslT_B.F02_libEngLdM.AirEfc_facOfsEfc;

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion2Inport1' */
  localTmpSignalConversionAtSig_o = EngMGslT_B.F02_libEngLdM.AirEfc_facSlopEfc;

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion7Inport1' */
  localTmpSignalConversionAtSig_f = EngMGslT_B.F02_libEngLdM.EngM_mTotEx;

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion6Inport1' */
  localTmpSignalConversionAtSig_c = EngMGslT_B.F02_libEngLdM.EngM_mfTotEx;

  /* SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion3Inport1' */
  localTmpSignalConversionAtSig_i = EngMGslT_B.F02_libEngLdM.EngM_rTotLdEx;

  /* DataTypeConversion: '<S373>/OutDTConv' incorporates:
   *  Constant: '<S373>/offset'
   *  Constant: '<S373>/one_on_slope'
   *  Product: '<S373>/Product4'
   *  Sum: '<S373>/Add1'
   */
  localtmp = 16384.0F * EngMGslT_B.F02_libEngLdM.EngM_rAirLd;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt16)localtmp;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* Assignment: '<S370>/Assignment3' incorporates:
   *  UnitDelay: '<S376>/Unit Delay'
   */
  for (locali = 0; locali < 6; locali++) {
    EngM_prm_rAirLdPredCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_c
      [(locali)];
  }

  EngM_prm_rAirLdPredCyl_MP[localTmpSignalConversionAtEn_n3 - 1] =
    locallocalTmpSignalConversionAt;

  /* Assignment: '<S370>/Assignment2' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment2[locali] = EngM_prm_rAirLdPredCyl_MP[(locali)];
    EngM_prm_mAirPredCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_o3
      [(locali)];
  }

  localAssignment2[localTmpSignalConversionAtEn_li - 1] =
    locallocalTmpSignalConversionAt;

  /* DataTypeConversion: '<S374>/OutDTConv' incorporates:
   *  Constant: '<S374>/offset'
   *  Constant: '<S374>/one_on_slope'
   *  Product: '<S374>/Product4'
   *  Sum: '<S374>/Add1'
   */
  localtmp = 8.389145E+006F * EngMGslT_B.F02_libEngLdM.EngM_mAir;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalTmpSignalConversion_0 = (UInt16)localtmp;
    } else {
      locallocalTmpSignalConversion_0 = 0U;
    }
  } else {
    locallocalTmpSignalConversion_0 = MAX_uint16_T;
  }

  /* Assignment: '<S371>/Assignment2' incorporates:
   *  UnitDelay: '<S377>/Unit Delay'
   */
  EngM_prm_mAirPredCyl_MP[localTmpSignalConversionAtEn_n3 - 1] =
    locallocalTmpSignalConversion_0;

  /* Assignment: '<S371>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment1[locali] = EngM_prm_mAirPredCyl_MP[(locali)];
    EngM_prm_mfAirPredCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_b
      [(locali)];
  }

  localAssignment1[localTmpSignalConversionAtEn_li - 1] =
    locallocalTmpSignalConversion_0;

  /* DataTypeConversion: '<S375>/OutDTConv' incorporates:
   *  Constant: '<S375>/offset'
   *  Constant: '<S375>/one_on_slope'
   *  Product: '<S375>/Product4'
   *  Sum: '<S375>/Add1'
   */
  localtmp = 65536.0F * EngMGslT_B.F02_libEngLdM.EngM_mfAir;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      locallocalTmpSignalConversion_1 = (UInt16)localtmp;
    } else {
      locallocalTmpSignalConversion_1 = 0U;
    }
  } else {
    locallocalTmpSignalConversion_1 = MAX_uint16_T;
  }

  /* Assignment: '<S372>/Assignment1' incorporates:
   *  UnitDelay: '<S378>/Unit Delay'
   */
  EngM_prm_mfAirPredCyl_MP[localTmpSignalConversionAtEn_n3 - 1] =
    locallocalTmpSignalConversion_1;

  /* Assignment: '<S372>/Assignment2' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment2_h[locali] = EngM_prm_mfAirPredCyl_MP[(locali)];

    /* Update for UnitDelay: '<S376>/Unit Delay' */
    EngMGslT_DWork.UnitDelay_DSTATE_c[(locali)] = localAssignment2[locali];

    /* Update for UnitDelay: '<S377>/Unit Delay' */
    EngMGslT_DWork.UnitDelay_DSTATE_o3[(locali)] = localAssignment1[locali];
  }

  localAssignment2_h[localTmpSignalConversionAtEn_li - 1] =
    locallocalTmpSignalConversion_1;

  /* Update for UnitDelay: '<S378>/Unit Delay' */
  for (locali = 0; locali < 6; locali++) {
    EngMGslT_DWork.UnitDelay_DSTATE_b[(locali)] = localAssignment2_h[locali];
  }

  /* end of Outputs for SubSystem: '<S16>/F01_Output_Interface_IntkPredLoaEstimn' */

  /* DataTypeConversion: '<S359>/OutDTConv' incorporates:
   *  Constant: '<S359>/offset'
   *  Constant: '<S359>/one_on_slope'
   *  Product: '<S359>/Product4'
   *  SignalConversion: '<S356>/TmpSignal ConversionAtSignal Conversion5Inport1'
   *  Sum: '<S359>/Add1'
   */
  localtmp = 65536.0F * EngMGslT_B.F02_libEngLdM.AirEfc_facChrExpScvFil;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_o = (UInt16)localtmp;
    } else {
      localOutDTConv_o = 0U;
    }
  } else {
    localOutDTConv_o = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S325>/autosar_testpoint1' */

  /* S-Function Block: <S325>/autosar_testpoint1 */
  AirEfc_facChrExpScvFilPred = localOutDTConv_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S326>/autosar_testpoint1' */

  /* S-Function Block: <S326>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_001_IRV_MP = localAssignment1[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S327>/autosar_testpoint1' */

  /* S-Function Block: <S327>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_002_IRV_MP = localAssignment1[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S328>/autosar_testpoint1' */

  /* S-Function Block: <S328>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_003_IRV_MP = localAssignment1[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S329>/autosar_testpoint1' */

  /* S-Function Block: <S329>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_004_IRV_MP = localAssignment1[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S331>/autosar_testpoint1' */

  /* S-Function Block: <S331>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_005_IRV_MP = localAssignment1[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S332>/autosar_testpoint1' */

  /* S-Function Block: <S332>/autosar_testpoint1 */
  EngM_prm_mAirPredCyl_006_IRV_MP = localAssignment1[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S333>/autosar_testpoint1' */

  /* S-Function Block: <S333>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_001_IRV_MP = localAssignment2_h[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S334>/autosar_testpoint1' */

  /* S-Function Block: <S334>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_002_IRV_MP = localAssignment2_h[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S335>/autosar_testpoint1' */

  /* S-Function Block: <S335>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_003_IRV_MP = localAssignment2_h[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S337>/autosar_testpoint1' */

  /* S-Function Block: <S337>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_004_IRV_MP = localAssignment2_h[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S338>/autosar_testpoint1' */

  /* S-Function Block: <S338>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_005_IRV_MP = localAssignment2_h[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S339>/autosar_testpoint1' */

  /* S-Function Block: <S339>/autosar_testpoint1 */
  EngM_prm_mfAirPredCyl_006_IRV_MP = localAssignment2_h[5];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S340>/autosar_testpoint1' */

  /* S-Function Block: <S340>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_001 = localAssignment2[0];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S341>/autosar_testpoint1' */

  /* S-Function Block: <S341>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_002 = localAssignment2[1];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S343>/autosar_testpoint1' */

  /* S-Function Block: <S343>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_003 = localAssignment2[2];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S344>/autosar_testpoint1' */

  /* S-Function Block: <S344>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_004 = localAssignment2[3];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S345>/autosar_testpoint1' */

  /* S-Function Block: <S345>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_005 = localAssignment2[4];

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S346>/autosar_testpoint1' */

  /* S-Function Block: <S346>/autosar_testpoint1 */
  EngM_prm_rAirLdPredCyl_006 = localAssignment2[5];

  /* DataTypeConversion: '<S361>/OutDTConv' incorporates:
   *  Constant: '<S361>/offset'
   *  Constant: '<S361>/one_on_slope'
   *  Product: '<S361>/Product4'
   *  Sum: '<S361>/Add1'
   */
  localtmp = 65536.0F * localTmpSignalConversionAtSig_j;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_n = (UInt16)localtmp;
    } else {
      localOutDTConv_n = 0U;
    }
  } else {
    localOutDTConv_n = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S351>/autosar_testpoint1' */

  /* S-Function Block: <S351>/autosar_testpoint1 */
  AirEfc_facChrExpFilPred_IRV_MP = localOutDTConv_n;

  /* Switch: '<S323>/Switch' incorporates:
   *  Constant: '<S323>/Byp_Fonction_SC'
   *  Constant: '<S323>/Int_BypC'
   *  Constant: '<S356>/Cste_1'
   *  Constant: '<S363>/offset'
   *  Constant: '<S363>/one_on_slope'
   *  DataTypeConversion: '<S363>/OutDTConv'
   *  Product: '<S363>/Product4'
   *  Sum: '<S363>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_n3 = EngM_facAPred_B;
  } else {
    localTmpSignalConversionAtEn_n3 = 128U;
  }

  /* Switch: '<S324>/Switch' incorporates:
   *  Constant: '<S324>/Byp_Fonction_SC'
   *  Constant: '<S324>/Int_BypC'
   *  Constant: '<S364>/offset'
   *  Constant: '<S364>/one_on_slope'
   *  DataTypeConversion: '<S364>/OutDTConv'
   *  Product: '<S364>/Product4'
   *  Sum: '<S364>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_hg = EngM_facOfsEfcPred_B;
  } else {
    localtmp = 16384.0F * localTmpSignalConversionAtSig_n;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtEn_hg = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtEn_hg = 0U;
      }
    } else {
      localTmpSignalConversionAtEn_hg = MAX_uint16_T;
    }
  }

  /* Switch: '<S330>/Switch' incorporates:
   *  Constant: '<S330>/Byp_Fonction_SC'
   *  Constant: '<S330>/Int_BypC'
   *  Constant: '<S366>/offset'
   *  Constant: '<S366>/one_on_slope'
   *  DataTypeConversion: '<S366>/OutDTConv'
   *  Product: '<S366>/Product4'
   *  Sum: '<S366>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtInThM = EngM_facSlopEfcPred_B;
  } else {
    localtmp = 2.978909184E+009F * localTmpSignalConversionAtSig_o;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtInThM = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtInThM = 0U;
      }
    } else {
      localTmpSignalConversionAtInThM = MAX_uint16_T;
    }
  }

  /* Switch: '<S336>/Switch' incorporates:
   *  Constant: '<S336>/Byp_Fonction_SC'
   *  Constant: '<S336>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversion_0 = EngM_mAirPred_B;
  }

  /* Switch: '<S342>/Switch' incorporates:
   *  Constant: '<S342>/Byp_Fonction_SC'
   *  Constant: '<S342>/Int_BypC'
   *  Constant: '<S360>/offset'
   *  Constant: '<S360>/one_on_slope'
   *  DataTypeConversion: '<S360>/OutDTConv'
   *  Product: '<S360>/Product4'
   *  Sum: '<S360>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mTotExPred_p = EngM_mTotExPred_B;
  } else {
    localtmp = 8.389145E+006F * localTmpSignalConversionAtSig_f;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localEngM_mTotExPred_p = (UInt16)localtmp;
      } else {
        localEngM_mTotExPred_p = 0U;
      }
    } else {
      localEngM_mTotExPred_p = MAX_uint16_T;
    }
  }

  /* Switch: '<S347>/Switch' incorporates:
   *  Constant: '<S347>/Byp_Fonction_SC'
   *  Constant: '<S347>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversion_1 = EngM_mfAirPred_B;
  }

  /* Switch: '<S348>/Switch' incorporates:
   *  Constant: '<S348>/Byp_Fonction_SC'
   *  Constant: '<S348>/Int_BypC'
   *  Constant: '<S362>/offset'
   *  Constant: '<S362>/one_on_slope'
   *  DataTypeConversion: '<S362>/OutDTConv'
   *  Product: '<S362>/Product4'
   *  Sum: '<S362>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mfTotExPred_c = EngM_mfTotExPred_B;
  } else {
    localtmp = 65536.0F * localTmpSignalConversionAtSig_c;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localEngM_mfTotExPred_c = (UInt16)localtmp;
      } else {
        localEngM_mfTotExPred_c = 0U;
      }
    } else {
      localEngM_mfTotExPred_c = MAX_uint16_T;
    }
  }

  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S349>/Byp_Fonction_SC'
   *  Constant: '<S349>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = EngM_rAirLdPred_B;
  }

  /* Switch: '<S350>/Switch' incorporates:
   *  Constant: '<S350>/Byp_Fonction_SC'
   *  Constant: '<S350>/Int_BypC'
   *  Constant: '<S365>/offset'
   *  Constant: '<S365>/one_on_slope'
   *  DataTypeConversion: '<S365>/OutDTConv'
   *  Product: '<S365>/Product4'
   *  Sum: '<S365>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rTotLdExPred_i = EngM_rTotLdExPred_B;
  } else {
    localtmp = 16384.0F * localTmpSignalConversionAtSig_i;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localEngM_rTotLdExPred_i = (UInt16)localtmp;
      } else {
        localEngM_rTotLdExPred_i = 0U;
      }
    } else {
      localEngM_rTotLdExPred_i = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S16>/SignalConversion1' */
  localAirEfc_facChrExpScvFilPr_c = localOutDTConv_o;

  /* SignalConversion: '<S16>/SignalConversion10' */
  localEngM_prm_mfAirPredCyl_00_h = localAssignment2_h[2];

  /* SignalConversion: '<S16>/SignalConversion11' */
  localEngM_prm_mfAirPredCyl_00_m = localAssignment2_h[3];

  /* SignalConversion: '<S16>/SignalConversion12' */
  localEngM_prm_mfAirPredCyl_00_n = localAssignment2_h[4];

  /* SignalConversion: '<S16>/SignalConversion13' */
  localEngM_prm_mfAirPredCyl_00_d = localAssignment2_h[5];

  /* SignalConversion: '<S16>/SignalConversion15' */
  localEngM_prm_mAirPredCyl_004_j = localAssignment1[3];

  /* SignalConversion: '<S16>/SignalConversion16' */
  localEngM_prm_mAirPredCyl_005_o = localAssignment1[4];

  /* SignalConversion: '<S16>/SignalConversion17' */
  localEngM_prm_mAirPredCyl_006_l = localAssignment1[5];

  /* SignalConversion: '<S16>/SignalConversion23' */
  localEngM_prm_mfAirPredCyl_00_a = localAssignment2_h[0];

  /* SignalConversion: '<S16>/SignalConversion31' */
  localEngM_prm_mAirPredCyl_001_g = localAssignment1[0];

  /* SignalConversion: '<S16>/SignalConversion32' */
  localEngM_prm_mAirPredCyl_002_k = localAssignment1[1];

  /* SignalConversion: '<S16>/SignalConversion33' */
  localEngM_prm_mAirPredCyl_003_l = localAssignment1[2];

  /* SignalConversion: '<S16>/SignalConversion40' */
  localEngM_prm_rAirLdPredCyl_0_p = localAssignment2[0];

  /* SignalConversion: '<S16>/SignalConversion41' */
  localEngM_prm_rAirLdPredCyl_0_b = localAssignment2[1];

  /* SignalConversion: '<S16>/SignalConversion42' */
  localEngM_prm_rAirLdPredCyl_0_e = localAssignment2[2];

  /* SignalConversion: '<S16>/SignalConversion43' */
  localEngM_prm_rAirLdPredCyl_0_m = localAssignment2[3];

  /* SignalConversion: '<S16>/SignalConversion44' */
  localEngM_prm_rAirLdPredCyl_0_c = localAssignment2[4];

  /* SignalConversion: '<S16>/SignalConversion45' */
  localEngM_prm_rAirLdPredCyl_0_n = localAssignment2[5];

  /* SignalConversion: '<S16>/SignalConversion8' */
  localEngM_prm_mfAirPredCyl_0_au = localAssignment2_h[1];

  /* SignalConversion: '<S16>/TmpSignal ConversionAtAirEfc_facChrExpFilPred_irvInport2' incorporates:
   *  SignalConversion: '<S16>/SignalConversion21'
   */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_AirEfc_facChrExpFilPred_irv(localOutDTConv_n);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtAirEfc_facChrExpScvFilPred_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_AirEfc_facChrExpScvFilPred_irv
    (localAirEfc_facChrExpScvFilPr_c);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_facAPredInport2' */
  Rte_Write_P_EngM_facAPred_EngM_facAPred(localTmpSignalConversionAtEn_n3);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_facOfsEfcPredInport2' */
  Rte_Write_P_EngM_facOfsEfcPred_EngM_facOfsEfcPred
    (localTmpSignalConversionAtEn_hg);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_facSlopEfcPredInport2' */
  Rte_Write_P_EngM_facSlopEfcPred_EngM_facSlopEfcPred
    (localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_mAirPredInport2' */
  Rte_Write_P_EngM_mAirPred_EngM_mAirPred(locallocalTmpSignalConversion_0);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_mTotExPredInport2' */
  Rte_Write_P_EngM_mTotExPred_EngM_mTotExPred(localEngM_mTotExPred_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_mfAirPredInport2' */
  Rte_Write_P_EngM_mfAirPred_EngM_mfAirPred(locallocalTmpSignalConversion_1);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_mfTotExPredInport2' */
  Rte_Write_P_EngM_mfTotExPred_EngM_mfTotExPred(localEngM_mfTotExPred_c);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_001_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_001_irv
    (localEngM_prm_mAirPredCyl_001_g);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_002_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_002_irv
    (localEngM_prm_mAirPredCyl_002_k);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_003_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_003_irv
    (localEngM_prm_mAirPredCyl_003_l);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_004_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_004_irv
    (localEngM_prm_mAirPredCyl_004_j);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_005_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_005_irv
    (localEngM_prm_mAirPredCyl_005_o);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mAirPredCyl_006_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mAirPredCyl_006_irv
    (localEngM_prm_mAirPredCyl_006_l);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_001_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_001_irv
    (localEngM_prm_mfAirPredCyl_00_a);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_002_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_002_irv
    (localEngM_prm_mfAirPredCyl_0_au);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_003_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_003_irv
    (localEngM_prm_mfAirPredCyl_00_h);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_004_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_004_irv
    (localEngM_prm_mfAirPredCyl_00_m);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_005_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_005_irv
    (localEngM_prm_mfAirPredCyl_00_n);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_mfAirPredCyl_006_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_mfAirPredCyl_006_irv
    (localEngM_prm_mfAirPredCyl_00_d);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_001_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_001_irv
    (localEngM_prm_rAirLdPredCyl_0_p);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_002_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_002_irv
    (localEngM_prm_rAirLdPredCyl_0_b);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_003_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_003_irv
    (localEngM_prm_rAirLdPredCyl_0_e);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_004_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_004_irv
    (localEngM_prm_rAirLdPredCyl_0_m);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_005_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_005_irv
    (localEngM_prm_rAirLdPredCyl_0_c);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_prm_rAirLdPredCyl_006_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_020_TEV_EngM_prm_rAirLdPredCyl_006_irv
    (localEngM_prm_rAirLdPredCyl_0_n);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_rAirLdPredInport2' */
  Rte_Write_P_EngM_rAirLdPred_EngM_rAirLdPred(locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S16>/TmpSignal ConversionAtEngM_rTotLdExPredInport2' */
  Rte_Write_P_EngM_rTotLdExPred_EngM_rTotLdExPred(localEngM_rTotLdExPred_i);
}

/*
 * Output and update for atomic system:
 *    '<S17>/VlvBasChgT'
 *    '<S18>/VlvBasChgT'
 */
void EngMGslT_VlvBasChgT(Float32 rtu_EngM_agCkOpInVlvRef0, Float32
  rtu_EngM_agCkClsExVlvRef0, SInt16 rtu_Ext_tCoStrtMes, Float32
  rtu_AFA_agCkOpInVlvOfs, Float32 rtu_AFA_agCkClsExVlvOfs, UInt32
  rtu_EOM_tiEngRun, Float32 rtu_EngM_dstInVlvClrCor, Float32
  rtu_EngM_dstExVlvClrCor, UInt8 rtu_EngM_noAcvVlvMPVal,
  rtB_VlvBasChgT_EngMGslT *localB)
{
  /* local block i/o variables */
  Float32 localEngM_agCkClsExVlvOfsRef0;
  Float32 localEngM_agCkOpInVlvOfsRef0;

  /* S-Function (sfun_autosar_clientop): '<S395>/Invoke AUTOSAR Server Operation' */
  Rte_Call_R_LibVlvBasChg_OP_LibVlvBasChg(rtu_EngM_agCkOpInVlvRef0,
    rtu_EngM_agCkClsExVlvRef0, rtu_Ext_tCoStrtMes, rtu_AFA_agCkOpInVlvOfs,
    rtu_AFA_agCkClsExVlvOfs, rtu_EOM_tiEngRun, rtu_EngM_dstInVlvClrCor,
    rtu_EngM_dstExVlvClrCor, rtu_EngM_noAcvVlvMPVal,
    &localB->EngM_agCkOpInVlvRef1, &localB->EngM_agCkClsInVlvRef1,
    &localB->EngM_agCkClsInVlvRef0, &localB->EngM_agCkClsExVlvRef1,
    &localB->EngM_agCkOpExVlvRef1, &localB->EngM_agCkOpExVlvRef0,
    &localEngM_agCkClsExVlvOfsRef0, &localEngM_agCkOpInVlvOfsRef0);

  /* SignalConversion Block: '<S388>/Signal Conversion8'
   *
   * Regarding '<S388>/Signal Conversion8':
   *   Unused code path elimination
   */

  /* SignalConversion Block: '<S388>/Signal Conversion9'
   *
   * Regarding '<S388>/Signal Conversion9':
   *   Unused code path elimination
   */
}

/* Start for exported function: RE_EngMGslT_012_TEV */
void RE_EngMGslT_012_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_VlvBasChgEstim'
   *
   * Block requirements for '<S1>/F01_VlvBasChgEstim':
   *  1. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_001.01 ;
   *  2. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_002.01 ;
   *  3. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_008.01 ;
   *  4. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_111.01 ;
   *  5. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_113.01 ;
   *  6. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_114.01 ;
   *  7. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_117.02 ;
   *  8. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_119.01 ;
   *  9. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_120.02 ;
   *  10. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_122.01 ;
   *  11. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_123.01 ;
   *  12. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_127.01 ;
   *  13. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_128.01 ;
   *  14. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_129.01 ;
   *  15. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_272.02 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_012_TEV */
void RE_EngMGslT_012_TEV(void)
{
  /* local block i/o variables */
  Float32 localSignalConversion1_i;
  Float32 localSignalConversion2_l;
  Float32 localSignalConversion4_g;
  Float32 localSignalConversion3_b;
  Float32 localSignalConversion6_c;
  Float32 localSignalConversion5_d;
  SInt8 localTmpSignalConversionAtAFA_a;
  SInt8 localTmpSignalConversionAtAFA_j;
  UInt16 localTmpSignalConversionAtEn_hx;
  UInt16 localTmpSignalConversionAtEn_pm;
  UInt16 localEngM_agCkOpExVlvEstimRef_c;
  UInt16 localEngM_agCkOpExVlvEstimRef_d;
  SInt16 localTmpSignalConversionAtExt_a;
  SInt16 localTmpSignalConversionAtExt_b;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_VlvBasChgEstim'
   *
   * Block requirements for '<S1>/F01_VlvBasChgEstim':
   *  1. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_001.01 ;
   *  2. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_002.01 ;
   *  3. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_008.01 ;
   *  4. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_111.01 ;
   *  5. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_113.01 ;
   *  6. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_114.01 ;
   *  7. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_117.02 ;
   *  8. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_119.01 ;
   *  9. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_120.02 ;
   *  10. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_122.01 ;
   *  11. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_123.01 ;
   *  12. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_127.01 ;
   *  13. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_128.01 ;
   *  14. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_129.01 ;
   *  15. SubSystem "F01_VlvBasChgEstim" !Trace_To : VEMS_R_11_00998_272.02 ;
   */

  /* SignalConversion: '<S17>/TmpSignal ConversionAtExt_agCkOpInVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkOpInVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0
    (&localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtExt_agCkClsExVlvEstimRef0Outport2' incorporates:
   *  Inport: '<Root>/Ext_agCkClsExVlvEstimRef0'
   */
  Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0
    (&localTmpSignalConversionAtExt_b);

  /* DataTypeConversion: '<S17>/SignalConversion1' incorporates:
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSignal ConversionInport1'
   */
  localSignalConversion1_i = ((Float32)localTmpSignalConversionAtExt_a) *
    0.09375F;

  /* DataTypeConversion: '<S17>/SignalConversion2' incorporates:
   *  SignalConversion: '<S387>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  localSignalConversion2_l = ((Float32)localTmpSignalConversionAtExt_b) *
    0.09375F;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtExt_tCoStrtMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoStrtMes'
   */
  Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes
    (&EngMGslT_B.TmpSignalConversionAtExt_tCoStr);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtAFA_agCkOpInVlvOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkOpInVlvOfs'
   */
  Rte_Read_R_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs
    (&localTmpSignalConversionAtAFA_a);

  /* DataTypeConversion: '<S17>/SignalConversion4' */
  localSignalConversion4_g = ((Float32)localTmpSignalConversionAtAFA_a) *
    0.09375F;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtAFA_agCkClsExVlvOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkClsExVlvOfs'
   */
  Rte_Read_R_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs
    (&localTmpSignalConversionAtAFA_j);

  /* DataTypeConversion: '<S17>/SignalConversion3' */
  localSignalConversion3_b = ((Float32)localTmpSignalConversionAtAFA_j) *
    0.09375F;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEOM_tiEngRunOutport2' incorporates:
   *  Inport: '<Root>/EOM_tiEngRun'
   */
  Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun
    (&EngMGslT_B.TmpSignalConversionAtEOM_tiEngR);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_dstInVlvClrCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_dstInVlvClrCor'
   */
  Rte_Read_R_EngM_dstInVlvClrCor_EngM_dstInVlvClrCor
    (&localTmpSignalConversionAtEn_hx);

  /* DataTypeConversion: '<S17>/SignalConversion6' */
  localSignalConversion6_c = ((Float32)localTmpSignalConversionAtEn_hx) *
    1.525878872E-007F;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_dstExVlvClrCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_dstExVlvClrCor'
   */
  Rte_Read_R_EngM_dstExVlvClrCor_EngM_dstExVlvClrCor
    (&localTmpSignalConversionAtEn_pm);

  /* DataTypeConversion: '<S17>/SignalConversion5' */
  localSignalConversion5_d = ((Float32)localTmpSignalConversionAtEn_pm) *
    1.525878872E-007F;

  /* Outputs for atomic SubSystem: '<S17>/VlvBasChgT' *
   * Block requirements for '<S17>/VlvBasChgT':
   *  1. SubSystem "VlvBasChgT" !Trace_To : VEMS_R_11_00998_259.01 ;
   */
  EngMGslT_VlvBasChgT(localSignalConversion1_i, localSignalConversion2_l,
                      EngMGslT_B.TmpSignalConversionAtExt_tCoStr,
                      localSignalConversion4_g, localSignalConversion3_b,
                      EngMGslT_B.TmpSignalConversionAtEOM_tiEngR,
                      localSignalConversion6_c, localSignalConversion5_d,
                      ((UInt8)2U), &EngMGslT_B.VlvBasChgT);

  /* end of Outputs for SubSystem: '<S17>/VlvBasChgT' */

  /* Switch: '<S381>/Switch' incorporates:
   *  Constant: '<S381>/Byp_Fonction_SC'
   *  Constant: '<S381>/Int_BypC'
   *  Constant: '<S392>/offset'
   *  Constant: '<S392>/one_on_slope'
   *  DataTypeConversion: '<S392>/OutDTConv'
   *  Product: '<S392>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal Conversion3Inport1'
   *  Sum: '<S392>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_a = EngM_agCkClsExVlvEstimRef1_B;
  } else {
    localtmp = 1.066666698E+001F * EngMGslT_B.VlvBasChgT.EngM_agCkClsExVlvRef1;
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        localTmpSignalConversionAtExt_a = (SInt16)localtmp;
      } else {
        localTmpSignalConversionAtExt_a = MIN_int16_T;
      }
    } else {
      localTmpSignalConversionAtExt_a = MAX_int16_T;
    }
  }

  /* Switch: '<S382>/Switch' incorporates:
   *  Constant: '<S382>/Byp_Fonction_SC'
   *  Constant: '<S382>/Int_BypC'
   *  Constant: '<S391>/offset'
   *  Constant: '<S391>/one_on_slope'
   *  DataTypeConversion: '<S391>/OutDTConv'
   *  Product: '<S391>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal Conversion2Inport1'
   *  Sum: '<S391>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_hx = EngM_agCkClsInVlvEstimRef0_B;
  } else {
    localtmp = (EngMGslT_B.VlvBasChgT.EngM_agCkClsInVlvRef0 - 84.0F) *
      1.066666698E+001F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtEn_hx = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtEn_hx = 0U;
      }
    } else {
      localTmpSignalConversionAtEn_hx = MAX_uint16_T;
    }
  }

  /* Switch: '<S383>/Switch' incorporates:
   *  Constant: '<S383>/Byp_Fonction_SC'
   *  Constant: '<S383>/Int_BypC'
   *  Constant: '<S390>/offset'
   *  Constant: '<S390>/one_on_slope'
   *  DataTypeConversion: '<S390>/OutDTConv'
   *  Product: '<S390>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  Sum: '<S390>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_pm = EngM_agCkClsInVlvEstimRef1_B;
  } else {
    localtmp = (EngMGslT_B.VlvBasChgT.EngM_agCkClsInVlvRef1 - 84.0F) *
      1.066666698E+001F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localTmpSignalConversionAtEn_pm = (UInt16)localtmp;
      } else {
        localTmpSignalConversionAtEn_pm = 0U;
      }
    } else {
      localTmpSignalConversionAtEn_pm = MAX_uint16_T;
    }
  }

  /* Switch: '<S384>/Switch' incorporates:
   *  Constant: '<S384>/Byp_Fonction_SC'
   *  Constant: '<S384>/Int_BypC'
   *  Constant: '<S394>/offset'
   *  Constant: '<S394>/one_on_slope'
   *  DataTypeConversion: '<S394>/OutDTConv'
   *  Product: '<S394>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal Conversion5Inport1'
   *  Sum: '<S394>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkOpExVlvEstimRef_c = EngM_agCkOpExVlvEstimRef0_B;
  } else {
    localtmp = (EngMGslT_B.VlvBasChgT.EngM_agCkOpExVlvRef0 - -276.0F) *
      1.066666698E+001F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localEngM_agCkOpExVlvEstimRef_c = (UInt16)localtmp;
      } else {
        localEngM_agCkOpExVlvEstimRef_c = 0U;
      }
    } else {
      localEngM_agCkOpExVlvEstimRef_c = MAX_uint16_T;
    }
  }

  /* Switch: '<S385>/Switch' incorporates:
   *  Constant: '<S385>/Byp_Fonction_SC'
   *  Constant: '<S385>/Int_BypC'
   *  Constant: '<S393>/offset'
   *  Constant: '<S393>/one_on_slope'
   *  DataTypeConversion: '<S393>/OutDTConv'
   *  Product: '<S393>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal Conversion4Inport1'
   *  Sum: '<S393>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkOpExVlvEstimRef_d = EngM_agCkOpExVlvEstimRef1_B;
  } else {
    localtmp = (EngMGslT_B.VlvBasChgT.EngM_agCkOpExVlvRef1 - -276.0F) *
      1.066666698E+001F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        localEngM_agCkOpExVlvEstimRef_d = (UInt16)localtmp;
      } else {
        localEngM_agCkOpExVlvEstimRef_d = 0U;
      }
    } else {
      localEngM_agCkOpExVlvEstimRef_d = MAX_uint16_T;
    }
  }

  /* Switch: '<S386>/Switch' incorporates:
   *  Constant: '<S386>/Byp_Fonction_SC'
   *  Constant: '<S386>/Int_BypC'
   *  Constant: '<S389>/offset'
   *  Constant: '<S389>/one_on_slope'
   *  DataTypeConversion: '<S389>/OutDTConv'
   *  Product: '<S389>/Product4'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtSignal ConversionInport1'
   *  Sum: '<S389>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtExt_b = EngM_agCkOpInVlvEstimRef1_B;
  } else {
    localtmp = 1.066666698E+001F * EngMGslT_B.VlvBasChgT.EngM_agCkOpInVlvRef1;
    if (localtmp < 32768.0F) {
      if (localtmp >= -32768.0F) {
        localTmpSignalConversionAtExt_b = (SInt16)localtmp;
      } else {
        localTmpSignalConversionAtExt_b = MIN_int16_T;
      }
    } else {
      localTmpSignalConversionAtExt_b = MAX_int16_T;
    }
  }

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (localTmpSignalConversionAtExt_a);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef0Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvEstimRef0_EngM_agCkClsInVlvEstimRef0
    (localTmpSignalConversionAtEn_hx);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (localTmpSignalConversionAtEn_pm);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkOpExVlvEstimRef0Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvEstimRef0_EngM_agCkOpExVlvEstimRef0
    (localEngM_agCkOpExVlvEstimRef_c);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkOpExVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvEstimRef1_EngM_agCkOpExVlvEstimRef1
    (localEngM_agCkOpExVlvEstimRef_d);

  /* SignalConversion: '<S17>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Inport2' */
  Rte_Write_P_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (localTmpSignalConversionAtExt_b);
}

/* Start for exported function: RE_EngMGslT_008_TEV */
void RE_EngMGslT_008_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_VlvBasChgReq'
   *
   * Block requirements for '<S1>/F01_VlvBasChgReq':
   *  1. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_001.01 ;
   *  2. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_002.01 ;
   *  3. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_003.01 ;
   *  4. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_112.01 ;
   *  5. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_115.01 ;
   *  6. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_116.01 ;
   *  7. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_118.02 ;
   *  8. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_121.02 ;
   *  9. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_122.01 ;
   *  10. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_123.01 ;
   *  11. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_124.01 ;
   *  12. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_125.01 ;
   *  13. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_126.01 ;
   *  14. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_130.02 ;
   *  15. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_131.02 ;
   *  16. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_129.01 ;
   *  17. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_226.02 ;
   *  18. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_271.02 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_008_TEV */
void RE_EngMGslT_008_TEV(void)
{
  /* local block i/o variables */
  Float32 localSignalConversion1_j;
  Float32 localSignalConversion3_k;
  Float32 localSignalConversion4_i;
  Float32 localSignalConversion5_m;
  Float32 localSignalConversion6_j;
  Float32 localSignalConversion7_h;
  UInt32 localTmpSignalConversionAtEOM_t;
  SInt16 localTmpSignalConversionAtExt_t;
  UInt8 localOutDTConv_l;
  Float32 localTmpSignalConversionAtSig_m;
  Float32 localTmpSignalConversionAtSig_a;
  Float32 localTmpSignalConversionAtSi_i3;
  Float32 localTmpSignalConversionAtSi_jz;
  Float32 localTmpSignalConversionAtSi_bj;
  SInt8 localTmpSignalConversionAtAF_ja;
  SInt8 localTmpSignalConversionAtAFA_k;
  UInt16 localTmpSignalConversionAtEn_fy;
  UInt16 localTmpSignalConversionAtEn_lv;
  UInt8 localEngM_agCkClsInVlvReqRef1_h;
  SInt16 localEngM_agCkClsExVlvReqRef1_g;
  UInt8 localEngM_agCkOpExVlvReqRef1_f;
  SInt16 localEngM_agCkOpInVlvReqRef1_f;
  UInt8 localTmpSignalConversionAtVlvSy;
  UInt8 localTmpSignalConversionAtVlv_c;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_VlvBasChgReq'
   *
   * Block requirements for '<S1>/F01_VlvBasChgReq':
   *  1. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_001.01 ;
   *  2. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_002.01 ;
   *  3. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_003.01 ;
   *  4. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_112.01 ;
   *  5. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_115.01 ;
   *  6. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_116.01 ;
   *  7. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_118.02 ;
   *  8. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_121.02 ;
   *  9. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_122.01 ;
   *  10. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_123.01 ;
   *  11. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_124.01 ;
   *  12. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_125.01 ;
   *  13. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_126.01 ;
   *  14. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_130.02 ;
   *  15. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_131.02 ;
   *  16. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_129.01 ;
   *  17. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_226.02 ;
   *  18. SubSystem "F01_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_271.02 ;
   */

  /* SignalConversion: '<S18>/TmpSignal ConversionAtVlvSys_agCkOpInVlvReqRef0Outport2' incorporates:
   *  Inport: '<Root>/VlvSys_agCkOpInVlvReqRef0'
   */
  Rte_Read_R_VlvSys_agCkOpInVlvReqRef0_VlvSys_agCkOpInVlvReqRef0
    (&localTmpSignalConversionAtVlvSy);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtVlvSys_agCkClsExVlvReqRef0Outport2' incorporates:
   *  Inport: '<Root>/VlvSys_agCkClsExVlvReqRef0'
   */
  Rte_Read_R_VlvSys_agCkClsExVlvReqRef0_VlvSys_agCkClsExVlvReqRef0
    (&localTmpSignalConversionAtVlv_c);

  /* DataTypeConversion: '<S18>/SignalConversion1' incorporates:
   *  Inport: '<S402>/VlvSys_agCkOpInVlvReqRef0'
   */
  localSignalConversion1_j = (((Float32)localTmpSignalConversionAtVlvSy) *
    0.75F) - 96.0F;

  /* DataTypeConversion: '<S18>/SignalConversion3' incorporates:
   *  Inport: '<S402>/VlvSys_agCkClsExVlvReqRef0'
   */
  localSignalConversion3_k = (((Float32)localTmpSignalConversionAtVlv_c) *
    0.75F) - 96.0F;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtExt_tCoStrtMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoStrtMes'
   */
  Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtAFA_agCkOpInVlvOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkOpInVlvOfs'
   */
  Rte_Read_R_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs
    (&localTmpSignalConversionAtAF_ja);

  /* DataTypeConversion: '<S18>/SignalConversion4' */
  localSignalConversion4_i = ((Float32)localTmpSignalConversionAtAF_ja) *
    0.09375F;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtAFA_agCkClsExVlvOfsOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkClsExVlvOfs'
   */
  Rte_Read_R_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs
    (&localTmpSignalConversionAtAFA_k);

  /* DataTypeConversion: '<S18>/SignalConversion5' */
  localSignalConversion5_m = ((Float32)localTmpSignalConversionAtAFA_k) *
    0.09375F;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEOM_tiEngRunOutport2' incorporates:
   *  Inport: '<Root>/EOM_tiEngRun'
   */
  Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&localTmpSignalConversionAtEOM_t);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_dstInVlvClrCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_dstInVlvClrCor'
   */
  Rte_Read_R_EngM_dstInVlvClrCor_EngM_dstInVlvClrCor
    (&localTmpSignalConversionAtEn_fy);

  /* DataTypeConversion: '<S18>/SignalConversion6' */
  localSignalConversion6_j = ((Float32)localTmpSignalConversionAtEn_fy) *
    1.525878872E-007F;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_dstExVlvClrCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_dstExVlvClrCor'
   */
  Rte_Read_R_EngM_dstExVlvClrCor_EngM_dstExVlvClrCor
    (&localTmpSignalConversionAtEn_lv);

  /* DataTypeConversion: '<S18>/SignalConversion7' */
  localSignalConversion7_h = ((Float32)localTmpSignalConversionAtEn_lv) *
    1.525878872E-007F;

  /* Outputs for atomic SubSystem: '<S18>/VlvBasChgT' *
   * Block requirements for '<S18>/VlvBasChgT':
   *  1. SubSystem "VlvBasChgT" !Trace_To : VEMS_R_11_00998_259.01 ;
   */
  EngMGslT_VlvBasChgT(localSignalConversion1_j, localSignalConversion3_k,
                      localTmpSignalConversionAtExt_t, localSignalConversion4_i,
                      localSignalConversion5_m, localTmpSignalConversionAtEOM_t,
                      localSignalConversion6_j, localSignalConversion7_h,
                      ((UInt8)1U), &EngMGslT_B.VlvBasChgT_i);

  /* end of Outputs for SubSystem: '<S18>/VlvBasChgT' */

  /* Outputs for atomic SubSystem: '<S18>/F03_Layer_Out' *
   * Block requirements for '<S18>/F03_Layer_Out':
   *  1. SubSystem "F03_Layer_Out" !Trace_To : VEMS_R_11_00998_005.01 ;
   */

  /* Outputs for atomic SubSystem: '<S403>/F02_Layer_VlvBasChgReq' *
   * Block requirements for '<S403>/F02_Layer_VlvBasChgReq':
   *  1. SubSystem "F02_Layer_VlvBasChgReq" !Trace_To : VEMS_R_11_00998_007.01 ;
   */

  /* SignalConversion: '<S411>/TmpSignal ConversionAtSignal ConversionInport1' */
  localTmpSignalConversionAtSi_bj = EngMGslT_B.VlvBasChgT_i.EngM_agCkOpInVlvRef1;

  /* SignalConversion: '<S411>/TmpSignal ConversionAtSignal Conversion2Inport1' */
  localTmpSignalConversionAtSig_a =
    EngMGslT_B.VlvBasChgT_i.EngM_agCkClsInVlvRef0;

  /* SignalConversion: '<S411>/TmpSignal ConversionAtSignal Conversion3Inport1' */
  localTmpSignalConversionAtSig_m =
    EngMGslT_B.VlvBasChgT_i.EngM_agCkClsExVlvRef1;

  /* SignalConversion: '<S411>/TmpSignal ConversionAtSignal Conversion4Inport1' */
  localTmpSignalConversionAtSi_jz = EngMGslT_B.VlvBasChgT_i.EngM_agCkOpExVlvRef1;

  /* SignalConversion: '<S411>/TmpSignal ConversionAtSignal Conversion5Inport1' */
  localTmpSignalConversionAtSi_i3 = EngMGslT_B.VlvBasChgT_i.EngM_agCkOpExVlvRef0;

  /* end of Outputs for SubSystem: '<S403>/F02_Layer_VlvBasChgReq' */

  /* end of Outputs for SubSystem: '<S18>/F03_Layer_Out' */

  /* DataTypeConversion: '<S409>/OutDTConv' incorporates:
   *  Constant: '<S409>/offset'
   *  Constant: '<S409>/one_on_slope'
   *  Product: '<S409>/Product4'
   *  SignalConversion: '<S411>/TmpSignal ConversionAtSignal Conversion1Inport1'
   *  Sum: '<S409>/Add1'
   */
  localtmp = (EngMGslT_B.VlvBasChgT_i.EngM_agCkClsInVlvRef1 - 84.0F) *
    1.333333373E+000F;
  if (localtmp < 256.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_l = (UInt8)localtmp;
    } else {
      localOutDTConv_l = 0U;
    }
  } else {
    localOutDTConv_l = MAX_uint8_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S401>/autosar_testpoint1' */

  /* S-Function Block: <S401>/autosar_testpoint1 */
  EngM_agCkClsInVlvReqRef1_IRV_MP = localOutDTConv_l;

  /* Switch: '<S396>/Switch' incorporates:
   *  Constant: '<S396>/Byp_Fonction_SC'
   *  Constant: '<S396>/Int_BypC'
   *  Constant: '<S405>/offset'
   *  Constant: '<S405>/one_on_slope'
   *  DataTypeConversion: '<S405>/OutDTConv'
   *  Product: '<S405>/Product4'
   *  Sum: '<S405>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkClsExVlvReqRef1_g = EngM_agCkClsExVlvReqRef1_B;
  } else {
    localTmpSignalConversionAtSig_m *= 1.066666698E+001F;
    if (localTmpSignalConversionAtSig_m < 32768.0F) {
      if (localTmpSignalConversionAtSig_m >= -32768.0F) {
        localEngM_agCkClsExVlvReqRef1_g = (SInt16)
          localTmpSignalConversionAtSig_m;
      } else {
        localEngM_agCkClsExVlvReqRef1_g = MIN_int16_T;
      }
    } else {
      localEngM_agCkClsExVlvReqRef1_g = MAX_int16_T;
    }
  }

  /* Switch: '<S397>/Switch' incorporates:
   *  Constant: '<S397>/Byp_Fonction_SC'
   *  Constant: '<S397>/Int_BypC'
   *  Constant: '<S406>/offset'
   *  Constant: '<S406>/one_on_slope'
   *  DataTypeConversion: '<S406>/OutDTConv'
   *  Product: '<S406>/Product4'
   *  Sum: '<S406>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtVlvSy = EngM_agCkClsInVlvReqRef0_B;
  } else {
    localTmpSignalConversionAtSig_m = (localTmpSignalConversionAtSig_a - 84.0F) *
      1.333333373E+000F;
    if (localTmpSignalConversionAtSig_m < 256.0F) {
      if (localTmpSignalConversionAtSig_m >= 0.0F) {
        localTmpSignalConversionAtVlvSy = (UInt8)
          localTmpSignalConversionAtSig_m;
      } else {
        localTmpSignalConversionAtVlvSy = 0U;
      }
    } else {
      localTmpSignalConversionAtVlvSy = MAX_uint8_T;
    }
  }

  /* Switch: '<S398>/Switch' incorporates:
   *  Constant: '<S398>/Byp_Fonction_SC'
   *  Constant: '<S398>/Int_BypC'
   *  Constant: '<S408>/offset'
   *  Constant: '<S408>/one_on_slope'
   *  DataTypeConversion: '<S408>/OutDTConv'
   *  Product: '<S408>/Product4'
   *  Sum: '<S408>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtVlv_c = EngM_agCkOpExVlvReqRef0_B;
  } else {
    localTmpSignalConversionAtSig_m = (localTmpSignalConversionAtSi_i3 - -276.0F)
      * 1.333333373E+000F;
    if (localTmpSignalConversionAtSig_m < 256.0F) {
      if (localTmpSignalConversionAtSig_m >= 0.0F) {
        localTmpSignalConversionAtVlv_c = (UInt8)
          localTmpSignalConversionAtSig_m;
      } else {
        localTmpSignalConversionAtVlv_c = 0U;
      }
    } else {
      localTmpSignalConversionAtVlv_c = MAX_uint8_T;
    }
  }

  /* Switch: '<S399>/Switch' incorporates:
   *  Constant: '<S399>/Byp_Fonction_SC'
   *  Constant: '<S399>/Int_BypC'
   *  Constant: '<S407>/offset'
   *  Constant: '<S407>/one_on_slope'
   *  DataTypeConversion: '<S407>/OutDTConv'
   *  Product: '<S407>/Product4'
   *  Sum: '<S407>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkOpExVlvReqRef1_f = EngM_agCkOpExVlvReqRef1_B;
  } else {
    localTmpSignalConversionAtSig_m = (localTmpSignalConversionAtSi_jz - -276.0F)
      * 1.333333373E+000F;
    if (localTmpSignalConversionAtSig_m < 256.0F) {
      if (localTmpSignalConversionAtSig_m >= 0.0F) {
        localEngM_agCkOpExVlvReqRef1_f = (UInt8)
          localTmpSignalConversionAtSig_m;
      } else {
        localEngM_agCkOpExVlvReqRef1_f = 0U;
      }
    } else {
      localEngM_agCkOpExVlvReqRef1_f = MAX_uint8_T;
    }
  }

  /* Switch: '<S400>/Switch' incorporates:
   *  Constant: '<S400>/Byp_Fonction_SC'
   *  Constant: '<S400>/Int_BypC'
   *  Constant: '<S404>/offset'
   *  Constant: '<S404>/one_on_slope'
   *  DataTypeConversion: '<S404>/OutDTConv'
   *  Product: '<S404>/Product4'
   *  Sum: '<S404>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_agCkOpInVlvReqRef1_f = EngM_agCkOpInVlvReqRef1_B;
  } else {
    localTmpSignalConversionAtSig_m = 1.066666698E+001F *
      localTmpSignalConversionAtSi_bj;
    if (localTmpSignalConversionAtSig_m < 32768.0F) {
      if (localTmpSignalConversionAtSig_m >= -32768.0F) {
        localEngM_agCkOpInVlvReqRef1_f = (SInt16)
          localTmpSignalConversionAtSig_m;
      } else {
        localEngM_agCkOpInVlvReqRef1_f = MIN_int16_T;
      }
    } else {
      localEngM_agCkOpInVlvReqRef1_f = MAX_int16_T;
    }
  }

  /* SignalConversion: '<S18>/Signal Conversion28' */
  localEngM_agCkClsInVlvReqRef1_h = localOutDTConv_l;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkClsExVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkClsExVlvReqRef1_EngM_agCkClsExVlvReqRef1
    (localEngM_agCkClsExVlvReqRef1_g);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkClsInVlvReqRef0Inport2' */
  Rte_Write_P_EngM_agCkClsInVlvReqRef0_EngM_agCkClsInVlvReqRef0
    (localTmpSignalConversionAtVlvSy);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkClsInVlvReqRef1_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_008_TEV_EngM_agCkClsInVlvReqRef1_irv
    (localEngM_agCkClsInVlvReqRef1_h);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkOpExVlvReqRef0Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvReqRef0_EngM_agCkOpExVlvReqRef0
    (localTmpSignalConversionAtVlv_c);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkOpExVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkOpExVlvReqRef1_EngM_agCkOpExVlvReqRef1
    (localEngM_agCkOpExVlvReqRef1_f);

  /* SignalConversion: '<S18>/TmpSignal ConversionAtEngM_agCkOpInVlvReqRef1Inport2' */
  Rte_Write_P_EngM_agCkOpInVlvReqRef1_EngM_agCkOpInVlvReqRef1
    (localEngM_agCkOpInVlvReqRef1_f);
}

/* Start for exported function: RE_EngMGslT_018_TEV */
void RE_EngMGslT_018_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IntkLoaEstimn'
   *
   * Block requirements for '<S1>/F01_IntkLoaEstimn':
   *  1. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_013.02 ;
   *  2. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_014.02 ;
   *  3. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_015.01 ;
   *  4. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  5. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  6. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  7. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_163.01 ;
   *  8. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_164.01 ;
   *  9. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_165.01 ;
   *  10. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_166.01 ;
   *  11. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_167.01 ;
   *  12. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_168.01 ;
   *  13. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_169.01 ;
   *  14. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_170.01 ;
   *  15. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_171.01 ;
   *  16. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_172.01 ;
   *  17. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_173.02 ;
   *  18. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_174.01 ;
   *  19. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_175.01 ;
   *  20. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_176.01 ;
   *  21. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_177.01 ;
   *  22. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_178.01 ;
   *  23. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_179.01 ;
   *  24. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_180.01 ;
   *  25. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_181.01 ;
   *  26. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_182.01 ;
   *  27. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  28. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  29. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_133.02 ;
   *  30. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_134.01 ;
   *  31. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_135.01 ;
   *  32. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_136.02 ;
   *  33. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_137.01 ;
   *  34. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_138.01 ;
   *  35. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_139.01 ;
   *  36. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_140.01 ;
   *  37. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_141.01 ;
   *  38. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_142.01 ;
   *  39. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_143.01 ;
   *  40. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_144.02 ;
   *  41. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_145.02 ;
   *  42. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_146.01 ;
   *  43. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_147.01 ;
   *  44. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_148.01 ;
   *  45. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_149.02 ;
   *  46. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_150.02 ;
   *  47. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_151.02 ;
   *  48. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_153.01 ;
   *  49. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_154.01 ;
   *  50. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_155.01 ;
   *  51. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_227.03 ;
   *  52. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_248.02 ;
   *  53. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_249.02 ;
   *  54. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_278.01 ;
   *  55. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_280.01 ;
   *  56. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_279.01 ;
   *  57. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_290.01 ;
   *  58. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_273.03 ;
   *  59. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_016.01 ;
   *  60. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_019.02 ;
   *  61. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  62. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  63. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  64. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_162.04 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_018_TEV */
void RE_EngMGslT_018_TEV(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion5;
  Float32 localDataTypeConversion6;
  Float32 localDataTypeConversion4_p;
  Float32 localDataTypeConversion1_m;
  Float32 localDataTypeConversion17_g;
  Float32 localDataTypeConversion18_e;
  Float32 localDataTypeConversion19;
  Float32 localDataTypeConversion2_h;
  Float32 localDataTypeConversion3_k;
  Float32 localDataTypeConversion7_l;
  Float32 localDataTypeConversion12_i;
  Float32 localDataTypeConversion10_h;
  Float32 localDataTypeConversion14;
  Float32 localDataTypeConversion13_o;
  Float32 localDataTypeConversion16_k;
  UInt16 localSignalConversion12_f;
  UInt16 localSignalConversion15;
  UInt16 localOutDTConv_a;
  UInt16 localOutDTConv_io;
  UInt16 localTmpSignalConversionAtDataT;
  UInt16 localSignalConversion7_i;
  UInt16 localOutDTConv_mf;
  UInt16 localDataTypeConversion11;
  UInt16 localDataTypeConversion8_o;
  Float32 localAirEfc_facChrExpScvFil;
  Float32 localAirEfc_rDeltaLdInjPhaRef;
  Float32 localAirEfc_facMassAirScv;
  Float32 localAirEfc_rMassAirResi;
  Float32 localAirEfc_rMassAirScv;
  Float32 localAirEfc_tBurnCyl;
  Float32 localEngM_tMixtCyl;
  Float32 localAirEfc_facMassFlowLd;
  Float32 localAirEfc_facOfsEfc;
  Float32 localAirEfc_facSlopEfc;
  Float32 localEngM_mAir;
  Float32 localEngM_mBurn;
  UInt8 localMultiportSwitch_h;
  Float32 localSignalConversion6_n;
  Float32 localSignalConversion1_d;
  Float32 localSignalConversion2_f;
  UInt8 localTmpSignalConversionAtEn_h2;
  Boolean localRelationalOperator;
  Float32 localDivide_d0;
  UInt8 localTmpSignalConversionAtEn_pn;
  UInt16 localAirEfc_facChrExpScvFilCo_b;
  UInt16 localEngM_facECor_irv_k;
  UInt32 localEngM_facMassAirScvCor_o;
  UInt16 localEngM_facMassFlowLdCor_f;
  UInt16 localEngM_facOfsEfcCor_m;
  UInt16 localEngM_facSlopEfcCor_l;
  UInt16 localEngM_mAirCor_h;
  UInt16 localEngM_mBurnCor_n;
  UInt16 localEngM_rAirLdCor_l;
  SInt16 localEngM_rDeltaLdInjPha_l;
  UInt16 localEngM_rItBurnRateCor_i;
  UInt16 localEngM_rMassAirResiCor_b;
  UInt16 localEngM_rMassAirScvCor_c;
  UInt16 localEngM_rltMassAirScvCor_l;
  UInt16 localEngM_tBurnCylCor_b;
  UInt16 localEngM_tMixtCylCor_m;
  UInt16 localEngM_tMixtCylGDICor_a;
  UInt16 localAssignment1_e[6];
  UInt16 localAssignment1_f[6];
  UInt16 localAssignment1_c[6];
  UInt16 localAssignment2_n[6];
  UInt16 localTmpSignalConversionAtEn_mz[6];
  SInt32 locali;
  Float32 localtmp;
  UInt16 locallocalOutDTConv_mv;
  UInt16 locallocalOutDTConv_dy;
  UInt16 locallocalOutDTConv_or;
  UInt16 locallocalOutDTConv_b;
  UInt16 locallocalTmpSignalConversionAt;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IntkLoaEstimn'
   *
   * Block requirements for '<S1>/F01_IntkLoaEstimn':
   *  1. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_013.02 ;
   *  2. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_014.02 ;
   *  3. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_015.01 ;
   *  4. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  5. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  6. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  7. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_163.01 ;
   *  8. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_164.01 ;
   *  9. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_165.01 ;
   *  10. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_166.01 ;
   *  11. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_167.01 ;
   *  12. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_168.01 ;
   *  13. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_169.01 ;
   *  14. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_170.01 ;
   *  15. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_171.01 ;
   *  16. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_172.01 ;
   *  17. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_173.02 ;
   *  18. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_174.01 ;
   *  19. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_175.01 ;
   *  20. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_176.01 ;
   *  21. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_177.01 ;
   *  22. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_178.01 ;
   *  23. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_179.01 ;
   *  24. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_180.01 ;
   *  25. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_181.01 ;
   *  26. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_182.01 ;
   *  27. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  28. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_132.01 ;
   *  29. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_133.02 ;
   *  30. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_134.01 ;
   *  31. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_135.01 ;
   *  32. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_136.02 ;
   *  33. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_137.01 ;
   *  34. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_138.01 ;
   *  35. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_139.01 ;
   *  36. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_140.01 ;
   *  37. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_141.01 ;
   *  38. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_142.01 ;
   *  39. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_143.01 ;
   *  40. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_144.02 ;
   *  41. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_145.02 ;
   *  42. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_146.01 ;
   *  43. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_147.01 ;
   *  44. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_148.01 ;
   *  45. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_149.02 ;
   *  46. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_150.02 ;
   *  47. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_151.02 ;
   *  48. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_153.01 ;
   *  49. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_154.01 ;
   *  50. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_155.01 ;
   *  51. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_227.03 ;
   *  52. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_248.02 ;
   *  53. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_249.02 ;
   *  54. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_278.01 ;
   *  55. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_280.01 ;
   *  56. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_279.01 ;
   *  57. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_290.01 ;
   *  58. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_273.03 ;
   *  59. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_016.01 ;
   *  60. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_019.02 ;
   *  61. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  62. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  63. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  64. SubSystem "F01_IntkLoaEstimn" !Trace_To : VEMS_R_11_00998_162.04 ;
   */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslT_B.TmpSignalConversionAtExt_nEng_o);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&EngMGslT_B.TmpSignalConversionAtEngM_agCkC);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsInVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (&EngMGslT_B.TmpSignalConversionAtEngM_agC_h);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&EngMGslT_B.TmpSignalConversionAtEngM_agCkO);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&EngMGslT_B.TmpSignalConversionAtInThM_tA_e);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tExMnfEstimCyl'
   */
  Rte_Read_R_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl
    (&EngMGslT_B.TmpSignalConversionAtExM_prm__j);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pExMnfEstimOvlpCyl'
   */
  Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&EngMGslT_B.TmpSignalConversionAtExM_prm__m);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&EngMGslT_B.TmpSignalConversionAtUsThrM_p_n);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp
    (&EngMGslT_B.TmpSignalConversionAtFARSp_rM_i);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor
    (&EngMGslT_B.TmpSignalConversionAtInM_conc_o);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredOvlpCyl'
   */
  Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&EngMGslT_B.TmpSignalConversionAtInM_prm__p);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_agBegInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_a);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_agEndInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_d);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_mFuInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys__a3);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtFuSysM_tFuOutport2' incorporates:
   *  Inport: '<Root>/FuSysM_tFu'
   */
  Rte_Read_R_FuSysM_tFu_FuSysM_tFu(&EngMGslT_B.TmpSignalConversionAtFuSysM_t_l);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facCorOfsEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorOfsEfc'
   */
  Rte_Read_R_EngM_facCorOfsEfc_EngM_facCorOfsEfc
    (&EngMGslT_B.TmpSignalConversionAtEngM_fac_h);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facCorSlopEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorSlopEfc'
   */
  Rte_Read_R_EngM_facCorSlopEfc_EngM_facCorSlopEfc
    (&EngMGslT_B.TmpSignalConversionAtEngM_fac_n);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_agBegInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_k);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_agEndInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys__bg);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInjSys_prm_mFuInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_n);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl
    (&EngMGslT_B.TmpSignalConversionAtEng_noCm_j);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noCmbCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmbCyl'
   */
  Rte_Read_R_Eng_noCmbCyl_Eng_noCmbCyl
    (&EngMGslT_B.TmpSignalConversionAtEng_noCm_m);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&EngMGslT_B.TmpSignalConversionAtEng_noIn_j);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&EngMGslT_B.TmpSignalConversionAtEng_noEx_a);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor
    (&EngMGslT_B.TmpSignalConversionAtInThM_nE_o);

  /* Outputs for atomic SubSystem: '<S14>/F03_Input_Interface_IntkLoaEstimn'
   * Block description for '<S14>/F03_Input_Interface_IntkLoaEstimn':
   *  CSMT_CGMT09_0050_2.FR.5.2
   *
   * Block requirements for '<S14>/F03_Input_Interface_IntkLoaEstimn':
   *  1. SubSystem "F03_Input_Interface" !Trace_To : VEMS_R_11_00998_017.02 ;
   */

  /* SignalConversion: '<S184>/Signal Conversion12' */
  localSignalConversion12_f = EngMGslT_B.TmpSignalConversionAtExt_nEng_o;

  /* DataTypeConversion: '<S184>/Data Type Conversion5' */
  localDataTypeConversion5 = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_agCkC) * 0.09375F;

  /* DataTypeConversion: '<S184>/Data Type Conversion6' */
  localDataTypeConversion6 = (((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_agC_h) * 0.09375F) + 84.0F;

  /* DataTypeConversion: '<S184>/Data Type Conversion4' */
  localDataTypeConversion4_p = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_agCkO) * 0.09375F;

  /* SignalConversion: '<S184>/Signal Conversion7' */
  localSignalConversion7_i = EngMGslT_B.TmpSignalConversionAtInThM_tA_e;

  /* MultiPortSwitch: '<S184>/Multiport Switch' incorporates:
   *  Constant: '<S184>/EngM_noPhaInjLoaEstimn_C'
   */
  switch (EngM_noPhaInjLoaEstimn_C + 1) {
   case 1:
    localMultiportSwitch_h = EngMGslT_B.TmpSignalConversionAtEng_noIn_j;
    break;

   case 2:
    localMultiportSwitch_h = EngMGslT_B.TmpSignalConversionAtEng_noCm_j;
    break;

   case 3:
    localMultiportSwitch_h = EngMGslT_B.TmpSignalConversionAtEng_noCm_m;
    break;

   default:
    localMultiportSwitch_h = EngMGslT_B.TmpSignalConversionAtEng_noEx_a;
    break;
  }

  /* DataTypeConversion: '<S184>/Data Type Conversion1' incorporates:
   *  Selector: '<S184>/Selector8'
   */
  localDataTypeConversion1_m = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys_p_d[localMultiportSwitch_h - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S184>/Data Type Conversion17' incorporates:
   *  Selector: '<S184>/Selector2'
   */
  localDataTypeConversion17_g = ((Float32)
    EngMGslT_B.TmpSignalConversionAtExM_prm__m[EngMGslT_B.TmpSignalConversionAtEng_noIn_j
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S184>/Data Type Conversion18' incorporates:
   *  Selector: '<S184>/Selector1'
   */
  localDataTypeConversion18_e = (((Float32)
    EngMGslT_B.TmpSignalConversionAtExM_prm__j[EngMGslT_B.TmpSignalConversionAtEng_noIn_j
    - 1]) * 0.03125F) + 223.0F;

  /* DataTypeConversion: '<S184>/Data Type Conversion19' incorporates:
   *  Selector: '<S184>/Selector5'
   */
  localDataTypeConversion19 = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInM_prm__p[EngMGslT_B.TmpSignalConversionAtEng_noIn_j
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S184>/Data Type Conversion2' incorporates:
   *  Selector: '<S184>/Selector9'
   */
  localDataTypeConversion2_h = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys_p_a[localMultiportSwitch_h - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S184>/Data Type Conversion3' incorporates:
   *  Selector: '<S184>/Selector7'
   */
  localDataTypeConversion3_k = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys__a3[localMultiportSwitch_h - 1]) *
    7.450580597E-009F;

  /* Selector: '<S184>/Selector3' */
  EngMGslT_B.Selector3_p =
    EngMGslT_B.TmpSignalConversionAtInjSys_p_n[localMultiportSwitch_h - 1];

  /* Selector: '<S184>/Selector4' */
  EngMGslT_B.Selector4 =
    EngMGslT_B.TmpSignalConversionAtInjSys__bg[localMultiportSwitch_h - 1];

  /* Selector: '<S184>/Selector6' */
  EngMGslT_B.Selector6 =
    EngMGslT_B.TmpSignalConversionAtInjSys_p_k[localMultiportSwitch_h - 1];

  /* SignalConversion: '<S184>/TmpSignal ConversionAtData Type Conversion9Inport1' */
  localTmpSignalConversionAtDataT = locallocalTmpSignalConversionAt;

  /* DataTypeConversion: '<S184>/Data Type Conversion7' */
  localDataTypeConversion7_l = ((Float32)
    EngMGslT_B.TmpSignalConversionAtUsThrM_p_n) * 8.0F;

  /* DataTypeConversion: '<S184>/Data Type Conversion11' */
  localEngM_facMassAirScvCor_o = (UInt32)((SInt32)(((UInt32)
    (EngMGslT_B.TmpSignalConversionAtFARSp_rM_i * 17857)) >> 14));
  if (localEngM_facMassAirScvCor_o > 65535U) {
    localDataTypeConversion11 = MAX_uint16_T;
  } else {
    localDataTypeConversion11 = (UInt16)localEngM_facMassAirScvCor_o;
  }

  /* DataTypeConversion: '<S184>/Data Type Conversion12' */
  localDataTypeConversion12_i = (((Float32)
    EngMGslT_B.TmpSignalConversionAtInM_conc_o) * 1.525878906E-005F) +
    1.525878906E-005F;

  /* DataTypeConversion: '<S184>/Data Type Conversion10' incorporates:
   *  SignalConversion: '<S14>/TmpSignal ConversionAtAirEfc_facChrExpFilCor_irv1Outport2'
   */
  localDataTypeConversion10_h = ((Float32)
    Rte_IrvRead_RE_EngMGslT_018_TEV_AirEfc_facChrExpFilCor_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S184>/Data Type Conversion14' incorporates:
   *  SignalConversion: '<S14>/TmpSignal ConversionAtAirEfc_facChrExpScvFilCor_irv1Outport2'
   */
  localDataTypeConversion14 = ((Float32)
    Rte_IrvRead_RE_EngMGslT_018_TEV_AirEfc_facChrExpScvFilCor_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S184>/Data Type Conversion8' */
  localEngM_facMassAirScvCor_o = (UInt32)
    (EngMGslT_B.TmpSignalConversionAtFuSysM_t_l + 10);
  if (localEngM_facMassAirScvCor_o > 65535U) {
    localDataTypeConversion8_o = MAX_uint16_T;
  } else {
    localDataTypeConversion8_o = (UInt16)localEngM_facMassAirScvCor_o;
  }

  /* DataTypeConversion: '<S184>/Data Type Conversion13' */
  localDataTypeConversion13_o = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_fac_h) * 3.051757813E-005F;

  /* DataTypeConversion: '<S184>/Data Type Conversion16' */
  localDataTypeConversion16_k = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_fac_n) * 3.051757813E-005F;

  /* SignalConversion: '<S184>/Signal Conversion15' */
  localSignalConversion15 = EngMGslT_B.TmpSignalConversionAtInThM_nE_o;

  /* end of Outputs for SubSystem: '<S14>/F03_Input_Interface_IntkLoaEstimn' */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EngMGslT_B.TmpSignalConversionAtExt_tCoM_h);

  /* Outputs for atomic SubSystem: '<S14>/F02_libEngLdM' *
   * Block requirements for '<S14>/F02_libEngLdM':
   *  1. SubSystem "F02_libEngLdM" !Trace_To : VEMS_R_11_00998_018.02 ;
   */
  EngMGslT_F02_libEngLdM(localSignalConversion12_f, localDataTypeConversion5,
    localDataTypeConversion6, localDataTypeConversion4_p,
    localSignalConversion7_i, localDataTypeConversion18_e,
    localTmpSignalConversionAtDataT, localDataTypeConversion17_g,
    localDataTypeConversion7_l, localDataTypeConversion11,
    localDataTypeConversion19, EngMGslT_B.TmpSignalConversionAtExt_tCoM_h,
    localDataTypeConversion10_h, localDataTypeConversion14, ((UInt8)1U),
    localDataTypeConversion2_h, localDataTypeConversion1_m,
    localDataTypeConversion3_k, localDataTypeConversion8_o,
    localDataTypeConversion13_o, localDataTypeConversion16_k,
    localSignalConversion15, localDataTypeConversion12_i,
    &EngMGslT_B.F02_libEngLdM_o);

  /* end of Outputs for SubSystem: '<S14>/F02_libEngLdM' */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noInNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInNxtCyl'
   */
  Rte_Read_R_Eng_noInNxtCyl_Eng_noInNxtCyl(&localTmpSignalConversionAtEn_h2);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEng_noInNxtNxtCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInNxtNxtCyl'
   */
  Rte_Read_R_Eng_noInNxtNxtCyl_Eng_noInNxtNxtCyl
    (&localTmpSignalConversionAtEn_pn);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_mfTotExCorCyl_INPUTOutport2' incorporates:
   *  Inport: '<Root>/EngM_prm_mfTotExCorCyl_INPUT'
   */
  Rte_Read_R_EngM_prm_mfTotExCorCyl_EngM_prm_mfTotExCorCyl
    (&localTmpSignalConversionAtEn_mz);

  /* Outputs for atomic SubSystem: '<S14>/F03_Output_Interface_IntkLoaEstimn'
   * Block description for '<S14>/F03_Output_Interface_IntkLoaEstimn':
   *  CSMT_CGMT09_0050_2.FR.10.2
   *
   * Block requirements for '<S14>/F03_Output_Interface_IntkLoaEstimn':
   *  1. SubSystem "F03_Output_Interface_calculation1" !Trace_To : VEMS_R_11_00998_022.01 ;
   */

  /* Inport: '<S185>/AirEfc_rMassAirScv' */
  localAirEfc_rMassAirScv = EngMGslT_B.F02_libEngLdM_o.AirEfc_rMassAirScv;

  /* Inport: '<S185>/AirEfc_facMassFlowLd' */
  localAirEfc_facMassFlowLd = EngMGslT_B.F02_libEngLdM_o.AirEfc_facMassFlowLd;

  /* Outputs for atomic SubSystem: '<S185>/F01_Ecriture_en_vecteur_cylindre' *
   * Block requirements for '<S185>/F01_Ecriture_en_vecteur_cylindre':
   *  1. SubSystem "F01_Ecriture_en_vecteur_cylindre" !Trace_To : VEMS_R_11_00998_048.02 ;
   *  2. SubSystem "F01_Ecriture_en_vecteur_cylindre" !Trace_To : VEMS_R_11_00998_023.01 ;
   */

  /* DataTypeConversion: '<S209>/SignalConversion6' */
  localSignalConversion6_n = (Float32)
    EngMGslT_B.TmpSignalConversionAtExt_nEng_o;

  /* DataTypeConversion: '<S209>/SignalConversion1' incorporates:
   *  Constant: '<S209>/EngM_tiSampleFast_SC'
   */
  localSignalConversion1_d = (((Float32)EngM_tiSampleFast_SC) *
    5.000000237E-004F) + 5.000000237E-004F;

  /* Outputs for atomic SubSystem: '<S209>/F01_Activation_ecriture_InCyl'
   * Block description for '<S209>/F01_Activation_ecriture_InCyl':
   *  CSMT_CGMT09_0050_2.FR.12.1
   *
   * Block requirements for '<S209>/F01_Activation_ecriture_InCyl':
   *  1. SubSystem "F01_Activation_ecriture_InCyl" !Trace_To : VEMS_R_11_00998_024.02 ;
   */

  /* RelationalOperator: '<S218>/Relational Operator' */
  localRelationalOperator = (EngMGslT_B.TmpSignalConversionAtEng_noEx_a !=
    EngMGslT_B.TmpSignalConversionAtEng_noIn_j);

  /* end of Outputs for SubSystem: '<S209>/F01_Activation_ecriture_InCyl' */

  /* DataTypeConversion: '<S224>/OutDTConv' incorporates:
   *  Constant: '<S224>/offset'
   *  Constant: '<S224>/one_on_slope'
   *  Product: '<S224>/Product4'
   *  Sum: '<S224>/Add1'
   */
  localAirEfc_facChrExpScvFil = 65536.0F *
    EngMGslT_B.F02_libEngLdM_o.EngM_mfTotEx;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      locallocalTmpSignalConversionAt = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      locallocalTmpSignalConversionAt = 0U;
    }
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S209>/F02_Ecriture_InCyl' *
   * Block requirements for '<S209>/F02_Ecriture_InCyl':
   *  1. SubSystem "F02_Ecriture_InCyl" !Trace_To : VEMS_R_11_00998_025.01 ;
   */

  /* Outputs for enable SubSystem: '<S219>/F01_Ecriture_InCyl' incorporates:
   *  Constant: '<S218>/Cste_60_6'
   *  EnablePort: '<S226>/EngM_MAJ'
   *  EnablePort: '<S227>/EngM_NotMAJ'
   *  Logic: '<S218>/Logical Operator'
   *  Logic: '<S219>/Logical Operator'
   *  Product: '<S225>/Divide'
   *  RelationalOperator: '<S218>/Relational Operator2'
   *  SubSystem: '<S219>/F02_Pas_d_ecriture_InCyl'
   *
   * Block requirements for '<S219>/F01_Ecriture_InCyl':
   *  1. SubSystem "F01_Ecriture_InCyl" !Trace_To : VEMS_R_11_00998_026.01 ;
   *
   * Block requirements for '<S219>/F02_Pas_d_ecriture_InCyl':
   *  1. SubSystem "F02_Pas_d_ecriture_InCyl" !Trace_To : VEMS_R_11_00998_027.01 ;
   */
  if ((localRelationalOperator) || ((10.0F / localSignalConversion1_d) <
       localSignalConversion6_n)) {
    /* Assignment: '<S226>/Assignment3' */
    localTmpSignalConversionAtEn_mz[EngMGslT_B.TmpSignalConversionAtEng_noIn_j -
      1] = locallocalTmpSignalConversionAt;
  }

  /* end of Outputs for SubSystem: '<S219>/F01_Ecriture_InCyl' */

  /* end of Outputs for SubSystem: '<S209>/F02_Ecriture_InCyl' */

  /* DataTypeConversion: '<S209>/SignalConversion2' incorporates:
   *  Constant: '<S209>/EngM_tiSampleFast_SC1'
   */
  localSignalConversion2_f = (Float32)Ext_noCylEng_SC;

  /* Outputs for atomic SubSystem: '<S209>/F03_Activation_ecriture_InNxtCyl'
   * Block description for '<S209>/F03_Activation_ecriture_InNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.16.1
   *
   * Block requirements for '<S209>/F03_Activation_ecriture_InNxtCyl':
   *  1. SubSystem "F03_Activation_ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_028.02 ;
   */

  /* Product: '<S229>/Divide' incorporates:
   *  Constant: '<S220>/Cste_720_6'
   *  Product: '<S228>/Divide'
   */
  localDivide_d0 = (120.0F / localSignalConversion2_f) /
    localSignalConversion1_d;

  /* end of Outputs for SubSystem: '<S209>/F03_Activation_ecriture_InNxtCyl' */

  /* Outputs for atomic SubSystem: '<S209>/F04_Ecriture_InNxtCyl'
   * Block description for '<S209>/F04_Ecriture_InNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.17.1
   *
   * Block requirements for '<S209>/F04_Ecriture_InNxtCyl':
   *  1. SubSystem "F04_Ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_029.02 ;
   */

  /* Outputs for enable SubSystem: '<S221>/F01_Ecriture_InNxtCyl' incorporates:
   *  Constant: '<S220>/Cste_2'
   *  EnablePort: '<S231>/EngM_MAJ'
   *  EnablePort: '<S232>/EngM_NotMAJ'
   *  Logic: '<S220>/Logical Operator'
   *  Logic: '<S220>/Logical Operator1'
   *  Logic: '<S221>/Logical Operator'
   *  Product: '<S230>/Divide'
   *  RelationalOperator: '<S220>/Relational Operator1'
   *  RelationalOperator: '<S220>/Relational Operator2'
   *  SubSystem: '<S221>/F02_Pas_d_ecriture_InNxtCyl'
   *
   * Block description for '<S221>/F01_Ecriture_InNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.18.1
   *
   * Block description for '<S221>/F02_Pas_d_ecriture_InNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.19.1
   *
   * Block requirements for '<S221>/F01_Ecriture_InNxtCyl':
   *  1. SubSystem "F01_Ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_030.02 ;
   *
   * Block requirements for '<S221>/F02_Pas_d_ecriture_InNxtCyl':
   *  1. SubSystem "F02_Pas_d_ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_031.02 ;
   */
  if (((localRelationalOperator) && (localDivide_d0 < localSignalConversion6_n))
      || (localSignalConversion6_n > (localDivide_d0 * 2.0F))) {
    /* Assignment: '<S231>/Assignment3' */
    localTmpSignalConversionAtEn_mz[localTmpSignalConversionAtEn_h2 - 1] =
      locallocalTmpSignalConversionAt;
  }

  /* end of Outputs for SubSystem: '<S221>/F01_Ecriture_InNxtCyl' */

  /* end of Outputs for SubSystem: '<S209>/F04_Ecriture_InNxtCyl' */

  /* Outputs for atomic SubSystem: '<S209>/F06_Ecriture_InNxtNxtCyl'
   * Block description for '<S209>/F06_Ecriture_InNxtNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.21.1
   *
   * Block requirements for '<S209>/F06_Ecriture_InNxtNxtCyl':
   *  1. SubSystem "F06_Ecriture_InNxtNxtCyl" !Trace_To : VEMS_R_11_00998_033.02 ;
   */

  /* Outputs for enable SubSystem: '<S223>/F01_Ecriture_InNxtCyl' incorporates:
   *  Constant: '<S222>/Cste_2'
   *  Constant: '<S222>/Cste_720_6'
   *  EnablePort: '<S236>/EngM_MAJ'
   *  EnablePort: '<S237>/EngM_NotMAJ'
   *  Logic: '<S222>/Logical Operator1'
   *  Logic: '<S223>/Logical Operator'
   *  Product: '<S233>/Divide'
   *  Product: '<S234>/Divide'
   *  Product: '<S235>/Divide'
   *  RelationalOperator: '<S222>/Relational Operator1'
   *  SubSystem: '<S223>/F02_Pas_d_ecriture_InNxtCyl'
   *
   * Block description for '<S223>/F01_Ecriture_InNxtCyl':
   *  CSMT_CGMT09_0050_2.FR.22.1
   *
   * Block requirements for '<S223>/F01_Ecriture_InNxtCyl':
   *  1. SubSystem "F01_Ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_034.02 ;
   *
   * Block requirements for '<S223>/F02_Pas_d_ecriture_InNxtCyl':
   *  1. SubSystem "F02_Pas_d_ecriture_InNxtCyl" !Trace_To : VEMS_R_11_00998_035.01 ;
   */
  if ((localRelationalOperator) && (localSignalConversion6_n > (((120.0F /
          localSignalConversion2_f) / localSignalConversion1_d) * 2.0F))) {
    /* Assignment: '<S236>/Assignment3' */
    localTmpSignalConversionAtEn_mz[localTmpSignalConversionAtEn_pn - 1] =
      locallocalTmpSignalConversionAt;
  }

  /* end of Outputs for SubSystem: '<S223>/F01_Ecriture_InNxtCyl' */

  /* end of Outputs for SubSystem: '<S209>/F06_Ecriture_InNxtNxtCyl' */

  /* end of Outputs for SubSystem: '<S185>/F01_Ecriture_en_vecteur_cylindre' */

  /* DataTypeConversion: '<S214>/OutDTConv' incorporates:
   *  Constant: '<S214>/offset'
   *  Constant: '<S214>/one_on_slope'
   *  Product: '<S214>/Product4'
   *  Sum: '<S214>/Add1'
   */
  localAirEfc_facChrExpScvFil = 16384.0F *
    EngMGslT_B.F02_libEngLdM_o.EngM_rTotLdEx;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      locallocalOutDTConv_mv = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      locallocalOutDTConv_mv = 0U;
    }
  } else {
    locallocalOutDTConv_mv = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S185>/F02_Ecriture_en_vecteur_cylindre' *
   * Block requirements for '<S185>/F02_Ecriture_en_vecteur_cylindre':
   *  1. SubSystem "F02_Ecriture_en_vecteur_cylindre" !Trace_To : VEMS_R_11_00998_036.01 ;
   */

  /* UnitDelay: '<S238>/Unit Delay' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment2_n[locali] = EngMGslT_DWork.UnitDelay_DSTATE[(locali)];
  }

  /* Assignment: '<S210>/Assignment2' */
  localAssignment2_n[EngMGslT_B.TmpSignalConversionAtEng_noIn_j - 1] =
    locallocalOutDTConv_mv;

  /* DataStoreWrite: '<S210>/MemoryStore1' */
  for (locali = 0; locali < 6; locali++) {
    EngM_prm_rTotLdExCorCyl_MP[(locali)] = localAssignment2_n[locali];
  }

  /* Assignment: '<S210>/Assignment1' */
  localAssignment2_n[localTmpSignalConversionAtEn_h2 - 1] =
    locallocalOutDTConv_mv;

  /* end of Outputs for SubSystem: '<S185>/F02_Ecriture_en_vecteur_cylindre' */

  /* DataTypeConversion: '<S215>/OutDTConv' incorporates:
   *  Constant: '<S215>/offset'
   *  Constant: '<S215>/one_on_slope'
   *  Product: '<S215>/Product4'
   *  Sum: '<S215>/Add1'
   */
  localAirEfc_facChrExpScvFil = 8.389145E+006F *
    EngMGslT_B.F02_libEngLdM_o.EngM_mAirScv;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      locallocalOutDTConv_dy = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      locallocalOutDTConv_dy = 0U;
    }
  } else {
    locallocalOutDTConv_dy = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S185>/F03_Ecriture_en_vecteur_cylindre1' *
   * Block requirements for '<S185>/F03_Ecriture_en_vecteur_cylindre1':
   *  1. SubSystem "F03_Ecriture_en_vecteur_cylindre1" !Trace_To : VEMS_R_11_00998_037.01 ;
   */

  /* Assignment: '<S211>/Assignment2' incorporates:
   *  UnitDelay: '<S239>/Unit Delay'
   */
  for (locali = 0; locali < 6; locali++) {
    /* Update for UnitDelay: '<S238>/Unit Delay' */
    EngMGslT_DWork.UnitDelay_DSTATE[(locali)] = localAssignment2_n[locali];
    EngM_prm_mAirScvCorCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_l
      [(locali)];
  }

  EngM_prm_mAirScvCorCyl_MP[EngMGslT_B.TmpSignalConversionAtEng_noIn_j - 1] =
    locallocalOutDTConv_dy;

  /* Assignment: '<S211>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment1_e[locali] = EngM_prm_mAirScvCorCyl_MP[(locali)];
  }

  localAssignment1_e[localTmpSignalConversionAtEn_h2 - 1] =
    locallocalOutDTConv_dy;

  /* end of Outputs for SubSystem: '<S185>/F03_Ecriture_en_vecteur_cylindre1' */

  /* DataTypeConversion: '<S216>/OutDTConv' incorporates:
   *  Constant: '<S216>/offset'
   *  Constant: '<S216>/one_on_slope'
   *  Product: '<S216>/Product4'
   *  Sum: '<S216>/Add1'
   */
  localAirEfc_facChrExpScvFil = 65536.0F *
    EngMGslT_B.F02_libEngLdM_o.EngM_mfAirScv;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      locallocalOutDTConv_or = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      locallocalOutDTConv_or = 0U;
    }
  } else {
    locallocalOutDTConv_or = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S185>/F04_Ecriture_en_vecteur_cylindre2' *
   * Block requirements for '<S185>/F04_Ecriture_en_vecteur_cylindre2':
   *  1. SubSystem "F04_Ecriture_en_vecteur_cylindre2" !Trace_To : VEMS_R_11_00998_038.01 ;
   */

  /* Assignment: '<S212>/Assignment2' incorporates:
   *  UnitDelay: '<S240>/Unit Delay'
   */
  for (locali = 0; locali < 6; locali++) {
    /* Update for UnitDelay: '<S239>/Unit Delay' */
    EngMGslT_DWork.UnitDelay_DSTATE_l[(locali)] = localAssignment1_e[locali];
    EngM_prm_mfAirScvCorCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_m
      [(locali)];
  }

  EngM_prm_mfAirScvCorCyl_MP[EngMGslT_B.TmpSignalConversionAtEng_noIn_j - 1] =
    locallocalOutDTConv_or;

  /* Assignment: '<S212>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment1_c[locali] = EngM_prm_mfAirScvCorCyl_MP[(locali)];
  }

  localAssignment1_c[localTmpSignalConversionAtEn_h2 - 1] =
    locallocalOutDTConv_or;

  /* end of Outputs for SubSystem: '<S185>/F04_Ecriture_en_vecteur_cylindre2' */

  /* DataTypeConversion: '<S217>/OutDTConv' incorporates:
   *  Constant: '<S217>/offset'
   *  Constant: '<S217>/one_on_slope'
   *  Product: '<S217>/Product4'
   *  Sum: '<S217>/Add1'
   */
  localAirEfc_facChrExpScvFil = 65536.0F * EngMGslT_B.F02_libEngLdM_o.EngM_mfAir;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      locallocalOutDTConv_b = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      locallocalOutDTConv_b = 0U;
    }
  } else {
    locallocalOutDTConv_b = MAX_uint16_T;
  }

  /* Outputs for atomic SubSystem: '<S185>/F05_Ecriture_en_vecteur_cylindre3' *
   * Block requirements for '<S185>/F05_Ecriture_en_vecteur_cylindre3':
   *  1. SubSystem "F05_Ecriture_en_vecteur_cylindre3" !Trace_To : VEMS_R_11_00998_039.01 ;
   */

  /* Assignment: '<S213>/Assignment2' incorporates:
   *  UnitDelay: '<S241>/Unit Delay'
   */
  for (locali = 0; locali < 6; locali++) {
    /* Update for UnitDelay: '<S240>/Unit Delay' */
    EngMGslT_DWork.UnitDelay_DSTATE_m[(locali)] = localAssignment1_c[locali];
    EngM_prm_mfAirCorCyl_MP[(locali)] = EngMGslT_DWork.UnitDelay_DSTATE_o
      [(locali)];
  }

  EngM_prm_mfAirCorCyl_MP[EngMGslT_B.TmpSignalConversionAtEng_noIn_j - 1] =
    locallocalOutDTConv_b;

  /* Assignment: '<S213>/Assignment1' */
  for (locali = 0; locali < 6; locali++) {
    localAssignment1_f[locali] = EngM_prm_mfAirCorCyl_MP[(locali)];
  }

  localAssignment1_f[localTmpSignalConversionAtEn_h2 - 1] =
    locallocalOutDTConv_b;

  /* Update for UnitDelay: '<S241>/Unit Delay' */
  for (locali = 0; locali < 6; locali++) {
    EngMGslT_DWork.UnitDelay_DSTATE_o[(locali)] = localAssignment1_f[locali];
  }

  /* end of Outputs for SubSystem: '<S185>/F05_Ecriture_en_vecteur_cylindre3' */

  /* Inport: '<S185>/Eng_rltMassAirScv' */
  localSignalConversion6_n = EngMGslT_B.F02_libEngLdM_o.EngM_rltMassAirScv;

  /* Inport: '<S185>/Eng_tMixtCylGDI' */
  localSignalConversion1_d = EngMGslT_B.F02_libEngLdM_o.EngM_tMixtCylGDI;

  /* Inport: '<S185>/EngM_rAirLd' */
  localSignalConversion2_f = EngMGslT_B.F02_libEngLdM_o.EngM_rAirLd;

  /* Inport: '<S185>/EngM_rItBurnRate' */
  localDivide_d0 = EngMGslT_B.F02_libEngLdM_o.EngM_rItBurnRate;

  /* Inport: '<S185>/EngM_mBurn' */
  localEngM_mBurn = EngMGslT_B.F02_libEngLdM_o.EngM_mBurn;

  /* Inport: '<S185>/EngM_mAir' */
  localEngM_mAir = EngMGslT_B.F02_libEngLdM_o.EngM_mAir;

  /* Inport: '<S185>/EngM_tMixtCyl' */
  localEngM_tMixtCyl = EngMGslT_B.F02_libEngLdM_o.EngM_tMixtCyl;

  /* Inport: '<S185>/AirEfc_facMassAirScv' */
  localAirEfc_facMassAirScv = EngMGslT_B.F02_libEngLdM_o.AirEfc_facMassAirScv;

  /* Inport: '<S185>/AirEfc_tBurnCyl' */
  localAirEfc_tBurnCyl = EngMGslT_B.F02_libEngLdM_o.AirEfc_tBurnCyl;

  /* Inport: '<S185>/AirEfc_facChrExpScvFil' */
  localAirEfc_facChrExpScvFil =
    EngMGslT_B.F02_libEngLdM_o.AirEfc_facChrExpScvFil;

  /* Inport: '<S185>/AirEfc_rMassAirResi' */
  localAirEfc_rMassAirResi = EngMGslT_B.F02_libEngLdM_o.AirEfc_rMassAirResi;

  /* Inport: '<S185>/AirEfc_facOfsEfc' */
  localAirEfc_facOfsEfc = EngMGslT_B.F02_libEngLdM_o.AirEfc_facOfsEfc;

  /* Inport: '<S185>/AirEfc_facSlopEfc' */
  localAirEfc_facSlopEfc = EngMGslT_B.F02_libEngLdM_o.AirEfc_facSlopEfc;

  /* Inport: '<S185>/AirEfc_rDeltaLdInjPhaRef' */
  localAirEfc_rDeltaLdInjPhaRef =
    EngMGslT_B.F02_libEngLdM_o.AirEfc_rDeltaLdInjPhaRef;

  /* end of Outputs for SubSystem: '<S14>/F03_Output_Interface_IntkLoaEstimn' */

  /* DataTypeConversion: '<S189>/OutDTConv' incorporates:
   *  Constant: '<S189>/offset'
   *  Constant: '<S189>/one_on_slope'
   *  Inport: '<S185>/AirEfc_facChrExpFil'
   *  Product: '<S189>/Product4'
   *  Sum: '<S189>/Add1'
   */
  localtmp = 65536.0F * EngMGslT_B.F02_libEngLdM_o.AirEfc_facChrExpFil;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_a = (UInt16)localtmp;
    } else {
      localOutDTConv_a = 0U;
    }
  } else {
    localOutDTConv_a = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S169>/autosar_testpoint1' */

  /* S-Function Block: <S169>/autosar_testpoint1 */
  AirEfc_facChrExpFilCor_IRV_MP = localOutDTConv_a;

  /* DataTypeConversion: '<S190>/OutDTConv' incorporates:
   *  Constant: '<S190>/offset'
   *  Constant: '<S190>/one_on_slope'
   *  Product: '<S190>/Product4'
   *  Sum: '<S190>/Add1'
   */
  localAirEfc_facChrExpScvFil *= 65536.0F;
  if (localAirEfc_facChrExpScvFil < 65536.0F) {
    if (localAirEfc_facChrExpScvFil >= 0.0F) {
      localOutDTConv_io = (UInt16)localAirEfc_facChrExpScvFil;
    } else {
      localOutDTConv_io = 0U;
    }
  } else {
    localOutDTConv_io = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S170>/autosar_testpoint1' */

  /* S-Function Block: <S170>/autosar_testpoint1 */
  AirEfc_facChrExpScvFilCor_IRV_MP = localOutDTConv_io;

  /* DataTypeConversion: '<S191>/OutDTConv' incorporates:
   *  Constant: '<S185>/Cste_3'
   *  Constant: '<S191>/offset'
   *  Constant: '<S191>/one_on_slope'
   *  Product: '<S191>/Product4'
   *  Sum: '<S191>/Add1'
   */
  localOutDTConv_mf = 256U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S172>/autosar_testpoint1' */

  /* S-Function Block: <S172>/autosar_testpoint1 */
  EngM_facECor_IRV_MP = localOutDTConv_mf;

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S149>/Byp_Fonction_SC'
   *  Constant: '<S149>/Int_BypC'
   *  Constant: '<S185>/Cste_4'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localMultiportSwitch_h = EngM_facACor_B;
  } else {
    localMultiportSwitch_h = 128U;
  }

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Byp_Fonction_SC'
   *  Constant: '<S150>/Int_BypC'
   *  Constant: '<S185>/Cste_2'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_h2 = EngM_facDCor_B;
  } else {
    localTmpSignalConversionAtEn_h2 = 128U;
  }

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Byp_Fonction_SC'
   *  Constant: '<S151>/Int_BypC'
   *  SignalConversion: '<S212>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalOutDTConv_or = EngM_mfAirScvCor_B;
  }

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/Byp_Fonction_SC'
   *  Constant: '<S152>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalTmpSignalConversionAt = EngM_mfTotExCor_B;
  }

  for (locali = 0; locali < 6; locali++) {
    /* Switch: '<S153>/Switch' incorporates:
     *  Constant: '<S153>/Byp_Fonction_SC'
     *  Constant: '<S153>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment1_e[locali] = EngM_prm_mAirScvCorCyl_B[(locali)];
    }

    /* Switch: '<S154>/Switch' incorporates:
     *  Constant: '<S154>/Byp_Fonction_SC'
     *  Constant: '<S154>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment1_f[locali] = EngM_prm_mfAirCorCyl_B[(locali)];
    }

    /* Switch: '<S155>/Switch' incorporates:
     *  Constant: '<S155>/Byp_Fonction_SC'
     *  Constant: '<S155>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment1_c[locali] = EngM_prm_mfAirScvCorCyl_B[(locali)];
    }

    /* Switch: '<S156>/Switch' incorporates:
     *  Constant: '<S156>/Byp_Fonction_SC'
     *  Constant: '<S156>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localTmpSignalConversionAtEn_mz[locali] = EngM_prm_mfTotExCorCyl_B[(locali)];
    }

    /* Switch: '<S157>/Switch' incorporates:
     *  Constant: '<S157>/Byp_Fonction_SC'
     *  Constant: '<S157>/Int_BypC'
     */
    if (ENGMGSLT_ACTIVE_BYP_C) {
      localAssignment2_n[locali] = EngM_prm_rTotLdExCorCyl_B[(locali)];
    }
  }

  /* Switch: '<S158>/Switch' incorporates:
   *  Constant: '<S158>/Byp_Fonction_SC'
   *  Constant: '<S158>/Int_BypC'
   *  Constant: '<S199>/offset'
   *  Constant: '<S199>/one_on_slope'
   *  DataTypeConversion: '<S199>/OutDTConv'
   *  Product: '<S199>/Product4'
   *  Sum: '<S199>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rAirLdCor_l = EngM_rAirLdCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 16384.0F * localSignalConversion2_f;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_rAirLdCor_l = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rAirLdCor_l = 0U;
      }
    } else {
      localEngM_rAirLdCor_l = MAX_uint16_T;
    }
  }

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Byp_Fonction_SC'
   *  Constant: '<S159>/Int_BypC'
   *  Constant: '<S193>/offset'
   *  Constant: '<S193>/one_on_slope'
   *  DataTypeConversion: '<S193>/OutDTConv'
   *  Product: '<S193>/Product4'
   *  Sum: '<S193>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rDeltaLdInjPha_l = EngM_rDeltaLdInjPha_B;
  } else {
    localAirEfc_facChrExpScvFil = 1.092266699E+004F *
      localAirEfc_rDeltaLdInjPhaRef;
    if (localAirEfc_facChrExpScvFil < 32768.0F) {
      if (localAirEfc_facChrExpScvFil >= -32768.0F) {
        localEngM_rDeltaLdInjPha_l = (SInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rDeltaLdInjPha_l = MIN_int16_T;
      }
    } else {
      localEngM_rDeltaLdInjPha_l = MAX_int16_T;
    }
  }

  /* Switch: '<S160>/Switch' incorporates:
   *  Constant: '<S160>/Byp_Fonction_SC'
   *  Constant: '<S160>/Int_BypC'
   *  Constant: '<S202>/offset'
   *  Constant: '<S202>/one_on_slope'
   *  DataTypeConversion: '<S202>/OutDTConv'
   *  Product: '<S202>/Product4'
   *  Sum: '<S202>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rItBurnRateCor_i = EngM_rItBurnRateCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 16384.0F * localDivide_d0;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_rItBurnRateCor_i = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rItBurnRateCor_i = 0U;
      }
    } else {
      localEngM_rItBurnRateCor_i = MAX_uint16_T;
    }
  }

  /* Switch: '<S161>/Switch' incorporates:
   *  Constant: '<S161>/Byp_Fonction_SC'
   *  Constant: '<S161>/Int_BypC'
   *  Constant: '<S188>/offset'
   *  Constant: '<S188>/one_on_slope'
   *  DataTypeConversion: '<S188>/OutDTConv'
   *  Product: '<S188>/Product4'
   *  Sum: '<S188>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvCor_o = EngM_facMassAirScvCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 65536.0F * localAirEfc_facMassAirScv;
    if (localAirEfc_facChrExpScvFil < 4.294967296E+009F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_facMassAirScvCor_o = (UInt32)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_facMassAirScvCor_o = 0U;
      }
    } else {
      localEngM_facMassAirScvCor_o = MAX_uint32_T;
    }
  }

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/Byp_Fonction_SC'
   *  Constant: '<S162>/Int_BypC'
   *  Constant: '<S201>/offset'
   *  Constant: '<S201>/one_on_slope'
   *  DataTypeConversion: '<S201>/OutDTConv'
   *  Product: '<S201>/Product4'
   *  Sum: '<S201>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rMassAirResiCor_b = EngM_rMassAirResiCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 16384.0F * localAirEfc_rMassAirResi;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_rMassAirResiCor_b = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rMassAirResiCor_b = 0U;
      }
    } else {
      localEngM_rMassAirResiCor_b = MAX_uint16_T;
    }
  }

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/Byp_Fonction_SC'
   *  Constant: '<S163>/Int_BypC'
   *  Constant: '<S186>/offset'
   *  Constant: '<S186>/one_on_slope'
   *  DataTypeConversion: '<S186>/OutDTConv'
   *  Product: '<S186>/Product4'
   *  Sum: '<S186>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rMassAirScvCor_c = EngM_rMassAirScvCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 16384.0F * localAirEfc_rMassAirScv;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_rMassAirScvCor_c = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rMassAirScvCor_c = 0U;
      }
    } else {
      localEngM_rMassAirScvCor_c = MAX_uint16_T;
    }
  }

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/Byp_Fonction_SC'
   *  Constant: '<S164>/Int_BypC'
   *  SignalConversion: '<S210>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalOutDTConv_mv = EngM_rTotLdExCor_B;
  }

  /* Switch: '<S165>/Switch' incorporates:
   *  Constant: '<S165>/Byp_Fonction_SC'
   *  Constant: '<S165>/Int_BypC'
   *  Constant: '<S187>/offset'
   *  Constant: '<S187>/one_on_slope'
   *  DataTypeConversion: '<S187>/OutDTConv'
   *  Product: '<S187>/Product4'
   *  Sum: '<S187>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_rltMassAirScvCor_l = EngM_rltMassAirScvCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 65536.0F * localSignalConversion6_n;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_rltMassAirScvCor_l = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_rltMassAirScvCor_l = 0U;
      }
    } else {
      localEngM_rltMassAirScvCor_l = MAX_uint16_T;
    }
  }

  /* Switch: '<S166>/Switch' incorporates:
   *  Constant: '<S166>/Byp_Fonction_SC'
   *  Constant: '<S166>/Int_BypC'
   *  Constant: '<S192>/offset'
   *  Constant: '<S192>/one_on_slope'
   *  DataTypeConversion: '<S192>/OutDTConv'
   *  Product: '<S192>/Product4'
   *  Sum: '<S192>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_tBurnCylCor_b = EngM_tBurnCylCor_B;
  } else {
    localAirEfc_facChrExpScvFil = (localAirEfc_tBurnCyl - 223.0F) * 32.0F;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_tBurnCylCor_b = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_tBurnCylCor_b = 0U;
      }
    } else {
      localEngM_tBurnCylCor_b = MAX_uint16_T;
    }
  }

  /* Switch: '<S167>/Switch' incorporates:
   *  Constant: '<S167>/Byp_Fonction_SC'
   *  Constant: '<S167>/Int_BypC'
   *  Constant: '<S198>/offset'
   *  Constant: '<S198>/one_on_slope'
   *  DataTypeConversion: '<S198>/OutDTConv'
   *  Product: '<S198>/Product4'
   *  Sum: '<S198>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_tMixtCylCor_m = EngM_tMixtCylCor_B;
  } else {
    localAirEfc_facChrExpScvFil = (localEngM_tMixtCyl - 223.0F) * 32.0F;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_tMixtCylCor_m = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_tMixtCylCor_m = 0U;
      }
    } else {
      localEngM_tMixtCylCor_m = MAX_uint16_T;
    }
  }

  /* Switch: '<S168>/Switch' incorporates:
   *  Constant: '<S168>/Byp_Fonction_SC'
   *  Constant: '<S168>/Int_BypC'
   *  Constant: '<S195>/offset'
   *  Constant: '<S195>/one_on_slope'
   *  DataTypeConversion: '<S195>/OutDTConv'
   *  Product: '<S195>/Product4'
   *  Sum: '<S195>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_tMixtCylGDICor_a = EngM_tMixtCylGDICor_B;
  } else {
    localAirEfc_facChrExpScvFil = (localSignalConversion1_d - 223.0F) * 32.0F;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_tMixtCylGDICor_a = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_tMixtCylGDICor_a = 0U;
      }
    } else {
      localEngM_tMixtCylGDICor_a = MAX_uint16_T;
    }
  }

  /* Switch: '<S171>/Switch' incorporates:
   *  Constant: '<S171>/Byp_Fonction_SC'
   *  Constant: '<S171>/Int_BypC'
   *  Constant: '<S203>/offset'
   *  Constant: '<S203>/one_on_slope'
   *  DataTypeConversion: '<S203>/OutDTConv'
   *  Product: '<S203>/Product4'
   *  Sum: '<S203>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassFlowLdCor_f = EngM_facMassFlowLdCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 163840.0F * localAirEfc_facMassFlowLd;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_facMassFlowLdCor_f = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_facMassFlowLdCor_f = 0U;
      }
    } else {
      localEngM_facMassFlowLdCor_f = MAX_uint16_T;
    }
  }

  /* Switch: '<S173>/Switch' incorporates:
   *  Constant: '<S173>/Byp_Fonction_SC'
   *  Constant: '<S173>/Int_BypC'
   *  Constant: '<S200>/offset'
   *  Constant: '<S200>/one_on_slope'
   *  DataTypeConversion: '<S200>/OutDTConv'
   *  Product: '<S200>/Product4'
   *  Sum: '<S200>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facOfsEfcCor_m = EngM_facOfsEfcCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 16384.0F * localAirEfc_facOfsEfc;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_facOfsEfcCor_m = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_facOfsEfcCor_m = 0U;
      }
    } else {
      localEngM_facOfsEfcCor_m = MAX_uint16_T;
    }
  }

  /* Switch: '<S174>/Switch' incorporates:
   *  Constant: '<S174>/Byp_Fonction_SC'
   *  Constant: '<S174>/Int_BypC'
   *  Constant: '<S194>/offset'
   *  Constant: '<S194>/one_on_slope'
   *  DataTypeConversion: '<S194>/OutDTConv'
   *  Product: '<S194>/Product4'
   *  Sum: '<S194>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facSlopEfcCor_l = EngM_facSlopEfcCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 2.978909184E+009F * localAirEfc_facSlopEfc;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_facSlopEfcCor_l = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_facSlopEfcCor_l = 0U;
      }
    } else {
      localEngM_facSlopEfcCor_l = MAX_uint16_T;
    }
  }

  /* Switch: '<S175>/Switch' incorporates:
   *  Constant: '<S175>/Byp_Fonction_SC'
   *  Constant: '<S175>/Int_BypC'
   *  Constant: '<S197>/offset'
   *  Constant: '<S197>/one_on_slope'
   *  DataTypeConversion: '<S197>/OutDTConv'
   *  Product: '<S197>/Product4'
   *  Sum: '<S197>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mAirCor_h = EngM_mAirCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 8.389145E+006F * localEngM_mAir;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_mAirCor_h = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_mAirCor_h = 0U;
      }
    } else {
      localEngM_mAirCor_h = MAX_uint16_T;
    }
  }

  /* Switch: '<S176>/Switch' incorporates:
   *  Constant: '<S176>/Byp_Fonction_SC'
   *  Constant: '<S176>/Int_BypC'
   *  SignalConversion: '<S211>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalOutDTConv_dy = EngM_mAirScvCor_B;
  }

  /* Switch: '<S177>/Switch' incorporates:
   *  Constant: '<S177>/Byp_Fonction_SC'
   *  Constant: '<S177>/Int_BypC'
   *  Constant: '<S196>/offset'
   *  Constant: '<S196>/one_on_slope'
   *  DataTypeConversion: '<S196>/OutDTConv'
   *  Product: '<S196>/Product4'
   *  Sum: '<S196>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mBurnCor_n = EngM_mBurnCor_B;
  } else {
    localAirEfc_facChrExpScvFil = 8.389145E+006F * localEngM_mBurn;
    if (localAirEfc_facChrExpScvFil < 65536.0F) {
      if (localAirEfc_facChrExpScvFil >= 0.0F) {
        localEngM_mBurnCor_n = (UInt16)localAirEfc_facChrExpScvFil;
      } else {
        localEngM_mBurnCor_n = 0U;
      }
    } else {
      localEngM_mBurnCor_n = MAX_uint16_T;
    }
  }

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S178>/Byp_Fonction_SC'
   *  Constant: '<S178>/Int_BypC'
   *  SignalConversion: '<S213>/TmpSignal ConversionAtSignal Conversion1Inport1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    locallocalOutDTConv_b = EngM_mfAirCor_B;
  }

  /* SignalConversion: '<S14>/SignalConversion1' */
  localAirEfc_facChrExpScvFilCo_b = localOutDTConv_io;

  /* SignalConversion: '<S14>/SignalConversion4' */
  localEngM_facECor_irv_k = localOutDTConv_mf;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirEfc_facChrExpFilCor_irvInport2' incorporates:
   *  SignalConversion: '<S14>/SignalConversion5'
   */
  Rte_IrvWrite_RE_EngMGslT_018_TEV_AirEfc_facChrExpFilCor_irv(localOutDTConv_a);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAirEfc_facChrExpScvFilCor_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_018_TEV_AirEfc_facChrExpScvFilCor_irv
    (localAirEfc_facChrExpScvFilCo_b);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facACorInport2' */
  Rte_Write_P_EngM_facACor_EngM_facACor(localMultiportSwitch_h);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facDCorInport2' */
  Rte_Write_P_EngM_facDCor_EngM_facDCor(localTmpSignalConversionAtEn_h2);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facECor_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_018_TEV_EngM_facECor_irv(localEngM_facECor_irv_k);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facMassAirScvCorInport2' */
  Rte_Write_P_EngM_facMassAirScvCor_EngM_facMassAirScvCor
    (localEngM_facMassAirScvCor_o);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facMassFlowLdCorInport2' */
  Rte_Write_P_EngM_facMassFlowLdCor_EngM_facMassFlowLdCor
    (localEngM_facMassFlowLdCor_f);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facOfsEfcCorInport2' */
  Rte_Write_P_EngM_facOfsEfcCor_EngM_facOfsEfcCor(localEngM_facOfsEfcCor_m);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_facSlopEfcCorInport2' */
  Rte_Write_P_EngM_facSlopEfcCor_EngM_facSlopEfcCor(localEngM_facSlopEfcCor_l);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mAirCorInport2' */
  Rte_Write_P_EngM_mAirCor_EngM_mAirCor(localEngM_mAirCor_h);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mAirScvCorInport2' */
  Rte_Write_P_EngM_mAirScvCor_EngM_mAirScvCor(locallocalOutDTConv_dy);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mBurnCorInport2' */
  Rte_Write_P_EngM_mBurnCor_EngM_mBurnCor(localEngM_mBurnCor_n);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mfAirCorInport2' */
  Rte_Write_P_EngM_mfAirCor_EngM_mfAirCor(locallocalOutDTConv_b);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mfAirScvCorInport2' */
  Rte_Write_P_EngM_mfAirScvCor_EngM_mfAirScvCor(locallocalOutDTConv_or);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_mfTotExCorInport2' */
  Rte_Write_P_EngM_mfTotExCor_EngM_mfTotExCor(locallocalTmpSignalConversionAt);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_mAirScvCorCylInport2' */
  Rte_Write_P_EngM_prm_mAirScvCorCyl_EngM_prm_mAirScvCorCyl(&localAssignment1_e);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_mfAirCorCylInport2' */
  Rte_Write_P_EngM_prm_mfAirCorCyl_EngM_prm_mfAirCorCyl(&localAssignment1_f);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_mfAirScvCorCylInport2' */
  Rte_Write_P_EngM_prm_mfAirScvCorCyl_EngM_prm_mfAirScvCorCyl
    (&localAssignment1_c);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_mfTotExCorCylInport2' */
  Rte_Write_P_EngM_prm_mfTotExCorCyl_EngM_prm_mfTotExCorCyl
    (&localTmpSignalConversionAtEn_mz);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_prm_rTotLdExCorCylInport2' */
  Rte_Write_P_EngM_prm_rTotLdExCorCyl_EngM_prm_rTotLdExCorCyl
    (&localAssignment2_n);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rAirLdCorInport2' */
  Rte_Write_P_EngM_rAirLdCor_EngM_rAirLdCor(localEngM_rAirLdCor_l);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rDeltaLdInjPhaInport2' */
  Rte_Write_P_EngM_rDeltaLdInjPha_EngM_rDeltaLdInjPha(localEngM_rDeltaLdInjPha_l);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rItBurnRateCorInport2' */
  Rte_Write_P_EngM_rItBurnRateCor_EngM_rItBurnRateCor(localEngM_rItBurnRateCor_i);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rMassAirResiCorInport2' */
  Rte_Write_P_EngM_rMassAirResiCor_EngM_rMassAirResiCor
    (localEngM_rMassAirResiCor_b);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rMassAirScvCorInport2' */
  Rte_Write_P_EngM_rMassAirScvCor_EngM_rMassAirScvCor(localEngM_rMassAirScvCor_c);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rTotLdExCorInport2' */
  Rte_Write_P_EngM_rTotLdExCor_EngM_rTotLdExCor(locallocalOutDTConv_mv);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_rltMassAirScvCorInport2' */
  Rte_Write_P_EngM_rltMassAirScvCor_EngM_rltMassAirScvCor
    (localEngM_rltMassAirScvCor_l);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_tBurnCylCorInport2' */
  Rte_Write_P_EngM_tBurnCylCor_EngM_tBurnCylCor(localEngM_tBurnCylCor_b);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_tMixtCylCorInport2' */
  Rte_Write_P_EngM_tMixtCylCor_EngM_tMixtCylCor(localEngM_tMixtCylCor_m);

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEngM_tMixtCylGDICorInport2' */
  Rte_Write_P_EngM_tMixtCylGDICor_EngM_tMixtCylGDICor(localEngM_tMixtCylGDICor_a);
}

/* Start for exported function: RE_EngMGslT_022_TEV */
void RE_EngMGslT_022_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IntkLoaReq'
   *
   * Block requirements for '<S1>/F01_IntkLoaReq':
   *  1. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  2. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  3. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  4. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_159.01 ;
   *  5. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  6. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_196.01 ;
   *  7. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_197.01 ;
   *  8. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  9. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_281.01 ;
   *  10. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_282.01 ;
   *  11. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_275.03 ;
   *  12. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_055.01 ;
   *  13. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_056.01 ;
   *  14. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_059.01 ;
   *  15. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  16. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  17. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  18. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  19. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_264.02 ;
   *  20. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_053.03 ;
   *  21. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_054.03 ;
   *  22. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_162.04 ;
   *  23. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_292.01 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_022_TEV */
void RE_EngMGslT_022_TEV(void)
{
  /* local block i/o variables */
  Float32 localDataTypeConversion1_i;
  Float32 localDataTypeConversion2_j;
  Float32 localDataTypeConversion3_g;
  Float32 localDataTypeConversion16_o;
  Float32 localDataTypeConversion17_a;
  Float32 localDataTypeConversion18_p;
  Float32 localDataTypeConversion20_p;
  Float32 localDataTypeConversion21_b;
  Float32 localDataTypeConversion22_j;
  Float32 localTmpSignalConversionAtSi_co;
  Float32 localTmpSignalConversionAtSi_ay;
  Float32 localDataTypeConversion11_c;
  Float32 localDataTypeConversion12_a;
  Float32 localDataTypeConversion9_n;
  Float32 localTmpSignalConversionAtSi_o5;
  UInt32 localOutDTConv_l1;
  UInt16 localDataTypeConversion1_f;
  UInt16 localSignalConversion4_gz;
  UInt16 localSignalConversion6_d;
  UInt16 localOutDTConv_nx;
  UInt16 localOutDTConv_fl;
  UInt16 localOutDTConv_kc;
  UInt16 localOutDTConv_p;
  UInt16 localOutDTConv_d0;
  UInt16 localLookUpTable;
  UInt16 localOutDTConv_fo;
  UInt16 localOutDTConv_bq;
  UInt16 localOutDTConv_e0;
  UInt16 localOutDTConv_hi;
  UInt16 localOutDTConv_cb;
  UInt16 localOutDTConv_g5;
  UInt16 localSignalConversion19;
  UInt16 localDataTypeConversion5_m;
  UInt16 localDataTypeConversion8_k;
  UInt8 localOutDTConv_j0;
  Float32 localTmpSignalConversionAtSi_jc;
  Float32 localTmpSignalConversionAtSi_gp;
  Float32 localTmpSignalConversionAtSi_bm;
  Float32 localSignalConversion13;
  Float32 localSignalConversion5_c;
  Float32 localSignalConversion2_h;
  UInt8 localMultiportSwitch_b;
  Float32 localSignalConversion4_f;
  Float32 localSignalConversion9;
  Float32 localSignalConversion5_p;
  Float32 localSignalConversion3_j;
  Float32 localDivide_mv;
  Float32 localEngM_rAirLdAtm;
  UInt16 localAirEfc_facChrExpScvFilRe_b;
  UInt16 localEngM_pBegCorBoostSlopEfc_l;
  UInt16 localInM_pDsThrPrev_irv_f;
  UInt16 localEngM_rVolCylClsInVlvPrev_p;
  UInt16 localEngM_facTAirUsInVlvPrev__c;
  UInt16 localEngM_facCorAtmSlopEfcPre_k;
  UInt16 localEngM_facCorBoostSlopEfcP_n;
  UInt16 localEngM_pDeltaCorSlopEfcPre_j;
  UInt32 localEngM_facMassAirScvReq_j;
  SInt16 localTmpSignalConversionAtEn_hu;
  SInt16 localTmpSignalConversionAtEn_bh;
  UInt16 localTmpSignalConversionAtEng_c;
  UInt16 localTmpSignalConversionAtAirSy;
  Float32 localtmp;

  /* S-Function (fcncallgen): '<S9>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IntkLoaReq'
   *
   * Block requirements for '<S1>/F01_IntkLoaReq':
   *  1. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_101.01 ;
   *  2. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  3. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  4. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_159.01 ;
   *  5. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_161.02 ;
   *  6. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_196.01 ;
   *  7. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_197.01 ;
   *  8. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  9. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_281.01 ;
   *  10. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_282.01 ;
   *  11. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_275.03 ;
   *  12. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_055.01 ;
   *  13. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_056.01 ;
   *  14. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_059.01 ;
   *  15. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_198.01 ;
   *  16. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_291.01 ;
   *  17. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_260.02 ;
   *  18. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  19. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_264.02 ;
   *  20. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_053.03 ;
   *  21. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_054.03 ;
   *  22. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_162.04 ;
   *  23. SubSystem "F01_IntkLoaReq" !Trace_To : VEMS_R_11_00998_292.01 ;
   */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslT_B.TmpSignalConversionAtExt_nEng_b);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_agCkClsExVlvReqRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvReqRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkClsExVlvReqRef1_EngM_agCkClsExVlvReqRef1
    (&localTmpSignalConversionAtEn_hu);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_agCkOpInVlvReqRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvReqRef1_INPUT'
   */
  Rte_Read_R_EngM_agCkOpInVlvReqRef1_EngM_agCkOpInVlvReqRef1
    (&localTmpSignalConversionAtEn_bh);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&EngMGslT_B.TmpSignalConversionAtInThM_tAir);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtExM_prm_tExMnfEstimCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_tExMnfEstimCyl'
   */
  Rte_Read_R_ExM_prm_tExMnfEstimCyl_ExM_prm_tExMnfEstimCyl
    (&EngMGslT_B.TmpSignalConversionAtExM_prm_tE);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtExM_prm_pExMnfEstimOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/ExM_prm_pExMnfEstimOvlpCyl'
   */
  Rte_Read_R_ExM_prm_pExMnfEstimOvlpCyl_ExM_prm_pExMnfEstimOvlpCyl
    (&EngMGslT_B.TmpSignalConversionAtExM_prm_pE);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor
    (&EngMGslT_B.TmpSignalConversionAtInM_pDsThr);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&EngMGslT_B.TmpSignalConversionAtUsThrM_p_h);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp
    (&EngMGslT_B.TmpSignalConversionAtFARSp_rMix);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor
    (&EngMGslT_B.TmpSignalConversionAtInM_concAi);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInM_prm_pDsThrPredOvlpCylOutport2' incorporates:
   *  Inport: '<Root>/InM_prm_pDsThrPredOvlpCyl'
   */
  Rte_Read_R_InM_prm_pDsThrPredOvlpCyl_InM_prm_pDsThrPredOvlpCyl
    (&EngMGslT_B.TmpSignalConversionAtInM_prm_pD);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEng_noInCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noInCyl'
   */
  Rte_Read_R_Eng_noInCyl_Eng_noInCyl(&EngMGslT_B.TmpSignalConversionAtEng_noInCy);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_agBegInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH1ReqCyl_InjSys_prm_agBegInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_prm);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_agEndInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH1ReqCyl_InjSys_prm_agEndInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_f);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_mFuInjH1ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH1ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH1ReqCyl_InjSys_prm_mFuInjH1ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_c);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtFuSysM_tFuOutport2' incorporates:
   *  Inport: '<Root>/FuSysM_tFu'
   */
  Rte_Read_R_FuSysM_tFu_FuSysM_tFu(&EngMGslT_B.TmpSignalConversionAtFuSysM_tFu);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorOfsEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorOfsEfc'
   */
  Rte_Read_R_EngM_facCorOfsEfc_EngM_facCorOfsEfc
    (&EngMGslT_B.TmpSignalConversionAtEngM_facCo);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorSlopEfcOutport2' incorporates:
   *  Inport: '<Root>/EngM_facCorSlopEfc'
   */
  Rte_Read_R_EngM_facCorSlopEfc_EngM_facCorSlopEfc
    (&EngMGslT_B.TmpSignalConversionAtEngM_fa_ht);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_agBegInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agBegInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agBegInjH2ReqCyl_InjSys_prm_agBegInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys__fr);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_agEndInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_agEndInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_agEndInjH2ReqCyl_InjSys_prm_agEndInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys_p_b);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInjSys_prm_mFuInjH2ReqCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_mFuInjH2ReqCyl'
   */
  Rte_Read_R_InjSys_prm_mFuInjH2ReqCyl_InjSys_prm_mFuInjH2ReqCyl
    (&EngMGslT_B.TmpSignalConversionAtInjSys__cc);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEng_noCmprCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmprCyl'
   */
  Rte_Read_R_Eng_noCmprCyl_Eng_noCmprCyl
    (&EngMGslT_B.TmpSignalConversionAtEng_noCmpr);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEng_noCmbCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noCmbCyl'
   */
  Rte_Read_R_Eng_noCmbCyl_Eng_noCmbCyl
    (&EngMGslT_B.TmpSignalConversionAtEng_noCmbC);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEng_noExCylOutport2' incorporates:
   *  Inport: '<Root>/Eng_noExCyl'
   */
  Rte_Read_R_Eng_noExCyl_Eng_noExCyl(&EngMGslT_B.TmpSignalConversionAtEng_noExCy);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor
    (&EngMGslT_B.TmpSignalConversionAtInThM_nEng);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facOfsEfcReq1Outport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcReq_INPUT'
   */
  Rte_Read_R_EngM_facOfsEfcReq_EngM_facOfsEfcReq
    (&localTmpSignalConversionAtEng_c);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirSys_rAirLdReqOutport2' incorporates:
   *  Inport: '<Root>/AirSys_rAirLdReq'
   */
  Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&localTmpSignalConversionAtAirSy);

  /* Outputs for atomic SubSystem: '<S15>/F03_Input_Interface_IntkLoaReq'
   * Block description for '<S15>/F03_Input_Interface_IntkLoaReq':
   *  CSMT_CGMT09_0052_2.FR.5.1
   *
   * Block requirements for '<S15>/F03_Input_Interface_IntkLoaReq':
   *  1. SubSystem "F03_Input_Interface_IntkLoaReq" !Trace_To : VEMS_R_11_00998_057.03 ;
   */

  /* DataTypeConversion: '<S260>/SignalConversion13' */
  localSignalConversion13 = ((Float32)
    EngMGslT_B.TmpSignalConversionAtUsThrM_p_h) * 8.0F;

  /* DataTypeConversion: '<S260>/SignalConversion5' */
  localSignalConversion5_c = (((Float32)
    EngMGslT_B.TmpSignalConversionAtInM_concAi) * 1.525878906E-005F) +
    1.525878906E-005F;

  /* DataTypeConversion: '<S260>/SignalConversion2' */
  localSignalConversion2_h = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_fa_ht) * 3.051757813E-005F;

  /* Outputs for atomic SubSystem: '<S260>/F01_Variables_assignment' *
   * Block requirements for '<S260>/F01_Variables_assignment':
   *  1. SubSystem "F01_Variables_assignment" !Trace_To : VEMS_R_11_00998_293.01 ;
   */

  /* DataTypeConversion: '<S280>/Data Type Conversion1' */
  localDataTypeConversion1_i = ((Float32)localTmpSignalConversionAtEn_hu) *
    0.09375F;

  /* DataTypeConversion: '<S280>/Data Type Conversion2' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_agCkClsInVlvReqRef1_irvOutport2'
   */
  localDataTypeConversion2_j = (((Float32)
    Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_agCkClsInVlvReqRef1_irv()) * 0.75F) +
    84.0F;

  /* DataTypeConversion: '<S280>/Data Type Conversion3' */
  localDataTypeConversion3_g = ((Float32)localTmpSignalConversionAtEn_bh) *
    0.09375F;

  /* SignalConversion: '<S280>/Signal Conversion19' */
  localSignalConversion19 = EngMGslT_B.TmpSignalConversionAtInThM_tAir;

  /* DataTypeConversion: '<S280>/Data Type Conversion16' incorporates:
   *  Selector: '<S280>/Selector7'
   */
  localDataTypeConversion16_o = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInM_prm_pD[EngMGslT_B.TmpSignalConversionAtEng_noInCy
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S280>/Data Type Conversion17' incorporates:
   *  Selector: '<S280>/Selector8'
   */
  localDataTypeConversion17_a = ((Float32)
    EngMGslT_B.TmpSignalConversionAtExM_prm_pE[EngMGslT_B.TmpSignalConversionAtEng_noInCy
    - 1]) * 8.0F;

  /* DataTypeConversion: '<S280>/Data Type Conversion18' incorporates:
   *  Selector: '<S280>/Selector9'
   */
  localDataTypeConversion18_p = (((Float32)
    EngMGslT_B.TmpSignalConversionAtExM_prm_tE[EngMGslT_B.TmpSignalConversionAtEng_noInCy
    - 1]) * 0.03125F) + 223.0F;

  /* MultiPortSwitch: '<S280>/Multiport Switch' incorporates:
   *  Constant: '<S280>/EngM_noPhaInjLoaReq_C'
   */
  switch (EngM_noPhaInjLoaReq_C + 1) {
   case 1:
    localMultiportSwitch_b = EngMGslT_B.TmpSignalConversionAtEng_noInCy;
    break;

   case 2:
    localMultiportSwitch_b = EngMGslT_B.TmpSignalConversionAtEng_noCmpr;
    break;

   case 3:
    localMultiportSwitch_b = EngMGslT_B.TmpSignalConversionAtEng_noCmbC;
    break;

   default:
    localMultiportSwitch_b = EngMGslT_B.TmpSignalConversionAtEng_noExCy;
    break;
  }

  /* DataTypeConversion: '<S280>/Data Type Conversion20' incorporates:
   *  Selector: '<S280>/Selector6'
   */
  localDataTypeConversion20_p = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys_prm[localMultiportSwitch_b - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S280>/Data Type Conversion21' incorporates:
   *  Selector: '<S280>/Selector4'
   */
  localDataTypeConversion21_b = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys_p_f[localMultiportSwitch_b - 1]) *
    0.0625F;

  /* DataTypeConversion: '<S280>/Data Type Conversion22' incorporates:
   *  Selector: '<S280>/Selector3'
   */
  localDataTypeConversion22_j = ((Float32)
    EngMGslT_B.TmpSignalConversionAtInjSys_p_c[localMultiportSwitch_b - 1]) *
    7.450580597E-009F;

  /* Selector: '<S280>/Selector1' */
  EngMGslT_B.Selector1 =
    EngMGslT_B.TmpSignalConversionAtInjSys_p_b[localMultiportSwitch_b - 1];

  /* Selector: '<S280>/Selector2' */
  EngMGslT_B.Selector2 =
    EngMGslT_B.TmpSignalConversionAtInjSys__fr[localMultiportSwitch_b - 1];

  /* Selector: '<S280>/Selector5' */
  EngMGslT_B.Selector5 =
    EngMGslT_B.TmpSignalConversionAtInjSys__cc[localMultiportSwitch_b - 1];

  /* SignalConversion: '<S280>/TmpSignal ConversionAtSignal Conversion15Inport1' */
  localTmpSignalConversionAtSi_co = localSignalConversion13;

  /* DataTypeConversion: '<S280>/Data Type Conversion5' */
  localEngM_facMassAirScvReq_j = (UInt32)((SInt32)(((UInt32)
    (EngMGslT_B.TmpSignalConversionAtFARSp_rMix * 17857)) >> 14));
  if (localEngM_facMassAirScvReq_j > 65535U) {
    localDataTypeConversion5_m = MAX_uint16_T;
  } else {
    localDataTypeConversion5_m = (UInt16)localEngM_facMassAirScvReq_j;
  }

  /* SignalConversion: '<S280>/TmpSignal ConversionAtSignal Conversion17Inport1' */
  localTmpSignalConversionAtSi_ay = localSignalConversion5_c;

  /* DataTypeConversion: '<S280>/Data Type Conversion11' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtAirEfc_facChrExpFilReq1Outport2'
   */
  localDataTypeConversion11_c = ((Float32)
    Rte_IrvRead_RE_EngMGslT_022_TEV_AirEfc_facChrExpFilReq_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S280>/Data Type Conversion12' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtAirEfc_facChrExpScvFilReq1Outport2'
   */
  localDataTypeConversion12_a = ((Float32)
    Rte_IrvRead_RE_EngMGslT_022_TEV_AirEfc_facChrExpScvFilReq_irv()) *
    1.525878906E-005F;

  /* DataTypeConversion: '<S280>/Data Type Conversion8' */
  localEngM_facMassAirScvReq_j = (UInt32)
    (EngMGslT_B.TmpSignalConversionAtFuSysM_tFu + 10);
  if (localEngM_facMassAirScvReq_j > 65535U) {
    localDataTypeConversion8_k = MAX_uint16_T;
  } else {
    localDataTypeConversion8_k = (UInt16)localEngM_facMassAirScvReq_j;
  }

  /* DataTypeConversion: '<S280>/Data Type Conversion9' */
  localDataTypeConversion9_n = ((Float32)
    EngMGslT_B.TmpSignalConversionAtEngM_facCo) * 3.051757813E-005F;

  /* SignalConversion: '<S280>/TmpSignal ConversionAtSignal Conversion21Inport1' */
  localTmpSignalConversionAtSi_o5 = localSignalConversion2_h;

  /* SignalConversion: '<S280>/Signal Conversion4' */
  localSignalConversion4_gz = EngMGslT_B.TmpSignalConversionAtInThM_nEng;

  /* SignalConversion: '<S280>/Signal Conversion6' */
  localSignalConversion6_d = EngMGslT_B.TmpSignalConversionAtExt_nEng_b;

  /* end of Outputs for SubSystem: '<S260>/F01_Variables_assignment' */

  /* If: '<S260>/If' incorporates:
   *  ActionPort: '<S281>/Action Port'
   *  ActionPort: '<S282>/Action Port'
   *  Constant: '<S260>/EngM_bAcvReqPres_C'
   *  SubSystem: '<S260>/F02_required_pressure_calculation'
   *  SubSystem: '<S260>/F03_Default_pressure'
   *
   * Block requirements for '<S260>/F02_required_pressure_calculation':
   *  1. SubSystem "F02_required_pressure_calculation" !Trace_To : VEMS_R_11_00998_294.01 ;
   *
   * Block requirements for '<S260>/F03_Default_pressure':
   *  1. SubSystem "F03_Default_pressure" !Trace_To : VEMS_R_11_00998_300.01 ;
   */
  if (EngM_bAcvReqPres_C) {
    /* DataTypeConversion: '<S281>/SignalConversion4' incorporates:
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_pBegCorBoostSlopEfcPrevOutport2'
     */
    localSignalConversion4_f = ((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_pBegCorBoostSlopEfcPrev_irv()) * 8.0F;

    /* DataTypeConversion: '<S281>/SignalConversion9' */
    localSignalConversion9 = ((Float32)localTmpSignalConversionAtEng_c) *
      6.103515625E-005F;

    /* DataTypeConversion: '<S281>/SignalConversion5' incorporates:
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_pDeltaCorSlopEfcPrevOutport2'
     */
    localSignalConversion5_p = ((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_pDeltaCorSlopEfcPrev_irv()) * 8.0F;

    /* DataTypeConversion: '<S281>/SignalConversion3' incorporates:
     *  Constant: '<S281>/1//AirEfc_pRef_C'
     */
    localSignalConversion3_j = ((Float32)AirEfc_pRef_C) * 8.0F;

    /* Product: '<S289>/Divide' */
    localDivide_mv = localSignalConversion13 / localSignalConversion3_j;

    /* Outputs for atomic SubSystem: '<S281>/F05_Slop_correction_for_alternative_fuel' *
     * Block requirements for '<S281>/F05_Slop_correction_for_alternative_fuel':
     *  1. SubSystem "F05_Slop_correction_for_alternative_fuel" !Trace_To : VEMS_R_11_00998_299.01 ;
     */

    /* Switch: '<S288>/Switch1' incorporates:
     *  Constant: '<S288>/AirEfc_bAcvAirLdCor_C'
     *  Constant: '<S288>/Cste_1'
     */
    if (!AirEfc_bAcvAirLdCor_C) {
      localSignalConversion2_h = 1.0F;
    }

    /* end of Outputs for SubSystem: '<S281>/F05_Slop_correction_for_alternative_fuel' */

    /* Product: '<S290>/Divide' incorporates:
     *  DataTypeConversion: '<S281>/SignalConversion1'
     *  DataTypeConversion: '<S281>/SignalConversion2'
     *  DataTypeConversion: '<S281>/SignalConversion6'
     *  DataTypeConversion: '<S281>/SignalConversion8'
     *  Product: '<S291>/Divide'
     *  Product: '<S292>/Divide'
     *  Product: '<S293>/Divide'
     *  Product: '<S294>/Divide'
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorAtmSlopEfcPrevOutport2'
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facTAirUsInVlvPrevOutport2'
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facTCoPrevOutport2'
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_rVolCylClsInVlvPrevOutport2'
     */
    EngM_facAtmSlop_MP = (((((((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_facTCoPrev_irv()) * 0.0078125F) *
      (((Float32)Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_rVolCylClsInVlvPrev_irv())
       * 3.051757813E-005F)) * (((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_facCorAtmSlopEfcPrev_irv()) *
      3.051757813E-005F)) * localSignalConversion2_h) * (((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_facTAirUsInVlvPrev_irv()) *
      3.051757813E-005F)) / localSignalConversion3_j;

    /* Outputs for atomic SubSystem: '<S281>/F01_Boost_air_load_calculation' */

    /* Product: '<S298>/Divide' incorporates:
     *  DataTypeConversion: '<S281>/SignalConversion7'
     *  SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorBoostSlopEfcPrevOutport2'
     */
    EngM_facBoostSlop_MP = (((Float32)
      Rte_IrvRead_RE_EngMGslT_022_TEV_EngM_facCorBoostSlopEfcPrev_irv()) *
      3.051757813E-005F) * EngM_facAtmSlop_MP;

    /* end of Outputs for SubSystem: '<S281>/F01_Boost_air_load_calculation' */

    /* Outputs for atomic SubSystem: '<S281>/F02_Atm_air_load_calculation' *
     * Block requirements for '<S281>/F02_Atm_air_load_calculation':
     *  1. SubSystem "F02_Atm_air_load_calculation" !Trace_To : VEMS_R_11_00998_295.01 ;
     */

    /* Product: '<S300>/Divide' incorporates:
     *  Product: '<S299>/Divide'
     *  Product: '<S301>/Divide'
     *  Sum: '<S285>/Add'
     */
    localEngM_rAirLdAtm = (((EngM_facAtmSlop_MP * localSignalConversion4_f) *
      localDivide_mv) - localSignalConversion9) * localSignalConversion5_c;

    /* end of Outputs for SubSystem: '<S281>/F02_Atm_air_load_calculation' */

    /* Outputs for atomic SubSystem: '<S281>/F03_Required_pressure_calculation' *
     * Block requirements for '<S281>/F03_Required_pressure_calculation':
     *  1. SubSystem "F03_Required_pressure_calculation" !Trace_To : VEMS_R_11_00998_297.01 ;
     */

    /* Product: '<S304>/Divide' incorporates:
     *  DataTypeConversion: '<S281>/SignalConversion10'
     *  Product: '<S295>/Divide'
     *  Product: '<S296>/Divide'
     *  Product: '<S297>/Divide'
     *  Sum: '<S284>/Add'
     *  Sum: '<S284>/Add1'
     *  Sum: '<S286>/Add'
     *  Sum: '<S286>/Add1'
     */
    localEngM_rAirLdAtm = ((((Float32)localTmpSignalConversionAtAirSy) *
      6.103515625E-005F) - localEngM_rAirLdAtm) / ((((((localSignalConversion4_f
      + localSignalConversion5_p) * EngM_facBoostSlop_MP) * localDivide_mv) -
      localSignalConversion9) * localSignalConversion5_c) - localEngM_rAirLdAtm);

    /* Outputs for atomic SubSystem: '<S304>/If Action Subsystem3' */

    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant1'
     *  Constant: '<S309>/Constant2'
     *  Constant: '<S309>/Constant3'
     *  Logic: '<S309>/Logical Operator1'
     *  RelationalOperator: '<S309>/Relational Operator'
     *  RelationalOperator: '<S309>/Relational Operator1'
     *  RelationalOperator: '<S309>/Relational Operator3'
     */
    if (((localEngM_rAirLdAtm != localEngM_rAirLdAtm) || (localEngM_rAirLdAtm >
          3.000000005E+038F)) || (-3.000000005E+038F > localEngM_rAirLdAtm)) {
      localEngM_rAirLdAtm = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S304>/If Action Subsystem3' */

    /* DataTypeConversion: '<S303>/OutDTConv' incorporates:
     *  Constant: '<S303>/offset'
     *  Constant: '<S303>/one_on_slope'
     *  Product: '<S303>/Product4'
     *  Sum: '<S303>/Add1'
     */
    localSignalConversion9 = 65536.0F * localEngM_rAirLdAtm;
    if (localSignalConversion9 < 65536.0F) {
      if (localSignalConversion9 >= 0.0F) {
        localOutDTConv_d0 = (UInt16)localSignalConversion9;
      } else {
        localOutDTConv_d0 = 0U;
      }
    } else {
      localOutDTConv_d0 = MAX_uint16_T;
    }

    /* Lookup: '<S302>/Look-Up Table'
     * About '<S302>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-16
     * Output0 Data Type:  Fixed Point    U16  2^-16
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable), (&(EngM_facChgCorSlopEfc_T[0])),
                   localOutDTConv_d0, (&(EngM_facChgCorSlopEfc_A[0])), 10U);

    /* DataTypeDuplicate Block: '<S302>/Data Type Duplicate1'
     *
     * Regarding '<S302>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion: '<S286>/SignalConversion1' incorporates:
     *  Lookup: '<S302>/Look-Up Table'
     */
    localSignalConversion2_h = ((Float32)localLookUpTable) * 1.525878906E-005F;

    /* Sum: '<S286>/Add5' incorporates:
     *  Constant: '<S286>/Cste_0'
     *  Constant: '<S286>/Cste_1'
     *  MinMax: '<S286>/MinMax'
     *  MinMax: '<S286>/MinMax1'
     *  Product: '<S305>/Divide'
     *  Product: '<S306>/Divide'
     *  Product: '<S307>/Divide'
     */
    localSignalConversion3_j = ((localSignalConversion5_p * localDivide_mv) *
      rt_MINf(localSignalConversion2_h, 1.0F)) + (localDivide_mv *
      localSignalConversion4_f);

    /* end of Outputs for SubSystem: '<S281>/F03_Required_pressure_calculation' */

    /* Outputs for atomic SubSystem: '<S281>/F04_Pressure_Ratio_calculation' *
     * Block requirements for '<S281>/F04_Pressure_Ratio_calculation':
     *  1. SubSystem "F04_Pressure_Ratio_calculation" !Trace_To : VEMS_R_11_00998_298.01 ;
     */

    /* Product: '<S310>/Divide' */
    localEngM_rAirLdAtm = localSignalConversion3_j / localSignalConversion13;

    /* Outputs for atomic SubSystem: '<S310>/If Action Subsystem3' */

    /* Switch: '<S312>/Switch1' incorporates:
     *  Constant: '<S312>/Constant1'
     *  Constant: '<S312>/Constant2'
     *  Constant: '<S312>/Constant3'
     *  Logic: '<S312>/Logical Operator1'
     *  RelationalOperator: '<S312>/Relational Operator'
     *  RelationalOperator: '<S312>/Relational Operator1'
     *  RelationalOperator: '<S312>/Relational Operator3'
     */
    if (((localEngM_rAirLdAtm != localEngM_rAirLdAtm) || (localEngM_rAirLdAtm >
          3.000000005E+038F)) || (-3.000000005E+038F > localEngM_rAirLdAtm)) {
      localEngM_rAirLdAtm = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S310>/If Action Subsystem3' */

    /* end of Outputs for SubSystem: '<S281>/F04_Pressure_Ratio_calculation' */
  } else {
    /* DataTypeConversion: '<S282>/SignalConversion13' */
    localSignalConversion3_j = ((Float32)
      EngMGslT_B.TmpSignalConversionAtInM_pDsThr) * 8.0F;

    /* Product: '<S313>/Divide' */
    localEngM_rAirLdAtm = localSignalConversion3_j / localSignalConversion13;

    /* Outputs for atomic SubSystem: '<S313>/If Action Subsystem3' */

    /* Switch: '<S315>/Switch1' incorporates:
     *  Constant: '<S315>/Constant1'
     *  Constant: '<S315>/Constant2'
     *  Constant: '<S315>/Constant3'
     *  Logic: '<S315>/Logical Operator1'
     *  RelationalOperator: '<S315>/Relational Operator'
     *  RelationalOperator: '<S315>/Relational Operator1'
     *  RelationalOperator: '<S315>/Relational Operator3'
     */
    if (((localEngM_rAirLdAtm != localEngM_rAirLdAtm) || (localEngM_rAirLdAtm >
          3.000000005E+038F)) || (-3.000000005E+038F > localEngM_rAirLdAtm)) {
      localEngM_rAirLdAtm = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S313>/If Action Subsystem3' */
  }

  /* Outputs for atomic SubSystem: '<S260>/F04_First_Order_Filter' *
   * Block requirements for '<S260>/F04_First_Order_Filter':
   *  1. SubSystem "F04_First_Order_Filter" !Trace_To : VEMS_R_11_00998_301.01 ;
   */

  /* DataTypeConversion: '<S316>/Data Type Conversion1' */
  localDataTypeConversion1_f = EngMGslT_B.TmpSignalConversionAtExt_nEng_b;

  /* DataTypeConversion: '<S318>/OutDTConv' incorporates:
   *  Constant: '<S318>/offset'
   *  Constant: '<S318>/one_on_slope'
   *  Product: '<S318>/Product4'
   *  Sum: '<S318>/Add1'
   */
  localSignalConversion9 = 65536.0F * localEngM_rAirLdAtm;
  if (localSignalConversion9 < 4.294967296E+009F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_l1 = (UInt32)localSignalConversion9;
    } else {
      localOutDTConv_l1 = 0U;
    }
  } else {
    localOutDTConv_l1 = MAX_uint32_T;
  }

  /* Lookup2D: '<S316>/Look-Up Table (2-D)'
   * About '<S316>/Look-Up Table (2-D)':
   * Input0  Data Type:  Fixed Point    U32  2^-16
   * Input1  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U8  2^-7  FSlope 1.28
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_U8_U32_U16( &(EngM_facLfpPresAtmBoost_MP),
                    (&(EngM_facLfpPresAtmBoost_M[0])), localOutDTConv_l1,
                    (&(EngM_rPresX_A[0])), 10U, localDataTypeConversion1_f,
                    (&(EngM_nEng_LfpPresAtmY_A[0])), 7U);

  /* DataTypeDuplicate Block: '<S316>/Data Type Duplicate2'
   *
   * Regarding '<S316>/Data Type Duplicate2':
   *   Unused code path elimination
   */

  /* DataTypeConversion: '<S283>/SignalConversion2' */
  localEngM_rAirLdAtm = ((Float32)EngM_facLfpPresAtmBoost_MP) *
    9.999999776E-003F;

  /* Saturate: '<S322>/Saturation [0-1]' */
  localSignalConversion2_h = rt_SATURATE(localEngM_rAirLdAtm, 0.0F, 1.0F);

  /* DataTypeConversion: '<S283>/SignalConversion1' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtInM_pDsThrPrev1Outport2'
   */
  localEngM_rAirLdAtm = ((Float32)
    Rte_IrvRead_RE_EngMGslT_022_TEV_InM_pDsThrPrev_irv()) * 8.0F;

  /* DataTypeConversion: '<S319>/OutDTConv' incorporates:
   *  Constant: '<S319>/offset'
   *  Constant: '<S319>/one_on_slope'
   *  Product: '<S319>/Product4'
   *  Product: '<S322>/Product'
   *  Sum: '<S319>/Add1'
   *  Sum: '<S322>/Sum'
   *  Sum: '<S322>/Sum1'
   */
  localSignalConversion9 = (((localSignalConversion3_j - localEngM_rAirLdAtm) *
    localSignalConversion2_h) + localEngM_rAirLdAtm) * 0.125F;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_e0 = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_e0 = 0U;
    }
  } else {
    localOutDTConv_e0 = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S260>/F04_First_Order_Filter' */

  /* end of Outputs for SubSystem: '<S15>/F03_Input_Interface_IntkLoaReq' */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EngMGslT_B.TmpSignalConversionAtExt_tCoMes);

  /* Outputs for atomic SubSystem: '<S15>/F02_libEngLdM' *
   * Block requirements for '<S15>/F02_libEngLdM':
   *  1. SubSystem "F02_libEngLdM" !Trace_To : VEMS_R_11_00998_018.02 ;
   */
  EngMGslT_F02_libEngLdM(localSignalConversion6_d, localDataTypeConversion1_i,
    localDataTypeConversion2_j, localDataTypeConversion3_g,
    localSignalConversion19, localDataTypeConversion18_p, localOutDTConv_e0,
    localDataTypeConversion17_a, localTmpSignalConversionAtSi_co,
    localDataTypeConversion5_m, localDataTypeConversion16_o,
    EngMGslT_B.TmpSignalConversionAtExt_tCoMes, localDataTypeConversion11_c,
    localDataTypeConversion12_a, ((UInt8)3U), localDataTypeConversion20_p,
    localDataTypeConversion21_b, localDataTypeConversion22_j,
    localDataTypeConversion8_k, localDataTypeConversion9_n,
    localTmpSignalConversionAtSi_o5, localSignalConversion4_gz,
    localTmpSignalConversionAtSi_ay, &EngMGslT_B.F02_libEngLdM_j);

  /* end of Outputs for SubSystem: '<S15>/F02_libEngLdM' */

  /* DataTypeConversion: '<S15>/SignalConversion3' */
  localEngM_rAirLdAtm = ((Float32)localOutDTConv_e0) * 8.0F;

  /* Outputs for atomic SubSystem: '<S15>/F05_Output_Interface' *
   * Block requirements for '<S15>/F05_Output_Interface':
   *  1. SubSystem "F05_Output_Interface" !Trace_To : VEMS_R_11_00998_059.02 ;
   *  2. SubSystem "F05_Output_Interface" !Trace_To : VEMS_R_11_00998_060.02 ;
   */

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion18Inport1' */
  localSignalConversion2_h = EngMGslT_B.F02_libEngLdM_j.AirEfc_facMassAirScv;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion2Inport1' */
  localSignalConversion3_j = EngMGslT_B.F02_libEngLdM_j.AirEfc_facSlopEfc;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion1Inport1' */
  localSignalConversion5_c = EngMGslT_B.F02_libEngLdM_j.AirEfc_facOfsEfc;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion11Inport1' */
  localSignalConversion9 = EngMGslT_B.F02_libEngLdM_j.AirEfc_facChrExpScvFil;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion9Inport1' */
  localSignalConversion4_f = EngMGslT_B.F02_libEngLdM_j.AirEfc_rVolCylClsInVlv;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion12Inport1' */
  localSignalConversion5_p = EngMGslT_B.F02_libEngLdM_j.AirEfc_facTAirUsInVlv;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion13Inport1' */
  localDivide_mv = EngMGslT_B.F02_libEngLdM_j.AirEfc_facTCo;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion14Inport1' */
  localSignalConversion13 = EngMGslT_B.F02_libEngLdM_j.AirEfc_facCorAtmSlopEfc;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion15Inport1' */
  localTmpSignalConversionAtSi_jc =
    EngMGslT_B.F02_libEngLdM_j.AirEfc_facCorBoostSlopEfc;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion16Inport1' */
  localTmpSignalConversionAtSi_gp =
    EngMGslT_B.F02_libEngLdM_j.AirEfc_pDeltaCorSlopEfc;

  /* SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion17Inport1' */
  localTmpSignalConversionAtSi_bm =
    EngMGslT_B.F02_libEngLdM_j.AirEfc_pBegCorBoostSlopEfc;

  /* end of Outputs for SubSystem: '<S15>/F05_Output_Interface' */

  /* DataTypeConversion: '<S271>/OutDTConv' incorporates:
   *  Constant: '<S271>/offset'
   *  Constant: '<S271>/one_on_slope'
   *  Product: '<S271>/Product4'
   *  SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion10Inport1'
   *  Sum: '<S271>/Add1'
   */
  localtmp = 65536.0F * EngMGslT_B.F02_libEngLdM_j.AirEfc_facChrExpFil;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_fo = (UInt16)localtmp;
    } else {
      localOutDTConv_fo = 0U;
    }
  } else {
    localOutDTConv_fo = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S244>/autosar_testpoint1' */

  /* S-Function Block: <S244>/autosar_testpoint1 */
  AirEfc_facChrExpFilReq_IRV_MP = localOutDTConv_fo;

  /* DataTypeConversion: '<S269>/OutDTConv' incorporates:
   *  Constant: '<S269>/offset'
   *  Constant: '<S269>/one_on_slope'
   *  Product: '<S269>/Product4'
   *  Sum: '<S269>/Add1'
   */
  localSignalConversion9 *= 65536.0F;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_bq = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_bq = 0U;
    }
  } else {
    localOutDTConv_bq = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S245>/autosar_testpoint1' */

  /* S-Function Block: <S245>/autosar_testpoint1 */
  AirEfc_facChrExpScvFilReq_IRV_MP = localOutDTConv_bq;

  /* DataTypeConversion: '<S270>/OutDTConv' incorporates:
   *  Constant: '<S270>/offset'
   *  Constant: '<S270>/one_on_slope'
   *  Product: '<S270>/Product4'
   *  SignalConversion: '<S261>/TmpSignal ConversionAtSignal Conversion7Inport1'
   *  Sum: '<S270>/Add1'
   */
  localOutDTConv_hi = (UInt16)(0.125F * localEngM_rAirLdAtm);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S246>/autosar_testpoint1' */

  /* S-Function Block: <S246>/autosar_testpoint1 */
  InM_pDsThrPrev_IRV_MP = localOutDTConv_hi;

  /* DataTypeConversion: '<S272>/OutDTConv' incorporates:
   *  Constant: '<S272>/offset'
   *  Constant: '<S272>/one_on_slope'
   *  Product: '<S272>/Product4'
   *  Sum: '<S272>/Add1'
   */
  localSignalConversion9 = 32768.0F * localSignalConversion4_f;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_nx = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_nx = 0U;
    }
  } else {
    localOutDTConv_nx = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S248>/autosar_testpoint1' */

  /* S-Function Block: <S248>/autosar_testpoint1 */
  EngM_rVolCylClsInVlvPrev_IRV_MP = localOutDTConv_nx;

  /* DataTypeConversion: '<S273>/OutDTConv' incorporates:
   *  Constant: '<S273>/offset'
   *  Constant: '<S273>/one_on_slope'
   *  Product: '<S273>/Product4'
   *  Sum: '<S273>/Add1'
   */
  localSignalConversion9 = 32768.0F * localSignalConversion5_p;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_fl = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_fl = 0U;
    }
  } else {
    localOutDTConv_fl = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S249>/autosar_testpoint1' */

  /* S-Function Block: <S249>/autosar_testpoint1 */
  EngM_facTAirUsInVlvPrev_IRV_MP = localOutDTConv_fl;

  /* DataTypeConversion: '<S274>/OutDTConv' incorporates:
   *  Constant: '<S274>/offset'
   *  Constant: '<S274>/one_on_slope'
   *  Product: '<S274>/Product4'
   *  Sum: '<S274>/Add1'
   */
  localSignalConversion9 = 128.0F * localDivide_mv;
  if (localSignalConversion9 < 256.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_j0 = (UInt8)localSignalConversion9;
    } else {
      localOutDTConv_j0 = 0U;
    }
  } else {
    localOutDTConv_j0 = MAX_uint8_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S250>/autosar_testpoint1' */

  /* S-Function Block: <S250>/autosar_testpoint1 */
  EngM_facTCoPrev_IRV_MP = localOutDTConv_j0;

  /* DataTypeConversion: '<S263>/OutDTConv' incorporates:
   *  Constant: '<S263>/offset'
   *  Constant: '<S263>/one_on_slope'
   *  Product: '<S263>/Product4'
   *  Sum: '<S263>/Add1'
   */
  localSignalConversion9 = 32768.0F * localSignalConversion13;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_kc = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_kc = 0U;
    }
  } else {
    localOutDTConv_kc = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S251>/autosar_testpoint1' */

  /* S-Function Block: <S251>/autosar_testpoint1 */
  EngM_facCorAtmSlopEfcPrev_IRV_MP = localOutDTConv_kc;

  /* DataTypeConversion: '<S264>/OutDTConv' incorporates:
   *  Constant: '<S264>/offset'
   *  Constant: '<S264>/one_on_slope'
   *  Product: '<S264>/Product4'
   *  Sum: '<S264>/Add1'
   */
  localSignalConversion9 = 32768.0F * localTmpSignalConversionAtSi_jc;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_p = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_p = 0U;
    }
  } else {
    localOutDTConv_p = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S252>/autosar_testpoint1' */

  /* S-Function Block: <S252>/autosar_testpoint1 */
  EngM_facCorBoostSlopEfcPrev_IRV_MP = localOutDTConv_p;

  /* DataTypeConversion: '<S265>/OutDTConv' incorporates:
   *  Constant: '<S265>/offset'
   *  Constant: '<S265>/one_on_slope'
   *  Product: '<S265>/Product4'
   *  Sum: '<S265>/Add1'
   */
  localSignalConversion9 = 0.125F * localTmpSignalConversionAtSi_gp;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_cb = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_cb = 0U;
    }
  } else {
    localOutDTConv_cb = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S253>/autosar_testpoint1' */

  /* S-Function Block: <S253>/autosar_testpoint1 */
  EngM_pDeltaCorSlopEfcPrev_IRV_MP = localOutDTConv_cb;

  /* DataTypeConversion: '<S266>/OutDTConv' incorporates:
   *  Constant: '<S266>/offset'
   *  Constant: '<S266>/one_on_slope'
   *  Product: '<S266>/Product4'
   *  Sum: '<S266>/Add1'
   */
  localSignalConversion9 = 0.125F * localTmpSignalConversionAtSi_bm;
  if (localSignalConversion9 < 65536.0F) {
    if (localSignalConversion9 >= 0.0F) {
      localOutDTConv_g5 = (UInt16)localSignalConversion9;
    } else {
      localOutDTConv_g5 = 0U;
    }
  } else {
    localOutDTConv_g5 = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S254>/autosar_testpoint1' */

  /* S-Function Block: <S254>/autosar_testpoint1 */
  EngM_pBegCorBoostSlopEfcPrev_IRV_MP = localOutDTConv_g5;

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Byp_Fonction_SC'
   *  Constant: '<S242>/Int_BypC'
   *  Constant: '<S268>/offset'
   *  Constant: '<S268>/one_on_slope'
   *  DataTypeConversion: '<S268>/OutDTConv'
   *  Product: '<S268>/Product4'
   *  Sum: '<S268>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_facMassAirScvReq_j = EngM_facMassAirScvReq_B;
  } else {
    localSignalConversion9 = 65536.0F * localSignalConversion2_h;
    if (localSignalConversion9 < 4.294967296E+009F) {
      if (localSignalConversion9 >= 0.0F) {
        localEngM_facMassAirScvReq_j = (UInt32)localSignalConversion9;
      } else {
        localEngM_facMassAirScvReq_j = 0U;
      }
    } else {
      localEngM_facMassAirScvReq_j = MAX_uint32_T;
    }
  }

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S243>/Byp_Fonction_SC'
   *  Constant: '<S243>/Int_BypC'
   *  Constant: '<S267>/offset'
   *  Constant: '<S267>/one_on_slope'
   *  DataTypeConversion: '<S267>/OutDTConv'
   *  Product: '<S267>/Product4'
   *  Sum: '<S267>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEng_c = EngM_facOfsEfcReq_B;
  } else {
    localSignalConversion9 = 16384.0F * localSignalConversion5_c;
    if (localSignalConversion9 < 65536.0F) {
      if (localSignalConversion9 >= 0.0F) {
        localTmpSignalConversionAtEng_c = (UInt16)localSignalConversion9;
      } else {
        localTmpSignalConversionAtEng_c = 0U;
      }
    } else {
      localTmpSignalConversionAtEng_c = MAX_uint16_T;
    }
  }

  /* Switch: '<S247>/Switch' incorporates:
   *  Constant: '<S247>/Byp_Fonction_SC'
   *  Constant: '<S247>/Int_BypC'
   *  Constant: '<S262>/offset'
   *  Constant: '<S262>/one_on_slope'
   *  DataTypeConversion: '<S262>/OutDTConv'
   *  Product: '<S262>/Product4'
   *  Sum: '<S262>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAirSy = EngM_facSlopEfcReq_B;
  } else {
    localSignalConversion9 = 2.978909184E+009F * localSignalConversion3_j;
    if (localSignalConversion9 < 65536.0F) {
      if (localSignalConversion9 >= 0.0F) {
        localTmpSignalConversionAtAirSy = (UInt16)localSignalConversion9;
      } else {
        localTmpSignalConversionAtAirSy = 0U;
      }
    } else {
      localTmpSignalConversionAtAirSy = MAX_uint16_T;
    }
  }

  /* SignalConversion: '<S15>/SignalConversion' */
  localAirEfc_facChrExpScvFilRe_b = localOutDTConv_bq;

  /* SignalConversion: '<S15>/SignalConversion10' */
  localEngM_pBegCorBoostSlopEfc_l = localOutDTConv_g5;

  /* SignalConversion: '<S15>/SignalConversion2' */
  localInM_pDsThrPrev_irv_f = localOutDTConv_hi;

  /* SignalConversion: '<S15>/SignalConversion4' */
  localEngM_rVolCylClsInVlvPrev_p = localOutDTConv_nx;

  /* SignalConversion: '<S15>/SignalConversion5' */
  localEngM_facTAirUsInVlvPrev__c = localOutDTConv_fl;

  /* SignalConversion: '<S15>/SignalConversion6' */
  localMultiportSwitch_b = localOutDTConv_j0;

  /* SignalConversion: '<S15>/SignalConversion7' */
  localEngM_facCorAtmSlopEfcPre_k = localOutDTConv_kc;

  /* SignalConversion: '<S15>/SignalConversion8' */
  localEngM_facCorBoostSlopEfcP_n = localOutDTConv_p;

  /* SignalConversion: '<S15>/SignalConversion9' */
  localEngM_pDeltaCorSlopEfcPre_j = localOutDTConv_cb;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirEfc_facChrExpFilReqInport2' incorporates:
   *  SignalConversion: '<S15>/SignalConversion1'
   */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_AirEfc_facChrExpFilReq_irv(localOutDTConv_fo);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAirEfc_facChrExpScvFilReqInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_AirEfc_facChrExpScvFilReq_irv
    (localAirEfc_facChrExpScvFilRe_b);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorAtmSlopEfcPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_facCorAtmSlopEfcPrev_irv
    (localEngM_facCorAtmSlopEfcPre_k);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facCorBoostSlopEfcPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_facCorBoostSlopEfcPrev_irv
    (localEngM_facCorBoostSlopEfcP_n);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facMassAirScvReqInport2' */
  Rte_Write_P_EngM_facMassAirScvReq_EngM_facMassAirScvReq
    (localEngM_facMassAirScvReq_j);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facOfsEfcReqInport2' */
  Rte_Write_P_EngM_facOfsEfcReq_EngM_facOfsEfcReq
    (localTmpSignalConversionAtEng_c);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facSlopEfcReqInport2' */
  Rte_Write_P_EngM_facSlopEfcReq_EngM_facSlopEfcReq
    (localTmpSignalConversionAtAirSy);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facTAirUsInVlvPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_facTAirUsInVlvPrev_irv
    (localEngM_facTAirUsInVlvPrev__c);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_facTCoPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_facTCoPrev_irv(localMultiportSwitch_b);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_pBegCorBoostSlopEfcPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_pBegCorBoostSlopEfcPrev_irv
    (localEngM_pBegCorBoostSlopEfc_l);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_pDeltaCorSlopEfcPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_pDeltaCorSlopEfcPrev_irv
    (localEngM_pDeltaCorSlopEfcPre_j);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtEngM_rVolCylClsInVlvPrev_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_EngM_rVolCylClsInVlvPrev_irv
    (localEngM_rVolCylClsInVlvPrev_p);

  /* SignalConversion: '<S15>/TmpSignal ConversionAtInM_pDsThrPrevInport2' */
  Rte_IrvWrite_RE_EngMGslT_022_TEV_InM_pDsThrPrev_irv(localInM_pDsThrPrev_irv_f);
}

/* Output and update for exported function: RE_EngMGslT_004_TEV */
void RE_EngMGslT_004_TEV(void)
{
  Float32 localSignalConversion4_ik;
  UInt16 localTmpSignalConversionAtEn_m3;
  UInt16 localTmpSignalConversionAtEngMT;
  UInt32 localEngM_mAirEngCylMax_j;
  UInt32 localEngM_mAirEngCylMin_e;
  UInt32 localEngM_mAirEngCylTrbMax_p;
  UInt32 localEngM_mAirPresUsThr_l;

  /* S-Function (fcncallgen): '<S10>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_engLdToMass'
   *
   * Block requirements for '<S1>/F01_engLdToMass':
   *  1. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_084.01 ;
   *  2. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_085.01 ;
   *  3. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_105.01 ;
   *  4. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_106.01 ;
   *  5. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_107.01 ;
   *  6. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_108.01 ;
   *  7. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_283.01 ;
   *  8. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_270.02 ;
   *  9. SubSystem "F01_engLdToMass" !Trace_To : VEMS_R_11_00998_214.01 ;
   */

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_rMaxTotLdOutport2' incorporates:
   *  Inport: '<Root>/EngM_rMaxTotLd_INPUT'
   */
  Rte_Read_R_EngM_rMaxTotLd_EngM_rMaxTotLd(&localTmpSignalConversionAtEn_m3);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngMTrb_rLdMaxOvbAcvOutport2' incorporates:
   *  Inport: '<Root>/EngMTrb_rLdMaxOvbAcv'
   */
  Rte_Read_R_EngMTrb_rLdMaxOvbAcv_EngMTrb_rLdMaxOvbAcv
    (&localTmpSignalConversionAtEngMT);

  /* DataTypeConversion: '<S19>/SignalConversion4' incorporates:
   *  Constant: '<S19>/Eng_mRef_C'
   */
  localSignalConversion4_ik = ((Float32)Eng_mRef_C) * 1.192016583E-007F;

  /* Switch: '<S412>/Switch' incorporates:
   *  Constant: '<S412>/Byp_Fonction_SC'
   *  Constant: '<S412>/Int_BypC'
   *  Constant: '<S418>/offset'
   *  Constant: '<S418>/one_on_slope'
   *  DataTypeConversion: '<S19>/SignalConversion1'
   *  DataTypeConversion: '<S418>/OutDTConv'
   *  Product: '<S418>/Product4'
   *  Product: '<S423>/Divide'
   *  Sum: '<S418>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mAirEngCylMax_j = EngM_mAirEngCylMax_B;
  } else {
    localEngM_mAirEngCylMax_j = (UInt32)(((((Float32)
      localTmpSignalConversionAtEn_m3) * 6.103515625E-005F) *
      localSignalConversion4_ik) * 1.6777216E+007F);
  }

  /* Switch: '<S413>/Switch' incorporates:
   *  Constant: '<S413>/Byp_Fonction_SC'
   *  Constant: '<S413>/Int_BypC'
   *  Constant: '<S420>/offset'
   *  Constant: '<S420>/one_on_slope'
   *  DataTypeConversion: '<S19>/SignalConversion3'
   *  DataTypeConversion: '<S420>/OutDTConv'
   *  Product: '<S420>/Product4'
   *  Product: '<S425>/Divide'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtEngM_rMinTotLd_irvOutport2'
   *  Sum: '<S420>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mAirEngCylMin_e = EngM_mAirEngCylMin_B;
  } else {
    localEngM_mAirEngCylMin_e = (UInt32)(((((Float32)
      Rte_IrvRead_RE_EngMGslT_004_TEV_EngM_rMinTotLd_irv()) * 6.103515625E-005F)
      * localSignalConversion4_ik) * 1.6777216E+007F);
  }

  /* Switch: '<S414>/Switch' incorporates:
   *  Constant: '<S414>/Byp_Fonction_SC'
   *  Constant: '<S414>/Int_BypC'
   *  Constant: '<S419>/offset'
   *  Constant: '<S419>/one_on_slope'
   *  DataTypeConversion: '<S19>/SignalConversion'
   *  DataTypeConversion: '<S419>/OutDTConv'
   *  Product: '<S419>/Product4'
   *  Product: '<S424>/Divide'
   *  Sum: '<S419>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mAirEngCylTrbMax_p = EngM_mAirEngCylTrbMax_B;
  } else {
    localEngM_mAirEngCylTrbMax_p = (UInt32)(((((Float32)
      localTmpSignalConversionAtEngMT) * 6.103515625E-005F) *
      localSignalConversion4_ik) * 1.6777216E+007F);
  }

  /* Switch: '<S415>/Switch' incorporates:
   *  Constant: '<S415>/Byp_Fonction_SC'
   *  Constant: '<S415>/Int_BypC'
   *  Constant: '<S421>/offset'
   *  Constant: '<S421>/one_on_slope'
   *  DataTypeConversion: '<S19>/SignalConversion2'
   *  DataTypeConversion: '<S421>/OutDTConv'
   *  Product: '<S421>/Product4'
   *  Product: '<S422>/Divide'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtEngM_rMaxAvlLd_irvOutport2'
   *  Sum: '<S421>/Add1'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localEngM_mAirPresUsThr_l = EngM_mAirPresUsThr_B;
  } else {
    localEngM_mAirPresUsThr_l = (UInt32)(((((Float32)
      Rte_IrvRead_RE_EngMGslT_004_TEV_EngM_rMaxAvlLd_irv()) * 6.103515625E-005F)
      * localSignalConversion4_ik) * 1.6777216E+007F);
  }

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_mAirEngCylMaxInport2' */
  Rte_Write_P_EngM_mAirEngCylMax_EngM_mAirEngCylMax(localEngM_mAirEngCylMax_j);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_mAirEngCylMinInport2' */
  Rte_Write_P_EngM_mAirEngCylMin_EngM_mAirEngCylMin(localEngM_mAirEngCylMin_e);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_mAirEngCylTrbMaxInport2' */
  Rte_Write_P_EngM_mAirEngCylTrbMax_EngM_mAirEngCylTrbMax
    (localEngM_mAirEngCylTrbMax_p);

  /* SignalConversion: '<S19>/TmpSignal ConversionAtEngM_mAirPresUsThrInport2' */
  Rte_Write_P_EngM_mAirPresUsThr_EngM_mAirPresUsThr(localEngM_mAirPresUsThr_l);
}

/*
 * Output and update for action system:
 *    '<S449>/If Action Subsystem'
 *    '<S449>/If Action Subsystem3'
 */
void EngMGslT_IfActionSubsystem(UInt16 rtu_0, UInt16 *rty_Out1)
{
  /* Inport: '<S461>/In1' */
  (*rty_Out1) = rtu_0;
}

/* Start for exported function: RE_EngMGslT_024_TEV */
void RE_EngMGslT_024_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_engLoaMax'
   *
   * Block requirements for '<S1>/F01_engLoaMax':
   *  1. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_063.01 ;
   *  2. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_064.01 ;
   *  3. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  4. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  5. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_201.01 ;
   *  6. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_202.01 ;
   *  7. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_204.01 ;
   *  8. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_205.01 ;
   *  9. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_206.01 ;
   *  10. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_207.01 ;
   *  11. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_208.01 ;
   *  12. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_262.01 ;
   *  13. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_263.01 ;
   *  14. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_264.01 ;
   *  15. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_246.02 ;
   *  16. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_284.01 ;
   *  17. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_286.01 ;
   *  18. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_287.01 ;
   *  19. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_276.02 ;
   *  20. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_183.01 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_024_TEV */
void RE_EngMGslT_024_TEV(void)
{
  /* local block i/o variables */
  UInt16 localOutDTConv_f5;
  UInt16 localTmpSignalConversionAtMPM_r;
  UInt16 localMerge81_m;
  UInt16 localMerge1_d;
  UInt16 localLookUpTable_d;
  UInt16 localTmpSignalConversionAtUsT_k;
  Boolean localAutosarServer;
  Boolean localAutosarServer_e;
  Float32 localSignalConversion11;
  Boolean localNot;
  Boolean localNot_m;
  Float32 localDivide_fn;
  Float32 localPrelookup_o2;
  Float32 localPrelookup_o2_h;
  SInt32 localPrelookup_o1;
  SInt32 localPrelookup_o1_n;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  SInt32 localbpIndex[2];
  UInt16 localTmpSignalConversionAtUsThr;
  UInt8 localTmpSignalConversionAtEn_mt;
  UInt16 localTmpSignalConversionAtEn_fx;
  UInt16 localTmpSignalConversionAtEn_nb;
  UInt16 localTmpSignalConversionAtIn_kj;
  UInt16 localTmpSignalConversionAtEn_fa;
  UInt16 localTmpSignalConversionAtTPM_r;
  Float32 localtmp;
  UInt16 locallocalTmpSignalConversionAt;

  /* S-Function (fcncallgen): '<S11>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_engLoaMax'
   *
   * Block requirements for '<S1>/F01_engLoaMax':
   *  1. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_063.01 ;
   *  2. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_064.01 ;
   *  3. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  4. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  5. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_201.01 ;
   *  6. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_202.01 ;
   *  7. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_204.01 ;
   *  8. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_205.01 ;
   *  9. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_206.01 ;
   *  10. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_207.01 ;
   *  11. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_208.01 ;
   *  12. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_262.01 ;
   *  13. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_263.01 ;
   *  14. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_264.01 ;
   *  15. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_246.02 ;
   *  16. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_284.01 ;
   *  17. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_286.01 ;
   *  18. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_287.01 ;
   *  19. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_276.02 ;
   *  20. SubSystem "F01_engLoaMax" !Trace_To : VEMS_R_11_00998_183.01 ;
   */

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&localTmpSignalConversionAtUsThr);

  /* DataTypeConversion: '<S20>/SignalConversion11' */
  localSignalConversion11 = ((Float32)localTmpSignalConversionAtUsThr) * 8.0F;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_facACorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facACor_INPUT'
   */
  Rte_Read_R_EngM_facACor_EngM_facACor(&localTmpSignalConversionAtEn_mt);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&EngMGslT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_facOfsEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (&localTmpSignalConversionAtEn_fx);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&localTmpSignalConversionAtEn_nb);

  /* S-Function (sfun_autosar_clientop): '<S431>/AutosarServer' */
  Rte_Call_R_FRM_bAcvLimThrPresDelta_GetFunctionPermission(&localAutosarServer);

  /* Logic: '<S431>/Not' */
  localNot = !localAutosarServer;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtExt_bAcvGasModOutport2' incorporates:
   *  Inport: '<Root>/Ext_bAcvGasMod'
   */
  Rte_Read_R_Ext_bAcvGasMod_Ext_bAcvGasMod
    (&EngMGslT_B.TmpSignalConversionAtExt_bAcvGa);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor(&localTmpSignalConversionAtIn_kj);

  /* Outputs for atomic SubSystem: '<S20>/F01_remplissage_max_realisable' *
   * Block requirements for '<S20>/F01_remplissage_max_realisable':
   *  1. SubSystem "F01_remplissage_max_realisable" !Trace_To : VEMS_R_11_00998_065.01 ;
   */

  /* Switch: '<S428>/Switch2' incorporates:
   *  Constant: '<S428>/EngM_rPresLostThrPosnInfo_C'
   *  DataTypeConversion: '<S428>/Data Type Conversion'
   *  Product: '<S442>/Divide'
   */
  if (localNot) {
    localSignalConversion11 *= ((Float32)EngM_rPresLostThrPosnInfo_C) *
      0.00390625F;
  }

  /* DataTypeConversion: '<S438>/OutDTConv' incorporates:
   *  Constant: '<S438>/offset'
   *  Constant: '<S438>/one_on_slope'
   *  Product: '<S438>/Product4'
   *  Sum: '<S438>/Add1'
   */
  localtmp = 0.125F * localSignalConversion11;
  if (localtmp < 65536.0F) {
    locallocalTmpSignalConversionAt = (UInt16)localtmp;
  } else {
    locallocalTmpSignalConversionAt = MAX_uint16_T;
  }

  /* PreLookup: '<S436>/Prelookup' */
  localPrelookup_o1 = plook_s32u16f_bincpa(locallocalTmpSignalConversionAt,
    (&(Air_pAir_A[0])), 15U, &localPrelookup_o2,
    &EngMGslT_DWork.Prelookup_DWORK1_o);

  /* PreLookup: '<S435>/Prelookup' */
  localPrelookup_o1_n = plook_s32u16f_bincpa
    (EngMGslT_B.TmpSignalConversionAtExt_nEngOu, (&(Ext_nEng_A[0])), 15U,
     &localPrelookup_o2_h, &EngMGslT_DWork.Prelookup_DWORK1_i);

  /* If: '<S428>/If' incorporates:
   *  ActionPort: '<S433>/Action Port'
   *  ActionPort: '<S434>/Action Port'
   *  SubSystem: '<S428>/If Action Subsystem'
   *  SubSystem: '<S428>/If Action Subsystem1'
   */
  if (EngMGslT_B.TmpSignalConversionAtExt_bAcvGa) {
    /* Interpolation_n-D: '<S445>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_h;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localPrelookup_o1;
    localbpIndex[1] = localPrelookup_o1_n;
    localfractionTmp_0d = intrp2d_is16n11ff_s32f_la_ns(localbpIndex, localfrac,
      (&(EngM_facDGas_M[0])), 16U, &EngMGslT_ConstP.pooled22[0]);
  } else {
    /* Interpolation_n-D: '<S446>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_h;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localPrelookup_o1;
    localbpIndex[1] = localPrelookup_o1_n;
    localfractionTmp_0d = intrp2d_is16n11ff_s32f_la_ns(localbpIndex, localfrac,
      (&(EngM_facD_M[0])), 16U, &EngMGslT_ConstP.pooled22[0]);
  }

  /* DataStoreWrite: '<S428>/MemoryStore1' incorporates:
   *  Constant: '<S440>/offset'
   *  Constant: '<S440>/one_on_slope'
   *  DataTypeConversion: '<S440>/OutDTConv'
   *  Product: '<S440>/Product4'
   *  Sum: '<S440>/Add1'
   */
  localtmp = 2048.0F * localfractionTmp_0d;
  if (localtmp < 128.0F) {
    if (localtmp >= -128.0F) {
      EngM_facD_MP = (SInt8)localtmp;
    } else {
      EngM_facD_MP = MIN_int8_T;
    }
  } else {
    EngM_facD_MP = MAX_int8_T;
  }

  /* Product: '<S443>/Divide' incorporates:
   *  DataTypeConversion: '<S20>/SignalConversion15'
   */
  localSignalConversion11 *= ((Float32)localTmpSignalConversionAtEn_nb) *
    3.356933620E-010F;

  /* Sum: '<S428>/Sum' incorporates:
   *  DataTypeConversion: '<S20>/SignalConversion14'
   */
  localfractionTmp_0d += localSignalConversion11 - (((Float32)
    localTmpSignalConversionAtEn_fx) * 6.103515625E-005F);

  /* DataStoreWrite: '<S428>/MemoryStore3' incorporates:
   *  Constant: '<S439>/offset'
   *  Constant: '<S439>/one_on_slope'
   *  DataTypeConversion: '<S439>/OutDTConv'
   *  Product: '<S439>/Product4'
   *  Sum: '<S439>/Add1'
   */
  localtmp = 16384.0F * localfractionTmp_0d;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      EngM_facRLdMax_MP = (UInt16)localtmp;
    } else {
      EngM_facRLdMax_MP = 0U;
    }
  } else {
    EngM_facRLdMax_MP = MAX_uint16_T;
  }

  /* DataStoreWrite: '<S428>/MemoryStore5' incorporates:
   *  Constant: '<S437>/offset'
   *  Constant: '<S437>/one_on_slope'
   *  DataTypeConversion: '<S437>/OutDTConv'
   *  Product: '<S437>/Product4'
   *  Sum: '<S437>/Add1'
   */
  localtmp = 16384.0F * localSignalConversion11;
  if (localtmp < 65536.0F) {
    EngM_facUsThr_MP = (UInt16)localtmp;
  } else {
    EngM_facUsThr_MP = MAX_uint16_T;
  }

  /* end of Outputs for SubSystem: '<S20>/F01_remplissage_max_realisable' */

  /* DataTypeConversion: '<S432>/OutDTConv' incorporates:
   *  Constant: '<S432>/offset'
   *  Constant: '<S432>/one_on_slope'
   *  DataTypeConversion: '<S20>/SignalConversion13'
   *  DataTypeConversion: '<S20>/SignalConversion7'
   *  Product: '<S432>/Product4'
   *  Product: '<S441>/Divide'
   *  Product: '<S444>/Divide'
   *  Sum: '<S432>/Add1'
   */
  localtmp = ((((((Float32)localTmpSignalConversionAtEn_mt) * 0.00390625F) +
                0.5F) * localfractionTmp_0d) * ((((Float32)
    localTmpSignalConversionAtIn_kj) * 1.525878906E-005F) + 1.525878906E-005F)) *
    16384.0F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_f5 = (UInt16)localtmp;
    } else {
      localOutDTConv_f5 = 0U;
    }
  } else {
    localOutDTConv_f5 = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S427>/autosar_testpoint1' */

  /* S-Function Block: <S427>/autosar_testpoint1 */
  EngM_rMaxAvlLd_IRV_MP = localOutDTConv_f5;

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&EngMGslT_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtUsThrM_tThrMesOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_tThrMes'
   */
  Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&localTmpSignalConversionAtUsT_k);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtTPM_rLdProtExThermoOutport2' incorporates:
   *  Inport: '<Root>/TPM_rLdProtExThermo'
   */
  Rte_Read_R_TPM_rLdProtExThermo_TPM_rLdProtExThermo
    (&localTmpSignalConversionAtTPM_r);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtMPM_rLdMaxOutport2' incorporates:
   *  Inport: '<Root>/MPM_rLdMax'
   */
  Rte_Read_R_MPM_rLdMax_MPM_rLdMax(&localTmpSignalConversionAtMPM_r);

  /* Outputs for enable SubSystem: '<S20>/F02_remplissage_max_apres_limitations' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Ext_bAcvTrbMod_C'
   *  EnablePort: '<S429>/Enable'
   *  RelationalOperator: '<S20>/Relational Operator2'
   *
   * Block requirements for '<S20>/F02_remplissage_max_apres_limitations':
   *  1. SubSystem "F02_remplissage_max_apres_limitations" !Trace_To : VEMS_R_11_00998_066.01 ;
   */
  if (!Ext_bAcvTrbMod_C) {
    /* S-Function (sfun_autosar_clientop): '<S453>/AutosarServer' */
    Rte_Call_R_FRM_bLimRich_GetFunctionPermission(&localAutosarServer_e);

    /* Logic: '<S453>/Not' */
    localNot_m = !localAutosarServer_e;

    /* Product: '<S457>/Divide' incorporates:
     *  Constant: '<S429>/Air_pUsThrRef_C'
     *  DataTypeConversion: '<S429>/SignalConversion10'
     *  DataTypeConversion: '<S429>/SignalConversion6'
     */
    localfractionTmp_0d = (((Float32)EngMGslT_B.TmpSignalConversionAtUsThrM_pAi)
      * 8.0F) / (((Float32)Air_pUsThrRef_C) * 8.0F);

    /* Outputs for atomic SubSystem: '<S457>/If Action Subsystem3' */

    /* Switch: '<S473>/Switch1' incorporates:
     *  Constant: '<S473>/Constant1'
     *  Constant: '<S473>/Constant2'
     *  Constant: '<S473>/Constant3'
     *  Logic: '<S473>/Logical Operator1'
     *  RelationalOperator: '<S473>/Relational Operator'
     *  RelationalOperator: '<S473>/Relational Operator1'
     *  RelationalOperator: '<S473>/Relational Operator3'
     */
    if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
          3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
      localfractionTmp_0d = 0.0F;
    }

    /* end of Outputs for SubSystem: '<S457>/If Action Subsystem3' */

    /* Lookup: '<S447>/Look-Up Table'
     * About '<S447>/Look-Up Table':
     * Input0  Data Type:  Fixed Point    U16  2^-7  Bias 223.0
     * Output0 Data Type:  Fixed Point    U16  2^-15
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_U16_U16( &(localLookUpTable_d), (&(EngM_facCorT_T[0])),
                   localTmpSignalConversionAtUsT_k, (&(Ext_tAirRef1_A[0])), 7U);

    /* DataTypeDuplicate Block: '<S447>/Data Type Duplicate1'
     *
     * Regarding '<S447>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* Product: '<S458>/Divide' incorporates:
     *  DataTypeConversion: '<S429>/SignalConversion2'
     *  Lookup: '<S447>/Look-Up Table'
     */
    localDivide_fn = (((Float32)localLookUpTable_d) * 3.051757813E-005F) *
      localfractionTmp_0d;

    /* If: '<S429>/If2' incorporates:
     *  ActionPort: '<S448>/Action Port'
     *  ActionPort: '<S449>/Action Port'
     *  SubSystem: '<S429>/If Action Subsystem4'
     *  SubSystem: '<S429>/If Action Subsystem5'
     */
    if (localNot_m) {
      /* Interpolation_n-D: '<S460>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localPrelookup_o2_h;
      localSignalConversion11 = intrp1d_if_s32f_la(localPrelookup_o1_n,
        localfractionTmp_0d, &EngMGslT_ConstP.InterpolationUsingPr[0], 15U);
    } else {
      /* If: '<S449>/If' incorporates:
       *  ActionPort: '<S461>/Action Port'
       *  ActionPort: '<S462>/Action Port'
       *  Constant: '<S449>/EngM_bAcvMPMMod_C'
       *  SubSystem: '<S449>/If Action Subsystem'
       *  SubSystem: '<S449>/If Action Subsystem1'
       */
      if (EngM_bAcvMPMMod_C) {
        EngMGslT_IfActionSubsystem(localTmpSignalConversionAtMPM_r,
          &localMerge81_m);
      } else {
        /* Interpolation_n-D: '<S465>/Interpolation Using Prelookup3' */
        localfractionTmp_0d = localPrelookup_o2_h;
        localfractionTmp_0d = intrp1d_if_s32f_la(localPrelookup_o1_n,
          localfractionTmp_0d, &EngMGslT_ConstP.InterpolationUsing_a[0], 15U);

        /* DataTypeConversion: '<S466>/OutDTConv' incorporates:
         *  Constant: '<S466>/offset'
         *  Constant: '<S466>/one_on_slope'
         *  Product: '<S466>/Product4'
         *  Sum: '<S466>/Add1'
         */
        localtmp = 16384.0F * localfractionTmp_0d;
        if (localtmp < 65536.0F) {
          if (localtmp >= 0.0F) {
            localMerge81_m = (UInt16)localtmp;
          } else {
            localMerge81_m = 0U;
          }
        } else {
          localMerge81_m = MAX_uint16_T;
        }
      }

      /* If: '<S449>/If1' incorporates:
       *  ActionPort: '<S463>/Action Port'
       *  ActionPort: '<S464>/Action Port'
       *  Constant: '<S449>/EngM_bSelMaxLdClcMod_C'
       *  SubSystem: '<S449>/If Action Subsystem2'
       *  SubSystem: '<S449>/If Action Subsystem3'
       */
      if (EngM_bSelMaxLdClcMod_C) {
        /* Product: '<S468>/Divide' incorporates:
         *  DataTypeConversion: '<S468>/Data Type Conversion'
         */
        localfractionTmp_0d = (((Float32)localOutDTConv_f5) * 6.103515625E-005F)
          / localDivide_fn;

        /* Outputs for atomic SubSystem: '<S468>/If Action Subsystem3' */

        /* Switch: '<S470>/Switch1' incorporates:
         *  Constant: '<S470>/Constant1'
         *  Constant: '<S470>/Constant2'
         *  Constant: '<S470>/Constant3'
         *  Logic: '<S470>/Logical Operator1'
         *  RelationalOperator: '<S470>/Relational Operator'
         *  RelationalOperator: '<S470>/Relational Operator1'
         *  RelationalOperator: '<S470>/Relational Operator3'
         */
        if (((localfractionTmp_0d != localfractionTmp_0d) ||
             (localfractionTmp_0d > 3.000000005E+038F)) || (-3.000000005E+038F >
             localfractionTmp_0d)) {
          localfractionTmp_0d = 0.0F;
        }

        /* end of Outputs for SubSystem: '<S468>/If Action Subsystem3' */

        /* MinMax: '<S463>/MinMax2' incorporates:
         *  Constant: '<S467>/offset'
         *  Constant: '<S467>/one_on_slope'
         *  DataTypeConversion: '<S467>/OutDTConv'
         *  Product: '<S467>/Product4'
         *  Sum: '<S467>/Add1'
         */
        localtmp = 16384.0F * localfractionTmp_0d;
        if (localtmp < 65536.0F) {
          if (localtmp >= 0.0F) {
            locallocalTmpSignalConversionAt = (UInt16)localtmp;
          } else {
            locallocalTmpSignalConversionAt = 0U;
          }
        } else {
          locallocalTmpSignalConversionAt = MAX_uint16_T;
        }

        if (localMerge81_m < locallocalTmpSignalConversionAt) {
          locallocalTmpSignalConversionAt = localMerge81_m;
        }

        localMerge1_d = locallocalTmpSignalConversionAt;
      } else {
        EngMGslT_IfActionSubsystem(localMerge81_m, &localMerge1_d);
      }

      /* Switch: '<S449>/Switch4' incorporates:
       *  Constant: '<S449>/Constant2'
       *  Constant: '<S449>/EngM_bAcvTPMMod_C'
       */
      if (!EngM_bAcvTPMMod_C) {
        localTmpSignalConversionAtTPM_r = MAX_uint16_T;
      }

      /* MinMax: '<S449>/MinMax4' */
      locallocalTmpSignalConversionAt = localMerge1_d;
      if (localTmpSignalConversionAtTPM_r < localMerge1_d) {
        locallocalTmpSignalConversionAt = localTmpSignalConversionAtTPM_r;
      }

      localSignalConversion11 = ((Float32)locallocalTmpSignalConversionAt) *
        6.103515625E-005F;
    }

    /* DataStoreWrite: '<S429>/MemoryStore1' incorporates:
     *  Constant: '<S454>/offset'
     *  Constant: '<S454>/one_on_slope'
     *  DataTypeConversion: '<S454>/OutDTConv'
     *  Product: '<S454>/Product4'
     *  Sum: '<S454>/Add1'
     */
    localtmp = 16384.0F * localSignalConversion11;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        EngM_rLdBas_MP = (UInt16)localtmp;
      } else {
        EngM_rLdBas_MP = 0U;
      }
    } else {
      EngM_rLdBas_MP = MAX_uint16_T;
    }

    /* S-Function (sfun_autosar_clientop): '<S452>/AutosarServer' */
    Rte_Call_R_FRM_bAcvLimLd_GetFunctionPermission(&localAutosarServer_e);

    /* If: '<S429>/If3' incorporates:
     *  ActionPort: '<S450>/Action Port'
     *  ActionPort: '<S451>/Action Port'
     *  Logic: '<S452>/Not'
     *  SubSystem: '<S429>/If Action Subsystem6'
     *  SubSystem: '<S429>/If Action Subsystem7'
     */
    if (!localAutosarServer_e) {
      /* Interpolation_n-D: '<S471>/Interpolation Using Prelookup3' */
      localfractionTmp_0d = localPrelookup_o2_h;
      localfractionTmp_0d = intrp1d_if_s32f_la(localPrelookup_o1_n,
        localfractionTmp_0d, &EngMGslT_ConstP.InterpolationUsing_l[0], 15U);

      /* MinMax: '<S450>/MinMax1' */
      localSignalConversion11 = rt_MINf(localfractionTmp_0d,
        localSignalConversion11);
    }

    /* DataStoreWrite: '<S429>/MemoryStore3' incorporates:
     *  Constant: '<S456>/offset'
     *  Constant: '<S456>/one_on_slope'
     *  DataTypeConversion: '<S456>/OutDTConv'
     *  Product: '<S456>/Product4'
     *  Sum: '<S456>/Add1'
     */
    localtmp = 16384.0F * localSignalConversion11;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        EngM_rLdMaxBas_MP = (UInt16)localtmp;
      } else {
        EngM_rLdMaxBas_MP = 0U;
      }
    } else {
      EngM_rLdMaxBas_MP = MAX_uint16_T;
    }

    /* DataTypeConversion: '<S455>/OutDTConv' incorporates:
     *  Constant: '<S455>/offset'
     *  Constant: '<S455>/one_on_slope'
     *  Product: '<S455>/Product4'
     *  Product: '<S459>/Divide'
     *  Sum: '<S455>/Add1'
     */
    localtmp = (localSignalConversion11 * localDivide_fn) * 16384.0F;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        EngM_rMaxLimLd = (UInt16)localtmp;
      } else {
        EngM_rMaxLimLd = 0U;
      }
    } else {
      EngM_rMaxLimLd = MAX_uint16_T;
    }
  }

  /* end of Outputs for SubSystem: '<S20>/F02_remplissage_max_apres_limitations' */

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngMTrb_rLdMaxOutport2' incorporates:
   *  Inport: '<Root>/EngMTrb_rLdMax'
   */
  Rte_Read_R_EngMTrb_rLdMax_EngMTrb_rLdMax(&localTmpSignalConversionAtEn_fa);

  /* Outputs for atomic SubSystem: '<S20>/F03_Coordination_des_limitations_de_charge' *
   * Block requirements for '<S20>/F03_Coordination_des_limitations_de_charge':
   *  1. SubSystem "F03_Coordination_des_limitations_de_charge" !Trace_To : VEMS_R_11_00998_067.01 ;
   */

  /* If: '<S430>/If' incorporates:
   *  ActionPort: '<S474>/Action Port'
   *  ActionPort: '<S475>/Action Port'
   *  Constant: '<S430>/Ext_bAcvTrbMod_C'
   *  SubSystem: '<S430>/If Action Subsystem'
   *  SubSystem: '<S430>/If Action Subsystem1'
   */
  if (!Ext_bAcvTrbMod_C) {
    /* Switch: '<S475>/Switch5' */
    if (localNot) {
      localTmpSignalConversionAtUsThr = localOutDTConv_f5;
    } else {
      localTmpSignalConversionAtUsThr = EngM_rMaxLimLd;
    }

    /* MinMax: '<S475>/MinMax' incorporates:
     *  Constant: '<S475>/Air_rLdMin_C'
     */
    locallocalTmpSignalConversionAt = Air_rLdMin_C;
    if (localTmpSignalConversionAtUsThr > Air_rLdMin_C) {
      locallocalTmpSignalConversionAt = localTmpSignalConversionAtUsThr;
    }

    localTmpSignalConversionAtEn_fa = locallocalTmpSignalConversionAt;
  }

  /* end of Outputs for SubSystem: '<S20>/F03_Coordination_des_limitations_de_charge' */

  /* Switch: '<S426>/Switch' incorporates:
   *  Constant: '<S426>/Byp_Fonction_SC'
   *  Constant: '<S426>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_fa = EngM_rMaxTotLd_B;
  }

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_rMaxAvlLd_irvInport2' incorporates:
   *  SignalConversion: '<S20>/SignalConversion4'
   */
  Rte_IrvWrite_RE_EngMGslT_024_TEV_EngM_rMaxAvlLd_irv(localOutDTConv_f5);

  /* SignalConversion: '<S20>/TmpSignal ConversionAtEngM_rMaxTotLdInport2' */
  Rte_Write_P_EngM_rMaxTotLd_EngM_rMaxTotLd(localTmpSignalConversionAtEn_fa);
}

/* Start for exported function: RE_EngMGslT_026_TEV */
void RE_EngMGslT_026_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_engLoaMin'
   *
   * Block requirements for '<S1>/F01_engLoaMin':
   *  1. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_068.01 ;
   *  2. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_069.01 ;
   *  3. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  4. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  5. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_208.01 ;
   *  6. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_210.02 ;
   *  7. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_202.01 ;
   *  8. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_247.02 ;
   *  9. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_286.01 ;
   *  10. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_287.01 ;
   *  11. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_277.02 ;
   *  12. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  13. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_209.01 ;
   *  14. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_211.01 ;
   *  15. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_212.01 ;
   */
}

/* Output and update for exported function: RE_EngMGslT_026_TEV */
void RE_EngMGslT_026_TEV(void)
{
  /* local block i/o variables */
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localOutDTConv_gv;
  UInt16 localLookUpTable_d1;
  UInt16 localLookUpTable_h;
  UInt16 localOutDTConv_ay;
  UInt16 localLookUpTable_k;
  UInt16 localSignalConversion4_j;
  Boolean localTmpSignalConversionAtInj_e[6];
  Float32 localProduct4_nz;
  Boolean localTmpSignalConversionAtEx_nm;
  Float32 localPrelookup_o2_m;
  Float32 localPrelookup_o2_k;
  SInt32 localPrelookup_o1_d;
  SInt32 localPrelookup_o1_pg;
  Float32 localfractionTmp_0d;
  Float32 localfrac[2];
  SInt32 localbpIndex[2];
  Float32 localPrelookup_o2_e;
  Float32 localfrac_0[2];
  SInt32 localbpIndex_0[2];
  Boolean localLowerRelop1;
  Boolean localTmpSignalConversionAtInj_p;
  SInt16 localTmpSignalConversionAtExt_c;
  UInt16 localTmpSignalConversionAtEn_a1;
  UInt16 localTmpSignalConversionAtEn_fh;
  UInt8 localTmpSignalConversionAtEn_op;
  UInt16 localTmpSignalConversionAtInM_m;
  UInt16 localTmpSignalConversionAtFARSp;
  UInt16 localTmpSignalConversionAtCanPu;
  UInt16 localTmpSignalConversionAtUsT_b;
  UInt16 localTmpSignalConversionAtExt_p;
  Float32 localtmp;
  UInt32 localtmp_0;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_engLoaMin'
   *
   * Block requirements for '<S1>/F01_engLoaMin':
   *  1. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_068.01 ;
   *  2. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_069.01 ;
   *  3. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_102.01 ;
   *  4. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_103.01 ;
   *  5. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_208.01 ;
   *  6. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_210.02 ;
   *  7. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_202.01 ;
   *  8. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_247.02 ;
   *  9. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_286.01 ;
   *  10. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_287.01 ;
   *  11. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_277.02 ;
   *  12. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_183.01 ;
   *  13. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_209.01 ;
   *  14. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_211.01 ;
   *  15. SubSystem "F01_engLoaMin" !Trace_To : VEMS_R_11_00998_212.01 ;
   */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&localTmpSignalConversionAtEn_a1);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtEngM_facOfsEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facOfsEfcCor_INPUT'
   */
  Rte_Read_R_EngM_facOfsEfcCor_EngM_facOfsEfcCor
    (&localTmpSignalConversionAtEn_fh);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtEngM_facACorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facACor_INPUT'
   */
  Rte_Read_R_EngM_facACor_EngM_facACor(&localTmpSignalConversionAtEn_op);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtExt_bAcvGasModOutport2' incorporates:
   *  Inport: '<Root>/Ext_bAcvGasMod'
   */
  Rte_Read_R_Ext_bAcvGasMod_Ext_bAcvGasMod(&localTmpSignalConversionAtEx_nm);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtInM_concAirCorOutport2' incorporates:
   *  Inport: '<Root>/InM_concAirCor'
   */
  Rte_Read_R_InM_concAirCor_InM_concAirCor(&localTmpSignalConversionAtInM_m);

  /* Outputs for atomic SubSystem: '<S21>/F01_rLdMin_par_equation_de_charge_Pmini' *
   * Block requirements for '<S21>/F01_rLdMin_par_equation_de_charge_Pmini':
   *  1. SubSystem "F01_rLdMin_par_equation_de_charge_Pmini" !Trace_To : VEMS_R_11_00998_070.01 ;
   */

  /* Lookup: '<S482>/Look-Up Table'
   * About '<S482>/Look-Up Table':
   * Input0  Data Type:  Integer        U16
   * Output0 Data Type:  Fixed Point    U16  2^3
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_h), (&(EngM_pInMnfMinReq_T[0])),
                 localTmpSignalConversionAtExt_n, (&(Ext_nEngRef2_A[0])), 8U);

  /* DataTypeDuplicate Block: '<S482>/Data Type Duplicate1'
   *
   * Regarding '<S482>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S476>/Data Type Conversion'
   *
   * Regarding '<S476>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Product: '<S489>/Divide' incorporates:
   *  DataTypeConversion: '<S21>/SignalConversion13'
   *  DataTypeConversion: '<S478>/SignalConversion7'
   */
  localProduct4_nz = (((Float32)localTmpSignalConversionAtEn_a1) *
                      3.356933620E-010F) * (((Float32)localLookUpTable_h) *
    8.0F);

  /* DataStoreWrite: '<S478>/MemoryStore1' incorporates:
   *  Constant: '<S487>/offset'
   *  Constant: '<S487>/one_on_slope'
   *  DataTypeConversion: '<S487>/OutDTConv'
   *  Product: '<S487>/Product4'
   *  Sum: '<S487>/Add1'
   */
  localtmp = 16384.0F * localProduct4_nz;
  if (localtmp < 65536.0F) {
    EngM_rLd_MP = (UInt16)localtmp;
  } else {
    EngM_rLd_MP = MAX_uint16_T;
  }

  /* PreLookup: '<S486>/Prelookup' */
  localPrelookup_o1_d = plook_s32u16f_bincpa(localLookUpTable_h, (&(Air_pAir_A[0])),
    15U, &localPrelookup_o2_m, &EngMGslT_DWork.Prelookup_DWORK1_g);

  /* PreLookup: '<S485>/Prelookup' */
  localPrelookup_o1_pg = plook_s32u16f_bincpa(localTmpSignalConversionAtExt_n, (
    &(Ext_nEng_A[0])), 15U, &localPrelookup_o2_k,
    &EngMGslT_DWork.Prelookup_DWORK1_h);

  /* If: '<S478>/If' incorporates:
   *  ActionPort: '<S483>/Action Port'
   *  ActionPort: '<S484>/Action Port'
   *  SubSystem: '<S478>/If Action Subsystem'
   *  SubSystem: '<S478>/If Action Subsystem1'
   */
  if (localTmpSignalConversionAtEx_nm) {
    /* Interpolation_n-D: '<S493>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_m;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localPrelookup_o1_d;
    localbpIndex[1] = localPrelookup_o1_pg;
    localfractionTmp_0d = intrp2d_is16n11ff_s32f_la_ns(localbpIndex, localfrac,
      (&(EngM_facDGas_M[0])), 16U, &EngMGslT_ConstP.pooled22[0]);
  } else {
    /* Interpolation_n-D: '<S494>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_m;
    localfrac[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac[1] = localfractionTmp_0d;
    localbpIndex[0] = localPrelookup_o1_d;
    localbpIndex[1] = localPrelookup_o1_pg;
    localfractionTmp_0d = intrp2d_is16n11ff_s32f_la_ns(localbpIndex, localfrac,
      (&(EngM_facD_M[0])), 16U, &EngMGslT_ConstP.pooled22[0]);
  }

  /* Product: '<S492>/Divide' incorporates:
   *  DataTypeConversion: '<S21>/SignalConversion11'
   *  DataTypeConversion: '<S21>/SignalConversion12'
   *  DataTypeConversion: '<S21>/SignalConversion14'
   *  Product: '<S490>/Divide'
   *  SignalConversion: '<S21>/TmpSignal ConversionAtEngM_facECor_irvOutport2'
   *  Sum: '<S478>/Sum'
   */
  localfractionTmp_0d = (((localProduct4_nz - (((Float32)
    localTmpSignalConversionAtEn_fh) * 6.103515625E-005F)) + localfractionTmp_0d)
    * ((((Float32)localTmpSignalConversionAtEn_op) * 0.00390625F) + 0.5F)) *
    ((((Float32)Rte_IrvRead_RE_EngMGslT_026_TEV_EngM_facECor_irv()) *
      0.0009765625F) + 0.75F);

  /* DataStoreWrite: '<S478>/MemoryStore3' incorporates:
   *  Constant: '<S488>/offset'
   *  Constant: '<S488>/one_on_slope'
   *  DataTypeConversion: '<S488>/OutDTConv'
   *  Product: '<S488>/Product4'
   *  Sum: '<S488>/Add1'
   */
  localtmp = 16384.0F * localfractionTmp_0d;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      EngM_rMinLd_MP = (UInt16)localtmp;
    } else {
      EngM_rMinLd_MP = 0U;
    }
  } else {
    EngM_rMinLd_MP = MAX_uint16_T;
  }

  /* Product: '<S491>/Divide' incorporates:
   *  DataTypeConversion: '<S21>/SignalConversion7'
   */
  EngM_rMinLd = ((((Float32)localTmpSignalConversionAtInM_m) *
                  1.525878906E-005F) + 1.525878906E-005F) * localfractionTmp_0d;

  /* end of Outputs for SubSystem: '<S21>/F01_rLdMin_par_equation_de_charge_Pmini' */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_c);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtInjSys_prm_bInjCutOffCylOutport2' incorporates:
   *  Inport: '<Root>/InjSys_prm_bInjCutOffCyl'
   */
  Rte_Read_R_InjSys_prm_bInjCutOffCyl_InjSys_prm_bInjCutOffCyl
    (&localTmpSignalConversionAtInj_e);

  /* Logic: '<S21>/Logical Operator' */
  localTmpSignalConversionAtEx_nm = ((((((localTmpSignalConversionAtInj_e[0]) ||
    (localTmpSignalConversionAtInj_e[1])) || (localTmpSignalConversionAtInj_e[2]))
    || (localTmpSignalConversionAtInj_e[3])) ||
    (localTmpSignalConversionAtInj_e[4])) || (localTmpSignalConversionAtInj_e[5]));

  /* SignalConversion: '<S21>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsT_b);

  /* Outputs for atomic SubSystem: '<S21>/F02_rLdMini_Cartographie' *
   * Block requirements for '<S21>/F02_rLdMini_Cartographie':
   *  1. SubSystem "F02_rLdMini_Cartographie" !Trace_To : VEMS_R_11_00998_071.01 ;
   */

  /* PreLookup: '<S498>/Prelookup' */
  localPrelookup_o1_d = plook_s32s16f_bincpa(localTmpSignalConversionAtExt_c,
    (&(Ext_tCoRef1_A[0])), 16U, &localPrelookup_o2_e,
    &EngMGslT_DWork.Prelookup_DWORK1);

  /* If: '<S479>/If' incorporates:
   *  ActionPort: '<S496>/Action Port'
   *  ActionPort: '<S497>/Action Port'
   *  SubSystem: '<S479>/If Action Subsystem'
   *  SubSystem: '<S479>/If Action Subsystem1'
   */
  if (localTmpSignalConversionAtEx_nm) {
    /* Interpolation_n-D: '<S504>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac_0[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_e;
    localfrac_0[1] = localfractionTmp_0d;
    localbpIndex_0[0] = localPrelookup_o1_pg;
    localbpIndex_0[1] = localPrelookup_o1_d;
    localfractionTmp_0d = intrp2d_iu16n14ff_s32f_la_ns(localbpIndex_0,
      localfrac_0, (&(EngM_rLdMinProt_M[0])), 16U, &EngMGslT_ConstP.pooled24[0]);
  } else {
    /* Interpolation_n-D: '<S505>/Interpolation Using Prelookup3' */
    localfractionTmp_0d = localPrelookup_o2_k;
    localfrac_0[0] = localfractionTmp_0d;
    localfractionTmp_0d = localPrelookup_o2_e;
    localfrac_0[1] = localfractionTmp_0d;
    localbpIndex_0[0] = localPrelookup_o1_pg;
    localbpIndex_0[1] = localPrelookup_o1_d;
    localfractionTmp_0d = intrp2d_iu16n14ff_s32f_la_ns(localbpIndex_0,
      localfrac_0, (&(EngM_rLdMinRef_M[0])), 16U, &EngMGslT_ConstP.pooled24[0]);
  }

  /* DataStoreWrite: '<S479>/MemoryStore1' incorporates:
   *  Constant: '<S499>/offset'
   *  Constant: '<S499>/one_on_slope'
   *  DataTypeConversion: '<S499>/OutDTConv'
   *  Product: '<S499>/Product4'
   *  Sum: '<S499>/Add1'
   */
  localtmp = 16384.0F * localfractionTmp_0d;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      EngM_rLdMinBas_MP = (UInt16)localtmp;
    } else {
      EngM_rLdMinBas_MP = 0U;
    }
  } else {
    EngM_rLdMinBas_MP = MAX_uint16_T;
  }

  /* Product: '<S502>/Divide' incorporates:
   *  Constant: '<S479>/Air_pUsThrRef_C'
   *  DataTypeConversion: '<S479>/SignalConversion1'
   *  DataTypeConversion: '<S479>/SignalConversion5'
   */
  localProduct4_nz = (((Float32)localTmpSignalConversionAtUsT_b) * 8.0F) /
    (((Float32)Air_pUsThrRef_C) * 8.0F);

  /* Outputs for atomic SubSystem: '<S502>/If Action Subsystem3' */

  /* Switch: '<S507>/Switch1' incorporates:
   *  Constant: '<S507>/Constant1'
   *  Constant: '<S507>/Constant2'
   *  Constant: '<S507>/Constant3'
   *  Logic: '<S507>/Logical Operator1'
   *  RelationalOperator: '<S507>/Relational Operator'
   *  RelationalOperator: '<S507>/Relational Operator1'
   *  RelationalOperator: '<S507>/Relational Operator3'
   */
  if (((localProduct4_nz != localProduct4_nz) || (localProduct4_nz >
        3.000000005E+038F)) || (-3.000000005E+038F > localProduct4_nz)) {
    localProduct4_nz = 0.0F;
  }

  /* end of Outputs for SubSystem: '<S502>/If Action Subsystem3' */

  /* DataTypeConversion: '<S501>/OutDTConv' incorporates:
   *  Constant: '<S501>/offset'
   *  Constant: '<S501>/one_on_slope'
   *  Product: '<S501>/Product4'
   *  Sum: '<S501>/Add1'
   */
  localtmp = (localProduct4_nz - 0.5F) * 65536.0F;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_ay = (UInt16)localtmp;
    } else {
      localOutDTConv_ay = 0U;
    }
  } else {
    localOutDTConv_ay = MAX_uint16_T;
  }

  /* Lookup: '<S495>/Look-Up Table'
   * About '<S495>/Look-Up Table':
   * Input0  Data Type:  Fixed Point    U16  2^-16  Bias 0.5
   * Output0 Data Type:  Fixed Point    U16  2^-16  Bias 0.5
   * Lookup Method: Linear_Endpoint
   *
   * XData parameter uses the same data type and scaling as Input0
   * YData parameter uses the same data type and scaling as Output0
   */
  LookUp_U16_U16( &(localLookUpTable_k), (&(EngM_facCorRatPresExt_T[0])),
                 localOutDTConv_ay, (&(Air_rAirPresRef2_A[0])), 21U);

  /* DataTypeDuplicate Block: '<S495>/Data Type Duplicate1'
   *
   * Regarding '<S495>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* Product: '<S503>/Divide' incorporates:
   *  DataTypeConversion: '<S479>/SignalConversion3'
   *  Lookup: '<S495>/Look-Up Table'
   */
  localfractionTmp_0d *= (((Float32)localLookUpTable_k) * 1.525878906E-005F) +
    0.5F;

  /* DataStoreWrite: '<S479>/MemoryStore5' incorporates:
   *  Constant: '<S500>/offset'
   *  Constant: '<S500>/one_on_slope'
   *  DataTypeConversion: '<S500>/OutDTConv'
   *  Product: '<S500>/Product4'
   *  Sum: '<S500>/Add1'
   */
  localtmp = 16384.0F * localfractionTmp_0d;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      EngM_rLdMinCor_MP = (UInt16)localtmp;
    } else {
      EngM_rLdMinCor_MP = 0U;
    }
  } else {
    EngM_rLdMinCor_MP = MAX_uint16_T;
  }

  /* MinMax: '<S479>/MinMax1' incorporates:
   *  Constant: '<S479>/Air_rLdMin_C'
   */
  localProduct4_nz = rt_MAXf(EngM_rMinLd, ((Float32)Air_rLdMin_C) *
    6.103515625E-005F);
  EngM_rLdMinCord = rt_MAXf(localProduct4_nz, localfractionTmp_0d);

  /* end of Outputs for SubSystem: '<S21>/F02_rLdMini_Cartographie' */

  /* SignalConversion: '<S21>/TmpSignal ConversionAtExt_pFuMesFineReslOutport2' incorporates:
   *  Inport: '<Root>/Ext_pFuMesFineResl'
   */
  Rte_Read_R_Ext_pFuMesFineResl_Ext_pFuMesFineResl
    (&localTmpSignalConversionAtExt_p);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtFARSp_rMixtCylSpOutport2' incorporates:
   *  Inport: '<Root>/FARSp_rMixtCylSp'
   */
  Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&localTmpSignalConversionAtFARSp);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtCanPurg_mfFuStmEstimOutport2' incorporates:
   *  Inport: '<Root>/CanPurg_mfFuStmEstim'
   */
  Rte_Read_R_CanPurg_mfFuStmEstim_CanPurg_mfFuStmEstim
    (&localTmpSignalConversionAtCanPu);

  /* DataTypeConversion: '<S21>/SignalConversion3' */
  localfractionTmp_0d = (Float32)localTmpSignalConversionAtExt_n;

  /* SignalConversion: '<S21>/TmpSignal ConversionAtInjSys_bAcvAirLdMinSatOutport2' incorporates:
   *  Inport: '<Root>/InjSys_bAcvAirLdMinSat'
   */
  Rte_Read_R_InjSys_bAcvAirLdMinSat_InjSys_bAcvAirLdMinSat
    (&localTmpSignalConversionAtInj_p);

  /* Outputs for atomic SubSystem: '<S21>/F03_rLdMin_Valve_Sans_Retour' *
   * Block requirements for '<S21>/F03_rLdMin_Valve_Sans_Retour':
   *  1. SubSystem "F03_rLdMin_Valve_Sans_Retour" !Trace_To : VEMS_R_11_00998_072.01 ;
   */

  /* Outputs for atomic SubSystem: '<S480>/F01_Transformation_debit_masse' *
   * Block requirements for '<S480>/F01_Transformation_debit_masse':
   *  1. SubSystem "F01_Transformation_debit_masse" !Trace_To : VEMS_R_11_00998_073.01 ;
   */

  /* Switch: '<S510>/Switch' incorporates:
   *  Abs: '<S510>/Abs1'
   *  Abs: '<S510>/Abs2'
   *  Constant: '<S510>/ '
   *  Constant: '<S510>/ 1'
   *  Constant: '<S510>/ Constant2'
   *  Constant: '<S510>/constant'
   *  Product: '<S515>/Divide'
   *  RelationalOperator: '<S510>/Relational Operator'
   */
  localProduct4_nz = 3.051757813E-005F;

  /* Switch: '<S510>/Switch2' incorporates:
   *  Abs: '<S510>/Abs'
   *  Abs: '<S510>/Abs3'
   *  Constant: '<S510>/ constant3'
   *  RelationalOperator: '<S510>/Relational Operator1'
   */
  if (!(localfractionTmp_0d < 3.051757813E-005F)) {
    localProduct4_nz = localfractionTmp_0d;
  }

  /* Product: '<S514>/Divide' incorporates:
   *  DataTypeConversion: '<S21>/SignalConversion1'
   */
  localProduct4_nz = (((Float32)localTmpSignalConversionAtCanPu) *
                      9.536743164E-007F) / localProduct4_nz;

  /* RelationalOperator: '<S518>/LowerRelop1' incorporates:
   *  Constant: '<S510>/SatMaxDiv'
   */
  localLowerRelop1 = (localProduct4_nz > 1.0E+005F);

  /* Switch: '<S518>/Switch' incorporates:
   *  Constant: '<S510>/SatMinDiv'
   *  RelationalOperator: '<S518>/UpperRelop'
   */
  if (localProduct4_nz < -1.0E+005F) {
    localProduct4_nz = -1.0E+005F;
  }

  /* Switch: '<S518>/Switch2' incorporates:
   *  Constant: '<S510>/SatMaxDiv'
   */
  if (localLowerRelop1) {
    localProduct4_nz = 1.0E+005F;
  }

  /* Product: '<S512>/Divide' incorporates:
   *  Constant: '<S508>/Ext_noCylEng_SC'
   *  Constant: '<S508>/Ext_noCylRev_SC'
   *  DataTypeConversion: '<S508>/Data Type Conversion'
   *  DataTypeConversion: '<S508>/Data Type Conversion1'
   *  Product: '<S511>/Divide'
   */
  EngM_mFuStmEstim = (((Float32)Ext_noCylRev_SC) / ((Float32)Ext_noCylEng_SC))
    * localProduct4_nz;

  /* end of Outputs for SubSystem: '<S480>/F01_Transformation_debit_masse' */

  /* Outputs for atomic SubSystem: '<S480>/F02_Calcul_rlMinFinal_Valve_sans_retour' *
   * Block requirements for '<S480>/F02_Calcul_rlMinFinal_Valve_sans_retour':
   *  1. SubSystem "F02_Calcul_rlMinFinal_Valve_sans_retour" !Trace_To : VEMS_R_11_00998_074.01 ;
   */

  /* If: '<S509>/If1' incorporates:
   *  ActionPort: '<S519>/Action Port'
   *  ActionPort: '<S520>/Action Port'
   *  Constant: '<S509>/EngM_bAcvStraLdMin_C'
   *  Logic: '<S509>/Logical Operator1'
   *  SubSystem: '<S509>/If Action Subsystem2'
   *  SubSystem: '<S509>/If Action Subsystem3'
   */
  if (EngM_bAcvStraLdMin_C && (localTmpSignalConversionAtInj_p)) {
    /* If: '<S519>/If' incorporates:
     *  ActionPort: '<S521>/Action Port'
     *  ActionPort: '<S522>/Action Port'
     *  SubSystem: '<S519>/If Action Subsystem'
     *  SubSystem: '<S519>/If Action Subsystem1'
     */
    if (localTmpSignalConversionAtEx_nm) {
      /* Inport: '<S521>/EngM_rLdMinCord' */
      localfractionTmp_0d = EngM_rLdMinCord;
    } else {
      /* DataTypeConversion: '<S522>/SignalConversion4' */
      localtmp_0 = ((((UInt32)localTmpSignalConversionAtExt_p) * 52429U) >> 12);
      if (localtmp_0 > 65535U) {
        localSignalConversion4_j = MAX_uint16_T;
      } else {
        localSignalConversion4_j = (UInt16)localtmp_0;
      }

      /* Lookup: '<S524>/Look-Up Table'
       * About '<S524>/Look-Up Table':
       * Input0  Data Type:  Fixed Point    U16  2^9  FSlope 1.5258789062500000E+000
       * Output0 Data Type:  Fixed Point    U16  2^-16
       * Lookup Method: Linear_Endpoint
       *
       * XData parameter uses the same data type and scaling as Input0
       * YData parameter uses the same data type and scaling as Output0
       */
      LookUp_U16_U16( &(localLookUpTable_d1), (&(EngM_mfFuInjMin_T[0])),
                     localSignalConversion4_j, (&(EngM_pFuLdMin_A[0])), 5U);

      /* DataTypeDuplicate Block: '<S524>/Data Type Duplicate1'
       *
       * Regarding '<S524>/Data Type Duplicate1':
       *   Unused code path elimination
       */

      /* Product: '<S526>/Divide' incorporates:
       *  Constant: '<S522>/EngM_tiInjMin_C'
       *  Constant: '<S522>/Eng_facStoich_C'
       *  DataTypeConversion: '<S21>/SignalConversion6'
       *  DataTypeConversion: '<S522>/SignalConversion2'
       *  Lookup: '<S524>/Look-Up Table'
       *  Product: '<S528>/Divide'
       *  Product: '<S529>/Divide'
       *  Sum: '<S522>/Sum'
       */
      localfractionTmp_0d = ((((Float32)(((Float32d)(((Float32)
        localLookUpTable_d1) * 1.525878906E-005F)) * ACTEMS_LdexpF((Float32d)
        EngM_tiInjMin_C, -16))) + EngM_mFuStmEstim) * (((Float32)
        Eng_facStoich_C) * 0.00048828125F)) / (((Float32)
        localTmpSignalConversionAtFARSp) * 0.000244140625F);

      /* Outputs for atomic SubSystem: '<S526>/If Action Subsystem3' */

      /* Switch: '<S531>/Switch1' incorporates:
       *  Constant: '<S531>/Constant1'
       *  Constant: '<S531>/Constant2'
       *  Constant: '<S531>/Constant3'
       *  Logic: '<S531>/Logical Operator1'
       *  RelationalOperator: '<S531>/Relational Operator'
       *  RelationalOperator: '<S531>/Relational Operator1'
       *  RelationalOperator: '<S531>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        localfractionTmp_0d = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S526>/If Action Subsystem3' */

      /* DataStoreWrite: '<S522>/MemoryStore3' incorporates:
       *  Constant: '<S525>/offset'
       *  Constant: '<S525>/one_on_slope'
       *  DataTypeConversion: '<S525>/OutDTConv'
       *  Product: '<S525>/Product4'
       *  Sum: '<S525>/Add1'
       */
      localtmp = 8.389145E+006F * localfractionTmp_0d;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          EngM_mAirMin_MP = (UInt16)localtmp;
        } else {
          EngM_mAirMin_MP = 0U;
        }
      } else {
        EngM_mAirMin_MP = MAX_uint16_T;
      }

      /* Product: '<S527>/Divide' incorporates:
       *  Constant: '<S522>/Eng_mRef_C'
       *  DataTypeConversion: '<S522>/SignalConversion6'
       */
      localfractionTmp_0d /= ((Float32)Eng_mRef_C) * 1.192016583E-007F;

      /* Outputs for atomic SubSystem: '<S527>/If Action Subsystem3' */

      /* Switch: '<S533>/Switch1' incorporates:
       *  Constant: '<S533>/Constant1'
       *  Constant: '<S533>/Constant2'
       *  Constant: '<S533>/Constant3'
       *  Logic: '<S533>/Logical Operator1'
       *  RelationalOperator: '<S533>/Relational Operator'
       *  RelationalOperator: '<S533>/Relational Operator1'
       *  RelationalOperator: '<S533>/Relational Operator3'
       */
      if (((localfractionTmp_0d != localfractionTmp_0d) || (localfractionTmp_0d >
            3.000000005E+038F)) || (-3.000000005E+038F > localfractionTmp_0d)) {
        localfractionTmp_0d = 0.0F;
      }

      /* end of Outputs for SubSystem: '<S527>/If Action Subsystem3' */

      /* MinMax: '<S522>/MinMax1' */
      localfractionTmp_0d = rt_MAXf(EngM_rLdMinCord, localfractionTmp_0d);
    }

    /* DataStoreWrite: '<S519>/MemoryStore1' incorporates:
     *  Constant: '<S523>/offset'
     *  Constant: '<S523>/one_on_slope'
     *  DataTypeConversion: '<S523>/OutDTConv'
     *  Product: '<S523>/Product4'
     *  Sum: '<S523>/Add1'
     */
    localtmp = 16384.0F * localfractionTmp_0d;
    if (localtmp < 65536.0F) {
      if (localtmp >= 0.0F) {
        EngM_rMinCord_MP = (UInt16)localtmp;
      } else {
        EngM_rMinCord_MP = 0U;
      }
    } else {
      EngM_rMinCord_MP = MAX_uint16_T;
    }
  } else {
    /* Inport: '<S520>/EngM_rLdMinCord' */
    localfractionTmp_0d = EngM_rLdMinCord;
  }

  /* end of Outputs for SubSystem: '<S480>/F02_Calcul_rlMinFinal_Valve_sans_retour' */

  /* end of Outputs for SubSystem: '<S21>/F03_rLdMin_Valve_Sans_Retour' */

  /* DataTypeConversion: '<S481>/OutDTConv' incorporates:
   *  Constant: '<S481>/offset'
   *  Constant: '<S481>/one_on_slope'
   *  Product: '<S481>/Product4'
   *  Sum: '<S481>/Add1'
   */
  localtmp = 16384.0F * localfractionTmp_0d;
  if (localtmp < 65536.0F) {
    if (localtmp >= 0.0F) {
      localOutDTConv_gv = (UInt16)localtmp;
    } else {
      localOutDTConv_gv = 0U;
    }
  } else {
    localOutDTConv_gv = MAX_uint16_T;
  }

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S477>/autosar_testpoint1' */

  /* S-Function Block: <S477>/autosar_testpoint1 */
  EngM_rMinTotLd_IRV_MP = localOutDTConv_gv;

  /* Switch: '<S476>/Switch' incorporates:
   *  Constant: '<S476>/Byp_Fonction_SC'
   *  Constant: '<S476>/Int_BypC'
   */
  if (ENGMGSLT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtEn_a1 = EngM_pInMnfMinReq_B;
  } else {
    localTmpSignalConversionAtEn_a1 = localLookUpTable_h;
  }

  /* SignalConversion: '<S21>/SignalConversion8' */
  localTmpSignalConversionAtEn_fh = localOutDTConv_gv;

  /* SignalConversion: '<S21>/TmpSignal ConversionAtEngM_pInMnfMinReqInport2' */
  Rte_Write_P_EngM_pInMnfMinReq_EngM_pInMnfMinReq
    (localTmpSignalConversionAtEn_a1);

  /* SignalConversion: '<S21>/TmpSignal ConversionAtEngM_rMinTotLd_irvInport2' */
  Rte_IrvWrite_RE_EngMGslT_026_TEV_EngM_rMinTotLd_irv
    (localTmpSignalConversionAtEn_fh);
}

/* Model initialize function */
void Runnable_EngMGslT_Init(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__10'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   *  Start for SubSystem: '<Root>/__ExpFcn__8'
   *  Start for SubSystem: '<Root>/__ExpFcn__9'
   */
  RE_EngMGslT_001_MSE_Start();
  RE_EngMGslT_020_TEV_Start();
  RE_EngMGslT_012_TEV_Start();
  RE_EngMGslT_008_TEV_Start();
  RE_EngMGslT_018_TEV_Start();
  RE_EngMGslT_022_TEV_Start();
  RE_EngMGslT_024_TEV_Start();
  RE_EngMGslT_026_TEV_Start();
}

#define EngMGslT_STOP_SEC_CODE
#include "EngMGslT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
