/***************************************************************************
;**
;** FILE NAME      : SYNCENGCLC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCENGCLC_L_H
#define SYNCENGCLC_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SYNC_PRM_BNENGINSDAR_COLS              ( 20 )
#define SYNC_PRM_NCORCONTNSCYL1_COLS           ( 20 )
#define SYNC_PRM_NCORCONTNSCYL2_COLS           ( 20 )
#define SYNC_PRM_NCORCONTNSCYL3_COLS           ( 20 )
#define SYNC_PRM_NTHDNENGCLC_COLS              ( 21 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st95 */
#define INIT_ENG_SPEED_IN_AREA            0
#define ENG_SPEED_IN_AREA                 2
/*extern uint8 SYNCENGCLC_StAssignEngArea;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  SYNCENGCLC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 SYNCENGCLC_StAssignEngArea;
extern boolean Sync_bAckdMvCyl1ArAcv;
extern boolean Sync_bAckdMvCyl2ArAcv;
extern boolean Sync_bAckdMvCyl3ArAcv;
extern boolean Sync_bChgnoArAcvnEngClc;
extern boolean Sync_bCondLrnCornEngClc;
extern boolean Sync_bEndMemrnCycEng;
extern boolean Sync_bIdlSpdInsdArAcv;
extern boolean Sync_bLrnCorArAcv;
extern boolean Sync_bnEngInsdAr;
extern boolean Sync_bProtClcSum;
extern boolean SYNCENGCLC_bHysOut;
extern boolean SYNCENGCLC_bTimeOut;
extern boolean SYNCENGCLC_bTimeOutInit;
extern uint32 Sync_ct_SampleCyl1ArAcv;
extern uint32 Sync_ct_SampleCyl2ArAcv;
extern uint32 Sync_ct_SampleCyl3ArAcv;
extern uint32 Sync_nSumCyl1ArAcv;
extern uint32 Sync_nSumCyl1ArAcvPrev;
extern uint32 Sync_nSumCyl2ArAcv;
extern uint32 Sync_nSumCyl2ArAcvPrev;
extern uint32 Sync_nSumCyl3ArAcv;
extern uint32 Sync_nSumCyl3ArAcvPrev;
extern sint8 Sync_CorCyl1ArAcv;
extern sint8 Sync_CorCyl2ArAcv;
extern sint8 Sync_CorCyl3ArAcv;
extern sint8 Sync_nCorContnsCyl1;
extern sint8 Sync_nCorContnsCyl2;
extern sint8 Sync_nCorContnsCyl3;
extern sint8 Sync_nCorContnsCylCmb;
extern sint8 Sync_prm_nCorContnsCyl1[SYNC_PRM_NCORCONTNSCYL1_COLS];
extern sint8 Sync_prm_nCorContnsCyl2[SYNC_PRM_NCORCONTNSCYL2_COLS];
extern sint8 Sync_prm_nCorContnsCyl3[SYNC_PRM_NCORCONTNSCYL3_COLS];
extern uint8 Sync_ct_MemrnEngCyl;
extern uint8 Sync_ctTiCutOff;
extern uint8 Sync_no_ArAcvnEngClc;
extern uint8 Sync_no_BodyCorSatEngClc;
extern uint8 Sync_no_MemrArAcvnEngClc;
extern uint8 Sync_no_PrevMemrArAcvnEngClc;
extern uint8 Sync_prm_bnEngInsdAr[SYNC_PRM_BNENGINSDAR_COLS];
extern uint8 SYNCENGCLC_u8NoArAcvnEngClc;
extern uint8 SYNCENGCLC_u8NumberActiveZonPrev;
extern uint16 Sync_nCycEngMemrCyl1;
extern uint16 Sync_nCycEngMemrCyl2;
extern uint16 Sync_nCycEngMemrCyl3;
extern uint16 Sync_nMemrCyl1;
extern uint16 Sync_nMemrCyl2;
extern uint16 Sync_nMemrCyl3;
extern uint16 Sync_nMvAllCylArAcv;
extern uint16 Sync_nMvCyl1ArAcv;
extern uint16 Sync_nMvCyl2ArAcv;
extern uint16 Sync_nMvCyl3ArAcv;
extern uint16 Sync_prm_nThdnEngClc[SYNC_PRM_NTHDNENGCLC_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCENGCLC_vidActLearningCorr(void);
void SYNCENGCLC_vidApplication(void);
void SYNCENGCLC_vidApplicationCorr(void);
void SYNCENGCLC_vidAppliCor(void);
void SYNCENGCLC_vidAssigEngSpdArea(void);
void SYNCENGCLC_vidCalculAreaEngClc(void);
void SYNCENGCLC_vidCalculCorrection(void);
void SYNCENGCLC_vidCalculCorrEngClc(void);
void SYNCENGCLC_vidCalculMean(void);
void SYNCENGCLC_vidContinuityRules(void);
void SYNCENGCLC_vidCorrectAssignment(void);
void SYNCENGCLC_vidCorrectionArea(void);
void SYNCENGCLC_vidEchtSumCyl_1_Areas(void);
void SYNCENGCLC_vidEchtSumCyl_2_Areas(void);
void SYNCENGCLC_vidEchtSumCyl_3_Areas(void);
void SYNCENGCLC_vidEchtSumCylAllAreas(void);
void SYNCENGCLC_vidEcritureAdapt(void);
void SYNCENGCLC_vidEngineSpeedMemr(void);
void SYNCENGCLC_vidEngSpdInsideArea(void);
void SYNCENGCLC_vidEngSpdMemrCylMot(void);
void SYNCENGCLC_vidInitOutput(void);
void SYNCENGCLC_vidMngIdlSpdInsidArea(void);
void SYNCENGCLC_vidProtectCalcSomme(void);
void SYNCENGCLC_vidResetnEngClc(void);
void SYNCENGCLC_vidSelectCorrection(void);


#endif /* SYNCENGCLC_L_H */

/*-------------------------------- end of file -------------------------------*/
