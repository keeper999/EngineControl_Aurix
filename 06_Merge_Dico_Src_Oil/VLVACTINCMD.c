/***************************************************************************
;**
;** FILE NAME      : VLVACTINCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTINCMD.H"
#include "VLVACTINCMD_L.H"
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
const boolean  Sens_rco_vvt_adm = 0;
const uint8  Consigne_rco_vvt_adm_max = 0;
const uint8  Consigne_rco_vvt_adm_min = 0;
const uint8  Kevcpi_u_voltage_comp = 0;
const uint8  Kfvcpi_u_reference_voltage = 0;
const uint8  Seuil_maxi_vbatt_activ_vvt_adm = 0;
const uint8  Seuil_mini_vbatt_activ_vvt_adm = 0;
const uint8  VLVACTINCMD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorisation_pwm_adm;
boolean Demande_vvt_adm_dormant;
boolean VlvAct_bDgoHiVlvActInDrv;
boolean VlvAct_bDgoLoVlvActInDrv;
boolean VlvActIn_bMonRunHiVlvActInDrv;
boolean VlvActIn_bMonRunLoVlvActInDrv;
uint16 Rco_applique_vvt_adm;
uint16 VlvAct_InCmpCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

