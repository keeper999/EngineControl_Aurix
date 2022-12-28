/***************************************************************************
;**
;** FILE NAME      : MISFSUCDETIDLE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFSUCDETIDLE.H"
#include "MISFSUCDETIDLE_L.H"
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
const uint8  Mf_2_misfire_idle_det_uacn0 = 0;
const uint8  Mf_misfire_idle_det_thresh_uacn0 = 0;
const uint8  MisfDet_noDelaySyncDetSingle_C = 0;
const uint8  MisfDet_noDelaySyncSuc_C = 0;
const uint8  MISFSUCDETIDLE_u8Inhib = 0;
const uint16  Mf_idle_algo_thresh_2_map_uacn2[MF_IDLE_ALGO_THRESH_2_MAP_UACN2_LNS][MF_IDLE_ALGO_THRESH_2_MAP_UACN2_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Mf_2_misfire_idle_detected_uavb0;
boolean MisfDet_bMisfSucDetEna;
boolean MisfDet_bMisfSucDetRaw;
boolean MISFSUCDETIDLE_bCondSucEnaPrev;
boolean MISFSUCDETIDLE_bMisfSucRawPrev1;
boolean MISFSUCDETIDLE_bMisfSucRawPrev2;
uint8 Mf_Idl_det_single_out_prev_uavb0;
uint8 MISFSUCDETIDLE_u8MfIdlesingPrev1;
uint8 MISFSUCDETIDLE_u8MfIdlesingPrev2;
sint16 Mf_idle1_algo_trust_uavn0;
sint16 Mf_idle2_algo_trust_uavn0;
sint16 MisfDet_critAlgoIdleOut1;
sint16 MisfDet_critAlgoIdleOut2;
uint16 Mf_idle_algo_thresh_2_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

