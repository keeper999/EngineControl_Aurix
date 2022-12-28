/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DS_H
#define HEATSENO2DS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define LSSYS_TCOLSDSTHDBOOSTPROTREQ_T_COLS    ( 6 )
#define LSSYS_TILSDSDLYDEWTRANNOTOK_M_COLS     ( 8 )
#define LSSYS_TILSDSDLYDEWTRANOKSTALL_T_COLS   ( 8 )
#define LSSYS_TILSDSDLYDTRINTROXCHT_M_LNS     ( 16 )
#define LSSYS_TILSDSDLYDTRINTROXCHT_M_COLS     ( 6 )
#define LSSYS_TILSDSDLYDTRINTROXCHTPNT_M_COLS  ( 16 )
#define LSSYS_TILSDSDLYDTROXCHT_M_LNS         ( 16 )
#define LSSYS_TILSDSDLYDTROXCHT_M_COLS         ( 8 )
#define LSSYS_TILSDSDLYDTROXCHTPNT_M_COLS      ( 16 )
#define LSSYS_TILSDSTHDBOOSTPROTREQ_M_COLS     ( 6 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st70 */
#define LSDSMAINOXCHEAT_PHASE_A           0
#define LSDSMAINOXCHEAT_PHASE_B           1
#define LSDSMAINOXCHEAT_PHASE_C1          2
#define LSDSMAINOXCHEAT_PHASE_C2          3
#define LSDSMAINOXCHEAT_PHASE_D           4
#define LSDSMAINOXCHEAT_PHASE_E           5
#define LSDSMAINOXCHEAT_PHASE_F           6
#define LSDSMAINOXCHEAT_PHASE_G           7
/*extern uint8 LsSys_stLsDsMainOxCHeat;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  LsSys_bInhLsDsOxCNoPtOkLstStrt_C;
extern const boolean  LsSys_bInhLsDsOxCPtOkLstStrt_C;
extern const uint8  LsSys_tCoLsDsThdBoostProtReq_T[LSSYS_TCOLSDSTHDBOOSTPROTREQ_T_COLS];
extern const uint8  LsSys_tiLsDsDlyHeatHi_C;
extern const uint8  LsSys_tiLsDsThdBoostProtReq_M[LSSYS_TILSDSTHDBOOSTPROTREQ_M_COLS];
extern const uint16  LsSys_tiLsDsDlyDewTranNotOk_M[LSSYS_TILSDSDLYDEWTRANNOTOK_M_COLS];
extern const uint16  LsSys_tiLsDsDlyDewTranOkStall_T[LSSYS_TILSDSDLYDEWTRANOKSTALL_T_COLS];
extern const uint16  LsSys_tiLsDsDlyDTrIntrOxCHt_M[LSSYS_TILSDSDLYDTRINTROXCHT_M_LNS][LSSYS_TILSDSDLYDTRINTROXCHT_M_COLS];
extern const uint16  LsSys_tiLsDsDlyDTrIntrOxCHtPnt_M[LSSYS_TILSDSDLYDTRINTROXCHTPNT_M_COLS];
extern const uint16  LsSys_tiLsDsDlyDTrOxCHt_M[LSSYS_TILSDSDLYDTROXCHT_M_LNS][LSSYS_TILSDSDLYDTROXCHT_M_COLS];
extern const uint16  LsSys_tiLsDsDlyDTrOxCHtPnt_M[LSSYS_TILSDSDLYDTROXCHTPNT_M_COLS];
extern const uint16  LsSys_tiLsDsDlyWaitSecHeatHi_C;
extern const uint16  LsSys_tiLsDsMaxDlyHeatLo_C;
extern const uint16  LsSys_tiLsDsMaxDlyHeatModStop_C;
extern const uint16  LsSys_tiLsDsWaitSecBoost_C;
extern const uint16  LsSys_tiSumLsDsOxCHeatNullThd_C;
extern const uint16  LsSys_tMaxLsDsHeatBoostThd_C;
extern const uint16  LsSys_tMaxLsDsHeatHiThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 LsSys_stLsDsMainOxCHeat;
extern boolean LsSys_bAcvLsDsMainOxCHeatLih;
extern boolean LsSys_bLsDsMainOxCDewProtReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveCrTR_DsMgr(void);
void HeatSenO2_EveRst_DsMgr(void);
void HeatSenO2_EveRTSt_DsMgr(void);
void HeatSenO2_EveStTCr_DsMgr(void);
void HeatSenO2_SdlFast_DsMgr(void);
void HeatSenO2_SdlMid_DsMgr(void);


#endif /* HEATSENO2DS_H */

/*-------------------------------- end of file -------------------------------*/
