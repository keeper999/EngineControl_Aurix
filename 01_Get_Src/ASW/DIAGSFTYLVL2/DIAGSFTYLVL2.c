/***************************************************************************
;**
;** FILE NAME      : DIAGSFTYLVL2.C75
;**
;** FILE AUTHOR    : MBENFRADJ (VEES)
;**
;**************************************************************************/

#include "STD_TYPES.h"
#include "DIAGSFTYLVL2.h"
#include "DIAGSFTYLVL2_l.h"

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
const boolean  Ext_bAcv_F329SftyLvl2_C = 0;
const boolean  Ext_bAcv_F349SftyLvl2_C = 0;
const boolean  Ext_bAcv_F34DSftyLvl2_C = 0;
const boolean  Ext_bAcv_F38DSftyLvl2_C = 0;
const boolean  Ext_bAcv_NeutPosSftyLvl2_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  DIAGSFTYLVL2_u8Inhib = 0;
const uint8  SftyMgt_ctDftMaxProcCntF329_C = 0;
const uint8  SftyMgt_ctDftMaxProcCntF349_C = 0;
const uint8  SftyMgt_ctDftMaxProcCntF34D_C = 0;
const uint8  SftyMgt_ctDftMaxProcCntF38D_C = 0;
const uint8  SftyMgt_ctDftMinProcCntF329_C = 0;
const uint8  SftyMgt_ctDftMinProcCntF349_C = 0;
const uint8  SftyMgt_ctDftMinProcCntF34D_C = 0;
const uint8  SftyMgt_ctDftMinProcCntF38D_C = 0;
const uint8  SftyMgt_nDecCpt_AccPCoh_C = 0;
const uint8  SftyMgt_nDecCpt_BrkPedInvCoh_C = 0;
const uint8  SftyMgt_nDecCpt_CluPedSc_C = 0;
const uint8  SftyMgt_nDecCpt_F329ProcFaild_C = 0;
const uint8  SftyMgt_nDecCpt_F349ProcFaild_C = 0;
const uint8  SftyMgt_nDecCpt_F34DProcFaild_C = 0;
const uint8  SftyMgt_nDecCpt_F34DTqCohFaild_C = 0;
const uint8  SftyMgt_nDecCpt_F38DProcFaild_C = 0;
const uint8  SftyMgt_nDecCpt_NeutSc_C = 0;
const uint8  SftyMgt_nDecCpt_ThrCoh_C = 0;
const uint8  SftyMgt_nDecCpt_VehSpdCoh_C = 0;
const uint8  SftyMgt_nDownThd_34DTqCohFaild_C = 0;
const uint8  SftyMgt_nDownThd_BrkPedInvCoh_C = 0;
const uint8  SftyMgt_nDownThd_F329ProcFaild_C = 0;
const uint8  SftyMgt_nDownThd_F349ProcFaild_C = 0;
const uint8  SftyMgt_nDownThd_F34DProcFaild_C = 0;
const uint8  SftyMgt_nDownThd_F38DProcFaild_C = 0;
const uint8  SftyMgt_nDownThd_ThrCoh_C = 0;
const uint8  SftyMgt_nDownTranThd_AccPCoh_C = 0;
const uint8  SftyMgt_nDownTranThd_CluPedSc_C = 0;
const uint8  SftyMgt_nDownTranThd_NeutSc_C = 0;
const uint8  SftyMgt_nDownTranThd_VehSpdCoh_C = 0;
const uint8  SftyMgt_nIniCpt_F34DTqCohFaild_C = 0;
const uint8  SftyMgt_nInitCpt_BrkPedInvCoh_C = 0;
const uint8  SftyMgt_nInitCpt_F329ProcFaild_C = 0;
const uint8  SftyMgt_nInitCpt_F349ProcFaild_C = 0;
const uint8  SftyMgt_nInitCpt_F34DProcFaild_C = 0;
const uint8  SftyMgt_nInitCpt_F38DProcFaild_C = 0;
const uint8  SftyMgt_nInitCpt_ThrCoh_C = 0;
const uint8  SftyMgt_nInitCptConf_AccPCoh_C = 0;
const uint8  SftyMgt_nInitCptConf_CluPedSc_C = 0;
const uint8  SftyMgt_nInitCptConf_NeutSc_C = 0;
const uint8  SftyMgt_nInitCptConf_VehSpdCoh_C = 0;
const uint8  SftyMgt_nUpThd_BrkPedInvCoh_C = 0;
const uint8  SftyMgt_nUpThd_F329ProcFaild_C = 0;
const uint8  SftyMgt_nUpThd_F349ProcFaild_C = 0;
const uint8  SftyMgt_nUpThd_F34DProcFaild_C = 0;
const uint8  SftyMgt_nUpThd_F34DTqCohFaild_C = 0;
const uint8  SftyMgt_nUpThd_F38DProcFaild_C = 0;
const uint8  SftyMgt_nUpTranThd_AccPCoh_C = 0;
const uint8  SftyMgt_nUpTranThd_CluPedSc_C = 0;
const uint8  SftyMgt_nUpTranThd_NeutSc_C = 0;
const uint8  SftyMgt_nUpTranThd_ThrCoh_C = 0;
const uint8  SftyMgt_nUpTranThd_VehSpdCoh_C = 0;
const uint8  SftyMgt_ThdAccelBrk_C = 0;
const uint8  SftyMgt_ThdDecelBrk_C = 0;
const uint8  SftyMgt_ticounterBattMes_C = 0;
const uint8  SftyMgt_ticounterEngStrtReq_C = 0;
const uint8  SftyMgt_ticounterWkuMain_C = 0;
const uint8  SftyMgt_tiSpdVehInit_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftyMgt_facFilSpdVehLvl2_C = 0;
const uint16  SftyMgt_rDftMaxCluPed_C = 0;
const uint16  SftyMgt_rDftMaxNeut_C = 0;
const uint16  SftyMgt_rDftMinCluPed_C = 0;
const uint16  SftyMgt_rDftMinNeut_C = 0;
const uint16  SftyMgt_spdGrdMax_C = 0;
const uint16  SftyMgt_spdVehIniLvl2_C = 0;
const uint16  SftyMgt_spdVehMax_inhLvl2_C = 0;
const uint16  SftyMgt_spdVehMaxISCANLvl2_C = 0;
const uint16  SftyMgt_spdVehMinISCANLvl2_C = 0;
const uint16  SftyMgt_tiBrkPedPressInit_C = 0;
const uint16  SftyMgt_uAccPCohMax_C = 0;
const uint16  SftyMgt_uBattMaxUCFtoCMMLvl2 = 0;
const uint16  SftyMgt_uBattMinUCFtoCMMLvl2 = 0;
const uint16  SftyMgt_uThrCohMax_C = 0;
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
boolean DIAGSFTYLVL2_bDgoNiv2_AccP;
boolean DIAGSFTYLVL2_bDgoNiv2_BrkPed;
boolean DIAGSFTYLVL2_bDgoNiv2_CluPed;
boolean DIAGSFTYLVL2_bDgoNiv2_Coh;
boolean DIAGSFTYLVL2_bDgoNiv2_F329;
boolean DIAGSFTYLVL2_bDgoNiv2_F349;
boolean DIAGSFTYLVL2_bDgoNiv2_F34D;
boolean DIAGSFTYLVL2_bDgoNiv2_F38D;
boolean DIAGSFTYLVL2_bDgoNiv2_Neut;
boolean DIAGSFTYLVL2_bDgoNiv2_Thr;
boolean DIAGSFTYLVL2_bDgoNiv2_VehSpd;
boolean DIAGSFTYLVL2_bECUWkuMainPrev;
boolean DIAGSFTYLVL2_bEngRStrtReqPrev;
boolean DIAGSFTYLVL2_bFilSig_AccP;
boolean DIAGSFTYLVL2_bFilSig_BrkPed;
boolean DIAGSFTYLVL2_bFilSig_CluPed;
boolean DIAGSFTYLVL2_bFilSig_Coh;
boolean DIAGSFTYLVL2_bFilSig_F329;
boolean DIAGSFTYLVL2_bFilSig_F349;
boolean DIAGSFTYLVL2_bFilSig_F34D;
boolean DIAGSFTYLVL2_bFilSig_F38D;
boolean DIAGSFTYLVL2_bFilSig_Neut;
boolean DIAGSFTYLVL2_bFilSig_Thr;
boolean DIAGSFTYLVL2_bFilSig_VehSpd;
boolean DIAGSFTYLVL2_bPosHys;
boolean DIAGSFTYLVL2_bPosHys1;
boolean DIAGSFTYLVL2_bPosHys2;
boolean DIAGSFTYLVL2_bPosHys3;
boolean DIAGSFTYLVL2_bSftyBattMesRanPrev;
boolean DIAGSFTYLVL2_bTimeOut;
boolean DIAGSFTYLVL2_bTimerInputPrev;
boolean SftyMgt_bAcvDiagCanSftyLvl2;
boolean SftyMgt_bAuthDiagCoh_BrkPed;
boolean SftyMgt_bDftCks_F329;
boolean SftyMgt_bDftCks_F349;
boolean SftyMgt_bDftCks_F38D;
boolean SftyMgt_bDftCoh_AccP;
boolean SftyMgt_bDftCoh_SpdVeh;
boolean SftyMgt_bDftCoh_SpdVeh_Prev;
boolean SftyMgt_bDftCoh_SpdVehLvl2;
boolean SftyMgt_bDftCoh_Thr;
boolean SftyMgt_bDftInvCoh_BrkPed;
boolean SftyMgt_bDftProcCnt_F329;
boolean SftyMgt_bDftProcCnt_F349;
boolean SftyMgt_bDftProcCnt_F34D;
boolean SftyMgt_bDftProcCnt_F38D;
boolean SftyMgt_bDftSc_CluPed;
boolean SftyMgt_bDftSc_Neut;
boolean SftyMgt_bDftSftyCoh_AccP;
boolean SftyMgt_bDftSftyCoh_Thr;
boolean SftyMgt_bDftSftyCoh_VehSpd;
boolean SftyMgt_bDftSftyInvCoh_BrkPed;
boolean SftyMgt_bDftSftyPrcFaild_F329;
boolean SftyMgt_bDftSftyPrcFaild_F349;
boolean SftyMgt_bDftSftyPrcFaild_F34D;
boolean SftyMgt_bDftSftyPrcFaild_F38D;
boolean SftyMgt_bDftSftySc_CluPed;
boolean SftyMgt_bDftSftySc_Neut;
boolean SftyMgt_bDftSftyTqCoh_F34D;
boolean SftyMgt_bDftTqCoh_F34D;
boolean SftyMgt_bEndtiCohSpdVehLvl2;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 DIAGSFTYLVL2_u8CntFilt_AccP;
uint8 DIAGSFTYLVL2_u8CntFilt_BrkPed;
uint8 DIAGSFTYLVL2_u8CntFilt_CluPed;
uint8 DIAGSFTYLVL2_u8CntFilt_Coh;
uint8 DIAGSFTYLVL2_u8CntFilt_F329;
uint8 DIAGSFTYLVL2_u8CntFilt_F349;
uint8 DIAGSFTYLVL2_u8CntFilt_F34D;
uint8 DIAGSFTYLVL2_u8CntFilt_F38D;
uint8 DIAGSFTYLVL2_u8CntFilt_Neut;
uint8 DIAGSFTYLVL2_u8CntFilt_Thr;
uint8 DIAGSFTYLVL2_u8CntFilt_VehSpd;
uint8 DIAGSFTYLVL2_u8CountNiv2_AccP;
uint8 DIAGSFTYLVL2_u8CountNiv2_BrkPed;
uint8 DIAGSFTYLVL2_u8CountNiv2_CluPed;
uint8 DIAGSFTYLVL2_u8CountNiv2_Coh;
uint8 DIAGSFTYLVL2_u8CountNiv2_F329;
uint8 DIAGSFTYLVL2_u8CountNiv2_F349;
uint8 DIAGSFTYLVL2_u8CountNiv2_F34D;
uint8 DIAGSFTYLVL2_u8CountNiv2_F38D;
uint8 DIAGSFTYLVL2_u8CountNiv2_Neut;
uint8 DIAGSFTYLVL2_u8CountNiv2_Thr;
uint8 DIAGSFTYLVL2_u8CountNiv2_VehSpd;
uint8 DIAGSFTYLVL2_u8CountTimer;
uint8 DIAGSFTYLVL2_u8EspProcMax_Prev;
uint8 DIAGSFTYLVL2_u8F329P230bisPrev;
uint8 DIAGSFTYLVL2_u8F349P230Prev;
uint8 DIAGSFTYLVL2_u8F34DP157Prev;
uint8 DIAGSFTYLVL2_u8F38DP606Prev;
uint8 SftyMgt_counterBattMes;
uint8 SftyMgt_counterEngStrtReq;
uint8 SftyMgt_counterWkuMain;
uint8 SftyMgt_tiCohSpdVehLvl2;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16 DIAGSFTYLVL2_u16N16F30DP263;
uint16 DIAGSFTYLVL2_u16N16F30DP264;
uint16 DIAGSFTYLVL2_u16N16F30DP265;
uint16 DIAGSFTYLVL2_u16N16F30DP266;
uint16 SftyMgt_spdVehMinValLvl2;
uint16 SftyMgt_spdVehSecu;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
uint32 DIAGSFTYLVL2_u32N16F30DP263Mem;
uint32 DIAGSFTYLVL2_u32N16F30DP264Mem;
uint32 DIAGSFTYLVL2_u32N16F30DP265Mem;
uint32 DIAGSFTYLVL2_u32N16F30DP266Mem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

