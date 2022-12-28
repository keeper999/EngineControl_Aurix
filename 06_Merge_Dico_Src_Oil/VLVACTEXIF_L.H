/***************************************************************************
;**
;** FILE NAME      : VLVACTEXIF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXIF_L_H
#define VLVACTEXIF_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define VLVACT_AGCKEXCMTOOTHERR_COLS           ( 4 )

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

extern const uint8  VLVACTEXIF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bExSpFuncIntlHiOutIdcInt;
extern boolean VlvAct_bExSpFuncIntlLoOutIdcInt;
extern boolean VLVACTEXIF_bLihPosTimerOut;
extern boolean VLVACTEXIF_bTimerInputPrev;
extern boolean VLVACTEXIF_bVcpeCamOffsetLndPrev;
extern uint8 VLVACTEXIF_u8TimerCount;
extern sint16 VlvAct_agCkExCmOfs;
extern sint16 VlvAct_agCkExCmToothErr[VLVACT_AGCKEXCMTOOTHERR_COLS];
extern sint16 VlvAct_agCkExCmToothOfs;
extern uint16 VlvAct_agExSpFuncIntlThdHi;
extern uint16 VlvAct_agExSpFuncIntlThdLo;
extern uint16 VLVACTEXIF_u16SlewRateOut;
extern uint16 Vxx_vvtc_ex_angl_sp_Int;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXIF_vidCalcSatSetpoint(void);
void VLVACTEXIF_vidCmOfsCmp(void);
void VLVACTEXIF_vidInitialisation(void);
void VLVACTEXIF_vidInitOutput(void);
void VLVACTEXIF_vidVlvActCmToothOfs(void);
void VLVACTEXIF_vidVlvActOfsCmp(void);
void VLVACTEXIF_vidVVTPosition(void);
void VLVACTEXIF_vidVVTSetpoint(void);
void VLVACTEXIF_vidVVTToothErrDet(void);


#endif /* VLVACTEXIF_L_H */

/*-------------------------------- end of file -------------------------------*/
