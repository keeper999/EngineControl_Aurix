/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name: FARSp.c %
*
* %version: 6.0.build1 %
*
* %date_modified: Wed Dec 19 11:03:22 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp.c-6.0.build1:csrc:3 %
*
*******************************************************************************/

#ifndef _FARSP_C_
#define _FARSP_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_FARSp.h"
#include "FARSp.h"
#include "FARSp_002_TEV_fct.h"
#include "FARSp_004_TEV_fct.h"
#include "FARSp_006_TEV_fct.h"
#include "FARSp_006_calibrations.h"
#include "FARSp_008_TEV_fct.h"
#include "FARSp_008_calibrations.h"
#include "FARSp_010_TEV_fct.h"
#include "FARSp_012_TEV_fct.h"
#include "FARSp_014_TEV_fct.h"
#include "FARSp_016_TEV_fct.h"
#include "FARSp_018_TEV_fct.h"
#include "FARSp_022_TEV_fct.h"
#include "FARSp_024_TEV_fct.h"
#include "FARSp_026_TEV_fct.h"
#include "FARSp_RE026_calibrations.h"
#include "FARSp_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define FARSP_START_SEC_CONST_VERSION_MODULE_8BIT
#include "FARSp_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 FARSp_ModuleVersion_Major_MP = 6;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 FARSp_ModuleVersion_Minor_MP = 0;
#define FARSP_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "FARSp_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 5
#define Module_LIB_PSA_VERSION_REQ_MIN 1
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define FARSP_START_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_008_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_010_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_012_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_014_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_016_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_018_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_022_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_024_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_FARSp_026_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bDeacAntiStall_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bEnaAntiStall_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichLoTqReqNotAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichMixtAcv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bRichScvThermoInvld_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bSatMaxRatMixt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bSatMinRatMixt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bThermoProtReqNotAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_bStiBlbyNotAcv_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean FARSp_prm_bRlamSpAcv_B[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#define FARSP_STOP_SEC_CALIB_BOOLEAN
#include "FARSp_MemMap.h"

#define FARSP_START_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_prm_rMixtCylSp_B[6] = {4096,4096,4096,4096,4096,4096};
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSp_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSpWiStiTWC_B = 4096;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtFullLdSpRaw_B = 4096;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtThermoProtSp_B = 4096;
AR_MERGEABLE_CALIB_16BIT UInt16 FARSp_rMixtCylSpWoutStiBlby_B = 4096;
#define FARSP_STOP_SEC_CALIB_16BIT
#include "FARSp_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define FARSP_START_SEC_CODE
#include "FARSp_MemMap.h"
void RE_FARSp_001_MSE(void)
{
   FARSp_001_MSE_ini();

   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtScvExAfs(4096);
/*   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_001_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_002_TEV(void)
{
   if (FALSE == RE_FARSp_002_TEV_B)
   {
      (void)Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor(&FARSp_RE002_EngM_mfAirCor_in);
      (void)Rte_Read_R_EngM_mfAirScvCor_EngM_mfAirScvCor(&FARSp_RE002_EngM_mfAirScvCor_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE002_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE002_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stTypInjSysCf_Ext_stTypInjSysCf(&FARSp_RE002_Ext_stTypInjSysCf_in);

      FARSp_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_002_TEV_FARSp_bAcvAflScvGDI(FARSp_bAcvAflScvGDI_out);
   (void)Rte_IrvWrite_RE_FARSp_002_TEV_FARSp_rMixtBasSp(FARSp_rMixtBasSp_out);
   (void)Rte_IrvWrite_RE_FARSp_002_TEV_FARSp_rMixtScvExAfs(FARSp_rMixtScvExAfs_out);
   
}

void RE_FARSp_003_MSE(void)
{
   FARSp_003_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtScvExAfs(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtMaxThermoProt(4096);
/*   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_003_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);*
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);*/
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);/*
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_004_TEV(void)
{
   if (FALSE == RE_FARSp_004_TEV_B)
   {
	   UInt8 i;
      (void)Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&FARSp_RE004_EngM_mfTotExCor_in);
      (void)Rte_Read_R_ExM_stO2HcStgTWC_ExM_stO2HcStgTWC(&FARSp_RE004_ExM_stO2HcStgTWC_in);
      (void)Rte_Read_R_ExM_tExStatAfs_ExM_tExStatAfs(&FARSp_RE004_ExM_tExStatAfs_in);
      (void)Rte_Read_R_TPM_bAcvRichProtOxdTWC_TPM_bAcvRichProtOxdTWC(&FARSp_RE004_TPM_bAcvRichProtOxdTWC_in);
      (void)Rte_Read_R_TPM_bAcvRichThermoProt_TPM_bAcvRichThermoProt(&FARSp_RE004_TPM_bAcvRichThermoProt_in);
      (void)Rte_Read_R_TPM_bAirLdLimTExMgr_TPM_bAirLdLimTExMgr(&FARSp_RE004_TPM_bAirLdLimTExMgr_in);
      (void)Rte_Read_R_TPM_bRichLimScv_TPM_bRichLimScv(&FARSp_RE004_TPM_bRichLimScv_in);
      (void)Rte_Read_R_TPM_rMixtLimMaxAflScv_TPM_rMixtLimMaxAflScv(&FARSp_RE004_TPM_rMixtLimMaxAflScv_in);
      (void)Rte_Read_R_TPM_tExReq_TPM_tExReq(&FARSp_RE004_TPM_tExReq_in);
	  for (i=0;i<24;i++){
		FARSp_RE004_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE004_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      FARSp_rMixtThermoProtSp_out = FARSp_rMixtThermoProtSp_B;
   }
   (void)Rte_IrvWrite_RE_FARSp_004_TEV_FARSp_bInvldThermoProt(FARSp_bInvldThermoProt_out);
   (void)Rte_IrvWrite_RE_FARSp_004_TEV_FARSp_bThermoProtAuth(FARSp_bThermoProtAuth_out);
   (void)Rte_IrvWrite_RE_FARSp_004_TEV_FARSp_rMixtMaxThermoProt(FARSp_rMixtMaxThermoProt_out);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(FARSp_rMixtThermoProtSp_out);
   
}

void RE_FARSp_005_MSE(void)
{
   FARSp_005_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtMaxThermoProt(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtSelCutOffSp(4096);
/*   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_005_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_006_TEV(void)
{
   if (FALSE == RE_FARSp_006_TEV_B)
   {
	   UInt8 i;
      (void)Rte_Read_R_EngM_mfTotExCor_EngM_mfTotExCor(&FARSp_RE006_EngM_mfTotExCor_in);
      (void)Rte_Read_R_InjSys_noCylCutOff_InjSys_noCylCutOff(&FARSp_RE006_InjSys_noCylCutOff_in);
	  for (i=0;i<24;i++){
		FARSp_RE006_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE006_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_006_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_006_TEV_FARSp_bAcvSelCutOffSpcMixt(FARSp_bAcvSelCutOffSpcMixt_out);
   (void)Rte_IrvWrite_RE_FARSp_006_TEV_FARSp_rMixtSelCutOffSp(FARSp_rMixtSelCutOffSp_out);
   
}

void RE_FARSp_007_MSE(void)
{
   FARSp_007_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtSelCutOffSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtFullLdSp(4096);/*
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_007_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);*/
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);/*
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_008_TEV(void)
{
   if (FALSE == RE_FARSp_008_TEV_B)
   {
	  UInt8 i;
      (void)Rte_Read_R_AfuA_bFlexAdpAcv_AfuA_bFlexAdpAcv(&FARSp_RE008_AfuA_bFlexAdpAcv_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE008_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE008_Ext_nEng_in);
      (void)Rte_Read_R_TqSys_bAuthRich_TqSys_bAuthRich(&FARSp_RE008_TqSys_bAuthRich_in);
      (void)Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim(&FARSp_RE008_UsThrM_pAirExtEstim_in);
	  for (i=0;i<24;i++){
		FARSp_RE008_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE008_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_008_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      FARSp_rMixtFullLdSpRaw_out = FARSp_rMixtFullLdSpRaw_B;
   }
   (void)Rte_IrvWrite_RE_FARSp_008_TEV_FARSp_bAcvRichFullLd(FARSp_bAcvRichFullLd_out);
   (void)Rte_IrvWrite_RE_FARSp_008_TEV_FARSp_rMixtFullLdSp(FARSp_rMixtFullLdSp_out);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(FARSp_rMixtFullLdSpRaw_out);
   
}

void RE_FARSp_009_MSE(void)
{
   FARSp_009_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtFullLdSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtAstWupSTTSp(4096);/*
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_009_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_010_TEV(void)
{
   if (FALSE == RE_FARSp_010_TEV_B)
   {
	  UInt8 i;
      (void)Rte_Read_R_CoPTSt_bRStrtSTT_CoPTSt_bRStrtSTT(&FARSp_RE010_CoPTSt_bRStrtSTT_in);
      (void)Rte_Read_R_CoPTSt_tCoMesRStrtSTT_CoPTSt_tCoMesRStrtSTT(&FARSp_RE010_CoPTSt_tCoMesRStrtSTT_in);
      (void)Rte_Read_R_EOM_tiEngStopRst_EOM_tiEngStopRst(&FARSp_RE010_EOM_tiEngStopRst_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&FARSp_RE010_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&FARSp_RE010_Ext_tCoStrtMes_in);
      (void)Rte_Read_R_Ext_tiAst_Ext_tiAst(&FARSp_RE010_Ext_tiAst_in);
      (void)Rte_Read_R_InjSys_ctNbCmbAst_InjSys_ctNbCmbAst(&FARSp_RE010_InjSys_ctNbCmbAst_in);
      (void)Rte_Read_R_CoHeat_bAcvHeatMgt_CoHeat_bAcvHeatMgt(&FARSp_RE010_CoHeat_bAcvHeatMgt_in);
      (void)Rte_Read_R_CoHeat_tCoEstim_CoHeat_tCoEstim(&FARSp_RE010_CoHeat_tCoEstim_in);
      (void)Rte_Read_R_CoHeat_tCoEstimStrt_CoHeat_tCoEstimStrt(&FARSp_RE010_CoHeat_tCoEstimStrt_in);
	  for (i=0;i<24;i++){
		FARSp_RE010_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE010_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      Rte_Call_R_FRM_bLihAstWupSTT_GetFunctionPermission(&FARSp_RE010_FRM_bLihAstWupSTT_in);
      FARSp_RE010_FRM_bLihAstWupSTT_in = !FARSp_RE010_FRM_bLihAstWupSTT_in;
      FARSp_010_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_010_TEV_FARSp_rMixtAstWupSTTSp(FARSp_rMixtAstWupSTTSp_out);
   
}

void RE_FARSp_011_MSE(void)
{
   FARSp_011_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtAstWupSTTSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtTWCHeatSp(4096);/*
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_011_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_012_TEV(void)
{
   if (FALSE == RE_FARSp_012_TEV_B)
   {
	  UInt8 i;
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE012_EngM_rAirLdCor_in);
      (void)Rte_Read_R_EOM_bTWCHeatPha_EOM_bTWCHeatPha(&FARSp_RE012_EOM_bTWCHeatPha_in);
      (void)Rte_Read_R_EOM_prm_facBasModCur_EOM_prm_facBasModCur(FARSp_RE012_EOM_prm_facBasModCur_in);
      (void)Rte_Read_R_EOM_prm_facBasModTar_EOM_prm_facBasModTar(FARSp_RE012_EOM_prm_facBasModTar_in);
      (void)Rte_Read_R_EOM_prm_facTranMod_EOM_prm_facTranMod(FARSp_RE012_EOM_prm_facTranMod_in);
      (void)Rte_Read_R_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(FARSp_RE012_EOM_prm_idxBas1ModCur_in);
      (void)Rte_Read_R_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(FARSp_RE012_EOM_prm_idxBas1ModTar_in);
      (void)Rte_Read_R_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(FARSp_RE012_EOM_prm_idxBas2ModCur_in);
      (void)Rte_Read_R_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(FARSp_RE012_EOM_prm_idxBas2ModTar_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE012_Ext_nEng_in);
      (void)Rte_Read_R_TWCMgt_bLiOffDone_TWCMgt_bLiOffDone(&FARSp_RE012_TWCMgt_bLiOffDone_in);
	  for (i=0;i<24;i++){
		FARSp_RE012_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE012_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_012_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_012_TEV_FARSp_bAcvRatMixtTWCHeat(FARSp_bAcvRatMixtTWCHeat_out);
   (void)Rte_IrvWrite_RE_FARSp_012_TEV_FARSp_rMixtTWCHeatSp(FARSp_rMixtTWCHeatSp_out);
   
}

void RE_FARSp_013_MSE(void)
{
   FARSp_013_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtTWCHeatSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtLihSp(4096);/*
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_013_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_014_TEV(void)
{
   if (FALSE == RE_FARSp_014_TEV_B)
   {

      Rte_Call_R_FRM_bAcvAflLih_GetFunctionPermission(&FARSp_RE014_FRM_bAcvAflLih_in);
      FARSp_RE014_FRM_bAcvAflLih_in = !FARSp_RE014_FRM_bAcvAflLih_in;
      Rte_Call_R_FRM_bAcvAfrLih_GetFunctionPermission(&FARSp_RE014_FRM_bAcvAfrLih_in);
      FARSp_RE014_FRM_bAcvAfrLih_in = !FARSp_RE014_FRM_bAcvAfrLih_in;
      Rte_Call_R_FRM_bAcvAfsLih_GetFunctionPermission(&FARSp_RE014_FRM_bAcvAfsLih_in);
      FARSp_RE014_FRM_bAcvAfsLih_in = !FARSp_RE014_FRM_bAcvAfsLih_in;
      FARSp_014_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_014_TEV_FARSp_bLihAcv(FARSp_bLihAcv_out);
   (void)Rte_IrvWrite_RE_FARSp_014_TEV_FARSp_rMixtLihSp(FARSp_rMixtLihSp_out);
   
}

void RE_FARSp_015_MSE(void)
{

   FARSp_015_MSE_ini();

 /*  (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtLihSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtLoTqReqSp(4096);/*
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_015_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby_FARSp_rMixtCylSpWoutStiBlby(4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_016_TEV(void)
{
   if (FALSE == RE_FARSp_016_TEV_B)
   {
	  UInt8 i;
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE016_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE016_Ext_nEng_in);
      (void)Rte_Read_R_IgSys_agIgLimKnkMin_IgSys_agIgLimKnkMin(&FARSp_RE016_IgSys_agIgLimKnkMin_in);
      (void)Rte_Read_R_IgSys_agIgLimKnkMv_IgSys_agIgLimKnkMv(&FARSp_RE016_IgSys_agIgLimKnkMv_in);
      (void)Rte_Read_R_IgSys_agIgLimMinKnk_IgSys_agIgLimMinKnk(&FARSp_RE016_IgSys_agIgLimMinKnk_in);
      (void)Rte_Read_R_IgSys_agIgLimMinRef_IgSys_agIgLimMinRef(&FARSp_RE016_IgSys_agIgLimMinRef_in);
      (void)Rte_Read_R_IgSys_agIgMinCmb_IgSys_agIgMinCmb(&FARSp_RE016_IgSys_agIgMinCmb_in);
      (void)Rte_Read_R_IgSys_agIgSp_IgSys_agIgSp(&FARSp_RE016_IgSys_agIgSp_in);
      (void)Rte_Read_R_TPM_bExThermoProt_TPM_bExThermoProt(&FARSp_RE016_TPM_bExThermoProt_in);
	  for (i=0;i<24;i++){
		FARSp_RE016_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE016_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_016_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_016_TEV_FARSp_rMixtAgIgMinProtSp(FARSp_rMixtAgIgMinProtSp_out);
   (void)Rte_IrvWrite_RE_FARSp_016_TEV_FARSp_rMixtAutIgPrvtSp(FARSp_rMixtAutIgPrvtSp_out);
   (void)Rte_IrvWrite_RE_FARSp_016_TEV_FARSp_rMixtLoTqReqSp(FARSp_rMixtLoTqReqSp_out);
   
}

void RE_FARSp_017_MSE(void)
{
   FARSp_017_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtLoTqReqSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtTWCPurgeSp(4096);
/*   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_017_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_018_TEV(void)
{
   if (FALSE == RE_FARSp_018_TEV_B)
   {
	  UInt8 i;
      (void)Rte_Read_R_CoPTSt_bRStrtSTT_CoPTSt_bRStrtSTT(&FARSp_RE018_CoPTSt_bRStrtSTT_in);
      (void)Rte_Read_R_CoPTSt_tCoMesRStrtSTT_CoPTSt_tCoMesRStrtSTT(&FARSp_RE018_CoPTSt_tCoMesRStrtSTT_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE018_EngM_rAirLdCor_in);
      (void)Rte_Read_R_ExM_mO2StgCur_ExM_mO2StgCur(&FARSp_RE018_ExM_mO2StgCur_in);
      (void)Rte_Read_R_ExM_mO2StgEngStop_ExM_mO2StgEngStop(&FARSp_RE018_ExM_mO2StgEngStop_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE018_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tiAst_Ext_tiAst(&FARSp_RE018_Ext_tiAst_in);
      (void)Rte_Read_R_Ext_uLsDsMes_Ext_uLsDsMes(&FARSp_RE018_Ext_uLsDsMes_in);
      (void)Rte_Read_R_LsSys_bLsDsMainOxCHeatOk_LsSys_bLsDsMainOxCHeatOk(&FARSp_RE018_LsSys_bLsDsMainOxCHeatOk_in);
      (void)Rte_Read_R_UsThrM_pAirExtEstim_UsThrM_pAirExtEstim(&FARSp_RE018_UsThrM_pAirExtEstim_in);
	  for (i=0;i<24;i++){
		FARSp_RE018_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE018_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_018_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_FARSp_018_TEV_FARSp_rMixtTWCPurgeSp(FARSp_rMixtTWCPurgeSp_out);
   
}

void RE_FARSp_021_MSE(void)
{
   Boolean TAB_FARSp_prm_bRlamSpAcv[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   UInt16 TAB_FARSp_prm_rMixtCylSp[6] = {4096,4096,4096,4096,4096,4096};
   FARSp_021_MSE_ini();

/*   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_rMixtSpAntiStall(4096);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_021_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);*/
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_bRlamSpAcv_FARSp_prm_bRlamSpAcv(TAB_FARSp_prm_bRlamSpAcv);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
/*   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);*/
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby_FARSp_rMixtCylSpWoutStiBlby(4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);
}

