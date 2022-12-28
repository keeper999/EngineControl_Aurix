/***************************************************************************
;**
;** FILE NAME      : VLVACTINIF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINIF_L_H
#define VLVACTINIF_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGCKINCMTOOTHERR_COLS           ( 4 )

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

extern const uint8  VLVACTINIF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bInSpFuncIntlHiOutIdcInt;
extern boolean VlvAct_bInSpFuncIntlLoOutIdcInt;
extern boolean VLVACTINIF_bLihPosTimerOut;
extern boolean VLVACTINIF_bSwitchOutPrev;
extern boolean VLVACTINIF_bTimerInitPrev;
extern boolean VLVACTINIF_bTimerInputPrev;
extern boolean VLVACTINIF_bTimerOut;
extern boolean VLVACTINIF_bVcpiCamOffsetLndPrev;
extern uint8 VLVACTINIF_u8TimerCount;
extern sint16 VlvAct_agCkInCmOfs;
extern sint16 VlvAct_agCkInCmToothErr[VLVACT_AGCKINCMTOOTHERR_COLS];
extern sint16 VlvAct_agCkInCmToothOfs;
extern sint16 VlvAct_agCkInExVlvDif;
extern uint16 VlvAct_agInSpFuncIntlThdHi;
extern uint16 VlvAct_agInSpFuncIntlThdLo;
extern uint16 VlvAct_tiDlyInhDiagPresScavOff;
extern uint16 VLVACTINIF_u16SlewRateOut;
extern uint16 Vxx_vvtc_in_angl_sp_Int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINIF_vidCalcSatSetpoint(void);
void VLVACTINIF_vidCmOfsCmp(void);
void VLVACTINIF_vidInitialisation(void);
void VLVACTINIF_vidInitOutput(void);
void VLVACTINIF_vidVlvActCmToothOfs(void);
void VLVACTINIF_vidVlvActOfsCmp(void);
void VLVACTINIF_vidVVTDiagInhFlagCal(void);
void VLVACTINIF_vidVVTPosition(void);
void VLVACTINIF_vidVVTSetpoint(void);
void VLVACTINIF_vidVVTToothErrDet(void);


#endif /* VLVACTINIF_L_H */

/*-------------------------------- end of file -------------------------------*/
