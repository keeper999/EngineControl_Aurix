/***************************************************************************
;**
;** FILE NAME      : CHATQAIRCORD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CHATQAIRCORD_H
#define CHATQAIRCORD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COCHA_FACTAUDOWN_T_COLS                ( 12 )
#define COCHA_NENGBKPT_A_COLS                  ( 12 )
#define COCHA_NOCYLCUTAUTH_M_LNS              ( 12 )
#define COCHA_NOCYLCUTAUTH_M_COLS              ( 12 )
#define COCHA_RAIRLDBKPT_A_COLS                ( 12 )
#define COCHA_TQDIFTQBKPT_A_COLS               ( 12 )
#define COCHA_TQOFSDIF_M_LNS                  ( 12 )
#define COCHA_TQOFSDIF_M_COLS                  ( 12 )

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

extern const boolean  CoCha_bAcvCutSelASR_C;
extern const boolean  CoCha_bAcvCutSelSecu_C;
extern const boolean  CoCha_bOfsClcTyp_C;
extern const boolean  TqCha_bTqASRSel_C;
extern const boolean  TqCha_bTqMSRSel_C;
extern const uint8  CoCha_facTauDown_T[COCHA_FACTAUDOWN_T_COLS];
extern const uint8  CoCha_facTauDownThermo_C;
extern const uint8  CoCha_facTauUp_C;
extern const uint8  CoCha_facTauUpThermo_C;
extern const uint8  CoCha_noCylCutAuth_M[COCHA_NOCYLCUTAUTH_M_LNS][COCHA_NOCYLCUTAUTH_M_COLS];
extern const sint16  CoCha_tqLimMin_C;
extern const uint16  CoCha_nEngBkpt_A[COCHA_NENGBKPT_A_COLS];
extern const uint16  CoCha_rAirLdBkpt_A[COCHA_RAIRLDBKPT_A_COLS];
extern const uint16  CoCha_tqDifTqBkpt_A[COCHA_TQDIFTQBKPT_A_COLS];
extern const uint16  CoCha_tqOfsDif_M[COCHA_TQOFSDIF_M_LNS][COCHA_TQOFSDIF_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint16 CoCha_tqEfcASRAirReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CHATQAIRCORD_vidEntryInit(void);
void TqSys_Sdl10ms_TqCha(void);


#endif /* CHATQAIRCORD_H */

/*-------------------------------- end of file -------------------------------*/
