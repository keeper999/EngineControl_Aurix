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
* %name: TPM_code.h %
*
* %version: 3.0 %
*
* %date_modified: Mon Dec  3 09:47:29 2012 %
*
*
* %derived_by: u260001 %
* %release: EPflex/Vf %
* %full_filespec: TPM_code.h-3.0:incl:2 %
*
*******************************************************************************/


#ifndef _TPM_CODE_H_
#define _TPM_CODE_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#include "TPM_Library.h"
#define TPM_START_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 PhyMSI_pwrCylHdEstim_out;extern 
AR_IF_GLOBAL_16BIT UInt16 PhyMSI_tExMnfEstim_out;extern AR_IF_GLOBAL_16BIT 
UInt16 PhyMSI_tTrbCaseEstim_out;extern AR_IF_GLOBAL_16BIT UInt16 
RE004_TPM_mfAirScvLimMax_in;extern AR_IF_GLOBAL_16BIT UInt16 
RE004_TPM_tRefTWCScvMax_in;extern AR_IF_GLOBAL_16BIT UInt16 RE005_TPM_tTWC_in;
extern AR_IF_GLOBAL_16BIT UInt16 RE006_TPM_rAirLdReqRbl_in;extern 
AR_IF_GLOBAL_16BIT UInt16 RE006_TPM_rAirLdReq_in;extern AR_IF_GLOBAL_16BIT 
UInt16 RE006_TPM_tExCurAcvThermoProtDev_in;extern AR_IF_GLOBAL_16BIT UInt16 
RE007_TPM_rAirLdReqRbl_in;extern AR_IF_GLOBAL_16BIT UInt16 
TEMP_PhyMSI_tExMnfEstim_NV;extern AR_IF_GLOBAL_16BIT UInt16 
TEMP_PhyMSI_tTrbCaseEstim_NV;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_EngM_mfAirCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_ExM_mfEgTot_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_ExM_prm_tEg_in[12];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_ExM_prm_tWall_in[12];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE002_FARSp_rMixtCylSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_ExM_prm_tEg_in[12];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_ExM_prm_tWall_in[12];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_FARSp_rMixtCylSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_PhyMSI_tExMnfEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE003_PhyMSI_tTrbCaseEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_EngM_mfAirScvCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE004_UsThrM_facPresAltiCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE005_EngM_mfAirCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE005_EngM_mfAirScvCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE005_FARSp_rMixtCylSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_EngMTrb_rLdMax_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_ExM_mfEgTot_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_ExM_tExStatAfs_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_FARSp_rMixtCylSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_FARSp_rMixtThermoProtSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE006_TPM_tTarAcvThermoProtDev_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_facCorIgProtComp_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_mfEgTot_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_prm_facFlex_in[5];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_ExM_prm_facGas_in[5];extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_IgSys_rStatIgSpEfc_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_TPM_rAirLdReqGas_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE007_TPM_tExReq_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_ExM_mfEgWoutEGR_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_ExM_tExMnfEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE008_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT SInt16 TPM_RE008_Ext_tCoMes_in;
extern AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_FARSp_rMixtCylSp_in;extern 
AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_PhyMSI_tExMnfEstim_in;extern 
AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_PhyMSI_tTrbCaseEstim_in;extern 
AR_IF_GLOBAL_16BIT UInt16 TPM_RE008_Veh_spdVeh_in;extern AR_IF_GLOBAL_16BIT 
UInt16 TPM_RE009_EngM_rAirLdCor_in;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_RE009_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 TPM_mfAirScvLimMaxCor_out
;extern AR_IF_GLOBAL_16BIT UInt16 TPM_rLdProtExThermo_out;extern 
AR_IF_GLOBAL_16BIT UInt16 TPM_rMixtLimMaxAflScv_out;extern AR_IF_GLOBAL_16BIT 
UInt16 TPM_tExReq_out;extern AR_IF_GLOBAL_16BIT UInt16 
TPM_tTarAcvThermoProtDev_out;
#define TPM_STOP_SEC_GLOBAL_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_32BIT
#include "TPM_MemMap.h"
extern AR_IF_GLOBAL_32BIT UInt32 PhyMSI_pCylMaxEstim_out;extern 
AR_IF_GLOBAL_32BIT UInt32 TPM_RE001_EOM_tiEngStop_in;extern AR_IF_GLOBAL_32BIT 
UInt32 TPM_RE005_ExM_lamTot_in;
#define TPM_STOP_SEC_GLOBAL_32BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_8BIT
#include "TPM_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 ExM_stO2HcStgTWC_out;extern AR_IF_GLOBAL_8BIT 
UInt8 RE006_TPM_noAcvThermoProtDev_in;extern AR_IF_GLOBAL_8BIT SInt8 
TPM_RE001_Ext_tAir_in;extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE002_ExM_stO2HcStgTWC_in;extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE003_IgSys_agIgMinThermo_in;extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE003_IgSys_prm_agIgSpCyl_in[6];extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE004_ExM_stO2HcStgTWC_in;extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE005_Ext_uLsDsMes_in;extern AR_IF_GLOBAL_8BIT UInt8 
TPM_RE008_Ext_rSpdFanAct_in;extern AR_IF_GLOBAL_8BIT SInt8 TPM_RE008_Ext_tAir_in
;
#define TPM_STOP_SEC_GLOBAL_8BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_GLOBAL_BOOLEAN
#include "TPM_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean RE006_TPM_bAcvProtExScv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean RE007_TPM_bAcvProtExScv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_DmgMSI_bLdLimReq_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_DmgMSI_bMPMInh_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_FARSp_bRichScvThermoInvld_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_FARSp_bSatMaxRatMixt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_FARSp_bThermoProtReqNotAuth_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_FRM_bAcvEcpHeatProt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_FRM_bAcvTPMDecTMaxDev_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_TPM_bRichLimScv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE003_ThMgt_bAcvR1234Mgt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE004_FARSp_bRichScvThermoInvld_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE004_FRM_bAcvLimScv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE004_FRM_bAcvTPMDecTMaxDev_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE005_FRM_bAcvTPMDecTMaxDev_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE005_FRM_bAcvTPMInhLsTWCSt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE005_FRM_bInhCutOff_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_FARSp_bSatMaxRatMixt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_FARSp_bThermoProtReqNotAuth_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_FRM_bAcvTPMDecTMaxDev_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_TPM_bAcvRichProtOxdTWC_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_TPM_bAcvRichThermoProt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE006_TPM_bAirLdLimTExMgr_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_RE007_TPM_bAirLdLimTExMgr_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_bAcvRichProtOxdTWC_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_bAcvRichThermoProt_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean TPM_bAirLdLimTExMgr_out;extern AR_IF_GLOBAL_BOOLEAN
 Boolean TPM_bExThermoProt_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bInhInjCutOff_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
