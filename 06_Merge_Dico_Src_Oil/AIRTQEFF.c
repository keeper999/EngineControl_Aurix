/***************************************************************************
;**
;** FILE NAME      : AIRTQEFF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AIRTQEFF.H"
#include "AIRTQEFF_L.H"
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
const boolean  AirSys_bFlexEffAfr_C = 0;
const boolean  AirSys_bFlexEffCyc_C = 0;
const boolean  AirSys_bFlexEffEGR_C = 0;
const boolean  AirSys_bGasEffAfr_C = 0;
const boolean  AirSys_bGasEffCyc_C = 0;
const boolean  AirSys_bGasEffEGR_C = 0;
const uint8  AirSys_effEGR_T[AIRSYS_EFFEGR_T_COLS] = {0};
const uint8  AirSys_rGradAfrReqLim_C = 0;
const uint8  AirSys_rGradEGRReqLim_C = 0;
const uint8  AIRTQEFF_u8Inhib = 0;
const uint16  AirSys_effAfr_T[AIRSYS_EFFAFR_T_COLS] = {0};
const uint16  AirSys_effCycIni_C = 0;
const uint16  AirSys_nEngEffCyc_A[AIRSYS_NENGEFFCYC_A_COLS] = {0};
const uint16  AirSys_nEngEffCycSho_A[AIRSYS_NENGEFFCYCSHO_A_COLS] = {0};
const uint16  AirSys_nEngEffCycShoIdl_A[AIRSYS_NENGEFFCYCSHOIDL_A_COLS] = {0};
const uint16  AirSys_rAirLdEffCyc_A[AIRSYS_RAIRLDEFFCYC_A_COLS] = {0};
const uint16  AirSys_rEGR_A[AIRSYS_REGR_A_COLS] = {0};
const uint16  AirSys_tiSdlFastAirTqEff_C = 0;
const uint16  AirSys_tqIdcHPCal1_M[AIRSYS_TQIDCHPCAL1_M_LNS][AIRSYS_TQIDCHPCAL1_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal10_M[AIRSYS_TQIDCHPCAL10_M_LNS][AIRSYS_TQIDCHPCAL10_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal11_M[AIRSYS_TQIDCHPCAL11_M_LNS][AIRSYS_TQIDCHPCAL11_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal12_M[AIRSYS_TQIDCHPCAL12_M_LNS][AIRSYS_TQIDCHPCAL12_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal13_M[AIRSYS_TQIDCHPCAL13_M_LNS][AIRSYS_TQIDCHPCAL13_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal14_M[AIRSYS_TQIDCHPCAL14_M_LNS][AIRSYS_TQIDCHPCAL14_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal2_M[AIRSYS_TQIDCHPCAL2_M_LNS][AIRSYS_TQIDCHPCAL2_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal3_M[AIRSYS_TQIDCHPCAL3_M_LNS][AIRSYS_TQIDCHPCAL3_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal4_M[AIRSYS_TQIDCHPCAL4_M_LNS][AIRSYS_TQIDCHPCAL4_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal5_M[AIRSYS_TQIDCHPCAL5_M_LNS][AIRSYS_TQIDCHPCAL5_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal6_M[AIRSYS_TQIDCHPCAL6_M_LNS][AIRSYS_TQIDCHPCAL6_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal7_M[AIRSYS_TQIDCHPCAL7_M_LNS][AIRSYS_TQIDCHPCAL7_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal8_M[AIRSYS_TQIDCHPCAL8_M_LNS][AIRSYS_TQIDCHPCAL8_M_COLS] = {0};
const uint16  AirSys_tqIdcHPCal9_M[AIRSYS_TQIDCHPCAL9_M_LNS][AIRSYS_TQIDCHPCAL9_M_COLS] = {0};
const uint16  Inj_rlamEng_A[INJ_RLAMENG_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AirSys_bAcvCycCal1;
boolean AirSys_bAcvCycCal10;
boolean AirSys_bAcvCycCal11;
boolean AirSys_bAcvCycCal12;
boolean AirSys_bAcvCycCal13;
boolean AirSys_bAcvCycCal14;
boolean AirSys_bAcvCycCal2;
boolean AirSys_bAcvCycCal3;
boolean AirSys_bAcvCycCal4;
boolean AirSys_bAcvCycCal5;
boolean AirSys_bAcvCycCal6;
boolean AirSys_bAcvCycCal7;
boolean AirSys_bAcvCycCal8;
boolean AirSys_bAcvCycCal9;
boolean AirSys_prm_bAcvEffCycCal[AIRSYS_PRM_BACVEFFCYCCAL_COLS];
uint8 AirSys_effEGRClc;
uint8 AirSys_effEGRWiFlexCor_MP;
uint8 AirSys_facBasModCur;
uint8 AirSys_facBasModTar;
uint8 AirSys_facTranMod;
uint8 AirSys_idxBas1ModCur;
uint8 AirSys_idxBas1ModTar;
uint8 AirSys_idxBas2ModCur;
uint8 AirSys_idxBas2ModTar;
uint16 AirSys_effCycTran;
uint16 AirSys_effCycWiFlexCor_MP;
uint16 AirSys_effEffCycBas1ModCur;
uint16 AirSys_effEffCycBas1ModTar;
uint16 AirSys_effEffCycBas2ModCur;
uint16 AirSys_effEffCycBas2ModTar;
uint16 AirSys_prm_effAfrClc[AIRSYS_PRM_EFFAFRCLC_COLS];
uint16 AirSys_prm_effAfrFlexCor_MP[AIRSYS_PRM_EFFAFRFLEXCOR_MP_COLS];
uint16 AirSys_prm_effCyc[AIRSYS_PRM_EFFCYC_COLS];
uint16 AirSys_tqIdcHPCal1;
uint16 AirSys_tqIdcHPCal10;
uint16 AirSys_tqIdcHPCal11;
uint16 AirSys_tqIdcHPCal12;
uint16 AirSys_tqIdcHPCal13;
uint16 AirSys_tqIdcHPCal14;
uint16 AirSys_tqIdcHPCal2;
uint16 AirSys_tqIdcHPCal3;
uint16 AirSys_tqIdcHPCal4;
uint16 AirSys_tqIdcHPCal5;
uint16 AirSys_tqIdcHPCal6;
uint16 AirSys_tqIdcHPCal7;
uint16 AirSys_tqIdcHPCal8;
uint16 AirSys_tqIdcHPCal9;
uint16 AIRTQEFF_u16Barycentre1;
uint16 AIRTQEFF_u16Barycentre2;
uint16 AIRTQEFF_u16Inj_rlamEng_A_input;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

