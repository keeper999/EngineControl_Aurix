/***************************************************************************
;**
;** FILE NAME      : MUXTQREQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MUXTQREQ.H"
#include "MUXTQREQ_L.H"
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
const uint8  MUXTQREQ_u8Inhib = 0;
const sint16  Ext_nEngSpdLimHiOfs_C = 0;
const sint16  Ext_nEngSpdLimLoOfs_C = 0;
const sint16  Ext_tqLimOfs_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 REOM_stEngOpm;
boolean Ext_bCdnEngSpdLimHiEfc;
boolean Ext_bCdnEngSpdLimLoEfc;
boolean Ext_bCdnTqLimEfc;
boolean MUXTQREQ_bHysEngHi;
boolean MUXTQREQ_bHysEngLo;
boolean MUXTQREQ_bHysTqLimEfc;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

