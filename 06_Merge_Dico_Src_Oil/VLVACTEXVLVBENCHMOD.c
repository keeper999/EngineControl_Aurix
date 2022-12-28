/***************************************************************************
;**
;** FILE NAME      : VLVACTEXVLVBENCHMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXVLVBENCHMOD.H"
#include "VLVACTEXVLVBENCHMOD_L.H"
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
const boolean  VlvAct_bExVlvSpBenchModEna_C = 0;
const boolean  VlvAct_bExVlvSpManSelTyp_C = 0;
const boolean  VlvAct_bExVlvSpThrSelTyp_C = 0;
const boolean  VlvAct_bExVlvSpTqSelTyp_C = 0;
const uint8  VLVACTEXVLVBENCHMOD_u8Inhib = 0;
const uint16  VlvAct_agCkExBenchModSpMaxRate_C = 0;
const uint16  VlvAct_agCkExBenchModSpMinRate_C = 0;
const uint16  VlvAct_agCkExSp_pInMnfX_nEngY_M[VLVACT_AGCKEXSP_PINMNFX_NENGY_M_LNS][VLVACT_AGCKEXSP_PINMNFX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkExSp_posnThrX_nEngY_M[VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_LNS][VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkExSp_tqAirX_nEngY_M[VLVACT_AGCKEXSP_TQAIRX_NENGY_M_LNS][VLVACT_AGCKEXSP_TQAIRX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkExVlvBenchModIniSp_C = 0;
const uint16  VlvAct_agCkExVlvManModSp_C = 0;
const uint16  VlvAct_pExVlvAbsDifDB_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bExVlvSpBenchModEna;
uint16 VlvAct_agCkExVlvBenchModPrevSp;
uint16 VlvAct_agCkExVlvSpBenchMod;
uint16 VLVACTEXVLVBENCHMOD_u16IoFldPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

