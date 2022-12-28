/***************************************************************************
;**
;** FILE NAME      : ACCPLRNPOS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPLRNPOS_H
#define ACCPLRNPOS_H

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

extern const boolean  Dv_app_pos_ped_pas_inst_pc;
extern const boolean  Dv_app_pos_ped_pas_inst_pl;
extern const uint8  Dv_1_app_pc_tempo_delay;
extern const uint8  Dv_1_app_pl_tempo_delay;
extern const uint8  Dv_1_app_pos_ped_pc_cdef;
extern const uint8  Dv_1_app_pos_ped_pc_init;
extern const uint8  Dv_1_app_pos_ped_pc_max;
extern const uint8  Dv_1_app_pos_ped_pl_cdef;
extern const uint8  Dv_1_app_pos_ped_pl_init;
extern const uint8  Dv_1_app_pos_ped_pl_min;
extern const uint8  Dv_2_app_pc_tempo_delay;
extern const uint8  Dv_2_app_pl_tempo_delay;
extern const uint8  Dv_2_app_pos_ped_pc_cdef;
extern const uint8  Dv_2_app_pos_ped_pc_init;
extern const uint8  Dv_2_app_pos_ped_pc_max;
extern const uint8  Dv_2_app_pos_ped_pl_cdef;
extern const uint8  Dv_2_app_pos_ped_pl_init;
extern const uint8  Dv_2_app_pos_ped_pl_min;
extern const uint8  Dv_app_eng_speed_thresh_min_pc;
extern const uint8  Dv_app_eng_speed_thresh_min_pl;
extern const uint8  Dv_app_eng_speed_thresh_pc;
extern const uint8  Dv_app_eng_speed_thresh_pl;
extern const uint16  Dv_1_app_decrement_pc;
extern const uint16  Dv_1_app_decrement_pl;
extern const uint16  Dv_1_app_increment_pc;
extern const uint16  Dv_1_app_increment_pl;
extern const uint16  Dv_2_app_decrement_pc;
extern const uint16  Dv_2_app_decrement_pl;
extern const uint16  Dv_2_app_increment_pc;
extern const uint16  Dv_2_app_increment_pl;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveRst_FLrng(void);
void AccP_EveRstPed_FLrng(void);
void AccP_SdlSlow_FLrng(void);


#endif /* ACCPLRNPOS_H */

/*-------------------------------- end of file -------------------------------*/
