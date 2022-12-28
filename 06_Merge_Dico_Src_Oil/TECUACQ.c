/***************************************************************************
;**
;** FILE NAME      : TECUACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TECUACQ.H"
#include "TECUACQ_L.H"
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
const uint8  SenAct_tECUIni_C = 0;
const uint8  SenAct_utECU_T[SENACT_UTECU_T_COLS] = {0};
const uint8  TECUACQ_u8Inhib = 0;
const uint16  SenAct_tECUAcq_utECUMes_A[SENACT_TECUACQ_UTECUMES_A_COLS] = {0};
const uint16  SenAct_uDgoScg_tECUAcq_C = 0;
const uint16  SenAct_uDgoScp_tECUAcq_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean SenAct_bDgoScg_tECUAcq;
boolean SenAct_bDgoScp_tECUAcq;
boolean SenAct_bMonRunScg_tECUAcq;
boolean SenAct_bMonRunScp_tECUAcq;
uint8 SenAct_tECUAcq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

