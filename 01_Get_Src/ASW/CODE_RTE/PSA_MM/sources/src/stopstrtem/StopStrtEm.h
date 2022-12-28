/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : StopStrtEm.h
* Description   : Interface AUTOSAR du module StopStrtEm avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 22-December-2011(11:19:8)
*******************************************************************************/

#ifndef _STOPSTRTEM_H_
#define _STOPSTRTEM_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define STOPSTRTEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEm_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEm_ModuleVersion_Build_MP;
#define STOPSTRTEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEm_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define STOPSTRTEM_START_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_002_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTEM_006_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bDetSlowN_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bInfoCplReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bInfoCplSt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bReqAltBoostFil_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bRvAltPrepRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bRvAltRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bStaRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bStaStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bVldFastN_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmCkg_bWaitStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bPwrAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bStaReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoCplReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoCplSt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bInfoStaRun_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bStaReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bDftElCmd_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bProt10StopInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bRstrtProt4_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bStrtProt10_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaRstrtMgt_bRstrtProt10_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaStrtMgt_bDmgLimStopInh_B;
#define STOPSTRTEM_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stReqAltBoost_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stRstrtTyp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stStrtRstrtFbCmd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_stSTTCf_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_tiStaEgdHiThd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmCkg_tiStaEgdLoThd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_stStaStrtFbCmd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_stStaRstrtFbCmd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_tiStaEgdHiThd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaRstrtMgt_tiStaEgdLoThd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaStrtMgt_stStaFbCmd_B;
#define STOPSTRTEM_STOP_SEC_CALIB_8BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiStaAcvCnt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_nStaEgdHiThd_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmCkg_nStaEgdLoThd_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaRstrtMgt_nStaEgdHiThd_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaRstrtMgt_nStaEgdLoThd_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 StaStrtMgt_tiMaxAcv_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoEmCkg_nFast_B;
#define STOPSTRTEM_STOP_SEC_CALIB_16BIT
#include "StopStrtEm_MemMap.h"

#define STOPSTRTEM_START_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaAcv_B;
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaRstrtAcv_B;
extern AR_MERGEABLE_CALIB_32BIT UInt32 StaStrtMgt_ctStaStrtAcv_B;
#define STOPSTRTEM_STOP_SEC_CALIB_32BIT
#include "StopStrtEm_MemMap.h"

#endif/*_STOPSTRTEM_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

