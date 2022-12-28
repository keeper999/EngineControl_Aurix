/***************************************************************************
;**
;** FILE NAME      : ACQAIRT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACQAIRT.H"
#include "ACQAIRT_L.H"
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
const uint8  ACQAIRT_u8Inhib = 0;
const uint8  Temp_air_diag_grad_delay = 0;
const uint8  Temp_air_grad_thresh = 0;
const uint8  Temp_air_par_defaut = 0;
const uint8  Temperature_air_slew_rate = 0;
const uint16  Table_temperature_air_linearisee[TABLE_TEMPERATURE_AIR_LINEARISEE_COLS] = {0};
const uint16  Temp_air_result_ad_conv_bkpt_map[TEMP_AIR_RESULT_AD_CONV_BKPT_MAP_COLS] = {0};
const uint16  Tension_air_seuil_cc0 = 0;
const uint16  Tension_air_seuil_cc1 = 0;
const uint16  Tension_air_seuil_co = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACQAIRT_bExtbDgoOctAirMesPrev;
boolean ACQAIRT_bExtbDgoScgtAirMesPrev;
boolean ACQAIRT_bExtbDgoScptAirMesPrev;
boolean Autorise_diag_grad_air;
boolean Ext_bDgoGrd_tAirMes;
boolean Ext_bDgoOc_tAirMes;
boolean Ext_bDgoScg_tAirMes;
boolean Ext_bDgoScp_tAirMes;
boolean Ext_bMonRunGrd_tAirMes;
boolean Ext_bMonRunOc_tAirMes;
boolean Ext_bMonRunScg_tAirMes;
boolean Ext_bMonRunScp_tAirMes;
uint8 Temp_air_diag_grad_count;
uint8 Temperature_air_mesuree;
uint8 Temperature_air_mesuree_delta;
uint8 Temperature_air_mesuree_prev;
sint16 Ext_tDsThrStrtMes;
uint16 Tair_raw_range_voltage;
uint16 Temperature_air_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

