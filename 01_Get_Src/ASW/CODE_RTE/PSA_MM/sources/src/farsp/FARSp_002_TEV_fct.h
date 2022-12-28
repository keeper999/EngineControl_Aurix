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
* %name: FARSp_002_TEV_fct.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:46 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_002_TEV_fct.h-3.0:incl:5 %
*
*******************************************************************************/


#ifndef _FARSP_002_TEV_FCT_H_
#define _FARSP_002_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_EngM_mfAirCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_EngM_mfAirScvCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_EngM_rAirLdCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE002_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_rMixtBasSp_out;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtScvExAfs_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE002_Ext_stTypInjSysCf_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bAcvAflScvGDI_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_001_MSE_ini(Void);extern Void FARSp_002_TEV_fct(Void);extern 
Void FARSp_002_FctVarInit(Void);
#endif

