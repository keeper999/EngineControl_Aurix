/***************************************************************************
;**
;** FILE NAME      : VSSNWDMTRACV.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VSSNWDMTRACV.H"
#include "VSSNWDMTRACV_L.H"
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
const boolean  Ext_bVSSNwAcvReqInv_C = 0;
const uint8  VSSNWDMTRACV_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
boolean Ext_bDgoScg_VSSNwAcvReq;
boolean Ext_bDgoScp_VSSNwAcvReq;
boolean Ext_bMonRunScg_VSSNwAcvReq;
boolean Ext_bMonRunScp_VSSNwAcvReq;
boolean Ext_bVSSNwAcvAuth;
boolean Ext_bVSSNwAcvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

