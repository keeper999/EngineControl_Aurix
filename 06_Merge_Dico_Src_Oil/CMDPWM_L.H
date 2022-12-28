/***************************************************************************
;**
;** FILE NAME      : CMDPWM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CMDPWM_L_H
#define CMDPWM_L_H

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

extern const uint8  CMDPWM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean CMDPWM_bDemandeInhibHbridge_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CMDPWM_vidCmd_tpac(void);
void CMDPWM_vidCmdPwmCoFan(void);
void CMDPWM_vidCmdPwmCstr(void);
void CMDPWM_vidCmdPwmECTCmd(void);
void CMDPWM_vidCmdPwmPropFuPmp(void);
void CMDPWM_vidCmdPwmVlvActEx(void);
void CMDPWM_vidCmdPwmVlvActIn(void);
void CMDPWM_vidDriverInh(void);
void CMDPWM_vidF00_Init_CmdPwmECTCmd(void);
void CMDPWM_vidF00_Init_CmdPwmThrCmd(void);
void CMDPWM_vidF00_Init_CmdPwmVlvAct(void);
void CMDPWM_vidF00InitCmdPwmPropFuPmP(void);
void CMDPWM_vidInitOutput(void);


#endif /* CMDPWM_L_H */

/*-------------------------------- end of file -------------------------------*/
