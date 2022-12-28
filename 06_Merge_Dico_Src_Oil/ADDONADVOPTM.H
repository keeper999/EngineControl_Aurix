/***************************************************************************
;**
;** FILE NAME      : ADDONADVOPTM.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONADVOPTM_H
#define ADDONADVOPTM_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_NENGOFSAGIGOPTM_A_COLS           ( 16 )
#define IGSYS_NENGOFSAGIGOPTMSHOIDL_A_COLS     ( 8 )
#define IGSYS_OFSAGIGOPTMCAL1_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL1_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL10_M_LNS          ( 16 )
#define IGSYS_OFSAGIGOPTMCAL10_M_COLS          ( 16 )
#define IGSYS_OFSAGIGOPTMCAL11_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL11_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL12_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL12_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL13_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL13_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL14_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL14_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL15_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL15_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL16_M_LNS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL16_M_COLS          ( 8 )
#define IGSYS_OFSAGIGOPTMCAL2_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL2_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL3_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL3_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL4_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL4_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL5_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL5_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL6_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL6_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL7_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL7_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL8_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL8_M_COLS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL9_M_LNS           ( 16 )
#define IGSYS_OFSAGIGOPTMCAL9_M_COLS           ( 16 )
#define IGSYS_RAIRLDOFSAGIGOPTM_A_COLS         ( 16 )
#define IGSYS_RAIRLDOFSAGIGOPTMSHOIDL_A_COLS   ( 8 )

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

extern const uint8  IgSys_ofsAgIgOptmCal1_M[IGSYS_OFSAGIGOPTMCAL1_M_LNS][IGSYS_OFSAGIGOPTMCAL1_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal10_M[IGSYS_OFSAGIGOPTMCAL10_M_LNS][IGSYS_OFSAGIGOPTMCAL10_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal11_M[IGSYS_OFSAGIGOPTMCAL11_M_LNS][IGSYS_OFSAGIGOPTMCAL11_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal12_M[IGSYS_OFSAGIGOPTMCAL12_M_LNS][IGSYS_OFSAGIGOPTMCAL12_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal13_M[IGSYS_OFSAGIGOPTMCAL13_M_LNS][IGSYS_OFSAGIGOPTMCAL13_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal14_M[IGSYS_OFSAGIGOPTMCAL14_M_LNS][IGSYS_OFSAGIGOPTMCAL14_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal15_M[IGSYS_OFSAGIGOPTMCAL15_M_LNS][IGSYS_OFSAGIGOPTMCAL15_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal16_M[IGSYS_OFSAGIGOPTMCAL16_M_LNS][IGSYS_OFSAGIGOPTMCAL16_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal2_M[IGSYS_OFSAGIGOPTMCAL2_M_LNS][IGSYS_OFSAGIGOPTMCAL2_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal3_M[IGSYS_OFSAGIGOPTMCAL3_M_LNS][IGSYS_OFSAGIGOPTMCAL3_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal4_M[IGSYS_OFSAGIGOPTMCAL4_M_LNS][IGSYS_OFSAGIGOPTMCAL4_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal5_M[IGSYS_OFSAGIGOPTMCAL5_M_LNS][IGSYS_OFSAGIGOPTMCAL5_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal6_M[IGSYS_OFSAGIGOPTMCAL6_M_LNS][IGSYS_OFSAGIGOPTMCAL6_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal7_M[IGSYS_OFSAGIGOPTMCAL7_M_LNS][IGSYS_OFSAGIGOPTMCAL7_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal8_M[IGSYS_OFSAGIGOPTMCAL8_M_LNS][IGSYS_OFSAGIGOPTMCAL8_M_COLS];
extern const uint8  IgSys_ofsAgIgOptmCal9_M[IGSYS_OFSAGIGOPTMCAL9_M_LNS][IGSYS_OFSAGIGOPTMCAL9_M_COLS];
extern const sint16  IgSys_ofsAgIgOptmCal17_C;
extern const uint16  IgSys_nEngOfsAgIgOptm_A[IGSYS_NENGOFSAGIGOPTM_A_COLS];
extern const uint16  IgSys_nEngOfsAgIgOptmShoIdl_A[IGSYS_NENGOFSAGIGOPTMSHOIDL_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgOptm_A[IGSYS_RAIRLDOFSAGIGOPTM_A_COLS];
extern const uint16  IgSys_rAirLdOfsAgIgOptmShoIdl_A[IGSYS_RAIRLDOFSAGIGOPTMSHOIDL_A_COLS];

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

void ADDONADVOPTM_vidEntryInit(void);
void IgSys_EveTDC_AddOnAdvOptm(void);


#endif /* ADDONADVOPTM_H */

/*-------------------------------- end of file -------------------------------*/