void RE_FARSp_022_TEV(void)
{
   UInt8 i;
   if (FALSE == RE_FARSp_022_TEV_B)
   {
      (void)Rte_Read_R_Afts_bAcvRlamSpTest_Afts_bAcvRlamSpTest(&FARSp_RE022_Afts_bAcvRlamSpTest_in);
      (void)Rte_Read_R_Afts_rMixtReqRlamSpTest_Afts_rMixtReqRlamSpTest(&FARSp_RE022_Afts_rMixtReqRlamSpTest_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE022_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE022_Ext_nEng_in);
      (void)Rte_Read_R_FARSp_rDeltaMixtStiTWCSp_FARSp_rDeltaMixtStiTWCSp(&FARSp_RE022_FARSp_rDeltaMixtStiTWCSp_in);
      (void)Rte_Read_R_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(&FARSp_RE022_FARSp_rMixtThermoProtSp_in);
      (void)Rte_Read_R_InjSys_bTotCutOff_InjSys_bTotCutOff(&FARSp_RE022_InjSys_bTotCutOff_in);
      (void)Rte_Read_R_InjSys_prm_bCylCutOff_InjSys_prm_bCylCutOff(FARSp_RE022_InjSys_prm_bCylCutOff_in);
      (void)Rte_Read_R_LsMon_bAcvReqMonItrsv_LsMon_bAcvReqMonItrsv(&FARSp_RE022_LsMon_bAcvReqMonItrsv_in);
      (void)Rte_Read_R_LsMon_rMixtReqMonItrsv_LsMon_rMixtReqMonItrsv(&FARSp_RE022_LsMon_rMixtReqMonItrsv_in);
      (void)Rte_Read_R_OxC_bAcvReqMonItrsv_OxC_bAcvReqMonItrsv(&FARSp_RE022_OxC_bAcvReqMonItrsv_in);
      (void)Rte_Read_R_OxC_rMixtReqMonItrsv_OxC_rMixtReqMonItrsv(&FARSp_RE022_OxC_rMixtReqMonItrsv_in);
      (void)Rte_Read_R_Blby_bAcvStiRich_Blby_bAcvStiRich(&FARSp_RE022_Blby_bAcvStiRich_in);
      (void)Rte_Read_R_Blby_facStiRich_Blby_facStiRich(&FARSp_RE022_Blby_facStiRich_in);
      (void)Rte_Read_R_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(&FARSp_RE022_FARSp_bEnaAntiStall_in);
      FARSp_RE022_FARSp_bAcvAflScvGDI_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bAcvAflScvGDI();
      FARSp_RE022_FARSp_rMixtBasSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtBasSp();
      FARSp_RE022_FARSp_rMixtScvExAfs_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtScvExAfs();
      FARSp_RE022_FARSp_bInvldThermoProt_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bInvldThermoProt();
      FARSp_RE022_FARSp_bThermoProtAuth_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bThermoProtAuth();
      FARSp_RE022_FARSp_rMixtMaxThermoProt_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtMaxThermoProt();
      FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bAcvSelCutOffSpcMixt();
      FARSp_RE022_FARSp_rMixtSelCutOffSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtSelCutOffSp();
      FARSp_RE022_FARSp_bAcvRichFullLd_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bAcvRichFullLd();
      FARSp_RE022_FARSp_rMixtFullLdSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtFullLdSp();
      FARSp_RE022_FARSp_rMixtAstWupSTTSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtAstWupSTTSp();
      FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bAcvRatMixtTWCHeat();
      FARSp_RE022_FARSp_rMixtTWCHeatSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtTWCHeatSp();
      FARSp_RE022_FARSp_bLihAcv_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_bLihAcv();
      FARSp_RE022_FARSp_rMixtLihSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtLihSp();
      FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtAgIgMinProtSp();
      FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtAutIgPrvtSp();
      FARSp_RE022_FARSp_rMixtLoTqReqSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtLoTqReqSp();
      FARSp_RE022_FARSp_rMixtTWCPurgeSp_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtTWCPurgeSp();
      FARSp_RE022_FARSp_rMixtSpAntiStall_in = Rte_IrvRead_RE_FARSp_022_TEV_FARSp_rMixtSpAntiStall();
	  for (i=0;i<24;i++){
		FARSp_RE022_FARSp_prm_facGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_facGasFlexSp())[i];
		FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[i] = (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i];
	  }
      FARSp_022_TEV_fct();
   }
   else
   {

      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      FARSp_bRichLoTqReqNotAuth_out = FARSp_bRichLoTqReqNotAuth_B;
      FARSp_bRichMixtAcv_out = FARSp_bRichMixtAcv_B;
      FARSp_bRichScvThermoInvld_out = FARSp_bRichScvThermoInvld_B;
      FARSp_bSatMaxRatMixt_out = FARSp_bSatMaxRatMixt_B;
      FARSp_bSatMinRatMixt_out = FARSp_bSatMinRatMixt_B;
      FARSp_bThermoProtReqNotAuth_out = FARSp_bThermoProtReqNotAuth_B;
      for(i=0;i<20;i++)
		FARSp_prm_bRlamSpAcv_out[i] = FARSp_prm_bRlamSpAcv_B[i];
	  for(i=0;i<6;i++)
		FARSp_prm_rMixtCylSp_out[i] = FARSp_prm_rMixtCylSp_B[i];
      FARSp_rMixtCylSp_out = FARSp_rMixtCylSp_B;
      FARSp_rMixtCylSpWiStiTWC_out = FARSp_rMixtCylSpWiStiTWC_B;
      FARSp_rMixtCylSpWoutStiBlby_out = FARSp_rMixtCylSpWoutStiBlby_B;
      FARSp_bStiBlbyNotAcv_out = FARSp_bStiBlbyNotAcv_B;
   }
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(FARSp_bRichLoTqReqNotAuth_out);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(FARSp_bRichMixtAcv_out);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(FARSp_bRichScvThermoInvld_out);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(FARSp_bSatMaxRatMixt_out);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(FARSp_bSatMinRatMixt_out);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(FARSp_bThermoProtReqNotAuth_out);
   (void)Rte_Write_P_FARSp_prm_bRlamSpAcv_FARSp_prm_bRlamSpAcv(FARSp_prm_bRlamSpAcv_out);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(FARSp_prm_rMixtCylSp_out);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(FARSp_rMixtCylSp_out);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(FARSp_rMixtCylSpWiStiTWC_out);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby_FARSp_rMixtCylSpWoutStiBlby(FARSp_rMixtCylSpWoutStiBlby_out);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(FARSp_bStiBlbyNotAcv_out);
   
}

