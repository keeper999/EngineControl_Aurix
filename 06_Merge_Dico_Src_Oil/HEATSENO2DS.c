/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HEATSENO2DS.H"
#include "HEATSENO2DS_L.H"
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
const boolean  LsSys_bInhLsDsOxCNoPtOkLstStrt_C = 0;
const boolean  LsSys_bInhLsDsOxCPtOkLstStrt_C = 0;
const uint8  HEATSENO2DS_u8Inhib = 0;
const uint8  LsSys_tCoLsDsThdBoostProtReq_T[LSSYS_TCOLSDSTHDBOOSTPROTREQ_T_COLS] = {0};
const uint8  LsSys_tiLsDsDlyHeatHi_C = 0;
const uint8  LsSys_tiLsDsThdBoostProtReq_M[LSSYS_TILSDSTHDBOOSTPROTREQ_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDewTranNotOk_M[LSSYS_TILSDSDLYDEWTRANNOTOK_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDewTranOkStall_T[LSSYS_TILSDSDLYDEWTRANOKSTALL_T_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDTrIntrOxCHt_M[LSSYS_TILSDSDLYDTRINTROXCHT_M_LNS][LSSYS_TILSDSDLYDTRINTROXCHT_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDTrIntrOxCHtPnt_M[LSSYS_TILSDSDLYDTRINTROXCHTPNT_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDTrOxCHt_M[LSSYS_TILSDSDLYDTROXCHT_M_LNS][LSSYS_TILSDSDLYDTROXCHT_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyDTrOxCHtPnt_M[LSSYS_TILSDSDLYDTROXCHTPNT_M_COLS] = {0};
const uint16  LsSys_tiLsDsDlyWaitSecHeatHi_C = 0;
const uint16  LsSys_tiLsDsMaxDlyHeatLo_C = 0;
const uint16  LsSys_tiLsDsMaxDlyHeatModStop_C = 0;
const uint16  LsSys_tiLsDsWaitSecBoost_C = 0;
const uint16  LsSys_tiSumLsDsOxCHeatNullThd_C = 0;
const uint16  LsSys_tMaxLsDsHeatBoostThd_C = 0;
const uint16  LsSys_tMaxLsDsHeatHiThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 LsSys_stLsDsMainOxCHeat;
boolean HEATSENO2DS_bTimeout1;
boolean HEATSENO2DS_bTimerInit;
boolean HEATSENO2DS_bUBattAcvHeatLih;
boolean LsSys_bAcvLsDsMainOxCHeatLih;
boolean LsSys_bAcvLsDsMainOxCHeatLo;
boolean LsSys_bLsDsBoostEnd;
boolean LsSys_bLsDsDetRTStall;
boolean LsSys_bLsDsMainOxCAcvHeatHi;
boolean LsSys_bLsDsMainOxCDewProtReq;
boolean LsSys_bLsDsMainOxCDewPtNOk;
boolean LsSys_bLsDsMainOxCDewPtOkLstStrt;
boolean LsSys_bLsDsMainOxCHeatEna;
boolean LsSys_bLsDsMainOxCHeatHiEnd;
boolean LsSys_bLsDsMainOxCHeatHotEna;
boolean LsSys_bLsDsMainOxCHeatLoEnd;
boolean LsSys_bLsDsMainOxCHeatProtEnd;
boolean LsSys_bNotrackPwrLsDsMainOxCHeat;
uint32 LsSys_tiLsDsDlySinceLstHeatHi;
uint8 HEATSENO2DS_stEngPrev;
uint8 HEATSENO2DS_u8MainOxCHeatPrev;
uint8 HEATSENO2DS_u8OxCHeatPrevslow;
uint8 LsSys_tiLsDsBoostProtReq;
uint16 LsSys_tiLsDsDlyAcvHeatLih;
uint16 LsSys_tiLsDsDlyDewTranNotOk;
uint16 LsSys_tiLsDsDlyDTrIntrOxCHt;
uint16 LsSys_tiLsDsDlyDTrIntrOxCHtPnt;
uint16 LsSys_tiLsDsDlyDTrOxCHt;
uint16 LsSys_tiLsDsDlyDTrOxCHtPnt;
uint16 LsSys_tiLsDsDlyMainOxCPhaseC;
uint16 LsSys_tiLsDsDlyMainOxCPhaseD;
uint16 LsSys_tiLsDsDlyMainOxCPhaseF;
uint16 LsSys_tiLsDsMainOxCDlyDewTranOk;
uint16 LsSys_tiLsDsMaxDlyHeatModStop;
uint16 LsSys_tiSumLsDsMainOxCHeatNull;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

