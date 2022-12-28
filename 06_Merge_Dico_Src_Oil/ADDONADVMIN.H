/***************************************************************************
;**
;** FILE NAME      : ADDONADVMIN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVMIN_H
#define ADDONADVMIN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_NENGOFSAGIGMIN_A_COLS            ( 16 )
#define IGSYS_NENGOFSAGIGMINSHOIDL_A_COLS      ( 8 )
#define IGSYS_OFSAGIGMINCAL1_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL1_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL10_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMINCAL10_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMINCAL11_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMINCAL11_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMINCAL12_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMINCAL12_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMINCAL13_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMINCAL13_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMINCAL2_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL2_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL3_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL3_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL4_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL4_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL5_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL5_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL6_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL6_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL7_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL7_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL8_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMINCAL8_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMINCAL9_M_LNS            ( 8 )
#define IGSYS_OFSAGIGMINCAL9_M_COLS            ( 8 )
#define IGSYS_RAIRLDOFSAGIGMIN_A_COLS          ( 16 )
#define IGSYS_RAIRLDOFSAGIGMINSHOIDL_A_COLS    ( 8 )

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

extern const uint8  IgSys_ofsAgIgMinCal1_M[IGSYS_OFSAGIGMINCAL1_M_LNS][IGSYS_OFSAGIGMINCAL1_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal10_M[IGSYS_OFSAGIGMINCAL10_M_LNS][IGSYS_OFSAGIGMINCAL10_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal11_M[IGSYS_OFSAGIGMINCAL11_M_LNS][IGSYS_OFSAGIGMINCAL11_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal12_M[IGSYS_OFSAGIGMINCAL12_M_LNS][IGSYS_OFSAGIGMINCAL12_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal13_M[IGSYS_OFSAGIGMINCAL13_M_LNS][IGSYS_OFSAGIGMINCAL13_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal2_M[IGSYS_OFSAGIGMINCAL2_M_LNS][IGSYS_OFSAGIGMINCAL2_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal3_M[IGSYS_OFSAGIGMINCAL3_M_LNS][IGSYS_OFSAGIGMINCAL3_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal4_M[IGSYS_OFSAGIGMINCAL4_M_LNS][IGSYS_OFSAGIGMINCAL4_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal5_M[IGSYS_OFSAGIGMINCAL5_M_LNS][IGSYS_OFSAGIGMINCAL5_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal6_M[IGSYS_OFSAGIGMINCAL6_M_LNS][IGSYS_OFSAGIGMINCAL6_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal7_M[IGSYS_OFSAGIGMINCAL7_M_LNS][IGSYS_OFSAGIGMINCAL7_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal8_M[IGSYS_OFSAGIGMINCAL8_M_LNS][IGSYS_OFSAGIGMINCAL8_M_COLS];
extern const uint8  IgSys_ofsAgIgMinCal9_M[IGSYS_OFSAGIGMINCAL9_M_LNS][IGSYS_OFSAGIGMINCAL9_M_COLS];
extern const sint16  IgSys_ofsAgIgMinCal14_C;
extern const uint16  IgSys_nEngOfsAgIgMin_A[IGSYS_NENGOFSAGIGMIN_A_COLS];
extern const uint16  IgSys_nEngOfsAgIgMinShoIdl_A[IGSYS_NENGOFSAGIGMINSHOIDL_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgMin_A[IGSYS_RAIRLDOFSAGIGMIN_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgMinShoIdl_A[IGSYS_RAIRLDOFSAGIGMINSHOIDL_A_COLS];

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

void ADDONADVMIN_vidEntryInit(void);
void IgSys_EveTDC_AddOnAdvMin(void);


#endif /* ADDONADVMIN_H */

/*-------------------------------- end of file -------------------------------*/
