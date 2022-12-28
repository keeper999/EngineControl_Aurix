/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ProdElEm.c
* Description   : Interface AUTOSAR du module ProdElEm avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 30-May-2011(17:16:51)
*******************************************************************************/

#ifndef _PRODELEM_C_
#define _PRODELEM_C_
/*----------------------------------------------------------------------------
  INCLUDES
*----------------------------------------------------------------------------*/
#include "Rte_Type.h"
#include "dsfxp.h"
#include "Rte_ProdElEm.h"
#include "ProdElEm.h"
#include "ProdElEm_002_TEV_fct.h"
#include "ProdElEm_004_TEV_fct.h"
#include "ProdElEm_006_TEV_fct.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define PRODELEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEm_MemMap.h"
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ProdElEm_ModuleVersion_Major_MP = 4;
AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 ProdElEm_ModuleVersion_Minor_MP = 4;
#define PRODELEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEm_MemMap.h"

/*----------------------------------------------------------------------------
CHECK LIBRARY VERSION
*----------------------------------------------------------------------------*/

#define Module_LIB_PSA_VERSION_REQ_MAJ 4
#define Module_LIB_PSA_VERSION_REQ_MIN 2

#if defined(LIB_PSA_VERSION_MAJ) && defined(LIB_PSA_VERSION_MIN)
#if ((Module_LIB_PSA_VERSION_REQ_MAJ > LIB_PSA_VERSION_MAJ) || ((Module_LIB_PSA_VERSION_REQ_MAJ == LIB_PSA_VERSION_MAJ) && (Module_LIB_PSA_VERSION_REQ_MIN > LIB_PSA_VERSION_MIN)))
    #error "FNR_lib.* version is not compatible with current SWC version"
#endif
#endif

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PRODELEM_START_SEC_CALIB_BOOLEAN
#include "ProdElEm_MemMap.h"
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_002_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_004_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_006_TEV_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bAuthAntiAgiStra_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bWupAcv_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattAntiAgiAcvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattChProtAcvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattSoCMinProtAcvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattStopPrepAcvReq_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattTProtAcvReq_B = 1;
AR_MERGEABLE_CALIB_BOOLEAN Boolean ElProdMgt_bAcvCoefFilDftAlt_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bAntiAgiStraEfcChIdc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bAntiAgiStraEndIdc_B = 0;
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bAcvElCnsReq_B = 0;
#define PRODELEM_STOP_SEC_CALIB_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_8BIT
#include "ProdElEm_MemMap.h"
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_grdNegSlop_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_grdPosSlop_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_rElRecup_B = 50;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_rElRest_B = 50;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElLvlProd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElProd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSoC_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSt_B = 3;
AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_stProdPrgCh_B = 7;
AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_stProdPrgChDi_nEng_B = 4;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_bfAcvConstEm1_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_bfAcvConstEm2_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElProd_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstNegSlop_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstPosSlop_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstVoltMax_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstVoltMin_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElEProv_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stOptmElCf_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stOptmElStra_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stPrevElProdReq_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stSoCRefTyp_B = 1;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stStraVoltBatt_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_tiLdSoCAuthStop_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_ctStcAcvAntiAgiStra_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_ctStcCnclAntiAgiStra_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattAntiAgi_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattTProt_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattAntiAgi_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattTProt_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSoH_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_iAltEstim_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattChProt_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattChProt_B = 16;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElNw_B = 0;
AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_resBattItNorm_B = 80;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElProdMaxLdBatt_B = 250;
AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stPrgChReq_B = 7;
AR_MERGEABLE_CALIB_8BIT SInt8 BatMgt_iBattMaxCkg_B = -18;
#define PRODELEM_STOP_SEC_CALIB_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_16BIT
#include "ProdElEm_MemMap.h"
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rBattSoCSp_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMax_B = 1946;
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMin_B = 1562;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rBattSoCCor_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_resBattIt_B = 640;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattMes_B = 1536;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattOc_B = 1600;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattRstrt_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_iExctMax_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_tqAltEstim_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_uElProdSp_B = 1357;
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rThdRstrtAuthSoCCf1_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rThdStopAuthSoCCf2_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMinInc_B = 1562;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rOfsSoC_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rStcSoCMax_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rStcSoCMin_B = 1120;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_tiStcVoltBattDmg_B = 0;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattStrt_B = 1600;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattAntiAgi_B = 243;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattTProt_B = 243;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattAntiAgi_B = 195;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattTProt_B = 195;
AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_uBattSp_B = 1357;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattChProt_B = 12.1875;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattChProt_B = 15.1875;
AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattMinCkg_B = 1536;
AR_MERGEABLE_CALIB_16BIT SInt16 CoOptmEl_tqAlt_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 BatMgt_rSoCErrEstim_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 BatMgt_tBattMes_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_rSoCErrEstim_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_uOfs_uElProdSp_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 CoOptmEl_rOfsSoCSTT_B = 0;
AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_uOfsLossCor_B = 0;
#define PRODELEM_STOP_SEC_CALIB_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_32BIT
#include "ProdElEm_MemMap.h"
AR_MERGEABLE_CALIB_32BIT SInt32 BatMgt_iBattMes_B = 0;
#define PRODELEM_STOP_SEC_CALIB_32BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_VAR_BOOLEAN
#include "ProdElEm_MemMap.h"
static Boolean CoOptmEl_bMonRunTqAlt_out_prec;
static Boolean BatMgt_bMonRun_iBattMes_out_prec;
static Boolean BatMgt_bMonRun_resBattIt_out_prec;
static Boolean BatMgt_bMonRun_tBattMes_out_prec;
static Boolean BatMgt_bMonRun_uBattMes_out_prec;
static Boolean BatMgt_bMonRun_uBattRstrt_out_prec;
static Boolean BatMgt_bMonRun_uBattOc_out_prec;
static Boolean BatMgt_bMonRun_uBattStrt_out_prec;
static Boolean BatMgt_bMonRun_iBattMaxCkg_out_prec;
static Boolean BatMgt_bMonRun_rBattSoC_out_prec;
static Boolean BatMgt_bMonRun_uBattMinCkg_out_prec;
static Boolean ElProdMgt_bMonRunCorLoss_out_prec;
static Boolean ElProdMgt_bMonRunCorSpCur_out_prec;
#define PRODELEM_STOP_SEC_VAR_BOOLEAN
#include "ProdElEm_MemMap.h"

/*----------------------------------------------------------------------------*
  RUNNABLES DEFINITION
*----------------------------------------------------------------------------*/
#define PRODELEM_START_SEC_CODE
#include "ProdElEm_MemMap.h"

void RE_ProdElEm_001_MSE(void)
{


      ProdElEm_001_MSE_ini();

      (void)Rte_Write_P_CoOptmEl_bAuthAntiAgiStra_CoOptmEl_bAuthAntiAgiStra(1);
      (void)Rte_Write_P_CoOptmEl_bWupAcv_CoOptmEl_bWupAcv(0);
      (void)Rte_Write_P_CoOptmEl_grdNegSlop_CoOptmEl_grdNegSlop(16);
      (void)Rte_Write_P_CoOptmEl_grdPosSlop_CoOptmEl_grdPosSlop(16);
      (void)Rte_Write_P_CoOptmEl_rBattSoCSp_CoOptmEl_rBattSoCSp(1120);
      (void)Rte_Write_P_CoOptmEl_rElRecup_CoOptmEl_rElRecup(50);
      (void)Rte_Write_P_CoOptmEl_rElRest_CoOptmEl_rElRest(50);
      (void)Rte_Write_P_CoOptmEl_stElLvlProd_CoOptmEl_stElLvlProd(0);
      (void)Rte_Write_P_CoOptmEl_stElProd_CoOptmEl_stElProd(0);
      (void)Rte_Write_P_CoOptmEl_tqAlt_CoOptmEl_tqAlt(0);
      (void)Rte_Write_P_CoOptmEl_uMax_CoOptmEl_uMax(1946);
      (void)Rte_Write_P_CoOptmEl_uMin_CoOptmEl_uMin(1562);
      (void)Rte_Write_P_CoOptmEl_bfAcvConstEm1_CoOptmEl_bfAcvConstEm1(0);
      (void)Rte_Write_P_CoOptmEl_bfAcvConstEm2_CoOptmEl_bfAcvConstEm2(0);
      (void)Rte_Write_P_CoOptmEl_iElProd_CoOptmEl_iElProd(0);
      (void)Rte_Write_P_CoOptmEl_rOfsSoCSTT_CoOptmEl_rOfsSoCSTT(0);
      (void)Rte_Write_P_CoOptmEl_rThdRstrtAuthSoCCf1_CoOptmEl_rThdRstrtAuthSoCCf1(1120);
      (void)Rte_Write_P_CoOptmEl_rThdStopAuthSoCCf2_CoOptmEl_rThdStopAuthSoCCf2(1120);
      (void)Rte_Write_P_CoOptmEl_stDetConstNegSlop_CoOptmEl_stDetConstNegSlop(0);
      (void)Rte_Write_P_CoOptmEl_stDetConstPosSlop_CoOptmEl_stDetConstPosSlop(0);
      (void)Rte_Write_P_CoOptmEl_stDetConstVoltMax_CoOptmEl_stDetConstVoltMax(0);
      (void)Rte_Write_P_CoOptmEl_stDetConstVoltMin_CoOptmEl_stDetConstVoltMin(0);
      (void)Rte_Write_P_CoOptmEl_stElEProv_CoOptmEl_stElEProv(1);
      (void)Rte_Write_P_CoOptmEl_stOptmElCf_CoOptmEl_stOptmElCf(0);
      (void)Rte_Write_P_CoOptmEl_stOptmElStra_CoOptmEl_stOptmElStra(0);
      (void)Rte_Write_P_CoOptmEl_stPrevElProdReq_CoOptmEl_stPrevElProdReq(0);
      (void)Rte_Write_P_CoOptmEl_stSoCRefTyp_CoOptmEl_stSoCRefTyp(1);
      (void)Rte_Write_P_CoOptmEl_stStraVoltBatt_CoOptmEl_stStraVoltBatt(0);
      (void)Rte_Write_P_CoOptmEl_tiLdSoCAuthStop_CoOptmEl_tiLdSoCAuthStop(0);
      (void)Rte_Write_P_CoOptmEl_uMinInc_CoOptmEl_uMinInc(1562);
      (void)Rte_Write_P_CoOptmEl_iElNw_CoOptmEl_iElNw(0);
      (void)Rte_Write_P_CoOptmEl_iElProdMaxLdBatt_CoOptmEl_iElProdMaxLdBatt(250);
      (void)Rte_Write_P_CoOptmEl_bAcvElCnsReq_CoOptmEl_bAcvElCnsReq(0);
      (void)Rte_Write_P_CoOptmEl_stPrgChReq_CoOptmEl_stPrgChReq(7);

}

