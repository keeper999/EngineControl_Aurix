/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_L.h                                                                                     */
/* !Description     : Internal functions of TLE8718 Component                                                         */
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
 * %PID: P2017_BSW:0A133947.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_L_H
#define TLE8718_L_H

#include "Std_Types.h"

#include "DGOHAL.h"
#include "HOD.h"
#include "Msc.h"
#include "Pwm.h"
#include "TLE8718.h"
#include "TLE8718_Cfg_I.h"
#include "TLE8718_Typ.h"

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* !MComment: Number of TLE8718 Channels by Instance                          */
#define TLE8718_udtCHANNEL_NB            18u

/* !MComment: Output Mode Type: TLE8718_u8DIO_MODE / TLE8718_u8PWM_MODE       */
#define TLE8718_u8DIO_MODE               0x1u
#define TLE8718_u8PWM_MODE               0x2u
#define TLE8718_u8CDD_MODE               0x3u /* uses and manages its own TOM or ATOM resource */ 

/* !MComment: Value of Duty Cycles of 100%                                    */
#define TLE8718_udtDUTY_MAX             0x8000u
/* !MComment: Value of Duty Cycles of 0%                                      */
#define TLE8718_udtDUTY_MIN             0x0000u

/* !MComment: MSC Error Types */
#define TLE8718_u8MSC_COM_OK            0x00u
#define TLE8718_u8MSC_FAILURE           0x01u
#define TLE8718_u8MSC_TIMEOUT           0x02u

/* !MComment: Maximal Number of Command Sending Without Receiving Any Frame   */
#define TLE8718_u8MAX_RX_ERR_CNT         0x03u

/* !MComment: Output Diag State Linked To The 2 Bits of Diag                  */
#define TLE8718_u8POWER_STAGE_OK         0x3u
#define TLE8718_u8SCB_OR_DOT             0x2u
#define TLE8718_u8OL                     0x1u
#define TLE8718_u8SCG                    0x0u

/* !MComment: States allowed for TLE8718_au8CmdAuthorized                     */
#define TLE8718_u8CMD_DISA_DESTRUCT_FLT  0x2u
#define TLE8718_u8CMD_DISA_WITHOUT_FLT   0x1u
#define TLE8718_u8CMD_ENABLED            0x0u

/* !MComment: MSC Service Identifiers To Control TLE8718 Instances            */
#define TLE8718_udtRD_CONFIG_ID          0x10u
#define TLE8718_udtRD_DATA_ID            0x13u
#define TLE8718_udtWR_CONREG1_ID         0x01u
#define TLE8718_udtWR_CONREG2_ID         0x02u
#define TLE8718_udtWR_CONREG3_ID         0x04u
#define TLE8718_udtWR_CONREG4_ID         0x0Du
#define TLE8718_udtWR_OUT15OUT16_ID      0x07u
#define TLE8718_udtWR_RST_ID             0x08u
#define TLE8718_udtWR_START_ID           0x0Bu

/* !MComment: TLE8718 Register Identifier In RD_CONFIG Command                */
#define TLE8718_udtCONREG1_ID            0x80u
#define TLE8718_udtCONREG2_ID            0x40u
#define TLE8718_udtCONREG3_ID            0x20u
#define TLE8718_udtCONREG4_ID            0x10u
#define TLE8718_udtOUT15OUT16_ID         0x08u
#define TLE8718_udtOUTREG_EVEN_ID        0x02u
#define TLE8718_udtOUTREG_ODD_ID         0x01u

/* !MComment: TLE8718 Register Identifier In RD_DATA Command                  */
#define TLE8718_udtDIAREG1_ID            0x80u
#define TLE8718_udtDIAREG2_ID            0x40u
#define TLE8718_udtDIAREG3_ID            0x20u
#define TLE8718_udtDIAREG4_ID            0x10u
#define TLE8718_udtDIAREG5_ID            0x08u
#define TLE8718_udtDIAREG6_ID            0x04u
#define TLE8718_udtDIAREG7_ID            0x02u

