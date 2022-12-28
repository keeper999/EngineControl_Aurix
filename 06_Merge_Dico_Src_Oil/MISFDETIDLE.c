/***************************************************************************
;**
;** FILE NAME      : MISFDETIDLE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MISFDETIDLE.H"
#include "MISFDETIDLE_L.H"
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
const uint8  MisfDet_noDelaySync_C = 0;
const uint8  MISFDETIDLE_u8Inhib = 0;
const uint16  Mf_idle_algo_thresh_map_uacn2[MF_IDLE_ALGO_THRESH_MAP_UACN2_LNS][MF_IDLE_ALGO_THRESH_MAP_UACN2_COLS] = {0};
const uint16  Mf_idle_gain_thresh_map_uacn1[MF_IDLE_GAIN_THRESH_MAP_UACN1_COLS] = {0};
const uint16  Mf_idle_gain_thresh_map_UT_uacn1[MF_IDLE_GAIN_THRESH_MAP_UT_UACN1_COLS] = {0};
const uint16  MisfDet_nEngCurIdle_Y[MISFDET_NENGCURIDLE_Y_COLS] = {0};
const uint16  MisfDet_tqEngCurIdle_X[MISFDET_TQENGCURIDLE_X_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint32 MISFDETIDLE_u32tiDlyWinAdpPrev1;
uint32 MISFDETIDLE_u32tiDlyWinAdpPrev2;
uint8 Mf_Idle_det_single_output_uavb0;
sint16 Mf_idle_algo_out_uavn0;
sint16 Mf_idle_crite_next_uavn0;
sint16 Mf_idle_crite_prev_prev_uavn0;
sint16 Mf_idle_crite_prev_uavn0;
sint16 Mf_idle_crite_uavn0;
uint16 Mf_idle_algo_thresh_uavn0;
uint16 MISFDETIDLE_u16ResultPrev3;
uint16 MISFDETIDLE_u16ResultPrev4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

