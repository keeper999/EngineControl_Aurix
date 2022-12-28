/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : DfwCtl.c
* Description   : Interface AUTOSAR du module DfwCtl avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 18-Jan-2011(11:45:58)
*******************************************************************************/

#ifndef _DFWCTL_C_
#define _DFWCTL_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_DfwCtl.h"
#include "DfwCtl.h"
#include "DfwCtl_002_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define DFWCTL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "DfwCtl_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 DfwCtl_ModuleVersion_Major_MP = 1;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 DfwCtl_ModuleVersion_Minor_MP = 5;
#define DFWCTL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "DfwCtl_MemMap.h"

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

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define DFWCTL_START_SEC_CALIB_BOOLEAN
#include "DfwCtl_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean DFWCTL_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean DfwCtl_bAcvLimTqIdl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean DfwCtl_bInhInjProtDfw_B = 0;
#define DFWCTL_STOP_SEC_CALIB_BOOLEAN
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_CALIB_16BIT
#include "DfwCtl_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 DfwCtl_noOverOscDetProtAcv_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 DfwCtl_noProtAdp_B = 0;
#define DFWCTL_STOP_SEC_CALIB_16BIT
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_VAR_BOOLEAN
#include "DfwCtl_MemMap.h"
static Boolean DfwCtl_bMonRunProtAdp_out_prec;
#define DFWCTL_STOP_SEC_VAR_BOOLEAN
#include "DfwCtl_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define DFWCTL_START_SEC_CODE
#include "DfwCtl_MemMap.h"

void RE_DfwCtl_001_MSE(void)
{

      DfwCtl_001_MSE_ini();

      (void)Rte_Write_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl(0);
      (void)Rte_Write_P_DfwCtl_bInhInjProtDfw_DfwCtl_bInhInjProtDfw(0);
      (void)Rte_Write_P_DfwCtl_noOverOscDetProtAcv_DfwCtl_noOverOscDetProtAcv(0);
      (void)Rte_Write_P_DfwCtl_noProtAdp_DfwCtl_noProtAdp(0);

}

void RE_DfwCtl_002_TEV(void)
{

  if (FALSE == DFWCTL_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Afts_bRstDfwChg_Afts_bRstDfwChg(&DfwCtl_Afts_bRstDfwChg_in);
      (void)Rte_Read_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(&DfwCtl_CoStrtRStrt_stEngStrtReq_in);
      (void)Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&DfwCtl_CoSync_bDetNNull_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&DfwCtl_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_Ext_bDirRotCk_Ext_bDirRotCk(&DfwCtl_Ext_bDirRotCk_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&DfwCtl_Ext_nEng_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&DfwCtl_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&DfwCtl_Ext_tCoMes_in);
      (void)Rte_Read_R_PredEs_bVldFastN_PredEs_bVldFastN(&DfwCtl_PredEs_bVldFastN_in);
      (void)Rte_Read_R_PredEs_nFast_PredEs_nFast(&DfwCtl_PredEs_nFast_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&DfwCtl_Veh_spdVeh_in);

      Rte_Call_R_FRM_bInhOscDet_GetFunctionPermission(& DfwCtl_FRM_bInhOscDet_in);
      DfwCtl_FRM_bInhOscDet_in = !DfwCtl_FRM_bInhOscDet_in;
      Rte_Call_R_FRM_bInhOscDet_GetFunctionPermission(& DfwCtl_FRM_bInhOscDet_in);
      DfwCtl_FRM_bInhOscDet_in = !DfwCtl_FRM_bInhOscDet_in;
      DfwCtl_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      DfwCtl_bAcvLimTqIdl_out = DfwCtl_bAcvLimTqIdl_B;
      DfwCtl_bInhInjProtDfw_out = DfwCtl_bInhInjProtDfw_B;
      DfwCtl_noOverOscDetProtAcv_out = DfwCtl_noOverOscDetProtAcv_B;
      DfwCtl_noProtAdp_out = DfwCtl_noProtAdp_B;
  }
  (void)Rte_Write_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl(DfwCtl_bAcvLimTqIdl_out);
  (void)Rte_Write_P_DfwCtl_bInhInjProtDfw_DfwCtl_bInhInjProtDfw(DfwCtl_bInhInjProtDfw_out);
  (void)Rte_Write_P_DfwCtl_noOverOscDetProtAcv_DfwCtl_noOverOscDetProtAcv(DfwCtl_noOverOscDetProtAcv_out);
  (void)Rte_Write_P_DfwCtl_noProtAdp_DfwCtl_noProtAdp(DfwCtl_noProtAdp_out);

  if (FALSE == DFWCTL_ACTIVE_BYP_C)
  {

  /* Diag treatment : DfwCtl_ProtAdp */
     if(DfwCtl_bMonRunProtAdp_out==1)
     {
         /* Diag activation */
         if(DfwCtl_bDgoProtAdp_out==1)
         {
              Rte_Call_R_DfwCtl_ProtAdp_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_DfwCtl_ProtAdp_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (DfwCtl_bMonRunProtAdp_out_prec==1)
         {
             Rte_Call_R_DfwCtl_ProtAdp_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     DfwCtl_bMonRunProtAdp_out_prec = DfwCtl_bMonRunProtAdp_out;
  }

}

#define DFWCTL_STOP_SEC_CODE
#include "DfwCtl_MemMap.h"

#endif/*_DFWCTL_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

