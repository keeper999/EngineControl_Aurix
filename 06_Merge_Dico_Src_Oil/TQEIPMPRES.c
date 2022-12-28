/***************************************************************************
;**
;** FILE NAME      : TQEIPMPRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQEIPMPRES.H"
#include "TQEIPMPRES_L.H"
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
const boolean  TqRes_bAcvElPmpGrpRes_C = 0;
const uint8  TQEIPMPRES_u8Inhib = 0;
const uint8  TqRes_spdThrElPmpGrpRes_C = 0;
const uint8  TqRes_tiCdnElPmpGrpRes_C = 0;
const sint16  TqRes_tqDecMaxElPmpGrpRes_C = 0;
const uint16  TqRes_tqElPmpGrpRes_C = 0;
const uint16  TqRes_tqIncMaxElPmpGrpRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bStHaltElPmpGrp_Prev;
boolean TQEIPMPRES_bCdnElPmpResMPPrev;
boolean TqRes_bCdnElPmpRes_MP;
boolean TqRes_bCdnSpdElPmpGrpRes_MP;
boolean TqRes_bCdnStElPmpGrpRes_MP;
uint16 TQEIPMPRES_u16ElPmpGrpTempo;
uint16 TqRes_tqElPmpGrpRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