/* !MComment: Configuration Of TLE8718 Behavior In Case Of Short Circuit To   */
/*            Battery Voltage. Allowed Values:                                */
#define TLE8718_OUTPUT_SWITCH_OFF        1u
#define TLE8718_LIMITED_CURRENT          0u

/* !MComment: Configuration Of The Switch On/Off Of The Internal Diagnostic   */
/*            Pull-Down Current Source. Diagnosis Of OL Is Deactivated If Off */
/*            Allowed Values:                                                 */
#define TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_ENABLED  1u
#define TLE8718_DIAG_PULL_DOWN_CUR_AND_OPEN_LOAD_DISABLED 0u

/* !MComment: Configuration Of Rising Edge Filter Time Before Switching       */
/*            DELAYOUT Or RES15_16. Allowed Values:                           */
#define TLE8718_LONG_FILTER_TIME         1u
#define TLE8718_SHORT_FILTER_TIME        0u

/* !MComment: VOUTn Is Checked In Addition To IOUTn And The Diagnosis Register*/
/*            SCB Is Only Set, If IOUTn_max And VOL Is Reached For Longer Than*/
/*            tDIAG_SCB. This Feature Is Available For OUT5...14 Only.        */
/*            Allowed Values:                                                 */
#define TLE8718_EXTENDED_SCB_ENABLED     1u
#define TLE8718_EXTENDED_SCB_DISABLED    0u

/* !MComment: Configuration Of DELAYIN - Filtering Time Before Switching      */
/*            DELAYOUT Low. Allowed Values:                                   */
#define TLE8718_LONG_DELAY               3u
#define TLE8718_MEDIUM_LONG_DELAY        1u
#define TLE8718_MEDIUM_SHORT_DELAY       2u
#define TLE8718_SHORT_DELAY              0u

/* !MComment: Configuration Of Upstream Divider                               */
/*            Allowed Values:                                                 */
#define TLE8718_CLOCK_DIV_16             3u
#define TLE8718_CLOCK_DIV_32             0u
#define TLE8718_CLOCK_DIV_64             1u
#define TLE8718_CLOCK_DIV_128            2u

/* !MComment: Configuration Of Delay  For ABE and VDD monitoring To disable   */
/*            All Outputs. Allowed Values:                                    */
#define TLE8718_DISA_OUTPUT_SHORT_DELAY  1u
#define TLE8718_DISA_OUTPUT_LONG_DELAY   0u

/* !MComment: Configuration Of Enable Of VDD Monitoring Test                  */
/*            Allowed Values:                                                 */
#define TLE8718_VDD_MONITORING_DISABLED  1u
#define TLE8718_VDD_MONITORING_ENABLED   0u

/* !MComment: Configuration Of Enable Of Overvoltage And Undervoltage Tests   */
/*            Allowed Values:                                                 */
#define TLE8718_TEST_OVERVOLTAGE_THRESH  0u
#define TLE8718_TEST_UNDERVOLTAGE_THRESH 1u

/* !MComment: Configuration Of Behavior Of The ABE Level And Output Stages On */
/*            The Return Of VDD From Overvoltage To The Correct Range.        */
/*            Allowed Values:                                                 */
#define TLE8718_ABE_LATCHED_AND_OUTPUTS_REMAIN_OFF 1u
#define TLE8718_ABE_INACTIVE                       0u

/* !MComment: Configuration Of Enable Of Restart Timeout Counter For Delayed  */
/*            Reset Behavior. Available for OUT15 and OUT16 Only.             */
/*            Allowed Values:                                                 */
#define TLE8718_DELAYED_RESET_ON         1u
#define TLE8718_DELAYED_RESET_OFF        0u

/* !MComment: Configuration Of CONREG1 Register */
#define TLE8718_u8CONREG1 \
   ( TLE8718_OUT1_SCB  << 0u \
   | TLE8718_OUT2_SCB  << 1u \
   | TLE8718_OUT3_SCB  << 2u \
   | TLE8718_OUT4_SCB  << 3u \
   | TLE8718_OUT5_SCB  << 4u \
   | TLE8718_OUT6_SCB  << 5u \
   | TLE8718_OUT7_SCB  << 6u \
   | TLE8718_OUT8_SCB  << 7u)

