/***************************************************************************
;**
;** FILE NAME      : AIRTFONCDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTFONCDIAG_H
#define AIRTFONCDIAG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRT_TAIREXTMES_A_COLS                 ( 8 )
#define AIRT_TDSTHR_PAIREXTMES_T_COLS          ( 8 )

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

extern const uint32  AirT_tiDlyTDsThrStallCoh_C;
extern const uint8  AirT_spdVehThdMaxTNegOfs_C;
extern const uint8  AirT_spdVehThdMinTPosOfs_C;
extern const uint8  AirT_tAirExtMes_A[AIRT_TAIREXTMES_A_COLS];
extern const uint8  AirT_tDsThr_pAirExtMes_T[AIRT_TDSTHR_PAIREXTMES_T_COLS];
extern const uint8  AirT_tDsThrStallCoh_C;
extern const sint16  AirT_tCoThdMaxTNegOfs_C;
extern const sint16  AirT_tDsThrThdMaxPosOfs_C;
extern const sint16  AirT_tDsThrThdORngMax_C;
extern const sint16  AirT_tDsThrThdORngMin_C;
extern const uint16  AirT_mfAirThdMinTPosOfs_C;
extern const uint16  AirT_tiDlyEngrunTNegOfs_C;
extern const uint16  AirT_tiDlyIdlCtlTNegOfs_C;
extern const uint16  AirT_tiDlymaxTDsThrStallCoh_C;
extern const uint16  AirT_tiDlymfAirCorPosOfs_C;
extern const uint16  AirT_tiDlyTPosOfs_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirT_SdlMid_MonAirT(void);
void AIRTFONCDIAG_vidEntryInit(void);


#endif /* AIRTFONCDIAG_H */

/*-------------------------------- end of file -------------------------------*/
