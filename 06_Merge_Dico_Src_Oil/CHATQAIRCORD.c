/***************************************************************************
;**
;** FILE NAME      : CHATQAIRCORD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CHATQAIRCORD.H"
#include "CHATQAIRCORD_L.H"
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
const boolean  CoCha_bAcvCutSelASR_C = 0;
const boolean  CoCha_bAcvCutSelSecu_C = 0;
const boolean  CoCha_bOfsClcTyp_C = 0;
const boolean  TqCha_bTqASRSel_C = 0;
const boolean  TqCha_bTqMSRSel_C = 0;
const uint8  CHATQAIRCORD_u8Inhib = 0;
const uint8  CoCha_facTauDown_T[COCHA_FACTAUDOWN_T_COLS] = {0};
const uint8  CoCha_facTauDownThermo_C = 0;
const uint8  CoCha_facTauUp_C = 0;
const uint8  CoCha_facTauUpThermo_C = 0;
const uint8  CoCha_noCylCutAuth_M[COCHA_NOCYLCUTAUTH_M_LNS][COCHA_NOCYLCUTAUTH_M_COLS] = {0};
const sint16  CoCha_tqLimMin_C = 0;
const uint16  CoCha_nEngBkpt_A[COCHA_NENGBKPT_A_COLS] = {0};
const uint16  CoCha_rAirLdBkpt_A[COCHA_RAIRLDBKPT_A_COLS] = {0};
const uint16  CoCha_tqDifTqBkpt_A[COCHA_TQDIFTQBKPT_A_COLS] = {0};
const uint16  CoCha_tqOfsDif_M[COCHA_TQOFSDIF_M_LNS][COCHA_TQOFSDIF_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoCha_bTypFil_MP;
sint16 CHATQAIRCORD_s16FilterOutput;
sint16 CoCha_tqAirFil_MP;
sint16 CoCha_tqEfcASRAirReq;
uint16 CHATQAIRCORD_u16CoChaTqDifT;
uint16 CoCha_tqDeltaASROfs_MP;
sint32 CHATQAIRCORD_s32FilterKMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

