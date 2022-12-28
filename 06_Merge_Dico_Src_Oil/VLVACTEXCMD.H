/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXCMD_H
#define VLVACTEXCMD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BATT_LINEAR_EX                    1
#define BATT_OFF_EX                       0
#define VVT_EXHAUST_100_PERC_LDA          1024
#define VVT_EXHAUST_100_PERC_LDA_TO_LDB   32
#define VVT_EXHAUST_100_PERC_LDB          32768

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

extern const boolean  Sens_rco_vvt_echap;
extern const uint8  Consigne_rco_vvt_echap_max;
extern const uint8  Consigne_rco_vvt_echap_min;
extern const uint8  Kevcpe_u_voltage_comp;
extern const uint8  Kfvcpe_u_reference_voltage;
extern const uint8  Seuil_maxi_vbatt_activ_vvt_echap;
extern const uint8  Seuil_mini_vbatt_activ_vvt_echap;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Rco_applique_vvt_echap;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VlvAct_EveRst_ExCmd(void);
void VlvAct_SdlFast_ExCmd(void);
void VlvAct_SdlMid_ExCmd(void);


#endif /* VLVACTEXCMD_H */

/*-------------------------------- end of file -------------------------------*/
