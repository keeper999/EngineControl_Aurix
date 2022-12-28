/***************************************************************************
;**
;** FILE NAME      : BICD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BICD.H"
#include "BICD_L.H"
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
const boolean  Ext_bStaCmdFctSt_C = 0;
const uint8  BICD_u8Inhib = 0;
const uint8  Ext_noDftStaCmdHiThd_C = 0;
const uint8  Ext_noDftStaCmdLoThd_C = 0;
const uint16  Ext_uDgoScg_DftStaCmd_C = 0;
const uint16  Ext_uDgoScp_DftStaCmd_C = 0;
const uint16  Ext_uMaxDftStaCmd_C = 0;
const uint16  Ext_uMaxNoDftStaCmd_C = 0;
const uint16  Ext_uMinDftStaCmd_C = 0;
const uint16  Ext_uMinNoDftStaCmd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoInvld_uDftStaCmd;
boolean Ext_bDgoScg_uDftStaCmd;
boolean Ext_bDgoScp_uDftStaCmd;
boolean Ext_bMonRunInvld_uDftStaCmd;
boolean Ext_bMonRunScg_uDftStaCmd;
boolean Ext_bMonRunScp_uDftStaCmd;
boolean Ext_bStaCmdFctStFilt;
boolean Ext_bStaCmdFctStMes;
uint8 BICD_u8AntiBounceCounter;
uint16 Ext_uDftStaCmdRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

