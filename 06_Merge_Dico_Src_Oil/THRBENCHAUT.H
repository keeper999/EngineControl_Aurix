/***************************************************************************
;**
;** FILE NAME      : THRBENCHAUT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRBENCHAUT_H
#define THRBENCHAUT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TPAC_DYN_TEST_BED_DURATION_MAP_COLS    ( 16 )
#define TPAC_DYN_TEST_BED_OFFSET_MAP_COLS      ( 16 )
#define TPAC_DYN_TEST_BED_REL_REF_MAP_COLS     ( 16 )
#define TPAC_DYN_TEST_BED_TYPE_REF_MAP_COLS    ( 16 )
#define TPAC_SIN_AMPLITUDE_MAP_COLS            ( 8 )
#define TPAC_SIN_BKPT_MAP_COLS                 ( 7 )
#define TPAC_SIN_FREQ_MAP_COLS                 ( 8 )
#define TPAC_SIN_MAP_COLS                      ( 7 )
#define TPAC_SIN_PERIOD_COUNT_MAP_COLS         ( 8 )

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

extern const boolean  Dtc_throttle_test_bed_mode;
extern const boolean  Tpac_dyn_test_bed_mode;
extern const boolean  Tpac_dyn_test_bed_sinus_mode;
extern const boolean  Tpac_dyn_test_bed_type_ref_map[TPAC_DYN_TEST_BED_TYPE_REF_MAP_COLS];
extern const uint8  Tpac_dyn_test_bed_offset_map[TPAC_DYN_TEST_BED_OFFSET_MAP_COLS];
extern const uint8  Tpac_dyn_test_bed_pattern_number;
extern const uint8  Tpac_sin_freq_map[TPAC_SIN_FREQ_MAP_COLS];
extern const uint8  Tpac_sin_period_count_map[TPAC_SIN_PERIOD_COUNT_MAP_COLS];
extern const uint8  Tpac_sin_signal_number;
extern const sint16  Tpac_dyn_test_bed_rel_ref_map[TPAC_DYN_TEST_BED_REL_REF_MAP_COLS];
extern const uint16  TEST_BED_SAMP_PERIOD;
extern const uint16  Tpac_dyn_test_bed_duration_map[TPAC_DYN_TEST_BED_DURATION_MAP_COLS];
extern const uint16  Tpac_sin_amplitude_map[TPAC_SIN_AMPLITUDE_MAP_COLS];
extern const uint16  Tpac_sin_bkpt_map[TPAC_SIN_BKPT_MAP_COLS];
extern const uint16  Tpac_sin_map[TPAC_SIN_MAP_COLS];
extern const uint16  Tpac_sin_signal_offset;
extern const uint16  Tpac_sin_time_constant1;
extern const uint16  Tpac_sin_time_constant2;
extern const uint16  Tpac_sin_time_constant3;
extern const uint16  Tpac_sin_time_constant4;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Dtc_throttle_pos_for_test_bed;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_BenchAut(void);
void Thr_SdlMid_BenchAut(void);


#endif /* THRBENCHAUT_H */

/*-------------------------------- end of file -------------------------------*/
