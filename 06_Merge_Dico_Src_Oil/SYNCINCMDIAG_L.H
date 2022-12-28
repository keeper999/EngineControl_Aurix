/***************************************************************************
;**
;** FILE NAME      : SYNCINCMDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCINCMDIAG_L_H
#define SYNCINCMDIAG_L_H

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

extern const uint8  SYNCINCMDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bDgoCoh_InCm;
extern boolean Sync_bMonRunCoh_InCm;
extern boolean SYNCINCMDIAG_bHysteresisOutput;
extern uint8 Sync_cntFrntIncm;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCINCMDIAG_vidCntFrnt(void);
void SYNCINCMDIAG_vidDiag(void);
void SYNCINCMDIAG_vidDiagInCmAcq(void);
void SYNCINCMDIAG_vidInCmAcqVld(void);
void SYNCINCMDIAG_vidInCmCntFrnt(void);
void SYNCINCMDIAG_vidIniDiag(void);
void SYNCINCMDIAG_vidInitOutput(void);
void SYNCINCMDIAG_vidStopEng(void);


#endif /* SYNCINCMDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
