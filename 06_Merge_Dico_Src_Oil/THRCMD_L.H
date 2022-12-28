/***************************************************************************
;**
;** FILE NAME      : THRCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRCMD_L_H
#define THRCMD_L_H

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

extern const uint8  THRCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bDgoCpt_ThrCmd;
extern boolean Thr_bDgoOvld_ThrCmd;
extern boolean Thr_bMonRunCpt_ThrCmd;
extern boolean Thr_bMonRunOvld_ThrCmd;
extern boolean Tpc_throt_on_off_request;
extern uint32 ThrCmd_tiFreeWheeling;
extern sint16 Tpac_throt_duty_cycle_to_apply;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRCMD_vidCommandTpac(void);
void THRCMD_vidComptagePanne(void);
void THRCMD_vidDriverInh(void);
void THRCMD_vidInitOutput(void);


#endif /* THRCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
