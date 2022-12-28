/***************************************************************************
;**
;** FILE NAME      : TQESTMAX.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQESTMAX.H"
#include "TQESTMAX_L.H"
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
const boolean  CoPt_bAcvASRUp_C = 0;
const boolean  CoPt_bAcvTqResEstim_C = 0;
const boolean  CoPt_bAuthTqMaxEstimSIP_C = 0;
const boolean  CoPt_bDeacInhPrepSIP_C = 0;
const boolean  CoPt_bSelTqAirDrv_C = 0;
const boolean  CoPt_bSelTqAirMSR_C = 0;
const uint8  CoPt_facAcvTqMaxEstim_T[COPT_FACACVTQMAXESTIM_T_COLS] = {0};
const uint8  CoPt_facDeacTqMaxEstim_T[COPT_FACDEACTQMAXESTIM_T_COLS] = {0};
const uint8  CoPt_facFilTqMaxEstim_M[COPT_FACFILTQMAXESTIM_M_LNS][COPT_FACFILTQMAXESTIM_M_COLS] = {0};
const uint8  CoPt_noDlyTqMax_T[COPT_NODLYTQMAX_T_COLS] = {0};
const uint8  TQESTMAX_u8Inhib = 0;
const sint16  CoPt_tqThdAcvEstim1_C = 0;
const sint16  CoPt_tqThdAcvEstim2_C = 0;
const sint16  CoPt_tqThdAcvTqMaxEstim_C = 0;
const uint16  Copt_nEngTqMaxEstimX_A[COPT_NENGTQMAXESTIMX_A_COLS] = {0};
const uint16  CoPt_tqFilTqMaxEstimY_A[COPT_TQFILTQMAXESTIMY_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoPt_bAcvTqMaxEstimSIP;
boolean CoPt_bAcvTqMaxEstimTq_MP;
boolean CoPt_bASR;
boolean CoPt_bAuthTqMaxEstimSIP;
boolean TQESTMAX_bRSOutput;
uint8 CoPt_facTqMaxEstim;
uint8 TQESTMAX_u8Cha_stTqReqPrev;
uint8 TQESTMAX_u8CoPfacTqMaxEstimPrev2;
uint8 TQESTMAX_u8CoPtfacTqMaxEstimPrev;
sint16 CoPt_stepFacTqMaxEstim_MP;
sint16 CoPt_tqAirLimEstim;
sint16 CoPt_tqEfcAirEstimDly;
sint16 CoPt_tqEfcAirEstimRaw;
sint16 CoPt_tqEfcAirMaxEstim;
sint16 CoPt_tqEfcAirMaxFil;
sint16 CoPt_tqEfcAirMaxFil1;
sint16 TQESTMAX_as16TqEfcAirEstimRaw[TQESTMAX_AS16TQEFCAIRESTIMRAW_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

