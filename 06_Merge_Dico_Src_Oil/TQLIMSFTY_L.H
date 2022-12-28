/***************************************************************************
;**
;** FILE NAME      : TQLIMSFTY_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQLIMSFTY_L_H
#define TQLIMSFTY_L_H

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

extern const uint8  TQLIMSFTY_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean EngLim_bAcvTqLim_prev;
extern boolean EngLim_bRiseEdgeTqLim;
extern boolean EngLim_bTqLimTran;
extern sint16 EngLim_tqSftystat;
extern sint16 TQLIMSFTY_s16SlewRateOutput;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQLIMSFTY_vidEcuReset(void);
void TQLIMSFTY_vidPreviousCalc(void);
void TQLIMSFTY_vidStaticLimit(void);
void TQLIMSFTY_vidTorqueLimitSafety(void);


#endif /* TQLIMSFTY_L_H */

/*-------------------------------- end of file -------------------------------*/
