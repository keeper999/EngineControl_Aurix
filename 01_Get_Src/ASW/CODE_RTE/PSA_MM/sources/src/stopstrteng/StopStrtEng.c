/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : StopStrtEng.c
* Description   : Interface AUTOSAR du module StopStrtEng avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 06-Jun-2011(10:30:21)
*******************************************************************************/

#ifndef _STOPSTRTENG_C_
#define _STOPSTRTENG_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_StopStrtEng.h"
#include "StopStrtEng.h"
#include "StopStrtEng_004_TEV_fct.h"
#include "StopStrtEng_006_TEV_fct.h"
#include "StopStrtEng_008_TEV_fct.h"
#include "StopStrtEng_010_TEV_fct.h"
#include "StopStrtEng_012_TEV_fct.h"
#include "StopStrtEng_014_TEV_fct.h"
#include "StopStrtEng_016_TEV_fct.h"
#include "StopStrtEng_018_TEV_fct.h"
#include "StopStrtEng_020_TEV_fct.h"
#include "StopStrtEng_022_TEV_fct.h"
#include "StopStrtEng_024_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define STOPSTRTENG_START_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEng_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEng_ModuleVersion_Major_MP = 5;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 StopStrtEng_ModuleVersion_Minor_MP = 3;
#define STOPSTRTENG_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "StopStrtEng_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 1
#define Module_LIB_PSA_VERSION_REQ_MIN 6

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define STOPSTRTENG_START_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_008_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_010_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_012_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_014_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_016_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_018_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_020_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_022_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_STOPSTRTENG_024_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngRun_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngRunSTT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bEngStop_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaRawAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaStopReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrtRStrt_bInh_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bMainEngStopReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrt_bStrtAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoStrtRStrt_bVSSNwAcvAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPtSynt_bStopIp_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bChaTqAvl_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bChaTqCrt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bEngStrtSuc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bTraCoplAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoTqRStrt_bTraTqAuthRaw_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean StaCtl_bStaProt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bDgoSftyORngAMT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bDgoSftyORngAT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bMonRunSftyORngAMT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoPTSt_bMonRunSftyORngAT_B = 0;
#define STOPSTRTENG_STOP_SEC_CALIB_BOOLEAN
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoPTSt_stEng_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 StaCtl_stStaAuth_B = 2;
AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stEngStrtReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stStopCutReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoStrtRStrt_stAcvReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPTStNew_stEng_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPTStNew_stEngPrec_B = 12;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPTSt_stDrvTra_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 StopStrtEng_stCdnNxtCkg_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoPtSynt_stPwt_B = 1;
#define STOPSTRTENG_STOP_SEC_CALIB_8BIT
#include "StopStrtEng_MemMap.h"

#define STOPSTRTENG_START_SEC_VAR_BOOLEAN
#include "StopStrtEng_MemMap.h"
static Boolean CoPTSt_bMonRunSftyORngAMT_out_prec;
static Boolean CoPTSt_bMonRunSftyORngAT_out_prec;
static Boolean CoSTT_bMonRunORngCutOffReq_out_prec;
static Boolean CoSTT_bMonRunORngStopReq_out_prec;
static Boolean CoPTSt_bMonRunORngMplReq_out_prec;
#define STOPSTRTENG_STOP_SEC_VAR_BOOLEAN
#include "StopStrtEng_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define STOPSTRTENG_START_SEC_CODE
#include "StopStrtEng_MemMap.h"

void RE_StopStrtEng_003_MSE(void)
{


      StopStrtEng_003_MSE_ini();

      (void)Rte_Write_P_CoPTSt_stDrvTra_CoPTSt_stDrvTra(1);
  	  (void)Rte_Write_P_CoPTSt_bDgoSftyORngAMT_CoPTSt_bDgoSftyORngAMT(0);
      (void)Rte_Write_P_CoPTSt_bDgoSftyORngAT_CoPTSt_bDgoSftyORngAT(0);
      (void)Rte_Write_P_CoPTSt_bMonRunSftyORngAMT_CoPTSt_bMonRunSftyORngAMT(0);
      (void)Rte_Write_P_CoPTSt_bMonRunSftyORngAT_CoPTSt_bMonRunSftyORngAT(0);
}

