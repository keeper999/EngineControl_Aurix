/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoEmSTT.c
* Description   : Interface AUTOSAR du module CoEmSTT avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 17-Nov-2010(10:0:22)
*******************************************************************************/

#ifndef _COEMSTT_C_
#define _COEMSTT_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_CoEmSTT.h"
#include "CoEmSTT.h"
#include "CoEmSTT_002_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define COEMSTT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoEmSTT_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoEmSTT_ModuleVersion_Major_MP = 4;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 CoEmSTT_ModuleVersion_Minor_MP = 4;
#define COEMSTT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoEmSTT_MemMap.h"

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
#define COEMSTT_START_SEC_CALIB_BOOLEAN
#include "CoEmSTT_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_COEMSTT_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bStaProt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bSTTWaitStrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bUcapUndVolt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSAcvSt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngRstrtAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzEngStopAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzStrtAuth_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattPrf_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattProt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bBattUncrtSoC_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bEngStallAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltCritT_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngRstrtAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngRstrtReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bRvAltEngStopAuth_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bVSSCtzCrit_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bOverThdUcapBoost_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoEmSTT_bUcapDchaAuth_B = 1;
#define COEMSTT_STOP_SEC_CALIB_BOOLEAN
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_CALIB_8BIT
#include "CoEmSTT_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stUcapChSp_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_uEmPredRstrt_B = 80;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_uUcapSp_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_ctRstrtAcvTi_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_facSen_uEmPredRstrt_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_iElNwStop_B = 40;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stBattEngRstrtReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stBattEngStopAuth_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stEngRStrtReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stEngStopAuth_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_stTypEmPredRstrt_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoEmSTT_tiVSSTmrStrtAuth_B = 0;
#define COEMSTT_STOP_SEC_CALIB_8BIT
#include "CoEmSTT_MemMap.h"

#define COEMSTT_START_SEC_CALIB_16BIT
#include "CoEmSTT_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdRstrtAuthSoCBatt_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdStopAuthSoCBatt_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 CoEmSTT_rThdStopAuthSoCCf1_B = 1120;
#define COEMSTT_STOP_SEC_CALIB_16BIT
#include "CoEmSTT_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define COEMSTT_START_SEC_CODE
#include "CoEmSTT_MemMap.h"

