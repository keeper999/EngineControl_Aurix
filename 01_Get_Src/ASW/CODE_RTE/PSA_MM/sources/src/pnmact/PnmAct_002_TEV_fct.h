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
* %name: PnmAct_002_TEV_fct.h %
*
* %version: 1.0.build1 %
*
* %date_modified: Mon Jan  7 10:52:36 2013 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC4 %
* %full_filespec: PnmAct_002_TEV_fct.h-1.0.build1:incl:2 %
*
*******************************************************************************/


#ifndef _PNMACT_002_TEV_FCT_H_
#define _PNMACT_002_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define PNMACT_START_SEC_GLOBAL_16BIT
#include "PnmAct_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_ExM_pDsTrbEstimSI_in;extern 
AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_ExM_pExMnfEstim_in;extern 
AR_IF_GLOBAL_16BIT SInt16 PnmAct_RE002_TrbAct_pDifMaxPnmActReq_in;extern 
AR_IF_GLOBAL_16BIT SInt16 PnmAct_RE002_TrbAct_pDifTrbActReq_in;extern 
AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_TrbAct_rRCOReqRaw_in;extern 
AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_UsThrM_pAirExt_in;extern 
AR_IF_GLOBAL_16BIT UInt16 PnmAct_RE002_UsThrM_pUsCmpr_in;extern 
AR_IF_GLOBAL_16BIT UInt16 PnmAct_rOpTrbActEstim_out;extern AR_IF_GLOBAL_16BIT 
SInt16 PnmAct_rRCOCorReq_out;
#define PNMACT_STOP_SEC_GLOBAL_16BIT
#include "PnmAct_MemMap.h"
extern Void PnmAct_001_MSE_ini(Void);extern Void PnmAct_002_TEV_fct(Void);extern
 Void PnmAct_FctVarInit(Void);
#endif

