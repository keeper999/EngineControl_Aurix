/***************************************************************************
;**
;** FILE NAME      : PROTMANCLU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROTMANCLU_L_H
#define PROTMANCLU_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define PTLIM_PRM_FACRATEPTTOWHL_MP_COLS       ( 3 )
#define PTLIM_PRM_PWRDELTALOHI_MP_COLS         ( 3 )
#define PTLIM_PRM_PWRDELTALOMID_MP_COLS        ( 3 )
#define PTLIM_PRM_TTINIAFTERSTOP_MP_COLS       ( 5 )

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

extern const uint8  PROTMANCLU_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPt_bAcvProtCluBfCord;
extern boolean CoPt_bDgoCluDmgAftsBfCord;
extern boolean CoPt_bMonRunCluDmgAftsBfCord;
extern boolean CoPt_bWarnProtCluBfCord;
extern boolean PROTMANCLU_bBasculeRS;
extern boolean PROTMANCLU_bOutHysNeg5;
extern boolean PROTMANCLU_bOutHysPos;
extern boolean PROTMANCLU_bOutHysPos1;
extern boolean PROTMANCLU_bOutHysPos2;
extern boolean PROTMANCLU_bOutHysPos3;
extern boolean PROTMANCLU_bOutHysPos4;
extern boolean PROTMANCLU_bOutHysPos5;
extern boolean PROTMANCLU_bRstIntegrator;
extern boolean PROTMANCLU_bRstIntegratorPrev;
extern boolean PROTMANCLU_bTurnOffDelayInPrev;
extern boolean PtLim_bDeacManCluProtReg;
extern sint8 PtLim_tOfsCluFanProtHiT;
extern sint8 PtLim_tOfsCluFanProtLoT;
extern sint8 PtLim_tOfsCluNRegT;
extern sint8 PtLim_tOfsCluStopWarnT;
extern uint8 CoPt_rSpdFanReqProtCluBfCord;
extern uint8 PROTMANCLU_u8Ext_stGBxCfPrev;
extern uint8 PROTMANCLU_u8OutMem1;
extern uint8 PROTMANCLU_u8PtLim_noGearMid;
extern uint8 PROTMANCLU_u8PtLim_stManCluPrev;
extern uint8 PROTMANCLU_u8PtLim_stManCluPrev2;
extern uint8 PtLim_facTqGearHiC_MP;
extern uint8 PtLim_facTqGearLoC_MP;
extern uint8 PtLim_facTqGearMidC_MP;
extern uint8 PtLim_noCrtSelGear;
extern uint8 PtLim_noGearHi;
extern uint8 PtLim_noGearLo;
extern uint8 PtLim_noGearMid;
extern uint8 PtLim_noGearSel;
extern uint8 PtLim_noProtManClu;
extern uint8 PtLim_prm_facRatePtToWhl_MP[PTLIM_PRM_FACRATEPTTOWHL_MP_COLS];
extern uint8 PtLim_stManClu;
extern sint16 CoPt_tManCluEstimBfCord;
extern sint16 PROTMANCLU_s16CoPt_tManCluPrev1;
extern sint16 PROTMANCLU_s16CoPt_tManCluPrev2;
extern sint16 PROTMANCLU_s16CoPt_tManCluPrev3;
extern sint16 PROTMANCLU_s16CoPt_tManCluPrev4;
extern sint16 PtLim_nCkGrdFil_MP;
extern sint16 PtLim_prm_pwrDeltaLoHi_MP[PTLIM_PRM_PWRDELTALOHI_MP_COLS];
extern sint16 PtLim_prm_pwrDeltaLoMid_MP[PTLIM_PRM_PWRDELTALOMID_MP_COLS];
extern sint16 PtLim_pwrDeltaCluSel;
extern sint16 PtLim_pwrDeltaGearSel;
extern sint16 PtLim_pwrDeltaWhlCluSel;
extern sint16 PtLim_tGrdDynCluT;
extern sint16 PtLim_tqManClu;
extern sint16 PtLim_wDeltaCluLoHi;
extern sint16 PtLim_wDeltaCluLoMid;
extern sint16 PtLim_wDeltaGearLoHi;
extern sint16 PtLim_wDeltaGearLoMid;
extern sint16 PtLim_wDeltaWhlCluLoHi;
extern sint16 PtLim_wDeltaWhlCluLoMid;
extern uint16 PROTMANCLU_u16AirCluEstimPrev2;
extern uint16 PROTMANCLU_u16CaseCluEstimPrev2;
extern uint16 PROTMANCLU_u16CluEstimPrev2;
extern uint16 PROTMANCLU_u16GearCluEstimPrev2;
extern uint16 PROTMANCLU_u16PtLim_tiEngStopCf;
extern uint16 PROTMANCLU_u16SpdVehFanReq;
extern uint16 PROTMANCLU_u16TurnOffDelayCount;
extern uint16 PROTMANCLU_u16WhlCluEstimPrev2;
extern uint16 PtLim_facTCaseExtAir;
extern uint16 PtLim_facTCaseItAir;
extern uint16 PtLim_facTCluItAir;
extern uint16 PtLim_facTCoMesAirExt;
extern uint16 PtLim_facTEngItAir;
extern uint16 PtLim_facTExtAirGear;
extern uint16 PtLim_facTGearItAir;
extern uint16 PtLim_facTqGearHiA_MP;
extern uint16 PtLim_facTqGearHiB_MP;
extern uint16 PtLim_facTqGearLoA_MP;
extern uint16 PtLim_facTqGearLoB_MP;
extern uint16 PtLim_facTqGearMidA_MP;
extern uint16 PtLim_facTqGearMidB_MP;
extern uint16 PtLim_facTWhlCluItAir;
extern uint16 PtLim_nDeltaPrimEngSpdHi;
extern uint16 PtLim_nDeltaPrimEngSpdLo;
extern uint16 PtLim_nDeltaPrimEngSpdMid;
extern uint16 PtLim_nPrimShaftTheHi;
extern uint16 PtLim_nPrimShaftTheLo;
extern uint16 PtLim_nPrimShaftTheMid;
extern uint16 PtLim_prm_tTIniAfterStop_MP[PTLIM_PRM_TTINIAFTERSTOP_MP_COLS];
extern uint16 PtLim_pwrHeatCluLo;
extern uint16 PtLim_pwrHeatGearLo;
extern uint16 PtLim_pwrHeatWhlCluLo;
extern uint16 PtLim_tAirExtMes;
extern uint16 PtLim_tCaseCluEstim;
extern uint16 PtLim_tCaseCluEstimGrd_MP;
extern uint16 PtLim_tCaseCluEstimPrev;
extern uint16 PtLim_tCluEstim;
extern uint16 PtLim_tCluEstimGrd_MP;
extern uint16 PtLim_tCluEstimPrev;
extern uint16 PtLim_tCoMes;
extern uint16 PtLim_tGearCluEstim;
extern uint16 PtLim_tGearCluEstimGrd_MP;
extern uint16 PtLim_tGearCluEstimPrev;
extern uint16 PtLim_tItAirCluEstim;
extern uint16 PtLim_tItAirCluEstimGrd_MP;
extern uint16 PtLim_tItAirCluEstimPrev;
extern uint16 PtLim_tOilEstim;
extern uint16 PtLim_tqManCluCf;
extern uint16 PtLim_tWhlCluEstim;
extern uint16 PtLim_tWhlCluEstimGrd_MP;
extern uint16 PtLim_tWhlCluEstimPrev;
extern sint32 PROTMANCLU_s32Filtre1Mem;
extern sint32 PROTMANCLU_s32Filtre2Mem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PROTMANCLU_vidActivationProtect(void);
void PROTMANCLU_vidActivOfProtection(void);
void PROTMANCLU_vidActivProtections(void);
uint16 PROTMANCLU_vidCalcCoefConParm(uint16 u16FirstCalib, uint16 u16SecondCalib, uint8 u8Interp1d);
void PROTMANCLU_vidCalcCoefConvHeatex(void);
void PROTMANCLU_vidCalcDelLowHighEngy(void);
void PROTMANCLU_vidCalcDelLowMidEnrgy(void);
void PROTMANCLU_vidCalcDisPowerLowRat(void);
void PROTMANCLU_vidCalcGradclutchTemp(void);
void PROTMANCLU_vidCalculationOffsets(void);
void PROTMANCLU_vidCalculPreviousTemp(void);
void PROTMANCLU_vidCalculPrevTempInit(void);
void PROTMANCLU_vidCalDelEngPrimshaft(void);
void PROTMANCLU_vidClutch_Protection(void);
void PROTMANCLU_vidConvTemperToKelvin(void);
void PROTMANCLU_vidDeactvEngRotSpdctr(void);
void PROTMANCLU_vidDetermStateClutch(void);
void PROTMANCLU_vidDeterStatesClutch(void);
void PROTMANCLU_vidDeterTripltGearbox(void);
void PROTMANCLU_vidEstimClutchBellTmp(void);
void PROTMANCLU_vidEstimClutchPlatTmp(void);
void PROTMANCLU_vidEstimClutchTemp(void);
void PROTMANCLU_vidEstimClutchTemper(void);
void PROTMANCLU_vidEstimDissipatEnerg(void);
void PROTMANCLU_vidEstimGearboxTemp(void);
void PROTMANCLU_vidEstimHeatArdClutch(void);
void PROTMANCLU_vidEstimHousClutchTmp(void);
void PROTMANCLU_vidEstimTempOfClutch(void);
void PROTMANCLU_vidEstimTorqTransClut(void);
void PROTMANCLU_vidInitOutput(void);
void PROTMANCLU_vidOutput_managment(void);
void PROTMANCLU_vidReconfigProtActiv(void);
void PROTMANCLU_vidReconfTorqTransClu(void);
void PROTMANCLU_vidSelectEnergyInject(void);
void PROTMANCLU_vidSelectEnergyToInj(void);
void PROTMANCLU_vidSelectGearboxRatio(void);


#endif /* PROTMANCLU_L_H */

/*-------------------------------- end of file -------------------------------*/
