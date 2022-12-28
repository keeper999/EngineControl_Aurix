/***************************************************************************
;**
;** FILE NAME      : ENGRUNST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGRUNST_H
#define ENGRUNST_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COPT_NOGEARCORD_SFTY_AX_COLS           ( 8 )
#define ENGST_ENGSPDLIMHITHD_M_LNS            ( 8 )
#define ENGST_ENGSPDLIMHITHD_M_COLS            ( 16 )
#define ENGST_ENGSPDLIMHITHD_T_COLS            ( 8 )
#define ENGST_ENGSPDLIMHITHDPROTMEC_M_LNS     ( 8 )
#define ENGST_ENGSPDLIMHITHDPROTMEC_M_COLS     ( 16 )
#define ENGST_ENGSPDLIMLOTHD_T_COLS            ( 8 )
#define ENGST_ENGSPDLIMTHDHYS_T_COLS           ( 8 )
#define ENGST_NLOFUCUTOFFHYS_T_COLS            ( 8 )
#define ENGST_NOEGDGEARCORD_AX_COLS            ( 8 )
#define ERUN_ENGINE_OVERSPEED_TQLIM       2
#define Ext_stEngIdl_SC                   16
#define Ext_stEngMaxLd_SC                 64
#define Ext_stEngOverRun_SC               8
#define Ext_stEngOverSpd_SC               32
#define Ext_stEngOverSpdTqLim_SC          2
#define Ext_stEngrunNorm_SC               128
#define FULL_LOAD_PEDALE_MAP_COLS              ( 16 )
#define FULL_LOAD_THROTTLE_MAP_COLS            ( 16 )
#define OXC_BINHCUTOFFOVERN_M_COLS             ( 6 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st07 */
#define ERUN_ENGINE_OVERRUN_FCO           8
#define ERUN_ON_IDLE                      16
#define ERUN_ENGINE_OVERSPEED_FCO         32
#define ERUN_FULL_LOAD                    64
#define ERUN_NORMAL_RUNNING               128
/*extern uint8 Engine_running_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  EngSt_bAcvCdnGc_C;
extern const boolean  OxC_bInhCutOffOvern_M[OXC_BINHCUTOFFOVERN_M_COLS];
extern const uint8  CoPt_noGearCord_Sfty_AX[COPT_NOGEARCORD_SFTY_AX_COLS];
extern const uint8  Engs_fl_eng_speed_high_thres;
extern const uint8  Engs_fl_eng_speed_low_thres;
extern const uint8  Engs_full_load_water_temp_thres;
extern const uint8  EngSt_EngSpdLimHiThd_M[ENGST_ENGSPDLIMHITHD_M_LNS][ENGST_ENGSPDLIMHITHD_M_COLS];
extern const uint8  EngSt_EngSpdLimHiThd_T[ENGST_ENGSPDLIMHITHD_T_COLS];
extern const uint8  EngSt_EngSpdLimHiThdProtMec_M[ENGST_ENGSPDLIMHITHDPROTMEC_M_LNS][ENGST_ENGSPDLIMHITHDPROTMEC_M_COLS];
extern const uint8  EngSt_EngSpdLimLoThd_T[ENGST_ENGSPDLIMLOTHD_T_COLS];
extern const uint8  EngSt_EngSpdLimThdHys_T[ENGST_ENGSPDLIMTHDHYS_T_COLS];
extern const uint8  EngSt_noEgdGearCord_AX[ENGST_NOEGDGEARCORD_AX_COLS];
extern const uint8  Full_load_pedale_hysteresis;
extern const uint8  Full_load_pedale_map[FULL_LOAD_PEDALE_MAP_COLS];
extern const uint8  Full_load_throttle_hysteresis;
extern const uint8  Full_load_throttle_map[FULL_LOAD_THROTTLE_MAP_COLS];
extern const uint8  Pl_fco_water_temp;
extern const uint16  Engs_full_load_after_crank_delay;
extern const uint16  Engs_full_load_entry_delay;
extern const uint16  EngSt_ctDlyOverSpdFCO_C;
extern const uint16  EngSt_nLoFuCutOffHys_T[ENGST_NLOFUCUTOFFHYS_T_COLS];
extern const uint16  ESLim_tiMaxOverNEngMax_C;
extern const uint16  Esp_cut_off_allowed_delay;
extern const uint16  Fco_cat_temperature_thresh_high;
extern const uint16  Fco_cat_temperature_thresh_low;
extern const uint16  Pl_fco_start_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Engine_running_state;
extern boolean Conditions_generales_de_coupure;
extern boolean EngSt_bEngNOnIdl;
extern boolean ESLim_bAcvFuCutOff;
extern boolean Manage_isc_closed_loop;
extern uint8 Ext_stEngrun;
extern uint16 Afr_tgt_reinst_time_in_fco_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngSt_EveCrTR_EngrunSt(void);
void EngSt_EveKOn_EngrunSt(void);
void EngSt_EveRst_EngrunSt(void);
void EngSt_SdlFast_EngrunSt(void);


#endif /* ENGRUNST_H */

/*-------------------------------- end of file -------------------------------*/
