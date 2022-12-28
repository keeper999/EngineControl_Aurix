/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoEmSTT.h
* Description   : Interface AUTOSAR du module CoEmSTT avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 17-Nov-2010(10:0:26)
*******************************************************************************/

#ifndef _COEMSTT_H_
#define _COEMSTT_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COEMSTT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoEmSTT_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoEmSTT_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoEmSTT_ModuleVersion_Minor_MP;
#define COEMSTT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoEmSTT_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define COEMSTT_START_SEC_CALIB_BOOLEAN
#include "CoEmSTT_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COEMSTT_002_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bStaProt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bSTTWaitStrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bUcapUndVolt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSAcvSt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngRstrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngStopAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzStrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattPrf_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattProt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattUncrtSoC_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bEngStallAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltCritT_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngRstrtAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngStopAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzCrit_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bOverThdUcapBoost_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bUcapDchaAuth_B;
#define COEMSTT_STOP_SEC_CALIB_BOOLEAN
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_CALIB_8BIT
#include "CoEmSTT_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stUcapChSp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_uEmPredRstrt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_uUcapSp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_ctRstrtAcvTi_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_facSen_uEmPredRstrt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_iElNwStop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stBattEngRstrtReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stBattEngStopAuth_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stEngRStrtReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stEngStopAuth_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stTypEmPredRstrt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_tiVSSTmrStrtAuth_B;
#define COEMSTT_STOP_SEC_CALIB_8BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_CALIB_16BIT
#include "CoEmSTT_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdRstrtAuthSoCBatt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdStopAuthSoCBatt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdStopAuthSoCCf1_B;
#define COEMSTT_STOP_SEC_CALIB_16BIT
#include "CoEmSTT_MemMap.h"

#endif/*_COEMSTT_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

