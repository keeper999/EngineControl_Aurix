/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoStopStart.h
* Description   : Interface AUTOSAR du module CoStopStart avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 24-Apr-2013(10:29:13)
*******************************************************************************/

#ifndef _COSTOPSTART_H_
#define _COSTOPSTART_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoStopStart_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 COSTOPSTART_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 COSTOPSTART_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 COSTOPSTART_ModuleVersion_Build_MP;
#define COSTOPSTART_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define COSTOPSTART_START_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_008_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_010_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_012_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_014_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_016_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_018_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_020_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_022_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_024_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_026_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_028_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_030_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COSTOPSTART_032_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltPrepRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltRPosnEngReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAltStallReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCdnInhRStrt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCompTqRStrt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseClsTra_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseLongGc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseRCfTyp3_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngCutOffReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngStopReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bFbSpcFactSTTReq1_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bFbSpcFactSTTReq2_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInfoAcvCluPed_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInfoRdy_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bLatchDrvCyc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRecNotStop_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtAnt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bStPresLo_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bSTTInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bOpDrvTraReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCtlDmprAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseAutRStrt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseElMecRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseNotRStrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseSpdMax_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseVehRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngStallReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bLimFreqStopInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtReqAvl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtReqDgoBlt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtTypAT_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bTestPrvtBltAcv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bVSSNwAcvAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bAuthSA_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bEngRStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bEngStopAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseDgoBlt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bCutCaseRStrtReqForc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bBltStopAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRStrtMchAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bStopAuthSlop_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bDrvTraOp_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bRstrtCritAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bEngRstrtClsCluCdn_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bInhHiSpdAltRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bNotBlsVehReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoReqRStrt_bRstrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtUH_bAcvGSINeut_B;
#define COSTOPSTART_STOP_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_noGearTmpBeg_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_noGearTmpEnd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stSTTLightAcv_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stPwt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stMaxRStrtReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stTypSTTNotAvl_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_tiCmplStop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stTestPosClu_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stAftsRStrtSuc_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stFbSpcFactRStrtSuc_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stBfLstRStrtFailCase_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stLstRStrtFailCase_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoReqRStrt_stRStrtTyp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_stBfBfLstRStrtFail_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtUH_pRelBrkAsi_B;
#define COSTOPSTART_STOP_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_nEngClc_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_rMaxCluGc_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_rMinCluRStrt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPtUH_tiNbRstrtFreqLim_B;
#define COSTOPSTART_STOP_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"

#endif/*_COSTOPSTART_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

