/***************************************************************************
;**
;** FILE NAME      : IFFAR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IFFAR.H"
#include "IFFAR_L.H"
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
const boolean  Far_bAcvIfStrtFar_C = 0;
const uint8  IFFAR_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Obj_rich_decrease_enable;
uint32 Obj_rich_apres_depart;
uint32 OxC_rlamOxCHeatPhaReq;
sint16 Afr_target_reinst_aps_corr;
sint16 Afr_target_reinst_corr;
sint16 Eng_FacCorIntrSttHiEngSpd;
uint16 Eng_rlamRstrtSTT;
uint16 Hsfr_target;
uint16 Obj_rich_charge_partielle;
uint16 Obj_rich_coef_base_total;
uint16 Obj_rich_min_limit;
uint16 Obj_rich_mise_en_action;
uint16 Obj_rich_pleine_charge;
uint16 Obj_rich_temperature_air;
uint16 Objectif_richesse_anti_k;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

