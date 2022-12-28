/***************************************************************************
;**
;** FILE NAME      : HEATSENO2USCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2USCMD_L_H
#define HEATSENO2USCMD_L_H

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

extern const uint8  HEATSENO2USCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Lshd_upstr_period_updating;
extern boolean LsSys_bLsUsMainOxCHeatPwrCmd;
extern uint8 HEATSENO2USCMD_u8DiagCmdCntPrev;
extern uint8 HEATSENO2USCMD_u8MainOxCHeatPrev;
extern uint8 Lshd_lbup_diag_cmd_counter;
extern uint8 LsSys_rLsUsMainOxCHeatPwrCor;
extern uint8 LsSys_rLsUsMainOxCHeatPwrDiag;
extern uint8 LsSys_rLsUsMainOxCHeatPwrRaw;
extern uint8 LsSys_UsPosSlopHeat;
extern sint16 LsSys_UsNegSlopHeat;
extern uint16 HEATSENO2USCMD_u16RcoPeriodPrev;
extern uint16 Lshd_upstr_period_counter;
extern uint16 Lshd_upstr_rco_periode;
extern uint16 Lshd_upstr_t_on_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2USCMD_vidCalcPwmPeriod(void);
void HEATSENO2USCMD_vidCalculTimeOn(void);
void HEATSENO2USCMD_vidDriverCmd(void);
void HEATSENO2USCMD_vidInitOutput(void);
void HEATSENO2USCMD_vidLsUsHeatCmd(void);
void HEATSENO2USCMD_vidLsUsHeatCor(void);
void HEATSENO2USCMD_vidLsUsHeatDiag(void);
void HEATSENO2USCMD_vidLsUsHeatMan(void);
void HEATSENO2USCMD_vidLsUsHeatRaw(void);
void HEATSENO2USCMD_vidLsUsHeatReq(void);
void HEATSENO2USCMD_vidLsUsHeatTst(void);
void HEATSENO2USCMD_vidSlopHeat(void);


#endif /* HEATSENO2USCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
