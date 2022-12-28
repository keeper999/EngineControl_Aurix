/***************************************************************************
;**
;** FILE NAME      : SPTMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPTMOD_H
#define SPTMOD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_NENGMODSPT_A_COLS                ( 16 )
#define TQSYS_NOGEARMODSPT_A_COLS              ( 8 )
#define TQSYS_PBOOSTMAXMODSPT_T_COLS           ( 5 )
#define TQSYS_PEXTMODSPTY_A_COLS               ( 5 )
#define TQSYS_PWRMAXMODSPT_T_COLS              ( 5 )
#define TQSYS_RPRFNOMMODSPT_T_COLS             ( 16 )
#define TQSYS_TIFILTQEFCFILMODSPT_M_LNS       ( 16 )
#define TQSYS_TIFILTQEFCFILMODSPT_M_COLS       ( 5 )
#define TQSYS_TIFILTQEFCMODSPT_M_LNS          ( 16 )
#define TQSYS_TIFILTQEFCMODSPT_M_COLS          ( 5 )
#define TQSYS_TQEFCMAXGBXMODSPT_T_COLS         ( 8 )
#define TQSYS_TQEFCMAXMODSPT_T_COLS            ( 5 )
#define TQSYS_TQEFCMAXNOMMODSPT_M_LNS         ( 16 )
#define TQSYS_TQEFCMAXNOMMODSPT_M_COLS         ( 5 )
#define TQSYS_TQEFCMAXTRBOFF_T_COLS            ( 16 )

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

extern const boolean  TqSys_bBoostPresSelModSpt_C;
extern const boolean  TqSys_bChaRegSelModSpt_C;
extern const uint8  TqSys_facAntiOscFilModSpt_C;
extern const uint8  TqSys_facAntiOscModSpt_C;
extern const uint8  TqSys_idxTqEfcModSptSel_C;
extern const uint8  TqSys_noGearModSpt_A[TQSYS_NOGEARMODSPT_A_COLS];
extern const uint8  TqSys_rHystPrfNomModSpt_C;
extern const uint8  TqSys_rPrfNomModSpt_T[TQSYS_RPRFNOMMODSPT_T_COLS];
extern const uint8  TqSys_spdHystIdlModSpt_C;
extern const uint8  TqSys_tiDeltaFootOffFilModSpt_C;
extern const uint8  TqSys_tiDeltaFootOffModSpt_C;
extern const uint8  TqSys_tiFilTqEfcFilModSpt_M[TQSYS_TIFILTQEFCFILMODSPT_M_LNS][TQSYS_TIFILTQEFCFILMODSPT_M_COLS];
extern const uint8  TqSys_tiFilTqEfcModSpt_M[TQSYS_TIFILTQEFCMODSPT_M_LNS][TQSYS_TIFILTQEFCMODSPT_M_COLS];
extern const uint16  TqSys_nEngModSpt_A[TQSYS_NENGMODSPT_A_COLS];
extern const uint16  TqSys_pBoostMaxModSpt_T[TQSYS_PBOOSTMAXMODSPT_T_COLS];
extern const uint16  TqSys_pExtModSptY_A[TQSYS_PEXTMODSPTY_A_COLS];
extern const uint16  TqSys_pwrMaxModSpt_T[TQSYS_PWRMAXMODSPT_T_COLS];
extern const uint16  TqSys_rAccPFootOffModSpt_C;
extern const uint16  TqSys_spdThdIdlModSpt_C;
extern const uint16  TqSys_tqEfcMaxGBxModSpt_T[TQSYS_TQEFCMAXGBXMODSPT_T_COLS];
extern const uint16  TqSys_tqEfcMaxModSpt_T[TQSYS_TQEFCMAXMODSPT_T_COLS];
extern const uint16  TqSys_tqEfcMaxNomModSpt_M[TQSYS_TQEFCMAXNOMMODSPT_M_LNS][TQSYS_TQEFCMAXNOMMODSPT_M_COLS];
extern const uint16  TqSys_tqEfcMaxTrbOff_T[TQSYS_TQEFCMAXTRBOFF_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 TqSys_rBoostPresSndModSpt;
extern uint8 TqSys_rPwrEngSndModSpt;
extern uint8 TqSys_rTqEfcSndModSpt;
extern uint8 TqSys_stModSpt;
extern uint16 TqSys_pBoostSndModSpt;
extern uint16 TqSys_pwrEngSndModSpt;
extern uint16 TqSys_tqEfcSndModSpt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SPTMOD_vidEntryInit(void);
void TqSys_Sdl10ms_SptMod(void);


#endif /* SPTMOD_H */

/*-------------------------------- end of file -------------------------------*/
