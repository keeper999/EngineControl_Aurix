/***************************************************************************
;**
;** FILE NAME      : VLVACTINVLVBENCHMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINVLVBENCHMOD_H
#define VLVACTINVLVBENCHMOD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGCKINSP_PINMNFX_NENGY_M_LNS   ( 16 )
#define VLVACT_AGCKINSP_PINMNFX_NENGY_M_COLS   ( 24 )
#define VLVACT_AGCKINSP_POSNTHRX_NENGY_M_LNS  ( 16 )
#define VLVACT_AGCKINSP_POSNTHRX_NENGY_M_COLS  ( 24 )
#define VLVACT_AGCKINSP_TQAIRX_NENGY_M_LNS    ( 16 )
#define VLVACT_AGCKINSP_TQAIRX_NENGY_M_COLS    ( 24 )
#define VLVACT_NENGY_A_COLS                    ( 24 )
#define VLVACT_PINMNFX_A_COLS                  ( 16 )
#define VLVACT_POSNTHRX_A_COLS                 ( 16 )
#define VLVACT_TQIDCAIRX_A_COLS                ( 16 )

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

extern const boolean  VlvAct_bInVlvSpBenchModEna_C;
extern const boolean  VlvAct_bInVlvSpManSelTyp_C;
extern const boolean  VlvAct_bInVlvSpThrSelTyp_C;
extern const boolean  VlvAct_bInVlvSpTqSelTyp_C;
extern const uint8  VLVACTINVLVBENCHMOD_u8Inhib;
extern const uint16  VlvAct_agCkInBenchModSpMaxRate_C;
extern const uint16  VlvAct_agCkInBenchModSpMinRate_C;
extern const uint16  VlvAct_agCkInSp_pInMnfX_nEngY_M[VLVACT_AGCKINSP_PINMNFX_NENGY_M_LNS][VLVACT_AGCKINSP_PINMNFX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkInSp_posnThrX_nEngY_M[VLVACT_AGCKINSP_POSNTHRX_NENGY_M_LNS][VLVACT_AGCKINSP_POSNTHRX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkInSp_tqAirX_nEngY_M[VLVACT_AGCKINSP_TQAIRX_NENGY_M_LNS][VLVACT_AGCKINSP_TQAIRX_NENGY_M_COLS];
extern const uint16  VlvAct_agCkInVlvBenchModIniSp_C;
extern const uint16  VlvAct_agCkInVlvManModSp_C;
extern const uint16  VlvAct_nEngY_A[VLVACT_NENGY_A_COLS];
extern const uint16  VlvAct_pInMnfX_A[VLVACT_PINMNFX_A_COLS];
extern const uint16  VlvAct_pInVlvAbsDifDB_C;
extern const uint16  VlvAct_posnThrX_A[VLVACT_POSNTHRX_A_COLS];
extern const uint16  VlvAct_tqIdcAirX_A[VLVACT_TQIDCAIRX_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bInVlvSpBenchModEna;
extern uint16 VlvAct_agCkInVlvSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_InVlvSpBenchMod(void);
void VlvAct_SdlFast_InVlvSpBenchMod(void);


#endif /* VLVACTINVLVBENCHMOD_H */

/*-------------------------------- end of file -------------------------------*/
