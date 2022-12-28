/***************************************************************************
;**
;** FILE NAME      : MISFSUCDET.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFSUCDET_H
#define MISFSUCDET_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MF_2_MISFIRE_DET_MAP_UACN2_LNS        ( 7 )
#define MF_2_MISFIRE_DET_MAP_UACN2_COLS        ( 16 )

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

extern const uint8  Mf_2_misfire_det_map_uacn2[MF_2_MISFIRE_DET_MAP_UACN2_LNS][MF_2_MISFIRE_DET_MAP_UACN2_COLS];
extern const uint8  Mf_misfire_detected_thresh_uacn0;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Mf_2_misfire_detected_uavb0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveMisf_MisfSucDet(void);
void MISFSUCDET_vidEntryInit(void);


#endif /* MISFSUCDET_H */

/*-------------------------------- end of file -------------------------------*/
