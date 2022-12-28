/***************************************************************************
;**
;** FILE NAME      : PWRRLYCMDDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PWRRLYCMDDIAG.H"
#include "PWRRLYCMDDIAG_L.H"
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
const boolean  PwrRly_bInhFctDiag_Man = 0;
const uint8  PWRRLYCMDDIAG_u8Inhib = 0;
const uint16  Diag_relais_bsm_wait_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean PwrRlyHw_bDgoDef;
boolean PwrRlyHw_bDgoOc_PwrRly;
boolean PwrRlyHw_bDgoScg_PwrRly;
boolean PwrRlyHw_bDgoScp_PwrRly;
boolean PwrRlyHw_bDgoStuck_PwrRly;
boolean PwrRlyHw_bMonRunOc_PwrRly;
boolean PwrRlyHw_bMonRunScg_PwrRly;
boolean PwrRlyHw_bMonRunScp_PwrRly;
boolean PwrRlyHw_bMonRunStuck_PwrRly;
uint16 Diag_relais_bsm_wait_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

