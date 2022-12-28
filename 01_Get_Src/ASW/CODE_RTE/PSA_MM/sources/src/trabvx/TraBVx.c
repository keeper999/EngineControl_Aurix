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
* %name: TraBVx.c %
*
* %version: 14.2.build1 %
*
* %date_modified: Tue Jun 25 14:06:35 2013 %
*
*
* %derived_by: u391752 %
* %release: TqStruct/14.0 %
* %full_filespec: TraBVx.c-14.2.build1:csrc:3 %
*
*******************************************************************************/

#ifndef _TRABVX_C_
#define _TRABVX_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_TraBVx.h"
#include "TraBVx.h"
#include "TraBVx_016_DRE_fct.h"
#include "TraBVx_018_DRE_fct.h"
#include "TraBVx_020_DRE_fct.h"
#include "TraBVx_028_TEV_fct.h"
#include "TraBVx_030_TEV_fct.h"
#include "TraBVx_032_TEV_fct.h"
#include "TraBVx_028_calibrations.h"
#include "TraBVx_030_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define TRABVX_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TraBVx_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TraBVx_ModuleVersion_Major_MP = 14;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TraBVx_ModuleVersion_Minor_MP = 2;
#define TRABVX_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TraBVx_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 5
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TRABVX_START_SEC_CALIB_BOOLEAN
#include "TraBVx_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean TRABVX_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvDynTqResCrawl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvStatTqResCrawl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAuthCrawl_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvIdlCrawl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvNRegReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvSptTakeOff_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvWupMod_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bBrioUHAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bDiagSIPORng_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzAC_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzEGR_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bFrzTrbSt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhEGR_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhRecup_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInjCutDynAuth3_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bPrepSIP_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bPrfModReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSIP_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSmkFil_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTakeOff_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltFrzReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltGrdLimReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqTx_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_stDrvTra_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bDeacCllIt_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvCll_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvNCross_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bTqAltFrzReq_nCross_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bEngCrawlAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bSpdVehLoDet_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvTqNCord_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bInhAC_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPt_bAcvCycMod_B = 1;
#define TRABVX_STOP_SEC_CALIB_BOOLEAN
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_CALIB_8BIT
#include "TraBVx_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_idxPrfGBxMsg_B = 128;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCrawl_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGBxMod_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGearRat_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_idxPtSpt_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noCylCutAuth_B = -1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_noDrivFilTyp_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noEgdGear_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_noTarGear_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_posnLev_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stClu_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCnvCluFil_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stCpl_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stDragRed_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stGSTyp_B = 5;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPt_stVoltAltBoostReq_B = 0;
AR_MERGEABLE_CALIB_8BIT SInt8 CoPt_stVehDirEstim_B = 0;
#define TRABVX_STOP_SEC_CALIB_8BIT
#include "TraBVx_MemMap.h"

#define TRABVX_START_SEC_CALIB_16BIT
#include "TraBVx_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nMinTqMaxGBxMsg_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMinGBxMsg_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqReqClu_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_facAntiJerk_B = 256;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nPrimShaft_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nTar_B = 3000;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nTrb_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_rCnvTq_B = 1;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tiDeacPrfMod_B = 1;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tOilGBx_B = 160;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirMaxGBx_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqCnvClu_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxClu_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBx_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBx_nReg_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqMaxGBxAir_B = 32000;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqCord_tqGBx_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvFil_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvRaw_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirDslCord_nReg_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcCord_nRegReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tiTranCll_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcReqCord_nRegReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_tqIncCll_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirDrvFil_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqAirCord_tqGBx_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirGslCord_nReg_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqIdcAirCord_nCross_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 CoPt_nPrimShaftTar_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqFfNReg_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoPt_tqDrvRawTarGear_B = 0;

