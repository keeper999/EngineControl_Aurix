/***************************************************************************
;**
;** FILE NAME      : TQADVMIN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQADVMIN_H
#define TQADVMIN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQADVMIN_NENG_A_COLS                   ( 6 )
#define TQADVMIN_TITRANCLL_T_COLS              ( 6 )
#define TQADVMIN_TQINCCLL_T_COLS               ( 6 )
#define TQADVMIN_TQTHDACVCLLLO_T_COLS          ( 6 )

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

extern const uint16  TqAdvMin_nEng_A[TQADVMIN_NENG_A_COLS];
extern const uint16  TqAdvMin_tiTranCll_T[TQADVMIN_TITRANCLL_T_COLS];
extern const uint16  TqAdvMin_tqAcvCllOfs_C;
extern const uint16  TqAdvMin_tqIncCll_T[TQADVMIN_TQINCCLL_T_COLS];
extern const uint16  TqAdvMin_tqThdAcvCllLo_T[TQADVMIN_TQTHDACVCLLLO_T_COLS];

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

void TQADVMIN_vidEntryInit(void);
void TqSys_Sdl20ms_TqAdvMin(void);


#endif /* TQADVMIN_H */

/*-------------------------------- end of file -------------------------------*/
