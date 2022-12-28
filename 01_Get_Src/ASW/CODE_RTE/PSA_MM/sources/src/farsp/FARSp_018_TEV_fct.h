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
* %name: FARSp_018_TEV_fct.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:58 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_018_TEV_fct.h-3.0:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_018_TEV_FCT_H_
#define _FARSP_018_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE018_EngM_rAirLdCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE018_ExM_mO2StgCur_in;extern AR_IF_GLOBAL_16BIT
 UInt16 FARSp_RE018_ExM_mO2StgEngStop_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_FARSp_prm_rMixtGasFlexSp_in[24];extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE018_UsThrM_pAirExtEstim_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtTWCPurgeSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_32BIT UInt32 FARSp_RE018_Ext_tiAst_in;
#define FARSP_STOP_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE018_CoPTSt_tCoMesRStrtSTT_in;extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE018_Ext_uLsDsMes_in;extern AR_IF_GLOBAL_8BIT 
UInt8 FARSp_RE018_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE018_CoPTSt_bRStrtSTT_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE018_LsSys_bLsDsMainOxCHeatOk_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_017_MSE_ini(Void);extern Void FARSp_018_TEV_fct(Void);extern 
Void FARSp_018_FctVarInit(Void);
#endif

