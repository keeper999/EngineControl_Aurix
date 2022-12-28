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
* %name: FARSp_004_TEV_fct.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:48 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_004_TEV_fct.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_004_TEV_FCT_H_
#define _FARSP_004_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_EngM_mfTotExCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_ExM_tExStatAfs_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_FARSp_prm_rMixtGasFlexSp_in[24];extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_TPM_rMixtLimMaxAflScv_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE004_TPM_tExReq_in;extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_rMixtMaxThermoProt_out;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtThermoProtSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE004_ExM_stO2HcStgTWC_in;extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE004_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAcvRichProtOxdTWC_in;extern
 AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAcvRichThermoProt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bAirLdLimTExMgr_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE004_TPM_bRichLimScv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bInvldThermoProt_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bThermoProtAuth_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_003_MSE_ini(Void);extern Void FARSp_004_TEV_fct(Void);extern 
Void FARSp_004_FctVarInit(Void);
#endif

