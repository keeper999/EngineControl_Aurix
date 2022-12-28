/***************************************************************************
;**
;** FILE NAME      : THRCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRCMD.H"
#include "THRCMD_L.H"
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
const boolean  ThrCmd_bForcFreeWheeling_C = 0;
const boolean  Tpac_thr_servoing_typ_select = 0;
const uint32  Tpc_free_wheeling_delay = 0;
const uint8  THRCMD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bDgoCpt_ThrCmd;
boolean Thr_bDgoOvld_ThrCmd;
boolean Thr_bMonRunCpt_ThrCmd;
boolean Thr_bMonRunOvld_ThrCmd;
boolean Tpc_throt_on_off_request;
uint32 Delai_freewheeling_bpm;
uint32 ThrCmd_tiFreeWheeling;
sint16 Tpac_throt_duty_cycle_to_apply;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

