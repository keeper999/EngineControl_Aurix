/***************************************************************************
;**
;** FILE NAME      : PROTMANCLU.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROTMANCLU_H
#define PROTMANCLU_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define PTLIM_FACRATEPTTOWHLGEAR_T_COLS        ( 7 )
#define PTLIM_FACTCASEEXTAIR_T_COLS            ( 7 )
#define PTLIM_FACTCOMESAIREXT_T_COLS           ( 7 )
#define PTLIM_FACTEXTAIRGEAR_T_COLS            ( 7 )
#define PTLIM_FACTHERMOEXGAFTERSTOP_T_COLS     ( 8 )
#define PTLIM_FACTHERMOEXGENGSPD_T_COLS        ( 7 )
#define PTLIM_FACTQGEARA_M_LNS                ( 8 )
#define PTLIM_FACTQGEARA_M_COLS                ( 9 )
#define PTLIM_FACTQGEARB_M_LNS                ( 8 )
#define PTLIM_FACTQGEARB_M_COLS                ( 9 )
#define PTLIM_FACTQGEARC_M_LNS                ( 8 )
#define PTLIM_FACTQGEARC_M_COLS                ( 9 )
#define PTLIM_NENGSPD_A_COLS                   ( 7 )
#define PTLIM_NOGEAR_A_COLS                    ( 7 )
#define PTLIM_NOGEARAX_A_COLS                  ( 8 )
#define PTLIM_NOGEARBX_A_COLS                  ( 8 )
#define PTLIM_NOGEARCX_A_COLS                  ( 8 )
#define PTLIM_NOGEARHI_T_COLS                  ( 3 )
#define PTLIM_NOGEARLO_T_COLS                  ( 3 )
#define PTLIM_NOGEARMID_T_COLS                 ( 3 )
#define PTLIM_NOGEARSEL_T_COLS                 ( 3 )
#define PTLIM_NOGEARSELHI_A_COLS               ( 3 )
#define PTLIM_NOGEARSELHI_T_COLS               ( 3 )
#define PTLIM_NOGEARSELLO_A_COLS               ( 3 )
#define PTLIM_NOGEARSELLO_T_COLS               ( 3 )
#define PTLIM_NOGEARSELMID_A_COLS              ( 3 )
#define PTLIM_NOGEARSELMID_T_COLS              ( 3 )
#define PTLIM_NOSELGLBLGEARHI_A_COLS           ( 3 )
#define PTLIM_NOSELGLBLGEARLO_A_COLS           ( 3 )
#define PTLIM_NOSELGLBLGEARMID_A_COLS          ( 3 )
#define PTLIM_SPDSPDVEHFANREQ_A_COLS           ( 7 )
#define PTLIM_SPDVEHRNG_A_COLS                 ( 3 )
#define PTLIM_TGEARCLUESTIMAY_A_COLS           ( 9 )
#define PTLIM_TGEARCLUESTIMBY_A_COLS           ( 9 )
#define PTLIM_TGEARCLUESTIMCY_A_COLS           ( 9 )
#define PTLIM_TIENGSTOPX_A_COLS                ( 8 )
#define PtLim_tiSdlManCluTEstim_SC        40
#define PTLIM_TITHERMOEXGAFTERSTOP_A_COLS      ( 8 )
#define PTLIM_TOFSCLUFANPROTHIT_T_COLS         ( 4 )
#define PTLIM_TOFSCLUFANPROTLOT_T_COLS         ( 4 )
#define PTLIM_TOFSCLUNREGT_T_COLS              ( 4 )
#define PTLIM_TOFSCLUSTOPWARNT_T_COLS          ( 4 )
#define PTLIM_TTCLUESTIMMEMY_A_COLS            ( 8 )
#define PTLIM_TTGRDFANPROTCLUHI_A_COLS         ( 4 )
#define PTLIM_TTGRDFANPROTCLULO_A_COLS         ( 4 )
#define PTLIM_TTGRDNREGCLU_A_COLS              ( 4 )
#define PTLIM_TTGRDSTOPWARNCLU_A_COLS          ( 4 )
#define PTLIM_TTINIAFTERSTOP_M_LNS            ( 8 )
#define PTLIM_TTINIAFTERSTOP_M_COLS            ( 8 )

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

extern const boolean  PtLim_bAcvProtManClu_C;
extern const boolean  PtLim_bSelIniTClu_C;
extern const sint8  PtLim_tqCluTqThdNegHi_C;
extern const sint8  PtLim_tqCluTqThdNegLo_C;
extern const sint8  PtLim_tqCluTqThdPosHi_C;
extern const sint8  PtLim_tqCluTqThdPosLo_C;
extern const uint8  PtLim_facEfcClu_C;
extern const uint8  PtLim_facEfcWhlClu_C;
extern const uint8  PtLim_facMassClu_C;
extern const uint8  PtLim_facMassCluCase_C;
extern const uint8  PtLim_facMassItAir_C;
extern const uint8  PtLim_facMassWhlClu_C;
extern const uint8  PtLim_facRatePtToWhlGear_T[PTLIM_FACRATEPTTOWHLGEAR_T_COLS];
extern const uint8  PtLim_facTCoMesAirExt_T[PTLIM_FACTCOMESAIREXT_T_COLS];
extern const uint8  PtLim_facThermoExgAfterStop_T[PTLIM_FACTHERMOEXGAFTERSTOP_T_COLS];
extern const uint8  PtLim_facThermoExgEngSpd_T[PTLIM_FACTHERMOEXGENGSPD_T_COLS];
extern const uint8  PtLim_facTqGearC_M[PTLIM_FACTQGEARC_M_LNS][PTLIM_FACTQGEARC_M_COLS];
extern const uint8  PtLim_facTThermoClu_C;
extern const uint8  PtLim_facTThermoCluCase_C;
extern const uint8  PtLim_facTThermoGear_C;
extern const uint8  PtLim_facTThermoItAir_C;
extern const uint8  PtLim_facTThermoWhlClu_C;
extern const uint8  PtLim_jCluEng_C;
extern const uint8  PtLim_noGear_A[PTLIM_NOGEAR_A_COLS];
extern const uint8  PtLim_noGearAX_A[PTLIM_NOGEARAX_A_COLS];
extern const uint8  PtLim_noGearBX_A[PTLIM_NOGEARBX_A_COLS];
extern const uint8  PtLim_noGearCX_A[PTLIM_NOGEARCX_A_COLS];
extern const uint8  PtLim_noGearHi_T[PTLIM_NOGEARHI_T_COLS];
extern const uint8  PtLim_noGearLo_T[PTLIM_NOGEARLO_T_COLS];
extern const uint8  PtLim_noGearMid_T[PTLIM_NOGEARMID_T_COLS];
extern const uint8  PtLim_noGearSel_T[PTLIM_NOGEARSEL_T_COLS];
extern const uint8  PtLim_noGearSelHi_A[PTLIM_NOGEARSELHI_A_COLS];
extern const uint8  PtLim_noGearSelHi_T[PTLIM_NOGEARSELHI_T_COLS];
extern const uint8  PtLim_noGearSelLo_A[PTLIM_NOGEARSELLO_A_COLS];
extern const uint8  PtLim_noGearSelLo_T[PTLIM_NOGEARSELLO_T_COLS];
extern const uint8  PtLim_noGearSelMid_A[PTLIM_NOGEARSELMID_A_COLS];
extern const uint8  PtLim_noGearSelMid_T[PTLIM_NOGEARSELMID_T_COLS];
extern const uint8  PtLim_noSelGlblGearHi_A[PTLIM_NOSELGLBLGEARHI_A_COLS];
extern const uint8  PtLim_noSelGlblGearLo_A[PTLIM_NOSELGLBLGEARLO_A_COLS];
extern const uint8  PtLim_noSelGlblGearMid_A[PTLIM_NOSELGLBLGEARMID_A_COLS];
extern const uint8  PtLim_rCaseCluTIni_C;
extern const uint8  PtLim_rCluTIni_C;
extern const uint8  PtLim_rGearCluTIni_C;
extern const uint8  PtLim_rItAirTIni_C;
extern const uint8  PtLim_rSpdFanReqProtManCluHi_C;
extern const uint8  PtLim_rSpdFanReqProtManCluLo_C;
extern const uint8  PtLim_rWhlCluTIni_C;
extern const uint8  PtLim_spdThdHiDeacProtReg_C;
extern const uint8  PtLim_spdThdLoDeacProtReg_C;
extern const uint8  PtLim_spdVehRng_A[PTLIM_SPDVEHRNG_A_COLS];
extern const uint8  PtLim_tiDlyTmp_C;
extern const uint8  PtLim_tOfsCluFanProtHiT_T[PTLIM_TOFSCLUFANPROTHIT_T_COLS];
extern const uint8  PtLim_tOfsCluFanProtLoT_T[PTLIM_TOFSCLUFANPROTLOT_T_COLS];
extern const uint8  PtLim_tOfsCluNRegT_T[PTLIM_TOFSCLUNREGT_T_COLS];
extern const uint8  PtLim_tOfsCluStopWarnT_T[PTLIM_TOFSCLUSTOPWARNT_T_COLS];
extern const uint8  PtLim_tOfsConT_C;
extern const uint8  PtLim_tTCluEstimMemY_A[PTLIM_TTCLUESTIMMEMY_A_COLS];
extern const uint8  PtLim_tThdAcvProtFanHi_C;
extern const uint8  PtLim_tThdAcvProtFanLo_C;
extern const uint8  PtLim_tThdAcvProtNReg_C;
extern const uint8  PtLim_tThdAcvProtStopWarn_C;
extern const uint8  PtLim_tTIniAfterStop_M[PTLIM_TTINIAFTERSTOP_M_LNS][PTLIM_TTINIAFTERSTOP_M_COLS];
extern const uint16  PtLim_arCaseEng_C;
extern const uint16  PtLim_arCaseExtAir_C;
extern const uint16  PtLim_arCaseGear_C;
extern const uint16  PtLim_arCaseItAir_C;
extern const uint16  PtLim_arCluEng_C;
extern const uint16  PtLim_arCluItAir_C;
extern const uint16  PtLim_arCluWhlClu_C;
extern const uint16  PtLim_arEngItAir_C;
extern const uint16  PtLim_arExtAirGear_C;
extern const uint16  PtLim_arGearItAir_C;
extern const uint16  PtLim_arWhlCluItAir_C;
extern const uint16  PtLim_facMassGear_C;
extern const uint16  PtLim_facSpdFanReq_C;
extern const uint16  PtLim_facTCaseEng_C;
extern const uint16  PtLim_facTCaseExtAir_C;
extern const uint16  PtLim_facTCaseExtAir_T[PTLIM_FACTCASEEXTAIR_T_COLS];
extern const uint16  PtLim_facTCaseGear_C;
extern const uint16  PtLim_facTCaseItAir_C;
extern const uint16  PtLim_facTClu_C;
extern const uint16  PtLim_facTCluCase_C;
extern const uint16  PtLim_facTCluEng_C;
extern const uint16  PtLim_facTCluItAir_C;
extern const uint16  PtLim_facTCluWhlClu_C;
extern const uint16  PtLim_facTEngItAir_C;
extern const uint16  PtLim_facTExtAirGear_C;
extern const uint16  PtLim_facTExtAirGear_T[PTLIM_FACTEXTAIRGEAR_T_COLS];
extern const uint16  PtLim_facTGear_C;
extern const uint16  PtLim_facTGearItAir_C;
extern const uint16  PtLim_facTItAir_C;
extern const uint16  PtLim_facTqGearA_M[PTLIM_FACTQGEARA_M_LNS][PTLIM_FACTQGEARA_M_COLS];
extern const uint16  PtLim_facTqGearB_M[PTLIM_FACTQGEARB_M_LNS][PTLIM_FACTQGEARB_M_COLS];
extern const uint16  PtLim_facTWhlClu_C;
extern const uint16  PtLim_facTWhlCluItAir_C;
extern const uint16  PtLim_nEngSpd_A[PTLIM_NENGSPD_A_COLS];
extern const uint16  PtLim_pPAirRef_C;
extern const uint16  PtLim_spdSpdVehFanReq_A[PTLIM_SPDSPDVEHFANREQ_A_COLS];
extern const uint16  PtLim_tGearCluEstimAY_A[PTLIM_TGEARCLUESTIMAY_A_COLS];
extern const uint16  PtLim_tGearCluEstimBY_A[PTLIM_TGEARCLUESTIMBY_A_COLS];
extern const uint16  PtLim_tGearCluEstimCY_A[PTLIM_TGEARCLUESTIMCY_A_COLS];
extern const uint16  PtLim_tiEngStopX_A[PTLIM_TIENGSTOPX_A_COLS];
extern const uint16  PtLim_tiFilEngSpd_C;
extern const uint16  PtLim_tiFilTqClu_C;
extern const uint16  PtLim_tiThdSelIniTClu_C;
extern const uint16  PtLim_tiThermoExgAfterStop_A[PTLIM_TITHERMOEXGAFTERSTOP_A_COLS];
extern const uint16  PtLim_tTGrdFanProtCluHi_A[PTLIM_TTGRDFANPROTCLUHI_A_COLS];
extern const uint16  PtLim_tTGrdFanProtCluLo_A[PTLIM_TTGRDFANPROTCLULO_A_COLS];
extern const uint16  PtLim_tTGrdNRegClu_A[PTLIM_TTGRDNREGCLU_A_COLS];
extern const uint16  PtLim_tTGrdStopWarnClu_A[PTLIM_TTGRDSTOPWARNCLU_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPt_bDgoCluDmgAfts;
extern boolean CoPt_bMonRunCluDmgAfts;
extern boolean CoPt_bWarnProtClu;
extern sint16 CoPt_tManCluEstim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PROTMANCLU_vidEntryInit(void);
void TqSys_Sdl40ms_ProtManClu(void);


#endif /* PROTMANCLU_H */

/*-------------------------------- end of file -------------------------------*/
