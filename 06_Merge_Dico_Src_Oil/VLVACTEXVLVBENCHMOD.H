/***************************************************************************
;**
;** FILE NAME      : VLVACTEXVLVBENCHMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXVLVBENCHMOD_H
#define VLVACTEXVLVBENCHMOD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGCKEXSP_PINMNFX_NENGY_M_LNS   ( 16 )
#define VLVACT_AGCKEXSP_PINMNFX_NENGY_M_COLS   ( 24 )
#define VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_LNS  ( 16 )
#define VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_COLS  ( 24 )
#define VLVACT_AGCKEXSP_TQAIRX_NENGY_M_LNS    ( 16 )
#define VLVACT_AGCKEXSP_TQAIRX_NENGY_M_COLS    ( 24 )

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

extern const boolean  VlvAct_bExVlvSpBenchModEna_C;
extern const boolean  VlvAct_bExVlvSpManSelTyp_C;
extern const boolean  VlvAct_bExVlvSpThrSelTyp_C;
extern const boolean  VlvAct_bExVlvSpTqSelTyp_C;
extern const uint8  VLVACTEXVLVBENCHMOD_u8Inhib;
extern const uint16  VlvAct_agCkExBenchModSpMaxRate_C;
extern const uint16  VlvAct_agCkExBenchModSpMinRate_C;
extern const uint16  VlvAct_agCkExSp_pInMnfX_nEngY_M[VLVACT_AGCKEXSP_PINMNFX_NENGY_M_LNS][VLVACT_AGCKEXSP_PINMNFX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkExSp_posnThrX_nEngY_M[VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_LNS][VLVACT_AGCKEXSP_POSNTHRX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkExSp_tqAirX_nEngY_M[VLVACT_AGCKEXSP_TQAIRX_NENGY_M_LNS][VLVACT_AGCKEXSP_TQAIRX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkExVlvBenchModIniSp_C;
extern const uint16  VlvAct_agCkExVlvManModSp_C;
extern const uint16  VlvAct_pExVlvAbsDifDB_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bExVlvSpBenchModEna;
extern uint16 VlvAct_agCkExVlvSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_ExVlvSpBenchMod(void);
void VlvAct_SdlFast_ExVlvSpBenchMod(void);


#endif /* VLVACTEXVLVBENCHMOD_H */

/*-------------------------------- end of file -------------------------------*/
