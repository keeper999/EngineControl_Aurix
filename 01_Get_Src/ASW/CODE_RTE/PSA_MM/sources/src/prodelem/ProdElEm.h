/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ProdElEm.h
* Description   : Interface AUTOSAR du module ProdElEm avec Bypasses 
* Auteur        : CLCO/CLO
* Creation      : 30-May-2011(17:16:58)
*******************************************************************************/

#ifndef _PRODELEM_H_
#define _PRODELEM_H_
#include "tl_defines.h"

/*----------------------------------------------------------------------------
VERSION MODULE
*----------------------------------------------------------------------------*/
#define PRODELEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEm_MemMap.h"
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PRODELEM_ModuleVersion_Major_MP;
extern AR_SEC_CONST_VERSION_MODULE_8BIT UInt8 PRODELEM_ModuleVersion_Minor_MP;
#define PRODELEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "ProdElEm_MemMap.h"

/*----------------------------------------------------------------------------*
  OUTPUTS BYPASSES
*----------------------------------------------------------------------------*/
#define PRODELEM_START_SEC_CALIB_BOOLEAN
#include "ProdElEm_MemMap.h"
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_002_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_004_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean RE_PRODELEM_006_TEV_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bAuthAntiAgiStra_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bWupAcv_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattAntiAgiAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattChProtAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattSoCMinProtAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattStopPrepAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bBattTProtAcvReq_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean ElProdMgt_bAcvCoefFilDftAlt_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bAntiAgiStraEfcChIdc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean BatMgt_bAntiAgiStraEndIdc_B;
extern AR_MERGEABLE_CALIB_BOOLEAN Boolean CoOptmEl_bAcvElCnsReq_B;
#define PRODELEM_STOP_SEC_CALIB_BOOLEAN
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_8BIT
#include "ProdElEm_MemMap.h"
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_grdNegSlop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_grdPosSlop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_rElRecup_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_rElRest_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElLvlProd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElProd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSoC_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_stProdPrgCh_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_stProdPrgChDi_nEng_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_bfAcvConstEm1_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_bfAcvConstEm2_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElProd_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstNegSlop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstPosSlop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstVoltMax_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stDetConstVoltMin_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stElEProv_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stOptmElCf_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stOptmElStra_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stPrevElProdReq_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stSoCRefTyp_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stStraVoltBatt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_tiLdSoCAuthStop_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_ctStcAcvAntiAgiStra_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_ctStcCnclAntiAgiStra_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattAntiAgi_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattTProt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattAntiAgi_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattTProt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_stBattSoH_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 ElProdMgt_iAltEstim_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdPosSlopBattChProt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_grdNegSlopBattChProt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElNw_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 BatMgt_resBattItNorm_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_iElProdMaxLdBatt_B;
extern AR_MERGEABLE_CALIB_8BIT UInt8 CoOptmEl_stPrgChReq_B;
extern AR_MERGEABLE_CALIB_8BIT SInt8 BatMgt_iBattMaxCkg_B;
#define PRODELEM_STOP_SEC_CALIB_8BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_16BIT
#include "ProdElEm_MemMap.h"
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rBattSoCSp_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMax_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMin_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rBattSoCCor_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_resBattIt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattMes_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattOc_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattRstrt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_iExctMax_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_tqAltEstim_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_uElProdSp_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rThdRstrtAuthSoCCf1_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_rThdStopAuthSoCCf2_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 CoOptmEl_uMinInc_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rOfsSoC_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rStcSoCMax_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_rStcSoCMin_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_tiStcVoltBattDmg_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattStrt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattAntiAgi_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattTProt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattAntiAgi_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattTProt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 ElProdMgt_uBattSp_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMinBattChProt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uReqEmMaxBattChProt_B;
extern AR_MERGEABLE_CALIB_16BIT UInt16 BatMgt_uBattMinCkg_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoOptmEl_tqAlt_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 BatMgt_rSoCErrEstim_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 BatMgt_tBattMes_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_rSoCErrEstim_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_uOfs_uElProdSp_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 CoOptmEl_rOfsSoCSTT_B;
extern AR_MERGEABLE_CALIB_16BIT SInt16 ElProdMgt_uOfsLossCor_B;
#define PRODELEM_STOP_SEC_CALIB_16BIT
#include "ProdElEm_MemMap.h"

#define PRODELEM_START_SEC_CALIB_32BIT
#include "ProdElEm_MemMap.h"
extern AR_MERGEABLE_CALIB_32BIT SInt32 BatMgt_iBattMes_B;
#define PRODELEM_STOP_SEC_CALIB_32BIT
#include "ProdElEm_MemMap.h"

#endif/*_PRODELEM_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/

