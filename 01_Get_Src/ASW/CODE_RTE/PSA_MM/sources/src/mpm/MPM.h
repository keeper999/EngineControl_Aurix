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
* %name: MPM.h %
*
* %version: 2.0 %
*
* %date_modified: Fri Aug 10 08:27:45 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM.h-2.0:incl:1 %
*
*******************************************************************************/

#ifndef _MPM_H_
#define _MPM_H_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define MPM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "MPM_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 MPM_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 MPM_ModuleVersion_Minor_MP;
#define MPM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "MPM_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define MPM_START_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bLdLimReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bMPMInh_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bOvbStop_B;
#define MPM_STOP_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"

#define MPM_START_SEC_CALIB_16BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 MPM_facOvbReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 MPM_rLdMax_B;
#define MPM_STOP_SEC_CALIB_16BIT
#include "MPM_MemMap.h"

#endif/*_MPM_H_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
