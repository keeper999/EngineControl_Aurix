/***************************************************************************
;**
;** FILE NAME      : BATTVOLTREQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BATTVOLTREQ.H"
#include "BATTVOLTREQ_L.H"
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
const boolean  BoostReq_bAcvBattVoltReq_C = 0;
const boolean  BoostReq_bAcvFrzMod_C = 0;
const boolean  BoostReq_bAcvStraBattVoltReq_C = 0;
const boolean  BoostReq_bBattVoltReqIni_C = 0;
const uint8  BATTVOLTREQ_u8Inhib = 0;
const uint16  BoostReq_pAirExt_A[BOOSTREQ_PAIREXT_A_COLS] = {0};
const uint16  BoostReq_pAirExtHiThd_C = 0;
const uint16  BoostReq_pAirExtLoThd_C = 0;
const uint16  BoostReq_rDuCyMaxThd_C = 0;
const uint16  BoostReq_rDuCyThd_T[BOOSTREQ_RDUCYTHD_T_COLS] = {0};
const uint16  BoostReq_tiDlyAcvMax_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean BATTVOLTREQ_bAcvTrbActMax_MPPrev;
boolean BATTVOLTREQ_bOutNegHysRqstCond;
boolean BoostAct_bAcvTrbActMax;
boolean BoostAct_bAcvTrbActMax_MP;
boolean BoostReq_bBattVoltReq;
uint16 BATTVOLTREQ_u16TOffDlyAuthCnt;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

