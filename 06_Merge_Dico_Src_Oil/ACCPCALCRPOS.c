/***************************************************************************
;**
;** FILE NAME      : ACCPCALCRPOS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPCALCRPOS.H"
#include "ACCPCALCRPOS_L.H"
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
const boolean  Tr_test_bed_mode_dyn = 0;
const boolean  Tr_test_bed_mode_stat = 0;
const uint8  ACCPCALCRPOS_u8Inhib = 0;
const uint16  Dv_detect_pc_high_thresh = 0;
const uint16  Dv_detect_pc_low_thresh = 0;
const uint16  Dv_detect_pl_high_thresh = 0;
const uint16  Dv_detect_pl_low_thresh = 0;
const uint16  Dv_fil_pos_ped_abb_Pas_dec = 0;
const uint16  Dv_fil_pos_ped_abb_Pas_inc = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Dv_detection_pied_a_fond;
boolean Dv_detection_pied_leve;
boolean Dv_detection_pied_leve_final;
uint8 AccP_stAccP;
uint8 Dv_Etat_Pedale;
uint8 Dv_position_pedale_relative;
uint16 ACCPCALCRPOS_u16DvPsPedRlApsPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