/* !MComment: Configuration Of CONREG2 Register */
#define TLE8718_u8CONREG2 \
   ( TLE8718_OUT9_SCB  << 0u \
   | TLE8718_OUT10_SCB << 1u \
   | TLE8718_OUT11_SCB << 2u \
   | TLE8718_OUT12_SCB << 3u \
   | TLE8718_OUT13_SCB << 4u \
   | TLE8718_OUT14_SCB << 5u \
   | TLE8718_OUT17_SCB << 6u \
   | TLE8718_OUT18_SCB << 7u)

/* !MComment: Configuration Of CONREG3 Register */
#define TLE8718_u8CONREG3 \
   ( TLE8718_OUT11_DIAC  << 0u \
   | TLE8718_OUT12_DIAC  << 1u \
   | TLE8718_OUT13_DIAC  << 2u \
   | TLE8718_OUT14_DIAC  << 3u \
   | TLE8718_OUT17_DIAC  << 4u \
   | TLE8718_OUT18_DIAC  << 5u \
   | TLE8718_DELAYIN_FIL << 6u \
   | TLE8718_EXT_SCB     << 7u)

/* !MComment: Configuration Of CONREG4 Register */
#define TLE8718_u8CONREG4 \
   ( TLE8718_DELAYIN_CONF << 0u \
   | TLE8718_FCL_CONF     << 2u \
   | TLE8718_ABE_IMPACT   << 4u \
   | TLE8718_MON_TEST     << 5u \
   | TLE8718_MON_THRES    << 6u \
   | TLE8718_MON_LATCH    << 7u)

/* !MComment: Configuration Of OUT15OUT16 Register */
#define TLE8718_u8OUT15OUT16 \
   ( TLE8718_OUT15_DELAY << 1u \
   | TLE8718_OUT15_DIAC  << 2u \
   | TLE8718_OUT15_SCB   << 3u \
   | TLE8718_OUT16_DELAY << 5u \
   | TLE8718_OUT16_DIAC  << 6u \
   | TLE8718_OUT16_SCB   << 7u)

#define TLE8718_u8OUT15OUT16_CFG_MASK 0xEEu

/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"

