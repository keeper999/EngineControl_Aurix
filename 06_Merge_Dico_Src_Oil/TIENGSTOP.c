/***************************************************************************
;**
;** FILE NAME      : TIENGSTOP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TIENGSTOP.H"
#include "TIENGSTOP_L.H"
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
const boolean  EngSt_bAcvChgMind_C = 0;
const boolean  EngSt_bAcvTairCANModDftSel_C = 0;
const uint8  EngSt_ctCohRx552Thd_C = 0;
const uint8  EngSt_nThdHiChgMind_C = 0;
const uint8  EngSt_tAir_AX[ENGST_TAIR_AX_COLS] = {0};
const uint8  EngSt_tCoMes_AY[ENGST_TCOMES_AY_COLS] = {0};
const uint8  TIENGSTOP_u8Inhib = 0;
const sint16  EngSt_tDeltaThd_C = 0;
const uint16  EngSt_tiEngStopDft_M[ENGST_TIENGSTOPDFT_M_LNS][ENGST_TIENGSTOPDFT_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Date_emf_dem_calcule;
boolean Date_emf_init_time_since_stall;
boolean EngSt_bAcvChangeOfMind;
boolean EngSt_bDetEngStallSTT;
boolean EngSt_bDiagCohCtTi;
boolean EngSt_bTramTairCANVal;
boolean EOM_bDgoCoh_tiEngStop;
boolean EOM_bDgoORng_tiEngStop;
boolean EOM_bMonRunCoh_tiEngStop;
boolean EOM_bMonRunORng_tiEngStop;
boolean TIENGSTOP_bWkuMainPrev;
uint32 Date_emf_arret_s;
uint32 Date_emf_reveil_s;
uint32 EngSt_ctSec_buff_0;
uint32 EngSt_ctSec_buff_1;
uint32 EngSt_ctSec_buff_2;
uint32 EOM_tiEngStopDft;
uint32 Time_since_stall;
uint8 Date_emf_arret_a;
uint8 Date_emf_reveil_a;
uint8 EngSt_ctYr_buff_0;
uint8 EngSt_ctYr_buff_1;
uint8 EngSt_ctYr_buff_2;
uint8 TIENGSTOP_u8CoPTStEngPrev;
uint8 TIENGSTOP_u8CtTiIndex;
sint16 EngSt_tAirMesSel;
sint16 TIENGSTOP_s16TCoMesDelta;
uint16 Date_emf_arret_j;
uint16 Date_emf_reveil_j;
uint16 EngSt_ctDay_buff_0;
uint16 EngSt_ctDay_buff_1;
uint16 EngSt_ctDay_buff_2;
uint16 EngSt_tiEngStopDft;
uint16 TIENGSTOP_u16Ext_nEngPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

