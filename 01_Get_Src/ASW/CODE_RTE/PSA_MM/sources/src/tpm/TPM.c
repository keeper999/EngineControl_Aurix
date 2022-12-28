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
* %name: TPM.c %
*
* %version: 3.3 %
*
* %date_modified: Thu May  2 11:30:46 2013 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC4.3 %
* %full_filespec: TPM.c-3.3:csrc:1 %
*
*******************************************************************************/

#ifndef _TPM_C_
#define _TPM_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_TPM.h"
#include "TPM.h"
#include "TPM_code.h"
#include "TPM_calibrations.h"
#include "TPM_nvm.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define TPM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TPM_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TPM_ModuleVersion_Major_MP = 3;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TPM_ModuleVersion_Minor_MP = 3;
#define TPM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TPM_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 6
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TPM_START_SEC_CALIB_BOOLEAN
#include "TPM_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAcvRichProtOxdTWC_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAcvRichThermoProt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bAirLdLimTExMgr_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bExThermoProt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhOvbReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bRichLimScv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhInjCutOff_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TPM_bInhInjSelCutOff_B = 0;
#define TPM_STOP_SEC_CALIB_BOOLEAN
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_8BIT
#include "TPM_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 ExM_stO2HcStgTWC_B = 0;
#define TPM_STOP_SEC_CALIB_8BIT
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_16BIT
#include "TPM_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 TPM_rMixtLimMaxAflScv_B = 5325;
AR_MERGEABLE_CALIB_16BIT UInt16 TPM_tTarAcvThermoProtDev_B = 31777;
AR_MERGEABLE_CALIB_16BIT UInt16 TPM_mfAirScvLimMaxCor_B = 65535;
AR_MERGEABLE_CALIB_16BIT UInt16 TPM_tExReq_B = 29664;
AR_MERGEABLE_CALIB_16BIT UInt16 TPM_rLdProtExThermo_B = 49152;
AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_pwrCylHdEstim_B = 106;
AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_tExMnfEstim_B = 7136;
AR_MERGEABLE_CALIB_16BIT UInt16 PhyMSI_tTrbCaseEstim_B = 7136;
#define TPM_STOP_SEC_CALIB_16BIT
#include "TPM_MemMap.h"

