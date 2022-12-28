/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ASE.c
* Description   : Interface AUTOSAR du module ASE avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 23-May-2011(12:33:37)
*******************************************************************************/

#ifndef _ASE_C_
#define _ASE_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_ASE.h"
#include "ASE.h"
#include "ASE_002_TEV_fct.h"
#include "ASE_004_TEV_fct.h"
#include "ASE_006_TEV_fct.h"
#include "ASE_008_TEV_fct.h"
#include "ASE_010_TEV_fct.h"
#include "ASE_012_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define ASE_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ASE_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Major_MP = 3;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Minor_MP = 3;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ASE_ModuleVersion_Build_MP = 1;
#define ASE_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 1
#define Module_LIB_PSA_VERSION_REQ_MIN 5

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define ASE_START_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_008_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_010_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_ASE_012_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bRstrtReqAvl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngCutOffReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngStallReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bAltRStrtTypASEReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bCdnInhRStrt_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bEngRStrtTypASEReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtASE_bVSSNwAcvAuth_B = 0;
#define ASE_STOP_SEC_CALIB_BOOLEAN
#include "ASE_MemMap.h"

#define ASE_START_SEC_CALIB_8BIT
#include "ASE_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtASE_stPwt_B = 1;
#define ASE_STOP_SEC_CALIB_8BIT
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define ASE_START_SEC_CODE
#include "ASE_MemMap.h"

void RE_ASE_001_MSE(void)
{


      ASE_001_MSE_ini();

  (void)Rte_IrvWrite_RE_ASE_001_MSE_CoStall_bEngStallAuth(0);
  (void)Rte_IrvWrite_RE_ASE_001_MSE_CoStall_bEngStallReq(0);

}

