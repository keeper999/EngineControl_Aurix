/***************************************************************************
;**
;** FILE NAME      : POSTEQUSRV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "POSTEQUSRV.H"
#include "POSTEQUSRV_L.H"
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
const boolean  Srv_bInhSAFstWrPosEq_C = 0;
const uint8  POSTEQUSRV_u8Inhib = 0;
const uint8  Srv_PostEquIndice_C = 0;
const uint8  Srv_prmPostEquMax_C = 0;
const uint8  Srv_prmPostEquMin_C = 0;
const uint16  Srv_tiDelayPostEqu_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Srv_stPostEquEcuStatus;
boolean Srv_bPostEquVld;
uint8 Ext_spdVehVSMaxPrmaReq2;
uint8 POSTEQUSRV_u8stPostEcuStatPrev;
uint16 Srv_tiWaitDelayPostEqu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