void RE_ProdElEm_002_TEV(void)
{

  if (FALSE == RE_PRODELEM_002_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_BatMgt_iBattMes_BatMgt_iBattMes(&ProdElEm_002_BatMgt_iBattMes_in);
      (void)Rte_Read_R_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(&ProdElEm_002_BatMgt_rBattSoCCor_in);
      (void)Rte_Read_R_BatMgt_rSoCErrEstim_BatMgt_rSoCErrEstim(&ProdElEm_002_BatMgt_rSoCErrEstim_in);
      (void)Rte_Read_R_BatMgt_stBattSoC_BatMgt_stBattSoC(&ProdElEm_002_BatMgt_stBattSoC_in);
      (void)Rte_Read_R_BatMgt_tBattMes_BatMgt_tBattMes(&ProdElEm_002_BatMgt_tBattMes_in);
      (void)Rte_Read_R_BatMgt_uBattMes_BatMgt_uBattMes(&ProdElEm_002_BatMgt_uBattMes_in);
      (void)Rte_Read_R_CoEmSTT_rThdRstrtAuthSoCBatt_CoEmSTT_rThdRstrtAuthSoCBatt(&ProdElEm_002_CoEmSTT_rThdRstrtAuthSoCBatt_in);
      (void)Rte_Read_R_ECU_bWkuMain_ECU_bWkuMain(&ProdElEm_002_ECU_bWkuMain_in);
      (void)Rte_Read_R_ElProdMgt_tqAltEstim_ElProdMgt_tqAltEstim(&ProdElEm_002_ElProdMgt_tqAltEstim_in);
      (void)Rte_Read_R_ElProdMgt_uElProdSp_ElProdMgt_uElProdSp(&ProdElEm_002_ElProdMgt_uElProdSp_in);
      (void)Rte_Read_R_ElProdMgt_uOfs_uElProdSp_ElProdMgt_uOfs_uElProdSp(&ProdElEm_002_ElProdMgt_uOfs_uElProdSp_in);
      (void)Rte_Read_R_Ext_bAuthWupElMgt_Ext_bAuthWupElMgt(&ProdElEm_002_Ext_bAuthWupElMgt_in);
      (void)Rte_Read_R_Ext_bNotAvl_rBattSoC_Ext_bNotAvl_rBattSoC(&ProdElEm_002_Ext_bNotAvl_rBattSoC_in);
      (void)Rte_Read_R_Ext_bNotAvl_tBattMes_Ext_bNotAvl_tBattMes(&ProdElEm_002_Ext_bNotAvl_tBattMes_in);
      (void)Rte_Read_R_Ext_bSTTCf_Ext_bSTTCf(&ProdElEm_002_Ext_bSTTCf_in);
      (void)Rte_Read_R_Ext_rCorSoCHyb_Ext_rCorSoCHyb(&ProdElEm_002_Ext_rCorSoCHyb_in);
      (void)Rte_Read_R_Ext_spdVeh_Ext_spdVeh(&ProdElEm_002_Ext_spdVeh_in);
      (void)Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&ProdElEm_002_Ext_stElProdCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ProdElEm_002_Ext_tCoMes_in);
      (void)Rte_Read_R_MCT_tqFrntMchEstim_MCT_tqFrntMchEstim(&ProdElEm_002_MCT_tqFrntMchEstim_in);
      (void)Rte_Read_R_TqLimUH_bFrzReqTqVoltCtl_TqLimUH_bFrzReqTqVoltCtl(&ProdElEm_002_TqLimUH_bFrzReqTqVoltCtl_in);
      (void)Rte_Read_R_TqLimUH_stDrivTyp_TqLimUH_stDrivTyp(&ProdElEm_002_TqLimUH_stDrivTyp_in);
      (void)Rte_Read_R_TqLimUH_stReqBlsVoltCtl_TqLimUH_stReqBlsVoltCtl(&ProdElEm_002_TqLimUH_stReqBlsVoltCtl_in);
      (void)Rte_Read_R_TqLimUH_stReqUnBlsVoltCtl_TqLimUH_stReqUnBlsVoltCtl(&ProdElEm_002_TqLimUH_stReqUnBlsVoltCtl_in);
      (void)Rte_Read_R_Ext_bArchiCf_Ext_bArchiCf(&ProdElEm_002_Ext_bArchiCf_in);
      (void)Rte_Read_R_Ext_bNotAvl_iBattMes_Ext_bNotAvl_iBattMes(&ProdElEm_002_Ext_bNotAvl_iBattMes_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattClc_Ext_bNotAvl_uBattClc(&ProdElEm_002_Ext_bNotAvl_uBattClc_in);
      (void)Rte_Read_R_AccP_rAccP_AccP_rAccP(&ProdElEm_002_AccP_rAccP_in);
      (void)Rte_Read_R_BatMgt_bBattAntiAgiAcvReq_BatMgt_bBattAntiAgiAcvReq(&ProdElEm_002_BatMgt_bBattAntiAgiAcvReq_in);
      (void)Rte_Read_R_BatMgt_bBattChProtAcvReq_BatMgt_bBattChProtAcvReq(&ProdElEm_002_BatMgt_bBattChProtAcvReq_in);
      (void)Rte_Read_R_BatMgt_bBattSoCMinProtAcvReq_BatMgt_bBattSoCMinProtAcvReq(&ProdElEm_002_BatMgt_bBattSoCMinProtAcvReq_in);
      (void)Rte_Read_R_BatMgt_bBattStopPrepAcvReq_BatMgt_bBattStopPrepAcvReq(&ProdElEm_002_BatMgt_bBattStopPrepAcvReq_in);
      (void)Rte_Read_R_BatMgt_bBattTProtAcvReq_BatMgt_bBattTProtAcvReq(&ProdElEm_002_BatMgt_bBattTProtAcvReq_in);
      (void)Rte_Read_R_BatMgt_grdNegSlopBattAntiAgi_BatMgt_grdNegSlopBattAntiAgi(&ProdElEm_002_BatMgt_grdNegSlopBattAntiAgi_in);
      (void)Rte_Read_R_BatMgt_grdNegSlopBattTProt_BatMgt_grdNegSlopBattTProt(&ProdElEm_002_BatMgt_grdNegSlopBattTProt_in);
      (void)Rte_Read_R_BatMgt_grdPosSlopBattAntiAgi_BatMgt_grdPosSlopBattAntiAgi(&ProdElEm_002_BatMgt_grdPosSlopBattAntiAgi_in);
      (void)Rte_Read_R_BatMgt_grdPosSlopBattTProt_BatMgt_grdPosSlopBattTProt(&ProdElEm_002_BatMgt_grdPosSlopBattTProt_in);
      (void)Rte_Read_R_BatMgt_rOfsSoC_BatMgt_rOfsSoC(&ProdElEm_002_BatMgt_rOfsSoC_in);
      (void)Rte_Read_R_BatMgt_stBattSoH_BatMgt_stBattSoH(&ProdElEm_002_BatMgt_stBattSoH_in);
      (void)Rte_Read_R_BatMgt_uReqEmMaxBattAntiAgi_BatMgt_uReqEmMaxBattAntiAgi(&ProdElEm_002_BatMgt_uReqEmMaxBattAntiAgi_in);
      (void)Rte_Read_R_BatMgt_uReqEmMaxBattTProt_BatMgt_uReqEmMaxBattTProt(&ProdElEm_002_BatMgt_uReqEmMaxBattTProt_in);
      (void)Rte_Read_R_BatMgt_uReqEmMinBattAntiAgi_BatMgt_uReqEmMinBattAntiAgi(&ProdElEm_002_BatMgt_uReqEmMinBattAntiAgi_in);
      (void)Rte_Read_R_BatMgt_uReqEmMinBattTProt_BatMgt_uReqEmMinBattTProt(&ProdElEm_002_BatMgt_uReqEmMinBattTProt_in);
      (void)Rte_Read_R_CoEmCkg_stStrtRstrtFbCmd_CoEmCkg_stStrtRstrtFbCmd(&ProdElEm_002_CoEmCkg_stStrtRstrtFbCmd_in);
      (void)Rte_Read_R_CoEmSTT_bVSSAcvSt_CoEmSTT_bVSSAcvSt(&ProdElEm_002_CoEmSTT_bVSSAcvSt_in);
      (void)Rte_Read_R_CoEmSTT_iElNwStop_CoEmSTT_iElNwStop(&ProdElEm_002_CoEmSTT_iElNwStop_in);
      (void)Rte_Read_R_CoEmSTT_rThdStopAuthSoCCf1_CoEmSTT_rThdStopAuthSoCCf1(&ProdElEm_002_CoEmSTT_rThdStopAuthSoCCf1_in);
      (void)Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&ProdElEm_002_CoPt_noEgdGearCord_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&ProdElEm_002_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_CoPtUH_stTypSTTNotAvl_CoPtUH_stTypSTTNotAvl(&ProdElEm_002_CoPtUH_stTypSTTNotAvl_in);
      (void)Rte_Read_R_CoStrtRStrt_stAcvReq_CoStrtRStrt_stAcvReq(&ProdElEm_002_CoStrtRStrt_stAcvReq_in);
      (void)Rte_Read_R_ElecMgt_stPrioVoltMax_ElecMgt_stPrioVoltMax(&ProdElEm_002_ElecMgt_stPrioVoltMax_in);
      (void)Rte_Read_R_ElecMgt_stPrioVoltMin_ElecMgt_stPrioVoltMin(&ProdElEm_002_ElecMgt_stPrioVoltMin_in);
      (void)Rte_Read_R_ElecMgt_uReqProdMax_ElecMgt_uReqProdMax(&ProdElEm_002_ElecMgt_uReqProdMax_in);
      (void)Rte_Read_R_ElecMgt_uReqProdMin_ElecMgt_uReqProdMin(&ProdElEm_002_ElecMgt_uReqProdMin_in);
      (void)Rte_Read_R_ElecMgt_uReqProdSlope_ElecMgt_uReqProdSlope(&ProdElEm_002_ElecMgt_uReqProdSlope_in);
      (void)Rte_Read_R_ElProdMgt_bAcvCoefFilDftAlt_ElProdMgt_bAcvCoefFilDftAlt(&ProdElEm_002_ElProdMgt_bAcvCoefFilDftAlt_in);
      (void)Rte_Read_R_ElProdMgt_iAltEstim_ElProdMgt_iAltEstim(&ProdElEm_002_ElProdMgt_iAltEstim_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEm_002_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_bfAcvConstElMgt1_Ext_bfAcvConstElMgt1(&ProdElEm_002_Ext_bfAcvConstElMgt1_in);
      (void)Rte_Read_R_Ext_bfAcvConstElMgt2_Ext_bfAcvConstElMgt2(&ProdElEm_002_Ext_bfAcvConstElMgt2_in);
      (void)Rte_Read_R_Ext_bfAcvConstElMgt3_Ext_bfAcvConstElMgt3(&ProdElEm_002_Ext_bfAcvConstElMgt3_in);
      (void)Rte_Read_R_Ext_bfAcvConstEng1_Ext_bfAcvConstEng1(&ProdElEm_002_Ext_bfAcvConstEng1_in);
      (void)Rte_Read_R_Ext_bfAcvConstReTra1_Ext_bfAcvConstReTra1(&ProdElEm_002_Ext_bfAcvConstReTra1_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&ProdElEm_002_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_Ext_stAltClasCf_Ext_stAltClasCf(&ProdElEm_002_Ext_stAltClasCf_in);
      (void)Rte_Read_R_Ext_stVSSCf_Ext_stVSSCf(&ProdElEm_002_Ext_stVSSCf_in);
      (void)Rte_Read_R_RvAltMgt_iRvAltGenModEstim_RvAltMgt_iRvAltGenModEstim(&ProdElEm_002_RvAltMgt_iRvAltGenModEstim_in);
      (void)Rte_Read_R_RvAltMgt_tqRvAltGenModEstim_RvAltMgt_tqRvAltGenModEstim(&ProdElEm_002_RvAltMgt_tqRvAltGenModEstim_in);
      (void)Rte_Read_R_RvAltMgt_tRvAltECUMes_RvAltMgt_tRvAltECUMes(&ProdElEm_002_RvAltMgt_tRvAltECUMes_in);
      (void)Rte_Read_R_StopStrtEng_stCdnNxtCkg_StopStrtEng_stCdnNxtCkg(&ProdElEm_002_StopStrtEng_stCdnNxtCkg_in);
      (void)Rte_Read_R_TqDem_bTqGrdLim_TqDem_bTqGrdLim(&ProdElEm_002_TqDem_bTqGrdLim_in);
      (void)Rte_Read_R_BatMgt_uReqEmMinBattChProt_BatMgt_uReqEmMinBattChProt(&ProdElEm_002_BatMgt_uReqEmMinBattChProt_in);
      (void)Rte_Read_R_BatMgt_uReqEmMaxBattChProt_BatMgt_uReqEmMaxBattChProt(&ProdElEm_002_BatMgt_uReqEmMaxBattChProt_in);
      (void)Rte_Read_R_BatMgt_grdPosSlopBattChProt_BatMgt_grdPosSlopBattChProt(&ProdElEm_002_BatMgt_grdPosSlopBattChProt_in);
      (void)Rte_Read_R_BatMgt_grdNegSlopBattChProt_BatMgt_grdNegSlopBattChProt(&ProdElEm_002_BatMgt_grdNegSlopBattChProt_in);
      (void)Rte_Read_R_CoPtUH_bTestPrvtBltAcv_CoPtUH_bTestPrvtBltAcv(&ProdElEm_002_CoPtUH_bTestPrvtBltAcv_in);
      (void)Rte_Read_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(&ProdElEm_002_CoStrtRStrt_stEngStrtReq_in);
      (void)Rte_Read_R_ElProdMgt_uOfsLossCor_ElProdMgt_uOfsLossCor(&ProdElEm_002_ElProdMgt_uOfsLossCor_in);
      (void)Rte_Read_R_Ext_rAltCycOp_Ext_rAltCycOp(&ProdElEm_002_Ext_rAltCycOp_in);
      (void)Rte_Read_R_RvAltMgt_stRvAltModReq_RvAltMgt_stRvAltModReq(&ProdElEm_002_RvAltMgt_stRvAltModReq_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&ProdElEm_002_Ext_tAir_in);
      (void)Rte_Read_R_TqLimUH_bfAcvConstFrntTra1_TqLimUH_bfAcvConstFrntTra1(&ProdElEm_002_TqLimUH_bfAcvConstFrntTra1_in);
      (void)Rte_Read_R_VSSCtzMgt_bAcvElCnsReq_VSSCtzMgt_bAcvElCnsReq(&ProdElEm_002_VSSCtzMgt_bAcvElCnsReq_in);

      Rte_Call_R_FRM_bAcvCoOptmElDftLvlProd_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElDftLvlProd_in);
      ProdElEm_002_FRM_bAcvCoOptmElDftLvlProd_in = !ProdElEm_002_FRM_bAcvCoOptmElDftLvlProd_in;
      Rte_Call_R_FRM_bAcvCoOptmElDftSoC_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElDftSoC_in);
      ProdElEm_002_FRM_bAcvCoOptmElDftSoC_in = !ProdElEm_002_FRM_bAcvCoOptmElDftSoC_in;
      Rte_Call_R_FRM_bAcvCoOptmElSatLvlProd_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElSatLvlProd_in);
      ProdElEm_002_FRM_bAcvCoOptmElSatLvlProd_in = !ProdElEm_002_FRM_bAcvCoOptmElSatLvlProd_in;
      Rte_Call_R_FRM_bInhCoOptmElElMgtReq_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElElMgtReq_in);
      ProdElEm_002_FRM_bInhCoOptmElElMgtReq_in = !ProdElEm_002_FRM_bInhCoOptmElElMgtReq_in;
      Rte_Call_R_FRM_bInhCoOptmElEngReq_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElEngReq_in);
      ProdElEm_002_FRM_bInhCoOptmElEngReq_in = !ProdElEm_002_FRM_bInhCoOptmElEngReq_in;
      Rte_Call_R_FRM_bInhCoOptmElFrntTraReq_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElFrntTraReq_in);
      ProdElEm_002_FRM_bInhCoOptmElFrntTraReq_in = !ProdElEm_002_FRM_bInhCoOptmElFrntTraReq_in;
      Rte_Call_R_FRM_bInhCoOptmElFrzLvlProd_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElFrzLvlProd_in);
      ProdElEm_002_FRM_bInhCoOptmElFrzLvlProd_in = !ProdElEm_002_FRM_bInhCoOptmElFrzLvlProd_in;
      Rte_Call_R_FRM_bInhCoOptmElReTraReq_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElReTraReq_in);
      ProdElEm_002_FRM_bInhCoOptmElReTraReq_in = !ProdElEm_002_FRM_bInhCoOptmElReTraReq_in;
      Rte_Call_R_FRM_bInhCoOptmElStra_tAirExt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElStra_tAirExt_in);
      ProdElEm_002_FRM_bInhCoOptmElStra_tAirExt_in = !ProdElEm_002_FRM_bInhCoOptmElStra_tAirExt_in;
      Rte_Call_R_FRM_bInhCoOptmElTHom_tAirExt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElTHom_tAirExt_in);
      ProdElEm_002_FRM_bInhCoOptmElTHom_tAirExt_in = !ProdElEm_002_FRM_bInhCoOptmElTHom_tAirExt_in;
      Rte_Call_R_FRM_bInhCoOptmElTHom_tBatt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElTHom_tBatt_in);
      ProdElEm_002_FRM_bInhCoOptmElTHom_tBatt_in = !ProdElEm_002_FRM_bInhCoOptmElTHom_tBatt_in;
      Rte_Call_R_FRM_bInhCoOptmElWup_tBatt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElWup_tBatt_in);
      ProdElEm_002_FRM_bInhCoOptmElWup_tBatt_in = !ProdElEm_002_FRM_bInhCoOptmElWup_tBatt_in;
      Rte_Call_R_FRM_bInhCoOptmElWupElMgt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElWupElMgt_in);
      ProdElEm_002_FRM_bInhCoOptmElWupElMgt_in = !ProdElEm_002_FRM_bInhCoOptmElWupElMgt_in;
      Rte_Call_R_FRM_bAcvCoOptmEl_tBatt_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmEl_tBatt_in);
      ProdElEm_002_FRM_bAcvCoOptmEl_tBatt_in = !ProdElEm_002_FRM_bAcvCoOptmEl_tBatt_in;
      Rte_Call_R_FRM_bAcvCoOptmEl_tCo_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmEl_tCo_in);
      ProdElEm_002_FRM_bAcvCoOptmEl_tCo_in = !ProdElEm_002_FRM_bAcvCoOptmEl_tCo_in;
      Rte_Call_R_FRM_bAcvCoOptmElBattElEProv_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElBattElEProv_in);
      ProdElEm_002_FRM_bAcvCoOptmElBattElEProv_in = !ProdElEm_002_FRM_bAcvCoOptmElBattElEProv_in;
      Rte_Call_R_FRM_bAcvCoOptmElProdElEProv_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElProdElEProv_in);
      ProdElEm_002_FRM_bAcvCoOptmElProdElEProv_in = !ProdElEm_002_FRM_bAcvCoOptmElProdElEProv_in;
      Rte_Call_R_FRM_bAcvCoOptmElSlopStra_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElSlopStra_in);
      ProdElEm_002_FRM_bAcvCoOptmElSlopStra_in = !ProdElEm_002_FRM_bAcvCoOptmElSlopStra_in;
      Rte_Call_R_FRM_bAcvCoOptmElSoCSpDftVal_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElSoCSpDftVal_in);
      ProdElEm_002_FRM_bAcvCoOptmElSoCSpDftVal_in = !ProdElEm_002_FRM_bAcvCoOptmElSoCSpDftVal_in;
      Rte_Call_R_FRM_bInhCoOptmElBackUpStra_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElBackUpStra_in);
      ProdElEm_002_FRM_bInhCoOptmElBackUpStra_in = !ProdElEm_002_FRM_bInhCoOptmElBackUpStra_in;
      Rte_Call_R_FRM_bInhCoOptmElBlsProd_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElBlsProd_in);
      ProdElEm_002_FRM_bInhCoOptmElBlsProd_in = !ProdElEm_002_FRM_bInhCoOptmElBlsProd_in;
      Rte_Call_R_FRM_bInhCoOptmElCurAuxEstim_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElCurAuxEstim_in);
      ProdElEm_002_FRM_bInhCoOptmElCurAuxEstim_in = !ProdElEm_002_FRM_bInhCoOptmElCurAuxEstim_in;
      Rte_Call_R_FRM_bInhCoOptmElRvAltLoss_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElRvAltLoss_in);
      ProdElEm_002_FRM_bInhCoOptmElRvAltLoss_in = !ProdElEm_002_FRM_bInhCoOptmElRvAltLoss_in;
      Rte_Call_R_FRM_bInhCoOptmElTHom_iBatt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElTHom_iBatt_in);
      ProdElEm_002_FRM_bInhCoOptmElTHom_iBatt_in = !ProdElEm_002_FRM_bInhCoOptmElTHom_iBatt_in;
      Rte_Call_R_FRM_bInhCoOptmElTHom_spdVeh_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElTHom_spdVeh_in);
      ProdElEm_002_FRM_bInhCoOptmElTHom_spdVeh_in = !ProdElEm_002_FRM_bInhCoOptmElTHom_spdVeh_in;
      Rte_Call_R_FRM_bInhCoOptmElTHomElMgt_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElTHomElMgt_in);
      ProdElEm_002_FRM_bInhCoOptmElTHomElMgt_in = !ProdElEm_002_FRM_bInhCoOptmElTHomElMgt_in;
      Rte_Call_R_FRM_bInhCoOptmElElMgtOldReq_GetFunctionPermission(& ProdElEm_002_FRM_bInhCoOptmElElMgtOldReq_in);
      ProdElEm_002_FRM_bInhCoOptmElElMgtOldReq_in = !ProdElEm_002_FRM_bInhCoOptmElElMgtOldReq_in;
      Rte_Call_R_FRM_bAcvCoOptmElMinSoCReq_GetFunctionPermission(& ProdElEm_002_FRM_bAcvCoOptmElMinSoCReq_in);
      ProdElEm_002_FRM_bAcvCoOptmElMinSoCReq_in = !ProdElEm_002_FRM_bAcvCoOptmElMinSoCReq_in;
      ProdElEm_002_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      CoOptmEl_bAuthAntiAgiStra_out = CoOptmEl_bAuthAntiAgiStra_B;
      CoOptmEl_bWupAcv_out = CoOptmEl_bWupAcv_B;
      CoOptmEl_grdNegSlop_out = CoOptmEl_grdNegSlop_B;
      CoOptmEl_grdPosSlop_out = CoOptmEl_grdPosSlop_B;
      CoOptmEl_rBattSoCSp_out = CoOptmEl_rBattSoCSp_B;
      CoOptmEl_rElRecup_out = CoOptmEl_rElRecup_B;
      CoOptmEl_rElRest_out = CoOptmEl_rElRest_B;
      CoOptmEl_stElLvlProd_out = CoOptmEl_stElLvlProd_B;
      CoOptmEl_stElProd_out = CoOptmEl_stElProd_B;
      CoOptmEl_tqAlt_out = CoOptmEl_tqAlt_B;
      CoOptmEl_uMax_out = CoOptmEl_uMax_B;
      CoOptmEl_uMin_out = CoOptmEl_uMin_B;
      CoOptmEl_bfAcvConstEm1_out = CoOptmEl_bfAcvConstEm1_B;
      CoOptmEl_bfAcvConstEm2_out = CoOptmEl_bfAcvConstEm2_B;
      CoOptmEl_iElProd_out = CoOptmEl_iElProd_B;
      CoOptmEl_rOfsSoCSTT_out = CoOptmEl_rOfsSoCSTT_B;
      CoOptmEl_rThdRstrtAuthSoCCf1_out = CoOptmEl_rThdRstrtAuthSoCCf1_B;
      CoOptmEl_rThdStopAuthSoCCf2_out = CoOptmEl_rThdStopAuthSoCCf2_B;
      CoOptmEl_stDetConstNegSlop_out = CoOptmEl_stDetConstNegSlop_B;
      CoOptmEl_stDetConstPosSlop_out = CoOptmEl_stDetConstPosSlop_B;
      CoOptmEl_stDetConstVoltMax_out = CoOptmEl_stDetConstVoltMax_B;
      CoOptmEl_stDetConstVoltMin_out = CoOptmEl_stDetConstVoltMin_B;
      CoOptmEl_stElEProv_out = CoOptmEl_stElEProv_B;
      CoOptmEl_stOptmElCf_out = CoOptmEl_stOptmElCf_B;
      CoOptmEl_stOptmElStra_out = CoOptmEl_stOptmElStra_B;
      CoOptmEl_stPrevElProdReq_out = CoOptmEl_stPrevElProdReq_B;
      CoOptmEl_stSoCRefTyp_out = CoOptmEl_stSoCRefTyp_B;
      CoOptmEl_stStraVoltBatt_out = CoOptmEl_stStraVoltBatt_B;
      CoOptmEl_tiLdSoCAuthStop_out = CoOptmEl_tiLdSoCAuthStop_B;
      CoOptmEl_uMinInc_out = CoOptmEl_uMinInc_B;
      CoOptmEl_iElNw_out = CoOptmEl_iElNw_B;
      CoOptmEl_iElProdMaxLdBatt_out = CoOptmEl_iElProdMaxLdBatt_B;
      CoOptmEl_bAcvElCnsReq_out = CoOptmEl_bAcvElCnsReq_B;
      CoOptmEl_stPrgChReq_out = CoOptmEl_stPrgChReq_B;
  }
  (void)Rte_Write_P_CoOptmEl_bAuthAntiAgiStra_CoOptmEl_bAuthAntiAgiStra(CoOptmEl_bAuthAntiAgiStra_out);
  (void)Rte_Write_P_CoOptmEl_bWupAcv_CoOptmEl_bWupAcv(CoOptmEl_bWupAcv_out);
  (void)Rte_Write_P_CoOptmEl_grdNegSlop_CoOptmEl_grdNegSlop(CoOptmEl_grdNegSlop_out);
  (void)Rte_Write_P_CoOptmEl_grdPosSlop_CoOptmEl_grdPosSlop(CoOptmEl_grdPosSlop_out);
  (void)Rte_Write_P_CoOptmEl_rBattSoCSp_CoOptmEl_rBattSoCSp(CoOptmEl_rBattSoCSp_out);
  (void)Rte_Write_P_CoOptmEl_rElRecup_CoOptmEl_rElRecup(CoOptmEl_rElRecup_out);
  (void)Rte_Write_P_CoOptmEl_rElRest_CoOptmEl_rElRest(CoOptmEl_rElRest_out);
  (void)Rte_Write_P_CoOptmEl_stElLvlProd_CoOptmEl_stElLvlProd(CoOptmEl_stElLvlProd_out);
  (void)Rte_Write_P_CoOptmEl_stElProd_CoOptmEl_stElProd(CoOptmEl_stElProd_out);
  (void)Rte_Write_P_CoOptmEl_tqAlt_CoOptmEl_tqAlt(CoOptmEl_tqAlt_out);
  (void)Rte_Write_P_CoOptmEl_uMax_CoOptmEl_uMax(CoOptmEl_uMax_out);
  (void)Rte_Write_P_CoOptmEl_uMin_CoOptmEl_uMin(CoOptmEl_uMin_out);
  (void)Rte_Write_P_CoOptmEl_bfAcvConstEm1_CoOptmEl_bfAcvConstEm1(CoOptmEl_bfAcvConstEm1_out);
  (void)Rte_Write_P_CoOptmEl_bfAcvConstEm2_CoOptmEl_bfAcvConstEm2(CoOptmEl_bfAcvConstEm2_out);
  (void)Rte_Write_P_CoOptmEl_iElProd_CoOptmEl_iElProd(CoOptmEl_iElProd_out);
  (void)Rte_Write_P_CoOptmEl_rOfsSoCSTT_CoOptmEl_rOfsSoCSTT(CoOptmEl_rOfsSoCSTT_out);
  (void)Rte_Write_P_CoOptmEl_rThdRstrtAuthSoCCf1_CoOptmEl_rThdRstrtAuthSoCCf1(CoOptmEl_rThdRstrtAuthSoCCf1_out);
  (void)Rte_Write_P_CoOptmEl_rThdStopAuthSoCCf2_CoOptmEl_rThdStopAuthSoCCf2(CoOptmEl_rThdStopAuthSoCCf2_out);
  (void)Rte_Write_P_CoOptmEl_stDetConstNegSlop_CoOptmEl_stDetConstNegSlop(CoOptmEl_stDetConstNegSlop_out);
  (void)Rte_Write_P_CoOptmEl_stDetConstPosSlop_CoOptmEl_stDetConstPosSlop(CoOptmEl_stDetConstPosSlop_out);
  (void)Rte_Write_P_CoOptmEl_stDetConstVoltMax_CoOptmEl_stDetConstVoltMax(CoOptmEl_stDetConstVoltMax_out);
  (void)Rte_Write_P_CoOptmEl_stDetConstVoltMin_CoOptmEl_stDetConstVoltMin(CoOptmEl_stDetConstVoltMin_out);
  (void)Rte_Write_P_CoOptmEl_stElEProv_CoOptmEl_stElEProv(CoOptmEl_stElEProv_out);
  (void)Rte_Write_P_CoOptmEl_stOptmElCf_CoOptmEl_stOptmElCf(CoOptmEl_stOptmElCf_out);
  (void)Rte_Write_P_CoOptmEl_stOptmElStra_CoOptmEl_stOptmElStra(CoOptmEl_stOptmElStra_out);
  (void)Rte_Write_P_CoOptmEl_stPrevElProdReq_CoOptmEl_stPrevElProdReq(CoOptmEl_stPrevElProdReq_out);
  (void)Rte_Write_P_CoOptmEl_stSoCRefTyp_CoOptmEl_stSoCRefTyp(CoOptmEl_stSoCRefTyp_out);
  (void)Rte_Write_P_CoOptmEl_stStraVoltBatt_CoOptmEl_stStraVoltBatt(CoOptmEl_stStraVoltBatt_out);
  (void)Rte_Write_P_CoOptmEl_tiLdSoCAuthStop_CoOptmEl_tiLdSoCAuthStop(CoOptmEl_tiLdSoCAuthStop_out);
  (void)Rte_Write_P_CoOptmEl_uMinInc_CoOptmEl_uMinInc(CoOptmEl_uMinInc_out);
  (void)Rte_Write_P_CoOptmEl_iElNw_CoOptmEl_iElNw(CoOptmEl_iElNw_out);
  (void)Rte_Write_P_CoOptmEl_iElProdMaxLdBatt_CoOptmEl_iElProdMaxLdBatt(CoOptmEl_iElProdMaxLdBatt_out);
  (void)Rte_Write_P_CoOptmEl_bAcvElCnsReq_CoOptmEl_bAcvElCnsReq(CoOptmEl_bAcvElCnsReq_out);
  (void)Rte_Write_P_CoOptmEl_stPrgChReq_CoOptmEl_stPrgChReq(CoOptmEl_stPrgChReq_out);

  if (FALSE == RE_PRODELEM_002_TEV_B)
  {

  /* Diag treatment : ProdElEm_TqAlt */
     if(CoOptmEl_bMonRunTqAlt_out==1)
     {
         /* Diag activation */
         if(CoOptmEl_bDgoTqAlt_out==1)
         {
             Rte_Call_R_CoOptmEl_TqAlt_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_CoOptmEl_TqAlt_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (CoOptmEl_bMonRunTqAlt_out_prec==1)
         {
             Rte_Call_R_CoOptmEl_TqAlt_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     CoOptmEl_bMonRunTqAlt_out_prec = CoOptmEl_bMonRunTqAlt_out;
  }

}

void RE_ProdElEm_003_MSE(void)
{


      ProdElEm_003_MSE_ini();

      (void)Rte_Write_P_BatMgt_iBattMes_BatMgt_iBattMes(0);
      (void)Rte_Write_P_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(1120);
      (void)Rte_Write_P_BatMgt_resBattIt_BatMgt_resBattIt(640);
      (void)Rte_Write_P_BatMgt_rSoCErrEstim_BatMgt_rSoCErrEstim(0);
      (void)Rte_Write_P_BatMgt_stBattSoC_BatMgt_stBattSoC(0);
      (void)Rte_Write_P_BatMgt_stBattSt_BatMgt_stBattSt(3);
      (void)Rte_Write_P_BatMgt_tBattMes_BatMgt_tBattMes(0);
      (void)Rte_Write_P_BatMgt_uBattMes_BatMgt_uBattMes(1536);
      (void)Rte_Write_P_BatMgt_uBattOc_BatMgt_uBattOc(1600);
      (void)Rte_Write_P_BatMgt_uBattRstrt_BatMgt_uBattRstrt(0);
      (void)Rte_Write_P_BatMgt_bBattAntiAgiAcvReq_BatMgt_bBattAntiAgiAcvReq(0);
      (void)Rte_Write_P_BatMgt_bBattChProtAcvReq_BatMgt_bBattChProtAcvReq(0);
      (void)Rte_Write_P_BatMgt_bBattSoCMinProtAcvReq_BatMgt_bBattSoCMinProtAcvReq(0);
      (void)Rte_Write_P_BatMgt_bBattStopPrepAcvReq_BatMgt_bBattStopPrepAcvReq(0);
      (void)Rte_Write_P_BatMgt_bBattTProtAcvReq_BatMgt_bBattTProtAcvReq(1);
      (void)Rte_Write_P_BatMgt_ctStcAcvAntiAgiStra_BatMgt_ctStcAcvAntiAgiStra(0);
      (void)Rte_Write_P_BatMgt_ctStcCnclAntiAgiStra_BatMgt_ctStcCnclAntiAgiStra(0);
      (void)Rte_Write_P_BatMgt_grdNegSlopBattAntiAgi_BatMgt_grdNegSlopBattAntiAgi(16);
      (void)Rte_Write_P_BatMgt_grdNegSlopBattTProt_BatMgt_grdNegSlopBattTProt(16);
      (void)Rte_Write_P_BatMgt_grdPosSlopBattAntiAgi_BatMgt_grdPosSlopBattAntiAgi(16);
      (void)Rte_Write_P_BatMgt_grdPosSlopBattTProt_BatMgt_grdPosSlopBattTProt(16);
      (void)Rte_Write_P_BatMgt_rOfsSoC_BatMgt_rOfsSoC(0);
      (void)Rte_Write_P_BatMgt_rStcSoCMax_BatMgt_rStcSoCMax(1120);
      (void)Rte_Write_P_BatMgt_rStcSoCMin_BatMgt_rStcSoCMin(1120);
      (void)Rte_Write_P_BatMgt_stBattSoH_BatMgt_stBattSoH(0);
      (void)Rte_Write_P_BatMgt_tiStcVoltBattDmg_BatMgt_tiStcVoltBattDmg(0);
      (void)Rte_Write_P_BatMgt_uBattStrt_BatMgt_uBattStrt(1600);
      (void)Rte_Write_P_BatMgt_uReqEmMaxBattAntiAgi_BatMgt_uReqEmMaxBattAntiAgi(243);
      (void)Rte_Write_P_BatMgt_uReqEmMaxBattTProt_BatMgt_uReqEmMaxBattTProt(243);
      (void)Rte_Write_P_BatMgt_uReqEmMinBattAntiAgi_BatMgt_uReqEmMinBattAntiAgi(195);
      (void)Rte_Write_P_BatMgt_uReqEmMinBattTProt_BatMgt_uReqEmMinBattTProt(195);
      (void)Rte_Write_P_BatMgt_uReqEmMinBattChProt_BatMgt_uReqEmMinBattChProt(12.1875);
      (void)Rte_Write_P_BatMgt_uReqEmMaxBattChProt_BatMgt_uReqEmMaxBattChProt(15.1875);
      (void)Rte_Write_P_BatMgt_grdPosSlopBattChProt_BatMgt_grdPosSlopBattChProt(16);
      (void)Rte_Write_P_BatMgt_grdNegSlopBattChProt_BatMgt_grdNegSlopBattChProt(16);
      (void)Rte_Write_P_BatMgt_bAntiAgiStraEfcChIdc_BatMgt_bAntiAgiStraEfcChIdc(0);
      (void)Rte_Write_P_BatMgt_bAntiAgiStraEndIdc_BatMgt_bAntiAgiStraEndIdc(0);
      (void)Rte_Write_P_BatMgt_iBattMaxCkg_BatMgt_iBattMaxCkg(-18);
      (void)Rte_Write_P_BatMgt_resBattItNorm_BatMgt_resBattItNorm(80);
      (void)Rte_Write_P_BatMgt_uBattMinCkg_BatMgt_uBattMinCkg(1536);

}

void RE_ProdElEm_004_TEV(void)
{

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_CoEmSTT_rThdStopAuthSoCBatt_CoEmSTT_rThdStopAuthSoCBatt(&ProdElEm_004_CoEmSTT_rThdStopAuthSoCBatt_in);
      (void)Rte_Read_R_ElProdMgt_uOfs_uElProdSp_ElProdMgt_uOfs_uElProdSp(&ProdElEm_004_ElProdMgt_uOfs_uElProdSp_in);
      (void)Rte_Read_R_Ext_bNotAvl_rBattSoC_Ext_bNotAvl_rBattSoC(&ProdElEm_004_Ext_bNotAvl_rBattSoC_in);
      (void)Rte_Read_R_Ext_bNotAvl_tBattMes_Ext_bNotAvl_tBattMes(&ProdElEm_004_Ext_bNotAvl_tBattMes_in);
      (void)Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&ProdElEm_004_Ext_stElProdCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ProdElEm_004_Ext_tCoMes_in);
      (void)Rte_Read_R_Afts_bInhStSoCBatt_Afts_bInhStSoCBatt(&ProdElEm_004_Afts_bInhStSoCBatt_in);
      (void)Rte_Read_R_CoOptmEl_bAuthAntiAgiStra_CoOptmEl_bAuthAntiAgiStra(&ProdElEm_004_CoOptmEl_bAuthAntiAgiStra_in);
      (void)Rte_Read_R_ElProdMgt_rSoCErrEstim_ElProdMgt_rSoCErrEstim(&ProdElEm_004_ElProdMgt_rSoCErrEstim_in);
      (void)Rte_Read_R_Ext_bNotAvl_iBattMes_Ext_bNotAvl_iBattMes(&ProdElEm_004_Ext_bNotAvl_iBattMes_in);
      (void)Rte_Read_R_Ext_bNotAvl_resBattIt_Ext_bNotAvl_resBattIt(&ProdElEm_004_Ext_bNotAvl_resBattIt_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattClc_Ext_bNotAvl_uBattClc(&ProdElEm_004_Ext_bNotAvl_uBattClc_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattOc_Ext_bNotAvl_uBattOc(&ProdElEm_004_Ext_bNotAvl_uBattOc_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattRstrt_Ext_bNotAvl_uBattRstrt(&ProdElEm_004_Ext_bNotAvl_uBattRstrt_in);
      (void)Rte_Read_R_Ext_ctDay_Ext_ctDay(&ProdElEm_004_Ext_ctDay_in);
      (void)Rte_Read_R_Ext_ctSec_Ext_ctSec(&ProdElEm_004_Ext_ctSec_in);
      (void)Rte_Read_R_Ext_iBattMes_Ext_iBattMes(&ProdElEm_004_Ext_iBattMes_in);
      (void)Rte_Read_R_Ext_rBattSoC_Ext_rBattSoC(&ProdElEm_004_Ext_rBattSoC_in);
      (void)Rte_Read_R_Ext_rBattSoCLoResl_Ext_rBattSoCLoResl(&ProdElEm_004_Ext_rBattSoCLoResl_in);
      (void)Rte_Read_R_Ext_resBattIt_Ext_resBattIt(&ProdElEm_004_Ext_resBattIt_in);
      (void)Rte_Read_R_Ext_stBattSoC_Ext_stBattSoC(&ProdElEm_004_Ext_stBattSoC_in);
      (void)Rte_Read_R_Ext_stBattTypCf_Ext_stBattTypCf(&ProdElEm_004_Ext_stBattTypCf_in);
      (void)Rte_Read_R_Ext_tBattMes_Ext_tBattMes(&ProdElEm_004_Ext_tBattMes_in);
      (void)Rte_Read_R_Ext_uBattClc_Ext_uBattClc(&ProdElEm_004_Ext_uBattClc_in);
      (void)Rte_Read_R_Ext_uBattMes_Ext_uBattMes(&ProdElEm_004_Ext_uBattMes_in);
      (void)Rte_Read_R_Ext_uBattOc_Ext_uBattOc(&ProdElEm_004_Ext_uBattOc_in);
      (void)Rte_Read_R_Ext_uBattRstrt_Ext_uBattRstrt(&ProdElEm_004_Ext_uBattRstrt_in);
      (void)Rte_Read_R_Ext_uBattStrt_Ext_uBattStrt(&ProdElEm_004_Ext_uBattStrt_in);
      (void)Rte_Read_R_CoOptmEl_uMax_CoOptmEl_uMax(&ProdElEm_004_CoOptmEl_uMax_in);
      (void)Rte_Read_R_CoPtSynt_stPwt_CoPtSynt_stPwt(&ProdElEm_004_CoPtSynt_stPwt_in);
      (void)Rte_Read_R_Ext_dstVehTotMes_Ext_dstVehTotMes(&ProdElEm_004_Ext_dstVehTotMes_in);
      (void)Rte_Read_R_Afts_bLrnRstReq_rOfsSoC_Afts_bLrnRstReq_rOfsSoC(&ProdElEm_004_Afts_bLrnRstReq_rOfsSoC_in);
      (void)Rte_Read_R_Afts_bRstReq_stSoHBatt_Afts_bRstReq_stSoHBatt(&ProdElEm_004_Afts_bRstReq_stSoHBatt_in);
      (void)Rte_Read_R_Afts_bRstReqStcBatt_Afts_bRstReqStcBatt(&ProdElEm_004_Afts_bRstReqStcBatt_in);
      (void)Rte_Read_R_CoOptmEl_stOptmElCf_CoOptmEl_stOptmElCf(&ProdElEm_004_CoOptmEl_stOptmElCf_in);
      (void)Rte_Read_R_CoOptmEl_stStraVoltBatt_CoOptmEl_stStraVoltBatt(&ProdElEm_004_CoOptmEl_stStraVoltBatt_in);
      (void)Rte_Read_R_CoOptmEl_tiLdSoCAuthStop_CoOptmEl_tiLdSoCAuthStop(&ProdElEm_004_CoOptmEl_tiLdSoCAuthStop_in);
      (void)Rte_Read_R_ElProdMgt_uBattSp_ElProdMgt_uBattSp(&ProdElEm_004_ElProdMgt_uBattSp_in);
      (void)Rte_Read_R_Ext_bNotAvl_rBattSoCLoResl_Ext_bNotAvl_rBattSoCLoResl(&ProdElEm_004_Ext_bNotAvl_rBattSoCLoResl_in);
      (void)Rte_Read_R_Ext_bNotAvl_uBattStrt_Ext_bNotAvl_uBattStrt(&ProdElEm_004_Ext_bNotAvl_uBattStrt_in);
      (void)Rte_Read_R_Ext_ctYr_Ext_ctYr(&ProdElEm_004_Ext_ctYr_in);
      (void)Rte_Read_R_RvAltMgt_uRvAltMes_RvAltMgt_uRvAltMes(&ProdElEm_004_RvAltMgt_uRvAltMes_in);
      (void)Rte_Read_R_CoOptmEl_stPrevElProdReq_CoOptmEl_stPrevElProdReq(&ProdElEm_004_CoOptmEl_stPrevElProdReq_in);
      (void)Rte_Read_R_CoOptmEl_stOptmElStra_CoOptmEl_stOptmElStra(&ProdElEm_004_CoOptmEl_stOptmElStra_in);
      (void)Rte_Read_R_Ext_iBattMaxCkg_Ext_iBattMaxCkg(&ProdElEm_004_Ext_iBattMaxCkg_in);
      (void)Rte_Read_R_Ext_resBattItNorm_Ext_resBattItNorm(&ProdElEm_004_Ext_resBattItNorm_in);
      (void)Rte_Read_R_Ext_uBattMinCkg_Ext_uBattMinCkg(&ProdElEm_004_Ext_uBattMinCkg_in);
      (void)Rte_Read_R_CoOptmEl_iElProdMaxLdBatt_CoOptmEl_iElProdMaxLdBatt(&ProdElEm_004_CoOptmEl_iElProdMaxLdBatt_in);

      Rte_Call_R_FRM_bAcvBatMgtDftValStBatt_GetFunctionPermission(& ProdElEm_004_FRM_bAcvBatMgtDftValStBatt_in);
      ProdElEm_004_FRM_bAcvBatMgtDftValStBatt_in = !ProdElEm_004_FRM_bAcvBatMgtDftValStBatt_in;
      Rte_Call_R_FRM_bInhBatMgtSoCClc_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtSoCClc_in);
      ProdElEm_004_FRM_bInhBatMgtSoCClc_in = !ProdElEm_004_FRM_bInhBatMgtSoCClc_in;
      Rte_Call_R_FRM_bInhBatMgtTestCohVolt_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtTestCohVolt_in);
      ProdElEm_004_FRM_bInhBatMgtTestCohVolt_in = !ProdElEm_004_FRM_bInhBatMgtTestCohVolt_in;
      Rte_Call_R_FRM_bInhBatMgt_uBattRstrt_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgt_uBattRstrt_in);
      ProdElEm_004_FRM_bInhBatMgt_uBattRstrt_in = !ProdElEm_004_FRM_bInhBatMgt_uBattRstrt_in;
      Rte_Call_R_FRM_bInhBatMgtBattNotConn_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtBattNotConn_in);
      ProdElEm_004_FRM_bInhBatMgtBattNotConn_in = !ProdElEm_004_FRM_bInhBatMgtBattNotConn_in;
      Rte_Call_R_FRM_bInhBatMgtCurBattMes_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtCurBattMes_in);
      ProdElEm_004_FRM_bInhBatMgtCurBattMes_in = !ProdElEm_004_FRM_bInhBatMgtCurBattMes_in;
      Rte_Call_R_FRM_bInhBatMgtKmAntiAgi_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtKmAntiAgi_in);
      ProdElEm_004_FRM_bInhBatMgtKmAntiAgi_in = !ProdElEm_004_FRM_bInhBatMgtKmAntiAgi_in;
      Rte_Call_R_FRM_bInhBatMgtPerAntiAgi_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtPerAntiAgi_in);
      ProdElEm_004_FRM_bInhBatMgtPerAntiAgi_in = !ProdElEm_004_FRM_bInhBatMgtPerAntiAgi_in;
      Rte_Call_R_FRM_bInhBatMgtSoH_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtSoH_in);
      ProdElEm_004_FRM_bInhBatMgtSoH_in = !ProdElEm_004_FRM_bInhBatMgtSoH_in;
      Rte_Call_R_FRM_bInhBatMgtStSoCAfts_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtStSoCAfts_in);
      ProdElEm_004_FRM_bInhBatMgtStSoCAfts_in = !ProdElEm_004_FRM_bInhBatMgtStSoCAfts_in;
      Rte_Call_R_FRM_bInhBatMgtTBattMes_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtTBattMes_in);
      ProdElEm_004_FRM_bInhBatMgtTBattMes_in = !ProdElEm_004_FRM_bInhBatMgtTBattMes_in;
      Rte_Call_R_FRM_bInhBatMgtTiAntiAgi_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtTiAntiAgi_in);
      ProdElEm_004_FRM_bInhBatMgtTiAntiAgi_in = !ProdElEm_004_FRM_bInhBatMgtTiAntiAgi_in;
      Rte_Call_R_FRM_bInhBatMgtVoltBattClc_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtVoltBattClc_in);
      ProdElEm_004_FRM_bInhBatMgtVoltBattClc_in = !ProdElEm_004_FRM_bInhBatMgtVoltBattClc_in;
      Rte_Call_R_FRM_bInhBatMgtDiagSoC_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtDiagSoC_in);
      ProdElEm_004_FRM_bInhBatMgtDiagSoC_in = !ProdElEm_004_FRM_bInhBatMgtDiagSoC_in;
      Rte_Call_R_FRM_bInhBatMgtOfsSoC_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtOfsSoC_in);
      ProdElEm_004_FRM_bInhBatMgtOfsSoC_in = !ProdElEm_004_FRM_bInhBatMgtOfsSoC_in;
      Rte_Call_R_FRM_bInhBatMgtStcBattSoC_GetFunctionPermission(& ProdElEm_004_FRM_bInhBatMgtStcBattSoC_in);
      ProdElEm_004_FRM_bInhBatMgtStcBattSoC_in = !ProdElEm_004_FRM_bInhBatMgtStcBattSoC_in;
      ProdElEm_004_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      BatMgt_iBattMes_out = BatMgt_iBattMes_B;
      BatMgt_rBattSoCCor_out = BatMgt_rBattSoCCor_B;
      BatMgt_resBattIt_out = BatMgt_resBattIt_B;
      BatMgt_rSoCErrEstim_out = BatMgt_rSoCErrEstim_B;
      BatMgt_stBattSoC_out = BatMgt_stBattSoC_B;
      BatMgt_stBattSt_out = BatMgt_stBattSt_B;
      BatMgt_tBattMes_out = BatMgt_tBattMes_B;
      BatMgt_uBattMes_out = BatMgt_uBattMes_B;
      BatMgt_uBattOc_out = BatMgt_uBattOc_B;
      BatMgt_uBattRstrt_out = BatMgt_uBattRstrt_B;
      BatMgt_bBattAntiAgiAcvReq_out = BatMgt_bBattAntiAgiAcvReq_B;
      BatMgt_bBattChProtAcvReq_out = BatMgt_bBattChProtAcvReq_B;
      BatMgt_bBattSoCMinProtAcvReq_out = BatMgt_bBattSoCMinProtAcvReq_B;
      BatMgt_bBattStopPrepAcvReq_out = BatMgt_bBattStopPrepAcvReq_B;
      BatMgt_bBattTProtAcvReq_out = BatMgt_bBattTProtAcvReq_B;
      BatMgt_ctStcAcvAntiAgiStra_out = BatMgt_ctStcAcvAntiAgiStra_B;
      BatMgt_ctStcCnclAntiAgiStra_out = BatMgt_ctStcCnclAntiAgiStra_B;
      BatMgt_grdNegSlopBattAntiAgi_out = BatMgt_grdNegSlopBattAntiAgi_B;
      BatMgt_grdNegSlopBattTProt_out = BatMgt_grdNegSlopBattTProt_B;
      BatMgt_grdPosSlopBattAntiAgi_out = BatMgt_grdPosSlopBattAntiAgi_B;
      BatMgt_grdPosSlopBattTProt_out = BatMgt_grdPosSlopBattTProt_B;
      BatMgt_rOfsSoC_out = BatMgt_rOfsSoC_B;
      BatMgt_rStcSoCMax_out = BatMgt_rStcSoCMax_B;
      BatMgt_rStcSoCMin_out = BatMgt_rStcSoCMin_B;
      BatMgt_stBattSoH_out = BatMgt_stBattSoH_B;
      BatMgt_tiStcVoltBattDmg_out = BatMgt_tiStcVoltBattDmg_B;
      BatMgt_uBattStrt_out = BatMgt_uBattStrt_B;
      BatMgt_uReqEmMaxBattAntiAgi_out = BatMgt_uReqEmMaxBattAntiAgi_B;
      BatMgt_uReqEmMaxBattTProt_out = BatMgt_uReqEmMaxBattTProt_B;
      BatMgt_uReqEmMinBattAntiAgi_out = BatMgt_uReqEmMinBattAntiAgi_B;
      BatMgt_uReqEmMinBattTProt_out = BatMgt_uReqEmMinBattTProt_B;
      BatMgt_uReqEmMinBattChProt_out = BatMgt_uReqEmMinBattChProt_B;
      BatMgt_uReqEmMaxBattChProt_out = BatMgt_uReqEmMaxBattChProt_B;
      BatMgt_grdPosSlopBattChProt_out = BatMgt_grdPosSlopBattChProt_B;
      BatMgt_grdNegSlopBattChProt_out = BatMgt_grdNegSlopBattChProt_B;
      BatMgt_bAntiAgiStraEfcChIdc_out = BatMgt_bAntiAgiStraEfcChIdc_B;
      BatMgt_bAntiAgiStraEndIdc_out = BatMgt_bAntiAgiStraEndIdc_B;
      BatMgt_iBattMaxCkg_out = BatMgt_iBattMaxCkg_B;
      BatMgt_resBattItNorm_out = BatMgt_resBattItNorm_B;
      BatMgt_uBattMinCkg_out = BatMgt_uBattMinCkg_B;
  }
  (void)Rte_Write_P_BatMgt_iBattMes_BatMgt_iBattMes(BatMgt_iBattMes_out);
  (void)Rte_Write_P_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(BatMgt_rBattSoCCor_out);
  (void)Rte_Write_P_BatMgt_resBattIt_BatMgt_resBattIt(BatMgt_resBattIt_out);
  (void)Rte_Write_P_BatMgt_rSoCErrEstim_BatMgt_rSoCErrEstim(BatMgt_rSoCErrEstim_out);
  (void)Rte_Write_P_BatMgt_stBattSoC_BatMgt_stBattSoC(BatMgt_stBattSoC_out);
  (void)Rte_Write_P_BatMgt_stBattSt_BatMgt_stBattSt(BatMgt_stBattSt_out);
  (void)Rte_Write_P_BatMgt_tBattMes_BatMgt_tBattMes(BatMgt_tBattMes_out);
  (void)Rte_Write_P_BatMgt_uBattMes_BatMgt_uBattMes(BatMgt_uBattMes_out);
  (void)Rte_Write_P_BatMgt_uBattOc_BatMgt_uBattOc(BatMgt_uBattOc_out);
  (void)Rte_Write_P_BatMgt_uBattRstrt_BatMgt_uBattRstrt(BatMgt_uBattRstrt_out);
  (void)Rte_Write_P_BatMgt_bBattAntiAgiAcvReq_BatMgt_bBattAntiAgiAcvReq(BatMgt_bBattAntiAgiAcvReq_out);
  (void)Rte_Write_P_BatMgt_bBattChProtAcvReq_BatMgt_bBattChProtAcvReq(BatMgt_bBattChProtAcvReq_out);
  (void)Rte_Write_P_BatMgt_bBattSoCMinProtAcvReq_BatMgt_bBattSoCMinProtAcvReq(BatMgt_bBattSoCMinProtAcvReq_out);
  (void)Rte_Write_P_BatMgt_bBattStopPrepAcvReq_BatMgt_bBattStopPrepAcvReq(BatMgt_bBattStopPrepAcvReq_out);
  (void)Rte_Write_P_BatMgt_bBattTProtAcvReq_BatMgt_bBattTProtAcvReq(BatMgt_bBattTProtAcvReq_out);
  (void)Rte_Write_P_BatMgt_ctStcAcvAntiAgiStra_BatMgt_ctStcAcvAntiAgiStra(BatMgt_ctStcAcvAntiAgiStra_out);
  (void)Rte_Write_P_BatMgt_ctStcCnclAntiAgiStra_BatMgt_ctStcCnclAntiAgiStra(BatMgt_ctStcCnclAntiAgiStra_out);
  (void)Rte_Write_P_BatMgt_grdNegSlopBattAntiAgi_BatMgt_grdNegSlopBattAntiAgi(BatMgt_grdNegSlopBattAntiAgi_out);
  (void)Rte_Write_P_BatMgt_grdNegSlopBattTProt_BatMgt_grdNegSlopBattTProt(BatMgt_grdNegSlopBattTProt_out);
  (void)Rte_Write_P_BatMgt_grdPosSlopBattAntiAgi_BatMgt_grdPosSlopBattAntiAgi(BatMgt_grdPosSlopBattAntiAgi_out);
  (void)Rte_Write_P_BatMgt_grdPosSlopBattTProt_BatMgt_grdPosSlopBattTProt(BatMgt_grdPosSlopBattTProt_out);
  (void)Rte_Write_P_BatMgt_rOfsSoC_BatMgt_rOfsSoC(BatMgt_rOfsSoC_out);
  (void)Rte_Write_P_BatMgt_rStcSoCMax_BatMgt_rStcSoCMax(BatMgt_rStcSoCMax_out);
  (void)Rte_Write_P_BatMgt_rStcSoCMin_BatMgt_rStcSoCMin(BatMgt_rStcSoCMin_out);
  (void)Rte_Write_P_BatMgt_stBattSoH_BatMgt_stBattSoH(BatMgt_stBattSoH_out);
  (void)Rte_Write_P_BatMgt_tiStcVoltBattDmg_BatMgt_tiStcVoltBattDmg(BatMgt_tiStcVoltBattDmg_out);
  (void)Rte_Write_P_BatMgt_uBattStrt_BatMgt_uBattStrt(BatMgt_uBattStrt_out);
  (void)Rte_Write_P_BatMgt_uReqEmMaxBattAntiAgi_BatMgt_uReqEmMaxBattAntiAgi(BatMgt_uReqEmMaxBattAntiAgi_out);
  (void)Rte_Write_P_BatMgt_uReqEmMaxBattTProt_BatMgt_uReqEmMaxBattTProt(BatMgt_uReqEmMaxBattTProt_out);
  (void)Rte_Write_P_BatMgt_uReqEmMinBattAntiAgi_BatMgt_uReqEmMinBattAntiAgi(BatMgt_uReqEmMinBattAntiAgi_out);
  (void)Rte_Write_P_BatMgt_uReqEmMinBattTProt_BatMgt_uReqEmMinBattTProt(BatMgt_uReqEmMinBattTProt_out);
  (void)Rte_Write_P_BatMgt_uReqEmMinBattChProt_BatMgt_uReqEmMinBattChProt(BatMgt_uReqEmMinBattChProt_out);
  (void)Rte_Write_P_BatMgt_uReqEmMaxBattChProt_BatMgt_uReqEmMaxBattChProt(BatMgt_uReqEmMaxBattChProt_out);
  (void)Rte_Write_P_BatMgt_grdPosSlopBattChProt_BatMgt_grdPosSlopBattChProt(BatMgt_grdPosSlopBattChProt_out);
  (void)Rte_Write_P_BatMgt_grdNegSlopBattChProt_BatMgt_grdNegSlopBattChProt(BatMgt_grdNegSlopBattChProt_out);
  (void)Rte_Write_P_BatMgt_bAntiAgiStraEfcChIdc_BatMgt_bAntiAgiStraEfcChIdc(BatMgt_bAntiAgiStraEfcChIdc_out);
  (void)Rte_Write_P_BatMgt_bAntiAgiStraEndIdc_BatMgt_bAntiAgiStraEndIdc(BatMgt_bAntiAgiStraEndIdc_out);
  (void)Rte_Write_P_BatMgt_iBattMaxCkg_BatMgt_iBattMaxCkg(BatMgt_iBattMaxCkg_out);
  (void)Rte_Write_P_BatMgt_resBattItNorm_BatMgt_resBattItNorm(BatMgt_resBattItNorm_out);
  (void)Rte_Write_P_BatMgt_uBattMinCkg_BatMgt_uBattMinCkg(BatMgt_uBattMinCkg_out);

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__iBattMes */
     if(BatMgt_bMonRun_iBattMes_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_iBattMes_out==1)
         {
             Rte_Call_R_BatMgt__iBattMes_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__iBattMes_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_iBattMes_out_prec==1)
         {
             Rte_Call_R_BatMgt__iBattMes_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_iBattMes_out_prec = BatMgt_bMonRun_iBattMes_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__resBattIt */
     if(BatMgt_bMonRun_resBattIt_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_resBattIt_out==1)
         {
             Rte_Call_R_BatMgt__resBattIt_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__resBattIt_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_resBattIt_out_prec==1)
         {
             Rte_Call_R_BatMgt__resBattIt_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_resBattIt_out_prec = BatMgt_bMonRun_resBattIt_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__tBattMes */
     if(BatMgt_bMonRun_tBattMes_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_tBattMes_out==1)
         {
             Rte_Call_R_BatMgt__tBattMes_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__tBattMes_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_tBattMes_out_prec==1)
         {
             Rte_Call_R_BatMgt__tBattMes_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_tBattMes_out_prec = BatMgt_bMonRun_tBattMes_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__uBattMes */
     if(BatMgt_bMonRun_uBattMes_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_uBattMes_out==1)
         {
             Rte_Call_R_BatMgt__uBattMes_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__uBattMes_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_uBattMes_out_prec==1)
         {
             Rte_Call_R_BatMgt__uBattMes_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_uBattMes_out_prec = BatMgt_bMonRun_uBattMes_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__uBattRstrt */
     if(BatMgt_bMonRun_uBattRstrt_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_uBattRstrt_out==1)
         {
             Rte_Call_R_BatMgt__uBattRstrt_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__uBattRstrt_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_uBattRstrt_out_prec==1)
         {
             Rte_Call_R_BatMgt__uBattRstrt_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_uBattRstrt_out_prec = BatMgt_bMonRun_uBattRstrt_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__uBattOc */
     if(BatMgt_bMonRun_uBattOc_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_uBattOc_out==1)
         {
             Rte_Call_R_BatMgt__uBattOc_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__uBattOc_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_uBattOc_out_prec==1)
         {
             Rte_Call_R_BatMgt__uBattOc_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_uBattOc_out_prec = BatMgt_bMonRun_uBattOc_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__uBattStrt */
     if(BatMgt_bMonRun_uBattStrt_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_uBattStrt_out==1)
         {
             Rte_Call_R_BatMgt__uBattStrt_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__uBattStrt_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_uBattStrt_out_prec==1)
         {
             Rte_Call_R_BatMgt__uBattStrt_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_uBattStrt_out_prec = BatMgt_bMonRun_uBattStrt_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__iBattMaxCkg */
     if(BatMgt_bMonRun_iBattMaxCkg_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_iBattMaxCkg_out==1)
         {
             Rte_Call_R_BatMgt__iBattMaxCkg_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__iBattMaxCkg_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_iBattMaxCkg_out_prec==1)
         {
             Rte_Call_R_BatMgt__iBattMaxCkg_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_iBattMaxCkg_out_prec = BatMgt_bMonRun_iBattMaxCkg_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__rBattSoC */
     if(BatMgt_bMonRun_rBattSoC_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_rBattSoC_out==1)
         {
             Rte_Call_R_BatMgt__rBattSoC_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__rBattSoC_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_rBattSoC_out_prec==1)
         {
             Rte_Call_R_BatMgt__rBattSoC_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_rBattSoC_out_prec = BatMgt_bMonRun_rBattSoC_out;
  }

  if (FALSE == RE_PRODELEM_004_TEV_B)
  {

  /* Diag treatment : ProdElEm__uBattMinCkg */
     if(BatMgt_bMonRun_uBattMinCkg_out==1)
     {
         /* Diag activation */
         if(BatMgt_bDgo_uBattMinCkg_out==1)
         {
             Rte_Call_R_BatMgt__uBattMinCkg_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_BatMgt__uBattMinCkg_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (BatMgt_bMonRun_uBattMinCkg_out_prec==1)
         {
             Rte_Call_R_BatMgt__uBattMinCkg_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     BatMgt_bMonRun_uBattMinCkg_out_prec = BatMgt_bMonRun_uBattMinCkg_out;
  }

}

void RE_ProdElEm_005_MSE(void)
{


      ProdElEm_005_MSE_ini();

      (void)Rte_Write_P_ElProdMgt_iExctMax_ElProdMgt_iExctMax(0);
      (void)Rte_Write_P_ElProdMgt_rSoCErrEstim_ElProdMgt_rSoCErrEstim(0);
      (void)Rte_Write_P_ElProdMgt_stProdPrgCh_ElProdMgt_stProdPrgCh(7);
      (void)Rte_Write_P_ElProdMgt_stProdPrgChDi_nEng_ElProdMgt_stProdPrgChDi_nEng(4);
      (void)Rte_Write_P_ElProdMgt_tqAltEstim_ElProdMgt_tqAltEstim(0);
      (void)Rte_Write_P_ElProdMgt_uElProdSp_ElProdMgt_uElProdSp(1357);
      (void)Rte_Write_P_ElProdMgt_uOfs_uElProdSp_ElProdMgt_uOfs_uElProdSp(0);
      (void)Rte_Write_P_ElProdMgt_bAcvCoefFilDftAlt_ElProdMgt_bAcvCoefFilDftAlt(0);
      (void)Rte_Write_P_ElProdMgt_iAltEstim_ElProdMgt_iAltEstim(0);
      (void)Rte_Write_P_ElProdMgt_uBattSp_ElProdMgt_uBattSp(1357);
      (void)Rte_Write_P_ElProdMgt_uOfsLossCor_ElProdMgt_uOfsLossCor(0);

}

void RE_ProdElEm_006_TEV(void)
{

  if (FALSE == RE_PRODELEM_006_TEV_B)
  {
      /* Module code execution */
      /* Module behaviour unchanged */

      (void)Rte_Read_R_BatMgt_iBattMes_BatMgt_iBattMes(&ProdElEm_006_BatMgt_iBattMes_in);
      (void)Rte_Read_R_BatMgt_rBattSoCCor_BatMgt_rBattSoCCor(&ProdElEm_006_BatMgt_rBattSoCCor_in);
      (void)Rte_Read_R_BatMgt_tBattMes_BatMgt_tBattMes(&ProdElEm_006_BatMgt_tBattMes_in);
      (void)Rte_Read_R_BatMgt_uBattMes_BatMgt_uBattMes(&ProdElEm_006_BatMgt_uBattMes_in);
      (void)Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&ProdElEm_006_Ext_stElProdCf_in);
      (void)Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ProdElEm_006_Ext_tCoMes_in);
      (void)Rte_Read_R_CoOptmEl_grdNegSlop_CoOptmEl_grdNegSlop(&ProdElEm_006_CoOptmEl_grdNegSlop_in);
      (void)Rte_Read_R_CoOptmEl_grdPosSlop_CoOptmEl_grdPosSlop(&ProdElEm_006_CoOptmEl_grdPosSlop_in);
      (void)Rte_Read_R_CoOptmEl_rBattSoCSp_CoOptmEl_rBattSoCSp(&ProdElEm_006_CoOptmEl_rBattSoCSp_in);
      (void)Rte_Read_R_CoOptmEl_uMax_CoOptmEl_uMax(&ProdElEm_006_CoOptmEl_uMax_in);
      (void)Rte_Read_R_TqLimUH_grdLimVoltCtlDynMax_TqLimUH_grdLimVoltCtlDynMax(&ProdElEm_006_TqLimUH_grdLimVoltCtlDynMax_in);
      (void)Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&ProdElEm_006_Eng_nCkFil_in);
      (void)Rte_Read_R_Ext_stAltClasCf_Ext_stAltClasCf(&ProdElEm_006_Ext_stAltClasCf_in);
      (void)Rte_Read_R_CoOptmEl_stOptmElCf_CoOptmEl_stOptmElCf(&ProdElEm_006_CoOptmEl_stOptmElCf_in);
      (void)Rte_Read_R_CoOptmEl_stStraVoltBatt_CoOptmEl_stStraVoltBatt(&ProdElEm_006_CoOptmEl_stStraVoltBatt_in);
      (void)Rte_Read_R_RvAltMgt_uRvAltMes_RvAltMgt_uRvAltMes(&ProdElEm_006_RvAltMgt_uRvAltMes_in);
      (void)Rte_Read_R_CoOptmEl_stPrevElProdReq_CoOptmEl_stPrevElProdReq(&ProdElEm_006_CoOptmEl_stPrevElProdReq_in);
      (void)Rte_Read_R_CoOptmEl_uMinInc_CoOptmEl_uMinInc(&ProdElEm_006_CoOptmEl_uMinInc_in);
      (void)Rte_Read_R_Ext_facRatTqAltCf_Ext_facRatTqAltCf(&ProdElEm_006_Ext_facRatTqAltCf_in);
      (void)Rte_Read_R_Ext_iAltExct_Ext_iAltExct(&ProdElEm_006_Ext_iAltExct_in);
      (void)Rte_Read_R_RvAltMgt_nRvAltMes_RvAltMgt_nRvAltMes(&ProdElEm_006_RvAltMgt_nRvAltMes_in);
      (void)Rte_Read_R_Ext_rAltCycOp_Ext_rAltCycOp(&ProdElEm_006_Ext_rAltCycOp_in);
      (void)Rte_Read_R_CoOptmEl_stOptmElStra_CoOptmEl_stOptmElStra(&ProdElEm_006_CoOptmEl_stOptmElStra_in);
      (void)Rte_Read_R_CoOptmEl_iElNw_CoOptmEl_iElNw(&ProdElEm_006_CoOptmEl_iElNw_in);
      (void)Rte_Read_R_Ext_idxCtlAltProvIdf_Ext_idxCtlAltProvIdf(&ProdElEm_006_Ext_idxCtlAltProvIdf_in);
      (void)Rte_Read_R_RvAltMgt_bIdcVldCurGenMod_RvAltMgt_bIdcVldCurGenMod(&ProdElEm_006_RvAltMgt_bIdcVldCurGenMod_in);
      (void)Rte_Read_R_Ext_tAir_Ext_tAir(&ProdElEm_006_Ext_tAir_in);
      (void)Rte_Read_R_CoOptmEl_stPrgChReq_CoOptmEl_stPrgChReq(&ProdElEm_006_CoOptmEl_stPrgChReq_in);

      Rte_Call_R_FRM_bInhElProdMgtCorVoltSp_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtCorVoltSp_in);
      ProdElEm_006_FRM_bInhElProdMgtCorVoltSp_in = !ProdElEm_006_FRM_bInhElProdMgtCorVoltSp_in;
      Rte_Call_R_FRM_bAcvElProdMgtStraDftCom_GetFunctionPermission(& ProdElEm_006_FRM_bAcvElProdMgtStraDftCom_in);
      ProdElEm_006_FRM_bAcvElProdMgtStraDftCom_in = !ProdElEm_006_FRM_bAcvElProdMgtStraDftCom_in;
      Rte_Call_R_FRM_bAcvElProdMgtStraDftEl_GetFunctionPermission(& ProdElEm_006_FRM_bAcvElProdMgtStraDftEl_in);
      ProdElEm_006_FRM_bAcvElProdMgtStraDftEl_in = !ProdElEm_006_FRM_bAcvElProdMgtStraDftEl_in;
      Rte_Call_R_FRM_bAcvElProdMgtStraDftMec_GetFunctionPermission(& ProdElEm_006_FRM_bAcvElProdMgtStraDftMec_in);
      ProdElEm_006_FRM_bAcvElProdMgtStraDftMec_in = !ProdElEm_006_FRM_bAcvElProdMgtStraDftMec_in;
      Rte_Call_R_FRM_bInhElProdMgtAltOfsSpMes_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtAltOfsSpMes_in);
      ProdElEm_006_FRM_bInhElProdMgtAltOfsSpMes_in = !ProdElEm_006_FRM_bInhElProdMgtAltOfsSpMes_in;
      Rte_Call_R_FRM_bInhElProdMgtAltProvIdf_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtAltProvIdf_in);
      ProdElEm_006_FRM_bInhElProdMgtAltProvIdf_in = !ProdElEm_006_FRM_bInhElProdMgtAltProvIdf_in;
      Rte_Call_R_FRM_bInhElProdMgtAltVoltSp_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtAltVoltSp_in);
      ProdElEm_006_FRM_bInhElProdMgtAltVoltSp_in = !ProdElEm_006_FRM_bInhElProdMgtAltVoltSp_in;
      Rte_Call_R_FRM_bInhElProdMgtCorOfsLoss_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtCorOfsLoss_in);
      ProdElEm_006_FRM_bInhElProdMgtCorOfsLoss_in = !ProdElEm_006_FRM_bInhElProdMgtCorOfsLoss_in;
      Rte_Call_R_FRM_bInhElProdMgtDiagCorLoss_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtDiagCorLoss_in);
      ProdElEm_006_FRM_bInhElProdMgtDiagCorLoss_in = !ProdElEm_006_FRM_bInhElProdMgtDiagCorLoss_in;
      Rte_Call_R_FRM_bInhElProdMgtTqAltLoss_GetFunctionPermission(& ProdElEm_006_FRM_bInhElProdMgtTqAltLoss_in);
      ProdElEm_006_FRM_bInhElProdMgtTqAltLoss_in = !ProdElEm_006_FRM_bInhElProdMgtTqAltLoss_in;
      ProdElEm_006_TEV_fct();

  }
  else
  {
      /* Integration tests instrumentation activated */
      /* Force Output with Bypasses calibration values */

      ElProdMgt_iExctMax_out = ElProdMgt_iExctMax_B;
      ElProdMgt_rSoCErrEstim_out = ElProdMgt_rSoCErrEstim_B;
      ElProdMgt_stProdPrgCh_out = ElProdMgt_stProdPrgCh_B;
      ElProdMgt_stProdPrgChDi_nEng_out = ElProdMgt_stProdPrgChDi_nEng_B;
      ElProdMgt_tqAltEstim_out = ElProdMgt_tqAltEstim_B;
      ElProdMgt_uElProdSp_out = ElProdMgt_uElProdSp_B;
      ElProdMgt_uOfs_uElProdSp_out = ElProdMgt_uOfs_uElProdSp_B;
      ElProdMgt_bAcvCoefFilDftAlt_out = ElProdMgt_bAcvCoefFilDftAlt_B;
      ElProdMgt_iAltEstim_out = ElProdMgt_iAltEstim_B;
      ElProdMgt_uBattSp_out = ElProdMgt_uBattSp_B;
      ElProdMgt_uOfsLossCor_out = ElProdMgt_uOfsLossCor_B;
  }
  (void)Rte_Write_P_ElProdMgt_iExctMax_ElProdMgt_iExctMax(ElProdMgt_iExctMax_out);
  (void)Rte_Write_P_ElProdMgt_rSoCErrEstim_ElProdMgt_rSoCErrEstim(ElProdMgt_rSoCErrEstim_out);
  (void)Rte_Write_P_ElProdMgt_stProdPrgCh_ElProdMgt_stProdPrgCh(ElProdMgt_stProdPrgCh_out);
  (void)Rte_Write_P_ElProdMgt_stProdPrgChDi_nEng_ElProdMgt_stProdPrgChDi_nEng(ElProdMgt_stProdPrgChDi_nEng_out);
  (void)Rte_Write_P_ElProdMgt_tqAltEstim_ElProdMgt_tqAltEstim(ElProdMgt_tqAltEstim_out);
  (void)Rte_Write_P_ElProdMgt_uElProdSp_ElProdMgt_uElProdSp(ElProdMgt_uElProdSp_out);
  (void)Rte_Write_P_ElProdMgt_uOfs_uElProdSp_ElProdMgt_uOfs_uElProdSp(ElProdMgt_uOfs_uElProdSp_out);
  (void)Rte_Write_P_ElProdMgt_bAcvCoefFilDftAlt_ElProdMgt_bAcvCoefFilDftAlt(ElProdMgt_bAcvCoefFilDftAlt_out);
  (void)Rte_Write_P_ElProdMgt_iAltEstim_ElProdMgt_iAltEstim(ElProdMgt_iAltEstim_out);
  (void)Rte_Write_P_ElProdMgt_uBattSp_ElProdMgt_uBattSp(ElProdMgt_uBattSp_out);
  (void)Rte_Write_P_ElProdMgt_uOfsLossCor_ElProdMgt_uOfsLossCor(ElProdMgt_uOfsLossCor_out);

  if (FALSE == RE_PRODELEM_006_TEV_B)
  {

  /* Diag treatment : ProdElEm_CorLoss */
     if(ElProdMgt_bMonRunCorLoss_out==1)
     {
         /* Diag activation */
         if(ElProdMgt_bDgoCorLoss_out==1)
         {
             Rte_Call_R_ElProdMgt_CorLoss_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_ElProdMgt_CorLoss_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (ElProdMgt_bMonRunCorLoss_out_prec==1)
         {
             Rte_Call_R_ElProdMgt_CorLoss_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     ElProdMgt_bMonRunCorLoss_out_prec = ElProdMgt_bMonRunCorLoss_out;
  }

  if (FALSE == RE_PRODELEM_006_TEV_B)
  {

  /* Diag treatment : ProdElEm_CorSpCur */
     if(ElProdMgt_bMonRunCorSpCur_out==1)
     {
         /* Diag activation */
         if(ElProdMgt_bDgoCorSpCur_out==1)
         {
             Rte_Call_R_ElProdMgt_CorSpCur_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
         }
         else
         {
             Rte_Call_R_ElProdMgt_CorSpCur_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
         }
     }
     else
     {
         if (ElProdMgt_bMonRunCorSpCur_out_prec==1)
         {
             Rte_Call_R_ElProdMgt_CorSpCur_SetEventStatus(DEM_EVENT_STATUS_INIT);
         }
     }
     ElProdMgt_bMonRunCorSpCur_out_prec = ElProdMgt_bMonRunCorSpCur_out;
  }

}

#define PRODELEM_STOP_SEC_CODE
#include "ProdElEm_MemMap.h"

#endif/*_PRODELEM_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

