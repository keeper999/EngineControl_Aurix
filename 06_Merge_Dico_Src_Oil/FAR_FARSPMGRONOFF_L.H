/***************************************************************************
;**
;** FILE NAME      : FAR_FARSPMGRONOFF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FAR_FARSPMGRONOFF_L_H
#define FAR_FARSPMGRONOFF_L_H

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

extern const uint8  FAR_FARSPMGRONOFF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Objectif_richesse_global_Ena;
extern uint32 Objectif_richesse_global_brute;
extern uint16 Far_facScvCmbEgMixt;
extern uint16 Obj_rich_en_regul_rich_Brute;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FAR_FARSPMGRONOFF_ChoixTypInj(void);
void FAR_FARSPMGRONOFF_vidCalcObjRich(void);
void FAR_FARSPMGRONOFF_vidCaObjREnReg(void);
void FAR_FARSPMGRONOFF_vidInitOutput(void);
void FAR_FARSPMGRONOFF_vidObjRchGlBrt(void);
void FAR_FARSPMGRONOFF_vidObjRiGlobal(void);


#endif /* FAR_FARSPMGRONOFF_L_H */

/*-------------------------------- end of file -------------------------------*/
