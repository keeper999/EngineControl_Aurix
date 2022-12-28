/***************************************************************************
;**
;** FILE NAME      : VLVACTEXCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXCMD_L_H
#define VLVACTEXCMD_L_H

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

extern const uint8  VLVACTEXCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorisation_pwm_echap;
extern boolean Demande_vvt_echap_dormant;
extern boolean VlvAct_bDgoHiVlvActExDrv;
extern boolean VlvAct_bDgoLoVlvActExDrv;
extern boolean VlvActIn_bMonRunHiVlvActExDrv;
extern boolean VlvActIn_bMonRunLoVlvActExDrv;
extern uint16 VlvAct_ExCmpCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXCMD_vidBatteryComp(void);
void VLVACTEXCMD_vidDiagnostic(void);
void VLVACTEXCMD_vidEnablePwm(void);
void VLVACTEXCMD_vidInitialization(void);
void VLVACTEXCMD_vidInitOutput(void);
void VLVACTEXCMD_vidPwmCommand(void);


#endif /* VLVACTEXCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
