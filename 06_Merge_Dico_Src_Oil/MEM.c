/***************************************************************************
;**
;** FILE NAME      : MEM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "MEM_Macro.h"
#include "NVMSRV.h"
#include "MEM.H"
#include "MEM_L.H"
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
const uint32  GD_NoDTC_C[GD_NODTC_C_LNS] = {0};
const uint8  MEM_AllowEepSave = 0;
const uint8  MEM_u8Inhib = 0;
const uint16  GD_DID_dstAbsKm_C = 0;
const uint16  GD_DID_nEng_C = 0;
const uint16  GD_DID_rAccP_C = 0;
const uint16  GD_DID_spdVeh_C = 0;
const uint16  GD_DID_tCoMes_C = 0;
const uint16  GD_DID_tiCurVehTmr_C = 0;
const uint16  GD_DID_uBattMes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint32 GD_NoDTC[GD_NODTC_LNS];
uint16 GD_DID_dstAbsKm;
uint16 GD_DID_nEng;
uint16 GD_DID_rAccP;
uint16 GD_DID_spdVeh;
uint16 GD_DID_tCoMes;
uint16 GD_DID_tiCurVehTmr;
uint16 GD_DID_uBattMes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

