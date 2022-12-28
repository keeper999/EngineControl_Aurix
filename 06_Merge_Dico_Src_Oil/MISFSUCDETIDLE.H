/***************************************************************************
;**
;** FILE NAME      : MISFSUCDETIDLE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFSUCDETIDLE_H
#define MISFSUCDETIDLE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_IDLE_ALGO_THRESH_2_MAP_UACN2_LNS   ( 7 )
#define MF_IDLE_ALGO_THRESH_2_MAP_UACN2_COLS   ( 7 )

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

extern const uint8  Mf_2_misfire_idle_det_uacn0;
extern const uint8  Mf_misfire_idle_det_thresh_uacn0;
extern const uint8  MisfDet_noDelaySyncDetSingle_C;
extern const uint8  MisfDet_noDelaySyncSuc_C;
extern const uint16  Mf_idle_algo_thresh_2_map_uacn2[MF_IDLE_ALGO_THRESH_2_MAP_UACN2_LNS][MF_IDLE_ALGO_THRESH_2_MAP_UACN2_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_2_misfire_idle_detected_uavb0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfSucDetIdle(void);
void Misf_EveRst_MisfSucDetIdle(void);


#endif /* MISFSUCDETIDLE_H */

/*-------------------------------- end of file -------------------------------*/