#define TPM_START_SEC_CALIB_32BIT
#include "TPM_MemMap.h"
AR_MERGEABLE_CALIB_32BIT UInt32 PhyMSI_pCylMaxEstim_B = 0;
#define TPM_STOP_SEC_CALIB_32BIT
#include "TPM_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define TPM_START_SEC_CODE
#include "TPM_MemMap.h"
void RE_TPM_001_MSE(void)
{
	UInt16 *Ptr16_1;
	UInt16 *Ptr16_2;

	Ptr16_1 = &TPM_sNV_Z1_CST_16BIT.PhyMSI_tExMnfEstim_NV;
	Ptr16_2 = &TPM_sNV_Z1_CST_16BIT.PhyMSI_tTrbCaseEstim_NV;

	TEMP_PhyMSI_tExMnfEstim_NV = *Ptr16_1 ;
	TEMP_PhyMSI_tTrbCaseEstim_NV = *Ptr16_2;

    (void)Rte_Read_R_Ext_tAir_Ext_tAir(&TPM_RE001_Ext_tAir_in);
    (void)Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&TPM_RE001_EOM_tiEngStop_in);

   TPM_FctVarInit();
   TPM_Init_MSE_fct();

   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_mfAirScvLimMax(TPM_mfAirScvUnLim_C);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_tRefTWCScvMax(0);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_noAcvThermoProtDev(0);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_tExCurAcvThermoProtDev(56864);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_tTWC(2240);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_bAcvProtExScv(0);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_rAirLdReqRbl(49152);
   (void)Rte_IrvWrite_RE_TPM_001_MSE_TPM_rAirLdReq(49152);
   (void)Rte_Write_P_TPM_rMixtLimMaxAflScv_TPM_rMixtLimMaxAflScv(5325);
   (void)Rte_Write_P_TPM_bAcvRichProtOxdTWC_TPM_bAcvRichProtOxdTWC(0);
   (void)Rte_Write_P_TPM_bAcvRichThermoProt_TPM_bAcvRichThermoProt(0);
   (void)Rte_Write_P_TPM_bAirLdLimTExMgr_TPM_bAirLdLimTExMgr(0);
   (void)Rte_Write_P_TPM_bExThermoProt_TPM_bExThermoProt(0);
   (void)Rte_Write_P_TPM_bInhOvbReq_TPM_bInhOvbReq(0);
   (void)Rte_Write_P_TPM_tTarAcvThermoProtDev_TPM_tTarAcvThermoProtDev(32000);
   (void)Rte_Write_P_TPM_bRichLimScv_TPM_bRichLimScv(0);
   (void)Rte_Write_P_TPM_mfAirScvLimMaxCor_TPM_mfAirScvLimMaxCor(65535);
   (void)Rte_Write_P_TPM_bInhInjCutOff_TPM_bInhInjCutOff(0);
   (void)Rte_Write_P_TPM_bInhInjSelCutOff_TPM_bInhInjSelCutOff(0);
   (void)Rte_Write_P_TPM_tExReq_TPM_tExReq(TPM_tExNotReq_C);
   (void)Rte_Write_P_TPM_rLdProtExThermo_TPM_rLdProtExThermo(49152);
   (void)Rte_Write_P_PhyMSI_pCylMaxEstim_PhyMSI_pCylMaxEstim(0);
   (void)Rte_Write_P_PhyMSI_pwrCylHdEstim_PhyMSI_pwrCylHdEstim(PhyMSI_pwrCylHdEstim_out);
   (void)Rte_Write_P_PhyMSI_tExMnfEstim_PhyMSI_tExMnfEstim(PhyMSI_tExMnfEstim_out);
   (void)Rte_Write_P_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(PhyMSI_tTrbCaseEstim_out);
   (void)Rte_Write_P_ExM_stO2HcStgTWC_ExM_stO2HcStgTWC(0);

}

void RE_TPM_002_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor(&TPM_RE002_EngM_mfAirCor_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE002_EngM_rAirLdCor_in);
      (void)Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&TPM_RE002_ExM_mfEgTot_in);
      (void)Rte_Read_R_ExM_prm_tEg_ExM_prm_tEg(&TPM_RE002_ExM_prm_tEg_in);
      (void)Rte_Read_R_ExM_prm_tWall_ExM_prm_tWall(&TPM_RE002_ExM_prm_tWall_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE002_Ext_nEng_in);
      (void)Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&TPM_RE002_FARSp_rMixtCylSp_in);
      (void)Rte_Read_R_ExM_stO2HcStgTWC_ExM_stO2HcStgTWC(&TPM_RE002_ExM_stO2HcStgTWC_in);

      TPM_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_rMixtLimMaxAflScv_out = TPM_rMixtLimMaxAflScv_B;
   }
   (void)Rte_IrvWrite_RE_TPM_002_TEV_TPM_mfAirScvLimMax(RE002_TPM_mfAirScvLimMax_out);
   (void)Rte_IrvWrite_RE_TPM_002_TEV_TPM_tRefTWCScvMax(RE002_TPM_tRefTWCScvMax_out);
   (void)Rte_Write_P_TPM_rMixtLimMaxAflScv_TPM_rMixtLimMaxAflScv(TPM_rMixtLimMaxAflScv_out);

}

