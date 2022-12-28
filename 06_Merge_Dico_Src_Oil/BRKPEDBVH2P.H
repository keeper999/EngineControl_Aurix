/***************************************************************************
;**
;** FILE NAME      : BRKPEDBVH2P.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKPEDBVH2P_H
#define BRKPEDBVH2P_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Brk_SampleTiMid_SC                10

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

extern const uint8  Brk_aVehDiagAccelCohBVH2_C;
extern const uint8  Brk_aVehDiagDecelCohBVH2_C;
extern const uint8  Brk_nDecCpt_AccelCohBVH2p_C;
extern const uint8  Brk_nDecCpt_DecelCohBVH2p_C;
extern const uint8  Brk_nDownTranThd_AccelCohBVH2p_C;
extern const uint8  Brk_nDownTranThd_DecelCohBVH2p_C;
extern const uint8  Brk_nInitCpt_AccelCohBVH2p_C;
extern const uint8  Brk_nInitCpt_DecelCohBVH2p_C;
extern const uint8  Brk_nUpTranThd_AccelCohBVH2p_C;
extern const uint8  Brk_nUpTranThd_DecelCohBVH2p_C;
extern const uint8  Brk_spdVehBrkCoh_C;
extern const uint8  Brk_tiCluPCoh_C;
extern const uint8  Brk_tiSIPCoh_C;
extern const uint16  Brk_noThdDecPedBVH2pAccelCoh_C;
extern const uint16  Brk_noThdDecPedBVH2pDecelCoh_C;
extern const uint16  Brk_noThdIncPedBVH2pAccelCoh_C;
extern const uint16  Brk_noThdIncPedBVH2pDecelCoh_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDftSftyAccelCoh_BrkPedBVH2p;
extern boolean Ext_bDftSftyDecelCoh_BrkPedBVH2p;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Brk_SdlMid_BrkPedBVH2p(void);
void Brk_SdlSfty_BrkPedBVH2p(void);
void BRKPEDBVH2P_vidEntryInit(void);


#endif /* BRKPEDBVH2P_H */

/*-------------------------------- end of file -------------------------------*/
