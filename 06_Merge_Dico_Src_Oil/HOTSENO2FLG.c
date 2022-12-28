/***************************************************************************
;**
;** FILE NAME      : HOTSENO2FLG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "HOTSENO2FLG.H"
#include "HOTSENO2FLG_L.H"
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
const uint8  HOTSENO2FLG_u8Inhib = 0;
const uint8  Lshd_sensor_voltage_filter_gain = 0;
const uint8  LsSys_tiLsDsDlyHeatNotOk_C = 0;
const uint8  LsSys_tiLsDsDlyHeatOkColdStrt_C = 0;
const uint8  LsSys_tiLsDsDlyHeatOkHotStrt_C = 0;
const uint8  LsSys_tiLsUsDlyHeatNotOk_C = 0;
const uint8  LsSys_tiLsUsDlyHeatOkColdStrt_C = 0;
const uint8  LsSys_tiLsUsDlyHeatOkHotStrt_C = 0;
const uint16  Lshd_dwn_lbda_sens_heat_delay = 0;
const uint16  Lshd_dwnstr_volt_high_limit = 0;
const uint16  Lshd_dwnstr_volt_high_thresh = 0;
const uint16  Lshd_dwnstr_volt_low_limit = 0;
const uint16  Lshd_dwnstr_volt_low_thresh = 0;
const uint16  Lshd_up_lbda_sens_heat_delay = 0;
const uint16  Lshd_upstr_volt_high_limit = 0;
const uint16  Lshd_upstr_volt_high_thresh = 0;
const uint16  Lshd_upstr_volt_low_limit = 0;
const uint16  Lshd_upstr_volt_low_thresh = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean HOTSENO2FLG_bInitTimer1Prev;
boolean HOTSENO2FLG_bInitTimer2Prev;
boolean HOTSENO2FLG_bInitTimer3Prev;
boolean HOTSENO2FLG_bInitTimer4Prev;
boolean Lshd_dnstr_lbda_sens_hot_prv;
boolean Lshd_down_stream_lbda_sensor_hot;
boolean Lshd_up_stream_lbda_sensor_hot;
boolean LsSys_bLsDsHeatOk;
boolean LsSys_bLsDsMainOxCHeatOkdiag;
boolean LsSys_bLsUsHeatOk;
boolean LsSys_bLsUsMainOxCHeatOk;
boolean LsSys_bLsUsMainOxCHeatOkdiag;
uint32 HOTSENO2FLG_u32VoltageDsFiltMem;
uint32 HOTSENO2FLG_u32VoltageUsFiltMem;
uint8 HOTSENO2FLG_u8DsMainOxCHeatPrev;
uint8 HOTSENO2FLG_u8UsMainOxCHeatPrev;
uint16 Lshd_dwn_lbda_sens_heat_count;
uint16 Lshd_up_lbda_sens_heat_count;
uint16 Lshd_voltage_dnstr_sens_filtered;
uint16 Lshd_voltage_upstr_sens_filtered;
uint16 LsSys_tiLsDsDlyHeat;
uint16 LsSys_tiLsUsDlyHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

