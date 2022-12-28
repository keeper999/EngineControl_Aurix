/***************************************************************************
;**
;** FILE NAME      : ACQCOT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACQCOT.H"
#include "ACQCOT_L.H"
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
const uint8  ACQCOT_u8Inhib = 0;
const uint8  Cts_default_coolant_temp = 0;
const uint8  Cts_global_failure_default_temp = 0;
const uint8  Temp_eau_grad_thresh = 0;
const uint8  Temperature_eau_bkpt_map[TEMPERATURE_EAU_BKPT_MAP_COLS] = {0};
const sint16  Ext_tCoMesPwrl_C = 0;
const uint16  Cts_oc_failure_thresh = 0;
const uint16  Cts_range_conv_bkpt_map[CTS_RANGE_CONV_BKPT_MAP_COLS] = {0};
const uint16  Cts_range_conv_map[CTS_RANGE_CONV_MAP_COLS] = {0};
const uint16  Cts_sc0_failure_thresh = 0;
const uint16  Cts_sc1_failure_thresh = 0;
const uint16  Temp_eau_diag_grad_delay = 0;
const uint16  Temperature_eau_mode_defaut_step = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACQCOT_bExtbDgoOctCoMesPrev;
boolean ACQCOT_bExtbDgoScgtCoMesPrev;
boolean ACQCOT_bExtbDgoScptCoMesPrev;
boolean Autorise_diag_grad;
boolean Ext_bDgoGrd_tCoMes;
boolean Ext_bDgoOc_tCoMes;
boolean Ext_bDgoScg_tCoMes;
boolean Ext_bDgoScp_tCoMes;
boolean Ext_bMonRunGrd_tCoMes;
boolean Ext_bMonRunOc_tCoMes;
boolean Ext_bMonRunScg_tCoMes;
boolean Ext_bMonRunScp_tCoMes;
uint8 ACQCOT_u8TempEauMesureePrev;
uint8 Crank_to_run_water_temp;
uint8 Temperature_eau_a_stall;
uint8 Temperature_eau_mesuree;
uint8 Temperature_eau_mesuree_delta;
sint16 Ext_tCoMesFineResl;
uint16 Cts_range_voltage;
uint16 Cts_raw_range_temp;
uint16 Temp_eau_diag_grad_count;
uint16 Temperature_eau_mode_defaut;
uint16 Temperature_eau_precise;
uint16 Temperature_eau_precise_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

