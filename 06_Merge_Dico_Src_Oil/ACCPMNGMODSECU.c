/***************************************************************************
;**
;** FILE NAME      : ACCPMNGMODSECU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPMNGMODSECU.H"
#include "ACCPMNGMODSECU_L.H"
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
const boolean  AccP_bAccPCohDegMod_C = 0;
const uint8  ACCPMNGMODSECU_u8Inhib = 0;
const uint16  AccP_rAccPMaxDec_C = 0;
const uint16  AccP_rAccPMaxInc_C = 0;
const uint16  AccP_rAccPRampFault_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 AccP_stAccPSec;
uint8 AccP_stAccPVld;
boolean AccP_bCohPctl;
boolean AccP_bCohPSenPctl;
boolean AccP_bPsenNoBoothDftEl;
boolean AccP_bPsenNoDftEl;
boolean AccP_bPsenOneDftEl;
boolean AccP_bPsenPctlEl;
uint16 AccP_rAccPFctMon;
uint16 AccP_rAccPFctMonPrev;
uint16 AccP_rAccPPrev;
uint16 AccP_rAccPRaw;
uint16 AccP_rAccPSens1Prev;
uint16 AccP_rAccPSens2Prev;
uint16 ACCPMNGMODSECU_u16AccPRawFilter;
uint16 Ssm_precise_pedal_position;
sint32 AccP_rGrdAccP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

