/***************************************************************************
;**
;** FILE NAME      : AIRTFONCDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTFONCDIAG_L_H
#define AIRTFONCDIAG_L_H

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

extern const uint8  AIRTFONCDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirT_bDgoNegOfs_tAirMes;
extern boolean AirT_bDgoORng_tAirMes;
extern boolean AirT_bDgoPosOfs_tAirMes;
extern boolean AirT_bDgoStallCoh_tAirMes;
extern boolean AirT_bMonRunNegOfs_tAirMes;
extern boolean AirT_bMonRunORng_tAirMes;
extern boolean AirT_bMonRunPosOfs_tAirMes;
extern boolean AirT_bMonRunStallCoh_tAirMes;
extern boolean AirT_bTmfAirCorPosOfs;
extern boolean AIRTFONCDIAG_bTimerInit_prev;
extern uint16 AirT_tiEngrunTNegOfs;
extern uint16 AirT_tiIdlCtlTNegOfs;
extern uint16 AirT_timfAirCorPosOfs;
extern uint16 AirT_tiTPosOfs;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIRTFONCDIAG_vidBeforeStartCoh(void);
void AIRTFONCDIAG_vidCohActivDtct(void);
void AIRTFONCDIAG_vidInitOutput(void);
void AIRTFONCDIAG_vidNegOfsActivDtct(void);
void AIRTFONCDIAG_vidNegOfsDtct(void);
void AIRTFONCDIAG_vidOutRngActivDtct(void);
void AIRTFONCDIAG_vidOutRngDtct(void);
void AIRTFONCDIAG_vidPosOfsActivDtct(void);
void AIRTFONCDIAG_vidPosOfsDtct(void);


#endif /* AIRTFONCDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
