/***************************************************************************
;**
;** FILE NAME      : THRPOSMES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRPOSMES_H
#define THRPOSMES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TPS_POSITION_TOLERANCE_MAP_COLS        ( 9 )

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

extern const uint8  Thr_nDecCpt_CohPosnSnsr_C;
extern const uint8  Thr_nDecCpt_ScgPosnSnsr1_C;
extern const uint8  Thr_nDecCpt_ScgPosnSnsr2_C;
extern const uint8  Thr_nDecCpt_ScpPosnSnsr1_C;
extern const uint8  Thr_nDecCpt_ScpPosnSnsr2_C;
extern const uint8  Thr_nDownTranThd_CohPosnSnsr_C;
extern const uint8  Thr_nDownTranThd_ScgPosnSnsr1_C;
extern const uint8  Thr_nDownTranThd_ScgPosnSnsr2_C;
extern const uint8  Thr_nDownTranThd_ScpPosnSnsr1_C;
extern const uint8  Thr_nDownTranThd_ScpPosnSnsr2_C;
extern const uint8  Thr_nInitCptConf_CohPosnSnsr_C;
extern const uint8  Thr_nInitCptConf_ScgPosnSnsr1_C;
extern const uint8  Thr_nInitCptConf_ScgPosnSnsr2_C;
extern const uint8  Thr_nInitCptConf_ScpPosnSnsr1_C;
extern const uint8  Thr_nInitCptConf_ScpPosnSnsr2_C;
extern const uint8  Thr_nUpTranThd_CohPosnSnsr_C;
extern const uint8  Thr_nUpTranThd_ScgPosnSnsr1_C;
extern const uint8  Thr_nUpTranThd_ScgPosnSnsr2_C;
extern const uint8  Thr_nUpTranThd_ScpPosnSnsr1_C;
extern const uint8  Thr_nUpTranThd_ScpPosnSnsr2_C;
extern const uint8  Tps_coh_filter_gain;
extern const uint8  Tps_tension_alimentation_gain;
extern const uint16  Tps_1_default_cc_thresh;
extern const uint16  Tps_1_default_co_thresh;
extern const uint16  Tps_2_default_cc_thresh;
extern const uint16  Tps_2_default_co_thresh;
extern const uint16  Tps_position_tolerance_map[TPS_POSITION_TOLERANCE_MAP_COLS];
extern const uint16  Tps_tension_alim_thr_init;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Enable_diag_panne_tps_2_basse;
extern boolean Thr_bAuthDiagInhThr_CpuSfty;
extern boolean Thr_bDftSftyCohPosnSnsr;
extern boolean Thr_bDftSftyScgPosnSnsr1;
extern boolean Thr_bDftSftyScgPosnSnsr2;
extern boolean Thr_bDftSftyScpPosnSnsr1;
extern boolean Thr_bDftSftyScpPosnSnsr2;
extern uint16 Pos_papillon_1_result_ad_conv;
extern uint16 Pos_papillon_2_result_ad_conv;
extern uint16 Tps_1_ratio_meas_position;
extern uint16 Tps_2_ratio_meas_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveClcnServo_PosnMes(void);
void Thr_EveRst_PosnMes(void);
void Thr_EveTDC_PosnMes(void);
void Thr_SdlSfty_ThrPosnMes(void);


#endif /* THRPOSMES_H */

/*-------------------------------- end of file -------------------------------*/
