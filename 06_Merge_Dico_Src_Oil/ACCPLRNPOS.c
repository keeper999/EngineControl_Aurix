/***************************************************************************
;**
;** FILE NAME      : ACCPLRNPOS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPLRNPOS.H"
#include "ACCPLRNPOS_L.H"
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
const boolean  Dv_app_pos_ped_pas_inst_pc = 0;
const boolean  Dv_app_pos_ped_pas_inst_pl = 0;
const uint8  ACCPLRNPOS_u8Inhib = 0;
const uint8  Dv_1_app_pc_tempo_delay = 0;
const uint8  Dv_1_app_pl_tempo_delay = 0;
const uint8  Dv_1_app_pos_ped_pc_cdef = 0;
const uint8  Dv_1_app_pos_ped_pc_init = 0;
const uint8  Dv_1_app_pos_ped_pc_max = 0;
const uint8  Dv_1_app_pos_ped_pl_cdef = 0;
const uint8  Dv_1_app_pos_ped_pl_init = 0;
const uint8  Dv_1_app_pos_ped_pl_min = 0;
const uint8  Dv_2_app_pc_tempo_delay = 0;
const uint8  Dv_2_app_pl_tempo_delay = 0;
const uint8  Dv_2_app_pos_ped_pc_cdef = 0;
const uint8  Dv_2_app_pos_ped_pc_init = 0;
const uint8  Dv_2_app_pos_ped_pc_max = 0;
const uint8  Dv_2_app_pos_ped_pl_cdef = 0;
const uint8  Dv_2_app_pos_ped_pl_init = 0;
const uint8  Dv_2_app_pos_ped_pl_min = 0;
const uint8  Dv_app_eng_speed_thresh_min_pc = 0;
const uint8  Dv_app_eng_speed_thresh_min_pl = 0;
const uint8  Dv_app_eng_speed_thresh_pc = 0;
const uint8  Dv_app_eng_speed_thresh_pl = 0;
const uint16  Dv_1_app_decrement_pc = 0;
const uint16  Dv_1_app_decrement_pl = 0;
const uint16  Dv_1_app_increment_pc = 0;
const uint16  Dv_1_app_increment_pl = 0;
const uint16  Dv_2_app_decrement_pc = 0;
const uint16  Dv_2_app_decrement_pl = 0;
const uint16  Dv_2_app_increment_pc = 0;
const uint16  Dv_2_app_increment_pl = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACCPLRNPOS_bAutoris_1_app_pl_pc;
boolean ACCPLRNPOS_bAutoris_2_app_pl_pc;
boolean Dv_app_pc_eng_spd_enable;
boolean Dv_app_pl_eng_spd_enable;
boolean Dv_init_1_app_pc_tempo1;
boolean Dv_init_1_app_pc_tempo1_prev;
boolean Dv_init_1_app_pc_tempo2;
boolean Dv_init_1_app_pc_tempo2_prev;
boolean Dv_init_1_app_pl_tempo1;
boolean Dv_init_1_app_pl_tempo1_prev;
boolean Dv_init_1_app_pl_tempo2;
boolean Dv_init_1_app_pl_tempo2_prev;
boolean Dv_init_2_app_pc_tempo1;
boolean Dv_init_2_app_pc_tempo1_prev;
boolean Dv_init_2_app_pc_tempo2;
boolean Dv_init_2_app_pc_tempo2_prev;
boolean Dv_init_2_app_pl_tempo1;
boolean Dv_init_2_app_pl_tempo1_prev;
boolean Dv_init_2_app_pl_tempo2;
boolean Dv_init_2_app_pl_tempo2_prev;
uint8 Dv_1_app_pc_tempo1;
uint8 Dv_1_app_pc_tempo2;
uint8 Dv_1_app_pl_tempo1;
uint8 Dv_1_app_pl_tempo2;
uint8 Dv_2_app_pc_tempo1;
uint8 Dv_2_app_pc_tempo2;
uint8 Dv_2_app_pl_tempo1;
uint8 Dv_2_app_pl_tempo2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

