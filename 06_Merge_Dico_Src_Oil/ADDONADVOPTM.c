/***************************************************************************
;**
;** FILE NAME      : ADDONADVOPTM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADDONADVOPTM.H"
#include "ADDONADVOPTM_L.H"
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
const uint8  ADDONADVOPTM_u8Inhib = 0;
const uint8  IgSys_ofsAgIgOptmCal1_M[IGSYS_OFSAGIGOPTMCAL1_M_LNS][IGSYS_OFSAGIGOPTMCAL1_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal10_M[IGSYS_OFSAGIGOPTMCAL10_M_LNS][IGSYS_OFSAGIGOPTMCAL10_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal11_M[IGSYS_OFSAGIGOPTMCAL11_M_LNS][IGSYS_OFSAGIGOPTMCAL11_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal12_M[IGSYS_OFSAGIGOPTMCAL12_M_LNS][IGSYS_OFSAGIGOPTMCAL12_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal13_M[IGSYS_OFSAGIGOPTMCAL13_M_LNS][IGSYS_OFSAGIGOPTMCAL13_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal14_M[IGSYS_OFSAGIGOPTMCAL14_M_LNS][IGSYS_OFSAGIGOPTMCAL14_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal15_M[IGSYS_OFSAGIGOPTMCAL15_M_LNS][IGSYS_OFSAGIGOPTMCAL15_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal16_M[IGSYS_OFSAGIGOPTMCAL16_M_LNS][IGSYS_OFSAGIGOPTMCAL16_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal2_M[IGSYS_OFSAGIGOPTMCAL2_M_LNS][IGSYS_OFSAGIGOPTMCAL2_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal3_M[IGSYS_OFSAGIGOPTMCAL3_M_LNS][IGSYS_OFSAGIGOPTMCAL3_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal4_M[IGSYS_OFSAGIGOPTMCAL4_M_LNS][IGSYS_OFSAGIGOPTMCAL4_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal5_M[IGSYS_OFSAGIGOPTMCAL5_M_LNS][IGSYS_OFSAGIGOPTMCAL5_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal6_M[IGSYS_OFSAGIGOPTMCAL6_M_LNS][IGSYS_OFSAGIGOPTMCAL6_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal7_M[IGSYS_OFSAGIGOPTMCAL7_M_LNS][IGSYS_OFSAGIGOPTMCAL7_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal8_M[IGSYS_OFSAGIGOPTMCAL8_M_LNS][IGSYS_OFSAGIGOPTMCAL8_M_COLS] = {0};
const uint8  IgSys_ofsAgIgOptmCal9_M[IGSYS_OFSAGIGOPTMCAL9_M_LNS][IGSYS_OFSAGIGOPTMCAL9_M_COLS] = {0};
const sint16  IgSys_ofsAgIgOptmCal17_C = 0;
const uint16  IgSys_nEngOfsAgIgOptm_A[IGSYS_NENGOFSAGIGOPTM_A_COLS] = {0};
const uint16  IgSys_nEngOfsAgIgOptmShoIdl_A[IGSYS_NENGOFSAGIGOPTMSHOIDL_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgOptm_A[IGSYS_RAIRLDOFSAGIGOPTM_A_COLS] = {0};
const uint16  IgSys_rAirLdOfsAgIgOptmShoIdl_A[IGSYS_RAIRLDOFSAGIGOPTMSHOIDL_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IgSys_bAcvOfsAgIgOptmCal1;
boolean IgSys_bAcvOfsAgIgOptmCal10;
boolean IgSys_bAcvOfsAgIgOptmCal11;
boolean IgSys_bAcvOfsAgIgOptmCal12;
boolean IgSys_bAcvOfsAgIgOptmCal13;
boolean IgSys_bAcvOfsAgIgOptmCal14;
boolean IgSys_bAcvOfsAgIgOptmCal15;
boolean IgSys_bAcvOfsAgIgOptmCal16;
boolean IgSys_bAcvOfsAgIgOptmCal17;
boolean IgSys_bAcvOfsAgIgOptmCal2;
boolean IgSys_bAcvOfsAgIgOptmCal3;
boolean IgSys_bAcvOfsAgIgOptmCal4;
boolean IgSys_bAcvOfsAgIgOptmCal5;
boolean IgSys_bAcvOfsAgIgOptmCal6;
boolean IgSys_bAcvOfsAgIgOptmCal7;
boolean IgSys_bAcvOfsAgIgOptmCal8;
boolean IgSys_bAcvOfsAgIgOptmCal9;
boolean IgSys_prm_bAcvOfsAgIgOptmCal[IGSYS_PRM_BACVOFSAGIGOPTMCAL_COLS];
uint8 IgSys_facOfsAgIgOpBasModCur;
uint8 IgSys_facOfsAgIgOpBasModTar;
uint8 IgSys_facOfsAgIgOpTranMod;
uint8 IgSys_idxOfsAgIgOpBas1ModCur;
uint8 IgSys_idxOfsAgIgOpBas1ModTar;
uint8 IgSys_idxOfsAgIgOpBas2ModCur;
uint8 IgSys_idxOfsAgIgOpBas2ModTar;
sint16 IgSys_agIgCmbModOfsCur_MP;
sint16 IgSys_agIgCmbModOfsTar_MP;
sint16 IgSys_ofsAgIgOptmBas1ModCur;
sint16 IgSys_ofsAgIgOptmBas1ModTar;
sint16 IgSys_ofsAgIgOptmBas2ModCur;
sint16 IgSys_ofsAgIgOptmBas2ModTar;
sint16 IgSys_ofsAgIgOptmCal1;
sint16 IgSys_ofsAgIgOptmCal10;
sint16 IgSys_ofsAgIgOptmCal11;
sint16 IgSys_ofsAgIgOptmCal12;
sint16 IgSys_ofsAgIgOptmCal13;
sint16 IgSys_ofsAgIgOptmCal14;
sint16 IgSys_ofsAgIgOptmCal15;
sint16 IgSys_ofsAgIgOptmCal16;
sint16 IgSys_ofsAgIgOptmCal17;
sint16 IgSys_ofsAgIgOptmCal2;
sint16 IgSys_ofsAgIgOptmCal3;
sint16 IgSys_ofsAgIgOptmCal4;
sint16 IgSys_ofsAgIgOptmCal5;
sint16 IgSys_ofsAgIgOptmCal6;
sint16 IgSys_ofsAgIgOptmCal7;
sint16 IgSys_ofsAgIgOptmCal8;
sint16 IgSys_ofsAgIgOptmCal9;
sint16 IgSys_prm_ofsAgIgOptm[IGSYS_PRM_OFSAGIGOPTM_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

