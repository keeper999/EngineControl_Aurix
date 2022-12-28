/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ProdElEng.c
* Description   : Interface AUTOSAR du module ProdElEng avec Bypasses
* Auteur        : BETC/CLO
* Creation      : 16-May-2011(10:9:7)
* Modification  : 22-March-2012
*******************************************************************************/

#ifndef _PRODELENG_C_
#define _PRODELENG_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_ProdElEng.h"
#include "ProdElEng.h"
#include "ProdElEng_002_TEV_fct.h"
#include "ProdElEng_004_TEV_fct.h"
#include "ProdElEng_006_TEV_fct.h"
#include "ProdElEng_008_TEV_fct.h"
#include "ProdElEng_010_TEV_fct.h"
#include "ProdElEng_012_TEV_fct.h"
#include "ProdElEng_014_TEV_fct.h"
#include "ProdElEng_016_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define PRODELENG_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEng_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ProdElEng_ModuleVersion_Major_MP = 4;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ProdElEng_ModuleVersion_Minor_MP = 2;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ProdElEng_ModuleVersion_Build_MP = 1;
#define PRODELENG_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEng_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 1

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PRODELENG_START_SEC_CALIB_BOOLEAN
#include "ProdElEng_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_008_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_010_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_012_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_014_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELENG_016_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqLimUH_bFrzReqTqVoltCtl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqLimUH_bReqClsCnv_B = 0;
#define PRODELENG_STOP_SEC_CALIB_BOOLEAN
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stReqBlsVoltCtl_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stReqUnBlsVoltCtl_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_stDrivTyp_B = 4;
AR_MERGEABLE_CALIB_8BIT UInt8 TqLimUH_bfAcvConstFrntTra1_B = 0;
#define PRODELENG_STOP_SEC_CALIB_8BIT
#include "ProdElEng_MemMap.h"

#define PRODELENG_START_SEC_CALIB_16BIT
#include "ProdElEng_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 TqLimUH_grdLimVoltCtlDynMax_B = 8;
#define PRODELENG_STOP_SEC_CALIB_16BIT
#include "ProdElEng_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define PRODELENG_START_SEC_CODE
#include "ProdElEng_MemMap.h"

