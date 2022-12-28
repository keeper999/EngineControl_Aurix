/***************************************************************************
;**
;** FILE NAME      : CRSCTLINTREATIF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLINTREATIF.H"
#include "CRSCTLINTREATIF_L.H"
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
const uint8  CRSCTLINTREATIF_u8Inhib = 0;
const uint8  Ext_SpdVehBVVMax_C = 0;
const uint8  Ext_SpdVehBVVMin_C = 0;
const uint16  CrsCtl_tempo_init_diag_xVV_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CRSCTLINTREATIF_bTimeOut;
boolean CRSCTLINTREATIF_Diag_onPrev;
boolean Ext_bClu;
uint8 Ext_noGearEgd;
uint16 CRSCTLINTREATIF_u16Timer;
uint16 Ext_nAvrFrntWhl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

