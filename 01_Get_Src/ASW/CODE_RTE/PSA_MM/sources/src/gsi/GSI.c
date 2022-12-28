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
* %name: GSI.c %
*
* %version: 13.0.build1 %
*
* %date_modified: Tue Oct 18 14:36:34 2011 %
*
*
* %derived_by: e360852 %
* %release: GSI/13.0 %
* %full_filespec: GSI.c-13.0.build1:csrc:5 %
*
*******************************************************************************/

#ifndef _GSI_C_
#define _GSI_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_GSI.h"
#include "GSI.h"
#include "GSI_002_TEV_fct.h"
#include "GSI_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define GSI_START_SEC_CONST_VERSION_MODULE_8BIT
#include "GSI_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 GSI_ModuleVersion_Major_MP = 13;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 GSI_ModuleVersion_Minor_MP = 0;
#define GSI_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "GSI_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 4
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define GSI_START_SEC_CALIB_BOOLEAN
#include "GSI_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean GSI_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean GSI3_stGSIEna_B = 0;
#define GSI_STOP_SEC_CALIB_BOOLEAN
#include "GSI_MemMap.h"

#define GSI_START_SEC_CALIB_8BIT
#include "GSI_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_noEgdGearCordFilIt_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_noTarGear_B = 9;
AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_stGearShiftReq_B = 3;
#define GSI_STOP_SEC_CALIB_8BIT
#include "GSI_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define GSI_START_SEC_CODE
#include "GSI_MemMap.h"
void RE_GSI_001_MSE(void)
{
   GSI_001_MSE_ini();

   (void)Rte_Write_P_GSI3_noEgdGearCordFilIt_GSI3_noEgdGearCordFilIt(0);
   (void)Rte_Write_P_GSI3_noTarGear_GSI3_noTarGear(9);
   (void)Rte_Write_P_GSI3_stGearShiftReq_GSI3_stGearShiftReq(3);
   (void)Rte_Write_P_GSI3_stGSIEna_GSI3_stGSIEna(0);
}

void RE_GSI_002_TEV(void)
{
   if (FALSE == GSI_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&GSI_AccP_rAccP_in);
      (void)Rte_Read_R_Cha_bABSReg_Cha_bABSReg(&GSI_Cha_bABSReg_in);
      (void)Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&GSI_Cha_stTqReq_in);
      (void)Rte_Read_R_CoPt_bRvsCord_CoPt_bRvsCord(&GSI_CoPt_bRvsCord_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&GSI_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_CoPt_posnLev_CoPt_posnLev(&GSI_CoPt_posnLev_in);
      (void)Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&GSI_CoPt_stCpl_in);
      (void)Rte_Read_R_CoPt_stDrvTra_CoPt_stDrvTra(&GSI_CoPt_stDrvTra_in);
      (void)Rte_Read_R_CoPt_stGSTyp_CoPt_stGSTyp(&GSI_CoPt_stGSTyp_in);
      (void)Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&GSI_TqSys_tqCkEngReal_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&GSI_CoPTSt_stEng_in);
      (void)Rte_Read_R_Ext_bBrkPedPrss_Ext_bBrkPedPrss(&GSI_Ext_bBrkPedPrss_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&GSI_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&GSI_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&GSI_Ext_tAir_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&GSI_Ext_tCoMes_in);
      (void)Rte_Read_R_TqDem_tqCkEfc_TqDem_tqCkEfc(&GSI_TqDem_tqCkEfc_in);
      (void)Rte_Read_R_TqSys_bAcvVehSpdCtlLim_TqSys_bAcvVehSpdCtlLim(&GSI_TqSys_bAcvVehSpdCtlLim_in);
      (void)Rte_Read_R_TqSys_bAcvVehSpdCtlReg_TqSys_bAcvVehSpdCtlReg(&GSI_TqSys_bAcvVehSpdCtlReg_in);
      (void)Rte_Read_R_AccP_bHdPtMon_AccP_bHdPtMon(&GSI_AccP_bHdPtMon_in);
      (void)Rte_Read_R_CoVSCtl_rAccPTra_CoVSCtl_rAccPTra(&GSI_CoVSCtl_rAccPTra_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&GSI_Veh_spdVeh_in);

      Rte_Call_R_FRM_bInhGSI3_GetFunctionPermission(&GSI_FRM_bInhGSI3_in);
      GSI_FRM_bInhGSI3_in = !GSI_FRM_bInhGSI3_in;
      GSI_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      GSI3_noEgdGearCordFilIt_out = GSI3_noEgdGearCordFilIt_B;
      GSI3_noTarGear_out = GSI3_noTarGear_B;
      GSI3_stGearShiftReq_out = GSI3_stGearShiftReq_B;
      GSI3_stGSIEna_out = GSI3_stGSIEna_B;
   }
   (void)Rte_Write_P_GSI3_noEgdGearCordFilIt_GSI3_noEgdGearCordFilIt(GSI3_noEgdGearCordFilIt_out);
   (void)Rte_Write_P_GSI3_noTarGear_GSI3_noTarGear(GSI3_noTarGear_out);
   (void)Rte_Write_P_GSI3_stGearShiftReq_GSI3_stGearShiftReq(GSI3_stGearShiftReq_out);
   (void)Rte_Write_P_GSI3_stGSIEna_GSI3_stGSIEna(GSI3_stGSIEna_out);

}

#define GSI_STOP_SEC_CODE
#include "GSI_MemMap.h"
#endif/*_GSI_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
