/***************************************************************************
;**
;** FILE NAME      : THRPOSNSPLRN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRPOSNSPLRN_L_H
#define THRPOSNSPLRN_L_H

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

extern const uint8  THRPOSNSPLRN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bMblRstorEna;
extern boolean Thr_FLrnClCtl_bTempoEnd;
extern uint8 Thr_FLrnClCtl_titempo;
extern uint8 ThrPosnSpLrn_u8State;
extern uint16 Thr_FClnClCtl_posnSp;
extern uint16 Thr_FLrnClCtl_posnExiLoThruSp;
extern uint16 Thr_FLrnClCtl_posnHiThruSp;
extern uint16 Thr_FLrnClCtl_posnIniHiThruSp;
extern uint16 Thr_FLrnClCtl_posnIniLoThruSp;
extern uint16 Thr_FLrnClCtl_posnLoThruSp;
extern uint16 Thr_FLrnClCtl_posnReturnLihSp;
extern uint16 Thr_FLrnClCtl_posnSp;
extern uint16 Thr_FLrnClCtl_posnTar;
extern uint16 Thr_FLrnClCtl_vExiLoThru;
extern uint16 Thr_FLrnClCtl_vHiThru;
extern uint16 Thr_FLrnClCtl_vIniHiThru;
extern uint16 Thr_FLrnClCtl_vIniLoThru;
extern uint16 Thr_FLrnClCtl_vLoThru;
extern uint16 Thr_FLrnClCtl_vReturnLih;
extern uint16 Thr_FLrnClCtl_vTar;
extern uint16 Thr_FMblRstor_tiMblRstor;
extern uint16 Thr_FMblRstorClCtl_posnSp;
extern uint16 Thr_FMblRstorClCtl_SpRaw;
extern uint16 Thr_SampleTiMid_physVal;
extern uint16 THRPOSNSPLRN_u16SlewOut;
extern uint16 THRPOSNSPLRN_u16TimerCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRPOSNSPLRN_vidAutomate(void);
void THRPOSNSPLRN_vidCalibration(void);
void THRPOSNSPLRN_vidCmptTemps(void);
void THRPOSNSPLRN_vidCntrndRstrMbilit(void);
void THRPOSNSPLRN_vidDurExitLowThrust(void);
void THRPOSNSPLRN_vidDuringHighThrust(void);
void THRPOSNSPLRN_vidDuringLimpHome(void);
void THRPOSNSPLRN_vidDuringLowThrust(void);
void THRPOSNSPLRN_vidDuringMcwInhTest(void);
void THRPOSNSPLRN_vidFinalSpcSp(void);
void THRPOSNSPLRN_vidInit(void);
void THRPOSNSPLRN_vidMobiltRestorat(void);
void THRPOSNSPLRN_vidRawSpRstrMoblit(void);
void THRPOSNSPLRN_vidResMblitFuncEnb(void);
void THRPOSNSPLRN_vidRstrMblitSetPnt(void);
void THRPOSNSPLRN_vidRstRstrMblitSetP(void);
void THRPOSNSPLRN_vidSglPapilBrisGlac(void);
void THRPOSNSPLRN_vidSlewRate(void);
void THRPOSNSPLRN_vidTransFromCenter(void);


#endif /* THRPOSNSPLRN_L_H */

/*-------------------------------- end of file -------------------------------*/
