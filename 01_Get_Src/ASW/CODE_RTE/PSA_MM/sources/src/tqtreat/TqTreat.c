/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : TqTreat.c
* Description   : Interface AUTOSAR du module TqTreat avec Bypasses
* Auteur        : CLCO/CLO
* Creation      : 27-Jan-2011(11:54:30)
*******************************************************************************/

#ifndef _TQTREAT_C_
#define _TQTREAT_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_TqTreat.h"
#include "TqTreat.h"
#include "TqTreat_002_TEV_fct.h"
#include "TqTreat_004_TEV_fct.h"
#include "TqTreat_010_TEV_fct.h"
#include "TqTreat_006_DRE_fct.h"
#include "TqTreat_008_DRE_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define TQTREAT_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqTreat_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqTreat_ModuleVersion_Major_MP = 11;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 TqTreat_ModuleVersion_Minor_MP = 1;
#define TQTREAT_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqTreat_MemMap.h"

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
#define TQTREAT_START_SEC_CALIB_BOOLEAN
#include "TqTreat_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean TQTREAT_ACTIVE_BYP_C = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bAcvVehSpdCtlLim_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bAcvVehSpdCtlReg_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean TqSys_bTypFu_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoBrk_bAcvBrk_B = 0;
#define TQTREAT_STOP_SEC_CALIB_BOOLEAN
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_8BIT
#include "TqTreat_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 TqSys_idxTqAccu_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 TqSys_stTypPwtCf_B = 0;
#define TQTREAT_STOP_SEC_CALIB_8BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_16BIT
#include "TqTreat_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 Eng_nCkFil_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 TreatTenms_nCkRaw_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 TreatTDC_nCkFil_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEng1_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEng2_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiEngCrankStrt_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 EOM_tiEngRunStrt_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngAvr_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngClc0_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 Ext_nEngClc1_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkGrd_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkTDCDelta_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTenms_nCkGrdFil_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkTDCDelta_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkGrd_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 TreatTDC_nCkGrdFil_B = 0;
#define TQTREAT_STOP_SEC_CALIB_16BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_CALIB_32BIT
#include "TqTreat_MemMap.h"
AR_MERGEABLE_CALIB_32BIT UInt32 EOM_tiEngModStp_B = 0;
AR_MERGEABLE_CALIB_32BIT UInt32 EOM_tiEngRun_B = 0;
#define TQTREAT_STOP_SEC_CALIB_32BIT
#include "TqTreat_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define TQTREAT_START_SEC_CODE
#include "TqTreat_MemMap.h"

void RE_TqTreat_001_MSE(void)
{


      TqTreat_001_MSE_ini();

      (void)Rte_Write_P_TreatTenms_nCkTDCDelta_TreatTenms_nCkTDCDelta(0);
      (void)Rte_Write_P_Eng_nCkFil_Eng_nCkFil(0);
      (void)Rte_Write_P_TreatTenms_nCkGrd_TreatTenms_nCkGrd(0);
      (void)Rte_Write_P_TreatTenms_nCkGrdFil_TreatTenms_nCkGrdFil(0);
      (void)Rte_Write_P_TreatTenms_nCkRaw_TreatTenms_nCkRaw(0);

}

