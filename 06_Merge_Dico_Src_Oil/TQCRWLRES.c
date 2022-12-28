/***************************************************************************
;**
;** FILE NAME      : TQCRWLRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQCRWLRES.H"
#include "TQCRWLRES_L.H"
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
const boolean  TqRes_bCfTqMaxCluDyn_C = 0;
const boolean  TqRes_bCfTqMaxCluStat_C = 0;
const boolean  TqRes_bCfTqReqCluDyn_C = 0;
const boolean  TqRes_bCfTqReqCluStat_C = 0;
const uint8  TQCRWLRES_u8Inhib = 0;
const uint8  TqRes_facCorTqCrwlResDyn_T[TQRES_FACCORTQCRWLRESDYN_T_COLS] = {0};
const uint8  TqRes_facCorTqCrwlResStat_T[TQRES_FACCORTQCRWLRESSTAT_T_COLS] = {0};
const uint8  TqRes_facFilTqMaxClu_C = 0;
const uint8  TqRes_facFilTqReqClu_C = 0;
const uint8  TqRes_spdVehCrwlRes_A[TQRES_SPDVEHCRWLRES_A_COLS] = {0};
const uint8  TqRes_tCo_A[TQRES_TCO_A_COLS] = {0};
const sint16  TqRes_tqDecMaxCrwlResDyn_C = 0;
const sint16  TqRes_tqDecMaxCrwlResStat_C = 0;
const uint16  TqRes_tqCrwlResDyn_M[TQRES_TQCRWLRESDYN_M_LNS][TQRES_TQCRWLRESDYN_M_COLS] = {0};
const uint16  TqRes_tqCrwlResStat_M[TQRES_TQCRWLRESSTAT_M_LNS][TQRES_TQCRWLRESSTAT_M_COLS] = {0};
const uint16  TqRes_tqIncMaxCrwlResDyn_C = 0;
const uint16  TqRes_tqIncMaxCrwlResStat_C = 0;
const uint16  TqRes_tqMaxClu_A[TQRES_TQMAXCLU_A_COLS] = {0};
const uint16  TqRes_tqMaxClu_T[TQRES_TQMAXCLU_T_COLS] = {0};
const uint16  TqRes_tqReqClu_A[TQRES_TQREQCLU_A_COLS] = {0};
const uint16  TqRes_tqReqClu_T[TQRES_TQREQCLU_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQCRWLRES_bCPtAcvDyTqResCrwlPrev;
boolean TQCRWLRES_bCPtAcvStTqResCrwlPrev;
uint32 TQCRWLRES_u32Filtre1Mem;
uint32 TQCRWLRES_u32Filtre2Mem;
sint16 TqRes_tqCrwlResDyn;
sint16 TqRes_tqCrwlResDynNoSat_MP;
sint16 TqRes_tqCrwlResSat_MP;
sint16 TqRes_tqCrwlResStat;
sint16 TqRes_tqCrwlResStatNoSat_MP;
sint16 TqRes_tqMaxClu;
sint16 TqRes_tqReqClu;
uint16 TqRes_tqCrwlRes;
uint16 TqRes_tqCrwlResPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

