/***************************************************************************
;**
;** FILE NAME      : IFFAR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFFAR_H
#define IFFAR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const boolean  Far_bAcvIfStrtFar_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Obj_rich_decrease_enable;
extern uint32 Obj_rich_apres_depart;
extern uint32 OxC_rlamOxCHeatPhaReq;
extern sint16 Afr_target_reinst_aps_corr;
extern sint16 Afr_target_reinst_corr;
extern sint16 Eng_FacCorIntrSttHiEngSpd;
extern uint16 Eng_rlamRstrtSTT;
extern uint16 Hsfr_target;
extern uint16 Obj_rich_charge_partielle;
extern uint16 Obj_rich_coef_base_total;
extern uint16 Obj_rich_min_limit;
extern uint16 Obj_rich_mise_en_action;
extern uint16 Obj_rich_pleine_charge;
extern uint16 Obj_rich_temperature_air;
extern uint16 Objectif_richesse_anti_k;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CatMon_SdlFast_CatAcvDiagIf2(void);
void Far_EveRst_IfFar(void);
void RE_FARSp_022_TEVIf(void);
void SenO2Ds_SdlMid_DsPlausIf(void);


#endif /* IFFAR_H */

/*-------------------------------- end of file -------------------------------*/