void RE_TqTreat_002_TEV(void)
{

  if (FALSE == TQTREAT_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqTreat_002_Ext_nEng_in);
      (void)Rte_Read_R_Ext_nEngAvr_Ext_nEngAvr(&TqTreat_002_Ext_nEngAvr_in);
      (void)Rte_Read_R_TreatTDC_nCkFil_TreatTDC_nCkFil(&TqTreat_002_TreatTDC_nCkFil_in);
      (void)Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&TqTreat_002_TreatTDC_nCkGrd_in);
      (void)Rte_Read_R_TreatTDC_nCkGrdFil_TreatTDC_nCkGrdFil(&TqTreat_002_TreatTDC_nCkGrdFil_in);
      (void)Rte_Read_R_TreatTDC_nCkTDCDelta_TreatTDC_nCkTDCDelta(&TqTreat_002_TreatTDC_nCkTDCDelta_in);

      TqTreat_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      TreatTenms_nCkTDCDelta_out = TreatTenms_nCkTDCDelta_B;
      Eng_nCkFil_out = Eng_nCkFil_B;
      TreatTenms_nCkGrd_out = TreatTenms_nCkGrd_B;
      TreatTenms_nCkGrdFil_out = TreatTenms_nCkGrdFil_B;
      TreatTenms_nCkRaw_out = TreatTenms_nCkRaw_B;
  }
  (void)Rte_Write_P_TreatTenms_nCkTDCDelta_TreatTenms_nCkTDCDelta(TreatTenms_nCkTDCDelta_out);
  (void)Rte_Write_P_Eng_nCkFil_Eng_nCkFil(Eng_nCkFil_out);
  (void)Rte_Write_P_TreatTenms_nCkGrd_TreatTenms_nCkGrd(TreatTenms_nCkGrd_out);
  (void)Rte_Write_P_TreatTenms_nCkGrdFil_TreatTenms_nCkGrdFil(TreatTenms_nCkGrdFil_out);
  (void)Rte_Write_P_TreatTenms_nCkRaw_TreatTenms_nCkRaw(TreatTenms_nCkRaw_out);

}

void RE_TqTreat_003_MSE(void)
{


      TqTreat_003_MSE_ini();

      (void)Rte_Write_P_EOM_tiEngModStp_EOM_tiEngModStp(0);
      (void)Rte_Write_P_EOM_tiEngCrankStrt_EOM_tiEngCrankStrt(0);
      (void)Rte_Write_P_EOM_tiEngRun_EOM_tiEngRun(0);
      (void)Rte_Write_P_EOM_tiEngRunStrt_EOM_tiEngRunStrt(0);
      (void)Rte_Write_P_TqSys_bAcvVehSpdCtlLim_TqSys_bAcvVehSpdCtlLim(0);
      (void)Rte_Write_P_TqSys_bAcvVehSpdCtlReg_TqSys_bAcvVehSpdCtlReg(0);
      (void)Rte_Write_P_TqSys_bTypFu_TqSys_bTypFu(0);
      (void)Rte_Write_P_TqSys_idxTqAccu_TqSys_idxTqAccu(1);
      (void)Rte_Write_P_TqSys_stTypPwtCf_TqSys_stTypPwtCf(0);

}