void RE_ProdElEng_001_MSE(void)
{


      ProdElEng_001_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqLimUH_bAcvAntiStall(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqLimUH_bEngUHNOnIdl(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqLimUH_tqIdcMaxLim(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqSys_bBrioUHAuth(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqSys_bInhRecupUHVoltCtl(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqSys_bTqAltFrzReq(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqSys_bTqAltGrdLimReq(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqSys_bTqAltRlsReq(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqLimUH_tqIdcFLdLim(0);
  (void)Rte_IrvWrite_RE_ProdElEng_001_MSE_TqLimUH_bRlsAltBrkAsi(0);

}

void RE_ProdElEng_002_TEV(void)
{

  if (FALSE == RE_PRODELENG_002_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoCha_bTqAccuReq_CoCha_bTqAccuReq(&ProdElEng_002_CoCha_bTqAccuReq_in);
      (void)Rte_Read_R_CoCha_bTqDynReq_CoCha_bTqDynReq(&ProdElEng_002_CoCha_bTqDynReq_in);
      (void)Rte_Read_R_CoPt_bBrioUHAuth_CoPt_bBrioUHAuth(&ProdElEng_002_CoPt_bBrioUHAuth_in);
      (void)Rte_Read_R_CoPt_bInhRecup_CoPt_bInhRecup(&ProdElEng_002_CoPt_bInhRecup_in);
      (void)Rte_Read_R_CoPt_bTqAltFrzReq_CoPt_bTqAltFrzReq(&ProdElEng_002_CoPt_bTqAltFrzReq_in);
      (void)Rte_Read_R_CoPt_bTqAltFrzReq_nCross_CoPt_bTqAltFrzReq_nCross(&ProdElEng_002_CoPt_bTqAltFrzReq_nCross_in);
      (void)Rte_Read_R_CoPt_bTqAltGrdLimReq_CoPt_bTqAltGrdLimReq(&ProdElEng_002_CoPt_bTqAltGrdLimReq_in);
      (void)Rte_Read_R_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax(&ProdElEng_002_EngLim_tqIdcLdMaxTrbMax_in);
      (void)Rte_Read_R_EngLim_tqIdcLim_EngLim_tqIdcLim(&ProdElEng_002_EngLim_tqIdcLim_in);
      (void)Rte_Read_R_TqEM_bFrzACComp_TqEM_bFrzACComp(&ProdElEng_002_TqEM_bFrzACComp_in);
      (void)Rte_Read_R_TqSys_bAcvAntiStall_TqSys_bAcvAntiStall(&ProdElEng_002_TqSys_bAcvAntiStall_in);
      (void)Rte_Read_R_TqSys_bEngUHNOnIdl_TqSys_bEngUHNOnIdl(&ProdElEng_002_TqSys_bEngUHNOnIdl_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&ProdElEng_002_TqSys_bTypFu_in);
      (void)Rte_Read_R_TqSys_bUHFrzReq_TqSys_bUHFrzReq(&ProdElEng_002_TqSys_bUHFrzReq_in);
      (void)Rte_Read_R_VSCtl_bInhRecup_VSCtl_bInhRecup(&ProdElEng_002_VSCtl_bInhRecup_in);
      (void)Rte_Read_R_TqSys_bRlsAltBrkAsi_TqSys_bRlsAltBrkAsi(&ProdElEng_002_TqSys_bRlsAltBrkAsi_in);
      (void)Rte_Read_R_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(&ProdElEng_002_EngLim_tqIdcFLdLim_in);
      RE_ProdElEng_002_TEV_TqSys_bInjFrzTqUHReq_in = Rte_IrvRead_RE_ProdElEng_002_TEV_TqSys_bInjFrzTqUHReq();

      ProdElEng_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqLimUH_bAcvAntiStall(TqLimUH_bAcvAntiStall);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqLimUH_bEngUHNOnIdl(TqLimUH_bEngUHNOnIdl);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqLimUH_tqIdcMaxLim(TqLimUH_tqIdcMaxLim);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqSys_bBrioUHAuth(TqSys_bBrioUHAuth);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqSys_bInhRecupUHVoltCtl(TqSys_bInhRecupUHVoltCtl);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqSys_bTqAltFrzReq(TqSys_bTqAltFrzReq);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqSys_bTqAltGrdLimReq(TqSys_bTqAltGrdLimReq);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqSys_bTqAltRlsReq(TqSys_bTqAltRlsReq);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqLimUH_tqIdcFLdLim(TqLimUH_tqIdcFLdLim);
  (void)Rte_IrvWrite_RE_ProdElEng_002_TEV_TqLimUH_bRlsAltBrkAsi(TqLimUH_bRlsAltBrkAsi);

}

void RE_ProdElEng_003_MSE(void)
{


      ProdElEng_003_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_003_MSE_TqLimUH_tqGrdBrioUHJerkLim(254);
  (void)Rte_IrvWrite_RE_ProdElEng_003_MSE_TqLimUH_bBrioUHBoost(0);
  (void)Rte_IrvWrite_RE_ProdElEng_003_MSE_TqLimUH_bBrioUHGrdUnlim(0);
  (void)Rte_IrvWrite_RE_ProdElEng_003_MSE_TqLimUH_bBrioUHRls(0);

}

void RE_ProdElEng_004_TEV(void)
{

  if (FALSE == RE_PRODELENG_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ProdElEng_004_AccP_rAccP_in);
      (void)Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&ProdElEng_004_Cha_stTqReq_in);
      (void)Rte_Read_R_CoPt_bRvsCord_CoPt_bRvsCord(&ProdElEng_004_CoPt_bRvsCord_in);
      (void)Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&ProdElEng_004_CoPt_noGearCord_in);
      (void)Rte_Read_R_CoPt_tqIdcCordLim_tqGBx_CoPt_tqIdcCordLim_tqGBx(&ProdElEng_004_CoPt_tqIdcCordLim_tqGBx_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_004_CoPTSt_stEng_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEng_004_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_bPush_Ext_bPush(&ProdElEng_004_Ext_bPush_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&ProdElEng_004_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ProdElEng_004_Ext_stGBxCf_in);
      (void)Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&ProdElEng_004_TqCmp_tqAltLoss_in);
      (void)Rte_Read_R_TqSys_bDeceAcv_TqSys_bDeceAcv(&ProdElEng_004_TqSys_bDeceAcv_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&ProdElEng_004_Veh_spdVeh_in);
      RE_ProdElEng_004_TEV_TqLimUH_tqIdcMaxLim_in = Rte_IrvRead_RE_ProdElEng_004_TEV_TqLimUH_tqIdcMaxLim();
      RE_ProdElEng_004_TEV_TqSys_bBrioUHAuth_in = Rte_IrvRead_RE_ProdElEng_004_TEV_TqSys_bBrioUHAuth();
      RE_ProdElEng_004_TEV_TqLimUH_tqIdcFLdLim_in = Rte_IrvRead_RE_ProdElEng_004_TEV_TqLimUH_tqIdcFLdLim();

      Rte_Call_R_FRM_bInhTqLimUHBrioUH_GetFunctionPermission(& ProdElEng_004_FRM_bInhTqLimUHBrioUH_in);
      ProdElEng_004_FRM_bInhTqLimUHBrioUH_in = !ProdElEng_004_FRM_bInhTqLimUHBrioUH_in;
      ProdElEng_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_004_TEV_TqLimUH_tqGrdBrioUHJerkLim(TqLimUH_tqGrdBrioUHJerkLim);
  (void)Rte_IrvWrite_RE_ProdElEng_004_TEV_TqLimUH_bBrioUHBoost(TqLimUH_bBrioUHBoost);
  (void)Rte_IrvWrite_RE_ProdElEng_004_TEV_TqLimUH_bBrioUHGrdUnlim(TqLimUH_bBrioUHGrdUnlim);
  (void)Rte_IrvWrite_RE_ProdElEng_004_TEV_TqLimUH_bBrioUHRls(TqLimUH_bBrioUHRls);

}

void RE_ProdElEng_005_MSE(void)
{


      ProdElEng_005_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_005_MSE_TqLimUH_bESPUnBlsAltReq(0);
  (void)Rte_IrvWrite_RE_ProdElEng_005_MSE_TqLimUH_bOutFrzUHGrdLim(0);
  (void)Rte_IrvWrite_RE_ProdElEng_005_MSE_TqLimUH_bTqAltFrzReq(0);

}

void RE_ProdElEng_006_TEV(void)
{

  if (FALSE == RE_PRODELENG_006_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_006_CoPTSt_stEng_in);
      (void)Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&ProdElEng_006_TqCmp_tqAltLoss_in);
      (void)Rte_Read_R_TqLimUH_stReqUnBlsVoltCtl_TqLimUH_stReqUnBlsVoltCtl(&ProdElEng_006_TqLimUH_stReqUnBlsVoltCtl_in);
      RE_ProdElEng_006_TEV_TqSys_bTqAltFrzReq_in = Rte_IrvRead_RE_ProdElEng_006_TEV_TqSys_bTqAltFrzReq();
      RE_ProdElEng_006_TEV_TqSys_bTqAltRlsReq_in = Rte_IrvRead_RE_ProdElEng_006_TEV_TqSys_bTqAltRlsReq();

      Rte_Call_R_FRM_bInhTqLimUHTqMchFrz_GetFunctionPermission(& ProdElEng_006_FRM_bInhTqLimUHTqMchFrz_in);
      ProdElEng_006_FRM_bInhTqLimUHTqMchFrz_in = !ProdElEng_006_FRM_bInhTqLimUHTqMchFrz_in;
      ProdElEng_006_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_006_TEV_TqLimUH_bESPUnBlsAltReq(TqLimUH_bESPUnBlsAltReq);
  (void)Rte_IrvWrite_RE_ProdElEng_006_TEV_TqLimUH_bOutFrzUHGrdLim(TqLimUH_bOutFrzUHGrdLim);
  (void)Rte_IrvWrite_RE_ProdElEng_006_TEV_TqLimUH_bTqAltFrzReq(TqLimUH_bTqAltFrzReq);

}

void RE_ProdElEng_007_MSE(void)
{


      ProdElEng_007_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_007_MSE_TqLimUH_tqGrdLimUHDynMax(40);

}

void RE_ProdElEng_008_TEV(void)
{

  if (FALSE == RE_PRODELENG_008_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&ProdElEng_008_CoPt_noGearCord_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_008_CoPTSt_stEng_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEng_008_Eng_nCkFil_in);
      (void)Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&ProdElEng_008_TqCmp_tqAltLoss_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ProdElEng_008_Ext_tCoMes_in);
      RE_ProdElEng_008_TEV_TqLimUH_bEngUHNOnIdl_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bEngUHNOnIdl();
      RE_ProdElEng_008_TEV_TqLimUH_bOutFrzUHGrdLim_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bOutFrzUHGrdLim();
      RE_ProdElEng_008_TEV_TqLimUH_bRecupAcv_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bRecupAcv();
      RE_ProdElEng_008_TEV_TqLimUH_bTqAltFrzReq_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bTqAltFrzReq();
      RE_ProdElEng_008_TEV_TqLimUH_tqGrdBrioUHJerkLim_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_tqGrdBrioUHJerkLim();
      RE_ProdElEng_008_TEV_TqSys_bTqAltGrdLimReq_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqSys_bTqAltGrdLimReq();
      RE_ProdElEng_008_TEV_TqLimUH_bAntiStallGrdUnlim_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bAntiStallGrdUnlim();
      RE_ProdElEng_008_TEV_TqLimUH_bBrioUHGrdUnlim_in = Rte_IrvRead_RE_ProdElEng_008_TEV_TqLimUH_bBrioUHGrdUnlim();

      Rte_Call_R_FRM_bAcvTqLimUHMdl_tqGrdLim_GetFunctionPermission(& ProdElEng_008_FRM_bAcvTqLimUHMdl_tqGrdLim_in);
      ProdElEng_008_FRM_bAcvTqLimUHMdl_tqGrdLim_in = !ProdElEng_008_FRM_bAcvTqLimUHMdl_tqGrdLim_in;
      ProdElEng_008_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_008_TEV_TqLimUH_tqGrdLimUHDynMax(TqLimUH_tqGrdLimUHDynMax);

}

void RE_ProdElEng_009_MSE(void)
{


      ProdElEng_009_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_009_MSE_TqSys_bInjAcvUHReq(1);
  (void)Rte_IrvWrite_RE_ProdElEng_009_MSE_TqSys_bInjFrzTqUHReq(0);

}

void RE_ProdElEng_010_TEV(void)
{

  if (FALSE == RE_PRODELENG_010_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&ProdElEng_010_TqSys_bTypFu_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEng_010_Eng_nCkFil_in);
      (void)Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&ProdElEng_010_TqSys_tqIdcReq_in);
      (void)Rte_Read_R_InjSys_bFuCutOff_InjSys_bFuCutOff(&ProdElEng_010_InjSys_bFuCutOff_in);
      (void)Rte_Read_R_InjSP_mfFuPoI1Req_InjSP_mfFuPoI1Req(&ProdElEng_010_InjSP_mfFuPoI1Req_in);
      (void)Rte_Read_R_InjSP_mfFuPoI2Req_InjSP_mfFuPoI2Req(&ProdElEng_010_InjSP_mfFuPoI2Req_in);

      Rte_Call_R_FRM_bInhTqSysStInjEs_GetFunctionPermission(& ProdElEng_010_FRM_bInhTqSysStInjEs_in);
      ProdElEng_010_FRM_bInhTqSysStInjEs_in = !ProdElEng_010_FRM_bInhTqSysStInjEs_in;
      ProdElEng_010_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_010_TEV_TqSys_bInjAcvUHReq(TqSys_bInjAcvUHReq);
  (void)Rte_IrvWrite_RE_ProdElEng_010_TEV_TqSys_bInjFrzTqUHReq(TqSys_bInjFrzTqUHReq);

}

void RE_ProdElEng_011_MSE(void)
{


      ProdElEng_011_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_011_MSE_TqLimUH_bRecupAcv(0);
  (void)Rte_IrvWrite_RE_ProdElEng_011_MSE_TqLimUH_bUHRecupInh(0);
      (void)Rte_Write_P_TqLimUH_bFrzReqTqVoltCtl_TqLimUH_bFrzReqTqVoltCtl(0);
      (void)Rte_Write_P_TqLimUH_grdLimVoltCtlDynMax_TqLimUH_grdLimVoltCtlDynMax(8);
      (void)Rte_Write_P_TqLimUH_stReqBlsVoltCtl_TqLimUH_stReqBlsVoltCtl(0);
      (void)Rte_Write_P_TqLimUH_stReqUnBlsVoltCtl_TqLimUH_stReqUnBlsVoltCtl(0);
      (void)Rte_Write_P_TqLimUH_bReqClsCnv_TqLimUH_bReqClsCnv(0);
      (void)Rte_Write_P_TqLimUH_bfAcvConstFrntTra1_TqLimUH_bfAcvConstFrntTra1(0);

}

void RE_ProdElEng_012_TEV(void)
{

  if (FALSE == RE_PRODELENG_012_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&ProdElEng_012_CoPt_noGearCord_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_012_CoPTSt_stEng_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEng_012_Eng_nCkFil_in);
      (void)Rte_Read_R_CoOptmEl_stElProd_CoOptmEl_stElProd(&ProdElEng_012_CoOptmEl_stElProd_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&ProdElEng_012_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_bBrkPedPrss_Ext_bBrkPedPrss(&ProdElEng_012_Ext_bBrkPedPrss_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&ProdElEng_012_TqSys_nTarIdl_in);
      (void)Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&ProdElEng_012_TqSys_tqCkEngReal_in);
      (void)Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&ProdElEng_012_CoVSCtl_rAccPEngTrv_in);
      (void)Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&ProdElEng_012_CoPt_bTqTx_in);
      (void)Rte_Read_R_CoPt_stCnvCluFil_CoPt_stCnvCluFil(&ProdElEng_012_CoPt_stCnvCluFil_in);
      (void)Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&ProdElEng_012_CoPt_stCpl_in);
      (void)Rte_Read_R_CoPt_stVoltAltBoostReq_CoPt_stVoltAltBoostReq(&ProdElEng_012_CoPt_stVoltAltBoostReq_in);
      RE_ProdElEng_012_TEV_TqLimUH_bTqAltFrzReq_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_bTqAltFrzReq();
      RE_ProdElEng_012_TEV_TqLimUH_bAntiStall_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_bAntiStall();
      RE_ProdElEng_012_TEV_TqLimUH_tqGrdLimUHDynMax_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_tqGrdLimUHDynMax();
      RE_ProdElEng_012_TEV_TqSys_bInhRecupUHVoltCtl_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqSys_bInhRecupUHVoltCtl();
      RE_ProdElEng_012_TEV_TqSys_bInjAcvUHReq_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqSys_bInjAcvUHReq();
      RE_ProdElEng_012_TEV_TqLimUH_bBrioUHBoost_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_bBrioUHBoost();
      RE_ProdElEng_012_TEV_TqLimUH_bBrioUHRls_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_bBrioUHRls();
      RE_ProdElEng_012_TEV_TqLimUH_bRlsAltBrkAsi_in = Rte_IrvRead_RE_ProdElEng_012_TEV_TqLimUH_bRlsAltBrkAsi();

      Rte_Call_R_FRM_bInhRecupUH_GetFunctionPermission(& ProdElEng_012_FRM_bInhRecupUH_in);
      ProdElEng_012_FRM_bInhRecupUH_in = !ProdElEng_012_FRM_bInhRecupUH_in;
      Rte_Call_R_FRM_bInhRecupVoltCtl_GetFunctionPermission(& ProdElEng_012_FRM_bInhRecupVoltCtl_in);
      ProdElEng_012_FRM_bInhRecupVoltCtl_in = !ProdElEng_012_FRM_bInhRecupVoltCtl_in;
      ProdElEng_012_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      TqLimUH_bFrzReqTqVoltCtl_out = TqLimUH_bFrzReqTqVoltCtl_B;
      TqLimUH_grdLimVoltCtlDynMax_out = TqLimUH_grdLimVoltCtlDynMax_B;
      TqLimUH_stReqBlsVoltCtl_out = TqLimUH_stReqBlsVoltCtl_B;
      TqLimUH_stReqUnBlsVoltCtl_out = TqLimUH_stReqUnBlsVoltCtl_B;
      TqLimUH_bReqClsCnv_out = TqLimUH_bReqClsCnv_B;
      TqLimUH_bfAcvConstFrntTra1_out = TqLimUH_bfAcvConstFrntTra1_B;
  }
  (void)Rte_IrvWrite_RE_ProdElEng_012_TEV_TqLimUH_bRecupAcv(TqLimUH_bRecupAcv);
  (void)Rte_IrvWrite_RE_ProdElEng_012_TEV_TqLimUH_bUHRecupInh(TqLimUH_bUHRecupInh);
  (void)Rte_Write_P_TqLimUH_bFrzReqTqVoltCtl_TqLimUH_bFrzReqTqVoltCtl(TqLimUH_bFrzReqTqVoltCtl_out);
  (void)Rte_Write_P_TqLimUH_grdLimVoltCtlDynMax_TqLimUH_grdLimVoltCtlDynMax(TqLimUH_grdLimVoltCtlDynMax_out);
  (void)Rte_Write_P_TqLimUH_stReqBlsVoltCtl_TqLimUH_stReqBlsVoltCtl(TqLimUH_stReqBlsVoltCtl_out);
  (void)Rte_Write_P_TqLimUH_stReqUnBlsVoltCtl_TqLimUH_stReqUnBlsVoltCtl(TqLimUH_stReqUnBlsVoltCtl_out);
  (void)Rte_Write_P_TqLimUH_bReqClsCnv_TqLimUH_bReqClsCnv(TqLimUH_bReqClsCnv_out);
  (void)Rte_Write_P_TqLimUH_bfAcvConstFrntTra1_TqLimUH_bfAcvConstFrntTra1(TqLimUH_bfAcvConstFrntTra1_out);

}

