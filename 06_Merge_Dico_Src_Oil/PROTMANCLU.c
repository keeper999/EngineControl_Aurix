/***************************************************************************
;**
;** FILE NAME      : PROTMANCLU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PROTMANCLU.H"
#include "PROTMANCLU_L.H"
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
const boolean  PtLim_bAcvProtManClu_C = 0;
const boolean  PtLim_bSelIniTClu_C = 0;
const sint8  PtLim_tqCluTqThdNegHi_C = 0;
const sint8  PtLim_tqCluTqThdNegLo_C = 0;
const sint8  PtLim_tqCluTqThdPosHi_C = 0;
const sint8  PtLim_tqCluTqThdPosLo_C = 0;
const uint8  PROTMANCLU_u8Inhib = 0;
const uint8  PtLim_facEfcClu_C = 0;
const uint8  PtLim_facEfcWhlClu_C = 0;
const uint8  PtLim_facMassClu_C = 0;
const uint8  PtLim_facMassCluCase_C = 0;
const uint8  PtLim_facMassItAir_C = 0;
const uint8  PtLim_facMassWhlClu_C = 0;
const uint8  PtLim_facRatePtToWhlGear_T[PTLIM_FACRATEPTTOWHLGEAR_T_COLS] = {0};
const uint8  PtLim_facTCoMesAirExt_T[PTLIM_FACTCOMESAIREXT_T_COLS] = {0};
const uint8  PtLim_facThermoExgAfterStop_T[PTLIM_FACTHERMOEXGAFTERSTOP_T_COLS] = {0};
const uint8  PtLim_facThermoExgEngSpd_T[PTLIM_FACTHERMOEXGENGSPD_T_COLS] = {0};
const uint8  PtLim_facTqGearC_M[PTLIM_FACTQGEARC_M_LNS][PTLIM_FACTQGEARC_M_COLS] = {0};
const uint8  PtLim_facTThermoClu_C = 0;
const uint8  PtLim_facTThermoCluCase_C = 0;
const uint8  PtLim_facTThermoGear_C = 0;
const uint8  PtLim_facTThermoItAir_C = 0;
const uint8  PtLim_facTThermoWhlClu_C = 0;
const uint8  PtLim_jCluEng_C = 0;
const uint8  PtLim_noGear_A[PTLIM_NOGEAR_A_COLS] = {0};
const uint8  PtLim_noGearAX_A[PTLIM_NOGEARAX_A_COLS] = {0};
const uint8  PtLim_noGearBX_A[PTLIM_NOGEARBX_A_COLS] = {0};
const uint8  PtLim_noGearCX_A[PTLIM_NOGEARCX_A_COLS] = {0};
const uint8  PtLim_noGearHi_T[PTLIM_NOGEARHI_T_COLS] = {0};
const uint8  PtLim_noGearLo_T[PTLIM_NOGEARLO_T_COLS] = {0};
const uint8  PtLim_noGearMid_T[PTLIM_NOGEARMID_T_COLS] = {0};
const uint8  PtLim_noGearSel_T[PTLIM_NOGEARSEL_T_COLS] = {0};
const uint8  PtLim_noGearSelHi_A[PTLIM_NOGEARSELHI_A_COLS] = {0};
const uint8  PtLim_noGearSelHi_T[PTLIM_NOGEARSELHI_T_COLS] = {0};
const uint8  PtLim_noGearSelLo_A[PTLIM_NOGEARSELLO_A_COLS] = {0};
const uint8  PtLim_noGearSelLo_T[PTLIM_NOGEARSELLO_T_COLS] = {0};
const uint8  PtLim_noGearSelMid_A[PTLIM_NOGEARSELMID_A_COLS] = {0};
const uint8  PtLim_noGearSelMid_T[PTLIM_NOGEARSELMID_T_COLS] = {0};
const uint8  PtLim_noSelGlblGearHi_A[PTLIM_NOSELGLBLGEARHI_A_COLS] = {0};
const uint8  PtLim_noSelGlblGearLo_A[PTLIM_NOSELGLBLGEARLO_A_COLS] = {0};
const uint8  PtLim_noSelGlblGearMid_A[PTLIM_NOSELGLBLGEARMID_A_COLS] = {0};
const uint8  PtLim_rCaseCluTIni_C = 0;
const uint8  PtLim_rCluTIni_C = 0;
const uint8  PtLim_rGearCluTIni_C = 0;
const uint8  PtLim_rItAirTIni_C = 0;
const uint8  PtLim_rSpdFanReqProtManCluHi_C = 0;
const uint8  PtLim_rSpdFanReqProtManCluLo_C = 0;
const uint8  PtLim_rWhlCluTIni_C = 0;
const uint8  PtLim_spdThdHiDeacProtReg_C = 0;
const uint8  PtLim_spdThdLoDeacProtReg_C = 0;
const uint8  PtLim_spdVehRng_A[PTLIM_SPDVEHRNG_A_COLS] = {0};
const uint8  PtLim_tiDlyTmp_C = 0;
const uint8  PtLim_tOfsCluFanProtHiT_T[PTLIM_TOFSCLUFANPROTHIT_T_COLS] = {0};
const uint8  PtLim_tOfsCluFanProtLoT_T[PTLIM_TOFSCLUFANPROTLOT_T_COLS] = {0};
const uint8  PtLim_tOfsCluNRegT_T[PTLIM_TOFSCLUNREGT_T_COLS] = {0};
const uint8  PtLim_tOfsCluStopWarnT_T[PTLIM_TOFSCLUSTOPWARNT_T_COLS] = {0};
const uint8  PtLim_tOfsConT_C = 0;
const uint8  PtLim_tTCluEstimMemY_A[PTLIM_TTCLUESTIMMEMY_A_COLS] = {0};
const uint8  PtLim_tThdAcvProtFanHi_C = 0;
const uint8  PtLim_tThdAcvProtFanLo_C = 0;
const uint8  PtLim_tThdAcvProtNReg_C = 0;
const uint8  PtLim_tThdAcvProtStopWarn_C = 0;
const uint8  PtLim_tTIniAfterStop_M[PTLIM_TTINIAFTERSTOP_M_LNS][PTLIM_TTINIAFTERSTOP_M_COLS] = {0};
const uint16  PtLim_arCaseEng_C = 0;
const uint16  PtLim_arCaseExtAir_C = 0;
const uint16  PtLim_arCaseGear_C = 0;
const uint16  PtLim_arCaseItAir_C = 0;
const uint16  PtLim_arCluEng_C = 0;
const uint16  PtLim_arCluItAir_C = 0;
const uint16  PtLim_arCluWhlClu_C = 0;
const uint16  PtLim_arEngItAir_C = 0;
const uint16  PtLim_arExtAirGear_C = 0;
const uint16  PtLim_arGearItAir_C = 0;
const uint16  PtLim_arWhlCluItAir_C = 0;
const uint16  PtLim_facMassGear_C = 0;
const uint16  PtLim_facSpdFanReq_C = 0;
const uint16  PtLim_facTCaseEng_C = 0;
const uint16  PtLim_facTCaseExtAir_C = 0;
const uint16  PtLim_facTCaseExtAir_T[PTLIM_FACTCASEEXTAIR_T_COLS] = {0};
const uint16  PtLim_facTCaseGear_C = 0;
const uint16  PtLim_facTCaseItAir_C = 0;
const uint16  PtLim_facTClu_C = 0;
const uint16  PtLim_facTCluCase_C = 0;
const uint16  PtLim_facTCluEng_C = 0;
const uint16  PtLim_facTCluItAir_C = 0;
const uint16  PtLim_facTCluWhlClu_C = 0;
const uint16  PtLim_facTEngItAir_C = 0;
const uint16  PtLim_facTExtAirGear_C = 0;
const uint16  PtLim_facTExtAirGear_T[PTLIM_FACTEXTAIRGEAR_T_COLS] = {0};
const uint16  PtLim_facTGear_C = 0;
const uint16  PtLim_facTGearItAir_C = 0;
const uint16  PtLim_facTItAir_C = 0;
const uint16  PtLim_facTqGearA_M[PTLIM_FACTQGEARA_M_LNS][PTLIM_FACTQGEARA_M_COLS] = {0};
const uint16  PtLim_facTqGearB_M[PTLIM_FACTQGEARB_M_LNS][PTLIM_FACTQGEARB_M_COLS] = {0};
const uint16  PtLim_facTWhlClu_C = 0;
const uint16  PtLim_facTWhlCluItAir_C = 0;
const uint16  PtLim_nEngSpd_A[PTLIM_NENGSPD_A_COLS] = {0};
const uint16  PtLim_pPAirRef_C = 0;
const uint16  PtLim_spdSpdVehFanReq_A[PTLIM_SPDSPDVEHFANREQ_A_COLS] = {0};
const uint16  PtLim_tGearCluEstimAY_A[PTLIM_TGEARCLUESTIMAY_A_COLS] = {0};
const uint16  PtLim_tGearCluEstimBY_A[PTLIM_TGEARCLUESTIMBY_A_COLS] = {0};
const uint16  PtLim_tGearCluEstimCY_A[PTLIM_TGEARCLUESTIMCY_A_COLS] = {0};
const uint16  PtLim_tiEngStopX_A[PTLIM_TIENGSTOPX_A_COLS] = {0};
const uint16  PtLim_tiFilEngSpd_C = 0;
const uint16  PtLim_tiFilTqClu_C = 0;
const uint16  PtLim_tiThdSelIniTClu_C = 0;
const uint16  PtLim_tiThermoExgAfterStop_A[PTLIM_TITHERMOEXGAFTERSTOP_A_COLS] = {0};
const uint16  PtLim_tTGrdFanProtCluHi_A[PTLIM_TTGRDFANPROTCLUHI_A_COLS] = {0};
const uint16  PtLim_tTGrdFanProtCluLo_A[PTLIM_TTGRDFANPROTCLULO_A_COLS] = {0};
const uint16  PtLim_tTGrdNRegClu_A[PTLIM_TTGRDNREGCLU_A_COLS] = {0};
const uint16  PtLim_tTGrdStopWarnClu_A[PTLIM_TTGRDSTOPWARNCLU_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoPt_bAcvProtCluBfCord;
boolean CoPt_bDgoCluDmgAfts;
boolean CoPt_bDgoCluDmgAftsBfCord;
boolean CoPt_bMonRunCluDmgAfts;
boolean CoPt_bMonRunCluDmgAftsBfCord;
boolean CoPt_bWarnProtClu;
boolean CoPt_bWarnProtCluBfCord;
boolean PROTMANCLU_bBasculeRS;
boolean PROTMANCLU_bOutHysNeg5;
boolean PROTMANCLU_bOutHysPos;
boolean PROTMANCLU_bOutHysPos1;
boolean PROTMANCLU_bOutHysPos2;
boolean PROTMANCLU_bOutHysPos3;
boolean PROTMANCLU_bOutHysPos4;
boolean PROTMANCLU_bOutHysPos5;
boolean PROTMANCLU_bRstIntegrator;
boolean PROTMANCLU_bRstIntegratorPrev;
boolean PROTMANCLU_bTurnOffDelayInPrev;
boolean PtLim_bDeacManCluProtReg;
sint8 PtLim_tOfsCluFanProtHiT;
sint8 PtLim_tOfsCluFanProtLoT;
sint8 PtLim_tOfsCluNRegT;
sint8 PtLim_tOfsCluStopWarnT;
uint8 CoPt_rSpdFanReqProtCluBfCord;
uint8 PROTMANCLU_u8Ext_stGBxCfPrev;
uint8 PROTMANCLU_u8OutMem1;
uint8 PROTMANCLU_u8PtLim_noGearMid;
uint8 PROTMANCLU_u8PtLim_stManCluPrev;
uint8 PROTMANCLU_u8PtLim_stManCluPrev2;
uint8 PtLim_facTqGearHiC_MP;
uint8 PtLim_facTqGearLoC_MP;
uint8 PtLim_facTqGearMidC_MP;
uint8 PtLim_noCrtSelGear;
uint8 PtLim_noGearHi;
uint8 PtLim_noGearLo;
uint8 PtLim_noGearMid;
uint8 PtLim_noGearSel;
uint8 PtLim_noProtManClu;
uint8 PtLim_prm_facRatePtToWhl_MP[PTLIM_PRM_FACRATEPTTOWHL_MP_COLS];
uint8 PtLim_stManClu;
sint16 CoPt_tManCluEstim;
sint16 CoPt_tManCluEstimBfCord;
sint16 PROTMANCLU_s16CoPt_tManCluPrev1;
sint16 PROTMANCLU_s16CoPt_tManCluPrev2;
sint16 PROTMANCLU_s16CoPt_tManCluPrev3;
sint16 PROTMANCLU_s16CoPt_tManCluPrev4;
sint16 PtLim_nCkGrdFil_MP;
sint16 PtLim_prm_pwrDeltaLoHi_MP[PTLIM_PRM_PWRDELTALOHI_MP_COLS];
sint16 PtLim_prm_pwrDeltaLoMid_MP[PTLIM_PRM_PWRDELTALOMID_MP_COLS];
sint16 PtLim_pwrDeltaCluSel;
sint16 PtLim_pwrDeltaGearSel;
sint16 PtLim_pwrDeltaWhlCluSel;
sint16 PtLim_tGrdDynCluT;
sint16 PtLim_tqManClu;
sint16 PtLim_wDeltaCluLoHi;
sint16 PtLim_wDeltaCluLoMid;
sint16 PtLim_wDeltaGearLoHi;
sint16 PtLim_wDeltaGearLoMid;
sint16 PtLim_wDeltaWhlCluLoHi;
sint16 PtLim_wDeltaWhlCluLoMid;
uint16 PROTMANCLU_u16AirCluEstimPrev2;
uint16 PROTMANCLU_u16CaseCluEstimPrev2;
uint16 PROTMANCLU_u16CluEstimPrev2;
uint16 PROTMANCLU_u16GearCluEstimPrev2;
uint16 PROTMANCLU_u16PtLim_tiEngStopCf;
uint16 PROTMANCLU_u16SpdVehFanReq;
uint16 PROTMANCLU_u16TurnOffDelayCount;
uint16 PROTMANCLU_u16WhlCluEstimPrev2;
uint16 PtLim_facTCaseExtAir;
uint16 PtLim_facTCaseItAir;
uint16 PtLim_facTCluItAir;
uint16 PtLim_facTCoMesAirExt;
uint16 PtLim_facTEngItAir;
uint16 PtLim_facTExtAirGear;
uint16 PtLim_facTGearItAir;
uint16 PtLim_facTqGearHiA_MP;
uint16 PtLim_facTqGearHiB_MP;
uint16 PtLim_facTqGearLoA_MP;
uint16 PtLim_facTqGearLoB_MP;
uint16 PtLim_facTqGearMidA_MP;
uint16 PtLim_facTqGearMidB_MP;
uint16 PtLim_facTWhlCluItAir;
uint16 PtLim_nDeltaPrimEngSpdHi;
uint16 PtLim_nDeltaPrimEngSpdLo;
uint16 PtLim_nDeltaPrimEngSpdMid;
uint16 PtLim_nPrimShaftTheHi;
uint16 PtLim_nPrimShaftTheLo;
uint16 PtLim_nPrimShaftTheMid;
uint16 PtLim_prm_tTIniAfterStop_MP[PTLIM_PRM_TTINIAFTERSTOP_MP_COLS];
uint16 PtLim_pwrHeatCluLo;
uint16 PtLim_pwrHeatGearLo;
uint16 PtLim_pwrHeatWhlCluLo;
uint16 PtLim_tAirExtMes;
uint16 PtLim_tCaseCluEstim;
uint16 PtLim_tCaseCluEstimGrd_MP;
uint16 PtLim_tCaseCluEstimPrev;
uint16 PtLim_tCluEstim;
uint16 PtLim_tCluEstimGrd_MP;
uint16 PtLim_tCluEstimPrev;
uint16 PtLim_tCoMes;
uint16 PtLim_tGearCluEstim;
uint16 PtLim_tGearCluEstimGrd_MP;
uint16 PtLim_tGearCluEstimPrev;
uint16 PtLim_tItAirCluEstim;
uint16 PtLim_tItAirCluEstimGrd_MP;
uint16 PtLim_tItAirCluEstimPrev;
uint16 PtLim_tOilEstim;
uint16 PtLim_tqManCluCf;
uint16 PtLim_tWhlCluEstim;
uint16 PtLim_tWhlCluEstimGrd_MP;
uint16 PtLim_tWhlCluEstimPrev;
sint32 PROTMANCLU_s32Filtre1Mem;
sint32 PROTMANCLU_s32Filtre2Mem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

