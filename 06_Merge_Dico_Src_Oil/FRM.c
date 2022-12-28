/***************************************************************************
;**
;** FILE NAME      : FRM.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FRM_Macro.h"
#include "GD.h"
#include "GD_api.h"
#include "GDFRM.h"
#include "GDFRMDEF.h"
#include "FRM.H"
#include "FRM_L.H"
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
const boolean  FRM_abAuthTypCc_NameVar_C[FRM_ABAUTHTYPCC_NAMEVAR_C_LNS] = {0};
const boolean  FRM_bEnaFid_C = 0;
const uint8  FRM_au8EnaTypAcvOptRvCcDd_C[FRM_AU8ENATYPACVOPTRVCCDD_C_LNS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean FRM_abDftTypCc_NameVar[FRM_ABDFTTYPCC_NAMEVAR_LNS];
boolean FRM_abRawTypAcvOptRvCcDd[FRM_ABRAWTYPACVOPTRVCCDD_LNS];
boolean FRM_abTypAcvOptRvCcDd[FRM_ABTYPACVOPTRVCCDD_LNS];
uint8 FRM_au8DU[FRM_AU8DU_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

