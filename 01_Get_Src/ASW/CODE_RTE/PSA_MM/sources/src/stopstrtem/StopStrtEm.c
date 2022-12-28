/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : StopStrtEm.c
* Description   : Interface AUTOSAR du module StopStrtEm avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 22-December-2011(15:08:1)
*******************************************************************************/

#ifndef _STOPSTRTEM_C_
#define _STOPSTRTEM_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_StopStrtEm.h"
#include "StopStrtEm.h"
#include "StopStrtEm_002_TEV_fct.h"
#include "StopStrtEm_004_TEV_fct.h"
#include "StopStrtEm_006_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define STOPSTRTEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEm_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Major_MP = 5;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Minor_MP = 1;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Build_MP = 1;
#define STOPSTRTEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 4

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define STOPSTRTEM_START_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bDetSlowN_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bInfoCplReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bInfoCplSt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bReqAltBoostFil_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bRvAltPrepRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bRvAltRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bStaRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bStaStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bVldFastN_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bWaitStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bPwrAcvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bStaReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoCplReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoCplSt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoStaRun_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bStaReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bDftElCmd_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bProt10StopInh_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bRstrtProt4_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bStrtProt10_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bRstrtProt10_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bDmgLimStopInh_B = 0;
#define STOPSTRTEM_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stReqAltBoost_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stRstrtTyp_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stStrtRstrtFbCmd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stSTTCf_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_tiStaEgdHiThd_B = 60;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_tiStaEgdLoThd_B = 30;
AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_stStaStrtFbCmd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_stStaRstrtFbCmd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_tiStaEgdHiThd_B = 60;
AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_tiStaEgdLoThd_B = 30;
AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_stStaFbCmd_B = 0;
#define STOPSTRTEM_STOP_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiStaAcvCnt_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_nStaEgdHiThd_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_nStaEgdLoThd_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 StaRstrtMgt_nStaEgdHiThd_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 StaRstrtMgt_nStaEgdLoThd_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiMaxAcv_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoEmCkg_nFast_B = 0;
#define STOPSTRTEM_STOP_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"
AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaAcv_B = 0;
AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaRstrtAcv_B = 0;
AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaStrtAcv_B = 0;
#define STOPSTRTEM_STOP_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_VAR_BOOLEAN
#include "StopStrtEm_MemMap.h"
static Boolean StaStrtMgt_bMonRunStaCmd_out_prec;
static Boolean StaStrtMgt_bMonRunStaElCmd_out_prec;
static Boolean StaStrtMgt_bMonRunStuckMec_out_prec;
static Boolean StaStrtMgt_bMonRunStaAcvThd1_out_prec;
static Boolean StaStrtMgt_bMonRunStaAcvThd2_out_prec;
static Boolean StaStrtMgt_bMonRunStaCmdInfo_out_prec;
#define STOPSTRTEM_STOP_SEC_VAR_BOOLEAN
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define STOPSTRTEM_START_SEC_CODE
#include "StopStrtEm_MemMap.h"

void RE_StopStrtEm_001_MSE(void)
{


      StopStrtEm_001_MSE_ini();

      (void)Rte_Write_P_CoEmCkg_bDetSlowN_CoEmCkg_bDetSlowN(0);
      (void)Rte_Write_P_CoEmCkg_bInfoCplReq_CoEmCkg_bInfoCplReq(0);
      (void)Rte_Write_P_CoEmCkg_bInfoCplSt_CoEmCkg_bInfoCplSt(0);
      (void)Rte_Write_P_CoEmCkg_bStaRstrtReq_CoEmCkg_bStaRstrtReq(0);
      (void)Rte_Write_P_CoEmCkg_bStaStrtReq_CoEmCkg_bStaStrtReq(0);
      (void)Rte_Write_P_CoEmCkg_bVldFastN_CoEmCkg_bVldFastN(0);
      (void)Rte_Write_P_CoEmCkg_bWaitStrtReq_CoEmCkg_bWaitStrtReq(0);
      (void)Rte_Write_P_CoEmCkg_nFast_CoEmCkg_nFast(0);
      (void)Rte_Write_P_CoEmCkg_stRstrtTyp_CoEmCkg_stRstrtTyp(0);
      (void)Rte_Write_P_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(0);
      (void)Rte_Write_P_CoEmCkg_bRvAltPrepRstrtReq_CoEmCkg_bRvAltPrepRstrtReq(0);
      (void)Rte_Write_P_CoEmCkg_bRvAltRstrtReq_CoEmCkg_bRvAltRstrtReq(0);
      (void)Rte_Write_P_CoEmCkg_nStaEgdHiThd_CoEmCkg_nStaEgdHiThd(0);
      (void)Rte_Write_P_CoEmCkg_nStaEgdLoThd_CoEmCkg_nStaEgdLoThd(0);
      (void)Rte_Write_P_CoEmCkg_stSTTCf_CoEmCkg_stSTTCf(0);
      (void)Rte_Write_P_CoEmCkg_tiStaEgdHiThd_CoEmCkg_tiStaEgdHiThd(60);
      (void)Rte_Write_P_CoEmCkg_tiStaEgdLoThd_CoEmCkg_tiStaEgdLoThd(30);
      (void)Rte_Write_P_CoEmCkg_bReqAltBoostFil_CoEmCkg_bReqAltBoostFil(0);
      (void)Rte_Write_P_CoEmCkg_stReqAltBoost_CoEmCkg_stReqAltBoost(0);

}

