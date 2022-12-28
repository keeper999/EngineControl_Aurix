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
* %name: FARSp_024_TEV_fct.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:55:04 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_024_TEV_fct.h-4.0.build1:incl:5 %
*
*******************************************************************************/


#ifndef _FARSP_024_TEV_FCT_H_
#define _FARSP_024_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT SInt16 FARSp_RE024_Ext_tCoMes_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_rMixtSpAntiStall_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE024_CoPt_noEgdGearCord_in;
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE024_IdlSys_bAcvAntiStall_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE024_IdlSys_bEnaAntiStall_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bDeacAntiStall_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bEnaAntiStall_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_023_MSE_ini(Void);extern Void FARSp_024_TEV_fct(Void);extern 
Void FARSp_024_FctVarInit(Void);
#endif

