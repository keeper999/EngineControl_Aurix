/***************************************************************************
;**
;** FILE NAME      : FAR_FARSPMGRONOFF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FAR_FARSPMGRONOFF_H
#define FAR_FARSPMGRONOFF_H

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

extern const boolean  Fco_for_regul_lambda_on;
extern const boolean  Manu_inh_rich_stt;
extern const uint8  Objectif_richesse_defaut;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 Obj_rich_depart;
extern uint32 Objectif_richesse_global;
extern uint16 Obj_rich_en_regulation_richesse;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Far_EveCrTR_FarSpMgr(void);
void Far_EveNTFL_FarSpMgr(void);
void Far_EveTOSR_FarSpMgr(void);
void FAR_FARSPMGRONOFF_vidEntryInit(void);
void Far_SdlFast_FarSpMgr(void);


#endif /* FAR_FARSPMGRONOFF_H */

/*-------------------------------- end of file -------------------------------*/
