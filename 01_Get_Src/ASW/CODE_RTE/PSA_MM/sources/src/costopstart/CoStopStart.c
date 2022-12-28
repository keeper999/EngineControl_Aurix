/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoStopStart.c
* Description   : Interface AUTOSAR du module CoStopStart avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 24-Apr-2013(10:28:53)
*******************************************************************************/

#ifndef _COSTOPSTART_C_
#define _COSTOPSTART_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_CoStopStart.h"
#include "CoStopStart.h"
#include "CoStopStart_004_TEV_fct.h"
#include "CoStopStart_008_TEV_fct.h"
#include "CoStopStart_010_TEV_fct.h"
#include "CoStopStart_012_TEV_fct.h"
#include "CoStopStart_014_TEV_fct.h"
#include "CoStopStart_016_TEV_fct.h"
#include "CoStopStart_018_TEV_fct.h"
#include "CoStopStart_020_TEV_fct.h"
#include "CoStopStart_022_TEV_fct.h"
#include "CoStopStart_024_TEV_fct.h"
#include "CoStopStart_026_TEV_fct.h"
#include "CoStopStart_028_TEV_fct.h"
#include "CoStopStart_030_TEV_fct.h"
#include "CoStopStart_032_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoStopStart_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoStopStart_ModuleVersion_Major_MP = 12;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoStopStart_ModuleVersion_Minor_MP = 1;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoStopStart_ModuleVersion_Build_MP = 0;
#define COSTOPSTART_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 5
#define Module_LIB_PSA_VERSION_REQ_MIN 5

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_008_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_010_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_012_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_014_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_016_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_018_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_020_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_022_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_024_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_026_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_028_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_030_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_032_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltInh_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltPrepRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltRPosnEngReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltStallReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCdnInhRStrt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCompTqRStrt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseClsTra_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseLongGc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseRCfTyp3_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngCutOffReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngStopReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bFbSpcFactSTTReq1_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bFbSpcFactSTTReq2_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInfoAcvCluPed_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInfoRdy_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bLatchDrvCyc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRecNotStop_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtAnt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bStPresLo_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bSTTInh_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bOpDrvTraReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCtlDmprAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseAutRStrt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseElMecRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseNotRStrtAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseSpdMax_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseVehRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngStallReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bLimFreqStopInh_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtReqAvl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtReqDgoBlt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtTypAT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bTestPrvtBltAcv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bVSSNwAcvAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bAuthSA_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bEngRStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bEngStopAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseDgoBlt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseRStrtReqForc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bBltStopAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtMchAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bStopAuthSlop_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bDrvTraOp_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRstrtCritAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngRstrtClsCluCdn_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInhHiSpdAltRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bNotBlsVehReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bRstrtAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAcvGSINeut_B = 0;
#define COSTOPSTART_STOP_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_noGearTmpBeg_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_noGearTmpEnd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stSTTLightAcv_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stPwt_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stMaxRStrtReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stTypSTTNotAvl_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_tiCmplStop_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stTestPosClu_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stAftsRStrtSuc_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stFbSpcFactRStrtSuc_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stBfLstRStrtFailCase_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stLstRStrtFailCase_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoReqRStrt_stRStrtTyp_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stBfBfLstRStrtFail_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_pRelBrkAsi_B = 2;
#define COSTOPSTART_STOP_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_nEngClc_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_rMaxCluGc_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_rMinCluRStrt_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_tiNbRstrtFreqLim_B = 0;
#define COSTOPSTART_STOP_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_VAR_BOOLEAN
#include "CoStopStart_MemMap.h"
static Boolean CoPtUH_bMonRunCutReq_out_prec;
static Boolean CoPtUH_bMonRunLgEngRStrtInh_out_prec;
static Boolean CoPtUH_bMonRunBlt_out_prec;
static Boolean CoPtUH_bMonRunORngGcClu_out_prec;
static Boolean CoPtUH_bMonRunORngGcNeut_out_prec;
static Boolean CoPtUH_bMonRunORngGearEnaClu_out_prec;
static Boolean CoPtUH_bMonRunORngGearNeut_out_prec;
static Boolean CoPtUH_bMonRunORngGcMinClu_out_prec;
static Boolean CoPtUH_bMonRunORngGearMinClu_out_prec;
#define COSTOPSTART_STOP_SEC_VAR_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_CODE
#include "CoStopStart_MemMap.h"

void RE_CoStopStart_003_MSE(void)
{


      CoStopStart_003_MSE_ini();

      (void)Rte_Write_P_CoReqRStrt_bAuthSA_CoReqRStrt_bAuthSA(0);
      (void)Rte_Write_P_CoReqRStrt_bEngRStrtReq_CoReqRStrt_bEngRStrtReq(0);
      (void)Rte_Write_P_CoReqRStrt_bEngStopAuth_CoReqRStrt_bEngStopAuth(0);
      (void)Rte_Write_P_CoReqRStrt_stRStrtTyp_CoReqRStrt_stRStrtTyp(0);
      (void)Rte_Write_P_CoReqRStrt_bNotBlsVehReq_CoReqRStrt_bNotBlsVehReq(0);
      (void)Rte_Write_P_CoReqRStrt_bRstrtAuth_CoReqRStrt_bRstrtAuth(1);

}

void RE_CoStopStart_004_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&CoStopStart_004_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_004_Veh_spdVeh_in);
      (void)Rte_Read_R_BatMgt_resBattIt_BatMgt_resBattIt(&CoStopStart_004_BatMgt_resBattIt_in);
      (void)Rte_Read_R_BatMgt_uBattOc_BatMgt_uBattOc(&CoStopStart_004_BatMgt_uBattOc_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&CoStopStart_004_Ext_pAirExtMes_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&CoStopStart_004_Ext_tCoMes_in);
      (void)Rte_Read_R_PredEs_agEs_PredEs_agEs(&CoStopStart_004_PredEs_agEs_in);
      (void)Rte_Read_R_PredEs_agUncrtEs_PredEs_agUncrtEs(&CoStopStart_004_PredEs_agUncrtEs_in);
      (void)Rte_Read_R_VSSCtzMgt_uUcapMes_VSSCtzMgt_uUcapMes(&CoStopStart_004_VSSCtzMgt_uUcapMes_in);
      (void)Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&CoStopStart_004_CoSync_bDetNNull_in);
      (void)Rte_Read_R_CoEmSTT_iElNwStop_CoEmSTT_iElNwStop(&CoStopStart_004_CoEmSTT_iElNwStop_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&CoStopStart_004_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(&CoStopStart_004_CoPtUH_bDrvTraOp_in);
      (void)Rte_Read_R_CoSync_bAgEsCfm_CoSync_bAgEsCfm(&CoStopStart_004_CoSync_bAgEsCfm_in);
      (void)Rte_Read_R_Ext_bNotAvl_resBattIt_Ext_bNotAvl_resBattIt(&CoStopStart_004_Ext_bNotAvl_resBattIt_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattOc_Ext_bNotAvl_uBattOc(&CoStopStart_004_Ext_bNotAvl_uBattOc_in);
      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&CoStopStart_004_Ext_tOilMes_in);
      (void)Rte_Read_R_PredEs_nFast_PredEs_nFast(&CoStopStart_004_PredEs_nFast_in);
      (void)Rte_Read_R_PredRstrt_noTDC_PredRstrt_noTDC(&CoStopStart_004_PredRstrt_noTDC_in);
      (void)Rte_Read_R_PredRstrt_tiMax2TDC_PredRstrt_tiMax2TDC(&CoStopStart_004_PredRstrt_tiMax2TDC_in);
      (void)Rte_Read_R_RvAltMgt_tRvAltStatEstim_RvAltMgt_tRvAltStatEstim(&CoStopStart_004_RvAltMgt_tRvAltStatEstim_in);
      (void)Rte_Read_R_Sync_agEng_Sync_agEng(&CoStopStart_004_Sync_agEng_in);
      (void)Rte_Read_R_TqLimUH_stDrivTyp_TqLimUH_stDrivTyp(&CoStopStart_004_TqLimUH_stDrivTyp_in);
      (void)Rte_Read_R_Afts_bRstMemCoReqRStrt_Afts_bRstMemCoReqRStrt(&CoStopStart_004_Afts_bRstMemCoReqRStrt_in);
      (void)Rte_Read_R_CoPtUH_bRstrtCritAuth_CoPtUH_bRstrtCritAuth(&CoStopStart_004_CoPtUH_bRstrtCritAuth_in);
      (void)Rte_Read_R_CoOptmEl_stElEProv_CoOptmEl_stElEProv(&CoStopStart_004_CoOptmEl_stElEProv_in);

      CoStopStart_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoReqRStrt_bAuthSA_out = CoReqRStrt_bAuthSA_B;
      CoReqRStrt_bEngRStrtReq_out = CoReqRStrt_bEngRStrtReq_B;
      CoReqRStrt_bEngStopAuth_out = CoReqRStrt_bEngStopAuth_B;
      CoReqRStrt_stRStrtTyp_out = CoReqRStrt_stRStrtTyp_B;
      CoReqRStrt_bNotBlsVehReq_out = CoReqRStrt_bNotBlsVehReq_B;
      CoReqRStrt_bRstrtAuth_out = CoReqRStrt_bRstrtAuth_B;
  }
  (void)Rte_Write_P_CoReqRStrt_bAuthSA_CoReqRStrt_bAuthSA(CoReqRStrt_bAuthSA_out);
  (void)Rte_Write_P_CoReqRStrt_bEngRStrtReq_CoReqRStrt_bEngRStrtReq(CoReqRStrt_bEngRStrtReq_out);
  (void)Rte_Write_P_CoReqRStrt_bEngStopAuth_CoReqRStrt_bEngStopAuth(CoReqRStrt_bEngStopAuth_out);
  (void)Rte_Write_P_CoReqRStrt_stRStrtTyp_CoReqRStrt_stRStrtTyp(CoReqRStrt_stRStrtTyp_out);
  (void)Rte_Write_P_CoReqRStrt_bNotBlsVehReq_CoReqRStrt_bNotBlsVehReq(CoReqRStrt_bNotBlsVehReq_out);
  (void)Rte_Write_P_CoReqRStrt_bRstrtAuth_CoReqRStrt_bRstrtAuth(CoReqRStrt_bRstrtAuth_out);

}

