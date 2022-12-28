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
* %name: FARSp_026_TEV_fct.h %
*
* %version: 5.0.build1 %
*
* %date_modified: Tue Aug  7 11:14:58 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_026_TEV_fct.h-5.0.build1:incl:2 %
*
*******************************************************************************/


#ifndef _FARSP_026_TEV_FCT_H_
#define _FARSP_026_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE026_EngM_rAirLdCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE026_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT 
SInt16 FARSp_RE026_Ext_tCoMes_in;extern AR_IF_GLOBAL_16BIT SInt16 
FARSp_RE026_Ext_tCoStrtMes_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE026_InjSys_ctNbCmbAst_in;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_AfuA_rEthWiExct_in;extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_CoPTSt_tCoMesRStrtSTT_in;extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_facBasModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_facBasModTar_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_facTranMod_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_idxBas1ModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_idxBas1ModTar_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_idxBas2ModCur_in[16];extern 
AR_IF_GLOBAL_8BIT UInt8 FARSp_RE026_EOM_prm_idxBas2ModTar_in[16];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE026_AfuA_bInvldEthRat_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE026_CoPTSt_bRStrtSTT_in;
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_025_MSE_ini(Void);extern Void FARSp_026_TEV_fct(Void);extern 
Void FARSp_RE026_FctVarInit(Void);
#endif

