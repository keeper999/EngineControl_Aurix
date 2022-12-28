/***************************************************************************
;**
;** FILE NAME      : DRVRSENO2US.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DRVRSENO2US_H
#define DRVRSENO2US_H

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

extern const uint16  Ichauff_min_SenO2Us;
extern const uint16  Lshd_max_voltage_diag_thresh;
extern const uint16  Lshd_min_voltage_diag_thresh;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean M_diag_chauffage_amont;
extern uint16 Ext_uEcuUsMes;
extern uint16 Ichauff_SO2Us;
extern uint16 LsMon_resLsUsHeat;
extern uint16 Rchauff_SO2Us;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HeatSenO2_EveKOf_DrvrSenO2Us(void);
void HeatSenO2_SdlFast_DrvrSenO2Us(void);


#endif /* DRVRSENO2US_H */

/*-------------------------------- end of file -------------------------------*/
