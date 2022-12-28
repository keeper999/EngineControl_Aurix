/***************************************************************************
;**
;** FILE NAME      : TQENGRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQENGRES.H"
#include "TQENGRES_L.H"
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
const boolean  TqRes_bCfEfcIvsBasRes_C = 0;
const boolean  TqRes_bDeacAntRes_C = 0;
const boolean  TqRes_bTqLossBfIdlAcv_C = 0;
const sint8  TqRes_rAccPThdAcvAntDyn_C = 0;
const uint8  TQENGRES_u8Inhib = 0;
const uint8  TqRes_ctIncCdnResDyn_C = 0;
const uint8  TqRes_ctThdHiCdnResDyn_C = 0;
const uint8  TqRes_ctThdLoCdnResDyn_C = 0;
const uint8  TqRes_facNoGearTqAntRes_T[TQRES_FACNOGEARTQANTRES_T_COLS] = {0};
const uint8  TqRes_noSelAntRes_C = 0;
const uint8  TqRes_rEfcIvsBasRes_M[TQRES_REFCIVSBASRES_M_LNS][TQRES_REFCIVSBASRES_M_COLS] = {0};
const uint8  TqRes_rMaxBasRes_C = 0;
const uint8  TqRes_tAir_A[TQRES_TAIR_A_COLS] = {0};
const uint8  TqRes_tqTqLoss_A[TQRES_TQTQLOSS_A_COLS] = {0};
const sint16  TqRes_ctDecCdnResDyn_C = 0;
const sint16  TqRes_nOfsAcvAntRes_T[TQRES_NOFSACVANTRES_T_COLS] = {0};
const sint16  TqRes_nThdDeacAntRes_C = 0;
const sint16  TqRes_tqDecMaxFastIdlResDyn_C = 0;
const sint16  TqRes_tqDecMaxIdlResStat_C = 0;
const sint16  TqRes_tqDecMaxSlowIdlResDyn_C = 0;
const uint16  TqRes_facFilDecTqAntIdlRes_C = 0;
const uint16  TqRes_facFilIncTqAntIdlRes_C = 0;
const uint16  TqRes_nEngBasRes_A[TQRES_NENGBASRES_A_COLS] = {0};
const uint16  TqRes_rAirLdBasRes_A[TQRES_RAIRLDBASRES_A_COLS] = {0};
const uint16  TqRes_rIgEfcOfsIdlResDyn_C = 0;
const uint16  TqRes_tqDeltaTqStabLoss_A[TQRES_TQDELTATQSTABLOSS_A_COLS] = {0};
const uint16  TqRes_tqDftValIdlResStat_C = 0;
const uint16  TqRes_tqDynMaxIdlRes_C = 0;
const uint16  TqRes_tqIdlAntRes_M[TQRES_TQIDLANTRES_M_LNS][TQRES_TQIDLANTRES_M_COLS] = {0};
const uint16  TqRes_tqIdlResStat_M[TQRES_TQIDLRESSTAT_M_LNS][TQRES_TQIDLRESSTAT_M_COLS] = {0};
const uint16  TqRes_tqIdlResStat_T[TQRES_TQIDLRESSTAT_T_COLS] = {0};
const uint16  TqRes_tqIncMaxIdlResDyn_C = 0;
const uint16  TqRes_tqIncMaxIdlResStat_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQENGRES_bNegHysOut;
boolean TqRes_bAcvAntIdl;
boolean TqRes_bCdnIdlResDyn;
uint32 TQENGRES_u32FiltredResAntIdlMem;
uint8 TQENGRES_u8ctCdnResDyn_MP_Prev;
uint8 TqRes_ctCdnResDyn_MP;
uint16 TQENGRES_u16TqDeltaTqStabLoss;
uint16 TqRes_rBasRes;
uint16 TqRes_rBasResNotSat_MP;
uint16 TqRes_tqAntIdl;
uint16 TqRes_tqAntIdlRaw;
uint16 TqRes_tqIdlRes;
uint16 TqRes_tqIdlResDyn_MP;
uint16 TqRes_tqIdlResStat_MP;
uint16 TqRes_tqIdlResStatTAir_MP;
uint16 TqRes_tqIdlResStatTCo_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

