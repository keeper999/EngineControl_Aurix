/***************************************************************************
;**
;** FILE NAME      : PREDES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PREDES_L_H
#define PREDES_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define PREDES_PRM_IDXBUFTIWR_MP_COLS          ( 3 )
#define PREDES_PRM_NBUF_COLS                   ( 255 )
#define PREDES_SQRT_BKPT_COLS                  ( 9 )
#define PREDES_SQRT_TABLE_COLS                 ( 9 )

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

extern const uint8  PREDES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean PredEs_bAcvClcPredCurN;
extern boolean PredEs_bAcvClcPredNHi;
extern boolean PredEs_bAcvClcPredNLo;
extern boolean PredEs_bAcvRecBuf;
extern boolean PredEs_bAcvRecBuf0_MP;
extern boolean PREDES_bAcvRecBufPrev;
extern boolean PredEs_bClcPredCurN;
extern boolean PredEs_bClcPredEs;
extern boolean PredEs_bClcPredN;
extern boolean PredEs_bClcPredNHi;
extern boolean PredEs_bClcPredNIntl;
extern boolean PredEs_bCndStop;
extern boolean PredEs_bDetChgDir;
extern boolean PredEs_bDetSlowNPredRaw;
extern boolean PredEs_bDirRotCk;
extern boolean PREDES_bDirRotCkPrev;
extern boolean PredEs_bEngSyncAccu;
extern boolean PREDES_bFallEdgStrtTmrRst2Prev;
extern boolean PredEs_bFirstClcPredEs;
extern boolean PREDES_bFirstClcPredEsPrev;
extern boolean PREDES_bFlipFlopNotOut1;
extern boolean PREDES_bFlipFlopOut2;
extern boolean PREDES_bFlipFlopOut2Prev;
extern boolean PREDES_bFlipFlopOut3;
extern boolean PREDES_bFlipFlopOut5;
extern boolean PREDES_bInfoCplStPrev;
extern boolean PredEs_bNotCgtLstFct;
extern boolean PredEs_bOkCndIntl;
extern boolean PredEs_bOkN2EgdChgDir;
extern boolean PREDES_bOkN2EgdPrev;
extern boolean PredEs_bOkOscN;
extern boolean PredEs_bOkOscNRaw;
extern boolean PREDES_bOkOscNRawPrev;
extern boolean PREDES_bOkOscPrev;
extern boolean PREDES_bRisingEdgeInPrev1;
extern boolean PREDES_bRisingEdgeInPrev2;
extern boolean PREDES_bRisingEdgeInPrev3;
extern boolean PredEs_bSecPhaPred;
extern boolean PredEs_bSecPhaSecu;
extern boolean PREDES_bStrtTmrRst1Prev;
extern boolean PREDES_bStrtTmrRst2Prev;
extern boolean PREDES_bTmr1Out;
extern boolean PREDES_bTmr1OutPrev;
extern boolean PREDES_bTmrOut;
extern boolean PREDES_bTmrOutPrev;
extern boolean PREDES_bTmrRstOut2;
extern boolean PredEs_bTrigIni;
extern boolean PredEs_bTypCgt;
extern boolean PredEs_bTypCgt180First;
extern boolean PredEs_bVldCurNCll;
extern boolean PredEs_bVldCurNCll_MP;
extern boolean PredEs_bVldCurNCor;
extern boolean PredEs_bVldOKN2Egd_MP;
extern boolean PredEs_bVldOkN2EgdSave;
extern boolean PredEs_bVldTiLstCgt;
extern boolean PredEs_bVldTiLstCgtRaw_MP;
extern boolean PredEs_bVldTiLstCgtUpd;
extern uint32 PredEs_ti3LstCgtClc_MP;
extern uint32 PredEs_tiCgt_MP;
extern uint32 PredEs_tiCgtCor;
extern uint32 PredEs_tiCgtLst_MP;
extern uint32 PredEs_tiLst2CgtCor;
extern uint32 PredEs_tiLstCgtCor;
extern uint8 PredEs_agEng;
extern uint8 PredEs_agEngDly;
extern uint8 PredEs_agMissCgt360;
extern uint8 PredEs_idxLstBufTiWr;
extern uint8 PREDES_idxLstBufTiWrPrev;
extern uint8 PredEs_idxLstBufWr;
extern uint8 PredEs_idxLstBufWrDyn_MP;
extern uint8 PredEs_idxLstTDCChgDir_MP;
extern uint8 PredEs_noCgt;
extern uint8 PredEs_noCgtLstCgtChgDir;
extern uint8 PredEs_noCgtPhaEng;
extern uint8 PredEs_noIniCnd;
extern uint8 PredEs_noNFill;
extern uint8 PredEs_noNFill180_MP;
extern uint8 PredEs_noNFillTi;
extern uint8 PredEs_noOkOscN_MP;
extern uint8 PredEs_noTrig;
extern uint8 PredEs_noTrigBufNEs;
extern uint8 PredEs_noTrigBufNEs_MP;
extern uint8 PredEs_noTrigBufTi;
extern uint8 PredEs_noTrigCor;
extern uint8 PredEs_noTrigInc;
extern uint8 PredEs_noTypCgt;
extern uint8 PREDES_u8Cnt;
extern uint8 PREDES_u8Cnt1;
extern uint8 PREDES_u8CntTmrRst2;
extern uint8 PREDES_u8IncrCounter;
extern sint16 PredEs_n2DecE2TDC;
extern sint16 PredEs_n2DecE2TDCRaw_MP;
extern sint16 PredEs_n2DecE2TDCSave_MP;
extern sint16 PredEs_n2DecEPred;
extern sint16 PredEs_n2PredCur_MP;
extern sint16 PredEs_n2PredInter;
extern sint16 PredEs_nCorPred;
extern sint16 PredEs_nCurCor;
extern sint16 PredEs_nCurCor2;
extern sint16 PredEs_nCurRaw;
extern sint16 PredEs_nCurRaw_MP;
extern sint16 PredEs_nLstTDCChgDir_MP;
extern sint16 PredEs_nPredHiRaw;
extern sint16 PredEs_nPredInter;
extern sint16 PredEs_nPredInterPrev;
extern sint16 PredEs_nPredLoRaw;
extern sint16 PredEs_nStaEgdLoThd;
extern sint16 PredEs_prm_idxBufTiWr_MP[PREDES_PRM_IDXBUFTIWR_MP_COLS];
extern sint16 PredEs_tiCntFct2CntCgt;
extern sint16 PredEs_tiErrOkN2EgdInc_MP;
extern uint16 PredEs_n2CgtLstTDCChgDir_MP;
extern uint16 PredEs_n2ChgDir_MP;
extern uint16 PredEs_nMaxOsc_MP;
extern uint16 PredEs_nPredCur_MP;
extern uint16 PredEs_prm_nBuf[PREDES_PRM_NBUF_COLS];
extern uint16 PREDES_Sqrt_Bkpt[PREDES_SQRT_BKPT_COLS];
extern uint16 PREDES_Sqrt_Table[PREDES_SQRT_TABLE_COLS];
extern uint16 PredEs_ti3LstCgtCor_MP;
extern uint16 PredEs_tiCntCgt;
extern uint16 PredEs_tiCntCgtPrev;
extern uint16 PredEs_tiCntPred;
extern uint16 PredEs_tiCntPredPrev;
extern uint16 PredEs_tiDlyLstClcN;
extern uint16 PredEs_tiDlyLstClcNNew;
extern uint16 PredEs_tiErrOkN2EgdChgDir;
extern uint16 PredEs_tiErrOkN2EgdChgDir2;
extern uint16 PredEs_tiMaxBufMax;
extern uint16 PredEs_tiMaxBufMin_MP;
extern uint16 PredEs_tiMaxBufMinRaw_MP;
extern uint16 PredEs_tiMaxBufPrevMin_MP;
extern uint16 PredEs_tiMinBufMax_MP;
extern uint16 PredEs_tiMinBufMaxRaw_MP;
extern uint16 PredEs_tiMinBufPrevMax_MP;
extern uint16 PredEs_tiStaEgdHiThd;
extern uint16 PredEs_tiStaEgdLoThd;
extern uint16 PREDES_u16TiMaxBufMaxPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PREDES_vidActCalStrtEngaAuthrEng(void);
void PREDES_vidCalcCrkPosBfrEngDirChg(void);
void PREDES_vidCalcDlyBtwEngSpdNCrtTi(void);
void PREDES_vidCalcInfEstTiBtwPrdNBfN(void);
void PREDES_vidCalcInstEngSpdNFillBfr(void);
void PREDES_vidCalcPredictionSetpts(void);
void PREDES_vidCalcStrtEngaAuthrEng(void);
void PREDES_vidCalcStrtrEngaAfrEngDir(void);
void PREDES_vidCalcStrtrEngaBfrEngDir(void);
void PREDES_vidCalculateIncrementStep(void);
void PREDES_vidCalculatPredictionTime(void);
void PREDES_vidCalEngSpdLnkWthWhilInc(void);
void PREDES_vidChkCondToEngagAreFlfld(void);
void PREDES_vidChkEngSpdToEngageStrtr(void);
void PREDES_vidChkIfCndToFilbfrRFlfld(void);
void PREDES_vidCoordinatWhileLoopPrt1(void);
void PREDES_vidCoordinatWhileLoopPrt2(void);
void PREDES_vidCorrectPredictionTime(void);
void PREDES_vidCorrOutIfCalcDisabled(void);
void PREDES_vidCreatLvlBtw6DgrVarNFct(void);
void PREDES_vidCrtLogDatToCalcInstSpd(void);
void PREDES_vidCrtNumDatToCalcInstSpd(void);
void PREDES_vidDetectSmallEngSpdOsc(void);
void PREDES_vidEstimatCorrectedEngSpd(void);
void PREDES_vidEstmTibtwPrdEsNBufNEs(void);
void PREDES_vidEvaluatCorEngSpdValdty(void);
void PREDES_vidFillInstanEngSpdBuffer(void);
void PREDES_vidFormatInformation(void);
void PREDES_vidGlobalView(void);
void PREDES_vidInitOutput(void);
void PREDES_vidMergThe2Authorizations(void);
void PREDES_vidPredictEngineSpeed(void);
void PREDES_vidPredictEngSpdForDefiTi(void);
void PREDES_vidSetRelSecEngAuthorize(void);
void PREDES_vidSetRlbleEngagemntAuthr(void);
void PREDES_vidSetSmallEngSpdOscDtct(void);
void PREDES_vidSlctTiBtwCrkshftTeeth(void);


#endif /* PREDES_L_H */

/*-------------------------------- end of file -------------------------------*/