TPM_bInhInjSelCutOff_out;extern AR_IF_GLOBAL_BOOLEAN Boolean TPM_bInhOvbReq_out;
extern AR_IF_GLOBAL_BOOLEAN Boolean TPM_bRichLimScv_out;
#define TPM_STOP_SEC_GLOBAL_BOOLEAN
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_16BIT
#include "TPM_MemMap.h"
extern ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev1_0;extern ISV_SRSS11_0_tp 
subIsv16_TPM_SRSS11_Dev2_0;extern ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev3_0;
extern ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev4_0;extern ISV_SRSS11_0_tp 
subIsv16_TPM_SRSS11_Dev_0;extern ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev_0_a;
extern ISV_SRSS11_0_tp subIsv16_TPM_SRSS11_Dev_0_b;
#define TPM_STOP_SEC_VAR_16BIT
#include "TPM_MemMap.h"
#define TPM_START_SEC_VAR_8BIT
#include "TPM_MemMap.h"
extern ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev1_1;extern ISV_SRSS11_1_tp 
subIsv8_TPM_SRSS11_Dev2_1;extern ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev3_1;
extern ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev4_1;extern ISV_SRSS11_1_tp 
subIsv8_TPM_SRSS11_Dev_1;extern ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev_1_a;
extern ISV_SRSS11_1_tp subIsv8_TPM_SRSS11_Dev_1_b;
#define TPM_STOP_SEC_VAR_8BIT
#include "TPM_MemMap.h"
extern Void TPM_002_TEV_fct(Void);extern Void TPM_003_TEV_fct(Void);extern Void 
TPM_004_TEV_fct(Void);extern Void TPM_005_TEV_fct(Void);extern Void 
TPM_006_TEV_fct(Void);extern Void TPM_007_TEV_fct(Void);extern Void 
TPM_008_TEV_fct(Void);extern Void TPM_009_DRE_fct(Void);extern Void 
TPM_Init_MSE_fct(Void);extern Void TPM_FctVarInit(Void);
#endif

