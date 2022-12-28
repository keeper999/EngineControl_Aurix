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
* %name: FARSp_022_TEV_fct.h %
*
* %version: 6.0.build1 %
*
* %date_modified: Wed Dec 19 11:24:27 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: FARSp_022_TEV_fct.h-6.0.build1:incl:5 %
*
*******************************************************************************/


#ifndef _FARSP_022_TEV_FCT_H_
#define _FARSP_022_TEV_FCT_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
extern UInt32 X_S02233_UnitDelay[2];extern UInt32 X_S02240_Unit_Delay2[2];extern
 Boolean X_S02234_UnitDelay[2];extern Boolean X_S02234_UnitDelay1;extern Boolean
 X_S02236_UnitDelay;extern Boolean X_S02239_UnitDelay;extern Boolean 
X_S02240_Unit_Delay1;
#define FARSP_START_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_Afts_rMixtReqRlamSpTest_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_Blby_facStiRich_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_EngM_rAirLdCor_in;extern 
AR_IF_GLOBAL_16BIT UInt16 FARSp_RE022_Ext_nEng_in;extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE022_FARSp_prm_rMixtGasFlexSp_in[24];extern AR_IF_GLOBAL_16BIT 
UInt16 FARSp_RE022_FARSp_rDeltaMixtStiTWCSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAgIgMinProtSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAstWupSTTSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtAutIgPrvtSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtBasSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtFullLdSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtLihSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtLoTqReqSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtMaxThermoProt_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtScvExAfs_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtSelCutOffSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtSpAntiStall_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtTWCHeatSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtTWCPurgeSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_FARSp_rMixtThermoProtSp_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_LsMon_rMixtReqMonItrsv_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_RE022_OxC_rMixtReqMonItrsv_in;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_prm_rMixtCylSp_out[6];extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtCylSpWiStiTWC_out;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtCylSpWoutStiBlby_out;extern AR_IF_GLOBAL_16BIT UInt16 
FARSp_rMixtCylSp_out;
#define FARSP_STOP_SEC_GLOBAL_16BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_8BIT UInt8 FARSp_RE022_FARSp_prm_facGasFlexSp_in[24];
#define FARSP_STOP_SEC_GLOBAL_8BIT
#include "FARSp_MemMap.h"
#define FARSP_START_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_Afts_bAcvRlamSpTest_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_Blby_bAcvStiRich_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvAflScvGDI_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvRatMixtTWCHeat_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvRichFullLd_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bAcvSelCutOffSpcMixt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bEnaAntiStall_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bInvldThermoProt_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bLihAcv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_FARSp_bThermoProtAuth_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_InjSys_bTotCutOff_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_InjSys_prm_bCylCutOff_in[6];extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_LsMon_bAcvReqMonItrsv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_RE022_OxC_bAcvReqMonItrsv_in;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bRichLoTqReqNotAuth_out;extern 
AR_IF_GLOBAL_BOOLEAN Boolean FARSp_bRichMixtAcv_out;extern AR_IF_GLOBAL_BOOLEAN 
Boolean FARSp_bRichScvThermoInvld_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bSatMaxRatMixt_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bSatMinRatMixt_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bStiBlbyNotAcv_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_bThermoProtReqNotAuth_out;extern AR_IF_GLOBAL_BOOLEAN Boolean 
FARSp_prm_bRlamSpAcv_out[20];
#define FARSP_STOP_SEC_GLOBAL_BOOLEAN
#include "FARSp_MemMap.h"
extern Void FARSp_021_MSE_ini(Void);extern Void FARSp_022_TEV_fct(Void);extern 
Void FARSp_022_FctVarInit(Void);
#endif

