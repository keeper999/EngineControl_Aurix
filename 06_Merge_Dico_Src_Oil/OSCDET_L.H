/***************************************************************************
;**
;** FILE NAME      : OSCDET_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OSCDET_L_H
#define OSCDET_L_H

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

extern const uint8  OSCDET_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean EngSt_bAcvOscDetStab;
extern boolean EngSt_bEnaOscDet;
extern boolean EngSt_bOscDetAirLdCor;
extern boolean EngSt_bOscDetIdlSpd;
extern boolean OSCDET_bTimerInit;
extern uint16 EngSt_nIdlSpdOscMax;
extern uint16 EngSt_nIdlSpdOscMin;
extern uint16 EngSt_rAirLdOscMax;
extern uint16 EngSt_rAirLdOscMin;
extern uint16 EngSt_tiDlyOscDet;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OSCDET_vidInitOutput(void);
void OSCDET_vidOscCheckFctCallInit(void);
void OSCDET_vidOscCheckStabDecision(void);
void OSCDET_vidOscCheckStabIdlSpd(void);
void OSCDET_vidOscCheckStabilityInit(void);
void OSCDET_vidOscChekStabAirLd(void);
void OSCDET_vidOscChekStabilityPeriod(void);
void OSCDET_vidOscEngAirLoadExtrCmpt(void);
void OSCDET_vidOscEngAirLoadStabCompt(void);
void OSCDET_vidOscEngSpeedExtrCmpt(void);
void OSCDET_vidOscEngSpeedStabCmpt(void);


#endif /* OSCDET_L_H */

/*-------------------------------- end of file -------------------------------*/
