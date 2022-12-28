/***************************************************************************
;**
;** FILE NAME      : SYNCINCMDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCINCMDIAG_H
#define SYNCINCMDIAG_H

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

extern const boolean  Acq_incam_chr_diag_ena_upcb0;
extern const uint8  Sync_cntFrntThd_C;
extern const uint16  Sync_nEngInhMonCohInCm_C;
extern const uint16  Sync_nEngInhMonCohInCm_Hys_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bAcvInjIgDrv;
extern boolean Sync_bInCmAcqVld;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Sync_EveInCmToo_InCmSts(void);
void Sync_EveKOn_InCmSts(void);
void Sync_EveRst_InCmSts(void);
void Sync_EveRTSt_InCmSts(void);


#endif /* SYNCINCMDIAG_H */

/*-------------------------------- end of file -------------------------------*/