void RE_StopStrtEm_002_TEV(void)
{

  if (FALSE == RE_STOPSTRTEM_002_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmSTT_bSTTWaitStrtReq_CoEmSTT_bSTTWaitStrtReq(&StopStrtEm_002_CoEmSTT_bSTTWaitStrtReq_in);
      (void)Rte_Read_R_CoPtUH_bAltPrepRStrtReq_CoPtUH_bAltPrepRStrtReq(&StopStrtEm_002_CoPtUH_bAltPrepRStrtReq_in);
      (void)Rte_Read_R_CoStrtRStrt_stAcvReq_CoStrtRStrt_stAcvReq(&StopStrtEm_002_CoStrtRStrt_stAcvReq_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&StopStrtEm_002_Ext_bSTTCf_in);
      (void)Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&StopStrtEm_002_Ext_stElProdCf_in);
      (void)Rte_Read_R_Ext_stStaCf_Ext_stStaCf(&StopStrtEm_002_Ext_stStaCf_in);
      (void)Rte_Read_R_PredEs_bDetSlowN_PredEs_bDetSlowN(&StopStrtEm_002_PredEs_bDetSlowN_in);
      (void)Rte_Read_R_PredEs_bVldFastN_PredEs_bVldFastN(&StopStrtEm_002_PredEs_bVldFastN_in);
      (void)Rte_Read_R_PredEs_nFast_PredEs_nFast(&StopStrtEm_002_PredEs_nFast_in);
      (void)Rte_Read_R_StaRstrtMgt_bInfoCplReq_StaRstrtMgt_bInfoCplReq(&StopStrtEm_002_StaRstrtMgt_bInfoCplReq_in);
      (void)Rte_Read_R_StaRstrtMgt_bInfoCplSt_StaRstrtMgt_bInfoCplSt(&StopStrtEm_002_StaRstrtMgt_bInfoCplSt_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&StopStrtEm_002_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_CoReqRStrt_stRStrtTyp_CoReqRStrt_stRStrtTyp(&StopStrtEm_002_CoReqRStrt_stRStrtTyp_in);
      (void)Rte_Read_R_RvAltMgt_stRvAltRstrtFbCmd_RvAltMgt_stRvAltRstrtFbCmd(&StopStrtEm_002_RvAltMgt_stRvAltRstrtFbCmd_in);
      (void)Rte_Read_R_StaRstrtMgt_nStaEgdHiThd_StaRstrtMgt_nStaEgdHiThd(&StopStrtEm_002_StaRstrtMgt_nStaEgdHiThd_in);
      (void)Rte_Read_R_StaRstrtMgt_nStaEgdLoThd_StaRstrtMgt_nStaEgdLoThd(&StopStrtEm_002_StaRstrtMgt_nStaEgdLoThd_in);
      (void)Rte_Read_R_StaRstrtMgt_tiStaEgdHiThd_StaRstrtMgt_tiStaEgdHiThd(&StopStrtEm_002_StaRstrtMgt_tiStaEgdHiThd_in);
      (void)Rte_Read_R_StaRstrtMgt_tiStaEgdLoThd_StaRstrtMgt_tiStaEgdLoThd(&StopStrtEm_002_StaRstrtMgt_tiStaEgdLoThd_in);
      (void)Rte_Read_R_StaStrtMgt_stStaFbCmd_StaStrtMgt_stStaFbCmd(&StopStrtEm_002_StaStrtMgt_stStaFbCmd_in);
      (void)Rte_Read_R_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(&StopStrtEm_002_CoEmSTT_bVSSAcvSt_in);
      (void)Rte_Read_R_CoEmSTT_bAuthBoost_CoEmSTT_bAuthBoost(&StopStrtEm_002_CoEmSTT_bAuthBoost_in);
      (void)Rte_Read_R_TqLimUH_bAcvUnBlsEng_TqLimUH_bAcvUnBlsEng(&StopStrtEm_002_TqLimUH_bAcvUnBlsEng_in);

      StopStrtEm_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoEmCkg_bDetSlowN_out = CoEmCkg_bDetSlowN_B;
      CoEmCkg_bInfoCplReq_out = CoEmCkg_bInfoCplReq_B;
      CoEmCkg_bInfoCplSt_out = CoEmCkg_bInfoCplSt_B;
      CoEmCkg_bStaRstrtReq_out = CoEmCkg_bStaRstrtReq_B;
      CoEmCkg_bStaStrtReq_out = CoEmCkg_bStaStrtReq_B;
      CoEmCkg_bVldFastN_out = CoEmCkg_bVldFastN_B;
      CoEmCkg_bWaitStrtReq_out = CoEmCkg_bWaitStrtReq_B;
      CoEmCkg_nFast_out = CoEmCkg_nFast_B;
      CoEmCkg_stRstrtTyp_out = CoEmCkg_stRstrtTyp_B;
      CoEmCkg_stStrtRstrtFbCmd_out = CoEmCkg_stStrtRstrtFbCmd_B;
      CoEmCkg_bRvAltPrepRstrtReq_out = CoEmCkg_bRvAltPrepRstrtReq_B;
      CoEmCkg_bRvAltRstrtReq_out = CoEmCkg_bRvAltRstrtReq_B;
      CoEmCkg_nStaEgdHiThd_out = CoEmCkg_nStaEgdHiThd_B;
      CoEmCkg_nStaEgdLoThd_out = CoEmCkg_nStaEgdLoThd_B;
      CoEmCkg_stSTTCf_out = CoEmCkg_stSTTCf_B;
      CoEmCkg_tiStaEgdHiThd_out = CoEmCkg_tiStaEgdHiThd_B;
      CoEmCkg_tiStaEgdLoThd_out = CoEmCkg_tiStaEgdLoThd_B;
      CoEmCkg_bReqAltBoostFil_out = CoEmCkg_bReqAltBoostFil_B;
      CoEmCkg_stReqAltBoost_out = CoEmCkg_stReqAltBoost_B;
  }
  (void)Rte_Write_P_CoEmCkg_bDetSlowN_CoEmCkg_bDetSlowN(CoEmCkg_bDetSlowN_out);
  (void)Rte_Write_P_CoEmCkg_bInfoCplReq_CoEmCkg_bInfoCplReq(CoEmCkg_bInfoCplReq_out);
  (void)Rte_Write_P_CoEmCkg_bInfoCplSt_CoEmCkg_bInfoCplSt(CoEmCkg_bInfoCplSt_out);
  (void)Rte_Write_P_CoEmCkg_bStaRstrtReq_CoEmCkg_bStaRstrtReq(CoEmCkg_bStaRstrtReq_out);
  (void)Rte_Write_P_CoEmCkg_bStaStrtReq_CoEmCkg_bStaStrtReq(CoEmCkg_bStaStrtReq_out);
  (void)Rte_Write_P_CoEmCkg_bVldFastN_CoEmCkg_bVldFastN(CoEmCkg_bVldFastN_out);
  (void)Rte_Write_P_CoEmCkg_bWaitStrtReq_CoEmCkg_bWaitStrtReq(CoEmCkg_bWaitStrtReq_out);
  (void)Rte_Write_P_CoEmCkg_nFast_CoEmCkg_nFast(CoEmCkg_nFast_out);
  (void)Rte_Write_P_CoEmCkg_stRstrtTyp_CoEmCkg_stRstrtTyp(CoEmCkg_stRstrtTyp_out);
  (void)Rte_Write_P_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(CoEmCkg_stStrtRstrtFbCmd_out);
  (void)Rte_Write_P_CoEmCkg_bRvAltPrepRstrtReq_CoEmCkg_bRvAltPrepRstrtReq(CoEmCkg_bRvAltPrepRstrtReq_out);
  (void)Rte_Write_P_CoEmCkg_bRvAltRstrtReq_CoEmCkg_bRvAltRstrtReq(CoEmCkg_bRvAltRstrtReq_out);
  (void)Rte_Write_P_CoEmCkg_nStaEgdHiThd_CoEmCkg_nStaEgdHiThd(CoEmCkg_nStaEgdHiThd_out);
  (void)Rte_Write_P_CoEmCkg_nStaEgdLoThd_CoEmCkg_nStaEgdLoThd(CoEmCkg_nStaEgdLoThd_out);
  (void)Rte_Write_P_CoEmCkg_stSTTCf_CoEmCkg_stSTTCf(CoEmCkg_stSTTCf_out);
  (void)Rte_Write_P_CoEmCkg_tiStaEgdHiThd_CoEmCkg_tiStaEgdHiThd(CoEmCkg_tiStaEgdHiThd_out);
  (void)Rte_Write_P_CoEmCkg_tiStaEgdLoThd_CoEmCkg_tiStaEgdLoThd(CoEmCkg_tiStaEgdLoThd_out);
  (void)Rte_Write_P_CoEmCkg_bReqAltBoostFil_CoEmCkg_bReqAltBoostFil(CoEmCkg_bReqAltBoostFil_out);
  (void)Rte_Write_P_CoEmCkg_stReqAltBoost_CoEmCkg_stReqAltBoost(CoEmCkg_stReqAltBoost_out);

}

