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
* %name: PnmAct.h %
*
* %version: 0.1.build1 %
*
* %date_modified: Tue Dec 11 11:53:55 2012 %
*
*
* %derived_by: u329893 %
* %release: EB2DT/SC4 %
* %full_filespec: PnmAct.h-0.1.build1:incl:1 %
*
*******************************************************************************/

#ifndef _PNMACT_H_
#define _PNMACT_H_

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define PNMACT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "PnmAct_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PnmAct_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PnmAct_ModuleVersion_Minor_MP;
#define PNMACT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "PnmAct_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PNMACT_START_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean PNMACT_ACTIVE_BYP_C;
#define PNMACT_STOP_SEC_CALIB_BOOLEAN
#include "PnmAct_MemMap.h"

#define PNMACT_START_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT SInt16 PnmAct_rRCOCorReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 PnmAct_rOpTrbActEstim_B;
#define PNMACT_STOP_SEC_CALIB_16BIT
#include "PnmAct_MemMap.h"

#endif/*_PNMACT_H_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
