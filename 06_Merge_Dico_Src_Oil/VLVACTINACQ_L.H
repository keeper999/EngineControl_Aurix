/***************************************************************************
;**
;** FILE NAME      : VLVACTINACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINACQ_L_H
#define VLVACTINACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_AGCMINMESTBL_COLS                  ( 4 )
#define VLVACTINACQ_u8CAM_LENGTH          4

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

extern const uint8  VLVACTINACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VlvAct_bDgoMissToothVlvActIn;
extern boolean VlvAct_bDgoORngShiftVlvActIn;
extern boolean VlvAct_bDgoORngSpdVlvActIn;
extern boolean VlvAct_bDgoTDCDiagVlvActIn;
extern boolean VlvAct_bMonRunMissToothVlvActIn;
extern boolean VlvAct_bMonRunORngShiftVlvActIn;
extern boolean VlvAct_bMonRunORngSpdVlvActIn;
extern boolean VlvAct_bMonRunTDCDiagVlvActIn;
extern boolean VLVACTINACQ_bnEngInORngShiftThd;
extern boolean VLVACTINACQ_bnEngInTDCDiagThd;
extern boolean Vta_intake_camshaft_level;
extern boolean Vta_intake_velocity_set;
extern uint8 VLVACTINACQ_u8VehActvStatePrev;
extern uint8 Vta_intake_pmh_counter;
extern sint16 VLVACTINACQ_s16VtaIntakeFilt1;
extern sint16 VLVACTINACQ_s16VtaIntakeFilt2;
extern sint16 Vta_intake_camshaft_shift;
extern sint16 Vta_intake_camshaft_velocity;
extern sint16 Vta_intake_camshaft_velocity_1;
extern sint16 Vta_intake_camshaft_velocity_2;
extern uint16 Ext_agCmInMesTbl[EXT_AGCMINMESTBL_COLS];
extern uint16 Ext_agCmInMesTbl_4;
extern uint16 VlvAct_nEngInCm;
extern uint16 VlvAct_nEngInCmAdd;
extern uint16 VLVACTINACQ_u16EngInCmPrev1;
extern uint16 VLVACTINACQ_u16EngInCmPrev2;
extern uint16 VLVACTINACQ_u16EngInCmPrev3;
extern uint16 VLVACTINACQ_u16RelInVvtMesPrev;
extern sint32 VLVACTINACQ_s32FrstOrderFiltMem1;
extern sint32 VLVACTINACQ_s32FrstOrderFiltMem2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINACQ_vidCamEngineSpeed(void);
void VLVACTINACQ_vidCamTargetState(void);
void VLVACTINACQ_vidCurrentShift(void);
void VLVACTINACQ_vidCurrentVelo(void);
void VLVACTINACQ_vidCurrentVelocity(void);
void VLVACTINACQ_vidInCamEngineSpd(void);
void VLVACTINACQ_vidInit(void);
void VLVACTINACQ_vidInitOutput(void);
void VLVACTINACQ_vidInitPannes(void);
void VLVACTINACQ_vidIntakeCalcul(void);
void VLVACTINACQ_vidIntakeCaptCalc(void);
void VLVACTINACQ_vidIntakeDiagnosis(void);
void VLVACTINACQ_vidIntakePmhCounter(void);
void VLVACTINACQ_vidIntakePmhDiag(void);
void VLVACTINACQ_vidIntakeResyn(void);
void VLVACTINACQ_vidIntakeResynchro(void);
void VLVACTINACQ_vidIntakeRisingCapt(void);
void VLVACTINACQ_vidIntCamshaftEdge(void);
void VLVACTINACQ_vidMissToothbMonRun(void);
void VLVACTINACQ_vidORngShiftbMonRun(void);
void VLVACTINACQ_vidORngSpdVlvbMonRun(void);
void VLVACTINACQ_vidSecondOrderFilter(void);
void VLVACTINACQ_vidTDCDiagbMonRun(void);
void VLVACTINACQ_vidTraitementXDent(void);


#endif /* VLVACTINACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
