/***************************************************************************
;**
;** FILE NAME      : BRKPEDBVH2P.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "BRKPEDBVH2P.H"
#include "BRKPEDBVH2P_L.H"
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
const uint8  Brk_aVehDiagAccelCohBVH2_C = 0;
const uint8  Brk_aVehDiagDecelCohBVH2_C = 0;
const uint8  Brk_nDecCpt_AccelCohBVH2p_C = 0;
const uint8  Brk_nDecCpt_DecelCohBVH2p_C = 0;
const uint8  Brk_nDownTranThd_AccelCohBVH2p_C = 0;
const uint8  Brk_nDownTranThd_DecelCohBVH2p_C = 0;
const uint8  Brk_nInitCpt_AccelCohBVH2p_C = 0;
const uint8  Brk_nInitCpt_DecelCohBVH2p_C = 0;
const uint8  Brk_nUpTranThd_AccelCohBVH2p_C = 0;
const uint8  Brk_nUpTranThd_DecelCohBVH2p_C = 0;
const uint8  Brk_spdVehBrkCoh_C = 0;
const uint8  Brk_tiCluPCoh_C = 0;
const uint8  Brk_tiSIPCoh_C = 0;
const uint8  BRKPEDBVH2P_u8Inhib = 0;
const uint16  Brk_noThdDecPedBVH2pAccelCoh_C = 0;
const uint16  Brk_noThdDecPedBVH2pDecelCoh_C = 0;
const uint16  Brk_noThdIncPedBVH2pAccelCoh_C = 0;
const uint16  Brk_noThdIncPedBVH2pDecelCoh_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean BRKPEDBVH2P_bCluPedPrss_Prev;
boolean BRKPEDBVH2P_bFilSig_1;
boolean BRKPEDBVH2P_bFilSig_2;
boolean BRKPEDBVH2P_bRawSigAccel;
boolean BRKPEDBVH2P_bRawSigDecel;
boolean BRKPEDBVH2P_bTraSIP_Prev;
boolean BRKPEDBVH2P_Ext_bDftSftyAccelCoh;
boolean BRKPEDBVH2P_Ext_bDftSftyDecelCoh;
boolean CoPt_bSIPEnd;
boolean Ext_bCluPedPrssEnd;
boolean Ext_bDftSftyAccelCoh_BrkPedBVH2p;
boolean Ext_bDftSftyDecelCoh_BrkPedBVH2p;
boolean Ext_bDgoAccelCoh_BrkPedBVH2p;
boolean Ext_bDgoDecelCoh_BrkPedBVH2p;
boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;
boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;
boolean Ext_bTiCluP;
boolean Ext_bTiSIP;
uint8 BRKPEDBVH2P_u8CntFilt_1;
uint8 BRKPEDBVH2P_u8CntFilt_2;
uint8 Ext_ctSftyAccelCoh_BrkPedBVH2p;
uint8 Ext_ctSftyDecelCoh_BrkPedBVH2p;
uint8 Ext_tiCluP;
uint8 Ext_tiSIP;
uint16 BRKPEDBVH2P_u16AccelCounter;
uint16 BRKPEDBVH2P_u16DecelCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

