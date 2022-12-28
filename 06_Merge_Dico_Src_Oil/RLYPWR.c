/***************************************************************************
;**
;** FILE NAME      : RLYPWR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "RLYPWR.H"
#include "RLYPWR_L.H"
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
const boolean  RlyPwr_bModEcoBatt_Inh_C = 0;
const uint8  RlyPwr_ctInhDiagOcCmdActr_C = 0;
const uint8  RLYPWR_u8Inhib = 0;
const uint16  Rly_InitTimer_C = 0;
const uint16  Rly_tiMaintMainRly_C = 0;
const uint16  RlyPwr_tiAftEndDiag_C = 0;
const uint16  RlyPwr_tiEcuStPwrlLong_C = 0;
const uint16  RlyPwr_tiWaitAcvModEcoBatt_C = 0;
const uint16  RlyPwr_tiWaitOp_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 RlyPwrMng_stPwrRlyCmd;
boolean Actionneurs;
boolean Actionneurs_Int;
boolean EcuSt_bInhDiagOcCmdActr;
boolean EcuSt_bPwrlLong;
boolean Ext_bUnBlsReq;
boolean PwrRly_rCtl;
boolean Rly_bTiEndHldRlyActr;
boolean RlyPwr_bActivTempoEcoBatt;
boolean RlyPwr_bAcvModEcoBatt;
boolean RLYPWR_bEcuStPwrlLongPrev;
boolean RlyPwr_bEndDiag;
boolean RlyPwr_bEngStopped;
boolean RlyPwr_bInitTempoEcoBatt;
uint8 RlyPwr_ctInhDiagOcCmdActr;
uint8 RLYPWR_u8PowercondstatePrev;
uint16 Rly_InitTimer;
uint16 Rly_tiEndHldRlyActr;
uint16 RlyPwr_tiAftEndDiag;
uint16 RlyPwr_tiEcuStPwrlLong;
uint16 RlyPwr_tiWaitAcvModEcoBatt;
uint16 RlyPwr_tiWaitOp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

