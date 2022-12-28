/***************************************************************************
;**
;** FILE NAME      : INAIRFLOWDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "INAIRFLOWDIAG.H"
#include "INAIRFLOWDIAG_L.H"
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
const uint8  AirSys_rClsThdThr_C = 0;
const uint8  AirSys_rpDsUsThr_C = 0;
const uint8  INAIRFLOWDIAG_u8Inhib = 0;
const sint16  AirSys_tCoMes_C = 0;
const uint16  AirSys_nEng_C = 0;
const uint16  AirSys_pDsThrLeak1_T[AIRSYS_PDSTHRLEAK1_T_COLS] = {0};
const uint16  AirSys_pDsThrLeak2_T[AIRSYS_PDSTHRLEAK2_T_COLS] = {0};
const uint16  AirSys_pDsThrLeak3_C = 0;
const uint16  AirSys_pDsThrLeak4_C = 0;
const uint16  EngM_mfTotExCor_A[ENGM_MFTOTEXCOR_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirSys_bDgoBoost1_pDsThr;
boolean AirSys_bDgoBoost2_pDsThr;
boolean AirSys_bDgoBoost3_pDsThr;
boolean AirSys_bDgoBoost4_pDsThr;
boolean AirSys_bMonRunBoost1_pDsThr;
boolean AirSys_bMonRunBoost2_pDsThr;
boolean AirSys_bMonRunBoost3_pDsThr;
boolean AirSys_bMonRunBoost4_pDsThr;
uint16 AirSys_pDsThrLeak1;
uint16 AirSys_pDsThrLeak2;
uint16 AirSys_rCohMnfMfBoost;
uint16 AirSys_rCohMnfMfBoostDeac;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

