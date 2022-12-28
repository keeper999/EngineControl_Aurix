/***************************************************************************
;**
;** FILE NAME      : DGOHALACQINJ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DGOHALACQINJ.H"
#include "DGOHALACQINJ_L.H"
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
const uint8  DGOHALACQINJ_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoOc_Inj1Cmd;
boolean Ext_bDgoOc_Inj2Cmd;
boolean Ext_bDgoOc_Inj3Cmd;
boolean Ext_bDgoOc_Inj4Cmd;
boolean Ext_bDgoOvld_Inj1Cmd;
boolean Ext_bDgoOvld_Inj2Cmd;
boolean Ext_bDgoOvld_Inj3Cmd;
boolean Ext_bDgoOvld_Inj4Cmd;
boolean Ext_bDgoScg_Inj1Cmd;
boolean Ext_bDgoScg_Inj2Cmd;
boolean Ext_bDgoScg_Inj3Cmd;
boolean Ext_bDgoScg_Inj4Cmd;
boolean Ext_bDgoScp_Inj1Cmd;
boolean Ext_bDgoScp_Inj2Cmd;
boolean Ext_bDgoScp_Inj3Cmd;
boolean Ext_bDgoScp_Inj4Cmd;
boolean Ext_bMonRunOc_Inj1Cmd;
boolean Ext_bMonRunOc_Inj2Cmd;
boolean Ext_bMonRunOc_Inj3Cmd;
boolean Ext_bMonRunOc_Inj4Cmd;
boolean Ext_bMonRunOvld_Inj1Cmd;
boolean Ext_bMonRunOvld_Inj2Cmd;
boolean Ext_bMonRunOvld_Inj3Cmd;
boolean Ext_bMonRunOvld_Inj4Cmd;
boolean Ext_bMonRunScg_Inj1Cmd;
boolean Ext_bMonRunScg_Inj2Cmd;
boolean Ext_bMonRunScg_Inj3Cmd;
boolean Ext_bMonRunScg_Inj4Cmd;
boolean Ext_bMonRunScp_Inj1Cmd;
boolean Ext_bMonRunScp_Inj2Cmd;
boolean Ext_bMonRunScp_Inj3Cmd;
boolean Ext_bMonRunScp_Inj4Cmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

