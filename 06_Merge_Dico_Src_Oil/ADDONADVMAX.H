/***************************************************************************
;**
;** FILE NAME      : ADDONADVMAX.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVMAX_H
#define ADDONADVMAX_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_NENGOFSAGIGMAX_A_COLS            ( 16 )
#define IGSYS_NENGOFSAGIGMAXSHOIDL_A_COLS      ( 8 )
#define IGSYS_OFSAGIGMAXCAL1_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL1_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL10_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL10_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL11_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL11_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL12_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL12_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL13_M_LNS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL13_M_COLS           ( 8 )
#define IGSYS_OFSAGIGMAXCAL2_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL2_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL3_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL3_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL4_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL4_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL5_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL5_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL6_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL6_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL7_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL7_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL8_M_LNS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL8_M_COLS            ( 16 )
#define IGSYS_OFSAGIGMAXCAL9_M_LNS            ( 8 )
#define IGSYS_OFSAGIGMAXCAL9_M_COLS            ( 8 )
#define IGSYS_RAIRLDOFSAGIGMAX_A_COLS          ( 16 )
#define IGSYS_RAIRLDOFSAGIGMAXSHOIDL_A_COLS    ( 8 )

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

extern const uint8  IgSys_ofsAgIgMaxCal1_M[IGSYS_OFSAGIGMAXCAL1_M_LNS][IGSYS_OFSAGIGMAXCAL1_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal10_M[IGSYS_OFSAGIGMAXCAL10_M_LNS][IGSYS_OFSAGIGMAXCAL10_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal11_M[IGSYS_OFSAGIGMAXCAL11_M_LNS][IGSYS_OFSAGIGMAXCAL11_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal12_M[IGSYS_OFSAGIGMAXCAL12_M_LNS][IGSYS_OFSAGIGMAXCAL12_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal13_M[IGSYS_OFSAGIGMAXCAL13_M_LNS][IGSYS_OFSAGIGMAXCAL13_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal2_M[IGSYS_OFSAGIGMAXCAL2_M_LNS][IGSYS_OFSAGIGMAXCAL2_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal3_M[IGSYS_OFSAGIGMAXCAL3_M_LNS][IGSYS_OFSAGIGMAXCAL3_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal4_M[IGSYS_OFSAGIGMAXCAL4_M_LNS][IGSYS_OFSAGIGMAXCAL4_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal5_M[IGSYS_OFSAGIGMAXCAL5_M_LNS][IGSYS_OFSAGIGMAXCAL5_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal6_M[IGSYS_OFSAGIGMAXCAL6_M_LNS][IGSYS_OFSAGIGMAXCAL6_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal7_M[IGSYS_OFSAGIGMAXCAL7_M_LNS][IGSYS_OFSAGIGMAXCAL7_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal8_M[IGSYS_OFSAGIGMAXCAL8_M_LNS][IGSYS_OFSAGIGMAXCAL8_M_COLS];
extern const uint8  IgSys_ofsAgIgMaxCal9_M[IGSYS_OFSAGIGMAXCAL9_M_LNS][IGSYS_OFSAGIGMAXCAL9_M_COLS];
extern const sint16  IgSys_ofsAgIgMaxCal14_C;
extern const uint16  IgSys_nEngOfsAgIgMax_A[IGSYS_NENGOFSAGIGMAX_A_COLS];
extern const uint16  IgSys_nEngOfsAgIgMaxShoIdl_A[IGSYS_NENGOFSAGIGMAXSHOIDL_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgMax_A[IGSYS_RAIRLDOFSAGIGMAX_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgMaxShoIdl_A[IGSYS_RAIRLDOFSAGIGMAXSHOIDL_A_COLS];

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

void ADDONADVMAX_vidEntryInit(void);
void IgSys_EveTDC_AddOnAdvMax(void);


#endif /* ADDONADVMAX_H */

/*-------------------------------- end of file -------------------------------*/
