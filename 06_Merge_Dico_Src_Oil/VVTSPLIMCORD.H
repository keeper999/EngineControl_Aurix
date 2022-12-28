/***************************************************************************
;**
;** FILE NAME      : VVTSPLIMCORD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VVTSPLIMCORD_H
#define VVTSPLIMCORD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXM_NENGCORX_A_COLS                    ( 8 )
#define EXM_RAIRCORY_A_COLS                    ( 8 )
#define EXM_TEXOFSCAL1_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL1_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL10_M_LNS                 ( 8 )
#define EXM_TEXOFSCAL10_M_COLS                 ( 8 )
#define EXM_TEXOFSCAL11_M_LNS                 ( 8 )
#define EXM_TEXOFSCAL11_M_COLS                 ( 8 )
#define EXM_TEXOFSCAL12_M_LNS                 ( 8 )
#define EXM_TEXOFSCAL12_M_COLS                 ( 8 )
#define EXM_TEXOFSCAL13_M_LNS                 ( 8 )
#define EXM_TEXOFSCAL13_M_COLS                 ( 8 )
#define EXM_TEXOFSCAL2_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL2_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL3_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL3_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL4_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL4_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL5_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL5_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL6_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL6_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL7_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL7_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL8_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL8_M_COLS                  ( 8 )
#define EXM_TEXOFSCAL9_M_LNS                  ( 8 )
#define EXM_TEXOFSCAL9_M_COLS                  ( 8 )

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

extern const sint8  ExM_tExOfsCal14_C;
extern const uint8  ExM_tExOfsCal1_M[EXM_TEXOFSCAL1_M_LNS][EXM_TEXOFSCAL1_M_COLS];
extern const uint8  ExM_tExOfsCal10_M[EXM_TEXOFSCAL10_M_LNS][EXM_TEXOFSCAL10_M_COLS];
extern const uint8  ExM_tExOfsCal11_M[EXM_TEXOFSCAL11_M_LNS][EXM_TEXOFSCAL11_M_COLS];
extern const uint8  ExM_tExOfsCal12_M[EXM_TEXOFSCAL12_M_LNS][EXM_TEXOFSCAL12_M_COLS];
extern const uint8  ExM_tExOfsCal13_M[EXM_TEXOFSCAL13_M_LNS][EXM_TEXOFSCAL13_M_COLS];
extern const uint8  ExM_tExOfsCal2_M[EXM_TEXOFSCAL2_M_LNS][EXM_TEXOFSCAL2_M_COLS];
extern const uint8  ExM_tExOfsCal3_M[EXM_TEXOFSCAL3_M_LNS][EXM_TEXOFSCAL3_M_COLS];
extern const uint8  ExM_tExOfsCal4_M[EXM_TEXOFSCAL4_M_LNS][EXM_TEXOFSCAL4_M_COLS];
extern const uint8  ExM_tExOfsCal5_M[EXM_TEXOFSCAL5_M_LNS][EXM_TEXOFSCAL5_M_COLS];
extern const uint8  ExM_tExOfsCal6_M[EXM_TEXOFSCAL6_M_LNS][EXM_TEXOFSCAL6_M_COLS];
extern const uint8  ExM_tExOfsCal7_M[EXM_TEXOFSCAL7_M_LNS][EXM_TEXOFSCAL7_M_COLS];
extern const uint8  ExM_tExOfsCal8_M[EXM_TEXOFSCAL8_M_LNS][EXM_TEXOFSCAL8_M_COLS];
extern const uint8  ExM_tExOfsCal9_M[EXM_TEXOFSCAL9_M_LNS][EXM_TEXOFSCAL9_M_COLS];
extern const uint16  ExM_nEngCorX_A[EXM_NENGCORX_A_COLS];
extern const uint16  ExM_rAirCorY_A[EXM_RAIRCORY_A_COLS];

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

void ExM_SdlFast_ExOfs(void);
void VVTSPLIMCORD_vidEntryInit(void);


#endif /* VVTSPLIMCORD_H */

/*-------------------------------- end of file -------------------------------*/
