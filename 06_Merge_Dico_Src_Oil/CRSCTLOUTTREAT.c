/***************************************************************************
;**
;** FILE NAME      : CRSCTLOUTTREAT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLOUTTREAT_I.h"
#include "CRSCTLOUTTREAT.H"
#include "CRSCTLOUTTREAT_L.H"
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
const uint8  CRSCTLOUTTREAT_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Cc_accel_pedal_regulation_master;
boolean Cc_couple_lvv_effectif;
boolean CrsCtl_bDgoCrsCtlDft;
boolean CrsCtl_bMonRunCrsCtlDft;
boolean VSCtl_bVSCtlDft;
uint8 Position_pedale_limiteur;
uint8 Position_pedale_regulateur;
uint8 VSCtl_stVSCtl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

