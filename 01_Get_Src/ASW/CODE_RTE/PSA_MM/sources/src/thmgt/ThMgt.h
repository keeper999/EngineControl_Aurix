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
* %name: ThMgt.h %
*
* %version: 12.1.build1 %
*
* %date_modified: Tue Oct 25 10:21:40 2011 %
*
*
* %derived_by: u380306 %
* %release: ThMgt/12.1 %
* %full_filespec: ThMgt.h-12.1.build1:incl:12 %
*
*******************************************************************************/

#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define THMGT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ThMgt_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ThMgt_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ThMgt_ModuleVersion_Minor_MP;
#define THMGT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define THMGT_START_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean THMGT_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bMainWaPmpSt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldAdFanReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldTrbWaPmpReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bACCmprOffReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvR1234Mgt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAdFanReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bBattFanReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bECTAftsReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bECUFanReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEHRHeatReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEHRWaPmpReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEndCtlCoVlv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bHeatWaPmpReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bHldPosnCoVlvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bMainWaPmpReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPosnFSF_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldCoVlvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldFSFReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldMainFanReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bRstrtReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bTCoWarnReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bTrbWaPmpReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bIncVoltReq_B;
#define THMGT_STOP_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rCoHeatReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rPwrECTReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpBypCoVlvReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpHeatCoVlvReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpRadCoVlvReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rSpdFanReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stPosnCoVlvEstim_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stPosnFSFReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stSpdCoVlvReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_tECTReq_B;
#define THMGT_STOP_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_nTarIdlHeatReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiAcvTrbWaPmpEngStop_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcLimReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_wThFil_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tCoReg_B;
#define THMGT_STOP_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
