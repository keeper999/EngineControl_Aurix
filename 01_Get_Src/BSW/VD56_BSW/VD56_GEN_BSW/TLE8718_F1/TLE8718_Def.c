/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Def.c                                                                                   */
/* !Description     : Data of TLE8718 Component                                                                       */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A133940.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "HOD.h"
#include "TLE8718.h"
#include "TLE8718_co_Cfg.h"
#include "TLE8718_L.h"
#include "TLE8718_Msc.h"
#include "TLE8718_MscM.h"
#include "TLE8718_Typ.h"

#ifndef TLE8718_coDMA_USE_FOR_FRAME_RX
   #error The macro-constant TLE8718_coDMA_USE_FOR_FRAME_RX shall be defined
#endif
#ifndef TLE8718_coDISABLED
   #error The macro-constant TLE8718_coDISABLED shall be defined
#endif

/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"

boolean TLE8718_abAbeInactive[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abBattOverVoltDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abDelayInActive[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abDiagReqStartEvent[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abDioAppliedState[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
boolean TLE8718_abDioLastCommand[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
boolean TLE8718_abDisOutputs5_10_Active[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abDisOutputs15_16_Active[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abFactoryTestDisabled[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abFailureDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abIdentRegAvailable[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abMajorFailureDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abMscM_SeqRequest[TLE8718_udtINSTANCE_NB][TLE8718_udtMSCM_SEQUENCE_NB];
boolean TLE8718_abMscFailure[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abMscMonTimeoutDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abOut15LevelOnApplied[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abOut16LevelOnApplied[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abOutputStandByActive[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abOverTempDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abPowerOnResetDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abReactDelayMngEvent[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abReverseCurrentDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abSafetyFailure[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abSafetyReqStartEvent[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abVDD_MonitorTestActive[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abVDD_OverVoltDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abVDD_UnderVoltDetected[TLE8718_udtINSTANCE_NB];
boolean TLE8718_abWrOut1516ReqStartEvent[TLE8718_udtINSTANCE_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

uint8 TLE8718_au8CmdAuthorized[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
uint8 TLE8718_au8ConReg1[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8ConReg2[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8ConReg3[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8ConReg4[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagOutput[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
uint8 TLE8718_au8DiagReg1[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg2[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg3[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg4[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg5[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg6[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8DiagReg7[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8IdentReg[TLE8718_udtINSTANCE_NB];

uint8 TLE8718_au8MscCmdData[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscCmdId[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscErrorFrameCnt[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscExpectedRxFrameNb[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscRxData[TLE8718_udtINSTANCE_NB][8u];
#if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED)
uint8 TLE8718_au8MscRxFrameId[TLE8718_udtINSTANCE_NB];
#endif /* if (TLE8718_coDMA_USE_FOR_FRAME_RX == TLE8718_coDISABLED) */

uint8 TLE8718_au8MscM_CmdData[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscM_CmdId[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscM_ErrorStatus[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscM_ExpectedRxFramNb[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8MscM_RdDiagReg6Cnt[TLE8718_udtINSTANCE_NB];

uint8 TLE8718_au8Out1516Reg[TLE8718_udtINSTANCE_NB];
uint8 TLE8718_au8OutputMode[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
uint8 TLE8718_au8ReactivRemainDelay[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
uint8 TLE8718_au8ShortCircuitCounter[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

uint32 TLE8718_au32DataOutput[TLE8718_udtINSTANCE_NB];
uint32 TLE8718_au32MscRxFrame[TLE8718_udtINSTANCE_NB][8u];

#define TLE8718_STOP_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"

TLE8718_tenuMscMSequences TLE8718_aenuMscM_SeqRunning[TLE8718_udtINSTANCE_NB];
TLE8718_tenuStateType     TLE8718_aenuState[TLE8718_udtINSTANCE_NB];
TLE8718_tenuReturnType    TLE8718_audtMscM_SeqStatus[TLE8718_udtINSTANCE_NB][TLE8718_udtMSCM_SEQUENCE_NB];
HOD_tudtDutyCycle         TLE8718_audtAppliedDutyCycle[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
HOD_tudtDutyCycle         TLE8718_audtDutyCycleLastCommand[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
HOD_tudtPeriod            TLE8718_audtRequestedPeriod[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CONST_BOOLEAN
#include "TLE8718_MemMap.h"

/* !MComment: Declaration Of The PWM MCAL Channel (AUTOSAR or LIBEMB)         */
const boolean TLE8718_kabDataFrameBit[TLE8718_udtCHANNEL_NB] =
{
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   TRUE,  /* channel commanded by data frame */
   FALSE, /* channel commanded by WR_OUT1516 command frame */
   FALSE, /* channel commanded by WR_OUT1516 command frame */
   TRUE,  /* channel commanded by data frame */
   TRUE   /* channel commanded by data frame */
};

#define TLE8718_STOP_SEC_CONST_BOOLEAN
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

/* !MComment: Declaration Of The Bit Positions Linked To TLE8718 Channels In Data Frame */
const uint8 TLE8718_kau8MscBitPosition[TLE8718_udtCHANNEL_NB] =
{
   0u,  /* OUT1 :bit 0  in Data register */
   8u,  /* OUT2 :bit 8  in Data register */
   1u,  /* OUT3 :bit 1  in Data register */
   9u,  /* OUT4 :bit 9  in Data register */
   2u,  /* OUT5 :bit 2  in Data register */
   10u, /* OUT6 :bit 10 in Data register */
   3u,  /* OUT7 :bit 3  in Data register */
   11u, /* OUT8 :bit 11 in Data register */
   4u,  /* OUT9 :bit 4  in Data register */
   12u, /* OUT10:bit 12 in Data register */
   5u,  /* OUT11:bit 5  in Data register */
   13u, /* OUT12:bit 13 in Data register */
   6u,  /* OUT13:bit 6  in Data register */
   14u, /* OUT14:bit 14 in Data register */
   0u,  /* OUT15:bit 0 "OUT15_CONTROL" in OUT1516 register */ 
   4u,  /* OUT16:bit 4 "OUT16_CONTROL" in OUT1516 register */
   7u,  /* OUT17:bit 7  in Data register */
   15u  /* OUT18:bit 15 in Data register */
};

#define TLE8718_STOP_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
