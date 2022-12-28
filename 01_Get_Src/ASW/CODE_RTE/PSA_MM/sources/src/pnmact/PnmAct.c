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
* %name: PnmAct.c %
*
* %version: 1.0.build1 %
*
* %date_modified: Wed Jan  9 09:38:41 2013 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC4 %
* %full_filespec: PnmAct.c-1.0.build1:csrc:1 %
*
*******************************************************************************/

#ifndef _PNMACT_C_
#define _PNMACT_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_PnmAct.h"
#include "PnmAct.h"
#include "PnmAct_002_TEV_fct.h"
#include "PnmAct_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define PNMACT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "PnmAct_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PnmAct_ModuleVersion_Major_MP = 1;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PnmAct_ModuleVersion_Minor_MP = 0;
#define PNMACT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "PnmAct_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 5
#define Module_LIB_PSA_VERSION_REQ_MIN 5
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PNMACT_START_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean PNMACT_ACTIVE_BYP_C = 0;
#define PNMACT_STOP_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"

#define PNMACT_START_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"
AR_MERGEABLE_CALIB_16BIT SInt16 PnmAct_rRCOCorReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_rOpTrbActEstim_B = 65535;
#define PNMACT_STOP_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define PNMACT_START_SEC_CODE
#include "PnmAct_MemMap.h"
void RE_PnmAct_001_MSE(void)
{
   PnmAct_001_MSE_ini();

   (void)Rte_Write_P_PnmAct_rRCOCorReq_PnmAct_rRCOCorReq(0);
   (void)Rte_Write_P_PnmAct_rOpTrbActEstim_PnmAct_rOpTrbActEstim(65535);
}

void RE_PnmAct_002_TEV(void)
{
   if (FALSE == PNMACT_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_ExM_pDsTrbEstimSI_ExM_pDsTrbEstimSI(&PnmAct_RE002_ExM_pDsTrbEstimSI_in);
      (void)Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&PnmAct_RE002_ExM_pExMnfEstim_in);
      (void)Rte_Read_R_TrbAct_pDifMaxPnmActReq_TrbAct_pDifMaxPnmActReq(&PnmAct_RE002_TrbAct_pDifMaxPnmActReq_in);
      (void)Rte_Read_R_TrbAct_rRCOReqRaw_TrbAct_rRCOReqRaw(&PnmAct_RE002_TrbAct_rRCOReqRaw_in);
      (void)Rte_Read_R_UsThrM_pAirExt_UsThrM_pAirExt(&PnmAct_RE002_UsThrM_pAirExt_in);
      (void)Rte_Read_R_UsThrM_pUsCmpr_UsThrM_pUsCmpr(&PnmAct_RE002_UsThrM_pUsCmpr_in);
      (void)Rte_Read_R_TrbAct_pDifTrbActReq_TrbAct_pDifTrbActReq(&PnmAct_RE002_TrbAct_pDifTrbActReq_in);

      PnmAct_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      PnmAct_rRCOCorReq_out = PnmAct_rRCOCorReq_B;
      PnmAct_rOpTrbActEstim_out = PnmAct_rOpTrbActEstim_B;
   }
   (void)Rte_Write_P_PnmAct_rRCOCorReq_PnmAct_rRCOCorReq(PnmAct_rRCOCorReq_out);
   (void)Rte_Write_P_PnmAct_rOpTrbActEstim_PnmAct_rOpTrbActEstim(PnmAct_rOpTrbActEstim_out);
   
}

#define PNMACT_STOP_SEC_CODE
#include "PnmAct_MemMap.h"

#endif/*_PNMACT_C_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
