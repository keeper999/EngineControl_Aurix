/***************************************************************************
;**
;** FILE NAME      : PREDES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PREDES.H"
#include "PREDES_L.H"
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
const boolean  PredEs_bAcvOKOscN_C = 0;
const boolean  PredEs_bBypTi3LstCgtClc_C = 0;
const boolean  PredEs_bChgOKN2EgdChgDir_C = 0;
const boolean  PredEs_bForcAcvRecBuf_C = 0;
const boolean  PredEs_bTrigBufNEsSet_C = 0;
const sint8  PredEs_tiIncErrOkEgdChgDir_C = 0;
const uint8  PredEs_bAcvInfoCpl_C = 0;
const uint8  PredEs_facFilN2Dec_C = 0;
const uint8  PredEs_nLim2Inc1_C = 0;
const uint8  PredEs_noCaseBuf_C = 0;
const uint8  PredEs_noCgtPhaEng_C = 0;
const uint8  PredEs_noFirstTrigBufNEs_C = 0;
const uint8  PredEs_noLim2Inc_C = 0;
const uint8  PredEs_nStaEgdLoThd2_C = 0;
const uint8  PredEs_nThdAcvFct_C = 0;
const uint8  PredEs_nVldOKN2Egd_C = 0;
const uint8  PREDES_u8Inhib = 0;
const uint16  PredEs_tiDlyStaEgdHiThd_C = 0;
const uint16  PredEs_tiUncrtTrigFct_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean PredEs_bAcvClcPredCurN;
boolean PredEs_bAcvClcPredNHi;
boolean PredEs_bAcvClcPredNLo;
boolean PredEs_bAcvRecBuf;
boolean PredEs_bAcvRecBuf0_MP;
boolean PREDES_bAcvRecBufPrev;
boolean PredEs_bClcPredCurN;
boolean PredEs_bClcPredEs;
boolean PredEs_bClcPredN;
boolean PredEs_bClcPredNHi;
boolean PredEs_bClcPredNIntl;
boolean PredEs_bCndStop;
boolean PredEs_bDetChgDir;
boolean PredEs_bDetSlowNPred;
boolean PredEs_bDetSlowNPredRaw;
boolean PredEs_bDirRotCk;
boolean PREDES_bDirRotCkPrev;
boolean PredEs_bEngSyncAccu;
boolean PREDES_bFallEdgStrtTmrRst2Prev;
boolean PredEs_bFirstClcPredEs;
boolean PREDES_bFirstClcPredEsPrev;
boolean PREDES_bFlipFlopNotOut1;
boolean PREDES_bFlipFlopOut2;
boolean PREDES_bFlipFlopOut2Prev;
boolean PREDES_bFlipFlopOut3;
boolean PREDES_bFlipFlopOut5;
boolean PREDES_bInfoCplStPrev;
boolean PredEs_bNotCgtLstFct;
boolean PredEs_bOkCndIntl;
boolean PredEs_bOkN2EgdChgDir;
boolean PREDES_bOkN2EgdPrev;
boolean PredEs_bOkOscN;
boolean PredEs_bOkOscNRaw;
boolean PREDES_bOkOscNRawPrev;
boolean PREDES_bOkOscPrev;
boolean PREDES_bRisingEdgeInPrev1;
boolean PREDES_bRisingEdgeInPrev2;
boolean PREDES_bRisingEdgeInPrev3;
boolean PredEs_bSecPhaPred;
boolean PredEs_bSecPhaSecu;
boolean PREDES_bStrtTmrRst1Prev;
boolean PREDES_bStrtTmrRst2Prev;
boolean PREDES_bTmr1Out;
boolean PREDES_bTmr1OutPrev;
boolean PREDES_bTmrOut;
boolean PREDES_bTmrOutPrev;
boolean PREDES_bTmrRstOut2;
boolean PredEs_bTrigIni;
boolean PredEs_bTypCgt;
boolean PredEs_bTypCgt180First;
boolean PredEs_bVldCurNCll;
boolean PredEs_bVldCurNCll_MP;
boolean PredEs_bVldCurNCor;
boolean PredEs_bVldOKN2Egd_MP;
boolean PredEs_bVldOkN2EgdSave;
boolean PredEs_bVldTiLstCgt;
boolean PredEs_bVldTiLstCgtRaw_MP;
boolean PredEs_bVldTiLstCgtUpd;
uint32 PredEs_ti3LstCgtClc_MP;
uint32 PredEs_tiCgt_MP;
uint32 PredEs_tiCgtCor;
uint32 PredEs_tiCgtLst_MP;
uint32 PredEs_tiLst2CgtCor;
uint32 PredEs_tiLstCgtCor;
uint8 PredEs_agEng;
uint8 PredEs_agEngDly;
uint8 PredEs_agMissCgt360;
uint8 PredEs_idxLstBufTiWr;
uint8 PREDES_idxLstBufTiWrPrev;
uint8 PredEs_idxLstBufWr;
uint8 PredEs_idxLstBufWrDyn_MP;
uint8 PredEs_idxLstTDCChgDir_MP;
uint8 PredEs_noCgt;
uint8 PredEs_noCgtLstCgtChgDir;
uint8 PredEs_noCgtPhaEng;
uint8 PredEs_noIniCnd;
uint8 PredEs_noNFill;
uint8 PredEs_noNFill180_MP;
uint8 PredEs_noNFillTi;
uint8 PredEs_noOkOscN_MP;
uint8 PredEs_noTrig;
uint8 PredEs_noTrigBufNEs;
uint8 PredEs_noTrigBufNEs_MP;
uint8 PredEs_noTrigBufTi;
uint8 PredEs_noTrigCor;
uint8 PredEs_noTrigInc;
uint8 PredEs_noTypCgt;
uint8 PREDES_u8Cnt;
uint8 PREDES_u8Cnt1;
uint8 PREDES_u8CntTmrRst2;
uint8 PREDES_u8IncrCounter;
sint16 PredEs_n2DecE2TDC;
sint16 PredEs_n2DecE2TDCRaw_MP;
sint16 PredEs_n2DecE2TDCSave_MP;
sint16 PredEs_n2DecEPred;
sint16 PredEs_n2PredCur_MP;
sint16 PredEs_n2PredInter;
sint16 PredEs_nCorPred;
sint16 PredEs_nCurCor;
sint16 PredEs_nCurCor2;
sint16 PredEs_nCurRaw;
sint16 PredEs_nCurRaw_MP;
sint16 PredEs_nLstTDCChgDir_MP;
sint16 PredEs_nPredHiRaw;
sint16 PredEs_nPredInter;
sint16 PredEs_nPredInterPrev;
sint16 PredEs_nPredLoRaw;
sint16 PredEs_nStaEgdLoThd;
sint16 PredEs_prm_idxBufTiWr_MP[PREDES_PRM_IDXBUFTIWR_MP_COLS];
sint16 PredEs_tiCntFct2CntCgt;
sint16 PredEs_tiErrOkN2EgdInc_MP;
uint16 PredEs_n2CgtLstTDCChgDir_MP;
uint16 PredEs_n2ChgDir_MP;
uint16 PredEs_nMaxOsc_MP;
uint16 PredEs_nPredCur_MP;
uint16 PredEs_prm_nBuf[PREDES_PRM_NBUF_COLS];
uint16 PREDES_Sqrt_Bkpt[PREDES_SQRT_BKPT_COLS];
uint16 PREDES_Sqrt_Table[PREDES_SQRT_TABLE_COLS];
uint16 PredEs_ti3LstCgtCor_MP;
uint16 PredEs_tiCntCgt;
uint16 PredEs_tiCntCgtPrev;
uint16 PredEs_tiCntPred;
uint16 PredEs_tiCntPredPrev;
uint16 PredEs_tiDlyLstClcN;
uint16 PredEs_tiDlyLstClcNNew;
uint16 PredEs_tiErrOkN2EgdChgDir;
uint16 PredEs_tiErrOkN2EgdChgDir2;
uint16 PredEs_tiMaxBufMax;
uint16 PredEs_tiMaxBufMin_MP;
uint16 PredEs_tiMaxBufMinRaw_MP;
uint16 PredEs_tiMaxBufPrevMin_MP;
uint16 PredEs_tiMinBufMax_MP;
uint16 PredEs_tiMinBufMaxRaw_MP;
uint16 PredEs_tiMinBufPrevMax_MP;
uint16 PredEs_tiStaEgdHiThd;
uint16 PredEs_tiStaEgdLoThd;
uint16 PREDES_u16TiMaxBufMaxPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

