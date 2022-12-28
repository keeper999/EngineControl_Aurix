/***************************************************************************
;**
;** FILE NAME      : ENGIDLEINTERFACE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGIDLEINTERFACE.H"
#include "ENGIDLEINTERFACE_L.H"
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
const boolean  IdlSys_bTqMinSel_C = 0;
const uint8  ENGIDLEINTERFACE_u8Inhib = 0;
const sint16  IdlSys_tqSatIdlMin_C = 0;
const uint16  IdlSys_tqOfsIdlMax_C = 0;
const uint16  IdlSys_tqOfsIdlMin_C = 0;
const uint16  IdlSys_tqSatIdlMax_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IdlSys_bAcvStrtTqSys;
uint8 IdlSys_idxIdlCtlMod;
sint16 IdlSys_tqIdcIdlMax;
sint16 IdlSys_tqIdcIdlMin;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

