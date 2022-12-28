/***************************************************************************
;**
;** FILE NAME      : VLVACTINMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINMNG.H"
#include "VLVACTINMNG_L.H"
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
const boolean  VlvAct_bInMngClnBenchEna_C = 0;
const boolean  VlvAct_bInMngUnlckStEna_C = 0;
const uint8  VlvAct_agInAcvSpFuncIntlThd_C = 0;
const uint8  VlvAct_agInAcvSpFuncIntlThdHys_C = 0;
const uint8  VlvAct_agInAcvUnlckPosnThd_C = 0;
const uint8  VlvAct_agInAcvUnlckPosnThdHys_C = 0;
const uint8  VlvAct_InEngStopCmdThd_C = 0;
const uint8  VlvAct_InEngStopPosnMax_C = 0;
const uint8  VlvAct_InLihValCmd_C = 0;
const uint8  VlvAct_InTOilMaxValCmd_C = 0;
const uint8  VlvAct_nEngInLrnThdHi_C = 0;
const uint8  VlvAct_nEngInLrnThdHiHys_C = 0;
const uint8  VlvAct_nEngInLrnThdLo_C = 0;
const uint8  VlvAct_nEngInLrnThdLoHys_C = 0;
const uint8  VlvAct_nEngInServoThdLo_C = 0;
const uint8  VlvAct_nEngInServoThdLoHys_C = 0;
const uint8  VlvAct_nEngInUnlckThdLo_C = 0;
const uint8  VlvAct_nEngInUnlckThdLoHys_C = 0;
const uint8  VlvAct_noInUnlckStrThd_M[VLVACT_NOINUNLCKSTRTHD_M_COLS] = {0};
const uint8  VlvAct_tCoInCmdAuthDly_T[VLVACT_TCOINCMDAUTHDLY_T_COLS] = {0};
const uint8  VlvAct_tiInEngStopAuthDly_M[VLVACT_TIINENGSTOPAUTHDLY_M_LNS][VLVACT_TIINENGSTOPAUTHDLY_M_COLS] = {0};
const uint8  VlvAct_tiInEngStopDftAuthDly_C = 0;
const uint8  VlvAct_tiInLrnEngRunDly_C = 0;
const uint8  VlvAct_tiInLrnOilPresDly_C = 0;
const uint8  VlvAct_tiInUnlckIni_M[VLVACT_TIINUNLCKINI_M_COLS] = {0};
const uint8  VlvAct_tiInUnlckSlop_M[VLVACT_TIINUNLCKSLOP_M_COLS] = {0};
const uint8  VlvAct_tiInUnlckStab_M[VLVACT_TIINUNLCKSTAB_M_COLS] = {0};
const uint8  VlvAct_uBattInLrnThdHi_C = 0;
const uint8  VlvAct_uBattInLrnThdHiHys_C = 0;
const uint8  VlvAct_uBattInLrnThdLo_C = 0;
const uint8  VlvAct_uBattInLrnThdLoHys_C = 0;
const uint8  VlvAct_uBattInServoThdLo_C = 0;
const uint8  VlvAct_uBattInServoThdLoHys_C = 0;
const uint8  VLVACTINMNG_u8Inhib = 0;
const sint16  VlvAct_tCoInLrnThdHi_C = 0;
const sint16  VlvAct_tCoInLrnThdHiHys_C = 0;
const sint16  VlvAct_tCoInLrnThdLo_C = 0;
const sint16  VlvAct_tCoInLrnThdLoHys_C = 0;
const sint16  VlvAct_tOilInInitThdHi_C = 0;
const sint16  VlvAct_tOilInInitThdHiHys_C = 0;
const sint16  VlvAct_tOilInLrnThdHi_C = 0;
const sint16  VlvAct_tOilInLrnThdHiHys_C = 0;
const sint16  VlvAct_tOilInLrnThdLo_C = 0;
const sint16  VlvAct_tOilInLrnThdLoHys_C = 0;
const sint16  VlvAct_tOilInServoThdLo_C = 0;
const sint16  VlvAct_tOilInServoThdLoHys_C = 0;
const sint16  VlvAct_tOilInUnlckThdHi_C = 0;
const sint16  VlvAct_tOilInUnlckThdHiHys_C = 0;
const uint16  VlvAct_InUnlckCmdIni_M[VLVACT_INUNLCKCMDINI_M_COLS] = {0};
const uint16  VlvAct_InUnlckCmdMin_C = 0;
const uint16  VlvAct_InUnlckCmdStab_M[VLVACT_INUNLCKCMDSTAB_M_COLS] = {0};
const uint16  VlvAct_InUnlckSlop1_M[VLVACT_INUNLCKSLOP1_M_COLS] = {0};
const uint16  VlvAct_InUnlckSlop2_M[VLVACT_INUNLCKSLOP2_M_COLS] = {0};
const uint16  VlvAct_tiInCmdAuthDly_M[VLVACT_TIINCMDAUTHDLY_M_COLS] = {0};
const uint16  VlvAct_tOilInEngStopAuthDly_T[VLVACT_TOILINENGSTOPAUTHDLY_T_COLS] = {0};
const uint16  VlvAct_tOilInUnlckStr_T[VLVACT_TOILINUNLCKSTR_T_COLS] = {0};
const uint16  VlvAct_uBattInEngStopAuthDly_T[VLVACT_UBATTINENGSTOPAUTHDLY_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 VlvAct_InMngSt;
uint8 VlvAct_InUnlckStrSt;
boolean VlvAct_bInClnEna;
boolean VlvAct_bInCmdAuth;
boolean VlvAct_bInEngStopAuth;
boolean VlvAct_bInInUnlckStrEndIdc;
boolean VlvAct_bInLrnEna;
boolean VlvAct_bInMngClnStEna;
boolean VlvAct_bInMngInitStEna;
boolean VlvAct_bInMngLrnStEna;
boolean VlvAct_bInMngServoStEna;
boolean VlvAct_bInMngUnlckStEna;
boolean VlvAct_bInServoEna;
boolean VlvAct_bInUnlckEna;
boolean VLVACTINMNG_bagInAcvSpFuncIntThd;
boolean VLVACTINMNG_bAgInAcvUnlckPosnThd;
boolean VLVACTINMNG_bInLrnHyst01;
boolean VLVACTINMNG_bInLrnHyst02;
boolean VLVACTINMNG_bInLrnHyst03;
boolean VLVACTINMNG_bInLrnHyst04;
boolean VLVACTINMNG_bInLrnHyst05;
boolean VLVACTINMNG_bInLrnHyst06;
boolean VLVACTINMNG_bInLrnHyst07;
boolean VLVACTINMNG_bInLrnHyst08;
boolean VLVACTINMNG_bInServoHyst01;
boolean VLVACTINMNG_bInServoHyst02;
boolean VLVACTINMNG_bInServoHyst03;
boolean VLVACTINMNG_bNEngInUnlckThd;
boolean VLVACTINMNG_bOilPresPrev;
boolean VLVACTINMNG_bTimeout1;
boolean VLVACTINMNG_bTimeout2;
boolean VLVACTINMNG_bTimeout3;
boolean VLVACTINMNG_bTimeout4;
boolean VLVACTINMNG_bTimeout5;
boolean VLVACTINMNG_bTimer1Input;
boolean VLVACTINMNG_bTimer2Input;
boolean VLVACTINMNG_bTOilInUnlckThd;
boolean VLVACTINMNG_bVehicleStatePrev;
uint8 VlvAct_noInUnlckStr;
uint8 VlvAct_noInUnlckStrThd;
uint8 VlvAct_tiInUnlck;
uint8 VlvAct_tiInUnlckIni;
uint8 VlvAct_tiInUnlckSlop;
uint8 VlvAct_tiInUnlckStab;
uint8 VLVACTINMNG_u8Tempo1;
uint8 VLVACTINMNG_u8Tempo2;
uint8 VLVACTINMNG_u8Tempo3;
uint8 VLVACTINMNG_u8Tempo4;
uint8 VLVACTINMNG_u8VehActStatPrev;
uint16 VlvAct_InMngStCmd;
uint16 VlvAct_InUnlckCmd;
uint16 VlvAct_InUnlckCmdIni;
uint16 VlvAct_InUnlckCmdStab;
uint16 VlvAct_InUnlckSlop1;
uint16 VlvAct_InUnlckSlop2;
uint16 VLVACTINMNG_u16Tempo5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

