/***************************************************************************
;**
;** FILE NAME      : FAR_FARSPMGRONOFF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "FAR_FARSPMGRONOFF.H"
#include "FAR_FARSPMGRONOFF_L.H"
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
const boolean  Fco_for_regul_lambda_on = 0;
const boolean  Manu_inh_rich_stt = 0;
const uint8  FAR_FARSPMGRONOFF_u8Inhib = 0;
const uint8  Objectif_richesse_defaut = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Objectif_richesse_global_Ena;
uint32 Obj_rich_depart;
uint32 Objectif_richesse_global;
uint32 Objectif_richesse_global_brute;
uint16 Far_facScvCmbEgMixt;
uint16 Obj_rich_en_regul_rich_Brute;
uint16 Obj_rich_en_regulation_richesse;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

