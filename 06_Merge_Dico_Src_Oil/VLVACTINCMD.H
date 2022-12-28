/***************************************************************************
;**
;** FILE NAME      : VLVACTINCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINCMD_H
#define VLVACTINCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BATT_LINEAR                       1
#define BATT_OFF                          0
#define VVT_INTAKE_100_PERC_LDA           1024
#define VVT_INTAKE_100_PERC_LDA_TO_LDB    32
#define VVT_INTAKE_100_PERC_LDB           32768

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

extern const boolean  Sens_rco_vvt_adm;
extern const uint8  Consigne_rco_vvt_adm_max;
extern const uint8  Consigne_rco_vvt_adm_min;
extern const uint8  Kevcpi_u_voltage_comp;
extern const uint8  Kfvcpi_u_reference_voltage;
extern const uint8  Seuil_maxi_vbatt_activ_vvt_adm;
extern const uint8  Seuil_mini_vbatt_activ_vvt_adm;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Rco_applique_vvt_adm;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_InCmd(void);
void VlvAct_SdlFast_InCmd(void);
void VlvAct_SdlMid_InCmd(void);


#endif /* VLVACTINCMD_H */

/*-------------------------------- end of file -------------------------------*/