void RE_TPM_003_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ExM_prm_tEg_ExM_prm_tEg(&TPM_RE003_ExM_prm_tEg_in);
      (void)Rte_Read_R_ExM_prm_tWall_ExM_prm_tWall(&TPM_RE003_ExM_prm_tWall_in);
      (void)Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&TPM_RE003_FARSp_rMixtCylSp_in);
      (void)Rte_Read_R_DmgMSI_bLdLimReq_DmgMSI_bLdLimReq(&TPM_RE003_DmgMSI_bLdLimReq_in);
      (void)Rte_Read_R_DmgMSI_bMPMInh_DmgMSI_bMPMInh(&TPM_RE003_DmgMSI_bMPMInh_in);
      (void)Rte_Read_R_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(&TPM_RE003_FARSp_bRichScvThermoInvld_in);
      (void)Rte_Read_R_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(&TPM_RE003_FARSp_bSatMaxRatMixt_in);
      (void)Rte_Read_R_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(&TPM_RE003_FARSp_bThermoProtReqNotAuth_in);
      (void)Rte_Read_R_IgSys_agIgMinThermo_IgSys_agIgMinThermo(&TPM_RE003_IgSys_agIgMinThermo_in);
      (void)Rte_Read_R_IgSys_prm_agIgSpCyl_IgSys_prm_agIgSpCyl(&TPM_RE003_IgSys_prm_agIgSpCyl_in);
      (void)Rte_Read_R_PhyMSI_tExMnfEstim_PhyMSI_tExMnfEstim(&TPM_RE003_PhyMSI_tExMnfEstim_in);
      (void)Rte_Read_R_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(&TPM_RE003_PhyMSI_tTrbCaseEstim_in);
      (void)Rte_Read_R_ThMgt_bAcvR1234Mgt_ThMgt_bAcvR1234Mgt(&TPM_RE003_ThMgt_bAcvR1234Mgt_in);

      Rte_Call_R_FRM_bAcvEcpHeatProt_GetFunctionPermission(&TPM_RE003_FRM_bAcvEcpHeatProt_in);
      TPM_RE003_FRM_bAcvEcpHeatProt_in = !TPM_RE003_FRM_bAcvEcpHeatProt_in;
      Rte_Call_R_FRM_bAcvTPMDecTMaxDev_GetFunctionPermission(&TPM_RE003_FRM_bAcvTPMDecTMaxDev_in);
      TPM_RE003_FRM_bAcvTPMDecTMaxDev_in = !TPM_RE003_FRM_bAcvTPMDecTMaxDev_in;
      TPM_003_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_bAcvRichProtOxdTWC_out = TPM_bAcvRichProtOxdTWC_B;
      TPM_bAcvRichThermoProt_out = TPM_bAcvRichThermoProt_B;
      TPM_bAirLdLimTExMgr_out = TPM_bAirLdLimTExMgr_B;
      TPM_bExThermoProt_out = TPM_bExThermoProt_B;
      TPM_bInhOvbReq_out = TPM_bInhOvbReq_B;
      TPM_tTarAcvThermoProtDev_out = TPM_tTarAcvThermoProtDev_B;
   }
   (void)Rte_IrvWrite_RE_TPM_003_TEV_TPM_noAcvThermoProtDev(RE003_TPM_noAcvThermoProtDev_out);
   (void)Rte_IrvWrite_RE_TPM_003_TEV_TPM_tExCurAcvThermoProtDev(RE003_TPM_tExCurAcvThermoProtDev_out);
   (void)Rte_IrvWrite_RE_TPM_003_TEV_TPM_tTWC(RE003_TPM_tTWC_out);
   (void)Rte_Write_P_TPM_bAcvRichProtOxdTWC_TPM_bAcvRichProtOxdTWC(TPM_bAcvRichProtOxdTWC_out);
   (void)Rte_Write_P_TPM_bAcvRichThermoProt_TPM_bAcvRichThermoProt(TPM_bAcvRichThermoProt_out);
   (void)Rte_Write_P_TPM_bAirLdLimTExMgr_TPM_bAirLdLimTExMgr(TPM_bAirLdLimTExMgr_out);
   (void)Rte_Write_P_TPM_bExThermoProt_TPM_bExThermoProt(TPM_bExThermoProt_out);
   (void)Rte_Write_P_TPM_bInhOvbReq_TPM_bInhOvbReq(TPM_bInhOvbReq_out);
   (void)Rte_Write_P_TPM_tTarAcvThermoProtDev_TPM_tTarAcvThermoProtDev(TPM_tTarAcvThermoProtDev_out);

}