void RE_FARSp_023_MSE(void)
{
   FARSp_023_MSE_ini();

 /*  (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtTWCPurgeSp(4096);*/
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_rMixtSpAntiStall(4096);
/*   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_prm_rMixtGasFlexSp ([4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096 4096]);
   (void)Rte_IrvWrite_RE_FARSp_023_MSE_FARSp_prm_facGasFlexSp([0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]);*/
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);/*
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_024_TEV(void)
{
   if (FALSE == RE_FARSp_024_TEV_B)
   {
      (void)Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&FARSp_RE024_CoPt_noEgdGearCord_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&FARSp_RE024_Ext_tCoMes_in);
      (void)Rte_Read_R_IdlSys_bAcvAntiStall_IdlSys_bAcvAntiStall(&FARSp_RE024_IdlSys_bAcvAntiStall_in);
      (void)Rte_Read_R_IdlSys_bEnaAntiStall_IdlSys_bEnaAntiStall(&FARSp_RE024_IdlSys_bEnaAntiStall_in);

      FARSp_024_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      FARSp_bDeacAntiStall_out = FARSp_bDeacAntiStall_B;
      FARSp_bEnaAntiStall_out = FARSp_bEnaAntiStall_B;
   }
   (void)Rte_IrvWrite_RE_FARSp_024_TEV_FARSp_rMixtSpAntiStall(FARSp_rMixtSpAntiStall_out);
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(FARSp_bDeacAntiStall_out);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(FARSp_bEnaAntiStall_out);
   
}

void RE_FARSp_025_MSE(void)
{
   UInt8 i;
   FARSp_025_MSE_ini();

 /*  (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bAcvAflScvGDI(1);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtBasSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtScvExAfs(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bInvldThermoProt(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bThermoProtAuth(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtMaxThermoProt(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bAcvSelCutOffSpcMixt(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtSelCutOffSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bAcvRichFullLd(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtFullLdSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtAstWupSTTSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bAcvRatMixtTWCHeat(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtTWCHeatSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_bLihAcv(0);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtLihSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtAgIgMinProtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtAutIgPrvtSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtLoTqReqSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtTWCPurgeSp(4096);
   (void)Rte_IrvWrite_RE_FARSp_025_MSE_FARSp_rMixtSpAntiStall(4096);*/
    for (i=0;i<24;i++){
	   (*Rte_Pim_FARSp_prm_facGasFlexSp())[i] = 0;
	   (*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i] = 4096;
	}
   /*
   (void)Rte_Write_P_FARSp_bDeacAntiStall_FARSp_bDeacAntiStall(0);
   (void)Rte_Write_P_FARSp_bEnaAntiStall_FARSp_bEnaAntiStall(0);
   (void)Rte_Write_P_FARSp_bRichLoTqReqNotAuth_FARSp_bRichLoTqReqNotAuth(0);
   (void)Rte_Write_P_FARSp_bRichMixtAcv_FARSp_bRichMixtAcv(0);
   (void)Rte_Write_P_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(0);
   (void)Rte_Write_P_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(0);
   (void)Rte_Write_P_FARSp_bSatMinRatMixt_FARSp_bSatMinRatMixt(0);
   (void)Rte_Write_P_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(0);
   (void)Rte_Write_P_FARSp_prm_rMixtCylSp_FARSp_prm_rMixtCylSp(TAB_FARSp_prm_rMixtCylSp);
   (void)Rte_Write_P_FARSp_rMixtCylSp_FARSp_rMixtCylSp(0);
   (void)Rte_Write_P_FARSp_rMixtCylSpWiStiTWC_FARSp_rMixtCylSpWiStiTWC(4096);
   (void)Rte_Write_P_FARSp_rMixtFullLdSpRaw_FARSp_rMixtFullLdSpRaw(4096);
   (void)Rte_Write_P_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(4096);
   (void)Rte_Write_P_FARSp_rMixtCylSpWoutStiBlby _FARSp_rMixtCylSpWoutStiBlby (4096);
   (void)Rte_Write_P_FARSp_bStiBlbyNotAcv_FARSp_bStiBlbyNotAcv(1);*/
}

