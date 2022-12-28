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
* %name: TraBVx.h %
*
* %version: 13.0.build1 %
*
* %date_modified: Fri Jan  6 10:01:40 2012 %
*
*
* %derived_by: e360852 %
* %release: TqStruct/13.0 %
* %full_filespec: TraBVx.h-13.0.build1:incl:1 %
*
*******************************************************************************/
#include "tl_defines.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define TRABVX_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TraBVx_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TraBVx_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TraBVx_ModuleVersion_Minor_MP;
#define TRABVX_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TraBVx_MemMap.h"

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TRABVX_START_SEC_CALIB_BOOLEAN
#include "TraBVx_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean TRABVX_ACTIVE_BYP_C;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvDynTqResCrawl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvStatTqResCrawl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAuthCrawl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvIdlCrawl_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvNRegReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvSptTakeOff_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvWupMod_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bBrioUHAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bDiagSIPORng_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzAC_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzEGR_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzTrbSt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhEGR_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhRecup_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInjCutDynAuth3_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bPrepSIP_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bPrfModReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIP_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSmkFil_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTakeOff_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltFrzReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltGrdLimReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqTx_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_stDrvTra_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bDeacCllIt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvCll_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvNCross_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltFrzReq_nCross_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bEngCrawlAuth_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSpdVehLoDet_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvTqNCord_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhAC_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvCycMod_B;
#define TRABVX_STOP_SEC_CALIB_BOOLEAN
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_CALIB_8BIT
#include "TraBVx_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_idxPrfGBxMsg_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCrawl_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGBxMod_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGearRat_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_idxPtSpt_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noCylCutAuth_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noDrivFilTyp_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noEgdGear_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noTarGear_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_posnLev_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stClu_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCnvCluFil_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCpl_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stDragRed_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGSTyp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stVoltAltBoostReq_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_stVehDirEstim_B;
#define TRABVX_STOP_SEC_CALIB_8BIT
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_CALIB_16BIT
#include "TraBVx_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nMinTqMaxGBxMsg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMinGBxMsg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqReqClu_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_facAntiJerk_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nPrimShaft_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nTar_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nTrb_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_rCnvTq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tiDeacPrfMod_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tOilGBx_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirMaxGBx_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqCnvClu_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxClu_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBx_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBx_nReg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBxAir_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqCord_tqGBx_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvFil_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvRaw_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirDslCord_nReg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcCord_nRegReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tiTranCll_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcReqCord_nRegReq_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tqIncCll_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirDrvFil_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirCord_tqGBx_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirGslCord_nReg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirCord_nCross_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nPrimShaftTar_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqFfNReg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvRawTarGear_B;
#define TRABVX_STOP_SEC_CALIB_16BIT
#include "TraBVx_MemMap.h"

/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