#define TRABVX_STOP_SEC_CALIB_16BIT
#include "TraBVx_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define TRABVX_START_SEC_CODE
#include "TraBVx_MemMap.h"
void RE_TraBVx_001_MSE(void)
{
   TraBVx_028_MSE_ini();
   TraBVx_030_MSE_ini();
   TraBVx_016_MSE_ini();
   TraBVx_018_MSE_ini();
   TraBVx_020_MSE_ini();
   TraBVx_032_MSE_ini();

   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_tqIniNReg_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_nErrNReg_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_bVldAcvNReg_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_stPhaGS_irv(2);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_bInhNCross_irv(1);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_noTypPIDGain_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_tqGBxLossNReg_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_tqIdcNReg_irv(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_bDeacCllNReg_irv(1);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_tqReqGBx(0);
   (void)Rte_IrvWrite_RE_TraBVx_001_MSE_CoPt_tqAirReqGBx(0);
   (void)Rte_Write_P_CoPt_bAcvDynTqResCrawl_CoPt_bAcvDynTqResCrawl(0);
   (void)Rte_Write_P_CoPt_bAcvStatTqResCrawl_CoPt_bAcvStatTqResCrawl(0);
   (void)Rte_Write_P_CoPt_bAuthCrawl_CoPt_bAuthCrawl(1);
   (void)Rte_Write_P_CoPt_idxPrfGBxMsg_CoPt_idxPrfGBxMsg(128);
   (void)Rte_Write_P_CoPt_nMinTqMaxGBxMsg_CoPt_nMinTqMaxGBxMsg(0);
   (void)Rte_Write_P_CoPt_stCrawl_CoPt_stCrawl(0);
   (void)Rte_Write_P_CoPt_stGBxMod_CoPt_stGBxMod(0);
   (void)Rte_Write_P_CoPt_stGearRat_CoPt_stGearRat(0);
   (void)Rte_Write_P_CoPt_tqMinGBxMsg_CoPt_tqMinGBxMsg(0);
   (void)Rte_Write_P_CoPt_tqReqClu_CoPt_tqReqClu(0);
   (void)Rte_Write_P_CoPt_bAcvIdlCrawl_CoPt_bAcvIdlCrawl(0);
   (void)Rte_Write_P_CoPt_bAcvNRegReq_CoPt_bAcvNRegReq(0);
   (void)Rte_Write_P_CoPt_bAcvSptTakeOff_CoPt_bAcvSptTakeOff(0);
   (void)Rte_Write_P_CoPt_bAcvWupMod_CoPt_bAcvWupMod(1);
   (void)Rte_Write_P_CoPt_bBrioUHAuth_CoPt_bBrioUHAuth(0);
   (void)Rte_Write_P_CoPt_bDiagSIPORng_CoPt_bDiagSIPORng(0);
   (void)Rte_Write_P_CoPt_bFrzAC_CoPt_bFrzAC(0);
   (void)Rte_Write_P_CoPt_bFrzEGR_CoPt_bFrzEGR(0);
   (void)Rte_Write_P_CoPt_bFrzTrbSt_CoPt_bFrzTrbSt(0);
   (void)Rte_Write_P_CoPt_bInhEGR_CoPt_bInhEGR(0);
   (void)Rte_Write_P_CoPt_bInhRecup_CoPt_bInhRecup(0);
   (void)Rte_Write_P_CoPt_bInjCutDynAuth3_CoPt_bInjCutDynAuth3(1);
   (void)Rte_Write_P_CoPt_bPrepSIP_CoPt_bPrepSIP(0);
   (void)Rte_Write_P_CoPt_bPrfModReq_CoPt_bPrfModReq(0);
   (void)Rte_Write_P_CoPt_bSIP_CoPt_bSIP(0);
   (void)Rte_Write_P_CoPt_bSmkFil_CoPt_bSmkFil(0);
   (void)Rte_Write_P_CoPt_bTakeOff_CoPt_bTakeOff(0);
   (void)Rte_Write_P_CoPt_bTqAltFrzReq_CoPt_bTqAltFrzReq(0);
   (void)Rte_Write_P_CoPt_bTqAltGrdLimReq_CoPt_bTqAltGrdLimReq(0);
   (void)Rte_Write_P_CoPt_bTqTx_CoPt_bTqTx(0);
   (void)Rte_Write_P_CoPt_facAntiJerk_CoPt_facAntiJerk(256);
   (void)Rte_Write_P_CoPt_idxPtSpt_CoPt_idxPtSpt(0);
   (void)Rte_Write_P_CoPt_noCylCutAuth_CoPt_noCylCutAuth(-1);
   (void)Rte_Write_P_CoPt_noDrivFilTyp_CoPt_noDrivFilTyp(0);
   (void)Rte_Write_P_CoPt_noEgdGear_CoPt_noEgdGear(0);
   (void)Rte_Write_P_CoPt_noTarGear_CoPt_noTarGear(0);
   (void)Rte_Write_P_CoPt_nPrimShaft_CoPt_nPrimShaft(0);
   (void)Rte_Write_P_CoPt_nTar_CoPt_nTar(3000);
   (void)Rte_Write_P_CoPt_nTrb_CoPt_nTrb(0);
   (void)Rte_Write_P_CoPt_posnLev_CoPt_posnLev(0);
   (void)Rte_Write_P_CoPt_rCnvTq_CoPt_rCnvTq(1);
   (void)Rte_Write_P_CoPt_stClu_CoPt_stClu(0);
   (void)Rte_Write_P_CoPt_stCnvCluFil_CoPt_stCnvCluFil(0);
   (void)Rte_Write_P_CoPt_stCpl_CoPt_stCpl(0);
   (void)Rte_Write_P_CoPt_stDragRed_CoPt_stDragRed(0);
   (void)Rte_Write_P_CoPt_stDrvTra_CoPt_stDrvTra(0);
   (void)Rte_Write_P_CoPt_stGSTyp_CoPt_stGSTyp(5);
   (void)Rte_Write_P_CoPt_tiDeacPrfMod_CoPt_tiDeacPrfMod(1);
   (void)Rte_Write_P_CoPt_tOilGBx_CoPt_tOilGBx(160);
   (void)Rte_Write_P_CoPt_tqAirMaxGBx_CoPt_tqAirMaxGBx(32000);
   (void)Rte_Write_P_CoPt_tqCnvClu_CoPt_tqCnvClu(0);
   (void)Rte_Write_P_CoPt_tqMaxClu_CoPt_tqMaxClu(0);
   (void)Rte_Write_P_CoPt_tqMaxGBx_CoPt_tqMaxGBx(32000);
   (void)Rte_Write_P_CoPt_tqMaxGBx_nReg_CoPt_tqMaxGBx_nReg(32000);
   (void)Rte_Write_P_CoPt_tqMaxGBxAir_CoPt_tqMaxGBxAir(32000);
   (void)Rte_Write_P_CoPt_bDeacCllIt_CoPt_bDeacCllIt(1);
   (void)Rte_Write_P_CoPt_tqCord_tqGBx_CoPt_tqCord_tqGBx(0);
   (void)Rte_Write_P_CoPt_tqDrvFil_CoPt_tqDrvFil(0);
   (void)Rte_Write_P_CoPt_tqDrvRaw_CoPt_tqDrvRaw(0);
   (void)Rte_Write_P_CoPt_tqIdcAirDslCord_nReg_CoPt_tqIdcAirDslCord_nReg(0);
   (void)Rte_Write_P_CoPt_tqIdcCord_nRegReq_CoPt_tqIdcCord_nRegReq(0);
   (void)Rte_Write_P_CoPt_bAcvCll_CoPt_bAcvCll(0);
   (void)Rte_Write_P_CoPt_bAcvNCross_CoPt_bAcvNCross(0);
   (void)Rte_Write_P_CoPt_bTqAltFrzReq_nCross_CoPt_bTqAltFrzReq_nCross(0);
   (void)Rte_Write_P_CoPt_tiTranCll_CoPt_tiTranCll(0);
   (void)Rte_Write_P_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(0);
   (void)Rte_Write_P_CoPt_tqIncCll_CoPt_tqIncCll(0);
   (void)Rte_Write_P_CoPt_tqAirDrvFil_CoPt_tqAirDrvFil(0);
   (void)Rte_Write_P_CoPt_tqAirCord_tqGBx_CoPt_tqAirCord_tqGBx(0);
   (void)Rte_Write_P_CoPt_tqIdcAirGslCord_nReg_CoPt_tqIdcAirGslCord_nReg(0);
   (void)Rte_Write_P_CoPt_tqIdcAirCord_nCross_CoPt_tqIdcAirCord_nCross(0);
   (void)Rte_Write_P_CoPt_stVoltAltBoostReq_CoPt_stVoltAltBoostReq(0);
   (void)Rte_Write_P_CoPt_nPrimShaftTar_CoPt_nPrimShaftTar(0);
   (void)Rte_Write_P_CoPt_tqFfNReg_CoPt_tqFfNReg(0);
   (void)Rte_Write_P_CoPt_bEngCrawlAuth_CoPt_bEngCrawlAuth(0);
   (void)Rte_Write_P_CoPt_stVehDirEstim_CoPt_stVehDirEstim(0);
   (void)Rte_Write_P_CoPt_bSpdVehLoDet_CoPt_bSpdVehLoDet(1);
   (void)Rte_Write_P_CoPt_bAcvTqNCord_CoPt_bAcvTqNCord(0);
   (void)Rte_Write_P_CoPt_tqDrvRawTarGear_CoPt_tqDrvRawTarGear(0);
   (void)Rte_Write_P_CoPt_bInhAC_CoPt_bInhAC(0);
   (void)Rte_Write_P_CoPt_bAcvCycMod_CoPt_bAcvCycMod(1);

}

void RE_TraBVx_016_DRE(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TraBVx_016_Ext_nEng_in);
      (void)Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&TraBVx_016_TqCmp_tqSumLossCmp_in);
      (void)Rte_Read_R_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(&TraBVx_016_EngLim_tqEfcMaxNReg_in);
      (void)Rte_Read_R_TqSys_tqEfcIdl_TqSys_tqEfcIdl(&TraBVx_016_TqSys_tqEfcIdl_in);
      (void)Rte_Read_R_CoPt_bAcvNRegReqBuf_CoPt_bAcvNRegReqBuf(&TraBVx_016_CoPt_bAcvNRegReqBuf_in);
      (void)Rte_Read_R_CoPt_noTarGearCordBuf_CoPt_noTarGearCordBuf(&TraBVx_016_CoPt_noTarGearCordBuf_in);
      (void)Rte_Read_R_CoPt_nTarBuf_CoPt_nTarBuf(&TraBVx_016_CoPt_nTarBuf_in);
      (void)Rte_Read_R_CoPt_tqMaxGBx_nRegBuf_CoPt_tqMaxGBx_nRegBuf(&TraBVx_016_CoPt_tqMaxGBx_nRegBuf_in);
      (void)Rte_Read_R_TqSys_bTqSysAcv_TqSys_bTqSysAcv(&TraBVx_016_TqSys_bTqSysAcv_in);
