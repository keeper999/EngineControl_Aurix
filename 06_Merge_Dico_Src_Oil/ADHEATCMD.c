/***************************************************************************
;**
;** FILE NAME      : ADHEATCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADHEATCMD.H"
#include "ADHEATCMD_L.H"
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
const boolean  AdHeatCmd_bInvReq_C = 0;
const uint8  ADHEATCMD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AC_bDgoOc_CTP1;
boolean AC_bDgoOc_CTP2;
boolean AC_bDgoScg_CTP1;
boolean AC_bDgoScg_CTP2;
boolean AC_bDgoScp_CTP1;
boolean AC_bDgoScp_CTP2;
boolean AC_bMonRunOc_CTP1;
boolean AC_bMonRunOc_CTP2;
boolean AC_bMonRunScg_CTP1;
boolean AC_bMonRunScg_CTP2;
boolean AC_bMonRunScp_CTP1;
boolean AC_bMonRunScp_CTP2;
boolean AdHeatCmd_bAcvCTP1;
boolean AdHeatCmd_bAcvCTP2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