void RE_FARSp_026_TEV(void)
{
   UInt8 i;
   if (FALSE == RE_FARSp_026_TEV_B)
   {
      (void)Rte_Read_R_CoPTSt_bRStrtSTT_CoPTSt_bRStrtSTT(&FARSp_RE026_CoPTSt_bRStrtSTT_in);
      (void)Rte_Read_R_CoPTSt_tCoMesRStrtSTT_CoPTSt_tCoMesRStrtSTT(&FARSp_RE026_CoPTSt_tCoMesRStrtSTT_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&FARSp_RE026_EngM_rAirLdCor_in);
      (void)Rte_Read_R_EOM_prm_facBasModCur_EOM_prm_facBasModCur(FARSp_RE026_EOM_prm_facBasModCur_in);
      (void)Rte_Read_R_EOM_prm_facBasModTar_EOM_prm_facBasModTar(FARSp_RE026_EOM_prm_facBasModTar_in);
      (void)Rte_Read_R_EOM_prm_facTranMod_EOM_prm_facTranMod(FARSp_RE026_EOM_prm_facTranMod_in);
      (void)Rte_Read_R_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(FARSp_RE026_EOM_prm_idxBas1ModCur_in);
      (void)Rte_Read_R_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(FARSp_RE026_EOM_prm_idxBas1ModTar_in);
      (void)Rte_Read_R_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(FARSp_RE026_EOM_prm_idxBas2ModCur_in);
      (void)Rte_Read_R_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(FARSp_RE026_EOM_prm_idxBas2ModTar_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&FARSp_RE026_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&FARSp_RE026_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&FARSp_RE026_Ext_tCoStrtMes_in);
      (void)Rte_Read_R_InjSys_ctNbCmbAst_InjSys_ctNbCmbAst(&FARSp_RE026_InjSys_ctNbCmbAst_in);
      (void)Rte_Read_R_AfuA_rEthWiExct_AfuA_rEthWiExct(&FARSp_RE026_AfuA_rEthWiExct_in);
      (void)Rte_Read_R_AfuA_bInvldEthRat_AfuA_bInvldEthRat(&FARSp_RE026_AfuA_bInvldEthRat_in);

      FARSp_026_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   for (i=0;i<24;i++){
		(*Rte_Pim_FARSp_prm_facGasFlexSp())[i] = FARSp_prm_facGasFlexSp_out[i];
		(*Rte_Pim_FARSp_prm_rMixtGasFlexSp())[i] = FARSp_prm_rMixtGasFlexSp_out[i];
	}
   
}

#define FARSP_STOP_SEC_CODE
#include "FARSp_MemMap.h"

#endif/*_FARSP_C_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
