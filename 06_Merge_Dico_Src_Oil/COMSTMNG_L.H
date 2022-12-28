/***************************************************************************
;**
;** FILE NAME      : COMSTMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COMSTMNG_L_H
#define COMSTMNG_L_H

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

extern const uint8  COMSTMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Clef_de_contact_FallEdge;
extern boolean COMSTMNG_bClefDeContactPrev;
extern boolean Ext_bElecItgrReq_prev;
extern uint8 COMSTMNG_LinCurrentMode;
extern uint8 Rcd_power_state_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COMSTMNG_vidCanIsLifeCyclePhases(void);
void COMSTMNG_vidInitOutput(void);
void COMSTMNG_vidIntegraElectronique(void);
void COMSTMNG_vidLinLifeCyclePhases(void);
void COMSTMNG_vidLinStatusInit(void);
void COMSTMNG_vidLinStatusNormal(void);
void COMSTMNG_vidLinStatusShut(void);
void COMSTMNG_vidLinStatusWakeUp(void);
void COMSTMNG_vidPowerlatch(void);
void COMSTMNG_vidReset(void);
void COMSTMNG_vidShutDown(void);
void COMSTMNG_vidWakeUp(void);
void VidMainFunction_StackCom_10MS(void);
void VidMainFunction_StackCom_2_5MS(void);
void VidMainFunction_StackCom_20MS(void);


#endif /* COMSTMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
