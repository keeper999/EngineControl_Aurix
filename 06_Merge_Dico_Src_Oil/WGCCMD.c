/***************************************************************************
;**
;** FILE NAME      : WGCCMD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "WGCCMD.H"
#include "WGCCMD_L.H"
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
const boolean  Ext_bAcv_Trb_rCtlBattCor_C = 0;
const boolean  Ext_bAcv_Trb_rCtlCurCor_C = 0;
const uint8  WgcCmd_u8Inhib = 0;
const uint16  Ext_resLoSideTrb_C = 0;
const uint16  WgcCmd_frqTrbAct_rCtl_T[WGCCMD_FRQTRBACT_RCTL_T_COLS] = {0};
const uint16  WgcCmd_nEng_A[WGCCMD_NENG_A_COLS] = {0};
const uint16  WgcCmd_TrbAct_DrvMax_C = 0;
const uint16  WgcCmd_TrbAct_DrvMin_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Wg_bDgoHi_WgcCmd;
boolean Wg_bDgoLo_WgcCmd;
boolean Wg_bMonRunHi_WgcCmd;
boolean Wg_bMonRunLo_WgcCmd;
uint8 Ext_uBattMes_Filt;
sint16 Ext_TrbAct_rCtlCor;
sint16 WGCCMD_s16Ext_uBattMesPrev;
uint16 Ext_TrbAct_rCtl;
uint16 Ext_TrbAct_rCtlLim;
uint16 Ext_uTrbAct;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

