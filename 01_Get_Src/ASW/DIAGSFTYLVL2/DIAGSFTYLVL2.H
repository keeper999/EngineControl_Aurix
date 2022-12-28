/***************************************************************************
;**
;** FILE NAME      : DIAGSFTYLVL2.H
;**
;** FILE AUTHOR    : MBENFRADJ (VEES)
;**
;**************************************************************************/

#ifndef DIAGSFTYLVL2_H
#define DIAGSFTYLVL2_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  Ext_bAcv_F329SftyLvl2_C;
extern const boolean  Ext_bAcv_F349SftyLvl2_C;
extern const boolean  Ext_bAcv_F34DSftyLvl2_C;
extern const boolean  Ext_bAcv_F38DSftyLvl2_C;
extern const boolean  Ext_bAcv_NeutPosSftyLvl2_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_ctDftMaxProcCntF329_C;
extern const uint8  SftyMgt_ctDftMaxProcCntF349_C;
extern const uint8  SftyMgt_ctDftMaxProcCntF34D_C;
extern const uint8  SftyMgt_ctDftMaxProcCntF38D_C;
extern const uint8  SftyMgt_ctDftMinProcCntF329_C;
extern const uint8  SftyMgt_ctDftMinProcCntF349_C;
extern const uint8  SftyMgt_ctDftMinProcCntF34D_C;
extern const uint8  SftyMgt_ctDftMinProcCntF38D_C;
extern const uint8  SftyMgt_nDecCpt_AccPCoh_C;
extern const uint8  SftyMgt_nDecCpt_BrkPedInvCoh_C;
extern const uint8  SftyMgt_nDecCpt_CluPedSc_C;
extern const uint8  SftyMgt_nDecCpt_F329ProcFaild_C;
extern const uint8  SftyMgt_nDecCpt_F349ProcFaild_C;
extern const uint8  SftyMgt_nDecCpt_F34DProcFaild_C;
extern const uint8  SftyMgt_nDecCpt_F34DTqCohFaild_C;
extern const uint8  SftyMgt_nDecCpt_F38DProcFaild_C;
extern const uint8  SftyMgt_nDecCpt_NeutSc_C;
extern const uint8  SftyMgt_nDecCpt_ThrCoh_C;
extern const uint8  SftyMgt_nDecCpt_VehSpdCoh_C;
extern const uint8  SftyMgt_nDownThd_34DTqCohFaild_C;
extern const uint8  SftyMgt_nDownThd_BrkPedInvCoh_C;
extern const uint8  SftyMgt_nDownThd_F329ProcFaild_C;
extern const uint8  SftyMgt_nDownThd_F349ProcFaild_C;
extern const uint8  SftyMgt_nDownThd_F34DProcFaild_C;
extern const uint8  SftyMgt_nDownThd_F38DProcFaild_C;
extern const uint8  SftyMgt_nDownThd_ThrCoh_C;
extern const uint8  SftyMgt_nDownTranThd_AccPCoh_C;
extern const uint8  SftyMgt_nDownTranThd_CluPedSc_C;
extern const uint8  SftyMgt_nDownTranThd_NeutSc_C;
extern const uint8  SftyMgt_nDownTranThd_VehSpdCoh_C;
extern const uint8  SftyMgt_nIniCpt_F34DTqCohFaild_C;
extern const uint8  SftyMgt_nInitCpt_BrkPedInvCoh_C;
extern const uint8  SftyMgt_nInitCpt_F329ProcFaild_C;
extern const uint8  SftyMgt_nInitCpt_F349ProcFaild_C;
extern const uint8  SftyMgt_nInitCpt_F34DProcFaild_C;
extern const uint8  SftyMgt_nInitCpt_F38DProcFaild_C;
extern const uint8  SftyMgt_nInitCpt_ThrCoh_C;
extern const uint8  SftyMgt_nInitCptConf_AccPCoh_C;
extern const uint8  SftyMgt_nInitCptConf_CluPedSc_C;
extern const uint8  SftyMgt_nInitCptConf_NeutSc_C;
extern const uint8  SftyMgt_nInitCptConf_VehSpdCoh_C;
extern const uint8  SftyMgt_nUpThd_BrkPedInvCoh_C;
extern const uint8  SftyMgt_nUpThd_F329ProcFaild_C;
extern const uint8  SftyMgt_nUpThd_F349ProcFaild_C;
extern const uint8  SftyMgt_nUpThd_F34DProcFaild_C;
extern const uint8  SftyMgt_nUpThd_F34DTqCohFaild_C;
extern const uint8  SftyMgt_nUpThd_F38DProcFaild_C;
extern const uint8  SftyMgt_nUpTranThd_AccPCoh_C;
extern const uint8  SftyMgt_nUpTranThd_CluPedSc_C;
extern const uint8  SftyMgt_nUpTranThd_NeutSc_C;
extern const uint8  SftyMgt_nUpTranThd_ThrCoh_C;
extern const uint8  SftyMgt_nUpTranThd_VehSpdCoh_C;
extern const uint8  SftyMgt_ThdAccelBrk_C;
extern const uint8  SftyMgt_ThdDecelBrk_C;
extern const uint8  SftyMgt_ticounterBattMes_C;
extern const uint8  SftyMgt_ticounterEngStrtReq_C;
extern const uint8  SftyMgt_ticounterWkuMain_C;
extern const uint8  SftyMgt_tiSpdVehInit_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftyMgt_facFilSpdVehLvl2_C;
extern const uint16  SftyMgt_rDftMaxCluPed_C;
extern const uint16  SftyMgt_rDftMaxNeut_C;
extern const uint16  SftyMgt_rDftMinCluPed_C;
extern const uint16  SftyMgt_rDftMinNeut_C;
extern const uint16  SftyMgt_spdGrdMax_C;
extern const uint16  SftyMgt_spdVehIniLvl2_C;
extern const uint16  SftyMgt_spdVehMax_inhLvl2_C;
extern const uint16  SftyMgt_spdVehMaxISCANLvl2_C;
extern const uint16  SftyMgt_spdVehMinISCANLvl2_C;
extern const uint16  SftyMgt_tiBrkPedPressInit_C;
extern const uint16  SftyMgt_uAccPCohMax_C;
extern const uint16  SftyMgt_uBattMaxUCFtoCMMLvl2;
extern const uint16  SftyMgt_uBattMinUCFtoCMMLvl2;
extern const uint16  SftyMgt_uThrCohMax_C;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/
#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bAcvDiagCanSftyLvl2;
extern boolean SftyMgt_bDftCks_F329;
extern boolean SftyMgt_bDftCks_F349;
extern boolean SftyMgt_bDftCks_F38D;
extern boolean SftyMgt_bDftSftyCoh_AccP;
extern boolean SftyMgt_bDftSftyCoh_Thr;
extern boolean SftyMgt_bDftSftyCoh_VehSpd;
extern boolean SftyMgt_bDftSftyInvCoh_BrkPed;
extern boolean SftyMgt_bDftSftyPrcFaild_F329;
extern boolean SftyMgt_bDftSftyPrcFaild_F349;
extern boolean SftyMgt_bDftSftyPrcFaild_F34D;
extern boolean SftyMgt_bDftSftyPrcFaild_F38D;
extern boolean SftyMgt_bDftSftySc_CluPed;
extern boolean SftyMgt_bDftSftySc_Neut;
extern boolean SftyMgt_bDftSftyTqCoh_F34D;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 SftyMgt_spdVehSecu;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_EveRst_DiagSftyLvl2(void);
void SftyMgt_EveRxn329_DiagSftyLvl2(void);
void SftyMgt_EveRxn349_DiagSftyLvl2(void);
void SftyMgt_EveRxn34D_DiagSftyLvl2(void);
void SftyMgt_EveRxn38D_DiagSftyLvl2(void);
void SftyMgt_SdlMid_DiagSftyLvl2(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* DIAGSFTYLVL2_H */

/*-------------------------------- end of file -------------------------------*/
