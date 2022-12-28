/***************************************************************************
;**
;** FILE NAME      : IGEXTHERMOPROT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGEXTHERMOPROT_H
#define IGEXTHERMOPROT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGM_RAIRLDCOR_3_A_COLS                ( 8 )
#define ENGM_RAIRLDCOR_4_A_COLS                ( 16 )
#define IGSYS_MAIRMAX_THERMOPROT_M_LNS        ( 16 )
#define IGSYS_MAIRMAX_THERMOPROT_M_COLS        ( 16 )
#define IGSYS_NENG_IGTHERMOPROT_A_COLS         ( 8 )
#define IGSYS_NENG_IGTHERMOPROT2_A_COLS        ( 16 )
#define IGSYS_RAIRCOR_M_LNS                   ( 16 )
#define IGSYS_RAIRCOR_M_COLS                   ( 16 )
#define IGSYS_RAIRMAX_THERMOPROT_T_COLS        ( 6 )
#define IGSYS_RIGEFC_SP_THERMOPROT_M_COLS      ( 6 )
#define IGSYS_RIGEFC_THERMO_THERMOPROT_M_COLS  ( 6 )
#define IGSYS_RIGEFC_THERMOPROT_T_COLS         ( 6 )
#define TEMPO_APPLI_AGR_CUR_AVANCE_MINI_LNS   ( 8 )
#define TEMPO_APPLI_AGR_CUR_AVANCE_MINI_COLS   ( 8 )
#define TEMPO_APPLI_AGR_PREV_AVANCE_MINI_LNS  ( 8 )
#define TEMPO_APPLI_AGR_PREV_AVANCE_MINI_COLS  ( 8 )
#define TEMPO_APPLI_BV_AVANCE_MINI_LNS        ( 8 )
#define TEMPO_APPLI_BV_AVANCE_MINI_COLS        ( 8 )
#define TEMPO_APPLI_ESP_ASR_AVANCE_MINI_LNS   ( 8 )
#define TEMPO_APPLI_ESP_ASR_AVANCE_MINI_COLS   ( 8 )
#define TEMPO_INH_AGR_CUR_AVANCE_MINI_LNS     ( 8 )
#define TEMPO_INH_AGR_CUR_AVANCE_MINI_COLS     ( 8 )
#define TEMPO_INH_AGR_PREV_AVANCE_MINI_LNS    ( 8 )
#define TEMPO_INH_AGR_PREV_AVANCE_MINI_COLS    ( 8 )
#define TEMPO_INH_BV_AVANCE_MINI_LNS          ( 8 )
#define TEMPO_INH_BV_AVANCE_MINI_COLS          ( 8 )
#define TEMPO_INH_ESP_ASR_AVANCE_MINI_LNS     ( 8 )
#define TEMPO_INH_ESP_ASR_AVANCE_MINI_COLS     ( 8 )

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

extern const boolean  Activation_agr_cur_avance_mini;
extern const boolean  Activation_agr_prev_avance_mini;
extern const boolean  Activation_BV_avance_mini;
extern const boolean  Activation_ESP_ASR_avance_mini;
extern const boolean  IgSys_bAirMin_ThermoProtOfs_C;
extern const boolean  IgSys_bSel_effClc_C;
extern const uint8  IgSys_rAirMax_ThermoProt_T[IGSYS_RAIRMAX_THERMOPROT_T_COLS];
extern const uint8  IgSys_rIgEfc_thermoProt_T[IGSYS_RIGEFC_THERMOPROT_T_COLS];
extern const uint16  EngM_rAirLdCor_3_A[ENGM_RAIRLDCOR_3_A_COLS];
extern const uint16  EngM_rAirLdCor_4_A[ENGM_RAIRLDCOR_4_A_COLS];
extern const uint16  IgSys_mAirMax_ThermoProt_M[IGSYS_MAIRMAX_THERMOPROT_M_LNS][IGSYS_MAIRMAX_THERMOPROT_M_COLS];
extern const uint16  IgSys_mAirMin_ThermoProt_C;
extern const uint16  IgSys_mAirMin_ThermoProtOfs_C;
extern const uint16  IgSys_nEng_IgThermoProt_A[IGSYS_NENG_IGTHERMOPROT_A_COLS];
extern const uint16  IgSys_nEng_IgThermoProt2_A[IGSYS_NENG_IGTHERMOPROT2_A_COLS];
extern const uint16  IgSys_rAirCor_M[IGSYS_RAIRCOR_M_LNS][IGSYS_RAIRCOR_M_COLS];
extern const uint16  IgSys_rDecPuc_mAir_C;
extern const uint16  IgSys_rIgEfc_Sp_thermoProt_M[IGSYS_RIGEFC_SP_THERMOPROT_M_COLS];
extern const uint16  IgSys_rIgEfc_Thermo_thermoProt_M[IGSYS_RIGEFC_THERMO_THERMOPROT_M_COLS];
extern const uint16  Tempo_appli_agr_cur_avance_mini[TEMPO_APPLI_AGR_CUR_AVANCE_MINI_LNS][TEMPO_APPLI_AGR_CUR_AVANCE_MINI_COLS];
extern const uint16  Tempo_appli_agr_prev_avance_mini[TEMPO_APPLI_AGR_PREV_AVANCE_MINI_LNS][TEMPO_APPLI_AGR_PREV_AVANCE_MINI_COLS];
extern const uint16  Tempo_appli_BV_avance_mini[TEMPO_APPLI_BV_AVANCE_MINI_LNS][TEMPO_APPLI_BV_AVANCE_MINI_COLS];
extern const uint16  Tempo_appli_ESP_ASR_avance_mini[TEMPO_APPLI_ESP_ASR_AVANCE_MINI_LNS][TEMPO_APPLI_ESP_ASR_AVANCE_MINI_COLS];
extern const uint16  Tempo_inh_agr_cur_avance_mini[TEMPO_INH_AGR_CUR_AVANCE_MINI_LNS][TEMPO_INH_AGR_CUR_AVANCE_MINI_COLS];
extern const uint16  Tempo_inh_agr_prev_avance_mini[TEMPO_INH_AGR_PREV_AVANCE_MINI_LNS][TEMPO_INH_AGR_PREV_AVANCE_MINI_COLS];
extern const uint16  Tempo_inh_BV_avance_mini[TEMPO_INH_BV_AVANCE_MINI_LNS][TEMPO_INH_BV_AVANCE_MINI_COLS];
extern const uint16  Tempo_inh_ESP_ASR_avance_mini[TEMPO_INH_ESP_ASR_AVANCE_MINI_LNS][TEMPO_INH_ESP_ASR_AVANCE_MINI_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eng_bExThermoProt;
extern boolean Eng_bExThermoProtNotInh;
extern uint8 IgSys_agIgMinThermo2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGEXTHERMOPROT_vidEntryInit(void);
void IgSys_EveBDC_IgExThermoProt(void);
void IgSys_SdlMid_IgExThermoProt(void);


#endif /* IGEXTHERMOPROT_H */

/*-------------------------------- end of file -------------------------------*/