void RE_StopStrtEm_003_MSE(void)
{


      StopStrtEm_003_MSE_ini();

      (void)Rte_Write_P_StaStrtMgt_bPwrAcvReq_StaStrtMgt_bPwrAcvReq(0);
      (void)Rte_Write_P_StaStrtMgt_bStaReq_StaStrtMgt_bStaReq(0);
      (void)Rte_Write_P_StaStrtMgt_tiStaAcvCnt_StaStrtMgt_tiStaAcvCnt(0);
      (void)Rte_Write_P_StaStrtMgt_ctStaAcv_StaStrtMgt_ctStaAcv(0);
      (void)Rte_Write_P_StaStrtMgt_ctStaRstrtAcv_StaStrtMgt_ctStaRstrtAcv(0);
      (void)Rte_Write_P_StaStrtMgt_ctStaStrtAcv_StaStrtMgt_ctStaStrtAcv(0);
      (void)Rte_Write_P_StaStrtMgt_stStaStrtFbCmd_StaStrtMgt_stStaStrtFbCmd(0);
      (void)Rte_Write_P_StaStrtMgt_bStrtProt10_StaStrtMgt_bStrtProt10(0);
      (void)Rte_Write_P_StaStrtMgt_stStaFbCmd_StaStrtMgt_stStaFbCmd(0);
      (void)Rte_Write_P_StaStrtMgt_bDmgLimStopInh_StaStrtMgt_bDmgLimStopInh(0);
      (void)Rte_Write_P_StaStrtMgt_tiMaxAcv_StaStrtMgt_tiMaxAcv(0);

}