void RE_TPM_004_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE004_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE004_Ext_nEng_in);
      (void)Rte_Read_R_FARSp_bRichScvThermoInvld_FARSp_bRichScvThermoInvld(&TPM_RE004_FARSp_bRichScvThermoInvld_in);
      (void)Rte_Read_R_EngM_mfAirScvCor_EngM_mfAirScvCor(&TPM_RE004_EngM_mfAirScvCor_in);
      (void)Rte_Read_R_UsThrM_facPresAltiCor_UsThrM_facPresAltiCor(&TPM_RE004_UsThrM_facPresAltiCor_in);
      (void)Rte_Read_R_ExM_stO2HcStgTWC_ExM_stO2HcStgTWC(&TPM_RE004_ExM_stO2HcStgTWC_in);
      RE004_TPM_mfAirScvLimMax_in = Rte_IrvRead_RE_TPM_004_TEV_TPM_mfAirScvLimMax();
      RE004_TPM_tRefTWCScvMax_in = Rte_IrvRead_RE_TPM_004_TEV_TPM_tRefTWCScvMax();

      Rte_Call_R_FRM_bAcvTPMDecTMaxDev_GetFunctionPermission(&TPM_RE004_FRM_bAcvTPMDecTMaxDev_in);
      TPM_RE004_FRM_bAcvTPMDecTMaxDev_in = !TPM_RE004_FRM_bAcvTPMDecTMaxDev_in;
      Rte_Call_R_FRM_bAcvLimScv_GetFunctionPermission(&TPM_RE004_FRM_bAcvLimScv_in);
      TPM_RE004_FRM_bAcvLimScv_in = !TPM_RE004_FRM_bAcvLimScv_in;
      TPM_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_bRichLimScv_out = TPM_bRichLimScv_B;
      TPM_mfAirScvLimMaxCor_out = TPM_mfAirScvLimMaxCor_B;
   }
   (void)Rte_IrvWrite_RE_TPM_004_TEV_TPM_bAcvProtExScv(RE004_TPM_bAcvProtExScv_out);
   (void)Rte_IrvWrite_RE_TPM_004_TEV_TPM_rAirLdReqRbl(RE004_TPM_rAirLdReqRbl_out);
   (void)Rte_Write_P_TPM_bRichLimScv_TPM_bRichLimScv(TPM_bRichLimScv_out);
   (void)Rte_Write_P_TPM_mfAirScvLimMaxCor_TPM_mfAirScvLimMaxCor(TPM_mfAirScvLimMaxCor_out);

}

void RE_TPM_005_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_mfAirCor_EngM_mfAirCor(&TPM_RE005_EngM_mfAirCor_in);
      (void)Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&TPM_RE005_FARSp_rMixtCylSp_in);
      (void)Rte_Read_R_EngM_mfAirScvCor_EngM_mfAirScvCor(&TPM_RE005_EngM_mfAirScvCor_in);
      (void)Rte_Read_R_ExM_lamTot_ExM_lamTot(&TPM_RE005_ExM_lamTot_in);
      (void)Rte_Read_R_Ext_uLsDsMes_Ext_uLsDsMes(&TPM_RE005_Ext_uLsDsMes_in);
      RE005_TPM_tTWC_in = Rte_IrvRead_RE_TPM_005_TEV_TPM_tTWC();

      Rte_Call_R_FRM_bAcvTPMDecTMaxDev_GetFunctionPermission(&TPM_RE005_FRM_bAcvTPMDecTMaxDev_in);
      TPM_RE005_FRM_bAcvTPMDecTMaxDev_in = !TPM_RE005_FRM_bAcvTPMDecTMaxDev_in;
      Rte_Call_R_FRM_bAcvTPMInhLsTWCSt_GetFunctionPermission(&TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in);
      TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in = !TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in;
      Rte_Call_R_FRM_bInhCutOff_GetFunctionPermission(&TPM_RE005_FRM_bInhCutOff_in);
      TPM_RE005_FRM_bInhCutOff_in = !TPM_RE005_FRM_bInhCutOff_in;
      TPM_005_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_bInhInjCutOff_out = TPM_bInhInjCutOff_B;
      TPM_bInhInjSelCutOff_out = TPM_bInhInjSelCutOff_B;
      ExM_stO2HcStgTWC_out = ExM_stO2HcStgTWC_B;
   }
   (void)Rte_Write_P_TPM_bInhInjCutOff_TPM_bInhInjCutOff(TPM_bInhInjCutOff_out);
   (void)Rte_Write_P_TPM_bInhInjSelCutOff_TPM_bInhInjSelCutOff(TPM_bInhInjSelCutOff_out);
   (void)Rte_Write_P_ExM_stO2HcStgTWC_ExM_stO2HcStgTWC(ExM_stO2HcStgTWC_out);

}

