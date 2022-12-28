/***************************************************************************
;**
;** FILE NAME      : THRPOSMES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRPOSMES.H"
#include "THRPOSMES_L.H"
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
const uint8  Thr_nDecCpt_CohPosnSnsr_C = 0;
const uint8  Thr_nDecCpt_ScgPosnSnsr1_C = 0;
const uint8  Thr_nDecCpt_ScgPosnSnsr2_C = 0;
const uint8  Thr_nDecCpt_ScpPosnSnsr1_C = 0;
const uint8  Thr_nDecCpt_ScpPosnSnsr2_C = 0;
const uint8  Thr_nDownTranThd_CohPosnSnsr_C = 0;
const uint8  Thr_nDownTranThd_ScgPosnSnsr1_C = 0;
const uint8  Thr_nDownTranThd_ScgPosnSnsr2_C = 0;
const uint8  Thr_nDownTranThd_ScpPosnSnsr1_C = 0;
const uint8  Thr_nDownTranThd_ScpPosnSnsr2_C = 0;
const uint8  Thr_nInitCptConf_CohPosnSnsr_C = 0;
const uint8  Thr_nInitCptConf_ScgPosnSnsr1_C = 0;
const uint8  Thr_nInitCptConf_ScgPosnSnsr2_C = 0;
const uint8  Thr_nInitCptConf_ScpPosnSnsr1_C = 0;
const uint8  Thr_nInitCptConf_ScpPosnSnsr2_C = 0;
const uint8  Thr_nUpTranThd_CohPosnSnsr_C = 0;
const uint8  Thr_nUpTranThd_ScgPosnSnsr1_C = 0;
const uint8  Thr_nUpTranThd_ScgPosnSnsr2_C = 0;
const uint8  Thr_nUpTranThd_ScpPosnSnsr1_C = 0;
const uint8  Thr_nUpTranThd_ScpPosnSnsr2_C = 0;
const uint8  THRPOSMES_u8Inhib = 0;
const uint8  Tps_coh_filter_gain = 0;
const uint8  Tps_tension_alimentation_gain = 0;
const uint16  Tps_1_default_cc_thresh = 0;
const uint16  Tps_1_default_co_thresh = 0;
const uint16  Tps_2_default_cc_thresh = 0;
const uint16  Tps_2_default_co_thresh = 0;
const uint16  Tps_position_tolerance_map[TPS_POSITION_TOLERANCE_MAP_COLS] = {0};
const uint16  Tps_tension_alim_thr_init = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Enable_diag_panne_tps_2_basse;
boolean Ext_bDgoDftSenr_Thr;
boolean Ext_bMonRunDftSenr_Thr;
boolean Thr_bAuthDiagInhThr_CpuSfty;
boolean Thr_bDftSftyCohPosnSnsr;
boolean Thr_bDftSftyScgPosnSnsr1;
boolean Thr_bDftSftyScgPosnSnsr2;
boolean Thr_bDftSftyScpPosnSnsr1;
boolean Thr_bDftSftyScpPosnSnsr2;
boolean Thr_bDgoCohPosnSnsr;
boolean Thr_bDgoScgPosnSnsr1;
boolean Thr_bDgoScgPosnSnsr2;
boolean Thr_bDgoScpPosnSnsr1;
boolean Thr_bDgoScpPosnSnsr2;
boolean Thr_bMonRunCohPosnSnsr;
boolean Thr_bMonRunScgPosnSnsr1;
boolean Thr_bMonRunScgPosnSnsr2;
boolean Thr_bMonRunScpPosnSnsr1;
boolean Thr_bMonRunScpPosnSnsr2;
boolean Thr_bMonWaitCohPosnSnsr;
boolean Thr_bMonWaitScgPosnSnsr1;
boolean Thr_bMonWaitScgPosnSnsr2;
boolean Thr_bMonWaitScpPosnSnsr1;
boolean Thr_bMonWaitScpPosnSnsr2;
boolean THRPOSMES_bDftSftyCohPosnSnsr;
boolean THRPOSMES_bDftSftyScgPosnSnsr1;
boolean THRPOSMES_bDftSftyScgPosnSnsr2;
boolean THRPOSMES_bDftSftyScpPosnSnsr1;
boolean THRPOSMES_bDftSftyScpPosnSnsr2;
boolean THRPOSMES_bFilSig_1;
boolean THRPOSMES_bFilSig_2;
boolean THRPOSMES_bFilSig_3;
boolean THRPOSMES_bFilSig_4;
boolean THRPOSMES_bFilSig_5;
boolean THRPOSMES_bTpsSensDefDiagEnaPrev;
boolean Tps_sensing_default_diag_enable;
uint32 THRPOSMES_u32AccuFilterMem;
uint32 THRPOSMES_u32DeltaVoltageFilt;
uint32 THRPOSMES_u32VoltFilterMem;
uint8 THRPOSMES_u8CntFilt_1;
uint8 THRPOSMES_u8CntFilt_2;
uint8 THRPOSMES_u8CntFilt_3;
uint8 THRPOSMES_u8CntFilt_4;
uint8 THRPOSMES_u8CntFilt_5;
uint8 THRPOSMES_u8CountNiv2_1;
uint8 THRPOSMES_u8CountNiv2_2;
uint8 THRPOSMES_u8CountNiv2_3;
uint8 THRPOSMES_u8CountNiv2_4;
uint8 THRPOSMES_u8CountNiv2_5;
uint16 Pos_papillon_1_result_ad_conv;
uint16 Pos_papillon_2_result_ad_conv;
uint16 Tension_alimentation_thr_filtree;
uint16 Tps_1_ratio_meas_position;
uint16 Tps_2_ratio_meas_position;
uint16 Tps_coh_abs_error;
uint16 Tps_coh_filt_abs_error;
uint16 Tps_position_tolerance;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

