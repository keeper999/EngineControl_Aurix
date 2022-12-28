/***************************************************************************
;**
;** FILE NAME      : FUPMPMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FUPMPMNG_L_H
#define FUPMPMNG_L_H

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

/* enum st79 */
#define FUPMP_NOM_WAIT                    0
#define FUPMP_NOM_PCTL                    1
#define FUPMP_STALL_PCTL                  2
#define FUPMP_REPOS                       3
#define FUPMP_COMMANDE                    4
#define FUPMP_KEY_ON_PCTL                 5
/*extern uint8 FuPmp_stCtl;*/

/* enum st02 */
#define FUPMP_WAIT                        0
#define FUPMP_PRECOM_WAIT                 1
#define FUPMP_AUTO_PRECOM                 2
/*extern uint8 FuPmp_stInitCallMng;*/

/* enum st03 */
#define FUPMP_PREC_LONGUE                 0
#define FUPMP_PREC_COURTE                 1
/*extern uint8 FuPmp_stInitFuPmpPctl;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  FUPMPMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 FuPmp_stCtl;
extern uint8 FuPmp_stInitCallMng;
extern uint8 FuPmp_stInitFuPmpPctl;
extern boolean Fuel_pump_bEveKOn_Mng;
extern boolean Fuel_pump_bEveRxnIdDaRcdDml;
extern boolean Fuel_pump_init_delay_ok;
extern boolean Fuel_pump_pre_control_active;
extern boolean Fuel_pump_pre_control_ok;
extern boolean FuPmp_bafter_stall_ena;
extern boolean FuPmp_bPerdPctl_Ena;
extern uint8 Fuel_pump_counter;
extern uint8 Fuel_pump_engine_speed_thresh;
extern uint16 Fuel_pump_delay;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FUPMPMNG_vidCondAcv(void);
void FUPMPMNG_vidControlPump(void);
void FUPMPMNG_vidCtl(void);
void FUPMPMNG_vidEngineRunning(void);
void FUPMPMNG_vidInit(void);
void FUPMPMNG_vidInitCallMng(void);
void FUPMPMNG_vidInitEveKOnMng(void);
void FUPMPMNG_vidInitEveRxnIdDaRcdDml(void);
void FUPMPMNG_vidInitFuPmpPctl(void);
void FUPMPMNG_vidInitOutput(void);
void FUPMPMNG_vidInitPumpCrankStall(void);
void FUPMPMNG_vidInitPumpStallCrank(void);
void FUPMPMNG_vidStopEngReqOrKeyOff(void);


#endif /* FUPMPMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
