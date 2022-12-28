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
* %name: GSI.h %
*
* %version: 13.0.build1 %
*
* %date_modified: Tue Oct 18 14:36:34 2011 %
*
*
* %derived_by: e360852 %
* %release: GSI/13.0 %
* %full_filespec: GSI.h-13.0.build1:incl:5 %
*
*******************************************************************************/

#ifndef _GSI_C_
#define _GSI_C_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define GSI_START_SEC_CONST_VERSION_MODULE_8BIT
#include "GSI_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 GSI_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 GSI_ModuleVersion_Minor_MP;
#define GSI_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "GSI_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define GSI_START_SEC_CALIB_BOOLEAN
#include "GSI_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean GSI_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean GSI3_stGSIEna_B;
#define GSI_STOP_SEC_CALIB_BOOLEAN
#include "GSI_MemMap.h"

#define GSI_START_SEC_CALIB_8BIT
#include "GSI_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_noEgdGearCordFilIt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_noTarGear_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 GSI3_stGearShiftReq_B;
#define GSI_STOP_SEC_CALIB_8BIT
#include "GSI_MemMap.h"

#endif/*_GSI_H_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
