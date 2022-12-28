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
* %name: FARSp_010_TEV_fct.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Fri May 25 16:54:55 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC2 %
* %full_filespec: FARSp_010_TEV_fct.h-4.0.build1:incl:4 %
*
*******************************************************************************/


#ifndef _FARSP_010_TEV_FCT_H_
#define _FARSP_010_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT SInt16 FARSp_RE010_CoHeat_tCoEstimStrt_in;extern 
AR_IF_GLOBAL_16BIT SInt16 FARSp_RE010_CoHeat_tCoEstim_in;extern 
AR_IF_GLOBAL_16BIT SInt16 FARSp_RE010_Ext_tCoMes_in;extern AR_IF_GLOBAL_16BIT 
SInt16 FARSp_RE010_Ext_tCoStrtMes_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE010_FARSp_prm_rMixtGasFlexSp_in[24];extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE010_InjSys_ctNbCmbAst_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtAstWupSTTSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_32BIT UInt32 FARSp_RE010_EOM_tiEngStopRst_in;extern 
AR_IF_GLOBAL_32BIT UInt32 FARSp_RE010_Ext_tiAst_in;
#define FARSP_STOP_SEC_GLOBAL_32BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE010_CoPTSt_tCoMesRStrtSTT_in;extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE010_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_CoHeat_bAcvHeatMgt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_CoPTSt_bRStrtSTT_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE010_FRM_bLihAstWupSTT_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_009_MSE_ini(Void);extern Void FARSp_010_TEV_fct(Void);extern 
Void FARSp_010_FctVarInit(Void);
#endif

