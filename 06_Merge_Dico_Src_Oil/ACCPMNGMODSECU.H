/***************************************************************************
;**
;** FILE NAME      : ACCPMNGMODSECU.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPMNGMODSECU_H
#define ACCPMNGMODSECU_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AccP_SampleTiFast_SC              10

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st99 */
#define AccP_stNomMode_SC                 0
#define AccP_stNomDegMode_SC              2
#define AccP_stDegMode_SC                 4
#define AccP_stDegPctlMode_SC             8
#define AccP_stDegSen1Mode_SC             16
#define AccP_stDegSen2Mode_SC             32
#define AccP_stStuckMode_SC               64
#define AccP_stSubstMode_SC               128
/*extern uint8 AccP_stAccPSec;*/

/* enum st100 */
#define AccP_stVldNomMode_SC              0
#define AccP_stVldDegMode_SC              1
#define AccP_stVldSubstMode_SC            2
#define AccP_stVldStuckMode_SC            3
/*extern uint8 AccP_stAccPVld;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  AccP_bAccPCohDegMod_C;
extern const uint16  AccP_rAccPMaxDec_C;
extern const uint16  AccP_rAccPMaxInc_C;
extern const uint16  AccP_rAccPRampFault_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 AccP_stAccPSec;
extern uint8 AccP_stAccPVld;
extern uint16 AccP_rAccPFctMon;
extern uint16 Ssm_precise_pedal_position;
extern sint32 AccP_rGrdAccP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveRst_AccPMngModSec(void);
void AccP_SdlFast_AccPMngModSec(void);


#endif /* ACCPMNGMODSECU_H */

/*-------------------------------- end of file -------------------------------*/
