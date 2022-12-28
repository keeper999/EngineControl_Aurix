/***************************************************************************
;**
;** FILE NAME      : ACCPMNGMODSECU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPMNGMODSECU_L_H
#define ACCPMNGMODSECU_L_H

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

extern const uint8  ACCPMNGMODSECU_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AccP_bCohPctl;
extern boolean AccP_bCohPSenPctl;
extern boolean AccP_bPsenNoBoothDftEl;
extern boolean AccP_bPsenNoDftEl;
extern boolean AccP_bPsenOneDftEl;
extern boolean AccP_bPsenPctlEl;
extern uint16 AccP_rAccPFctMonPrev;
extern uint16 AccP_rAccPPrev;
extern uint16 AccP_rAccPRaw;
extern uint16 AccP_rAccPSens1Prev;
extern uint16 AccP_rAccPSens2Prev;
extern uint16 ACCPMNGMODSECU_u16AccPRawFilter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPMNGMODSECU_vidComputeAccPMng(void);
void ACCPMNGMODSECU_vidInit(void);
void ACCPMNGMODSECU_vidInitOutput(void);
void ACCPMNGMODSECU_vidMngPosSecu(void);
void ACCPMNGMODSECU_vidPedalPosfilter(void);
void ACCPMNGMODSECU_vidPedalPosInCalc(void);
void ACCPMNGMODSECU_vidStateTransit(void);
void ACCPMNGMODSECU_vidStuckPedalPos(void);


#endif /* ACCPMNGMODSECU_L_H */

/*-------------------------------- end of file -------------------------------*/