void RE_TPM_006_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE006_EngM_rAirLdCor_in);
      (void)Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&TPM_RE006_ExM_mfEgTot_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE006_Ext_nEng_in);
      (void)Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&TPM_RE006_FARSp_rMixtCylSp_in);
      (void)Rte_Read_R_FARSp_bSatMaxRatMixt_FARSp_bSatMaxRatMixt(&TPM_RE006_FARSp_bSatMaxRatMixt_in);
      (void)Rte_Read_R_FARSp_bThermoProtReqNotAuth_FARSp_bThermoProtReqNotAuth(&TPM_RE006_FARSp_bThermoProtReqNotAuth_in);
      (void)Rte_Read_R_EngMTrb_rLdMax_EngMTrb_rLdMax(&TPM_RE006_EngMTrb_rLdMax_in);
      (void)Rte_Read_R_ExM_tExStatAfs_ExM_tExStatAfs(&TPM_RE006_ExM_tExStatAfs_in);
      (void)Rte_Read_R_FARSp_rMixtThermoProtSp_FARSp_rMixtThermoProtSp(&TPM_RE006_FARSp_rMixtThermoProtSp_in);
      (void)Rte_Read_R_TPM_bAcvRichProtOxdTWC_TPM_bAcvRichProtOxdTWC(&TPM_RE006_TPM_bAcvRichProtOxdTWC_in);
      (void)Rte_Read_R_TPM_bAcvRichThermoProt_TPM_bAcvRichThermoProt(&TPM_RE006_TPM_bAcvRichThermoProt_in);
      (void)Rte_Read_R_TPM_bAirLdLimTExMgr_TPM_bAirLdLimTExMgr(&TPM_RE006_TPM_bAirLdLimTExMgr_in);
      (void)Rte_Read_R_TPM_tTarAcvThermoProtDev_TPM_tTarAcvThermoProtDev(&TPM_RE006_TPM_tTarAcvThermoProtDev_in);
      RE006_TPM_noAcvThermoProtDev_in = Rte_IrvRead_RE_TPM_006_TEV_TPM_noAcvThermoProtDev();
      RE006_TPM_tExCurAcvThermoProtDev_in = Rte_IrvRead_RE_TPM_006_TEV_TPM_tExCurAcvThermoProtDev();
      RE006_TPM_bAcvProtExScv_in = Rte_IrvRead_RE_TPM_006_TEV_TPM_bAcvProtExScv();
      RE006_TPM_rAirLdReqRbl_in = Rte_IrvRead_RE_TPM_006_TEV_TPM_rAirLdReqRbl();
      RE006_TPM_rAirLdReq_in = Rte_IrvRead_RE_TPM_006_TEV_TPM_rAirLdReq();

      Rte_Call_R_FRM_bAcvTPMDecTMaxDev_GetFunctionPermission(&TPM_RE006_FRM_bAcvTPMDecTMaxDev_in);
      TPM_RE006_FRM_bAcvTPMDecTMaxDev_in = !TPM_RE006_FRM_bAcvTPMDecTMaxDev_in;
      TPM_006_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_tExReq_out = TPM_tExReq_B;
   }
   (void)Rte_Write_P_TPM_tExReq_TPM_tExReq(TPM_tExReq_out);

}