//      (void)Rte_Read_R_TqSys_EveSync_CoPtNReg_TqSys_EveSync_CoPtNReg(&TraBVx_016_TqSys_EveSync_CoPtNReg_in);
      (void)Rte_Read_R_CoPt_tqFfNRegBuf_CoPt_tqFfNRegBuf(&TraBVx_016_CoPt_tqFfNRegBuf_in);
      Re_TraBVx_016_DRE_CoPt_tqIniNReg_irv_in = Rte_IrvRead_RE_TraBVx_016_DRE_CoPt_tqIniNReg_irv();
      Re_TraBVx_016_DRE_CoPt_nErrNReg_irv_in = Rte_IrvRead_RE_TraBVx_016_DRE_CoPt_nErrNReg_irv();
      Re_TraBVx_016_DRE_CoPt_noTypPIDGain_irv_in = Rte_IrvRead_RE_TraBVx_016_DRE_CoPt_noTypPIDGain_irv();
      Re_TraBVx_016_DRE_CoPt_tqGBxLossNReg_irv_in = Rte_IrvRead_RE_TraBVx_016_DRE_CoPt_tqGBxLossNReg_irv();

      TraBVx_016_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_TraBVx_016_DRE_CoPt_bVldAcvNReg_irv(Re_TraBVx_016_DRE_CoPt_bVldAcvNReg_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_016_DRE_CoPt_tqIdcNReg_irv(Re_TraBVx_016_DRE_CoPt_tqIdcNReg_irv_out);

}

void RE_TraBVx_018_DRE(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TraBVx_018_Ext_nEng_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TraBVx_018_TqSys_bTypFu_in);
      (void)Rte_Read_R_CoPt_bAcvNRegReqBuf_CoPt_bAcvNRegReqBuf(&TraBVx_018_CoPt_bAcvNRegReqBuf_in);
      (void)Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&TraBVx_018_Cha_stTqReq_in);
      (void)Rte_Read_R_CoPt_bSIPBuf_CoPt_bSIPBuf(&TraBVx_018_CoPt_bSIPBuf_in);
      (void)Rte_Read_R_CoPt_tqIdcCordLimBuf_tqGBx_CoPt_tqIdcCordLimBuf_tqGBx(&TraBVx_018_CoPt_tqIdcCordLimBuf_tqGBx_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&TraBVx_018_Ext_tiTDC_in);
      (void)Rte_Read_R_TqLimEM_tqIdcLimEM_TqLimEM_tqIdcLimEM(&TraBVx_018_TqLimEM_tqIdcLimEM_in);
      (void)Rte_Read_R_TqSys_bInjCutDynReq_TqSys_bInjCutDynReq(&TraBVx_018_TqSys_bInjCutDynReq_in);
//      (void)Rte_Read_R_TqSys_EveSync_CoPtNRegCord_TqSys_EveSync_CoPtNRegCord(&TraBVx_018_TqSys_EveSync_CoPtNRegCord_in);
      (void)Rte_Read_R_CoPt_bAcvTqNCordBuf_CoPt_bAcvTqNCordBuf(&TraBVx_018_CoPt_bAcvTqNCordBuf_in);
      (void)Rte_Read_R_CoVSCtl_tqIdcSIPTar_CoVSCtl_tqIdcSIPTar(&TraBVx_018_CoVSCtl_tqIdcSIPTar_in);
      Re_TraBVx_018_DRE_CoPt_tqIdcNReg_irv_in = Rte_IrvRead_RE_TraBVx_018_DRE_CoPt_tqIdcNReg_irv();

      TraBVx_018_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      CoPt_tqIdcAirDslCord_nReg_out = CoPt_tqIdcAirDslCord_nReg_B;
      CoPt_tqIdcCord_nRegReq_out = CoPt_tqIdcCord_nRegReq_B;
   }
   (void)Rte_IrvWrite_RE_TraBVx_018_DRE_CoPt_bDeacCllNReg_irv(Re_TraBVx_018_DRE_CoPt_bDeacCllNReg_irv_out);
   (void)Rte_Write_P_CoPt_tqIdcAirDslCord_nReg_CoPt_tqIdcAirDslCord_nReg(CoPt_tqIdcAirDslCord_nReg_out);
   (void)Rte_Write_P_CoPt_tqIdcCord_nRegReq_CoPt_tqIdcCord_nRegReq(CoPt_tqIdcCord_nRegReq_out);

}

void RE_TraBVx_020_DRE(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TraBVx_020_Ext_nEng_in);
      (void)Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&TraBVx_020_TqCmp_tqSumLossCmp_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&TraBVx_020_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&TraBVx_020_CoVSCtl_rAccPEngTrv_in);
      (void)Rte_Read_R_CoPt_bAcvNRegReqBuf_CoPt_bAcvNRegReqBuf(&TraBVx_020_CoPt_bAcvNRegReqBuf_in);
      (void)Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&TraBVx_020_Cha_stTqReq_in);
      (void)Rte_Read_R_CoPt_bSIPBuf_CoPt_bSIPBuf(&TraBVx_020_CoPt_bSIPBuf_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&TraBVx_020_Ext_tiTDC_in);
      (void)Rte_Read_R_CoPt_bDeacCllBuf_CoPt_bDeacCllBuf(&TraBVx_020_CoPt_bDeacCllBuf_in);
      (void)Rte_Read_R_CoPt_bPrepSIP_CoPt_bPrepSIP(&TraBVx_020_CoPt_bPrepSIP_in);
      (void)Rte_Read_R_CoPt_nTrb_CoPt_nTrb(&TraBVx_020_CoPt_nTrb_in);
      (void)Rte_Read_R_CoPt_tqDrvFil_CoPt_tqDrvFil(&TraBVx_020_CoPt_tqDrvFil_in);
      (void)Rte_Read_R_CoPt_tqDrvRaw_CoPt_tqDrvRaw(&TraBVx_020_CoPt_tqDrvRaw_in);
      (void)Rte_Read_R_CoPt_tqIdcCord_nRegReq_CoPt_tqIdcCord_nRegReq(&TraBVx_020_CoPt_tqIdcCord_nRegReq_in);
      (void)Rte_Read_R_CoPt_tqIdcMaxGBxBuf_CoPt_tqIdcMaxGBxBuf(&TraBVx_020_CoPt_tqIdcMaxGBxBuf_in);
      (void)Rte_Read_R_CoPt_tqMaxGBx_CoPt_tqMaxGBx(&TraBVx_020_CoPt_tqMaxGBx_in);
