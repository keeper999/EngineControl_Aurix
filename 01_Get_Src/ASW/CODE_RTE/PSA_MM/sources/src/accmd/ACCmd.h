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
* %name: ACCmd.h %
*
* %version: 11.0.build1 %
*
* %date_modified: Tue Nov  8 11:24:46 2011 %
*
*
* %derived_by: e360487 %
* %release: TqStruct/10.1 %
* %full_filespec: ACCmd.h-11.0.build1:incl:5 %
*
*******************************************************************************/

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define ACCMD_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ACCmd_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ACCmd_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ACCmd_ModuleVersion_Minor_MP;
#define ACCMD_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ACCmd_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define ACCMD_START_SEC_CALIB_BOOLEAN
#include "ACCmd_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_002_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_003_DRE_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ACCMD_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ACCmd_bInhAntiStall_B;
#define ACCMD_STOP_SEC_CALIB_BOOLEAN
#include "ACCmd_MemMap.h"

#define ACCMD_START_SEC_CALIB_8BIT
#include "ACCmd_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 ACCmd_stReq_B;
#define ACCMD_STOP_SEC_CALIB_8BIT
#include "ACCmd_MemMap.h"

#define ACCMD_START_SEC_CALIB_16BIT
#include "ACCmd_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 ACCmd_nAntiStall_B;
#define ACCMD_STOP_SEC_CALIB_16BIT
#include "ACCmd_MemMap.h"

/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
