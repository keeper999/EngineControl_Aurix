/***************************************************************************
;**
;** FILE NAME      : VVTSPLIMCORD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VVTSPLIMCORD.H"
#include "VVTSPLIMCORD_L.H"
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
const sint8  ExM_tExOfsCal14_C = 0;
const uint8  ExM_tExOfsCal1_M[EXM_TEXOFSCAL1_M_LNS][EXM_TEXOFSCAL1_M_COLS] = {0};
const uint8  ExM_tExOfsCal10_M[EXM_TEXOFSCAL10_M_LNS][EXM_TEXOFSCAL10_M_COLS] = {0};
const uint8  ExM_tExOfsCal11_M[EXM_TEXOFSCAL11_M_LNS][EXM_TEXOFSCAL11_M_COLS] = {0};
const uint8  ExM_tExOfsCal12_M[EXM_TEXOFSCAL12_M_LNS][EXM_TEXOFSCAL12_M_COLS] = {0};
const uint8  ExM_tExOfsCal13_M[EXM_TEXOFSCAL13_M_LNS][EXM_TEXOFSCAL13_M_COLS] = {0};
const uint8  ExM_tExOfsCal2_M[EXM_TEXOFSCAL2_M_LNS][EXM_TEXOFSCAL2_M_COLS] = {0};
const uint8  ExM_tExOfsCal3_M[EXM_TEXOFSCAL3_M_LNS][EXM_TEXOFSCAL3_M_COLS] = {0};
const uint8  ExM_tExOfsCal4_M[EXM_TEXOFSCAL4_M_LNS][EXM_TEXOFSCAL4_M_COLS] = {0};
const uint8  ExM_tExOfsCal5_M[EXM_TEXOFSCAL5_M_LNS][EXM_TEXOFSCAL5_M_COLS] = {0};
const uint8  ExM_tExOfsCal6_M[EXM_TEXOFSCAL6_M_LNS][EXM_TEXOFSCAL6_M_COLS] = {0};
const uint8  ExM_tExOfsCal7_M[EXM_TEXOFSCAL7_M_LNS][EXM_TEXOFSCAL7_M_COLS] = {0};
const uint8  ExM_tExOfsCal8_M[EXM_TEXOFSCAL8_M_LNS][EXM_TEXOFSCAL8_M_COLS] = {0};
const uint8  ExM_tExOfsCal9_M[EXM_TEXOFSCAL9_M_LNS][EXM_TEXOFSCAL9_M_COLS] = {0};
const uint8  VVTSPLIMCORD_u8Inhib = 0;
const uint16  ExM_nEngCorX_A[EXM_NENGCORX_A_COLS] = {0};
const uint16  ExM_rAirCorY_A[EXM_RAIRCORY_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ExM_bAcvTExOfsCal1;
boolean ExM_bAcvTExOfsCal10;
boolean ExM_bAcvTExOfsCal11;
boolean ExM_bAcvTExOfsCal12;
boolean ExM_bAcvTExOfsCal13;
boolean ExM_bAcvTExOfsCal14;
boolean ExM_bAcvTExOfsCal2;
boolean ExM_bAcvTExOfsCal3;
boolean ExM_bAcvTExOfsCal4;
boolean ExM_bAcvTExOfsCal5;
boolean ExM_bAcvTExOfsCal6;
boolean ExM_bAcvTExOfsCal7;
boolean ExM_bAcvTExOfsCal8;
boolean ExM_bAcvTExOfsCal9;
boolean ExM_prm_bAcvTExOfsCal[EXM_PRM_BACVTEXOFSCAL_COLS];
uint8 ExM_facBasModCur;
uint8 ExM_facBasModTar;
uint8 ExM_facTranMod;
uint8 ExM_idxBas1ModCur;
uint8 ExM_idxBas1ModTar;
uint8 ExM_idxBas2ModCur;
uint8 ExM_idxBas2ModTar;
sint16 ExM_prm_tExOfsCal[EXM_PRM_TEXOFSCAL_COLS];
sint16 ExM_tExOfsBas1ModCur;
sint16 ExM_tExOfsBas1ModTar;
sint16 ExM_tExOfsBas2ModCur;
sint16 ExM_tExOfsBas2ModTar;
sint16 ExM_tExOfsCal1;
sint16 ExM_tExOfsCal10;
sint16 ExM_tExOfsCal11;
sint16 ExM_tExOfsCal12;
sint16 ExM_tExOfsCal13;
sint16 ExM_tExOfsCal14;
sint16 ExM_tExOfsCal2;
sint16 ExM_tExOfsCal3;
sint16 ExM_tExOfsCal4;
sint16 ExM_tExOfsCal5;
sint16 ExM_tExOfsCal6;
sint16 ExM_tExOfsCal7;
sint16 ExM_tExOfsCal8;
sint16 ExM_tExOfsCal9;
sint16 ExM_tExOfsModCur_MP;
sint16 ExM_tExOfsModTar_MP;
uint16 ExM_nEngCor;
uint16 ExM_rAirLdCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

