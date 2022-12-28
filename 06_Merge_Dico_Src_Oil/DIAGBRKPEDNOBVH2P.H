/***************************************************************************
;**
;** FILE NAME      : DIAGBRKPEDNOBVH2P.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGBRKPEDNOBVH2P_H
#define DIAGBRKPEDNOBVH2P_H

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

extern const uint8  Brk_nDecCpt_AccelCoh_C;
extern const uint8  Brk_nDecCpt_DecelCoh_C;
extern const uint8  Brk_nDecCpt_InvCoh_C;
extern const uint8  Brk_nDownTranThd_AccelCoh_C;
extern const uint8  Brk_nDownTranThd_DecelCoh_C;
extern const uint8  Brk_nDownTranThd_InvCoh_C;
extern const uint8  Brk_nInitCpt_AccelCoh_C;
extern const uint8  Brk_nInitCpt_DecelCoh_C;
extern const uint8  Brk_nInitCpt_InvCoh_C;
extern const uint8  Brk_nUpTranThd_AccelCoh_C;
extern const uint8  Brk_nUpTranThd_DecelCoh_C;
extern const uint8  Brk_nUpTranThd_InvCoh_C;
extern const uint16  Bps_coh_seuil_accel;
extern const uint16  Bps_coh_seuil_decel;
extern const uint16  Brk_noPedNoBVH2pDecAccelCoh_C;
extern const uint16  Brk_noPedNoBVH2pDecDecelCoh_C;
extern const uint16  Brk_noPedNoBVH2pDecInvCoh_C;
extern const uint16  Brk_noPedNoBVH2pIncAccelCoh_C;
extern const uint16  Brk_noPedNoBVH2pIncDecelCoh_C;
extern const uint16  Brk_noPedNoBVH2pIncInvCoh_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDftSftyAccelCoh_BrkPed;
extern boolean Ext_bDftSftyDecelCoh_BrkPed;
extern boolean Ext_bDftSftyInvCoh_BrkPed;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Brk_EveRst_DiagBrkPedNoBVH2p(void);
void Brk_SdlMid_DiagBrkPedNoBVH2p(void);
void Brk_SdlSfty_BrkPed(void);


#endif /* DIAGBRKPEDNOBVH2P_H */

/*-------------------------------- end of file -------------------------------*/
