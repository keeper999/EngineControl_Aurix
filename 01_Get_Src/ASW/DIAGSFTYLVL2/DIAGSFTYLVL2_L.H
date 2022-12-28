/***************************************************************************
;**
;** FILE NAME      : DIAGSFTYLVL2_L.H
;**
;** FILE AUTHOR    : MBENFRADJ (VEES)
;**
;**************************************************************************/

#ifndef DIAGSFTYLVL2_L_H
#define DIAGSFTYLVL2_L_H

#include "STD_TYPES.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  DIAGSFTYLVL2_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean DIAGSFTYLVL2_bDgoNiv2_AccP;
extern boolean DIAGSFTYLVL2_bDgoNiv2_BrkPed;
extern boolean DIAGSFTYLVL2_bDgoNiv2_CluPed;
extern boolean DIAGSFTYLVL2_bDgoNiv2_Coh;
extern boolean DIAGSFTYLVL2_bDgoNiv2_F329;
extern boolean DIAGSFTYLVL2_bDgoNiv2_F349;
extern boolean DIAGSFTYLVL2_bDgoNiv2_F34D;
extern boolean DIAGSFTYLVL2_bDgoNiv2_F38D;
extern boolean DIAGSFTYLVL2_bDgoNiv2_Neut;
extern boolean DIAGSFTYLVL2_bDgoNiv2_Thr;
extern boolean DIAGSFTYLVL2_bDgoNiv2_VehSpd;
extern boolean DIAGSFTYLVL2_bECUWkuMainPrev;
extern boolean DIAGSFTYLVL2_bEngRStrtReqPrev;
extern boolean DIAGSFTYLVL2_bFilSig_AccP;
extern boolean DIAGSFTYLVL2_bFilSig_BrkPed;
extern boolean DIAGSFTYLVL2_bFilSig_CluPed;
extern boolean DIAGSFTYLVL2_bFilSig_Coh;
extern boolean DIAGSFTYLVL2_bFilSig_F329;
extern boolean DIAGSFTYLVL2_bFilSig_F349;
extern boolean DIAGSFTYLVL2_bFilSig_F34D;
extern boolean DIAGSFTYLVL2_bFilSig_F38D;
extern boolean DIAGSFTYLVL2_bFilSig_Neut;
extern boolean DIAGSFTYLVL2_bFilSig_Thr;
extern boolean DIAGSFTYLVL2_bFilSig_VehSpd;
extern boolean DIAGSFTYLVL2_bPosHys;
extern boolean DIAGSFTYLVL2_bPosHys1;
extern boolean DIAGSFTYLVL2_bPosHys2;
extern boolean DIAGSFTYLVL2_bPosHys3;
extern boolean DIAGSFTYLVL2_bSftyBattMesRanPrev;
extern boolean DIAGSFTYLVL2_bTimeOut;
extern boolean DIAGSFTYLVL2_bTimerInputPrev;
extern boolean SftyMgt_bAuthDiagCoh_BrkPed;
extern boolean SftyMgt_bDftCoh_AccP;
extern boolean SftyMgt_bDftCoh_SpdVeh;
extern boolean SftyMgt_bDftCoh_SpdVeh_Prev;
extern boolean SftyMgt_bDftCoh_SpdVehLvl2;
extern boolean SftyMgt_bDftCoh_Thr;
extern boolean SftyMgt_bDftInvCoh_BrkPed;
extern boolean SftyMgt_bDftProcCnt_F329;
extern boolean SftyMgt_bDftProcCnt_F349;
extern boolean SftyMgt_bDftProcCnt_F34D;
extern boolean SftyMgt_bDftProcCnt_F38D;
extern boolean SftyMgt_bDftSc_CluPed;
extern boolean SftyMgt_bDftSc_Neut;
extern boolean SftyMgt_bDftTqCoh_F34D;
extern boolean SftyMgt_bEndtiCohSpdVehLvl2;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 DIAGSFTYLVL2_u8CntFilt_AccP;
extern uint8 DIAGSFTYLVL2_u8CntFilt_BrkPed;
extern uint8 DIAGSFTYLVL2_u8CntFilt_CluPed;
extern uint8 DIAGSFTYLVL2_u8CntFilt_Coh;
extern uint8 DIAGSFTYLVL2_u8CntFilt_F329;
extern uint8 DIAGSFTYLVL2_u8CntFilt_F349;
extern uint8 DIAGSFTYLVL2_u8CntFilt_F34D;
extern uint8 DIAGSFTYLVL2_u8CntFilt_F38D;
extern uint8 DIAGSFTYLVL2_u8CntFilt_Neut;
extern uint8 DIAGSFTYLVL2_u8CntFilt_Thr;
extern uint8 DIAGSFTYLVL2_u8CntFilt_VehSpd;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_AccP;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_BrkPed;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_CluPed;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_Coh;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_F329;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_F349;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_F34D;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_F38D;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_Neut;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_Thr;
extern uint8 DIAGSFTYLVL2_u8CountNiv2_VehSpd;
extern uint8 DIAGSFTYLVL2_u8CountTimer;
extern uint8 DIAGSFTYLVL2_u8EspProcMax_Prev;
extern uint8 DIAGSFTYLVL2_u8F329P230bisPrev;
extern uint8 DIAGSFTYLVL2_u8F349P230Prev;
extern uint8 DIAGSFTYLVL2_u8F34DP157Prev;
extern uint8 DIAGSFTYLVL2_u8F38DP606Prev;
extern uint8 SftyMgt_counterBattMes;
extern uint8 SftyMgt_counterEngStrtReq;
extern uint8 SftyMgt_counterWkuMain;
extern uint8 SftyMgt_tiCohSpdVehLvl2;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 DIAGSFTYLVL2_u16N16F30DP263;
extern uint16 DIAGSFTYLVL2_u16N16F30DP264;
extern uint16 DIAGSFTYLVL2_u16N16F30DP265;
extern uint16 DIAGSFTYLVL2_u16N16F30DP266;
extern uint16 SftyMgt_spdVehMinValLvl2;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 DIAGSFTYLVL2_u32N16F30DP263Mem;
extern uint32 DIAGSFTYLVL2_u32N16F30DP264Mem;
extern uint32 DIAGSFTYLVL2_u32N16F30DP265Mem;
extern uint32 DIAGSFTYLVL2_u32N16F30DP266Mem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void DIAGSFTYLVL2_vidAccPDiag(void);
void DIAGSFTYLVL2_vidAccPDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidAccPSecu(void);
void DIAGSFTYLVL2_vidActDiagCanSftyL2(void);
void DIAGSFTYLVL2_vidActDiagCanSftyNv(void);
void DIAGSFTYLVL2_vidBrkDiag(void);
void DIAGSFTYLVL2_vidBrkDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidBrkSecu(void);
void DIAGSFTYLVL2_vidCalculcounter(void);
void DIAGSFTYLVL2_vidCluDiag(void);
void DIAGSFTYLVL2_vidCluDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidCluSecu(void);
void DIAGSFTYLVL2_vidF329_ProcCnt(void);
void DIAGSFTYLVL2_vidF329Diag(void);
void DIAGSFTYLVL2_vidF329Secu(void);
void DIAGSFTYLVL2_vidF329SftyLevel2(void);
void DIAGSFTYLVL2_vidF349_ProcCnt(void);
void DIAGSFTYLVL2_vidF349Diag(void);
void DIAGSFTYLVL2_vidF349Secu(void);
void DIAGSFTYLVL2_vidF349SftyLevel2(void);
void DIAGSFTYLVL2_vidF34D_ProcCnt(void);
void DIAGSFTYLVL2_vidF34DDiag(void);
void DIAGSFTYLVL2_vidF34DSecu(void);
void DIAGSFTYLVL2_vidF34DSftyLevel2(void);
void DIAGSFTYLVL2_vidF34DTqCoh(void);
void DIAGSFTYLVL2_vidF38D_ProcCnt(void);
void DIAGSFTYLVL2_vidF38DDiag(void);
void DIAGSFTYLVL2_vidF38DSecu(void);
void DIAGSFTYLVL2_vidF38DSftyLevel2(void);
void DIAGSFTYLVL2_vidInit(void);
void DIAGSFTYLVL2_vidInitOutput(void);
void DIAGSFTYLVL2_vidNeutPosDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidNeutPosnDiag(void);
void DIAGSFTYLVL2_vidNeutPosnSecu(void);
void DIAGSFTYLVL2_vidReinitCounter(void);
void DIAGSFTYLVL2_vidReinitCounter1(void);
void DIAGSFTYLVL2_vidReinitCounter2(void);
void DIAGSFTYLVL2_vidReinitCounter3(void);
void DIAGSFTYLVL2_vidSensDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidThrDiag(void);
void DIAGSFTYLVL2_vidThrDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidThrSecu(void);
void DIAGSFTYLVL2_vidVehSpdDiag(void);
void DIAGSFTYLVL2_vidVehSpdDiagSftyLvl2(void);
void DIAGSFTYLVL2_vidVehSpdSecu(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* DIAGSFTYLVL2_L_H */

/*-------------------------------- end of file -------------------------------*/
