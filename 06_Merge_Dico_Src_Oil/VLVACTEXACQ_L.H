/***************************************************************************
;**
;** FILE NAME      : VLVACTEXACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXACQ_L_H
#define VLVACTEXACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_AGCMEXMESTBL_COLS                  ( 4 )
#define VLVACTEXACQ_u8CAM_LENGTH          4

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

extern const uint8  VLVACTEXACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bDgoMissToothVlvActEx;
extern boolean VlvAct_bDgoORngShiftVlvActEx;
extern boolean VlvAct_bDgoORngSpdVlvActEx;
extern boolean VlvAct_bDgoTDCDiagVlvActEx;
extern boolean VlvAct_bMonRunMissToothVlvActEx;
extern boolean VlvAct_bMonRunORngShiftVlvActEx;
extern boolean VlvAct_bMonRunORngSpdVlvActEx;
extern boolean VlvAct_bMonRunTDCDiagVlvActEx;
extern boolean VLVACTEXACQ_bnEngExORngShiftThd;
extern boolean VLVACTEXACQ_bnEngExTDCDiagThd;
extern boolean Vta_exhaust_camshaft_level;
extern boolean Vta_exhaust_velocity_set;
extern uint8 VLVACTEXACQ_u8VehActivStatePrev;
extern uint8 Vta_exhaust_pmh_counter;
extern sint16 VLVACTEXACQ_s16VtaExhaustFilt1;
extern sint16 VLVACTEXACQ_s16VtaExhaustFilt2;
extern sint16 Vta_exhaust_camshaft_shift;
extern sint16 Vta_exhaust_camshaft_velocity;
extern sint16 Vta_exhaust_camshaft_velocity_1;
extern sint16 Vta_exhaust_camshaft_velocity_2;
extern uint16 Ext_agCmExMesTbl[EXT_AGCMEXMESTBL_COLS];
extern uint16 VlvAct_nEngExCm;
extern uint16 VlvAct_nEngExCmAdd;
extern uint16 VLVACTEXACQ_u16EngInCmPrev1;
extern uint16 VLVACTEXACQ_u16EngInCmPrev2;
extern uint16 VLVACTEXACQ_u16EngInCmPrev3;
extern uint16 VLVACTEXACQ_u16RelInVvtMesPrev;
extern sint32 VLVACTEXACQ_s32FrstOrderFiltMem1;
extern sint32 VLVACTEXACQ_s32FrstOrderFiltMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXACQ_vidCamTargetState(void);
void VLVACTEXACQ_vidCurrentShift(void);
void VLVACTEXACQ_vidCurrentVelo(void);
void VLVACTEXACQ_vidCurrentVelocity(void);
void VLVACTEXACQ_vidExCamEngineSpd(void);
void VLVACTEXACQ_vidExhaustCalcul(void);
void VLVACTEXACQ_vidExhaustCaptCalc(void);
void VLVACTEXACQ_vidExhaustDiagnosis(void);
void VLVACTEXACQ_vidExhaustPmhCounter(void);
void VLVACTEXACQ_vidExhaustPmhDiag(void);
void VLVACTEXACQ_vidExhaustResyn(void);
void VLVACTEXACQ_vidExhaustResynchro(void);
void VLVACTEXACQ_vidExhaustRisingCapt(void);
void VLVACTEXACQ_vidExhautsDiagnosis(void);
void VLVACTEXACQ_vidInit(void);
void VLVACTEXACQ_vidInitOutput(void);
void VLVACTEXACQ_vidInitPannes(void);
void VLVACTEXACQ_vidIntCamshaftEdge(void);
void VLVACTEXACQ_vidMissToothbMonRun(void);
void VLVACTEXACQ_vidORngShiftbMonRun(void);
void VLVACTEXACQ_vidORngSpdVlvbMonRun(void);
void VLVACTEXACQ_vidSecondOrderFilter(void);
void VLVACTEXACQ_vidTDCDiagbMonRun(void);
void VLVACTEXACQ_vidTraitementXDent(void);


#endif /* VLVACTEXACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
