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
* %name: OilSys.h %
*
* %version: 4.0.build1 %
*
* %date_modified: Thu Oct  6 15:45:06 2011 %
*
*
* %derived_by: e360487 %
* %release: OilSys/4.0 %
* %full_filespec: OilSys.h-4.0.build1:incl:4 %
*
*******************************************************************************/

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define OILSYS_START_SEC_CONST_VERSION_MODULE_8BIT
#include "OilSys_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 OilSys_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 OilSys_ModuleVersion_Minor_MP;
#define OILSYS_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "OilSys_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define OILSYS_START_SEC_CALIB_BOOLEAN
#include "OilSys_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean OILSYS_ACTIVE_BYP_C;
#define OILSYS_STOP_SEC_CALIB_BOOLEAN
#include "OilSys_MemMap.h"

#define OILSYS_START_SEC_CALIB_8BIT
#include "OilSys_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 OilSys_stCtlTyp_B;
#define OILSYS_STOP_SEC_CALIB_8BIT
#include "OilSys_MemMap.h"

#define OILSYS_START_SEC_CALIB_16BIT
#include "OilSys_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 OilSys_pOilReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 OilSys_rCtlPmpReq_B;
#define OILSYS_STOP_SEC_CALIB_16BIT
#include "OilSys_MemMap.h"

/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
