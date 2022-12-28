/***************************************************************************
;**
;** FILE NAME      : IGEXTHERMOPROT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGEXTHERMOPROT.H"
#include "IGEXTHERMOPROT_L.H"
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
const boolean  Activation_agr_cur_avance_mini = 0;
const boolean  Activation_agr_prev_avance_mini = 0;
const boolean  Activation_BV_avance_mini = 0;
const boolean  Activation_ESP_ASR_avance_mini = 0;
const boolean  IgSys_bAirMin_ThermoProtOfs_C = 0;
const boolean  IgSys_bSel_effClc_C = 0;
const uint8  IGEXTHERMOPROT_u8Inhib = 0;
const uint8  IgSys_rAirMax_ThermoProt_T[IGSYS_RAIRMAX_THERMOPROT_T_COLS] = {0};
const uint8  IgSys_rIgEfc_thermoProt_T[IGSYS_RIGEFC_THERMOPROT_T_COLS] = {0};
const uint16  EngM_rAirLdCor_3_A[ENGM_RAIRLDCOR_3_A_COLS] = {0};
const uint16  EngM_rAirLdCor_4_A[ENGM_RAIRLDCOR_4_A_COLS] = {0};
const uint16  IgSys_mAirMax_ThermoProt_M[IGSYS_MAIRMAX_THERMOPROT_M_LNS][IGSYS_MAIRMAX_THERMOPROT_M_COLS] = {0};
const uint16  IgSys_mAirMin_ThermoProt_C = 0;
const uint16  IgSys_mAirMin_ThermoProtOfs_C = 0;
const uint16  IgSys_nEng_IgThermoProt_A[IGSYS_NENG_IGTHERMOPROT_A_COLS] = {0};
const uint16  IgSys_nEng_IgThermoProt2_A[IGSYS_NENG_IGTHERMOPROT2_A_COLS] = {0};
const uint16  IgSys_rAirCor_M[IGSYS_RAIRCOR_M_LNS][IGSYS_RAIRCOR_M_COLS] = {0};
const uint16  IgSys_rDecPuc_mAir_C = 0;
const uint16  IgSys_rIgEfc_Sp_thermoProt_M[IGSYS_RIGEFC_SP_THERMOPROT_M_COLS] = {0};
const uint16  IgSys_rIgEfc_Thermo_thermoProt_M[IGSYS_RIGEFC_THERMO_THERMOPROT_M_COLS] = {0};
const uint16  Tempo_appli_agr_cur_avance_mini[TEMPO_APPLI_AGR_CUR_AVANCE_MINI_LNS][TEMPO_APPLI_AGR_CUR_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_appli_agr_prev_avance_mini[TEMPO_APPLI_AGR_PREV_AVANCE_MINI_LNS][TEMPO_APPLI_AGR_PREV_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_appli_BV_avance_mini[TEMPO_APPLI_BV_AVANCE_MINI_LNS][TEMPO_APPLI_BV_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_appli_ESP_ASR_avance_mini[TEMPO_APPLI_ESP_ASR_AVANCE_MINI_LNS][TEMPO_APPLI_ESP_ASR_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_inh_agr_cur_avance_mini[TEMPO_INH_AGR_CUR_AVANCE_MINI_LNS][TEMPO_INH_AGR_CUR_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_inh_agr_prev_avance_mini[TEMPO_INH_AGR_PREV_AVANCE_MINI_LNS][TEMPO_INH_AGR_PREV_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_inh_BV_avance_mini[TEMPO_INH_BV_AVANCE_MINI_LNS][TEMPO_INH_BV_AVANCE_MINI_COLS] = {0};
const uint16  Tempo_inh_ESP_ASR_avance_mini[TEMPO_INH_ESP_ASR_AVANCE_MINI_LNS][TEMPO_INH_ESP_ASR_AVANCE_MINI_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 IgSys_stThermoProt;
boolean Eng_bExThermoProt;
boolean Eng_bExThermoProtNotInh;
boolean IGEXTHERMOPROT_bCond1;
boolean IGEXTHERMOPROT_bCond2;
boolean IGEXTHERMOPROT_bCond3;
boolean IGEXTHERMOPROT_bCond4;
boolean IGEXTHERMOPROT_bInitTmrPrev1;
boolean IGEXTHERMOPROT_bInitTmrPrev2;
boolean IGEXTHERMOPROT_bInitTmrPrev3;
boolean IGEXTHERMOPROT_bInitTmrPrev4;
boolean IGEXTHERMOPROT_bInitTmrPrev5;
boolean IGEXTHERMOPROT_bInitTmrPrev6;
boolean IGEXTHERMOPROT_bInitTmrPrev7;
boolean IGEXTHERMOPROT_bInitTmrPrev8;
boolean IGEXTHERMOPROT_bTimer1Init;
boolean IGEXTHERMOPROT_bTimer1InitPrev;
boolean IGEXTHERMOPROT_bTimerOut1;
boolean IGEXTHERMOPROT_bTimerOut2;
boolean IGEXTHERMOPROT_bTimerOut3;
boolean IGEXTHERMOPROT_bTimerOut4;
boolean Inhibition_appli_avance_min_spc[INHIBITION_APPLI_AVANCE_MIN_SPC_LNS];
uint8 IgSys_agIgDifOptmSp;
uint8 IgSys_agIgDifOptmThermo;
uint8 IgSys_agIgMinThermo2;
uint8 IgSys_SampleTiMid_PhysVal;
uint16 EngM_mfAirCor_temp;
uint16 IGEXTHERMOPROT_u16TmrDelay1;
uint16 IGEXTHERMOPROT_u16TmrDelay2;
uint16 IGEXTHERMOPROT_u16TmrDelay3;
uint16 IGEXTHERMOPROT_u16TmrDelay4;
uint16 IGEXTHERMOPROT_u16TmrDelay5;
uint16 IGEXTHERMOPROT_u16TmrDelay6;
uint16 IGEXTHERMOPROT_u16TmrDelay7;
uint16 IGEXTHERMOPROT_u16TmrDelay8;
uint16 IgSys_mAirInt_thermoProt;
uint16 IgSys_mAirMax_ThermoProt;
uint16 IgSys_mAirMin_ThermoProt;
uint16 IgSys_rDynIgSpEfc_ThP;
uint16 IgSys_rMinThermoIgEfc_ThP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

