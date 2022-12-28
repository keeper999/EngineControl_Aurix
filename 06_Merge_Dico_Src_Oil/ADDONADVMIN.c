/***************************************************************************
;**
;** FILE NAME      : ADDONADVMIN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADDONADVMIN.H"
#include "ADDONADVMIN_L.H"
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
const uint8  ADDONADVMIN_u8Inhib = 0;
const uint8  IgSys_ofsAgIgMinCal1_M[IGSYS_OFSAGIGMINCAL1_M_LNS][IGSYS_OFSAGIGMINCAL1_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal10_M[IGSYS_OFSAGIGMINCAL10_M_LNS][IGSYS_OFSAGIGMINCAL10_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal11_M[IGSYS_OFSAGIGMINCAL11_M_LNS][IGSYS_OFSAGIGMINCAL11_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal12_M[IGSYS_OFSAGIGMINCAL12_M_LNS][IGSYS_OFSAGIGMINCAL12_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal13_M[IGSYS_OFSAGIGMINCAL13_M_LNS][IGSYS_OFSAGIGMINCAL13_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal2_M[IGSYS_OFSAGIGMINCAL2_M_LNS][IGSYS_OFSAGIGMINCAL2_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal3_M[IGSYS_OFSAGIGMINCAL3_M_LNS][IGSYS_OFSAGIGMINCAL3_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal4_M[IGSYS_OFSAGIGMINCAL4_M_LNS][IGSYS_OFSAGIGMINCAL4_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal5_M[IGSYS_OFSAGIGMINCAL5_M_LNS][IGSYS_OFSAGIGMINCAL5_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal6_M[IGSYS_OFSAGIGMINCAL6_M_LNS][IGSYS_OFSAGIGMINCAL6_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal7_M[IGSYS_OFSAGIGMINCAL7_M_LNS][IGSYS_OFSAGIGMINCAL7_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal8_M[IGSYS_OFSAGIGMINCAL8_M_LNS][IGSYS_OFSAGIGMINCAL8_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMinCal9_M[IGSYS_OFSAGIGMINCAL9_M_LNS][IGSYS_OFSAGIGMINCAL9_M_COLS] = {0};
const sint16  IgSys_ofsAgIgMinCal14_C = 0;
const uint16  IgSys_nEngOfsAgIgMin_A[IGSYS_NENGOFSAGIGMIN_A_COLS] = {0};
const uint16  IgSys_nEngOfsAgIgMinShoIdl_A[IGSYS_NENGOFSAGIGMINSHOIDL_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgMin_A[IGSYS_RAIRLDOFSAGIGMIN_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgMinShoIdl_A[IGSYS_RAIRLDOFSAGIGMINSHOIDL_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IgSys_bAcvOfsAgIgMinCal1;
boolean IgSys_bAcvOfsAgIgMinCal10;
boolean IgSys_bAcvOfsAgIgMinCal11;
boolean IgSys_bAcvOfsAgIgMinCal12;
boolean IgSys_bAcvOfsAgIgMinCal13;
boolean IgSys_bAcvOfsAgIgMinCal14;
boolean IgSys_bAcvOfsAgIgMinCal2;
boolean IgSys_bAcvOfsAgIgMinCal3;
boolean IgSys_bAcvOfsAgIgMinCal4;
boolean IgSys_bAcvOfsAgIgMinCal5;
boolean IgSys_bAcvOfsAgIgMinCal6;
boolean IgSys_bAcvOfsAgIgMinCal7;
boolean IgSys_bAcvOfsAgIgMinCal8;
boolean IgSys_bAcvOfsAgIgMinCal9;
boolean IgSys_prm_bAcvOfsAgIgMinCal[IGSYS_PRM_BACVOFSAGIGMINCAL_COLS];
uint8 IgSys_facOfsAgIgMinBasModCur;
uint8 IgSys_facOfsAgIgMinBasModTar;
uint8 IgSys_facOfsAgIgMinTranMod;
uint8 IgSys_idxOfsAgIgMinBas1ModCur;
uint8 IgSys_idxOfsAgIgMinBas1ModTar;
uint8 IgSys_idxOfsAgIgMinBas2ModCur;
uint8 IgSys_idxOfsAgIgMinBas2ModTar;
sint16 IgSys_agIgCmbModOfsMinCur_MP;
sint16 IgSys_agIgCmbModOfsMinTar_MP;
sint16 IgSys_ofsAgIgMinBas1ModCur;
sint16 IgSys_ofsAgIgMinBas1ModTar;
sint16 IgSys_ofsAgIgMinBas2ModCur;
sint16 IgSys_ofsAgIgMinBas2ModTar;
sint16 IgSys_ofsAgIgMinCal1;
sint16 IgSys_ofsAgIgMinCal10;
sint16 IgSys_ofsAgIgMinCal11;
sint16 IgSys_ofsAgIgMinCal12;
sint16 IgSys_ofsAgIgMinCal13;
sint16 IgSys_ofsAgIgMinCal14;
sint16 IgSys_ofsAgIgMinCal2;
sint16 IgSys_ofsAgIgMinCal3;
sint16 IgSys_ofsAgIgMinCal4;
sint16 IgSys_ofsAgIgMinCal5;
sint16 IgSys_ofsAgIgMinCal6;
sint16 IgSys_ofsAgIgMinCal7;
sint16 IgSys_ofsAgIgMinCal8;
sint16 IgSys_ofsAgIgMinCal9;
sint16 IgSys_prm_ofsAgIgMin[IGSYS_PRM_OFSAGIGMIN_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

