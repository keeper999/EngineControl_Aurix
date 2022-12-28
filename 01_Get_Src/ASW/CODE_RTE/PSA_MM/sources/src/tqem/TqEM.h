/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : TqEM.h
* Description   : Interface AUTOSAR du module TqEM avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 15-Mar-2011(13:16:22)
*******************************************************************************/

#ifndef _TQEM_H_
#define _TQEM_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define TQEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqEM_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Build_MP;
#define TQEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqEM_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TQEM_START_SEC_CALIB_BOOLEAN
#include "TqEM_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TQEM_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TqEM_bFrzACComp_B;
#define TQEM_STOP_SEC_CALIB_BOOLEAN
#include "TqEM_MemMap.h"

#define TQEM_START_SEC_CALIB_16BIT
#include "TqEM_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT SInt16 TqEM_tqEM_B;
#define TQEM_STOP_SEC_CALIB_16BIT
#include "TqEM_MemMap.h"

#endif/*_TQEM_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

