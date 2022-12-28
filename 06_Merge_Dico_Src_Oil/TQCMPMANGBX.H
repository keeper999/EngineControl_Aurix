/***************************************************************************
;**
;** FILE NAME      : TQCMPMANGBX.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCMPMANGBX_H
#define TQCMPMANGBX_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQCMP_TAIRMANGBXLOSSX_A_COLS           ( 6 )
#define TQCMP_TIENGRUNCLUMANGBXY_A_COLS        ( 6 )
#define TQCMP_TISTOPMANGBXY_A_COLS             ( 6 )
#define TQCMP_TMANGBXLOSS_M_LNS               ( 6 )
#define TQCMP_TMANGBXLOSS_M_COLS               ( 6 )
#define TQCMP_TMANGBXX_A_COLS                  ( 6 )
#define TQCMP_TQMANGBXLOSS_M_LNS              ( 6 )
#define TQCMP_TQMANGBXLOSS_M_COLS              ( 6 )

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

extern const boolean  TqCmp_bInhTqManGBxLoss_C;
extern const uint8  TqCmp_facTOilFilManGBx_C;
extern const uint8  TqCmp_tAirManGBxLossX_A[TQCMP_TAIRMANGBXLOSSX_A_COLS];
extern const uint8  TqCmp_tiEngRunCluManGBxY_A[TQCMP_TIENGRUNCLUMANGBXY_A_COLS];
extern const uint8  TqCmp_tManGBxLoss_M[TQCMP_TMANGBXLOSS_M_LNS][TQCMP_TMANGBXLOSS_M_COLS];
extern const uint8  TqCmp_tManGBxX_A[TQCMP_TMANGBXX_A_COLS];
extern const uint8  TqCmp_tOfsOilMinManGBx_C;
extern const uint16  TqCmp_tiEngStop_C;
extern const uint16  TqCmp_tiStopManGBxY_A[TQCMP_TISTOPMANGBXY_A_COLS];
extern const uint16  TqCmp_tqManGBxLoss_M[TQCMP_TQMANGBXLOSS_M_LNS][TQCMP_TQMANGBXLOSS_M_COLS];

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

void TQCMPMANGBX_vidEntryInit(void);
void TqSys_Sdl20ms_TqCmpManGBx(void);


#endif /* TQCMPMANGBX_H */

/*-------------------------------- end of file -------------------------------*/
