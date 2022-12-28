/***************************************************************************
;**
;** FILE NAME      : IGEXTHERMOPROT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGEXTHERMOPROT_L_H
#define IGEXTHERMOPROT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define INHIBITION_APPLI_AVANCE_MIN_SPC_LNS   ( 4 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st74 */
#define THERMOPROT_INIT                   4
#define THERMOPROT_INTEGRATION            8
#define THERMOPROT_COUPURE                16
#define THERMOPROT_PROTECTION             32
#define THERMOPROT_COUP_PROT              64
/*extern uint8 IgSys_stThermoProt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  IGEXTHERMOPROT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 IgSys_stThermoProt;
extern boolean IGEXTHERMOPROT_bCond1;
extern boolean IGEXTHERMOPROT_bCond2;
extern boolean IGEXTHERMOPROT_bCond3;
extern boolean IGEXTHERMOPROT_bCond4;
extern boolean IGEXTHERMOPROT_bInitTmrPrev1;
extern boolean IGEXTHERMOPROT_bInitTmrPrev2;
extern boolean IGEXTHERMOPROT_bInitTmrPrev3;
extern boolean IGEXTHERMOPROT_bInitTmrPrev4;
extern boolean IGEXTHERMOPROT_bInitTmrPrev5;
extern boolean IGEXTHERMOPROT_bInitTmrPrev6;
extern boolean IGEXTHERMOPROT_bInitTmrPrev7;
extern boolean IGEXTHERMOPROT_bInitTmrPrev8;
extern boolean IGEXTHERMOPROT_bTimer1Init;
extern boolean IGEXTHERMOPROT_bTimer1InitPrev;
extern boolean IGEXTHERMOPROT_bTimerOut1;
extern boolean IGEXTHERMOPROT_bTimerOut2;
extern boolean IGEXTHERMOPROT_bTimerOut3;
extern boolean IGEXTHERMOPROT_bTimerOut4;
extern boolean Inhibition_appli_avance_min_spc[INHIBITION_APPLI_AVANCE_MIN_SPC_LNS];
extern uint8 IgSys_agIgDifOptmSp;
extern uint8 IgSys_agIgDifOptmThermo;
extern uint8 IgSys_SampleTiMid_PhysVal;
extern uint16 EngM_mfAirCor_temp;
extern uint16 IGEXTHERMOPROT_u16TmrDelay1;
extern uint16 IGEXTHERMOPROT_u16TmrDelay2;
extern uint16 IGEXTHERMOPROT_u16TmrDelay3;
extern uint16 IGEXTHERMOPROT_u16TmrDelay4;
extern uint16 IGEXTHERMOPROT_u16TmrDelay5;
extern uint16 IGEXTHERMOPROT_u16TmrDelay6;
extern uint16 IGEXTHERMOPROT_u16TmrDelay7;
extern uint16 IGEXTHERMOPROT_u16TmrDelay8;
extern uint16 IgSys_mAirInt_thermoProt;
extern uint16 IgSys_mAirMax_ThermoProt;
extern uint16 IgSys_mAirMin_ThermoProt;
extern uint16 IgSys_rDynIgSpEfc_ThP;
extern uint16 IgSys_rMinThermoIgEfc_ThP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGEXTHERMOPROT_vidAdvCalc(void);
void IGEXTHERMOPROT_vidASRAdvCalc(void);
void IGEXTHERMOPROT_vidBVAdvCalc(void);
void IGEXTHERMOPROT_vidCalOnCutOrCutP(void);
void IGEXTHERMOPROT_vidCalOnIntOrProt(void);
void IGEXTHERMOPROT_vidCurAdvCalc(void);
void IGEXTHERMOPROT_vidCut(void);
void IGEXTHERMOPROT_vidCutProt(void);
void IGEXTHERMOPROT_vidInhAdvMinTimer(void);
void IGEXTHERMOPROT_vidInit(void);
void IGEXTHERMOPROT_vidInitOutput(void);
void IGEXTHERMOPROT_vidIntegration(void);
void IGEXTHERMOPROT_vidPrevAdvCalc(void);
void IGEXTHERMOPROT_vidProtAdvCalc(void);
void IGEXTHERMOPROT_vidProtection(void);
void IGEXTHERMOPROT_vidResetProtTherm(void);
void IGEXTHERMOPROT_vidThermProt(void);
void IGEXTHERMOPROT_vidThermProtCalc(void);
void IGEXTHERMOPROT_vidYieldAdvCalc(void);


#endif /* IGEXTHERMOPROT_L_H */

/*-------------------------------- end of file -------------------------------*/
