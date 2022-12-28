/***************************************************************************
;**
;** FILE NAME      : MCWDG_L.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef MCWDG_L_H
#define MCWDG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MCWDG_Cfg.h"
#include "MCWDG_Typ.h"
#include "STD_Types.h"
#include "type.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MCWDG_AU8RXBUFFER_COLS                 ( 2 )
#define MCWDG_AU8TXBUFFER_COLS                 ( 2 )
#define MCWDG_bfNO_FAULT                  0
#define MCWDG_bfNO_MONITORING_STATE       0
#define MCWDG_KAU8CALCRESULTSTABLE_COLS        ( 3 )
#define MCWDG_KAU8CALCVECTORSTABLE_COLS        ( 3 )
#define MCWDG_KAU8SEQUENCESLIST_COLS           ( 8 )
#define MCWDG_u8CALC_RESULTS_TABLE_SIZE   3
#define MCWDG_u8CALC_VECTORS_TABLE_SIZE   3
#define MCWDG_u8CKS_TEST_DISABLE1         85
#define MCWDG_u8CKS_TEST_DISABLE2         170
#define MCWDG_u8DEFAULT_IDENT_MESSAGE     0
#define MCWDG_u8EXE_DIAG_CONFIG_SIZE      1
#define MCWDG_u8EXECUTE_ALGORITHM         192
#define MCWDG_u8EXECUTE_ALGORITHM_SIZE    1
#define MCWDG_u8EXECUTE_DIAG_CONFIG       48
#define MCWDG_u8FUNC_TEST_EXCH_RESULT     34
#define MCWDG_u8FUNC_TEST_EXCH_RESULT_SIZE  1
#define MCWDG_u8GET_ALGORITHM             207
#define MCWDG_u8GET_ALGORITHM_SIZE        1
#define MCWDG_u8GET_CLOCK                 223
#define MCWDG_u8GET_CLOCK_SIZE            2
#define MCWDG_u8GET_CONVERSION_RESULT     255
#define MCWDG_u8GET_CONVERSION_SIZE       2
#define MCWDG_u8GET_FAULT_STATE           191
#define MCWDG_u8GET_FAULT_STATE_SIZE      1
#define MCWDG_u8GET_INIT_SAFETY_RESULT    43
#define MCWDG_u8GET_INIT_SAFETY_RESULT_SIZE  1
#define MCWDG_u8GET_ROM_CHECKSUM          63
#define MCWDG_u8GET_ROM_CHECKSUM_SIZE     2
#define MCWDG_u8MAX_MESSAGE_LENGTH        2
#define MCWDG_u8MCP_ELEC_DIAG             4
#define MCWDG_u8MCP_RAM_FLASH_TEST        2
#define MCWDG_u8MCW_COMPUTED_CKS          8
#define MCWDG_u8MCW_INH_DRIVE_REQ         33
#define MCWDG_u8MCW_INH_DRIVE_REQ_SIZE    1
#define MCWDG_u8MCW_OUT1_INHIB_MASK       1
#define MCWDG_u8MCW_OUT2_INHIB_MASK       2
#define MCWDG_u8SEQUENCES_NUMBER_MAX      8
#define MCWDG_u8START_INIT_SAFETY         32
#define MCWDG_u8START_INIT_SAFETY_SIZE    1
#define MCWDG_u8STATUS_IN_PROGRESS        170
#define MCWDG_u8STATUS_KO                 90
#define MCWDG_u8STATUS_OK                 165
#define MCWDG_u8SYNCHRONIZATION_BYTE      153
#define MCWDG_u8TEST_RESULT_1             96
#define MCWDG_u8TEST_RESULT_2             30
#define MCWDG_u8TEST_RESULT_3             0
#define MCWDG_u8TEST_VECTOR_1             85
#define MCWDG_u8TEST_VECTOR_2             170
#define MCWDG_u8TEST_VECTOR_3             246
#define MCWDG_udtELEC_CUT_OFF_PATH_TEST   4
#define MCWDG_udtFAULT_STATE              32
#define MCWDG_udtINIT_SAFETY              2
#define MCWDG_udtMCP_FLASH_CKS_MASK       2
#define MCWDG_udtMCP_RAM_TEST_MASK        1
#define MCWDG_udtPREP_INIT_SAFETY         1
#define MCWDG_udtRESET_FLAG               64
#define MCWDG_udtRUNNING_STATE            16
#define MCWDG_udtWAITING_CUT_OFF_FUNC     8

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st39 */
#define MCWDG_ACQUI_SYNCHRO_IDLE          1
#define MCWDG_ACQUI_SYNCHRO_REQUEST       2
#define MCWDG_ACQUI_START_SYNCHRO_1       4
#define MCWDG_ACQUI_WAIT_SYNCHRO_1        8
#define MCWDG_ACQUI_START_SYNCHRO_2       16
#define MCWDG_ACQUI_WAIT_SYNCHRO_2        32
/*extern uint8 MCWDG_enuAcquiSynchroState;*/

