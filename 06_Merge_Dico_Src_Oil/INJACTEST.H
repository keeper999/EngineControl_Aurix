/***************************************************************************
;**
;** FILE NAME      : INJACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJACTEST_H
#define INJACTEST_H

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

extern const uint8  Inj_noInjFirstFull_C;
extern const uint16  ActrTstInj_TempoIdle_C;
extern const uint16  Afts_tiDlyTotTestInj_C;
extern const uint16  Afts_tiPerTestInj_C;
extern const uint16  Afts_tiTestInj_C;
extern const uint16  Inj_tiDlyFirstFillFu_C;
extern const uint16  Inj_tiInjFirstFillFu_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Inj_bInj1TstCmpl;
extern boolean Inj_bInj2TstCmpl;
extern boolean Inj_bInj3TstCmpl;
extern boolean Inj_bInj4TstCmpl;
extern boolean Inj_bPwrRlyCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Inj_EveRst_ActrTstInj(void);
void Inj_SdlFast_ActrTstInj(void);


#endif /* INJACTEST_H */

/*-------------------------------- end of file -------------------------------*/
