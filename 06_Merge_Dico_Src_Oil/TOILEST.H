/***************************************************************************
;**
;** FILE NAME      : TOILEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TOILEST_H
#define TOILEST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENG_NENGTOILCORENGCH_A_COLS            ( 12 )
#define ENG_RAIRLDTOILCORENGCH_A_COLS          ( 12 )
#define ENG_RCORTOILINI_A_COLS                 ( 12 )
#define ENG_RCORTOILINI_T_COLS                 ( 12 )
#define ENG_RSPDFANTOILENGSTOP_A_COLS          ( 8 )
#define ENG_SPDVEHTOILCOREXTCND_A_COLS         ( 8 )
#define ENG_SPDVEHTOILENGSTOP_A_COLS           ( 8 )
#define ENG_TDELTATOILCOREXTCND_A_COLS         ( 8 )
#define ENG_TDELTATOILENGSTOP_A_COLS           ( 8 )
#define ENG_TIFILTOILENGRUN_A_COLS             ( 16 )
#define ENG_TIFILTOILENGRUN_T_COLS             ( 16 )
#define ENG_TOILCORENGCH_M_LNS                ( 12 )
#define ENG_TOILCORENGCH_M_COLS                ( 12 )
#define ENG_TOILCORENGRUN_A_COLS               ( 8 )
#define ENG_TOILCORENGRUN_T_COLS               ( 8 )
#define ENG_TOILCOREXTCND_M_LNS               ( 8 )
#define ENG_TOILCOREXTCND_M_COLS               ( 8 )
#define ENG_TOILENGSTOPSPDFAN_M_LNS           ( 8 )
#define ENG_TOILENGSTOPSPDFAN_M_COLS           ( 8 )
#define ENG_TOILENGSTOPSPDVEH_M_LNS           ( 8 )
#define ENG_TOILENGSTOPSPDVEH_M_COLS           ( 8 )
#define ENG_TOILENGSTOPTCO_A_COLS              ( 8 )
#define ENG_TOILENGSTOPTCO_T_COLS              ( 8 )
#define ENG_TOILESTIMDFT_A_COLS                ( 8 )
#define ENG_TOILESTIMDFT_T_COLS                ( 8 )
#define ENG_TOILWAPMP_A_COLS                   ( 16 )
#define ENG_TOILWAPMPOFF_T_COLS                ( 16 )
#define ENG_TOILWAPMPON_T_COLS                 ( 16 )

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

extern const sint8  Eng_tAirVldMax_C;
extern const uint8  Eng_rCorTOilIni_T[ENG_RCORTOILINI_T_COLS];
extern const uint8  Eng_rSpdFanTOilEngStop_A[ENG_RSPDFANTOILENGSTOP_A_COLS];
extern const uint8  Eng_rTOilIni_C;
extern const uint8  Eng_spdVehTOilCorExtCnd_A[ENG_SPDVEHTOILCOREXTCND_A_COLS];
extern const uint8  Eng_spdVehTOilEngStop_A[ENG_SPDVEHTOILENGSTOP_A_COLS];
extern const uint8  Eng_tDeltaTOilCorExtCnd_A[ENG_TDELTATOILCOREXTCND_A_COLS];
extern const uint8  Eng_tDeltaTOilEngStop_A[ENG_TDELTATOILENGSTOP_A_COLS];
extern const uint8  Eng_tiInvldTAirMax_C;
extern const uint8  Eng_tOilCorEngCh_M[ENG_TOILCORENGCH_M_LNS][ENG_TOILCORENGCH_M_COLS];
extern const uint8  Eng_tOilCorEngRun_A[ENG_TOILCORENGRUN_A_COLS];
extern const uint8  Eng_tOilCorEngRun_T[ENG_TOILCORENGRUN_T_COLS];
extern const uint8  Eng_tOilCorExtCnd_M[ENG_TOILCOREXTCND_M_LNS][ENG_TOILCOREXTCND_M_COLS];
extern const uint8  Eng_tOilEngStopSpdFan_M[ENG_TOILENGSTOPSPDFAN_M_LNS][ENG_TOILENGSTOPSPDFAN_M_COLS];
extern const uint8  Eng_tOilEngStopSpdVeh_M[ENG_TOILENGSTOPSPDVEH_M_LNS][ENG_TOILENGSTOPSPDVEH_M_COLS];
extern const uint8  Eng_tOilEngStopTCo_A[ENG_TOILENGSTOPTCO_A_COLS];
extern const uint8  Eng_tOilEngStopTCo_T[ENG_TOILENGSTOPTCO_T_COLS];
extern const uint8  Eng_tOilEstimIncMax_C;
extern const uint8  Eng_tOilWaPmp_A[ENG_TOILWAPMP_A_COLS];
extern const uint8  Eng_tOilWaPmpOff_T[ENG_TOILWAPMPOFF_T_COLS];
extern const uint8  Eng_tOilWaPmpOn_T[ENG_TOILWAPMPON_T_COLS];
extern const sint16  Eng_tOilEstimDecMax_C;
extern const sint16  Eng_tOilEstimMax_C;
extern const sint16  Eng_tOilIni_C;
extern const uint16  Eng_nEngTOilCorEngCh_A[ENG_NENGTOILCORENGCH_A_COLS];
extern const uint16  Eng_rAirLdTOilCorEngCh_A[ENG_RAIRLDTOILCORENGCH_A_COLS];
extern const uint16  Eng_rCorTOilIni_A[ENG_RCORTOILINI_A_COLS];
extern const uint16  Eng_tiFilTOilEngRun_A[ENG_TIFILTOILENGRUN_A_COLS];
extern const uint16  Eng_tiFilTOilEngRun_T[ENG_TIFILTOILENGRUN_T_COLS];
extern const uint16  Eng_tiFilTOilEngStop_C;
extern const uint16  Eng_tOilEstimDft_A[ENG_TOILESTIMDFT_A_COLS];
extern const uint16  Eng_tOilEstimDft_T[ENG_TOILESTIMDFT_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eng_bDgoORngHiTOilEstim;
extern boolean Eng_bMonRunORngTOilEstim;
extern boolean Eng_bTOilChk;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Eng_EveIni_tOilEstim(void);
void Eng_EvePwL_tOilEstim(void);
void Eng_Sdl100ms_tOilEstim(void);


#endif /* TOILEST_H */

/*-------------------------------- end of file -------------------------------*/
