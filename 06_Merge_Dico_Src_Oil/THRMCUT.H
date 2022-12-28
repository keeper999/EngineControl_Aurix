/***************************************************************************
;**
;** FILE NAME      : THRMCUT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRMCUT_H
#define THRMCUT_H

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

extern const boolean  Throttle_pos_ref_freeze_manu_inh;
extern const boolean  Tps_1_mcut_det_manu_inh;
extern const uint8  Tps_1_drop_mcut_filter_gain;
extern const uint8  Tps_num_rec_prev_mcut;
extern const uint8  Tps_overlap_gain_meas;
extern const uint8  Tps_overlap_gain_ref;
extern const uint8  Tps_overlap_switch_step_number;
extern const uint16  Thr_tiMcutMaxDetTi_C;
extern const uint16  Tps_drop_mcut_diff_tolerance;
extern const uint16  Tps_drop_mcut_grad_tolerance;
extern const uint16  Tps_overlap_switch_max_rate;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bDeacThrStopLrn;
extern boolean Throttle_pos_ref_freeze_enab;
extern boolean Tps_1_overlap_demand;
extern boolean Tps_2_overlap_demand;
extern boolean Tps_mcut_detect_flag;
extern uint16 Tps_1_raw_filt_position;
extern uint16 Tps_2_raw_filt_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveClcnServo_mCut(void);
void Thr_EveRst_mCut(void);


#endif /* THRMCUT_H */

/*-------------------------------- end of file -------------------------------*/
