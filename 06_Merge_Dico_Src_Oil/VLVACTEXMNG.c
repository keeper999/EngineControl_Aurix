/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXMNG.H"
#include "VLVACTEXMNG_L.H"
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
const boolean  VlvAct_bExMngClnBenchEna_C = 0;
const boolean  VlvAct_bExMngUnlckStEna_C = 0;
const uint8  VlvAct_agExAcvSpFuncIntlThd_C = 0;
const uint8  VlvAct_agExAcvSpFuncIntlThdHys_C = 0;
const uint8  VlvAct_agExAcvUnlckPosnThd_C = 0;
const uint8  VlvAct_agExAcvUnlckPosnThdHys_C = 0;
const uint8  VlvAct_ExEngStopCmdThd_C = 0;
const uint8  VlvAct_ExEngStopPosnMax_C = 0;
const uint8  VlvAct_nEngExLrnThdHi_C = 0;
const uint8  VlvAct_nEngExLrnThdHiHys_C = 0;
const uint8  VlvAct_nEngExLrnThdLo_C = 0;
const uint8  VlvAct_nEngExLrnThdLoHys_C = 0;
const uint8  VlvAct_nEngExServoThdLo_C = 0;
const uint8  VlvAct_nEngExServoThdLoHys_C = 0;
const uint8  VlvAct_nEngExUnlckThdLo_C = 0;
const uint8  VlvAct_nEngExUnlckThdLoHys_C = 0;
const uint8  VlvAct_noExUnlckStrThd_M[VLVACT_NOEXUNLCKSTRTHD_M_COLS] = {0};
const uint8  VlvAct_tCoExCmdAuthDly_T[VLVACT_TCOEXCMDAUTHDLY_T_COLS] = {0};
const uint8  VlvAct_tiExEngStopAuthDly_M[VLVACT_TIEXENGSTOPAUTHDLY_M_LNS][VLVACT_TIEXENGSTOPAUTHDLY_M_COLS] = {0};
const uint8  VlvAct_tiExEngStopDftAuthDly_C = 0;
const uint8  VlvAct_tiExLrnEngRunDly_C = 0;
const uint8  VlvAct_tiExLrnOilPresDly_C = 0;
const uint8  VlvAct_tiExUnlckIni_M[VLVACT_TIEXUNLCKINI_M_COLS] = {0};
const uint8  VlvAct_tiExUnlckSlop_M[VLVACT_TIEXUNLCKSLOP_M_COLS] = {0};
const uint8  VlvAct_tiExUnlckStab_M[VLVACT_TIEXUNLCKSTAB_M_COLS] = {0};
const uint8  VlvAct_uBattExLrnThdHi_C = 0;
const uint8  VlvAct_uBattExLrnThdHiHys_C = 0;
const uint8  VlvAct_uBattExLrnThdLo_C = 0;
const uint8  VlvAct_uBattExLrnThdLoHys_C = 0;
const uint8  VlvAct_uBattExServoThdLo_C = 0;
const uint8  VlvAct_uBattExServoThdLoHys_C = 0;
const uint8  VLVACTEXMNG_u8Inhib = 0;
const sint16  VlvAct_tCoExLrnThdHi_C = 0;
const sint16  VlvAct_tCoExLrnThdHiHys_C = 0;
const sint16  VlvAct_tCoExLrnThdLo_C = 0;
const sint16  VlvAct_tCoExLrnThdLoHys_C = 0;
const sint16  VlvAct_tOilExInitThdHi_C = 0;
const sint16  VlvAct_tOilExInitThdHiHys_C = 0;
const sint16  VlvAct_tOilExLrnThdHi_C = 0;
const sint16  VlvAct_tOilExLrnThdHiHys_C = 0;
const sint16  VlvAct_tOilExLrnThdLo_C = 0;
const sint16  VlvAct_tOilExLrnThdLoHys_C = 0;
const sint16  VlvAct_tOilExServoThdLo_C = 0;
const sint16  VlvAct_tOilExServoThdLoHys_C = 0;
const sint16  VlvAct_tOilExUnlckThdHi_C = 0;
const sint16  VlvAct_tOilExUnlckThdHiHys_C = 0;
const uint16  VlvAct_ExLihValCmd_C = 0;
const uint16  VlvAct_ExTOilMaxValCmd_C = 0;
const uint16  VlvAct_ExUnlckCmdIni_M[VLVACT_EXUNLCKCMDINI_M_COLS] = {0};
const uint16  VlvAct_ExUnlckCmdMin_C = 0;
const uint16  VlvAct_ExUnlckCmdStab_M[VLVACT_EXUNLCKCMDSTAB_M_COLS] = {0};
const uint16  VlvAct_ExUnlckSlop1_M[VLVACT_EXUNLCKSLOP1_M_COLS] = {0};
const uint16  VlvAct_ExUnlckSlop2_M[VLVACT_EXUNLCKSLOP2_M_COLS] = {0};
const uint16  VlvAct_tiExCmdAuthDly_M[VLVACT_TIEXCMDAUTHDLY_M_COLS] = {0};
const uint16  VlvAct_tOilExEngStopAuthDly_T[VLVACT_TOILEXENGSTOPAUTHDLY_T_COLS] = {0};
const uint16  VlvAct_tOilExUnlckStr_T[VLVACT_TOILEXUNLCKSTR_T_COLS] = {0};
const uint16  VlvAct_uBattExEngStopAuthDly_T[VLVACT_UBATTEXENGSTOPAUTHDLY_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_ExMngSt;
uint8 VlvAct_ExUnlckStrSt;
boolean VlvAct_bExClnEna;
boolean VlvAct_bExCmdAuth;
boolean VlvAct_bExEngStopAuth;
boolean VlvAct_bExLrnEna;
boolean VlvAct_bExMngClnStEna;
boolean VlvAct_bExMngInitStEna;
boolean VlvAct_bExMngLrnStEna;
boolean VlvAct_bExMngServoStEna;
boolean VlvAct_bExMngUnlckStEna;
boolean VlvAct_bExServoEna;
boolean VlvAct_bExUnlckEna;
boolean VlvAct_bExUnlckStrEndIdc;
boolean VLVACTEXMNG_bAgExAcvSpFuncIntThd;
boolean VLVACTEXMNG_bAgExAcvUnlckPosnThd;
boolean VLVACTEXMNG_bExLrnHyst01;
boolean VLVACTEXMNG_bExLrnHyst02;
boolean VLVACTEXMNG_bExLrnHyst03;
boolean VLVACTEXMNG_bExLrnHyst04;
boolean VLVACTEXMNG_bExLrnHyst05;
boolean VLVACTEXMNG_bExLrnHyst06;
boolean VLVACTEXMNG_bExLrnHyst07;
boolean VLVACTEXMNG_bExLrnHyst08;
boolean VLVACTEXMNG_bExServoHyst01;
boolean VLVACTEXMNG_bExServoHyst02;
boolean VLVACTEXMNG_bExServoHyst03;
boolean VLVACTEXMNG_bNEngExUnlckThd;
boolean VLVACTEXMNG_bOilPresPrev;
boolean VLVACTEXMNG_bTimeout1;
boolean VLVACTEXMNG_bTimeout2;
boolean VLVACTEXMNG_bTimeout3;
boolean VLVACTEXMNG_bTimeout4;
boolean VLVACTEXMNG_bTimeout5;
boolean VLVACTEXMNG_bTimer1Input;
boolean VLVACTEXMNG_bTimer2Input;
boolean VLVACTEXMNG_bTOilExUnlckThd;
boolean VLVACTEXMNG_bVehicleStatePrev;
uint8 VlvAct_noExUnlckStr;
uint8 VlvAct_noExUnlckStrThd;
uint8 VlvAct_tiExUnlck;
uint8 VlvAct_tiExUnlckIni;
uint8 VlvAct_tiExUnlckSlop;
uint8 VlvAct_tiExUnlckStab;
uint8 VLVACTEXMNG_u8Tempo1;
uint8 VLVACTEXMNG_u8Tempo2;
uint8 VLVACTEXMNG_u8Tempo3;
uint8 VLVACTEXMNG_u8Tempo4;
uint8 VLVACTEXMNG_u8VehActStatPrev;
uint16 VlvAct_ExMngStCmd;
uint16 VlvAct_ExUnlckCmd;
uint16 VlvAct_ExUnlckCmdIni;
uint16 VlvAct_ExUnlckCmdStab;
uint16 VlvAct_ExUnlckSlop1;
uint16 VlvAct_ExUnlckSlop2;
uint16 VLVACTEXMNG_u16ExMngStCmdPrev;
uint16 VLVACTEXMNG_u16Tempo5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

