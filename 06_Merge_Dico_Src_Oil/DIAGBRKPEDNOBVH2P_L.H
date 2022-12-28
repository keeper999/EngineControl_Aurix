/***************************************************************************
;**
;** FILE NAME      : DIAGBRKPEDNOBVH2P_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGBRKPEDNOBVH2P_L_H
#define DIAGBRKPEDNOBVH2P_L_H

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

/* enum st05 */
#define BPS_DIAG_INIT                     1
#define BPS_DIAG_INVAL                    2
#define BPS_DIAG_ACCEL                    4
#define BPS_DIAG_DECEL                    8
/*extern uint8 Bps_diag_state;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  DIAGBRKPEDNOBVH2P_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Bps_diag_state;
extern boolean DIAGBRKPEDNOBVH2P_bAccelCoh_BrkP;
extern boolean DIAGBRKPEDNOBVH2P_bDecelCoh_BrkP;
extern boolean DIAGBRKPEDNOBVH2P_bFilSig_1;
extern boolean DIAGBRKPEDNOBVH2P_bFilSig_2;
extern boolean DIAGBRKPEDNOBVH2P_bFilSig_3;
extern boolean DIAGBRKPEDNOBVH2P_bInvCoh_BrkP;
extern boolean Ext_bDgoAccelCoh_BrkPed;
extern boolean Ext_bDgoDecelCoh_BrkPed;
extern boolean Ext_bDgoInvCoh_BrkPed;
extern boolean Ext_bMonRunAccelCoh_BrkPed;
extern boolean Ext_bMonRunDecelCoh_BrkPed;
extern boolean Ext_bMonRunInvCoh_BrkPed;
extern uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_1;
extern uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_2;
extern uint8 DIAGBRKPEDNOBVH2P_u8CntFilt_3;
extern uint8 Ext_ctDftSftyAccelCoh_BrkPed;
extern uint8 Ext_ctDftSftyDecelCoh_BrkPed;
extern uint8 Ext_ctDftSftyInvCoh_BrkPed;
extern uint16 DIAGBRKPEDNOBVH2P_u16CntFilt0;
extern uint16 DIAGBRKPEDNOBVH2P_u16CntFilt1;
extern uint16 DIAGBRKPEDNOBVH2P_u16CntFilt2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DIAGBRKPEDNOBVH2P_vidDiagBrkPMng(void);
void DIAGBRKPEDNOBVH2P_vidDiagManager(void);
void DIAGBRKPEDNOBVH2P_vidFnctionCall(void);
void DIAGBRKPEDNOBVH2P_vidInitOutput(void);
void DIAGBRKPEDNOBVH2P_vidSftyNiv2(void);


#endif /* DIAGBRKPEDNOBVH2P_L_H */

/*-------------------------------- end of file -------------------------------*/
