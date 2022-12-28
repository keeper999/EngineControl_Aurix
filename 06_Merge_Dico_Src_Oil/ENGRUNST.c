/***************************************************************************
;**
;** FILE NAME      : ENGRUNST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGRUNST.H"
#include "ENGRUNST_L.H"
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
const boolean  EngSt_bAcvCdnGc_C = 0;
const boolean  OxC_bInhCutOffOvern_M[OXC_BINHCUTOFFOVERN_M_COLS] = {0};
const uint8  CoPt_noGearCord_Sfty_AX[COPT_NOGEARCORD_SFTY_AX_COLS] = {0};
const uint8  ENGRUNST_u8Inhib = 0;
const uint8  Engs_fl_eng_speed_high_thres = 0;
const uint8  Engs_fl_eng_speed_low_thres = 0;
const uint8  Engs_full_load_water_temp_thres = 0;
const uint8  EngSt_EngSpdLimHiThd_M[ENGST_ENGSPDLIMHITHD_M_LNS][ENGST_ENGSPDLIMHITHD_M_COLS] = {0};
const uint8  EngSt_EngSpdLimHiThd_T[ENGST_ENGSPDLIMHITHD_T_COLS] = {0};
const uint8  EngSt_EngSpdLimHiThdProtMec_M[ENGST_ENGSPDLIMHITHDPROTMEC_M_LNS][ENGST_ENGSPDLIMHITHDPROTMEC_M_COLS] = {0};
const uint8  EngSt_EngSpdLimLoThd_T[ENGST_ENGSPDLIMLOTHD_T_COLS] = {0};
const uint8  EngSt_EngSpdLimThdHys_T[ENGST_ENGSPDLIMTHDHYS_T_COLS] = {0};
const uint8  EngSt_noEgdGearCord_AX[ENGST_NOEGDGEARCORD_AX_COLS] = {0};
const uint8  Full_load_pedale_hysteresis = 0;
const uint8  Full_load_pedale_map[FULL_LOAD_PEDALE_MAP_COLS] = {0};
const uint8  Full_load_throttle_hysteresis = 0;
const uint8  Full_load_throttle_map[FULL_LOAD_THROTTLE_MAP_COLS] = {0};
const uint8  Pl_fco_water_temp = 0;
const uint16  Engs_full_load_after_crank_delay = 0;
const uint16  Engs_full_load_entry_delay = 0;
const uint16  EngSt_ctDlyOverSpdFCO_C = 0;
const uint16  EngSt_nLoFuCutOffHys_T[ENGST_NLOFUCUTOFFHYS_T_COLS] = {0};
const uint16  ESLim_tiMaxOverNEngMax_C = 0;
const uint16  Esp_cut_off_allowed_delay = 0;
const uint16  Fco_cat_temperature_thresh_high = 0;
const uint16  Fco_cat_temperature_thresh_low = 0;
const uint16  Pl_fco_start_delay = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Engine_running_state;
boolean Conditions_generales_de_coupure;
boolean ENGRUNST_Srv_bByCnOvrNEngMx_prev;
boolean Engs_full_load_entry_delay_cond;
boolean Engs_full_load_entry_with_delay;
boolean EngSt_bDgoRedESLim;
boolean EngSt_bEngNOnIdl;
boolean EngSt_bEntryOVERSPEED_FCO;
boolean EngSt_bMonRunRedESLim;
boolean ESLim_bAcvFuCutOff;
boolean ESLim_bAcvRedESLimProtMec;
boolean ESLim_bAcvRedESLimProtMecKOn;
boolean Fco_main_conditions_ok;
boolean Fco_temp_cata_ok;
boolean Manage_isc_closed_loop;
uint8 EngSt_EngSpdLimThd;
uint8 Ext_stEngrun;
uint8 Full_load_pedale;
uint8 Full_load_throttle;
uint16 Afr_tgt_reinst_time_in_fco_count;
uint16 Engs_full_load_after_crank_count;
uint16 Engs_full_load_entry_count;
uint16 EngSt_ctOverSpdFCO;
uint16 ESLim_tiCntOverNEngMaxTmp;
uint16 Esp_cut_off_allowed_count;
uint16 Pl_fco_entry_delay_timeout;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

