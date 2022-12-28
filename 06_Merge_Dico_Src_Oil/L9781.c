/***************************************************************************
;**
;** FILE NAME      : L9781.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "L9781_CFG_E.h"
#include "L9781_E.h"
#include "L9781_TYP.h"
#include "STD_TYPES.h"
#include "TYPE.h"
#include "L9781.H"
#include "L9781_L.H"
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
const uint32  L9781_ku32AbFra1ConfCfg1 = 0;
const uint32  L9781_ku32AbFra1ConfCfg2 = 0;
const uint32  L9781_ku32AbFra1Para1Prof1 = 0;
const uint32  L9781_ku32AbFra1Para1Prof2 = 0;
const uint32  L9781_ku32AbFra1Para1Prof3 = 0;
const uint32  L9781_ku32AbFra1Para1Prof4 = 0;
const uint32  L9781_ku32AbFra1Para2Prof1 = 0;
const uint32  L9781_ku32AbFra1Para2Prof2 = 0;
const uint32  L9781_ku32AbFra1Para2Prof3 = 0;
const uint32  L9781_ku32AbFra1Para2Prof4 = 0;
const uint32  L9781_ku32AbFra1Para3Prof1 = 0;
const uint32  L9781_ku32AbFra1Para3Prof2 = 0;
const uint32  L9781_ku32AbFra1Para3Prof3 = 0;
const uint32  L9781_ku32AbFra1Para3Prof4 = 0;
const uint32  L9781_ku32AbFra1Para4Prof1 = 0;
const uint32  L9781_ku32AbFra1Para4Prof2 = 0;
const uint32  L9781_ku32AbFra1Para4Prof3 = 0;
const uint32  L9781_ku32AbFra1Para4Prof4 = 0;
const uint32  L9781_ku32AbFra2ConfCfg1 = 0;
const uint32  L9781_ku32AbFra2ConfCfg2 = 0;
const uint32  L9781_ku32AbFra2Para1Prof1 = 0;
const uint32  L9781_ku32AbFra2Para1Prof2 = 0;
const uint32  L9781_ku32AbFra2Para1Prof3 = 0;
const uint32  L9781_ku32AbFra2Para1Prof4 = 0;
const uint32  L9781_ku32AbFra2Para2Prof1 = 0;
const uint32  L9781_ku32AbFra2Para2Prof2 = 0;
const uint32  L9781_ku32AbFra2Para2Prof3 = 0;
const uint32  L9781_ku32AbFra2Para2Prof4 = 0;
const uint32  L9781_ku32AbFra2Para3Prof1 = 0;
const uint32  L9781_ku32AbFra2Para3Prof2 = 0;
const uint32  L9781_ku32AbFra2Para3Prof3 = 0;
const uint32  L9781_ku32AbFra2Para3Prof4 = 0;
const uint32  L9781_ku32AbFra2Para4Prof1 = 0;
const uint32  L9781_ku32AbFra2Para4Prof2 = 0;
const uint32  L9781_ku32AbFra2Para4Prof3 = 0;
const uint32  L9781_ku32AbFra2Para4Prof4 = 0;
const uint32  L9781_ku32AbFra3ConfCfg1 = 0;
const uint32  L9781_ku32AbFra3ConfCfg2 = 0;
const uint32  L9781_ku32AbFra3Para1Prof1 = 0;
const uint32  L9781_ku32AbFra3Para1Prof2 = 0;
const uint32  L9781_ku32AbFra3Para1Prof3 = 0;
const uint32  L9781_ku32AbFra3Para1Prof4 = 0;
const uint32  L9781_ku32AbFra3Para2Prof1 = 0;
const uint32  L9781_ku32AbFra3Para2Prof2 = 0;
const uint32  L9781_ku32AbFra3Para2Prof3 = 0;
const uint32  L9781_ku32AbFra3Para2Prof4 = 0;
const uint32  L9781_ku32AbFra3Para3Prof1 = 0;
const uint32  L9781_ku32AbFra3Para3Prof2 = 0;
const uint32  L9781_ku32AbFra3Para3Prof3 = 0;
const uint32  L9781_ku32AbFra3Para3Prof4 = 0;
const uint32  L9781_ku32AbIdleDlyCfg1 = 0;
const uint32  L9781_ku32AbIdleDlyCfg2 = 0;
const uint32  L9781_ku32AbProtConfCfg1 = 0;
const uint32  L9781_ku32AbProtConfCfg2 = 0;
const uint32  L9781_ku32AbZlcOcConfCfg1 = 0;
const uint32  L9781_ku32AbZlcOcConfCfg2 = 0;
const uint32  L9781_ku32DcdcConfCfg1 = 0;
const uint32  L9781_ku32DcdcConfCfg2 = 0;
const uint32  L9781_ku32DiagProtCtrlCfg1 = 0;
const uint32  L9781_ku32DiagProtCtrlCfg2 = 0;
const uint32  L9781_ku32FpFra1ConfCfg1 = 0;
const uint32  L9781_ku32FpFra1ConfCfg2 = 0;
const uint32  L9781_ku32FpFra1Para1Prof1 = 0;
const uint32  L9781_ku32FpFra1Para1Prof10 = 0;
const uint32  L9781_ku32FpFra1Para1Prof11 = 0;
const uint32  L9781_ku32FpFra1Para1Prof12 = 0;
const uint32  L9781_ku32FpFra1Para1Prof13 = 0;
const uint32  L9781_ku32FpFra1Para1Prof14 = 0;
const uint32  L9781_ku32FpFra1Para1Prof15 = 0;
const uint32  L9781_ku32FpFra1Para1Prof16 = 0;
const uint32  L9781_ku32FpFra1Para1Prof17 = 0;
const uint32  L9781_ku32FpFra1Para1Prof18 = 0;
const uint32  L9781_ku32FpFra1Para1Prof19 = 0;
const uint32  L9781_ku32FpFra1Para1Prof2 = 0;
const uint32  L9781_ku32FpFra1Para1Prof20 = 0;
const uint32  L9781_ku32FpFra1Para1Prof21 = 0;
const uint32  L9781_ku32FpFra1Para1Prof22 = 0;
const uint32  L9781_ku32FpFra1Para1Prof23 = 0;
const uint32  L9781_ku32FpFra1Para1Prof24 = 0;
const uint32  L9781_ku32FpFra1Para1Prof25 = 0;
const uint32  L9781_ku32FpFra1Para1Prof26 = 0;
const uint32  L9781_ku32FpFra1Para1Prof3 = 0;
const uint32  L9781_ku32FpFra1Para1Prof4 = 0;
const uint32  L9781_ku32FpFra1Para1Prof5 = 0;
const uint32  L9781_ku32FpFra1Para1Prof6 = 0;
const uint32  L9781_ku32FpFra1Para1Prof7 = 0;
const uint32  L9781_ku32FpFra1Para1Prof8 = 0;
const uint32  L9781_ku32FpFra1Para1Prof9 = 0;
const uint32  L9781_ku32FpFra1Para2Prof1 = 0;
const uint32  L9781_ku32FpFra1Para2Prof10 = 0;
const uint32  L9781_ku32FpFra1Para2Prof11 = 0;
const uint32  L9781_ku32FpFra1Para2Prof12 = 0;
const uint32  L9781_ku32FpFra1Para2Prof13 = 0;
const uint32  L9781_ku32FpFra1Para2Prof14 = 0;
const uint32  L9781_ku32FpFra1Para2Prof15 = 0;
const uint32  L9781_ku32FpFra1Para2Prof16 = 0;
const uint32  L9781_ku32FpFra1Para2Prof17 = 0;
const uint32  L9781_ku32FpFra1Para2Prof18 = 0;
const uint32  L9781_ku32FpFra1Para2Prof19 = 0;
const uint32  L9781_ku32FpFra1Para2Prof2 = 0;
const uint32  L9781_ku32FpFra1Para2Prof20 = 0;
const uint32  L9781_ku32FpFra1Para2Prof21 = 0;
const uint32  L9781_ku32FpFra1Para2Prof22 = 0;
const uint32  L9781_ku32FpFra1Para2Prof23 = 0;
const uint32  L9781_ku32FpFra1Para2Prof24 = 0;
const uint32  L9781_ku32FpFra1Para2Prof25 = 0;
const uint32  L9781_ku32FpFra1Para2Prof26 = 0;
const uint32  L9781_ku32FpFra1Para2Prof3 = 0;
const uint32  L9781_ku32FpFra1Para2Prof4 = 0;
const uint32  L9781_ku32FpFra1Para2Prof5 = 0;
const uint32  L9781_ku32FpFra1Para2Prof6 = 0;
const uint32  L9781_ku32FpFra1Para2Prof7 = 0;
const uint32  L9781_ku32FpFra1Para2Prof8 = 0;
const uint32  L9781_ku32FpFra1Para2Prof9 = 0;
const uint32  L9781_ku32FpFra1Para3Prof1 = 0;
const uint32  L9781_ku32FpFra1Para3Prof10 = 0;
const uint32  L9781_ku32FpFra1Para3Prof11 = 0;
const uint32  L9781_ku32FpFra1Para3Prof12 = 0;
const uint32  L9781_ku32FpFra1Para3Prof13 = 0;
const uint32  L9781_ku32FpFra1Para3Prof14 = 0;
const uint32  L9781_ku32FpFra1Para3Prof15 = 0;
const uint32  L9781_ku32FpFra1Para3Prof16 = 0;
const uint32  L9781_ku32FpFra1Para3Prof17 = 0;
const uint32  L9781_ku32FpFra1Para3Prof18 = 0;
const uint32  L9781_ku32FpFra1Para3Prof19 = 0;
const uint32  L9781_ku32FpFra1Para3Prof2 = 0;
const uint32  L9781_ku32FpFra1Para3Prof20 = 0;
const uint32  L9781_ku32FpFra1Para3Prof21 = 0;
const uint32  L9781_ku32FpFra1Para3Prof22 = 0;
const uint32  L9781_ku32FpFra1Para3Prof23 = 0;
const uint32  L9781_ku32FpFra1Para3Prof24 = 0;
const uint32  L9781_ku32FpFra1Para3Prof25 = 0;
const uint32  L9781_ku32FpFra1Para3Prof26 = 0;
const uint32  L9781_ku32FpFra1Para3Prof3 = 0;
const uint32  L9781_ku32FpFra1Para3Prof4 = 0;
const uint32  L9781_ku32FpFra1Para3Prof5 = 0;
const uint32  L9781_ku32FpFra1Para3Prof6 = 0;
const uint32  L9781_ku32FpFra1Para3Prof7 = 0;
const uint32  L9781_ku32FpFra1Para3Prof8 = 0;
const uint32  L9781_ku32FpFra1Para3Prof9 = 0;
const uint32  L9781_ku32FpFra1Para4Prof1 = 0;
const uint32  L9781_ku32FpFra1Para4Prof10 = 0;
const uint32  L9781_ku32FpFra1Para4Prof11 = 0;
const uint32  L9781_ku32FpFra1Para4Prof12 = 0;
const uint32  L9781_ku32FpFra1Para4Prof13 = 0;
const uint32  L9781_ku32FpFra1Para4Prof14 = 0;
const uint32  L9781_ku32FpFra1Para4Prof15 = 0;
const uint32  L9781_ku32FpFra1Para4Prof16 = 0;
const uint32  L9781_ku32FpFra1Para4Prof17 = 0;
const uint32  L9781_ku32FpFra1Para4Prof18 = 0;
const uint32  L9781_ku32FpFra1Para4Prof19 = 0;
const uint32  L9781_ku32FpFra1Para4Prof2 = 0;
const uint32  L9781_ku32FpFra1Para4Prof20 = 0;
const uint32  L9781_ku32FpFra1Para4Prof21 = 0;
const uint32  L9781_ku32FpFra1Para4Prof22 = 0;
const uint32  L9781_ku32FpFra1Para4Prof23 = 0;
const uint32  L9781_ku32FpFra1Para4Prof24 = 0;
const uint32  L9781_ku32FpFra1Para4Prof25 = 0;
const uint32  L9781_ku32FpFra1Para4Prof26 = 0;
const uint32  L9781_ku32FpFra1Para4Prof3 = 0;
const uint32  L9781_ku32FpFra1Para4Prof4 = 0;
const uint32  L9781_ku32FpFra1Para4Prof5 = 0;
const uint32  L9781_ku32FpFra1Para4Prof6 = 0;
const uint32  L9781_ku32FpFra1Para4Prof7 = 0;
const uint32  L9781_ku32FpFra1Para4Prof8 = 0;
const uint32  L9781_ku32FpFra1Para4Prof9 = 0;
const uint32  L9781_ku32FpFra2ConfCfg1 = 0;
const uint32  L9781_ku32FpFra2ConfCfg2 = 0;
const uint32  L9781_ku32FpFra2Para1Prof1 = 0;
const uint32  L9781_ku32FpFra2Para1Prof10 = 0;
const uint32  L9781_ku32FpFra2Para1Prof11 = 0;
const uint32  L9781_ku32FpFra2Para1Prof12 = 0;
const uint32  L9781_ku32FpFra2Para1Prof13 = 0;
const uint32  L9781_ku32FpFra2Para1Prof14 = 0;
const uint32  L9781_ku32FpFra2Para1Prof15 = 0;
const uint32  L9781_ku32FpFra2Para1Prof16 = 0;
const uint32  L9781_ku32FpFra2Para1Prof17 = 0;
const uint32  L9781_ku32FpFra2Para1Prof18 = 0;
const uint32  L9781_ku32FpFra2Para1Prof19 = 0;
const uint32  L9781_ku32FpFra2Para1Prof2 = 0;
const uint32  L9781_ku32FpFra2Para1Prof20 = 0;
const uint32  L9781_ku32FpFra2Para1Prof21 = 0;
const uint32  L9781_ku32FpFra2Para1Prof22 = 0;
const uint32  L9781_ku32FpFra2Para1Prof23 = 0;
const uint32  L9781_ku32FpFra2Para1Prof24 = 0;
const uint32  L9781_ku32FpFra2Para1Prof25 = 0;
const uint32  L9781_ku32FpFra2Para1Prof26 = 0;
const uint32  L9781_ku32FpFra2Para1Prof3 = 0;
const uint32  L9781_ku32FpFra2Para1Prof4 = 0;
const uint32  L9781_ku32FpFra2Para1Prof5 = 0;
const uint32  L9781_ku32FpFra2Para1Prof6 = 0;
const uint32  L9781_ku32FpFra2Para1Prof7 = 0;
const uint32  L9781_ku32FpFra2Para1Prof8 = 0;
const uint32  L9781_ku32FpFra2Para1Prof9 = 0;
const uint32  L9781_ku32FpFra2Para2Prof1 = 0;
const uint32  L9781_ku32FpFra2Para2Prof10 = 0;
const uint32  L9781_ku32FpFra2Para2Prof11 = 0;
const uint32  L9781_ku32FpFra2Para2Prof12 = 0;
const uint32  L9781_ku32FpFra2Para2Prof13 = 0;
const uint32  L9781_ku32FpFra2Para2Prof14 = 0;
const uint32  L9781_ku32FpFra2Para2Prof15 = 0;
const uint32  L9781_ku32FpFra2Para2Prof16 = 0;
const uint32  L9781_ku32FpFra2Para2Prof17 = 0;
const uint32  L9781_ku32FpFra2Para2Prof18 = 0;
const uint32  L9781_ku32FpFra2Para2Prof19 = 0;
const uint32  L9781_ku32FpFra2Para2Prof2 = 0;
const uint32  L9781_ku32FpFra2Para2Prof20 = 0;
const uint32  L9781_ku32FpFra2Para2Prof21 = 0;
const uint32  L9781_ku32FpFra2Para2Prof22 = 0;
const uint32  L9781_ku32FpFra2Para2Prof23 = 0;
const uint32  L9781_ku32FpFra2Para2Prof24 = 0;
const uint32  L9781_ku32FpFra2Para2Prof25 = 0;
const uint32  L9781_ku32FpFra2Para2Prof26 = 0;
const uint32  L9781_ku32FpFra2Para2Prof3 = 0;
const uint32  L9781_ku32FpFra2Para2Prof4 = 0;
const uint32  L9781_ku32FpFra2Para2Prof5 = 0;
const uint32  L9781_ku32FpFra2Para2Prof6 = 0;
const uint32  L9781_ku32FpFra2Para2Prof7 = 0;
const uint32  L9781_ku32FpFra2Para2Prof8 = 0;
const uint32  L9781_ku32FpFra2Para2Prof9 = 0;
const uint32  L9781_ku32FpFra2Para3Prof1 = 0;
const uint32  L9781_ku32FpFra2Para3Prof10 = 0;
const uint32  L9781_ku32FpFra2Para3Prof11 = 0;
const uint32  L9781_ku32FpFra2Para3Prof12 = 0;
const uint32  L9781_ku32FpFra2Para3Prof13 = 0;
const uint32  L9781_ku32FpFra2Para3Prof14 = 0;
const uint32  L9781_ku32FpFra2Para3Prof15 = 0;
const uint32  L9781_ku32FpFra2Para3Prof16 = 0;
const uint32  L9781_ku32FpFra2Para3Prof17 = 0;
const uint32  L9781_ku32FpFra2Para3Prof18 = 0;
const uint32  L9781_ku32FpFra2Para3Prof19 = 0;
const uint32  L9781_ku32FpFra2Para3Prof2 = 0;
const uint32  L9781_ku32FpFra2Para3Prof20 = 0;
const uint32  L9781_ku32FpFra2Para3Prof21 = 0;
const uint32  L9781_ku32FpFra2Para3Prof22 = 0;
const uint32  L9781_ku32FpFra2Para3Prof23 = 0;
const uint32  L9781_ku32FpFra2Para3Prof24 = 0;
const uint32  L9781_ku32FpFra2Para3Prof25 = 0;
const uint32  L9781_ku32FpFra2Para3Prof26 = 0;
const uint32  L9781_ku32FpFra2Para3Prof3 = 0;
const uint32  L9781_ku32FpFra2Para3Prof4 = 0;
const uint32  L9781_ku32FpFra2Para3Prof5 = 0;
const uint32  L9781_ku32FpFra2Para3Prof6 = 0;
const uint32  L9781_ku32FpFra2Para3Prof7 = 0;
const uint32  L9781_ku32FpFra2Para3Prof8 = 0;
const uint32  L9781_ku32FpFra2Para3Prof9 = 0;
const uint32  L9781_ku32FpIdleDlyCfg1 = 0;
const uint32  L9781_ku32FpIdleDlyCfg2 = 0;
const uint32  L9781_ku32FpProtConfCfg1 = 0;
const uint32  L9781_ku32FpProtConfCfg2 = 0;
const uint32  L9781_ku32FpZlcOcConfCfg1 = 0;
const uint32  L9781_ku32FpZlcOcConfCfg2 = 0;
const uint32  L9781_ku32GenConfCfg1 = 0;
const uint32  L9781_ku32GenConfCfg2 = 0;
const uint32  L9781_ku32IsenConfCfg1 = 0;
const uint32  L9781_ku32IsenConfCfg2 = 0;
const uint32  L9781_ku32PdrvConfCfg1 = 0;
const uint32  L9781_ku32PdrvConfCfg2 = 0;
const uint32  L9781_ku32PdrvEnbCfg1 = 0;
const uint32  L9781_ku32PdrvEnbCfg2 = 0;
const uint32  L9781_ku32ProtFiltCtrlCfg1 = 0;
const uint32  L9781_ku32ProtFiltCtrlCfg2 = 0;
const uint8  L9781_ku8DelayBeforeUnlock = 0;
const uint8  L9781_ku8MaxSpiFailureNbAtInit = 0;
const uint8  L9781_ku8VboostAuthDiagDly = 0;
const uint16  L9781_ku16ClkToRstTime = 0;
const uint16  L9781_ku16MaxBankFailure = 0;
const uint16  L9781_ku16RstActiveTime = 0;
const uint16  L9781_ku16RstToSpiTime = 0;
const uint16  L9781_ku16VboostVoltHighLimit = 0;
const uint16  L9781_ku16VboostVoltLowLimit = 0;
const uint16  L9781_ku16WCbtChargeTime = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
uint8 L9781_enuLoadingState;
uint8 L9781_enuStartupState;
boolean L9781_abActStatus[L9781_ABACTSTATUS_COLS];
boolean L9781_abIrqActStatus[L9781_ABIRQACTSTATUS_COLS];
boolean L9781_abIrqIdleStatus[L9781_ABIRQIDLESTATUS_COLS];
boolean L9781_abOnlyOvlSpiDiagMode[L9781_ABONLYOVLSPIDIAGMODE_COLS];
boolean L9781_bCheckBuffer;
boolean L9781_bDiagOlBankAx;
boolean L9781_bDiagOlBankAy;
boolean L9781_bDiagOlBankBx;
boolean L9781_bDiagOlBankBy;
boolean L9781_bDiagOlBankFp;
boolean L9781_bDiagOvVbat;
boolean L9781_bDiagScGndBankAx;
boolean L9781_bDiagScGndBankAy;
boolean L9781_bDiagScGndBankBx;
boolean L9781_bDiagScGndBankBy;
boolean L9781_bDiagScGndBankFp;
boolean L9781_bDiagScVbBankAx;
boolean L9781_bDiagScVbBankAy;
boolean L9781_bDiagScVbBankBx;
boolean L9781_bDiagScVbBankBy;
boolean L9781_bDiagScVbBankFp;
boolean L9781_bDiagScVhsVlsBankAx;
boolean L9781_bDiagScVhsVlsBankAy;
boolean L9781_bDiagScVhsVlsBankBx;
boolean L9781_bDiagScVhsVlsBankBy;
boolean L9781_bDiagScVhsVlsBankFp;
boolean L9781_bDiagUvVbat;
boolean L9781_bEnabled;
boolean L9781_bEnableRequest;
boolean L9781_bFirstInitDone;
boolean L9781_bGdiAsicFullStopped;
boolean L9781_bReadDiagValid;
boolean L9781_bSpiAddressFail;
boolean L9781_bSpiComFailure;
boolean L9781_bSpiDataFail;
boolean L9781_bSpiFifoRequest;
boolean L9781_bSpiMswFrameTransmit;
boolean L9781_bSpiStartRequest;
boolean L9781_bSpiTxRequest;
boolean L9781_bStartupComplete;
boolean L9781_bStopModeActive;
uint32 L9781_u32SpiCorruptedAddress;
uint8 L9781_au8FifoSpiReqCh[L9781_AU8FIFOSPIREQCH_COLS];
uint8 L9781_au8FifoSpiReqTyp[L9781_AU8FIFOSPIREQTYP_COLS];
uint8 L9781_u8ComponentIndex;
uint8 L9781_u8ComponentToDiag;
uint8 L9781_u8InjFrameUpdtCnt;
uint8 L9781_u8InjProfileIndex;
uint8 L9781_u8NbSpiRequest;
uint8 L9781_u8PmpFrameUpdtCnt;
uint8 L9781_u8PmpProfileIndex;
uint8 L9781_u8SpiErrorCnt;
uint8 L9781_u8SpiFailureNbAtInit;
uint8 L9781_u8SpiFrameIndex;
uint8 L9781_u8VboostAuthDiagDcntr;
uint16 L9781_bfDiagComplete;
uint16 L9781_bfInjProfUpdated;
uint16 L9781_bfLoadDiagReq;
uint16 L9781_bfLoadInjProfReq;
uint16 L9781_bfLoadPmpProfReq;
uint16 L9781_bfLoadUnlockReq;
uint16 L9781_bfPmpProfUpdated;
uint16 L9781_u16SpiBufferRxLsw;
uint16 L9781_u16SpiBufferRxMsw;
uint16 L9781_u16SpiBufferTxLsw;
uint16 L9781_u16SpiBufferTxMsw;
uint16 L9781_u16SpiPrevFrameTxLsw;
uint16 L9781_u16SpiPrevFrameTxMsw;
uint16 L9781_u16VboostVoltage;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

