/***************************************************************************
;**
;** FILE NAME      : ECUMNG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ECUMNG_I.h"
#include "ECUMNG.H"
#include "ECUMNG_L.H"
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
const boolean  EcuSt_bInhFirstCrank_C = 0;
const uint8  ECUMNG_u8Inhib = 0;
const uint8  Forcage_power_latch_emf = 0;
const uint8  Manu_inh_gestion_power_latch_emf = 0;
const uint16  EcuSt_ctHotRst_Count_Init = 0;
const uint16  Engine_restart_delay = 0;
const uint16  Power_latch_delay = 0;
const uint16  Power_latch_emf_delay_max = 0;
const uint16  Power_latch_no_emf_delay_max = 0;
const uint16  Rcd_wait_open_pwr_relay_delay = 0;
const uint16  Rcd_wait_wr_in_eeprom_delay = 0;
const uint16  Rcd_waiting_for_anticip_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Power_conditions_state;
uint8 Rcd_power_state;
boolean ECUMNG_bAcv_Diag_Hot_Rst;
boolean EcuSt_bDetHotRst;
boolean EcuSt_bDgoHotRst;
boolean EcuSt_bMonRunHotRst;
boolean EcuSt_bPwrlEnd;
boolean EcuSt_EcuStpEna;
boolean EcuSt_fin_wr_eeprom;
boolean EcuSt_FinWrEepromTemp;
boolean Ext_bUnlockReq;
boolean Rcd_cond_for_power_on_default;
boolean Srv_bRstSw_DiagSrv_Prev;
uint8 Apc_PwrSt;
uint8 EcuSt_stPwr_EcuMng;
uint8 EcuSt_stPwr_EcuMng_prev;
uint8 EcuSt_stTypRst;
uint8 Ext_stSt;
uint8 Rcd_PwrSt;
uint16 Power_cond_delay_count;
uint16 Power_latch_delay_max;
uint16 Rcd_wait_open_pwr_relay_count;
uint16 Rcd_wait_wr_in_eeprom_count;
uint16 Rcd_waiting_for_anticip_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