void RE_TqTreat_004_TEV(void)
{

  if (FALSE == TQTREAT_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&TqTreat_004_CoPTSt_stEng_in);
      (void)Rte_Read_R_EOM_facItpolCur_EOM_facItpolCur(&TqTreat_004_EOM_facItpolCur_in);
      (void)Rte_Read_R_EOM_idxBas1InjCur_EOM_idxBas1InjCur(&TqTreat_004_EOM_idxBas1InjCur_in);
      (void)Rte_Read_R_EOM_idxBas2InjCur_EOM_idxBas2InjCur(&TqTreat_004_EOM_idxBas2InjCur_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqTreat_004_Ext_nEng_in);
      (void)Rte_Read_R_Ext_stFuTypCf_Ext_stFuTypCf(&TqTreat_004_Ext_stFuTypCf_in);
      (void)Rte_Read_R_Ext_stVSCtlRegCf_Ext_stVSCtlRegCf(&TqTreat_004_Ext_stVSCtlRegCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&TqTreat_004_Ext_tCoMes_in);
      (void)Rte_Read_R_VSCtl_stTqPTMaxCtl_VSCtl_stTqPTMaxCtl(&TqTreat_004_VSCtl_stTqPTMaxCtl_in);
      (void)Rte_Read_R_VSCtl_stTqPTMinCtl_VSCtl_stTqPTMinCtl(&TqTreat_004_VSCtl_stTqPTMinCtl_in);
      (void)Rte_Read_R_VSCtl_stVSLim_VSCtl_stVSLim(&TqTreat_004_VSCtl_stVSLim_in);
      (void)Rte_Read_R_VSCtl_stVSMax_VSCtl_stVSMax(&TqTreat_004_VSCtl_stVSMax_in);
      (void)Rte_Read_R_VSCtl_stVSReg_VSCtl_stVSReg(&TqTreat_004_VSCtl_stVSReg_in);

      TqTreat_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      EOM_tiEngModStp_out = EOM_tiEngModStp_B;
      EOM_tiEngCrankStrt_out = EOM_tiEngCrankStrt_B;
      EOM_tiEngRun_out = EOM_tiEngRun_B;
      EOM_tiEngRunStrt_out = EOM_tiEngRunStrt_B;
      TqSys_bAcvVehSpdCtlLim_out = TqSys_bAcvVehSpdCtlLim_B;
      TqSys_bAcvVehSpdCtlReg_out = TqSys_bAcvVehSpdCtlReg_B;
      TqSys_bTypFu_out = TqSys_bTypFu_B;
      TqSys_idxTqAccu_out = TqSys_idxTqAccu_B;
      TqSys_stTypPwtCf_out = TqSys_stTypPwtCf_B;
  }
  (void)Rte_Write_P_EOM_tiEngModStp_EOM_tiEngModStp(EOM_tiEngModStp_out);
  (void)Rte_Write_P_EOM_tiEngCrankStrt_EOM_tiEngCrankStrt(EOM_tiEngCrankStrt_out);
  (void)Rte_Write_P_EOM_tiEngRun_EOM_tiEngRun(EOM_tiEngRun_out);
  (void)Rte_Write_P_EOM_tiEngRunStrt_EOM_tiEngRunStrt(EOM_tiEngRunStrt_out);
  (void)Rte_Write_P_TqSys_bAcvVehSpdCtlLim_TqSys_bAcvVehSpdCtlLim(TqSys_bAcvVehSpdCtlLim_out);
  (void)Rte_Write_P_TqSys_bAcvVehSpdCtlReg_TqSys_bAcvVehSpdCtlReg(TqSys_bAcvVehSpdCtlReg_out);
  (void)Rte_Write_P_TqSys_bTypFu_TqSys_bTypFu(TqSys_bTypFu_out);
  (void)Rte_Write_P_TqSys_idxTqAccu_TqSys_idxTqAccu(TqSys_idxTqAccu_out);
  (void)Rte_Write_P_TqSys_stTypPwtCf_TqSys_stTypPwtCf(TqSys_stTypPwtCf_out);

}

void RE_TqTreat_005_MSE(void)
{


      TqTreat_005_MSE_ini();

      (void)Rte_Write_P_Ext_nEng1_Ext_nEng1(0);
      (void)Rte_Write_P_Ext_nEng2_Ext_nEng2(0);
      (void)Rte_Write_P_Ext_nEngAvr_Ext_nEngAvr(0);
      (void)Rte_Write_P_Ext_nEngClc0_Ext_nEngClc0(0);
      (void)Rte_Write_P_Ext_nEngClc1_Ext_nEngClc1(0);

}

void RE_TqTreat_006_DRE(void)
{

  if (FALSE == TQTREAT_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      //(void)Rte_Read_R_TqSys_EveSync_VarElem_TqSys_EveSync_VarElem(&TqTreat_006_TqSys_EveSync_VarElem_in);
      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqTreat_006_Ext_nEng_in);
      (void)Rte_Read_R_Ext_nEngClc_Ext_nEngClc(&TqTreat_006_Ext_nEngClc_in);
      (void)Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&TqTreat_006_Ext_noCylEng_in);

      TqTreat_006_DRE_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      Ext_nEng1_out = Ext_nEng1_B;
      Ext_nEng2_out = Ext_nEng2_B;
      Ext_nEngAvr_out = Ext_nEngAvr_B;
      Ext_nEngClc0_out = Ext_nEngClc0_B;
      Ext_nEngClc1_out = Ext_nEngClc1_B;
  }
  (void)Rte_Write_P_Ext_nEng1_Ext_nEng1(Ext_nEng1_out);
  (void)Rte_Write_P_Ext_nEng2_Ext_nEng2(Ext_nEng2_out);
  (void)Rte_Write_P_Ext_nEngAvr_Ext_nEngAvr(Ext_nEngAvr_out);
  (void)Rte_Write_P_Ext_nEngClc0_Ext_nEngClc0(Ext_nEngClc0_out);
  (void)Rte_Write_P_Ext_nEngClc1_Ext_nEngClc1(Ext_nEngClc1_out);

}

