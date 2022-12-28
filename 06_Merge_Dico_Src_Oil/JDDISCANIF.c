/***************************************************************************
;**
;** FILE NAME      : JDDISCANIF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "JDDISCANIF.H"
#include "JDDISCANIF_L.H"
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
const uint8  JDDISCANIF_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Jbsi_pertinence_info_cmm;
uint8 Jbsi_etat_rcd_tx;
uint8 Jbsi_IscanBufferPos1;
uint8 Jbsi_IscanBufferPos2;
uint8 Jbsi_IscanBufferPos3;
uint8 Jbsi_IscanBufferPos4;
uint8 Jbsi_IscanBufferPos5;
uint8 Jbsi_IscanBufferPos6;
uint8 Jbsi_IscanBufferPos7;
uint8 Jbsi_IscanBufferPos8;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

