/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VLVACTEXCMD.H"
#include "VLVACTEXCMD_L.H"
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
const boolean  Sens_rco_vvt_echap = 0;
const uint8  Consigne_rco_vvt_echap_max = 0;
const uint8  Consigne_rco_vvt_echap_min = 0;
const uint8  Kevcpe_u_voltage_comp = 0;
const uint8  Kfvcpe_u_reference_voltage = 0;
const uint8  Seuil_maxi_vbatt_activ_vvt_echap = 0;
const uint8  Seuil_mini_vbatt_activ_vvt_echap = 0;
const uint8  VLVACTEXCMD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorisation_pwm_echap;
boolean Demande_vvt_echap_dormant;
boolean VlvAct_bDgoHiVlvActExDrv;
boolean VlvAct_bDgoLoVlvActExDrv;
boolean VlvActIn_bMonRunHiVlvActExDrv;
boolean VlvActIn_bMonRunLoVlvActExDrv;
uint16 Rco_applique_vvt_echap;
uint16 VlvAct_ExCmpCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

