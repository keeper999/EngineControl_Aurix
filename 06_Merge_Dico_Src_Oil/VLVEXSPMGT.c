/***************************************************************************
;**
;** FILE NAME      : VLVEXSPMGT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVEXSPMGT.H"
#include "VLVEXSPMGT_L.H"
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
const sint8  VlvSys_agCkClsExCal17_C = 0;
const sint8  VlvSys_agCkClsExCal18_C = 0;
const uint8  VLVEXSPMGT_u8Inhib = 0;
const uint8  VlvSys_agCkClsExCal1_M[VLVSYS_AGCKCLSEXCAL1_M_LNS][VLVSYS_AGCKCLSEXCAL1_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal10_M[VLVSYS_AGCKCLSEXCAL10_M_LNS][VLVSYS_AGCKCLSEXCAL10_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal11_M[VLVSYS_AGCKCLSEXCAL11_M_LNS][VLVSYS_AGCKCLSEXCAL11_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal12_M[VLVSYS_AGCKCLSEXCAL12_M_LNS][VLVSYS_AGCKCLSEXCAL12_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal13_M[VLVSYS_AGCKCLSEXCAL13_M_LNS][VLVSYS_AGCKCLSEXCAL13_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal14_M[VLVSYS_AGCKCLSEXCAL14_M_LNS][VLVSYS_AGCKCLSEXCAL14_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal15_M[VLVSYS_AGCKCLSEXCAL15_M_LNS][VLVSYS_AGCKCLSEXCAL15_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal16_M[VLVSYS_AGCKCLSEXCAL16_M_LNS][VLVSYS_AGCKCLSEXCAL16_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal2_M[VLVSYS_AGCKCLSEXCAL2_M_LNS][VLVSYS_AGCKCLSEXCAL2_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal3_M[VLVSYS_AGCKCLSEXCAL3_M_LNS][VLVSYS_AGCKCLSEXCAL3_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal4_M[VLVSYS_AGCKCLSEXCAL4_M_LNS][VLVSYS_AGCKCLSEXCAL4_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal5_M[VLVSYS_AGCKCLSEXCAL5_M_LNS][VLVSYS_AGCKCLSEXCAL5_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal6_M[VLVSYS_AGCKCLSEXCAL6_M_LNS][VLVSYS_AGCKCLSEXCAL6_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal7_M[VLVSYS_AGCKCLSEXCAL7_M_LNS][VLVSYS_AGCKCLSEXCAL7_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal8_M[VLVSYS_AGCKCLSEXCAL8_M_LNS][VLVSYS_AGCKCLSEXCAL8_M_COLS] = {0};
const uint8  VlvSys_agCkClsExCal9_M[VLVSYS_AGCKCLSEXCAL9_M_LNS][VLVSYS_AGCKCLSEXCAL9_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvSys_bAcvClsExCal1;
boolean VlvSys_bAcvClsExCal10;
boolean VlvSys_bAcvClsExCal11;
boolean VlvSys_bAcvClsExCal12;
boolean VlvSys_bAcvClsExCal13;
boolean VlvSys_bAcvClsExCal14;
boolean VlvSys_bAcvClsExCal15;
boolean VlvSys_bAcvClsExCal16;
boolean VlvSys_bAcvClsExCal17;
boolean VlvSys_bAcvClsExCal18;
boolean VlvSys_bAcvClsExCal2;
boolean VlvSys_bAcvClsExCal3;
boolean VlvSys_bAcvClsExCal4;
boolean VlvSys_bAcvClsExCal5;
boolean VlvSys_bAcvClsExCal6;
boolean VlvSys_bAcvClsExCal7;
boolean VlvSys_bAcvClsExCal8;
boolean VlvSys_bAcvClsExCal9;
boolean VlvSys_prm_bAcvClsExCal[VLVSYS_PRM_BACVCLSEXCAL_COLS];
sint8 VlvSys_agCkClsExBas1ModCur;
sint8 VlvSys_agCkClsExBas1ModTar;
sint8 VlvSys_agCkClsExBas2ModCur;
sint8 VlvSys_agCkClsExBas2ModTar;
sint8 VlvSys_agCkClsExCal1;
sint8 VlvSys_agCkClsExCal10;
sint8 VlvSys_agCkClsExCal11;
sint8 VlvSys_agCkClsExCal12;
sint8 VlvSys_agCkClsExCal13;
sint8 VlvSys_agCkClsExCal14;
sint8 VlvSys_agCkClsExCal15;
sint8 VlvSys_agCkClsExCal16;
sint8 VlvSys_agCkClsExCal17;
sint8 VlvSys_agCkClsExCal18;
sint8 VlvSys_agCkClsExCal2;
sint8 VlvSys_agCkClsExCal3;
sint8 VlvSys_agCkClsExCal4;
sint8 VlvSys_agCkClsExCal5;
sint8 VlvSys_agCkClsExCal6;
sint8 VlvSys_agCkClsExCal7;
sint8 VlvSys_agCkClsExCal8;
sint8 VlvSys_agCkClsExCal9;
sint8 VlvSys_agCkClsExVlvReq;
sint8 VlvSys_prm_agCkClsExCal[VLVSYS_PRM_AGCKCLSEXCAL_COLS];
uint8 VlvSys_facBasModCurClsEx;
uint8 VlvSys_facBasModTarClsEx;
uint8 VlvSys_facTranModClsEx;
uint8 VlvSys_idxBas1ModCurClsEx;
uint8 VlvSys_idxBas1ModTarClsEx;
uint8 VlvSys_idxBas2ModCurClsEx;
uint8 VlvSys_idxBas2ModTarClsEx;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

