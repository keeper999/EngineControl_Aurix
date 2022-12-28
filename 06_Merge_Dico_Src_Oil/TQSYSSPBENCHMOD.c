/***************************************************************************
;**
;** FILE NAME      : TQSYSSPBENCHMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQSYSSPBENCHMOD.H"
#include "TQSYSSPBENCHMOD_L.H"
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
const boolean  TqSys_bSelTqSpManModTyp_C = 0;
const boolean  TqSys_bTqSpBenchModEna_C = 0;
const uint8  TqSys_posnAccPY_A[TQSYS_POSNACCPY_A_COLS] = {0};
const uint8  TQSYSSPBENCHMOD_u8Inhib = 0;
const sint16  TqSys_tqIdcAirBenchModIniSp_C = 0;
const sint16  TqSys_tqIdcAirManModSp_C = 0;
const sint16  TqSys_tqIdcIgnBenchModIniSp_C = 0;
const sint16  TqSys_tqIdcIgnManModSp_C = 0;
const uint16  TqSys_nEngX_A[TQSYS_NENGX_A_COLS] = {0};
const uint16  TqSys_tqAirSp_nEngX_posnAccPY_M[TQSYS_TQAIRSP_NENGX_POSNACCPY_M_LNS][TQSYS_TQAIRSP_NENGX_POSNACCPY_M_COLS] = {0};
const uint16  TqSys_tqIdcAirMaxRate_C = 0;
const uint16  TqSys_tqIdcAirMinRate_C = 0;
const uint16  TqSys_tqIdcIgnMaxRate_C = 0;
const uint16  TqSys_tqIdcIgnMinRate_C = 0;
const uint16  TqSys_tqIgnSp_nEngX_posnAccPY_M[TQSYS_TQIGNSP_NENGX_POSNACCPY_M_LNS][TQSYS_TQIGNSP_NENGX_POSNACCPY_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TqSys_bSelTqSpManModTyp;
boolean TqSys_bTqSpBenchModEna;
sint16 TqSys_tqIdcAirSpBenchMod;
sint16 TqSys_tqIdcIgnSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

