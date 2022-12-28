/***************************************************************************
;**
;** FILE NAME      : MISFROUGHNSROAD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFROUGHNSROAD_H
#define MISFROUGHNSROAD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_ROUGH_ROAD_DET_MAP_UACN2_LNS       ( 7 )
#define MF_ROUGH_ROAD_DET_MAP_UACN2_COLS       ( 16 )

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

extern const uint8  Mf_low_veh_speed_thresh_uacn0;
extern const uint8  Mf_n_min_rough_road_det_uacn0;
extern const uint8  Mf_rough_road_det_map_uacn2[MF_ROUGH_ROAD_DET_MAP_UACN2_LNS][MF_ROUGH_ROAD_DET_MAP_UACN2_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_rough_road_uavb0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfRoughnsRoad(void);
void MISFROUGHNSROAD_vidEntryInit(void);


#endif /* MISFROUGHNSROAD_H */

/*-------------------------------- end of file -------------------------------*/
