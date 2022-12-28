/***************************************************************************
;**
;** FILE NAME      : THRBENCHAUT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRBENCHAUT.H"
#include "THRBENCHAUT_L.H"
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
const boolean  Dtc_throttle_test_bed_mode = 0;
const boolean  Tpac_dyn_test_bed_mode = 0;
const boolean  Tpac_dyn_test_bed_sinus_mode = 0;
const boolean  Tpac_dyn_test_bed_type_ref_map[TPAC_DYN_TEST_BED_TYPE_REF_MAP_COLS] = {0};
const uint8  THRBENCHAUT_u8Inhib = 0;
const uint8  Tpac_dyn_test_bed_offset_map[TPAC_DYN_TEST_BED_OFFSET_MAP_COLS] = {0};
const uint8  Tpac_dyn_test_bed_pattern_number = 0;
const uint8  Tpac_sin_freq_map[TPAC_SIN_FREQ_MAP_COLS] = {0};
const uint8  Tpac_sin_period_count_map[TPAC_SIN_PERIOD_COUNT_MAP_COLS] = {0};
const uint8  Tpac_sin_signal_number = 0;
const sint16  Tpac_dyn_test_bed_rel_ref_map[TPAC_DYN_TEST_BED_REL_REF_MAP_COLS] = {0};
const uint16  TEST_BED_SAMP_PERIOD = 0;
const uint16  Tpac_dyn_test_bed_duration_map[TPAC_DYN_TEST_BED_DURATION_MAP_COLS] = {0};
const uint16  Tpac_sin_amplitude_map[TPAC_SIN_AMPLITUDE_MAP_COLS] = {0};
const uint16  Tpac_sin_bkpt_map[TPAC_SIN_BKPT_MAP_COLS] = {0};
const uint16  Tpac_sin_map[TPAC_SIN_MAP_COLS] = {0};
const uint16  Tpac_sin_signal_offset = 0;
const uint16  Tpac_sin_time_constant1 = 0;
const uint16  Tpac_sin_time_constant2 = 0;
const uint16  Tpac_sin_time_constant3 = 0;
const uint16  Tpac_sin_time_constant4 = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Etat_papmot_mode_banc;
boolean THRBENCHAUT_bTpacOpenLpCtrlPrev;
boolean Tpac_compute_ref_enab;
boolean Tpac_dyn_test_bed_type_ref;
boolean Tpac_sin_inverse_output;
uint8 Tpac_dyn_test_bed_next_offset;
uint8 Tpac_dyn_test_bed_offset;
uint8 Tpac_sin_freq;
uint8 Tpac_sin_signal_count;
uint8 Tpac_test_bed_next_table_counter;
uint8 Tpac_test_bed_table_counter;
sint16 Tpac_dyn_test_bed_next_rel_ref;
sint16 Tpac_dyn_test_bed_rel_ref;
sint16 Tpac_sin_signal_raw;
uint16 Dtc_throttle_pos_for_test_bed;
uint16 THRBENCHAUT_u16DtcThrPosTestBed1;
uint16 THRBENCHAUT_u16DtcThrPosTestBed2;
uint16 THRBENCHAUT_u16DtcThrPosTestBed3;
uint16 Tpac_dyn_test_bed_abs_ref;
uint16 Tpac_dyn_test_bed_duration;
uint16 Tpac_dyn_test_bed_next_abs_ref;
uint16 Tpac_dyn_test_bed_tempo;
uint16 Tpac_sin_amplitude;
uint16 Tpac_sin_duration;
uint16 Tpac_sin_func_entry;
uint16 Tpac_sin_time;
uint16 Tpac_sin_time_count;
sint32 Tpac_dyn_test_bed_increment;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

