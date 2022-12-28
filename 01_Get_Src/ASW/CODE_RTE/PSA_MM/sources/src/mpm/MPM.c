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
* %name: MPM.c %
*
* %version: 2.4 %
*
* %date_modified: Wed Jul 31 08:59:48 2013 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC4.3 %
* %full_filespec: MPM.c-2.4:csrc:1 %
*
*******************************************************************************/

#ifndef _MPM_C_
#define _MPM_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_MPM.h"
#include "MPM.h"
#include "MPM_code.h"
#include "MPM_nvm.h"
/*#include "MPM_AftsNvmChkRead_fct.h"
#include "MPM_AftsNvmRead_fct.h"
#include "MPM_AftsNvmChkWrite_fct.h"
#include "MPM_AftsNvmWrite_fct.h"
#include "MPM_AftsNvmRDL_fct.h"
#include "MPM_RstStart_fct.h"
#include "MPM_RstRqResults_fct.h"
#include "MPM_AftsGetSesChgPerm_fct.h"
#include "MPM_AftsSesChgInd_fct.h"
#include "MPM_AftsNvm_fct.h"
#include "MPM_AftrsInit_fct.h"*/
#include "MPM_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define MPM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "MPM_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 MPM_ModuleVersion_Major_MP = 2;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 MPM_ModuleVersion_Minor_MP = 4;
#define MPM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "MPM_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 13
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define MPM_START_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bLdLimReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bMPMInh_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bOvbStop_B = 0;
#define MPM_STOP_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"

#define MPM_START_SEC_CALIB_16BIT
#include "MPM_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 MPM_facOvbReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 MPM_rLdMax_B = 0;
#define MPM_STOP_SEC_CALIB_16BIT
#include "MPM_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define MPM_START_SEC_CODE
#include "MPM_MemMap.h"
void RE_MPM_001_MSE(void)
{
   MPM_FctVarInit();


   (void)Rte_IrvWrite_RE_MPM_001_MSE_DmgMSI_rCylHdInjDmgCnt(MPM_sNV_Z1_CST_16BIT.DmgMSI_rCylHdInjDmgCnt_NV * 2^14);
   (void)Rte_IrvWrite_RE_MPM_001_MSE_DmgMSI_rCylBlockDmg(MPM_sNV_Z1_CST_32BIT.DmgMSI_rCylBlockDmg_NV * 10^-8);
   (void)Rte_IrvWrite_RE_MPM_001_MSE_DmgMSI_rTrbCaseDmg(MPM_sNV_Z1_CST_32BIT_1.DmgMSI_rTrbCaseDmg_NV * 2^27);
   (void)Rte_IrvWrite_RE_MPM_001_MSE_DmgMSI_rExMnfDmg(MPM_sNV_Z1_CST_32BIT_2.DmgMSI_rExMnfDmg_NV * 2^27);
   (void)Rte_IrvWrite_RE_MPM_001_MSE_DmgMSI_rCylHdDmg(MPM_sNV_Z1_CST_32BIT.DmgMSI_rCylHdDmg_NV * 2^27);
   (void)Rte_Write_P_DmgMSI_bLdLimReq_DmgMSI_bLdLimReq(0);
   (void)Rte_Write_P_DmgMSI_bMPMInh_DmgMSI_bMPMInh(0);
   (void)Rte_Write_P_MPM_bOvbStop_MPM_bOvbStop(0);
   (void)Rte_Write_P_MPM_facOvbReq_MPM_facOvbReq(0);
   (void)Rte_Write_P_MPM_rLdMax_MPM_rLdMax(0);
}

void RE_MPM_002_TEV(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&MPM_RE002_Ext_dstVehTotMes_in);
      RE002_DmgMSI_rCylHdInjDmgCnt_in = Rte_IrvRead_RE_MPM_002_TEV_DmgMSI_rCylHdInjDmgCnt();
      RE002_DmgMSI_rCylBlockDmg_in = Rte_IrvRead_RE_MPM_002_TEV_DmgMSI_rCylBlockDmg();
      RE002_DmgMSI_rTrbCaseDmg_in = Rte_IrvRead_RE_MPM_002_TEV_DmgMSI_rTrbCaseDmg();
      RE002_DmgMSI_rExMnfDmg_in = Rte_IrvRead_RE_MPM_002_TEV_DmgMSI_rExMnfDmg();
      RE002_DmgMSI_rCylHdDmg_in = Rte_IrvRead_RE_MPM_002_TEV_DmgMSI_rCylHdDmg();

      MPM_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      DmgMSI_bLdLimReq_out = DmgMSI_bLdLimReq_B;
      DmgMSI_bMPMInh_out = DmgMSI_bMPMInh_B;
   }
   (void)Rte_Write_P_DmgMSI_bLdLimReq_DmgMSI_bLdLimReq(DmgMSI_bLdLimReq_out);
   (void)Rte_Write_P_DmgMSI_bMPMInh_DmgMSI_bMPMInh(DmgMSI_bMPMInh_out);

}

