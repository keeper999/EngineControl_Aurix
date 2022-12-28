/***************************************************************************
;**
;** FILE NAME      : VLVINSPMGT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVINSPMGT.H"
#include "VLVINSPMGT_L.H"
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
const sint8  VlvSys_agCkOpInCal17_C = 0;
const sint8  VlvSys_agCkOpInCal18_C = 0;
const uint8  VLVINSPMGT_u8Inhib = 0;
const uint8  VlvSys_agCkOpInCal1_M[VLVSYS_AGCKOPINCAL1_M_LNS][VLVSYS_AGCKOPINCAL1_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal10_M[VLVSYS_AGCKOPINCAL10_M_LNS][VLVSYS_AGCKOPINCAL10_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal11_M[VLVSYS_AGCKOPINCAL11_M_LNS][VLVSYS_AGCKOPINCAL11_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal12_M[VLVSYS_AGCKOPINCAL12_M_LNS][VLVSYS_AGCKOPINCAL12_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal13_M[VLVSYS_AGCKOPINCAL13_M_LNS][VLVSYS_AGCKOPINCAL13_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal14_M[VLVSYS_AGCKOPINCAL14_M_LNS][VLVSYS_AGCKOPINCAL14_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal15_M[VLVSYS_AGCKOPINCAL15_M_LNS][VLVSYS_AGCKOPINCAL15_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal16_M[VLVSYS_AGCKOPINCAL16_M_LNS][VLVSYS_AGCKOPINCAL16_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal2_M[VLVSYS_AGCKOPINCAL2_M_LNS][VLVSYS_AGCKOPINCAL2_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal3_M[VLVSYS_AGCKOPINCAL3_M_LNS][VLVSYS_AGCKOPINCAL3_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal4_M[VLVSYS_AGCKOPINCAL4_M_LNS][VLVSYS_AGCKOPINCAL4_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal5_M[VLVSYS_AGCKOPINCAL5_M_LNS][VLVSYS_AGCKOPINCAL5_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal6_M[VLVSYS_AGCKOPINCAL6_M_LNS][VLVSYS_AGCKOPINCAL6_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal7_M[VLVSYS_AGCKOPINCAL7_M_LNS][VLVSYS_AGCKOPINCAL7_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal8_M[VLVSYS_AGCKOPINCAL8_M_LNS][VLVSYS_AGCKOPINCAL8_M_COLS] = {0};
const uint8  VlvSys_agCkOpInCal9_M[VLVSYS_AGCKOPINCAL9_M_LNS][VLVSYS_AGCKOPINCAL9_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VlvSys_bAcvOpInCal1;
boolean VlvSys_bAcvOpInCal10;
boolean VlvSys_bAcvOpInCal11;
boolean VlvSys_bAcvOpInCal12;
boolean VlvSys_bAcvOpInCal13;
boolean VlvSys_bAcvOpInCal14;
boolean VlvSys_bAcvOpInCal15;
boolean VlvSys_bAcvOpInCal16;
boolean VlvSys_bAcvOpInCal17;
boolean VlvSys_bAcvOpInCal18;
boolean VlvSys_bAcvOpInCal2;
boolean VlvSys_bAcvOpInCal3;
boolean VlvSys_bAcvOpInCal4;
boolean VlvSys_bAcvOpInCal5;
boolean VlvSys_bAcvOpInCal6;
boolean VlvSys_bAcvOpInCal7;
boolean VlvSys_bAcvOpInCal8;
boolean VlvSys_bAcvOpInCal9;
boolean VlvSys_prm_bAcvOpInCal[VLVSYS_PRM_BACVOPINCAL_COLS];
sint8 VlvSys_agCkOpInCal1;
sint8 VlvSys_agCkOpInCal10;
sint8 VlvSys_agCkOpInCal11;
sint8 VlvSys_agCkOpInCal12;
sint8 VlvSys_agCkOpInCal13;
sint8 VlvSys_agCkOpInCal14;
sint8 VlvSys_agCkOpInCal15;
sint8 VlvSys_agCkOpInCal16;
sint8 VlvSys_agCkOpInCal17;
sint8 VlvSys_agCkOpInCal18;
sint8 VlvSys_agCkOpInCal2;
sint8 VlvSys_agCkOpInCal3;
sint8 VlvSys_agCkOpInCal4;
sint8 VlvSys_agCkOpInCal5;
sint8 VlvSys_agCkOpInCal6;
sint8 VlvSys_agCkOpInCal7;
sint8 VlvSys_agCkOpInCal8;
sint8 VlvSys_agCkOpInCal9;
sint8 VlvSys_agCkOpInVlvBas1ModCur;
sint8 VlvSys_agCkOpInVlvBas1ModTar;
sint8 VlvSys_agCkOpInVlvBas2ModCur;
sint8 VlvSys_agCkOpInVlvBas2ModTar;
sint8 VlvSys_agCkOpInVlvReq;
sint8 VlvSys_prm_agCkOpInCal[VLVSYS_PRM_AGCKOPINCAL_COLS];
uint8 VlvSys_facBasModCurOpIn;
uint8 VlvSys_facBasModTarOpIn;
uint8 VlvSys_facTranModOpIn;
uint8 VlvSys_idxBas1ModCurOpIn;
uint8 VlvSys_idxBas1ModTarOpIn;
uint8 VlvSys_idxBas2ModCurOpIn;
uint8 VlvSys_idxBas2ModTarOpIn;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

