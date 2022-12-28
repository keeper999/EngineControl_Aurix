/***************************************************************************
;**
;** FILE NAME      : INFOCRASH.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INFOCRASH.H"
#include "INFOCRASH_L.H"
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
const boolean  Manu_Inh_info_crash = 0;
const uint8  INFOCRASH_u8Inhib = 0;
const uint8  Step_dec_crash_counter = 0;
const uint8  Step_inc_crash_counter = 0;
const uint8  Thd_crash_absent = 0;
const uint8  Thd_crash_confirmed = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Crash_fps_confirmed;
boolean Crash_fps_detected;
boolean Ext_bDgoDft_Info_Crash;
boolean Ext_bMonRunDft_Info_Crash;
boolean Ext_bVehCollWarnFil;
boolean INFOCRASH_bCrashMuxPrev;
uint8 Confirm_crash_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