void RE_StopStrtEm_004_TEV(void)
{

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstReq_ctStaAcv_Afts_bRstReq_ctStaAcv(&StopStrtEm_004_Afts_bRstReq_ctStaAcv_in);
      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEm_004_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&StopStrtEm_004_Ext_bSTTCf_in);
      (void)Rte_Read_R_Ext_stStaCf_Ext_stStaCf(&StopStrtEm_004_Ext_stStaCf_in);
      (void)Rte_Read_R_StaRstrtMgt_bInfoStaRun_StaRstrtMgt_bInfoStaRun(&StopStrtEm_004_StaRstrtMgt_bInfoStaRun_in);
      (void)Rte_Read_R_CoEmCkg_bStaStrtReq_CoEmCkg_bStaStrtReq(&StopStrtEm_004_CoEmCkg_bStaStrtReq_in);
      (void)Rte_Read_R_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(&StopStrtEm_004_CoEmSTT_bVSSAcvSt_in);
      (void)Rte_Read_R_CoSync_bStuckEngStaAcv_CoSync_bStuckEngStaAcv(&StopStrtEm_004_CoSync_bStuckEngStaAcv_in);
      (void)Rte_Read_R_Ext_bAcvSta_Ext_bAcvSta(&StopStrtEm_004_Ext_bAcvSta_in);
      (void)Rte_Read_R_Ext_bArchiCf_Ext_bArchiCf(&StopStrtEm_004_Ext_bArchiCf_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEm_004_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&StopStrtEm_004_Ext_stFuTypCf_in);
      (void)Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&StopStrtEm_004_Ext_stVSSCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&StopStrtEm_004_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_uBattMes_Ext_uBattMes(&StopStrtEm_004_Ext_uBattMes_in);
      (void)Rte_Read_R_StaRstrtMgt_bStaReq_StaRstrtMgt_bStaReq(&StopStrtEm_004_StaRstrtMgt_bStaReq_in);
      (void)Rte_Read_R_CoEmCkg_bVldFastN_CoEmCkg_bVldFastN(&StopStrtEm_004_CoEmCkg_bVldFastN_in);
      (void)Rte_Read_R_CoEmCkg_nFast_CoEmCkg_nFast(&StopStrtEm_004_CoEmCkg_nFast_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&StopStrtEm_004_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_StaRstrtMgt_stStaRstrtFbCmd_StaRstrtMgt_stStaRstrtFbCmd(&StopStrtEm_004_StaRstrtMgt_stStaRstrtFbCmd_in);
      (void)Rte_Read_R_CoStrtRStrt_bInh_CoStrtRStrt_bInh(&StopStrtEm_004_CoStrtRStrt_bInh_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&StopStrtEm_004_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_ctDay_Ext_ctDay(&StopStrtEm_004_Ext_ctDay_in);
      (void)Rte_Read_R_Ext_ctYr_Ext_ctYr(&StopStrtEm_004_Ext_ctYr_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&StopStrtEm_004_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_StaRstrtMgt_bDftElCmd_StaRstrtMgt_bDftElCmd(&StopStrtEm_004_StaRstrtMgt_bDftElCmd_in);
      (void)Rte_Read_R_StaRstrtMgt_bRstrtProt4_StaRstrtMgt_bRstrtProt4(&StopStrtEm_004_StaRstrtMgt_bRstrtProt4_in);
      (void)Rte_Read_R_CoEmCkg_stSTTCf_CoEmCkg_stSTTCf(&StopStrtEm_004_CoEmCkg_stSTTCf_in);
      (void)Rte_Read_R_Ext_bStaCmdFctSt_Ext_bStaCmdFctSt(&StopStrtEm_004_Ext_bStaCmdFctSt_in);
      (void)Rte_Read_R_Ext_ctSec_Ext_ctSec(&StopStrtEm_004_Ext_ctSec_in);

      Rte_Call_R_FRM_bAcvStaStrtMgtDftValThd_GetFunctionPermission(& StopStrtEm_004_FRM_bAcvStaStrtMgtDftValThd_in);
      StopStrtEm_004_FRM_bAcvStaStrtMgtDftValThd_in = !StopStrtEm_004_FRM_bAcvStaStrtMgtDftValThd_in;
      Rte_Call_R_FRM_bAcvStaStrtMgtDiagElCmd_GetFunctionPermission(& StopStrtEm_004_FRM_bAcvStaStrtMgtDiagElCmd_in);
      StopStrtEm_004_FRM_bAcvStaStrtMgtDiagElCmd_in = !StopStrtEm_004_FRM_bAcvStaStrtMgtDiagElCmd_in;
      Rte_Call_R_FRM_bInhStaStrtMgtVoltFall_GetFunctionPermission(& StopStrtEm_004_FRM_bInhStaStrtMgtVoltFall_in);
      StopStrtEm_004_FRM_bInhStaStrtMgtVoltFall_in = !StopStrtEm_004_FRM_bInhStaStrtMgtVoltFall_in;
      Rte_Call_R_FRM_bInhStaStrtMgtDmgTiCnt_GetFunctionPermission(& StopStrtEm_004_FRM_bInhStaStrtMgtDmgTiCnt_in);
      StopStrtEm_004_FRM_bInhStaStrtMgtDmgTiCnt_in = !StopStrtEm_004_FRM_bInhStaStrtMgtDmgTiCnt_in;
      Rte_Call_R_FRM_bInhStaStrtMgtDmgVehDst_GetFunctionPermission(& StopStrtEm_004_FRM_bInhStaStrtMgtDmgVehDst_in);
      StopStrtEm_004_FRM_bInhStaStrtMgtDmgVehDst_in = !StopStrtEm_004_FRM_bInhStaStrtMgtDmgVehDst_in;
      StopStrtEm_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      StaStrtMgt_bPwrAcvReq_out = StaStrtMgt_bPwrAcvReq_B;
      StaStrtMgt_bStaReq_out = StaStrtMgt_bStaReq_B;
      StaStrtMgt_tiStaAcvCnt_out = StaStrtMgt_tiStaAcvCnt_B;
      StaStrtMgt_ctStaAcv_out = StaStrtMgt_ctStaAcv_B;
      StaStrtMgt_ctStaRstrtAcv_out = StaStrtMgt_ctStaRstrtAcv_B;
      StaStrtMgt_ctStaStrtAcv_out = StaStrtMgt_ctStaStrtAcv_B;
      StaStrtMgt_stStaStrtFbCmd_out = StaStrtMgt_stStaStrtFbCmd_B;
      StaStrtMgt_bStrtProt10_out = StaStrtMgt_bStrtProt10_B;
      StaStrtMgt_stStaFbCmd_out = StaStrtMgt_stStaFbCmd_B;
      StaStrtMgt_bDmgLimStopInh_out = StaStrtMgt_bDmgLimStopInh_B;
      StaStrtMgt_tiMaxAcv_out = StaStrtMgt_tiMaxAcv_B;
  }
  (void)Rte_Write_P_StaStrtMgt_bPwrAcvReq_StaStrtMgt_bPwrAcvReq(StaStrtMgt_bPwrAcvReq_out);
  (void)Rte_Write_P_StaStrtMgt_bStaReq_StaStrtMgt_bStaReq(StaStrtMgt_bStaReq_out);
  (void)Rte_Write_P_StaStrtMgt_tiStaAcvCnt_StaStrtMgt_tiStaAcvCnt(StaStrtMgt_tiStaAcvCnt_out);
  (void)Rte_Write_P_StaStrtMgt_ctStaAcv_StaStrtMgt_ctStaAcv(StaStrtMgt_ctStaAcv_out);
  (void)Rte_Write_P_StaStrtMgt_ctStaRstrtAcv_StaStrtMgt_ctStaRstrtAcv(StaStrtMgt_ctStaRstrtAcv_out);
  (void)Rte_Write_P_StaStrtMgt_ctStaStrtAcv_StaStrtMgt_ctStaStrtAcv(StaStrtMgt_ctStaStrtAcv_out);
  (void)Rte_Write_P_StaStrtMgt_stStaStrtFbCmd_StaStrtMgt_stStaStrtFbCmd(StaStrtMgt_stStaStrtFbCmd_out);
  (void)Rte_Write_P_StaStrtMgt_bStrtProt10_StaStrtMgt_bStrtProt10(StaStrtMgt_bStrtProt10_out);
  (void)Rte_Write_P_StaStrtMgt_stStaFbCmd_StaStrtMgt_stStaFbCmd(StaStrtMgt_stStaFbCmd_out);
  (void)Rte_Write_P_StaStrtMgt_bDmgLimStopInh_StaStrtMgt_bDmgLimStopInh(StaStrtMgt_bDmgLimStopInh_out);
  (void)Rte_Write_P_StaStrtMgt_tiMaxAcv_StaStrtMgt_tiMaxAcv(StaStrtMgt_tiMaxAcv_out);

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StaCmd */
     if(StaStrtMgt_bMonRunStaCmd_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStaCmd_out==1)
         {
             Rte_Call_R_StaStrtMgt_StaCmd_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StaCmd_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStaCmd_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StaCmd_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStaCmd_out_prec = StaStrtMgt_bMonRunStaCmd_out;
  }

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StaElCmd */
     if(StaStrtMgt_bMonRunStaElCmd_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStaElCmd_out==1)
         {
             Rte_Call_R_StaStrtMgt_StaElCmd_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StaElCmd_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStaElCmd_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StaElCmd_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStaElCmd_out_prec = StaStrtMgt_bMonRunStaElCmd_out;
  }

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StuckMec */
     if(StaStrtMgt_bMonRunStuckMec_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStuckMec_out==1)
         {
             Rte_Call_R_StaStrtMgt_StuckMec_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StuckMec_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStuckMec_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StuckMec_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStuckMec_out_prec = StaStrtMgt_bMonRunStuckMec_out;
  }

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StaAcvThd1 */
     if(StaStrtMgt_bMonRunStaAcvThd1_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStaAcvThd1_out==1)
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd1_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd1_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStaAcvThd1_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd1_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStaAcvThd1_out_prec = StaStrtMgt_bMonRunStaAcvThd1_out;
  }

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StaAcvThd2 */
     if(StaStrtMgt_bMonRunStaAcvThd2_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStaAcvThd2_out==1)
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd2_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd2_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStaAcvThd2_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StaAcvThd2_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStaAcvThd2_out_prec = StaStrtMgt_bMonRunStaAcvThd2_out;
  }

  if (FALSE == RE_STOPSTRTEM_004_TEV_B)
  {

  /* Diag treatment : StopStrtEm_StaCmdInfo */
     if(StaStrtMgt_bMonRunStaCmdInfo_out==1)
     {
         /* Diag activation */
         if(StaStrtMgt_bDgoStaCmdInfo_out==1)
         {
             Rte_Call_R_StaStrtMgt_StaCmdInfo_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_StaStrtMgt_StaCmdInfo_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (StaStrtMgt_bMonRunStaCmdInfo_out_prec==1)
         {
             Rte_Call_R_StaStrtMgt_StaCmdInfo_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     StaStrtMgt_bMonRunStaCmdInfo_out_prec = StaStrtMgt_bMonRunStaCmdInfo_out;
  }

}

void RE_StopStrtEm_005_MSE(void)
{


      StopStrtEm_005_MSE_ini();

      (void)Rte_Write_P_StaRstrtMgt_bInfoCplReq_StaRstrtMgt_bInfoCplReq(0);
      (void)Rte_Write_P_StaRstrtMgt_bInfoCplSt_StaRstrtMgt_bInfoCplSt(0);
      (void)Rte_Write_P_StaRstrtMgt_bInfoStaRun_StaRstrtMgt_bInfoStaRun(0);
      (void)Rte_Write_P_StaRstrtMgt_bStaReq_StaRstrtMgt_bStaReq(0);
      (void)Rte_Write_P_StaRstrtMgt_bDftElCmd_StaRstrtMgt_bDftElCmd(0);
      (void)Rte_Write_P_StaRstrtMgt_bProt10StopInh_StaRstrtMgt_bProt10StopInh(0);
      (void)Rte_Write_P_StaRstrtMgt_bRstrtProt4_StaRstrtMgt_bRstrtProt4(0);
      (void)Rte_Write_P_StaRstrtMgt_nStaEgdHiThd_StaRstrtMgt_nStaEgdHiThd(0);
      (void)Rte_Write_P_StaRstrtMgt_nStaEgdLoThd_StaRstrtMgt_nStaEgdLoThd(0);
      (void)Rte_Write_P_StaRstrtMgt_stStaRstrtFbCmd_StaRstrtMgt_stStaRstrtFbCmd(0);
      (void)Rte_Write_P_StaRstrtMgt_tiStaEgdHiThd_StaRstrtMgt_tiStaEgdHiThd(60);
      (void)Rte_Write_P_StaRstrtMgt_tiStaEgdLoThd_StaRstrtMgt_tiStaEgdLoThd(30);
      (void)Rte_Write_P_StaRstrtMgt_bRstrtProt10_StaRstrtMgt_bRstrtProt10(0);

}

void RE_StopStrtEm_006_TEV(void)
{

  if (FALSE == RE_STOPSTRTEM_006_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEm_006_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&StopStrtEm_006_Ext_bSTTCf_in);
      (void)Rte_Read_R_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(&StopStrtEm_006_CoEmSTT_bVSSAcvSt_in);
      (void)Rte_Read_R_CoSync_bStuckEngStaAcv_CoSync_bStuckEngStaAcv(&StopStrtEm_006_CoSync_bStuckEngStaAcv_in);
      (void)Rte_Read_R_Ext_bArchiCf_Ext_bArchiCf(&StopStrtEm_006_Ext_bArchiCf_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEm_006_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&StopStrtEm_006_Ext_stFuTypCf_in);
      (void)Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&StopStrtEm_006_Ext_stVSSCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&StopStrtEm_006_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_uBattMes_Ext_uBattMes(&StopStrtEm_006_Ext_uBattMes_in);
      (void)Rte_Read_R_CoEmCkg_bDetSlowN_CoEmCkg_bDetSlowN(&StopStrtEm_006_CoEmCkg_bDetSlowN_in);
      (void)Rte_Read_R_CoEmCkg_bStaRstrtReq_CoEmCkg_bStaRstrtReq(&StopStrtEm_006_CoEmCkg_bStaRstrtReq_in);
      (void)Rte_Read_R_CoEmCkg_bVldFastN_CoEmCkg_bVldFastN(&StopStrtEm_006_CoEmCkg_bVldFastN_in);
      (void)Rte_Read_R_CoEmCkg_nFast_CoEmCkg_nFast(&StopStrtEm_006_CoEmCkg_nFast_in);
      (void)Rte_Read_R_StaStrtMgt_tiStaAcvCnt_StaStrtMgt_tiStaAcvCnt(&StopStrtEm_006_StaStrtMgt_tiStaAcvCnt_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&StopStrtEm_006_Eng_nCkFil_in);
      (void)Rte_Read_R_StaStrtMgt_ctStaAcv_StaStrtMgt_ctStaAcv(&StopStrtEm_006_StaStrtMgt_ctStaAcv_in);
      (void)Rte_Read_R_StaStrtMgt_tiMaxAcv_StaStrtMgt_tiMaxAcv(&StopStrtEm_006_StaStrtMgt_tiMaxAcv_in);

      Rte_Call_R_FRM_bAcvStaRstrtMgtDftValThd_GetFunctionPermission(& StopStrtEm_006_FRM_bAcvStaRstrtMgtDftValThd_in);
      StopStrtEm_006_FRM_bAcvStaRstrtMgtDftValThd_in = !StopStrtEm_006_FRM_bAcvStaRstrtMgtDftValThd_in;
      Rte_Call_R_FRM_bAcvStaRstrtMgtDiagElCmd_GetFunctionPermission(& StopStrtEm_006_FRM_bAcvStaRstrtMgtDiagElCmd_in);
      StopStrtEm_006_FRM_bAcvStaRstrtMgtDiagElCmd_in = !StopStrtEm_006_FRM_bAcvStaRstrtMgtDiagElCmd_in;
      Rte_Call_R_FRM_bInhStaRstrtMgtVoltFall_GetFunctionPermission(& StopStrtEm_006_FRM_bInhStaRstrtMgtVoltFall_in);
      StopStrtEm_006_FRM_bInhStaRstrtMgtVoltFall_in = !StopStrtEm_006_FRM_bInhStaRstrtMgtVoltFall_in;
      StopStrtEm_006_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      StaRstrtMgt_bInfoCplReq_out = StaRstrtMgt_bInfoCplReq_B;
      StaRstrtMgt_bInfoCplSt_out = StaRstrtMgt_bInfoCplSt_B;
      StaRstrtMgt_bInfoStaRun_out = StaRstrtMgt_bInfoStaRun_B;
      StaRstrtMgt_bStaReq_out = StaRstrtMgt_bStaReq_B;
      StaRstrtMgt_bDftElCmd_out = StaRstrtMgt_bDftElCmd_B;
      StaRstrtMgt_bProt10StopInh_out = StaRstrtMgt_bProt10StopInh_B;
      StaRstrtMgt_bRstrtProt4_out = StaRstrtMgt_bRstrtProt4_B;
      StaRstrtMgt_nStaEgdHiThd_out = StaRstrtMgt_nStaEgdHiThd_B;
      StaRstrtMgt_nStaEgdLoThd_out = StaRstrtMgt_nStaEgdLoThd_B;
      StaRstrtMgt_stStaRstrtFbCmd_out = StaRstrtMgt_stStaRstrtFbCmd_B;
      StaRstrtMgt_tiStaEgdHiThd_out = StaRstrtMgt_tiStaEgdHiThd_B;
      StaRstrtMgt_tiStaEgdLoThd_out = StaRstrtMgt_tiStaEgdLoThd_B;
      StaRstrtMgt_bRstrtProt10_out = StaRstrtMgt_bRstrtProt10_B;
  }
  (void)Rte_Write_P_StaRstrtMgt_bInfoCplReq_StaRstrtMgt_bInfoCplReq(StaRstrtMgt_bInfoCplReq_out);
  (void)Rte_Write_P_StaRstrtMgt_bInfoCplSt_StaRstrtMgt_bInfoCplSt(StaRstrtMgt_bInfoCplSt_out);
  (void)Rte_Write_P_StaRstrtMgt_bInfoStaRun_StaRstrtMgt_bInfoStaRun(StaRstrtMgt_bInfoStaRun_out);
  (void)Rte_Write_P_StaRstrtMgt_bStaReq_StaRstrtMgt_bStaReq(StaRstrtMgt_bStaReq_out);
  (void)Rte_Write_P_StaRstrtMgt_bDftElCmd_StaRstrtMgt_bDftElCmd(StaRstrtMgt_bDftElCmd_out);
  (void)Rte_Write_P_StaRstrtMgt_bProt10StopInh_StaRstrtMgt_bProt10StopInh(StaRstrtMgt_bProt10StopInh_out);
  (void)Rte_Write_P_StaRstrtMgt_bRstrtProt4_StaRstrtMgt_bRstrtProt4(StaRstrtMgt_bRstrtProt4_out);
  (void)Rte_Write_P_StaRstrtMgt_nStaEgdHiThd_StaRstrtMgt_nStaEgdHiThd(StaRstrtMgt_nStaEgdHiThd_out);
  (void)Rte_Write_P_StaRstrtMgt_nStaEgdLoThd_StaRstrtMgt_nStaEgdLoThd(StaRstrtMgt_nStaEgdLoThd_out);
  (void)Rte_Write_P_StaRstrtMgt_stStaRstrtFbCmd_StaRstrtMgt_stStaRstrtFbCmd(StaRstrtMgt_stStaRstrtFbCmd_out);
  (void)Rte_Write_P_StaRstrtMgt_tiStaEgdHiThd_StaRstrtMgt_tiStaEgdHiThd(StaRstrtMgt_tiStaEgdHiThd_out);
  (void)Rte_Write_P_StaRstrtMgt_tiStaEgdLoThd_StaRstrtMgt_tiStaEgdLoThd(StaRstrtMgt_tiStaEgdLoThd_out);
  (void)Rte_Write_P_StaRstrtMgt_bRstrtProt10_StaRstrtMgt_bRstrtProt10(StaRstrtMgt_bRstrtProt10_out);

}

#define STOPSTRTEM_STOP_SEC_CODE
#include "StopStrtEm_MemMap.h"

#endif/*_STOPSTRTEM_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

