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
* %name: EOMGsl.c %
*
* %version: 4.0.build1 %
*
* %date_modified: Wed Aug 29 08:12:26 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: EOMGsl.c-4.0.build1:csrc:1 %
*
*******************************************************************************/

#ifndef _EOMGSL_C_
#define _EOMGSL_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_EOMGsl.h"
#include "EOMGsl.h"
#include "EOMGsl_002_TEV_fct.h"
#include "EOMGsl_003_TEV_fct.h"
#include "EOMGsl_004_TEV_fct.h"
#include "EOMGsl_002_calibrations.h"
#include "EOMGsl_003_calibrations.h"
#include "EOMGsl_004_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define EOMGSL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "EOMGsl_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EOMGsl_ModuleVersion_Major_MP = 4;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EOMGsl_ModuleVersion_Minor_MP = 0;
#define EOMGSL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "EOMGsl_MemMap.h"

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
#define EOMGSL_START_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOMGSL_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bSpcInjMod_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bTranMod_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bTWCHeatPha_B = 0;
#define EOMGSL_STOP_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"

#define EOMGSL_START_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facBasModCur_B[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facBasModTar_B[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facTranMod_B[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas1ModCur_B[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas1ModTar_B[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas2ModCur_B[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas2ModTar_B[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
#define EOMGSL_STOP_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define EOMGSL_START_SEC_CODE
#include "EOMGsl_MemMap.h"
void RE_EOMGsl_001_MSE(void)
{
   UInt8 TAB_EOM_prm_facBasModCur[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   UInt8 TAB_EOM_prm_facBasModTar[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   UInt8 TAB_EOM_prm_facTranMod[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   UInt8 TAB_EOM_prm_idxBas1ModCur[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   UInt8 TAB_EOM_prm_idxBas1ModTar[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   UInt8 TAB_EOM_prm_idxBas2ModCur[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   UInt8 TAB_EOM_prm_idxBas2ModTar[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
   EOMGsl_002_TEV_ini();
   EOMGsl_003_TEV_ini();
   EOMGsl_004_TEV_ini();
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_bDiTran(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_bFdoutModReq(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_stCmbModReq(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_01(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_02(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_03(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_04(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_05(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_06(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_07(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_08(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_09(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_10(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_11(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_12(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_13(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_14(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_15(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_prm_facTranModNotSync_16(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_stCmbModTar(0);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_bEnaCmbModChg(1);
   (void)Rte_IrvWrite_RE_EOMGsl_001_MSE_EOM_stCmbModCur(0);
   (void)Rte_Write_P_EOM_bSpcInjMod_EOM_bSpcInjMod(0);
   (void)Rte_Write_P_EOM_bTranMod_EOM_bTranMod(0);
   (void)Rte_Write_P_EOM_bTWCHeatPha_EOM_bTWCHeatPha(0);
   (void)Rte_Write_P_EOM_prm_facBasModCur_EOM_prm_facBasModCur(TAB_EOM_prm_facBasModCur);
   (void)Rte_Write_P_EOM_prm_facBasModTar_EOM_prm_facBasModTar(TAB_EOM_prm_facBasModTar);
   (void)Rte_Write_P_EOM_prm_facTranMod_EOM_prm_facTranMod(TAB_EOM_prm_facTranMod);
   (void)Rte_Write_P_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(TAB_EOM_prm_idxBas1ModCur);
   (void)Rte_Write_P_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(TAB_EOM_prm_idxBas1ModTar);
   (void)Rte_Write_P_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(TAB_EOM_prm_idxBas2ModCur);
   (void)Rte_Write_P_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(TAB_EOM_prm_idxBas2ModTar);
}

void RE_EOMGsl_002_TEV(void)
{
   if (FALSE == EOMGSL_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_InjSys_bAcvSpcInjMod_InjSys_bAcvSpcInjMod(&EOMGsl_RE002_InjSys_bAcvSpcInjMod_in);
      (void)Rte_Read_R_InjSys_bAcvSpcInjModOvlp_InjSys_bAcvSpcInjModOvlp(&EOMGsl_RE002_InjSys_bAcvSpcInjModOvlp_in);
      (void)Rte_Read_R_KnkMgt_bAcvVlvPosnRblReq_KnkMgt_bAcvVlvPosnRblReq(&EOMGsl_RE002_KnkMgt_bAcvVlvPosnRblReq_in);
      (void)Rte_Read_R_TPM_bInhOvbReq_TPM_bInhOvbReq(&EOMGsl_RE002_TPM_bInhOvbReq_in);
      (void)Rte_Read_R_VlvAct_bAcvExServo_VlvAct_bAcvExServo(&EOMGsl_RE002_VlvAct_bAcvExServo_in);
      (void)Rte_Read_R_VlvAct_bAcvInServo_VlvAct_bAcvInServo(&EOMGsl_RE002_VlvAct_bAcvInServo_in);
      (void)Rte_Read_R_AFA_bAcvSpcInjMod_AFA_bAcvSpcInjMod(&EOMGsl_RE002_AFA_bAcvSpcInjMod_in);
      (void)Rte_Read_R_AirSys_rAirLdReq_AirSys_rAirLdReq(&EOMGsl_RE002_AirSys_rAirLdReq_in);
      (void)Rte_Read_R_CoEs_bAcvVlvSysLockPosnSTTEs_CoEs_bAcvVlvSysLockPosnSTTEs(&EOMGsl_RE002_CoEs_bAcvVlvSysLockPosnSTTEs_in);
      (void)Rte_Read_R_CoPt_bPrfModReq_CoPt_bPrfModReq(&EOMGsl_RE002_CoPt_bPrfModReq_in);
      (void)Rte_Read_R_CoVSCtl_stAccP_CoVSCtl_stAccP(&EOMGsl_RE002_CoVSCtl_stAccP_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&EOMGsl_RE002_EngM_rAirLdCor_in);
      (void)Rte_Read_R_ExM_pExMnfEstim_facVlvOvlp_ExM_pExMnfEstim_facVlvOvlp(&EOMGsl_RE002_ExM_pExMnfEstim_facVlvOvlp_in);
      (void)Rte_Read_R_Ext_agCkClsExVlvEstimRef0_Ext_agCkClsExVlvEstimRef0(&EOMGsl_RE002_Ext_agCkClsExVlvEstimRef0_in);
      (void)Rte_Read_R_Ext_agCkOpInVlvEstimRef0_Ext_agCkOpInVlvEstimRef0(&EOMGsl_RE002_Ext_agCkOpInVlvEstimRef0_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&EOMGsl_RE002_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&EOMGsl_RE002_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stSysGas_Ext_stSysGas(&EOMGsl_RE002_Ext_stSysGas_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EOMGsl_RE002_Ext_tCoMes_in);
      (void)Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&EOMGsl_RE002_InM_pDsThrCor_in);
      (void)Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&EOMGsl_RE002_TqSys_bEngNOnIdl_in);
      (void)Rte_Read_R_TWCMgt_stHeatPhaReq_TWCMgt_stHeatPhaReq(&EOMGsl_RE002_TWCMgt_stHeatPhaReq_in);
      (void)Rte_Read_R_VlvSys_agCkClsExVlvReqRef0_VlvSys_agCkClsExVlvReqRef0(&EOMGsl_RE002_VlvSys_agCkClsExVlvReqRef0_in);
      (void)Rte_Read_R_VlvSys_agCkClsExVlvSatCorReq_VlvSys_agCkClsExVlvSatCorReq(&EOMGsl_RE002_VlvSys_agCkClsExVlvSatCorReq_in);
      (void)Rte_Read_R_VlvSys_agCkOpInVlvReqRef0_VlvSys_agCkOpInVlvReqRef0(&EOMGsl_RE002_VlvSys_agCkOpInVlvReqRef0_in);
      (void)Rte_Read_R_VlvSys_agCkOpInVlvSatCorReq_VlvSys_agCkOpInVlvSatCorReq(&EOMGsl_RE002_VlvSys_agCkOpInVlvSatCorReq_in);
      (void)Rte_Read_R_InjSys_bAcvSpcInjModCmdInjr_InjSys_bAcvSpcInjModCmdInjr(&EOMGsl_RE002_InjSys_bAcvSpcInjModCmdInjr_in);
      (void)Rte_Read_R_TqSys_bAcvVlvSysOptmVac_TqSys_bAcvVlvSysOptmVac(&EOMGsl_RE002_TqSys_bAcvVlvSysOptmVac_in);
      (void)Rte_Read_R_CoHeat_bAcvHeatMgt_CoHeat_bAcvHeatMgt(&EOMGsl_RE002_CoHeat_bAcvHeatMgt_in);
      (void)Rte_Read_R_Ext_bAcvSpcInjModProtECU_Ext_bAcvSpcInjModProtECU(&EOMGsl_RE002_Ext_bAcvSpcInjModProtECU_in);
      (void)Rte_Read_R_Blby_bCfHiMfBlby_Blby_bCfHiMfBlby(&EOMGsl_RE002_Blby_bCfHiMfBlby_in);
      (void)Rte_Read_R_Blby_bDecPfu_Blby_bDecPfu(&EOMGsl_RE002_Blby_bDecPfu_in);
      (void)Rte_Read_R_Blby_bIncIdlSpd_Blby_bIncIdlSpd(&EOMGsl_RE002_Blby_bIncIdlSpd_in);
      RE002_EOM_bEnaCmbModChg_in = Rte_IrvRead_RE_EOMGsl_002_TEV_EOM_bEnaCmbModChg();

      Rte_Call_R_FRM_bAcvCmbModDft_GetFunctionPermission(&EOMGsl_RE002_FRM_bAcvCmbModDft_in);
      EOMGsl_RE002_FRM_bAcvCmbModDft_in = !EOMGsl_RE002_FRM_bAcvCmbModDft_in;
      Rte_Call_R_FRM_bAcvCmbModHiLvlDft_GetFunctionPermission(&EOMGsl_RE002_FRM_bAcvCmbModHiLvlDft_in);
      EOMGsl_RE002_FRM_bAcvCmbModHiLvlDft_in = !EOMGsl_RE002_FRM_bAcvCmbModHiLvlDft_in;
      Rte_Call_R_FRM_bAcvNomModPrio_GetFunctionPermission(&EOMGsl_RE002_FRM_bAcvNomModPrio_in);
      EOMGsl_RE002_FRM_bAcvNomModPrio_in = !EOMGsl_RE002_FRM_bAcvNomModPrio_in;
      Rte_Call_R_FRM_bInhCmbModPrf_GetFunctionPermission(&EOMGsl_RE002_FRM_bInhCmbModPrf_in);
      EOMGsl_RE002_FRM_bInhCmbModPrf_in = !EOMGsl_RE002_FRM_bInhCmbModPrf_in;
      Rte_Call_R_FRM_bAcvTCoMesDft_GetFunctionPermission(&EOMGsl_RE002_FRM_bAcvTCoMesDft_in);
      EOMGsl_RE002_FRM_bAcvTCoMesDft_in = !EOMGsl_RE002_FRM_bAcvTCoMesDft_in;
      EOMGsl_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_EOMGsl_002_TEV_EOM_bDiTran(RE002_EOM_bDiTran_out);
   (void)Rte_IrvWrite_RE_EOMGsl_002_TEV_EOM_bFdoutModReq(RE002_EOM_bFdoutModReq_out);
   (void)Rte_IrvWrite_RE_EOMGsl_002_TEV_EOM_stCmbModReq(RE002_EOM_stCmbModReq_out);
   
}

void RE_EOMGsl_003_TEV(void)
{
   if (FALSE == EOMGSL_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EOMGsl_RE003_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tCoStrtMes_Ext_tCoStrtMes(&EOMGsl_RE003_Ext_tCoStrtMes_in);
      (void)Rte_Read_R_Ext_tiStrt_Ext_tiStrt(&EOMGsl_RE003_Ext_tiStrt_in);
      (void)Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&EOMGsl_RE003_EOM_tiEngStop_in);
      RE003_EOM_prm_facTranModNotSync_01_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_01();
      RE003_EOM_prm_facTranModNotSync_02_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_02();
      RE003_EOM_prm_facTranModNotSync_03_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_03();
      RE003_EOM_prm_facTranModNotSync_04_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_04();
      RE003_EOM_prm_facTranModNotSync_05_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_05();
      RE003_EOM_prm_facTranModNotSync_06_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_06();
      RE003_EOM_prm_facTranModNotSync_07_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_07();
      RE003_EOM_prm_facTranModNotSync_08_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_08();
      RE003_EOM_prm_facTranModNotSync_09_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_09();
      RE003_EOM_prm_facTranModNotSync_10_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_10();
      RE003_EOM_prm_facTranModNotSync_11_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_11();
      RE003_EOM_prm_facTranModNotSync_12_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_12();
      RE003_EOM_prm_facTranModNotSync_13_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_13();
      RE003_EOM_prm_facTranModNotSync_14_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_14();
      RE003_EOM_prm_facTranModNotSync_15_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_15();
      RE003_EOM_prm_facTranModNotSync_16_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_prm_facTranModNotSync_16();
      RE003_EOM_stCmbModTar_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_stCmbModTar();
      RE003_EOM_stCmbModCur_in = Rte_IrvRead_RE_EOMGsl_003_TEV_EOM_stCmbModCur();

      Rte_Call_R_FRM_bAcvTCoMesDft_GetFunctionPermission(&EOMGsl_RE003_FRM_bAcvTCoMesDft_in);
      EOMGsl_RE003_FRM_bAcvTCoMesDft_in = !EOMGsl_RE003_FRM_bAcvTCoMesDft_in;
      EOMGsl_003_TEV_fct();
   }
   else
   {
	int i;
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
	  for (i = 0; i<16;i++){
         EOM_prm_facBasModCur_out[i] = EOM_prm_facBasModCur_B[i];
         EOM_prm_facBasModTar_out[i] = EOM_prm_facBasModTar_B[i];
         EOM_prm_facTranMod_out[i] = EOM_prm_facTranMod_B[i];
         EOM_prm_idxBas1ModCur_out[i] = EOM_prm_idxBas1ModCur_B[i];
         EOM_prm_idxBas1ModTar_out[i] = EOM_prm_idxBas1ModTar_B[i];
         EOM_prm_idxBas2ModCur_out[i] = EOM_prm_idxBas2ModCur_B[i];
         EOM_prm_idxBas2ModTar_out[i] = EOM_prm_idxBas2ModTar_B[i];
	  }
   }
   (void)Rte_Write_P_EOM_prm_facBasModCur_EOM_prm_facBasModCur(EOM_prm_facBasModCur_out);
   (void)Rte_Write_P_EOM_prm_facBasModTar_EOM_prm_facBasModTar(EOM_prm_facBasModTar_out);
   (void)Rte_Write_P_EOM_prm_facTranMod_EOM_prm_facTranMod(EOM_prm_facTranMod_out);
   (void)Rte_Write_P_EOM_prm_idxBas1ModCur_EOM_prm_idxBas1ModCur(EOM_prm_idxBas1ModCur_out);
   (void)Rte_Write_P_EOM_prm_idxBas1ModTar_EOM_prm_idxBas1ModTar(EOM_prm_idxBas1ModTar_out);
   (void)Rte_Write_P_EOM_prm_idxBas2ModCur_EOM_prm_idxBas2ModCur(EOM_prm_idxBas2ModCur_out);
   (void)Rte_Write_P_EOM_prm_idxBas2ModTar_EOM_prm_idxBas2ModTar(EOM_prm_idxBas2ModTar_out);
   
}

void RE_EOMGsl_004_TEV(void)
{
   if (FALSE == EOMGSL_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      RE004_EOM_bDiTran_in = Rte_IrvRead_RE_EOMGsl_004_TEV_EOM_bDiTran();
      RE004_EOM_bFdoutModReq_in = Rte_IrvRead_RE_EOMGsl_004_TEV_EOM_bFdoutModReq();
      RE004_EOM_stCmbModReq_in = Rte_IrvRead_RE_EOMGsl_004_TEV_EOM_stCmbModReq();

      EOMGsl_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      EOM_bSpcInjMod_out = EOM_bSpcInjMod_B;
      EOM_bTranMod_out = EOM_bTranMod_B;
      EOM_bTWCHeatPha_out = EOM_bTWCHeatPha_B;
   }
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_01(RE004_EOM_prm_facTranModNotSync_01_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_02(RE004_EOM_prm_facTranModNotSync_02_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_03(RE004_EOM_prm_facTranModNotSync_03_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_04(RE004_EOM_prm_facTranModNotSync_04_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_05(RE004_EOM_prm_facTranModNotSync_05_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_06(RE004_EOM_prm_facTranModNotSync_06_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_07(RE004_EOM_prm_facTranModNotSync_07_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_08(RE004_EOM_prm_facTranModNotSync_08_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_09(RE004_EOM_prm_facTranModNotSync_09_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_10(RE004_EOM_prm_facTranModNotSync_10_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_11(RE004_EOM_prm_facTranModNotSync_11_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_12(RE004_EOM_prm_facTranModNotSync_12_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_13(RE004_EOM_prm_facTranModNotSync_13_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_14(RE004_EOM_prm_facTranModNotSync_14_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_15(RE004_EOM_prm_facTranModNotSync_15_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_prm_facTranModNotSync_16(RE004_EOM_prm_facTranModNotSync_16_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_stCmbModTar(RE004_EOM_stCmbModTar_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_bEnaCmbModChg(RE004_EOM_bEnaCmbModChg_out);
   (void)Rte_IrvWrite_RE_EOMGsl_004_TEV_EOM_stCmbModCur(RE004_EOM_stCmbModCur_out);
   (void)Rte_Write_P_EOM_bSpcInjMod_EOM_bSpcInjMod(EOM_bSpcInjMod_out);
   (void)Rte_Write_P_EOM_bTranMod_EOM_bTranMod(EOM_bTranMod_out);
   (void)Rte_Write_P_EOM_bTWCHeatPha_EOM_bTWCHeatPha(EOM_bTWCHeatPha_out);
   
}

#define EOMGSL_STOP_SEC_CODE
#include "EOMGsl_MemMap.h"

#endif/*_EOMGSL_C_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
