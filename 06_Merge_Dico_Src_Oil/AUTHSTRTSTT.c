/***************************************************************************
;**
;** FILE NAME      : AUTHSTRTSTT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AUTHSTRTSTT.H"
#include "AUTHSTRTSTT_L.H"
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
const boolean  Ext_bInhCrkAltHwInv_C = 0;
const uint8  AUTHSTRTSTT_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean EngSt_bInhCrkAlt;
boolean EngSt_bInhCrkAltHw;
boolean Ext_bDgoOc_bInhCrkAltHw;
boolean Ext_bDgoScg_bInhCrkAltHw;
boolean Ext_bDgoScp_bInhCrkAltHw;
boolean Ext_bInhCrkAltHw;
boolean Ext_bMonRunOc_bInhCrkAltHw;
boolean Ext_bMonRunScg_bInhCrkAltHw;
boolean Ext_bMonRunScp_bInhCrkAltHw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

