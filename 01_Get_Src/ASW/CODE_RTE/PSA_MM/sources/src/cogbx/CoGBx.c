/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoGBx.c
* Description   : Interface AUTOSAR du module CoGBx avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 25-Aug-2010(11:31:48)
*******************************************************************************/

#ifndef _COGBX_C_
#define _COGBX_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_CoGBx.h"
#include "CoGBx.h"
#include "CoGBx2096_fct.h"
#include "TqSys_Sdl10ms_CluPCord_fct.h"
#include "TqSys_Sdl10ms_CoPtGearCord_fct.h"
#include "TqSys_Sdl10ms_Tra_1_fct.h"
#include "TqSys_Sdl10ms_Tra_2_fct.h"
#include "TqSys_Sdl10ms_Tra_3_fct.h"
#include "TqSys_Sdl10ms_Tra_4_fct.h"
#include "TqSys_Sdl20ms_Tra_fct.h"
#include "TqSys_EveSync_Tra_1_fct.h"
#include "TqSys_EveSync_Tra_2_fct.h"
#include "TqSys_EveSyncFrame30D_Tra_fct.h"
#include "TqSys_EveSyncFrame38D_Tra_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoGBx_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoGBx_ModuleVersion_Major_MP = 11;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoGBx_ModuleVersion_Minor_MP = 0;
#define COGBX_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoGBx_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 1
#define Module_LIB_PSA_VERSION_REQ_MIN 5

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_CALIB_BOOLEAN
#include "CoGBx_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean COGBX_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bCluPedxVV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bDrvTra_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean Clu_bCluPedEng_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIPcordAirSys_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bCluDiEgdCord_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bRvsCord_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIPCord_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean Tra_bGearManVld_B = 0;
#define COGBX_STOP_SEC_CALIB_BOOLEAN
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_CALIB_8BIT
#include "CoGBx_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 TqDem_rGearRatAftRng_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noEgdGearCordExtd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noEgdGearCord_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noGearCord_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noGearCordDrivFil_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noTarGearCord_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 Tra_noGearMan_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noEgdGearCordIt_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noTarGearCordIt_B = 0;
#define COGBX_STOP_SEC_CALIB_8BIT
#include "CoGBx_MemMap.h"

#define COGBX_START_SEC_CALIB_32BIT
#include "CoGBx_MemMap.h"
AR_MERGEABLE_CALIB_32BIT UInt32 CoPt_spdVehGearRatCord_B = 0;
#define COGBX_STOP_SEC_CALIB_32BIT
#include "CoGBx_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define COGBX_START_SEC_CODE
#include "CoGBx_MemMap.h"

void RE_CoGBx_001_MSE(void)
{


      //CoGBx_001_MSE_ini();
	  Msn_FctVarInit();
	  CoGBx_2040_FctVarInit();
	  TqSys_Sdl10ms_CoPtGearCord_ini();

  // Irv remplacée par une E-S
  //(void)Rte_IrvWrite_RE_CoGBx_001_MSE_Tra_bGearManVld_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_Tra_spdVehGearRatCord_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_stGearratOverNRise_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_n6CylEngMvFil_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_spdVehFil1_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_spdWhlFil1_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_bGearRatCdnVld1_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_rPedPrssGrd_irv(0);
  (void)Rte_IrvWrite_RE_CoGBx_001_MSE_TqDem_tqTqRealSyncFuseMv_irv(0);
      (void)Rte_Write_P_Clu_bCluPedxVV_Clu_bCluPedxVV(0);
      (void)Rte_Write_P_Clu_bDrvTra_Clu_bDrvTra(0);
      (void)Rte_Write_P_Clu_bCluPedEng_Clu_bCluPedEng(0);
      (void)Rte_Write_P_TqDem_rGearRatAftRng_TqDem_rGearRatAftRng(0);
      (void)Rte_Write_P_CoPt_bSIPcordAirSys_CoPt_bSIPcordAirSys(0);
      (void)Rte_Write_P_CoPt_noEgdGearCordExtd_CoPt_noEgdGearCordExtd(0);
      (void)Rte_Write_P_CoPt_bCluDiEgdCord_CoPt_bCluDiEgdCord(0);
      (void)Rte_Write_P_CoPt_bRvsCord_CoPt_bRvsCord(0);
      (void)Rte_Write_P_CoPt_bSIPCord_CoPt_bSIPCord(0);
      (void)Rte_Write_P_CoPt_noEgdGearCord_CoPt_noEgdGearCord(0);
      (void)Rte_Write_P_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(0);
      (void)Rte_Write_P_CoPt_noGearCord_CoPt_noGearCord(0);
      (void)Rte_Write_P_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(0);
      (void)Rte_Write_P_CoPt_noTarGearCord_CoPt_noTarGearCord(0);
      (void)Rte_Write_P_CoPt_noTarGearCordIt_CoPt_noTarGearCordIt(0);
      (void)Rte_Write_P_CoPt_spdVehGearRatCord_CoPt_spdVehGearRatCord(0);
      (void)Rte_Write_P_Tra_noGearMan_Tra_noGearMan(0);
      (void)Rte_Write_P_Tra_bGearManVld_Tra_bGearManVld(0); // Irv remplacée par une E-S

}

