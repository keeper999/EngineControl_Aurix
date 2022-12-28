/***************************************************************************
;**
;** FILE NAME      : ECUMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ECUMNG_H
#define ECUMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ECUMNG_I.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define POWER_LATCH_12_SEC                300

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st08 */
#define WAITING_FOR_ANTICIPATION          8
#define SLEEPING                          16
#define WAITING_FOR_POWER_LATCH_DELAY     32
#define WAITING_FOR_RESTART_DELAY         64
#define POWER_ON                          128
/*extern uint8 Power_conditions_state;*/

/* enum st09 */
#define RCD_ANTICIPATION                  1
#define RCD_POWER_LATCH                   2
#define RCD_TRANSIT                       4
#define RCD_POWER_ON                      8
#define RCD_POWER_ON_DEFAULT              16
#define RCD_SLEEPING                      32
/*extern uint8 Rcd_power_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  EcuSt_bInhFirstCrank_C;
extern const uint8  Forcage_power_latch_emf;
extern const uint8  Manu_inh_gestion_power_latch_emf;
extern const uint16  EcuSt_ctHotRst_Count_Init;
extern const uint16  Engine_restart_delay;
extern const uint16  Power_latch_delay;
extern const uint16  Power_latch_emf_delay_max;
extern const uint16  Power_latch_no_emf_delay_max;
extern const uint16  Rcd_wait_open_pwr_relay_delay;
extern const uint16  Rcd_wait_wr_in_eeprom_delay;
extern const uint16  Rcd_waiting_for_anticip_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Power_conditions_state;
extern uint8 Rcd_power_state;
extern boolean EcuSt_bDetHotRst;
extern boolean EcuSt_FinWrEepromTemp;
extern boolean Ext_bUnlockReq;
extern uint8 EcuSt_stTypRst;
extern uint8 Ext_stSt;
extern uint16 Rcd_waiting_for_anticip_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EcuSt_EveKOf_EcuMng(void);
void EcuSt_EveKOn_EcuMng(void);
void EcuSt_EvePtlWku_Wku(void);
void EcuSt_EvePwrlEnd_EcuMng(void);
void EcuSt_EveRst_EcuMng(void);
void EcuSt_SdlMid_EcuMng(void);


#endif /* ECUMNG_H */

/*-------------------------------- end of file -------------------------------*/
