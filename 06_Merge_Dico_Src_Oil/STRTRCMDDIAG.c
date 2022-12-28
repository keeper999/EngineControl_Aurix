/***************************************************************************
;**
;** FILE NAME      : STRTRCMDDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "STRTRCMDDIAG.H"
#include "STRTRCMDDIAG_L.H"
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
const uint8  STRTRCMDDIAG_u8Inhib = 0;
const uint16  Dml_diag_blocage_sta_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoOc_Dml;
boolean Ext_bDgoScg_Dml;
boolean Ext_bDgoScp_Dml;
boolean Ext_bMonRunOc_Dml;
boolean Ext_bMonRunScg_Dml;
boolean Ext_bMonRunScp_Dml;
boolean Ext_bMonWaitOc_Dml;
boolean Ext_bMonWaitScg_Dml;
boolean Ext_bMonWaitScp_Dml;
boolean Strtr_bDgoBlock_Strtr;
boolean Strtr_bMonRunBlock_Strtr;
boolean Strtr_bMonWaitBlock_Strtr;
boolean STRTRCMDDIAG_bCondRstTempo;
boolean STRTRCMDDIAG_bDmlCmdCrankingPrev;
boolean STRTRCMDDIAG_boc_diag_ena;
boolean STRTRCMDDIAG_bscg_diag_ena;
boolean STRTRCMDDIAG_bscw_diag_ena;
uint16 Dml_diag_cmd_blocage_sta_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