void RE_TqSys_Sdl10ms_CluPCord(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
	      /* Module code execution */
	      /* Module behaviour unchanged */

	      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&CoGBx_2040_Ext_rCluPHiFreq_in);

	      Rte_Call_R_FRM_bAcvDrvTraInvld_GetFunctionPermission(& CoGBx_2040_FRM_bAcvDrvTraInvld_in);
	      CoGBx_2040_FRM_bAcvDrvTraInvld_in = !CoGBx_2040_FRM_bAcvDrvTraInvld_in;
	      TqSys_Sdl10ms_CluPCord_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      Clu_bCluPedxVV_out = Clu_bCluPedxVV_B;
      Clu_bDrvTra_out = Clu_bDrvTra_B;
      Clu_bCluPedEng_out = Clu_bCluPedEng_B;
  }
  (void)Rte_Write_P_Clu_bCluPedxVV_Clu_bCluPedxVV(Clu_bCluPedxVV_out);
  (void)Rte_Write_P_Clu_bDrvTra_Clu_bDrvTra(Clu_bDrvTra_out);
  (void)Rte_Write_P_Clu_bCluPedEng_Clu_bCluPedEng(Clu_bCluPedEng_out);

}

void RE_TqSys_Sdl10ms_CoPtGearCord(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&CoGBx_2097_AccP_rAccP_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&CoGBx_2097_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2097_Ext_stGBxCf_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoGBx_2097_Veh_spdVeh_in);
      (void)Rte_Read_R_CoPt_bPrepSIP_CoPt_bPrepSIP(&CoGBx_2097_CoPt_bPrepSIP_in);
      (void)Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&CoGBx_2097_CoPt_bSIP_in);
      (void)Rte_Read_R_CoPt_noEgdGear_CoPt_noEgdGear(&CoGBx_2097_CoPt_noEgdGear_in);
      (void)Rte_Read_R_CoPt_noTarGear_CoPt_noTarGear(&CoGBx_2097_CoPt_noTarGear_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&CoGBx_2097_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_bRvs_Ext_bRvs(&CoGBx_2097_Ext_bRvs_in);
      (void)Rte_Read_R_Ext_bRvsVld_Ext_bRvsVld(&CoGBx_2097_Ext_bRvsVld_in);
      (void)Rte_Read_R_Ext_bSecBrkPedPrssMes_Ext_bSecBrkPedPrssMes(&CoGBx_2097_Ext_bSecBrkPedPrssMes_in);
	  (void)Rte_Read_R_Tra_noGearMan_Tra_noGearMan(&CoGBx_2097_Tra_noGearMan_in);
	  (void)Rte_Read_R_Tra_bGearManVld_Tra_bGearManVld(&CoGBx_2097_Tra_bGearManVld_in); // Irv remplacée par une E-S

      TqSys_Sdl10ms_CoPtGearCord_Tra_spdVehGearRatCord_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_CoPtGearCord_Tra_spdVehGearRatCord_irv();

      Rte_Call_R_FRM_bDft_spdVeh_GetFunctionPermission(& CoGBx_2097_FRM_bDft_spdVeh_in);
      CoGBx_2097_FRM_bDft_spdVeh_in = !CoGBx_2097_FRM_bDft_spdVeh_in;
      Rte_Call_R_FRM_bDft_bBrkPedPrss_GetFunctionPermission(& CoGBx_2097_FRM_bDft_bBrkPedPrss_in);
      CoGBx_2097_FRM_bDft_bBrkPedPrss_in = !CoGBx_2097_FRM_bDft_bBrkPedPrss_in;
      Rte_Call_R_FRM_bDft_bCluPPedPrss_GetFunctionPermission(& CoGBx_2097_FRM_bDft_bCluPPedPrss_in);
      CoGBx_2097_FRM_bDft_bCluPPedPrss_in = !CoGBx_2097_FRM_bDft_bCluPPedPrss_in;
      TqSys_Sdl10ms_CoPtGearCord_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPt_bSIPcordAirSys_out = CoPt_bSIPcordAirSys_B;
      CoPt_noEgdGearCordExtd_out = CoPt_noEgdGearCordExtd_B;
      CoPt_bCluDiEgdCord_out = CoPt_bCluDiEgdCord_B;
      CoPt_bRvsCord_out = CoPt_bRvsCord_B;
      CoPt_bSIPCord_out = CoPt_bSIPCord_B;
      CoPt_noEgdGearCord_out = CoPt_noEgdGearCord_B;
      CoPt_noEgdGearCordIt_out = CoPt_noEgdGearCordIt_B;
      CoPt_noGearCord_out = CoPt_noGearCord_B;
      CoPt_noGearCordDrivFil_out = CoPt_noGearCordDrivFil_B;
      CoPt_noTarGearCord_out = CoPt_noTarGearCord_B;
      CoPt_noTarGearCordIt_out = CoPt_noTarGearCordIt_B;
      CoPt_spdVehGearRatCord_out = CoPt_spdVehGearRatCord_B;
  }
  (void)Rte_Write_P_CoPt_bSIPcordAirSys_CoPt_bSIPcordAirSys(CoPt_bSIPcordAirSys_out);
  (void)Rte_Write_P_CoPt_noEgdGearCordExtd_CoPt_noEgdGearCordExtd(CoPt_noEgdGearCordExtd_out);
  (void)Rte_Write_P_CoPt_bCluDiEgdCord_CoPt_bCluDiEgdCord(CoPt_bCluDiEgdCord_out);
  (void)Rte_Write_P_CoPt_bRvsCord_CoPt_bRvsCord(CoPt_bRvsCord_out);
  (void)Rte_Write_P_CoPt_bSIPCord_CoPt_bSIPCord(CoPt_bSIPCord_out);
  (void)Rte_Write_P_CoPt_noEgdGearCord_CoPt_noEgdGearCord(CoPt_noEgdGearCord_out);
  (void)Rte_Write_P_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(CoPt_noEgdGearCordIt_out);
  (void)Rte_Write_P_CoPt_noGearCord_CoPt_noGearCord(CoPt_noGearCord_out);
  (void)Rte_Write_P_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(CoPt_noGearCordDrivFil_out);
  (void)Rte_Write_P_CoPt_noTarGearCord_CoPt_noTarGearCord(CoPt_noTarGearCord_out);
  (void)Rte_Write_P_CoPt_noTarGearCordIt_CoPt_noTarGearCordIt(CoPt_noTarGearCordIt_out);
  (void)Rte_Write_P_CoPt_spdVehGearRatCord_CoPt_spdVehGearRatCord(CoPt_spdVehGearRatCord_out);

}

