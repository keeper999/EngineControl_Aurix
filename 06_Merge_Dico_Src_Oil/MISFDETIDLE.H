/***************************************************************************
;**
;** FILE NAME      : MISFDETIDLE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFDETIDLE_H
#define MISFDETIDLE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_IDLE_ALGO_THRESH_MAP_UACN2_LNS     ( 7 )
#define MF_IDLE_ALGO_THRESH_MAP_UACN2_COLS     ( 7 )
#define MF_IDLE_GAIN_THRESH_MAP_UACN1_COLS     ( 7 )
#define MF_IDLE_GAIN_THRESH_MAP_UT_UACN1_COLS  ( 7 )
#define MISFDET_NENGCURIDLE_Y_COLS             ( 7 )
#define MISFDET_TQENGCURIDLE_X_COLS            ( 7 )

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

extern const uint8  MisfDet_noDelaySync_C;
extern const uint16  Mf_idle_algo_thresh_map_uacn2[MF_IDLE_ALGO_THRESH_MAP_UACN2_LNS][MF_IDLE_ALGO_THRESH_MAP_UACN2_COLS];
extern const uint16  Mf_idle_gain_thresh_map_uacn1[MF_IDLE_GAIN_THRESH_MAP_UACN1_COLS];
extern const uint16  Mf_idle_gain_thresh_map_UT_uacn1[MF_IDLE_GAIN_THRESH_MAP_UT_UACN1_COLS];
extern const uint16  MisfDet_nEngCurIdle_Y[MISFDET_NENGCURIDLE_Y_COLS];
extern const uint16  MisfDet_tqEngCurIdle_X[MISFDET_TQENGCURIDLE_X_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Mf_Idle_det_single_output_uavb0;
extern sint16 Mf_idle_crite_next_uavn0;
extern sint16 Mf_idle_crite_prev_prev_uavn0;
extern sint16 Mf_idle_crite_prev_uavn0;
extern sint16 Mf_idle_crite_uavn0;
extern uint16 Mf_idle_algo_thresh_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfDetIdle(void);
void Misf_EveRst_MisfDetIdle(void);


#endif /* MISFDETIDLE_H */

/*-------------------------------- end of file -------------------------------*/
