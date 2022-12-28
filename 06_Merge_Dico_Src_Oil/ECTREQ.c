/***************************************************************************
;**
;** FILE NAME      : ECTREQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ECTREQ.H"
#include "ECTREQ_L.H"
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
const boolean  ECTReq_bInvDuCy_C = 0;
const uint8  ECTREQ_u8Inhib = 0;
const uint16  ECTReq_rMaxDuCy_C = 0;
const uint16  ECTReq_rMinDuCy_C = 0;
const uint16  ECTReq_rSatMax_C = 0;
const uint16  ECTReq_rSatMin_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoFan_bDgoOc_ECTReq;
boolean CoFan_bDgoScg_ECTReq;
boolean CoFan_bDgoScp_ECTReq;
boolean CoFan_bMonRunOc_ECTReq;
boolean CoFan_bMonRunScg_ECTReq;
boolean CoFan_bMonRunScp_ECTReq;
boolean Dena_oc_ectcommand;
boolean Dena_scg_ectcommand;
boolean Dena_scw_ectcommand;
boolean Dft_oc_ectcommand;
boolean Dft_scg_ectcommand;
boolean Dft_scw_ectcommand;
sint16 ECTREQ_s16Ext_uBattMesPrev;
uint16 CoFan_uBattMes_Filtered;
uint16 PwrHw_rCtlECTReq_Cnv;
uint16 PwrHw_rCtlECTReq_Cor;
uint16 PwrHw_rCtlECTReq_Drv;
uint16 PwrHw_rCtlECTReq_Sat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

