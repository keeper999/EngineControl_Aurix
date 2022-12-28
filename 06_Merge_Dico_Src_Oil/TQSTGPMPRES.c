/***************************************************************************
;**
;** FILE NAME      : TQSTGPMPRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQSTGPMPRES.H"
#include "TQSTGPMPRES_L.H"
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
const boolean  TqRes_bAcvCdnAgStgPmpRes_C = 0;
const boolean  TqRes_bAcvStgPmpRes_C = 0;
const uint8  TqRes_agvStrWhl_A[TQRES_AGVSTRWHL_A_COLS] = {0};
const uint8  TqRes_facFilAgStgPmpRes_C = 0;
const uint8  TqRes_facFilAvgStgPmpRes_C = 0;
const uint8  TqRes_spdThrStgPmpRes_C = 0;
const uint8  TqRes_spdVehStgPmpRes_A[TQRES_SPDVEHSTGPMPRES_A_COLS] = {0};
const uint8  TqRes_tiCdnStgPmpStgPmpRes_C = 0;
const uint8  TqRes_tiCdnStrWhlStgPmpRes_C = 0;
const uint8  TQSTGPMPRES_u8Inhib = 0;
const sint16  TqRes_tCoThrStgPmpRes_C = 0;
const sint16  TqRes_tqDecMaxStgPmpRes_C = 0;
const uint16  TqRes_agStrWhlThr_T[TQRES_AGSTRWHLTHR_T_COLS] = {0};
const uint16  TqRes_nEngStgPmpRes_A[TQRES_NENGSTGPMPRES_A_COLS] = {0};
const uint16  TqRes_pStgPmpThrStgPmpRes_C = 0;
const uint16  TqRes_tiThrEngRunStgPmpRes_C = 0;
const uint16  TqRes_tqIncMaxStgPmpRes_C = 0;
const uint16  TqRes_tqStgPmpRes_M[TQRES_TQSTGPMPRES_M_LNS][TQRES_TQSTGPMPRES_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TqRes_bCdnAgWhlStgPmpRes;
boolean TqRes_bCdnEngRunStgPmpRes_MP;
boolean TqRes_bCdnSpdStgPmpRes_MP;
boolean TqRes_bCdnStgPmpRes;
boolean TqRes_bCdnStgPmpStgPmpRes;
boolean TqRes_bCdnTCoStgPmpRes_MP;
boolean TQSTGPMPRES_bRateLimiterPrevEna;
boolean TQSTGPMPRES_bTurnOffDelayIn;
boolean TQSTGPMPRES_bTurnOffDelayInPrev;
uint32 TQSTGPMPRES_u32FiltredCoefFilMem;
uint8 TqRes_agvStrWhlFilStgPmpRes_MP;
sint16 TqRes_agStrWhlFilStgPmpRes_MP;
uint16 TqRes_tqStgPmpRes;
uint16 TqRes_tqStgPmpResMax_MP;
uint16 TqRes_tqStgPmpResSat_MP;
uint16 TQSTGPMPRES_u16tiStgPmpThrCpt;
uint16 TQSTGPMPRES_u16tiStgPmpThrCpt1;
sint32 TQSTGPMPRES_s32FiltredCoefFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

