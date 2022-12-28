/***************************************************************************
;**
;** FILE NAME      : CRSCTLOUTTREAT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLOUTTREAT_H
#define CRSCTLOUTTREAT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLOUTTREAT_I.h"
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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cc_accel_pedal_regulation_master;
extern boolean Cc_couple_lvv_effectif;
extern boolean VSCtl_bVSCtlDft;
extern uint8 Position_pedale_limiteur;
extern uint8 Position_pedale_regulateur;
extern uint8 VSCtl_stVSCtl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CrsCtl_EveRst_CrsCtlOutTreat(void);
void CrsCtl_SdlFast_CrsCtlOutTreat(void);


#endif /* CRSCTLOUTTREAT_H */

/*-------------------------------- end of file -------------------------------*/