void RE_ProdElEng_013_MSE(void)
{


      ProdElEng_013_MSE_ini();

      (void)Rte_Write_P_TqLimUH_stDrivTyp_TqLimUH_stDrivTyp(4);

}

void RE_ProdElEng_014_TEV(void)
{

  if (FALSE == RE_PRODELENG_014_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ProdElEng_014_AccP_rAccP_in);
      (void)Rte_Read_R_CoPt_bRvsCord_CoPt_bRvsCord(&ProdElEng_014_CoPt_bRvsCord_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_014_CoPTSt_stEng_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&ProdElEng_014_Veh_spdVeh_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ProdElEng_014_Ext_tCoMes_in);
      (void)Rte_Read_R_CoPt_stDrvTra_CoPt_stDrvTra(&ProdElEng_014_CoPt_stDrvTra_in);
      (void)Rte_Read_R_EOM_stCmbMod_EOM_stCmbMod(&ProdElEng_014_EOM_stCmbMod_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&ProdElEng_014_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tAirExtMes_Ext_tAirExtMes(&ProdElEng_014_Ext_tAirExtMes_in);
      (void)Rte_Read_R_Stg_agStrWhl_Stg_agStrWhl(&ProdElEng_014_Stg_agStrWhl_in);
      (void)Rte_Read_R_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(&ProdElEng_014_TqSys_tqCkEfcFilTrv_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&ProdElEng_014_Ext_dstVehTotMes_in);

      Rte_Call_R_FRM_bInhWup_GetFunctionPermission(& ProdElEng_014_FRM_bInhWup_in);
      ProdElEng_014_FRM_bInhWup_in = !ProdElEng_014_FRM_bInhWup_in;
      Rte_Call_R_FRM_bDrivTyp_GetFunctionPermission(& ProdElEng_014_FRM_bDrivTyp_in);
      ProdElEng_014_FRM_bDrivTyp_in = !ProdElEng_014_FRM_bDrivTyp_in;
      ProdElEng_014_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      TqLimUH_stDrivTyp_out = TqLimUH_stDrivTyp_B;
  }
  (void)Rte_Write_P_TqLimUH_stDrivTyp_TqLimUH_stDrivTyp(TqLimUH_stDrivTyp_out);

}

