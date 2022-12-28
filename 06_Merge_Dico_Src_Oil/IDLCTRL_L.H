/***************************************************************************
;**
;** FILE NAME      : IDLCTRL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLCTRL_L_H
#define IDLCTRL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLCTRL_U16TABSAMPLE_COLS              ( 12 )
#define IDLCTRL_u8MAX_SAMPLE_NB           12

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

extern const uint8  IDLCTRL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IDLCTRL_bRstCalc;
extern uint8 IDLCTRL_u8Ind;
extern sint16 IDLCTRL_s16EngErrIdlCtlPrev;
extern sint16 IdlSys_nErrIdlCtl;
extern sint16 IdlSys_nErrIdlCtl1;
extern sint16 IdlSys_nErrIdlCtl2;
extern sint16 IdlSys_nErrIdlCtlPID;
extern sint16 IdlSys_tqIdcAirIdlRaw;
extern sint16 IdlSys_tqIdcIdlRaw;
extern sint16 IdlSys_tqIdcIdlSatMin;
extern sint16 IdlSys_tqIdlCorDer_MP;
extern sint16 IdlSys_tqIdlCorDerFil_MP;
extern sint16 IdlSys_tqIdlCorIni;
extern sint16 IdlSys_tqIdlCorInt_MP;
extern sint16 IdlSys_tqIdlCorMax;
extern sint16 IdlSys_tqIdlCorMin;
extern sint16 IdlSys_tqIdlCorPID;
extern sint16 IdlSys_tqIdlCorProp_MP;
extern sint16 IdlSys_tqIdlCorSatMin;
extern uint16 IDLCTRL_u16nErrIdlAir;
extern uint16 IDLCTRL_u16RatLimOutput;
extern uint16 IDLCTRL_u16TabSample[IDLCTRL_U16TABSAMPLE_COLS];
extern uint16 IDLCTRL_u16TqErrIdlAir;
extern uint16 IdlSys_facDerIdlCtl;
extern uint16 IdlSys_facFilIdlCtl;
extern uint16 IdlSys_facIntIdlCtl;
extern uint16 IdlSys_facPropIdlCtl;
extern uint16 IdlSys_tiFilTqIdlAir_MP;
extern sint32 IDLCTRL_s32TqIdcAirIdlRawFiltMem;
extern sint32 IDLCTRL_s32TqIdlCor;
extern sint32 IdlSys_tqIdlCor;
extern sint32 IdlSys_tqIdlCorNotSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLCTRL_vidAppliquer_SBPA(void);
void IDLCTRL_vidBorner_correction(void);
void IDLCTRL_vidCalc_correction_PID(void);
void IDLCTRL_vidCalc_regulateur_air(void);
void IDLCTRL_vidCalc_regulateur_av(void);
void IDLCTRL_vidCalc_terme_regulateur(void);
void IDLCTRL_vidCalculer_couple_init(void);
void IDLCTRL_vidConditionner_erreur(void);
void IDLCTRL_vidCoord_couples_ralenti(void);
void IDLCTRL_vidIdleSpeedControl(void);
void IDLCTRL_vidInitOutput(void);
void IDLCTRL_vidParametrer_mode_1(void);
void IDLCTRL_vidParametrer_mode_2(void);
void IDLCTRL_vidParametrer_mode_3(void);
void IDLCTRL_vidParametrer_mode_4(void);
void IDLCTRL_vidParametrer_PID(void);


#endif /* IDLCTRL_L_H */

/*-------------------------------- end of file -------------------------------*/
