/***************************************************************************
;**
;** FILE NAME      : VLVACTINCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINCMD_L_H
#define VLVACTINCMD_L_H

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

extern const uint8  VLVACTINCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorisation_pwm_adm;
extern boolean Demande_vvt_adm_dormant;
extern boolean VlvAct_bDgoHiVlvActInDrv;
extern boolean VlvAct_bDgoLoVlvActInDrv;
extern boolean VlvActIn_bMonRunHiVlvActInDrv;
extern boolean VlvActIn_bMonRunLoVlvActInDrv;
extern uint16 VlvAct_InCmpCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINCMD_vidBatteryComp(void);
void VLVACTINCMD_vidDiagnostic(void);
void VLVACTINCMD_vidEnablePwm(void);
void VLVACTINCMD_vidInitialization(void);
void VLVACTINCMD_vidInitOutput(void);
void VLVACTINCMD_vidPwmCommand(void);


#endif /* VLVACTINCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
