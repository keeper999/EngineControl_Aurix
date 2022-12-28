/***************************************************************************
;**
;** FILE NAME      : HEATSENO2US.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2US_H
#define HEATSENO2US_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CAT_OLD_GAIN_BKPT_MAP_COLS             ( 8 )
#define LSSYS_TAIRFLOENA_T_COLS                ( 6 )
#define LSSYS_TCOLSUSTHDBOOSTPROTREQ_T_COLS    ( 6 )
#define LSSYS_TCOOLFLOENA_T_COLS               ( 6 )
#define LSSYS_TILSUSDLYDEWTRANNOTOK_M_COLS     ( 8 )
#define LSSYS_TILSUSDLYDEWTRANOKSTALL_T_COLS   ( 8 )
#define LSSYS_TILSUSDLYDTRINTROXCHT_M_LNS     ( 16 )
#define LSSYS_TILSUSDLYDTRINTROXCHT_M_COLS     ( 6 )
#define LSSYS_TILSUSDLYDTRINTROXCHTPNT_M_COLS  ( 16 )
#define LSSYS_TILSUSDLYDTROXCHT_M_LNS         ( 16 )
#define LSSYS_TILSUSDLYDTROXCHT_M_COLS         ( 8 )
#define LSSYS_TILSUSDLYDTROXCHTPNT_M_COLS      ( 16 )
#define LSSYS_TILSUSDLYHEATHIFLO_M_COLS        ( 8 )
#define LSSYS_TILSUSTHDBOOSTPROTREQ_M_COLS     ( 6 )
#define LSSYS_TIPHASEB_TIHEATHIFLO_A_COLS      ( 8 )
#define LSSYS_VEHDSTFLOENA_T_COLS              ( 6 )
#define TEMPERATURE_AIR_BKPT_MAP_COLS          ( 6 )
#define TEMPERATURE_WATER_BKPT_MAP_COLS        ( 16 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st71 */
#define LSUSMAINOXCHEAT_PHASE_A           0
#define LSUSMAINOXCHEAT_PHASE_B           1
#define LSUSMAINOXCHEAT_PHASE_C1          2
#define LSUSMAINOXCHEAT_PHASE_C2          3
#define LSUSMAINOXCHEAT_PHASE_D           4
#define LSUSMAINOXCHEAT_PHASE_E           5
#define LSUSMAINOXCHEAT_PHASE_F           6
#define LSUSMAINOXCHEAT_PHASE_G           7
/*extern uint8 LsSys_stLsUsMainOxCHeat;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  LsSys_bHeatWkuEna_C;
extern const boolean  LsSys_bInhLsUsOxCNoPtOkLstStrt_C;
extern const boolean  LsSys_bInhLsUsOxCPtOkLstStrt_C;
extern const boolean  LsSys_bLsUsMaxDlyStopFLOEna_C;
extern const uint32  LsSys_tiLsUsMaxDlyStopFLOEna_C;
extern const uint8  Cat_old_gain_bkpt_map[CAT_OLD_GAIN_BKPT_MAP_COLS];
extern const uint8  LsSys_bTAirFLOEna_M;
extern const uint8  LsSys_bTCoolFLOEna_M;
extern const uint8  LsSys_bVehDstFLOEna_M;
extern const uint8  LsSys_tAirFLOEna_T[LSSYS_TAIRFLOENA_T_COLS];
extern const uint8  LsSys_tCoLsUsThdBoostProtReq_T[LSSYS_TCOLSUSTHDBOOSTPROTREQ_T_COLS];
extern const uint8  LsSys_tCoolFLOEna_T[LSSYS_TCOOLFLOENA_T_COLS];
extern const uint8  LsSys_tiDlyAcvHeatLih_C;
extern const uint8  LsSys_tiLsUsDlyDewProtReqFLO_C;
extern const uint8  LsSys_tiLsUsDlyHeatHi_C;
extern const uint8  LsSys_tiLsUsDlyHeatHiFLO_M[LSSYS_TILSUSDLYHEATHIFLO_M_COLS];
extern const uint8  LsSys_tiLsUsThdBoostProtReq_M[LSSYS_TILSUSTHDBOOSTPROTREQ_M_COLS];
extern const uint8  LsSys_uBattAcvHeatLih_C;
extern const uint8  LsSys_uHeatWkuEna_C;
extern const uint8  Temperature_air_bkpt_map[TEMPERATURE_AIR_BKPT_MAP_COLS];
extern const uint8  Temperature_water_bkpt_map[TEMPERATURE_WATER_BKPT_MAP_COLS];
extern const sint16  LsSys_tCoLihLsHeat_C;
extern const sint16  LsSys_tCoolHeatHotThd_C;
extern const sint16  LsSys_tDsThrLihLsHeat_C;
extern const uint16  LsSys_tiDlyHeatWkuEna_C;
extern const uint16  LsSys_tiLsUsDlyDewTranNotOk_M[LSSYS_TILSUSDLYDEWTRANNOTOK_M_COLS];
extern const uint16  LsSys_tiLsUsDlyDewTranOkStall_T[LSSYS_TILSUSDLYDEWTRANOKSTALL_T_COLS];
extern const uint16  LsSys_tiLsUsDlyDTrIntrOxCHt_M[LSSYS_TILSUSDLYDTRINTROXCHT_M_LNS][LSSYS_TILSUSDLYDTRINTROXCHT_M_COLS];
extern const uint16  LsSys_tiLsUsDlyDTrIntrOxCHtPnt_M[LSSYS_TILSUSDLYDTRINTROXCHTPNT_M_COLS];
extern const uint16  LsSys_tiLsUsDlyDTrOxCHt_M[LSSYS_TILSUSDLYDTROXCHT_M_LNS][LSSYS_TILSUSDLYDTROXCHT_M_COLS];
extern const uint16  LsSys_tiLsUsDlyDTrOxCHtPnt_M[LSSYS_TILSUSDLYDTROXCHTPNT_M_COLS];
extern const uint16  LsSys_tiLsUsDlyWaitSecHeatHi_C;
extern const uint16  LsSys_tiLsUsMaxDlyHeatLo_C;
extern const uint16  LsSys_tiLsUsMaxDlyHeatModStop_C;
extern const uint16  LsSys_tiLsUsWaitSecBoost_C;
extern const uint16  LsSys_tiPhaseB_tiHeatHiFLO_A[LSSYS_TIPHASEB_TIHEATHIFLO_A_COLS];
extern const uint16  LsSys_tiSumLsUsOxCHeatNullThd_C;
extern const uint16  LsSys_tiThdWkuDewProtReqFLO_C;
extern const uint16  LsSys_tMaxLsUsHeatBoostThd_C;
extern const uint16  LsSys_tMaxLsUsHeatHiThd_C;
extern const uint16  LsSys_VehDstFLOEna_T[LSSYS_VEHDSTFLOENA_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 LsSys_stLsUsMainOxCHeat;
extern boolean Ext_bAcvHeatWkuLsSys;
extern boolean LsSys_bAcvLsUsMainOxCHeatLih;
extern boolean LsSys_bHeatDoneNotIntr;
extern boolean LsSys_bLsFloOxCHeatReq;
extern boolean LsSys_bLsOxCHeatAftStrt;
extern boolean LsSys_bLsUsMainOxCHeatFloEna;
extern sint16 LsSys_tCoLsHeat;
extern sint16 LsSys_tDsThrLsHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveCrTR_UsMgr(void);
void HeatSenO2_EveRst_UsMgr(void);
void HeatSenO2_EveRTSt_UsMgr(void);
void HeatSenO2_EveStTCr_UsMgr(void);
void HeatSenO2_SdlFast_UsMgr(void);
void HeatSenO2_SdlMid_UsMgr(void);
void HeatSenO2_SdlSlow_UsMgr(void);


#endif /* HEATSENO2US_H */

/*-------------------------------- end of file -------------------------------*/
