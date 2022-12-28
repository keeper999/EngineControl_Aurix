/***************************************************************************
;**
;** FILE NAME      : ENGLIMEFCCORD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGLIMEFCCORD_H
#define ENGLIMEFCCORD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const boolean  EngLim_bLimDynSel_C;
extern const boolean  EngLim_bProtDfltChaSel_C;
extern const boolean  EngLim_bProtDfltModSptSel_C;
extern const boolean  EngLim_bSmkLimDrivFil_C;
extern const uint8  EngLim_idxChaLim_C;
extern const uint8  EngLim_idxCoPtLim_C;
extern const uint8  EngLim_idxCoPtLimAT_C;
extern const uint8  EngLim_idxModSptLim_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 EngLim_tqCkEfcModSptLim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGLIMEFCCORD_vidEntryInit(void);
void TqSys_Sdl10ms_TqEfcCordLim(void);


#endif /* ENGLIMEFCCORD_H */

/*-------------------------------- end of file -------------------------------*/
