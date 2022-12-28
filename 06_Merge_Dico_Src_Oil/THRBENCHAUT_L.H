/***************************************************************************
;**
;** FILE NAME      : THRBENCHAUT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRBENCHAUT_L_H
#define THRBENCHAUT_L_H

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

/* enum st33 */
#define PAPMOT_IDLE                       1
#define PAPMOT_INCR_IDX                   2
/*extern uint8 Etat_papmot_mode_banc;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  THRBENCHAUT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Etat_papmot_mode_banc;
extern boolean THRBENCHAUT_bTpacOpenLpCtrlPrev;
extern boolean Tpac_compute_ref_enab;
extern boolean Tpac_dyn_test_bed_type_ref;
extern boolean Tpac_sin_inverse_output;
extern uint8 Tpac_dyn_test_bed_next_offset;
extern uint8 Tpac_dyn_test_bed_offset;
extern uint8 Tpac_sin_freq;
extern uint8 Tpac_sin_signal_count;
extern uint8 Tpac_test_bed_next_table_counter;
extern uint8 Tpac_test_bed_table_counter;
extern sint16 Tpac_dyn_test_bed_next_rel_ref;
extern sint16 Tpac_dyn_test_bed_rel_ref;
extern sint16 Tpac_sin_signal_raw;
extern uint16 THRBENCHAUT_u16DtcThrPosTestBed1;
extern uint16 THRBENCHAUT_u16DtcThrPosTestBed2;
extern uint16 THRBENCHAUT_u16DtcThrPosTestBed3;
extern uint16 Tpac_dyn_test_bed_abs_ref;
extern uint16 Tpac_dyn_test_bed_duration;
extern uint16 Tpac_dyn_test_bed_next_abs_ref;
extern uint16 Tpac_dyn_test_bed_tempo;
extern uint16 Tpac_sin_amplitude;
extern uint16 Tpac_sin_duration;
extern uint16 Tpac_sin_func_entry;
extern uint16 Tpac_sin_time;
extern uint16 Tpac_sin_time_count;
extern sint32 Tpac_dyn_test_bed_increment;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRBENCHAUT_vidCalcAngleEval(void);
void THRBENCHAUT_vidCompSinAngleEval(void);
void THRBENCHAUT_vidComputeAbsolutRef(void);
void THRBENCHAUT_vidComputeAbsRefIncr(void);
void THRBENCHAUT_vidComputeIncrement(void);
void THRBENCHAUT_vidComputeReference(void);
void THRBENCHAUT_vidComputeSignal(void);
void THRBENCHAUT_vidControlPart(void);
void THRBENCHAUT_vidCurrentIndex(void);
void THRBENCHAUT_vidDynMode_1(void);
void THRBENCHAUT_vidDynMode_2(void);
void THRBENCHAUT_vidDynMode_3(void);
void THRBENCHAUT_vidGenerateSignal(void);
void THRBENCHAUT_vidIncrGenTimeCount(void);
void THRBENCHAUT_vidIncrSignalCount(void);
void THRBENCHAUT_vidIncSinTime(void);
void THRBENCHAUT_vidInitOutput(void);
void THRBENCHAUT_vidMotThrAutBenchMod(void);
void THRBENCHAUT_vidNextIndex(void);
void THRBENCHAUT_vidNextSignal(void);
void THRBENCHAUT_vidResetSinTime(void);
void THRBENCHAUT_vidSelectFrequency(void);
void THRBENCHAUT_vidSinTimeFirstQuad(void);
void THRBENCHAUT_vidSinTimeFourthQuad(void);
void THRBENCHAUT_vidSinTimeSecondQuad(void);
void THRBENCHAUT_vidSinTimeThirdQuad(void);
void THRBENCHAUT_vidUserCalibrations(void);


#endif /* THRBENCHAUT_L_H */

/*-------------------------------- end of file -------------------------------*/
