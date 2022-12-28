/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : AFAT                                                    */
/* !Description     : AFAT Software component                                 */
/*                                                                            */
/* !Module          : AFAT                                                    */
/* !Description     : AFAT Software Component                                 */
/*                                                                            */
/* !File            : AFAT.c                                                  */
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
/*   Model name       : AFAT_SWC.mdl                                          */
/*   Root subsystem   : /AFAT                                                 */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/BA/M11-AFAT/5-SOFT-$*/
/* $Revision::   1.13                                                        $*/
/* $Author::   adelvare                               $$Date::   21 Jul 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "AFAT.h"
#include "AFAT_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Named constants for Stateflow: '<S276>/F01_algo_adapt_control_process_chart1' */
#define IN_APP                         (1U)
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_OBS                         (2U)
#define IN_Pas0                        (1U)
#define IN_Pas1                        (2U)
#define IN_Pas2                        (3U)
#define IN_Pas3                        (4U)
#define IN_Pas4                        (5U)
#define IN_Pas5                        (6U)
#define IN_Pas6                        (7U)
#define IN_Pas7                        (8U)
#define IN_Pas8                        (9U)
#define IN_WAIT                        (3U)

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */


#define AFAT_START_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


/* Exported block signals */
UInt32 AFA_tiDlyLstObsPrev;          
UInt32 AFA_tiAcvSpcInjModPrev;       
UInt32 AFA_tiAcvSpcInjMod;           
UInt32 AFA_mFuReqFil_IRV_MP;         
UInt32 AFA_tAirUsInVlvEstimFil_IRV_MP;
UInt32 AFA_facSlopEfcCorFil_IRV_MP;  

#define AFAT_STOP_SEC_INTERNAL_VAR_32BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"

SInt16 AFA_tCoMesFil_IRV_MP;          
UInt16 AFA_facOutInnov_MP;           
UInt16 AFA_nEngFil_IRV_MP;           
UInt16 AFA_nEngCorFil_IRV_MP;        
UInt16 AFA_noAdpEfcIni;              
UInt16 AFA_noAdpEfcAstIni;           
UInt16 AFA_rEthStoichFil_IRV_MP;     
UInt16 AFA_prm_covNoiseValPrev[8];   
UInt16 AFA_prm_covNoiseValIni[8];    
SInt16 AFA_prm_rErrPrev[8];           
SInt16 AFA_prm_rErrIni[8];            
UInt16 AFA_rTotLdExCorFil_IRV_MP;    
UInt16 AFA_rInMassFlowFil_IRV_MP;    
UInt16 AFA_pAirExtEstimHldPrev;      
UInt16 AFA_pExMnfEstimFil_IRV_MP;    
UInt16 AFA_pAirExtEstimFil_IRV_MP;   
UInt16 AFA_pDsThrPred_facVlvOvlpFil; 
UInt16 AFA_pDsThrEstimFil_IRV_MP;    
UInt16 AFA_pDsThrCorFil_IRV_MP;      
UInt16 AFA_pAirExtEstimHld_IRV_MP;   
UInt16 AFA_arEffAdpThrFil_IRV_MP;    
UInt16 AFA_arEffAdpEGRVlvFil_IRV_MP; 
UInt16 AFA_arEffEGRVlvFil_IRV_MP;    
SInt16 AFA_pDsThrEstimErrFil_IRV_MP;  
UInt16 AFA_rOpClsEGRVlvBolPrev;      
UInt16 AFA_rOpClsThrBolPrev;         
UInt16 AFA_rOpSIFil_IRV_MP;          
UInt16 AFA_rOpClsThrBolHld_IRV_MP;   
UInt16 AFA_rOpClsEGRVlvBolHld_IRV_MP;
UInt16 AFA_agCkOpInVlvBolPrev;       
UInt16 AFA_agCkClsExVlvBolPrev;      
UInt16 AFA_agCkClsInVlvEstimRef1Fil; 
UInt16 AFA_agCkOpInVlvBolHld_IRV_MP; 
UInt16 AFA_agCkClsExVlvBolHld_IRV_MP;
SInt16 AFA_agCkClsExVlvEstimRef1Fil;  
SInt16 AFA_agCkOpInVlvEstimRef1Fil;   
UInt16 AFA_tExMnfEstimFil_IRV_MP;    

#define AFAT_STOP_SEC_INTERNAL_VAR_16BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"

UInt8 AFA_noObsDonePrev;             
UInt8 AFA_stMonAdp;                  
UInt8 AFA_noObsDoneIdlPrev;          
UInt8 AFA_noObsSpcInjModPrev;        
UInt8 AFA_noObsInnovNotCohPrev;      
UInt8 AFA_noRstAdpValPrev;           
UInt8 AFA_noObsDoneIni;              
UInt8 AFA_noObsInnovNotCoh_IRV_MP;   
UInt8 AFA_noObsSpcInjModIni;         
UInt8 AFA_noObsSpcInjMod_IRV_MP;     
UInt8 AFA_noObsDoneIdlIni;           
UInt8 AFA_noObsDoneIdlIni_IRV_MP;    
UInt8 AFA_noAdpClcRstPrev;           
UInt8 AFA_prm_noObsDoneMatIni[9];    
UInt8 AFA_facRhoFuFil_IRV_MP;        

#define AFAT_STOP_SEC_INTERNAL_VAR_8BIT
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"

Boolean AFA_bObsRun;                 
Boolean AFA_bIdcInv_covPredInnov_IRV_MP;
Boolean AFA_bAdpClcRstReqPrev;       
Boolean AFA_bEngStopAuthIni;         
Boolean AFA_bAcvSpcInjModIni;        
Boolean AFA_bAdpClcRstReqIni;        
Boolean AFA_bAdpClcRstReqHld_IRV_MP; 

#define AFAT_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "AFAT_MemMap.h"


#define AFAT_START_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"


/* Block signals (auto storage) */
BlockIO_AFAT AFAT_B;

/* Block states (auto storage) */
D_Work_AFAT AFAT_DWork;


#define AFAT_STOP_SEC_VAR_UNSPECIFIED
#include "AFAT_MemMap.h"


/******************************************************************/
/*  Check Library Version                                         */
/******************************************************************/
#include "VemsRtLibT_compatibility.h"
#define AFAT_VEMSRTLIBT_MAJOR_VERSION_REQ 4
#define AFAT_VEMSRTLIBT_MINOR_VERSION_REQ 14
#define AFAT_VEMSRTLIBT_PATCH_VERSION_REQ 0
#define AFAT_VEMSRTLIBT_VERSION_REQ (AFAT_VEMSRTLIBT_PATCH_VERSION_REQ + AFAT_VEMSRTLIBT_MINOR_VERSION_REQ*1000 + AFAT_VEMSRTLIBT_MAJOR_VERSION_REQ*1000000)
#if AFAT_VEMSRTLIBT_VERSION_REQ > VEMSRTLIBT_VERSION
#error VemsRtLibT version is not compatible with current SWC version
#endif


/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AFAT_START_SEC_CODE
#include "AFAT_MemMap.h"

void AFAT_ASYNC1(int controlPortIdx)
{
}

void AFAT_ASYNC2(int controlPortIdx)
{
}

void AFAT_ASYNC3(int controlPortIdx)
{
}

void AFAT_ASYNC4(int controlPortIdx)
{
}

void AFAT_ASYNC5(int controlPortIdx)
{
}

void AFAT_ASYNC6(int controlPortIdx)
{
}

void AFAT_ASYNC7(int controlPortIdx)
{
}

void AFAT_ASYNC8(int controlPortIdx)
{
}

/* Start for exported function: RE_AFAT_001_MSE */
void RE_AFAT_001_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_initialisation_(001_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_initialisation_(001_MSE)':
   *  1. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_135.01 ;
   *  2. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_136.01 ;
   *  3. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_221.01 ;
   *  4. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_223.01 ;
   *  5. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_225.01 ;
   *  6. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_237.01 ;
   *  7. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_206.01 ;
   *  8. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_208.01 ;
   *  9. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_220.01 ;
   *  10. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_222.01 ;
   *  11. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  12. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_232.01 ;
   *  13. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  14. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  15. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  16. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  17. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_235.01 ;
   *  18. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_236.01 ;
   *  19. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_201.01 ;
   *  20. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_202.01 ;
   *  21. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_203.01 ;
   *  22. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  23. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  24. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_215.01 ;
   *  25. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_216.01 ;
   *  26. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_217.01 ;
   *  27. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_218.01 ;
   *  28. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_219.01 ;
   *  29. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_231.01 ;
   *  30. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_234.01 ;
   *  31. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_213.01 ;
   *  32. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_214.01 ;
   *  33. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  34. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_246.01 ;
   *  35. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  36. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_248.01 ;
   *  37. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  38. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_250.01 ;
   *  39. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  40. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  41. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  42. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  43. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  44. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  45. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_278.01 ;
   *  46. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_279.01 ;
   *  47. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  48. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  49. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  50. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  51. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  52. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  53. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  54. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  55. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  56. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  57. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  58. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  59. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  60. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  61. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  62. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  63. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  64. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  65. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  66. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  67. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  68. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  69. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_303.01 ;
   *  70. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  71. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_305.01 ;
   *  72. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_306.01 ;
   */
}

/* Output and update for exported function: RE_AFAT_001_MSE */
void RE_AFAT_001_MSE(void)
{
  UInt8 localSwitch_bf;
  UInt16 localSwitch_h;
  Boolean localSwitch_m5;
  UInt32 localSwitch_c;
  SInt16 localSwitch_b;
  SInt8 localSwitch_go;
  UInt16 localSwitch_g[8];
  SInt32 locali;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_initialisation_(001_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_initialisation_(001_MSE)':
   *  1. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_135.01 ;
   *  2. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_136.01 ;
   *  3. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_221.01 ;
   *  4. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_223.01 ;
   *  5. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_225.01 ;
   *  6. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_237.01 ;
   *  7. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_206.01 ;
   *  8. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_208.01 ;
   *  9. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_220.01 ;
   *  10. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_222.01 ;
   *  11. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  12. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_232.01 ;
   *  13. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  14. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  15. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  16. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  17. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_235.01 ;
   *  18. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_236.01 ;
   *  19. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_201.01 ;
   *  20. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_202.01 ;
   *  21. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_203.01 ;
   *  22. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  23. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  24. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_215.01 ;
   *  25. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_216.01 ;
   *  26. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_217.01 ;
   *  27. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_218.01 ;
   *  28. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_219.01 ;
   *  29. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_231.01 ;
   *  30. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_234.01 ;
   *  31. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_213.01 ;
   *  32. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_214.01 ;
   *  33. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  34. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_246.01 ;
   *  35. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  36. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_248.01 ;
   *  37. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  38. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_250.01 ;
   *  39. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  40. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  41. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  42. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  43. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  44. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  45. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_278.01 ;
   *  46. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_279.01 ;
   *  47. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  48. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  49. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  50. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  51. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  52. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  53. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  54. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  55. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  56. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  57. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  58. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  59. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  60. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  61. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  62. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  63. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  64. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  65. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  66. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  67. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  68. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  69. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_303.01 ;
   *  70. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  71. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_305.01 ;
   *  72. SubSystem "RE_AFAT_initialisation_(001_MSE)" !Trace_To : VEMS_R_11_04467_306.01 ;
   */

  /* user code (Output function Body for TID15) */
  RE_AFAT_Init();
  for (locali = 0; locali < 64; locali++) {
    /* DataStoreWrite: '<S15>/Data Store Write2' incorporates:
     *  Constant: '<S15>/0_dim_1'
     */
    (*Rte_Pim_AFA_prm_covPredErrMat_PIM())[(locali)] = AFAT_ConstP.pooled6
      [(locali)];

    /* DataStoreWrite: '<S15>/Data Store Write' incorporates:
     *  Constant: '<S15>/0_dim_64'
     */
    (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)] = AFAT_ConstP.pooled6
      [(locali)];
  }

  /* DataStoreWrite: '<S15>/Data Store Write9' incorporates:
   *  Constant: '<S15>/Bool10'
   */
  for (locali = 0; locali < 9; locali++) {
    (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali)] = AFAT_ConstP.pooled14
      [(locali)];
  }

  /* DataStoreWrite: '<S15>/Data Store Write11' incorporates:
   *  Constant: '<S15>/Bool12'
   */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[0] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write12' incorporates:
   *  Constant: '<S15>/Bool13'
   */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[0] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write11' incorporates:
   *  Constant: '<S15>/Bool12'
   */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[1] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write12' incorporates:
   *  Constant: '<S15>/Bool13'
   */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[1] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write11' incorporates:
   *  Constant: '<S15>/Bool12'
   */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[2] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write12' incorporates:
   *  Constant: '<S15>/Bool13'
   */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[2] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write11' incorporates:
   *  Constant: '<S15>/Bool12'
   */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[3] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write12' incorporates:
   *  Constant: '<S15>/Bool13'
   */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[3] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write14' incorporates:
   *  Constant: '<S15>/Bool15'
   */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[0] = 0U;
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[1] = 0U;
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[2] = 0U;
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[3] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write1' incorporates:
   *  Constant: '<S15>/Bool6'
   */
  (*Rte_Pim_AFA_prm_facMes_PIM())[0] = 0;
  (*Rte_Pim_AFA_prm_facMes_PIM())[1] = 0;

  /* DataStoreWrite: '<S15>/Data Store Write6' incorporates:
   *  Constant: '<S15>/Bool7'
   */
  (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[0] = 0U;
  (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[1] = 0U;
  (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[2] = 0U;
  (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[3] = 0U;
  for (locali = 0; locali < 16; locali++) {
    /* DataStoreWrite: '<S15>/Data Store Write10' incorporates:
     *  Constant: '<S15>/Bool11'
     */
    (*Rte_Pim_AFA_prm_bMaskSenMat_PIM())[(locali)] = AFAT_ConstP.pooled17
      [(locali)];

    /* DataStoreWrite: '<S15>/Data Store Write13' incorporates:
     *  Constant: '<S15>/Bool14'
     */
    (*Rte_Pim_AFA_prm_facSenTransMat_PIM())[(locali)] = 0;

    /* DataStoreWrite: '<S15>/Data Store Write5' incorporates:
     *  Constant: '<S15>/Bool5'
     */
    (*Rte_Pim_AFA_prm_facInterMat_PIM())[(locali)] = AFAT_ConstP.pooled9[(locali)];

    /* DataStoreWrite: '<S15>/Data Store Write3' incorporates:
     *  Constant: '<S15>/Bool71'
     */
    (*Rte_Pim_AFA_prm_facSenMat_PIM())[(locali)] = 0;

    /* DataStoreWrite: '<S15>/Data Store Write7' incorporates:
     *  Constant: '<S15>/Bool8'
     */
    (*Rte_Pim_AFA_prm_facKalmMat_PIM())[(locali)] = AFAT_ConstP.pooled10[(locali)];
  }

  /* DataStoreWrite: '<S15>/Data Store Write4' incorporates:
   *  Constant: '<S15>/Bool87'
   */
  (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[0] = 0U;
  (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[1] = 0U;
  (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[2] = 0U;
  (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[3] = 0U;

  /* DataStoreWrite: '<S15>/Data Store Write8' incorporates:
   *  Constant: '<S15>/Bool9'
   */
  (*Rte_Pim_AFA_prm_facOutInnov_PIM())[0] = 0;
  (*Rte_Pim_AFA_prm_facOutInnov_PIM())[1] = 0;

  /* S-Function (NvRamReadAccess): '<S15>/S-Function1' */
  {
    UInt32 locali;
    for (locali=0 ; locali <8; locali++) {
      AFAT_B.SFunction1_d[locali] =
        AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[locali];
    }
  }

  /* SignalConversion Block: '<S504>/copy'
   *
   * Regarding '<S504>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* DataStoreWrite: '<S15>/Data Store Write15' */
  for (locali = 0; locali < 8; locali++) {
    (*Rte_Pim_AFA_prm_rErr_PIM())[(locali)] = AFAT_B.SFunction1_d[(locali)];
  }

  /* Switch: '<S531>/Switch' incorporates:
   *  Constant: '<S15>/Bool192'
   *  Constant: '<S531>/Byp_Fonction_SC'
   *  Constant: '<S531>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_bf = AFA_noAdpClcRst_B;
  } else {
    localSwitch_bf = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_noAdpClcRstInport2' */
  Rte_Write_P_AFA_noAdpClcRst_AFA_noAdpClcRst(localSwitch_bf);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S502>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool193'
   */

  /* S-Function Block: <S502>/autosar_testpoint1 */
  AFA_noAdpEfcAstIni = ((UInt16)0U);

  /* Switch: '<S530>/Switch' incorporates:
   *  Constant: '<S15>/Bool193'
   *  Constant: '<S530>/Byp_Fonction_SC'
   *  Constant: '<S530>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_noAdpEfcAst_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_noAdpEfcAstInport2' */
  Rte_Write_P_AFA_noAdpEfcAst_AFA_noAdpEfcAst(localSwitch_h);

  /* Switch: '<S518>/Switch' incorporates:
   *  Constant: '<S15>/Bool194'
   *  Constant: '<S518>/Byp_Fonction_SC'
   *  Constant: '<S518>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_bf = AFA_noRstAdpVal_B;
  } else {
    localSwitch_bf = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_noRstAdpValInport2' */
  Rte_Write_P_AFA_noRstAdpVal_AFA_noRstAdpVal(localSwitch_bf);

  /* S-Function (NvRamReadAccess): '<S15>/EepromReadAccess1' */
  AFAT_B.EepromReadAccess1_f = AFAT_sNV_Z1_CONST_BOOLEAN.AFA_bAcvSpcInjMod_NV;

  /* SignalConversion Block: '<S506>/copy'
   *
   * Regarding '<S506>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* DataTypeConversion Block: '<S529>/Data Type Conversion'
   *
   * Regarding '<S529>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S506>/autosar_testpoint1' */

  /* S-Function Block: <S506>/autosar_testpoint1 */
  AFA_bAcvSpcInjModIni = AFAT_B.EepromReadAccess1_f;

  /* Switch: '<S529>/Switch' incorporates:
   *  Constant: '<S529>/Byp_Fonction_SC'
   *  Constant: '<S529>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bAcvSpcInjMod_B;
  } else {
    localSwitch_m5 = AFAT_B.EepromReadAccess1_f;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bAcvSpcInjModInport2' */
  Rte_Write_P_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod(localSwitch_m5);

  /* Switch: '<S509>/Switch' incorporates:
   *  Constant: '<S15>/Bool196'
   *  Constant: '<S509>/Byp_Fonction_SC'
   *  Constant: '<S509>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bAuthClsCanPurg_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bAuthClsCanPurgInport2' */
  Rte_Write_P_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg(localSwitch_m5);

  /* S-Function (NvRamReadAccess): '<S15>/EepromReadAccess4' */
  AFAT_B.EepromReadAccess4_n = AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV;

  /* DataTypeConversion Block: '<S528>/Data Type Conversion'
   *
   * Regarding '<S528>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S528>/Switch' incorporates:
   *  Constant: '<S528>/Byp_Fonction_SC'
   *  Constant: '<S528>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bEngStopAuth_B;
  } else {
    localSwitch_m5 = AFAT_B.EepromReadAccess4_n;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bEngStopAuthInport2' */
  Rte_Write_P_AFA_bEngStopAuth_AFA_bEngStopAuth(localSwitch_m5);

  /* Switch: '<S527>/Switch' incorporates:
   *  Constant: '<S15>/Bool198'
   *  Constant: '<S527>/Byp_Fonction_SC'
   *  Constant: '<S527>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_nEngLstObs_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_nEngLstObsInport2' */
  Rte_Write_P_AFA_nEngLstObs_AFA_nEngLstObs(localSwitch_h);

  /* S-Function (NvRamReadAccess): '<S15>/EepromReadAccess' */
  AFAT_B.EepromReadAccess_k = AFAT_sNV_Z1_CONST_16BIT.AFA_noAdpEfc_NV;

  /* DataTypeConversion Block: '<S508>/Data Type Conversion'
   *
   * Regarding '<S508>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S508>/Switch' incorporates:
   *  Constant: '<S508>/Byp_Fonction_SC'
   *  Constant: '<S508>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_noAdpEfc_B;
  } else {
    localSwitch_h = AFAT_B.EepromReadAccess_k;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_noAdpEfcInport2' */
  Rte_Write_P_AFA_noAdpEfc_AFA_noAdpEfc(localSwitch_h);

  /* S-Function (NvRamReadAccess): '<S15>/EepromReadAccess3' */
  AFAT_B.EepromReadAccess3_dg = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDone_NV;

  /* DataTypeConversion Block: '<S538>/Data Type Conversion'
   *
   * Regarding '<S538>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S538>/Switch' incorporates:
   *  Constant: '<S538>/Byp_Fonction_SC'
   *  Constant: '<S538>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_bf = AFA_noObsDone_B;
  } else {
    localSwitch_bf = AFAT_B.EepromReadAccess3_dg;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_noObsDoneInport2' */
  Rte_Write_P_AFA_noObsDone_AFA_noObsDone(localSwitch_bf);

  /* Switch: '<S537>/Switch' incorporates:
   *  Constant: '<S15>/Bool201'
   *  Constant: '<S537>/Byp_Fonction_SC'
   *  Constant: '<S537>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_rTotLdCorLstObs_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_rTotLdCorLstObsInport2' */
  Rte_Write_P_AFA_rTotLdCorLstObs_AFA_rTotLdCorLstObs(localSwitch_h);

  /* Switch: '<S524>/Switch' incorporates:
   *  Constant: '<S15>/Bool202'
   *  Constant: '<S524>/Byp_Fonction_SC'
   *  Constant: '<S524>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_c = AFA_tiDlyLstObs_B;
  } else {
    localSwitch_c = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_tiDlyLstObsInport2' */
  Rte_Write_P_AFA_tiDlyLstObs_AFA_tiDlyLstObs(localSwitch_c);

  /* Switch: '<S536>/Switch' incorporates:
   *  Constant: '<S15>/Bool203'
   *  Constant: '<S536>/Byp_Fonction_SC'
   *  Constant: '<S536>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bClsEGRRef_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bClsEGRRefInport2' */
  Rte_Write_P_AFA_bClsEGRRef_AFA_bClsEGRRef(localSwitch_m5);

  /* Switch: '<S535>/Switch' incorporates:
   *  Constant: '<S15>/Bool204'
   *  Constant: '<S535>/Byp_Fonction_SC'
   *  Constant: '<S535>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bFitPresAirExt_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bFitPresAirExtInport2' */
  Rte_Write_P_AFA_bFitPresAirExt_AFA_bFitPresAirExt(localSwitch_m5);

  /* Switch: '<S534>/Switch' incorporates:
   *  Constant: '<S15>/Bool205'
   *  Constant: '<S534>/Byp_Fonction_SC'
   *  Constant: '<S534>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bFitZeroPosnThr_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bFitZeroPosnThrInport2' */
  Rte_Write_P_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr(localSwitch_m5);

  /* Switch: '<S533>/Switch' incorporates:
   *  Constant: '<S15>/Bool206'
   *  Constant: '<S533>/Byp_Fonction_SC'
   *  Constant: '<S533>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bFitOpInVlvBol_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bFitOpInVlvBolInport2' */
  Rte_Write_P_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol(localSwitch_m5);

  /* Switch: '<S532>/Switch' incorporates:
   *  Constant: '<S15>/Bool207'
   *  Constant: '<S532>/Byp_Fonction_SC'
   *  Constant: '<S532>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bFitClsExVlvBol_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bFitClsExVlvBolInport2' */
  Rte_Write_P_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol(localSwitch_m5);

  /* Switch: '<S520>/Switch' incorporates:
   *  Constant: '<S15>/Bool208'
   *  Constant: '<S520>/Byp_Fonction_SC'
   *  Constant: '<S520>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_pDsThrPredFil_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_pDsThrPredFilInport2' */
  Rte_Write_P_AFA_pDsThrPredFil_AFA_pDsThrPredFil(localSwitch_h);

  /* Switch: '<S539>/Switch' incorporates:
   *  Constant: '<S15>/Bool209'
   *  Constant: '<S539>/Byp_Fonction_SC'
   *  Constant: '<S539>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_rAirPresFil_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_rAirPresFilInport2' */
  Rte_Write_P_AFA_rAirPresFil_AFA_rAirPresFil(localSwitch_h);

  /* Switch: '<S540>/Switch' incorporates:
   *  Constant: '<S15>/Bool210'
   *  Constant: '<S540>/Byp_Fonction_SC'
   *  Constant: '<S540>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_rAirLdCorFil_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_rAirLdCorFilInport2' */
  Rte_Write_P_AFA_rAirLdCorFil_AFA_rAirLdCorFil(localSwitch_h);

  /* Switch: '<S541>/Switch' incorporates:
   *  Constant: '<S15>/Bool211'
   *  Constant: '<S541>/Byp_Fonction_SC'
   *  Constant: '<S541>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h = AFA_pUsThrCorFil_B;
  } else {
    localSwitch_h = 0U;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_pUsThrCorFilInport2' */
  Rte_Write_P_AFA_pUsThrCorFil_AFA_pUsThrCorFil(localSwitch_h);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function6' */
  AFAT_B.SFunction6 = AFAT_sNV_Z1_CALIB_16BIT.AFA_arEffThrOfs_NV;

  /* DataTypeConversion Block: '<S510>/Data Type Conversion'
   *
   * Regarding '<S510>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S510>/Switch' incorporates:
   *  Constant: '<S510>/Byp_Fonction_SC'
   *  Constant: '<S510>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_b = AFA_arEffThrOfs_B;
  } else {
    localSwitch_b = AFAT_B.SFunction6;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_arEffThrOfsInport2' */
  Rte_Write_P_AFA_arEffThrOfs_AFA_arEffThrOfs(localSwitch_b);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function7' */
  AFAT_B.SFunction7 = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs1_NV;

  /* DataTypeConversion Block: '<S511>/Data Type Conversion'
   *
   * Regarding '<S511>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S511>/Switch' incorporates:
   *  Constant: '<S511>/Byp_Fonction_SC'
   *  Constant: '<S511>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_facArEffThrOfs1_B;
  } else {
    localSwitch_go = AFAT_B.SFunction7;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_facArEffThrOfs1Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function8' */
  AFAT_B.SFunction8 = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs2_NV;

  /* DataTypeConversion Block: '<S512>/Data Type Conversion'
   *
   * Regarding '<S512>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S512>/Switch' incorporates:
   *  Constant: '<S512>/Byp_Fonction_SC'
   *  Constant: '<S512>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_facArEffThrOfs2_B;
  } else {
    localSwitch_go = AFAT_B.SFunction8;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_facArEffThrOfs2Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function9' */
  AFAT_B.SFunction9 = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs3_NV;

  /* DataTypeConversion Block: '<S513>/Data Type Conversion'
   *
   * Regarding '<S513>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S513>/Switch' incorporates:
   *  Constant: '<S513>/Byp_Fonction_SC'
   *  Constant: '<S513>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_facArEffThrOfs3_B;
  } else {
    localSwitch_go = AFAT_B.SFunction9;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_facArEffThrOfs3Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function10' */
  AFAT_B.SFunction10 = AFAT_sNV_Z1_CALIB_8BIT.AFA_rCor_arEffEGRVlv_NV;

  /* DataTypeConversion Block: '<S514>/Data Type Conversion'
   *
   * Regarding '<S514>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S514>/Switch' incorporates:
   *  Constant: '<S514>/Byp_Fonction_SC'
   *  Constant: '<S514>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_rCor_arEffEGRVlv_B;
  } else {
    localSwitch_go = AFAT_B.SFunction10;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlvInport2' */
  Rte_Write_P_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function11' */
  AFAT_B.SFunction11 = AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkOpInVlvOfs_NV;

  /* DataTypeConversion Block: '<S515>/Data Type Conversion'
   *
   * Regarding '<S515>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S515>/Switch' incorporates:
   *  Constant: '<S515>/Byp_Fonction_SC'
   *  Constant: '<S515>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_agCkOpInVlvOfs_B;
  } else {
    localSwitch_go = AFAT_B.SFunction11;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_agCkOpInVlvOfsInport2' */
  Rte_Write_P_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function12' */
  AFAT_B.SFunction12 = AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkClsExVlvOfs_NV;

  /* DataTypeConversion Block: '<S516>/Data Type Conversion'
   *
   * Regarding '<S516>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S516>/Switch' incorporates:
   *  Constant: '<S516>/Byp_Fonction_SC'
   *  Constant: '<S516>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_agCkClsExVlvOfs_B;
  } else {
    localSwitch_go = AFAT_B.SFunction12;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_agCkClsExVlvOfsInport2' */
  Rte_Write_P_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs(localSwitch_go);

  /* Switch: '<S523>/Switch' incorporates:
   *  Constant: '<S15>/Bool225'
   *  Constant: '<S523>/Byp_Fonction_SC'
   *  Constant: '<S523>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_arEffEGRVlvOfs_B;
  } else {
    localSwitch_go = 0;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_arEffEGRVlvOfsInport2' */
  Rte_Write_P_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function4' */
  AFAT_B.SFunction4 = AFAT_sNV_Z1_CALIB_16BIT.AFA_facIvsInjGain_NV;

  /* DataTypeConversion Block: '<S517>/Data Type Conversion'
   *
   * Regarding '<S517>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S517>/Switch' incorporates:
   *  Constant: '<S517>/Byp_Fonction_SC'
   *  Constant: '<S517>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_b = AFA_facIvsInjGain_B;
  } else {
    localSwitch_b = AFAT_B.SFunction4;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_facIvsInjGainInport2' */
  Rte_Write_P_AFA_facIvsInjGain_AFA_facIvsInjGain(localSwitch_b);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function2' */
  AFAT_B.SFunction2 = AFAT_sNV_Z1_CALIB_8BIT.AFA_tiOffInj_NV;

  /* DataTypeConversion Block: '<S519>/Data Type Conversion'
   *
   * Regarding '<S519>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S519>/Switch' incorporates:
   *  Constant: '<S519>/Byp_Fonction_SC'
   *  Constant: '<S519>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_go = AFA_tiOffInj_B;
  } else {
    localSwitch_go = AFAT_B.SFunction2;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_tiOffInjInport2' */
  Rte_Write_P_AFA_tiOffInj_AFA_tiOffInj(localSwitch_go);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function5' */
  AFAT_B.SFunction5 = AFAT_sNV_Z1_CALIB_32BIT.AFA_facSlopInjGain_NV;

  /* DataTypeConversion Block: '<S521>/Data Type Conversion'
   *
   * Regarding '<S521>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S521>/Switch' incorporates:
   *  Constant: '<S521>/Byp_Fonction_SC'
   *  Constant: '<S521>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    locali = AFA_facSlopInjGain_B;
  } else {
    locali = AFAT_B.SFunction5;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_facSlopInjGainInport2' */
  Rte_Write_P_AFA_facSlopInjGain_AFA_facSlopInjGain(locali);

  /* Switch: '<S525>/Switch' incorporates:
   *  Constant: '<S15>/Bool222'
   *  Constant: '<S525>/Byp_Fonction_SC'
   *  Constant: '<S525>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bIdcCohLstObs_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bIdcCohLstObsInport2' */
  Rte_Write_P_AFA_bIdcCohLstObs_AFA_bIdcCohLstObs(localSwitch_m5);

  /* Switch: '<S526>/Switch' incorporates:
   *  Constant: '<S15>/Bool223'
   *  Constant: '<S526>/Byp_Fonction_SC'
   *  Constant: '<S526>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_m5 = AFA_bInnovTestCohDone_B;
  } else {
    localSwitch_m5 = FALSE;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_bInnovTestCohDoneInport2' */
  Rte_Write_P_AFA_bInnovTestCohDone_AFA_bInnovTestCohDone(localSwitch_m5);

  /* S-Function (NvRamReadAccess): '<S15>/S-Function3' */
  {
    UInt32 locali;
    for (locali=0 ; locali <8; locali++) {
      AFAT_B.SFunction3_p[locali] =
        AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali];
    }
  }

  /* DataTypeConversion Block: '<S522>/Data Type Conversion'
   *
   * Regarding '<S522>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* Switch: '<S522>/Switch' incorporates:
   *  Constant: '<S522>/Byp_Fonction_SC'
   *  Constant: '<S522>/Int_BypC'
   */
  for (locali = 0; locali < 8; locali++) {
    if (AFAT_ACTIVE_BYP_C) {
      localSwitch_g[locali] = AFA_prm_covErrEstim_B[(locali)];
    } else {
      localSwitch_g[locali] = AFAT_B.SFunction3_p[(locali)];
    }
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtAFA_prm_covErrEstimInport2' */
  Rte_Write_P_AFA_prm_covErrEstim_AFA_prm_covErrEstim(&localSwitch_g);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write49' incorporates:
   *  Constant: '<S15>/Bool'
   */

  /* S-Function Block: <S15>/autosar_irv_write49 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_rOpClsThrBolHld_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S475>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool'
   */

  /* S-Function Block: <S475>/autosar_testpoint1 */
  AFA_rOpClsThrBolHld_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write1' incorporates:
   *  Constant: '<S15>/Bool1'
   */

  /* S-Function Block: <S15>/autosar_irv_write1 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pAirExtEstimHld_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S476>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool1'
   */

  /* S-Function Block: <S476>/autosar_testpoint1 */
  AFA_pAirExtEstimHld_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write11' incorporates:
   *  Constant: '<S15>/Bool130'
   */

  /* S-Function Block: <S15>/autosar_irv_write11 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_bAdpClcRstReqHld_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S472>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool130'
   */

  /* S-Function Block: <S472>/autosar_testpoint1 */
  AFA_bAdpClcRstReqHld_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S474>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool130'
   */

  /* S-Function Block: <S474>/autosar_testpoint1 */
  AFA_bAdpClcRstReqIni = FALSE;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write22' incorporates:
   *  Constant: '<S15>/Bool158'
   */

  /* S-Function Block: <S15>/autosar_irv_write22 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_agCkClsExVlvEstimRef1Fil_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S477>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool158'
   */

  /* S-Function Block: <S477>/autosar_testpoint1 */
  AFA_agCkClsExVlvEstimRef1Fil = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write23' incorporates:
   *  Constant: '<S15>/Bool159'
   */

  /* S-Function Block: <S15>/autosar_irv_write23 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_facSlopEfcCorFil_irv(0U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S478>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool159'
   */

  /* S-Function Block: <S478>/autosar_testpoint1 */
  AFA_facSlopEfcCorFil_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write24' incorporates:
   *  Constant: '<S15>/Bool160'
   */

  /* S-Function Block: <S15>/autosar_irv_write24 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_mFuReqFil_irv(0U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S479>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool160'
   */

  /* S-Function Block: <S479>/autosar_testpoint1 */
  AFA_mFuReqFil_IRV_MP = 0U;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write25' incorporates:
   *  Constant: '<S15>/Bool161'
   */

  /* S-Function Block: <S15>/autosar_irv_write25 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_nEngFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S480>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool161'
   */

  /* S-Function Block: <S480>/autosar_testpoint1 */
  AFA_nEngFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write26' incorporates:
   *  Constant: '<S15>/Bool162'
   */

  /* S-Function Block: <S15>/autosar_irv_write26 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pAirExtEstimFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S481>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool162'
   */

  /* S-Function Block: <S481>/autosar_testpoint1 */
  AFA_pAirExtEstimFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write27' incorporates:
   *  Constant: '<S15>/Bool163'
   */

  /* S-Function Block: <S15>/autosar_irv_write27 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pDsThrCorFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S482>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool163'
   */

  /* S-Function Block: <S482>/autosar_testpoint1 */
  AFA_pDsThrCorFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write28' incorporates:
   *  Constant: '<S15>/Bool164'
   */

  /* S-Function Block: <S15>/autosar_irv_write28 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pDsThrEstimErrFil_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S483>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool164'
   */

  /* S-Function Block: <S483>/autosar_testpoint1 */
  AFA_pDsThrEstimErrFil_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write29' incorporates:
   *  Constant: '<S15>/Bool165'
   */

  /* S-Function Block: <S15>/autosar_irv_write29 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pDsThrEstimFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S485>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool165'
   */

  /* S-Function Block: <S485>/autosar_testpoint1 */
  AFA_pDsThrEstimFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write30' incorporates:
   *  Constant: '<S15>/Bool166'
   */

  /* S-Function Block: <S15>/autosar_irv_write30 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pDsThrPred_facVlvOvlpFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S486>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool166'
   */

  /* S-Function Block: <S486>/autosar_testpoint1 */
  AFA_pDsThrPred_facVlvOvlpFil = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write31' incorporates:
   *  Constant: '<S15>/Bool167'
   */

  /* S-Function Block: <S15>/autosar_irv_write31 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_pExMnfEstimFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S487>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool167'
   */

  /* S-Function Block: <S487>/autosar_testpoint1 */
  AFA_pExMnfEstimFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write92' incorporates:
   *  Constant: '<S15>/Bool180'
   */

  /* S-Function Block: <S15>/autosar_irv_write92 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_rInMassFlowFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S489>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool180'
   */

  /* S-Function Block: <S489>/autosar_testpoint1 */
  AFA_rInMassFlowFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write93' incorporates:
   *  Constant: '<S15>/Bool181'
   */

  /* S-Function Block: <S15>/autosar_irv_write93 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_rOpSIFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S490>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool181'
   */

  /* S-Function Block: <S490>/autosar_testpoint1 */
  AFA_rOpSIFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write94' incorporates:
   *  Constant: '<S15>/Bool182'
   */

  /* S-Function Block: <S15>/autosar_irv_write94 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_rTotLdExCorFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S491>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool182'
   */

  /* S-Function Block: <S491>/autosar_testpoint1 */
  AFA_rTotLdExCorFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write95' incorporates:
   *  Constant: '<S15>/Bool183'
   */

  /* S-Function Block: <S15>/autosar_irv_write95 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_tAirUsInVlvEstimFil_irv(28544U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S492>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool183'
   */

  /* S-Function Block: <S492>/autosar_testpoint1 */
  AFA_tAirUsInVlvEstimFil_IRV_MP = 28544U;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write96' incorporates:
   *  Constant: '<S15>/Bool184'
   */

  /* S-Function Block: <S15>/autosar_irv_write96 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_tCoMesFil_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S493>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool184'
   */

  /* S-Function Block: <S493>/autosar_testpoint1 */
  AFA_tCoMesFil_IRV_MP = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write97' incorporates:
   *  Constant: '<S15>/Bool185'
   */

  /* S-Function Block: <S15>/autosar_irv_write97 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_tExMnfEstimFil_irv(7136U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S495>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool185'
   */

  /* S-Function Block: <S495>/autosar_testpoint1 */
  AFA_tExMnfEstimFil_IRV_MP = 7136U;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write148' incorporates:
   *  Constant: '<S15>/Bool187'
   */

  /* S-Function Block: <S15>/autosar_irv_write148 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_agCkClsInVlvEstimRef1Fil_irv(1344U);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S497>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool187'
   */

  /* S-Function Block: <S497>/autosar_testpoint1 */
  AFA_agCkClsInVlvEstimRef1Fil = 1344U;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write149' incorporates:
   *  Constant: '<S15>/Bool188'
   */

  /* S-Function Block: <S15>/autosar_irv_write149 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_agCkOpInVlvEstimRef1Fil_irv(0);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S498>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool188'
   */

  /* S-Function Block: <S498>/autosar_testpoint1 */
  AFA_agCkOpInVlvEstimRef1Fil = 0;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write150' incorporates:
   *  Constant: '<S15>/Bool189'
   */

  /* S-Function Block: <S15>/autosar_irv_write150 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_arEffAdpEGRVlvFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S499>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool189'
   */

  /* S-Function Block: <S499>/autosar_testpoint1 */
  AFA_arEffAdpEGRVlvFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write151' incorporates:
   *  Constant: '<S15>/Bool190'
   */

  /* S-Function Block: <S15>/autosar_irv_write151 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_arEffAdpThrFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S500>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool190'
   */

  /* S-Function Block: <S500>/autosar_testpoint1 */
  AFA_arEffAdpThrFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write152' incorporates:
   *  Constant: '<S15>/Bool191'
   */

  /* S-Function Block: <S15>/autosar_irv_write152 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_arEffEGRVlvFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S501>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool191'
   */

  /* S-Function Block: <S501>/autosar_testpoint1 */
  AFA_arEffEGRVlvFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write14' incorporates:
   *  Constant: '<S15>/Bool2'
   */

  /* S-Function Block: <S15>/autosar_irv_write14 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_rOpClsEGRVlvBolHld_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S484>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool2'
   */

  /* S-Function Block: <S484>/autosar_testpoint1 */
  AFA_rOpClsEGRVlvBolHld_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write15' incorporates:
   *  Constant: '<S15>/Bool3'
   */

  /* S-Function Block: <S15>/autosar_irv_write15 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_agCkOpInVlvBolHld_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S488>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool3'
   */

  /* S-Function Block: <S488>/autosar_testpoint1 */
  AFA_agCkOpInVlvBolHld_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write16' incorporates:
   *  Constant: '<S15>/Bool4'
   */

  /* S-Function Block: <S15>/autosar_irv_write16 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_agCkClsExVlvBolHld_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S494>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool4'
   */

  /* S-Function Block: <S494>/autosar_testpoint1 */
  AFA_agCkClsExVlvBolHld_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write6' incorporates:
   *  Constant: '<S15>/Bool46'
   */

  /* S-Function Block: <S15>/autosar_irv_write6 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_nEngCorFil_irv(((UInt16)0U));

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S505>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool46'
   */

  /* S-Function Block: <S505>/autosar_testpoint1 */
  AFA_nEngCorFil_IRV_MP = ((UInt16)0U);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write56' incorporates:
   *  Constant: '<S15>/Bool91'
   */

  /* S-Function Block: <S15>/autosar_irv_write56 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_bIdcInv_covPredInnov_irv(FALSE);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S507>/autosar_testpoint1' incorporates:
   *  Constant: '<S15>/Bool91'
   */

  /* S-Function Block: <S507>/autosar_testpoint1 */
  AFA_bIdcInv_covPredInnov_IRV_MP = FALSE;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S504>/autosar_testpoint1' */

  /* S-Function Block: <S504>/autosar_testpoint1 */
  {
    SInt32 i1;
    const SInt16 *u0 = AFAT_B.SFunction1_d;
    for (i1=0; i1 < 8; i1++) {
      AFA_prm_rErrIni[i1] = u0[i1];
    }
  }

  /* S-Function (NvRamReadAccess): '<S15>/S-Function13' */
  AFAT_B.SFunction13 = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV;

  /* S-Function Block: '<S448>/FixPt Data Type Propagation'
   *
   * Regarding '<S448>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S448>/FixPt Gateway Out'
   *
   * Regarding '<S448>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion Block: '<S496>/copy'
   *
   * Regarding '<S496>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S503>/copy'
   *
   * Regarding '<S503>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write147' */

  /* S-Function Block: <S15>/autosar_irv_write147 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_noObsDoneIdlIni_irv(AFAT_B.SFunction13);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S496>/autosar_testpoint1' */

  /* S-Function Block: <S496>/autosar_testpoint1 */
  AFA_noObsDoneIdlIni = AFAT_B.SFunction13;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S503>/autosar_testpoint1' */

  /* S-Function Block: <S503>/autosar_testpoint1 */
  AFA_noObsDoneIdlIni_IRV_MP = AFAT_B.SFunction13;

  /* S-Function (NvRamReadAccess): '<S15>/EepromReadAccess2' */
  AFAT_B.EepromReadAccess2_c1 = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV;

  /* S-Function Block: '<S465>/FixPt Data Type Propagation'
   *
   * Regarding '<S465>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S465>/FixPt Gateway Out'
   *
   * Regarding '<S465>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion Block: '<S471>/copy'
   *
   * Regarding '<S471>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S473>/copy'
   *
   * Regarding '<S473>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S15>/autosar_irv_write12' */

  /* S-Function Block: <S15>/autosar_irv_write12 */
  Rte_IrvWrite_RE_AFAT_001_MSE_AFA_noObsSpcInjMod_irv
    (AFAT_B.EepromReadAccess2_c1);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S471>/autosar_testpoint1' */

  /* S-Function Block: <S471>/autosar_testpoint1 */
  AFA_noObsSpcInjModIni = AFAT_B.EepromReadAccess2_c1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S473>/autosar_testpoint1' */

  /* S-Function Block: <S473>/autosar_testpoint1 */
  AFA_noObsSpcInjMod_IRV_MP = AFAT_B.EepromReadAccess2_c1;
}

/*
 * Output and update for atomic system:
 *    '<S84>/Diag_Vect2Mat'
 *    '<S390>/Diag_Vect2Mat'
 */
void Diag_Vect2Mat(const UInt16 rtu_u[8], UInt16 rty_y[64])
{
  SInt32 locali;

  /* Embedded MATLAB: '<S84>/Diag_Vect2Mat' */
  /* Embedded MATLAB Function 'Group_005-003-013-032/F02_reinit_algo_adaptation_(005_DRE)/Diag_Vect2Mat': '<S86>:1' */
  /* '<S86>:1:2' */
  memset((void *)(&rty_y[0]), (SInt32)0U, sizeof(UInt16) << 6U);
  for (locali = 0; locali < 8; locali++) {
    rty_y[locali + (locali << 3)] = rtu_u[(locali)];
  }
}

/* Output and update for function-call system: '<S9>/F01_lire_adaptatifs_en_eeprom_(026_MSE)' */
void F01_lire_adaptatifs_en_eeprom_0(SInt32 controlPortIdx)
{
  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess' */
  AFAT_B.EepromReadAccess_i = AFAT_sNV_Z1_CALIB_16BIT.AFA_facIvsInjGain_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess1' */
  AFAT_B.EepromReadAccess1_l = AFAT_sNV_Z1_CALIB_8BIT.AFA_tiOffInj_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess2' */
  AFAT_B.EepromReadAccess2 = AFAT_sNV_Z1_CALIB_32BIT.AFA_facSlopInjGain_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess3' */
  AFAT_B.EepromReadAccess3 = AFAT_sNV_Z1_CALIB_16BIT.AFA_arEffThrOfs_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess4' */
  AFAT_B.EepromReadAccess4_a = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs1_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess5' */
  AFAT_B.EepromReadAccess5_o = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs2_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess6' */
  AFAT_B.EepromReadAccess6 = AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs3_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess7' */
  AFAT_B.EepromReadAccess7 = AFAT_sNV_Z1_CALIB_8BIT.AFA_rCor_arEffEGRVlv_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess8' */
  AFAT_B.EepromReadAccess8 = AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkOpInVlvOfs_NV;

  /* S-Function (NvRamReadAccess): '<S45>/EepromReadAccess9' */
  AFAT_B.EepromReadAccess9 = AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkClsExVlvOfs_NV;

  /* ModelReference: '<S45>/AFA_F01_lire_adaptatifs_en_eeprom' */
  mr_AFA_F01_lire_adaptatifs_en_e(&AFAT_B.EepromReadAccess_i,
    &AFAT_B.EepromReadAccess1_l, &AFAT_B.EepromReadAccess2,
    &AFAT_B.EepromReadAccess3, &AFAT_B.EepromReadAccess4_a,
    &AFAT_B.EepromReadAccess5_o, &AFAT_B.EepromReadAccess6,
    &AFAT_B.EepromReadAccess7, &AFAT_B.EepromReadAccess8,
    &AFAT_B.EepromReadAccess9, &AFAT_B.AFA_facIvsInjGain_merge_c,
    &AFAT_B.AFA_tiOffInj_merge_j, &AFAT_B.AFA_facSlopInjGain_merge_mi,
    &AFAT_B.AFA_arEffThrOfs_merge_a, &AFAT_B.AFA_facArEffThrOfs1_merge_m,
    &AFAT_B.AFA_facArEffThrOfs2_merge_a, &AFAT_B.AFA_facArEffThrOfs3_merge_p,
    &AFAT_B.AFA_rCor_arEffEGRVlv_merge_k, &AFAT_B.AFA_agCkOpInVlvOfs_merge_k0,
    &AFAT_B.AFA_agCkClsExVlvOfs_merge_l);
}

/* Start for exported function: RE_AFAT_002_MSE */
void RE_AFAT_002_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_EveRst_AFAClcCtl_(002_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_EveRst_AFAClcCtl_(002_MSE)':
   *  1. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_155.01 ;
   *  2. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_158.01 ;
   *  3. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_223.01 ;
   *  4. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_225.01 ;
   *  5. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_237.01 ;
   *  6. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_206.01 ;
   *  7. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_222.01 ;
   *  8. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  9. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_241.01 ;
   *  10. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_243.01 ;
   *  11. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_246.01 ;
   *  12. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  13. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_248.01 ;
   *  14. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  15. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_250.01 ;
   *  16. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  17. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_279.01 ;
   *  18. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  19. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_307.01 ;
   *  20. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_343.02 ;
   */

  /* Start for Embedded MATLAB: '<S9>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S9>/ELSE'
   *  Start for SubSystem: '<S9>/F01_init_algo_adaptation'
   *
   * Block requirements for '<S9>/ELSE':
   *  1. SubSystem "F01_init_algo_adaptation_code" !Trace_To : VEMS_R_11_04467_004.01 ;
   *
   * Block requirements for '<S9>/F01_init_algo_adaptation':
   *  1. SubSystem "F01_init_algo_adaptation" !Trace_To : VEMS_R_11_04467_004.01 ;
   */

  /* Start for ifaction SubSystem: '<S44>/F02_reinit_only_current_cycle' *
   * Block requirements for '<S44>/F02_reinit_only_current_cycle':
   *  1. SubSystem "F02_reinit_only_current_cycle" !Trace_To : VEMS_R_11_04467_008.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S52>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S47>/F02_common_init_algo3_(003_DRE)'
   *  Start for SubSystem: '<S52>/F01_read_adaption_parameters'
   *  Start for SubSystem: '<S9>/F01_add_cranking_noise_(015_MSE)'
   *
   * Block requirements for '<S47>/F02_common_init_algo3_(003_DRE)':
   *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
   *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
   *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
   *
   * Block requirements for '<S52>/F01_read_adaption_parameters':
   *  1. SubSystem "F01_read_adaption_parameters" !Trace_To : VEMS_R_11_04467_009.01 ;
   *
   * Block requirements for '<S9>/F01_add_cranking_noise_(015_MSE)':
   *  1. SubSystem "F01_add_cranking_noise_(015_MSE)" !Trace_To : VEMS_R_11_04467_048.01 ;
   *  2. SubSystem "F01_add_cranking_noise_(015_MSE)" !Trace_To : VEMS_R_11_04467_320.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S70>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S47>/F00_init_scruter_environ_adaptation(013_DRE)'
   *  Start for SubSystem: '<S47>/F03_reset_cumulated_model_noise_v(032_DRE)'
   *
   * Block requirements for '<S47>/F00_init_scruter_environ_adaptation(013_DRE)':
   *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
   *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
   *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
   *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
   *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
   *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
   *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
   *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
   *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
   *
   * Block requirements for '<S47>/F03_reset_cumulated_model_noise_v(032_DRE)':
   *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
   *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
   */

  /* end of Start for SubSystem: '<S44>/F02_reinit_only_current_cycle' */

  /* Start for ifaction SubSystem: '<S44>/F01_reinit_whole_algo_adapt' *
   * Block requirements for '<S44>/F01_reinit_whole_algo_adapt':
   *  1. SubSystem "F01_reinit_whole_algo_adapt" !Trace_To : VEMS_R_11_04467_005.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S51>/Function-Call Generator3' incorporates:
   *  Start for SubSystem: '<S48>/F02_reinit_algo_adaptation_(005_DRE)'
   */

  /* Start for S-Function (fcncallgen): '<S84>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S85>/F02_common_init_algo3_(003_DRE)'
   *
   * Block requirements for '<S85>/F02_common_init_algo3_(003_DRE)':
   *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
   *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
   *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S98>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S85>/F00_init_scruter_environ_adaptation(013_DRE)'
   *  Start for SubSystem: '<S85>/F03_reset_cumulated_model_noise_v(032_DRE)'
   *
   * Block requirements for '<S85>/F00_init_scruter_environ_adaptation(013_DRE)':
   *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
   *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
   *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
   *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
   *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
   *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
   *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
   *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
   *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
   *
   * Block requirements for '<S85>/F03_reset_cumulated_model_noise_v(032_DRE)':
   *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
   *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
   */

  /* Start for ifaction SubSystem: '<S51>/F01_call_reinit_adaption_terms' *
   * Block requirements for '<S51>/F01_call_reinit_adaption_terms':
   *  1. SubSystem "F01_call_reinit_adaption_terms" !Trace_To : VEMS_R_11_04467_006.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S58>/Function-Call Generator3' incorporates:
   *  Start for SubSystem: '<S9>/F02_Afa_adapt_terms_reset_(027_MSE)'
   *
   * Block requirements for '<S9>/F02_Afa_adapt_terms_reset_(027_MSE)':
   *  1. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_113.01 ;
   *  2. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_201.01 ;
   *  3. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_202.01 ;
   *  4. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_203.01 ;
   *  5. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  6. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_215.01 ;
   *  7. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_216.01 ;
   *  8. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_217.01 ;
   *  9. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_218.01 ;
   *  10. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_231.01 ;
   *  11. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_234.01 ;
   *  12. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_252.01 ;
   *  13. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_253.01 ;
   *  14. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_254.01 ;
   *  15. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_255.01 ;
   *  16. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_256.01 ;
   *  17. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_257.01 ;
   *  18. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_258.01 ;
   *  19. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_259.01 ;
   *  20. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_260.01 ;
   *  21. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_332.01 ;
   */

  /* end of Start for SubSystem: '<S51>/F01_call_reinit_adaption_terms' */

  /* end of Start for SubSystem: '<S44>/F01_reinit_whole_algo_adapt' */
}

/* Output and update for exported function: RE_AFAT_002_MSE */
void RE_AFAT_002_MSE(void)
{
  /* local block i/o variables */
  UInt16 localAFA_F01_add_cranking_noise[8];
  UInt16 localDataStoreRead[64];
  UInt16 localAFAT_F03_reset_cumulated_m[8];
  UInt16 localDataStoreRead_p[64];
  UInt16 localAFAT_F03_reset_cumulated_i[8];
  UInt16 localy_k[64];
  UInt16 localSignalConversion[8];
  UInt16 localAFAT_F00_init_scruter_envi;
  UInt16 localAFAT_F00_init_scruter_en_b;
  UInt16 localAFAT_F00_init_scruter_en_d;
  UInt16 localAFAT_F00_init_scruter_en_f;
  UInt16 localAFAT_F00_init_scruter_en_k;
  UInt16 localAFAT_F00_init_scruter_en_p;
  UInt16 localAFAT_F00_init_scruter_e_kp;
  UInt16 localAFAT_F00_init_scruter_e_f0;
  UInt16 localAFAT_F00_init_scruter_e_k0;
  UInt16 localAFAT_F00_init_scruter_en_m;
  Boolean localSignalConversion_l;
  Boolean localSwitch_iy;
  Boolean localSwitch_bc;
  Boolean localSwitch_oq;
  Boolean localSwitch_ad;
  Boolean localSwitch_nv;
  UInt16 localSwitch_nq;
  SInt8 localSwitch_c0;
  SInt8 localSwitch_h3;
  SInt8 localSwitch_ny;
  SInt16 localSwitch_l3;
  SInt8 localSwitch_lb;
  SInt8 localSwitch_eh;
  SInt8 localSwitch_cq;
  SInt16 localSwitch_e1;
  SInt8 localSwitch_ehn;
  SInt8 localSwitch_jy;
  UInt16 localy[64];
  SInt16 localSignalConversion4[8];
  Boolean localAFA_bAcvSpcInjMod_merge_j;
  Boolean localAFA_bAuthClsCanPurg_merge_;
  Boolean localAFA_bEngStopAuth_merge_c;
  UInt8 localAFA_noAdpClcRst_merge_e;
  UInt16 localAFA_noAdpEfc_merge_g;
  UInt8 localAFA_noObsDone_merge_l;
  UInt8 localAFA_noRstAdpVal_merge_l;
  UInt16 localAFA_prm_covErrEstim_merge_[8];
  UInt32 localAFA_tiDlyLstObs_merge_c;
  SInt32 locali;
  SInt32 locali_0;

  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_EveRst_AFAClcCtl_(002_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_EveRst_AFAClcCtl_(002_MSE)':
   *  1. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_155.01 ;
   *  2. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_158.01 ;
   *  3. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_223.01 ;
   *  4. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_225.01 ;
   *  5. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_237.01 ;
   *  6. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_206.01 ;
   *  7. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_222.01 ;
   *  8. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  9. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_241.01 ;
   *  10. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_243.01 ;
   *  11. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_246.01 ;
   *  12. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  13. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_248.01 ;
   *  14. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  15. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_250.01 ;
   *  16. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  17. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_279.01 ;
   *  18. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  19. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_307.01 ;
   *  20. SubSystem "RE_AFAT_EveRst_AFAClcCtl_(002_MSE)" !Trace_To : VEMS_R_11_04467_343.02 ;
   */

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bAdpClcRstReqOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bAdpClcRstReq'
   */
  Rte_Read_R_AFAMgt_bAdpClcRstReq_AFAMgt_bAdpClcRstReq
    (&AFAT_B.TmpSignalConversionAtAFAMgt_b_f);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFAMgt_bAdpOfsRstReqOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bAdpOfsRstReq'
   */
  Rte_Read_R_AFAMgt_bAdpOfsRstReq_AFAMgt_bAdpOfsRstReq
    (&AFAT_B.TmpSignalConversionAtAFAMgt_b_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noRstAdpVal_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noRstAdpVal_INPUT'
   */
  Rte_Read_R_AFA_noRstAdpVal_AFA_noRstAdpVal(&AFA_noRstAdpValPrev);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtThrLrn_rOpClsThrBolOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpClsThrBol'
   */
  Rte_Read_R_ThrLrn_rOpClsThrBol_ThrLrn_rOpClsThrBol
    (&AFAT_B.TmpSignalConversionAtThrLrn_r_m);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtUsThrM_pAirExtEstimOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExtEstim'
   */
  Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim
    (&AFAT_B.TmpSignalConversionAtUsThrM_p_o);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtEGRVlv_rOpClsEGRVlvBolOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_rOpClsEGRVlvBol'
   */
  Rte_Read_R_EGRVlv_rOpClsEGRVlvBol_EGRVlv_rOpClsEGRVlvBol
    (&AFAT_B.TmpSignalConversionAtEGRVlv_r_o);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtVlvAct_prm_agCkOpInVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkOpInVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_p_o);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtVlvAct_prm_agCkClsExVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkClsExVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_p_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpClcRst_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpClcRst_INPUT'
   */
  Rte_Read_R_AFA_noAdpClcRst_AFA_noAdpClcRst
    (&AFAT_B.TmpSignalConversionAtAFA_noAd_g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_agCkClsExVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkClsExVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_agCk_j);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_agCkOpInVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkOpInVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_agCk_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_arEffEGRVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffEGRVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_arEf_i);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_arEffThrOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffThrOfs_INPUT'
   */
  Rte_Read_R_AFA_arEffThrOfs_AFA_arEffThrOfs
    (&AFAT_B.TmpSignalConversionAtAFA_arEf_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bAcvSpcInjMod_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAcvSpcInjMod_INPUT'
   */
  Rte_Read_R_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod
    (&AFAT_B.TmpSignalConversionAtAFA_bAcv_h);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bAuthClsCanPurg_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAuthClsCanPurg_INPUT'
   */
  Rte_Read_R_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg
    (&AFAT_B.TmpSignalConversionAtAFA_bAut_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bClsEGRRef_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bClsEGRRef_INPUT'
   */
  Rte_Read_R_AFA_bClsEGRRef_AFA_bClsEGRRef
    (&AFAT_B.TmpSignalConversionAtAFA_bCls_d);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bEngStopAuth_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bEngStopAuth_INPUT'
   */
  Rte_Read_R_AFA_bEngStopAuth_AFA_bEngStopAuth
    (&AFAT_B.TmpSignalConversionAtAFA_bEng_i);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitClsExVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitClsExVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol
    (&AFAT_B.TmpSignalConversionAtAFA_bFit_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitOpInVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitOpInVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol
    (&AFAT_B.TmpSignalConversionAtAFA_bFit_k);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitPresAirExt_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitPresAirExt_INPUT'
   */
  Rte_Read_R_AFA_bFitPresAirExt_AFA_bFitPresAirExt
    (&AFAT_B.TmpSignalConversionAtAFA_bFit_o);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitZeroPosnThr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitZeroPosnThr_INPUT'
   */
  Rte_Read_R_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr
    (&AFAT_B.TmpSignalConversionAtAFA_bFi_kz);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs1_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs1_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1
    (&AFAT_B.TmpSignalConversionAtAFA_facA_m);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs2_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs2_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2
    (&AFAT_B.TmpSignalConversionAtAFA_facA_h);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs3_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs3_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3
    (&AFAT_B.TmpSignalConversionAtAFA_facA_j);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facIvsInjGain_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facIvsInjGain_INPUT'
   */
  Rte_Read_R_AFA_facIvsInjGain_AFA_facIvsInjGain
    (&AFAT_B.TmpSignalConversionAtAFA_facI_j);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facSlopInjGain_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facSlopInjGain_INPUT'
   */
  Rte_Read_R_AFA_facSlopInjGain_AFA_facSlopInjGain
    (&AFAT_B.TmpSignalConversionAtAFA_facS_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpEfc_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpEfc_INPUT'
   */
  Rte_Read_R_AFA_noAdpEfc_AFA_noAdpEfc(&AFAT_B.TmpSignalConversionAtAFA_noAd_n);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpEfcAst_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpEfcAst_INPUT'
   */
  Rte_Read_R_AFA_noAdpEfcAst_AFA_noAdpEfcAst
    (&AFAT_B.TmpSignalConversionAtAFA_noAd_p);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noObsDone_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noObsDone_INPUT'
   */
  Rte_Read_R_AFA_noObsDone_AFA_noObsDone(&AFAT_B.TmpSignalConversionAtAFA_noOb_a);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_prm_covErrEstim_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_prm_covErrEstim_INPUT'
   */
  Rte_Read_R_AFA_prm_covErrEstim_AFA_prm_covErrEstim
    (&AFAT_B.TmpSignalConversionAtAFA_prm__g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlv_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_rCor_arEffEGRVlv_INPUT'
   */
  Rte_Read_R_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv
    (&AFAT_B.TmpSignalConversionAtAFA_rCo_aa);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_tiDlyLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiDlyLstObs_INPUT'
   */
  Rte_Read_R_AFA_tiDlyLstObs_AFA_tiDlyLstObs
    (&AFAT_B.TmpSignalConversionAtAFA_tiDl_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_tiOffInj_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiOffInj_INPUT'
   */
  Rte_Read_R_AFA_tiOffInj_AFA_tiOffInj(&AFAT_B.TmpSignalConversionAtAFA_tiOf_p);

  /* Embedded MATLAB: '<S9>/Task_sceduler' incorporates:
   *  SubSystem: '<S9>/ELSE'
   *  SubSystem: '<S9>/F01_init_algo_adaptation'
   *
   * Block requirements for '<S9>/ELSE':
   *  1. SubSystem "F01_init_algo_adaptation_code" !Trace_To : VEMS_R_11_04467_004.01 ;
   *
   * Block requirements for '<S9>/F01_init_algo_adaptation':
   *  1. SubSystem "F01_init_algo_adaptation" !Trace_To : VEMS_R_11_04467_004.01 ;
   */
  /* Embedded MATLAB Function 'AFAT/RE_AFAT_EveRst_AFAClcCtl_(002_MSE)/Task_sceduler': '<S49>:1' */
  /* '<S49>:1:5' */

  /* Inport: '<S42>/AFA_agCkClsExVlvOfs_INPUT' */
  AFAT_B.AFA_agCkClsExVlvOfs_merge_l = AFAT_B.TmpSignalConversionAtAFA_agCk_j;

  /* Inport: '<S42>/AFA_agCkOpInVlvOfs_INPUT' */
  AFAT_B.AFA_agCkOpInVlvOfs_merge_k0 = AFAT_B.TmpSignalConversionAtAFA_agCk_n;

  /* Inport: '<S42>/AFA_arEffEGRVlvOfs_INPUT' */
  AFAT_B.AFA_arEffEGRVlvOfs_merge_h = AFAT_B.TmpSignalConversionAtAFA_arEf_i;

  /* Inport: '<S42>/AFA_arEffThrOfs_INPUT' */
  AFAT_B.AFA_arEffThrOfs_merge_a = AFAT_B.TmpSignalConversionAtAFA_arEf_e;

  /* Inport: '<S42>/AFA_bClsEGRRef_INPUT' */
  AFAT_B.AFA_bClsEGRRef_merge_a0 = AFAT_B.TmpSignalConversionAtAFA_bCls_d;

  /* Inport: '<S42>/AFA_bFitClsExVlvBol_INPUT' */
  AFAT_B.AFA_bFitClsExVlvBol_merge_o = AFAT_B.TmpSignalConversionAtAFA_bFit_p;

  /* Inport: '<S42>/AFA_bFitOpInVlvBol_INPUT' */
  AFAT_B.AFA_bFitOpInVlvBol_merge_k = AFAT_B.TmpSignalConversionAtAFA_bFit_k;

  /* Inport: '<S42>/AFA_bFitPresAirExt_INPUT' */
  AFAT_B.AFA_bFitPresAirExt_merge_p = AFAT_B.TmpSignalConversionAtAFA_bFit_o;

  /* Inport: '<S42>/AFA_bFitZeroPosnThr_INPUT' */
  AFAT_B.AFA_bFitZeroPosnThr_merge_o = AFAT_B.TmpSignalConversionAtAFA_bFi_kz;

  /* Inport: '<S42>/AFA_facArEffThrOfs1_INPUT' */
  AFAT_B.AFA_facArEffThrOfs1_merge_m = AFAT_B.TmpSignalConversionAtAFA_facA_m;

  /* Inport: '<S42>/AFA_facArEffThrOfs2_INPUT' */
  AFAT_B.AFA_facArEffThrOfs2_merge_a = AFAT_B.TmpSignalConversionAtAFA_facA_h;

  /* Inport: '<S42>/AFA_facArEffThrOfs3_INPUT' */
  AFAT_B.AFA_facArEffThrOfs3_merge_p = AFAT_B.TmpSignalConversionAtAFA_facA_j;

  /* Inport: '<S42>/AFA_facIvsInjGain_INPUT' */
  AFAT_B.AFA_facIvsInjGain_merge_c = AFAT_B.TmpSignalConversionAtAFA_facI_j;

  /* Inport: '<S42>/AFA_facSlopInjGain_INPUT' */
  AFAT_B.AFA_facSlopInjGain_merge_mi = AFAT_B.TmpSignalConversionAtAFA_facS_e;

  /* Inport: '<S42>/AFA_noAdpClcRst_INPUT' */
  localAFA_noAdpClcRst_merge_e = AFAT_B.TmpSignalConversionAtAFA_noAd_g;

  /* Inport: '<S42>/AFA_noRstAdpVal_INPUT' */
  localAFA_noRstAdpVal_merge_l = AFA_noRstAdpValPrev;

  /* Inport: '<S42>/AFA_rCor_arEffEGRVlv_INPUT' */
  AFAT_B.AFA_rCor_arEffEGRVlv_merge_k = AFAT_B.TmpSignalConversionAtAFA_rCo_aa;

  /* Inport: '<S42>/AFA_tiOffInj_INPUT' */
  AFAT_B.AFA_tiOffInj_merge_j = AFAT_B.TmpSignalConversionAtAFA_tiOf_p;

  /* '<S49>:1:7' */

  /* If: '<S44>/If' incorporates:
   *  ActionPort: '<S51>/Action Port'
   *  ActionPort: '<S52>/Action Port'
   *  SubSystem: '<S44>/F01_reinit_whole_algo_adapt'
   *  SubSystem: '<S44>/F02_reinit_only_current_cycle'
   *
   * Block requirements for '<S44>/F01_reinit_whole_algo_adapt':
   *  1. SubSystem "F01_reinit_whole_algo_adapt" !Trace_To : VEMS_R_11_04467_005.01 ;
   *
   * Block requirements for '<S44>/F02_reinit_only_current_cycle':
   *  1. SubSystem "F02_reinit_only_current_cycle" !Trace_To : VEMS_R_11_04467_008.01 ;
   */
  if (AFAT_B.TmpSignalConversionAtAFAMgt_b_f) {
    /* S-Function (fcncallgen): '<S51>/Function-Call Generator3' incorporates:
     *  SubSystem: '<S48>/F02_reinit_algo_adaptation_(005_DRE)'
     */

    /* Embedded MATLAB: '<S84>/Diag_Vect2Mat' */
    Diag_Vect2Mat((&(AFA_prm_covErrIni_C[0])), localy_k);

    /* DataStoreWrite: '<S84>/Data Store Write' */
    for (locali_0 = 0; locali_0 < 64; locali_0++) {
      (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali_0)] = localy_k[locali_0];
    }

    /* DataStoreWrite: '<S84>/Data Store Write1' incorporates:
     *  Constant: '<S84>/Constant10'
     */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      (*Rte_Pim_AFA_prm_rErr_PIM())[(locali_0)] = AFAT_ConstP.pooled12[(locali_0)];
    }

    /* DataStoreWrite: '<S84>/Data Store Write9' incorporates:
     *  Constant: '<S84>/Constant7'
     */
    for (locali_0 = 0; locali_0 < 9; locali_0++) {
      (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali_0)] = AFAT_ConstP.pooled14
        [(locali_0)];
    }

    /* S-Function (NvRamWriteAccess): '<S84>/EepromWriteAccess3' */
    AFAT_sNV_Z1_CONST_16BIT.AFA_noAdpEfc_NV = ((UInt16)0U);

    /* Constant: '<S84>/Bool' */
    localAFA_bAuthClsCanPurg_merge_ = FALSE;

    /* S-Function (fcncallgen): '<S84>/Function-Call Generator' incorporates:
     *  SubSystem: '<S85>/F02_common_init_algo3_(003_DRE)'
     *
     * Block requirements for '<S85>/F02_common_init_algo3_(003_DRE)':
     *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
     *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
     *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
     *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
     */

    /* Constant: '<S98>/Constant1' */
    localAFA_tiDlyLstObs_merge_c = 0U;

    /* S-Function (fcncallgen): '<S98>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S85>/F00_init_scruter_environ_adaptation(013_DRE)'
     *  SubSystem: '<S85>/F03_reset_cumulated_model_noise_v(032_DRE)'
     *
     * Block requirements for '<S85>/F00_init_scruter_environ_adaptation(013_DRE)':
     *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
     *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
     *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
     *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
     *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
     *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
     *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
     *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
     *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
     *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
     *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
     *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
     *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
     *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
     *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
     *
     * Block requirements for '<S85>/F03_reset_cumulated_model_noise_v(032_DRE)':
     *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
     *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
     *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
     *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
     */

    /* DataStoreRead: '<S99>/Data Store Read' */
    for (locali_0 = 0; locali_0 < 64; locali_0++) {
      localDataStoreRead_p[locali_0] = (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())
        [(locali_0)];
    }

    /* ModelReference: '<S99>/AFAT_F03_reset_cumulated_model_noise_v' */
    mr_AFA_F03_reset_cumulated_mode(localDataStoreRead_p,
      AFAT_B.AFAT_F03_reset_cumulated_mode_e, localAFAT_F03_reset_cumulated_i);

    /* SignalConversion Block: '<S111>/copy'
     *
     * Regarding '<S111>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* DataStoreWrite: '<S99>/Data Store Write4' incorporates:
     *  SignalConversion: '<S99>/Signal Conversion1'
     */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali_0)] =
        localAFAT_F03_reset_cumulated_i[locali_0];
    }

    /* S-Function (NvRamWriteAccess): '<S99>/S-Function2' */
    {
      UInt32 locali;
      for (locali=0 ; locali <8; locali++) {
        AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali] =
          AFAT_B.AFAT_F03_reset_cumulated_mode_e[locali];
      }
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S111>/autosar_testpoint1' */

    /* S-Function Block: <S111>/autosar_testpoint1 */
    {
      SInt32 i1;
      const UInt16 *u0 = localAFAT_F03_reset_cumulated_i;
      for (i1=0; i1 < 8; i1++) {
        AFA_prm_covNoiseValIni[i1] = u0[i1];
      }
    }

    /* SignalConversion: '<S99>/Signal11' */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      localAFA_prm_covErrEstim_merge_[locali_0] =
        AFAT_B.AFAT_F03_reset_cumulated_mode_e[(locali_0)];
    }

    /* ModelReference: '<S97>/AFAT_F00_init_scruter_environ_adaptation' */
    mr_AFA_F00_init_scruter_environ(&AFAT_B.TmpSignalConversionAtThrLrn_r_m,
      &AFAT_B.TmpSignalConversionAtUsThrM_p_o,
      &AFAT_B.TmpSignalConversionAtEGRVlv_r_o,
      AFAT_B.TmpSignalConversionAtVlvAct_p_o,
      AFAT_B.TmpSignalConversionAtVlvAct_p_a, &AFAT_B.AFA_bClsEGRRef_merge_a0,
      &AFAT_B.AFA_bFitPresAirExt_merge_p, &AFAT_B.AFA_bFitZeroPosnThr_merge_o,
      &AFAT_B.AFA_bFitOpInVlvBol_merge_k, &AFAT_B.AFA_bFitClsExVlvBol_merge_o,
      &localAFAT_F00_init_scruter_en_k, &localAFAT_F00_init_scruter_en_b,
      &localAFAT_F00_init_scruter_en_p, &localAFAT_F00_init_scruter_e_k0,
      &localAFAT_F00_init_scruter_en_m);

    /* S-Function Block: '<S100>/FixPt Data Type Propagation'
     *
     * Regarding '<S100>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S101>/FixPt Data Type Propagation'
     *
     * Regarding '<S101>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S102>/FixPt Data Type Propagation'
     *
     * Regarding '<S102>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S103>/FixPt Data Type Propagation'
     *
     * Regarding '<S103>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S104>/FixPt Data Type Propagation'
     *
     * Regarding '<S104>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S100>/FixPt Gateway Out'
     *
     * Regarding '<S100>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S101>/FixPt Gateway Out'
     *
     * Regarding '<S101>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S102>/FixPt Gateway Out'
     *
     * Regarding '<S102>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S103>/FixPt Gateway Out'
     *
     * Regarding '<S103>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S104>/FixPt Gateway Out'
     *
     * Regarding '<S104>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* SignalConversion Block: '<S105>/copy'
     *
     * Regarding '<S105>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* SignalConversion Block: '<S106>/copy'
     *
     * Regarding '<S106>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* SignalConversion Block: '<S107>/copy'
     *
     * Regarding '<S107>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* SignalConversion Block: '<S108>/copy'
     *
     * Regarding '<S108>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* SignalConversion Block: '<S109>/copy'
     *
     * Regarding '<S109>/copy':
     *   Eliminate redundant signal conversion block
     */

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S97>/autosar_irv_write10' */

    /* S-Function Block: <S97>/autosar_irv_write10 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_pAirExtEstimHld_irv
      (localAFAT_F00_init_scruter_en_b);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S97>/autosar_irv_write11' */

    /* S-Function Block: <S97>/autosar_irv_write11 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_rOpClsEGRVlvBolHld_irv
      (localAFAT_F00_init_scruter_en_p);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S97>/autosar_irv_write12' */

    /* S-Function Block: <S97>/autosar_irv_write12 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_agCkOpInVlvBolHld_irv
      (localAFAT_F00_init_scruter_e_k0);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S97>/autosar_irv_write13' */

    /* S-Function Block: <S97>/autosar_irv_write13 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_agCkClsExVlvBolHld_irv
      (localAFAT_F00_init_scruter_en_m);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S97>/autosar_irv_write9' */

    /* S-Function Block: <S97>/autosar_irv_write9 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_rOpClsThrBolHld_irv
      (localAFAT_F00_init_scruter_en_k);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S105>/autosar_testpoint1' */

    /* S-Function Block: <S105>/autosar_testpoint1 */
    AFA_rOpClsThrBolHld_IRV_MP = localAFAT_F00_init_scruter_en_k;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S106>/autosar_testpoint1' */

    /* S-Function Block: <S106>/autosar_testpoint1 */
    AFA_pAirExtEstimHld_IRV_MP = localAFAT_F00_init_scruter_en_b;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S107>/autosar_testpoint1' */

    /* S-Function Block: <S107>/autosar_testpoint1 */
    AFA_rOpClsEGRVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_en_p;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S108>/autosar_testpoint1' */

    /* S-Function Block: <S108>/autosar_testpoint1 */
    AFA_agCkOpInVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_e_k0;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S109>/autosar_testpoint1' */

    /* S-Function Block: <S109>/autosar_testpoint1 */
    AFA_agCkClsExVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_en_m;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S98>/autosar_irv_write162' incorporates:
     *  Constant: '<S98>/Constant2'
     */

    /* S-Function Block: <S98>/autosar_irv_write162 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsInnovNotCoh_irv(((UInt8)0U));

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S110>/autosar_testpoint1' incorporates:
     *  Constant: '<S98>/Constant2'
     */

    /* S-Function Block: <S110>/autosar_testpoint1 */
    AFA_noObsInnovNotCoh_IRV_MP = ((UInt8)0U);

    /* S-Function (NvRamWriteAccess): '<S84>/S-Function2' */
    AFAT_sNV_Z1_CONST_BOOLEAN.AFA_bAcvSpcInjMod_NV = AFA_bAcvSpcInjModIni_C;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S96>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/AFA_bAcvSpcInjModIni_C'
     */

    /* S-Function Block: <S96>/autosar_testpoint1 */
    AFA_bAcvSpcInjModIni = AFA_bAcvSpcInjModIni_C;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S88>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant2'
     */

    /* S-Function Block: <S88>/autosar_testpoint1 */
    AFA_noObsDoneIni = ((UInt8)0U);

    /* SignalConversion: '<S84>/Signal Conversion' */
    localAFA_noAdpClcRst_merge_e = AFAT_B.TmpSignalConversionAtAFA_noAd_g;

    /* SignalConversion: '<S93>/copy' */
    AFA_noAdpClcRstPrev = AFAT_B.TmpSignalConversionAtAFA_noAd_g;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S93>/autosar_testpoint1' */

    /* S-Function Block: <S93>/autosar_testpoint1 */

    /* Sum: '<S84>/Subtract' incorporates:
     *  Constant: '<S84>/Constant4'
     */
    locali_0 = localAFA_noAdpClcRst_merge_e + 1;
    if (((UInt32)locali_0) > 255U) {
      localAFA_noAdpClcRst_merge_e = MAX_uint8_T;
    } else {
      localAFA_noAdpClcRst_merge_e = (UInt8)locali_0;
    }

    /* S-Function (NvRamWriteAccess): '<S84>/EepromWriteAccess2' */
    AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV = AFA_bEngStopAuthIni_C;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S95>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/AFA_bEngStopAuthIni_C'
     */

    /* S-Function Block: <S95>/autosar_testpoint1 */
    AFA_bEngStopAuthIni = AFA_bEngStopAuthIni_C;

    /* S-Function (NvRamWriteAccess): '<S84>/S-Function1' */
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[0] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[1] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[2] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[3] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[4] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[5] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[6] = (0);
    AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[7] = (0);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S92>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant10'
     */

    /* S-Function Block: <S92>/autosar_testpoint1 */
    {
      SInt32 i1;
      const SInt16 *u0 = AFAT_ConstP.pooled12;
      for (i1=0; i1 < 8; i1++) {
        AFA_prm_rErrIni[i1] = u0[i1];
      }
    }

    /* S-Function (NvRamWriteAccess): '<S84>/EepromWriteAccess1' */
    AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV = ((UInt8)0U);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S84>/autosar_irv_write32' incorporates:
     *  Constant: '<S84>/Constant5'
     */

    /* S-Function Block: <S84>/autosar_irv_write32 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsDoneIdlIni_irv(((UInt8)0U));

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S89>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant5'
     */

    /* S-Function Block: <S89>/autosar_testpoint1 */
    AFA_noObsDoneIdlIni_IRV_MP = ((UInt8)0U);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S91>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant5'
     */

    /* S-Function Block: <S91>/autosar_testpoint1 */
    AFA_noObsDoneIdlIni = ((UInt8)0U);

    /* S-Function (NvRamWriteAccess): '<S84>/EepromWriteAccess' */
    AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV = ((UInt8)0U);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S84>/autosar_irv_write1' incorporates:
     *  Constant: '<S84>/Constant6'
     */

    /* S-Function Block: <S84>/autosar_irv_write1 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsSpcInjMod_irv(((UInt8)0U));

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S87>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant6'
     */

    /* S-Function Block: <S87>/autosar_testpoint1 */
    AFA_noObsSpcInjMod_IRV_MP = ((UInt8)0U);

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S90>/autosar_testpoint1' incorporates:
     *  Constant: '<S84>/Constant6'
     */

    /* S-Function Block: <S90>/autosar_testpoint1 */
    AFA_noObsSpcInjModIni = ((UInt8)0U);

    /* SignalConversion: '<S94>/copy' incorporates:
     *  Constant: '<S84>/Constant7'
     */
    for (locali_0 = 0; locali_0 < 9; locali_0++) {
      AFA_prm_noObsDoneMatIni[locali_0] = AFAT_ConstP.pooled14[(locali_0)];
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S94>/autosar_testpoint1' */

    /* S-Function Block: <S94>/autosar_testpoint1 */

    /* If: '<S51>/If' incorporates:
     *  ActionPort: '<S58>/Action Port'
     *  ActionPort: '<S59>/Action Port'
     *  SubSystem: '<S51>/F01_call_reinit_adaption_terms'
     *  SubSystem: '<S51>/F02_call_read_adap_eep'
     *
     * Block requirements for '<S51>/F01_call_reinit_adaption_terms':
     *  1. SubSystem "F01_call_reinit_adaption_terms" !Trace_To : VEMS_R_11_04467_006.01 ;
     *
     * Block requirements for '<S51>/F02_call_read_adap_eep':
     *  1. SubSystem "F01_call_reinit_adaption_terms" !Trace_To : VEMS_R_11_04467_006.01 ;
     */
    if (AFAT_B.TmpSignalConversionAtAFAMgt_b_a) {
      /* Sum: '<S58>/Sum' incorporates:
       *  Constant: '<S58>/Constant'
       */
      locali_0 = 1 + AFA_noRstAdpValPrev;
      if (((UInt32)locali_0) > 255U) {
        localAFA_noRstAdpVal_merge_l = MAX_uint8_T;
      } else {
        localAFA_noRstAdpVal_merge_l = (UInt8)locali_0;
      }

      /* S-Function (fcncallgen): '<S58>/Function-Call Generator3' incorporates:
       *  SubSystem: '<S9>/F02_Afa_adapt_terms_reset_(027_MSE)'
       *
       * Block requirements for '<S9>/F02_Afa_adapt_terms_reset_(027_MSE)':
       *  1. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_113.01 ;
       *  2. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_201.01 ;
       *  3. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_202.01 ;
       *  4. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_203.01 ;
       *  5. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_204.01 ;
       *  6. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_215.01 ;
       *  7. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_216.01 ;
       *  8. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_217.01 ;
       *  9. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_218.01 ;
       *  10. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_231.01 ;
       *  11. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_234.01 ;
       *  12. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_252.01 ;
       *  13. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_253.01 ;
       *  14. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_254.01 ;
       *  15. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_255.01 ;
       *  16. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_256.01 ;
       *  17. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_257.01 ;
       *  18. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_258.01 ;
       *  19. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_259.01 ;
       *  20. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_260.01 ;
       *  21. SubSystem "F02_Afa_adapt_terms_reset_(027_DRE)" !Trace_To : VEMS_R_11_04467_332.01 ;
       */

      /* ModelReference: '<S46>/AFA_F02_Afa_adapt_terms_reset' */
      mr_AFA_F02_Afa_adapt_terms_rese(&AFAT_B.AFA_F02_Afa_adapt_terms_rese_ot,
        &AFAT_B.AFA_F02_Afa_adapt_terms_rese_jb,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_o,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_j,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_m,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_a,
        &AFAT_B.AFA_F02_Afa_adapt_terms_rese_mg,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_g,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_b,
        &AFAT_B.AFA_F02_Afa_adapt_terms_reset_h,
        &AFAT_B.AFA_arEffEGRVlvOfs_merge_h);

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess10' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs3_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_rese_mg;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess11' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_rCor_arEffEGRVlv_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_g;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess12' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkOpInVlvOfs_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_b;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess13' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkClsExVlvOfs_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_h;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess4' */
      AFAT_sNV_Z1_CALIB_16BIT.AFA_facIvsInjGain_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_rese_ot;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess5' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_tiOffInj_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_rese_jb;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess6' */
      AFAT_sNV_Z1_CALIB_32BIT.AFA_facSlopInjGain_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_o;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess7' */
      AFAT_sNV_Z1_CALIB_16BIT.AFA_arEffThrOfs_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_j;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess8' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs1_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_m;

      /* S-Function (NvRamWriteAccess): '<S46>/EepromWriteAccess9' */
      AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs2_NV =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_a;

      /* SignalConversion: '<S46>/Signal1' */
      AFAT_B.AFA_agCkOpInVlvOfs_merge_k0 =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_b;

      /* SignalConversion: '<S46>/Signal10' */
      AFAT_B.AFA_agCkClsExVlvOfs_merge_l =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_h;

      /* SignalConversion: '<S46>/Signal2' */
      AFAT_B.AFA_rCor_arEffEGRVlv_merge_k =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_g;

      /* SignalConversion: '<S46>/Signal3' */
      AFAT_B.AFA_facArEffThrOfs3_merge_p =
        AFAT_B.AFA_F02_Afa_adapt_terms_rese_mg;

      /* SignalConversion: '<S46>/Signal4' */
      AFAT_B.AFA_facArEffThrOfs2_merge_a =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_a;

      /* SignalConversion: '<S46>/Signal5' */
      AFAT_B.AFA_facArEffThrOfs1_merge_m =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_m;

      /* SignalConversion: '<S46>/Signal6' */
      AFAT_B.AFA_arEffThrOfs_merge_a = AFAT_B.AFA_F02_Afa_adapt_terms_reset_j;

      /* SignalConversion: '<S46>/Signal7' */
      AFAT_B.AFA_facSlopInjGain_merge_mi =
        AFAT_B.AFA_F02_Afa_adapt_terms_reset_o;

      /* SignalConversion: '<S46>/Signal8' */
      AFAT_B.AFA_tiOffInj_merge_j = AFAT_B.AFA_F02_Afa_adapt_terms_rese_jb;

      /* SignalConversion: '<S46>/Signal9' */
      AFAT_B.AFA_facIvsInjGain_merge_c = AFAT_B.AFA_F02_Afa_adapt_terms_rese_ot;
    } else {
      /* S-Function (fcncallgen): '<S59>/Function-Call Generator3' incorporates:
       *  SubSystem: '<S9>/F01_lire_adaptatifs_en_eeprom_(026_MSE)'
       */
      F01_lire_adaptatifs_en_eeprom_0(0);
    }

    /* SignalConversion: '<S51>/Signal Conversion' incorporates:
     *  Constant: '<S51>/Bool'
     */
    localSignalConversion_l = TRUE;

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S51>/autosar_irv_write50' */

    /* S-Function Block: <S51>/autosar_irv_write50 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_bAdpClcRstReqHld_irv
      (localSignalConversion_l);

    /* SignalConversion: '<S60>/copy' */
    AFA_bAdpClcRstReqIni = localSignalConversion_l;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S60>/autosar_testpoint1' */

    /* S-Function Block: <S60>/autosar_testpoint1 */

    /* SignalConversion: '<S61>/copy' */
    AFA_bAdpClcRstReqHld_IRV_MP = localSignalConversion_l;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S61>/autosar_testpoint1' */

    /* S-Function Block: <S61>/autosar_testpoint1 */
  } else {
    /* S-Function (fcncallgen): '<S52>/Function-Call Generator' incorporates:
     *  SubSystem: '<S47>/F02_common_init_algo3_(003_DRE)'
     *  SubSystem: '<S52>/F01_read_adaption_parameters'
     *  SubSystem: '<S9>/F01_add_cranking_noise_(015_MSE)'
     *  SubSystem: '<S9>/F01_lire_adaptatifs_en_eeprom_(026_MSE)'
     *
     * Block requirements for '<S47>/F02_common_init_algo3_(003_DRE)':
     *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
     *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
     *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
     *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
     *
     * Block requirements for '<S52>/F01_read_adaption_parameters':
     *  1. SubSystem "F01_read_adaption_parameters" !Trace_To : VEMS_R_11_04467_009.01 ;
     *
     * Block requirements for '<S9>/F01_add_cranking_noise_(015_MSE)':
     *  1. SubSystem "F01_add_cranking_noise_(015_MSE)" !Trace_To : VEMS_R_11_04467_048.01 ;
     *  2. SubSystem "F01_add_cranking_noise_(015_MSE)" !Trace_To : VEMS_R_11_04467_320.01 ;
     */

    /* S-Function (NvRamReadAccess): '<S62>/S-Function3' */
    {
      UInt32 locali;
      for (locali=0 ; locali <8; locali++) {
        AFAT_B.SFunction3[locali] =
          AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali];
      }
    }

    /* Embedded MATLAB: '<S62>/Diag_Vect2Mat' */
    /* Embedded MATLAB Function 'Diag_Vect2Mat': '<S63>:1' */
    /* '<S63>:1:2' */
    memset((void *)(&localy[0]), (SInt32)0U, sizeof(UInt16) << 6U);
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      localy[locali_0 + (locali_0 << 3)] = AFAT_B.SFunction3[(locali_0)];
    }

    /* DataStoreWrite: '<S62>/Data Store Write' */
    for (locali_0 = 0; locali_0 < 64; locali_0++) {
      (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali_0)] = localy[locali_0];
    }

    /* S-Function (NvRamReadAccess): '<S62>/S-Function1' */
    {
      UInt32 locali;
      for (locali=0 ; locali <8; locali++) {
        AFAT_B.SFunction1[locali] =
          AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[locali];
      }
    }

    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      /* SignalConversion: '<S62>/Signal Conversion4' */
      localSignalConversion4[locali_0] = AFAT_B.SFunction1[(locali_0)];

      /* DataStoreWrite: '<S62>/Data Store Write5' */
      (*Rte_Pim_AFA_prm_rErr_PIM())[(locali_0)] = AFAT_B.SFunction1[(locali_0)];
    }

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess' */
    AFAT_B.EepromReadAccess = AFAT_sNV_Z1_CONST_16BIT.AFA_noAdpEfc_NV;

    /* RelationalOperator: '<S62>/Relational Operator2' incorporates:
     *  Constant: '<S62>/AFA_noAdpEfcMinThd_C'
     */
    localAFA_bAuthClsCanPurg_merge_ = (AFAT_B.EepromReadAccess >=
      AFA_noAdpEfcMinThd_C);

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess3' */
    AFAT_B.EepromReadAccess3_d = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDone_NV;

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess1' */
    AFAT_B.EepromReadAccess1 = AFAT_sNV_Z1_CONST_BOOLEAN.AFA_bAcvSpcInjMod_NV;

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess4' */
    AFAT_B.EepromReadAccess4 = AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV;

    /* SignalConversion: '<S62>/Signal Conversion3' */
    AFAT_B.SignalConversion3 = AFAT_B.EepromReadAccess4;

    /* SignalConversion: '<S65>/copy' */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      AFA_prm_rErrIni[locali_0] = localSignalConversion4[locali_0];
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S65>/autosar_testpoint1' */

    /* S-Function Block: <S65>/autosar_testpoint1 */

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess2' */
    AFAT_B.EepromReadAccess2_c = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV;

    /* DataTypeConversion Block: '<S62>/Data Type Conversion29'
     *
     * Regarding '<S62>/Data Type Conversion29':
     *   Eliminate redundant data type conversion
     */

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S62>/autosar_irv_write4' */

    /* S-Function Block: <S62>/autosar_irv_write4 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsSpcInjMod_irv
      (AFAT_B.EepromReadAccess2_c);

    /* SignalConversion: '<S64>/copy' */
    AFA_noObsSpcInjModIni = AFAT_B.EepromReadAccess2_c;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S64>/autosar_testpoint1' */

    /* S-Function Block: <S64>/autosar_testpoint1 */

    /* SignalConversion: '<S66>/copy' */
    AFA_noObsSpcInjMod_IRV_MP = AFAT_B.EepromReadAccess2_c;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S66>/autosar_testpoint1' */

    /* S-Function Block: <S66>/autosar_testpoint1 */

    /* S-Function (NvRamReadAccess): '<S62>/EepromReadAccess5' */
    AFAT_B.EepromReadAccess5 = AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV;

    /* SignalConversion Block: '<S62>/Signal Conversion6'
     *
     * Regarding '<S62>/Signal Conversion6':
     *   Eliminate redundant signal conversion block
     */

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S62>/autosar_irv_write' */

    /* S-Function Block: <S62>/autosar_irv_write */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsDoneIdlIni_irv
      (AFAT_B.EepromReadAccess5);

    /* SignalConversion: '<S67>/copy' */
    AFA_noObsDoneIdlIni = AFAT_B.EepromReadAccess5;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S67>/autosar_testpoint1' */

    /* S-Function Block: <S67>/autosar_testpoint1 */

    /* SignalConversion: '<S68>/copy' */
    AFA_noObsDoneIdlIni_IRV_MP = AFAT_B.EepromReadAccess5;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S68>/autosar_testpoint1' */

    /* S-Function Block: <S68>/autosar_testpoint1 */
    F01_lire_adaptatifs_en_eeprom_0(1);

    /* Constant: '<S70>/Constant1' */
    localAFA_tiDlyLstObs_merge_c = 0U;

    /* S-Function (fcncallgen): '<S70>/Function-Call Generator1' incorporates:
     *  SubSystem: '<S47>/F00_init_scruter_environ_adaptation(013_DRE)'
     *  SubSystem: '<S47>/F03_reset_cumulated_model_noise_v(032_DRE)'
     *
     * Block requirements for '<S47>/F00_init_scruter_environ_adaptation(013_DRE)':
     *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
     *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
     *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
     *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
     *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
     *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
     *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
     *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
     *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
     *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
     *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
     *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
     *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
     *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
     *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
     *
     * Block requirements for '<S47>/F03_reset_cumulated_model_noise_v(032_DRE)':
     *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
     *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
     *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
     *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
     */

    /* DataStoreRead: '<S71>/Data Store Read' */
    for (locali_0 = 0; locali_0 < 64; locali_0++) {
      localDataStoreRead[locali_0] = (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())
        [(locali_0)];
    }

    /* ModelReference: '<S71>/AFAT_F03_reset_cumulated_model_noise_v' */
    mr_AFA_F03_reset_cumulated_mode(localDataStoreRead,
      AFAT_B.AFAT_F03_reset_cumulated_mode_j, localAFAT_F03_reset_cumulated_m);

    /* DataStoreWrite: '<S71>/Data Store Write4' incorporates:
     *  SignalConversion: '<S71>/Signal Conversion1'
     */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali_0)] =
        localAFAT_F03_reset_cumulated_m[locali_0];
    }

    /* S-Function (NvRamWriteAccess): '<S71>/S-Function2' */
    {
      UInt32 locali;
      for (locali=0 ; locali <8; locali++) {
        AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali] =
          AFAT_B.AFAT_F03_reset_cumulated_mode_j[locali];
      }
    }

    /* SignalConversion: '<S83>/copy' */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      AFA_prm_covNoiseValIni[locali_0] =
        localAFAT_F03_reset_cumulated_m[locali_0];
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S83>/autosar_testpoint1' */

    /* S-Function Block: <S83>/autosar_testpoint1 */

    /* SignalConversion: '<S71>/Signal11' */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      localAFA_prm_covErrEstim_merge_[locali_0] =
        AFAT_B.AFAT_F03_reset_cumulated_mode_j[(locali_0)];
    }

    /* ModelReference: '<S69>/AFAT_F00_init_scruter_environ_adaptation' */
    mr_AFA_F00_init_scruter_environ(&AFAT_B.TmpSignalConversionAtThrLrn_r_m,
      &AFAT_B.TmpSignalConversionAtUsThrM_p_o,
      &AFAT_B.TmpSignalConversionAtEGRVlv_r_o,
      AFAT_B.TmpSignalConversionAtVlvAct_p_o,
      AFAT_B.TmpSignalConversionAtVlvAct_p_a, &AFAT_B.AFA_bClsEGRRef_merge_a0,
      &AFAT_B.AFA_bFitPresAirExt_merge_p, &AFAT_B.AFA_bFitZeroPosnThr_merge_o,
      &AFAT_B.AFA_bFitOpInVlvBol_merge_k, &AFAT_B.AFA_bFitClsExVlvBol_merge_o,
      &localAFAT_F00_init_scruter_en_d, &localAFAT_F00_init_scruter_envi,
      &localAFAT_F00_init_scruter_en_f, &localAFAT_F00_init_scruter_e_kp,
      &localAFAT_F00_init_scruter_e_f0);

    /* S-Function Block: '<S72>/FixPt Data Type Propagation'
     *
     * Regarding '<S72>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S73>/FixPt Data Type Propagation'
     *
     * Regarding '<S73>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S74>/FixPt Data Type Propagation'
     *
     * Regarding '<S74>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S75>/FixPt Data Type Propagation'
     *
     * Regarding '<S75>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S76>/FixPt Data Type Propagation'
     *
     * Regarding '<S76>/FixPt Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S72>/FixPt Gateway Out'
     *
     * Regarding '<S72>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S73>/FixPt Gateway Out'
     *
     * Regarding '<S73>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S74>/FixPt Gateway Out'
     *
     * Regarding '<S74>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S75>/FixPt Gateway Out'
     *
     * Regarding '<S75>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S76>/FixPt Gateway Out'
     *
     * Regarding '<S76>/FixPt Gateway Out':
     *   Eliminate redundant data type conversion
     */

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S69>/autosar_irv_write10' */

    /* S-Function Block: <S69>/autosar_irv_write10 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_pAirExtEstimHld_irv
      (localAFAT_F00_init_scruter_envi);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S69>/autosar_irv_write11' */

    /* S-Function Block: <S69>/autosar_irv_write11 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_rOpClsEGRVlvBolHld_irv
      (localAFAT_F00_init_scruter_en_f);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S69>/autosar_irv_write12' */

    /* S-Function Block: <S69>/autosar_irv_write12 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_agCkOpInVlvBolHld_irv
      (localAFAT_F00_init_scruter_e_kp);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S69>/autosar_irv_write13' */

    /* S-Function Block: <S69>/autosar_irv_write13 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_agCkClsExVlvBolHld_irv
      (localAFAT_F00_init_scruter_e_f0);

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S69>/autosar_irv_write9' */

    /* S-Function Block: <S69>/autosar_irv_write9 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_rOpClsThrBolHld_irv
      (localAFAT_F00_init_scruter_en_d);

    /* SignalConversion: '<S77>/copy' */
    AFA_rOpClsThrBolHld_IRV_MP = localAFAT_F00_init_scruter_en_d;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S77>/autosar_testpoint1' */

    /* S-Function Block: <S77>/autosar_testpoint1 */

    /* SignalConversion: '<S78>/copy' */
    AFA_pAirExtEstimHld_IRV_MP = localAFAT_F00_init_scruter_envi;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S78>/autosar_testpoint1' */

    /* S-Function Block: <S78>/autosar_testpoint1 */

    /* SignalConversion: '<S79>/copy' */
    AFA_rOpClsEGRVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_en_f;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S79>/autosar_testpoint1' */

    /* S-Function Block: <S79>/autosar_testpoint1 */

    /* SignalConversion: '<S80>/copy' */
    AFA_agCkOpInVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_e_kp;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S80>/autosar_testpoint1' */

    /* S-Function Block: <S80>/autosar_testpoint1 */

    /* SignalConversion: '<S81>/copy' */
    AFA_agCkClsExVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_e_f0;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S81>/autosar_testpoint1' */

    /* S-Function Block: <S81>/autosar_testpoint1 */

    /* S-Function (sfun_autosar_extras_irv_read_write): '<S70>/autosar_irv_write162' incorporates:
     *  Constant: '<S70>/Constant2'
     */

    /* S-Function Block: <S70>/autosar_irv_write162 */
    Rte_IrvWrite_RE_AFAT_002_MSE_AFA_noObsInnovNotCoh_irv(((UInt8)0U));

    /* SignalConversion: '<S82>/copy' incorporates:
     *  Constant: '<S70>/Constant2'
     */
    AFA_noObsInnovNotCoh_IRV_MP = 0U;

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S82>/autosar_testpoint1' */

    /* S-Function Block: <S82>/autosar_testpoint1 */

    /* DataStoreRead: '<S43>/Data Store Read1' */
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      localSignalConversion[locali_0] = (*Rte_Pim_AFA_prm_covNoiseVal_PIM())
        [(locali_0)];
    }

    /* ModelReference: '<S43>/AFA_F01_add_cranking_noise' */
    mr_AFA_F01_add_cranking_noise(localSignalConversion,
      localAFA_F01_add_cranking_noise);
    for (locali_0 = 0; locali_0 < 8; locali_0++) {
      /* DataStoreWrite: '<S43>/Data Store Write4' */
      (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali_0)] =
        localAFA_F01_add_cranking_noise[locali_0];

      /* SignalConversion: '<S50>/copy' */
      AFA_prm_covNoiseValPrev[locali_0] = localSignalConversion[locali_0];
    }

    /* S-Function (sfun_autosar_extras_dsm_read_write): '<S50>/autosar_testpoint1' */

    /* S-Function Block: <S50>/autosar_testpoint1 */
  }

  /* SignalConversion: '<S54>/copy' */
  AFA_noAdpEfcIni = AFAT_B.EepromReadAccess;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S54>/autosar_testpoint1' */

  /* S-Function Block: <S54>/autosar_testpoint1 */

  /* SignalConversion: '<S55>/copy' */
  AFA_bEngStopAuthIni = AFAT_B.SignalConversion3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S55>/autosar_testpoint1' */

  /* S-Function Block: <S55>/autosar_testpoint1 */

  /* SignalConversion: '<S56>/copy' */
  AFA_noObsDoneIni = AFAT_B.EepromReadAccess3_d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S56>/autosar_testpoint1' */

  /* S-Function Block: <S56>/autosar_testpoint1 */

  /* SignalConversion: '<S57>/copy' */
  AFA_bAcvSpcInjModIni = AFAT_B.EepromReadAccess1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S57>/autosar_testpoint1' */

  /* S-Function Block: <S57>/autosar_testpoint1 */

  /* SignalConversion: '<S44>/Signal1' */
  localAFA_noObsDone_merge_l = AFAT_B.EepromReadAccess3_d;

  /* SignalConversion: '<S44>/Signal11' */
  localAFA_noAdpEfc_merge_g = AFAT_B.EepromReadAccess;

  /* SignalConversion: '<S44>/Signal2' */
  localAFA_bAcvSpcInjMod_merge_j = AFAT_B.EepromReadAccess1;

  /* SignalConversion: '<S44>/Signal3' */
  localAFA_bEngStopAuth_merge_c = AFAT_B.SignalConversion3;

  /* SignalConversion: '<S53>/copy' incorporates:
   *  Constant: '<S44>/Constant2'
   */
  AFA_noAdpEfcAstIni = 0U;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S53>/autosar_testpoint1' */

  /* S-Function Block: <S53>/autosar_testpoint1 */

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Byp_Fonction_SC'
   *  Constant: '<S16>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_c0 = AFA_agCkClsExVlvOfs_B;
  } else {
    localSwitch_c0 = AFAT_B.AFA_agCkClsExVlvOfs_merge_l;
  }

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Byp_Fonction_SC'
   *  Constant: '<S17>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_h3 = AFA_agCkOpInVlvOfs_B;
  } else {
    localSwitch_h3 = AFAT_B.AFA_agCkOpInVlvOfs_merge_k0;
  }

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Byp_Fonction_SC'
   *  Constant: '<S18>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_ny = AFA_arEffEGRVlvOfs_B;
  } else {
    localSwitch_ny = AFAT_B.AFA_arEffEGRVlvOfs_merge_h;
  }

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Byp_Fonction_SC'
   *  Constant: '<S19>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_l3 = AFA_arEffThrOfs_B;
  } else {
    localSwitch_l3 = AFAT_B.AFA_arEffThrOfs_merge_a;
  }

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Byp_Fonction_SC'
   *  Constant: '<S20>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bAcvSpcInjMod_merge_j = AFA_bAcvSpcInjMod_B;
  }

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Byp_Fonction_SC'
   *  Constant: '<S21>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bAuthClsCanPurg_merge_ = AFA_bAuthClsCanPurg_B;
  }

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Byp_Fonction_SC'
   *  Constant: '<S22>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_iy = AFA_bClsEGRRef_B;
  } else {
    localSwitch_iy = AFAT_B.AFA_bClsEGRRef_merge_a0;
  }

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Byp_Fonction_SC'
   *  Constant: '<S23>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bEngStopAuth_merge_c = AFA_bEngStopAuth_B;
  }

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Byp_Fonction_SC'
   *  Constant: '<S24>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_bc = AFA_bFitClsExVlvBol_B;
  } else {
    localSwitch_bc = AFAT_B.AFA_bFitClsExVlvBol_merge_o;
  }

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Byp_Fonction_SC'
   *  Constant: '<S25>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_oq = AFA_bFitOpInVlvBol_B;
  } else {
    localSwitch_oq = AFAT_B.AFA_bFitOpInVlvBol_merge_k;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Byp_Fonction_SC'
   *  Constant: '<S26>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_ad = AFA_bFitPresAirExt_B;
  } else {
    localSwitch_ad = AFAT_B.AFA_bFitPresAirExt_merge_p;
  }

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Byp_Fonction_SC'
   *  Constant: '<S27>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_nv = AFA_bFitZeroPosnThr_B;
  } else {
    localSwitch_nv = AFAT_B.AFA_bFitZeroPosnThr_merge_o;
  }

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Byp_Fonction_SC'
   *  Constant: '<S28>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_lb = AFA_facArEffThrOfs1_B;
  } else {
    localSwitch_lb = AFAT_B.AFA_facArEffThrOfs1_merge_m;
  }

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Byp_Fonction_SC'
   *  Constant: '<S29>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_eh = AFA_facArEffThrOfs2_B;
  } else {
    localSwitch_eh = AFAT_B.AFA_facArEffThrOfs2_merge_a;
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Byp_Fonction_SC'
   *  Constant: '<S30>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_cq = AFA_facArEffThrOfs3_B;
  } else {
    localSwitch_cq = AFAT_B.AFA_facArEffThrOfs3_merge_p;
  }

  /* Switch: '<S31>/Switch' incorporates:
   *  Constant: '<S31>/Byp_Fonction_SC'
   *  Constant: '<S31>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_e1 = AFA_facIvsInjGain_B;
  } else {
    localSwitch_e1 = AFAT_B.AFA_facIvsInjGain_merge_c;
  }

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Byp_Fonction_SC'
   *  Constant: '<S32>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    locali_0 = AFA_facSlopInjGain_B;
  } else {
    locali_0 = AFAT_B.AFA_facSlopInjGain_merge_mi;
  }

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Byp_Fonction_SC'
   *  Constant: '<S33>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noAdpClcRst_merge_e = AFA_noAdpClcRst_B;
  }

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Byp_Fonction_SC'
   *  Constant: '<S34>/Int_BypC'
   *  Constant: '<S44>/Constant2'
   *  SignalConversion: '<S44>/Signal4'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_nq = AFA_noAdpEfcAst_B;
  } else {
    localSwitch_nq = 0U;
  }

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Byp_Fonction_SC'
   *  Constant: '<S35>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noAdpEfc_merge_g = AFA_noAdpEfc_B;
  }

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S36>/Byp_Fonction_SC'
   *  Constant: '<S36>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noObsDone_merge_l = AFA_noObsDone_B;
  }

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Byp_Fonction_SC'
   *  Constant: '<S37>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noRstAdpVal_merge_l = AFA_noRstAdpVal_B;
  }

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Byp_Fonction_SC'
   *  Constant: '<S38>/Int_BypC'
   */
  for (locali = 0; locali < 8; locali++) {
    if (AFAT_ACTIVE_BYP_C) {
      localAFA_prm_covErrEstim_merge_[locali] = AFA_prm_covErrEstim_B[(locali)];
    }
  }

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Byp_Fonction_SC'
   *  Constant: '<S39>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_ehn = AFA_rCor_arEffEGRVlv_B;
  } else {
    localSwitch_ehn = AFAT_B.AFA_rCor_arEffEGRVlv_merge_k;
  }

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S40>/Byp_Fonction_SC'
   *  Constant: '<S40>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_tiDlyLstObs_merge_c = AFA_tiDlyLstObs_B;
  }

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/Byp_Fonction_SC'
   *  Constant: '<S41>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_jy = AFA_tiOffInj_B;
  } else {
    localSwitch_jy = AFAT_B.AFA_tiOffInj_merge_j;
  }

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_agCkClsExVlvOfsInport2' */
  Rte_Write_P_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs(localSwitch_c0);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_agCkOpInVlvOfsInport2' */
  Rte_Write_P_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs(localSwitch_h3);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_arEffEGRVlvOfsInport2' */
  Rte_Write_P_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs(localSwitch_ny);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_arEffThrOfsInport2' */
  Rte_Write_P_AFA_arEffThrOfs_AFA_arEffThrOfs(localSwitch_l3);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bAcvSpcInjModInport2' */
  Rte_Write_P_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod(localAFA_bAcvSpcInjMod_merge_j);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bAuthClsCanPurgInport2' */
  Rte_Write_P_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg
    (localAFA_bAuthClsCanPurg_merge_);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bClsEGRRefInport2' */
  Rte_Write_P_AFA_bClsEGRRef_AFA_bClsEGRRef(localSwitch_iy);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bEngStopAuthInport2' */
  Rte_Write_P_AFA_bEngStopAuth_AFA_bEngStopAuth(localAFA_bEngStopAuth_merge_c);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitClsExVlvBolInport2' */
  Rte_Write_P_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol(localSwitch_bc);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitOpInVlvBolInport2' */
  Rte_Write_P_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol(localSwitch_oq);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitPresAirExtInport2' */
  Rte_Write_P_AFA_bFitPresAirExt_AFA_bFitPresAirExt(localSwitch_ad);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_bFitZeroPosnThrInport2' */
  Rte_Write_P_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr(localSwitch_nv);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs1Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1(localSwitch_lb);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs2Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2(localSwitch_eh);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facArEffThrOfs3Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3(localSwitch_cq);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facIvsInjGainInport2' */
  Rte_Write_P_AFA_facIvsInjGain_AFA_facIvsInjGain(localSwitch_e1);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_facSlopInjGainInport2' */
  Rte_Write_P_AFA_facSlopInjGain_AFA_facSlopInjGain(locali_0);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpClcRstInport2' */
  Rte_Write_P_AFA_noAdpClcRst_AFA_noAdpClcRst(localAFA_noAdpClcRst_merge_e);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpEfcAstInport2' */
  Rte_Write_P_AFA_noAdpEfcAst_AFA_noAdpEfcAst(localSwitch_nq);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noAdpEfcInport2' */
  Rte_Write_P_AFA_noAdpEfc_AFA_noAdpEfc(localAFA_noAdpEfc_merge_g);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noObsDoneInport2' */
  Rte_Write_P_AFA_noObsDone_AFA_noObsDone(localAFA_noObsDone_merge_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_noRstAdpValInport2' */
  Rte_Write_P_AFA_noRstAdpVal_AFA_noRstAdpVal(localAFA_noRstAdpVal_merge_l);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_prm_covErrEstimInport2' */
  Rte_Write_P_AFA_prm_covErrEstim_AFA_prm_covErrEstim
    (&localAFA_prm_covErrEstim_merge_);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlvInport2' */
  Rte_Write_P_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv(localSwitch_ehn);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_tiDlyLstObsInport2' */
  Rte_Write_P_AFA_tiDlyLstObs_AFA_tiDlyLstObs(localAFA_tiDlyLstObs_merge_c);

  /* SignalConversion: '<S9>/TmpSignal ConversionAtAFA_tiOffInjInport2' */
  Rte_Write_P_AFA_tiOffInj_AFA_tiOffInj(localSwitch_jy);
}

/* Start for exported function: RE_AFAT_003_MSE */
void RE_AFAT_003_MSE_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_EveRst_AFAClcFilInp_(003_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_EveRst_AFAClcFilInp_(003_MSE)':
   *  1. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  2. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  3. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_195.01 ;
   *  4. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_175.01 ;
   *  5. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_176.01 ;
   *  6. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_177.01 ;
   *  7. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_163.01 ;
   *  8. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_164.01 ;
   *  9. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_165.01 ;
   *  10. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_166.01 ;
   *  11. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_167.01 ;
   *  12. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_170.01 ;
   *  13. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_171.01 ;
   *  14. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_173.01 ;
   *  15. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_180.01 ;
   *  16. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_182.01 ;
   *  17. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_183.01 ;
   *  18. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_184.01 ;
   *  19. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_187.01 ;
   *  20. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_188.01 ;
   *  21. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_189.01 ;
   *  22. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_190.01 ;
   *  23. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_191.01 ;
   *  24. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_192.01 ;
   *  25. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_193.01 ;
   *  26. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_196.01 ;
   *  27. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_198.01 ;
   *  28. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  29. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  30. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  31. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  32. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_240.01 ;
   *  33. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  34. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  35. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  36. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  37. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  38. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  39. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  40. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  41. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  42. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  43. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  44. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  45. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  46. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  47. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  48. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  49. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  50. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  51. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  52. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  53. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  54. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  55. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_328.01 ;
   */
}

/* Output and update for exported function: RE_AFAT_003_MSE */
void RE_AFAT_003_MSE(void)
{
  /* local block i/o variables */
  UInt32 localAFAT_F01_init_inputs_filte[4];
  UInt32 localAFAT_F01_init_inputs_fil_n[4];
  UInt32 localAFAT_F01_init_inputs_fil_c;
  UInt32 localAFAT_F01_init_inputs_fil_i;
  UInt32 localAFAT_F01_init_inputs_fi_cq;
  SInt16 localAFAT_F01_init_inputs_fil_o;
  UInt16 localAFAT_F01_init_inputs_fil_j;
  UInt16 localAFAT_F01_init_inputs_fil_a;
  UInt16 localAFAT_F01_init_inputs_fil_m[4];
  UInt16 localAFAT_F01_init_inputs_fi_cf;
  UInt16 localAFAT_F01_init_inputs_fi_in;
  UInt16 localAFAT_F01_init_inputs_fil_h;
  UInt16 localAFAT_F01_init_inputs_fil_g;
  UInt16 localAFAT_F01_init_inputs_fil_b;
  UInt16 localAFAT_F01_init_inputs_fil_d;
  UInt16 localAFAT_F01_init_inputs_fi_md;
  UInt16 localAFAT_F01_init_inputs_fil_e;
  UInt16 localAFAT_F01_init_inputs_fi_ei;
  UInt16 localAFAT_F01_init_inputs_fi_av;
  UInt16 localAFAT_F01_init_inputs_fil_f;
  UInt16 localAFAT_F01_init_inputs_fi_jg;
  UInt16 localAFAT_F01_init_inputs_fi_cx;
  UInt16 localAFAT_F01_init_inputs_fi_op;
  UInt16 localAFAT_F01_init_inputs_fi_b1;
  SInt16 localAFAT_F01_init_inputs_fi_br;
  UInt16 localAFAT_F01_init_inputs_fil_k;
  UInt16 localAFAT_F01_init_inputs_fi_iy;
  SInt16 localAFAT_F01_init_inputs_fi_ef;
  SInt16 localAFAT_F01_init_inputs_fi_kj;
  UInt16 localAFAT_F01_init_inputs_fil_l;
  UInt8 localAFAT_F01_init_inputs_fi_dz;
  UInt16 localSwitch_i1;

  /* S-Function (fcncallgen): '<S4>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_EveRst_AFAClcFilInp_(003_MSE)'
   *
   * Block requirements for '<S1>/RE_AFAT_EveRst_AFAClcFilInp_(003_MSE)':
   *  1. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  2. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  3. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_195.01 ;
   *  4. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_175.01 ;
   *  5. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_176.01 ;
   *  6. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_177.01 ;
   *  7. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_163.01 ;
   *  8. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_164.01 ;
   *  9. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_165.01 ;
   *  10. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_166.01 ;
   *  11. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_167.01 ;
   *  12. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_170.01 ;
   *  13. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_171.01 ;
   *  14. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_173.01 ;
   *  15. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_180.01 ;
   *  16. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_182.01 ;
   *  17. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_183.01 ;
   *  18. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_184.01 ;
   *  19. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_187.01 ;
   *  20. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_188.01 ;
   *  21. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_189.01 ;
   *  22. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_190.01 ;
   *  23. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_191.01 ;
   *  24. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_192.01 ;
   *  25. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_193.01 ;
   *  26. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_196.01 ;
   *  27. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_198.01 ;
   *  28. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  29. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  30. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  31. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  32. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_240.01 ;
   *  33. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  34. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  35. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  36. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  37. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  38. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  39. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  40. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  41. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  42. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  43. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  44. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  45. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  46. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  47. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  48. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  49. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  50. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  51. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  52. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  53. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  54. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  55. SubSystem "RE_AFAT_EveRst_AFAClcFilInp_(023_MSE)" !Trace_To : VEMS_R_11_04467_328.01 ;
   */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_pDsThrPredOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrPred'
   */
  Rte_Read_R_InM_pDsThrPred_InM_pDsThrPred
    (&AFAT_B.TmpSignalConversionAtInM_pDsT_h);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_rAirPresOutport2' incorporates:
   *  Inport: '<Root>/InM_rAirPres'
   */
  Rte_Read_R_InM_rAirPres_InM_rAirPres(&AFAT_B.TmpSignalConversionAtInM_rAirPr);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_arEffAdpThrOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpThr'
   */
  Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr
    (&AFAT_B.TmpSignalConversionAtInM_arEffA);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_arEffAdpEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpEGRVlv'
   */
  Rte_Read_R_InM_arEffAdpEGRVlv_InM_arEffAdpEGRVlv
    (&AFAT_B.TmpSignalConversionAtInM_arEf_g);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_arEffEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffEGRVlv'
   */
  Rte_Read_R_InM_arEffEGRVlv_InM_arEffEGRVlv
    (&AFAT_B.TmpSignalConversionAtInM_arEffE);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInjrM_prm_facGainInjOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_facGainInj'
   */
  Rte_Read_R_InjrM_prm_facGainInj_InjrM_prm_facGainInj
    (&AFAT_B.TmpSignalConversionAtInjrM_pr_d);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor
    (&AFAT_B.TmpSignalConversionAtEngM_rAirL);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&AFAT_B.TmpSignalConversionAtThrLrn__kn);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&AFAT_B.TmpSignalConversionAtInM_pDsT_i);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_pDsThrEstimErrOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstimErr'
   */
  Rte_Read_R_InM_pDsThrEstimErr_InM_pDsThrEstimErr
    (&AFAT_B.TmpSignalConversionAtInM_pDsT_n);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExM_pExMnfEstim_facVlvOvlpOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim_facVlvOvlp'
   */
  Rte_Read_R_ExM_pExMnfEstim_facVlvOvlp_ExM_pExMnfEstim_facVlvOvlp
    (&AFAT_B.TmpSignalConversionAtExM_pExMnf);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&AFAT_B.TmpSignalConversionAtEngM_facSl);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExM_tExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExMnfEstim'
   */
  Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim
    (&AFAT_B.TmpSignalConversionAtExM_tExMnf);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&AFAT_B.TmpSignalConversionAtExt_nEng_i);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&AFAT_B.TmpSignalConversionAtInThM_tAir);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&AFAT_B.TmpSignalConversionAtEngM_agCkC);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&AFAT_B.TmpSignalConversionAtEngM_agCkO);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_rTotLdExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rTotLdExCor'
   */
  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor
    (&AFAT_B.TmpSignalConversionAtEngM_rTo_n);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (&AFAT_B.TmpSignalConversionAtEngM_agC_j);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt
    (&AFAT_B.TmpSignalConversionAtUsThrM_p_b);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInjSys_mFuReqOutport2' incorporates:
   *  Inport: '<Root>/InjSys_mFuReq'
   */
  Rte_Read_R_InjSys_mFuReq_InjSys_mFuReq(&AFAT_B.TmpSignalConversionAtInjSys_mFu);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInjrM_prm_facCorGainLnrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_facCorGainLnr'
   */
  Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr
    (&AFAT_B.TmpSignalConversionAtInjrM_prm_);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&AFAT_B.TmpSignalConversionAtExt_tCoMes);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_pDsThrPred_facVlvOvlpOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrPred_facVlvOvlp'
   */
  Rte_Read_R_InM_pDsThrPred_facVlvOvlp_InM_pDsThrPred_facVlvOvlp
    (&AFAT_B.TmpSignalConversionAtInM_pDsT_g);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim
    (&AFAT_B.TmpSignalConversionAtInM_pDsThr);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor
    (&AFAT_B.TmpSignalConversionAtUsThrM_pUs);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInjrM_prm_pDifInjrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_pDifInjr'
   */
  Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr
    (&AFAT_B.TmpSignalConversionAtInjrM_pr_p);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor(&AFAT_B.TmpSignalConversionAtInThM_nEng);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAfuA_rEthStoichOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthStoich'
   */
  Rte_Read_R_AfuA_rEthStoich_AfuA_rEthStoich
    (&AFAT_B.TmpSignalConversionAtAfuA_rEthS);

  /* SignalConversion: '<S10>/TmpSignal ConversionAtExt_facRhoFuOutport2' incorporates:
   *  Inport: '<Root>/Ext_facRhoFu'
   */
  Rte_Read_R_Ext_facRhoFu_Ext_facRhoFu(&AFAT_B.TmpSignalConversionAtExt_facRho);

  /* Outputs for atomic SubSystem: '<S10>/F01_init_inputs_filters' *
   * Block requirements for '<S10>/F01_init_inputs_filters':
   *  1. SubSystem "F01_init_inputs_filters" !Trace_To : VEMS_R_11_04467_058.02 ;
   */

  /* ModelReference: '<S136>/AFAT_F01_init_inputs_filters' */
  mr_AFA_F01_init_inputs_filters(&AFAT_B.TmpSignalConversionAtInM_pDsT_h,
    &AFAT_B.TmpSignalConversionAtInM_rAirPr,
    &AFAT_B.TmpSignalConversionAtInM_arEffA,
    &AFAT_B.TmpSignalConversionAtInM_arEf_g,
    &AFAT_B.TmpSignalConversionAtInM_arEffE,
    AFAT_B.TmpSignalConversionAtInjrM_pr_d,
    &AFAT_B.TmpSignalConversionAtEngM_rAirL,
    &AFAT_B.TmpSignalConversionAtThrLrn__kn,
    &AFAT_B.TmpSignalConversionAtInM_pDsT_i,
    &AFAT_B.TmpSignalConversionAtInM_pDsT_n,
    &AFAT_B.TmpSignalConversionAtExM_pExMnf,
    &AFAT_B.TmpSignalConversionAtEngM_facSl,
    &AFAT_B.TmpSignalConversionAtExM_tExMnf,
    &AFAT_B.TmpSignalConversionAtExt_nEng_i,
    &AFAT_B.TmpSignalConversionAtInThM_tAir,
    &AFAT_B.TmpSignalConversionAtEngM_agCkC,
    &AFAT_B.TmpSignalConversionAtEngM_agCkO,
    &AFAT_B.TmpSignalConversionAtEngM_rTo_n,
    &AFAT_B.TmpSignalConversionAtEngM_agC_j,
    &AFAT_B.TmpSignalConversionAtUsThrM_p_b,
    &AFAT_B.TmpSignalConversionAtInjSys_mFu,
    AFAT_B.TmpSignalConversionAtInjrM_prm_,
    &AFAT_B.TmpSignalConversionAtExt_tCoMes,
    &AFAT_B.TmpSignalConversionAtInM_pDsT_g,
    &AFAT_B.TmpSignalConversionAtInM_pDsThr,
    &AFAT_B.TmpSignalConversionAtUsThrM_pUs,
    AFAT_B.TmpSignalConversionAtInjrM_pr_p,
    &AFAT_B.TmpSignalConversionAtInThM_nEng,
    &AFAT_B.TmpSignalConversionAtAfuA_rEthS,
    &AFAT_B.TmpSignalConversionAtExt_facRho, &localAFAT_F01_init_inputs_fil_d,
    &localAFAT_F01_init_inputs_fil_g, &localAFAT_F01_init_inputs_fi_cx,
    &localAFAT_F01_init_inputs_fi_op, &localAFAT_F01_init_inputs_fi_b1,
    &localAFAT_F01_init_inputs_fil_b, localAFAT_F01_init_inputs_filte,
    &localAFAT_F01_init_inputs_fi_in, &localAFAT_F01_init_inputs_fil_k,
    &localAFAT_F01_init_inputs_fi_md, &localAFAT_F01_init_inputs_fi_br,
    &localAFAT_F01_init_inputs_fil_e, &localAFAT_F01_init_inputs_fi_cq,
    &localAFAT_F01_init_inputs_fil_l, &localAFAT_F01_init_inputs_fil_j,
    &localAFAT_F01_init_inputs_fil_i, &localAFAT_F01_init_inputs_fi_ef,
    &localAFAT_F01_init_inputs_fi_kj, &localAFAT_F01_init_inputs_fil_h,
    &localAFAT_F01_init_inputs_fi_iy, &localAFAT_F01_init_inputs_fi_ei,
    &localAFAT_F01_init_inputs_fil_c, localAFAT_F01_init_inputs_fil_m,
    &localAFAT_F01_init_inputs_fil_o, &localAFAT_F01_init_inputs_fi_av,
    &localAFAT_F01_init_inputs_fil_f, &localAFAT_F01_init_inputs_fi_jg,
    localAFAT_F01_init_inputs_fil_n, &localAFAT_F01_init_inputs_fil_a,
    &localAFAT_F01_init_inputs_fi_cf, &localAFAT_F01_init_inputs_fi_dz);

  /* S-Function Block: '<S112>/FixPt Data Type Propagation'
   *
   * Regarding '<S112>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S113>/FixPt Data Type Propagation'
   *
   * Regarding '<S113>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S114>/FixPt Data Type Propagation'
   *
   * Regarding '<S114>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S115>/FixPt Data Type Propagation'
   *
   * Regarding '<S115>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S116>/FixPt Data Type Propagation'
   *
   * Regarding '<S116>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S117>/FixPt Data Type Propagation'
   *
   * Regarding '<S117>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S118>/FixPt Data Type Propagation'
   *
   * Regarding '<S118>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S119>/FixPt Data Type Propagation'
   *
   * Regarding '<S119>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S120>/FixPt Data Type Propagation'
   *
   * Regarding '<S120>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S121>/FixPt Data Type Propagation'
   *
   * Regarding '<S121>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S122>/FixPt Data Type Propagation'
   *
   * Regarding '<S122>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S123>/FixPt Data Type Propagation'
   *
   * Regarding '<S123>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S124>/FixPt Data Type Propagation'
   *
   * Regarding '<S124>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S125>/FixPt Data Type Propagation'
   *
   * Regarding '<S125>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S126>/FixPt Data Type Propagation'
   *
   * Regarding '<S126>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S127>/FixPt Data Type Propagation'
   *
   * Regarding '<S127>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S128>/FixPt Data Type Propagation'
   *
   * Regarding '<S128>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S129>/FixPt Data Type Propagation'
   *
   * Regarding '<S129>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S130>/FixPt Data Type Propagation'
   *
   * Regarding '<S130>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S131>/FixPt Data Type Propagation'
   *
   * Regarding '<S131>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S132>/FixPt Data Type Propagation'
   *
   * Regarding '<S132>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S133>/FixPt Data Type Propagation'
   *
   * Regarding '<S133>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S134>/FixPt Data Type Propagation'
   *
   * Regarding '<S134>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S135>/FixPt Data Type Propagation'
   *
   * Regarding '<S135>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S112>/FixPt Gateway Out'
   *
   * Regarding '<S112>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S113>/FixPt Gateway Out'
   *
   * Regarding '<S113>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S114>/FixPt Gateway Out'
   *
   * Regarding '<S114>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S115>/FixPt Gateway Out'
   *
   * Regarding '<S115>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S116>/FixPt Gateway Out'
   *
   * Regarding '<S116>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S117>/FixPt Gateway Out'
   *
   * Regarding '<S117>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S118>/FixPt Gateway Out'
   *
   * Regarding '<S118>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S119>/FixPt Gateway Out'
   *
   * Regarding '<S119>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S120>/FixPt Gateway Out'
   *
   * Regarding '<S120>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S121>/FixPt Gateway Out'
   *
   * Regarding '<S121>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S122>/FixPt Gateway Out'
   *
   * Regarding '<S122>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S123>/FixPt Gateway Out'
   *
   * Regarding '<S123>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S124>/FixPt Gateway Out'
   *
   * Regarding '<S124>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S125>/FixPt Gateway Out'
   *
   * Regarding '<S125>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S126>/FixPt Gateway Out'
   *
   * Regarding '<S126>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S127>/FixPt Gateway Out'
   *
   * Regarding '<S127>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S128>/FixPt Gateway Out'
   *
   * Regarding '<S128>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S129>/FixPt Gateway Out'
   *
   * Regarding '<S129>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S130>/FixPt Gateway Out'
   *
   * Regarding '<S130>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S131>/FixPt Gateway Out'
   *
   * Regarding '<S131>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S132>/FixPt Gateway Out'
   *
   * Regarding '<S132>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S133>/FixPt Gateway Out'
   *
   * Regarding '<S133>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S134>/FixPt Gateway Out'
   *
   * Regarding '<S134>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S135>/FixPt Gateway Out'
   *
   * Regarding '<S135>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S161>/Data Type Conversion'
   *
   * Regarding '<S161>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S162>/Data Type Conversion'
   *
   * Regarding '<S162>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S163>/Data Type Conversion'
   *
   * Regarding '<S163>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S164>/Data Type Conversion'
   *
   * Regarding '<S164>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S10>/F01_init_inputs_filters' */

  /* DataStoreWrite: '<S10>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[0] = localAFAT_F01_init_inputs_filte[0];

  /* DataStoreWrite: '<S10>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[0] = localAFAT_F01_init_inputs_fil_n[0];

  /* DataStoreWrite: '<S10>/Data Store Write5' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[0] =
    localAFAT_F01_init_inputs_fil_m[0];

  /* DataStoreWrite: '<S10>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[1] = localAFAT_F01_init_inputs_filte[1];

  /* DataStoreWrite: '<S10>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[1] = localAFAT_F01_init_inputs_fil_n[1];

  /* DataStoreWrite: '<S10>/Data Store Write5' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[1] =
    localAFAT_F01_init_inputs_fil_m[1];

  /* DataStoreWrite: '<S10>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[2] = localAFAT_F01_init_inputs_filte[2];

  /* DataStoreWrite: '<S10>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[2] = localAFAT_F01_init_inputs_fil_n[2];

  /* DataStoreWrite: '<S10>/Data Store Write5' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[2] =
    localAFAT_F01_init_inputs_fil_m[2];

  /* DataStoreWrite: '<S10>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[3] = localAFAT_F01_init_inputs_filte[3];

  /* DataStoreWrite: '<S10>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[3] = localAFAT_F01_init_inputs_fil_n[3];

  /* DataStoreWrite: '<S10>/Data Store Write5' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[3] =
    localAFAT_F01_init_inputs_fil_m[3];

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write1' */
  /* S-Function Block: <S10>/autosar_irv_write1 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_facRhoFuFil_irv
    (localAFAT_F01_init_inputs_fi_dz);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write10' */

  /* S-Function Block: <S10>/autosar_irv_write10 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pDsThrEstimErrFil_irv
    (localAFAT_F01_init_inputs_fi_br);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write11' */

  /* S-Function Block: <S10>/autosar_irv_write11 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pExMnfEstimFil_irv
    (localAFAT_F01_init_inputs_fil_e);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write12' */

  /* S-Function Block: <S10>/autosar_irv_write12 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_facSlopEfcCorFil_irv
    (localAFAT_F01_init_inputs_fi_cq);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write13' */

  /* S-Function Block: <S10>/autosar_irv_write13 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_tExMnfEstimFil_irv
    (localAFAT_F01_init_inputs_fil_l);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write14' */

  /* S-Function Block: <S10>/autosar_irv_write14 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_nEngFil_irv(localAFAT_F01_init_inputs_fil_j);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write15' */

  /* S-Function Block: <S10>/autosar_irv_write15 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_tAirUsInVlvEstimFil_irv
    (localAFAT_F01_init_inputs_fil_i);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write16' */

  /* S-Function Block: <S10>/autosar_irv_write16 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_agCkClsExVlvEstimRef1Fil_irv
    (localAFAT_F01_init_inputs_fi_ef);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write17' */

  /* S-Function Block: <S10>/autosar_irv_write17 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_agCkOpInVlvEstimRef1Fil_irv
    (localAFAT_F01_init_inputs_fi_kj);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write18' */

  /* S-Function Block: <S10>/autosar_irv_write18 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_rTotLdExCorFil_irv
    (localAFAT_F01_init_inputs_fil_h);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write19' */

  /* S-Function Block: <S10>/autosar_irv_write19 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_agCkClsInVlvEstimRef1Fil_irv
    (localAFAT_F01_init_inputs_fi_iy);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write2' */

  /* S-Function Block: <S10>/autosar_irv_write2 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_arEffAdpThrFil_irv
    (localAFAT_F01_init_inputs_fi_cx);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write20' */

  /* S-Function Block: <S10>/autosar_irv_write20 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pAirExtEstimFil_irv
    (localAFAT_F01_init_inputs_fi_ei);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write21' */

  /* S-Function Block: <S10>/autosar_irv_write21 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_mFuReqFil_irv(localAFAT_F01_init_inputs_fil_c);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write23' */

  /* S-Function Block: <S10>/autosar_irv_write23 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_tCoMesFil_irv(localAFAT_F01_init_inputs_fil_o);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write24' */

  /* S-Function Block: <S10>/autosar_irv_write24 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pDsThrPred_facVlvOvlpFil_irv
    (localAFAT_F01_init_inputs_fi_av);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write25' */

  /* S-Function Block: <S10>/autosar_irv_write25 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pDsThrEstimFil_irv
    (localAFAT_F01_init_inputs_fil_f);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write3' */

  /* S-Function Block: <S10>/autosar_irv_write3 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_arEffAdpEGRVlvFil_irv
    (localAFAT_F01_init_inputs_fi_op);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write4' */

  /* S-Function Block: <S10>/autosar_irv_write4 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_arEffEGRVlvFil_irv
    (localAFAT_F01_init_inputs_fi_b1);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write5' */

  /* S-Function Block: <S10>/autosar_irv_write5 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_rInMassFlowFil_irv
    (localAFAT_F01_init_inputs_fil_b);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write6' */

  /* S-Function Block: <S10>/autosar_irv_write6 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_nEngCorFil_irv
    (localAFAT_F01_init_inputs_fil_a);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write7' */

  /* S-Function Block: <S10>/autosar_irv_write7 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_rEthStoichFil_irv
    (localAFAT_F01_init_inputs_fi_cf);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write8' */

  /* S-Function Block: <S10>/autosar_irv_write8 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_rOpSIFil_irv(localAFAT_F01_init_inputs_fil_k);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S10>/autosar_irv_write9' */

  /* S-Function Block: <S10>/autosar_irv_write9 */
  Rte_IrvWrite_RE_AFAT_003_MSE_AFA_pDsThrCorFil_irv
    (localAFAT_F01_init_inputs_fi_md);

  /* SignalConversion: '<S137>/copy' */
  AFA_rEthStoichFil_IRV_MP = localAFAT_F01_init_inputs_fi_cf;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S137>/autosar_testpoint1' */

  /* S-Function Block: <S137>/autosar_testpoint1 */

  /* SignalConversion: '<S138>/copy' */
  AFA_pDsThrEstimErrFil_IRV_MP = localAFAT_F01_init_inputs_fi_br;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S138>/autosar_testpoint1' */

  /* S-Function Block: <S138>/autosar_testpoint1 */

  /* SignalConversion: '<S139>/copy' */
  AFA_pExMnfEstimFil_IRV_MP = localAFAT_F01_init_inputs_fil_e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S139>/autosar_testpoint1' */

  /* S-Function Block: <S139>/autosar_testpoint1 */

  /* SignalConversion: '<S140>/copy' */
  AFA_facSlopEfcCorFil_IRV_MP = localAFAT_F01_init_inputs_fi_cq;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S140>/autosar_testpoint1' */

  /* S-Function Block: <S140>/autosar_testpoint1 */

  /* SignalConversion: '<S141>/copy' */
  AFA_tExMnfEstimFil_IRV_MP = localAFAT_F01_init_inputs_fil_l;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S141>/autosar_testpoint1' */

  /* S-Function Block: <S141>/autosar_testpoint1 */

  /* SignalConversion: '<S142>/copy' */
  AFA_nEngFil_IRV_MP = localAFAT_F01_init_inputs_fil_j;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S142>/autosar_testpoint1' */

  /* S-Function Block: <S142>/autosar_testpoint1 */

  /* SignalConversion: '<S143>/copy' */
  AFA_tAirUsInVlvEstimFil_IRV_MP = localAFAT_F01_init_inputs_fil_i;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S143>/autosar_testpoint1' */

  /* S-Function Block: <S143>/autosar_testpoint1 */

  /* SignalConversion: '<S144>/copy' */
  AFA_agCkClsExVlvEstimRef1Fil = localAFAT_F01_init_inputs_fi_ef;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S144>/autosar_testpoint1' */

  /* S-Function Block: <S144>/autosar_testpoint1 */

  /* SignalConversion: '<S145>/copy' */
  AFA_agCkOpInVlvEstimRef1Fil = localAFAT_F01_init_inputs_fi_kj;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S145>/autosar_testpoint1' */

  /* S-Function Block: <S145>/autosar_testpoint1 */

  /* SignalConversion: '<S146>/copy' */
  AFA_rTotLdExCorFil_IRV_MP = localAFAT_F01_init_inputs_fil_h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S146>/autosar_testpoint1' */

  /* S-Function Block: <S146>/autosar_testpoint1 */

  /* SignalConversion: '<S147>/copy' */
  AFA_agCkClsInVlvEstimRef1Fil = localAFAT_F01_init_inputs_fi_iy;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S147>/autosar_testpoint1' */

  /* S-Function Block: <S147>/autosar_testpoint1 */

  /* SignalConversion: '<S148>/copy' */
  AFA_arEffAdpThrFil_IRV_MP = localAFAT_F01_init_inputs_fi_cx;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S148>/autosar_testpoint1' */

  /* S-Function Block: <S148>/autosar_testpoint1 */

  /* SignalConversion: '<S149>/copy' */
  AFA_pAirExtEstimFil_IRV_MP = localAFAT_F01_init_inputs_fi_ei;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S149>/autosar_testpoint1' */

  /* S-Function Block: <S149>/autosar_testpoint1 */

  /* SignalConversion: '<S150>/copy' */
  AFA_mFuReqFil_IRV_MP = localAFAT_F01_init_inputs_fil_c;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S150>/autosar_testpoint1' */

  /* S-Function Block: <S150>/autosar_testpoint1 */

  /* SignalConversion: '<S151>/copy' */
  AFA_tCoMesFil_IRV_MP = localAFAT_F01_init_inputs_fil_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S151>/autosar_testpoint1' */

  /* S-Function Block: <S151>/autosar_testpoint1 */

  /* SignalConversion: '<S152>/copy' */
  AFA_pDsThrPred_facVlvOvlpFil = localAFAT_F01_init_inputs_fi_av;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S152>/autosar_testpoint1' */

  /* S-Function Block: <S152>/autosar_testpoint1 */

  /* SignalConversion: '<S153>/copy' */
  AFA_pDsThrEstimFil_IRV_MP = localAFAT_F01_init_inputs_fil_f;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S153>/autosar_testpoint1' */

  /* S-Function Block: <S153>/autosar_testpoint1 */

  /* SignalConversion: '<S154>/copy' */
  AFA_arEffAdpEGRVlvFil_IRV_MP = localAFAT_F01_init_inputs_fi_op;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S154>/autosar_testpoint1' */

  /* S-Function Block: <S154>/autosar_testpoint1 */

  /* SignalConversion: '<S155>/copy' */
  AFA_arEffEGRVlvFil_IRV_MP = localAFAT_F01_init_inputs_fi_b1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S155>/autosar_testpoint1' */

  /* S-Function Block: <S155>/autosar_testpoint1 */

  /* SignalConversion: '<S156>/copy' */
  AFA_rInMassFlowFil_IRV_MP = localAFAT_F01_init_inputs_fil_b;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S156>/autosar_testpoint1' */

  /* S-Function Block: <S156>/autosar_testpoint1 */

  /* SignalConversion: '<S157>/copy' */
  AFA_nEngCorFil_IRV_MP = localAFAT_F01_init_inputs_fil_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S157>/autosar_testpoint1' */

  /* S-Function Block: <S157>/autosar_testpoint1 */

  /* SignalConversion: '<S158>/copy' */
  AFA_facRhoFuFil_IRV_MP = localAFAT_F01_init_inputs_fi_dz;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S158>/autosar_testpoint1' */

  /* S-Function Block: <S158>/autosar_testpoint1 */

  /* SignalConversion: '<S159>/copy' */
  AFA_rOpSIFil_IRV_MP = localAFAT_F01_init_inputs_fil_k;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S159>/autosar_testpoint1' */

  /* S-Function Block: <S159>/autosar_testpoint1 */

  /* SignalConversion: '<S160>/copy' */
  AFA_pDsThrCorFil_IRV_MP = localAFAT_F01_init_inputs_fi_md;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S160>/autosar_testpoint1' */

  /* S-Function Block: <S160>/autosar_testpoint1 */

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/Byp_Fonction_SC'
   *  Constant: '<S162>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_i1 = AFA_pDsThrPredFil_B;
  } else {
    localSwitch_i1 = localAFAT_F01_init_inputs_fil_d;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFA_pDsThrPredFilInport2' */
  Rte_Write_P_AFA_pDsThrPredFil_AFA_pDsThrPredFil(localSwitch_i1);

  /* Switch: '<S164>/Switch' incorporates:
   *  Constant: '<S164>/Byp_Fonction_SC'
   *  Constant: '<S164>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_i1 = AFA_pUsThrCorFil_B;
  } else {
    localSwitch_i1 = localAFAT_F01_init_inputs_fi_jg;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFA_pUsThrCorFilInport2' */
  Rte_Write_P_AFA_pUsThrCorFil_AFA_pUsThrCorFil(localSwitch_i1);

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/Byp_Fonction_SC'
   *  Constant: '<S163>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_i1 = AFA_rAirLdCorFil_B;
  } else {
    localSwitch_i1 = localAFAT_F01_init_inputs_fi_in;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFA_rAirLdCorFilInport2' */
  Rte_Write_P_AFA_rAirLdCorFil_AFA_rAirLdCorFil(localSwitch_i1);

  /* Switch: '<S161>/Switch' incorporates:
   *  Constant: '<S161>/Byp_Fonction_SC'
   *  Constant: '<S161>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_i1 = AFA_rAirPresFil_B;
  } else {
    localSwitch_i1 = localAFAT_F01_init_inputs_fil_g;
  }

  /* SignalConversion: '<S10>/TmpSignal ConversionAtAFA_rAirPresFilInport2' */
  Rte_Write_P_AFA_rAirPresFil_AFA_rAirPresFil(localSwitch_i1);
}

/* Start for exported function: RE_AFAT_004_TEV */
void RE_AFAT_004_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_SdlFast_AFAClcFilInp_(004_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlFast_AFAClcFilInp_(004_TEV)':
   *  1. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  2. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  3. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_195.01 ;
   *  4. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_175.01 ;
   *  5. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_176.01 ;
   *  6. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_177.01 ;
   *  7. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_163.01 ;
   *  8. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_164.01 ;
   *  9. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_165.01 ;
   *  10. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_166.01 ;
   *  11. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_167.01 ;
   *  12. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_170.01 ;
   *  13. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_171.01 ;
   *  14. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_173.01 ;
   *  15. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_180.01 ;
   *  16. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_182.01 ;
   *  17. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_183.01 ;
   *  18. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_184.01 ;
   *  19. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_185.01 ;
   *  20. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_186.01 ;
   *  21. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_187.01 ;
   *  22. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_188.01 ;
   *  23. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_189.01 ;
   *  24. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_190.01 ;
   *  25. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_191.01 ;
   *  26. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_192.01 ;
   *  27. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_193.01 ;
   *  28. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_196.01 ;
   *  29. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_198.01 ;
   *  30. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  31. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  32. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  33. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  34. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  35. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  36. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  37. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  38. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  39. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  40. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  41. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  42. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  43. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  44. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  45. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  46. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  47. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  48. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  49. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  50. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  51. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  52. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  53. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  54. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  55. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  56. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  57. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  58. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_329.01 ;
   */
}

/* Output and update for exported function: RE_AFAT_004_TEV */
void RE_AFAT_004_TEV(void)
{
  /* local block i/o variables */
  UInt32 localAFAT_F02_inputs_filters_o7[4];
  UInt32 localAFAT_F02_inputs_filters_o2[4];
  UInt32 localTmpSignalConversionAtInjSy;
  UInt32 localAFAT_F02_inputs_filters__n;
  UInt32 localTmpSignalConversionAtInM_p;
  UInt32 localAFAT_F02_inputs_filters_o1;
  UInt32 localAFAT_F02_inputs_filters__e;
  SInt16 localTmpSignalConversionAtExt_t;
  SInt16 localAFAT_F02_inputs_filters__m;
  UInt16 localTmpSignalConversionAtExt_n;
  UInt16 localTmpSignalConversionAtInThM;
  UInt16 localAFAT_F02_inputs_filters__f;
  UInt16 localAFAT_F02_inputs_filters__h;
  UInt16 localTmpSignalConversionAtInjrM[4];
  UInt16 localTmpSignalConversionAtAfuA_;
  UInt16 localAFAT_F02_inputs_filters_f4[4];
  UInt16 localAFAT_F02_inputs_filters_o3;
  UInt16 localTmpSignalConversionAtEngM_;
  UInt16 localTmpSignalConversionAtEng_l;
  UInt16 localAFAT_F02_inputs_filters_o8;
  UInt16 localAFAT_F02_inputs_filters_hn;
  UInt16 localTmpSignalConversionAtInM_r;
  UInt16 localTmpSignalConversionAtInM_m;
  UInt16 localTmpSignalConversionAtInM_i;
  UInt16 localAFAT_F02_inputs_filters__l;
  UInt16 localAFAT_F02_inputs_filters_o6;
  SInt16 localTmpSignalConversionAtEn_l5;
  SInt16 localTmpSignalConversionAtEng_k;
  UInt16 localTmpSignalConversionAtEng_j;
  UInt16 localTmpSignalConversionAtEn_kl;
  UInt16 localTmpSignalConversionAtInM_d;
  UInt16 localTmpSignalConversionAtInM_l;
  UInt16 localTmpSignalConversionAtExM_p;
  UInt16 localTmpSignalConversionAtUsThr;
  UInt16 localTmpSignalConversionAtInM_f;
  UInt16 localTmpSignalConversionAtUsT_l;
  UInt16 localAFAT_F02_inputs_filters_hw;
  UInt16 localAFAT_F02_inputs_filters__b;
  UInt16 localAFAT_F02_inputs_filters__d;
  UInt16 localAFAT_F02_inputs_filters__c;
  UInt16 localAFAT_F02_inputs_filters__k;
  UInt16 localAFAT_F02_inputs_filters_bb;
  UInt16 localAFAT_F02_inputs_filter_hne;
  UInt16 localTmpSignalConversionAtExM_t;
  UInt16 localTmpSignalConversionAtInj_p[4];
  UInt16 localTmpSignalConversionAtInj_i[4];
  UInt16 localTmpSignalConversionAtInM_a;
  UInt16 localTmpSignalConversionAtInM_b;
  UInt16 localTmpSignalConversionAtInM_g;
  UInt16 localAFAT_F02_inputs_filters_f3;
  UInt16 localAFAT_F02_inputs_filters_o4;
  UInt16 localAFAT_F02_inputs_filters_o5;
  SInt16 localTmpSignalConversionAtIn_by;
  SInt16 localAFAT_F02_inputs_filters_bx;
  UInt16 localTmpSignalConversionAtInT_b;
  UInt16 localTmpSignalConversionAtThrLr;
  UInt16 localAFAT_F02_inputs_filters_o9;
  UInt16 localAFAT_F02_inputs_filters_l5;
  SInt16 localAFAT_F02_inputs_filters__j;
  SInt16 localAFAT_F02_inputs_filters_b4;
  UInt16 localAFAT_F02_inputs_filters__o;
  UInt8 localTmpSignalConversionAtExt_f;
  UInt8 localAFAT_F02_inputs_filters__p;
  UInt16 localSwitch_hj;

  /* S-Function (fcncallgen): '<S5>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_SdlFast_AFAClcFilInp_(004_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlFast_AFAClcFilInp_(004_TEV)':
   *  1. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  2. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  3. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_195.01 ;
   *  4. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_175.01 ;
   *  5. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_176.01 ;
   *  6. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_177.01 ;
   *  7. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_163.01 ;
   *  8. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_164.01 ;
   *  9. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_165.01 ;
   *  10. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_166.01 ;
   *  11. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_167.01 ;
   *  12. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_170.01 ;
   *  13. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_171.01 ;
   *  14. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_173.01 ;
   *  15. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_180.01 ;
   *  16. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_182.01 ;
   *  17. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_183.01 ;
   *  18. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_184.01 ;
   *  19. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_185.01 ;
   *  20. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_186.01 ;
   *  21. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_187.01 ;
   *  22. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_188.01 ;
   *  23. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_189.01 ;
   *  24. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_190.01 ;
   *  25. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_191.01 ;
   *  26. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_192.01 ;
   *  27. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_193.01 ;
   *  28. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_196.01 ;
   *  29. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_198.01 ;
   *  30. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  31. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  32. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_226.01 ;
   *  33. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_228.01 ;
   *  34. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_229.01 ;
   *  35. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_230.01 ;
   *  36. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  37. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  38. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  39. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  40. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  41. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  42. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  43. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  44. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  45. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  46. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  47. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  48. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  49. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  50. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  51. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  52. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  53. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  54. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  55. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  56. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  57. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  58. SubSystem "RE_AFAT_SdlFast_AFAClcFilInp_(024_TEV)" !Trace_To : VEMS_R_11_04467_329.01 ;
   */

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_pDsThrPredOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrPred'
   */
  Rte_Read_R_InM_pDsThrPred_InM_pDsThrPred(&localTmpSignalConversionAtInM_d);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_rAirPresOutport2' incorporates:
   *  Inport: '<Root>/InM_rAirPres'
   */
  Rte_Read_R_InM_rAirPres_InM_rAirPres(&localTmpSignalConversionAtInM_r);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_arEffAdpThrOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpThr'
   */
  Rte_Read_R_InM_arEffAdpThr_InM_arEffAdpThr(&localTmpSignalConversionAtInM_a);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_arEffAdpEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffAdpEGRVlv'
   */
  Rte_Read_R_InM_arEffAdpEGRVlv_InM_arEffAdpEGRVlv
    (&localTmpSignalConversionAtInM_b);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_arEffEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_arEffEGRVlv'
   */
  Rte_Read_R_InM_arEffEGRVlv_InM_arEffEGRVlv(&localTmpSignalConversionAtInM_g);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_mfEGREstimEGRVlvOutport2' incorporates:
   *  Inport: '<Root>/InM_mfEGREstimEGRVlv'
   */
  Rte_Read_R_InM_mfEGREstimEGRVlv_InM_mfEGREstimEGRVlv
    (&localTmpSignalConversionAtInM_m);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_mfAirThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_mfAirThrEstim'
   */
  Rte_Read_R_InM_mfAirThrEstim_InM_mfAirThrEstim
    (&localTmpSignalConversionAtInM_i);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrM_prm_facGainInjOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_facGainInj'
   */
  Rte_Read_R_InjrM_prm_facGainInj_InjrM_prm_facGainInj
    (&localTmpSignalConversionAtInj_p);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rAirLdCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rAirLdCor'
   */
  Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&localTmpSignalConversionAtEngM_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&localTmpSignalConversionAtThrLr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_pDsThrCorOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrCor'
   */
  Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&localTmpSignalConversionAtInM_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_pDsThrEstimErrOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstimErr'
   */
  Rte_Read_R_InM_pDsThrEstimErr_InM_pDsThrEstimErr
    (&localTmpSignalConversionAtIn_by);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExM_pExMnfEstim_facVlvOvlpOutport2' incorporates:
   *  Inport: '<Root>/ExM_pExMnfEstim_facVlvOvlp'
   */
  Rte_Read_R_ExM_pExMnfEstim_facVlvOvlp_ExM_pExMnfEstim_facVlvOvlp
    (&localTmpSignalConversionAtExM_p);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_facSlopEfcCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_facSlopEfcCor'
   */
  Rte_Read_R_EngM_facSlopEfcCor_EngM_facSlopEfcCor
    (&localTmpSignalConversionAtEn_kl);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExM_tExMnfEstimOutport2' incorporates:
   *  Inport: '<Root>/ExM_tExMnfEstim'
   */
  Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&localTmpSignalConversionAtExM_t);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&localTmpSignalConversionAtExt_n);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInThM_tAirUsInVlvEstimOutport2' incorporates:
   *  Inport: '<Root>/InThM_tAirUsInVlvEstim'
   */
  Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim
    (&localTmpSignalConversionAtInT_b);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_agCkClsExVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsExVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsExVlvEstimRef1_EngM_agCkClsExVlvEstimRef1
    (&localTmpSignalConversionAtEn_l5);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_agCkOpInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkOpInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkOpInVlvEstimRef1_EngM_agCkOpInVlvEstimRef1
    (&localTmpSignalConversionAtEng_k);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_rTotLdExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rTotLdExCor'
   */
  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor(&localTmpSignalConversionAtEng_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtEngM_agCkClsInVlvEstimRef1Outport2' incorporates:
   *  Inport: '<Root>/EngM_agCkClsInVlvEstimRef1'
   */
  Rte_Read_R_EngM_agCkClsInVlvEstimRef1_EngM_agCkClsInVlvEstimRef1
    (&localTmpSignalConversionAtEng_j);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtUsThrM_pAirExtOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExt'
   */
  Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&localTmpSignalConversionAtUsThr);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjSys_mFuReqOutport2' incorporates:
   *  Inport: '<Root>/InjSys_mFuReq'
   */
  Rte_Read_R_InjSys_mFuReq_InjSys_mFuReq(&localTmpSignalConversionAtInjSy);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrM_prm_facCorGainLnrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_facCorGainLnr'
   */
  Rte_Read_R_InjrM_prm_facCorGainLnr_InjrM_prm_facCorGainLnr
    (&localTmpSignalConversionAtInjrM);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_tCoMesOutport2' incorporates:
   *  Inport: '<Root>/Ext_tCoMes'
   */
  Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&localTmpSignalConversionAtExt_t);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_pDsThrPred_facVlvOvlpOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrPred_facVlvOvlp'
   */
  Rte_Read_R_InM_pDsThrPred_facVlvOvlp_InM_pDsThrPred_facVlvOvlp
    (&localTmpSignalConversionAtInM_f);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInM_pDsThrEstimOutport2' incorporates:
   *  Inport: '<Root>/InM_pDsThrEstim'
   */
  Rte_Read_R_InM_pDsThrEstim_InM_pDsThrEstim(&localTmpSignalConversionAtInM_p);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtUsThrM_pUsThrCorOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pUsThrCor'
   */
  Rte_Read_R_UsThrM_pUsThrCor_UsThrM_pUsThrCor(&localTmpSignalConversionAtUsT_l);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInjrM_prm_pDifInjrOutport2' incorporates:
   *  Inport: '<Root>/InjrM_prm_pDifInjr'
   */
  Rte_Read_R_InjrM_prm_pDifInjr_InjrM_prm_pDifInjr
    (&localTmpSignalConversionAtInj_i);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtInThM_nEngCorOutport2' incorporates:
   *  Inport: '<Root>/InThM_nEngCor'
   */
  Rte_Read_R_InThM_nEngCor_InThM_nEngCor(&localTmpSignalConversionAtInThM);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAfuA_rEthStoichOutport2' incorporates:
   *  Inport: '<Root>/AfuA_rEthStoich'
   */
  Rte_Read_R_AfuA_rEthStoich_AfuA_rEthStoich(&localTmpSignalConversionAtAfuA_);

  /* SignalConversion: '<S11>/TmpSignal ConversionAtExt_facRhoFuOutport2' incorporates:
   *  Inport: '<Root>/Ext_facRhoFu'
   */
  Rte_Read_R_Ext_facRhoFu_Ext_facRhoFu(&localTmpSignalConversionAtExt_f);

  /* Outputs for atomic SubSystem: '<S11>/F02_inputs_filters' *
   * Block requirements for '<S11>/F02_inputs_filters':
   *  1. SubSystem "F02_inputs_filters" !Trace_To : VEMS_R_11_04467_059.02 ;
   */

  /* ModelReference: '<S189>/AFAT_F02_inputs_filters' */
  mr_AFA_F02_inputs_filters(&localTmpSignalConversionAtInM_d,
    &localTmpSignalConversionAtInM_r, &localTmpSignalConversionAtInM_a,
    &localTmpSignalConversionAtInM_b, &localTmpSignalConversionAtInM_g,
    &localTmpSignalConversionAtInM_m, &localTmpSignalConversionAtInM_i,
    localTmpSignalConversionAtInj_p, &localTmpSignalConversionAtEngM_,
    &localTmpSignalConversionAtThrLr, &localTmpSignalConversionAtInM_l,
    &localTmpSignalConversionAtIn_by, &localTmpSignalConversionAtExM_p,
    &localTmpSignalConversionAtEn_kl, &localTmpSignalConversionAtExM_t,
    &localTmpSignalConversionAtExt_n, &localTmpSignalConversionAtInT_b,
    &localTmpSignalConversionAtEn_l5, &localTmpSignalConversionAtEng_k,
    &localTmpSignalConversionAtEng_l, &localTmpSignalConversionAtEng_j,
    &localTmpSignalConversionAtUsThr, &localTmpSignalConversionAtInjSy,
    localTmpSignalConversionAtInjrM, &localTmpSignalConversionAtExt_t,
    &localTmpSignalConversionAtInM_f, &localTmpSignalConversionAtInM_p,
    &localTmpSignalConversionAtUsT_l, localTmpSignalConversionAtInj_i,
    &localTmpSignalConversionAtInThM, &localTmpSignalConversionAtAfuA_,
    &localTmpSignalConversionAtExt_f, &localAFAT_F02_inputs_filters_hw,
    &localAFAT_F02_inputs_filters__l, &localAFAT_F02_inputs_filters_f3,
    &localAFAT_F02_inputs_filters_o4, &localAFAT_F02_inputs_filters_o5,
    &localAFAT_F02_inputs_filters_o6, localAFAT_F02_inputs_filters_o7,
    &localAFAT_F02_inputs_filters_o8, &localAFAT_F02_inputs_filters_o9,
    &localAFAT_F02_inputs_filters__b, &localAFAT_F02_inputs_filters_bx,
    &localAFAT_F02_inputs_filters__d, &localAFAT_F02_inputs_filters__e,
    &localAFAT_F02_inputs_filters__o, &localAFAT_F02_inputs_filters__f,
    &localAFAT_F02_inputs_filters_o1, &localAFAT_F02_inputs_filters__j,
    &localAFAT_F02_inputs_filters_b4, &localAFAT_F02_inputs_filters_hn,
    &localAFAT_F02_inputs_filters_l5, &localAFAT_F02_inputs_filters__c,
    &localAFAT_F02_inputs_filters__n, localAFAT_F02_inputs_filters_f4,
    &localAFAT_F02_inputs_filters__m, &localAFAT_F02_inputs_filters__k,
    &localAFAT_F02_inputs_filters_bb, &localAFAT_F02_inputs_filter_hne,
    localAFAT_F02_inputs_filters_o2, &localAFAT_F02_inputs_filters__h,
    &localAFAT_F02_inputs_filters_o3, &localAFAT_F02_inputs_filters__p);

  /* S-Function Block: '<S165>/FixPt Data Type Propagation'
   *
   * Regarding '<S165>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S166>/FixPt Data Type Propagation'
   *
   * Regarding '<S166>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S167>/FixPt Data Type Propagation'
   *
   * Regarding '<S167>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S168>/FixPt Data Type Propagation'
   *
   * Regarding '<S168>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S169>/FixPt Data Type Propagation'
   *
   * Regarding '<S169>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S170>/FixPt Data Type Propagation'
   *
   * Regarding '<S170>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S171>/FixPt Data Type Propagation'
   *
   * Regarding '<S171>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S172>/FixPt Data Type Propagation'
   *
   * Regarding '<S172>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S173>/FixPt Data Type Propagation'
   *
   * Regarding '<S173>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S174>/FixPt Data Type Propagation'
   *
   * Regarding '<S174>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S175>/FixPt Data Type Propagation'
   *
   * Regarding '<S175>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S176>/FixPt Data Type Propagation'
   *
   * Regarding '<S176>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S177>/FixPt Data Type Propagation'
   *
   * Regarding '<S177>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S178>/FixPt Data Type Propagation'
   *
   * Regarding '<S178>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S179>/FixPt Data Type Propagation'
   *
   * Regarding '<S179>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S180>/FixPt Data Type Propagation'
   *
   * Regarding '<S180>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S181>/FixPt Data Type Propagation'
   *
   * Regarding '<S181>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S182>/FixPt Data Type Propagation'
   *
   * Regarding '<S182>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S183>/FixPt Data Type Propagation'
   *
   * Regarding '<S183>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S184>/FixPt Data Type Propagation'
   *
   * Regarding '<S184>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S185>/FixPt Data Type Propagation'
   *
   * Regarding '<S185>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S186>/FixPt Data Type Propagation'
   *
   * Regarding '<S186>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S187>/FixPt Data Type Propagation'
   *
   * Regarding '<S187>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S188>/FixPt Data Type Propagation'
   *
   * Regarding '<S188>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S165>/FixPt Gateway Out'
   *
   * Regarding '<S165>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S166>/FixPt Gateway Out'
   *
   * Regarding '<S166>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S167>/FixPt Gateway Out'
   *
   * Regarding '<S167>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S168>/FixPt Gateway Out'
   *
   * Regarding '<S168>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S169>/FixPt Gateway Out'
   *
   * Regarding '<S169>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S170>/FixPt Gateway Out'
   *
   * Regarding '<S170>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S171>/FixPt Gateway Out'
   *
   * Regarding '<S171>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S172>/FixPt Gateway Out'
   *
   * Regarding '<S172>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S173>/FixPt Gateway Out'
   *
   * Regarding '<S173>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S174>/FixPt Gateway Out'
   *
   * Regarding '<S174>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S175>/FixPt Gateway Out'
   *
   * Regarding '<S175>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S176>/FixPt Gateway Out'
   *
   * Regarding '<S176>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S177>/FixPt Gateway Out'
   *
   * Regarding '<S177>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S178>/FixPt Gateway Out'
   *
   * Regarding '<S178>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S179>/FixPt Gateway Out'
   *
   * Regarding '<S179>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S180>/FixPt Gateway Out'
   *
   * Regarding '<S180>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S181>/FixPt Gateway Out'
   *
   * Regarding '<S181>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S182>/FixPt Gateway Out'
   *
   * Regarding '<S182>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S183>/FixPt Gateway Out'
   *
   * Regarding '<S183>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S184>/FixPt Gateway Out'
   *
   * Regarding '<S184>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S185>/FixPt Gateway Out'
   *
   * Regarding '<S185>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S186>/FixPt Gateway Out'
   *
   * Regarding '<S186>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S187>/FixPt Gateway Out'
   *
   * Regarding '<S187>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S188>/FixPt Gateway Out'
   *
   * Regarding '<S188>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion Block: '<S190>/copy'
   *
   * Regarding '<S190>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S191>/copy'
   *
   * Regarding '<S191>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S192>/copy'
   *
   * Regarding '<S192>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S193>/copy'
   *
   * Regarding '<S193>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S194>/copy'
   *
   * Regarding '<S194>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S195>/copy'
   *
   * Regarding '<S195>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S196>/copy'
   *
   * Regarding '<S196>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S197>/copy'
   *
   * Regarding '<S197>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S198>/copy'
   *
   * Regarding '<S198>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S199>/copy'
   *
   * Regarding '<S199>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S200>/copy'
   *
   * Regarding '<S200>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S201>/copy'
   *
   * Regarding '<S201>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S202>/copy'
   *
   * Regarding '<S202>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S203>/copy'
   *
   * Regarding '<S203>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S204>/copy'
   *
   * Regarding '<S204>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S205>/copy'
   *
   * Regarding '<S205>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S206>/copy'
   *
   * Regarding '<S206>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S207>/copy'
   *
   * Regarding '<S207>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S208>/copy'
   *
   * Regarding '<S208>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S209>/copy'
   *
   * Regarding '<S209>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S210>/copy'
   *
   * Regarding '<S210>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S211>/copy'
   *
   * Regarding '<S211>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S212>/copy'
   *
   * Regarding '<S212>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S213>/copy'
   *
   * Regarding '<S213>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* DataTypeConversion Block: '<S214>/Data Type Conversion'
   *
   * Regarding '<S214>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S215>/Data Type Conversion'
   *
   * Regarding '<S215>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S216>/Data Type Conversion'
   *
   * Regarding '<S216>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S217>/Data Type Conversion'
   *
   * Regarding '<S217>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S11>/F02_inputs_filters' */

  /* DataStoreWrite: '<S11>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[0] = localAFAT_F02_inputs_filters_o7[0];

  /* DataStoreWrite: '<S11>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[0] = localAFAT_F02_inputs_filters_o2[0];

  /* DataStoreWrite: '<S11>/Data Store Write7' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[0] =
    localAFAT_F02_inputs_filters_f4[0];

  /* DataStoreWrite: '<S11>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[1] = localAFAT_F02_inputs_filters_o7[1];

  /* DataStoreWrite: '<S11>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[1] = localAFAT_F02_inputs_filters_o2[1];

  /* DataStoreWrite: '<S11>/Data Store Write7' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[1] =
    localAFAT_F02_inputs_filters_f4[1];

  /* DataStoreWrite: '<S11>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[2] = localAFAT_F02_inputs_filters_o7[2];

  /* DataStoreWrite: '<S11>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[2] = localAFAT_F02_inputs_filters_o2[2];

  /* DataStoreWrite: '<S11>/Data Store Write7' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[2] =
    localAFAT_F02_inputs_filters_f4[2];

  /* DataStoreWrite: '<S11>/Data Store Write1' */
  (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[3] = localAFAT_F02_inputs_filters_o7[3];

  /* DataStoreWrite: '<S11>/Data Store Write2' */
  (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[3] = localAFAT_F02_inputs_filters_o2[3];

  /* DataStoreWrite: '<S11>/Data Store Write7' */
  (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())[3] =
    localAFAT_F02_inputs_filters_f4[3];

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write1' */
  /* S-Function Block: <S11>/autosar_irv_write1 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_rEthStoichFil_irv
    (localAFAT_F02_inputs_filters_o3);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write10' */

  /* S-Function Block: <S11>/autosar_irv_write10 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pDsThrEstimErrFil_irv
    (localAFAT_F02_inputs_filters_bx);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write11' */

  /* S-Function Block: <S11>/autosar_irv_write11 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pExMnfEstimFil_irv
    (localAFAT_F02_inputs_filters__d);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write12' */

  /* S-Function Block: <S11>/autosar_irv_write12 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_facSlopEfcCorFil_irv
    (localAFAT_F02_inputs_filters__e);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write13' */

  /* S-Function Block: <S11>/autosar_irv_write13 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_tExMnfEstimFil_irv
    (localAFAT_F02_inputs_filters__o);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write14' */

  /* S-Function Block: <S11>/autosar_irv_write14 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_nEngFil_irv(localAFAT_F02_inputs_filters__f);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write15' */

  /* S-Function Block: <S11>/autosar_irv_write15 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_tAirUsInVlvEstimFil_irv
    (localAFAT_F02_inputs_filters_o1);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write16' */

  /* S-Function Block: <S11>/autosar_irv_write16 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_agCkClsExVlvEstimRef1Fil_irv
    (localAFAT_F02_inputs_filters__j);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write17' */

  /* S-Function Block: <S11>/autosar_irv_write17 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_agCkOpInVlvEstimRef1Fil_irv
    (localAFAT_F02_inputs_filters_b4);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write18' */

  /* S-Function Block: <S11>/autosar_irv_write18 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_rTotLdExCorFil_irv
    (localAFAT_F02_inputs_filters_hn);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write19' */

  /* S-Function Block: <S11>/autosar_irv_write19 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_agCkClsInVlvEstimRef1Fil_irv
    (localAFAT_F02_inputs_filters_l5);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write2' */

  /* S-Function Block: <S11>/autosar_irv_write2 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_arEffAdpThrFil_irv
    (localAFAT_F02_inputs_filters_f3);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write20' */

  /* S-Function Block: <S11>/autosar_irv_write20 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pAirExtEstimFil_irv
    (localAFAT_F02_inputs_filters__c);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write21' */

  /* S-Function Block: <S11>/autosar_irv_write21 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_mFuReqFil_irv(localAFAT_F02_inputs_filters__n);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write23' */

  /* S-Function Block: <S11>/autosar_irv_write23 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_tCoMesFil_irv(localAFAT_F02_inputs_filters__m);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write24' */

  /* S-Function Block: <S11>/autosar_irv_write24 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pDsThrPred_facVlvOvlpFil_irv
    (localAFAT_F02_inputs_filters__k);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write25' */

  /* S-Function Block: <S11>/autosar_irv_write25 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pDsThrEstimFil_irv
    (localAFAT_F02_inputs_filters_bb);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write3' */

  /* S-Function Block: <S11>/autosar_irv_write3 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_arEffAdpEGRVlvFil_irv
    (localAFAT_F02_inputs_filters_o4);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write4' */

  /* S-Function Block: <S11>/autosar_irv_write4 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_arEffEGRVlvFil_irv
    (localAFAT_F02_inputs_filters_o5);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write5' */

  /* S-Function Block: <S11>/autosar_irv_write5 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_rInMassFlowFil_irv
    (localAFAT_F02_inputs_filters_o6);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write6' */

  /* S-Function Block: <S11>/autosar_irv_write6 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_nEngCorFil_irv
    (localAFAT_F02_inputs_filters__h);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write7' */

  /* S-Function Block: <S11>/autosar_irv_write7 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_facRhoFuFil_irv
    (localAFAT_F02_inputs_filters__p);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write8' */

  /* S-Function Block: <S11>/autosar_irv_write8 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_rOpSIFil_irv(localAFAT_F02_inputs_filters_o9);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S11>/autosar_irv_write9' */

  /* S-Function Block: <S11>/autosar_irv_write9 */
  Rte_IrvWrite_RE_AFAT_004_TEV_AFA_pDsThrCorFil_irv
    (localAFAT_F02_inputs_filters__b);

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S190>/autosar_testpoint1' */

  /* S-Function Block: <S190>/autosar_testpoint1 */
  AFA_rEthStoichFil_IRV_MP = localAFAT_F02_inputs_filters_o3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S191>/autosar_testpoint1' */

  /* S-Function Block: <S191>/autosar_testpoint1 */
  AFA_pDsThrEstimErrFil_IRV_MP = localAFAT_F02_inputs_filters_bx;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S192>/autosar_testpoint1' */

  /* S-Function Block: <S192>/autosar_testpoint1 */
  AFA_pExMnfEstimFil_IRV_MP = localAFAT_F02_inputs_filters__d;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S193>/autosar_testpoint1' */

  /* S-Function Block: <S193>/autosar_testpoint1 */
  AFA_facSlopEfcCorFil_IRV_MP = localAFAT_F02_inputs_filters__e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S194>/autosar_testpoint1' */

  /* S-Function Block: <S194>/autosar_testpoint1 */
  AFA_tExMnfEstimFil_IRV_MP = localAFAT_F02_inputs_filters__o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S195>/autosar_testpoint1' */

  /* S-Function Block: <S195>/autosar_testpoint1 */
  AFA_nEngFil_IRV_MP = localAFAT_F02_inputs_filters__f;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S196>/autosar_testpoint1' */

  /* S-Function Block: <S196>/autosar_testpoint1 */
  AFA_tAirUsInVlvEstimFil_IRV_MP = localAFAT_F02_inputs_filters_o1;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S197>/autosar_testpoint1' */

  /* S-Function Block: <S197>/autosar_testpoint1 */
  AFA_agCkClsExVlvEstimRef1Fil = localAFAT_F02_inputs_filters__j;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S198>/autosar_testpoint1' */

  /* S-Function Block: <S198>/autosar_testpoint1 */
  AFA_agCkOpInVlvEstimRef1Fil = localAFAT_F02_inputs_filters_b4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S199>/autosar_testpoint1' */

  /* S-Function Block: <S199>/autosar_testpoint1 */
  AFA_rTotLdExCorFil_IRV_MP = localAFAT_F02_inputs_filters_hn;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S200>/autosar_testpoint1' */

  /* S-Function Block: <S200>/autosar_testpoint1 */
  AFA_agCkClsInVlvEstimRef1Fil = localAFAT_F02_inputs_filters_l5;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S201>/autosar_testpoint1' */

  /* S-Function Block: <S201>/autosar_testpoint1 */
  AFA_arEffAdpThrFil_IRV_MP = localAFAT_F02_inputs_filters_f3;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S202>/autosar_testpoint1' */

  /* S-Function Block: <S202>/autosar_testpoint1 */
  AFA_pAirExtEstimFil_IRV_MP = localAFAT_F02_inputs_filters__c;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S203>/autosar_testpoint1' */

  /* S-Function Block: <S203>/autosar_testpoint1 */
  AFA_mFuReqFil_IRV_MP = localAFAT_F02_inputs_filters__n;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S204>/autosar_testpoint1' */

  /* S-Function Block: <S204>/autosar_testpoint1 */
  AFA_tCoMesFil_IRV_MP = localAFAT_F02_inputs_filters__m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S205>/autosar_testpoint1' */

  /* S-Function Block: <S205>/autosar_testpoint1 */
  AFA_pDsThrPred_facVlvOvlpFil = localAFAT_F02_inputs_filters__k;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S206>/autosar_testpoint1' */

  /* S-Function Block: <S206>/autosar_testpoint1 */
  AFA_pDsThrEstimFil_IRV_MP = localAFAT_F02_inputs_filters_bb;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S207>/autosar_testpoint1' */

  /* S-Function Block: <S207>/autosar_testpoint1 */
  AFA_arEffAdpEGRVlvFil_IRV_MP = localAFAT_F02_inputs_filters_o4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S208>/autosar_testpoint1' */

  /* S-Function Block: <S208>/autosar_testpoint1 */
  AFA_arEffEGRVlvFil_IRV_MP = localAFAT_F02_inputs_filters_o5;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S209>/autosar_testpoint1' */

  /* S-Function Block: <S209>/autosar_testpoint1 */
  AFA_rInMassFlowFil_IRV_MP = localAFAT_F02_inputs_filters_o6;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S210>/autosar_testpoint1' */

  /* S-Function Block: <S210>/autosar_testpoint1 */
  AFA_nEngCorFil_IRV_MP = localAFAT_F02_inputs_filters__h;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S211>/autosar_testpoint1' */

  /* S-Function Block: <S211>/autosar_testpoint1 */
  AFA_facRhoFuFil_IRV_MP = localAFAT_F02_inputs_filters__p;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S212>/autosar_testpoint1' */

  /* S-Function Block: <S212>/autosar_testpoint1 */
  AFA_rOpSIFil_IRV_MP = localAFAT_F02_inputs_filters_o9;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S213>/autosar_testpoint1' */

  /* S-Function Block: <S213>/autosar_testpoint1 */
  AFA_pDsThrCorFil_IRV_MP = localAFAT_F02_inputs_filters__b;

  /* Switch: '<S215>/Switch' incorporates:
   *  Constant: '<S215>/Byp_Fonction_SC'
   *  Constant: '<S215>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hj = AFA_pDsThrPredFil_B;
  } else {
    localSwitch_hj = localAFAT_F02_inputs_filters_hw;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_pDsThrPredFilInport2' */
  Rte_Write_P_AFA_pDsThrPredFil_AFA_pDsThrPredFil(localSwitch_hj);

  /* Switch: '<S217>/Switch' incorporates:
   *  Constant: '<S217>/Byp_Fonction_SC'
   *  Constant: '<S217>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hj = AFA_pUsThrCorFil_B;
  } else {
    localSwitch_hj = localAFAT_F02_inputs_filter_hne;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_pUsThrCorFilInport2' */
  Rte_Write_P_AFA_pUsThrCorFil_AFA_pUsThrCorFil(localSwitch_hj);

  /* Switch: '<S216>/Switch' incorporates:
   *  Constant: '<S216>/Byp_Fonction_SC'
   *  Constant: '<S216>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hj = AFA_rAirLdCorFil_B;
  } else {
    localSwitch_hj = localAFAT_F02_inputs_filters_o8;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_rAirLdCorFilInport2' */
  Rte_Write_P_AFA_rAirLdCorFil_AFA_rAirLdCorFil(localSwitch_hj);

  /* Switch: '<S214>/Switch' incorporates:
   *  Constant: '<S214>/Byp_Fonction_SC'
   *  Constant: '<S214>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hj = AFA_rAirPresFil_B;
  } else {
    localSwitch_hj = localAFAT_F02_inputs_filters__l;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtAFA_rAirPresFilInport2' */
  Rte_Write_P_AFA_rAirPresFil_AFA_rAirPresFil(localSwitch_hj);
}

/* Start for exported function: RE_AFAT_005_TEV */
void RE_AFAT_005_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_156.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_157.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_161.01 ;
   *  4. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  5. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  6. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_148.01 ;
   *  7. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_205.01 ;
   *  8. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_220.01 ;
   *  9. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  10. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_232.01 ;
   *  11. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  12. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_244.01 ;
   *  13. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_245.01 ;
   *  14. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  15. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_311.01 ;
   */

  /* Start for Embedded MATLAB: '<S12>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S12>/AFA_Func_ClcCtl_ELSE'
   *  Start for SubSystem: '<S12>/F01_Gestion_algorythme_adaptation'
   *
   * Block requirements for '<S12>/F01_Gestion_algorythme_adaptation':
   *  1. SubSystem "F01_Gestion_algorythme_adaptation" !Trace_To : VEMS_R_11_04467_016.01 ;
   */

  /* Start for ifaction SubSystem: '<S249>/F01_algo_adapt_control_process' *
   * Block requirements for '<S249>/F01_algo_adapt_control_process':
   *  1. SubSystem "F01_algo_adapt_control_process" !Trace_To : VEMS_R_11_04467_017.01 ;
   */

  /* Start for Stateflow: '<S276>/F01_algo_adapt_control_process_chart1' incorporates:
   *  Start for SubSystem: '<S12>/F01_AFAClcObs_(025_DRE)'
   *  Start for SubSystem: '<S12>/F01_Osbservation_Number_(010_DRE)'
   *  Start for SubSystem: '<S12>/F01_calc_measurement_vector_(030_DRE)'
   *  Start for SubSystem: '<S12>/F01_reinit_after_app_adaption_(004_DRE)'
   *  Start for SubSystem: '<S12>/F02_Activation_EOM_Mode_(011_DRE)'
   *  Start for SubSystem: '<S12>/F02_Test_Algo_Reset_Rqst_(007_DRE)'
   *  Start for SubSystem: '<S12>/F02_calc_model_noise_mat_(031_DRE)'
   *  Start for SubSystem: '<S12>/F03_calcul_adaptatifs_(028_DRE)'
   *  Start for SubSystem: '<S12>/F03_check_environment_adaption_(008_DRE)'
   *  Start for SubSystem: '<S12>/F03_reset_cumulated_model_noise_v(032_DRE)'
   *  Start for SubSystem: '<S12>/F04_calc_innovation_vect_(033_DRE)'
   *  Start for SubSystem: '<S12>/F04_command_adaptation_parameters_(009_DRE)'
   *  Start for SubSystem: '<S12>/F04_detect_adaptation_stop_(029_DRE)'
   *  Start for SubSystem: '<S12>/F05_calc_pred_innov_covar_mat_(034_DRE)'
   *  Start for SubSystem: '<S12>/F06_add_adaption_noise_(020_DRE)'
   *  Start for SubSystem: '<S12>/F06_calc_gain_de_kalman_(035_DRE)'
   *  Start for SubSystem: '<S12>/F07_calc_error_param_vect_(036_DRE)'
   *  Start for SubSystem: '<S12>/F08_calc_est_error_covar_mat_(037_DRE)'
   *  Start for SubSystem: '<S12>/F09_test_innovation_coherence_(038_DRE)'
   *
   * Block requirements for '<S12>/F01_AFAClcObs_(025_DRE)':
   *  1. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_060.02 ;
   *  2. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_178.01 ;
   *  3. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_150.01 ;
   *  4. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_151.01 ;
   *  5. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_281.01 ;
   *  6. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_282.01 ;
   *  7. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_283.01 ;
   *  8. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_284.01 ;
   *  9. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_285.01 ;
   *  10. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_286.01 ;
   *  11. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_287.01 ;
   *  12. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_288.01 ;
   *  13. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_289.01 ;
   *  14. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_291.01 ;
   *  15. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_292.01 ;
   *  16. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_294.01 ;
   *  17. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_295.01 ;
   *  18. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_296.01 ;
   *  19. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_297.01 ;
   *  20. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_298.01 ;
   *  21. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_299.01 ;
   *  22. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_300.01 ;
   *  23. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_301.01 ;
   *  24. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_302.01 ;
   *  25. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_304.01 ;
   *  26. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_330.01 ;
   *
   * Block requirements for '<S12>/F01_Osbservation_Number_(010_DRE)':
   *  1. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_032.01 ;
   *  2. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  3. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_169.01 ;
   *  4. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  5. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_174.01 ;
   *  6. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_208.01 ;
   *  7. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  8. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  9. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_303.01 ;
   *  10. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_315.01 ;
   *
   * Block requirements for '<S12>/F01_calc_measurement_vector_(030_DRE)':
   *  1. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_118.01 ;
   *  2. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
   *  3. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_179.01 ;
   *  4. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_293.01 ;
   *  5. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_335.01 ;
   *
   * Block requirements for '<S12>/F01_reinit_after_app_adaption_(004_DRE)':
   *  1. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_012.01 ;
   *  2. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_149.01 ;
   *  3. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
   *  4. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_147.01 ;
   *  5. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_223.01 ;
   *  6. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_206.01 ;
   *  7. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_222.01 ;
   *  8. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  9. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_246.01 ;
   *  10. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  11. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_303.01 ;
   *  12. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_309.01 ;
   *
   * Block requirements for '<S12>/F02_Activation_EOM_Mode_(011_DRE)':
   *  1. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_033.01 ;
   *  2. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_159.01 ;
   *  3. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_160.01 ;
   *  4. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
   *  5. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_237.01 ;
   *  6. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_250.01 ;
   *  7. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_251.01 ;
   *  8. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_280.01 ;
   *  9. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_316.01 ;
   *
   * Block requirements for '<S12>/F02_Test_Algo_Reset_Rqst_(007_DRE)':
   *  1. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_018.01 ;
   *  2. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_155.01 ;
   *  3. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_279.01 ;
   *  4. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_312.01 ;
   *
   * Block requirements for '<S12>/F02_calc_model_noise_mat_(031_DRE)':
   *  1. SubSystem "F02_calc_model_noise_mat_(031_DRE)" !Trace_To : VEMS_R_11_04467_119.02 ;
   *  2. SubSystem "F02_calc_model_noise_mat_(031_DRE)" !Trace_To : VEMS_R_11_04467_336.01 ;
   *
   * Block requirements for '<S12>/F03_calcul_adaptatifs_(028_DRE)':
   *  1. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_114.01 ;
   *  2. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_132.01 ;
   *  3. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_133.01 ;
   *  4. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_134.01 ;
   *  5. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_140.01 ;
   *  6. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_141.01 ;
   *  7. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_142.01 ;
   *  8. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_143.01 ;
   *  9. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_144.01 ;
   *  10. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_152.01 ;
   *  11. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_154.01 ;
   *  12. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_201.01 ;
   *  13. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_202.01 ;
   *  14. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_203.01 ;
   *  15. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_204.01 ;
   *  16. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_215.01 ;
   *  17. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_216.01 ;
   *  18. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_217.01 ;
   *  19. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_218.01 ;
   *  20. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_219.01 ;
   *  21. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_231.01 ;
   *  22. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_234.01 ;
   *  23. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_252.01 ;
   *  24. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_253.01 ;
   *  25. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_254.01 ;
   *  26. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_255.01 ;
   *  27. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_256.01 ;
   *  28. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_257.01 ;
   *  29. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_258.01 ;
   *  30. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_259.01 ;
   *  31. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_260.01 ;
   *  32. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_333.01 ;
   *
   * Block requirements for '<S12>/F03_check_environment_adaption_(008_DRE)':
   *  1. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_020.01 ;
   *  2. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_207.01 ;
   *  3. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_209.01 ;
   *  4. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_135.01 ;
   *  5. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_137.01 ;
   *  6. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_138.01 ;
   *  7. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_139.01 ;
   *  8. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_313.01 ;
   *
   * Block requirements for '<S12>/F03_reset_cumulated_model_noise_v(032_DRE)':
   *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
   *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
   *
   * Block requirements for '<S12>/F04_calc_innovation_vect_(033_DRE)':
   *  1. SubSystem "F04_calc_innovation_vect_(033_DRE)" !Trace_To : VEMS_R_11_04467_121.01 ;
   *  2. SubSystem "F04_calc_innovation_vect_(033_DRE)" !Trace_To : VEMS_R_11_04467_338.01 ;
   *
   * Block requirements for '<S12>/F04_command_adaptation_parameters_(009_DRE)':
   *  1. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_026.01 ;
   *  2. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  3. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  4. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_181.02 ;
   *  5. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_195.01 ;
   *  6. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
   *  7. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_314.01 ;
   *
   * Block requirements for '<S12>/F04_detect_adaptation_stop_(029_DRE)':
   *  1. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_115.01 ;
   *  2. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_132.01 ;
   *  3. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_133.01 ;
   *  4. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_134.01 ;
   *  5. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_140.01 ;
   *  6. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_141.01 ;
   *  7. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_142.01 ;
   *  8. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_143.01 ;
   *  9. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_144.01 ;
   *  10. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_152.01 ;
   *  11. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_154.01 ;
   *  12. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_263.01 ;
   *  13. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_264.01 ;
   *  14. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_265.01 ;
   *  15. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_266.01 ;
   *  16. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_267.01 ;
   *  17. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_268.01 ;
   *  18. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_269.01 ;
   *  19. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_270.01 ;
   *  20. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_271.01 ;
   *  21. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_272.01 ;
   *  22. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_334.01 ;
   *
   * Block requirements for '<S12>/F05_calc_pred_innov_covar_mat_(034_DRE)':
   *  1. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_122.01 ;
   *  2. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
   *  3. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_339.01 ;
   *
   * Block requirements for '<S12>/F06_add_adaption_noise_(020_DRE)':
   *  1. SubSystem "F06_add_adaption_noise_(020_DRE)" !Trace_To : VEMS_R_11_04467_053.01 ;
   *  2. SubSystem "F06_add_adaption_noise_(020_DRE)" !Trace_To : VEMS_R_11_04467_325.01 ;
   *
   * Block requirements for '<S12>/F06_calc_gain_de_kalman_(035_DRE)':
   *  1. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_125.01 ;
   *  2. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
   *  3. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_340.01 ;
   *
   * Block requirements for '<S12>/F07_calc_error_param_vect_(036_DRE)':
   *  1. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_126.01 ;
   *  2. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_248.01 ;
   *  3. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_341.01 ;
   *
   * Block requirements for '<S12>/F08_calc_est_error_covar_mat_(037_DRE)':
   *  1. SubSystem "F08_calc_est_error_covar_mat_(037_DRE)" !Trace_To : VEMS_R_11_04467_127.01 ;
   *  2. SubSystem "F08_calc_est_error_covar_mat_(037_DRE)" !Trace_To : VEMS_R_11_04467_342.01 ;
   *
   * Block requirements for '<S12>/F09_test_innovation_coherence_(038_DRE)':
   *  1. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_128.01 ;
   *  2. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_213.01 ;
   *  3. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_214.01 ;
   *  4. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_242.01 ;
   *  5. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
   *  6. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
   *  7. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_305.01 ;
   *  8. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_343.01 ;
   */

  /* Start for Embedded MATLAB: '<S254>/Task_sceduler' incorporates:
   *  Start for SubSystem: '<S254>/F01_algo_reset_request1'
   *  Start for SubSystem: '<S254>/F01_algo_reset_request2'
   *
   * Block requirements for '<S254>/F01_algo_reset_request1':
   *  1. SubSystem "F01_algo_reset_request1" !Trace_To : VEMS_R_11_04467_019.01 ;
   *
   * Block requirements for '<S254>/F01_algo_reset_request2':
   *  1. SubSystem "F01_algo_reset_request2" !Trace_To : VEMS_R_11_04467_019.01 ;
   */

  /* Start for ifaction SubSystem: '<S294>/F01_algo_reset_request' *
   * Block requirements for '<S294>/F01_algo_reset_request':
   *  1. SubSystem "F01_algo_reset_request" !Trace_To : VEMS_R_11_04467_019.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S297>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S274>/F02_reinit_algo_adaptation_(005_DRE)'
   */

  /* Start for S-Function (fcncallgen): '<S390>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S391>/F02_common_init_algo3_(003_DRE)'
   *
   * Block requirements for '<S391>/F02_common_init_algo3_(003_DRE)':
   *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
   *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
   *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S404>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S391>/F00_init_scruter_environ_adaptation(013_DRE)'
   *  Start for SubSystem: '<S391>/F03_reset_cumulated_model_noise_v(032_DRE)'
   *
   * Block requirements for '<S391>/F00_init_scruter_environ_adaptation(013_DRE)':
   *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
   *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
   *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
   *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
   *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
   *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
   *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
   *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
   *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
   *
   * Block requirements for '<S391>/F03_reset_cumulated_model_noise_v(032_DRE)':
   *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
   *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
   *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
   *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
   */

  /* end of Start for SubSystem: '<S294>/F01_algo_reset_request' */

  /* Start for ModelReference: '<S266>/AFAT_F05_calc_pred_innov_covar_mat' */
  mr_AFA_F05_calc_pred_inno_Start();

  /* Start for enable SubSystem: '<S259>/F01_Add_patmo_reference_noise' *
   * Block requirements for '<S259>/F01_Add_patmo_reference_noise':
   *  1. SubSystem "F01_Add_patmo_reference_noise" !Trace_To : VEMS_R_11_04467_021.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S301>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F02_add_patmo_reference_noise_(016_DRE)'
   *
   * Block requirements for '<S12>/F02_add_patmo_reference_noise_(016_DRE)':
   *  1. SubSystem "F02_add_patmo_reference_noise_(016_DRE)" !Trace_To : VEMS_R_11_04467_049.01 ;
   *  2. SubSystem "F02_add_patmo_reference_noise_(016_DRE)" !Trace_To : VEMS_R_11_04467_321.01 ;
   */

  /* end of Start for SubSystem: '<S259>/F01_Add_patmo_reference_noise' */

  /* Start for enable SubSystem: '<S259>/F02_Add_throttle_reference_noise' *
   * Block requirements for '<S259>/F02_Add_throttle_reference_noise':
   *  1. SubSystem "F02_Add_throttle_reference_noise" !Trace_To : VEMS_R_11_04467_022.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S302>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F03_add_throttle_reference_noise_(017_DRE)'
   *
   * Block requirements for '<S12>/F03_add_throttle_reference_noise_(017_DRE)':
   *  1. SubSystem "F03_add_throttle_reference_noise_(017_DRE)" !Trace_To : VEMS_R_11_04467_050.01 ;
   *  2. SubSystem "F03_add_throttle_reference_noise_(017_DRE)" !Trace_To : VEMS_R_11_04467_322.01 ;
   */

  /* end of Start for SubSystem: '<S259>/F02_Add_throttle_reference_noise' */

  /* Start for enable SubSystem: '<S259>/F03_Add_egr_reference_noise' *
   * Block requirements for '<S259>/F03_Add_egr_reference_noise':
   *  1. SubSystem "F03_Add_egr_reference_noise" !Trace_To : VEMS_R_11_04467_023.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S303>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F04_add_egr_reference_noise_(018_DRE)'
   *
   * Block requirements for '<S12>/F04_add_egr_reference_noise_(018_DRE)':
   *  1. SubSystem "F04_add_egr_reference_noise_(018_DRE)" !Trace_To : VEMS_R_11_04467_051.01 ;
   *  2. SubSystem "F04_add_egr_reference_noise_(018_DRE)" !Trace_To : VEMS_R_11_04467_323.01 ;
   */

  /* end of Start for SubSystem: '<S259>/F03_Add_egr_reference_noise' */

  /* Start for enable SubSystem: '<S259>/F04_Add_IVO_reference_noise' *
   * Block requirements for '<S259>/F04_Add_IVO_reference_noise':
   *  1. SubSystem "F04_Add_IVO_reference_noise" !Trace_To : VEMS_R_11_04467_024.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S304>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F07_add_IVO_reference_noise_(021_DRE)'
   *
   * Block requirements for '<S12>/F07_add_IVO_reference_noise_(021_DRE)':
   *  1. SubSystem "F07_add_IVO_reference_noise_(021_DRE)" !Trace_To : VEMS_R_11_04467_054.01 ;
   *  2. SubSystem "F07_add_IVO_reference_noise_(021_DRE)" !Trace_To : VEMS_R_11_04467_326.01 ;
   */

  /* end of Start for SubSystem: '<S259>/F04_Add_IVO_reference_noise' */

  /* Start for enable SubSystem: '<S259>/F05_Add_EVC_reference_noise' *
   * Block requirements for '<S259>/F05_Add_EVC_reference_noise':
   *  1. SubSystem "F05_Add_EVC_reference_noise" !Trace_To : VEMS_R_11_04467_025.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S305>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F08_add_EVC_reference_noise_(022_DRE)'
   *
   * Block requirements for '<S12>/F08_add_EVC_reference_noise_(022_DRE)':
   *  1. SubSystem "F08_add_EVC_reference_noise_(022_DRE)" !Trace_To : VEMS_R_11_04467_055.01 ;
   *  2. SubSystem "F08_add_EVC_reference_noise_(022_DRE)" !Trace_To : VEMS_R_11_04467_327.01 ;
   */

  /* end of Start for SubSystem: '<S259>/F05_Add_EVC_reference_noise' */

  /* Start for ModelReference: '<S248>/AFA_F01_AFAClcObs' */
  mr_AFA_F01_AFAClcObs_Start();

  /* Start for ifaction SubSystem: '<S273>/F03_Add_incoherence_model_noise' *
   * Block requirements for '<S273>/F03_Add_incoherence_model_noise':
   *  1. SubSystem "F03_Add_incoherence_model_noise" !Trace_To : VEMS_R_11_04467_131.01 ;
   */

  /* Start for S-Function (fcncallgen): '<S386>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S12>/F05_add_incoherence_model_noise_(019_DRE)'
   *
   * Block requirements for '<S12>/F05_add_incoherence_model_noise_(019_DRE)':
   *  1. SubSystem "F05_add_incoherence_model_noise_(019_DRE)" !Trace_To : VEMS_R_11_04467_052.01 ;
   *  2. SubSystem "F05_add_incoherence_model_noise_(019_DRE)" !Trace_To : VEMS_R_11_04467_324.01 ;
   */

  /* end of Start for SubSystem: '<S273>/F03_Add_incoherence_model_noise' */

  /* end of Start for SubSystem: '<S249>/F01_algo_adapt_control_process' */
}

/* Output and update for exported function: RE_AFAT_005_TEV */
void RE_AFAT_005_TEV(void)
{
  /* local block i/o variables */
  UInt32 localautosar_irv_read22;
  UInt32 localautosar_irv_read26;
  UInt32 localautosar_irv_read38;
  SInt32 localAFA_F01_AFAClcObs[16];
  SInt32 localDataStoreRead7[16];
  SInt32 localDataStoreRead8[16];
  SInt32 localAFAT_F04_calc_innovation_v[16];
  SInt32 localDataStoreRead2[16];
  SInt32 localDataStoreRead4[16];
  SInt32 localDataStoreRead1[16];
  UInt32 localDataStoreRead2_m[4];
  UInt32 localDataStoreRead3[4];
  SInt32 localDataTypeConversion;
  SInt16 localautosar_irv_read23;
  SInt16 localautosar_irv_read24;
  SInt16 localautosar_irv_read39;
  SInt16 localautosar_irv_read63;
  UInt16 localautosar_irv_read18;
  UInt16 localautosar_irv_read19;
  UInt16 localautosar_irv_read20;
  UInt16 localautosar_irv_read21;
  UInt16 localautosar_irv_read25;
  UInt16 localautosar_irv_read28;
  UInt16 localautosar_irv_read29;
  UInt16 localautosar_irv_read30;
  UInt16 localautosar_irv_read31;
  UInt16 localautosar_irv_read32;
  UInt16 localautosar_irv_read36;
  UInt16 localautosar_irv_read37;
  UInt16 localautosar_irv_read40;
  UInt16 localautosar_irv_read41;
  UInt16 localautosar_irv_read1;
  UInt16 localautosar_irv_read2;
  UInt16 localAFAT_F05_add_incoherence_m[8];
  UInt16 localDataStoreRead_pl[64];
  UInt16 localAFAT_F03_reset_cumulated_p[8];
  UInt16 localDataStoreRead1_l[4];
  UInt16 localAFAT_F08_add_EVC_reference[8];
  UInt16 localAFAT_F07_add_IVO_reference[8];
  UInt16 localAFAT_F04_add_egr_reference[8];
  UInt16 localAFAT_F03_add_throttle_refe[8];
  UInt16 localAFAT_F02_add_patmo_referen[8];
  UInt16 localDataStoreRead6[64];
  UInt16 localAFAT_F05_calc_pred_innov_c[4];
  UInt16 localDataStoreRead1_i[8];
  UInt16 localDataStoreRead1_j[4];
  UInt16 localAFAT_F06_add_adaption_nois[8];
  UInt16 localDataStoreRead_nj[64];
  UInt16 localAFAT_F03_reset_cumulated_l[8];
  UInt16 localDataStoreRead_b[64];
  UInt16 localSignalConversion6[8];
  UInt16 localSignalConversion4_k[8];
  UInt16 localSignalConversion3[8];
  UInt16 localSignalConversion2[8];
  UInt16 localSignalConversion1_p[8];
  UInt16 localSignalConversion_k[8];
  UInt16 localSignalConversion5[8];
  SInt16 localAFAT_F05_calc_pred_innov_l[16];
  SInt16 localDataStoreRead2_my[16];
  SInt16 localAFAT_F06_calc_gain_de_kalm[16];
  SInt16 localDataStoreRead4_e[16];
  SInt16 localDataStoreRead1_bx[16];
  SInt16 localAFAT_F01_calc_measurement_[2];
  SInt16 localAFAT_F04_calc_innovation_c[2];
  SInt16 localDataStoreRead3_n[2];
  SInt16 localDataStoreRead2_n[2];
  SInt16 localAFAT_F07_calc_error_param_[8];
  SInt16 localDataStoreRead2_d[8];
  SInt16 localDataStoreRead5[8];
  SInt16 localSignalConversion2_i[8];
  UInt16 localSignal1;
  UInt16 localAFAT_F00_init_scruter_en_e;
  UInt16 localAFAT_F00_init_scruter_en_i;
  UInt16 localAFAT_F00_init_scruter_e_dq;
  UInt16 localAFAT_F00_init_scruter_en_g;
  UInt16 localAFAT_F00_init_scruter_e_g0;
  UInt8 localautosar_irv_read134;
  UInt8 localAFA_F02_Activation_EOM_Mod;
  UInt8 localAFAT_F01_Osbservation_Numb[9];
  UInt8 localAFAT_F01_Osbservation_Nu_b;
  UInt8 localAFAT_F01_Osbservation_Nu_f;
  UInt8 localSwitch2;
  UInt8 localAFAT_F01_reinit_after_app_;
  UInt8 localAFAT_F01_reinit_after_ap_h[9];
  UInt8 localautosar_irv_read3;
  UInt8 localDataStoreRead2_p[9];
  UInt8 localautosar_irv_read81;
  UInt8 localSignalConversion_g0;
  UInt8 localSignal3;
  UInt8 localSignal4;
  Boolean localAFAT_F04_command_adaptatio[16];
  Boolean localAFAT_F05_calc_pred_innov_a;
  Boolean localAFAT_F04_detect_adaptation;
  Boolean localAFAT_F04_detect_adaptati_c;
  Boolean localAFAT_F04_detect_adaptati_o;
  Boolean localAFAT_F04_detect_adaptati_p;
  Boolean localAFAT_F04_detect_adaptati_g;
  Boolean localAFAT_F04_detect_adaptat_op;
  Boolean localAFAT_F04_detect_adaptati_d;
  Boolean localAFAT_F04_detect_adaptat_ps;
  Boolean localAFAT_F04_detect_adaptati_n;
  Boolean localAFAT_F04_detect_adaptat_cs;
  Boolean localAFAT_F04_detect_adaptat_o5;
  Boolean localAFAT_F04_detect_adaptati_m;
  Boolean localAFAT_F04_detect_adaptati_a;
  Boolean localAFAT_F04_detect_adaptati_k;
  Boolean localAFAT_F04_detect_adaptat_kt;
  Boolean localAFAT_F04_detect_adaptati_h;
  Boolean localAFAT_F04_detect_adaptat_oy;
  Boolean localAFAT_F04_detect_adaptat_nu;
  Boolean localAFAT_F04_detect_adaptat_kv;
  Boolean localAFAT_F04_detect_adapta_oyb;
  Boolean localDataStoreRead4_f[16];
  Boolean localautosar_irv_read193;
  Boolean localSignalConversion_ks;
  UInt8 localAFAT_F05_calc_pred_inno_at[4];
  UInt8 localDataStoreRead3_c[4];
  Boolean localSwitch_hq;
  Boolean localSwitch_le;
  Boolean localSwitch_ga;
  Boolean localSwitch_gax;
  Boolean localSwitch_gt;
  Boolean localSwitch_lm;
  UInt8 localSignal2;
  Boolean localLogicalOperator1;
  SInt8 localSwitch_hu;
  UInt16 localSwitch_bm;
  UInt32 localSwitch_hm;
  SInt16 localSignalConversion1_i[8];
  Boolean localAFA_bAcvSpcInjMod_merge_m;
  Boolean localAFA_bEngStopAuth_merge_i;
  Boolean localAFA_bInnovTestCohDone_merg;
  UInt8 localAFA_noAdpClcRst_merge_o;
  UInt16 localAFA_noAdpEfc_merge_e;
  SInt8 localAFA_agCkClsExVlvOfs_merge_;
  SInt8 localAFA_agCkOpInVlvOfs_merge_k;
  SInt16 localAFA_arEffThrOfs_merge_h;
  SInt8 localAFA_facArEffThrOfs1_merge_;
  SInt8 localAFA_facArEffThrOfs2_merge_;
  SInt8 localAFA_facArEffThrOfs3_merge_;
  SInt16 localAFA_facIvsInjGain_merge_k;
  SInt32 localAFA_facSlopInjGain_merge_m;
  UInt16 localAFA_prm_covErrEstim_merge_[8];
  SInt8 localAFA_rCor_arEffEGRVlv_merge;
  SInt8 localAFA_tiOffInj_merge_i;
  SInt32 locali;
  SInt16 locallocalDataStoreRead2_i_idx;
  SInt16 locallocalDataStoreRead2_i_id_0;
  UInt16 locallocalDataStoreRead1_b_idx;
  UInt16 locallocalDataStoreRead1_b_id_0;
  UInt16 locallocalDataStoreRead1_b_id_1;
  UInt16 locallocalDataStoreRead1_b_id_2;
  SInt16 locallocalDataStoreRead2_i;
  SInt16 localtmp;

  /* S-Function (fcncallgen): '<S6>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_156.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_157.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_161.01 ;
   *  4. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_168.01 ;
   *  5. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_172.01 ;
   *  6. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_148.01 ;
   *  7. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_205.01 ;
   *  8. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_220.01 ;
   *  9. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_224.01 ;
   *  10. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_232.01 ;
   *  11. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  12. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_244.01 ;
   *  13. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_245.01 ;
   *  14. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_249.01 ;
   *  15. SubSystem "RE_AFAT_SdlSlow_AFAClcCtl_(006_TEV)" !Trace_To : VEMS_R_11_04467_311.01 ;
   */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpEfc_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpEfc_INPUT'
   */
  Rte_Read_R_AFA_noAdpEfc_AFA_noAdpEfc(&AFAT_B.TmpSignalConversionAtAFA_noAdpE);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpEfcAst_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpEfcAst_INPUT'
   */
  Rte_Read_R_AFA_noAdpEfcAst_AFA_noAdpEfcAst
    (&AFAT_B.TmpSignalConversionAtAFA_noAd_e);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_prm_covErrEstim_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_prm_covErrEstim_INPUT'
   */
  Rte_Read_R_AFA_prm_covErrEstim_AFA_prm_covErrEstim
    (&AFAT_B.TmpSignalConversionAtAFA_prm_co);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bInhAFAOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bInhAFA'
   */
  Rte_Read_R_AFAMgt_bInhAFA_AFAMgt_bInhAFA
    (&AFAT_B.TmpSignalConversionAtAFAMgt_bIn);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bAdpEfcReqOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bAdpEfcReq'
   */
  Rte_Read_R_AFAMgt_bAdpEfcReq_AFAMgt_bAdpEfcReq
    (&AFAT_B.TmpSignalConversionAtAFAMgt_bAd);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bAdpObsReqOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bAdpObsReq'
   */
  Rte_Read_R_AFAMgt_bAdpObsReq_AFAMgt_bAdpObsReq
    (&AFAT_B.TmpSignalConversionAtAFAMgt_b_l);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtExt_nEngOutport2' incorporates:
   *  Inport: '<Root>/Ext_nEng'
   */
  Rte_Read_R_Ext_nEng_Ext_nEng(&AFAT_B.TmpSignalConversionAtExt_nEngOu);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEngM_rTotLdExCorOutport2' incorporates:
   *  Inport: '<Root>/EngM_rTotLdExCor'
   */
  Rte_Read_R_EngM_rTotLdExCor_EngM_rTotLdExCor
    (&AFAT_B.TmpSignalConversionAtEngM_rTotL);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noObsDone_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noObsDone_INPUT'
   */
  Rte_Read_R_AFA_noObsDone_AFA_noObsDone(&AFAT_B.TmpSignalConversionAtAFA_noObsD);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtThrLrn_rOpClsThrBolOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpClsThrBol'
   */
  Rte_Read_R_ThrLrn_rOpClsThrBol_ThrLrn_rOpClsThrBol
    (&AFAT_B.TmpSignalConversionAtThrLrn_r_k);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtUsThrM_pAirExtEstimOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExtEstim'
   */
  Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim
    (&AFAT_B.TmpSignalConversionAtUsThrM_p_g);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEGRVlv_rOpClsEGRVlvBolOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_rOpClsEGRVlvBol'
   */
  Rte_Read_R_EGRVlv_rOpClsEGRVlvBol_EGRVlv_rOpClsEGRVlvBol
    (&AFAT_B.TmpSignalConversionAtEGRVlv_r_p);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtVlvAct_prm_agCkOpInVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkOpInVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_p_c);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtVlvAct_prm_agCkClsExVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkClsExVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_p_m);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpClcRst_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_noAdpClcRst_INPUT'
   */
  Rte_Read_R_AFA_noAdpClcRst_AFA_noAdpClcRst
    (&AFAT_B.TmpSignalConversionAtAFA_noAdpC);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facIvsInjGain_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facIvsInjGain_INPUT'
   */
  Rte_Read_R_AFA_facIvsInjGain_AFA_facIvsInjGain
    (&AFAT_B.TmpSignalConversionAtAFA_facIvs);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_tiOffInj_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiOffInj_INPUT'
   */
  Rte_Read_R_AFA_tiOffInj_AFA_tiOffInj(&AFAT_B.TmpSignalConversionAtAFA_tiOffI);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facSlopInjGain_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facSlopInjGain_INPUT'
   */
  Rte_Read_R_AFA_facSlopInjGain_AFA_facSlopInjGain
    (&AFAT_B.TmpSignalConversionAtAFA_facSlo);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_arEffThrOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffThrOfs_INPUT'
   */
  Rte_Read_R_AFA_arEffThrOfs_AFA_arEffThrOfs
    (&AFAT_B.TmpSignalConversionAtAFA_arEffT);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs1_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs1_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1
    (&AFAT_B.TmpSignalConversionAtAFA_facArE);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs2_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs2_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2
    (&AFAT_B.TmpSignalConversionAtAFA_facA_d);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs3_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_facArEffThrOfs3_INPUT'
   */
  Rte_Read_R_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3
    (&AFAT_B.TmpSignalConversionAtAFA_facA_l);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlv_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_rCor_arEffEGRVlv_INPUT'
   */
  Rte_Read_R_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv
    (&AFAT_B.TmpSignalConversionAtAFA_rCor_a);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_agCkOpInVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkOpInVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_agCkOp);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_agCkClsExVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_agCkClsExVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_agCkCl);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtThrLrn_rOpSIOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpSI'
   */
  Rte_Read_R_ThrLrn_rOpSI_ThrLrn_rOpSI(&AFAT_B.TmpSignalConversionAtThrLrn_r_c);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInjSys_noTDCDlyLsclFilModOutport2' incorporates:
   *  Inport: '<Root>/InjSys_noTDCDlyLsclFilMod'
   */
  Rte_Read_R_InjSys_noTDCDlyLsclFilMod_InjSys_noTDCDlyLsclFilMod
    (&AFAT_B.TmpSignalConversionAtInjSys_noT);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitPresAirExt_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitPresAirExt_INPUT'
   */
  Rte_Read_R_AFA_bFitPresAirExt_AFA_bFitPresAirExt
    (&AFAT_B.TmpSignalConversionAtAFA_bFitPr);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitZeroPosnThr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitZeroPosnThr_INPUT'
   */
  Rte_Read_R_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr
    (&AFAT_B.TmpSignalConversionAtAFA_bFitZe);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bClsEGRRef_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bClsEGRRef_INPUT'
   */
  Rte_Read_R_AFA_bClsEGRRef_AFA_bClsEGRRef
    (&AFAT_B.TmpSignalConversionAtAFA_bClsEG);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitOpInVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitOpInVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol
    (&AFAT_B.TmpSignalConversionAtAFA_bFitOp);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitClsExVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitClsExVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol
    (&AFAT_B.TmpSignalConversionAtAFA_bFitCl);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bAdpClcRstReqOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bAdpClcRstReq'
   */
  Rte_Read_R_AFAMgt_bAdpClcRstReq_AFAMgt_bAdpClcRstReq
    (&AFAT_B.TmpSignalConversionAtAFAMgt_b_e);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bIdcInjrMdlCndOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bIdcInjrMdlCnd'
   */
  Rte_Read_R_AFAMgt_bIdcInjrMdlCnd_AFAMgt_bIdcInjrMdlCnd
    (&AFAT_B.TmpSignalConversionAtAFAMgt_bId);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFAMgt_bIdcTmpObsCndOutport2' incorporates:
   *  Inport: '<Root>/AFAMgt_bIdcTmpObsCnd'
   */
  Rte_Read_R_AFAMgt_bIdcTmpObsCnd_AFAMgt_bIdcTmpObsCnd
    (&AFAT_B.TmpSignalConversionAtAFAMgt_b_p);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInjSys_lamFbFilOutport2' incorporates:
   *  Inport: '<Root>/InjSys_lamFbFil'
   */
  Rte_Read_R_InjSys_lamFbFil_InjSys_lamFbFil
    (&AFAT_B.TmpSignalConversionAtInjSys_lam);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtIdlSys_bAcvIdlCtlOutport2' incorporates:
   *  Inport: '<Root>/IdlSys_bAcvIdlCtl'
   */
  Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl
    (&AFAT_B.TmpSignalConversionAtIdlSys_bAc);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtEOM_bSpcInjModOutport2' incorporates:
   *  Inport: '<Root>/EOM_bSpcInjMod'
   */
  Rte_Read_R_EOM_bSpcInjMod_EOM_bSpcInjMod
    (&AFAT_B.TmpSignalConversionAtEOM_bSpcIn);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rAirPresFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_rAirPresFil_INPUT'
   */
  Rte_Read_R_AFA_rAirPresFil_AFA_rAirPresFil
    (&AFAT_B.TmpSignalConversionAtAFA_rAirPr);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rAirLdCorFil_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_rAirLdCorFil_INPUT'
   */
  Rte_Read_R_AFA_rAirLdCorFil_AFA_rAirLdCorFil
    (&AFAT_B.TmpSignalConversionAtAFA_rAirLd);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtInjrSys_prm_tiInjOutport2' incorporates:
   *  Inport: '<Root>/InjrSys_prm_tiInj'
   */
  Rte_Read_R_InjrSys_prm_tiInj_InjrSys_prm_tiInj
    (&AFAT_B.TmpSignalConversionAtInjrSys_pr);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_arEffEGRVlvOfs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_arEffEGRVlvOfs_INPUT'
   */
  Rte_Read_R_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs
    (&AFAT_B.TmpSignalConversionAtAFA_arEffE);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bAcvSpcInjMod_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAcvSpcInjMod_INPUT'
   */
  Rte_Read_R_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod
    (&AFAT_B.TmpSignalConversionAtAFA_bAcvSp);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bAuthClsCanPurg_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bAuthClsCanPurg_INPUT'
   */
  Rte_Read_R_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg
    (&AFAT_B.TmpSignalConversionAtAFA_bAuthC);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bEngStopAuth_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bEngStopAuth_INPUT'
   */
  Rte_Read_R_AFA_bEngStopAuth_AFA_bEngStopAuth
    (&AFAT_B.TmpSignalConversionAtAFA_bEngSt);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bIdcCohLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bIdcCohLstObs_INPUT'
   */
  Rte_Read_R_AFA_bIdcCohLstObs_AFA_bIdcCohLstObs
    (&AFAT_B.TmpSignalConversionAtAFA_bIdcCo);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bInnovTestCohDone_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bInnovTestCohDone_INPUT'
   */
  Rte_Read_R_AFA_bInnovTestCohDone_AFA_bInnovTestCohDone
    (&AFAT_B.TmpSignalConversionAtAFA_bInnov);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_nEngLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_nEngLstObs_INPUT'
   */
  Rte_Read_R_AFA_nEngLstObs_AFA_nEngLstObs
    (&AFAT_B.TmpSignalConversionAtAFA_nEngLs);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rTotLdCorLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_rTotLdCorLstObs_INPUT'
   */
  Rte_Read_R_AFA_rTotLdCorLstObs_AFA_rTotLdCorLstObs
    (&AFAT_B.TmpSignalConversionAtAFA_rTotLd);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_tiDlyLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiDlyLstObs_INPUT'
   */
  Rte_Read_R_AFA_tiDlyLstObs_AFA_tiDlyLstObs
    (&AFAT_B.TmpSignalConversionAtAFA_tiDlyL);

  /* Embedded MATLAB: '<S12>/Task_sceduler' incorporates:
   *  SubSystem: '<S12>/AFA_Func_ClcCtl_ELSE'
   *  SubSystem: '<S12>/F01_Gestion_algorythme_adaptation'
   *
   * Block requirements for '<S12>/F01_Gestion_algorythme_adaptation':
   *  1. SubSystem "F01_Gestion_algorythme_adaptation" !Trace_To : VEMS_R_11_04467_016.01 ;
   */
  /* Embedded MATLAB Function 'AFAT/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)/Task_sceduler': '<S275>:1' */
  /* '<S275>:1:5' */

  /* Inport: '<S218>/AFA_agCkClsExVlvOfs_INPUT' */
  localAFA_agCkClsExVlvOfs_merge_ = AFAT_B.TmpSignalConversionAtAFA_agCkCl;

  /* Inport: '<S218>/AFA_agCkOpInVlvOfs_INPUT' */
  localAFA_agCkOpInVlvOfs_merge_k = AFAT_B.TmpSignalConversionAtAFA_agCkOp;

  /* Inport: '<S218>/AFA_arEffEGRVlvOfs_INPUT' */
  AFAT_B.AFA_arEffEGRVlvOfs_merge_j = AFAT_B.TmpSignalConversionAtAFA_arEffE;

  /* Inport: '<S218>/AFA_arEffThrOfs_INPUT' */
  localAFA_arEffThrOfs_merge_h = AFAT_B.TmpSignalConversionAtAFA_arEffT;

  /* Inport: '<S218>/AFA_bAcvSpcInjMod_INPUT' */
  localAFA_bAcvSpcInjMod_merge_m = AFAT_B.TmpSignalConversionAtAFA_bAcvSp;

  /* Inport: '<S218>/AFA_bAuthClsCanPurg_INPUT' */
  AFAT_B.AFA_bAuthClsCanPurg_merge_m = AFAT_B.TmpSignalConversionAtAFA_bAuthC;

  /* Inport: '<S218>/AFA_bClsEGRRef_INPUT' */
  AFAT_B.AFA_bClsEGRRef_merge_a = AFAT_B.TmpSignalConversionAtAFA_bClsEG;

  /* Inport: '<S218>/AFA_bEngStopAuth_INPUT' */
  localAFA_bEngStopAuth_merge_i = AFAT_B.TmpSignalConversionAtAFA_bEngSt;

  /* Inport: '<S218>/AFA_bFitClsExVlvBol_INPUT' */
  AFAT_B.AFA_bFitClsExVlvBol_merge_d = AFAT_B.TmpSignalConversionAtAFA_bFitCl;

  /* Inport: '<S218>/AFA_bFitOpInVlvBol_INPUT' */
  AFAT_B.AFA_bFitOpInVlvBol_merge_g = AFAT_B.TmpSignalConversionAtAFA_bFitOp;

  /* Inport: '<S218>/AFA_bFitPresAirExt_INPUT' */
  AFAT_B.AFA_bFitPresAirExt_merge_k = AFAT_B.TmpSignalConversionAtAFA_bFitPr;

  /* Inport: '<S218>/AFA_bFitZeroPosnThr_INPUT' */
  AFAT_B.AFA_bFitZeroPosnThr_merge_j = AFAT_B.TmpSignalConversionAtAFA_bFitZe;

  /* Inport: '<S218>/AFA_bIdcCohLstObs_INPUT' */
  localLogicalOperator1 = AFAT_B.TmpSignalConversionAtAFA_bIdcCo;

  /* Inport: '<S218>/AFA_bInnovTestCohDone_INPUT' */
  localAFA_bInnovTestCohDone_merg = AFAT_B.TmpSignalConversionAtAFA_bInnov;

  /* Inport: '<S218>/AFA_facArEffThrOfs1_INPUT' */
  localAFA_facArEffThrOfs1_merge_ = AFAT_B.TmpSignalConversionAtAFA_facArE;

  /* Inport: '<S218>/AFA_facArEffThrOfs2_INPUT' */
  localAFA_facArEffThrOfs2_merge_ = AFAT_B.TmpSignalConversionAtAFA_facA_d;

  /* Inport: '<S218>/AFA_facArEffThrOfs3_INPUT' */
  localAFA_facArEffThrOfs3_merge_ = AFAT_B.TmpSignalConversionAtAFA_facA_l;

  /* Inport: '<S218>/AFA_facIvsInjGain_INPUT' */
  localAFA_facIvsInjGain_merge_k = AFAT_B.TmpSignalConversionAtAFA_facIvs;

  /* Inport: '<S218>/AFA_facSlopInjGain_INPUT' */
  localAFA_facSlopInjGain_merge_m = AFAT_B.TmpSignalConversionAtAFA_facSlo;

  /* Inport: '<S218>/AFA_nEngLstObs_INPUT' */
  AFAT_B.AFA_nEngLstObs_merge_e = AFAT_B.TmpSignalConversionAtAFA_nEngLs;

  /* Inport: '<S218>/AFA_noAdpClcRst_INPUT' */
  localAFA_noAdpClcRst_merge_o = AFAT_B.TmpSignalConversionAtAFA_noAdpC;

  /* Inport: '<S218>/AFA_noAdpEfc_INPUT' */
  localAFA_noAdpEfc_merge_e = AFAT_B.TmpSignalConversionAtAFA_noAdpE;

  /* Inport: '<S218>/AFA_noAdpEfcAst_INPUT' */
  AFAT_B.AFA_noAdpEfcAst_merge_l = AFAT_B.TmpSignalConversionAtAFA_noAd_e;

  /* Inport: '<S218>/AFA_noObsDone_INPUT' */
  AFAT_B.AFA_noObsDone_merge_j = AFAT_B.TmpSignalConversionAtAFA_noObsD;

  /* Inport: '<S218>/AFA_prm_covErrEstim_INPUT' */
  for (locali = 0; locali < 8; locali++) {
    localAFA_prm_covErrEstim_merge_[locali] =
      AFAT_B.TmpSignalConversionAtAFA_prm_co[(locali)];
  }

  /* Inport: '<S218>/AFA_rCor_arEffEGRVlv_INPUT' */
  localAFA_rCor_arEffEGRVlv_merge = AFAT_B.TmpSignalConversionAtAFA_rCor_a;

  /* Inport: '<S218>/AFA_rTotLdCorLstObs_INPUT' */
  AFAT_B.AFA_rTotLdCorLstObs_merge_b = AFAT_B.TmpSignalConversionAtAFA_rTotLd;

  /* Inport: '<S218>/AFA_tiDlyLstObs_INPUT' */
  AFAT_B.AFA_tiDlyLstObs_merge_h = AFAT_B.TmpSignalConversionAtAFA_tiDlyL;

  /* Inport: '<S218>/AFA_tiOffInj_INPUT' */
  localAFA_tiOffInj_merge_i = AFAT_B.TmpSignalConversionAtAFA_tiOffI;

  /* '<S275>:1:7' */

  /* SignalConversion: '<S249>/Signal2' */
  localSignal2 = AFAT_B.TmpSignalConversionAtAFA_noObsD;

  /* SignalConversion: '<S277>/copy' */
  AFA_noObsDonePrev = AFAT_B.TmpSignalConversionAtAFA_noObsD;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S277>/autosar_testpoint1' */

  /* S-Function Block: <S277>/autosar_testpoint1 */

  /* If: '<S249>/If' incorporates:
   *  ActionPort: '<S276>/Action Port'
   *  SubSystem: '<S249>/F01_algo_adapt_control_process'
   *
   * Block requirements for '<S249>/F01_algo_adapt_control_process':
   *  1. SubSystem "F01_algo_adapt_control_process" !Trace_To : VEMS_R_11_04467_017.01 ;
   */
  if (!AFAT_B.TmpSignalConversionAtAFAMgt_bIn) {
    /* Stateflow: '<S276>/F01_algo_adapt_control_process_chart1' incorporates:
     *  Constant: '<S276>/AFA_stEfc_SC'
     *  Constant: '<S276>/AFA_stObs_SC'
     *  Constant: '<S276>/AFA_stWait_SC'
     *  SubSystem: '<S12>/F01_AFAClcObs_(025_DRE)'
     *  SubSystem: '<S12>/F01_Osbservation_Number_(010_DRE)'
     *  SubSystem: '<S12>/F01_calc_measurement_vector_(030_DRE)'
     *  SubSystem: '<S12>/F01_reinit_after_app_adaption_(004_DRE)'
     *  SubSystem: '<S12>/F02_Activation_EOM_Mode_(011_DRE)'
     *  SubSystem: '<S12>/F02_Test_Algo_Reset_Rqst_(007_DRE)'
     *  SubSystem: '<S12>/F02_calc_model_noise_mat_(031_DRE)'
     *  SubSystem: '<S12>/F03_calcul_adaptatifs_(028_DRE)'
     *  SubSystem: '<S12>/F03_check_environment_adaption_(008_DRE)'
     *  SubSystem: '<S12>/F03_reset_cumulated_model_noise_v(032_DRE)'
     *  SubSystem: '<S12>/F04_calc_innovation_vect_(033_DRE)'
     *  SubSystem: '<S12>/F04_command_adaptation_parameters_(009_DRE)'
     *  SubSystem: '<S12>/F04_detect_adaptation_stop_(029_DRE)'
     *  SubSystem: '<S12>/F05_calc_pred_innov_covar_mat_(034_DRE)'
     *  SubSystem: '<S12>/F06_add_adaption_noise_(020_DRE)'
     *  SubSystem: '<S12>/F06_calc_gain_de_kalman_(035_DRE)'
     *  SubSystem: '<S12>/F07_calc_error_param_vect_(036_DRE)'
     *  SubSystem: '<S12>/F08_calc_est_error_covar_mat_(037_DRE)'
     *  SubSystem: '<S12>/F09_test_innovation_coherence_(038_DRE)'
     *
     * Block requirements for '<S12>/F01_AFAClcObs_(025_DRE)':
     *  1. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_060.02 ;
     *  2. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_178.01 ;
     *  3. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_150.01 ;
     *  4. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_151.01 ;
     *  5. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_281.01 ;
     *  6. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_282.01 ;
     *  7. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_283.01 ;
     *  8. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_284.01 ;
     *  9. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_285.01 ;
     *  10. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_286.01 ;
     *  11. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_287.01 ;
     *  12. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_288.01 ;
     *  13. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_289.01 ;
     *  14. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_291.01 ;
     *  15. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_292.01 ;
     *  16. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_294.01 ;
     *  17. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_295.01 ;
     *  18. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_296.01 ;
     *  19. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_297.01 ;
     *  20. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_298.01 ;
     *  21. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_299.01 ;
     *  22. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_300.01 ;
     *  23. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_301.01 ;
     *  24. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_302.01 ;
     *  25. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_304.01 ;
     *  26. SubSystem "F01_AFAClcObs_(025_DRE)" !Trace_To : VEMS_R_11_04467_330.01 ;
     *
     * Block requirements for '<S12>/F01_Osbservation_Number_(010_DRE)':
     *  1. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_032.01 ;
     *  2. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_168.01 ;
     *  3. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_169.01 ;
     *  4. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_172.01 ;
     *  5. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_174.01 ;
     *  6. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_208.01 ;
     *  7. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_251.01 ;
     *  8. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_280.01 ;
     *  9. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_303.01 ;
     *  10. SubSystem "F01_Osbservation_Number_(010_DRE)" !Trace_To : VEMS_R_11_04467_315.01 ;
     *
     * Block requirements for '<S12>/F01_calc_measurement_vector_(030_DRE)':
     *  1. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_118.01 ;
     *  2. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
     *  3. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_179.01 ;
     *  4. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_293.01 ;
     *  5. SubSystem "F01_calc_measurement_vector_(030_DRE)" !Trace_To : VEMS_R_11_04467_335.01 ;
     *
     * Block requirements for '<S12>/F01_reinit_after_app_adaption_(004_DRE)':
     *  1. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_012.01 ;
     *  2. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_149.01 ;
     *  3. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
     *  4. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_147.01 ;
     *  5. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_223.01 ;
     *  6. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_206.01 ;
     *  7. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_222.01 ;
     *  8. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_224.01 ;
     *  9. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_246.01 ;
     *  10. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_249.01 ;
     *  11. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_303.01 ;
     *  12. SubSystem "F01_reinit_after_app_adaption_(004_DRE)" !Trace_To : VEMS_R_11_04467_309.01 ;
     *
     * Block requirements for '<S12>/F02_Activation_EOM_Mode_(011_DRE)':
     *  1. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_033.01 ;
     *  2. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_159.01 ;
     *  3. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_160.01 ;
     *  4. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
     *  5. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_237.01 ;
     *  6. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_250.01 ;
     *  7. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_251.01 ;
     *  8. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_280.01 ;
     *  9. SubSystem "F02_Activation_EOM_Mode_(011_DRE)" !Trace_To : VEMS_R_11_04467_316.01 ;
     *
     * Block requirements for '<S12>/F02_Test_Algo_Reset_Rqst_(007_DRE)':
     *  1. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_018.01 ;
     *  2. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_155.01 ;
     *  3. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_279.01 ;
     *  4. SubSystem "F02_Test_Algo_Reset_Rqst_(007_DRE)" !Trace_To : VEMS_R_11_04467_312.01 ;
     *
     * Block requirements for '<S12>/F02_calc_model_noise_mat_(031_DRE)':
     *  1. SubSystem "F02_calc_model_noise_mat_(031_DRE)" !Trace_To : VEMS_R_11_04467_119.02 ;
     *  2. SubSystem "F02_calc_model_noise_mat_(031_DRE)" !Trace_To : VEMS_R_11_04467_336.01 ;
     *
     * Block requirements for '<S12>/F03_calcul_adaptatifs_(028_DRE)':
     *  1. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_114.01 ;
     *  2. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_132.01 ;
     *  3. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_133.01 ;
     *  4. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_134.01 ;
     *  5. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_140.01 ;
     *  6. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_141.01 ;
     *  7. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_142.01 ;
     *  8. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_143.01 ;
     *  9. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_144.01 ;
     *  10. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_152.01 ;
     *  11. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_154.01 ;
     *  12. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_201.01 ;
     *  13. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_202.01 ;
     *  14. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_203.01 ;
     *  15. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_204.01 ;
     *  16. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_215.01 ;
     *  17. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_216.01 ;
     *  18. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_217.01 ;
     *  19. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_218.01 ;
     *  20. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_219.01 ;
     *  21. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_231.01 ;
     *  22. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_234.01 ;
     *  23. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_252.01 ;
     *  24. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_253.01 ;
     *  25. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_254.01 ;
     *  26. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_255.01 ;
     *  27. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_256.01 ;
     *  28. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_257.01 ;
     *  29. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_258.01 ;
     *  30. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_259.01 ;
     *  31. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_260.01 ;
     *  32. SubSystem "F03_calcul_adaptatifs_(028_DRE)" !Trace_To : VEMS_R_11_04467_333.01 ;
     *
     * Block requirements for '<S12>/F03_check_environment_adaption_(008_DRE)':
     *  1. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_020.01 ;
     *  2. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_207.01 ;
     *  3. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_209.01 ;
     *  4. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_135.01 ;
     *  5. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_137.01 ;
     *  6. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_138.01 ;
     *  7. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_139.01 ;
     *  8. SubSystem "F03_check_environment_adaption_(008_DRE)" !Trace_To : VEMS_R_11_04467_313.01 ;
     *
     * Block requirements for '<S12>/F03_reset_cumulated_model_noise_v(032_DRE)':
     *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
     *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
     *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
     *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
     *
     * Block requirements for '<S12>/F04_calc_innovation_vect_(033_DRE)':
     *  1. SubSystem "F04_calc_innovation_vect_(033_DRE)" !Trace_To : VEMS_R_11_04467_121.01 ;
     *  2. SubSystem "F04_calc_innovation_vect_(033_DRE)" !Trace_To : VEMS_R_11_04467_338.01 ;
     *
     * Block requirements for '<S12>/F04_command_adaptation_parameters_(009_DRE)':
     *  1. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_026.01 ;
     *  2. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_168.01 ;
     *  3. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_172.01 ;
     *  4. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_181.02 ;
     *  5. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_195.01 ;
     *  6. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_146.01 ;
     *  7. SubSystem "F04_command_adaptation_parameters_(009_DRE)" !Trace_To : VEMS_R_11_04467_314.01 ;
     *
     * Block requirements for '<S12>/F04_detect_adaptation_stop_(029_DRE)':
     *  1. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_115.01 ;
     *  2. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_132.01 ;
     *  3. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_133.01 ;
     *  4. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_134.01 ;
     *  5. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_140.01 ;
     *  6. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_141.01 ;
     *  7. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_142.01 ;
     *  8. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_143.01 ;
     *  9. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_144.01 ;
     *  10. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_152.01 ;
     *  11. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_154.01 ;
     *  12. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_263.01 ;
     *  13. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_264.01 ;
     *  14. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_265.01 ;
     *  15. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_266.01 ;
     *  16. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_267.01 ;
     *  17. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_268.01 ;
     *  18. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_269.01 ;
     *  19. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_270.01 ;
     *  20. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_271.01 ;
     *  21. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_272.01 ;
     *  22. SubSystem "F04_detect_adaptation_stop_(029_DRE)" !Trace_To : VEMS_R_11_04467_334.01 ;
     *
     * Block requirements for '<S12>/F05_calc_pred_innov_covar_mat_(034_DRE)':
     *  1. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_122.01 ;
     *  2. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
     *  3. SubSystem "F05_calc_pred_innov_covar_mat_(034_DRE)" !Trace_To : VEMS_R_11_04467_339.01 ;
     *
     * Block requirements for '<S12>/F06_add_adaption_noise_(020_DRE)':
     *  1. SubSystem "F06_add_adaption_noise_(020_DRE)" !Trace_To : VEMS_R_11_04467_053.01 ;
     *  2. SubSystem "F06_add_adaption_noise_(020_DRE)" !Trace_To : VEMS_R_11_04467_325.01 ;
     *
     * Block requirements for '<S12>/F06_calc_gain_de_kalman_(035_DRE)':
     *  1. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_125.01 ;
     *  2. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
     *  3. SubSystem "F06_calc_gain_de_kalman_(035_DRE)" !Trace_To : VEMS_R_11_04467_340.01 ;
     *
     * Block requirements for '<S12>/F07_calc_error_param_vect_(036_DRE)':
     *  1. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_126.01 ;
     *  2. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_248.01 ;
     *  3. SubSystem "F07_calc_error_param_vect_(036_DRE)" !Trace_To : VEMS_R_11_04467_341.01 ;
     *
     * Block requirements for '<S12>/F08_calc_est_error_covar_mat_(037_DRE)':
     *  1. SubSystem "F08_calc_est_error_covar_mat_(037_DRE)" !Trace_To : VEMS_R_11_04467_127.01 ;
     *  2. SubSystem "F08_calc_est_error_covar_mat_(037_DRE)" !Trace_To : VEMS_R_11_04467_342.01 ;
     *
     * Block requirements for '<S12>/F09_test_innovation_coherence_(038_DRE)':
     *  1. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_128.01 ;
     *  2. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_213.01 ;
     *  3. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_214.01 ;
     *  4. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_242.01 ;
     *  5. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_278.01 ;
     *  6. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
     *  7. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_305.01 ;
     *  8. SubSystem "F09_test_innovation_coherence_(038_DRE)" !Trace_To : VEMS_R_11_04467_343.01 ;
     */
    /* Gateway: AFAT/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)/F01_Gestion_algorythme_adaptation/F01_algo_adapt_control_process/F01_algo_adapt_control_process_chart1 */
    /* During: AFAT/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)/F01_Gestion_algorythme_adaptation/F01_algo_adapt_control_process/F01_algo_adapt_control_process_chart1 */
    if (AFAT_DWork.is_active_c10_AFAT == 0) {
      /* Entry: AFAT/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)/F01_Gestion_algorythme_adaptation/F01_algo_adapt_control_process/F01_algo_adapt_control_process_chart1 */
      AFAT_DWork.is_active_c10_AFAT = 1U;

      /* Transition: '<S278>:13' */
      /* Entry 'WAIT': '<S278>:1' */
      AFAT_DWork.is_c10_AFAT = IN_WAIT;
    } else {
      switch (AFAT_DWork.is_c10_AFAT) {
       case IN_APP:
        /* During 'APP': '<S278>:2' */
        /* Transition: '<S278>:22' */
        /* Transition: '<S278>:23' */
        /* Transition: '<S278>:16' */
        /* Exit 'APP': '<S278>:2' */
        /* Entry 'WAIT': '<S278>:1' */
        AFAT_DWork.is_c10_AFAT = IN_WAIT;
        break;

       case IN_OBS:
        /* During 'OBS': '<S278>:3' */
        /* Transition: '<S278>:15' */
        if (((SInt32)AFA_bObsRun) == 0) {
          /* Transition: '<S278>:14' */
          /* Exit 'Pas0': '<S278>:4' */
          AFAT_DWork.is_OBS = (UInt8)IN_NO_ACTIVE_CHILD;

          /* Exit 'Pas1': '<S278>:6' */
          /* Exit 'Pas2': '<S278>:8' */
          /* Exit 'Pas3': '<S278>:9' */
          /* Exit 'Pas4': '<S278>:10' */
          /* Exit 'Pas5': '<S278>:11' */
          /* Exit 'Pas6': '<S278>:12' */
          /* Exit 'Pas7': '<S278>:7' */
          /* Exit 'Pas8': '<S278>:5' */
          /* Exit 'OBS': '<S278>:3' */
          /* Entry 'WAIT': '<S278>:1' */
          AFAT_DWork.is_c10_AFAT = IN_WAIT;
        } else {
          switch (AFAT_DWork.is_OBS) {
           case IN_Pas0:
            /* During 'Pas0': '<S278>:4' */
            /* Transition: '<S278>:24' */
            /* Exit 'Pas0': '<S278>:4' */
            /* Entry 'Pas1': '<S278>:6' */
            AFAT_DWork.is_OBS = IN_Pas1;

            /* Event: '<S278>:59' */

            /* DataStoreRead: '<S256>/Data Store Read1' */
            for (locali = 0; locali < 8; locali++) {
              localDataStoreRead1_i[locali] = (*Rte_Pim_AFA_prm_covNoiseVal_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S256>/Data Store Read' */
            for (locali = 0; locali < 64; locali++) {
              AFAT_B.DataStoreRead_g[(locali)] =
                (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)];
            }

            /* ModelReference: '<S256>/AFAT_F02_calc_model_noise_mat' */
            mr_AFA_F02_calc_model_noise_mat(localDataStoreRead1_i,
              AFAT_B.DataStoreRead_g, AFAT_B.AFAT_F02_calc_model_noise_);

            /* DataStoreWrite: '<S256>/Data Store Write2' */
            for (locali = 0; locali < 64; locali++) {
              (*Rte_Pim_AFA_prm_covPredErrMat_PIM())[(locali)] =
                AFAT_B.AFAT_F02_calc_model_noise_[(locali)];
            }
            break;

           case IN_Pas1:
            /* During 'Pas1': '<S278>:6' */
            /* Transition: '<S278>:31' */
            /* Exit 'Pas1': '<S278>:6' */
            /* Entry 'Pas2': '<S278>:8' */
            AFAT_DWork.is_OBS = IN_Pas2;

            /* Event: '<S278>:57' */

            /* DataStoreRead: '<S262>/Data Store Read5' */
            for (locali = 0; locali < 8; locali++) {
              localDataStoreRead5[locali] = (*Rte_Pim_AFA_prm_rErr_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S262>/Data Store Read3' */
            localDataStoreRead3_n[0] = (*Rte_Pim_AFA_prm_facMes_PIM())[0];
            localDataStoreRead3_n[1] = (*Rte_Pim_AFA_prm_facMes_PIM())[1];

            /* DataStoreRead: '<S262>/Data Store Read4' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead4[locali] = (*Rte_Pim_AFA_prm_facSenTransMat_PIM
                ())[(locali)];
            }

            /* ModelReference: '<S262>/AFAT_F04_calc_innovation_vect' */
            mr_AFA_F04_calc_innovation_vect(localDataStoreRead5,
              localDataStoreRead3_n, localDataStoreRead4,
              localAFAT_F04_calc_innovation_c, localAFAT_F04_calc_innovation_v);

            /* DataStoreWrite: '<S262>/Data Store Write1' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_facSenMat_PIM())[(locali)] =
                localAFAT_F04_calc_innovation_v[locali];
            }

            /* DataStoreWrite: '<S262>/Data Store Write3' */
            (*Rte_Pim_AFA_prm_facOutInnov_PIM())[0] =
              localAFAT_F04_calc_innovation_c[0];
            (*Rte_Pim_AFA_prm_facOutInnov_PIM())[1] =
              localAFAT_F04_calc_innovation_c[1];
            break;

           case IN_Pas2:
            /* During 'Pas2': '<S278>:8' */
            /* Transition: '<S278>:28' */
            /* Exit 'Pas2': '<S278>:8' */
            /* Entry 'Pas3': '<S278>:9' */
            AFAT_DWork.is_OBS = IN_Pas3;

            /* Event: '<S278>:60' */
            for (locali = 0; locali < 16; locali++) {
              /* DataStoreRead: '<S266>/Data Store Read7' */
              localDataStoreRead7[locali] = (*Rte_Pim_AFA_prm_facSenMat_PIM())
                [(locali)];

              /* DataStoreRead: '<S266>/Data Store Read8' */
              localDataStoreRead8[locali] = (*Rte_Pim_AFA_prm_facSenTransMat_PIM
                ())[(locali)];
            }

            /* DataStoreRead: '<S266>/Data Store Read6' */
            for (locali = 0; locali < 64; locali++) {
              localDataStoreRead6[locali] = (*Rte_Pim_AFA_prm_covPredErrMat_PIM())
                [(locali)];
            }

            /* ModelReference: '<S266>/AFAT_F05_calc_pred_innov_covar_mat'
             *
             * Block requirements for '<S266>/AFAT_F05_calc_pred_innov_covar_mat':
             *  1. ModelReference "AFAT_F05_calc_pred_innov_covar_mat" !Trace_To : VEMS_R_11_04467_124.01 ;
             */
            mr_AFA_F05_calc_pred_innov_cova(localDataStoreRead7,
              localDataStoreRead8, localDataStoreRead6,
              localAFAT_F05_calc_pred_innov_c, &localAFAT_F05_calc_pred_innov_a,
              localAFAT_F05_calc_pred_innov_l, localAFAT_F05_calc_pred_inno_at);

            /* DataTypeConversion Block: '<S266>/Data Type Conversion195'
             *
             * Regarding '<S266>/Data Type Conversion195':
             *   Eliminate redundant data type conversion
             */

            /* DataStoreWrite: '<S266>/Data Store Write4' */
            (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[0] =
              localAFAT_F05_calc_pred_innov_c[0];

            /* DataStoreWrite: '<S266>/Data Store Write5' */
            (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[0] =
              localAFAT_F05_calc_pred_inno_at[0];

            /* DataStoreWrite: '<S266>/Data Store Write4' */
            (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[1] =
              localAFAT_F05_calc_pred_innov_c[1];

            /* DataStoreWrite: '<S266>/Data Store Write5' */
            (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[1] =
              localAFAT_F05_calc_pred_inno_at[1];

            /* DataStoreWrite: '<S266>/Data Store Write4' */
            (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[2] =
              localAFAT_F05_calc_pred_innov_c[2];

            /* DataStoreWrite: '<S266>/Data Store Write5' */
            (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[2] =
              localAFAT_F05_calc_pred_inno_at[2];

            /* DataStoreWrite: '<S266>/Data Store Write4' */
            (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[3] =
              localAFAT_F05_calc_pred_innov_c[3];

            /* DataStoreWrite: '<S266>/Data Store Write5' */
            (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[3] =
              localAFAT_F05_calc_pred_inno_at[3];

            /* DataStoreWrite: '<S266>/Data Store Write6' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_facInterMat_PIM())[(locali)] =
                localAFAT_F05_calc_pred_innov_l[locali];
            }

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S266>/autosar_irv_write56' */

            /* S-Function Block: <S266>/autosar_irv_write56 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_bIdcInv_covPredInnov_irv
              (localAFAT_F05_calc_pred_innov_a);

            /* SignalConversion: '<S379>/copy' */
            AFA_bIdcInv_covPredInnov_IRV_MP = localAFAT_F05_calc_pred_innov_a;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S379>/autosar_testpoint1' */

            /* S-Function Block: <S379>/autosar_testpoint1 */
            break;

           case IN_Pas3:
            /* During 'Pas3': '<S278>:9' */
            /* Transition: '<S278>:29' */
            /* Exit 'Pas3': '<S278>:9' */
            /* Entry 'Pas4': '<S278>:10' */
            AFAT_DWork.is_OBS = IN_Pas4;

            /* Event: '<S278>:56' */

            /* DataStoreRead: '<S268>/Data Store Read1' */
            localDataStoreRead1_j[0] = (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())
              [0];
            localDataStoreRead1_j[1] = (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())
              [1];
            localDataStoreRead1_j[2] = (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())
              [2];
            localDataStoreRead1_j[3] = (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())
              [3];

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S268>/autosar_irv_read193' */

            /* S-Function Block: <S268>/autosar_irv_read193 */
            localautosar_irv_read193 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_bIdcInv_covPredInnov_irv();

            /* DataTypeConversion Block: '<S268>/Data Type Conversion323'
             *
             * Regarding '<S268>/Data Type Conversion323':
             *   Eliminate redundant data type conversion
             */

            /* DataStoreRead: '<S268>/Data Store Read2' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead2[locali] = (*Rte_Pim_AFA_prm_facSenTransMat_PIM
                ())[(locali)];
            }

            /* DataStoreRead: '<S268>/Data Store Read' */
            for (locali = 0; locali < 64; locali++) {
              AFAT_B.DataStoreRead_nn[(locali)] =
                (*Rte_Pim_AFA_prm_covPredErrMat_PIM())[(locali)];
            }

            /* ModelReference: '<S268>/AFAT_F06_calc_gain_de_kalman' */
            mr_AFA_F06_calc_gain_de_kalman(localDataStoreRead1_j,
              &localautosar_irv_read193, localDataStoreRead2,
              AFAT_B.DataStoreRead_nn, localAFAT_F06_calc_gain_de_kalm);

            /* DataStoreWrite: '<S268>/Data Store Write5' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_facKalmMat_PIM())[(locali)] =
                localAFAT_F06_calc_gain_de_kalm[locali];
            }
            break;

           case IN_Pas4:
            /* During 'Pas4': '<S278>:10' */
            /* Transition: '<S278>:30' */
            /* Exit 'Pas4': '<S278>:10' */
            /* Entry 'Pas5': '<S278>:11' */
            AFAT_DWork.is_OBS = IN_Pas5;

            /* Event: '<S278>:54' */

            /* DataStoreRead: '<S270>/Data Store Read2' */
            localDataStoreRead2_n[0] = (*Rte_Pim_AFA_prm_facOutInnov_PIM())[0];
            localDataStoreRead2_n[1] = (*Rte_Pim_AFA_prm_facOutInnov_PIM())[1];
            for (locali = 0; locali < 8; locali++) {
              /* DataStoreRead: '<S270>/Data Store Read3' */
              localSignalConversion1_i[locali] = (*Rte_Pim_AFA_prm_rErr_PIM())
                [(locali)];

              /* SignalConversion: '<S270>/Signal Conversion2' */
              localSignalConversion2_i[locali] = (*Rte_Pim_AFA_prm_rErr_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S270>/Data Store Read1' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead1_bx[locali] = (*Rte_Pim_AFA_prm_facKalmMat_PIM())
                [(locali)];
            }

            /* ModelReference: '<S270>/AFAT_F07_calc_error_param_vect' */
            mr_AFA_F07_calc_error_param_vec(localDataStoreRead2_n,
              localSignalConversion2_i, localDataStoreRead1_bx,
              localAFAT_F07_calc_error_param_);
            for (locali = 0; locali < 8; locali++) {
              /* DataStoreWrite: '<S270>/Data Store Write5' */
              (*Rte_Pim_AFA_prm_rErr_PIM())[(locali)] =
                localAFAT_F07_calc_error_param_[locali];

              /* SignalConversion: '<S270>/Signal9' */
              AFAT_B.Signal9[(locali)] = localAFAT_F07_calc_error_param_[locali];
            }

            /* S-Function (NvRamWriteAccess): '<S270>/S-Function1' */
            {
              UInt32 locali;
              for (locali=0 ; locali <8; locali++) {
                AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[locali] =
                  AFAT_B.Signal9[locali];
              }
            }

            /* SignalConversion: '<S382>/copy' */
            for (locali = 0; locali < 8; locali++) {
              AFA_prm_rErrPrev[locali] = localSignalConversion1_i[locali];
            }

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S382>/autosar_testpoint1' */

            /* S-Function Block: <S382>/autosar_testpoint1 */
            break;

           case IN_Pas5:
            /* During 'Pas5': '<S278>:11' */
            /* Transition: '<S278>:26' */
            /* Exit 'Pas5': '<S278>:11' */
            /* Entry 'Pas6': '<S278>:12' */
            AFAT_DWork.is_OBS = IN_Pas6;

            /* Event: '<S278>:55' */

            /* DataStoreRead: '<S272>/Data Store Read3' */
            localDataStoreRead3_c[0] = (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[0];
            localDataStoreRead3_c[1] = (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[1];
            localDataStoreRead3_c[2] = (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[2];
            localDataStoreRead3_c[3] = (*Rte_Pim_AFA_prm_covNoiseMesMat_PIM())[3];

            /* DataStoreRead: '<S272>/Data Store Read4' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead4_e[locali] = (*Rte_Pim_AFA_prm_facKalmMat_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S272>/Data Store Read' */
            for (locali = 0; locali < 64; locali++) {
              localDataStoreRead_b[locali] = (*Rte_Pim_AFA_prm_covPredErrMat_PIM
                ())[(locali)];
            }

            for (locali = 0; locali < 16; locali++) {
              /* DataStoreRead: '<S272>/Data Store Read2' */
              localDataStoreRead2_my[locali] = (*Rte_Pim_AFA_prm_facInterMat_PIM
                ())[(locali)];

              /* DataStoreRead: '<S272>/Data Store Read1' */
              localDataStoreRead1[locali] = (*Rte_Pim_AFA_prm_facSenMat_PIM())
                [(locali)];
            }

            /* ModelReference: '<S272>/AFAT_F08_calc_est_error_covar_mat' */
            mr_AFA_F08_calc_est_error_covar(localDataStoreRead3_c,
              localDataStoreRead4_e, localDataStoreRead_b,
              localDataStoreRead2_my, localDataStoreRead1,
              AFAT_B.AFAT_F08_calc_est_error_co);

            /* Event: '<S278>:65' */
            for (locali = 0; locali < 64; locali++) {
              /* DataStoreWrite: '<S272>/Data Store Write' */
              (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)] =
                AFAT_B.AFAT_F08_calc_est_error_co[(locali)];

              /* DataStoreRead: '<S260>/Data Store Read' */
              localDataStoreRead_pl[locali] =
                (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)];
            }

            /* ModelReference: '<S260>/AFAT_F03_reset_cumulated_model_noise_v' */
            mr_AFA_F03_reset_cumulated_mode(localDataStoreRead_pl,
              AFAT_B.AFAT_F03_reset_cumulated_model_,
              localAFAT_F03_reset_cumulated_p);

            /* SignalConversion Block: '<S306>/copy'
             *
             * Regarding '<S306>/copy':
             *   Eliminate redundant signal conversion block
             */

            /* DataStoreWrite: '<S260>/Data Store Write4' incorporates:
             *  SignalConversion: '<S260>/Signal Conversion1'
             */
            for (locali = 0; locali < 8; locali++) {
              (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                localAFAT_F03_reset_cumulated_p[locali];
            }

            /* S-Function (NvRamWriteAccess): '<S260>/S-Function2' */
            {
              UInt32 locali;
              for (locali=0 ; locali <8; locali++) {
                AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali] =
                  AFAT_B.AFAT_F03_reset_cumulated_model_[locali];
              }
            }

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S306>/autosar_testpoint1' */

            /* S-Function Block: <S306>/autosar_testpoint1 */
            {
              SInt32 i1;
              const UInt16 *u0 = localAFAT_F03_reset_cumulated_p;
              for (i1=0; i1 < 8; i1++) {
                AFA_prm_covNoiseValIni[i1] = u0[i1];
              }
            }

            /* SignalConversion: '<S260>/Signal11' */
            for (locali = 0; locali < 8; locali++) {
              localAFA_prm_covErrEstim_merge_[locali] =
                AFAT_B.AFAT_F03_reset_cumulated_model_[(locali)];
            }
            break;

           case IN_Pas6:
            /* During 'Pas6': '<S278>:12' */
            /* Transition: '<S278>:27' */
            /* Exit 'Pas6': '<S278>:12' */
            /* Entry 'Pas7': '<S278>:7' */
            AFAT_DWork.is_OBS = IN_Pas7;

            /* Event: '<S278>:66' */

            /* DataStoreRead: '<S273>/Data Store Read2' */
            locallocalDataStoreRead2_i_idx = (*Rte_Pim_AFA_prm_facOutInnov_PIM())
              [0];
            locallocalDataStoreRead2_i_id_0 = (*Rte_Pim_AFA_prm_facOutInnov_PIM())
              [1];

            /* DataStoreRead: '<S273>/Data Store Read1' */
            locallocalDataStoreRead1_b_idx =
              (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[0];
            locallocalDataStoreRead1_b_id_0 =
              (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[1];
            locallocalDataStoreRead1_b_id_1 =
              (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[2];
            locallocalDataStoreRead1_b_id_2 =
              (*Rte_Pim_AFA_prm_covIvsPredInnovMat_PIM())[3];

            /* Outputs for atomic SubSystem: '<S273>/F01_Innovation_coherence' *
             * Block requirements for '<S273>/F01_Innovation_coherence':
             *  1. SubSystem "F01_Innovation_coherence" !Trace_To : VEMS_R_11_04467_129.01 ;
             */

            /* Product: '<S384>/Product3' incorporates:
             *  Math: '<S389>/Math Function'
             *  Product: '<S384>/Product2'
             */
            locali = locallocalDataStoreRead2_i_idx *
              locallocalDataStoreRead1_b_idx;
            locali += (locali < 0) ? 32767 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 15U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 15U)));
            if (locali > 32767) {
              locallocalDataStoreRead2_i = MAX_int16_T;
            } else if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i;
            if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i_id_0 *
              locallocalDataStoreRead1_b_id_0;
            locali += (locali < 0) ? 32767 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 15U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 15U)));
            if (locali > 32767) {
              localtmp = MAX_int16_T;
            } else if (locali <= -32768) {
              localtmp = MIN_int16_T;
            } else {
              localtmp = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i + localtmp;
            if (locali > 32767) {
              locallocalDataStoreRead2_i = MAX_int16_T;
            } else if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i * locallocalDataStoreRead2_i_idx;
            locali += (locali < 0) ? 65535 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 16U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 16U)));
            if (locali <= 0) {
              localSwitch_bm = 0U;
            } else {
              localSwitch_bm = (UInt16)locali;
            }

            locali = locallocalDataStoreRead2_i_idx *
              locallocalDataStoreRead1_b_id_1;
            locali += (locali < 0) ? 32767 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 15U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 15U)));
            if (locali > 32767) {
              locallocalDataStoreRead2_i = MAX_int16_T;
            } else if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i;
            if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i_id_0 *
              locallocalDataStoreRead1_b_id_2;
            locali += (locali < 0) ? 32767 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 15U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 15U)));
            if (locali > 32767) {
              localtmp = MAX_int16_T;
            } else if (locali <= -32768) {
              localtmp = MIN_int16_T;
            } else {
              localtmp = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i + localtmp;
            if (locali > 32767) {
              locallocalDataStoreRead2_i = MAX_int16_T;
            } else if (locali <= -32768) {
              locallocalDataStoreRead2_i = MIN_int16_T;
            } else {
              locallocalDataStoreRead2_i = (SInt16)locali;
            }

            locali = locallocalDataStoreRead2_i *
              locallocalDataStoreRead2_i_id_0;
            locali += (locali < 0) ? 65535 : 0;
            locali = (locali >= 0) ? ((SInt32)(((UInt32)locali) >> 16U)) :
              (~((SInt32)(((UInt32)(~locali)) >> 16U)));
            if (locali <= 0) {
              locallocalDataStoreRead1_b_idx = 0U;
            } else {
              locallocalDataStoreRead1_b_idx = (UInt16)locali;
            }

            localSwitch_hm = (UInt32)(localSwitch_bm +
              locallocalDataStoreRead1_b_idx);
            if (localSwitch_hm > 65535U) {
              AFA_facOutInnov_MP = MAX_uint16_T;
            } else {
              AFA_facOutInnov_MP = (UInt16)localSwitch_hm;
            }

            /* Logic: '<S384>/Logical Operator1' incorporates:
             *  Constant: '<S384>/AFA_facOutInnovThd_C'
             *  Logic: '<S384>/Logical Operator'
             *  RelationalOperator: '<S384>/Relational Operator1'
             *  S-Function (sfun_autosar_extras_irv_read_write): '<S273>/autosar_irv_read5'
             */
            localLogicalOperator1 = ((AFA_facOutInnov_MP < AFA_facOutInnovThd_C)
              && (!Rte_IrvRead_RE_AFAT_005_TEV_AFA_bIdcInv_covPredInnov_irv()));

            /* end of Outputs for SubSystem: '<S273>/F01_Innovation_coherence' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S273>/autosar_irv_read81' */

            /* S-Function Block: <S273>/autosar_irv_read81 */
            localautosar_irv_read81 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsInnovNotCoh_irv();

            /* DataTypeConversion Block: '<S273>/Data Type Conversion114'
             *
             * Regarding '<S273>/Data Type Conversion114':
             *   Eliminate redundant data type conversion
             */

            /* SignalConversion: '<S273>/Signal Conversion' */
            localSignal2 = localautosar_irv_read81;

            /* Outputs for atomic SubSystem: '<S273>/F02_Innovation_incoherence_counter' *
             * Block requirements for '<S273>/F02_Innovation_incoherence_counter':
             *  1. SubSystem "F02_Innovation_incoherence_counter" !Trace_To : VEMS_R_11_04467_130.01 ;
             */

            /* Switch: '<S385>/Switch2' incorporates:
             *  Constant: '<S385>/Constant4'
             *  Constant: '<S385>/Constant5'
             *  Sum: '<S385>/Subtract'
             */
            if (localLogicalOperator1) {
              localSwitch2 = 0U;
            } else {
              locali = localautosar_irv_read81 + 1;
              if (((UInt32)locali) > 255U) {
                localSwitch2 = MAX_uint8_T;
              } else {
                localSwitch2 = (UInt8)locali;
              }
            }

            /* end of Outputs for SubSystem: '<S273>/F02_Innovation_incoherence_counter' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S273>/autosar_irv_write122' */

            /* S-Function Block: <S273>/autosar_irv_write122 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsInnovNotCoh_irv(localSwitch2);

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S387>/autosar_testpoint1' */

            /* S-Function Block: <S387>/autosar_testpoint1 */
            AFA_noObsInnovNotCoh_IRV_MP = localSwitch2;

            /* SignalConversion: '<S388>/copy' */
            AFA_noObsInnovNotCohPrev = localSignal2;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S388>/autosar_testpoint1' */

            /* S-Function Block: <S388>/autosar_testpoint1 */

            /* If: '<S273>/If' incorporates:
             *  ActionPort: '<S386>/Action Port'
             *  Constant: '<S273>/Constant6'
             *  SubSystem: '<S273>/F03_Add_incoherence_model_noise'
             *
             * Block requirements for '<S273>/F03_Add_incoherence_model_noise':
             *  1. SubSystem "F03_Add_incoherence_model_noise" !Trace_To : VEMS_R_11_04467_131.01 ;
             */
            if (localSwitch2 > AFA_noObsInnovNotCohThd_C) {
              /* S-Function (fcncallgen): '<S386>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F05_add_incoherence_model_noise_(019_DRE)'
               *
               * Block requirements for '<S12>/F05_add_incoherence_model_noise_(019_DRE)':
               *  1. SubSystem "F05_add_incoherence_model_noise_(019_DRE)" !Trace_To : VEMS_R_11_04467_052.01 ;
               *  2. SubSystem "F05_add_incoherence_model_noise_(019_DRE)" !Trace_To : VEMS_R_11_04467_324.01 ;
               */

              /* DataStoreRead: '<S265>/Data Store Read2' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion6[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S265>/AFAT_F05_add_incoherence_model_noise' */
              mr_AFA_F05_add_incoherence_mode(localSignalConversion6,
                localAFAT_F05_add_incoherence_m);

              /* DataStoreWrite: '<S265>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F05_add_incoherence_m[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S378>/autosar_testpoint1' */

              /* S-Function Block: <S378>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion6;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }
            }

            /* Constant: '<S273>/Bool' */
            localAFA_bInnovTestCohDone_merg = TRUE;
            break;

           case IN_Pas7:
            /* During 'Pas7': '<S278>:7' */
            /* Transition: '<S278>:25' */
            /* Exit 'Pas7': '<S278>:7' */
            /* Entry 'Pas8': '<S278>:5' */
            AFAT_DWork.is_OBS = IN_Pas8;
            AFA_bObsRun = FALSE;
            break;

           case IN_Pas8:
            break;

           default:
            /* Transition: '<S278>:21' */
            /* Entry 'Pas0': '<S278>:4' */
            AFAT_DWork.is_OBS = IN_Pas0;
            AFAT_B.AFA_nEngLstObs_merge_e =
              AFAT_B.TmpSignalConversionAtExt_nEngOu;
            AFAT_B.AFA_rTotLdCorLstObs_merge_b =
              AFAT_B.TmpSignalConversionAtEngM_rTotL;

            /* Event: '<S278>:68' */

            /* ModelReference: '<S263>/AFAT_F04_command_adaptation_parameters' */
            mr_AFA_F04_command_adaptation_p
              (&AFAT_B.TmpSignalConversionAtAFA_noAdpE,
               &AFAT_B.TmpSignalConversionAtThrLrn_r_c,
               &AFAT_B.TmpSignalConversionAtInjSys_noT,
               &AFAT_B.TmpSignalConversionAtExt_nEngOu,
               &AFAT_B.TmpSignalConversionAtEngM_rTotL,
               localAFAT_F04_command_adaptatio);

            /* DataStoreWrite: '<S263>/Data Store Write4' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_bMaskSenMat_PIM())[(locali)] =
                localAFAT_F04_command_adaptatio[locali];
            }

            /* Event: '<S278>:63' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read18' */

            /* S-Function Block: <S248>/autosar_irv_read18 */
            localautosar_irv_read18 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read19' */

            /* S-Function Block: <S248>/autosar_irv_read19 */
            localautosar_irv_read19 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pExMnfEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read20' */

            /* S-Function Block: <S248>/autosar_irv_read20 */
            localautosar_irv_read20 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_nEngFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read21' */

            /* S-Function Block: <S248>/autosar_irv_read21 */
            localautosar_irv_read21 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tExMnfEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read22' */

            /* S-Function Block: <S248>/autosar_irv_read22 */
            localautosar_irv_read22 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tAirUsInVlvEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read23' */

            /* S-Function Block: <S248>/autosar_irv_read23 */
            localautosar_irv_read23 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkClsExVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read24' */

            /* S-Function Block: <S248>/autosar_irv_read24 */
            localautosar_irv_read24 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkOpInVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read25' */

            /* S-Function Block: <S248>/autosar_irv_read25 */
            localautosar_irv_read25 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rTotLdExCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read26' */

            /* S-Function Block: <S248>/autosar_irv_read26 */
            localautosar_irv_read26 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_facSlopEfcCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read28' */

            /* S-Function Block: <S248>/autosar_irv_read28 */
            localautosar_irv_read28 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffAdpThrFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read29' */

            /* S-Function Block: <S248>/autosar_irv_read29 */
            localautosar_irv_read29 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffAdpEGRVlvFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read30' */

            /* S-Function Block: <S248>/autosar_irv_read30 */
            localautosar_irv_read30 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rInMassFlowFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read31' */

            /* S-Function Block: <S248>/autosar_irv_read31 */
            localautosar_irv_read31 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rOpSIFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read32' */

            /* S-Function Block: <S248>/autosar_irv_read32 */
            localautosar_irv_read32 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffEGRVlvFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read36' */

            /* S-Function Block: <S248>/autosar_irv_read36 */
            localautosar_irv_read36 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkClsInVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read37' */

            /* S-Function Block: <S248>/autosar_irv_read37 */
            localautosar_irv_read37 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pAirExtEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read38' */

            /* S-Function Block: <S248>/autosar_irv_read38 */
            localautosar_irv_read38 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_mFuReqFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read39' */

            /* S-Function Block: <S248>/autosar_irv_read39 */
            localautosar_irv_read39 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tCoMesFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read40' */

            /* S-Function Block: <S248>/autosar_irv_read40 */
            localautosar_irv_read40 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrPred_facVlvOvlpFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read41' */

            /* S-Function Block: <S248>/autosar_irv_read41 */
            localautosar_irv_read41 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrEstimFil_irv();

            /* DataStoreRead: '<S248>/Data Store Read4' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead4_f[locali] = (*Rte_Pim_AFA_prm_bMaskSenMat_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[0] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [0];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[0] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[0];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[0] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[0];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[1] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [1];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[1] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[1];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[1] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[1];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[2] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [2];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[2] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[2];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[2] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[2];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[3] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [3];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[3] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[3];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[3] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[3];

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read1' */

            /* S-Function Block: <S248>/autosar_irv_read1 */
            localautosar_irv_read1 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_nEngCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read2' */

            /* S-Function Block: <S248>/autosar_irv_read2 */
            localautosar_irv_read2 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rEthStoichFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read3' */

            /* S-Function Block: <S248>/autosar_irv_read3 */
            localautosar_irv_read3 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_facRhoFuFil_irv();

            /* ModelReference: '<S248>/AFA_F01_AFAClcObs' */
            mr_AFA_F01_AFAClcObs(&localautosar_irv_read18,
                                 &localautosar_irv_read19,
                                 &localautosar_irv_read20,
                                 &localautosar_irv_read21,
                                 &localautosar_irv_read22,
                                 &localautosar_irv_read23,
                                 &localautosar_irv_read24,
                                 &localautosar_irv_read25,
                                 &localautosar_irv_read26,
                                 &AFAT_B.TmpSignalConversionAtAFA_rAirPr,
                                 &localautosar_irv_read28,
                                 &localautosar_irv_read29,
                                 &localautosar_irv_read30,
                                 &localautosar_irv_read31,
                                 &localautosar_irv_read32,
                                 &AFAT_B.TmpSignalConversionAtAFA_rAirLd,
                                 &localautosar_irv_read36,
                                 &localautosar_irv_read37,
                                 &localautosar_irv_read38,
                                 &localautosar_irv_read39,
                                 &localautosar_irv_read40,
                                 &localautosar_irv_read41,
                                 AFAT_B.TmpSignalConversionAtInjrSys_pr,
                                 localDataStoreRead4_f, localDataStoreRead1_l,
                                 localDataStoreRead2_m, localDataStoreRead3,
                                 &localautosar_irv_read1,
                                 &localautosar_irv_read2,
                                 &localautosar_irv_read3, localAFA_F01_AFAClcObs);

            /* DataStoreWrite: '<S248>/Data Store Write13' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_facSenTransMat_PIM())[(locali)] =
                localAFA_F01_AFAClcObs[locali];
            }

            /* Event: '<S278>:58' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S251>/autosar_irv_read63' */

            /* S-Function Block: <S251>/autosar_irv_read63 */
            localautosar_irv_read63 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrEstimErrFil_irv();

            /* ModelReference: '<S251>/AFAT_F01_calc_measurement_vector' */
            mr_AFA_F01_calc_measurement_vec(&localautosar_irv_read63,
              &AFAT_B.TmpSignalConversionAtInjSys_lam,
              &AFAT_B.TmpSignalConversionAtAFA_noAdpE,
              localAFAT_F01_calc_measurement_);

            /* DataStoreWrite: '<S251>/Data Store Write' */
            (*Rte_Pim_AFA_prm_facMes_PIM())[0] =
              localAFAT_F01_calc_measurement_[0];
            (*Rte_Pim_AFA_prm_facMes_PIM())[1] =
              localAFAT_F01_calc_measurement_[1];/* Event: '<S278>:67' */

            /* SignalConversion: '<S250>/Signal1' */
            localSignal1 = AFAT_B.TmpSignalConversionAtEngM_rTotL;

            /* DataStoreRead: '<S250>/Data Store Read2' */
            for (locali = 0; locali < 9; locali++) {
              localDataStoreRead2_p[locali] = (*Rte_Pim_AFA_prm_noObsDoneMat_PIM
                ())[(locali)];
            }

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_read1' */

            /* S-Function Block: <S250>/autosar_irv_read1 */
            localSignal3 = Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_read133' */

            /* S-Function Block: <S250>/autosar_irv_read133 */
            localSignal4 = Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv();

            /* ModelReference: '<S250>/AFAT_F01_Osbservation_Number' */
            mr_AFA_F01_Osbservation_Number
              (&AFAT_B.TmpSignalConversionAtIdlSys_bAc,
               &AFAT_B.TmpSignalConversionAtExt_nEngOu, &localSignal1,
               localDataStoreRead2_p, &localSignal3,
               &AFAT_B.TmpSignalConversionAtEOM_bSpcIn, &localSignal4,
               &AFAT_B.TmpSignalConversionAtAFA_noAdpE,
               localAFAT_F01_Osbservation_Numb,
               &AFAT_B.AFAT_F01_Osbservation_Number_o2,
               &localAFAT_F01_Osbservation_Nu_b,
               &localAFAT_F01_Osbservation_Nu_f);

            /* DataStoreWrite: '<S250>/Data Store Write9' */
            for (locali = 0; locali < 9; locali++) {
              (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali)] =
                localAFAT_F01_Osbservation_Numb[locali];
            }

            /* SignalConversion: '<S250>/Signal10' */
            AFAT_B.Signal10 = localAFAT_F01_Osbservation_Nu_f;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess' */
            AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV = AFAT_B.Signal10;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess1' */
            AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV =
              AFAT_B.AFAT_F01_Osbservation_Number_o2;

            /* SignalConversion: '<S250>/Signal11' */
            AFAT_B.Signal11 = localAFAT_F01_Osbservation_Nu_b;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess2' */
            AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV = AFAT_B.Signal11;

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_write4' */

            /* S-Function Block: <S250>/autosar_irv_write4 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv(AFAT_B.Signal10);

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_write40' */

            /* S-Function Block: <S250>/autosar_irv_write40 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv(AFAT_B.Signal11);

            /* SignalConversion: '<S281>/copy' */
            AFA_noObsDoneIdlPrev = localSignal3;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S281>/autosar_testpoint1' */

            /* S-Function Block: <S281>/autosar_testpoint1 */

            /* SignalConversion: '<S282>/copy' */
            AFA_noObsSpcInjModPrev = localSignal4;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S282>/autosar_testpoint1' */

            /* S-Function Block: <S282>/autosar_testpoint1 */

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S283>/autosar_testpoint1' */

            /* S-Function Block: <S283>/autosar_testpoint1 */
            AFA_noObsDoneIdlIni_IRV_MP = AFAT_B.Signal11;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S284>/autosar_testpoint1' */

            /* S-Function Block: <S284>/autosar_testpoint1 */
            AFA_noObsSpcInjMod_IRV_MP = AFAT_B.Signal10;

            /* SignalConversion: '<S250>/Signal2' */
            localAFA_bEngStopAuth_merge_i =
              AFAT_B.AFAT_F01_Osbservation_Number_o2;
            AFAT_B.AFA_noObsDone_merge_j = (UInt8)(localSignal2 + 1);
            AFAT_B.AFA_tiDlyLstObs_merge_h = 0U;
            break;
          }
        }
        break;

       case IN_WAIT:
        /* During 'WAIT': '<S278>:1' */
        /* Transition: '<S278>:17' */
        if (((SInt32)AFAT_B.TmpSignalConversionAtAFAMgt_bAd) == 1) {
          /* Transition: '<S278>:19' */
          /* Exit 'WAIT': '<S278>:1' */
          /* Entry 'APP': '<S278>:2' */
          AFAT_DWork.is_c10_AFAT = IN_APP;
          AFA_stMonAdp = AFA_stEfc_SC;

          /* Event: '<S278>:61' */

          /* DataStoreRead: '<S258>/Data Store Read2' */
          for (locali = 0; locali < 8; locali++) {
            localDataStoreRead2_d[locali] = (*Rte_Pim_AFA_prm_rErr_PIM())
              [(locali)];
          }

          /* DataTypeConversion: '<S258>/Data Type Conversion' */
          localDataTypeConversion = mul_s32_s32_s32_sr16_sat
            (AFAT_B.TmpSignalConversionAtAFA_facSlo, 46875);

          /* ModelReference: '<S258>/AFAT_F03_calcul_adaptatifs' */
          mr_AFA_F03_calcul_adaptatifs(localDataStoreRead2_d,
            &AFAT_B.TmpSignalConversionAtAFA_tiOffI, &localDataTypeConversion,
            &AFAT_B.TmpSignalConversionAtAFA_arEffT,
            &AFAT_B.TmpSignalConversionAtAFA_facArE,
            &AFAT_B.TmpSignalConversionAtAFA_facA_d,
            &AFAT_B.TmpSignalConversionAtAFA_facA_l,
            &AFAT_B.TmpSignalConversionAtAFA_rCor_a,
            &AFAT_B.TmpSignalConversionAtAFA_facIvs,
            &AFAT_B.TmpSignalConversionAtAFA_agCkOp,
            &AFAT_B.TmpSignalConversionAtAFA_agCkCl,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o1,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o2,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o3,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o4,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o5,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o6,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o7,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o8,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o9,
            &AFAT_B.AFAT_F03_calcul_adaptatifs_o10,
            &AFAT_B.AFA_arEffEGRVlvOfs_merge_j);

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess10' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs3_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o7;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess11' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_rCor_arEffEGRVlv_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o8;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess12' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkOpInVlvOfs_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o9;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess13' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_agCkClsExVlvOfs_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o10;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess4' */
          AFAT_sNV_Z1_CALIB_16BIT.AFA_facIvsInjGain_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o1;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess5' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_tiOffInj_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o2;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess6' */
          AFAT_sNV_Z1_CALIB_32BIT.AFA_facSlopInjGain_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o3;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess7' */
          AFAT_sNV_Z1_CALIB_16BIT.AFA_arEffThrOfs_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o4;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess8' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs1_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o5;

          /* S-Function (NvRamWriteAccess): '<S258>/EepromWriteAccess9' */
          AFAT_sNV_Z1_CALIB_8BIT.AFA_facArEffThrOfs2_NV =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o6;

          /* SignalConversion: '<S258>/Signal1' */
          localAFA_agCkOpInVlvOfs_merge_k = AFAT_B.AFAT_F03_calcul_adaptatifs_o9;

          /* SignalConversion: '<S258>/Signal11' */
          localAFA_agCkClsExVlvOfs_merge_ =
            AFAT_B.AFAT_F03_calcul_adaptatifs_o10;

          /* SignalConversion: '<S258>/Signal2' */
          localAFA_rCor_arEffEGRVlv_merge = AFAT_B.AFAT_F03_calcul_adaptatifs_o8;

          /* SignalConversion: '<S258>/Signal3' */
          localAFA_facArEffThrOfs3_merge_ = AFAT_B.AFAT_F03_calcul_adaptatifs_o7;

          /* SignalConversion: '<S258>/Signal4' */
          localAFA_facArEffThrOfs2_merge_ = AFAT_B.AFAT_F03_calcul_adaptatifs_o6;

          /* SignalConversion: '<S258>/Signal5' */
          localAFA_facArEffThrOfs1_merge_ = AFAT_B.AFAT_F03_calcul_adaptatifs_o5;

          /* SignalConversion: '<S258>/Signal6' */
          localAFA_arEffThrOfs_merge_h = AFAT_B.AFAT_F03_calcul_adaptatifs_o4;

          /* SignalConversion: '<S258>/Signal7' */
          localAFA_facSlopInjGain_merge_m = AFAT_B.AFAT_F03_calcul_adaptatifs_o3;

          /* SignalConversion: '<S258>/Signal8' */
          localAFA_tiOffInj_merge_i = AFAT_B.AFAT_F03_calcul_adaptatifs_o2;

          /* SignalConversion: '<S258>/Signal9' */
          localAFA_facIvsInjGain_merge_k = AFAT_B.AFAT_F03_calcul_adaptatifs_o1;

          /* Event: '<S278>:51' */

          /* ModelReference: '<S264>/AFAT_F04_detect_adaptation_stop' */
          mr_AFA_F04_detect_adaptation_st
            (&AFAT_B.TmpSignalConversionAtAFA_facIvs,
             &AFAT_B.TmpSignalConversionAtAFA_tiOffI,
             &AFAT_B.TmpSignalConversionAtAFA_facSlo,
             &AFAT_B.TmpSignalConversionAtAFA_arEffT,
             &AFAT_B.TmpSignalConversionAtAFA_facArE,
             &AFAT_B.TmpSignalConversionAtAFA_facA_d,
             &AFAT_B.TmpSignalConversionAtAFA_facA_l,
             &AFAT_B.TmpSignalConversionAtAFA_rCor_a,
             &AFAT_B.TmpSignalConversionAtAFA_agCkOp,
             &AFAT_B.TmpSignalConversionAtAFA_agCkCl,
             &localAFAT_F04_detect_adaptation, &localAFAT_F04_detect_adaptati_c,
             &localAFAT_F04_detect_adaptati_o, &localAFAT_F04_detect_adaptati_p,
             &localAFAT_F04_detect_adaptati_g, &localAFAT_F04_detect_adaptat_op,
             &localAFAT_F04_detect_adaptati_d, &localAFAT_F04_detect_adaptat_ps,
             &localAFAT_F04_detect_adaptati_n, &localAFAT_F04_detect_adaptat_cs,
             &localAFAT_F04_detect_adaptat_o5, &localAFAT_F04_detect_adaptati_m,
             &localAFAT_F04_detect_adaptati_a, &localAFAT_F04_detect_adaptati_k,
             &localAFAT_F04_detect_adaptat_kt, &localAFAT_F04_detect_adaptati_h,
             &localAFAT_F04_detect_adaptat_oy, &localAFAT_F04_detect_adaptat_nu,
             &localAFAT_F04_detect_adaptat_kv, &localAFAT_F04_detect_adapta_oyb);

          /* If: '<S308>/If' incorporates:
           *  ActionPort: '<S318>/Action Port'
           *  Constant: '<S264>/AFAT_ACTIVE_BYP_C1'
           *  SubSystem: '<S308>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S318>/If' incorporates:
             *  ActionPort: '<S319>/Action Port'
             *  ActionPort: '<S320>/Action Port'
             *  SubSystem: '<S318>/if_s1'
             *  SubSystem: '<S318>/if_s2'
             */
            if (localAFAT_F04_detect_adaptat_kt) {
              /* If: '<S319>/If' incorporates:
               *  ActionPort: '<S321>/Action Port'
               *  ActionPort: '<S322>/Action Port'
               *  SubSystem: '<S319>/if_s1'
               *  SubSystem: '<S319>/if_s2'
               */
              if (localAFAT_F04_detect_adaptati_h) {
                /* S-Function (sfun_autosar_clientop): '<S321>/Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S321>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S322>/Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S322>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S320>/If' incorporates:
               *  ActionPort: '<S323>/Action Port'
               *  Memory: '<S318>/Memory'
               *  SubSystem: '<S320>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_p) {
                /* S-Function (sfun_autosar_clientop): '<S323>/Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S323>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S318>/Memory' */
            AFAT_DWork.Memory_PreviousInput_p = localAFAT_F04_detect_adaptat_kt;
          }

          /* If: '<S309>/If' incorporates:
           *  ActionPort: '<S324>/Action Port'
           *  Constant: '<S264>/Constant7'
           *  SubSystem: '<S309>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S324>/If' incorporates:
             *  ActionPort: '<S325>/Action Port'
             *  ActionPort: '<S326>/Action Port'
             *  SubSystem: '<S324>/if_s1'
             *  SubSystem: '<S324>/if_s2'
             */
            if (localAFAT_F04_detect_adaptati_n) {
              /* If: '<S325>/If' incorporates:
               *  ActionPort: '<S327>/Action Port'
               *  ActionPort: '<S328>/Action Port'
               *  SubSystem: '<S325>/if_s1'
               *  SubSystem: '<S325>/if_s2'
               */
              if (localAFAT_F04_detect_adaptat_cs) {
                /* S-Function (sfun_autosar_clientop): '<S327>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S327>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S328>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S328>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S326>/If' incorporates:
               *  ActionPort: '<S329>/Action Port'
               *  Memory: '<S324>/Memory'
               *  SubSystem: '<S326>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_e2) {
                /* S-Function (sfun_autosar_clientop): '<S329>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S329>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S324>/Memory' */
            AFAT_DWork.Memory_PreviousInput_e2 = localAFAT_F04_detect_adaptati_n;
          }

          /* If: '<S310>/If' incorporates:
           *  ActionPort: '<S330>/Action Port'
           *  Constant: '<S264>/Constant8'
           *  SubSystem: '<S310>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S330>/If' incorporates:
             *  ActionPort: '<S331>/Action Port'
             *  ActionPort: '<S332>/Action Port'
             *  SubSystem: '<S330>/if_s1'
             *  SubSystem: '<S330>/if_s2'
             */
            if (localAFAT_F04_detect_adaptat_o5) {
              /* If: '<S331>/If' incorporates:
               *  ActionPort: '<S333>/Action Port'
               *  ActionPort: '<S334>/Action Port'
               *  SubSystem: '<S331>/if_s1'
               *  SubSystem: '<S331>/if_s2'
               */
              if (localAFAT_F04_detect_adaptati_m) {
                /* S-Function (sfun_autosar_clientop): '<S333>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S333>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S334>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S334>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S332>/If' incorporates:
               *  ActionPort: '<S335>/Action Port'
               *  Memory: '<S330>/Memory'
               *  SubSystem: '<S332>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_nc) {
                /* S-Function (sfun_autosar_clientop): '<S335>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S335>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S330>/Memory' */
            AFAT_DWork.Memory_PreviousInput_nc = localAFAT_F04_detect_adaptat_o5;
          }

          /* If: '<S311>/If' incorporates:
           *  ActionPort: '<S336>/Action Port'
           *  Constant: '<S264>/Constant9'
           *  SubSystem: '<S311>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S336>/If' incorporates:
             *  ActionPort: '<S337>/Action Port'
             *  ActionPort: '<S338>/Action Port'
             *  SubSystem: '<S336>/if_s1'
             *  SubSystem: '<S336>/if_s2'
             */
            if (localAFAT_F04_detect_adaptati_a) {
              /* If: '<S337>/If' incorporates:
               *  ActionPort: '<S339>/Action Port'
               *  ActionPort: '<S340>/Action Port'
               *  SubSystem: '<S337>/if_s1'
               *  SubSystem: '<S337>/if_s2'
               */
              if (localAFAT_F04_detect_adaptati_k) {
                /* S-Function (sfun_autosar_clientop): '<S339>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S339>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S340>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S340>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S338>/If' incorporates:
               *  ActionPort: '<S341>/Action Port'
               *  Memory: '<S336>/Memory'
               *  SubSystem: '<S338>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_n) {
                /* S-Function (sfun_autosar_clientop): '<S341>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S341>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S336>/Memory' */
            AFAT_DWork.Memory_PreviousInput_n = localAFAT_F04_detect_adaptati_a;
          }

          /* If: '<S312>/If' incorporates:
           *  ActionPort: '<S342>/Action Port'
           *  Constant: '<S264>/AFAT_ACTIVE_BYP_C'
           *  SubSystem: '<S312>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S342>/If' incorporates:
             *  ActionPort: '<S343>/Action Port'
             *  ActionPort: '<S344>/Action Port'
             *  SubSystem: '<S342>/if_s1'
             *  SubSystem: '<S342>/if_s2'
             */
            if (localAFAT_F04_detect_adaptati_d) {
              /* If: '<S343>/If' incorporates:
               *  ActionPort: '<S345>/Action Port'
               *  ActionPort: '<S346>/Action Port'
               *  SubSystem: '<S343>/if_s1'
               *  SubSystem: '<S343>/if_s2'
               */
              if (localAFAT_F04_detect_adaptat_ps) {
                /* S-Function (sfun_autosar_clientop): '<S345>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S345>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S346>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S346>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S344>/If' incorporates:
               *  ActionPort: '<S347>/Action Port'
               *  Memory: '<S342>/Memory'
               *  SubSystem: '<S344>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_a) {
                /* S-Function (sfun_autosar_clientop): '<S347>/Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S347>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S342>/Memory' */
            AFAT_DWork.Memory_PreviousInput_a = localAFAT_F04_detect_adaptati_d;
          }

          /* If: '<S313>/If' incorporates:
           *  ActionPort: '<S348>/Action Port'
           *  Constant: '<S264>/Constant2'
           *  SubSystem: '<S313>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S348>/If' incorporates:
             *  ActionPort: '<S349>/Action Port'
             *  ActionPort: '<S350>/Action Port'
             *  SubSystem: '<S348>/if_s1'
             *  SubSystem: '<S348>/if_s2'
             */
            if (localAFAT_F04_detect_adaptat_kv) {
              /* If: '<S349>/If' incorporates:
               *  ActionPort: '<S351>/Action Port'
               *  ActionPort: '<S352>/Action Port'
               *  SubSystem: '<S349>/if_s1'
               *  SubSystem: '<S349>/if_s2'
               */
              if (localAFAT_F04_detect_adapta_oyb) {
                /* S-Function (sfun_autosar_clientop): '<S351>/Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S351>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S352>/Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S352>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S350>/If' incorporates:
               *  ActionPort: '<S353>/Action Port'
               *  Memory: '<S348>/Memory'
               *  SubSystem: '<S350>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_g) {
                /* S-Function (sfun_autosar_clientop): '<S353>/Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S353>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpClsExOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S348>/Memory' */
            AFAT_DWork.Memory_PreviousInput_g = localAFAT_F04_detect_adaptat_kv;
          }

          /* If: '<S314>/If' incorporates:
           *  ActionPort: '<S354>/Action Port'
           *  Constant: '<S264>/Constant3'
           *  SubSystem: '<S314>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S354>/If' incorporates:
             *  ActionPort: '<S355>/Action Port'
             *  ActionPort: '<S356>/Action Port'
             *  SubSystem: '<S354>/if_s1'
             *  SubSystem: '<S354>/if_s2'
             */
            if (localAFAT_F04_detect_adaptati_o) {
              /* If: '<S355>/If' incorporates:
               *  ActionPort: '<S357>/Action Port'
               *  ActionPort: '<S358>/Action Port'
               *  SubSystem: '<S355>/if_s1'
               *  SubSystem: '<S355>/if_s2'
               */
              if (localAFAT_F04_detect_adaptati_p) {
                /* S-Function (sfun_autosar_clientop): '<S357>/Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S357>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S358>/Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S358>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S356>/If' incorporates:
               *  ActionPort: '<S359>/Action Port'
               *  Memory: '<S354>/Memory'
               *  SubSystem: '<S356>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_e) {
                /* S-Function (sfun_autosar_clientop): '<S359>/Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S359>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpInjOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S354>/Memory' */
            AFAT_DWork.Memory_PreviousInput_e = localAFAT_F04_detect_adaptati_o;
          }

          /* If: '<S315>/If' incorporates:
           *  ActionPort: '<S360>/Action Port'
           *  Constant: '<S264>/Constant4'
           *  SubSystem: '<S315>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S360>/If' incorporates:
             *  ActionPort: '<S361>/Action Port'
             *  ActionPort: '<S362>/Action Port'
             *  SubSystem: '<S360>/if_s1'
             *  SubSystem: '<S360>/if_s2'
             */
            if (localAFAT_F04_detect_adaptation) {
              /* If: '<S361>/If' incorporates:
               *  ActionPort: '<S363>/Action Port'
               *  ActionPort: '<S364>/Action Port'
               *  SubSystem: '<S361>/if_s1'
               *  SubSystem: '<S361>/if_s2'
               */
              if (localAFAT_F04_detect_adaptati_c) {
                /* S-Function (sfun_autosar_clientop): '<S363>/Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S363>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S364>/Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S364>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S362>/If' incorporates:
               *  ActionPort: '<S365>/Action Port'
               *  Memory: '<S360>/Memory'
               *  SubSystem: '<S362>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_k) {
                /* S-Function (sfun_autosar_clientop): '<S365>/Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S365>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpIvsInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S360>/Memory' */
            AFAT_DWork.Memory_PreviousInput_k = localAFAT_F04_detect_adaptation;
          }

          /* If: '<S316>/If' incorporates:
           *  ActionPort: '<S366>/Action Port'
           *  Constant: '<S264>/Constant5'
           *  SubSystem: '<S316>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S366>/If' incorporates:
             *  ActionPort: '<S367>/Action Port'
             *  ActionPort: '<S368>/Action Port'
             *  SubSystem: '<S366>/if_s1'
             *  SubSystem: '<S366>/if_s2'
             */
            if (localAFAT_F04_detect_adaptat_oy) {
              /* If: '<S367>/If' incorporates:
               *  ActionPort: '<S369>/Action Port'
               *  ActionPort: '<S370>/Action Port'
               *  SubSystem: '<S367>/if_s1'
               *  SubSystem: '<S367>/if_s2'
               */
              if (localAFAT_F04_detect_adaptat_nu) {
                /* S-Function (sfun_autosar_clientop): '<S369>/Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S369>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S370>/Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S370>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S368>/If' incorporates:
               *  ActionPort: '<S371>/Action Port'
               *  Memory: '<S366>/Memory'
               *  SubSystem: '<S368>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput_o) {
                /* S-Function (sfun_autosar_clientop): '<S371>/Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S371>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpOpInOfsLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S366>/Memory' */
            AFAT_DWork.Memory_PreviousInput_o = localAFAT_F04_detect_adaptat_oy;
          }

          /* If: '<S317>/If' incorporates:
           *  ActionPort: '<S372>/Action Port'
           *  Constant: '<S264>/Constant6'
           *  SubSystem: '<S317>/If_s'
           */
          if (!AFAT_ACTIVE_BYP_C) {
            /* If: '<S372>/If' incorporates:
             *  ActionPort: '<S373>/Action Port'
             *  ActionPort: '<S374>/Action Port'
             *  SubSystem: '<S372>/if_s1'
             *  SubSystem: '<S372>/if_s2'
             */
            if (localAFAT_F04_detect_adaptati_g) {
              /* If: '<S373>/If' incorporates:
               *  ActionPort: '<S375>/Action Port'
               *  ActionPort: '<S376>/Action Port'
               *  SubSystem: '<S373>/if_s1'
               *  SubSystem: '<S373>/if_s2'
               */
              if (localAFAT_F04_detect_adaptat_op) {
                /* S-Function (sfun_autosar_clientop): '<S375>/Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S375>/Constant1'
                 */
                Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREFAILED);
              } else {
                /* S-Function (sfun_autosar_clientop): '<S376>/Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S376>/Constant2'
                 */
                Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_PREPASSED);
              }
            } else {
              /* If: '<S374>/If' incorporates:
               *  ActionPort: '<S377>/Action Port'
               *  Memory: '<S372>/Memory'
               *  SubSystem: '<S374>/If Action Subsystem'
               */
              if (AFAT_DWork.Memory_PreviousInput) {
                /* S-Function (sfun_autosar_clientop): '<S377>/Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus_sf' incorporates:
                 *  Constant: '<S377>/Constant3'
                 */
                Rte_Call_R_AFAT_AFA_AdpSlopInjConLim_SetEventStatus
                  (DEM_EVENT_STATUS_INIT);
              }
            }

            /* Update for Memory: '<S372>/Memory' */
            AFAT_DWork.Memory_PreviousInput = localAFAT_F04_detect_adaptati_g;
          }

          /* Event: '<S278>:64' */

          /* DataStoreRead: '<S252>/Data Store Read' */
          for (locali = 0; locali < 64; locali++) {
            AFAT_B.DataStoreRead_n[(locali)] =
              (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)];
          }

          /* ModelReference: '<S252>/AFAT_F01_reinit_after_app_adaption' */
          mr_AFA_F01_reinit_after_app_ada
            (&AFAT_B.TmpSignalConversionAtAFA_noAdpE,
             &AFAT_B.TmpSignalConversionAtAFA_noAd_e,
             AFAT_B.TmpSignalConversionAtAFA_prm_co, AFAT_B.DataStoreRead_n,
             &AFAT_B.AFAT_F01_reinit_after_app_adapt,
             AFAT_B.AFAT_F01_reinit_after_app_ada_m,
             &localAFAT_F01_reinit_after_app_,
             &AFAT_B.AFA_bAuthClsCanPurg_merge_m,
             localAFAT_F01_reinit_after_ap_h,
             &AFAT_B.AFAT_F01_reinit_after_app_ada_p,
             &AFAT_B.AFA_noAdpEfcAst_merge_l,
             AFAT_B.AFAT_F01_reinit_after_app_ada_e);

          /* S-Function Block: '<S285>/FixPt Data Type Propagation'
           *
           * Regarding '<S285>/FixPt Data Type Propagation':
           *   Unused code path elimination
           */

          /* DataTypeConversion Block: '<S285>/FixPt Gateway Out'
           *
           * Regarding '<S285>/FixPt Gateway Out':
           *   Eliminate redundant data type conversion
           */

          /* SignalConversion Block: '<S286>/copy'
           *
           * Regarding '<S286>/copy':
           *   Eliminate redundant signal conversion block
           */

          /* SignalConversion Block: '<S287>/copy'
           *
           * Regarding '<S287>/copy':
           *   Eliminate redundant signal conversion block
           */

          /* SignalConversion Block: '<S288>/copy'
           *
           * Regarding '<S288>/copy':
           *   Eliminate redundant signal conversion block
           */

          /* SignalConversion Block: '<S289>/copy'
           *
           * Regarding '<S289>/copy':
           *   Eliminate redundant signal conversion block
           */

          /* SignalConversion Block: '<S290>/copy'
           *
           * Regarding '<S290>/copy':
           *   Eliminate redundant signal conversion block
           */

          /* DataStoreWrite: '<S252>/Data Store Write' */
          for (locali = 0; locali < 64; locali++) {
            (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)] =
              AFAT_B.AFAT_F01_reinit_after_app_ada_e[(locali)];
          }

          /* DataStoreWrite: '<S252>/Data Store Write1' */
          for (locali = 0; locali < 9; locali++) {
            (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali)] =
              localAFAT_F01_reinit_after_ap_h[locali];
          }

          /* DataStoreWrite: '<S252>/Data Store Write5' */
          for (locali = 0; locali < 8; locali++) {
            (*Rte_Pim_AFA_prm_rErr_PIM())[(locali)] =
              AFAT_B.AFAT_F01_reinit_after_app_ada_m[(locali)];
          }

          /* S-Function (NvRamWriteAccess): '<S252>/EepromWriteAccess' */
          AFAT_sNV_Z1_CONST_16BIT.AFA_noAdpEfc_NV =
            AFAT_B.AFAT_F01_reinit_after_app_adapt;

          /* S-Function (NvRamWriteAccess): '<S252>/EepromWriteAccess1' */
          AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV =
            AFAT_B.AFAT_F01_reinit_after_app_ada_p;

          /* S-Function (NvRamWriteAccess): '<S252>/S-Function1' */
          {
            UInt32 locali;
            for (locali=0 ; locali <8; locali++) {
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[locali] =
                AFAT_B.AFAT_F01_reinit_after_app_ada_m[locali];
            }
          }

          /* S-Function (sfun_autosar_extras_irv_read_write): '<S252>/autosar_irv_write151' */

          /* S-Function Block: <S252>/autosar_irv_write151 */
          Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv
            (AFAT_B.AFAT_F01_reinit_after_app_ada_p);

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S286>/autosar_testpoint1' */

          /* S-Function Block: <S286>/autosar_testpoint1 */
          AFA_noObsDoneIni = localAFAT_F01_reinit_after_app_;

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S287>/autosar_testpoint1' */

          /* S-Function Block: <S287>/autosar_testpoint1 */
          AFA_noObsDoneIdlIni_IRV_MP = AFAT_B.AFAT_F01_reinit_after_app_ada_p;

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S288>/autosar_testpoint1' */

          /* S-Function Block: <S288>/autosar_testpoint1 */
          {
            SInt32 i1;
            const SInt16 *u0 = AFAT_B.AFAT_F01_reinit_after_app_ada_m;
            for (i1=0; i1 < 8; i1++) {
              AFA_prm_rErrIni[i1] = u0[i1];
            }
          }

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S289>/autosar_testpoint1' */

          /* S-Function Block: <S289>/autosar_testpoint1 */
          {
            SInt32 i1;
            const UInt8 *u0 = localAFAT_F01_reinit_after_ap_h;
            for (i1=0; i1 < 9; i1++) {
              AFA_prm_noObsDoneMatIni[i1] = u0[i1];
            }
          }

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S290>/autosar_testpoint1' */

          /* S-Function Block: <S290>/autosar_testpoint1 */
          AFA_noObsDoneIdlIni = AFAT_B.AFAT_F01_reinit_after_app_ada_p;

          /* SignalConversion: '<S252>/Signal1' */
          AFAT_B.AFA_noObsDone_merge_j = localAFAT_F01_reinit_after_app_;

          /* SignalConversion: '<S252>/Signal11' */
          localAFA_noAdpEfc_merge_e = AFAT_B.AFAT_F01_reinit_after_app_adapt;

          /* Event: '<S278>:53' */

          /* DataStoreRead: '<S267>/Data Store Read2' */
          for (locali = 0; locali < 8; locali++) {
            localSignalConversion5[locali] = (*Rte_Pim_AFA_prm_covNoiseVal_PIM())
              [(locali)];
          }

          /* ModelReference: '<S267>/AFAT_F06_add_adaption_noise' */
          mr_AFA_F06_add_adaption_noise(localSignalConversion5,
            localAFAT_F06_add_adaption_nois);

          /* DataStoreWrite: '<S267>/Data Store Write4' */
          for (locali = 0; locali < 8; locali++) {
            (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
              localAFAT_F06_add_adaption_nois[locali];
          }

          /* S-Function (sfun_autosar_extras_dsm_read_write): '<S380>/autosar_testpoint1' */

          /* S-Function Block: <S380>/autosar_testpoint1 */
          {
            SInt32 i1;
            const UInt16 *u0 = localSignalConversion5;
            for (i1=0; i1 < 8; i1++) {
              AFA_prm_covNoiseValPrev[i1] = u0[i1];
            }
          }
        } else {
          /* Transition: '<S278>:18' */
          if (((SInt32)AFAT_B.TmpSignalConversionAtAFAMgt_b_l) == 1) {
            /* Transition: '<S278>:20' */
            /* Exit 'WAIT': '<S278>:1' */
            AFAT_DWork.is_c10_AFAT = (UInt8)IN_NO_ACTIVE_CHILD;

            /* Event: '<S278>:62' */

            /* Outputs for enable SubSystem: '<S259>/F01_Add_patmo_reference_noise' incorporates:
             *  EnablePort: '<S301>/AFA_bFitPresAirExtPrev'
             *  SignalConversion: '<S259>/HiddenBuf_InsertedFor_F01_Add_patmo_reference_noise_at_inport_0'
             *
             * Block requirements for '<S259>/F01_Add_patmo_reference_noise':
             *  1. SubSystem "F01_Add_patmo_reference_noise" !Trace_To : VEMS_R_11_04467_021.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFA_bFitPr) {
              /* S-Function (fcncallgen): '<S301>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F02_add_patmo_reference_noise_(016_DRE)'
               *
               * Block requirements for '<S12>/F02_add_patmo_reference_noise_(016_DRE)':
               *  1. SubSystem "F02_add_patmo_reference_noise_(016_DRE)" !Trace_To : VEMS_R_11_04467_049.01 ;
               *  2. SubSystem "F02_add_patmo_reference_noise_(016_DRE)" !Trace_To : VEMS_R_11_04467_321.01 ;
               */

              /* DataStoreRead: '<S255>/Data Store Read1' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion_k[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S255>/AFAT_F02_add_patmo_reference_noise' */
              mr_AFA_F02_add_patmo_reference_(localSignalConversion_k,
                localAFAT_F02_add_patmo_referen);

              /* DataStoreWrite: '<S255>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F02_add_patmo_referen[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S299>/autosar_testpoint1' */

              /* S-Function Block: <S299>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion_k;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }

              /* Constant: '<S301>/Bool' */
              AFAT_B.AFA_bFitPresAirExt_merge_k = FALSE;
            }

            /* end of Outputs for SubSystem: '<S259>/F01_Add_patmo_reference_noise' */

            /* Outputs for enable SubSystem: '<S259>/F02_Add_throttle_reference_noise' incorporates:
             *  EnablePort: '<S302>/AFA_bFitZeroPosnThrPrev'
             *  SignalConversion: '<S259>/HiddenBuf_InsertedFor_F02_Add_throttle_reference_noise_at_inport_0'
             *
             * Block requirements for '<S259>/F02_Add_throttle_reference_noise':
             *  1. SubSystem "F02_Add_throttle_reference_noise" !Trace_To : VEMS_R_11_04467_022.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFA_bFitZe) {
              /* S-Function (fcncallgen): '<S302>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F03_add_throttle_reference_noise_(017_DRE)'
               *
               * Block requirements for '<S12>/F03_add_throttle_reference_noise_(017_DRE)':
               *  1. SubSystem "F03_add_throttle_reference_noise_(017_DRE)" !Trace_To : VEMS_R_11_04467_050.01 ;
               *  2. SubSystem "F03_add_throttle_reference_noise_(017_DRE)" !Trace_To : VEMS_R_11_04467_322.01 ;
               */

              /* DataStoreRead: '<S257>/Data Store Read2' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion1_p[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S257>/AFAT_F03_add_throttle_reference_noise' */
              mr_AFA_F03_add_throttle_referen(localSignalConversion1_p,
                localAFAT_F03_add_throttle_refe);

              /* DataStoreWrite: '<S257>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F03_add_throttle_refe[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S300>/autosar_testpoint1' */

              /* S-Function Block: <S300>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion1_p;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }

              /* Constant: '<S302>/Bool' */
              AFAT_B.AFA_bFitZeroPosnThr_merge_j = FALSE;
            }

            /* end of Outputs for SubSystem: '<S259>/F02_Add_throttle_reference_noise' */

            /* Outputs for enable SubSystem: '<S259>/F03_Add_egr_reference_noise' incorporates:
             *  EnablePort: '<S303>/AFA_bClsEGRRefPrev'
             *  SignalConversion: '<S259>/HiddenBuf_InsertedFor_F03_Add_egr_reference_noise_at_inport_0'
             *
             * Block requirements for '<S259>/F03_Add_egr_reference_noise':
             *  1. SubSystem "F03_Add_egr_reference_noise" !Trace_To : VEMS_R_11_04467_023.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFA_bClsEG) {
              /* S-Function (fcncallgen): '<S303>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F04_add_egr_reference_noise_(018_DRE)'
               *
               * Block requirements for '<S12>/F04_add_egr_reference_noise_(018_DRE)':
               *  1. SubSystem "F04_add_egr_reference_noise_(018_DRE)" !Trace_To : VEMS_R_11_04467_051.01 ;
               *  2. SubSystem "F04_add_egr_reference_noise_(018_DRE)" !Trace_To : VEMS_R_11_04467_323.01 ;
               */

              /* DataStoreRead: '<S261>/Data Store Read2' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion2[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S261>/AFAT_F04_add_egr_reference_noise' */
              mr_AFA_F04_add_egr_reference_no(localSignalConversion2,
                localAFAT_F04_add_egr_reference);

              /* DataStoreWrite: '<S261>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F04_add_egr_reference[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S307>/autosar_testpoint1' */

              /* S-Function Block: <S307>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion2;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }

              /* Constant: '<S303>/Bool' */
              AFAT_B.AFA_bClsEGRRef_merge_a = FALSE;
            }

            /* end of Outputs for SubSystem: '<S259>/F03_Add_egr_reference_noise' */

            /* Outputs for enable SubSystem: '<S259>/F04_Add_IVO_reference_noise' incorporates:
             *  EnablePort: '<S304>/AFA_bFitOpInVlvBolPrev'
             *  SignalConversion: '<S259>/HiddenBuf_InsertedFor_F04_Add_IVO_reference_noise_at_inport_0'
             *
             * Block requirements for '<S259>/F04_Add_IVO_reference_noise':
             *  1. SubSystem "F04_Add_IVO_reference_noise" !Trace_To : VEMS_R_11_04467_024.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFA_bFitOp) {
              /* S-Function (fcncallgen): '<S304>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F07_add_IVO_reference_noise_(021_DRE)'
               *
               * Block requirements for '<S12>/F07_add_IVO_reference_noise_(021_DRE)':
               *  1. SubSystem "F07_add_IVO_reference_noise_(021_DRE)" !Trace_To : VEMS_R_11_04467_054.01 ;
               *  2. SubSystem "F07_add_IVO_reference_noise_(021_DRE)" !Trace_To : VEMS_R_11_04467_326.01 ;
               */

              /* DataStoreRead: '<S269>/Data Store Read2' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion3[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S269>/AFAT_F07_add_IVO_reference_noise' */
              mr_AFA_F07_add_IVO_reference_no(localSignalConversion3,
                localAFAT_F07_add_IVO_reference);

              /* DataStoreWrite: '<S269>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F07_add_IVO_reference[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S381>/autosar_testpoint1' */

              /* S-Function Block: <S381>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion3;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }

              /* Constant: '<S304>/Bool' */
              AFAT_B.AFA_bFitOpInVlvBol_merge_g = FALSE;
            }

            /* end of Outputs for SubSystem: '<S259>/F04_Add_IVO_reference_noise' */

            /* Outputs for enable SubSystem: '<S259>/F05_Add_EVC_reference_noise' incorporates:
             *  EnablePort: '<S305>/AFA_bFitClsExVlvBolPrev'
             *  SignalConversion: '<S259>/HiddenBuf_InsertedFor_F05_Add_EVC_reference_noise_at_inport_0'
             *
             * Block requirements for '<S259>/F05_Add_EVC_reference_noise':
             *  1. SubSystem "F05_Add_EVC_reference_noise" !Trace_To : VEMS_R_11_04467_025.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFA_bFitCl) {
              /* S-Function (fcncallgen): '<S305>/Function-Call Generator' incorporates:
               *  SubSystem: '<S12>/F08_add_EVC_reference_noise_(022_DRE)'
               *
               * Block requirements for '<S12>/F08_add_EVC_reference_noise_(022_DRE)':
               *  1. SubSystem "F08_add_EVC_reference_noise_(022_DRE)" !Trace_To : VEMS_R_11_04467_055.01 ;
               *  2. SubSystem "F08_add_EVC_reference_noise_(022_DRE)" !Trace_To : VEMS_R_11_04467_327.01 ;
               */

              /* DataStoreRead: '<S271>/Data Store Read2' */
              for (locali = 0; locali < 8; locali++) {
                localSignalConversion4_k[locali] =
                  (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)];
              }

              /* ModelReference: '<S271>/AFAT_F08_add_EVC_reference_noise' */
              mr_AFA_F08_add_EVC_reference_no(localSignalConversion4_k,
                localAFAT_F08_add_EVC_reference);

              /* DataStoreWrite: '<S271>/Data Store Write4' */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F08_add_EVC_reference[locali];
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S383>/autosar_testpoint1' */

              /* S-Function Block: <S383>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localSignalConversion4_k;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValPrev[i1] = u0[i1];
                }
              }

              /* Constant: '<S305>/Bool' */
              AFAT_B.AFA_bFitClsExVlvBol_merge_d = FALSE;
            }

            /* end of Outputs for SubSystem: '<S259>/F05_Add_EVC_reference_noise' */
            /* Entry 'OBS': '<S278>:3' */
            AFAT_DWork.is_c10_AFAT = IN_OBS;
            AFA_stMonAdp = AFA_stObs_SC;
            AFA_bObsRun = TRUE;

            /* Transition: '<S278>:21' */
            /* Entry 'Pas0': '<S278>:4' */
            AFAT_DWork.is_OBS = IN_Pas0;
            AFAT_B.AFA_nEngLstObs_merge_e =
              AFAT_B.TmpSignalConversionAtExt_nEngOu;
            AFAT_B.AFA_rTotLdCorLstObs_merge_b =
              AFAT_B.TmpSignalConversionAtEngM_rTotL;

            /* Event: '<S278>:68' */

            /* ModelReference: '<S263>/AFAT_F04_command_adaptation_parameters' */
            mr_AFA_F04_command_adaptation_p
              (&AFAT_B.TmpSignalConversionAtAFA_noAdpE,
               &AFAT_B.TmpSignalConversionAtThrLrn_r_c,
               &AFAT_B.TmpSignalConversionAtInjSys_noT,
               &AFAT_B.TmpSignalConversionAtExt_nEngOu,
               &AFAT_B.TmpSignalConversionAtEngM_rTotL,
               localAFAT_F04_command_adaptatio);

            /* DataStoreWrite: '<S263>/Data Store Write4' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_bMaskSenMat_PIM())[(locali)] =
                localAFAT_F04_command_adaptatio[locali];
            }

            /* Event: '<S278>:63' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read18' */

            /* S-Function Block: <S248>/autosar_irv_read18 */
            localautosar_irv_read18 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read19' */

            /* S-Function Block: <S248>/autosar_irv_read19 */
            localautosar_irv_read19 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pExMnfEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read20' */

            /* S-Function Block: <S248>/autosar_irv_read20 */
            localautosar_irv_read20 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_nEngFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read21' */

            /* S-Function Block: <S248>/autosar_irv_read21 */
            localautosar_irv_read21 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tExMnfEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read22' */

            /* S-Function Block: <S248>/autosar_irv_read22 */
            localautosar_irv_read22 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tAirUsInVlvEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read23' */

            /* S-Function Block: <S248>/autosar_irv_read23 */
            localautosar_irv_read23 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkClsExVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read24' */

            /* S-Function Block: <S248>/autosar_irv_read24 */
            localautosar_irv_read24 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkOpInVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read25' */

            /* S-Function Block: <S248>/autosar_irv_read25 */
            localautosar_irv_read25 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rTotLdExCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read26' */

            /* S-Function Block: <S248>/autosar_irv_read26 */
            localautosar_irv_read26 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_facSlopEfcCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read28' */

            /* S-Function Block: <S248>/autosar_irv_read28 */
            localautosar_irv_read28 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffAdpThrFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read29' */

            /* S-Function Block: <S248>/autosar_irv_read29 */
            localautosar_irv_read29 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffAdpEGRVlvFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read30' */

            /* S-Function Block: <S248>/autosar_irv_read30 */
            localautosar_irv_read30 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rInMassFlowFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read31' */

            /* S-Function Block: <S248>/autosar_irv_read31 */
            localautosar_irv_read31 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rOpSIFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read32' */

            /* S-Function Block: <S248>/autosar_irv_read32 */
            localautosar_irv_read32 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_arEffEGRVlvFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read36' */

            /* S-Function Block: <S248>/autosar_irv_read36 */
            localautosar_irv_read36 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_agCkClsInVlvEstimRef1Fil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read37' */

            /* S-Function Block: <S248>/autosar_irv_read37 */
            localautosar_irv_read37 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pAirExtEstimFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read38' */

            /* S-Function Block: <S248>/autosar_irv_read38 */
            localautosar_irv_read38 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_mFuReqFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read39' */

            /* S-Function Block: <S248>/autosar_irv_read39 */
            localautosar_irv_read39 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_tCoMesFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read40' */

            /* S-Function Block: <S248>/autosar_irv_read40 */
            localautosar_irv_read40 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrPred_facVlvOvlpFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read41' */

            /* S-Function Block: <S248>/autosar_irv_read41 */
            localautosar_irv_read41 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrEstimFil_irv();

            /* DataStoreRead: '<S248>/Data Store Read4' */
            for (locali = 0; locali < 16; locali++) {
              localDataStoreRead4_f[locali] = (*Rte_Pim_AFA_prm_bMaskSenMat_PIM())
                [(locali)];
            }

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[0] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [0];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[0] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[0];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[0] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[0];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[1] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [1];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[1] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[1];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[1] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[1];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[2] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [2];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[2] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[2];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[2] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[2];

            /* DataStoreRead: '<S248>/Data Store Read1' */
            localDataStoreRead1_l[3] = (*Rte_Pim_AFA_prm_facCorGainLnrFil_PIM())
              [3];

            /* DataStoreRead: '<S248>/Data Store Read2' */
            localDataStoreRead2_m[3] = (*Rte_Pim_AFA_prm_facGainInjFil_PIM())[3];

            /* DataStoreRead: '<S248>/Data Store Read3' */
            localDataStoreRead3[3] = (*Rte_Pim_AFA_prm_pDifInjrFil_PIM())[3];

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read1' */

            /* S-Function Block: <S248>/autosar_irv_read1 */
            localautosar_irv_read1 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_nEngCorFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read2' */

            /* S-Function Block: <S248>/autosar_irv_read2 */
            localautosar_irv_read2 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_rEthStoichFil_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S248>/autosar_irv_read3' */

            /* S-Function Block: <S248>/autosar_irv_read3 */
            localautosar_irv_read3 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_facRhoFuFil_irv();

            /* ModelReference: '<S248>/AFA_F01_AFAClcObs' */
            mr_AFA_F01_AFAClcObs(&localautosar_irv_read18,
                                 &localautosar_irv_read19,
                                 &localautosar_irv_read20,
                                 &localautosar_irv_read21,
                                 &localautosar_irv_read22,
                                 &localautosar_irv_read23,
                                 &localautosar_irv_read24,
                                 &localautosar_irv_read25,
                                 &localautosar_irv_read26,
                                 &AFAT_B.TmpSignalConversionAtAFA_rAirPr,
                                 &localautosar_irv_read28,
                                 &localautosar_irv_read29,
                                 &localautosar_irv_read30,
                                 &localautosar_irv_read31,
                                 &localautosar_irv_read32,
                                 &AFAT_B.TmpSignalConversionAtAFA_rAirLd,
                                 &localautosar_irv_read36,
                                 &localautosar_irv_read37,
                                 &localautosar_irv_read38,
                                 &localautosar_irv_read39,
                                 &localautosar_irv_read40,
                                 &localautosar_irv_read41,
                                 AFAT_B.TmpSignalConversionAtInjrSys_pr,
                                 localDataStoreRead4_f, localDataStoreRead1_l,
                                 localDataStoreRead2_m, localDataStoreRead3,
                                 &localautosar_irv_read1,
                                 &localautosar_irv_read2,
                                 &localautosar_irv_read3, localAFA_F01_AFAClcObs);

            /* DataStoreWrite: '<S248>/Data Store Write13' */
            for (locali = 0; locali < 16; locali++) {
              (*Rte_Pim_AFA_prm_facSenTransMat_PIM())[(locali)] =
                localAFA_F01_AFAClcObs[locali];
            }

            /* Event: '<S278>:58' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S251>/autosar_irv_read63' */

            /* S-Function Block: <S251>/autosar_irv_read63 */
            localautosar_irv_read63 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_pDsThrEstimErrFil_irv();

            /* ModelReference: '<S251>/AFAT_F01_calc_measurement_vector' */
            mr_AFA_F01_calc_measurement_vec(&localautosar_irv_read63,
              &AFAT_B.TmpSignalConversionAtInjSys_lam,
              &AFAT_B.TmpSignalConversionAtAFA_noAdpE,
              localAFAT_F01_calc_measurement_);

            /* DataStoreWrite: '<S251>/Data Store Write' */
            (*Rte_Pim_AFA_prm_facMes_PIM())[0] =
              localAFAT_F01_calc_measurement_[0];
            (*Rte_Pim_AFA_prm_facMes_PIM())[1] =
              localAFAT_F01_calc_measurement_[1];/* Event: '<S278>:67' */

            /* SignalConversion: '<S250>/Signal1' */
            localSignal1 = AFAT_B.TmpSignalConversionAtEngM_rTotL;

            /* DataStoreRead: '<S250>/Data Store Read2' */
            for (locali = 0; locali < 9; locali++) {
              localDataStoreRead2_p[locali] = (*Rte_Pim_AFA_prm_noObsDoneMat_PIM
                ())[(locali)];
            }

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_read1' */

            /* S-Function Block: <S250>/autosar_irv_read1 */
            localSignal3 = Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv();

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_read133' */

            /* S-Function Block: <S250>/autosar_irv_read133 */
            localSignal4 = Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv();

            /* ModelReference: '<S250>/AFAT_F01_Osbservation_Number' */
            mr_AFA_F01_Osbservation_Number
              (&AFAT_B.TmpSignalConversionAtIdlSys_bAc,
               &AFAT_B.TmpSignalConversionAtExt_nEngOu, &localSignal1,
               localDataStoreRead2_p, &localSignal3,
               &AFAT_B.TmpSignalConversionAtEOM_bSpcIn, &localSignal4,
               &AFAT_B.TmpSignalConversionAtAFA_noAdpE,
               localAFAT_F01_Osbservation_Numb,
               &AFAT_B.AFAT_F01_Osbservation_Number_o2,
               &localAFAT_F01_Osbservation_Nu_b,
               &localAFAT_F01_Osbservation_Nu_f);

            /* DataStoreWrite: '<S250>/Data Store Write9' */
            for (locali = 0; locali < 9; locali++) {
              (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali)] =
                localAFAT_F01_Osbservation_Numb[locali];
            }

            /* SignalConversion: '<S250>/Signal10' */
            AFAT_B.Signal10 = localAFAT_F01_Osbservation_Nu_f;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess' */
            AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV = AFAT_B.Signal10;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess1' */
            AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV =
              AFAT_B.AFAT_F01_Osbservation_Number_o2;

            /* SignalConversion: '<S250>/Signal11' */
            AFAT_B.Signal11 = localAFAT_F01_Osbservation_Nu_b;

            /* S-Function (NvRamWriteAccess): '<S250>/EepromWriteAccess2' */
            AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV = AFAT_B.Signal11;

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_write4' */

            /* S-Function Block: <S250>/autosar_irv_write4 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv(AFAT_B.Signal10);

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S250>/autosar_irv_write40' */

            /* S-Function Block: <S250>/autosar_irv_write40 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv(AFAT_B.Signal11);

            /* SignalConversion: '<S281>/copy' */
            AFA_noObsDoneIdlPrev = localSignal3;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S281>/autosar_testpoint1' */

            /* S-Function Block: <S281>/autosar_testpoint1 */

            /* SignalConversion: '<S282>/copy' */
            AFA_noObsSpcInjModPrev = localSignal4;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S282>/autosar_testpoint1' */

            /* S-Function Block: <S282>/autosar_testpoint1 */

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S283>/autosar_testpoint1' */

            /* S-Function Block: <S283>/autosar_testpoint1 */
            AFA_noObsDoneIdlIni_IRV_MP = AFAT_B.Signal11;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S284>/autosar_testpoint1' */

            /* S-Function Block: <S284>/autosar_testpoint1 */
            AFA_noObsSpcInjMod_IRV_MP = AFAT_B.Signal10;

            /* SignalConversion: '<S250>/Signal2' */
            localAFA_bEngStopAuth_merge_i =
              AFAT_B.AFAT_F01_Osbservation_Number_o2;
            AFAT_B.AFA_noObsDone_merge_j = (UInt8)(localSignal2 + 1);
            AFAT_B.AFA_tiDlyLstObs_merge_h = 0U;
          } else {
            AFA_stMonAdp = AFA_stWait_SC;

            /* Event: '<S278>:52' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S254>/autosar_irv_read12' */

            /* S-Function Block: <S254>/autosar_irv_read12 */
            AFAT_B.autosar_irv_read12 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_bAdpClcRstReqHld_irv();

            /* DataTypeConversion Block: '<S254>/Data Type Conversion26'
             *
             * Regarding '<S254>/Data Type Conversion26':
             *   Eliminate redundant data type conversion
             */

            /* Embedded MATLAB: '<S254>/Task_sceduler' incorporates:
             *  SubSystem: '<S254>/F01_algo_reset_request1'
             *  SubSystem: '<S254>/F01_algo_reset_request2'
             *
             * Block requirements for '<S254>/F01_algo_reset_request1':
             *  1. SubSystem "F01_algo_reset_request1" !Trace_To : VEMS_R_11_04467_019.01 ;
             *
             * Block requirements for '<S254>/F01_algo_reset_request2':
             *  1. SubSystem "F01_algo_reset_request2" !Trace_To : VEMS_R_11_04467_019.01 ;
             */
            /* Embedded MATLAB Function 'AFAT/RE_AFAT_SdlSlow_AFAClcCtl_(005_TEV)/F02_Test_Algo_Reset_Rqst_(007_DRE)/Task_sceduler': '<S296>:1' */
            /* '<S296>:1:5' */

            /* SignalConversion: '<S294>/Signal Conversion1' */
            AFA_bAdpClcRstReqPrev = AFAT_B.autosar_irv_read12;

            /* If: '<S294>/If' incorporates:
             *  ActionPort: '<S297>/Action Port'
             *  Logic: '<S294>/Logical Operator'
             *  Logic: '<S294>/Logical Operator1'
             *  SubSystem: '<S294>/F01_algo_reset_request'
             *
             * Block requirements for '<S294>/F01_algo_reset_request':
             *  1. SubSystem "F01_algo_reset_request" !Trace_To : VEMS_R_11_04467_019.01 ;
             */
            if (AFAT_B.TmpSignalConversionAtAFAMgt_b_e &&
                (!AFA_bAdpClcRstReqPrev)) {
              /* S-Function (fcncallgen): '<S297>/Function-Call Generator' incorporates:
               *  SubSystem: '<S274>/F02_reinit_algo_adaptation_(005_DRE)'
               */

              /* Embedded MATLAB: '<S390>/Diag_Vect2Mat' */
              Diag_Vect2Mat((&(AFA_prm_covErrIni_C[0])), AFAT_B.y_g);

              /* DataStoreWrite: '<S390>/Data Store Write' */
              for (locali = 0; locali < 64; locali++) {
                (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)] = AFAT_B.y_g
                  [(locali)];
              }

              /* DataStoreWrite: '<S390>/Data Store Write1' incorporates:
               *  Constant: '<S390>/Constant10'
               */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_rErr_PIM())[(locali)] = AFAT_ConstP.pooled12
                  [(locali)];
              }

              /* DataStoreWrite: '<S390>/Data Store Write9' incorporates:
               *  Constant: '<S390>/Constant7'
               */
              for (locali = 0; locali < 9; locali++) {
                (*Rte_Pim_AFA_prm_noObsDoneMat_PIM())[(locali)] =
                  AFAT_ConstP.pooled14[(locali)];
              }

              /* S-Function (NvRamWriteAccess): '<S390>/EepromWriteAccess3' */
              AFAT_sNV_Z1_CONST_16BIT.AFA_noAdpEfc_NV = ((UInt16)0U);

              /* SignalConversion: '<S390>/Signal2' incorporates:
               *  Constant: '<S390>/Constant9'
               */
              localAFA_noAdpEfc_merge_e = 0U;

              /* Constant: '<S390>/Bool' */
              AFAT_B.AFA_bAuthClsCanPurg_merge_m = FALSE;

              /* S-Function (fcncallgen): '<S390>/Function-Call Generator' incorporates:
               *  SubSystem: '<S391>/F02_common_init_algo3_(003_DRE)'
               *
               * Block requirements for '<S391>/F02_common_init_algo3_(003_DRE)':
               *  1. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_010.01 ;
               *  2. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_233.01 ;
               *  3. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_290.01 ;
               *  4. SubSystem "F02_common_init_algo3_(003_DRE)" !Trace_To : VEMS_R_11_04467_308.01 ;
               */

              /* Constant: '<S404>/Constant1' */
              AFAT_B.AFA_tiDlyLstObs_merge_h = 0U;

              /* S-Function (fcncallgen): '<S404>/Function-Call Generator1' incorporates:
               *  SubSystem: '<S391>/F00_init_scruter_environ_adaptation(013_DRE)'
               *  SubSystem: '<S391>/F03_reset_cumulated_model_noise_v(032_DRE)'
               *
               * Block requirements for '<S391>/F00_init_scruter_environ_adaptation(013_DRE)':
               *  1. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_039.01 ;
               *  2. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_162.01 ;
               *  3. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_199.02 ;
               *  4. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_200.02 ;
               *  5. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_194.01 ;
               *  6. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_197.01 ;
               *  7. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_210.01 ;
               *  8. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_211.01 ;
               *  9. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_212.01 ;
               *  10. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_273.01 ;
               *  11. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_274.01 ;
               *  12. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_275.01 ;
               *  13. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_276.01 ;
               *  14. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_277.01 ;
               *  15. SubSystem "F00_init_scruter_environ_adaptation(013_DRE)" !Trace_To : VEMS_R_11_04467_318.01 ;
               *
               * Block requirements for '<S391>/F03_reset_cumulated_model_noise_v(032_DRE)':
               *  1. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_120.01 ;
               *  2. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_227.01 ;
               *  3. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_247.01 ;
               *  4. SubSystem "F03_reset_cumulated_model_noise_v(032_DRE)" !Trace_To : VEMS_R_11_04467_337.01 ;
               */

              /* DataStoreRead: '<S405>/Data Store Read' */
              for (locali = 0; locali < 64; locali++) {
                localDataStoreRead_nj[locali] =
                  (*Rte_Pim_AFA_prm_covErrEstimMat_PIM())[(locali)];
              }

              /* ModelReference: '<S405>/AFAT_F03_reset_cumulated_model_noise_v' */
              mr_AFA_F03_reset_cumulated_mode(localDataStoreRead_nj,
                AFAT_B.AFAT_F03_reset_cumulated_mode_f,
                localAFAT_F03_reset_cumulated_l);

              /* SignalConversion Block: '<S417>/copy'
               *
               * Regarding '<S417>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* DataStoreWrite: '<S405>/Data Store Write4' incorporates:
               *  SignalConversion: '<S405>/Signal Conversion1'
               */
              for (locali = 0; locali < 8; locali++) {
                (*Rte_Pim_AFA_prm_covNoiseVal_PIM())[(locali)] =
                  localAFAT_F03_reset_cumulated_l[locali];
              }

              /* S-Function (NvRamWriteAccess): '<S405>/S-Function2' */
              {
                UInt32 locali;
                for (locali=0 ; locali <8; locali++) {
                  AFAT_sNV_Z1_CALIB_16BIT.AFA_prm_covErrEstim_NV[locali] =
                    AFAT_B.AFAT_F03_reset_cumulated_mode_f[locali];
                }
              }

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S417>/autosar_testpoint1' */

              /* S-Function Block: <S417>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt16 *u0 = localAFAT_F03_reset_cumulated_l;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_covNoiseValIni[i1] = u0[i1];
                }
              }

              /* SignalConversion: '<S405>/Signal11' */
              for (locali = 0; locali < 8; locali++) {
                localAFA_prm_covErrEstim_merge_[locali] =
                  AFAT_B.AFAT_F03_reset_cumulated_mode_f[(locali)];
              }

              /* ModelReference: '<S403>/AFAT_F00_init_scruter_environ_adaptation' */
              mr_AFA_F00_init_scruter_environ
                (&AFAT_B.TmpSignalConversionAtThrLrn_r_k,
                 &AFAT_B.TmpSignalConversionAtUsThrM_p_g,
                 &AFAT_B.TmpSignalConversionAtEGRVlv_r_p,
                 AFAT_B.TmpSignalConversionAtVlvAct_p_c,
                 AFAT_B.TmpSignalConversionAtVlvAct_p_m,
                 &AFAT_B.AFA_bClsEGRRef_merge_a,
                 &AFAT_B.AFA_bFitPresAirExt_merge_k,
                 &AFAT_B.AFA_bFitZeroPosnThr_merge_j,
                 &AFAT_B.AFA_bFitOpInVlvBol_merge_g,
                 &AFAT_B.AFA_bFitClsExVlvBol_merge_d,
                 &localAFAT_F00_init_scruter_en_i,
                 &localAFAT_F00_init_scruter_en_e,
                 &localAFAT_F00_init_scruter_e_dq,
                 &localAFAT_F00_init_scruter_en_g,
                 &localAFAT_F00_init_scruter_e_g0);

              /* S-Function Block: '<S406>/FixPt Data Type Propagation'
               *
               * Regarding '<S406>/FixPt Data Type Propagation':
               *   Unused code path elimination
               */

              /* S-Function Block: '<S407>/FixPt Data Type Propagation'
               *
               * Regarding '<S407>/FixPt Data Type Propagation':
               *   Unused code path elimination
               */

              /* S-Function Block: '<S408>/FixPt Data Type Propagation'
               *
               * Regarding '<S408>/FixPt Data Type Propagation':
               *   Unused code path elimination
               */

              /* S-Function Block: '<S409>/FixPt Data Type Propagation'
               *
               * Regarding '<S409>/FixPt Data Type Propagation':
               *   Unused code path elimination
               */

              /* S-Function Block: '<S410>/FixPt Data Type Propagation'
               *
               * Regarding '<S410>/FixPt Data Type Propagation':
               *   Unused code path elimination
               */

              /* DataTypeConversion Block: '<S406>/FixPt Gateway Out'
               *
               * Regarding '<S406>/FixPt Gateway Out':
               *   Eliminate redundant data type conversion
               */

              /* DataTypeConversion Block: '<S407>/FixPt Gateway Out'
               *
               * Regarding '<S407>/FixPt Gateway Out':
               *   Eliminate redundant data type conversion
               */

              /* DataTypeConversion Block: '<S408>/FixPt Gateway Out'
               *
               * Regarding '<S408>/FixPt Gateway Out':
               *   Eliminate redundant data type conversion
               */

              /* DataTypeConversion Block: '<S409>/FixPt Gateway Out'
               *
               * Regarding '<S409>/FixPt Gateway Out':
               *   Eliminate redundant data type conversion
               */

              /* DataTypeConversion Block: '<S410>/FixPt Gateway Out'
               *
               * Regarding '<S410>/FixPt Gateway Out':
               *   Eliminate redundant data type conversion
               */

              /* SignalConversion Block: '<S411>/copy'
               *
               * Regarding '<S411>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* SignalConversion Block: '<S412>/copy'
               *
               * Regarding '<S412>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* SignalConversion Block: '<S413>/copy'
               *
               * Regarding '<S413>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* SignalConversion Block: '<S414>/copy'
               *
               * Regarding '<S414>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* SignalConversion Block: '<S415>/copy'
               *
               * Regarding '<S415>/copy':
               *   Eliminate redundant signal conversion block
               */

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S403>/autosar_irv_write10' */

              /* S-Function Block: <S403>/autosar_irv_write10 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_pAirExtEstimHld_irv
                (localAFAT_F00_init_scruter_en_e);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S403>/autosar_irv_write11' */

              /* S-Function Block: <S403>/autosar_irv_write11 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_rOpClsEGRVlvBolHld_irv
                (localAFAT_F00_init_scruter_e_dq);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S403>/autosar_irv_write12' */

              /* S-Function Block: <S403>/autosar_irv_write12 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_agCkOpInVlvBolHld_irv
                (localAFAT_F00_init_scruter_en_g);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S403>/autosar_irv_write13' */

              /* S-Function Block: <S403>/autosar_irv_write13 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_agCkClsExVlvBolHld_irv
                (localAFAT_F00_init_scruter_e_g0);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S403>/autosar_irv_write9' */

              /* S-Function Block: <S403>/autosar_irv_write9 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_rOpClsThrBolHld_irv
                (localAFAT_F00_init_scruter_en_i);

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S411>/autosar_testpoint1' */

              /* S-Function Block: <S411>/autosar_testpoint1 */
              AFA_rOpClsThrBolHld_IRV_MP = localAFAT_F00_init_scruter_en_i;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S412>/autosar_testpoint1' */

              /* S-Function Block: <S412>/autosar_testpoint1 */
              AFA_pAirExtEstimHld_IRV_MP = localAFAT_F00_init_scruter_en_e;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S413>/autosar_testpoint1' */

              /* S-Function Block: <S413>/autosar_testpoint1 */
              AFA_rOpClsEGRVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_e_dq;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S414>/autosar_testpoint1' */

              /* S-Function Block: <S414>/autosar_testpoint1 */
              AFA_agCkOpInVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_en_g;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S415>/autosar_testpoint1' */

              /* S-Function Block: <S415>/autosar_testpoint1 */
              AFA_agCkClsExVlvBolHld_IRV_MP = localAFAT_F00_init_scruter_e_g0;

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S404>/autosar_irv_write162' incorporates:
               *  Constant: '<S404>/Constant2'
               */

              /* S-Function Block: <S404>/autosar_irv_write162 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsInnovNotCoh_irv(((UInt8)0U));

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S416>/autosar_testpoint1' incorporates:
               *  Constant: '<S404>/Constant2'
               */

              /* S-Function Block: <S416>/autosar_testpoint1 */
              AFA_noObsInnovNotCoh_IRV_MP = ((UInt8)0U);

              /* S-Function (NvRamWriteAccess): '<S390>/S-Function2' */
              AFAT_sNV_Z1_CONST_BOOLEAN.AFA_bAcvSpcInjMod_NV =
                AFA_bAcvSpcInjModIni_C;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S402>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/AFA_bAcvSpcInjModIni_C'
               */

              /* S-Function Block: <S402>/autosar_testpoint1 */
              AFA_bAcvSpcInjModIni = AFA_bAcvSpcInjModIni_C;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S394>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant2'
               */

              /* S-Function Block: <S394>/autosar_testpoint1 */
              AFA_noObsDoneIni = ((UInt8)0U);

              /* SignalConversion: '<S390>/Signal3' incorporates:
               *  Constant: '<S390>/Constant2'
               */
              AFAT_B.AFA_noObsDone_merge_j = 0U;

              /* SignalConversion: '<S390>/Signal Conversion' */
              localSignalConversion_g0 = AFAT_B.TmpSignalConversionAtAFA_noAdpC;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S399>/autosar_testpoint1' */

              /* S-Function Block: <S399>/autosar_testpoint1 */
              AFA_noAdpClcRstPrev = localSignalConversion_g0;

              /* Sum: '<S390>/Subtract' incorporates:
               *  Constant: '<S390>/Constant4'
               */
              locali = localSignalConversion_g0 + 1;
              if (((UInt32)locali) > 255U) {
                localAFA_noAdpClcRst_merge_o = MAX_uint8_T;
              } else {
                localAFA_noAdpClcRst_merge_o = (UInt8)locali;
              }

              /* S-Function (NvRamWriteAccess): '<S390>/EepromWriteAccess2' */
              AFAT_sNV_Z1_CALIB_BOOLEAN.AFA_bEngStopAuth_NV =
                AFA_bEngStopAuthIni_C;

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S401>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/AFA_bEngStopAuthIni_C'
               */

              /* S-Function Block: <S401>/autosar_testpoint1 */
              AFA_bEngStopAuthIni = AFA_bEngStopAuthIni_C;

              /* SignalConversion: '<S390>/Signal1' incorporates:
               *  Constant: '<S390>/AFA_bEngStopAuthIni_C'
               */
              localAFA_bEngStopAuth_merge_i = AFA_bEngStopAuthIni_C;

              /* S-Function (NvRamWriteAccess): '<S390>/S-Function1' */
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[0] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[1] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[2] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[3] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[4] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[5] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[6] = (0);
              AFAT_sNV_Z1_CONST_16BIT.AFA_prm_rErr_NV[7] = (0);

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S398>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant10'
               */

              /* S-Function Block: <S398>/autosar_testpoint1 */
              {
                SInt32 i1;
                const SInt16 *u0 = AFAT_ConstP.pooled12;
                for (i1=0; i1 < 8; i1++) {
                  AFA_prm_rErrIni[i1] = u0[i1];
                }
              }

              /* S-Function (NvRamWriteAccess): '<S390>/EepromWriteAccess1' */
              AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDoneIdl_NV = ((UInt8)0U);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S390>/autosar_irv_write32' incorporates:
               *  Constant: '<S390>/Constant5'
               */

              /* S-Function Block: <S390>/autosar_irv_write32 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsDoneIdlIni_irv(((UInt8)0U));

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S395>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant5'
               */

              /* S-Function Block: <S395>/autosar_testpoint1 */
              AFA_noObsDoneIdlIni_IRV_MP = ((UInt8)0U);

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S397>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant5'
               */

              /* S-Function Block: <S397>/autosar_testpoint1 */
              AFA_noObsDoneIdlIni = ((UInt8)0U);

              /* S-Function (NvRamWriteAccess): '<S390>/EepromWriteAccess' */
              AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV = ((UInt8)0U);

              /* S-Function (sfun_autosar_extras_irv_read_write): '<S390>/autosar_irv_write1' incorporates:
               *  Constant: '<S390>/Constant6'
               */

              /* S-Function Block: <S390>/autosar_irv_write1 */
              Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv(((UInt8)0U));

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S393>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant6'
               */

              /* S-Function Block: <S393>/autosar_testpoint1 */
              AFA_noObsSpcInjMod_IRV_MP = ((UInt8)0U);

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S396>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant6'
               */

              /* S-Function Block: <S396>/autosar_testpoint1 */
              AFA_noObsSpcInjModIni = ((UInt8)0U);

              /* S-Function (sfun_autosar_extras_dsm_read_write): '<S400>/autosar_testpoint1' incorporates:
               *  Constant: '<S390>/Constant7'
               */

              /* S-Function Block: <S400>/autosar_testpoint1 */
              {
                SInt32 i1;
                const UInt8 *u0 = AFAT_ConstP.pooled14;
                for (i1=0; i1 < 9; i1++) {
                  AFA_prm_noObsDoneMatIni[i1] = u0[i1];
                }
              }
            }

            /* '<S296>:1:7' */

            /* SignalConversion: '<S295>/Signal Conversion' */
            localSignalConversion_ks = AFAT_B.TmpSignalConversionAtAFAMgt_b_e;

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S298>/autosar_testpoint1' */

            /* S-Function Block: <S298>/autosar_testpoint1 */
            AFA_bAdpClcRstReqHld_IRV_MP = localSignalConversion_ks;

            /* SignalConversion: '<S295>/Signal Conversion2' */
            AFAT_B.SignalConversion2 = localSignalConversion_ks;

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S254>/autosar_irv_write42' */

            /* S-Function Block: <S254>/autosar_irv_write42 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_bAdpClcRstReqHld_irv
              (AFAT_B.SignalConversion2);

            /* Event: '<S278>:69' */

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S253>/autosar_irv_read134' */

            /* S-Function Block: <S253>/autosar_irv_read134 */
            localautosar_irv_read134 =
              Rte_IrvRead_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv();

            /* DataTypeConversion Block: '<S253>/Data Type Conversion31'
             *
             * Regarding '<S253>/Data Type Conversion31':
             *   Eliminate redundant data type conversion
             */

            /* UnitDelay: '<S292>/Unit Delay' */
            AFA_tiAcvSpcInjModPrev = AFAT_DWork.UnitDelay_DSTATE;

            /* ModelReference: '<S253>/AFA_F02_Activation_EOM_Mode'
             *
             * Block requirements for '<S253>/AFA_F02_Activation_EOM_Mode':
             *  1. ModelReference "AFA_F02_Activation_EOM_Mode" !Trace_To : VEMS_R_11_04467_033.01 ;
             */
            mr_AFA_F02_Activation_EOM_Mode(&localautosar_irv_read134,
              &AFAT_B.TmpSignalConversionAtAFA_noAdpE,
              &AFAT_B.TmpSignalConversionAtAFAMgt_bId,
              &AFAT_B.TmpSignalConversionAtAFAMgt_b_p, &AFA_tiAcvSpcInjModPrev,
              &localAFA_F02_Activation_EOM_Mod,
              &AFAT_B.AFA_F02_Activation_EOM_Mode_o2, &AFA_tiAcvSpcInjMod);

            /* SignalConversion: '<S253>/Signal9' */
            AFAT_B.Signal9_d = localAFA_F02_Activation_EOM_Mod;

            /* S-Function (NvRamWriteAccess): '<S253>/EepromWriteAccess' */
            AFAT_sNV_Z1_CONST_8BIT.AFA_noObsSpcInjMod_NV = AFAT_B.Signal9_d;

            /* S-Function (NvRamWriteAccess): '<S253>/S-Function3' */
            AFAT_sNV_Z1_CONST_BOOLEAN.AFA_bAcvSpcInjMod_NV =
              AFAT_B.AFA_F02_Activation_EOM_Mode_o2;

            /* S-Function (sfun_autosar_extras_irv_read_write): '<S253>/autosar_irv_write5' */

            /* S-Function Block: <S253>/autosar_irv_write5 */
            Rte_IrvWrite_RE_AFAT_005_TEV_AFA_noObsSpcInjMod_irv(AFAT_B.Signal9_d);

            /* S-Function (sfun_autosar_extras_dsm_read_write): '<S293>/autosar_testpoint1' */

            /* S-Function Block: <S293>/autosar_testpoint1 */
            AFA_noObsSpcInjMod_IRV_MP = AFAT_B.Signal9_d;

            /* SignalConversion: '<S253>/Signal11' */
            localAFA_bAcvSpcInjMod_merge_m =
              AFAT_B.AFA_F02_Activation_EOM_Mode_o2;

            /* Update for UnitDelay: '<S292>/Unit Delay' */
            AFAT_DWork.UnitDelay_DSTATE = AFA_tiAcvSpcInjMod;
          }
        }
        break;

       default:
        /* Transition: '<S278>:13' */
        /* Entry 'WAIT': '<S278>:1' */
        AFAT_DWork.is_c10_AFAT = IN_WAIT;
        break;
      }
    }
  }

  /* S-Function (NvRamWriteAccess): '<S12>/EepromWriteAccess3' */
  AFAT_sNV_Z1_CONST_8BIT.AFA_noObsDone_NV = AFAT_B.AFA_noObsDone_merge_j;

  /* Switch: '<S219>/Switch' incorporates:
   *  Constant: '<S219>/Byp_Fonction_SC'
   *  Constant: '<S219>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_agCkClsExVlvOfs_merge_ = AFA_agCkClsExVlvOfs_B;
  }

  /* Switch: '<S220>/Switch' incorporates:
   *  Constant: '<S220>/Byp_Fonction_SC'
   *  Constant: '<S220>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_agCkOpInVlvOfs_merge_k = AFA_agCkOpInVlvOfs_B;
  }

  /* Switch: '<S221>/Switch' incorporates:
   *  Constant: '<S221>/Byp_Fonction_SC'
   *  Constant: '<S221>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hu = AFA_arEffEGRVlvOfs_B;
  } else {
    localSwitch_hu = AFAT_B.AFA_arEffEGRVlvOfs_merge_j;
  }

  /* Switch: '<S222>/Switch' incorporates:
   *  Constant: '<S222>/Byp_Fonction_SC'
   *  Constant: '<S222>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_arEffThrOfs_merge_h = AFA_arEffThrOfs_B;
  }

  /* Switch: '<S223>/Switch' incorporates:
   *  Constant: '<S223>/Byp_Fonction_SC'
   *  Constant: '<S223>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bAcvSpcInjMod_merge_m = AFA_bAcvSpcInjMod_B;
  }

  /* Switch: '<S224>/Switch' incorporates:
   *  Constant: '<S224>/Byp_Fonction_SC'
   *  Constant: '<S224>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hq = AFA_bAuthClsCanPurg_B;
  } else {
    localSwitch_hq = AFAT_B.AFA_bAuthClsCanPurg_merge_m;
  }

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Byp_Fonction_SC'
   *  Constant: '<S225>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_le = AFA_bClsEGRRef_B;
  } else {
    localSwitch_le = AFAT_B.AFA_bClsEGRRef_merge_a;
  }

  /* Switch: '<S226>/Switch' incorporates:
   *  Constant: '<S226>/Byp_Fonction_SC'
   *  Constant: '<S226>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bEngStopAuth_merge_i = AFA_bEngStopAuth_B;
  }

  /* Switch: '<S227>/Switch' incorporates:
   *  Constant: '<S227>/Byp_Fonction_SC'
   *  Constant: '<S227>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_ga = AFA_bFitClsExVlvBol_B;
  } else {
    localSwitch_ga = AFAT_B.AFA_bFitClsExVlvBol_merge_d;
  }

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Byp_Fonction_SC'
   *  Constant: '<S228>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_gax = AFA_bFitOpInVlvBol_B;
  } else {
    localSwitch_gax = AFAT_B.AFA_bFitOpInVlvBol_merge_g;
  }

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Byp_Fonction_SC'
   *  Constant: '<S229>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_gt = AFA_bFitPresAirExt_B;
  } else {
    localSwitch_gt = AFAT_B.AFA_bFitPresAirExt_merge_k;
  }

  /* Switch: '<S230>/Switch' incorporates:
   *  Constant: '<S230>/Byp_Fonction_SC'
   *  Constant: '<S230>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_lm = AFA_bFitZeroPosnThr_B;
  } else {
    localSwitch_lm = AFAT_B.AFA_bFitZeroPosnThr_merge_j;
  }

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/Byp_Fonction_SC'
   *  Constant: '<S231>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localLogicalOperator1 = AFA_bIdcCohLstObs_B;
  }

  /* Switch: '<S232>/Switch' incorporates:
   *  Constant: '<S232>/Byp_Fonction_SC'
   *  Constant: '<S232>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_bInnovTestCohDone_merg = AFA_bInnovTestCohDone_B;
  }

  /* Switch: '<S233>/Switch' incorporates:
   *  Constant: '<S233>/Byp_Fonction_SC'
   *  Constant: '<S233>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_facArEffThrOfs1_merge_ = AFA_facArEffThrOfs1_B;
  }

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Byp_Fonction_SC'
   *  Constant: '<S234>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_facArEffThrOfs2_merge_ = AFA_facArEffThrOfs2_B;
  }

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Byp_Fonction_SC'
   *  Constant: '<S235>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_facArEffThrOfs3_merge_ = AFA_facArEffThrOfs3_B;
  }

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Byp_Fonction_SC'
   *  Constant: '<S236>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_facIvsInjGain_merge_k = AFA_facIvsInjGain_B;
  }

  /* Switch: '<S237>/Switch' incorporates:
   *  Constant: '<S237>/Byp_Fonction_SC'
   *  Constant: '<S237>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_facSlopInjGain_merge_m = AFA_facSlopInjGain_B;
  }

  /* Switch: '<S238>/Switch' incorporates:
   *  Constant: '<S238>/Byp_Fonction_SC'
   *  Constant: '<S238>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    locallocalDataStoreRead1_b_idx = AFA_nEngLstObs_B;
  } else {
    locallocalDataStoreRead1_b_idx = AFAT_B.AFA_nEngLstObs_merge_e;
  }

  /* Switch: '<S239>/Switch' incorporates:
   *  Constant: '<S239>/Byp_Fonction_SC'
   *  Constant: '<S239>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noAdpClcRst_merge_o = AFA_noAdpClcRst_B;
  }

  /* Switch: '<S240>/Switch' incorporates:
   *  Constant: '<S240>/Byp_Fonction_SC'
   *  Constant: '<S240>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    locallocalDataStoreRead1_b_id_0 = AFA_noAdpEfcAst_B;
  } else {
    locallocalDataStoreRead1_b_id_0 = AFAT_B.AFA_noAdpEfcAst_merge_l;
  }

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/Byp_Fonction_SC'
   *  Constant: '<S241>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_noAdpEfc_merge_e = AFA_noAdpEfc_B;
  }

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Byp_Fonction_SC'
   *  Constant: '<S242>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSignal2 = AFA_noObsDone_B;
  } else {
    localSignal2 = AFAT_B.AFA_noObsDone_merge_j;
  }

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S243>/Byp_Fonction_SC'
   *  Constant: '<S243>/Int_BypC'
   */
  for (locali = 0; locali < 8; locali++) {
    if (AFAT_ACTIVE_BYP_C) {
      localAFA_prm_covErrEstim_merge_[locali] = AFA_prm_covErrEstim_B[(locali)];
    }
  }

  /* Switch: '<S244>/Switch' incorporates:
   *  Constant: '<S244>/Byp_Fonction_SC'
   *  Constant: '<S244>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_rCor_arEffEGRVlv_merge = AFA_rCor_arEffEGRVlv_B;
  }

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S245>/Byp_Fonction_SC'
   *  Constant: '<S245>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_bm = AFA_rTotLdCorLstObs_B;
  } else {
    localSwitch_bm = AFAT_B.AFA_rTotLdCorLstObs_merge_b;
  }

  /* Switch: '<S246>/Switch' incorporates:
   *  Constant: '<S246>/Byp_Fonction_SC'
   *  Constant: '<S246>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localSwitch_hm = AFA_tiDlyLstObs_B;
  } else {
    localSwitch_hm = AFAT_B.AFA_tiDlyLstObs_merge_h;
  }

  /* Switch: '<S247>/Switch' incorporates:
   *  Constant: '<S247>/Byp_Fonction_SC'
   *  Constant: '<S247>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localAFA_tiOffInj_merge_i = AFA_tiOffInj_B;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_agCkClsExVlvOfsInport2' */
  Rte_Write_P_AFA_agCkClsExVlvOfs_AFA_agCkClsExVlvOfs
    (localAFA_agCkClsExVlvOfs_merge_);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_agCkOpInVlvOfsInport2' */
  Rte_Write_P_AFA_agCkOpInVlvOfs_AFA_agCkOpInVlvOfs
    (localAFA_agCkOpInVlvOfs_merge_k);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_arEffEGRVlvOfsInport2' */
  Rte_Write_P_AFA_arEffEGRVlvOfs_AFA_arEffEGRVlvOfs(localSwitch_hu);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_arEffThrOfsInport2' */
  Rte_Write_P_AFA_arEffThrOfs_AFA_arEffThrOfs(localAFA_arEffThrOfs_merge_h);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bAcvSpcInjModInport2' */
  Rte_Write_P_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod(localAFA_bAcvSpcInjMod_merge_m);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bAuthClsCanPurgInport2' */
  Rte_Write_P_AFA_bAuthClsCanPurg_AFA_bAuthClsCanPurg(localSwitch_hq);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bClsEGRRefInport2' */
  Rte_Write_P_AFA_bClsEGRRef_AFA_bClsEGRRef(localSwitch_le);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bEngStopAuthInport2' */
  Rte_Write_P_AFA_bEngStopAuth_AFA_bEngStopAuth(localAFA_bEngStopAuth_merge_i);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitClsExVlvBolInport2' */
  Rte_Write_P_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol(localSwitch_ga);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitOpInVlvBolInport2' */
  Rte_Write_P_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol(localSwitch_gax);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitPresAirExtInport2' */
  Rte_Write_P_AFA_bFitPresAirExt_AFA_bFitPresAirExt(localSwitch_gt);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bFitZeroPosnThrInport2' */
  Rte_Write_P_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr(localSwitch_lm);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bIdcCohLstObsInport2' */
  Rte_Write_P_AFA_bIdcCohLstObs_AFA_bIdcCohLstObs(localLogicalOperator1);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_bInnovTestCohDoneInport2' */
  Rte_Write_P_AFA_bInnovTestCohDone_AFA_bInnovTestCohDone
    (localAFA_bInnovTestCohDone_merg);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs1Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs1_AFA_facArEffThrOfs1
    (localAFA_facArEffThrOfs1_merge_);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs2Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs2_AFA_facArEffThrOfs2
    (localAFA_facArEffThrOfs2_merge_);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facArEffThrOfs3Inport2' */
  Rte_Write_P_AFA_facArEffThrOfs3_AFA_facArEffThrOfs3
    (localAFA_facArEffThrOfs3_merge_);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facIvsInjGainInport2' */
  Rte_Write_P_AFA_facIvsInjGain_AFA_facIvsInjGain(localAFA_facIvsInjGain_merge_k);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_facSlopInjGainInport2' */
  Rte_Write_P_AFA_facSlopInjGain_AFA_facSlopInjGain
    (localAFA_facSlopInjGain_merge_m);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_nEngLstObsInport2' */
  Rte_Write_P_AFA_nEngLstObs_AFA_nEngLstObs(locallocalDataStoreRead1_b_idx);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpClcRstInport2' */
  Rte_Write_P_AFA_noAdpClcRst_AFA_noAdpClcRst(localAFA_noAdpClcRst_merge_o);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpEfcAstInport2' */
  Rte_Write_P_AFA_noAdpEfcAst_AFA_noAdpEfcAst(locallocalDataStoreRead1_b_id_0);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noAdpEfcInport2' */
  Rte_Write_P_AFA_noAdpEfc_AFA_noAdpEfc(localAFA_noAdpEfc_merge_e);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_noObsDoneInport2' */
  Rte_Write_P_AFA_noObsDone_AFA_noObsDone(localSignal2);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_prm_covErrEstimInport2' */
  Rte_Write_P_AFA_prm_covErrEstim_AFA_prm_covErrEstim
    (&localAFA_prm_covErrEstim_merge_);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rCor_arEffEGRVlvInport2' */
  Rte_Write_P_AFA_rCor_arEffEGRVlv_AFA_rCor_arEffEGRVlv
    (localAFA_rCor_arEffEGRVlv_merge);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_rTotLdCorLstObsInport2' */
  Rte_Write_P_AFA_rTotLdCorLstObs_AFA_rTotLdCorLstObs(localSwitch_bm);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_tiDlyLstObsInport2' */
  Rte_Write_P_AFA_tiDlyLstObs_AFA_tiDlyLstObs(localSwitch_hm);

  /* SignalConversion: '<S12>/TmpSignal ConversionAtAFA_tiOffInjInport2' */
  Rte_Write_P_AFA_tiOffInj_AFA_tiOffInj(localAFA_tiOffInj_merge_i);
}

/* Start for exported function: RE_AFAT_007_TEV */
void RE_AFAT_007_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcMonEnv_(007_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcMonEnv_(007_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_135.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_136.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_162.01 ;
   *  4. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_199.02 ;
   *  5. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_200.02 ;
   *  6. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_194.01 ;
   *  7. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_197.01 ;
   *  8. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  9. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_211.01 ;
   *  10. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_212.01 ;
   *  11. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  12. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  13. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  14. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  15. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  16. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_319.01 ;
   */
}

/* Output and update for exported function: RE_AFAT_007_TEV */
void RE_AFAT_007_TEV(void)
{
  /* local block i/o variables */
  UInt16 localautosar_irv_read42;
  UInt16 localautosar_irv_read1_m;
  UInt16 localautosar_irv_read2_m;
  UInt16 localautosar_irv_read3_a;
  UInt16 localautosar_irv_read4;
  UInt16 localSignalConversion2_f;
  UInt16 localAFAT_F01_scruter_environ_a;
  UInt16 localSignalConversion1_l;
  UInt16 localSignalConversion3_d;
  UInt16 localAFAT_F01_scruter_environ_i;
  UInt16 localAFAT_F01_scruter_environ_k;
  UInt16 localSignalConversion4_j;
  UInt16 localSignalConversion5_o;
  UInt16 localAFAT_F01_scruter_environ_e;
  UInt16 localAFAT_F01_scruter_environ_b;
  Boolean localSignalConversion10;
  Boolean localSignalConversion6_k;
  Boolean localSignalConversion7;
  Boolean localSignalConversion8;
  Boolean localSignalConversion9;
  Boolean localAFAT_F01_scruter_environ_d;
  Boolean localAFAT_F01_scruter_enviro_at;
  Boolean localAFAT_F01_scruter_environ_l;
  Boolean localAFAT_F01_scruter_environ_f;
  Boolean localAFAT_F01_scruter_environ_h;
  Boolean localTmpSignalConversionAtAFA_b;
  Boolean localTmpSignalConversionAtAFA_h;
  Boolean localTmpSignalConversionAtAFA_l;
  Boolean localTmpSignalConversionAtAFA_n;
  Boolean localTmpSignalConversionAtAFA_i;

  /* S-Function (fcncallgen): '<S7>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcMonEnv_(007_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcMonEnv_(007_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_135.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_136.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_162.01 ;
   *  4. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_199.02 ;
   *  5. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_200.02 ;
   *  6. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_194.01 ;
   *  7. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_197.01 ;
   *  8. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_210.01 ;
   *  9. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_211.01 ;
   *  10. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_212.01 ;
   *  11. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_273.01 ;
   *  12. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_274.01 ;
   *  13. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_275.01 ;
   *  14. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_276.01 ;
   *  15. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_277.01 ;
   *  16. SubSystem "RE_AFAT_SdlSlow_AFAClcMonEnv_(014_TEV)" !Trace_To : VEMS_R_11_04467_319.01 ;
   */

  /* SignalConversion: '<S13>/TmpSignal ConversionAtThrLrn_rOpClsThrBolOutport2' incorporates:
   *  Inport: '<Root>/ThrLrn_rOpClsThrBol'
   */
  Rte_Read_R_ThrLrn_rOpClsThrBol_ThrLrn_rOpClsThrBol
    (&AFAT_B.TmpSignalConversionAtThrLrn_rOp);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtUsThrM_pAirExtEstimOutport2' incorporates:
   *  Inport: '<Root>/UsThrM_pAirExtEstim'
   */
  Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim
    (&AFAT_B.TmpSignalConversionAtUsThrM_pAi);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtEGRVlv_rOpClsEGRVlvBolOutport2' incorporates:
   *  Inport: '<Root>/EGRVlv_rOpClsEGRVlvBol'
   */
  Rte_Read_R_EGRVlv_rOpClsEGRVlvBol_EGRVlv_rOpClsEGRVlvBol
    (&AFAT_B.TmpSignalConversionAtEGRVlv_rOp);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtVlvAct_prm_agCkOpInVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkOpInVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkOpInVlvBol_VlvAct_prm_agCkOpInVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_prm);

  /* SignalConversion: '<S13>/TmpSignal ConversionAtVlvAct_prm_agCkClsExVlvBolOutport2' incorporates:
   *  Inport: '<Root>/VlvAct_prm_agCkClsExVlvBol'
   */
  Rte_Read_R_VlvAct_prm_agCkClsExVlvBol_VlvAct_prm_agCkClsExVlvBol
    (&AFAT_B.TmpSignalConversionAtVlvAct_p_b);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read42' */

  /* S-Function Block: <S13>/autosar_irv_read42 */
  localautosar_irv_read42 = Rte_IrvRead_RE_AFAT_007_TEV_AFA_rOpClsThrBolHld_irv();

  /* DataTypeConversion Block: '<S13>/Data Type Conversion85'
   *
   * Regarding '<S13>/Data Type Conversion85':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S13>/Signal Conversion1' */
  localSignalConversion1_l = localautosar_irv_read42;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read1' */

  /* S-Function Block: <S13>/autosar_irv_read1 */
  localautosar_irv_read1_m = Rte_IrvRead_RE_AFAT_007_TEV_AFA_pAirExtEstimHld_irv
    ();

  /* DataTypeConversion Block: '<S13>/Data Type Conversion1'
   *
   * Regarding '<S13>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S13>/Signal Conversion2' */
  localSignalConversion2_f = localautosar_irv_read1_m;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read2' */

  /* S-Function Block: <S13>/autosar_irv_read2 */
  localautosar_irv_read2_m =
    Rte_IrvRead_RE_AFAT_007_TEV_AFA_rOpClsEGRVlvBolHld_irv();

  /* DataTypeConversion Block: '<S13>/Data Type Conversion2'
   *
   * Regarding '<S13>/Data Type Conversion2':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S13>/Signal Conversion3' */
  localSignalConversion3_d = localautosar_irv_read2_m;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read3' */

  /* S-Function Block: <S13>/autosar_irv_read3 */
  localautosar_irv_read3_a =
    Rte_IrvRead_RE_AFAT_007_TEV_AFA_agCkOpInVlvBolHld_irv();

  /* DataTypeConversion Block: '<S13>/Data Type Conversion3'
   *
   * Regarding '<S13>/Data Type Conversion3':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S13>/Signal Conversion4' */
  localSignalConversion4_j = localautosar_irv_read3_a;

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_read4' */

  /* S-Function Block: <S13>/autosar_irv_read4 */
  localautosar_irv_read4 =
    Rte_IrvRead_RE_AFAT_007_TEV_AFA_agCkClsExVlvBolHld_irv();

  /* DataTypeConversion Block: '<S13>/Data Type Conversion4'
   *
   * Regarding '<S13>/Data Type Conversion4':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion: '<S13>/Signal Conversion5' */
  localSignalConversion5_o = localautosar_irv_read4;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitPresAirExt_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitPresAirExt_INPUT'
   */
  Rte_Read_R_AFA_bFitPresAirExt_AFA_bFitPresAirExt
    (&localTmpSignalConversionAtAFA_b);

  /* SignalConversion: '<S13>/Signal Conversion10' */
  localSignalConversion10 = localTmpSignalConversionAtAFA_b;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitZeroPosnThr_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitZeroPosnThr_INPUT'
   */
  Rte_Read_R_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr
    (&localTmpSignalConversionAtAFA_h);

  /* SignalConversion: '<S13>/Signal Conversion6' */
  localSignalConversion6_k = localTmpSignalConversionAtAFA_h;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bClsEGRRef_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bClsEGRRef_INPUT'
   */
  Rte_Read_R_AFA_bClsEGRRef_AFA_bClsEGRRef(&localTmpSignalConversionAtAFA_l);

  /* SignalConversion: '<S13>/Signal Conversion7' */
  localSignalConversion7 = localTmpSignalConversionAtAFA_l;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitOpInVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitOpInVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol
    (&localTmpSignalConversionAtAFA_n);

  /* SignalConversion: '<S13>/Signal Conversion8' */
  localSignalConversion8 = localTmpSignalConversionAtAFA_n;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitClsExVlvBol_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_bFitClsExVlvBol_INPUT'
   */
  Rte_Read_R_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol
    (&localTmpSignalConversionAtAFA_i);

  /* SignalConversion: '<S13>/Signal Conversion9' */
  localSignalConversion9 = localTmpSignalConversionAtAFA_i;

  /* Outputs for atomic SubSystem: '<S13>/F01_scruter_environ_adaptation' *
   * Block requirements for '<S13>/F01_scruter_environ_adaptation':
   *  1. SubSystem "F01_scruter_environ_adaptation" !Trace_To : VEMS_R_11_04467_040.01 ;
   */

  /* ModelReference: '<S423>/AFAT_F01_scruter_environ_adaptation' */
  mr_AFA_F01_scruter_environ_adap(&AFAT_B.TmpSignalConversionAtThrLrn_rOp,
    &AFAT_B.TmpSignalConversionAtUsThrM_pAi,
    &AFAT_B.TmpSignalConversionAtEGRVlv_rOp,
    AFAT_B.TmpSignalConversionAtVlvAct_prm,
    AFAT_B.TmpSignalConversionAtVlvAct_p_b, &localSignalConversion1_l,
    &localSignalConversion2_f, &localSignalConversion3_d,
    &localSignalConversion4_j, &localSignalConversion5_o,
    &localSignalConversion10, &localSignalConversion6_k, &localSignalConversion7,
    &localSignalConversion8, &localSignalConversion9,
    &localAFAT_F01_scruter_environ_d, &localAFAT_F01_scruter_enviro_at,
    &localAFAT_F01_scruter_environ_l, &localAFAT_F01_scruter_environ_f,
    &localAFAT_F01_scruter_environ_h, &localAFAT_F01_scruter_environ_i,
    &localAFAT_F01_scruter_environ_a, &localAFAT_F01_scruter_environ_k,
    &localAFAT_F01_scruter_environ_e, &localAFAT_F01_scruter_environ_b);

  /* S-Function Block: '<S418>/FixPt Data Type Propagation'
   *
   * Regarding '<S418>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S419>/FixPt Data Type Propagation'
   *
   * Regarding '<S419>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S420>/FixPt Data Type Propagation'
   *
   * Regarding '<S420>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S421>/FixPt Data Type Propagation'
   *
   * Regarding '<S421>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S422>/FixPt Data Type Propagation'
   *
   * Regarding '<S422>/FixPt Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S418>/FixPt Gateway Out'
   *
   * Regarding '<S418>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S419>/FixPt Gateway Out'
   *
   * Regarding '<S419>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S420>/FixPt Gateway Out'
   *
   * Regarding '<S420>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S421>/FixPt Gateway Out'
   *
   * Regarding '<S421>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S422>/FixPt Gateway Out'
   *
   * Regarding '<S422>/FixPt Gateway Out':
   *   Eliminate redundant data type conversion
   */

  /* SignalConversion Block: '<S425>/copy'
   *
   * Regarding '<S425>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S426>/copy'
   *
   * Regarding '<S426>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S427>/copy'
   *
   * Regarding '<S427>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S428>/copy'
   *
   * Regarding '<S428>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* SignalConversion Block: '<S429>/copy'
   *
   * Regarding '<S429>/copy':
   *   Eliminate redundant signal conversion block
   */

  /* DataTypeConversion Block: '<S434>/Data Type Conversion'
   *
   * Regarding '<S434>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S435>/Data Type Conversion'
   *
   * Regarding '<S435>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S436>/Data Type Conversion'
   *
   * Regarding '<S436>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S437>/Data Type Conversion'
   *
   * Regarding '<S437>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S438>/Data Type Conversion'
   *
   * Regarding '<S438>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S13>/F01_scruter_environ_adaptation' */

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_write5' */

  /* S-Function Block: <S13>/autosar_irv_write5 */
  Rte_IrvWrite_RE_AFAT_007_TEV_AFA_rOpClsThrBolHld_irv
    (localAFAT_F01_scruter_environ_i);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_write6' */

  /* S-Function Block: <S13>/autosar_irv_write6 */
  Rte_IrvWrite_RE_AFAT_007_TEV_AFA_pAirExtEstimHld_irv
    (localAFAT_F01_scruter_environ_a);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_write7' */

  /* S-Function Block: <S13>/autosar_irv_write7 */
  Rte_IrvWrite_RE_AFAT_007_TEV_AFA_agCkOpInVlvBolHld_irv
    (localAFAT_F01_scruter_environ_e);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_write8' */

  /* S-Function Block: <S13>/autosar_irv_write8 */
  Rte_IrvWrite_RE_AFAT_007_TEV_AFA_agCkClsExVlvBolHld_irv
    (localAFAT_F01_scruter_environ_b);

  /* S-Function (sfun_autosar_extras_irv_read_write): '<S13>/autosar_irv_write9' */

  /* S-Function Block: <S13>/autosar_irv_write9 */
  Rte_IrvWrite_RE_AFAT_007_TEV_AFA_rOpClsEGRVlvBolHld_irv
    (localAFAT_F01_scruter_environ_k);

  /* SignalConversion: '<S424>/copy' */
  AFA_rOpClsEGRVlvBolPrev = localautosar_irv_read2_m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S424>/autosar_testpoint1' */

  /* S-Function Block: <S424>/autosar_testpoint1 */

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S425>/autosar_testpoint1' */

  /* S-Function Block: <S425>/autosar_testpoint1 */
  AFA_rOpClsThrBolHld_IRV_MP = localAFAT_F01_scruter_environ_i;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S426>/autosar_testpoint1' */

  /* S-Function Block: <S426>/autosar_testpoint1 */
  AFA_pAirExtEstimHld_IRV_MP = localAFAT_F01_scruter_environ_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S427>/autosar_testpoint1' */

  /* S-Function Block: <S427>/autosar_testpoint1 */
  AFA_rOpClsEGRVlvBolHld_IRV_MP = localAFAT_F01_scruter_environ_k;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S428>/autosar_testpoint1' */

  /* S-Function Block: <S428>/autosar_testpoint1 */
  AFA_agCkOpInVlvBolHld_IRV_MP = localAFAT_F01_scruter_environ_e;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S429>/autosar_testpoint1' */

  /* S-Function Block: <S429>/autosar_testpoint1 */
  AFA_agCkClsExVlvBolHld_IRV_MP = localAFAT_F01_scruter_environ_b;

  /* SignalConversion: '<S430>/copy' */
  AFA_agCkOpInVlvBolPrev = localautosar_irv_read3_a;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S430>/autosar_testpoint1' */

  /* S-Function Block: <S430>/autosar_testpoint1 */

  /* SignalConversion: '<S431>/copy' */
  AFA_agCkClsExVlvBolPrev = localautosar_irv_read4;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S431>/autosar_testpoint1' */

  /* S-Function Block: <S431>/autosar_testpoint1 */

  /* SignalConversion: '<S432>/copy' */
  AFA_rOpClsThrBolPrev = localautosar_irv_read42;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S432>/autosar_testpoint1' */

  /* S-Function Block: <S432>/autosar_testpoint1 */

  /* SignalConversion: '<S433>/copy' */
  AFA_pAirExtEstimHldPrev = localautosar_irv_read1_m;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S433>/autosar_testpoint1' */

  /* S-Function Block: <S433>/autosar_testpoint1 */

  /* Switch: '<S438>/Switch' incorporates:
   *  Constant: '<S438>/Byp_Fonction_SC'
   *  Constant: '<S438>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_b = AFA_bClsEGRRef_B;
  } else {
    localTmpSignalConversionAtAFA_b = localAFAT_F01_scruter_environ_d;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bClsEGRRefInport2' */
  Rte_Write_P_AFA_bClsEGRRef_AFA_bClsEGRRef(localTmpSignalConversionAtAFA_b);

  /* Switch: '<S434>/Switch' incorporates:
   *  Constant: '<S434>/Byp_Fonction_SC'
   *  Constant: '<S434>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_b = AFA_bFitClsExVlvBol_B;
  } else {
    localTmpSignalConversionAtAFA_b = localAFAT_F01_scruter_environ_h;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitClsExVlvBolInport2' */
  Rte_Write_P_AFA_bFitClsExVlvBol_AFA_bFitClsExVlvBol
    (localTmpSignalConversionAtAFA_b);

  /* Switch: '<S435>/Switch' incorporates:
   *  Constant: '<S435>/Byp_Fonction_SC'
   *  Constant: '<S435>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_b = AFA_bFitOpInVlvBol_B;
  } else {
    localTmpSignalConversionAtAFA_b = localAFAT_F01_scruter_environ_f;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitOpInVlvBolInport2' */
  Rte_Write_P_AFA_bFitOpInVlvBol_AFA_bFitOpInVlvBol
    (localTmpSignalConversionAtAFA_b);

  /* Switch: '<S437>/Switch' incorporates:
   *  Constant: '<S437>/Byp_Fonction_SC'
   *  Constant: '<S437>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_b = AFA_bFitPresAirExt_B;
  } else {
    localTmpSignalConversionAtAFA_b = localAFAT_F01_scruter_enviro_at;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitPresAirExtInport2' */
  Rte_Write_P_AFA_bFitPresAirExt_AFA_bFitPresAirExt
    (localTmpSignalConversionAtAFA_b);

  /* Switch: '<S436>/Switch' incorporates:
   *  Constant: '<S436>/Byp_Fonction_SC'
   *  Constant: '<S436>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_b = AFA_bFitZeroPosnThr_B;
  } else {
    localTmpSignalConversionAtAFA_b = localAFAT_F01_scruter_environ_l;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtAFA_bFitZeroPosnThrInport2' */
  Rte_Write_P_AFA_bFitZeroPosnThr_AFA_bFitZeroPosnThr
    (localTmpSignalConversionAtAFA_b);
}

/* Start for exported function: RE_AFAT_006_TEV */
void RE_AFAT_006_TEV_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcObsDly_(006_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcObsDly_(006_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_153.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_317.01 ;
   */
}

/* Output and update for exported function: RE_AFAT_006_TEV */
void RE_AFAT_006_TEV(void)
{
  /* local block i/o variables */
  UInt32 localSignalConversion_o;
  UInt32 localAFAT_F06_tempos_adaptation;
  UInt32 localTmpSignalConversionAtAFA_t;

  /* S-Function (fcncallgen): '<S8>/expFcn' incorporates:
   *  SubSystem: '<S1>/RE_AFAT_SdlSlow_AFAClcObsDly_(006_TEV)'
   *
   * Block requirements for '<S1>/RE_AFAT_SdlSlow_AFAClcObsDly_(006_TEV)':
   *  1. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_153.01 ;
   *  2. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_233.01 ;
   *  3. SubSystem "RE_AFAT_SdlSlow_AFAClcObsDly_(012_TEV)" !Trace_To : VEMS_R_11_04467_317.01 ;
   */

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAFA_tiDlyLstObs_INPUTOutport2' incorporates:
   *  Inport: '<Root>/AFA_tiDlyLstObs_INPUT'
   */
  Rte_Read_R_AFA_tiDlyLstObs_AFA_tiDlyLstObs(&localTmpSignalConversionAtAFA_t);

  /* SignalConversion: '<S14>/Signal Conversion' */
  localSignalConversion_o = localTmpSignalConversionAtAFA_t;

  /* SignalConversion: '<S440>/copy' */
  AFA_tiDlyLstObsPrev = localSignalConversion_o;

  /* S-Function (sfun_autosar_extras_dsm_read_write): '<S440>/autosar_testpoint1' */

  /* S-Function Block: <S440>/autosar_testpoint1 */

  /* Outputs for atomic SubSystem: '<S14>/F06_tempos_adaptation' *
   * Block requirements for '<S14>/F06_tempos_adaptation':
   *  1. SubSystem "F06_tempos_adaptation" !Trace_To : VEMS_R_11_04467_036.01 ;
   */

  /* ModelReference: '<S439>/AFAT_F06_tempos_adaptation' */
  mr_AFA_F06_tempos_adaptation(&localSignalConversion_o,
    &localAFAT_F06_tempos_adaptation);

  /* DataTypeConversion Block: '<S441>/Data Type Conversion'
   *
   * Regarding '<S441>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* end of Outputs for SubSystem: '<S14>/F06_tempos_adaptation' */

  /* Switch: '<S441>/Switch' incorporates:
   *  Constant: '<S441>/Byp_Fonction_SC'
   *  Constant: '<S441>/Int_BypC'
   */
  if (AFAT_ACTIVE_BYP_C) {
    localTmpSignalConversionAtAFA_t = AFA_tiDlyLstObs_B;
  } else {
    localTmpSignalConversionAtAFA_t = localAFAT_F06_tempos_adaptation;
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtAFA_tiDlyLstObsInport2' */
  Rte_Write_P_AFA_tiDlyLstObs_AFA_tiDlyLstObs(localTmpSignalConversionAtAFA_t);
}

/* Model initialize function */
void RE_AFAT_Init(void)
{
  /* Model Initialize fcn for ModelReference Block: '<S43>/AFA_F01_add_cranking_noise' */
  mr_AFA_F01_add_crank_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S45>/AFA_F01_lire_adaptatifs_en_eeprom' */
  mr_AFA_F01_lire_adap_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S46>/AFA_F02_Afa_adapt_terms_reset' */
  mr_AFA_F02_Afa_adapt_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S69>/AFAT_F00_init_scruter_environ_adaptation' */
  mr_AFA_F00_init_scru_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S71>/AFAT_F03_reset_cumulated_model_noise_v' */
  mr_AFA_F03_reset_cum_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S97>/AFAT_F00_init_scruter_environ_adaptation' */
  mr_AFA_F00_init_scru_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S99>/AFAT_F03_reset_cumulated_model_noise_v' */
  mr_AFA_F03_reset_cum_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S136>/AFAT_F01_init_inputs_filters' */
  mr_AFA_F01_init_inpu_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S189>/AFAT_F02_inputs_filters' */
  mr_AFA_F02_inputs_fi_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S248>/AFA_F01_AFAClcObs' */
  mr_AFA_F01_AFAClcObs_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S250>/AFAT_F01_Osbservation_Number' */
  mr_AFA_F01_Osbservat_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S251>/AFAT_F01_calc_measurement_vector' */
  mr_AFA_F01_calc_meas_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S252>/AFAT_F01_reinit_after_app_adaption' */
  mr_AFA_F01_reinit_af_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S253>/AFA_F02_Activation_EOM_Mode' */
  mr_AFA_F02_Activatio_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S255>/AFAT_F02_add_patmo_reference_noise' */
  mr_AFA_F02_add_patmo_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S256>/AFAT_F02_calc_model_noise_mat' */
  mr_AFA_F02_calc_mode_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S257>/AFAT_F03_add_throttle_reference_noise' */
  mr_AFA_F03_add_throt_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S258>/AFAT_F03_calcul_adaptatifs' */
  mr_AFA_F03_calcul_ad_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S260>/AFAT_F03_reset_cumulated_model_noise_v' */
  mr_AFA_F03_reset_cum_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S261>/AFAT_F04_add_egr_reference_noise' */
  mr_AFA_F04_add_egr_r_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S262>/AFAT_F04_calc_innovation_vect' */
  mr_AFA_F04_calc_inno_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S263>/AFAT_F04_command_adaptation_parameters' */
  mr_AFA_F04_command_a_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S264>/AFAT_F04_detect_adaptation_stop' */
  mr_AFA_F04_detect_ad_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S265>/AFAT_F05_add_incoherence_model_noise' */
  mr_AFA_F05_add_incoh_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S266>/AFAT_F05_calc_pred_innov_covar_mat' */
  mr_AFA_F05_calc_pred_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S267>/AFAT_F06_add_adaption_noise' */
  mr_AFA_F06_add_adapt_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S268>/AFAT_F06_calc_gain_de_kalman' */
  mr_AFA_F06_calc_gain_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S269>/AFAT_F07_add_IVO_reference_noise' */
  mr_AFA_F07_add_IVO_r_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S270>/AFAT_F07_calc_error_param_vect' */
  mr_AFA_F07_calc_erro_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S271>/AFAT_F08_add_EVC_reference_noise' */
  mr_AFA_F08_add_EVC_r_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S272>/AFAT_F08_calc_est_error_covar_mat' */
  mr_AFA_F08_calc_est__initialize();

  /* Model Initialize fcn for ModelReference Block: '<S403>/AFAT_F00_init_scruter_environ_adaptation' */
  mr_AFA_F00_init_scru_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S405>/AFAT_F03_reset_cumulated_model_noise_v' */
  mr_AFA_F03_reset_cum_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S423>/AFAT_F01_scruter_environ_adaptation' */
  mr_AFA_F01_scruter_e_initialize();

  /* Model Initialize fcn for ModelReference Block: '<S439>/AFAT_F06_tempos_adaptation' */
  mr_AFA_F06_tempos_ad_initialize();

  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   *  Start for SubSystem: '<Root>/__ExpFcn__3'
   *  Start for SubSystem: '<Root>/__ExpFcn__4'
   *  Start for SubSystem: '<Root>/__ExpFcn__5'
   *  Start for SubSystem: '<Root>/__ExpFcn__6'
   *  Start for SubSystem: '<Root>/__ExpFcn__7'
   */
  RE_AFAT_001_MSE_Start();
  RE_AFAT_002_MSE_Start();
  RE_AFAT_003_MSE_Start();
  RE_AFAT_004_TEV_Start();
  RE_AFAT_005_TEV_Start();
  RE_AFAT_007_TEV_Start();
  RE_AFAT_006_TEV_Start();
}

#define AFAT_STOP_SEC_CODE
#include "AFAT_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