void RE_StopStrtEng_004_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEng_004_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEng_004_Ext_nEng_in);
      (void)Rte_Read_R_Ext_bATParkNeut_Ext_bATParkNeut(&StopStrtEng_004_Ext_bATParkNeut_in);
      (void)Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(&StopStrtEng_004_Ext_bCluPedPrss_in);
      (void)Rte_Read_R_Ext_bDrvTraAMT_Ext_bDrvTraAMT(&StopStrtEng_004_Ext_bDrvTraAMT_in);
      (void)Rte_Read_R_Ext_bInhStrtAMT_Ext_bInhStrtAMT(&StopStrtEng_004_Ext_bInhStrtAMT_in);
      (void)Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(&StopStrtEng_004_Ext_rCluPHiFreq_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&StopStrtEng_004_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_stStrtCf_Ext_stStrtCf(&StopStrtEng_004_Ext_stStrtCf_in);
      (void)Rte_Read_R_Ext_bDgoSenPN_Ext_bDgoSenPN(&StopStrtEng_004_Ext_bDgoSenPN_in);

      Rte_Call_R_FRM_bAcvDrvTraInvld_GetFunctionPermission(& StopStrtEng_004_FRM_bAcvDrvTraInvld_in);
      StopStrtEng_004_FRM_bAcvDrvTraInvld_in = !StopStrtEng_004_FRM_bAcvDrvTraInvld_in;
      StopStrtEng_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPTSt_stDrvTra_out = CoPTSt_stDrvTra_B;
      CoPTSt_bDgoSftyORngAMT_out = CoPTSt_bDgoSftyORngAMT_B;
      CoPTSt_bDgoSftyORngAT_out = CoPTSt_bDgoSftyORngAT_B;
      CoPTSt_bMonRunSftyORngAMT_out = CoPTSt_bMonRunSftyORngAMT_B;
      CoPTSt_bMonRunSftyORngAT_out = CoPTSt_bMonRunSftyORngAT_B;
  }
  (void)Rte_Write_P_CoPTSt_stDrvTra_CoPTSt_stDrvTra(CoPTSt_stDrvTra_out);
  (void)Rte_Write_P_CoPTSt_bDgoSftyORngAMT_CoPTSt_bDgoSftyORngAMT(CoPTSt_bDgoSftyORngAMT_out);
  (void)Rte_Write_P_CoPTSt_bDgoSftyORngAT_CoPTSt_bDgoSftyORngAT(CoPTSt_bDgoSftyORngAT_out);
  (void)Rte_Write_P_CoPTSt_bMonRunSftyORngAMT_CoPTSt_bMonRunSftyORngAMT(CoPTSt_bMonRunSftyORngAMT_out);
  (void)Rte_Write_P_CoPTSt_bMonRunSftyORngAT_CoPTSt_bMonRunSftyORngAT(CoPTSt_bMonRunSftyORngAT_out);

  if (FALSE == RE_STOPSTRTENG_004_TEV_B)
  {

  /* Diag treatment : StopStrtEng_SftyORngAMT */
     if(CoPTSt_bMonRunSftyORngAMT_out==1)
     {
         /* Diag activation */
         if(CoPTSt_bDgoSftyORngAMT_out==1)
         {
             Rte_Call_R_CoPTSt_SftyORngAMT_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPTSt_SftyORngAMT_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPTSt_bMonRunSftyORngAMT_out_prec==1)
         {
             Rte_Call_R_CoPTSt_SftyORngAMT_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPTSt_bMonRunSftyORngAMT_out_prec = CoPTSt_bMonRunSftyORngAMT_out;
  }

  if (FALSE == RE_STOPSTRTENG_004_TEV_B)
  {

  /* Diag treatment : StopStrtEng_SftyORngAT */
     if(CoPTSt_bMonRunSftyORngAT_out==1)
     {
         /* Diag activation */
         if(CoPTSt_bDgoSftyORngAT_out==1)
         {
             Rte_Call_R_CoPTSt_SftyORngAT_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPTSt_SftyORngAT_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPTSt_bMonRunSftyORngAT_out_prec==1)
         {
             Rte_Call_R_CoPTSt_SftyORngAT_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPTSt_bMonRunSftyORngAT_out_prec = CoPTSt_bMonRunSftyORngAT_out;
  }

}

void RE_StopStrtEng_005_MSE(void)
{


      StopStrtEng_005_MSE_ini();

      (void)Rte_Write_P_StaCtl_bStaRawAuth_StaCtl_bStaRawAuth(0);
      (void)Rte_Write_P_StaCtl_stStaAuth_StaCtl_stStaAuth(2);
      (void)Rte_Write_P_StaCtl_bStaAuth_StaCtl_bStaAuth(0);
      (void)Rte_Write_P_StaCtl_bStaStopReq_StaCtl_bStaStopReq(0);

}

void RE_StopStrtEng_006_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_006_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEng_006_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEng_006_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&StopStrtEng_006_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&StopStrtEng_006_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_stStrtCf_Ext_stStrtCf(&StopStrtEng_006_Ext_stStrtCf_in);
      (void)Rte_Read_R_Ext_bTypStrt_Ext_bTypStrt(&StopStrtEng_006_Ext_bTypStrt_in);
      (void)Rte_Read_R_Ext_bBrkPedPrss_Ext_bBrkPedPrss(&StopStrtEng_006_Ext_bBrkPedPrss_in);
      (void)Rte_Read_R_Ext_posnGBxLev_Ext_posnGBxLev(&StopStrtEng_006_Ext_posnGBxLev_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&StopStrtEng_006_Ext_pAirExtMes_in);
      (void)Rte_Read_R_CoPTSt_stDrvTra_CoPTSt_stDrvTra(&StopStrtEng_006_CoPTSt_stDrvTra_in);
      RE_StopStrtEng_006_TEV_StaCtl_bEngStrtAuth_in = Rte_IrvRead_RE_StopStrtEng_006_TEV_StaCtl_bEngStrtAuth();
      RE_StopStrtEng_006_TEV_StaCtl_bPrepStrtAuth_in = Rte_IrvRead_RE_StopStrtEng_006_TEV_StaCtl_bPrepStrtAuth();

      StopStrtEng_006_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      StaCtl_bStaRawAuth_out = StaCtl_bStaRawAuth_B;
      StaCtl_stStaAuth_out = StaCtl_stStaAuth_B;
      StaCtl_bStaAuth_out = StaCtl_bStaAuth_B;
      StaCtl_bStaStopReq_out = StaCtl_bStaStopReq_B;
  }
  (void)Rte_Write_P_StaCtl_bStaRawAuth_StaCtl_bStaRawAuth(StaCtl_bStaRawAuth_out);
  (void)Rte_Write_P_StaCtl_stStaAuth_StaCtl_stStaAuth(StaCtl_stStaAuth_out);
  (void)Rte_Write_P_StaCtl_bStaAuth_StaCtl_bStaAuth(StaCtl_bStaAuth_out);
  (void)Rte_Write_P_StaCtl_bStaStopReq_StaCtl_bStaStopReq(StaCtl_bStaStopReq_out);

}

void RE_StopStrtEng_007_MSE(void)
{


      StopStrtEng_007_MSE_ini();

      (void)Rte_IrvWrite_RE_StopStrtEng_007_MSE_StaCtl_bPTProt(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_008_TEV_StaCtl_bPTProt(0);
      (void)Rte_Write_P_StaCtl_bStaProt_StaCtl_bStaProt(0);

}

void RE_StopStrtEng_008_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_008_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&StopStrtEng_008_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoPTSt_bEngRunSTT_CoPTSt_bEngRunSTT(&StopStrtEng_008_CoPTSt_bEngRunSTT_in);

      StopStrtEng_008_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      StaCtl_bStaProt_out = StaCtl_bStaProt_B;
  }
  (void)Rte_IrvWrite_RE_StopStrtEng_008_TEV_StaCtl_bPTProt(StaCtl_bPTProt);
  (void)Rte_Write_P_StaCtl_bStaProt_StaCtl_bStaProt(StaCtl_bStaProt_out);

}