void RE_TPM_007_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE007_EngM_rAirLdCor_in);
      (void)Rte_Read_R_ExM_mfEgTot_ExM_mfEgTot(&TPM_RE007_ExM_mfEgTot_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE007_Ext_nEng_in);
      (void)Rte_Read_R_TPM_bAirLdLimTExMgr_TPM_bAirLdLimTExMgr(&TPM_RE007_TPM_bAirLdLimTExMgr_in);
      (void)Rte_Read_R_ExM_facCorIgProtComp_ExM_facCorIgProtComp(&TPM_RE007_ExM_facCorIgProtComp_in);
      (void)Rte_Read_R_ExM_prm_facFlex_ExM_prm_facFlex(&TPM_RE007_ExM_prm_facFlex_in);
      (void)Rte_Read_R_ExM_prm_facGas_ExM_prm_facGas(&TPM_RE007_ExM_prm_facGas_in);
      (void)Rte_Read_R_TPM_rAirLdReqGas_TPM_rAirLdReqGas(&TPM_RE007_TPM_rAirLdReqGas_in);
      (void)Rte_Read_R_TPM_tExReq_TPM_tExReq(&TPM_RE007_TPM_tExReq_in);
	  (void)Rte_Read_R_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc(&TPM_RE007_IgSys_rStatIgSpEfc_in);
      RE007_TPM_bAcvProtExScv_in = Rte_IrvRead_RE_TPM_007_TEV_TPM_bAcvProtExScv();
      RE007_TPM_rAirLdReqRbl_in = Rte_IrvRead_RE_TPM_007_TEV_TPM_rAirLdReqRbl();

      TPM_007_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TPM_rLdProtExThermo_out = TPM_rLdProtExThermo_B;
   }
   (void)Rte_IrvWrite_RE_TPM_007_TEV_TPM_rAirLdReq(RE007_TPM_rAirLdReq_out);
   (void)Rte_Write_P_TPM_rLdProtExThermo_TPM_rLdProtExThermo(TPM_rLdProtExThermo_out);

}

void RE_TPM_008_TEV(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE008_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE008_Ext_nEng_in);
      (void)Rte_Read_R_FARSp_rMixtCylSp_FARSp_rMixtCylSp(&TPM_RE008_FARSp_rMixtCylSp_in);
      (void)Rte_Read_R_PhyMSI_tExMnfEstim_PhyMSI_tExMnfEstim(&TPM_RE008_PhyMSI_tExMnfEstim_in);
      (void)Rte_Read_R_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(&TPM_RE008_PhyMSI_tTrbCaseEstim_in);
      (void)Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(&TPM_RE008_ExM_mfEgWoutEGR_in);
      (void)Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&TPM_RE008_ExM_tExMnfEstim_in);
      (void)Rte_Read_R_Ext_rSpdFanAct_Ext_rSpdFanAct(&TPM_RE008_Ext_rSpdFanAct_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&TPM_RE008_Ext_tAir_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&TPM_RE008_Ext_tCoMes_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&TPM_RE008_Veh_spdVeh_in);

      TPM_008_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      PhyMSI_pwrCylHdEstim_out = PhyMSI_pwrCylHdEstim_B;
      PhyMSI_tExMnfEstim_out = PhyMSI_tExMnfEstim_B;
      PhyMSI_tTrbCaseEstim_out = PhyMSI_tTrbCaseEstim_B;
   }
   (void)Rte_Write_P_PhyMSI_pwrCylHdEstim_PhyMSI_pwrCylHdEstim(PhyMSI_pwrCylHdEstim_out);
   (void)Rte_Write_P_PhyMSI_tExMnfEstim_PhyMSI_tExMnfEstim(PhyMSI_tExMnfEstim_out);
   (void)Rte_Write_P_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(PhyMSI_tTrbCaseEstim_out);

}

void RE_TPM_009_DRE(void)
{
   if (FALSE == TPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TPM_RE009_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TPM_RE009_Ext_nEng_in);

      TPM_009_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      PhyMSI_pCylMaxEstim_out = PhyMSI_pCylMaxEstim_B;
   }
   (void)Rte_Write_P_PhyMSI_pCylMaxEstim_PhyMSI_pCylMaxEstim(PhyMSI_pCylMaxEstim_out);

}

#define TPM_STOP_SEC_CODE
#include "TPM_MemMap.h"

#endif/*_TPM_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
