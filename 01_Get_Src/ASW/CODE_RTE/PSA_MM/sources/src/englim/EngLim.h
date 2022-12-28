/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : EngLim.h
* Description   : Interface AUTOSAR du module EngLim avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 12-Aug-2010(9:55:6)
*******************************************************************************/

#ifndef _ENGLIM_H_
#define _ENGLIM_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define ENGLIM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "EngLim_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ENGLIM_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ENGLIM_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ENGLIM_ModuleVersion_Build_MP;
#define ENGLIM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "EngLim_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define ENGLIM_START_SEC_CALIB_BOOLEAN
#include "EngLim_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ENGLIM_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EngLim_bAcvCll_B;
#define ENGLIM_STOP_SEC_CALIB_BOOLEAN
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_CALIB_8BIT
#include "EngLim_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 EngLim_stLim_B;
#define ENGLIM_STOP_SEC_CALIB_8BIT
#include "EngLim_MemMap.h"

#define ENGLIM_START_SEC_CALIB_16BIT
#include "EngLim_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 EngLim_tiTranCll_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 EngLim_tqIncCll_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 EngLim_tqCkEfcStatLimIt_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 EngLim_tqCkEfcInrtLim_B;
#define ENGLIM_STOP_SEC_CALIB_16BIT
#include "EngLim_MemMap.h"

#endif/*_ENGLIM_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

