/***************************************************************************
;**
;** FILE NAME      : TQLNCHRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQLNCHRES_H
#define TQLNCHRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_TQCKEFC_A_COLS                   ( 8 )
#define TQRES_TQLNCHRES_M_LNS                 ( 8 )
#define TQRES_TQLNCHRES_M_COLS                 ( 8 )

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

extern const boolean  TqRes_bAcvCdnAccLnchRes_C;
extern const boolean  TqRes_bAcvCdnCluLnchRes_C;
extern const boolean  TqRes_bAcvCdnSpdLnchRes_C;
extern const boolean  TqRes_bCfCluLnchRes_C;
extern const uint8  TqRes_rAccThrLnchRes_C;
extern const uint8  TqRes_rCluThrLnchRes_C;
extern const uint8  TqRes_spdThrHiLnchRes_C;
extern const uint8  TqRes_spdThrLoLnchRes_C;
extern const uint8  TqRes_tiCdnCluLnchRes_C;
extern const uint8  TqRes_tiCdnNEngLnchRes_C;
extern const uint8  TqRes_tiCdnSpdLnchRes_C;
extern const sint16  TqRes_tqDecMaxLnchRes_C;
extern const uint16  TqRes_nEngOfsLnchRes_C;
extern const uint16  TqRes_tqCkEfc_A[TQRES_TQCKEFC_A_COLS];
extern const uint16  TqRes_tqIncMaxLnchRes_C;
extern const uint16  TqRes_tqLnchRes_M[TQRES_TQLNCHRES_M_LNS][TQRES_TQLNCHRES_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqLnchRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQLNCHRES_vidEntry_10ms(void);
void TQLNCHRES_vidEntryInit(void);


#endif /* TQLNCHRES_H */

/*-------------------------------- end of file -------------------------------*/
