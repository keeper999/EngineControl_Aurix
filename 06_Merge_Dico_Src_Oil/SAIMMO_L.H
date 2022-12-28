/***************************************************************************
;**
;** FILE NAME      : SAIMMO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SAIMMO_L_H
#define SAIMMO_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SAIMMO_I.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SAIMMO_ADC_CAN_CLIENT_AUTO        0
#define SAIMMO_ADC_CAN_CLIENT_MANUEL      1
#define SAIMMO_ADC_CAN_PSA_AUTO           128
#define SAIMMO_ADC_CAN_PSA_MANUEL         129
#define SAIMMO_CAN_FRAME_ASK_UNLOCK_AUTHO  0
#define SAIMMO_CAN_FRAME_ECU_STATE        2
#define SAIMMO_CAN_FRAME_SEND             1
#define SAIMMO_CAN_FRAME_STOP             0
#define SAIMMO_CAN_SEND_ONE_FRAME         1
#define SAIMMO_CAN_SEND_START             2
#define SAIMMO_CAN_STOP_SEND_FRAME        0
#define SAIMMO_ETAT_PROG_ETUDE            28679
#define SAIMMO_ETAT_PROG_LIVRAISON        32776
#define SAIMMO_GETCONF_PROG_1             3
#define SAIMMO_GETCONF_PROG_2             4
#define SAIMMO_GETCONF_PROG_3             5
#define SAIMMO_GETCONF_PROG_ETUDE         1
#define SAIMMO_GETCONF_PROG_LIVRAISON     2
#define SAIMMO_GETCONF_UC_APPAIRE_4       8
#define SAIMMO_STECU_INVALED              0
#define SAIMMO_STECU_LOCKED               23205
#define SAIMMO_STECU_UNLOCKED             23356
#define SAIMMO_STLOCKECU_LOCK             76
#define SAIMMO_STLOCKECU_NOK              0
#define SAIMMO_STLOCKECU_UNLOCK           179
#define SAIMMO_u8NVMSRV_DEFAULT           4
#define SAIMMO_u8NVMSRV_NOT_TESTED        0
#define SAIMMO_u8NVMSRV_OK                2

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

extern const boolean  SAIMMO_bTmpSwitchMode;
extern const uint8  SAIMMO_CptObjEEPROM_Code;
extern const uint8  SAIMMO_CptObjEEPROM_Etat;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Immo_bDgoImmoCodNotRead;
extern boolean Immo_bDgoNoAnswCtlUnit;
extern boolean Immo_bDgoWrgAnswCtlUnit;
extern boolean SAIMMO_bActived;
extern boolean SAIMMO_bTmpSwitchMode_prev;
extern boolean SAIMMO_bUnlockAutho;
extern Struct_ObjCode_NVM SAIMMO_ObjCode;
extern Struct_ObjEtat_NVM SAIMMO_ObjEtat;
extern uint8 SAIMMO_u8CptObjCode;
extern uint8 SAIMMO_u8CptObjEtat;
extern uint8 SAIMMO_u8TypeContinuFrame;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SAIMMO_vidCallIsCanTx(void);
void SAIMMO_vidChkWrEep(void);
void SAIMMO_vidSendCAN(void);
void SAIMMO_vidUpdateSaimmoExit(void);


#endif /* SAIMMO_L_H */

/*-------------------------------- end of file -------------------------------*/
