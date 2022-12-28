/***************************************************************************
;**
;** FILE NAME      : ACQWKUSIG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQWKUSIG_L_H
#define ACQWKUSIG_L_H

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

extern const uint8  ACQWKUSIG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Clef_signal_raw;
extern uint8 ACQWKUSIG_u8AntiBounceCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACQWKUSIG_vidInitOutPut(void);
void ACQWKUSIG_vidKeyOnOffInit(void);
void ACQWKUSIG_vidKeyTreatement(void);
void ACQWKUSIG_vidRcdModeActive(void);
void ACQWKUSIG_vidRcdModeNoAct(void);


#endif /* ACQWKUSIG_L_H */

/*-------------------------------- end of file -------------------------------*/
