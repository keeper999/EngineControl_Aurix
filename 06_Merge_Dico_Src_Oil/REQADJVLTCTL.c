/***************************************************************************
;**
;** FILE NAME      : REQADJVLTCTL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "REQADJVLTCTL.H"
#include "REQADJVLTCTL_L.H"
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
const boolean  LsSys_bEnaLsDs_AdjuBattNom_C = 0;
const boolean  LsSys_bEnaLsUs_AdjuBattNom_C = 0;
const boolean  LsSys_bLsDsMainOxCHeatModeReq_M[LSSYS_BLSDSMAINOXCHEATMODEREQ_M_COLS] = {0};
const boolean  LsSys_bLsUsMainOxCHeatModeReq_M[LSSYS_BLSUSMAINOXCHEATMODEREQ_M_COLS] = {0};
const uint8  LsSys_LsDsMainOxCHeatModeReq_T[LSSYS_LSDSMAINOXCHEATMODEREQ_T_COLS] = {0};
const uint8  LsSys_LsUsMainOxCHeatModeReq_T[LSSYS_LSUSMAINOXCHEATMODEREQ_T_COLS] = {0};
const uint8  REQADJVLTCTL_u8Inhib = 0;
const uint16  LsSys_uBatt2LsDsMainOxCRef_C = 0;
const uint16  LsSys_uBatt2LsDsMainOxCThd_C = 0;
const uint16  LsSys_uBatt2LsUsMainOxCRef_C = 0;
const uint16  LsSys_uBatt2LsUsMainOxCThd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean LsSys_bAcv_stLsDsMainOxC;
boolean LsSys_bAcv_stLsUsMainOxC;
boolean LsSys_bAdj_uBattNom;
boolean LsSys_bComp_uBatt2LsDsMainOxC;
boolean LsSys_bComp_uBatt2LsUsMainOxC;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