void RE_ProdElEng_015_MSE(void)
{


      ProdElEng_015_MSE_ini();

  (void)Rte_IrvWrite_RE_ProdElEng_015_MSE_TqLimUH_bAntiStall(0);
  (void)Rte_IrvWrite_RE_ProdElEng_015_MSE_TqLimUH_bAntiStallGrdUnlim(0);

}

void RE_ProdElEng_016_TEV(void)
{

  if (FALSE == RE_PRODELENG_016_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ProdElEng_016_CoPTSt_stEng_in);
      (void)Rte_Read_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(&ProdElEng_016_ACCmd_bInhAntiStall_in);
      RE_ProdElEng_016_TEV_TqLimUH_bAcvAntiStall_in = Rte_IrvRead_RE_ProdElEng_016_TEV_TqLimUH_bAcvAntiStall();
      RE_ProdElEng_016_TEV_TqLimUH_bESPUnBlsAltReq_in = Rte_IrvRead_RE_ProdElEng_016_TEV_TqLimUH_bESPUnBlsAltReq();

      Rte_Call_R_FRM_bInhTqLimUHAntiStall_GetFunctionPermission(& ProdElEng_016_FRM_bInhTqLimUHAntiStall_in);
      ProdElEng_016_FRM_bInhTqLimUHAntiStall_in = !ProdElEng_016_FRM_bInhTqLimUHAntiStall_in;
      ProdElEng_016_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ProdElEng_016_TEV_TqLimUH_bAntiStall(TqLimUH_bAntiStall);
  (void)Rte_IrvWrite_RE_ProdElEng_016_TEV_TqLimUH_bAntiStallGrdUnlim(TqLimUH_bAntiStallGrdUnlim);

}

#define PRODELENG_STOP_SEC_CODE
#include "ProdElEng_MemMap.h"

#endif/*_PRODELENG_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

