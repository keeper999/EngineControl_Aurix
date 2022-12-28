/***************************************************************************
;**
;** FILE NAME      : STRTLOCKACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STRTLOCKACQ_L_H
#define STRTLOCKACQ_L_H

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

extern const uint8  STRTLOCKACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoCoh_StrtLock;
extern boolean Ext_bMonRunCoh_StrtLock;
extern boolean STRTLOCKACQ_bDebouncingFilSig;
extern uint8 STRTLOCKACQ_u8DebouncingFiltCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STRTLOCKACQ_vidDefautStrtLock(void);
void STRTLOCKACQ_vidDiagnostic(void);
void STRTLOCKACQ_vidInitialisation(void);
void STRTLOCKACQ_vidOS(void);
void STRTLOCKACQ_vidStrtLockAcq(void);


#endif /* STRTLOCKACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
