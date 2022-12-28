/***************************************************************************
;**
;** FILE NAME      : TQLNCHRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQLNCHRES.H"
#include "TQLNCHRES_L.H"
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
const boolean  TqRes_bAcvCdnAccLnchRes_C = 0;
const boolean  TqRes_bAcvCdnCluLnchRes_C = 0;
const boolean  TqRes_bAcvCdnSpdLnchRes_C = 0;
const boolean  TqRes_bCfCluLnchRes_C = 0;
const uint8  TQLNCHRES_u8Inhib = 0;
const uint8  TqRes_rAccThrLnchRes_C = 0;
const uint8  TqRes_rCluThrLnchRes_C = 0;
const uint8  TqRes_spdThrHiLnchRes_C = 0;
const uint8  TqRes_spdThrLoLnchRes_C = 0;
const uint8  TqRes_tiCdnCluLnchRes_C = 0;
const uint8  TqRes_tiCdnNEngLnchRes_C = 0;
const uint8  TqRes_tiCdnSpdLnchRes_C = 0;
const sint16  TqRes_tqDecMaxLnchRes_C = 0;
const uint16  TqRes_nEngOfsLnchRes_C = 0;
const uint16  TqRes_tqCkEfc_A[TQRES_TQCKEFC_A_COLS] = {0};
const uint16  TqRes_tqIncMaxLnchRes_C = 0;
const uint16  TqRes_tqLnchRes_M[TQRES_TQLNCHRES_M_LNS][TQRES_TQLNCHRES_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TQLNCHRES_bCdnCluLnchResInPrev;
boolean TQLNCHRES_bCdnExtrCluPPrev;
boolean TQLNCHRES_bCdnNEngLnchResInPrev;
boolean TQLNCHRES_bCdnSpdLnchResInPrev;
boolean TQLNCHRES_bRateLimiterSwitchPrev;
boolean TqRes_bCdnAccLnchRes_MP;
boolean TqRes_bCdnCluLnchRes_MP;
boolean TqRes_bCdnLnchRes;
boolean TqRes_bCdnNEngLnchRes_MP;
boolean TqRes_bCdnSpdLnchRes;
boolean TqRes_bCdnSpdLnchRes_MP;
uint16 TQLNCHRES_u16tiCluTempo;
uint16 TQLNCHRES_u16tiLoCkSpdTempo;
uint16 TQLNCHRES_u16tiSpdVehTempo;
uint16 TqRes_tqLnchRes;
uint16 TqRes_tqLnchResMax_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