void RE_CoEmSTT_001_MSE(void)
{


      CoEmSTT_001_MSE_ini();

      (void)Rte_Write_P_CoEmSTT_bStaProt_CoEmSTT_bStaProt(0);
      (void)Rte_Write_P_CoEmSTT_bSTTWaitStrtReq_CoEmSTT_bSTTWaitStrtReq(0);
      (void)Rte_Write_P_CoEmSTT_bUcapUndVolt_CoEmSTT_bUcapUndVolt(0);
      (void)Rte_Write_P_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(0);
      (void)Rte_Write_P_CoEmSTT_bVSSCtzEngRstrtAuth_CoEmSTT_bVSSCtzEngRstrtAuth(1);
      (void)Rte_Write_P_CoEmSTT_bVSSCtzEngRstrtReq_CoEmSTT_bVSSCtzEngRstrtReq(0);
      (void)Rte_Write_P_CoEmSTT_bVSSCtzEngStopAuth_CoEmSTT_bVSSCtzEngStopAuth(1);
      (void)Rte_Write_P_CoEmSTT_bVSSCtzStrtAuth_CoEmSTT_bVSSCtzStrtAuth(0);
      (void)Rte_Write_P_CoEmSTT_rThdRstrtAuthSoCBatt_CoEmSTT_rThdRstrtAuthSoCBatt(1120);
      (void)Rte_Write_P_CoEmSTT_rThdStopAuthSoCBatt_CoEmSTT_rThdStopAuthSoCBatt(1120);
      (void)Rte_Write_P_CoEmSTT_stUcapChSp_CoEmSTT_stUcapChSp(0);
      (void)Rte_Write_P_CoEmSTT_uEmPredRstrt_CoEmSTT_uEmPredRstrt(80);
      (void)Rte_Write_P_CoEmSTT_uUcapSp_CoEmSTT_uUcapSp(0);
      (void)Rte_Write_P_CoEmSTT_bBattPrf_CoEmSTT_bBattPrf(0);
      (void)Rte_Write_P_CoEmSTT_bBattProt_CoEmSTT_bBattProt(0);
      (void)Rte_Write_P_CoEmSTT_bBattUncrtSoC_CoEmSTT_bBattUncrtSoC(0);
      (void)Rte_Write_P_CoEmSTT_bEngStallAuth_CoEmSTT_bEngStallAuth(1);
      (void)Rte_Write_P_CoEmSTT_bRvAltCritT_CoEmSTT_bRvAltCritT(0);
      (void)Rte_Write_P_CoEmSTT_bRvAltEngRstrtAuth_CoEmSTT_bRvAltEngRstrtAuth(1);
      (void)Rte_Write_P_CoEmSTT_bRvAltEngRstrtReq_CoEmSTT_bRvAltEngRstrtReq(0);
      (void)Rte_Write_P_CoEmSTT_bRvAltEngStopAuth_CoEmSTT_bRvAltEngStopAuth(1);
      (void)Rte_Write_P_CoEmSTT_bVSSCtzCrit_CoEmSTT_bVSSCtzCrit(0);
      (void)Rte_Write_P_CoEmSTT_ctRstrtAcvTi_CoEmSTT_ctRstrtAcvTi(0);
      (void)Rte_Write_P_CoEmSTT_facSen_uEmPredRstrt_CoEmSTT_facSen_uEmPredRstrt(0);
      (void)Rte_Write_P_CoEmSTT_iElNwStop_CoEmSTT_iElNwStop(40);
      (void)Rte_Write_P_CoEmSTT_rThdStopAuthSoCCf1_CoEmSTT_rThdStopAuthSoCCf1(1120);
      (void)Rte_Write_P_CoEmSTT_stBattEngRstrtReq_CoEmSTT_stBattEngRstrtReq(0);
      (void)Rte_Write_P_CoEmSTT_stBattEngStopAuth_CoEmSTT_stBattEngStopAuth(1);
      (void)Rte_Write_P_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(0);
      (void)Rte_Write_P_CoEmSTT_stEngStopAuth_CoEmSTT_stEngStopAuth(1);
      (void)Rte_Write_P_CoEmSTT_stTypEmPredRstrt_CoEmSTT_stTypEmPredRstrt(0);

}