/* enum st38 */
#define MCWDG_SYNCHRONOUS_STATE           1
#define MCWDG_IDENTIFIER_STATE            2
#define MCWDG_DATA_STATE                  4
#define MCWDG_CHECKSUM_STATE              8
#define MCWDG_FAULT_STATE                 16
/*extern uint8 MCWDG_enuCommunicationState;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

extern const uint8  MCWDG_ku8CheckSumTestConfig1;
extern const uint8  MCWDG_ku8CheckSumTestConfig2;
extern const uint8  MCWDG_ku8ClockCheckAvlTime;
extern const uint8  MCWDG_ku8MaxNbUnsupportedMsg;
extern const uint8  MCWDG_ku8Sig1PosDiffThreshold;
extern const uint8  MCWDG_ku8Sig2PosDiffThreshold;
extern const uint16  MCWDG_ku16ClockDiffThreshold;
extern const uint16  MCWDG_ku16InitSafetyTimeout;
extern const uint16  MCWDG_ku16TimeoutMaxSpiCom;

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

extern uint8 MCWDG_enuAcquiSynchroState;
extern uint8 MCWDG_enuCommunicationState;
extern boolean MCWDG_bEnableSampleCheck;
extern boolean MCWDG_bFaultsMaskReq;
extern boolean MCWDG_bFirstAcquiSynchroDone;
extern boolean MCWDG_bFuncTestExchangeReq;
extern boolean MCWDG_bFuncTestMainPerformed;
extern boolean MCWDG_bMcwComputedCksReq;
extern boolean MCWDG_bMcwRomChecksumAvailable;
extern boolean MCWDG_bMcwUpdateInhibitReq;
extern boolean MCWDG_bPrepInitTestPerformed;
extern boolean MCWDG_bRxDataProcessing;
extern boolean MCWDG_bSentMessageProcessing;
extern boolean MCWDG_bSetFaultMaskReq;
extern boolean MCWDG_bSetStatusExchangeReq;
extern MCWDG_tbfPrepInitStatus MCWDG_bfMcpPrepInitTestStatus;
extern uint8 MCWDG_au8RxBuffer[MCWDG_AU8RXBUFFER_COLS];
extern uint8 MCWDG_au8TxBuffer[MCWDG_AU8TXBUFFER_COLS];
extern uint8 MCWDG_bfMcpFaultState;
extern uint8 MCWDG_bfMcwFaultState;
extern uint8 MCWDG_enuInitStateFlow;
extern uint8 MCWDG_u8ApiFunctionalResultCntr;
extern uint8 MCWDG_u8ApiStartInhibtionCntr;
extern uint8 MCWDG_u8ApiStopInhibtionCntr;
extern uint8 MCWDG_u8BufferIndex;
extern uint8 MCWDG_u8CalculationVectorsIndex;
extern uint8 MCWDG_u8FunctionalTestsResult;
extern uint8 MCWDG_u8MaxNbUnsupportedMsgCtr;
extern uint8 MCWDG_u8McpCalculationTestResult;
extern uint8 MCWDG_u8McpCalculationTestValue;
extern uint8 MCWDG_u8McwCalculationTestResult;
extern uint8 MCWDG_u8McwCalculationTestValue;
extern uint8 MCWDG_u8MCWInhibPinStatus;
extern uint8 MCWDG_u8MessageIdentifier;
extern uint8 MCWDG_u8MessageLength;
extern uint8 MCWDG_u8ReadingBlockAddress;
extern uint8 MCWDG_u8RxChecksum;
extern uint8 MCWDG_u8RxData;
extern uint8 MCWDG_u8SequencingIndex;
extern uint8 MCWDG_u8Sig1PositionMcpMcp;
extern uint8 MCWDG_u8Sig1PositionMcwMcp;
extern uint8 MCWDG_u8Sig2PositionMcpMcp;
extern uint8 MCWDG_u8Sig2PositionMcwMcp;
extern uint8 MCWDG_u8Signal2WaitEventInitNb;
extern uint8 MCWDG_u8Signal2WaitEventNb;
extern uint8 MCWDG_u8TaskAbortCntr;
extern uint8 MCWDG_u8TaskEndCntr;
extern uint8 MCWDG_u8TaskStartCntr;
extern uint8 MCWDG_u8TrigMcpMessageIdentifier;
extern uint8 MCWDG_u8TxChecksum;
extern uint8 MCWDG_u8TxData;
extern uint16 MCWDG_u16CheckSumTestCounter;
extern uint16 MCWDG_u16McpClockTime;
extern uint16 MCWDG_u16McpCurrentClockTime;
extern uint16 MCWDG_u16McpMcwClockDifference;
extern uint16 MCWDG_u16McpSignal1Time;
extern uint16 MCWDG_u16McpSignal2Time;
extern uint16 MCWDG_u16McwClockTime;
extern uint16 MCWDG_u16McwComputedFlashCKS;
extern uint16 MCWDG_u16TimeOutDownCounter;
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MCWDG_vidAlgorithmAnalysis(void);
void MCWDG_vidCheckCutOffTestResult(void);
void MCWDG_vidCheckInitSafetyResults(void);
void MCWDG_vidCheckMcpTest(uint8 u8LocalTmp);
void MCWDG_vidClockAnalysis(void);
void MCWDG_vidConversionAnalysis(void);
void MCWDG_vidDisableSpiTimeout(void);
void MCWDG_vidEnableSpiTimeout(void);
void MCWDG_vidEnterFaultState(void);
void MCWDG_vidExecuteAlgorithm(void);
void MCWDG_vidExecuteTriggeredMessage(void);
void MCWDG_vidGetMessage(void);
void MCWDG_vidInitAcknowledgeByteMcw(void);
void MCWDG_vidInitCommunicationState(void);
void MCWDG_vidInitMcwMessage(void);
void MCWDG_vidInitSafetyTimeoutMngt(void);
void MCWDG_vidInitSequence(void);
void MCWDG_vidInitSynchronousAcqui(void);
void MCWDG_vidInitTimeoutSpiCom(void);
void MCWDG_vidManageMcwCksTest(void);
void MCWDG_vidMessagePreparation(void);
void MCWDG_vidRestartInitSafety(void);
void MCWDG_vidSequencer(void);
void MCWDG_vidSequencer_InitSafety(void);
void MCWDG_vidSequencer_Running(void);
void MCWDG_vidStartSynchroAcqui(void);
void MCWDG_vidSynchronousAcquiRequest(void);
void MCWDG_vidWaitChecksum(void);
void MCWDG_vidWaitData(void);
void MCWDG_vidWaitIdentification(void);
void MCWDG_vidWaitSynchronization(void);


#endif /* MCWDG_L_H */

/*-------------------------------- end of file -------------------------------*/
