/***************************************************************************
;**
;** FILE NAME      : IGCOILDIAG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGCOILDIAG.H"
#include "IGCOILDIAG_L.H"
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
const boolean  IgCmd_bCallDiagTyp_C = 0;
const uint8  IGCOILDIAG_u8Inhib = 0;
const uint8  Seuil_regime_diag_bobine = 0;
const uint16  Seuil_tension_inf_diag_bobine = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Ext_bDgoOc_IgCoil1Cmd;
boolean Ext_bDgoOc_IgCoil2Cmd;
boolean Ext_bDgoOc_IgCoil3Cmd;
boolean Ext_bDgoOc_IgCoil4Cmd;
boolean Ext_bDgoScp_IgCoil1Cmd;
boolean Ext_bDgoScp_IgCoil2Cmd;
boolean Ext_bDgoScp_IgCoil3Cmd;
boolean Ext_bDgoScp_IgCoil4Cmd;
boolean Ext_bMonRunOc_IgCoil1Cmd;
boolean Ext_bMonRunOc_IgCoil2Cmd;
boolean Ext_bMonRunOc_IgCoil3Cmd;
boolean Ext_bMonRunOc_IgCoil4Cmd;
boolean Ext_bMonRunScp_IgCoil1Cmd;
boolean Ext_bMonRunScp_IgCoil2Cmd;
boolean Ext_bMonRunScp_IgCoil3Cmd;
boolean Ext_bMonRunScp_IgCoil4Cmd;
boolean Icd_diagnostic_enabled;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

