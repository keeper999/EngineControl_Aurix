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
* %name: ACCmd.c %
*
* %version: 11.1.build1 %
*
* %date_modified: Wed Jan  4 14:44:58 2012 %
*
*
* %derived_by: e360487 %
* %release: TqStruct/12.0 %
* %full_filespec: ACCmd.c-11.1.build1:csrc:5 %
*
*******************************************************************************/

#ifndef _ACCMD_C_
#define _ACCMD_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_ACCmd.h"
#include "ACCmd.h"
#include "RE_ACCmd_002_TEV.h"
#include "RE_ACCmd_003_DRE.h"
#include "RE_ACCmd_004_TEV.h"
#include "ACCmd_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define ACCMD_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ACCmd_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ACCmd_ModuleVersion_Major_MP = 12;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ACCmd_ModuleVersion_Minor_MP = 0;
#define ACCMD_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ACCmd_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 5
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define ACCMD_START_SEC_CALIB_BOOLEAN
#include "ACCmd_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_003_DRE_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ACCmd_bInhAntiStall_B = 0;
#define ACCMD_STOP_SEC_CALIB_BOOLEAN
#include "ACCmd_MemMap.h"

#define ACCMD_START_SEC_CALIB_8BIT
#include "ACCmd_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 ACCmd_stReq_B = 1;
#define ACCMD_STOP_SEC_CALIB_8BIT
#include "ACCmd_MemMap.h"

#define ACCMD_START_SEC_CALIB_16BIT
#include "ACCmd_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 ACCmd_nAntiStall_B = 0;
#define ACCMD_STOP_SEC_CALIB_16BIT
#include "ACCmd_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define ACCMD_START_SEC_CODE
#include "ACCmd_MemMap.h"
void RE_ACCmd_001_MSE(void)
{
   RE_ACCmd_002_TEV_ini();
   RE_ACCmd_003_DRE_ini();
   RE_ACCmd_004_TEV_ini();

   (void)Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhAst_irv(0);
   (void)Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhACOn_irv(0);
   (void)Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhTakeOff_irv(0);
   (void)Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhTDCClc_irv(0);
   (void)Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_spdVeh_irv(0);
   (void)Rte_Write_P_ACCmd_stReq_ACCmd_stReq(1);
   (void)Rte_Write_P_ACCmd_nAntiStall_ACCmd_nAntiStall(0);
   (void)Rte_Write_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(0);
}

void RE_ACCmd_002_TEV(void)
{
   if (FALSE == RE_ACCMD_002_TEV_B)
   {
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ACCmd_RE002_AccP_rAccP_in);
      (void)Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&ACCmd_RE002_Cha_stTqReq_in);
      (void)Rte_Read_R_CoPt_bFrzAC_CoPt_bFrzAC(&ACCmd_RE002_CoPt_bFrzAC_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ACCmd_RE002_CoPTSt_stEng_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ACCmd_RE002_Eng_nCkFil_in);
      (void)Rte_Read_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim(&ACCmd_RE002_EngLim_tqCkEfcACCmprLim_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ACCmd_RE002_Ext_stGBxCf_in);
      (void)Rte_Read_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq(&ACCmd_RE002_ThMgt_bACCmprOffReq_in);
      (void)Rte_Read_R_TqEM_bFrzACComp_TqEM_bFrzACComp(&ACCmd_RE002_TqEM_bFrzACComp_in);
      (void)Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&ACCmd_RE002_TqSys_bEngNOnIdl_in);
      (void)Rte_Read_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw(&ACCmd_RE002_TreatTenms_nCkRaw_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&ACCmd_RE002_Veh_spdVeh_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&ACCmd_RE002_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_TqSys_bInhBrio_TqSys_bInhBrio(&ACCmd_RE002_TqSys_bInhBrio_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&ACCmd_RE002_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&ACCmd_RE002_Ext_tAir_in);
      (void)Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&ACCmd_RE002_TqLimEM_tqLimEMTrv_in);
      (void)Rte_Read_R_TqRes_bFrzAC_TqRes_bFrzAC(&ACCmd_RE002_TqRes_bFrzAC_in);
      (void)Rte_Read_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi(&ACCmd_RE002_TqSys_bInhACBrkAsi_in);
      (void)Rte_Read_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(&ACCmd_RE002_ACCmd_bInhAntiStall_in);
      (void)Rte_Read_R_ACCmd_nAntiStall_ACCmd_nAntiStall(&ACCmd_RE002_ACCmd_nAntiStall_in);
      RE002_ACCmd_bInhAst_irv_in = Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhAst_irv();
      RE002_ACCmd_bInhACOn_irv_in = Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhACOn_irv();
      RE002_ACCmd_bInhTakeOff_irv_in = Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhTakeOff_irv();

      Rte_Call_R_FRM_bInhBrioVst_GetFunctionPermission(&ACCmd_RE002_FRM_bInhBrioVst_in);
      ACCmd_RE002_FRM_bInhBrioVst_in = !ACCmd_RE002_FRM_bInhBrioVst_in;
      Rte_Call_R_FRM_bInhRvFrzESP_GetFunctionPermission(&ACCmd_RE002_FRM_bInhRvFrzESP_in);
      ACCmd_RE002_FRM_bInhRvFrzESP_in = !ACCmd_RE002_FRM_bInhRvFrzESP_in;
	  Rte_Call_R_FRM_bInhACRlsTakeOff_GetFunctionPermission(&ACCmd_RE002_FRM_bInhACRlsTakeOff_in);
      ACCmd_RE002_FRM_bInhACRlsTakeOff_in = !ACCmd_RE002_FRM_bInhACRlsTakeOff_in;
      RE_ACCmd_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      ACCmd_stReq_out = ACCmd_stReq_B;
   }
   (void)Rte_IrvWrite_RE_ACCmd_002_TEV_ACCmd_bInhTDCClc_irv(RE002_ACCmd_bInhTDCClc_irv_out);
   (void)Rte_IrvWrite_RE_ACCmd_002_TEV_ACCmd_spdVeh_irv(RE002_ACCmd_spdVeh_irv_out);
   (void)Rte_Write_P_ACCmd_stReq_ACCmd_stReq(ACCmd_stReq_out);

}

