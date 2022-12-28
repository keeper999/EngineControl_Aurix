/***************************************************************************
;**
;** FILE NAME      : CATAGIESTIM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CATAGIESTIM_H
#define CATAGIESTIM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CAT_OLD_GAIN_MAP_COLS                  ( 8 )
#define CAT_OLD_GAIN_OBD_MAP_COLS              ( 8 )
#define KM_VEHICLE_BKPT_MAP_COLS               ( 8 )

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

extern const uint8  Cat_old_gain_map[CAT_OLD_GAIN_MAP_COLS];
extern const uint8  Cat_old_gain_obd_map[CAT_OLD_GAIN_OBD_MAP_COLS];
extern const uint16  Km_vehicle_bkpt_map[KM_VEHICLE_BKPT_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Cat_old_gain;
extern uint8 Cat_old_gain_obd;
extern uint16 OxC_facDmgOxC;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CATAGIESTIM_vidEntryInit(void);
void CatMdl_SdlSlow_EstimAgi(void);


#endif /* CATAGIESTIM_H */

/*-------------------------------- end of file -------------------------------*/
