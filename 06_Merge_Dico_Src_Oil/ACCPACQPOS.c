/***************************************************************************
;**
;** FILE NAME      : ACCPACQPOS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACCPACQPOS.H"
#include "ACCPACQPOS_L.H"
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
const uint8  AccP1_filter_gain = 0;
const uint8  AccP2_filter_gain = 0;
const uint8  ACCPACQPOS_u8Inhib = 0;
const uint16  AccP_uThdCohSens_C = 0;
const uint16  AccP_uThdScgSens1_C = 0;
const uint16  AccP_uThdScgSens2_C = 0;
const uint16  AccP_uThdScpSens1_C = 0;
const uint16  AccP_uThdScpSens2_C = 0;
const uint16  AccP1_LinPos_Map[ACCP1_LINPOS_MAP_COLS] = {0};
const uint16  AccP1_LinPosBkpt_Map[ACCP1_LINPOSBKPT_MAP_COLS] = {0};
const uint16  AccP2_LinPos_Map[ACCP2_LINPOS_MAP_COLS] = {0};
const uint16  AccP2_LinPosBkpt_Map[ACCP2_LINPOSBKPT_MAP_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ACCPACQPOS_bInitFilter1;
boolean ACCPACQPOS_bInitFilter2;
boolean Ext_bDgoCoh_Ped;
boolean Ext_bDgoDftSenr_AccP;
boolean Ext_bDgoScg_Ped1;
boolean Ext_bDgoScg_Ped2;
boolean Ext_bDgoScpOc_Ped1;
boolean Ext_bDgoScpOc_Ped2;
boolean Ext_bMonRunCoh_Ped;
boolean Ext_bMonRunDftSenr_AccP;
boolean Ext_bMonRunScg_Ped1;
boolean Ext_bMonRunScg_Ped2;
boolean Ext_bMonRunScpOc_Ped1;
boolean Ext_bMonRunScpOc_Ped2;
uint32 ACCPACQPOS_u32FiltrePositionMem1;
uint32 ACCPACQPOS_u32FiltrePositionMem2;
uint16 Aps_1_raw_position;
uint16 Aps_2_raw_position;
uint16 Pos_pedale_1_result_ad_conv;
uint16 Pos_pedale_2_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

