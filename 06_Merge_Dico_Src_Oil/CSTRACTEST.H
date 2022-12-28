/***************************************************************************
;**
;** FILE NAME      : CSTRACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRACTEST_H
#define CSTRACTEST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Cstr_SampleTiMid_SC               100

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

extern const uint8  ActrTstCstr_OffTime;
extern const uint8  ActrTstCstr_OnTime;
extern const uint8  CSTRACTEST_u8Inhib;
extern const uint16  ActrTstCstr_Tempo_C;
extern const uint16  ActrTstCstr_TotTime;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cstr_bPurgTstCmpl;
extern boolean Cstr_bPwrRlyCmd;
extern uint8 Cstr_rSpPosnActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cstr_EveRst_ActrTstCstr(void);
void Cstr_SdlMid_ActrTstCstr(void);


#endif /* CSTRACTEST_H */

/*-------------------------------- end of file -------------------------------*/
