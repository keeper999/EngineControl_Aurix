/***************************************************************************
;**
;** FILE NAME      : FCTDIAGWG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGWG_H
#define FCTDIAGWG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define WG_NDIFPUSTHR_A_COLS                   ( 8 )
#define WG_NENG_PAIREXTMES_T_COLS              ( 8 )
#define WG_NENGMAX_PAIREXTMES_T_COLS           ( 8 )
#define WG_NENGX_A_COLS                        ( 8 )
#define WG_PAIREXTMES_A_COLS                   ( 8 )
#define WG_PAIREXTMESINTERY_A_COLS             ( 8 )
#define WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_LNS  ( 8 )
#define WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_COLS  ( 8 )
#define Wg_SampleTiFast_SC                10
#define WG_TIDIFPUSTHR_T_COLS                  ( 8 )

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

extern const uint8  Wg_rClsThdThr_C;
extern const uint8  Wg_tiDifpUsThr_T[WG_TIDIFPUSTHR_T_COLS];
extern const sint16  Wg_pUsThrNatStuckClsOfs_C;
extern const sint16  Wg_pUsThrNatStuckOpOfs_C;
extern const uint16  Wg_nDifpUsThr_A[WG_NDIFPUSTHR_A_COLS];
extern const uint16  Wg_nEng_pAirExtMes_T[WG_NENG_PAIREXTMES_T_COLS];
extern const uint16  Wg_nEngMax_pAirExtMes_T[WG_NENGMAX_PAIREXTMES_T_COLS];
extern const uint16  Wg_nEngX_A[WG_NENGX_A_COLS];
extern const uint16  Wg_pAirExtMes_A[WG_PAIREXTMES_A_COLS];
extern const uint16  Wg_pAirExtMes_C;
extern const uint16  Wg_pAirExtMesInter_C;
extern const uint16  Wg_pAirExtMesInterY_A[WG_PAIREXTMESINTERY_A_COLS];
extern const uint16  Wg_pTrbActStuckOp_C;
extern const uint16  Wg_pUsThrNat_nEngX_pAirExtMesY_M[WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_LNS][WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_COLS];
extern const uint16  Wg_tiTrbActStuckCls_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Wg_pUsThrNat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Wg_EveRst_FctDiagWg(void);
void Wg_SdlFast_FctDiagWg(void);


#endif /* FCTDIAGWG_H */

/*-------------------------------- end of file -------------------------------*/
