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
* %name: MPM_calibrations.h %
*
* %version: 2.0_OBS %
*
* %date_modified: Fri Aug 10 10:45:34 2012 %
*
*
* %derived_by: u260001 %
* %release: EB2DT/SC3 %
* %full_filespec: MPM_calibrations.h-2.0_OBS:incl:2 %
*
*******************************************************************************/


#ifndef _MPM_CALIBRATIONS_H_
#define _MPM_CALIBRATIONS_H_
#include "tl_defines.h"
#include "tl_basetypes.h"
#define MPM_START_SEC_CALIB_16BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_dstVehThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_dstVehThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylBlockDmgThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylBlockDmgThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylHdDmgThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylHdDmgThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylHdInjDmgThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rCylHdInjDmgThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rExMnfDmgThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rExMnfDmgThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rTrbCaseDmgThdLdLim_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgMSI_rTrbCaseDmgThdMPMInh_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 DmgM_pCylBlockMecStrgth_C;extern 
AR_MERGEABLE_CALIB_16BIT UInt16 MPM_nEngThd_C;extern AR_MERGEABLE_CALIB_16BIT 
UInt16 MPM_tExMnfThdHi_C;extern AR_MERGEABLE_CALIB_16BIT UInt16 
MPM_tExMnfThdLo_C;extern AR_MERGEABLE_CALIB_16BIT UInt16 RFL_pwrDeltaThd_C;
extern AR_MERGEABLE_CALIB_16BIT UInt16 RFL_tDeltaThd_C;
#define MPM_STOP_SEC_CALIB_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_CALIB_8BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 MPM_tiDecInterBas_C;extern 
AR_MERGEABLE_CALIB_8BIT UInt8 MPM_tiDecMPMInter_C;extern AR_MERGEABLE_CALIB_8BIT
 UInt8 MPM_tiIncInterBas_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 
MPM_tiIncMPMInter_C;extern AR_MERGEABLE_CALIB_8BIT UInt8 RFL_noAcvCylHd_C;extern
 AR_MERGEABLE_CALIB_8BIT UInt8 RFL_noAcvExMnf_C;extern AR_MERGEABLE_CALIB_8BIT 
