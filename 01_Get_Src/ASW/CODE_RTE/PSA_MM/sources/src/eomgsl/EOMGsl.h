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
* %name: EOMGsl.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Wed Aug 29 08:12:26 2012 %
*
*
* %derived_by: u391752 %
* %release: EPflex/Vf-1 %
* %full_filespec: EOMGsl.h-4.0.build1:incl:1 %
*
*******************************************************************************/

#ifndef _EOMGSL_H_
#define _EOMGSL_H_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define EOMGSL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "EOMGsl_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EOMGsl_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 EOMGsl_ModuleVersion_Minor_MP;
#define EOMGSL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "EOMGsl_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define EOMGSL_START_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOMGSL_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bSpcInjMod_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bTranMod_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean EOM_bTWCHeatPha_B;
#define EOMGSL_STOP_SEC_CALIB_BOOLEAN
#include "EOMGsl_MemMap.h"

#define EOMGSL_START_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facBasModCur_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facBasModTar_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_facTranMod_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas1ModCur_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas1ModTar_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas2ModCur_B[16];
extern AR_MERGEABLE_CALIB_8BIT UInt8 EOM_prm_idxBas2ModTar_B[16];
#define EOMGSL_STOP_SEC_CALIB_8BIT
#include "EOMGsl_MemMap.h"

#endif/*_EOMGSL_H_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
