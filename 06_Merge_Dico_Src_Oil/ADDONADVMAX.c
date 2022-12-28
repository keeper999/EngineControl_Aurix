/***************************************************************************
;**
;** FILE NAME      : ADDONADVMAX.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADDONADVMAX.H"
#include "ADDONADVMAX_L.H"
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
const uint8  ADDONADVMAX_u8Inhib = 0;
const uint8  IgSys_ofsAgIgMaxCal1_M[IGSYS_OFSAGIGMAXCAL1_M_LNS][IGSYS_OFSAGIGMAXCAL1_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal10_M[IGSYS_OFSAGIGMAXCAL10_M_LNS][IGSYS_OFSAGIGMAXCAL10_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal11_M[IGSYS_OFSAGIGMAXCAL11_M_LNS][IGSYS_OFSAGIGMAXCAL11_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal12_M[IGSYS_OFSAGIGMAXCAL12_M_LNS][IGSYS_OFSAGIGMAXCAL12_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal13_M[IGSYS_OFSAGIGMAXCAL13_M_LNS][IGSYS_OFSAGIGMAXCAL13_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal2_M[IGSYS_OFSAGIGMAXCAL2_M_LNS][IGSYS_OFSAGIGMAXCAL2_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal3_M[IGSYS_OFSAGIGMAXCAL3_M_LNS][IGSYS_OFSAGIGMAXCAL3_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal4_M[IGSYS_OFSAGIGMAXCAL4_M_LNS][IGSYS_OFSAGIGMAXCAL4_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal5_M[IGSYS_OFSAGIGMAXCAL5_M_LNS][IGSYS_OFSAGIGMAXCAL5_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal6_M[IGSYS_OFSAGIGMAXCAL6_M_LNS][IGSYS_OFSAGIGMAXCAL6_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal7_M[IGSYS_OFSAGIGMAXCAL7_M_LNS][IGSYS_OFSAGIGMAXCAL7_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal8_M[IGSYS_OFSAGIGMAXCAL8_M_LNS][IGSYS_OFSAGIGMAXCAL8_M_COLS] = {0};
const uint8  IgSys_ofsAgIgMaxCal9_M[IGSYS_OFSAGIGMAXCAL9_M_LNS][IGSYS_OFSAGIGMAXCAL9_M_COLS] = {0};
const sint16  IgSys_ofsAgIgMaxCal14_C = 0;
const uint16  IgSys_nEngOfsAgIgMax_A[IGSYS_NENGOFSAGIGMAX_A_COLS] = {0};
const uint16  IgSys_nEngOfsAgIgMaxShoIdl_A[IGSYS_NENGOFSAGIGMAXSHOIDL_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgMax_A[IGSYS_RAIRLDOFSAGIGMAX_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgMaxShoIdl_A[IGSYS_RAIRLDOFSAGIGMAXSHOIDL_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IgSys_bAcvOfsAgIgMaxCal1;
boolean IgSys_bAcvOfsAgIgMaxCal10;
boolean IgSys_bAcvOfsAgIgMaxCal11;
boolean IgSys_bAcvOfsAgIgMaxCal12;
boolean IgSys_bAcvOfsAgIgMaxCal13;
boolean IgSys_bAcvOfsAgIgMaxCal14;
boolean IgSys_bAcvOfsAgIgMaxCal2;
boolean IgSys_bAcvOfsAgIgMaxCal3;
boolean IgSys_bAcvOfsAgIgMaxCal4;
boolean IgSys_bAcvOfsAgIgMaxCal5;
boolean IgSys_bAcvOfsAgIgMaxCal6;
boolean IgSys_bAcvOfsAgIgMaxCal7;
boolean IgSys_bAcvOfsAgIgMaxCal8;
boolean IgSys_bAcvOfsAgIgMaxCal9;
boolean IgSys_prm_bAcvOfsAgIgMaxCal[IGSYS_PRM_BACVOFSAGIGMAXCAL_COLS];
uint8 IgSys_facOfsAgIgMaxBasModCur;
uint8 IgSys_facOfsAgIgMaxBasModTar;
uint8 IgSys_facOfsAgIgMaxTranMod;
uint8 IgSys_idxOfsAgIgMaxBas1ModCur;
uint8 IgSys_idxOfsAgIgMaxBas1ModTar;
uint8 IgSys_idxOfsAgIgMaxBas2ModCur;
uint8 IgSys_idxOfsAgIgMaxBas2ModTar;
sint16 IgSys_agIgCmbModOfsMaxCur_MP;
sint16 IgSys_agIgCmbModOfsMaxTar_MP;
sint16 IgSys_ofsAgIgMaxBas1ModCur;
sint16 IgSys_ofsAgIgMaxBas1ModTar;
sint16 IgSys_ofsAgIgMaxBas2ModCur;
sint16 IgSys_ofsAgIgMaxBas2ModTar;
sint16 IgSys_ofsAgIgMaxCal1;
sint16 IgSys_ofsAgIgMaxCal10;
sint16 IgSys_ofsAgIgMaxCal11;
sint16 IgSys_ofsAgIgMaxCal12;
sint16 IgSys_ofsAgIgMaxCal13;
sint16 IgSys_ofsAgIgMaxCal14;
sint16 IgSys_ofsAgIgMaxCal2;
sint16 IgSys_ofsAgIgMaxCal3;
sint16 IgSys_ofsAgIgMaxCal4;
sint16 IgSys_ofsAgIgMaxCal5;
sint16 IgSys_ofsAgIgMaxCal6;
sint16 IgSys_ofsAgIgMaxCal7;
sint16 IgSys_ofsAgIgMaxCal8;
sint16 IgSys_ofsAgIgMaxCal9;
sint16 IgSys_prm_ofsAgIgMax[IGSYS_PRM_OFSAGIGMAX_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

