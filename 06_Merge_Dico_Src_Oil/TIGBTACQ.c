/***************************************************************************
;**
;** FILE NAME      : TIGBTACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TIGBTACQ.H"
#include "TIGBTACQ_L.H"
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
const uint8  SenAct_tIGBTIni_C = 0;
const uint8  SenAct_utIGBT_T[SENACT_UTIGBT_T_COLS] = {0};
const uint8  TIGBTACQ_u8Inhib = 0;
const uint16  SenAct_tIGBTAcq_utIGBTMes_A[SENACT_TIGBTACQ_UTIGBTMES_A_COLS] = {0};
const uint16  SenAct_uDgoScg_tIGBTAcq_C = 0;
const uint16  SenAct_uDgoScp_tIGBTAcq_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean SenAct_bDgoScg_tIGBTAcq;
boolean SenAct_bDgoScp_tIGBTAcq;
boolean SenAct_bMonRunScg_tIGBTAcq;
boolean SenAct_bMonRunScp_tIGBTAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

