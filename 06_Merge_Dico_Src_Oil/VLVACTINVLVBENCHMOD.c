/***************************************************************************
;**
;** FILE NAME      : VLVACTINVLVBENCHMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINVLVBENCHMOD.H"
#include "VLVACTINVLVBENCHMOD_L.H"
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
const boolean  VlvAct_bInVlvSpBenchModEna_C = 0;
const boolean  VlvAct_bInVlvSpManSelTyp_C = 0;
const boolean  VlvAct_bInVlvSpThrSelTyp_C = 0;
const boolean  VlvAct_bInVlvSpTqSelTyp_C = 0;
const uint8  VLVACTINVLVBENCHMOD_u8Inhib = 0;
const uint16  VlvAct_agCkInBenchModSpMaxRate_C = 0;
const uint16  VlvAct_agCkInBenchModSpMinRate_C = 0;
const uint16  VlvAct_agCkInSp_pInMnfX_nEngY_M[VLVACT_AGCKINSP_PINMNFX_NENGY_M_LNS][VLVACT_AGCKINSP_PINMNFX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkInSp_posnThrX_nEngY_M[VLVACT_AGCKINSP_POSNTHRX_NENGY_M_LNS][VLVACT_AGCKINSP_POSNTHRX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkInSp_tqAirX_nEngY_M[VLVACT_AGCKINSP_TQAIRX_NENGY_M_LNS][VLVACT_AGCKINSP_TQAIRX_NENGY_M_COLS] = {0};
const uint16  VlvAct_agCkInVlvBenchModIniSp_C = 0;
const uint16  VlvAct_agCkInVlvManModSp_C = 0;
const uint16  VlvAct_nEngY_A[VLVACT_NENGY_A_COLS] = {0};
const uint16  VlvAct_pInMnfX_A[VLVACT_PINMNFX_A_COLS] = {0};
const uint16  VlvAct_pInVlvAbsDifDB_C = 0;
const uint16  VlvAct_posnThrX_A[VLVACT_POSNTHRX_A_COLS] = {0};
const uint16  VlvAct_tqIdcAirX_A[VLVACT_TQIDCAIRX_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvAct_bInVlvSpBenchModEna;
uint16 VlvAct_agCkInVlvBenchModPrevSp;
uint16 VlvAct_agCkInVlvSpBenchMod;
uint16 VLVACTINVLVBENCHMOD_u16IoFldPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