//      (void)Rte_Read_R_TqSys_EveSync_CoPtNCross_TqSys_EveSync_CoPtNCross(&TraBVx_020_TqSys_EveSync_CoPtNCross_in);
      (void)Rte_Read_R_TqSys_idxTqAccu_TqSys_idxTqAccu(&TraBVx_020_TqSys_idxTqAccu_in);
      (void)Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&TraBVx_020_TreatTDC_nCkGrd_in);
      (void)Rte_Read_R_CoPt_bAcvTqNCordBuf_CoPt_bAcvTqNCordBuf(&TraBVx_020_CoPt_bAcvTqNCordBuf_in);
      Re_TraBVx_020_DRE_CoPt_bInhNCross_irv_in = Rte_IrvRead_RE_TraBVx_020_DRE_CoPt_bInhNCross_irv();
      Re_TraBVx_020_DRE_CoPt_bDeacCllNReg_irv_in = Rte_IrvRead_RE_TraBVx_020_DRE_CoPt_bDeacCllNReg_irv();

      TraBVx_020_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      CoPt_bAcvCll_out = CoPt_bAcvCll_B;
      CoPt_bAcvNCross_out = CoPt_bAcvNCross_B;
      CoPt_bTqAltFrzReq_nCross_out = CoPt_bTqAltFrzReq_nCross_B;
      CoPt_tiTranCll_out = CoPt_tiTranCll_B;
      CoPt_tqIdcReqCord_nRegReq_out = CoPt_tqIdcReqCord_nRegReq_B;
      CoPt_tqIncCll_out = CoPt_tqIncCll_B;
   }
   (void)Rte_Write_P_CoPt_bAcvCll_CoPt_bAcvCll(CoPt_bAcvCll_out);
   (void)Rte_Write_P_CoPt_bAcvNCross_CoPt_bAcvNCross(CoPt_bAcvNCross_out);
   (void)Rte_Write_P_CoPt_bTqAltFrzReq_nCross_CoPt_bTqAltFrzReq_nCross(CoPt_bTqAltFrzReq_nCross_out);
   (void)Rte_Write_P_CoPt_tiTranCll_CoPt_tiTranCll(CoPt_tiTranCll_out);
   (void)Rte_Write_P_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(CoPt_tqIdcReqCord_nRegReq_out);
   (void)Rte_Write_P_CoPt_tqIncCll_CoPt_tqIncCll(CoPt_tqIncCll_out);

}

