/***************************************************************************
;**
;** FILE NAME      : KNKCRITZONE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKCRITZONE_H
#define KNKCRITZONE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MDYN_COR_CYL_INT_TEMP_BKPT_MAP_COLS    ( 9 )
#define TABLE_ZONE_CRITIQUE_LNS               ( 16 )
#define TABLE_ZONE_CRITIQUE_COLS               ( 9 )

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

extern const uint8  Seuil_temp_eau_zone_critique;
extern const uint8  Table_zone_critique[TABLE_ZONE_CRITIQUE_LNS][TABLE_ZONE_CRITIQUE_COLS];
extern const uint16  Mdyn_cor_cyl_int_temp_bkpt_map[MDYN_COR_CYL_INT_TEMP_BKPT_MAP_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Zone_critique;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgLim_EveBDC_CritZone(void);
void IgLim_EveCrTR_CritZone(void);
void IgLim_EveRst_CritZone(void);
void IgLim_EveRTCr_CritZone(void);


#endif /* KNKCRITZONE_H */

/*-------------------------------- end of file -------------------------------*/
