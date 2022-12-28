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
* %name: ThMgt.c %
*
* %version: 15.2.build1 %
*
* %date_modified: Thu Nov 14 17:49:44 2013 %
*
*
* %derived_by: u299919 %
* %release: ThMgt/14.2 %
* %full_filespec: ThMgt.c-15.2.build1:csrc:6 %
*
*******************************************************************************/

#ifndef _THMGT_C_
#define _THMGT_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_ThMgt.h"
#include "ThMgt.h"
#include "ThMgt_002_TEV_fct.h"
#include "ThMgt_003_TEV_fct.h"
#include "ThMgt_004_TEV_fct.h"
#include "ThMgt_002_calibrations.h"
#include "ThMgt_003_calibrations.h"
#include "ThMgt_004_calibrations.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define THMGT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ThMgt_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ThMgt_ModuleVersion_Major_MP = 15;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ThMgt_ModuleVersion_Minor_MP = 2;
#define THMGT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 5
#define Module_LIB_PSA_VERSION_REQ_MIN 7
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define THMGT_START_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean THMGT_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bMainWaPmpSt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldAdFanReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldTrbWaPmpReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bACCmprOffReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAcvR1234Mgt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bAdFanReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bBattFanReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bECTAftsReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bECUFanReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEHRHeatReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEHRWaPmpReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bEndCtlCoVlv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bHeatWaPmpReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bHldPosnCoVlvReq_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bMainWaPmpReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPosnFSF_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldCoVlvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldFSFReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bPwrHldMainFanReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bTCoWarnReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bTrbWaPmpReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ThMgt_bIncVoltReq_B = 0;
#define THMGT_STOP_SEC_CALIB_BOOLEAN
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rCoHeatReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rPwrECTReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpBypCoVlvReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpHeatCoVlvReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rOpRadCoVlvReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_rSpdFanReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stPosnCoVlvEstim_B = 3;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stPosnFSFReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_stSpdCoVlvReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ThMgt_tECTReq_B = 105;
#define THMGT_STOP_SEC_CALIB_8BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_nTarIdlHeatReq_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tiAcvTrbWaPmpEngStop_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_tqIdcLimReq_B = 32000;
AR_MERGEABLE_CALIB_16BIT UInt16 ThMgt_wThFil_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 ThMgt_tCoReg_B = 105;
#define THMGT_STOP_SEC_CALIB_16BIT
#include "ThMgt_MemMap.h"

