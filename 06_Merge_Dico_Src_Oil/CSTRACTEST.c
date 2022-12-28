/***************************************************************************
;**
;** FILE NAME      : CSTRACTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CSTRACTEST.H"
#include "CSTRACTEST_L.H"
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
const uint8  ActrTstCstr_OffTime = 0;
const uint8  ActrTstCstr_OnTime = 0;
const uint8  CSTRACTEST_u8Inhib = 0;
const uint16  ActrTstCstr_Tempo_C = 0;
const uint16  ActrTstCstr_TotTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Cstr_stActrTst;
boolean Cstr_bPurgTstCmpl;
boolean Cstr_bPwrRlyCmd;
uint8 ActrTstCstr_IntTime;
uint8 Cstr_rSpPosnActrTst;
uint16 ActrTstCstr_CumulTime;
uint16 ActrTstCstr_Tempo;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

