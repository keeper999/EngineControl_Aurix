/***************************************************************************
;**
;** FILE NAME      : SYNCEXCMDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCEXCMDIAG_L_H
#define SYNCEXCMDIAG_L_H

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

extern const uint8  SYNCEXCMDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Sync_bDgoCoh_ExCm;
extern boolean Sync_bMonRunCoh_ExCm;
extern boolean SYNCEXCMDIAG_bHysOutput;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCEXCMDIAG_vidDiag(void);
void SYNCEXCMDIAG_vidDiagExCmAcq(void);
void SYNCEXCMDIAG_vidExCmAcqVld(void);
void SYNCEXCMDIAG_vidIniDiag(void);
void SYNCEXCMDIAG_vidInitOutput(void);


#endif /* SYNCEXCMDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
