/***************************************************************************
;**
;** FILE NAME      : THRBENCHMODE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRBENCHMODE_H
#define THRBENCHMODE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define THR_NENGX_A_COLS                       ( 16 )
#define THR_POSNSP_NENGX_TQIDCAIRY_M_LNS      ( 16 )
#define THR_POSNSP_NENGX_TQIDCAIRY_M_COLS      ( 16 )
#define THR_TQIDCAIRY_A_COLS                   ( 16 )

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

extern const boolean  Thr_bAcvSpBenchMod_C;
extern const uint16  Thr_nEngX_A[THR_NENGX_A_COLS];
extern const uint16  Thr_posnSp_nEngX_tqIdcAirY_M[THR_POSNSP_NENGX_TQIDCAIRY_M_LNS][THR_POSNSP_NENGX_TQIDCAIRY_M_COLS];
extern const uint16  Thr_posnSpBenchModMaxRate_C;
extern const uint16  Thr_posnSpBenchModMinRate_C;
extern const uint16  Thr_tqIdcAirY_A[THR_TQIDCAIRY_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bAcvSpBenchMod;
extern uint16 Thr_posnSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveRst_SpBenchMod(void);
void Thr_SdlMid_SpBenchMod(void);


#endif /* THRBENCHMODE_H */

/*-------------------------------- end of file -------------------------------*/
