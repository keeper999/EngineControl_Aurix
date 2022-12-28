/***************************************************************************
;**
;** FILE NAME      : THRBENCHMODE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "THRBENCHMODE.H"
#include "THRBENCHMODE_L.H"
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
const boolean  Thr_bAcvSpBenchMod_C = 0;
const uint8  THRBENCHMODE_u8Inhib = 0;
const uint16  Thr_nEngX_A[THR_NENGX_A_COLS] = {0};
const uint16  Thr_posnSp_nEngX_tqIdcAirY_M[THR_POSNSP_NENGX_TQIDCAIRY_M_LNS][THR_POSNSP_NENGX_TQIDCAIRY_M_COLS] = {0};
const uint16  Thr_posnSpBenchModMaxRate_C = 0;
const uint16  Thr_posnSpBenchModMinRate_C = 0;
const uint16  Thr_tqIdcAirY_A[THR_TQIDCAIRY_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Thr_bAcvSpBenchMod;
uint16 Thr_posnSpBenchMod;
uint16 Thr_posnSpBenchMod_NotFil;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

