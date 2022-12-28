/***************************************************************************
;**
;** FILE NAME      : VEHST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VEHST.H"
#include "VEHST_L.H"
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
const boolean  Manu_inh_run_to_crank = 0;
const uint8  Crank_exit_delay = 0;
const uint8  Crank_to_run_engine_rpm_high_map[CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_LNS][CRANK_TO_RUN_ENGINE_RPM_HIGH_MAP_COLS] = {0};
const uint8  Crank_to_run_engine_rpm_low_map[CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_LNS][CRANK_TO_RUN_ENGINE_RPM_LOW_MAP_COLS] = {0};
const uint8  Demarrage_en_cours_delay = 0;
const uint8  VEHST_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Vehicle_active_state;
boolean EngSt_CrkIp;
boolean Ext_bAcvInjSys;
uint8 Crank_to_run_engine_rpm_high;
uint8 Crank_to_run_engine_rpm_low;
uint8 Demarrage_en_cours_counter;
uint16 Initial_vs_crank_tdc_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

