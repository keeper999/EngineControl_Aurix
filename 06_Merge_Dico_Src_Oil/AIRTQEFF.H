/***************************************************************************
;**
;** FILE NAME      : AIRTQEFF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTQEFF_H
#define AIRTQEFF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRSYS_EFFAFR_T_COLS                   ( 9 )
#define AIRSYS_EFFEGR_T_COLS                   ( 9 )
#define AIRSYS_NENGEFFCYC_A_COLS               ( 16 )
#define AIRSYS_NENGEFFCYCSHO_A_COLS            ( 8 )
#define AIRSYS_NENGEFFCYCSHOIDL_A_COLS         ( 8 )
#define AIRSYS_RAIRLDEFFCYC_A_COLS             ( 8 )
#define AIRSYS_REGR_A_COLS                     ( 9 )
#define AIRSYS_TQIDCHPCAL1_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL1_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL10_M_LNS             ( 8 )
#define AIRSYS_TQIDCHPCAL10_M_COLS             ( 8 )
#define AIRSYS_TQIDCHPCAL11_M_LNS             ( 8 )
#define AIRSYS_TQIDCHPCAL11_M_COLS             ( 8 )
#define AIRSYS_TQIDCHPCAL12_M_LNS             ( 8 )
#define AIRSYS_TQIDCHPCAL12_M_COLS             ( 8 )
#define AIRSYS_TQIDCHPCAL13_M_LNS             ( 8 )
#define AIRSYS_TQIDCHPCAL13_M_COLS             ( 8 )
#define AIRSYS_TQIDCHPCAL14_M_LNS             ( 8 )
#define AIRSYS_TQIDCHPCAL14_M_COLS             ( 8 )
#define AIRSYS_TQIDCHPCAL2_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL2_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL3_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL3_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL4_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL4_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL5_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL5_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL6_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL6_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL7_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL7_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL8_M_LNS              ( 16 )
#define AIRSYS_TQIDCHPCAL8_M_COLS              ( 8 )
#define AIRSYS_TQIDCHPCAL9_M_LNS              ( 8 )
#define AIRSYS_TQIDCHPCAL9_M_COLS              ( 8 )
#define INJ_RLAMENG_A_COLS                     ( 9 )

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

extern const boolean  AirSys_bFlexEffAfr_C;
extern const boolean  AirSys_bFlexEffCyc_C;
extern const boolean  AirSys_bFlexEffEGR_C;
extern const boolean  AirSys_bGasEffAfr_C;
extern const boolean  AirSys_bGasEffCyc_C;
extern const boolean  AirSys_bGasEffEGR_C;
extern const uint8  AirSys_effEGR_T[AIRSYS_EFFEGR_T_COLS];
extern const uint8  AirSys_rGradAfrReqLim_C;
extern const uint8  AirSys_rGradEGRReqLim_C;
extern const uint16  AirSys_effAfr_T[AIRSYS_EFFAFR_T_COLS];
extern const uint16  AirSys_effCycIni_C;
extern const uint16  AirSys_nEngEffCyc_A[AIRSYS_NENGEFFCYC_A_COLS];
extern const uint16  AirSys_nEngEffCycSho_A[AIRSYS_NENGEFFCYCSHO_A_COLS];
extern const uint16  AirSys_nEngEffCycShoIdl_A[AIRSYS_NENGEFFCYCSHOIDL_A_COLS];
extern const uint16  AirSys_rAirLdEffCyc_A[AIRSYS_RAIRLDEFFCYC_A_COLS];
extern const uint16  AirSys_rEGR_A[AIRSYS_REGR_A_COLS];
extern const uint16  AirSys_tiSdlFastAirTqEff_C;
extern const uint16  AirSys_tqIdcHPCal1_M[AIRSYS_TQIDCHPCAL1_M_LNS][AIRSYS_TQIDCHPCAL1_M_COLS];
extern const uint16  AirSys_tqIdcHPCal10_M[AIRSYS_TQIDCHPCAL10_M_LNS][AIRSYS_TQIDCHPCAL10_M_COLS];
extern const uint16  AirSys_tqIdcHPCal11_M[AIRSYS_TQIDCHPCAL11_M_LNS][AIRSYS_TQIDCHPCAL11_M_COLS];
extern const uint16  AirSys_tqIdcHPCal12_M[AIRSYS_TQIDCHPCAL12_M_LNS][AIRSYS_TQIDCHPCAL12_M_COLS];
extern const uint16  AirSys_tqIdcHPCal13_M[AIRSYS_TQIDCHPCAL13_M_LNS][AIRSYS_TQIDCHPCAL13_M_COLS];
extern const uint16  AirSys_tqIdcHPCal14_M[AIRSYS_TQIDCHPCAL14_M_LNS][AIRSYS_TQIDCHPCAL14_M_COLS];
extern const uint16  AirSys_tqIdcHPCal2_M[AIRSYS_TQIDCHPCAL2_M_LNS][AIRSYS_TQIDCHPCAL2_M_COLS];
extern const uint16  AirSys_tqIdcHPCal3_M[AIRSYS_TQIDCHPCAL3_M_LNS][AIRSYS_TQIDCHPCAL3_M_COLS];
extern const uint16  AirSys_tqIdcHPCal4_M[AIRSYS_TQIDCHPCAL4_M_LNS][AIRSYS_TQIDCHPCAL4_M_COLS];
extern const uint16  AirSys_tqIdcHPCal5_M[AIRSYS_TQIDCHPCAL5_M_LNS][AIRSYS_TQIDCHPCAL5_M_COLS];
extern const uint16  AirSys_tqIdcHPCal6_M[AIRSYS_TQIDCHPCAL6_M_LNS][AIRSYS_TQIDCHPCAL6_M_COLS];
extern const uint16  AirSys_tqIdcHPCal7_M[AIRSYS_TQIDCHPCAL7_M_LNS][AIRSYS_TQIDCHPCAL7_M_COLS];
extern const uint16  AirSys_tqIdcHPCal8_M[AIRSYS_TQIDCHPCAL8_M_LNS][AIRSYS_TQIDCHPCAL8_M_COLS];
extern const uint16  AirSys_tqIdcHPCal9_M[AIRSYS_TQIDCHPCAL9_M_LNS][AIRSYS_TQIDCHPCAL9_M_COLS];
extern const uint16  Inj_rlamEng_A[INJ_RLAMENG_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirSys_EveIni_AirTqEff(void);
void AirSys_SdlFast_AirTqEff(void);


#endif /* AIRTQEFF_H */

/*-------------------------------- end of file -------------------------------*/
