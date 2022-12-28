/***************************************************************************
;**
;** FILE NAME      : TQACRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQACRES_H
#define TQACRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_PAC_A_COLS                       ( 8 )
#define TQRES_TQAC3RES_T_COLS                  ( 8 )
#define TQRES_TQAC4RES_A_COLS                  ( 8 )
#define TQRES_TQAC4RES_T_COLS                  ( 8 )

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

extern const boolean  TqRes_bAuthFrzAC_C;
extern const boolean  TqRes_bInhResACCluOp_C;
extern const uint8  TqRes_pAC_A[TQRES_PAC_A_COLS];
extern const uint8  TqRes_pwrACSftyACRes_C;
extern const uint8  TqRes_pwrACThrFrzAC_C;
extern const uint8  TqRes_tiAC3Res_C;
extern const uint8  TqRes_tiAC4Res_C;
extern const uint8  TqRes_tiAC4ResTmpMax_C;
extern const sint16  TqRes_tqDecMaxACRes_C;
extern const uint16  TqRes_nEngThdOptmRes_C;
extern const uint16  TqRes_nEngThrFrzAC_C;
extern const uint16  TqRes_tqAC3Res_T[TQRES_TQAC3RES_T_COLS];
extern const uint16  TqRes_tqAC4Res_A[TQRES_TQAC4RES_A_COLS];
extern const uint16  TqRes_tqAC4Res_T[TQRES_TQAC4RES_T_COLS];
extern const uint16  TqRes_tqDftValACRes_C;
extern const uint16  TqRes_tqIncMaxACRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqACRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQACRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqACRes(void);
void TqRes_Sdl20ms_tqACRes(void);


#endif /* TQACRES_H */

/*-------------------------------- end of file -------------------------------*/
