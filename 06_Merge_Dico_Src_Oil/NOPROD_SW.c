/***************************************************************************
;**
;** FILE NAME      : NOPROD_SW.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "NOPROD_SW.H"
#include "NOPROD_SW_L.H"
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
const uint8  Dtc_STT_crank_delay_map[DTC_STT_CRANK_DELAY_MAP_COLS] = {0};
const uint8  NOPROD_u8Inhib = 0;
const uint8  Sfty_maskCfgDiag_C = 0;
const uint8  Srv_IdChrnInjr_C = 0;
const uint16  Regime_moteur_bkpt_map[REGIME_MOTEUR_BKPT_MAP_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Srv_stInjrChrnEcuStatus;
boolean Immo_bLockECUCAN;
uint32 DEBUG_u32Data01;
uint32 DEBUG_u32Data02;
uint32 DEBUG_u32Data03;
uint32 DEBUG_u32Data04;
uint32 DEBUG_u32Data05;
uint32 Tpc_free_wheeling_delay_temp;
uint8 Immo_bfImmoReadStDft;
uint8 Immo_stCANMatchOptReadSt;
uint8 Immo_stProgImmoReadSt;
uint8 Srv_prm_IdChrnInjr[SRV_PRM_IDCHRNINJR_COLS];
sint32 DEBUG_s32Data11;
sint32 DEBUG_s32Data12;
sint32 DEBUG_s32Data13;
sint32 DEBUG_s32Data14;
sint32 DEBUG_s32Data15;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

