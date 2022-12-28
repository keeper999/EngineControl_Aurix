/***************************************************************************
;**
;** FILE NAME      : MISFWINACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MISFWINACQ_L_H
#define MISFWINACQ_L_H

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

extern const uint8  MISFWINACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Misf_bAcqActive;
extern boolean Misf_bAcqActive_prev;
extern uint32 Misf_tiDlyBdcWinLdb;
extern uint32 Misf_tiDlyExpWinLdb;
extern uint32 Misf_tiDlyLongWinLdb;
extern uint32 Misf_tiDlyTDCWinLdb;
extern uint8 Misf_cntWinAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MISFWINACQ_MisfAcqDesactive(void);
void MISFWINACQ_vidAcqLdbWinDuration(void);
void MISFWINACQ_vidInitOuput(void);
void MISFWINACQ_vidinitWintiDly(void);
void MISFWINACQ_vidMisfAcqActive(void);
void MISFWINACQ_vidMisfAcqDesactive(void);
void MISFWINACQ_vidMisfAcqSdlActive(void);
void MISFWINACQ_vidMisfAcqSyncActive(void);
void MISFWINACQ_vidReadWintiDly(void);
void MISFWINACQ_vidWinDuration(void);


#endif /* MISFWINACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
