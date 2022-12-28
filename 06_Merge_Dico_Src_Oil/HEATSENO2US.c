/***************************************************************************
;**
;** FILE NAME      : HEATSENO2US.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2US.H"
#include "HEATSENO2US_L.H"
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
const boolean  LsSys_bHeatWkuEna_C = 0;
const boolean  LsSys_bInhLsUsOxCNoPtOkLstStrt_C = 0;
const boolean  LsSys_bInhLsUsOxCPtOkLstStrt_C = 0;
const boolean  LsSys_bLsUsMaxDlyStopFLOEna_C = 0;
const uint32  LsSys_tiLsUsMaxDlyStopFLOEna_C = 0;
const uint8  Cat_old_gain_bkpt_map[CAT_OLD_GAIN_BKPT_MAP_COLS] = {0};
const uint8  HEATSENO2US_u8Inhib = 0;
const uint8  LsSys_bTAirFLOEna_M = 0;
const uint8  LsSys_bTCoolFLOEna_M = 0;
const uint8  LsSys_bVehDstFLOEna_M = 0;
const uint8  LsSys_tAirFLOEna_T[LSSYS_TAIRFLOENA_T_COLS] = {0};
const uint8  LsSys_tCoLsUsThdBoostProtReq_T[LSSYS_TCOLSUSTHDBOOSTPROTREQ_T_COLS] = {0};
const uint8  LsSys_tCoolFLOEna_T[LSSYS_TCOOLFLOENA_T_COLS] = {0};
const uint8  LsSys_tiDlyAcvHeatLih_C = 0;
const uint8  LsSys_tiLsUsDlyDewProtReqFLO_C = 0;
const uint8  LsSys_tiLsUsDlyHeatHi_C = 0;
const uint8  LsSys_tiLsUsDlyHeatHiFLO_M[LSSYS_TILSUSDLYHEATHIFLO_M_COLS] = {0};
const uint8  LsSys_tiLsUsThdBoostProtReq_M[LSSYS_TILSUSTHDBOOSTPROTREQ_M_COLS] = {0};
const uint8  LsSys_uBattAcvHeatLih_C = 0;
const uint8  LsSys_uHeatWkuEna_C = 0;
const uint8  Temperature_air_bkpt_map[TEMPERATURE_AIR_BKPT_MAP_COLS] = {0};
const uint8  Temperature_water_bkpt_map[TEMPERATURE_WATER_BKPT_MAP_COLS] = {0};
const sint16  LsSys_tCoLihLsHeat_C = 0;
const sint16  LsSys_tCoolHeatHotThd_C = 0;
const sint16  LsSys_tDsThrLihLsHeat_C = 0;
const uint16  LsSys_tiDlyHeatWkuEna_C = 0;
const uint16  LsSys_tiLsUsDlyDewTranNotOk_M[LSSYS_TILSUSDLYDEWTRANNOTOK_M_COLS] = {0};
const uint16  LsSys_tiLsUsDlyDewTranOkStall_T[LSSYS_TILSUSDLYDEWTRANOKSTALL_T_COLS] = {0};
const uint16  LsSys_tiLsUsDlyDTrIntrOxCHt_M[LSSYS_TILSUSDLYDTRINTROXCHT_M_LNS][LSSYS_TILSUSDLYDTRINTROXCHT_M_COLS] = {0};
const uint16  LsSys_tiLsUsDlyDTrIntrOxCHtPnt_M[LSSYS_TILSUSDLYDTRINTROXCHTPNT_M_COLS] = {0};
const uint16  LsSys_tiLsUsDlyDTrOxCHt_M[LSSYS_TILSUSDLYDTROXCHT_M_LNS][LSSYS_TILSUSDLYDTROXCHT_M_COLS] = {0};
const uint16  LsSys_tiLsUsDlyDTrOxCHtPnt_M[LSSYS_TILSUSDLYDTROXCHTPNT_M_COLS] = {0};
const uint16  LsSys_tiLsUsDlyWaitSecHeatHi_C = 0;
const uint16  LsSys_tiLsUsMaxDlyHeatLo_C = 0;
const uint16  LsSys_tiLsUsMaxDlyHeatModStop_C = 0;
const uint16  LsSys_tiLsUsWaitSecBoost_C = 0;
const uint16  LsSys_tiPhaseB_tiHeatHiFLO_A[LSSYS_TIPHASEB_TIHEATHIFLO_A_COLS] = {0};
const uint16  LsSys_tiSumLsUsOxCHeatNullThd_C = 0;
const uint16  LsSys_tiThdWkuDewProtReqFLO_C = 0;
const uint16  LsSys_tMaxLsUsHeatBoostThd_C = 0;
const uint16  LsSys_tMaxLsUsHeatHiThd_C = 0;
const uint16  LsSys_VehDstFLOEna_T[LSSYS_VEHDSTFLOENA_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 LsSys_stLsUsMainOxCHeat;
boolean Ext_bAcvHeatWkuLsSys;
boolean HEATSENO2US_bTimeout1;
boolean HEATSENO2US_bTimerInit;
boolean HEATSENO2US_bUBattAcvHeatLih;
boolean LsSys_bAcvLsUsMainOxCHeatLih;
boolean LsSys_bAcvLsUsMainOxCHeatLo;
boolean LsSys_bHeatDoneNotIntr;
boolean LsSys_bHeatWkuLsSysDone;
boolean LsSys_bLsFloOxCHeatReq;
boolean LsSys_bLsOxCHeatAftStrt;
boolean LsSys_bLsUsBoostEnd;
boolean LsSys_bLsUsDetRTStall;
boolean LsSys_bLsUsMainOxcAcvFLO;
boolean LsSys_bLsUsMainOxCAcvHeatHi;
boolean LsSys_bLsUsMainOxCDewPtNOk;
boolean LsSys_bLsUsMainOxCDewPtOkLstStrt;
boolean LsSys_bLsUsMainOxCDiFLO;
boolean LsSys_bLsUsMainOxCHeatEna;
boolean LsSys_bLsUsMainOxCHeatFloEna;
boolean LsSys_bLsUsMainOxCHeatHiEnd;
boolean LsSys_bLsUsMainOxCHeatHotEna;
boolean LsSys_bLsUsMainOxCHeatLoEnd;
boolean LsSys_bLsUsMainOxCHeatProtEnd;
boolean LsSys_bLsUsMainOxCHeatWkuEna;
boolean LsSys_bLsUsMainOxCHeatWkuEnd;
boolean LsSys_bLsUsTAirFLOEna;
boolean LsSys_bLsUsTCoolFLOEna;
boolean LsSys_bLsUsVehDstFLOEna;
boolean LsSys_bNotrackPwrLsUsMainOxCHeat;
uint32 LsSys_tiLsUsDlySinceLstHeatHi;
uint8 HEATSENO2US_stEngPrev;
uint8 HEATSENO2US_u8MainOxCHeatPrev;
uint8 HEATSENO2US_u8OxCHeatPrevslow;
uint8 LsSys_tiLsUsBoostProtReq;
sint16 LsSys_tCoLsHeat;
sint16 LsSys_tDsThrLsHeat;
uint16 LsSys_tiLsUsDlyAcvHeatLih;
uint16 LsSys_tiLsUsDlyDewTranNotOk;
uint16 LsSys_tiLsUsDlyDTrIntrOxCHt;
uint16 LsSys_tiLsUsDlyDTrIntrOxCHtPnt;
uint16 LsSys_tiLsUsDlyDTrOxCHt;
uint16 LsSys_tiLsUsDlyDTrOxCHtPnt;
uint16 LsSys_tiLsUsDlyMainOxCPhaseB;
uint16 LsSys_tiLsUsDlyMainOxCPhaseC;
uint16 LsSys_tiLsUsDlyMainOxCPhaseD;
uint16 LsSys_tiLsUsDlyMainOxCPhaseF;
uint16 LsSys_tiLsUsMainOxCDlyDewTranOk;
uint16 LsSys_tiLsUsMaxDlyHeatModStop;
uint16 LsSys_tiSumLsUsMainOxCHeatNull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

