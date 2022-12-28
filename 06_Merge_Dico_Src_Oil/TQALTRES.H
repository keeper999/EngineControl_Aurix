/***************************************************************************
;**
;** FILE NAME      : TQALTRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQALTRES_H
#define TQALTRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_IALTFIL_A_COLS                   ( 8 )
#define TQRES_IDXALTSTDCLAS_T_COLS             ( 8 )
#define TQRES_RALTFIL_A_COLS                   ( 8 )
#define TQRES_TQALTRESGAPCLAS1_T_COLS          ( 8 )
#define TQRES_TQALTRESGAPCLAS2_T_COLS          ( 8 )
#define TQRES_TQALTRESGAPCLAS3_T_COLS          ( 8 )
#define TQRES_TQALTRESSTDCLAS1_T_COLS          ( 8 )
#define TQRES_TQALTRESSTDCLAS2_T_COLS          ( 8 )
#define TQRES_TQALTRESSTDCLAS3_T_COLS          ( 8 )

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

extern const uint8  TqRes_facFilDuCyAltRes_C;
extern const uint8  TqRes_facFilIAltRes_C;
extern const uint8  TqRes_iAltFil_A[TQRES_IALTFIL_A_COLS];
extern const uint8  TqRes_idxAltGapClas2_C;
extern const uint8  TqRes_idxAltGapClas3_C;
extern const uint8  TqRes_idxAltStdClas_T[TQRES_IDXALTSTDCLAS_T_COLS];
extern const uint8  TqRes_rAltFil_A[TQRES_RALTFIL_A_COLS];
extern const uint8  TqRes_tiCdnNEngAltRes_C;
extern const sint16  TqRes_tqDecMaxAltRes_C;
extern const uint16  TqRes_nEngOfsLoAltRes_C;
extern const uint16  TqRes_nEngThrHiAltRes_C;
extern const uint16  TqRes_tqAltResGapClas1_T[TQRES_TQALTRESGAPCLAS1_T_COLS];
extern const uint16  TqRes_tqAltResGapClas2_T[TQRES_TQALTRESGAPCLAS2_T_COLS];
extern const uint16  TqRes_tqAltResGapClas3_T[TQRES_TQALTRESGAPCLAS3_T_COLS];
extern const uint16  TqRes_tqAltResStdClas1_T[TQRES_TQALTRESSTDCLAS1_T_COLS];
extern const uint16  TqRes_tqAltResStdClas2_T[TQRES_TQALTRESSTDCLAS2_T_COLS];
extern const uint16  TqRes_tqAltResStdClas3_T[TQRES_TQALTRESSTDCLAS3_T_COLS];
extern const uint16  TqRes_tqDftValAltRes_C;
extern const uint16  TqRes_tqIncMaxAltRes_C;
extern const uint16  TqRes_tqUHAltRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqAltRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQALTRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqAltRes(void);


#endif /* TQALTRES_H */

/*-------------------------------- end of file -------------------------------*/