void RE_TraBVx_028_TEV(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TraBVx_028_Ext_nEng_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&TraBVx_028_Ext_posnGBxLev_in);
      (void)Rte_Read_R_InjSys_bFuCutOff_InjSys_bFuCutOff(&TraBVx_028_InjSys_bFuCutOff_in);
      (void)Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&TraBVx_028_TqCmp_tqSumLossCmp_in);
      (void)Rte_Read_R_TqSys_bAcvCllIt_TqSys_bAcvCllIt(&TraBVx_028_TqSys_bAcvCllIt_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TraBVx_028_TqSys_bTypFu_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&TraBVx_028_TqSys_nTarIdl_in);
      (void)Rte_Read_R_Tra_bFrzAC_Tra_bFrzAC(&TraBVx_028_Tra_bFrzAC_in);
      (void)Rte_Read_R_Tra_bNRegReq_Tra_bNRegReq(&TraBVx_028_Tra_bNRegReq_in);
      (void)Rte_Read_R_Tra_bSIP_Tra_bSIP(&TraBVx_028_Tra_bSIP_in);
      (void)Rte_Read_R_Tra_bTqTx_Tra_bTqTx(&TraBVx_028_Tra_bTqTx_in);
      (void)Rte_Read_R_Tra_idxPtSpt_Tra_idxPtSpt(&TraBVx_028_Tra_idxPtSpt_in);
      (void)Rte_Read_R_Tra_noEgdGear_Tra_noEgdGear(&TraBVx_028_Tra_noEgdGear_in);
      (void)Rte_Read_R_Tra_noTarGear_Tra_noTarGear(&TraBVx_028_Tra_noTarGear_in);
      (void)Rte_Read_R_Tra_nTar_Tra_nTar(&TraBVx_028_Tra_nTar_in);
      (void)Rte_Read_R_Tra_nTrb_Tra_nTrb(&TraBVx_028_Tra_nTrb_in);
      (void)Rte_Read_R_Tra_rCnvTq_Tra_rCnvTq(&TraBVx_028_Tra_rCnvTq_in);
      (void)Rte_Read_R_Tra_stCnvClu_Tra_stCnvClu(&TraBVx_028_Tra_stCnvClu_in);
      (void)Rte_Read_R_Tra_stCpl_Tra_stCpl(&TraBVx_028_Tra_stCpl_in);
      (void)Rte_Read_R_Tra_stDragRed_Tra_stDragRed(&TraBVx_028_Tra_stDragRed_in);
      (void)Rte_Read_R_Tra_stGBxMod_Tra_stGBxMod(&TraBVx_028_Tra_stGBxMod_in);
      (void)Rte_Read_R_Tra_stGearRat_Tra_stGearRat(&TraBVx_028_Tra_stGearRat_in);
      (void)Rte_Read_R_Tra_stGSTyp_Tra_stGSTyp(&TraBVx_028_Tra_stGSTyp_in);
      (void)Rte_Read_R_Tra_tqCnvClu_Tra_tqCnvClu(&TraBVx_028_Tra_tqCnvClu_in);
      (void)Rte_Read_R_Tra_tqMaxGBx_Tra_tqMaxGBx(&TraBVx_028_Tra_tqMaxGBx_in);
      (void)Rte_Read_R_Tra_tqReqGBx_Tra_tqReqGBx(&TraBVx_028_Tra_tqReqGBx_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&TraBVx_028_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_CoCha_tqEfcAirReq_CoCha_tqEfcAirReq(&TraBVx_028_CoCha_tqEfcAirReq_in);
      (void)Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&TraBVx_028_CoVSCtl_rAccPEngTrv_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&TraBVx_028_Ext_pAirExtMes_in);
      (void)Rte_Read_R_Tra_nPrimShaft_Tra_nPrimShaft(&TraBVx_028_Tra_nPrimShaft_in);
      (void)Rte_Read_R_Tra_stClu_Tra_stClu(&TraBVx_028_Tra_stClu_in);
      (void)Rte_Read_R_Tra_stCrawl_Tra_stCrawl(&TraBVx_028_Tra_stCrawl_in);
      (void)Rte_Read_R_Tra_tqMaxClu_Tra_tqMaxClu(&TraBVx_028_Tra_tqMaxClu_in);
      (void)Rte_Read_R_Tra_tqReqClu_Tra_tqReqClu(&TraBVx_028_Tra_tqReqClu_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&TraBVx_028_Veh_spdVeh_in);
      (void)Rte_Read_R_Tra_bNRegTyp_Tra_bNRegTyp(&TraBVx_028_Tra_bNRegTyp_in);
      (void)Rte_Read_R_CoPt_facAntiJerkExt_CoPt_facAntiJerkExt(&TraBVx_028_CoPt_facAntiJerkExt_in);
      (void)Rte_Read_R_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(&TraBVx_028_EngLim_tqEfcMaxNReg_in);
      (void)Rte_Read_R_EngLim_tqEfcMinCurCutOffTrv_EngLim_tqEfcMinCurCutOffTrv(&TraBVx_028_EngLim_tqEfcMinCurCutOffTrv_in);
      (void)Rte_Read_R_EngLim_tqEfcMinCurTrv_EngLim_tqEfcMinCurTrv(&TraBVx_028_EngLim_tqEfcMinCurTrv_in);
      (void)Rte_Read_R_EngLim_tqEfcNRegTakeOffLim_EngLim_tqEfcNRegTakeOffLim(&TraBVx_028_EngLim_tqEfcNRegTakeOffLim_in);
      (void)Rte_Read_R_EOM_bTWCHeatPha_EOM_bTWCHeatPha(&TraBVx_028_EOM_bTWCHeatPha_in);
      (void)Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&TraBVx_028_EOM_tiEngRun_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&TraBVx_028_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&TraBVx_028_Ext_stTraTypCf_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&TraBVx_028_Ext_tAir_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&TraBVx_028_Ext_tCoMes_in);
      (void)Rte_Read_R_TqSys_bAcvOvbReq_TqSys_bAcvOvbReq(&TraBVx_028_TqSys_bAcvOvbReq_in);
      (void)Rte_Read_R_TqSys_stTypPwtCf_TqSys_stTypPwtCf(&TraBVx_028_TqSys_stTypPwtCf_in);
      (void)Rte_Read_R_TqSys_tiDeacOvbReq_TqSys_tiDeacOvbReq(&TraBVx_028_TqSys_tiDeacOvbReq_in);
      (void)Rte_Read_R_TqSys_tqEfcIdl_TqSys_tqEfcIdl(&TraBVx_028_TqSys_tqEfcIdl_in);
      (void)Rte_Read_R_CoPtUH_bRStrtTypAT_CoPtUH_bRStrtTypAT(&TraBVx_028_CoPtUH_bRStrtTypAT_in);
      (void)Rte_Read_R_Tra_bSIPPrep_Tra_bSIPPrep(&TraBVx_028_Tra_bSIPPrep_in);
      (void)Rte_Read_R_Tra_stPhaGearShift_Tra_stPhaGearShift(&TraBVx_028_Tra_stPhaGearShift_in);
      (void)Rte_Read_R_TqSys_stStrtEngTyp_TqSys_stStrtEngTyp(&TraBVx_028_TqSys_stStrtEngTyp_in);
      (void)Rte_Read_R_Ext_tOilGBx_Ext_tOilGBx(&TraBVx_028_Ext_tOilGBx_in);
      (void)Rte_Read_R_Tra_bVoltAltBoostReqGBx_Tra_bVoltAltBoostReqGBx(&TraBVx_028_Tra_bVoltAltBoostReqGBx_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&TraBVx_028_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_Tra_bEngCrawlAuth_Tra_bEngCrawlAuth(&TraBVx_028_Tra_bEngCrawlAuth_in);
      (void)Rte_Read_R_Tra_bSpdVehLoDet_Tra_bSpdVehLoDet(&TraBVx_028_Tra_bSpdVehLoDet_in);
      (void)Rte_Read_R_Tra_stVehDirEstim_Tra_stVehDirEstim(&TraBVx_028_Tra_stVehDirEstim_in);
	  (void)Rte_Read_R_CoVSCtl_tqSIPTar_CoVSCtl_tqSIPTar(&TraBVx_028_CoVSCtl_tqSIPTar_in);
	  (void)Rte_Read_R_Tra_bInhAC_Tra_bInhAC(&TraBVx_028_Tra_bInhAC_in);

      Rte_Call_R_FRM_bInhCoPtSIP_GetFunctionPermission(&TraBVx_028_FRM_bInhCoPtSIP_in);
      TraBVx_028_FRM_bInhCoPtSIP_in = !TraBVx_028_FRM_bInhCoPtSIP_in;
      Rte_Call_R_FRM_bInhCoPtCrawl_GetFunctionPermission(&TraBVx_028_FRM_bInhCoPtCrawl_in);
      TraBVx_028_FRM_bInhCoPtCrawl_in = !TraBVx_028_FRM_bInhCoPtCrawl_in;
      TraBVx_028_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      CoPt_bAcvDynTqResCrawl_out = CoPt_bAcvDynTqResCrawl_B;
      CoPt_bAcvStatTqResCrawl_out = CoPt_bAcvStatTqResCrawl_B;
      CoPt_bAuthCrawl_out = CoPt_bAuthCrawl_B;
      CoPt_idxPrfGBxMsg_out = CoPt_idxPrfGBxMsg_B;
      CoPt_nMinTqMaxGBxMsg_out = CoPt_nMinTqMaxGBxMsg_B;
      CoPt_stCrawl_out = CoPt_stCrawl_B;
      CoPt_stGBxMod_out = CoPt_stGBxMod_B;
      CoPt_stGearRat_out = CoPt_stGearRat_B;
      CoPt_tqMinGBxMsg_out = CoPt_tqMinGBxMsg_B;
      CoPt_tqReqClu_out = CoPt_tqReqClu_B;
      CoPt_bAcvIdlCrawl_out = CoPt_bAcvIdlCrawl_B;
      CoPt_bAcvNRegReq_out = CoPt_bAcvNRegReq_B;
      CoPt_bAcvSptTakeOff_out = CoPt_bAcvSptTakeOff_B;
      CoPt_bAcvWupMod_out = CoPt_bAcvWupMod_B;
      CoPt_bBrioUHAuth_out = CoPt_bBrioUHAuth_B;
      CoPt_bDiagSIPORng_out = CoPt_bDiagSIPORng_B;
      CoPt_bFrzAC_out = CoPt_bFrzAC_B;
      CoPt_bFrzEGR_out = CoPt_bFrzEGR_B;
      CoPt_bFrzTrbSt_out = CoPt_bFrzTrbSt_B;
      CoPt_bInhEGR_out = CoPt_bInhEGR_B;
      CoPt_bInhRecup_out = CoPt_bInhRecup_B;
      CoPt_bInjCutDynAuth3_out = CoPt_bInjCutDynAuth3_B;
      CoPt_bPrepSIP_out = CoPt_bPrepSIP_B;
      CoPt_bPrfModReq_out = CoPt_bPrfModReq_B;
      CoPt_bSIP_out = CoPt_bSIP_B;
      CoPt_bSmkFil_out = CoPt_bSmkFil_B;
      CoPt_bTakeOff_out = CoPt_bTakeOff_B;
      CoPt_bTqAltFrzReq_out = CoPt_bTqAltFrzReq_B;
      CoPt_bTqAltGrdLimReq_out = CoPt_bTqAltGrdLimReq_B;
      CoPt_bTqTx_out = CoPt_bTqTx_B;
      CoPt_facAntiJerk_out = CoPt_facAntiJerk_B;
      CoPt_idxPtSpt_out = CoPt_idxPtSpt_B;
      CoPt_noCylCutAuth_out = CoPt_noCylCutAuth_B;
      CoPt_noDrivFilTyp_out = CoPt_noDrivFilTyp_B;
      CoPt_noEgdGear_out = CoPt_noEgdGear_B;
      CoPt_noTarGear_out = CoPt_noTarGear_B;
      CoPt_nPrimShaft_out = CoPt_nPrimShaft_B;
      CoPt_nTar_out = CoPt_nTar_B;
      CoPt_nTrb_out = CoPt_nTrb_B;
      CoPt_posnLev_out = CoPt_posnLev_B;
      CoPt_rCnvTq_out = CoPt_rCnvTq_B;
      CoPt_stClu_out = CoPt_stClu_B;
      CoPt_stCnvCluFil_out = CoPt_stCnvCluFil_B;
      CoPt_stCpl_out = CoPt_stCpl_B;
      CoPt_stDragRed_out = CoPt_stDragRed_B;
      CoPt_stDrvTra_out = CoPt_stDrvTra_B;
      CoPt_stGSTyp_out = CoPt_stGSTyp_B;
      CoPt_tiDeacPrfMod_out = CoPt_tiDeacPrfMod_B;
      CoPt_tOilGBx_out = CoPt_tOilGBx_B;
      CoPt_tqAirMaxGBx_out = CoPt_tqAirMaxGBx_B;
      CoPt_tqCnvClu_out = CoPt_tqCnvClu_B;
      CoPt_tqMaxClu_out = CoPt_tqMaxClu_B;
      CoPt_tqMaxGBx_out = CoPt_tqMaxGBx_B;
      CoPt_tqMaxGBx_nReg_out = CoPt_tqMaxGBx_nReg_B;
      CoPt_tqMaxGBxAir_out = CoPt_tqMaxGBxAir_B;
      CoPt_stVoltAltBoostReq_out = CoPt_stVoltAltBoostReq_B;
      CoPt_nPrimShaftTar_out = CoPt_nPrimShaftTar_B;
      CoPt_tqFfNReg_out = CoPt_tqFfNReg_B;
      CoPt_bEngCrawlAuth_out = CoPt_bEngCrawlAuth_B;
      CoPt_stVehDirEstim_out = CoPt_stVehDirEstim_B;
      CoPt_bSpdVehLoDet_out = CoPt_bSpdVehLoDet_B;
      CoPt_bAcvTqNCord_out = CoPt_bAcvTqNCord_B;
   }
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_stPhaGS_irv(Re_TraBVx_028_TEV_CoPt_stPhaGS_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_bInhNCross_irv(Re_TraBVx_028_TEV_CoPt_bInhNCross_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_noTypPIDGain_irv(Re_TraBVx_028_TEV_CoPt_noTypPIDGain_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_tqGBxLossNReg_irv(Re_TraBVx_028_TEV_CoPt_tqGBxLossNReg_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_tqReqGBx(Re_TraBVx_028_TEV_CoPt_tqReqGBx_out);
   (void)Rte_IrvWrite_RE_TraBVx_028_TEV_CoPt_tqAirReqGBx(Re_TraBVx_028_TEV_CoPt_tqAirReqGBx_out);
   (void)Rte_Write_P_CoPt_bAcvDynTqResCrawl_CoPt_bAcvDynTqResCrawl(CoPt_bAcvDynTqResCrawl_out);
   (void)Rte_Write_P_CoPt_bAcvStatTqResCrawl_CoPt_bAcvStatTqResCrawl(CoPt_bAcvStatTqResCrawl_out);
   (void)Rte_Write_P_CoPt_bAuthCrawl_CoPt_bAuthCrawl(CoPt_bAuthCrawl_out);
   (void)Rte_Write_P_CoPt_idxPrfGBxMsg_CoPt_idxPrfGBxMsg(CoPt_idxPrfGBxMsg_out);
   (void)Rte_Write_P_CoPt_nMinTqMaxGBxMsg_CoPt_nMinTqMaxGBxMsg(CoPt_nMinTqMaxGBxMsg_out);
   (void)Rte_Write_P_CoPt_stCrawl_CoPt_stCrawl(CoPt_stCrawl_out);
   (void)Rte_Write_P_CoPt_stGBxMod_CoPt_stGBxMod(CoPt_stGBxMod_out);
   (void)Rte_Write_P_CoPt_stGearRat_CoPt_stGearRat(CoPt_stGearRat_out);
   (void)Rte_Write_P_CoPt_tqMinGBxMsg_CoPt_tqMinGBxMsg(CoPt_tqMinGBxMsg_out);
   (void)Rte_Write_P_CoPt_tqReqClu_CoPt_tqReqClu(CoPt_tqReqClu_out);
   (void)Rte_Write_P_CoPt_bAcvIdlCrawl_CoPt_bAcvIdlCrawl(CoPt_bAcvIdlCrawl_out);
   (void)Rte_Write_P_CoPt_bAcvNRegReq_CoPt_bAcvNRegReq(CoPt_bAcvNRegReq_out);
   (void)Rte_Write_P_CoPt_bAcvSptTakeOff_CoPt_bAcvSptTakeOff(CoPt_bAcvSptTakeOff_out);
   (void)Rte_Write_P_CoPt_bAcvWupMod_CoPt_bAcvWupMod(CoPt_bAcvWupMod_out);
   (void)Rte_Write_P_CoPt_bBrioUHAuth_CoPt_bBrioUHAuth(CoPt_bBrioUHAuth_out);
   (void)Rte_Write_P_CoPt_bDiagSIPORng_CoPt_bDiagSIPORng(CoPt_bDiagSIPORng_out);
   (void)Rte_Write_P_CoPt_bFrzAC_CoPt_bFrzAC(CoPt_bFrzAC_out);
   (void)Rte_Write_P_CoPt_bFrzEGR_CoPt_bFrzEGR(CoPt_bFrzEGR_out);
   (void)Rte_Write_P_CoPt_bFrzTrbSt_CoPt_bFrzTrbSt(CoPt_bFrzTrbSt_out);
   (void)Rte_Write_P_CoPt_bInhEGR_CoPt_bInhEGR(CoPt_bInhEGR_out);
   (void)Rte_Write_P_CoPt_bInhRecup_CoPt_bInhRecup(CoPt_bInhRecup_out);
   (void)Rte_Write_P_CoPt_bInjCutDynAuth3_CoPt_bInjCutDynAuth3(CoPt_bInjCutDynAuth3_out);
   (void)Rte_Write_P_CoPt_bPrepSIP_CoPt_bPrepSIP(CoPt_bPrepSIP_out);
   (void)Rte_Write_P_CoPt_bPrfModReq_CoPt_bPrfModReq(CoPt_bPrfModReq_out);
   (void)Rte_Write_P_CoPt_bSIP_CoPt_bSIP(CoPt_bSIP_out);
   (void)Rte_Write_P_CoPt_bSmkFil_CoPt_bSmkFil(CoPt_bSmkFil_out);
   (void)Rte_Write_P_CoPt_bTakeOff_CoPt_bTakeOff(CoPt_bTakeOff_out);
   (void)Rte_Write_P_CoPt_bTqAltFrzReq_CoPt_bTqAltFrzReq(CoPt_bTqAltFrzReq_out);
   (void)Rte_Write_P_CoPt_bTqAltGrdLimReq_CoPt_bTqAltGrdLimReq(CoPt_bTqAltGrdLimReq_out);
   (void)Rte_Write_P_CoPt_bTqTx_CoPt_bTqTx(CoPt_bTqTx_out);
   (void)Rte_Write_P_CoPt_facAntiJerk_CoPt_facAntiJerk(CoPt_facAntiJerk_out);
   (void)Rte_Write_P_CoPt_idxPtSpt_CoPt_idxPtSpt(CoPt_idxPtSpt_out);
   (void)Rte_Write_P_CoPt_noCylCutAuth_CoPt_noCylCutAuth(CoPt_noCylCutAuth_out);
   (void)Rte_Write_P_CoPt_noDrivFilTyp_CoPt_noDrivFilTyp(CoPt_noDrivFilTyp_out);
   (void)Rte_Write_P_CoPt_noEgdGear_CoPt_noEgdGear(CoPt_noEgdGear_out);
   (void)Rte_Write_P_CoPt_noTarGear_CoPt_noTarGear(CoPt_noTarGear_out);
   (void)Rte_Write_P_CoPt_nPrimShaft_CoPt_nPrimShaft(CoPt_nPrimShaft_out);
   (void)Rte_Write_P_CoPt_nTar_CoPt_nTar(CoPt_nTar_out);
   (void)Rte_Write_P_CoPt_nTrb_CoPt_nTrb(CoPt_nTrb_out);
   (void)Rte_Write_P_CoPt_posnLev_CoPt_posnLev(CoPt_posnLev_out);
   (void)Rte_Write_P_CoPt_rCnvTq_CoPt_rCnvTq(CoPt_rCnvTq_out);
   (void)Rte_Write_P_CoPt_stClu_CoPt_stClu(CoPt_stClu_out);
   (void)Rte_Write_P_CoPt_stCnvCluFil_CoPt_stCnvCluFil(CoPt_stCnvCluFil_out);
   (void)Rte_Write_P_CoPt_stCpl_CoPt_stCpl(CoPt_stCpl_out);
   (void)Rte_Write_P_CoPt_stDragRed_CoPt_stDragRed(CoPt_stDragRed_out);
   (void)Rte_Write_P_CoPt_stDrvTra_CoPt_stDrvTra(CoPt_stDrvTra_out);
   (void)Rte_Write_P_CoPt_stGSTyp_CoPt_stGSTyp(CoPt_stGSTyp_out);
   (void)Rte_Write_P_CoPt_tiDeacPrfMod_CoPt_tiDeacPrfMod(CoPt_tiDeacPrfMod_out);
   (void)Rte_Write_P_CoPt_tOilGBx_CoPt_tOilGBx(CoPt_tOilGBx_out);
   (void)Rte_Write_P_CoPt_tqAirMaxGBx_CoPt_tqAirMaxGBx(CoPt_tqAirMaxGBx_out);
   (void)Rte_Write_P_CoPt_tqCnvClu_CoPt_tqCnvClu(CoPt_tqCnvClu_out);
   (void)Rte_Write_P_CoPt_tqMaxClu_CoPt_tqMaxClu(CoPt_tqMaxClu_out);
   (void)Rte_Write_P_CoPt_tqMaxGBx_CoPt_tqMaxGBx(CoPt_tqMaxGBx_out);
   (void)Rte_Write_P_CoPt_tqMaxGBx_nReg_CoPt_tqMaxGBx_nReg(CoPt_tqMaxGBx_nReg_out);
   (void)Rte_Write_P_CoPt_tqMaxGBxAir_CoPt_tqMaxGBxAir(CoPt_tqMaxGBxAir_out);
   (void)Rte_Write_P_CoPt_stVoltAltBoostReq_CoPt_stVoltAltBoostReq(CoPt_stVoltAltBoostReq_out);
   (void)Rte_Write_P_CoPt_nPrimShaftTar_CoPt_nPrimShaftTar(CoPt_nPrimShaftTar_out);
   (void)Rte_Write_P_CoPt_tqFfNReg_CoPt_tqFfNReg(CoPt_tqFfNReg_out);
   (void)Rte_Write_P_CoPt_bEngCrawlAuth_CoPt_bEngCrawlAuth(CoPt_bEngCrawlAuth_out);
   (void)Rte_Write_P_CoPt_stVehDirEstim_CoPt_stVehDirEstim(CoPt_stVehDirEstim_out);
   (void)Rte_Write_P_CoPt_bSpdVehLoDet_CoPt_bSpdVehLoDet(CoPt_bSpdVehLoDet_out);
   (void)Rte_Write_P_CoPt_bAcvTqNCord_CoPt_bAcvTqNCord(CoPt_bAcvTqNCord_out);
   (void)Rte_Write_P_CoPt_bInhAC_CoPt_bInhAC(CoPt_bInhAC_out);
   (void)Rte_Write_P_CoPt_bAcvCycMod_CoPt_bAcvCycMod(CoPt_bAcvCycMod_out);
}

void RE_TraBVx_030_TEV(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TraBVx_030_TqSys_bTypFu_in);
      (void)Rte_Read_R_CoCha_tqEfcAirReq_CoCha_tqEfcAirReq(&TraBVx_030_CoCha_tqEfcAirReq_in);
      (void)Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&TraBVx_030_Ext_stTraTypCf_in);
      (void)Rte_Read_R_TqSys_stTypPwtCf_TqSys_stTypPwtCf(&TraBVx_030_TqSys_stTypPwtCf_in);
      (void)Rte_Read_R_TqSys_tqEfcIdl_TqSys_tqEfcIdl(&TraBVx_030_TqSys_tqEfcIdl_in);
      (void)Rte_Read_R_Cha_tqDynASRReq_Cha_tqDynASRReq(&TraBVx_030_Cha_tqDynASRReq_in);
      (void)Rte_Read_R_Cha_tqMSRReq_Cha_tqMSRReq(&TraBVx_030_Cha_tqMSRReq_in);
      (void)Rte_Read_R_CoCha_tqEfcReq_CoCha_tqEfcReq(&TraBVx_030_CoCha_tqEfcReq_in);
      (void)Rte_Read_R_CoCha_tqEfcReqExt_CoCha_tqEfcReqExt(&TraBVx_030_CoCha_tqEfcReqExt_in);
      (void)Rte_Read_R_CoPt_bAcvTqMaxEstim_CoPt_bAcvTqMaxEstim(&TraBVx_030_CoPt_bAcvTqMaxEstim_in);
      (void)Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&TraBVx_030_CoPt_bSIP_in);
      (void)Rte_Read_R_EngLim_tqCkEfcATLimCordEL2_EngLim_tqCkEfcATLimCordEL2(&TraBVx_030_EngLim_tqCkEfcATLimCordEL2_in);
      (void)Rte_Read_R_EngLim_tqCkEfcGBxLimCordEL2_EngLim_tqCkEfcGBxLimCordEL2(&TraBVx_030_EngLim_tqCkEfcGBxLimCordEL2_in);
      (void)Rte_Read_R_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(&TraBVx_030_TqCmp_tqCnvLoss_in);
      (void)Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&TraBVx_030_TqLimEM_tqLimEM_in);
      (void)Rte_Read_R_TqLimEM_tqLimEMExt_TqLimEM_tqLimEMExt(&TraBVx_030_TqLimEM_tqLimEMExt_in);
      (void)Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&TraBVx_030_TqSys_tqCkEfcFil_in);
      (void)Rte_Read_R_TqSys_tqCkEfcFilExt_TqSys_tqCkEfcFilExt(&TraBVx_030_TqSys_tqCkEfcFilExt_in);
      (void)Rte_Read_R_CoCha_tqEfcAirReqExt_CoCha_tqEfcAirReqExt(&TraBVx_030_CoCha_tqEfcAirReqExt_in);
      (void)Rte_Read_R_TqCha_tqAirTqDecReq_TqCha_tqAirTqDecReq(&TraBVx_030_TqCha_tqAirTqDecReq_in);
      (void)Rte_Read_R_TqCha_tqAirTqDecReqExt_TqCha_tqAirTqDecReqExt(&TraBVx_030_TqCha_tqAirTqDecReqExt_in);
      (void)Rte_Read_R_TqCha_tqAirTqIncReq_TqCha_tqAirTqIncReq(&TraBVx_030_TqCha_tqAirTqIncReq_in);
      (void)Rte_Read_R_TqCha_tqAirTqIncReqExt_TqCha_tqAirTqIncReqExt(&TraBVx_030_TqCha_tqAirTqIncReqExt_in);
      (void)Rte_Read_R_TqSys_tqCkEfcAirFil_TqSys_tqCkEfcAirFil(&TraBVx_030_TqSys_tqCkEfcAirFil_in);
      (void)Rte_Read_R_TqSys_tqCkEfcAirFilExt_TqSys_tqCkEfcAirFilExt(&TraBVx_030_TqSys_tqCkEfcAirFilExt_in);
      (void)Rte_Read_R_TqSys_tqEfcAirIdl_TqSys_tqEfcAirIdl(&TraBVx_030_TqSys_tqEfcAirIdl_in);
      (void)Rte_Read_R_CoVSCtl_tqSIPTar_CoVSCtl_tqSIPTar(&TraBVx_030_CoVSCtl_tqSIPTar_in);
      (void)Rte_Read_R_CoPt_bAcvTqNCord_CoPt_bAcvTqNCord(&TraBVx_030_CoPt_bAcvTqNCord_in);
	  Re_TraBVx_030_TEV_CoPt_tqReqGBx_in=Rte_IrvRead_RE_TraBVx_030_TEV_CoPt_tqReqGBx();
	  Re_TraBVx_030_TEV_CoPt_tqAirReqGBx_in=Rte_IrvRead_RE_TraBVx_030_TEV_CoPt_tqAirReqGBx();

      TraBVx_030_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      CoPt_bDeacCllIt_out = CoPt_bDeacCllIt_B;
      CoPt_tqCord_tqGBx_out = CoPt_tqCord_tqGBx_B;
      CoPt_tqDrvFil_out = CoPt_tqDrvFil_B;
      CoPt_tqDrvRaw_out = CoPt_tqDrvRaw_B;
      CoPt_tqAirDrvFil_out = CoPt_tqAirDrvFil_B;
      CoPt_tqAirCord_tqGBx_out = CoPt_tqAirCord_tqGBx_B;
      CoPt_tqDrvRawTarGear_out = CoPt_tqDrvRawTarGear_B;
   }

   (void)Rte_Write_P_CoPt_bDeacCllIt_CoPt_bDeacCllIt(CoPt_bDeacCllIt_out);
   (void)Rte_Write_P_CoPt_tqCord_tqGBx_CoPt_tqCord_tqGBx(CoPt_tqCord_tqGBx_out);
   (void)Rte_Write_P_CoPt_tqDrvFil_CoPt_tqDrvFil(CoPt_tqDrvFil_out);
   (void)Rte_Write_P_CoPt_tqDrvRaw_CoPt_tqDrvRaw(CoPt_tqDrvRaw_out);
   (void)Rte_Write_P_CoPt_tqAirDrvFil_CoPt_tqAirDrvFil(CoPt_tqAirDrvFil_out);
   (void)Rte_Write_P_CoPt_tqAirCord_tqGBx_CoPt_tqAirCord_tqGBx(CoPt_tqAirCord_tqGBx_out);
   (void)Rte_Write_P_CoPt_tqDrvRawTarGear_CoPt_tqDrvRawTarGear(CoPt_tqDrvRawTarGear_out);

}

