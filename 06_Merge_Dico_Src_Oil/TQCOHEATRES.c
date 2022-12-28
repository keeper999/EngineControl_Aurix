/***************************************************************************
;**
;** FILE NAME      : TQCOHEATRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQCOHEATRES.H"
#include "TQCOHEATRES_L.H"
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
const boolean  TqRes_bAcvCoHeatRes_C = 0;
const uint8  TQCOHEATRES_u8Inhib = 0;
const uint8  TqRes_facCorCoHeatRes_M[TQRES_FACCORCOHEATRES_M_LNS][TQRES_FACCORCOHEATRES_M_COLS] = {0};
const sint16  TqRes_tqDecMaxCoHeatRes_C = 0;
const uint16  TqRes_nEngCoHeatRes_A[TQRES_NENGCOHEATRES_A_COLS] = {0};
const uint16  TqRes_tqCkEngCoHeatRes_A[TQRES_TQCKENGCOHEATRES_A_COLS] = {0};
const uint16  TqRes_tqCoHeatRes_M[TQRES_TQCOHEATRES_M_LNS][TQRES_TQCOHEATRES_M_COLS] = {0};
const uint16  TqRes_tqIncMaxCoHeatRes_C = 0;
const uint16  TqRes_tqMaxCoHeatRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint16 TQCOHEATRES_u16RateLimterOut;
uint16 TqRes_tqCoHeatRes;
uint16 TqRes_tqCoHeatResMax_MP;
uint16 TqRes_tqCoHeatResNotSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

