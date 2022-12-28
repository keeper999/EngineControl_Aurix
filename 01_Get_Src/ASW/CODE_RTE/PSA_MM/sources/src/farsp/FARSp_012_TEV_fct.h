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
* %name: FARSp_012_TEV_fct.h %
*
* %version: 3.0 %
*
* %date_modified: Tue Feb  7 09:58:54 2012 %
*
*
* %derived_by: u391752 %
* %release: EB2DT/SC1 %
* %full_filespec: FARSp_012_TEV_fct.h-3.0:incl:3 %
*
*******************************************************************************/


#ifndef _FARSP_012_TEV_FCT_H_
#define _FARSP_012_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE012_EngM_rAirLdCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE012_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE012_FARSp_prm_rMixtGasFlexSp_in[24];extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_rMixtTWCHeatSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facBasModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facBasModTar_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_facTranMod_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_idxBas1ModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_idxBas1ModTar_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_idxBas2ModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_EOM_prm_idxBas2ModTar_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE012_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE012_EOM_bTWCHeatPha_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE012_TWCMgt_bLiOffDone_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bAcvRatMixtTWCHeat_out;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_011_MSE_ini(Void);extern Void FARSp_012_TEV_fct(Void);extern 
Void FARSp_012_FctVarInit(Void);
#endif

