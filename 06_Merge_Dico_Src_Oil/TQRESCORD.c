/***************************************************************************
;**
;** FILE NAME      : TQRESCORD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQRESCORD.H"
#include "TQRESCORD_L.H"
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
const uint8  TQRESCORD_u8Inhib = 0;
const sint16  TqRes_tqDecMaxCanPurgRes_C = 0;
const uint16  TqRes_idxTqResAcvCll_C = 0;
const uint16  TqRes_tiValTranCll_C = 0;
const uint16  TqRes_tqIncMaxCanPurgRes_C = 0;
const uint16  TqRes_tqSatMaxRes_C = 0;
const uint16  TqRes_tqThrHiMaxRes_C = 0;
const uint16  TqRes_tqThrLoMaxRes_C = 0;
const uint16  TqRes_tqValIncCll_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
sint16 TqRes_tqMaxResnoSat;
uint16 TqRes_tqAirCmp;
uint16 TqRes_tqCanPurgRes;
uint16 TqRes_tqMaxResNotSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

