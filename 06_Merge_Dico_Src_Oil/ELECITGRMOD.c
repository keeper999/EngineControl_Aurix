/***************************************************************************
;**
;** FILE NAME      : ELECITGRMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ELECITGRMOD.H"
#include "ELECITGRMOD_L.H"
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
const uint8  DIAGCAN_tiF092Out_ClearDTC_C = 0;
const uint8  DIAGCAN_tiF092Out_InteElec_C = 0;
const uint8  ELECITGRMOD_u8Inhib = 0;
const uint8  Ext_tiHldIntModeExitMainWku_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DIAGCAN_bInhibition_defauts;
boolean DIAGCAN_bTxMute;
uint8 DIAGCAN_tiF092Out_ClearDTC;
uint8 DIAGCAN_tiF092Out_InteElec;
uint8 DIAGCAN_u8Command_InteElec_prev;
uint8 DIAGCAN_u8IntElecAftrRstWaitCnt;
uint8 DIAGCAN_u8Nb_trame_ClearDTC_rec;
uint8 DIAGCAN_u8Nb_trame_InteElec_rec;
uint8 Ext_tiHldIntModeExitMainWku;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

