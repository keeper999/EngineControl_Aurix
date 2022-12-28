/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : EngLim.c
* Description   : Interface AUTOSAR du module EngLim avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 12-Aug-2010(9:55:2)
*******************************************************************************/

#ifndef _ENGLIM_C_
#define _ENGLIM_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_EngLim.h"
#include "EngLim.h"
#include "TqSys_Sdl10ms_EngLimStat_fct.h"
#include "TqSys_Sdl10ms_TqLimFwdRvs_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define ENGLIM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "EngLim_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EngLim_ModuleVersion_Major_MP = 11;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EngLim_ModuleVersion_Minor_MP = 1;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EngLim_ModuleVersion_Build_MP = 1;
#define ENGLIM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "EngLim_MemMap.h"

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
#define ENGLIM_START_SEC_CALIB_BOOLEAN
#include "EngLim_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean ENGLIM_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean EngLim_bAcvCll_B = 0;
#define ENGLIM_STOP_SEC_CALIB_BOOLEAN
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_CALIB_8BIT
#include "EngLim_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 EngLim_stLim_B = 1;
#define ENGLIM_STOP_SEC_CALIB_8BIT
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_CALIB_16BIT
#include "EngLim_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 EngLim_tiTranCll_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 EngLim_tqIncCll_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 EngLim_tqCkEfcStatLimIt_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 EngLim_tqCkEfcInrtLim_B = 32000;
#define ENGLIM_STOP_SEC_CALIB_16BIT
#include "EngLim_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define ENGLIM_START_SEC_CODE
#include "EngLim_MemMap.h"

void RE_EngLim_001_MSE(void)
{


 /*     EngLim_001_MSE_ini();*/
      TqSys_Sdl10ms_TqLimFwdRvs_fct();

      (void)Rte_Write_P_EngLim_tqCkEfcStatLimIt_EngLim_tqCkEfcStatLimIt(32000);
      (void)Rte_Write_P_EngLim_stLim_EngLim_stLim(1);
      (void)Rte_Write_P_EngLim_bAcvCll_EngLim_bAcvCll(0);
      (void)Rte_Write_P_EngLim_tiTranCll_EngLim_tiTranCll(0);
      (void)Rte_Write_P_EngLim_tqCkEfcInrtLim_EngLim_tqCkEfcInrtLim(32000);
      (void)Rte_Write_P_EngLim_tqIncCll_EngLim_tqIncCll(32000);

}

void RE_TqSys_Sdl10ms_EngLimStat(void)
{

  if (FALSE == ENGLIM_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&EngLim_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&EngLim_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&EngLim_Ext_stGBxCf_in);

      Rte_Call_R_FRM_bLimRvEngLim_GetFunctionPermission(&EngLim_FRM_bLimRvEngLim_in);
      EngLim_FRM_bLimRvEngLim_in = !EngLim_FRM_bLimRvEngLim_in;
      
      TqSys_Sdl10ms_EngLimStat_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      EngLim_tqCkEfcStatLimIt_out = EngLim_tqCkEfcStatLimIt_B;
  }
  (void)Rte_Write_P_EngLim_tqCkEfcStatLimIt_EngLim_tqCkEfcStatLimIt(EngLim_tqCkEfcStatLimIt_out);

}

void RE_TqSys_Sdl10ms_TqLimFwdRvs(void)
{

  if (FALSE == ENGLIM_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&EngLim_CoPTSt_stEng_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&EngLim_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_Ext_bRvs_Ext_bRvs(&EngLim_Ext_bRvs_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&EngLim_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&EngLim_Ext_tCoMes_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&EngLim_TqSys_bTypFu_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&EngLim_TqSys_nTarIdl_in);
      (void)Rte_Read_R_TqSys_tqCkEfcReq_TqSys_tqCkEfcReq(&EngLim_TqSys_tqCkEfcReq_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&EngLim_Veh_spdVeh_in);
      
      Rte_Call_R_FRM_bInhRvInrtLim_bCluP_GetFunctionPermission(&EngLim_FRM_bInhRvInrtLim_bCluP_in);
      EngLim_FRM_bInhRvInrtLim_bCluP_in     = ! EngLim_FRM_bInhRvInrtLim_bCluP_in;
      
      Rte_Call_R_FRM_bInhRvInrtLim_bRvs_GetFunctionPermission(&EngLim_FRM_bInhRvInrtLim_bRvs_in);
      EngLim_FRM_bInhRvInrtLim_bRvs_in      = !EngLim_FRM_bInhRvInrtLim_bRvs_in;
      
      Rte_Call_R_FRM_bInhInrtLim_tCoMes_GetFunctionPermission(&EngLim_FRM_bInhInrtLim_tCoMes_in);
      EngLim_FRM_bInhInrtLim_tCoMes_in      = !EngLim_FRM_bInhInrtLim_tCoMes_in;
      
      Rte_Call_R_FRM_bInhRvInrtLim_spdVeh_GetFunctionPermission(&EngLim_FRM_bInhRvInrtLim_spdVeh_in);
      EngLim_FRM_bInhRvInrtLim_spdVeh_in    = !EngLim_FRM_bInhRvInrtLim_spdVeh_in;
      
      TqSys_Sdl10ms_TqLimFwdRvs_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      EngLim_stLim_out = EngLim_stLim_B;
      EngLim_bAcvCll_out = EngLim_bAcvCll_B;
      EngLim_tiTranCll_out = EngLim_tiTranCll_B;
      EngLim_tqCkEfcInrtLim_out = EngLim_tqCkEfcInrtLim_B;
      EngLim_tqIncCll_out = EngLim_tqIncCll_B;
  }
  (void)Rte_Write_P_EngLim_stLim_EngLim_stLim(EngLim_stLim_out);
  (void)Rte_Write_P_EngLim_bAcvCll_EngLim_bAcvCll(EngLim_bAcvCll_out);
  (void)Rte_Write_P_EngLim_tiTranCll_EngLim_tiTranCll(EngLim_tiTranCll_out);
  (void)Rte_Write_P_EngLim_tqCkEfcInrtLim_EngLim_tqCkEfcInrtLim(EngLim_tqCkEfcInrtLim_out);
  (void)Rte_Write_P_EngLim_tqIncCll_EngLim_tqIncCll(EngLim_tqIncCll_out);

}

#define ENGLIM_STOP_SEC_CODE
#include "EngLim_MemMap.h"

#endif/*_ENGLIM_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

