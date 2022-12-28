/***************************************************************************
;**
;** FILE NAME      : THROPLCTL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THROPLCTL_L_H
#define THROPLCTL_L_H

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

extern const uint8  THROPLCTL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean THROPLCTL_bTpacOpenLoopCtrlPrev;
extern uint8 THROPLCTL_u8TpacThrotCtrlStPrev;
extern uint8 Tpac_exit_low_thrust_tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THROPLCTL_CalcWaitAdc(void);
void THROPLCTL_vidCalcClosingRamp(void);
void THROPLCTL_vidCalcExitLowThrust(void);
void THROPLCTL_vidCalcMcwInh(void);
void THROPLCTL_vidCalcOpeningRamp(void);
void THROPLCTL_vidConditions(void);
void THROPLCTL_vidInit(void);
void THROPLCTL_vidInitClosingRamp(void);
void THROPLCTL_vidInitExitLowThrust(void);
void THROPLCTL_vidInitMcpInh(void);
void THROPLCTL_vidInitMcwInh(void);
void THROPLCTL_vidInitOpeningRamp(void);
void THROPLCTL_vidInitOutput(void);


#endif /* THROPLCTL_L_H */

/*-------------------------------- end of file -------------------------------*/