void RE_TqSys_EveSync_Tra(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */
	 (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2096_Ext_stGBxCf_in);
     if (CoGBx_2096_Ext_stGBxCf_in == 0)
	 {

      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&CoGBx_2096_Ext_tOilMes_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&CoGBx_2096_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_Ext_bTOilChk_Ext_bTOilChk(&CoGBx_2096_Ext_bTOilChk_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoGBx_2096_Ext_nEng_in);
      (void)Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&CoGBx_2096_Ext_noCylEng_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&CoGBx_2096_Ext_tiTDC_in);
      (void)Rte_Read_R_InjSys_bFuCutOff_InjSys_bFuCutOff(&CoGBx_2096_InjSys_bFuCutOff_in);
      (void)Rte_Read_R_TqCmp_pwrACLoss_TqCmp_pwrACLoss(&CoGBx_2096_TqCmp_pwrACLoss_in);
      (void)Rte_Read_R_TqDiag_bUncrt_tqCkEngReal_TqDiag_bUncrt_tqCkEngReal(&CoGBx_2096_TqDiag_bUncrt_tqCkEngReal_in);
      (void)Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&CoGBx_2096_TqSys_bEngNOnIdl_in);
      (void)Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&CoGBx_2096_TqSys_tqCkEngReal_in);
      (void)Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&CoGBx_2096_TqSys_tqIdcReq_in);
      (void)Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&CoGBx_2096_TreatTDC_nCkGrd_in);
      //(void)Rte_Read_R_EV_TqSys_EveSync_Tra_EV_TqSys_EveSync_Tra_DRE(&CoGBx_2096_EV_TqSys_EveSync_Tra_in);
      (void)Rte_Read_R_Tra_noGearMan_Tra_noGearMan(&CoGBx_2096_Tra_noGearMan_in);
	  TqSys_EveSync_Tra_TqDem_bGearRatCdnVld1_irv_in = Rte_IrvRead_RE_TqSys_EveSync_Tra_TqDem_bGearRatCdnVld1_irv();
      TqSys_EveSync_Tra_TqDem_rPedPrssGrd_irv_in = Rte_IrvRead_RE_TqSys_EveSync_Tra_TqDem_rPedPrssGrd_irv();

      Rte_Call_R_FRM_bInhOverShootDet_GetFunctionPermission(& CoGBx_2096_FRM_bInhOverShootDet_in);
      CoGBx_2096_FRM_bInhOverShootDet_in = !CoGBx_2096_FRM_bInhOverShootDet_in;
      TqSys_EveSync_Tra_1_fct();
      TqSys_EveSync_Tra_2_fct();

	  }
  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_TqSys_EveSync_Tra_TqDem_stGearratOverNRise_irv(TqSys_EveSync_Tra_TqDem_stGearRatOverNRise_irv_out);
  (void)Rte_IrvWrite_RE_TqSys_EveSync_Tra_TqDem_n6CylEngMvFil_irv(TqSys_EveSync_Tra_TqDem_n6CylEngMvFil_irv_out);
  (void)Rte_IrvWrite_RE_TqSys_EveSync_Tra_TqDem_tqTqRealSyncFuseMv_irv(TqSys_EveSync_Tra_TqDem_tqTqRealSyncFuseMv_irv_out);

}