void RE_StopStrtEng_009_MSE(void)
{


      StopStrtEng_009_MSE_ini();

      (void)Rte_Write_P_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(0);
      (void)Rte_Write_P_CoStrtRStrt_stStopCutReq_CoStrtRStrt_stStopCutReq(0);
      (void)Rte_Write_P_CoStrtRStrt_bInh_CoStrtRStrt_bInh(1);
      (void)Rte_Write_P_CoStrtRStrt_stAcvReq_CoStrtRStrt_stAcvReq(0);
      (void)Rte_Write_P_CoStrtRStrt_bVSSNwAcvAuth_CoStrtRStrt_bVSSNwAcvAuth(0);

}

void RE_StopStrtEng_010_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_010_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEng_010_ECU_bWkuMain_in);      
      (void)Rte_Read_R_CoPtUH_bAltRStrtReq_CoPtUH_bAltRStrtReq(&StopStrtEng_010_CoPtUH_bAltRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_bCdnInhRStrt_CoPtUH_bCdnInhRStrt(&StopStrtEng_010_CoPtUH_bCdnInhRStrt_in);
      (void)Rte_Read_R_CoStrt_bStrtAuth_CoStrt_bStrtAuth(&StopStrtEng_010_CoStrt_bStrtAuth_in);
      (void)Rte_Read_R_CoPtASE_bAltRStrtTypASEReq_CoPtASE_bAltRStrtTypASEReq(&StopStrtEng_010_CoPtASE_bAltRStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtASE_bAltStrtTypASEReq_CoPtASE_bAltStrtTypASEReq(&StopStrtEng_010_CoPtASE_bAltStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtASE_bCdnInhRStrt_CoPtASE_bCdnInhRStrt(&StopStrtEng_010_CoPtASE_bCdnInhRStrt_in);
      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&StopStrtEng_010_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_bEngRStrtTypASEReq_CoPtASE_bEngRStrtTypASEReq(&StopStrtEng_010_CoPtASE_bEngRStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(&StopStrtEng_010_CoPtASE_bEngStallReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStrtTypASEReq_CoPtASE_bEngStrtTypASEReq(&StopStrtEng_010_CoPtASE_bEngStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtASE_bVSSNwAcvAuth_CoPtASE_bVSSNwAcvAuth(&StopStrtEng_010_CoPtASE_bVSSNwAcvAuth_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&StopStrtEng_010_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoPtUH_bVSSNwAcvAuth_CoPtUH_bVSSNwAcvAuth(&StopStrtEng_010_CoPtUH_bVSSNwAcvAuth_in);
      (void)Rte_Read_R_Afts_bSpcFactOffDeacInh_Afts_bSpcFactOffDeacInh(&StopStrtEng_010_Afts_bSpcFactOffDeacInh_in);
      (void)Rte_Read_R_Afts_bSpcFactOnDeacInh_Afts_bSpcFactOnDeacInh(&StopStrtEng_010_Afts_bSpcFactOnDeacInh_in);
      (void)Rte_Read_R_CoEmSTT_tiVSSTmrStrtAuth_CoEmSTT_tiVSSTmrStrtAuth(&StopStrtEng_010_CoEmSTT_tiVSSTmrStrtAuth_in);
      RE_StopStrtEng_010_TEV_CoPTSt_bEngStopReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoPTSt_bEngStopReq();
      RE_StopStrtEng_010_TEV_CoStrt_bStrtReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoStrt_bStrtReq();
      RE_StopStrtEng_010_TEV_CoSTT_bEngCutOffReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoSTT_bEngCutOffReq();
      RE_StopStrtEng_010_TEV_CoSTT_bEngRStrtReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoSTT_bEngRStrtReq();
      RE_StopStrtEng_010_TEV_CoSTT_bEngStopReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoSTT_bEngStopReq();
      RE_StopStrtEng_010_TEV_StopStrtEng_bVSSNwAcvAuth_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_StopStrtEng_bVSSNwAcvAuth();
      RE_StopStrtEng_010_TEV_CoPTSt_bEngStrtGlblReq_in = Rte_IrvRead_RE_StopStrtEng_010_TEV_CoPTSt_bEngStrtGlblReq();

      StopStrtEng_010_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoStrtRStrt_stEngStrtReq_out = CoStrtRStrt_stEngStrtReq_B;
      CoStrtRStrt_stStopCutReq_out = CoStrtRStrt_stStopCutReq_B;
      CoStrtRStrt_bInh_out = CoStrtRStrt_bInh_B;
      CoStrtRStrt_stAcvReq_out = CoStrtRStrt_stAcvReq_B;
      CoStrtRStrt_bVSSNwAcvAuth_out = CoStrtRStrt_bVSSNwAcvAuth_B;
  }
  (void)Rte_Write_P_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(CoStrtRStrt_stEngStrtReq_out);
  (void)Rte_Write_P_CoStrtRStrt_stStopCutReq_CoStrtRStrt_stStopCutReq(CoStrtRStrt_stStopCutReq_out);
  (void)Rte_Write_P_CoStrtRStrt_bInh_CoStrtRStrt_bInh(CoStrtRStrt_bInh_out);
  (void)Rte_Write_P_CoStrtRStrt_stAcvReq_CoStrtRStrt_stAcvReq(CoStrtRStrt_stAcvReq_out);
  (void)Rte_Write_P_CoStrtRStrt_bVSSNwAcvAuth_CoStrtRStrt_bVSSNwAcvAuth(CoStrtRStrt_bVSSNwAcvAuth_out);

}

void RE_StopStrtEng_011_MSE(void)
{


      StopStrtEng_011_MSE_ini();

      (void)Rte_IrvWrite_RE_StopStrtEng_011_MSE_StaCtl_bEngPrepAcv(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_011_MSE_StaCtl_bEngPrepEngAuth(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_011_MSE_StaCtl_bEngRunPrepReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_011_MSE_StaCtl_bEngStrtAuth(1);
      (void)Rte_IrvWrite_RE_StopStrtEng_011_MSE_StaCtl_bPrepStrtAuth(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngPrepAcv(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngPrepEngAuth(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngRunPrepReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngStrtAuth(1);
      (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bPrepStrtAuth(0);

}

void RE_StopStrtEng_012_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_012_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_bWaitStrtReq_CoEmCkg_bWaitStrtReq(&StopStrtEng_012_CoEmCkg_bWaitStrtReq_in);
      (void)Rte_Read_R_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(&StopStrtEng_012_CoPTSt_bMainEngStopReq_in);
      (void)Rte_Read_R_Ext_bGslEngPrepReq_Ext_bGslEngPrepReq(&StopStrtEng_012_Ext_bGslEngPrepReq_in);
      (void)Rte_Read_R_GlwCtl_bEngRunAuth_GlwCtl_bEngRunAuth(&StopStrtEng_012_GlwCtl_bEngRunAuth_in);
      (void)Rte_Read_R_GlwCtl_bEngRunReq_GlwCtl_bEngRunReq(&StopStrtEng_012_GlwCtl_bEngRunReq_in);
      (void)Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&StopStrtEng_012_Ext_stFuTypCf_in);
      (void)Rte_Read_R_Sfty_bInhDrvTraSfty_Sfty_bInhDrvTraSfty(&StopStrtEng_012_Sfty_bInhDrvTraSfty_in);
      RE_StopStrtEng_012_TEV_StaCtl_bPTProt_in = Rte_IrvRead_RE_StopStrtEng_012_TEV_StaCtl_bPTProt();

      Rte_Call_R_FRM_bInhSta_GetFunctionPermission(&StopStrtEng_012_FRM_bInhSta_in);
      StopStrtEng_012_FRM_bInhSta_in = !StopStrtEng_012_FRM_bInhSta_in;
      StopStrtEng_012_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

  }
  (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngPrepAcv(StaCtl_bEngPrepAcv);
  (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngPrepEngAuth(StaCtl_bEngPrepEngAuth);
  (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngRunPrepReq(StaCtl_bEngRunPrepReq);
  (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bEngStrtAuth(StaCtl_bEngStrtAuth);
  (void)Rte_IrvWrite_RE_StopStrtEng_012_TEV_StaCtl_bPrepStrtAuth(StaCtl_bPrepStrtAuth);

}

void RE_StopStrtEng_013_MSE(void)
{


      StopStrtEng_013_MSE_ini();

      (void)Rte_Write_P_CoPTSt_bEngRun_CoPTSt_bEngRun(0);
      (void)Rte_Write_P_CoPTSt_bEngRunSTT_CoPTSt_bEngRunSTT(0);
      (void)Rte_Write_P_CoPTSt_bEngStop_CoPTSt_bEngStop(1);
      (void)Rte_Write_P_CoPTSt_stEng_CoPTSt_stEng(1);
      (void)Rte_Write_P_CoPTStNew_stEng_CoPTStNew_stEng(1);
      (void)Rte_Write_P_CoPTStNew_stEngPrec_CoPTStNew_stEngPrec(12);

}

void RE_StopStrtEng_014_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_014_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_InjCtl_mfFuReq_InjCtl_mfFuReq(&StopStrtEng_014_InjCtl_mfFuReq_in);
      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEng_014_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEng_014_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&StopStrtEng_014_Ext_tCoMes_in);
      (void)Rte_Read_R_TqSys_bTqSysAcv_TqSys_bTqSysAcv(&StopStrtEng_014_TqSys_bTqSysAcv_in);
      (void)Rte_Read_R_CoEs_bAcvInjCutOffSTTEs_CoEs_bAcvInjCutOffSTTEs(&StopStrtEng_014_CoEs_bAcvInjCutOffSTTEs_in);
      (void)Rte_Read_R_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(&StopStrtEng_014_CoTqRStrt_bEngStrtSuc_in);
      (void)Rte_Read_R_EngReqH_bEngRStrtAutnAvl_EngReqH_bEngRStrtAutnAvl(&StopStrtEng_014_EngReqH_bEngRStrtAutnAvl_in);
      (void)Rte_Read_R_IgSys_bAcvStructAdv_IgSys_bAcvStructAdv(&StopStrtEng_014_IgSys_bAcvStructAdv_in);
      (void)Rte_Read_R_IgSys_bAcvStructAir_IgSys_bAcvStructAir(&StopStrtEng_014_IgSys_bAcvStructAir_in);
      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&StopStrtEng_014_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_bEngRStrtTypASEReq_CoPtASE_bEngRStrtTypASEReq(&StopStrtEng_014_CoPtASE_bEngRStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStrtTypASEReq_CoPtASE_bEngStrtTypASEReq(&StopStrtEng_014_CoPtASE_bEngStrtTypASEReq_in);
      (void)Rte_Read_R_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(&StopStrtEng_014_CoPtUH_bEngStallReq_in);
      (void)Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(&StopStrtEng_014_CoSync_bDetNNull_in);
      (void)Rte_Read_R_CoOptmEl_stElEProv_CoOptmEl_stElEProv(&StopStrtEng_014_CoOptmEl_stElEProv_in);
      (void)Rte_Read_R_CoTqRStrt_bTraTqAuthRaw_CoTqRStrt_bTraTqAuthRaw(&StopStrtEng_014_CoTqRStrt_bTraTqAuthRaw_in);
      (void)Rte_Read_R_PARM_bEngRstrtAutnAvl_PARM_bEngRstrtAutnAvl(&StopStrtEng_014_PARM_bEngRstrtAutnAvl_in);
      (void)Rte_Read_R_Ext_bAcvInjCutOff_Ext_bAcvInjCutOff(&StopStrtEng_014_Ext_bAcvInjCutOff_in);
      RE_StopStrtEng_014_TEV_CoPTSt_bEngStopReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_CoPTSt_bEngStopReq();
      RE_StopStrtEng_014_TEV_CoSTT_bEngCutOffReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_CoSTT_bEngCutOffReq();
      RE_StopStrtEng_014_TEV_CoSTT_bEngRStrtReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_CoSTT_bEngRStrtReq();
      RE_StopStrtEng_014_TEV_CoSTT_bEngStopReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_CoSTT_bEngStopReq();
      RE_StopStrtEng_014_TEV_StaCtl_bEngPrepAcv_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_StaCtl_bEngPrepAcv();
      RE_StopStrtEng_014_TEV_StaCtl_bEngPrepEngAuth_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_StaCtl_bEngPrepEngAuth();
      RE_StopStrtEng_014_TEV_StaCtl_bEngRunPrepReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_StaCtl_bEngRunPrepReq();
      RE_StopStrtEng_014_TEV_CoPTSt_bEngStrtGlblReq_in = Rte_IrvRead_RE_StopStrtEng_014_TEV_CoPTSt_bEngStrtGlblReq();

      StopStrtEng_014_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPTSt_bEngRun_out = CoPTSt_bEngRun_B;
      CoPTSt_bEngRunSTT_out = CoPTSt_bEngRunSTT_B;
      CoPTSt_bEngStop_out = CoPTSt_bEngStop_B;
      CoPTSt_stEng_out = CoPTSt_stEng_B;
      CoPTStNew_stEng_out = CoPTStNew_stEng_B;
      CoPTStNew_stEngPrec_out = CoPTStNew_stEngPrec_B;
  }
  (void)Rte_Write_P_CoPTSt_bEngRun_CoPTSt_bEngRun(CoPTSt_bEngRun_out);
  (void)Rte_Write_P_CoPTSt_bEngRunSTT_CoPTSt_bEngRunSTT(CoPTSt_bEngRunSTT_out);
  (void)Rte_Write_P_CoPTSt_bEngStop_CoPTSt_bEngStop(CoPTSt_bEngStop_out);
  (void)Rte_Write_P_CoPTSt_stEng_CoPTSt_stEng(CoPTSt_stEng_out);
  (void)Rte_Write_P_CoPTStNew_stEng_CoPTStNew_stEng(CoPTStNew_stEng_out);
  (void)Rte_Write_P_CoPTStNew_stEngPrec_CoPTStNew_stEngPrec(CoPTStNew_stEngPrec_out);

}

void RE_StopStrtEng_015_MSE(void)
{


      StopStrtEng_015_MSE_ini();

      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoPTSt_bEngStopReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoPTSt_bEngStrtReqVld(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoSTT_bEngCutOffReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoSTT_bEngRStrtReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoSTT_bEngStopReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_015_MSE_CoPTSt_bEngStrtGlblReq(1);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStopReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStrtReqVld(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngCutOffReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngRStrtReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngStopReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStrtGlblReq(1);
      (void)Rte_Write_P_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(0);

}

void RE_StopStrtEng_016_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_016_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&StopStrtEng_016_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEng_016_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stStrtCf_Ext_stStrtCf(&StopStrtEng_016_Ext_stStrtCf_in);
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&StopStrtEng_016_AccP_rAccP_in);
      (void)Rte_Read_R_CoPtFH_bEngCutOffReq_CoPtFH_bEngCutOffReq(&StopStrtEng_016_CoPtFH_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtFH_bEngRunReq_CoPtFH_bEngRunReq(&StopStrtEng_016_CoPtFH_bEngRunReq_in);
      (void)Rte_Read_R_CoPtFH_bEngStopReq_CoPtFH_bEngStopReq(&StopStrtEng_016_CoPtFH_bEngStopReq_in);
      (void)Rte_Read_R_CoPtUH_bEngCutOffReq_CoPtUH_bEngCutOffReq(&StopStrtEng_016_CoPtUH_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtUH_bEngRStrtReq_CoPtUH_bEngRStrtReq(&StopStrtEng_016_CoPtUH_bEngRStrtReq_in);
      (void)Rte_Read_R_CoPtUH_bEngStopReq_CoPtUH_bEngStopReq(&StopStrtEng_016_CoPtUH_bEngStopReq_in);
      (void)Rte_Read_R_CoReqVeh_bEngStrtReq_CoReqVeh_bEngStrtReq(&StopStrtEng_016_CoReqVeh_bEngStrtReq_in);
      (void)Rte_Read_R_Ext_bCoReqVehCf_bEngStrtReq_Ext_bCoReqVehCf_bEngStrtReq(&StopStrtEng_016_Ext_bCoReqVehCf_bEngStrtReq_in);
      (void)Rte_Read_R_Ext_bEngStopReq_Ext_bEngStopReq(&StopStrtEng_016_Ext_bEngStopReq_in);
      (void)Rte_Read_R_Ext_bEngStrtReq_Ext_bEngStrtReq(&StopStrtEng_016_Ext_bEngStrtReq_in);
      (void)Rte_Read_R_Ext_bRCDLine_Ext_bRCDLine(&StopStrtEng_016_Ext_bRCDLine_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&StopStrtEng_016_Ext_bSTTCf_in);
      (void)Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&StopStrtEng_016_Ext_stFuTypCf_in);
      (void)Rte_Read_R_StaCtl_bStaProt_StaCtl_bStaProt(&StopStrtEng_016_StaCtl_bStaProt_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&StopStrtEng_016_Veh_spdVeh_in);
      (void)Rte_Read_R_CoPtASE_bEngCutOffReq_CoPtASE_bEngCutOffReq(&StopStrtEng_016_CoPtASE_bEngCutOffReq_in);
      (void)Rte_Read_R_CoPtASE_bEngStallReq_CoPtASE_bEngStallReq(&StopStrtEng_016_CoPtASE_bEngStallReq_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&StopStrtEng_016_CoPTStNew_stEng_in);
      (void)Rte_Read_R_Ext_bASECf_Ext_bASECf(&StopStrtEng_016_Ext_bASECf_in);
      (void)Rte_Read_R_CoOptmEl_stElEProv_CoOptmEl_stElEProv(&StopStrtEng_016_CoOptmEl_stElEProv_in);
      (void)Rte_Read_R_CoPtUH_bEngStallReq_CoPtUH_bEngStallReq(&StopStrtEng_016_CoPtUH_bEngStallReq_in);

      Rte_Call_R_FRM_bAcvCoPTStByp_nEng_GetFunctionPermission(& StopStrtEng_016_FRM_bAcvCoPTStByp_nEng_in);
      StopStrtEng_016_FRM_bAcvCoPTStByp_nEng_in = !StopStrtEng_016_FRM_bAcvCoPTStByp_nEng_in;
      Rte_Call_R_FRM_bAcvCoPTStByp_spdVeh_GetFunctionPermission(& StopStrtEng_016_FRM_bAcvCoPTStByp_spdVeh_in);
      StopStrtEng_016_FRM_bAcvCoPTStByp_spdVeh_in = !StopStrtEng_016_FRM_bAcvCoPTStByp_spdVeh_in;
      Rte_Call_R_FRM_bAcvCoPTStEngStop_GetFunctionPermission(& StopStrtEng_016_FRM_bAcvCoPTStEngStop_in);
      StopStrtEng_016_FRM_bAcvCoPTStEngStop_in = !StopStrtEng_016_FRM_bAcvCoPTStEngStop_in;
      Rte_Call_R_FRM_bAcvEngCutOffRCDLo_GetFunctionPermission(& StopStrtEng_016_FRM_bAcvEngCutOffRCDLo_in);
      StopStrtEng_016_FRM_bAcvEngCutOffRCDLo_in = !StopStrtEng_016_FRM_bAcvEngCutOffRCDLo_in;
      Rte_Call_R_FRM_bInhEngCutOff_GetFunctionPermission(& StopStrtEng_016_FRM_bInhEngCutOff_in);
      StopStrtEng_016_FRM_bInhEngCutOff_in = !StopStrtEng_016_FRM_bInhEngCutOff_in;
      Rte_Call_R_FRM_bInhSTT_GetFunctionPermission(& StopStrtEng_016_FRM_bInhSTT_in);
      StopStrtEng_016_FRM_bInhSTT_in = !StopStrtEng_016_FRM_bInhSTT_in;
      Rte_Call_R_FRM_bAcvEngCutOff_GetFunctionPermission(& StopStrtEng_016_FRM_bAcvEngCutOff_in);
      StopStrtEng_016_FRM_bAcvEngCutOff_in = !StopStrtEng_016_FRM_bAcvEngCutOff_in;
      StopStrtEng_016_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPTSt_bMainEngStopReq_out = CoPTSt_bMainEngStopReq_B;
  }
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStopReq(CoPTSt_bEngStopReq);
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStrtReqVld(CoPTSt_bEngStrtReqVld);
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngCutOffReq(CoSTT_bEngCutOffReq);
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngRStrtReq(CoSTT_bEngRStrtReq);
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoSTT_bEngStopReq(CoSTT_bEngStopReq);
  (void)Rte_IrvWrite_RE_StopStrtEng_016_TEV_CoPTSt_bEngStrtGlblReq(CoPTSt_bEngStrtGlblReq);
  (void)Rte_Write_P_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(CoPTSt_bMainEngStopReq_out);

  if (FALSE == RE_STOPSTRTENG_016_TEV_B)
  {

  /* Diag treatment : StopStrtEng_ORngCutOffReq */
     if(CoSTT_bMonRunORngCutOffReq_out==1)
     {
         /* Diag activation */
         if(CoSTT_bDgoORngCutOffReq_out==1)
         {
             Rte_Call_R_CoSTT_ORngCutOffReq_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoSTT_ORngCutOffReq_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoSTT_bMonRunORngCutOffReq_out_prec==1)
         {
             Rte_Call_R_CoSTT_ORngCutOffReq_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoSTT_bMonRunORngCutOffReq_out_prec = CoSTT_bMonRunORngCutOffReq_out;
  }

  if (FALSE == RE_STOPSTRTENG_016_TEV_B)
  {

  /* Diag treatment : StopStrtEng_ORngStopReq */
     if(CoSTT_bMonRunORngStopReq_out==1)
     {
         /* Diag activation */
         if(CoSTT_bDgoORngStopReq_out==1)
         {
             Rte_Call_R_CoSTT_ORngStopReq_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoSTT_ORngStopReq_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoSTT_bMonRunORngStopReq_out_prec==1)
         {
             Rte_Call_R_CoSTT_ORngStopReq_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoSTT_bMonRunORngStopReq_out_prec = CoSTT_bMonRunORngStopReq_out;
  }

  if (FALSE == RE_STOPSTRTENG_016_TEV_B)
  {

  /* Diag treatment : StopStrtEng_ORngMplReq */
     if(CoPTSt_bMonRunORngMplReq_out==1)
     {
         /* Diag activation */
         if(CoPTSt_bDgoORngMplReq_out==1)
         {
             Rte_Call_R_CoPTSt_ORngMplReq_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoPTSt_ORngMplReq_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoPTSt_bMonRunORngMplReq_out_prec==1)
         {
             Rte_Call_R_CoPTSt_ORngMplReq_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoPTSt_bMonRunORngMplReq_out_prec = CoPTSt_bMonRunORngMplReq_out;
  }

}

void RE_StopStrtEng_017_MSE(void)
{


      StopStrtEng_017_MSE_ini();

      (void)Rte_IrvWrite_RE_StopStrtEng_017_MSE_CoStrt_bStrtReq(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_018_TEV_CoStrt_bStrtReq(0);
      (void)Rte_Write_P_CoStrt_bStrtAuth_CoStrt_bStrtAuth(0);

}

void RE_StopStrtEng_018_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_018_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_bDrvStrtReq_Ext_bDrvStrtReq(&StopStrtEng_018_Ext_bDrvStrtReq_in);
      (void)Rte_Read_R_StaCtl_bStaAuth_StaCtl_bStaAuth(&StopStrtEng_018_StaCtl_bStaAuth_in);
      RE_StopStrtEng_018_TEV_CoPTSt_bEngStrtReqVld_in = Rte_IrvRead_RE_StopStrtEng_018_TEV_CoPTSt_bEngStrtReqVld();

      StopStrtEng_018_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoStrt_bStrtAuth_out = CoStrt_bStrtAuth_B;
  }
  (void)Rte_IrvWrite_RE_StopStrtEng_018_TEV_CoStrt_bStrtReq(CoStrt_bStrtReq);
  (void)Rte_Write_P_CoStrt_bStrtAuth_CoStrt_bStrtAuth(CoStrt_bStrtAuth_out);

}

void RE_StopStrtEng_019_MSE(void)
{


      StopStrtEng_019_MSE_ini();

      (void)Rte_IrvWrite_RE_StopStrtEng_019_MSE_StopStrtEng_bVSSNwAcvAuth(0);
      (void)Rte_IrvWrite_RE_StopStrtEng_020_TEV_StopStrtEng_bVSSNwAcvAuth(0);
      (void)Rte_Write_P_StopStrtEng_stCdnNxtCkg_StopStrtEng_stCdnNxtCkg(0);

}

void RE_StopStrtEng_020_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_020_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&StopStrtEng_020_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_TqAdp_stCdnNxtCkg_TqAdp_stCdnNxtCkg(&StopStrtEng_020_TqAdp_stCdnNxtCkg_in);
      (void)Rte_Read_R_CoEmSTT_tiVSSTmrStrtAuth_CoEmSTT_tiVSSTmrStrtAuth(&StopStrtEng_020_CoEmSTT_tiVSSTmrStrtAuth_in);
      (void)Rte_Read_R_EngReqH_bDetPresAirUnfav_EngReqH_bDetPresAirUnfav(&StopStrtEng_020_EngReqH_bDetPresAirUnfav_in);
      RE_StopStrtEng_020_TEV_CoStrt_bStrtReq_in = Rte_IrvRead_RE_StopStrtEng_020_TEV_CoStrt_bStrtReq();

      Rte_Call_R_FRM_bStrtPrf_GetFunctionPermission(& StopStrtEng_020_FRM_bStrtPrf_in);
      StopStrtEng_020_FRM_bStrtPrf_in = !StopStrtEng_020_FRM_bStrtPrf_in;
      StopStrtEng_020_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      StopStrtEng_stCdnNxtCkg_out = StopStrtEng_stCdnNxtCkg_B;
  }
  (void)Rte_IrvWrite_RE_StopStrtEng_020_TEV_StopStrtEng_bVSSNwAcvAuth(StopStrtEng_bVSSNwAcvAuth);
  (void)Rte_Write_P_StopStrtEng_stCdnNxtCkg_StopStrtEng_stCdnNxtCkg(StopStrtEng_stCdnNxtCkg_out);

}

void RE_StopStrtEng_021_MSE(void)
{


      StopStrtEng_021_MSE_ini();

      (void)Rte_Write_P_CoPtSynt_bStopIp_CoPtSynt_bStopIp(0);
      (void)Rte_Write_P_CoPtSynt_stPwt_CoPtSynt_stPwt(1);

}

void RE_StopStrtEng_022_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_022_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPtUH_bEngStopReq_CoPtUH_bEngStopReq(&StopStrtEng_022_CoPtUH_bEngStopReq_in);
      (void)Rte_Read_R_CoPTStNew_stEng_CoPTStNew_stEng(&StopStrtEng_022_CoPTStNew_stEng_in);
      (void)Rte_Read_R_CoOptmEl_stElEProv_CoOptmEl_stElEProv(&StopStrtEng_022_CoOptmEl_stElEProv_in);
      (void)Rte_Read_R_CoPtASE_stPwt_CoPtASE_stPwt(&StopStrtEng_022_CoPtASE_stPwt_in);
      (void)Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&StopStrtEng_022_CoPtUH_stPwt_in);

      StopStrtEng_022_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoPtSynt_bStopIp_out = CoPtSynt_bStopIp_B;
      CoPtSynt_stPwt_out = CoPtSynt_stPwt_B;
  }
  (void)Rte_Write_P_CoPtSynt_bStopIp_CoPtSynt_bStopIp(CoPtSynt_bStopIp_out);
  (void)Rte_Write_P_CoPtSynt_stPwt_CoPtSynt_stPwt(CoPtSynt_stPwt_out);

}

void RE_StopStrtEng_023_MSE(void)
{


      StopStrtEng_023_MSE_ini();

      (void)Rte_Write_P_CoTqRStrt_bChaTqAvl_CoTqRStrt_bChaTqAvl(0);
      (void)Rte_Write_P_CoTqRStrt_bChaTqCrt_CoTqRStrt_bChaTqCrt(0);
      (void)Rte_Write_P_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(0);
      (void)Rte_Write_P_CoTqRStrt_bTraCoplAuth_CoTqRStrt_bTraCoplAuth(0);
      (void)Rte_Write_P_CoTqRStrt_bTraTqAuthRaw_CoTqRStrt_bTraTqAuthRaw(0);

}

void RE_StopStrtEng_024_TEV(void)
{

  if (FALSE == RE_STOPSTRTENG_024_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_InjCtl_mfFuReq_InjCtl_mfFuReq(&StopStrtEng_024_InjCtl_mfFuReq_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&StopStrtEng_024_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&StopStrtEng_024_Ext_tCoMes_in);
      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&StopStrtEng_024_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&StopStrtEng_024_Ext_pAirExtMes_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&StopStrtEng_024_TqSys_nTarIdl_in);
      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&StopStrtEng_024_Ext_tOilMes_in);
      (void)Rte_Read_R_PredEs_nFast_PredEs_nFast(&StopStrtEng_024_PredEs_nFast_in);
      (void)Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&StopStrtEng_024_CoPt_bSIP_in);

      Rte_Call_R_FRM_bAcvPrmCoTqRStrt_GetFunctionPermission(& StopStrtEng_024_FRM_bAcvPrmCoTqRStrt_in);
      StopStrtEng_024_FRM_bAcvPrmCoTqRStrt_in = !StopStrtEng_024_FRM_bAcvPrmCoTqRStrt_in;
      StopStrtEng_024_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoTqRStrt_bChaTqAvl_out = CoTqRStrt_bChaTqAvl_B;
      CoTqRStrt_bChaTqCrt_out = CoTqRStrt_bChaTqCrt_B;
      CoTqRStrt_bEngStrtSuc_out = CoTqRStrt_bEngStrtSuc_B;
      CoTqRStrt_bTraCoplAuth_out = CoTqRStrt_bTraCoplAuth_B;
      CoTqRStrt_bTraTqAuthRaw_out = CoTqRStrt_bTraTqAuthRaw_B;
  }
  (void)Rte_Write_P_CoTqRStrt_bChaTqAvl_CoTqRStrt_bChaTqAvl(CoTqRStrt_bChaTqAvl_out);
  (void)Rte_Write_P_CoTqRStrt_bChaTqCrt_CoTqRStrt_bChaTqCrt(CoTqRStrt_bChaTqCrt_out);
  (void)Rte_Write_P_CoTqRStrt_bEngStrtSuc_CoTqRStrt_bEngStrtSuc(CoTqRStrt_bEngStrtSuc_out);
  (void)Rte_Write_P_CoTqRStrt_bTraCoplAuth_CoTqRStrt_bTraCoplAuth(CoTqRStrt_bTraCoplAuth_out);
  (void)Rte_Write_P_CoTqRStrt_bTraTqAuthRaw_CoTqRStrt_bTraTqAuthRaw(CoTqRStrt_bTraTqAuthRaw_out);

}

#define STOPSTRTENG_STOP_SEC_CODE
#include "StopStrtEng_MemMap.h"

#endif/*_STOPSTRTENG_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

