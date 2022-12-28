/***************************************************************************
;**
;** FILE NAME      : FCTDIAGWG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FCTDIAGWG.H"
#include "FCTDIAGWG_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const uint8  FCTDIAGWG_u8Inhib = 0;
const uint8  Wg_rClsThdThr_C = 0;
const uint8  Wg_tiDifpUsThr_T[WG_TIDIFPUSTHR_T_COLS] = {0};
const sint16  Wg_pUsThrNatStuckClsOfs_C = 0;
const sint16  Wg_pUsThrNatStuckOpOfs_C = 0;
const uint16  Wg_nDifpUsThr_A[WG_NDIFPUSTHR_A_COLS] = {0};
const uint16  Wg_nEng_pAirExtMes_T[WG_NENG_PAIREXTMES_T_COLS] = {0};
const uint16  Wg_nEngMax_pAirExtMes_T[WG_NENGMAX_PAIREXTMES_T_COLS] = {0};
const uint16  Wg_nEngX_A[WG_NENGX_A_COLS] = {0};
const uint16  Wg_pAirExtMes_A[WG_PAIREXTMES_A_COLS] = {0};
const uint16  Wg_pAirExtMes_C = 0;
const uint16  Wg_pAirExtMesInter_C = 0;
const uint16  Wg_pAirExtMesInterY_A[WG_PAIREXTMESINTERY_A_COLS] = {0};
const uint16  Wg_pTrbActStuckOp_C = 0;
const uint16  Wg_pUsThrNat_nEngX_pAirExtMesY_M[WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_LNS][WG_PUSTHRNAT_NENGX_PAIREXTMESY_M_COLS] = {0};
const uint16  Wg_tiTrbActStuckCls_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean FCTDIAGWG_bTimeout1;
boolean FCTDIAGWG_bTimerInit;
boolean Wg_bDgoStuckCls_pTrbAct;
boolean Wg_bDgoStuckOp_pTrbAct;
boolean Wg_bMonRunStuckCls_pTrbAct;
boolean Wg_bMonRunStuckOp_pTrbAct;
uint8 Wg_tiStuckOp;
uint16 Wg_pAirExtMesInter;
uint16 Wg_pTrbActStuckOp;
uint16 Wg_pUsThrNat;
uint16 Wg_pUsThrNatStuckCls;
uint16 Wg_tiStuckCls;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

