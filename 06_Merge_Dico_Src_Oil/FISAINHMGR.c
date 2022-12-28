/***************************************************************************
;**
;** FILE NAME      : FISAINHMGR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FISAINHMGR.H"
#include "FISAINHMGR_L.H"
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
const uint8  FISAINHMGR_u8Inhib = 0;
const sint16  DiftCotOilFisaTrsh_C = 0;
const sint16  Ext_tCoMesMinInhFisa_C = 0;
const sint16  tqMaxResInhFisa_C = 0;
const uint16  Ext_nEngCrkInhFisa_C = 0;
const uint16  Ext_pAirExtMesMaxInhFisa_C = 0;
const uint16  Ext_pAirExtMesMinInhFisa_C = 0;
const uint16  Ext_uBattMesInhFisa_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Demarrage_poussette;
boolean Detection_consommateurs_actifs;
boolean Detection_demarrage_poussette;
boolean Ext_nEngCrkInf;
boolean Ext_uBattMesDeltaSup;
sint16 Ext_uBattMes_prev;
sint16 TqRes_tqMaxRes_prev;
uint16 Ext_uBattMesDelta;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