void RE_TqTreat_007_MSE(void)
{


      TqTreat_007_MSE_ini();

      (void)Rte_Write_P_TreatTDC_nCkFil_TreatTDC_nCkFil(0);
      (void)Rte_Write_P_TreatTDC_nCkGrd_TreatTDC_nCkGrd(0);
      (void)Rte_Write_P_TreatTDC_nCkGrdFil_TreatTDC_nCkGrdFil(0);
      (void)Rte_Write_P_TreatTDC_nCkTDCDelta_TreatTDC_nCkTDCDelta(0);

}

void RE_TqTreat_008_DRE(void)
{

  if (FALSE == TQTREAT_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Ext_nEng_Ext_nEng(&TqTreat_008_Ext_nEng_in);
      (void)Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&TqTreat_008_Ext_tiTDC_in);
      (void)Rte_Read_R_TqDem_facGainFilTrv_nCk_TqDem_facGainFilTrv_nCk(&TqTreat_008_TqDem_facGainFilTrv_nCk_in);
//      (void)Rte_Read_R_TqSys_EveSync_TqTreatElem_TqSys_EveSync_TqTreatElem(&TqTreat_008_TqSys_EveSync_TqTreatElem_in);

      TqTreat_008_DRE_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      TreatTDC_nCkFil_out = TreatTDC_nCkFil_B;
      TreatTDC_nCkGrd_out = TreatTDC_nCkGrd_B;
      TreatTDC_nCkGrdFil_out = TreatTDC_nCkGrdFil_B;
      TreatTDC_nCkTDCDelta_out = TreatTDC_nCkTDCDelta_B;
  }
  (void)Rte_Write_P_TreatTDC_nCkFil_TreatTDC_nCkFil(TreatTDC_nCkFil_out);
  (void)Rte_Write_P_TreatTDC_nCkGrd_TreatTDC_nCkGrd(TreatTDC_nCkGrd_out);
  (void)Rte_Write_P_TreatTDC_nCkGrdFil_TreatTDC_nCkGrdFil(TreatTDC_nCkGrdFil_out);
  (void)Rte_Write_P_TreatTDC_nCkTDCDelta_TreatTDC_nCkTDCDelta(TreatTDC_nCkTDCDelta_out);

}

void RE_TqTreat_009_MSE(void)
{


//      TqTreat_009_MSE_ini();

      (void)Rte_Write_P_CoBrk_bAcvBrk_CoBrk_bAcvBrk(0);

}

void RE_TqTreat_010_TEV(void)
{

  if (FALSE == TQTREAT_ACTIVE_BYP_C)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_Brk_bBrkAuto_Brk_bBrkAuto(&TqTreat_010_Brk_bBrkAuto_in);
      (void)Rte_Read_R_Ext_bBrkPedPrss_Ext_bBrkPedPrss(&TqTreat_010_Ext_bBrkPedPrss_in);
      (void)Rte_Read_R_Ext_bSecBrkPedPrssMes_Ext_bSecBrkPedPrssMes(&TqTreat_010_Ext_bSecBrkPedPrssMes_in);

      TqTreat_010_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoBrk_bAcvBrk_out = CoBrk_bAcvBrk_B;
  }
  (void)Rte_Write_P_CoBrk_bAcvBrk_CoBrk_bAcvBrk(CoBrk_bAcvBrk_out);

}

#define TQTREAT_STOP_SEC_CODE
#include "TqTreat_MemMap.h"

#endif/*_TQTREAT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