void RE_TqSys_EveSyncFrame30D_Tra(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
	 (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2096_Ext_stGBxCf_in);
     if (CoGBx_2096_Ext_stGBxCf_in == 0)
	 {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_spdVehAvrFrntWhl_Ext_spdVehAvrFrntWhl(&CoGBx_2096_Ext_spdVehAvrFrntWhl_in);
      //(void)Rte_Read_R_EV_TqSys_EveSyncFrame30D_Tra_EV_TqSys_EveSyncFrame30D_Tra_DRE(&CoGBx_EV_TqSys_EveSyncFrame30D_Tra_Eve_in);

      TqSys_EveSyncFrame30D_Tra_fct();
	}
  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_TqSys_EveSyncFrame30D_Tra_TqDem_spdWhlFil1_irv(TqSys_EveSyncFrame30D_Tra_TqDem_spdWhlFil1_irv_out);

}

void RE_TqSys_EveSyncFrame38D_Tra(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
	 (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2096_Ext_stGBxCf_in);
	 if (CoGBx_2096_Ext_stGBxCf_in == 0)
	 {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&CoGBx_2096_Ext_spdVeh_in);
      //(void)Rte_Read_R_EV_TqSys_EveSyncFrame38D_Tra_EV_TqSys_EveSyncFrame38D_Tra_DRE(&CoGBx_EV_TqSys_EveSyncFrame38D_Tra_Eve_in);

      TqSys_EveSyncFrame38D_Tra_fct();
	}
  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_TqSys_EveSyncFrame38D_Tra_TqDem_spdVehFil1_irv(TqSys_EveSyncFrame38D_Tra_TqDem_spdVehFil1_irv_out);

}