void RE_ASE_002_TEV(void)
{

  if (FALSE == RE_ASE_002_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmSTT_bEngASERstrtReq_CoEmSTT_bEngASERstrtReq(&ASE_002_CoEmSTT_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoEmSTT_bEngStallAuth_CoEmSTT_bEngStallAuth(&ASE_002_CoEmSTT_bEngStallAuth_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&ASE_002_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_bBltStopAuth_CoPtUH_bBltStopAuth(&ASE_002_CoPtUH_bBltStopAuth_in);
      (void)Rte_Read_R_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(&ASE_002_CoPtUH_bCompTqRStrt_in);
      (void)Rte_Read_R_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(&ASE_002_CoPtUH_bEngStallReq_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&ASE_002_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq2_CoPtUH_bFbSpcFactSTTReq2(&ASE_002_CoPtUH_bFbSpcFactSTTReq2_in);
      (void)Rte_Read_R_CoPtUH_bLimFreqStopInh_CoPtUH_bLimFreqStopInh(&ASE_002_CoPtUH_bLimFreqStopInh_in);
      (void)Rte_Read_R_CoPtUH_bRStrtReqDgoBlt_CoPtUH_bRStrtReqDgoBlt(&ASE_002_CoPtUH_bRStrtReqDgoBlt_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&ASE_002_CoPtUH_stPwt_in);
      (void)Rte_Read_R_CoReqCha_bEngASERstrtReq_CoReqCha_bEngASERstrtReq(&ASE_002_CoReqCha_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoReqCha_bEngStallAuth_CoReqCha_bEngStallAuth(&ASE_002_CoReqCha_bEngStallAuth_in);
      (void)Rte_Read_R_CoReqDamp_bEngStallAuth_CoReqDamp_bEngStallAuth(&ASE_002_CoReqDamp_bEngStallAuth_in);
      (void)Rte_Read_R_CoReqStg_bEngASERstrtReq_CoReqStg_bEngASERstrtReq(&ASE_002_CoReqStg_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoReqStg_bEngStallAuth_CoReqStg_bEngStallAuth(&ASE_002_CoReqStg_bEngStallAuth_in);
      (void)Rte_Read_R_CoReqVeh_bEngASERstrtReq_CoReqVeh_bEngASERstrtReq(&ASE_002_CoReqVeh_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoReqVeh_bEngStallAuth_CoReqVeh_bEngStallAuth(&ASE_002_CoReqVeh_bEngStallAuth_in);
      (void)Rte_Read_R_EngReqH_bEngStallAuth_EngReqH_bEngStallAuth(&ASE_002_EngReqH_bEngStallAuth_in);
      RE_ASE_002_TEV_CoASE_spdVeh_in = Rte_IrvRead_RE_ASE_002_TEV_CoASE_spdVeh();
      RE_ASE_002_TEV_CoASE_stEngASEReqClas_in = Rte_IrvRead_RE_ASE_002_TEV_CoASE_stEngASEReqClas();
      RE_ASE_002_TEV_MgtStall_bStallAuthNbASE_in = Rte_IrvRead_RE_ASE_002_TEV_MgtStall_bStallAuthNbASE();
      RE_ASE_002_TEV_MgtStall_bStallAuthNbRstrt_in = Rte_IrvRead_RE_ASE_002_TEV_MgtStall_bStallAuthNbRstrt();

      Rte_Call_R_FRM_bAcvCutCoPtASE_GetFunctionPermission(& ASE_002_FRM_bAcvCutCoPtASE_in);
      ASE_002_FRM_bAcvCutCoPtASE_in = !ASE_002_FRM_bAcvCutCoPtASE_in;
      Rte_Call_R_FRM_bAcvFastRstrtCoPtASE_GetFunctionPermission(& ASE_002_FRM_bAcvFastRstrtCoPtASE_in);
      ASE_002_FRM_bAcvFastRstrtCoPtASE_in = !ASE_002_FRM_bAcvFastRstrtCoPtASE_in;
      Rte_Call_R_FRM_bAcvRstrtCoPtASE_GetFunctionPermission(& ASE_002_FRM_bAcvRstrtCoPtASE_in);
      ASE_002_FRM_bAcvRstrtCoPtASE_in = !ASE_002_FRM_bAcvRstrtCoPtASE_in;
      ASE_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_ASE_002_TEV_CoStall_bEngStallAuth(CoStall_bEngStallAuth);
  (void)Rte_IrvWrite_RE_ASE_002_TEV_CoStall_bEngStallReq(CoStall_bEngStallReq);

}

void RE_ASE_003_MSE(void)
{


      ASE_003_MSE_ini();

  (void)Rte_IrvWrite_RE_ASE_003_MSE_CoASE_bEngASEReqVld(0);
  (void)Rte_IrvWrite_RE_ASE_003_MSE_CoASE_bHiSpdRstrtAuth(0);
  (void)Rte_IrvWrite_RE_ASE_003_MSE_CoASE_spdVeh(0);
  (void)Rte_IrvWrite_RE_ASE_003_MSE_CoASE_stEngASEReqClas(0);
      (void)Rte_Write_P_CoPtASE_bRstrtReqAvl_CoPtASE_bRstrtReqAvl(0);

}

void RE_ASE_004_TEV(void)
{

  if (FALSE == RE_ASE_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ASE_004_AccP_rAccP_in);
      (void)Rte_Read_R_CoEmSTT_bEngASERstrtReq_CoEmSTT_bEngASERstrtReq(&ASE_004_CoEmSTT_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&ASE_004_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_bCompTqRStrt_CoPtUH_bCompTqRStrt(&ASE_004_CoPtUH_bCompTqRStrt_in);
      (void)Rte_Read_R_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(&ASE_004_CoPtUH_bDrvTraOp_in);
      (void)Rte_Read_R_CoPtUH_bInhHiSpdAltRstrtReq_CoPtUH_bInhHiSpdAltRstrtReq(&ASE_004_CoPtUH_bInhHiSpdAltRstrtReq_in);
      (void)Rte_Read_R_CoPtUH_bRStrtReqDgoBlt_CoPtUH_bRStrtReqDgoBlt(&ASE_004_CoPtUH_bRStrtReqDgoBlt_in);
      (void)Rte_Read_R_CoPtUH_stMaxRStrtReq_CoPtUH_stMaxRStrtReq(&ASE_004_CoPtUH_stMaxRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_stSTTLightAcv_CoPtUH_stSTTLightAcv(&ASE_004_CoPtUH_stSTTLightAcv_in);
      (void)Rte_Read_R_CoReqCha_bEngASERstrtReq_CoReqCha_bEngASERstrtReq(&ASE_004_CoReqCha_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&ASE_004_CoReqCha_stEngRStrtInh_in);
      (void)Rte_Read_R_CoReqStg_bEngASERstrtReq_CoReqStg_bEngASERstrtReq(&ASE_004_CoReqStg_bEngASERstrtReq_in);
      (void)Rte_Read_R_CoReqVeh_bEngASERstrtReq_CoReqVeh_bEngASERstrtReq(&ASE_004_CoReqVeh_bEngASERstrtReq_in);
      (void)Rte_Read_R_Ext_bNeut_Ext_bNeut(&ASE_004_Ext_bNeut_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&ASE_004_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&ASE_004_Veh_spdVeh_in);

      Rte_Call_R_FRM_bAcvFastRstrtCoPtASE_GetFunctionPermission(& ASE_004_FRM_bAcvFastRstrtCoPtASE_in);
      ASE_004_FRM_bAcvFastRstrtCoPtASE_in = !ASE_004_FRM_bAcvFastRstrtCoPtASE_in;
      Rte_Call_R_FRM_bAcvRstrtCoPtASE_GetFunctionPermission(& ASE_004_FRM_bAcvRstrtCoPtASE_in);
      ASE_004_FRM_bAcvRstrtCoPtASE_in = !ASE_004_FRM_bAcvRstrtCoPtASE_in;
      Rte_Call_R_FRM_bInhCluPCoPtASE_GetFunctionPermission(& ASE_004_FRM_bInhCluPCoPtASE_in);
      ASE_004_FRM_bInhCluPCoPtASE_in = !ASE_004_FRM_bInhCluPCoPtASE_in;
      Rte_Call_R_FRM_bInhNeutCoPtASE_GetFunctionPermission(& ASE_004_FRM_bInhNeutCoPtASE_in);
      ASE_004_FRM_bInhNeutCoPtASE_in = !ASE_004_FRM_bInhNeutCoPtASE_in;
      Rte_Call_R_FRM_bInhSpdVehCoPtASE_GetFunctionPermission(& ASE_004_FRM_bInhSpdVehCoPtASE_in);
      ASE_004_FRM_bInhSpdVehCoPtASE_in = !ASE_004_FRM_bInhSpdVehCoPtASE_in;
      ASE_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtASE_bRstrtReqAvl_out = CoPtASE_bRstrtReqAvl_B;
  }
  (void)Rte_IrvWrite_RE_ASE_004_TEV_CoASE_bEngASEReqVld(CoASE_bEngASEReqVld);
  (void)Rte_IrvWrite_RE_ASE_004_TEV_CoASE_bHiSpdRstrtAuth(CoASE_bHiSpdRstrtAuth);
  (void)Rte_IrvWrite_RE_ASE_004_TEV_CoASE_spdVeh(CoASE_spdVeh);
  (void)Rte_IrvWrite_RE_ASE_004_TEV_CoASE_stEngASEReqClas(CoASE_stEngASEReqClas);
  (void)Rte_Write_P_CoPtASE_bRstrtReqAvl_CoPtASE_bRstrtReqAvl(CoPtASE_bRstrtReqAvl_out);

}

void RE_ASE_005_MSE(void)
{


      ASE_005_MSE_ini();

      (void)Rte_Write_P_CoPtASE_stPwt_CoPtASE_stPwt(1);

}

void RE_ASE_006_TEV(void)
{

  if (FALSE == RE_ASE_006_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&ASE_006_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(&ASE_006_CoPtASE_bEngStallReq_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&ASE_006_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&ASE_006_CoSync_bDetNNull_in);
      RE_ASE_006_TEV_CoASE_bEngASEReqVld_in = Rte_IrvRead_RE_ASE_006_TEV_CoASE_bEngASEReqVld();
      RE_ASE_006_TEV_CoStall_bEngStallAuth_in = Rte_IrvRead_RE_ASE_006_TEV_CoStall_bEngStallAuth();
      RE_ASE_006_TEV_CoStall_bEngStallReq_in = Rte_IrvRead_RE_ASE_006_TEV_CoStall_bEngStallReq();
      RE_ASE_006_TEV_MgtStall_bEngASEEndTi_in = Rte_IrvRead_RE_ASE_006_TEV_MgtStall_bEngASEEndTi();

      Rte_Call_R_FRM_bAcvRunCoPtASE_GetFunctionPermission(& ASE_006_FRM_bAcvRunCoPtASE_in);
      ASE_006_FRM_bAcvRunCoPtASE_in = !ASE_006_FRM_bAcvRunCoPtASE_in;
      ASE_006_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtASE_stPwt_out = CoPtASE_stPwt_B;
  }
  (void)Rte_Write_P_CoPtASE_stPwt_CoPtASE_stPwt(CoPtASE_stPwt_out);

}

void RE_ASE_007_MSE(void)
{


      ASE_007_MSE_ini();

  (void)Rte_IrvWrite_RE_ASE_007_MSE_MgtASECut_bRstrtMchInh(1);
      (void)Rte_Write_P_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(0);

}

void RE_ASE_008_TEV(void)
{

  if (FALSE == RE_ASE_008_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&ASE_008_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(&ASE_008_CoEmSTT_stEngRStrtReq_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&ASE_008_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_bDrvTraOp_CoPtUH_bDrvTraOp(&ASE_008_CoPtUH_bDrvTraOp_in);
      (void)Rte_Read_R_CoPtUH_bRStrtMchAuth_CoPtUH_bRStrtMchAuth(&ASE_008_CoPtUH_bRStrtMchAuth_in);
      (void)Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&ASE_008_CoReqCha_stEngRStrtInh_in);
      (void)Rte_Read_R_CoReqVeh_stEngRStrtReq_CoReqVeh_stEngRStrtReq(&ASE_008_CoReqVeh_stEngRStrtReq_in);
      RE_ASE_008_TEV_CoASE_spdVeh_in = Rte_IrvRead_RE_ASE_008_TEV_CoASE_spdVeh();
      RE_ASE_008_TEV_CoASE_stEngASEReqClas_in = Rte_IrvRead_RE_ASE_008_TEV_CoASE_stEngASEReqClas();
      RE_ASE_008_TEV_CoStall_bEngStallAuth_in = Rte_IrvRead_RE_ASE_008_TEV_CoStall_bEngStallAuth();
      RE_ASE_008_TEV_CoStall_bEngStallReq_in = Rte_IrvRead_RE_ASE_008_TEV_CoStall_bEngStallReq();
      RE_ASE_008_TEV_MgtStall_bMissRstrtTmp_in = Rte_IrvRead_RE_ASE_008_TEV_MgtStall_bMissRstrtTmp();
      RE_ASE_008_TEV_MgtStall_bStallAuthNbASE_in = Rte_IrvRead_RE_ASE_008_TEV_MgtStall_bStallAuthNbASE();
      RE_ASE_008_TEV_MgtStall_bStallAuthNbRstrt_in = Rte_IrvRead_RE_ASE_008_TEV_MgtStall_bStallAuthNbRstrt();

      Rte_Call_R_FRM_bAcvCutCoPtASE_GetFunctionPermission(& ASE_008_FRM_bAcvCutCoPtASE_in);
      ASE_008_FRM_bAcvCutCoPtASE_in = !ASE_008_FRM_bAcvCutCoPtASE_in;
      Rte_Call_R_FRM_bAcvCutCoPtUH_GetFunctionPermission(& ASE_008_FRM_bAcvCutCoPtUH_in);
      ASE_008_FRM_bAcvCutCoPtUH_in = !ASE_008_FRM_bAcvCutCoPtUH_in;
      ASE_008_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtASE_bEngCutOffReq_out = CoPtASE_bEngCutOffReq_B;
  }
  (void)Rte_IrvWrite_RE_ASE_008_TEV_MgtASECut_bRstrtMchInh(MgtASECut_bRstrtMchInh);
  (void)Rte_Write_P_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(CoPtASE_bEngCutOffReq_out);

}

void RE_ASE_009_MSE(void)
{


      ASE_009_MSE_ini();

  (void)Rte_IrvWrite_RE_ASE_009_MSE_MgtStall_bEngASEEndTi(0);
  (void)Rte_IrvWrite_RE_ASE_009_MSE_MgtStall_bMissRstrtTmp(0);
  (void)Rte_IrvWrite_RE_ASE_009_MSE_MgtStall_bStallAuthNbASE(0);
  (void)Rte_IrvWrite_RE_ASE_009_MSE_MgtStall_bStallAuthNbRstrt(0);
      (void)Rte_Write_P_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(0);

}

void RE_ASE_010_TEV(void)
{

  if (FALSE == RE_ASE_010_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&ASE_010_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&ASE_010_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&ASE_010_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&ASE_010_CoPtUH_stPwt_in);
      (void)Rte_Read_R_CoPtUH_tiCmplStop_CoPtUH_tiCmplStop(&ASE_010_CoPtUH_tiCmplStop_in);
      (void)Rte_Read_R_CoReqCha_stEngRStrtInh_CoReqCha_stEngRStrtInh(&ASE_010_CoReqCha_stEngRStrtInh_in);
      RE_ASE_010_TEV_MgtASECut_bRstrtMchInh_in = Rte_IrvRead_RE_ASE_010_TEV_MgtASECut_bRstrtMchInh();

      ASE_010_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtASE_bEngStallReq_out = CoPtASE_bEngStallReq_B;
  }
  (void)Rte_IrvWrite_RE_ASE_010_TEV_MgtStall_bEngASEEndTi(MgtStall_bEngASEEndTi);
  (void)Rte_IrvWrite_RE_ASE_010_TEV_MgtStall_bMissRstrtTmp(MgtStall_bMissRstrtTmp);
  (void)Rte_IrvWrite_RE_ASE_010_TEV_MgtStall_bStallAuthNbASE(MgtStall_bStallAuthNbASE);
  (void)Rte_IrvWrite_RE_ASE_010_TEV_MgtStall_bStallAuthNbRstrt(MgtStall_bStallAuthNbRstrt);
  (void)Rte_Write_P_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(CoPtASE_bEngStallReq_out);

}

void RE_ASE_011_MSE(void)
{


      ASE_011_MSE_ini();

      (void)Rte_Write_P_CoPtASE_bAltRStrtTypASEReq_CoPtASE_bAltRStrtTypASEReq(0);
      (void)Rte_Write_P_CoPtASE_bCdnInhRStrt_CoPtASE_bCdnInhRStrt(1);
      (void)Rte_Write_P_CoPtASE_bEngRStrtTypASEReq_CoPtASE_bEngRStrtTypASEReq(0);
      (void)Rte_Write_P_CoPtASE_bVSSNwAcvAuth_CoPtASE_bVSSNwAcvAuth(0);

}

void RE_ASE_012_TEV(void)
{

  if (FALSE == RE_ASE_012_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&ASE_012_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&ASE_012_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(&ASE_012_CoPtASE_bEngStallReq_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&ASE_012_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_bEngRstrtClsCluCdn_CoPtUH_bEngRstrtClsCluCdn(&ASE_012_CoPtUH_bEngRstrtClsCluCdn_in);
      (void)Rte_Read_R_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(&ASE_012_CoTqRStrt_bEngStrtSuc_in);
      (void)Rte_Read_R_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(&ASE_012_EngReqH_bEngRStrtAutnAvl_in);
      (void)Rte_Read_R_PARM_bEngRstrtAutnAvl_PARM_bEngRstrtAutnAvl(&ASE_012_PARM_bEngRstrtAutnAvl_in);
      RE_ASE_012_TEV_CoASE_bHiSpdRstrtAuth_in = Rte_IrvRead_RE_ASE_012_TEV_CoASE_bHiSpdRstrtAuth();

      ASE_012_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtASE_bAltRStrtTypASEReq_out = CoPtASE_bAltRStrtTypASEReq_B;
      CoPtASE_bCdnInhRStrt_out = CoPtASE_bCdnInhRStrt_B;
      CoPtASE_bEngRStrtTypASEReq_out = CoPtASE_bEngRStrtTypASEReq_B;
      CoPtASE_bVSSNwAcvAuth_out = CoPtASE_bVSSNwAcvAuth_B;
  }
  (void)Rte_Write_P_CoPtASE_bAltRStrtTypASEReq_CoPtASE_bAltRStrtTypASEReq(CoPtASE_bAltRStrtTypASEReq_out);
  (void)Rte_Write_P_CoPtASE_bCdnInhRStrt_CoPtASE_bCdnInhRStrt(CoPtASE_bCdnInhRStrt_out);
  (void)Rte_Write_P_CoPtASE_bEngRStrtTypASEReq_CoPtASE_bEngRStrtTypASEReq(CoPtASE_bEngRStrtTypASEReq_out);
  (void)Rte_Write_P_CoPtASE_bVSSNwAcvAuth_CoPtASE_bVSSNwAcvAuth(CoPtASE_bVSSNwAcvAuth_out);

}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

#endif/*_ASE_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

