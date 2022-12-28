/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ASE.h
* Description   : Interface AUTOSAR du module ASE avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 23-May-2011(12:33:46)
*******************************************************************************/

#ifndef _ASE_H_
#define _ASE_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define ASE_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ASE_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Build_MP;
#define ASE_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define ASE_START_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_006_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_008_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_010_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_012_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bRstrtReqAvl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngCutOffReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngStallReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bAltRStrtTypASEReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bCdnInhRStrt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngRStrtTypASEReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bVSSNwAcvAuth_B;
#define ASE_STOP_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_8BIT
#include "ASE_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPtASE_stPwt_B;
#define ASE_STOP_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

#endif/*_ASE_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