void RE_CoEmSTT_002_TEV(void)
{

  if (FALSE == RE_COEMSTT_002_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_BatMgt_iBattMes_BatMgt_iBattMes(&CoEmSTT_002_BatMgt_iBattMes_in);
      (void)Rte_Read_R_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(&CoEmSTT_002_BatMgt_rBattSoCCor_in);
      (void)Rte_Read_R_BatMgt_resBattIt_BatMgt_resBattIt(&CoEmSTT_002_BatMgt_resBattIt_in);
      (void)Rte_Read_R_BatMgt_stBattSoC_BatMgt_stBattSoC(&CoEmSTT_002_BatMgt_stBattSoC_in);
      (void)Rte_Read_R_BatMgt_tBattMes_BatMgt_tBattMes(&CoEmSTT_002_BatMgt_tBattMes_in);
      (void)Rte_Read_R_BatMgt_uBattMes_BatMgt_uBattMes(&CoEmSTT_002_BatMgt_uBattMes_in);
      (void)Rte_Read_R_BatMgt_uBattRstrt_BatMgt_uBattRstrt(&CoEmSTT_002_BatMgt_uBattRstrt_in);
      (void)Rte_Read_R_CoPtUH_bFbSpcFactSTTReq1_CoPtUH_bFbSpcFactSTTReq1(&CoEmSTT_002_CoPtUH_bFbSpcFactSTTReq1_in);
      (void)Rte_Read_R_ECU_bWkuChDchaUcap_ECU_bWkuChDchaUcap(&CoEmSTT_002_ECU_bWkuChDchaUcap_in);
      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&CoEmSTT_002_ECU_bWkuMain_in);
      (void)Rte_Read_R_Ext_bNotAvl_iBattMes_Ext_bNotAvl_iBattMes(&CoEmSTT_002_Ext_bNotAvl_iBattMes_in);
      (void)Rte_Read_R_Ext_bNotAvl_rBattSoC_Ext_bNotAvl_rBattSoC(&CoEmSTT_002_Ext_bNotAvl_rBattSoC_in);
      (void)Rte_Read_R_Ext_bNotAvl_resBattIt_Ext_bNotAvl_resBattIt(&CoEmSTT_002_Ext_bNotAvl_resBattIt_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&CoEmSTT_002_Ext_bSTTCf_in);
      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&CoEmSTT_002_Ext_spdVeh_in);
      (void)Rte_Read_R_Ext_stBattTypCf_Ext_stBattTypCf(&CoEmSTT_002_Ext_stBattTypCf_in);
      (void)Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&CoEmSTT_002_Ext_stElProdCf_in);
      (void)Rte_Read_R_Ext_stUcapChSpElMgt_Ext_stUcapChSpElMgt(&CoEmSTT_002_Ext_stUcapChSpElMgt_in);
      (void)Rte_Read_R_Ext_stUcapTypCf_Ext_stUcapTypCf(&CoEmSTT_002_Ext_stUcapTypCf_in);
      (void)Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&CoEmSTT_002_Ext_stVSSCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&CoEmSTT_002_Ext_tCoMes_in);
      (void)Rte_Read_R_StaStrtMgt_bStaReq_StaStrtMgt_bStaReq(&CoEmSTT_002_StaStrtMgt_bStaReq_in);
      (void)Rte_Read_R_VSSCtzMgt_rUcapSoHTreat_VSSCtzMgt_rUcapSoHTreat(&CoEmSTT_002_VSSCtzMgt_rUcapSoHTreat_in);
      (void)Rte_Read_R_VSSCtzMgt_stVSSCtzAcvSt_VSSCtzMgt_stVSSCtzAcvSt(&CoEmSTT_002_VSSCtzMgt_stVSSCtzAcvSt_in);
      (void)Rte_Read_R_VSSCtzMgt_stVSSCtzFctLvl_VSSCtzMgt_stVSSCtzFctLvl(&CoEmSTT_002_VSSCtzMgt_stVSSCtzFctLvl_in);
      (void)Rte_Read_R_VSSCtzMgt_tUcapMes_VSSCtzMgt_tUcapMes(&CoEmSTT_002_VSSCtzMgt_tUcapMes_in);
      (void)Rte_Read_R_VSSCtzMgt_uUcapMes_VSSCtzMgt_uUcapMes(&CoEmSTT_002_VSSCtzMgt_uUcapMes_in);
      (void)Rte_Read_R_Afts_bLrnRstReq_iElNwStop_Afts_bLrnRstReq_iElNwStop(&CoEmSTT_002_Afts_bLrnRstReq_iElNwStop_in);
      (void)Rte_Read_R_Afts_bVSSCtzActrTestCmd_Afts_bVSSCtzActrTestCmd(&CoEmSTT_002_Afts_bVSSCtzActrTestCmd_in);
      (void)Rte_Read_R_BatMgt_stBattSoH_BatMgt_stBattSoH(&CoEmSTT_002_BatMgt_stBattSoH_in);
      (void)Rte_Read_R_CoEmCkg_stRstrtTyp_CoEmCkg_stRstrtTyp(&CoEmSTT_002_CoEmCkg_stRstrtTyp_in);
      (void)Rte_Read_R_CoEmCkg_stSTTCf_CoEmCkg_stSTTCf(&CoEmSTT_002_CoEmCkg_stSTTCf_in);
      (void)Rte_Read_R_CoOptmEl_iElProd_CoOptmEl_iElProd(&CoEmSTT_002_CoOptmEl_iElProd_in);
      (void)Rte_Read_R_CoOptmEl_rOfsSoCSTT_CoOptmEl_rOfsSoCSTT(&CoEmSTT_002_CoOptmEl_rOfsSoCSTT_in);
      (void)Rte_Read_R_CoOptmEl_rThdRstrtAuthSoCCf1_CoOptmEl_rThdRstrtAuthSoCCf1(&CoEmSTT_002_CoOptmEl_rThdRstrtAuthSoCCf1_in);
      (void)Rte_Read_R_CoOptmEl_rThdStopAuthSoCCf2_CoOptmEl_rThdStopAuthSoCCf2(&CoEmSTT_002_CoOptmEl_rThdStopAuthSoCCf2_in);
      (void)Rte_Read_R_CoOptmEl_stSoCRefTyp_CoOptmEl_stSoCRefTyp(&CoEmSTT_002_CoOptmEl_stSoCRefTyp_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&CoEmSTT_002_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_CoPtUH_stTypSTTNotAvl_CoPtUH_stTypSTTNotAvl(&CoEmSTT_002_CoPtUH_stTypSTTNotAvl_in);
      (void)Rte_Read_R_Ext_bNotAvl_tBattMes_Ext_bNotAvl_tBattMes(&CoEmSTT_002_Ext_bNotAvl_tBattMes_in);
      (void)Rte_Read_R_Ext_bVSSNwAcvSt_Ext_bVSSNwAcvSt(&CoEmSTT_002_Ext_bVSSNwAcvSt_in);
      (void)Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&CoEmSTT_002_Ext_stTraTypCf_in);
      (void)Rte_Read_R_RvAltMgt_bAntStopStrtWarn_RvAltMgt_bAntStopStrtWarn(&CoEmSTT_002_RvAltMgt_bAntStopStrtWarn_in);
      (void)Rte_Read_R_RvAltMgt_bStopStrtWarn_RvAltMgt_bStopStrtWarn(&CoEmSTT_002_RvAltMgt_bStopStrtWarn_in);
      (void)Rte_Read_R_RvAltMgt_stRvAltRstrtFbCmd_RvAltMgt_stRvAltRstrtFbCmd(&CoEmSTT_002_RvAltMgt_stRvAltRstrtFbCmd_in);
      (void)Rte_Read_R_RvAltMgt_tRvAltStatEstim_RvAltMgt_tRvAltStatEstim(&CoEmSTT_002_RvAltMgt_tRvAltStatEstim_in);
      (void)Rte_Read_R_StaRstrtMgt_bProt10StopInh_StaRstrtMgt_bProt10StopInh(&CoEmSTT_002_StaRstrtMgt_bProt10StopInh_in);
      (void)Rte_Read_R_StaRstrtMgt_stStaRstrtFbCmd_StaRstrtMgt_stStaRstrtFbCmd(&CoEmSTT_002_StaRstrtMgt_stStaRstrtFbCmd_in);
      (void)Rte_Read_R_StopStrtEng_stCdnNxtCkg_StopStrtEng_stCdnNxtCkg(&CoEmSTT_002_StopStrtEng_stCdnNxtCkg_in);
      (void)Rte_Read_R_VSSCtzMgt_bUcapSerAcvTest_VSSCtzMgt_bUcapSerAcvTest(&CoEmSTT_002_VSSCtzMgt_bUcapSerAcvTest_in);
      (void)Rte_Read_R_VSSCtzMgt_resVSSCtzEstim_VSSCtzMgt_resVSSCtzEstim(&CoEmSTT_002_VSSCtzMgt_resVSSCtzEstim_in);
      (void)Rte_Read_R_VSSCtzMgt_stUcapDchaRslt_VSSCtzMgt_stUcapDchaRslt(&CoEmSTT_002_VSSCtzMgt_stUcapDchaRslt_in);
      (void)Rte_Read_R_Afts_bLrnRstReq_uEmPredRstrt_Afts_bLrnRstReq_uEmPredRstrt(&CoEmSTT_002_Afts_bLrnRstReq_uEmPredRstrt_in);
      (void)Rte_Read_R_Afts_bUcapChgIdc_Afts_bUcapChgIdc(&CoEmSTT_002_Afts_bUcapChgIdc_in);
      (void)Rte_Read_R_BatMgt_iBattMaxCkg_BatMgt_iBattMaxCkg(&CoEmSTT_002_BatMgt_iBattMaxCkg_in);
      (void)Rte_Read_R_BatMgt_uBattMinCkg_BatMgt_uBattMinCkg(&CoEmSTT_002_BatMgt_uBattMinCkg_in);
      (void)Rte_Read_R_CoPtUH_bRStrtReqAvl_CoPtUH_bRStrtReqAvl(&CoEmSTT_002_CoPtUH_bRStrtReqAvl_in);
      (void)Rte_Read_R_Ext_rAltCycOp_Ext_rAltCycOp(&CoEmSTT_002_Ext_rAltCycOp_in);
	    (void)Rte_Read_R_StaStrtMgt_bDmgLimStopInh_StaStrtMgt_bDmgLimStopInh(&CoEmSTT_002_StaStrtMgt_bDmgLimStopInh_in);

      Rte_Call_R_FRM_bAcvCoEmSTTVSSCtzStrt_GetFunctionPermission(& CoEmSTT_002_FRM_bAcvCoEmSTTVSSCtzStrt_in);
      CoEmSTT_002_FRM_bAcvCoEmSTTVSSCtzStrt_in = !CoEmSTT_002_FRM_bAcvCoEmSTTVSSCtzStrt_in;
      Rte_Call_R_FRM_bInhCoEmSTT_uEmPredRstrt_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTT_uEmPredRstrt_in);
      CoEmSTT_002_FRM_bInhCoEmSTT_uEmPredRstrt_in = !CoEmSTT_002_FRM_bInhCoEmSTT_uEmPredRstrt_in;
      Rte_Call_R_FRM_bInhCoEmSTTNwCurClcStop_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTTNwCurClcStop_in);
      CoEmSTT_002_FRM_bInhCoEmSTTNwCurClcStop_in = !CoEmSTT_002_FRM_bInhCoEmSTTNwCurClcStop_in;
      Rte_Call_R_FRM_bInhCoEmSTTStopAuth_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTTStopAuth_in);
      CoEmSTT_002_FRM_bInhCoEmSTTStopAuth_in = !CoEmSTT_002_FRM_bInhCoEmSTTStopAuth_in;
      Rte_Call_R_FRM_bInhCoEmSTTVSSCtzStrt_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTTVSSCtzStrt_in);
      CoEmSTT_002_FRM_bInhCoEmSTTVSSCtzStrt_in = !CoEmSTT_002_FRM_bInhCoEmSTTVSSCtzStrt_in;
      Rte_Call_R_FRM_bInhCoEmSTTWaitStrt_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTTWaitStrt_in);
      CoEmSTT_002_FRM_bInhCoEmSTTWaitStrt_in = !CoEmSTT_002_FRM_bInhCoEmSTTWaitStrt_in;
      Rte_Call_R_FRM_bAcvCoEmSTTDftUcapCurSp_GetFunctionPermission(& CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapCurSp_in);
      CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapCurSp_in = !CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapCurSp_in;
      Rte_Call_R_FRM_bAcvCoEmSTTDftUcapVoltSp_GetFunctionPermission(& CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapVoltSp_in);
      CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapVoltSp_in = !CoEmSTT_002_FRM_bAcvCoEmSTTDftUcapVoltSp_in;
      Rte_Call_R_FRM_bAcvCoEmSTTRstrtReq_GetFunctionPermission(& CoEmSTT_002_FRM_bAcvCoEmSTTRstrtReq_in);
      CoEmSTT_002_FRM_bAcvCoEmSTTRstrtReq_in = !CoEmSTT_002_FRM_bAcvCoEmSTTRstrtReq_in;
      Rte_Call_R_FRM_bInhCoEmSTT_uVSSCtzRstrt_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTT_uVSSCtzRstrt_in);
      CoEmSTT_002_FRM_bInhCoEmSTT_uVSSCtzRstrt_in = !CoEmSTT_002_FRM_bInhCoEmSTT_uVSSCtzRstrt_in;
      Rte_Call_R_FRM_bInhCoEmSTTNwCurMv_GetFunctionPermission(& CoEmSTT_002_FRM_bInhCoEmSTTNwCurMv_in);
      CoEmSTT_002_FRM_bInhCoEmSTTNwCurMv_in = !CoEmSTT_002_FRM_bInhCoEmSTTNwCurMv_in;
      Rte_Call_R_FRM_bAcvCoEmSTTCutReq_GetFunctionPermission(& CoEmSTT_002_FRM_bAcvCoEmSTTCutReq_in);
      CoEmSTT_002_FRM_bAcvCoEmSTTCutReq_in = !CoEmSTT_002_FRM_bAcvCoEmSTTCutReq_in;
	  
      CoEmSTT_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoEmSTT_bStaProt_out = CoEmSTT_bStaProt_B;
      CoEmSTT_bSTTWaitStrtReq_out = CoEmSTT_bSTTWaitStrtReq_B;
      CoEmSTT_bUcapUndVolt_out = CoEmSTT_bUcapUndVolt_B;
      CoEmSTT_bVSSAcvSt_out = CoEmSTT_bVSSAcvSt_B;
      CoEmSTT_bVSSCtzEngRstrtAuth_out = CoEmSTT_bVSSCtzEngRstrtAuth_B;
      CoEmSTT_bVSSCtzEngRstrtReq_out = CoEmSTT_bVSSCtzEngRstrtReq_B;
      CoEmSTT_bVSSCtzEngStopAuth_out = CoEmSTT_bVSSCtzEngStopAuth_B;
      CoEmSTT_bVSSCtzStrtAuth_out = CoEmSTT_bVSSCtzStrtAuth_B;
      CoEmSTT_rThdRstrtAuthSoCBatt_out = CoEmSTT_rThdRstrtAuthSoCBatt_B;
      CoEmSTT_rThdStopAuthSoCBatt_out = CoEmSTT_rThdStopAuthSoCBatt_B;
      CoEmSTT_stUcapChSp_out = CoEmSTT_stUcapChSp_B;
      CoEmSTT_uEmPredRstrt_out = CoEmSTT_uEmPredRstrt_B;
      CoEmSTT_uUcapSp_out = CoEmSTT_uUcapSp_B;
      CoEmSTT_bBattPrf_out = CoEmSTT_bBattPrf_B;
      CoEmSTT_bBattProt_out = CoEmSTT_bBattProt_B;
      CoEmSTT_bBattUncrtSoC_out = CoEmSTT_bBattUncrtSoC_B;
      CoEmSTT_bEngStallAuth_out = CoEmSTT_bEngStallAuth_B;
      CoEmSTT_bRvAltCritT_out = CoEmSTT_bRvAltCritT_B;
      CoEmSTT_bRvAltEngRstrtAuth_out = CoEmSTT_bRvAltEngRstrtAuth_B;
      CoEmSTT_bRvAltEngRstrtReq_out = CoEmSTT_bRvAltEngRstrtReq_B;
      CoEmSTT_bRvAltEngStopAuth_out = CoEmSTT_bRvAltEngStopAuth_B;
      CoEmSTT_bVSSCtzCrit_out = CoEmSTT_bVSSCtzCrit_B;
      CoEmSTT_ctRstrtAcvTi_out = CoEmSTT_ctRstrtAcvTi_B;
      CoEmSTT_facSen_uEmPredRstrt_out = CoEmSTT_facSen_uEmPredRstrt_B;
      CoEmSTT_iElNwStop_out = CoEmSTT_iElNwStop_B;
      CoEmSTT_rThdStopAuthSoCCf1_out = CoEmSTT_rThdStopAuthSoCCf1_B;
      CoEmSTT_stBattEngRstrtReq_out = CoEmSTT_stBattEngRstrtReq_B;
      CoEmSTT_stBattEngStopAuth_out = CoEmSTT_stBattEngStopAuth_B;
      CoEmSTT_stEngRStrtReq_out = CoEmSTT_stEngRStrtReq_B;
      CoEmSTT_stEngStopAuth_out = CoEmSTT_stEngStopAuth_B;
      CoEmSTT_stTypEmPredRstrt_out = CoEmSTT_stTypEmPredRstrt_B;
      CoEmSTT_bOverThdUcapBoost_out = CoEmSTT_bOverThdUcapBoost_B;
      CoEmSTT_bUcapDchaAuth_out = CoEmSTT_bUcapDchaAuth_B;
      CoEmSTT_tiVSSTmrStrtAuth_out = CoEmSTT_tiVSSTmrStrtAuth_B;
  }
  (void)Rte_Write_P_CoEmSTT_bStaProt_CoEmSTT_bStaProt(CoEmSTT_bStaProt_out);
  (void)Rte_Write_P_CoEmSTT_bSTTWaitStrtReq_CoEmSTT_bSTTWaitStrtReq(CoEmSTT_bSTTWaitStrtReq_out);
  (void)Rte_Write_P_CoEmSTT_bUcapUndVolt_CoEmSTT_bUcapUndVolt(CoEmSTT_bUcapUndVolt_out);
  (void)Rte_Write_P_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(CoEmSTT_bVSSAcvSt_out);
  (void)Rte_Write_P_CoEmSTT_bVSSCtzEngRstrtAuth_CoEmSTT_bVSSCtzEngRstrtAuth(CoEmSTT_bVSSCtzEngRstrtAuth_out);
  (void)Rte_Write_P_CoEmSTT_bVSSCtzEngRstrtReq_CoEmSTT_bVSSCtzEngRstrtReq(CoEmSTT_bVSSCtzEngRstrtReq_out);
  (void)Rte_Write_P_CoEmSTT_bVSSCtzEngStopAuth_CoEmSTT_bVSSCtzEngStopAuth(CoEmSTT_bVSSCtzEngStopAuth_out);
  (void)Rte_Write_P_CoEmSTT_bVSSCtzStrtAuth_CoEmSTT_bVSSCtzStrtAuth(CoEmSTT_bVSSCtzStrtAuth_out);
  (void)Rte_Write_P_CoEmSTT_rThdRstrtAuthSoCBatt_CoEmSTT_rThdRstrtAuthSoCBatt(CoEmSTT_rThdRstrtAuthSoCBatt_out);
  (void)Rte_Write_P_CoEmSTT_rThdStopAuthSoCBatt_CoEmSTT_rThdStopAuthSoCBatt(CoEmSTT_rThdStopAuthSoCBatt_out);
  (void)Rte_Write_P_CoEmSTT_stUcapChSp_CoEmSTT_stUcapChSp(CoEmSTT_stUcapChSp_out);
  (void)Rte_Write_P_CoEmSTT_uEmPredRstrt_CoEmSTT_uEmPredRstrt(CoEmSTT_uEmPredRstrt_out);
  (void)Rte_Write_P_CoEmSTT_uUcapSp_CoEmSTT_uUcapSp(CoEmSTT_uUcapSp_out);
  (void)Rte_Write_P_CoEmSTT_bBattPrf_CoEmSTT_bBattPrf(CoEmSTT_bBattPrf_out);
  (void)Rte_Write_P_CoEmSTT_bBattProt_CoEmSTT_bBattProt(CoEmSTT_bBattProt_out);
  (void)Rte_Write_P_CoEmSTT_bBattUncrtSoC_CoEmSTT_bBattUncrtSoC(CoEmSTT_bBattUncrtSoC_out);
  (void)Rte_Write_P_CoEmSTT_bEngStallAuth_CoEmSTT_bEngStallAuth(CoEmSTT_bEngStallAuth_out);
  (void)Rte_Write_P_CoEmSTT_bRvAltCritT_CoEmSTT_bRvAltCritT(CoEmSTT_bRvAltCritT_out);
  (void)Rte_Write_P_CoEmSTT_bRvAltEngRstrtAuth_CoEmSTT_bRvAltEngRstrtAuth(CoEmSTT_bRvAltEngRstrtAuth_out);
  (void)Rte_Write_P_CoEmSTT_bRvAltEngRstrtReq_CoEmSTT_bRvAltEngRstrtReq(CoEmSTT_bRvAltEngRstrtReq_out);
  (void)Rte_Write_P_CoEmSTT_bRvAltEngStopAuth_CoEmSTT_bRvAltEngStopAuth(CoEmSTT_bRvAltEngStopAuth_out);
  (void)Rte_Write_P_CoEmSTT_bVSSCtzCrit_CoEmSTT_bVSSCtzCrit(CoEmSTT_bVSSCtzCrit_out);
  (void)Rte_Write_P_CoEmSTT_ctRstrtAcvTi_CoEmSTT_ctRstrtAcvTi(CoEmSTT_ctRstrtAcvTi_out);
  (void)Rte_Write_P_CoEmSTT_facSen_uEmPredRstrt_CoEmSTT_facSen_uEmPredRstrt(CoEmSTT_facSen_uEmPredRstrt_out);
  (void)Rte_Write_P_CoEmSTT_iElNwStop_CoEmSTT_iElNwStop(CoEmSTT_iElNwStop_out);
  (void)Rte_Write_P_CoEmSTT_rThdStopAuthSoCCf1_CoEmSTT_rThdStopAuthSoCCf1(CoEmSTT_rThdStopAuthSoCCf1_out);
  (void)Rte_Write_P_CoEmSTT_stBattEngRstrtReq_CoEmSTT_stBattEngRstrtReq(CoEmSTT_stBattEngRstrtReq_out);
  (void)Rte_Write_P_CoEmSTT_stBattEngStopAuth_CoEmSTT_stBattEngStopAuth(CoEmSTT_stBattEngStopAuth_out);
  (void)Rte_Write_P_CoEmSTT_stEngRStrtReq_CoEmSTT_stEngRStrtReq(CoEmSTT_stEngRStrtReq_out);
  (void)Rte_Write_P_CoEmSTT_stEngStopAuth_CoEmSTT_stEngStopAuth(CoEmSTT_stEngStopAuth_out);
  (void)Rte_Write_P_CoEmSTT_stTypEmPredRstrt_CoEmSTT_stTypEmPredRstrt(CoEmSTT_stTypEmPredRstrt_out);
  (void)Rte_Write_P_CoEmSTT_bOverThdUcapBoost_CoEmSTT_bOverThdUcapBoost(CoEmSTT_bOverThdUcapBoost_out);
  (void)Rte_Write_P_CoEmSTT_bUcapDchaAuth_CoEmSTT_bUcapDchaAuth(CoEmSTT_bUcapDchaAuth_out);
  (void)Rte_Write_P_CoEmSTT_tiVSSTmrStrtAuth_CoEmSTT_tiVSSTmrStrtAuth(CoEmSTT_tiVSSTmrStrtAuth_out);

}

#define COEMSTT_STOP_SEC_CODE
#include "CoEmSTT_MemMap.h"

#endif/*_COEMSTT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

