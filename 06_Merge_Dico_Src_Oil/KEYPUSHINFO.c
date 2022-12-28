/***************************************************************************
;**
;** FILE NAME      : KEYPUSHINFO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KEYPUSHINFO.H"
#include "KEYPUSHINFO_L.H"
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
const boolean  Ext_bInvDemLine_C = 0;
const uint8  Ext_ctSdlStp_C = 0;
const uint8  Ext_numDebHighKeyLine_C = 0;
const uint8  Ext_numDebHighPushLine_C = 0;
const uint8  Ext_numDebLowKeyLine_C = 0;
const uint8  Ext_numDebLowPushLine_C = 0;
const uint8  KEYPUSHINFO_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDemLineRaw;
boolean Ext_bKeyLine;
boolean Ext_bPushLine;
uint8 Ext_ctSdl;
uint8 KEYPUSHINFO_u8AntiBounceCntKey;
uint8 KEYPUSHINFO_u8AntiBounceCntPush;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