void RE_ACCmd_003_DRE(void)
{
   if (FALSE == RE_ACCMD_003_DRE_B)
   {
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ACCmd_RE003_AccP_rAccP_in);
      (void)Rte_Read_R_AC_bACClu_AC_bACClu(&ACCmd_RE003_AC_bACClu_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ACCmd_RE003_Ext_tiTDC_in);
      (void)Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&ACCmd_RE003_TqSys_bEngNOnIdl_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&ACCmd_RE003_TqSys_nTarIdl_in);
      (void)Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&ACCmd_RE003_TreatTDC_nCkGrd_in);
      (void)Rte_Read_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw(&ACCmd_RE003_TreatTenms_nCkRaw_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&ACCmd_RE003_CoPt_noEgdGearCordIt_in);
      //(void)Rte_Read_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd(&ACCmd_RE003_TqSys_EveSync_ACCmd_in);
      RE003_ACCmd_bInhTDCClc_irv_in = Rte_IrvRead_RE_ACCmd_003_DRE_ACCmd_bInhTDCClc_irv();
      RE003_ACCmd_spdVeh_irv_in = Rte_IrvRead_RE_ACCmd_003_DRE_ACCmd_spdVeh_irv();

      RE_ACCmd_003_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      ACCmd_nAntiStall_out = ACCmd_nAntiStall_B;
      ACCmd_bInhAntiStall_out = ACCmd_bInhAntiStall_B;
   }
   (void)Rte_IrvWrite_RE_ACCmd_003_DRE_ACCmd_bInhTakeOff_irv(RE003_ACCmd_bInhTakeOff_irv_out);
   (void)Rte_Write_P_ACCmd_nAntiStall_ACCmd_nAntiStall(ACCmd_nAntiStall_out);
   (void)Rte_Write_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(ACCmd_bInhAntiStall_out);

}

void RE_ACCmd_004_TEV(void)
{
   if (FALSE == RE_ACCMD_004_TEV_B)
   {
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ACCmd_RE004_CoPTSt_stEng_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&ACCmd_RE004_Ext_tAir_in);
      (void)Rte_Read_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn(&ACCmd_RE004_TqCmp_bACOffDftSelOn_in);

      Rte_Call_R_FRM_bInhACOn_GetFunctionPermission(&ACCmd_RE004_FRM_bInhACOn_in);
      ACCmd_RE004_FRM_bInhACOn_in = !ACCmd_RE004_FRM_bInhACOn_in;
      Rte_Call_R_FRM_bInhPwrPresInvld_GetFunctionPermission(&ACCmd_RE004_FRM_bInhPwrPresInvld_in);
      ACCmd_RE004_FRM_bInhPwrPresInvld_in = !ACCmd_RE004_FRM_bInhPwrPresInvld_in;
      RE_ACCmd_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_ACCmd_004_TEV_ACCmd_bInhAst_irv(RE004_ACCmd_bInhAst_irv_out);
   (void)Rte_IrvWrite_RE_ACCmd_004_TEV_ACCmd_bInhACOn_irv(RE004_ACCmd_bInhACOn_irv_out);

}

#define ACCMD_STOP_SEC_CODE
#include "ACCmd_MemMap.h"

#endif/*_ACCMD_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
