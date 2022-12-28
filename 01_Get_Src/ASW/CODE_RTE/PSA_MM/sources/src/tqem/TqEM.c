/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : TqEM.c
* Description   : Interface AUTOSAR du module TqEM avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 10/10/2011 10:43
*******************************************************************************/

#ifndef _TQEM_C_
#define _TQEM_C_

/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_TqEM.h"
#include "TqEM.h"
#include "TqEM_002_TEV_fct.h"
#include "TqEM_004_TEV_fct.h"
#include "TqEM_006_DRE_fct.h"

/*----------------------------------------------------------------------------
  VERSION MODULE
*----------------------------------------------------------------------------*/
#define TQEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqEM_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Major_MP = 12;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Minor_MP = 2;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqEM_ModuleVersion_Build_MP = 0;
#define TQEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqEM_MemMap.h"

/*----------------------------------------------------------------------------
  CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/
#define Module_LIB_PSA_VERSION_REQ_MAJ 1
#define Module_LIB_PSA_VERSION_REQ_MIN 7
#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define TQEM_START_SEC_CALIB_BOOLEAN
#include "TqEM_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean TQEM_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqEM_bFrzACComp_B = 0;
#define TQEM_STOP_SEC_CALIB_BOOLEAN
#include "TqEM_MemMap.h"

#define TQEM_START_SEC_CALIB_16BIT
#include "TqEM_MemMap.h"
AR_MERGEABLE_CALIB_16BIT SInt16 TqEM_tqEM_B = 0;
#define TQEM_STOP_SEC_CALIB_16BIT
#include "TqEM_MemMap.h"

/*----------------------------------------------------------------------------
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define TQEM_START_SEC_CODE
#include "TqEM_MemMap.h"
void RE_TqEM_001_MSE(void)
{
      //TqEM_001_MSE_ini();
        TqEM_002_TEV_ini();
        TqEM_004_TEV_ini();
        TqEM_006_DRE_ini();

   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_tiEveSync(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_bAuthClc(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_tqEMWiCutOff(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_bEnaAvr3Sync(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_bEnaAvr4Sync(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_bEnaAvr6Sync(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_facTEng(40);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_tqAdpRaw(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_EveSync(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_tqAdp(0);
   (void)Rte_IrvWrite_RE_TqEM_001_MSE_TqEM_tqCkEngRealEM(0);
   (void)Rte_Write_P_TqEM_bFrzACComp_TqEM_bFrzACComp(0);
   (void)Rte_Write_P_TqEM_tqEM_TqEM_tqEM(0);
}

void RE_TqEM_002_TEV(void)
{
   if (FALSE == TQEM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqEM_RE002_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&TqEM_RE002_Ext_tiTDC_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TqEM_RE002_TqSys_bTypFu_in);
      (void)Rte_Read_R_TqSys_tiEveSync2_TqSys_tiEveSync2(&TqEM_RE002_TqSys_tiEveSync2_in);
      (void)Rte_Read_R_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(&TqEM_RE002_TqSys_tqCkEngRealEM_in);
      (void)Rte_Read_R_TqSys_tqCkEngReal_TqSys_tqCkEngReal(&TqEM_RE002_TqSys_tqCkEngReal_in);

      TqEM_002_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_TqEM_002_TEV_TqEM_tiEveSync(RE002_TqEM_tiEveSync_out);
   (void)Rte_IrvWrite_RE_TqEM_002_TEV_TqEM_EveSync(RE002_TqEM_EveSync_out);
   (void)Rte_IrvWrite_RE_TqEM_002_TEV_TqEM_tqCkEngRealEM(RE002_TqEM_tqCkEngRealEM_out);
   
}

void RE_TqEM_004_TEV(void)
{
   if (FALSE == TQEM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&TqEM_RE004_AccP_rAccP_in);
      (void)Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(&TqEM_RE004_CoPt_noEgdGearCordIt_in);
      (void)Rte_Read_R_CoPt_stClu_CoPt_stClu(&TqEM_RE004_CoPt_stClu_in);
      (void)Rte_Read_R_CoPt_stDragRed_CoPt_stDragRed(&TqEM_RE004_CoPt_stDragRed_in);
      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&TqEM_RE004_CoPTSt_stEng_in);
      (void)Rte_Read_R_Ext_bEPB_Ext_bEPB(&TqEM_RE004_Ext_bEPB_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqEM_RE004_Ext_nEng_in);
      (void)Rte_Read_R_Ext_rCluP_Ext_rCluP(&TqEM_RE004_Ext_rCluP_in);
      (void)Rte_Read_R_Ext_spdLeReWhl_Ext_spdLeReWhl(&TqEM_RE004_Ext_spdLeReWhl_in);
      (void)Rte_Read_R_Ext_spdRiReWhl_Ext_spdRiReWhl(&TqEM_RE004_Ext_spdRiReWhl_in);
      (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&TqEM_RE004_Ext_stGBxCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&TqEM_RE004_Ext_tCoMes_in);
      (void)Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&TqEM_RE004_Ext_tOilMes_in);
      (void)Rte_Read_R_TqSys_bIdlAcvCmn_TqSys_bIdlAcvCmn(&TqEM_RE004_TqSys_bIdlAcvCmn_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&TqEM_RE004_TqSys_nTarIdl_in);
      (void)Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&TqEM_RE004_Veh_spdVeh_in);
      RE004_TqEM_tqEMWiCutOff_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_tqEMWiCutOff();
      RE004_TqEM_bEnaAvr3Sync_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_bEnaAvr3Sync();
      RE004_TqEM_bEnaAvr4Sync_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_bEnaAvr4Sync();
      RE004_TqEM_bEnaAvr6Sync_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_bEnaAvr6Sync();
      RE004_TqEM_tqAdpRaw_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_tqAdpRaw();
      RE004_TqEM_tqCkEngRealEM_in = Rte_IrvRead_RE_TqEM_004_TEV_TqEM_tqCkEngRealEM();	  

      Rte_Call_R_FRM_bInhAdp_tqEM_GetFunctionPermission(&TqEM_RE004_FRM_bInhAdp_tqEM_in);
      TqEM_RE004_FRM_bInhAdp_tqEM_in = !TqEM_RE004_FRM_bInhAdp_tqEM_in;
      Rte_Call_R_FRM_bInhTqLimEM_GetFunctionPermission(&TqEM_RE004_FRM_bInhTqLimEM_in);
      TqEM_RE004_FRM_bInhTqLimEM_in = !TqEM_RE004_FRM_bInhTqLimEM_in;
      TqEM_004_TEV_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
      TqEM_bFrzACComp_out = TqEM_bFrzACComp_B;
      TqEM_tqEM_out = TqEM_tqEM_B;
   }
   (void)Rte_IrvWrite_RE_TqEM_004_TEV_TqEM_bAuthClc(RE004_TqEM_bAuthClc_out);
   (void)Rte_IrvWrite_RE_TqEM_004_TEV_TqEM_facTEng(RE004_TqEM_facTEng_out);
   (void)Rte_IrvWrite_RE_TqEM_004_TEV_TqEM_tqAdp(RE004_TqEM_tqAdp_out);
   (void)Rte_Write_P_TqEM_bFrzACComp_TqEM_bFrzACComp(TqEM_bFrzACComp_out);
   (void)Rte_Write_P_TqEM_tqEM_TqEM_tqEM(TqEM_tqEM_out);
   
}

void RE_TqEM_006_DRE(void)
{
   if (FALSE == TQEM_ACTIVE_BYP_C)
   {
      /* Module code execution */
      /* Module behaviour unchanged */
  
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&TqEM_RE006_AccP_rAccP_in);
      (void)Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&TqEM_RE006_EngM_rAirLdCor_in);
      (void)Rte_Read_R_EngM_rAirLdPred_EngM_rAirLdPred(&TqEM_RE006_EngM_rAirLdPred_in);
      (void)Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&TqEM_RE006_EOM_tiEngRun_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqEM_RE006_Ext_nEng_in);
      (void)Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&TqEM_RE006_Ext_noCylEng_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&TqEM_RE006_Ext_tCoMes_in);
      (void)Rte_Read_R_IgSys_rStatIgSpEfc_IgSys_rStatIgSpEfc(&TqEM_RE006_IgSys_rStatIgSpEfc_in);
      (void)Rte_Read_R_IgSys_tqIdcEstim_IgSys_tqIdcEstim(&TqEM_RE006_IgSys_tqIdcEstim_in);
      (void)Rte_Read_R_InjSys_bFuCutOff_InjSys_bFuCutOff(&TqEM_RE006_InjSys_bFuCutOff_in);
      (void)Rte_Read_R_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(&TqEM_RE006_TqCmp_tqCnvLoss_in);
      (void)Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&TqEM_RE006_TqSys_bTypFu_in);
      (void)Rte_Read_R_TqSys_idxTqAccu_TqSys_idxTqAccu(&TqEM_RE006_TqSys_idxTqAccu_in);
      (void)Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&TqEM_RE006_TqSys_nTarIdl_in);
      (void)Rte_Read_R_TreatTDC_nCkFil_TreatTDC_nCkFil(&TqEM_RE006_TreatTDC_nCkFil_in);
      (void)Rte_Read_R_TreatTDC_nCkTDCDelta_TreatTDC_nCkTDCDelta(&TqEM_RE006_TreatTDC_nCkTDCDelta_in);
      RE006_TqEM_tiEveSync_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_tiEveSync();
      RE006_TqEM_bAuthClc_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_bAuthClc();
      RE006_TqEM_facTEng_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_facTEng();
      RE006_TqEM_EveSync_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_EveSync();
      RE006_TqEM_tqAdp_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_tqAdp();
      RE006_TqEM_tqCkEngRealEM_in = Rte_IrvRead_RE_TqEM_006_DRE_TqEM_tqCkEngRealEM();

      TqEM_006_DRE_fct();
   }
   else
   {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */
   }
   (void)Rte_IrvWrite_RE_TqEM_006_DRE_TqEM_tqEMWiCutOff(RE006_TqEM_tqEMWiCutOff_out);
   (void)Rte_IrvWrite_RE_TqEM_006_DRE_TqEM_bEnaAvr3Sync(RE006_TqEM_bEnaAvr3Sync_out);
   (void)Rte_IrvWrite_RE_TqEM_006_DRE_TqEM_bEnaAvr4Sync(RE006_TqEM_bEnaAvr4Sync_out);
   (void)Rte_IrvWrite_RE_TqEM_006_DRE_TqEM_bEnaAvr6Sync(RE006_TqEM_bEnaAvr6Sync_out);
   (void)Rte_IrvWrite_RE_TqEM_006_DRE_TqEM_tqAdpRaw(RE006_TqEM_tqAdpRaw_out);
   
}

#define TQEM_STOP_SEC_CODE
#include "TqEM_MemMap.h"
#endif/*_TQEM_C_ */
/*----------------------------------------------------------------------------*\ 
  END OF FILE
\*----------------------------------------------------------------------------*/ 
