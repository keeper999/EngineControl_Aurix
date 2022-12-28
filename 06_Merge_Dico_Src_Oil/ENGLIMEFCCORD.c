/***************************************************************************
;**
;** FILE NAME      : ENGLIMEFCCORD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGLIMEFCCORD.H"
#include "ENGLIMEFCCORD_L.H"
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
const boolean  EngLim_bLimDynSel_C = 0;
const boolean  EngLim_bProtDfltChaSel_C = 0;
const boolean  EngLim_bProtDfltModSptSel_C = 0;
const boolean  EngLim_bSmkLimDrivFil_C = 0;
const uint8  EngLim_idxChaLim_C = 0;
const uint8  EngLim_idxCoPtLim_C = 0;
const uint8  EngLim_idxCoPtLimAT_C = 0;
const uint8  EngLim_idxModSptLim_C = 0;
const uint8  ENGLIMEFCCORD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
sint16 EngLim_tqCkEfcModSptLim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

