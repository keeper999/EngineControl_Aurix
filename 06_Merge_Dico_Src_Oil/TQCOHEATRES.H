/***************************************************************************
;**
;** FILE NAME      : TQCOHEATRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCOHEATRES_H
#define TQCOHEATRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_FACCORCOHEATRES_M_LNS           ( 8 )
#define TQRES_FACCORCOHEATRES_M_COLS           ( 8 )
#define TQRES_NENGCOHEATRES_A_COLS             ( 8 )
#define TQRES_TQCKENGCOHEATRES_A_COLS          ( 8 )
#define TQRES_TQCOHEATRES_M_LNS               ( 8 )
#define TQRES_TQCOHEATRES_M_COLS               ( 8 )

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

extern const boolean  TqRes_bAcvCoHeatRes_C;
extern const uint8  TqRes_facCorCoHeatRes_M[TQRES_FACCORCOHEATRES_M_LNS][TQRES_FACCORCOHEATRES_M_COLS];
extern const sint16  TqRes_tqDecMaxCoHeatRes_C;
extern const uint16  TqRes_nEngCoHeatRes_A[TQRES_NENGCOHEATRES_A_COLS];
extern const uint16  TqRes_tqCkEngCoHeatRes_A[TQRES_TQCKENGCOHEATRES_A_COLS];
extern const uint16  TqRes_tqCoHeatRes_M[TQRES_TQCOHEATRES_M_LNS][TQRES_TQCOHEATRES_M_COLS];
extern const uint16  TqRes_tqIncMaxCoHeatRes_C;
extern const uint16  TqRes_tqMaxCoHeatRes_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqCoHeatRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCOHEATRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqCoHeatRes(void);


#endif /* TQCOHEATRES_H */

/*-------------------------------- end of file -------------------------------*/
