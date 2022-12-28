/***************************************************************************
;**
;** FILE NAME      : TQENGRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQENGRES_H
#define TQENGRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_FACNOGEARTQANTRES_T_COLS         ( 4 )
#define TQRES_NENGBASRES_A_COLS                ( 12 )
#define TQRES_NOFSACVANTRES_T_COLS             ( 4 )
#define TQRES_RAIRLDBASRES_A_COLS              ( 12 )
#define TQRES_REFCIVSBASRES_M_LNS             ( 12 )
#define TQRES_REFCIVSBASRES_M_COLS             ( 12 )
#define TQRES_TAIR_A_COLS                      ( 8 )
#define TQRES_TQDELTATQSTABLOSS_A_COLS         ( 12 )
#define TQRES_TQIDLANTRES_M_LNS               ( 12 )
#define TQRES_TQIDLANTRES_M_COLS               ( 12 )
#define TQRES_TQIDLRESSTAT_M_LNS              ( 8 )
#define TQRES_TQIDLRESSTAT_M_COLS              ( 8 )
#define TQRES_TQIDLRESSTAT_T_COLS              ( 8 )
#define TQRES_TQTQLOSS_A_COLS                  ( 12 )

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

extern const boolean  TqRes_bCfEfcIvsBasRes_C;
extern const boolean  TqRes_bDeacAntRes_C;
extern const boolean  TqRes_bTqLossBfIdlAcv_C;
extern const sint8  TqRes_rAccPThdAcvAntDyn_C;
extern const uint8  TqRes_ctIncCdnResDyn_C;
extern const uint8  TqRes_ctThdHiCdnResDyn_C;
extern const uint8  TqRes_ctThdLoCdnResDyn_C;
extern const uint8  TqRes_facNoGearTqAntRes_T[TQRES_FACNOGEARTQANTRES_T_COLS];
extern const uint8  TqRes_noSelAntRes_C;
extern const uint8  TqRes_rEfcIvsBasRes_M[TQRES_REFCIVSBASRES_M_LNS][TQRES_REFCIVSBASRES_M_COLS];
extern const uint8  TqRes_rMaxBasRes_C;
extern const uint8  TqRes_tAir_A[TQRES_TAIR_A_COLS];
extern const uint8  TqRes_tqTqLoss_A[TQRES_TQTQLOSS_A_COLS];
extern const sint16  TqRes_ctDecCdnResDyn_C;
extern const sint16  TqRes_nOfsAcvAntRes_T[TQRES_NOFSACVANTRES_T_COLS];
extern const sint16  TqRes_nThdDeacAntRes_C;
extern const sint16  TqRes_tqDecMaxFastIdlResDyn_C;
extern const sint16  TqRes_tqDecMaxIdlResStat_C;
extern const sint16  TqRes_tqDecMaxSlowIdlResDyn_C;
extern const uint16  TqRes_facFilDecTqAntIdlRes_C;
extern const uint16  TqRes_facFilIncTqAntIdlRes_C;
extern const uint16  TqRes_nEngBasRes_A[TQRES_NENGBASRES_A_COLS];
extern const uint16  TqRes_rAirLdBasRes_A[TQRES_RAIRLDBASRES_A_COLS];
extern const uint16  TqRes_rIgEfcOfsIdlResDyn_C;
extern const uint16  TqRes_tqDeltaTqStabLoss_A[TQRES_TQDELTATQSTABLOSS_A_COLS];
extern const uint16  TqRes_tqDftValIdlResStat_C;
extern const uint16  TqRes_tqDynMaxIdlRes_C;
extern const uint16  TqRes_tqIdlAntRes_M[TQRES_TQIDLANTRES_M_LNS][TQRES_TQIDLANTRES_M_COLS];
extern const uint16  TqRes_tqIdlResStat_M[TQRES_TQIDLRESSTAT_M_LNS][TQRES_TQIDLRESSTAT_M_COLS];
extern const uint16  TqRes_tqIdlResStat_T[TQRES_TQIDLRESSTAT_T_COLS];
extern const uint16  TqRes_tqIncMaxIdlResDyn_C;
extern const uint16  TqRes_tqIncMaxIdlResStat_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_rBasRes;
extern uint16 TqRes_tqIdlRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQENGRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqIdlRes(void);


#endif /* TQENGRES_H */

/*-------------------------------- end of file -------------------------------*/
