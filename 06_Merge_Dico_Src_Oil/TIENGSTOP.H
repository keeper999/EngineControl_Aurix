/***************************************************************************
;**
;** FILE NAME      : TIENGSTOP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TIENGSTOP_H
#define TIENGSTOP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGST_TAIR_AX_COLS                     ( 10 )
#define ENGST_TCOMES_AY_COLS                   ( 10 )
#define ENGST_TIENGSTOPDFT_M_LNS              ( 10 )
#define ENGST_TIENGSTOPDFT_M_COLS              ( 10 )

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

extern const boolean  EngSt_bAcvChgMind_C;
extern const boolean  EngSt_bAcvTairCANModDftSel_C;
extern const uint8  EngSt_ctCohRx552Thd_C;
extern const uint8  EngSt_nThdHiChgMind_C;
extern const uint8  EngSt_tAir_AX[ENGST_TAIR_AX_COLS];
extern const uint8  EngSt_tCoMes_AY[ENGST_TCOMES_AY_COLS];
extern const sint16  EngSt_tDeltaThd_C;
extern const uint16  EngSt_tiEngStopDft_M[ENGST_TIENGSTOPDFT_M_LNS][ENGST_TIENGSTOPDFT_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean EngSt_bAcvChangeOfMind;
extern uint32 EOM_tiEngStopDft;
extern uint32 Time_since_stall;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Can_EveRxn5B2_TiEngStop(void);
void Can_EveRxn7F2_TiEngStop(void);
void EngSt_EvePwrl_TiEngStop(void);
void EngSt_EveRst_TiEngStop(void);
void EngSt_EveRTSt_TiEngStop(void);
void EngSt_EveRxn552_TiEngStop(void);
void EngSt_EveRxn552bis_TiEngStop(void);
void EngSt_SdlFast_TiEngStop(void);
void EngSt_SdlMid_TiEngStop(void);
void EngSt_SdlSlow_TiEngStop(void);


#endif /* TIENGSTOP_H */

/*-------------------------------- end of file -------------------------------*/
