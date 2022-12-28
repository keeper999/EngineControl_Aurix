/***************************************************************************
;**
;** FILE NAME      : CHAADVMINUNLIM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CHAADVMINUNLIM.H"
#include "CHAADVMINUNLIM_L.H"
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
const uint8  CHAADVMINUNLIM_u8Inhib = 0;
const uint8  Ext_ctSdlASRSecuReqThd_C = 0;
const uint8  Ext_spdVehAvrReWhlThd_C = 0;
const uint16  Ext_tiTmrASRReg_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CHAADVMINUNLIM_bInitCndPrev;
boolean CHAADVMINUNLIM_bTimeOut;
boolean Ext_bASRSecuReq_flag1;
boolean Ext_bASRSecuReq_flag2;
uint8 Ext_ctSdlASRSecuReq;
uint8 Ext_spdVehAvrReWhl;
uint16 Ext_tiTmrASRReg;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

