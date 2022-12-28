/***************************************************************************
;**
;** FILE NAME      : TQCRWLRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCRWLRES_H
#define TQCRWLRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_FACCORTQCRWLRESDYN_T_COLS        ( 8 )
#define TQRES_FACCORTQCRWLRESSTAT_T_COLS       ( 8 )
#define TQRES_SPDVEHCRWLRES_A_COLS             ( 8 )
#define TQRES_TCO_A_COLS                       ( 8 )
#define TQRES_TQCRWLRESDYN_M_LNS              ( 8 )
#define TQRES_TQCRWLRESDYN_M_COLS              ( 8 )
#define TQRES_TQCRWLRESSTAT_M_LNS             ( 8 )
#define TQRES_TQCRWLRESSTAT_M_COLS             ( 8 )
#define TQRES_TQMAXCLU_A_COLS                  ( 8 )
#define TQRES_TQMAXCLU_T_COLS                  ( 8 )
#define TQRES_TQREQCLU_A_COLS                  ( 8 )
#define TQRES_TQREQCLU_T_COLS                  ( 8 )

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

extern const boolean  TqRes_bCfTqMaxCluDyn_C;
extern const boolean  TqRes_bCfTqMaxCluStat_C;
extern const boolean  TqRes_bCfTqReqCluDyn_C;
extern const boolean  TqRes_bCfTqReqCluStat_C;
extern const uint8  TqRes_facCorTqCrwlResDyn_T[TQRES_FACCORTQCRWLRESDYN_T_COLS];
extern const uint8  TqRes_facCorTqCrwlResStat_T[TQRES_FACCORTQCRWLRESSTAT_T_COLS];
extern const uint8  TqRes_facFilTqMaxClu_C;
extern const uint8  TqRes_facFilTqReqClu_C;
extern const uint8  TqRes_spdVehCrwlRes_A[TQRES_SPDVEHCRWLRES_A_COLS];
extern const uint8  TqRes_tCo_A[TQRES_TCO_A_COLS];
extern const sint16  TqRes_tqDecMaxCrwlResDyn_C;
extern const sint16  TqRes_tqDecMaxCrwlResStat_C;
extern const uint16  TqRes_tqCrwlResDyn_M[TQRES_TQCRWLRESDYN_M_LNS][TQRES_TQCRWLRESDYN_M_COLS];
extern const uint16  TqRes_tqCrwlResStat_M[TQRES_TQCRWLRESSTAT_M_LNS][TQRES_TQCRWLRESSTAT_M_COLS];
extern const uint16  TqRes_tqIncMaxCrwlResDyn_C;
extern const uint16  TqRes_tqIncMaxCrwlResStat_C;
extern const uint16  TqRes_tqMaxClu_A[TQRES_TQMAXCLU_A_COLS];
extern const uint16  TqRes_tqMaxClu_T[TQRES_TQMAXCLU_T_COLS];
extern const uint16  TqRes_tqReqClu_A[TQRES_TQREQCLU_A_COLS];
extern const uint16  TqRes_tqReqClu_T[TQRES_TQREQCLU_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqCrwlRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCRWLRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqCrawlRes(void);


#endif /* TQCRWLRES_H */

/*-------------------------------- end of file -------------------------------*/
