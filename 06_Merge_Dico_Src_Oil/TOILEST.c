/***************************************************************************
;**
;** FILE NAME      : TOILEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TOILEST.H"
#include "TOILEST_L.H"
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
const sint8  Eng_tAirVldMax_C = 0;
const uint8  Eng_rCorTOilIni_T[ENG_RCORTOILINI_T_COLS] = {0};
const uint8  Eng_rSpdFanTOilEngStop_A[ENG_RSPDFANTOILENGSTOP_A_COLS] = {0};
const uint8  Eng_rTOilIni_C = 0;
const uint8  Eng_spdVehTOilCorExtCnd_A[ENG_SPDVEHTOILCOREXTCND_A_COLS] = {0};
const uint8  Eng_spdVehTOilEngStop_A[ENG_SPDVEHTOILENGSTOP_A_COLS] = {0};
const uint8  Eng_tDeltaTOilCorExtCnd_A[ENG_TDELTATOILCOREXTCND_A_COLS] = {0};
const uint8  Eng_tDeltaTOilEngStop_A[ENG_TDELTATOILENGSTOP_A_COLS] = {0};
const uint8  Eng_tiInvldTAirMax_C = 0;
const uint8  Eng_tOilCorEngCh_M[ENG_TOILCORENGCH_M_LNS][ENG_TOILCORENGCH_M_COLS] = {0};
const uint8  Eng_tOilCorEngRun_A[ENG_TOILCORENGRUN_A_COLS] = {0};
const uint8  Eng_tOilCorEngRun_T[ENG_TOILCORENGRUN_T_COLS] = {0};
const uint8  Eng_tOilCorExtCnd_M[ENG_TOILCOREXTCND_M_LNS][ENG_TOILCOREXTCND_M_COLS] = {0};
const uint8  Eng_tOilEngStopSpdFan_M[ENG_TOILENGSTOPSPDFAN_M_LNS][ENG_TOILENGSTOPSPDFAN_M_COLS] = {0};
const uint8  Eng_tOilEngStopSpdVeh_M[ENG_TOILENGSTOPSPDVEH_M_LNS][ENG_TOILENGSTOPSPDVEH_M_COLS] = {0};
const uint8  Eng_tOilEngStopTCo_A[ENG_TOILENGSTOPTCO_A_COLS] = {0};
const uint8  Eng_tOilEngStopTCo_T[ENG_TOILENGSTOPTCO_T_COLS] = {0};
const uint8  Eng_tOilEstimIncMax_C = 0;
const uint8  Eng_tOilWaPmp_A[ENG_TOILWAPMP_A_COLS] = {0};
const uint8  Eng_tOilWaPmpOff_T[ENG_TOILWAPMPOFF_T_COLS] = {0};
const uint8  Eng_tOilWaPmpOn_T[ENG_TOILWAPMPON_T_COLS] = {0};
const uint8  TOILEST_u8Inhib = 0;
const sint16  Eng_tOilEstimDecMax_C = 0;
const sint16  Eng_tOilEstimMax_C = 0;
const sint16  Eng_tOilIni_C = 0;
const uint16  Eng_nEngTOilCorEngCh_A[ENG_NENGTOILCORENGCH_A_COLS] = {0};
const uint16  Eng_rAirLdTOilCorEngCh_A[ENG_RAIRLDTOILCORENGCH_A_COLS] = {0};
const uint16  Eng_rCorTOilIni_A[ENG_RCORTOILINI_A_COLS] = {0};
const uint16  Eng_tiFilTOilEngRun_A[ENG_TIFILTOILENGRUN_A_COLS] = {0};
const uint16  Eng_tiFilTOilEngRun_T[ENG_TIFILTOILENGRUN_T_COLS] = {0};
const uint16  Eng_tiFilTOilEngStop_C = 0;
const uint16  Eng_tOilEstimDft_A[ENG_TOILESTIMDFT_A_COLS] = {0};
const uint16  Eng_tOilEstimDft_T[ENG_TOILESTIMDFT_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Eng_bDgoORngHiTOilEstim;
boolean Eng_bIniTOil;
boolean Eng_bMonRunORngTOilEstim;
boolean Eng_bTOilChk;
boolean TOILEST_btOilEstEngRunRstPrev;
boolean TOILEST_btOilEstEngStopRstPrev;
uint8 Eng_stTOilCalc;
uint8 Eng_tiInvldTAir;
uint8 TOILEST_u8DeltaEngTOilExtTAir;
sint16 Eng_tOilCorEngCh_MP;
sint16 Eng_tOilCorEngRun_MP;
sint16 Eng_tOilCorExtCnd_MP;
sint16 Eng_tOilEstimEngRun;
sint16 Eng_tOilEstimEngRunRaw;
sint16 Eng_tOilEstimEngStopRaw_MP;
sint16 Eng_tOilEstimIni;
sint16 Eng_tOilEstimIni1_MP;
sint16 Eng_tOilEstimIni2_MP;
sint16 Eng_tOilEstimIni3_MP;
sint16 Eng_tOilEstimPrec;
sint16 Eng_tOilEstimRaw;
sint16 Eng_tOilWaPmpOff_MP;
sint16 Eng_tOilWaPmpOn_MP;
uint16 Eng_rCorTOilIni_MP;
uint16 Eng_tiFilTOilEngRun_MP;
sint32 Eng_tOilEngRunFil_MP;
sint32 Eng_tOilEstimEngStop;
sint32 TOILEST_s32tOilEngRunFiltMem;
sint32 TOILEST_s32tOilEstEngStopFiltMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

