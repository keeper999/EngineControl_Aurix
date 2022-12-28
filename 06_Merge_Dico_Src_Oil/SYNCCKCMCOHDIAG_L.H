/***************************************************************************
;**
;** FILE NAME      : SYNCCKCMCOHDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCCKCMCOHDIAG_L_H
#define SYNCCKCMCOHDIAG_L_H

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

extern const uint8  SYNCCKCMCOHDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bDgoEngSpdCohCk;
extern boolean Sync_bDgoEngSpdCohExCm;
extern boolean Sync_bDgoEngSpdCohInCm;
extern boolean Sync_bEngSpdDIfExCmCk;
extern boolean Sync_bEngSpdDIfInCmCk;
extern boolean Sync_bEngSpdDIfInCmExCm;
extern boolean Sync_bMonRunEngSpdCohCk;
extern boolean Sync_bMonRunEngSpdCohExCm;
extern boolean Sync_bMonRunEngSpdCohInCm;
extern boolean SYNCCKCMCOHDIAG_bEngineSyncPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCCKCMCOHDIAG_vidCondMonitor(void);
void SYNCCKCMCOHDIAG_vidExCm(void);
void SYNCCKCMCOHDIAG_vidInCm(void);
void SYNCCKCMCOHDIAG_vidInCmExCm(void);
void SYNCCKCMCOHDIAG_vidInitOutput(void);
void SYNCCKCMCOHDIAG_vidMonEngSpd(void);


#endif /* SYNCCKCMCOHDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
