/***************************************************************************
;**
;** FILE NAME      : HEATSENO2DSCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2DSCMD_L_H
#define HEATSENO2DSCMD_L_H

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

extern const uint8  HEATSENO2DSCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Lshd_dwstr_period_updating;
extern boolean LsSys_bLsDsMainOxCHeatPwrCmd;
extern uint8 HEATSENO2DSCMD_u8DiagCmdCntPrev;
extern uint8 HEATSENO2DSCMD_u8MainOxCHeatPrev;
extern uint8 Lshd_lbdw_diag_cmd_counter;
extern uint8 LsSys_DsPosSlopHeat;
extern uint8 LsSys_rLsDsMainOxCHeatPwrCor;
extern uint8 LsSys_rLsDsMainOxCHeatPwrDiag;
extern uint8 LsSys_rLsDsMainOxCHeatPwrRaw;
extern sint16 LsSys_DsNegSlopHeat;
extern uint16 HEATSENO2DSCMD_u16RcoPeriodPrev;
extern uint16 Lshd_dwstr_period_counter;
extern uint16 Lshd_dwstr_rco_periode;
extern uint16 Lshd_dwstr_t_on_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2DSCMD_vidCalcPwmPeriod(void);
void HEATSENO2DSCMD_vidCalculTimeOn(void);
void HEATSENO2DSCMD_vidDriverCmd(void);
void HEATSENO2DSCMD_vidInitOutput(void);
void HEATSENO2DSCMD_vidLsUsHeatCmd(void);
void HEATSENO2DSCMD_vidLsUsHeatCor(void);
void HEATSENO2DSCMD_vidLsUsHeatDiag(void);
void HEATSENO2DSCMD_vidLsUsHeatMan(void);
void HEATSENO2DSCMD_vidLsUsHeatRaw(void);
void HEATSENO2DSCMD_vidLsUsHeatReq(void);
void HEATSENO2DSCMD_vidLsUsHeatTst(void);
void HEATSENO2DSCMD_vidSlopHeat(void);


#endif /* HEATSENO2DSCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