#define THMGT_START_SEC_VAR_BOOLEAN
#include "ThMgt_MemMap.h"
static Boolean ThMgt_bMonRunAntiBoil_out_prec;
static Boolean ThMgt_bMonRunCoSysDfct_out_prec;
static Boolean ThMgt_bMonRunFSFBlockCls_out_prec;
static Boolean ThMgt_bMonRunFSFBlockOp_out_prec;
static Boolean ThMgt_bMonRunTCoBlock_out_prec;
static Boolean ThMgt_bMonRunTCoOverEstim_out_prec;
static Boolean ThMgt_bMonRunTCoSlowRise_out_prec;
static Boolean ThMgt_bMonRunTCoUndEstim_out_prec;
static Boolean ThMgt_bMonRunTCoWarn_out_prec;
static Boolean ThMgt_bMonRunThermoStuckCls_out_prec;
static Boolean ThMgt_bMonRunThermoStuckOp_out_prec;
#define THMGT_STOP_SEC_VAR_BOOLEAN
#include "ThMgt_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define THMGT_START_SEC_CODE
#include "ThMgt_MemMap.h"
void RE_ThMgt_001_MSE(void)
{

	  ThMgt_002_TEV_ini();
	  ThMgt_003_TEV_ini();
	  ThMgt_004_TEV_ini();

   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AntiBoil_rCorPwrFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AntiBoil_tCoMesFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AtyModMgt_bLoTCoRegReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AtyModMgt_tECTReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CmptFil_agStrWhlFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CmptFil_agvStrWhlFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CoAftsMgt_tECTAftsReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EGRCo_bOpCoVlvReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EGRCo_stSpdCoVlvReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EGRVlvByp_rOp(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TPMByp_bExThermoProt(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EngMByp_mfDsEGRCoEstim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EngMByp_mfEgEstim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ESLimByp_bAcvTrqLim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_nEng(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_pAirExtMes(1000);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_spdVeh(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tAirExtMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tCoMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tCoMesFineResl2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tECTSp(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tUsPFlt(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bAcvBoilLimChg(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bAcvLoTCoReg(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bAcvTrbWaPmp(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bAcvVeryLoTCoReg(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bDeacCoBoilLim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bInhDiagCoBoilLim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_bEngRun(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_bEngStop(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_bPFltRgnReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_tAirInMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_tEg(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_tqIdcEstim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_tqIdcFld(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PFltByp_bPFltRgnSrvReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PwtFil_nEngFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PwtFil_tCoRegFil1(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PwtFil_tCoRegFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PwtFil_tqIdcEstimFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_StgByp_agStrWhl(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_StgByp_agvStrWhl(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ThEClc_wThFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TRegClc_bEngWrm(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TRegClc_bHiEngLd(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TRegClc_bModRegCoVlv(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TRegClc_tCoRegCoVlv(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TRegClc_tCoRegECT(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_nEngFil1(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_nEngFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_spdVehFil1(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_spdVehFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tAirExtMesFil1(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tAirExtMesFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tAirInMesFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tqIdcEstimFil1(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tqIdcEstimFil2(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoFil_tUsPFltFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoTMgt_bLoTCoRegReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_UndHoTMgt_tECTReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AirSysByp_rOpEGRCoBypReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CoPtByp_bTqTx(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CoPtByp_noEgdGearCord(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CoPtByp_stCpl(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EOMByp_stCmbTdOff(15);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EOMByp_tiEngStop(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_bFSFCf(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_bKeyOff(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_stGBxCf(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_stVSSCf(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tAirUsCmprMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tDsThrMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tFuMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tOilMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_ExtByp_tUsThrMes(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bAcvNoEgdGearDft(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_FRMByp_bInhTCoColdDiag(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_bACCf(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_bPwtRun(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_KnkMgtByp_ctRblInjCutOffPtl(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_OAMByp_rOilDil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AntiBoil_bRatCorPwrFilIniDly(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_AntiBoil_tECTReqDly(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CoVlvCtl_bRstStopHldDly(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_GBxCo_tECTReqDly(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_IgSysByp_bAcvLoTCoRegKnk(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InThMByp_tAirUsInVlvEstim(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_KnkProt_tECTAdpReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_KnkProt_tECTTAirReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_OilDilProt_bLoTCoRegReq(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_TqSysByp_tqIdcAirReqGen(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_CmptFil_tCACFil(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_InpClc_tCAC(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_EngLimByp_tqIdcEngCur(0);
   (void)Rte_IrvWrite_RE_ThMgt_001_MSE_PwtFil_tCoRegFil3(0);
   (void)Rte_Write_P_ThMgt_bMainWaPmpSt_ThMgt_bMainWaPmpSt(0);
   (void)Rte_Write_P_ThMgt_bPwrHldAdFanReq_ThMgt_bPwrHldAdFanReq(0);
   (void)Rte_Write_P_ThMgt_bPwrHldTrbWaPmpReq_ThMgt_bPwrHldTrbWaPmpReq(0);
   (void)Rte_Write_P_ThMgt_rCoHeatReq_ThMgt_rCoHeatReq(0);
   (void)Rte_Write_P_ThMgt_rPwrECTReq_ThMgt_rPwrECTReq(0);
   (void)Rte_Write_P_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq(0);
   (void)Rte_Write_P_ThMgt_bAcvR1234Mgt_ThMgt_bAcvR1234Mgt(0);
   (void)Rte_Write_P_ThMgt_bAdFanReq_ThMgt_bAdFanReq(0);
   (void)Rte_Write_P_ThMgt_bBattFanReq_ThMgt_bBattFanReq(0);
   (void)Rte_Write_P_ThMgt_bECTAftsReq_ThMgt_bECTAftsReq(0);
   (void)Rte_Write_P_ThMgt_bECUFanReq_ThMgt_bECUFanReq(0);
   (void)Rte_Write_P_ThMgt_bEHRHeatReq_ThMgt_bEHRHeatReq(0);
   (void)Rte_Write_P_ThMgt_bEHRWaPmpReq_ThMgt_bEHRWaPmpReq(0);
   (void)Rte_Write_P_ThMgt_bEndCtlCoVlv_ThMgt_bEndCtlCoVlv(0);
   (void)Rte_Write_P_ThMgt_bHeatWaPmpReq_ThMgt_bHeatWaPmpReq(0);
   (void)Rte_Write_P_ThMgt_bHldPosnCoVlvReq_ThMgt_bHldPosnCoVlvReq(1);
   (void)Rte_Write_P_ThMgt_bMainWaPmpReq_ThMgt_bMainWaPmpReq(0);
   (void)Rte_Write_P_ThMgt_bPosnFSF_ThMgt_bPosnFSF(0);
   (void)Rte_Write_P_ThMgt_bPwrHldCoVlvReq_ThMgt_bPwrHldCoVlvReq(0);
   (void)Rte_Write_P_ThMgt_bPwrHldFSFReq_ThMgt_bPwrHldFSFReq(0);
   (void)Rte_Write_P_ThMgt_bPwrHldMainFanReq_ThMgt_bPwrHldMainFanReq(0);
   (void)Rte_Write_P_ThMgt_bRstrtReq_ThMgt_bRstrtReq(0);
   (void)Rte_Write_P_ThMgt_bTCoWarnReq_ThMgt_bTCoWarnReq(0);
   (void)Rte_Write_P_ThMgt_bTrbWaPmpReq_ThMgt_bTrbWaPmpReq(0);
   (void)Rte_Write_P_ThMgt_nTarIdlHeatReq_ThMgt_nTarIdlHeatReq(0);
   (void)Rte_Write_P_ThMgt_rOpBypCoVlvReq_ThMgt_rOpBypCoVlvReq(0);
   (void)Rte_Write_P_ThMgt_rOpHeatCoVlvReq_ThMgt_rOpHeatCoVlvReq(0);
   (void)Rte_Write_P_ThMgt_rOpRadCoVlvReq_ThMgt_rOpRadCoVlvReq(0);
   (void)Rte_Write_P_ThMgt_rSpdFanReq_ThMgt_rSpdFanReq(0);
   (void)Rte_Write_P_ThMgt_stPosnCoVlvEstim_ThMgt_stPosnCoVlvEstim(3);
   (void)Rte_Write_P_ThMgt_stPosnFSFReq_ThMgt_stPosnFSFReq(0);
   (void)Rte_Write_P_ThMgt_stSpdCoVlvReq_ThMgt_stSpdCoVlvReq(0);
   (void)Rte_Write_P_ThMgt_tECTReq_ThMgt_tECTReq(105);
   (void)Rte_Write_P_ThMgt_tiAcvTrbWaPmpEngStop_ThMgt_tiAcvTrbWaPmpEngStop(0);
   (void)Rte_Write_P_ThMgt_tqIdcLimReq_ThMgt_tqIdcLimReq(32000);
   (void)Rte_Write_P_ThMgt_wThFil_ThMgt_wThFil(0);
   (void)Rte_Write_P_ThMgt_bIncVoltReq_ThMgt_bIncVoltReq(0);
   (void)Rte_Write_P_ThMgt_tCoReg_ThMgt_tCoReg(105);
}

void RE_ThMgt_002_TEV(void)
{
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AC_bOpFSFReq_AC_bOpFSFReq(&ThMgt_RE002_AC_bOpFSFReq_in);
      (void)Rte_Read_R_AC_rSpdFanReq_AC_rSpdFanReq(&ThMgt_RE002_AC_rSpdFanReq_in);
      (void)Rte_Read_R_Afts_bAcvFSF_Afts_bAcvFSF(&ThMgt_RE002_Afts_bAcvFSF_in);
      (void)Rte_Read_R_CoVlv_rOpBypCoVlvMes_CoVlv_rOpBypCoVlvMes(&ThMgt_RE002_CoVlv_rOpBypCoVlvMes_in);
      (void)Rte_Read_R_CoVlv_rOpHeatCoVlvMes_CoVlv_rOpHeatCoVlvMes(&ThMgt_RE002_CoVlv_rOpHeatCoVlvMes_in);
      (void)Rte_Read_R_CoVlv_rOpRadCoVlvMes_CoVlv_rOpRadCoVlvMes(&ThMgt_RE002_CoVlv_rOpRadCoVlvMes_in);
      (void)Rte_Read_R_ElSysCo_bOpFSFReq_ElSysCo_bOpFSFReq(&ThMgt_RE002_ElSysCo_bOpFSFReq_in);
      (void)Rte_Read_R_ElSysCo_rSpdFanReq_ElSysCo_rSpdFanReq(&ThMgt_RE002_ElSysCo_rSpdFanReq_in);
      (void)Rte_Read_R_EngM_tUsTrbEstimFil_EngM_tUsTrbEstimFil(&ThMgt_RE002_EngM_tUsTrbEstimFil_in);
      (void)Rte_Read_R_ExM_tExMnfEstim_ExM_tExMnfEstim(&ThMgt_RE002_ExM_tExMnfEstim_in);
      (void)Rte_Read_R_Ext_bRawMainWaPmpSt_Ext_bRawMainWaPmpSt(&ThMgt_RE002_Ext_bRawMainWaPmpSt_in);
      (void)Rte_Read_R_Ext_stSpdFanPFltReq_Ext_stSpdFanPFltReq(&ThMgt_RE002_Ext_stSpdFanPFltReq_in);
      (void)Rte_Read_R_Ext_tAirExtMes_Ext_tAirExtMes(&ThMgt_RE002_Ext_tAirExtMes_in);
      (void)Rte_Read_R_Ext_tAirUsCmprMes_Ext_tAirUsCmprMes(&ThMgt_RE002_Ext_tAirUsCmprMes_in);
      (void)Rte_Read_R_Ext_tBattMes_Ext_tBattMes(&ThMgt_RE002_Ext_tBattMes_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ThMgt_RE002_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tCoMesFineResl2_Ext_tCoMesFineResl2(&ThMgt_RE002_Ext_tCoMesFineResl2_in);
      (void)Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&ThMgt_RE002_Ext_tDsThrMes_in);
      (void)Rte_Read_R_Ext_tECTSp_Ext_tECTSp(&ThMgt_RE002_Ext_tECTSp_in);
      (void)Rte_Read_R_Ext_tECUMes_Ext_tECUMes(&ThMgt_RE002_Ext_tECUMes_in);
      (void)Rte_Read_R_Ext_tFuMes_Ext_tFuMes(&ThMgt_RE002_Ext_tFuMes_in);
      (void)Rte_Read_R_Ext_tOilGBx_Ext_tOilGBx(&ThMgt_RE002_Ext_tOilGBx_in);
      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&ThMgt_RE002_Ext_tOilMes_in);
      (void)Rte_Read_R_Ext_tUcapMes_Ext_tUcapMes(&ThMgt_RE002_Ext_tUcapMes_in);
      (void)Rte_Read_R_Ext_tUsPFlt_Ext_tUsPFlt(&ThMgt_RE002_Ext_tUsPFlt_in);
      (void)Rte_Read_R_Ext_tUsThrMes_Ext_tUsThrMes(&ThMgt_RE002_Ext_tUsThrMes_in);
      (void)Rte_Read_R_Ext_tVSS_Ext_tVSS(&ThMgt_RE002_Ext_tVSS_in);
      (void)Rte_Read_R_PhyM_tTrbCaseEstim_PhyM_tTrbCaseEstim(&ThMgt_RE002_PhyM_tTrbCaseEstim_in);
      (void)Rte_Read_R_ShdFlap_stPosn_ShdFlap_stPosn(&ThMgt_RE002_ShdFlap_stPosn_in);
      (void)Rte_Read_R_ShwRm_bAcvFSF_ShwRm_bAcvFSF(&ThMgt_RE002_ShwRm_bAcvFSF_in);
      (void)Rte_Read_R_Stg_tSysStrWhl_Stg_tSysStrWhl(&ThMgt_RE002_Stg_tSysStrWhl_in);
      (void)Rte_Read_R_TqCmp_bOpFSFReq_tAir_TqCmp_bOpFSFReq_tAir(&ThMgt_RE002_TqCmp_bOpFSFReq_tAir_in);
      (void)Rte_Read_R_Veh_bHeatReq_Veh_bHeatReq(&ThMgt_RE002_Veh_bHeatReq_in);
      (void)Rte_Read_R_Veh_bHeatWaPmpReq_Veh_bHeatWaPmpReq(&ThMgt_RE002_Veh_bHeatWaPmpReq_in);
      (void)Rte_Read_R_Veh_stHeatCoFlowReq_Veh_stHeatCoFlowReq(&ThMgt_RE002_Veh_stHeatCoFlowReq_in);
      (void)Rte_Read_R_ThMgt_wThFil_ThMgt_wThFil(&ThMgt_RE002_ThMgt_wThFil_in);
      (void)Rte_Read_R_CoPt_rSpdFanReqProtManClu_CoPt_rSpdFanReqProtManClu(&ThMgt_RE002_CoPt_rSpdFanReqProtManClu_in);
      (void)Rte_Read_R_RvAltMgt_tRvAltStatEstim_RvAltMgt_tRvAltStatEstim(&ThMgt_RE002_RvAltMgt_tRvAltStatEstim_in);
      (void)Rte_Read_R_WaTEst_rErrTCo_WaTEst_rErrTCo(&ThMgt_RE002_WaTEst_rErrTCo_in);
      (void)Rte_Read_R_WaTEst_tMtlEngEstim_WaTEst_tMtlEngEstim(&ThMgt_RE002_WaTEst_tMtlEngEstim_in);
      (void)Rte_Read_R_IgSys_bAcvLoTCoRegKnk_IgSys_bAcvLoTCoRegKnk(&ThMgt_RE002_IgSys_bAcvLoTCoRegKnk_in);
      (void)Rte_Read_R_InThM_tAirUsInVlvEstim_InThM_tAirUsInVlvEstim(&ThMgt_RE002_InThM_tAirUsInVlvEstim_in);
      RE002_AntiBoil_tCoMesFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_AntiBoil_tCoMesFil();
      RE002_CmptFil_agStrWhlFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_CmptFil_agStrWhlFil();
      RE002_CmptFil_agvStrWhlFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_CmptFil_agvStrWhlFil();
      RE002_EGRCo_bOpCoVlvReq_in = Rte_IrvRead_RE_ThMgt_002_TEV_EGRCo_bOpCoVlvReq();
      RE002_EGRCo_stSpdCoVlvReq_in = Rte_IrvRead_RE_ThMgt_002_TEV_EGRCo_stSpdCoVlvReq();
      RE002_TPMByp_bExThermoProt_in = Rte_IrvRead_RE_ThMgt_002_TEV_TPMByp_bExThermoProt();
      RE002_ESLimByp_bAcvTrqLim_in = Rte_IrvRead_RE_ThMgt_002_TEV_ESLimByp_bAcvTrqLim();
      RE002_ExtByp_nEng_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_nEng();
      RE002_ExtByp_pAirExtMes_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_pAirExtMes();
      RE002_ExtByp_spdVeh_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_spdVeh();
      RE002_FRMByp_bAcvTrbWaPmp_in = Rte_IrvRead_RE_ThMgt_002_TEV_FRMByp_bAcvTrbWaPmp();
      RE002_InpClc_bEngRun_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_bEngRun();
      RE002_InpClc_bEngStop_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_bEngStop();
      RE002_InpClc_bPFltRgnReq_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_bPFltRgnReq();
      RE002_InpClc_tqIdcEstim_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_tqIdcEstim();
      RE002_InpClc_tqIdcFld_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_tqIdcFld();
      RE002_PFltByp_bPFltRgnSrvReq_in = Rte_IrvRead_RE_ThMgt_002_TEV_PFltByp_bPFltRgnSrvReq();
      RE002_PwtFil_nEngFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_PwtFil_nEngFil();
      RE002_PwtFil_tCoRegFil1_in = Rte_IrvRead_RE_ThMgt_002_TEV_PwtFil_tCoRegFil1();
      RE002_PwtFil_tCoRegFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_PwtFil_tCoRegFil2();
      RE002_PwtFil_tqIdcEstimFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_PwtFil_tqIdcEstimFil();
      RE002_ThEClc_wThFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_ThEClc_wThFil2();
      RE002_TRegClc_bEngWrm_in = Rte_IrvRead_RE_ThMgt_002_TEV_TRegClc_bEngWrm();
      RE002_TRegClc_bHiEngLd_in = Rte_IrvRead_RE_ThMgt_002_TEV_TRegClc_bHiEngLd();
      RE002_TRegClc_bModRegCoVlv_in = Rte_IrvRead_RE_ThMgt_002_TEV_TRegClc_bModRegCoVlv();
      RE002_TRegClc_tCoRegCoVlv_in = Rte_IrvRead_RE_ThMgt_002_TEV_TRegClc_tCoRegCoVlv();
      RE002_TRegClc_tCoRegECT_in = Rte_IrvRead_RE_ThMgt_002_TEV_TRegClc_tCoRegECT();
      RE002_UndHoFil_nEngFil1_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_nEngFil1();
      RE002_UndHoFil_nEngFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_nEngFil2();
      RE002_UndHoFil_spdVehFil1_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_spdVehFil1();
      RE002_UndHoFil_spdVehFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_spdVehFil2();
      RE002_UndHoFil_tAirExtMesFil1_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tAirExtMesFil1();
      RE002_UndHoFil_tAirExtMesFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tAirExtMesFil2();
      RE002_UndHoFil_tAirInMesFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tAirInMesFil();
      RE002_UndHoFil_tqIdcEstimFil1_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tqIdcEstimFil1();
      RE002_UndHoFil_tqIdcEstimFil2_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tqIdcEstimFil2();
      RE002_UndHoFil_tUsPFltFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_UndHoFil_tUsPFltFil();
      RE002_CoPtByp_bTqTx_in = Rte_IrvRead_RE_ThMgt_002_TEV_CoPtByp_bTqTx();
      RE002_CoPtByp_noEgdGearCord_in = Rte_IrvRead_RE_ThMgt_002_TEV_CoPtByp_noEgdGearCord();
      RE002_CoPtByp_stCpl_in = Rte_IrvRead_RE_ThMgt_002_TEV_CoPtByp_stCpl();
      RE002_EOMByp_stCmbTdOff_in = Rte_IrvRead_RE_ThMgt_002_TEV_EOMByp_stCmbTdOff();
      RE002_ExtByp_bFSFCf_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_bFSFCf();
      RE002_ExtByp_bKeyOff_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_bKeyOff();
      RE002_ExtByp_stGBxCf_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_stGBxCf();
      RE002_ExtByp_stVSSCf_in = Rte_IrvRead_RE_ThMgt_002_TEV_ExtByp_stVSSCf();
      RE002_FRMByp_bAcvNoEgdGearDft_in = Rte_IrvRead_RE_ThMgt_002_TEV_FRMByp_bAcvNoEgdGearDft();
      RE002_InpClc_bACCf_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_bACCf();
      RE002_InpClc_bPwtRun_in = Rte_IrvRead_RE_ThMgt_002_TEV_InpClc_bPwtRun();
      RE002_KnkMgtByp_ctRblInjCutOffPtl_in = Rte_IrvRead_RE_ThMgt_002_TEV_KnkMgtByp_ctRblInjCutOffPtl();
      RE002_OAMByp_rOilDil_in = Rte_IrvRead_RE_ThMgt_002_TEV_OAMByp_rOilDil();
      RE002_AntiBoil_bRatCorPwrFilIniDly_in = Rte_IrvRead_RE_ThMgt_002_TEV_AntiBoil_bRatCorPwrFilIniDly();
      RE002_TqSysByp_tqIdcAirReqGen_in = Rte_IrvRead_RE_ThMgt_002_TEV_TqSysByp_tqIdcAirReqGen();
      RE002_CmptFil_tCACFil_in = Rte_IrvRead_RE_ThMgt_002_TEV_CmptFil_tCACFil();
	  RE002_EOMByp_tiEngStop_in = Rte_IrvRead_RE_ThMgt_002_TEV_EOMByp_tiEngStop();
	  RE002_EngLimByp_tqIdcEngCur_in = Rte_IrvRead_RE_ThMgt_002_TEV_EngLimByp_tqIdcEngCur();
      Rte_Call_R_FRM_bAcvAdFan_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvAdFan_in);
      ThMgt_RE002_FRM_bAcvAdFan_in = !ThMgt_RE002_FRM_bAcvAdFan_in;
      Rte_Call_R_FRM_bAcvBattFan_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvBattFan_in);
      ThMgt_RE002_FRM_bAcvBattFan_in = !ThMgt_RE002_FRM_bAcvBattFan_in;
      Rte_Call_R_FRM_bAcvBoilLimChg_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvBoilLimChg_in);
      ThMgt_RE002_FRM_bAcvBoilLimChg_in = !ThMgt_RE002_FRM_bAcvBoilLimChg_in;
      Rte_Call_R_FRM_bAcvCoVlvMaxOp_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvCoVlvMaxOp_in);
      ThMgt_RE002_FRM_bAcvCoVlvMaxOp_in = !ThMgt_RE002_FRM_bAcvCoVlvMaxOp_in;
      Rte_Call_R_FRM_bAcvCoVlvOpByp_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvCoVlvOpByp_in);
      ThMgt_RE002_FRM_bAcvCoVlvOpByp_in = !ThMgt_RE002_FRM_bAcvCoVlvOpByp_in;
      Rte_Call_R_FRM_bAcvCoVlvOpHeat_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvCoVlvOpHeat_in);
      ThMgt_RE002_FRM_bAcvCoVlvOpHeat_in = !ThMgt_RE002_FRM_bAcvCoVlvOpHeat_in;
      Rte_Call_R_FRM_bAcvCoVlvOpRad_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvCoVlvOpRad_in);
      ThMgt_RE002_FRM_bAcvCoVlvOpRad_in = !ThMgt_RE002_FRM_bAcvCoVlvOpRad_in;
      Rte_Call_R_FRM_bAcvECUFan_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvECUFan_in);
      ThMgt_RE002_FRM_bAcvECUFan_in = !ThMgt_RE002_FRM_bAcvECUFan_in;
      Rte_Call_R_FRM_bAcvEHRPmp_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvEHRPmp_in);
      ThMgt_RE002_FRM_bAcvEHRPmp_in = !ThMgt_RE002_FRM_bAcvEHRPmp_in;
      Rte_Call_R_FRM_bAcvFanHiSpd_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvFanHiSpd_in);
      ThMgt_RE002_FRM_bAcvFanHiSpd_in = !ThMgt_RE002_FRM_bAcvFanHiSpd_in;
      Rte_Call_R_FRM_bAcvFanHiSpdRcvMod_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvFanHiSpdRcvMod_in);
      ThMgt_RE002_FRM_bAcvFanHiSpdRcvMod_in = !ThMgt_RE002_FRM_bAcvFanHiSpdRcvMod_in;
      Rte_Call_R_FRM_bAcvFanLoSpd_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvFanLoSpd_in);
      ThMgt_RE002_FRM_bAcvFanLoSpd_in = !ThMgt_RE002_FRM_bAcvFanLoSpd_in;
      Rte_Call_R_FRM_bAcvHeatWaPmp_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvHeatWaPmp_in);
      ThMgt_RE002_FRM_bAcvHeatWaPmp_in = !ThMgt_RE002_FRM_bAcvHeatWaPmp_in;
      Rte_Call_R_FRM_bAcvLoTCoReg_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvLoTCoReg_in);
      ThMgt_RE002_FRM_bAcvLoTCoReg_in = !ThMgt_RE002_FRM_bAcvLoTCoReg_in;
      Rte_Call_R_FRM_bAcvLoThdACCmprOff_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvLoThdACCmprOff_in);
      ThMgt_RE002_FRM_bAcvLoThdACCmprOff_in = !ThMgt_RE002_FRM_bAcvLoThdACCmprOff_in;
      Rte_Call_R_FRM_bAcvLoThdTCoWarn_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvLoThdTCoWarn_in);
      ThMgt_RE002_FRM_bAcvLoThdTCoWarn_in = !ThMgt_RE002_FRM_bAcvLoThdTCoWarn_in;
      Rte_Call_R_FRM_bAcvOpFSF_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvOpFSF_in);
      ThMgt_RE002_FRM_bAcvOpFSF_in = !ThMgt_RE002_FRM_bAcvOpFSF_in;
      Rte_Call_R_FRM_bAcvTCoWarn_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvTCoWarn_in);
      ThMgt_RE002_FRM_bAcvTCoWarn_in = !ThMgt_RE002_FRM_bAcvTCoWarn_in;
      Rte_Call_R_FRM_bAcvThMgtRcvModTAlt_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvModTAlt_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvModTAlt_in = !ThMgt_RE002_FRM_bAcvThMgtRcvModTAlt_in;
      Rte_Call_R_FRM_bAcvThMgtRcvModTECU_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvModTECU_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvModTECU_in = !ThMgt_RE002_FRM_bAcvThMgtRcvModTECU_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTAirExt_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvValTAirExt_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvValTAirExt_in = !ThMgt_RE002_FRM_bAcvThMgtRcvValTAirExt_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTAirIn_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvValTAirIn_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvValTAirIn_in = !ThMgt_RE002_FRM_bAcvThMgtRcvValTAirIn_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTCAC_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvValTCAC_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvValTCAC_in = !ThMgt_RE002_FRM_bAcvThMgtRcvValTCAC_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTEg_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvValTEg_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvValTEg_in = !ThMgt_RE002_FRM_bAcvThMgtRcvValTEg_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTUsPFlt_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvThMgtRcvValTUsPFlt_in);
      ThMgt_RE002_FRM_bAcvThMgtRcvValTUsPFlt_in = !ThMgt_RE002_FRM_bAcvThMgtRcvValTUsPFlt_in;
      Rte_Call_R_FRM_bAcvVeryLoTCoReg_GetFunctionPermission(&ThMgt_RE002_FRM_bAcvVeryLoTCoReg_in);
      ThMgt_RE002_FRM_bAcvVeryLoTCoReg_in = !ThMgt_RE002_FRM_bAcvVeryLoTCoReg_in;
      Rte_Call_R_FRM_bDeacCoBoilLim_GetFunctionPermission(&ThMgt_RE002_FRM_bDeacCoBoilLim_in);
      ThMgt_RE002_FRM_bDeacCoBoilLim_in = !ThMgt_RE002_FRM_bDeacCoBoilLim_in;
      Rte_Call_R_FRM_bDeacCoVlv_GetFunctionPermission(&ThMgt_RE002_FRM_bDeacCoVlv_in);
      ThMgt_RE002_FRM_bDeacCoVlv_in = !ThMgt_RE002_FRM_bDeacCoVlv_in;
      Rte_Call_R_FRM_bDiMoveFSFReq_GetFunctionPermission(&ThMgt_RE002_FRM_bDiMoveFSFReq_in);
      ThMgt_RE002_FRM_bDiMoveFSFReq_in = !ThMgt_RE002_FRM_bDiMoveFSFReq_in;
      Rte_Call_R_FRM_bInhCTICoHeat_GetFunctionPermission(&ThMgt_RE002_FRM_bInhCTICoHeat_in);
      ThMgt_RE002_FRM_bInhCTICoHeat_in = !ThMgt_RE002_FRM_bInhCTICoHeat_in;
      Rte_Call_R_FRM_bInhDiagCoBoilLim_GetFunctionPermission(&ThMgt_RE002_FRM_bInhDiagCoBoilLim_in);
      ThMgt_RE002_FRM_bInhDiagCoBoilLim_in = !ThMgt_RE002_FRM_bInhDiagCoBoilLim_in;
      Rte_Call_R_FRM_bInhDiagFctFSF_GetFunctionPermission(&ThMgt_RE002_FRM_bInhDiagFctFSF_in);
      ThMgt_RE002_FRM_bInhDiagFctFSF_in = !ThMgt_RE002_FRM_bInhDiagFctFSF_in;
      Rte_Call_R_FRM_bInhDiagTCoWarn_GetFunctionPermission(&ThMgt_RE002_FRM_bInhDiagTCoWarn_in);
      ThMgt_RE002_FRM_bInhDiagTCoWarn_in = !ThMgt_RE002_FRM_bInhDiagTCoWarn_in;
      Rte_Call_R_FRM_bInhECTPwrLim_GetFunctionPermission(&ThMgt_RE002_FRM_bInhECTPwrLim_in);
      ThMgt_RE002_FRM_bInhECTPwrLim_in = !ThMgt_RE002_FRM_bInhECTPwrLim_in;
      Rte_Call_R_FRM_bInhEHRPmp_GetFunctionPermission(&ThMgt_RE002_FRM_bInhEHRPmp_in);
      ThMgt_RE002_FRM_bInhEHRPmp_in = !ThMgt_RE002_FRM_bInhEHRPmp_in;
      Rte_Call_R_FRM_bInhHeatReqMainWaPmp_GetFunctionPermission(&ThMgt_RE002_FRM_bInhHeatReqMainWaPmp_in);
      ThMgt_RE002_FRM_bInhHeatReqMainWaPmp_in = !ThMgt_RE002_FRM_bInhHeatReqMainWaPmp_in;
      Rte_Call_R_FRM_bInhHeatWaPmp_GetFunctionPermission(&ThMgt_RE002_FRM_bInhHeatWaPmp_in);
      ThMgt_RE002_FRM_bInhHeatWaPmp_in = !ThMgt_RE002_FRM_bInhHeatWaPmp_in;
      Rte_Call_R_FRM_bInhIdlIncCoHeat_GetFunctionPermission(&ThMgt_RE002_FRM_bInhIdlIncCoHeat_in);
      ThMgt_RE002_FRM_bInhIdlIncCoHeat_in = !ThMgt_RE002_FRM_bInhIdlIncCoHeat_in;
      Rte_Call_R_FRM_bInhTCoBlockDiag_GetFunctionPermission(&ThMgt_RE002_FRM_bInhTCoBlockDiag_in);
      ThMgt_RE002_FRM_bInhTCoBlockDiag_in = !ThMgt_RE002_FRM_bInhTCoBlockDiag_in;
      Rte_Call_R_FRM_bInhTCoColdDiag_GetFunctionPermission(&ThMgt_RE002_FRM_bInhTCoColdDiag_in);
      ThMgt_RE002_FRM_bInhTCoColdDiag_in = !ThMgt_RE002_FRM_bInhTCoColdDiag_in;
      Rte_Call_R_FRM_bInhTCoMdlCompDiag_GetFunctionPermission(&ThMgt_RE002_FRM_bInhTCoMdlCompDiag_in);
      ThMgt_RE002_FRM_bInhTCoMdlCompDiag_in = !ThMgt_RE002_FRM_bInhTCoMdlCompDiag_in;
      Rte_Call_R_FRM_bInhTCoRiseDiag_GetFunctionPermission(&ThMgt_RE002_FRM_bInhTCoRiseDiag_in);
      ThMgt_RE002_FRM_bInhTCoRiseDiag_in = !ThMgt_RE002_FRM_bInhTCoRiseDiag_in;
      Rte_Call_R_FRM_bInhThermoDiag1_GetFunctionPermission(&ThMgt_RE002_FRM_bInhThermoDiag1_in);
      ThMgt_RE002_FRM_bInhThermoDiag1_in = !ThMgt_RE002_FRM_bInhThermoDiag1_in;
      ThMgt_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      ThMgt_bMainWaPmpSt_out = ThMgt_bMainWaPmpSt_B;
      ThMgt_bPwrHldAdFanReq_out = ThMgt_bPwrHldAdFanReq_B;
      ThMgt_bPwrHldTrbWaPmpReq_out = ThMgt_bPwrHldTrbWaPmpReq_B;
      ThMgt_rCoHeatReq_out = ThMgt_rCoHeatReq_B;
      ThMgt_rPwrECTReq_out = ThMgt_rPwrECTReq_B;
      ThMgt_bACCmprOffReq_out = ThMgt_bACCmprOffReq_B;
      ThMgt_bAcvR1234Mgt_out = ThMgt_bAcvR1234Mgt_B;
      ThMgt_bAdFanReq_out = ThMgt_bAdFanReq_B;
      ThMgt_bBattFanReq_out = ThMgt_bBattFanReq_B;
      ThMgt_bECTAftsReq_out = ThMgt_bECTAftsReq_B;
      ThMgt_bECUFanReq_out = ThMgt_bECUFanReq_B;
      ThMgt_bEHRHeatReq_out = ThMgt_bEHRHeatReq_B;
      ThMgt_bEHRWaPmpReq_out = ThMgt_bEHRWaPmpReq_B;
      ThMgt_bEndCtlCoVlv_out = ThMgt_bEndCtlCoVlv_B;
      ThMgt_bHeatWaPmpReq_out = ThMgt_bHeatWaPmpReq_B;
      ThMgt_bHldPosnCoVlvReq_out = ThMgt_bHldPosnCoVlvReq_B;
      ThMgt_bMainWaPmpReq_out = ThMgt_bMainWaPmpReq_B;
      ThMgt_bPosnFSF_out = ThMgt_bPosnFSF_B;
      ThMgt_bPwrHldCoVlvReq_out = ThMgt_bPwrHldCoVlvReq_B;
      ThMgt_bPwrHldFSFReq_out = ThMgt_bPwrHldFSFReq_B;
      ThMgt_bPwrHldMainFanReq_out = ThMgt_bPwrHldMainFanReq_B;
      ThMgt_bRstrtReq_out = ThMgt_bRstrtReq_B;
      ThMgt_bTCoWarnReq_out = ThMgt_bTCoWarnReq_B;
      ThMgt_bTrbWaPmpReq_out = ThMgt_bTrbWaPmpReq_B;
      ThMgt_nTarIdlHeatReq_out = ThMgt_nTarIdlHeatReq_B;
      ThMgt_rOpBypCoVlvReq_out = ThMgt_rOpBypCoVlvReq_B;
      ThMgt_rOpHeatCoVlvReq_out = ThMgt_rOpHeatCoVlvReq_B;
      ThMgt_rOpRadCoVlvReq_out = ThMgt_rOpRadCoVlvReq_B;
      ThMgt_rSpdFanReq_out = ThMgt_rSpdFanReq_B;
      ThMgt_stPosnCoVlvEstim_out = ThMgt_stPosnCoVlvEstim_B;
      ThMgt_stPosnFSFReq_out = ThMgt_stPosnFSFReq_B;
      ThMgt_stSpdCoVlvReq_out = ThMgt_stSpdCoVlvReq_B;
      ThMgt_tECTReq_out = ThMgt_tECTReq_B;
      ThMgt_tiAcvTrbWaPmpEngStop_out = ThMgt_tiAcvTrbWaPmpEngStop_B;
      ThMgt_bIncVoltReq_out = ThMgt_bIncVoltReq_B;
   }
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_AntiBoil_rCorPwrFil(RE002_AntiBoil_rCorPwrFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_AtyModMgt_bLoTCoRegReq(RE002_AtyModMgt_bLoTCoRegReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_AtyModMgt_tECTReq(RE002_AtyModMgt_tECTReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_CoAftsMgt_tECTAftsReq(RE002_CoAftsMgt_tECTAftsReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tAirExtMes(RE002_ExtByp_tAirExtMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tCoMes(RE002_ExtByp_tCoMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tCoMesFineResl2(RE002_ExtByp_tCoMesFineResl2_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tECTSp(RE002_ExtByp_tECTSp_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tUsPFlt(RE002_ExtByp_tUsPFlt_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bAcvBoilLimChg(RE002_FRMByp_bAcvBoilLimChg_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bAcvLoTCoReg(RE002_FRMByp_bAcvLoTCoReg_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bAcvVeryLoTCoReg(RE002_FRMByp_bAcvVeryLoTCoReg_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bDeacCoBoilLim(RE002_FRMByp_bDeacCoBoilLim_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bInhDiagCoBoilLim(RE002_FRMByp_bInhDiagCoBoilLim_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_InpClc_tAirInMes(RE002_InpClc_tAirInMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_InpClc_tEg(RE002_InpClc_tEg_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_UndHoTMgt_bLoTCoRegReq(RE002_UndHoTMgt_bLoTCoRegReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_UndHoTMgt_tECTReq(RE002_UndHoTMgt_tECTReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tAirUsCmprMes(RE002_ExtByp_tAirUsCmprMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tDsThrMes(RE002_ExtByp_tDsThrMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tFuMes(RE002_ExtByp_tFuMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tOilMes(RE002_ExtByp_tOilMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_ExtByp_tUsThrMes(RE002_ExtByp_tUsThrMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_FRMByp_bInhTCoColdDiag(RE002_FRMByp_bInhTCoColdDiag_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_CoVlvCtl_bRstStopHldDly(RE002_CoVlvCtl_bRstStopHldDly_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_GBxCo_tECTReqDly(RE002_GBxCo_tECTReqDly_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_IgSysByp_bAcvLoTCoRegKnk(RE002_IgSysByp_bAcvLoTCoRegKnk_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_InThMByp_tAirUsInVlvEstim(RE002_InThMByp_tAirUsInVlvEstim_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_OilDilProt_bLoTCoRegReq(RE002_OilDilProt_bLoTCoRegReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_002_TEV_InpClc_tCAC(RE002_InpClc_tCAC_out);
   (void)Rte_Write_P_ThMgt_bMainWaPmpSt_ThMgt_bMainWaPmpSt(ThMgt_bMainWaPmpSt_out);
   (void)Rte_Write_P_ThMgt_bPwrHldAdFanReq_ThMgt_bPwrHldAdFanReq(ThMgt_bPwrHldAdFanReq_out);
   (void)Rte_Write_P_ThMgt_bPwrHldTrbWaPmpReq_ThMgt_bPwrHldTrbWaPmpReq(ThMgt_bPwrHldTrbWaPmpReq_out);
   (void)Rte_Write_P_ThMgt_rCoHeatReq_ThMgt_rCoHeatReq(ThMgt_rCoHeatReq_out);
   (void)Rte_Write_P_ThMgt_rPwrECTReq_ThMgt_rPwrECTReq(ThMgt_rPwrECTReq_out);
   (void)Rte_Write_P_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq(ThMgt_bACCmprOffReq_out);
   (void)Rte_Write_P_ThMgt_bAcvR1234Mgt_ThMgt_bAcvR1234Mgt(ThMgt_bAcvR1234Mgt_out);
   (void)Rte_Write_P_ThMgt_bAdFanReq_ThMgt_bAdFanReq(ThMgt_bAdFanReq_out);
   (void)Rte_Write_P_ThMgt_bBattFanReq_ThMgt_bBattFanReq(ThMgt_bBattFanReq_out);
   (void)Rte_Write_P_ThMgt_bECTAftsReq_ThMgt_bECTAftsReq(ThMgt_bECTAftsReq_out);
   (void)Rte_Write_P_ThMgt_bECUFanReq_ThMgt_bECUFanReq(ThMgt_bECUFanReq_out);
   (void)Rte_Write_P_ThMgt_bEHRHeatReq_ThMgt_bEHRHeatReq(ThMgt_bEHRHeatReq_out);
   (void)Rte_Write_P_ThMgt_bEHRWaPmpReq_ThMgt_bEHRWaPmpReq(ThMgt_bEHRWaPmpReq_out);
   (void)Rte_Write_P_ThMgt_bEndCtlCoVlv_ThMgt_bEndCtlCoVlv(ThMgt_bEndCtlCoVlv_out);
   (void)Rte_Write_P_ThMgt_bHeatWaPmpReq_ThMgt_bHeatWaPmpReq(ThMgt_bHeatWaPmpReq_out);
   (void)Rte_Write_P_ThMgt_bHldPosnCoVlvReq_ThMgt_bHldPosnCoVlvReq(ThMgt_bHldPosnCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_bMainWaPmpReq_ThMgt_bMainWaPmpReq(ThMgt_bMainWaPmpReq_out);
   (void)Rte_Write_P_ThMgt_bPosnFSF_ThMgt_bPosnFSF(ThMgt_bPosnFSF_out);
   (void)Rte_Write_P_ThMgt_bPwrHldCoVlvReq_ThMgt_bPwrHldCoVlvReq(ThMgt_bPwrHldCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_bPwrHldFSFReq_ThMgt_bPwrHldFSFReq(ThMgt_bPwrHldFSFReq_out);
   (void)Rte_Write_P_ThMgt_bPwrHldMainFanReq_ThMgt_bPwrHldMainFanReq(ThMgt_bPwrHldMainFanReq_out);
   (void)Rte_Write_P_ThMgt_bRstrtReq_ThMgt_bRstrtReq(ThMgt_bRstrtReq_out);
   (void)Rte_Write_P_ThMgt_bTCoWarnReq_ThMgt_bTCoWarnReq(ThMgt_bTCoWarnReq_out);
   (void)Rte_Write_P_ThMgt_bTrbWaPmpReq_ThMgt_bTrbWaPmpReq(ThMgt_bTrbWaPmpReq_out);
   (void)Rte_Write_P_ThMgt_nTarIdlHeatReq_ThMgt_nTarIdlHeatReq(ThMgt_nTarIdlHeatReq_out);
   (void)Rte_Write_P_ThMgt_rOpBypCoVlvReq_ThMgt_rOpBypCoVlvReq(ThMgt_rOpBypCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_rOpHeatCoVlvReq_ThMgt_rOpHeatCoVlvReq(ThMgt_rOpHeatCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_rOpRadCoVlvReq_ThMgt_rOpRadCoVlvReq(ThMgt_rOpRadCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_rSpdFanReq_ThMgt_rSpdFanReq(ThMgt_rSpdFanReq_out);
   (void)Rte_Write_P_ThMgt_stPosnCoVlvEstim_ThMgt_stPosnCoVlvEstim(ThMgt_stPosnCoVlvEstim_out);
   (void)Rte_Write_P_ThMgt_stPosnFSFReq_ThMgt_stPosnFSFReq(ThMgt_stPosnFSFReq_out);
   (void)Rte_Write_P_ThMgt_stSpdCoVlvReq_ThMgt_stSpdCoVlvReq(ThMgt_stSpdCoVlvReq_out);
   (void)Rte_Write_P_ThMgt_tECTReq_ThMgt_tECTReq(ThMgt_tECTReq_out);
   (void)Rte_Write_P_ThMgt_tiAcvTrbWaPmpEngStop_ThMgt_tiAcvTrbWaPmpEngStop(ThMgt_tiAcvTrbWaPmpEngStop_out);
   (void)Rte_Write_P_ThMgt_bIncVoltReq_ThMgt_bIncVoltReq(ThMgt_bIncVoltReq_out);

   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_CoSysDfct */
      if(ThMgt_bMonRunCoSysDfct_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoCoSysDfct_out==1)
         {
            Rte_Call_R_ThMgt_CoSysDfct_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_CoSysDfct_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunCoSysDfct_out_prec==1)
         {
            Rte_Call_R_ThMgt_CoSysDfct_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunCoSysDfct_out_prec = ThMgt_bMonRunCoSysDfct_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_FSFBlockCls */
      if(ThMgt_bMonRunFSFBlockCls_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoFSFBlockCls_out==1)
         {
            Rte_Call_R_ThMgt_FSFBlockCls_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_FSFBlockCls_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunFSFBlockCls_out_prec==1)
         {
            Rte_Call_R_ThMgt_FSFBlockCls_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunFSFBlockCls_out_prec = ThMgt_bMonRunFSFBlockCls_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_FSFBlockOp */
      if(ThMgt_bMonRunFSFBlockOp_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoFSFBlockOp_out==1)
         {
            Rte_Call_R_ThMgt_FSFBlockOp_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_FSFBlockOp_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunFSFBlockOp_out_prec==1)
         {
            Rte_Call_R_ThMgt_FSFBlockOp_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunFSFBlockOp_out_prec = ThMgt_bMonRunFSFBlockOp_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_TCoBlock */
      if(ThMgt_bMonRunTCoBlock_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoTCoBlock_out==1)
         {
            Rte_Call_R_ThMgt_TCoBlock_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_TCoBlock_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunTCoBlock_out_prec==1)
         {
            Rte_Call_R_ThMgt_TCoBlock_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunTCoBlock_out_prec = ThMgt_bMonRunTCoBlock_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_TCoSlowRise */
      if(ThMgt_bMonRunTCoSlowRise_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoTCoSlowRise_out==1)
         {
            Rte_Call_R_ThMgt_TCoSlowRise_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_TCoSlowRise_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunTCoSlowRise_out_prec==1)
         {
            Rte_Call_R_ThMgt_TCoSlowRise_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunTCoSlowRise_out_prec = ThMgt_bMonRunTCoSlowRise_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_TCoWarn */
      if(ThMgt_bMonRunTCoWarn_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoTCoWarn_out==1)
         {
            Rte_Call_R_ThMgt_TCoWarn_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_TCoWarn_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunTCoWarn_out_prec==1)
         {
            Rte_Call_R_ThMgt_TCoWarn_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunTCoWarn_out_prec = ThMgt_bMonRunTCoWarn_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_ThermoStuckCls */
      if(ThMgt_bMonRunThermoStuckCls_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoThermoStuckCls_out==1)
         {
            Rte_Call_R_ThMgt_ThermoStuckCls_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_ThermoStuckCls_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunThermoStuckCls_out_prec==1)
         {
            Rte_Call_R_ThMgt_ThermoStuckCls_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunThermoStuckCls_out_prec = ThMgt_bMonRunThermoStuckCls_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_ThermoStuckOp */
      if(ThMgt_bMonRunThermoStuckOp_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoThermoStuckOp_out==1)
         {
            Rte_Call_R_ThMgt_ThermoStuckOp_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_ThermoStuckOp_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunThermoStuckOp_out_prec==1)
         {
            Rte_Call_R_ThMgt_ThermoStuckOp_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunThermoStuckOp_out_prec = ThMgt_bMonRunThermoStuckOp_out;
   }
}

void RE_ThMgt_003_TEV(void)
{
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPtFH_stPwt_CoPtFH_stPwt(&ThMgt_RE003_CoPtFH_stPwt_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&ThMgt_RE003_CoPTSt_stEng_in);
      (void)Rte_Read_R_Ext_bACCf_Ext_bACCf(&ThMgt_RE003_Ext_bACCf_in);
      (void)Rte_Read_R_Ext_bFSFCf_Ext_bFSFCf(&ThMgt_RE003_Ext_bFSFCf_in);
      (void)Rte_Read_R_Ext_bKeyOff_Ext_bKeyOff(&ThMgt_RE003_Ext_bKeyOff_in);
      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&ThMgt_RE003_Ext_spdVeh_in);
      (void)Rte_Read_R_Ext_stACTypCf_Ext_stACTypCf(&ThMgt_RE003_Ext_stACTypCf_in);
      (void)Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&ThMgt_RE003_Ext_stVSSCf_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ThMgt_RE003_Ext_stGBxCf_in);
      RE003_AtyModMgt_bLoTCoRegReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_AtyModMgt_bLoTCoRegReq();
      RE003_AtyModMgt_tECTReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_AtyModMgt_tECTReq();
      RE003_CoAftsMgt_tECTAftsReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_CoAftsMgt_tECTAftsReq();
      RE003_EGRVlvByp_rOp_in = Rte_IrvRead_RE_ThMgt_003_TEV_EGRVlvByp_rOp();
      RE003_EngMByp_mfDsEGRCoEstim_in = Rte_IrvRead_RE_ThMgt_003_TEV_EngMByp_mfDsEGRCoEstim();
      RE003_EngMByp_mfEgEstim_in = Rte_IrvRead_RE_ThMgt_003_TEV_EngMByp_mfEgEstim();
      RE003_ExtByp_nEng_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_nEng();
      RE003_ExtByp_tAirExtMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tAirExtMes();
      RE003_ExtByp_tCoMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tCoMes();
      RE003_ExtByp_tECTSp_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tECTSp();
      RE003_ExtByp_tUsPFlt_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tUsPFlt();
      RE003_FRMByp_bAcvLoTCoReg_in = Rte_IrvRead_RE_ThMgt_003_TEV_FRMByp_bAcvLoTCoReg();
      RE003_FRMByp_bAcvVeryLoTCoReg_in = Rte_IrvRead_RE_ThMgt_003_TEV_FRMByp_bAcvVeryLoTCoReg();
      RE003_InpClc_tAirInMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_InpClc_tAirInMes();
      RE003_InpClc_tEg_in = Rte_IrvRead_RE_ThMgt_003_TEV_InpClc_tEg();
      RE003_InpClc_tqIdcEstim_in = Rte_IrvRead_RE_ThMgt_003_TEV_InpClc_tqIdcEstim();
      RE003_StgByp_agStrWhl_in = Rte_IrvRead_RE_ThMgt_003_TEV_StgByp_agStrWhl();
      RE003_StgByp_agvStrWhl_in = Rte_IrvRead_RE_ThMgt_003_TEV_StgByp_agvStrWhl();
      RE003_UndHoTMgt_bLoTCoRegReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_UndHoTMgt_bLoTCoRegReq();
      RE003_UndHoTMgt_tECTReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_UndHoTMgt_tECTReq();
      RE003_AirSysByp_rOpEGRCoBypReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_AirSysByp_rOpEGRCoBypReq();
      RE003_EOMByp_tiEngStop_in = Rte_IrvRead_RE_ThMgt_003_TEV_EOMByp_tiEngStop();
      RE003_ExtByp_tAirUsCmprMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tAirUsCmprMes();
      RE003_ExtByp_tDsThrMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tDsThrMes();
      RE003_ExtByp_tFuMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tFuMes();
      RE003_ExtByp_tOilMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tOilMes();
      RE003_ExtByp_tUsThrMes_in = Rte_IrvRead_RE_ThMgt_003_TEV_ExtByp_tUsThrMes();
      RE003_FRMByp_bInhTCoColdDiag_in = Rte_IrvRead_RE_ThMgt_003_TEV_FRMByp_bInhTCoColdDiag();
      RE003_AntiBoil_tECTReqDly_in = Rte_IrvRead_RE_ThMgt_003_TEV_AntiBoil_tECTReqDly();
      RE003_CoVlvCtl_bRstStopHldDly_in = Rte_IrvRead_RE_ThMgt_003_TEV_CoVlvCtl_bRstStopHldDly();
      RE003_GBxCo_tECTReqDly_in = Rte_IrvRead_RE_ThMgt_003_TEV_GBxCo_tECTReqDly();
      RE003_KnkProt_tECTAdpReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_KnkProt_tECTAdpReq();
      RE003_KnkProt_tECTTAirReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_KnkProt_tECTTAirReq();
      RE003_OilDilProt_bLoTCoRegReq_in = Rte_IrvRead_RE_ThMgt_003_TEV_OilDilProt_bLoTCoRegReq();
      RE003_InpClc_tCAC_in = Rte_IrvRead_RE_ThMgt_003_TEV_InpClc_tCAC();

      ThMgt_003_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      ThMgt_wThFil_out = ThMgt_wThFil_B;
      ThMgt_tCoReg_out = ThMgt_tCoReg_B;
   }
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_CmptFil_agStrWhlFil(RE003_CmptFil_agStrWhlFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_CmptFil_agvStrWhlFil(RE003_CmptFil_agvStrWhlFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_EGRCo_bOpCoVlvReq(RE003_EGRCo_bOpCoVlvReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_EGRCo_stSpdCoVlvReq(RE003_EGRCo_stSpdCoVlvReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ExtByp_spdVeh(RE003_ExtByp_spdVeh_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_InpClc_bEngRun(RE003_InpClc_bEngRun_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_InpClc_bEngStop(RE003_InpClc_bEngStop_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_PwtFil_nEngFil(RE003_PwtFil_nEngFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_PwtFil_tCoRegFil1(RE003_PwtFil_tCoRegFil1_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_PwtFil_tCoRegFil2(RE003_PwtFil_tCoRegFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_PwtFil_tqIdcEstimFil(RE003_PwtFil_tqIdcEstimFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ThEClc_wThFil2(RE003_ThEClc_wThFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_TRegClc_bEngWrm(RE003_TRegClc_bEngWrm_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_TRegClc_bHiEngLd(RE003_TRegClc_bHiEngLd_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_TRegClc_bModRegCoVlv(RE003_TRegClc_bModRegCoVlv_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_TRegClc_tCoRegCoVlv(RE003_TRegClc_tCoRegCoVlv_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_TRegClc_tCoRegECT(RE003_TRegClc_tCoRegECT_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_nEngFil1(RE003_UndHoFil_nEngFil1_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_nEngFil2(RE003_UndHoFil_nEngFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_spdVehFil1(RE003_UndHoFil_spdVehFil1_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_spdVehFil2(RE003_UndHoFil_spdVehFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tAirExtMesFil1(RE003_UndHoFil_tAirExtMesFil1_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tAirExtMesFil2(RE003_UndHoFil_tAirExtMesFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tAirInMesFil(RE003_UndHoFil_tAirInMesFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tqIdcEstimFil1(RE003_UndHoFil_tqIdcEstimFil1_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tqIdcEstimFil2(RE003_UndHoFil_tqIdcEstimFil2_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_UndHoFil_tUsPFltFil(RE003_UndHoFil_tUsPFltFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ExtByp_bFSFCf(RE003_ExtByp_bFSFCf_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ExtByp_bKeyOff(RE003_ExtByp_bKeyOff_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ExtByp_stGBxCf(RE003_ExtByp_stGBxCf_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_ExtByp_stVSSCf(RE003_ExtByp_stVSSCf_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_InpClc_bACCf(RE003_InpClc_bACCf_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_InpClc_bPwtRun(RE003_InpClc_bPwtRun_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_CmptFil_tCACFil(RE003_CmptFil_tCACFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_003_TEV_PwtFil_tCoRegFil3(RE003_PwtFil_tCoRegFil3_out);
   (void)Rte_Write_P_ThMgt_wThFil_ThMgt_wThFil(ThMgt_wThFil_out);
   (void)Rte_Write_P_ThMgt_tCoReg_ThMgt_tCoReg(ThMgt_tCoReg_out);

   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_TCoOverEstim */
      if(ThMgt_bMonRunTCoOverEstim_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoTCoOverEstim_out==1)
         {
            Rte_Call_R_ThMgt_TCoOverEstim_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_TCoOverEstim_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunTCoOverEstim_out_prec==1)
         {
            Rte_Call_R_ThMgt_TCoOverEstim_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunTCoOverEstim_out_prec = ThMgt_bMonRunTCoOverEstim_out;
   }
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_TCoUndEstim */
      if(ThMgt_bMonRunTCoUndEstim_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoTCoUndEstim_out==1)
         {
            Rte_Call_R_ThMgt_TCoUndEstim_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_TCoUndEstim_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunTCoUndEstim_out_prec==1)
         {
            Rte_Call_R_ThMgt_TCoUndEstim_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunTCoUndEstim_out_prec = ThMgt_bMonRunTCoUndEstim_out;
   }
}

void RE_ThMgt_004_TEV(void)
{
   if (FALSE == THMGT_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_EGRVlv_rOp_EGRVlv_rOp(&ThMgt_RE004_EGRVlv_rOp_in);
      (void)Rte_Read_R_TPM_bExThermoProt_TPM_bExThermoProt(&ThMgt_RE004_TPM_bExThermoProt_in);
      (void)Rte_Read_R_EngLim_tqIdcAdvOptmTrbMax_EngLim_tqIdcAdvOptmTrbMax(&ThMgt_RE004_EngLim_tqIdcAdvOptmTrbMax_in);
      (void)Rte_Read_R_EngLim_tqIdcFLdUnlim_EngLim_tqIdcFLdUnlim(&ThMgt_RE004_EngLim_tqIdcFLdUnlim_in);
      (void)Rte_Read_R_EngM_mfDsEGRCoEstim_EngM_mfDsEGRCoEstim(&ThMgt_RE004_EngM_mfDsEGRCoEstim_in);
      (void)Rte_Read_R_EngM_mfEgEstim_EngM_mfEgEstim(&ThMgt_RE004_EngM_mfEgEstim_in);
      (void)Rte_Read_R_EOM_stEngModReq_EOM_stEngModReq(&ThMgt_RE004_EOM_stEngModReq_in);
      (void)Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&ThMgt_RE004_EOM_tiEngStop_in);
      (void)Rte_Read_R_ESLim_bAcvTrqLim_ESLim_bAcvTrqLim(&ThMgt_RE004_ESLim_bAcvTrqLim_in);
      (void)Rte_Read_R_ExM_mfEgWoutEGR_ExM_mfEgWoutEGR(&ThMgt_RE004_ExM_mfEgWoutEGR_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&ThMgt_RE004_Ext_nEng_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&ThMgt_RE004_Ext_pAirExtMes_in);
      (void)Rte_Read_R_IgSys_tqIdcEstim_IgSys_tqIdcEstim(&ThMgt_RE004_IgSys_tqIdcEstim_in);
      (void)Rte_Read_R_PFlt_bPFltRgnReq_PFlt_bPFltRgnReq(&ThMgt_RE004_PFlt_bPFltRgnReq_in);
      (void)Rte_Read_R_PFlt_bPFltRgnSrvReq_PFlt_bPFltRgnSrvReq(&ThMgt_RE004_PFlt_bPFltRgnSrvReq_in);
      (void)Rte_Read_R_Stg_agStrWhl_Stg_agStrWhl(&ThMgt_RE004_Stg_agStrWhl_in);
      (void)Rte_Read_R_Stg_agvStrWhl_Stg_agvStrWhl(&ThMgt_RE004_Stg_agvStrWhl_in);
      (void)Rte_Read_R_TqEst_tqIdcEstim_TqEst_tqIdcEstim(&ThMgt_RE004_TqEst_tqIdcEstim_in);
      (void)Rte_Read_R_AirSys_rOpEGRCoBypReq_AirSys_rOpEGRCoBypReq(&ThMgt_RE004_AirSys_rOpEGRCoBypReq_in);
      (void)Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&ThMgt_RE004_CoPt_bTqTx_in);
      (void)Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&ThMgt_RE004_CoPt_noEgdGearCord_in);
      (void)Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&ThMgt_RE004_CoPt_stCpl_in);
      (void)Rte_Read_R_EOM_stCmbTdOff_EOM_stCmbTdOff(&ThMgt_RE004_EOM_stCmbTdOff_in);
      (void)Rte_Read_R_KnkMgt_prm_ctRblInjCutOffPtl_KnkMgt_prm_ctRblInjCutOffPtl(ThMgt_RE004_KnkMgt_prm_ctRblInjCutOffPtl_in);
      (void)Rte_Read_R_OAM_rOilDil_OAM_rOilDil(&ThMgt_RE004_OAM_rOilDil_in);
      (void)Rte_Read_R_ThMgt_tCoReg_ThMgt_tCoReg(&ThMgt_RE004_ThMgt_tCoReg_in);
      (void)Rte_Read_R_TqSys_tqIdcAirReqGen_TqSys_tqIdcAirReqGen(&ThMgt_RE004_TqSys_tqIdcAirReqGen_in);
	  (void)Rte_Read_R_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(&ThMgt_RE004_EngLim_tqIdcEngCur_in);
	  (void)Rte_Read_R_TqRes_tqMaxRes_TqRes_tqMaxRes(&ThMgt_RE004_TqRes_tqMaxRes_in);
      RE004_AntiBoil_rCorPwrFil_in = Rte_IrvRead_RE_ThMgt_004_TEV_AntiBoil_rCorPwrFil();
      RE004_ExtByp_spdVeh_in = Rte_IrvRead_RE_ThMgt_004_TEV_ExtByp_spdVeh();
      RE004_ExtByp_tAirExtMes_in = Rte_IrvRead_RE_ThMgt_004_TEV_ExtByp_tAirExtMes();
      RE004_ExtByp_tCoMesFineResl2_in = Rte_IrvRead_RE_ThMgt_004_TEV_ExtByp_tCoMesFineResl2();
      RE004_FRMByp_bAcvBoilLimChg_in = Rte_IrvRead_RE_ThMgt_004_TEV_FRMByp_bAcvBoilLimChg();
      RE004_FRMByp_bDeacCoBoilLim_in = Rte_IrvRead_RE_ThMgt_004_TEV_FRMByp_bDeacCoBoilLim();
      RE004_FRMByp_bInhDiagCoBoilLim_in = Rte_IrvRead_RE_ThMgt_004_TEV_FRMByp_bInhDiagCoBoilLim();
      RE004_InpClc_bEngRun_in = Rte_IrvRead_RE_ThMgt_004_TEV_InpClc_bEngRun();
      RE004_InpClc_bEngStop_in = Rte_IrvRead_RE_ThMgt_004_TEV_InpClc_bEngStop();
      RE004_IgSysByp_bAcvLoTCoRegKnk_in = Rte_IrvRead_RE_ThMgt_004_TEV_IgSysByp_bAcvLoTCoRegKnk();
      RE004_InThMByp_tAirUsInVlvEstim_in = Rte_IrvRead_RE_ThMgt_004_TEV_InThMByp_tAirUsInVlvEstim();
	  RE004_PwtFil_tCoRegFil3_in = Rte_IrvRead_RE_ThMgt_004_TEV_PwtFil_tCoRegFil3();

      Rte_Call_R_FRM_bAcvNoEgdGearDft_GetFunctionPermission(&ThMgt_RE004_FRM_bAcvNoEgdGearDft_in);
      ThMgt_RE004_FRM_bAcvNoEgdGearDft_in = !ThMgt_RE004_FRM_bAcvNoEgdGearDft_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValMfEg_GetFunctionPermission(&ThMgt_RE004_FRM_bAcvThMgtRcvValMfEg_in);
      ThMgt_RE004_FRM_bAcvThMgtRcvValMfEg_in = !ThMgt_RE004_FRM_bAcvThMgtRcvValMfEg_in;
      Rte_Call_R_FRM_bAcvThMgtRcvValTqIdc_GetFunctionPermission(&ThMgt_RE004_FRM_bAcvThMgtRcvValTqIdc_in);
      ThMgt_RE004_FRM_bAcvThMgtRcvValTqIdc_in = !ThMgt_RE004_FRM_bAcvThMgtRcvValTqIdc_in;
      Rte_Call_R_FRM_bAcvTrbWaPmp_GetFunctionPermission(&ThMgt_RE004_FRM_bAcvTrbWaPmp_in);
      ThMgt_RE004_FRM_bAcvTrbWaPmp_in = !ThMgt_RE004_FRM_bAcvTrbWaPmp_in;
      ThMgt_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      ThMgt_tqIdcLimReq_out = ThMgt_tqIdcLimReq_B;
   }
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_AntiBoil_tCoMesFil(RE004_AntiBoil_tCoMesFil_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EGRVlvByp_rOp(RE004_EGRVlvByp_rOp_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_TPMByp_bExThermoProt(RE004_TPMByp_bExThermoProt_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EngMByp_mfDsEGRCoEstim(RE004_EngMByp_mfDsEGRCoEstim_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EngMByp_mfEgEstim(RE004_EngMByp_mfEgEstim_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_ESLimByp_bAcvTrqLim(RE004_ESLimByp_bAcvTrqLim_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_ExtByp_nEng(RE004_ExtByp_nEng_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_ExtByp_pAirExtMes(RE004_ExtByp_pAirExtMes_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_FRMByp_bAcvTrbWaPmp(RE004_FRMByp_bAcvTrbWaPmp_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_InpClc_bPFltRgnReq(RE004_InpClc_bPFltRgnReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_InpClc_tqIdcEstim(RE004_InpClc_tqIdcEstim_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_InpClc_tqIdcFld(RE004_InpClc_tqIdcFld_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_PFltByp_bPFltRgnSrvReq(RE004_PFltByp_bPFltRgnSrvReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_StgByp_agStrWhl(RE004_StgByp_agStrWhl_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_StgByp_agvStrWhl(RE004_StgByp_agvStrWhl_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_AirSysByp_rOpEGRCoBypReq(RE004_AirSysByp_rOpEGRCoBypReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_CoPtByp_bTqTx(RE004_CoPtByp_bTqTx_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_CoPtByp_noEgdGearCord(RE004_CoPtByp_noEgdGearCord_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_CoPtByp_stCpl(RE004_CoPtByp_stCpl_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EOMByp_stCmbTdOff(RE004_EOMByp_stCmbTdOff_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EOMByp_tiEngStop(RE004_EOMByp_tiEngStop_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_FRMByp_bAcvNoEgdGearDft(RE004_FRMByp_bAcvNoEgdGearDft_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_KnkMgtByp_ctRblInjCutOffPtl(RE004_KnkMgtByp_ctRblInjCutOffPtl_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_OAMByp_rOilDil(RE004_OAMByp_rOilDil_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_AntiBoil_bRatCorPwrFilIniDly(RE004_AntiBoil_bRatCorPwrFilIniDly_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_AntiBoil_tECTReqDly(RE004_AntiBoil_tECTReqDly_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_KnkProt_tECTAdpReq(RE004_KnkProt_tECTAdpReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_KnkProt_tECTTAirReq(RE004_KnkProt_tECTTAirReq_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_TqSysByp_tqIdcAirReqGen(RE004_TqSysByp_tqIdcAirReqGen_out);
   (void)Rte_IrvWrite_RE_ThMgt_004_TEV_EngLimByp_tqIdcEngCur(RE004_EngLimByp_tqIdcEngCur_out);
   (void)Rte_Write_P_ThMgt_tqIdcLimReq_ThMgt_tqIdcLimReq(ThMgt_tqIdcLimReq_out);

   if (FALSE == THMGT_ACTIVE_BYP_C)
   {

      /* Diag treatment : ThMgt_AntiBoil */
      if(ThMgt_bMonRunAntiBoil_out==1)
      {
         /* Diag activation */
         if(ThMgt_bDgoAntiBoil_out==1)
         {
            Rte_Call_R_ThMgt_AntiBoil_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
            Rte_Call_R_ThMgt_AntiBoil_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
      }
      else
      {
         if(ThMgt_bMonRunAntiBoil_out_prec==1)
         {
            Rte_Call_R_ThMgt_AntiBoil_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
      }
      ThMgt_bMonRunAntiBoil_out_prec = ThMgt_bMonRunAntiBoil_out;
   }
}

#define THMGT_STOP_SEC_CODE
#include "ThMgt_MemMap.h"

#endif/*_THMGT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
