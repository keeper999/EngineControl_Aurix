/***************************************************************************
;**
;** FILE NAME      : HEATSENO2UPPERDDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HEATSENO2UPPERDDIAG_L_H
#define HEATSENO2UPPERDDIAG_L_H

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

extern const uint8  HEATSENO2UPPERDDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Enable_period_lean;
extern boolean Enable_period_rich;
extern boolean HEATSENO2UPPERDDIAG_bEnleanPrev;
extern boolean HEATSENO2UPPERDDIAG_bEnrichPrev;
extern boolean HEATSENO2UPPERDDIAG_bOxyApvPrev;
extern boolean HEATSENO2UPPERDDIAG_bOxySensPrev;
extern boolean HEATSENO2UPPERDDIAG_bTimeout1;
extern boolean HEATSENO2UPPERDDIAG_bTimeout2;
extern boolean Oxy_sens_period_apv_failure;
extern boolean Oxy_sens_period_failure;
extern boolean SenO2Us_bDgoORng_OxyApvPerd;
extern boolean SenO2Us_bDgoORng_OxySensPerd;
extern boolean SenO2Us_bMonRunORng_OxyApvPerd;
extern boolean SenO2Us_bMonRunORng_OxySensPerd;
extern boolean SenO2Us_bMonRunRaw_OxyApvPerd;
extern boolean SenO2Us_bMonRunRaw_OxySensPerd;
extern boolean SenO2Us_bMonWaitORng_OxyApvPerd;
extern boolean SenO2Us_bMonWaitORng_OxySensPerd;
extern boolean SenO2Us_bMonWaitRaw_OxyApvPerd;
extern boolean SenO2Us_bMonWaitRaw_OxySensPerd;
extern uint8 HEATSENO2UPPERDDIAG_u8SysGasPrev;
extern uint8 Os_period_tests_done;
extern uint8 Oxy_period_tests;
extern uint16 Dnstr_modifier_temp;
extern uint16 Lfbk_on_enlean_clamp_delay;
extern uint16 Lfbk_on_enrich_clamp_delay;
extern uint16 LsMon_tiPerUs;
extern uint16 Max_oxy_apv_period_l;
extern uint16 Max_oxy_apv_period_r;
extern uint16 Max_oxy_sens_period_l;
extern uint16 Max_oxy_sens_period_r;
extern uint16 Oxy_apv_period_map_max;
extern uint16 Oxy_sens_lower_voltage_thresh;
extern uint16 Oxy_sens_period_map_max;
extern uint16 Oxy_sens_upper_voltage_thresh;
extern uint16 Oxy_ups_period;
extern uint16 Oxy_ups_period_lean;
extern uint16 Oxy_ups_period_rich;
extern uint16 Oxy_ups_tempo_lean;
extern uint16 Oxy_ups_tempo_rich;
extern uint16 SenO2Us_PerDiag_FacMaxRaw;
extern uint16 SenO2Us_PerDiag_FacMesRaw;
extern uint16 SenO2Us_PerDiag_tiInhDiag;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HEATSENO2UPPERDDIAG_vidApvPMonit(void);
void HEATSENO2UPPERDDIAG_vidCalcPerdL(void);
void HEATSENO2UPPERDDIAG_vidCalcPerdR(void);
void HEATSENO2UPPERDDIAG_vidcallGDU(void);
void HEATSENO2UPPERDDIAG_vidCntLean(void);
void HEATSENO2UPPERDDIAG_vidCntRich(void);
void HEATSENO2UPPERDDIAG_vidCompPerL(void);
void HEATSENO2UPPERDDIAG_vidCompPerR(void);
void HEATSENO2UPPERDDIAG_vidCorLean(void);
void HEATSENO2UPPERDDIAG_vidCorRich(void);
void HEATSENO2UPPERDDIAG_vidCounters(void);
void HEATSENO2UPPERDDIAG_vidCpThdApvR(void);
void HEATSENO2UPPERDDIAG_vidCpThdSnsR(void);
void HEATSENO2UPPERDDIAG_vidCrPrdLean(void);
void HEATSENO2UPPERDDIAG_vidCrPrdRich(void);
void HEATSENO2UPPERDDIAG_vidCtThdApvL(void);
void HEATSENO2UPPERDDIAG_vidCtThdsnsL(void);
void HEATSENO2UPPERDDIAG_vidDiagCompl(void);
void HEATSENO2UPPERDDIAG_vidDiagCond(void);
void HEATSENO2UPPERDDIAG_vidEfLeanCal(void);
void HEATSENO2UPPERDDIAG_vidEfRichCal(void);
void HEATSENO2UPPERDDIAG_vidIniCnLean(void);
void HEATSENO2UPPERDDIAG_vidIniCnRich(void);
void HEATSENO2UPPERDDIAG_vidIniOutput(void);
void HEATSENO2UPPERDDIAG_vidInit(void);
void HEATSENO2UPPERDDIAG_vidInitCbTrn(void);
void HEATSENO2UPPERDDIAG_vidIniTimers(void);
void HEATSENO2UPPERDDIAG_vidOsPFaultL(void);
void HEATSENO2UPPERDDIAG_vidOsPFaultR(void);
void HEATSENO2UPPERDDIAG_vidPerDgApv(void);
void HEATSENO2UPPERDDIAG_vidPerDgSens(void);
void HEATSENO2UPPERDDIAG_vidPerdLean(void);
void HEATSENO2UPPERDDIAG_vidPerdRich(void);
void HEATSENO2UPPERDDIAG_vidPerTest(void);
void HEATSENO2UPPERDDIAG_vidPMonitor(void);
void HEATSENO2UPPERDDIAG_vidReInPrTst(void);
void HEATSENO2UPPERDDIAG_vidReIntPer(void);
void HEATSENO2UPPERDDIAG_vidRepOsPFlL(void);
void HEATSENO2UPPERDDIAG_vidRepOsPFlR(void);
void HEATSENO2UPPERDDIAG_vidSensPerEf(void);
void HEATSENO2UPPERDDIAG_vidsnsPTest(void);
void HEATSENO2UPPERDDIAG_vidStateMgr(void);
void HEATSENO2UPPERDDIAG_vidTgInitTrn(void);


#endif /* HEATSENO2UPPERDDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