UInt8 RFL_noAcvTrbCase_C;
#define MPM_STOP_SEC_CALIB_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bAcvDmgCylBlock_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bAcvDmgCylHdInj_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bAcvDmgCylHd_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bAcvDmgExMnf_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean DmgMSI_bAcvDmgTrbCase_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bAcvBedModDft_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bAcvBedModDmgThd_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bAuthRvInterBas_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bAuthRvMPMInter_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bInhMPM_C;extern 
AR_MERGEABLE_CALIB_BOOLEAN Boolean MPM_bLdLim_C;
#define MPM_STOP_SEC_CALIB_BOOLEAN
#include "MPM_MemMap.h"
#define MPM_START_SEC_CARTO_16BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CARTO_16BIT UInt16 DmgMSI_pCylBlockMecStrgthEqu_M[12][16];
extern AR_MERGEABLE_CARTO_16BIT UInt16 DmgMSI_pwrCylRCylHdInjDmgY_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 DmgMSI_rAirLdPCylBlockX_A[12];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngFacRLdInhY_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngFacRLdInterY_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngFacRLdMaxY_A[6];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngRLdInh_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngRLdInter_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_nEngRLdMax_A[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_rLdInhMPM_T[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_rLdInter_T[16];extern 
AR_MERGEABLE_CARTO_16BIT UInt16 MPM_rLdMax_T[16];extern AR_MERGEABLE_CARTO_16BIT
 UInt16 RFL_pwrAvr_rDmgCylHdY_A[20];extern AR_MERGEABLE_CARTO_16BIT UInt16 
RFL_pwrDelta_rDmgCylHdX_A[16];extern AR_MERGEABLE_CARTO_16BIT UInt16 
RFL_tAvr_rDmgExMnfY_A[20];extern AR_MERGEABLE_CARTO_16BIT UInt16 
RFL_tAvr_rDmgTrbCaseY_A[20];extern AR_MERGEABLE_CARTO_16BIT UInt16 
RFL_tDelta_rDmgExMnfX_A[16];extern AR_MERGEABLE_CARTO_16BIT UInt16 
RFL_tDelta_rDmgTrbCaseX_A[16];
#define MPM_STOP_SEC_CARTO_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_CARTO_32BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CARTO_32BIT UInt32 DmgMSI_pCylMaxRCylHdInjDmgX_A[12];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 DmgMSI_rCylHdInjDmg_M[12][16];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_facOvbRLdInh_M[4][6];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_facOvbRLdInter_M[4][6];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_facOvbRLdMax_M[4][6];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_tThrFacRLdInhX_A[4];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_tThrFacRLdInterX_A[4];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 MPM_tThrFacRLdMaxX_A[4];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 RFL_rDmgCylHd_M[16][20];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 RFL_rDmgExMnf_M[16][20];extern 
AR_MERGEABLE_CARTO_32BIT UInt32 RFL_rDmgTrbCase_M[16][20];
#define MPM_STOP_SEC_CARTO_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_CARTO_8BIT
#include "MPM_MemMap.h"
extern AR_MERGEABLE_CARTO_8BIT UInt8 DmgMSI_nEngPCylBlockY_A[16];
#define MPM_STOP_SEC_CARTO_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_16BIT
#include "MPM_MemMap.h"
extern AR_INTERNAL_VAR_DISP_16BIT UInt16 MPM_facTranInterBas;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 MPM_facTranMPMInter;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 MPM_rLdMaxInter_MP;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RE006_DmgMSI_rCylHdInjDmgCnt_out;extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RFL_prm_tWallPwrFlow[20];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RFL_prm_tWallPwrFlowCylHd[20];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RFL_prm_tWallPwrFlowExMnf[20];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RFL_prm_tWallPwrFlowPrev[20];extern 
AR_INTERNAL_VAR_DISP_16BIT UInt16 RFL_prm_tWallPwrFlowTrbCase[20];
#define MPM_STOP_SEC_INTERNAL_VAR_16BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_32BIT
#include "MPM_MemMap.h"
extern AR_INTERNAL_VAR_DISP_32BIT UInt32 DmgMSI_ctCylHdInjDmgInter;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 DmgMSI_rCylBlockDmg_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 DmgMSI_rCylHdInjDmg;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 DmgMSI_rCylHdInjDmgInter;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 MPM_facOvbInter_MP;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 RE003_DmgMSI_rTrbCaseDmg_out;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 RE004_DmgMSI_rExMnfDmg_out;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 RE005_DmgMSI_rCylHdDmg_out;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 RE006_DmgMSI_rCylBlockDmg_out;extern 
AR_INTERNAL_VAR_DISP_32BIT UInt32 RFL_rDmg;extern AR_INTERNAL_VAR_DISP_32BIT 
UInt32 RFL_rDmgPrev;
#define MPM_STOP_SEC_INTERNAL_VAR_32BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_8BIT
#include "MPM_MemMap.h"
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 LibCallNum;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 MPM_stCtl;extern AR_INTERNAL_VAR_DISP_8BIT UInt8
 RFL_idxPrm;extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RFL_idxPrmCylHd;extern 
AR_INTERNAL_VAR_DISP_8BIT UInt8 RFL_idxPrmExMnf;extern AR_INTERNAL_VAR_DISP_8BIT
 UInt8 RFL_idxPrmPrev;extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RFL_idxPrmTrbCase;
extern AR_INTERNAL_VAR_DISP_8BIT UInt8 RFL_noAcvMap;
#define MPM_STOP_SEC_INTERNAL_VAR_8BIT
#include "MPM_MemMap.h"
#define MPM_START_SEC_INTERNAL_VAR_BOOLEAN
#include "MPM_MemMap.h"
extern AR_INTERNAL_VAR_DISP_BOOLEAN Boolean Afts_bRstCntReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvLdLimCylBlock;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvLdLimCylHd;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvLdLimCylHdInj;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvLdLimExMnf;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvLdLimTrbCase;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvMPMInhCylBlock;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvMPMInhCylHd;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvMPMInhCylHdInj;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvMPMInhExMnf;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAcvMPMInhTrbCase;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bAuthLdLim;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgMSI_bCylHdInjDmgMv;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean DmgM_bAuthMPMInh;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MPM_bLdLimReq;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MPM_bMPMDft;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean MPM_bMPMInh;extern 
AR_INTERNAL_VAR_DISP_BOOLEAN Boolean RFL_bAcvSelMod;
#define MPM_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "MPM_MemMap.h"
#endif

