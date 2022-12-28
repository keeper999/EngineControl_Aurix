/***************************************************************************
;**
;** FILE NAME      : COHCAN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "COHCAN.H"
#include "COHCAN_L.H"
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
const uint8  COHCAN_u8Inhib = 0;
const uint8  Ext_tiACClu_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean COHCAN_bAC_bACClu_prev;
boolean COHCAN_bTimeOut;
boolean COHCAN_bTimerInit_prev;
boolean Ext_bDgoChkBattSys_iBattMes;
boolean Ext_bDgoChkBattSys_tBattMes;
boolean Ext_bDgoChkBattSys_uBattClc;
boolean Ext_bDgoCoh_bModSptReq;
boolean Ext_bDgoCoh_stCluAC;
boolean Ext_bDgoCoh_stPwrAC;
boolean Ext_bDgoCohBit2_stDftOBD;
boolean Ext_bDgoCohBit3_stDftOBD;
boolean Ext_bDgoCohBit4_stDftOBD;
boolean Ext_bDgoCohBit7_stDftOBD;
boolean Ext_bDgoStFuLvlDft;
boolean Ext_bMonRunChkBattSys;
boolean Ext_bMonRunCoh_bModSptReq;
boolean Ext_bMonRunCoh_stCluAC;
boolean Ext_bMonRunCoh_stDftOBD;
boolean Ext_bMonRunStFuLvlDft;
uint8 Ext_tiACClu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