void RE_MPM_003_TEV(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstTrbCaseDmgReq_Afts_bRstTrbCaseDmgReq(&MPM_RE003_Afts_bRstTrbCaseDmgReq_in);
      (void)Rte_Read_R_Eng_stEru_Eng_stEru(&MPM_RE003_Eng_stEru_in);
      (void)Rte_Read_R_PhyMSI_tTrbCaseEstim_PhyMSI_tTrbCaseEstim(&MPM_RE003_PhyMSI_tTrbCaseEstim_in);

      MPM_003_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_MPM_003_TEV_DmgMSI_rTrbCaseDmg(RE003_DmgMSI_rTrbCaseDmg_out);

}

void RE_MPM_004_TEV(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstExMnfDmgReq_Afts_bRstExMnfDmgReq(&MPM_RE004_Afts_bRstExMnfDmgReq_in);
      (void)Rte_Read_R_Eng_stEru_Eng_stEru(&MPM_RE004_Eng_stEru_in);
      (void)Rte_Read_R_PhyMSI_tExMnfEstim_PhyMSI_tExMnfEstim(&MPM_RE004_PhyMSI_tExMnfEstim_in);

      MPM_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_MPM_004_TEV_DmgMSI_rExMnfDmg(RE004_DmgMSI_rExMnfDmg_out);

}

void RE_MPM_005_TEV(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstCylHdDmgReq_Afts_bRstCylHdDmgReq(&MPM_RE005_Afts_bRstCylHdDmgReq_in);
      (void)Rte_Read_R_Eng_stEru_Eng_stEru(&MPM_RE005_Eng_stEru_in);
      (void)Rte_Read_R_PhyMSI_pwrCylHdEstim_PhyMSI_pwrCylHdEstim(&MPM_RE005_PhyMSI_pwrCylHdEstim_in);

      MPM_005_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_MPM_005_TEV_DmgMSI_rCylHdDmg(RE005_DmgMSI_rCylHdDmg_out);

}

void RE_MPM_006_DRE(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstCylBlockDmgReq_Afts_bRstCylBlockDmgReq(&MPM_RE006_Afts_bRstCylBlockDmgReq_in);
      (void)Rte_Read_R_Afts_bRstCylHdDmgReq_Afts_bRstCylHdDmgReq(&MPM_RE006_Afts_bRstCylHdDmgReq_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&MPM_RE006_EngM_rAirLdCor_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&MPM_RE006_Ext_nEng_in);
      (void)Rte_Read_R_PhyMSI_pCylMaxEstim_PhyMSI_pCylMaxEstim(&MPM_RE006_PhyMSI_pCylMaxEstim_in);
      (void)Rte_Read_R_PhyMSI_pwrCylHdEstim_PhyMSI_pwrCylHdEstim(&MPM_RE006_PhyMSI_pwrCylHdEstim_in);

      MPM_006_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_MPM_006_DRE_DmgMSI_rCylHdInjDmgCnt(RE006_DmgMSI_rCylHdInjDmgCnt_out);
   (void)Rte_IrvWrite_RE_MPM_006_DRE_DmgMSI_rCylBlockDmg(RE006_DmgMSI_rCylBlockDmg_out);

}

void RE_MPM_007_TEV(void)
{
   if (FALSE == MPM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&MPM_RE007_Ext_nEng_in);
      (void)Rte_Read_R_DmgMSI_bLdLimReq_DmgMSI_bLdLimReq(&MPM_RE007_DmgMSI_bLdLimReq_in);
      (void)Rte_Read_R_DmgMSI_bMPMInh_DmgMSI_bMPMInh(&MPM_RE007_DmgMSI_bMPMInh_in);
      (void)Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&MPM_RE007_ExM_tExMnfEstim_in);
      (void)Rte_Read_R_UsThrM_tThrMes_UsThrM_tThrMes(&MPM_RE007_UsThrM_tThrMes_in);

      Rte_Call_R_FRM_bInhMPM_GetFunctionPermission(&MPM_RE007_FRM_bInhMPM_in);
      MPM_RE007_FRM_bInhMPM_in = !MPM_RE007_FRM_bInhMPM_in;
      MPM_007_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      MPM_bOvbStop_out = MPM_bOvbStop_B;
      MPM_facOvbReq_out = MPM_facOvbReq_B;
      MPM_rLdMax_out = MPM_rLdMax_B;
   }
   (void)Rte_Write_P_MPM_bOvbStop_MPM_bOvbStop(MPM_bOvbStop_out);
   (void)Rte_Write_P_MPM_facOvbReq_MPM_facOvbReq(MPM_facOvbReq_out);
   (void)Rte_Write_P_MPM_rLdMax_MPM_rLdMax(MPM_rLdMax_out);

}



#define MPM_STOP_SEC_CODE
#include "MPM_MemMap.h"

#endif/*_MPM_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
