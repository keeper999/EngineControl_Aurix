/***************************************************************************
;**
;** FILE NAME      : DIAGBRKPEDNOBVH2P.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DIAGBRKPEDNOBVH2P.H"
#include "DIAGBRKPEDNOBVH2P_L.H"
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
const uint8  Brk_nDecCpt_AccelCoh_C = 0;
const uint8  Brk_nDecCpt_DecelCoh_C = 0;
const uint8  Brk_nDecCpt_InvCoh_C = 0;
const uint8  Brk_nDownTranThd_AccelCoh_C = 0;
const uint8  Brk_nDownTranThd_DecelCoh_C = 0;
const uint8  Brk_nDownTranThd_InvCoh_C = 0;
const uint8  Brk_nInitCpt_AccelCoh_C = 0;
const uint8  Brk_nInitCpt_DecelCoh_C = 0;
const uint8  Brk_nInitCpt_InvCoh_C = 0;
const uint8  Brk_nUpTranThd_AccelCoh_C = 0;
const uint8  Brk_nUpTranThd_DecelCoh_C = 0;
const uint8  Brk_nUpTranThd_InvCoh_C = 0;
const uint8  DIAGBRKPEDNOBVH2P_u8Inhib = 0;
const uint16  Bps_coh_seuil_accel = 0;
const uint16  Bps_coh_seuil_decel = 0;
const uint16  Brk_noPedNoBVH2pDecAccelCoh_C = 0;
const uint16  Brk_noPedNoBVH2pDecDecelCoh_C = 0;
const uint16  Brk_noPedNoBVH2pDecInvCoh_C = 0;
const uint16  Brk_noPedNoBVH2pIncAccelCoh_C = 0;
const uint16  Brk_noPedNoBVH2pIncDecelCoh_C = 0;
const uint16  Brk_noPedNoBVH2pIncInvCoh_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Bps_diag_state;
boolean DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP;
boolean DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP;
boolean DIAGBRKPEDNOBVH2P_bFilSig_1;
boolean DIAGBRKPEDNOBVH2P_bFilSig_2;
boolean DIAGBRKPEDNOBVH2P_bFilSig_3;
boolean DIAGBRKPEDNOBVH2P_bInvCoh_BrkP;
boolean Ext_bDftSftyAccelCoh_BrkPed;
boolean Ext_bDftSftyDecelCoh_BrkPed;
boolean Ext_bDftSftyInvCoh_BrkPed;
boolean Ext_bDgoAccelCoh_BrkPed;
boolean Ext_bDgoDecelCoh_BrkPed;
boolean Ext_bDgoInvCoh_BrkPed;
boolean Ext_bMonRunAccelCoh_BrkPed;
boolean Ext_bMonRunDecelCoh_BrkPed;
boolean Ext_bMonRunInvCoh_BrkPed;
uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_1;
uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_2;
uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_3;
uint8 Ext_ctDftSftyAccelCoh_BrkPed;
uint8 Ext_ctDftSftyDecelCoh_BrkPed;
uint8 Ext_ctDftSftyInvCoh_BrkPed;
uint16 DIAGBRKPEDNOBVH2P_u16CntFilt0;
uint16 DIAGBRKPEDNOBVH2P_u16CntFilt1;
uint16 DIAGBRKPEDNOBVH2P_u16CntFilt2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

