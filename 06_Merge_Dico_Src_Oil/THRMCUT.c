/***************************************************************************
;**
;** FILE NAME      : THRMCUT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRMCUT.H"
#include "THRMCUT_L.H"
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
const boolean  Throttle_pos_ref_freeze_manu_inh = 0;
const boolean  Tps_1_mcut_det_manu_inh = 0;
const uint8  THRMCUT_u8Inhib = 0;
const uint8  Tps_1_drop_mcut_filter_gain = 0;
const uint8  Tps_num_rec_prev_mcut = 0;
const uint8  Tps_overlap_gain_meas = 0;
const uint8  Tps_overlap_gain_ref = 0;
const uint8  Tps_overlap_switch_step_number = 0;
const uint16  Thr_tiMcutMaxDetTi_C = 0;
const uint16  Tps_drop_mcut_diff_tolerance = 0;
const uint16  Tps_drop_mcut_grad_tolerance = 0;
const uint16  Tps_overlap_switch_max_rate = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bDeacThrStopLrn;
boolean THRMCUT_bMcutDetectflag;
boolean THRMCUT_bMcutDetectflagTimeOut;
boolean Throttle_pos_ref_freeze_enab;
boolean Tps_1_overlap_demand;
boolean Tps_1_overlap_demand_Prev;
boolean Tps_2_overlap_demand;
boolean Tps_2_overlap_demand_Prev;
boolean Tps_mcut_detect_flag;
boolean Tps_ratio_meas_position_enab;
boolean Tps_ratio_meas_position_enab_prev;
uint32 THRMCUT_u32RatioMeasPosFiltMem;
uint16 THRMCUT_u16FiltredPosition;
uint16 THRMCUT_u16McutDetectflagTimer;
uint16 Tps_1_diff_ratio_meas_overlap;
uint16 Tps_1_ratio_meas_pos_overlap;
uint16 Tps_1_ratio_meas_pos_prec_0;
uint16 Tps_1_ratio_meas_pos_prec_1;
uint16 Tps_1_ratio_meas_pos_prec_2;
uint16 Tps_1_ratio_meas_pos_prec_3;
uint16 Tps_1_raw_filt_position;
uint16 Tps_1_switch_step;
uint16 Tps_2_diff_ratio_meas_overlap;
uint16 Tps_2_ratio_meas_pos_overlap;
uint16 Tps_2_ratio_meas_pos_prec_0;
uint16 Tps_2_ratio_meas_pos_prec_1;
uint16 Tps_2_ratio_meas_pos_prec_2;
uint16 Tps_2_ratio_meas_pos_prec_3;
uint16 Tps_2_raw_filt_position;
uint16 Tps_2_switch_step;
sint32 THRMCUT_s32FilterPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

