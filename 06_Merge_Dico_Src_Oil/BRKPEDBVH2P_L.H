/***************************************************************************
;**
;** FILE NAME      : BRKPEDBVH2P_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKPEDBVH2P_L_H
#define BRKPEDBVH2P_L_H

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

extern const uint8  BRKPEDBVH2P_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BRKPEDBVH2P_bCluPedPrss_Prev;
extern boolean BRKPEDBVH2P_bFilSig_1;
extern boolean BRKPEDBVH2P_bFilSig_2;
extern boolean BRKPEDBVH2P_bRawSigAccel;
extern boolean BRKPEDBVH2P_bRawSigDecel;
extern boolean BRKPEDBVH2P_bTraSIP_Prev;
extern boolean BRKPEDBVH2P_Ext_bDftSftyAccelCoh;
extern boolean BRKPEDBVH2P_Ext_bDftSftyDecelCoh;
extern boolean CoPt_bSIPEnd;
extern boolean Ext_bCluPedPrssEnd;
extern boolean Ext_bDgoAccelCoh_BrkPedBVH2p;
extern boolean Ext_bDgoDecelCoh_BrkPedBVH2p;
extern boolean Ext_bMonRunAccelCoh_BrkPedBVH2p;
extern boolean Ext_bMonRunDecelCoh_BrkPedBVH2p;
extern boolean Ext_bTiCluP;
extern boolean Ext_bTiSIP;
extern uint8 BRKPEDBVH2P_u8CntFilt_1;
extern uint8 BRKPEDBVH2P_u8CntFilt_2;
extern uint8 Ext_ctSftyAccelCoh_BrkPedBVH2p;
extern uint8 Ext_ctSftyDecelCoh_BrkPedBVH2p;
extern uint8 Ext_tiCluP;
extern uint8 Ext_tiSIP;
extern uint16 BRKPEDBVH2P_u16AccelCounter;
extern uint16 BRKPEDBVH2P_u16DecelCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BRKPEDBVH2P_vidClutchPedalEdge(void);
void BRKPEDBVH2P_vidCounter(void);
void BRKPEDBVH2P_vidDiagnostic(void);
void BRKPEDBVH2P_vidDiagnostic_niv2(void);
void BRKPEDBVH2P_vidEventGeneration(void);
void BRKPEDBVH2P_vidGearRatioChgEdge(void);
void BRKPEDBVH2P_vidInitOutput(void);


#endif /* BRKPEDBVH2P_L_H */

/*-------------------------------- end of file -------------------------------*/