void RE_CoStopStart_007_MSE(void)
{


      CoStopStart_007_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_007_MSE_CoCut_bRstrtFail(0);
  (void)Rte_IrvWrite_RE_CoStopStart_007_MSE_CoCut_ctForcRstrtFail(0);
  (void)Rte_IrvWrite_RE_CoStopStart_007_MSE_CoCut_ctRstrtFail(0);
  (void)Rte_IrvWrite_RE_CoStopStart_007_MSE_CoCut_bElMecIntrRstrt(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseClsTra_CoPtUH_bCutCaseClsTra(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseLongGc_CoPtUH_bCutCaseLongGc(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseRCfTyp3_CoPtUH_bCutCaseRCfTyp3(0);
      (void)Rte_Write_P_CoPtUH_bEngCutOffReq_CoPtUH_bEngCutOffReq(0);
      (void)Rte_Write_P_CoPtUH_stBfLstRStrtFailCase_CoPtUH_stBfLstRStrtFailCase(0);
      (void)Rte_Write_P_CoPtUH_stLstRStrtFailCase_CoPtUH_stLstRStrtFailCase(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseAutRStrt_CoPtUH_bCutCaseAutRStrt(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseElMecRStrtReq_CoPtUH_bCutCaseElMecRStrtReq(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseNotRStrtAuth_CoPtUH_bCutCaseNotRStrtAuth(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseSpdMax_CoPtUH_bCutCaseSpdMax(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseVehRStrtReq_CoPtUH_bCutCaseVehRStrtReq(0);
      (void)Rte_Write_P_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseDgoBlt_CoPtUH_bCutCaseDgoBlt(0);
      (void)Rte_Write_P_CoPtUH_bCutCaseRStrtReqForc_CoPtUH_bCutCaseRStrtReqForc(0);
      (void)Rte_Write_P_CoPtUH_stBfBfLstRStrtFail_CoPtUH_stBfBfLstRStrtFail(0);

}

void RE_CoStopStart_008_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_008_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&CoStopStart_008_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoSync_bStuckEngStaAcv_CoSync_bStuckEngStaAcv(&CoStopStart_008_CoSync_bStuckEngStaAcv_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoStopStart_008_Ext_nEng_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_008_Veh_spdVeh_in);
      (void)Rte_Read_R_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(&CoStopStart_008_CoEmSTT_stEngRStrtReq_in);
      (void)Rte_Read_R_CoReqVeh_stEngRStrtReq_CoReqVeh_stEngRStrtReq(&CoStopStart_008_CoReqVeh_stEngRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_bRStrtMchAuth_CoPtUH_bRStrtMchAuth(&CoStopStart_008_CoPtUH_bRStrtMchAuth_in);
      (void)Rte_Read_R_CoPtUH_bRStrtReqAvl_CoPtUH_bRStrtReqAvl(&CoStopStart_008_CoPtUH_bRStrtReqAvl_in);
      (void)Rte_Read_R_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(&CoStopStart_008_CoPtUH_stMaxRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_008_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_008_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPtUH_bInhHiSpdAltRstrtReq_CoPtUH_bInhHiSpdAltRstrtReq(&CoStopStart_008_CoPtUH_bInhHiSpdAltRstrtReq_in);
      (void)Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&CoStopStart_008_Ext_spdVehSecu_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_008_CoPTStNew_stEng_in);
      RE_CoStopStart_008_TEV_DgoFct_bHealDiagCfLvl1_in = Rte_IrvRead_RE_CoStopStart_008_TEV_DgoFct_bHealDiagCfLvl1();
      RE_CoStopStart_008_TEV_MgtDrv_bDftHld_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MgtDrv_bDftHld();
      RE_CoStopStart_008_TEV_MgtEng_bLgRstrt_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MgtEng_bLgRstrt();
      RE_CoStopStart_008_TEV_MonDrv_bRstrtAntCncl_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonDrv_bRstrtAntCncl();
      RE_CoStopStart_008_TEV_MonDrv_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonDrv_bRstrtReq();
      RE_CoStopStart_008_TEV_MonGB_bCutCaseLgGc_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonGB_bCutCaseLgGc();
      RE_CoStopStart_008_TEV_MonGB_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonGB_bRstrtAuth();
      RE_CoStopStart_008_TEV_MonVeh_bPresPtlRstrtReqForc_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonVeh_bPresPtlRstrtReqForc();
      RE_CoStopStart_008_TEV_MonVeh_bPtlVehRstrtReqForc_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonVeh_bPtlVehRstrtReqForc();
      RE_CoStopStart_008_TEV_MonVeh_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_008_TEV_MonVeh_bRstrtAuth();

      Rte_Call_R_FRM_bAcvCutCoPtUH_GetFunctionPermission(& CoStopStart_008_FRM_bAcvCutCoPtUH_in);
      CoStopStart_008_FRM_bAcvCutCoPtUH_in = !CoStopStart_008_FRM_bAcvCutCoPtUH_in;
      Rte_Call_R_FRM_bAcvCutTotCoPtUH_GetFunctionPermission(& CoStopStart_008_FRM_bAcvCutTotCoPtUH_in);
      CoStopStart_008_FRM_bAcvCutTotCoPtUH_in = !CoStopStart_008_FRM_bAcvCutTotCoPtUH_in;
      Rte_Call_R_FRM_bInhspdVehCoPtUH_GetFunctionPermission(& CoStopStart_008_FRM_bInhspdVehCoPtUH_in);
      CoStopStart_008_FRM_bInhspdVehCoPtUH_in = !CoStopStart_008_FRM_bInhspdVehCoPtUH_in;
      CoStopStart_008_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bCutCaseClsTra_out = CoPtUH_bCutCaseClsTra_B;
      CoPtUH_bCutCaseLongGc_out = CoPtUH_bCutCaseLongGc_B;
      CoPtUH_bCutCaseRCfTyp3_out = CoPtUH_bCutCaseRCfTyp3_B;
      CoPtUH_bEngCutOffReq_out = CoPtUH_bEngCutOffReq_B;
      CoPtUH_stBfLstRStrtFailCase_out = CoPtUH_stBfLstRStrtFailCase_B;
      CoPtUH_stLstRStrtFailCase_out = CoPtUH_stLstRStrtFailCase_B;
      CoPtUH_bCutCaseAutRStrt_out = CoPtUH_bCutCaseAutRStrt_B;
      CoPtUH_bCutCaseElMecRStrtReq_out = CoPtUH_bCutCaseElMecRStrtReq_B;
      CoPtUH_bCutCaseNotRStrtAuth_out = CoPtUH_bCutCaseNotRStrtAuth_B;
      CoPtUH_bCutCaseSpdMax_out = CoPtUH_bCutCaseSpdMax_B;
      CoPtUH_bCutCaseVehRStrtReq_out = CoPtUH_bCutCaseVehRStrtReq_B;
      CoPtUH_bEngStallReq_out = CoPtUH_bEngStallReq_B;
      CoPtUH_bCutCaseDgoBlt_out = CoPtUH_bCutCaseDgoBlt_B;
      CoPtUH_bCutCaseRStrtReqForc_out = CoPtUH_bCutCaseRStrtReqForc_B;
      CoPtUH_stBfBfLstRStrtFail_out = CoPtUH_stBfBfLstRStrtFail_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_008_TEV_CoCut_bRstrtFail(CoCut_bRstrtFail);
  (void)Rte_IrvWrite_RE_CoStopStart_008_TEV_CoCut_ctForcRstrtFail(CoCut_ctForcRstrtFail);
  (void)Rte_IrvWrite_RE_CoStopStart_008_TEV_CoCut_ctRstrtFail(CoCut_ctRstrtFail);
  (void)Rte_IrvWrite_RE_CoStopStart_008_TEV_CoCut_bElMecIntrRstrt(CoCut_bElMecIntrRstrt);
  (void)Rte_Write_P_CoPtUH_bCutCaseClsTra_CoPtUH_bCutCaseClsTra(CoPtUH_bCutCaseClsTra_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseLongGc_CoPtUH_bCutCaseLongGc(CoPtUH_bCutCaseLongGc_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseRCfTyp3_CoPtUH_bCutCaseRCfTyp3(CoPtUH_bCutCaseRCfTyp3_out);
  (void)Rte_Write_P_CoPtUH_bEngCutOffReq_CoPtUH_bEngCutOffReq(CoPtUH_bEngCutOffReq_out);
  (void)Rte_Write_P_CoPtUH_stBfLstRStrtFailCase_CoPtUH_stBfLstRStrtFailCase(CoPtUH_stBfLstRStrtFailCase_out);
  (void)Rte_Write_P_CoPtUH_stLstRStrtFailCase_CoPtUH_stLstRStrtFailCase(CoPtUH_stLstRStrtFailCase_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseAutRStrt_CoPtUH_bCutCaseAutRStrt(CoPtUH_bCutCaseAutRStrt_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseElMecRStrtReq_CoPtUH_bCutCaseElMecRStrtReq(CoPtUH_bCutCaseElMecRStrtReq_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseNotRStrtAuth_CoPtUH_bCutCaseNotRStrtAuth(CoPtUH_bCutCaseNotRStrtAuth_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseSpdMax_CoPtUH_bCutCaseSpdMax(CoPtUH_bCutCaseSpdMax_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseVehRStrtReq_CoPtUH_bCutCaseVehRStrtReq(CoPtUH_bCutCaseVehRStrtReq_out);
  (void)Rte_Write_P_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(CoPtUH_bEngStallReq_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseDgoBlt_CoPtUH_bCutCaseDgoBlt(CoPtUH_bCutCaseDgoBlt_out);
  (void)Rte_Write_P_CoPtUH_bCutCaseRStrtReqForc_CoPtUH_bCutCaseRStrtReqForc(CoPtUH_bCutCaseRStrtReqForc_out);
  (void)Rte_Write_P_CoPtUH_stBfBfLstRStrtFail_CoPtUH_stBfBfLstRStrtFail(CoPtUH_stBfBfLstRStrtFail_out);

  if (FALSE == RE_COSTOPSTART_008_TEV_B)
  {

  /* Diag treatment : CoStopStart_CutReq */
     if(CoPtUH_bMonRunCutReq_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoCutReq_out==1)
         {
             Rte_Call_R_CoPtUH_CutReq_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_CutReq_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunCutReq_out_prec==1)
         {
             Rte_Call_R_CoPtUH_CutReq_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunCutReq_out_prec = CoPtUH_bMonRunCutReq_out;
  }

}

void RE_CoStopStart_009_MSE(void)
{


      CoStopStart_009_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_009_MSE_CoRStrt_bRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_bRStrtReqAvl_CoPtUH_bRStrtReqAvl(0);
      (void)Rte_Write_P_CoPtUH_bRStrtTypAT_CoPtUH_bRStrtTypAT(0);
      (void)Rte_Write_P_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(0);

}

void RE_CoStopStart_010_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_010_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_010_Veh_spdVeh_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_010_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_010_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_tOilGBx_Ext_tOilGBx(&CoStopStart_010_Ext_tOilGBx_in);
      (void)Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&CoStopStart_010_Ext_spdVehSecu_in);
      RE_CoStopStart_010_TEV_MonDrv_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonDrv_bRstrtReq();
      RE_CoStopStart_010_TEV_MonGB_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonGB_bRstrtAuth();
      RE_CoStopStart_010_TEV_MonVeh_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonVeh_bRstrtAuth();
      RE_CoStopStart_010_TEV_DgoFct_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_DgoFct_stRstrtReq();
      RE_CoStopStart_010_TEV_MonDrv_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonDrv_stRstrtReq();
      RE_CoStopStart_010_TEV_MonEE_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonEE_stRstrtReq();
      RE_CoStopStart_010_TEV_MonEng_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonEng_stRstrtReq();
      RE_CoStopStart_010_TEV_MonGB_bMAPRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonGB_bMAPRstrtAuth();
      RE_CoStopStart_010_TEV_MonGB_bRstrtTypATReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonGB_bRstrtTypATReq();
      RE_CoStopStart_010_TEV_MonGB_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonGB_stRstrtReq();
      RE_CoStopStart_010_TEV_MonVeh_stRstrtReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonVeh_stRstrtReq();
      RE_CoStopStart_010_TEV_MonDrv_bRstrtAntReq_in = Rte_IrvRead_RE_CoStopStart_010_TEV_MonDrv_bRstrtAntReq();

      Rte_Call_R_FRM_bAcvRStrtCoPtUH_GetFunctionPermission(& CoStopStart_010_FRM_bAcvRStrtCoPtUH_in);
      CoStopStart_010_FRM_bAcvRStrtCoPtUH_in = !CoStopStart_010_FRM_bAcvRStrtCoPtUH_in;
      Rte_Call_R_FRM_bInhspdVehCoPtUH_GetFunctionPermission(& CoStopStart_010_FRM_bInhspdVehCoPtUH_in);
      CoStopStart_010_FRM_bInhspdVehCoPtUH_in = !CoStopStart_010_FRM_bInhspdVehCoPtUH_in;
      Rte_Call_R_FRM_bAcvFastRStrtCoPtUH_GetFunctionPermission(& CoStopStart_010_FRM_bAcvFastRStrtCoPtUH_in);
      CoStopStart_010_FRM_bAcvFastRStrtCoPtUH_in = !CoStopStart_010_FRM_bAcvFastRStrtCoPtUH_in;
      CoStopStart_010_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bRStrtReqAvl_out = CoPtUH_bRStrtReqAvl_B;
      CoPtUH_bRStrtTypAT_out = CoPtUH_bRStrtTypAT_B;
      CoPtUH_stMaxRStrtReq_out = CoPtUH_stMaxRStrtReq_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_010_TEV_CoRStrt_bRstrtReq(CoRStrt_bRstrtReq);
  (void)Rte_Write_P_CoPtUH_bRStrtReqAvl_CoPtUH_bRStrtReqAvl(CoPtUH_bRStrtReqAvl_out);
  (void)Rte_Write_P_CoPtUH_bRStrtTypAT_CoPtUH_bRStrtTypAT(CoPtUH_bRStrtTypAT_out);
  (void)Rte_Write_P_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(CoPtUH_stMaxRStrtReq_out);

}

void RE_CoStopStart_011_MSE(void)
{


      CoStopStart_011_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_011_MSE_CoStop_bStopAuthInfoRdy(0);
  (void)Rte_IrvWrite_RE_CoStopStart_011_MSE_CoStop_bStopReq(0);
      (void)Rte_Write_P_CoPtUH_bOpDrvTraReq_CoPtUH_bOpDrvTraReq(0);
      (void)Rte_Write_P_CoPtUH_stTypSTTNotAvl_CoPtUH_stTypSTTNotAvl(0);

}

void RE_CoStopStart_012_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_012_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmSTT_stEngStopAuth_CoEmSTT_stEngStopAuth(&CoStopStart_012_CoEmSTT_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqAMT_stEngStopAuth_CoReqAMT_stEngStopAuth(&CoStopStart_012_CoReqAMT_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqCha_stEngStopAuth_CoReqCha_stEngStopAuth(&CoStopStart_012_CoReqCha_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqDmpr_stEngStopAuth_CoReqDmpr_stEngStopAuth(&CoStopStart_012_CoReqDmpr_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqStg_stEngStopAuth_CoReqStg_stEngStopAuth(&CoStopStart_012_CoReqStg_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqVeh_stEngStopAuth_CoReqVeh_stEngStopAuth(&CoStopStart_012_CoReqVeh_stEngStopAuth_in);
      (void)Rte_Read_R_EngReqH_stEngStopAuth_EngReqH_stEngStopAuth(&CoStopStart_012_EngReqH_stEngStopAuth_in);
      (void)Rte_Read_R_Veh_stDrvAvl_Veh_stDrvAvl(&CoStopStart_012_Veh_stDrvAvl_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&CoStopStart_012_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_012_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_012_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPtUH_bBltStopAuth_CoPtUH_bBltStopAuth(&CoStopStart_012_CoPtUH_bBltStopAuth_in);
      (void)Rte_Read_R_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(&CoStopStart_012_CoPtUH_bCompTqRStrt_in);
      (void)Rte_Read_R_Sfty_bInhEngStopSTTReq_Sfty_bInhEngStopSTTReq(&CoStopStart_012_Sfty_bInhEngStopSTTReq_in);
      RE_CoStopStart_012_TEV_MonDrv_bReqOpTraAT_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonDrv_bReqOpTraAT();
      RE_CoStopStart_012_TEV_MonDrv_bRstrtCritAuthAnt_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonDrv_bRstrtCritAuthAnt();
      RE_CoStopStart_012_TEV_MonDrv_bStopAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonDrv_bStopAuth();
      RE_CoStopStart_012_TEV_MonEE_bStopAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonEE_bStopAuth();
      RE_CoStopStart_012_TEV_MonEng_bStopAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonEng_bStopAuth();
      RE_CoStopStart_012_TEV_MonGB_bStopAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonGB_bStopAuth();
      RE_CoStopStart_012_TEV_MonVeh_bDeacHillAsi_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonVeh_bDeacHillAsi();
      RE_CoStopStart_012_TEV_MonVeh_bOpDrvTraAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonVeh_bOpDrvTraAuth();
      RE_CoStopStart_012_TEV_MonVeh_bStopAuth_in = Rte_IrvRead_RE_CoStopStart_012_TEV_MonVeh_bStopAuth();

      Rte_Call_R_FRM_bAcvCutCoPtUH_GetFunctionPermission(& CoStopStart_012_FRM_bAcvCutCoPtUH_in);
      CoStopStart_012_FRM_bAcvCutCoPtUH_in = !CoStopStart_012_FRM_bAcvCutCoPtUH_in;
      Rte_Call_R_FRM_bAcvRStrtCoPtUH_GetFunctionPermission(& CoStopStart_012_FRM_bAcvRStrtCoPtUH_in);
      CoStopStart_012_FRM_bAcvRStrtCoPtUH_in = !CoStopStart_012_FRM_bAcvRStrtCoPtUH_in;
      Rte_Call_R_FRM_bInhStopCoPtUH_GetFunctionPermission(& CoStopStart_012_FRM_bInhStopCoPtUH_in);
      CoStopStart_012_FRM_bInhStopCoPtUH_in = !CoStopStart_012_FRM_bInhStopCoPtUH_in;
      Rte_Call_R_FRM_bAcvFastRStrtCoPtUH_GetFunctionPermission(& CoStopStart_012_FRM_bAcvFastRStrtCoPtUH_in);
      CoStopStart_012_FRM_bAcvFastRStrtCoPtUH_in = !CoStopStart_012_FRM_bAcvFastRStrtCoPtUH_in;
      CoStopStart_012_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bOpDrvTraReq_out = CoPtUH_bOpDrvTraReq_B;
      CoPtUH_stTypSTTNotAvl_out = CoPtUH_stTypSTTNotAvl_B;
      CoPtUH_bRstrtCritAuth_out = CoPtUH_bRstrtCritAuth_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_012_TEV_CoStop_bStopAuthInfoRdy(CoStop_bStopAuthInfoRdy);
  (void)Rte_IrvWrite_RE_CoStopStart_012_TEV_CoStop_bStopReq(CoStop_bStopReq);
  (void)Rte_Write_P_CoPtUH_bOpDrvTraReq_CoPtUH_bOpDrvTraReq(CoPtUH_bOpDrvTraReq_out);
  (void)Rte_Write_P_CoPtUH_stTypSTTNotAvl_CoPtUH_stTypSTTNotAvl(CoPtUH_stTypSTTNotAvl_out);
  (void)Rte_Write_P_CoPtUH_bRstrtCritAuth_CoPtUH_bRstrtCritAuth(CoPtUH_bRstrtCritAuth_out);

}

void RE_CoStopStart_013_MSE(void)
{


      CoStopStart_013_MSE_ini();

      (void)Rte_Write_P_CoPtUH_stPwt_CoPtUH_stPwt(1);

}

void RE_CoStopStart_014_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_014_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&CoStopStart_014_CoSync_bDetNNull_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&CoStopStart_014_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_014_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_bEngCutOffReq_CoPtUH_bEngCutOffReq(&CoStopStart_014_CoPtUH_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtUH_bEngStopReq_CoPtUH_bEngStopReq(&CoStopStart_014_CoPtUH_bEngStopReq_in);
      RE_CoStopStart_014_TEV_MonDrv_bRstrtAntCncl_in = Rte_IrvRead_RE_CoStopStart_014_TEV_MonDrv_bRstrtAntCncl();
      RE_CoStopStart_014_TEV_CoRStrt_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_014_TEV_CoRStrt_bRstrtReq();
      RE_CoStopStart_014_TEV_CoStop_bStopReq_in = Rte_IrvRead_RE_CoStopStart_014_TEV_CoStop_bStopReq();
      RE_CoStopStart_014_TEV_MgtEng_bLgRstrt_in = Rte_IrvRead_RE_CoStopStart_014_TEV_MgtEng_bLgRstrt();

      Rte_Call_R_FRM_bAcvCutTotCoPtUH_GetFunctionPermission(& CoStopStart_014_FRM_bAcvCutTotCoPtUH_in);
      CoStopStart_014_FRM_bAcvCutTotCoPtUH_in = !CoStopStart_014_FRM_bAcvCutTotCoPtUH_in;
      Rte_Call_R_FRM_bAcvRunCoPtUH_GetFunctionPermission(& CoStopStart_014_FRM_bAcvRunCoPtUH_in);
      CoStopStart_014_FRM_bAcvRunCoPtUH_in = !CoStopStart_014_FRM_bAcvRunCoPtUH_in;
      CoStopStart_014_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_stPwt_out = CoPtUH_stPwt_B;
  }
  (void)Rte_Write_P_CoPtUH_stPwt_CoPtUH_stPwt(CoPtUH_stPwt_out);

}

void RE_CoStopStart_015_MSE(void)
{


      CoStopStart_015_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_015_MSE_DgoFct_bHealDiagCfLvl1(0);
  (void)Rte_IrvWrite_RE_CoStopStart_015_MSE_DgoFct_bSTTOff(0);
  (void)Rte_IrvWrite_RE_CoStopStart_015_MSE_DgoFct_stRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_nEngClc_CoPtUH_nEngClc(0);
      (void)Rte_Write_P_CoPtUH_noGearTmpBeg_CoPtUH_noGearTmpBeg(0);
      (void)Rte_Write_P_CoPtUH_noGearTmpEnd_CoPtUH_noGearTmpEnd(0);
      (void)Rte_Write_P_CoPtUH_rMaxCluGc_CoPtUH_rMaxCluGc(0);
      (void)Rte_Write_P_CoPtUH_rMinCluRStrt_CoPtUH_rMinCluRStrt(0);
      (void)Rte_Write_P_CoPtUH_bRStrtReqDgoBlt_CoPtUH_bRStrtReqDgoBlt(0);
      (void)Rte_Write_P_CoPtUH_bTestPrvtBltAcv_CoPtUH_bTestPrvtBltAcv(0);
      (void)Rte_Write_P_CoPtUH_bBltStopAuth_CoPtUH_bBltStopAuth(0);
      (void)Rte_Write_P_CoPtUH_stTestPosClu_CoPtUH_stTestPosClu(0);


}

void RE_CoStopStart_016_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&CoStopStart_016_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_bNeut_Ext_bNeut(&CoStopStart_016_Ext_bNeut_in);
      (void)Rte_Read_R_Ext_bPush_Ext_bPush(&CoStopStart_016_Ext_bPush_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoStopStart_016_Ext_nEng_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&CoStopStart_016_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&CoStopStart_016_TqSys_nTarIdl_in);
      (void)Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&CoStopStart_016_TqSys_tqCkEngReal_in);
      (void)Rte_Read_R_Tra_bGearManVld_Tra_bGearManVld(&CoStopStart_016_Tra_bGearManVld_in);
      (void)Rte_Read_R_Tra_noGearMan_Tra_noGearMan(&CoStopStart_016_Tra_noGearMan_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_016_Veh_spdVeh_in);
      (void)Rte_Read_R_CoOptmEl_tqAlt_CoOptmEl_tqAlt(&CoStopStart_016_CoOptmEl_tqAlt_in);
      (void)Rte_Read_R_RvAltMgt_nRvAltMes_RvAltMgt_nRvAltMes(&CoStopStart_016_RvAltMgt_nRvAltMes_in);
      (void)Rte_Read_R_RvAltMgt_nRvAltMv_RvAltMgt_nRvAltMv(&CoStopStart_016_RvAltMgt_nRvAltMv_in);
      (void)Rte_Read_R_RvAltMgt_tqRstrtMaxEstim_RvAltMgt_tqRstrtMaxEstim(&CoStopStart_016_RvAltMgt_tqRstrtMaxEstim_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&CoStopStart_016_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_016_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_016_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_016_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPt_spdVehGearRatCord_CoPt_spdVehGearRatCord(&CoStopStart_016_CoPt_spdVehGearRatCord_in);
      (void)Rte_Read_R_RvAltMgt_tqRvAltGenModMv_RvAltMgt_tqRvAltGenModMv(&CoStopStart_016_RvAltMgt_tqRvAltGenModMv_in);
      (void)Rte_Read_R_TqLimUH_stDrivTyp_TqLimUH_stDrivTyp(&CoStopStart_016_TqLimUH_stDrivTyp_in);
      (void)Rte_Read_R_CoReqCha_rSlopStab_CoReqCha_rSlopStab(&CoStopStart_016_CoReqCha_rSlopStab_in);
      (void)Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&CoStopStart_016_CoReqCha_stEngRStrtInh_in);
      RE_CoStopStart_016_TEV_MonDrv_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_016_TEV_MonDrv_bRstrtReq();

      Rte_Call_R_FRM_bInhDgoBltCoPtUH_GetFunctionPermission(& CoStopStart_016_FRM_bInhDgoBltCoPtUH_in);
      CoStopStart_016_FRM_bInhDgoBltCoPtUH_in = !CoStopStart_016_FRM_bInhDgoBltCoPtUH_in;
      Rte_Call_R_FRM_bInhDgoCluNeutCoPtUH_GetFunctionPermission(& CoStopStart_016_FRM_bInhDgoCluNeutCoPtUH_in);
      CoStopStart_016_FRM_bInhDgoCluNeutCoPtUH_in = !CoStopStart_016_FRM_bInhDgoCluNeutCoPtUH_in;
      CoStopStart_016_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_nEngClc_out = CoPtUH_nEngClc_B;
      CoPtUH_noGearTmpBeg_out = CoPtUH_noGearTmpBeg_B;
      CoPtUH_noGearTmpEnd_out = CoPtUH_noGearTmpEnd_B;
      CoPtUH_rMaxCluGc_out = CoPtUH_rMaxCluGc_B;
      CoPtUH_rMinCluRStrt_out = CoPtUH_rMinCluRStrt_B;
      CoPtUH_bRStrtReqDgoBlt_out = CoPtUH_bRStrtReqDgoBlt_B;
      CoPtUH_bTestPrvtBltAcv_out = CoPtUH_bTestPrvtBltAcv_B;
      CoPtUH_bBltStopAuth_out = CoPtUH_bBltStopAuth_B;
      CoPtUH_stTestPosClu_out = CoPtUH_stTestPosClu_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_016_TEV_DgoFct_bHealDiagCfLvl1(DgoFct_bHealDiagCfLvl1);
  (void)Rte_IrvWrite_RE_CoStopStart_016_TEV_DgoFct_bSTTOff(DgoFct_bSTTOff);
  (void)Rte_IrvWrite_RE_CoStopStart_016_TEV_DgoFct_stRstrtReq(DgoFct_stRstrtReq);
  (void)Rte_Write_P_CoPtUH_nEngClc_CoPtUH_nEngClc(CoPtUH_nEngClc_out);
  (void)Rte_Write_P_CoPtUH_noGearTmpBeg_CoPtUH_noGearTmpBeg(CoPtUH_noGearTmpBeg_out);
  (void)Rte_Write_P_CoPtUH_noGearTmpEnd_CoPtUH_noGearTmpEnd(CoPtUH_noGearTmpEnd_out);
  (void)Rte_Write_P_CoPtUH_rMaxCluGc_CoPtUH_rMaxCluGc(CoPtUH_rMaxCluGc_out);
  (void)Rte_Write_P_CoPtUH_rMinCluRStrt_CoPtUH_rMinCluRStrt(CoPtUH_rMinCluRStrt_out);
  (void)Rte_Write_P_CoPtUH_bRStrtReqDgoBlt_CoPtUH_bRStrtReqDgoBlt(CoPtUH_bRStrtReqDgoBlt_out);
  (void)Rte_Write_P_CoPtUH_bTestPrvtBltAcv_CoPtUH_bTestPrvtBltAcv(CoPtUH_bTestPrvtBltAcv_out);
  (void)Rte_Write_P_CoPtUH_bBltStopAuth_CoPtUH_bBltStopAuth(CoPtUH_bBltStopAuth_out);
  (void)Rte_Write_P_CoPtUH_stTestPosClu_CoPtUH_stTestPosClu(CoPtUH_stTestPosClu_out);

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_Blt */
     if(CoPtUH_bMonRunBlt_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoBlt_out==1)
         {
             Rte_Call_R_CoPtUH_Blt_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_Blt_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunBlt_out_prec==1)
         {
             Rte_Call_R_CoPtUH_Blt_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunBlt_out_prec = CoPtUH_bMonRunBlt_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGcClu */
     if(CoPtUH_bMonRunORngGcClu_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGcClu_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGcClu_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGcClu_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGcClu_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGcClu_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGcClu_out_prec = CoPtUH_bMonRunORngGcClu_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGcNeut */
     if(CoPtUH_bMonRunORngGcNeut_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGcNeut_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGcNeut_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGcNeut_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGcNeut_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGcNeut_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGcNeut_out_prec = CoPtUH_bMonRunORngGcNeut_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGearEnaClu */
     if(CoPtUH_bMonRunORngGearEnaClu_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGearEnaClu_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGearEnaClu_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGearEnaClu_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGearEnaClu_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGearEnaClu_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGearEnaClu_out_prec = CoPtUH_bMonRunORngGearEnaClu_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGearNeut */
     if(CoPtUH_bMonRunORngGearNeut_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGearNeut_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGearNeut_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGearNeut_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGearNeut_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGearNeut_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGearNeut_out_prec = CoPtUH_bMonRunORngGearNeut_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGcMinClu */
     if(CoPtUH_bMonRunORngGcMinClu_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGcMinClu_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGcMinClu_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGcMinClu_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGcMinClu_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGcMinClu_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGcMinClu_out_prec = CoPtUH_bMonRunORngGcMinClu_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_ORngGearMinClu */
     if(CoPtUH_bMonRunORngGearMinClu_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoORngGearMinClu_out==1)
         {
             Rte_Call_R_CoPtUH_ORngGearMinClu_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_ORngGearMinClu_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunORngGearMinClu_out_prec==1)
         {
             Rte_Call_R_CoPtUH_ORngGearMinClu_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunORngGearMinClu_out_prec = CoPtUH_bMonRunORngGearMinClu_out;
  }

  if (FALSE == RE_COSTOPSTART_016_TEV_B)
  {

  /* Diag treatment : CoStopStart_LgEngRStrtInh */
     if(CoPtUH_bMonRunLgEngRStrtInh_out==1)
     {
         /* Diag activation */
         if(CoPtUH_bDgoLgEngRStrtInh_out==1)
         {
             Rte_Call_R_CoPtUH_LgEngRStrtInh_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPtUH_LgEngRStrtInh_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPtUH_bMonRunLgEngRStrtInh_out_prec==1)
         {
             Rte_Call_R_CoPtUH_LgEngRStrtInh_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPtUH_bMonRunLgEngRStrtInh_out_prec = CoPtUH_bMonRunLgEngRStrtInh_out;
  }

}

void RE_CoStopStart_017_MSE(void)
{


      CoStopStart_017_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_017_MSE_MgtAlt_bIntrAltRstrtReqRaw(0);
      (void)Rte_Write_P_CoPtUH_bAltInh_CoPtUH_bAltInh(1);
      (void)Rte_Write_P_CoPtUH_bAltPrepRStrtReq_CoPtUH_bAltPrepRStrtReq(0);
      (void)Rte_Write_P_CoPtUH_bAltRPosnEngReq_CoPtUH_bAltRPosnEngReq(0);
      (void)Rte_Write_P_CoPtUH_bAltRStrtReq_CoPtUH_bAltRStrtReq(0);
      (void)Rte_Write_P_CoPtUH_bAltStallReq_CoPtUH_bAltStallReq(0);
      (void)Rte_Write_P_CoPtUH_bCdnInhRStrt_CoPtUH_bCdnInhRStrt(0);
      (void)Rte_Write_P_CoPtUH_bRStrtAnt_CoPtUH_bRStrtAnt(0);
      (void)Rte_Write_P_CoPtUH_bVSSNwAcvAuth_CoPtUH_bVSSNwAcvAuth(0);

}

void RE_CoStopStart_018_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_018_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoStrt_bStrtAuth_CoStrt_bStrtAuth(&CoStopStart_018_CoStrt_bStrtAuth_in);
      (void)Rte_Read_R_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(&CoStopStart_018_CoTqRStrt_bEngStrtSuc_in);
      (void)Rte_Read_R_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(&CoStopStart_018_EngReqH_bEngRStrtAutnAvl_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_018_Veh_spdVeh_in);
      (void)Rte_Read_R_CoReqRStrt_bAuthSA_CoReqRStrt_bAuthSA(&CoStopStart_018_CoReqRStrt_bAuthSA_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&CoStopStart_018_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_018_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_bRStrtMchAuth_CoPtUH_bRStrtMchAuth(&CoStopStart_018_CoPtUH_bRStrtMchAuth_in);
      (void)Rte_Read_R_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(&CoStopStart_018_CoPtUH_stMaxRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_018_CoPtUH_stPwt_in);
      (void)Rte_Read_R_PARM_bEngRstrtAutnAvl_PARM_bEngRstrtAutnAvl(&CoStopStart_018_PARM_bEngRstrtAutnAvl_in);
      (void)Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&CoStopStart_018_Ext_spdVehSecu_in);
      (void)Rte_Read_R_TqLimUH_bAcvUnBlsEng_TqLimUH_bAcvUnBlsEng(&CoStopStart_018_TqLimUH_bAcvUnBlsEng_in);
      RE_CoStopStart_018_TEV_MgtEng_bLgRstrt_in = Rte_IrvRead_RE_CoStopStart_018_TEV_MgtEng_bLgRstrt();
      RE_CoStopStart_018_TEV_MonDrv_bRstrtAntCncl_in = Rte_IrvRead_RE_CoStopStart_018_TEV_MonDrv_bRstrtAntCncl();
      RE_CoStopStart_018_TEV_CoRStrt_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_018_TEV_CoRStrt_bRstrtReq();
      RE_CoStopStart_018_TEV_MonDrv_bPrepRstrtReq_in = Rte_IrvRead_RE_CoStopStart_018_TEV_MonDrv_bPrepRstrtReq();
      RE_CoStopStart_018_TEV_MonVeh_bHiSpdRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_018_TEV_MonVeh_bHiSpdRstrtAuth();
      RE_CoStopStart_018_TEV_MonVeh_bRstrtAuthMch_in = Rte_IrvRead_RE_CoStopStart_018_TEV_MonVeh_bRstrtAuthMch();

      Rte_Call_R_FRM_bInhspdVehCoPtUH_GetFunctionPermission(& CoStopStart_018_FRM_bInhspdVehCoPtUH_in);
      CoStopStart_018_FRM_bInhspdVehCoPtUH_in = !CoStopStart_018_FRM_bInhspdVehCoPtUH_in;
      CoStopStart_018_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bAltInh_out = CoPtUH_bAltInh_B;
      CoPtUH_bAltPrepRStrtReq_out = CoPtUH_bAltPrepRStrtReq_B;
      CoPtUH_bAltRPosnEngReq_out = CoPtUH_bAltRPosnEngReq_B;
      CoPtUH_bAltRStrtReq_out = CoPtUH_bAltRStrtReq_B;
      CoPtUH_bAltStallReq_out = CoPtUH_bAltStallReq_B;
      CoPtUH_bCdnInhRStrt_out = CoPtUH_bCdnInhRStrt_B;
      CoPtUH_bRStrtAnt_out = CoPtUH_bRStrtAnt_B;
      CoPtUH_bVSSNwAcvAuth_out = CoPtUH_bVSSNwAcvAuth_B;
  }
  (void)Rte_Write_P_CoPtUH_bAltInh_CoPtUH_bAltInh(CoPtUH_bAltInh_out);
  (void)Rte_Write_P_CoPtUH_bAltPrepRStrtReq_CoPtUH_bAltPrepRStrtReq(CoPtUH_bAltPrepRStrtReq_out);
  (void)Rte_Write_P_CoPtUH_bAltRPosnEngReq_CoPtUH_bAltRPosnEngReq(CoPtUH_bAltRPosnEngReq_out);
  (void)Rte_Write_P_CoPtUH_bAltRStrtReq_CoPtUH_bAltRStrtReq(CoPtUH_bAltRStrtReq_out);
  (void)Rte_Write_P_CoPtUH_bAltStallReq_CoPtUH_bAltStallReq(CoPtUH_bAltStallReq_out);
  (void)Rte_Write_P_CoPtUH_bCdnInhRStrt_CoPtUH_bCdnInhRStrt(CoPtUH_bCdnInhRStrt_out);
  (void)Rte_Write_P_CoPtUH_bRStrtAnt_CoPtUH_bRStrtAnt(CoPtUH_bRStrtAnt_out);
  (void)Rte_Write_P_CoPtUH_bVSSNwAcvAuth_CoPtUH_bVSSNwAcvAuth(CoPtUH_bVSSNwAcvAuth_out);
  (void)Rte_IrvWrite_RE_CoStopStart_018_TEV_MgtAlt_bIntrAltRstrtReqRaw(MgtAlt_bIntrAltRstrtReqRaw);

}

void RE_CoStopStart_019_MSE(void)
{


      CoStopStart_019_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_019_MSE_MgtDrv_bDftHld(0);
  (void)Rte_IrvWrite_RE_CoStopStart_019_MSE_MgtDrv_bRiseSpcFacSTTReq1(0);
      (void)Rte_Write_P_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(0);
      (void)Rte_Write_P_CoPtUH_bFbSpcFactSTTReq2_CoPtUH_bFbSpcFactSTTReq2(0);
      (void)Rte_Write_P_CoPtUH_bInfoAcvCluPed_CoPtUH_bInfoAcvCluPed(0);
      (void)Rte_Write_P_CoPtUH_bInfoRdy_CoPtUH_bInfoRdy(0);
      (void)Rte_Write_P_CoPtUH_bSTTInh_CoPtUH_bSTTInh(0);
      (void)Rte_Write_P_CoPtUH_stSTTLightAcv_CoPtUH_stSTTLightAcv(0);
      (void)Rte_Write_P_CoPtUH_bAcvGSINeut_CoPtUH_bAcvGSINeut(0);

}

void RE_CoStopStart_020_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_020_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_bPush_Ext_bPush(&CoStopStart_020_Ext_bPush_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoStopStart_020_Ext_nEng_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&CoStopStart_020_TqSys_nTarIdl_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&CoStopStart_020_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_020_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_020_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_020_Ext_stGBxCf_in);
      (void)Rte_Read_R_Afts_stSpcFactSTTReq_Afts_stSpcFactSTTReq(&CoStopStart_020_Afts_stSpcFactSTTReq_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&CoStopStart_020_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_Sfty_bInhEngStopSTTReq_Sfty_bInhEngStopSTTReq(&CoStopStart_020_Sfty_bInhEngStopSTTReq_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&CoStopStart_020_Ext_tAir_in);
	  (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_020_CoPtUH_stPwt_in);
      RE_CoStopStart_020_TEV_MonDrv_bGSIStopAuth_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonDrv_bGSIStopAuth();
      RE_CoStopStart_020_TEV_MonDrv_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonDrv_bRstrtReq();
      RE_CoStopStart_020_TEV_MonGB_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonGB_bRstrtAuth();
      RE_CoStopStart_020_TEV_CoCut_ctForcRstrtFail_in = Rte_IrvRead_RE_CoStopStart_020_TEV_CoCut_ctForcRstrtFail();
      RE_CoStopStart_020_TEV_CoCut_ctRstrtFail_in = Rte_IrvRead_RE_CoStopStart_020_TEV_CoCut_ctRstrtFail();
      RE_CoStopStart_020_TEV_CoStop_bStopAuthInfoRdy_in = Rte_IrvRead_RE_CoStopStart_020_TEV_CoStop_bStopAuthInfoRdy();
      RE_CoStopStart_020_TEV_DgoFct_bSTTOff_in = Rte_IrvRead_RE_CoStopStart_020_TEV_DgoFct_bSTTOff();
      RE_CoStopStart_020_TEV_MonDrv_bPrepInfoRdy_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonDrv_bPrepInfoRdy();
      RE_CoStopStart_020_TEV_MonDrv_bStopAuthRaw_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonDrv_bStopAuthRaw();
      RE_CoStopStart_020_TEV_MonDrv_bStopCdnChg_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonDrv_bStopCdnChg();
      RE_CoStopStart_020_TEV_MonEng_bStopEngRdy_in = Rte_IrvRead_RE_CoStopStart_020_TEV_MonEng_bStopEngRdy();

      Rte_Call_R_FRM_bAcvCutCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bAcvCutCoPtUH_in);
      CoStopStart_020_FRM_bAcvCutCoPtUH_in = !CoStopStart_020_FRM_bAcvCutCoPtUH_in;
      Rte_Call_R_FRM_bAcvCutTotCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bAcvCutTotCoPtUH_in);
      CoStopStart_020_FRM_bAcvCutTotCoPtUH_in = !CoStopStart_020_FRM_bAcvCutTotCoPtUH_in;
      Rte_Call_R_FRM_bAcvRStrtCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bAcvRStrtCoPtUH_in);
      CoStopStart_020_FRM_bAcvRStrtCoPtUH_in = !CoStopStart_020_FRM_bAcvRStrtCoPtUH_in;
      Rte_Call_R_FRM_bAcvSTTLitCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bAcvSTTLitCoPtUH_in);
      CoStopStart_020_FRM_bAcvSTTLitCoPtUH_in = !CoStopStart_020_FRM_bAcvSTTLitCoPtUH_in;
      Rte_Call_R_FRM_bInhPushCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bInhPushCoPtUH_in);
      CoStopStart_020_FRM_bInhPushCoPtUH_in = !CoStopStart_020_FRM_bInhPushCoPtUH_in;
      Rte_Call_R_FRM_bInhStopCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bInhStopCoPtUH_in);
      CoStopStart_020_FRM_bInhStopCoPtUH_in = !CoStopStart_020_FRM_bInhStopCoPtUH_in;
      Rte_Call_R_FRM_bAcvFastRStrtCoPtUH_GetFunctionPermission(& CoStopStart_020_FRM_bAcvFastRStrtCoPtUH_in);
      CoStopStart_020_FRM_bAcvFastRStrtCoPtUH_in = !CoStopStart_020_FRM_bAcvFastRStrtCoPtUH_in;
      CoStopStart_020_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bFbSpcFactSTTReq1_out = CoPtUH_bFbSpcFactSTTReq1_B;
      CoPtUH_bFbSpcFactSTTReq2_out = CoPtUH_bFbSpcFactSTTReq2_B;
      CoPtUH_bInfoAcvCluPed_out = CoPtUH_bInfoAcvCluPed_B;
      CoPtUH_bInfoRdy_out = CoPtUH_bInfoRdy_B;
      CoPtUH_bSTTInh_out = CoPtUH_bSTTInh_B;
      CoPtUH_stSTTLightAcv_out = CoPtUH_stSTTLightAcv_B;
      CoPtUH_bAcvGSINeut_out = CoPtUH_bAcvGSINeut_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_020_TEV_MgtDrv_bDftHld(MgtDrv_bDftHld);
  (void)Rte_IrvWrite_RE_CoStopStart_020_TEV_MgtDrv_bRiseSpcFacSTTReq1(MgtDrv_bRiseSpcFacSTTReq1);
  (void)Rte_Write_P_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(CoPtUH_bFbSpcFactSTTReq1_out);
  (void)Rte_Write_P_CoPtUH_bFbSpcFactSTTReq2_CoPtUH_bFbSpcFactSTTReq2(CoPtUH_bFbSpcFactSTTReq2_out);
  (void)Rte_Write_P_CoPtUH_bInfoAcvCluPed_CoPtUH_bInfoAcvCluPed(CoPtUH_bInfoAcvCluPed_out);
  (void)Rte_Write_P_CoPtUH_bInfoRdy_CoPtUH_bInfoRdy(CoPtUH_bInfoRdy_out);
  (void)Rte_Write_P_CoPtUH_bSTTInh_CoPtUH_bSTTInh(CoPtUH_bSTTInh_out);
  (void)Rte_Write_P_CoPtUH_stSTTLightAcv_CoPtUH_stSTTLightAcv(CoPtUH_stSTTLightAcv_out);
  (void)Rte_Write_P_CoPtUH_bAcvGSINeut_CoPtUH_bAcvGSINeut(CoPtUH_bAcvGSINeut_out);

}

void RE_CoStopStart_021_MSE(void)
{


      CoStopStart_021_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_021_MSE_MgtEng_bLgRstrt(0);
      (void)Rte_Write_P_CoPtUH_bEngRStrtReq_CoPtUH_bEngRStrtReq(0);
      (void)Rte_Write_P_CoPtUH_bEngStopReq_CoPtUH_bEngStopReq(0);
      (void)Rte_Write_P_CoPtUH_bLatchDrvCyc_CoPtUH_bLatchDrvCyc(0);
      (void)Rte_Write_P_CoPtUH_bCtlDmprAuth_CoPtUH_bCtlDmprAuth(0);
      (void)Rte_Write_P_CoPtUH_tiCmplStop_CoPtUH_tiCmplStop(0);
      (void)Rte_Write_P_CoPtUH_stAftsRStrtSuc_CoPtUH_stAftsRStrtSuc(0);
      (void)Rte_Write_P_CoPtUH_stFbSpcFactRStrtSuc_CoPtUH_stFbSpcFactRStrtSuc(0);

}

void RE_CoStopStart_022_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_022_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&CoStopStart_022_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(&CoStopStart_022_CoTqRStrt_bEngStrtSuc_in);
      (void)Rte_Read_R_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(&CoStopStart_022_EngReqH_bEngRStrtAutnAvl_in);
      (void)Rte_Read_R_Ext_bNeut_Ext_bNeut(&CoStopStart_022_Ext_bNeut_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoStopStart_022_Ext_nEng_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_022_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_022_Ext_stGBxCf_in);
      (void)Rte_Read_R_PARM_bEngRstrtAutnAvl_PARM_bEngRstrtAutnAvl(&CoStopStart_022_PARM_bEngRstrtAutnAvl_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&CoStopStart_022_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_CoPtUH_bAltRStrtReq_CoPtUH_bAltRStrtReq(&CoStopStart_022_CoPtUH_bAltRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoStopStart_022_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_CoPtUH_bStPresLo_CoPtUH_bStPresLo(&CoStopStart_022_CoPtUH_bStPresLo_in);
      (void)Rte_Read_R_CoTqRStrt_bTraTqAuthRaw_CoTqRStrt_bTraTqAuthRaw(&CoStopStart_022_CoTqRStrt_bTraTqAuthRaw_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&CoStopStart_022_Ext_posnGBxLev_in);
      (void)Rte_Read_R_CoPtUH_bEngRstrtClsCluCdn_CoPtUH_bEngRstrtClsCluCdn(&CoStopStart_022_CoPtUH_bEngRstrtClsCluCdn_in);
      RE_CoStopStart_022_TEV_MonDrv_bRstrtAntCncl_in = Rte_IrvRead_RE_CoStopStart_022_TEV_MonDrv_bRstrtAntCncl();
      RE_CoStopStart_022_TEV_CoRStrt_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_022_TEV_CoRStrt_bRstrtReq();
      RE_CoStopStart_022_TEV_CoCut_ctRstrtFail_in = Rte_IrvRead_RE_CoStopStart_022_TEV_CoCut_ctRstrtFail();
      RE_CoStopStart_022_TEV_CoCut_bRstrtFail_in = Rte_IrvRead_RE_CoStopStart_022_TEV_CoCut_bRstrtFail();
      RE_CoStopStart_022_TEV_MgtDrv_bRiseSpcFacSTTReq1_in = Rte_IrvRead_RE_CoStopStart_022_TEV_MgtDrv_bRiseSpcFacSTTReq1();
      RE_CoStopStart_022_TEV_CoCut_bElMecIntrRstrt_in = Rte_IrvRead_RE_CoStopStart_022_TEV_CoCut_bElMecIntrRstrt();
      RE_CoStopStart_022_TEV_MgtAlt_bIntrAltRstrtReqRaw_in = Rte_IrvRead_RE_CoStopStart_022_TEV_MgtAlt_bIntrAltRstrtReqRaw();

      Rte_Call_R_FRM_bInhCtlDmprAuth_GetFunctionPermission(& CoStopStart_022_FRM_bInhCtlDmprAuth_in);
      CoStopStart_022_FRM_bInhCtlDmprAuth_in = !CoStopStart_022_FRM_bInhCtlDmprAuth_in;
      CoStopStart_022_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bEngRStrtReq_out = CoPtUH_bEngRStrtReq_B;
      CoPtUH_bEngStopReq_out = CoPtUH_bEngStopReq_B;
      CoPtUH_bLatchDrvCyc_out = CoPtUH_bLatchDrvCyc_B;
      CoPtUH_bCtlDmprAuth_out = CoPtUH_bCtlDmprAuth_B;
      CoPtUH_tiCmplStop_out = CoPtUH_tiCmplStop_B;
      CoPtUH_stAftsRStrtSuc_out = CoPtUH_stAftsRStrtSuc_B;
      CoPtUH_stFbSpcFactRStrtSuc_out = CoPtUH_stFbSpcFactRStrtSuc_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_022_TEV_MgtEng_bLgRstrt(MgtEng_bLgRstrt);
  (void)Rte_Write_P_CoPtUH_bEngRStrtReq_CoPtUH_bEngRStrtReq(CoPtUH_bEngRStrtReq_out);
  (void)Rte_Write_P_CoPtUH_bEngStopReq_CoPtUH_bEngStopReq(CoPtUH_bEngStopReq_out);
  (void)Rte_Write_P_CoPtUH_bLatchDrvCyc_CoPtUH_bLatchDrvCyc(CoPtUH_bLatchDrvCyc_out);
  (void)Rte_Write_P_CoPtUH_bCtlDmprAuth_CoPtUH_bCtlDmprAuth(CoPtUH_bCtlDmprAuth_out);
  (void)Rte_Write_P_CoPtUH_tiCmplStop_CoPtUH_tiCmplStop(CoPtUH_tiCmplStop_out);
  (void)Rte_Write_P_CoPtUH_stAftsRStrtSuc_CoPtUH_stAftsRStrtSuc(CoPtUH_stAftsRStrtSuc_out);
  (void)Rte_Write_P_CoPtUH_stFbSpcFactRStrtSuc_CoPtUH_stFbSpcFactRStrtSuc(CoPtUH_stFbSpcFactRStrtSuc_out);

}

void RE_CoStopStart_023_MSE(void)
{


      CoStopStart_023_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bGSIStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bPrepInfoRdy(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bPrepRstrtReq(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bReqOpTraAT(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bRstrtAntCncl(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bRstrtCritAuthAnt(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bRstrtReq(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bStopAuthRaw(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bStopCdnChg(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_stRstrtReq(0);
  (void)Rte_IrvWrite_RE_CoStopStart_023_MSE_MonDrv_bRstrtAntReq(0);
      (void)Rte_Write_P_CoPtUH_bRecNotStop_CoPtUH_bRecNotStop(0);

}

void RE_CoStopStart_024_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_024_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&CoStopStart_024_AccP_rAccP_in);
      (void)Rte_Read_R_Ext_bEfcBrkPedPrss_Ext_bEfcBrkPedPrss(&CoStopStart_024_Ext_bEfcBrkPedPrss_in);
      (void)Rte_Read_R_Ext_bNeut_Ext_bNeut(&CoStopStart_024_Ext_bNeut_in);
      (void)Rte_Read_R_Ext_bRvs_Ext_bRvs(&CoStopStart_024_Ext_bRvs_in);
      (void)Rte_Read_R_Ext_pBrkMCT_Ext_pBrkMCT(&CoStopStart_024_Ext_pBrkMCT_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&CoStopStart_024_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_024_Veh_spdVeh_in);
      (void)Rte_Read_R_Veh_stDrvAvl_Veh_stDrvAvl(&CoStopStart_024_Veh_stDrvAvl_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_024_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(&CoStopStart_024_CoPtUH_stMaxRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_024_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_024_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoStopStart_024_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_Cha_stEPB_Cha_stEPB(&CoStopStart_024_Cha_stEPB_in);
      (void)Rte_Read_R_CoPtUH_bOpDrvTraReq_CoPtUH_bOpDrvTraReq(&CoStopStart_024_CoPtUH_bOpDrvTraReq_in);
      (void)Rte_Read_R_CoPtUH_bSTTInh_CoPtUH_bSTTInh(&CoStopStart_024_CoPtUH_bSTTInh_in);
      (void)Rte_Read_R_CoPtUH_stSTTLightAcv_CoPtUH_stSTTLightAcv(&CoStopStart_024_CoPtUH_stSTTLightAcv_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&CoStopStart_024_Ext_posnGBxLev_in);
      (void)Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&CoStopStart_024_Ext_spdVehSecu_in);
      (void)Rte_Read_R_CoReqRStrt_stRStrtTyp_CoReqRStrt_stRStrtTyp(&CoStopStart_024_CoReqRStrt_stRStrtTyp_in);
      (void)Rte_Read_R_Tra_stGBxMod_Tra_stGBxMod(&CoStopStart_024_Tra_stGBxMod_in);
      (void)Rte_Read_R_CoReqAMT_stEngStopAuth_CoReqAMT_stEngStopAuth(&CoStopStart_024_CoReqAMT_stEngStopAuth_in);
      RE_CoStopStart_024_TEV_CoRStrt_bRstrtReq_in = Rte_IrvRead_RE_CoStopStart_024_TEV_CoRStrt_bRstrtReq();
      RE_CoStopStart_024_TEV_CoCut_ctRstrtFail_in = Rte_IrvRead_RE_CoStopStart_024_TEV_CoCut_ctRstrtFail();
      RE_CoStopStart_024_TEV_MonVeh_bInfoHillAsiDrvRstrt_in = Rte_IrvRead_RE_CoStopStart_024_TEV_MonVeh_bInfoHillAsiDrvRstrt();
      RE_CoStopStart_024_TEV_MonEng_bStopEngRdy_in = Rte_IrvRead_RE_CoStopStart_024_TEV_MonEng_bStopEngRdy();

      Rte_Call_R_FRM_bInhspdVehCoPtUH_GetFunctionPermission(& CoStopStart_024_FRM_bInhspdVehCoPtUH_in);
      CoStopStart_024_FRM_bInhspdVehCoPtUH_in = !CoStopStart_024_FRM_bInhspdVehCoPtUH_in;
      CoStopStart_024_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bRecNotStop_out = CoPtUH_bRecNotStop_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bGSIStopAuth(MonDrv_bGSIStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bPrepInfoRdy(MonDrv_bPrepInfoRdy);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bPrepRstrtReq(MonDrv_bPrepRstrtReq);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bReqOpTraAT(MonDrv_bReqOpTraAT);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bRstrtAntCncl(MonDrv_bRstrtAntCncl);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bRstrtCritAuthAnt(MonDrv_bRstrtCritAuthAnt);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bRstrtReq(MonDrv_bRstrtReq);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bStopAuth(MonDrv_bStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bStopAuthRaw(MonDrv_bStopAuthRaw);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bStopCdnChg(MonDrv_bStopCdnChg);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_stRstrtReq(MonDrv_stRstrtReq);
  (void)Rte_IrvWrite_RE_CoStopStart_024_TEV_MonDrv_bRstrtAntReq(MonDrv_bRstrtAntReq);
  (void)Rte_Write_P_CoPtUH_bRecNotStop_CoPtUH_bRecNotStop(CoPtUH_bRecNotStop_out);

}

void RE_CoStopStart_025_MSE(void)
{


      CoStopStart_025_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_025_MSE_MonEE_bStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_025_MSE_MonEE_stRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(0);

}

void RE_CoStopStart_026_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_026_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(&CoStopStart_026_CoEmSTT_stEngRStrtReq_in);
      (void)Rte_Read_R_CoEmSTT_stEngStopAuth_CoEmSTT_stEngStopAuth(&CoStopStart_026_CoEmSTT_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqRStrt_bEngRStrtReq_CoReqRStrt_bEngRStrtReq(&CoStopStart_026_CoReqRStrt_bEngRStrtReq_in);
      (void)Rte_Read_R_CoReqRStrt_bEngStopAuth_CoReqRStrt_bEngStopAuth(&CoStopStart_026_CoReqRStrt_bEngStopAuth_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoStopStart_026_CoPtUH_bFbSpcFactSTTReq1_in);

      CoStopStart_026_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bCompTqRStrt_out = CoPtUH_bCompTqRStrt_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_026_TEV_MonEE_bStopAuth(MonEE_bStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_026_TEV_MonEE_stRstrtReq(MonEE_stRstrtReq);
  (void)Rte_Write_P_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(CoPtUH_bCompTqRStrt_out);

}

void RE_CoStopStart_027_MSE(void)
{


      CoStopStart_027_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_027_MSE_MonEng_bStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_027_MSE_MonEng_bStopEngRdy(0);
  (void)Rte_IrvWrite_RE_CoStopStart_027_MSE_MonEng_stRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_bLimFreqStopInh_CoPtUH_bLimFreqStopInh(0);
      (void)Rte_Write_P_CoPtUH_tiNbRstrtFreqLim_CoPtUH_tiNbRstrtFreqLim(0);

}

void RE_CoStopStart_028_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_028_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&CoStopStart_028_CoPt_tqIdcReqCord_nRegReq_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_028_Veh_spdVeh_in);
      (void)Rte_Read_R_EngReqH_stEngStopAuth_EngReqH_stEngStopAuth(&CoStopStart_028_EngReqH_stEngStopAuth_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&CoStopStart_028_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoStopStart_028_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_EngReqH_bEngRunReq_EngReqH_bEngRunReq(&CoStopStart_028_EngReqH_bEngRunReq_in);
      (void)Rte_Read_R_Afts_bInhIniRunReq_Afts_bInhIniRunReq(&CoStopStart_028_Afts_bInhIniRunReq_in);

      CoStopStart_028_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bLimFreqStopInh_out = CoPtUH_bLimFreqStopInh_B;
      CoPtUH_tiNbRstrtFreqLim_out = CoPtUH_tiNbRstrtFreqLim_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_028_TEV_MonEng_bStopAuth(MonEng_bStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_028_TEV_MonEng_bStopEngRdy(MonEng_bStopEngRdy);
  (void)Rte_IrvWrite_RE_CoStopStart_028_TEV_MonEng_stRstrtReq(MonEng_stRstrtReq);
  (void)Rte_Write_P_CoPtUH_bLimFreqStopInh_CoPtUH_bLimFreqStopInh(CoPtUH_bLimFreqStopInh_out);
  (void)Rte_Write_P_CoPtUH_tiNbRstrtFreqLim_CoPtUH_tiNbRstrtFreqLim(CoPtUH_tiNbRstrtFreqLim_out);

}

void RE_CoStopStart_029_MSE(void)
{


      CoStopStart_029_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_bCutCaseLgGc(0);
  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_bMAPRstrtAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_bRstrtAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_bRstrtTypATReq(0);
  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_bStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_029_MSE_MonGB_stRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(0);
      (void)Rte_Write_P_CoPtUH_bRStrtMchAuth_CoPtUH_bRStrtMchAuth(0);

}

void RE_CoStopStart_030_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_030_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoReqAMT_bEngRStrtReq_CoReqAMT_bEngRStrtReq(&CoStopStart_030_CoReqAMT_bEngRStrtReq_in);
      (void)Rte_Read_R_Ext_bNeut_Ext_bNeut(&CoStopStart_030_Ext_bNeut_in);
      (void)Rte_Read_R_Ext_bRStrtAuthTra_Ext_bRStrtAuthTra(&CoStopStart_030_Ext_bRStrtAuthTra_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&CoStopStart_030_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_CoReqAMT_stEngStopAuth_CoReqAMT_stEngStopAuth(&CoStopStart_030_CoReqAMT_stEngStopAuth_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_030_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPtUH_bOpDrvTraReq_CoPtUH_bOpDrvTraReq(&CoStopStart_030_CoPtUH_bOpDrvTraReq_in);
      (void)Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&CoStopStart_030_Ext_stTraTypCf_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&CoStopStart_030_Ext_posnGBxLev_in);
      (void)Rte_Read_R_Tra_noEgdGear_Tra_noEgdGear(&CoStopStart_030_Tra_noEgdGear_in);
      (void)Rte_Read_R_Tra_noTarGear_Tra_noTarGear(&CoStopStart_030_Tra_noTarGear_in);
      (void)Rte_Read_R_CoPt_bInhEngStopProtManClu_CoPt_bInhEngStopProtManClu(&CoStopStart_030_CoPt_bInhEngStopProtManClu_in);

      Rte_Call_R_FRM_bInhCluPCoPtUH_GetFunctionPermission(& CoStopStart_030_FRM_bInhCluPCoPtUH_in);
      CoStopStart_030_FRM_bInhCluPCoPtUH_in = !CoStopStart_030_FRM_bInhCluPCoPtUH_in;
      Rte_Call_R_FRM_bInhNeutCoPtUH_GetFunctionPermission(& CoStopStart_030_FRM_bInhNeutCoPtUH_in);
      CoStopStart_030_FRM_bInhNeutCoPtUH_in = !CoStopStart_030_FRM_bInhNeutCoPtUH_in;
      CoStopStart_030_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bDrvTraOp_out = CoPtUH_bDrvTraOp_B;
      CoPtUH_bRStrtMchAuth_out = CoPtUH_bRStrtMchAuth_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_bCutCaseLgGc(MonGB_bCutCaseLgGc);
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_bMAPRstrtAuth(MonGB_bMAPRstrtAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_bRstrtAuth(MonGB_bRstrtAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_bRstrtTypATReq(MonGB_bRstrtTypATReq);
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_bStopAuth(MonGB_bStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_030_TEV_MonGB_stRstrtReq(MonGB_stRstrtReq);
  (void)Rte_Write_P_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(CoPtUH_bDrvTraOp_out);
  (void)Rte_Write_P_CoPtUH_bRStrtMchAuth_CoPtUH_bRStrtMchAuth(CoPtUH_bRStrtMchAuth_out);

}

void RE_CoStopStart_031_MSE(void)
{


      CoStopStart_031_MSE_ini();

  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bDeacHillAsi(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bHiSpdRstrtAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bInfoHillAsiDrvRstrt(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bOpDrvTraAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bPresPtlRstrtReqForc(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bPtlVehRstrtReqForc(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bRstrtAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bRstrtAuthMch(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_bStopAuth(0);
  (void)Rte_IrvWrite_RE_CoStopStart_031_MSE_MonVeh_stRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_bStPresLo_CoPtUH_bStPresLo(0);
      (void)Rte_Write_P_CoPtUH_bStopAuthSlop_CoPtUH_bStopAuthSlop(0);
      (void)Rte_Write_P_CoPtUH_bEngRstrtClsCluCdn_CoPtUH_bEngRstrtClsCluCdn(0);
      (void)Rte_Write_P_CoPtUH_bInhHiSpdAltRstrtReq_CoPtUH_bInhHiSpdAltRstrtReq(0);
      (void)Rte_Write_P_CoPtUH_pRelBrkAsi_CoPtUH_pRelBrkAsi(2);

}

void RE_CoStopStart_032_TEV(void)
{

  if (FALSE == RE_COSTOPSTART_032_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoReqCha_bEngRStrtReq_CoReqCha_bEngRStrtReq(&CoStopStart_032_CoReqCha_bEngRStrtReq_in);
      (void)Rte_Read_R_CoReqCha_bHillAsiRdyEngStop_CoReqCha_bHillAsiRdyEngStop(&CoStopStart_032_CoReqCha_bHillAsiRdyEngStop_in);
      (void)Rte_Read_R_CoReqDmpr_bEngRStrtReq_CoReqDmpr_bEngRStrtReq(&CoStopStart_032_CoReqDmpr_bEngRStrtReq_in);
      (void)Rte_Read_R_CoReqStg_bEngRStrtReq_CoReqStg_bEngRStrtReq(&CoStopStart_032_CoReqStg_bEngRStrtReq_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoStopStart_032_Ext_nEng_in);
      (void)Rte_Read_R_Ext_pBrkAsi_Ext_pBrkAsi(&CoStopStart_032_Ext_pBrkAsi_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&CoStopStart_032_TqSys_nTarIdl_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoStopStart_032_Veh_spdVeh_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&CoStopStart_032_Ext_pAirExtMes_in);
      (void)Rte_Read_R_CoReqCha_stEngStopAuth_CoReqCha_stEngStopAuth(&CoStopStart_032_CoReqCha_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqDmpr_stEngStopAuth_CoReqDmpr_stEngStopAuth(&CoStopStart_032_CoReqDmpr_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqStg_stEngStopAuth_CoReqStg_stEngStopAuth(&CoStopStart_032_CoReqStg_stEngStopAuth_in);
      (void)Rte_Read_R_CoReqVeh_stEngRStrtReq_CoReqVeh_stEngRStrtReq(&CoStopStart_032_CoReqVeh_stEngRStrtReq_in);
      (void)Rte_Read_R_CoReqVeh_stEngStopAuth_CoReqVeh_stEngStopAuth(&CoStopStart_032_CoReqVeh_stEngStopAuth_in);
      (void)Rte_Read_R_Ext_pRelBrkAsi_Ext_pRelBrkAsi(&CoStopStart_032_Ext_pRelBrkAsi_in);
      (void)Rte_Read_R_PredEs_nFast_PredEs_nFast(&CoStopStart_032_PredEs_nFast_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&CoStopStart_032_CoPtUH_stPwt_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoStopStart_032_Ext_stGBxCf_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoStopStart_032_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_CoReqCha_bUncrtSlopStab_CoReqCha_bUncrtSlopStab(&CoStopStart_032_CoReqCha_bUncrtSlopStab_in);
      (void)Rte_Read_R_CoReqCha_rSlopStab_CoReqCha_rSlopStab(&CoStopStart_032_CoReqCha_rSlopStab_in);
      (void)Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&CoStopStart_032_CoReqCha_stEngRStrtInh_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&CoStopStart_032_Ext_posnGBxLev_in);
      (void)Rte_Read_R_Ext_spdVehSecu_Ext_spdVehSecu(&CoStopStart_032_Ext_spdVehSecu_in);
      RE_CoStopStart_032_TEV_MonGB_bRstrtAuth_in = Rte_IrvRead_RE_CoStopStart_032_TEV_MonGB_bRstrtAuth();

      Rte_Call_R_FRM_bInhspdVehCoPtUH_GetFunctionPermission(& CoStopStart_032_FRM_bInhspdVehCoPtUH_in);
      CoStopStart_032_FRM_bInhspdVehCoPtUH_in = !CoStopStart_032_FRM_bInhspdVehCoPtUH_in;
      Rte_Call_R_FRM_bInhRelBrkAsiCoPtUH_GetFunctionPermission(& CoStopStart_032_FRM_bInhRelBrkAsiCoPtUH_in);
      CoStopStart_032_FRM_bInhRelBrkAsiCoPtUH_in = !CoStopStart_032_FRM_bInhRelBrkAsiCoPtUH_in;
      CoStopStart_032_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtUH_bStPresLo_out = CoPtUH_bStPresLo_B;
      CoPtUH_bStopAuthSlop_out = CoPtUH_bStopAuthSlop_B;
      CoPtUH_bEngRstrtClsCluCdn_out = CoPtUH_bEngRstrtClsCluCdn_B;
      CoPtUH_bInhHiSpdAltRstrtReq_out = CoPtUH_bInhHiSpdAltRstrtReq_B;
      CoPtUH_pRelBrkAsi_out = CoPtUH_pRelBrkAsi_B;
  }
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bDeacHillAsi(MonVeh_bDeacHillAsi);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bHiSpdRstrtAuth(MonVeh_bHiSpdRstrtAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bInfoHillAsiDrvRstrt(MonVeh_bInfoHillAsiDrvRstrt);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bOpDrvTraAuth(MonVeh_bOpDrvTraAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bPresPtlRstrtReqForc(MonVeh_bPresPtlRstrtReqForc);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bPtlVehRstrtReqForc(MonVeh_bPtlVehRstrtReqForc);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bRstrtAuth(MonVeh_bRstrtAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bRstrtAuthMch(MonVeh_bRstrtAuthMch);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_bStopAuth(MonVeh_bStopAuth);
  (void)Rte_IrvWrite_RE_CoStopStart_032_TEV_MonVeh_stRstrtReq(MonVeh_stRstrtReq);
  (void)Rte_Write_P_CoPtUH_bStPresLo_CoPtUH_bStPresLo(CoPtUH_bStPresLo_out);
  (void)Rte_Write_P_CoPtUH_bStopAuthSlop_CoPtUH_bStopAuthSlop(CoPtUH_bStopAuthSlop_out);
  (void)Rte_Write_P_CoPtUH_bEngRstrtClsCluCdn_CoPtUH_bEngRstrtClsCluCdn(CoPtUH_bEngRstrtClsCluCdn_out);
  (void)Rte_Write_P_CoPtUH_bInhHiSpdAltRstrtReq_CoPtUH_bInhHiSpdAltRstrtReq(CoPtUH_bInhHiSpdAltRstrtReq_out);
  (void)Rte_Write_P_CoPtUH_pRelBrkAsi_CoPtUH_pRelBrkAsi(CoPtUH_pRelBrkAsi_out);

}


#define COSTOPSTART_STOP_SEC_CODE
#include "CoStopStart_MemMap.h"

#endif/*_COSTOPSTART_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

