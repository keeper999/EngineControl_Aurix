/***************************************************************************
;**
;** FILE NAME      : TWCMGT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TWCMGT.H"
#include "TWCMGT_L.H"
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

#pragma section ".calib" a
const boolean  TWCMgt_bInhAcvExServoCdn_C = 0;
const boolean  TWCMgt_bInhAcvInServoCdn_C = 0;
const boolean  TWCMgt_bInhCtlTrbPosn_C = 0;
const boolean  TWCMgt_bInhReGearHeatDeac_C = 0;
const boolean  TWCMgt_bRstETBTiPha1_C = 0;
const uint8  TWCMgt_facFilRatEfcLsUsPer_C = 0;
const uint8  TWCMgt_rAccePedDrvReq_C = 0;
const uint8  TWCMgt_stAcvHeatPha_T[TWCMGT_STACVHEATPHA_T_COLS] = {0};
const uint8  TWCMgt_stModLiOffClc_C = 0;
const uint8  TWCMgt_tCoAcvHeatPha_A[TWCMGT_TCOACVHEATPHA_A_COLS] = {0};
const uint8  TWCMGT_u8Inhib = 0;
const sint16  TWCMgt_tThdDifMaxTInTCo_C = 0;
const sint16  TWCMgt_tThdDifTCo_C = 0;
const sint16  TWCMgt_tTWCHeatDeacThd_C = 0;
const sint16  TWCMgt_tTWCHeatPha3Acv_C = 0;
const sint16  TWCMgt_tTWCLiOff_C = 0;
const sint16  TWCMgt_tTWCMaxHeatAcvT_C = 0;
const uint16  TWCMgt_dstDftKmOldVeh_C = 0;
const uint16  TWCMgt_dstVeh_tiPha1Km_A[TWCMGT_DSTVEH_TIPHA1KM_A_COLS] = {0};
const uint16  TWCMgt_mO2Stg_tiPha_A[TWCMGT_MO2STG_TIPHA_A_COLS] = {0};
const uint16  TWCMgt_nEngToDrvReq_A[TWCMGT_NENGTODRVREQ_A_COLS] = {0};
const uint16  TWCMgt_nEngTWCStrtThd_C = 0;
const uint16  TWCMgt_noRatEfcLsUsPer_A[TWCMGT_NORATEFCLSUSPER_A_COLS] = {0};
const uint16  TWCMgt_pThrMinAmbPres_C = 0;
const uint16  TWCMgt_resLsUsHeat_A[TWCMGT_RESLSUSHEAT_A_COLS] = {0};
const uint16  TWCMgt_rMisfOBD_tPha1Misf_A[TWCMGT_RMISFOBD_TPHA1MISF_A_COLS] = {0};
const uint16  TWCMgt_tiDlyAcvCdnAcvHiAr_C = 0;
const uint16  TWCMgt_tiDlyAcvCdnAcvLoAr_C = 0;
const uint16  TWCMgt_tiDlyGearIdl_C = 0;
const uint16  TWCMgt_tiDlyIdlHeatPhaThd_C = 0;
const uint16  TWCMgt_tiDlyPha3_C = 0;
const uint16  TWCMgt_tiDlyTWCHeatDeac_C = 0;
const uint16  TWCMgt_tiDlyTWCLiOff_C = 0;
const uint16  TWCMgt_tiHeatCaseDeac_A[TWCMGT_TIHEATCASEDEAC_A_COLS] = {0};
const uint16  TWCMgt_tiHeatCaseDeacLiOff_T[TWCMGT_TIHEATCASEDEACLIOFF_T_COLS] = {0};
const uint16  TWCMgt_tiHeatHiAr_A[TWCMGT_TIHEATHIAR_A_COLS] = {0};
const uint16  TWCMgt_tiLiOffDone_T[TWCMGT_TILIOFFDONE_T_COLS] = {0};
const uint16  TWCMgt_tiMaxHeatThdLoAr_C = 0;
const uint16  TWCMgt_tiPha1_tiTrbPosn_A[TWCMGT_TIPHA1_TITRBPOSN_A_COLS] = {0};
const uint16  TWCMgt_tiPha1ETB_C = 0;
const uint16  TWCMgt_tiPha1Km_T[TWCMGT_TIPHA1KM_T_COLS] = {0};
const uint16  TWCMgt_tiPha1Misf_T[TWCMGT_TIPHA1MISF_T_COLS] = {0};
const uint16  TWCMgt_tiPha3Acv_T[TWCMGT_TIPHA3ACV_T_COLS] = {0};
const uint16  TWCMgt_tiPhaO2Stg_T[TWCMGT_TIPHAO2STG_T_COLS] = {0};
const uint16  TWCMgt_tiPhaRatEfcLsUsPer_T[TWCMGT_TIPHARATEFCLSUSPER_T_COLS] = {0};
const uint16  TWCMgt_tiResLsUsHeat_T[TWCMGT_TIRESLSUSHEAT_T_COLS] = {0};
const uint16  TWCMgt_tiSdlFast_C = 0;
const uint16  TWCMgt_tiThdMinEngStopRst_C = 0;
const uint16  TWCMgt_tiTrbClsPosn_T[TWCMGT_TITRBCLSPOSN_T_COLS] = {0};
const uint16  TWCMgt_tiTrbClsPosnThdLoAr_C = 0;
const uint16  TWCMgt_tiTrbOpPosn_T[TWCMGT_TITRBOPPOSN_T_COLS] = {0};
const uint16  TWCMgt_tiTrbOpPosnThdLoAr_C = 0;
const uint16  TWCMgt_tiTWCHeatDeac_T[TWCMGT_TITWCHEATDEAC_T_COLS] = {0};
const uint16  TWCMgt_tiTWCLiOffHeatLoAr_C = 0;
const uint16  TWCMgt_tqNEngDrvReq_T[TWCMGT_TQNENGDRVREQ_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean OxC_bIntrHeat;
boolean TWCMgt_bAcvHeatPha;
boolean TWCMGT_bAcvHeatPhaPrev;
boolean TWCMgt_bAcvNEngAcvCdn;
boolean TWCMgt_bAcvNEngBegCdnAcv;
boolean TWCMgt_bAfterEngStrtReqCdn;
boolean TWCMGT_bBasculRS1;
boolean TWCMgt_bDeacHeatPha;
boolean TWCMGT_bDeacHeatPhaPrev;
boolean TWCMGT_bInGearIdlTurnOnPrev;
boolean TWCMGT_bInHeatPhaTurnOnPrev;
boolean TWCMGT_bIntiDlyPha3TurnOnPrev;
boolean TWCMGT_bInTWCHeatTurnOnPrev;
boolean TWCMGT_bInTWCLiOffTurnOnPrev;
boolean TWCMgt_bLiOffClcAuth;
boolean TWCMgt_bLiOffDonePrev;
boolean TWCMGT_bLsMonbEndMonResHeatPrev;
boolean TWCMGT_bMonMisfbClcMisfOBDPrev;
boolean TWCMGT_bOutGearIdlTurnOnDelay;
boolean TWCMGT_bOutHeatPhaTurnOnDelay;
boolean TWCMGT_bOuttiDlyPha3TurnOnDelay;
boolean TWCMGT_bOutTurnOnDelay;
boolean TWCMGT_bOutTWCHeatTurnOnDelay;
boolean TWCMGT_bOutTWCLiOffTurnOnDelay;
boolean TWCMGT_bOxCbEndMonORngItrsvPrev;
boolean TWCMGT_bRstETBTiPha1Prev;
boolean TWCMgt_bTCoAr;
boolean TWCMgt_bTWCHeatPha3Acv;
boolean TWCMgt_bTWCHeatReq;
boolean TWCMgt_bTWCHeatReqPrev;
boolean TWCMGT_bTWCHeatReqPrev2;
boolean TWCMgt_bTWCMinStrtCdnReq;
boolean TWCMGT_bTWCMinStrtCdnReqPrev;
uint32 TWCMGT_u32FilterKMem;
uint8 TWCMgt_stHeatPhaReqBas;
uint8 TWCMgt_stTrbActPosnReqBas;
uint16 TWCMgt_dstVehMesLoResl_MP;
uint16 TWCMgt_tiHiTWCCurEstim_MP;
uint16 TWCMgt_tiHiTWCHiAr;
uint16 TWCMgt_tiHiTWCHiArPrev;
uint16 TWCMgt_tiLiOff;
uint16 TWCMgt_tiLiOffHeatDeac;
uint16 TWCMgt_tiLiOffNormCdn;
uint16 TWCMgt_tiOutStg_MP;
uint16 TWCMgt_tiPha1Km;
uint16 TWCMgt_tiPha1Misf;
uint16 TWCMgt_tiPhaO2Stg;
uint16 TWCMgt_tiPhaRatEfcLsUsPer;
uint16 TWCMgt_tiResLsUsHeat;
uint16 TWCMgt_tiTWC;
uint16 TWCMGT_u16AcvCdnAcvCount;
uint16 TWCMGT_u16GearIdlCount;
uint16 TWCMGT_u16HeatPhaCount;
uint16 TWCMGT_u16InputdstVehTiPha1Km;
uint16 TWCMGT_u16InputTtiHeatCaseDeac;
uint16 TWCMGT_u16OutPassFilterK;
uint16 TWCMGT_u16tiDlyPha3Count;
uint16 TWCMGT_u16tiLiOffOutMem;
uint16 TWCMGT_u16TWCHeatCount;
uint16 TWCMGT_u16TWCLiOffCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

