/***************************************************************************
;**
;** FILE NAME      : ECUMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ECUMNG_L_H
#define ECUMNG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ECUMNG_I.h"
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

extern const uint8  ECUMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ECUMNG_bAcv_Diag_Hot_Rst;
extern boolean EcuSt_bDgoHotRst;
extern boolean EcuSt_bMonRunHotRst;
extern boolean EcuSt_bPwrlEnd;
extern boolean EcuSt_EcuStpEna;
extern boolean EcuSt_fin_wr_eeprom;
extern boolean Rcd_cond_for_power_on_default;
extern boolean Srv_bRstSw_DiagSrv_Prev;
extern uint8 Apc_PwrSt;
extern uint8 EcuSt_stPwr_EcuMng;
extern uint8 EcuSt_stPwr_EcuMng_prev;
extern uint8 Rcd_PwrSt;
extern uint16 Power_cond_delay_count;
extern uint16 Power_latch_delay_max;
extern uint16 Rcd_wait_open_pwr_relay_count;
extern uint16 Rcd_wait_wr_in_eeprom_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ECUMNG_NVMSRV_vidInit(void);
void ECUMNG_vidAPCConfig(void);
void ECUMNG_vidbisAcvDiagHotRst(void);
void ECUMNG_vidbRstSrvRstEepromCount(void);
void ECUMNG_vidEcuMng_Init(void);
void ECUMNG_vidFctPrinDegrad(void);
void ECUMNG_vidInitOutput(void);
void ECUMNG_vidInterneCmm(void);
void ECUMNG_vidManagePowerOn(void);
void ECUMNG_vidManager(void);
void ECUMNG_vidPowerOnTrans(void);
void ECUMNG_vidPwrLatchDelayTrans(void);
void ECUMNG_vidPwrlEndAuth(void);
void ECUMNG_vidRCDConfig(void);
void ECUMNG_vidRcdStateSelection(void);
void ECUMNG_vidSleepingTrans(void);
void ECUMNG_vidSurveillance(void);
void ECUMNG_vidWaitAnticipationTrans(void);
void ECUMNG_vidWaitRstrtDelayTrans(void);


#endif /* ECUMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
