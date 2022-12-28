/***************************************************************************
;**
;** FILE NAME      : TQESTMAX.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQESTMAX_H
#define TQESTMAX_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COPT_FACACVTQMAXESTIM_T_COLS           ( 10 )
#define COPT_FACDEACTQMAXESTIM_T_COLS          ( 10 )
#define COPT_FACFILTQMAXESTIM_M_LNS           ( 10 )
#define COPT_FACFILTQMAXESTIM_M_COLS           ( 10 )
#define COPT_NENGTQMAXESTIMX_A_COLS            ( 10 )
#define COPT_NODLYTQMAX_T_COLS                 ( 10 )
#define COPT_TQFILTQMAXESTIMY_A_COLS           ( 10 )

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

extern const boolean  CoPt_bAcvASRUp_C;
extern const boolean  CoPt_bAcvTqResEstim_C;
extern const boolean  CoPt_bAuthTqMaxEstimSIP_C;
extern const boolean  CoPt_bDeacInhPrepSIP_C;
extern const boolean  CoPt_bSelTqAirDrv_C;
extern const boolean  CoPt_bSelTqAirMSR_C;
extern const uint8  CoPt_facAcvTqMaxEstim_T[COPT_FACACVTQMAXESTIM_T_COLS];
extern const uint8  CoPt_facDeacTqMaxEstim_T[COPT_FACDEACTQMAXESTIM_T_COLS];
extern const uint8  CoPt_facFilTqMaxEstim_M[COPT_FACFILTQMAXESTIM_M_LNS][COPT_FACFILTQMAXESTIM_M_COLS];
extern const uint8  CoPt_noDlyTqMax_T[COPT_NODLYTQMAX_T_COLS];
extern const sint16  CoPt_tqThdAcvEstim1_C;
extern const sint16  CoPt_tqThdAcvEstim2_C;
extern const sint16  CoPt_tqThdAcvTqMaxEstim_C;
extern const uint16  Copt_nEngTqMaxEstimX_A[COPT_NENGTQMAXESTIMX_A_COLS];
extern const uint16  CoPt_tqFilTqMaxEstimY_A[COPT_TQFILTQMAXESTIMY_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPt_bAcvTqMaxEstimSIP;
extern sint16 CoPt_tqEfcAirMaxEstim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQESTMAX_TqSys_EveSync(void);
void TQESTMAX_vidEntryInit(void);


#endif /* TQESTMAX_H */

/*-------------------------------- end of file -------------------------------*/