void RE_TqSys_Sdl10ms_Tra(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
     (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2096_Ext_stGBxCf_in);
     if (CoGBx_2096_Ext_stGBxCf_in == 0)
	 {
      /* Module code execution */
      /* Module behaviour unchanged */
	  (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&CoGBx_2096_Veh_spdVeh_in);
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&CoGBx_2096_AccP_rAccP_in);
      (void)Rte_Read_R_Cha_bABSReg_Cha_bABSReg(&CoGBx_2096_Cha_bABSReg_in);
      (void)Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&CoGBx_2096_CoPt_noGearCord_in);
      (void)Rte_Read_R_CoVSCtl_tqEfcReq_CoVSCtl_tqEfcReq(&CoGBx_2096_CoVSCtl_tqEfcReq_in);
      (void)Rte_Read_R_Ext_nAvrFrntWhlCAN_Ext_nAvrFrntWhlCAN(&CoGBx_2096_Ext_nAvrFrntWhlCAN_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&CoGBx_2096_Ext_nEng_in);
      (void)Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&CoGBx_2096_Ext_noCylEng_in);
      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&CoGBx_2096_Ext_spdVeh_in);
      (void)Rte_Read_R_TqSys_bClrCrossAcce_TqSys_bClrCrossAcce(&CoGBx_2096_TqSys_bClrCrossAcce_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&CoGBx_2096_TqSys_nTarIdl_in);
      TqSys_Sdl10ms_Tra_TqDem_stGearRatOverNRise_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_Tra_TqDem_stGearratOverNRise_irv();
      TqSys_Sdl10ms_Tra_TqDem_n6CylEngMvFil_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_Tra_TqDem_n6CylEngMvFil_irv();
      TqSys_Sdl10ms_Tra_TqDem_spdWhlFil1_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_Tra_TqDem_spdWhlFil1_irv();
      TqSys_Sdl10ms_Tra_TqDem_spdVehFil1_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_Tra_TqDem_spdVehFil1_irv();
      TqSys_Sdl10ms_Tra_TqDem_tqTqRealSyncFuseMv_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_Tra_TqDem_tqTqRealSyncFuseMv_irv();

      //Rte_Call_R_FRM_bDft_bBrkPedPrss_GetFunctionPermission(& CoGBx_FRM_bDft_bBrkPedPrss_Sdl_in);
      //CoGBx_FRM_bDft_bBrkPedPrss_Sdl_in = !CoGBx_FRM_bDft_bBrkPedPrss_Sdl_in;
      Rte_Call_R_FRM_bDft_CluPedPrss_GetFunctionPermission(& CoGBx_2096_FRM_bDft_CluPedPrss_in);
      CoGBx_2096_FRM_bDft_CluPedPrss_in = !CoGBx_2096_FRM_bDft_CluPedPrss_in;
      TqSys_Sdl10ms_Tra_1_fct();
      TqSys_Sdl10ms_Tra_3_fct();
      TqSys_Sdl10ms_Tra_4_fct();
      TqSys_Sdl10ms_Tra_2_fct();
	}
  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      TqDem_rGearRatAftRng_out = TqDem_rGearRatAftRng_B;
      Tra_noGearMan_out = Tra_noGearMan_B;
  }
  (void)Rte_IrvWrite_RE_TqSys_Sdl10ms_Tra_Tra_spdVehGearRatCord_irv(TqSys_Sdl10ms_Tra_Tra_spdVehGearRatCord_irv_out);
  (void)Rte_IrvWrite_RE_TqSys_Sdl10ms_Tra_TqDem_bGearRatCdnVld1_irv(TqSys_Sdl10ms_Tra_TqDem_bGearRatCdnVld1_irv_out);
  (void)Rte_IrvWrite_RE_TqSys_Sdl10ms_Tra_TqDem_rPedPrssGrd_irv(TqSys_Sdl10ms_Tra_TqDem_rPedPrssGrd_irv_out);
  (void)Rte_Write_P_TqDem_rGearRatAftRng_TqDem_rGearRatAftRng(TqDem_rGearRatAftRng_out);
  (void)Rte_Write_P_Tra_noGearMan_Tra_noGearMan(Tra_noGearMan_out);
}

void RE_TqSys_Sdl20ms_Tra(void)
{

  if (FALSE == COGBX_ACTIVE_BYP_C)
  {
	 (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&CoGBx_2096_Ext_stGBxCf_in);
     if (CoGBx_2096_Ext_stGBxCf_in == 0)
	 {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_bAvrFrntWhlVld_Ext_bAvrFrntWhlVld(&CoGBx_2096_Ext_bAvrFrntWhlVld_in);
      (void)Rte_Read_R_Ext_bEspVehVld_Ext_bEspVehVld(&CoGBx_2096_Ext_bEspVehVld_in);
      (void)Rte_Read_R_Ext_bFrntLeftWhlVehVld_Ext_bFrntLeftWhlVehVld(&CoGBx_2096_Ext_bFrntLeftWhlVehVld_in);
      (void)Rte_Read_R_Ext_bFrntRightWhlVehVld_Ext_bFrntRightWhlVehVld(&CoGBx_2096_Ext_bFrntRightWhlVehVld_in);

      Rte_Call_R_FRM_bDft_spdVeh_GetFunctionPermission(& CoGBx_2096_FRM_bDft_spdVeh_in);
      CoGBx_2096_FRM_bDft_spdVeh_in = !CoGBx_2096_FRM_bDft_spdVeh_in;
      TqSys_Sdl20ms_Tra_fct();
	}
  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
	Tra_bGearManVld_out = Tra_bGearManVld_B;

  }
  // Irv remplacée par une E-S
  //(void)Rte_IrvWrite_RE_TqSys_Sdl20ms_Tra_Tra_bGearManVld_irv(TqSys_Sdl20ms_Tra_Tra_bGearManVld_irv_out);
  (void)Rte_Write_P_Tra_bGearManVld_Tra_bGearManVld(Tra_bGearManVld_out);

}

#define COGBX_STOP_SEC_CODE
#include "CoGBx_MemMap.h"

#endif/*_COGBX_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