void RE_TraBVx_032_TEV(void)
{
   if (FALSE == TRABVX_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TraBVx_032_Ext_nEng_in);
      (void)Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&TraBVx_032_TqCmp_tqSumLossCmp_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TraBVx_032_TqSys_bTypFu_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&TraBVx_032_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&TraBVx_032_CoVSCtl_rAccPEngTrv_in);
      (void)Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&TraBVx_032_Ext_stTraTypCf_in);
      (void)Rte_Read_R_CoPt_noTarGearCordIt_CoPt_noTarGearCordIt(&TraBVx_032_CoPt_noTarGearCordIt_in);
      (void)Rte_Read_R_CoPt_nTar_CoPt_nTar(&TraBVx_032_CoPt_nTar_in);
      (void)Rte_Read_R_CoPt_tqIdcAirCordLim_tqGBx_CoPt_tqIdcAirCordLim_tqGBx(&TraBVx_032_CoPt_tqIdcAirCordLim_tqGBx_in);
      (void)Rte_Read_R_TqEst_tqIdcStrt_TqEst_tqIdcStrt(&TraBVx_032_TqEst_tqIdcStrt_in);
      (void)Rte_Read_R_TqSys_bTqSysAcv_TqSys_bTqSysAcv(&TraBVx_032_TqSys_bTqSysAcv_in);
      (void)Rte_Read_R_CoPt_nTrb_CoPt_nTrb(&TraBVx_032_CoPt_nTrb_in);
      (void)Rte_Read_R_TqSys_idxTqAccu_TqSys_idxTqAccu(&TraBVx_032_TqSys_idxTqAccu_in);
      (void)Rte_Read_R_CoPt_bAcvNRegReq_CoPt_bAcvNRegReq(&TraBVx_032_CoPt_bAcvNRegReq_in);
      (void)Rte_Read_R_CoPt_bAcvNCross_CoPt_bAcvNCross(&TraBVx_032_CoPt_bAcvNCross_in);
      (void)Rte_Read_R_CoPt_tqIdcAirMaxGBx_CoPt_tqIdcAirMaxGBx(&TraBVx_032_CoPt_tqIdcAirMaxGBx_in);
      Re_TraBVx_032_TEV_CoPt_bVldAcvNReg_irv_in = Rte_IrvRead_RE_TraBVx_032_TEV_CoPt_bVldAcvNReg_irv();
      Re_TraBVx_032_TEV_CoPt_bInhNCross_irv_in = Rte_IrvRead_RE_TraBVx_032_TEV_CoPt_bInhNCross_irv();
      Re_TraBVx_032_TEV_CoPt_noTypPIDGain_irv_in = Rte_IrvRead_RE_TraBVx_032_TEV_CoPt_noTypPIDGain_irv();
      Re_TraBVx_032_TEV_CoPt_tqIdcNReg_irv_in = Rte_IrvRead_RE_TraBVx_032_TEV_CoPt_tqIdcNReg_irv();

      TraBVx_032_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      CoPt_tqIdcAirGslCord_nReg_out = CoPt_tqIdcAirGslCord_nReg_B;
      CoPt_tqIdcAirCord_nCross_out = CoPt_tqIdcAirCord_nCross_B;
   }
   (void)Rte_IrvWrite_RE_TraBVx_032_TEV_CoPt_tqIniNReg_irv(Re_TraBVx_032_TEV_CoPt_tqIniNReg_irv_out);
   (void)Rte_IrvWrite_RE_TraBVx_032_TEV_CoPt_nErrNReg_irv(Re_TraBVx_032_TEV_CoPt_nErrNReg_irv_out);
   (void)Rte_Write_P_CoPt_tqIdcAirGslCord_nReg_CoPt_tqIdcAirGslCord_nReg(CoPt_tqIdcAirGslCord_nReg_out);
   (void)Rte_Write_P_CoPt_tqIdcAirCord_nCross_CoPt_tqIdcAirCord_nCross(CoPt_tqIdcAirCord_nCross_out);

}

#define TRABVX_STOP_SEC_CODE
#include "TraBVx_MemMap.h"

#endif/*_TRABVX_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
