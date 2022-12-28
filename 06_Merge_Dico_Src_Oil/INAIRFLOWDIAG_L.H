/***************************************************************************
;**
;** FILE NAME      : INAIRFLOWDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INAIRFLOWDIAG_L_H
#define INAIRFLOWDIAG_L_H

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

extern const uint8  INAIRFLOWDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AirSys_bDgoBoost1_pDsThr;
extern boolean AirSys_bDgoBoost2_pDsThr;
extern boolean AirSys_bDgoBoost3_pDsThr;
extern boolean AirSys_bDgoBoost4_pDsThr;
extern boolean AirSys_bMonRunBoost1_pDsThr;
extern boolean AirSys_bMonRunBoost2_pDsThr;
extern boolean AirSys_bMonRunBoost3_pDsThr;
extern boolean AirSys_bMonRunBoost4_pDsThr;
extern uint16 AirSys_pDsThrLeak1;
extern uint16 AirSys_pDsThrLeak2;
extern uint16 AirSys_rCohMnfMfBoost;
extern uint16 AirSys_rCohMnfMfBoostDeac;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INAIRFLOWDIAG_vidDgPrLeak(void);
void INAIRFLOWDIAG_vidDgPrLwAirfl(void);
void INAIRFLOWDIAG_vidInit(void);
void INAIRFLOWDIAG_vidLeak(void);
void INAIRFLOWDIAG_vidLowAirflow(void);


#endif /* INAIRFLOWDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
