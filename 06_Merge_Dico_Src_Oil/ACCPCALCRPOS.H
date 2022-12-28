/***************************************************************************
;**
;** FILE NAME      : ACCPCALCRPOS.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPCALCRPOS_H
#define ACCPCALCRPOS_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CHARGE_PARTIELLE                  2
#define PIED_A_FOND                       0
#define PIED_LEVE                         1

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

extern const boolean  Tr_test_bed_mode_dyn;
extern const boolean  Tr_test_bed_mode_stat;
extern const uint16  Dv_detect_pc_high_thresh;
extern const uint16  Dv_detect_pc_low_thresh;
extern const uint16  Dv_detect_pl_high_thresh;
extern const uint16  Dv_detect_pl_low_thresh;
extern const uint16  Dv_fil_pos_ped_abb_Pas_dec;
extern const uint16  Dv_fil_pos_ped_abb_Pas_inc;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Dv_detection_pied_a_fond;
extern boolean Dv_detection_pied_leve;
extern boolean Dv_detection_pied_leve_final;
extern uint8 AccP_stAccP;
extern uint8 Dv_Etat_Pedale;
extern uint8 Dv_position_pedale_relative;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AccP_EveRst_Clc(void);
void AccP_SdlFast_Clc(void);


#endif /* ACCPCALCRPOS_H */

/*-------------------------------- end of file -------------------------------*/
