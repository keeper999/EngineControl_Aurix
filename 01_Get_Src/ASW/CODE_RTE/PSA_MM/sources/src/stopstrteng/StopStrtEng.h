/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : StopStrtEng.h
* Description   : Interface AUTOSAR du module StopStrtEng avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 06-Jun-2011(10:30:35)
*******************************************************************************/

#ifndef _STOPSTRTENG_H_
#define _STOPSTRTENG_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define STOPSTRTENG_START_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEng_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEng_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEng_ModuleVersion_Minor_MP;
#define STOPSTRTENG_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEng_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define STOPSTRTENG_START_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_006_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_008_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_010_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_012_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_014_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_016_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_018_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_020_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_022_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_024_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngRun_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngRunSTT_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngStop_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaRawAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaStopReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrtRStrt_bInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bMainEngStopReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrt_bStrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrtRStrt_bVSSNwAcvAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtSynt_bStopIp_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bChaTqAvl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bChaTqCrt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bEngStrtSuc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bTraCoplAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bTraTqAuthRaw_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaProt_B;
#define STOPSTRTENG_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPTSt_stEng_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StaCtl_stStaAuth_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stEngStrtReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stStopCutReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stAcvReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPTStNew_stEng_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPTStNew_stEngPrec_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPTSt_stDrvTra_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 StopStrtEng_stCdnNxtCkg_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtSynt_stPwt_B;
#define STOPSTRTENG_STOP_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"

#endif/*_STOPSTRTENG_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

