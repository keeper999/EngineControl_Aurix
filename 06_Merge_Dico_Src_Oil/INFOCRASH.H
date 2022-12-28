/***************************************************************************
;**
;** FILE NAME      : INFOCRASH.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INFOCRASH_H
#define INFOCRASH_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const boolean  Manu_Inh_info_crash;
extern const uint8  Step_dec_crash_counter;
extern const uint8  Step_inc_crash_counter;
extern const uint8  Thd_crash_absent;
extern const uint8  Thd_crash_confirmed;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Crash_fps_confirmed;
extern boolean Crash_fps_detected;
extern boolean Ext_bVehCollWarnFil;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RlyPwr_EveRst_CrashVeh(void);
void RlyPwr_EveRxn4c8_CrashVeh(void);
void RlyPwr_SdlFast_CrashVeh(void);


#endif /* INFOCRASH_H */

/*-------------------------------- end of file -------------------------------*/
