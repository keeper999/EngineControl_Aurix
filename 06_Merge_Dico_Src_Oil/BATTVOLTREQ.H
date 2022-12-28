/***************************************************************************
;**
;** FILE NAME      : BATTVOLTREQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BATTVOLTREQ_H
#define BATTVOLTREQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BOOSTREQ_PAIREXT_A_COLS                ( 5 )
#define BOOSTREQ_RDUCYTHD_T_COLS               ( 5 )

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

extern const boolean  BoostReq_bAcvBattVoltReq_C;
extern const boolean  BoostReq_bAcvFrzMod_C;
extern const boolean  BoostReq_bAcvStraBattVoltReq_C;
extern const boolean  BoostReq_bBattVoltReqIni_C;
extern const uint16  BoostReq_pAirExt_A[BOOSTREQ_PAIREXT_A_COLS];
extern const uint16  BoostReq_pAirExtHiThd_C;
extern const uint16  BoostReq_pAirExtLoThd_C;
extern const uint16  BoostReq_rDuCyMaxThd_C;
extern const uint16  BoostReq_rDuCyThd_T[BOOSTREQ_RDUCYTHD_T_COLS];
extern const uint16  BoostReq_tiDlyAcvMax_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BoostReq_bBattVoltReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BoostReq_EveIni_BattVoltReq(void);
void BoostReq_SdlFast_BattVoltReq(void);


#endif /* BATTVOLTREQ_H */

/*-------------------------------- end of file -------------------------------*/
