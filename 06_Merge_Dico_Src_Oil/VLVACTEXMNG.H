/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXMNG_H
#define VLVACTEXMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_EXUNLCKCMDINI_M_COLS            ( 5 )
#define VLVACT_EXUNLCKCMDSTAB_M_COLS           ( 5 )
#define VLVACT_EXUNLCKSLOP1_M_COLS             ( 5 )
#define VLVACT_EXUNLCKSLOP2_M_COLS             ( 5 )
#define VLVACT_NOEXUNLCKSTRTHD_M_COLS          ( 5 )
#define VLVACT_TCOEXCMDAUTHDLY_T_COLS          ( 5 )
#define VLVACT_TIEXCMDAUTHDLY_M_COLS           ( 5 )
#define VLVACT_TIEXENGSTOPAUTHDLY_M_LNS       ( 5 )
#define VLVACT_TIEXENGSTOPAUTHDLY_M_COLS       ( 5 )
#define VLVACT_TIEXUNLCKINI_M_COLS             ( 5 )
#define VLVACT_TIEXUNLCKSLOP_M_COLS            ( 5 )
#define VLVACT_TIEXUNLCKSTAB_M_COLS            ( 5 )
#define VLVACT_TOILEXENGSTOPAUTHDLY_T_COLS     ( 5 )
#define VLVACT_TOILEXUNLCKSTR_T_COLS           ( 5 )
#define VLVACT_UBATTEXENGSTOPAUTHDLY_T_COLS    ( 5 )

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

extern const boolean  VlvAct_bExMngClnBenchEna_C;
extern const boolean  VlvAct_bExMngUnlckStEna_C;
extern const uint8  VlvAct_agExAcvSpFuncIntlThd_C;
extern const uint8  VlvAct_agExAcvSpFuncIntlThdHys_C;
extern const uint8  VlvAct_agExAcvUnlckPosnThd_C;
extern const uint8  VlvAct_agExAcvUnlckPosnThdHys_C;
extern const uint8  VlvAct_ExEngStopCmdThd_C;
extern const uint8  VlvAct_ExEngStopPosnMax_C;
extern const uint8  VlvAct_nEngExLrnThdHi_C;
extern const uint8  VlvAct_nEngExLrnThdHiHys_C;
extern const uint8  VlvAct_nEngExLrnThdLo_C;
extern const uint8  VlvAct_nEngExLrnThdLoHys_C;
extern const uint8  VlvAct_nEngExServoThdLo_C;
extern const uint8  VlvAct_nEngExServoThdLoHys_C;
extern const uint8  VlvAct_nEngExUnlckThdLo_C;
extern const uint8  VlvAct_nEngExUnlckThdLoHys_C;
extern const uint8  VlvAct_noExUnlckStrThd_M[VLVACT_NOEXUNLCKSTRTHD_M_COLS];
extern const uint8  VlvAct_tCoExCmdAuthDly_T[VLVACT_TCOEXCMDAUTHDLY_T_COLS];
extern const uint8  VlvAct_tiExEngStopAuthDly_M[VLVACT_TIEXENGSTOPAUTHDLY_M_LNS][VLVACT_TIEXENGSTOPAUTHDLY_M_COLS];
extern const uint8  VlvAct_tiExEngStopDftAuthDly_C;
extern const uint8  VlvAct_tiExLrnEngRunDly_C;
extern const uint8  VlvAct_tiExLrnOilPresDly_C;
extern const uint8  VlvAct_tiExUnlckIni_M[VLVACT_TIEXUNLCKINI_M_COLS];
extern const uint8  VlvAct_tiExUnlckSlop_M[VLVACT_TIEXUNLCKSLOP_M_COLS];
extern const uint8  VlvAct_tiExUnlckStab_M[VLVACT_TIEXUNLCKSTAB_M_COLS];
extern const uint8  VlvAct_uBattExLrnThdHi_C;
extern const uint8  VlvAct_uBattExLrnThdHiHys_C;
extern const uint8  VlvAct_uBattExLrnThdLo_C;
extern const uint8  VlvAct_uBattExLrnThdLoHys_C;
extern const uint8  VlvAct_uBattExServoThdLo_C;
extern const uint8  VlvAct_uBattExServoThdLoHys_C;
extern const sint16  VlvAct_tCoExLrnThdHi_C;
extern const sint16  VlvAct_tCoExLrnThdHiHys_C;
extern const sint16  VlvAct_tCoExLrnThdLo_C;
extern const sint16  VlvAct_tCoExLrnThdLoHys_C;
extern const sint16  VlvAct_tOilExInitThdHi_C;
extern const sint16  VlvAct_tOilExInitThdHiHys_C;
extern const sint16  VlvAct_tOilExLrnThdHi_C;
extern const sint16  VlvAct_tOilExLrnThdHiHys_C;
extern const sint16  VlvAct_tOilExLrnThdLo_C;
extern const sint16  VlvAct_tOilExLrnThdLoHys_C;
extern const sint16  VlvAct_tOilExServoThdLo_C;
extern const sint16  VlvAct_tOilExServoThdLoHys_C;
extern const sint16  VlvAct_tOilExUnlckThdHi_C;
extern const sint16  VlvAct_tOilExUnlckThdHiHys_C;
extern const uint16  VlvAct_ExLihValCmd_C;
extern const uint16  VlvAct_ExTOilMaxValCmd_C;
extern const uint16  VlvAct_ExUnlckCmdIni_M[VLVACT_EXUNLCKCMDINI_M_COLS];
extern const uint16  VlvAct_ExUnlckCmdMin_C;
extern const uint16  VlvAct_ExUnlckCmdStab_M[VLVACT_EXUNLCKCMDSTAB_M_COLS];
extern const uint16  VlvAct_ExUnlckSlop1_M[VLVACT_EXUNLCKSLOP1_M_COLS];
extern const uint16  VlvAct_ExUnlckSlop2_M[VLVACT_EXUNLCKSLOP2_M_COLS];
extern const uint16  VlvAct_tiExCmdAuthDly_M[VLVACT_TIEXCMDAUTHDLY_M_COLS];
extern const uint16  VlvAct_tOilExEngStopAuthDly_T[VLVACT_TOILEXENGSTOPAUTHDLY_T_COLS];
extern const uint16  VlvAct_tOilExUnlckStr_T[VLVACT_TOILEXUNLCKSTR_T_COLS];
extern const uint16  VlvAct_uBattExEngStopAuthDly_T[VLVACT_UBATTEXENGSTOPAUTHDLY_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bExClnEna;
extern boolean VlvAct_bExCmdAuth;
extern boolean VlvAct_bExEngStopAuth;
extern boolean VlvAct_bExLrnEna;
extern boolean VlvAct_bExMngLrnStEna;
extern boolean VlvAct_bExMngServoStEna;
extern boolean VlvAct_bExServoEna;
extern uint16 VlvAct_ExMngStCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_SdlFast_ExMng_1(void);
void VlvAct_SdlFast_ExMng_2(void);
void VLVACTEXMNG_vidEntryInit(void);


#endif /* VLVACTEXMNG_H */

/*-------------------------------- end of file -------------------------------*/
