/***************************************************************************
;**
;** FILE NAME      : ACCPEM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPEM.H"
#include "ACCPEM_L.H"
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
const boolean  AccP_bCycPosPedClc_C = 0;
const boolean  AccP_bInhDiagCoh_C = 0;
const uint8  AccP_tiInhCohTest_C = 0;
const uint8  ACCPEM_u8Inhib = 0;
const uint16  AccPEM_rPosPedCohThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AccP_bDftElAccP;
boolean AccP_bDgoCoh_rAccP;
boolean AccP_bMonRunCoh_rAccP;
boolean ACCPEM_bAcvSaveAccPInvldPrev;
boolean ACCPEM_bFRM_InhDiagCohrAccPrev;
boolean ACCPEM_bRstHwReqAntPrev;
boolean ACCPEM_bRstSwReqAntPrev;
uint8 AccPEM_rAccP;
uint16 AccP_rAccPFinal;
uint16 AccP_rAccPLim;
uint16 AccP_rAccPRobust;
uint16 ACCPEM_u16AccP_tiInhCohTest;
uint16 ACCPEM_u16AccPRAccPSens1Prev;
uint16 ACCPEM_u16AccPRAccPSens1Prev2;
uint16 ACCPEM_u16AccPRAccPSens2Prev;
uint16 ACCPEM_u16AccPRAccPSens2Prev2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