extern boolean TLE8718_abAbeInactive[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abBattOverVoltDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abDelayInActive[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abDiagReqStartEvent[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abDioAppliedState[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern boolean TLE8718_abDioLastCommand[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern boolean TLE8718_abDisOutputs5_10_Active[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abDisOutputs15_16_Active[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abFactoryTestDisabled[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abFailureDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abIdentRegAvailable[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abMajorFailureDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abMscFailure[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abMscMonTimeoutDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abOut15LevelOnApplied[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abOut16LevelOnApplied[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abOutputStandByActive[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abOverTempDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abPowerOnResetDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abReactDelayMngEvent[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abReverseCurrentDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abSafetyReqStartEvent[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abSafetyFailure[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abVDD_MonitorTestActive[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abVDD_OverVoltDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abVDD_UnderVoltDetected[TLE8718_udtINSTANCE_NB];
extern boolean TLE8718_abWrOut1516ReqStartEvent[TLE8718_udtINSTANCE_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

extern uint8 TLE8718_au8CmdAuthorized[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern uint8 TLE8718_au8ConReg1[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8ConReg2[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8ConReg3[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8ConReg4[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagOutput[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern uint8 TLE8718_au8DiagReg1[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg2[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg3[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg4[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg5[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg6[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8DiagReg7[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8IdentReg[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8Out1516Reg[TLE8718_udtINSTANCE_NB];
extern uint8 TLE8718_au8OutputMode[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern uint8 TLE8718_au8ReactivRemainDelay[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern uint8 TLE8718_au8ShortCircuitCounter[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

extern uint32 TLE8718_au32DataOutput[TLE8718_udtINSTANCE_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_32BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"

extern TLE8718_tenuStateType TLE8718_aenuState[TLE8718_udtINSTANCE_NB];
extern HOD_tudtDutyCycle     TLE8718_audtDutyCycleLastCommand[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern HOD_tudtDutyCycle     TLE8718_audtAppliedDutyCycle[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern HOD_tudtPeriod        TLE8718_audtRequestedPeriod[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* CONSTANTS DECLARATION                                                                                              */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CONST_BOOLEAN
#include "TLE8718_MemMap.h"

extern const boolean TLE8718_kabDataFrameBit[TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_CONST_BOOLEAN
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

extern const uint8 TLE8718_kau8Module[TLE8718_udtINSTANCE_NB];
extern const uint8 TLE8718_kau8MscBitPosition[TLE8718_udtCHANNEL_NB];
extern const uint8 TLE8718_kau8OutputMode[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern const uint8 TLE8718_kau8ReactivationDelay[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern const uint8 TLE8718_kau8ShortCircuitDetectNb[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];

#define TLE8718_STOP_SEC_CONST_8BIT
#include "TLE8718_MemMap.h"

#define TLE8718_START_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

extern const Dio_ChannelType     TLE8718_kaudtAbeDioChannel[TLE8718_udtINSTANCE_NB];
extern const DGOHAL_tudtChannel  TLE8718_kaudtDgohalChannel[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern const Dio_ChannelType     TLE8718_kaudtDis5_10DioChannel[TLE8718_udtINSTANCE_NB];
extern const Pwm_ChannelType     TLE8718_kaudtPwmChannel[TLE8718_udtINSTANCE_NB][TLE8718_udtCHANNEL_NB];
extern const Msc_RxDevSelectType TLE8718_kaudtRxDevice[TLE8718_udtINSTANCE_NB];
extern const Msc_TxDevSelectType TLE8718_kaudtTxDevice[TLE8718_udtINSTANCE_NB];

#define TLE8718_STOP_SEC_CONST_UNSPECIFIED
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/*  INTERNAL FUNCTIONS                                                                                                */
/**********************************************************************************************************************/

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

Std_ReturnType TLE8718_udtCheckAllConfigReg(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckConfigReg1To4(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckConfigReg1(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckConfigReg2(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckConfigReg3(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckConfigReg4(HOD_tudtInstance udtInstance);
Std_ReturnType TLE8718_udtCheckOut1516Reg(HOD_tudtInstance udtInstance);
void TLE8718_vidConRegInitReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidConRegInitReqStart(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeAllDiagnosisReg(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg1(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg2(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg3(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg4(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg5(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg6(HOD_tudtInstance udtInstance);
void TLE8718_vidDecodeDiagReg7(HOD_tudtInstance udtInstance);
void TLE8718_vidDiagRegMng(HOD_tudtInstance udtInstance,
                           HOD_tudtChannel udtOutputChannelBeg,
                           HOD_tudtChannel udtOutputChannelEnd,
                           uint8 u8RxData);
void TLE8718_vidDiagNoFaultMng(HOD_tudtInstance udtInstance);

void TLE8718_vidDiagReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidDiagReqStart(HOD_tudtInstance udtInstance);
void TLE8718_vidEmergencyMng(HOD_tudtInstance udtInstance);
void TLE8718_vidEnaDataFrOutReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidEnaDataFrOutReqStart(HOD_tudtInstance udtInstance);
void TLE8718_vidEnterInInitReadyState(HOD_tudtInstance udtInstance);
void TLE8718_vidMainFunction(HOD_tudtInstance udtInstance);
void TLE8718_vidOut1516RegIniReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidOut1516RegIniReqStart(HOD_tudtInstance udtInstance);
void TLE8718_vidReactivationDelayMng(HOD_tudtInstance udtInstance);
void TLE8718_vidSafetyReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidSafetyReqStart(HOD_tudtInstance udtInstance);
void TLE8718_vidSetMode(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, HOD_tenuMode enuMode);
void TLE8718_vidSetDataOutputState(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, boolean bState);
void TLE8718_vidShortCircProtection(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel);
void TLE8718_vidUpdateDiagFailures(HOD_tudtInstance udtInstance);
void TLE8718_vidWrOut1516ReqNotif(HOD_tudtInstance udtInstance);
void TLE8718_vidWrOut1516ReqStart(HOD_tudtInstance udtInstance);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_L_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
