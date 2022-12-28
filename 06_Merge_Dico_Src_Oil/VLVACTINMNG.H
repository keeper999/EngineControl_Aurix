/***************************************************************************
;**
;** FILE NAME      : VLVACTINMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINMNG_H
#define VLVACTINMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_INUNLCKCMDINI_M_COLS            ( 5 )
#define VLVACT_INUNLCKCMDSTAB_M_COLS           ( 5 )
#define VLVACT_INUNLCKSLOP1_M_COLS             ( 5 )
#define VLVACT_INUNLCKSLOP2_M_COLS             ( 5 )
#define VLVACT_NOINUNLCKSTRTHD_M_COLS          ( 5 )
#define VLVACT_TCOINCMDAUTHDLY_T_COLS          ( 5 )
#define VLVACT_TIINCMDAUTHDLY_M_COLS           ( 5 )
#define VLVACT_TIINENGSTOPAUTHDLY_M_LNS       ( 5 )
#define VLVACT_TIINENGSTOPAUTHDLY_M_COLS       ( 5 )
#define VLVACT_TIINUNLCKINI_M_COLS             ( 5 )
#define VLVACT_TIINUNLCKSLOP_M_COLS            ( 5 )
#define VLVACT_TIINUNLCKSTAB_M_COLS            ( 5 )
#define VLVACT_TOILINENGSTOPAUTHDLY_T_COLS     ( 5 )
#define VLVACT_TOILINUNLCKSTR_T_COLS           ( 5 )
#define VLVACT_UBATTINENGSTOPAUTHDLY_T_COLS    ( 5 )

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

extern const boolean  VlvAct_bInMngClnBenchEna_C;
extern const boolean  VlvAct_bInMngUnlckStEna_C;
extern const uint8  VlvAct_agInAcvSpFuncIntlThd_C;
extern const uint8  VlvAct_agInAcvSpFuncIntlThdHys_C;
extern const uint8  VlvAct_agInAcvUnlckPosnThd_C;
extern const uint8  VlvAct_agInAcvUnlckPosnThdHys_C;
extern const uint8  VlvAct_InEngStopCmdThd_C;
extern const uint8  VlvAct_InEngStopPosnMax_C;
extern const uint8  VlvAct_InLihValCmd_C;
extern const uint8  VlvAct_InTOilMaxValCmd_C;
extern const uint8  VlvAct_nEngInLrnThdHi_C;
extern const uint8  VlvAct_nEngInLrnThdHiHys_C;
extern const uint8  VlvAct_nEngInLrnThdLo_C;
extern const uint8  VlvAct_nEngInLrnThdLoHys_C;
extern const uint8  VlvAct_nEngInServoThdLo_C;
extern const uint8  VlvAct_nEngInServoThdLoHys_C;
extern const uint8  VlvAct_nEngInUnlckThdLo_C;
extern const uint8  VlvAct_nEngInUnlckThdLoHys_C;
extern const uint8  VlvAct_noInUnlckStrThd_M[VLVACT_NOINUNLCKSTRTHD_M_COLS];
extern const uint8  VlvAct_tCoInCmdAuthDly_T[VLVACT_TCOINCMDAUTHDLY_T_COLS];
extern const uint8  VlvAct_tiInEngStopAuthDly_M[VLVACT_TIINENGSTOPAUTHDLY_M_LNS][VLVACT_TIINENGSTOPAUTHDLY_M_COLS];
extern const uint8  VlvAct_tiInEngStopDftAuthDly_C;
extern const uint8  VlvAct_tiInLrnEngRunDly_C;
extern const uint8  VlvAct_tiInLrnOilPresDly_C;
extern const uint8  VlvAct_tiInUnlckIni_M[VLVACT_TIINUNLCKINI_M_COLS];
extern const uint8  VlvAct_tiInUnlckSlop_M[VLVACT_TIINUNLCKSLOP_M_COLS];
extern const uint8  VlvAct_tiInUnlckStab_M[VLVACT_TIINUNLCKSTAB_M_COLS];
extern const uint8  VlvAct_uBattInLrnThdHi_C;
extern const uint8  VlvAct_uBattInLrnThdHiHys_C;
extern const uint8  VlvAct_uBattInLrnThdLo_C;
extern const uint8  VlvAct_uBattInLrnThdLoHys_C;
extern const uint8  VlvAct_uBattInServoThdLo_C;
extern const uint8  VlvAct_uBattInServoThdLoHys_C;
extern const sint16  VlvAct_tCoInLrnThdHi_C;
extern const sint16  VlvAct_tCoInLrnThdHiHys_C;
extern const sint16  VlvAct_tCoInLrnThdLo_C;
extern const sint16  VlvAct_tCoInLrnThdLoHys_C;
extern const sint16  VlvAct_tOilInInitThdHi_C;
extern const sint16  VlvAct_tOilInInitThdHiHys_C;
extern const sint16  VlvAct_tOilInLrnThdHi_C;
extern const sint16  VlvAct_tOilInLrnThdHiHys_C;
extern const sint16  VlvAct_tOilInLrnThdLo_C;
extern const sint16  VlvAct_tOilInLrnThdLoHys_C;
extern const sint16  VlvAct_tOilInServoThdLo_C;
extern const sint16  VlvAct_tOilInServoThdLoHys_C;
extern const sint16  VlvAct_tOilInUnlckThdHi_C;
extern const sint16  VlvAct_tOilInUnlckThdHiHys_C;
extern const uint16  VlvAct_InUnlckCmdIni_M[VLVACT_INUNLCKCMDINI_M_COLS];
extern const uint16  VlvAct_InUnlckCmdMin_C;
extern const uint16  VlvAct_InUnlckCmdStab_M[VLVACT_INUNLCKCMDSTAB_M_COLS];
extern const uint16  VlvAct_InUnlckSlop1_M[VLVACT_INUNLCKSLOP1_M_COLS];
extern const uint16  VlvAct_InUnlckSlop2_M[VLVACT_INUNLCKSLOP2_M_COLS];
extern const uint16  VlvAct_tiInCmdAuthDly_M[VLVACT_TIINCMDAUTHDLY_M_COLS];
extern const uint16  VlvAct_tOilInEngStopAuthDly_T[VLVACT_TOILINENGSTOPAUTHDLY_T_COLS];
extern const uint16  VlvAct_tOilInUnlckStr_T[VLVACT_TOILINUNLCKSTR_T_COLS];
extern const uint16  VlvAct_uBattInEngStopAuthDly_T[VLVACT_UBATTINENGSTOPAUTHDLY_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bInClnEna;
extern boolean VlvAct_bInCmdAuth;
extern boolean VlvAct_bInEngStopAuth;
extern boolean VlvAct_bInLrnEna;
extern boolean VlvAct_bInMngLrnStEna;
extern boolean VlvAct_bInMngServoStEna;
extern boolean VlvAct_bInServoEna;
extern uint16 VlvAct_InMngStCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_SdlFast_InMng_1(void);
void VlvAct_SdlFast_InMng_2(void);
void VLVACTINMNG_vidEntryInit(void);


#endif /* VLVACTINMNG_H */

/*-------------------------------- end of file -------------------------------*/
