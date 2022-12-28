/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : DfwCtl.h
* Description   : Interface AUTOSAR du module DfwCtl avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 18-Jan-2011(11:46:2)
*******************************************************************************/

#ifndef _DFWCTL_H_
#define _DFWCTL_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define DFWCTL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "DfwCtl_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 DfwCtl_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 DfwCtl_ModuleVersion_Minor_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 DfwCtl_ModuleVersion_Build_MP;
#define DFWCTL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "DfwCtl_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define DFWCTL_START_SEC_CALIB_BOOLEAN
#include "DfwCtl_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DFWCTL_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DfwCtl_bAcvLimTqIdl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DfwCtl_bInhInjProtDfw_B;
#define DFWCTL_STOP_SEC_CALIB_BOOLEAN
#include "DfwCtl_MemMap.h"

#define DFWCTL_START_SEC_CALIB_16BIT
#include "DfwCtl_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 DfwCtl_noOverOscDetProtAcv_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 DfwCtl_noProtAdp_B;
#define DFWCTL_STOP_SEC_CALIB_16BIT
#include "DfwCtl_MemMap.h"

#endif/*_DFWCTL_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

